#include "iso_codeGenerator.h"
#include "iso_token.h"
#include "iso_ast.h"
#include "y.tab.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instructions.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <iostream>

extern int column;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char* s);
extern SegmentAST* ProgramHead;

int main(int argc, char *argv[]){
	class codeGenerator cg;
	cg.typeTable["long"] = cg.getIRBuilder()->getInt64Ty();
	cg.typeTable["int"] = cg.getIRBuilder()->getInt32Ty();
	cg.typeTable["float"] = cg.getIRBuilder()->getFloatTy();
	cg.typeTable["double"] = cg.getIRBuilder()->getDoubleTy();
	cg.typeTable["bool"] = cg.getIRBuilder()->getInt1Ty();
	char terminal[80] = "cat ";
	yyin = fopen(argv[1], "r");
	printf("INPUT FILE: \"%s\"\nCONTENT:\n", argv[1]);
	printf("------------------------------------------\n\n");
	strcat(terminal, argv[1]);
	system(terminal);
	printf("\n------------------------------------------\n");
	printf("THROUGH yyparse():\n\n");
	if(!yyparse())
		printf("\n====>%s compile complete!\n", argv[1]);
	cg.printAST(*ProgramHead);
	cg.generateCode(*ProgramHead);
	/*map<string, Value*>::iterator it = cg.NamedValues.begin();
    for(int i = 0; it != cg.NamedValues.end(); ++it, ++i)
    {
        std::cout<<(*it).first<<" : "<<(*it).second<<endl;
    }*/
	//cg.getModule()->dump();
	return 0;
}

void yyerror(const char* s){
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}