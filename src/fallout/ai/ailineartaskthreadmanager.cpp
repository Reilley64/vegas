// fallout/ai/ailineartaskthreadmanager.cpp: AIThreadManager (21 functions)

#include "fnv/tls.h"
#include <windows.h>
#include <new>
#include "fnv/decl/BGSDestructibleObjectForm.h"
#include "fnv/decl/DetectionLists.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_00455640_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087a730_cls.h"
#include "fnv/decl/FUN_008c7a30_class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_0096cb50_shell.h"
#include "fnv/decl/FUN_0096cca0_shell.h"
#include "fnv/decl/FUN_009784c0_shell.h"
#include "fnv/decl/FUN_00986150_shell.h"
#include "fnv/decl/FUN_00986c40_shell.h"
#include "fnv/decl/FUN_00991dc0_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/ProcListsExt.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "fnv/decl/Zt5TES.h"
#include "fnv/decl/fnv_006c3640__C006c3640.h"
#include "fnv/decl/fnv_0086cdd0__FUN_0086cdd0.h"
#include "fnv/decl/fnv_0096bcd0__ProcessListsHigh.h"
#include "fnv/decl/fnv_0096db30__Target96.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_005a9000.h"
#include "fnv/symbols_005ae000.h"
#include "fnv/symbols_005c4000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_00713000.h"
#include "fnv/symbols_0086f000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_008c8000.h"
#include "fnv/symbols_0096d000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d7000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01272000.h"
#include "ailineartaskthreadmanager_rendering.h"

typedef void(__cdecl* AIThreadFunction)();

class BSThread
{
  public:
    enum StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };
    void Initialize(StackSize, const char*, bool);
    void SetSchedulingPriority(unsigned int);
    void SetThreadPriority(int);
    void SetName(const char*);
};

class AILinearTaskThread : public BSThread
{
  public:
    AILinearTaskThread(AIThreadFunction);
    unsigned char layoutPadding[0x78];
};

class MemoryManager
{
  public:
};

class AIThreadManager
{
  public:
    enum AI_THREAD_INDEX
    {
        AI_THREAD_1 = 0,
        AI_THREAD_2 = 1,
        AI_THREAD_COUNT = 2
    };
    AILinearTaskThread* m_pTaskThreads[3];
    unsigned char layoutPadding0[0x30];
    void* threadHandles1[12];
    void* threadHandles2[8];
    void LaunchWorkerThread(AI_THREAD_INDEX, unsigned int, AIThreadFunction, const char*, BSThread::StackSize);
    void StartRenderingTaskThread();
    static void SetThreadingEnabled(bool);
};

union SETTING_VALUE
{
    int value;
};
class SettingT_GameSettingCollection_
{
  public:
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
extern "C" unsigned int gPreferredMoveMode;

// @fnv 0x008c7290
void AIThreadManager::StartRenderingTaskThread()
{
    int i = 0;
    int j;
    for (; i <= 11; ++i)
        threadHandles1[i] = CreateEventA(0, 1, 0, 0);

    j = 0;
    for (; j <= 7; ++j)
        threadHandles2[j] = CreateEventA(0, 1, 0, 0);

    if (((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(((SettingT_GameSettingCollection_*)0x011c3ea4)))))->value > 2)
    {
        LaunchWorkerThread(AI_THREAD_1, ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(((SettingT_GameSettingCollection_*)0x011dfb34)))))->value,
                           (AIThreadFunction)0x008c7da0, "AI Linear Task Thread 1", (BSThread::StackSize)0x10000);
        LaunchWorkerThread(AI_THREAD_2, ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(((SettingT_GameSettingCollection_*)0x011dfb18)))))->value,
                           (AIThreadFunction)0x008c7f50, "AI Linear Task Thread 2", (BSThread::StackSize)0x10000);
    }
    else
    {
        LaunchWorkerThread(AI_THREAD_1, ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(((SettingT_GameSettingCollection_*)0x011dfb34)))))->value,
                           (AIThreadFunction)0x008c7bd0, "AI Linear Task Thread", (BSThread::StackSize)0x10000);
    }

    gPreferredMoveMode = ((ActorMover*)m_pTaskThreads[0])->GetCurrentMoveModeType();
}

