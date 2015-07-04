/* see copyright notice in isolang.h */

#ifndef ISO_MSGHANDLER_H
#define ISO_MSGHANDLER_H

#include "iso_token.h"

class isoMsgHandler
{
public:
    isoMsgHandler()
    {
        m_filename = "input";
        registerPrintMsg(printMsg);
    }

    void setFileName(const char* filename);
    std::string& getFileName() { return m_filename; }

    void error(isoToken& tok, const char *format, ...);
    void error(const char *file, int line, const char *format, ...);
    void error(int line, const char *format, ...);
    void error(const char *format, ...);
    void warning(const char *format, ...);
    void info(const char *format, ...);
    void output(const char *format, ...);

    enum MessageType
    {
        //compile-time & run-time message
        ERROR,
        WARNING,
        INFO,
        //program output, e.g. print()
        OUTPUT,
    };
    typedef void(*PrintMsg)(int type, const char *msg);
    void registerPrintMsg(PrintMsg func);

protected:
    PrintMsg m_printMsgFunc;
    std::string m_filename;
    static void printMsg(int type, const char *msg);
};


#endif // ISO_MSGHANDLER_H