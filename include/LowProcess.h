// Source layout: LowProcess. PC corrections are in generate_headers.py.
#ifndef FNV_LOWPROCESS_H
#define FNV_LOWPROCESS_H
#include <cstdint>
#include "layout_support.h"
#include "BaseProcess.h"
#include "TimeoutTimer.h"
#include "ActorValueModifierList.h"
class Actor;
struct BGSLoadFormBuffer;
class PatrolActorPackageData;
class TESActorBase;
class TESObjectREFR;
namespace ActorValue { enum Index; }
class LowProcess : public BaseProcess
{
  public:
    unsigned char m_uiObjectFlags;  // +0x30
    unsigned char layoutPadding31;
    unsigned short layoutPadding32;
    TESBoundObject* m_pCurrentWeapon;  // +0x34
    TimeoutTimer m_kProcessData38;      // +0x38
    TESObjectREFR* pTarget;            // +0x40
    TESObjectREFR* m_pReference40;     // +0x44
    TESObjectREFR* m_pReference44;     // +0x48
    BGSListForm* m_pFormList;          // +0x4C
    short m_sFourthValue;              // +0x50
    unsigned short layoutPadding52;
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
    unsigned char layoutPaddingB1;
    unsigned short layoutPaddingB2;
    void SetCurrentBoundObject(TESBoundObject*);
    void SetCurrentCombatTarget(TESObjectREFR*);
    TESObjectREFR* GetTarget();
    void SetPackageObjectType(intptr_t);
    int GetPackageObjectType();
    TESObjectREFR* GetActiveCombatTarget();
public:
    ::ActorPackageData *GetCurrentPackageData();
    void FUN_0092cab0(::Actor* source);
public:
    int GetActorValue(::TESActorBase *, ::ActorValue::Index, ::Actor *);
public:
    float GetCurrentActorValue(::TESActorBase *, ::ActorValue::Index, ::Actor *);
public:
    void UpdateTargetFromPackage();
public:
    bool CanProcessActor(::Actor *, bool);
public:
    void SetFlag40(int);
public:
    static bool HandlePackageLocationLoaded(::TESObjectREFR *, intptr_t);
public:
    static bool HandlePackageTargetLoaded(::TESObjectREFR *, intptr_t);
public:
    void LoadGame(::BGSLoadFormBuffer *);
public:
    void InitLoadGame(::BGSLoadFormBuffer *);
public:
    void Revert(::BGSLoadFormBuffer *);
public:
    void HandlePatrolArrival(::Actor *, ::PatrolActorPackageData *);
};
#endif
