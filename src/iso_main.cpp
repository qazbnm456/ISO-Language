#include "iso_variable.h"
#include "iso_vm.h"
#include "iso_gc.h"
#include "iso_msghandler.h"
#include "iso_token.h"
#include "iso_ast.h"
#include "iso_codeGenerator.h"
#include "y.tab.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instructions.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "iso_vm.h"

#if defined(WIN32)
#include <windows.h>
#endif

extern int column;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char* s);
extern SegmentAST* ProgramHead;

//>>>>> Dump Memory Leaks >>>>>
#if defined(WIN32) && defined(_DEBUG)
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK ,__FILE__, __LINE__)
struct __DumpMemLeaks
{
    __DumpMemLeaks()
    {
        _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
        long ba = -1;
        _CrtSetBreakAlloc(ba);
    }
};
static __DumpMemLeaks __dml;
#endif
//<<<<< Dump Memory Leaks <<<<<

using namespace std;

void test_lexer();
void test_parser();
void test_gc();

void isolang_shell(isoVM* vm);
int inputCode(std::string& buffer, isoVM* vm);
int MBCSToUTF8(std::string& buffer);

int main(int argc, char *argv[]) {
	isoVM* isoVm = new class isoVM();
	//class isoCodeGenerator cg(isoVm);
	isoVm->getCodeGenerator()->typeTable["long"] = isoVm->getCodeGenerator()->getIRBuilder().getInt64Ty();
	isoVm->getCodeGenerator()->typeTable["int"] = isoVm->getCodeGenerator()->getIRBuilder().getInt32Ty();
	isoVm->getCodeGenerator()->typeTable["float"] = isoVm->getCodeGenerator()->getIRBuilder().getFloatTy();
	isoVm->getCodeGenerator()->typeTable["double"] = isoVm->getCodeGenerator()->getIRBuilder().getDoubleTy();
	isoVm->getCodeGenerator()->typeTable["bool"] = isoVm->getCodeGenerator()->getIRBuilder().getInt1Ty();
	/*char terminal[80] = "cat ";
	yyin = fopen(argv[1], "r");
	printf("INPUT FILE: \"%s\"\nCONTENT:\n", argv[1]);
	printf("------------------------------------------\n\n");
	strcat(terminal, argv[1]);
	system(terminal);
	printf("\n------------------------------------------\n");
	printf("THROUGH yyparse():\n\n");
	//if(!yyparse())
		//printf("\n====>%s compile complete!\n", argv[1]);
	if(isoVm->runCode(NULL, 1)) {
		printf("\n====>%s compile complete!\n", argv[1]);
	}*/
	if(argv[1]) {
		char terminal[80] = "cat ";
		yyin = fopen(argv[1], "r");
		printf("INPUT FILE: \"%s\"\nCONTENT:\n", argv[1]);
		printf("------------------------------------------\n\n");
		strcat(terminal, argv[1]);
		system(terminal);
		printf("\n------------------------------------------\n");
		printf("THROUGH yyparse():\n\n");
		if(isoVm->runCode(NULL, 1)) {
			printf("\n====>%s compile complete!\n", argv[1]);
		}
	}
    else
	   isolang_shell(isoVm);
	return 0;
}

void yyerror(const char* s){
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

void isolang_shell(isoVM* vm)
{
    vm->getMsgHandler()->setFileName("<stdin>");
    std::string buffer;

    while(inputCode(buffer, vm) > 0)
    {
        vm->runCode(buffer.c_str());
    }
}

int inputCode(std::string& buffer, isoVM* vm)
{
    fflush(stdin);

    fprintf(stderr, "\n[printAST() = %s, printIR() = %s, printGC() = %s]\n",
        vm->getPrintAST()? "true":"false",
        vm->getPrintIR()? "true":"false",
        vm->getPrintGC()? "true":"false" );
    fprintf(stderr, "ISOLang ready (press Ctrl+D to end input) >\n");

    errno = 0;

    buffer.clear();

    while(1)
    {
        int ch = -1;
        ch = getchar();
        if(ch == -1 || ch == 0x04) break;
        buffer += (char)ch;
        /*string code;
        if(cin.eof() == 1) {
            cin.clear();
            cin.ignore();
            break;
        }
        getline(cin, code);
        buffer.append(code);
        cout<<buffer;*/
    }

#if defined(WIN32)
    MBCSToUTF8(buffer);
#endif

    return buffer.length();
}

#if defined(WIN32)
WCHAR* pTempWCBuf = 0;
int nTempWCBufSize = 0;
int MBCSToUTF8(std::string& buffer)
{
    WCHAR outBuf[ 1024 ];

    /// MBCS -> Unicode
    int iWideCharCnt = MultiByteToWideChar( CP_ACP,
        0,
        buffer.c_str(),
        static_cast<int>(buffer.length()), 
        outBuf, 
        0 );

    WCHAR* pOutBuf = NULL;
    size_t    iOutBufSize = 0;
    if( iWideCharCnt >= 1024 )
    {
        if( iWideCharCnt > nTempWCBufSize )
        {
            if( pTempWCBuf )
            {
                delete[] pTempWCBuf;
                pTempWCBuf = NULL;
            }
            pTempWCBuf = new WCHAR[ iWideCharCnt + 10 ];
            nTempWCBufSize = iWideCharCnt;
        }
        pOutBuf = pTempWCBuf;
        iOutBufSize = nTempWCBufSize;
    }
    else
    {
        pOutBuf = outBuf;
        iOutBufSize = sizeof( outBuf );
    }

    /// MBCS -> Unicode
    iWideCharCnt = MultiByteToWideChar( CP_ACP, //When this is set, dwFlags must be zero.
        0, 
        buffer.c_str(),
        buffer.length(), 
        pOutBuf, 
        static_cast<int>(iOutBufSize) );
    pOutBuf[iWideCharCnt] = 0;

    /// Unicode -> UTF8
    int ret = WideCharToMultiByte( CP_UTF8,
        0, 
        pOutBuf, 
        -1, 
        0, 
        0, 
        0, 
        0 );
    buffer.resize(ret);

    ret = WideCharToMultiByte( CP_UTF8,
        0, 
        pOutBuf, 
        -1, 
        &buffer[0], 
        ret, 
        0, 
        0 );
    if(buffer[ret] == 0)
    {
        --ret;
        buffer.resize(ret);
    }
    return ret;
}
#endif