
// src/fallout_shared/tescreature_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005f9b90: the skeleton of src/fallout_shared/tescreature_rtti_variant.cpp
// with declarations corrected to what the original code does (tescreature_decls_rtti_variant.h: BGSBodyPartData* GetBodyPartData(); -> ; tescreature_decls_rtti_variant.h: TESCreature += virtual void C01(); virtual void C02(); virtual void C03(); virtual void C04(); virtual void C05(); virtual void C06(); virtual void C07(); virtual void C08(); virtual void C09). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tescreature_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm). The skeleton of src/fallout_shared/tescreature.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_00489a60.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005f06f0_shell.h"
#include "fnv/decl/FUN_005f75e0.h"
#include "fnv/decl/FUN_005f77b0.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_005f9100_shell.h"
#include "fnv/decl/FUN_005f91d0_shell.h"
#include "fnv/decl/FUN_005f9ad0_shell.h"
#include "fnv/decl/FUN_005f9b30_shell.h"
#include "fnv/decl/FUN_005f9b70_shell.h"
#include "fnv/decl/FUN_00821640_shell.h"
#include "fnv/decl/FUN_00821660_shell.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/Twin_009c0070.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_005f9000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011c3000.h"
#include "tescreature_decls_rtti_variant_decl_tescreature_rtti_variant.h"

#include <string.h>
// @fnv 0x005f9b90
bool TESCreature::FUN_005f9b90(TESForm* otherForm)
{
    TESCreature* other = dynamic_cast<TESCreature*>(otherForm);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(other)))
        return true;
    if (memcmp(&dataPadding, reinterpret_cast<::FUN_005f9b70_shell *>((other))->GetOffset12C(), 4))
        return true;
    if (((bool)(reinterpret_cast<::FUN_005f9ad0_shell *>(this)->FUN_005f9ad0())) != ((bool)(reinterpret_cast<::FUN_005f9ad0_shell *>((other))->FUN_005f9ad0())))
        return true;
    if (reinterpret_cast<::FUN_00821640_shell *>(this)->FUN_00821640() != reinterpret_cast<::FUN_00821640_shell *>((other))->FUN_00821640())
        return true;
    if (::FUN_00567470((char *)this) != ::FUN_00567470((char *)(other)))
        return true;
    if (reinterpret_cast<::FUN_00821660_shell *>(this)->FUN_00821660() != reinterpret_cast<::FUN_00821660_shell *>((other))->FUN_00821660())
        return true;
    if (GetBloodImpactMaterial() != other->GetBloodImpactMaterial())
        return true;
    if (GetCombatStyle() != other->GetCombatStyle())
        return true;
    if (GetBodyPartData() != other->GetBodyPartData())
        return true;
    if (((int)(reinterpret_cast<::Twin_009c0070 *>(this)->GetFilePosition())) != ((int)(reinterpret_cast<::Twin_009c0070 *>((other))->GetFilePosition())))
        return true;
    if (reinterpret_cast<::TESActorBaseData *>(this)->GetFlag(0x100))
    {
        CreatureSoundCollection* sounds = reinterpret_cast<::FUN_005f91d0_shell *>(this)->FUN_005f91d0();
        CreatureSoundCollection* otherSounds5 = reinterpret_cast<::FUN_005f91d0_shell *>((other))->FUN_005f91d0();
        if (sounds)
        {
            if (!otherSounds5)
                return true;
            if (reinterpret_cast<::FUN_005f06f0_shell *>((sounds))->IsDifferentFrom(otherSounds5))
                return true;
        }
        else if (otherSounds5)
            return true;
    }
    else
    {
        if (reinterpret_cast<::FUN_005f9100_shell *>(this)->FUN_005f9100() != reinterpret_cast<::FUN_005f9100_shell *>((other))->FUN_005f9100())
            return true;
    }
    if (((int)(reinterpret_cast<::FUN_005f9b30_shell *>(this)->GetImpactDataSet())) != ((int)(reinterpret_cast<::FUN_005f9b30_shell *>((other))->GetImpactDataSet())))
        return true;
    if (::GetField158((int)this) != ::GetField158((int)(other)))
        return true;
    return false;
}
