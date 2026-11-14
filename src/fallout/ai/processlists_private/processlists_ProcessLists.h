// and dependency headers establish the PC member order and natural alignment.
#ifndef FNV_PROCESSLISTS_PRIVATE_PROCESSLISTS_H
#define FNV_PROCESSLISTS_PRIVATE_PROCESSLISTS_H

#include "fnv/symbols_011e0000.h"
#include "processlists_layout_support.h"
#include "processlists_ProcessArray.h"
#include "processlists_task_data.h"
#include "processlists_lock_free_map.h"

class Actor;
struct Crime;
class MagicShaderHitEffect;
struct BGSLoadGameBuffer;
class BSTempEffect;
class MuzzleFlash;
class DialoguePackage;

class ProcessLists
{
  public:
    float m_fProcessListValue1;
    MobileObjectProcessArray m_kMobileObjectProcessList;
    BSSimpleList<Crime*>* m_pkCrimeLists[5];
    BSSimpleList<NiPointer<BSTempEffect> > m_kTemporaryEffectList;
    BSSimpleList<NiPointer<BSTempEffect> > m_kTemporaryEffectList2;
    BSSimpleList<MuzzleFlash*> m_kMuzzleFlashList;
    BSSimpleList<MobileObject*> m_kMobileObjectList;
    BSSimpleList<TESObjectREFR*> m_kObjectReferenceList;
    BSSimpleList<Actor*> m_kAliveActorList;
    Actor* m_apActorCache[50];
    int m_iActorCount;
    float m_fProcessListValue2;
    float m_fProcessUpdateTimer;
    bool m_bFirstFlagBeforeTaskManager;
    bool m_bSecondFlagBeforeTaskManager;
    ActorTaskManager m_kTaskManager;
    BSSimpleList<DialoguePackage*> DialoguePackageList;
    RecursiveSpinLock m_kActorListLock;
    RecursiveSpinLock kUpdateLock;
    BSSimpleList<MobileObject*>* m_pMobileObjectList;
    BSSimpleList<MobileObject*>* m_pkSecondMobileObjectList;
    LipSyncBackgroundManager m_kLipSyncBackgroundManager;
    bool m_bFirstOfThreeFlags;
    bool m_bSecondOfThreeFlags;
    bool m_bThirdOfThreeFlags;
    Actor* ActorProcessData;
    bool m_bThirdBooleanFlag;
    bool m_bUpdateLowProcesses;
    bool m_bRunSecondProcessUpdate;
    bool m_bUpdateLowListProcessLists;
    bool m_bSeventhBooleanFlag;
    bool m_bFourthOfFiveFlags;
    bool m_bFourthBooleanFlagBeforeFloat;
    int m_iMobileObjectCount;
    float m_fCrimeListUpdateTimer;
    int m_iCrimeNumber;
    float SemaphoreTimingState;
    CountingSemaphore m_kLoadSemaphore;

    void AdvanceProcessLists(float time);
    void InitLoadGame(BGSLoadGameBuffer* buffer);
    bool CanAddActorToList(Actor* actor, int count);
    void Revert(BGSLoadGameBuffer* buffer);
    MagicShaderHitEffect* FindMagicShaderHitEffect(TESObjectREFR* target);
    ~ProcessLists();
    const MobileObjectProcessArray* GetProcessArray() const;  // PC 00717E50
    MobileObjectProcessArray* GetProcessArray();              // PC 00717E50
    BSSimpleList<Actor*>* GetAliveActorList();
    void AddActorToAliveList(Actor* apActor);
    void RemoveActorFromAliveList(Actor* apActor);
    void CalculateAliveActorList();
    void RunActorUpdates();
    void AddMobileObjectToList(MobileObject* object);
    void RemoveMobileObjectFromList(MobileObject* object);
    void UpdateMagicTempEffects(float delta);
    void UpdateFollowerTempList();
    void UpdateInterfaceTempEffects(float delta);
    void UpdateHighProcess();
    bool IsActorTalkingThroughActivator(Actor* apActor);
};

// Genuine names-only original object: ?g_kProcessLists@@3VProcessLists@@A
// qualified cross-platform identity inference, supported by independently
// annotated PC singleton ownership and direct object-address use at 0096E327.
// This is not an exact PC symbol annotation and does not define new storage.
#endif
