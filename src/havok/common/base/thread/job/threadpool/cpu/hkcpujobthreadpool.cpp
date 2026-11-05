#include "havok/hkCpuJobThreadPool.h"

#include <algorithm>
#include <new>
#include <stdexcept>

namespace
{
thread_local bool workerMonitorPublished = false;
}

void havok::threading::SetWorkerContext(int number, int processor, void* monitor)
{
    if (havok::base::GetMonitor())
        throw std::logic_error("worker monitor already initialized");
    havok::base::SetMonitor(static_cast<SpawnedBuffer*>(monitor));
    workerMonitorPublished = true;
    SetPlatformWorkerContext(number, processor);
}

void havok::threading::ClearWorkerContext()
{
    try
    {
        if (workerMonitorPublished)
        {
            havok::base::SetMonitor(nullptr);
            workerMonitorPublished = false;
        }
        ClearPlatformWorkerContext();
    }
    catch (...) { std::terminate(); }
}

// @fnv 0x00d2d380
hkCpuJobThreadPool::Cinfo::Cinfo() = default;

// @fnv 0x00d2d110
hkCpuJobThreadPool::hkCpuJobThreadPool(hkMemorySystem& memory, const Cinfo& config)
    : memory(memory), config(config)
{
    if (config.numThreads < 0 || config.timerBufferBytes < 0 ||
        config.numHardwareThreadIds < 0 ||
        (config.numHardwareThreadIds && !config.hardwareThreadIds))
        throw std::invalid_argument("invalid worker configuration");
    const int desired = config.numThreads > 6 ? 5 : config.numThreads;
    if (config.numHardwareThreadIds && config.numHardwareThreadIds < desired)
        throw std::invalid_argument("missing worker processor ids");
    if (!completion.Create(6))
        throw std::bad_alloc();
    try
    {
        while (count < desired)
            InitializeWorkerThread();
        // The retained constructor consumes this array; later growth uses default affinity.
        this->config.hardwareThreadIds = nullptr;
        this->config.numHardwareThreadIds = 0;
    }
    catch (...)
    {
        Shutdown();
        throw;
    }
}

hkCpuJobThreadPool::~hkCpuJobThreadPool()
{
    Shutdown();
}

// @fnv 0x00d2d240
void hkCpuJobThreadPool::InitializeWorkerThread()
{
    WaitForCompletion();
    if (closed || count == 6)
        throw std::logic_error("worker pool cannot grow");
    Worker& worker = workers[count];
    worker.pool = this;
    worker.number = count + 1;
    worker.processor = config.numHardwareThreadIds > count ? config.hardwareThreadIds[count] :
                       worker.number % std::max(1, havok::threading::ProcessorCount());
    worker.quit = false;
    worker.clearTimers = false;
    worker.ready = false;
    worker.exited = false;
    worker.failure = nullptr;
    if (!worker.wake.Create(1))
        throw std::bad_alloc();
    if (!worker.thread.Start(&CpuJobThreadMain, &worker, config.name, config.stackBytes))
    {
        worker.wake.Close();
        throw std::bad_alloc();
    }
    // Readiness is separate from work completion. Failed initialization also acks.
    completion.Acquire();
    if (!worker.ready)
    {
        JoinWorker(worker);
        if (worker.failure)
            std::rethrow_exception(worker.failure);
        throw std::bad_alloc();
    }
    ++count;
}

// @fnv 0x00d2ce30
bool hkCpuJobThreadPool::IsProcessing() const { return running; }

// @fnv 0x00d2ce40
int hkCpuJobThreadPool::GetNumThreads() const { return count; }

void hkCpuJobThreadPool::ProcessWork(Work function, void* argument)
{
    if (closed || running || !function)
        throw std::logic_error("worker pool cannot dispatch");
    for (int i = 0; i < count; ++i)
        if (workers[i].exited)
            throw std::logic_error("worker failed");
    work = function;
    workArgument = argument;
    running = true;
    for (int i = count - 1; i >= 0; --i)
        workers[i].wake.Release();
}

// @fnv 0x00d2ce90
void hkCpuJobThreadPool::WaitForCompletion()
{
    if (!running)
        return;
    for (int i = 0; i < count; ++i)
        completion.Acquire();
    running = false;
    for (int i = 0; i < count; ++i)
        if (workers[i].failure)
            std::rethrow_exception(workers[i].failure);
}

// @fnv 0x00d2d2c0
int hkCpuJobThreadPool::GetTimerData(TimerData* output, int capacity)
{
    WaitForCompletion();
    if (capacity < count || (count && !output))
        throw std::invalid_argument("insufficient timer data storage");
    for (int i = 0; i < count; ++i)
    {
        const SpawnedBuffer* monitor = workers[i].monitor;
        output[i] = {monitor->m_00, monitor->m_04};
    }
    return count;
}

// @fnv 0x00d2ced0
void hkCpuJobThreadPool::ClearTimerData()
{
    WaitForCompletion();
    for (int i = 0; i < count; ++i)
    {
        if (workers[i].monitor)
            workers[i].monitor->Reset();
        workers[i].clearTimers = true;
    }
}

