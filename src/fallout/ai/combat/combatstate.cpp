// fallout/ai/combat/combatstate.cpp: CombatState, Host, Holder, NavMeshSearchLOSArray and more (141 functions)

#include <new>
#include "fnv/decl/ActionOwner.h"
#include "fnv/decl/ActorAvoidanceDataArray.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/B989700List.h"
#include "fnv/decl/BGSSaveGameBuffer.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Collection.h"
#include "fnv/decl/CombatActionStandIn.h"
#include "fnv/decl/CombatAssessment__Group.h"
#include "fnv/decl/CombatDialogueHandler.h"
#include "fnv/decl/CombatFlagHolder.h"
#include "fnv/decl/CombatPlan.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/CombatWeapon.h"
#include "fnv/decl/DistanceCheck.h"
#include "fnv/decl/Dummy00981520.h"
#include "fnv/decl/E9A3A80Allocator.h"
#include "fnv/decl/EffectList405c.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_004186f0_shell.h"
#include "fnv/decl/FUN_00418b10_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_0042eb40_shell.h"
#include "fnv/decl/FUN_00435de0_ctor.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043a3c0.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_00453700_shell.h"
#include "fnv/decl/FUN_0046e8c0_class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004c7300_shell.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_004f9bf0_shell.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_00507b00Class.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_00527ac0_shell.h"
#include "fnv/decl/FUN_00527b70_shell.h"
#include "fnv/decl/FUN_00527ba0_This.h"
#include "fnv/decl/FUN_005407b0_Class.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_0067a700_shell.h"
#include "fnv/decl/FUN_006b3160_shell.h"
#include "fnv/decl/FUN_006cee30_Class.h"
#include "fnv/decl/FUN_006d30e0_Class.h"
#include "fnv/decl/FUN_006d3120_Class.h"
#include "fnv/decl/FUN_006d33a0_Class.h"
#include "fnv/decl/FUN_006d3ac0_Class.h"
#include "fnv/decl/FUN_006dad40_Class.h"
#include "fnv/decl/FUN_006dbfc0_Class.h"
#include "fnv/decl/FUN_006e4320_Class.h"
#include "fnv/decl/FUN_006e4340_Class.h"
#include "fnv/decl/FUN_006e4380_Class.h"
#include "fnv/decl/FUN_006e43a0_class.h"
#include "fnv/decl/FUN_006e43c0_class.h"
#include "fnv/decl/FUN_006e43e0_class.h"
#include "fnv/decl/FUN_006e4430_class.h"
#include "fnv/decl/FUN_006e4650_class.h"
#include "fnv/decl/FUN_006e4ef0_shell.h"
#include "fnv/decl/FUN_006e4f10_class.h"
#include "fnv/decl/FUN_006e4f90_shell.h"
#include "fnv/decl/FUN_006e4fb0_shell.h"
#include "fnv/decl/FUN_006e5ee0_Class.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_0072ba80_shell.h"
#include "fnv/decl/FUN_00844160_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008846c0_shell.h"
#include "fnv/decl/FUN_00894900_shell.h"
#include "fnv/decl/FUN_008be220_cls.h"
#include "fnv/decl/FUN_008d7f40_shell.h"
#include "fnv/decl/FUN_008eeaa0Class.h"
#include "fnv/decl/FUN_008f6630_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00968630_stub.h"
#include "fnv/decl/FUN_0097ede0_cls.h"
#include "fnv/decl/FUN_0097f200_t.h"
#include "fnv/decl/FUN_0097f220_Class.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_0097fd40_shell.h"
#include "fnv/decl/FUN_00980070_shell.h"
#include "fnv/decl/FUN_00980700_shell.h"
#include "fnv/decl/FUN_00981300_shell.h"
#include "fnv/decl/FUN_00981970_shell.h"
#include "fnv/decl/FUN_00982be0_cls.h"
#include "fnv/decl/FUN_00982ca0_Class.h"
#include "fnv/decl/FUN_009835d0_cls.h"
#include "fnv/decl/FUN_00986a80_shell.h"
#include "fnv/decl/FUN_0098cb30_cls.h"
#include "fnv/decl/FUN_0098de00_class.h"
#include "fnv/decl/FUN_0098f1f0_Class.h"
#include "fnv/decl/FUN_00990890_shell.h"
#include "fnv/decl/FUN_00995890_shell.h"
#include "fnv/decl/FUN_00995980_class.h"
#include "fnv/decl/FUN_009959c0Class.h"
#include "fnv/decl/FUN_009962f0_s.h"
#include "fnv/decl/FUN_009973a0_class.h"
#include "fnv/decl/FUN_009a0240_shell.h"
#include "fnv/decl/FUN_009a03d0_cls.h"
#include "fnv/decl/FUN_009a0510_shell.h"
#include "fnv/decl/FUN_009a1260_Class.h"
#include "fnv/decl/FUN_009a1380_cls.h"
#include "fnv/decl/FUN_009a3950_Class.h"
#include "fnv/decl/FUN_009a39f0_class.h"
#include "fnv/decl/FUN_009a3bc0_class.h"
#include "fnv/decl/FUN_009a3c50_cls.h"
#include "fnv/decl/FUN_009a5eb0_shell.h"
#include "fnv/decl/FakeHolder.h"
#include "fnv/decl/GroupScore.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryIterOwner.h"
#include "fnv/decl/ItemList.h"
#include "fnv/decl/LockExtraData.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/OuterObj.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/PRProcedure.h"
#include "fnv/decl/PathingLocationCheck.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PathingRequestCover.h"
#include "fnv/decl/ProximityGroup.h"
#include "fnv/decl/Proxy88c600.h"
#include "fnv/decl/ResultQuery.h"
#include "fnv/decl/S006950d0.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S5460.h"
#include "fnv/decl/S_006e4570.h"
#include "fnv/decl/S_006e4740.h"
#include "fnv/decl/S_008a8840.h"
#include "fnv/decl/SearchGroup.h"
#include "fnv/decl/Self99.h"
#include "fnv/decl/StandIn.h"
#include "fnv/decl/StandIn_00989010.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESHealthForm.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/ThreatManager.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/UnkThis.h"
#include "fnv/decl/fnv_0049f210__FUN_0049f210_class.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_006dbe40__FUN_006dbe40_Class.h"
#include "fnv/decl/fnv_006dc4d0__FUN_006dc4d0_Class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_008a0b10__FUN_008a0b10_shell.h"
#include "fnv/decl/fnv_008a6840__FUN_008a6840_shell.h"
#include "fnv/decl/fnv_008a8870__HA.h"
#include "fnv/decl/fnv_008acbe0__FUN_008acbe0_shell.h"
#include "fnv/decl/fnv_008be420__Dd.h"
#include "fnv/decl/fnv_00979f70__FUN_00979f70_shell.h"
#include "fnv/decl/fnv_0097c150__CombatActionStandIn.h"
#include "fnv/decl/fnv_0097cfc0__CombatActionStandIn.h"
#include "fnv/decl/fnv_00981380__CombatController.h"
#include "fnv/decl/fnv_009890e0__CombatGroupStub.h"
#include "fnv/decl/fnv_009928c0__CombatFlagHolder.h"
#include "fnv/decl/fnv_009a05b0__FUN_009a05b0_shell.h"
#include "fnv/decl/fnv_009a1280__CombatLogic.h"
#include "fnv/decl/fnv_009a5f90__FUN_009a5f90_shell.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005f9000.h"
#include "fnv/symbols_00637000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006ba000.h"
#include "fnv/symbols_006d6000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00884000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_0099c000.h"
#include "fnv/symbols_0099d000.h"
#include "fnv/symbols_009a0000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_009a7000.h"
#include "fnv/symbols_009a8000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_00aa6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_01066000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_01071000.h"
#include "fnv/symbols_0108d000.h"
#include "fnv/symbols_0108e000.h"
#include "fnv/symbols_011a4000.h"
#include "fnv/symbols_011a5000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f6000.h"
#include "combatstate_decls.h"
// Gets or adds the InventoryChanges for this reference and returns the count of the given object in it, or 0 if none.
// @fnv 0x00575610
int CombatState::GetInventoryItemCount(TESForm* object)
{
    struct
    {
        int result;
        InventoryChanges* inventory;
    } locals;
    locals.result = 0;
    locals.inventory = ::InventoryChanges::CreateForReference((TESObjectREFR*)this);
    if (locals.inventory)
        locals.result = reinterpret_cast<::FUN_004c8f30_shell *>((locals.inventory))->FUN_004c8f30((int)(object));
    return locals.result;
}
// If los is set and its check passes, calls los->FUN_008be220(this); otherwise calls Clear().
// @fnv 0x008be1b0
void CombatState::ProcessCoverLOSResult()
{
    if (los && ::FUN_00884920((int *)(los)))
        reinterpret_cast<::FUN_008be220_cls *>((los))->FUN_008be220((::FUN_008be220_vt *)(::CombatLocations *)(this));
    else
        Clear();
}

// @fnv 0x0064bf90
void CombatState::UpdateCombatStateData(int state, float* pfX, float* pfY, float delta)
{
    timer -= delta;
    if (timer <= 0.0)
    {
        switch (state)
        {
        case -1:
        case 0:
        case 8:
        case 11:
            if (RandomBoolean(::DAT_01017870))
            {
                timer = RandomFloat(::DAT_010162c0, DAT_01017718);
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                timer = RandomFloat(::fnv_00c88020::DAT_01016248, DAT_01016088);
                offsetY = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1286))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1285))))->FUN_00450410());
                offsetX = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1288))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1287))))->FUN_00450410());
            }
            break;
        case 2:
        case 4:
            if (RandomBoolean(::DAT_01017870))
            {
                timer = RandomFloat(DAT_01017718, DAT_0101e570);
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                timer = RandomFloat(::fnv_00c88020::DAT_01016248, DAT_01016088);
                offsetY = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1278))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1277))))->FUN_00450410());
                offsetX = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1280))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1279))))->FUN_00450410());
            }
            break;
        case 3:
        case 9:
        case 12:
            timer = RandomFloat(::DAT_010162c0, DAT_01017718);
            if (RandomBoolean(::DAT_01017870))
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                offsetY = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1282))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1281))))->FUN_00450410());
                offsetX = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1284))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1283))))->FUN_00450410());
            }
            break;
        case 1:
        case 6:
            timer = RandomFloat(::fnv_00c88020::DAT_01016248, DAT_01016088);
            offsetY = 0.0f;
            if (RandomBoolean(::fnv_00c88020::DAT_01016248))
                offsetX = 0.0f;
            else
                offsetX = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1290))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1289))))->FUN_00450410());
            break;
        case 5:
            if (RandomBoolean(::DAT_01017870))
            {
                timer = RandomFloat(DAT_01017718, DAT_0101e570);
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else
            {
                timer = RandomFloat(::fnv_00c88020::DAT_01016248, DAT_01016088);
                offsetY = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1292))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1291))))->FUN_00450410());
                offsetX = RandomFloat(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1294))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1293))))->FUN_00450410());
            }
            break;
        }
    }
    *pfX += offsetX;
    *pfY += offsetY;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CombatCoverPointData
{
    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
    bool m_bDataDirty;
    bool bReserved;
    unsigned char m_ucCoverHeight;
    char _pad_3[1];
    int iLocation;
    char m_cCoverData[12];
    char CombatCoverPoint[84];
    unsigned int m_uiCoverFlags;
    unsigned int m_uiLocationFlags;
    char m_cTrailingData[6];
    char _pad_76[2];
};
struct FUN_005dc960_shell : public CombatCoverPointData
{
    bool FUN_005dc960();
};

// @fnv 0x005dc960
bool FUN_005dc960_shell::FUN_005dc960()
{
    return bReserved;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CoordinateTriple;
struct TESForm;
struct TESObjectREFR;
struct CombatAvoidanceSphere
{
    void Copy(void*);
    void SetLocation(int);
    void SetPoint(void*, TESForm*);
    void SetTargetForm(TESForm*);
    void AssignReference(TESObjectREFR*);
    void SetRadius(float);
    void SetFlag(unsigned int, bool);
    void SetWorldLocation(void*);
    void* GetPoint();
    TESObjectREFR* GetRef();
    TESForm* GetReferenceSpace();
    CoordinateTriple* GetWorldForwardVector();
    int GetLocation();
    float GetRadius();
    bool GetFlag(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void IsWithinSphere();
    char m_cBuffer[16];
    TESObjectREFR* pRef;
    int iLocation;
    float fRadius;
    unsigned int iFlags;
};
struct FUN_00819a50_shell : public CombatAvoidanceSphere
{
    void FUN_00819a50(float);
};

// @fnv 0x00819a50
void FUN_00819a50_shell::FUN_00819a50(float afRadius)
{
    fRadius = afRadius;
}

struct FUN_00997c10_shell
{
    void FUN_00997c10();
};

struct FUN_009989f0_shell
{
    unsigned char GetByteAtOffsetC7();
};

// @fnv 0x009989f0
unsigned char FUN_009989f0_shell::GetByteAtOffsetC7()
{
    return ((unsigned char*)this)[0xc7];
}

struct FUN_00998a10_shell
{
    unsigned char field_c5;
    unsigned char GetFieldC5();
};

// @fnv 0x00998a10
unsigned char FUN_00998a10_shell::GetFieldC5()
{
    return *(unsigned char*)((char*)this + 0xc5);
}

struct CombatTargetMapLock
{
};

struct FUN_0099c210_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    CombatTargetMapLock m_lock;
    void LockCombatTargetMap();
};

// @fnv 0x0099c210
void FUN_0099c210_shell::LockCombatTargetMap()
{
    ::fnv_00aa6060::AcquireLock((::ReadWriteLock *)&(m_lock));
}

struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};

// Deletes the pointer stored at offset 0x18c and sets that field to null.
// @fnv 0x009a0680
void FUN_009a0680_shell::ClearAndDeletePointer()
{
    void* ptr = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18c);
    ::FUN_00401030(ptr);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18c) = 0;
}

void __cdecl operator delete(void*);

struct FUN_009a0a40_shell
{
    char pad[0xc4];
    void* field_c4;
};

// Deletes the pointer stored at field_c4 and sets it to null.
// @fnv 0x009a0a40
void FreeAndClearFieldC4(FUN_009a0a40_shell* thisp)
{
    void* p = thisp->field_c4;
    ::FUN_00401030(p);
    thisp->field_c4 = 0;
}

struct CoordinateTriple
{
};

class BGSLoadGameBuffer;
struct CombatTargetTimestamp
{
public:
    float FUN_006a7f50() const;
public:
    void LoadGame(::BGSLoadGameBuffer *);
};

struct FUN_009a2d80_shell
{
    void FUN_009a2d80(void* buffer);
};

// Calls FUN_00527b70 on this and SaveTimeStamp on the object at offset 0x10, passing buffer to both.
// @fnv 0x009a2d80
void FUN_009a2d80_shell::FUN_009a2d80(void* buffer)
{
    reinterpret_cast<::FUN_00527b70_shell *>((reinterpret_cast<CoordinateTriple*>(this)))->FUN_00527b70((::BGSSaveGameBuffer *)(buffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x10)))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(buffer));
}

struct GlobalObject_00869f00
{
    int* m_ptr;
    void Clear(bool);
};

extern int DAT_0108e068;

// @fnv 0x009a3410
void FUN_009a3410(GlobalObject_00869f00* this_)
{
    this_->m_ptr = &DAT_0108e068;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this_))->Clear(true);
}

namespace fnv_009a35f0 {
struct GlobalObject_00869f00
{
    int m_Data;
    void Clear(bool);
};


struct FUN_009a35f0_shell : GlobalObject_00869f00
{
    void FUN_009a35f0();
};

// @fnv 0x009a35f0
void FUN_009a35f0_shell::FUN_009a35f0()
{
    m_Data = reinterpret_cast<int>(&::DAT_0108e090);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(true);
}
}  // namespace fnv_009a35f0

struct FUN_006d3280_s
{
    bool a, b, c, d, e, f;
    FUN_006d3280_s* ClearFlags();
};
// Sets all six boolean flags of this object to false and returns this.
// @fnv 0x006d3280
FUN_006d3280_s* FUN_006d3280_s::ClearFlags()
{
    a = false;
    b = false;
    c = false;
    d = false;
    e = false;
    f = false;
    return this;
}

struct FUN_006d3370_s
{
    FUN_006d3370_s* FUN_006d3370(unsigned int flags);
};
// Calls FUN_006d33a0, then frees this with _Deallocate if flags has bit 1 set, and returns this.
// @fnv 0x006d3370
FUN_006d3370_s* FUN_006d3370_s::FUN_006d3370(unsigned int flags)
{
    reinterpret_cast<::FUN_006d33a0_Class *>(this)->FUN_006d33a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NavMeshSearchLOSArray
{
    void* vfn_0;
    void* data;
    int size;
    int capacity;
    void FUN_006dbde0(bool freeStorage);
};

struct Elem
{
    int v[21];
};
struct FUN_006dbee0_s
{
    void FUN_006dbee0(Elem* arr, unsigned int count);
};
// @fnv 0x006dbde0
void NavMeshSearchLOSArray::FUN_006dbde0(bool freeStorage)
{
    if (data)
    {
        reinterpret_cast<::FUN_006dbee0_s *>(this)->FUN_006dbee0((::Elem *)(data), size);
        if (freeStorage)
        {
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            data = 0;
            capacity = 0;
        }
        size = 0;
    }
}
// Calls FUN_006dc4d0(0) on each of the count elements in arr.
// @fnv 0x006dbee0
void FUN_006dbee0_s::FUN_006dbee0(Elem* apElements, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
        reinterpret_cast<::fnv_006dc4d0::FUN_006dc4d0_Class *>(&(apElements[i]))->FUN_006dc4d0(0);
}

struct FUN_009052c0_shell
{
    void* FUN_009052c0(int index);
};
// @fnv 0x009052c0
void* FUN_009052c0_shell::FUN_009052c0(int index)
{
    return *(char**)((char*)this + 4) + index * 0x54;
}

struct Tile;
struct IMH
{
};
struct CombatLoc
{
    void FUN_0099ac20(int);
};
// @fnv 0x0097beb0
void FUN_0097beb0(IMH* pIMH, int iUnused, int iValue)
{
    CombatLoc* t = (CombatLoc*)reinterpret_cast<::InterfaceManager *>((pIMH))->FUN_00586150();
    t->FUN_0099ac20(iValue);
}

struct V4
{
    int a, b, c, d;
};
struct FUN_0097ee60_shell
{
    V4 v;
    void AssignV4(V4* o);
};
// Copies the four-int V4 pointed to by o into the shell's v member.
// @fnv 0x0097ee60
void FUN_0097ee60_shell::AssignV4(V4* apValue)
{
    v = *apValue;
}

struct Setting_S
{
};
struct CombatTimeStampHelper
{
};
struct UnknownClass
{
    char _pad[0x94];
    CombatTimeStampHelper ts;
    bool IsElapsedTimeAtLeastSetting();
};
// Returns true if ts.GetElapsedTime() is greater than or equal to the value from originalRuntimeFloatSetting413.Float().
// @fnv 0x0097eee0
bool UnknownClass::IsElapsedTimeAtLeastSetting()
{
    return (reinterpret_cast<::FUN_00435e00_t *>(&(ts))->FUN_00435e00() >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting413)))))) ? 1 : 0);
}

struct FUN_0097ef30_shell
{
    bool FUN_0097ef30();
};
// @fnv 0x0097ef30
bool FUN_0097ef30_shell::FUN_0097ef30()
{
    return 0 < *(unsigned int*)((char*)this + 0xd0);
}

namespace fnv_00997400 {
struct CoordinateTriple
{
    int a;
    int b;
    int c;
    int d;
};

struct TESObjectREFR_STUB
{
};

struct CombatAvoidanceSphere
{
    CoordinateTriple m_cBuffer;
    TESObjectREFR* pRef;
    void FUN_00997400(TESObjectREFR* apRef);
};

// @fnv 0x00997400
void CombatAvoidanceSphere::FUN_00997400(TESObjectREFR* apRef)
{
    pRef = apRef;
    m_cBuffer = (*(::fnv_00997400::CoordinateTriple *)(reinterpret_cast<::FUN_00575650_Class *>((reinterpret_cast<TESObjectREFR_STUB*>(pRef)))->FUN_00575650({})));
}
}  // namespace fnv_00997400

struct WL16_997440
{
    int v0;
    int v4;
    int v8;
    int vC;
};
struct Ref_997440
{
};
struct Outer_997440
{
    WL16_997440 loc;
    Ref_997440* pRef;
    void CopyRefValue();
};
// If pRef is set, copies the value returned by pRef->FUN_00575650() into loc.
// @fnv 0x00997440
void Outer_997440::CopyRefValue()
{
    if (pRef)
        loc = (*(::WL16_997440 *)(reinterpret_cast<::FUN_00575650_Class *>((pRef))->FUN_00575650({})));
}

struct CH
{
    int v;
    void CombatTargetTimestamp(float);
};
struct SH
{
};
struct Unk975C0
{
    char _0[24];
    float f18;
    int i1c;
    SH s20;
    void FUN_009975c0();
};
// @fnv 0x00997c10
void FUN_00997c10_shell::FUN_00997c10()
{
    reinterpret_cast<::Unk975C0 *>((((FUN_00997c10_shell*)((char*)this + 0x128))))->FUN_009975c0();
}
// @fnv 0x009975c0
void Unk975C0::FUN_009975c0()
{
    CH data;
    f18 = 0.0f;
    reinterpret_cast<::FUN_00435de0_ctor *>(&(data))->FUN_00435de0(-DAT_0108df70);
    i1c = data.v;
    reinterpret_cast<::NavMeshSearchLOSArray *>(&(s20))->FUN_006dbde0(1);
}

namespace fnv_00997ba0 {
struct FUN_00997c10_shell
{
};
struct FUN_009a0680_shell
{
};
struct FUN_00997ba0_shell
{
    void FUN_00997bf0();
    void ReleaseStageHolder(int);
    void FUN_00997ba0(int, int);
};
// When a is zero and b is non-zero, calls FUN_009a03d0(0), FUN_00997bf0, ReleaseStageHolder(0), FUN_00997c10 and ClearAndDeletePointer.
// @fnv 0x00997ba0
void FUN_00997ba0_shell::FUN_00997ba0(int aiFirst, int aiSecond)
{
    if (aiFirst == 0 && aiSecond != 0)
    {
        reinterpret_cast<::FUN_009a03d0_cls *>(this)->FUN_009a03d0(0);
        FUN_00997bf0();
        ReleaseStageHolder(0);
        reinterpret_cast<::FUN_00997c10_shell *>((((FUN_00997c10_shell*)this)))->FUN_00997c10();
        reinterpret_cast<::FUN_009a0680_shell *>((((FUN_009a0680_shell*)this)))->ClearAndDeletePointer();
    }
}
}  // namespace fnv_00997ba0

namespace fnv_00997bf0 {
struct FUN_00997c10_shell
{
};
struct FUN_00997bf0_shell
{
    void FUN_00997bf0();
};
// @fnv 0x00997bf0
void FUN_00997bf0_shell::FUN_00997bf0()
{
    reinterpret_cast<::Unk975C0 *>((((FUN_00997c10_shell*)((char*)this + 0xec))))->FUN_009975c0();
}
}  // namespace fnv_00997bf0

struct MobileObject
{
    unsigned int GetCurrentProcessLevel();
};

struct TESAmmoInitCalls
{
};

struct FUN_00997cb0_Class
{
    void FUN_00997cb0();
    void FUN_00997cf0();
    void FUN_00999160();
};

namespace fnv_00998980 {
struct Setting_S
{
};
struct CombatTimeStampHelper
{
};
struct FUN_00998980_shell
{
    char _pad[0x98];
    CombatTimeStampHelper _ts;
    bool FUN_00998980();
};
// Returns whether the elapsed time from _ts is less than the float value of originalRuntimeFloatSetting411.
// @fnv 0x00998980
bool FUN_00998980_shell::FUN_00998980()
{
    return (double)reinterpret_cast<::FUN_00435e00_t *>(&(_ts))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00998980::Setting_S *>(&::originalRuntimeFloatSetting411))))));
}
}  // namespace fnv_00998980

struct FUN_009989d0_shell
{
    bool FUN_009989d0();
};
// @fnv 0x009989d0
bool FUN_009989d0_shell::FUN_009989d0()
{
    return reinterpret_cast<::fnv_009928c0::CombatFlagHolder *>(this)->HasCombatFlag(0x10);
}

struct FUN_00998a30_shell
{
    bool FUN_00998a30();
};
// @fnv 0x00998a30
bool FUN_00998a30_shell::FUN_00998a30()
{
    return *(bool*)((char*)this + 0xd4);
}

struct FUN_009990c0_s
{
    int a;
    float value;
    bool IsNegative();
};
// Returns true when value is less than _gModifierZero.
// @fnv 0x009990c0
bool FUN_009990c0_s::IsNegative()
{
    return value < ::_DAT_01012060;
}

struct FUN_00999100_shell
{
    bool FUN_006296b0(int);
    bool FUN_00999100();
};
// @fnv 0x00999100
bool FUN_00999100_shell::FUN_00999100()
{
    return FUN_006296b0(3);
}

struct Modifier
{
};
struct Holder
{
    unsigned char _pad[0xB4];
    Modifier mod;
    bool IsModifierZero();
};
// Returns whether the holder's modifier value equals _gModifierZero.
// @fnv 0x00999120
bool Holder::IsModifierZero()
{
    return reinterpret_cast<::TimeoutTimer *>(&(mod))->FUN_006b9130() == ::_DAT_01012060;
}

struct FUN_0099a3e0_s
{
    char a[0x10];
    int state;
    bool FUN_0099a3e0();
};
// Returns true when state is neither 3 nor 4.
// @fnv 0x0099a3e0
bool FUN_0099a3e0_s::FUN_0099a3e0()
{
    return state != 3 && state != 4;
}

class TESActorBase;
struct Actor
{
public:
    ::TESActorBase *GetActorBase();
public:
    bool IsSneaking();
};

struct RegionPoint
{
};

struct CombatTimeStampCtor
{
    void CombatTargetTimestamp(float);
};

struct CombatTimeStamp4
{
    float v;
};


struct FUN_0099a5e0_shell
{
    void UpdateCombatTimestamps(int);
};

// Stores a new combat timestamp at this+0x9c and, if the timestamp at this+0xa4 equals -DAT_0108df70, replaces it with a new one.
// @fnv 0x0099a5e0
void FUN_0099a5e0_shell::UpdateCombatTimestamps(int)
{
    CombatTimeStamp4 a;
    CombatTimeStamp4 b;
    reinterpret_cast<::FUN_00435de0_ctor *>((reinterpret_cast<CombatTimeStampCtor*>(&a)))->FUN_00435de0(::FUN_00435dd0());
    *(CombatTimeStamp4*)((char*)this + 0x9c) = a;
    if (reinterpret_cast<::CombatTargetTimestamp *>((((RegionPoint*)((char*)this + 0xa4))))->FUN_006a7f50() == -DAT_0108df70)
    {
        reinterpret_cast<::FUN_00435de0_ctor *>((reinterpret_cast<CombatTimeStampCtor*>(&b)))->FUN_00435de0(::FUN_00435dd0());
        *(CombatTimeStamp4*)((char*)this + 0xa4) = b;
    }
}

struct FUN_0097f220_t
{
};
struct FUN_0099a650_shell : CombatState
{
    void FUN_0099a650(int a, bool b);
};
// If the flag is false, calls FUN_0097f220 on the object at offset 0x214 of this CombatState.
// @fnv 0x0099a650
void FUN_0099a650_shell::FUN_0099a650(int aiUnused, bool b)
{
    if (!b)
        reinterpret_cast<::FUN_0097f220_Class *>((((FUN_0097f220_t*)((char*)this + 0x214))))->FUN_0097f220();
}

namespace fnv_0099a6b0 {
struct Actor
{
};

struct CombatTargetTimestamp
{
    float val;
    CombatTargetTimestamp(float v);
};

struct S9a0c50
{
    void UpdateModifierState(int);
};

struct S9a1280
{
};

struct FUN_0099a6b0_Class
{
    void FUN_0099a6b0(int, int);
};

// @fnv 0x0099a6b0
void FUN_0099a6b0_Class::FUN_0099a6b0(int p1, int p2)
{
    if (reinterpret_cast<::FUN_00435e00_t *>((((CombatTargetTimestamp*)((char*)this + 0xa0))))->FUN_00435e00() > 1.0)
    {
        ((S9a0c50*)this)->UpdateModifierState(1);
    }
    CombatTargetTimestamp ts(::FUN_00435dd0());
    *(CombatTargetTimestamp*)((char*)this + 0xa0) = ts;
    if (*(unsigned char*)((char*)this + 0xd8) == 2)
    {
        reinterpret_cast<::fnv_009a1280::CombatLogic *>((((S9a1280*)this)))->FUN_009a1280(1);
    }
}
}  // namespace fnv_0099a6b0

namespace fnv_0099a720 {
struct Setting_S
{
};

Setting_S g_011ce058;

struct FUN_008d7f40_cls
{
};

struct FUN_0099a720_cls
{
    void EvaluateWeaponScores();
    void FUN_0099a720();
};

// @fnv 0x0099a720
void FUN_0099a720_cls::FUN_0099a720()
{
    if (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64) <
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58))
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58);
        reinterpret_cast<::FUN_008d7f40_shell *>((reinterpret_cast<FUN_008d7f40_cls*>(reinterpret_cast<char*>(this) + 0x1d4)))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099a720::Setting_S *>(&::g_011ce058)))))));
    }
    EvaluateWeaponScores();
}
}  // namespace fnv_0099a720

struct StageHolder
{
};
struct FUN_0099a9a0_shell
{
    void UpdateStageHolders();
    void ReleaseStageHolder(int);
};
// Checks the StageHolder pointers at offsets 0xE4 and 0xE8 and calls FUN_009a03d0(0) or ReleaseStageHolder(0) for each one that is not done.
// @fnv 0x0099a9a0
void FUN_0099a9a0_shell::UpdateStageHolders()
{
    if (*(StageHolder**)((char*)this + 0xE4) && !reinterpret_cast<::FUN_005dc960_shell *>(((*(StageHolder**)((char*)this + 0xE4))))->FUN_005dc960())
        reinterpret_cast<::FUN_009a03d0_cls *>((this))->FUN_009a03d0(0);
    if (*(StageHolder**)((char*)this + 0xE8) && !reinterpret_cast<::FUN_005dc960_shell *>(((*(StageHolder**)((char*)this + 0xE8))))->FUN_005dc960())
        this->ReleaseStageHolder(0);
}

class TESSound;
struct AlchemyItem
{
    void* FUN_004030b0();
public:
    void SetSound(::TESSound *);
};
struct CTSHelper
{
};
struct D3
{
    int a, b, c;
};

struct FUN_0099ab50_Class
{
    bool FUN_0099ab50(D3* dest);
};

// Checks the item pointer at 0x1c4 and elapsed time against DAT_010718b8; if valid, copies the D3 at 0x84 into dest and returns true, else false.
// @fnv 0x0099ab50
bool FUN_0099ab50_Class::FUN_0099ab50(D3* dest)
{
    void* p = (*(AlchemyItem**)((char*)this + 0x1c4))->FUN_004030b0();
    if (p == 0 || reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)this + 0x98))))->FUN_00435e00() > ::DAT_010718b8)
        return false;
    *dest = *(D3*)((char*)this + 0x84);
    return true;
}

