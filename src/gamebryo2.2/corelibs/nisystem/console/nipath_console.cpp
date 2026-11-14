
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cctype>
#include <cstdint>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/symbols_01013000.h"

// @fnv 0x00aa2d10
int FUN_00aa2d10(intptr_t aiValue1, int aiValue2)
{
    int r = ((int)(std::uintptr_t)(fnv::crt::getcwd((char *)(aiValue1), aiValue2)));
    r = !r;
    r = !r;
    return r;
}

extern "C" int __cdecl FUN_00aa1370(const char* a, const char* b, unsigned int n);

extern char str_010a2564[];

// Skips a leading drive letter or path prefix in s and returns the pointer past it.
// @fnv 0x00aa2c50
char* __cdecl SkipPathPrefix(char* szPath)
{
    if (FUN_00aa1370(szPath, str_010a2564, 2) == 0)
    {
        return std::strchr((char *)(szPath + 2), 0x5c) + 1;
    }
    if (FUN_00aa1370(szPath, DAT_01013444, 1) == 0)
    {
        goto skip;
    }
    {
        char c = (char)std::toupper(szPath[0]);
        if (szPath[1] != ':' || (unsigned char)(c - 0x41) > 0x19)
        {
            goto done;
        }
    }
    szPath += 2;
    if (*szPath != 0x5c)
    {
        goto done;
    }
skip:
    szPath++;
done:
    return szPath;
}

#include <string.h>
// Returns false for slash-prefixed paths or a drive letter followed by a colon in the first two characters; otherwise true.
// @fnv 0x00aa2cc0
bool __cdecl FUN_00aa2cc0(const char* pcPath)
{
    char c1stChar;
    char c2ndChar;
    unsigned int uiLen;
    uiLen = strlen(pcPath);
    if (uiLen < 2)
        return true;
    c1stChar = pcPath[0];
    if (c1stChar == '\\' || c1stChar == '/')
        return false;
    c1stChar = (char)std::toupper(c1stChar);
    c2ndChar = pcPath[1];
    if (c2ndChar != ':' || (unsigned char)(c1stChar - 'A') > 25)
        return true;
    return false;
}

#include "generated/data/gamebryo2.2/corelibs/nisystem/console/nipath_console.inc"