// @fnv 0x008c74d0
void AIThreadManager::LaunchWorkerThread(AI_THREAD_INDEX threadIndex, unsigned int processor,
                                         AIThreadFunction taskFunction, const char* threadName,
                                         BSThread::StackSize stackSize)
{
    if (threadIndex < 3 && threadIndex < 2 && !m_pTaskThreads[threadIndex])
    {
        m_pTaskThreads[threadIndex] = new AILinearTaskThread(taskFunction);
        m_pTaskThreads[threadIndex]->Initialize(stackSize, threadName, false);
        m_pTaskThreads[threadIndex]->SetSchedulingPriority(processor);
        m_pTaskThreads[threadIndex]->SetThreadPriority(0);

        if (!threadName)
        {
            char generatedName[0x104];
            ::FUN_00406d00(generatedName, 0x104, "AI Linear Task Thread DEF %i", threadIndex);
            m_pTaskThreads[threadIndex]->SetName(generatedName);
        }
    }
}

// Updates DAT_011dfa18 to the rendering flag and, when it was set and rendering is false, calls FUN_008c80c0.
// @fnv 0x008c80e0
void AIThreadManager::SetThreadingEnabled(bool rendering)
{
    if (DAT_011dfa18 && !rendering)
    {
        DAT_011dfa18 = rendering;
        ::fnv_008c80c0::FUN_008c80c0();
    }
    DAT_011dfa18 = rendering;
}

class CountingSemaphore
{
  public:
};

struct FUN_008c7490_this
{
    char pad[0x3c];
    CountingSemaphore sem;
};

// @fnv 0x008c7490
void FUN_008c7490(FUN_008c7490_this* pThis)
{
    reinterpret_cast<::SemaphoreWaitReceiver *>(&(pThis->sem))->FUN_004424e0();
}

struct ActiveEffect;
struct Actor;
struct PackedTaskQueueProcessor;
struct Character;
struct DismemberLimbTaskData;
struct BooleanFloatQuery;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct TESBoundObject;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TaskQueueInterface
{
    void ThreadProcessInput();
    void ThreadBeginSecondaryInput();
    void ThreadProcessSecondaryInput();
    void ThreadEndSecondaryInput();
    void ProcessQueue();
    void ProcessTaskQueue();
    unsigned long QProcessingThread();
    void ExamplePrintFloat(float);
    void ExamplePrintInt(int);
    void QueueSkyEmittanceUpdate(NiNode*, NiColor*);
    void ProcessPackedTask(unsigned int, TESObjectREFR*, ...);
    void QueueWeaponFire(TESObjectWEAP*, TESObjectREFR*);
    void QueueParallelTaskProcessing();
    void QueueCellTransformChildTask(NiNode*);
    void QueueActorHavokSync(NiNode*);
    void QueueActorNodeUpdate(Actor*, NiAVObject*);
    void QueueParticlesUpdate(NiNode*);
    void QueueMorphControllerUpdate(NiNode*);
    void QueueNodeAttach(NiAVObject*, NiNode*, bool, bool);
    void QueueNodeDetach(NiAVObject*);
    void QueueBiped3DDetach(NiAVObject*);
    void QueueSSNRemoveObject(NiAVObject*, int);
    void QueueObjectUpdate(NiAVObject*);
    void QueueActorHitMe(Actor*, BooleanFloatQuery*);
    void QueueActorCreateBlood(Actor*, BooleanFloatQuery*);
    void QueueMobileObjectInitialize(MobileObject*);
    void QueueMHEInstantiateHitEffects(ActiveEffect*);
    void QueueReferenceFloatTask(TESObjectREFR*, float, bool);
    void QueuePickedUpObjectRemoval(TESObjectREFR*, bool);
    void QueueActorDismemberLimb(Actor*, float*, DismemberLimbTaskData*);
    void QueueActorCombatTask(Actor*, bool, bool);
    void QueueActorKnockExplosion(Actor*, float, float, float, float);
    void QueueHavokInit(TESObjectREFR*);
    void QueueHavokAdd(NiAVObject*);
    void QueueHavokDelete(NiAVObject*);
    void QueueHavokMotionChange(NiAVObject*, int);
    void QueueHavokMove(TESObjectREFR*);
    void QueueHavokDetach(TESObjectREFR*);
    void QueueHavokAdjustForceAddCount(NiAVObject*, bool, bool, bool);
    void CopyStringToBuffer(Actor*, TESObjectWEAP*);
    void QueueRemoveWeapon(Actor*, TESBoundObject*);
    void QueueSet3DNull(TESObjectREFR*);
    void QueueDismemberLimb(Actor*, int, int, bool, bool);
    void QueueWaterObjectForAdd(TESObjectREFR*, TESObjectREFR*, float);
    void QueueWaterObjectForRemove(TESObjectREFR*, TESObjectREFR*, float);
    void QueueObstacleDoorOpen(TESObjectREFR*);
    void QueueObstacleDoorClose(TESObjectREFR*);
    void QueueCharacterReset3D(Character*);
    void QueueReferenceStateTask(TESObjectREFR*, bool, bool);
    void QueueActorDataTask(Actor*, void*);
    void QueueActorSetHavokWeapon(Actor*, bool);
    void QueueWaterSplashEffects(float, void*);
    void QueueAddRipple(float, void*);
    void QueueActorTriggerPain(Actor*, bool, bool);
    void QueueActorDisarm(Actor*);
    void QueueActorResetLoadedAnims(Actor*);
    void QueueActorAnimationTask(Actor*);
    void QueueDeleteActiveEffect(ActiveEffect*);
    static void Instantiate(PackedTaskQueueProcessor*, PackedTaskQueueProcessor*);
    static void Shutdown();
    static void ProcessQueuedTask(void*);
    bool QQueueFurtherTasks();
    static bool QActive();
    static void SetActive(bool);
    PackedTaskQueueProcessor* GetActiveQueue();
    void SetActiveQueue(void*);
    void* __vecDelDtor(unsigned int);
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;
    unsigned long m_uiTaskFlags;
public:
    static ::TaskQueueInterface *GetSingleton();
};

