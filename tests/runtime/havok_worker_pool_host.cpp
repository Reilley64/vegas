#include "havok/hkCpuJobThreadPool.h"

#include <atomic>
#include <cstdlib>
#include <new>
#include <stdexcept>

// Retained import-slot payload, not used by the standard-C++ transport.
extern "C" void TestGetSystemInfo() __asm__("GetSystemInfo");
extern "C" void TestGetSystemInfo() { std::abort(); }

#ifdef FNV_POOL_PLATFORM_TEST
namespace pool_test_platform
{
std::atomic<int> cleanReturns{0};
std::atomic<int> contextClears{0};
std::atomic<int> failedPublishedContexts{0};
int failContextAfter = -1;
thread_local int failNewAfter = -1;
thread_local int workerNumber = 0;
thread_local bool cleared = false;
bool Fail(int& after)
{
    if (after == 0)
        return true;
    if (after > 0)
        --after;
    return false;
}
struct ThreadExit
{
    ~ThreadExit()
    {
        if (FUN_00c85750() || havok::base::GetMonitor() || workerNumber || !cleared)
            std::abort();
        ++cleanReturns;
    }
};
thread_local ThreadExit exitCheck;
}

// Allocation injection affects real std::thread/semaphore storage, not their operations.
void* operator new(std::size_t bytes)
{
    if (pool_test_platform::Fail(pool_test_platform::failNewAfter))
        throw std::bad_alloc();
    if (void* block = std::malloc(bytes ? bytes : 1))
        return block;
    throw std::bad_alloc();
}
void operator delete(void* block) noexcept { std::free(block); }
void operator delete(void* block, std::size_t) noexcept { std::free(block); }

void havok::threading::SetPlatformWorkerContext(int number, int)
{
    (void)pool_test_platform::exitCheck;
    pool_test_platform::workerNumber = number;
    pool_test_platform::cleared = false;
    if (pool_test_platform::Fail(pool_test_platform::failContextAfter))
    {
        auto* monitor = havok::base::GetMonitor();
        if (!monitor || !monitor->m_00 || monitor->m_04 != monitor->m_00)
            std::abort();
        ++pool_test_platform::failedPublishedContexts;
        throw std::runtime_error("platform context publication failed after monitor publication");
    }
}
void havok::threading::ClearPlatformWorkerContext()
{
    if (havok::base::GetMonitor())
        std::abort();
    (void)pool_test_platform::exitCheck;
    pool_test_platform::workerNumber = 0;
    pool_test_platform::cleared = true;
    ++pool_test_platform::contextClears;
}
#endif
