#include "havok/hkCpuJobThreadPool.h"
#include "fnv/decl/FUN_00cd0a60.h"
#include "check.h"

#include <atomic>
#include <cstring>
#include <stdexcept>

class Backing final : public havok::native_memory::Allocator
{
  public:
    havok::native_memory::AlignedAllocator native;
    std::atomic<int> live{0};
    std::atomic<int> failAfter{-1};
    void* Allocate(std::size_t bytes) override
    {
        int remaining = failAfter.load();
        if (remaining == 0)
            return nullptr;
        if (remaining > 0)
            --failAfter;
        void* block = native.Allocate(bytes);
        if (block)
            ++live;
        return block;
    }
    void Free(void* block, std::size_t bytes) noexcept override
    {
        if (block)
            --live;
        native.Free(block, bytes);
    }
};

struct Work
{
    std::atomic<int> calls{0};
    std::atomic<int> validRouters{0};
    std::atomic<int> validMonitors{0};
    static void Run(void* argument)
    {
        auto& work = *static_cast<Work*>(argument);
        auto* router = static_cast<hkMemoryRouter*>(FUN_00c85750());
        if (router && router->m_threadSlot >= 0)
        {
            int bytes = 97;
            void* block = router->heap().bufAlloc(bytes);
            if (block)
            {
                std::memset(block, 0x5a, bytes);
                router->heap().bufFree(block, bytes);
                ++work.validRouters;
            }
        }
        auto* monitor = havok::base::GetMonitor();
        if (monitor && monitor->m_00 && monitor->m_04 < monitor->m_0c)
        {
            *monitor->m_04++ = 'W';
            ++work.validMonitors;
        }
        ++work.calls;
    }
};

#ifdef FNV_POOL_PLATFORM_TEST
namespace pool_test_platform
{
extern std::atomic<int> cleanReturns, contextClears;
extern int failContextAfter;
extern thread_local int failNewAfter;
extern std::atomic<int> failedPublishedContexts;
}
void CheckHandles(Checks& checks)
{
    checks.Equal("every cleared worker reached actual thread exit before join returned",
                 pool_test_platform::contextClears.load(), pool_test_platform::cleanReturns.load());
}
#endif

