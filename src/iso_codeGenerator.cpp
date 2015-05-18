#include "iso_ast.h"
#include "iso_codeGenerator.h"
#include <llvm/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ManagedStatic.h>
#include <iostream>
#include <sstream>

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

using namespace llvm;


codeGenerator::codeGenerator()
	: context(getGlobalContext())
	, TheModule(new Module("my jit test", context))
	, Builder(new IRBuilder<> (getGlobalContext()))
{
}

codeGenerator::~codeGenerator()
{
}

Type* codeGenerator::getType(string* name){
    Type* type = typeTable[*name];
    if(type == NULL)
    {
        if(name->compare("void") == 0)
        {
            //errorMsg = "variable has incomplete type 'void'";
        }else
        {
            //errorMsg = "undeclared type '"+name+"'";
        }
    }
    return type;
}

Constant* codeGenerator::getInitial(Type* type){
    if(type->isIntegerTy(32))
    {
        return Builder->getInt32(0);
    }
    else if(type->isIntegerTy(64))
    {
        return Builder->getInt64(0);
    }
    else if(type->isFloatTy())
    {
        return ConstantFP::get(Builder->getFloatTy(), 0);
    }
    else if(type->isDoubleTy())
    {
        return ConstantFP::get(Builder->getDoubleTy(), 0);
    }
    else
    {
        //errorMsg = "no initializer for '"+getTypeName(type)+"'";
        return NULL;
    }
}

Value* codeGenerator::createCast(Value* value,Type* type){
    Type* valType = value->getType();
    if(valType == type)
    {
        return value;
    }
    else if(type->isFloatTy() && valType->isFloatTy())
    {
        return value;
    }
    else if(type->isDoubleTy() && valType->isDoubleTy())
    {
        return value;
    }
    else if(type->isIntegerTy(64) && valType->isIntegerTy(64))
    {
        return value;
    }
    else if(type->isFloatTy() && valType->isIntegerTy(64))
    {
        return Builder->CreateSIToFP(value, type);
    }
    else if(type->isDoubleTy() && valType->isIntegerTy(64))
    {
        return Builder->CreateSIToFP(value, type);
    }
    else if(type->isIntegerTy(64) && valType->isDoubleTy())
    {
        return Builder->CreateFPToSI(value, type);
    }
    else
    {
        //errorMsg = "no viable conversion from '"+getTypeName(valType)+"' to '"+getTypeName(type)+"'";
        return NULL;
    }
}

void codeGenerator::generateCode(SegmentAST& root)
{
    // Setup a module and engine for JIT-ing
    /*std::string error;
    LLVMInitializeNativeTarget();
    ExecutionEngine *engine = EngineBuilder(TheModule)
        .setErrorStr(&error)
        .setOptLevel(CodeGenOpt::Aggressive)
        .create();
    if(!engine) {
        std::cout << "No engine created: " << error << std::endl;
        exit 1;
    }*/

    std::cout << "Generating code...\n";
    root.codeGen(this); /* emit bytecode for the toplevel block */
 
    /* Print the bytecode in a human-readable format
       to see if our program compiled properly
     */
    std::cout << "Code is generated.\n";
    PassManager pm;
    //pm.add(new TargetData(*(engine->getTargetData())));
    pm.add(createPrintModulePass(outs()));
    pm.run(*TheModule);

    // Compile
    /*std::cout << "Compiling..." << std::flush;
    void (*bf)() = (void (*)()) engine->getPointerToFunction(TheModule);
    std::cout << " done" << std::endl;*/
    
    // and run!
    /*bf();*/
}

void codeGenerator::printAST(SegmentAST& root)
{
    std::cout << "Generating AST...\n";
 
    root.print(2);
}