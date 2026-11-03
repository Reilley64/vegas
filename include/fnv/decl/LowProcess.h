#pragma once
#include <cstdint>

class Actor;
class BGSLoadFormBuffer;
class PatrolActorPackageData;
class TESActorBase;
class TESBoundObject;
class TESObjectREFR;
class TESPackage;
namespace ActorValue { enum Index; }

class LowProcess {
public:
    // 0x005a8060
    void SetPackageObjectType(std::intptr_t);
    // 0x006286d0
    intptr_t GetPackageObjectType();
    // 0x008041a0
    ::TESObjectREFR *GetActiveCombatTarget();
    // 0x008d0430
    ::PatrolActorPackageData *GetCurrentPackageData();
    // 0x008d6f30
    ::TESObjectREFR *GetTarget();
    // 0x008d7dc0
    void SetCurrentBoundObject(::TESBoundObject *);
    // 0x008d8040
    void SetCurrentCombatTarget(::TESObjectREFR *);
    // 0x009070a0
    void ClearData();
    // 0x00907260
    float GetActorTimeDelta(::Actor *);
    // 0x009072d0
    int GetActorValue(::TESActorBase *, ::ActorValue::Index, ::Actor *);
    // 0x00907380
    float GetCurrentActorValue(::TESActorBase *, ::ActorValue::Index, ::Actor *);
    // 0x00907510
    void HandlePackageChange(::LowProcess *);
    // 0x009078d0
    bool CanRunPackage(::TESPackage *, bool);
    // 0x00908f70
    void ProcessAcquire(::Actor *);
    // 0x0090a070
    void UpdateTargetFromPackage();
    // 0x0090a1a0
    bool CanProcessActor(::Actor *, bool);
    // 0x0090ac20
    void SetFlag40(int);
    // 0x0090d480
    static bool HandlePackageLocationLoaded(::TESObjectREFR *, intptr_t);
    // 0x0090d570
    static bool HandlePackageTargetLoaded(::TESObjectREFR *, intptr_t);
    // 0x00910630
    void LoadGame(::BGSLoadFormBuffer *);
    // 0x00910820
    void InitLoadGame(::BGSLoadFormBuffer *);
    // 0x00910a60
    void Revert(::BGSLoadFormBuffer *);
    // 0x009121e0
    void ProcessPatrol(::Actor *);
    // 0x00912960
    void HandlePatrolArrival(::Actor *, ::PatrolActorPackageData *);
    // 0x009b88a0
    float GetCurrentDetectionAmount();
};
