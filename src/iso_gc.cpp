/* see copyright notice in isolang.h */

#include "iso_gc.h"
#include "iso_vm.h"
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <stdio.h>
#include <string.h>


isoGCObject* isoGarbageCollector::createObject(isoVarType type)
{
    isoGCObject* obj;
    
    switch(type)
    {
    case isoVT_NULL:
    case isoVT_BOOL:
    case isoVT_INT32:
    case isoVT_INT64:
    case isoVT_FLOAT:
    case isoVT_DOUBLE:
        {
            isoVariable* var = new isoVariable();
            var->m_valueType = type;
            isoVariable::setBaseFuncPtrs(var);
            obj = var;
        }
        break;
    case isoVT_VAR:
        obj = new isoVariable();
        //isoVariable::setBaseFuncPtrs((isoVariable*)obj);
        break;
    case isoVT_STRING:
        obj = new isoString();
        break;
    case isoVT_ARRAY:
        obj = new isoArray();
        break;
    case isoVT_TABLE:
        obj = new isoTable();
        break;
    case isoVT_FUNCTION:
        obj = new isoFunction();
        break;
    case isoVT_DELEGATE:
        obj = new isoDelegate();
        break;

    case isoVT_USERDATA:
        //obj = new isoUserData();//TODO
        break;
    case isoVT_USERFUNC:
        obj = new isoUserFunc();
        break;

    case isoVT_FUNCBINDER:
        {
            isoFuncBinder* fb = new isoFuncBinder();
            fb->m_funcTable = (isoTable*)createObject(isoVT_TABLE);
            obj = fb;
        }
        break;

    case isoVT_FUNCTIONDATA:
        obj = new isoFunctionData();
        break;
    }

    m_objectList.push_back(obj);
    initGCColor(obj);
    return obj;
}

isoVariable* isoGarbageCollector::createVarWithData(const char* data)
{
    isoString* str = (isoString*)createObject(isoVT_STRING);
    str->setData(data);
    isoVariable* var = (isoVariable*)createObject(isoVT_VAR);
    var->setValue(str);
    return var;
}

isoVariable* isoGarbageCollector::createVarWithData(isoInt32 data)
{
    isoVariable* var = (isoVariable*)createObject(isoVT_INT32);
    var->m_int32 = data;
    return var;
}

void isoGarbageCollector::incrementalGC(clock_t clocks)
{
    switch(m_state)
    {
    case INIT:
        if(gcInit())
        {
            m_state = MARK;
        }
        break;
    case MARK:
        if(gcMark(clocks))
        {
            m_state = SWEEP;
        }
        break;
    case SWEEP:
        if(gcSweep(clocks))
        {
            m_state = FINAL;
        }
        break;
    case FINAL:
        if(gcFinal(clocks))
        {
            m_state = INIT;
        }
        break;
    }
}

void isoGarbageCollector::completeGC()
{
    do
    {
        incrementalGC(0x7FFFFFFF);
    }
    while(m_state != INIT);
}

void isoGarbageCollector::changeGCColor(isoGCObject* obj)
{
    if(m_state == MARK)
    {
        if(obj->m_gcColor == GC_WHITE)
        {
            switch(obj->m_objType)
            {
            case isoVT_VAR:
            case isoVT_ARRAY:
            case isoVT_TABLE:
            case isoVT_FUNCTION:
            case isoVT_DELEGATE:
            case isoVT_USERFUNC:
            case isoVT_FUNCBINDER:
                obj->m_gcColor = GC_GRAY;
                m_grayList.insert(obj);
                break;
            default:
                obj->m_gcColor = GC_BLACK;
                break;
            }
        }
    }
}

void isoGarbageCollector::initGCColor(isoGCObject* obj)
{
    if(m_state == MARK)
    {
        obj->m_gcColor = GC_BLACK;
    }
    else
    {
        obj->m_gcColor = GC_WHITE;
    }
}

