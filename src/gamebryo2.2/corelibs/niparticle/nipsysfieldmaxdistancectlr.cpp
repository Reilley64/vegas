// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmaxdistancectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmaxdistancectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c2b040
#include <cstdint>
#include "fnv/symbols_00aa1000.h"
#include <new>
#include "fnv/decl/FUN_00c32d80.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_010bf000.h"
#include "fnv/symbols_01202000.h"
const void* __cdecl FUN_00c2b040()
{
    return &(*reinterpret_cast<const void * *>(&::g_01202710));
}

struct NiPSysModifierFloatCtlr
{
};

struct NiPSysFieldMaxDistanceCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2b050(float fValue);
};

// @fnv 0x00c2b050
void NiPSysFieldMaxDistanceCtlr::FUN_00c2b050(float fValue)
{
    float* p = (float*)(*((float**)(this + 0x3c)));
    p[0xA] = fValue;
    p[0xB] = fValue * fValue;
}

struct StrArr
{
    unsigned char _0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned char _c[2];
    unsigned short m_usGrowBy;
};
// @fnv 0x00c2b0c0
void FUN_00c2b0c0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* psz = ::FUN_00a7d330((const char*)(*reinterpret_cast<const void * *>(&::g_01202710)));
    unsigned int uSize = pkStrings->m_usSize;
    if (uSize >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uSize + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uSize, psz);
}



struct CtorBase_cls
{
};

struct FUN_00c2b070_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void* FUN_00c2b070(uintptr_t a1);
};

// Allocates a 0x40-byte object, runs its base constructor and sets its vtable, then passes it with a1 to FUN_00c32de0 and returns it.
// @fnv 0x00c2b070
void* FUN_00c2b070_cls::FUN_00c2b070(uintptr_t a1)
{
    FUN_00c2b070_cls* p = (FUN_00c2b070_cls*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        new ((void *)(((CtorBase_cls*)p))) ::FUN_00c32d80();
        p->m_vtbl = (void*)&DAT_010bf354;
    }
    else
    {
        p = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>((this))->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(p), (*(::CloningProcess *)(a1)));
    return p;
}
