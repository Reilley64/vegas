// bssystem/console/bsconsolefilecache.cpp: FaceGenData (13 functions)

#include <windows.h>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00b00cf0_shell.h"
#include "fnv/decl/FUN_00b01f00_class.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_011f6000.h"
#include "bsconsolefilecache_decls.h"
#include <cstddef>
#include "fnv/decl/B02670Task.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00b02000.h"

struct CritSection : CRITICAL_SECTION
{
};

struct JobSemaphore
{
    long cnt;
    void* h;
    void Wait()
    {
        WaitForSingleObject(h, -1);
        InterlockedDecrement(&cnt);
    }
    void Signal()
    {
        ReleaseSemaphore(h, 1, 0);
        InterlockedIncrement(&cnt);
    }
};

struct JobOwner
{
    int unk00;
    bool unk04;
    JobSemaphore completion;
    int unk10;
    CritSection kLock;
    bool enabled;
    bool pending;
    bool bBusy;
    char unk2F;
    unsigned int priority;
    unsigned int count;
    unsigned int completed;
    void CompleteTask()
    {
        EnterCriticalSection(&kLock);
        ++completed;
        bool done = !pending && completed == count;
        LeaveCriticalSection(&kLock);
        if (done)
            completion.Signal();
    }
    bool IsBusy()
    {
        return bBusy;
    }
};

struct Job
{
    virtual void Release();
    virtual bool HasFinished();
    virtual void Run();
    virtual void Cancel();
    bool bHasCallback;
    JobOwner* pOwner;
    bool bPending;
    int unk10;
    Job* pNext;
};

struct JobThread
{
    int unk00;
    bool unk04;
    bool bThreadsStarted;
    JobSemaphore kStartSemaphore;
    int unk10;
    HANDLE hUnk14;
    int unk18;
    unsigned int uiThreadCount;
    HANDLE ahThreads[12];
    bool bStop;
    CritSection kLock;
    Job* m_pQueueHeads[64];
    Job** pQueueTails[64];
    JobSemaphore kSemaphore;
    void FUN_00b02460();
};


// Initializes the object's fields to zero/default values and clears the three primitive arrays.
// @fnv 0x005dd590
FaceGenData::FaceGenData()
{
    m_pHair = 0;
    iHairColor = 0;
    m_fHairLength = 0.0f;
    pEyes = 0;
    m_eSex = SEX_MALE;
    ::FUN_005e03d0((::NiTArray_Layout *)(reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(&m_kModelObjectsItem)));
    ::FUN_005e03d0((::NiTArray_Layout *)(reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(&pTexture)));
    ::FUN_005e03d0((::NiTArray_Layout *)(reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(&m_kTexturePaths)));
    bFaceGenTexturing = false;
    m_bFaceGenDataValid = false;
    m_eFaceGenLOD = BS_FACEGEN_LOD_NONE;
}

// @fnv 0x00b01c00
BSWin32FileCache::BSWin32FileCache()
{}

struct FUN_00b02310_shell
{
    bool FUN_00b02310(unsigned char* param);
};
// @fnv 0x00b02310
bool FUN_00b02310_shell::FUN_00b02310(unsigned char* pObject)
{
    JobOwner* p = reinterpret_cast<JobOwner*>(pObject);
    bool b;
    EnterCriticalSection(&p->kLock);
    if (p->enabled)
    {
        p->pending = false;
        b = 1;
    }
    else
    {
        b = 0;
    }
    LeaveCriticalSection(&p->kLock);
    return b;
}

struct DelObj
{
    virtual ~DelObj()
    {}
};
struct FUN_00b02360_shell
{
    void DeleteIfNotNull(DelObj* p);
};
// Deletes the given object if the pointer is non-null.
// @fnv 0x00b02360
void FUN_00b02360_shell::DeleteIfNotNull(DelObj* apObject)
{
    if (apObject)
        delete apObject;
}

struct Inner_00b023b0
{
    long cnt;
    void* h;
};
struct Outer_00b023b0
{
    char pad[8];
    Inner_00b023b0 inner;
    void ResumeAllThreads();
};
// Waits on the inner handle, decrements the inner counter, calls ResumeAllThreads, then exits the thread.
// @fnv 0x00b023b0
void WaitAndExitThread(Outer_00b023b0* pOuter)
{
    Inner_00b023b0* pInner = &pOuter->inner;
    WaitForSingleObject(pInner->h, 0xFFFFFFFF);
    InterlockedDecrement(&pInner->cnt);
    pOuter->ResumeAllThreads();
    ExitThread(0);
}

