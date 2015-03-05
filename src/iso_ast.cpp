/* see copyright notice in ISOLang.h */

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

using namespace llvm;

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1)*33) ^ str[h];
}

Value* StringList::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* InitDeclAST::codeGen(class codeGenerator* cg)
{
    func->codeGen(cg);
    return 0;
}

Value* InitDeclListAST::codeGen(class codeGenerator* cg)
{
    vector<class NodeAST*>::iterator it = decl_inits.begin();
    for(int i = 0; it != decl_inits.end(); ++it, ++i)
    {
        (*it)->codeGen(cg);
    }
    return 0;
}

Value* InitAST::codeGen(class codeGenerator* cg)
{
    if(e_Type == 1)
    {
        return expr->codeGen(cg);
    }
    else if(e_Type == 2)
    {
        return init_list->codeGen(cg);
    }
    else
    {
        return init_list->codeGen(cg);
    }
}

Value* InitListAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* NullAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* BooleanAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* Int32AST::codeGen(class codeGenerator* cg)
{
    return ConstantInt::get(cg->getLLVMContext(), APInt(32, m_val, false));
}

Value* Int64AST::codeGen(class codeGenerator* cg)
{
    return ConstantInt::get(cg->getLLVMContext(), APInt(64, m_val, false));
}

Value* FloatAST::codeGen(class codeGenerator* cg)
{
    return ConstantFP::get(cg->getLLVMContext(), APFloat(m_val));
}

Value* DoubleAST::codeGen(class codeGenerator* cg)
{
    return ConstantFP::get(cg->getLLVMContext(), APFloat(m_val));
}

Value* DeclarationAST::codeGen(class codeGenerator* cg)
{
    cg->currentType = &specifiers;
    deque<string*>::iterator it = specifiers.begin();
    for(int i = 0; it != specifiers.end(); ++it, ++i)
    {
        switch(str2int((*it)->c_str()))
        {
            case str2int("int"):
                if(InitDeclList)
                    InitDeclList->codeGen(cg);
                else
                    return cg->getType((*it))
                break;
            case str2int("long"):
                if(InitDeclList)
                    InitDeclList->codeGen(cg);
                else
                    return cg->getType((*it))
                break;
            case str2int("float"):
                if(InitDeclList)
                    InitDeclList->codeGen(cg);
                else
                    return cg->getType((*it))
                break;
            case str2int("double"):
                if(InitDeclList)
                    InitDeclList->codeGen(cg);
                else
                    return cg->getType((*it))
                break;
        }
    }
    return 0;
}

Value* DefinitionAST::codeGen(class codeGenerator* cg)
{
    if(e_Type == 1)
    {
        return 0;
    }
    else if(e_Type == 2)
    {
        std::vector<Type*> FuncTy_1_args;
        FunctionType* FuncTy_1 = FunctionType::get(decl_spec->codeGen(cg), FuncTy_1_args, false);
        Function* func_main = cg->getIRBuilder()->getFunction("main");
        if (!func_main)
        {
            func_main = Function::Create(FuncTy_1, GlobalValue::ExternalLinkage, "main", cg->getIRBuilder()); 
            func_main->setCallingConv(CallingConv::C);
        }
        declarator->codeGen(cg);
        block->codeGen(cg);
    }
}

Value* GetVarAST::codeGen(class codeGenerator* cg)
{
    if(!m_keyIdentifier->empty())
    {
        return cg->getIRBuilder()->CreateLoad(cg->NamedValues[*m_keyIdentifier], *m_keyIdentifier);
        //return cg->getModule()->getGlobalVariable(*m_keyIdentifier);
    }
    else
    {
        printf("m_keyExpr:\n");
    }
}

Value* FunctionAST::codeGen(class codeGenerator* cg)
{
    Value* val = NULL;
    if(e_Type == 1)
    {
        if(initializer)
            val = initializer->codeGen(cg);
    }
    else if(e_Type == 2)
    {
        if(initializer)
            val = initializer->codeGen(cg);
    }
    else
    {
    }
    Type* type = cg->getType(cg->currentType[0][0]);
    //GlobalVariable* temp = cast<GlobalVariable>(cg->getModule()->getOrInsertGlobal(Name, type));
    GlobalVariable* temp = new GlobalVariable(*(cg->getModule()), type, false, GlobalValue::ExternalLinkage, cg->getInitial(type), Name);
     //LoadInst* l_temp = cg->getIRBuilder()->CreateLoad(temp);
    if(val)
    {
        val = cg->createCast(val, type);
        //temp->setInitializer(cast<Constant>(val));
        cg->getIRBuilder()->CreateStore(val, temp);
    }
        
    cg->NamedValues[Name] = temp;

    return 0;
}

Value* ReturnAST::codeGen(class codeGenerator* cg)
{
    if(m_expr)
    {
        return m_expr->codeGen(cg);
    }
    else
    {
        return 
    }
}

