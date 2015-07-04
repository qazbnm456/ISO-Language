/* see copyright notice in ISOLang.h */

#include "iso_vm.h"
#include "iso_variable.h"
#include "iso_stdlib.h"
#include <llvm/ExecutionEngine/MCJIT.h>
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ManagedStatic.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <memory>

extern SegmentAST* ProgramHead;

using namespace llvm;


void llvm_fatal_error_handler(void *user_data, const std::string &reason, bool gen_crash_diag)
{
    isoVM* vm = (isoVM*)user_data;
    vm->getMsgHandler()->error("LLVM fatal error: %d\n", reason.c_str());
}

class HelpingMemoryManager : public SectionMemoryManager {
    HelpingMemoryManager(const HelpingMemoryManager &) = delete;
    void operator=(const HelpingMemoryManager &) = delete;

public:
    HelpingMemoryManager(isoVM* vm) : m_vm(vm) {}
    virtual ~HelpingMemoryManager() {}

    /// This method returns the address of the specified symbol.
    /// Our implementation will attempt to find symbols in other
    /// modules associated with the MCJITHelper to cross link symbols
    /// from one generated module to another.
    virtual uint64_t getSymbolAddress(const std::string &name) override;

private:
    isoVM* m_vm;
};

uint64_t HelpingMemoryManager::getSymbolAddress(const std::string &name) {
    uint64_t fnAddr = SectionMemoryManager::getSymbolAddress(name);
    if(fnAddr)
        return fnAddr;

    return (uint64_t)m_vm->getCodeGenerator()->getGlobalSymbolAddress(name);

    //uint64_t helperFun = m_vm->getCurrentExecutionEngine()->getFunctionAddress(name);
    //if(!helperFun)
    //{
    //    report_fatal_error("Program used extern function '" + Name +
    //        "' which could not be resolved!");
    //}
    //return helperFun;
}


isoVM::isoVM()
    : m_initOkay(true)
    , m_llvmContext()
    , m_module(0)
    , m_msgHandler()
    , m_gc(this)
    , m_isRuntimeError(false)
    , m_debugInfo(0)
    , m_printAST(true)
    , m_printIR(true)
{
    llvm::install_fatal_error_handler(&llvm_fatal_error_handler, this);
    
    //LLVMInitializeAllTargets();
    //LLVMInitializeAllTargetMCs();
    //LLVMInitializeAllTargetInfos();
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();
    InitializeNativeTargetDisassembler();

    m_codeGenerator = new isoCodeGenerator(this);

    createNewModuleEngine();
    
    //isoStdLib::bindStdFunctions(this);
}

isoVM::~isoVM()
{
    delete m_codeGenerator;
    delete m_executionEngine;
    llvm::llvm_shutdown();
}

ExecutionEngine* isoVM::getExecutionEngine(Module* mod)
{
    if(mod == m_module)
        return m_executionEngine;

    auto it = m_moduleEngineMap.find(mod);
    if(it == m_moduleEngineMap.end())
        return 0;

    return it->second;
}

void isoVM::releaseCurrentModuleEngine()
{
    if(m_module != 0)
    {
        delete m_executionEngine;

        m_module = 0;
        m_executionEngine = 0;
        m_functionCount = 0;
    }
}

void isoVM::storeCurrentModuleEngine()
{
    if(m_module != 0)
    {
        m_moduleEngineMap[m_module] = m_executionEngine;
        m_moduleFunctionCountMap[m_module] = m_functionCount;

        m_module = 0;
        m_executionEngine = 0;
        m_functionCount = 0;
    }
}

void isoVM::decFunctionCount(llvm::Module* mod)
{
    if(mod == m_module)
    {
        if(m_functionCount > 0)
        {
            --m_functionCount;
        }
        else
        {
            //error!!!
        }
    }
    else
    {
        int count = m_moduleFunctionCountMap[mod];
        if(count > 0)
        {
            if(--count == 0)
            {
                ExecutionEngine* ee = m_moduleEngineMap[mod];
                m_moduleEngineMap.erase(mod);
                m_moduleFunctionCountMap.erase(mod);

                delete ee;
            }
            else
            {
                m_moduleFunctionCountMap[mod] = count;
            }
        }
        else
        {
            //error!!!
        }
    }
}

