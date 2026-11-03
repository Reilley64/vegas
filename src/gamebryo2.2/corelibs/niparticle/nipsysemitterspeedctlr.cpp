// src/gamebryo2.2/corelibs/niparticle/nipsysemitterspeedctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterspeedctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c2b360
#include <new>
#include "fnv/decl/FUN_00c32d80.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_010bf000.h"
#include "fnv/symbols_01202000.h"
const void* __cdecl FUN_00c2b360()
{
    return &(*reinterpret_cast<const void * *>(&::g_01202728));
}

struct NiPSysModifierFloatCtlr
{
    float m_fValue;
};

struct NiPSysEmitterSpeedCtlr
{
    void FUN_00c2b370(float& rfValue);
};

// @fnv 0x00c2b370
void NiPSysEmitterSpeedCtlr::FUN_00c2b370(float& rfValue)
{
    NiPSysModifierFloatCtlr* pkTarget = *(NiPSysModifierFloatCtlr**)(this + 0x3c);
    rfValue = *(float*)((char*)pkTarget + 0x18);
}

namespace fnv_00c29fa0 {
struct NiPSysModifierFloatCtlr
{
    char pad[0x18];
    float m_fTarget;
};

struct NiPSysEmitterSpeedCtlr
{
    char pad[0x3c];
    NiPSysModifierFloatCtlr* m_pFloatCtlr;
    void FUN_00c29fa0(float fValue);
};

// @fnv 0x00c29fa0
void NiPSysEmitterSpeedCtlr::FUN_00c29fa0(float fValue)
{
    m_pFloatCtlr->m_fTarget = fValue;
}
}  // namespace fnv_00c29fa0

struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrowBy;
};
// @fnv 0x00c2b3d0
void __stdcall FUN_00c2b3d0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* psz = ::FUN_00a7d330((const char *)((*reinterpret_cast<const void * *>(&::g_01202728))));
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, psz);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

struct CtorBase_cls
{
};

struct FUN_00c2b380_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void* FUN_00c2b380(unsigned int a1);
};

// Allocates a 0x40-byte object, runs its base constructor and sets its vtable, then passes it to FUN_00c32de0 with a1 and returns it.
// @fnv 0x00c2b380
void* FUN_00c2b380_cls::FUN_00c2b380(unsigned int a1)
{
    FUN_00c2b380_cls* p = (FUN_00c2b380_cls*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        new ((void *)(((CtorBase_cls*)p))) ::FUN_00c32d80();
        p->m_vtbl = (void*)&DAT_010bf654;
    }
    else
    {
        p = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>((this))->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(p), (*(::CloningProcess *)(a1)));
    return p;
}
