
// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00c32d80.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c1b0f0__FUN_00c1b0f0_cls.h"
#include "fnv/decl/fnv_00c31530__NiPSysModifierCtlrRuntime.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_010be000.h"
#include "fnv/symbols_01202000.h"
struct NiRTTI;

// @fnv 0x00c2a1a0
const NiRTTI* __cdecl FUN_00c2a1a0()
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_012026f0));
}

struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pBaseRTTI;
};
struct NiObject
{
    virtual ~NiObject();
    virtual void _U4();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOfType(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* pkMy = GetRTTI();
        while (pkMy)
        {
            if (pkMy == pkRTTI)
                return true;
            pkMy = pkMy->m_pBaseRTTI;
        }
        return false;
    }
};
struct NiPSysModifier : NiObject
{
};
struct B00c1bff0
{
};
struct NiObjectNET : B00c1bff0
{
};
struct BaseStandIn
{
};
struct NiPSysInitialRotAngleCtlr : BaseStandIn
{
    bool IsModifierOfType(NiObjectNET*);
};
// @fnv 0x00c2a210
bool NiPSysInitialRotAngleCtlr::IsModifierOfType(NiObjectNET* pkTarget)
{
    if (!reinterpret_cast<::fnv_00c31530::NiPSysModifierCtlrRuntime *>(this)->IsTargetParticleSystem((::fnv_00c31530::NiParticleSystemRuntime *)(pkTarget)))
        return false;
    NiPSysModifier* pkModifier = (NiPSysModifier*)reinterpret_cast<::fnv_00c1b0f0::FUN_00c1b0f0_cls *>((pkTarget))->FUN_00c1b0f0((unsigned int *)(void *)((void*)((char*)this + 0x38)));
    if (!pkModifier)
        return false;
    return pkModifier->IsKindOfType(&(*reinterpret_cast<::NiRTTI *>(&::g_01202528)));
}

struct StrArr
{
};
// @fnv 0x00c2a260
void __stdcall FUN_00c2a260(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pStr = FUN_00a7d330((*reinterpret_cast<::NiRTTI *>(&::g_012026f0)).m_pcName);
    unsigned int iCount = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int iSize = *(unsigned short*)((char*)pkStrings + 8);
    if (iCount >= iSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(iCount + *(unsigned short*)((char*)pkStrings + 14));
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(iCount, pStr);
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct SpawnedObject
{
};

struct SpawnedCtlr
{
    SpawnedObject* CreateSpawnedObject(void* pArg);
};

// Allocates a 0x40-byte SpawnedObject, initialises it, passes it to FUN_00c32de0 with pArg, and returns it (or null on allocation failure).
// @fnv 0x00c2a1c0
SpawnedObject* SpawnedCtlr::CreateSpawnedObject(void* pArg)
{
    SpawnedObject* pkObj = (SpawnedObject*)FUN_00aa13e0(0x40);
    if (pkObj != 0)
    {
        new ((void *)(pkObj)) ::FUN_00c32d80();
        *(char**)pkObj = &DAT_010befbc;
    }
    else
    {
        pkObj = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>(this)->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(pkObj), (*(::CloningProcess *)(pArg)));
    return pkObj;
}
