/* see copyright notice in ISOLang.h */

#include "iso_config.h"
#include "iso_variable.h"
#include "iso_gc.h"
#include "iso_vm.h"
#include "MurmurHash3.h"
#include <memory.h>
#include <sstream>

std::string getVarTypeStr(isoVarType vt)
{
    switch(vt)
    {
    case isoVT_NULL:
        return "null";
    case isoVT_BOOL:
        return "bool";
    case isoVT_INT32:
        return "int32";
    case isoVT_INT64:
        return "int64";
    case isoVT_FLOAT:
        return "float";
    case isoVT_DOUBLE:
        return "double";
    case isoVT_VAR:
        return "var";
    case isoVT_STRING:
        return "string";
    case isoVT_ARRAY:
        return "array";
    case isoVT_TABLE:
        return "table";
    case isoVT_FUNCTION:
        return "function";
    case isoVT_DELEGATE:
        return "delegate";
    case isoVT_USERDATA:
        return "userdata";
    case isoVT_USERFUNC:
        return "userfunc";
    }
    return "unknwon type";
}

void isoString::hash()
{
    MurmurHash3_x86_32(m_data.c_str(), m_data.length(), HASH_SEED, &m_hash, &m_sum);
}

//======================================
void isoVariable::setValue(const char* str, isoVM* vm)
{
    if(m_valueType == isoVT_STRING)
    {
        ((isoString*)m_gcobj)->setData(str);
    }
    else
    {
        isoGarbageCollector* gc = vm->getGarbageCollector();
        isoString* s = (isoString*)gc->createObject(isoVT_STRING);
        s->setData(str);
        setValue(s);
    }
}

void isoVariable::assignFrom(isoVariable* v)
{
    memcpy(this, v, sizeof(isoVariable));
    m_gcColor = isoGarbageCollector::GC_BLACK;//avoid to be gc
}

void isoVariable::cloneTo(isoVariable* v, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();
    v->assignFrom(this);

    switch(m_valueType)
    {
    case isoVT_STRING:
        {
            isoString* obj = (isoString*)gc->createObject(isoVT_STRING);
            obj->setData(v->toString()->m_data);
            v->m_gcobj = obj;
        }
        break;
    case isoVT_ARRAY:
        {
            isoArray* obj = (isoArray*)gc->createObject(isoVT_ARRAY);
            toArray()->cloneTo(obj, vm);
            v->m_gcobj = obj;
        }
        break;
    case isoVT_TABLE:
        {
            isoTable* obj = (isoTable*)gc->createObject(isoVT_TABLE);
            toTable()->cloneTo(obj, vm);
            v->m_gcobj = obj;
        }
        break;
    }
}

