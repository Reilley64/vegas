
// src/havok/common/base/container/string/hkstring.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstring.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/B6266F0Array.h"
#include "fnv/symbols_00c85000.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/fnv_00cb0c50__SStringPtr.h"
#include "fnv/symbols_00cb1000.h"

// @fnv 0x00cb10b0
void __cdecl CopyIfNonEmpty(char* dest, const char* src, intptr_t count)
{
    if (count)
        std::strncpy(dest, src, count);
}


// @fnv 0x00cb10f0
void __cdecl CallWithZeroMiddleArg(intptr_t aiFirst, int aiThird)
{
    std::strtoul((const char *)(aiFirst), 0, aiThird);
}

struct BSAudio;
struct UnkRet
{
    void* p;
};
struct UnkHolder
{
    UnkRet* FUN_00c85750();
};

// @fnv 0x00cb13c0
void __cdecl FUN_00cb13c0(intptr_t aiAudio)
{
    ::CallSwappedArgs((uintptr_t)((BSAudio*)aiAudio), *(int*)((char*)static_cast<BSAudio*>(::FUN_00c85750()) + 0x10));
}

// @fnv 0x00cb1110
float __cdecl ConvertToFloat(uintptr_t value)
{
    return std::strtod((const char *)(value), 0);
}

class hkBool
{
  public:
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

// Returns true if str begins with prefix by comparing characters until the prefix's null terminator.
// @fnv 0x00cb1310
hkBool StartsWith(const char* acString, const char* prefix)
{
    for (int i = 0; prefix[i] != 0; ++i)
    {
        if (acString[i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}


// Compares the tail of text against suffix and stores whether text ends with suffix into result.
// @fnv 0x00cb1340
bool* __cdecl EndsWith(bool* result, const char* text, const char* suffix)
{
    intptr_t textLength = ::fnv_00cb10d0::FUN_00cb10d0(text);
    intptr_t suffixLength = ::fnv_00cb10d0::FUN_00cb10d0(suffix);
    if (textLength < suffixLength)
    {
        *result = false;
        return result;
    }
    intptr_t offset = textLength - suffixLength;
    for (int i = 0; i < suffixLength; ++i)
    {
        if (text[offset + i] != suffix[i])
        {
            *result = false;
            return result;
        }
    }
    *result = true;
    return result;
}

class NineIntegerRecord
{
  public:
    NineIntegerRecord();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};

struct BSAudio
{
    void* unk00; void* unk04; void* unk08; void* unk0c;
    void* unk10;
};


// Reads unk10 from the BSAudio returned by FUN_00c85750 and passes it with a and b to FUN_00cb11b0.
// @fnv 0x00cb13e0
void __cdecl FUN_00cb13e0(intptr_t aiArg1, int aiArg2)
{
    NineIntegerRecord router;
    intptr_t c = (intptr_t)static_cast<BSAudio*>(::FUN_00c85750())->unk10;
    ::fnv_00cb11b0::FUN_00cb11b0((void *)(aiArg1), aiArg2, (void *)(c));
}

// @fnv 0x00cb1090
void __cdecl FUN_00cb1090(char* pcDest, const char* pcSrc)
{
    const char* s = pcSrc;
    char c;
    char* d = pcDest;
    int iOffset = d - s;
    do
    {
        c = *s;
        *(char*)(s + iOffset) = c;
        s++;
    } while (c);
}

// Compares two byte buffers over n bytes, four at a time, returning -1, 1 or 0 based on the first differing byte.
// @fnv 0x00cb1290
int __cdecl FUN_00cb1290(const unsigned char* pLeft, const unsigned char* pRight, unsigned int uiLength)
{
    int d = 0;
    while (uiLength >= 4)
    {
        if (*(const unsigned int*)pLeft != *(const unsigned int*)pRight)
        {
            goto bytes;
        }
        uiLength -= 4;
        pRight += 4;
        pLeft += 4;
    }
    if (uiLength != 0)
    {
    bytes:
        d = (int)pLeft[0] - (int)pRight[0];
        if (d == 0 && uiLength > 1)
        {
            d = (int)pLeft[1] - (int)pRight[1];
            if (d == 0 && uiLength > 2)
            {
                d = (int)pLeft[2] - (int)pRight[2];
                if (d == 0 && uiLength > 3)
                {
                    d = (int)pLeft[3] - (int)pRight[3];
                    return (d >> 31) | 1;
                }
            }
        }
        if (d != 0)
        {
            return (d >> 31) | 1;
        }
    }
    return 0;
}


// @fnv 0x00cb1390
int __cdecl FUN_00cb1390(const char* str, char acChar)
{
    const char* p = ::fnv_00cb1150::FUN_00cb1150(str, acChar);
    return p ? (int)(p - str) : -1;
}

struct S_00cb1410_Buf
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    S_00cb1410_Buf();
};

// Constructs a local S_00cb1410_Buf, reads unk10 from FUN_00c85750()'s result, and passes it with a to FUN_00cb1160.
// @fnv 0x00cb1410
void __cdecl FUN_00cb1410(intptr_t aiValue)
{
    S_00cb1410_Buf buf;
    intptr_t r = (intptr_t)static_cast<BSAudio*>(::FUN_00c85750())->unk10;
    ::FUN_00cb1160((const char *)(aiValue), (void *)(r));
}

struct Sink
{
};


static __declspec(noinline) char* skip(char* p)
{
    while (*p == ' ')
        ++p;
    return p;
}

// Finds needle in hay, skips spaces to an '=', then a quoted string, and passes the quoted text to sink; returns 1 on success, 0 otherwise.
// @fnv 0x00d48440
static __declspec(noinline) int ParseQuotedValue(const char* pText, const char* pKey, Sink* sink)
{
    const char* p = ::fnv_00cb1130::FUN_00cb1130(pText, pKey);
    if (!p)
        return 0;
    p += ::fnv_00cb10d0::FUN_00cb10d0(pKey);
    p = skip((char*)p);
    if (*p != '=')
        return 0;
    p = skip((char*)p + 1);
    if (*p != '"')
        return 0;
    ++p;
    char* pQuoteEnd = ::fnv_00cb1140::FUN_00cb1140(p, '"');
    if (!pQuoteEnd)
        return 0;
    reinterpret_cast<::fnv_00cb0c50::SStringPtr *>((sink))->FUN_00cb0c50(p, (int)(pQuoteEnd - p));
    return 1;
}

int __cdecl call_it(const char* a, const char* b, Sink* s)
{
    return ParseQuotedValue(a, b, s);
}

void __cdecl FUN_00ecddf1(intptr_t a, int b, intptr_t c, intptr_t d);

// @fnv 0x00cb0f50
void __cdecl FUN_00cb0f50(intptr_t a, int b, intptr_t c, intptr_t d)
{
    FUN_00ecddf1(a, b, c, d);
}

namespace fnv_00cb1140 {

// @fnv 0x00cb1140
char* __cdecl FUN_00cb1140(const char* s, int c)
{
    return std::strchr((char *)(s), c);
}
}  // namespace fnv_00cb1140

namespace fnv_00cb1150 {

// @fnv 0x00cb1150
const char* __cdecl FUN_00cb1150(const char* str, int c)
{
    return ((const char *)(std::strrchr((char *)(str), c)));
}
}  // namespace fnv_00cb1150


// @fnv 0x00cb1260
void* __cdecl FUN_00cb1260(void* dst, const void* src, uintptr_t count)
{
    return std::memmove(dst, src, count);
}

// @fnv 0x00cb1270
void* __cdecl FUN_00cb1270(char* a, const char* b, int c)
{
    return std::memmove(a, b, c);
}


// @fnv 0x00cb1280
void __cdecl FUN_00cb1280(void* dest, int value, uintptr_t count)
{
    std::memset(dest, value, count);
}

#include <stdarg.h>

// @fnv 0x00cb0f60
int __cdecl Vsnprintf(char* buf, intptr_t n, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int ret = std::vsnprintf(buf, n, fmt, args);
    va_end(args);
    return ret;
}

#include <string.h>
namespace fnv_00cb10d0 {
// @fnv 0x00cb10d0
int __cdecl FUN_00cb10d0(const char* apString)
{
    return (int)strlen(apString);
}
}  // namespace fnv_00cb10d0

namespace fnv_00cb1130 {
// @fnv 0x00cb1130
const char* __cdecl FUN_00cb1130(const char* a, const char* b)
{
    return strstr(a, b);
}
}  // namespace fnv_00cb1130


struct Cls;

struct BoolGuard
{
    bool flag;
    intptr_t Get(Cls* owner, intptr_t value);
};

struct Cls
{
    void FUN_00626420(intptr_t value);
};

// @fnv 0x00626420
void Cls::FUN_00626420(intptr_t value)
{
    BoolGuard g = {};
    reinterpret_cast<::B6266F0Array *>(this)->FUN_006266f0((::B6266F0Allocator *)(g.Get(this, value)), *(const ::B6266F0Entry *)nullptr);
}
