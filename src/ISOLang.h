/*
This library is distributed under the MIT License:
[http://opensource.org/licenses/mit-license.php]

ISO-Lang Programming Library
Copyright (c) 2015 Lobsiinvok

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef ISOLANG_H
#define ISOLANG_H

#include <llvm/Support/DataTypes.h>

typedef int8_t      isoInt8;
typedef uint8_t     isoUInt8;
typedef int16_t     isoInt16;
typedef uint16_t    isoUInt16;
typedef int32_t     isoInt32;
typedef uint32_t    isoUInt32;
typedef int64_t     isoInt64;
typedef uint64_t    isoUInt64;

typedef float       isoFloat;
typedef double      isoDouble;

//typedef acUInt8     isoBool;
//typedef acInt8      isoByte;
//typedef acUInt8     isoUbyte;
//typedef acInt16     isoShort;
//typedef acUInt16    isoUshort;
//typedef acInt32     isoInt;
//typedef acUInt32    isoUInt;
//typedef acInt64     isoLong;
//typedef acUInt64    isoUlong;
typedef isoUInt8     isoChar;
typedef isoUInt16    isoWchar;
typedef isoUInt32    isoDchar;

//typedef size_t      isoPointer;

#endif //SIOLANG_H