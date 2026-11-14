#pragma once

class Actor;
struct BGSLoadGameBuffer;
class MagicShaderHitEffect;
class MobileObject;
class TESObjectREFR;
template <class> class BSSimpleList;

class ProcessLists {
public:
    // 0x0096c240
    void UpdateMagicTempEffects(float);
    // 0x0096c7c0
    void RunActorUpdates();
    // 0x0096d4b0
    void AdvanceProcessLists(float);
    // 0x0096e290
    ::BSSimpleList< ::Actor *> *GetAliveActorList();
    // 0x0096e2b0
    void AddActorToAliveList(::Actor *);
    // 0x0096e2f0
    void RemoveActorFromAliveList(::Actor *);
    // 0x0096e7d0
    bool CanAddActorToList(::Actor *, int);
    // 0x0096e870
    void AddMobileObjectToList(::MobileObject *);
    // 0x0096e9b0
    void UpdateFollowerTempList();
    // 0x0096f400
    void RemoveMobileObjectFromList(::MobileObject *);
    // 0x00972bb0
    void UpdateHighProcess();
    // 0x00974420
    void UpdateInterfaceTempEffects(float);
    // 0x00974cb0
    ::MagicShaderHitEffect *FindMagicShaderHitEffect(::TESObjectREFR *);
    // 0x00975af0
    void InitLoadGame(::BGSLoadGameBuffer *);
};