int isoVariable::compare(isoVariable* v, isoVM* vm)
{
    switch(m_valueType)
    {
    case isoVT_INT32:
        switch(v->m_valueType)
        {
        case isoVT_INT32:
            return m_int32 - v->m_int32;
            break;
        case isoVT_INT64:
            {
                isoInt64 cmp = isoInt64(m_int32) - v->m_int64;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_FLOAT:
            {
                isoFloat cmp = isoFloat(m_int32) - v->m_float;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_DOUBLE:
            {
                isoDouble cmp = isoDouble(m_int32) - v->m_double;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        }
        break;
    case isoVT_INT64:
        switch(v->m_valueType)
        {
        case isoVT_INT32:
            {
                isoInt64 cmp = m_int64 - isoInt64(v->m_int32);
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_INT64:
            {
                isoInt64 cmp = m_int64 - v->m_int64;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_FLOAT:
            {
                isoDouble cmp = isoDouble(m_int64) - isoDouble(v->m_float);
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_DOUBLE:
            {
                isoDouble cmp = isoDouble(m_int64) - v->m_double;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        }
        break;
    case isoVT_FLOAT:
        switch(v->m_valueType)
        {
        case isoVT_INT32:
            {
                isoFloat cmp = m_float - isoFloat(v->m_int32);
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_INT64:
            {
                isoDouble cmp = isoDouble(m_float) - v->m_int64;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_FLOAT:
            {
                isoFloat cmp = m_float - v->m_float;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_DOUBLE:
            {
                isoDouble cmp = isoDouble(m_float) - v->m_double;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        }
        break;
    case isoVT_DOUBLE:
        switch(v->m_valueType)
        {
        case isoVT_INT32:
            {
                isoDouble cmp = m_double - isoDouble(v->m_int32);
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_INT64:
            {
                isoDouble cmp = m_double - isoDouble(v->m_int64);
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_FLOAT:
            {
                isoFloat cmp = m_double - isoDouble(v->m_float);
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        case isoVT_DOUBLE:
            {
                isoDouble cmp = m_double - v->m_double;
                return (cmp > 0)? 1 : ((cmp < 0)? -1 : 0);
            }
            break;
        }
        break;
    case isoVT_STRING:
        if(v->m_valueType == isoVT_STRING)
        {
            return ((isoString*)m_gcobj)->m_data.compare(((isoString*)v->m_gcobj)->m_data);
        }
        break;
    }

    char msg[128];
    sprintf(msg, "Error: comparsion between '%s' and '%s'", getVarTypeStr(m_valueType).c_str(), getVarTypeStr(v->m_valueType).c_str());
    vm->runtimeError(msg);
    return 0;
}

isoHashValue& isoVariable::getHash()
{
    switch(m_valueType)
    {
    case isoVT_BOOL:
    case isoVT_INT32:
    case isoVT_INT64:
    case isoVT_FLOAT:
    case isoVT_DOUBLE:
        m_hash.u64_0 = (isoUInt64)m_int64;
        m_hash.u32_2 = 0;
        break;
    case isoVT_STRING:
        m_hash.u32_0 = ((isoString*)m_gcobj)->m_hash;
        m_hash.u32_1 = ((isoString*)m_gcobj)->m_sum;
        m_hash.u32_2 = ((isoString*)m_gcobj)->m_data.length();
        break;
    case isoVT_VAR:
    case isoVT_ARRAY:
    case isoVT_TABLE:
    case isoVT_FUNCTION:
    case isoVT_DELEGATE:
    //user data
    case isoVT_USERDATA:
    case isoVT_USERFUNC:
        m_hash.u64_0 = (isoUInt64)m_gcobj;
        m_hash.u32_2 = 0;
        break;
    }

    m_hash.u32_3 = m_valueType;

    return m_hash;
}

void isoVariable::getHash(isoInt32 value, isoHashValue& hash)
{
    hash.u64_0 = (isoUInt64)value;
    hash.u32_2 = 0;
    hash.u32_3 = isoVT_INT32;
}

void isoVariable::getHash(isoInt64 value, isoHashValue& hash)
{
    hash.u64_0 = value;
    hash.u32_2 = 0;
    hash.u32_3 = isoVT_INT64;
}

void isoVariable::getHash(const char* str, isoHashValue& hash)
{
    isoUInt32 h, s;
    isoUInt32 len = strlen(str);
    MurmurHash3_x86_32(str, len, HASH_SEED, &h, &s);

    hash.u32_0 = h;
    hash.u32_1 = s;
    hash.u32_2 = len;
    hash.u32_3 = isoVT_STRING;
}

//======================================
isoVariable* isoVariable::get(isoInt32 idx)
{
    switch(m_valueType)
    {
    case isoVT_ARRAY:
        {
            isoArray* arr = (isoArray*)m_gcobj;
            if(idx < 0 || idx >= arr->size())
                return 0;

            return arr->get(idx);
        }
        break;
    case isoVT_TABLE:
        {
            isoTable* tab = (isoTable*)m_gcobj;
            return tab->get(idx);
        }
        break;
    }

    return 0;
}

isoVariable* isoVariable::get(isoInt64 idx)
{
    switch(m_valueType)
    {
    case isoVT_ARRAY:
        {
            isoArray* arr = (isoArray*)m_gcobj;
            if(idx < 0 || idx >= arr->size())
                return 0;

            return arr->get(idx);
        }
        break;
    case isoVT_TABLE:
        {
            isoTable* tab = (isoTable*)m_gcobj;
            return tab->get(idx);
        }
        break;
    }

    return 0;
}

isoVariable* isoVariable::get(const char* key)
{
    switch(m_valueType)
    {
    case isoVT_TABLE:
        {
            isoTable* tab = (isoTable*)m_gcobj;
            return tab->get(key);
        }
        break;
    }

    return 0;
}

isoVariable* isoVariable::get(isoVariable* key)
{
    switch(m_valueType)
    {
    case isoVT_ARRAY:
        {
            int idx = -1;
            switch(key->m_valueType)
            {
            case isoVT_INT32:
                idx = key->m_int32;
                break;
            case isoVT_INT64:
                idx = (int)key->m_int64;
                break;
            default:
                return 0;
            }

            isoArray* arr = (isoArray*)m_gcobj;
            if(idx < 0 || idx >= arr->size())
                return 0;

            return arr->get(idx);
        }
        break;
    case isoVT_TABLE:
        {
            isoTable* tab = (isoTable*)m_gcobj;
            return tab->get(key);
        }
        break;
    }

    return 0;
}

//======================================
void isoArray::fillAndSet(int idx, isoVariable* var, isoVM* vm)
{
    //fill
    if(idx >= (int)m_data.size())
    {
        isoGarbageCollector* gc = vm->getGarbageCollector();
        do
        {
            m_data.push_back((isoVariable*)gc->createObject(isoVT_NULL));
        }
        while(idx >= (int)m_data.size());
    }

    //set
    m_data[idx] = var;
}

isoVariable* isoArray::fillAndGet(int idx, isoVM* vm)
{
    //fill
    if(idx >= (int)m_data.size())
    {
        isoGarbageCollector* gc = vm->getGarbageCollector();
        do
        {
            m_data.push_back((isoVariable*)gc->createObject(isoVT_NULL));
        }
        while(idx >= (int)m_data.size());
    }

    //get
    return m_data[idx];
}

void isoArray::cloneTo(isoArray* other, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();
    other->m_data.clear();
    other->m_data.resize(m_data.size());

    DataIterator it = m_data.begin();
    DataIterator itEnd = m_data.end();
    for(int idx = 0; it != itEnd; ++it, ++idx)
    {
        isoVariable* value = *it;

        if(value->m_valueType == isoVT_STRING)
        {
            value = gc->createVarWithData(value->toString()->m_data.c_str());
        }
        else
        {
            isoVariable* old = value;
            value = (isoVariable*)gc->createObject(isoVT_NULL);
            value->assignFrom(old);
        }

        other->m_data[idx] = value;
    }
}

//======================================
void isoTable::add(const char* key, const char* value, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();
    isoVariable* keyVar = gc->createVarWithData(key);
    isoVariable* valVar = gc->createVarWithData(value);
    add(keyVar, valVar);
}
void isoTable::add(const char* key, int value, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();
    isoVariable* keyVar = gc->createVarWithData(key);
    isoVariable* valVar = gc->createVarWithData(value);
    add(keyVar, valVar);
}
void isoTable::add(int key, const char* value, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();
    isoVariable* keyVar = gc->createVarWithData(key);
    isoVariable* valVar = gc->createVarWithData(value);
    add(keyVar, valVar);
}
void isoTable::add(int key, int value, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();
    isoVariable* keyVar = gc->createVarWithData(key);
    isoVariable* valVar = gc->createVarWithData(value);
    add(keyVar, valVar);
}

void isoTable::cloneTo(isoTable* other, isoVM* vm)
{
    other->m_data.clear();
    other->m_funcBinder = m_funcBinder;
    copyDataTo(other, vm);
}

void isoTable::copyDataTo(isoTable* other, isoVM* vm)
{
    isoGarbageCollector* gc = vm->getGarbageCollector();

    DataIterator it = m_data.begin();
    DataIterator itEnd = m_data.end();
    for(; it != itEnd; ++it)
    {
        KeyValue& kv = it->second;
        isoVariable* key = kv.key;
        isoVariable* value = kv.value;

        //clone key
        if(key->m_valueType == isoVT_STRING)
        {
            key = gc->createVarWithData(key->toString()->m_data.c_str());
        }
        else
        {
            isoVariable* old = key;
            key = (isoVariable*)gc->createObject(isoVT_NULL);
            key->assignFrom(old);
        }
        //clone value
        if(value->m_valueType == isoVT_STRING)
        {
            value = gc->createVarWithData(value->toString()->m_data.c_str());
        }
        else
        {
            isoVariable* old = value;
            value = (isoVariable*)gc->createObject(isoVT_NULL);
            value->assignFrom(old);
        }

        other->add(key, value);
    }
}

void isoTable::bindFunc(char* name, isoVariable* func)
{

}

void isoTable::bindFunc(isoVariable* key, isoVariable* func, isoVM* vm)
{
    isoFuncBinder* oldFB = m_funcBinder;
    m_funcBinder = (isoFuncBinder*)vm->getGarbageCollector()->createObject(isoVT_FUNCBINDER);
    if(oldFB != 0)
    {
        oldFB->cloneTo(m_funcBinder, vm);
    }
    m_funcBinder->bindFunc(key, func);
}

void isoTable::bindFunc(isoTable* table, isoVM* vm)
{
    m_funcBinder = (isoFuncBinder*)vm->getGarbageCollector()->createObject(isoVT_FUNCBINDER);
    m_funcBinder->bindFunc(table, vm);
}

isoVariable* isoTable::getBindFunc(isoOperatorFunc func)
{
    if(m_funcBinder == 0) return 0;
    return m_funcBinder->m_funcArray[func];
}

isoVariable* isoTable::getBindFunc(const char* name)
{
    if(m_funcBinder == 0) return 0;
    return m_funcBinder->m_funcTable->get(name);
}

isoVariable* isoTable::getBindFunc(isoVariable* key)
{
    if(m_funcBinder == 0) return 0;
    return m_funcBinder->m_funcTable->get(key);
}

//======================================
void isoFuncBinder::cloneTo(isoFuncBinder* dest, isoVM* vm)
{
    m_funcTable->cloneTo(dest->m_funcTable, vm);
    memcpy(dest->m_funcArray, m_funcArray, sizeof(m_funcArray));
}

void isoFuncBinder::bindFunc(isoVariable* key, isoVariable* func)
{
    //add
    if(func->m_valueType == isoVT_FUNCTION || func->m_valueType == isoVT_USERFUNC)
    {
        m_funcTable->add(key, func);
        isoOperatorFunc opfunc = getOpFunc(key);
        if(opfunc < isoOF_MAX)
        {
            m_funcArray[opfunc] = func;
        }
    }
    else//remove
    {
        isoOperatorFunc opfunc = getOpFunc(key);
        if(opfunc < isoOF_MAX)
        {
            m_funcArray[opfunc] = 0;
        }
    }
}

void isoFuncBinder::bindFunc(isoTable* table, isoVM* vm)
{
    table->cloneTo(m_funcTable, vm);
    memset(m_funcArray, 0, sizeof(m_funcArray));

    isoTable::DataIterator it = m_funcTable->m_data.begin();
    isoTable::DataIterator itEnd = m_funcTable->m_data.end();
    while(it != itEnd)
    {
        isoTable::KeyValue& kv = it->second;
        isoOperatorFunc opfunc = getOpFunc(kv.key);
        if(opfunc < isoOF_MAX)
        {
            switch(kv.value->m_valueType)
            {
            case isoVT_FUNCTION:
            case isoVT_USERFUNC:
                m_funcArray[opfunc] = kv.value;
                break;
            }
        }
        ++it;
    }
}

isoOperatorFunc isoFuncBinder::getOpFunc(isoVariable* var)
{
    if(var->m_valueType == isoVT_STRING)
    {
        isoString* str = (isoString*)var->m_gcobj;
        std::string& s = str->m_data;
        if(s.length() > 0 && s[0] == '_')
        {
            if(s == "_new") return isoOF_NEW;
            if(s == "_add") return isoOF_ADD;
            if(s == "_sub") return isoOF_SUB;
            if(s == "_mul") return isoOF_MUL;
            if(s == "_div") return isoOF_DIV;
            if(s == "_mod") return isoOF_MOD;
        }
    }
    return isoOF_MAX;
}

//======================================
template <class T> 
std::string convertToString(T value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template <class T> 
bool convertFromString(T& value, const std::string& str)
{
    std::stringstream ss(str);
    ss >> value;
    return ss.eof();
}

//======================================
//null base functions
bool null_toBool(isoVariable* var, isoVM* vm)
{
    return false;
}
isoInt32 null_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'null' to 'int32'");
    return 0;
}
isoInt64 null_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'null' to 'int64'");
    return 0;
}
isoFloat null_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'null' to 'float'");
    return 0;
}
isoDouble null_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'null' to 'double'");
    return 0;
}
std::string null_toStr(isoVariable* var, isoVM* vm)
{
    //vm->runtimeError("Error: attempt to convert 'null' to 'string'");
    return "null";
}
void null_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'null'");
}

//======================================
//boolean base functions
bool bool_toBool(isoVariable* var, isoVM* vm)
{
    return var->m_int32 != 0;
}
isoInt32 bool_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'bool' to 'int32'");
    return 0;
}
isoInt64 bool_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'bool' to 'int64'");
    return 0;
}
isoFloat bool_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'bool' to 'float'");
    return 0;
}
isoDouble bool_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'bool' to 'double'");
    return 0;
}
std::string bool_toStr(isoVariable* var, isoVM* vm)
{
    //vm->runtimeError("Error: attempt to convert 'bool' to 'string'");
    return var->m_int32 != 0 ? "true" : "false";
}
void bool_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'bool'");
}

//======================================
//int32 base functions
bool int32_toBool(isoVariable* var, isoVM* vm)
{
    return var->m_int32 != 0;
}
isoInt32 int32_toInt32(isoVariable* var, isoVM* vm)
{
    return (isoInt32)var->m_int32;
}
isoInt64 int32_toInt64(isoVariable* var, isoVM* vm)
{
    return (isoInt64)var->m_int32;
}
isoFloat int32_toFloat(isoVariable* var, isoVM* vm)
{
    return (isoFloat)var->m_int32;
}
isoDouble int32_toDouble(isoVariable* var, isoVM* vm)
{
    return (isoDouble)var->m_int32;
}
std::string int32_toStr(isoVariable* var, isoVM* vm)
{
    return convertToString(var->m_int32);
}
void int32_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'int32'");
}

//======================================
//int64 base functions
bool int64_toBool(isoVariable* var, isoVM* vm)
{
    return var->m_int64 != 0;
}
isoInt32 int64_toInt32(isoVariable* var, isoVM* vm)
{
    return (isoInt32)var->m_int64;
}
isoInt64 int64_toInt64(isoVariable* var, isoVM* vm)
{
    return (isoInt64)var->m_int64;
}
isoFloat int64_toFloat(isoVariable* var, isoVM* vm)
{
    return (isoFloat)var->m_int64;
}
isoDouble int64_toDouble(isoVariable* var, isoVM* vm)
{
    return (isoDouble)var->m_int64;
}
std::string int64_toStr(isoVariable* var, isoVM* vm)
{
    return convertToString(var->m_int64)+"L";
}
void int64_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'int64'");
}

//======================================
//float base functions
bool float_toBool(isoVariable* var, isoVM* vm)
{
    return var->m_float != 0;
}
isoInt32 float_toInt32(isoVariable* var, isoVM* vm)
{
    return (isoInt32)var->m_float;
}
isoInt64 float_toInt64(isoVariable* var, isoVM* vm)
{
    return (isoInt64)var->m_float;
}
isoFloat float_toFloat(isoVariable* var, isoVM* vm)
{
    return (isoFloat)var->m_float;
}
isoDouble float_toDouble(isoVariable* var, isoVM* vm)
{
    return (isoDouble)var->m_float;
}
std::string float_toStr(isoVariable* var, isoVM* vm)
{
    std::stringstream ss;
    //ss.precision(1);
    ss <<  var->m_float << "f";
    return ss.str();
}
void float_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'float'");
}

//======================================
//double base functions
bool double_toBool(isoVariable* var, isoVM* vm)
{
    return var->m_double != 0;
}
isoInt32 double_toInt32(isoVariable* var, isoVM* vm)
{
    return (isoInt32)var->m_double;
}
isoInt64 double_toInt64(isoVariable* var, isoVM* vm)
{
    return (isoInt64)var->m_double;
}
isoFloat double_toFloat(isoVariable* var, isoVM* vm)
{
    return (isoFloat)var->m_double;
}
isoDouble double_toDouble(isoVariable* var, isoVM* vm)
{
    return (isoDouble)var->m_double;
}
std::string double_toStr(isoVariable* var, isoVM* vm)
{
    std::stringstream ss;
    //ss.precision(1);
    ss << std::fixed << var->m_double;
    return ss.str();
}
void double_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'double'");
}

//======================================
//string base functions
bool str_toBool(isoVariable* var, isoVM* vm)
{
    return true;
}
isoInt32 str_toInt32(isoVariable* var, isoVM* vm)
{
    isoInt32 v;
    if(!convertFromString(v, ((isoString*)var->m_gcobj)->m_data))
    {
        vm->runtimeError("Error: attempt to convert 'string' to 'int32'");
    }
    return v;
}
isoInt64 str_toInt64(isoVariable* var, isoVM* vm)
{
    isoInt64 v;
    if(!convertFromString(v, ((isoString*)var->m_gcobj)->m_data))
    {
        vm->runtimeError("Error: attempt to convert 'string' to 'int64'");
    }
    return v;
}
isoFloat str_toFloat(isoVariable* var, isoVM* vm)
{
    isoFloat v;
    if(!convertFromString(v, ((isoString*)var->m_gcobj)->m_data))
    {
        vm->runtimeError("Error: attempt to convert 'string' to 'float'");
    }
    return v;
}
isoDouble str_toDouble(isoVariable* var, isoVM* vm)
{
    isoDouble v;
    if(!convertFromString(v, ((isoString*)var->m_gcobj)->m_data))
    {
        vm->runtimeError("Error: attempt to convert 'string' to 'double'");
    }
    return v;
}
std::string str_toStr(isoVariable* var, isoVM* vm)
{
    return ((isoString*)var->m_gcobj)->m_data;
}
void str_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call a 'string'");
}