void isoGarbageCollector::addToGrayList(std::list<isoGCObject*>& list)
{
    std::list<isoGCObject*>::iterator it = list.begin();
    std::list<isoGCObject*>::iterator itEnd = list.end();
    while(it != itEnd)
    {
        isoGCObject* obj = *it;
        obj->m_gcColor = GC_BLACK;
        switch(obj->m_objType)
        {
        case isoVT_VAR:
            addChildrenToGrayList((isoVariable*)obj);
            break;
        case isoVT_ARRAY:
            addChildrenToGrayList((isoArray*)obj);
            break;
        case isoVT_TABLE:
            addChildrenToGrayList((isoTable*)obj);
            break;
        case isoVT_FUNCTION:
            addChildrenToGrayList((isoFunction*)obj);
            break;
        case isoVT_DELEGATE:
            addChildrenToGrayList((isoDelegate*)obj);
            break;
        case isoVT_USERFUNC:
            addChildrenToGrayList((isoUserFunc*)obj);
            break;
        case isoVT_FUNCBINDER:
            addChildrenToGrayList((isoFuncBinder*)obj);
            break;
        }
        ++it;
    }
}

bool isoGarbageCollector::gcInit()
{
    if(m_objectList.size() == 0) return false;

    //all objects are white, add children in roottable to grayList
    addToGrayList(m_rootList);
    addToGrayList(m_tempList);

    m_sweepIter = m_objectList.begin();
    m_sweepLastIter = m_objectList.end();
    //point to last object, not end-iterator
    --m_sweepLastIter;

    return true;
}

bool isoGarbageCollector::gcMark(clock_t clocks)
{
    clock_t beginClock = clock();

    if(m_grayList.size() != 0)
    {
        do
        {
            std::set<isoGCObject*>::iterator it = m_grayList.begin();
            isoGCObject* obj = *it;

            obj->m_gcColor = GC_BLACK;

            switch(obj->m_objType)
            {
            case isoVT_VAR:
                addChildrenToGrayList((isoVariable*)obj);
                break;
            case isoVT_ARRAY:
                addChildrenToGrayList((isoArray*)obj);
                break;
            case isoVT_TABLE:
                addChildrenToGrayList((isoTable*)obj);
                break;
            case isoVT_FUNCTION:
                addChildrenToGrayList((isoFunction*)obj);
                break;
            case isoVT_DELEGATE:
                addChildrenToGrayList((isoDelegate*)obj);
                break;
            case isoVT_USERFUNC:
                addChildrenToGrayList((isoUserFunc*)obj);
                break;
            case isoVT_FUNCBINDER:
                addChildrenToGrayList((isoFuncBinder*)obj);
                break;
            }

            m_grayList.erase(it);
        }
        while((m_grayList.size() != 0) && (clock() - beginClock < clocks));
    }

    return m_grayList.size() == 0;
}

