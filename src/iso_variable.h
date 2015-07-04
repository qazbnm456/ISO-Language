/* see copyright notice in ISOLang.h */

#ifndef AC_VARIABLE_H
#define AC_VARIABLE_H

#include "iso_codeGenerator.h"
#include "iso_hashvalue.h"
#include <llvm/IR/Function.h>
#include <llvm/IR/Constants.h>
#include <list>
#include <map>
#include <string>
#include <vector>

class isoVM;
class isoGarbageCollector;
struct isoGCObject;
struct isoString;
struct isoArray;
struct isoTable;
struct isoFunction;
struct isoFuncBinder;
struct isoFunctionData;

enum isoVarType
{
    isoVT_NULL = 0,
    //primitive data
    isoVT_BOOL,
    isoVT_INT32,
    isoVT_INT64,
    isoVT_FLOAT,
    isoVT_DOUBLE,
    //gc object
    isoVT_VAR,
    isoVT_STRING,
    isoVT_ARRAY,
    isoVT_TABLE,
    isoVT_FUNCTION,
    isoVT_DELEGATE,
    //user data
    isoVT_USERDATA,
    isoVT_USERFUNC,
    //helper data, internal use only
    isoVT_FUNCBINDER,
    isoVT_FUNCTIONDATA,
};

enum isoBaseFunc
{
    isoBF_TOBOOL,
    isoBF_TOINT32,
    isoBF_TOINT64,
    isoBF_TOFLOAT,
    isoBF_TODOUBLE,
    isoBF_TOSTR,
    isoBF_CALL,
    isoBF_MAX
};

enum isoOperatorFunc
{
    isoOF_NEW,// new "_new"
    isoOF_ADD,// + "_add"
    isoOF_SUB,// - "_sub"
    isoOF_MUL,// * "_mul"
    isoOF_DIV,// / "_div"
    isoOF_MOD,// % "_mod"
    isoOF_MAX,
};

#pragma pack(1)
struct isoGCObject
{
    isoVarType m_objType : 8;
    isoUInt8 m_gcColor;

    isoGCObject()
    {
    }

    isoGCObject(isoVarType type)
        : m_objType(type)
    {
    }
};
#pragma pack()

#pragma pack(1)
struct isoVariable : isoGCObject
{
    isoVarType m_valueType : 8;

    union //value
    {
        isoInt32 m_int32;
        isoInt64 m_int64;
        isoFloat m_float;
        isoDouble m_double;
        isoGCObject* m_gcobj;
    };

    isoHashValue m_hash;
    void**      m_baseFuncPtrs;

    isoVariable()
    {
        setNull();
    }

    void setNull()
    {
        memset(this, 0, sizeof(isoVariable));
        m_objType = isoVT_VAR;
        setBaseFuncPtrs(this);
    }
    void setValue(bool v)
    {
        m_valueType = isoVT_BOOL;
        m_int64 = 0;
        m_int32 = v;
        setBaseFuncPtrs(this);
    }
    void setValue(isoInt32 v)
    {
        m_valueType = isoVT_INT32;
        m_int64 = 0;
        m_int32 = v;
        setBaseFuncPtrs(this);
    }
    void setValue(isoInt64 v)
    {
        m_valueType = isoVT_INT64;
        m_int64 = v;
        setBaseFuncPtrs(this);
    }
    void setValue(isoFloat v)
    {
        m_valueType = isoVT_FLOAT;
        m_int64 = 0;
        m_float = v;
        setBaseFuncPtrs(this);
    }
    void setValue(isoDouble v)
    {
        m_valueType = isoVT_DOUBLE;
        m_double = v;
        setBaseFuncPtrs(this);
    }
    void setValue(isoVariable* v)
    {
        assignFrom(v);
    }
    void setValue(isoGCObject* v)
    {
        m_valueType = v->m_objType;
        m_gcobj = v;
        setBaseFuncPtrs(this);
    }
    void setValue(const char* str, isoVM* vm);
    
    void assignFrom(isoVariable* v);
    void cloneTo(isoVariable* v, isoVM* vm);

    isoHashValue& getHash();
    static void getHash(isoInt32 value, isoHashValue& hash);
    static void getHash(isoInt64 value, isoHashValue& hash);
    static void getHash(const char* str, isoHashValue& hash);
    static void setBaseFuncPtrs(isoVariable* var);

    //return >0, =0, <0
    int compare(isoVariable* v, isoVM* vm);

    //get child var by index/key. for array & table.
    isoVariable* get(isoInt32 idx);
    isoVariable* get(isoInt64 idx);
    isoVariable* get(const char* key);
    isoVariable* get(isoVariable* key);

