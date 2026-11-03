
// src/fallout_shared/bipedanim_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x004abd30: the skeleton of src/fallout_shared/bipedanim.cpp
// with declarations corrected to what the original code does (bipedanim_decls.h: BipedAnim += void FUN_004abd30(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet, QueuedFile* file);). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/B4AEE60Owner.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSXFlags.h"
#include "fnv/decl/BipedAnimHelper.h"
#include "fnv/decl/BipedWeaponRemoval.h"
#include "fnv/decl/C4AEDE0Queue.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004700d0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004aaef0_shell.h"
#include "fnv/decl/FUN_004aaf10_shell.h"
#include "fnv/decl/FUN_004aaff0_S.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004add70_shell.h"
#include "fnv/decl/FUN_004adda0_shell.h"
#include "fnv/decl/FUN_004adde0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004af860_shell.h"
#include "fnv/decl/FUN_004af880_shell.h"
#include "fnv/decl/FUN_004afa20_shell.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_00950b30_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/FaceLoader.h"
#include "fnv/decl/Fake_FUN_004a2020.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/NP_0092c820.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/W_0043b4f0.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_00571760__Actor.h"
#include "fnv/decl/fnv_006148f0__FUN_006148f0_shell.h"
#include "fnv/decl/fnv_006149b0__RaceTexture.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008b0b00__FUN_008b0b00_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ab000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00572000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "bipedanim_decls_decl_bipedanim.h"

// @fnv 0x004abd30
void BipedAnim::FUN_004abd30(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet, QueuedFile* file)
{
    unsigned int modelFlags;
    TESNPC* npc;
    int i;
    NiPointer<QueuedHelmet> pHelmetQueueEntry(0);
    modelFlags = 0;
    npc = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430())));
    if (npc)
    {
        for (i = 0; i < 20; i++)
        {
            if (object[i].m_pModel && object[i].m_pModel != (TESModel*)-1)
            {
                modelFlags |= ((unsigned int)(::FUN_004abf80((unsigned char *)(object[i].m_pModel))));
                if (IsSlotHidden((BIPED_OBJECT)i) && (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011c5ef0)).Bool()->b && ((bool)(::FUN_0043faf0())) &&
                    CanLoadHiddenBipedObjects())
                {
                    reinterpret_cast<::B4AEE60Owner *>(this)->RequestModelLoad((*(int *)&(priority)), (int)(file), (::B4AEE60Request *)&(pHelmetQueueEntry), (*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)i)));
                }
                else
                {
                    if (m_pActor == ::_g_thePlayer)
                    {
                        TESModel* firstPersonModel = GetModelForSlot((BIPED_OBJECT)i, object[i].m_pModel);
                        if (firstPersonModel != object[i].m_pModel)
                            reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30((int)(firstPersonModel), (*(int *)&(priority)), (int)(file), 3, true, false, false);
                    }
                    reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30((int)(object[i].m_pModel), (*(int *)&(priority)), (int)(file), 3, true, false, false);
                    TESBipedModelForm* biped = ::TESBipedModelForm::GetFormAsBipedModel(object[i].pParent);
                    if (biped)
                    {
                        const char* path = biped->FUN_00480ce0();
                        if (*path)
                            reinterpret_cast<::QueueHelper *>((g_modelLoader))->FUN_00444040((int)(path), (*(int *)&(priority)), (int)(file), 3, true, false, false);
                    }
                }
            }
        }
    }
    reinterpret_cast<::NP_0092c820 *>((void *)&(const ::NiPointer< ::QueuedHelmet> &)(queuedHelmet))->FUN_0092c820((const ::NP_0092c820 &)(pHelmetQueueEntry));
    QueueBipedObjectLoads(modelFlags, priority, file);
}