bool isoGarbageCollector::gcSweep(clock_t clocks)
{
    clock_t beginClock = clock();

    bool isLast = false;
    do
    {
        isLast = (m_sweepIter == m_sweepLastIter);
        isoGCObject* obj = *m_sweepIter;

        if(obj->m_gcColor == GC_WHITE)
        {
            //delete variable
            switch(obj->m_objType)
            {
            case isoVT_VAR:
                if(m_printGC)
                    printf("gc: delete var: %p\n", obj);

                delete (isoVariable*)obj;
                break;

            case isoVT_STRING:
                if(m_printGC)
                    printf("gc: delete string: %p\n", obj);

                ((isoString*)obj)->m_data.clear();
                delete (isoString*)obj;
                break;

            case isoVT_ARRAY:
                if(m_printGC)
                    printf("gc: delete array: %p\n", obj);

                ((isoArray*)obj)->m_data.clear();
                delete (isoArray*)obj;
                break;

            case isoVT_TABLE:
                if(m_printGC)
                    printf("gc: delete table: %p\n", obj);

                ((isoTable*)obj)->m_data.clear();
                delete (isoTable*)obj;
                break;

            case isoVT_FUNCTION:
                if(m_printGC)
                    printf("gc: delete function: %p\n", obj);

                {
                    isoFunction* func = (isoFunction*)obj;
                    delete func->m_createdFuncDataList;
                    delete func;
                }
                break;

            case isoVT_DELEGATE:
                if(m_printGC)
                    printf("gc: delete delegate: %p\n", obj);

                //TODO
                delete (isoDelegate*)obj;
                break;

            case isoVT_USERFUNC:
                if(m_printGC)
                    printf("gc: delete userfunc: %p\n", obj);

                //TODO
                delete (isoUserFunc*)obj;
                break;

            case isoVT_FUNCBINDER:
                if(m_printGC)
                    printf("gc: delete funcbinder: %p\n", obj);

                delete (isoFuncBinder*)obj;
                break;

            case isoVT_FUNCTIONDATA:
                if(m_printGC)
                    printf("gc: delete funcdata: %p\n", obj);

                {
                    isoFunctionData* funcData = (isoFunctionData*)obj;
                    //ExecutionEngine* ee = m_vm->getExecutionEngine();
                    //ee->freeMisohineCodeForFunction(funcData->m_llvmFunc);
                    //funcData->m_llvmFunc->replisoeAllUsesWith(UndefValue::get(funcData->m_llvmFunc->getType()));
                    //funcData->m_llvmFunc->deleteBody();
                    //funcData->m_llvmFunc->eraseFromParent();
                    Module* mod = funcData->m_llvmFunc->getParent();
                    m_vm->decFunctionCount(mod);

                    delete funcData->m_stringList;
                    delete funcData->m_debugInfoList;
                    delete funcData;
                }
                break;

            default:
                break;
            }

            m_sweepIter = m_objectList.erase(m_sweepIter);
        }
        else
        {
            obj->m_gcColor = GC_WHITE;
            ++m_sweepIter;
        }
    }
    while((!isLast) && (clock() - beginClock < clocks));

    return isLast;
}

bool isoGarbageCollector::gcFinal(clock_t clocks)
{
    clock_t beginClock = clock();
    std::list<isoGCObject*>::iterator endIter = m_objectList.end();

    //mark new created objects between GC cycle as white
    if(m_sweepIter != endIter)
    {
        do
        {
            (*m_sweepIter)->m_gcColor = GC_WHITE;

            if(++m_sweepIter == endIter)
            {
                return true;
            }
        }
        while(clock() - beginClock < clocks);

        return false;
    }

    return true;
}

void isoGarbageCollector::addChildrenToGrayList(isoVariable* var)
{
    switch(var->m_valueType)
    {
    case isoVT_STRING:
    case isoVT_FUNCTIONDATA:
        var->m_gcobj->m_gcColor = GC_BLACK;
        break;
    case isoVT_VAR:
    case isoVT_ARRAY:
    case isoVT_TABLE:
    case isoVT_FUNCTION:
    case isoVT_DELEGATE:
    case isoVT_USERFUNC:
    case isoVT_FUNCBINDER:
        {
            isoGCObject* obj = var->m_gcobj;
            if(obj->m_gcColor == GC_WHITE)
            {
                obj->m_gcColor = GC_GRAY;
                m_grayList.insert(obj);
            }
        }
        break;
    default:
        break;
    }
}

void isoGarbageCollector::addChildrenToGrayList(isoArray* array)
{
    std::vector<isoVariable*>::iterator it = array->m_data.begin();
    std::vector<isoVariable*>::iterator itend = array->m_data.end();

    while(it != itend)
    {
        isoVariable* var = *it;
        var->m_gcColor = GC_BLACK;

        switch(var->m_valueType)
        {
        case isoVT_STRING:
        case isoVT_FUNCTIONDATA:
            var->m_gcobj->m_gcColor = GC_BLACK;
            break;
        case isoVT_VAR:
        case isoVT_ARRAY:
        case isoVT_TABLE:
        case isoVT_FUNCTION:
        case isoVT_DELEGATE:
        case isoVT_USERFUNC:
        case isoVT_FUNCBINDER:
            {
                isoGCObject* obj = var->m_gcobj;
                if(obj->m_gcColor == GC_WHITE)
                {
                    obj->m_gcColor = GC_GRAY;
                    m_grayList.insert(obj);
                }
            }
            break;
        default:
            break;
        }
        ++it;
    }
}