class GlobalObject2_0040c150
{
  public:
};
class BSAudio
{
  public:
};
unsigned int __cdecl gm_GetCurrentThreadId(void);
bool __cdecl FUN_008c7bc0(void);

// @fnv 0x008c7aa0
bool __cdecl FUN_008c7aa0()
{
    bool bretval = false;
    bool bretvalBug44071 = false;
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1 && ((bool)(::FUN_00713d90())))
    {
        TaskQueueInterface* pqueueInterface = ::TaskQueueInterface::GetSingleton();
        if (reinterpret_cast<::FUN_0087a730_cls *>((pqueueInterface))->FUN_0087a730())
            bretvalBug44071 = true;

        unsigned long icurrthread = gm_GetCurrentThreadId();
        if (icurrthread != (unsigned long)((void *)(reinterpret_cast<::MagicCaster_shell *>(((*reinterpret_cast<::BSAudio * *>(&::g_osGlobals))))->FUN_0044edb0())))
        {
            if (FUN_008c7bc0() || ((unsigned int)(reinterpret_cast<::FUN_008c7a30_class *>((((void *)(::FUN_00713d80()))))->GetValueWithItemResult({}))) < 6)
                bretval = true;
        }
        else
        {
            if (!FUN_008c7bc0())
            {
                if (((unsigned int)(reinterpret_cast<::FUN_008c7a30_class *>((((void *)(::FUN_00713d80()))))->GetValueWithItemResult({}))) < 11 || ((unsigned int)(reinterpret_cast<::FUN_008c7a30_class *>((((void *)(::FUN_00713d80()))))->GetValueWithItemResult({}))) < 7)
                    bretval = true;
                else
                    bretval = false;
            }
        }

        if (!bretval)
        {
            unsigned long iprocessthread = ((unsigned long)(reinterpret_cast<::FUN_0084e3a0_Class *>((::TaskQueueInterface::GetSingleton()))->FUN_0084e3a0()));
            if (iprocessthread != 0 && icurrthread != iprocessthread)
                bretval = true;
        }
    }
    bretval = bretval || bretvalBug44071;
    return bretval;
}

