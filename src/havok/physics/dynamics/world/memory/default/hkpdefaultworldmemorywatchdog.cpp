
// src/havok/physics/dynamics/world/memory/default/hkpdefaultworldmemorywatchdog.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/memory/default/hkpdefaultworldmemorywatchdog.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00c91620_Class.h"
#include "fnv/symbols_00e48000.h"
#include "havok/hkpDefaultWorldMemoryWatchDog.h"

struct FnvCpu_FUN_00e48260_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int FUN_00e48260();
};
// @fnv 0x00e48260
int FnvCpu_FUN_00e48260_CpuObject::FUN_00e48260()
{
    return value;
}

struct WatchdogCallback
{
};

struct WatchdogState
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    WatchdogCallback* callback18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    ::FUN_00c91620_Target** value48;
};

// @fnv 0x00e48270
void NotifyWatchdogCallback(WatchdogState* pState, int unused)
{
    reinterpret_cast<::FUN_00c91620_Class *>((pState->callback18))->ProcessTarget((unsigned char *)(void **)(reinterpret_cast<void**>(&pState)), *pState->value48);
}


namespace hkRouterE482 {

}

struct hkJobE482
{
    char unk00[0xd0];
    signed char m_priority;
};

struct hkResultE482
{
    hkResultE482()
    {}
    int m_pClassEnum;
};

class hkQueueE482
{
  public:
};

struct hkSchedulerE482
{
    int unk00[6];
    hkQueueE482* m_queue;
    int unk1C[11];
    hkJobE482** m_jobs;
    int m_numJobs;
};

// @fnv 0x00e48290
void __cdecl FUN_00e48290(hkSchedulerE482* pScheduler, int level, int param, int* piMaxLevel)
{
    for (int i = pScheduler->m_numJobs - 1; i >= 0; i--)
    {
        hkJobE482* job = pScheduler->m_jobs[i];
        int iPriority = job->m_priority;
        if (iPriority >= level)
        {
            reinterpret_cast<::FUN_00c91620_Class *>((pScheduler->m_queue))->ProcessTarget((unsigned char *)(job), {});
            if (!hkMemoryRouter::getInstance().heap().canAllocTotal(param))
                return;
        }
        else
        {
            *piMaxLevel = (*piMaxLevel > iPriority) ? *piMaxLevel : iPriority;
        }
    }
}


struct ListE483
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    void** m_ppPos;
    int m_iPosSize;
    int unk30;
    char* m_pcNeg;
    int m_iNegSize;
};

class HostE483
{
  public:
    int unk00;
    int unk04;
    int m_iMinMemoryAvailable;
    void ProcessList(ListE483* pkList);
};

// Repeatedly walks pkList from the last positive entry down through the negative entries calling FUN_00e48290, stopping once the heap can allocate the minimum available memory.
// @fnv 0x00e48300
void HostE483::ProcessList(ListE483* pkList)
{
    int iMinMemoryAvailable = m_iMinMemoryAvailable;
    int iFlags = 0x7f;
    do
    {
        int iOut = 0;
        int i = pkList->m_iPosSize - 1;
        while (i >= -pkList->m_iNegSize)
        {
            if (i >= pkList->m_iPosSize)
            {
                i = pkList->m_iPosSize - 1;
                if (i < -pkList->m_iNegSize)
                    return;
            }
            void* pvItem;
            if (i >= 0)
                pvItem = pkList->m_ppPos[i];
            else
                pvItem = reinterpret_cast<void**>(pkList->m_pcNeg)[-(i + 1)];
            ::FUN_00e48290((::hkSchedulerE482 *)(pvItem), iFlags, iMinMemoryAvailable, &iOut);
            if (hkMemoryRouter::getInstance().heap().canAllocTotal(iMinMemoryAvailable))
                return;
            i--;
        }
        iFlags = iOut;
    } while (iFlags > 0);
}