int main()
{
    Checks checks("runtime.havok_worker_pool");
    Backing backing;
    {
        FUN_00cd0a60 system(backing, 257);
        hkCpuJobThreadPool::Cinfo config;
        config.numThreads = 3;
        config.timerBufferBytes = 257;
        Work work;
        {
            hkCpuJobThreadPool pool(system, config);
            checks.Equal("all workers ready before constructor returns", 3, pool.GetNumThreads());
            checks.Equal("ready pool is idle", false, pool.IsProcessing());
            std::array<hkCpuJobThreadPool::TimerData, 6> timers;
            checks.Equal("one monitor range per ready worker", 3, pool.GetTimerData(timers.data(), timers.size()));
            for (int i = 0; i < 3; ++i)
                checks.Equal("new monitor range is empty", true, timers[i].begin && timers[i].begin == timers[i].end);
            pool.ProcessWork(&Work::Run, &work);
            pool.WaitForCompletion();
            checks.Equal("one dispatch per real worker", 3, work.calls.load());
            checks.Equal("work sees initialized production router", 3, work.validRouters.load());
            checks.Equal("work sees published production monitor", 3, work.validMonitors.load());
            pool.GetTimerData(timers.data(), timers.size());
            for (int i = 0; i < 3; ++i)
            {
                checks.Equal("work writes the pool-owned monitor", true, timers[i].end == timers[i].begin + 1);
                if (timers[i].end == timers[i].begin + 1)
                    checks.Equal("pool timer range contains dispatched work", 'W', *timers[i].begin);
            }
            pool.ProcessWork(&Work::Run, &work);
        }
        checks.Equal("destructor finishes outstanding work", 6, work.calls.load());
        checks.Equal("pool leaves no allocation before system quit", 0, backing.live.load());
        checks.Equal("all worker routers detached before system quit", true, system.TryMainQuit());
    }
#ifdef FNV_POOL_PLATFORM_TEST
    CheckHandles(checks);
#endif
    {
        FUN_00cd0a60 system(backing, 257);
        hkCpuJobThreadPool::Cinfo config;
        config.numThreads = 2;
        config.timerBufferBytes = 97;
        Work work;
        {
            hkCpuJobThreadPool pool(system, config);
            pool.SetNumThreads(4);
            pool.ProcessWork(&Work::Run, &work);
            pool.SetNumThreads(1);
            checks.Equal("resize waits for work then joins removed workers", 4, work.calls.load());
            checks.Equal("one worker retained", 1, pool.GetNumThreads());
            backing.failAfter = 0;
            bool growCaught = false;
            try { pool.SetNumThreads(3); }
            catch (const std::bad_alloc&) { growCaught = true; }
            backing.failAfter = -1;
            checks.Equal("growth failure keeps existing ready worker", true, growCaught && pool.GetNumThreads() == 1);
            pool.SetNumThreads(3);
            pool.ClearTimerData();
            pool.ProcessWork(&Work::Run, &work);
            pool.WaitForCompletion();
            checks.Equal("reused worker records dispatch", 7, work.calls.load());
            pool.SetNumThreads(0);
            checks.Equal("remove-one releases all monitor and worker storage", 0, backing.live.load());
            pool.SetNumThreads(2);
            pool.ProcessWork([](void*) { throw std::runtime_error("work failed"); }, nullptr);
            bool caught = false;
            try { pool.WaitForCompletion(); }
            catch (const std::runtime_error&) { caught = true; }
            checks.Equal("worker failure reaches controller", true, caught);
            pool.Shutdown();
            pool.Shutdown();
        }
        checks.Equal("failed workers still joined and storage released", 0, backing.live.load());
        checks.Equal("failed worker routers detached", true, system.TryMainQuit());
    }
    // The backing failure positions are synthetic allocation injections, not original layout claims.
    for (int failure = 0; failure < 9; ++failure)
    {
        FUN_00cd0a60 system(backing, 257);
        hkCpuJobThreadPool::Cinfo config;
        config.numThreads = 3;
        config.timerBufferBytes = 97;
        backing.failAfter = failure;
        bool caught = false;
        try { hkCpuJobThreadPool pool(system, config); }
        catch (const std::bad_alloc&) { caught = true; }
        backing.failAfter = -1;
        checks.Equal("partial router or monitor startup fails", true, caught);
        checks.Equal("partial startup frees every allocation", 0, backing.live.load());
        checks.Equal("partial startup detaches all routers", true, system.TryMainQuit());
    }
    {
        FUN_00cd0a60 system(backing, 257);
        hkMemoryRouter* main = system.MainInit(257, 3);
        hkCpuJobThreadPool::Cinfo config;
        config.numThreads = 3;
        config.timerBufferBytes = 97;
        // Use the shared allocator, not the main thread's private cache.
        hkCpuJobThreadPool* pool = hkCpuJobThreadPool::Create(system, *main->m_debug, config);
        Work work;
        pool->ProcessWork(&Work::Run, &work);
        pool->DestroyIfFlagged(1);
        checks.Equal("allocator-owned release waits for real workers", 3, work.calls.load());
        checks.Equal("only main scratch remains after controller release", 1, backing.live.load());
        checks.Equal("allocator-owned release allows system quit", true, system.TryMainQuit());
        checks.Equal("system quit frees final allocation", 0, backing.live.load());
    }
#ifdef FNV_POOL_PLATFORM_TEST
    {
        FUN_00cd0a60 system(backing, 257);
        hkCpuJobThreadPool::Cinfo config;
        config.numThreads = 3;
        config.timerBufferBytes = 97;
        const int returned = pool_test_platform::cleanReturns.load();
        const int cleared = pool_test_platform::contextClears.load();
        pool_test_platform::failContextAfter = 2;
        bool caught = false;
        try { hkCpuJobThreadPool pool(system, config); }
        catch (const std::runtime_error&) { caught = true; }
        pool_test_platform::failContextAfter = -1;
        checks.Equal("context publication failure propagates", true, caught);
        checks.Equal("failed context had a real published monitor", 1, pool_test_platform::failedPublishedContexts.load());
        checks.Equal("failed context and earlier workers clear real monitor TLS", 3, pool_test_platform::contextClears.load() - cleared);
        checks.Equal("failure joins actual return of all three workers", 3, pool_test_platform::cleanReturns.load() - returned);
        checks.Equal("context failure releases all allocations", 0, backing.live.load());
        checks.Equal("context failure detaches all routers", true, system.TryMainQuit());
        CheckHandles(checks);
    }
    // Fail real transport allocations, including startup after earlier workers are ready.
    for (int failure = 0; failure < 7; ++failure)
    {
        FUN_00cd0a60 system(backing, 257);
        hkCpuJobThreadPool::Cinfo config;
        config.numThreads = 3;
        config.timerBufferBytes = 97;
        pool_test_platform::failNewAfter = failure;
        bool caught = false;
        try { hkCpuJobThreadPool pool(system, config); }
        catch (const std::bad_alloc&) { caught = true; }
        pool_test_platform::failNewAfter = -1;
        checks.Equal("real transport allocation failure propagates", true, caught);
        checks.Equal("transport startup failure releases storage", 0, backing.live.load());
        checks.Equal("transport failure joins before system quit", true, system.TryMainQuit());
        CheckHandles(checks);
    }
    CheckHandles(checks);
#endif
    std::printf("native controller extent %zu; monitor owner extent %zu\n", sizeof(hkCpuJobThreadPool), sizeof(SpawnedBuffer));
    return checks.ExitCode();
}
