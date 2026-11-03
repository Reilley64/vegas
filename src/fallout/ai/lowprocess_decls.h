// Authored check-time copy of the canonical generated LowProcess layout.
// Content mirrors include/LowProcess.h; the member declarations appended at
// the end are the canonical generated-header additions requested for
// FNV_LOWPROCESS_H guard keeps this copy conflict-free until the canonical
// header is regenerated and this file retires.
#ifndef FNV_LOWPROCESS_H
#define FNV_LOWPROCESS_H

#include <cstdio>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_005c1a00.h"
#include "fnv/decl/FUN_0083c850.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00962720_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/State.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00962620__FUN_00962620_cls.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_0090d000.h"
#include "fnv/symbols_0090e000.h"
#include "fnv/symbols_00936000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "lowprocess_support.h"
#include "lowprocess_NiPoint3.h"
#include "lowprocess_PathingLocation.h"
#include "lowprocess_types_PathingRequest.h"
#include "lowprocess_TESForm.h"
#include "lowprocess_ExtraDataList.h"
#include "lowprocess_TESObjectREFR.h"
#include "lowprocess_MobileObject.h"
#include "lowprocess_Actor.h"
#include "lowprocess_types_TESPackage.h"
#include "lowprocess_types_PackageTarget.h"
#include "lowprocess_types_PackageLocation.h"
#include "lowprocess_base.h"
#include "lowprocess_types_TESBoundObject.h"
#include "lowprocess_CombatTimer.h"
#include "lowprocess_ModifierList.h"
class LowProcess : public BaseProcess
{
  public:
    PatrolActorPackageData* GetCurrentPackageData();

    unsigned char m_uiObjectFlags;  // +0x30
    unsigned char layoutPadding31[3];
    TESBoundObject* m_pCurrentWeapon;  // +0x34
    TimeoutTimer m_kProcessData38;      // +0x38
    TESObjectREFR* pTarget;            // +0x40
    TESObjectREFR* m_pReference40;     // +0x44
    TESObjectREFR* m_pReference44;     // +0x48
    BGSListForm* m_pFormList;          // +0x4C
    short m_sFourthValue;              // +0x50
    unsigned char layoutPadding52[2];
    TESObjectREFR* m_pObjectReference;                     // +0x54
    int m_iValue58;                                        // +0x58
    BSSimpleList<TargetDoorController*> ReferenceListNode;     // +0x5C
    TargetDoorController* m_pDetectionData60;                  // +0x64
    TargetDoorController* m_pDetectionData64;                  // +0x68
    BSSimpleList<TESObjectREFR*> m_kReferenceList68;       // +0x6C
    BSSimpleList<TargetDoorController*> m_kDetectionDataList;  // +0x74
    BSSimpleList<TESObjectREFR*> m_kReferenceList70;       // +0x7C
    TESBoundObject* m_pBoundObject74;                      // +0x84
    TESBoundObject* m_pBoundObject78;                      // +0x88
    PACKAGE_OBJECT_TYPE m_eReferenceTypeInfo;                         // +0x8C
    TESFaction* PackageFactionTarget;                      // +0x90
    ActorValueModifierList m_kActorValueModifiers;                   // +0x94
    float m_fValue88;                                      // +0xA4
    float m_fValue8C;                                      // +0xA8
    float m_fValue90;                                      // +0xAC
    bool m_bHasBoundObject;                                // +0xB0
    unsigned char layoutPaddingB1[3];
    void SetCurrentBoundObject(TESBoundObject*);
    void SetCurrentCombatTarget(TESObjectREFR*);
    TESObjectREFR* GetTarget();
    void SetPackageObjectType(int);
    int GetPackageObjectType();
    TESObjectREFR* GetActiveCombatTarget();
    // Canonical additions requested:
    void SetAnimationComplete(bool);
    bool IsMovementComplete();
    bool IsCurrentProcessComplete();
    void SetProcessTaskComplete(bool);
    bool IsProcessConditionMet();
    void SetProcessConditionMet(bool);
    bool IsProcessActivityActive();
    void SetProcessModeEnabled(bool);
    bool IsAnimationStateActive();
    void SetAnimationStateActive(bool);
    bool IsCurrentlyAlerted();
    void SetAlert(bool);
    void UpdateTargetFromPackage();
    void SetFlag40(int);
    float GetCurrentDetectionAmount();
    virtual void ProcessSleep(Actor*);
    virtual void ProcessEat(Actor*, TESForm*);
    virtual void vfn_7c0();
    virtual void ProcessAlarm(Actor*);
    virtual bool ProcessActivate(Actor*, bool);
    virtual void ProcessAccompany(Actor*);
    virtual void ProcessAcquire(Actor*);
    virtual void ProcessAmbushWait(Actor*);
    virtual void ProcessUseItemAt(Actor*);
    virtual bool ProcessUseWeapon(Actor*);
    virtual void vfn_7e0(Actor*);
    virtual void ProcessFleeNonCombat(Actor*);
    virtual void ProcessAvoidRadiation(Actor*);
    virtual void ProcessSandbox(Actor*);
    virtual void ProcessMovementBlocked(Actor*);
    virtual void ProcessGuard(Actor*);
    virtual void vfn_7f8(Actor*, PatrolActorPackageData*);
    virtual void ProcessPatrol(Actor*);
    virtual void vfn_800(Actor*);
    virtual void vfn_804();
    virtual void ProcessNotify(Actor*);
    virtual bool vfn_80c(Actor*, int);
    virtual TESObjectREFR* vfn_810(Actor*, TESPackage*);
    virtual TESObjectREFR* vfn_814(Actor*, TESPackage*, bool);
    virtual void vfn_818(Actor*);
    void HandlePackageChange(LowProcess*);
    void ClearData();
    int GetActorValue(TESActorBase*, ActorValue__Index, Actor*);
    void ResetPackageState();
    void SetMobileObjectState(MobileObject*, bool);
    int GetPackedStateBits0To8();
    int GetPackedStateBits9To12();
    int GetPackedStateBits13To26();
    virtual bool CanProcessActor(Actor*, bool);
    bool SelectNextPackage(Actor*);
    bool EvaluateActorPackage(Actor*, TESPackage*, bool);
    bool CanRunPackage(TESPackage*, bool);
    virtual void SetTarget(TESObjectREFR*);
    void OnPackageChanged(Actor*, TESPackage*);
    float GetCurrentActorValue(TESActorBase*, ActorValue__Index, Actor*);
    static bool HandlePackageTargetLoaded(TESObjectREFR*, long);
    void ProcessDialogueTopic(Actor*, TESTopic*, bool, bool, bool, bool);
    static bool HandlePackageLocationLoaded(TESObjectREFR*, long);
    void Revert(BGSLoadFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void Update(MobileObject*);
    virtual void SetProcessTarget(MobileObject*, int);
    virtual void OnPackageEnd(Actor*, TESPackage*);

    float GetActorTimeDelta(Actor*);

    virtual void UpdateCurrentPackage(Actor*);
    TESObjectREFR* ResolvePackageLocation(Actor*, TESPackage*, bool);
    TESObjectREFR* GetPackageLocationReference(Actor*, bool);

    bool FindPatrolTarget(Actor*, PatrolActorPackageData*);
    void ProcessPatrolPackage(Actor*, PatrolActorPackageData*);
    float RunProcessUpdate(Actor*, PatrolActorPackageData*, float);
    void HandlePatrolArrival(Actor*, PatrolActorPackageData*);
    float UpdatePatrolProgress(Actor*, PatrolActorPackageData*, float);
    void UpdateActorPackage(Actor*, bool, int, bool);
    virtual bool FindPackageTarget(Actor*);
    TESObjectREFR* ResolvePackageTarget(Actor*, TESPackage*);
    void ClearReferenceRecords(TESObjectREFR*);
    void OnPackageStart(Actor*, TESPackage*);
};
#endif

class Actor;
class HighProcess
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void Update();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual bool vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0(bool);
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void SetProcessTarget(MobileObject*, int);
public:
    unsigned int UpdateHighProcessState(::Actor *);
};
class PlayerCharacter : public Actor
{
  public:
    unsigned char layoutPadding1B4[0x58];
    bool bResting;
    bool IsSleepingOrResting();
    bool HasCombatState();
};
class TargetDoorController
{
  public:
    TESObjectREFR* pObject;
    TESBoundObject* pItem;
    bool bActivate;
    bool m_bUseSpecialAction;
    unsigned char layoutPaddingA[2];
    int iCount;
    float fDistance;
    float fValue;
    int eType;
    ~TargetDoorController();
};
class Calendar
{
  public:
    float GetGameTime();
public:
    int GetDayOfMonth();
};
class LowProcessTimer
{
  public:
    bool IsBoundItem();
};
#include "lowprocess_types_PatrolActorPackageData.h"
class BGSListForm : public TESForm
{
  public:
};
class TESFaction : public TESForm
{
};
class TESValueForm
{
  public:
};
union SETTING_VALUE
{
    int i;
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};

