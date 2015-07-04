/* see copyright notice in isolang.h */

#ifndef ISO_GC_H
#define ISO_GC_H

#include "iso_variable.h"
#include <list>
#include <set>
#include <string>
#include <vector>
#include <time.h>

class isoVM;

class isoGarbageCollector
{
public:
    enum CollectionState
    {
        INIT,
        MARK,
        SWEEP,
        FINAL
    };

    enum GC_Color
    {
        GC_WHITE = 0,//unused
        GC_GRAY  = 1,//parent is used, self is not processed yet
        GC_BLACK = 2 //used
    };


private:
    isoVM* m_vm;
    CollectionState m_state;
    std::list<isoGCObject*> m_rootList;
    std::list<isoGCObject*> m_tempList;//store temp variables to avoid being GCed
    std::list<isoGCObject*> m_objectList;
    std::list<isoGCObject*>::iterator m_sweepIter, m_sweepLastIter;
    std::set<isoGCObject*> m_grayList;

    //for debug
    bool m_printGC;
public:
    isoGarbageCollector(isoVM* vm)
        : m_vm(vm)
        , m_state(INIT)
        , m_printGC(false)
    {
    }

    isoGCObject* createObject(isoVarType type);
    isoVariable* createVarWithData(const char* data);
    isoVariable* createVarWithData(isoInt32 data);

    isoVM* getVM() { return m_vm; }

    void addRootObj(isoGCObject* obj) { m_rootList.push_back(obj); }
    void addTempObj(isoGCObject* obj) { m_tempList.push_back(obj); }
    void removeTempObj(isoGCObject* obj) { m_tempList.remove(obj); }
    void clearTempObj() { m_tempList.clear(); }

    void incrementalGC(clock_t clocks);//run incremental gc
    void completeGC();//run one complete gc
    CollectionState getGCState() { return m_state; }
    void changeGCColor(isoGCObject* obj);

    size_t getObjectListCount() { return m_objectList.size(); }
    size_t getGrayListCount() { return m_grayList.size(); }

    void setPrintGC(bool b) { m_printGC = b; }
    bool getPrintGC() { return m_printGC; }

private:    
    void initGCColor(isoGCObject* obj);
    void addToGrayList(std::list<isoGCObject*>& list);
    bool gcInit();
    bool gcMark(clock_t clocks);
    bool gcSweep(clock_t clocks);
    bool gcFinal(clock_t clocks);

    void addChildrenToGrayList(isoVariable* var);
    void addChildrenToGrayList(isoArray* array);
    void addChildrenToGrayList(isoTable* table);
    void addChildrenToGrayList(isoFunction* func);
    void addChildrenToGrayList(isoDelegate* dele);
    void addChildrenToGrayList(isoFuncBinder* fb);
    void addChildrenToGrayList(isoUserFunc* uf);
};



#endif //ISO_GC_H