void isoVM::createNewModuleEngine()
{
    storeCurrentModuleEngine();

    static int count = 0;
    char buf[16];
    sprintf(buf, "isolang jit %d", count++);
    std::unique_ptr<Module> mod(new Module(buf, m_llvmContext));
    m_module = mod.get();

#ifdef _WIN32
    std::string s = llvm::sys::getDefaultTargetTriple();
    //s = llvm::sys::getProcessTriple();
    //m_module->setTargetTriple("x86_64-pc-windows-msvc");
    m_module->setTargetTriple(s + "-elf");
#endif

    std::string errStr;
    llvm::EngineBuilder fisotory(std::move(mod));
    fisotory.setEngineKind(llvm::EngineKind::JIT);
    fisotory.setErrorStr(&errStr);

    HelpingMemoryManager* memMgr = new HelpingMemoryManager(this);
    fisotory.setMCJITMemoryManager(std::unique_ptr<RTDyldMemoryManager>(memMgr));

    m_executionEngine = fisotory.create();
    if(m_executionEngine == NULL)
    {
        m_msgHandler.error("Could not create ExecutionEngine: %s\n", errStr.c_str());
        m_initOkay = false;
    }
    else
    {
        m_codeGenerator->createCoreFunctions();
    }

    m_functionCount = 0;
}

void isoVM::runtimeError(const char* errMsg)
{
    m_isRuntimeError = true;
    if(m_debugInfo != 0)
    {
        m_msgHandler.error(m_debugInfo->file, m_debugInfo->line, errMsg);
        m_debugInfo = 0;
    }
    else
    {
        m_msgHandler.error(errMsg);
    }
    m_gc.clearTempObj();
    longjmp(*m_codeGenerator->getErrorJmpBuf(), 1);
}

extern "C"
{
    void* addTableVar_str(isoTable* tab, const char* name, isoVM* vm);
}

void isoVM::bindFunction(const std::string& name, ISO_FUNCTION func)
{
    isoUserFunc* uf = (isoUserFunc*)m_gc.createObject(isoVT_USERFUNC);
    uf->m_funcPtr = (void*)func;

    isoTable* rootTable = m_codeGenerator->m_rootTable;
    isoVariable* var = (isoVariable*)addTableVar_str(rootTable, name.c_str(), this);
    var->setValue(uf);
}

isoVariable* isoVM::createString(const char* str)
{
    return m_gc.createVarWithData(str);
}

extern int yyparse();
bool isoVM::runCode(const char* code, bool runGCFinally)
{
    m_isRuntimeError = false;
    m_codeGenerator->setCompileError(false);
    m_gc.clearTempObj();

    /*if(m_parser->setCode(code) == 0)
        return false;*/

    if(m_module == NULL)
    {
        createNewModuleEngine();
    }

    bool compileOk = true;
    if(yyparse() != 0) {
        m_msgHandler.error("yyparse() failed\n");
        compileOk = false;
    }

    m_codeGenerator->setProgramSegmentAST(ProgramHead);

    if(compileOk && m_codeGenerator->getProgramSegmentAST() == 0) {
        m_msgHandler.error("getProgramSegmentAST() failed\n");
        compileOk = false;
    }

    if(compileOk && m_printAST)
    {
        printf("========AST Begin========\n");
        m_codeGenerator->getProgramSegmentAST()->print(0);        
        printf("========AST End========\n");
    }

    if(compileOk)
    {
        m_codeGenerator->generateCode();

        if(m_codeGenerator->isCompileError()) {
            m_msgHandler.error("m_codeGenerator->isCompileError()\n");
            compileOk = false;
        }
        else
            m_codeGenerator->runCode();
    }

    if(m_functionCount == 0)
    {
        releaseCurrentModuleEngine();
    }
    else
    {
        storeCurrentModuleEngine();
    }

    //m_parser->releaseNodeASTList();

    if(runGCFinally)
    {
        m_gc.completeGC();
    }

    return compileOk && !m_isRuntimeError;
}