namespace fnv_0099abc0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct Actor
{
};
struct AlchemyItem
{
};
struct FUN_0099abc0_This
{
    bool UpdateLastSeenFiringLocation(NiPoint3&);
};
// Checks the point via FUN_0099ab50, then adds FUN_009a8460's result for the target actor to the point's z and returns true.
// @fnv 0x0099abc0
bool FUN_0099abc0_This::UpdateLastSeenFiringLocation(NiPoint3& arLastSeenFiringLocation)
{
    Actor* ptarget;
    if (!reinterpret_cast<::FUN_0099ab50_Class *>(this)->FUN_0099ab50((::D3 *)&(arLastSeenFiringLocation)))
        return false;
    ptarget = ((::fnv_0099abc0::Actor *)(reinterpret_cast<::AlchemyItem *>(((*(AlchemyItem**)((char*)this + 0x1c4))))->FUN_004030b0()));
    arLastSeenFiringLocation.z += ::FUN_009a8460((::S_009a8460_Actor *)(ptarget), 2, 1);
    return true;
}
}  // namespace fnv_0099abc0

struct MagicItem;
struct MagicCaster
{
};
struct FUN_0099b520_shell : MagicCaster
{
    void FUN_0099b520(MagicItem* spell);
};
// @fnv 0x0099b520
void FUN_0099b520_shell::FUN_0099b520(MagicItem* spell)
{
    reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00((int)(spell));
}

struct FUN_0099b580_shell
{
    void CallReferencedFunction();
};
// @fnv 0x0099b580
void FUN_0099b580_shell::CallReferencedFunction()
{
    reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0();
}

struct FUN_00989010_t
{
};
struct FUN_0099b8b0_shell : FUN_00989010_t
{
    void FUN_0099b8b0(int a, int b);
};
// Calls SetTripleAndValue with the two arguments, then writes 0 to the field at offset 0x10 of this object.
// @fnv 0x0099b8b0
void FUN_0099b8b0_shell::FUN_0099b8b0(int a, int b)
{
    reinterpret_cast<::StandIn_00989010 *>(this)->SetTripleAndValue((::ThreeInts_00989010 *)(a), b);
    *(int*)((char*)this + 0x10) = 0;
}

struct FUN_0099c1f0_shell
{
    bool FUN_0099c1f0();
};
// @fnv 0x0099c1f0
bool FUN_0099c1f0_shell::FUN_0099c1f0()
{
    return *(bool*)((char*)this + 0x4c);
}

struct ParentSpaceNode
{
    int a;
    int b;
    int c;
};
template <class T, int N> struct BSSimpleArray
{
    T& GetAt(int);
};
struct ArrSI : public BSSimpleArray<ParentSpaceNode, 1024>
{
};
bool __cdecl FUN_0099cc60(void*, ParentSpaceNode*, int);
// @fnv 0x0099cb00
bool __cdecl FUN_0099cb00(void* p1, ArrSI* pNodes)
{
    unsigned int i;
    ParentSpaceNode node;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((pNodes))->GetName())); ++i)
    {
        node = pNodes->GetAt(i);
        if (FUN_0099cc60(p1, &node, 0))
            return true;
    }
    return false;
}

namespace fnv_009a0260 {
struct CoordinateTriple
{
    int v[4];
};
struct FUN_009a0260_s
{
    void FUN_009a02a0(CoordinateTriple*);
    void FUN_009a0260(int a, int b, bool c, bool d);
};
// @fnv 0x009a0260
void FUN_009a0260_s::FUN_009a0260(int a, int b, bool c, bool d)
{
    CoordinateTriple loc;
    FUN_009a02a0(((::fnv_009a0260::CoordinateTriple *)(new ((void *)&(loc)) ::FUN_0043a3c0((*(const ::NiPoint3 *)(a)), (::TESForm *)(b)))));
}
}  // namespace fnv_009a0260

namespace fnv_009a0650 {
struct FUN_009a0680_shell
{
};
struct FUN_009a0650_shell : FUN_009a0680_shell
{
    void SetField18C(int v);
};
// Calls ClearAndDeletePointer, then stores v at offset 0x18c of this object.
// @fnv 0x009a0650
void FUN_009a0650_shell::SetField18C(int aiValue)
{
    reinterpret_cast<::FUN_009a0680_shell *>(this)->ClearAndDeletePointer();
    *(int*)((char*)this + 0x18c) = aiValue;
}
}  // namespace fnv_009a0650

struct Inner097
{
    char data[16];
};
struct FUN_009a08d0_Cls
{
    unsigned char b0;
    unsigned char b1;
    int i4;
    Inner097 u8;
    float f18;
    float f1c;
    FUN_009a08d0_Cls* FUN_009a08d0();
};
// @fnv 0x009a08d0
FUN_009a08d0_Cls* FUN_009a08d0_Cls::FUN_009a08d0()
{
    b0 = 0;
    b1 = 0;
    i4 = 0;
    reinterpret_cast<::FUN_0097ede0_cls *>(&(u8))->FUN_0097ede0();
    f18 = 0.0f;
    f1c = 0.0f;
    return this;
}

struct FUN_009a0b30_self
{
    float GetScaledValue();
};

// Returns 0.9 times the float at offset 0x18 of the pointer stored at offset 0xc4, or 0.0 if that pointer is null.
// @fnv 0x009a0b30
float FUN_009a0b30_self::GetScaledValue()
{
    return (
        float)(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xc4)
                   ? *reinterpret_cast<float*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0xc4) + 0x18) *
                         (double)0.9f
                   : 0.0);
}

namespace fnv_009a0be0 {
struct AnimIdle
{
};
struct Setting_S
{
};
struct Obj_1c4
{
};
struct GameSettingCollection;
template <class T> struct SettingT;

struct FUN_009a0be0_Class
{
    float GetIdleAdjustedValue();
};

// Returns the float at this+0xc4 offset 0x1c, adding the runtime float setting when the idle's section is not 0xf, 6 or 0.
// @fnv 0x009a0be0
float FUN_009a0be0_Class::GetIdleAdjustedValue()
{
    AnimIdle* idle = ((::fnv_009a0be0::AnimIdle *)(reinterpret_cast<::FUN_004f9bf0_shell *>((((Obj_1c4*)*(void**)((char*)this + 0x1c4))))->FUN_004f9bf0()));
    if (idle)
    {
        int section = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((idle))->FUN_00825c00()));
        if (section != 0xf && section != 6 && section != 0)
        {
            return *(float*)(*(char**)((char*)this + 0xc4) + 0x1c) +
                   ((float *)&(::FUN_00403e20((float *)(reinterpret_cast<Setting_S*>(&(*reinterpret_cast<::fnv_009a0be0::SettingT< ::fnv_009a0be0::GameSettingCollection> *>(&::originalRuntimeFloatSetting424)))))))[0];
        }
    }
    return *(float*)(*(char**)((char*)this + 0xc4) + 0x1c);
}
}  // namespace fnv_009a0be0

namespace fnv_009a0d00 {
struct E006950d0;

struct S5460
{
};

struct S006950d0
{
};

struct Actor
{
};

struct CombatTargetTimestamp
{
    float time;
    CombatTargetTimestamp(float);
};

struct Entry
{
    void* ptr;
    CombatTargetTimestamp ts;
};

struct FUN_009a0d00_shell
{
    void StoreEntry(const void* apCopy);
};

// @fnv 0x009a0d00
void FUN_009a0d00_shell::StoreEntry(const void* apCopy)
{
    if (!apCopy)
        return;
    unsigned int count = reinterpret_cast<::S5460 *>((((S5460*)((char*)this + 0x164))))->FUN_00845460();
    ((Entry*)((::fnv_009a0d00::E006950d0 *)(reinterpret_cast<::S006950d0 *>((((S006950d0*)((char*)this + 0x164))))->GetElement(count))))->ptr = (void*)apCopy;
    CombatTargetTimestamp ts(::FUN_00435dd0());
    ((Entry*)((::fnv_009a0d00::E006950d0 *)(reinterpret_cast<::S006950d0 *>((((S006950d0*)((char*)this + 0x164))))->GetElement(count))))->ts = ts;
}
}  // namespace fnv_009a0d00

namespace fnv_009a0ec0 {
struct S20;
struct H4
{
};
struct FUN_007881d0_shell
{
};
struct CombatTimeStamp_ctor
{
    void CombatTargetTimestamp(float);
};
struct Actor
{
};

struct FUN_009a0ec0_Block
{
    unsigned int v[4];
};
struct FUN_009a0ec0_Ts
{
    unsigned int v;
};
struct FUN_009a0ec0_Node
{
    FUN_009a0ec0_Block block;
    FUN_009a0ec0_Ts ts;
};

struct FUN_009a0ec0_shell
{
    void SetNodeBlockAndTimestamp(const FUN_009a0ec0_Block* a1);
};

// @fnv 0x009a0ec0
void FUN_009a0ec0_shell::SetNodeBlockAndTimestamp(const FUN_009a0ec0_Block* apBlock)
{
    FUN_009a0ec0_Ts timeStamp;
    unsigned int index = reinterpret_cast<::S5460 *>((reinterpret_cast<FUN_007881d0_shell*>(reinterpret_cast<char*>(this) + 0x174)))->FUN_007881d0();
    reinterpret_cast<FUN_009a0ec0_Node*>(
        ((::fnv_009a0ec0::S20 *)(reinterpret_cast<::FUN_006b3160_shell *>((reinterpret_cast<H4*>(reinterpret_cast<char*>(this) + 0x174)))->FUN_006b3160(index))))
        ->block = *apBlock;
    reinterpret_cast<::FUN_00435de0_ctor *>((reinterpret_cast<CombatTimeStamp_ctor*>(&timeStamp)))->FUN_00435de0(::FUN_00435dd0());
    reinterpret_cast<FUN_009a0ec0_Node*>(
        ((::fnv_009a0ec0::S20 *)(reinterpret_cast<::FUN_006b3160_shell *>((reinterpret_cast<H4*>(reinterpret_cast<char*>(this) + 0x174)))->FUN_006b3160(index))))
        ->ts = timeStamp;
}
}  // namespace fnv_009a0ec0

namespace fnv_009a1010 {
struct Actor
{
    float FUN_008be600();
};

struct TESAmmoInitCalls
{
};

struct FUN_009a1010_Class
{
    void FUN_009a1010();
};

// @fnv 0x009a1010
void FUN_009a1010_Class::FUN_009a1010()
{
    Actor* ptarget = (Actor*)((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)((*(TESAmmoInitCalls**)((char*)this + 0x1c4))))));
    *(float*)((char*)this + 0xd4) = ptarget->FUN_008be600();
    *(float*)((char*)this + 0xd0) = reinterpret_cast<::fnv_008acbe0::FUN_008acbe0_shell *>((ptarget))->GetModifiedDamagePerSecond(*(float*)((char*)this + 0xd4));
}
}  // namespace fnv_009a1010

namespace fnv_009a2bf0 {
struct BGSSaveFormBuffer
{
};

struct CoordinateTriple
{
    void* field00;
    void* field04;
    void* field08;
    void* field0C;
};

struct FUN_009a2bf0_shell : CoordinateTriple
{
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void FUN_009a2bf0(BGSSaveFormBuffer* a_buffer);
};

// @fnv 0x009a2bf0
void FUN_009a2bf0_shell::FUN_009a2bf0(BGSSaveFormBuffer* a_buffer)
{
    reinterpret_cast<::FUN_00527b70_shell *>(this)->FUN_00527b70((::BGSSaveGameBuffer *)(a_buffer));
    reinterpret_cast<::FUN_00865e50_shell *>((a_buffer))->FUN_00865e50(&field14, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((a_buffer))->FUN_00865e50(&field18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((a_buffer))->FUN_00865e50(&field1C, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((a_buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(field10), 0);
}
}  // namespace fnv_009a2bf0

struct BGSLoadFormBuffer
{
};

struct FUN_00527ba0_Class
{
};

struct FUN_009a2c60_Class
{
    void LoadFormData(void*);
};

// @fnv 0x009a2c60
void FUN_009a2c60_Class::LoadFormData(void* buffer)
{
    reinterpret_cast<::FUN_00527ba0_This *>((((FUN_00527ba0_Class*)this)))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x14)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x18)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x1c)), 4);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_008648e0((unsigned int *)(void *)((void*)((char*)this + 0x10)));
}

namespace fnv_009a2d20 {
struct BGSSaveFormBuffer
{
};
struct CombatTargetTimestamp
{
    int v;
};
struct FUN_009a2d20_s
{
    int a;
    CombatTargetTimestamp ts;
    void FUN_009a2d20(BGSSaveFormBuffer* buf);
};
// @fnv 0x009a2d20
void FUN_009a2d20_s::FUN_009a2d20(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(this, 4, 0);
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(ts))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(apBuffer));
}
}  // namespace fnv_009a2d20

namespace fnv_009a2d50 {
struct BGSLoadGameBuffer;
struct BGSLoadFormBuffer
{
};
struct CombatTargetTimestamp
{
    int v;
    void LoadGame(BGSLoadGameBuffer*);
};
struct FUN_009a2d50_s
{
    int a;
    CombatTargetTimestamp ts;
    void FUN_009a2d50(BGSLoadFormBuffer* buf);
};
// Reads 4 bytes of this object from buf, then loads the ts member from the same buffer.
// @fnv 0x009a2d50
void FUN_009a2d50_s::FUN_009a2d50(BGSLoadFormBuffer* buf)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 4);
    reinterpret_cast<::CombatTargetTimestamp *>(&(ts))->LoadGame((::BGSLoadGameBuffer *)(::fnv_009a2d50::BGSLoadGameBuffer *)((BGSLoadGameBuffer*)buf));
}
}  // namespace fnv_009a2d50

namespace fnv_009a2db0 {
struct BGSLoadGameBuffer;
struct CombatTargetTimestamp
{
    void LoadGame(BGSLoadGameBuffer*);
};
struct FUN_00527ba0_t
{
};
struct FUN_009a2db0_shell : FUN_00527ba0_t
{
    void FUN_009a2db0(BGSLoadGameBuffer* buf);
};
// @fnv 0x009a2db0
void FUN_009a2db0_shell::FUN_009a2db0(BGSLoadGameBuffer* buf)
{
    reinterpret_cast<::FUN_00527ba0_This *>(this)->FUN_00527ba0((::BGSLoadGameBuffer *)(buf));
    reinterpret_cast<::CombatTargetTimestamp *>((((CombatTargetTimestamp*)((char*)this + 0x10))))->LoadGame((::BGSLoadGameBuffer *)(buf));
}
}  // namespace fnv_009a2db0

namespace fnv_009a3130 {
struct BGSSaveFormBuffer
{
};
struct CoordinateTriple
{
};
struct CombatSaveData
{
    unsigned char unk0;
    unsigned char unk1;
    void* pRef;
    unsigned char unk08[16];
    int unk18;
    int unk1C;
    void FUN_009a3130(BGSSaveFormBuffer*);
};
// @fnv 0x009a3130
void CombatSaveData::FUN_009a3130(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk0, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk1, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk1C, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pRef), 0);
    reinterpret_cast<::FUN_00527b70_shell *>((((CoordinateTriple*)((char*)this + 8))))->FUN_00527b70((::BGSSaveGameBuffer *)(apSaveGameBuffer));
}
}  // namespace fnv_009a3130

namespace fnv_009a31b0 {
struct BGSLoadFormBuffer
{
};
struct Sub08
{
};
struct Holder
{
    void FUN_009a31b0(BGSLoadFormBuffer*);
};
// Reads bytes at offsets 0, 1, 0x18 and 0x1C, a value at offset 4, and delegates offset 8 to FUN_00527ba0, all via the load buffer.
// @fnv 0x009a31b0
void Holder::FUN_009a31b0(BGSLoadFormBuffer* pBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 1)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x18)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x1C)), 4);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((pBuffer))->FUN_008648e0((unsigned int *)(void *)((void*)((char*)this + 4)));
    reinterpret_cast<::FUN_00527ba0_This *>((((Sub08*)((char*)this + 8))))->FUN_00527ba0((::BGSLoadGameBuffer *)(pBuffer));
}
}  // namespace fnv_009a31b0

struct FUN_009a3280_shell
{
    void* FUN_009a3280(int index);
};
// @fnv 0x009a3280
void* FUN_009a3280_shell::FUN_009a3280(int index)
{
    return reinterpret_cast<::FUN_009052c0_shell *>(this)->FUN_009052c0(index);
}

struct Elem54
{
    char data[0x54];
};
struct RetObj
{
};
struct Helper
{
};
struct Host
{
    int unk0;
    Elem54* arr;
    unsigned int cnt;
    void ProcessElements(Helper*);
};
struct FUN_009cc490_shell
{
    void FUN_009cc490(unsigned int flags);
};
// @fnv 0x009cc490
void FUN_009cc490_shell::FUN_009cc490(unsigned int flags)
{
    *(unsigned int*)((char*)this + 4) |= flags;
}

struct CCL
{
    int v;
};
struct FUN_009d6730_shell : CombatState
{
    CCL* FUN_009d6730(CCL* out);
};
// @fnv 0x009d6730
CCL* FUN_009d6730_shell::FUN_009d6730(CCL* out)
{
    *out = *(CCL*)((char*)this + 0xa0);
    return out;
}

struct CombatCoverPointData;
struct FUN_009d6c80_shell
{
    void FUN_009d6c80();
};
// @fnv 0x009d6c80
void FUN_009d6c80_shell::FUN_009d6c80()
{
    reinterpret_cast<::fnv_009a05b0::FUN_009a05b0_shell *>(this)->FUN_009a05b0((::fnv_009a05b0::StageHolder *)(*(CombatCoverPointData**)((char*)this + 0xe8)));
}

struct CombatCoverPointData;
struct FUN_009d7c20_shell : CombatState
{
    void FUN_009d7c20();
};
// @fnv 0x009d7c20
void FUN_009d7c20_shell::FUN_009d7c20()
{
    reinterpret_cast<::FUN_009a0510_shell *>(this)->FUN_009a0510((::StageHolder *)(*(CombatCoverPointData**)&this->unke8));
}

struct RefX
{
};
struct FUN_00981340_shell
{
    void FreeSlot(int);
};
struct FUN_0097cfc0_shell
{
};
struct FUN_0099a530_shell
{
    void FUN_0099a530();
};
// @fnv 0x0099a530
void FUN_0099a530_shell::FUN_0099a530()
{
    void* a = *(void**)((char*)this + 0x19c);
    void* b = *(void**)((char*)this + 0x1a0);
    for (unsigned int i = 0; i < 5; ++i)
    {
        void* pSlotObj = ((void *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>((((FUN_0097cfc0_shell*)this)))->GetActionAtIndex(i)));
        if (pSlotObj && *(void**)pSlotObj && reinterpret_cast<::FUN_00437b90_shell *>((((RefX*)*(void**)pSlotObj)))->FUN_00437b90())
            ((FUN_00981340_shell*)this)->FreeSlot(i);
    }
    if (a != ((void *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>((((FUN_0097cfc0_shell*)this)))->GetActionAtIndex(3))) || b != ((void *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>((((FUN_0097cfc0_shell*)this)))->GetActionAtIndex(4))))
    {
        ((FUN_00981340_shell*)this)->FreeSlot(3);
        ((FUN_00981340_shell*)this)->FreeSlot(4);
    }
}

namespace fnv_009a2f50 {
struct BGSSaveGameBuffer
{
};
struct BGSSaveFormBuffer : BGSSaveGameBuffer
{
};
struct ArrSI
{
};
struct CombatTargetTimestamp
{
};
struct FUN_009a3280_shell
{
};
struct FUN_009a2f50_shell
{
    void FUN_009a2f50(BGSSaveFormBuffer* buffer);
};
// @fnv 0x009a2f50
void FUN_009a2f50_shell::FUN_009a2f50(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(this, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 12, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 24, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 56, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 48, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 52, 4, 0);
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((CombatTargetTimestamp*)((char*)this + 28))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(buffer));
    unsigned int flags = ((char*)this + 32) ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 32))))->GetName())) : 0;
    reinterpret_cast<::BGSSaveGameBuffer *>((buffer))->FUN_00865f60(flags);
    for (unsigned int i = 0; i < flags; ++i)
    {
        void* cover = reinterpret_cast<::FUN_009a3280_shell *>((((FUN_009a3280_shell*)((char*)this + 32))))->FUN_009a3280(i);
        ((void(*)(void*, BGSSaveFormBuffer*))(*((int**)cover))[0])(cover, buffer);
    }
}
}  // namespace fnv_009a2f50

namespace fnv_009a3050 {
struct BGSLoadFormBuffer
{
};
struct CombatTargetTimestamp
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct PathingCoverLocation
{
    virtual void v0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct Helper
{
    void FUN_009a32a0(unsigned int, int);
};
struct FUN_009a3280_shell
{
};
struct CombatSaveGameData
{
    void FUN_009a3050(BGSLoadFormBuffer* buffer);
};
// Reads this object's fields from the buffer, then loads a count and each of that many PathingCoverLocation entries via LoadGame.
// @fnv 0x009a3050
void CombatSaveGameData::FUN_009a3050(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0xc), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x18), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x38), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x30), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x34), 4);
    reinterpret_cast<::CombatTargetTimestamp *>((((CombatTargetTimestamp*)((char*)this + 0x1c))))->LoadGame((::BGSLoadGameBuffer *)(buffer));
    unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
    ((Helper*)((char*)this + 0x20))->FUN_009a32a0(count, 1);
    unsigned int i = 0;
    for (; i < count; ++i)
    {
        PathingCoverLocation* cover = ((::fnv_009a3050::PathingCoverLocation *)(reinterpret_cast<::FUN_009a3280_shell *>((((FUN_009a3280_shell*)((char*)this + 0x20))))->FUN_009a3280(i)));
        cover->LoadGame(buffer);
    }
}
}  // namespace fnv_009a3050

struct FUN_0097ee20_shell
{
    char _pad[0x10];
    int f10;
    int f14;
    float f18;
    int f1c;
    FUN_0097ee20_shell* FUN_0097ee20();
};

// Calls FUN_0097ede0, then sets f10 to 0, f14 to -1, f18 to 0.0f and f1c to 0, returning this.
// @fnv 0x0097ee20
FUN_0097ee20_shell* FUN_0097ee20_shell::FUN_0097ee20()
{
    reinterpret_cast<::FUN_0097ede0_cls *>(this)->FUN_0097ede0();
    f10 = 0;
    f14 = -1;
    f18 = 0.0f;
    f1c = 0;
    return this;
}

struct TES;
struct TESWorldSpace;

struct TES
{
};

struct TESWorldSpace
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
    virtual int getFormType();
};

struct Container
{
    bool FUN_0099a360(int, TESWorldSpace*);
};

// @fnv 0x0099a360
bool Container::FUN_0099a360(int, TESWorldSpace* param2)
{
    if (param2 != *(TESWorldSpace**)((char*)this + 0x1c0))
        return true;
    bool bResult = true;
    if (*(int*)((char*)this + 0x6c) > 0)
    {
        TESWorldSpace* SoundAssetTmp = ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((((TES*)(*(TES**)((char*)this + 0x1c4)))))->GetHitSound()));
        if (SoundAssetTmp)
        {
            if (SoundAssetTmp->getFormType() == 7)
            {
                TESWorldSpace* pHitSoundCopy = SoundAssetTmp;
                if (reinterpret_cast<::FUN_0099a3e0_s *>((pHitSoundCopy))->FUN_0099a3e0())
                    bResult = false;
            }
        }
    }
    return bResult;
}

namespace fnv_0099a680 {
struct CombatTargetTimestamp
{
    int v;
    CombatTargetTimestamp(float);
};
struct Actor
{
};
struct FUN_0099a680_s
{
    char pad[0x9c];
    CombatTargetTimestamp stamp;
    void SetStampFromActor(int);
};
// @fnv 0x0099a680
void FUN_0099a680_s::SetStampFromActor(int)
{
    CombatTargetTimestamp t(::FUN_00435dd0());
    stamp = t;
}
}  // namespace fnv_0099a680

struct S81
{
};
struct C99
{
    char _pad[0x1C4];
    S81* f1C4;
    void FUN_0099a780(int);
};
namespace fnv_0099a7d0 {
bool FUN_00981990(void*);
int _FNV_GetFormType(void*);
struct Actor
{
};
struct CTSHelper
{
    void CombatTargetTimestamp(float);
};
struct Host
{
    char _pad0[0xdc];
    unsigned int m_uiCoverPointFlags;
    unsigned int m_kCoverPointData;
    char _pad1[0x1c4 - 0xe4];
    void* ctrl;
    void FUN_0099a7d0(void* apRef, void* apObject, int aiCount, bool abActivatedScriptOnly);
};
// @fnv 0x0099a7d0
void Host::FUN_0099a7d0(void* apRef, void* apObject, int aiCount, bool abActivatedScriptOnly)
{
    if (FUN_00981990(ctrl))
    {
        if (_FNV_GetFormType(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))) == 0x1c)
        {
            m_uiCoverPointFlags = reinterpret_cast<::FUN_0084e3a0_Class *>((apRef))->FUN_0084e3a0();
            unsigned int ts;
            reinterpret_cast<::FUN_00435de0_ctor *>((((CTSHelper*)&ts)))->FUN_00435de0(::FUN_00435dd0());
            m_kCoverPointData = ts;
        }
    }
}
}  // namespace fnv_0099a7d0

struct FUN_0099b540_s
{
    char pad[0x1c];
    unsigned int flags;
    void SetFlags(unsigned int mask, bool set);
};
// Sets or clears the bits of flags selected by mask, according to set.
// @fnv 0x0099b540
void FUN_0099b540_s::SetFlags(unsigned int mask, bool set)
{
    if (set)
        flags |= mask;
    else
        flags &= ~mask;
}

struct CombatCoverPointData;
struct FUN_009a0600_shell
{
    unsigned char _pad[0xE4];
    CombatCoverPointData* m_pCurrentCoverPoint;
    CombatCoverPointData* m_pAlternateCoverPoint;
    bool FUN_009a0600(CombatCoverPointData* apCoverLocation);
};
// @fnv 0x009a0600
bool FUN_009a0600_shell::FUN_009a0600(CombatCoverPointData* apCoverLocation)
{
    if (!apCoverLocation)
        return false;
    return apCoverLocation == m_pCurrentCoverPoint || apCoverLocation == m_pAlternateCoverPoint;
}

namespace fnv_009a0a80 {
struct AlchemyItem
{
};
struct Host
{
    unsigned char pad0[0xC4];
    unsigned char* field_C4;
    unsigned char pad1[0x1C4 - 0xC4 - 4];
    AlchemyItem* field_1C4;
    bool FUN_0097ee90();
    bool FUN_009a0a80();
};
// @fnv 0x009a0a80
bool Host::FUN_009a0a80()
{
    void* tmp = reinterpret_cast<::AlchemyItem *>((field_1C4))->FUN_004030b0();
    if (tmp != 0)
    {
        if (FUN_0097ee90() || reinterpret_cast<::OuterObj *>((field_1C4))->FUN_00981420())
            return true;
    }
    if (tmp == 0 && field_C4 != 0 && *field_C4 == 2)
        return true;
    return false;
}
}  // namespace fnv_009a0a80

struct Target
{
    float f[8];
public:
    int GetIntAt(unsigned int);
};
struct FUN_009a0b00_s
{
    char pad[0xc4];
    Target* t;
    float FUN_009a0b00();
};
// Returns t->f[7] when FUN_009a0a80() succeeds, otherwise returns the result of GetScaledValue().
// @fnv 0x009a0b00
float FUN_009a0b00_s::FUN_009a0b00()
{
    if (reinterpret_cast<::fnv_009a0a80::Host *>(this)->FUN_009a0a80())
        return t->f[7];
    return reinterpret_cast<::FUN_009a0b30_self *>(this)->GetScaledValue();
}

namespace fnv_009a0b70 {
struct Setting_S
{
};
struct SettingT_GameSettingCollection : Setting_S
{
};

struct InnerData
{
    char pad0;
    unsigned char flag;
    char pad[0x16];
    float val18;
    float val1c;
};

struct FUN_009a0b70_shell
{
    char pad_c4[0xc4];
    InnerData* ptr;
    float GetInterpolatedValue();
};

// Returns ptr->val1c plus the runtime float setting when ptr->flag is set, otherwise interpolates between ptr->val18 and ptr->val1c using DAT_0101de30.
// @fnv 0x009a0b70
float FUN_009a0b70_shell::GetInterpolatedValue()
{
    if (ptr->flag)
        return ptr->val1c + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009a0b70::SettingT_GameSettingCollection *>(&::originalRuntimeFloatSetting424))))));
    return (ptr->val1c - ptr->val18) * ::DAT_0101de30 + ptr->val18;
}
}  // namespace fnv_009a0b70

