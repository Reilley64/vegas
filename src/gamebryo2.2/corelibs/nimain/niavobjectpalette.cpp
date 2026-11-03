
// src/gamebryo2.2/corelibs/nimain/niavobjectpalette.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niavobjectpalette.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_011f5000.h"
struct StrArr
{
};
struct NiAVObjectPalette
{
    void AppendString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f4a04_arg1) to pkStrings, growing it if the current index reaches its size.
// @fnv 0x00a88a70
void NiAVObjectPalette::AppendString(StrArr* pkStrings)
{
    reinterpret_cast<::A5D6E0This *>((pkStrings))->AppendCameraPathEntries({});
    char* pString = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f5b58)));
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)pkStrings + 8))
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(*(unsigned short*)((char*)pkStrings + 0xe) + uiIndex);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, pString);
}