class TES
{
  public:
};
class PathingActorData;
class Pathing
{
  public:
    enum DOOR_LOCK_DISPOSITION
    {
        kIgnoreLocks
    };
    static float FindPathDistance(const PathingLocation&, const PathingLocation&, float, PathingActorData*,
                                  DOOR_LOCK_DISPOSITION);
};



class FormChangeMask
{
  public:
    unsigned int value;
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
    FormChangeMask GetChangeFlags(unsigned int);
    FormChangeMask GetOldChangeFlags(unsigned int);
};

bool FUN_0090e660(TESObjectREFR*, long);

class RegionPoint
{
  public:
};
void FUN_005ac750(TESForm*, ExtraDataList*, unsigned int);
class DialogueResponse;
class DialogueItem
{
  public:
    bool SelectDefaultResponseList();
public:
    ::DialogueResponse *GetActiveResponse();
};

class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};

class ExtraLock
{
  public:
};
namespace ActorValue {
}
class TESGlobal
{
  public:
    float FUN_00526ac0();
};
class PackageTargetHolder
{
  public:
    void FUN_00403550(TESObjectREFR*);
};

extern SettingT_GameSettingCollection_ DAT_011cdbac;
extern SettingT_GameSettingCollection_ DAT_011cd82c;

// Private views of canonical declarations for identical folded accessor bodies.
class Date
{
  public:
    ~Date();
};
class BGSLoadGameBuffer
{
  public:
};
class BGSMessageInitAccess
{
  public:
    unsigned int GetIconFormID();
};
class ExtraDataListHelper
{
  public:
    RegionPoint* GetStartingPositionData();
};
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class RecipeCraftingInfo;
namespace ActorValue { enum Index; }
class TESRecipe
{
  public:
    RecipeCraftingInfo* GetData();
public:
    void SetRequiredSkill(::ActorValue::Index);
};
class ActiveEffect
{
  public:
    void FUN_00693d50(float);
public:
    float GetDuration() const;
};
class TESSound;
class EffectSetting
{
  public:
public:
    ::TESSound *GetHitSound();
};
class TESTopicInfo
{
  public:
};
class TESGlobalValueReader
{
  public:
};
class BGSDehydrationStage
{
  public:
    unsigned int FUN_00441110();
};
class TESObjectREFRHelper
{
  public:
};
class BGSPickupPutdownSounds
{
  public:
};