//======================================
//array base functions
bool arr_toBool(isoVariable* var, isoVM* vm)
{
    return true;
}
isoInt32 arr_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'array' to 'int32'");
    return 0;
}
isoInt64 arr_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'array' to 'int64'");
    return 0;
}
isoFloat arr_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'array' to 'float'");
    return 0;
}
isoDouble arr_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'array' to 'double'");
    return 0;
}
std::string arr_toStr(isoVariable* var, isoVM* vm)
{
    char buf[32];
    sprintf(buf, "array: 0x%08x", (size_t)var->m_gcobj);
    return std::string(buf);
}
void arr_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'array'");
}

//======================================
//table base functions
bool tab_toBool(isoVariable* var, isoVM* vm)
{
    return true;
}
isoInt32 tab_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'table' to 'int32'");
    return 0;
}
isoInt64 tab_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'table' to 'int64'");
    return 0;
}
isoFloat tab_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'table' to 'float'");
    return 0;
}
isoDouble tab_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'table' to 'double'");
    return 0;
}
std::string tab_toStr(isoVariable* var, isoVM* vm)
{
    char buf[32];
    sprintf(buf, "table: 0x%08x", (size_t)var->m_gcobj);
    return std::string(buf);
}
void tab_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    vm->runtimeError("Error: attempt to call 'table'");
}