__declspec(thread) int DAT_tls_0264;
// @fnv 0x0047b200
::TESObjectREFR* FUN_0047b200()
{
    return g_tlsBlock.loading3DRef;
}

struct FUN_0086c600_shell
{
    void SignalAtOffset();
};
struct FUN_0087a6b0_shell
{
    FUN_0086c600_shell* p;
    void FUN_0087a6b0();
};
// @fnv 0x0087a6b0
void FUN_0087a6b0_shell::FUN_0087a6b0()
{
    p->SignalAtOffset();
}

struct FUN_0086cdd0_shell
{
};
struct FUN_0087a6d0_shell
{
    FUN_0086cdd0_shell* p;
    void FUN_0087a6d0();
};
// @fnv 0x0087a6d0
void FUN_0087a6d0_shell::FUN_0087a6d0()
{
    reinterpret_cast<::fnv_0086cdd0::FUN_0086cdd0 *>((p))->Wait();
}

namespace fnv_008c74b0 {
struct CountingSemaphore
{
};

struct FUN_008c74b0_shell
{
    unsigned char layoutPadding[0x48];
    CountingSemaphore semaphore;
    void SignalThread();
};

// @fnv 0x008c74b0
void FUN_008c74b0_shell::SignalThread()
{
    (*(unsigned char*)&this->semaphore) = 1;
    reinterpret_cast<::FUN_00442550_shell *>((((CountingSemaphore*)((unsigned char*)this + 0x30))))->ReleaseAndInitScriptRunLock();
}
}  // namespace fnv_008c74b0

extern bool DAT_011dfa18;

// @fnv 0x008c7bc0
bool FUN_008c7bc0()
{
    return DAT_011dfa18;
}

namespace fnv_008c80b0 {
class CountingSemaphore
{
  public:
};


// @fnv 0x008c80b0
void FUN_008c80b0()
{
    reinterpret_cast<::SemaphoreWaitReceiver *>(&((*reinterpret_cast<::fnv_008c80b0::CountingSemaphore *>(&::g_011dfafc))))->FUN_004424e0();
}
}  // namespace fnv_008c80b0

namespace fnv_008c80c0 {
struct CountingSemaphore
{
};

// @fnv 0x008c80c0
void FUN_008c80c0()
{
    reinterpret_cast<::FUN_00442550_shell *>(&((*reinterpret_cast<::fnv_008c80c0::CountingSemaphore *>(&::g_011dfafc))))->ReleaseAndInitScriptRunLock();
}
}  // namespace fnv_008c80c0


// @fnv 0x008c80d0
void __cdecl FUN_008c80d0()
{
    ::fnv_008c80b0::FUN_008c80b0();
}

struct FUN_008c79e0_shell
{
    void* apThreads[3];
    int aiCurrent[2];
    char pad[0x78];
    void** ppEvents[2];
    void SignalThreadEvent(int aiIndex, int aiEvent);
};
// If aiIndex is below 2 and the thread handle exists, signals the event at ppEvents[aiIndex][aiEvent] and stores aiEvent in aiCurrent[aiIndex].
// @fnv 0x008c79e0
void FUN_008c79e0_shell::SignalThreadEvent(int aiIndex, int aiEvent)
{
    if (aiIndex < 2 && apThreads[aiIndex])
    {
        SetEvent(ppEvents[aiIndex][aiEvent]);
        aiCurrent[aiIndex] = aiEvent;
    }
}

struct FUN_008c7a70_shell
{
    char pad[0x8c];
    void** ppEvents[2];
    void WaitForEvent(int aiIndex, int aiEvent);
};
// Waits indefinitely on the event at ppEvents[aiIndex][aiEvent].
// @fnv 0x008c7a70
void FUN_008c7a70_shell::WaitForEvent(int aiIndex, int aiEvent)
{
    WaitForSingleObject(ppEvents[aiIndex][aiEvent], 0xffffffff);
}

struct FUN_008c7d80_shell
{
    void* m_pObjectPointers[3];
    int aiCurrent[2];
    char pad[0x74];
    void SetCurrent(int aiIndex, int aiValue);
};
// @fnv 0x008c7d80
void FUN_008c7d80_shell::SetCurrent(int aiIndex, int aiValue)
{
    aiCurrent[aiIndex] = aiValue;
}