struct Unk00b023f0
{
};
// Calls three methods on p in sequence, then terminates the calling thread with ExitThread(0).
// @fnv 0x00b023f0
void FUN_00b023f0(Unk00b023f0* pTarget)
{
    ::CallVfn1OnAllEntries(pTarget);
    reinterpret_cast<::JobThread *>((pTarget))->FUN_00b02460();
    reinterpret_cast<::FUN_00b00cf0_shell *>((pTarget))->CallVirtualOnAllEntries();
    ExitThread(0);
}

struct FUN_00b02420_Data : JobThread
{
    void ResumeAllThreads();
};
// Resumes each thread handle stored in the array, iterating uiThreadCount times.
// @fnv 0x00b02420
void FUN_00b02420_Data::ResumeAllThreads()
{
    for (unsigned int i = 0; i < uiThreadCount; ++i)
        ResumeThread(ahThreads[i]);
}

struct FUN_00b02600_shell
{
    bool ContainsValue(int);
};
// Scans the six ints at offset 0x38 of this object and returns true if any equals a, otherwise false.
// @fnv 0x00b02600
bool FUN_00b02600_shell::ContainsValue(int aiValue)
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (((int*)((char*)this + 0x38))[i] == aiValue)
            return true;
    }
    return false;
}

struct MemoryManager
{
};
struct S00b02640
{
    void* FUN_00b02640(unsigned int);
};
// Calls DestroyAndFreeLibraries, then deallocates this via g_memoryManager if flags has bit 1 set, and returns this.
// @fnv 0x00b02640
void* S00b02640::FUN_00b02640(unsigned int flags)
{
    reinterpret_cast<::FUN_00b01f00_class *>(this)->DestroyAndFreeLibraries();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00b02130_shell : JobThread
{
    bool QueueItem(void* p);
};

// @fnv 0x00b02130
bool FUN_00b02130_shell::QueueItem(void* apItem)
{
    Job* pJob = static_cast<Job*>(apItem);
    unsigned int idx;
    bool result9;
    if (pJob->pOwner)
    {
        EnterCriticalSection(&kLock);
        idx = pJob->pOwner->priority;
        if (idx >= 0x40)
            idx = 0x3f;
        if (m_pQueueHeads[idx] == 0)
            pQueueTails[idx] = &m_pQueueHeads[idx];
        *pQueueTails[idx] = pJob;
        pQueueTails[idx] = &pJob->pNext;
        pJob->pNext = 0;
        pJob->bHasCallback = false;
        LeaveCriticalSection(&kLock);
        kSemaphore.Signal();
        result9 = true;
    }
    else
        result9 = false;
    return result9;
}

struct FUN_00b020a0_shell
{
    char FUN_00b020a0(void* p);
};
// @fnv 0x00b020a0
char FUN_00b020a0_shell::FUN_00b020a0(void* pObject)
{
    unsigned char flag;
    JobOwner* obj = static_cast<JobOwner*>(pObject);
    EnterCriticalSection(&obj->kLock);
    if (!obj->enabled)
    {
        WaitForSingleObject(obj->completion.h, 0);
        flag = 1;
        obj->enabled = flag;
        obj->unk04 = false;
        obj->pending = true;
        obj->bBusy = false;
        obj->count = 0;
        obj->completed = 0;
    }
    else
    {
        flag = 0;
    }
    LeaveCriticalSection(&obj->kLock);
    return (char)flag;
}


struct FUN_00b01f50_shell : JobThread
{
    void FUN_00b01f50();
};

// @fnv 0x00b01f50
void FUN_00b01f50_shell::FUN_00b01f50()
{
    unsigned int i;

    bStop = true;
    if (bThreadsStarted)
    {
        for (i = 0; i < uiThreadCount; ++i)
            kSemaphore.Signal();
        WaitForMultipleObjects(uiThreadCount, ahThreads, 1, 0xFFFFFFFF);
    }

    for (i = 0; i < uiThreadCount; ++i)
    {
        CloseHandle(ahThreads[i]);
    }
    CloseHandle(hUnk14);
}

struct Lock_00b02220 : CRITICAL_SECTION
{
};
struct FUN_00b02220_Owner
{
    int u000;
    int u004;
    int u008;
    int u00C;
    int u010;
    Lock_00b02220 m_kLock;
    bool m_bEnableState;
    bool m_bPending;
    short u02E;
    int u030;
    int m_iArrayLength;
};
struct FUN_00b02220_Task
{
    int unk00;
    bool m_bDone;
    char u005;
    short u006;
    FUN_00b02220_Owner* m_pkOwnerManager;
    int unk0C;
    long m_lBusy;
};
struct FUN_00b02220_Class : FUN_00b02130_shell
{
    bool TryStartTask(void* pOwner, void* pTask, bool bClearPending);
};
// @fnv 0x00b02220
bool FUN_00b02220_Class::TryStartTask(void* pOwner, void* pTask, bool bClearPending)
{
    FUN_00b02220_Owner* pkOwner = (FUN_00b02220_Owner*)pOwner;
    FUN_00b02220_Task* pkTask2 = (FUN_00b02220_Task*)pTask;
    EnterCriticalSection(&pkOwner->m_kLock);
    bool bResult;
    bool bAcquired;
    if ((bAcquired = InterlockedCompareExchange(&pkTask2->m_lBusy, 1, 0) == 0))
    {
    }
    if (bAcquired)
    {
        bResult = pkOwner->m_bEnableState && pkOwner->m_bPending && pkTask2->m_pkOwnerManager == 0;
        if (bResult == true)
        {
            pkTask2->m_pkOwnerManager = pkOwner;
            pkTask2->m_bDone = false;
            if (bClearPending)
                pkOwner->m_bPending = false;
            bResult = QueueItem(pkTask2);
            pkOwner->m_iArrayLength++;
        }
        else
        {
            pkTask2->m_lBusy = 0;
        }
    }
    else
    {
        bResult = false;
    }
    LeaveCriticalSection(&pkOwner->m_kLock);
    return bResult;
}

struct NiMemoryManager_b02010
{
};

struct Spawned_b02010
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    Spawned_b02010();
    static void* operator new(std::size_t size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::NiMemoryManager_b02010 *>(&::g_memoryManager))))->FUN_00aa3e40(size);
    }
    static void operator delete(void*)
    {}
};

