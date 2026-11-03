
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// ResolveRelativePath: resolve a path, strip leading "..\\" components from rel,
// and copy the result into out (cdecl, /MT /Od /GS /EHsc).

#include <cstring>
#include "runtime/crt.h"
extern "C" char DAT_010a46be[];
extern "C" char DAT_010a46c8[];

void __cdecl FUN_00ec408c();

// @fnv 0x00afe830
void __cdecl ResolveRelativePath(const char* aBasePath, const char* aRelPath, char* aOutPath)
{
    char buf2[0x104];
    aOutPath[0] = 0;
    fnv::crt::splitpath_s(aBasePath, 0, 0, buf2, 0x104, 0, 0, 0, 0);

    char* pX = buf2;
    int len5 = std::strlen(pX);
    if (pX[len5 - 1] == '\\')
    {
        pX[len5 - 1] = 0;
    }

    bool stripped3 = false;
    char* lastSep;
    while (std::strncmp(aRelPath, "..\\", 3) == 0)
    {
        stripped3 = true;
        lastSep = pX;
        len5 = std::strlen(pX);
        for (int i2 = len5 - 1; i2 > 0; i2--)
        {
            if (pX[i2] == '\\')
            {
                lastSep = pX + i2;
                break;
            }
        }
        if (lastSep != 0)
        {
            *lastSep = 0;
            aRelPath += 3;
        }
        else
        {
            pX = DAT_010a46be;
        }
    }

    if (stripped3)
    {
        fnv::crt::strcat_s(aOutPath, 0x104, pX);
        fnv::crt::strcat_s(aOutPath, 0x104, DAT_010a46c8);
        fnv::crt::strcat_s(aOutPath, 0x104, aRelPath);
    }
    else
    {
        fnv::crt::strcpy_s(aOutPath, 0x104, aRelPath);
    }
}

#include "generated/data/bssystem/console/archive_console.inc"
