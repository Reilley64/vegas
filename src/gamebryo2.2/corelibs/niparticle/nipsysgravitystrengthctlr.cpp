
// src/gamebryo2.2/corelibs/niparticle/nipsysgravitystrengthctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravitystrengthctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c2a8a0
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c1b0f0__FUN_00c1b0f0_cls.h"
#include "fnv/decl/fnv_00c31530__NiPSysModifierCtlrRuntime.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_01202000.h"
void* __cdecl FUN_00c2a8a0()
{
    return &(*reinterpret_cast<void * *>(&::g_01202700));
}

struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pkBase;
};
struct NiObject
{
    virtual ~NiObject();
    virtual void _a();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOfType(const NiRTTI* pkRTTI) const;
};
inline bool NiObject::IsKindOfType(const NiRTTI* pkRTTI) const
{
    const NiRTTI* pkMy = GetRTTI();
    if (!pkMy)
        return false;
    do
    {
        if (pkMy == pkRTTI)
            return true;
        pkMy = pkMy->m_pkBase;
    } while (pkMy);
    return false;
}
struct NiPSysModifier : NiObject
{
};
struct NiObjectNET
{
};
struct B00c1bff0
{
};
struct BaseStandIn
{
    char _pad[0x38];
};
struct NiPSysGravityStrengthCtlr : BaseStandIn
{
    void* m_p38;
    bool FUN_00c2a910(NiObjectNET*);
};
// @fnv 0x00c2a910
bool NiPSysGravityStrengthCtlr::FUN_00c2a910(NiObjectNET* pkTarget)
{
    if (!reinterpret_cast<::fnv_00c31530::NiPSysModifierCtlrRuntime *>(this)->IsTargetParticleSystem((::fnv_00c31530::NiParticleSystemRuntime *)(pkTarget)))
        return false;
    NiPSysModifier* pkModifier = (NiPSysModifier*)reinterpret_cast<::fnv_00c1b0f0::FUN_00c1b0f0_cls *>((((B00c1bff0*)pkTarget)))->FUN_00c1b0f0((unsigned int *)(void *)((void*)&m_p38));
    if (!pkModifier)
        return false;
    return pkModifier->IsKindOfType(&(*reinterpret_cast<::NiRTTI *>(&::g_01202548)));
}

namespace fnv_00c2a960 {
struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrowSize;
};
struct NiPSysGravityStrengthCtlr
{
    void FUN_00c2a960(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_01202700) to pkStrings, growing the array if it is full.
// @fnv 0x00c2a960
void NiPSysGravityStrengthCtlr::FUN_00c2a960(StrArr* pkStrings)
{
    ::FUN_00c32f60((::StrArr *)(pkStrings));
    char* pStr = ::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_01202700))));
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + pkStrings->m_usGrowSize);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, pStr);
}
}  // namespace fnv_00c2a960

class C2A8C0CloningProcess;

class C2A8C0Base
{
  public:
    C2A8C0Base() throw();
    virtual ~C2A8C0Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

class C2A8C0Object : public C2A8C0Base
{
  public:
    __forceinline C2A8C0Object() throw()
    {}
    virtual ~C2A8C0Object();

    C2A8C0Object* FUN_00c2a8c0(C2A8C0CloningProcess& kCloning);
};

// @fnv 0x00c2a8c0
C2A8C0Object* C2A8C0Object::FUN_00c2a8c0(C2A8C0CloningProcess& kCloning)
{
    C2A8C0Object* pkDest = new C2A8C0Object;
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>(this)->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(pkDest), (::CloningProcess &)(kCloning));
    return pkDest;
}