void isoGarbageCollector::addChildrenToGrayList(isoTable* table)
{
    isoTable::DataIterator it = table->m_data.begin();
    isoTable::DataIterator itend = table->m_data.end();

    while(it != itend)
    {
        isoTable::KeyValue kv = it->second;

        isoVariable* key = kv.key;
        key->m_gcColor = GC_BLACK;
        switch(key->m_valueType)
        {
        case isoVT_STRING:
        case isoVT_FUNCTIONDATA:
            key->m_gcobj->m_gcColor = GC_BLACK;
            break;
        case isoVT_VAR:
        case isoVT_ARRAY:
        case isoVT_TABLE:
        case isoVT_FUNCTION:
        case isoVT_DELEGATE:
        case isoVT_USERFUNC:
        case isoVT_FUNCBINDER:
            {
                isoGCObject* obj = key->m_gcobj;
                if(obj->m_gcColor == GC_WHITE)
                {
                    obj->m_gcColor = GC_GRAY;
                    m_grayList.insert(obj);
                }
            }
            break;
        default:
            break;
        }

        isoVariable* var = kv.value;
        var->m_gcColor = GC_BLACK;
        switch(var->m_valueType)
        {
        case isoVT_STRING:
        case isoVT_FUNCTIONDATA:
            var->m_gcobj->m_gcColor = GC_BLACK;
            break;
        case isoVT_VAR:
        case isoVT_ARRAY:
        case isoVT_TABLE:
        case isoVT_FUNCTION:
        case isoVT_DELEGATE:
        case isoVT_USERFUNC:
        case isoVT_FUNCBINDER:
            {
                isoGCObject* obj = var->m_gcobj;
                if(obj->m_gcColor == GC_WHITE)
                {
                    obj->m_gcColor = GC_GRAY;
                    m_grayList.insert(obj);
                }
            }
            break;
        default:
            break;
        }
        ++it;
    }

    if(table->m_funcBinder != 0)
    {
        table->m_funcBinder->m_gcColor = GC_BLACK;
        addChildrenToGrayList(table->m_funcBinder);
    }
}

void isoGarbageCollector::addChildrenToGrayList(isoFunction* func)
{
    func->m_funcData->m_gcColor = GC_BLACK;

    if(func->m_upValueTable != 0)
    {
        func->m_upValueTable->m_gcColor = GC_BLACK;
        addChildrenToGrayList(func->m_upValueTable);
    }

    if(func->m_createdFuncDataList != 0)
    {
        addToGrayList(*(func->m_createdFuncDataList));
    }
}

void isoGarbageCollector::addChildrenToGrayList(isoDelegate* dele)
{
    if(dele->m_funcVar != 0)
    {
        dele->m_funcVar->m_gcColor = GC_BLACK;
        addChildrenToGrayList(dele->m_funcVar);
    }
}

void isoGarbageCollector::addChildrenToGrayList(isoFuncBinder* fb)
{
    if(fb->m_funcTable != 0)
    {
        fb->m_funcTable->m_gcColor = GC_BLACK;
        addChildrenToGrayList(fb->m_funcTable);
    }

    //all functions are in funcTable
    //for(int i = 0; i < isoOF_MAX; ++i)
    //{
    //    isoGCObject* func = fb->m_funcArray[i];
    //    if(func != 0)
    //    {
    //    }
    //}
}

void isoGarbageCollector::addChildrenToGrayList(isoUserFunc* uf)
{
}