extern int DAT_0108e068;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_009a33e0_shell : AX
{
    FUN_009a33e0_shell* FUN_009a33e0();
};
// Sets the object's vtable pointer to DAT_0108e068, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x009a33e0
FUN_009a33e0_shell* FUN_009a33e0_shell::FUN_009a33e0()
{
    *(int**)this = &DAT_0108e068;
    FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_009a39f0_t
{
};
struct FUN_009a3430_shell : FUN_009a39f0_t
{
    FUN_009a3430_shell* FUN_009a3430();
};
// Sets the object's vtable pointer to DAT_0108e07c, calls FUN_009a39f0(0, 0), and returns this.
// @fnv 0x009a3430
FUN_009a3430_shell* FUN_009a3430_shell::FUN_009a3430()
{
    *(int**)this = &DAT_0108e07c;
    reinterpret_cast<::FUN_009a39f0_class *>(this)->FUN_009a39f0(0, 0);
    return this;
}

namespace fnv_009a3460 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_009a3460_shell : GlobalObject_00869f00
{
    void FUN_009a3460();
};
// @fnv 0x009a3460
void FUN_009a3460_shell::FUN_009a3460()
{
    *(int**)this = &::DAT_0108e07c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_009a3460

struct FUN_009a3bc0_t
{
};
struct FUN_009a35c0_shell : FUN_009a3bc0_t
{
    FUN_009a35c0_shell* FUN_009a35c0();
};
// Sets the object's vtable pointer to DAT_0108e090, calls Initialize with 0, 0, and returns this.
// @fnv 0x009a35c0
FUN_009a35c0_shell* FUN_009a35c0_shell::FUN_009a35c0()
{
    *(int**)this = &DAT_0108e090;
    reinterpret_cast<::FUN_009a3bc0_class *>(this)->Initialize(0, 0);
    return this;
}

namespace fnv_00997480 {
struct S12
{
    int a, b, c;
};
struct S6
{
    short a, b, c;
};

struct RetObj
{
};

struct FUN_00997480_shell
{
    void FUN_00997480(const FUN_00997480_shell* apCopy);
};

// @fnv 0x00997480
void FUN_00997480_shell::FUN_00997480(const FUN_00997480_shell* apCopy)
{
    *(bool*)((char*)this + 0) = *(bool*)((char*)apCopy + 0);
    *(bool*)((char*)this + 1) = *(bool*)((char*)apCopy + 1);
    *(unsigned char*)((char*)this + 2) = *(unsigned char*)((char*)apCopy + 2);
    *(int*)((char*)this + 4) = *(int*)((char*)apCopy + 4);
    *(S12*)((char*)this + 8) = *(S12*)((char*)apCopy + 8);
    reinterpret_cast<::FUN_006e4430_class *>((((RetObj*)((char*)this + 0x14))))->operator=((*(const ::FUN_006e4430_class *)((RetObj*)((char*)apCopy + 0x14))));
    *(unsigned int*)((char*)this + 0x68) = *(unsigned int*)((char*)apCopy + 0x68);
    *(unsigned int*)((char*)this + 0x6c) = *(unsigned int*)((char*)apCopy + 0x6c);
    *(S6*)((char*)this + 0x70) = *(S6*)((char*)apCopy + 0x70);
}
}  // namespace fnv_00997480

namespace fnv_00997520 {
struct S12
{
    int a, b, c;
};
struct S4
{
    int a;
};
struct Helper;
struct Host
{
};
struct Unk975C0
{
};
struct FUN_00997520_shell : Unk975C0
{
    void FUN_00997520(const void* apParam);
};

// @fnv 0x00997520
void FUN_00997520_shell::FUN_00997520(const void* apParam)
{
    if (!apParam)
    {
        reinterpret_cast<::Unk975C0 *>(this)->FUN_009975c0();
        return;
    }
    *(S12*)((char*)this + 0) = *(S12*)((char*)apParam + 0);
    *(S12*)((char*)this + 0xc) = *(S12*)((char*)apParam + 0xc);
    *(float*)((char*)this + 0x18) = *(float*)((char*)apParam + 0x18);
    *(S4*)((char*)this + 0x1c) = *(S4*)((char*)apParam + 0x1c);
    reinterpret_cast<::Host *>((((Host*)((char*)apParam + 0x20))))->ProcessElements((::Helper *)(::fnv_00997520::Helper *)((Helper*)((char*)this + 0x20)));
    *(int*)((char*)this + 0x30) = *(int*)((char*)apParam + 0x30);
    *(int*)((char*)this + 0x34) = *(int*)((char*)apParam + 0x34);
    *(char*)((char*)this + 0x38) = *(char*)((char*)apParam + 0x38);
}
}  // namespace fnv_00997520

namespace fnv_00997aa0 {
struct FUN_00981340_shell
{
};

struct FUN_009a0680_shell : FUN_00981340_shell
{
};

struct FUN_0099a9a0_shell : FUN_009a0680_shell
{
    void ReleaseStageHolder(int);
};

struct FUN_009a0a40_shell : FUN_0099a9a0_shell
{
};


struct PrimaryBase : FUN_009a0a40_shell
{
    int pad[9];
    void FUN_0099a2a0();
};

struct GlobalObject_00869f00;
void FUN_009a3410(GlobalObject_00869f00*);

struct Base_009a3410
{
    int pad;
    ~Base_009a3410()
    {
        FUN_009a3410((GlobalObject_00869f00*)this);
    }
};

struct FUN_006e4d00_shell
{
    int pad;
    void CallMemberFunction();
    ~FUN_006e4d00_shell()
    {
        CallMemberFunction();
    }
};

struct FUN_009a3460_shell
{
    int pad;
    void FUN_009a3460();
    ~FUN_009a3460_shell()
    {
        FUN_009a3460();
    }
};

struct FUN_009a35f0_class
{
    int pad;
    void FUN_009a35f0();
    ~FUN_009a35f0_class()
    {
        FUN_009a35f0();
    }
};

struct Ptr2_006e9e20
{
    int pad;
    ~Ptr2_006e9e20();
};

struct FUN_00997aa0 : PrimaryBase, Base_009a3410
{
    char pad_28[0xec - 0x28];
    FUN_006e4d00_shell m_ec;
    char pad_f0[0x128 - 0xf0];
    FUN_006e4d00_shell m_128;
    char pad_12c[0x164 - 0x12c];
    FUN_009a3460_shell m_164;
    char pad_168[0x174 - 0x168];
    FUN_009a35f0_class m_174;
    char pad_178[0x224 - 0x178];
    Ptr2_006e9e20 m_224;

    ~FUN_00997aa0();
};

// @fnv 0x00997aa0
FUN_00997aa0::~FUN_00997aa0()
{
    FUN_0099a2a0();
    reinterpret_cast<::FUN_009a03d0_cls *>(this)->FUN_009a03d0(0);
    ReleaseStageHolder(0);
    reinterpret_cast<::FUN_009a0680_shell *>(this)->ClearAndDeletePointer();
    ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)(::fnv_00997aa0::FUN_009a0a40_shell *)(this));
    for (unsigned int i = 0; i < 5; ++i)
    {
        reinterpret_cast<::FUN_00981340_shell *>(this)->FreeSlot(i);
    }
}
}  // namespace fnv_00997aa0

namespace fnv_00997c30 {
struct TESAmmoInitCalls
{
};


struct FUN_00997cb0_Class
{
};

struct SubObj
{
    virtual void vf0();
    virtual void vf1();
    virtual bool vf2(bool);
};

struct FUN_00997c30_shell : FUN_00997cb0_Class
{
    void EvaluateWeaponScores();
    void InitAmmoState();
};

// @fnv 0x00997c30
void FUN_00997c30_shell::InitAmmoState()
{
    void* local4 = (void*)((void *)(::GetFieldBC((::FUN_0097ae90_Class *)(((TESAmmoInitCalls*)*(void**)((char*)this + 0x1c4))))));
    *(char*)((char*)this + 0x75) = ::FUN_0097f310((::VtableOwner *)(local4), 0);
    EvaluateWeaponScores();
    reinterpret_cast<::FUN_00997cb0_Class *>(this)->FUN_00997cb0();
    *(char*)((char*)this + 0xc8) = ((SubObj*)((char*)local4 + 0xa4))->vf2(true);
    *(char*)((char*)this + 0xc9) = *(char*)((char*)this + 0xc8);
    *(char*)((char*)this + 0x1c8) = 0;
}
}  // namespace fnv_00997c30

namespace fnv_00999160 {
struct CombatTargetTimestamp;

struct TESAmmoInitCalls
{
};

struct AlchemyItem : TESAmmoInitCalls
{
};

struct MyClass
{
};

struct EffectSetting : AlchemyItem
{
};

struct Setting_S
{
};


struct FUN_008d7f40_shell
{
};

struct TimeoutTimer : FUN_008d7f40_shell
{
};

struct FUN_00999160_struct
{
    char pad_00[0x6c];
    int unk6c;
    bool unk70;
    bool unk71;
    char pad72[0x5];
    bool unk77;
    char pad78[0x14c];
    EffectSetting* field_1C4;

    void EvaluateWeaponScores();
    void UpdateRangeValue();

    void FUN_00999160();
};

// Reads count and target from field_1C4, calls UpdateTargetPerception with this's offsets when target is set, then runs timer-gated updates at 0x204 and 0x20c.
// @fnv 0x00999160
void FUN_00999160_struct::FUN_00999160()
{
    unsigned int count = ((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)(field_1C4))));
    int target = ((int)(reinterpret_cast<::AlchemyItem *>((field_1C4))->FUN_004030b0()));
    if (target)
    {
        reinterpret_cast<::CombatAssessment::Group *>((((::fnv_00999160::MyClass *)(reinterpret_cast<::EffectSetting *>((field_1C4))->GetCastSound()))))->UpdateTargetPerception((::CombatAssessment::Actor *)(count), (::CombatAssessment::Actor *)(target), &this->unk6c,
                                                          (::CombatAssessment::Time *)(::fnv_00999160::CombatTargetTimestamp *)((CombatTargetTimestamp*)((char*)this + 0x94)),
                                                          &this->unk70, &this->unk71);
    }
    if (this->unk77)
    {
        EvaluateWeaponScores();
    }
    if (reinterpret_cast<::TimeoutTimer *>((((TimeoutTimer*)((char*)this + 0x204))))->CheckTimer())
    {
        reinterpret_cast<::fnv_009a1010::FUN_009a1010_Class *>(this)->FUN_009a1010();
        reinterpret_cast<::FUN_008d7f40_shell *>((((TimeoutTimer*)((char*)this + 0x204))))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00999160::Setting_S *>(&::g_011cf198)))))));
    }
    if (reinterpret_cast<::TimeoutTimer *>((((TimeoutTimer*)((char*)this + 0x20c))))->CheckTimer())
    {
        UpdateRangeValue();
        reinterpret_cast<::FUN_008d7f40_shell *>((((TimeoutTimer*)((char*)this + 0x20c))))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00999160::Setting_S *>(&::originalRuntimeFloatSetting492)))))));
    }
}
}  // namespace fnv_00999160

struct WEAPStub;

struct FUN_0097ac90_shell
{
    float FUN_0097ac90(int);
};

struct CombatStateStub
{
};

struct FUN_0099a2d0_shell
{
    WEAPStub* GetBestWeapon();
};

// Scores weapon types 0-6 via FUN_0097ac90 and returns the weapon from FUN_0097c150 with the highest score, or null for type 6.
// @fnv 0x0099a2d0
WEAPStub* FUN_0099a2d0_shell::GetBestWeapon()
{
    float bestScoreA = 0.0f;
    WEAPStub* kBestWeapon = 0;
    for (unsigned int i = 0; i < 7; ++i)
    {
        float fScore2;
        int weaponType = i;
        fScore2 = ((FUN_0097ac90_shell*)this)->FUN_0097ac90(weaponType);
        if (fScore2 > bestScoreA)
        {
            bestScoreA = fScore2;
            kBestWeapon = (weaponType != 6) ? (kBestWeapon = ((::WEAPStub *)(reinterpret_cast<::fnv_0097c150::CombatActionStandIn *>((((CombatStateStub*)this)))->FUN_0097c150(weaponType)))) : 0;
        }
    }
    return kBestWeapon;
}

namespace fnv_0099a840 {
struct FUN_008d7f40_shell
{
};

struct Setting_S
{
};

struct FUN_0099a840_shell
{
    void FUN_0099a840(void* apItem);
};

// @fnv 0x0099a840
void FUN_0099a840_shell::FUN_0099a840(void* apItem)
{
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (*(void**)((char*)this + 0x1a4 + i * 4) == apItem)
        {
            float val = 0.0f;
            switch (i + 17)
            {
            case 17:
                val = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099a840::Setting_S *>(&::originalRuntimeFloatSetting425))))));
            case 18:
                val = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099a840::Setting_S *>(&::originalRuntimeFloatSetting426))))));
                break;
            }
            reinterpret_cast<::FUN_008d7f40_shell *>((((FUN_008d7f40_shell*)((char*)this + 0x1ac + i * 8))))->FUN_008d7f40(val);
            break;
        }
    }
}
}  // namespace fnv_0099a840

namespace fnv_0099a8d0 {
struct NiPoint3
{
    float x, y, z;
};

struct AlchemyItem
{
};

struct LocS
{
    void* GetLocation();
};

struct FUN_005407b0_Class
{
    char pad0[0x14];
    LocS loc;
};

struct Field18C
{
    char pad0[0x14];
    int state;
};

struct FUN_0099a8d0_struct;

struct FUN_009a0680_shell
{
};

struct FUN_00999100_shell : FUN_009a0680_shell
{
};

struct FUN_0099a8d0_struct : FUN_00999100_shell
{
    char pad0[0xe4];
    FUN_005407b0_Class* field_E4;
    char padE8[0x18c - 0xe8];
    Field18C* field_18C;
    char pad190[0x1c4 - 0x190];
    AlchemyItem* field_1C4;

    bool FUN_0099ccd0(void*, void*, NiPoint3*, void*, int);
    void EvaluateWeaponScores();

    void FUN_0099a8d0();
};

// @fnv 0x0099a8d0
void FUN_0099a8d0_struct::FUN_0099a8d0()
{
    void* ptr4 = reinterpret_cast<::AlchemyItem *>((field_1C4))->FUN_004030b0();
    if (field_E4 && ptr4)
    {
        NiPoint3 local_14;
        bool bSafe = FUN_0099ccd0(&field_E4->loc, ((void *)&(reinterpret_cast<::TaskQueueInterface *>(&(field_E4->loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), &local_14, ptr4, 0);
        if (!bSafe || !::FUN_0097fb20((::CombatState *)(::fnv_0099a8d0::FUN_0099a8d0_struct *)(this)))
        {
            reinterpret_cast<::FUN_005407b0_Class *>((field_E4))->FUN_005407b0(1);
        }
    }
    if (field_18C)
    {
        if (field_18C->state == 0 || field_18C->state == 1)
        {
            reinterpret_cast<::FUN_009a0680_shell *>(this)->ClearAndDeletePointer();
        }
    }
    reinterpret_cast<::FUN_00999100_shell *>(this)->FUN_00999100();
    EvaluateWeaponScores();
}
}  // namespace fnv_0099a8d0

struct NiPoint3
{
    float x, y, z;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

extern int DAT_0106cbc0;

struct StandInShell
{
    StandInShell* FUN_006dcc40(void*);
};

struct FUN_0099aa80_struct : StandInShell
{
    void* vtable;
    char pad4[0x28 - 4];
    NiPoint3 pt28;
    NiPoint3 pt34;
    NiPoint3 pt40;
    char b4c;
    char b4d;
    char b4e;
    char b4f;
    char b50;
    char b51;
    char b52;

    FUN_0099aa80_struct* FUN_0099aa80(FUN_0099aa80_struct* other);
};

// @fnv 0x0099aa80
FUN_0099aa80_struct* FUN_0099aa80_struct::FUN_0099aa80(FUN_0099aa80_struct* other)
{
    FUN_006dcc40(other);
    vtable = &DAT_0106cbc0;
    pt28 = other->pt28;
    pt34 = other->pt34;
    pt40 = other->pt40;
    b4c = other->b4c;
    b4d = other->b4d;
    b4e = other->b4e;
    b4f = other->b4f;
    b50 = other->b50;
    b51 = other->b51;
    b52 = other->b52;
    return this;
}

namespace fnv_0099ca00 {

struct ParentSpaceNode
{
};

struct _ref_006815c0 : ParentSpaceNode
{
    int a, b, c;
    _ref_006815c0();
};

struct Inner097
{
    int pad[4];
    _ref_006815c0* _ref_006815c0();
};

struct Member
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual _ref_006815c0* GetPos();
};

struct EffectSetting
{
};

struct ActorCombatGroup
{
};


struct FUN_0099ca00_struct
{
    char pad0[0x1c4];
    EffectSetting* field_1C4;

    bool FUN_0099ca00(void* arg1, Member* ignore);
};

// @fnv 0x0099ca00
bool FUN_0099ca00_struct::FUN_0099ca00(void* arg1, Member* pIgnoreMember)
{
    ActorCombatGroup* group = ((::fnv_0099ca00::ActorCombatGroup *)(reinterpret_cast<::EffectSetting *>((field_1C4))->GetCastSound()));
    unsigned int count = ::FUN_005a4320((char *)(group));
    for (unsigned int i = 0; i < count; ++i)
    {
        Member* member = ((::fnv_0099ca00::Member *)(reinterpret_cast<::FUN_00968630_stub *>((group))->FUN_00968630(i)));
        if (member == pIgnoreMember)
        {
            continue;
        }
        Inner097 loc;
        reinterpret_cast<::FUN_0097ede0_cls *>(&(loc))->FUN_0097ede0();
        _ref_006815c0 pos;
        if (reinterpret_cast<::ResultQuery *>((group))->TryGetQuadForState(i, (::ResultQuad *)(::fnv_0099ca00::Inner097 *)(&loc), ::DAT_01017718))
        {
            pos = *loc._ref_006815c0();
        }
        else
        {
            pos = *member->GetPos();
        }
        if (::FUN_0099cc60(arg1, (::ParentSpaceNode *)(::fnv_0099ca00::ParentSpaceNode *)(&pos), 0))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0099ca00

namespace fnv_0099cb70 {

struct _ref_006815c0
{
    int a, b, c;
    _ref_006815c0();
};

struct Inner097
{
    int pad[4];
    _ref_006815c0* _ref_006815c0();
};

struct Member
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual _ref_006815c0* GetPos();
};

struct EffectSetting
{
};

struct ActorCombatGroup
{
};

struct Arr_006cee30
{
};

struct FUN_0099cb70_struct
{
    char pad0[0x1c4];
    EffectSetting* field_1C4;

    void CollectCastSoundPositions(Arr_006cee30* array);
};

// @fnv 0x0099cb70
void FUN_0099cb70_struct::CollectCastSoundPositions(Arr_006cee30* array)
{
    ActorCombatGroup* group = ((::fnv_0099cb70::ActorCombatGroup *)(reinterpret_cast<::EffectSetting *>((field_1C4))->GetCastSound()));
    unsigned int count = ::FUN_005a4320((char *)(group));
    reinterpret_cast<::FUN_006cee30_Class *>((array))->FUN_006cee30(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        Member* member = ((::fnv_0099cb70::Member *)(reinterpret_cast<::FUN_00968630_stub *>((group))->FUN_00968630(i)));
        Inner097 loc;
        reinterpret_cast<::FUN_0097ede0_cls *>(&(loc))->FUN_0097ede0();
        _ref_006815c0 pos;
        if (reinterpret_cast<::ResultQuery *>((group))->TryGetQuadForState(i, (::ResultQuad *)(::fnv_0099cb70::Inner097 *)(&loc), ::DAT_01017718))
        {
            pos = *loc._ref_006815c0();
        }
        else
        {
            pos = *member->GetPos();
        }
        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((array))->AddItem((*(const ::fnv_0049f210::NiPoint3 *)(&pos)));
    }
}
}  // namespace fnv_0099cb70

namespace fnv_009a02a0 {
struct CoordinateTriple
{
    double FUN_00527a40(CoordinateTriple*);
};

struct LocationTarget
{
    unsigned char type;
    char pad[7];
    CoordinateTriple location;
};

struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
};

struct FUN_009a02a0_struct : ABD_005f92d0
{
    char pad0[0xc4];
    LocationTarget* pAssociatedObject;

    bool HasItemWithinRadius(const CoordinateTriple& loc, float f);

    bool FUN_009a02a0(const CoordinateTriple& arWorldLocation, bool abCheckLocationReachable,
                      bool abIgnoreCombatAreaCheck);
};

// @fnv 0x009a02a0
bool FUN_009a02a0_struct::FUN_009a02a0(const CoordinateTriple& arWorldLocation, bool abCheckLocationReachable,
                                       bool abIgnoreCombatAreaCheck)
{
    if (pAssociatedObject)
    {
        if ((pAssociatedObject->type == 1 && !reinterpret_cast<::TESActorBaseData *>((void *)this)->GetFlag(0x100)) || pAssociatedObject->type == 2 ||
            (pAssociatedObject->type == 3 && !abIgnoreCombatAreaCheck))
        {
            float fmaxDistance = reinterpret_cast<::fnv_009a0be0::FUN_009a0be0_Class *>(this)->GetIdleAdjustedValue();
            if (((CoordinateTriple&)arWorldLocation).FUN_00527a40(&pAssociatedObject->location) >
                fmaxDistance * fmaxDistance)
            {
                return false;
            }
        }
    }
    if (abCheckLocationReachable && HasItemWithinRadius(arWorldLocation, -1.0f))
    {
        return false;
    }
    return true;
}
}  // namespace fnv_009a02a0

namespace fnv_009a0470 {
struct StageHolder
{
};

struct CombatCoverPointData;

struct FUN_009d6c80_shell
{
};

struct FUN_006d3370_s
{
    ~FUN_006d3370_s();
};

struct FUN_009a0470_shell : FUN_009d6c80_shell
{
    void ReleaseStageHolder(bool);
};

// @fnv 0x009a0470
void FUN_009a0470_shell::ReleaseStageHolder(bool bParam)
{
    if (*(void**)((char*)this + 0xe8))
    {
        if (bParam)
        {
            reinterpret_cast<::fnv_009a0d00::FUN_009a0d00_shell *>(this)->StoreEntry((const void *)(*(int*)(*(char**)((char*)this + 0xe8) + 0x68)));
        }
        if (reinterpret_cast<::FUN_005dc960_shell *>((((StageHolder*)*(void**)((char*)this + 0xe8))))->FUN_005dc960())
        {
            reinterpret_cast<::fnv_009a05b0::FUN_009a05b0_shell *>(this)->FUN_009a05b0((::fnv_009a05b0::StageHolder *)(::fnv_009a0470::CombatCoverPointData *)((CombatCoverPointData*)*(void**)((char*)this + 0xe8)));
        }
        delete (FUN_006d3370_s*)*(void**)((char*)this + 0xe8);
        *(void**)((char*)this + 0xe8) = 0;
    }
}
}  // namespace fnv_009a0470

namespace fnv_009a06c0 {
void* __cdecl operator new(unsigned int);

struct TESObjectREFRHelper
{
};

struct SL
{
    TESObjectREFRHelper* field_0;
    int field_4;
    SL();
};

struct FUN_00981340_shell
{
};

struct FUN_009a06c0_struct : FUN_00981340_shell
{
    char pad0[0x190];
    SL* array_190[1];

    void SetArrayEntry(int arg1, TESObjectREFRHelper* arg2, int arg3);
};

// @fnv 0x009a06c0
void FUN_009a06c0_struct::SetArrayEntry(int aiIndex, TESObjectREFRHelper* apRefr, int aiValue)
{
    reinterpret_cast<::FUN_00981340_shell *>(this)->FreeSlot(aiIndex);
    if (apRefr)
    {
        array_190[aiIndex] = new SL();
        array_190[aiIndex]->field_0 = apRefr;
        array_190[aiIndex]->field_4 = aiValue;
        if (apRefr)
        {
            reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((apRefr))->FUN_00564db0(true);
        }
    }
}
}  // namespace fnv_009a06c0

namespace fnv_009a0c50 {

struct Setting_S
{
};

struct CameraShotHelper
{
};

struct TESAmmoInitCalls
{
};

struct FUN_00980070_shell : TESAmmoInitCalls
{
};

struct FieldC4
{
    unsigned char byte0;
};

struct Ref_997440
{
};

struct Local18
{
    int data[4];
};

struct FUN_009a0c50_class
{
    char pad0[0xc4];
    FieldC4* field_C4;
    char padC8[0x1c4 - 0xc8];
    FUN_00980070_shell* field_1C4;

    void FUN_009a0910(int);
    void UpdateModifierState(bool arg_8);
};

// If field_C4 is null or its byte0 is 3 and arg_8 is set, computes a modifier value and applies it via FUN_009a0910 when it exceeds _gModifierZero.
// @fnv 0x009a0c50
void FUN_009a0c50_class::UpdateModifierState(bool arg_8)
{
    if (field_C4)
    {
        if (field_C4->byte0 != 3 || !arg_8)
        {
            return;
        }
    }
    float f = reinterpret_cast<::FUN_00507b00Class *>((((::fnv_009a0c50::CameraShotHelper *)(reinterpret_cast<::FUN_00980070_shell *>((field_1C4))->FUN_00980070()))))->GetField4C();
    if (f > ::_DAT_01012060)
    {
        Ref_997440* pRef = (Ref_997440*)((void *)(::GetFieldBC((::FUN_0097ae90_Class *)(field_1C4))));
        {
            Local18 localData;
            FUN_009a0910(((int)(reinterpret_cast<::FUN_00575650_Class *>((pRef))->FUN_00575650((::FUN_00575650_Result *)(void *)(&localData)))));
        }
    }
}
}  // namespace fnv_009a0c50

namespace fnv_009a0d70 {
struct CTSHelper
{
};

struct ArrSI
{
};

struct FUN_00844160_shell
{
};

struct ActorAvoidanceDataArray
{
};

struct FUN_009a0d70_shell
{
    bool ContainsItem(void* apItem);
};

// Scans the array at offset 0x164, removing entries whose elapsed time exceeds 10.0, and returns true if any remaining entry's pointer equals apItem.
// @fnv 0x009a0d70
bool FUN_009a0d70_shell::ContainsItem(void* apItem)
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x164))))->GetName())); ++i)
    {
        void* entry = (void*)reinterpret_cast<::FUN_00844160_shell *>((((FUN_00844160_shell*)((char*)this + 0x164))))->FUN_00844160(i);
        if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)entry + 4))))->FUN_00435e00() > 10.0)
        {
            reinterpret_cast<::ActorAvoidanceDataArray *>((((ActorAvoidanceDataArray*)((char*)this + 0x164))))->FUN_00983720(i, 1);
            --i;
            continue;
        }
        if (*(void**)entry == apItem)
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009a0d70

namespace fnv_009a0e10 {
struct CTSHelper
{
};

struct ArrSI
{
};

struct FUN_00844160_entry
{
    void* item;
    CTSHelper timer;
};

struct FUN_00844160_shell : ArrSI
{
};

struct ActorAvoidanceDataArray : FUN_00844160_shell
{
};

struct HArr
{
};

template <typename T, int N> struct BSSimpleArray;

template <> struct BSSimpleArray<void*, 1024> : HArr
{
};

struct FUN_009a0e10_shell
{
    char pad[0x164];
    ActorAvoidanceDataArray avoidanceData;

    void CollectAvoidanceItems(BSSimpleArray<void*, 1024>* apArray);
};

// Removes avoidance entries whose timer exceeds 10 seconds and adds the remaining entries' items to the array.
// @fnv 0x009a0e10
void FUN_009a0e10_shell::CollectAvoidanceItems(BSSimpleArray<void*, 1024>* apArray)
{
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>((apArray))->FUN_0084b5c0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(avoidanceData))->GetName())));
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(avoidanceData))->GetName())); ++i)
    {
        FUN_00844160_entry* entry = ((::fnv_009a0e10::FUN_00844160_entry *)(reinterpret_cast<::FUN_00844160_shell *>(&(avoidanceData))->FUN_00844160(i)));
        if (reinterpret_cast<::FUN_00435e00_t *>(&(entry->timer))->FUN_00435e00() > 10.0)
        {
            reinterpret_cast<::ActorAvoidanceDataArray *>(&(avoidanceData))->FUN_00983720(i, 1);
            --i;
            continue;
        }
        reinterpret_cast<::FUN_00438690 *>((apArray))->FUN_007cb2e0((unsigned int *)&(entry->item));
    }
}
}  // namespace fnv_009a0e10

namespace fnv_009a0f40 {

struct CoordinateTriple
{
    double FUN_00527a40(const CoordinateTriple*);
};

struct CTSHelper
{
};

struct Item : CoordinateTriple
{
    char pad[0x10];
    CTSHelper time;
};

struct ArrSI
{
};

struct MyArr : ArrSI
{
    Item* FUN_006dad90(unsigned int) const;
};

struct FUN_009a0f40_struct
{
    char pad0[0x174];
    MyArr array_174;

    bool HasItemWithinRadius(const CoordinateTriple* arWorldLocation, float afRadius);
};

// @fnv 0x009a0f40
bool FUN_009a0f40_struct::HasItemWithinRadius(const CoordinateTriple* arWorldLocation, float afRadius)
{
    float maxDistSq = 0.0f;
    if (afRadius == -1.0)
    {
        maxDistSq = runtimeFloatSettingDefault1296;
    }
    else
    {
        maxDistSq = afRadius * afRadius;
    }

    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(array_174))->GetName())); ++i)
    {
        Item* item = array_174.FUN_006dad90(i);
        if (reinterpret_cast<::FUN_00435e00_t *>(&(item->time))->FUN_00435e00() > 10.0)
        {
            reinterpret_cast<::FUN_0098f1f0_Class *>(&(array_174))->RemoveEntries(i, 1);
            --i;
            continue;
        }
        if (item->FUN_00527a40(arWorldLocation) < maxDistSq)
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009a0f40

struct BGSSaveFormBuffer
{
};

struct Member14
{
    virtual void SaveGame(BGSSaveFormBuffer*);
};

struct FUN_00982c20
{
    void Save(BGSSaveFormBuffer*);
};

struct FUN_009a2de0_struct
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    char data8[12];
    Member14 member14;
    char pad18[0x68 - 0x14 - sizeof(Member14)];
    int dword68;
    int dword6c;
    FUN_00982c20 member70;

    void FUN_009a2de0(BGSSaveFormBuffer* buffer);
};

// Serializes byte1, byte0, byte2, dword4, data8, member14, dword68, dword6c and member70 into the save buffer.
// @fnv 0x009a2de0
void FUN_009a2de0_struct::FUN_009a2de0(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&byte1, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&byte0, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&byte2, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&dword4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(data8, 12, 0);
    member14.SaveGame(buffer);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&dword68, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&dword6c, 4, 0);
    member70.Save(buffer);
}

namespace fnv_009a2ea0 {
struct BGSLoadFormBuffer
{
};

struct Member14
{
    virtual void unk0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};

struct Member70
{
};

struct FUN_009a2ea0_struct
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    char data8[12];
    Member14 member14;
    char pad18[0x68 - 0x14 - sizeof(Member14)];
    int dword68;
    int dword6c;
    Member70 member70;

    void FUN_009a2ea0(BGSLoadFormBuffer* buffer);
};

// Reads byte1, byte0, byte2, dword4, data8, dword68 and dword6c from the buffer and calls member14.LoadGame and member70.FUN_00982ca0.
// @fnv 0x009a2ea0
void FUN_009a2ea0_struct::FUN_009a2ea0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&byte1), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&byte0), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&byte2), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&dword4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(data8), 12);
    member14.LoadGame(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&dword68), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&dword6c), 4);
    reinterpret_cast<::FUN_00982ca0_Class *>(&(member70))->FUN_00982ca0((::BGSLoadFormBuffer *)(buffer));
}
}  // namespace fnv_009a2ea0

namespace fnv_009a3610 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0072ba80_shell
{
};
struct UCL_009a3610
{
    unsigned int m_uiData;
    char pad[0x10];
};
struct FUN_009a3610_arr
{
    virtual void v0();
    virtual UCL_009a3610* Allocate(unsigned int);
    UCL_009a3610* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void FUN_009a3610(unsigned int aiNewSize, bool abFreeMemory);
};
// @fnv 0x009a3610
void FUN_009a3610_arr::FUN_009a3610(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(abFreeMemory);
    }
    else if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_009a3c50_cls *>(this)->UpdateThreat(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }
        reinterpret_cast<::E9A3A80Allocator *>(this)->ConstructEntries((::E9A3A80Entry *)(::fnv_009a3610::UCL_009a3610 *)(&pBuffer[iSize]), aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((((FUN_0072ba80_shell*)this)))->FUN_0072ba80(&pBuffer[aiNewSize], iSize - aiNewSize);
        iSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= SimpleArrayStorage >> 2)
        {
            reinterpret_cast<::FUN_009a3c50_cls *>(this)->UpdateThreat(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        reinterpret_cast<::E9A3A80Allocator *>(this)->ConstructEntries((::E9A3A80Entry *)(::fnv_009a3610::UCL_009a3610 *)(&pBuffer[iSize]), aiNewSize - iSize);
        iSize = aiNewSize;
    }
}
}  // namespace fnv_009a3610

struct TESObjectWEAP;


struct ActH2
{
    void* GetActiveWeapon();
};

struct S981990
{
public:
    bool FUN_00981990();
};

// @fnv 0x009a9630
bool FUN_009a9630(void* apActor)
{
    TESObjectWEAP* weapon = 0;
    void* pcombatController = (*(void*(**)(void*))(*(char**)apActor + 0x428))(apActor);
    if (pcombatController)
    {
        weapon = (TESObjectWEAP*)FUN_007031c0((int)pcombatController);
    }
    else
    {
        weapon = (TESObjectWEAP*)((ActH2*)apActor)->GetActiveWeapon();
    }

    if (!weapon || ::FUN_006450c0(weapon))
    {
        return true;
    }

    if (pcombatController &&
        (reinterpret_cast<::CombatPlan *>((((S981990*)pcombatController)))->FUN_00981940(7) || reinterpret_cast<::CombatPlan *>((((S981990*)pcombatController)))->FUN_00981940(8)))
    {
        return true;
    }

    return false;
}

namespace fnv_009a0910 {
struct FUN_009a0a40_shell;
struct FUN_009a08d0_Cls;

struct FUN_009a0910_Vector
{
    float x;
    float y;
    float z;
    float w;
};


unsigned int _data_011c16bc;

struct Setting_S
{
};

struct GameSettingCollection
{
};

template <class T> struct SettingT : public Setting_S
{
};


struct FUN_009a08d0_Cls
{
    unsigned char flag;
    int field4;
    FUN_009a0910_Vector value;
    float value18;
    float value1c;

    FUN_009a08d0_Cls();
};

struct FUN_009a0910_shell
{
    unsigned char padding[0xc4];
    FUN_009a08d0_Cls* fieldC4;

