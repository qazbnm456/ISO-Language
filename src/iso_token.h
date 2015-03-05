/* see copyright notice in ISOLang.h */

#ifndef ISO_TOKEN_H
#define ISO_TOKEN_H

#include "ISOLang.h"
#include <string>

struct isoToken
{
    int         m_type;
    std::string*     m_name;

    union
    {
        isoDchar     m_charValue;
        isoUInt64    m_integerValue;
        isoDouble    m_doubleValue;
        /*struct
        {
            isoDcharVector* m_string;
            isoChar m_postfix;
        };*/
    };
};

#endif //ISO_TOKEN_H