// @fnv 0x00d2d330
void hkCpuJobThreadPool::SetNumThreads(int desired)
{
    if (desired < 0 || closed)
        throw std::invalid_argument("invalid worker count");
    WaitForCompletion();
    desired = std::min(desired, 6);
    while (count < desired)
        InitializeWorkerThread();
    while (count > desired)
        FUN_00d2ce50();
}

void hkCpuJobThreadPool::ReleaseMonitor(Worker& worker)
{
    if (!worker.monitor)
        return;
    worker.monitor->~SpawnedBuffer();
    worker.monitorAllocator->blockFree(worker.monitor, sizeof(SpawnedBuffer));
    worker.monitor = nullptr;
    worker.monitorAllocator = nullptr;
}

void hkCpuJobThreadPool::JoinWorker(Worker& worker)
{
    // An acknowledgement proves router cleanup, not OS thread return.
    worker.thread.JoinAndClose();
    worker.wake.Close();
    ReleaseMonitor(worker);
}

// @fnv 0x00d2ce50
void hkCpuJobThreadPool::FUN_00d2ce50()
{
    WaitForCompletion();
    if (!count)
        return;
    Worker& worker = workers[--count];
    if (!worker.exited)
    {
        worker.quit = true;
        worker.wake.Release();
        completion.Acquire();
    }
    JoinWorker(worker);
}

// @fnv 0x00d2cf00
void hkCpuJobThreadPool::Shutdown()
{
    if (closed)
        return;
    try { WaitForCompletion(); }
    catch (...) { /* Worker failures do not cancel lifetime cleanup. */ }
    int stopping = 0;
    for (int i = 0; i < count; ++i)
        if (!workers[i].exited)
        {
            ++stopping;
            workers[i].quit = true;
            workers[i].wake.Release();
        }
    for (int i = 0; i < stopping; ++i)
        completion.Acquire();
    for (int i = 0; i < count; ++i)
        JoinWorker(workers[i]);
    count = 0;
    closed = true;
    completion.Close();
}

// @fnv 0x00d2cfb0
void* CpuJobThreadMain(void* argument)
{
    auto& worker = *static_cast<hkCpuJobThreadPool::Worker*>(argument);
    worker.pool->RunWorker(worker);
    return nullptr;
}

void hkCpuJobThreadPool::RunWorker(Worker& worker)
{
    hkMemoryRouter router;
    bool attached = false;
    bool announced = false;
    try
    {
        attached = memory.InitializeThreadRouter(router, "hkCpuJobThreadPool", 3);
        if (!attached)
            throw std::bad_alloc();
        SetThreadLocalValue(&router);
        worker.monitorAllocator = router.m_debug;
        if (!worker.monitorAllocator)
            throw std::bad_alloc();
        void* storage = worker.monitorAllocator->blockAlloc(sizeof(SpawnedBuffer));
        if (!storage)
            throw std::bad_alloc();
        worker.monitor = new (storage) SpawnedBuffer(*worker.monitorAllocator);
        if (config.timerBufferBytes)
            worker.monitor->Resize(config.timerBufferBytes);
        havok::threading::SetWorkerContext(worker.number, worker.processor, worker.monitor);
        worker.ready = true;
        announced = true;
        completion.Release();
        worker.wake.Acquire();
        while (!worker.quit)
        {
            if (worker.clearTimers)
            {
                worker.monitor->Reset();
                worker.clearTimers = false;
            }
            work(workArgument);
            completion.Release();
            worker.wake.Acquire();
        }
    }
    catch (...)
    {
        worker.failure = std::current_exception();
    }
    havok::threading::ClearWorkerContext();
    SetThreadLocalValue(nullptr);
    if (attached)
        memory.ThreadQuit(router, 3);
    worker.exited = true;
    if (!announced)
        worker.ready = false;
    // This is the last access before return. The controller must still join.
    completion.Release();
}

hkCpuJobThreadPool* hkCpuJobThreadPool::Create(hkMemorySystem& memory, hkMemoryAllocator& allocator, const Cinfo& config)
{
    void* storage = allocator.blockAlloc(sizeof(hkCpuJobThreadPool));
    if (!storage)
        throw std::bad_alloc();
    try
    {
        auto* pool = new (storage) hkCpuJobThreadPool(memory, config);
        pool->objectAllocator = &allocator;
        return pool;
    }
    catch (...)
    {
        allocator.blockFree(storage, sizeof(hkCpuJobThreadPool));
        throw;
    }
}

// @fnv 0x00d2d3b0
hkCpuJobThreadPool* hkCpuJobThreadPool::DestroyIfFlagged(unsigned int flags)
{
    hkMemoryAllocator* allocator = objectAllocator;
    if ((flags & 1) && !allocator)
        throw std::logic_error("worker controller has no allocation owner");
    this->~hkCpuJobThreadPool();
    if (flags & 1)
        allocator->blockFree(this, sizeof(hkCpuJobThreadPool));
    return this;
}

// The immutable import-slot payload only needs this retained pointer type.
namespace fnv_00d2d110 { struct SYSTEM_INFO_D2D1; }
#include "generated/data/havok/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.inc"
