
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <cstdint>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CClsA.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a57630.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00a6cd30_cls.h"
#include "fnv/decl/S_00a53280_Foo.h"
#include "fnv/decl/fnv_00495d50__Holder_00495d50.h"
#include "fnv/decl/nsa__FUN_00a368f0_cls.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysemitterctlr_types_NiPSysEmitterCtlr.h"
#include "nipsysemitterctlr_types_NiStream.h"
#include "nipsysemitterctlr_external.h"
#include <new>
struct NiSingleInterpControllerBase
{
    char pad[0x30];
    NiSingleInterpControllerBase() throw();
    virtual void f();
};
struct FUN_00a38e00 : NiSingleInterpControllerBase
{
    int m34;
    FUN_00a38e00();
};
struct GlobalObjectO2_00a7b610;
void* __cdecl FUN_00a537e0();
struct NiTimeControllerStop
{
};
struct FUN_00c1ba30 : NiTimeControllerStop
{
    char pad[0x48 - 1];
    float m48;
};
void FUN_00c1ba30(FUN_00c1ba30* self, int unused);
const char* const* __cdecl FUN_00c1c2f0();
extern intptr_t DAT_011ae754;
extern intptr_t DAT_011ae758;
const char* const* FUN_00c1ba50(unsigned short usIndex);
struct NiPSysEmitterCtlr_shell : NiPSysEmitterCtlr
{
    void FUN_00c1bcc0(NiInterpolator* pkInterpolator, unsigned short usIndex);
};

struct GO
{
    operator unsigned int() const;
};

struct NiBlendBoolInterpolator : NiBoolInterpolator
{
};

struct NiPSysEmitterCtlr_StandIn
{
    char pad[0x34];
    GO m34;
    NiBoolInterpolator* FUN_00639b60();
};

extern unsigned char DAT_01096968;

// @fnv 0x00639b60
NiBoolInterpolator* NiPSysEmitterCtlr_StandIn::FUN_00639b60()
{
    NiBoolInterpolator* pkBoolInterp;
    NiBlendBoolInterpolator* pkBlendInterp;

    pkBoolInterp = reinterpret_cast<NiBoolInterpolator*>(((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f3738))), (::NiObject *)(m34.operator unsigned int())))));

    if (pkBoolInterp)
        return pkBoolInterp;

    pkBlendInterp =
        reinterpret_cast<NiBlendBoolInterpolator*>(((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&::g_011f3e58), (::NiObject *)(m34.operator unsigned int())))));

    if (pkBlendInterp)
    {
        unsigned char m_ucClipIdentifier = reinterpret_cast<::nsa::FUN_00a368f0_cls *>((pkBlendInterp))->FindHighestWeightIndex();
        if (m_ucClipIdentifier != DAT_01096968)
            return ((::NiBoolInterpolator *)(reinterpret_cast<::fnv_00495d50::Holder_00495d50 *>((pkBlendInterp))->GetValueForIndex(m_ucClipIdentifier)));
    }

    return 0;
}
