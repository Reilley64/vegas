// FUN_00406d00, in a unit of its own so that a link that reaches it loads
// no other code (VEGAS-128). It was defined in
// src/fallout_shared/magic/effectitemlist.cpp.
#include <cstdarg>
#include <cstdio>
#include "fnv/symbols_00406000.h"

// Calls _vsprintf_s to format the variadic arguments following apFormat into apString1 using aiSize as the buffer size.
// @fnv 0x00406d00
int __cdecl FUN_00406d00(char* apString1, int aiSize, const char* apFormat, ...)
{
    va_list vList;
    va_start(vList, apFormat);
    int iResult = std::vsnprintf(apString1, aiSize, apFormat, vList);
    va_end(vList);
    return iResult;
}
