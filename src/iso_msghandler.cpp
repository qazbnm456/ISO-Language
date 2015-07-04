/* see copyright notice in isolang.h */

#include "iso_msghandler.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isoMsgHandler::setFileName(const char* filename)
{
    m_filename = filename;
}

void isoMsgHandler::error(isoToken& tok, const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    char buffer2[1024];
    sprintf(buffer2, "%s:%d: on token `%s`: %s", m_filename.c_str(), tok.m_beginLine, tok.getRawString().c_str(), buffer);
    m_printMsgFunc(MessageType::ERROR, buffer2);
}

void isoMsgHandler::error(const char *file, int line, const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    char buffer2[1024];
    sprintf(buffer2, "%s:%d: %s", file, line, buffer);
    m_printMsgFunc(MessageType::ERROR, buffer2);
}

void isoMsgHandler::error(int line, const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    char buffer2[1024];
    sprintf(buffer2, "%s:%d: %s", m_filename.c_str(), line, buffer);
    m_printMsgFunc(MessageType::ERROR, buffer2);
}

void isoMsgHandler::error(const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    m_printMsgFunc(MessageType::ERROR, buffer);
}

void isoMsgHandler::warning(const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    m_printMsgFunc(MessageType::WARNING, buffer);
}

void isoMsgHandler::info(const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    m_printMsgFunc(MessageType::INFO, buffer);
}

void isoMsgHandler::output(const char *format, ...)
{
    char buffer[1024];
    va_list ap;
    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    m_printMsgFunc(MessageType::OUTPUT, buffer);
}

void isoMsgHandler::registerPrintMsg(PrintMsg func)
{
    m_printMsgFunc = func;
}

//default printMsg function
void isoMsgHandler::printMsg(int type, const char *msg)
{
    if(type == MessageType::OUTPUT)
        printf("%s", msg);
    else
        printf("%s\n", msg);
}