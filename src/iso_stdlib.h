/* see copyright notice in isolang.h */

#ifndef ISO_STDLIB_H
#define ISO_STDLIB_H

#include "iso_config.h"

class isoVM;

class isoStdLib
{
public:
    isoStdLib() {}
    ~isoStdLib() {}
    
    static void bindStdFunctions(isoVM* vm);
};

#endif // ISO_STDLIB_H