//======================================
//function base functions
bool func_toBool(isoVariable* var, isoVM* vm)
{
    return true;
}
isoInt32 func_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'function' to 'int32'");
    return 0;
}
isoInt64 func_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'function' to 'int64'");
    return 0;
}
isoFloat func_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'function' to 'float'");
    return 0;
}
isoDouble func_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'function' to 'double'");
    return 0;
}
std::string func_toStr(isoVariable* var, isoVM* vm)
{
    char buf[32];
    sprintf(buf, "function: 0x%08x", (size_t)var->m_gcobj);
    return std::string(buf);
}
void func_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    isoFunction* func = (isoFunction*)var->m_gcobj;
    isoFunctionData* funcData = (isoFunctionData*)func->m_funcData;

    typedef void (*PFN)(void*, void*, void*);
    if(funcData->m_funcPtr == 0)
    {
        Module* mod = funcData->m_llvmFunc->getParent();
        ExecutionEngine* ee = vm->getExecutionEngine(mod);
        funcData->m_funcPtr = ee->getPointerToFunction(funcData->m_llvmFunc);
    }
    PFN pfn = reinterpret_cast<PFN>(funcData->m_funcPtr);
    pfn(thisVar, argArray, func->m_upValueTable);
}

//======================================
//delegate base functions
bool dele_toBool(isoVariable* var, isoVM* vm)
{
    return true;
}
isoInt32 dele_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'delegate' to 'int32'");
    return 0;
}
isoInt64 dele_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'delegate' to 'int64'");
    return 0;
}
isoFloat dele_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'delegate' to 'float'");
    return 0;
}
isoDouble dele_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'delegate' to 'double'");
    return 0;
}
std::string dele_toStr(isoVariable* var, isoVM* vm)
{
    char buf[32];
    sprintf(buf, "delegate: 0x%08x", (size_t)var->m_gcobj);
    return std::string(buf);
}
void dele_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    isoDelegate* dele = (isoDelegate*)var->m_gcobj;
    switch(dele->m_funcVar->m_valueType)
    {
    case isoVT_FUNCTION:
        {
            isoFunction* func = (isoFunction*)dele->m_funcVar->m_gcobj;
            isoFunctionData* funcData = (isoFunctionData*)func->m_funcData;
            typedef void(*PFN)(void*, void*, void*);
            if(funcData->m_funcPtr == 0)
            {
                Module* mod = funcData->m_llvmFunc->getParent();
                ExecutionEngine* ee = vm->getExecutionEngine(mod);
                funcData->m_funcPtr = ee->getPointerToFunction(funcData->m_llvmFunc);
            }
            PFN pfn = reinterpret_cast<PFN>(funcData->m_funcPtr);
            pfn(thisVar, argArray, func->m_upValueTable);
        }
        break;
    case isoVT_USERFUNC:
        {
            isoGarbageCollector* gc = vm->getGarbageCollector();
            isoVariable* retVar = (isoVariable*)gc->createObject(isoVT_NULL);
            gc->addTempObj(retVar);

            isoUserFunc* uf = (isoUserFunc*)dele->m_funcVar->m_gcobj;
            typedef void(*PFN)(void*, void*, void*, void*);
            PFN pfn = reinterpret_cast<PFN>(uf->m_funcPtr);
            pfn(thisVar, argArray, retVar, vm);

            //set ret var
            if(argArray->size() > 0)
            {
                argArray->set(0, retVar);
            }
            else
            {
                argArray->add(retVar);
            }
            gc->removeTempObj(retVar);
        }
    default:
        {
            char msg[128];
            sprintf(msg, "Error: attempt to call a '%s'", getVarTypeStr(dele->m_funcVar->m_valueType).c_str());
            vm->runtimeError(msg);
        }
        break;
    }
}

