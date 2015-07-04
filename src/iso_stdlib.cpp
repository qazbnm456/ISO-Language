/* see copyright notice in isolang.h */

#include "iso_stdlib.h"
#include "iso_vm.h"
#include <iostream>

void iso_stdlib_printAST(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() > 0)
    {
        vm->setPrintAST(toBool(args->get(0), vm));
    }
}
void iso_stdlib_printIR(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() > 0)
    {
        vm->setPrintIR(toBool(args->get(0), vm));
    }
}
void iso_stdlib_printGC(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() > 0)
    {
        vm->setPrintGC(toBool(args->get(0), vm));
    }
}

void iso_stdlib_typeof(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: typeof() has no argument");
        return;
    }

    retVar->setValue(getVarTypeStr(args->get(0)->m_valueType).c_str(), vm);
}

void iso_stdlib_isfunction(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: isfunction() has no argument");
        return;
    }

    std::string t = getVarTypeStr(args->get(0)->m_valueType);
    retVar->setValue(t == "function" || t == "userfunc");
}

void iso_stdlib_print(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    std::string str;
    int count = args->size();
    for(int i = 0; i < count; ++i)
    {
        if(i != 0)
        {
            str += "\t";
        }
        str += toString(args->get(i), vm);
    }
    vm->getMsgHandler()->output("%s\n", str.c_str());
}

void iso_stdlib_tobool(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: tobool() has no argument");
        return;
    }

    retVar->setValue(toBool(args->get(0), vm));
}

void iso_stdlib_toint32(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: toint32() has no argument");
        return;
    }

    retVar->setValue(toInt32(args->get(0), vm));
}

void iso_stdlib_toint64(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: toint64() has no argument");
        return;
    }

    retVar->setValue(toInt64(args->get(0), vm));
}

void iso_stdlib_tofloat(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: tofloat() has no argument");
        return;
    }

    retVar->setValue(toFloat(args->get(0), vm));
}

void iso_stdlib_todouble(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: todouble() has no argument");
        return;
    }

    retVar->setValue(toDouble(args->get(0), vm));
}

void iso_stdlib_tostr(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: tostr() has no argument");
        return;
    }

    retVar->setValue(toString(args->get(0), vm).c_str(), vm);
}

void iso_stdlib_bindfunc(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 2)
    {
        vm->runtimeError("Error: bindfunc() must has two arguments");
        return;
    }

    isoVariable* tab0 = args->get(0);
    isoVariable* tab1 = args->get(1);

    if(tab0->m_valueType != isoVT_TABLE)
    {
        vm->runtimeError("Error: bindfunc(): args[0] must be a table");
        return;
    }

    if(tab1->m_valueType != isoVT_TABLE)
    {
        vm->runtimeError("Error: bindfunc(): args[1] must be a table");
        return;
    }

    tab0->toTable()->bindFunc(tab1->toTable(), vm);
}

void iso_stdlib_clone(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: clone() has no argument");
        return;
    }

    args->get(0)->cloneTo(retVar, vm);
}

void iso_stdlib_inherit(isoVariable* thisVar, isoArray* args, isoVariable* retVar, isoVM* vm)
{
    if(args->size() < 1)
    {
        vm->runtimeError("Error: inherit() has no argument");
        return;
    }

    //check type
    for(int i = 0; i < args->size(); ++i)
    {
        isoVariable* var = args->get(i);
        if(var->m_valueType != isoVT_TABLE)
        {
            vm->runtimeError("Error: inherit(): all of args must be tables");
            return;
        }
    }

    //clone first table
    args->get(0)->cloneTo(retVar, vm);
    isoTable* retTab = retVar->toTable();

    //copy all the other tables
    for(int i = 1; i < args->size(); ++i)
    {
        isoTable* tab = args->get(i)->toTable();
        tab->copyDataTo(retTab, vm);
    }
}

void isoStdLib::bindStdFunctions(isoVM* vm)
{
    vm->bindFunction("printAST",    iso_stdlib_printAST);
    vm->bindFunction("printIR",     iso_stdlib_printIR);
    vm->bindFunction("printGC",     iso_stdlib_printGC);

    vm->bindFunction("typeof",      iso_stdlib_typeof);
    vm->bindFunction("isfunction",  iso_stdlib_isfunction);

    vm->bindFunction("print",       iso_stdlib_print);
    vm->bindFunction("tobool",      iso_stdlib_tobool);
    vm->bindFunction("toint32",     iso_stdlib_toint32);
    vm->bindFunction("toint64",     iso_stdlib_toint64);
    vm->bindFunction("tofloat",     iso_stdlib_tofloat);
    vm->bindFunction("todouble",    iso_stdlib_todouble);
    vm->bindFunction("tostr",       iso_stdlib_tostr);

    vm->bindFunction("bindfunc",    iso_stdlib_bindfunc);
    vm->bindFunction("clone",       iso_stdlib_clone);
    vm->bindFunction("inherit",     iso_stdlib_inherit);
}