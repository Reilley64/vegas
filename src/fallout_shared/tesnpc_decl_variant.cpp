
// src/fallout_shared/tesnpc_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006047c0: the skeleton of src/fallout_shared/tesnpc.cpp
// with declarations corrected to what the original code does (tesnpc_pc_decls.h: TESNPC += void FUN_006047c0(TESObjectREFR* pRef, bool b1, bool b2, bool b3, bool b4);). Move the function to its real unit once
// that unit declares it this way.

#include <new>
#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnimWeap.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/Dummy_00607810.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cb70_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_0047ded0_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004bfe50_t.h"
#include "fnv/decl/FUN_004c8220_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_00601800_shell.h"
#include "fnv/decl/FUN_00601c10_shell.h"
#include "fnv/decl/FUN_00602130_shell.h"
#include "fnv/decl/FUN_00602170_shell.h"
#include "fnv/decl/FUN_006031e0_shell.h"
#include "fnv/decl/FUN_00603200_shell.h"
#include "fnv/decl/FUN_00604210_shell.h"
#include "fnv/decl/FUN_00606050_shell.h"
#include "fnv/decl/FUN_00606800_shell.h"
#include "fnv/decl/FUN_00607350_shell.h"
#include "fnv/decl/FUN_00607830_helper.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0060b370_shell.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00634890_shell.h"
#include "fnv/decl/FUN_006727b0_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00c748d0_C.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HeadNPC.h"
#include "fnv/decl/Header47cb90.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk_0097fa10.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047d220__ABD_47d220.h"
#include "fnv/decl/fnv_0047f500__FUN_0047f500_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0057b7c0__Actor57.h"
#include "fnv/decl/fnv_00613c50__FUN_00613c50_C.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008a7a90__ActorAnimView.h"
#include "fnv/decl/fnv_008a8e50__ActorP_S.h"
#include "fnv/decl/fnv_008b3c30__FUN_008b3c30_shell.h"
#include "fnv/decl/fnv_008bb520__TES.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_008f2000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "tesnpc_pc_decls_decl_tesnpc.h"

// @fnv 0x006047c0
void TESNPC::FUN_006047c0(TESObjectREFR* a2, bool a3, bool a4, bool a5, bool a6)
{
    InventoryChanges* j;
    InventoryStackRecord* item;
    bool bAllowed;
    bAllowed = true;
    if (a6 == 0)
    {
        bAllowed = reinterpret_cast<::FUN_004623f0_shell *>((::g_BGSSaveLoadGame))->FUN_004623f0(false);
    }
    if (a2->IsActor())
    {
        reinterpret_cast<::BipedAnim *>((a2))->AttachFaceGenNode();
    }
    j = ::InventoryChanges::CreateForReference(a2);
    reinterpret_cast<::FUN_004bfe50_t *>((j))->RemoveWornItems(true, a2);
    Actor* pBiped;
    pBiped = (Actor*)a2;
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture())))
    {
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentAmmunition(NULL);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentShield(NULL);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentTorch(NULL);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentArmor(NULL, NULL, false);
    }
    TESBipedModelForm* res = NULL;
    ExtraDataList* pExtra = NULL;
    for (int i = 0; i < 20; i++)
    {
        item = reinterpret_cast<::FUN_004c8220_shell *>((j))->FUN_004c8220(this, i, true);
        if (item)
        {
            bool val = true;
            TESBoundObject* p;
            p = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()));
            if ((!res || !res->HasBipedModel(i, false, NULL)) && !reinterpret_cast<::Thing575 *>((a2))->FUN_00575400((int)(p)))
            {
                if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(item)))))
                {
                    pExtra = ((::ExtraDataList *)(new ((void *)(((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(item)))))) ::Vec3()));
                }
                else
                {
                    pExtra = NULL;
                }
                if (i == 2)
                {
                    res = dynamic_cast<TESBipedModelForm*>(p);
                }
                else
                {
                    TESBipedModelForm* pInv;
                    pInv = ::TESBipedModelForm::GetFormAsBipedModel(p);
                    if (pInv->HasBipedModel(2, false, NULL))
                    {
                        val = false;
                    }
                }
                if (val)
                {
                    a2->EquipItem(p, 1, pExtra, false);
                }
            }
            delete item;
            item = NULL;
        }
    }
    if (a4 && !a2->HasHealth(false))
    {
        float cnt;
        cnt = 0.0f;
        InventoryStackRecord* pWeaponExtra;
        pWeaponExtra = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((j))->SelectBestWeapon((::ActorStand *)(::TESActorBase *)(this), &cnt, 6, true)));
        if (pWeaponExtra)
        {
            bool pItem = true;
            if (!reinterpret_cast<::Thing575 *>((a2))->FUN_00575400((int)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeaponExtra))->GetName())))))
            {
                ExtraDataList* fWeight;
                fWeight = NULL;
                if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(pWeaponExtra)))))
                {
                    fWeight = ((::ExtraDataList *)(new ((void *)(((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(pWeaponExtra)))))) ::Vec3()));
                    pItem = false;
                }
                else
                {
                    fWeight = NULL;
                }
                TESObjectREFR* bEquipWeapon;
                bEquipWeapon = a2;
                reinterpret_cast<::fnv_0088c830::ThisC *>((bEquipWeapon))->FUN_0088c830((::fnv_0088c830::FormC *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeaponExtra))->GetName()))), ((int)(reinterpret_cast<::Callees *>((pWeaponExtra))->FUN_00726070())), fWeight, true,
                                          false, true);
                if (pItem)
                {
                    delete pWeaponExtra;
                }
            }
            else if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)a2)))->GetBaseTexture())))
            {
                if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeaponExtra))->GetName())) != reinterpret_cast<::FUN_008a1710_shell *>((((Actor*)a2)))->FUN_008a1710())
                {
                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)a2)))->GetBaseTexture()))->SetCurrentArmor(pWeaponExtra, a2->GetNiNode(), false);
                }
            }
        }
    }
    if (a6 == 0)
    {
        reinterpret_cast<::FUN_004623f0_shell *>((::g_BGSSaveLoadGame))->FUN_004623f0(bAllowed);
    }
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture())))
    {
        reinterpret_cast<::ActorSpellView *>((pBiped))->UpdateSpells(true);
    }
}
