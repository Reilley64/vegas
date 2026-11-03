
// src/fallout/ai/middlehighprocess_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0091db40: the skeleton of src/fallout/ai/middlehighprocess.cpp
// with declarations corrected to what the original code does (middlehighprocess_decls.h: MiddleHighProcess += void FUN_0091db40(Actor* actor);; Actor.h: virtual void Unk_10D(void); -> virtual void Unk_10D(Actor* target);; TESObjectREFR.h: TESObjectREFR += float FUN_005723b0(TESObjectREFR* ref, int a, int b);). Move the function to its real unit once
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
#include "fnv/decl/FUN_0049bb50_shell.h"
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
#include "fnv/decl/RefS.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0092a000.h"
#include "fnv/symbols_011cd000.h"
#include "middlehighprocess_decls_decl_middlehighprocess.h"

struct SettingFloat
{
};
// @fnv 0x0091db40
void MiddleHighProcess::FUN_0091db40(Actor* actor)
{
    int remaining = (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting236))))));
    Actor* found = 0;
    found = dynamic_cast<Actor*>(pTarget);
    bool worked = false;
    if (!found || found->GetDisabled())
    {
        actor->Unk_10D(found);
        return;
    }
    if (found &&
        ((actor->GetParentCell() && actor->GetParentCell() == found->GetParentCell()) ||
         reinterpret_cast<::RefS *>((actor))->FUN_005723b0((::RefS *)(found), 0, 0) < 300.0) &&
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((found))->GetBaseTexture())) && (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((found))->GetBaseTexture()))))->FUN_0045cd60())) == 1)
    {
        while (remaining)
        {
            if (actor->Unk_8B(false))
                break;
            actor->Unk_10E();
            found = dynamic_cast<Actor*>(pTarget);
            if (found && !found->Unk_8B(false) && (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((found))->GetBaseTexture()))))->FUN_0045cd60())) == 1)
            {
                found->Unk_10E();
                worked = true;
            }
            remaining--;
        }
        if (worked)
        {
            if (found)
            {
                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((found))->GetBaseTexture()))->ResetPackageState();
            }
            worked = false;
        }
    }
    else
    {
        UpdateActorPackage(actor, true, 0x101, false);
    }
}