struct Owner_b02010
{
    unsigned int unk00;
    bool FUN_00b02010(Spawned_b02010** out);
};

// @fnv 0x00b02010
bool Owner_b02010::FUN_00b02010(Spawned_b02010** out)
{
    Spawned_b02010* v = new Spawned_b02010;
    *out = v;
    return v != 0;
}











// @fnv 0x00b02460
void JobThread::FUN_00b02460()
{
    Job* pJobB;
    JobOwner* pOwner;
    unsigned int i;
    Job** ppSlot;
    bool bRun;
    while (!bStop)
    {
        pJobB = 0;
        pOwner = 0;
        kSemaphore.Wait();
        if (!bStop)
        {
            EnterCriticalSection(&kLock);
            for (i = 0, ppSlot = m_pQueueHeads; i < 64; ++i, ++ppSlot)
            {
                pJobB = *ppSlot;
                if (pJobB)
                {
                    *ppSlot = pJobB->pNext;
                    pOwner = pJobB->pOwner;
                    break;
                }
            }
            LeaveCriticalSection(&kLock);
            if (pJobB && pOwner && pJobB && !pOwner->IsBusy())
            {
                if ((bRun = pJobB->bPending ? pJobB->HasFinished() : true))
                {
                    pJobB->bPending = false;
                    pJobB->Run();
                }
            }
            if (pJobB && pOwner)
            {
                if (pJobB->bHasCallback && !pOwner->IsBusy())
                {
                    reinterpret_cast<::FUN_00b02130_shell *>(this)->QueueItem(pJobB);
                }
                else
                {
                    pJobB->Cancel();
                    pJobB->pOwner = 0;
                    pJobB->unk10 = 0;
                    reinterpret_cast<::B02670Task *>((pOwner))->CompleteTask();
                }
            }
        }
        Sleep(0);
    }
}
