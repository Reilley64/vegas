
// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c29f90
#include <cstdint>
#include <new>
#include "fnv/decl/FUN_00c32d80.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_010be000.h"
#include "fnv/symbols_01202000.h"
void* __cdecl FUN_00c29f90()
{
    return &(*reinterpret_cast<void * *>(&::g_012026e0));
}

struct StrArr
{
};
struct NiPSysInitialRotSpeedCtlr
{
    void AppendString(StrArr* pkStrings);
};
// Appends a string obtained from FUN_00a7d330(g_012026e0) to pkStrings, growing the array by its growth step when full.
// @fnv 0x00c2a000
void NiPSysInitialRotSpeedCtlr::AppendString(StrArr* pkStrings)
{
    ::FUN_00c32f60((::StrArr *)this);
    char* p = (char*)((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_012026e0))))));
    unsigned int nCount = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int nMax = *(unsigned short*)((char*)pkStrings + 8);
    if (nCount >= nMax)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(nCount + *(unsigned short*)((char*)pkStrings + 14));
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(nCount, p);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

struct CtorBase_cls
{
};

struct FUN_00c29fb0_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void* FUN_00c29fb0(uintptr_t a1);
};

// Allocates a 0x40-byte object, runs its base constructor, sets its vtable, passes it to FUN_00c32de0 with a1, and returns it.
// @fnv 0x00c29fb0
void* FUN_00c29fb0_cls::FUN_00c29fb0(uintptr_t a1)
{
    FUN_00c29fb0_cls* p = (FUN_00c29fb0_cls*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        new ((void *)(((CtorBase_cls*)p))) ::FUN_00c32d80();
        p->m_vtbl = (void*)&DAT_010bedbc;
    }
    else
    {
        p = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>((this))->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(p), (*(::CloningProcess *)(a1)));
    return p;
}