    void FUN_009a0910(FUN_009a0910_Vector* value, unsigned char flag, float value10, float value14);
};

// Calls FreeAndClearFieldC4, allocates a FUN_009a08d0_Cls into fieldC4 and stores the flag, vector, and two clamped float values.
// @fnv 0x009a0910
void FUN_009a0910_shell::FUN_009a0910(FUN_009a0910_Vector* apVector, unsigned char flag, float value10, float value14)
{
    ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)(::fnv_009a0910::FUN_009a0a40_shell *)(reinterpret_cast<FUN_009a0a40_shell*>(this)));

    fieldC4 = new FUN_009a08d0_Cls;

    fieldC4->flag = flag;
    fieldC4->field4 = 0;
    fieldC4->value = *apVector;

    fieldC4->value18 = ::FUN_00404010(value10, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009a0910::SettingT< ::fnv_009a0910::GameSettingCollection> *>(&::originalRuntimeFloatSetting423)))))));
    fieldC4->value1c = ::FUN_00404010(value14, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009a0910::SettingT< ::fnv_009a0910::GameSettingCollection> *>(&::originalRuntimeFloatSetting423)))))));
}
}  // namespace fnv_009a0910

namespace fnv_009a3480 {
struct Actor
{
    unsigned int field_0;
    unsigned int field_4;
};

struct BSSimpleArrayActor
{
    virtual void FUN_00000000() = 0;
    virtual Actor* Allocate(unsigned int count) = 0;

    void Clear(bool clear);
    Actor* m_buffer;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
};

struct FUN_0072ba80_shell : public BSSimpleArrayActor
{
};

struct S5460 : public FUN_0072ba80_shell
{
    void FUN_009a3480(unsigned int count, bool clear);
};

// @fnv 0x009a3480
void S5460::FUN_009a3480(unsigned int count, bool clear)
{
    if (count == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(clear);
    }
    else if (count > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_buffer = Allocate(count);
            m_pRayCursor = count;
        }
        else
        {
            reinterpret_cast<::StandIn *>(this)->FUN_006a2770(count, m_iElementCount);
            m_pRayCursor = count;
        }

        reinterpret_cast<::FUN_009a3950_Class *>(this)->ConstructObjects((::FUN_009a3d90 *)(::fnv_009a3480::Actor *)(m_buffer + m_iElementCount), count - m_iElementCount);
        m_iElementCount = count;
    }
    else if (count < m_iElementCount)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80((char*)(m_buffer + count), m_iElementCount - count);
        m_iElementCount = count;

        if (clear && count <= (m_pRayCursor >> 2))
        {
            reinterpret_cast<::StandIn *>(this)->FUN_006a2770(count, count);
            m_pRayCursor = count;
        }
    }
    else
    {
        reinterpret_cast<::FUN_009a3950_Class *>(this)->ConstructObjects((::FUN_009a3d90 *)(::fnv_009a3480::Actor *)(m_buffer + m_iElementCount), count - m_iElementCount);
        m_iElementCount = count;
    }
}
}  // namespace fnv_009a3480

struct CombatTimer999260
{
};
struct ValueSource999260
{
};
struct CombatController999260
{
};
struct FloatSetting999260
{
};

struct FUN_00999260_shell
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
    unsigned int iFlags;
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    CombatController999260* pController;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    CombatTimer999260 timer1e4;
    int unk1e8;
    CombatTimer999260 timer1ec;
    void UpdateCombatFlags();
};

// Refreshes the two combat timers when expired and sets iFlags bits from the runtime float setting and the controller's value source.
// @fnv 0x00999260
void FUN_00999260_shell::UpdateCombatFlags()
{
    int iActor = ::GetFieldBC((::FUN_0097ae90_Class *)(pController));
    if (reinterpret_cast<::TimeoutTimer *>(&(timer1e4))->CheckTimer())
    {
        iFlags &= 0xffff00ff;
        if (RandomBoolean(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting999260 *>(&::originalRuntimeFloatSetting357))))))))
        {
            iFlags |= 0x100;
        }
        reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1e4))->FUN_008d7f40(::DAT_0101712c);
    }
    if (reinterpret_cast<::TimeoutTimer *>(&(timer1ec))->CheckTimer())
    {
        iFlags &= 0xffffff00;
        float fValue = ::GetFloatAtOffset1C((char *)(((::ValueSource999260 *)(reinterpret_cast<::FUN_00980070_shell *>((pController))->FUN_00980070()))));
        if (RandomBoolean(fValue / 100.0))
        {
            iFlags |= 1;
        }
        if (fValue > ::_DAT_01012060)
        {
            iFlags |= 2;
        }
        reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1ec))->FUN_008d7f40(::DAT_01017b78);
    }
}

// Menu event hook: on event 15 forward the argument to the active list, and refresh when the
// tracked item's id matches the event id.

class AA10List
{
  public:
};

class AA10Source
{
  public:
};

class AA10Item
{
  public:
};

class AA10Menu
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    AA10Item* m_pkTrackedItem;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    AA10Source* m_pkSource;

    void HandleMenuEvent(int iArg, unsigned int uiEvent);
};

// Handles event 15 by forwarding iArg to the source list, and refreshes when the tracked item's ID equals uiEvent.
// @fnv 0x0099aa10
void AA10Menu::HandleMenuEvent(int iArg, unsigned int uiEvent)
{
    switch (uiEvent)
    {
    case 15:
        reinterpret_cast<::ProximityGroup *>((((::AA10List *)(reinterpret_cast<::EffectSetting *>((m_pkSource))->GetCastSound()))))->UpdateProximityTimers((void *)(iArg));
        break;
    }

    if (m_pkTrackedItem)
    {
        unsigned int uiItemID = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((m_pkTrackedItem))->FUN_00825c00();
        if (uiItemID == uiEvent)
            reinterpret_cast<::FUN_009a0680_shell *>(this)->ClearAndDeletePointer();
    }
}

struct Pt3
{
    float x, y, z;
    Pt3();
    Pt3 operator-(const Pt3& o) const;
};

struct Seg99
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
    Pt3 start;
    Pt3 end;
};

struct Timer99
{
};


struct Combat99
{
    char unk000;
    char unk001;
    char unk002;
    char unk003;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    Timer99* pTimer;
    bool FUN_0099cec0(Seg99* apSeg, Pt3* apFrom, Pt3* apTarget, TESObjectREFR* apRef);
};

// @fnv 0x0099cec0
bool Combat99::FUN_0099cec0(Seg99* apSeg, Pt3* apFrom, Pt3* apTarget, TESObjectREFR* apRef)
{
    float fTop3 = FUN_0040ebd0(apSeg->start.z, apSeg->end.z);
    if (apTarget->z >= fTop3)
    {
        return false;
    }
    else
    {
        Pt3 kTarget4 = *apTarget;
        kTarget4.z += ::GetScaleOrHeightDelta(apRef, 1);
        if (kTarget4.z >= fTop3)
        {
            return false;
        }
        else
        {
            Pt3 kHit3;
            bool bHitB = ::FUN_006ba6e0((*(const ::ns6b::V3 *)(&apSeg->start)), (*(const ::ns6b::V3 *)(&apSeg->end)), (*(const ::ns6b::V3 *)(&kTarget4)), (*(const ::ns6b::V3 *)(apFrom)), (::ns6b::V3 *)(::Pt3 *)(&kHit3));
            if (!bHitB)
                return false;
            float m_fGlyphExtent = kHit3.z - kTarget4.z;
            Pt3 kDiff9 = kHit3 - kTarget4;
            float fDist6 = reinterpret_cast<::FUN_00589850_Class *>(&(kDiff9))->FUN_00589850();
            Pt3 kDiffVal = kHit3 - *apFrom;
            float fLen2 = reinterpret_cast<::FUN_00589850_Class *>(&(kDiffVal))->FUN_00589850();
            float fScaledTmp = m_fGlyphExtent * fLen2 / fDist6;
            float fLimit3 = reinterpret_cast<::FUN_00998a30_shell *>((pTimer))->FUN_00998a30() ? reinterpret_cast<::FUN_00453700_shell *>((pTimer))->FUN_00453700() : reinterpret_cast<::FUN_004536e0_Class *>((pTimer))->GetFieldCC();
            if (fLimit3 > fScaledTmp)
                return false;
        }
    }
    return true;
}

struct PosHolder;
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3* Self();
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator+(const Vec3& o) const;
    Vec3 operator*(float s) const;
    Vec3 Cross(const Vec3& o) const;
};

struct MyTimer
{
    float t;
    MyTimer(float v);
    MyTimer(const MyTimer& o);
};

struct Picker
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    Picker(void* p);
    Picker();
    ~Picker();
    Vec3 GetPoint();
};

struct MyMover
{
};

struct MyActor
{
    virtual void v0();
    float FUN_008be1b0();
};

struct MyRef
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual Vec3* GetPos();
};

struct MyProc
{
};

struct PosHolder
{
    float unk00, unk04, unk08;
    int unk0C;
    Vec3* Self();
};

struct Result
{
    float EvaluateThreats();
};

struct Mgr
{
};

bool FUN_006d7490(Picker* a, Vec3* b, Picker* c, int d);

struct FUN_0099e190_cls
{
    char unk000[0x184];
    MyTimer timer;
    signed char last;
    char pad189[0x1c4 - 0x189];
    MyProc* proc;
    bool FUN_009a0260(Vec3* v, int x);
    bool SelectAndMoveToPoint(MyMover* mover, unsigned int mask1, unsigned int mask2, float dist, float minDist);
};

// Tests up to four candidate points around the actor against masks and distance limits, then moves the mover to a chosen valid point.
// @fnv 0x0099e190
bool FUN_0099e190_cls::SelectAndMoveToPoint(MyMover* mover, unsigned int mask1, unsigned int mask2, float dist,
                                            float minDist)
{
    MyActor* A9 = ((::MyActor *)(::GetFieldBC((::FUN_0097ae90_Class *)(proc))));
    MyRef* ref = ((::MyRef *)(reinterpret_cast<::AlchemyItem *>((proc))->FUN_004030b0()));
    float radius = A9->FUN_008be1b0() + 8.0;
    PosHolder h7;
    reinterpret_cast<::FUN_00575650_Class *>((A9))->FUN_00575650((::FUN_00575650_Result *)(::PosHolder *)(&h7));
    Vec3 pp = *new ((void *)&(h7)) ::Vec3();
    Vec3 T = *ref->GetPos();
    Picker p4(A9);
    Vec3 D_ = pp - T;
    reinterpret_cast<::FUN_004a0c10_s *>(&(D_))->FUN_004a0c10();
    Vec3 s = D_.Cross((*reinterpret_cast<::Vec3 *>((void *)&::DAT_011a9484)));
    Vec3 A5[4];
    signed char slot[4];
    signed char dirOf[4];
    int n = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        slot[i] = -1;
        unsigned int bit = 1 << i;
        if (mask1 & bit)
        {
            Vec3 off;
            switch (bit)
            {
            case 1:
                off = s;
                break;
            case 2:
                off = (*(::Vec3 *)(reinterpret_cast<::P3 *>((void *)&(s))->FUN_004a0bd0({})));
                break;
            case 4:
                off = (*(::Vec3 *)(reinterpret_cast<::P3 *>((void *)&(D_))->FUN_004a0bd0({})));
                break;
            case 8:
                off = D_;
                break;
            }
            Vec3 target = pp + off * dist;
            Vec3 end = target + off * radius;
            if (((::Result *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::Mgr * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))->EvaluateThreats() > 0.0)
                continue;
            Picker hit;
            if (!FUN_006d7490(&p4, &end, &hit, 0))
            {
                if (minDist < dist)
                {
                    Vec3 diff3 = pp - (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>(&(hit))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
                    float len = reinterpret_cast<::FUN_00589850_Class *>((void *)&(diff3))->FUN_00589850();
                    if (minDist > len - radius)
                        continue;
                    target = pp + off * (len - radius);
                }
                else
                {
                    continue;
                }
            }
            if (mask2 & bit)
            {
                if (!::FUN_009a7940((::SightReference *)(A9), (::SightReference *)(ref), (*(const ::NiPoint3 *)(&target)), (*(const ::NiPoint3 *)(&T)), 0, -1))
                    continue;
            }
            if (!FUN_009a0260(&target, reinterpret_cast<::FUN_0084e3a0_Class *>(&(h7))->FUN_0084e3a0()))
                continue;
            A5[n] = target;
            slot[i] = n;
            dirOf[n] = i;
            n++;
        }
    }
    if (n == 0)
        return false;
    if (last != -1 && reinterpret_cast<::FUN_00435e00_t *>(&(timer))->FUN_00435e00() < 10.0 && slot[last] != -1)
    {
        reinterpret_cast<::FUN_0099b8b0_shell *>((mover))->FUN_0099b8b0((int)(&A5[slot[last]]), 0);
        return true;
    }
    int aK = ((int)(::FUN_005a00a0(n)));
    last = dirOf[aK];
    timer = FUN_00435dd0();
    reinterpret_cast<::FUN_0099b8b0_shell *>((mover))->FUN_0099b8b0((int)(&A5[slot[last]]), 0);
    return true;
}

struct TargetPosition
{
    float x, y, z;
    unsigned space;
};
struct TargetRef
{
};
struct TargetParameters
{
    unsigned char flag;
    TargetRef* reference;
    TargetPosition position;
    float nearRange, farRange;
    TargetParameters();
};
struct TargetSetting
{
};
struct TargetWork
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    TargetParameters* parameters;
    void FUN_009a0790(TargetRef*, unsigned char, float, float);
};
// @fnv 0x009a0790
void TargetWork::FUN_009a0790(TargetRef* reference, unsigned char flag, float nearRange, float farRange)
{
    ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)this);
    if (!reference)
        return;
    parameters = new TargetParameters;
    parameters->flag = flag;
    parameters->reference = reference;
    parameters->position = (*(::TargetPosition *)(reinterpret_cast<::FUN_00575650_Class *>((reference))->FUN_00575650({})));
    parameters->nearRange = FUN_00404010(nearRange, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TargetSetting *>(&::originalRuntimeFloatSetting423)))))));
    parameters->farRange = FUN_00404010(farRange, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TargetSetting *>(&::originalRuntimeFloatSetting423)))))));
}

class TESForm
{
  public:
    virtual void v0();
public:
    void ClearData();
};

class ExtraRadioData;
class TESObjectREFR : public TESForm
{
  public:
    virtual void v1();
public:
    ::ExtraRadioData *GetExtraRadioData();
public:
    float GetBoundingRadius();
};


class FUN_009a3220_cls
{
  public:
    char unk00[4];
    TESObjectREFR* m_04;
    void FUN_009a3220(int unkArg);
};

// Re-resolves m_04 through FUN_004839c0 and dynamic_cast to TESObjectREFR, or clears it to null when m_04 is null.
// @fnv 0x009a3220
void FUN_009a3220_cls::FUN_009a3220(int unkArg)
{
    m_04 = m_04 != 0 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(m_04))) : 0;
}

struct ElementProxy
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
};
struct ArrayProxy
{
    virtual void unused();
    virtual ElementProxy* Allocate(unsigned int);
    ElementProxy* data;
    unsigned int size, capacity;
    void FUN_009a32a0(unsigned int, bool);
};
// Calls FUN_009a32a0 with cnt and 1, then for each of cnt elements calls FUN_009052c0(i, &arr[i]) and FUN_006e4430 on the result.
// @fnv 0x009a3780
void Host::ProcessElements(Helper* apHelper)
{
    reinterpret_cast<::ArrayProxy *>((apHelper))->FUN_009a32a0(cnt, 1);
    for (unsigned int i = 0; i < cnt; ++i)
    {
        reinterpret_cast<::FUN_006e4430_class *>((((::RetObj *)(reinterpret_cast<::FUN_009052c0_shell *>((apHelper))->FUN_009052c0(i)))))->operator=(*(const ::FUN_006e4430_class *)nullptr);
    }
}
// Grows, shrinks or clears the array to count elements, reallocating storage when needed and optionally shrinking capacity.
// @fnv 0x009a32a0
void ArrayProxy::FUN_009a32a0(unsigned int count, bool shrink)
{
    if (count == 0)
    {
        reinterpret_cast<::NavMeshSearchLOSArray *>(this)->FUN_006dbde0(shrink);
    }
    else if (count > capacity)
    {
        if (capacity == 0)
        {
            data = Allocate(count);
            capacity = count;
        }
        else
        {
            reinterpret_cast<::FUN_006dbfc0_Class *>(this)->FUN_006dbfc0((char *)(count), size);
            capacity = count;
        }
        reinterpret_cast<::fnv_006dbe40::FUN_006dbe40_Class *>(this)->ConstructInPlace((::fnv_006dbe40::FUN_006d3200 *)(::ElementProxy *)(data + size), count - size);
        size = count;
    }
    else if (count < size)
    {
        reinterpret_cast<::FUN_006dbee0_s *>(this)->FUN_006dbee0((::Elem *)(::ElementProxy *)(data + count), size - count);
        size = count;
        if (shrink && count <= (capacity >> 2))
        {
            reinterpret_cast<::FUN_006dbfc0_Class *>(this)->FUN_006dbfc0((char *)(count), count);
            capacity = count;
        }
    }
    else
    {
        reinterpret_cast<::fnv_006dbe40::FUN_006dbe40_Class *>(this)->ConstructInPlace((::fnv_006dbe40::FUN_006d3200 *)(::ElementProxy *)(data + size), count - size);
        size = count;
    }
}

struct LocS
{
    int v0;
    int v4;
    int v8;
    int vC;
    float DistTo(LocS* other);
};
struct Loc2S
{
    int v0;
    int v4;
    int v8;
    int vC;
};
struct CellS
{
};
struct RefS
{
};
struct TileS
{
};
struct IfaceS
{
};
struct Sub30S
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual bool IsFlagV();
};
struct ActorBaseS
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
    Sub30S data30;
};
struct ActorS
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
    virtual bool IsDeadV();
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
    virtual IfaceS* GetIfaceV();
};
struct NodeS
{
    RefS* ref;
    void* other;
    unsigned char level;
    unsigned char flag9;
    unsigned char flagA;
};
struct NodeArrS
{
    NodeS& GetAt(int);
};
struct GlobalIntS
{
};
struct CombatNodeFinder
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    NodeArrS nodes;
    RefS* FindNearestCombatNode(ActorS* actor, float maxDist, bool checkCell);
};

// Scans nodes for a valid, in-range reference (optionally cell-checked and tile-tested) and returns the closest one to the actor, or null.
// @fnv 0x0098c3d0
RefS* CombatNodeFinder::FindNearestCombatNode(ActorS* actor, float maxDist, bool checkCell)
{
    if (actor->IsDeadV() && ((::ActorBaseS *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()))->data30.IsFlagV())
        return 0;
    IfaceS* iface3 = actor->GetIfaceV();
    LocS actorLoc2 = (*(::LocS *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})));
    RefS* bestX = 0;
    float bestDist5 = maxDist * maxDist;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(nodes))->GetName())); i++)
    {
        NodeS& node5 = nodes.GetAt(i);
        if (!node5.ref || !node5.other)
            continue;
        if (node5.level > *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalIntS *>(&::g_011cfc98)))))) || node5.flagA || node5.flag9)
            continue;
        CellS* cell2 = ((::CellS *)(reinterpret_cast<::TESObjectREFR *>((node5.ref))->GetExtraRadioData()));
        if (!cell2)
            continue;
        if (checkCell)
        {
            Loc2S cellLoc = (*(::Loc2S *)(reinterpret_cast<::UnkThis *>((cell2))->FUN_0043a390({})));
            if (!::FUN_009a96f0((::TESObjectREFR *)(actor), (::CoordinateTriple *)(::Loc2S *)(&cellLoc)))
                continue;
        }
        LocS nodeLoc2 = (*(::LocS *)(reinterpret_cast<::FUN_00575650_Class *>((node5.ref))->FUN_00575650({})));
        if (iface3 && !reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((((::TileS *)(reinterpret_cast<::InterfaceManager *>((iface3))->FUN_00586150()))))->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&nodeLoc2)), 1, 0))
            continue;
        float dist4 = actorLoc2.DistTo(&nodeLoc2);
        if (dist4 < bestDist5)
        {
            bestX = node5.ref;
            bestDist5 = dist4;
        }
    }
    return bestX;
}

namespace fnv_00997cf0 {
struct NiPoint3Ex
{
    float x, y, z;
};
struct CombatStamp
{
    int value;
};
struct CombatWorld
{
    int a, b, c, d;
    float FUN_00527a40(const CombatWorld&);
};
struct CombatActor
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual NiPoint3Ex* GetPosition();
};
struct CombatTimers
{
    int a, b;
};
struct CombatMode
{
    unsigned char type;
    bool active;
    short unk02;
    CombatActor* actor;
    CombatWorld world;
    float nearDistance, farDistance;
};
struct CombatPackage
{
};
struct CombatMap
{
};
struct CombatOptions
{
};
struct CombatController
{
};
struct CombatPath
{
};
struct CombatPathOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    CombatPath path;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int index;
};
struct CombatHazard
{
    float EvaluateThreats(NiPoint3Ex, CombatActor*, float, float, void*, float);
};
struct CombatHazardHolder
{
};
struct CombatSetting
{
};
extern bool DAT_011f1ae4;
extern float DAT_011a5310, DAT_011a530c, DAT_011a5308;
struct CombatUpdate
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    float chaseDistance;
    int targetState;
    bool visible, detected, known;
    signed char status;
    bool differentSpace;
    unsigned char unk075;
    bool changed, updateNow;
    int unk078;
    int unk07c;
    float danger;
    NiPoint3Ex targetPosition;
    unsigned int flags;
    CombatStamp targetTime;
    CombatStamp seenTime;
    int unk09c;
    int unk0a0;
    CombatStamp idleTime;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    void* hazardData;
    CombatMode* mode;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    void* temporary;
    CombatStamp temporaryTime;
    CombatPathOwner* path;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    CombatActor* previousTarget;
    CombatController* controller;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    CombatTimers stanceTimer;
    CombatTimers pathTimer;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    CombatTimers chaseTimer;

    void FUN_00997cf0();
    void EvaluateWeaponScores();
};
// Updates the combat target, detection state, path and stance timers, mode activation, danger level and chase timer for the controller's owner.
// @fnv 0x00997cf0
void CombatUpdate::FUN_00997cf0()
{
    CombatStamp timeD3;
    CombatWorld worldB;
    CombatWorld worldAB;
    CombatStamp timeC3;
    CombatStamp timeB_1;
    CombatStamp timeA;
    CombatWorld ownLocation3;
    CombatWorld targetLocation;
    unsigned char stance;
    CombatActor* follow;
    float range_;
    NiPoint3Ex weights_26;
    float distance_1;
    bool fleeing_3;
    CombatActor* aFoundOther;
    CombatActor* found;
    CombatActor* current;
    float nearRange;
    float searchRange5;
    float farRange_5;
    CombatPackage* package2;
    int state_7;
    CombatActor* target4;
    float oldDangerX;
    void* space_41;
    CombatActor* owner_21;
    owner_21 = ((::fnv_00997cf0::CombatActor *)(::GetFieldBC((::FUN_0097ae90_Class *)(controller))));
    {
        target4 = ((::fnv_00997cf0::CombatActor *)(reinterpret_cast<::AlchemyItem *>((controller))->FUN_004030b0()));
        space_41 = ((void *)(reinterpret_cast<::s575ca0::Owner *>((owner_21))->FUN_00575ca0()));
        if (target4 && space_41 != ((void *)(reinterpret_cast<::s575ca0::Owner *>((target4))->FUN_00575ca0())))
        {
            if (!differentSpace)
            {
                if (visible)
                    reinterpret_cast<::FUN_0097f200_t *>((controller))->FUN_0097f200();
                differentSpace = true;
            }
        }
        else
            differentSpace = false;
        if (target4)
        {
            if (((bool)(reinterpret_cast<::FUN_00998a10_shell *>((controller))->GetFieldC5())) || previousTarget != target4)
            {
                state_7 = -100;
                reinterpret_cast<::CombatAssessment::Group *>((((::fnv_00997cf0::CombatMap *)(reinterpret_cast<::EffectSetting *>((controller))->GetCastSound()))))->UpdateTargetPerception((::CombatAssessment::Actor *)(owner_21), (::CombatAssessment::Actor *)(target4), &state_7, (::CombatAssessment::Time *)(::fnv_00997cf0::CombatStamp *)(&targetTime), &visible,
                                                                   &detected);
                targetState = state_7;
                reinterpret_cast<::FUN_008f6630_Class *>((controller))->SetByteAtOffsetC5(false);
            }
            if (detected)
            {
                reinterpret_cast<::FUN_00435de0_ctor *>(&(timeA))->FUN_00435de0(::FUN_00435dd0());
                seenTime = timeA;
                targetPosition = *target4->GetPosition();
                package2 = ((::fnv_00997cf0::CombatPackage *)(reinterpret_cast<::FUN_004f9bf0_shell *>((controller))->FUN_004f9bf0()));
                if (!package2 || ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((package2))->FUN_00825c00())) != 13)
                {
                    status = -1;
                    changed = false;
                }
            }
            if (detected && !known && reinterpret_cast<::CombatPlan *>((controller))->FUN_00981940(24))
                reinterpret_cast<::FUN_0097f200_t *>((controller))->FUN_0097f200();
            if (!reinterpret_cast<::fnv_00998980::FUN_00998980_shell *>(this)->FUN_00998980() && status == -1)
                status = 0;
        }
        else
        {
            targetState = -1;
            detected = false;
            reinterpret_cast<::FUN_00435de0_ctor *>(&(timeB_1))->FUN_00435de0(-::DAT_0108df70);
            targetTime = timeB_1;
            reinterpret_cast<::FUN_00435de0_ctor *>(&(timeC3))->FUN_00435de0(-::DAT_0108df70);
            seenTime = timeC3;
            status = -1;
        }
        reinterpret_cast<::FUN_0099a530_shell *>(this)->FUN_0099a530();
        if (reinterpret_cast<::FUN_0097fa50_Class *>(&(pathTimer))->FUN_0097fa50())
        {
            if (reinterpret_cast<::TimeoutTimer *>(&(pathTimer))->CheckTimer())
            {
                reinterpret_cast<::FUN_009a03d0_cls *>(this)->FUN_009a03d0(false);
                reinterpret_cast<::TimeoutTimer *>(&(pathTimer))->FUN_00910b10();
            }
        }
        else if (path && path->index != -1 && !reinterpret_cast<::FUN_006e4650_class *>(&(path->path))->FUN_006e4650(path->index))
            reinterpret_cast<::FUN_008d7f40_shell *>(&(pathTimer))->FUN_008d7f40(2.0f);
        if (DAT_011f1ae4)
        {
            if (!mode || mode->type == 2)
            {
                nearRange = DAT_011a5310;
                farRange_5 = DAT_011a530c;
                searchRange5 = DAT_011a5308;
                if (::FUN_009a9630(owner_21))
                {
                    nearRange *= 2;
                    farRange_5 *= 2;
                }
                if (farRange_5 + 256.0 > searchRange5)
                    searchRange5 = farRange_5 + 256.0;
                if (::DAT_011a4d34)
                {
                    current = 0;
                    if (mode && mode->actor && mode->actor->IsActor())
                        current = mode->actor;
                    found = ((::fnv_00997cf0::CombatActor *)(reinterpret_cast<::SearchGroup *>((((::fnv_00997cf0::CombatMap *)(reinterpret_cast<::EffectSetting *>((controller))->GetCastSound()))))->FindNearestActor((::InputActor *)(owner_21), (::OutputActor *)(current), searchRange5)));
                    if (found)
                        reinterpret_cast<::TargetWork *>(this)->FUN_009a0790((::TargetRef *)(found), 2, nearRange, farRange_5);
                    else
                        ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)this);
                }
                else
                {
                    aFoundOther = ((::fnv_00997cf0::CombatActor *)(reinterpret_cast<::FUN_0098de00_class *>((((::fnv_00997cf0::CombatMap *)(reinterpret_cast<::EffectSetting *>((controller))->GetCastSound()))))->GetFieldAtOffset16((int)(owner_21))));
                    if (aFoundOther)
                        reinterpret_cast<::fnv_009a0910::FUN_009a0910_shell *>(this)->FUN_009a0910((::fnv_009a0910::FUN_009a0910_Vector *)(aFoundOther), 2, nearRange, farRange_5);
                    else
                        ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)this);
                }
            }
        }
        else if (!DAT_011f1ae4 && mode && mode->type == 2)
            ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)this);
        if (mode)
        {
            if (mode->type == 3 && ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(mode->world))->FUN_0084e3a0())) != space_41)
                reinterpret_cast<::fnv_009a0c50::FUN_009a0c50_class *>(this)->UpdateModifierState(true);
            if (mode->actor)
                mode->world = *((::fnv_00997cf0::CombatWorld *)(reinterpret_cast<::FUN_00575650_Class *>((mode->actor))->FUN_00575650((::FUN_00575650_Result *)(::fnv_00997cf0::CombatWorld *)(&worldAB))));
            reinterpret_cast<::FUN_00416870_t *>(&(weights_26))->FUN_00416870(1.0f, 1.0f, 0.25f);
            distance_1 = reinterpret_cast<::FUN_00527ac0_shell *>(&(mode->world))->ComputeWeightedDistance((::FUN_00527ac0_shell *)&(*((::fnv_00997cf0::CombatWorld *)(reinterpret_cast<::FUN_00575650_Class *>((owner_21))->FUN_00575650((::FUN_00575650_Result *)(::fnv_00997cf0::CombatWorld *)(&worldB))))), (::P3 *)&(weights_26));
            fleeing_3 = false;
            if ((mode->type == 0 || mode->type == 1) && target4 && reinterpret_cast<::FUN_00981300_shell *>((controller))->FUN_00981300() &&
                !reinterpret_cast<::FUN_0067a700_shell *>((controller))->FUN_0067a700())
                fleeing_3 = true;
            if (fleeing_3)
                mode->active = true;
            else
            {
                if (mode->farDistance > mode->nearDistance && reinterpret_cast<::fnv_009a0a80::Host *>(this)->FUN_009a0a80())
                {
                    range_ = reinterpret_cast<::fnv_009a0b70::FUN_009a0b70_shell *>(this)->GetInterpolatedValue();
                    if (mode->active)
                    {
                        if (distance_1 > range_ * range_)
                            mode->active = false;
                    }
                    else
                    {
                        if (distance_1 < range_ * range_)
                            mode->active = true;
                    }
                }
                else
                {
                    mode->active = false;
                    if (distance_1 < mode->nearDistance * mode->nearDistance)
                        mode->active = true;
                }
            }
            switch (mode->type)
            {
            case 0:
                if (mode->active && !fleeing_3)
                {
                    ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)this);
                    reinterpret_cast<::fnv_00981380::CombatController *>((controller))->FUN_00981380();
                }
                break;
            case 1:
                if (reinterpret_cast<::FUN_00998a30_shell *>((controller))->FUN_00998a30() && mode->actor && mode->actor->IsActor())
                {
                    if (distance_1 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997cf0::CombatSetting *>(&::originalRuntimeFloatSetting414)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997cf0::CombatSetting *>(&::originalRuntimeFloatSetting414)))))))
                    {
                        follow = mode->actor;
                        stance = ((unsigned char)(reinterpret_cast<::Actor *>((follow))->IsSneaking()));
                        if (stance != ((unsigned char)(reinterpret_cast<::Actor *>((owner_21))->IsSneaking())))
                        {
                            if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(stanceTimer))->FUN_0097fa50())
                            {
                                if (follow == (*reinterpret_cast<::fnv_00997cf0::CombatActor * *>(&::_g_thePlayer)))
                                    reinterpret_cast<::FUN_008d7f40_shell *>(&(stanceTimer))->FUN_008d7f40(::RandomFloat(0.5f, 1.0f));
                                else
                                    reinterpret_cast<::FUN_008d7f40_shell *>(&(stanceTimer))->FUN_008d7f40(::RandomFloat(0.1f, 0.5f));
                            }
                            else if (reinterpret_cast<::TimeoutTimer *>(&(stanceTimer))->CheckTimer())
                            {
                                reinterpret_cast<::Dummy00981520 *>((controller))->SetFieldC7(stance);
                                reinterpret_cast<::TimeoutTimer *>(&(stanceTimer))->FUN_00910b10();
                            }
                        }
                        else
                            reinterpret_cast<::TimeoutTimer *>(&(stanceTimer))->FUN_00910b10();
                    }
                    else if (((bool)(reinterpret_cast<::FUN_009989f0_shell *>((controller))->GetByteAtOffsetC7())))
                        reinterpret_cast<::Dummy00981520 *>((controller))->SetFieldC7(0);
                }
                break;
            }
        }
        oldDangerX = danger;
        if (!reinterpret_cast<::FUN_009989d0_shell *>((((::fnv_00997cf0::CombatOptions *)(reinterpret_cast<::FUN_00980070_shell *>((controller))->FUN_00980070()))))->FUN_009989d0())
        {
            if (danger > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997cf0::CombatSetting *>(&::originalRuntimeFloatSetting481)))))) || (flags & 0x100))
            {
                danger = ((::fnv_00997cf0::CombatHazard *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00997cf0::CombatHazardHolder * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))->EvaluateThreats(*owner_21->GetPosition(), owner_21, 0, 0,
                                                                       hazardData, 0);
                if (danger >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997cf0::CombatSetting *>(&::originalRuntimeFloatSetting481)))))) && oldDangerX < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997cf0::CombatSetting *>(&::originalRuntimeFloatSetting481)))))))
                    reinterpret_cast<::FUN_0097f200_t *>((controller))->FUN_0097f200();
            }
            else
                danger = 0;
        }
        if (reinterpret_cast<::CombatTargetTimestamp *>(&(idleTime))->FUN_006a7f50() != -::DAT_0108df70 && !reinterpret_cast<::FUN_00894900_shell *>((owner_21))->FUN_00894900())
        {
            reinterpret_cast<::FUN_00435de0_ctor *>(&(timeD3))->FUN_00435de0(-::DAT_0108df70);
            idleTime = timeD3;
        }
        if (target4 && chaseDistance > 0.0)
        {
            reinterpret_cast<::FUN_00575650_Class *>((owner_21))->FUN_00575650((::FUN_00575650_Result *)(::fnv_00997cf0::CombatWorld *)(&ownLocation3));
            reinterpret_cast<::FUN_00575650_Class *>((target4))->FUN_00575650((::FUN_00575650_Result *)(::fnv_00997cf0::CombatWorld *)(&targetLocation));
            if (ownLocation3.FUN_00527a40(targetLocation) < chaseDistance * chaseDistance)
                reinterpret_cast<::FUN_0097f220_Class *>(&(chaseTimer))->FUN_0097f220();
        }
        if (updateNow || (reinterpret_cast<::FUN_0097fa50_Class *>(&(chaseTimer))->FUN_0097fa50() && reinterpret_cast<::TimeoutTimer *>(&(chaseTimer))->CheckTimer()))
            EvaluateWeaponScores();
        reinterpret_cast<::fnv_009a0c50::FUN_009a0c50_class *>(this)->UpdateModifierState(false);
        if (temporary && ((double)(reinterpret_cast<::FUN_00435e00_t *>(&(temporaryTime))->FUN_00435e00())) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997cf0::CombatSetting *>(&::originalRuntimeFloatSetting443)))))))
            temporary = 0;
        previousTarget = target4;
    }
}
}  // namespace fnv_00997cf0