//======================================
//userfunc base functions
bool uf_toBool(isoVariable* var, isoVM* vm)
{
    return true;
}
isoInt32 uf_toInt32(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'userfunc' to 'int32'");
    return 0;
}
isoInt64 uf_toInt64(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'userfunc' to 'int64'");
    return 0;
}
isoFloat uf_toFloat(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'userfunc' to 'float'");
    return 0;
}
isoDouble uf_toDouble(isoVariable* var, isoVM* vm)
{
    vm->runtimeError("Error: attempt to convert 'userfunc' to 'double'");
    return 0;
}
std::string uf_toStr(isoVariable* var, isoVM* vm)
{
    char buf[32];
    sprintf(buf, "userfunc: 0x%08x", (size_t)var->m_gcobj);
    return std::string(buf);
}
void uf_funcCall(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    //ExecutionEngine* ee = vm->getExecutionEngine();
    isoGarbageCollector* gc = vm->getGarbageCollector();

    //ret var = null
    isoVariable* retVar = (isoVariable*)gc->createObject(isoVT_NULL);
    gc->addTempObj(retVar);

    isoUserFunc* uf = (isoUserFunc*)var->m_gcobj;

    typedef void(*PFN)(void*, void*, void*, void*);
    PFN pfn = reinterpret_cast<PFN>(uf->m_funcPtr);
    pfn(thisVar, argArray, retVar, vm);

    //set ret var
    if(argArray->size() > 0)
    {
        argArray->set(0, retVar);
    }
    else
    {
        argArray->add(retVar);
    }
    gc->removeTempObj(retVar);
}

