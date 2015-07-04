/* see copyright notice in ISOLang.h */

#ifndef ISO_HASHVALUE_H
#define ISO_HASHVALUE_H

#include "iso_config.h"

struct isoHashValue
{
    union
    {
        struct
        {
            isoUInt32 u32_0;
            isoUInt32 u32_1;
            isoUInt32 u32_2;
            isoUInt32 u32_3;
        };

        struct
        {
            isoUInt64 u64_0;
            isoUInt64 u64_1;
        };
    };

    isoHashValue()
        : u64_0(0)
        , u64_1(0)
    {
    }

    bool equal(isoHashValue& other)
    {
        return (u64_0 == other.u64_0) && (u64_1 == other.u64_1);
    }

    int compare(isoHashValue& other)
    {
        if(u64_1 == other.u64_1)
        {
            if(u64_0 == other.u64_0)
            {
                return 0;
            }
            if(u64_0 > other.u64_0)
            {
                return 1;
            }
            return -1;
        }
        if(u64_1 > other.u64_1)
        {
            return 1;
        }
        return -1;
    }

    bool operator<(const isoHashValue& other) const
    {
        if(u64_1 == other.u64_1)
        {
            if(u64_0 >= other.u64_0)
            {
                return false;
            }
            return true;
        }
        if(u64_1 > other.u64_1)
        {
            return false;
        }
        return true;
    }
};

#endif //ISO_HASHVALUE_H