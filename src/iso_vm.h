/* see copyright notice in ISOLang.h */

#ifndef ISO_VM_H
#define ISO_VM_H

#include "iso_codeGenerator.h"
#include "iso_gc.h"
#include "iso_msghandler.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>

class isoVM
{
protected:
    bool m_initOkay;

    llvm::LLVMContext m_llvmContext;

    //current module
    llvm::Module* m_module;
    //current engine
    llvm::ExecutionEngine* m_executionEngine;
    //count of generated functions in current module
    int m_functionCount; 

    //finalized modules
    std::map<llvm::Module*, llvm::ExecutionEngine*> m_moduleEngineMap;
    //for GC. if count == 0, the module can be safely deleted.
    std::map<llvm::Module*, int> m_moduleFunctionCountMap;

    isoMsgHandler m_msgHandler;
    isoCodeGenerator* m_codeGenerator;
    isoGarbageCollector m_gc;
    bool m_isRuntimeError;
    isoDebugInfo* m_debugInfo;

    //for debug
    bool m_printAST;
    bool m_printIR;

public:
    isoVM();
    ~isoVM();

    bool getInitOkay() { return m_initOkay; }

    llvm::LLVMContext& getLLVMContext() { return m_llvmContext; }

    llvm::Module* getCurrentModule() { return m_module; }
    llvm::ExecutionEngine* getCurrentExecutionEngine() { return m_executionEngine; }
    llvm::ExecutionEngine* getExecutionEngine(llvm::Module* mod);

    void releaseCurrentModuleEngine();
    void storeCurrentModuleEngine();
    void incFunctionCount() { ++m_functionCount; }
    void decFunctionCount(llvm::Module* mod);
    void createNewModuleEngine();

    isoMsgHandler* getMsgHandler() { return &m_msgHandler; }
    isoCodeGenerator* getCodeGenerator() { return m_codeGenerator; }
    isoGarbageCollector* getGarbageCollector() { return &m_gc; }
    void setDebugInfo(isoDebugInfo* debugInfo) { m_debugInfo = debugInfo; }
    void runtimeError(const char* errMsg);

    typedef void(*ISO_FUNCTION)(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm);
    void bindFunction(const std::string& name, ISO_FUNCTION func);
    //void callFunction(const std::string& name, std::vector<GenericValue> noargs);

    //helper function for creating isoVariable objects
    isoVariable* createString(const char* str);

    //for debug
    void setPrintAST(bool b) { m_printAST = b; }
    bool getPrintAST() { return m_printAST; }
    void setPrintIR(bool b) { m_printIR = b; }
    bool getPrintIR() { return m_printIR; }
    void setPrintGC(bool b) { m_gc.setPrintGC(b); }
    bool getPrintGC() { return m_gc.getPrintGC(); }

public:
    //compile & run Code
    bool runCode(const char* code, bool runGCFinally = true);

    //get roottable
    isoVariable* getRootTable() { return m_codeGenerator->getRootTableVar(); }
    //key: "a.b.123"; return ::a[b][123] or NULL if there is any key that is not exist.
    isoVariable* getItemInRootTable(const std::string& keys);
    //key: "a.b.123"; return var[a][b][123] or NULL if there is any key that is not exist.
    isoVariable* getItemInVar(isoVariable* var, const std::string& keys);

    //add a new item in table
    isoVariable* addItemInTable(isoVariable* tableVar, const char* key, isoVarType valueType);
    //add a new item at array[idx], if sizeof(array) < idx, array will be fill up with null values
    isoVariable* addItemInArray(isoVariable* arrayVar, int idx, isoVarType valueType);

    void setVarType(isoVariable* var, isoVarType type);

protected:

};



#endif //ISO_VM_H