//======================================
static void* null_baseFuncPtrs[isoBF_MAX] =
{
    (void*)null_toBool,
    (void*)null_toInt32,
    (void*)null_toInt64,
    (void*)null_toFloat,
    (void*)null_toDouble,
    (void*)null_toStr,
    (void*)null_funcCall
};
static void* bool_baseFuncPtrs[isoBF_MAX] =
{
    (void*)bool_toBool,
    (void*)bool_toInt32,
    (void*)bool_toInt64,
    (void*)bool_toFloat,
    (void*)bool_toDouble,
    (void*)bool_toStr,
    (void*)bool_funcCall
};
static void* int32_baseFuncPtrs[isoBF_MAX] =
{
    (void*)int32_toBool,
    (void*)int32_toInt32,
    (void*)int32_toInt64,
    (void*)int32_toFloat,
    (void*)int32_toDouble,
    (void*)int32_toStr,
    (void*)int32_funcCall
};
static void* int64_baseFuncPtrs[isoBF_MAX] =
{
    (void*)int64_toBool,
    (void*)int64_toInt32,
    (void*)int64_toInt64,
    (void*)int64_toFloat,
    (void*)int64_toDouble,
    (void*)int64_toStr,
    (void*)int64_funcCall
};
static void* float_baseFuncPtrs[isoBF_MAX] =
{
    (void*)float_toBool,
    (void*)float_toInt32,
    (void*)float_toInt64,
    (void*)float_toFloat,
    (void*)float_toDouble,
    (void*)float_toStr,
    (void*)float_funcCall
};
static void* double_baseFuncPtrs[isoBF_MAX] =
{
    (void*)double_toBool,
    (void*)double_toInt32,
    (void*)double_toInt64,
    (void*)double_toFloat,
    (void*)double_toDouble,
    (void*)double_toStr,
    (void*)double_funcCall
};
static void* str_baseFuncPtrs[isoBF_MAX] =
{
    (void*)str_toBool,
    (void*)str_toInt32,
    (void*)str_toInt64,
    (void*)str_toFloat,
    (void*)str_toDouble,
    (void*)str_toStr,
    (void*)str_funcCall
};
static void* arr_baseFuncPtrs[isoBF_MAX] =
{
    (void*)arr_toBool,
    (void*)arr_toInt32,
    (void*)arr_toInt64,
    (void*)arr_toFloat,
    (void*)arr_toDouble,
    (void*)arr_toStr,
    (void*)arr_funcCall
};
static void* tab_baseFuncPtrs[isoBF_MAX] =
{
    (void*)tab_toBool,
    (void*)tab_toInt32,
    (void*)tab_toInt64,
    (void*)tab_toFloat,
    (void*)tab_toDouble,
    (void*)tab_toStr,
    (void*)tab_funcCall
};
static void* func_baseFuncPtrs[isoBF_MAX] =
{
    (void*)func_toBool,
    (void*)func_toInt32,
    (void*)func_toInt64,
    (void*)func_toFloat,
    (void*)func_toDouble,
    (void*)func_toStr,
    (void*)func_funcCall
};
static void* dele_baseFuncPtrs[isoBF_MAX] =
{
    (void*)dele_toBool,
    (void*)dele_toInt32,
    (void*)dele_toInt64,
    (void*)dele_toFloat,
    (void*)dele_toDouble,
    (void*)dele_toStr,
    (void*)dele_funcCall
};
static void* uf_baseFuncPtrs[isoBF_MAX] =
{
    (void*)uf_toBool,
    (void*)uf_toInt32,
    (void*)uf_toInt64,
    (void*)uf_toFloat,
    (void*)uf_toDouble,
    (void*)uf_toStr,
    (void*)uf_funcCall
};
//======================================
void isoVariable::setBaseFuncPtrs(isoVariable* var)
{
    switch(var->m_valueType)
    {
    case isoVT_NULL:
        var->m_baseFuncPtrs = null_baseFuncPtrs;
        break;
    case isoVT_BOOL:
        var->m_baseFuncPtrs = bool_baseFuncPtrs;
        break;
    case isoVT_INT32:
        var->m_baseFuncPtrs = int32_baseFuncPtrs;
        break;
    case isoVT_INT64:
        var->m_baseFuncPtrs = int64_baseFuncPtrs;
        break;
    case isoVT_FLOAT:
        var->m_baseFuncPtrs = float_baseFuncPtrs;
        break;
    case isoVT_DOUBLE:
        var->m_baseFuncPtrs = double_baseFuncPtrs;
        break;
    case isoVT_STRING:
        var->m_baseFuncPtrs = str_baseFuncPtrs;
        break;
    case isoVT_ARRAY:
        var->m_baseFuncPtrs = arr_baseFuncPtrs;
        break;
    case isoVT_TABLE:
        var->m_baseFuncPtrs = tab_baseFuncPtrs;
        break;
    case isoVT_FUNCTION:
        var->m_baseFuncPtrs = func_baseFuncPtrs;
        break;
    case isoVT_DELEGATE:
        var->m_baseFuncPtrs = dele_baseFuncPtrs;
        break;
    case isoVT_USERFUNC:
        var->m_baseFuncPtrs = uf_baseFuncPtrs;
        break;
    default:
        break;
    }
}