struct AutoMemHelper
{
    int aiMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct ArrHelper
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct CombatTargetMap
{
    void ResetTargetMap();
};
struct FUN_00986c40_obj
{
};
void __cdecl FUN_009915e0(float);
struct FUN_00991500_shell
{
    char pad[0x14];
    CombatTargetMap* m_pTargetMap;
    void FUN_00991500(bool abFlag);
};
// @fnv 0x00991500
void FUN_00991500_shell::FUN_00991500(bool abFlag)
{
    AutoMemHelper kMem(0x2b, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\CombatManager.cpp",
                       0x8b);
    if (!abFlag)
    {
        FUN_009915e0((*reinterpret_cast<::Twin_0084d030 *>(&::g_timeGlobal)).GetStoredFloatValue());
        for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>((((ArrHelper*)this)))->GetShortAtOffsetA(); i++)
        {
            FUN_00986c40_obj* pEntry = (FUN_00986c40_obj*)*((Arr*)this)->GetAt(i);
            if (pEntry && !reinterpret_cast<::FUN_00986c40_shell *>((pEntry))->FUN_00986c40())
                reinterpret_cast<::FUN_00986150_shell *>((pEntry))->FUN_00986150();
        }
        m_pTargetMap->ResetTargetMap();
    }
}



struct TaskThreadStandin
{
    virtual ~TaskThreadStandin();
};

struct FUN_008c73a0_shell : public AIThreadManager
{
    void FUN_008c73a0();
};

// @fnv 0x008c73a0
void FUN_008c73a0_shell::FUN_008c73a0()
{
    unsigned int i;
    int j;
    int iHandleIndex1;

    for (i = 0; i < 2; ++i)
    {
        if (m_pTaskThreads[i])
        {
            reinterpret_cast<::fnv_008c74b0::FUN_008c74b0_shell *>((m_pTaskThreads[i]))->SignalThread();
            ::FUN_008c7490((::FUN_008c7490_this *)(m_pTaskThreads[i]));
            delete (TaskThreadStandin*)m_pTaskThreads[i];
            m_pTaskThreads[i] = 0;
        }
    }

    for (iHandleIndex1 = 0; iHandleIndex1 <= 11; ++iHandleIndex1)
    {
        CloseHandle(threadHandles1[iHandleIndex1]);
    }

    for (j = 0; j <= 7; ++j)
    {
        CloseHandle(threadHandles2[j]);
    }
}

namespace fnv_008c7bd0 {
struct BSAudio
{
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct RecursiveSpinLock
{
};

struct Zt5TES
{
};

struct TaskQueueInterface
{
};

struct NavMeshObstacleManager
{
};

struct BGSDestructibleObjectForm
{
};

struct FUN_008c79e0_shell
{
};

struct FUN_008c7d80_shell
{
};

struct FUN_0087a6b0_shell
{
};

struct FUN_0087a6d0_shell
{
};

struct FUN_00991500_shell
{
};

struct FUN_0096cb50_shell
{
};

struct FUN_009784c0_shell
{
};

struct FUN_00455640_shell
{
};

struct SkyObject
{
};

struct ProcessLists
{
};

struct GlobalObject_0096d020
{
};



// @fnv 0x008c7bd0
void __cdecl FUN_008c7bd0()
{
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, {});
    ::FUN_0086fd70((*reinterpret_cast<::fnv_008c7bd0::BSAudio * *>(&::g_osGlobals)));
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(1, {});

