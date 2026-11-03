// src/bsshader/geometrydecalshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/geometrydecalshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01200000.h"
struct StrArr
{
    char _pad[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    char _pad2[2];
    unsigned short m_usGrow;
};
void __stdcall FUN_00b71450(StrArr*);
// Grows the string array if it is full, then appends the string returned by _FUN_00a7d330(DAT_012005b8) at the end.
// @fnv 0x00bb44a0
void __stdcall FUN_00bb44a0(StrArr* apStrings)
{
    FUN_00b71450(apStrings);
    char* pString = ::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_012005b8)));
    unsigned int uiIndex = apStrings->m_usSize;
    if (uiIndex >= apStrings->m_usMax)
        reinterpret_cast<::ViewerStrings *>((apStrings))->SetSize(uiIndex + apStrings->m_usGrow);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apStrings))->SetAt(uiIndex, pString);
}
