
// src/fallout_shared/tesworldspace_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSProjectile.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_00585fe0_shell.h"
#include "fnv/decl/FUN_005860c0_shell.h"
#include "fnv/decl/FUN_00586280_shell.h"
#include "fnv/decl/FUN_00588070_shell.h"
#include "fnv/decl/FUN_0058f5c0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Unk00586340.h"
#include "fnv/decl/fnv_0054db50__FUN_0054db50_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00586000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "tesworldspace_packet_rtti2_tesworldspace.h"

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
struct S00585250_WorldData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Different(S00585250_WorldData*);
    int unk04, unk08;
};
struct S00585250_WorldReference
{
    bool Different(S00585250_WorldReference*);
};
struct WorldCompareView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    S00585250_WorldReference* reference;
    unsigned char flags;
    unsigned char unk4D;
    unsigned short field4E;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    float fC8;
    float fCC;
    unsigned int unkD0;
    S00585250_WorldData dataD4;
    S00585250_WorldData dataE0;
    bool FUN_00585250(TESForm*);
};
// @fnv 0x00585250
bool WorldCompareView::FUN_00585250(TESForm* form)
{
    WorldCompareView* other = (WorldCompareView*)dynamic_cast< ::TESWorldSpace*>(form);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(other)))
        return true;
    if (flags != other->flags)
        return true;
    if (field4E != other->field4E)
        return true;
    if (unk70 != other->unk70)
        return true;
    if (unkD0 != other->unkD0)
        return true;
    if (((void *)(reinterpret_cast<::FUN_00585fe0_shell *>(this)->FUN_00585fe0())) != ((void *)(reinterpret_cast<::FUN_00585fe0_shell *>((other))->FUN_00585fe0())))
        return true;
    if (((void *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())) != ((void *)(reinterpret_cast<::LowProcess *>((other))->GetActiveCombatTarget())))
        return true;
    if (reference && other->reference)
    {
        if (reinterpret_cast<::FUN_0058f5c0_shell *>((reference))->IsImpactSwapDifferent((::ImpactSwap *)(other->reference)))
            return true;
    }
    else if (reference || other->reference)
        return true;
    if (((void *)(::FUN_00586070((::TESWorldSpace *)this))) != ((void *)(::FUN_00586070((::TESWorldSpace *)(other)))))
        return true;
    if (((void *)(reinterpret_cast<::FUN_005860c0_shell *>(this)->FUN_005860c0())) != ((void *)(reinterpret_cast<::FUN_005860c0_shell *>((other))->FUN_005860c0())))
        return true;
    if (reinterpret_cast<::BGSProjectile *>(this)->GetExplosionProximity() != reinterpret_cast<::BGSProjectile *>((other))->GetExplosionProximity())
        return true;
    if (fC8 != other->fC8 || fCC != other->fCC)
        return true;
    if (memcmp(&unk80, &other->unk80, 16))
        return true;
    if (memcmp(&unk90, &other->unk90, 12))
        return true;
    if (((void *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150())) != ((void *)(reinterpret_cast<::InterfaceManager *>((other))->FUN_00586150())))
        return true;
    if (dataD4.Different(&other->dataD4))
        return true;
    if (dataE0.Different(&other->dataE0))
        return true;
    return false;
}