struct UpdateActor
{
};
struct UpdateEffect
{
};
struct UpdateRef
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual int Query(float);
};
struct UpdateController
{
    UpdateActor* Actor();
};
struct DurationTracker
{
    int time;
    int state;
    void Clear();
};
struct UpdateArray
{
};
struct UpdateSetting
{
};
struct UpdateWorld
{
};
struct UpdateManager
{
};
struct UpdateResult
{
    int status;
    int detail;
    UpdateResult();
    ~UpdateResult();
};
struct UpdateRequest
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Poll(UpdateResult*);
};
struct UpdatePointer
{
};
struct UpdateState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    UpdateArray targets;
    int unk028;
    int unk02c;
    int unk030;
    int target;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    float threshold;
    int unk05c;
    int unk060;
    float elapsed;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int pending;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    bool notified;
    char unk0d9;
    char unk0da;
    char unk0db;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    UpdateController* controller;
    bool force;
    char unk1c9;
    char unk1ca;
    char unk1cb;
    DurationTracker timer1cc;
    DurationTracker timer1d4;
    DurationTracker timer1dc;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    DurationTracker timer204;
    DurationTracker timer20c;
    DurationTracker timer214;
    int unk21c;
    int unk220;
    UpdatePointer request;
    int requestState;
    void Changed();
    bool GetFlag(unsigned);
    void FUN_00998a50();
};
namespace CombatWeapons {
struct Actor;
struct Weapon;
struct Ammo;
struct Entry;
struct Item;
struct Controller;
struct Process;
struct Profile
{
    int value;
    Profile(int, int, const char*, int);
    ~Profile();
};
struct Point
{
    float x, y, z;
};
struct Location
{
    Point point;
    void* cell;
    float FUN_00527a40(const Location&);
};
struct Effects
{
};
struct Item
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    Effects effects;
    int FUN_00401170();
};
struct Extra
{
};
struct Extras
{
};
struct Entry
{
};
struct AmmoState
{
};
struct Animation
{
};
struct Equip
{
    unsigned int unk0, unk4, unk8;
    Equip(Ammo*, int);
};
struct Process
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
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
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual Entry* Equipped();
    virtual AmmoState* Ammunition();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void EquipAmmo(Equip*);
};
struct Projectile
{
};
struct Weapon : Item
{
};
struct InventoryIterator
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    InventoryIterator();
    ~InventoryIterator();
};
struct Inventory
{
};
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
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
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual Animation* AnimationData();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual const Point& Position();
};
struct CombatData
{
};
struct Controller
{
};
struct WeaponScore
{
    Weapon* weapon;
    float health, damage, range;
    bool inRange;
};
struct Scores
{
    unsigned int unk0, unk4, unk8, unkc;
    Scores(int, int);
    ~Scores();
    WeaponScore& FUN_006dad90(unsigned int);
};
struct Ammos
{
    unsigned int unk0, unk4, unk8, unkc;
    Ammos(int, int);
    ~Ammos();
};
struct WeaponList
{
    unsigned int unk0, unk4, unk8, unkc;
};
struct Timer
{
};
struct Setting
{
};
extern const char DAT_0108dfb0[];
extern double DAT_01017a40;
extern float DAT_0108dfac;
void FUN_009a9180(Controller*, Weapon*, float&, float&, float&);
struct System
{
};
struct Manager
{
    unsigned int unk0, unk4, unk8;
    Weapon* bestWeapons[6];
    WeaponList ranged;
    Weapon* current;
    unsigned int types;
    float categoryScore[7];
    float maxDamage, maxRanged, maxScore, unk64, maxRange;
    unsigned int unk6c, unk70;
    unsigned char unk74, unk75, unk76, flag;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    Item* aids[2];
    unsigned int unk1ac, unk1b0, unk1b4, unk1b8, aidTypes, unk1c0;
    Controller* controller;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    Timer timer;
    void FUN_0099a2a0();
    void EvaluateWeaponScores();
};
// Scans the actor's inventory for aids, weapons and ammo, scores each weapon by damage and range, fills bestWeapons/categoryScore, and updates the timer.
// @fnv 0x009993c0
void Manager::EvaluateWeaponScores()
{
    Profile profile(43, 1, DAT_0108dfb0, 838);
    Actor* actor = ((::CombatWeapons::Actor *)(::GetFieldBC((::FUN_0097ae90_Class *)(controller))));
    Actor* target = ((::CombatWeapons::Actor *)(reinterpret_cast<::AlchemyItem *>((controller))->FUN_004030b0()));
    CombatData* dataSlot17 = ((::CombatWeapons::CombatData *)(reinterpret_cast<::FUN_00980070_shell *>((controller))->FUN_00980070()));
    float distance = 0.0f;
    if (target)
    {
        Location sourcePointSlot0 = (*(::CombatWeapons::Location *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})));
        Location targetPointSlot14 = (*(::CombatWeapons::Location *)(reinterpret_cast<::FUN_00575650_Class *>((target))->FUN_00575650({})));
        distance = sourcePointSlot0.FUN_00527a40(targetPointSlot14);
    }
    FUN_0099a2a0();
    flag = 0;
    maxDamage = 0.0f;
    maxRanged = 0.0f;
    maxScore = 0.0f;
    maxRange = 0.0f;
    types = 0;
    aidTypes = 0;
    ::FUN_00403d30(categoryScore, 0, 28);
    ::FUN_00403d30(aids, 0, 8);
    float aidScoresSlot19[2];
    ::FUN_00403d30(aidScoresSlot19, 0, 8);
    Scores scoresSlot20(32, 0);
    Ammos ammosSlot1(32, 0);
    Entry* entry = 0;
    InventoryIterator iteratorSlot1;
    Inventory* inventorySlot40 = ((::CombatWeapons::Inventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(actor))));
    while (reinterpret_cast<::InventoryIterOwner *>((inventorySlot40))->AdvanceInventoryIterator((::IterState *)(::CombatWeapons::InventoryIterator *)(&iteratorSlot1), (void **)(::CombatWeapons::Entry **)(&entry), 0))
    {
        Item* item = ((::CombatWeapons::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName()));
        switch (item->FUN_00401170())
        {
        case 47: {
            Item* aid = item;
            for (unsigned int n = 0; n < 2; n++)
            {
                float scoreSlot25 = 0.0f;
                unsigned int effect = n + 17;
                switch (effect)
                {
                case 17:
                    scoreSlot25 = reinterpret_cast<::EffectList405c *>(&(aid->effects))->FUN_00405c00(0, 0, 16);
                    scoreSlot25 += reinterpret_cast<::EffectList405c *>(&(aid->effects))->FUN_00405c00(34, 0, 16);
                    break;
                case 18:
                    if (!reinterpret_cast<::fnv_009928c0::CombatFlagHolder *>((dataSlot17))->HasCombatFlag(256))
                        scoreSlot25 = reinterpret_cast<::EffectList405c *>(&(aid->effects))->FUN_00405c00(12, 0, 77);
                    break;
                }
                if (scoreSlot25 > aidScoresSlot19[n])
                {
                    aids[n] = item;
                    aidScoresSlot19[n] = scoreSlot25;
                    aidTypes |= 1 << effect;
                    break;
                }
            }
            break;
        }
        case 40: {
            Weapon* weaponSlot32Slot15 = (Weapon*)item;
            if (reinterpret_cast<::ActionOwner *>((actor))->FUN_008bc9d0((::TargetObject *)(weaponSlot32Slot15), 1))
            {
                unsigned int index = reinterpret_cast<::S5460 *>(&(scoresSlot20))->FUN_007881d0();
                ::FUN_00403d30(&(*(::CombatWeapons::WeaponScore *)(reinterpret_cast<::FUN_006b3160_shell *>(&(scoresSlot20))->FUN_006b3160(index))), 0, 20);
                (*(::CombatWeapons::WeaponScore *)(reinterpret_cast<::FUN_006b3160_shell *>(&(scoresSlot20))->FUN_006b3160(index))).weapon = weaponSlot32Slot15;
                (*(::CombatWeapons::WeaponScore *)(reinterpret_cast<::FUN_006b3160_shell *>(&(scoresSlot20))->FUN_006b3160(index))).health = reinterpret_cast<::FUN_004bcdb0_shell *>((entry))->FUN_004bcdb0(1) / 100.0f;
            }
            break;
        }
        case 41:
            reinterpret_cast<::FUN_00438690 *>(&(ammosSlot1))->FUN_007cb2e0((unsigned int *)&(const ::CombatWeapons::Ammo *const &)((Ammo*)item));
            break;
        }
    }
    Weapon* forcedSlot30 = 0;
    Entry* equippedSlot10 = ((::CombatWeapons::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Equipped();
    if (equippedSlot10 && ((::CombatWeapons::Extras *)(::FUN_00559450((int *)(equippedSlot10)))) && *((::CombatWeapons::Extra **)(new ((void *)(((::CombatWeapons::Extras *)(::FUN_00559450((int *)(equippedSlot10)))))) ::Vec3())) &&
        reinterpret_cast<::FUN_00418b10_shell *>(((*((::CombatWeapons::Extra **)(new ((void *)(((::CombatWeapons::Extras *)(::FUN_00559450((int *)(equippedSlot10)))))) ::Vec3())))))->FUN_00418b10())
        forcedSlot30 = ((::CombatWeapons::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((equippedSlot10))->GetName()));
    if (!forcedSlot30)
    {
        float bestOutsideSlot13 = 0.0f;
        Weapon* outsideWeaponSlot0 = 0;
        float bestInsideSlot33 = 0.0f;
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(scoresSlot20))->GetName())); i++)
        {
            WeaponScore* scoreSlot25 = &scoresSlot20.FUN_006dad90(i);
            Weapon* weaponSlot32Slot15 = scoreSlot25->weapon;
            Actor* ownerSlot16 = (equippedSlot10 && weaponSlot32Slot15 == ((::CombatWeapons::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((equippedSlot10))->GetName()))) ? actor : 0;
            Ammo* ammoSlot1 = ((::CombatWeapons::Ammo *)(reinterpret_cast<::AmmoOwner *>((weaponSlot32Slot15))->FUN_00525980((::AmmoActor *)(ownerSlot16))));
            if (ammoSlot1 && !reinterpret_cast<::FUN_009962f0_s *>(&(ammosSlot1))->f((::NavMesh *const &)(ammoSlot1)))
            {
                bool special = false;
                Ammo* alternativeSlot0 = ((::CombatWeapons::Ammo *)(reinterpret_cast<::FUN_004c7300_shell *>((inventorySlot40))->FindInventoryItem((::TESObjectREFR *)(weaponSlot32Slot15), &special)));
                if (alternativeSlot0 && reinterpret_cast<::FUN_009962f0_s *>(&(ammosSlot1))->f((::NavMesh *const &)(alternativeSlot0)))
                {
                    if (equippedSlot10 && weaponSlot32Slot15 == ((::CombatWeapons::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((equippedSlot10))->GetName())))
                    {
                        Animation* animation = actor->AnimationData();
                        bool busySlot0 = reinterpret_cast<::fnv_008a8870::HA *>((actor))->FUN_008a8870() || (animation && reinterpret_cast<::FUN_008846c0_shell *>((animation))->FUN_008846c0());
                        if (!busySlot0)
                        {
                            Process* process = ((::CombatWeapons::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()));
                            int countSlot11 = reinterpret_cast<::FUN_004c8f30_shell *>((inventorySlot40))->FUN_004c8f30((int)(alternativeSlot0));
                            Equip* replacement = new Equip(alternativeSlot0, countSlot11);
                            process->EquipAmmo(replacement);
                            reinterpret_cast<::CombatProcedure *>((process->Ammunition()))->Initialize((::CombatController *)(0));
                            reinterpret_cast<::S_008a8840 *>((actor))->FUN_008a8840();
                        }
                    }
                }
                else
                {
                    reinterpret_cast<::FUN_0098f1f0_Class *>(&(scoresSlot20))->RemoveEntries(i, 1);
                    i--;
                    continue;
                }
            }
            else if (equippedSlot10 && weaponSlot32Slot15 == ((::CombatWeapons::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((equippedSlot10))->GetName())))
            {
                AmmoState* state = ((::CombatWeapons::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Ammunition();
                if (state)
                {
                    Animation* animation2Slot1 = actor->AnimationData();
                    Weapon* active = ((::CombatWeapons::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((equippedSlot10))->GetName()));
                    if (animation2Slot1 && active)
                    {
                        bool emptySlot0 = state && ((int)(reinterpret_cast<::Callees *>((state))->FUN_00726070())) <= 0 && active && reinterpret_cast<::FUN_00524b60_shell *>((active))->GetByteAt102() > 0;
                        bool busy2Slot10 =
                            reinterpret_cast<::fnv_008a8870::HA *>((actor))->FUN_008a8870() || (animation2Slot1 && reinterpret_cast<::FUN_008846c0_shell *>((animation2Slot1))->FUN_008846c0());
                        if (emptySlot0 && !busy2Slot10)
                            reinterpret_cast<::S_008a8840 *>((actor))->FUN_008a8840();
                    }
                }
            }
            scoreSlot25->damage = ::ComputeWeaponDamage((::CombatActorForm *)(actor), (::DamageWeapon *)(weaponSlot32Slot15), scoreSlot25->health, (::DamageAmmo *)(dataSlot17), (void *)(0), (void *)(0));
            if (scoreSlot25->damage <= ::_DAT_01012060)
            {
                reinterpret_cast<::FUN_0098f1f0_Class *>(&(scoresSlot20))->RemoveEntries(i, 1);
                i--;
                continue;
            }
            scoreSlot25->inRange = 1;
            scoreSlot25->range = 0.0f;
            int categorySlot22 = reinterpret_cast<::CombatWeapon *>((scoreSlot25->weapon))->FUN_00522c80();
            if (target && (categorySlot22 == 1 || categorySlot22 == 0))
            {
                float nearRange = 0.0f;
                float middleRangeSlot34 = 0.0f;
                float farRangeSlot1 = 0.0f;
                FUN_009a9180(controller, weaponSlot32Slot15, nearRange, middleRangeSlot34, farRangeSlot1);
                scoreSlot25->range = farRangeSlot1;
                if (((::CombatWeapons::Weapon *)(::FUN_007031c0((int)(controller)))) == weaponSlot32Slot15)
                    farRangeSlot1 *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatWeapons::Setting *>(&::originalRuntimeFloatSetting395))))));
                if (distance > farRangeSlot1 * farRangeSlot1)
                {
                    scoreSlot25->inRange = 0;
                    if (scoreSlot25->damage > bestOutsideSlot13)
                    {
                        bestOutsideSlot13 = scoreSlot25->damage;
                        outsideWeaponSlot0 = weaponSlot32Slot15;
                    }
                }
                else if (scoreSlot25->damage > bestInsideSlot33)
                    bestInsideSlot33 = scoreSlot25->damage;
            }
        }
        if (bestInsideSlot33 > ::_DAT_01012060)
            outsideWeaponSlot0 = 0;
        for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(scoresSlot20))->GetName())); j++)
        {
            WeaponScore* candidateSlot0 = &scoresSlot20.FUN_006dad90(j);
            Weapon* weapon2Slot11 = candidateSlot0->weapon;
            int category2Slot19 = reinterpret_cast<::CombatWeapon *>((candidateSlot0->weapon))->FUN_00522c80();
            float value = candidateSlot0->damage;
            if (weapon2Slot11 == current)
                value += DAT_0106b798;
            if (weapon2Slot11 == outsideWeaponSlot0)
                candidateSlot0->inRange = 1;
            if (!candidateSlot0->inRange)
            {
                value /= ::DAT_0102f078;
                if (candidateSlot0->range > maxRange && candidateSlot0->damage > bestInsideSlot33)
                    maxRange = candidateSlot0->range;
            }
            if (reinterpret_cast<::FUN_0046e8c0_class *>((weapon2Slot11))->FUN_0046e8c0() && candidateSlot0->inRange)
                reinterpret_cast<::FUN_00438690 *>(&(ranged))->FUN_007cb2e0((unsigned int *)&(weapon2Slot11));
            maxDamage = ::FUN_00404010(maxDamage, candidateSlot0->damage);
            if (category2Slot19 == 1 || category2Slot19 == 0)
                maxRanged = ::FUN_00404010(maxRanged, candidateSlot0->damage);
            maxScore = ::FUN_00404010(maxScore, value);
            types |= 1 << category2Slot19;
            if (value > categoryScore[category2Slot19])
            {
                bestWeapons[category2Slot19] = weapon2Slot11;
                categoryScore[category2Slot19] = value;
            }
        }
        categoryScore[6] = ::ComputeWeaponDamage((::CombatActorForm *)(actor), (::DamageWeapon *)(::CombatWeapons::Weapon *)(0), 1.0f, (::DamageAmmo *)(dataSlot17), (void *)(0), (void *)(0));
        maxDamage = ::FUN_00404010(maxDamage, categoryScore[6]);
        maxScore = ::FUN_00404010(maxScore, categoryScore[6]);
        types |= 64;
    }
    else
    {
        int category3 = reinterpret_cast<::CombatWeapon *>((forcedSlot30))->FUN_00522c80();
        bestWeapons[category3] = forcedSlot30;
        categoryScore[category3] = DAT_0108dfac;
        types |= 1 << category3;
        maxDamage = categoryScore[category3];
        maxScore = categoryScore[category3];
        if (category3 == 1 || category3 == 0)
            maxRanged = categoryScore[category3];
    }
    if (target && bestWeapons[0])
    {
        int projectile = ((int)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::CombatWeapons::Projectile *)(reinterpret_cast<::Thing *>((bestWeapons[0]))->GetOrFallback((int)(actor))))))));
        if (!reinterpret_cast<::ThreatManager *>(((*reinterpret_cast<::CombatWeapons::System * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->IsThreatWithinLimits((::ThreatActor *)(actor), (::ThreatActor *)(projectile), (const ::ThreatPosition &)(target->Position()), ::DAT_010162c0))
            reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(projectile));
    }
    reinterpret_cast<::FUN_008d7f40_shell *>(&(timer))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatWeapons::Setting *>(&::originalRuntimeFloatSetting427)))))));
}
}

struct Caster99a420
{
};
struct Slot99a420
{
    int target;
};
struct Track99a420
{
    int unk00;
    int target;
};

struct Combat99a420
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    Track99a420* track;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    Caster99a420* caster;
    int unk190;
    int unk194;
    int unk198;
    Slot99a420* slot3;
    Slot99a420* slot4;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int target;

    void FUN_0099a420(int aTarget, bool bKeep);
};
// Looks up entry 2, calls f1C4->FUN_00981380() if its value equals a, then calls FUN_0099a420(a, 1).
// @fnv 0x0099a780
void C99::FUN_0099a780(int a)
{
    int* b = ((int *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>(this)->GetActionAtIndex(2)));
    if (b && *b == a)
        reinterpret_cast<::fnv_00981380::CombatController *>((f1C4))->FUN_00981380();
    reinterpret_cast<::Combat99a420 *>(this)->FUN_0099a420(a, 1);
}


// @fnv 0x0099a420
void Combat99a420::FUN_0099a420(int aTarget, bool bKeep)
{
    Slot99a420* pSavedSlot3 = slot3;
    Slot99a420* pSavedSlot4 = slot4;
    for (unsigned int i = 0; i < 5; i++)
    {
        Slot99a420* pSlot = ((::Slot99a420 *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>(this)->GetActionAtIndex(i)));
        if (pSlot && pSlot->target == aTarget)
            reinterpret_cast<::FUN_00981340_shell *>(this)->FreeSlot(i);
    }
    if (!bKeep)
    {
        if (pSavedSlot3 != ((::Slot99a420 *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>(this)->GetActionAtIndex(3))) || pSavedSlot4 != ((::Slot99a420 *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>(this)->GetActionAtIndex(4))))
        {
            reinterpret_cast<::FUN_00981340_shell *>(this)->FreeSlot(3);
            reinterpret_cast<::FUN_00981340_shell *>(this)->FreeSlot(4);
        }
    }
    if (track && track->target == aTarget)
        ::FreeAndClearFieldC4((::FUN_009a0a40_shell *)(::Combat99a420 *)(this));
    if (caster && ((int)(reinterpret_cast<::MagicCaster_shell *>((caster))->FUN_0044edb0())) == aTarget)
        reinterpret_cast<::FUN_009a0680_shell *>(this)->ClearAndDeletePointer();
    if (target == aTarget)
        target = 0;
}

struct PointC
{
    float x, y, z;
    PointC();
    PointC operator-(const PointC&) const;
};
struct LocationC
{
    int a, b, c, d, e, f, g, h, i, j;
    LocationC(const PointC*, void*);
    ~LocationC();
};
struct SegmentC
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
    PointC start, kEnd4, third;
    unsigned char b4c, b4d, b4e, b4f, b50;
    PointC GetLocation();
};
struct ActorC
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual PointC* Position();
    float Radius();
};
struct InfoC
{
    int a, b, c, d;
    InfoC();
};
struct QueryC
{
};
struct OptionsC;
struct ControllerC
{
    ActorC* Actor();
    QueryC* Query();
};
struct TimeC
{
    float value;
    TimeC(float);
    TimeC(const TimeC&);
};
struct HazardC
{
    float Evaluate(PointC, ActorC*, float, float, TimeC, float);
};
struct WorldC
{
    ControllerC* Controller();
};
bool GeometryC(const PointC*, const PointC*, const PointC*, const PointC*);
struct DestinationC
{
};
struct OptionsC
{
    unsigned char a, b, c, d, e, f;
};
struct SearchC
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    ControllerC* controller;
    bool CheckSpace(PointC*, void*, int, int);
    bool FindPathCandidate(SegmentC*, DestinationC*, OptionsC*, PointC*, void*, void*, int, ActorC*, ActorC*, float,
                           float, int*, float*, bool);
};
struct FUN_005c3420_cls
{
};
struct FUN_00439ef0_cls
{
};
struct FUN_004a7290_cls
{
};
bool __cdecl FUN_006d7490(void* a, ParentSpaceNode* b, int c, int d);
extern double DAT_0108d658;

// @fnv 0x0099cc60
bool __cdecl FUN_0099cc60(void* pNodeA, ParentSpaceNode* pNodeB, int c)
{
    ParentSpaceNode s1;
    ParentSpaceNode s2;
    if ((unsigned char)c == 0)
    {
        reinterpret_cast<::FUN_00439ef0_class *>((((FUN_00439ef0_cls*)pNodeB)))->FUN_00439ef0((::NiPoint3 *)(::ParentSpaceNode *)(&s2), (*(const ::NiPoint3 *)(((int)(reinterpret_cast<::TaskQueueInterface *>((((FUN_005c3420_cls*)pNodeA)))->QueueActorAnimationTask((*(::NiPoint3 *)(&s1))))))));
        if (((double)(reinterpret_cast<::TESCombatStyle *>((((FUN_004a7290_cls*)&s2)))->UpdateCombatStyle())) > DAT_0108d658)
        {
            return false;
        }
    }
    if (FUN_006d7490(pNodeA, pNodeB, 0, 0) == false)
    {
        return false;
    }
    return true;
}

struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex operator-(const NiPoint3& kPt) const;
};
namespace std {
float abs(float);
}
struct FUN_0099ccd0_Actor
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
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual float GetCurrentTargetDistance(int iUnk);
};
class PathingLocation
{
  public:
    int m_data[10];
    ~PathingLocation();
};
struct FUN_006dce10 : PathingLocation
{
    FUN_006dce10(const NiPoint3& kPt, TESObjectREFR* pRef);
};
struct FUN_006e4820_class
{
    bool FUN_006e4820();
};
// @fnv 0x0099c230
bool SearchC::FindPathCandidate(SegmentC* segment, DestinationC* destination, OptionsC* options, PointC* target,
                                void* first, void* second, int mode, ActorC* actor, ActorC* reference, float nearRange,
                                float farRange, int* piReason, float* pfDistance, bool force)
{
    ActorC* actor13 = ((::ActorC *)(::GetFieldBC((::FUN_0097ae90_Class *)(controller))));
    float range4 = ::DAT_01032adc;
    if (((bool)(reinterpret_cast<::FUN_00982be0_cls *>((segment))->FUN_00982be0())) && !force && !segment->b4f && !segment->b50)
    {
        *piReason = 2;
        return false;
    }
    if (first == second && !GeometryC(&(*(::PointC *)&(reinterpret_cast<::TaskQueueInterface *>((segment))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), reference->Position(), &segment->start, &segment->kEnd4))
    {
        *piReason = 13;
        return false;
    }
    if (reinterpret_cast<::fnv_009a0d70::FUN_009a0d70_shell *>(this)->ContainsItem(first))
    {
        *piReason = 3;
        return false;
    }
    int failure5 = 0;
    int prevA = 0;
    *pfDistance = 0.0f;
    float travelTime8 = ::DAT_01012054;
    float radius = actor13->Radius();
    unsigned preferred3 = 1;
    if (options->b)
    {
        if (options->f)
            preferred3 = 0;
    }
    else if (reinterpret_cast<::DistanceCheck *>((segment))->FUN_006e4840((*(const ::NiPoint3 *)(actor->Position()))))
        preferred3 = 0;
    bool _special = ((bool)(reinterpret_cast<::FUN_00982be0_cls *>((segment))->FUN_00982be0())) && !force;
    bool _aim = (((bool)(reinterpret_cast<::FUN_00982be0_cls *>((segment))->FUN_00982be0())) || reinterpret_cast<::FUN_006e4820_class *>((segment))->FUN_006e4820()) && !force;
    unsigned cCount = (_special ? 1 : 0) + 1;
    for (unsigned iteration = 0; iteration < cCount; iteration++)
    {
        if (failure5)
            prevA = failure5;
        bool alternate4 = false;
        if (_special)
        {
            if (iteration == preferred3 && segment->b4f)
                alternate4 = true;
            else if (iteration != preferred3 && segment->b50)
                alternate4 = false;
            else
                continue;
        }
        if (!reinterpret_cast<::FUN_009835d0_cls *>((((::ControllerC *)(reinterpret_cast<::FUN_009611e0_shell *>(((*reinterpret_cast<::WorldC * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_009611e0()))))->TryUseCoverItem((unsigned int)(first), (unsigned int)(segment), (unsigned int)(controller), radius, options, force, alternate4))
        {
            failure5 = 9;
            continue;
        }
        PointC fStartB;
        PointC kEnd4;
        ::fnv_009a93a0::FUN_009a93a0((::fnv_009a93a0::TESAmmoInitCalls *)(controller), (int)(segment), (int)(options), (int)(&fStartB), (int)(&kEnd4));
        if (reinterpret_cast<::FUN_006e4820_class *>((segment))->FUN_006e4820() && reference && !reinterpret_cast<::Combat99 *>(this)->FUN_0099cec0((::Seg99 *)(segment), (::Pt3 *)(::PointC *)(&fStartB), (::Pt3 *)(target), (::TESObjectREFR *)(reference)))
        {
            failure5 = 6;
            continue;
        }
        LocationC location(&fStartB, segment);
        if (!reinterpret_cast<::PathingLocationCheck *>(&(location))->FUN_006ded70(actor13->Radius()))
        {
            failure5 = 4;
            continue;
        }
        if (_aim)
        {
            LocationC other4(&kEnd4, segment);
            if (!reinterpret_cast<::PathingLocationCheck *>(&(other4))->FUN_006ded70(actor13->Radius()))
            {
                failure5 = 5;
                continue;
            }
        }
        if (!CheckSpace(&fStartB, ((void *)(reinterpret_cast<::s575ca0::Owner *>((actor))->FUN_00575ca0())), 1, 0))
        {
            failure5 = 16;
            continue;
        }
        *pfDistance = reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::PointC &)((*target - fStartB)))->UpdateCombatStyle();
        if (*pfDistance > farRange * farRange)
        {
            failure5 = 7;
            continue;
        }
        if (*pfDistance < nearRange * nearRange)
        {
            failure5 = 8;
            continue;
        }
        InfoC pInfo5;
        reinterpret_cast<::StandIn_00989010 *>(&(pInfo5))->SetTripleAndValue((::ThreeInts_00989010 *)(::PointC *)(&fStartB), (int)(((void *)(reinterpret_cast<::s575ca0::Owner *>((actor))->FUN_00575ca0()))));
        if (((int)(reinterpret_cast<::B989700List *>((((::QueryC *)(reinterpret_cast<::EffectSetting *>((controller))->GetCastSound()))))->FindRefInRadius((::B9897F0Point *)(::InfoC *)(&pInfo5), range4, 0))))
        {
            failure5 = 10;
            continue;
        }
        if (travelTime8 == -1.0)
        {
            PointC delta4 = *actor->Position() - fStartB;
            travelTime8 = reinterpret_cast<::NiPoint3 *>((void *)&(delta4))->ComputeMagnitude() / reinterpret_cast<::fnv_008a0b10::FUN_008a0b10_shell *>((actor))->FUN_008a0b10();
        }
        if (((::HazardC *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::WorldC * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))->Evaluate(fStartB, actor, travelTime8, 0.0f, TimeC(0.0f), 0.0f) > 0.0)
        {
            failure5 = 11;
            continue;
        }
        if (_aim)
        {
            if (((::HazardC *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::WorldC * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))->Evaluate(kEnd4, actor, travelTime8, 0.0f, TimeC(0.0f), 0.0f) > 0.0)
            {
                failure5 = 12;
                continue;
            }
        }
        bool _d0x = ::FUN_0099cc60(&location, (::ParentSpaceNode *)(target), 1);
        if (!_d0x)
            _d0x = reinterpret_cast<::fnv_0099ca00::FUN_0099ca00_struct *>(this)->FUN_0099ca00(&location, (::fnv_0099ca00::Member *)(reference));
        if (_d0x)
        {
            failure5 = 13;
            continue;
        }
        bool checkPackage = true;
        if (mode == 5)
            checkPackage = false;
        else if (force)
            checkPackage = false;
        else if (first == second)
            checkPackage = false;
        if (checkPackage)
        {
            bool clear5 = ::FUN_009a7940((::SightReference *)(actor), (::SightReference *)(reference), (*(const ::NiPoint3 *)(&kEnd4)), (*(const ::NiPoint3 *)(target)), 1, -1);
            if (!clear5)
            {
                failure5 = 14;
                continue;
            }
        }
        reinterpret_cast<::FUN_0099b8b0_shell *>((destination))->FUN_0099b8b0((int)(&fStartB), 0);
        return true;
    }
    if (prevA > failure5)
        *piReason = prevA;
    else
        *piReason = failure5;
    return false;
}
struct FUN_008a1710_shell
{
    TESObjectWEAP* FUN_008a1710();
};

struct FUN_0099ccd0_shell : Combat99
{
    bool FUN_0099ccd0(Seg99* pSeg, NiPoint3Ex* pPos, FUN_0099ccd0_Actor* pActor, bool bCheckAngle);
};

// @fnv 0x0099ccd0
bool FUN_0099ccd0_shell::FUN_0099ccd0(Seg99* pSeg, NiPoint3Ex* pPos, FUN_0099ccd0_Actor* pActor, bool bCheckAngle)
{
    NiPoint3 kTargetPos = *pActor->GetPos();
    NiPoint3Ex kDiff = *pPos - kTargetPos;
    float fDistSqr9 = reinterpret_cast<::TESCombatStyle *>((void *)&(kDiff))->UpdateCombatStyle();
    if (fDistSqr9 < DAT_0106cd60)
        return false;
    if (bCheckAngle)
    {
        float fDesiredHeadingAngle = ::GetDirectionAngle((const ::NiPoint3 *)&(kDiff));
        float fUnused;
        float fAngleDifference = FUN_004b15e0(pActor->GetCurrentTargetDistance(0), fDesiredHeadingAngle, &fUnused);
        if (std::abs(fAngleDifference) > 0.78539818525314331)
            return true;
    }
    if (FUN_009a9630(pActor))
    {
        float fImpulseRadiusSquared = ::GetActorReach((::A69C0Actor *)(::Actor *)((Actor*)pActor), (::A69C0Weapon *)(::TESObjectWEAP *)(((FUN_008a1710_shell*)pActor)->FUN_008a1710())) * ::DAT_01016ff0;
        if (fDistSqr9 < fImpulseRadiusSquared * fImpulseRadiusSquared)
            return false;
    }
    else
    {
        FUN_006dce10 kLoc(*pPos, (TESObjectREFR*)pActor);
        if (FUN_006d7490((Picker*)&kLoc, (Vec3*)&kTargetPos, 0, 0))
            return false;
        if (((FUN_006e4820_class*)pSeg)->FUN_006e4820())
        {
            if (!FUN_0099cec0(pSeg, (Pt3*)pPos, (Pt3*)pActor->GetPos(), (TESObjectREFR*)pActor))
                return false;
        }
    }
    return true;
}

struct FUN_0099d310_actor_calls
{
    float FUN_008be1b0();
};
struct FUN_0099d310_field_calls
{
};
struct FUN_0099d310_window
{
};
struct FUN_0099d310_arg
{
};
struct FUN_0099d310_shell : C99
{
    bool FUN_0097ee90();
    void FUN_0099d310(FUN_0099d310_arg*);
};
// @fnv 0x0099d310
void FUN_0099d310_shell::FUN_0099d310(FUN_0099d310_arg* param)
{
    MobileObject* actor = ((::MobileObject *)(::GetFieldBC((::FUN_0097ae90_Class *)(((TESAmmoInitCalls*)f1C4)))));
    void* item = ((AlchemyItem*)f1C4)->FUN_004030b0();
    reinterpret_cast<::FUN_00507610_Class *>((param))->FUN_00507610(((FUN_0099d310_actor_calls*)actor)->FUN_008be1b0());
    reinterpret_cast<::FUN_006e5ee0_Class *>((param))->FUN_006e5ee0(reinterpret_cast<::fnv_008a0b10::FUN_008a0b10_shell *>((((FUN_0099d310_actor_calls*)actor)))->FUN_008a0b10());
    reinterpret_cast<::FUN_006e4ef0_shell *>((param))->FUN_006e4ef0(reinterpret_cast<::FUN_004536e0_Class *>((((FUN_0099d310_field_calls*)f1C4)))->GetFieldCC());
    if (reinterpret_cast<::FUN_00998a30_shell *>((((FUN_0099d310_field_calls*)f1C4)))->FUN_00998a30())
    {
        reinterpret_cast<::FUN_006e4320_Class *>((param))->FUN_006e4320(reinterpret_cast<::FUN_00453700_shell *>((((FUN_0099d310_field_calls*)f1C4)))->FUN_00453700());
    }
    reinterpret_cast<::FUN_005076c0Class *>((param))->FUN_005076c0((float)((int(*)(void*, unsigned int))(*(unsigned int**)((char*)actor + 0xa4))[2])(
        (char*)actor + 0xa4, 0x10));
    if (item != 0)
    {
        if (FUN_0097ee90() && (unsigned char)_pad[0x74] == 0)
        {
            reinterpret_cast<::FUN_006e4f10_class *>((param))->FUN_006e4f10((*(const ::NiPoint3 *)(((int(*)(void*))(*(unsigned int**)item)[0x1f4 / 4])(item))));
        }
        reinterpret_cast<::fnv_0099cb70::FUN_0099cb70_struct *>(this)->CollectCastSoundPositions((::fnv_0099cb70::Arr_006cee30 *)(((int)(reinterpret_cast<::FUN_006e4fb0_shell *>((param))->GetOffsetF4()))));
    }
    reinterpret_cast<::fnv_009a0e10::FUN_009a0e10_shell *>(this)->CollectAvoidanceItems((::fnv_009a0e10::BSSimpleArray<void *, 1024> *)(((int)(reinterpret_cast<::FUN_006e4f90_shell *>((param))->FUN_006e4f90()))));
    if (*((void**)&_pad[0xe4]) != 0 && *((unsigned char*)*((void**)&_pad[0xe4]) + 1) != 0)
    {
        reinterpret_cast<::FUN_00438690 *>((((::FUN_0099d310_window *)(reinterpret_cast<::FUN_006e4f90_shell *>((param))->FUN_006e4f90()))))->FUN_007cb2e0({});
    }
}

struct Sub14
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
};

struct FUN_006d3150
{
    FUN_006d3150();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sub14 sub14;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};

struct RetObjParam
{
};

struct LocalData2C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
};

struct CombatDecompClass : FUN_0099a9a0_shell
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
    FUN_006d3150* unkE8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;

    bool FUN_0099d030(void* p1, FUN_006d3150* p2, LocalData2C* p3, int p4, int p5, float p6, int p7);
    bool InitSubObject(RetObjParam* a1, int a2, int a3, float a4, int a5);
};

// Resets the object, allocates a FUN_006d3150, initialises local data and calls FUN_0099d030; on success stores two sub14 values and passes sub14 to a1.
// @fnv 0x0099e060
bool CombatDecompClass::InitSubObject(RetObjParam* pRetObj, int a2, int a3, float a4, int a5)
{
    reinterpret_cast<::fnv_009a0470::FUN_009a0470_shell *>((this))->ReleaseStageHolder(0);
    this->unkE8 = new FUN_006d3150();
    LocalData2C local2c;
    reinterpret_cast<::FUN_0097ee20_shell *>(&(local2c))->FUN_0097ee20();
    if (!this->FUN_0099d030(&this->unk128, this->unkE8, &local2c, a3, a2, a4, a5))
    {
        reinterpret_cast<::fnv_009a0470::FUN_009a0470_shell *>((this))->ReleaseStageHolder(0);
        return false;
    }
    this->unkE8->unk68 = ((int)(reinterpret_cast<::S_006e4570 *>(&(this->unkE8->sub14))->FUN_006e4570()));
    this->unkE8->unk6c = reinterpret_cast<::S_006e4740 *>(&(this->unkE8->sub14))->FUN_006e4740();
    reinterpret_cast<::FUN_006e4430_class *>((pRetObj))->operator=((*(const ::FUN_006e4430_class *)(&this->unkE8->sub14)));
    return true;
}

struct PickWeapon;
struct PickActor;
struct PickRef;
struct PickVec
{
    float x, y, z;
};
struct PickLoc
{
    float x, y, z;
    unsigned space;
    float FUN_00527a40(PickLoc*);
};
struct PickBase
{
};
struct PickNode
{
};
struct PickWrap
{
    PickNode* node;
};
struct PickPtr
{
};
struct PickProc
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual PickPtr* GetActive();
};
struct PickExtra
{
};
struct PickLock
{
};
struct PickForm
{
    unsigned FUN_00401170();
};
struct PickWeapon
{
};
struct PickRef
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual PickVec* Pos();
};
struct PickActor : PickRef
{
    virtual void a126();
    virtual void a127();
    virtual void a128();
    virtual void a129();
    virtual void a130();
    virtual void a131();
    virtual void a132();
    virtual void a133();
    virtual void a134();
    virtual bool IsCreature();
};
struct PickController
{
};
struct PickEntry
{
};
struct PickIter
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
    PickIter(int, PickActor*);
    PickIter(void*, PickActor*);
    ~PickIter();
};
struct PickCollection
{
};
struct PickGlobal
{
};
struct PickSetting
{
};
struct WeaponSearch
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    float unk058;
    float unk05c;
    int unk060;
    float unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    PickController* controller;
    bool SelectBestWeaponTarget();
};
// Scans nearby refs for a weapon target, scores candidates by distance and damage, and records the best pick via SetArrayEntry.
// @fnv 0x0099f6d0
bool WeaponSearch::SelectBestWeaponTarget()
{
    PickActor* aC1 = ((::PickActor *)(::GetFieldBC((::FUN_0097ae90_Class *)(controller))));
    PickRef* aFB = ((::PickRef *)(reinterpret_cast<::AlchemyItem *>((controller))->FUN_004030b0()));
    if (!((bool)(reinterpret_cast<::FUN_009a0240_shell *>((controller))->GetFixedNormals())))
        return false;
    if (unk034 || ((::PickWeapon *)(reinterpret_cast<::Twin_0044ddc0 *>((((PickEntry*)&unk024)))->GetName())))
        return false;
    if (aC1->IsCreature())
    {
        PickBase* aPC = ((::PickBase *)(reinterpret_cast<::Actor *>((aC1))->GetActorBase()));
        PickWeapon* aXi = ((::PickWeapon *)(::GetField158((int)(aPC))));
        if (!aXi)
            return false;
    }
    PickPtr* aId = ((::PickProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((aC1))->GetBaseTexture()))->GetActive();
    if (aId && ((::PickWrap *)(::FUN_00559450((int *)(aId)))) && ((::PickWrap *)(new ((void *)(((::PickWrap *)(::FUN_00559450((int *)(aId)))))) ::Vec3()))->node &&
        reinterpret_cast<::FUN_00418b10_shell *>((((::PickWrap *)(new ((void *)(((::PickWrap *)(::FUN_00559450((int *)(aId)))))) ::Vec3()))->node))->FUN_00418b10())
        return false;
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::PickGlobal *>(&::g_011f1a60))))->ClearData();
    PickLoc aI4 = (*(::PickLoc *)(reinterpret_cast<::FUN_00575650_Class *>((aC1))->FUN_00575650({})));
    PickRef* aCr = 0;
    PickWeapon* aB8 = 0;
    PickRef* aB4 = 0;
    void* aCb = 0;
    PickWeapon* aFg = ((::PickWeapon *)(::FUN_007031c0((int)(controller))));
    bool aC2 = reinterpret_cast<::FUN_0097fd40_shell *>(this)->FUN_0097fd40();
    float aRt = aC2 ? unk05c : unk058;
    float aKB = aRt * (1.0f + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting362)))))));
    float aPE = 1.0f;
    if (unk064 > unk058)
    {
        aPE = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting369))))));
        aKB = FUN_0040ebd0(aKB, unk064);
    }
    if (aC2)
        aPE = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting370))))));
    float aPa = 0.0f;
    float aIt = 0.0f;
    if (aC2 || (aFg && ::FUN_004c0c30((char *)(aFg))))
    {
        aPa = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting367))))));
        aIt = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting368))))));
    }
    else
    {
        if (!aFg)
        {
            aPa = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting363))))));
            aIt = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting364))))));
        }
        else
        {
            aPa = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting365))))));
            aIt = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting366))))));
        }
        bool apX = false;
        if (aFB)
        {
            PickLoc bpA = (*(::PickLoc *)(reinterpret_cast<::FUN_00575650_Class *>((aFB))->FUN_00575650({})));
            if (aI4.FUN_00527a40(&bpA) < 589824.0)
                apX = true;
        }
        if (!apX && unk05c > 0.0 && unk058 > 0.0)
        {
            float cb2 = unk05c / unk058;
            if (cb2 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting371)))))) && *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting368)))))) > aIt)
                aIt = aIt + cb2 * (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting368)))))) - aIt);
        }
    }
    aPa *= aPE;
    aIt *= aPE;
    float aB1 = 0.0f;
    float aP2 = DAT_0108df70;
    PickIter ap8(40, aC1);
    PickRef* aFC = 0;
    PickEntry* aPb = 0;
    while (reinterpret_cast<::Collection *>(((*reinterpret_cast<::PickCollection * *>(&::DAT_011c95c8))))->FindNextRef((::State *)(::PickIter *)(&ap8), (::Ref **)(::PickRef **)(&aFC), (::Ref **)(::PickEntry **)(&aPb), 3))
    {
        float cbX = aPb ? reinterpret_cast<::FUN_004bcdb0_shell *>((aPb))->FUN_004bcdb0(0) : reinterpret_cast<::FUN_004186f0_shell *>((((::PickExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((aFC))->FUN_005d43c0()))))->FUN_004186f0();
        if (reinterpret_cast<::FUN_00477ba0_shell *>((aFC))->FUN_00477ba0() || cbX == 0.0)
            continue;
        PickWeapon* aRy = aPb ? ((::PickWeapon *)(reinterpret_cast<::Twin_0044ddc0 *>((aPb))->GetName())) : ((::PickWeapon *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((aFC))->FUN_007af430()));
        float ap9 = 1.0f;
        if (cbX != -1.0)
            ap9 = cbX / ::TESHealthForm::GetBaseHealth((::TESForm *)(aRy));
        float ch3 = ::ComputeWeaponDamage((::CombatActorForm *)(aC1), (::DamageWeapon *)(aRy), ap9, (::DamageAmmo *)(reinterpret_cast<::FUN_00980070_shell *>((controller))->FUN_00980070()), (void *)(0), (void *)(0));
        if (::FUN_006450c0((::TESObjectWEAP *)(aRy)))
            ch3 *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting373))))));
        if (ch3 <= aKB)
            continue;
        if (aC2 && !::FUN_004c0c30((char *)(aRy)))
            continue;
        if (!reinterpret_cast<::ActionOwner *>((aC1))->FUN_008bc9d0((::TargetObject *)(aRy), 0))
            continue;
        float cbA = 0.0f;
        if (aKB <= 0.0)
            cbA = aIt * aIt;
        else
        {
            float c_2 = ch3 / aKB;
            c_2 = FUN_0040ebd0(c_2, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting372)))))));
            float d_2 = (c_2 - 1.0) / (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PickSetting *>(&::originalRuntimeFloatSetting372)))))) - 1.0);
            float b10 = aPa + d_2 * (aIt - aPa);
            cbA = b10 * b10;
        }
        PickLoc aPH = (*(::PickLoc *)(reinterpret_cast<::FUN_00575650_Class *>((aFC))->FUN_00575650({})));
        float aM4 = aPH.FUN_00527a40(&aI4);
        if (aM4 >= cbA)
            continue;
        if (!reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>(this)->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&aPH)), 1, 0))
            continue;
        if (((::PickWeapon *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((aFC))->FUN_007af430())) && ((PickForm*)((::PickWeapon *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((aFC))->FUN_007af430())))->FUN_00401170() == 27)
        {
            PickWeapon* base = ((::PickWeapon *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((aFC))->FUN_007af430()));
            if (base)
            {
                if (((::PickLock *)(reinterpret_cast<::FUN_00569160_shell *>((aFC))->FUN_00569160())) && reinterpret_cast<::LockExtraData *>((((::PickLock *)(reinterpret_cast<::FUN_00569160_shell *>((aFC))->FUN_00569160()))))->IsLocked())
                    continue;
                if (((void *)(reinterpret_cast<::OwnerLookupView *>((aFC))->FUN_00567790())) && !reinterpret_cast<::OwnershipReferenceView *>((aFC))->FUN_005785e0((::Actor *)(aC1), true))
                    continue;
            }
        }
        PickRef* ch8 = 0;
        bool ap3 = true;
        void* ap7 = ((void *)(reinterpret_cast<::AmmoOwner *>((aRy))->FUN_00525980((::AmmoActor *)(aC1))));
        if (ap7)
        {
            ap3 = false;
            if (!aPb && ((void *)(reinterpret_cast<::FUN_0042eb40_shell *>((((::PickExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((aFC))->FUN_005d43c0()))))->GetExtraAmmo())))
                ap3 = true;
            if (!ap3 && ((unsigned int)(reinterpret_cast<::CombatState *>((aC1))->GetInventoryItemCount((::TESForm *)(ap7)))))
                ap3 = true;
            if (!ap3 && aPb && ((unsigned int)(reinterpret_cast<::CombatState *>((aFC))->GetInventoryItemCount((::TESForm *)(ap7)))))
            {
                ap3 = true;
                ch8 = aFC;
            }
            if (!ap3)
            {
                float cb3 = DAT_0108df70;
                PickVec cb5 = *aFC->Pos();
                PickIter dy9(ap7, aC1);
                PickRef* cbB = 0;
                PickEntry* e2x = 0;
                while (reinterpret_cast<::Collection *>(((*reinterpret_cast<::PickCollection * *>(&::DAT_011c95c8))))->FindNextRef((::State *)(::PickIter *)(&dy9), (::Ref **)(::PickRef **)(&cbB), (::Ref **)(::PickEntry **)(&e2x), 3))
                {
                    PickLoc fA8 = (*(::PickLoc *)(reinterpret_cast<::FUN_00575650_Class *>((cbB))->FUN_00575650({})));
                    float fEA = fA8.FUN_00527a40(&aI4) + fA8.FUN_00527a40(&aPH);
                    if (fEA > cbA || fEA > cb3)
                        continue;
                    if (!reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>(this)->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&fA8)), 1, 0))
                        continue;
                    ch8 = cbB;
                    cb3 = fEA;
                    aM4 = fEA;
                    ap3 = true;
                }
            }
        }
        if (ap3)
        {
            float ch2 = FUN_00404010(FUN_004579e0(aM4), 64.0f);
            float fT7 = ch3 * 10000.0 / ch2;
            bool crA = false;
            if (fT7 > aB1)
            {
                crA = true;
            }
            else if (fT7 == aB1 && aM4 < aP2)
                crA = true;
            if (crA)
            {
                aB1 = fT7;
                aP2 = aM4;
                aCr = aFC;
                aB8 = aCr ? aRy : 0;
                aB4 = ch8;
                aCb = ch8 ? ap7 : 0;
            }
        }
    }
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::PickGlobal *>(&::g_011f1a60))))->ClearData();
    if (aCr)
    {
        reinterpret_cast<::fnv_009a06c0::FUN_009a06c0_struct *>(this)->SetArrayEntry(3, (::fnv_009a06c0::TESObjectREFRHelper *)(aB4), (int)(aCb));
        reinterpret_cast<::fnv_009a06c0::FUN_009a06c0_struct *>(this)->SetArrayEntry(4, (::fnv_009a06c0::TESObjectREFRHelper *)(aCr), (int)(aB8));
        return true;
    }
    return false;
}


struct CS_Loc16
{
    int v0;
    int v4;
    int v8;
    int vC;
};

struct CS_AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};

struct CS_Actor
{
    int unk00;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    CS_AVOwner avOwner;
    CS_Loc16 GetLocation(float);
};

struct CS_Item
{
};

struct CS_Flags
{
};

struct CS_Owner
{
};

struct CS_Timer
{
};

struct CS_Setting
{
};

struct CS_State
{
    int unk00;
    int unk04;
    float fImpulseRadiusSquared;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    CS_Timer timerA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    unsigned char unkC8;
    unsigned char ucC9;
    unsigned char unkCA;
    unsigned char unkCB;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned char ucD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    CS_Owner* pOwner;
    void UpdateRangeValue();
};
// @fnv 0x00997cb0
void FUN_00997cb0_Class::FUN_00997cb0()
{
    if (((::MobileObject *)(::GetFieldBC((::FUN_0097ae90_Class *)((*reinterpret_cast<TESAmmoInitCalls**>(reinterpret_cast<char*>(this) + 0x1c4))))))
            ->GetCurrentProcessLevel() == 0)
    {
        FUN_00997cf0();
        reinterpret_cast<::UpdateState *>(this)->FUN_00998a50();
    }
    else
    {
        FUN_00999160();
    }
}
// @fnv 0x00998a50
void UpdateState::FUN_00998a50()
{
    UpdateActor* count = ((::UpdateActor *)(::GetFieldBC((::FUN_0097ae90_Class *)(controller))));
    UpdateRef* ref = ((::UpdateRef *)(reinterpret_cast<::AlchemyItem *>((controller))->FUN_004030b0()));
    {
        int actor = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(targets))->GetName()));
        if (actor > 1)
        {
            unsigned char flag = ((unsigned char)(reinterpret_cast<::FUN_00981970_shell *>((controller))->FUN_00981970()));
            if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(timer214))->FUN_0097fa50() && !flag)
                reinterpret_cast<::FUN_008d7f40_shell *>(&(timer214))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting381)))))));
            if ((reinterpret_cast<::FUN_0097fa50_Class *>(&(timer214))->FUN_0097fa50() && reinterpret_cast<::TimeoutTimer *>(&(timer214))->CheckTimer()) || force)
            {
                bool randomize = reinterpret_cast<::FUN_009990c0_s *>(&(timer214))->IsNegative();
                if (RandomBoolean(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting380))))))) || force || randomize)
                {
                    int selected = 0;
                    if (randomize && target)
                    {
                        int remaining = GetRandomNumberInRange(0, actor - 1);
                        for (unsigned index = 0; index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(targets))->GetName())); ++index)
                        {
                            int entry = ((int)(reinterpret_cast<::S3e60 *>(&(targets))->FUN_006a7ad0(index)));
                            if (entry == target)
                                continue;
                            if (remaining == 0)
                            {
                                selected = entry;
                                break;
                            }
                            --remaining;
                        }
                    }
                    else
                    {
                        int choice = GetRandomNumberInRange(0, actor);
                        selected = ((int)(reinterpret_cast<::S3e60 *>(&(targets))->FUN_006a7ad0(choice)));
                    }
                    if (selected != target)
                    {
                        target = selected;
                        Changed();
                        reinterpret_cast<::FUN_0097f200_t *>((controller))->FUN_0097f200();
                    }
                }
                reinterpret_cast<::TimeoutTimer *>(&(timer214))->FUN_00910b10();
            }
        }
    }
    if (pending)
    {
        if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(timer1dc))->FUN_0097fa50())
            reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1dc))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting359)))))));
        if (reinterpret_cast<::TimeoutTimer *>(&(timer1dc))->CheckTimer())
        {
            if (!ref || reinterpret_cast<::ThreatManager *>(((*reinterpret_cast<::UpdateWorld * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->IsThreatWithinLimits((::ThreatActor *)(count), (::ThreatActor *)(pending), (*(const ::ThreatPosition *)(ref->Query(::DAT_010162c0))), {}))
                pending = 0;
            else
                reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1dc))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting359)))))));
        }
    }
    else
        reinterpret_cast<::TimeoutTimer *>(&(timer1dc))->FUN_00910b10();
    if (reinterpret_cast<::TimeoutTimer *>(&(timer1d4))->CheckTimer())
    {
        reinterpret_cast<::WeaponSearch *>(this)->SelectBestWeaponTarget();
        if (elapsed < threshold)
        {
            reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1d4))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting360)))))));
            elapsed = 0.0f;
        }
        else
            reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1d4))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting361)))))));
    }
    if (reinterpret_cast<::TimeoutTimer *>(&(timer204))->CheckTimer())
    {
        reinterpret_cast<::fnv_009a1010::FUN_009a1010_Class *>(this)->FUN_009a1010();
        reinterpret_cast<::FUN_008d7f40_shell *>(&(timer204))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::g_011cf198)))))));
    }
    if (reinterpret_cast<::TimeoutTimer *>(&(timer20c))->CheckTimer())
    {
        reinterpret_cast<::CS_State *>(this)->UpdateRangeValue();
        reinterpret_cast<::FUN_008d7f40_shell *>(&(timer20c))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateSetting *>(&::originalRuntimeFloatSetting492)))))));
    }
    if (((::UpdateRequest *)(::FUN_00559450((int *)&(request)))))
    {
        UpdateResult result;
        if (((::UpdateRequest *)(::FUN_00559450((int *)&(request))))->Poll(&result))
        {
            switch (result.status)
            {
            case 0:
                reinterpret_cast<::FUN_00999100_shell *>(this)->FUN_00999100();
                requestState = -1;
                break;
            default:
                if (requestState == 1 && reinterpret_cast<::FUN_0097fd40_shell *>(this)->FUN_0097fd40() && ref)
                {
                    if (!reinterpret_cast<::PRProcedure *>(this)->SetMode(false))
                        requestState = -1;
                }
                else
                    requestState = -1;
                break;
            }
            if (requestState == -1)
                reinterpret_cast<::FakeHolder *>(&(request))->AssignObject((void *)(0));
        }
    }
    else if (reinterpret_cast<::FUN_0097fd40_shell *>(this)->FUN_0097fd40() && ref)
    {
        if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(timer1cc))->FUN_0097fa50())
            reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1cc))->FUN_008d7f40(::DAT_0101712c);
        if (reinterpret_cast<::TimeoutTimer *>(&(timer1cc))->CheckTimer())
        {
            bool bRequested = false;
            if (reinterpret_cast<::TESActorBaseData *>(this)->GetFlag(2) && reinterpret_cast<::PRProcedure *>(this)->SetMode(true))
                bRequested = true;
            if (!bRequested)
                reinterpret_cast<::PRProcedure *>(this)->SetMode(false);
            reinterpret_cast<::FUN_008d7f40_shell *>(&(timer1cc))->FUN_008d7f40(::DAT_0101712c);
        }
    }
    else
        reinterpret_cast<::TimeoutTimer *>(&(timer1cc))->FUN_00910b10();
    reinterpret_cast<::FUN_00999260_shell *>(this)->UpdateCombatFlags();
    if (reinterpret_cast<::S981990 *>((controller))->FUN_00981990())
    {
        if (!reinterpret_cast<::Holder *>((controller))->IsModifierZero() && !notified)
        {
            notified = true;
            reinterpret_cast<::fnv_008a6840::FUN_008a6840_shell *>((count))->FUN_008a6840(0);
            reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::UpdateManager * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(controller), 2, 3, 1);
        }
    }
    else
    {
        bool clear = true;
        if (((::UpdateEffect *)(reinterpret_cast<::FUN_004f9bf0_shell *>((controller))->FUN_004f9bf0())) && ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((::UpdateEffect *)(reinterpret_cast<::FUN_004f9bf0_shell *>((controller))->FUN_004f9bf0()))))->FUN_00825c00())) == 6 && ((bool)(reinterpret_cast<::FUN_009a1380_cls *>(this)->FUN_009a1380())))
            clear = false;
        if (clear)
            notified = false;
    }
}

// @fnv 0x009a1060
void CS_State::UpdateRangeValue()
{
    CS_Actor* pActor2 = ((::CS_Actor *)(::GetFieldBC((::FUN_0097ae90_Class *)(pOwner))));
    if (ucD8 != 1)
    {
        fImpulseRadiusSquared = 100.0f;
        if (reinterpret_cast<::FUN_00435e00_t *>(&(timerA0))->FUN_00435e00() < ::DAT_010718b8)
        {
            if (pActor2->avOwner.GetActorValue(0) != 3.0)
            {
                CS_Item* pItem5 = ((::CS_Item *)(reinterpret_cast<::EffectSetting *>((pOwner))->GetCastSound()));
                float fA4 = reinterpret_cast<::FUN_0098cb30_cls *>((pItem5))->GetModifierSum((::FUN_0098cb30_inner *)(pActor2));
                float fDivA4 = reinterpret_cast<::FUN_009a1260_Class *>((pItem5))->GetFloatAt0xC8();
                if (fA4 >= ::_DAT_01012060 && fDivA4 > ::_DAT_01012060)
                {
                    fImpulseRadiusSquared = fA4 / fDivA4;
                    if (fImpulseRadiusSquared > ::_DAT_01012060 && reinterpret_cast<::CombatFlagHolder *>((((::CS_Flags *)(reinterpret_cast<::FUN_00980070_shell *>((pOwner))->FUN_00980070()))))->FUN_009a1240())
                    {
                        float _fB = reinterpret_cast<::GroupScore *>((pItem5))->GetAverageScore((::GroupActor *)(pActor2));
                        float fDivB5 = reinterpret_cast<::FUN_004536e0_Class *>((pItem5))->GetFieldCC();
                        if (_fB >= ::_DAT_01012060 && fDivB5 > ::_DAT_01012060)
                        {
                            float fScaled5 = reinterpret_cast<::fnv_008acbe0::FUN_008acbe0_shell *>((pActor2))->GetModifiedDamagePerSecond(_fB);
                            float fNew2 = fScaled5 / fDivB5;
                            if (fNew2 < fImpulseRadiusSquared)
                            {
                                fImpulseRadiusSquared = fNew2;
                            }
                        }
                    }
                }
                if (ucD8 == 2 && ucC9 < 4)
                {
                    if (((int)(reinterpret_cast<::B989700List *>((pItem5))->FindRefInRadius((::B9897F0Point *)&(const ::CS_Loc16 &)(pActor2->GetLocation(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CS_Setting *>(&::originalRuntimeFloatSetting439)))))))), 1, {}))))
                    {
                        reinterpret_cast<::fnv_009a1280::CombatLogic *>(this)->FUN_009a1280(1);
                    }
                }
            }
        }
    }
}

