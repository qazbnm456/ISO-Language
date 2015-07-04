/* see copyright notice in ISOLang.h */

#ifndef ISO_TOKEN_H
#define ISO_TOKEN_H

#include "ISOLang.h"
#include <string>

struct isoToken
{
    int         m_type;
    std::string*     m_name;
    isoChar*     m_begin;
    isoChar*     m_end;
    int         m_beginLine;
    int         m_endLine;

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

    std::string getRawString()
    {
        return std::string(m_begin, m_end);
    }
};

#endif //ISO_TOKEN_H