    isoString* toString() { return (isoString*)m_gcobj; }
    isoArray* toArray() { return (isoArray*)m_gcobj; }
    isoTable* toTable() { return (isoTable*)m_gcobj; }
};
#pragma pack()

struct isoString : isoGCObject
{
    isoUInt32 m_hash;
    isoUInt32 m_sum;
    std::string m_data;
    int m_iteratorIndex;//for foreach()

    isoString()
        : isoGCObject(isoVT_STRING)
        , m_hash(0)
    {
    }

    isoString(isoChar* begin, isoChar* end)
        : isoGCObject(isoVT_STRING)
        , m_data(begin, end)
    {
        hash();
    }

    void setData(const std::string& data)
    {
        m_data = data;
        hash();
    }

    const char* c_str() const
    {
        return m_data.c_str();
    }

    void hash();

    void initIter() { m_iteratorIndex = 0; }
    bool iterate(isoVariable* idx, isoVariable* value)
    {
        if(m_iteratorIndex < 0 || m_iteratorIndex >= (int)m_data.size())
            return false;

        if(idx != 0)
            idx->setValue(m_iteratorIndex);
        if(value != 0)
            value->setValue((int)m_data[m_iteratorIndex]);

        ++m_iteratorIndex;
        return true;
    }
};

struct isoArray : isoGCObject
{
    std::vector<isoVariable*> m_data;
    typedef std::vector<isoVariable*>::iterator DataIterator;
    int m_iteratorIndex;//for foreach()

    isoArray()
        : isoGCObject(isoVT_ARRAY)
        , m_iteratorIndex(-1)
    {
    }

    int size() { return m_data.size(); }
    void add(isoVariable* var) { m_data.push_back(var); }
    isoVariable* get(int idx) { return m_data[idx]; }
    void set(int idx, isoVariable* var) { m_data[idx] = var; }
    void fillAndSet(int idx, isoVariable* var, isoVM* vm);
    isoVariable* fillAndGet(int idx, isoVM* vm);

    void initIter() { m_iteratorIndex = 0; }
    bool iterate(isoVariable* idx, isoVariable* value)
    {
        if(m_iteratorIndex < 0 || m_iteratorIndex >= size())
            return false;

        if(idx != 0)
            idx->setValue(m_iteratorIndex);
        if(value != 0)
            value->setValue(m_data[m_iteratorIndex]);

        ++m_iteratorIndex;
        return true;
    }

    void cloneTo(isoArray* other, isoVM* vm);
};

struct isoTable : isoGCObject
{
    struct KeyValue
    {
        isoVariable* key;
        isoVariable* value;
        KeyValue(isoVariable* k, isoVariable* v)
            : key(k)
            , value(v)
        {
        }
    };

    std::map<isoHashValue, KeyValue> m_data;
    typedef std::map<isoHashValue, KeyValue>::iterator DataIterator;
    DataIterator m_iterator;//for foreach()

    isoFuncBinder* m_funcBinder;

    isoTable()
        : isoGCObject(isoVT_TABLE)
        , m_iterator(m_data.end())
        , m_funcBinder(0)
    {
    }

    void add(isoVariable* key, isoVariable* var)
    {
        isoHashValue& hash = key->getHash();
        DataIterator it = m_data.find(hash);
        if(it == m_data.end())
        {
            m_data.insert(std::make_pair(hash, KeyValue(key, var)));
        }
        else
        {
            it->second = KeyValue(key, var);
        }
    }
    //helper functions for add kv
    void add(const char* key, const char* value, isoVM* vm);
    void add(const char* key, int value, isoVM* vm);
    void add(int key, const char* value, isoVM* vm);
    void add(int key, int value, isoVM* vm);

    void remove(isoInt32 idx)
    {
        isoHashValue hash;
        isoVariable::getHash(idx, hash);
        m_data.erase(hash);
    }
    void remove(isoInt64 idx)
    {
        isoHashValue hash;
        isoVariable::getHash(idx, hash);
        m_data.erase(hash);
    }
    void remove(const char* key)
    {
        isoHashValue hash;
        isoVariable::getHash(key, hash);
        m_data.erase(hash);
    }
    void remove(isoVariable* key)
    {
        m_data.erase(key->getHash());
    }
    //get value by int32
    isoVariable* get(isoInt32 idx)
    {
        isoHashValue hash;
        isoVariable::getHash(idx, hash);
        DataIterator it = m_data.find(hash);
        if(it == m_data.end()) return 0;
        return it->second.value;
    }
    //get value by int64
    isoVariable* get(isoInt64 idx)
    {
        isoHashValue hash;
        isoVariable::getHash(idx, hash);
        DataIterator it = m_data.find(hash);
        if(it == m_data.end()) return 0;
        return it->second.value;
    }
    //get value by string
    isoVariable* get(const char* key)
    {
        isoHashValue hash;
        isoVariable::getHash(key, hash);
        DataIterator it = m_data.find(hash);
        if(it == m_data.end()) return 0;
        return it->second.value;
    }
    //get value by var
    isoVariable* get(isoVariable* key)
    {
        isoHashValue& hash = key->getHash();
        DataIterator it = m_data.find(hash);
        if(it == m_data.end()) return 0;
        return it->second.value;
    }