Value* SegmentAST::codeGen(class codeGenerator* cg)
{
    NodeASTVec::const_iterator it;
    Value* last = NULL;

    for (it = m_segments.begin(); it != m_segments.end(); it++)
    {
        last = (*it)->codeGen(cg);
    }

    return last;
}

Value* BlockAST::codeGen(class codeGenerator* cg)
{
    NodeASTVec::const_iterator it;
    Value* last = NULL;

    for (it = m_statements.begin(); it != m_statements.end(); it++)
    {
        last = (*it)->codeGen(cg);
    }

    return last;
}

Value* PostfixIncrementAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* UnaryAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* MultiplicativeAST::codeGen(class codeGenerator* cg)
{
    Value* L = m_expr1->codeGen(cg);
    Value* R = m_expr2->codeGen(cg);

    switch(str2int(m_op->c_str()))
    {
    case str2int("*"):
        return cg->getIRBuilder()->CreateMul(L, R, "multmp");
    case str2int("/"):  
        break;
    case str2int("%"):
        break;
    }
}

Value* AdditiveAST::codeGen(class codeGenerator* cg)
{
    Value* L = m_expr1->codeGen(cg);
    Value* R = m_expr2->codeGen(cg);
    if (L == 0 || R == 0) return 0;

    if(L->getType()->isDoubleTy())
    {
        switch(str2int(m_op->c_str()))
        {
            case str2int("+"):
                return cg->getIRBuilder()->CreateFAdd(L, R, "addtmp");
            case str2int("-"):
                return cg->getIRBuilder()->CreateFSub(L, R, "subtmp");
        }
    }
    else
    {
        switch(str2int(m_op->c_str()))
        {
            case str2int("+"):
                return cg->getIRBuilder()->CreateAdd(L, R, "addtmp");
            case str2int("-"):
                return cg->getIRBuilder()->CreateSub(L, R, "subtmp");
        }
    }
}

Value* ShiftAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* RelationalAST::codeGen(class codeGenerator* cg)
{
    Value* L = m_expr1->codeGen(cg);
    Value* R = m_expr2->codeGen(cg);

    //Value* cmp = cg->getIRBuilder()->getInt32(m_op);

    return 0;
}

Value* EqualityAST::codeGen(class codeGenerator* cg)
{
    Value* L = m_expr1->codeGen(cg);
    Value* R = m_expr2->codeGen(cg);
    Value* ret = 0;
    if(str2int(m_op->c_str()) == str2int("=="))
    {
    }
    else
    {
    }

    return 0;
}

Value* AndAST::codeGen(class codeGenerator* cg)
{
    Value* val1 = m_expr1->codeGen(cg);
    Value* val2 = m_expr2->codeGen(cg);

    return 0;
}

Value* ExclusiveOrAST::codeGen(class codeGenerator* cg)
{
    Value* val1 = m_expr1->codeGen(cg);
    Value* val2 = m_expr2->codeGen(cg);

    return 0;
}

Value* InclusiveOrAST::codeGen(class codeGenerator* cg)
{
    Value* val1 = m_expr1->codeGen(cg);
    Value* val2 = m_expr2->codeGen(cg);

    return 0;
}

Value* LogicalAndAST::codeGen(class codeGenerator* cg)
{
    Value* val1 = m_expr1->codeGen(cg);
    Value* val2 = m_expr2->codeGen(cg);

    return 0;
}

Value* LogicalOrAST::codeGen(class codeGenerator* cg)
{
    Value* val1 = m_expr1->codeGen(cg);
    Value* val2 = m_expr2->codeGen(cg);

    return 0;
}

Value* ConditionalAST::codeGen(class codeGenerator* cg)
{
    Value* condVar = m_operand1->codeGen(cg);

    Value* trueVar = m_operand2->codeGen(cg);
    Value* falseVar = m_operand3->codeGen(cg);
}

Value* AssignmentAST::codeGen(class codeGenerator* cg)
{
    Value* val = m_expr1->codeGen(cg);

    if(str2int(m_op->c_str()) == str2int("="))
    {
        return 0;
    }

    Value* rhs = m_expr2->codeGen(cg);
    switch(str2int(m_op->c_str()))
    {
    case str2int("/="):
        break;
    case str2int("&="):
        return 0;
    case str2int("|="):
        return 0;
    case str2int("-="):
        break;
    case str2int("+="):
        break;
    case str2int("<<="):
        return 0;
    case str2int(">>="):
        return 0;
    case str2int("*="):
        break;
    case str2int("%="):
        break;
    case str2int("^="):
        return 0;
    case str2int("~="):
        return 0;
    }

    return 0;
}

Value* IfElseAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* SwitchAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* CaseAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* ContinueAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* BreakAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* WhileAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* DoWhileAST::codeGen(class codeGenerator* cg)
{
    return 0;
}

Value* ForAST::codeGen(class codeGenerator* cg)
{
    return 0;
}