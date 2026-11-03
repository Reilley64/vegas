
// src/gamebryo2.2/corelibs/niparticle/nipsysmodifierboolctlr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysmodifierboolctlr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <new>
#include "fnv/decl/FUN_00a38e00.h"
#include "fnv/decl/FUN_00c315b0_cls.h"
#include "fnv/decl/NiTimeControllerA362.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a531a0__FUN_00a531a0_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c0000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysmodifierboolctlr_packet.h"
// 54-byte covered span: constructor (33 B) + 15 B int3 padding +
// 6 B static-address accessor at 0x00c31290 (nirotkey.cpp pattern).

struct NiTimeController_Call
{
    void SetControllerActive();
};
struct CtlrStandin
{
    char _pad[0x38];
    NiFixedString m_s;
    void* m_p;
    CtlrStandin* FUN_00c31260();
};
// @fnv 0x00c31260
CtlrStandin* CtlrStandin::FUN_00c31260()
{
    new ((void *)(((NiTimeController_Call*)this))) ::FUN_00a38e00();
    *(void**)this = (void*)NiPSysModifierCtlr_vtable;
    m_s = (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220));
    m_p = 0;
    return this;
}

class NiRTTI;
struct NiObject
{
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
struct NiInterpolator : NiObject
{
};
struct NiBoolInterpolator : NiInterpolator
{
};
struct NiPSysModifierBoolCtlr
{
    void FUN_00c32c70(NiInterpolator*, unsigned short);
};
// @fnv 0x00c32c70
void NiPSysModifierBoolCtlr::FUN_00c32c70(NiInterpolator* pkInterp, unsigned short usIndex)
{
    bool bValue;
    NiBoolInterpolator* pkBoolInterp;
    if (pkInterp == 0)
        pkBoolInterp = 0;
    else
        pkBoolInterp = (NiBoolInterpolator*)pkInterp->DynamicCast((const ::NiRTTI *)(const unsigned int *)(&(*reinterpret_cast<unsigned int *>(&::g_011f404c))));
    ((void(*)(NiPSysModifierBoolCtlr*, bool*))(*(void***)this)[60])(this, &bValue);
    reinterpret_cast<::fnv_00a531a0::FUN_00a531a0_shell *>((pkBoolInterp))->SetBoolValue(bValue);
}

namespace fnv_00c32d30 {
struct StrArr
{
    char _pad0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    char _pad1[2];
    unsigned short m_usGrowBy;
};
struct NiPSysModifierBoolCtlr
{
    void FUN_00c32d30(StrArr*);
};
// @fnv 0x00c32d30
void NiPSysModifierBoolCtlr::FUN_00c32d30(StrArr* pkStrings)
{
    reinterpret_cast<::FUN_00c315b0_cls *>(this)->AppendModifierInfo(pkStrings);
    char* tmp = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_012027f0)));
    unsigned int size = pkStrings->m_usSize;
    unsigned int maxs = pkStrings->m_usMaxSize;
    if (size >= maxs)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(pkStrings->m_usGrowBy + size);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(size, tmp);
}
}  // namespace fnv_00c32d30


class C32CB0Interpolator
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual bool Update(float fTime, void* pkTarget, int& fValue);
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual bool IsChannelPosed();
};

class C32CB0Controller
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void SetManagerControlled(int fValue);

    bool GetManagerControlled() const
    {
        return ((unsigned char)(m_usFlags >> 5) & 1) != 0;
    }
    void FUN_00c32cb0(const float& fTime);

    int unk04;
    unsigned short m_usFlags;
    short unk0A;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    float m_fControllerTime;
    void* m_pkTarget;
    int unk30;
    C32CB0Interpolator* m_pkInterpolator;
};

// @fnv 0x00c32cb0
void C32CB0Controller::FUN_00c32cb0(const float& fTime)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (reinterpret_cast<::NiTimeControllerA362 *>(this)->FUN_00a36250(fTime) && (!m_pkInterpolator || !m_pkInterpolator->IsChannelPosed()))
    {
        return;
    }

    if (m_pkInterpolator)
    {
        int fValue;
        if (m_pkInterpolator->Update(m_fControllerTime, m_pkTarget, fValue))
            SetManagerControlled(fValue);
    }
}
