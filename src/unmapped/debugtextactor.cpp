
// src/unmapped/debugtextactor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextactor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/fnv_005bd5c0__FUN_005bd5c0_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_009aa000.h"
#include "fnv/symbols_011a5000.h"
struct S_009aae70_Entry
{
    unsigned char flag;
    int unk04;
};

int __cdecl FUN_00406d50(char* dst, unsigned int size, const char* src);

struct S_009aae70
{
    void FormatFlagsString(char* buf, unsigned int size, int type);
};

// @fnv 0x009aae70
void S_009aae70::FormatFlagsString(char* pBuffer, unsigned int size, int type)
{
    unsigned int mask = ((unsigned int)(reinterpret_cast<::fnv_005bd5c0::FUN_005bd5c0_shell *>(this)->FUN_005bd5c0(type)));
    if (DAT_011a55b4[type].flag)
    {
        bool any = false;
        for (unsigned int uiBit = 0; uiBit < 32; uiBit++)
        {
            if (mask & (1 << uiBit))
            {
                if (!any)
                {
                    FUN_00406d00(pBuffer, size, "%s: %s", ((const char *)(::FUN_009aa140(type))), ((const char *)(::FUN_009aa1b0(type, uiBit))));
                }
                else
                {
                    char acTemp[260];
                    FUN_00406d00(acTemp, 0x104, ", %s", ((const char *)(::FUN_009aa1b0(type, uiBit))));
                    FUN_00406d50(pBuffer, size - FUN_0044a670(pBuffer), acTemp);
                }
                any = true;
            }
        }
        if (!any)
            FUN_00406d00(pBuffer, size, "%s: None", ((const char *)(::FUN_009aa140(type))));
    }
    else
    {
        FUN_00406d00(pBuffer, size, "%s: %s", ((const char *)(::FUN_009aa140(type))), ((const char *)(::FUN_009aa1b0(type, mask))));
    }
}
