#pragma once

#include "havok/hkMemorySystem.h"
#include "havok/hkMonitorStream.h"
#include <array>
#include <exception>
#include <memory>
#include <semaphore>
#include <thread>

// Native transport storage is owned here, not overlaid on original-release records.
namespace havok::threading
{
struct Semaphore
{
    std::unique_ptr<std::counting_semaphore<6>> handle;
    bool Create(int maximum);
    void Acquire();
    void Release();
    void Close();
};
struct Thread
{
    using Entry = void* (*)(void*);
    std::thread thread;
    bool Start(Entry, void*, const char* name, unsigned long stackBytes);
    void JoinAndClose();
};
void SetWorkerContext(int number, int processor, void* monitor);
void ClearWorkerContext();
// Platform boundary: worker index and optional processor/FP setup, not monitor ownership.
void SetPlatformWorkerContext(int number, int processor);
void ClearPlatformWorkerContext();
int ProcessorCount();
}

class Dispatcher;

class hkCpuJobThreadPool
{
  public:
    struct Cinfo
    {
        Cinfo();
        int numThreads = 1;
        // Retained configuration only. std::thread uses the runtime's default stack.
        unsigned long stackBytes = 0x3d0900;
        int timerBufferBytes = 0;
        int threadPriority = 0;
        const int* hardwareThreadIds = nullptr;
        int numHardwareThreadIds = 0;
        int hardwareThreadIdsCapacity = static_cast<int>(0x80000000u);
        const char* name = "HavokWorkerThread";
    };
    using Work = void (*)(void*);
    hkCpuJobThreadPool(hkMemorySystem&, const Cinfo&);
    explicit hkCpuJobThreadPool(const Cinfo&);
    ~hkCpuJobThreadPool();
    hkCpuJobThreadPool(const hkCpuJobThreadPool&) = delete;
    hkCpuJobThreadPool& operator=(const hkCpuJobThreadPool&) = delete;

    // Controller calls, including destruction, must be serialized by their owner.
    void ProcessWork(Work, void*);
    void ProcessJobs(Dispatcher*);
    void WaitForCompletion();
    void SetNumThreads(int);
    struct TimerData { const char* begin; const char* end; };
    int GetTimerData(TimerData* output, int capacity);
    void ClearTimerData();
    void Shutdown();
    int GetNumThreads() const;
    bool IsProcessing() const;

    void FUN_00d2ce50();
    void InitializeWorkerThread();
    void FUN_00d2ce90() { WaitForCompletion(); }
    void FUN_00d2cf00() { Shutdown(); }
    void FUN_00d2d330(int desired) { SetNumThreads(desired); }
    void PerformVoidOperation() { ClearTimerData(); }
    bool FUN_00d2ce30() const { return IsProcessing(); }
    int FUN_00d2ce40() const { return GetNumThreads(); }
    void FUN_00d2cde0(Dispatcher* jobs, int) { ProcessJobs(jobs); }

    // Allocated controllers retain the allocator and exact native extent.
    static hkCpuJobThreadPool* Create(hkMemorySystem&, hkMemoryAllocator&, const Cinfo&);
    hkCpuJobThreadPool* DestroyIfFlagged(unsigned int);

  private:
    struct Worker
    {
        hkCpuJobThreadPool* pool = nullptr;
        havok::threading::Thread thread;
        havok::threading::Semaphore wake;
        int number = 0;
        int processor = 0;
        bool quit = false;
        bool clearTimers = false;
        bool ready = false;
        bool exited = false;
        std::exception_ptr failure;
        hkMemoryAllocator* monitorAllocator = nullptr;
        SpawnedBuffer* monitor = nullptr;
    };
    friend void* CpuJobThreadMain(void*);
    void RunWorker(Worker&);
    void ReleaseMonitor(Worker&);
    void JoinWorker(Worker&);
    hkMemorySystem& memory;
    Cinfo config;
    std::array<Worker, 6> workers;
    havok::threading::Semaphore completion;
    int count = 0;
    bool running = false;
    bool closed = false;
    Work work = nullptr;
    void* workArgument = nullptr;
    hkMemoryAllocator* objectAllocator = nullptr;
};

void* CpuJobThreadMain(void*);

namespace fnv_00d2d110
{
using hkCpuJobThreadPoolCinfoD2D1 = hkCpuJobThreadPool::Cinfo;
using FUN_00d2d110 = ::hkCpuJobThreadPool;
}