struct Save435
{
};
struct Stamp435
{
    unsigned value;
};
struct Pair435
{
    unsigned first, second;
};
struct Item435
{
};
struct ItemB435
{
};
struct List435
{
    unsigned first, second, third, fourth;
    ItemB435* FUN_006dad90(unsigned);
};
struct Optional435
{
};
struct OptionalB435
{
};
struct OptionalC435
{
};
struct Float435
{
    float value;
};
struct Location435
{
    unsigned x00, x04, x08, x0c, x10, x14, x18;
    Float435 range;
    unsigned x20, x24, x28, x2c, x30, x34, x38;
};
struct RefPair435
{
    void* first;
    void* second;
};
struct Vec435
{
    float x, y, z;
};
struct Owner435
{
    unsigned char flag;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    unsigned f04;
    unsigned f08;
    void* references[6];
    List435 list24;
    void* reference34;
    unsigned f38;
    unsigned values[7];
    unsigned f58;
    unsigned f5c;
    unsigned unk60;
    unsigned f64;
    unsigned f68;
    unsigned f6c;
    unsigned char f70;
    unsigned char f71;
    unsigned char f72;
    unsigned char f73;
    unsigned char f74;
    unsigned char f75;
    unsigned char f76;
    unsigned char f77;
    void* reference78;
    unsigned f7c;
    unsigned f80;
    Vec435 position;
    unsigned f90;
    Stamp435 s94;
    Stamp435 s98;
    Stamp435 s9c;
    Stamp435 sa0;
    Stamp435 sa4;
    Pair435 pa8;
    Pair435 pb0;
    Pair435 pb8;
    Stamp435 sc0;
    OptionalC435* optionalC;
    unsigned char fc8;
    unsigned char fc9;
    unsigned char unkca;
    unsigned char unkcb;
    unsigned fcc;
    unsigned fd0;
    unsigned fd4;
    unsigned char fd8;
    unsigned char unkd9;
    unsigned char unkda;
    unsigned char unkdb;
    void* referencedc;
    Stamp435 se0;
    Optional435* optionalE4;
    Optional435* optionalE8;
    Location435 location1;
    Location435 location2;
    List435 list164;
    List435 list174;
    Stamp435 s184;
    unsigned char f188;
    unsigned char unk189;
    unsigned char unk18a;
    unsigned char unk18b;
    OptionalB435* optional18c;
    RefPair435* pairs[5];
    void* refs[2];
    Pair435 timers[2];
    unsigned f1bc;
    void* ref1c0;
    unsigned unk1c4;
    unsigned char f1c8;
    unsigned char unk1c9;
    unsigned char unk1ca;
    unsigned char unk1cb;
    Pair435 p1cc;
    Pair435 p1d4;
    Pair435 p1dc;
    Pair435 p1e4;
    Pair435 p1ec;
    Pair435 p1f4;
    Pair435 p1fc;
    Pair435 p204;
    Pair435 p20c;
    Pair435 p214;
    Pair435 p21c;
    unsigned unk224;
    unsigned f228;
    void SaveToStream(Save435*);
};
// Serializes the object's fields, references, lists, timers and optional sub-objects into the save buffer, writing presence flags before each optional block.
// @fnv 0x009a17a0
void Owner435::SaveToStream(Save435* pSaveBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&flag, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f04, 4, 0);
    for (unsigned i = 0; i < 6; i++)
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(references[i]), 0);
    {
        unsigned count = &list24 ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list24))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((pSaveBuffer))->FUN_00865f60(count);
        for (unsigned j = 0; j < count; j++)
        {
            void** item = ((void **)(reinterpret_cast<::S3e60 *>(&(list24))->FUN_006a7ad0(j)));
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*item), 0);
        }
    }
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(reference34), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f38, 4, 0);
    for (unsigned uiValueIndex = 0; uiValueIndex < 7; uiValueIndex++)
        reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&values[uiValueIndex], 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f58, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f5c, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f64, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f68, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f6c, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f70, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f71, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f72, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f73, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f74, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f75, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f76, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f77, 1, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(reference78), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f7c, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f80, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&position, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f90, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&fc8, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&fc9, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&fcc, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&fd0, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&fd4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f08, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&fd8, 1, 0);
    reinterpret_cast<::FUN_00865db0_shell *>((pSaveBuffer))->FUN_00865db0((unsigned int)(referencedc), 0);
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(s94))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(s98))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(s9c))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(sa0))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(sa4))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(pa8))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(pb0))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(sc0))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(pb8))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(se0))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    unsigned char flags = 0;
    if (optionalE4)
        flags |= 1;
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(location1.range))->FUN_006a7f50() != -DAT_0108df70)
        flags |= 2;
    if (optionalE8)
        flags |= 4;
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(location2.range))->FUN_006a7f50() != -DAT_0108df70)
        flags |= 8;
    if (optional18c)
        flags |= 16;
    if (optionalC)
        flags |= 32;
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&flags, 1, 0);
    if (optionalE4)
        reinterpret_cast<::FUN_009a2de0_struct *>((optionalE4))->FUN_009a2de0((::BGSSaveFormBuffer *)(pSaveBuffer));
    if (optionalE8)
        reinterpret_cast<::FUN_009a2de0_struct *>((optionalE8))->FUN_009a2de0((::BGSSaveFormBuffer *)(pSaveBuffer));
    if (optional18c)
        reinterpret_cast<::fnv_009a2bf0::FUN_009a2bf0_shell *>((optional18c))->FUN_009a2bf0((::fnv_009a2bf0::BGSSaveFormBuffer *)(pSaveBuffer));
    if (optionalC)
        reinterpret_cast<::fnv_009a3130::CombatSaveData *>((optionalC))->FUN_009a3130((::fnv_009a3130::BGSSaveFormBuffer *)(pSaveBuffer));
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(location1.range))->FUN_006a7f50() != -DAT_0108df70)
        reinterpret_cast<::fnv_009a2f50::FUN_009a2f50_shell *>(&(location1))->FUN_009a2f50((::fnv_009a2f50::BGSSaveFormBuffer *)(pSaveBuffer));
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(location2.range))->FUN_006a7f50() != -DAT_0108df70)
        reinterpret_cast<::fnv_009a2f50::FUN_009a2f50_shell *>(&(location2))->FUN_009a2f50((::fnv_009a2f50::BGSSaveFormBuffer *)(pSaveBuffer));
    {
        unsigned uiList164Count = &list164 ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list164))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((pSaveBuffer))->FUN_00865f60(uiList164Count);
        for (unsigned uiList164Index = 0; uiList164Index < uiList164Count; uiList164Index++)
        {
            Item435* item2 = ((::Item435 *)(reinterpret_cast<::FUN_00844160_shell *>(&(list164))->FUN_00844160(uiList164Index)));
            reinterpret_cast<::fnv_009a2d20::FUN_009a2d20_s *>((item2))->FUN_009a2d20((::fnv_009a2d20::BGSSaveFormBuffer *)(pSaveBuffer));
        }
    }
    {
        unsigned uiList174Count = &list174 ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list174))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((pSaveBuffer))->FUN_00865f60(uiList174Count);
        for (unsigned m = 0; m < uiList174Count; m++)
        {
            ItemB435* item3 = list174.FUN_006dad90(m);
            reinterpret_cast<::FUN_009a2d80_shell *>((item3))->FUN_009a2d80(pSaveBuffer);
        }
    }
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(s184))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f188, 1, 0);
    unsigned char ucPairFlags = 0;
    for (unsigned n = 0; n < 5; n++)
    {
        if (pairs[n])
            ucPairFlags |= 1 << n;
    }
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&ucPairFlags, 1, 0);
    for (unsigned o = 0; o < 5; o++)
    {
        if (pairs[o])
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pairs[o]->first), 0);
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pairs[o]->second), 0);
        }
    }
    for (unsigned uiRefTimerIndex = 0; uiRefTimerIndex < 2; uiRefTimerIndex++)
    {
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(refs[uiRefTimerIndex]), 0);
        reinterpret_cast<::FUN_009a5eb0_shell *>(&(timers[uiRefTimerIndex]))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    }
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f1bc, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(ref1c0), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f1c8, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveBuffer))->FUN_00865e50(&f228, 4, 0);
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1cc))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1d4))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1dc))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1e4))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1ec))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1f4))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p1fc))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p20c))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p204))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p214))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>(&(p21c))->FUN_009a5eb0((::BGSSaveFormBuffer *)(pSaveBuffer));
}

class TESFile9A2;

class Holder9A2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TESObjectREFR* m_pkRef;

    void ResolveRef(TESFile9A2* pkFile);
};

// Replaces m_pkRef with the result of FUN_004839c0 cast to TESObjectREFR, or null if m_pkRef is null.
// @fnv 0x009a2cc0
void Holder9A2::ResolveRef(TESFile9A2* pkFile)
{
    m_pkRef = m_pkRef ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(m_pkRef))) : 0;
}

namespace fnv_0099b5a0 {
// 0x0099b5a0  779 bytes  /MT /Od /Oy- /GS /EHsc /Gy
struct Vec3
{
    float x, y, z;
};
struct P3
{
    float x, y, z;
    P3();
};

struct Sound99
{
};
struct Snd99
{
    Vec3 pos;
    int extra;
};
struct Mob99
{
};
struct Ammo99
{
};
struct Weap99
{
};
struct Spell99
{
};
struct Clock99
{
};
struct SndMgr99
{
};
struct A1_99
{
};


void __cdecl FUN_009a8050(Vec3*, void*);
bool __cdecl FUN_009a7670(void*, void*, Ammo99*, Vec3, P3, Vec3, char*, P3*, float);

struct FUN_0099b5a0_holder
{
    char pad00[0x84];
    P3 pt84;
    char pad90[0x98 - 0x90];
    Clock99 clk;
    char pad99[0x1c4 - 0x99];
    Spell99* p1c4;

    bool FUN_0099b5a0(A1_99* a1, char* a2, Weap99* a3);
};

// @fnv 0x0099b5a0
bool FUN_0099b5a0_holder::FUN_0099b5a0(A1_99* a1, char* acArg, Weap99* apWeapon)
{
    if (!apWeapon || !((void *)(reinterpret_cast<::Thing *>((apWeapon))->GetOrFallback((int)(((void *)(::GetFieldBC((::FUN_0097ae90_Class *)(p1c4)))))))))
        return false;
    Mob99* mobj3 = (Mob99*)((void *)(::GetFieldBC((::FUN_0097ae90_Class *)(p1c4))));
    Spell99* spellB = (Spell99*)reinterpret_cast<::AlchemyItem *>((p1c4))->FUN_004030b0();
    if (!spellB)
        return false;
    Ammo99* ammoA = (Ammo99*)((void *)(reinterpret_cast<::Thing *>((apWeapon))->GetOrFallback((int)(mobj3))));
    float f6 = ::FUN_009a7f00((::FUN_009a7f00_obj *)(ammoA), 0.0f);
    Vec3 posVal;
    FUN_009a8050(&posVal, mobj3);

    for (unsigned i = 0; i < 2; i++)
    {
        P3 v9;
        if (i == 0)
        {
            Snd99 s2;
            reinterpret_cast<::FUN_0097ede0_cls *>(&(s2))->FUN_0097ede0();
            if (!reinterpret_cast<::fnv_009890e0::CombatGroupStub *>((((::fnv_0099b5a0::Sound99 *)(reinterpret_cast<::EffectSetting *>((p1c4))->GetCastSound()))))->GetDetectedTargetLocation({}, *(::fnv_009890e0::CoordinateTriple *)nullptr))
                continue;
            if (((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(s2))->FUN_0084e3a0())) != ((void *)(reinterpret_cast<::s575ca0::Owner *>((mobj3))->FUN_00575ca0())))
                continue;
            v9 = *((::fnv_0099b5a0::P3 *)(new ((void *)&(s2)) ::Vec3()));
        }
        else
        {
            if (reinterpret_cast<::FUN_00435e00_t *>(&(clk))->FUN_00435e00() > 10.0)
                continue;
            v9 = pt84;
        }
        v9.z += ::FUN_009a8460((::S_009a8460_Actor *)(spellB), 2, 0);
        Vec3 d_ = (*(::fnv_0099b5a0::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(v9))->FUN_00439ef0((::NiPoint3 *)&(posVal), *(const ::NiPoint3 *)nullptr)));
        float len = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(d_))->GetSquaredXYLength();
        if (f6 * f6 < len)
            continue;
        if (len < 65536.0)
            continue;

        Sound99* snd2 = ((::fnv_0099b5a0::Sound99 *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(ammoA))));
        if (snd2)
        {
            if (!reinterpret_cast<::ThreatManager *>(((*reinterpret_cast<::fnv_0099b5a0::SndMgr99 * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->IsThreatWithinLimits((::ThreatActor *)(mobj3), (::ThreatActor *)(snd2), (*(const ::ThreatPosition *)((Vec3*)&v9)), 0.0f))
                continue;
        }
        P3 tB;
        if (FUN_009a7670(mobj3, spellB, ammoA, posVal, v9, (*reinterpret_cast<::fnv_0099b5a0::Vec3 *>((void *)&::NiPoint3::ZERO)), acArg, &tB, -1.0f))
        {
            if (snd2)
            {
                float r = ::ComputeProjectileFlightTime((::ShotActor *)(ammoA), (*(::Vec3 *)&(const ::fnv_0099b5a0::Vec3 &)(posVal)), (*(::Vec3 *)&(const ::fnv_0099b5a0::P3 &)(v9)), *acArg, 0.0f);
                if (!reinterpret_cast<::ThreatManager *>(((*reinterpret_cast<::fnv_0099b5a0::SndMgr99 * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->IsThreatWithinLimits((::ThreatActor *)(mobj3), (::ThreatActor *)(snd2), (*(const ::ThreatPosition *)((Vec3*)&v9)), r))
                    continue;
            }
            reinterpret_cast<::FUN_0099b8b0_shell *>((a1))->FUN_0099b8b0((int)((Vec3*)&v9), 0);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0099b5a0

namespace fnv_0099b8e0 {
struct QPoint
{
    float x, y, z;
    QPoint();
    QPoint operator-(const QPoint& rhs) const;
};

struct QWorldLoc
{
    QPoint& GetPoint();
};

struct QTarget
{
    unsigned char type;
    char pad1[7];
    QWorldLoc loc;
};

struct QRef
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
    virtual QPoint* GetPos();
};

struct QWeapon
{
};
struct QCombatInfo
{
    float GetMinRange(QPoint* out);
    float GetMaxRange(QPoint* out);
};
struct QProcess
{
    QWeapon* GetLoadedForm();
    QCombatInfo* GetCombatInfo();
};

struct QCombatCtrl
{
    QWeapon* GetLoadedForm();
    QCombatInfo* GetCombatInfo();
    float GetCoverHeight();
};

struct QSetting
{
};
struct QLock
{
};
struct QClock
{
};
struct QLockable
{
};
struct QMgr
{
};
struct QTimer
{
};
struct QCoverMgr
{
};

struct QStamp
{
    int v;
    QStamp(float f);
};

struct QSearchFlags
{
    bool a, b, c, d, e, f;
    QSearchFlags();
};

struct QLocElem
{
    char pad0[0x52];
    char state;
};

struct QLocSlot
{
};

struct QLocArray
{
    void* vtbl;
    void* data;
    int size;
    int capacity;
    void Clear(bool freeStorage);
};

struct QOut
{
    QPoint pos;
    QPoint dest;
    float radius;
    QStamp stamp;
    QLocArray locs;
    int key;
    int result;
    bool useCover;
};

struct QState
{
    char b0;
    char b1;
    char valid;
    char b3;
    int type;
    QPoint pos;
    QLocSlot slot;
    char pad18[0x50];
    int key;
    unsigned int timeStamp;
    QSearchFlags flags;
    void SetDirty(int);
};

struct QBuilder
{
    int data[0x3c];
    QBuilder();
    ~QBuilder();
};

struct QOrigin
{
    int data[0xa];
    QOrigin(QPoint* pos, QRef* actor);
    ~QOrigin();
};



struct FUN_0099b8e0_cls
{
    char pad0[0x84];
    QPoint coverPos;
    char pad90[8];
    QTimer timer;
    char pad9c[0x28];
    QTarget* target;
    char padc8[0xfc];
    QCombatCtrl* ctrl;
    char pad1c8[0x34];
    QCoverMgr coverMgr;

    bool FUN_0099b8e0(int a1, QOut* out, QState* st, int a4, int type);
};

// @fnv 0x0099b8e0
bool FUN_0099b8e0_cls::FUN_0099b8e0(int a1, QOut* out, QState* st, int a4, int aiSearchType)
{
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::fnv_0099b8e0::QLock *>(&::g_011f1a61))))->ClearData();
    float kMinHeight = ::DAT_010231a0;
    float dist7 = ::g_011c7b14_arg1;
    const int fMax2 = 200;
    QRef* self2 = ((::fnv_0099b8e0::QRef *)(::GetFieldBC((::FUN_0097ae90_Class *)(ctrl))));
    QRef* target = ((::fnv_0099b8e0::QRef *)(reinterpret_cast<::AlchemyItem *>((ctrl))->FUN_004030b0()));
    if (!target)
    {
        return false;
    }
    float f = 0.0f;
    float fMin3 = ::DAT_010231a0;
    float range5 = ::g_011c7b14_arg1;
    float cap3 = ::g_011c7b14_arg1;
    ::FUN_009a9180((::S_009a9180_Actor *)(ctrl), (::S_009a9180_Data *)(a1), &f, &range5, &cap3);
    range5 *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099b8e0::QSetting *>(&::originalRuntimeFloatSetting397))))));
    range5 = ::FUN_0040ebd0(range5, cap3);
    bool flag = false;
    bool flagB = false;
    bool flagC = false;
    bool flank = false;
    switch (aiSearchType)
    {
    case 12:
        fMin3 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099b8e0::QSetting *>(&::originalRuntimeFloatSetting436))))));
        dist7 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099b8e0::QSetting *>(&::originalRuntimeFloatSetting437))))));
        range5 = ::DAT_01022958;
        flagB = true;
        flagC = true;
        flank = true;
        break;
    case 10:
        range5 = ::DAT_01022958;
        flank = true;
        break;
    case 4:
        flank = true;
        flag = true;
        break;
    case 5:
        dist7 = ::DAT_01017a3c;
        range5 = ::DAT_01022958;
        flank = true;
        flagB = true;
        flagC = true;
        break;
    case 2:
        dist7 = reinterpret_cast<::BSMultiBoundSphere *>((((::fnv_0099b8e0::QWeapon *)(reinterpret_cast<::FUN_00980070_shell *>((ctrl))->FUN_00980070()))))->GetRadius();
        break;
    }
    int aUres = 0;
    float score5 = 0.0f;
    if (st->key)
    {
        out->key = st->key;
        out->result = 0;
        if (aiSearchType == st->type)
        {
            float half = fMin3 / ::DAT_01011590;
            if (reinterpret_cast<::SearchC *>(this)->FindPathCandidate((::SegmentC *)(void *)(&st->slot), (::DestinationC *)(a4), (::OptionsC *)(::fnv_0099b8e0::QSearchFlags *)(&st->flags), (::PointC *)(::fnv_0099b8e0::QPoint *)(&st->pos), (void *)(st->key), (void *)(st->key), aiSearchType, (::ActorC *)(self2), (::ActorC *)(target),
                                  half, range5, &aUres, &score5, flank))
            {
                reinterpret_cast<::FUN_005407b0_Class *>((st))->FUN_005407b0(0);
                reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::fnv_0099b8e0::QLock *>(&::g_011f1a61))))->ClearData();
                return true;
            }
            out->result = aUres;
        }
        else
        {
            out->result = 15;
        }
    }
    else
    {
        out->key = 0;
    }
    QPoint pos2;
    if (this->target && (this->target->type == 1 || this->target->type == 2))
    {
        pos2 = (*(::fnv_0099b8e0::QPoint *)(new ((void *)&(this->target->loc)) ::Vec3()));
        dist7 = reinterpret_cast<::FUN_009a0b00_s *>(this)->FUN_009a0b00();
    }
    else
    {
        pos2 = *self2->GetPos();
    }
    QBuilder builder2;
    QOrigin origin(&pos2, self2);
    reinterpret_cast<::FUN_006d3ac0_Class *>(&(builder2))->AssignPathingLocation((*(const ::PathingLocation *)(&origin)));
    if (aiSearchType == 5)
    {
        QPoint lo3;
        QPoint maxPt;
        float _lo = ((::fnv_0099b8e0::QCombatInfo *)(reinterpret_cast<::EffectSetting *>((ctrl))->GetCastSound()))->GetMinRange(&lo3);
        float hiA3 = ((::fnv_0099b8e0::QCombatInfo *)(reinterpret_cast<::EffectSetting *>((ctrl))->GetCastSound()))->GetMaxRange(&maxPt);
        out->pos = lo3;
        QPoint dir = maxPt - lo3;
        reinterpret_cast<::PathingRequestCover *>(&(builder2))->SetCover((*(const ::NiPoint3 *)(&dir)));
    }
    else
    {
        out->useCover = reinterpret_cast<::FUN_00435e00_t *>(&(timer))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099b8e0::QSetting *>(&::originalRuntimeFloatSetting376))))));
        if (out->useCover)
        {
            out->pos = coverPos;
        }
        else
        {
            out->pos = *target->GetPos();
        }
    }
    reinterpret_cast<::FUN_006dad40_Class *>(&(builder2))->FUN_006dad40((*(const ::NiPoint3 *)(&out->pos)));
    reinterpret_cast<::FUN_006e4340_Class *>(&(builder2))->FUN_006e4340(kMinHeight);
    reinterpret_cast<::FUN_006e4320_Class *>(&(builder2))->FUN_006e4320(dist7);
    reinterpret_cast<::AlchemyItem *>(&(builder2))->SetSound((::TESSound *)(fMax2));
    reinterpret_cast<::FUN_006e4380_Class *>(&(builder2))->SetFlagCE(flag);
    reinterpret_cast<::FUN_006e43a0_class *>(&(builder2))->FUN_006e43a0(flagB);
    reinterpret_cast<::FUN_006e43c0_class *>(&(builder2))->SetByteAtOffsetD0(flagC);
    reinterpret_cast<::PathingRequest *>(&(builder2))->SetActorRadius(reinterpret_cast<::FUN_004536e0_Class *>((ctrl))->GetFieldCC());
    reinterpret_cast<::FUN_005076c0Class *>(&(builder2))->FUN_005076c0(reinterpret_cast<::FUN_00453700_shell *>((ctrl))->FUN_00453700());
    reinterpret_cast<::FUN_008eeaa0Class *>(&(builder2))->FUN_008eeaa0(reinterpret_cast<::FUN_00998a30_shell *>((ctrl))->FUN_00998a30());
    reinterpret_cast<::FUN_006e43e0_class *>(&(builder2))->SetFlag(flank);
    st->type = aiSearchType;
    st->pos = out->pos;
    out->stamp = ::FUN_00435dd0();
    out->dest = pos2;
    out->radius = dist7;
    reinterpret_cast<::NavMeshSearchLOSArray *>(&(out->locs))->FUN_006dbde0(false);
    if (((int)(::FindNearbyTriangles((::GeometrySource *)(::fnv_0099b8e0::QBuilder *)(&builder2), (::OutputList *)(::fnv_0099b8e0::QLocArray *)(&out->locs)))))
    {
        reinterpret_cast<::FUN_0099c210_shell *>((((::fnv_0099b8e0::QLockable *)(reinterpret_cast<::FUN_009611e0_shell *>(((*reinterpret_cast<::fnv_0099b8e0::QMgr * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_009611e0()))))->LockCombatTargetMap();
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(out->locs))->GetName())); i++)
        {
            QLocElem* elem = ((::fnv_0099b8e0::QLocElem *)(reinterpret_cast<::FUN_009052c0_shell *>(&(out->locs))->FUN_009052c0(i)));
            int _resC = 0;
            float score8 = 0.0f;
            int id = ((int)(reinterpret_cast<::S_006e4570 *>((elem))->FUN_006e4570()));
            if (id != st->key)
            {
                unsigned int ts = ((unsigned int)(reinterpret_cast<::S_006e4740 *>((elem))->FUN_006e4740()));
                if (ts)
                {
                    if ((reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0099b8e0::QClock *>(&::g_timeGlobal))))->FUN_00825c00() - ts) / ::DAT_01017b70 < ::DAT_01021928)
                    {
                        elem->state = 1;
                        continue;
                    }
                }
                QSearchFlags flags;
                if (reinterpret_cast<::SearchC *>(this)->FindPathCandidate((::SegmentC *)(elem), (::DestinationC *)(a4), (::OptionsC *)(::fnv_0099b8e0::QSearchFlags *)(&flags), (::PointC *)(::fnv_0099b8e0::QPoint *)(&st->pos), (void *)(id), (void *)(0), aiSearchType, (::ActorC *)(self2), (::ActorC *)(target), fMin3, range5,
                                      &_resC, &score8, flank))
                {
                    elem->state = 19;
                    reinterpret_cast<::FUN_006e4430_class *>(&(st->slot))->operator=((*(const ::FUN_006e4430_class *)(elem)));
                    st->key = id;
                    st->timeStamp = ts;
                    st->flags = flags;
                    st->valid = reinterpret_cast<::FUN_0099c1f0_shell *>(&(st->slot))->FUN_0099c1f0();
                    reinterpret_cast<::FUN_005407b0_Class *>((st))->FUN_005407b0(0);
                    reinterpret_cast<::TimeoutTimer *>(&(coverMgr))->FUN_00910b10();
                    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::fnv_0099b8e0::QLock *>(&::g_011f1a61))))->ClearData();
                    return true;
                }
                elem->state = _resC;
            }
            else
            {
                elem->state = aUres;
            }
        }
        reinterpret_cast<::FUN_00995890_shell *>((((::fnv_0099b8e0::QLockable *)(reinterpret_cast<::FUN_009611e0_shell *>(((*reinterpret_cast<::fnv_0099b8e0::QMgr * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_009611e0()))))->FUN_00995890();
    }
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::fnv_0099b8e0::QLock *>(&::g_011f1a61))))->ClearData();
    return false;
}
}  // namespace fnv_0099b8e0

struct Pos9f48
{
    float x, y, z;
    float w;
    float FUN_00527a40(const Pos9f48& kOther);
};

struct Tile9f48
{
};

struct Process9f48
{
};

struct Actor9f48
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual bool IsAlive();
    virtual void W065();
    virtual void W066();
    virtual void W067();
    virtual void W068();
    virtual void W069();
    virtual void W070();
    virtual void W071();
    virtual void W072();
    virtual void W073();
    virtual void W074();
    virtual void W075();
    virtual void W076();
    virtual void W077();
    virtual void W078();
    virtual void W079();
    virtual void W080();
    virtual void W081();
    virtual void W082();
    virtual void W083();
    virtual void W084();
    virtual void W085();
    virtual void W086();
    virtual void W087();
    virtual void W088();
    virtual void W089();
    virtual void W090();
    virtual void W091();
    virtual void W092();
    virtual void W093();
    virtual void W094();
    virtual void W095();
    virtual void W096();
    virtual void W097();
    virtual void W098();
    virtual void W099();
    virtual void W100();
    virtual void W101();
    virtual void W102();
    virtual void W103();
    virtual void W104();
    virtual void W105();
    virtual void W106();
    virtual void W107();
    virtual void W108();
    virtual void W109();
    virtual void W110();
    virtual void W111();
    virtual void W112();
    virtual void W113();
    virtual void W114();
    virtual void W115();
    virtual void W116();
    virtual void W117();
    virtual void W118();
    virtual void W119();
    virtual void W120();
    virtual void W121();
    virtual void W122();
    virtual void W123();
    virtual void W124();
    virtual void W125();
    virtual void W126();
    virtual void W127();
    virtual void W128();
    virtual void W129();
    virtual void W130();
    virtual void W131();
    virtual void W132();
    virtual void W133();
    virtual void W134();
    virtual void W135();
    virtual void W136();
    virtual void W137();
    virtual void W138();
    virtual void W139();
    virtual void W140();
    virtual void W141();
    virtual void W142();
    virtual void W143();
    virtual void W144();
    virtual void W145();
    virtual void W146();
    virtual void W147();
    virtual void W148();
    virtual void W149();
    virtual void W150();
    virtual void W151();
    virtual void W152();
    virtual void W153();
    virtual void W154();
    virtual void W155();
    virtual void W156();
    virtual void W157();
    virtual void W158();
    virtual void W159();
    virtual void W160();
    virtual void W161();
    virtual void W162();
    virtual void W163();
    virtual void W164();
    virtual void W165();
    virtual void W166();
    virtual void W167();
    virtual void W168();
    virtual void W169();
    virtual void W170();
    virtual void W171();
    virtual void W172();
    virtual void W173();
    virtual void W174();
    virtual void W175();
    virtual void W176();
    virtual void W177();
    virtual void W178();
    virtual void W179();
    virtual void W180();
    virtual void W181();
    virtual void W182();
    virtual void W183();
    virtual void W184();
    virtual void W185();
    virtual void W186();
    virtual void W187();
    virtual void W188();
    virtual void W189();
    virtual void W190();
    virtual void W191();
    virtual void W192();
    virtual void W193();
    virtual void W194();
    virtual void W195();
    virtual void W196();
    virtual void W197();
    virtual void W198();
    virtual void W199();
    virtual void W200();
    virtual void W201();
    virtual void W202();
    virtual void W203();
    virtual void W204();
    virtual void W205();
    virtual void W206();
    virtual void W207();
    virtual void W208();
    virtual void W209();
    virtual void W210();
    virtual void W211();
    virtual void W212();
    virtual void W213();
    virtual void W214();
    virtual void W215();
    virtual void W216();
    virtual void W217();
    virtual void W218();
    virtual void W219();
    virtual void W220();
    virtual void W221();
    virtual void W222();
    virtual void W223();
    virtual void W224();
    virtual void W225();
    virtual void W226();
    virtual void W227();
    virtual void W228();
    virtual void W229();
    virtual void W230();
    virtual void W231();
    virtual void W232();
    virtual void W233();
    virtual void W234();
    virtual void W235();
    virtual void W236();
    virtual void W237();
    virtual void W238();
    virtual void W239();
    virtual void W240();
    virtual void W241();
    virtual void W242();
    virtual void W243();
    virtual void W244();
    virtual void W245();
    virtual void W246();
    virtual void W247();
    virtual void W248();
    virtual void W249();
    virtual void W250();
    virtual void W251();
    virtual void W252();
    virtual void W253();
    virtual void W254();
    virtual void W255();
    virtual void W256();
    virtual void W257();
    virtual void W258();
    virtual void W259();
    virtual void W260();
    virtual void W261();
    virtual void W262();
    virtual void W263();
    virtual void W264();
    virtual void W265();
    virtual Process9f48* GetProcess();
    float FUN_008be1b0();
};

struct Group9f48
{
};

struct Controller9f48
{
};

struct Request9f48
{
    char m_acPad[0x10];
    Actor9f48* m_pkTarget;
};

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    float* FUN_00403e20();
};

struct Planner9f48
{
    char m_acPad[0x1c4];
    Controller9f48* m_pkController;
    bool TryAssignAllyTarget(Request9f48* pkRequest, int iUnused);
};

