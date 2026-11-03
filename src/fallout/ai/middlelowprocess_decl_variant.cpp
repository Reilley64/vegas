
// src/fallout/ai/middlelowprocess_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0092cab0: the skeleton of src/fallout/ai/middlelowprocess.cpp
// with declarations corrected to what the original code does (LowProcess.h: LowProcess += void FUN_0092cab0(Actor* source);; Actor.h: virtual void Unk_10D(void); -> virtual void Unk_10D(int a);; Actor.h: Actor += void FUN_00881680(bool a);). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_011cd000.h"
#include "../../../include/layout_support.h"
#include "../../../include/Actor_decl_middlelowprocess.h"
#include "MiddleLowProcess_decl_middlelowprocess.h"

template <class Collection> class SettingT
{
  public:
    float* Float();
};
// @fnv 0x0092cab0
void LowProcess::FUN_0092cab0(Actor* source)
{
    int iterations = (int)(*((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting236)))) * 2);
    Actor* actor = 0;
    actor = dynamic_cast<Actor*>(pTarget);
    bool bUpdated = false;
    if (!pTarget || actor->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((void *)(actor))->FUN_00440d80() || actor->Unk_8B(false))
    {
        source->Unk_10D(0);
        reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((source))->FUN_00881680(false);
    }
    else if (actor && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))))->FUN_0045cd60())) == 2)
    {
        while (iterations)
        {
            if (source->Unk_8B(false))
                break;
            source->Unk_10E();
            actor = dynamic_cast<Actor*>(pTarget);
            if (actor && !actor->Unk_8B(false) && (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))))->FUN_0045cd60())) == 2)
            {
                actor->Unk_10E();
                bUpdated = true;
            }
            iterations--;
        }
        if (bUpdated && actor)
        {
            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->ResetPackageState();
            bUpdated = false;
        }
    }
    else
    {
        UpdateActorPackage(source, true, 0x101, false);
    }
}