//======================================
//for codegen
bool toBool(isoVariable* var, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_TOBOOL];
    return ((bool(*)(isoVariable*, isoVM*))fp)(var, vm);
}
isoInt32 toInt32(isoVariable* var, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_TOINT32];
    return ((isoInt32(*)(isoVariable*, isoVM*))fp)(var, vm);
}
isoInt64 toInt64(isoVariable* var, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_TOINT64];
    return ((isoInt64(*)(isoVariable*, isoVM*))fp)(var, vm);
}
isoFloat toFloat(isoVariable* var, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_TOFLOAT];
    return ((isoFloat(*)(isoVariable*, isoVM*))fp)(var, vm);
}
isoDouble toDouble(isoVariable* var, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_TODOUBLE];
    return ((isoDouble(*)(isoVariable*, isoVM*))fp)(var, vm);
}
std::string toString(isoVariable* var, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_TOSTR];
    return ((std::string(*)(isoVariable*, isoVM*))fp)(var, vm);
}
void callFunction(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm)
{
    void* fp = var->m_baseFuncPtrs[isoBF_CALL];
    return ((void(*)(isoVariable*, isoVariable*, isoArray*, isoVM*))fp)(var, thisVar, argArray, vm);
}

//======================================
void addInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt32 a = toInt32(v1, vm);
    isoInt32 b = toInt32(v2, vm);
    ret->setValue(a + b);
}

void subInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt32 a = toInt32(v1, vm);
    isoInt32 b = toInt32(v2, vm);
    ret->setValue(a - b);
}

void mulInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt32 a = toInt32(v1, vm);
    isoInt32 b = toInt32(v2, vm);
    ret->setValue(a * b);
}

void divInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt32 a = toInt32(v1, vm);
    isoInt32 b = toInt32(v2, vm);
    ret->setValue(a / b);
}

void modInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt32 a = toInt32(v1, vm);
    isoInt32 b = toInt32(v2, vm);
    ret->setValue(a % b);
}

void addInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt64 a = toInt64(v1, vm);
    isoInt64 b = toInt64(v2, vm);
    ret->setValue(a + b);
}

void subInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt64 a = toInt64(v1, vm);
    isoInt64 b = toInt64(v2, vm);
    ret->setValue(a - b);
}

void mulInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt64 a = toInt64(v1, vm);
    isoInt64 b = toInt64(v2, vm);
    ret->setValue(a * b);
}

void divInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt64 a = toInt64(v1, vm);
    isoInt64 b = toInt64(v2, vm);
    ret->setValue(a / b);
}

void modInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoInt64 a = toInt64(v1, vm);
    isoInt64 b = toInt64(v2, vm);
    ret->setValue(a % b);
}

void addFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoFloat a = toFloat(v1, vm);
    isoFloat b = toFloat(v2, vm);
    ret->setValue(a + b);
}

void subFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoFloat a = toFloat(v1, vm);
    isoFloat b = toFloat(v2, vm);
    ret->setValue(a - b);
}

void mulFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoFloat a = toFloat(v1, vm);
    isoFloat b = toFloat(v2, vm);
    ret->setValue(a * b);
}

void divFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoFloat a = toFloat(v1, vm);
    isoFloat b = toFloat(v2, vm);
    ret->setValue(a / b);
}

void modFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoFloat a = toFloat(v1, vm);
    isoFloat b = toFloat(v2, vm);
    ret->setValue(fmod(a, b));
}

void addDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoDouble a = toDouble(v1, vm);
    isoDouble b = toDouble(v2, vm);
    ret->setValue(a + b);
}

void subDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoDouble a = toDouble(v1, vm);
    isoDouble b = toDouble(v2, vm);
    ret->setValue(a - b);
}

void mulDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoDouble a = toDouble(v1, vm);
    isoDouble b = toDouble(v2, vm);
    ret->setValue(a * b);
}

void divDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoDouble a = toDouble(v1, vm);
    isoDouble b = toDouble(v2, vm);
    ret->setValue(a / b);
}

void modDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    isoDouble a = toDouble(v1, vm);
    isoDouble b = toDouble(v2, vm);
    ret->setValue(fmod(a, b));
}

void addString(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm)
{
    std::string a = toString(v1, vm);
    std::string b = toString(v2, vm);
    isoString* s = (isoString*)vm->getGarbageCollector()->createObject(isoVT_STRING);
    s->setData(a + b);
    ret->setValue(s);
}