    reinterpret_cast<::FUN_0087a6b0_shell *>((reinterpret_cast<FUN_0087a6b0_shell*>(((::fnv_008c7bd0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6b0();

    reinterpret_cast<::FUN_00991500_shell *>((reinterpret_cast<FUN_00991500_shell*>((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->FUN_00991500(::FUN_005c42d0());

    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_008c7bd0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::FUN_0096cca0_shell *>((reinterpret_cast<GlobalObject_0096d020*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096cca0();
    reinterpret_cast<::ProcListsExt *>((reinterpret_cast<GlobalObject_0096d020*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096cda0();
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_008c7bd0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();

    reinterpret_cast<::FUN_00455640_shell *>((reinterpret_cast<FUN_00455640_shell*>(::g_TES)))->FUN_00455640();

    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_008c7bd0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::FUN_009784c0_shell *>((reinterpret_cast<FUN_009784c0_shell*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_009784c0();
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_008c7bd0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();

    reinterpret_cast<::FUN_00991dc0_shell *>(((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00991dc0();

    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_008c7bd0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::fnv_0096bcd0::ProcessListsHigh *>((reinterpret_cast<GlobalObject_0096d020*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096bcd0(0.0f, 0);
    ::ProcessPlayerCellActors();
    reinterpret_cast<::DetectionLists *>((reinterpret_cast<GlobalObject_0096d020*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->UpdateDetection();
    reinterpret_cast<::fnv_0096db30::Target96 *>((reinterpret_cast<GlobalObject_0096d020*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096db30(0.0f, 0, 0);
    reinterpret_cast<::FUN_008d0600_s *>((reinterpret_cast<SkyObject*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_008d0600(0.0f, 0);
    reinterpret_cast<::ProcessLists *>((reinterpret_cast<ProcessLists*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->RunActorUpdates();
    reinterpret_cast<::FUN_0096cb50_shell *>((reinterpret_cast<FUN_0096cb50_shell*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->UpdateHighProcessActors();
    ::BGSDestructibleObjectForm::UpdateDestructionMap();
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_008c7bd0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();

    reinterpret_cast<::Zt5TES *>((reinterpret_cast<Zt5TES*>(::g_TES)))->FUN_00453550(::FUN_00453850());

    reinterpret_cast<::FUN_008c7d80_shell *>((reinterpret_cast<FUN_008c7d80_shell*>(((void *)(::FUN_00713d80())))))->SetCurrent(6, {});
    ::FUN_008c80d0();

    if (*(*reinterpret_cast<::fnv_008c7bd0::GlobalObject_0045cf30 *>(&::g_011d73e4)).Bool())
        reinterpret_cast<::fnv_006c3640::C006c3640 *>((((::fnv_008c7bd0::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c3640();

    reinterpret_cast<::FUN_0087a6d0_shell *>((reinterpret_cast<FUN_0087a6d0_shell*>(((::fnv_008c7bd0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6d0();
    ::FUN_005ae270();
    ::FUN_005a9d60();

    reinterpret_cast<::FUN_008c7d80_shell *>((reinterpret_cast<FUN_008c7d80_shell*>(((void *)(::FUN_00713d80())))))->SetCurrent(11, {});
    reinterpret_cast<::FUN_008c7d80_shell *>((reinterpret_cast<FUN_008c7d80_shell*>(((void *)(::FUN_00713d80())))))->SetCurrent(7, {});
}
}  // namespace fnv_008c7bd0

namespace fnv_008c7f50 {
class Sky;

struct Zt5TES
{
};

struct FUN_0096c330_shell
{
};

struct FUN_0087a6b0_shell
{
};

struct FUN_0087a6d0_shell
{
};

class TaskQueueInterface
{
  public:
};

struct FUN_008c79e0_shell
{
};

struct FUN_008c7a70_shell
{
};

struct SkyObject
{
};

struct BGSDestructibleObjectForm
{
};

struct FUN_0096cb50_shell
{
};


// @fnv 0x008c7f50
void FUN_008c7f50()
{
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, {});
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(1, {});

    reinterpret_cast<::FUN_0087a6b0_shell *>((reinterpret_cast<FUN_0087a6b0_shell*>(((::fnv_008c7f50::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6b0();
    reinterpret_cast<::DetectionLists *>((reinterpret_cast<FUN_0096c330_shell*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->UpdateDetection();

    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(1, {});
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(2, {});
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(2, {});

    reinterpret_cast<::fnv_0096db30::Target96 *>((reinterpret_cast<FUN_0096c330_shell*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096db30(0.0f, 0, 0);

    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(3, {});
    reinterpret_cast<::FUN_008d0600_s *>((reinterpret_cast<SkyObject*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_008d0600(0.0f, 0);
    reinterpret_cast<::FUN_0096cb50_shell *>((reinterpret_cast<FUN_0096cb50_shell*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->UpdateHighProcessActors();

    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(4, {});
    ::BGSDestructibleObjectForm::UpdateDestructionMap();

    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(5, {});
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(4, {});

    reinterpret_cast<::Zt5TES *>((reinterpret_cast<Zt5TES*>(::g_TES)))->FUN_00453550(::FUN_00453850());

    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(6, {});
    reinterpret_cast<::FUN_0087a6d0_shell *>((reinterpret_cast<FUN_0087a6d0_shell*>(((::fnv_008c7f50::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6d0();

    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(8, {});
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(7, {});

    ::FUN_005ae270();
    ::FUN_005a9d60();

    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(9, {});
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(11, {});
}
}  // namespace fnv_008c7f50

namespace fnv_008c7da0 {
struct FUN_00455640_shell
{
};

struct FUN_0087a6b0_shell
{
};

struct FUN_0087a6d0_shell
{
};

struct FUN_008c79e0_shell
{
};

struct FUN_008c7a70_shell
{
};

struct FUN_009784c0_shell
{
};

struct FUN_00991500_shell
{
};

struct TaskQueueInterface
{
};

struct ProcessLists
{
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct NavMeshObstacleManager
{
};

struct BSAudio
{
};



// @fnv 0x008c7da0
void __cdecl FUN_008c7da0()
{
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 0);
    ::FUN_0086fd70((*reinterpret_cast<::fnv_008c7da0::BSAudio * *>(&::g_osGlobals)));
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 1);
    reinterpret_cast<::FUN_0087a6b0_shell *>((reinterpret_cast<FUN_0087a6b0_shell*>(((::fnv_008c7da0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6b0();
    reinterpret_cast<::FUN_00991500_shell *>((reinterpret_cast<FUN_00991500_shell*>((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->FUN_00991500(::FUN_005c42d0());
    reinterpret_cast<::FUN_0096cca0_shell *>((reinterpret_cast<ProcessLists*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096cca0();
    reinterpret_cast<::ProcListsExt *>((reinterpret_cast<ProcessLists*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096cda0();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 2);
    reinterpret_cast<::FUN_00455640_shell *>(((*reinterpret_cast<::fnv_008c7da0::FUN_00455640_shell * *>(&::g_TES))))->FUN_00455640();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 3);
    reinterpret_cast<::FUN_00991dc0_shell *>(((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00991dc0();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 4);
    reinterpret_cast<::FUN_009784c0_shell *>((reinterpret_cast<FUN_009784c0_shell*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_009784c0();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 5);
    reinterpret_cast<::fnv_0096bcd0::ProcessListsHigh *>((reinterpret_cast<ProcessLists*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096bcd0(0.0f, 0);
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 6);
    ::ProcessPlayerCellActors();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 10);
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(1, 1);
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(1, 3);
    reinterpret_cast<::ProcessLists *>((reinterpret_cast<ProcessLists*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->RunActorUpdates();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 7);
    reinterpret_cast<::FUN_0087a6d0_shell *>((reinterpret_cast<FUN_0087a6d0_shell*>(((::fnv_008c7da0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6d0();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 8);
    reinterpret_cast<::FUN_008c7a70_shell *>((reinterpret_cast<FUN_008c7a70_shell*>(((void *)(::FUN_00713d80())))))->WaitForEvent(1, 7);
    ::FUN_008c80d0();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 9);
    if (*(*reinterpret_cast<::fnv_008c7da0::GlobalObject_0045cf30 *>(&::g_011d73e4)).Bool())
        reinterpret_cast<::fnv_006c3640::C006c3640 *>((((::fnv_008c7da0::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c3640();
    ::FUN_005ae270();
    ::FUN_005a9d60();
    reinterpret_cast<::FUN_008c79e0_shell *>((reinterpret_cast<FUN_008c79e0_shell*>(((void *)(::FUN_00713d80())))))->SignalThreadEvent(0, 11);
}
}  // namespace fnv_008c7da0

#include "generated/data/fallout/ai/ailineartaskthreadmanager.inc"
