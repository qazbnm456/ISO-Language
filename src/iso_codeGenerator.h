#ifndef ISO_CODEGEN_H
#define ISO_CODEGEN_H

#include "ISOLang.h"
#include "iso_ast.h"
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <list>
#include <vector>
#include <deque>
#include <stack>

using namespace llvm;

typedef struct FuncBlock {
	Type* retType;
	Function* func;
	std::vector<Type*> args;
	int flag = 0;
} Func_Block;

class codeGenerator
{
private:
	LLVMContext& context;
	Module* TheModule;
	IRBuilder<>* Builder;
	Function* mainFunction;

public:
	codeGenerator();
	~codeGenerator();
	LLVMContext& getLLVMContext() { return context; }
	IRBuilder<>* getIRBuilder() { return Builder; }
	Module* getModule() { return TheModule; }
	Type* getType(string* name);
	Constant* getInitial(Type* type);
	Value* createCast(Value* val, Type* type);
	void generateCode(SegmentAST& root);
	void printAST(SegmentAST& root);

	map<string, Type*> typeTable;
	map<string, Value*> NamedValues;
	deque<string*>* currentType;
	Func_Block fBlock;
};

#endif //ISO_CODEGEN_H