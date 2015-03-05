#include "iso_ast.h"
#include "iso_codeGenerator.h"
#include <llvm/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/raw_ostream.h>
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
    std::cout << "Generating code...\n";
 
    /* Create the top level interpreter function to call as entry */
    /*FunctionType *ftype = FunctionType::get(Type::getVoidTy(context), false);
    mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", TheModule);
    BasicBlock *bblock = BasicBlock::Create(context, "entry", mainFunction);*/

    root.codeGen(this); /* emit bytecode for the toplevel block */
    
    /*Builder->SetInsertPoint(bblock);
    Builder->CreateRetVoid();*/
 
    /* Print the bytecode in a human-readable format
       to see if our program compiled properly
     */
    std::cout << "Code is generated.\n";
    PassManager pm;
    pm.add(createPrintModulePass(outs()));
    pm.run(*TheModule);
}

void codeGenerator::printAST(SegmentAST& root)
{
    std::cout << "Generating AST...\n";
 
    root.print(2);
}