struct KeyData
{
    std::string key;
    bool isNumber;
};
//split keys by '.'
bool splitKeys(const std::string& keysStr, std::vector<KeyData>& keys)
{
    KeyData kd;
    kd.key.clear();
    kd.isNumber = true;

    int count = (int)keysStr.size();
    for(int i = 0; i < count; ++i)
    {
        char ch = keysStr[i];
        if(ch == '.')
        {
            if(kd.key.empty())
                return false;

            //add a keydata
            keys.push_back(kd);
            //clear keydata
            kd.key.clear();
            kd.isNumber = true;
        }
        else if(kd.isNumber && ch <= '9' && ch >= '0')
        {
            kd.key.push_back(ch);
        }
        else
        {
            kd.key.push_back(ch);
            kd.isNumber = false;
        }
    }

    if(kd.key.empty())
        return false;

    //add a keydata
    keys.push_back(kd);

    return true;
}

isoVariable* isoVM::getItemInRootTable(const std::string& keys)
{
    return getItemInVar(getRootTable(), keys);
}

isoVariable* isoVM::getItemInVar(isoVariable* var, const std::string& keys)
{
    std::vector<KeyData> keyData;
    if(!splitKeys(keys, keyData))
        return 0;

    int count = (int)keyData.size();
    for(int i = 0; i < count; ++i)
    {
        if(var == 0)
            return 0;

        const KeyData& kd = keyData[i];
        if(kd.isNumber)
        {
            int idx = atoi(kd.key.c_str());
            var =var->get(idx);
        }
        else
        {
            var = var->get(kd.key.c_str());
        }
    }

    return var;
}

isoVariable* isoVM::addItemInTable(isoVariable* tableVar, const char* key, isoVarType valueType)
{
    isoGarbageCollector* gc = getGarbageCollector();
    isoVariable* keyVar = gc->createVarWithData(key);
    isoVariable* valVar = (isoVariable*)gc->createObject(valueType);
    tableVar->toTable()->add(keyVar, valVar);
    return valVar;
}

isoVariable* isoVM::addItemInArray(isoVariable* arrayVar, int idx, isoVarType valueType)
{
    isoGarbageCollector* gc = getGarbageCollector();
    isoVariable* valVar = (isoVariable*)gc->createObject(valueType);
    arrayVar->toArray()->fillAndSet(idx, valVar, this);
    return valVar;
}

void isoVM::setVarType(isoVariable* var, isoVarType valueType)
{
    if(var->m_valueType != valueType)
    {
        switch(valueType)
        {
        case isoVT_NULL:
            var->setNull();
            break;
        case isoVT_BOOL:
            var->setValue(false);
            break;
        case isoVT_INT32:
            var->setValue(isoInt32(0));
            break;
        case isoVT_INT64:
            var->setValue(isoInt64(0));
            break;
        case isoVT_FLOAT:
            var->setValue(isoFloat(0));
            break;
        case isoVT_DOUBLE:
            var->setValue(isoDouble(0));
            break;
        case isoVT_STRING:
            var->setValue("", this);
            break;
        case isoVT_ARRAY:
            {
                isoGCObject* obj = getGarbageCollector()->createObject(isoVT_ARRAY);
                var->setValue(obj);
            }
            break;
        case isoVT_TABLE:
            {
                isoGCObject* obj = getGarbageCollector()->createObject(isoVT_TABLE);
                var->setValue(obj);
            }
            break;
        case isoVT_FUNCTION:
            {
                isoGCObject* obj = getGarbageCollector()->createObject(isoVT_FUNCTION);
                var->setValue(obj);
            }
            break;
        case isoVT_DELEGATE:
            {
                isoGCObject* obj = getGarbageCollector()->createObject(isoVT_DELEGATE);
                var->setValue(obj);
            }
            break;
        case isoVT_USERDATA:
            //TODO
            break;
        case isoVT_USERFUNC:
            {
                isoGCObject* obj = getGarbageCollector()->createObject(isoVT_USERFUNC);
                var->setValue(obj);
            }
            break;
        }
    }
}