    void initIter() { m_iterator = m_data.begin(); }
    bool iterate(isoVariable* key, isoVariable* value)
    {
        if(m_iterator == m_data.end())
            return false;

        KeyValue& kv = m_iterator->second;

        if(key != 0)
            key->setValue(kv.key);
        if(value != 0)
            value->setValue(kv.value);

        ++m_iterator;
        return true;
    }

    void cloneTo(isoTable* other, isoVM* vm);
    void copyDataTo(isoTable* other, isoVM* vm);

    void bindFunc(char* name, isoVariable* func);
    void bindFunc(isoVariable* key, isoVariable* func, isoVM* vm);
    void bindFunc(isoTable* table, isoVM* vm);
    isoVariable* getBindFunc(isoOperatorFunc func);
    isoVariable* getBindFunc(const char* name);
    isoVariable* getBindFunc(isoVariable* key);
};

struct isoFunction : isoGCObject
{
    isoFunctionData* m_funcData;
    isoTable* m_upValueTable;
    std::list<isoGCObject*>* m_createdFuncDataList;

    isoFunction()
        : isoGCObject(isoVT_FUNCTION)
        , m_funcData(0)
        , m_upValueTable(0)
        , m_createdFuncDataList(0)
    {
    }
};

struct isoDelegate : isoGCObject
{
    isoVariable* m_thisVar;
    isoVariable* m_funcVar;

    isoDelegate()
        : isoGCObject(isoVT_DELEGATE)
        , m_thisVar(0)
        , m_funcVar(0)
    {
    }
};

struct isoUserFunc : isoGCObject
{
    void* m_funcPtr;

    isoUserFunc()
        : isoGCObject(isoVT_USERFUNC)
        , m_funcPtr(0)
    {
    }
};

struct isoFuncBinder : isoGCObject
{
    isoTable* m_funcTable;
    isoVariable* m_funcArray[isoOF_MAX];//function or userfunc

    isoFuncBinder()
        : isoGCObject(isoVT_FUNCBINDER)
        , m_funcTable(0)
    {
        memset(m_funcArray, 0, sizeof(m_funcArray));
    }

    void cloneTo(isoFuncBinder* dest, isoVM* vm);
    void bindFunc(isoVariable* key, isoVariable* func);
    void bindFunc(isoTable* table, isoVM* vm);

    isoOperatorFunc getOpFunc(isoVariable* var);
};

struct isoFunctionData : isoGCObject
{
    llvm::Function* m_llvmFunc;
    void* m_funcPtr;
    std::list<std::string>* m_stringList;
    std::list<isoDebugInfo>* m_debugInfoList;

    isoFunctionData()
        : isoGCObject(isoVT_FUNCTIONDATA)
        , m_llvmFunc(0)
        , m_funcPtr(0)
        , m_stringList(0)
        , m_debugInfoList(0)
    {
    }
};

std::string getVarTypeStr(isoVarType vt);
bool toBool(isoVariable* var, isoVM* vm);
isoInt32 toInt32(isoVariable* var, isoVM* vm);
isoInt64 toInt64(isoVariable* var, isoVM* vm);
isoFloat toFloat(isoVariable* var, isoVM* vm);
isoDouble toDouble(isoVariable* var, isoVM* vm);
std::string toString(isoVariable* var, isoVM* vm);
void callFunction(isoVariable* var, isoVariable* thisVar, isoArray* argArray, isoVM* vm);
void addInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void subInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void mulInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void divInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void modInt32(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void addInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void subInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void mulInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void divInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void modInt64(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void addFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void subFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void mulFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void divFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void modFloat(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void addDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void subDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void mulDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void divDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void modDouble(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);
void addString(isoVariable* ret, isoVariable* v1, isoVariable* v2, isoVM* vm);

#endif //ISO_VARIABLE_H