// @fnv 0x0099f480
bool Planner9f48::TryAssignAllyTarget(Request9f48* pkRequest, int iUnused)
{
    Group9f48* pkGroupList = ((::Group9f48 *)(reinterpret_cast<::EffectSetting *>((m_pkController))->GetCastSound()));
    if (pkRequest->m_pkTarget && pkRequest->m_pkTarget->IsAlive())
    {
        Actor9f48* pkTarget = pkRequest->m_pkTarget;
        if (((bool)(reinterpret_cast<::FUN_00986a80_shell *>((pkGroupList))->FUN_00986a80((int)(pkTarget)))))
        {
            Process9f48* pkProcess = pkTarget->GetProcess();
            if (pkProcess && reinterpret_cast<::fnv_00998980::FUN_00998980_shell *>((((::Tile9f48 *)(reinterpret_cast<::InterfaceManager *>((pkProcess))->FUN_00586150()))))->FUN_00998980())
                return true;
            else if (reinterpret_cast<::Proxy88c600 *>((pkTarget))->IsTargetIn360View((::Actor *)(void *)(reinterpret_cast<::AlchemyItem *>((m_pkController))->FUN_004030b0())))
                return true;
        }
    }
    Actor9f48* pkOwner = ((::Actor9f48 *)(::GetFieldBC((::FUN_0097ae90_Class *)(m_pkController))));
    Pos9f48 kOwnerPos;
    reinterpret_cast<::FUN_00575650_Class *>((pkOwner))->FUN_00575650((::FUN_00575650_Result *)(::Pos9f48 *)(&kOwnerPos));
    Actor9f48* pkAlly = 0;
    float fClosest = 67108864.0f;
    unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00990890_shell *>((pkGroupList))->FUN_00990890();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Actor9f48* pkMember = ((::Actor9f48 *)(reinterpret_cast<::Target *>((pkGroupList))->GetIntAt(i)));
        if (pkMember == pkOwner)
            continue;
        bool bUsable = false;
        Process9f48* pkOtherProcess = pkMember->GetProcess();
        if (pkOtherProcess && reinterpret_cast<::fnv_00998980::FUN_00998980_shell *>((((::Tile9f48 *)(reinterpret_cast<::InterfaceManager *>((pkOtherProcess))->FUN_00586150()))))->FUN_00998980())
            bUsable = true;
        else if (reinterpret_cast<::Proxy88c600 *>((pkMember))->IsTargetIn360View((::Actor *)(void *)(reinterpret_cast<::AlchemyItem *>((m_pkController))->FUN_004030b0())))
            bUsable = true;
        if (!bUsable)
            continue;
        Pos9f48 kPos;
        reinterpret_cast<::FUN_00575650_Class *>((pkMember))->FUN_00575650((::FUN_00575650_Result *)(::Pos9f48 *)(&kPos));
        float fDistance = kPos.FUN_00527a40(kOwnerPos);
        if (fDistance >= fClosest)
            continue;
        if (!reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>(this)->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&kPos)), 1, 0))
            continue;
        pkAlly = pkMember;
        fClosest = fDistance;
    }
    if (pkAlly)
    {
        reinterpret_cast<::fnv_00997400::CombatAvoidanceSphere *>((pkRequest))->FUN_00997400((::TESObjectREFR *)(pkAlly));
        reinterpret_cast<::FUN_00819a50_shell *>((pkRequest))->FUN_00819a50(pkAlly->FUN_008be1b0() + pkOwner->FUN_008be1b0() +
                                *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting430)))));
        return true;
    }
    return false;
}

namespace CombatFind {

struct CombatPoint3
{
    float x, y, z;
};

struct CombatSpot;

struct CombatCell
{
};

struct CombatPos
{
    float x, y, z, w;
    CombatPos();
};

struct CombatRef
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual CombatPoint3* GetPos();
    float FUN_008be1b0();
};

struct CombatSpot
{
    CombatSpot();
    CombatCell* FUN_0097b940();
    int CallReferencedFunction();
    int iData[8];
};

struct CombatSearch
{
    CombatSearch();
    ~CombatSearch();
    void FUN_00997480(void* apSource);
    char pad00[0x68];
    int iCount;
    int iData[3];
};

struct CombatTimed
{
};

struct CombatTyped
{
    int iValue;
    int iType;
};

struct CombatTargetInfo
{
    bool bInvalid;
    char pad01[3];
    CombatRef* pRef;
    CombatPos kPos;
    float fRadius;
};

struct CombatSlot
{
    CombatRef* pRef;
};

struct CombatPathing
{
};

struct CombatLocations
{
};

struct CombatController
{
};

struct CombatTypeInfo
{
    bool bSkipSearch;
    bool bMeasure;
    char pad02[2];
    float fRadius;
};

struct CombatSetting
{
};


struct CombatStateQ
{
    char pad00[0x18];
    int iTargetCount;
    char pad1c[0x5a];
    char acFlags[0x4e];
    CombatTargetInfo* pTargetInfo;
    char padc8[0x1c];
    CombatTyped* pTyped;
    char pade8[4];
    char kEC[0xa0];
    CombatTimed* pTimed;
    char pad190[0x34];
    CombatController* pController;

    bool FUN_0097ee90();
    bool FUN_0099d030(void* apData, CombatSearch* apSearch, CombatSpot* apSpot, int aiType, CombatPos* apPos,
                      float afRadius, int a7);
    bool FUN_0099ac20(int aiType);
};

// Finds a location for aiType using a CombatSpot and CombatSearch, then stores the result through pLocationsRes.
// @fnv 0x0099ac20
bool CombatStateQ::FUN_0099ac20(int aiType)
{
    CombatRef* pActorOld = ((::CombatFind::CombatRef *)(::GetFieldBC((::FUN_0097ae90_Class *)(pController))));
    CombatRef* pTarget = ((::CombatFind::CombatRef *)(reinterpret_cast<::AlchemyItem *>((pController))->FUN_004030b0()));
    CombatPathing* pPathingTmp = ((::CombatFind::CombatPathing *)(reinterpret_cast<::EffectSetting *>((pController))->GetCastSound()));
    CombatLocations* pLocationsRes = ((::CombatFind::CombatLocations *)(reinterpret_cast<::FUN_005e3fc0_shell *>((pController))->Get()));
    if (reinterpret_cast<::FUN_00980700_shell *>((pLocationsRes))->FUN_00980700(aiType))
    {
        reinterpret_cast<::fnv_00979f70::FUN_00979f70_shell *>((pLocationsRes))->FUN_00979f70(aiType);
        return true;
    }
    else if (reinterpret_cast<::CombatActionStandIn *>((pLocationsRes))->FUN_0097bd00(aiType) == ::DAT_0108df70)
    {
        return false;
    }
    bool bFound = false;
    CombatSpot* pFinalSpot = new CombatSpot();
    CombatSearch* pSearch = new CombatSearch();
    reinterpret_cast<::FUN_00600ab0_shell *>((pFinalSpot))->FUN_00600ab0(aiType);
    reinterpret_cast<::FUN_00819a50_shell *>((pFinalSpot))->FUN_00819a50((*reinterpret_cast<CombatFind::CombatTypeInfo (*)[]>(&::MoveModes))[aiType].fRadius);
    if (pTimed && ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pTimed))->FUN_00825c00())) == aiType)
    {
        reinterpret_cast<::FUN_009973a0_class *>((pFinalSpot))->FUN_009973a0((const ::FUN_009973a0_class *)(pTimed));
        if (pTyped && pTyped->iType == aiType)
            pSearch->FUN_00997480(pTyped);
        if (!(*reinterpret_cast<CombatFind::CombatTypeInfo (*)[]>(&::MoveModes))[aiType].bSkipSearch)
        {
            reinterpret_cast<::Outer_997440 *>((pFinalSpot))->CopyRefValue();
            bFound = true;
        }
    }
    bool bFlag = false;
    switch (aiType)
    {
    case 10:
    case 12:
    case 15:
        bFlag = true;
    }
    if (!bFound)
    {
        switch (aiType)
        {
        case 0:
        case 1:
            if (pTarget)
            {
                if (FUN_0097ee90())
                {
                    if (!reinterpret_cast<::FUN_0097fd40_shell *>(this)->FUN_0097fd40())
                    {
                        reinterpret_cast<::fnv_00997400::CombatAvoidanceSphere *>((pFinalSpot))->FUN_00997400((::TESObjectREFR *)(pTarget));
                        bFound = true;
                    }
                }
                else
                {
                    CombatPos kPoint;
                    if (reinterpret_cast<::fnv_009890e0::CombatGroupStub *>((pPathingTmp))->GetDetectedTargetLocation((::fnv_009890e0::Actor *)(pTarget), (*(::fnv_009890e0::CoordinateTriple *)(&kPoint))))
                    {
                        reinterpret_cast<::FUN_0097ee60_shell *>((pFinalSpot))->AssignV4((::V4 *)(::CombatFind::CombatPos *)(&kPoint));
                        bFound = true;
                    }
                }
            }
            break;
        case 2:
        case 4:
        case 5:
            bFound = reinterpret_cast<::fnv_0099b8e0::FUN_0099b8e0_cls *>(this)->FUN_0099b8e0((int)(((void *)(::FUN_007031c0((int)(pController))))), (::fnv_0099b8e0::QOut *)(kEC), (::fnv_0099b8e0::QState *)(pSearch), (int)(pFinalSpot), aiType);
            break;
        case 3:
            bFound = reinterpret_cast<::FUN_0099e190_cls *>(this)->SelectAndMoveToPoint((::MyMover *)(pFinalSpot), 3, 0xf, 128.0f, 128.0f);
            break;
        case 6:
            if (pTargetInfo && !pTargetInfo->bInvalid)
            {
                bFound = FUN_0099d030(kEC, pSearch, pFinalSpot, aiType, (CombatPos*)((::CombatFind::CombatCell *)(new ((void *)&(pTargetInfo->kPos)) ::Vec3())),
                                      0.0f, 0);
            }
            else if (((::CombatFind::CombatRef *)(reinterpret_cast<::AlchemyItem *>((pController))->FUN_004030b0())))
            {
                CombatPoint3 kTargetPos = *((::CombatFind::CombatRef *)(reinterpret_cast<::AlchemyItem *>((pController))->FUN_004030b0()))->GetPos();
                bFound = FUN_0099d030(kEC, pSearch, pFinalSpot, aiType, (CombatPos*)&kTargetPos, 0.0f, 0);
            }
            break;
        case 7:
        case 8:
        case 9:
        case 16:
            if (pTargetInfo && (aiType != 8 || !reinterpret_cast<::TESActorBaseData *>(this)->GetFlag(1 << aiType)))
            {
                if (pTargetInfo->pRef)
                {
                    reinterpret_cast<::fnv_00997400::CombatAvoidanceSphere *>((pFinalSpot))->FUN_00997400((::TESObjectREFR *)(pTargetInfo->pRef));
                    if (pTargetInfo->pRef->IsActor())
                    {
                        CombatRef* pActor = pTargetInfo->pRef;
                        reinterpret_cast<::FUN_00819a50_shell *>((pFinalSpot))->FUN_00819a50(pActor->FUN_008be1b0() + pActorOld->FUN_008be1b0());
                    }
                }
                else
                {
                    reinterpret_cast<::FUN_0097ee60_shell *>((pFinalSpot))->AssignV4((::V4 *)(::CombatFind::CombatPos *)(&pTargetInfo->kPos));
                }
                reinterpret_cast<::FUN_00819a50_shell *>((pFinalSpot))->FUN_00819a50(pTargetInfo->fRadius);
                bFound = true;
            }
            break;
        case 11:
            bFound = reinterpret_cast<::fnv_0099b5a0::FUN_0099b5a0_holder *>(this)->FUN_0099b5a0((::fnv_0099b5a0::A1_99 *)(pFinalSpot), acFlags, (::fnv_0099b5a0::Weap99 *)(iTargetCount));
            break;
        case 10:
        case 12:
            bFound = reinterpret_cast<::Self99 *>(this)->FUN_0099ebe0(pSearch, (::Out99 *)(pFinalSpot), aiType);
            break;
        case 13:
            bFound = reinterpret_cast<::Planner9f48 *>(this)->TryAssignAllyTarget((::Request9f48 *)(pFinalSpot), aiType);
            break;
        case 14:
            reinterpret_cast<::FUN_0099b540_s *>((pFinalSpot))->SetFlags(1, 1);
            bFound = true;
            break;
        case 15: {
            CombatPos* pCover = ((::CombatFind::CombatPos *)(reinterpret_cast<::ItemList *>((((::CombatFind::CombatPathing *)(reinterpret_cast<::EffectSetting *>((pController))->GetCastSound()))))->FindBestItem((::ActorObj *)(pActorOld), 0x32, (::ItemObj *)(::CombatFind::CombatPos *)(((::CombatFind::CombatPos *)(new ((void *)(pFinalSpot)) ::Vec3()))))));
            if (pCover)
            {
                reinterpret_cast<::FUN_0097ee60_shell *>((pFinalSpot))->AssignV4((::V4 *)(pCover));
                bFound = true;
            }
            else if (reinterpret_cast<::NiPlane *>((pFinalSpot->FUN_0097b940()))->operator==((*(const ::NiPlane *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))))))
            {
                bFound = true;
            }
            if (bFound)
                reinterpret_cast<::FUN_0099b540_s *>((pFinalSpot))->SetFlags(2, 1);
            break;
        }
        case 17:
        case 18:
        case 19:
        case 20:
        case 21: {
            CombatSlot* pSlot = ((::CombatFind::CombatSlot *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>(this)->GetActionAtIndex(aiType - 0x11)));
            if (pSlot && pSlot->pRef)
            {
                reinterpret_cast<::fnv_00997400::CombatAvoidanceSphere *>((pFinalSpot))->FUN_00997400((::TESObjectREFR *)(pSlot->pRef));
                reinterpret_cast<::FUN_00819a50_shell *>((pFinalSpot))->FUN_00819a50(reinterpret_cast<::TESObjectREFR *>((pSlot->pRef))->GetBoundingRadius() + reinterpret_cast<::fnv_008be420::Dd *>((pActorOld))->FUN_008be420() +
                                         *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatFind::CombatSetting *>(&::originalRuntimeFloatSetting374)))))));
                reinterpret_cast<::FUN_0099b540_s *>((pFinalSpot))->SetFlags(2, 1);
                bFound = true;
            }
            break;
        }
        default:
            ::FUN_005b5e40();
        }
    }
    if (bFound)
    {
        if (!pFinalSpot->CallReferencedFunction())
            reinterpret_cast<::FUN_0099b520_shell *>((pFinalSpot))->FUN_0099b520((::MagicItem *)(void *)(((void *)(reinterpret_cast<::s575ca0::Owner *>((pActorOld))->FUN_00575ca0()))));
        CombatPos kSpotPosTmp = *((::CombatFind::CombatPos *)(new ((void *)(pFinalSpot)) ::Vec3()));
        if (reinterpret_cast<::NiPoint3 *>((((::CombatFind::CombatCell *)(new ((void *)&(kSpotPosTmp)) ::Vec3()))))->FUN_004390c0((*(const ::NiPoint3 *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))))) || reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>(this)->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&kSpotPosTmp)), 1, bFlag))
        {
            float fDistance = 0.0f;
            if ((*reinterpret_cast<CombatFind::CombatTypeInfo (*)[]>(&::MoveModes))[aiType].bMeasure)
            {
                CombatPos kActorPos = (*(::CombatFind::CombatPos *)(reinterpret_cast<::FUN_00575650_Class *>((pActorOld))->FUN_00575650({})));
                fDistance = ::FUN_0097acb0((::CombatController *)(pController), (::CoordinateTriple *)(::CombatFind::CombatPos *)(&kActorPos), (::CoordinateTriple *)(::CombatFind::CombatPos *)(&kSpotPosTmp));
            }
            reinterpret_cast<::FUN_00995980_class *>((pLocationsRes))->SetEntry(aiType, (int)(pFinalSpot), fDistance);
            if (pSearch->iCount)
                reinterpret_cast<::FUN_009959c0Class *>((pLocationsRes))->FUN_009959c0(aiType, (int)(pSearch));
            else
                delete pSearch;
            return true;
        }
    }
    delete pFinalSpot;
    delete pSearch;
    reinterpret_cast<::FUN_00995980_class *>((pLocationsRes))->SetEntry(aiType, (int)(0), ::DAT_0108df70);
    return false;
}

}

namespace fnv_0097ee90 {
class GameSettingCollection;

template <class T> class SettingT
{
  public:
    float* Float();
};


class CTSHelper
{
  public:
};

struct DummyInner
{
    char pad94[0x94];
    CTSHelper m_kTime;
    bool FUN_0097ee90();
};

// Returns true when m_kTime.GetElapsedTime() is less than the value of originalRuntimeFloatSetting412.
// @fnv 0x0097ee90
bool DummyInner::FUN_0097ee90()
{
    return (double)reinterpret_cast<::FUN_00435e00_t *>(&(m_kTime))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0097ee90::SettingT< ::fnv_0097ee90::GameSettingCollection> *>(&::originalRuntimeFloatSetting412))))));
}
}  // namespace fnv_0097ee90

namespace fnv_0099d030 {
union SETTING_VALUE
{
    float f;
};

class GameSettingCollection;
template <typename T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

class TESObjectREFR
{
  public:
    int unk00;
};

struct Actor : public TESObjectREFR
{
    float FUN_008be1b0();
};

class ActiveEffect
{
  public:
};

class FUN_00980070_shell
{
  public:
};

class AlchemyItem : public FUN_00980070_shell
{
  public:
};

class TESAmmoInitCalls : public AlchemyItem
{
  public:
};

class CalendarDays
{
  public:
};

class FUN_009611e0_shell
{
  public:
};

class TESWorldSpace : public FUN_009611e0_shell
{
};

class GlobalObject_0045d260
{
  public:
};

class NiPoint3;

class Arg0Class
{
  public:
    int unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c;
    int unk30;
};

class Arg1Class
{
  public:
    int unk00;
    int unk04;
    int unk08, unk0c, unk10;
    int unk14;
    int unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c, unk_30, unk_34, unk_38, unk_3c, unk_40, unk_44, unk_48, unk_4c,
        unk_50, unk_54, unk_58, unk_5c, unk_60, unk_64;
    void* unk68;
    int unk6c;
    int unk70;
    char unk74;
    bool unk75;
};

class FUN_0099b8b0_shell
{
  public:
};

class Arg2Class : public FUN_0099b8b0_shell
{
};

class PathingLocation
{
  public:
    PathingLocation(TESObjectREFR* actor);
    PathingLocation(const NiPoint3& pt, TESObjectREFR* actor);
    ~PathingLocation();
    int unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24;
};

class PathingRequest
{
  public:
    void FUN_006e4bf0();
    int unk_000, unk_004, unk_008, unk_00c, unk_010, unk_014, unk_018, unk_01c;
    int unk_020, unk_024, unk_028, unk_02c, unk_030, unk_034, unk_038, unk_03c;
    int unk_040, unk_044, unk_048, unk_04c, unk_050, unk_054, unk_058, unk_05c;
    int unk_060, unk_064, unk_068, unk_06c, unk_070, unk_074, unk_078, unk_07c;
    int unk_080, unk_084, unk_088, unk_08c, unk_090, unk_094, unk_098, unk_09c;
    int unk_0a0, unk_0a4, unk_0a8, unk_0ac, unk_0b0, unk_0b4, unk_0b8, unk_0bc;
    int unk_0c0, unk_0c4, unk_0c8, unk_0cc, unk_0d0, unk_0d4, unk_0d8, unk_0dc;
    int unk_0e0, unk_0e4, unk_0e8, unk_0ec, unk_0f0, unk_0f4, unk_0f8, unk_0fc;
    int unk_100, unk_104, unk_108;
};

class FUN_006e4a50 : public PathingRequest
{
  public:
    FUN_006e4a50();
    __forceinline ~FUN_006e4a50()
    {
        FUN_006e4bf0();
    }
};


class CombatController
{
  public:
    int unk_000, unk_004, unk_008, unk_00c, unk_010, unk_014, unk_018, unk_01c;
    int unk_020, unk_024, unk_028, unk_02c, unk_030, unk_034, unk_038, unk_03c;
    int unk_040, unk_044, unk_048, unk_04c, unk_050, unk_054, unk_058, unk_05c;
    int unk_060, unk_064, unk_068, unk_06c, unk_070, unk_074, unk_078, unk_07c;
    int unk_080, unk_084, unk_088, unk_08c, unk_090, unk_094, unk_098, unk_09c;
    int unk_0a0, unk_0a4, unk_0a8, unk_0ac, unk_0b0, unk_0b4, unk_0b8, unk_0bc;
    int unk_0c0, unk_0c4, unk_0c8, unk_0cc, unk_0d0, unk_0d4, unk_0d8, unk_0dc;
    int unk_0e0, unk_0e4, unk_0e8, unk_0ec, unk_0f0, unk_0f4, unk_0f8, unk_0fc;
    int unk_100, unk_104, unk_108, unk_10c, unk_110, unk_114, unk_118, unk_11c;
    int unk_120, unk_124, unk_128, unk_12c, unk_130, unk_134, unk_138, unk_13c;
    int unk_140, unk_144, unk_148, unk_14c, unk_150, unk_154, unk_158, unk_15c;
    int unk_160, unk_164, unk_168, unk_16c, unk_170, unk_174, unk_178, unk_17c;
    int unk_180, unk_184, unk_188, unk_18c, unk_190, unk_194, unk_198, unk_19c;
    int unk_1a0, unk_1a4, unk_1a8, unk_1ac, unk_1b0, unk_1b4, unk_1b8, unk_1bc;
    int unk_1c0;
    TESAmmoInitCalls* member_1c4;
    bool FUN_0099d030(Arg0Class* a0, Arg1Class* a1, Arg2Class* a2, int a3, const NiPoint3& a4, float a5, void* a6);
};

// Attempts to use a cover item, then builds a PathingRequest and calls FindCombatPosition to locate a combat position for the actor.
// @fnv 0x0099d030
bool CombatController::FUN_0099d030(Arg0Class* a0, Arg1Class* a1, Arg2Class* a2, int a3, const NiPoint3& a4, float a5,
                                    void* a6)
{
    float fTmp = 1024.0f;
    float f2 = 2048.0f;
    int i1_2 = 200;
    Actor* actor = ((::fnv_0099d030::Actor *)(::GetFieldBC((::FUN_0097ae90_Class *)(this->member_1c4))));
    int i4 = ((int)(reinterpret_cast<::AlchemyItem *>((this->member_1c4))->FUN_004030b0()));
    float val4 = (a5 != 0.0) ? a5 : 256.0f;
    if (a3 == 6)
    {
        val4 = ((::fnv_0099d030::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099d030::SettingT< ::fnv_0099d030::GameSettingCollection> *>(&::originalRuntimeFloatSetting401))))))->f +
               ((1.0f - ::GetFloatAtOffset1C((char *)(((ActiveEffect*)reinterpret_cast<::FUN_00980070_shell *>((this->member_1c4))->FUN_00980070()))) / 100.0f) *
                (((::fnv_0099d030::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099d030::SettingT< ::fnv_0099d030::GameSettingCollection> *>(&::originalRuntimeFloatSetting402))))))->f - ((::fnv_0099d030::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0099d030::SettingT< ::fnv_0099d030::GameSettingCollection> *>(&::originalRuntimeFloatSetting401))))))->f));
    }
    a0->unk30 = 0;
    if (a1->unk68 != 0 && a3 == a1->unk04)
    {
        if (reinterpret_cast<::FUN_009835d0_cls *>((((CalendarDays*)reinterpret_cast<::FUN_009611e0_shell *>(((*reinterpret_cast<::fnv_0099d030::TESWorldSpace * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_009611e0())))->TryUseCoverItem((unsigned int)(a1->unk68), (unsigned int)(&a1->unk14), (unsigned int)(this->member_1c4), actor->FUN_008be1b0(), &a1->unk70, 1,
                                  a1->unk75))
        {
            return true;
        }
    }
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::fnv_0099d030::GlobalObject_0045d260 *>(&::g_011f1a63))))->ClearData();
    FUN_006e4a50 req2;
    reinterpret_cast<::FUN_0099d310_shell *>((this))->FUN_0099d310((::FUN_0099d310_arg *)(::fnv_0099d030::PathingRequest *)(&req2));
    PathingLocation loc1(actor);
    reinterpret_cast<::FUN_006d3ac0_Class *>(&(req2))->AssignPathingLocation((*(const ::PathingLocation *)(&loc1)));
    PathingLocation loc2(a4, actor);
    reinterpret_cast<::PathingRequest *>(&(req2))->SetDestination((::PathingLocation *)(::fnv_0099d030::PathingLocation *)(&loc2));
    reinterpret_cast<::FUN_006d30e0_Class *>(&(req2))->FUN_006d30e0((int)a0);
    reinterpret_cast<::HX *>(&(req2))->FUN_006d3100((::CombatCoverPointData *)(a1));
    reinterpret_cast<::PathingRequest *>(&(req2))->SetAvoidNodeArray((::BSSimpleArray<void *, 1024> *)(a6));
    reinterpret_cast<::FUN_00705b10_Dummy *>(&(req2))->Set(a3);
    bool retVal7 = ::CombatPosition::FindCombatPosition((::CombatPosition::Actor *)(::fnv_0099d030::PathingRequest *)(&req2), val4, 0);
    if (retVal7)
    {
        reinterpret_cast<::FUN_0099b8b0_shell *>((a2))->FUN_0099b8b0((int)::FUN_006377e0((int)&(req2)), 0);
    }
    reinterpret_cast<::FUN_006d3120_Class *>(&(req2))->FUN_006d3120();
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::fnv_0099d030::GlobalObject_0045d260 *>(&::g_011f1a63))))->ClearData();
    return retVal7;
}
}  // namespace fnv_0099d030

namespace fnv_006d3150 {
struct NiPoint3
{
    float x, y, z;
};

struct FUN_006d3200
{
    char pad[0x54];
    FUN_006d3200();
    ~FUN_006d3200();
};

struct FUN_006d3280_s
{
};

struct FUN_006d3150
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    NiPoint3 point8;
    FUN_006d3200 member14;
    int dword68;
    int dword6c;
    FUN_006d3280_s member70;

    FUN_006d3150();
};

// Initializes the listed fields, constructs member14, and calls ClearFlags on member70.
// @fnv 0x006d3150
FUN_006d3150::FUN_006d3150()
    : byte0(0), byte1(0), byte2(0), dword4(0), point8((*reinterpret_cast<::fnv_006d3150::NiPoint3 *>((void *)&::NiPoint3::ZERO))), member14(), dword68(0), dword6c(-1)
{
    reinterpret_cast<::FUN_006d3280_s *>(&(member70))->ClearFlags();
}
}  // namespace fnv_006d3150

namespace fnv_00997600 {
extern "C" void* __cdecl memset(void*, int, size_t);

const float kFltMax = 3.402823466e+38F;
struct Pt3
{
    float x, y, z;
};

struct Setting
{
};


struct A24
{
    int unk0, unk4, unk8, unkC;
    A24();
    ~A24();
};
struct FloatW
{
    float f;
    FloatW(float v);
};
struct P2
{
    float x, y;
    P2();
};
struct W4
{
    int v;
    W4();
};
struct B3C
{
    int unk[15];
    B3C();
    ~B3C();
};
struct C10
{
    int unk0, unk4, unk8, unkC;
    C10();
    ~C10();
};
struct D10
{
    int unk0, unk4, unk8, unkC;
    D10();
    ~D10();
};
struct E4
{
    int v;
    E4(int a);
    ~E4();
};

struct FUN_00997600
{
    char b00;
    int unk04;
    float f08;
    int unk0C, unk10, unk14, unk18, unk1C, unk20;
    A24 a24;
    int unk34;
    int unk38;
    int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
    float f58, f5C, f60, f64, f68;
    int unk6C;
    char b70, b71, b72, b73, b74, b75, b76, b77;
    int unk78;
    int unk7C;
    float f80;
    Pt3 p84;
    int unk90;
    FloatW w94, w98, w9C, wA0, wA4;
    P2 pA8, pB0, pB8;
    W4 wC0;
    int unkC4;
    char bC8, bC9;
    float fCC;
    float fD0, fD4;
    char bD8;
    int unkDC;
    FloatW wE0;
    int unkE4;
    int unkE8;
    B3C bEC;
    B3C b128;
    C10 c164;
    D10 d174;
    W4 w184;
    char b188;
    int unk18C;
    int unk190, unk194, unk198, unk19C, unk1A0;
    int unk1A4, unk1A8;
    P2 arr1AC[2];
    int unk1BC;
    int unk1C0;
    int unk1C4;
    bool b1C8;
    P2 p1CC, p1D4, p1DC, p1E4, p1EC, p1F4, p1FC, p204, p20C, p214, p21C;
    E4 e224;
    int unk228;

    FUN_00997600(int a, int b);
};

// Initializes selected fields, stores a in unk1C4, sets p20C from g_set804, and computes fCC from g_setdcc and g_set7ec.
// @fnv 0x00997600
FUN_00997600::FUN_00997600(int aiUnk, int aiUnk2)
    : b00(0), unk04(0), f08(100.0f), unk34(0), unk38(0), f58(0.0f), f5C(0.0f), f60(0.0f), f64(0.0f), f68(0.0f),
      unk6C(-1), b70(0), b71(0), b72(0), b73(-1), b74(0), b75(0), b76(0), b77(0), unk78(0), unk7C(3), f80(0.0f),
      p84((*reinterpret_cast<::fnv_00997600::Pt3 *>((void *)&::NiPoint3::ZERO))), unk90(0), w94(-kFltMax), w98(-kFltMax), w9C(-kFltMax), wA0(-kFltMax), wA4(-kFltMax), unkC4(0),
      bC8(0), bC9(0), fD0(-1.0f), fD4(-1.0f), bD8(0), unkDC(0), wE0(-kFltMax), unkE4(0), unkE8(0), b188(-1), unk18C(0),
      unk1BC(0), unk1C0(0), unk1C4(aiUnk), b1C8(true), e224(0), unk228(-1)
{
    memset(&unk0C, 0, 0x18);
    memset(&unk3C, 0, 0x1c);
    memset(&unk190, 0, 0x14);
    memset(&unk1A4, 0, 8);
    reinterpret_cast<::FUN_008d7f40_shell *>(&(p20C))->FUN_008d7f40(::RandomFloat(0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997600::Setting *>(&::originalRuntimeFloatSetting492))))))));
    fCC = ::RandomFloat(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997600::Setting *>(&::originalRuntimeFloatSetting494)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00997600::Setting *>(&::originalRuntimeFloatSetting495)))))));
}
}  // namespace fnv_00997600

#include <string.h>

struct FUN_0099a2a0_s
{
    int a[3];
    char data[0x18];
    GlobalObject_00869f00 g;
    void FUN_0099a2a0();
};
// Zeroes the data buffer and clears the global object g.
// @fnv 0x0099a2a0
void FUN_0099a2a0_s::FUN_0099a2a0()
{
    memset(data, 0, 0x18);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(g))->Clear(false);
}

struct RefCalls_9a2a30
{
};
class BGSLoadFormBuffer;

struct RefSlot
{
    TESObjectREFR* ref;
};
struct MemberC4
{
};
struct Member18C
{
};
struct HostA
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    float values[7];
    int unk058;
    int unk05c;
    float maximum;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    MemberC4* memberC4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    Member18C* member18C;
    RefSlot* slots[5];
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    Actor* actor;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    unsigned int index;
    void FUN_009a2a30(BGSLoadFormBuffer*);
};
// Calls buffer handlers, re-resolves stored references, optionally processes index, and updates maximum from values.
// @fnv 0x009a2a30
void HostA::FUN_009a2a30(BGSLoadFormBuffer* buffer)
{
    if (memberC4)
        reinterpret_cast<::FUN_009a3220_cls *>((memberC4))->FUN_009a3220((int)(buffer));
    for (unsigned int i = 0; i < 5; i++)
    {
        if (slots[i])
        {
            slots[i]->ref = slots[i]->ref ? dynamic_cast<TESObjectREFR*>(FUN_004839c0((unsigned int)slots[i]->ref)) : 0;
            if (slots[i]->ref)
                reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((((RefCalls_9a2a30*)slots[i]->ref)))->FUN_00564db0(true);
        }
    }
    if (member18C)
        reinterpret_cast<::Holder9A2 *>((member18C))->ResolveRef((::TESFile9A2 *)(buffer));
    actor = actor ? dynamic_cast<Actor*>(FUN_004839c0((unsigned int)actor)) : 0;
    if (index != -1)
        reinterpret_cast<::PRProcedure *>(this)->SetMode(index);
    for (unsigned int j = 0; j < 7; j++)
        maximum = FUN_00404010(maximum, values[j]);
}
