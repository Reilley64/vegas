// fallout_shared/inventorychanges.cpp: Inventory, InventoryChanges, Target, TESBipedModelForm and more (144 functions)

#include <cstdint>
#include <new>
#include <cstdlib>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/ActionOwner.h"
#include "fnv/decl/ActorBaseTarget.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/Anim490.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/BGSBipedModelList.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSFaceGenKeyframe.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnim.h"
#include "fnv/decl/C418C00ExtraList.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellOwnerCheck.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/CombatWeapon.h"
#include "fnv/decl/CopyableExtraList.h"
#include "fnv/decl/DoorCell.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/ExtraCopyList.h"
#include "fnv/decl/ExtraDataLoader.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040fae0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_00418600_cls.h"
#include "fnv/decl/FUN_00418630_Class.h"
#include "fnv/decl/FUN_00418720_shell.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00418800_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_00418860_Holder.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_00419c60_cls.h"
#include "fnv/decl/FUN_00419ed0_shell.h"
#include "fnv/decl/FUN_00419f80_shell.h"
#include "fnv/decl/FUN_00419fb0_StandIn.h"
#include "fnv/decl/FUN_0041aa20_shell.h"
#include "fnv/decl/FUN_0041ab70_shell.h"
#include "fnv/decl/FUN_0041aed0_shell.h"
#include "fnv/decl/FUN_0041aef0_StandIn.h"
#include "fnv/decl/FUN_0041af10_Class.h"
#include "fnv/decl/FUN_0041afd0_shell.h"
#include "fnv/decl/FUN_0041b010.h"
#include "fnv/decl/FUN_0041b320_shell.h"
#include "fnv/decl/FUN_0041c900_cls.h"
#include "fnv/decl/FUN_0041d000_shell.h"
#include "fnv/decl/FUN_0041d360_shell.h"
#include "fnv/decl/FUN_0041db00_Class.h"
#include "fnv/decl/FUN_00428130_Class.h"
#include "fnv/decl/FUN_0042dde0_cls.h"
#include "fnv/decl/FUN_0042de90_cls.h"
#include "fnv/decl/FUN_0042e5a0_class.h"
#include "fnv/decl/FUN_0042e6f0_shell.h"
#include "fnv/decl/FUN_0042eb40_shell.h"
#include "fnv/decl/FUN_0042eb60_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046e8c0_class.h"
#include "fnv/decl/FUN_00474a00_shell.h"
#include "fnv/decl/FUN_0047bcf0_class.h"
#include "fnv/decl/FUN_0047d7c0_Class.h"
#include "fnv/decl/FUN_00480d30_shell.h"
#include "fnv/decl/FUN_00481110_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00494300_shell.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_004974a0_shell.h"
#include "fnv/decl/FUN_0049eea0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004bcbd0_Class.h"
#include "fnv/decl/FUN_004bcc30_List.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004be080_Class.h"
#include "fnv/decl/FUN_004be1a0_Class.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_004e4620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00621b20_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0081c470_shell.h"
#include "fnv/decl/FUN_008248e0_shell.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00857bd0.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_0088d7d0_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b70d0_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009ca410_shell.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FixupList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn40ea20.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/H.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/Host0087b360.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/KarmaActor.h"
#include "fnv/decl/ListHolder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Matrix161.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/OwnerList.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/PickupSoundActorView.h"
#include "fnv/decl/PlayerNoteStub.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/Ref39.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/Source08.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESLeveledList.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESWeightForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0086cf00.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/extra_save__SaveShell.h"
#include "fnv/decl/fnv_0040fe20__FUN_0040fe20_shell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00411ec0__FUN_00411ec0_shell.h"
#include "fnv/decl/fnv_004121e0__ExtraDataListCopyListForContainer.h"
#include "fnv/decl/fnv_00412380__FUN_00412380_shell.h"
#include "fnv/decl/fnv_004126c0__FUN_004126c0_shell.h"
#include "fnv/decl/fnv_00418550__FUN_00418550_cls.h"
#include "fnv/decl/fnv_00419700__FUN_00419700_shell.h"
#include "fnv/decl/fnv_0041af30__FUN_0041af30_shell.h"
#include "fnv/decl/fnv_0041b2a0__FUN_0041b2a0_shell.h"
#include "fnv/decl/fnv_0041c7f0__FUN_0041c7f0_cls.h"
#include "fnv/decl/fnv_0041d030__FUN_0041d030_shell.h"
#include "fnv/decl/fnv_0041d120__FUN_0041d120_shell.h"
#include "fnv/decl/fnv_0041d280__FUN_0041d280_shell.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/decl/fnv_00422c40__ExtraDataListQ.h"
#include "fnv/decl/fnv_00426a30__Owner.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00474a40__FUN_00474a40_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00482090__FUN_00482090_shell.h"
#include "fnv/decl/fnv_00482770__FUN_00482770_shell.h"
#include "fnv/decl/fnv_00490e60__FUN_00490e60_shell.h"
#include "fnv/decl/fnv_00494390__MovementAnimation.h"
#include "fnv/decl/fnv_004955c0__FUN_004955c0_t.h"
#include "fnv/decl/fnv_00496080__FUN_00496080_shell.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_004985f0__FUN_004985f0_s.h"
#include "fnv/decl/fnv_00498cf0__FUN_00498cf0_shell.h"
#include "fnv/decl/fnv_004994f0__FUN_004994f0_shell.h"
#include "fnv/decl/fnv_0049bca0__FUN_0049bca0_shell.h"
#include "fnv/decl/fnv_004efbc0__HY.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/decl/fnv_00567770__FUN_00567770_shell.h"
#include "fnv/decl/fnv_00567ad0__FUN_00567ad0.h"
#include "fnv/decl/fnv_00567e10__FUN_00567e10_shell.h"
#include "fnv/decl/fnv_00568bb0__FUN_00568bb0_shell.h"
#include "fnv/decl/fnv_00571760__Actor.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00861780__FUN_00861780_StandIn.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008b0b00__FUN_008b0b00_cls.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/load_extra_fixup__ThisQ.h"
#include "fnv/decl/p376__Extras.h"
#include "fnv/decl/s55d310__Owner.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00421000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0047b000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_00497000.h"
#include "fnv/symbols_00499000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_004bf000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_004ce000.h"
#include "fnv/symbols_004d1000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00679000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_008ba000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "inventorychanges_packet.h"
#include "../../include/TESObjectREFR.h"
#include "Actor.h"
#include "BaseProcess.h"
#include "AutoMemContext.h"
#include "game_constants.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/M_004b4500.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_008b8e90__FUN_008b8e90_shell.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_004c1000.h"
#include "fnv/symbols_0101c000.h"
#include "fnv/symbols_0101d000.h"


// @fnv 0x004bf220
InventoryChanges* InventoryChanges::CreateForReference(TESObjectREFR* reference)
{
    InventoryChanges* changes = 0;
    if (!reference->IsMobileObject() || reference->IsActor())
    {
        changes = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))->GetContainerChangeData();
        if (!changes)
        {
            AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_INVENTORY, true, ::DAT_01020778,
                                   kInventoryChangesCreateSourceLine);
            changes = new InventoryChanges(reference);
            ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))->SetContainerChanges(changes);
        }
    }
    return changes;
}

// @fnv 0x007b5370
void* InventoryStackRecord::GetPayloadAddress()
{
    return reinterpret_cast<char*>(m_iCountChange) + 8;
}

// @fnv 0x0056aa70
InventoryChanges* InventoryChanges::CreateForReference()
{
    return ((::InventoryChanges *)(reinterpret_cast<::FUN_0041db00_Class *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reinterpret_cast<TESObjectREFR*>(this)))->FUN_005d43c0()))))->FUN_0041db00()));
}

// @fnv 0x004c0bd0
bool TESBipedModelForm::GetIsHeavyArmor() const
{
    return static_cast<bool>(flags & 0x80);
}

// Initializes three fields to zero.
// @fnv 0x0076b630
InventoryStackRecord::InventoryStackRecord()
{
    m_pItemObject = 0;
    m_pExtraDataLists = 0;
    m_iCountChange = 0;
}

// A delete expression makes MSVC9 emit the nonvirtual scalar deleting destructor.
// Deletes the given item object.
// @fnv 0x004459e0
void DeleteItemChange(InventoryStackRecord* item)
{
    delete item;
}

// @fnv 0x00476b20
float InventoryStackRecord::GetConditionPercent(float value)
{
    float rounded = TruncateToInt(value);
    return static_cast<float>(rounded - value >= 0.0 ? rounded : rounded + 1.0);
}

// Walks a linked list of ExtraDataList entries and calls InitLoadGame on each with the given buffer and form.
// @fnv 0x004bef60
void InventoryStackRecord::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(m_pExtraDataLists);
    while (node)
    {
        ExtraDataList* extra = reinterpret_cast<ExtraDataList*>((node->m_item));
        if (extra)
            reinterpret_cast<::FixupList *>((extra))->FixupReferences((::FixupStream *)(buffer), reinterpret_cast<TESForm*>(m_pItemObject));
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}

// @fnv 0x004bd510
float InventoryStackRecord::RoundToNearestStep(float value, float step)
{
    float ratio = value / step;
    return (static_cast<int>(ratio) + (ratio - static_cast<int>(ratio) < 0.5 ? 0 : 1)) * step;
}

// @fnv 0x004bcb70
bool InventoryStackRecord::HasPerkEntry()
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(m_pExtraDataLists);
    while (node && (node->m_item))
    {
        ExtraDataList* extra = reinterpret_cast<ExtraDataList*>((node->m_item));
        if (extra && extra->HasExtraDataType0x2F())
            return true;
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return false;
}

// Walks a BSSimpleList of BGSPerkEntry pointers and returns true if any entry's ExtraDataList check succeeds.
// @fnv 0x004bccb0
bool InventoryStackRecord::HasApplicablePerkEntry()
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(m_pExtraDataLists);
    while (node && (node->m_item))
    {
        ExtraDataList* extra = reinterpret_cast<ExtraDataList*>((node->m_item));
        if (extra && reinterpret_cast<::fnv_0041d030::FUN_0041d030_shell *>((extra))->FUN_0041d030())
            return true;
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return false;
}

struct FUN_004bc5f0_shell : public InventoryStackRecord
{
    void FUN_004bc5f0();
};

// Removes and deletes the BSSimpleList<ExtraDataList*> stored at the start of the object, then nulls the pointer.
// @fnv 0x004bc5f0
void FUN_004bc5f0_shell::FUN_004bc5f0()
{
    if (*(BSSimpleList<ExtraDataList*>**)this)
        reinterpret_cast<::FileMatchList *>(((*(BSSimpleList<ExtraDataList*>**)this)))->RemoveAll();
    delete *(BSSimpleList<ExtraDataList*>**)this;
    *(BSSimpleList<ExtraDataList*>**)this = 0;
}

struct FUN_004bc780_shell : public InventoryStackRecord
{
    void ClearExtraDataList();
};

struct _DummyExtraDataList
{
    virtual ~_DummyExtraDataList();
};

struct _DummySimpleList
{
};

// @fnv 0x004bc780
void FUN_004bc780_shell::ClearExtraDataList()
{
    _DummySimpleList* pkCurrentObject = *reinterpret_cast<_DummySimpleList**>(this);
    while (pkCurrentObject && *((::ExtraDataList **)((void *)(pkCurrentObject))))
    {
        ExtraDataList* pExtra = *((::ExtraDataList **)((void *)(pkCurrentObject)));
        reinterpret_cast<::FUN_0040fae0_shell *>((reinterpret_cast<_DummyExtraDataList*>(pExtra)))->FUN_0040fae0(true);
        reinterpret_cast<::ItemChangeListNode *>((pkCurrentObject))->FUN_00905330((*(::InventoryStackRecord *const *)(&pExtra)));
        delete reinterpret_cast<_DummyExtraDataList*>(pExtra);
        pkCurrentObject = ((::_DummySimpleList *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
    }
}

struct XExtra
{
};
struct XNode
{
};
struct FUN_004bc8f0_stand
{
    XNode* first;
    int FUN_004bc8f0(bool abWornIgnore);
};
struct FUN_004bc980_shell : public InventoryStackRecord
{
    int FUN_004bc980();
};

struct ExtraNode;
struct ListRemover
{
};
struct FUN_0041d120_shell
{
};
struct ExtraVDtor
{
    virtual ~ExtraVDtor();
};
struct ExtraEmptyShell
{
};

// Walks the extra-data list, summing FUN_00418770 for entries where HasOnlyAllowedExtraData(0) is true, and removes empty entries while resetting the count.
// @fnv 0x004bc980
int FUN_004bc980_shell::FUN_004bc980()
{
    ExtraNode* pkCurrentObject = *(ExtraNode**)this;
    int icount = 0;
    while (pkCurrentObject && *((::ExtraDataList **)((void *)(pkCurrentObject))))
    {
        ExtraDataList* pExtra = *((::ExtraDataList **)((void *)(pkCurrentObject)));
        if (reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((((FUN_0041d120_shell*)pExtra)))->HasOnlyAllowedExtraData(0))
            icount += reinterpret_cast<::FUN_00418770_shell *>((void *)(pExtra))->FUN_00418770();
        pkCurrentObject = ((::ExtraNode *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
        if (reinterpret_cast<::ExtraDataList *>((((ExtraEmptyShell*)pExtra)))->IsEmpty())
        {
            reinterpret_cast<::ItemChangeListNode *>(((*(ListRemover**)this)))->FUN_00905330((*(::InventoryStackRecord *const *)(&pExtra)));
            delete (ExtraVDtor*)pExtra;
            icount = 0;
            pkCurrentObject = *(ExtraNode**)this;
        }
    }
    return icount;
}

struct FUN_004bca80_shell : public InventoryStackRecord
{
    int CountAndPruneEntries();
};

struct ExtraHelper_004bca80
{
    virtual ~ExtraHelper_004bca80();
};

struct ListHelper_004bca80
{
};

// @fnv 0x004bca80
int FUN_004bca80_shell::CountAndPruneEntries()
{
    ListHelper_004bca80* pkCurrentObject = *(ListHelper_004bca80**)this;
    int icount = 0;
    while (pkCurrentObject && *((::ExtraHelper_004bca80 **)((void *)(pkCurrentObject))))
    {
        ExtraHelper_004bca80* pExtra = *((::ExtraHelper_004bca80 **)((void *)(pkCurrentObject)));
        short sValue = reinterpret_cast<::FUN_00418770_shell *>((pExtra))->FUN_00418770();
        if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((pExtra))->HasOnlyAllowedExtraData(0) && sValue > 0)
        {
            icount = icount + 1;
        }
        pkCurrentObject = ((::ListHelper_004bca80 *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
        if (((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((pExtra))->FUN_0040fe20())) == 1 && sValue > 1)
        {
            reinterpret_cast<::FUN_0041af10_Class *>((pExtra))->RemoveExtra24();
            reinterpret_cast<::ItemChangeListNode *>(((*(ListHelper_004bca80**)this)))->FUN_00905330((*(::InventoryStackRecord *const *)(&pExtra)));
            delete pExtra;
            icount = 0;
            pkCurrentObject = *(ListHelper_004bca80**)this;
        }
    }
    return icount;
}

namespace fnv_004bda70 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_004bda70_shell : public InventoryStackRecord
{
    bool HasEffect(unsigned char);
};

struct ExtraNode;
struct FUN_00418c00_shell
{
};
struct FUN_004bd880_shell
{
    unsigned int GetSlotPointer(int);
};

// Checks the extra data list and weapon for effect slots 1, 2 and 4, returning true if any slot's effect matches eEffect.
// @fnv 0x004bda70
bool FUN_004bda70_shell::HasEffect(unsigned char eEffect)
{
    ExtraNode* pkCurrentObject = *(ExtraNode**)this;
    if (pkCurrentObject && *((::ExtraDataList **)((void *)(pkCurrentObject))))
    {
        ExtraDataList* pextra = *((::ExtraDataList **)((void *)(pkCurrentObject)));
        if (pextra)
        {
            FUN_004bd880_shell* pweap = (*(FUN_004bd880_shell**)&this->m_pItemObject);
            if (reinterpret_cast<::C418C00ExtraList *>((((FUN_00418c00_shell*)pextra)))->CheckExtraByType(1) && pweap->GetSlotPointer(1) == eEffect)
                return true;
            if (reinterpret_cast<::C418C00ExtraList *>((((FUN_00418c00_shell*)pextra)))->CheckExtraByType(2) && pweap->GetSlotPointer(2) == eEffect)
                return true;
            if (reinterpret_cast<::C418C00ExtraList *>((((FUN_00418c00_shell*)pextra)))->CheckExtraByType(4) && pweap->GetSlotPointer(4) == eEffect)
                return true;
        }
    }
    return false;
}
}  // namespace fnv_004bda70

struct FUN_004bddd0_shell : public InventoryStackRecord
{
    bool FUN_004bddd0(bool);
};

struct ExtraDataList_shell
{
};

struct Script;
struct FUN_004bde40_shell : public InventoryStackRecord
{
    Script* FUN_004bde40();
};


// Walks the linked list from this, returning the Script attached to the first entry whose ExtraDataList has one, or null.
// @fnv 0x004bde40
Script* FUN_004bde40_shell::FUN_004bde40()
{
    void* pkCurrentObject = *reinterpret_cast<void**>(this);
    while (pkCurrentObject && *((::ExtraDataList **)((void *)(pkCurrentObject))))
    {
        ExtraDataList* pextra = *((::ExtraDataList **)((void *)(pkCurrentObject)));
        if (pextra && reinterpret_cast<::FUN_00418800_shell *>((pextra))->FUN_00418800())
        {
            return reinterpret_cast<::FUN_00418800_shell *>((pextra))->FUN_00418800();
        }
        pkCurrentObject = reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070();
    }
    return 0;
}


// @fnv 0x004be060
int FUN_004be060(void* pThis)
{
    return ((int)(reinterpret_cast<::FUN_004be080_Class *>((pThis))->FUN_004be080()));
}

// @fnv 0x004be180
float FUN_004be180(char* pThis)
{
    return *(float*)(pThis + 0x17c);
}

struct ItemNode;
struct ExtraNode;
int _FNV_GetFormType(unsigned int);
struct ArrSI
{
};
struct FUN_00418ab0_shell
{
    bool FUN_00418ab0(bool);
};
// @fnv 0x004bc8f0
int FUN_004bc8f0_stand::FUN_004bc8f0(bool abWornIgnore)
{
    int icount;
    XNode* pkCurrentObject = first;
    icount = 0;
    while (pkCurrentObject && *((::XExtra **)((void *)(pkCurrentObject))))
    {
        XExtra* pExtra = *((::XExtra **)((void *)(pkCurrentObject)));
        if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((pExtra))->HasOnlyAllowedExtraData(0) && (abWornIgnore || !reinterpret_cast<::FUN_00418ab0_shell *>((pExtra))->FUN_00418ab0(0)))
            icount += reinterpret_cast<::FUN_00418770_shell *>((pExtra))->FUN_00418770();
        pkCurrentObject = ((::XNode *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
    }
    return icount;
}
// Walks the ExtraDataList linked list and returns true if any entry's FUN_00418ab0(ableft) check succeeds.
// @fnv 0x004bddd0
bool FUN_004bddd0_shell::FUN_004bddd0(bool ableft)
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject = *(BSSimpleList<ExtraDataList*>**)this;
    while (pkCurrentObject && (pkCurrentObject->m_item))
    {
        ExtraDataList* pextra = (pkCurrentObject->m_item);
        if (pextra && reinterpret_cast<::FUN_00418ab0_shell *>((((ExtraDataList_shell*)pextra)))->FUN_00418ab0(ableft))
        {
            return true;
        }
        pkCurrentObject = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
    }
    return false;
}

struct FUN_004bfc80_shell : public InventoryChanges
{
    bool FUN_004bfc80();
};

// @fnv 0x004bfc80
bool FUN_004bfc80_shell::FUN_004bfc80()
{
    ItemNode* pkCurrentObject;
    InventoryStackRecord* pchange3;
    bool bfound7;
    bfound7 = false;
    pchange3 = 0;
    pkCurrentObject = *(ItemNode**)this;
    while (pkCurrentObject && *((::InventoryStackRecord **)((void *)(pkCurrentObject))))
    {
        pchange3 = *((::InventoryStackRecord **)((void *)(pkCurrentObject)));
        if (pchange3 && _FNV_GetFormType(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pchange3)))->GetName()))) == 24 && !bfound7)
        {
            unsigned int flags3 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pchange3)))->GetName()));
            ExtraNode* pkFirst2 = *(ExtraNode**)pchange3;
            ExtraDataList* pextra = 0;
            while (pkFirst2 && *((::ExtraDataList **)((void *)(pkFirst2))) && !bfound7)
            {
                pextra = *((::ExtraDataList **)((void *)(pkFirst2)));
                if (pextra && ((FUN_00418ab0_shell*)pextra)->FUN_00418ab0(false) && ((bool)(::FUN_004bfd80((unsigned char *)(flags3)))))
                    bfound7 = true;
                pkFirst2 = ((::ExtraNode *)(reinterpret_cast<::Callees *>((pkFirst2))->FUN_00726070()));
            }
        }
        pkCurrentObject = ((::ItemNode *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
    }
    return bfound7;
}

// @fnv 0x004bfd80
unsigned char FUN_004bfd80(unsigned char* pData)
{
    return (pData[0x180] & 1) != 0;
}

namespace fnv_004bfda0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_004bfda0_shell : public InventoryChanges
{
    ExtraDataList* FUN_004bfda0(TESBoundObject*, bool);
};

struct FUN_00418ab0_shell
{
};
struct FUN_00418b10_shell
{
    bool FUN_00418b10();
};
struct FUN_0041aa20_shell
{
};
struct ExtraNode;
struct FUN_004bfba0_shell
{
    ExtraNode** FUN_004bfba0(TESBoundObject*, bool, bool);
};

// @fnv 0x004bfda0
ExtraDataList* FUN_004bfda0_shell::FUN_004bfda0(TESBoundObject* apObj, bool bshouldwear)
{
    ExtraNode** pkCurrentObject = ((FUN_004bfba0_shell*)this)->FUN_004bfba0(apObj, true, false);
    if (pkCurrentObject)
    {
        ExtraNode* node = *pkCurrentObject;
        while (node && *((::ExtraDataList **)((void *)(node))))
        {
            ExtraDataList* pExtra = *((::ExtraDataList **)((void *)(node)));
            if (pExtra && reinterpret_cast<::FUN_00418ab0_shell *>((((FUN_00418ab0_shell*)pExtra)))->FUN_00418ab0(false))
                return pExtra;
            else if (pExtra && ((FUN_00418b10_shell*)pExtra)->FUN_00418b10() && bshouldwear)
            {
                reinterpret_cast<::FUN_0041aa20_shell *>((((FUN_0041aa20_shell*)pExtra)))->SetWornState(true, false);
                return pExtra;
            }
            node = ((::fnv_004bfda0::ExtraNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    return 0;
}
}  // namespace fnv_004bfda0

class TESObjectWEAP
{
  public:
public:
    float GetWeightForForm(bool);
};


// Returns true when weap is a ranged weapon and FUN_004c0c60 returns false for it.
// @fnv 0x004c0bf0
bool FUN_004c0bf0(TESObjectWEAP* weap)
{
    return ::FUN_004c0c30((char *)(weap)) && !::FUN_004c0c60((::FUN_004c0c60_Helper *)(weap));
}

// Returns true when the byte at offset 0xf4 of the object is between 3 and 13, otherwise false.
// @fnv 0x004c0c30
bool FUN_004c0c30(char* pThis)
{
    switch (pThis[0xf4])
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return true;
    default:
        return false;
    }
}

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct NiPoint3;
struct TESAnimGroup;
struct TESIdleForm;
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    void SetReloadState(bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    void ClearDelta();
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    void SpecialIdleFree(bool, bool);
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    char m_kNodeTranslation[12];
    char m_kRootTranslation[12];
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
struct FUN_004c0c90_shell : public Animation
{
    void FUN_004c0c90(float);
};

// @fnv 0x004c0c90
void FUN_004c0c90_shell::FUN_004c0c90(float attackSpeed)
{
    if (attackSpeed < 0.1f)
    {
        m_fCombatAnimationRate = 0.1f;
    }
    else
    {
        m_fCombatAnimationRate = attackSpeed;
    }
}

namespace fnv_004c3380 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_004c3380_shell : public InventoryChanges
{
    void FUN_004c3380(InventoryStackRecord*, bool);
};

struct TESFormAccess
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void MarkAsModified(unsigned int changedFlags);
};

struct ItemChangeAccess
{
};

struct ExtraDataListAccess
{
    virtual ~ExtraDataListAccess();
    TESObjectREFR* GetReplacementReference();
};

template <class T> class BSSimpleListAccess : public BSSimpleList<T>
{
  public:
    void Remove(const T&);
};

struct InventoryChangesAccess
{
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, bool, bool);
};

class TESObjectWEAP
{
  public:
};

int FNV_GetFormType(TESForm*);

// Merges an inventory change into this list: combines counts and extra-data lists, optionally deletes the source, and removes emptied entries.
// @fnv 0x004c3380
void FUN_004c3380_shell::FUN_004c3380(InventoryStackRecord* apChange, bool abDelete)
{
    AutoMemContext tempMemContext(MEM_CONTEXT_MEM_CONTEXT_INVENTORY, true, ::DAT_01020778, 0xe03);
    this->m_fArmorWeight = this->m_fTotalWeight;
    this->m_fTotalWeight = -1.0f;
    if (!apChange)
        return;

    if (this->pRef)
        (*(TESFormAccess**)&this->pRef)->MarkAsModified(0x20);

    InventoryStackRecord* pitem =
        ((InventoryChangesAccess*)this)->FUN_004bfba0(((::fnv_004c3380::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((ItemChangeAccess*)apChange)))->GetName())), true, false);
    TESBoundObject* pobject = ((::fnv_004c3380::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((ItemChangeAccess*)apChange)))->GetName()));
    bool bIsThrown = false;
    if (FNV_GetFormType((TESForm*)pobject) == 0x28)
    {
        TESObjectWEAP* pWeap = (TESObjectWEAP*)pobject;
        bIsThrown = ::FUN_004c0bf0((::TESObjectWEAP *)(pWeap));
    }

    if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(((ItemChangeAccess*)apChange))))) && ((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(((ItemChangeAccess*)apChange)))))->IsEmpty())
    {
        delete apChange->m_pExtraDataLists;
        apChange->m_pExtraDataLists = 0;
    }

    if (pitem)
    {
        BSSimpleList<ExtraDataList*>* pChangeFirst;
        reinterpret_cast<::CombatProcedure *>((((ItemChangeAccess*)pitem)))->Initialize((::CombatController *)(std::uintptr_t)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ItemChangeAccess*)pitem)))->FUN_00726070())) + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ItemChangeAccess*)apChange)))->FUN_00726070()))));
        if (!apChange->m_pExtraDataLists || !apChange->m_pExtraDataLists->IsEmpty())
        {
            pChangeFirst = pitem->m_pExtraDataLists;
            BSSimpleList<ExtraDataList*>* pkCurrentObject = apChange->m_pExtraDataLists;
            while (pkCurrentObject && (pkCurrentObject->m_item))
            {
                ExtraDataList* pcompare = (pkCurrentObject->m_item);
                bool bHasResultObj = true;
                if (((ExtraDataListAccess*)pcompare)->GetReplacementReference())
                    reinterpret_cast<::fnv_0041c7f0::FUN_0041c7f0_cls *>((((ExtraDataListAccess*)pcompare)))->FUN_0041c7f0(this->pRef);

                while (pChangeFirst && (pChangeFirst->m_item) && bHasResultObj)
                {
                    ExtraDataList* pCurrent = (pChangeFirst->m_item);
                    bool bcomp = true;
                    if (pcompare)
                        bcomp = reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((((ExtraDataListAccess*)pcompare)))->FUN_004126c0(pCurrent, false, bIsThrown) ||
                                reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((((ExtraDataListAccess*)pCurrent)))->FUN_004126c0(pcompare, false, bIsThrown);
                    if (!bcomp)
                    {
                        reinterpret_cast<::FUN_00419ad0_shell *>((((ExtraDataListAccess*)pCurrent)))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((void *)(((ExtraDataListAccess*)pCurrent)))->FUN_00418770() +
                                           reinterpret_cast<::FUN_00418770_shell *>((void *)(((ExtraDataListAccess*)pcompare)))->FUN_00418770());
                        if (pcompare)
                        {
                            reinterpret_cast<::ItemChangeListNode *>((((BSSimpleListAccess<ExtraDataList*>*)apChange->m_pExtraDataLists)))->FUN_00905330((::InventoryStackRecord *const &)(pcompare));
                            delete (ExtraDataListAccess*)pcompare;
                        }
                        bHasResultObj = false;
                    }
                    else
                        pChangeFirst = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((pChangeFirst))->FUN_00726070()));
                }

                if (bHasResultObj)
                {
                    if (!pitem->m_pExtraDataLists)
                        pitem->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
                    pitem->m_pExtraDataLists->AddHead(pcompare);
                }
                pkCurrentObject = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
            }

            if (abDelete)
            {
                delete apChange;
                apChange = 0;
            }
        }

        pitem = ((InventoryChangesAccess*)this)->FUN_004bfba0(pobject, true, false);
        if (pitem && (!pitem->m_pExtraDataLists || pitem->m_pExtraDataLists->IsEmpty()) &&
            !((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ItemChangeAccess*)pitem)))->FUN_00726070())))
        {
            reinterpret_cast<::ItemChangeListNode *>(((*(BSSimpleListAccess<InventoryStackRecord*>**)this)))->FUN_00905330(pitem);
            delete pitem;
            delete apChange;
        }
    }
    else
        reinterpret_cast<::Callees *>(((*(BSSimpleList<InventoryStackRecord*>**)this)))->FUN_00905820((void *)&(apChange));
}
}  // namespace fnv_004c3380

struct FUN_004c94d0_shell
{
    unsigned char GetFlag() const;
};

// @fnv 0x004c94d0
unsigned char FUN_004c94d0_shell::GetFlag() const
{
    return !(reinterpret_cast<const unsigned char*>(this)[0xac] & 2);
}

// @fnv 0x004d1360
bool FUN_004d1360(char* pThis)
{
    return *(int*)(pThis + 0x7bc) == 1 ? true : false;
}

namespace fnv_0087ce80 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct FUN_0087ce80_shell : public TESObjectREFR
{
    void FUN_0087ce80(TESObjectCELL*);
};

// @fnv 0x0087ce80
void FUN_0087ce80_shell::FUN_0087ce80(TESObjectCELL* apCell)
{
    *reinterpret_cast<TESObjectCELL**>(&this->m_pOwningCell) = apCell;
}
}  // namespace fnv_0087ce80

struct VATSCommand
{
    int eType;
    void* pTarget;
    unsigned char cCount;
    bool bFadeQueuedCur;
    ~VATSCommand();
};
struct VATS_CommandList
{
    VATSCommand* pItem;
    VATS_CommandList* pNext;
    bool FUN_008256d0();
};
struct Setting_S
{
};
struct GameTimerRecord
{
    void SetGlobalTimeMultiplier(float, bool);
};

struct VATS
{
    VATS_CommandList m_kCommandList;
    int eMode;
    void FUN_009c8950(bool abForceQuit, bool abFinishCommandPlayback);
};

// @fnv 0x009c8950
void VATS::FUN_009c8950(bool abForceQuit, bool abFinishCommandPlayback)
{
    VATSCommand* pcommand;
    VATS_CommandList* pCurrentElementNext;
    if (!eMode || (DAT_011f21e0 != 0.0 && m_kCommandList.FUN_008256d0()))
        return;
    if (!abForceQuit && !m_kCommandList.FUN_008256d0() && (*((::VATSCommand **)((void *)&(m_kCommandList))))->eType == 15)
        return;
    if (abFinishCommandPlayback)
    {
        pcommand = ((::VATSCommand *)(reinterpret_cast<::ListHolder *>(this)->FUN_009c71c0()));
        if (pcommand && pcommand->cCount > 1)
        {
            pcommand->cCount = 1;
            pcommand->bFadeQueuedCur = false;
        }
        if (!m_kCommandList.FUN_008256d0())
        {
            pCurrentElementNext = ((::VATS_CommandList *)(reinterpret_cast<::Callees *>(&(m_kCommandList))->FUN_00726070()));
            while (pCurrentElementNext)
            {
                VATSCommand* pCommandToDelete = *((::VATSCommand **)((void *)(pCurrentElementNext)));
                delete pCommandToDelete;
                reinterpret_cast<::ItemChangeListNode *>(&(m_kCommandList))->FUN_00905330((::InventoryStackRecord *const &)(pCommandToDelete));
                pCurrentElementNext = ((::VATS_CommandList *)(reinterpret_cast<::Callees *>(&(m_kCommandList))->FUN_00726070()));
            }
        }
    }
    else
    {
        reinterpret_cast<::FUN_009ca410_shell *>(this)->ProcessVATSCommands();
        DAT_011f21e0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting543))))));
        reinterpret_cast<::FUN_00aa4db0_shell *>(&(g_timeGlobal))->FUN_00aa4db0(1.0f, false);
    }
}

struct FUN_004bd9d0_shell
{
    float FUN_004bd9d0(int a1, unsigned char a2);
};

// Returns a float field selected by a1 (1, 2 or 4) and a2 (0 or 1), otherwise 0.0f.
// @fnv 0x004bd9d0
float FUN_004bd9d0_shell::FUN_004bd9d0(int a1, unsigned char auiSubIndex)
{
    if (a1 == 1)
    {
        if (auiSubIndex == 0)
        {
            return *(float*)((char*)this + 0x18c);
        }
        else if (auiSubIndex == 1)
        {
            return *(float*)((char*)this + 0x1ac);
        }
    }
    else if (a1 == 2)
    {
        if (auiSubIndex == 0)
        {
            return *(float*)((char*)this + 0x190);
        }
        else if (auiSubIndex == 1)
        {
            return *(float*)((char*)this + 0x1b0);
        }
    }
    else if (a1 == 4)
    {
        if (auiSubIndex == 0)
        {
            return *(float*)((char*)this + 0x194);
        }
        else if (auiSubIndex == 1)
        {
            return *(float*)((char*)this + 0x1b4);
        }
    }
    return 0.0f;
}


struct FUN_00766a10_shell
{
    void SetCapacity(unsigned int a);
};

// Stores the result of BSStringCapacityMaximum(1, a) at offset 0x10 of this object.
// @fnv 0x00766a10
void FUN_00766a10_shell::SetCapacity(unsigned int auiCapacity)
{
    *(unsigned int*)((char*)this + 0x10) = ::FUN_00403940(1, auiCapacity);
}

struct FUN_0042dec0_shell : public BaseExtraList
{
    void FUN_0042dec0();
};
// @fnv 0x0042dec0
void FUN_0042dec0_shell::FUN_0042dec0()
{
    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x4a);
}

struct GetModHelper_4bcf00
{
};
struct FUN_004bcf00_stand
{
    int GetModdedValue(bool);
};
struct FUN_004bcf60_shell
{
    float GetEffectValue(int effect, unsigned char value);
};
// @fnv 0x004bcf00
int FUN_004bcf00_stand::GetModdedValue(bool abAddMod)
{
    if (abAddMod)
    {
        return (int)((double)reinterpret_cast<::FUN_004bcf60_shell *>((((GetModHelper_4bcf00*)this)))->GetEffectValue(10, 0) +
                     (double)(unsigned int)(std::uintptr_t)((::_DummySimpleList *)(reinterpret_cast<::Callees *>((((_DummySimpleList*)((char*)this + 0x94))))->FUN_00726070())));
    }
    else
    {
        return (int)(std::uintptr_t)((::_DummySimpleList *)(reinterpret_cast<::Callees *>((((_DummySimpleList*)((char*)this + 0x94))))->FUN_00726070()));
    }
}

// Looks up one of three effect IDs and returns the float stored for value 0 or 1, otherwise 0.0f.
// @fnv 0x004bcf60
float FUN_004bcf60_shell::GetEffectValue(int effect, unsigned char value)
{
    if (*(int*)((char*)this + 0x180) == effect)
    {
        if (!value)
            return *(float*)((char*)this + 0x18c);
        else if (value == 1)
            return *(float*)((char*)this + 0x1ac);
    }
    else if (*(int*)((char*)this + 0x184) == effect)
    {
        if (!value)
            return *(float*)((char*)this + 0x190);
        else if (value == 1)
            return *(float*)((char*)this + 0x1b0);
    }
    else if (*(int*)((char*)this + 0x188) == effect)
    {
        if (!value)
            return *(float*)((char*)this + 0x194);
        else if (value == 1)
            return *(float*)((char*)this + 0x1b4);
    }
    else
        return 0.0f;
    return 0.0f;
}

struct FUN_004bd570_this
{
    int FUN_004bd570(unsigned int);
};
// Returns the int stored at offset 0x350, 0x354 or 0x358 for slot 1, 2 or 4, otherwise 0.
// @fnv 0x004bd570
int FUN_004bd570_this::FUN_004bd570(unsigned int slot)
{
    if (slot == 1)
    {
        return *(int*)((char*)this + 0x350);
    }
    else if (slot == 2)
    {
        return *(int*)((char*)this + 0x354);
    }
    else if (slot == 4)
    {
        return *(int*)((char*)this + 0x358);
    }
    else
    {
        return 0;
    }
}

struct FUN_00418660_shell
{
    TESForm* FUN_00418660();
};
struct FUN_004bd740_stand
{
    TESForm* GetExtraForm();
};
// Returns the form from the extra data list's first entry if the list and entry exist, otherwise returns null.
// @fnv 0x004bd740
TESForm* FUN_004bd740_stand::GetExtraForm()
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject = *(BSSimpleList<ExtraDataList*>**)this;
    ExtraDataList* pextra;
    if (pkCurrentObject && *((::ExtraDataList **)((void *)(((_DummySimpleList*)pkCurrentObject)))))
    {
        pextra = *((::ExtraDataList **)((void *)(((_DummySimpleList*)pkCurrentObject))));
        if (pextra && ((FUN_00418660_shell*)pextra)->FUN_00418660())
            return ((FUN_00418660_shell*)pextra)->FUN_00418660();
    }
    return 0;
}

struct FUN_00418ba0_shell
{
    bool FUN_00418ba0();
};
struct FUN_0042e560_shell
{
    unsigned char FUN_0042e560();
};
struct FUN_004bd820_stand
{
    unsigned char FUN_004bd820();
};
// Checks the list stored at this; if it and its first ExtraDataList exist and pass FUN_00418ba0, returns FUN_0042e560's result, else 0.
// @fnv 0x004bd820
unsigned char FUN_004bd820_stand::FUN_004bd820()
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject;
    ExtraDataList* pextra;
    pkCurrentObject = *(BSSimpleList<ExtraDataList*>**)this;
    if (pkCurrentObject && *((::ExtraDataList **)((void *)(((_DummySimpleList*)pkCurrentObject)))))
    {
        pextra = *((::ExtraDataList **)((void *)(((_DummySimpleList*)pkCurrentObject))));
        if (pextra && ((FUN_00418ba0_shell*)pextra)->FUN_00418ba0())
            return ((FUN_0042e560_shell*)pextra)->FUN_0042e560();
    }
    return 0;
}

struct Caller_42
{
};
struct Holder_70
{
    _DummySimpleList* first;
    void FUN_004bdc70();
};
// If the list has a first node whose referenced object is non-null, calls FUN_0042e6f0 on it.
// @fnv 0x004bdc70
void Holder_70::FUN_004bdc70()
{
    _DummySimpleList* pNode = first;
    if (pNode)
    {
        if (*((::ExtraDataList **)((void *)(pNode))))
        {
            Caller_42* pItem = (Caller_42*)*((::ExtraDataList **)((void *)(pNode)));
            if (pItem)
                reinterpret_cast<::FUN_0042e6f0_shell *>((pItem))->FUN_0042e6f0();
        }
    }
}

struct FUN_004187d0_Class
{
    BSExtraData* FUN_004187d0();
};
struct FUN_004bdcc0_Class
{
    _DummySimpleList* first;
    BSExtraData* FUN_004bdcc0();
};
// Returns the BSExtraData from the first list entry's ExtraDataList if both the list and its extra data are non-null, otherwise null.
// @fnv 0x004bdcc0
BSExtraData* FUN_004bdcc0_Class::FUN_004bdcc0()
{
    BSExtraData* result = 0;
    _DummySimpleList* iter = first;
    if (iter && *((::ExtraDataList **)((void *)(iter))))
    {
        ExtraDataList* extra = *((::ExtraDataList **)((void *)(iter)));
        if (extra && ((FUN_004187d0_Class*)extra)->FUN_004187d0())
            result = ((FUN_004187d0_Class*)extra)->FUN_004187d0();
    }
    return result;
}

namespace fnv_004bdd80 {
struct FUN_004187d0_Class
{
};
struct FUN_0041af30_Class
{
};
struct FUN_004bdd80_stand
{
    _DummySimpleList* m_pHeadNode;
    void FUN_004bdd80();
};
// @fnv 0x004bdd80
void FUN_004bdd80_stand::FUN_004bdd80()
{
    _DummySimpleList* pNode = m_pHeadNode;
    if (pNode && *((::ExtraDataList **)((void *)(pNode))))
    {
        ExtraDataList* pExtra = *((::ExtraDataList **)((void *)(pNode)));
        if (pExtra && reinterpret_cast<::FUN_004187d0_Class *>((((FUN_004187d0_Class*)pExtra)))->FUN_004187d0())
            reinterpret_cast<::fnv_0041af30::FUN_0041af30_shell *>((((FUN_0041af30_Class*)pExtra)))->FUN_0041af30();
    }
}
}  // namespace fnv_004bdd80

struct ScriptLocals;
struct ItemChangeShell : public InventoryStackRecord
{
    ScriptLocals* FUN_004bdea0();
};
struct ExtraDataList_shell2 : public ExtraDataList
{
};
// Walks the extra data list and returns the script locals from the first entry that has them, or 0 if none do.
// @fnv 0x004bdea0
ScriptLocals* ItemChangeShell::FUN_004bdea0()
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject = m_pExtraDataLists;
    ExtraDataList* pextra;
    while (pkCurrentObject && (pkCurrentObject->m_item))
    {
        pextra = (pkCurrentObject->m_item);
        if (pextra && reinterpret_cast<::FUN_00418830_shell *>((((ExtraDataList_shell2*)pextra)))->FUN_00418830())
            return reinterpret_cast<::FUN_00418830_shell *>((((ExtraDataList_shell2*)pextra)))->FUN_00418830();
        pkCurrentObject = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
    }
    return 0;
}

struct StartMenu
{
    const char* GetMenuTitle();
};
struct GlobalObject_0040c150 : public StartMenu
{
};
struct TESModel
{
};
struct TESFullName : public BaseFormComponent
{
    unsigned int GetModelLength() const;
    const char* GetFullName();
};
struct TESBoundObject : public BaseFormComponent
{
};
struct ActorPackage_004be2d0
{
    TESBoundObject* GetTarget();
};
struct FUN_004be2d0_shell
{
    const char* GetTargetFullName();
};
// @fnv 0x004be2d0
const char* FUN_004be2d0_shell::GetTargetFullName()
{
    TESFullName* fullname = dynamic_cast<TESFullName*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ActorPackage_004be2d0*>(this)))->GetName())));
    if (fullname && fullname->GetModelLength())
        return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((fullname))->FUN_00408da0()));
    return ::g_011d35b8.GetMenuTitle();
}

struct IsEmptyNode
{
    bool _ref_008256d0();
};
struct CallerNode
{
};
struct FUN_004bed00_host
{
    _DummySimpleList* first;
    int unk04;
    int unk08;
    void FUN_004bed00();
};
// Walks the linked list from first, and for each non-empty node whose extra data is non-null, calls FUN_00426020 with unk08.
// @fnv 0x004bed00
void FUN_004bed00_host::FUN_004bed00()
{
    _DummySimpleList* pNode = first;
    ExtraDataList* pExtra;
    while (pNode && !((IsEmptyNode*)pNode)->_ref_008256d0())
    {
        pExtra = *((::ExtraDataList **)((void *)(pNode)));
        if (pExtra)
        {
            reinterpret_cast<::load_extra_fixup::ThisQ *>((((CallerNode*)pExtra)))->FUN_00426020(0, 0, (::load_extra_fixup::O *)(0), (void *)(unk08));
        }
        pNode = ((::_DummySimpleList *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
}

struct IndexedPointerCollection
{
    void* FUN_004bf630(unsigned int);
};
void _Deallocate(void*);
struct FUN_004bfb30_shell
{
    unsigned int GetAtIfValid(int);
};
// Returns the element at idx from the array at offset 0xE3C when idx is between 0 and 8, otherwise 0.
// @fnv 0x004bfb30
unsigned int FUN_004bfb30_shell::GetAtIfValid(int aiIndex)
{
    return (aiIndex >= 0 && aiIndex <= 8) ? ((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 400>*)((char*)this + 0xE3C))))->FUN_006a7ad0(aiIndex)))
                                          : 0;
}

struct DAT_011c6444_type
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual ~DAT_011c6444_type();
};
// Deletes the global DAT_011c6444 object if it is non-null, then sets the pointer to null.
// @fnv 0x004c1c40
void FUN_004c1c40()
{
    if ((*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))
        delete (*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444));
    (*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)) = 0;
}

struct ScriptS
{
};
struct FUN_00474a40
{
};
struct FUN_00474a00
{
    TESForm* GetForm();
};
struct FUN_004c7300_shell : public InventoryChanges
{
    InventoryStackRecord* FindInventoryItem(TESObjectREFR* pRef, bool* pFound);
};
// @fnv 0x004c7300
InventoryStackRecord* FUN_004c7300_shell::FindInventoryItem(TESObjectREFR* pRef, bool* pFound)
{
    *pFound = false;
    if (!pRef)
        return 0;
    ScriptS* script3 = ((::ScriptS *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>((((FUN_00474a40*)((char*)pRef + 0xa4))))->FUN_00474a40()));
    InventoryStackRecord* result2 = 0;
    if (script3)
    {
        unsigned int index = 0;
        TESObject* next = ((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((script3))->FUN_007af430()));
        ScriptS* current2 = (ScriptS*)((void *)(reinterpret_cast<::BGSCameraPath *>((script3))->GetConditions()));
        while (current2 && ((char**)((void *)((void *)(current2))))[0])
        {
            InventoryStackRecord* item = (InventoryStackRecord*)((char**)((void *)((void *)(current2))))[0];
            *pFound = true;
            if (reinterpret_cast<::FUN_004c8f30_shell *>((this))->FUN_004c8f30((std::intptr_t)((TESForm*)item)) > 0)
            {
                if (index < (unsigned int)next)
                    result2 = item;
                else
                    return item;
            }
            current2 = (ScriptS*)reinterpret_cast<::Callees *>((current2))->FUN_00726070();
            index++;
        }
    }
    if (result2)
        return result2;
    TESForm* form4 = ((::TESForm *)(reinterpret_cast<::FUN_00474a00_shell *>((((FUN_00474a00*)((char*)pRef + 0xa4))))->GetAmmoForm()));
    if (form4)
    {
        *pFound = true;
        if (reinterpret_cast<::FUN_004c8f30_shell *>((this))->FUN_004c8f30((std::intptr_t)(form4)) > 0)
            return (InventoryStackRecord*)form4;
    }
    return 0;
}

struct List_009e03e0
{
    ~List_009e03e0();
};
struct Unk_004ca1a0
{
    List_009e03e0* pList;
    void DestroyList();
};
// Calls DestroyList, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x004bf630
void* IndexedPointerCollection::FUN_004bf630(unsigned int flags)
{
    reinterpret_cast<::Unk_004ca1a0 *>(this)->DestroyList();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
// If pList is set, removes all its elements, deletes it and clears the pointer.
// @fnv 0x004ca1a0
void Unk_004ca1a0::DestroyList()
{
    if (pList)
    {
        reinterpret_cast<::FileMatchList *>((pList))->RemoveAll();
        delete pList;
        pList = 0;
    }
}

struct TESRaceForm
{
};
struct TESScriptableForm : public TESForm
{
    virtual ~TESScriptableForm();
};
// @fnv 0x004ce300
void FUN_004ce300(TESForm* apForm, unsigned int uiValue)
{
    TESScriptableForm* c = dynamic_cast<TESScriptableForm*>(apForm);
    if (c)
        reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)c)))->Initialize((::CombatController *)(uiValue));
}

struct FUN_004ce340_stand
{
    void FUN_004ce340(std::intptr_t a0, std::intptr_t a1, bool a2, bool a3, bool a4, bool a5, int a6, std::intptr_t a7);
};
struct C008256d0
{
    bool _ref_008256d0();
};
struct C004bed00
{
};
struct S_004d4030
{
    ItemNode* head;
    void FUN_004d4030();
};
// @fnv 0x004d4030
void S_004d4030::FUN_004d4030()
{
    ItemNode* cur = head;
    InventoryStackRecord* item;
    while (cur && !((C008256d0*)cur)->_ref_008256d0())
    {
        item = *((::InventoryStackRecord **)((void *)(cur)));
        if (item)
            reinterpret_cast<::FUN_004bed00_host *>((((C004bed00*)item)))->FUN_004bed00();
        cur = ((::ItemNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
}

struct FUN_004bd880_stand
{
    char _pad[0x180];
    void* f180;
    void* f184;
    void* f188;
    void* GetSlotPointer(int);
};
// Returns the pointer stored at f180, f184 or f188 for slot 1, 2 or 4, otherwise returns 0.
// @fnv 0x004bd880
void* FUN_004bd880_stand::GetSlotPointer(int slot)
{
    if (slot == 1)
    {
        return f180;
    }
    else if (slot == 2)
    {
        return f184;
    }
    else if (slot == 4)
    {
        return f188;
    }
    else
    {
        return 0;
    }
}

struct VTableHelper
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195(float);
};

// @fnv 0x004bf0e0
void FUN_004bf0e0(InventoryChanges* pThis)
{
    pThis->m_fArmorWeight = pThis->m_fTotalWeight;
    pThis->m_fTotalWeight = -1.0f;
    if (pThis->pRef && ((VTableHelper*)pThis->pRef)->v064())
    {
        VTableHelper* pact = (VTableHelper*)pThis->pRef;
        pact->v195(-1.0f);
    }
}

namespace fnv_004bf150 {
struct ExtraNode;
struct FUN_004bc780_shell
{
};

struct RefVtable
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void MarkAsUnmodified(unsigned int);
};

struct FUN_004bf150_shell : public InventoryChanges
{
    void ClearInventoryChanges();
};

// Walks the extra-node list, calls ClearExtraDataList and deletes each item, then clears the list, marks the ref unmodified and frees the list.
// @fnv 0x004bf150
void FUN_004bf150_shell::ClearInventoryChanges()
{
    ExtraNode* node = (ExtraNode*)this->m_pEntryList;
    while (node && *((::InventoryStackRecord **)((void *)(node))))
    {
        InventoryStackRecord* item = *((::InventoryStackRecord **)((void *)(node)));
        node = ((::fnv_004bf150::ExtraNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        reinterpret_cast<::FUN_004bc780_shell *>((((FUN_004bc780_shell*)item)))->ClearExtraDataList();
        delete item;
    }
    reinterpret_cast<::FileMatchList *>((this->m_pEntryList))->RemoveAll();
    if (this->pRef)
        ((RefVtable*)this->pRef)->MarkAsUnmodified(0x8000020);
    delete (BSSimpleList<const char*>*)this->m_pEntryList;
}
}  // namespace fnv_004bf150

struct XIdle;
struct XArr
{
    void SetAt(unsigned int i, XIdle*& v);
};
struct FUN_004bfb70_stand
{
    char pad[0xe3c];
    XArr arr;
    void SetIdleAt(unsigned int i, XIdle* v);
};
// Stores an XIdle pointer into the array at the given index.
// @fnv 0x004bfb70
void FUN_004bfb70_stand::SetIdleAt(unsigned int uiIndex, XIdle* v)
{
    arr.SetAt(uiIndex, v);
}

struct FUN_004c0c60_Helper
{
    char pad[0xf4];
    signed char type;
    bool IsGunWeapon()
    {
        switch (type)
        {
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return true;
        default:
            return false;
        }
    }
};

// Returns true when the helper's type field is one of 3 through 9, otherwise false.
// @fnv 0x004c0c60
bool FUN_004c0c60(FUN_004c0c60_Helper* pThis)
{
    switch (pThis->type)
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return true;
    default:
        return false;
    }
}

struct FUN_004c0cd0_This
{
    char pad[0x1f0];
    void* field_1f0;
};

struct FUN_004c0cd0_Arg
{
    void* val;
};

// @fnv 0x004c0cd0
void SetField1F0(FUN_004c0cd0_This* pThis, FUN_004c0cd0_Arg aValue)
{
    pThis->field_1f0 = aValue.val;
}

void FUN_004bf0e0(InventoryChanges*);
struct SL
{
    SL();
    void* a;
    void* b;
};
struct FUN_004befb0
{
    SL* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    FUN_004befb0(TESObjectREFR* apRef);
};
// @fnv 0x004befb0
FUN_004befb0::FUN_004befb0(TESObjectREFR* apRef)
{
    AutoMemContext tempMemContext((MEM_CONTEXT)0x36, true, ::DAT_01020778, 0x6de);
    pRef = apRef;
    m_pEntryList = new SL;
    if ((*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)) == 0)
    {
        (*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)) = (DAT_011c6444_type*)new TESObjectREFR;
        ((TESForm*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))->NotifySaveLoadGameOfFormChange();
    }
    m_fTotalWeight = -1.0f;
    m_fArmorWeight = m_fTotalWeight;
    FUN_004bf0e0((InventoryChanges*)this);
    m_bChanged = false;
}

struct TESContainer;
struct FUN_004bfba0_shell
{
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, int, int);
};
struct FUN_004bffb0_shell
{
    TESContainer* FUN_004bffb0();
};
struct QEntry1
{
    int count;
    TESBoundObject* form;
};
struct QEntry2
{
    int pad;
    int count;
    TESBoundObject* form;
};
struct QNode1
{
};
struct QNode2
{
    bool _ref_008256d0();
};
struct FUN_004d0360_shell
{
    QNode2* list;
    bool FUN_004d0360();
};
// Scans the process container and the list for a quest item whose count does not cancel out, returning whether one is found.
// @fnv 0x004d0360
bool FUN_004d0360_shell::FUN_004d0360()
{
    bool found = false;
    QNode1* it =
        (QNode1*)((BaseProcess*)((FUN_004bffb0_shell*)this)->FUN_004bffb0())->BaseProcess::GetCurrentProcessData();
    while (it && *((::QEntry1 **)((void *)(it))) && !found)
    {
        QEntry1* entry = *((::QEntry1 **)((void *)(it)));
        if (((TESForm*)entry->form)->IsQuestItem())
        {
            found = true;
            QEntry2* change = (QEntry2*)((FUN_004bfba0_shell*)this)->FUN_004bfba0(entry->form, 1, 0);
            if (change && change->count + entry->count == 0)
                found = false;
        }
        it = ((::QNode1 *)(reinterpret_cast<::Callees *>((it))->FUN_00726070()));
    }
    if (!found)
    {
        QNode2* node = list;
        while (node && !node->_ref_008256d0() && !found)
        {
            QEntry2* item = *((::QEntry2 **)((void *)(node)));
            if (item && item->form && ((TESForm*)item->form)->IsQuestItem() && item->count > 0)
                found = true;
            node = ((::QNode2 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    return found;
}

namespace fnv_004d0490 {
struct TESContainer;
struct Script;
struct FUN_004bfba0_shell
{
};
struct FUN_004bffb0_shell
{
    TESContainer* FUN_004bffb0();
};
struct FUN_0057c850_cls
{
};
struct FUN_0056aac0_map
{
};
struct FUN_004d4de0
{
    int a, b, c, d;
    FUN_004d4de0(int);
    ~FUN_004d4de0();
};
struct SEntry1
{
    int count;
    TESBoundObject* form;
};
struct SEntry2
{
    int pad;
    int count;
    TESBoundObject* form;
};
struct SNode1
{
    bool _ref_008256d0();
};
struct SNode2
{
    bool _ref_008256d0();
};
struct FUN_004d0490_shell
{
    SNode2* list;
    bool FUN_004d0490();
};
// @fnv 0x004d0490
bool FUN_004d0490_shell::FUN_004d0490()
{
    bool bfound9 = false;
    FUN_004d4de0 kMapA(0x25);
    SNode1* pIterVal =
        (SNode1*)((BaseProcess*)((::fnv_004d0490::TESContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>((((FUN_004bffb0_shell*)this)))->FUN_004bffb0())))->BaseProcess::GetCurrentProcessData();
    while (pIterVal && !pIterVal->_ref_008256d0() && !bfound9)
    {
        bool seen5;
        SEntry1* entry7 = *((::fnv_004d0490::SEntry1 **)((void *)(pIterVal)));
        seen5 = false;
        if (!reinterpret_cast<::FUN_0057c850_cls *>((((FUN_0057c850_cls*)&kMapA)))->FUN_0057c850(entry7->form, &seen5))
        {
            reinterpret_cast<::FUN_0084d310_class *>((((FUN_0056aac0_map*)&kMapA)))->FUN_0084d310((std::intptr_t)(entry7->form), true);
            if (((::fnv_004d0490::Script *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(entry7->form)))))
            {
                bfound9 = true;
                SEntry2* change = (SEntry2*)reinterpret_cast<::FUN_004bfba0_shell *>((((FUN_004bfba0_shell*)this)))->FUN_004bfba0(entry7->form, 1, 0);
                if (change && change->count + entry7->count == 0)
                    bfound9 = false;
            }
        }
        pIterVal = ((::fnv_004d0490::SNode1 *)(reinterpret_cast<::Callees *>((pIterVal))->FUN_00726070()));
    }
    if (!bfound9)
    {
        SNode2* node5 = list;
        while (node5 && !node5->_ref_008256d0() && !bfound9)
        {
            SEntry2* item = *((::fnv_004d0490::SEntry2 **)((void *)(node5)));
            bool seen8 = false;
            if (item->count && !reinterpret_cast<::FUN_0057c850_cls *>((((FUN_0057c850_cls*)&kMapA)))->FUN_0057c850(item->form, &seen8))
            {
                if (((::fnv_004d0490::Script *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(item->form)))))
                    bfound9 = true;
            }
            node5 = ((::fnv_004d0490::SNode2 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
        }
    }
    return bfound9;
}
}  // namespace fnv_004d0490

struct ContainerItemExtra;
struct TESBoundObject;
struct TESForm;
struct InventoryItemEntry
{
    void Save();
    void InitItem(TESForm*);
    bool Compare(InventoryItemEntry*);
    void Copy(InventoryItemEntry*);
    void* __vecDelDtor(unsigned int);
    int m_iCountDelta;
    TESBoundObject* pObj;
    ContainerItemExtra* m_pExtraData;
};
struct FUN_004d1610_shell : public InventoryChanges
{
    void FUN_004d1610();
};

struct ContNode;
struct FUN_004bffb0_S
{
    void* FUN_004bffb0();
};
ContNode* FUN_00717e50(void*);
bool FUN_008256d0(ContNode*);
struct FUN_00410360
{
    FUN_00410360();
    char pad[0x20];
};
struct FUN_004bc550
{
    FUN_004bc550(TESBoundObject*, int);
    char pad[0xc];
};
struct FUN_00419ad0_S
{
};
struct FUN_0040ea20_S
{
};
struct FUN_005ae3d0_S
{
    void FUN_005ae3d0(ExtraDataList**);
};
struct FUN_004c3380_S
{
};

// @fnv 0x004d1610
void FUN_004d1610_shell::FUN_004d1610()
{
    ContNode* pCurrentElementNext = FUN_00717e50(((void *)(reinterpret_cast<::FUN_004bffb0_shell *>((((FUN_004bffb0_S*)this)))->FUN_004bffb0())));
    while (pCurrentElementNext && !FUN_008256d0(pCurrentElementNext))
    {
        InventoryItemEntry* pItem = *((::InventoryItemEntry **)((void *)(pCurrentElementNext)));
        pCurrentElementNext = ((::ContNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        if (pItem->pObj && _FNV_GetFormType((unsigned int)pItem->pObj) != 0x34 && pItem->m_pExtraData)
        {
            ExtraDataList* pextra = (ExtraDataList*)new FUN_00410360;
            reinterpret_cast<::FUN_00419ad0_shell *>((((FUN_00419ad0_S*)pextra)))->FUN_00419ad0(*(unsigned short*)&pItem->m_iCountDelta);
            reinterpret_cast<::Fn40ea20 *>((((FUN_0040ea20_S*)pItem->m_pExtraData)))->FUN_0040ea20((::ExtraL *)(pextra), (::HealthForm *)(void *)(((void *)(::GetHealthForm((::TESForm *)(pItem->pObj))))));
            InventoryStackRecord* pchange = (InventoryStackRecord*)new FUN_004bc550(pItem->pObj, 0);
            (*(FUN_005ae3d0_S**)pchange)->FUN_005ae3d0(&pextra);
            reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((((FUN_004c3380_S*)this)))->FUN_004c3380(pchange, true);
        }
    }
}

struct RefV_004d17a0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void MarkAsModified(unsigned int);
};
struct Extra_004d17a0
{
    virtual ~Extra_004d17a0();
    void FUN_0041d000();
};
struct ExtraNode_004d17a0
{
    bool _ref_008256d0();
};
struct ItemNode_004d17a0
{
    bool _ref_008256d0();
};
struct ItemCount_004d17a0
{
};
struct FUN_004d17a0_t
{
    ItemNode_004d17a0* m_pEntryList;
    RefV_004d17a0* pRef;
    void FUN_004d17a0();
};

// Marks pRef as modified, then walks the item list removing extra entries whose GetExtraLeveledItem is true and deleting items left with no count.
// @fnv 0x004d17a0
void FUN_004d17a0_t::FUN_004d17a0()
{
    pRef->MarkAsModified(0x8000000);
    ItemNode_004d17a0* pkNode = m_pEntryList;
    while (pkNode && !pkNode->_ref_008256d0() && *((::InventoryStackRecord **)((void *)(pkNode))))
    {
        InventoryStackRecord* pItem = *((::InventoryStackRecord **)((void *)(pkNode)));
        ExtraNode_004d17a0* pkExtraNode = (ExtraNode_004d17a0*)pItem->m_pExtraDataLists;
        while (pkExtraNode && *((::Extra_004d17a0 **)((void *)(pkExtraNode))))
        {
            Extra_004d17a0* pExtra = *((::Extra_004d17a0 **)((void *)(pkExtraNode)));
            if (pExtra)
            {
                if (((void *)(reinterpret_cast<::FUN_00418720_shell *>((pExtra))->GetExtraLeveledItem())))
                {
                    reinterpret_cast<::FUN_0041d000_shell *>((pExtra))->FUN_0041d000();
                    reinterpret_cast<::CombatProcedure *>((((ItemCount_004d17a0*)pItem)))->Initialize((::CombatController *)(std::uintptr_t)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ItemCount_004d17a0*)pItem)))->FUN_00726070())) - reinterpret_cast<::FUN_00418770_shell *>((pExtra))->FUN_00418770()));
                    reinterpret_cast<::ItemChangeListNode *>((pkExtraNode))->FUN_00905330((*(::InventoryStackRecord *const *)(&pExtra)));
                    delete pExtra;
                    pkExtraNode = (ExtraNode_004d17a0*)pItem->m_pExtraDataLists;
                }
                else
                    pkExtraNode = ((::ExtraNode_004d17a0 *)(reinterpret_cast<::Callees *>((pkExtraNode))->FUN_00726070()));
            }
            else
                pkExtraNode = ((::ExtraNode_004d17a0 *)(reinterpret_cast<::Callees *>((pkExtraNode))->FUN_00726070()));
        }
        if (pItem && pItem->m_pExtraDataLists && ((ExtraNode_004d17a0*)pItem->m_pExtraDataLists)->_ref_008256d0() &&
            !((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ItemCount_004d17a0*)pItem)))->FUN_00726070())))
        {
            reinterpret_cast<::ItemChangeListNode *>((m_pEntryList))->FUN_00905330((*(::InventoryStackRecord *const *)(&pItem)));
            delete pItem;
            pItem = 0;
            pkNode = m_pEntryList;
        }
        else
            pkNode = ((::ItemNode_004d17a0 *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
    }
}

struct FUN_00418c00_shell
{
};
struct FUN_004bd8d0_shell : public InventoryStackRecord
{
    bool FUN_004bd8d0(unsigned char, float*);
};

// Checks the item's extra data list for slot flags 1, 2 or 4 matching type, writes the slot value to result and returns true, else false.
// @fnv 0x004bd8d0
bool FUN_004bd8d0_shell::FUN_004bd8d0(unsigned char type, float* pfResult)
{
    InventoryStackRecord* item = *(InventoryStackRecord**)this;
    if (item && *(ExtraDataList**)((::ExtraDataList **)((void *)(item))))
    {
        InventoryStackRecord* extra = (InventoryStackRecord*)*((::ExtraDataList **)((void *)(item)));
        if (extra)
        {
            InventoryStackRecord* slot = *(InventoryStackRecord**)&this->m_pItemObject;
            if (reinterpret_cast<::C418C00ExtraList *>((((FUN_00418c00_shell*)extra)))->CheckExtraByType(1) &&
                (int)((FUN_004bd880_stand*)slot)->GetSlotPointer(1) == type)
            {
                *pfResult = ((FUN_004bd9d0_shell*)slot)->FUN_004bd9d0(1, 0);
                return true;
            }
            if (reinterpret_cast<::C418C00ExtraList *>((((FUN_00418c00_shell*)extra)))->CheckExtraByType(2) &&
                (int)((FUN_004bd880_stand*)slot)->GetSlotPointer(2) == type)
            {
                *pfResult = ((FUN_004bd9d0_shell*)slot)->FUN_004bd9d0(2, 0);
                return true;
            }
            if (reinterpret_cast<::C418C00ExtraList *>((((FUN_00418c00_shell*)extra)))->CheckExtraByType(4) &&
                (int)((FUN_004bd880_stand*)slot)->GetSlotPointer(4) == type)
            {
                *pfResult = ((FUN_004bd9d0_shell*)slot)->FUN_004bd9d0(4, 0);
                return true;
            }
        }
    }
    return false;
}

struct TESNPC
{
    int GetSex();
};
struct FUN_00481230_stand
{
    const char* FUN_00481230(int);
};
struct TESTextureLoader
{
};
struct ItemChange_004be200 : public FUN_004bd740_stand
{
    const char* GetIconFilename(TESObjectREFR* apRef);
};
// Returns the biped model icon for the owner NPC's sex, falling back to the texture loader icon or a default.
// @fnv 0x004be200
const char* ItemChange_004be200::GetIconFilename(TESObjectREFR* apRef)
{
    const char* piconFilename = 0;
    TESForm* powner = GetExtraForm();
    TESBipedModelForm* pbipedModel = dynamic_cast<TESBipedModelForm*>((TESBoundObject*)*(void**)((char*)this + 8));
    if (powner && pbipedModel)
    {
        TESNPC* pownerNPC = dynamic_cast<TESNPC*>(powner);
        if (pownerNPC)
            piconFilename = ((FUN_00481230_stand*)pbipedModel)->FUN_00481230(pownerNPC->GetSex());
    }
    if (!piconFilename || !piconFilename[0])
        piconFilename =
            ::FUN_0048e730((TESForm*)(TESBoundObject*)*(void**)((char*)this + 8), (std::intptr_t)(apRef));
    if (!piconFilename || !piconFilename[0])
        return ::g_011d33f0.GetMenuTitle();
    return piconFilename;
}

namespace fnv_004bee00 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct FUN_004bee00_shell : public InventoryStackRecord
{
    void FUN_004bee00(BGSLoadFormBuffer*);
};

struct SoundListView
{
};
struct FUN_00428150_stand
{
};

// @fnv 0x004bee00
void FUN_004bee00_shell::FUN_004bee00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned int iExtraDataCount;
    this->m_pItemObject =
        dynamic_cast<TESBoundObject*>((::TESForm*)((::fnv_004bee00::TESForm *)(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()))));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_iCountChange)), 4);
    ((FUN_004bc780_shell*)this)->ClearExtraDataList();
    iExtraDataCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
    if (iExtraDataCount)
    {
        if (!*(SL**)this)
            *(SL**)this = new SL;
        for (unsigned int iIndex = 0; iIndex < iExtraDataCount; iIndex++)
        {
            ExtraDataList* pextraDataList = (ExtraDataList*)new FUN_00410360;
            reinterpret_cast<::ExtraDataLoader *>((((FUN_00428150_stand*)pextraDataList)))->FUN_00428150((::LoadBuffer *)(apLoadGameBuffer));
            reinterpret_cast<::Callees *>(((*(SoundListView**)this)))->FUN_00905820((void *)&(reinterpret_cast<char* const&>(pextraDataList)));
        }
    }
}
}  // namespace fnv_004bee00

struct MagicTargetDispel : MagicTarget
{
};
struct ActorDispelView : MobileObject, MagicCaster, MagicTargetDispel
{
};
struct FUN_004bfe50_inode
{
};
struct FUN_004bfe50_enode
{
};
struct FUN_004bddd0_t
{
};
struct FUN_004c0cf0_t
{
};
struct FUN_004bfe50_t : InventoryChanges
{
    void RemoveWornItems(bool abSkipCanNotWear, TESObjectREFR* apRef);
};

int FNV_GetFormType(TESForm*);

struct TESContainer
{
    bool HasObjectOfType(TESObject*);
    int GetObjectCount(TESObject*);
};
struct FUN_00480d90_shell : public TESBipedModelForm
{
    bool FUN_00480d90();
};
struct FUN_004bc8f0_shell : public InventoryStackRecord
{
};
struct FUN_00726070_shell : public InventoryStackRecord
{
};
struct Flt
{
    operator unsigned int() const;
};
struct TESBipedModelFormEx
{
};
struct TESLevItem : public TESBoundObject
{
};

struct FUN_004c8fd0_t : public InventoryChanges
{
    int FUN_004c8fd0(bool);
};

// Counts inventory items, optionally skipping non-playable forms, and removes entries whose count is negative.
// @fnv 0x004c8fd0
int FUN_004c8fd0_t::FUN_004c8fd0(bool abcountplayable)
{
    int icount = 0;
    bool bHasResultObj;
    BSSimpleList<InventoryStackRecord*>* pkCurrentObject;
    int itempcount;
    if (((FUN_004bffb0_shell*)this)->FUN_004bffb0())
    {
        BSSimpleList<InventoryItemEntry*>* pCurrentElementNext =
            (BSSimpleList<InventoryItemEntry*>*)FUN_00717e50(((FUN_004bffb0_shell*)this)->FUN_004bffb0());
        while (pCurrentElementNext && (pCurrentElementNext->m_item))
        {
            InventoryItemEntry* pobject = (pCurrentElementNext->m_item);
            TESLevItem* pObj = dynamic_cast<TESLevItem*>(pobject->pObj);
            TESBipedModelForm* pbipedForm = 0;
            int ioriginalcount = ((FUN_004bffb0_shell*)this)->FUN_004bffb0()->GetObjectCount((TESObject*)pobject->pObj);
            if (!abcountplayable)
            {
                switch (FNV_GetFormType((TESForm*)pobject->pObj))
                {
                case 41:
                    if (!((bool)(reinterpret_cast<::FUN_004c94d0_shell *>(((TESForm*)pobject->pObj))->GetFlag())))
                        pobject = 0;
                    break;
                case 40:
                    if (!reinterpret_cast<::FUN_0047bcf0_class *>(((TESForm*)pobject->pObj))->IsFlag80Clear())
                        pobject = 0;
                    break;
                default:
                    pbipedForm = ::TESBipedModelForm::GetFormAsBipedModel((TESForm*)pobject->pObj);
                    if (pbipedForm && !((FUN_00480d90_shell*)pbipedForm)->FUN_00480d90())
                        pobject = 0;
                    break;
                }
            }
            if (pobject && !pObj)
            {
                InventoryStackRecord* pitem = ((FUN_004bfba0_shell*)this)->FUN_004bfba0(pobject->pObj, true, false);
                int iAbsCount = ioriginalcount;
                if (iAbsCount < 0)
                    iAbsCount *= -1;
                if (pitem && pitem->m_iCountChange + iAbsCount > 0 &&
                    (ioriginalcount >= 0 || !pitem || ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)pitem)))->FUN_00726070())) > ioriginalcount))
                {
                    if (pitem->m_pExtraDataLists && (pitem->m_pExtraDataLists->m_item))
                    {
                        icount += ((FUN_004bca80_shell*)pitem)->CountAndPruneEntries();
                        if (pitem->HasApplicablePerkEntry())
                            icount++;
                        if (reinterpret_cast<::FUN_004bc8f0_stand *>((((FUN_004bc8f0_shell*)pitem)))->FUN_004bc8f0(false) <
                                ioriginalcount + pitem->m_iCountChange &&
                            (pitem->m_pExtraDataLists->m_item) && !((FUN_004bddd0_shell*)pitem)->FUN_004bddd0(false) &&
                            !(pitem->m_pExtraDataLists->m_item)->HasExtraDataType0x2F())
                            icount++;
                    }
                    else
                    {
                        icount++;
                    }
                }
                else if (!pitem)
                {
                    icount++;
                }
            }
            pCurrentElementNext = ((::BSSimpleList< ::InventoryItemEntry *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        }
    }
    pkCurrentObject = *(BSSimpleList<InventoryStackRecord*>**)this;
    itempcount = icount;
    bHasResultObj = true;
    while (pkCurrentObject && (pkCurrentObject->m_item))
    {
        InventoryStackRecord* pitem = (pkCurrentObject->m_item);
        bHasResultObj = true;
        bool bcontinue = true;
        if (pitem)
        {
            if ((unsigned int)*(const Flt*)pitem &&
                ((((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem))->m_item) &&
                ((((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem))->m_item)->HasExtraDataType0x2F())
                bcontinue = true;
            else if (((FUN_004bffb0_shell*)this)->FUN_004bffb0() &&
                     ((FUN_004bffb0_shell*)this)->FUN_004bffb0()->HasObjectOfType((TESObject*)pitem->m_pItemObject))
                bcontinue = false;
            TESBipedModelForm* pbipedForm = 0;
            if (!abcountplayable)
            {
                switch (FNV_GetFormType((TESForm*)((reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pitem)))->GetName()))))
                {
                case 41:
                    if (!((bool)(reinterpret_cast<::FUN_004c94d0_shell *>(((TESForm*)((reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pitem)))->GetName()))))->GetFlag())))
                        bcontinue = false;
                    break;
                case 40:
                    if (!reinterpret_cast<::FUN_0047bcf0_class *>(((TESForm*)((reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pitem)))->GetName()))))->IsFlag80Clear())
                        bcontinue = false;
                    break;
                default:
                    pbipedForm = ::TESBipedModelForm::GetFormAsBipedModel((TESForm*)((reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pitem)))->GetName())));
                    if (pbipedForm)
                        bcontinue = ((FUN_00480d90_shell*)pbipedForm)->FUN_00480d90();
                    break;
                }
            }
        }
        if (pitem && pitem->m_iCountChange > 0 && bcontinue)
        {
            icount += ((FUN_004bca80_shell*)pitem)->CountAndPruneEntries();
            if (pitem->HasApplicablePerkEntry())
                icount++;
            if (reinterpret_cast<::FUN_004bc8f0_stand *>((((FUN_004bc8f0_shell*)pitem)))->FUN_004bc8f0(false) < pitem->m_iCountChange)
                icount++;
            if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)pitem)))->FUN_00726070())) < 0 &&
                !((unsigned int)*(const Flt*)pitem &&
                  ((((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem))->m_item) &&
                  ((((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem))->m_item)->HasExtraDataType0x2F()))
            {
                reinterpret_cast<::ItemChangeListNode *>(((*(BSSimpleList<InventoryStackRecord*>**)this)))->FUN_00905330(pitem);
                ((FUN_004bc780_shell*)pitem)->ClearExtraDataList();
                delete pitem;
                icount = itempcount;
                pkCurrentObject = *(BSSimpleList<InventoryStackRecord*>**)this;
                if (pkCurrentObject && (pkCurrentObject->m_item))
                    pitem = (pkCurrentObject->m_item);
                else
                    pitem = 0;
                bHasResultObj = false;
            }
        }
        if (bHasResultObj)
            pkCurrentObject = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
    }
    return icount + 1;
}

struct ContEntry4cfe20
{
    int count;
    ::TESBoundObject* pObj;
};
struct ContNode4cfe20
{
    bool _ref_008256d0();
};
struct Container4cfe20
{
    ContNode4cfe20* FUN_00717e50();
};
struct ChangeCount4cfe20
{
};
struct ExtraNode4cfe20
{
};
struct ChangeNode4cfe20
{
    bool _ref_008256d0();
};
struct ExtraRef4cfe20
{
};

struct FUN_004cfe20_t : public ::InventoryChanges
{
    Container4cfe20* FUN_004bffb0();
    bool HasItem(std::uintptr_t aId);
};

struct FUN_00419d10
{
    void SetExtra(void*);
};

struct FUN_004bdd20_Stand
{
    void SetPerkExtra(void* apExtra);
};

// If the perk list's first perk exists and its check returns false, calls SetExtra on that perk with apExtra.
// @fnv 0x004bdd20
void FUN_004bdd20_Stand::SetPerkExtra(void* apExtra)
{
    BSSimpleList<BGSPerk*>* pk = reinterpret_cast<BSSimpleList<BGSPerk*>*>(*reinterpret_cast<void**>(this));
    if (pk && (pk->m_item))
    {
        BGSPerk* item = (pk->m_item);
        if (item)
        {
            if (!reinterpret_cast<FUN_004187d0_Class*>(item)->FUN_004187d0())
                reinterpret_cast<FUN_00419d10*>(item)->SetExtra(apExtra);
        }
    }
}

struct SaveFormIDHelper
{
};
struct BGSSaveFormBuffer
{
};
struct FUN_00426a30_shell
{
};
struct FUN_004bed60_shell
{
    BSSimpleList<BGSPerk*>* list;
    int pad0;
    int pad1;
    void SavePerkList(BGSSaveFormBuffer* buffer);
};

// @fnv 0x004bed60
void FUN_004bed60_shell::SavePerkList(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((SaveFormIDHelper*)buffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(void *)((void*)pad1), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)&this->pad0, 4, 0);
    unsigned int count = 0;
    unsigned int total = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    BSSimpleList<BGSPerk*>* node = list;
    while (node)
    {
        BGSPerk* perk = (node->m_item);
        if (perk)
        {
            reinterpret_cast<::fnv_00426a30::Owner *>((((FUN_00426a30_shell*)perk)))->WriteNodeList((::fnv_00426a30::BufObj *)(buffer));
            ++count;
        }
        node = ((::BSSimpleList< ::BGSPerk *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0((int)count, total);
}

struct SpawnedEntry
{
    unsigned int unk00;
    unsigned int unk04;
    SpawnedEntry();
};

struct FUN_004bc810_cls
{
    SpawnedEntry* m_afEntries;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0C;
    void FUN_004bc810(FUN_004bc810_cls* src);
};

// @fnv 0x004bc810
void FUN_004bc810_cls::FUN_004bc810(FUN_004bc810_cls* apSource)
{
    if (apSource != 0)
    {
        this->m_08 = apSource->m_08;
        this->m_afEntries = new SpawnedEntry();
        SpawnedEntry* head7;
        ContNode* cur;
        head7 = apSource->m_afEntries;
        cur = ((::ContNode *)(::FUN_00559450((int *)(apSource))));
        goto check;
    advance:
        cur = ((::ContNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    check:
        if (cur != 0)
        {
            if (*((::InventoryItemEntry **)((void *)(cur))) != 0)
            {
                reinterpret_cast<FUN_005ae3d0_S*>(((::ContNode *)(::FUN_00559450((int *)(this)))))
                    ->FUN_005ae3d0(reinterpret_cast<ExtraDataList**>(((::InventoryItemEntry **)((void *)(cur)))));
                goto advance;
            }
        }
    end:;
    }
}

struct FUN_004bd7a0_stand
{
    int FindFirstNonNegativeValue();
};

struct FUN_0042de90_obj
{
};

// Walks a node list, returning the first non-negative value from GetExtraByteValue, or -1 if none is found.
// @fnv 0x004bd7a0
int FUN_004bd7a0_stand::FindFirstNonNegativeValue()
{
    int result = -1;
    for (ExtraNode* cur = ((::ExtraNode *)(::FUN_00559450((int *)this))); result < 0 && cur != 0 && *((::ExtraDataList **)((void *)(cur))) != 0; cur = ((::ExtraNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if (((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((((FUN_0042de90_obj*)*((::ExtraDataList **)((void *)(cur))))))->GetExtraByteValue())) >= 0)
        {
            result = ((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((((FUN_0042de90_obj*)*((::ExtraDataList **)((void *)(cur))))))->GetExtraByteValue()));
        }
    }
    return result;
}

class B4BDF00Form
{
  public:
    int GetFormType();
};


class B4BDF00Data;


class B4BDF00Data
{
  public:
    float GetScaledValue(void* pvActor, float fValue, bool bFlag);

    int unk00;
    int unk04;
    B4BDF00Form* m_pkForm;
};

struct BookForm
{
    unsigned int FUN_00401170();
};
struct ItemChangeCalc
{
    int unknown00;
    int unknown04;
    BookForm* item;
    void UpdateItemChange(int unused);
};
struct NewExtraList
{
    virtual ~NewExtraList();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NewExtraList();
};
struct ExtraListFlagger
{
};
struct ExtraListDeleter
{
    virtual ~ExtraListDeleter();
};

struct ItemChange_004be3d0 : public InventoryStackRecord
{
    void SetExtraListFlag(bool abNew, bool abFlag, bool abDelete);
};

// Adds a new extra data list with flag bits set, or removes the matching list entry and optionally deletes it.
// @fnv 0x004be3d0
void ItemChange_004be3d0::SetExtraListFlag(bool abNew, bool abFlag, bool abDelete)
{
    if (abNew)
    {
        ExtraDataList* pNewList = (ExtraDataList*)new NewExtraList;
        reinterpret_cast<::FUN_0041aa20_shell *>((((ExtraListFlagger*)pNewList)))->SetWornState(1, abFlag);
        if (!m_pExtraDataLists)
        {
            m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
        }
        m_pExtraDataLists->AddHead(pNewList);
    }
    else if (((FUN_004bddd0_shell*)this)->FUN_004bddd0(abFlag))
    {
        BSSimpleList<ExtraDataList*>* pIter = m_pExtraDataLists;
        while (pIter && (pIter->m_item))
        {
            ExtraDataList* pExtra = (pIter->m_item);
            if (pExtra && reinterpret_cast<::FUN_00418ab0_shell *>((((ExtraDataList_shell*)pExtra)))->FUN_00418ab0(abFlag))
            {
                reinterpret_cast<::ItemChangeListNode *>((pIter))->FUN_00905330((::InventoryStackRecord *const &)(pExtra));
                if (abDelete)
                {
                    delete (ExtraListDeleter*)pExtra;
                }
                break;
            }
            pIter = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
}

struct RefBase_4bf330
{
};

struct Extra_4bf330
{
};

struct ExtraList_4bf330
{
    Extra_4bf330* item;
    ExtraList_4bf330* next;
    ~ExtraList_4bf330();
    bool IsEmpty();
};

struct Change_4bf330
{
    ExtraList_4bf330* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    ~Change_4bf330();
};

struct ChangeList_4bf330
{
};

struct Inv_4bf330
{
    ChangeList_4bf330* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    void ClearExtraForSlot(RefBase_4bf330* apRef, int aiSlot);
};

// @fnv 0x004bf330
void Inv_4bf330::ClearExtraForSlot(RefBase_4bf330* apRef, int aiSlot)
{
    Change_4bf330* pChange = ((::Change_4bf330 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((apRef))->GetName())), 1, 0)));
    if (pChange)
    {
        ExtraList_4bf330* pNode = pChange->m_pExtraDataLists;
        while (pNode)
        {
            Extra_4bf330* pExtra = ((::Extra_4bf330 *)((void *)(pNode)));
            if (pExtra && ((aiSlot != -1 && ((char)(reinterpret_cast<::FUN_0042de90_cls *>((pExtra))->GetExtraByteValue())) == aiSlot) ||
                           (aiSlot == -1 && ((char)(reinterpret_cast<::FUN_0042de90_cls *>((pExtra))->GetExtraByteValue())) >= 0)))
            {
                reinterpret_cast<::FUN_0042dec0_shell *>((pExtra))->FUN_0042dec0();
                if (reinterpret_cast<::ExtraDataList *>((pExtra))->IsEmpty() || (reinterpret_cast<::FUN_00418770_shell *>((pExtra))->FUN_00418770() > 1 && ((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((pExtra))->FUN_0040fe20())) == 1))
                {
                    reinterpret_cast<::ItemChangeListNode *>((pChange->m_pExtraDataLists))->FUN_00905330((::InventoryStackRecord *const &)(pExtra));
                    pNode = pChange->m_pExtraDataLists;
                }
                else
                {
                    pNode = ((::ExtraList_4bf330 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                }
            }
            else
            {
                pNode = ((::ExtraList_4bf330 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
            }
        }
        if (pChange->m_pExtraDataLists && pChange->m_pExtraDataLists->IsEmpty())
        {
            delete pChange->m_pExtraDataLists;
            pChange->m_pExtraDataLists = 0;
            if (!((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())))
            {
                reinterpret_cast<::ItemChangeListNode *>((m_pEntryList))->FUN_00905330((::InventoryStackRecord *const &)(pChange));
                delete pChange;
            }
        }
    }
}


struct InventoryIterator
{
    ~InventoryIterator();
};

struct ExtraListTyped
{
};

struct ExtraListNode
{
};

struct ItemChangeLists : public InventoryStackRecord
{
};

struct InventoryChangesIter : public InventoryChanges
{
    InventoryStackRecord* FindEntryWithExtraListType(int aiType);
};

struct TESForm;
struct TESBoundObject;
int FNV_GetFormType(TESForm*);

struct ContEntry4c6ba0
{
    int count;
    TESBoundObject* pObj;
};
struct ContNode4c6ba0
{
};
struct Container4c6ba0
{
    ContNode4c6ba0* FUN_00717e50();
};
struct Change4c6ba0
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
};
struct ChangeNode4c6ba0
{
};
struct Inv4c6ba0
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0* FUN_004bffb0();
    TESBoundObject* FindFirstItemOfType(int aType, int* apCount);
};

// @fnv 0x004c6ba0
TESBoundObject* Inv4c6ba0::FindFirstItemOfType(int aType, int* apCount)
{
    ContNode4c6ba0* pNode = ((::Container4c6ba0 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    Change4c6ba0* pChange;
    TESBoundObject* pForm = 0;
    ChangeNode4c6ba0* pChangeNode4;

    while (pNode && !pForm && *((::ContEntry4c6ba0 **)((void *)(pNode))))
    {
        pForm = (*((::ContEntry4c6ba0 **)((void *)(pNode))))->pObj;
        if (pForm && FNV_GetFormType((TESForm*)pForm) == aType)
        {
            pChange = ((::Change4c6ba0 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(pForm, 1, 0)));
            if (!pChange || (pChange && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + (*((::ContEntry4c6ba0 **)((void *)(pNode))))->count))
            {
                if (pChange)
                    *apCount = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + (*((::ContEntry4c6ba0 **)((void *)(pNode))))->count;
                else
                    *apCount = (*((::ContEntry4c6ba0 **)((void *)(pNode))))->count;
            }
        }
        else
        {
            pForm = 0;
        }
        pNode = ((::ContNode4c6ba0 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }

    pChangeNode4 = m_pEntryList;
    while (pChangeNode4 && !pForm && *((::Change4c6ba0 **)((void *)(pChangeNode4))))
    {
        pForm = (*((::Change4c6ba0 **)((void *)(pChangeNode4))))->m_pItemObject;
        if (pForm && FNV_GetFormType((TESForm*)pForm) == aType)
        {
            if (!reinterpret_cast<::TESContainer *>((((::Container4c6ba0 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(pForm)))
            {
                if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::Change4c6ba0 **)((void *)(pChangeNode4))))))->FUN_00726070())) > 0)
                    *apCount = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::Change4c6ba0 **)((void *)(pChangeNode4))))))->FUN_00726070()));
            }
        }
        else
        {
            pForm = 0;
        }
        pChangeNode4 = ((::ChangeNode4c6ba0 *)(reinterpret_cast<::Callees *>((pChangeNode4))->FUN_00726070()));
    }
    return pForm;
}


class FUN_004c6d40_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
    float m_0c;

    void ResetAndProcess(int a1, unsigned char a2, int a3);
};

struct NiPoint3_ext : NiPoint3
{
    NiPoint3_ext();
};
struct NiPoint3b : NiPoint3
{
    NiPoint3b(float, float, float);
};
struct NiMatrix3Helper
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    NiPoint3 _ref_004b4500(const NiPoint3&);
};
struct PlacedRef : TESObjectREFR
{
};
struct PlacedExtra
{
};
struct DataHandler
{
};
struct Placement
{
    PlacedRef* PlaceObject(PlacedRef*, void*, int, int, NiPoint3*, NiPoint3*);
};
// @fnv 0x004c6dd0
PlacedRef* Placement::PlaceObject(PlacedRef* ref, void* object, int count, int flags, NiPoint3* location,
                                  NiPoint3* rotation)
{
    NiPoint3_ext position;
    if (location)
    {
        position.x = location->x;
        position.y = location->y;
        position.z = location->z;
    }
    else
    {
        static_cast<NiPoint3&>(position) = *ref->GetPos();
        NiPoint3 angle = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(ref))->GetData()));
        NiMatrix3Helper matrix2;
        reinterpret_cast<::Matrix161 *>(&(matrix2))->FUN_00a59540(angle.x, angle.y, angle.z);
        NiPoint3b offset(0.0f, 50.0f, 30.0f);
        reinterpret_cast<::FUN_0063c8a0_shell *>(&(position))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(matrix2._ref_004b4500(offset)));
    }
    NiPoint3 orient3 = rotation ? *rotation : (ref ? (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(ref))->GetData())) : NiPoint3::ZERO);
    PlacedRef* result3 = ((::PlacedRef *)(reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->PlaceObjectReference((::TESBoundObject *)(object), (::NiPoint3 *)&(position), (::NiPoint3 *)&(orient3), ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())),
                                                      (::TESWorldSpace *)(void *)(((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((ref))->FUN_00575d70()))), {}, {}, {})));
    if (count > 1)
        reinterpret_cast<::FUN_00419ad0_shell *>((reinterpret_cast<PlacedExtra*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((result3))->FUN_005d43c0())))))->FUN_00419ad0((unsigned short)count);
    result3->MarkAsModified(0x400);
    return result3;
}

struct Weapon;
struct Extra;
struct Item;
struct ItemList;
struct BaseNode;
struct ActorStand;
struct Stats
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float vc(int);
};
struct ProcessStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual bool v388();
};
struct ActorStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool v100();
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    Stats stats;
};
struct Form
{
    int FUN_00401170();
};
struct ValueComp
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual unsigned short v10();
};
struct AmmoComp
{
    virtual void v0();
    virtual void v4();
    virtual float v8(int);
};
struct Ammo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    AmmoComp damage;
};
struct AmmoLink
{
    int unk00, unk04;
};
struct Weapon : Form
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    AmmoLink ammo;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    ValueComp value;
    int FUN_00446390();
};
struct Extra
{
    bool FUN_00418b10();
};
struct FUN_0096a2d0
{
    Extra* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(Extra**);
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
struct FUN_0076b630 : FUN_004459e0
{
    FUN_0096a2d0* extras;
    int count;
    Weapon* weapon;
    FUN_0076b630();
    float FUN_004bd350();
};
struct ItemList
{
    FUN_0076b630* item;
    ItemList* next;
    bool FUN_008256d0();
};
struct BaseItem
{
    int count;
    Weapon* form;
};
struct BaseNode
{
    BaseItem* item;
    BaseNode* next;
};
struct Container
{
    BaseNode* FUN_00717e50();
};
struct Target
{
    ItemList* changes;
    ActorStand* owner;
    Container* FUN_004bffb0();
    FUN_0076b630* FUN_004c8c10(int, int);
    FUN_0076b630* SelectBestWeapon(ActorStand*, float*, int, bool);
};
struct ContainerView
{
};
struct Product
{
    unsigned int unk00, unk04, unk08, unk0c;
    ContainerView* container;
    unsigned int unk14, unk18, unk1c, unk20, unk24;
    Product();
};
struct OwnerProduct
{
    ContainerView* FUN_004bffb0();
    Product* FUN_004ca200();
};
// @fnv 0x004ca200
Product* OwnerProduct::FUN_004ca200()
{
    AutoMemContext result((MEM_CONTEXT)0x36, true, DAT_01020778, 0x19b2);
    Product* context = new Product;
    context->unk00 = 0;
    context->unk04 = 0;
    if (((::ContainerView *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())))
        context->unk00 = ((unsigned int)(reinterpret_cast<::Source08 *>((((::ContainerView *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->CopyUniqueObjects()));
    context->unk08 = 0;
    context->unk0c = 0;
    context->container = ((::ContainerView *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()));
    context->unk04 = context->unk00;
    context->unk18 = 0;
    context->unk1c = 0;
    context->unk24 = 0;
    context->unk20 = 0;
    return context;
}

namespace fnv_004cba70 {
struct ContainerEntry
{
    int count;
    TESBoundObject* object;
};
struct ContainerNode
{
    bool _ref_008256d0();
};
struct Container
{
    ContainerNode* FUN_00717e50();
};
struct Extra
{
};
struct ExtraNode
{
};
struct Change
{
    ExtraNode* extras;
};
struct ChangeNode
{
    bool _ref_008256d0();
};
struct Changes
{
    ChangeNode* list;
    Container* FUN_004bffb0();
    int FUN_004cba70(TESLevItem* object);
};
// @fnv 0x004cba70
int Changes::FUN_004cba70(TESLevItem* pLeveledItem)
{
    int result = 0;
    if (pLeveledItem)
    {
        ContainerNode* node = ((::fnv_004cba70::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
        int index = 0;
        while (node && !node->_ref_008256d0())
        {
            TESLevItem* leveled = dynamic_cast<TESLevItem*>((*((::fnv_004cba70::ContainerEntry **)((void *)(node))))->object);
            if (leveled && leveled == pLeveledItem)
            {
                break;
            }
            else if (leveled)
            {
                index++;
            }
            node = ((::fnv_004cba70::ContainerNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        ChangeNode* changeNode = list;
        while (changeNode && !changeNode->_ref_008256d0() && *((::fnv_004cba70::Change **)((void *)(changeNode))))
        {
            Change* change = *((::fnv_004cba70::Change **)((void *)(changeNode)));
            if (change)
            {
                ExtraNode* extraNode = change->extras;
                while (extraNode && *((::fnv_004cba70::Extra **)((void *)(extraNode))))
                {
                    Extra* extra = *((::fnv_004cba70::Extra **)((void *)(extraNode)));
                    if (extra && reinterpret_cast<::FUN_0041d360_shell *>((extra))->FUN_0041d360() == index)
                    {
                        result = ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((change))->GetName()));
                        break;
                    }
                    extraNode = ((::fnv_004cba70::ExtraNode *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070()));
                }
            }
            changeNode = ((::fnv_004cba70::ChangeNode *)(reinterpret_cast<::Callees *>((changeNode))->FUN_00726070()));
        }
    }
    return result;
}
}  // namespace fnv_004cba70

extern char DAT_01183128[];

bool FUN_004d1360(char*);
int __cdecl FUN_00ec43fb(void*, int, const char*, const char*, int);

struct ObjectForm
{
    int FUN_00401170();
};
struct InventoryEntry
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    ObjectForm* m_pItemObject;
};
struct InventoryNode
{
    bool FUN_008256d0();
};
struct ActorProcessView
{
};
struct InventoryListView
{
    InventoryNode* first;
    float GetInventoryWeight(ActorProcessView*);
};

// Sums count times weight for each inventory node's entry, using form type 0x28/0x18 special cases and the actor's equipped ammo, skipping type 0x29.
// @fnv 0x004d1180
float InventoryListView::GetInventoryWeight(ActorProcessView* actor)
{
    float total = 0.0f;
    float weightModifier = 0.0f;
    InventoryNode* node = first;
    while (node && !node->FUN_008256d0() && *((::InventoryEntry **)((void *)(node))))
    {
        InventoryEntry* item = *((::InventoryEntry **)((void *)(node)));
        ObjectForm* form = item->m_pItemObject;
        if (reinterpret_cast<::FUN_004bddd0_shell *>((item))->FUN_004bddd0(false) && form->FUN_00401170() != 0x29)
        {
            if (form->FUN_00401170() == 0x28)
            {
                weightModifier = reinterpret_cast<::TESObjectWEAP *>((form))->GetWeightForForm(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((item))->HasEffect(4))));
                if (weightModifier >= DAT_01020758)
                {
                    float factor = 1.0f;
                    ::ApplyPerkModifiers(0x49, (::Actor *)((*reinterpret_cast<char * *>(&::_g_thePlayer))), &factor);
                    weightModifier *= factor;
                }
            }
            else
            {
                weightModifier = ::TESWeightForm::GetWeightForForm((::TESForm *)(form), FUN_004d1360((*reinterpret_cast<char * *>(&::_g_thePlayer))));
            }
            int count = reinterpret_cast<::FUN_004c8f30_shell *>(this)->FUN_004c8f30(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName())));
            if (form->FUN_00401170() == 0x18)
            {
                int evaluated = FUN_00ec43fb(form, 0, DAT_01183128, DAT_01183a34, 0);
            }
            else if (form->FUN_00401170() == 0x28)
            {
                BaseProcess* process = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()));
                if (process)
                {
                    InventoryStackRecord* weapon = process->GetActiveWeapon();
                    InventoryStackRecord* pSecondAmmo = process->GetCurrentAmmo();
                    if (weapon && pSecondAmmo &&
                        ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<InventoryEntry*>(weapon)))->GetName())) ==
                            ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<InventoryEntry*>(pSecondAmmo)))->GetName())))
                    {
                        count = 1;
                    }
                }
            }
            total += static_cast<float>(count) * weightModifier;
        }
        node = ((::InventoryNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return total;
}

namespace fnv_004d42f0 {
struct FUN_008c71b0
{
    int bits;
    FUN_008c71b0(int value);
};
struct InventoryStream
{
    virtual void v0();
    virtual int getInitialSetting();
    void FUN_00428110(int*);
    void FUN_0042ce30(int*);
};
struct InventoryItem
{
};
struct InventoryNode
{
};
struct InventoryItemManager
{
    InventoryNode* entries;
    void FUN_004d42f0(InventoryStream*);
};
// @fnv 0x004d42f0
void InventoryItemManager::FUN_004d42f0(InventoryStream* stream)
{
    int savedInitial = stream->getInitialSetting();
    int savedFlags;
    {
        int savedExtra;
        stream->FUN_00428110(&savedFlags);
        stream->FUN_0042ce30(&savedExtra);
        reinterpret_cast<::TESRecipe *>((stream))->SetRequiredSkill((::ActorValue::Index)(0));
        reinterpret_cast<::FUN_00428130_Class *>((stream))->SetValue((*(int *)&(const ::fnv_004d42f0::FUN_008c71b0 &)(0x400)));
        reinterpret_cast<::Twin_0086cf00 *>((stream))->SetD3DPixelShader((*(::GeometryRelatedType *const *)&(const ::fnv_004d42f0::FUN_008c71b0 &)(0)));
        InventoryNode* node = entries;
        while (node)
        {
            InventoryItem* item = *((::fnv_004d42f0::InventoryItem **)((void *)(node)));
            if (item)
                reinterpret_cast<::InventoryStackRecord *>((item))->InitLoadGame((::BGSLoadFormBuffer *)(stream));
            node = ((::fnv_004d42f0::InventoryNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        reinterpret_cast<::TESRecipe *>((stream))->SetRequiredSkill((::ActorValue::Index)(savedInitial));
        reinterpret_cast<::FUN_00428130_Class *>((stream))->SetValue((*(int *)&(const ::fnv_004d42f0::FUN_008c71b0 &)(*reinterpret_cast<FUN_008c71b0*>(&savedFlags))));
        reinterpret_cast<::Twin_0086cf00 *>((stream))->SetD3DPixelShader((*(::GeometryRelatedType *const *)&(const ::fnv_004d42f0::FUN_008c71b0 &)(*reinterpret_cast<FUN_008c71b0*>(&savedExtra))));
    }
}
}  // namespace fnv_004d42f0

struct FUN_004d43c0_cls
{
    ContNode* m_pFirstNode;
    int FindItemIndex(int a1, InventoryItemEntry* a2);
};


// Searches the list for an item whose FUN_0044ddc0 value equals a1, then returns the position of a2 in that item's sublist, or -1.
// @fnv 0x004d43c0
int FUN_004d43c0_cls::FindItemIndex(int a1, InventoryItemEntry* pTargetItem)
{
    if (a1 == 0 || pTargetItem == 0)
    {
        return -1;
    }
    ContNode* node7 = m_pFirstNode;
    while (node7 != 0)
    {
        InventoryItemEntry* itemTmp = *((::InventoryItemEntry **)((void *)(node7)));
        node7 = ((::ContNode *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        if (itemTmp != 0 && ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((itemTmp))->GetName())) == a1)
        {
            ContNode* inner6;
            int count2 = 0;
            inner6 = ((::ContNode *)(::FUN_00559450((int *)(itemTmp))));
            while (inner6 != 0)
            {
                InventoryItemEntry* cur = *((::InventoryItemEntry **)((void *)(inner6)));
                if (cur != 0 && cur == pTargetItem)
                {
                    return count2;
                }
                count2 = count2 + 1;
                inner6 = ((::ContNode *)(reinterpret_cast<::Callees *>((inner6))->FUN_00726070()));
            }
            break;
        }
    }
    return -1;
}

struct ItemExtraNode;
struct ChangeEntry
{
};
struct ItemChangeNode
{
};
struct ItemExtraNode
{
};
struct ItemChangeList
{
    ItemChangeNode* first;
    int GetExtraValueAtPosition(int form, int position);
};
// Walks the change list for the entry matching form, then returns the extra value at position, or 0 if not found.
// @fnv 0x004d4480
int ItemChangeList::GetExtraValueAtPosition(int form, int position)
{
    if (form == 0 || position == -1)
        return 0;
    ItemChangeNode* node = first;
    while (node != 0)
    {
        ChangeEntry* entry = *((::ChangeEntry **)((void *)(node)));
        node = ((::ItemChangeNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (entry != 0 && ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) == form)
        {
            int index = 0;
            ItemExtraNode* extra = ((::ItemExtraNode *)(::FUN_00559450((int *)(entry))));
            while (extra != 0)
            {
                int result = *((int *)((void *)(extra)));
                if (index == position)
                    return result;
                ++index;
                extra = ((::ItemExtraNode *)(reinterpret_cast<::Callees *>((extra))->FUN_00726070()));
            }
            break;
        }
    }
    return 0;
}

struct Entry_004d4b00
{
    ~Entry_004d4b00();
};
struct Iterator_004d4b00
{
    ~Iterator_004d4b00();
};
struct Output_004d4b00
{
    void FUN_005ae3d0(Entry_004d4b00**);
};
struct Host_004d4b00
{
    Entry_004d4b00* GetNextInventoryEntry(Iterator_004d4b00*);
    void FindEntriesByType(int type, Output_004d4b00* output);
};
// Iterates inventory changes and returns the first entry whose extra list has the given list type, deleting skipped entries.
// @fnv 0x004bf4b0
InventoryStackRecord* InventoryChangesIter::FindEntryWithExtraListType(int aiType)
{
    AutoMemContext memContext2((MEM_CONTEXT)0x36, true, ::DAT_01020778, 0x76a);
    InventoryIterator* pIter6 = ((::InventoryIterator *)(reinterpret_cast<::OwnerProduct *>(this)->FUN_004ca200()));
    InventoryStackRecord* pEntry = 0;
    do
    {
        pEntry = ((::InventoryStackRecord *)(reinterpret_cast<::Host_004d4b00 *>(this)->GetNextInventoryEntry((::Iterator_004d4b00 *)(pIter6))));
        if (pEntry)
        {
            for (ExtraListNode* pNode = ((::ExtraListNode *)(::FUN_00559450((int *)(static_cast<ItemChangeLists*>(pEntry)))));
                 pNode && *((::ExtraListTyped **)((void *)(pNode))); pNode = ((::ExtraListNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
            {
                char cType = ((char)(reinterpret_cast<::FUN_0042de90_cls *>(((*((::ExtraListTyped **)((void *)(pNode))))))->GetExtraByteValue()));
                if (cType == aiType)
                {
                    delete pIter6;
                    return pEntry;
                }
            }
            delete pEntry;
        }
    } while (pEntry);
    delete pIter6;
    return 0;
}
// @fnv 0x004d4b00
void Host_004d4b00::FindEntriesByType(int type, Output_004d4b00* output)
{
    if (type == 0 || output == 0)
        return;
    Iterator_004d4b00* iterator = ((::Iterator_004d4b00 *)(reinterpret_cast<::OwnerProduct *>(this)->FUN_004ca200()));
    Entry_004d4b00* entry = 0;
    bool found5 = false;
    do
    {
        entry = GetNextInventoryEntry(iterator);
        if (entry != 0)
        {
            if (((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) == type)
            {
                found5 = true;
                output->FUN_005ae3d0(&entry);
            }
            else
            {
                delete entry;
                if (found5)
                    break;
            }
        }
    } while (entry != 0);
    delete iterator;
}

namespace fnv_004d4bd0 {
struct ChangeItem
{
    ~ChangeItem();
};
struct InventoryIterator
{
    ~InventoryIterator();
};
struct MatchedChanges
{
    void FUN_005ae3d0(ChangeItem** item);
};
struct InventoryChangeFilterHost
{
    void FilterInventoryChanges(void* requestedForm, MatchedChanges* matchedChanges);
};
// Iterates inventory changes, keeps those matching requestedForm in matchedChanges, deletes the rest, then deletes the iterator.
// @fnv 0x004d4bd0
void InventoryChangeFilterHost::FilterInventoryChanges(void* requestedForm, MatchedChanges* matchedChanges)
{
    if (!requestedForm || !matchedChanges)
        return;

    InventoryIterator* iterator = ((::fnv_004d4bd0::InventoryIterator *)(reinterpret_cast<::OwnerProduct *>(this)->FUN_004ca200()));
    ChangeItem* itemChange = 0;
    do
    {
        itemChange = ((::fnv_004d4bd0::ChangeItem *)(reinterpret_cast<::Host_004d4b00 *>(this)->GetNextInventoryEntry((::Iterator_004d4b00 *)(iterator))));
        if (itemChange)
        {
            if (::IsItemEquivalent((::ItemForm *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((itemChange))->GetName()))), (::ItemForm *)(requestedForm)))
                matchedChanges->FUN_005ae3d0(&itemChange);
            else
                delete itemChange;
        }
    } while (itemChange);
    delete iterator;
}
}  // namespace fnv_004d4bd0

struct Record90
{
    unsigned int id;
    unsigned char type;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char version;
};
struct Load90
{
    unsigned char FUN_008df040();
};
unsigned short FUN_004efaa0();
struct Seq90
{
};
struct Idle90
{
};
struct Ptr90
{
    Idle90* p;
    void FUN_0066b0d0(Idle90*);
    operator Idle90*() const;
};
struct Found90
{
};
struct Caster90
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
};
struct Actor90 : MobileObject
{
    Caster90 caster;
};
struct Obj90
{
    virtual void v0();
};
struct Node90
{
};
struct Named90
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node90* v3();
};
struct Manager90
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual Named90* v35(void*);
};
struct Animation90 : Animation
{
    void LoadFromSave(TESObjectREFR*);
};
// @fnv 0x0049a1c0
void Animation90::LoadFromSave(TESObjectREFR* ref)
{
    char i;
    bool k;
    char j;
    {
        unsigned short size = 0;
        unsigned int start = 0;
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int uiBlockHeader;
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&uiBlockHeader, 4);
            if (uiBlockHeader != 0x424c4f4b)
            {
                Record90* record = ((::Record90 *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))));
                if (record)
                {
                    TESForm* form = FUN_004839c0(record->id);
                    ::FUN_005b5e40(
                        );
                }
                else
                    ::FUN_005b5e40(
                        );
            }
            start = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&size, 2);
        }
        Actor90* actor = 0;
        if (ref && ref->IsActor())
            actor = (Actor90*)ref;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&m_fMovementRate, 4);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&m_fCombatAnimationRate, 4);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(m_kNodeTranslation, 12);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&m_fAnimationAmount, 4);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&m_cState, 1);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&j, 1);
        for (i = 0; i < 8; i++)
            if (j & (1 << i))
            {
                reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&((unsigned short*)group)[i], 2);
                reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&((int*)action)[i], 4);
                reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&((int*)m_acTargetName)[i], 4);
                reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&((unsigned short*)usReloadGroup)[i], 2);
                reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&((int*)m_acAnimationName)[i], 4);
                char state;
                reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&state, 1);
                ((Seq90**)m_pChildTile)[i] = 0;
                if (state != -2)
                {
                    reinterpret_cast<::FUN_004974a0_shell *>(this)->FUN_004974a0();
                    reinterpret_cast<::fnv_004955c0::FUN_004955c0_t *>(this)->FUN_004955c0(i, ((unsigned short*)group)[i], ((int*)action)[i], time, state);
                    if (((Seq90**)m_pChildTile)[i])
                        reinterpret_cast<::fnv_004efbc0::HY *>((((Seq90**)m_pChildTile)[i]))->FUN_004efbc0(time);
                    else
                    {
                        reinterpret_cast<::FUN_00857bd0 *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->Init(FUN_004efaa0());
                        reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(i, 0.0f);
                    }
                }
            }
        ((Ptr90*)LocalInput)->FUN_0066b0d0(((::Idle90 *)(::LoadIdleAnimation((::Actor *)(actor), (::Animation *)(::Animation90 *)(this), time))));
        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 76)
            ((Ptr90*)LocalStateValue)->FUN_0066b0d0(((::Idle90 *)(::LoadIdleAnimation((::Actor *)(actor), (::Animation *)(::Animation90 *)(this), time))));
        if ((Idle90*)*(Ptr90*)LocalInput && ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((Idle90*)*(Ptr90*)LocalInput)))->GetName())) == 1)
            ((Seq90**)m_pChildTile)[7] = 0;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&m_cSkipNextBlend, 1);
        k = true;
        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 64)
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&k, 1);
        if (k)
        {
            bool restored = false;
            if (actor->caster.v13())
            {
                Named90* named = ((::Manager90 *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::Manager90 *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>(this)->FUN_00496940()))))))->v35(((void *)(::FUN_00499b70())));
                if (named)
                {
                    Node90* node = named->v3();
                    if (node)
                    {
                        Obj90* object = ((::Obj90 *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
                        if (object)
                        {
                            void* aControllers = ((void *)(::fnv_0043b230::FUN_0043b230((const char *)(object))));
                            {
                                Manager90* manager = ((::Manager90 *)(::FUN_00653270((const ::NiRTTI *)(const int *)(&(*reinterpret_cast<int *>(&::g_011f36ac))), (::NiObject *)(aControllers))));
                                if (manager)
                                {
                                    Seq90* sequence = ((::Seq90 *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(void *)(((void *)(::FUN_00499b80()))))));
                                    if (sequence)
                                    {
                                        reinterpret_cast<::NiControllerManager *>((manager))->DeactivateAllSequences(0.0f);
                                        reinterpret_cast<::NiControllerManager *>((manager))->ActivateControllerSequence((::NiControllerSequence *)(sequence), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                                        reinterpret_cast<::TaskQueueInterface *>((manager))->QueueReferenceStateTask(true);
                                        reinterpret_cast<::fnv_004efbc0::HY *>((sequence))->FUN_004efbc0(time);
                                        float aSavedTime;
                                        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&aSavedTime, 4);
                                        {
                                            Found90* found = ((::Found90 *)(reinterpret_cast<::Callees *>(&(actor->caster))->FUN_00726070()));
                                            if (found)
                                            {
                                                reinterpret_cast<::FUN_0081c470_shell *>((found))->FUN_0081c470(true, reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100() * 0.75);
                                                reinterpret_cast<::FUN_00621b20_Class *>((found))->FUN_00621b20(aSavedTime);
                                            }
                                        }
                                        restored = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 64 && !restored)
                reinterpret_cast<::FUN_00857bd0 *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->Init(FUN_004efaa0() + 4);
        }
        reinterpret_cast<::fnv_0049bca0::FUN_0049bca0_shell *>(this)->FUN_0049bca0(time, (::NiPoint3 *)(m_kRootTranslation), true);
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int end = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            Record90* record = ((::Record90 *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::Load90 * *>(&::g_TESSaveLoadGame))))));
            if (record)
            {
                TESForm* form = FUN_004839c0(record->id);
                if (end > start + size)
                    ::FUN_005b5e40(
                        );
                else if (end < start + size)
                    ::FUN_005b5e40(
                        );
            }
            else
            {
                if (end > start + size)
                    ::FUN_005b5e40(
                        );
                else if (end < start + size)
                    ::FUN_005b5e40(
                        );
            }
        }
    }
}

struct ExtraDataListCopy : public ExtraDataList
{
    ExtraDataListCopy();
};

struct FUN_004bc650_shell : public InventoryStackRecord
{
    InventoryStackRecord* FUN_004bc650(InventoryStackRecord* other);
};

// @fnv 0x004bc650
InventoryStackRecord* FUN_004bc650_shell::FUN_004bc650(InventoryStackRecord* other)
{
    m_pItemObject = other->m_pItemObject;
    m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
    ExtraDataList* copy;
    BSSimpleList<ExtraDataList*>* node2 = other->m_pExtraDataLists;
    copy = 0;
    while (node2 && (node2->m_item))
    {
        copy = new ExtraDataListCopy;
        reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((((ExtraDataListCopy*)copy)))->FUN_00412380((node2->m_item));
        reinterpret_cast<::Callees *>((m_pExtraDataLists))->FUN_00905820((void *)&(copy));
        node2 = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
    }
    m_iCountChange = other->m_iCountChange;
    return this;
}

struct ExtraList_4bd5c0
{
    ExtraList_4bd5c0();
    virtual ~ExtraList_4bd5c0();
    void* pHead;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct ExtraListList_4bd5c0
{
    ExtraList_4bd5c0* m_item;
    ExtraListList_4bd5c0* m_pkNext;
    ExtraListList_4bd5c0();
    void AddHead(ExtraList_4bd5c0*& item);
};

struct ItemChange_4bd5c0
{
    ExtraListList_4bd5c0* m_pExtraDataLists;
    int m_iCountChange;
    void* m_pItemObject;
    void FUN_004bd5c0(void* extra);
};

// Copies extra data into the first ExtraList, creating the list if needed, or removes and deletes the first entry when extra is null.
// @fnv 0x004bd5c0
void ItemChange_4bd5c0::FUN_004bd5c0(void* extra)
{
    if (extra)
    {
        if (m_pExtraDataLists && *((::ExtraList_4bd5c0 **)((void *)(m_pExtraDataLists))))
        {
            reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>(((*((::ExtraList_4bd5c0 **)((void *)(m_pExtraDataLists))))))->FUN_00419700((::fnv_00419700::TESForm *)(extra));
        }
        else
        {
            ExtraList_4bd5c0* list = new ExtraList_4bd5c0;
            reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((list))->FUN_00419700((::fnv_00419700::TESForm *)(extra));
            if (!m_pExtraDataLists)
                m_pExtraDataLists = new ExtraListList_4bd5c0;
            m_pExtraDataLists->AddHead(list);
        }
    }
    else if (m_pExtraDataLists)
    {
        ExtraList_4bd5c0* first = *((::ExtraList_4bd5c0 **)((void *)(m_pExtraDataLists)));
        if (first)
        {
            reinterpret_cast<::ItemChangeListNode *>((m_pExtraDataLists))->FUN_00905330((::InventoryStackRecord *const &)(first));
            delete first;
        }
    }
}

namespace fnv_004be5a0 {

struct SaveSizeItem
{
};
struct SaveSizeNode
{
    bool _ref_008256d0();
};
struct SaveSizeForm
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetEditorName();
};

struct SaveChangeRecord
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char changeFlagsStart;
};
struct SaveLoadGameStub
{
};

struct DebugSettingStub
{
    unsigned char* Bool();
};


struct InventoryChangesSaveSize : public InventoryChanges
{
    unsigned short FUN_004be5a0();
};

// Computes the save size of the inventory changes: adds fixed header bytes, sums each item's size, and optionally logs the total with the current form.
// @fnv 0x004be5a0
unsigned short InventoryChangesSaveSize::FUN_004be5a0()
{
    unsigned short size3 = 0;
    unsigned short start = size3;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004be5a0::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 8;
    size3 += 4;
    SaveSizeNode* node5 = (SaveSizeNode*)m_pEntryList;
    while (node5 && !node5->_ref_008256d0())
    {
        SaveSizeItem* itemB = *((::fnv_004be5a0::SaveSizeItem **)((void *)(node5)));
        size3 += reinterpret_cast<::fnv_00422c40::ExtraDataListQ *>((itemB))->FUN_00422c40(0, (::fnv_00422c40::ObjQ *)(0));
        node5 = ((::fnv_004be5a0::SaveSizeNode *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
    }
    if (*(*reinterpret_cast<::fnv_004be5a0::DebugSettingStub *>(&::g_011de4e8)).Bool())
    {
        SaveChangeRecord* pChangeRecord = ((::fnv_004be5a0::SaveChangeRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_004be5a0::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (pChangeRecord)
        {
            SaveSizeForm* form = ((::fnv_004be5a0::SaveSizeForm *)(::FUN_004839c0(pChangeRecord->formID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size3;
}
}  // namespace fnv_004be5a0

namespace fnv_004be930 {

struct FUN_004fd3c0_info
{
    unsigned int uiID;
    unsigned char aucData[6];
    unsigned int GetValue5()
    {
        return *(unsigned int*)&aucData[1];
    }
};

struct FUN_004be930_form
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual const char* v076();
};

struct FUN_008df040_shell
{
    unsigned char FUN_008df040();
};

struct FUN_00424960_extra
{
};

struct FUN_004be930_shell
{
    BSSimpleList<ExtraDataList*>* pExtraLists;
    int iCountDelta;
    TESBoundObject* pObject;
    void FUN_004be930();
};

// Reads a save-load block header, form ID, count delta and extra-data list, then warns on block header or buffer size mismatches.
// @fnv 0x004be930
void FUN_004be930_shell::FUN_004be930()
{
    int i;
    unsigned int uiFormIDX;
    unsigned short usSize = 0;
    unsigned int uiStart = 0;
    int iCount;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int uiMarker;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&uiMarker, 4);
        if (uiMarker != 0x424c4f4b)
        {
            FUN_004fd3c0_info* pInfo = ((::fnv_004be930::FUN_004fd3c0_info *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))));
            if (pInfo)
            {
                FUN_004be930_form* pForm = ((::fnv_004be930::FUN_004be930_form *)(::FUN_004839c0(pInfo->uiID)));
                ::FUN_005b5e40(
                    );
            }
            else
                ::FUN_005b5e40(
                    );
        }
        uiStart = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usSize, 2);
    }

    reinterpret_cast<::FUN_00857aa0 *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->ValidateFormIDArray(&uiFormIDX, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&iCountDelta, 4);
    pObject = dynamic_cast<TESBoundObject*>((TESForm*)((::fnv_004be930::FUN_004be930_form *)(::FUN_004839c0(uiFormIDX))));
    pExtraLists = 0;
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&iCount, 4);
    if (iCount)
    {
        pExtraLists = new BSSimpleList<ExtraDataList*>;
        for (i = 0; i < iCount; i++)
        {
            ExtraDataList* pExtra = (ExtraDataList*)new FUN_00410360;
            reinterpret_cast<::p376::Extras *>((((FUN_00424960_extra*)pExtra)))->FUN_00424960(0, 0, (::TESObjectREFR *)(0));
            reinterpret_cast<::Callees *>((pExtraLists))->FUN_00905820((void *)&(pExtra));
        }
    }

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        FUN_004fd3c0_info* pInfoCur;
        unsigned int uiEnd = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        pInfoCur = ((::fnv_004be930::FUN_004fd3c0_info *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_004be930::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))))));
        if (pInfoCur)
        {
            FUN_004be930_form* pFormCur = ((::fnv_004be930::FUN_004be930_form *)(::FUN_004839c0(pInfoCur->uiID)));
            if (uiEnd > usSize + uiStart)
                ::FUN_005b5e40(
                    );
            else if (uiEnd < usSize + uiStart)
                ::FUN_005b5e40(
                    );
        }
        else
        {
            if (uiEnd > usSize + uiStart)
                ::FUN_005b5e40(
                    );
            else if (uiEnd < usSize + uiStart)
                ::FUN_005b5e40(
                    );
        }
    }
}
}  // namespace fnv_004be930

namespace fnv_004bf660 {
struct InventoryExtra
{
};
struct InventoryExtraNode
{
};
struct InventoryEntry
{
    ~InventoryEntry();
};
struct InventoryIterator
{
    ~InventoryIterator();
};
struct InventoryOwner
{
    InventoryEntry** CollectEntriesByRank(int, int);
};
// @fnv 0x004bf660
InventoryEntry** InventoryOwner::CollectEntriesByRank(int aiMinRank, int aiMaxRank)
{
    if (aiMinRank > aiMaxRank)
        return 0;
    unsigned int iterator = aiMaxRank - aiMinRank + 1;
    InventoryEntry** entries = new InventoryEntry*[iterator];
    ::FUN_00403d30(entries, 0, iterator * sizeof(InventoryEntry*));
    InventoryIterator* count = ((::fnv_004bf660::InventoryIterator *)(reinterpret_cast<::OwnerProduct *>(this)->FUN_004ca200()));
    InventoryEntry* entry = 0;
    do
    {
        entry = ((::fnv_004bf660::InventoryEntry *)(reinterpret_cast<::Host_004d4b00 *>(this)->GetNextInventoryEntry((::Iterator_004d4b00 *)(count))));
        if (entry)
        {
            bool found = false;
            for (InventoryExtraNode* node = ((::fnv_004bf660::InventoryExtraNode *)(::FUN_00559450((int *)(entry)))); node && *((::fnv_004bf660::InventoryExtra **)((void *)(node)));
                 node = ((::fnv_004bf660::InventoryExtraNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                signed char rank = ((signed char)(reinterpret_cast<::FUN_0042de90_cls *>(((*((::fnv_004bf660::InventoryExtra **)((void *)(node))))))->GetExtraByteValue()));
                if (rank >= aiMinRank && rank <= aiMaxRank)
                {
                    int index = rank - aiMinRank;
                    delete entries[index];
                    entries[index] = entry;
                    found = true;
                }
            }
            if (!found)
                delete entry;
        }
    } while (entry);
    delete count;
    return entries;
}
}  // namespace fnv_004bf660

struct RefSlot
{
};
struct PlayerSlot
{
};
struct ExtraSlot
{
};
struct ChangeSlot : InventoryStackRecord
{
};
struct InventorySlot : InventoryChanges
{
    void SetInventorySlotExtraData(RefSlot*, ExtraDataList*, int);
};
// Ensures the inventory change for ref has an ExtraDataList tagged with slot, creating the change and list entries when missing.
// @fnv 0x004bf800
void InventorySlot::SetInventorySlotExtraData(RefSlot* ref, ExtraDataList* extra, int slot)
{
    AutoMemContext change(MEM_CONTEXT_MEM_CONTEXT_INVENTORY, true, ::DAT_01020778, 1974);
    if (!ref || slot < 0 || slot > 7)
        return;
    if (reinterpret_cast<::FUN_004bfb30_shell *>((((PlayerSlot*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->GetAtIfValid(slot))
        reinterpret_cast<::FUN_004bfb70_stand *>((((PlayerSlot*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->SetIdleAt(slot, (::XIdle *)(void *)(0));
    reinterpret_cast<::Inv_4bf330 *>(this)->ClearExtraForSlot((::RefBase_4bf330 *)(ref), -1);
    ChangeSlot* context = ((::ChangeSlot *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ref))->GetName())), 1, 0)));
    if (context)
    {
        ExtraDataList* selected = 0;
        if (!context->m_pExtraDataLists)
            context->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
        for (BSSimpleList<ExtraDataList*>* node = context->m_pExtraDataLists; node && (node->m_item);
             node = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
        {
            if (!selected && reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((((ExtraSlot*)(node->m_item))))->HasOnlyAllowedExtraData(0))
                selected = (node->m_item);
            if ((node->m_item) == extra)
                selected = extra;
        }
        if (!selected)
        {
            ExtraDataList* created = (ExtraDataList*)new FUN_00410360;
            reinterpret_cast<::FUN_0042dde0_cls *>((((ExtraSlot*)created)))->SetHotKey((unsigned char)slot);
            reinterpret_cast<::FUN_00419ad0_shell *>((((ExtraSlot*)created)))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((context))->FUN_00726070())) - reinterpret_cast<::FUN_004bc8f0_stand *>((context))->FUN_004bc8f0(false) -
                               (reinterpret_cast<::FUN_004bddd0_shell *>((context))->FUN_004bddd0(false) ? 1 : 0));
            context->m_pExtraDataLists->AddHead(created);
        }
        else
        {
            reinterpret_cast<::FUN_0042dde0_cls *>((((ExtraSlot*)selected)))->SetHotKey((unsigned char)slot);
        }
    }
    else
    {
        InventoryStackRecord* pNewChange = (InventoryStackRecord*)new FUN_004bc550(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ref))->GetName())), ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((ref))->FUN_00726070())));
        ExtraDataList* pNewExtra = (ExtraDataList*)new FUN_00410360;
        pNewChange->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
        reinterpret_cast<::FUN_0042dde0_cls *>((((ExtraSlot*)pNewExtra)))->SetHotKey((unsigned char)slot);
        pNewChange->m_pExtraDataLists->AddHead(pNewExtra);
        m_pEntryList->AddHead(pNewChange);
    }
}

struct EquipForm;
struct EquipExtra;
struct EquipEntry;
struct EquipActor;
struct EquipAnim;
struct EquipList
{
    EquipExtra* item;
    EquipList* next;
    EquipList();
    void FUN_005ae3d0(EquipExtra*&);
};
struct EquipExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    EquipExtra();
    bool FUN_004127e0(EquipExtra*);
    bool FUN_00418b10();
};
struct EquipEntry
{
    EquipList* extras;
    int count;
    EquipForm* form;
    EquipEntry(EquipForm*, int);
    ~EquipEntry();
};
struct EquipBiped
{
};
struct EquipForm
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    EquipBiped biped;
    int FUN_00401170();
};
struct EquipContainer
{
};
struct EquipChangeList
{
};
struct EquipProcess
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual EquipEntry* v148();
    virtual EquipEntry* v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool v160(EquipEntry*, int, int);
    virtual void v164();
    virtual bool v168(EquipEntry*);
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468(int);
    virtual void v46c();
    virtual void v470();
    virtual bool v474(int);
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4(EquipActor*);
};
struct EquipAnim
{
};
struct EquipActor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(int);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int v1d0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    EquipProcess* process;
    void SetField1F0(EquipForm*);
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};

struct EquipQueue
{
};
struct EquipInv
{
    EquipChangeList* changes;
    EquipActor* owner;
    EquipContainer* FUN_004bffb0();
    void AddItemToInventory(EquipForm*, int, EquipActor*, EquipExtra*, bool, bool);
};

struct BoundShell : TESBoundObject
{

    int FUN_00401170();


};

struct ExtraShell : ExtraDataList
{

    ExtraShell();



    bool FUN_004127e0(ExtraShell*);




};

struct ExtraNodeShell : BSSimpleList<ExtraDataList*>
{

    ExtraNodeShell();




    void FUN_005ae3d0(ExtraShell**);
};

struct ItemShell : InventoryStackRecord
{

    ItemShell(BoundShell*, int);



};

struct ItemListShell : BSSimpleList<InventoryStackRecord*>
{

};

struct RefShell : TESObjectREFR
{

    void Invalidate(unsigned mask)
    {

        typedef void(* Callback)(TESObjectREFR*, unsigned);

        ((Callback)(*(void***)this)[18])(this, mask);
    }
};

struct ChangesShell : InventoryChanges
{


    BoundShell* FUN_004bffb0(BoundShell*);

    void AddItemExtraData(BoundShell*, int, int, ExtraShell*, ExtraNodeShell**);
};

// @fnv 0x004c1520
void ChangesShell::AddItemExtraData(BoundShell* item, int number, int unknown, ExtraShell* selection,
                                    ExtraNodeShell** apResultList)

{

    AutoMemContext contextGuard((MEM_CONTEXT)0x36, true, ::DAT_01020778, 0xb83);

    if (pRef)
        pRef->MarkAsModified(0x20);

    ItemShell* itemCount = ((::ItemShell *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(item), 1, 0)));

    int wornCount = reinterpret_cast<::TESContainer *>((((::BoundShell *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount({});

    int itemChange = wornCount;

    if (itemCount)

        itemChange += itemCount->m_iCountChange;

    int oldCount = 0;

    if (itemCount && itemCount->m_pExtraDataLists)
    {

        oldCount = reinterpret_cast<::FUN_004bc8f0_stand *>((itemCount))->FUN_004bc8f0(false) + reinterpret_cast<::FUN_004bc980_shell *>((itemCount))->FUN_004bc980();
    }

    int needExtra = itemChange - oldCount;

    if (itemCount && itemCount->m_pExtraDataLists)
    {

        if (*((::ExtraShell **)((void *)(((ExtraNodeShell*)itemCount->m_pExtraDataLists)))) &&

            reinterpret_cast<::ExtraDataList *>(((*((::ExtraShell **)((void *)(((ExtraNodeShell*)itemCount->m_pExtraDataLists)))))))->HasExtraDataType0x2F())

            needExtra = wornCount - oldCount;

        bool found = false;

        if (selection && !reinterpret_cast<::RefList *>((((ExtraNodeShell*)itemCount->m_pExtraDataLists)))->FUN_005f65d0((void **)(::ExtraShell **)(&selection)))
        {

            ExtraNodeShell* cursor = (ExtraNodeShell*)itemCount->m_pExtraDataLists;

            while (cursor && *((::ExtraShell **)((void *)(cursor))))
            {

                ExtraShell* possible = *((::ExtraShell **)((void *)(cursor)));

                if (possible && !possible->FUN_004127e0(selection))
                {
                    selection = possible;
                    found = true;
                    break;
                }
                else
                {
                    cursor = ((::ExtraNodeShell *)(reinterpret_cast<::Callees *>((cursor))->FUN_00726070()));
                }
            }

            if (!found)
                selection = 0;
        }
    }

    bool remaining = true;

    ExtraShell* chosen = 0;

    if ((!selection && needExtra > 0) || !itemCount)
    {

        if (!itemCount)
        {

            itemCount = new ItemShell(item, 0);

            remaining = true;

            reinterpret_cast<::Callees *>((((ItemListShell*)m_pEntryList)))->FUN_00905820((InventoryStackRecord**)&itemCount);

            selection = 0;
        }
    }
    else
    {

        if (reinterpret_cast<::FUN_004bddd0_shell *>((itemCount))->FUN_004bddd0(false))

            return;

        ExtraNodeShell* cursor = (ExtraNodeShell*)itemCount->m_pExtraDataLists;

        while (cursor && remaining)
        {

            chosen = *((::ExtraShell **)((void *)(cursor)));

            if (selection && selection == chosen)
            {

                bool isWeapon = item->FUN_00401170() == 0x28 && ::FUN_004c0bf0((::TESObjectWEAP *)(item));

                if (reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770() > 1 && item->FUN_00401170() != 0x29 && !isWeapon)
                {

                    selection = new ExtraShell();

                    reinterpret_cast<::fnv_00411ec0::FUN_00411ec0_shell *>((selection))->FUN_00411ec0((::ExtraDataList *)(chosen));

                    reinterpret_cast<::FUN_00419ad0_shell *>((selection))->FUN_00419ad0(1);

                    reinterpret_cast<::FUN_00419ad0_shell *>((chosen))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770() - 1);

                    if (((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((chosen))->GetExtraByteValue())) >= 0)

                        reinterpret_cast<::FUN_0042dec0_shell *>((chosen))->FUN_0042dec0();
                }
                else
                {

                    reinterpret_cast<::FUN_00419ad0_shell *>((chosen))->FUN_00419ad0((int)(std::uintptr_t)((::ExtraNodeShell *)(reinterpret_cast<::Callees *>((((ExtraNodeShell*)itemCount)))->FUN_00726070())));
                }

                remaining = false;
            }
            else if (chosen && !selection)
            {

                if (reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770() == 1)
                {

                    selection = chosen;
                }
                else
                {

                    bool isWeapon = item->FUN_00401170() == 0x28 && ::FUN_004c0bf0((::TESObjectWEAP *)(item));

                    if (reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770() > 1 && item->FUN_00401170() != 0x29 && !isWeapon)
                    {

                        selection = new ExtraShell();

                        reinterpret_cast<::fnv_00411ec0::FUN_00411ec0_shell *>((selection))->FUN_00411ec0((::ExtraDataList *)(chosen));

                        reinterpret_cast<::FUN_00419ad0_shell *>((selection))->FUN_00419ad0(1);

                        reinterpret_cast<::FUN_00419ad0_shell *>((chosen))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770() - 1);

                        if (((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((chosen))->GetExtraByteValue())) >= 0)

                            reinterpret_cast<::FUN_0042dec0_shell *>((chosen))->FUN_0042dec0();
                    }
                    else
                        selection = chosen;
                }

                remaining = false;
            }
            else
            {

                cursor = ((::ExtraNodeShell *)(reinterpret_cast<::Callees *>((cursor))->FUN_00726070()));
            }
        }
    }

    if (selection)
    {

        reinterpret_cast<::FUN_00419ad0_shell *>((selection))->FUN_00419ad0((unsigned short)number);

        remaining = false;

        if (!itemCount->m_pExtraDataLists)

            itemCount->m_pExtraDataLists = new ExtraNodeShell();

        if (!reinterpret_cast<::RefList *>((((ExtraNodeShell*)itemCount->m_pExtraDataLists)))->FUN_005f65d0((void **)(::ExtraShell **)(&selection)))

            ((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005ae3d0(&selection);

        if (apResultList && !reinterpret_cast<::RefList *>(((*apResultList)))->FUN_005f65d0((void **)(::ExtraShell **)(&selection)))

            (*apResultList)->FUN_005ae3d0(&selection);

        chosen = selection;
    }

    if (remaining)
    {

        chosen = new ExtraShell();

        if (number > 1)

            reinterpret_cast<::FUN_00419ad0_shell *>((chosen))->FUN_00419ad0((unsigned short)number);

        if (!itemCount->m_pExtraDataLists)

            itemCount->m_pExtraDataLists = new ExtraNodeShell();

        if (!reinterpret_cast<::RefList *>((((ExtraNodeShell*)itemCount->m_pExtraDataLists)))->FUN_005f65d0((void **)(::ExtraShell **)(&chosen)))

            ((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005ae3d0(&chosen);

        if (apResultList)
        {

            if (!*apResultList)

                *apResultList = new ExtraNodeShell();

            if (!reinterpret_cast<::RefList *>(((*apResultList)))->FUN_005f65d0((void **)(::ExtraShell **)(&chosen)))

                (*apResultList)->FUN_005ae3d0(&chosen);
        }
    }
}

class TESForm;
struct TESHealthForm
{
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual unsigned int GetHealth();
public:
    static unsigned int GetBaseHealth(::TESForm *);
};
// If m_pkForm is form type 0x28, computes a scale from two values and forwards it to FUN_00644ce0; otherwise returns 0.0f.
// @fnv 0x004bdf00
float B4BDF00Data::GetScaledValue(void* pvActor, float fValue, bool bFlag)
{
    if (m_pkForm->GetFormType() == 0x28)
    {
        B4BDF00Form* pkWeapon = m_pkForm;
        float fScale = reinterpret_cast<::FUN_004bcdb0_shell *>(this)->FUN_004bcdb0(0) / ::TESHealthForm::GetBaseHealth((::TESForm *)(pkWeapon));
        return ::FUN_00644ce0((::ActorValueOwner *)(pvActor), (::DmgWeapon *)(pkWeapon), fScale, fValue, 0, bFlag, (::InventoryStackRecord *)(::B4BDF00Data *)(this), 1);
    }
    else
    {
        reinterpret_cast<::TESForm *>((m_pkForm))->GetFormType();
    }
    return 0.0f;
}
// Computes a value from the item's form type and count, then passes the result to FUN_00476b20.
// @fnv 0x004bdf90
void ItemChangeCalc::UpdateItemChange(int unused)
{
    float result = ::DAT_01012054;
    if (item->FUN_00401170() == 0x18)
    {
        BookForm* current = item;
        float count = (float)::TESHealthForm::GetBaseHealth((::TESForm *)(current));
        float multiplier = (float)(count == ::_DAT_01012060 ? 0.0 : reinterpret_cast<::FUN_004bcdb0_shell *>(this)->FUN_004bcdb0(0) / count);
        result = ::CombatDamageCalculator::CalculateArmorDamageThreshold((unsigned short)((float)(::FUN_004be060((void *)(current)))), multiplier);
    }
    ::InventoryStackRecord::GetConditionPercent(result);
}
struct W20Form;
struct W20Ref;
struct W20AmmoExtra
{
    unsigned int unk00, unk04, unk08, unk0c;
    int count;
};
struct W20Extra
{
    virtual ~W20Extra();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    W20Extra();
};
struct W20ExtraList
{
    W20Extra* data;
    W20ExtraList* next;
    W20ExtraList();
    ~W20ExtraList();
    void AddHead(W20Extra**);
    bool IsEmpty();
};
struct W20Entry
{
    W20ExtraList* extras;
    int count;
    W20Form* form;
    W20Entry(W20Form*, int);
    ~W20Entry();
};
struct W20EntryList
{
};
struct W20Form : TESBoundObject
{
    int FNV_GetFormType();
    int GetWeaponType();
    W20Form* GetCurrentAmmo(W20Ref*);
};
struct W20Ref
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void v48(int);
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual bool v100();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual const char* v130();
    unsigned int GetFormID();
};
struct W20Inventory
{
    W20EntryList* entries;
    W20Ref* owner;
    float weight;
    float previous;
    bool dirty;
    void FUN_004c1c90(W20Ref*, int, int, bool);
};

struct AddForm;
struct AddRef;
struct AddProcess;
struct AddExtra;
struct AddEntry;
struct AddAmmoExtra
{
    int unk00, unk04, unk08, unk0c;
    int count;
};
struct AddExtra
{
    virtual ~AddExtra();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    AddExtra();
};
struct AddNode
{
    AddExtra* data;
    AddNode* next;
    AddNode();
    void _ref_005ae3d0(AddExtra*&);
    int _ref_005ae380();
    bool _ref_008256d0();
};
struct AddEntry
{
    AddNode* extras;
    int count;
    AddForm* form;
    AddEntry(AddForm*, int);
    ~AddEntry();
};
struct AddProcess
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual AddEntry* ammoA();
    virtual AddEntry* p();
};
struct AddRef
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool isActor();
};
struct AddForm
{
    int FUN_00401170();
};
struct AddContainer
{
};
struct AddChanges
{
};
struct AddInventory
{
    AddChanges* changes;
    AddRef* owner;
    float weight, previousWeight;
    bool dirty;
    AddContainer* FUN_004bffb0();
    void FUN_004c29a0(AddForm*, AddExtra*, int);
};
struct Inv4c6a10
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0* FUN_004bffb0();
    TESBoundObject* FindInventoryItemByType(int aType, int* apCount);
};

// @fnv 0x004c6a10
TESBoundObject* Inv4c6a10::FindInventoryItemByType(int aType, int* apCount)
{
    ContNode4c6ba0* pNode = ((::Container4c6ba0 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    TESBoundObject* pFound5 = 0;
    while (pNode && !pFound5)
    {
        pFound5 = (*((::ContEntry4c6ba0 **)((void *)(pNode))))->pObj;
        if (pFound5 && FUN_00679ba0(pFound5) == aType)
        {
            Change4c6ba0* pChange = ((::Change4c6ba0 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(pFound5, 1, 0)));
            if (!pChange || (pChange && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + (*((::ContEntry4c6ba0 **)((void *)(pNode))))->count))
            {
                if (pChange)
                    *apCount = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + (*((::ContEntry4c6ba0 **)((void *)(pNode))))->count;
                else
                    *apCount = (*((::ContEntry4c6ba0 **)((void *)(pNode))))->count;
            }
        }
        else
        {
            pFound5 = 0;
        }
        pNode = ((::ContNode4c6ba0 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    ChangeNode4c6ba0* pIter_ = m_pEntryList;
    while (pIter_ && !pFound5)
    {
        pFound5 = (*((::Change4c6ba0 **)((void *)(pIter_))))->m_pItemObject;
        if (pFound5 && FUN_00679ba0(pFound5) == aType)
        {
            if (!reinterpret_cast<::TESContainer *>((((::Container4c6ba0 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(pFound5)) && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::Change4c6ba0 **)((void *)(pIter_))))))->FUN_00726070())) > 0)
                *apCount = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::Change4c6ba0 **)((void *)(pIter_))))))->FUN_00726070()));
        }
        else
        {
            pFound5 = 0;
        }
        pIter_ = ((::ChangeNode4c6ba0 *)(reinterpret_cast<::Callees *>((pIter_))->FUN_00726070()));
    }
    return pFound5;
}

class TESAmmo : public TESBoundObject
{
};
struct AmmoScorer
{
};
struct AmmoContainerEntry
{
    int count;
    TESBoundObject* object;
};
struct AmmoContainerNode
{
};
struct AmmoContainer
{
    AmmoContainerNode* FUN_00717e50();
};
struct AmmoInventory
{
    ItemList* changes;
    AmmoContainer* FUN_004bffb0();
    FUN_0076b630* FindBestAmmoChange(AmmoScorer*, int);
};
// @fnv 0x004c6f60
FUN_0076b630* AmmoInventory::FindBestAmmoChange(AmmoScorer* scorer, int unused)
{
    // Local names preserve the original MSVC9 stack allocation.
    AutoMemContext bestChange((MEM_CONTEXT)0x36, true, ::DAT_01020778, 0x13b5);
    float context = DAT_01015f5c;
    TESAmmo* memory = 0;
    TESAmmo* bestBase = 0;
    AmmoContainerNode* memContext = ((::AmmoContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    while (memContext)
    {
        AmmoContainerEntry* entry = *((::AmmoContainerEntry **)((void *)(memContext)));
        TESAmmo* ammo = 0;
        if (entry)
            ammo = dynamic_cast<TESAmmo*>(entry->object);
        if (ammo)
        {
            FUN_0076b630* change = ((::FUN_0076b630 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(ammo), 1, 0)));
            if (!change || ((change && change->count + (*((::AmmoContainerEntry **)((void *)(memContext))))->count > 0) ||
                            (*((::AmmoContainerEntry **)((void *)(memContext))))->count < 0))
            {
                float score = reinterpret_cast<::ActorBaseTarget *>((scorer))->FUN_005f0d60((::FormTarget *)(ammo));
                if (score > context)
                {
                    context = score;
                    memory = ammo;
                }
            }
        }
        memContext = ((::AmmoContainerNode *)(reinterpret_cast<::Callees *>((memContext))->FUN_00726070()));
    }
    ItemList* bestScore = changes;
    while (bestScore)
    {
        FUN_0076b630* ammo = ((::FUN_0076b630 *)((void *)(bestScore)));
        TESAmmo* entry = 0;
        if (ammo)
            entry = dynamic_cast<TESAmmo*>((TESBoundObject*)ammo->weapon);
        if (entry && (!reinterpret_cast<::InventoryStackRecord *>((ammo))->HasPerkEntry() || ammo->count >= 0) && ((::ItemList *)(reinterpret_cast<::Callees *>((ammo))->FUN_00726070())) &&
            !reinterpret_cast<::TESContainer *>((((::AmmoContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(entry)))
        {
            float score = reinterpret_cast<::ActorBaseTarget *>((scorer))->FUN_005f0d60((::FormTarget *)(entry));
            if (score > context)
            {
                context = score;
                bestBase = entry;
            }
        }
        bestScore = ((::ItemList *)(reinterpret_cast<::Callees *>((bestScore))->FUN_00726070()));
    }
    if (bestBase && bestBase != memory && reinterpret_cast<::ActorBaseTarget *>((scorer))->FUN_005f0d60((::FormTarget *)(bestBase)) > reinterpret_cast<::ActorBaseTarget *>((scorer))->FUN_005f0d60((::FormTarget *)(memory)))
        memory = bestBase;
    FUN_0076b630* change = ((::FUN_0076b630 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(memory), 1, 0)));
    FUN_0076b630* changeNode = 0;
    if (memory)
        changeNode = new FUN_0076b630;
    if (change)
    {
        changeNode->weapon = ((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((change))->GetName()));
        if (((::FUN_0096a2d0 *)(::FUN_00559450((int *)(change)))) && ((::Extra *)((void *)(change->extras))))
        {
            changeNode->extras = new FUN_0096a2d0;
            changeNode->extras->FUN_005ae3d0(&change->extras->item);
            reinterpret_cast<::CombatProcedure *>((changeNode))->Initialize((::CombatController *)(((::ItemList *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()))));
        }
    }
    else if (memory)
    {
        changeNode->weapon = (Weapon*)memory;
        int count = reinterpret_cast<::TESContainer *>((((::AmmoContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(memory));
        if (count < 0)
            count *= -1;
        reinterpret_cast<::CombatProcedure *>((changeNode))->Initialize((::CombatController *)(count));
    }
    return changeNode;
}

struct Scope64
{
    int value;
    Scope64(int, int, const char*, int);
    ~Scope64();
};
struct Form64
{
    int FUN_00401170();
    int FUN_00446390();
};
struct Extra64
{
};
struct ExtraNode64
{
    Extra64* data;
    ExtraNode64* next;
    ExtraNode64();
    unsigned int FUN_005ae380();
    void FUN_005ae3d0(Extra64* const&);
};
struct Change64
{
    ExtraNode64* extras;
    int count;
    Form64* form;
    Change64();
    Change64(Form64*, int);
};
struct BaseItem64
{
    int count;
    Form64* form;
};
struct BaseNode64
{
    ~BaseNode64();
};
struct BaseContainer64
{
};
struct ChangeNode64
{
};
struct Inventory64
{
    ChangeNode64* changes;
    BaseContainer64* FUN_004bffb0();
    Change64* FUN_004c94f0(int);
};
// Walks the base container and change list, counting entries and variants, and returns a new Change for the entry at the requested index, or null.
// @fnv 0x004c94f0
Change64* Inventory64::FUN_004c94f0(int requested)
{
    Scope64 scope3(0x36, 1, ::DAT_01020778, 0x187f);
    BaseNode64* head1 = 0;
    BaseNode64* node48 = 0;
    if (((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())))
        head1 = ((::BaseNode64 *)(reinterpret_cast<::Source08 *>((((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->CopyUniqueObjects()));
    int index14 = 0;
    Change64* result1 = 0;
    BaseContainer64* baseContainer43 = ((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()));
    node48 = head1;
    while (node48 && *((::BaseItem64 **)((void *)(node48))) && !result1)
    {
        BaseItem64* base14 = *((::BaseItem64 **)((void *)(node48)));
        Form64* leveled3 = 0;
        if (base14->form->FUN_00401170() == 0x34)
            leveled3 = base14->form;
        if (base14 && !leveled3)
        {
            Change64* change32 = ((::Change64 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(base14->form), 1, 0)));
            int count9 = reinterpret_cast<::TESContainer *>((baseContainer43))->GetObjectCount((::TESObject *)(base14->form));
            if (base14 && change32 && count9 <= 0)
                result1 = 0;
            else if ((count9 < 0 && change32) || (change32 && count9 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change32))->FUN_00726070())) <= 0) ||
                     (change32 && ((::ExtraNode64 *)(::FUN_00559450((int *)(change32)))) && *((::Extra64 **)((void *)(((::ExtraNode64 *)(::FUN_00559450((int *)(change32))))))) &&
                      reinterpret_cast<::ExtraDataList *>(((*((::Extra64 **)((void *)(((::ExtraNode64 *)(::FUN_00559450((int *)(change32))))))))))->HasExtraDataType0x2F()))
                result1 = 0;
            else if (base14 && index14 == requested && (!change32 || (change32 && !reinterpret_cast<::FUN_004bca80_shell *>((change32))->CountAndPruneEntries())))
            {
                result1 = new Change64;
                if (change32)
                {
                    if (count9 < 0)
                        result1->count = count9 + change32->count;
                    else
                        result1->count = count9 + change32->count - reinterpret_cast<::FUN_004bc8f0_stand *>((change32))->FUN_004bc8f0(0);
                }
                else
                {
                    if (count9 < 0)
                        result1->count = count9 * -1;
                    else
                        result1->count = count9;
                }
                reinterpret_cast<::TESRegionGrassObject *>((result1))->AssignLandTexture((::TESLandTexture *)(base14->form));
                if (change32 &&
                    (((void *)(reinterpret_cast<::FUN_004bde40_shell *>((change32))->FUN_004bde40())) || reinterpret_cast<::FUN_004bd7a0_stand *>((change32))->FindFirstNonNegativeValue() >= 0 ||
                     ((void *)(reinterpret_cast<::FUN_004bd740_stand *>((change32))->GetExtraForm())) != reinterpret_cast<::Callees *>(this)->FUN_00726070()) &&
                    ((::ExtraNode64 *)(::FUN_00559450((int *)(change32)))) && ((::ExtraNode64 *)(::FUN_00559450((int *)(change32))))->FUN_005ae380())
                {
                    if (!result1->extras)
                        result1->extras = new ExtraNode64;
                    ExtraNode64* copyNode = ((::ExtraNode64 *)(::FUN_00559450((int *)(change32))));
                    while (copyNode && *((::Extra64 **)((void *)(copyNode))))
                    {
                        result1->extras->FUN_005ae3d0(*((::Extra64 **)((void *)(copyNode))));
                        copyNode = ((::ExtraNode64 *)(reinterpret_cast<::Callees *>((copyNode))->FUN_00726070()));
                    }
                }
            }
            else if (change32)
            {
                int variants = 0;
                if (change32->extras)
                    variants = reinterpret_cast<::FUN_004bca80_shell *>((change32))->CountAndPruneEntries();
                if (requested < variants + index14)
                {
                    ExtraNode64* variantNode = change32->extras;
                    while (variantNode && *((::Extra64 **)((void *)(variantNode))) && !result1)
                    {
                        Extra64* extra = *((::Extra64 **)((void *)(variantNode)));
                        if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra))->HasOnlyAllowedExtraData(0))
                        {
                            if (index14 == requested)
                            {
                                int extraCount = reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                                if (extraCount > count9 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change32))->FUN_00726070())))
                                    extraCount = count9 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change32))->FUN_00726070()));
                                result1 = new Change64(change32->form, extraCount);
                                result1->extras->FUN_005ae3d0(extra);
                            }
                            index14++;
                        }
                        variantNode = ((::ExtraNode64 *)(reinterpret_cast<::Callees *>((variantNode))->FUN_00726070()));
                    }
                }
                else
                {
                    index14 += reinterpret_cast<::FUN_004bca80_shell *>((change32))->CountAndPruneEntries();
                    bool skip5 = false;
                    Form64* weapon109 = 0;
                    if (((::Form64 *)(reinterpret_cast<::Twin_0044ddc0 *>((change32))->GetName()))->FUN_00401170() == 0x28)
                        weapon109 = ((::Form64 *)(reinterpret_cast<::Twin_0044ddc0 *>((change32))->GetName()));
                    if (!reinterpret_cast<::FUN_004bc8f0_stand *>((change32))->FUN_004bc8f0(0) && reinterpret_cast<::FUN_004bddd0_shell *>((change32))->FUN_004bddd0(0) &&
                        (change32->count <= 0 || ((::Form64 *)(reinterpret_cast<::Twin_0044ddc0 *>((change32))->GetName()))->FUN_00401170() == 0x29 ||
                         (weapon109 && (weapon109->FUN_00446390() == 10 || weapon109->FUN_00446390() == 11 ||
                                        weapon109->FUN_00446390() == 13))))
                        skip5 = true;
                    if (!skip5 && reinterpret_cast<::FUN_004bc8f0_stand *>((change32))->FUN_004bc8f0(1) < count9 + change32->count &&
                        (!reinterpret_cast<::InventoryStackRecord *>((change32))->HasPerkEntry() || ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change32))->FUN_00726070())) <= count9))
                    {
                        if (index14 == requested)
                        {
                            result1 = new Change64;
                            if (change32)
                                result1->count = count9 + change32->count - reinterpret_cast<::FUN_004bc8f0_stand *>((change32))->FUN_004bc8f0(0);
                            else
                                result1->count = count9;
                            reinterpret_cast<::TESRegionGrassObject *>((result1))->AssignLandTexture((::TESLandTexture *)(base14->form));
                            if (change32 && ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((change32))->FUN_004bde40())) && ((::ExtraNode64 *)(::FUN_00559450((int *)(change32)))) &&
                                ((::ExtraNode64 *)(::FUN_00559450((int *)(change32))))->FUN_005ae380())
                            {
                                if (!result1->extras)
                                    result1->extras = new ExtraNode64;
                                ExtraNode64* scriptNode = ((::ExtraNode64 *)(::FUN_00559450((int *)(change32))));
                                while (scriptNode && *((::Extra64 **)((void *)(scriptNode))))
                                {
                                    result1->extras->FUN_005ae3d0(*((::Extra64 **)((void *)(scriptNode))));
                                    scriptNode = ((::ExtraNode64 *)(reinterpret_cast<::Callees *>((scriptNode))->FUN_00726070()));
                                }
                            }
                        }
                        else
                            index14++;
                    }
                }
            }
            else
                index14++;
        }
        node48 = ((::BaseNode64 *)(reinterpret_cast<::Callees *>((node48))->FUN_00726070()));
    }
    if (head1)
    {
        reinterpret_cast<::FileMatchList *>((head1))->RemoveAll();
        delete head1;
    }
    if (!result1)
    {
        ChangeNode64* changeNode = changes;
        while (changeNode && *((::Change64 **)((void *)(changeNode))) && !result1)
        {
            Change64* entry20 = *((::Change64 **)((void *)(changeNode)));
            int baseCount13 = 0;
            if (((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) && entry20)
                baseCount13 = reinterpret_cast<::TESContainer *>((((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(entry20->form));
            if (baseCount13 < 0 && reinterpret_cast<::FUN_004bddd0_shell *>((entry20))->FUN_004bddd0(0))
                reinterpret_cast<::FUN_00419ad0_shell *>(((*((::Extra64 **)((void *)(((::ExtraNode64 *)(::FUN_00559450((int *)(entry20))))))))))->FUN_00419ad0(baseCount13 * -1);
            if (entry20 && (entry20->count > 0 || baseCount13 < 0) &&
                ((((::ExtraNode64 *)(::FUN_00559450((int *)(entry20)))) && *((::Extra64 **)((void *)(((::ExtraNode64 *)(::FUN_00559450((int *)(entry20))))))) &&
                  reinterpret_cast<::ExtraDataList *>(((*((::Extra64 **)((void *)(((::ExtraNode64 *)(::FUN_00559450((int *)(entry20))))))))))->HasExtraDataType0x2F()) ||
                 baseCount13 < 0 || !((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) || !reinterpret_cast<::TESContainer *>((((::BaseContainer64 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(entry20->form))))
            {
                int sum34 = 0;
                ExtraNode64* sumNode15 = ((::ExtraNode64 *)(::FUN_00559450((int *)(entry20))));
                while (sumNode15 && *((::Extra64 **)((void *)(sumNode15))))
                {
                    Extra64* sumExtra = *((::Extra64 **)((void *)(sumNode15)));
                    if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((sumExtra))->HasOnlyAllowedExtraData(0))
                    {
                        short sumCount = reinterpret_cast<::FUN_00418770_shell *>((sumExtra))->FUN_00418770();
                        if (sumCount > 0)
                            sum34 += sumCount;
                    }
                    sumNode15 = ((::ExtraNode64 *)(reinterpret_cast<::Callees *>((sumNode15))->FUN_00726070()));
                }
                if (((::ExtraNode64 *)(::FUN_00559450((int *)(entry20)))) && *((::Extra64 **)((void *)(((::ExtraNode64 *)(::FUN_00559450((int *)(entry20))))))) &&
                    requested < index14 + reinterpret_cast<::FUN_004bca80_shell *>((entry20))->CountAndPruneEntries())
                {
                    ExtraNode64* entryNode = entry20->extras;
                    while (entryNode && *((::Extra64 **)((void *)(entryNode))) && !result1)
                    {
                        Extra64* entryExtra = *((::Extra64 **)((void *)(entryNode)));
                        if (index14 == requested)
                        {
                            if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((entryExtra))->HasOnlyAllowedExtraData(0))
                            {
                                short selectedCount = reinterpret_cast<::FUN_00418770_shell *>((entryExtra))->FUN_00418770();
                                if (selectedCount > 0)
                                {
                                    result1 = new Change64(entry20->form, selectedCount);
                                    result1->extras->FUN_005ae3d0(entryExtra);
                                }
                            }
                        }
                        else if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((entryExtra))->HasOnlyAllowedExtraData(0) && reinterpret_cast<::FUN_00418770_shell *>((entryExtra))->FUN_00418770() > 0)
                            index14++;
                        entryNode = ((::ExtraNode64 *)(reinterpret_cast<::Callees *>((entryNode))->FUN_00726070()));
                    }
                }
                else if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry20))->FUN_00726070())) == sum34)
                    index14 += reinterpret_cast<::FUN_004bca80_shell *>((entry20))->CountAndPruneEntries();
                else
                {
                    int unused = 0;
                    if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry20))->FUN_00726070())) > sum34)
                    {
                        int remainingVariants = reinterpret_cast<::FUN_004bca80_shell *>((entry20))->CountAndPruneEntries();
                        if (remainingVariants > 0)
                            index14 += remainingVariants;
                    }
                    if (index14 == requested && !result1 && entry20->count - sum34 > 0)
                    {
                        Extra64* worn = 0;
                        result1 = new Change64(entry20->form, 0);
                        result1->count = entry20->count - sum34;
                        if (entry20->extras)
                        {
                            ExtraNode64* wornNode = entry20->extras;
                            while (wornNode && *((::Extra64 **)((void *)(wornNode))))
                            {
                                worn = *((::Extra64 **)((void *)(wornNode)));
                                if (!reinterpret_cast<::FUN_00418ab0_shell *>((worn))->FUN_00418ab0(0) && reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((worn))->HasOnlyAllowedExtraData(1))
                                    reinterpret_cast<::Callees *>((result1->extras))->FUN_00905820((void *)&(worn));
                                wornNode = ((::ExtraNode64 *)(reinterpret_cast<::Callees *>((wornNode))->FUN_00726070()));
                            }
                        }
                    }
                    else
                        index14++;
                }
            }
            changeNode = ((::ChangeNode64 *)(reinterpret_cast<::Callees *>((changeNode))->FUN_00726070()));
        }
    }
    return result1;
}


struct InventoryTrace4ca330
{
    unsigned int m_slot;
    InventoryTrace4ca330(int category, int enabled, const char* file, int line);
    ~InventoryTrace4ca330();
};

struct InventoryForm4ca330
{
    int FUN_00401170();
    int FUN_00446390();
};

struct InventoryExtra4ca330
{
};

struct InventoryNode4ca330
{
    int FUN_005ae380();
};

struct InventoryRecord4ca330
{
    InventoryNode4ca330* m_extraList;
    InventoryForm4ca330* m_form;
    unsigned int m_flags;
};

struct InventoryChange4ca330
{
    InventoryNode4ca330* m_extraList;
    int m_quantity;
    InventoryForm4ca330* m_form;

};

struct InventoryContainer4ca330
{
};

struct InventoryList4ca330
{
};

struct InventoryChangeNode4ca330
{
};

struct InventoryBaseHost4ca330
{
    InventoryChangeNode4ca330* first;
    InventoryContainer4ca330* FUN_004bffb0();
};

struct InventoryOutputExtras4ca330
{
    void* m_pFirstNode;
    void* m_pTail;
    InventoryOutputExtras4ca330();
    void FUN_005ae3d0(InventoryExtra4ca330** extra);
};

struct InventoryOutput4ca330
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330* m_form;
    InventoryOutput4ca330();
};

struct InventoryOutputFromForm4ca330
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330* m_form;
    InventoryOutputFromForm4ca330(InventoryForm4ca330* form, int count);
};

struct InventoryCursor4ca330
{
    unsigned int m_uiContentCount;
    InventoryList4ca330* m_firstNode;
    unsigned int m_unknown08;
    InventoryOutput4ca330* m_pTileTemplate;
    InventoryContainer4ca330* m_sourceContainer;
    InventoryChangeNode4ca330* m_secondPhase;
    int m_phase;
    InventoryNode4ca330* m_activeExtras;
    InventoryNode4ca330* m_extrasToCount;
    InventoryNode4ca330* m_extrasToCopy;
};

// Advances the inventory cursor through its two phases and returns the next InventoryOutput4ca330 entry, or null when exhausted.
// @fnv 0x004ca330
Entry_004d4b00* Host_004d4b00::GetNextInventoryEntry(Iterator_004d4b00* apCursor)
{
    InventoryTrace4ca330 scope(0x36, 1, DAT_01020778, 0x19c9);
    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = 0;
    if (((InventoryCursor4ca330*)apCursor)->m_phase == 0)
    {
        while (((InventoryCursor4ca330*)apCursor)->m_firstNode &&
               *((::InventoryRecord4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_firstNode))) &&
               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
        {
            InventoryRecord4ca330* pRecord = *((::InventoryRecord4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_firstNode)));
            InventoryForm4ca330* record = 0;
            bool advance = true;
            if (pRecord->m_form->FUN_00401170() == 0x34)
                record = pRecord->m_form;

            if (pRecord && !record)
            {
                InventoryChange4ca330* pChange = ((::InventoryChange4ca330 *)(reinterpret_cast<::FUN_004bfba0_shell *>((((InventoryBaseHost4ca330*)this)))->FUN_004bfba0((::TESBoundObject *)(pRecord->m_form), 1, 0)));
                int change = reinterpret_cast<::TESContainer *>((((InventoryCursor4ca330*)apCursor)->m_sourceContainer))->GetObjectCount((::TESObject *)(pRecord->m_form));

                if (pRecord && pChange && change <= 0)
                {
                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = 0;
                }
                else
                {
                    if ((change < 0 && pChange) || (pChange && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + change <= 0) ||
                        (pChange && ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange)))) && *((::InventoryExtra4ca330 **)((void *)(((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))))) &&
                         ((unsigned char)(reinterpret_cast<::ExtraDataList *>(((*((::InventoryExtra4ca330 **)((void *)(((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))))))))->HasExtraDataType0x2F()))))
                    {
                        ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = 0;
                    }
                    else if (pRecord && (!pChange || (pChange && !reinterpret_cast<::FUN_004bca80_shell *>((pChange))->CountAndPruneEntries())))
                    {
                        ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = new InventoryOutput4ca330;
                        if (pChange)
                        {
                            if (change < 0)
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                    change + pChange->m_quantity;
                            else
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                    change + pChange->m_quantity - reinterpret_cast<::FUN_004bc8f0_stand *>((pChange))->FUN_004bc8f0(0);
                        }
                        else if (change < 0)
                        {
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount = change * -1;
                        }
                        else
                        {
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount = change;
                        }
                        reinterpret_cast<::TESRegionGrassObject *>((((InventoryCursor4ca330*)apCursor)->m_pTileTemplate))->AssignLandTexture((::TESLandTexture *)(pRecord->m_form));

                        if (pChange &&
                            (((int)(reinterpret_cast<::FUN_004bde40_shell *>((pChange))->FUN_004bde40())) || reinterpret_cast<::FUN_004bd7a0_stand *>((pChange))->FindFirstNonNegativeValue() >= 0 ||
                             ((int)(reinterpret_cast<::FUN_004bd740_stand *>((pChange))->GetExtraForm())) != (int)(std::uintptr_t)((::InventoryList4ca330 *)(reinterpret_cast<::Callees *>((((InventoryBaseHost4ca330*)this)))->FUN_00726070()))))
                        {
                            if (((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange)))) && ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))->FUN_005ae380())
                            {
                                if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList)
                                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList =
                                        new InventoryOutputExtras4ca330;
                                InventoryNode4ca330* pExtraNode = ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))));
                                while (pExtraNode && *((::InventoryExtra4ca330 **)((void *)(pExtraNode))))
                                {
                                    ((InventoryCursor4ca330*)apCursor)
                                        ->m_pTileTemplate->m_extraList->FUN_005ae3d0(((::InventoryExtra4ca330 **)((void *)(pExtraNode))));
                                    pExtraNode = ((::InventoryNode4ca330 *)(reinterpret_cast<::Callees *>((pExtraNode))->FUN_00726070()));
                                }
                            }
                        }
                    }
                    else if (pChange)
                    {
                        int count = 0;
                        if (pChange->m_extraList)
                            count = reinterpret_cast<::FUN_004bca80_shell *>((pChange))->CountAndPruneEntries();
                        if (!((InventoryCursor4ca330*)apCursor)->m_activeExtras)
                            ((InventoryCursor4ca330*)apCursor)->m_activeExtras = pChange->m_extraList;
                        while (((InventoryCursor4ca330*)apCursor)->m_activeExtras &&
                               *((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_activeExtras))) &&
                               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
                        {
                            InventoryExtra4ca330* extra =
                                *((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_activeExtras)));
                            if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra))->HasOnlyAllowedExtraData(0))
                            {
                                int quantity = reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                                if (quantity > ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + change)
                                    quantity = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + change;
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate =
                                    (InventoryOutput4ca330*)new InventoryOutputFromForm4ca330(pChange->m_form,
                                                                                              quantity);
                                ((InventoryOutputExtras4ca330*)((InventoryCursor4ca330*)apCursor)
                                     ->m_pTileTemplate->m_extraList)
                                    ->FUN_005ae3d0(&extra);
                            }
                            ((InventoryCursor4ca330*)apCursor)->m_activeExtras =
                                ((::InventoryNode4ca330 *)(reinterpret_cast<::Callees *>((((InventoryCursor4ca330*)apCursor)->m_activeExtras))->FUN_00726070()));
                        }
                        advance = !((InventoryCursor4ca330*)apCursor)->m_activeExtras ||
                                  !*((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_activeExtras)));
                    }
                    else
                    {
                        reinterpret_cast<::FUN_004bca80_shell *>((pChange))->CountAndPruneEntries();
                        bool skipItem = false;
                        InventoryForm4ca330* form = 0;
                        if (((::InventoryForm4ca330 *)(reinterpret_cast<::Twin_0044ddc0 *>((pChange))->GetName()))->FUN_00401170() == 0x28)
                            form = ((::InventoryForm4ca330 *)(reinterpret_cast<::Twin_0044ddc0 *>((pChange))->GetName()));
                        if (!reinterpret_cast<::FUN_004bc8f0_stand *>((pChange))->FUN_004bc8f0(0) && reinterpret_cast<::FUN_004bddd0_shell *>((pChange))->FUN_004bddd0(0))
                        {
                            if ((pChange->m_quantity <= 0 || ((::InventoryForm4ca330 *)(reinterpret_cast<::Twin_0044ddc0 *>((pChange))->GetName()))->FUN_00401170() == 0x29) ||
                                (form && (form->FUN_00446390() == 0xa || form->FUN_00446390() == 0xb ||
                                          form->FUN_00446390() == 0xd)))
                                skipItem = true;
                        }
                        if (!skipItem && reinterpret_cast<::FUN_004bc8f0_stand *>((pChange))->FUN_004bc8f0(1) < (change + pChange->m_quantity) &&
                            (!reinterpret_cast<::InventoryStackRecord *>((pChange))->HasPerkEntry() || (int)((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) <= change))
                        {
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = new InventoryOutput4ca330;
                            if (pChange)
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                    change + pChange->m_quantity - reinterpret_cast<::FUN_004bc8f0_stand *>((pChange))->FUN_004bc8f0(0);
                            else
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount = change;
                            reinterpret_cast<::TESRegionGrassObject *>((((InventoryCursor4ca330*)apCursor)->m_pTileTemplate))->AssignLandTexture((::TESLandTexture *)(pRecord->m_form));
                            if (pChange && ((int)(reinterpret_cast<::FUN_004bde40_shell *>((pChange))->FUN_004bde40())) && ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange)))) &&
                                ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))->FUN_005ae380())
                            {
                                if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList)
                                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList =
                                        new InventoryOutputExtras4ca330;
                                InventoryNode4ca330* extraNode = ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))));
                                while (extraNode && *((::InventoryExtra4ca330 **)((void *)(extraNode))))
                                {
                                    ((InventoryCursor4ca330*)apCursor)
                                        ->m_pTileTemplate->m_extraList->FUN_005ae3d0(((::InventoryExtra4ca330 **)((void *)(extraNode))));
                                    extraNode = ((::InventoryNode4ca330 *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070()));
                                }
                            }
                        }
                    }
                }
            }
            if (advance)
                ((InventoryCursor4ca330*)apCursor)->m_firstNode =
                    ((::InventoryList4ca330 *)(reinterpret_cast<::Callees *>((((InventoryCursor4ca330*)apCursor)->m_firstNode))->FUN_00726070()));
        }
        if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
        {
            ((InventoryCursor4ca330*)apCursor)->m_phase = 1;
            ((InventoryCursor4ca330*)apCursor)->m_secondPhase = ((InventoryBaseHost4ca330*)this)->first;
        }
    }
    if (((InventoryCursor4ca330*)apCursor)->m_phase == 1 && !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
    {
        while (((InventoryCursor4ca330*)apCursor)->m_secondPhase &&
               *((::InventoryChange4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_secondPhase))) &&
               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
        {
            bool count = true;
            InventoryChange4ca330* pChange = *((::InventoryChange4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_secondPhase)));
            int advance = 0;
            if (((::InventoryContainer4ca330 *)(reinterpret_cast<::FUN_004bffb0_shell *>((((InventoryBaseHost4ca330*)this)))->FUN_004bffb0())) && pChange)
                advance = reinterpret_cast<::TESContainer *>((((::InventoryContainer4ca330 *)(reinterpret_cast<::FUN_004bffb0_shell *>((((InventoryBaseHost4ca330*)this)))->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(pChange->m_form));
            if (advance < 0 && reinterpret_cast<::FUN_004bddd0_shell *>((pChange))->FUN_004bddd0(0))
                reinterpret_cast<::FUN_00419ad0_shell *>(((*((::InventoryExtra4ca330 **)((void *)(((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))))))))->FUN_00419ad0(advance * -1);
            if (pChange && (pChange->m_quantity > 0 || advance < 0))
            {
                if ((((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange)))) && *((::InventoryExtra4ca330 **)((void *)(((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))))) &&
                     ((unsigned char)(reinterpret_cast<::ExtraDataList *>(((*((::InventoryExtra4ca330 **)((void *)(((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))))))))->HasExtraDataType0x2F()))) ||
                    advance < 0 || !((::InventoryContainer4ca330 *)(reinterpret_cast<::FUN_004bffb0_shell *>((((InventoryBaseHost4ca330*)this)))->FUN_004bffb0())) ||
                    !reinterpret_cast<::TESContainer *>((((::InventoryContainer4ca330 *)(reinterpret_cast<::FUN_004bffb0_shell *>((((InventoryBaseHost4ca330*)this)))->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(pChange->m_form)))
                {
                    int total = 0;
                    if (!((InventoryCursor4ca330*)apCursor)->m_extrasToCount)
                        ((InventoryCursor4ca330*)apCursor)->m_extrasToCount = ((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))));
                    while (((InventoryCursor4ca330*)apCursor)->m_extrasToCount &&
                           *((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_extrasToCount))))
                    {
                        InventoryExtra4ca330* extra =
                            *((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_extrasToCount)));
                        if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra))->HasOnlyAllowedExtraData(0))
                        {
                            short extraCount = reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                            if (extraCount > 0)
                                total += extraCount;
                        }
                        ((InventoryCursor4ca330*)apCursor)->m_extrasToCount =
                            ((::InventoryNode4ca330 *)(reinterpret_cast<::Callees *>((((InventoryCursor4ca330*)apCursor)->m_extrasToCount))->FUN_00726070()));
                    }
                    ((InventoryCursor4ca330*)apCursor)->m_extrasToCount = 0;
                    if (((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange)))) && *((::InventoryExtra4ca330 **)((void *)(((::InventoryNode4ca330 *)(::FUN_00559450((int *)(pChange))))))) &&
                        (!reinterpret_cast<::FUN_004bca80_shell *>((pChange))->CountAndPruneEntries() || true))
                    {
                        if (!((InventoryCursor4ca330*)apCursor)->m_extrasToCopy)
                            ((InventoryCursor4ca330*)apCursor)->m_extrasToCopy = pChange->m_extraList;
                        while (((InventoryCursor4ca330*)apCursor)->m_extrasToCopy &&
                               *((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_extrasToCopy))) &&
                               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
                        {
                            InventoryExtra4ca330* extra =
                                *((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_extrasToCopy)));
                            if (!reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra))->HasOnlyAllowedExtraData(0))
                            {
                                short quantity = reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                                if (quantity > 0)
                                {
                                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate =
                                        (InventoryOutput4ca330*)new InventoryOutputFromForm4ca330(pChange->m_form,
                                                                                                  quantity);
                                    ((InventoryCursor4ca330*)apCursor)
                                        ->m_pTileTemplate->m_extraList->FUN_005ae3d0(&extra);
                                }
                            }
                            ((InventoryCursor4ca330*)apCursor)->m_extrasToCopy =
                                ((::InventoryNode4ca330 *)(reinterpret_cast<::Callees *>((((InventoryCursor4ca330*)apCursor)->m_extrasToCopy))->FUN_00726070()));
                        }
                        count = !((InventoryCursor4ca330*)apCursor)->m_extrasToCopy ||
                                !*((::InventoryExtra4ca330 **)((void *)(((InventoryCursor4ca330*)apCursor)->m_extrasToCopy)));
                    }
                    else if ((int)((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) == total)
                    {
                        reinterpret_cast<::FUN_004bca80_shell *>((pChange))->CountAndPruneEntries();
                    }
                    if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
                    {
                        int unusedCount = 0;
                        if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) > total)
                        {
                            int extraCount = reinterpret_cast<::FUN_004bca80_shell *>((pChange))->CountAndPruneEntries();
                        }
                        if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate && (pChange->m_quantity - total) > 0)
                        {
                            InventoryExtra4ca330* residualExtra = 0;
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate =
                                (InventoryOutput4ca330*)new InventoryOutputFromForm4ca330(pChange->m_form, 0);
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                pChange->m_quantity - total;
                            if (pChange->m_extraList)
                            {
                                InventoryNode4ca330* extraNode = pChange->m_extraList;
                                while (extraNode && *((::InventoryExtra4ca330 **)((void *)(extraNode))))
                                {
                                    residualExtra = *((::InventoryExtra4ca330 **)((void *)(extraNode)));
                                    if (!reinterpret_cast<::FUN_00418ab0_shell *>((residualExtra))->FUN_00418ab0(0) && reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((residualExtra))->HasOnlyAllowedExtraData(1))
                                        reinterpret_cast<::Callees *>((((InventoryCursor4ca330*)apCursor)
                                            ->m_pTileTemplate->m_extraList))->FUN_00905820(&residualExtra);
                                    extraNode = ((::InventoryNode4ca330 *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070()));
                                }
                            }
                        }
                    }
                }
            }
            if (count)
                ((InventoryCursor4ca330*)apCursor)->m_secondPhase =
                    ((::InventoryChangeNode4ca330 *)(reinterpret_cast<::Callees *>((((InventoryCursor4ca330*)apCursor)->m_secondPhase))->FUN_00726070()));
        }
    }
    return (Entry_004d4b00*)((InventoryCursor4ca330*)apCursor)->m_pTileTemplate;
}

struct Obj4cb320;
struct ContEntry4cb320
{
    int count;
    Obj4cb320* pObj;
};
struct ContNode4cb320
{
    bool IsEmpty();
};
struct Cont4cb320
{
    ContNode4cb320* GetHead();
};
struct Change4cb320
{
    void* pExtraLists;
    int m_iCountChange;
    Obj4cb320* pObj;
};
struct ChangeNode4cb320
{
    bool IsEmpty();
};
struct Inv4cb320
{
    ChangeNode4cb320* m_pEntryList;
    int GetCountableItemCount();
};

// @fnv 0x004cb320
int Inv4cb320::GetCountableItemCount()
{
    Obj4cb320* pObj7 = 0;
    int iTotal = 0;
    Cont4cb320* pCont3 = ((::Cont4cb320 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()));
    ContNode4cb320* pNode = pCont3 ? pCont3->GetHead() : 0;
    while (pNode && !pNode->IsEmpty())
    {
        pObj7 = (*((::ContEntry4cb320 **)((void *)(pNode))))->pObj;
        if (pObj7 && ::FUN_00481f10((::TESObject *)(pObj7)))
        {
            Change4cb320* pChange = ((::Change4cb320 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(pObj7), 1, 0)));
            if (pChange)
            {
                iTotal += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070())) + (*((::ContEntry4cb320 **)((void *)(pNode))))->count;
            }
            else
            {
                if ((iTotal += (*((::ContEntry4cb320 **)((void *)(pNode))))->count) < 0)
                    iTotal = iTotal * -1;
            }
        }
        pNode = ((::ContNode4cb320 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    ChangeNode4cb320* pChangeNode4 = m_pEntryList;
    while (pChangeNode4 && !pChangeNode4->IsEmpty())
    {
        pObj7 = (*((::Change4cb320 **)((void *)(pChangeNode4))))->pObj;
        if (pObj7 && ::FUN_00481f10((::TESObject *)(pObj7)))
        {
            if (!pCont3 || (!reinterpret_cast<::TESContainer *>((pCont3))->HasObjectOfType((::TESObject *)(pObj7)) && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::Change4cb320 **)((void *)(pChangeNode4))))))->FUN_00726070())) > 0))
                iTotal += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::Change4cb320 **)((void *)(pChangeNode4))))))->FUN_00726070()));
        }
        pChangeNode4 = ((::ChangeNode4cb320 *)(reinterpret_cast<::Callees *>((pChangeNode4))->FUN_00726070()));
    }
    return iTotal;
}

struct CO4cb4b0
{
    int count;
    TESObject* pObj;
};
struct CN4cb4b0
{
    bool _ref_008256d0();
};
struct Cont4cb4b0
{
    CN4cb4b0* _ref_00717e50();
};
struct IC4cb4b0
{
    int unk00;
    int count;
    TESObject* pObj;
};
struct IN4cb4b0
{
    bool _ref_008256d0();
};
struct Inv4cb4b0
{
    IN4cb4b0* m_pEntryList;
    void FUN_004cb4b0(std::intptr_t a1, int a2, std::intptr_t a3);
};

namespace InventoryCopy {
struct FUN_004bc550;
typedef FUN_004bc550 Item;
struct FUN_00410360;
typedef FUN_00410360 Extra;
struct ExtraNode;
struct BaseNode;
struct ItemNode;
struct Container;
struct Inventory;
struct FormView
{
    int FUN_00401170();
};
struct CopiedForm
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108(TESBoundObject*);
};
struct FUN_00410360
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360();
};
typedef FUN_00410360 Extra;
struct ExtraNode
{
    int FUN_005ae380();
};
struct FUN_004bc550
{
    ExtraNode* list;
    int count;
    TESBoundObject* form;
    FUN_004bc550(TESBoundObject*, int);
};
typedef FUN_004bc550 Item;
struct BaseEntry
{
    int count;
    TESBoundObject* form;
};
struct BaseNode
{
    bool FUN_008256d0();
};
struct ItemNode
{
    bool FUN_008256d0();
};
struct Container
{
    BaseNode* FUN_00717e50();
};
struct Registry
{
};
struct Inventory
{
    ItemNode* head;
    Container* FUN_004bffb0();
    void FUN_004cd9c0(void*, void*);
};
// @fnv 0x004cd9c0
void Inventory::FUN_004cd9c0(void* source, void* destination)
{
    if (!destination || !source)
        return;
    TESBoundObject* formSlot11 = 0;
    Item* copySlot14 = 0;
    Inventory* targetSlot4 = 0;
    targetSlot4 = ((::InventoryCopy::Inventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(destination))));
    if (!targetSlot4)
        return;
    BaseNode* baseSlot45 = ((::InventoryCopy::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    TESLevItem* leveledSlot24 = 0;
    while (baseSlot45 && !baseSlot45->FUN_008256d0())
    {
        formSlot11 = (*((::InventoryCopy::BaseEntry **)((void *)(baseSlot45))))->form;
        leveledSlot24 = dynamic_cast<TESLevItem*>((*((::InventoryCopy::BaseEntry **)((void *)(baseSlot45))))->form);
        if (formSlot11)
        {
            int baseCountSlot31 = reinterpret_cast<::TESContainer *>((((::InventoryCopy::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(formSlot11));
            Item* itemSlot25 = ((::InventoryCopy::FUN_004bc550 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(formSlot11, 1, 0)));
            int totalSlot2 = 0;
            int magnitudeSlot60 = baseCountSlot31;
            if (magnitudeSlot60 < 0)
                magnitudeSlot60 *= -1;
            if (itemSlot25)
                totalSlot2 += magnitudeSlot60 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemSlot25))->FUN_00726070()));
            else
                totalSlot2 += magnitudeSlot60;
            if (totalSlot2 > 0)
            {
                CopiedForm* clone = 0;
                if (((void *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(formSlot11)))))
                {
                    clone = ((::InventoryCopy::CopiedForm *)(::TESDataHandler::CreateFormForType(((FormView*)formSlot11)->FUN_00401170())));
                    clone->v108(formSlot11);
                    ::FUN_004ce300((::TESForm *)(clone), 0);
                    reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::InventoryCopy::Registry * *>(&::g_dataHandler))))->AddFormToDataHandler((::TESForm *)(clone));
                    reinterpret_cast<::fnv_00861780::FUN_00861780_StandIn *>(((*reinterpret_cast<::InventoryCopy::Registry * *>(&::g_TESSaveLoadGame))))->Add((::TESForm *)(clone));
                    int quantity = baseCountSlot31;
                    if (itemSlot25)
                        quantity += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemSlot25))->FUN_00726070()));
                    copySlot14 = new Item((TESBoundObject*)clone, quantity);

                    if (itemSlot25 && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(itemSlot25)))) && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(itemSlot25))))->FUN_005ae380())
                    {
                        ExtraNode* nodeA = ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(itemSlot25))));
                        if (nodeA && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeA))))
                        {
                            while (nodeA && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeA))))
                            {
                                Extra* extraASlot11 = new Extra;
                                void* removedASlot21 = ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(((*((::InventoryCopy::FUN_00410360 **)((void *)(nodeA))))))->FUN_00410220(0xd)));
                                if (removedASlot21)
                                    reinterpret_cast<::FUN_00410020_t *>(((*((::InventoryCopy::FUN_00410360 **)((void *)(nodeA))))))->FUN_00410020((::BSExtraData *)(removedASlot21), 0);
                                reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraASlot11))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360 **)((void *)(nodeA)))), 1);
                                reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraASlot11);
                                if (removedASlot21)
                                    reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(((*((::InventoryCopy::FUN_00410360 **)((void *)(nodeA))))))->FUN_0040ff60((::BSExtraData *)(removedASlot21));
                                nodeA = ((::InventoryCopy::ExtraNode *)(reinterpret_cast<::Callees *>((nodeA))->FUN_00726070()));
                            }
                        }
                    }
                }
                else
                {
                    copySlot14 = new Item(formSlot11, totalSlot2);
                    if (itemSlot25 && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(itemSlot25)))) && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(itemSlot25))))->FUN_005ae380())
                    {
                        ExtraNode* nodeB = ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(itemSlot25))));
                        if (nodeB && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeB))))
                        {
                            while (nodeB && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeB))))
                            {
                                Extra* extraB = new Extra;
                                reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraB))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360 **)((void *)(nodeB)))), 1);
                                reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraB);
                                nodeB = ((::InventoryCopy::ExtraNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
                            }
                        }
                    }
                }
                reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((targetSlot4))->FUN_004c3380((::InventoryStackRecord *)(copySlot14), 1);
            }
        }
        baseSlot45 = ((::InventoryCopy::BaseNode *)(reinterpret_cast<::Callees *>((baseSlot45))->FUN_00726070()));
    }
    Item* changedSlot20 = 0;
    ItemNode* nodeSlot26 = head;
    while (nodeSlot26 && !nodeSlot26->FUN_008256d0())
    {
        changedSlot20 = *((::InventoryCopy::FUN_004bc550 **)((void *)(nodeSlot26)));
        if (changedSlot20 && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changedSlot20))->FUN_00726070())) > 0)
        {
            formSlot11 = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName()));
            reinterpret_cast<::AGOwner *>((changedSlot20))->FUN_004bcd10();
            CopiedForm* clone2 = 0;
            if (((void *)(reinterpret_cast<::FUN_004bde40_shell *>((changedSlot20))->FUN_004bde40())))
            {
                clone2 = ((::InventoryCopy::CopiedForm *)(::TESDataHandler::CreateFormForType(((FormView*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName())))->FUN_00401170())));
                clone2->v108(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName())));
                ::FUN_004ce300((::TESForm *)(clone2), 0);
                reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::InventoryCopy::Registry * *>(&::g_dataHandler))))->AddFormToDataHandler((::TESForm *)(clone2));
                reinterpret_cast<::fnv_00861780::FUN_00861780_StandIn *>(((*reinterpret_cast<::InventoryCopy::Registry * *>(&::g_TESSaveLoadGame))))->Add((::TESForm *)(clone2));
                copySlot14 = new Item((TESBoundObject*)clone2, ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changedSlot20))->FUN_00726070())));
                if (changedSlot20 && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(changedSlot20)))) && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(changedSlot20))))->FUN_005ae380())
                {
                    ExtraNode* nodeC = ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(changedSlot20))));
                    if (nodeC && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeC))))
                    {
                        while (nodeC && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeC))))
                        {
                            Extra* extraCSlot22 = new Extra;
                            void* removedCSlot8 = ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(((*((::InventoryCopy::FUN_00410360 **)((void *)(nodeC))))))->FUN_00410220(0xd)));
                            if (removedCSlot8)
                                reinterpret_cast<::FUN_00410020_t *>(((*((::InventoryCopy::FUN_00410360 **)((void *)(nodeC))))))->FUN_00410020((::BSExtraData *)(removedCSlot8), 0);
                            reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraCSlot22))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360 **)((void *)(nodeC)))), 1);
                            reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraCSlot22);
                            if (removedCSlot8)
                                reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(((*((::InventoryCopy::FUN_00410360 **)((void *)(nodeC))))))->FUN_0040ff60((::BSExtraData *)(removedCSlot8));
                            nodeC = ((::InventoryCopy::ExtraNode *)(reinterpret_cast<::Callees *>((nodeC))->FUN_00726070()));
                        }
                    }
                }
            }
            else
            {
                copySlot14 = new Item(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName())), ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changedSlot20))->FUN_00726070())));
                if (changedSlot20 && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(changedSlot20)))) && ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(changedSlot20))))->FUN_005ae380())
                {
                    ExtraNode* nodeD = ((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(changedSlot20))));
                    if (nodeD && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeD))))
                    {
                        while (nodeD && *((::InventoryCopy::FUN_00410360 **)((void *)(nodeD))))
                        {
                            Extra* extraD = new Extra;
                            reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraD))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360 **)((void *)(nodeD)))), 1);
                            reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraD);
                            nodeD = ((::InventoryCopy::ExtraNode *)(reinterpret_cast<::Callees *>((nodeD))->FUN_00726070()));
                        }
                    }
                }
            }
            reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((targetSlot4))->FUN_004c3380((::InventoryStackRecord *)(copySlot14), 1);
            copySlot14 = 0;
        }
        nodeSlot26 = ((::InventoryCopy::ItemNode *)(reinterpret_cast<::Callees *>((nodeSlot26))->FUN_00726070()));
    }
}
}

struct MoveForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual bool IsQuestItem();
    int FUN_00401170();
};
struct MoveOwner;
struct MoveOwnershipProxy
{
};
struct MoveExtra
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MoveExtra();
    void FUN_00419700(void*);
};
struct MoveExtraNode
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    unsigned int FUN_005ae380();
    ~MoveExtraNode();
};
struct MoveItem
{
    MoveExtraNode* head;
    int count;
    TESBoundObject* form;
    MoveItem(TESBoundObject*, int);
};
struct MoveItemNode
{
    bool FUN_008256d0();
};
struct MoveBaseEntry
{
    int count;
    TESBoundObject* form;
};
struct MoveBaseNode
{
    bool FUN_008256d0();
};
struct MoveContainer
{
    MoveBaseNode* FUN_00717e50();
};
struct MoveOwner
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool IsActor();
};
struct MoveFilterResult
{
};
struct MoveFilter
{
};
struct MoveFormInfo
{
};
struct MoveString
{
    char* text;
    unsigned short length, capacity;
    MoveString();
    ~MoveString();
};
struct MoveSetting
{
    const char* FUN_00403df0();
};
struct InventoryMove
{
    MoveItemNode* head;
    MoveContainer* FUN_004bffb0();
    float FUN_004ce380(MoveOwner*, MoveOwner*, bool, bool, bool, bool, int, MoveFilter*);
};
union SETTING_VALUE
{
    float f;
};
template <> class SettingT<GameSettingCollection>
{
  public:
};
struct WeightExtra
{
};
struct WeightExtraNode
{
};
struct WeightWeapon
{
};
struct WeightEntry : InventoryStackRecord
{
};
struct WeightChangeNode
{
    bool FUN_008256d0();
};
struct WeightBaseEntry
{
    int count_2;
    TESBoundObject* form4;
};
struct WeightBaseNode
{
    bool FUN_008256d0();
};
struct WeightContainer
{
    WeightBaseNode* FUN_00717e50();
};
struct WeightInventory : InventoryChanges
{
    WeightContainer* FUN_004bffb0();
    float FUN_004d0900(bool useAmmoWeight);
};
// @fnv 0x004d0900
float WeightInventory::FUN_004d0900(bool useAmmoWeight)
{
    Actor* actorTmp = 0;
    if (pRef->IsActor())
        actorTmp = (Actor*)pRef;
    bool value4 = false;
    float value3 = 0.0f;
    ::ApplyPerkModifiers(0x37, (::Actor *)(char *)((char*)actorTmp), &value3);
    float scaleA = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting32))))->f;
    float valueTmp = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting31))))->f;
    if (value3 > 0.0)
        value4 = true;
    if (m_fTotalWeight == -1.0)
    {
        float result5 = 0.0f;
        float valueA = 0.0f;
        float resultB = 0.0f;
        WeightBaseNode* nodeX = ((::WeightContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
        while (nodeX && !nodeX->FUN_008256d0())
        {
            TESBoundObject* form4 = (*((::WeightBaseEntry **)((void *)(nodeX))))->form4;
            WeightEntry* item9 = ((::WeightEntry *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(form4, 1, 0)));
            if (!((TESForm*)form4)->IsQuestItem())
            {
                if (((ObjectForm*)form4)->FUN_00401170() == 0x28 && item9)
                {
                    ObjectForm* weaponTmp = (ObjectForm*)form4;
                    valueA = reinterpret_cast<::TESObjectWEAP *>((weaponTmp))->GetWeightForForm(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((item9))->HasEffect(4))));
                    if (valueA >= 10.0)
                    {
                        float multiplier = 1.0f;
                        ::ApplyPerkModifiers(0x49, (::Actor *)((*reinterpret_cast<char * *>(&::_g_thePlayer))), &multiplier);
                        valueA *= multiplier;
                    }
                }
                else
                {
                    valueA = ::TESWeightForm::GetWeightForForm((::TESForm *)(form4), useAmmoWeight);
                }
                if (valueA == -1.0)
                    valueA = 0.0f;
                if (value4 && valueA <= valueTmp)
                    valueA *= scaleA;
                if (!item9)
                {
                    result5 += (*((::WeightBaseEntry **)((void *)(nodeX))))->count_2 * valueA;
                }
                else if (item9 && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((item9))->FUN_00726070())) + (*((::WeightBaseEntry **)((void *)(nodeX))))->count_2)
                {
                    result5 += (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((item9))->FUN_00726070())) + (*((::WeightBaseEntry **)((void *)(nodeX))))->count_2) * valueA;
                }
            }
            nodeX = ((::WeightBaseNode *)(reinterpret_cast<::Callees *>((nodeX))->FUN_00726070()));
        }
        WeightChangeNode* nodeA = (WeightChangeNode*)m_pEntryList;
        while (nodeA && !nodeA->FUN_008256d0() && *((::WeightEntry **)((void *)(nodeA))))
        {
            bool current = false;
            WeightEntry* item7 = *((::WeightEntry **)((void *)(nodeA)));
            TESBoundObject* form4 = item7->m_pItemObject;
            if (form4 && (!((::WeightContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) || !reinterpret_cast<::TESContainer *>((((::WeightContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(form4))) && !((TESForm*)form4)->IsQuestItem())
            {
                if (((ObjectForm*)form4)->FUN_00401170() == 0x28)
                {
                    current = true;
                    resultB = reinterpret_cast<::TESObjectWEAP *>((((ObjectForm*)form4)))->GetWeightForForm(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((item7))->HasEffect(4))));
                    valueA = ::TESWeightForm::GetWeightForForm((::TESForm *)(form4), useAmmoWeight);
                    if (valueA >= 10.0)
                    {
                        float multiplier = 1.0f;
                        ::ApplyPerkModifiers(0x49, (::Actor *)((*reinterpret_cast<char * *>(&::_g_thePlayer))), &multiplier);
                        valueA *= multiplier;
                    }
                    if (resultB >= 10.0)
                    {
                        float multiplier = 1.0f;
                        ::ApplyPerkModifiers(0x49, (::Actor *)((*reinterpret_cast<char * *>(&::_g_thePlayer))), &multiplier);
                        resultB *= multiplier;
                    }
                }
                else
                {
                    valueA = ::TESWeightForm::GetWeightForForm((::TESForm *)(form4), useAmmoWeight);
                }
                if (valueA > 0.0)
                {
                    if (value4 && valueA <= valueTmp)
                        valueA *= scaleA;
                    if (value4 && resultB <= valueTmp)
                        resultB *= scaleA;
                    TESBoundObject* formX = 0;
                    if (form4 && ((ObjectForm*)form4)->FUN_00401170() == 0x18)
                        formX = form4;
                    int count_2 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((item7))->FUN_00726070()));
                    if (((::WeightExtraNode *)(::FUN_00559450((int *)(item7)))) && current && reinterpret_cast<::FUN_004bc8f0_stand *>((item7))->FUN_004bc8f0(true) > 0)
                    {
                        WeightWeapon* weaponTmp = ((::WeightWeapon *)(reinterpret_cast<::Twin_0044ddc0 *>((item7))->GetName()));
                        int countTmp = 0;
                        WeightExtraNode* extra2 = ((::WeightExtraNode *)(::FUN_00559450((int *)(item7))));
                        while (extra2)
                        {
                            WeightExtra* extra = *((::WeightExtra **)((void *)(extra2)));
                            if (extra && reinterpret_cast<::FUN_00418ba0_shell *>((extra))->FUN_00418ba0())
                            {
                                if (reinterpret_cast<::C418C00ExtraList *>((extra))->CheckExtraByType(1) && ((int)(reinterpret_cast<::FUN_004bd880_stand *>((weaponTmp))->GetSlotPointer(1))) == 4)
                                    countTmp += reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                                if (reinterpret_cast<::C418C00ExtraList *>((extra))->CheckExtraByType(2) && ((int)(reinterpret_cast<::FUN_004bd880_stand *>((weaponTmp))->GetSlotPointer(2))) == 4)
                                    countTmp += reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                                if (reinterpret_cast<::C418C00ExtraList *>((extra))->CheckExtraByType(4) && ((int)(reinterpret_cast<::FUN_004bd880_stand *>((weaponTmp))->GetSlotPointer(4))) == 4)
                                    countTmp += reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                            }
                            extra2 = ((::WeightExtraNode *)(reinterpret_cast<::Callees *>((extra2))->FUN_00726070()));
                        }
                        int normal9 = count_2 - countTmp;
                        valueA = normal9 * valueA + countTmp * resultB;
                    }
                    else if (current)
                    {
                        valueA = count_2 * valueA;
                    }
                    if (actorTmp && formX && reinterpret_cast<::FUN_004bddd0_shell *>((item7))->FUN_004bddd0(false))
                    {
                        float wornWeight = valueA;
                        if (count_2 > 0)
                        {
                            result5 += wornWeight;
                            count_2 = count_2 - 1;
                        }
                    }
                    if (count_2 > 0 && !current)
                        result5 += count_2 * valueA;
                    else if (count_2)
                        result5 += valueA;
                }
            }
            nodeA = ((::WeightChangeNode *)(reinterpret_cast<::Callees *>((nodeA))->FUN_00726070()));
        }
        m_fTotalWeight = result5;
        if (actorTmp)
            ::fnv_008ba2f0::FUN_008ba2f0((::fnv_008ba2f0::ActorValueOwner *)(actorTmp), 0x2e, m_fArmorWeight);
    }
    return m_fTotalWeight;
}

struct ValueForm : TESForm
{
    int FUN_0084e3a0();
};
struct ValueBaseEntry
{
    int count;
    ValueForm* object;
};
struct ValueBaseNode
{
    bool FUN_008256d0();
};
struct ValueChange : InventoryStackRecord
{
};
struct ValueChangeNode
{
    bool FUN_008256d0();
};
struct ValueContainer
{
    ValueBaseNode* FUN_00717e50();
};
struct ValueInventory : InventoryChanges
{
    ValueContainer* FUN_004bffb0();
    int FUN_004d0f40(bool includeQuestItems, bool includeType15);
};

// @fnv 0x004d0f40
int ValueInventory::FUN_004d0f40(bool includeQuestItems, bool includeType15)
{
    int changeNode = 0;
    ValueBaseNode* baseNode = ((::ValueContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    while (baseNode && !baseNode->FUN_008256d0())
    {
        ValueForm* object = (*((::ValueBaseEntry **)((void *)(baseNode))))->object;
        if ((includeQuestItems || !object->IsQuestItem()) && (includeType15 || reinterpret_cast<::FUN_0084e3a0_Class *>((object))->FUN_0084e3a0() != 15))
        {
            int value = ::FUN_0048e8a0((::TESForm *)(object));
            if (value == -1)
                value = 0;
            if (value)
            {
                ValueChange* change = ((::ValueChange *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(object), 1, 0)));
                if (!change)
                    changeNode += value * (*((::ValueBaseEntry **)((void *)(baseNode))))->count;
                else if (change && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change))->FUN_00726070())) + (*((::ValueBaseEntry **)((void *)(baseNode))))->count)
                    changeNode += (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change))->FUN_00726070())) + (*((::ValueBaseEntry **)((void *)(baseNode))))->count) * value;
            }
        }
        baseNode = ((::ValueBaseNode *)(reinterpret_cast<::Callees *>((baseNode))->FUN_00726070()));
    }
    ValueChangeNode* total = (ValueChangeNode*)m_pEntryList;
    while (total && !total->FUN_008256d0() && *((::ValueChange **)((void *)(total))))
    {
        ValueChange* object = *((::ValueChange **)((void *)(total)));
        ValueForm* change = (ValueForm*)object->m_pItemObject;
        if (change && (!((::ValueContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) || !reinterpret_cast<::TESContainer *>((((::ValueContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(change))) &&
            (includeQuestItems || !change->IsQuestItem()) && (includeType15 || reinterpret_cast<::FUN_0084e3a0_Class *>((change))->FUN_0084e3a0() != 15))
        {
            int value = ::FUN_0048e8a0((::TESForm *)(change));
            if (value == -1)
                value = 0;
            if (value && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((object))->FUN_00726070())))
                changeNode += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((object))->FUN_00726070())) * value;
        }
        total = ((::ValueChangeNode *)(reinterpret_cast<::Callees *>((total))->FUN_00726070()));
    }
    return changeNode;
}

struct Extra4d1440
{
};
struct Entry4d1440
{
    int count;
    TESForm* pObj;
    Extra4d1440* m_pExtraData;
};
struct Node4d1440
{
    bool _ref_008256d0();
};
struct Cont4d1440
{
    Node4d1440* FUN_00717e50();
};
struct List4d1440
{
    int unk00;
    int unk04;
    int unk08;
    List4d1440();
    ~List4d1440();
};
struct LevList4d1440
{
};
struct LevItem4d1440
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    LevList4d1440 leveledList;
};
struct Ref4d1440
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
};
struct Inv4d1440 : public InventoryChanges
{
    Cont4d1440* FUN_004bffb0();
    bool HasExtraDataWithValue(int);
    void FUN_004d1440();
};

// @fnv 0x004d1440
void Inv4d1440::FUN_004d1440()
{
    Node4d1440* node = ((::Cont4d1440 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    int index = 0;
    int level = 0;
    if (((::Ref4d1440 *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))->IsActor())
    {
        level = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((::Ref4d1440 *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->FUN_0087f9f0();
    }
    else
    {
        level = ((int)(reinterpret_cast<::fnv_00567e10::FUN_00567e10_shell *>((((::Ref4d1440 *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->FUN_00567e10(true)));
    }
    while (node && !node->_ref_008256d0())
    {
        Entry4d1440* pEntry = *((::Entry4d1440 **)((void *)(node)));
        LevItem4d1440* levItem = 0;
        if (pEntry->pObj && FNV_GetFormType(pEntry->pObj) == 0x34)
        {
            levItem = (LevItem4d1440*)pEntry->pObj;
        }
        if (levItem)
        {
            if (!HasExtraDataWithValue(index))
            {
                List4d1440 list;
                reinterpret_cast<::TESLeveledList *>(&(levItem->leveledList))->PopulateContainerWithLeveledItems(level, std::abs(pEntry->count), (::TESContainer *)(::List4d1440 *)(&list), 0);
                if (pEntry && pEntry->m_pExtraData && reinterpret_cast<::BSFaceGenKeyframe *>((pEntry->m_pExtraData))->GetTime() != 1.0)
                {
                    reinterpret_cast<::fnv_00482090::FUN_00482090_shell *>(&(list))->FUN_00482090(reinterpret_cast<::BSFaceGenKeyframe *>((pEntry->m_pExtraData))->GetTime());
                }
                reinterpret_cast<::fnv_00482770::FUN_00482770_shell *>(&(list))->AddLeveledItemsToChanges(index, (::fnv_00482770::InventoryChanges *)(::InventoryChanges *)(this));
            }
            index++;
        }
        node = ((::Node4d1440 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}

namespace InventoryTransfer {
struct Extra;
struct ExtraNode;
struct Item;
struct Inventory;
struct AutoMemContext
{
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
struct Form
{

    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual bool v094();
};
struct Extra
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Extra();
};
struct ExtraNode
{
    Extra* value;
    ExtraNode* next;
    ExtraNode();
    void FUN_005ae3d0(Extra**);
};
struct Item
{
    ExtraNode* list;
    int count;
    TESBoundObject* form;
    Item();
    ~Item();
};
struct BaseEntry
{
    int count;
    TESBoundObject* form;
};
struct BaseNode
{
};
struct ItemNode
{
};
struct Container
{
    BaseNode* FUN_00717e50();
};
struct Inventory
{
    ItemNode* head;
    Container* FUN_004bffb0();
    void FUN_004d26d0(Inventory*, void*, bool);
};
// Moves items from the base container and the inventory list into target, rebuilding extra lists and counts and skipping leveled or excluded items.
// @fnv 0x004d26d0
void Inventory::FUN_004d26d0(Inventory* target, void* owner, bool exclude)
{
    AutoMemContext contextSlot2(0x36, true, ::DAT_01020778, 0x26b7);
    BaseNode* baseSlot2 = ((::InventoryTransfer::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    Item* transferSlot3 = 0;
    while (baseSlot2 && *((::InventoryTransfer::BaseEntry **)((void *)(baseSlot2))))
    {
        BaseEntry* entrySlot7 = *((::InventoryTransfer::BaseEntry **)((void *)(baseSlot2)));
        TESLevItem* leveledSlot21 = dynamic_cast<TESLevItem*>(entrySlot7->form);
        transferSlot3 = new Item;
        int baseCountSlot38 = reinterpret_cast<::TESContainer *>((((::InventoryTransfer::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(entrySlot7->form));
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode;
        if (entrySlot7 && !leveledSlot21)
        {
            Item* current = ((::InventoryTransfer::Item *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(entrySlot7->form, 1, 0)));
            if (current)
                reinterpret_cast<::FUN_004bcbd0_Class *>((current))->ProcessNodes();
            if (entrySlot7 && current &&
                (((!reinterpret_cast<::InventoryStackRecord *>((current))->HasPerkEntry() || reinterpret_cast<::FUN_004bcc30_List *>((current))->FUN_004bcc30() < 1) && current->count + baseCountSlot38 == 0) ||
                 (((::InventoryTransfer::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((current))->GetName()))->v094() && exclude) || reinterpret_cast<::FUN_004bddd0_shell *>((current))->FUN_004bddd0(0)))
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
            else if (entrySlot7 && (!current || (current && !reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0))))
            {
                int magnitude = baseCountSlot38;
                if (magnitude < 0)
                    magnitude *= -1;
                if (current)
                    transferSlot3->count = magnitude + current->count - reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0);
                else
                    transferSlot3->count = magnitude;
                reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(entrySlot7->form));
                if (current && ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((current))->FUN_004bde40())))
                {
                    ExtraNode* scripted = ((::InventoryTransfer::ExtraNode *)(::FUN_00559450((int *)(current))));
                    while (scripted && *((::InventoryTransfer::Extra **)((void *)(scripted))))
                    {
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>(((*((::InventoryTransfer::Extra **)((void *)(scripted))))))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::Callees *>((transferSlot3->list))->FUN_00905820(((::InventoryTransfer::Extra **)((void *)(scripted))));
                        scripted = ((::InventoryTransfer::ExtraNode *)(reinterpret_cast<::Callees *>((scripted))->FUN_00726070()));
                    }
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                }
                else
                {
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    {
                        Extra* extraA = new Extra;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraA))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraA))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferSlot3))->FUN_00726070())));
                        transferSlot3->list->FUN_005ae3d0(&extraA);
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else if (current)
            {
                int extraCountSlot33 = 0;
                if (current->list)
                    extraCountSlot33 = reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0);
                ExtraNode* extrasSlot23 = current->list;
                while (extrasSlot23 && *((::InventoryTransfer::Extra **)((void *)(extrasSlot23))) && !transferSlot3)
                {
                    Extra* extraB = *((::InventoryTransfer::Extra **)((void *)(extrasSlot23)));
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(current->form));
                    reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(std::uintptr_t)(reinterpret_cast<::FUN_00418770_shell *>((extraB))->FUN_00418770()));
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode;
                    reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraB))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                    transferSlot3->list->FUN_005ae3d0(&extraB);
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    extrasSlot23 = ((::InventoryTransfer::ExtraNode *)(reinterpret_cast<::Callees *>((extrasSlot23))->FUN_00726070()));
                }
                if (reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0) < baseCountSlot38 + current->count)
                {
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode;
                    if (current)
                        transferSlot3->count = baseCountSlot38 + current->count - reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0);
                    else
                        transferSlot3->count = baseCountSlot38;
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(entrySlot7->form));
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    {
                        Extra* extraC = new Extra;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraC))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraC))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferSlot3))->FUN_00726070())));
                        transferSlot3->list->FUN_005ae3d0(&extraC);
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        baseSlot2 = ((::InventoryTransfer::BaseNode *)(reinterpret_cast<::Callees *>((baseSlot2))->FUN_00726070()));
    }
    ItemNode* nodeSlot1 = head;
    while (nodeSlot1 && *((::InventoryTransfer::Item **)((void *)(nodeSlot1))))
    {
        transferSlot3 = new Item;
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode;
        Item* changed = *((::InventoryTransfer::Item **)((void *)(nodeSlot1)));
        if (changed && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())) > 0 && (!((::InventoryTransfer::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) || !reinterpret_cast<::TESContainer *>((((::InventoryTransfer::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(changed->form))))
        {
            if (reinterpret_cast<::FUN_004bc8f0_stand *>((changed))->FUN_004bc8f0(0) || ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((changed))->FUN_004bde40())))
            {
                ExtraNode* walkSlot1 = changed->list;
                int countSlot56 = 0;
                bool hasSpecialSlot4 = false;
                while (walkSlot1 && *((::InventoryTransfer::Extra **)((void *)(walkSlot1))))
                {
                    if (((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(((*((::InventoryTransfer::Extra **)((void *)(walkSlot1))))))->FUN_00410220(0x2f))))
                        hasSpecialSlot4 = true;
                    walkSlot1 = ((::InventoryTransfer::ExtraNode *)(reinterpret_cast<::Callees *>((walkSlot1))->FUN_00726070()));
                }
                walkSlot1 = changed->list;
                if (!hasSpecialSlot4 || ((int)(reinterpret_cast<::FUN_004be1a0_Class *>((changed))->GetFormTypeCategory())) != 4)
                {
                    while (walkSlot1 && *((::InventoryTransfer::Extra **)((void *)(walkSlot1))))
                    {
                        Extra* extraD = *((::InventoryTransfer::Extra **)((void *)(walkSlot1)));
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraD))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        transferSlot3->list->FUN_005ae3d0(&extraD);
                        walkSlot1 = ((::InventoryTransfer::ExtraNode *)(reinterpret_cast<::Callees *>((walkSlot1))->FUN_00726070()));
                        countSlot56 += reinterpret_cast<::FUN_00418770_shell *>((extraD))->FUN_00418770();
                    }
                }
                else
                {
                    if (((int)(reinterpret_cast<::FUN_004be1a0_Class *>((changed))->GetFormTypeCategory())) == 4 && ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((changed))->FUN_004bde40())))
                        reinterpret_cast<::CombatProcedure *>((changed))->Initialize((::CombatController *)(1));
                    while (walkSlot1 && *((::InventoryTransfer::Extra **)((void *)(walkSlot1))))
                    {
                        Extra* extraE = *((::InventoryTransfer::Extra **)((void *)(walkSlot1)));
                        reinterpret_cast<::FUN_0041af10_Class *>((extraE))->RemoveExtra24();
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraE))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        transferSlot3->list->FUN_005ae3d0(&extraE);
                        walkSlot1 = ((::InventoryTransfer::ExtraNode *)(reinterpret_cast<::Callees *>((walkSlot1))->FUN_00726070()));
                        countSlot56 = 1;
                    }
                }
                reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(changed->form));
                reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0) && countSlot56 < ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())))
                {
                    Extra* extraF = new Extra;
                    reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraF))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                    reinterpret_cast<::FUN_00419ad0_shell *>((extraF))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())) - countSlot56);
                    transferSlot3->list->FUN_005ae3d0(&extraF);
                }
                if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                else
                {
                    if (*((::InventoryTransfer::Extra **)((void *)(transferSlot3->list))))
                        reinterpret_cast<::FUN_00418600_cls *>(((*((::InventoryTransfer::Extra **)((void *)(transferSlot3->list))))))->FUN_00418600();
                    delete transferSlot3;
                    transferSlot3 = 0;
                }
            }
            else
            {
                Extra* chosen = 0;
                if (changed->list)
                {
                    ExtraNode* walk2Slot3 = changed->list;
                    int count2Slot41 = 0;
                    while (walk2Slot3 && *((::InventoryTransfer::Extra **)((void *)(walk2Slot3))) && !chosen)
                    {
                        chosen = *((::InventoryTransfer::Extra **)((void *)(walk2Slot3)));
                        count2Slot41 += reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770();
                        if (reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((chosen))->HasOnlyAllowedExtraData(0))
                            chosen = 0;
                        walk2Slot3 = ((::InventoryTransfer::ExtraNode *)(reinterpret_cast<::Callees *>((walk2Slot3))->FUN_00726070()));
                    }
                    if (chosen)
                    {
                        if (!transferSlot3->list)
                            transferSlot3->list = new ExtraNode;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((chosen))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        transferSlot3->list->FUN_005ae3d0(&chosen);
                        if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0) && count2Slot41 < ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())))
                        {
                            Extra* extraG = new Extra;
                            reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraG))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                            reinterpret_cast<::FUN_00419ad0_shell *>((extraG))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())) - count2Slot41);
                            transferSlot3->list->FUN_005ae3d0(&extraG);
                        }
                    }
                    else
                    {
                        Extra* extraH = new Extra;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraH))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraH))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())));
                        transferSlot3->list->FUN_005ae3d0(&extraH);
                    }
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(changed->form));
                    reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    {
                        reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    }
                    else
                    {
                        if (*((::InventoryTransfer::Extra **)((void *)(transferSlot3->list))))
                            reinterpret_cast<::FUN_00418600_cls *>(((*((::InventoryTransfer::Extra **)((void *)(transferSlot3->list))))))->FUN_00418600();
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
                else
                {
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(::InventoryTransfer::Form *)(((::InventoryTransfer::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((changed))->GetName()))));
                    reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                    chosen = new Extra;
                    reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((chosen))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                    reinterpret_cast<::FUN_00419ad0_shell *>((chosen))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferSlot3))->FUN_00726070())));
                    transferSlot3->list->FUN_005ae3d0(&chosen);
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                }
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        nodeSlot1 = ((::InventoryTransfer::ItemNode *)(reinterpret_cast<::Callees *>((nodeSlot1))->FUN_00726070()));
    }
}
}

struct CleanupReference;
struct CleanupExtra
{
    virtual ~CleanupExtra();
};
struct CleanupExtraNode
{
    void FUN_0063f7b0();
};
struct CleanupItem : InventoryStackRecord
{
};
struct CleanupItemNode
{
};
struct CleanupInventory;
struct CleanupReferenceExtra
{
};
struct CleanupReference
{
};
struct CleanupInventory
{
    CleanupItemNode* first;
    void RemoveAllItems();
};
// @fnv 0x004d3660
void CleanupInventory::RemoveAllItems()
{
    CleanupItemNode* start = first;
    CleanupItemNode* itemList = first;
    CleanupItem* node = 0;
    while (start && *((::CleanupItem **)((void *)(start))))
    {
        node = *((::CleanupItem **)((void *)(start)));
        CleanupExtra* extra = 0;
        while (node->m_pExtraDataLists && *((::CleanupExtra **)((void *)(reinterpret_cast<CleanupExtraNode*>(node->m_pExtraDataLists)))))
        {
            extra = *((::CleanupExtra **)((void *)(reinterpret_cast<CleanupExtraNode*>(node->m_pExtraDataLists))));
            reinterpret_cast<CleanupExtraNode*>(node->m_pExtraDataLists)->FUN_0063f7b0();
            CleanupReference* ref = 0;
            if (extra)
                ref = ((::CleanupReference *)(reinterpret_cast<::FUN_00418630_Class *>((extra))->FUN_00418630()));
            if (ref)
            {
                if (((void *)(reinterpret_cast<::s55d310::Owner *>((ref))->FUN_0055d310())))
                {
                    reinterpret_cast<::FUN_00418600_cls *>((extra))->FUN_00418600();
                    if (reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extra))->FUN_0040fe20() < 2 && reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770() != 0)
                        reinterpret_cast<::FUN_0041af10_Class *>((extra))->RemoveExtra24();
                    reinterpret_cast<::ItemChangeListNode *>((((::CleanupExtraNode *)(::FUN_00559450((int *)(node))))))->FUN_00905330((::InventoryStackRecord *const &)(extra));
                    CleanupInventory* inventory = ((::CleanupInventory *)(reinterpret_cast<::ExtraDataList *>((((::CleanupReferenceExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->GetContainerChangeData()));
                    bool destroy = true;
                    if (inventory)
                    {
                        CleanupItem* entry = ((::CleanupItem *)(reinterpret_cast<::FUN_004bfba0_shell *>((inventory))->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((node))->GetName())), 1, 0)));
                        if (entry && ((::CleanupExtraNode *)(::FUN_00559450((int *)(entry)))))
                        {
                            CleanupExtraNode* scan = ((::CleanupExtraNode *)(::FUN_00559450((int *)(entry))));
                            while (scan && *((::CleanupExtra **)((void *)(scan))) && destroy)
                            {
                                if (*((::CleanupExtra **)((void *)(scan))) == extra)
                                    destroy = false;
                                else
                                    scan = ((::CleanupExtraNode *)(reinterpret_cast<::Callees *>((scan))->FUN_00726070()));
                            }
                        }
                    }
                    inventory = ((::CleanupInventory *)(reinterpret_cast<::ExtraDataList *>((((::CleanupReferenceExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((reinterpret_cast<CleanupReference*>((*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_005d43c0()))))->GetContainerChangeData()));
                    if (inventory)
                    {
                        CleanupItem* playerEntry = ((::CleanupItem *)(reinterpret_cast<::FUN_004bfba0_shell *>((inventory))->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((node))->GetName())), 1, 0)));
                        if (playerEntry && ((::CleanupExtraNode *)(::FUN_00559450((int *)(playerEntry)))))
                        {
                            CleanupExtraNode* playerScan = ((::CleanupExtraNode *)(::FUN_00559450((int *)(playerEntry))));
                            while (playerScan && *((::CleanupExtra **)((void *)(playerScan))) && destroy)
                            {
                                if (*((::CleanupExtra **)((void *)(playerScan))) == extra)
                                    destroy = false;
                                else
                                    playerScan = ((::CleanupExtraNode *)(reinterpret_cast<::Callees *>((playerScan))->FUN_00726070()));
                            }
                        }
                    }
                    if (destroy)
                        delete extra;
                    else
                        extra = 0;
                }
                else
                {
                    reinterpret_cast<::FUN_00418600_cls *>((extra))->FUN_00418600();
                    if (!((void *)(reinterpret_cast<::FUN_00418800_shell *>((extra))->FUN_00418800())))
                        delete extra;
                    extra = 0;
                }
            }
            else
                extra = 0;
        }
        reinterpret_cast<::ItemChangeListNode *>((start))->FUN_00905330((::InventoryStackRecord *const &)(node));
        delete node;
        node = 0;
        start = itemList;
    }
}

namespace fnv_004d3960 {

struct SaveItemChange
{
    unsigned short GetSaveSize();
};
struct SaveItemNode
{
    bool IsEmpty();
    SaveItemChange** Item();
};
struct SaveFormRecord
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flags05;
};
struct SaveLoadGame
{
};
struct DebugSetting
{
    unsigned char* Bool();
};

struct InventorySaveList
{
    SaveItemNode* first;
    unsigned short FUN_004d3960();
};

// @fnv 0x004d3960
unsigned short InventorySaveList::FUN_004d3960()
{
    unsigned short size3 = 0;
    unsigned short startSize = size3;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004d3960::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 2;
    SaveItemNode* node5 = first;
    while (node5 && !node5->IsEmpty())
    {
        SaveItemChange* itemB = *((::fnv_004d3960::SaveItemChange **)((void *)(node5)));
        if (itemB)
            size3 += reinterpret_cast<::fnv_004be5a0::InventoryChangesSaveSize *>((itemB))->FUN_004be5a0();
        node5 = ((::fnv_004d3960::SaveItemNode *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
    }
    if (*(*reinterpret_cast<::fnv_004d3960::DebugSetting *>(&::g_011de4e8)).Bool())
    {
        SaveFormRecord* pRecord = ((::fnv_004d3960::SaveFormRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_004d3960::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (pRecord)
        {
            TESForm* form = ::FUN_004839c0(pRecord->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size3;
}
}  // namespace fnv_004d3960

namespace fnv_004d3ab0 {
class SForm
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual bool vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual const char* vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();
    virtual void vf150();
    unsigned int FUN_0084e3a0();
};

struct FormIDEntry
{
    unsigned int formID;
    char flags[5];
};

struct SSaveGame
{
    void FUN_00857a10(void* data, int size);
    unsigned char FUN_008df040();
};

struct DebugFlag
{
    bool* FUN_00408d60();
};

struct ItemNode
{
    bool FUN_008256d0();
};

struct ItemChangeStub
{
    void FUN_004be6f0();
};



struct FUN_004d3ab0_cls
{
    void* m_pEntryList;
    void FUN_004d3ab0();
};

// Writes a BLOCK-tagged inventory-change list to the save game, counting changed items and patching the block size and count fields.
// @fnv 0x004d3ab0
void FUN_004d3ab0_cls::FUN_004d3ab0()
{
    SForm* f1;
    unsigned int endPos;
    FormIDEntry* hdr;
    ItemChangeStub* item2;
    int kTag;
    short count_;
    ItemNode* aNode;
    unsigned int kPosB;
    short zero;
    unsigned int cnt;
    unsigned int blk;

    zero = 0;
    blk = 0;
    kPosB = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    if (*(*reinterpret_cast<::fnv_004d3ab0::DebugFlag *>(&::g_011de4e8)).FUN_00408d60())
    {
        kPosB = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        kTag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&kTag, 4);
        blk = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&zero, 2);
    }
    count_ = 0;
    cnt = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&count_, 2);
    aNode = (ItemNode*)m_pEntryList;
    while (aNode && !aNode->FUN_008256d0())
    {
        item2 = (ItemChangeStub*)*((void **)((void *)(aNode)));
        if (item2)
        {
            item2->FUN_004be6f0();
            count_++;
        }
        aNode = ((::fnv_004d3ab0::ItemNode *)(reinterpret_cast<::Callees *>((aNode))->FUN_00726070()));
    }
    *(short*)cnt = count_;
    if (*(*reinterpret_cast<::fnv_004d3ab0::DebugFlag *>(&::g_011de4e8)).FUN_00408d60())
    {
        endPos = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        hdr = ((::fnv_004d3ab0::FormIDEntry *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (hdr)
        {
            f1 = ((::fnv_004d3ab0::SForm *)(::FUN_004839c0(hdr->formID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int _end = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004d3ab0::SSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        unsigned int tmp = blk;
        if (_end > tmp + 0xffff)
        {
            ::FUN_005b5e40();
        }
        *(short*)blk = (short)(_end - tmp);
    }
}
}  // namespace fnv_004d3ab0

// Save-game block loader (FUN_004d3cc0): block header checks, item list rebuild, size validation logs.

class TESForm;

struct LoadingFormInfo
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flags0;
    unsigned char flags1;
    unsigned char flags2;
    unsigned char flags3;
    unsigned char version;
};

class SaveLoadGame
{
  public:
                                 // 0x862110
      // 0x8579e0
                // 0x4fd3c0
    unsigned char GetVersion();                   // 0x8df040
                         // 0x825c00
};


  // 0x4839c0
       // 0x5b5e40

class LoadItem
{
  public:
    void* unk00;
    int unk04;
    void* unk08;
    LoadItem();             // 0x76b630
             // 0x4be930
      // 0x44ddc0
              // 0x4bc780
    ~LoadItem();
};

class LoadItemList
{
  public:
    void AddHead(LoadItem** item);  // 0x5ae3d0
};

class FUN_004d3cc0_cls
{
  public:
    LoadItemList* pItems;
      // 0x4cbbc0
    void FUN_004d3cc0();
};

struct Blob4_4d4090
{
    int m_data;
    Blob4_4d4090(int v);
};

struct SaveBuffer_4d4090
{
    virtual TESIdleForm* GetSpeakerIdle();
    Blob4_4d4090 GetChangeFlags();
    void SetChangeFlags(Blob4_4d4090 flags);
};

struct ItemSave_4d4090
{
};

struct InvChangesSave : InventoryChanges
{
    void FUN_004d4090(SaveBuffer_4d4090* buffer);
};

// Saves each non-null item change in the list to the buffer, then writes the count and restores the speaker idle and change flags.
// @fnv 0x004d4090
void InvChangesSave::FUN_004d4090(SaveBuffer_4d4090* buffer)
{
    TESIdleForm* savedIdle3 = buffer->GetSpeakerIdle();
    Blob4_4d4090 oldFlags = buffer->GetChangeFlags();
    reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((buffer))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(::TESIdleForm *)(0));
    reinterpret_cast<::FUN_00428130_Class *>((buffer))->SetValue((*(int *)&(const ::Blob4_4d4090 &)(0x400)));
    int count7 = 0;
    unsigned int pos3 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    BSSimpleList<InventoryStackRecord*>* nodeTmp = m_pEntryList;
    while (nodeTmp != 0)
    {
        InventoryStackRecord* change5 = (nodeTmp->m_item);
        if (change5 != 0)
        {
            reinterpret_cast<::FUN_004bed60_shell *>((((ItemSave_4d4090*)change5)))->SavePerkList((::BGSSaveFormBuffer *)(buffer));
            count7++;
        }
        nodeTmp = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((nodeTmp))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count7, pos3);
    reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((buffer))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(savedIdle3));
    reinterpret_cast<::FUN_00428130_Class *>((buffer))->SetValue((*(int *)&(const ::Blob4_4d4090 &)(oldFlags)));
}

struct WalkForm
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual bool excluded();
    int FUN_00401170();
};
struct WalkBiped
{
};
struct WalkBaseEntry
{
    int count;
    WalkForm* form;
};
struct WalkBaseNode
{
};
struct WalkContainer
{
    WalkBaseNode* FUN_00717e50();
};
struct WalkChange
{
};
struct WalkNode
{
};
struct WalkTemp
{
    void* extra;
    int count;
    WalkForm* form;
    WalkTemp();
    ~WalkTemp();
};
struct WalkInventory
{
    WalkNode* first;
    WalkContainer* FUN_004bffb0();
    int ForEachInventoryItem(bool(__cdecl* callback)(WalkTemp*, void*), void* context, int flags);
};
// Iterates base entries and change nodes, filters by flags, builds a WalkTemp per item and calls callback, returning the count processed.
// @fnv 0x004d4530
int WalkInventory::ForEachInventoryItem(bool(__cdecl* callback)(WalkTemp*, void*), void* context, int flags)
{
    int total_2 = 0;
    WalkBaseNode* base = ((::WalkContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    while (base)
    {
        WalkBaseEntry* entryB = *((::WalkBaseEntry **)((void *)(base)));
        base = ((::WalkBaseNode *)(reinterpret_cast<::Callees *>((base))->FUN_00726070()));
        if (entryB)
        {
            if (((void *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(entryB->form), 1, 0))))
                continue;
            if (flags & 1)
            {
                if (entryB->form->excluded())
                    continue;
                WalkBiped* biped3 = ((::WalkBiped *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(entryB->form))));
                if (biped3 && !reinterpret_cast<::FUN_00480d90_shell *>((biped3))->FUN_00480d90())
                    continue;
                if (entryB->form->FUN_00401170() == 40)
                {
                    WalkForm* aWeapon = entryB->form;
                    if (reinterpret_cast<::FUN_0046e8c0_class *>((aWeapon))->FUN_0046e8c0())
                        continue;
                }
            }
            WalkTemp temp;
            reinterpret_cast<::CombatProcedure *>(&(temp))->Initialize((::CombatController *)(entryB->count));
            reinterpret_cast<::TESRegionGrassObject *>(&(temp))->AssignLandTexture((::TESLandTexture *)(entryB->form));
            total_2++;
            if (callback(&temp, context))
                return total_2;
        }
    }
    WalkNode* node7 = first;
    while (node7)
    {
        WalkChange* change3 = *((::WalkChange **)((void *)(node7)));
        node7 = ((::WalkNode *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        if (change3)
        {
            WalkForm* form5 = ((::WalkForm *)(reinterpret_cast<::Twin_0044ddc0 *>((change3))->GetName()));
            if (flags & 1)
            {
                if (form5->excluded())
                    continue;
                WalkBiped* biped4 = ((::WalkBiped *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(form5))));
                if (biped4 && !reinterpret_cast<::FUN_00480d90_shell *>((biped4))->FUN_00480d90())
                    continue;
                if (form5->FUN_00401170() == 40)
                {
                    WalkForm* weapon6 = form5;
                    if (reinterpret_cast<::FUN_0046e8c0_class *>((weapon6))->FUN_0046e8c0())
                        continue;
                }
            }
            int countB = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((change3))->FUN_00726070())) + reinterpret_cast<::TESContainer *>((((::WalkContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(form5));
            if (!countB)
                continue;
            WalkTemp temp6;
            temp6.extra = ((void *)(::FUN_00559450((int *)(change3))));
            reinterpret_cast<::CombatProcedure *>(&(temp6))->Initialize((::CombatController *)(countB));
            reinterpret_cast<::TESRegionGrassObject *>(&(temp6))->AssignLandTexture((::TESLandTexture *)(form5));
            total_2++;
            if (callback(&temp6, context))
            {
                temp6.extra = 0;
                return total_2;
            }
            temp6.extra = 0;
        }
    }
    return total_2;
}

struct IterForm
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual bool IsFiltered();
    int FUN_00401170();
};

struct BipedIter
{
};
struct BaseEntryIter
{
    int count;
    IterForm* form;
};
struct BaseNodeIter
{
};
struct ChangeIter
{
};
struct ChangeNodeIter
{
};
struct IterContainer
{
    BaseNodeIter* FUN_00717e50();
};
struct IterState
{
    void* extra;
    int unk04;
    int unk08;
    BaseNodeIter* base;
    ChangeNodeIter* change;
    bool done;
};
struct InventoryIterOwner
{
    ChangeNodeIter* changes;
    IterContainer* FUN_004bffb0();
    bool AdvanceInventoryIterator(IterState*, void**, int);
};
// Advances the inventory iterator over base and change entries, applying flag-based filters, and fills state and out with the next matching entry.
// @fnv 0x004d4830
bool InventoryIterOwner::AdvanceInventoryIterator(IterState* state, void** out, int flags)
{
    if (state->done)
        return false;
    if (!state->base && !state->change)
        state->base = ((::IterContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    if (state->base)
    {
        while (state->base)
        {
            BaseEntryIter* entry7 = *((::BaseEntryIter **)((void *)(state->base)));
            state->base = ((::BaseNodeIter *)(reinterpret_cast<::Callees *>((state->base))->FUN_00726070()));
            if (!state->base)
            {
                if (changes)
                    state->change = changes;
                else
                    state->done = true;
            }
            if (entry7)
            {
                if (((int)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(entry7->form), 1, 0))))
                    continue;
                if (flags & 1)
                {
                    if (entry7->form->IsFiltered())
                        continue;
                    BipedIter* biped3 = ((::BipedIter *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(entry7->form))));
                    if (biped3 && !reinterpret_cast<::FUN_00480d90_shell *>((biped3))->FUN_00480d90())
                        continue;
                    if (entry7->form->FUN_00401170() == 40)
                    {
                        IterForm* aWeapon = entry7->form;
                        if (reinterpret_cast<::FUN_0046e8c0_class *>((aWeapon))->FUN_0046e8c0())
                            continue;
                    }
                }
                state->extra = 0;
                reinterpret_cast<::CombatProcedure *>((state))->Initialize((::CombatController *)(entry7->count));
                reinterpret_cast<::TESRegionGrassObject *>((state))->AssignLandTexture((::TESLandTexture *)(entry7->form));
                *out = state;
                return true;
            }
        }
    }
    if (state->change)
    {
        while (state->change)
        {
            ChangeIter* entry2 = *((::ChangeIter **)((void *)(state->change)));
            state->change = ((::ChangeNodeIter *)(reinterpret_cast<::Callees *>((state->change))->FUN_00726070()));
            if (!state->change)
                state->done = true;
            if (entry2)
            {
                IterForm* form2 = ((::IterForm *)(reinterpret_cast<::Twin_0044ddc0 *>((entry2))->GetName()));
                if (flags & 1)
                {
                    if (form2->IsFiltered())
                        continue;
                    BipedIter* pChangeBipedModel = ((::BipedIter *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(form2))));
                    if (pChangeBipedModel && !reinterpret_cast<::FUN_00480d90_shell *>((pChangeBipedModel))->FUN_00480d90())
                        continue;
                    if (form2->FUN_00401170() == 40)
                    {
                        IterForm* weapon6 = form2;
                        if (reinterpret_cast<::FUN_0046e8c0_class *>((weapon6))->FUN_0046e8c0())
                            continue;
                    }
                }
                int iChangeCount = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry2))->FUN_00726070())) + reinterpret_cast<::TESContainer *>((((::IterContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(form2));
                if (iChangeCount <= 0)
                    continue;
                *out = entry2;
                state->extra = ((void *)(::FUN_00559450((int *)(entry2))));
                reinterpret_cast<::CombatProcedure *>((state))->Initialize((::CombatController *)(iChangeCount));
                reinterpret_cast<::TESRegionGrassObject *>((state))->AssignLandTexture((::TESLandTexture *)(form2));
                *out = state;
                return true;
            }
        }
    }
    return false;
}

int FNV_GetFormType(TESForm* pForm);

struct TopicEntry4d4 : FUN_004459e0
{
};

struct FUN_004bf630
{
    ~FUN_004bf630();
};

struct TopicForm4d4
{
};

struct TopicList4d4
{
    void FUN_005ae3d0(FUN_004459e0*& pkItem);
};

struct FUN_004d4ca0_shell
{
    void CollectTopicEntries(TESForm* pkForm, TopicList4d4* pkList);
};

// @fnv 0x004d4ca0
void FUN_004d4ca0_shell::CollectTopicEntries(TESForm* pkForm, TopicList4d4* pkList)
{
    if (!pkForm || !pkList)
        return;
    if (FNV_GetFormType(pkForm) != 0x28)
        return;
    FUN_004bf630* pkIter = ((::FUN_004bf630 *)(reinterpret_cast<::OwnerProduct *>(this)->FUN_004ca200()));
    FUN_004459e0* pkItem = 0;
    TopicForm4d4* pNewkTopic = (TopicForm4d4*)pkForm;
    unsigned int uiFlagsCur = 0;
    do
    {
        pkItem = ((::FUN_004459e0 *)(reinterpret_cast<::Host_004d4b00 *>(this)->GetNextInventoryEntry((::Iterator_004d4b00 *)(pkIter))));
        if (pkItem)
        {
            if (FNV_GetFormType(((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((((TopicEntry4d4*)pkItem)))->GetName()))) == 0x67)
            {
                uiFlagsCur = (unsigned int)(std::uintptr_t)((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((((TopicEntry4d4*)pkItem)))->GetName()));
                if (uiFlagsCur == reinterpret_cast<::FUN_004bd570_this *>((pNewkTopic))->FUN_004bd570(1))
                    pkList->FUN_005ae3d0(pkItem);
                else if (uiFlagsCur == reinterpret_cast<::FUN_004bd570_this *>((pNewkTopic))->FUN_004bd570(2))
                    pkList->FUN_005ae3d0(pkItem);
                else if (uiFlagsCur == reinterpret_cast<::FUN_004bd570_this *>((pNewkTopic))->FUN_004bd570(4))
                    pkList->FUN_005ae3d0(pkItem);
            }
            else
            {
                delete pkItem;
            }
        }
    } while (pkItem);
    delete pkIter;
}

struct InvExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    InvExtra();
};
struct InvNode
{
    InvExtra* data;
    InvNode* next;
    InvNode();
    void FUN_005ae3d0(InvExtra*&);
};
struct InvEntry
{
    InvNode* list;
    int count;
    void* object;
    InvEntry(void*, int);
};
struct InvArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    InvEntry*& FUN_00877a30(unsigned);
};
struct InvHost
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    InvArray entries;
    float weight;
    void FUN_009687b0(void* object, InvExtra* extra, int amount);
};
// Adds amount of object to a matching entry (merging into extra nodes when given), creating a new entry if none matches, then updates weight.
// @fnv 0x009687b0
void InvHost::FUN_009687b0(void* object, InvExtra* extra, int amount)
{
    bool found = false;
    for (unsigned index = 0; !found && index < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries))->GetName())); ++index)
    {
        InvEntry* entry = entries.FUN_00877a30(index);
        if (((void *)(reinterpret_cast<::Twin_0044ddc0 *>((entries.FUN_00877a30(index)))->GetName())) == object)
        {
            bool empty = !((::InvNode *)(::FUN_00559450((int *)(entry)))) || !*((::InvExtra **)((void *)(((::InvNode *)(::FUN_00559450((int *)(entry))))))) ||
                         reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>(((*((::InvExtra **)((void *)(((::InvNode *)(::FUN_00559450((int *)(entry))))))))))->HasOnlyAllowedExtraData(0);
            if (!extra)
            {
                if (empty)
                {
                    reinterpret_cast<::CombatProcedure *>((entry))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entries.FUN_00877a30(index)))->FUN_00726070())) + amount));
                    found = true;
                }
            }
            else
            {
                for (InvNode* node = ((::InvNode *)(::FUN_00559450((int *)(entry)))); !found && node && *((::InvExtra **)((void *)(node)));
                     node = ((::InvNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
                {
                    if (!reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>(((*((::InvExtra **)((void *)(node))))))->FUN_004126c0((::ExtraDataList *)(extra), 1, 0) &&
                        !reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((extra))->FUN_004126c0((::ExtraDataList *)(*((::InvExtra **)((void *)(node)))), 1, 0))
                    {
                        reinterpret_cast<::CombatProcedure *>((entry))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entries.FUN_00877a30(index)))->FUN_00726070())) + amount));
                        reinterpret_cast<::FUN_00419ad0_shell *>(((*((::InvExtra **)((void *)(node))))))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>(((*((::InvExtra **)((void *)(node))))))->FUN_00418770() + amount);
                        found = true;
                    }
                }
                if (!found && reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra))->HasOnlyAllowedExtraData(0) && empty)
                {
                    InvExtra* copy = new InvExtra;
                    reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((copy))->FUN_00412380((::ExtraDataList *)(extra));
                    reinterpret_cast<::FUN_00419ad0_shell *>((copy))->FUN_00419ad0((unsigned short)amount);
                    if (!((::InvNode *)(::FUN_00559450((int *)(entry)))))
                        entry->list = new InvNode;
                    ((::InvNode *)(::FUN_00559450((int *)(entry))))->FUN_005ae3d0(copy);
                    reinterpret_cast<::CombatProcedure *>((entry))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entries.FUN_00877a30(index)))->FUN_00726070())) + amount));
                    found = true;
                }
            }
        }
    }
    if (!found)
    {
        InvEntry* added = new InvEntry(object, amount);
        if (extra)
        {
            InvExtra* pExtraCopy2 = new InvExtra;
            reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((pExtraCopy2))->FUN_00412380((::ExtraDataList *)(extra));
            reinterpret_cast<::FUN_00419ad0_shell *>((pExtraCopy2))->FUN_00419ad0((unsigned short)amount);
            ((::InvNode *)(::FUN_00559450((int *)(added))))->FUN_005ae3d0(pExtraCopy2);
        }
        reinterpret_cast<::FUN_00438690 *>(&(entries))->FUN_007cb2e0((unsigned int *)&(added));
    }
    weight += ::TESWeightForm::GetWeightForForm((::TESForm *)(object), ::FUN_004d1360((char *)this)) * amount;
}

struct Transfer4c37C37Form
{
    virtual void Pad48_0();
    virtual void Pad48_1();
    virtual void Pad48_2();
    virtual void Pad48_3();
    virtual void Pad48_4();
    virtual void Pad48_5();
    virtual void Pad48_6();
    virtual void Pad48_7();
    virtual void Pad48_8();
    virtual void Pad48_9();
    virtual void Pad48_10();
    virtual void Pad48_11();
    virtual void Pad48_12();
    virtual void Pad48_13();
    virtual void Pad48_14();
    virtual void Pad48_15();
    virtual void Pad48_16();
    virtual void Pad48_17();
    virtual void Vcall48(int arg);
    virtual void Pad190_19();
    virtual void Pad190_20();
    virtual void Pad190_21();
    virtual void Pad190_22();
    virtual void Pad190_23();
    virtual void Pad190_24();
    virtual void Pad190_25();
    virtual void Pad190_26();
    virtual void Pad190_27();
    virtual void Pad190_28();
    virtual void Pad190_29();
    virtual void Pad190_30();
    virtual void Pad190_31();
    virtual void Pad190_32();
    virtual void Pad190_33();
    virtual void Pad190_34();
    virtual void Pad190_35();
    virtual void Pad190_36();
    virtual void Pad190_37();
    virtual void Pad190_38();
    virtual void Pad190_39();
    virtual void Pad190_40();
    virtual void Pad190_41();
    virtual void Pad190_42();
    virtual void Pad190_43();
    virtual void Pad190_44();
    virtual void Pad190_45();
    virtual void Pad190_46();
    virtual void Pad190_47();
    virtual void Pad190_48();
    virtual void Pad190_49();
    virtual void Pad190_50();
    virtual void Pad190_51();
    virtual void Pad190_52();
    virtual void Pad190_53();
    virtual void Pad190_54();
    virtual void Pad190_55();
    virtual void Pad190_56();
    virtual void Pad190_57();
    virtual void Pad190_58();
    virtual void Pad190_59();
    virtual void Pad190_60();
    virtual void Pad190_61();
    virtual void Pad190_62();
    virtual void Pad190_63();
    virtual void Pad190_64();
    virtual void Pad190_65();
    virtual void Pad190_66();
    virtual void Pad190_67();
    virtual void Pad190_68();
    virtual void Pad190_69();
    virtual void Pad190_70();
    virtual void Pad190_71();
    virtual void Pad190_72();
    virtual void Pad190_73();
    virtual void Pad190_74();
    virtual void Pad190_75();
    virtual void Pad190_76();
    virtual void Pad190_77();
    virtual void Pad190_78();
    virtual void Pad190_79();
    virtual void Pad190_80();
    virtual void Pad190_81();
    virtual void Pad190_82();
    virtual void Pad190_83();
    virtual void Pad190_84();
    virtual void Pad190_85();
    virtual void Pad190_86();
    virtual void Pad190_87();
    virtual void Pad190_88();
    virtual void Pad190_89();
    virtual void Pad190_90();
    virtual void Pad190_91();
    virtual void Pad190_92();
    virtual void Pad190_93();
    virtual void Pad190_94();
    virtual void Pad190_95();
    virtual void Pad190_96();
    virtual void Pad190_97();
    virtual void Pad190_98();
    virtual void Pad190_99();
    virtual void Vcall190(int a, void* b, int c);
};
struct Transfer4c37Obj44
{
};
struct Transfer4c37Cont14c
{
    virtual void Pad14c_0();
    virtual void Pad14c_1();
    virtual void Pad14c_2();
    virtual void Pad14c_3();
    virtual void Pad14c_4();
    virtual void Pad14c_5();
    virtual void Pad14c_6();
    virtual void Pad14c_7();
    virtual void Pad14c_8();
    virtual void Pad14c_9();
    virtual void Pad14c_10();
    virtual void Pad14c_11();
    virtual void Pad14c_12();
    virtual void Pad14c_13();
    virtual void Pad14c_14();
    virtual void Pad14c_15();
    virtual void Pad14c_16();
    virtual void Pad14c_17();
    virtual void Pad14c_18();
    virtual void Pad14c_19();
    virtual void Pad14c_20();
    virtual void Pad14c_21();
    virtual void Pad14c_22();
    virtual void Pad14c_23();
    virtual void Pad14c_24();
    virtual void Pad14c_25();
    virtual void Pad14c_26();
    virtual void Pad14c_27();
    virtual void Pad14c_28();
    virtual void Pad14c_29();
    virtual void Pad14c_30();
    virtual void Pad14c_31();
    virtual void Pad14c_32();
    virtual void Pad14c_33();
    virtual void Pad14c_34();
    virtual void Pad14c_35();
    virtual void Pad14c_36();
    virtual void Pad14c_37();
    virtual void Pad14c_38();
    virtual void Pad14c_39();
    virtual void Pad14c_40();
    virtual void Pad14c_41();
    virtual void Pad14c_42();
    virtual void Pad14c_43();
    virtual void Pad14c_44();
    virtual void Pad14c_45();
    virtual void Pad14c_46();
    virtual void Pad14c_47();
    virtual void Pad14c_48();
    virtual void Pad14c_49();
    virtual void Pad14c_50();
    virtual void Pad14c_51();
    virtual void Pad14c_52();
    virtual void Pad14c_53();
    virtual void Pad14c_54();
    virtual void Pad14c_55();
    virtual void Pad14c_56();
    virtual void Pad14c_57();
    virtual void Pad14c_58();
    virtual void Pad14c_59();
    virtual void Pad14c_60();
    virtual void Pad14c_61();
    virtual void Pad14c_62();
    virtual void Pad14c_63();
    virtual void Pad14c_64();
    virtual void Pad14c_65();
    virtual void Pad14c_66();
    virtual void Pad14c_67();
    virtual void Pad14c_68();
    virtual void Pad14c_69();
    virtual void Pad14c_70();
    virtual void Pad14c_71();
    virtual void Pad14c_72();
    virtual void Pad14c_73();
    virtual void Pad14c_74();
    virtual void Pad14c_75();
    virtual void Pad14c_76();
    virtual void Pad14c_77();
    virtual void Pad14c_78();
    virtual void Pad14c_79();
    virtual void Pad14c_80();
    virtual void Pad14c_81();
    virtual void Pad14c_82();
    virtual Transfer4c37Obj44* Vcall14c();
};
struct Transfer4c37MidObj;
struct Transfer4c37C37Obj
{
    virtual void Pad100_0();
    virtual void Pad100_1();
    virtual void Pad100_2();
    virtual void Pad100_3();
    virtual void Pad100_4();
    virtual void Pad100_5();
    virtual void Pad100_6();
    virtual void Pad100_7();
    virtual void Pad100_8();
    virtual void Pad100_9();
    virtual void Pad100_10();
    virtual void Pad100_11();
    virtual void Pad100_12();
    virtual void Pad100_13();
    virtual void Pad100_14();
    virtual void Pad100_15();
    virtual void Pad100_16();
    virtual void Pad100_17();
    virtual void Pad100_18();
    virtual void Pad100_19();
    virtual void Pad100_20();
    virtual void Pad100_21();
    virtual void Pad100_22();
    virtual void Pad100_23();
    virtual void Pad100_24();
    virtual void Pad100_25();
    virtual void Pad100_26();
    virtual void Pad100_27();
    virtual void Pad100_28();
    virtual void Pad100_29();
    virtual void Pad100_30();
    virtual void Pad100_31();
    virtual void Pad100_32();
    virtual void Pad100_33();
    virtual void Pad100_34();
    virtual void Pad100_35();
    virtual void Pad100_36();
    virtual void Pad100_37();
    virtual void Pad100_38();
    virtual void Pad100_39();
    virtual void Pad100_40();
    virtual void Pad100_41();
    virtual void Pad100_42();
    virtual void Pad100_43();
    virtual void Pad100_44();
    virtual void Pad100_45();
    virtual void Pad100_46();
    virtual void Pad100_47();
    virtual void Pad100_48();
    virtual void Pad100_49();
    virtual void Pad100_50();
    virtual void Pad100_51();
    virtual void Pad100_52();
    virtual void Pad100_53();
    virtual void Pad100_54();
    virtual void Pad100_55();
    virtual void Pad100_56();
    virtual void Pad100_57();
    virtual void Pad100_58();
    virtual void Pad100_59();
    virtual void Pad100_60();
    virtual void Pad100_61();
    virtual void Pad100_62();
    virtual void Pad100_63();
    virtual bool Vcall100();
    virtual void Pad188_65();
    virtual void Pad188_66();
    virtual void Pad188_67();
    virtual void Pad188_68();
    virtual void Pad188_69();
    virtual void Pad188_70();
    virtual void Pad188_71();
    virtual void Pad188_72();
    virtual void Pad188_73();
    virtual void Pad188_74();
    virtual void Pad188_75();
    virtual void Pad188_76();
    virtual void Pad188_77();
    virtual void Pad188_78();
    virtual void Pad188_79();
    virtual void Pad188_80();
    virtual void Pad188_81();
    virtual void Pad188_82();
    virtual void Pad188_83();
    virtual void Pad188_84();
    virtual void Pad188_85();
    virtual void Pad188_86();
    virtual void Pad188_87();
    virtual void Pad188_88();
    virtual void Pad188_89();
    virtual void Pad188_90();
    virtual void Pad188_91();
    virtual void Pad188_92();
    virtual void Pad188_93();
    virtual void Pad188_94();
    virtual void Pad188_95();
    virtual void Pad188_96();
    virtual void Pad188_97();
    virtual bool Vcall188(int a, int b, void* c);
    virtual void Pad3ec_99();
    virtual void Pad3ec_100();
    virtual void Pad3ec_101();
    virtual void Pad3ec_102();
    virtual void Pad3ec_103();
    virtual void Pad3ec_104();
    virtual void Pad3ec_105();
    virtual void Pad3ec_106();
    virtual void Pad3ec_107();
    virtual void Pad3ec_108();
    virtual void Pad3ec_109();
    virtual void Pad3ec_110();
    virtual void Pad3ec_111();
    virtual void Pad3ec_112();
    virtual void Pad3ec_113();
    virtual void Pad3ec_114();
    virtual void Pad3ec_115();
    virtual void Pad3ec_116();
    virtual void Pad3ec_117();
    virtual void Pad3ec_118();
    virtual void Pad3ec_119();
    virtual void Pad3ec_120();
    virtual void Pad3ec_121();
    virtual void Pad3ec_122();
    virtual void Pad3ec_123();
    virtual void Pad3ec_124();
    virtual void Pad3ec_125();
    virtual void Pad3ec_126();
    virtual void Pad3ec_127();
    virtual void Pad3ec_128();
    virtual void Pad3ec_129();
    virtual void Pad3ec_130();
    virtual void Pad3ec_131();
    virtual void Pad3ec_132();
    virtual void Pad3ec_133();
    virtual void Pad3ec_134();
    virtual void Pad3ec_135();
    virtual void Pad3ec_136();
    virtual void Pad3ec_137();
    virtual void Pad3ec_138();
    virtual void Pad3ec_139();
    virtual void Pad3ec_140();
    virtual void Pad3ec_141();
    virtual void Pad3ec_142();
    virtual void Pad3ec_143();
    virtual void Pad3ec_144();
    virtual void Pad3ec_145();
    virtual void Pad3ec_146();
    virtual void Pad3ec_147();
    virtual void Pad3ec_148();
    virtual void Pad3ec_149();
    virtual void Pad3ec_150();
    virtual void Pad3ec_151();
    virtual void Pad3ec_152();
    virtual void Pad3ec_153();
    virtual void Pad3ec_154();
    virtual void Pad3ec_155();
    virtual void Pad3ec_156();
    virtual void Pad3ec_157();
    virtual void Pad3ec_158();
    virtual void Pad3ec_159();
    virtual void Pad3ec_160();
    virtual void Pad3ec_161();
    virtual void Pad3ec_162();
    virtual void Pad3ec_163();
    virtual void Pad3ec_164();
    virtual void Pad3ec_165();
    virtual void Pad3ec_166();
    virtual void Pad3ec_167();
    virtual void Pad3ec_168();
    virtual void Pad3ec_169();
    virtual void Pad3ec_170();
    virtual void Pad3ec_171();
    virtual void Pad3ec_172();
    virtual void Pad3ec_173();
    virtual void Pad3ec_174();
    virtual void Pad3ec_175();
    virtual void Pad3ec_176();
    virtual void Pad3ec_177();
    virtual void Pad3ec_178();
    virtual void Pad3ec_179();
    virtual void Pad3ec_180();
    virtual void Pad3ec_181();
    virtual void Pad3ec_182();
    virtual void Pad3ec_183();
    virtual void Pad3ec_184();
    virtual void Pad3ec_185();
    virtual void Pad3ec_186();
    virtual void Pad3ec_187();
    virtual void Pad3ec_188();
    virtual void Pad3ec_189();
    virtual void Pad3ec_190();
    virtual void Pad3ec_191();
    virtual void Pad3ec_192();
    virtual void Pad3ec_193();
    virtual void Pad3ec_194();
    virtual void Pad3ec_195();
    virtual void Pad3ec_196();
    virtual void Pad3ec_197();
    virtual void Pad3ec_198();
    virtual void Pad3ec_199();
    virtual void Pad3ec_200();
    virtual void Pad3ec_201();
    virtual void Pad3ec_202();
    virtual void Pad3ec_203();
    virtual void Pad3ec_204();
    virtual void Pad3ec_205();
    virtual void Pad3ec_206();
    virtual void Pad3ec_207();
    virtual void Pad3ec_208();
    virtual void Pad3ec_209();
    virtual void Pad3ec_210();
    virtual void Pad3ec_211();
    virtual void Pad3ec_212();
    virtual void Pad3ec_213();
    virtual void Pad3ec_214();
    virtual void Pad3ec_215();
    virtual void Pad3ec_216();
    virtual void Pad3ec_217();
    virtual void Pad3ec_218();
    virtual void Pad3ec_219();
    virtual void Pad3ec_220();
    virtual void Pad3ec_221();
    virtual void Pad3ec_222();
    virtual void Pad3ec_223();
    virtual void Pad3ec_224();
    virtual void Pad3ec_225();
    virtual void Pad3ec_226();
    virtual void Pad3ec_227();
    virtual void Pad3ec_228();
    virtual void Pad3ec_229();
    virtual void Pad3ec_230();
    virtual void Pad3ec_231();
    virtual void Pad3ec_232();
    virtual void Pad3ec_233();
    virtual void Pad3ec_234();
    virtual void Pad3ec_235();
    virtual void Pad3ec_236();
    virtual void Pad3ec_237();
    virtual void Pad3ec_238();
    virtual void Pad3ec_239();
    virtual void Pad3ec_240();
    virtual void Pad3ec_241();
    virtual void Pad3ec_242();
    virtual void Pad3ec_243();
    virtual void Pad3ec_244();
    virtual void Pad3ec_245();
    virtual void Pad3ec_246();
    virtual void Pad3ec_247();
    virtual void Pad3ec_248();
    virtual void Pad3ec_249();
    virtual void Pad3ec_250();
    virtual void Vcall3ec(int a, int b, int c, int d);
};

struct Transfer4c37Form4
{
    virtual ~Transfer4c37Form4();
};
struct Transfer4c37FirstObj
{
};
struct Transfer4c37NewObj
{
    void* m00;
    int m04;
    int m08;
    int FUN_004459e0(int a);
    Transfer4c37NewObj();
    ~Transfer4c37NewObj();
};
struct Transfer4c37Ret720
{
    int m00;
    int m04;
    int m08;
    int m0c;
};
struct Transfer4c37Obj20
{
    virtual ~Transfer4c37Obj20();
    Transfer4c37Obj20();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int FUN_0041d000();
    void FUN_00419700(void* a);
};
struct Transfer4c37ItemObj;
struct Transfer4c37EntryHeadS
{
    void FUN_005ae3d0(Transfer4c37Obj20** pp);
};
struct Transfer4c37Node84
{
};
unsigned char __cdecl FUN_00702680(int a, int b);
int FUN_00401170(std::uintptr_t a);
void* __cdecl FUN_00401000(int a);
struct Transfer4c37Obj96
{
    void* item;
    void* next;
    Transfer4c37Obj96();
};
struct Transfer4c37CurHead
{
    void FUN_005ae3d0(void* pp);
};
struct Transfer4c37MidObj
{
};
struct Transfer4c37AuxObj
{
    int FUN_005f0cc0();
};
struct Transfer4c37ResObj
{
    virtual void RPad_0();
    virtual void RPad_1();
    virtual void RPad_2();
    virtual void RPad_3();
    virtual void RPad_4();
    virtual void RPad_5();
    virtual void RPad_6();
    virtual void RPad_7();
    virtual void RPad_8();
    virtual void RPad_9();
    virtual void RPad_10();
    virtual void RPad_11();
    virtual void RPad_12();
    virtual void RPad_13();
    virtual void RPad_14();
    virtual void RPad_15();
    virtual void RPad_16();
    virtual void RPad_17();
    virtual void Vcall48(int a);
    virtual void RPadC4_19();
    virtual void RPadC4_20();
    virtual void RPadC4_21();
    virtual void RPadC4_22();
    virtual void RPadC4_23();
    virtual void RPadC4_24();
    virtual void RPadC4_25();
    virtual void RPadC4_26();
    virtual void RPadC4_27();
    virtual void RPadC4_28();
    virtual void RPadC4_29();
    virtual void RPadC4_30();
    virtual void RPadC4_31();
    virtual void RPadC4_32();
    virtual void RPadC4_33();
    virtual void RPadC4_34();
    virtual void RPadC4_35();
    virtual void RPadC4_36();
    virtual void RPadC4_37();
    virtual void RPadC4_38();
    virtual void RPadC4_39();
    virtual void RPadC4_40();
    virtual void RPadC4_41();
    virtual void RPadC4_42();
    virtual void RPadC4_43();
    virtual void RPadC4_44();
    virtual void RPadC4_45();
    virtual void RPadC4_46();
    virtual void RPadC4_47();
    virtual void RPadC4_48();
    virtual void VcallC4(int a);
};
struct Transfer4c37M68Obj
{
};
struct Transfer4c37M00Obj
{
    bool FUN_008256d0();
};
struct Transfer4c37LogObj
{
};
struct Transfer4c37T70Obj
{
};

struct Transfer4c37ItemObj
{
    int FUN_0041d000();
    virtual ~Transfer4c37ItemObj();
    void FUN_00419700(void* a);
};
struct Transfer4c37EntryFirst
{
};
struct Transfer4c37Tail470
{
};
struct Transfer4c37Entry
{
    ~Transfer4c37Entry();
    void* m00;
    int m04;
    int m08;
};
struct Transfer4c37Cont
{
};
struct Transfer4c37EntryNew
{
    void* extras;
    int count;
    void* form;
    Transfer4c37EntryNew(int a, int b);
};
struct Transfer4c37ThisHead
{
};
struct Transfer4c37D7Obj
{
};
struct Transfer4c37Sub100
{
    virtual void SPad_0();
    virtual void SPad_1();
    virtual void SPad_2();
    virtual float Vcall3(int a);
};
struct Transfer4c37ActorValueView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    Transfer4c37Sub100 values;
};
struct Transfer4c37Glob20
{
};
int __cdecl FUN_00ec62c0(float a);
struct Transfer4c37FormFull
{
    virtual void PadF_0();
    virtual void PadF_1();
    virtual void PadF_2();
    virtual void PadF_3();
    virtual void PadF_4();
    virtual void PadF_5();
    virtual void PadF_6();
    virtual void PadF_7();
    virtual void PadF_8();
    virtual void PadF_9();
    virtual void PadF_10();
    virtual void PadF_11();
    virtual void PadF_12();
    virtual void PadF_13();
    virtual void PadF_14();
    virtual void PadF_15();
    virtual void PadF_16();
    virtual void PadF_17();
    virtual void Vcall48(int arg);
    virtual void PadF_19();
    virtual void PadF_20();
    virtual void PadF_21();
    virtual void PadF_22();
    virtual void PadF_23();
    virtual void PadF_24();
    virtual void PadF_25();
    virtual void PadF_26();
    virtual void PadF_27();
    virtual void PadF_28();
    virtual void PadF_29();
    virtual void PadF_30();
    virtual void PadF_31();
    virtual void PadF_32();
    virtual void PadF_33();
    virtual void PadF_34();
    virtual void PadF_35();
    virtual void PadF_36();
    virtual void PadF_37();
    virtual void PadF_38();
    virtual void PadF_39();
    virtual void PadF_40();
    virtual void PadF_41();
    virtual void PadF_42();
    virtual void PadF_43();
    virtual void PadF_44();
    virtual void PadF_45();
    virtual void PadF_46();
    virtual void PadF_47();
    virtual void PadF_48();
    virtual void PadF_49();
    virtual void PadF_50();
    virtual void PadF_51();
    virtual void PadF_52();
    virtual void PadF_53();
    virtual void PadF_54();
    virtual void PadF_55();
    virtual void PadF_56();
    virtual void PadF_57();
    virtual void PadF_58();
    virtual void PadF_59();
    virtual void PadF_60();
    virtual void PadF_61();
    virtual void PadF_62();
    virtual void PadF_63();
    virtual bool Vcall100();
};
struct Transfer4c37C37This
{
    int m00;
    Transfer4c37FormFull* m04;
    float m08;
    float m0c;
    unsigned char m10;
    Transfer4c37Cont* FUN_004bffb0();
    int FUN_004c37d0(Transfer4c37C37Obj* p0, std::intptr_t p1, unsigned char p2, int p3, Transfer4c37Form4* p4, unsigned char p5,
                     Transfer4c37C37Form* p6, std::intptr_t p7, std::intptr_t p8, unsigned char p9, unsigned char p10,
                     Transfer4c37Entry* p11);
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int v);
    FUN_008c71b0(const FUN_008c71b0& other);
};

struct LoadBuffer4160
{
    virtual void Slot0();
    virtual int GetVersion();
    void FUN_00428110(unsigned int* out);
    void FUN_0042ce30(unsigned int* out);
};

struct Item4160 : FUN_0076b630
{
};

struct ChangeList4160
{
    void FUN_005ae3d0(FUN_004459e0** item);
};

struct Inventory4160
{
    ChangeList4160* changes;
    void FUN_004d4160(LoadBuffer4160* buffer);
};

// @fnv 0x004d4160
void Inventory4160::FUN_004d4160(LoadBuffer4160* buffer)
{
    int tag = buffer->GetVersion();
    unsigned int oldFlags;
    buffer->FUN_00428110(&oldFlags);
    unsigned int savedMode;
    buffer->FUN_0042ce30(&savedMode);
    reinterpret_cast<::TESRecipe *>((buffer))->SetRequiredSkill((::ActorValue::Index)(0));
    reinterpret_cast<::FUN_00428130_Class *>((buffer))->SetValue((*(int *)&(const ::FUN_008c71b0 &)(FUN_008c71b0(0x400))));
    reinterpret_cast<::Twin_0086cf00 *>((buffer))->SetD3DPixelShader((*(::GeometryRelatedType *const *)&(const ::FUN_008c71b0 &)(FUN_008c71b0(0))));
    unsigned int itemCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
    for (unsigned int i = 0; i < itemCount; i++)
    {
        FUN_004459e0* item = new FUN_0076b630;
        reinterpret_cast<::fnv_004bee00::FUN_004bee00_shell *>((static_cast<Item4160*>(item)))->FUN_004bee00((::fnv_004bee00::BGSLoadFormBuffer *)(buffer));
        if (!((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((static_cast<Item4160*>(item)))->GetName())))
        {
            reinterpret_cast<::FUN_004bc780_shell *>((static_cast<Item4160*>(item)))->ClearExtraDataList();
            delete item;
            item = 0;
        }
        changes->FUN_005ae3d0(&item);
    }
    reinterpret_cast<::TESRecipe *>((buffer))->SetRequiredSkill((::ActorValue::Index)(tag));
    reinterpret_cast<::FUN_00428130_Class *>((buffer))->SetValue(oldFlags);
    reinterpret_cast<::Twin_0086cf00 *>((buffer))->SetD3DPixelShader((::GeometryRelatedType *const)(savedMode));
}


struct FUN_0076b630_ex : public FUN_0076b630
{
};

struct MoveFormInfo_ex : public MoveFormInfo
{
};


// Scans the changes list for an entry with an extra matching the given slot, optionally requiring armor, and returns a new entry holding that item and extra.
// @fnv 0x004c8c10
FUN_0076b630* Target::FUN_004c8c10(int slot, int bOnlyArmor)
{
    AutoMemContext memContext2((MEM_CONTEXT)54, true, ::DAT_01020778, 5978);
    ItemList* node7 = this->changes;
    FUN_0076b630* result5 = 0;

    while (node7 && ((::FUN_0076b630 *)((void *)(node7))))
    {
        FUN_0076b630_ex* entry7 = (FUN_0076b630_ex*)((::FUN_0076b630 *)((void *)(node7)));
        if (entry7)
        {
            FUN_0096a2d0* extraNode = entry7->extras;
            XExtra* foundExtra6 = 0;
            bool equipped2 = false;

            if (reinterpret_cast<::InventoryStackRecord *>((entry7))->HasPerkEntry() && entry7->count < 0)
            {
                reinterpret_cast<::ItemChange_004be3d0 *>((entry7))->SetExtraListFlag(0, 0, 1);
            }

            while (extraNode && ((::Extra *)((void *)(extraNode))) && !equipped2)
            {
                foundExtra6 = (XExtra*)((::Extra *)((void *)(extraNode)));
                if (reinterpret_cast<::FUN_00418ab0_shell *>((foundExtra6))->FUN_00418ab0(0))
                {
                    switch (slot)
                    {
                    case 5:
                        if (((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName()))->FUN_00401170() == 0x28)
                        {
                            equipped2 = true;
                        }
                        break;
                    default: {
                        MoveFormInfo_ex* biped6 =
                            (MoveFormInfo_ex*)((::MoveFormInfo *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(::TESBoundObject *)((TESBoundObject*)((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName()))))));
                        switch (slot)
                        {
                        case 0:
                        case 1:
                        case 10: {
                            void* armor = ((void *)(::BGSBipedModelList::GetBipedModelList((::TESForm *)(::Weapon *)(((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName()))))));
                            if (biped6 && reinterpret_cast<::TESBipedModelForm *>((biped6))->HasBipedModel((::BIPED_OBJECT)(slot), 0, (::BGSBipedModelList *)(armor)))
                            {
                                equipped2 = true;
                            }
                            break;
                        }
                        default: {
                            if (biped6 && reinterpret_cast<::TESBipedModelForm *>((biped6))->HasBipedModel((::BIPED_OBJECT)(slot), 0, (::BGSBipedModelList *)(void *)(0)))
                            {
                                equipped2 = true;
                            }
                            break;
                        }
                        }
                        break;
                    }
                    }
                }
                extraNode = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070()));
            }

            if (equipped2)
            {
                if (*(bool*)&bOnlyArmor && ((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName()))->FUN_00401170() != 0x18)
                {
                    return result5;
                }

                result5 = new FUN_0076b630();
                result5->weapon = ((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName()));
                if (!result5->extras)
                {
                    result5->extras = new FUN_0096a2d0();
                }
                result5->extras->FUN_005ae3d0((Extra**)&foundExtra6);
                reinterpret_cast<::CombatProcedure *>((result5))->Initialize((::CombatController *)(std::uintptr_t)(reinterpret_cast<::FUN_00418770_shell *>((foundExtra6))->FUN_00418770()));
                equipped2 = false;
                return result5;
            }
        }

        node7 = ((::ItemList *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
    }

    return result5;
}


class VSubC5
{
  public:
    virtual void v0();
    virtual bool v4();
};

class IngredientItem : public TESBoundObject
{
  public:
    char padC5[0x38];
    VSubC5 sub;
};

class AlchemyItem : public TESBoundObject
{
  public:
    char padC5[0x38];
    VSubC5 sub;
};

struct E4C5
{
    int count;
    TESBoundObject* p4;
    TESBoundObject* p8;
};

struct ENodeC5
{
    bool FUN_008256d0();
};

struct MemHelperC5
{
    void* m_p;
    MemHelperC5(int, bool, const char*, int);
    ~MemHelperC5();
};

struct CItemC5
{
    TESBoundObject* p0;
    int i4;
    int i8;
    CItemC5(TESBoundObject*, int);
};

struct CContainerC5
{
    ENodeC5* FUN_00717e50();
};

struct CTargetC5
{
    ENodeC5* m_pFirstNode;
    CContainerC5* FUN_004bffb0();
    void* FUN_004cafe0();
};

// @fnv 0x004cafe0
void* CTargetC5::FUN_004cafe0()
{
    MemHelperC5 kMem(0x36, 1, DAT_01020778, 0x1afa);
    ENodeC5* pList = ((::CContainerC5 *)(reinterpret_cast<::FUN_004bffb0_shell *>((this))->FUN_004bffb0()))->FUN_00717e50();
    IngredientItem* pA7 = 0;
    TESBoundObject* pObj7 = 0;
    CItemC5* pItem = 0;
    AlchemyItem* pB = 0;

    while (pList && !pList->FUN_008256d0())
    {
        pA7 = dynamic_cast<IngredientItem*>((*((::E4C5 **)((void *)(pList))))->p4);
        if (!pA7)
        {
            pB = dynamic_cast<AlchemyItem*>((*((::E4C5 **)((void *)(pList))))->p4);
            pObj7 = pB;
        }
        else
            pObj7 = pA7;

        if ((pB && pB->sub.v4()) || (pA7 && pA7->sub.v4()))
        {
            CItemC5* pNew = ((::CItemC5 *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0(pObj7, 1, 0)));
            if (!pNew || (pNew && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pNew))->FUN_00726070())) + (*((::E4C5 **)((void *)(pList))))->count != 0))
            {
                if (!pNew)
                    pItem = new CItemC5(pObj7, 0);
                else
                    pItem = pNew;
                return pItem;
            }
        }
        pList = ((::ENodeC5 *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }

    ENodeC5* pInv8 = this->m_pFirstNode;
    while (pInv8 && !pInv8->FUN_008256d0())
    {
        pA7 = dynamic_cast<IngredientItem*>((*((::E4C5 **)((void *)(pInv8))))->p8);
        if (!pA7)
        {
            pB = dynamic_cast<AlchemyItem*>((*((::E4C5 **)((void *)(pInv8))))->p8);
            pObj7 = pB;
        }
        else
            pObj7 = pA7;

        if ((pA7 && pA7->sub.v4()) || (pB && pB->sub.v4()))
        {
            if (!reinterpret_cast<::TESContainer *>((((::CContainerC5 *)(reinterpret_cast<::FUN_004bffb0_shell *>((this))->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(pObj7)))
            {
                if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::E4C5 **)((void *)(pInv8))))))->FUN_00726070())) > 0)
                    return *((::E4C5 **)((void *)(pInv8)));
            }
        }
        pInv8 = ((::ENodeC5 *)(reinterpret_cast<::Callees *>((pInv8))->FUN_00726070()));
    }
    return pItem;
}

struct ProcV6;

struct Actor6
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool v100();
};

struct ProcV6
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void v1d0(void* p);
};

struct ContObj6
{
    int count;
    void* pObj;
    void* pExtra;
};

struct Node1_6;

struct Cont6
{
    Node1_6* FUN_00717e50();
};

struct Node1_6
{
    bool FUN_008256d0();
};

struct ItemCh6
{
    void* pExtraList;
    int m_iCountChange;
    void* m_pItemObject;
};

struct Node2_6
{
    bool FUN_008256d0();
};

struct Item2_6
{
};


struct FUN_004cffe0_t
{
    void* m_pEntryList;
    void* FUN_004bffb0();
    bool CheckItemRequirement(void* a1, void* a2, int a3, int* a4, void* a5, Actor6* a6);
};

// @fnv 0x004cffe0
bool FUN_004cffe0_t::CheckItemRequirement(void* a1, void* a2, int iRequiredCount, int* a4, void* a5, Actor6* pActor)
{
    int total = 0;
    if (a5 != 0)
        return reinterpret_cast<::FUN_004cfe20_t *>((this))->HasItem((std::uintptr_t)(a5));

    Actor6* pOwner = 0;
    if (pActor != 0 && pActor->v100() != 0)
        pOwner = pActor;

    Node1_6* pNode = ((Cont6*)((void *)(reinterpret_cast<::FUN_004bffb0_shell *>((this))->FUN_004bffb0())))->FUN_00717e50();

    while (pNode != 0 && !pNode->FUN_008256d0())
    {
        void* pObj = (*((::ContObj6 **)((void *)(pNode))))->pObj;
        if (pObj != 0 && ((a1 != 0 && pObj == a1) || (a1 == 0 && a2 != 0 && ::MatchesObjectType((::TESForm *)(pObj), (int)(a2)))))
        {
            Item2_6* pItem = ((::Item2_6 *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0((::TESBoundObject *)(pObj), 1, 0)));
            if (pItem != 0)
            {
                if ((*((::ContObj6 **)((void *)(pNode))))->count < 0)
                {
                    return true;
                }
                else
                {
                    if (pItem != 0)
                        total += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pItem))->FUN_00726070())) + (*((::ContObj6 **)((void *)(pNode))))->count;
                    else
                        total += (*((::ContObj6 **)((void *)(pNode))))->count;
                }
                if (pOwner != 0 && ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture())) != 0)
                    ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture()))->v1d0((void*)((reinterpret_cast<::Twin_0044ddc0 *>((pItem))->GetName())));
                *a4 = FUN_00679ba0((void*)((reinterpret_cast<::Twin_0044ddc0 *>((pItem))->GetName())));
            }
            else
            {
                if (pOwner != 0 && ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture())) != 0)
                    ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture()))->v1d0(pObj);
                *a4 = FUN_00679ba0(pObj);
                return true;
            }
        }
        pNode = ((::Node1_6 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }

    if (total >= iRequiredCount)
    {
        return true;
    }
    else
    {
        if (a1 != 0)
        {
            Item2_6* pItem2 = ((::Item2_6 *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0((::TESBoundObject *)(a1), 1, 0)));
            if (pItem2 != 0 && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pItem2))->FUN_00726070())) >= iRequiredCount)
            {
                if (pOwner != 0 && ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture())) != 0)
                    ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture()))->v1d0((void*)((reinterpret_cast<::Twin_0044ddc0 *>((pItem2))->GetName())));
                *a4 = FUN_00679ba0((void*)((reinterpret_cast<::Twin_0044ddc0 *>((pItem2))->GetName())));
                return true;
            }
        }
        else
        {
            Node2_6* pNode2 = (Node2_6*)this->m_pEntryList;
            while (pNode2 != 0 && !pNode2->FUN_008256d0() && *((::ItemCh6 **)((void *)(pNode2))) != 0)
            {
                void* pObj2 = (*((::ItemCh6 **)((void *)(pNode2))))->m_pItemObject;
                if (pObj2 != 0 && a2 != 0 && ::MatchesObjectType((::TESForm *)(pObj2), (int)(a2)) &&
                    ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(((*((::ItemCh6 **)((void *)(pNode2))))))->FUN_00726070())) >= iRequiredCount)
                {
                    if (pOwner != 0 && ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture())) != 0)
                        ((::ProcV6 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture()))->v1d0((void*)((reinterpret_cast<::Twin_0044ddc0 *>((*((::ItemCh6 **)((void *)(pNode2)))))->GetName())));
                    *a4 = FUN_00679ba0((void*)((reinterpret_cast<::Twin_0044ddc0 *>((*((::ItemCh6 **)((void *)(pNode2)))))->GetName())));
                    return true;
                }
                pNode2 = ((::Node2_6 *)(reinterpret_cast<::Callees *>((pNode2))->FUN_00726070()));
            }
        }
    }
    return false;
}

namespace Rebuild004d0650 {
struct Object
{
};
struct Extra
{
};
struct FUN_0096a2d0
{
    char data[8];
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    unsigned FUN_005ae380();
    void FUN_005ae3d0(Extra**);
    void* FUN_004702f0(unsigned);
};
struct FUN_004bc550
{
    FUN_0096a2d0* list;
    int count;
    Object* form;
    FUN_004bc550(Object*, int);
};
struct Entry
{
    int count;
    Object* form;
};
struct Node
{
    bool FUN_008256d0();
};
struct Container
{
    Node* FUN_00717e50();
};
struct Inventory
{
    Container* FUN_004bffb0();
    FUN_004bc550* FUN_004d0650(Object*, int);
};
// @fnv 0x004d0650
FUN_004bc550* Inventory::FUN_004d0650(Object* object, int arg)
{
    FUN_004bc550* source3 = ((::Rebuild004d0650::FUN_004bc550 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(object), 1, arg)));
    FUN_004bc550* result2 = 0;
    if (source3)
    {
        int count2 = reinterpret_cast<::TESContainer *>((((::Rebuild004d0650::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(object));
        result2 = new FUN_004bc550(object, count2 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((source3))->FUN_00726070())));
        if (((::Rebuild004d0650::FUN_0096a2d0 *)(::FUN_00559450((int *)(source3)))) && ((::Rebuild004d0650::FUN_0096a2d0 *)(::FUN_00559450((int *)(source3))))->FUN_005ae380())
        {
            if (!((::Rebuild004d0650::FUN_0096a2d0 *)(::FUN_00559450((int *)(result2)))))
                result2->list = new FUN_0096a2d0;
            Extra* extra7 = *((::Rebuild004d0650::Extra **)((void *)(((::Rebuild004d0650::FUN_0096a2d0 *)(::FUN_00559450((int *)(source3)))))));
            if (reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra7))->HasOnlyAllowedExtraData(0))
            {
                FUN_0096a2d0* node5 = ((::Rebuild004d0650::FUN_0096a2d0 *)(::FUN_00559450((int *)(source3))));
                while (node5 && *((::Rebuild004d0650::Extra **)((void *)(node5))))
                {
                    extra7 = *((::Rebuild004d0650::Extra **)((void *)(node5)));
                    reinterpret_cast<::Callees *>((result2->list))->FUN_00905820((void *)&(extra7));
                    node5 = ((::Rebuild004d0650::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                }
            }
            else
            {
                result2->list->FUN_005ae3d0(&extra7);
            }
        }
        else
        {
            if (((::Rebuild004d0650::FUN_0096a2d0 *)(::FUN_00559450((int *)(result2)))))
            {
                delete result2->list;
                result2->list = 0;
            }
        }
    }
    else
    {
        Node* base6 = ((::Rebuild004d0650::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
        Object* form2 = 0;
        while (base6 && !base6->FUN_008256d0())
        {
            form2 = (*((::Rebuild004d0650::Entry **)((void *)(base6))))->form;
            if (form2 == object)
            {
                result2 = new FUN_004bc550(object, (*((::Rebuild004d0650::Entry **)((void *)(base6))))->count);
                break;
            }
            base6 = ((::Rebuild004d0650::Node *)(reinterpret_cast<::Callees *>((base6))->FUN_00726070()));
        }
    }
    return result2;
}
}

struct InventoryScanNode
{
    bool FUN_008256d0();
};
struct InventoryScanExtra : ExtraDataList
{
};

// Walks the node list, scanning each item's extra-data list for an entry whose FUN_0041d360 equals value, and returns whether one was found.
// @fnv 0x004d1380
bool Inv4d1440::HasExtraDataWithValue(int value)
{
    InventoryScanNode* node;
    {
        bool found = false;
        node = (InventoryScanNode*)m_pEntryList;
        while (node && !node->FUN_008256d0() && *((::InventoryStackRecord **)((void *)(node))) && !found)
        {
            InventoryStackRecord* item = *((::InventoryStackRecord **)((void *)(node)));
            if (item)
            {
                BSSimpleList<ExtraDataList*>* extras = item->m_pExtraDataLists;
                while (extras && (extras->m_item))
                {
                    ExtraDataList* extra = (extras->m_item);
                    if (extra && reinterpret_cast<::FUN_0041d360_shell *>((((InventoryScanExtra*)extra)))->FUN_0041d360() == value)
                        found = true;
                    extras = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((extras))->FUN_00726070()));
                }
            }
            node = ((::InventoryScanNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        return found;
    }
}

// 0x004d2480  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 1 stack arg (ret 4) -> bool.  SEH from AutoMemHelper local.

struct AutoMemHelper
{
    int m_iOldMemContext;
    AutoMemHelper(int context, bool track, const char* file, int line);
    ~AutoMemHelper();
};

struct GlobalObject_0096a2d0
{
};
struct BSSpinLockUnlock
{
};


struct Sh00568bb0
{
};
struct Sh00575690
{
};
struct Sh005d43c0
{
};
struct Sh00419f80
{
};
struct Sh00411fd0
{
};
struct Sh00418830
{
};
struct Sh00418800
{
};
struct Sh005ac1e0
{
};
struct Sh0087ce80
{
};
struct Sh00436aa0
{
};
struct Sh0049eea0
{
};
struct Sh004013e0
{
};

struct C004d2480
{
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;
    int unk04;
    int unk08;
    int unk0c;
    bool m_bChanged;

    bool FUN_004d2480(TESObjectREFR* apRef);
};

// Locks g_011c64e0, iterates the change list's items and extra-data lists, runs scripts on initialized forms of type 0x11, and returns whether any ran.
// @fnv 0x004d2480
bool C004d2480::FUN_004d2480(TESObjectREFR* apRef)
{
    m_bChanged = 0;
    if (apRef == 0)
        return false;
    TESObjectCELL* pCell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((apRef))->GetTarget()));
    if (pCell == 0)
        return false;

    reinterpret_cast<::FUN_0040fbf0_shell *>(&(::g_011c64e0))->FUN_0040fbf0((char *)(0));
    BSSimpleList<InventoryStackRecord*>* pChange = m_pEntryList;
    bool bRan = false;
    {
        AutoMemHelper memCtx(0x15, true, ::DAT_01020778, 0x264b);
        reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>((((Sh0087ce80*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(pCell));
        reinterpret_cast<::FUN_0049eea0_shell *>((((Sh0049eea0*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_0049eea0((*(const ::NiPoint3 *)(((void *)(reinterpret_cast<::TESTopicInfo *>((((Sh00436aa0*)apRef)))->GetAddTopicList())))));

        while (pChange != 0 && *(void**)&(pChange->m_item) != 0)
        {
            InventoryStackRecord* pItem = (pChange->m_item);
            BSSimpleList<ExtraDataList*>* pExtraList = pItem->m_pExtraDataLists;
            while (pExtraList != 0 && *(void**)&(pExtraList->m_item) != 0)
            {
                ExtraDataList* pExtra = (pExtraList->m_item);
                if (pExtra != 0)
                {
                    void* pScript = ((void *)(reinterpret_cast<::FUN_00418800_shell *>((((Sh00418800*)pExtra)))->FUN_00418800()));
                    if (pScript != 0 && reinterpret_cast<::TESForm *>((void *)(((Sh004013e0*)pScript)))->GetInitialized())
                    {
                        if (FNV_GetFormType((TESForm*)pScript) == 0x11)
                        {
                            reinterpret_cast<::fnv_00568bb0::FUN_00568bb0_shell *>((((Sh00568bb0*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_00568bb0((::fnv_00568bb0::ExtraDataList *)(pExtra));
                            reinterpret_cast<::Fn575690 *>((((Sh00575690*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_00575690((void*)((reinterpret_cast<::Twin_0044ddc0 *>(((InventoryItemEntry*)pItem))->GetName())));
                            if (reinterpret_cast<::FUN_005ac1e0_shell *>((((Sh005ac1e0*)pScript)))->FUN_005ac1e0((::TESObjectREFR *)((*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444))), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((((Sh00418830*)pExtra)))->FUN_00418830()))), (::TESObjectREFR *)(apRef), false))
                                bRan = true;
                            reinterpret_cast<::FUN_00419f80_shell *>((((Sh00419f80*)reinterpret_cast<::FUN_005d43c0_ *>((((Sh005d43c0*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_005d43c0())))->FUN_00419f80((::ScriptLocals *)(void *)((void*)0));
                            reinterpret_cast<::CopyableExtraList *>((((Sh00411fd0*)reinterpret_cast<::FUN_005d43c0_ *>((((Sh005d43c0*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_005d43c0())))->FUN_00411fd0((bool)((void*)1));
                        }
                        if (m_bChanged)
                            break;
                    }
                }
                pExtraList = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((pExtraList))->FUN_00726070()));
            }
            if (m_bChanged)
            {
                pChange = m_pEntryList;
                m_bChanged = 0;
            }
            pChange = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pChange))->FUN_00726070()));
        }
        reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>((((Sh0087ce80*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(void *)(0));
        reinterpret_cast<::Fn575690 *>((((Sh00575690*)(*reinterpret_cast<::DAT_011c6444_type * *>(&::DAT_011c6444)))))->FUN_00575690(0);
    }
    reinterpret_cast<::RecursiveSpinLock *>((((BSSpinLockUnlock*)&::g_011c64e0)))->FUN_0040fba0();
    return bRan;
}

class FUN_008515f0
{
  public:
    int a;
    ~FUN_008515f0();
};
class ListZ
{
  public:
    int FUN_005ae380();
};
class Holder
{
  public:
    ListZ* m0;
    int m4;
    void RemoveAndDelete(FUN_008515f0* p);
};
// @fnv 0x00851620
void Holder::RemoveAndDelete(FUN_008515f0* p)
{
    if (!m0)
        return;
    reinterpret_cast<::ItemChangeListNode *>((m0))->FUN_00905330((*(::InventoryStackRecord *const *)(&p)));
    delete p;
    m4 = m0->FUN_005ae380();
}

class TESEnchantableForm
{
  public:
    virtual void v00();
};
namespace charge4bd {
struct C4Enchant
{
};
struct C4Node
{
    C4Enchant* pItem;
    C4Node* pNext;
};
struct C4Entry
{
    C4Node* pList;
    int unk04;
    TESBoundObject* pForm;
    float FUN_004bd350();
};
}
using namespace charge4bd;

// Returns the first valid enchant value from pList, falling back to the form's base value, or -1.0f if the form is not enchantable.
// @fnv 0x004bd350
float C4Entry::FUN_004bd350()
{
    TESEnchantableForm* pEnchantableForm = dynamic_cast<TESEnchantableForm*>(pForm);
    if (pEnchantableForm)
    {
        C4Node* pNode = pList;
        if (pNode && *((::charge4bd::C4Enchant **)((void *)(pNode))))
        {
            C4Enchant* pEnchant = *((::charge4bd::C4Enchant **)((void *)(pNode)));
            if (pEnchant && reinterpret_cast<::OwnerList *>((pEnchant))->GetValue() != -1.0f)
            {
                return reinterpret_cast<::OwnerList *>((pEnchant))->GetValue();
            }
            else
            {
                return (float)reinterpret_cast<::TESActorBaseData *>((pEnchantableForm))->GetFatigue();
            }
        }
        else
        {
            return (float)reinterpret_cast<::TESActorBaseData *>((pEnchantableForm))->GetFatigue();
        }
    }
    return -1.0f;
}

struct XActor17;
struct XProcess17;
struct XExtra17;
struct XExtra17;
struct XNodeE17
{
    bool _ref_008256d0();
};
struct XNodeC17
{
};
struct XDism17Part17
{
    unsigned char b0;
    unsigned char b1;
};
struct XDism17Arr17
{
    void* a;
    void* b;
};
struct XDism17
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    XDism17Arr17 arr;
};
struct XExtra17
{
    virtual ~XExtra17();
    bool FUN_00418b10();
};
struct XChange17
{
    ~XChange17();
};
struct XBiped17
{
    bool FUN_00418b10();
};
struct XBiped17Sub17
{
};
struct XArmor17
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    XBiped17Sub17 biped;
};
struct XFound17
{
};
struct XTQ17
{
};
struct XRefr17
{
    void FUN_00571b50();
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};
struct XForm17
{
    bool FUN_00483710();
};
struct XNPC17
{
    void SetField1F0(void*);
};
struct XListObj17
{
};
struct XInv17
{
    XNodeC17* pList;
    XActor17* pRef;
    TESContainer* FUN_004bffb0();
};
void FUN_004bf0e0(InventoryChanges*);
int FUN_00401170(std::uintptr_t);
bool FUN_004c0bf0(TESObjectWEAP*);

extern XExtra17* DAT_011c6448;

struct XProcess17
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual InventoryStackRecord* CurrentWeapon();
    virtual InventoryStackRecord* CurrentAmmo();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void SetWeapon(int, int, bool);
    virtual void v164();
    virtual void SetAmmo(int);
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void SetUpdate(int);
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void UpdateArmor(XActor17*);
};
struct XActor17
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void MarkAsModified(int);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool CanRemove(bool);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    XProcess17* process;
    void FUN_00571b50();
    void FUN_00483710();
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
    void SetField1F0(void*);
};
struct XHost17
{
    bool FUN_004c0cf0(bool*, std::uintptr_t, int, XActor17*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
};
namespace fnv_004d1960 {
struct InvExtra;
struct InvScript;
struct InvTemporary;
struct InvForm;
struct FUN_0055a2f0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~FUN_0055a2f0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    FUN_0055a2f0();
};
struct InvScript
{
};
struct FUN_00410360_Inventory
{
    void* table;
    void* data;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360_Inventory();
};
struct FUN_0096a2d0
{
    FUN_00410360_Inventory* data;
    void* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(FUN_00410360_Inventory* const&);
};
struct FUN_004bc550_Inventory
{
    FUN_0096a2d0* extras;
    int count;
    InvForm* form;
    FUN_004bc550_Inventory(InvForm*, int);
};
struct InvBaseItem
{
    int count;
    InvForm* form;
};
struct InvBaseNode
{
    bool FUN_008256d0();
};
struct InvBaseList
{
    InvBaseNode* FUN_00717e50();
};
struct InvChangesNode
{
};
struct InvInventory
{
    InvChangesNode* changes;
    InvBaseList* FUN_004bffb0();
    void FUN_004d1960();
};
// Iterates base and changed inventory items, attaching scripts to their extra data and creating new extras as needed.
// @fnv 0x004d1960
void InvInventory::FUN_004d1960()
{
    InvBaseNode* node = ((::fnv_004d1960::InvBaseList *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    while (node && !node->FUN_008256d0())
    {
        InvBaseItem* base26 = *((::fnv_004d1960::InvBaseItem **)((void *)(node)));
        InvScript* script1 = ((::fnv_004d1960::InvScript *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(base26->form))));
        int number73 = base26->count;
        int count17 = std::abs(number73);
        if (script1 && count17 > 0)
        {
            FUN_004bc550_Inventory* item = ((::fnv_004d1960::FUN_004bc550_Inventory *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(base26->form), 1, 0)));
            if (!item || !((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_004bde40_shell *>((item))->FUN_004bde40())))
            {
                bool created = false;
                if (!item)
                {
                    created = true;
                    item = new FUN_004bc550_Inventory(base26->form, 0);
                }
                if (!item->extras)
                    item->extras = new FUN_0096a2d0;
                else
                {
                    FUN_0096a2d0* cursorA = item->extras;
                    while (cursorA && *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorA))))
                    {
                        FUN_00410360_Inventory* extraA = *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorA)));
                        if (extraA && !((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraA))->FUN_00418800())))
                        {
                            reinterpret_cast<::FUN_00419ed0_shell *>((extraA))->FUN_00419ed0((::Script *)(script1));
                            reinterpret_cast<::FUN_00419f80_shell *>((extraA))->FUN_00419f80((::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_005abf60_shell *>((((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraA))->FUN_00418800()))))->FUN_005abf60()))));
                            FUN_0055a2f0* temporaryA = new FUN_0055a2f0;
                            reinterpret_cast<::TESForm *>((temporaryA))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((script1))->FUN_005ac1e0((::TESObjectREFR *)(temporaryA), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((extraA))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                            delete temporaryA;
                            --count17;
                        }
                        cursorA = ((::fnv_004d1960::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((cursorA))->FUN_00726070()));
                    }
                }
                if (count17 > 0)
                {
                    for (int iB = 0; iB < count17; ++iB)
                    {
                        FUN_00410360_Inventory* extraB = 0;
                        extraB = new FUN_00410360_Inventory;
                        item->extras->FUN_005ae3d0(extraB);
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraB))->FUN_00419ad0(1);
                        if (extraB && !((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraB))->FUN_00418800())))
                        {
                            reinterpret_cast<::FUN_00419ed0_shell *>((extraB))->FUN_00419ed0((::Script *)(script1));
                            reinterpret_cast<::FUN_00419f80_shell *>((extraB))->FUN_00419f80((::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_005abf60_shell *>((((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraB))->FUN_00418800()))))->FUN_005abf60()))));
                            FUN_0055a2f0* temporaryB = new FUN_0055a2f0;
                            reinterpret_cast<::TESForm *>((temporaryB))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((script1))->FUN_005ac1e0((::TESObjectREFR *)(temporaryB), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((extraB))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                            delete temporaryB;
                        }
                    }
                }
                if (created)
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>(this)->FUN_004c3380((::InventoryStackRecord *)(item), 1);
            }
            else if (item)
            {
                FUN_0096a2d0* cursorC = item->extras;
                while (cursorC && *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorC))))
                {
                    FUN_00410360_Inventory* extraC = *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorC)));
                    if (extraC)
                    {
                        FUN_0055a2f0* temporaryC = new FUN_0055a2f0;
                        reinterpret_cast<::TESForm *>((temporaryC))->NotifySaveLoadGameOfFormChange();
                        reinterpret_cast<::FUN_005ac1e0_shell *>((script1))->FUN_005ac1e0((::TESObjectREFR *)(temporaryC), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((extraC))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                        delete temporaryC;
                        --count17;
                    }
                    cursorC = ((::fnv_004d1960::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((cursorC))->FUN_00726070()));
                }
            }
        }
        node = ((::fnv_004d1960::InvBaseNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    InvChangesNode* change = changes;
    while (change && *((::fnv_004d1960::FUN_004bc550_Inventory **)((void *)(change))))
    {
        FUN_004bc550_Inventory* itemB5 = *((::fnv_004d1960::FUN_004bc550_Inventory **)((void *)(change)));
        InvForm* formB22 = ((::fnv_004d1960::InvForm *)(reinterpret_cast<::Twin_0044ddc0 *>((itemB5))->GetName()));
        InvScript* scriptB46 = ((::fnv_004d1960::InvScript *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(formB22))));
        int numberB11 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemB5))->FUN_00726070()));
        int countB11 = std::abs(numberB11);
        if (scriptB46 && countB11 > 0)
        {
            if (itemB5 && !((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemB5))->FUN_004bde40())))
            {
                if (!itemB5->extras)
                    itemB5->extras = new FUN_0096a2d0;
                else
                {
                    FUN_0096a2d0* cursorD = itemB5->extras;
                    while (cursorD && *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorD))))
                    {
                        FUN_00410360_Inventory* extraD = *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorD)));
                        if (extraD && !((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraD))->FUN_00418800())))
                        {
                            reinterpret_cast<::FUN_00419ed0_shell *>((extraD))->FUN_00419ed0((::Script *)(scriptB46));
                            reinterpret_cast<::FUN_00419f80_shell *>((extraD))->FUN_00419f80((::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_005abf60_shell *>((((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraD))->FUN_00418800()))))->FUN_005abf60()))));
                            FUN_0055a2f0* temporaryD = new FUN_0055a2f0;
                            reinterpret_cast<::TESForm *>((temporaryD))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((scriptB46))->FUN_005ac1e0((::TESObjectREFR *)(temporaryD), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((extraD))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                            delete temporaryD;
                            --countB11;
                        }
                        cursorD = ((::fnv_004d1960::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((cursorD))->FUN_00726070()));
                    }
                }
                for (int iE = 0; iE < countB11; ++iE)
                {
                    FUN_00410360_Inventory* extraE = 0;
                    extraE = new FUN_00410360_Inventory;
                    itemB5->extras->FUN_005ae3d0(extraE);
                    reinterpret_cast<::FUN_00419ad0_shell *>((extraE))->FUN_00419ad0(1);
                    if (extraE && !((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraE))->FUN_00418800())))
                    {
                        reinterpret_cast<::FUN_00419ed0_shell *>((extraE))->FUN_00419ed0((::Script *)(scriptB46));
                        reinterpret_cast<::FUN_00419f80_shell *>((extraE))->FUN_00419f80((::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_005abf60_shell *>((((::fnv_004d1960::InvScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraE))->FUN_00418800()))))->FUN_005abf60()))));
                        FUN_0055a2f0* temporaryE = new FUN_0055a2f0;
                        reinterpret_cast<::TESForm *>((temporaryE))->NotifySaveLoadGameOfFormChange();
                        reinterpret_cast<::FUN_005ac1e0_shell *>((scriptB46))->FUN_005ac1e0((::TESObjectREFR *)(temporaryE), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((extraE))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                        delete temporaryE;
                    }
                }
            }
            else if (itemB5)
            {
                FUN_0096a2d0* cursorF = itemB5->extras;
                while (cursorF && *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorF))))
                {
                    FUN_00410360_Inventory* extraF = *((::fnv_004d1960::FUN_00410360_Inventory **)((void *)(cursorF)));
                    if (extraF)
                    {
                        FUN_0055a2f0* temporaryF = new FUN_0055a2f0;
                        reinterpret_cast<::TESForm *>((temporaryF))->NotifySaveLoadGameOfFormChange();
                        reinterpret_cast<::FUN_005ac1e0_shell *>((scriptB46))->FUN_005ac1e0((::TESObjectREFR *)(temporaryF), (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((extraF))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                        delete temporaryF;
                        --countB11;
                    }
                    cursorF = ((::fnv_004d1960::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((cursorF))->FUN_00726070()));
                }
            }
        }
        change = ((::fnv_004d1960::InvChangesNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
    }
}

}  // namespace fnv_004d1960

struct HealthExtra : public ExtraDataList
{
    HealthExtra();
};
struct HealthInventory : public InventoryChanges
{
};
struct HealthItem : public InventoryStackRecord
{
    void FUN_004bd030(float health, HealthInventory* inventory, ExtraDataList* selected, bool removeEmpty);
};
// Updates the health extra data on the item, creating or removing HealthExtra entries based on the health value and removeEmpty flag.
// @fnv 0x004bd030
void HealthItem::FUN_004bd030(float health, HealthInventory* inventory, ExtraDataList* selected, bool removeEmpty)
{
    TESHealthForm* baseHealth = dynamic_cast<TESHealthForm*>(m_pItemObject);
    int healthForm = ((int)(::TESHealthForm::GetBaseHealth((::TESForm *)(m_pItemObject))));
    int currentHealth = (int)reinterpret_cast<::FUN_004bcdb0_shell *>(this)->FUN_004bcdb0(0);
    if (((::TESObjectREFR *)(reinterpret_cast<::Callees *>((inventory))->FUN_00726070())))
        ((::TESObjectREFR *)(reinterpret_cast<::Callees *>((inventory))->FUN_00726070()))->MarkAsModified(0x20);
    if (baseHealth)
    {
        if (health < healthForm || currentHealth > healthForm)
        {
            BSSimpleList<ExtraDataList*>* list = m_pExtraDataLists;
            if (!list)
            {
                HealthExtra* extra = new HealthExtra;
                list = new BSSimpleList<ExtraDataList*>;
                reinterpret_cast<::FUN_00419c60_cls *>((extra))->FUN_00419c60(health);
                list->AddHead((ExtraDataList*&)extra);
                m_pExtraDataLists = list;
            }
            else
            {
                ExtraDataList* extra = 0;
                while (list && (list->m_item))
                {
                    extra = (list->m_item);
                    if (extra && extra == selected)
                    {
                        if (extra)
                        {
                            reinterpret_cast<::ExtraDataList *>((((HealthExtra*)extra)))->SetExtraHealth(health);
                            return;
                        }
                    }
                    list = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                }
                extra = new HealthExtra;
                reinterpret_cast<::ExtraDataList *>((((HealthExtra*)extra)))->SetExtraHealth(health);
                m_pExtraDataLists->AddHead(extra);
            }
        }
        else
        {
            BSSimpleList<ExtraDataList*>* list = m_pExtraDataLists;
            while (list && (list->m_item))
            {
                ExtraDataList* extra = (list->m_item);
                if (extra && extra == selected)
                {
                    reinterpret_cast<::FUN_0041aef0_StandIn *>((((HealthExtra*)extra)))->FUN_0041aef0();
                    if (reinterpret_cast<::ExtraDataList *>((((HealthExtra*)extra)))->IsEmpty() && removeEmpty)
                    {
                        HealthItem* item = (HealthItem*)reinterpret_cast<::FUN_004bfba0_shell *>((inventory))->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())), 1, 0);
                        BSSimpleList<ExtraDataList*>* extras = ((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(item))));
                        reinterpret_cast<::ItemChangeListNode *>((extras))->FUN_00905330((::InventoryStackRecord *const &)(extra));
                        delete (ExtraVDtor*)extra;
                    }
                    break;
                }
                else
                {
                    list = ((::BSSimpleList< ::ExtraDataList *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                }
            }
        }
    }
}

struct CleanRef;
struct CleanEvent;
struct CleanScript
{
};
struct CleanRef
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual ~CleanRef();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    CleanRef();
};
struct CleanDatum
{
};
struct CleanExtra
{
    virtual ~CleanExtra();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CleanExtra();
};
struct CleanNode
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void FUN_005ae3d0(CleanExtra**);
    unsigned int FUN_005ae380();
    ~CleanNode();
};
struct CleanItem
{
    CleanNode* head;
    int count;
    TESBoundObject* form;
};
struct CleanItemNode
{
    bool FUN_008256d0();
};
struct CleanBaseEntry
{
    int count;
    TESBoundObject* form;
};
struct CleanBaseNode
{
    bool FUN_008256d0();
};
struct CleanContainer
{
    CleanBaseNode* FUN_00717e50();
};
struct CleanFormView
{
    int FUN_00401170();
};
struct InventoryClean
{
    CleanItemNode* head;
    void* owner;
    CleanContainer* FUN_004bffb0();
    void FUN_004cbbc0();
};
struct ExtraHealth;

struct SimpleListNode
{
    bool FUN_008256d0();
};

struct TESObjectARMO : public TESBoundObject
{
};

struct ArmorContainerList004c8220
{
    SimpleListNode* FUN_00717e50();
};

struct FUN_00480af0_shell
{
};
struct FUN_004186f0_shell
{
    float FUN_004186f0();
};
// Adds a reference's item to the inventory, fixing weapon/armor health, merging extras, and updating ammo counts.
// @fnv 0x004c1c90
void W20Inventory::FUN_004c1c90(W20Ref* ref, int count, int unused, bool mark)
{
    AutoMemContext k((MEM_CONTEXT)54, true, ::DAT_01020778, 3131);
    dirty = true;
    previous = weight;
    weight = -1.0f;
    if (((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType() == 40)
    {
        if (((int)(::TESHealthForm::GetBaseHealth((::TESForm *)(::W20Form *)(((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())))))) && reinterpret_cast<::FUN_004186f0_shell *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_004186f0() == -1.0)
        {
            if (((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->GetWeaponType() < 10)
            {
                ::FUN_005b5e40();
                TESHealthForm* p = dynamic_cast<TESHealthForm*>((TESBoundObject*)((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())));
                unsigned int uiHealth = p->GetHealth();
                if (reinterpret_cast<::FUN_00418ba0_shell *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00418ba0())
                    uiHealth += reinterpret_cast<::FUN_004bcf60_shell *>((((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))))->GetEffectValue(10, 0);
                uiHealth = FUN_0042f5a0((unsigned int)(uiHealth * 0.99), uiHealth - 1);
                reinterpret_cast<::Ref39 *>((ref))->FUN_00568bd0((float)uiHealth);
            }
        }
        else if (::FUN_004c0bf0((::TESObjectWEAP *)(((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())))) && reinterpret_cast<::FUN_004186f0_shell *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_004186f0() != -1.0)
        {
            ::FUN_005b5e40();
            TESHealthForm* p = dynamic_cast<TESHealthForm*>((TESBoundObject*)((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())));
            reinterpret_cast<::Ref39 *>((ref))->FUN_00568bd0((float)p->GetHealth());
        }
    }
    if ((((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType() == 24 || ((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType() == 26) &&
        ((int)(::TESHealthForm::GetBaseHealth((::TESForm *)(::W20Form *)(((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())))))) && reinterpret_cast<::FUN_004186f0_shell *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_004186f0() == -1.0)
    {
        ::FUN_005b5e40();
        TESHealthForm* p = dynamic_cast<TESHealthForm*>((TESBoundObject*)((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())));
        unsigned int uiHealth = p->GetHealth();
        uiHealth = FUN_0042f5a0((unsigned int)(uiHealth / 0.99), uiHealth - 1);
        reinterpret_cast<::Ref39 *>((ref))->FUN_00568bd0((float)uiHealth);
    }
    int iAmmoCount = 0;
    W20AmmoExtra* l = ((::W20AmmoExtra *)(reinterpret_cast<::FUN_0042eb40_shell *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->GetExtraAmmo()));
    if (l)
    {
        iAmmoCount = l->count;
        reinterpret_cast<::FUN_0042eb60_shell *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->SetOwnership((void *)(0), (void *)(0));
        ref->v48(0x800);
    }
    iAmmoCount *= count;
    if (owner)
        owner->v48(0x20);
    W20Entry* j = ((::W20Entry *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(::W20Form *)(((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))), true, 0)));
    reinterpret_cast<::FUN_0041af10_Class *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->RemoveExtra24();
    W20Extra* e = new W20Extra;
    bool c = false;
    if (!reinterpret_cast<::ExtraDataList *>((((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->IsEmpty())
    {
        W20Form* weapon = 0;
        if (((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType() == 40)
        {
            weapon = ((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
            c = ::FUN_004c0bf0((::TESObjectWEAP *)(weapon));
        }
        reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((e))->FUN_004121e0((::ExtraDataList *)(::W20Extra *)(((::W20Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))), false);
        if (((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType() != 41 && (!weapon || !::FUN_004c0bf0((::TESObjectWEAP *)(weapon))))
            reinterpret_cast<::FUN_00419fb0_StandIn *>((e))->FUN_00419fb0(reinterpret_cast<::TESObjectREFR *>((ref))->GetScale());
        if (((::W20Form *)(reinterpret_cast<::FUN_00418660_shell *>((e))->FUN_00418660())) == (W20Form*)(*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer)) && owner == (W20Ref*)(*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_0041aed0_shell *>((e))->FUN_0041aed0();
    }
    if (mark)
        reinterpret_cast<::FUN_0041aa20_shell *>((e))->SetWornState(true, false);
    if (j)
    {
        j->count += count;
        if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((ref))->FUN_005653d0())
        {
            reinterpret_cast<::fnv_0041c7f0::FUN_0041c7f0_cls *>((e))->FUN_0041c7f0((::TESObjectREFR *)(ref));
            if (count > 1)
                reinterpret_cast<::FUN_00419ad0_shell *>((e))->FUN_00419ad0((short)count);
            if (!j->extras)
                j->extras = new W20ExtraList;
            j->extras->AddHead(&e);
        }
        else
        {
            W20ExtraList* p = j->extras;
            bool h = true;
            while (p && *((::W20Extra **)((void *)(p))) && h)
            {
                W20Extra* pExistingExtra = *((::W20Extra **)((void *)(p)));
                W20Extra* i = e;
                bool a = true;
                if (i)
                    a = reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((i))->FUN_004126c0((::ExtraDataList *)(pExistingExtra), false, c) || reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((pExistingExtra))->FUN_004126c0((::ExtraDataList *)(i), false, c);
                if (a)
                    p = ((::W20ExtraList *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
                else
                {
                    reinterpret_cast<::FUN_00419ad0_shell *>((pExistingExtra))->FUN_00419ad0((short)(reinterpret_cast<::FUN_00418770_shell *>((pExistingExtra))->FUN_00418770() + count));
                    if (reinterpret_cast<::ExtraDataList *>((pExistingExtra))->IsEmpty())
                    {
                        reinterpret_cast<::ItemChangeListNode *>((j->extras))->FUN_00905330((*(::InventoryStackRecord *const *)(&pExistingExtra)));
                        delete pExistingExtra;
                    }
                    h = false;
                }
            }
            if (h)
            {
                if (e && reinterpret_cast<::ExtraDataList *>((e))->IsEmpty())
                {
                    delete e;
                    e = 0;
                }
                else
                {
                    if (!j->extras)
                        j->extras = new W20ExtraList;
                    j->extras->AddHead(&e);
                }
            }
            else
            {
                delete e;
                e = 0;
            }
        }
        if (j->extras && j->extras->IsEmpty() && !((::W20Entry *)(reinterpret_cast<::Callees *>((j))->FUN_00726070())))
        {
            reinterpret_cast<::ItemChangeListNode *>((entries))->FUN_00905330((*(::InventoryStackRecord *const *)(&j)));
            if (e)
                delete e;
            e = 0;
            delete j;
        }
    }
    else
    {
        W20Entry* added = new W20Entry(((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())), count);
        if (count > 1)
            reinterpret_cast<::FUN_00419ad0_shell *>((e))->FUN_00419ad0((short)count);
        if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((ref))->FUN_005653d0())
        {
            reinterpret_cast<::fnv_0041c7f0::FUN_0041c7f0_cls *>((e))->FUN_0041c7f0((::TESObjectREFR *)(ref));
            if (!added->extras)
                added->extras = new W20ExtraList;
            added->extras->AddHead(&e);
        }
        else if (e)
        {
            if (reinterpret_cast<::ExtraDataList *>((e))->IsEmpty())
            {
                delete e;
                e = 0;
            }
            else
            {
                if (!added->extras)
                    added->extras = new W20ExtraList;
                added->extras->AddHead(&e);
            }
        }
        reinterpret_cast<::Callees *>((entries))->FUN_00905820(&added);
    }
    if (e && reinterpret_cast<::ExtraDataList *>((e))->IsEmpty())
        delete e;
    if (iAmmoCount > 0)
    {
        W20Form* p = ((::W20Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
        W20Ref* a = owner->v100() ? owner : 0;
        W20Form* h = ((::W20Form *)(reinterpret_cast<::AmmoOwner *>((p))->FUN_00525980((::AmmoActor *)(::W20Ref *)(0))));
        if (h)
            reinterpret_cast<::AddInventory *>(this)->FUN_004c29a0((::AddForm *)(h), (::AddExtra *)(0), iAmmoCount);
    }
}
// @fnv 0x004d3cc0
void FUN_004d3cc0_cls::FUN_004d3cc0()
{
    int i;
    unsigned short fSizeB = 0;
    unsigned int start2 = 0;
    unsigned short cnt_2;
    unsigned int marker9;
    LoadingFormInfo* info8;
    TESForm* _form;
    LoadItem* itemB;
    LoadingFormInfo* _info;
    unsigned int offset2;
    TESForm* form;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&marker9, 4);
        if (marker9 != 0x424c4f4b)
        {
            info8 = ((::LoadingFormInfo *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))));
            if (info8 != 0)
            {
                _form = ::FUN_004839c0(info8->formID);
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
        }
        start2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&fSizeB, 2);
    }
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&cnt_2, 2);
    for (i = 0; i < cnt_2; i++)
    {
        itemB = new LoadItem();
        reinterpret_cast<::fnv_004be930::FUN_004be930_shell *>((itemB))->FUN_004be930();
        if (((::LoadItem *)(reinterpret_cast<::Twin_0044ddc0 *>((itemB))->GetName())) != 0)
        {
            pItems->AddHead(&itemB);
        }
        else
        {
            reinterpret_cast<::FUN_004bc780_shell *>((itemB))->ClearExtraDataList();
            delete itemB;
        }
    }
    reinterpret_cast<::InventoryClean *>(this)->FUN_004cbbc0();
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        offset2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        _info = ((::LoadingFormInfo *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::SaveLoadGame * *>(&::g_TESSaveLoadGame))))));
        if (_info != 0)
        {
            form = ::FUN_004839c0(_info->formID);
            if (offset2 > start2 + fSizeB)
            {
                ::FUN_005b5e40(
                    );
            }
            else if (offset2 < start2 + fSizeB)
            {
                ::FUN_005b5e40(
                    );
            }
        }
        else
        {
            if (offset2 > start2 + fSizeB)
            {
                ::FUN_005b5e40(
                    );
            }
            else if (offset2 < start2 + fSizeB)
            {
                ::FUN_005b5e40(
                    );
            }
        }
    }
}
// Updates extra lists and counts while traversing container and inventory entries, removing or freeing entries under several conditions.
// @fnv 0x004cbbc0
void InventoryClean::FUN_004cbbc0()
{
    TESBoundObject* formScope7 = 0;
    CleanBaseNode* baseScope8 = ((::CleanContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    TESLevItem* leveledScope2 = 0;
    while (baseScope8 && !baseScope8->FUN_008256d0())
    {
        formScope7 = (*((::CleanBaseEntry **)((void *)(baseScope8))))->form;
        leveledScope2 = dynamic_cast<TESLevItem*>((*((::CleanBaseEntry **)((void *)(baseScope8))))->form);
        MoveFormInfo* infoScope3 = ((::MoveFormInfo *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(formScope7))));
        if (formScope7 && !leveledScope2 && (!infoScope3 || reinterpret_cast<::FUN_00480d90_shell *>((infoScope3))->FUN_00480d90()))
        {
            CleanItem* itemScope4Local28 = ((::CleanItem *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(formScope7, 1, 0)));

            if (itemScope4Local28)
            {
                TESHealthForm* healthScope5 = dynamic_cast<TESHealthForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope4Local28))->GetName())));
                if (healthScope5 && itemScope4Local28->head)
                {
                    CleanNode* nodeScope6 = itemScope4Local28->head;
                    while (nodeScope6 && *((::CleanExtra **)((void *)(nodeScope6))))
                    {
                        CleanExtra* extraScope7 = *((::CleanExtra **)((void *)(nodeScope6)));
                        if (((double)(reinterpret_cast<::FUN_004186f0_shell *>((extraScope7))->FUN_004186f0())) > -1.0 &&
                            ((double)(reinterpret_cast<::FUN_004186f0_shell *>((extraScope7))->FUN_004186f0())) == healthScope5->GetHealth())
                        {
                            reinterpret_cast<::FUN_0041aef0_StandIn *>((extraScope7))->FUN_0041aef0();
                            int countScope8 = reinterpret_cast<::FUN_00418770_shell *>((extraScope7))->FUN_00418770();
                            reinterpret_cast<::FUN_0041af10_Class *>((extraScope7))->RemoveExtra24();
                            if (reinterpret_cast<::ExtraDataList *>((extraScope7))->IsEmpty())
                            {
                                reinterpret_cast<::ItemChangeListNode *>((nodeScope6))->FUN_00905330((*(::InventoryStackRecord *const *)(&extraScope7)));
                                delete extraScope7;
                                nodeScope6 = itemScope4Local28->head;
                            }
                            else
                            {
                                reinterpret_cast<::FUN_00419ad0_shell *>((extraScope7))->FUN_00419ad0((unsigned short)countScope8);
                                nodeScope6 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope6))->FUN_00726070()));
                            }
                        }
                        else
                            nodeScope6 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope6))->FUN_00726070()));
                    }
                }
            }

            if (itemScope4Local28 && ::FUN_00481f10((::TESObject *)(formScope7)) && owner == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)) && itemScope4Local28->head)
            {
                CleanNode* nodeScope9 = itemScope4Local28->head;
                while (nodeScope9 && *((::CleanExtra **)((void *)(nodeScope9))))
                {
                    CleanExtra* extraScope10 = *((::CleanExtra **)((void *)(nodeScope9)));
                    nodeScope9->FUN_0063f7b0();
                    delete extraScope10;
                }
            }

            if (itemScope4Local28 && ((::CleanScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemScope4Local28))->FUN_004bde40())))
            {
                CleanNode* nodeScope11 = itemScope4Local28->head;
                while (nodeScope11 && *((::CleanExtra **)((void *)(nodeScope11))))
                {
                    CleanExtra* extraScope12 = *((::CleanExtra **)((void *)(nodeScope11)));
                    if (extraScope12 && ((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope12))->FUN_00418800())))
                    {
                        CleanNode* nextScope13 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope11))->FUN_00726070()));
                        while (nextScope13 && *((::CleanExtra **)((void *)(nextScope13))))
                        {
                            CleanExtra* otherScope14 = *((::CleanExtra **)((void *)(nextScope13)));
                            if (extraScope12 == otherScope14)
                            {
                                nextScope13->FUN_0063f7b0();
                                CleanExtra* copyScope15 = new CleanExtra;
                                reinterpret_cast<::FUN_00419ed0_shell *>((copyScope15))->FUN_00419ed0((::Script *)(::CleanScript *)(((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope12))->FUN_00418800()))));
                                reinterpret_cast<::FUN_00419f80_shell *>((copyScope15))->FUN_00419f80((::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_005abf60_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((copyScope15))->FUN_00418800()))))->FUN_005abf60()))));
                                CleanRef* refScope3 = new CleanRef;
                                reinterpret_cast<::TESForm *>((refScope3))->NotifySaveLoadGameOfFormChange();
                                reinterpret_cast<::FUN_005ac1e0_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope12))->FUN_00418800()))))->FUN_005ac1e0((::TESObjectREFR *)(refScope3), (::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_00418830_shell *>((copyScope15))->FUN_00418830()))), (::TESObjectREFR *)(0),
                                                                           0);
                                reinterpret_cast<::Callees *>((nextScope13))->FUN_00905820(&copyScope15);
                                nextScope13 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope11))->FUN_00726070()));
                            }
                            else
                                nextScope13 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nextScope13))->FUN_00726070()));
                        }
                    }
                    nodeScope11 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope11))->FUN_00726070()));
                }
            }

            CleanScript* scriptScope17 = ((::CleanScript *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(formScope7))));
            if (!itemScope4Local28 && scriptScope17)
                reinterpret_cast<::fnv_004d1960::InvInventory *>(this)->FUN_004d1960();
            else if (itemScope4Local28 && itemScope4Local28->count >= 0 && scriptScope17)
            {

                CleanNode* nodeScope18 = itemScope4Local28->head;
                if (!nodeScope18 || nodeScope18->FUN_008256d0())
                    reinterpret_cast<::fnv_004d1960::InvInventory *>(this)->FUN_004d1960();
                else
                {
                    int missingScope19 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope4Local28))->FUN_00726070())) - nodeScope18->FUN_005ae380();
                    while (nodeScope18 && *((::CleanExtra **)((void *)(nodeScope18))))
                    {
                        CleanExtra* extraScope20 = *((::CleanExtra **)((void *)(nodeScope18)));
                        if (extraScope20 && !((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope20))->FUN_00418800())))
                        {
                            reinterpret_cast<::FUN_00419ed0_shell *>((extraScope20))->FUN_00419ed0((::Script *)(scriptScope17));
                            reinterpret_cast<::FUN_00419f80_shell *>((extraScope20))->FUN_00419f80((::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_005abf60_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope20))->FUN_00418800()))))->FUN_005abf60()))));
                            CleanRef* refScope21 = new CleanRef;
                            reinterpret_cast<::TESForm *>((refScope21))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemScope4Local28))->FUN_004bde40()))))->FUN_005ac1e0((::TESObjectREFR *)(refScope21), (::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_00418830_shell *>((extraScope20))->FUN_00418830()))), (::TESObjectREFR *)(0),
                                                                            0);
                            delete refScope21;
                        }
                        nodeScope18 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope18))->FUN_00726070()));
                    }
                    nodeScope18 = itemScope4Local28->head;
                    for (int iScope22 = 0; iScope22 < missingScope19; ++iScope22)
                    {
                        CleanExtra* extraScope23 = new CleanExtra;
                        reinterpret_cast<::FUN_00419ed0_shell *>((extraScope23))->FUN_00419ed0((::Script *)(::CleanScript *)(((::CleanScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemScope4Local28))->FUN_004bde40()))));
                        reinterpret_cast<::FUN_00419f80_shell *>((extraScope23))->FUN_00419f80((::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_005abf60_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope23))->FUN_00418800()))))->FUN_005abf60()))));
                        CleanRef* refScope3 = new CleanRef;
                        reinterpret_cast<::TESForm *>((refScope3))->NotifySaveLoadGameOfFormChange();
                        reinterpret_cast<::FUN_005ac1e0_shell *>((scriptScope17))->FUN_005ac1e0((::TESObjectREFR *)(refScope3), (::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_00418830_shell *>((extraScope23))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                        delete refScope3;
                        nodeScope18->FUN_005ae3d0(&extraScope23);
                    }
                }
            }
            if (itemScope4Local28 && reinterpret_cast<CleanFormView*>(formScope7)->FUN_00401170() == 41)
            {
                CleanExtra* wornScope25 = 0;

                if (owner == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                {
                    CleanNode* nodeScope26 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))));
                    while (nodeScope26 && *((::CleanExtra **)((void *)(nodeScope26))))
                    {
                        wornScope25 = *((::CleanExtra **)((void *)(nodeScope26)));
                        nodeScope26 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope26))->FUN_00726070()));
                        reinterpret_cast<::FUN_0041aed0_shell *>((wornScope25))->FUN_0041aed0();
                    }
                }

                if (reinterpret_cast<::FUN_004bddd0_shell *>((itemScope4Local28))->FUN_004bddd0(false) && !reinterpret_cast<::InventoryStackRecord *>((itemScope4Local28))->HasPerkEntry())
                {
                    if (itemScope4Local28->count > 0 &&
                        itemScope4Local28->count >= (*((::CleanBaseEntry **)((void *)(baseScope8))))->count)
                        itemScope4Local28->count = 0;
                }
                else if (reinterpret_cast<::FUN_004bddd0_shell *>((itemScope4Local28))->FUN_004bddd0(false) && reinterpret_cast<::InventoryStackRecord *>((itemScope4Local28))->HasPerkEntry())
                {
                    if (itemScope4Local28->count < 0)
                        reinterpret_cast<::ItemChange_004be3d0 *>((itemScope4Local28))->SetExtraListFlag(0, 0, true);
                    int countScope27 = reinterpret_cast<::FUN_004bca80_shell *>((itemScope4Local28))->CountAndPruneEntries();
                    if (countScope27 > 1)
                    {
                        CleanNode* nodeScope28 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))));
                        while (nodeScope28 && *((::CleanExtra **)((void *)(nodeScope28))))
                        {
                            CleanExtra* extraScope29 = *((::CleanExtra **)((void *)(nodeScope28)));
                            nodeScope28 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope28))->FUN_00726070()));
                            if (extraScope29 && reinterpret_cast<::FUN_00418ab0_shell *>((extraScope29))->FUN_00418ab0(false) && !wornScope25)
                                wornScope25 = extraScope29;
                            else if (wornScope25)
                            {
                                reinterpret_cast<::FUN_0040fae0_shell *>((wornScope25))->FUN_0040fae0(true);
                                reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((wornScope25))->FUN_00412380((::ExtraDataList *)(extraScope29));
                                reinterpret_cast<::FUN_0041aa20_shell *>((wornScope25))->SetWornState(true, false);
                                reinterpret_cast<::FileMatchList *>((((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))))))->RemoveAll();
                                ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))))->FUN_005ae3d0(&wornScope25);
                            }
                        }
                    }
                    if (itemScope4Local28->count < reinterpret_cast<::FUN_004bc8f0_stand *>((itemScope4Local28))->FUN_004bc8f0(false))
                        itemScope4Local28->count = reinterpret_cast<::FUN_004bc8f0_stand *>((itemScope4Local28))->FUN_004bc8f0(false);
                }
                else if (reinterpret_cast<::FUN_004bddd0_shell *>((itemScope4Local28))->FUN_004bddd0(false))
                {
                    if (itemScope4Local28->count < reinterpret_cast<::FUN_004bc8f0_stand *>((itemScope4Local28))->FUN_004bc8f0(false))
                        itemScope4Local28->count = reinterpret_cast<::FUN_004bc8f0_stand *>((itemScope4Local28))->FUN_004bc8f0(false);
                    else if (itemScope4Local28->count > reinterpret_cast<::FUN_004bc8f0_stand *>((itemScope4Local28))->FUN_004bc8f0(false))
                    {
                        CleanNode* nodeScope30 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))));
                        while (nodeScope30 && *((::CleanExtra **)((void *)(nodeScope30))))
                        {
                            CleanExtra* extraScope31 = *((::CleanExtra **)((void *)(nodeScope30)));
                            nodeScope30 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope30))->FUN_00726070()));
                            if (extraScope31 && reinterpret_cast<::FUN_00418ab0_shell *>((extraScope31))->FUN_00418ab0(false))
                                reinterpret_cast<::FUN_00419ad0_shell *>((extraScope31))->FUN_00419ad0((unsigned short)itemScope4Local28->count);
                        }
                    }
                }
            }
            int totalScope32 = 0;
            int baseCountScope33 = (*((::CleanBaseEntry **)((void *)(baseScope8))))->count;
            if (baseCountScope33 < 0)
                baseCountScope33 *= -1;
            if (itemScope4Local28)
                totalScope32 += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope4Local28))->FUN_00726070())) + baseCountScope33;
            else
                totalScope32 += baseCountScope33;
            if (totalScope32 > 0 && itemScope4Local28 && ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28)))) &&
                ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))))->FUN_005ae380())
            {
                CleanNode* nodeScope34 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))));

                while (totalScope32 < nodeScope34->FUN_005ae380())
                {
                    CleanExtra* extraScope35 = *((::CleanExtra **)((void *)(nodeScope34)));
                    nodeScope34->FUN_0063f7b0();
                    if (extraScope35)
                    {
                        CleanExtra* destinationScope36 = *((::CleanExtra **)((void *)(nodeScope34)));
                        if (destinationScope36)
                        {
                            CleanDatum* dataScope37 = ((::CleanDatum *)(reinterpret_cast<::Callees *>((extraScope35))->FUN_00726070()));
                            while (dataScope37)
                            {
                                if (((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((destinationScope36))->FUN_00410220(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((dataScope37))->IsPatrolling()))))))
                                {
                                    reinterpret_cast<::FUN_00410020_t *>((extraScope35))->FUN_00410020((::BSExtraData *)(dataScope37), true);
                                    dataScope37 = ((::CleanDatum *)(reinterpret_cast<::Callees *>((extraScope35))->FUN_00726070()));
                                }
                                else
                                {
                                    reinterpret_cast<::FUN_00410020_t *>((extraScope35))->FUN_00410020((::BSExtraData *)(dataScope37), false);
                                    reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((destinationScope36))->FUN_0040ff60((::BSExtraData *)(dataScope37));
                                    dataScope37 = ((::CleanDatum *)(reinterpret_cast<::Callees *>((extraScope35))->FUN_00726070()));
                                }
                            }
                        }
                        delete extraScope35;
                    }
                }
                if (nodeScope34->FUN_008256d0())
                {
                    delete itemScope4Local28->head;
                    itemScope4Local28->head = 0;
                }
                else
                    nodeScope34 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))));

                if (nodeScope34 && *((::CleanExtra **)((void *)(nodeScope34))))
                {

                    while (nodeScope34 && *((::CleanExtra **)((void *)(nodeScope34))))
                    {
                        CleanExtra* extraScope38 = *((::CleanExtra **)((void *)(nodeScope34)));
                        if (reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extraScope38))->FUN_0040fe20() < 1)
                        {
                            nodeScope34->FUN_0063f7b0();
                            extraScope38 = 0;
                            if (itemScope4Local28->head->FUN_008256d0())
                            {
                                reinterpret_cast<::FileMatchList *>((nodeScope34))->RemoveAll();
                                delete nodeScope34;
                                nodeScope34 = 0;
                                itemScope4Local28->head = 0;
                            }
                            else
                                nodeScope34 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope4Local28))));
                        }
                        else
                            nodeScope34 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope34))->FUN_00726070()));
                    }
                }
            }
        }
        baseScope8 = ((::CleanBaseNode *)(reinterpret_cast<::Callees *>((baseScope8))->FUN_00726070()));
    }
    CleanItem* itemScope39 = 0;
    CleanItemNode* changeScope4 = head;
    while (changeScope4 && !changeScope4->FUN_008256d0())
    {
        itemScope39 = *((::CleanItem **)((void *)(changeScope4)));
        int baseCountScope41 = 0;
        if (((::CleanContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) && itemScope39)
            baseCountScope41 = reinterpret_cast<::TESContainer *>((((::CleanContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(itemScope39->form));
        int totalScope8 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope39))->FUN_00726070())) + baseCountScope41;

        if (itemScope39)
        {
            TESHealthForm* healthScope43 = dynamic_cast<TESHealthForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope39))->GetName())));
            if (healthScope43 && itemScope39->head)
            {
                CleanNode* nodeScope44 = itemScope39->head;
                while (nodeScope44 && *((::CleanExtra **)((void *)(nodeScope44))))
                {
                    CleanExtra* extraScope45 = *((::CleanExtra **)((void *)(nodeScope44)));
                    if (((double)(reinterpret_cast<::FUN_004186f0_shell *>((extraScope45))->FUN_004186f0())) > -1.0 &&
                        ((double)(reinterpret_cast<::FUN_004186f0_shell *>((extraScope45))->FUN_004186f0())) == healthScope43->GetHealth())
                    {
                        reinterpret_cast<::FUN_0041aef0_StandIn *>((extraScope45))->FUN_0041aef0();
                        int countScope46 = reinterpret_cast<::FUN_00418770_shell *>((extraScope45))->FUN_00418770();
                        reinterpret_cast<::FUN_0041af10_Class *>((extraScope45))->RemoveExtra24();
                        if (reinterpret_cast<::ExtraDataList *>((extraScope45))->IsEmpty())
                        {
                            reinterpret_cast<::ItemChangeListNode *>((nodeScope44))->FUN_00905330((*(::InventoryStackRecord *const *)(&extraScope45)));
                            delete extraScope45;
                            nodeScope44 = itemScope39->head;
                        }
                        else
                        {
                            reinterpret_cast<::FUN_00419ad0_shell *>((extraScope45))->FUN_00419ad0((unsigned short)countScope46);
                            nodeScope44 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope44))->FUN_00726070()));
                        }
                    }
                    else
                        nodeScope44 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope44))->FUN_00726070()));
                }
            }
        }

        int equippedCountScope2 = reinterpret_cast<::FUN_004bc8f0_stand *>((itemScope39))->FUN_004bc8f0(false);
        formScope7 = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope39))->GetName()));

        if (itemScope39 && ((::CleanScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemScope39))->FUN_004bde40())))
        {
            CleanNode* nodeScope48 = itemScope39->head;
            while (nodeScope48 && *((::CleanExtra **)((void *)(nodeScope48))))
            {
                CleanExtra* extraScope49 = *((::CleanExtra **)((void *)(nodeScope48)));
                if (extraScope49 && ((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope49))->FUN_00418800())))
                {
                    CleanNode* nextScope50 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope48))->FUN_00726070()));
                    while (nextScope50 && *((::CleanExtra **)((void *)(nextScope50))))
                    {
                        CleanExtra* otherScope51 = *((::CleanExtra **)((void *)(nextScope50)));
                        if (extraScope49 == otherScope51)
                        {
                            nextScope50->FUN_0063f7b0();
                            CleanExtra* copyScope52 = new CleanExtra;
                            reinterpret_cast<::FUN_00419ed0_shell *>((copyScope52))->FUN_00419ed0((::Script *)(::CleanScript *)(((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope49))->FUN_00418800()))));
                            reinterpret_cast<::FUN_00419f80_shell *>((copyScope52))->FUN_00419f80((::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_005abf60_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((copyScope52))->FUN_00418800()))))->FUN_005abf60()))));
                            CleanRef* refScope6 = new CleanRef;
                            reinterpret_cast<::TESForm *>((refScope6))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope49))->FUN_00418800()))))->FUN_005ac1e0((::TESObjectREFR *)(refScope6), (::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_00418830_shell *>((copyScope52))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                            reinterpret_cast<::Callees *>((nextScope50))->FUN_00905820(&copyScope52);
                            nextScope50 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope48))->FUN_00726070()));
                        }
                        else
                            nextScope50 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nextScope50))->FUN_00726070()));
                    }
                }
                nodeScope48 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope48))->FUN_00726070()));
            }
        }

        if (itemScope39 && itemScope39->count >= 0)
        {
            CleanScript* scriptScope54 = ((::CleanScript *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope39))->GetName()))))));
            if (scriptScope54)
            {

                CleanNode* nodeScope55 = itemScope39->head;
                if (!nodeScope55 || nodeScope55->FUN_008256d0())
                    reinterpret_cast<::fnv_004d1960::InvInventory *>(this)->FUN_004d1960();
                else
                {
                    int missingScope56 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope39))->FUN_00726070())) - nodeScope55->FUN_005ae380();
                    while (nodeScope55 && *((::CleanExtra **)((void *)(nodeScope55))))
                    {
                        CleanExtra* extraScope57 = *((::CleanExtra **)((void *)(nodeScope55)));
                        if (extraScope57 && !((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope57))->FUN_00418800())))
                        {
                            reinterpret_cast<::FUN_00419ed0_shell *>((extraScope57))->FUN_00419ed0((::Script *)(scriptScope54));
                            reinterpret_cast<::FUN_00419f80_shell *>((extraScope57))->FUN_00419f80((::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_005abf60_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope57))->FUN_00418800()))))->FUN_005abf60()))));
                            CleanRef* refScope58 = new CleanRef;
                            reinterpret_cast<::TESForm *>((refScope58))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemScope39))->FUN_004bde40()))))->FUN_005ac1e0((::TESObjectREFR *)(refScope58), (::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_00418830_shell *>((extraScope57))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                        }
                        nodeScope55 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope55))->FUN_00726070()));
                    }
                    nodeScope55 = itemScope39->head;
                    for (int iScope59 = 0; iScope59 < missingScope56; ++iScope59)
                    {
                        CleanExtra* extraScope60 = new CleanExtra;
                        reinterpret_cast<::FUN_00419ed0_shell *>((extraScope60))->FUN_00419ed0((::Script *)(::CleanScript *)(((::CleanScript *)(reinterpret_cast<::FUN_004bde40_shell *>((itemScope39))->FUN_004bde40()))));
                        reinterpret_cast<::FUN_00419f80_shell *>((extraScope60))->FUN_00419f80((::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_005abf60_shell *>((((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope60))->FUN_00418800()))))->FUN_005abf60()))));
                        CleanRef* refScope61 = new CleanRef;
                        reinterpret_cast<::TESForm *>((refScope61))->NotifySaveLoadGameOfFormChange();
                        reinterpret_cast<::FUN_005ac1e0_shell *>((scriptScope54))->FUN_005ac1e0((::TESObjectREFR *)(refScope61), (::ScriptLocals *)(::CleanEvent *)(((::CleanEvent *)(reinterpret_cast<::FUN_00418830_shell *>((extraScope60))->FUN_00418830()))), (::TESObjectREFR *)(0), 0);
                        delete refScope61;
                        nodeScope55->FUN_005ae3d0(&extraScope60);
                    }
                }
            }
        }
        if (itemScope39 && reinterpret_cast<CleanFormView*>(formScope7)->FUN_00401170() == 41)
        {
            int baseCountScope62 = 0;
            if (((::CleanContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) && itemScope39)
                baseCountScope62 = reinterpret_cast<::TESContainer *>((((::CleanContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(itemScope39->form));
            CleanExtra* wornScope5 = 0;

            if (owner == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
            {
                CleanNode* nodeScope64 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope39))));
                while (nodeScope64 && *((::CleanExtra **)((void *)(nodeScope64))))
                {
                    wornScope5 = *((::CleanExtra **)((void *)(nodeScope64)));
                    nodeScope64 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope64))->FUN_00726070()));
                    reinterpret_cast<::FUN_0041aed0_shell *>((wornScope5))->FUN_0041aed0();
                }
            }

            if (reinterpret_cast<::FUN_004bddd0_shell *>((itemScope39))->FUN_004bddd0(false))
            {
                CleanNode* nodeScope65 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope39))));
                int sumScope66 = 0;
                while (nodeScope65 && *((::CleanExtra **)((void *)(nodeScope65))))
                {
                    CleanExtra* extraScope67 = *((::CleanExtra **)((void *)(nodeScope65)));
                    sumScope66 += reinterpret_cast<::FUN_00418770_shell *>((extraScope67))->FUN_00418770();
                    nodeScope65 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope65))->FUN_00726070()));
                }
                if (itemScope39->count + baseCountScope62 < sumScope66)
                    itemScope39->count = sumScope66 - (itemScope39->count + baseCountScope62);
                else if (itemScope39->count + baseCountScope62 > sumScope66)
                {
                    CleanNode* nodeScope68 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope39))));
                    while (nodeScope68 && *((::CleanExtra **)((void *)(nodeScope68))))
                    {
                        CleanExtra* extraScope69 = *((::CleanExtra **)((void *)(nodeScope68)));
                        nodeScope68 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope68))->FUN_00726070()));
                        if (extraScope69 && reinterpret_cast<::FUN_00418ab0_shell *>((extraScope69))->FUN_00418ab0(false))
                            reinterpret_cast<::FUN_00419ad0_shell *>((extraScope69))->FUN_00419ad0((unsigned short)itemScope39->count);
                    }
                }
            }
        }
        if (itemScope39 && itemScope39->head)
        {
            CleanNode* nodeScope70 = itemScope39->head;
            while (nodeScope70 && *((::CleanExtra **)((void *)(nodeScope70))))
            {
                CleanExtra* extraScope71 = *((::CleanExtra **)((void *)(nodeScope70)));
                if (extraScope71 && ((::CleanScript *)(reinterpret_cast<::FUN_00418800_shell *>((extraScope71))->FUN_00418800())))
                    reinterpret_cast<::FUN_0041af10_Class *>((extraScope71))->RemoveExtra24();
                nodeScope70 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope70))->FUN_00726070()));
            }
        }

        if (itemScope39 && ::FUN_00481f10((::TESObject *)(formScope7)) && owner == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)) && itemScope39->head)
        {
            CleanNode* nodeScope72 = itemScope39->head;
            while (nodeScope72 && *((::CleanExtra **)((void *)(nodeScope72))))
            {
                CleanExtra* extraScope73 = *((::CleanExtra **)((void *)(nodeScope72)));
                nodeScope72->FUN_0063f7b0();
                delete extraScope73;
            }
        }

        if (itemScope39 && totalScope8 < equippedCountScope2 && itemScope39->head)
        {
            int sumScope74 = 0;
            CleanNode* nodeScope75 = itemScope39->head;
            while (nodeScope75 && *((::CleanExtra **)((void *)(nodeScope75))))
            {
                CleanExtra* extraScope76 = *((::CleanExtra **)((void *)(nodeScope75)));
                sumScope74 += reinterpret_cast<::FUN_00418770_shell *>((extraScope76))->FUN_00418770();
                nodeScope75 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope75))->FUN_00726070()));
            }
            itemScope39->count = sumScope74;
        }
        if (itemScope39 && totalScope8 > 0)
        {
            CleanNode* nodeScope77 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope39))));
            if (nodeScope77 && *((::CleanExtra **)((void *)(nodeScope77))))
            {

                while (totalScope8 < nodeScope77->FUN_005ae380())
                {
                    CleanExtra* extraScope78 = *((::CleanExtra **)((void *)(nodeScope77)));
                    nodeScope77->FUN_0063f7b0();
                    if (extraScope78)
                    {
                        CleanExtra* destinationScope79 = *((::CleanExtra **)((void *)(nodeScope77)));
                        if (destinationScope79)
                        {
                            CleanDatum* dataScope80 = ((::CleanDatum *)(reinterpret_cast<::Callees *>((extraScope78))->FUN_00726070()));
                            while (dataScope80)
                            {
                                if (((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((destinationScope79))->FUN_00410220(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((dataScope80))->IsPatrolling()))))))
                                {
                                    reinterpret_cast<::FUN_00410020_t *>((extraScope78))->FUN_00410020((::BSExtraData *)(dataScope80), true);
                                    dataScope80 = ((::CleanDatum *)(reinterpret_cast<::Callees *>((extraScope78))->FUN_00726070()));
                                }
                                else
                                {
                                    reinterpret_cast<::FUN_00410020_t *>((extraScope78))->FUN_00410020((::BSExtraData *)(dataScope80), false);
                                    reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((destinationScope79))->FUN_0040ff60((::BSExtraData *)(dataScope80));
                                    dataScope80 = ((::CleanDatum *)(reinterpret_cast<::Callees *>((extraScope78))->FUN_00726070()));
                                }
                            }
                        }
                        delete extraScope78;
                    }
                }
                if (nodeScope77->FUN_008256d0())
                {
                    delete itemScope39->head;
                    itemScope39->head = 0;
                }
                else
                    nodeScope77 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope39))));

                while (nodeScope77 && *((::CleanExtra **)((void *)(nodeScope77))))
                {
                    CleanExtra* extraScope81 = *((::CleanExtra **)((void *)(nodeScope77)));
                    if (reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extraScope81))->FUN_0040fe20() < 1)
                    {
                        nodeScope77->FUN_0063f7b0();
                        extraScope81 = 0;
                        if (itemScope39->head->FUN_008256d0())
                        {
                            reinterpret_cast<::FileMatchList *>((nodeScope77))->RemoveAll();
                            delete nodeScope77;
                            nodeScope77 = 0;
                            itemScope39->head = 0;
                        }
                        else
                            nodeScope77 = ((::CleanNode *)(::FUN_00559450((int *)(itemScope39))));
                    }
                    else
                        nodeScope77 = ((::CleanNode *)(reinterpret_cast<::Callees *>((nodeScope77))->FUN_00726070()));
                }
            }
        }
        changeScope4 = ((::CleanItemNode *)(reinterpret_cast<::Callees *>((changeScope4))->FUN_00726070()));
    }
}
struct FUN_00418b10_shell
{
    bool FUN_00418b10();
};
// Scans the container and inventory changes for a usable weapon matching kind, scores candidates, and returns the best change with its score written to output.
// @fnv 0x004c7400
FUN_0076b630* Target::SelectBestWeapon(ActorStand* subject, float* apfScore, int kind, bool worn)
{
    ActorStand* a;
    {
        float b;
        {
            float c;
            {
                BaseNode* d;
                {
                    ItemList* e;
                    {
                        FUN_0076b630* f;
                        {
                            AutoMemContext g((MEM_CONTEXT)54, true, ::DAT_01020778, 0x1444);
                            {
                                float h;
                                {
                                    int i;
                                    {
                                        float j;
                                        {
                                            Weapon* k;
                                            {
                                                float l;
                                                {
                                                    float m;
                                                    {
                                                        ActorStand* pScoringActor;
                                                        {

                                                            l = 0.0f;
                                                            k = 0;
                                                            f = 0;
                                                            pScoringActor = subject;
                                                            a = 0;
                                                            if (owner && owner->v100())
                                                            {
                                                                a = owner;
                                                                pScoringActor = a;
                                                                if (((::ProcessStand *)(reinterpret_cast<::BSShaderNoLightingProperty *>((a))->GetBaseTexture())) && ((::ProcessStand *)(reinterpret_cast<::BSShaderNoLightingProperty *>((a))->GetBaseTexture()))->v388())
                                                                    return f;
                                                            }
                                                            if (worn)
                                                            {
                                                                FUN_0076b630* wornItem = FUN_004c8c10(5, 0);
                                                                if (wornItem && reinterpret_cast<::FUN_00418b10_shell *>((((::Extra *)((void *)(((::FUN_0096a2d0 *)(::FUN_00559450((int *)(wornItem)))))))))->FUN_00418b10())
                                                                    return wornItem;
                                                                else
                                                                    delete (FUN_004459e0*)wornItem;
                                                            }
                                                            d = ((::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
                                                            c = 0.0f;
                                                            m = reinterpret_cast<::ActorValueOwner *>(&(subject->stats))->GetActorValueFloatByIndex((::ActorValue::Index)(11));
                                                            b = (float)reinterpret_cast<::ActorValueOwner *>(&(subject->stats))->GetActorValueAsInteger((::ActorValue::Index)(5));
                                                            h = 0.0f;
                                                            if (a)
                                                                h = reinterpret_cast<::FUN_00893530_shell *>((a))->GetFatigueRatio();
                                                            else
                                                                h = 1.0f;
                                                            i = 1;
                                                            j = 1.0f;
                                                            while (d)
                                                            {
                                                                BaseItem* entry;
                                                                {
                                                                    Weapon* weapon;
                                                                    {
                                                                        FUN_0076b630* change;
                                                                        {
                                                                            bool found;
                                                                            {
                                                                                float score;
                                                                                {
                                                                                    FUN_0076b630* ammoItem;
                                                                                    {
                                                                                        bool usable;
                                                                                        {
                                                                                            ActorStand* ownerActor;
                                                                                            {
                                                                                                AmmoLink* pAmmoLink;
                                                                                                {
                                                                                                    Ammo* ammo;
                                                                                                    {
                                                                                                        FUN_0096a2d0*
                                                                                                            extraNode;
                                                                                                        {
                                                                                                            Extra*
                                                                                                                extra;
                                                                                                            {
                                                                                                                void*
                                                                                                                    health;
                                                                                                                {
                                                                                                                    float
                                                                                                                        itemHealth;
                                                                                                                    {
                                                                                                                        entry =
                                                                                                                            ((::BaseItem *)((void *)(d)));
                                                                                                                        weapon =
                                                                                                                            0;
                                                                                                                        if (entry &&
                                                                                                                            entry->form
                                                                                                                                    ->FUN_00401170() ==
                                                                                                                                40)
                                                                                                                            weapon =
                                                                                                                                entry
                                                                                                                                    ->form;
                                                                                                                        if (weapon)
                                                                                                                        {
                                                                                                                            change = ((::FUN_0076b630 *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(
                                                                                                                                (::TESBoundObject *)(weapon),
                                                                                                                                true,
                                                                                                                                0)));
                                                                                                                            if ((!change ||
                                                                                                                                 (change &&
                                                                                                                                  change->count +
                                                                                                                                          ((::BaseItem *)((void *)(d)))
                                                                                                                                              ->count >
                                                                                                                                      0) ||
                                                                                                                                 ((::BaseItem *)((void *)(d)))
                                                                                                                                         ->count <
                                                                                                                                     0) &&
                                                                                                                                weapon &&
                                                                                                                                (kind ==
                                                                                                                                     6 ||
                                                                                                                                 kind ==
                                                                                                                                     reinterpret_cast<::CombatWeapon *>((weapon))->FUN_00522c80()))
                                                                                                                            {
                                                                                                                                score =
                                                                                                                                    -1.0f;
                                                                                                                                usable =
                                                                                                                                    true;
                                                                                                                                found =
                                                                                                                                    false;
                                                                                                                                ownerActor =
                                                                                                                                    owner->v100()
                                                                                                                                        ? owner
                                                                                                                                        : 0;
                                                                                                                                ammoItem = ((::FUN_0076b630 *)(reinterpret_cast<::FUN_004c7300_shell *>(this)->FindInventoryItem(
                                                                                                                                    (::TESObjectREFR *)(weapon),
                                                                                                                                    &found)));
                                                                                                                                if (found &&
                                                                                                                                    !ammoItem)
                                                                                                                                    usable =
                                                                                                                                        false;
                                                                                                                                if (a &&
                                                                                                                                    (!reinterpret_cast<::ActionOwner *>((a))->FUN_008bc9d0(
                                                                                                                                         (::TargetObject *)(weapon),
                                                                                                                                         true) ||
                                                                                                                                     !usable))
                                                                                                                                {
                                                                                                                                    score =
                                                                                                                                        -1000.0f;
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    i = weapon
                                                                                                                                            ->value
                                                                                                                                            .v10();
                                                                                                                                    pAmmoLink =
                                                                                                                                        weapon
                                                                                                                                            ? &weapon
                                                                                                                                                   ->ammo
                                                                                                                                            : 0;
                                                                                                                                    ammo =
                                                                                                                                        pAmmoLink
                                                                                                                                            ? ((::Ammo *)(reinterpret_cast<::Callees *>((pAmmoLink))->FUN_00726070()))
                                                                                                                                            : 0;
                                                                                                                                    c = subject
                                                                                                                                            ->stats
                                                                                                                                            .vc(((int)(reinterpret_cast<::FUN_008d85e0_Class *>((weapon))->GetUnk15C())));
                                                                                                                                    if (change &&
                                                                                                                                        change
                                                                                                                                            ->extras &&
                                                                                                                                        ((::Extra *)((void *)(change
                                                                                                                                            ->extras))))
                                                                                                                                    {
                                                                                                                                        if (ammo &&
                                                                                                                                            change->FUN_004bd350() <
                                                                                                                                                ammo->damage
                                                                                                                                                    .v8(0))
                                                                                                                                            ammo =
                                                                                                                                                0;
                                                                                                                                        extraNode =
                                                                                                                                            change
                                                                                                                                                ->extras;
                                                                                                                                        while (
                                                                                                                                            extraNode)
                                                                                                                                        {
                                                                                                                                            extra =
                                                                                                                                                ((::Extra *)((void *)(extraNode)));
                                                                                                                                            if (extra)
                                                                                                                                            {
                                                                                                                                                health =
                                                                                                                                                    ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((extra))->FUN_00410220(
                                                                                                                                                            37)));
                                                                                                                                                itemHealth =
                                                                                                                                                    0.0f;
                                                                                                                                                if (health)
                                                                                                                                                    itemHealth =
                                                                                                                                                        reinterpret_cast<::FUN_004186f0_shell *>((extra))->FUN_004186f0();
                                                                                                                                                else
                                                                                                                                                    itemHealth =
                                                                                                                                                        (float)::TESHealthForm::GetBaseHealth(
                                                                                                                                                            (::TESForm *)(weapon));
                                                                                                                                                if (itemHealth >
                                                                                                                                                    0.0)
                                                                                                                                                {
                                                                                                                                                    j = itemHealth /
                                                                                                                                                        ::TESHealthForm::GetBaseHealth(
                                                                                                                                                            (::TESForm *)(weapon));
                                                                                                                                                    score = ::ComputeWeaponDamage(
                                                                                                                                                        (::CombatActorForm *)(pScoringActor),
                                                                                                                                                        (::DamageWeapon *)(weapon),
                                                                                                                                                        j,
                                                                                                                                                        (::DamageAmmo *)(0),
                                                                                                                                                        change,
                                                                                                                                                        ammoItem);
                                                                                                                                                    if (score >
                                                                                                                                                        l)
                                                                                                                                                    {
                                                                                                                                                        l = score;
                                                                                                                                                        k = weapon;
                                                                                                                                                        delete (
                                                                                                                                                            FUN_004459e0*)
                                                                                                                                                            f;
                                                                                                                                                        f = new FUN_0076b630;
                                                                                                                                                        f->weapon =
                                                                                                                                                            weapon;
                                                                                                                                                        f->extras =
                                                                                                                                                            new FUN_0096a2d0;
                                                                                                                                                        f->extras
                                                                                                                                                            ->FUN_005ae3d0(
                                                                                                                                                                &extra);
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            extraNode =
                                                                                                                                                ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070()));
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    else
                                                                                                                                    {
                                                                                                                                        score = ::ComputeWeaponDamage(
                                                                                                                                            (::CombatActorForm *)(pScoringActor),
                                                                                                                                            (::DamageWeapon *)(weapon),
                                                                                                                                            j,
                                                                                                                                            (::DamageAmmo *)(0),
                                                                                                                                            change,
                                                                                                                                            ammoItem);
                                                                                                                                        if (score >
                                                                                                                                            l)
                                                                                                                                        {
                                                                                                                                            l = score;
                                                                                                                                            k = weapon;
                                                                                                                                            delete (
                                                                                                                                                FUN_004459e0*)
                                                                                                                                                f;
                                                                                                                                            f = new FUN_0076b630;
                                                                                                                                            f->weapon =
                                                                                                                                                weapon;
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                d = ((::BaseNode *)(reinterpret_cast<::Callees *>((d))->FUN_00726070()));
                                                            }
                                                            e = changes;
                                                            while (e && !e->FUN_008256d0())
                                                            {
                                                                FUN_0076b630* change;
                                                                {
                                                                    Weapon* weapon;
                                                                    {
                                                                        bool found;
                                                                        {
                                                                            FUN_0076b630* ammoItem;
                                                                            {
                                                                                bool usable;
                                                                                {
                                                                                    ActorStand* ownerActor;
                                                                                    {
                                                                                        float score;
                                                                                        {
                                                                                            FUN_0096a2d0* extraNode;
                                                                                            {
                                                                                                void* health;
                                                                                                {
                                                                                                    Extra* extra;
                                                                                                    {
                                                                                                        float
                                                                                                            itemHealth;
                                                                                                        {
                                                                                                            AmmoLink*
                                                                                                                pAmmoLink;
                                                                                                            {
                                                                                                                Ammo*
                                                                                                                    ammo;
                                                                                                                {
                                                                                                                    weapon =
                                                                                                                        0;
                                                                                                                    change =
                                                                                                                        ((::FUN_0076b630 *)((void *)(e)));
                                                                                                                    if (change
                                                                                                                            ->weapon
                                                                                                                            ->FUN_00401170() ==
                                                                                                                        40)
                                                                                                                        weapon =
                                                                                                                            change
                                                                                                                                ->weapon;
                                                                                                                    if (weapon)
                                                                                                                    {
                                                                                                                        usable =
                                                                                                                            true;
                                                                                                                        found =
                                                                                                                            false;
                                                                                                                        ownerActor =
                                                                                                                            owner->v100()
                                                                                                                                ? owner
                                                                                                                                : 0;
                                                                                                                        ammoItem = ((::FUN_0076b630 *)(reinterpret_cast<::FUN_004c7300_shell *>(this)->FindInventoryItem(
                                                                                                                            (::TESObjectREFR *)(weapon),
                                                                                                                            &found)));
                                                                                                                        if (found &&
                                                                                                                            !ammoItem)
                                                                                                                            usable =
                                                                                                                                false;
                                                                                                                        if ((kind ==
                                                                                                                                 6 ||
                                                                                                                             kind ==
                                                                                                                                 reinterpret_cast<::CombatWeapon *>((weapon))->FUN_00522c80()) &&
                                                                                                                            ((::ItemList *)(reinterpret_cast<::Callees *>((change))->FUN_00726070())) &&
                                                                                                                            !reinterpret_cast<::TESContainer *>((((::Container *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType(
                                                                                                                                     (::TESObject *)(weapon)) &&
                                                                                                                            reinterpret_cast<::ActionOwner *>((a))->FUN_008bc9d0(
                                                                                                                                (::TargetObject *)(weapon),
                                                                                                                                true) &&
                                                                                                                            (!reinterpret_cast<::InventoryStackRecord *>((change))->HasPerkEntry() ||
                                                                                                                             change->count >=
                                                                                                                                 0) &&
                                                                                                                            usable)
                                                                                                                        {
                                                                                                                            score =
                                                                                                                                -1.0f;
                                                                                                                            if (score >=
                                                                                                                                -1.0)
                                                                                                                            {
                                                                                                                                c = subject
                                                                                                                                        ->stats
                                                                                                                                        .vc(((int)(reinterpret_cast<::FUN_008d85e0_Class *>((weapon))->GetUnk15C())));
                                                                                                                                i = weapon
                                                                                                                                        ->value
                                                                                                                                        .v10();
                                                                                                                                if (change &&
                                                                                                                                    change
                                                                                                                                        ->extras &&
                                                                                                                                    ((::Extra *)((void *)(change
                                                                                                                                        ->extras))))
                                                                                                                                {
                                                                                                                                    extraNode =
                                                                                                                                        change
                                                                                                                                            ->extras;
                                                                                                                                    while (
                                                                                                                                        extraNode &&
                                                                                                                                        ((::Extra *)((void *)(extraNode))))
                                                                                                                                    {
                                                                                                                                        extra =
                                                                                                                                            ((::Extra *)((void *)(extraNode)));
                                                                                                                                        health =
                                                                                                                                            ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((extra))->FUN_00410220(
                                                                                                                                                    37)));
                                                                                                                                        itemHealth =
                                                                                                                                            0.0f;
                                                                                                                                        if (health)
                                                                                                                                            itemHealth =
                                                                                                                                                reinterpret_cast<::FUN_004186f0_shell *>((extra))->FUN_004186f0();
                                                                                                                                        else
                                                                                                                                            itemHealth =
                                                                                                                                                (float)::TESHealthForm::GetBaseHealth(
                                                                                                                                                    (::TESForm *)(weapon));
                                                                                                                                        if (itemHealth >
                                                                                                                                            0.0)
                                                                                                                                        {
                                                                                                                                            pAmmoLink =
                                                                                                                                                weapon
                                                                                                                                                    ? &weapon
                                                                                                                                                           ->ammo
                                                                                                                                                    : 0;
                                                                                                                                            ammo =
                                                                                                                                                pAmmoLink
                                                                                                                                                    ? ((::Ammo *)(reinterpret_cast<::Callees *>((pAmmoLink))->FUN_00726070()))
                                                                                                                                                    : 0;
                                                                                                                                            j = itemHealth /
                                                                                                                                                ::TESHealthForm::GetBaseHealth(
                                                                                                                                                    (::TESForm *)(weapon));
                                                                                                                                            score = ::ComputeWeaponDamage(
                                                                                                                                                (::CombatActorForm *)(pScoringActor),
                                                                                                                                                (::DamageWeapon *)(weapon),
                                                                                                                                                j,
                                                                                                                                                (::DamageAmmo *)(0),
                                                                                                                                                change,
                                                                                                                                                ammoItem);
                                                                                                                                            if (score >
                                                                                                                                                l)
                                                                                                                                            {
                                                                                                                                                l = score;
                                                                                                                                                k = weapon;
                                                                                                                                                delete (
                                                                                                                                                    FUN_004459e0*)
                                                                                                                                                    f;
                                                                                                                                                f = new FUN_0076b630;
                                                                                                                                                f->weapon =
                                                                                                                                                    weapon;
                                                                                                                                                f->extras =
                                                                                                                                                    new FUN_0096a2d0;
                                                                                                                                                f->extras
                                                                                                                                                    ->FUN_005ae3d0(
                                                                                                                                                        &extra);
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        extraNode =
                                                                                                                                            ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070()));
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    score = ::ComputeWeaponDamage(
                                                                                                                                        (::CombatActorForm *)(pScoringActor),
                                                                                                                                        (::DamageWeapon *)(weapon),
                                                                                                                                        j,
                                                                                                                                        (::DamageAmmo *)(0),
                                                                                                                                        change,
                                                                                                                                        ammoItem);
                                                                                                                                    if (score >
                                                                                                                                        l)
                                                                                                                                    {
                                                                                                                                        l = score;
                                                                                                                                        k = weapon;
                                                                                                                                        delete (
                                                                                                                                            FUN_004459e0*)
                                                                                                                                            f;
                                                                                                                                        f = new FUN_0076b630;
                                                                                                                                        f->weapon =
                                                                                                                                            weapon;
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                e = ((::ItemList *)(reinterpret_cast<::Callees *>((e))->FUN_00726070()));
                                                            }
                                                            *apfScore = ::fnv_00644540::ScaleByGameSetting(l, 0, 0);
                                                            if (f)
                                                            {
                                                                Weapon* weapon = ((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((f))->GetName()));
                                                                if (weapon->FUN_00446390() == 10 ||
                                                                    weapon->FUN_00446390() == 11 ||
                                                                    weapon->FUN_00446390() == 13)
                                                                    reinterpret_cast<::CombatProcedure *>((f))->Initialize((::CombatController *)(std::uintptr_t)(reinterpret_cast<::FUN_004c8f30_shell *>(this)->FUN_004c8f30((int)(std::uintptr_t)(((::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((f))->GetName()))))));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            return f;
                        }
                    }
                }
            }
        }
    }
}
// Adds count of form to the inventory entry, creating or splitting extras as needed, then equips or applies it to the actor's process based on form type.
// @fnv 0x004bffe0
void EquipInv::AddItemToInventory(EquipForm* form, int count, EquipActor* actor, EquipExtra* extra, bool left,
                                  bool flag)
{
    AutoMemContext context4_2((MEM_CONTEXT)0x36, true, ::DAT_01020778, 0x960);
    ::FUN_004bf0e0((::InventoryChanges *)this);
    EquipBiped* unusedBiped5;
    if (owner)
    {
        owner->v48(0x20);
        if (form->FUN_00401170() == 0x1a || form->FUN_00401170() == 0x18)
            unusedBiped5 = ((::EquipBiped *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(form))));
    }
    EquipEntry* entry36 = ((::EquipEntry *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(form), 1, 0)));
    int baseCountX = reinterpret_cast<::TESContainer *>((((::EquipContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(form));
    int total5 = baseCountX;
    if (entry36)
        total5 += entry36->count;
    int wornCount3 = 0;
    if (entry36 && entry36->extras)
        wornCount3 = reinterpret_cast<::FUN_004bc8f0_stand *>((entry36))->FUN_004bc8f0(false) + reinterpret_cast<::FUN_004bc980_shell *>((entry36))->FUN_004bc980();
    int availableVal = total5 - wornCount3;
    if (entry36 && entry36->extras)
    {
        if (*((::EquipExtra **)((void *)(entry36->extras))) && reinterpret_cast<::ExtraDataList *>(((*((::EquipExtra **)((void *)(entry36->extras))))))->HasExtraDataType0x2F())
            availableVal = baseCountX - wornCount3;
        bool found = false;
        if (extra && !reinterpret_cast<::RefList *>((entry36->extras))->FUN_005f65d0((void **)&(extra)))
        {
            EquipList* scan = entry36->extras;
            while (scan && *((::EquipExtra **)((void *)(scan))))
            {
                EquipExtra* candidate = *((::EquipExtra **)((void *)(scan)));
                if (candidate && !candidate->FUN_004127e0(extra))
                {
                    extra = candidate;
                    found = true;
                    break;
                }
                else
                    scan = ((::EquipList *)(reinterpret_cast<::Callees *>((scan))->FUN_00726070()));
            }
            if (!found)
                extra = 0;
        }
    }
    bool created3 = true;
    EquipExtra* selected9 = 0;
    if ((!extra && availableVal > 0) || !entry36)
    {
        if (!entry36)
        {
            entry36 = new EquipEntry(form, 0);
            created3 = true;
            reinterpret_cast<::Callees *>((changes))->FUN_00905820((void *)&(entry36));
            extra = 0;
        }
    }
    else
    {
        if (reinterpret_cast<::FUN_004bddd0_shell *>((entry36))->FUN_004bddd0(false))
            return;
        EquipList* scan = entry36->extras;
        while (scan && created3)
        {
            selected9 = *((::EquipExtra **)((void *)(scan)));
            if (extra && extra == selected9)
            {
                bool special = form->FUN_00401170() == 0x28 && ::FUN_004c0bf0((::TESObjectWEAP *)(form));
                if (reinterpret_cast<::FUN_00418770_shell *>((selected9))->FUN_00418770() > 1 && form->FUN_00401170() != 0x29 && !special)
                {
                    extra = new EquipExtra;
                    reinterpret_cast<::fnv_00411ec0::FUN_00411ec0_shell *>((extra))->FUN_00411ec0((::ExtraDataList *)(selected9));
                    reinterpret_cast<::FUN_00419ad0_shell *>((extra))->FUN_00419ad0(1);
                    reinterpret_cast<::FUN_00419ad0_shell *>((selected9))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((selected9))->FUN_00418770() - 1);
                    if (((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((selected9))->GetExtraByteValue())) >= 0)
                        reinterpret_cast<::FUN_0042dec0_shell *>((selected9))->FUN_0042dec0();
                }
                else
                {
                    reinterpret_cast<::FUN_0041aa20_shell *>((selected9))->SetWornState(true, left);
                    reinterpret_cast<::FUN_00419ad0_shell *>((selected9))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry36))->FUN_00726070())));
                }
                created3 = false;
            }
            else if (selected9 && !extra)
            {
                if ((int)reinterpret_cast<::FUN_00418770_shell *>((selected9))->FUN_00418770() == 1)
                    extra = selected9;
                else
                {
                    bool special = form->FUN_00401170() == 0x28 && ::FUN_004c0bf0((::TESObjectWEAP *)(form));
                    if (reinterpret_cast<::FUN_00418770_shell *>((selected9))->FUN_00418770() > 1 && form->FUN_00401170() != 0x29 && !special)
                    {
                        extra = new EquipExtra;
                        reinterpret_cast<::fnv_00411ec0::FUN_00411ec0_shell *>((extra))->FUN_00411ec0((::ExtraDataList *)(selected9));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extra))->FUN_00419ad0(1);
                        reinterpret_cast<::FUN_00419ad0_shell *>((selected9))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((selected9))->FUN_00418770() - 1);
                        if (((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((selected9))->GetExtraByteValue())) >= 0)
                            reinterpret_cast<::FUN_0042dec0_shell *>((selected9))->FUN_0042dec0();
                    }
                    else
                        extra = selected9;
                }
                created3 = false;
            }
            else
                scan = ((::EquipList *)(reinterpret_cast<::Callees *>((scan))->FUN_00726070()));
        }
    }
    if (extra && !reinterpret_cast<::FUN_00418b10_shell *>((extra))->FUN_00418b10())
    {
        reinterpret_cast<::FUN_0041aa20_shell *>((extra))->SetWornState(true, left);
        reinterpret_cast<::FUN_00419ad0_shell *>((extra))->FUN_00419ad0((unsigned short)count);
        created3 = false;
        if (!entry36->extras)
            entry36->extras = new EquipList;
        if (!reinterpret_cast<::RefList *>((entry36->extras))->FUN_005f65d0((void **)&(extra)))
            entry36->extras->FUN_005ae3d0(extra);
        selected9 = extra;
    }
    if (created3)
    {
        selected9 = new EquipExtra;
        reinterpret_cast<::FUN_0041aa20_shell *>((selected9))->SetWornState(true, left);
        if (count > 1)
            reinterpret_cast<::FUN_00419ad0_shell *>((selected9))->FUN_00419ad0((unsigned short)count);
        if (!entry36->extras)
            entry36->extras = new EquipList;
        if (!reinterpret_cast<::RefList *>((entry36->extras))->FUN_005f65d0((void **)&(selected9)))
            entry36->extras->FUN_005ae3d0(selected9);
    }
    if (selected9)
        reinterpret_cast<::FUN_0041ab70_shell *>((selected9))->FUN_0041ab70(flag);
    if (actor->process)
    {
        EquipEntry* equipped = 0;
        EquipBiped* biped = ((::EquipBiped *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(form))));
        switch (form->FUN_00401170())
        {
        case 0x1a:
            actor->process->v468(1);
            break;
        case 0x28:
            equipped = ((::EquipProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v148();
            if (equipped)
            {
                reinterpret_cast<::FileMatchList *>((equipped->extras))->RemoveAll();
                equipped->extras->FUN_005ae3d0(selected9);
                equipped->form = form;
                reinterpret_cast<::fnv_008b0b00::FUN_008b0b00_cls *>((actor))->FUN_008b0b00(0);
            }
            else
            {
                equipped = new EquipEntry(form, count);
                equipped->extras->FUN_005ae3d0(selected9);
                if (!((::EquipProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v160(equipped, actor->v1d0(), 0))
                {
                    delete equipped;
                    equipped = 0;
                }
                else
                {
                    EquipAnim* anim7 = ((::EquipAnim *)(reinterpret_cast<::FUN_008b70d0_shell *>((actor))->FUN_008b70d0()));
                    float speed6 = reinterpret_cast<::FUN_004e4620_shell *>((((::EquipForm *)(reinterpret_cast<::Twin_0044ddc0 *>((equipped))->GetName()))))->FUN_004e4620();
                    ::ApplyPerkModifiers(0x2b, (::Actor *)(actor), ((::EquipForm *)(reinterpret_cast<::Twin_0044ddc0 *>((equipped))->GetName())), &speed6);
                    if (anim7)
                        reinterpret_cast<::FUN_004c0c90_shell *>((anim7))->FUN_004c0c90(speed6);
                }
            }
            if (actor == ((EquipActor*)(*reinterpret_cast<char * *>(&::_g_thePlayer))) || !actor->process->v474(1))
            {
                if (equipped)
                {
                    if (actor == ((EquipActor*)(*reinterpret_cast<char * *>(&::_g_thePlayer))))
                        ::SetField1F0((::FUN_004c0cd0_This *)(((EquipActor*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))), ::FUN_004c0cd0_Arg{equipped->form});
                    else if (FUN_008c7aa0() && actor != ((::EquipActor *)(::FUN_0047b200())))
                        reinterpret_cast<::Host0087b360 *>((((::EquipQueue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b360((std::intptr_t)(actor), (int)(equipped->form));
                    else
                        reinterpret_cast<::fnv_00571760::Actor *>((actor))->FUN_00571760((::fnv_00571760::TESObjectWEAP *)(equipped->form));
                }
            }
            break;
            break;
        case 0x18:
            if (reinterpret_cast<::TESBipedModelForm *>(&(form->biped))->IsPowerArmor() || reinterpret_cast<::TESBipedModelForm *>(&(form->biped))->GetIsHeavyArmor() || reinterpret_cast<::FUN_00480d30_shell *>(&(form->biped))->FUN_00480d30())
            {
                if (((::EquipProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
                    ((::EquipProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v6e4(actor);
            }
            actor->process->v468(1);
            break;
        case 0x29:
            equipped = ((::EquipProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v14c();
            if (equipped)
            {
                reinterpret_cast<::FileMatchList *>((equipped->extras))->RemoveAll();
                equipped->extras->FUN_005ae3d0(selected9);
                equipped->form = form;
            }
            else
            {
                equipped = new EquipEntry(form, 0);
                equipped->extras->FUN_005ae3d0(selected9);
                if (!((::EquipProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v168(equipped))
                {
                    delete equipped;
                    equipped = 0;
                }
            }
            if (!actor->process->v474(1) && equipped)
                reinterpret_cast<::FUN_004534f0_shell *>((actor))->FUN_004534f0((std::uintptr_t)(equipped->form));
            break;
        }
        reinterpret_cast<::FUN_008b0bd0_shell *>((actor))->FUN_008b0bd0((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((actor))->FUN_0043fcd0()))));
    }
}
// Iterates the inventory list, dispels worn items from the actor and removes them, restarting the walk when an entry is removed.
// @fnv 0x004bfe50
void FUN_004bfe50_t::RemoveWornItems(bool abSkipCanNotWear, TESObjectREFR* apRef)
{
    FUN_004bfe50_inode* pInvNode;
    pInvNode = (FUN_004bfe50_inode*)m_pEntryList;
    while (pInvNode)
    {
        InventoryStackRecord* pitem = *((::InventoryStackRecord **)((void *)(pInvNode)));
        if (pitem)
        {
            bool bremoved = false;
            ActorDispelView* pact = (ActorDispelView*)apRef;
            if (reinterpret_cast<::FUN_004bddd0_shell *>((((FUN_004bddd0_t*)pitem)))->FUN_004bddd0(false))
            {
                int iwornCount = 1;
                ExtraDataList* pextra = 0;
                for (FUN_004bfe50_enode* pExtraNode = (FUN_004bfe50_enode*)pitem->m_pExtraDataLists;
                     pExtraNode && *((::ExtraDataList **)((void *)(pExtraNode))); pExtraNode = ((::FUN_004bfe50_enode *)(reinterpret_cast<::Callees *>((pExtraNode))->FUN_00726070())))
                {
                    if (((FUN_00418ab0_shell*)*((::ExtraDataList **)((void *)(pExtraNode))))->FUN_00418ab0(false))
                    {
                        iwornCount = reinterpret_cast<::FUN_00418770_shell *>((void *)(*((::ExtraDataList **)((void *)(pExtraNode)))))->FUN_00418770();
                        pextra = *((::ExtraDataList **)((void *)(pExtraNode)));
                        break;
                    }
                }
                if (pact)
                    reinterpret_cast<::FUN_008248e0_shell *>((pact))->FUN_008248e0((::MagicItem *)(::TESBoundObject *)((TESBoundObject*)((reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pitem)))->GetName()))), true);
                reinterpret_cast<::XHost17 *>((((FUN_004c0cf0_t*)this)))->FUN_004c0cf0(&bremoved, ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pitem)))->GetName())), iwornCount, (::XActor17 *)(::Actor *)((Actor*)pact), pextra, 0, true,
                                   pitem, (bool *)(0));
                if (bremoved)
                    pInvNode = (FUN_004bfe50_inode*)m_pEntryList;
                else
                    pInvNode = ((::FUN_004bfe50_inode *)(reinterpret_cast<::Callees *>((pInvNode))->FUN_00726070()));
            }
            else
            {
                pInvNode = ((::FUN_004bfe50_inode *)(reinterpret_cast<::Callees *>((pInvNode))->FUN_00726070()));
            }
        }
        else
        {
            pInvNode = ((::FUN_004bfe50_inode *)(reinterpret_cast<::Callees *>((pInvNode))->FUN_00726070()));
        }
    }
}
// Forwards all arguments unchanged to FUN_004ce380.
// @fnv 0x004ce340
void FUN_004ce340_stand::FUN_004ce340(std::intptr_t a0, std::intptr_t a1, bool a2, bool a3, bool a4, bool a5, int a6, std::intptr_t a7)
{
    reinterpret_cast<::InventoryMove *>(this)->FUN_004ce380((::MoveOwner *)(a0), (::MoveOwner *)(a1), a2, a3, a4, a5, a6, (::MoveFilter *)(a7));
}
// Iterates the container's base entries and item list, moving matching items to the destination owner and returning the accumulated weight.
// @fnv 0x004ce380
float InventoryMove::FUN_004ce380(MoveOwner* owner, MoveOwner* destination, bool retainOwner, bool SetOwnerPointer,
                                  bool clearOwner, bool silent, int type, MoveFilter* filter)
{
    TESBoundObject* form3 = 0;
    float weight7 = 0.0f;
    bool skipQuest3 = false;
    bool filtered8 = false;
    if (filter)
        filtered8 = true;
    MoveBaseNode* base5 = ((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    TESLevItem* leveled5 = 0;
    while (base5 && !base5->FUN_008256d0())
    {
        form3 = (*((::MoveBaseEntry **)((void *)(base5))))->form;
        leveled5 = dynamic_cast<TESLevItem*>((*((::MoveBaseEntry **)((void *)(base5))))->form);
        MoveFormInfo* infoScope1 = ((::MoveFormInfo *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(form3))));
        if ((filtered8 && reinterpret_cast<::RefList *>((((::MoveFilterResult *)(reinterpret_cast<::BGSCameraPath *>((filter))->GetConditions()))))->FUN_005f65d0({})) ||
            (type > -1 && form3 && reinterpret_cast<MoveForm*>(form3)->FUN_00401170() != type))
        {
            base5 = ((::MoveBaseNode *)(reinterpret_cast<::Callees *>((base5))->FUN_00726070()));
            continue;
        }
        if (reinterpret_cast<MoveForm*>(form3)->IsQuestItem() && owner == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
        {
            MoveItem* quest = ((::MoveItem *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(form3, 1, 0)));
            if (quest && reinterpret_cast<::FUN_004bddd0_shell *>((quest))->FUN_004bddd0(false))
            {
                int baseCountScope1 = reinterpret_cast<::TESContainer *>((((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)((*((::MoveBaseEntry **)((void *)(base5))))->form));
                int countScope9 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((quest))->FUN_00726070())) + baseCountScope1;
                bool removedScope4 = false;
                reinterpret_cast<::XHost17 *>(this)->FUN_004c0cf0(&removedScope4, (std::uintptr_t)(form3), countScope9, (::XActor17 *)(owner), (::ExtraDataList *)(::MoveExtra *)(0), false, false, (::InventoryStackRecord *)(::MoveItem *)(0), 0);
            }
        }
        else if (form3 && !leveled5 && (!infoScope1 || reinterpret_cast<::FUN_00480d90_shell *>((infoScope1))->FUN_00480d90()))
        {
            MoveItem* itemScope1 = ((::MoveItem *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(form3, 1, 0)));
            if (!itemScope1 || !reinterpret_cast<::InventoryStackRecord *>((itemScope1))->HasPerkEntry())
            {
                int countScope2 = 0;
                int baseCountScope2 = reinterpret_cast<::TESContainer *>((((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)((*((::MoveBaseEntry **)((void *)(base5))))->form));
                if (baseCountScope2 < 0)
                    baseCountScope2 *= -1;
                if (itemScope1)
                    countScope2 += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope1))->FUN_00726070())) + baseCountScope2;
                else
                    countScope2 += baseCountScope2;
                if (countScope2 > 0)
                {
                    weight7 += static_cast<float>(::FUN_0048e8a0((::TESForm *)(form3)) * countScope2);
                    bool changed2 = false;
                    if (itemScope1 && ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1)))) && ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1))))->FUN_005ae380())
                    {
                        MoveExtraNode* nodeScope1 = ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1))));
                        if (nodeScope1 && *((::MoveExtra **)((void *)(nodeScope1))))
                        {
                            bool lastScope1 = false;
                            while (nodeScope1 && *((::MoveExtra **)((void *)(nodeScope1))) && !lastScope1)
                            {
                                MoveExtra* extraScope1 = *((::MoveExtra **)((void *)(nodeScope1)));
                                if (reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extraScope1))->FUN_0040fe20() < 1)
                                {
                                    nodeScope1->FUN_0063f7b0();
                                    if (nodeScope1->FUN_008256d0())
                                    {
                                        reinterpret_cast<::FileMatchList *>((nodeScope1))->RemoveAll();
                                        delete nodeScope1;
                                        nodeScope1 = 0;
                                        itemScope1->head = 0;
                                    }
                                    else
                                        nodeScope1 = ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1))));
                                }
                                else
                                {
                                    bool restartScope1 = false;
                                    if (((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1))))->FUN_005ae380() <= 1)
                                        lastScope1 = true;
                                    else
                                        restartScope1 = true;
                                    void* ownershipScope5 = 0;
                                    if (owner->IsActor())
                                    {
                                        void* actorOwnerScope1 = 0;
                                        actorOwnerScope1 = ((void *)(std::uintptr_t)(::FUN_004216f0((::BaseExtraList *)(((::MoveOwnershipProxy *)(reinterpret_cast<::FUN_005d43c0_ *>((owner))->FUN_005d43c0()))))));
                                        if (!actorOwnerScope1)
                                            actorOwnerScope1 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((owner))->FUN_007af430()));
                                        ownershipScope5 = actorOwnerScope1;
                                    }
                                    else
                                        ownershipScope5 = ((void *)(reinterpret_cast<::OwnerLookupView *>((owner))->FUN_00567790()));
                                    if ((retainOwner || SetOwnerPointer) && !::FUN_00481f10((::TESObject *)(form3)))
                                    {
                                        if (!((void *)(reinterpret_cast<::FUN_00418660_shell *>((extraScope1))->FUN_00418660())))
                                            reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((extraScope1))->FUN_00419700((::fnv_00419700::TESForm *)(ownershipScope5));
                                    }
                                    else if (clearOwner)
                                    {
                                        int sizeScope1 = reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extraScope1))->FUN_0040fe20();
                                        if (((void *)(reinterpret_cast<::FUN_00418660_shell *>((extraScope1))->FUN_00418660())) &&
                                            ((reinterpret_cast<::FUN_00418770_shell *>((extraScope1))->FUN_00418770() > 1 && sizeScope1 <= 2) || sizeScope1 <= 1))
                                        {
                                            reinterpret_cast<::FUN_0041aed0_shell *>((extraScope1))->FUN_0041aed0();
                                            extraScope1 = 0;
                                        }
                                        else
                                            reinterpret_cast<::FUN_0041aed0_shell *>((extraScope1))->FUN_0041aed0();
                                    }
                                    countScope2 -= reinterpret_cast<::FUN_00418770_shell *>((extraScope1))->FUN_00418770();
                                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((itemScope1))->FUN_004bddd0(false))
                                        reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, reinterpret_cast<::FUN_00418770_shell *>((extraScope1))->FUN_00418770(),
                                                     (::Transfer4c37Form4 *)(extraScope1), 0, (::Transfer4c37C37Form *)(destination), 0, 0, true, 0, (::Transfer4c37Entry *)(itemScope1));
                                    else
                                    {
                                        bool removedScope2 = false;
                                        bool handled5 = false;
                                        reinterpret_cast<::XHost17 *>(this)->FUN_004c0cf0(&removedScope2, (std::uintptr_t)(form3), ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope1))->FUN_00726070())),
                                                     (::XActor17 *)(::MoveOwner *)(owner->IsActor() ? owner : 0), (::ExtraDataList *)(extraScope1), false, false,
                                                     (::InventoryStackRecord *)(itemScope1), &handled5);
                                        if (!handled5)
                                            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, reinterpret_cast<::FUN_00418770_shell *>((extraScope1))->FUN_00418770(),
                                                         (::Transfer4c37Form4 *)(extraScope1), 0, (::Transfer4c37C37Form *)(destination), 0, 0, true, 0, (::Transfer4c37Entry *)(itemScope1));
                                    }
                                    changed2 = true;
                                    if (lastScope1)
                                    {
                                        itemScope1 = 0;
                                        nodeScope1 = 0;
                                    }
                                    else if (restartScope1)
                                        nodeScope1 = ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1))));
                                    else
                                        nodeScope1 = ((::MoveExtraNode *)(reinterpret_cast<::Callees *>((nodeScope1))->FUN_00726070()));
                                }
                            }
                        }
                    }
                    if (countScope2 > 0)
                    {
                        if (retainOwner || SetOwnerPointer)
                        {
                            itemScope1 = new MoveItem(form3, countScope2);
                            void* ownershipScope5 = 0;
                            ownershipScope5 = ((void *)(std::uintptr_t)(::FUN_004216f0((::BaseExtraList *)(((::MoveOwnershipProxy *)(reinterpret_cast<::FUN_005d43c0_ *>((owner))->FUN_005d43c0()))))));
                            if (!ownershipScope5)
                                ownershipScope5 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((owner))->FUN_007af430()));
                            reinterpret_cast<::ItemChange_4bd5c0 *>((itemScope1))->FUN_004bd5c0(ownershipScope5);
                            MoveExtra* extraScope2 = *((::MoveExtra **)((void *)(((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope1)))))));
                            reinterpret_cast<::FUN_00419ad0_shell *>((extraScope2))->FUN_00419ad0(static_cast<unsigned short>(countScope2));
                            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, reinterpret_cast<::FUN_00418770_shell *>((extraScope2))->FUN_00418770(), (::Transfer4c37Form4 *)(extraScope2), 0,
                                         (::Transfer4c37C37Form *)(destination), 0, 0, true, 0, (::Transfer4c37Entry *)(::MoveItem *)(0));
                        }
                        else
                            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, countScope2, (::Transfer4c37Form4 *)(::MoveExtra *)(0), 0, (::Transfer4c37C37Form *)(destination), 0, 0, true, 0, (::Transfer4c37Entry *)(::MoveItem *)(0));
                        if (destination == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                        {
                            if (form3 && !silent)
                            {
                                MoveString messageScope1;
                                if (countScope2 > 1)
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope1), "%i %s%s %s", countScope2, ::FUN_00482720((::TESForm *)(form3)),
                                                 (*reinterpret_cast<::MoveSetting *>(&::g_011d3114)).FUN_00403df0(), (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                else
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope1), "%s %s", ::FUN_00482720((::TESForm *)(form3)), (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                {
                                case 25:
                                case 30:
                                case 31:
                                case 40:
                                case 41:
                                case 46:
                                case 47:
                                case 50:
                                case 103:
                                case 108:
                                case 115:
                                case 116:
                                    ::DispatchMessageToSink(
                                        (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope1))))), 0,
                                        (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                        false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))), DAT_010162c0, 0);
                                    break;
                                case 24:
                                    ::DispatchMessageToSink(
                                        (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope1))))), 0,
                                        (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                        false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))), DAT_010162c0, 0);
                                    break;
                                }
                            }
                            ::fnv_00704af0::FUN_00704af0();
                        }
                    }
                }
            }
        }
        base5 = ((::MoveBaseNode *)(reinterpret_cast<::Callees *>((base5))->FUN_00726070()));
    }
    MoveItem* itemScope6 = 0;
    MoveItemNode* change = head;
    while (change && !change->FUN_008256d0())
    {
        bool removedItem5 = false;
        itemScope6 = *((::MoveItem **)((void *)(change)));
        if ((filtered8 &&
             reinterpret_cast<::RefList *>((((::MoveFilterResult *)(reinterpret_cast<::BGSCameraPath *>((filter))->GetConditions()))))->FUN_005f65d0({})) ||
            (type > -1 && itemScope6 &&
             reinterpret_cast<MoveForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope6))->GetName())))->FUN_00401170() != type))
        {
            change = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
            continue;
        }
        if (itemScope6)
        {
            MoveFormInfo* infoScope2 = ((::MoveFormInfo *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope6))->GetName()))))));
            if ((!infoScope2 || reinterpret_cast<::FUN_00480d90_shell *>((infoScope2))->FUN_00480d90()) &&
                (reinterpret_cast<::InventoryStackRecord *>((itemScope6))->HasPerkEntry() || !((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) || !reinterpret_cast<::TESContainer *>((((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(itemScope6->form))))
            {
                if (reinterpret_cast<MoveForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope6))->GetName())))->IsQuestItem() && owner == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                {
                    if (itemScope6 && reinterpret_cast<::FUN_004bddd0_shell *>((itemScope6))->FUN_004bddd0(false))
                    {
                        int countScope3 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope6))->FUN_00726070()));
                        bool removedScope6 = false;
                        bool equipped7 = false;
                        equipped7 = reinterpret_cast<::FUN_004bddd0_shell *>((itemScope6))->FUN_004bddd0(true);
                        reinterpret_cast<::XHost17 *>(this)->FUN_004c0cf0(&removedScope6, (unsigned int)(std::uintptr_t)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope6))->GetName()))), countScope3, (::XActor17 *)(owner), (::ExtraDataList *)(::MoveExtra *)(0), equipped7,
                                     itemScope6 != 0, (::InventoryStackRecord *)(::MoveItem *)(0), 0);
                    }
                    change = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
                }
                else if (itemScope6 && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope6))->FUN_00726070())) > 0 &&
                         (!skipQuest3 || !reinterpret_cast<MoveForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope6))->GetName())))->IsQuestItem()))
                {
                    form3 = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((itemScope6))->GetName()));
                    weight7 += static_cast<float>(::FUN_0048e8a0((::TESForm *)(form3)) * ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope6))->FUN_00726070())));
                    bool lastScope2 = false;
                    int baseCountScope4 = 0;
                    if (((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) && itemScope6)
                        baseCountScope4 = reinterpret_cast<::TESContainer *>((((::MoveContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(itemScope6->form));
                    int countScope4 = baseCountScope4 + itemScope6->count;
                    MoveExtraNode* nodeScope2 = ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope6))));
                    if (nodeScope2 && *((::MoveExtra **)((void *)(nodeScope2))))
                    {
                        while (nodeScope2 && *((::MoveExtra **)((void *)(nodeScope2))) && !lastScope2)
                        {
                            MoveExtra* extraScope3 = *((::MoveExtra **)((void *)(nodeScope2)));
                            bool restartScope2 = false;
                            if (reinterpret_cast<::FUN_00418770_shell *>((extraScope3))->FUN_00418770() < 1)
                            {
                                nodeScope2 = ((::MoveExtraNode *)(reinterpret_cast<::Callees *>((nodeScope2))->FUN_00726070()));
                                if (!nodeScope2)
                                {
                                    reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, itemScope6->count, (::Transfer4c37Form4 *)(::MoveExtra *)(0), 0, (::Transfer4c37C37Form *)(destination), 0, 0,
                                                 true, 0, (::Transfer4c37Entry *)(itemScope6));
                                    removedItem5 = true;
                                    if (destination == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                                    {
                                        if (form3 && !silent)
                                        {
                                            MoveString messageScope2;
                                            if (countScope4 > 1)
                                                ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope2), "%i %s%s %s", itemScope6->count,
                                                             ::FUN_00482720((::TESForm *)(form3)), (*reinterpret_cast<::MoveSetting *>(&::g_011d3114)).FUN_00403df0(),
                                                             (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                            else
                                                ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope2), "%s %s", ::FUN_00482720((::TESForm *)(form3)),
                                                             (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                            switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                            {
                                            case 25:
                                            case 30:
                                            case 31:
                                            case 40:
                                            case 41:
                                            case 46:
                                            case 47:
                                            case 50:
                                            case 103:
                                            case 108:
                                            case 115:
                                            case 116:
                                                ::DispatchMessageToSink(
                                                    (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope2))))), 0,
                                                    (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                                    false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))),
                                                    DAT_010162c0, 0);
                                                break;
                                            case 24:
                                                ::DispatchMessageToSink(
                                                    (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope2))))), 0,
                                                    (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                                    false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))),
                                                    DAT_010162c0, 0);
                                                break;
                                            }
                                        }
                                        ::fnv_00704af0::FUN_00704af0();
                                    }
                                    countScope4 = 0;
                                    change = head;
                                    break;
                                }
                            }
                            else if (reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extraScope3))->FUN_0040fe20() < 1)
                            {
                                nodeScope2->FUN_0063f7b0();
                                if (nodeScope2->FUN_008256d0())
                                {
                                    reinterpret_cast<::FileMatchList *>((nodeScope2))->RemoveAll();
                                    delete nodeScope2;
                                    nodeScope2 = 0;
                                    itemScope6->head = 0;
                                }
                                else
                                    nodeScope2 = ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope6))));
                            }
                            else
                            {
                                if (nodeScope2->FUN_005ae380() <= 1)
                                    lastScope2 = true;
                                else
                                    restartScope2 = true;
                                void* ownershipScope3 = 0;
                                if (owner->IsActor())
                                {
                                    void* actorOwnerScope2 = 0;
                                    actorOwnerScope2 = ((void *)(std::uintptr_t)(::FUN_004216f0((::BaseExtraList *)(((::MoveOwnershipProxy *)(reinterpret_cast<::FUN_005d43c0_ *>((owner))->FUN_005d43c0()))))));
                                    if (!actorOwnerScope2)
                                        actorOwnerScope2 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((owner))->FUN_007af430()));
                                    ownershipScope3 = actorOwnerScope2;
                                }
                                else
                                    ownershipScope3 = ((void *)(reinterpret_cast<::OwnerLookupView *>((owner))->FUN_00567790()));
                                if ((retainOwner || SetOwnerPointer) && !::FUN_00481f10((::TESObject *)(form3)))
                                {
                                    if (!((void *)(reinterpret_cast<::FUN_00418660_shell *>((extraScope3))->FUN_00418660())))
                                        reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((extraScope3))->FUN_00419700((::fnv_00419700::TESForm *)(ownershipScope3));
                                }
                                else if (clearOwner)
                                {
                                    int sizeScope2 = reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extraScope3))->FUN_0040fe20();
                                    if (((void *)(reinterpret_cast<::FUN_00418660_shell *>((extraScope3))->FUN_00418660())) &&
                                        ((reinterpret_cast<::FUN_00418770_shell *>((extraScope3))->FUN_00418770() > 1 && sizeScope2 <= 2) || sizeScope2 <= 1))
                                    {
                                        reinterpret_cast<::FUN_0041aed0_shell *>((extraScope3))->FUN_0041aed0();
                                        extraScope3 = 0;
                                    }
                                    else
                                        reinterpret_cast<::FUN_0041aed0_shell *>((extraScope3))->FUN_0041aed0();
                                }
                                if (extraScope3)
                                {
                                    countScope4 -= reinterpret_cast<::FUN_00418770_shell *>((extraScope3))->FUN_00418770();
                                    reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, reinterpret_cast<::FUN_00418770_shell *>((extraScope3))->FUN_00418770(), (::Transfer4c37Form4 *)(extraScope3), 0,
                                                 (::Transfer4c37C37Form *)(destination), 0, 0, true, 0, (::Transfer4c37Entry *)(itemScope6));
                                    removedItem5 = true;
                                    if (destination == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                                    {
                                        if (form3 && !silent)
                                        {
                                            MoveString messageScope3;
                                            if (countScope4 > 1)
                                                ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope3), "%i %s%s %s", reinterpret_cast<::FUN_00418770_shell *>((extraScope3))->FUN_00418770(),
                                                             ::FUN_00482720((::TESForm *)(form3)), (*reinterpret_cast<::MoveSetting *>(&::g_011d3114)).FUN_00403df0(),
                                                             (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                            else
                                                ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope3), "%s %s", ::FUN_00482720((::TESForm *)(form3)),
                                                             (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                            switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                            {
                                            case 25:
                                            case 30:
                                            case 31:
                                            case 40:
                                            case 41:
                                            case 46:
                                            case 47:
                                            case 50:
                                            case 103:
                                            case 108:
                                            case 115:
                                            case 116:
                                                ::DispatchMessageToSink(
                                                    (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope3))))), 0,
                                                    (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                                    false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))),
                                                    DAT_010162c0, 0);
                                                break;
                                            case 24:
                                                ::DispatchMessageToSink(
                                                    (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope3))))), 0,
                                                    (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                                    false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))),
                                                    DAT_010162c0, 0);
                                                break;
                                            }
                                        }
                                        ::fnv_00704af0::FUN_00704af0();
                                    }
                                }
                                itemScope6 = ((::MoveItem *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(form3, 1, 0)));
                                if (countScope4 <= 0 && !itemScope6)
                                    change = head;
                                else if (countScope4 <= 0 && itemScope6)
                                    change = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
                                if (itemScope6 && countScope4 > 0)
                                    nodeScope2 = ((::MoveExtraNode *)(::FUN_00559450((int *)(itemScope6))));
                                else
                                    nodeScope2 = 0;
                            }
                        }
                        if (countScope4 > 0)
                        {
                            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, countScope4, (::Transfer4c37Form4 *)(::MoveExtra *)(0), 0, (::Transfer4c37C37Form *)(destination), 0, 0, true, 0,
                                         (::Transfer4c37Entry *)(::MoveItem *)(removedItem5 ? 0 : itemScope6));
                            change = head;
                            if (destination == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                            {
                                if (form3 && !silent)
                                {
                                    MoveString messageScope4;
                                    if (countScope4 > 1)
                                        ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope4), "%i %s%s %s", countScope4, ::FUN_00482720((::TESForm *)(form3)),
                                                     (*reinterpret_cast<::MoveSetting *>(&::g_011d3114)).FUN_00403df0(), (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                    else
                                        ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope4), "%s %s", ::FUN_00482720((::TESForm *)(form3)),
                                                     (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                    switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                    {
                                    case 25:
                                    case 30:
                                    case 31:
                                    case 40:
                                    case 41:
                                    case 46:
                                    case 47:
                                    case 50:
                                    case 103:
                                    case 108:
                                    case 115:
                                    case 116:
                                        ::DispatchMessageToSink(
                                            (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope4))))), 0,
                                            (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                            false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))), DAT_010162c0,
                                            0);
                                        break;
                                    case 24:
                                        ::DispatchMessageToSink(
                                            (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope4))))), 0,
                                            (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                            false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))), DAT_010162c0,
                                            0);
                                        break;
                                    }
                                }
                                ::fnv_00704af0::FUN_00704af0();
                            }
                        }
                    }
                    else
                    {
                        MoveExtra* extraScope8 = 0;
                        void* ownershipScope5 = 0;
                        if (owner->IsActor())
                        {
                            void* actorOwnerScope3 = 0;
                            actorOwnerScope3 = ((void *)(std::uintptr_t)(::FUN_004216f0((::BaseExtraList *)(((::MoveOwnershipProxy *)(reinterpret_cast<::FUN_005d43c0_ *>((owner))->FUN_005d43c0()))))));
                            if (!actorOwnerScope3)
                                actorOwnerScope3 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((owner))->FUN_007af430()));
                            ownershipScope5 = actorOwnerScope3;
                        }
                        else
                            ownershipScope5 = ((void *)(reinterpret_cast<::OwnerLookupView *>((owner))->FUN_00567790()));
                        if ((retainOwner || SetOwnerPointer) && !::FUN_00481f10((::TESObject *)(form3)))
                        {
                            extraScope8 = new MoveExtra;
                            reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((extraScope8))->FUN_00419700((::fnv_00419700::TESForm *)(ownershipScope5));
                        }
                        int countScope5 = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope6))->FUN_00726070()));
                        reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(owner), (int)(form3), retainOwner, ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemScope6))->FUN_00726070())), (::Transfer4c37Form4 *)(extraScope8), 0, (::Transfer4c37C37Form *)(destination),
                                     0, 0, true, 0, (::Transfer4c37Entry *)(::MoveItem *)(removedItem5 ? 0 : itemScope6));
                        if (destination == (*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))
                        {
                            if (form3 && !silent)
                            {
                                MoveString messageScope5;
                                if (countScope5 > 1)
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope5), "%i %s%s %s", countScope5, ::FUN_00482720((::TESForm *)(form3)),
                                                 (*reinterpret_cast<::MoveSetting *>(&::g_011d3114)).FUN_00403df0(), (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                else
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&messageScope5), "%s %s", ::FUN_00482720((::TESForm *)(form3)), (*reinterpret_cast<::MoveSetting *>(&::g_011d4e7c)).FUN_00403df0());
                                switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                {
                                case 25:
                                case 30:
                                case 31:
                                case 40:
                                case 41:
                                case 46:
                                case 47:
                                case 50:
                                case 103:
                                case 108:
                                case 115:
                                case 116:
                                    ::DispatchMessageToSink(
                                        (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope5))))), 0,
                                        (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                        false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))), DAT_010162c0, 0);
                                    break;
                                case 24:
                                    ::DispatchMessageToSink(
                                        (const char *)(((const char *)(::FUN_00559450((int *)&(messageScope5))))), 0,
                                        (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds"),
                                        false ? 0 : ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form3, true, false))), DAT_010162c0, 0);
                                    break;
                                }
                            }
                            ::fnv_00704af0::FUN_00704af0();
                        }
                        change = head;
                    }
                }
                else
                    change = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
            }
            else
                change = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
        }
        else
            change = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((change))->FUN_00726070()));
    }
    return weight7;
}
// Processes matching extra data, updates equipment state and counts, and may remove or merge extra lists.
// @fnv 0x004c0cf0
bool XHost17::FUN_004c0cf0(bool* a0, std::uintptr_t a1, int iCount, XActor17* apActor, ExtraDataList* apExtraList,
                           bool abWorn, bool a6, InventoryStackRecord* apEntry, bool* abRemoved)
{
    DAT_011c6448 = 0;
    FUN_004bf0e0((InventoryChanges*)this);
    InventoryStackRecord* entry0 = apEntry != 0 ? apEntry : reinterpret_cast<::FUN_004bfba0_shell *>((((XInv17*)this)))->FUN_004bfba0((::TESBoundObject *)(a1), 1, 0);
    if (entry0 == 0)
        return true;
    *a0 = 1;
    XNodeE17* node1 = (XNodeE17*)entry0->m_pExtraDataLists;
    bool result3 = true;
    int count;
    bool armors2 = false;
    bool weapon3 = false;
    while (node1 != 0 && *((::XExtra17 **)((void *)(node1))) != 0)
    {
        XExtra17* extra = *((::XExtra17 **)((void *)(node1)));
        if (reinterpret_cast<::FUN_00418ab0_shell *>((extra))->FUN_00418ab0(abWorn) && (apExtraList == 0 || apExtraList == (ExtraDataList*)extra))
        {
            InventoryStackRecord* found = 0;
            XBiped17* biped = ((::XBiped17 *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(a1))));
            if (reinterpret_cast<::FUN_00418b10_shell *>((extra))->FUN_00418b10() && !apActor->CanRemove(false))
            {
                *a0 = 0;
                return result3;
            }
            if (apActor != 0 && ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture())) != 0)
            {
                bool can = true;
                switch (FUN_00401170(a1))
                {
                case 26: {
                    XDism17* dism = ((::XDism17 *)(reinterpret_cast<::ExtraDataList *>((((::XExtra17 *)(reinterpret_cast<::FUN_005d43c0_ *>((apActor))->FUN_005d43c0()))))->GetDismemberedLimbs()));
                    if (dism != 0 && ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(dism->arr))->GetName())) != 0 && ((::XDism17Part17 *)(reinterpret_cast<::B441420Owner *>((dism))->GetInfoAt(0))) != 0)
                    {
                        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(dism->arr))->GetName())); i++)
                        {
                            XDism17Part17* part = ((::XDism17Part17 *)(reinterpret_cast<::B441420Owner *>((dism))->GetInfoAt(i)));
                            if (part->b0 == 0 && part->b1 != 0)
                                can = false;
                        }
                    }
                    if (can)
                        apActor->process->SetUpdate(1);
                    break;
                }
                case 40: {
                    found = ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->CurrentWeapon();
                    if (found != 0)
                    {
                        if (*((::XExtra17 **)((void *)(((XNodeE17*)found->m_pExtraDataLists)))) == extra || apExtraList == 0)
                        {
                            if (apActor == (XActor17*)(*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer)))
                                ::SetField1F0((::FUN_004c0cd0_This *)(((XNPC17*)(*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer)))), ::FUN_004c0cd0_Arg{nullptr});
                            TESObjectWEAP* weap = (TESObjectWEAP*)a1;
                            if (FUN_004c0bf0(weap))
                                weapon3 = true;
                            if (FUN_008c7aa0())
                            {
                                reinterpret_cast<::H *>((((XTQ17*)((::EquipQueue *)(::TaskQueueInterface::GetSingleton())))))->SendCommand22((std::uintptr_t)(apActor), ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((XFound17*)found)))->GetName())));
                            }
                            else
                            {
                                reinterpret_cast<::BipedAnim *>((((XRefr17*)apActor)))->AttachFaceGenNode();
                                ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->SetWeapon(0, 0, false);
                                ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->SetAmmo(0);
                            }
                        }
                    }
                    break;
                }
                break;
                case 24: {
                    if (reinterpret_cast<::TESBipedModelForm *>(&(((XArmor17*)a1)->biped))->IsPowerArmor() || reinterpret_cast<::TESBipedModelForm *>(&(((XArmor17*)a1)->biped))->GetIsHeavyArmor())
                        armors2 = true;
                    XDism17* dism2 = ((::XDism17 *)(reinterpret_cast<::ExtraDataList *>((((::XExtra17 *)(reinterpret_cast<::FUN_005d43c0_ *>((apActor))->FUN_005d43c0()))))->GetDismemberedLimbs()));
                    if (dism2 != 0 && ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(dism2->arr))->GetName())) != 0 && ((::XDism17Part17 *)(reinterpret_cast<::B441420Owner *>((dism2))->GetInfoAt(0))) != 0)
                    {
                        for (unsigned int i2 = 0; i2 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(dism2->arr))->GetName())); i2++)
                        {
                            XDism17Part17* part2 = ((::XDism17Part17 *)(reinterpret_cast<::B441420Owner *>((dism2))->GetInfoAt(i2)));
                            if (part2->b0 == 0 && part2->b1 != 0)
                                can = false;
                        }
                    }
                    if (can)
                        apActor->process->SetUpdate(1);
                    break;
                }
                case 41: {
                    found = ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->CurrentAmmo();
                    if (found != 0)
                    {
                        if (*((::XExtra17 **)((void *)(((XNodeE17*)found->m_pExtraDataLists)))) == extra)
                        {
                            reinterpret_cast<::TESForm *>((((XForm17*)apActor)))->ClearData();
                            ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->SetAmmo(0);
                        }
                    }
                    break;
                }
                }
            }
            reinterpret_cast<::FUN_0041aa20_shell *>((extra))->SetWornState(false, abWorn);
            if ((unsigned int)((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((extra))->FUN_0040fe20())) <= 1)
            {
                if ((char)((char)(reinterpret_cast<::FUN_0042de90_cls *>((extra))->GetExtraByteValue())) >= 0)
                {
                    reinterpret_cast<::FUN_00419ad0_shell *>((extra))->FUN_00419ad0(
                        (short)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((XChange17*)entry0)))->FUN_00726070())) - reinterpret_cast<::FUN_004bc8f0_stand *>((((XChange17*)entry0)))->FUN_004bc8f0(false)));
                }
                else
                {
                    reinterpret_cast<::FUN_00419ad0_shell *>((extra))->FUN_00419ad0((short)0);
                }
            }
            if (reinterpret_cast<::ExtraDataList *>((extra))->IsEmpty())
            {
                reinterpret_cast<::ItemChangeListNode *>((((XNodeE17*)entry0->m_pExtraDataLists)))->FUN_00905330((*(::InventoryStackRecord *const *)(&extra)));
                delete extra;
                if ((ExtraDataList*)extra == apExtraList && abRemoved != 0)
                    *abRemoved = true;
                extra = 0;
                result3 = false;
                break;
            }
            else
            {
                XNodeE17* node2 = (XNodeE17*)entry0->m_pExtraDataLists;
                while (node2 != 0 && *((::XExtra17 **)((void *)(node2))) != 0 && result3)
                {
                    XExtra17* extra1 = *((::XExtra17 **)((void *)(node2)));
                    XExtra17* savedState3 = extra;
                    bool different2 = true;
                    if (savedState3 != 0)
                    {
                        different2 = reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((savedState3))->FUN_004126c0((::ExtraDataList *)(extra1), 0, weapon3) ||
                                     reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((extra1))->FUN_004126c0((::ExtraDataList *)(savedState3), 0, weapon3);
                    }
                    if (different2 || extra == extra1)
                    {
                        node2 = ((::XNodeE17 *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
                    }
                    else
                    {
                        reinterpret_cast<::FUN_00419ad0_shell *>((extra1))->FUN_00419ad0((short)(reinterpret_cast<::FUN_00418770_shell *>((extra1))->FUN_00418770() + iCount));
                        DAT_011c6448 = extra1;
                        if (extra != 0 && (char)((char)(reinterpret_cast<::FUN_0042de90_cls *>((extra))->GetExtraByteValue())) >= 0)
                        {
                            reinterpret_cast<::FUN_0042dde0_cls *>((extra1))->SetHotKey((unsigned char)((char)(reinterpret_cast<::FUN_0042de90_cls *>((extra))->GetExtraByteValue())));
                        }
                        if (reinterpret_cast<::ExtraDataList *>((extra1))->IsEmpty())
                        {
                            reinterpret_cast<::ItemChangeListNode *>((((XNodeE17*)entry0->m_pExtraDataLists)))->FUN_00905330((*(::InventoryStackRecord *const *)(&extra1)));
                            delete extra1;
                        }
                        else
                        {
                            reinterpret_cast<::ItemChangeListNode *>((((XNodeE17*)entry0->m_pExtraDataLists)))->FUN_00905330((*(::InventoryStackRecord *const *)(&extra)));
                        }
                        delete extra;
                        extra = 0;
                        result3 = false;
                    }
                }
            }
            node1 = 0;
        }
        else
            node1 = ((::XNodeE17 *)(reinterpret_cast<::Callees *>((node1))->FUN_00726070()));
    }
    if (armors2)
    {
        if (apActor != 0)
        {
            if (((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture())) != 0)
            {
                ((::XProcess17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->UpdateArmor(apActor);
            }
        }
    }
    if (((XInv17*)this)->pRef != 0)
        ((XInv17*)this)->pRef->MarkAsModified(0x20);
    count = reinterpret_cast<::FUN_004bffb0_shell *>((((XInv17*)this)))->FUN_004bffb0()->GetObjectCount((TESObject*)a1);
    if (entry0 != 0 && entry0->m_pExtraDataLists != 0 && ((XNodeE17*)entry0->m_pExtraDataLists)->_ref_008256d0() &&
        (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((XChange17*)entry0)))->FUN_00726070())) == 0 || count == ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((XChange17*)entry0)))->FUN_00726070()))))
    {
        reinterpret_cast<::ItemChangeListNode *>((((XNodeC17*)((InventoryChanges*)this)->m_pEntryList)))->FUN_00905330((*(::InventoryStackRecord *const *)(&entry0)));
        delete (XChange17*)entry0;
        return false;
    }
    else if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((XChange17*)entry0)))->FUN_00726070())) < 0 && ((void *)(::FUN_00559450((int *)(((XChange17*)entry0))))) != 0)
    {
        reinterpret_cast<::FileMatchList *>((((XListObj17*)((void *)(::FUN_00559450((int *)(((XChange17*)entry0))))))))->RemoveAll();
    }
    if (apActor != 0)
        reinterpret_cast<::FUN_008b0bd0_shell *>((((XRefr17*)apActor)))->FUN_008b0bd0((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((XRefr17*)apActor)))->FUN_0043fcd0()))));
    return result3;
}
struct FUN_00559450_shell
{
};
struct FUN_004c8c10_shell
{
};
struct G2
{
    void AddHead(ExtraDataList*&);
};


struct FUN_004c8220_shell : public InventoryChanges
{
    InventoryStackRecord* FUN_004c8220(TESActorBase*, int, bool);
};

// Finds the armor piece with the highest effective rating for a body slot, considering extra health and inventory changes.
// @fnv 0x004c8220
InventoryStackRecord* FUN_004c8220_shell::FUN_004c8220(TESActorBase* apActorBase, int aeBodySlot, bool abUseCanNotWear)
{
    float fHighDesire;
    TESObjectARMO* volatile pBest;
    AutoMemContext tempMemContext((MEM_CONTEXT)54, true, ::DAT_01020778, 5694);
    InventoryStackRecord* pchange;
    SimpleListNode* pListInv;
    SimpleListNode* pList;

    fHighDesire = DAT_01015f5c;
    pBest = 0;
    pchange = 0;
    if (abUseCanNotWear)
    {
        InventoryStackRecord* pitem = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((((FUN_004c8c10_shell*)this)))->FUN_004c8c10(aeBodySlot, false)));
        if (pitem &&
            ((FUN_00418b10_shell*)((void *)((void *)(((::SimpleListNode *)(::FUN_00559450((int *)(((FUN_00559450_shell*)pitem)))))))))->FUN_00418b10())
            return pitem;
        else
            delete pitem;
    }

    pList = ((ArmorContainerList004c8220*)((FUN_004bffb0_shell*)this)->FUN_004bffb0())->FUN_00717e50();
    while (pList && !pList->FUN_008256d0())
    {
        TESObjectARMO* pObj = dynamic_cast<TESObjectARMO*>(((InventoryItemEntry*)((void *)((void *)(pList))))->pObj);
        InventoryStackRecord* pitem = ((FUN_004bfba0_shell*)this)->FUN_004bfba0(pObj, true, false);
        if ((!pitem ||
             (pitem && pitem->m_iCountChange + ((InventoryItemEntry*)((void *)((void *)(pList))))->m_iCountDelta > 0) ||
             ((InventoryItemEntry*)((void *)((void *)(pList))))->m_iCountDelta < 0) &&
            pObj && aeBodySlot != -1 && reinterpret_cast<::TESBipedModelForm *>((((FUN_00480af0_shell*)((char*)pObj + 0x70))))->HasBipedModel((::BIPED_OBJECT)(aeBodySlot), false, (::BGSBipedModelList *)(void *)(0)))
        {
            float fDesire = -1.0f;
            if (pitem && pitem->m_pExtraDataLists && ((void *)((void *)(((SimpleListNode*)pitem->m_pExtraDataLists)))))
            {
                SimpleListNode* pextralist = (SimpleListNode*)pitem->m_pExtraDataLists;
                while (pextralist && ((void *)((void *)(pextralist))))
                {
                    ExtraDataList* pcurextra = (ExtraDataList*)((void *)((void *)(pextralist)));
                    ExtraHealth* pHealth = (ExtraHealth*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((pcurextra))->FUN_00410220(0x25);
                    float fhealth = 0.0f;
                    if (pHealth)
                        fhealth = ((FUN_004186f0_shell*)pcurextra)->FUN_004186f0();
                    else
                        fhealth = ::TESHealthForm::GetBaseHealth((::TESForm *)(pObj));
                    if (fhealth > 0.0)
                    {
                        float frating = ::CombatDamageCalculator::CalculateArmorDamageThreshold(((float)(::FUN_004be060((void *)(pObj)))), fhealth);
                        fDesire = ::FUN_004be180((char *)(pObj)) + frating;
                        if (fDesire > fHighDesire)
                        {
                            fHighDesire = fDesire;
                            pBest = pObj;
                            delete pchange;
                            pchange = new InventoryStackRecord;
                            pchange->m_pItemObject = pObj;
                            pchange->m_pExtraDataLists = (BSSimpleList<ExtraDataList*>*)new SL;
                            ((G2*)pchange->m_pExtraDataLists)->AddHead(pcurextra);
                        }
                    }
                    pextralist = ((::SimpleListNode *)(reinterpret_cast<::Callees *>((pextralist))->FUN_00726070()));
                }
            }
            else
            {
                float fhealth = ::TESHealthForm::GetBaseHealth((::TESForm *)(pObj));
                float frating = ::CombatDamageCalculator::CalculateArmorDamageThreshold(((float)(::FUN_004be060((void *)(pObj)))), fhealth);
                fDesire = ::FUN_004be180((char *)(pObj)) + frating;
                if (fDesire > fHighDesire)
                {
                    fHighDesire = fDesire;
                    pBest = pObj;
                    delete pchange;
                    pchange = new InventoryStackRecord;
                    pchange->m_pItemObject = pObj;
                }
            }
        }
        pList = ((::SimpleListNode *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }

    pListInv = (SimpleListNode*)((InventoryChanges*)this)->m_pEntryList;
    while (pListInv && !pListInv->FUN_008256d0())
    {
        TESObjectARMO* pObj = dynamic_cast<TESObjectARMO*>(((InventoryStackRecord*)((void *)((void *)(pListInv))))->m_pItemObject);
        InventoryStackRecord* pitem = (InventoryStackRecord*)((void *)((void *)(pListInv)));
        if (pObj && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)pitem)))->FUN_00726070())) &&
            !((FUN_004bffb0_shell*)this)->FUN_004bffb0()->HasObjectOfType((TESObject*)pObj) && aeBodySlot != -1 &&
            reinterpret_cast<::TESBipedModelForm *>((((FUN_00480af0_shell*)((char*)pObj + 0x70))))->HasBipedModel((::BIPED_OBJECT)(aeBodySlot), false, (::BGSBipedModelList *)(void *)(0)) &&
            pitem->m_iCountChange >= 0)
        {
            float fDesire = -1.0f;
            if (pitem && pitem->m_pExtraDataLists && ((void *)((void *)(((SimpleListNode*)pitem->m_pExtraDataLists)))))
            {
                SimpleListNode* pextralist = (SimpleListNode*)pitem->m_pExtraDataLists;
                while (pextralist && ((void *)((void *)(pextralist))))
                {
                    ExtraDataList* pcurextra = (ExtraDataList*)((void *)((void *)(pextralist)));
                    ExtraHealth* pHealth = (ExtraHealth*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((pcurextra))->FUN_00410220(0x25);
                    float fhealth = 0.0f;
                    if (pHealth)
                        fhealth = ((FUN_004186f0_shell*)pcurextra)->FUN_004186f0();
                    else
                        fhealth = ::TESHealthForm::GetBaseHealth((::TESForm *)(pObj));
                    if (fhealth > 0.0)
                    {
                        float frating = ::CombatDamageCalculator::CalculateArmorDamageThreshold(((float)(::FUN_004be060((void *)(pObj)))), fhealth);
                        fDesire = ::FUN_004be180((char *)(pObj)) + frating;
                        if (fDesire > fHighDesire)
                        {
                            fHighDesire = fDesire;
                            pBest = pObj;
                            delete pchange;
                            pchange = new InventoryStackRecord;
                            pchange->m_pItemObject = pObj;
                            pchange->m_pExtraDataLists = (BSSimpleList<ExtraDataList*>*)new SL;
                            ((G2*)pchange->m_pExtraDataLists)->AddHead(pcurextra);
                        }
                    }
                    pextralist = ((::SimpleListNode *)(reinterpret_cast<::Callees *>((pextralist))->FUN_00726070()));
                }
            }
            else
            {
                float fhealth = ::TESHealthForm::GetBaseHealth((::TESForm *)(pObj));
                float frating = ::CombatDamageCalculator::CalculateArmorDamageThreshold(((float)(::FUN_004be060((void *)(pObj)))), fhealth);
                fDesire = ::FUN_004be180((char *)(pObj)) + frating;
                if (fDesire > fHighDesire)
                {
                    fHighDesire = fDesire;
                    pBest = pObj;
                    delete pchange;
                    pchange = new InventoryStackRecord;
                    pchange->m_pItemObject = pObj;
                }
            }
        }
        pListInv = ((::SimpleListNode *)(reinterpret_cast<::Callees *>((pListInv))->FUN_00726070()));
    }
    return pchange;
}

class ScriptLocals;

class Script
{
  public:
    static bool HandleScriptLocals(TESObjectREFR*, void*, void*, double&);
};

int FNV_GetFormType(TESForm*);



struct W20Ref;

struct BSString
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;

    BSString();
    ~BSString();
    operator const char*() const;
};

template <class T> struct SimpleList
{
    T m_item;
    SimpleList<T>* m_pkNext;

    SimpleList();
    ~SimpleList();
    T& GetItem();
    SimpleList<T>* GetNext();
    bool IsEmpty();
    void AddHead(const T& item);
    void RemoveHead();
};

struct ListForm_5b4e90
{
};

struct EquippedActor_5b4e90 : public ::Actor
{
};

struct Target_5b4e90 : public ::MagicTarget
{
};

struct Player_5b4e90
{
};

struct InventoryLeveled_5b4e90 : public ::InventoryChanges
{
};

struct InventoryExtra_5b4e90 : public ::InventoryChanges
{
};

struct ExtraFlag_5b4e90 : public ::ExtraDataList
{
};

// Processes pRemoveForm or eligible list entries, removing up to iCount per item and handling equipment and player messages.
// @fnv 0x005b4e90
bool FUN_005b4e90(ScriptParameter* paramInfo, char* scriptData, TESObjectREFR* thisObj, TESObjectREFR* containingObj,
                  Script* scriptObj, ScriptLocals* eventList, double* result, unsigned int* opcodeOffsetPtr)
{
    TESForm* pRemoveForm = 0;
    TESBoundObject* pObject = 0;
    int iCount = 0;
    int iNoMessage = 0;

    if (!::FUN_005accb0((const ::ExtractParameter *)(paramInfo), scriptData, opcodeOffsetPtr, thisObj, containingObj, (::ExtractScript *)(scriptObj), eventList, &pRemoveForm,
                     &iCount, &iNoMessage))
        return false;

    if (thisObj && pRemoveForm)
    {
        SimpleList<TESForm*> itemList;
        if (pRemoveForm->IsActor_InEditor())
            pObject = (TESBoundObject*)pRemoveForm;
        if (::FNV_GetFormType(pRemoveForm) == 0x34)
        {
            TESLevItem* pLevItem = (TESLevItem*)pRemoveForm;
            if (pLevItem)
            {
                InventoryChanges* pInventoryChanges = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((thisObj))->FUN_005d43c0()))->GetContainerChangeData();
                if (pInventoryChanges)
                    pObject = ((::TESBoundObject *)(reinterpret_cast<::fnv_004cba70::Changes *>((static_cast<InventoryLeveled_5b4e90*>(pInventoryChanges)))->FUN_004cba70(pLevItem)));
            }
        }
        if (pObject)
        {
            itemList.AddHead((TESForm*)pObject);
        }
        else if (::FNV_GetFormType(pRemoveForm) == 0x55)
        {
            ListForm_5b4e90* pListForm = (ListForm_5b4e90*)pRemoveForm;
            SimpleList<TESForm*>* pNode = ((::SimpleList< ::TESForm *> *)(reinterpret_cast<::BGSCameraPath *>((pListForm))->GetConditions()));
            while (pNode && !pNode->IsEmpty())
            {
                TESForm* pListItem = ((::TESForm *)((void *)(pNode)));
                pNode = ((::SimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                if (pListItem->IsActor_InEditor())
                    itemList.AddHead(pListItem);
            }
        }

        while (!itemList.IsEmpty())
        {
            pObject = (TESBoundObject*)itemList.m_item;
            itemList.RemoveHead();
            int iRemove = iCount;
            ::Actor* pActor = dynamic_cast< ::Actor*>(thisObj);
            if (pActor)
            {
                {
                    double dCount = iRemove;
                    Script::HandleScriptLocals(thisObj, pObject, 0, dCount);
                    if (iRemove > dCount)
                        iRemove = (int)dCount;
                }
                ExtraDataList* pExtra = 0;
                if (reinterpret_cast<::Thing575 *>((static_cast<EquippedActor_5b4e90*>(pActor)))->FUN_00575400((std::intptr_t)(pObject)))
                {
                    InventoryChanges* m_pInventoryChangesValue = InventoryChanges::CreateForReference(thisObj);
                    if (m_pInventoryChangesValue)
                    {
                        pExtra =
                            reinterpret_cast<::fnv_004bfda0::FUN_004bfda0_shell *>((static_cast<InventoryExtra_5b4e90*>(m_pInventoryChangesValue)))->FUN_004bfda0((::fnv_004bfda0::TESBoundObject *)(pObject), 0);
                        if (pExtra)
                            reinterpret_cast<::FUN_0041ab70_shell *>((static_cast<ExtraFlag_5b4e90*>(pExtra)))->FUN_0041ab70(false);
                    }
                }
                if (iRemove > 0)
                {
                    bool bEquipped = reinterpret_cast<::Thing575 *>((static_cast<EquippedActor_5b4e90*>(pActor)))->FUN_00575400((std::intptr_t)(pObject));
                    if (bEquipped)
                        reinterpret_cast<::FUN_008248e0_shell *>((reinterpret_cast<Target_5b4e90*>(static_cast<MagicTarget *>(pActor))))->FUN_008248e0((::MagicItem *)(pObject), true);
                    pActor->RemoveItem((TESForm*)pObject, pExtra, iRemove, 0, 0, 0, 0, 0, 1, 0);
                    if (pActor == reinterpret_cast< ::Actor*>((*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer))))
                    {
                        if (!iNoMessage)
                        {
                            BSString sMessage;
                            if (iRemove > 1)
                                ::FUN_00406f60((::FUN_00406f90_this *)&(sMessage), "%i %s%s %s", iRemove, ::FUN_00482720((TESForm*)pObject),
                                                 (*reinterpret_cast<::StartMenu *>(&::g_011d3114)).GetMenuTitle(), (*reinterpret_cast<::StartMenu *>(&::g_011d3db4)).GetMenuTitle());
                            else
                                ::FUN_00406f60((::FUN_00406f90_this *)&(sMessage), DAT_01012058, ::FUN_00482720((TESForm*)pObject),
                                                 (*reinterpret_cast<::StartMenu *>(&::g_011d3db4)).GetMenuTitle());
                            switch (::FNV_GetFormType((TESForm*)pObject))
                            {
                            case 0x19:
                            case 0x1e:
                            case 0x1f:
                            case 0x28:
                            case 0x29:
                            case 0x2e:
                            case 0x2f:
                            case 0x32:
                            case 0x67:
                            case 0x6c:
                            case 0x73:
                            case 0x74:
                                ::DispatchMessageToSink(
                                    (const char *)(sMessage), 0, (const char *)(g_011cba4c_arg1),
                                    (const char *)(iNoMessage
                                        ? 0
                                        : reinterpret_cast<::PickupSoundActorView *>((reinterpret_cast<Player_5b4e90*>((*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer)))))->FUN_008adcf0(pObject, 0, 0)),
                                    2.0f, false);
                                break;
                            case 0x18:
                                ::DispatchMessageToSink(
                                    (const char *)(sMessage), 0, (const char *)(g_011cba4c_arg1),
                                    (const char *)(iNoMessage
                                        ? 0
                                        : reinterpret_cast<::PickupSoundActorView *>((reinterpret_cast<Player_5b4e90*>((*reinterpret_cast<::W20Ref * *>(&::_g_thePlayer)))))->FUN_008adcf0(pObject, 0, 0)),
                                    2.0f, false);
                                break;
                            }
                        }
                        ::fnv_00704af0::FUN_00704af0();
                    }
                    else if (bEquipped && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture())) && pActor->GetNiNode())
                    {
                        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()))->SelectPackage(pActor, false);
                    }
                }
            }
            else
            {
                thisObj->RemoveItem((TESForm*)pObject, 0, iRemove, 0, 0, 0, 0, 0, 1, 0);
            }
        }
    }
    return true;
}

namespace fnv_004be6f0 {
struct SaveRecord
{
    unsigned int formID;
    char kind;
    char flags;
};
struct SaveStream
{
};
struct DebugSetting
{
    bool* Bool();
};
struct SavedItem
{
    void Save(int, int);
};
struct SavedNode
{
    bool Empty();
    SavedItem** Item();
};
struct SavedOwner
{
};
struct SavedForm
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* Name();
};
struct SaveInventory
{
    SavedNode* changes;
    unsigned int owner;
    SavedOwner* container;
    void FUN_004be6f0();
};
// Writes the inventory owner, container, and item changes to the save stream, patching the block size and count fields.
// @fnv 0x004be6f0
void SaveInventory::FUN_004be6f0()
{
    unsigned short blockSize_ = 0;
    unsigned int blockStart6 = 0;
    unsigned int start2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    if (*(*reinterpret_cast<::fnv_004be6f0::DebugSetting *>(&::g_011de4e8)).Bool())
        start2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int tag5 = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&tag5, 4);
        blockStart6 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&blockSize_, 2);
    }
    unsigned int ownerID5 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((container))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&ownerID5), 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&owner, 4);
    unsigned int count4 = 0;
    unsigned int* countPos_ = (unsigned int*)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&count4, 4);
    SavedNode* nodeB = changes;
    while (nodeB && !nodeB->Empty())
    {
        SavedItem* itemB = *((::fnv_004be6f0::SavedItem **)((void *)(nodeB)));
        reinterpret_cast<::extra_save::SaveShell *>((itemB))->FUN_004235e0(0, (::extra_save::SForm *)(0));
        count4++;
        nodeB = ((::fnv_004be6f0::SavedNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
    }
    *countPos_ = count4;
    if (*(*reinterpret_cast<::fnv_004be6f0::DebugSetting *>(&::g_011de4e8)).Bool())
    {
        unsigned int end_2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        SaveRecord* record_ = ((::fnv_004be6f0::SaveRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (record_)
        {
            SavedForm* kForm = ((::fnv_004be6f0::SavedForm *)(::FUN_004839c0(record_->formID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int endBlock5 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004be6f0::SaveStream * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        unsigned int beginBlock6 = blockStart6;
        if (endBlock5 > beginBlock6 + 0xffff)
            ::FUN_005b5e40();
        *(unsigned short*)blockStart6 = (unsigned short)(endBlock5 - beginBlock6);
    }
}
}  // namespace fnv_004be6f0

struct ExtraSetter_bdb40
{
};
struct ExtraList_bdb40
{
    FUN_00410360* item;
    ExtraList_bdb40* next;
    ExtraList_bdb40();
    void FUN_00905330(FUN_00410360**);
};
struct InvEntry_bdb40
{
    ExtraList_bdb40* list;
    void FUN_004bdb40();
};
// Ensures the InvEntry has an ExtraList, then sets flag 1 on its first extra item, creating one if the list is empty.
// @fnv 0x004bdb40
void InvEntry_bdb40::FUN_004bdb40()
{
    ExtraList_bdb40* pExtraList = list;
    if (!pExtraList)
    {
        pExtraList = new ExtraList_bdb40;
        list = pExtraList;
    }
    if (!*((::FUN_00410360 **)((void *)(pExtraList))))
    {
        FUN_00410360* extra = new FUN_00410360;
        reinterpret_cast<::FUN_0042e5a0_class *>((reinterpret_cast<ExtraSetter_bdb40*>(extra)))->FUN_0042e5a0(1);
        list->FUN_00905330(&extra);
    }
    else if (pExtraList && *((::FUN_00410360 **)((void *)(pExtraList))))
    {
        FUN_00410360* result = *((::FUN_00410360 **)((void *)(pExtraList)));
        if (result)
            reinterpret_cast<::FUN_0042e5a0_class *>((reinterpret_cast<ExtraSetter_bdb40*>(result)))->FUN_0042e5a0(1);
    }
}

struct ItemChangeValueShell : public InventoryStackRecord
{
    float FUN_004bd400();
};

struct ItemHealthCall
{
};
float __cdecl ComputeItemValue(float, float);

// Combines FUN_0048e8a0's result with condition percent, adds values for selected weapon slots, then rounds to 0.1.
// @fnv 0x004bd400
float ItemChangeValueShell::FUN_004bd400()
{
    TESObjectWEAP* pWeap;
    float fConditionValue;
    fConditionValue =
        ComputeItemValue((float)::FUN_0048e8a0((::TESForm *)(m_pItemObject)), reinterpret_cast<::FUN_004bcdb0_shell *>((((ItemHealthCall*)this)))->FUN_004bcdb0(true));
    pWeap = dynamic_cast<TESObjectWEAP*>((TESBoundObject*)((reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())));
    if (pWeap)
    {
        int iSlotFlags = ((FUN_004bd820_stand*)this)->FUN_004bd820();
        if (iSlotFlags)
        {
            if (iSlotFlags & 1)
                fConditionValue +=
                    ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)(((FUN_004bd570_this*)pWeap)->FUN_004bd570(1) + 0x7c))))->FUN_00726070()));
            if (iSlotFlags & 2)
                fConditionValue +=
                    ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)(((FUN_004bd570_this*)pWeap)->FUN_004bd570(2) + 0x7c))))->FUN_00726070()));
            if (iSlotFlags & 4)
                fConditionValue +=
                    ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)(((FUN_004bd570_this*)pWeap)->FUN_004bd570(4) + 0x7c))))->FUN_00726070()));
        }
    }
    return InventoryStackRecord::RoundToNearestStep(fConditionValue, 0.1f);
}

struct RefIdShell
{
    unsigned int GetFormID();
};
class TESObjectREFR;
struct FUN_0041c8d0_shell
{
public:
    ::TESObjectREFR *FUN_0041c8d0();
};
// @fnv 0x004cfe20
bool FUN_004cfe20_t::HasItem(std::uintptr_t aId)
{
    ::TESBoundObject* pObj;
    ::InventoryStackRecord* pitem = 0;
    pObj = 0;
    int iProcessIndex = 0;
    ContNode4cfe20* pList = ((::Container4cfe20 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    while (pList && !pList->_ref_008256d0())
    {
        pObj = (*((::ContEntry4cfe20 **)((void *)(pList))))->pObj;
        if (pObj && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESForm*)pObj)))->FUN_0084e3a0())) == aId)
        {
            ::InventoryStackRecord* pchange = reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(pObj, 1, 0);
            if ((*((::ContEntry4cfe20 **)((void *)(pList))))->count < 0)
            {
                return true;
            }
            else
            {
                if (pchange && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ChangeCount4cfe20*)pchange)))->FUN_00726070())) + (*((::ContEntry4cfe20 **)((void *)(pList))))->count)
                    iProcessIndex += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((ChangeCount4cfe20*)pchange)))->FUN_00726070())) + (*((::ContEntry4cfe20 **)((void *)(pList))))->count;
                else
                    iProcessIndex += (*((::ContEntry4cfe20 **)((void *)(pList))))->count;
            }
            if (iProcessIndex > 0)
                return true;
        }
        pList = ((::ContNode4cfe20 *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }
    ChangeNode4cfe20* pListInv = (ChangeNode4cfe20*)m_pEntryList;
    while (pListInv && !pListInv->_ref_008256d0())
    {
        pitem = *((::InventoryStackRecord **)((void *)(pListInv)));
        ExtraNode4cfe20* pkCurrentObject = *(ExtraNode4cfe20**)pitem;
        while (pkCurrentObject && *((::ExtraDataList **)((void *)(pkCurrentObject))))
        {
            ::ExtraDataList* pextra = *((::ExtraDataList **)((void *)(pkCurrentObject)));
            if (pextra && reinterpret_cast<::FUN_0041c8d0_shell *>((((ExtraRef4cfe20*)pextra)))->FUN_0041c8d0() &&
                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<::FUN_0041c8d0_shell *>((((ExtraRef4cfe20*)pextra)))->FUN_0041c8d0()))->FUN_0084e3a0())) == aId)
                return true;
            pkCurrentObject = ((::ExtraNode4cfe20 *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
        }
        pListInv = ((::ChangeNode4cfe20 *)(reinterpret_cast<::Callees *>((pListInv))->FUN_00726070()));
    }
    return false;
}
// Adds count of form with extra to the inventory, merging extras, updating equipped weapon ammo counts, and recursively adding loaded ammo.
// @fnv 0x004c29a0
void AddInventory::FUN_004c29a0(AddForm* form, AddExtra* extra, int count)
{
    AutoMemContext context4((MEM_CONTEXT)0x36, true, ::DAT_01020778, 0xd28);
    dirty = true;
    previousWeight = weight;
    weight = ::DAT_01012054;
    int loadedAmmoTmp = 0;
    if (!extra)
        extra = new AddExtra;
    if (extra)
    {
        AddAmmoExtra* ammoExtra = ((::AddAmmoExtra *)(reinterpret_cast<::FUN_0042eb40_shell *>((extra))->GetExtraAmmo()));
        if (ammoExtra)
            loadedAmmoTmp = ammoExtra->count;
    }
    loadedAmmoTmp *= count;
    if (!count)
        count = 1;
    AddEntry* entry2 = ((::AddEntry *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(form), 1, 0)));
    bool result5 = true;
    bool equipped = false;
    if (extra && ((::AddRef *)(reinterpret_cast<::FUN_00418660_shell *>((extra))->FUN_00418660())) == (*reinterpret_cast<::AddRef * *>(&::_g_thePlayer)) && owner == (*reinterpret_cast<::AddRef * *>(&::_g_thePlayer)))
        reinterpret_cast<::FUN_0041aed0_shell *>((extra))->FUN_0041aed0();
    AddRef* actor11 = 0;
    if (owner && owner->isActor())
        actor11 = owner;
    if (form->FUN_00401170() == 0x28 && actor11 && ((::AddProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor11))->GetBaseTexture())))
    {
        AddForm* weapon = form;
        AddProcess* process = ((::AddProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor11))->GetBaseTexture()));
        if (::FUN_004c0bf0((::TESObjectWEAP *)(weapon)) && process->p() && weapon == ((::AddForm *)(reinterpret_cast<::Twin_0044ddc0 *>((process->p()))->GetName())))
        {
            equipped = true;
            if (process->ammoA())
                reinterpret_cast<::CombatProcedure *>((process->ammoA()))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((process->ammoA()))->FUN_00726070())) + count));
            if (process->p())
                reinterpret_cast<::CombatProcedure *>((process->p()))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((process->p()))->FUN_00726070())) + count));
            if (!entry2 || !reinterpret_cast<::FUN_004bddd0_shell *>((entry2))->FUN_004bddd0(false))
            {
                if (!extra)
                    extra = new AddExtra;
                reinterpret_cast<::FUN_0041aa20_shell *>((extra))->SetWornState(true, false);
            }
        }
    }
    if (extra && ((::AddRef *)(reinterpret_cast<::FUN_0041c8d0_shell *>((extra))->FUN_0041c8d0())))
    {
        AddRef* reference = ((::AddRef *)(reinterpret_cast<::FUN_0041c8d0_shell *>((extra))->FUN_0041c8d0()));
        if (reference)
            reinterpret_cast<::fnv_0041c7f0::FUN_0041c7f0_cls *>((((::AddExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041c7f0((::TESObjectREFR *)(owner));
    }
    if (!entry2)
    {
        if (extra && reinterpret_cast<::ExtraDataList *>((extra))->IsEmpty())
        {
            delete extra;
            extra = 0;
        }
        entry2 = new AddEntry(form, count);
        if (!entry2->extras)
            entry2->extras = new AddNode;
        entry2->extras->_ref_005ae3d0(extra);
        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>(this)->FUN_004c3380((::InventoryStackRecord *)(entry2), true);
    }
    else
    {
        if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry2))->FUN_00726070())) <= 0 && extra && !((::AddRef *)(reinterpret_cast<::FUN_00418660_shell *>((extra))->FUN_00418660())) && !((void *)(reinterpret_cast<::FUN_00418800_shell *>((extra))->FUN_00418800())) &&
            entry2->extras && entry2->extras->_ref_005ae380() && reinterpret_cast<::ExtraDataList *>((((::AddExtra *)((void *)(entry2->extras)))))->HasExtraDataType0x2F())
        {
            reinterpret_cast<::FUN_00419ad0_shell *>((((::AddExtra *)((void *)(entry2->extras)))))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((((::AddExtra *)((void *)(entry2->extras)))))->FUN_00418770() + count);
            delete extra;
            extra = 0;
        }
        if (extra && entry2->extras)
        {
            AddNode* node7 = entry2->extras;
            bool searching8 = true;
            while (node7 && ((::AddExtra *)((void *)(node7))) && searching8)
            {
                AddExtra* existing7 = ((::AddExtra *)((void *)(node7)));
                AddExtra* incomingVal = extra;
                bool different2 = true;
                if (incomingVal)
                    different2 = reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((incomingVal))->FUN_004126c0((::ExtraDataList *)(existing7), false, equipped) ||
                                 reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((existing7))->FUN_004126c0((::ExtraDataList *)(incomingVal), false, equipped);
                if (different2)
                    node7 = ((::AddNode *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
                else
                {
                    reinterpret_cast<::FUN_00419ad0_shell *>((existing7))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((existing7))->FUN_00418770() + count);
                    if (reinterpret_cast<::ExtraDataList *>((existing7))->IsEmpty())
                    {
                        reinterpret_cast<::ItemChangeListNode *>((entry2->extras))->FUN_00905330((::InventoryStackRecord *const &)(existing7));
                        delete existing7;
                    }
                    searching8 = false;
                }
            }
            if (searching8)
            {
                if (extra && reinterpret_cast<::ExtraDataList *>((extra))->IsEmpty())
                {
                    delete extra;
                    extra = 0;
                }
                else
                {
                    if (!entry2->extras)
                        entry2->extras = new AddNode;
                    entry2->extras->_ref_005ae3d0(extra);
                }
            }
            else if (!::Interface::ContainerIsBarter() && !::Interface::ContainerIsRecipe())
            {
                delete extra;
                extra = 0;
            }
        }
        else if (extra && !reinterpret_cast<::ExtraDataList *>((extra))->IsEmpty())
        {
            if (!entry2->extras)
                entry2->extras = new AddNode;
            entry2->extras->_ref_005ae3d0(extra);
        }
        AddContainer* base = ((::AddContainer *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()));
        int baseCount = base ? reinterpret_cast<::TESContainer *>((base))->GetObjectCount((::TESObject *)(form)) : 0;
        if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry2))->FUN_00726070())) < 0 && baseCount <= 0)
            reinterpret_cast<::CombatProcedure *>((entry2))->Initialize((::CombatController *)(count));
        else
            reinterpret_cast<::CombatProcedure *>((entry2))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry2))->FUN_00726070())) + count));
        if (entry2->extras && entry2->extras->_ref_008256d0() && !((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((entry2))->FUN_00726070())))
        {
            reinterpret_cast<::ItemChangeListNode *>((changes))->FUN_00905330((::InventoryStackRecord *const &)(entry2));
            delete entry2;
        }
    }
    if (loadedAmmoTmp > 0)
    {
        AddRef* ammoActor2 = owner->isActor() ? owner : 0;
        AddForm* p = form;
        AddForm* ammoA = ((::AddForm *)(reinterpret_cast<::AmmoOwner *>((p))->FUN_00525980((::AmmoActor *)(ammoActor2))));
        if (ammoA)
            FUN_004c29a0(ammoA, 0, loadedAmmoTmp);
    }
}
// @fnv 0x004c6d40
void FUN_004c6d40_cls::ResetAndProcess(int aiArg, unsigned char a2, int aiCount)
{
    std::intptr_t ptr;
    int cnt;
    m_0c = m_08;
    m_08 = ::DAT_01012054;
    ptr = 0;
    cnt = 0;
    while (aiCount > 0)
    {
        ptr = ((std::intptr_t)(reinterpret_cast<::Inv4c6ba0 *>(this)->FindFirstItemOfType(aiArg, &cnt)));
        if (cnt > aiCount)
        {
            cnt = aiCount;
        }
        reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(0), ptr, a2, cnt, (::Transfer4c37Form4 *)(0), 0, (::Transfer4c37C37Form *)(0), 0, 0, 1, 0, (::Transfer4c37Entry *)(0));
        aiCount -= cnt;
    }
}
// @fnv 0x004cb4b0
void Inv4cb4b0::FUN_004cb4b0(std::intptr_t a1, int a2, std::intptr_t a3)
{
    TESObject* pObj = 0;
    Cont4cb4b0* pCont3 = ((::Cont4cb4b0 *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()));
    CN4cb4b0* pNode2 = pCont3 ? pCont3->_ref_00717e50() : 0;
    while (pNode2 && !pNode2->_ref_008256d0())
    {
        pObj = (*((::CO4cb4b0 **)((void *)(pNode2))))->pObj;
        if (pObj && FUN_00481f10(pObj))
        {
            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(a1), (int)(pObj), 0, a2, (::Transfer4c37Form4 *)(0), 0, (::Transfer4c37C37Form *)(a3), 0, 0, 1, 0, (::Transfer4c37Entry *)(0));
            return;
        }
        pNode2 = ((::CN4cb4b0 *)(reinterpret_cast<::Callees *>((pNode2))->FUN_00726070()));
    }
    IN4cb4b0* pItem = m_pEntryList;
    while (pItem && !pItem->_ref_008256d0())
    {
        pObj = (*((::IC4cb4b0 **)((void *)(pItem))))->pObj;
        if (pObj && FUN_00481f10(pObj))
        {
            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(a1), (int)(pObj), 0, a2, (::Transfer4c37Form4 *)(0), 0, (::Transfer4c37C37Form *)(a3), 0, 0, 1, 0, (::Transfer4c37Entry *)(0));
            return;
        }
        pItem = ((::IN4cb4b0 *)(reinterpret_cast<::Callees *>((pItem))->FUN_00726070()));
    }
}
// @fnv 0x004c37d0
int Transfer4c37C37This::FUN_004c37d0(Transfer4c37C37Obj* apSource, std::intptr_t p1, unsigned char p2, int aiCount,
                                      Transfer4c37Form4* apExtra, unsigned char abCreateRef,
                                      Transfer4c37C37Form* apTarget, std::intptr_t p7, std::intptr_t p8, unsigned char p9,
                                      unsigned char abRecurse, Transfer4c37Entry* apEntry)
{
    AutoMemContext memoryContext72((MEM_CONTEXT)54, true, ::DAT_01020778, 3700);
    this->m10 = 1;
    this->m0c = this->m08;
    this->m08 = ::DAT_01012054;
    std::intptr_t resultRef6 = 0;
    if (this->m04 != 0)
        this->m04->Vcall48(0x20);
    if (apTarget != 0)
        apTarget->Vcall48(0x20);
    Transfer4c37Cont* container11 = (Transfer4c37Cont*)((FUN_004bffb0_shell*)this)->FUN_004bffb0();
    Transfer4c37Entry* itemChange7 = !apEntry ? ((::Transfer4c37Entry *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0((::TESBoundObject *)(p1), 1, 0))) : apEntry;
    Transfer4c37NewObj* transferEntry7 = 0;
    bool updateWeapon9 = 0;
    Transfer4c37C37Obj* playerSource2 = 0;
    if (apSource->Vcall100() && apSource == (Transfer4c37C37Obj*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))
        playerSource2 = apSource;
    if (playerSource2 != 0)
    {
        if (abCreateRef != 0 || apTarget != 0)
        {
            if (((::Transfer4c37Cont14c *)(reinterpret_cast<::BSShaderNoLightingProperty *>((playerSource2))->GetBaseTexture()))->Vcall14c())
            {
                if (((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((::Transfer4c37Cont14c *)(reinterpret_cast<::BSShaderNoLightingProperty *>((playerSource2))->GetBaseTexture()))->Vcall14c()))->GetName())) == p1)
                    updateWeapon9 = 1;
            }
        }
    }
    if (abCreateRef != 0 || 0 != apTarget)
    {
        if (apExtra != 0)
        {
            if (((int)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((apExtra))->FUN_00410220(0x4a))))
            {
                if (aiCount == (int)reinterpret_cast<::FUN_00418770_shell *>((apExtra))->FUN_00418770())
                    reinterpret_cast<::FUN_0042dec0_shell *>((apExtra))->FUN_0042dec0();
            }
        }
    }
    if (apExtra != 0)
    {
        if (!((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((apExtra))->FUN_0040fe20())))
        {
            if (itemChange7 != 0 && itemChange7->m00 != 0)
                reinterpret_cast<::ItemChangeListNode *>((((Transfer4c37FirstObj*)itemChange7->m00)))->FUN_00905330((*(::InventoryStackRecord *const *)(&apExtra)));
            delete apExtra;
            apExtra = 0;
        }
    }
    long baseCount48 = 0;
    if (apSource != 0)
    {
        baseCount48 = container11 ? reinterpret_cast<::TESContainer *>((container11))->GetObjectCount((::TESObject *)(p1)) : 0;
        if (itemChange7 != 0)
        {
            if (!reinterpret_cast<::FUN_004bddd0_shell *>((itemChange7))->FUN_004bddd0(0))
            {
                if (baseCount48 + itemChange7->m04 > reinterpret_cast<::FUN_004bc980_shell *>((itemChange7))->FUN_004bc980() + reinterpret_cast<::FUN_004bc8f0_stand *>((itemChange7))->FUN_004bc8f0(0))
                {
                    if (((void *)(reinterpret_cast<::FUN_004bde40_shell *>((itemChange7))->FUN_004bde40())) != 0)
                        baseCount48 = 0;
                }
            }
        }
    }
    int negativeBaseCount13 = 0;
    if (baseCount48 < 0)
    {
        negativeBaseCount13 = baseCount48;
        baseCount48 = -1 * baseCount48;
    }
    (void)negativeBaseCount13;
    if (baseCount48 < 0)
    {
        if (apTarget != (Transfer4c37C37Form*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))
            return 0;
    }
    if ((itemChange7 != 0 && itemChange7->m04 != 0 && itemChange7->m04 + baseCount48 == 0) ||
        (itemChange7 == 0 && baseCount48 == 0))
        return resultRef6;
    int leveledItem0 = 0;
    bool hasRemainder15 = 0;
    std::intptr_t unusedChange80 = 0;
    (void)leveledItem0;
    (void)hasRemainder15;
    (void)unusedChange80;
    while (itemChange7 != 0 && aiCount > 0 && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemChange7))->FUN_00726070())) + baseCount48 > 0)
    {
        if (transferEntry7 != 0)
        {
            delete transferEntry7;
        }
        transferEntry7 = new Transfer4c37NewObj;
        transferEntry7->m08 = ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName()));
        void* extraNode6 = itemChange7->m00;
        bool searchExtra78 = 1;

        if (((apExtra != 0 && ((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((apExtra))->FUN_0040fe20()))) || abRecurse != 0) && extraNode6 != 0 &&
            *((::Transfer4c37ItemObj **)((void *)(((Transfer4c37EntryFirst*)extraNode6)))) != 0)
        {
            while (extraNode6 != 0 && *((::Transfer4c37ItemObj **)((void *)(((Transfer4c37EntryFirst*)extraNode6)))) != 0 && searchExtra78)
            {
                Transfer4c37ItemObj* sourceExtra3 = *((::Transfer4c37ItemObj **)((void *)(((Transfer4c37EntryFirst*)extraNode6))));
                Transfer4c37Obj20* transferExtra18 = 0;
                (void)transferExtra18;
                if (apExtra != (Transfer4c37Form4*)sourceExtra3 &&
                    !(apExtra == 0 && abRecurse != 0 && ((void *)(reinterpret_cast<::FUN_00418660_shell *>((sourceExtra3))->FUN_00418660()))))
                {
                    extraNode6 = (void*)((::Transfer4c37EntryFirst *)(reinterpret_cast<::Callees *>((((Transfer4c37EntryFirst*)extraNode6)))->FUN_00726070()));
                    goto block4c2d;
                }
                apExtra = 0;
                searchExtra78 = 0;
                int stackCount10 = (int)reinterpret_cast<::FUN_00418770_shell *>((sourceExtra3))->FUN_00418770();

                if (reinterpret_cast<::FUN_00418ab0_shell *>((sourceExtra3))->FUN_00418ab0(0) && (int)reinterpret_cast<::FUN_00418770_shell *>((sourceExtra3))->FUN_00418770() <= aiCount)
                {
                    bool onlyWorn39;
                    bool didUnequip10;
                    onlyWorn39 = 0;
                    if ((unsigned int)((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((sourceExtra3))->FUN_0040fe20())) <= 1 ||
                        (((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((sourceExtra3))->FUN_0040fe20())) == 2 && (int)reinterpret_cast<::FUN_00418770_shell *>((sourceExtra3))->FUN_00418770() > 1) ||
                        (reinterpret_cast<::ExtraDataList *>((sourceExtra3))->HasExtraDataType0x2F() && ((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((sourceExtra3))->FUN_0040fe20())) == 2))
                        onlyWorn39 = 1;
                    didUnequip10 = 0;
                    if (apSource->Vcall100())
                    {
                        if (!reinterpret_cast<::TESForm *>((apSource))->GetDisabled())
                        {
                            Transfer4c37C37Obj* saved58 = apSource;
                            if (((::Transfer4c37Cont14c *)(reinterpret_cast<::BSShaderNoLightingProperty *>((saved58))->GetBaseTexture())) != 0)
                            {
                                didUnequip10 =
                                    reinterpret_cast<::FUN_0088d7d0_shell *>((saved58))->FUN_0088d7d0((::TESBoundObject *)(((reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName()))),
                                                          (int)reinterpret_cast<::FUN_00418770_shell *>((sourceExtra3))->FUN_00418770(), (::ExtraDataList *)(sourceExtra3), 0, 0, 1);
                            }
                            goto flag52_done;
                        }
                    }
                    didUnequip10 = apSource->Vcall188(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName())), (int)reinterpret_cast<::FUN_00418770_shell *>((sourceExtra3))->FUN_00418770(),
                                                      sourceExtra3);
                flag52_done:
                    if (!didUnequip10 || onlyWorn39)
                        sourceExtra3 = 0;
                    itemChange7 = ((::Transfer4c37Entry *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0((::TESBoundObject *)(p1), 1, 0)));
                    if (itemChange7 == 0 || !reinterpret_cast<::FUN_004bddd0_shell *>((itemChange7))->FUN_004bddd0(0))
                    {
                        resultRef6 = this->FUN_004c37d0(apSource, p1, p2, aiCount, (Transfer4c37Form4*)sourceExtra3,
                                                        abCreateRef, apTarget, p7, p8, 1, 0, 0);
                    }
                    if (itemChange7 != 0)
                    {
                        if (1 < stackCount10)
                        {
                            if (stackCount10 - aiCount > 0)
                            {
                                if (this->m04->Vcall100())
                                {
                                    reinterpret_cast<::fnv_0088c830::ThisC *>((this->m04))->FUN_0088c830((::fnv_0088c830::FormC *)(((reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName()))), stackCount10 - aiCount,
                                                            sourceExtra3, 1, 0, 0);
                                }
                            }
                        }
                    }
                    {
                        delete transferEntry7;
                    }
                    transferEntry7 = 0;
                    return resultRef6;
                }

                else
                {
                    if (stackCount10 > aiCount || ((::Transfer4c37Ret720 *)(reinterpret_cast<::FUN_00418720_shell *>((sourceExtra3))->GetExtraLeveledItem())) != 0)
                    {
                        int flag_ed;
                        leveledItem0 = (int)(std::uintptr_t)((::Transfer4c37Ret720 *)(reinterpret_cast<::FUN_00418720_shell *>((sourceExtra3))->GetExtraLeveledItem()));
                        flag_ed = FUN_00401170(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName())));
                        if (((::Transfer4c37Ret720 *)(reinterpret_cast<::FUN_00418720_shell *>((sourceExtra3))->GetExtraLeveledItem())) != 0 && ((void *)(reinterpret_cast<::FUN_00418800_shell *>((sourceExtra3))->FUN_00418800())) != 0 &&
                            flag_ed != 0x18 && flag_ed != 0x1a)
                        {
                            if (flag_ed == 0x73 || flag_ed == 0x18 || flag_ed == 0x1a)
                                reinterpret_cast<::FUN_00419ad0_shell *>((sourceExtra3))->FUN_00419ad0(1);
                            transferExtra18 = (Transfer4c37Obj20*)sourceExtra3;
                            reinterpret_cast<::ItemChangeListNode *>((((Transfer4c37EntryHeadS*)itemChange7->m00)))->FUN_00905330((*(::InventoryStackRecord *const *)(&sourceExtra3)));
                            Transfer4c37Obj20* a60 = new Transfer4c37Obj20;
                            reinterpret_cast<::fnv_0041d280::FUN_0041d280_shell *>((a60))->SetLeveledItemIndex(((::Transfer4c37Ret720 *)(reinterpret_cast<::FUN_00418720_shell *>((sourceExtra3))->GetExtraLeveledItem()))->m0c);
                            ((Transfer4c37EntryHeadS*)itemChange7->m00)->FUN_005ae3d0(&a60);
                            reinterpret_cast<::FUN_0041d000_shell *>((transferExtra18))->FUN_0041d000();
                            itemChange7->m04 = -1 * (int)reinterpret_cast<::FUN_00418770_shell *>((sourceExtra3))->FUN_00418770();
                        }
                        else
                        {
                            if (reinterpret_cast<::ExtraDataList *>((sourceExtra3))->HasExtraDataType0x2F())
                            {
                                if (aiCount == stackCount10)
                                {
                                    itemChange7->m04 -= stackCount10;
                                    reinterpret_cast<::FUN_00419ad0_shell *>((sourceExtra3))->FUN_00419ad0(-1 * stackCount10);
                                }
                                else
                                {
                                    itemChange7->m04 -= aiCount;
                                    reinterpret_cast<::FUN_00419ad0_shell *>((sourceExtra3))->FUN_00419ad0(stackCount10 - aiCount);
                                }
                            }
                            else
                            {
                                itemChange7->m04 -= aiCount;
                                reinterpret_cast<::FUN_00419ad0_shell *>((sourceExtra3))->FUN_00419ad0(stackCount10 - aiCount);
                            }
                            {
                                transferExtra18 = new Transfer4c37Obj20;
                            }
                            reinterpret_cast<::ExtraCopyList *>((transferExtra18))->FUN_00412490((::ExtraCopyList *)(sourceExtra3), 0);
                            reinterpret_cast<::FUN_0041d000_shell *>((transferExtra18))->FUN_0041d000();
                            reinterpret_cast<::FUN_00419ad0_shell *>((transferExtra18))->FUN_00419ad0((unsigned short)aiCount);
                            if ((((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((transferExtra18))->FUN_0040fe20())) == 1 && (int)reinterpret_cast<::FUN_00418770_shell *>((transferExtra18))->FUN_00418770() > 1) ||
                                ((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((transferExtra18))->FUN_0040fe20())) == 0)
                            {
                                delete transferExtra18;
                                transferExtra18 = 0;
                            }
                        }
                        ::FUN_005ac750((::TESForm *)(apSource), (::ExtraDataList *)(transferExtra18), 4);
                        stackCount10 = aiCount;
                        aiCount = aiCount - aiCount;
                    }
                    else
                    {

                        itemChange7->m04 -= stackCount10;
                        reinterpret_cast<::CombatProcedure *>((transferEntry7))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferEntry7))->FUN_00726070())) + stackCount10));
                        transferExtra18 = (Transfer4c37Obj20*)sourceExtra3;
                        aiCount = aiCount - stackCount10;
                        reinterpret_cast<::ItemChangeListNode *>((((Transfer4c37EntryHeadS*)itemChange7->m00)))->FUN_00905330((*(::InventoryStackRecord *const *)(&sourceExtra3)));

                        if (0 != sourceExtra3)
                        {
                            if ((int)((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((sourceExtra3))->GetExtraByteValue())) >= 0)
                            {
                                if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemChange7))->FUN_00726070())) > 0)
                                {
                                    reinterpret_cast<::InventorySlot *>((this))->SetInventorySlotExtraData(
                                        (::RefSlot *)(itemChange7),
                                        (::ExtraDataList *)(void *)(itemChange7->m00 ? *((::Transfer4c37ItemObj **)((void *)(((Transfer4c37EntryFirst*)itemChange7->m00))))
                                                         : 0),
                                        (int)((signed char)(reinterpret_cast<::FUN_0042de90_cls *>((sourceExtra3))->GetExtraByteValue())));
                                }
                            }
                        }
                        sourceExtra3 = 0;
                        ::FUN_005ac750((::TESForm *)(apSource), (::ExtraDataList *)(void *)((void*)transferExtra18), 4);
                        if (reinterpret_cast<::ExtraDataList *>((((Transfer4c37ItemObj*)transferExtra18)))->IsEmpty())
                        {
                            delete (Transfer4c37ItemObj*)transferExtra18;
                            transferExtra18 = 0;
                        }
                        if (itemChange7->m04 == 0)
                            unusedChange80 = (std::intptr_t)itemChange7;
                    }
                }
            block4323:
                if (transferExtra18 != 0)
                {
                    if (reinterpret_cast<::FUN_00418ab0_shell *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_00418ab0(0))
                    {
                        reinterpret_cast<::FUN_0041b010 *>((((Transfer4c37ItemObj*)transferExtra18)))->Method(0);
                        if (reinterpret_cast<::ExtraDataList *>((((Transfer4c37ItemObj*)transferExtra18)))->IsEmpty())
                        {
                            delete (Transfer4c37ItemObj*)transferExtra18;
                            transferExtra18 = 0;
                        }
                    }
                }
                if (transferExtra18 != 0)
                {
                    if (((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_0040fe20())))
                    {
                        if (!::FUN_00559450((int *)(transferEntry7)))
                        {
                            transferEntry7->m00 = new Transfer4c37Obj96;
                        }
                        ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0(&transferExtra18);
                    }
                }
                goto block441f;
            block441f:

                if (abCreateRef != 0)
                {
                    if (transferExtra18 == 0 || ((int)(reinterpret_cast<::FUN_0041c8d0_shell *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_0041c8d0())) == 0)
                    {
                        resultRef6 = (int)((::Transfer4c37ResObj *)(reinterpret_cast<::Placement *>((this))->PlaceObject((::PlacedRef *)(apSource), (void *)(itemChange7->m08), stackCount10, 0, (::NiPoint3 *)(p7), (::NiPoint3 *)(p8))));
                        ((Transfer4c37ResObj*)resultRef6)->Vcall48(0x400);
                        if (transferExtra18 != 0)
                        {
                            if (((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_0040fe20())))
                            {
                                bool flag69 = 1;
                                if (sourceExtra3 != 0)
                                    flag69 = 0;
                                (void)flag69;
                                reinterpret_cast<::fnv_00567490::ScaleReference *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567490(reinterpret_cast<::FUN_00418860_Holder *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_00418860());
                                reinterpret_cast<::ExtraCopyList *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_00412490((::ExtraCopyList *)(void *)((void*)transferExtra18), 1);
                                reinterpret_cast<::FUN_0041afd0_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->RemoveExtraData30();
                            }
                        }
                        bool copyModel0 = 0;
                        Transfer4c37M68Obj* sourceCell30 = (Transfer4c37M68Obj*)((reinterpret_cast<::LowProcess *>((apSource))->GetTarget()));
                        if (!((int)(reinterpret_cast<::fnv_00567770::FUN_00567770_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567770())))
                        {
                            if (sourceCell30 != 0)
                            {
                                if (((int)(reinterpret_cast<::DoorCell *>((sourceCell30))->GetOwner())))
                                {
                                    if (!((unsigned char)(reinterpret_cast<::CellOwnerCheck *>((sourceCell30))->FUN_00546ca0((::Actor *)(apSource)))))
                                        copyModel0 = 1;
                                }
                            }
                        }
                        if (!copyModel0)
                        {
                            if (FUN_00401170((int)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()))) == 0x2a)
                            {
                                if (((Transfer4c37AuxObj*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())))->FUN_005f0cc0() == 1)
                                {
                                    Transfer4c37T70Obj* t70 = (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                        (TESBoundObject*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_007af430())));
                                    if (t70 != 0)
                                    {
                                        if (((int)(reinterpret_cast<::FUN_00481110_shell *>((t70))->GetWorldModel(1))) != ((int)(reinterpret_cast<::FUN_00481110_shell *>((t70))->GetWorldModel(0))))
                                            copyModel0 = 1;
                                    }
                                }
                            }
                        }
                        if (copyModel0)
                            reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>((((Transfer4c37ResObj*)resultRef6)))->SetOwner(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())));
                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                        {
                            delete (Transfer4c37ItemObj*)transferExtra18;
                            transferExtra18 = 0;
                        }
                    }
                    else
                    {

                        if (transferExtra18 != 0)
                        {
                            resultRef6 = ((int)(reinterpret_cast<::FUN_0041c8d0_shell *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_0041c8d0()));
                        }
                        else if (sourceExtra3 != 0)
                        {
                            resultRef6 = ((int)(reinterpret_cast<::FUN_0041c8d0_shell *>((sourceExtra3))->FUN_0041c8d0()));
                        }
                        if (resultRef6 != 0)
                        {
                            ((Transfer4c37ResObj*)resultRef6)->VcallC4(0);
                            reinterpret_cast<::FUN_0041c900_cls *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_0041c900();
                            bool copyExtra1 = 1;
                            if (sourceExtra3 != 0)
                                copyExtra1 = 0;
                            reinterpret_cast<::fnv_00567490::ScaleReference *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567490(reinterpret_cast<::FUN_00418860_Holder *>((((Transfer4c37ItemObj*)transferExtra18)))->FUN_00418860());
                            reinterpret_cast<::ExtraCopyList *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_00412490((::ExtraCopyList *)(void *)((void*)transferExtra18), (int)copyExtra1);
                            reinterpret_cast<::FUN_0041afd0_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->RemoveExtraData30();
                            reinterpret_cast<::FUN_0041c900_cls *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_0041c900();
                            if (((int)(reinterpret_cast<::FUN_0041b320_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_0041b320())) == 0)
                            {
                                reinterpret_cast<::fnv_0041b2a0::FUN_0041b2a0_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_0041b2a0((::TESObjectREFR *)(void *)((void*)resultRef6));
                                ((Transfer4c37ResObj*)resultRef6)->Vcall48(0x400);
                            }
                            (void)reinterpret_cast<::Placement *>((this))->PlaceObject((::PlacedRef *)(apSource), (void *)(itemChange7->m08), stackCount10, resultRef6, (::NiPoint3 *)(p7), (::NiPoint3 *)(p8));
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                            {
                                delete (Transfer4c37ItemObj*)transferExtra18;
                                transferExtra18 = 0;
                            }
                            bool copyReferenceModel20 = 0;
                            Transfer4c37M68Obj* referenceCell8 = (Transfer4c37M68Obj*)((reinterpret_cast<::LowProcess *>((apSource))->GetTarget()));
                            if (!((int)(reinterpret_cast<::fnv_00567770::FUN_00567770_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567770())))
                            {
                                if (referenceCell8 != 0)
                                {
                                    if (((int)(reinterpret_cast<::DoorCell *>((referenceCell8))->GetOwner())))
                                    {
                                        if (!((unsigned char)(reinterpret_cast<::CellOwnerCheck *>((referenceCell8))->FUN_00546ca0((::Actor *)(apSource)))))
                                            copyReferenceModel20 = 1;
                                    }
                                }
                            }
                            if (!copyReferenceModel20)
                            {
                                if (FUN_00401170((int)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()))) == 0x2a)
                                {
                                    if (((Transfer4c37AuxObj*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())))->FUN_005f0cc0() == 1)
                                    {
                                        Transfer4c37T70Obj* t70b =
                                            (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                                (TESBoundObject*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_007af430())));
                                        if (t70b != 0)
                                        {
                                            if (((int)(reinterpret_cast<::FUN_00481110_shell *>((t70b))->GetWorldModel(1))) != ((int)(reinterpret_cast<::FUN_00481110_shell *>((t70b))->GetWorldModel(0))))
                                                copyReferenceModel20 = 1;
                                        }
                                    }
                                }
                            }
                            if (copyReferenceModel20)
                                reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>((((Transfer4c37ResObj*)resultRef6)))->SetOwner(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())));
                        }
                    }
                }
                else
                {
                    if (apTarget != 0)
                    {
                        Transfer4c37Obj20* raw1ec = 0;
                        if (transferEntry7->m00 != 0)
                        {
                            Transfer4c37Node84* node84 = (Transfer4c37Node84*)transferEntry7->m00;
                            while (node84 != 0 && *((::Transfer4c37ItemObj **)((void *)(node84))) != 0)
                            {
                                std::intptr_t item88 = 0;
                                raw1ec = (Transfer4c37Obj20*)*((::Transfer4c37ItemObj **)((void *)(node84)));
                                if (!((void *)(reinterpret_cast<::FUN_00418660_shell *>((raw1ec))->FUN_00418660())))
                                {
                                    if (apSource->Vcall100())
                                    {
                                        std::intptr_t item8c = 0;
                                        item8c = (int)::FUN_004216f0((::BaseExtraList *)(((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((apSource))->FUN_005d43c0()))));
                                        if (item8c == 0)
                                            item8c = (std::intptr_t)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()));
                                        item88 = item8c;
                                    }
                                    else
                                    {
                                        item88 = ((int)(reinterpret_cast<::OwnerLookupView *>((apSource))->FUN_00567790()));
                                    }
                                    if ((unsigned char)p2 != 0)
                                    {
                                        if (!((unsigned char)(::FUN_00481f10((::TESObject *)(((reinterpret_cast<::Twin_0044ddc0 *>((transferEntry7))->GetName())))))))
                                            reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((raw1ec))->FUN_00419700((::fnv_00419700::TESForm *)(void *)((void*)item88));
                                    }
                                }
                                apTarget->Vcall190(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((transferEntry7))->GetName())), raw1ec, stackCount10);
                                node84 = ((::Transfer4c37Node84 *)(reinterpret_cast<::Callees *>((node84))->FUN_00726070()));
                            }
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        else
                        {
                            {
                                std::intptr_t item90 = 0;
                                if (apSource->Vcall100())
                                {
                                    std::intptr_t item94 = 0;
                                    item94 = (int)::FUN_004216f0((::BaseExtraList *)(((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((apSource))->FUN_005d43c0()))));
                                    if (item94 == 0)
                                        item94 = (std::intptr_t)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()));
                                    item90 = item94;
                                }
                                else
                                {
                                    item90 = ((int)(reinterpret_cast<::OwnerLookupView *>((apSource))->FUN_00567790()));
                                }
                                if ((unsigned char)p2 != 0)
                                {
                                    if (!((unsigned char)(::FUN_00481f10((::TESObject *)(((reinterpret_cast<::Twin_0044ddc0 *>((transferEntry7))->GetName())))))))
                                    {
                                        raw1ec = new Transfer4c37Obj20;
                                        reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((raw1ec))->FUN_00419700((::fnv_00419700::TESForm *)(void *)((void*)item90));
                                        reinterpret_cast<::FUN_00419ad0_shell *>((raw1ec))->FUN_00419ad0((unsigned short)aiCount);
                                    }
                                }
                                apTarget->Vcall190(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((transferEntry7))->GetName())), raw1ec, stackCount10);
                            }
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        searchExtra78 = 0;
                    }
                    else
                    {
                        if (!::Interface::ContainerIsBarter() && !::Interface::ContainerIsRecipe() && !FUN_00702680(0x40b, 0) && !FUN_00702680(0x422, 0))
                            reinterpret_cast<::FUN_004bc780_shell *>((transferEntry7))->ClearExtraDataList();
                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                    }
                }
            block4c2d:

                if (aiCount > 0)
                {
                    if (abRecurse != 0)
                    {
                        return this->FUN_004c37d0(apSource, p1, p2, aiCount, 0, abCreateRef, apTarget, p7, p8, 1, 0, 0);
                    }
                }
                if (aiCount > 0 && resultRef6 != 0)
                {
                    return resultRef6;
                }
                else if (aiCount > 0 && extraNode6 == 0)
                {
                    apExtra = 0;
                    break;
                }
            }
        }
        else
        {
            int transferCount2 = 0;
            if (baseCount48 < 0)
            {
                transferCount2 = -1 * baseCount48 + itemChange7->m04;
            }
            else
            {
                transferCount2 = baseCount48 + itemChange7->m04;
            }
            if (transferCount2 < 0)
            {
                if (baseCount48 >= 0)
                    return resultRef6;
            }
            int wornCount11;
            wornCount11 = 0;
            if (itemChange7->m00 != 0)
            {
                wornCount11 = reinterpret_cast<::FUN_004bc8f0_stand *>((itemChange7))->FUN_004bc8f0(0) + (reinterpret_cast<::FUN_004bddd0_shell *>((itemChange7))->FUN_004bddd0(0) ? 1 : 0);
            }
            int plainCount1 = 0;
            plainCount1 = transferCount2 - wornCount11;
            if (plainCount1 < 0)
                plainCount1 = 0;
            Transfer4c37ItemObj* sourceList32 = 0;
            std::intptr_t destinationList14 = 0;
            Transfer4c37Node84* remainingNode23 = (Transfer4c37Node84*)itemChange7->m00;
            if (plainCount1 > 0)
            {
                if (reinterpret_cast<::FUN_004bddd0_shell *>((itemChange7))->FUN_004bddd0(0))
                {
                    Transfer4c37ItemObj* cont = 0;
                    long cnt_b4 = 0;
                    Transfer4c37Node84* node_b0;
                    node_b0 = (Transfer4c37Node84*)itemChange7->m00;
                    while (node_b0 != 0 && *((::Transfer4c37ItemObj **)((void *)(node_b0))) != 0)
                    {
                        cont = *((::Transfer4c37ItemObj **)((void *)(node_b0)));
                        short sh_bc = reinterpret_cast<::FUN_00418770_shell *>((cont))->FUN_00418770();
                        if (reinterpret_cast<::FUN_00418ab0_shell *>((cont))->FUN_00418ab0(0))
                        {
                            if ((int)sh_bc > 1)
                                reinterpret_cast<::FUN_00419ad0_shell *>((cont))->FUN_00419ad0((int)sh_bc - aiCount);
                        }
                        (void)cnt_b4;
                        node_b0 = ((::Transfer4c37Node84 *)(reinterpret_cast<::Callees *>((node_b0))->FUN_00726070()));
                    }
                }
                else if (reinterpret_cast<::InventoryStackRecord *>((itemChange7))->HasPerkEntry())
                {
                    Transfer4c37ItemObj* hotkeyExtra37 = 0;
                    int hotkeyCount26 = 0;
                    Transfer4c37Node84* hotkeyNode5 = (Transfer4c37Node84*)itemChange7->m00;
                    while (hotkeyNode5 != 0 && *((::Transfer4c37ItemObj **)((void *)(hotkeyNode5))) != 0)
                    {
                        hotkeyExtra37 = *((::Transfer4c37ItemObj **)((void *)(hotkeyNode5)));
                        short sh_cc = reinterpret_cast<::FUN_00418770_shell *>((hotkeyExtra37))->FUN_00418770();
                        if (reinterpret_cast<::ExtraDataList *>((hotkeyExtra37))->HasExtraDataType0x2F())
                        {
                            if ((int)sh_cc > 1)
                                reinterpret_cast<::FUN_00419ad0_shell *>((hotkeyExtra37))->FUN_00419ad0((int)sh_cc - aiCount);
                        }
                        (void)hotkeyCount26;
                        hotkeyNode5 = ((::Transfer4c37Node84 *)(reinterpret_cast<::Callees *>((hotkeyNode5))->FUN_00726070()));
                    }
                }
                if (plainCount1 >= aiCount)
                {
                    if (negativeBaseCount13 == 0)
                    {
                        itemChange7->m04 = itemChange7->m04 - aiCount;
                    }
                    transferCount2 = aiCount;
                    aiCount = 0;
                }
                else
                {
                    if (container11 != 0)
                    {
                        if (reinterpret_cast<::TESContainer *>((container11))->GetObjectCount((::TESObject *)(p1)) > 0)
                        {
                            itemChange7->m04 -= plainCount1;
                        }
                    }
                    transferCount2 = plainCount1;
                    aiCount = aiCount - plainCount1;
                    if (itemChange7->m04 + baseCount48 < 0)
                    {
                        if (baseCount48 != 0)
                        {
                            itemChange7->m04 = -1 * baseCount48;
                        }
                        else
                        {
                            itemChange7->m04 = 0;
                        }
                    }
                    else
                    {
                        itemChange7->m04 -= transferCount2;
                    }
                }
                if (abCreateRef != 0)
                {
                    resultRef6 = (int)((::Transfer4c37ResObj *)(reinterpret_cast<::Placement *>((this))->PlaceObject((::PlacedRef *)(apSource), (void *)(p1), transferCount2, 0, (::NiPoint3 *)(p7), (::NiPoint3 *)(p8))));
                    {
                        Transfer4c37M68Obj* plainCell18 = (Transfer4c37M68Obj*)((reinterpret_cast<::LowProcess *>((apSource))->GetTarget()));
                        bool copyPlainModel42 = 0;
                        if (!((int)(reinterpret_cast<::fnv_00567770::FUN_00567770_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567770())))
                        {
                            if (plainCell18 != 0)
                            {
                                if (((int)(reinterpret_cast<::DoorCell *>((plainCell18))->GetOwner())))
                                {
                                    if (!((unsigned char)(reinterpret_cast<::CellOwnerCheck *>((plainCell18))->FUN_00546ca0((::Actor *)(apSource)))))
                                        copyPlainModel42 = 1;
                                }
                            }
                        }
                        if (!copyPlainModel42)
                        {
                            if (FUN_00401170((int)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()))) == 0x2a)
                            {
                                if (((Transfer4c37AuxObj*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())))->FUN_005f0cc0() == 1)
                                {
                                    Transfer4c37T70Obj* loopTail =
                                        (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                            (TESBoundObject*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_007af430())));
                                    if (loopTail != 0)
                                    {
                                        if (((int)(reinterpret_cast<::FUN_00481110_shell *>((loopTail))->GetWorldModel(1))) != ((int)(reinterpret_cast<::FUN_00481110_shell *>((loopTail))->GetWorldModel(0))))
                                            copyPlainModel42 = 1;
                                    }
                                }
                            }
                        }
                        if (copyPlainModel42)
                            reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>((((Transfer4c37ResObj*)resultRef6)))->SetOwner(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())));
                    }
                    {
                        delete transferEntry7;
                        transferEntry7 = 0;
                    }
                    if (destinationList14 != 0)
                    {
                        delete (Transfer4c37ItemObj*)destinationList14;
                    }
                    destinationList14 = 0;
                }
                else if (apTarget != 0)
                {
                    void* dc_dc = 0;
                    if (apSource->Vcall100())
                    {
                        void* dc_e0 = 0;
                        dc_e0 = (void*)(std::uintptr_t)::FUN_004216f0((::BaseExtraList *)(((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((apSource))->FUN_005d43c0()))));
                        if (dc_e0 == 0)
                            dc_e0 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()));
                        dc_dc = dc_e0;
                    }
                    else
                    {
                        dc_dc = (void*)((reinterpret_cast<::OwnerLookupView *>((apSource))->FUN_00567790()));
                    }
                    if (p2 != 0 && !((unsigned char)(::FUN_00481f10((::TESObject *)(p1)))) &&
                        (FUN_00401170(p1) != 0x29 || apTarget != (Transfer4c37C37Form*)(*reinterpret_cast<char * *>(&::_g_thePlayer))))
                    {
                        if (apExtra == 0)
                        {
                            apExtra = (Transfer4c37Form4*)new Transfer4c37Obj20;
                        }
                        reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((((Transfer4c37Obj20*)apExtra)))->FUN_00419700((::fnv_00419700::TESForm *)(dc_dc));
                        reinterpret_cast<::FUN_00419ad0_shell *>((((Transfer4c37Obj20*)apExtra)))->FUN_00419ad0((unsigned short)transferCount2);
                    }
                    if (apExtra != 0)
                    {
                        if (apTarget == (Transfer4c37C37Form*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))
                        {
                            if (FUN_00401170(p1) == 0x29)
                                reinterpret_cast<::FUN_0041aed0_shell *>((((Transfer4c37Obj20*)apExtra)))->FUN_0041aed0();
                        }
                    }
                    apTarget->Vcall190(p1, apExtra, transferCount2);
                    {
                        delete transferEntry7;
                        transferEntry7 = 0;
                    }
                }
                {
                    delete transferEntry7;
                    transferEntry7 = 0;
                }
            }

            if (aiCount > 0 && itemChange7 != 0 && itemChange7->m00 != 0 &&
                !((Transfer4c37M00Obj*)itemChange7->m00)->FUN_008256d0())
            {
                remainingNode23 = (Transfer4c37Node84*)itemChange7->m00;
                while (remainingNode23 != 0 && *((::Transfer4c37ItemObj **)((void *)(remainingNode23))) != 0 && aiCount > 0)
                {
                    bool validStack1 = 1;
                    sourceList32 = *((::Transfer4c37ItemObj **)((void *)(remainingNode23)));
                    if (transferEntry7 != 0)
                    {
                        delete transferEntry7;
                    }
                    {
                        transferEntry7 = new Transfer4c37NewObj;
                    }
                    if (itemChange7 != 0)
                        transferEntry7->m08 = ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName()));
                    if ((int)reinterpret_cast<::FUN_00418770_shell *>((sourceList32))->FUN_00418770() < 0)
                    {
                        validStack1 = 0;
                        remainingNode23 = ((::Transfer4c37Node84 *)(reinterpret_cast<::Callees *>((remainingNode23))->FUN_00726070()));
                    }
                    else if (reinterpret_cast<::FUN_00418ab0_shell *>((sourceList32))->FUN_00418ab0(0) && (int)reinterpret_cast<::FUN_00418770_shell *>((sourceList32))->FUN_00418770() <= 1)
                    {
                        bool onlyWornFlag14 = 0;
                        if ((unsigned int)((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((sourceList32))->FUN_0040fe20())) <= 1 ||
                            (((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((sourceList32))->FUN_0040fe20())) == 2 && (int)reinterpret_cast<::FUN_00418770_shell *>((sourceList32))->FUN_00418770() > 1))
                        {
                            apExtra = 0;
                            onlyWornFlag14 = 1;
                        }
                        (void)onlyWornFlag14;
                        bool unequipped41 = apSource->Vcall188(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((itemChange7))->GetName())),
                                                               (int)reinterpret_cast<::FUN_00418770_shell *>((sourceList32))->FUN_00418770(), sourceList32);
                        if (unequipped41)
                        {
                            resultRef6 = this->FUN_004c37d0(apSource, p1, p2, aiCount, apExtra, abCreateRef, apTarget,
                                                            p7, p8, 1, 0, 0);
                        }
                        else
                        {
                            ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::Transfer4c37LogObj *>(&::g_011d31f8))))->IsDLCAvailable()))), 0,
                                                  (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"), 0,
                                                  DAT_010162c0, 0);
                        }
                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                        return resultRef6;
                    }
                    else
                    {
                        transferCount2 = (int)reinterpret_cast<::FUN_00418770_shell *>((sourceList32))->FUN_00418770();
                        if (transferCount2 > aiCount || ((::Transfer4c37Ret720 *)(reinterpret_cast<::FUN_00418720_shell *>((sourceList32))->GetExtraLeveledItem())) != 0)
                        {
                            leveledItem0 = (int)(std::uintptr_t)((::Transfer4c37Ret720 *)(reinterpret_cast<::FUN_00418720_shell *>((sourceList32))->GetExtraLeveledItem()));
                            if (leveledItem0)
                            {
                                if (aiCount == transferCount2 || aiCount > transferCount2)
                                {
                                    itemChange7->m04 += -1 * transferCount2;
                                    reinterpret_cast<::FUN_00419ad0_shell *>((sourceList32))->FUN_00419ad0(-1 * transferCount2);
                                }
                                else
                                {
                                    itemChange7->m04 += -1 * aiCount;
                                    reinterpret_cast<::FUN_00419ad0_shell *>((sourceList32))->FUN_00419ad0(transferCount2 - aiCount);
                                }
                            }
                            else
                            {
                                itemChange7->m04 -= aiCount;
                                reinterpret_cast<::FUN_00419ad0_shell *>((sourceList32))->FUN_00419ad0(transferCount2 - aiCount);
                            }
                            {
                                destinationList14 = (int)new Transfer4c37Obj20;
                            }
                            reinterpret_cast<::ExtraCopyList *>((((Transfer4c37Obj20*)destinationList14)))->FUN_00412490((::ExtraCopyList *)(sourceList32), 0);
                            reinterpret_cast<::FUN_0041d000_shell *>((((Transfer4c37Obj20*)destinationList14)))->FUN_0041d000();
                            if (transferCount2 < aiCount)
                                reinterpret_cast<::FUN_00419ad0_shell *>((((Transfer4c37Obj20*)destinationList14)))->FUN_00419ad0((unsigned short)transferCount2);
                            else
                                reinterpret_cast<::FUN_00419ad0_shell *>((((Transfer4c37Obj20*)destinationList14)))->FUN_00419ad0((unsigned short)aiCount);
                            if (aiCount < transferCount2)
                                transferCount2 = aiCount;
                            aiCount = aiCount - transferCount2;
                            if (reinterpret_cast<::ExtraDataList *>((((Transfer4c37Obj20*)destinationList14)))->IsEmpty())
                            {
                                delete (Transfer4c37Obj20*)destinationList14;
                                destinationList14 = 0;
                            }
                            else
                            {
                                if (!::FUN_00559450((int *)(transferEntry7)))
                                {
                                    transferEntry7->m00 = new Transfer4c37Obj96;
                                }
                                ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0(&destinationList14);
                            }
                        }
                        else
                        {
                            itemChange7->m04 -= transferCount2;
                            reinterpret_cast<::CombatProcedure *>((transferEntry7))->Initialize((::CombatController *)(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferEntry7))->FUN_00726070())) + transferCount2));
                            destinationList14 = (int)sourceList32;
                            aiCount = aiCount - transferCount2;
                            reinterpret_cast<::ItemChangeListNode *>((((Transfer4c37EntryHeadS*)itemChange7->m00)))->FUN_00905330((*(::InventoryStackRecord *const *)((Transfer4c37ItemObj**)&destinationList14)));
                            sourceList32 = 0;
                            if (reinterpret_cast<::ExtraDataList *>((((Transfer4c37ItemObj*)destinationList14)))->IsEmpty())
                            {
                                delete (Transfer4c37ItemObj*)destinationList14;
                                destinationList14 = 0;
                            }
                            else
                            {
                                if (!::FUN_00559450((int *)(transferEntry7)))
                                {
                                    transferEntry7->m00 = new Transfer4c37Obj96;
                                }
                                ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0(&destinationList14);
                            }
                        }
                    }
                t70d:
                    if (itemChange7 != 0 && validStack1)
                    {
                        if (abCreateRef != 0)
                        {
                            if (destinationList14 == 0 ||
                                ((int)(reinterpret_cast<::FUN_0041c8d0_shell *>((((Transfer4c37ItemObj*)destinationList14)))->FUN_0041c8d0())) == 0)
                            {

                                resultRef6 =
                                    (int)((::Transfer4c37ResObj *)(reinterpret_cast<::Placement *>((this))->PlaceObject((::PlacedRef *)(apSource), (void *)(itemChange7->m08), transferCount2, 0, (::NiPoint3 *)(p7), (::NiPoint3 *)(p8))));
                                {
                                    Transfer4c37M68Obj* stackCell3 = (Transfer4c37M68Obj*)((reinterpret_cast<::LowProcess *>((apSource))->GetTarget()));
                                    bool copyStackModel11 = 0;
                                    if (!((int)(reinterpret_cast<::fnv_00567770::FUN_00567770_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567770())))
                                    {
                                        if (stackCell3 != 0)
                                        {
                                            if (((int)(reinterpret_cast<::DoorCell *>((stackCell3))->GetOwner())))
                                            {
                                                if (!((unsigned char)(reinterpret_cast<::CellOwnerCheck *>((stackCell3))->FUN_00546ca0((::Actor *)(apSource)))))
                                                    copyStackModel11 = 1;
                                            }
                                        }
                                    }
                                    if (!copyStackModel11)
                                    {
                                        if (FUN_00401170((int)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()))) == 0x2a)
                                        {
                                            if (((Transfer4c37AuxObj*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())))->FUN_005f0cc0() == 1)
                                            {
                                                Transfer4c37T70Obj* t70e =
                                                    (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                                        (TESBoundObject*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_007af430())));
                                                if (t70e != 0)
                                                {
                                                    if (((int)(reinterpret_cast<::FUN_00481110_shell *>((t70e))->GetWorldModel(1))) != ((int)(reinterpret_cast<::FUN_00481110_shell *>((t70e))->GetWorldModel(0))))
                                                        copyStackModel11 = 1;
                                                }
                                            }
                                        }
                                    }
                                    if (copyStackModel11)
                                        reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>((((Transfer4c37ResObj*)resultRef6)))->SetOwner(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())));
                                }
                                if (destinationList14 != 0)
                                {
                                    if (((int)(reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((((Transfer4c37ItemObj*)destinationList14)))->FUN_0040fe20())))
                                    {
                                        reinterpret_cast<::fnv_00567490::ScaleReference *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567490(reinterpret_cast<::FUN_00418860_Holder *>((((Transfer4c37ItemObj*)destinationList14)))->FUN_00418860());
                                        reinterpret_cast<::ExtraCopyList *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_00412490((::ExtraCopyList *)(void *)((void*)destinationList14), 1);
                                        reinterpret_cast<::FUN_0041afd0_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->RemoveExtraData30();
                                    }
                                }
                                {
                                    delete transferEntry7;
                                    transferEntry7 = 0;
                                }
                                {
                                    delete (Transfer4c37ItemObj*)destinationList14;
                                    destinationList14 = 0;
                                }
                            }
                            else
                            {

                                if (destinationList14 != 0)
                                {
                                    resultRef6 = ((int)(reinterpret_cast<::FUN_0041c8d0_shell *>((((Transfer4c37ItemObj*)destinationList14)))->FUN_0041c8d0()));
                                }
                                else if (sourceList32 != 0)
                                {
                                    resultRef6 = ((int)(reinterpret_cast<::FUN_0041c8d0_shell *>((((Transfer4c37ItemObj*)sourceList32)))->FUN_0041c8d0()));
                                }
                                if (resultRef6 != 0)
                                {
                                    ((Transfer4c37ResObj*)resultRef6)->VcallC4(0);
                                    reinterpret_cast<::FUN_0041c900_cls *>((((Transfer4c37ItemObj*)destinationList14)))->FUN_0041c900();
                                    {
                                        bool flag41 = 1;
                                        if (sourceList32 != 0)
                                            flag41 = 0;
                                        reinterpret_cast<::fnv_00567490::ScaleReference *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567490(reinterpret_cast<::FUN_00418860_Holder *>((((Transfer4c37ItemObj*)destinationList14)))->FUN_00418860());
                                        reinterpret_cast<::ExtraCopyList *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_00412490((::ExtraCopyList *)(void *)((void*)destinationList14), (int)flag41);
                                    }
                                    reinterpret_cast<::FUN_0041afd0_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->RemoveExtraData30();
                                    reinterpret_cast<::FUN_0041c900_cls *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_0041c900();
                                    if (((int)(reinterpret_cast<::FUN_0041b320_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_0041b320())) == 0)
                                    {
                                        reinterpret_cast<::fnv_0041b2a0::FUN_0041b2a0_shell *>((((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((((Transfer4c37ResObj*)resultRef6)))->FUN_005d43c0()))))->FUN_0041b2a0((::TESObjectREFR *)(void *)((void*)resultRef6));
                                        ((Transfer4c37ResObj*)resultRef6)->Vcall48(0x400);
                                    }
                                    resultRef6 = (int)((::Transfer4c37ResObj *)(reinterpret_cast<::Placement *>((this))->PlaceObject((::PlacedRef *)(apSource), (void *)(itemChange7->m08), transferCount2,
                                                                        resultRef6, (::NiPoint3 *)(p7), (::NiPoint3 *)(p8))));
                                    {
                                        delete transferEntry7;
                                        transferEntry7 = 0;
                                    }
                                    {
                                        delete (Transfer4c37ItemObj*)destinationList14;
                                        destinationList14 = 0;
                                    }
                                    {
                                        bool copyStackReferenceModel26 = 0;
                                        Transfer4c37M68Obj* stackReferenceCell32 =
                                            (Transfer4c37M68Obj*)((reinterpret_cast<::LowProcess *>((apSource))->GetTarget()));
                                        if (!((int)(reinterpret_cast<::fnv_00567770::FUN_00567770_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567770())))
                                        {
                                            if (stackReferenceCell32 != 0)
                                            {
                                                if (((int)(reinterpret_cast<::DoorCell *>((stackReferenceCell32))->GetOwner())))
                                                {
                                                    if (!((unsigned char)(reinterpret_cast<::CellOwnerCheck *>((stackReferenceCell32))->FUN_00546ca0((::Actor *)(apSource)))))
                                                        copyStackReferenceModel26 = 1;
                                                }
                                            }
                                        }
                                        if (!copyStackReferenceModel26)
                                        {
                                            if (FUN_00401170((int)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()))) == 0x2a)
                                            {
                                                if (((Transfer4c37AuxObj*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())))->FUN_005f0cc0() ==
                                                    1)
                                                {
                                                    Transfer4c37T70Obj* t70f;
                                                    t70f = (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                                        (TESBoundObject*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_007af430())));
                                                    if (t70f != 0)
                                                    {
                                                        if (((int)(reinterpret_cast<::FUN_00481110_shell *>((t70f))->GetWorldModel(1))) != ((int)(reinterpret_cast<::FUN_00481110_shell *>((t70f))->GetWorldModel(0))))
                                                            copyStackReferenceModel26 = 1;
                                                    }
                                                }
                                            }
                                        }
                                        if (copyStackReferenceModel26)
                                            reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>((((Transfer4c37ResObj*)resultRef6)))->SetOwner(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())));
                                    }
                                }
                            }

                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        else if (apTarget != 0)
                        {

                            Transfer4c37Obj20* item_fc = 0;
                            if (transferEntry7->m00 != 0)
                            {
                                item_fc =
                                    (Transfer4c37Obj20*)*((::Transfer4c37ItemObj **)((void *)(((Transfer4c37Node84*)transferEntry7->m00))));
                            }
                            else
                            {
                                item_fc = new Transfer4c37Obj20;
                                transferEntry7->m00 = new Transfer4c37Obj96;
                                ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0((int*)&item_fc);
                            }
                            std::intptr_t item_100 = 0;
                            if (apSource->Vcall100())
                            {
                                std::intptr_t t104 = 0;
                                t104 = (int)::FUN_004216f0((::BaseExtraList *)(((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((apSource))->FUN_005d43c0()))));
                                if (t104 == 0)
                                    t104 = (std::intptr_t)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()));
                                item_100 = t104;
                            }
                            else
                            {
                                item_100 = ((int)(reinterpret_cast<::OwnerLookupView *>((apSource))->FUN_00567790()));
                            }
                            if (p2 != 0 && !((unsigned char)(::FUN_00481f10((::TESObject *)(((reinterpret_cast<::Twin_0044ddc0 *>((transferEntry7))->GetName())))))))
                            {
                                reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((item_fc))->FUN_00419700((::fnv_00419700::TESForm *)(void *)((void*)item_100));
                                reinterpret_cast<::FUN_00419ad0_shell *>((item_fc))->FUN_00419ad0((unsigned short)transferCount2);
                            }
                            else
                            {
                                reinterpret_cast<::FUN_0041aed0_shell *>((item_fc))->FUN_0041aed0();
                            }
                            apTarget->Vcall190(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((transferEntry7))->GetName())), item_fc, transferCount2);

                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        else
                        {

                            if ((unsigned char)p9 != 0)
                                reinterpret_cast<::FUN_004bc780_shell *>((transferEntry7))->ClearExtraDataList();
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }

                        if (sourceList32 != 0)
                            remainingNode23 = ((::Transfer4c37Node84 *)(reinterpret_cast<::Callees *>((remainingNode23))->FUN_00726070()));
                        if (aiCount != 0)
                            hasRemainder15 = 1;
                    }
                    else
                    {

                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                        {
                            delete (Transfer4c37ItemObj*)destinationList14;
                            destinationList14 = 0;
                        }
                    }
                }
            }
        }
    block62e7:
        itemChange7 = ((::Transfer4c37Entry *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0((::TESBoundObject *)(p1), 1, 0)));
    }

    if ((unsigned char)abRecurse != 0 && aiCount > 0)
        return this->FUN_004c37d0(apSource, p1, p2, aiCount, apExtra, abCreateRef, apTarget, p7, p8, 1, 0, 0);
    if ((itemChange7 == 0 || hasRemainder15) && baseCount48 != 0)
    {
        if (itemChange7 != 0)
            baseCount48 += itemChange7->m04;
        if (!baseCount48)
        {
            reinterpret_cast<::FileMatchList *>((((Transfer4c37Tail470*)((void *)(::FUN_00559450((int *)(itemChange7)))))))->RemoveAll();
            return resultRef6;
        }
        if (abCreateRef != 0)
        {
            resultRef6 = (int)((::Transfer4c37ResObj *)(reinterpret_cast<::Placement *>((this))->PlaceObject((::PlacedRef *)(apSource), (void *)(p1), aiCount, 0, (::NiPoint3 *)(p7), (::NiPoint3 *)(p8))));
            {
                Transfer4c37M68Obj* remainderCell3 = (Transfer4c37M68Obj*)((reinterpret_cast<::LowProcess *>((apSource))->GetTarget()));
                bool copyRemainderModel32 = 0;
                if (!((int)(reinterpret_cast<::fnv_00567770::FUN_00567770_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_00567770())))
                {
                    if (remainderCell3 != 0)
                    {
                        if (((int)(reinterpret_cast<::DoorCell *>((remainderCell3))->GetOwner())))
                        {
                            if (!((unsigned char)(reinterpret_cast<::CellOwnerCheck *>((remainderCell3))->FUN_00546ca0((::Actor *)(apSource)))))
                                copyRemainderModel32 = 1;
                        }
                    }
                }
                if (!copyRemainderModel32)
                {
                    if (FUN_00401170((int)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()))) == 0x2a)
                    {
                        if (((Transfer4c37AuxObj*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())))->FUN_005f0cc0() == 1)
                        {
                            Transfer4c37T70Obj* t70_110 = (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                (TESBoundObject*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Transfer4c37ResObj*)resultRef6)))->FUN_007af430())));
                            if (t70_110 != 0)
                            {
                                if (((int)(reinterpret_cast<::FUN_00481110_shell *>((t70_110))->GetWorldModel(1))) != ((int)(reinterpret_cast<::FUN_00481110_shell *>((t70_110))->GetWorldModel(0))))
                                    copyRemainderModel32 = 1;
                            }
                        }
                    }
                }
                if (copyRemainderModel32)
                    reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>((((Transfer4c37ResObj*)resultRef6)))->SetOwner(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430())));
            }
        }
        else if (apTarget != 0)
        {
            std::uintptr_t item_114 = 0;
            if (apSource->Vcall100())
            {
                std::intptr_t a = 0;
                a = (int)::FUN_004216f0((::BaseExtraList *)(((::Transfer4c37MidObj *)(reinterpret_cast<::FUN_005d43c0_ *>((apSource))->FUN_005d43c0()))));
                if (!a)
                    a = (std::intptr_t)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSource))->FUN_007af430()));
                item_114 = a;
            }
            else
            {
                item_114 = ((int)(reinterpret_cast<::OwnerLookupView *>((apSource))->FUN_00567790()));
            }
            if ((unsigned char)0 != p2 && !((unsigned char)(::FUN_00481f10((::TESObject *)(p1)))))
            {
                if (apExtra == 0)
                {
                    apExtra = (Transfer4c37Form4*)new Transfer4c37Obj20;
                }
                reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((((Transfer4c37Obj20*)apExtra)))->FUN_00419700((::fnv_00419700::TESForm *)(void *)((void*)item_114));
                reinterpret_cast<::FUN_00419ad0_shell *>((((Transfer4c37Obj20*)apExtra)))->FUN_00419ad0((unsigned short)aiCount);
            }
            else if (apExtra != 0)
            {
                reinterpret_cast<::FUN_0041aed0_shell *>((((Transfer4c37Obj20*)apExtra)))->FUN_0041aed0();
            }
            if (0 < aiCount)
            {
                if (FUN_00401170(p1) == 0x31 && apTarget == (Transfer4c37C37Form*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))
                {
                    bool flag_11d = 0;
                    if ((unsigned char)p2 != 0 && item_114 != 0)
                    {
                        if (FUN_00401170(item_114) == 8)
                        {
                            std::intptr_t pObj = item_114;
                            if (!reinterpret_cast<::FUN_0047d7c0_Class *>((((Transfer4c37D7Obj*)pObj)))->FUN_0047d7c0())
                                flag_11d = 1;
                        }
                        else
                        {
                            std::intptr_t tmp_128 = item_114;
                            if (tmp_128 != 0)
                            {
                                int res_12c = ::fnv_0047e040::FUN_0047e040(((Transfer4c37ActorValueView*)tmp_128)->values.Vcall3(0x17));
                                if (res_12c != 2 && res_12c != 4)
                                    flag_11d = 1;
                            }
                        }
                    }
                    if (flag_11d)
                    {
                        reinterpret_cast<::KarmaActor *>((((Transfer4c37C37Obj*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_0094fd30((int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Transfer4c37Glob20 *>(&::originalRuntimeFloatSetting282)))))));
                    }
                    std::intptr_t weapon = p1;
                    reinterpret_cast<::PlayerNoteStub *>((((Transfer4c37C37Obj*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_00966a70((::NoteStub *)(weapon), 1);
                }
                else
                {
                    apTarget->Vcall190(p1, apExtra, aiCount);
                }
            }
        }
        {
            delete transferEntry7;
            transferEntry7 = 0;
        }
        if (itemChange7 == 0)
        {
            itemChange7 = (Transfer4c37Entry*)new Transfer4c37EntryNew(p1, -1 * aiCount);
            reinterpret_cast<::Callees *>((((Transfer4c37ThisHead*)this->m00)))->FUN_00905820(&itemChange7);
        }
        else
        {
            itemChange7->m04 -= aiCount;
        }
    }
    itemChange7 = ((::Transfer4c37Entry *)(reinterpret_cast<::FUN_004bfba0_shell *>((this))->FUN_004bfba0((::TESBoundObject *)(p1), 1, 0)));
    if (itemChange7 != 0 && (leveledItem0 == 0 || apSource->Vcall100()) &&
        ((itemChange7->m04 == 0 && baseCount48 == 0) ||
         (itemChange7->m00 != 0 && ((Transfer4c37M00Obj*)itemChange7->m00)->FUN_008256d0() && itemChange7->m04 == 0)))
    {
        if (!::Interface::ContainerIsBarter() && !::Interface::ContainerIsRecipe() && !FUN_00702680(0x40b, 0) && !FUN_00702680(0x40b, 0))
            reinterpret_cast<::FUN_004bc780_shell *>((itemChange7))->ClearExtraDataList();
        reinterpret_cast<::ItemChangeListNode *>((((Transfer4c37ThisHead*)this->m00)))->FUN_00905330((*(::InventoryStackRecord *const *)(&itemChange7)));
        {
            delete itemChange7;
        }
    }
    else
    {

        if (itemChange7 != 0)
        {
            if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemChange7))->FUN_00726070())) + baseCount48 < 0)
            {
                if (!reinterpret_cast<::FUN_004bddd0_shell *>((itemChange7))->FUN_004bddd0(0))
                {
                    if (((void *)(::FUN_00559450((int *)(itemChange7)))) != 0)
                    {
                        if (leveledItem0 == 0)
                            reinterpret_cast<::FileMatchList *>((((Transfer4c37Tail470*)((void *)(::FUN_00559450((int *)(itemChange7)))))))->RemoveAll();
                    }
                }
            }
        }
    }
    if (updateWeapon9)
    {
        if (((int)(reinterpret_cast<::FUN_008a1710_shell *>((playerSource2))->FUN_008a1710())) != 0)
            playerSource2->Vcall3ec(((int)(reinterpret_cast<::FUN_008a1710_shell *>((playerSource2))->FUN_008a1710())), 0, 0, 0);
    }
    return resultRef6;
}

// Searches the linked list of changes for an entry matching apObj, optionally filtered by aId via the replacement reference form ID.
// @fnv 0x004bfba0
InventoryStackRecord* FUN_004bfba0_shell::FUN_004bfba0(TESBoundObject* apObj, int ableveled, int aId)
{
    ItemNode* pkCurrentObject = *(ItemNode**)this;
    bool bHasResultObj = true;
    while (pkCurrentObject && bHasResultObj)
    {
        InventoryStackRecord* pchange = *((::InventoryStackRecord **)((void *)(pkCurrentObject)));
        if (pchange && pchange->m_pItemObject == apObj)
        {
            bHasResultObj = false;
        }
        else
        {
            pkCurrentObject = ((::ItemNode *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
        }
    }
    if (pkCurrentObject)
    {
        InventoryStackRecord* pchange = *((::InventoryStackRecord **)((void *)(pkCurrentObject)));
        if (pchange && aId)
        {
            ExtraNode* pkCurrentObject = (ExtraNode*)pchange->m_pExtraDataLists;
            while (pkCurrentObject)
            {
                ExtraDataList* pextra = *((::ExtraDataList **)((void *)(pkCurrentObject)));
                if (pextra && ((::RefIdShell *)(((FUN_0041c8d0_shell*)pextra)->FUN_0041c8d0())) &&
                    ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RefIdShell *)(((FUN_0041c8d0_shell*)pextra)->FUN_0041c8d0()))))->FUN_0084e3a0())) == aId)
                    return pchange;
                pkCurrentObject = ((::ExtraNode *)(reinterpret_cast<::Callees *>((pkCurrentObject))->FUN_00726070()));
            }
            return 0;
        }
        else
        {
            return pchange;
        }
    }
    else
    {
        return 0;
    }
}

void DeleteItemChange(InventoryStackRecord* item);

struct ExtraNode_ctxr;

struct ItemNode_ctxr;

struct ExtraNode_ctxr;

struct StartMenu_ctxr
{
};

struct GlobalObject_0040c150_ctxr : public StartMenu_ctxr
{
};

struct TESFullName_ctxr : public BaseFormComponent
{
};

struct FUN_00474a00_ctxr
{
};

struct S_004d4030_ctxr
{
    ItemNode_ctxr* head;
    void FUN_004d4030();
};

struct XArr_ctxr
{
};

struct FUN_004bfb70_stand_ctxr
{
    char pad[0xe3c];
    XArr_ctxr arr;
    void SetIdleAt(unsigned int i, XIdle* v);
};

void SetField1F0(FUN_004c0cd0_This* pThis, FUN_004c0cd0_Arg arg);

struct FUN_00410360_ctxr
{
    FUN_00410360_ctxr();
    char pad[0x20];
};

struct FUN_004bc550_ctxr
{
    FUN_004bc550_ctxr(TESBoundObject*, int);
    char pad[0xc];
};

struct TESNPC_ctxr
{
};

struct Container4cfe20_ctxr
{
};

struct FUN_004cfe20_t_ctxr : public ::InventoryChanges
{
    Container4cfe20_ctxr* FUN_004bffb0();
    bool HasItem(unsigned int aId);
};

class B4BDF00Form_ctxr
{
  public:
};

class B4BDF00Data_ctxr;

class B4BDF00Data_ctxr
{
  public:
    float GetScaledValue(void* pvActor, float fValue, bool bFlag);

    int unk00;
    int unk04;
    B4BDF00Form_ctxr* m_pkForm;
};

struct BookForm_ctxr
{
};

struct ItemChangeCalc_ctxr
{
    int unknown00;
    int unknown04;
    BookForm_ctxr* item;
    void UpdateItemChange(int unused);
};

struct Container4c6ba0_ctxr
{
};

struct Inv4c6ba0_ctxr
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0_ctxr* FUN_004bffb0();
    TESBoundObject* FindFirstItemOfType(int aType, int* apCount);
};

struct NiMatrix3Helper_ctxr
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};

struct Weapon_ctxr;

struct Extra_ctxr;

struct Item_ctxr;

struct ItemList_ctxr;

struct BaseNode_ctxr;

struct Form_ctxr
{
};

struct Weapon_ctxr : Form_ctxr
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    AmmoLink ammo;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    ValueComp value;
    int FUN_00446390();
};

struct Extra_ctxr
{
    bool FUN_00418b10();
};

struct FUN_0096a2d0_ctxr
{
    Extra_ctxr* item;
    FUN_0096a2d0_ctxr* next;
    FUN_0096a2d0_ctxr();
    void FUN_005ae3d0(Extra_ctxr**);
};

struct FUN_0076b630_ctxr : FUN_004459e0
{
    FUN_0096a2d0_ctxr* extras;
    int count;
    Weapon_ctxr* weapon;
    FUN_0076b630_ctxr();
};

struct ItemList_ctxr
{
    FUN_0076b630_ctxr* item;
    ItemList_ctxr* next;
    bool FUN_008256d0();
};

struct BaseItem_ctxr
{
    int count;
    Weapon_ctxr* form;
};

struct BaseNode_ctxr
{
    BaseItem_ctxr* item;
    BaseNode_ctxr* next;
};

struct Container_ctxr
{
};

struct Target_ctxr
{
    ItemList_ctxr* changes;
    ActorStand* owner;
    Container_ctxr* FUN_004bffb0();
    FUN_0076b630_ctxr* FUN_004c8c10(int, int);
    FUN_0076b630_ctxr* SelectBestWeapon(ActorStand*, float*, int, bool);
};

struct ObjectForm_ctxr
{
};

struct InventoryEntry_ctxr
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    ObjectForm_ctxr* m_pItemObject;
};

struct Load90_ctxr
{
};

struct EquipForm_ctxr;

struct EquipEntry_ctxr;

struct EquipActor_ctxr;

struct EquipEntry_ctxr
{
    EquipList* extras;
    int count;
    EquipForm_ctxr* form;
    EquipEntry_ctxr(EquipForm_ctxr*, int);
    ~EquipEntry_ctxr();
};

struct EquipForm_ctxr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    EquipBiped biped;
};

struct EquipProcess_ctxr
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual EquipEntry_ctxr* v148();
    virtual EquipEntry_ctxr* v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool v160(EquipEntry_ctxr*, int, int);
    virtual void v164();
    virtual bool v168(EquipEntry_ctxr*);
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468(int);
    virtual void v46c();
    virtual void v470();
    virtual bool v474(int);
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4(EquipActor_ctxr*);
};

struct EquipActor_ctxr
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(int);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int v1d0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    EquipProcess_ctxr* process;
    void SetField1F0(EquipForm_ctxr*);
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};

struct EquipInv_ctxr
{
    EquipChangeList* changes;
    EquipActor_ctxr* owner;
    EquipContainer* FUN_004bffb0();
    void AddItemToInventory(EquipForm_ctxr*, int, EquipActor_ctxr*, EquipExtra*, bool, bool);
};

struct BoundShell_ctxr : TESBoundObject
{



};

struct ItemShell_ctxr : InventoryStackRecord
{

    ItemShell_ctxr(BoundShell_ctxr*, int);



};

struct ChangesShell_ctxr : InventoryChanges
{


    BoundShell_ctxr* FUN_004bffb0(BoundShell_ctxr*);

    void AddItemExtraData(BoundShell_ctxr*, int, int, ExtraShell*, ExtraNodeShell**);
};

struct W20Form_ctxr;

struct W20Ref_ctxr;

struct W20Entry_ctxr
{
    W20ExtraList* extras;
    int count;
    W20Form_ctxr* form;
    W20Entry_ctxr(W20Form_ctxr*, int);
    ~W20Entry_ctxr();
};

struct W20Form_ctxr : TESBoundObject
{
    int GetWeaponType();
    W20Form_ctxr* GetCurrentAmmo(W20Ref_ctxr*);
};

struct W20Ref_ctxr
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void v48(int);
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual bool v100();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual const char* v130();
};

struct W20Inventory_ctxr
{
    W20EntryList* entries;
    W20Ref_ctxr* owner;
    float weight;
    float previous;
    bool dirty;
    void FUN_004c1c90(W20Ref_ctxr*, int, int, bool);
};

struct AddForm_ctxr;

struct AddProcess_ctxr;

struct AddEntry_ctxr;

struct AddEntry_ctxr
{
    AddNode* extras;
    int count;
    AddForm_ctxr* form;
    AddEntry_ctxr(AddForm_ctxr*, int);
    ~AddEntry_ctxr();
};

struct AddProcess_ctxr
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual AddEntry_ctxr* ammoA();
    virtual AddEntry_ctxr* p();
};

struct AddForm_ctxr
{
};

struct AddInventory_ctxr
{
    AddChanges* changes;
    AddRef* owner;
    float weight, previousWeight;
    bool dirty;
    AddContainer* FUN_004bffb0();
    void FUN_004c29a0(AddForm_ctxr*, AddExtra*, int);
};

struct Inv4c6a10_ctxr
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0_ctxr* FUN_004bffb0();
    TESBoundObject* FindInventoryItemByType(int aType, int* apCount);
};

struct AmmoContainer_ctxr
{
};

struct AmmoInventory_ctxr
{
    ItemList_ctxr* changes;
    AmmoContainer_ctxr* FUN_004bffb0();
    FUN_0076b630_ctxr* FindBestAmmoChange(AmmoScorer*, int);
};

struct Form64_ctxr
{
    int FUN_00446390();
};

struct Change64_ctxr
{
    ExtraNode64* extras;
    int count;
    Form64_ctxr* form;
    Change64_ctxr();
    Change64_ctxr(Form64_ctxr*, int);
};

struct BaseItem64_ctxr
{
    int count;
    Form64_ctxr* form;
};

struct Inventory64_ctxr
{
    ChangeNode64* changes;
    BaseContainer64* FUN_004bffb0();
    Change64_ctxr* FUN_004c94f0(int);
};

struct InventoryForm4ca330_ctxr
{
    int FUN_00446390();
};

struct InventoryRecord4ca330_ctxr
{
    InventoryNode4ca330* m_extraList;
    InventoryForm4ca330_ctxr* m_form;
    unsigned int m_flags;
};

struct InventoryChange4ca330_ctxr
{
    InventoryNode4ca330* m_extraList;
    int m_quantity;
    InventoryForm4ca330_ctxr* m_form;

};

struct InventoryOutput4ca330_ctxr
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330_ctxr* m_form;
    InventoryOutput4ca330_ctxr();
};

struct InventoryOutputFromForm4ca330_ctxr
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330_ctxr* m_form;
    InventoryOutputFromForm4ca330_ctxr(InventoryForm4ca330_ctxr* form, int count);
};

struct InventoryCursor4ca330_ctxr
{
    unsigned int m_uiContentCount;
    InventoryList4ca330* m_firstNode;
    unsigned int m_unknown08;
    InventoryOutput4ca330_ctxr* m_pTileTemplate;
    InventoryContainer4ca330* m_sourceContainer;
    InventoryChangeNode4ca330* m_secondPhase;
    int m_phase;
    InventoryNode4ca330* m_activeExtras;
    InventoryNode4ca330* m_extrasToCount;
    InventoryNode4ca330* m_extrasToCopy;
};

struct Cont4cb320_ctxr
{
};

struct Cont4cb4b0_ctxr
{
};

namespace InventoryCopy {
struct FUN_004bc550_ctxr;
typedef FUN_004bc550_ctxr Item_ctxr;
struct FUN_00410360_ctxr;
typedef FUN_00410360_ctxr Extra_ctxr;
struct ExtraNode_ctxr;
struct BaseNode_ctxr;
struct ItemNode_ctxr;
struct Container_ctxr;
struct Inventory_ctxr;
struct FormView_ctxr
{
    int FUN_00401170();
};
struct CopiedForm_ctxr
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108(TESBoundObject*);
};
struct FUN_00410360_ctxr
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360_ctxr();
};
typedef FUN_00410360_ctxr Extra_ctxr;
struct ExtraNode_ctxr
{
    int FUN_005ae380();
};
struct FUN_004bc550_ctxr
{
    ExtraNode_ctxr* list;
    int count;
    TESBoundObject* form;
    FUN_004bc550_ctxr(TESBoundObject*, int);
};
typedef FUN_004bc550_ctxr Item_ctxr;
struct BaseEntry_ctxr
{
    int count;
    TESBoundObject* form;
};
struct BaseNode_ctxr
{
    bool FUN_008256d0();
};
struct ItemNode_ctxr
{
    bool FUN_008256d0();
};
struct Container_ctxr
{
    BaseNode_ctxr* FUN_00717e50();
};
struct Registry_ctxr
{
};
struct Inventory_ctxr
{
    ItemNode_ctxr* head;
    Container_ctxr* FUN_004bffb0();
    void FUN_004cd9c0(void*, void*);
};
// @fnv 0x004cd9c0
void Inventory_ctxr::FUN_004cd9c0(void* source, void* destination)
{
    if (!destination || !source)
        return;
    TESBoundObject* formSlot11 = 0;
    Item_ctxr* copySlot14 = 0;
    Inventory_ctxr* targetSlot4 = 0;
    targetSlot4 = ((::InventoryCopy::Inventory_ctxr *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(destination))));
    if (!targetSlot4)
        return;
    BaseNode_ctxr* baseSlot45 = ((::InventoryCopy::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    TESLevItem* leveledSlot24 = 0;
    while (baseSlot45 && !baseSlot45->FUN_008256d0())
    {
        formSlot11 = (*((::InventoryCopy::BaseEntry_ctxr **)((void *)(baseSlot45))))->form;
        leveledSlot24 = dynamic_cast<TESLevItem*>((*((::InventoryCopy::BaseEntry_ctxr **)((void *)(baseSlot45))))->form);
        if (formSlot11)
        {
            int baseCountSlot31 = reinterpret_cast<::TESContainer *>((((::InventoryCopy::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(formSlot11));
            Item_ctxr* itemSlot25 = ((::InventoryCopy::FUN_004bc550_ctxr *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(formSlot11, 1, 0)));
            int totalSlot2 = 0;
            int magnitudeSlot60 = baseCountSlot31;
            if (magnitudeSlot60 < 0)
                magnitudeSlot60 *= -1;
            if (itemSlot25)
                totalSlot2 += magnitudeSlot60 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemSlot25))->FUN_00726070()));
            else
                totalSlot2 += magnitudeSlot60;
            if (totalSlot2 > 0)
            {
                CopiedForm_ctxr* clone = 0;
                if (((void *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(formSlot11)))))
                {
                    clone = ((::InventoryCopy::CopiedForm_ctxr *)(::TESDataHandler::CreateFormForType(((FormView_ctxr*)formSlot11)->FUN_00401170())));
                    clone->v108(formSlot11);
                    ::FUN_004ce300((::TESForm *)(clone), 0);
                    reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::InventoryCopy::Registry_ctxr * *>(&::g_dataHandler))))->AddFormToDataHandler((::TESForm *)(clone));
                    reinterpret_cast<::fnv_00861780::FUN_00861780_StandIn *>(((*reinterpret_cast<::InventoryCopy::Registry_ctxr * *>(&::g_TESSaveLoadGame))))->Add((::TESForm *)(clone));
                    int quantity = baseCountSlot31;
                    if (itemSlot25)
                        quantity += ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((itemSlot25))->FUN_00726070()));
                    copySlot14 = new Item_ctxr((TESBoundObject*)clone, quantity);

                    if (itemSlot25 && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(itemSlot25)))) && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(itemSlot25))))->FUN_005ae380())
                    {
                        ExtraNode_ctxr* nodeA = ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(itemSlot25))));
                        if (nodeA && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeA))))
                        {
                            while (nodeA && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeA))))
                            {
                                Extra_ctxr* extraASlot11 = new Extra_ctxr;
                                void* removedASlot21 = ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(((*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeA))))))->FUN_00410220(0xd)));
                                if (removedASlot21)
                                    reinterpret_cast<::FUN_00410020_t *>(((*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeA))))))->FUN_00410020((::BSExtraData *)(removedASlot21), 0);
                                reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraASlot11))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeA)))), 1);
                                reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraASlot11);
                                if (removedASlot21)
                                    reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(((*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeA))))))->FUN_0040ff60((::BSExtraData *)(removedASlot21));
                                nodeA = ((::InventoryCopy::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((nodeA))->FUN_00726070()));
                            }
                        }
                    }
                }
                else
                {
                    copySlot14 = new Item_ctxr(formSlot11, totalSlot2);
                    if (itemSlot25 && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(itemSlot25)))) && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(itemSlot25))))->FUN_005ae380())
                    {
                        ExtraNode_ctxr* nodeB = ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(itemSlot25))));
                        if (nodeB && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeB))))
                        {
                            while (nodeB && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeB))))
                            {
                                Extra_ctxr* extraB = new Extra_ctxr;
                                reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraB))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeB)))), 1);
                                reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraB);
                                nodeB = ((::InventoryCopy::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
                            }
                        }
                    }
                }
                reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((targetSlot4))->FUN_004c3380((::InventoryStackRecord *)(copySlot14), 1);
            }
        }
        baseSlot45 = ((::InventoryCopy::BaseNode_ctxr *)(reinterpret_cast<::Callees *>((baseSlot45))->FUN_00726070()));
    }
    Item_ctxr* changedSlot20 = 0;
    ItemNode_ctxr* nodeSlot26 = head;
    while (nodeSlot26 && !nodeSlot26->FUN_008256d0())
    {
        changedSlot20 = *((::InventoryCopy::FUN_004bc550_ctxr **)((void *)(nodeSlot26)));
        if (changedSlot20 && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changedSlot20))->FUN_00726070())) > 0)
        {
            formSlot11 = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName()));
            reinterpret_cast<::AGOwner *>((changedSlot20))->FUN_004bcd10();
            CopiedForm_ctxr* clone2 = 0;
            if (((void *)(reinterpret_cast<::FUN_004bde40_shell *>((changedSlot20))->FUN_004bde40())))
            {
                clone2 = ((::InventoryCopy::CopiedForm_ctxr *)(::TESDataHandler::CreateFormForType(((FormView_ctxr*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName())))->FUN_00401170())));
                clone2->v108(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName())));
                ::FUN_004ce300((::TESForm *)(clone2), 0);
                reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::InventoryCopy::Registry_ctxr * *>(&::g_dataHandler))))->AddFormToDataHandler((::TESForm *)(clone2));
                reinterpret_cast<::fnv_00861780::FUN_00861780_StandIn *>(((*reinterpret_cast<::InventoryCopy::Registry_ctxr * *>(&::g_TESSaveLoadGame))))->Add((::TESForm *)(clone2));
                copySlot14 = new Item_ctxr((TESBoundObject*)clone2, ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changedSlot20))->FUN_00726070())));
                if (changedSlot20 && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(changedSlot20)))) && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(changedSlot20))))->FUN_005ae380())
                {
                    ExtraNode_ctxr* nodeC = ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(changedSlot20))));
                    if (nodeC && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeC))))
                    {
                        while (nodeC && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeC))))
                        {
                            Extra_ctxr* extraCSlot22 = new Extra_ctxr;
                            void* removedCSlot8 = ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(((*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeC))))))->FUN_00410220(0xd)));
                            if (removedCSlot8)
                                reinterpret_cast<::FUN_00410020_t *>(((*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeC))))))->FUN_00410020((::BSExtraData *)(removedCSlot8), 0);
                            reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraCSlot22))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeC)))), 1);
                            reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraCSlot22);
                            if (removedCSlot8)
                                reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(((*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeC))))))->FUN_0040ff60((::BSExtraData *)(removedCSlot8));
                            nodeC = ((::InventoryCopy::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((nodeC))->FUN_00726070()));
                        }
                    }
                }
            }
            else
            {
                copySlot14 = new Item_ctxr(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((changedSlot20))->GetName())), ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changedSlot20))->FUN_00726070())));
                if (changedSlot20 && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(changedSlot20)))) && ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(changedSlot20))))->FUN_005ae380())
                {
                    ExtraNode_ctxr* nodeD = ((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(changedSlot20))));
                    if (nodeD && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeD))))
                    {
                        while (nodeD && *((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeD))))
                        {
                            Extra_ctxr* extraD = new Extra_ctxr;
                            reinterpret_cast<::fnv_004121e0::ExtraDataListCopyListForContainer *>((extraD))->FUN_004121e0((::ExtraDataList *)(*((::InventoryCopy::FUN_00410360_ctxr **)((void *)(nodeD)))), 1);
                            reinterpret_cast<::Callees *>((((::InventoryCopy::ExtraNode_ctxr *)(::FUN_00559450((int *)(copySlot14))))))->FUN_00905820(&extraD);
                            nodeD = ((::InventoryCopy::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((nodeD))->FUN_00726070()));
                        }
                    }
                }
            }
            reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((targetSlot4))->FUN_004c3380((::InventoryStackRecord *)(copySlot14), 1);
            copySlot14 = 0;
        }
        nodeSlot26 = ((::InventoryCopy::ItemNode_ctxr *)(reinterpret_cast<::Callees *>((nodeSlot26))->FUN_00726070()));
    }
}
}

struct MoveContainer_ctxr
{
};

struct InventoryMove_ctxr
{
    MoveItemNode* head;
    MoveContainer_ctxr* FUN_004bffb0();
    float FUN_004ce380(MoveOwner*, MoveOwner*, bool, bool, bool, bool, int, MoveFilter*);
};

struct WeightContainer_ctxr
{
};

struct WeightInventory_ctxr : InventoryChanges
{
    WeightContainer_ctxr* FUN_004bffb0();
    float FUN_004d0900(bool useAmmoWeight);
};

struct ValueForm_ctxr : TESForm
{
};

struct ValueBaseEntry_ctxr
{
    int count;
    ValueForm_ctxr* object;
};

struct ValueContainer_ctxr
{
};

struct ValueInventory_ctxr : InventoryChanges
{
    ValueContainer_ctxr* FUN_004bffb0();
    int FUN_004d0f40(bool includeQuestItems, bool includeType15);
};

struct Cont4d1440_ctxr
{
};

int __cdecl FUN_00ec7d40(int);

struct Inv4d1440_ctxr : public InventoryChanges
{
    Cont4d1440_ctxr* FUN_004bffb0();
    bool HasExtraDataWithValue(int);
    void FUN_004d1440();
};

namespace InventoryTransfer {
struct Extra_ctxr;
struct ExtraNode_ctxr;
struct Item_ctxr;
struct Inventory_ctxr;
struct AutoMemContext_ctxr
{
    int context;
    AutoMemContext_ctxr(int, bool, const char*, int);
    ~AutoMemContext_ctxr();
};
struct Form_ctxr
{

    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual bool v094();
};
struct Extra_ctxr
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Extra_ctxr();
};
struct ExtraNode_ctxr
{
    Extra_ctxr* value;
    ExtraNode_ctxr* next;
    ExtraNode_ctxr();
    void FUN_005ae3d0(Extra_ctxr**);
};
struct Item_ctxr
{
    ExtraNode_ctxr* list;
    int count;
    TESBoundObject* form;
    Item_ctxr();
    ~Item_ctxr();
};
struct BaseEntry_ctxr
{
    int count;
    TESBoundObject* form;
};
struct BaseNode_ctxr
{
};
struct ItemNode_ctxr
{
};
struct Container_ctxr
{
    BaseNode_ctxr* FUN_00717e50();
};
struct Inventory_ctxr
{
    ItemNode_ctxr* head;
    Container_ctxr* FUN_004bffb0();
    void FUN_004d26d0(Inventory_ctxr*, void*, bool);
};
// @fnv 0x004d26d0
void Inventory_ctxr::FUN_004d26d0(Inventory_ctxr* target, void* owner, bool exclude)
{
    AutoMemContext_ctxr contextSlot2(0x36, true, ::DAT_01020778, 0x26b7);
    BaseNode_ctxr* baseSlot2 = ((::InventoryTransfer::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
    Item_ctxr* transferSlot3 = 0;
    while (baseSlot2 && *((::InventoryTransfer::BaseEntry_ctxr **)((void *)(baseSlot2))))
    {
        BaseEntry_ctxr* entrySlot7 = *((::InventoryTransfer::BaseEntry_ctxr **)((void *)(baseSlot2)));
        TESLevItem* leveledSlot21 = dynamic_cast<TESLevItem*>(entrySlot7->form);
        transferSlot3 = new Item_ctxr;
        int baseCountSlot38 = reinterpret_cast<::TESContainer *>((((::InventoryTransfer::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(entrySlot7->form));
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode_ctxr;
        if (entrySlot7 && !leveledSlot21)
        {
            Item_ctxr* current = ((::InventoryTransfer::Item_ctxr *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0(entrySlot7->form, 1, 0)));
            if (current)
                reinterpret_cast<::FUN_004bcbd0_Class *>((current))->ProcessNodes();
            if (entrySlot7 && current &&
                (((!reinterpret_cast<::InventoryStackRecord *>((current))->HasPerkEntry() || reinterpret_cast<::FUN_004bcc30_List *>((current))->FUN_004bcc30() < 1) && current->count + baseCountSlot38 == 0) ||
                 (((::InventoryTransfer::Form_ctxr *)(reinterpret_cast<::Twin_0044ddc0 *>((current))->GetName()))->v094() && exclude) || reinterpret_cast<::FUN_004bddd0_shell *>((current))->FUN_004bddd0(0)))
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
            else if (entrySlot7 && (!current || (current && !reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0))))
            {
                int magnitude = baseCountSlot38;
                if (magnitude < 0)
                    magnitude *= -1;
                if (current)
                    transferSlot3->count = magnitude + current->count - reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0);
                else
                    transferSlot3->count = magnitude;
                reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(entrySlot7->form));
                if (current && ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((current))->FUN_004bde40())))
                {
                    ExtraNode_ctxr* scripted = ((::InventoryTransfer::ExtraNode_ctxr *)(::FUN_00559450((int *)(current))));
                    while (scripted && *((::InventoryTransfer::Extra_ctxr **)((void *)(scripted))))
                    {
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>(((*((::InventoryTransfer::Extra_ctxr **)((void *)(scripted))))))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::Callees *>((transferSlot3->list))->FUN_00905820(((::InventoryTransfer::Extra_ctxr **)((void *)(scripted))));
                        scripted = ((::InventoryTransfer::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((scripted))->FUN_00726070()));
                    }
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                }
                else
                {
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    {
                        Extra_ctxr* extraA = new Extra_ctxr;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraA))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraA))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferSlot3))->FUN_00726070())));
                        transferSlot3->list->FUN_005ae3d0(&extraA);
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else if (current)
            {
                int extraCountSlot33 = 0;
                if (current->list)
                    extraCountSlot33 = reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0);
                ExtraNode_ctxr* extrasSlot23 = current->list;
                while (extrasSlot23 && *((::InventoryTransfer::Extra_ctxr **)((void *)(extrasSlot23))) && !transferSlot3)
                {
                    Extra_ctxr* extraB = *((::InventoryTransfer::Extra_ctxr **)((void *)(extrasSlot23)));
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(current->form));
                    reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(std::uintptr_t)(reinterpret_cast<::FUN_00418770_shell *>((extraB))->FUN_00418770()));
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode_ctxr;
                    reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraB))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                    transferSlot3->list->FUN_005ae3d0(&extraB);
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    extrasSlot23 = ((::InventoryTransfer::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((extrasSlot23))->FUN_00726070()));
                }
                if (reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0) < baseCountSlot38 + current->count)
                {
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode_ctxr;
                    if (current)
                        transferSlot3->count = baseCountSlot38 + current->count - reinterpret_cast<::FUN_004bc8f0_stand *>((current))->FUN_004bc8f0(0);
                    else
                        transferSlot3->count = baseCountSlot38;
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(entrySlot7->form));
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    {
                        Extra_ctxr* extraC = new Extra_ctxr;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraC))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraC))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferSlot3))->FUN_00726070())));
                        transferSlot3->list->FUN_005ae3d0(&extraC);
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        baseSlot2 = ((::InventoryTransfer::BaseNode_ctxr *)(reinterpret_cast<::Callees *>((baseSlot2))->FUN_00726070()));
    }
    ItemNode_ctxr* nodeSlot1 = head;
    while (nodeSlot1 && *((::InventoryTransfer::Item_ctxr **)((void *)(nodeSlot1))))
    {
        transferSlot3 = new Item_ctxr;
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode_ctxr;
        Item_ctxr* changed = *((::InventoryTransfer::Item_ctxr **)((void *)(nodeSlot1)));
        if (changed && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())) > 0 && (!((::InventoryTransfer::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0())) || !reinterpret_cast<::TESContainer *>((((::InventoryTransfer::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->HasObjectOfType((::TESObject *)(changed->form))))
        {
            if (reinterpret_cast<::FUN_004bc8f0_stand *>((changed))->FUN_004bc8f0(0) || ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((changed))->FUN_004bde40())))
            {
                ExtraNode_ctxr* walkSlot1 = changed->list;
                int countSlot56 = 0;
                bool hasSpecialSlot4 = false;
                while (walkSlot1 && *((::InventoryTransfer::Extra_ctxr **)((void *)(walkSlot1))))
                {
                    if (((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(((*((::InventoryTransfer::Extra_ctxr **)((void *)(walkSlot1))))))->FUN_00410220(0x2f))))
                        hasSpecialSlot4 = true;
                    walkSlot1 = ((::InventoryTransfer::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((walkSlot1))->FUN_00726070()));
                }
                walkSlot1 = changed->list;
                if (!hasSpecialSlot4 || ((int)(reinterpret_cast<::FUN_004be1a0_Class *>((changed))->GetFormTypeCategory())) != 4)
                {
                    while (walkSlot1 && *((::InventoryTransfer::Extra_ctxr **)((void *)(walkSlot1))))
                    {
                        Extra_ctxr* extraD = *((::InventoryTransfer::Extra_ctxr **)((void *)(walkSlot1)));
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraD))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        transferSlot3->list->FUN_005ae3d0(&extraD);
                        walkSlot1 = ((::InventoryTransfer::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((walkSlot1))->FUN_00726070()));
                        countSlot56 += reinterpret_cast<::FUN_00418770_shell *>((extraD))->FUN_00418770();
                    }
                }
                else
                {
                    if (((int)(reinterpret_cast<::FUN_004be1a0_Class *>((changed))->GetFormTypeCategory())) == 4 && ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((changed))->FUN_004bde40())))
                        reinterpret_cast<::CombatProcedure *>((changed))->Initialize((::CombatController *)(1));
                    while (walkSlot1 && *((::InventoryTransfer::Extra_ctxr **)((void *)(walkSlot1))))
                    {
                        Extra_ctxr* extraE = *((::InventoryTransfer::Extra_ctxr **)((void *)(walkSlot1)));
                        reinterpret_cast<::FUN_0041af10_Class *>((extraE))->RemoveExtra24();
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraE))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        transferSlot3->list->FUN_005ae3d0(&extraE);
                        walkSlot1 = ((::InventoryTransfer::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((walkSlot1))->FUN_00726070()));
                        countSlot56 = 1;
                    }
                }
                reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(changed->form));
                reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0) && countSlot56 < ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())))
                {
                    Extra_ctxr* extraF = new Extra_ctxr;
                    reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraF))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                    reinterpret_cast<::FUN_00419ad0_shell *>((extraF))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())) - countSlot56);
                    transferSlot3->list->FUN_005ae3d0(&extraF);
                }
                if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                else
                {
                    if (*((::InventoryTransfer::Extra_ctxr **)((void *)(transferSlot3->list))))
                        reinterpret_cast<::FUN_00418600_cls *>(((*((::InventoryTransfer::Extra_ctxr **)((void *)(transferSlot3->list))))))->FUN_00418600();
                    delete transferSlot3;
                    transferSlot3 = 0;
                }
            }
            else
            {
                Extra_ctxr* chosen = 0;
                if (changed->list)
                {
                    ExtraNode_ctxr* walk2Slot3 = changed->list;
                    int count2Slot41 = 0;
                    while (walk2Slot3 && *((::InventoryTransfer::Extra_ctxr **)((void *)(walk2Slot3))) && !chosen)
                    {
                        chosen = *((::InventoryTransfer::Extra_ctxr **)((void *)(walk2Slot3)));
                        count2Slot41 += reinterpret_cast<::FUN_00418770_shell *>((chosen))->FUN_00418770();
                        if (reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((chosen))->HasOnlyAllowedExtraData(0))
                            chosen = 0;
                        walk2Slot3 = ((::InventoryTransfer::ExtraNode_ctxr *)(reinterpret_cast<::Callees *>((walk2Slot3))->FUN_00726070()));
                    }
                    if (chosen)
                    {
                        if (!transferSlot3->list)
                            transferSlot3->list = new ExtraNode_ctxr;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((chosen))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        transferSlot3->list->FUN_005ae3d0(&chosen);
                        if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0) && count2Slot41 < ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())))
                        {
                            Extra_ctxr* extraG = new Extra_ctxr;
                            reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraG))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                            reinterpret_cast<::FUN_00419ad0_shell *>((extraG))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())) - count2Slot41);
                            transferSlot3->list->FUN_005ae3d0(&extraG);
                        }
                    }
                    else
                    {
                        Extra_ctxr* extraH = new Extra_ctxr;
                        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extraH))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                        reinterpret_cast<::FUN_00419ad0_shell *>((extraH))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((changed))->FUN_00726070())));
                        transferSlot3->list->FUN_005ae3d0(&extraH);
                    }
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(changed->form));
                    reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                    if (!reinterpret_cast<::FUN_004bddd0_shell *>((transferSlot3))->FUN_004bddd0(0))
                    {
                        reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                        reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                    }
                    else
                    {
                        if (*((::InventoryTransfer::Extra_ctxr **)((void *)(transferSlot3->list))))
                            reinterpret_cast<::FUN_00418600_cls *>(((*((::InventoryTransfer::Extra_ctxr **)((void *)(transferSlot3->list))))))->FUN_00418600();
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
                else
                {
                    reinterpret_cast<::TESRegionGrassObject *>((transferSlot3))->AssignLandTexture((::TESLandTexture *)(::InventoryTransfer::Form_ctxr *)(((::InventoryTransfer::Form_ctxr *)(reinterpret_cast<::Twin_0044ddc0 *>((changed))->GetName()))));
                    reinterpret_cast<::CombatProcedure *>((transferSlot3))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>((changed))->FUN_00726070()))));
                    chosen = new Extra_ctxr;
                    reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((chosen))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(owner));
                    reinterpret_cast<::FUN_00419ad0_shell *>((chosen))->FUN_00419ad0(((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((transferSlot3))->FUN_00726070())));
                    transferSlot3->list->FUN_005ae3d0(&chosen);
                    reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((target))->FUN_004c3380((::InventoryStackRecord *)(transferSlot3), 1);
                }
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        nodeSlot1 = ((::InventoryTransfer::ItemNode_ctxr *)(reinterpret_cast<::Callees *>((nodeSlot1))->FUN_00726070()));
    }
}
}

struct SaveBuffer_4d4090_ctxr
{
    virtual TESIdleForm* GetSpeakerIdle();
};

struct InvChangesSave_ctxr : InventoryChanges
{
    void FUN_004d4090(SaveBuffer_4d4090_ctxr* buffer);
};

struct WalkForm_ctxr
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual bool excluded();
};

struct WalkBaseEntry_ctxr
{
    int count;
    WalkForm_ctxr* form;
};

struct WalkContainer_ctxr
{
};

struct WalkTemp_ctxr
{
    void* extra;
    int count;
    WalkForm_ctxr* form;
    WalkTemp_ctxr();
    ~WalkTemp_ctxr();
};

struct WalkInventory_ctxr
{
    WalkNode* first;
    WalkContainer_ctxr* FUN_004bffb0();
    int ForEachInventoryItem(bool(__cdecl* callback)(WalkTemp_ctxr*, void*), void* context, int flags);
};

struct IterForm_ctxr
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual bool IsFiltered();
};

struct BaseEntryIter_ctxr
{
    int count;
    IterForm_ctxr* form;
};

struct IterContainer_ctxr
{
};

struct InventoryIterOwner_ctxr
{
    ChangeNodeIter* changes;
    IterContainer_ctxr* FUN_004bffb0();
    bool AdvanceInventoryIterator(IterState*, void**, int);
};

struct Transfer4c37AuxObj_ctxr
{
};

struct LoadBuffer4160_ctxr
{
    virtual void Slot0();
    virtual int GetVersion();
};

struct Item4160_ctxr : FUN_0076b630_ctxr
{
};

struct Inventory4160_ctxr
{
    ChangeList4160* changes;
    void FUN_004d4160(LoadBuffer4160_ctxr* buffer);
};

struct FUN_0076b630_ex_ctxr : public FUN_0076b630_ctxr
{
};

struct CContainerC5_ctxr
{
};

struct CTargetC5_ctxr
{
    ENodeC5* m_pFirstNode;
    CContainerC5_ctxr* FUN_004bffb0();
    void* FUN_004cafe0();
};

struct Cont6_ctxr
{
};

namespace Rebuild004d0650 {
struct Object_ctxr
{
};
struct Extra_ctxr
{
};
struct FUN_0096a2d0_ctxr
{
    char data[8];
    FUN_0096a2d0_ctxr();
    ~FUN_0096a2d0_ctxr();
    unsigned FUN_005ae380();
    void FUN_005ae3d0(Extra_ctxr**);
    void* FUN_004702f0(unsigned);
};
struct FUN_004bc550_ctxr
{
    FUN_0096a2d0_ctxr* list;
    int count;
    Object_ctxr* form;
    FUN_004bc550_ctxr(Object_ctxr*, int);
};
struct Entry_ctxr
{
    int count;
    Object_ctxr* form;
};
struct Node_ctxr
{
    bool FUN_008256d0();
};
struct Container_ctxr
{
    Node_ctxr* FUN_00717e50();
};
struct Inventory_ctxr
{
    Container_ctxr* FUN_004bffb0();
    FUN_004bc550_ctxr* FUN_004d0650(Object_ctxr*, int);
};
// @fnv 0x004d0650
FUN_004bc550_ctxr* Inventory_ctxr::FUN_004d0650(Object_ctxr* object, int arg)
{
    FUN_004bc550_ctxr* source3 = ((::Rebuild004d0650::FUN_004bc550_ctxr *)(reinterpret_cast<::FUN_004bfba0_shell *>(this)->FUN_004bfba0((::TESBoundObject *)(object), 1, arg)));
    FUN_004bc550_ctxr* result2 = 0;
    if (source3)
    {
        int count2 = reinterpret_cast<::TESContainer *>((((::Rebuild004d0650::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))))->GetObjectCount((::TESObject *)(object));
        result2 = new FUN_004bc550_ctxr(object, count2 + ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((source3))->FUN_00726070())));
        if (((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(::FUN_00559450((int *)(source3)))) && ((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(::FUN_00559450((int *)(source3))))->FUN_005ae380())
        {
            if (!((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(::FUN_00559450((int *)(result2)))))
                result2->list = new FUN_0096a2d0_ctxr;
            Extra_ctxr* extra7 = *((::Rebuild004d0650::Extra_ctxr **)((void *)(((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(::FUN_00559450((int *)(source3)))))));
            if (reinterpret_cast<::fnv_0041d120::FUN_0041d120_shell *>((extra7))->HasOnlyAllowedExtraData(0))
            {
                FUN_0096a2d0_ctxr* node5 = ((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(::FUN_00559450((int *)(source3))));
                while (node5 && *((::Rebuild004d0650::Extra_ctxr **)((void *)(node5))))
                {
                    extra7 = *((::Rebuild004d0650::Extra_ctxr **)((void *)(node5)));
                    reinterpret_cast<::Callees *>((result2->list))->FUN_00905820((void *)&(extra7));
                    node5 = ((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                }
            }
            else
            {
                result2->list->FUN_005ae3d0(&extra7);
            }
        }
        else
        {
            if (((::Rebuild004d0650::FUN_0096a2d0_ctxr *)(::FUN_00559450((int *)(result2)))))
            {
                delete result2->list;
                result2->list = 0;
            }
        }
    }
    else
    {
        Node_ctxr* base6 = ((::Rebuild004d0650::Container_ctxr *)(reinterpret_cast<::FUN_004bffb0_shell *>(this)->FUN_004bffb0()))->FUN_00717e50();
        Object_ctxr* form2 = 0;
        while (base6 && !base6->FUN_008256d0())
        {
            form2 = (*((::Rebuild004d0650::Entry_ctxr **)((void *)(base6))))->form;
            if (form2 == object)
            {
                result2 = new FUN_004bc550_ctxr(object, (*((::Rebuild004d0650::Entry_ctxr **)((void *)(base6))))->count);
                break;
            }
            base6 = ((::Rebuild004d0650::Node_ctxr *)(reinterpret_cast<::Callees *>((base6))->FUN_00726070()));
        }
    }
    return result2;
}
}

extern const char DAT_010207c0[];

struct MoveActorExt : MoveOwner
{
};

struct InventoryMoveTarget : InventoryMove_ctxr
{
    void FUN_004cb5f0(MoveOwner*, MoveOwner*, MoveForm*);
};

// @fnv 0x004cb5f0
void InventoryMoveTarget::FUN_004cb5f0(MoveOwner* source, MoveOwner* destination, MoveForm* onlyForm)
{
    MoveItem* item = 0;
    TESBoundObject* form = 0;
    MoveItemNode* itemNode = head;
    while (itemNode && !itemNode->FUN_008256d0())
    {

        MoveItemNode* savedItemNext = ((::MoveItemNode *)(reinterpret_cast<::Callees *>((itemNode))->FUN_00726070()));
        item = *((::MoveItem **)((void *)(itemNode)));
        bool restartItems = false;

        if (item && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((item))->FUN_00726070())) > 0 && !((MoveForm*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName())))->IsQuestItem())
        {
            MoveExtraNode* pExtra = ((::MoveExtraNode *)(::FUN_00559450((int *)(item))));
            form = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()));
            MoveOwner* actor = 0;
            if (destination->IsActor())
                actor = destination;
            if (pExtra && *((::MoveExtra **)((void *)(pExtra))))
            {
                while (pExtra && *((::MoveExtra **)((void *)(pExtra))) && !restartItems)
                {
                    MoveExtraNode* savedExtraNext2 = ((::MoveExtraNode *)(reinterpret_cast<::Callees *>((pExtra))->FUN_00726070()));
                    MoveExtra* extra = *((::MoveExtra **)((void *)(pExtra)));
                    bool restartExtras = false;
                    MoveForm* original4 = (MoveForm*)((void *)(reinterpret_cast<::FUN_00418660_shell *>((extra))->FUN_00418660()));
                    MoveForm* baseExtraA = 0;
                    MoveForm* modExtra_2 = 0;
                    if (original4)
                    {
                        if (original4->FUN_00401170() == 8)
                            modExtra_2 = original4;
                        else
                            baseExtraA = original4;
                    }

                    if (!onlyForm || onlyForm == (MoveForm*)((void *)(reinterpret_cast<::FUN_00418660_shell *>((extra))->FUN_00418660())))
                    {
                        if (actor && !onlyForm)
                            onlyForm = (MoveForm*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430()));
                        if (((void *)(reinterpret_cast<::FUN_00418660_shell *>((extra))->FUN_00418660())) && (MoveForm*)((void *)(reinterpret_cast<::FUN_00418660_shell *>((extra))->FUN_00418660())) != (MoveForm*)source &&
                            (!actor || ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430())) == baseExtraA ||
                             reinterpret_cast<::fnv_008b8e90::FUN_008b8e90_shell *>((((MoveActorExt*)actor)))->FUN_008b8e90((::fnv_008b8e90::TESFaction *)(modExtra_2))))
                        {

                            if (((::MoveExtraNode *)(::FUN_00559450((int *)(item))))->FUN_005ae380() <= 1)
                                restartItems = true;
                            else
                                restartExtras = true;

                            if (onlyForm)
                            {
                                MoveString formattedItem;
                                int copies = reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770();
                                if (copies > 1)
                                {
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&formattedItem), DAT_0101c178, copies, ::FUN_00482720((::TESForm *)(form)),
                                                 (*reinterpret_cast<::MoveSetting *>(&::g_011d3114)).FUN_00403df0(),
                                                 (*reinterpret_cast<::MoveSetting *>(&::g_011d3db4)).FUN_00403df0());
                                }
                                else
                                {
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::MoveString *)(&formattedItem), DAT_01012058, ::FUN_00482720((::TESForm *)(form)),
                                                 (*reinterpret_cast<::MoveSetting *>(&::g_011d3db4)).FUN_00403df0());
                                }
                                char message4[260];
                                ::FUN_00406d00(message4, 260, (*reinterpret_cast<const char (*)[]>(&::fnv_004965d0::DAT_0101dcc4)), DAT_010207c0,
                                             ::FUN_0048e730((::TESForm *)(form), (std::intptr_t)((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer)))));
                                ::DispatchMessageToSink((const char *)(((const char *)(::FUN_00559450((int *)&(formattedItem))))), 0, (const char *)(::g_011cba4c_arg1),
                                                      ((const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::MoveOwner * *>(&::_g_thePlayer))))->FUN_008adcf0(form, false, false))), DAT_010162c0,
                                                      0);
                            }
                            reinterpret_cast<::Transfer4c37C37This *>(this)->FUN_004c37d0((::Transfer4c37C37Obj *)(source), (int)(form), false, reinterpret_cast<::FUN_00418770_shell *>((extra))->FUN_00418770(), (::Transfer4c37Form4 *)(extra), 0, (::Transfer4c37C37Form *)(destination), 0, 0, true,
                                         0, (::Transfer4c37Entry *)(::MoveItem *)(0));
                            itemNode = head;
                        }
                    }

                    if (restartItems)
                    {
                        itemNode = head;
                        pExtra = 0;
                    }
                    else if (restartExtras)
                    {
                        pExtra = ((::MoveExtraNode *)(::FUN_00559450((int *)(item))));
                    }
                    else
                    {
                        if (savedExtraNext2 != ((::MoveExtraNode *)(reinterpret_cast<::Callees *>((pExtra))->FUN_00726070())))
                            pExtra = ((::MoveExtraNode *)(::FUN_00559450((int *)(item))));
                        else
                            pExtra = savedExtraNext2;
                        if (!pExtra)
                        {
                            if (savedItemNext != ((::MoveItemNode *)(reinterpret_cast<::Callees *>((itemNode))->FUN_00726070())))
                                itemNode = head;
                            else
                                itemNode = savedItemNext;
                        }
                    }
                }
            }
            else
            {
                if (savedItemNext != ((::MoveItemNode *)(reinterpret_cast<::Callees *>((itemNode))->FUN_00726070())))
                    itemNode = head;
                else
                    itemNode = savedItemNext;
            }
        }
        else
        {
            if (savedItemNext != ((::MoveItemNode *)(reinterpret_cast<::Callees *>((itemNode))->FUN_00726070())))
                itemNode = head;
            else
                itemNode = savedItemNext;
        }
    }
}

#include "generated/data/fallout_shared/inventorychanges.inc"
#include "generated/data/fallout_shared/inventorychanges_ctxr_variant.inc"
