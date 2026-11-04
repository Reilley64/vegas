#include "runtime/havok_memory_prerequisite.h"
#include "check.h"

#include <array>
#include <atomic>
#include <cstring>
#include <cstdint>
#include <latch>
#include <limits>
#include <new>
#include <semaphore>
#include <thread>

using namespace havok::native_memory;

class TrackingAllocator final : public Allocator
{
  public:
    AlignedAllocator backing;
    enum class Failure { None, Null, Exception };
    Failure failure = Failure::None;
    int allocations = 0;
    int frees = 0;
    std::size_t allocatedBytes = 0;
    std::size_t freedBytes = 0;

    void* Allocate(std::size_t bytes) override
    {
        ++allocations;
        if (failure == Failure::Null)
            return nullptr;
        if (failure == Failure::Exception)
            throw std::bad_alloc();
        void* block = backing.Allocate(bytes);
        if (block)
            allocatedBytes += bytes;
        return block;
    }
    void Free(void* block, std::size_t bytes) noexcept override
    {
        if (block)
        {
            ++frees;
            freedBytes += bytes;
        }
        backing.Free(block, bytes);
    }
};

void TestBackend(Checks& checks)
{
    AlignedAllocator allocator;
    for (std::size_t bytes : {1u, 15u, 16u, 17u, 73u, 257u})
    {
        void* block = allocator.Allocate(bytes);
        checks.Equal("backend block", true, block != nullptr);
        checks.Equal("backend alignment", std::uintptr_t{0}, reinterpret_cast<std::uintptr_t>(block) % 16);
        if (block)
            std::memset(block, 0x5a, bytes);
        allocator.Free(block, bytes);
    }
    checks.Equal("zero extent rejected", true, allocator.Allocate(0) == nullptr);
    checks.Equal("extent overflow rejected", true,
                 allocator.Allocate(std::numeric_limits<std::size_t>::max()) == nullptr);
    allocator.Free(nullptr, 0);
}

void TestStacks(Checks& checks)
{
    TrackingAllocator allocator;
    System system(allocator, ScratchBytes{257});
    Router router;
    checks.Equal("owned initialization", true, system.Initialize(router));
    checks.Equal("exact requested extent", std::size_t{257}, allocator.allocatedBytes);
    checks.Equal("repeat init rejected", false, system.Initialize(router));
    checks.Equal("repeat does not allocate", 1, allocator.allocations);
    void* start = nullptr;
    {
        Router::StackScope outer(router);
        start = router.AllocateStack(1);
        checks.Equal("stack exists", true, start != nullptr);
        {
            Router::StackScope inner(router);
            void* aligned = router.AllocateStack(17);
            checks.Equal("padding checked", true, aligned == static_cast<char*>(start) + 16);
            checks.Equal("nested alignment", std::uintptr_t{0}, reinterpret_cast<std::uintptr_t>(aligned) % 16);
            checks.Equal("overflow checked", true,
                         router.AllocateStack(std::numeric_limits<std::size_t>::max()) == nullptr);
            checks.Equal("zero unchanged", true, router.AllocateStack(0) == nullptr);
            checks.Equal("overflow leaves cursor", true, router.AllocateStack(209) == static_cast<char*>(start) + 48);
            checks.Equal("exact end bounded", true, router.AllocateStack(1) == nullptr);
        }
        checks.Equal("inner restore", true, router.AllocateStack(241) == static_cast<char*>(start) + 16);
    }
    try
    {
        Router::StackScope unwind(router);
        checks.Equal("scope before exception", true, router.AllocateStack(1) == start);
        throw std::bad_alloc();
    }
    catch (const std::bad_alloc&) {}
    checks.Equal("outer and exception restore", true, router.AllocateStack(257) == start);
    std::memset(start, 0x35, 257);
    system.ReleaseScratch(router);
    checks.Equal("record retained", true, router.IsInitialized());
    checks.Equal("scratch gone", true, router.AllocateStack(1) == nullptr);
    checks.Equal("exact release", std::size_t{257}, allocator.freedBytes);
    checks.Equal("heap retained", true, &router.heap() == &allocator);
    system.ReleaseScratch(router);
    system.Quit(router);
    system.Quit(router);
    checks.Equal("one owned free", 1, allocator.frees);
    checks.Equal("detached", false, router.IsInitialized());

    alignas(16) std::array<char, 257> borrowed{};
    checks.Equal("unaligned rejected", false, system.InitializeBorrowed(router, borrowed.data() + 1, 16));
    checks.Equal("null rejected", false, system.InitializeBorrowed(router, nullptr, 16));
    checks.Equal("empty rejected", false, system.InitializeBorrowed(router, borrowed.data(), 0));
    checks.Equal("wrapping region rejected", false,
                 system.InitializeBorrowed(router, borrowed.data(), std::numeric_limits<std::size_t>::max()));
    checks.Equal("borrowed initialize", true, system.InitializeBorrowed(router, borrowed.data(), borrowed.size()));
    {
        Router::StackScope scope(router);
        checks.Equal("borrowed exact extent", true, router.AllocateStack(257) == borrowed.data());
        checks.Equal("borrowed bounded", true, router.AllocateStack(1) == nullptr);
    }
    checks.Equal("borrowed restore", true, router.AllocateStack(257) == borrowed.data());
    system.Quit(router);
    checks.Equal("borrowed never freed", 1, allocator.frees);
    borrowed[256] = 1;
    checks.Equal("reuse after borrowed quit", true, system.Initialize(router));
    system.Quit(router);
    checks.Equal("reuse owned released", 2, allocator.frees);
}

void TestRollback(Checks& checks)
{
    TrackingAllocator allocator;
    System system(allocator, ScratchBytes{257});
    std::array<Router, 31> residents;
    alignas(16) char borrowed[16]{};
    for (auto& router : residents)
        checks.Equal("reserve resident", true, system.InitializeBorrowed(router, borrowed, sizeof(borrowed)));
    Router worker;
    allocator.failure = TrackingAllocator::Failure::Null;
    checks.Equal("null after reservation", false, system.Initialize(worker));
    checks.Equal("null detached", false, worker.IsInitialized());
    checks.Equal("null scratch detached", true, worker.AllocateStack(1) == nullptr);
    allocator.failure = TrackingAllocator::Failure::Exception;
    bool caught = false;
    try { system.Initialize(worker); }
    catch (const std::bad_alloc&) { caught = true; }
    checks.Equal("exception propagated", true, caught);
    checks.Equal("exception detached", false, worker.IsInitialized());
    checks.Equal("allocation attempted after both reservations", 2, allocator.allocations);
    allocator.failure = TrackingAllocator::Failure::None;
    checks.Equal("last record restored and retry", true, system.Initialize(worker));
    Router overflow;
    checks.Equal("full rejects", false, system.Initialize(overflow));
    checks.Equal("capacity failure does not allocate", 3, allocator.allocations);
    system.Quit(worker);
    checks.Equal("released record retry", true, system.Initialize(overflow));
    system.Quit(overflow);
    for (auto& router : residents)
        system.Quit(router);
    checks.Equal("only completed allocations freed", 2, allocator.frees);
    checks.Equal("exact rollback totals", std::size_t{514}, allocator.freedBytes);
}

void TestConcurrentCapacity(Checks& checks)
{
    AlignedAllocator allocator;
    // Controller holds the real owner by value; workers receive this same owner.
    System system(allocator, ScratchBytes{257});
    Router main;
    alignas(16) char borrowed[32]{};
    checks.Equal("main record", true, system.InitializeBorrowed(main, borrowed, sizeof(borrowed)));
    std::array<std::thread, 31> threads;
    struct Gate { std::binary_semaphore value{0}; };
    std::array<Gate, 31> release;
    std::array<bool, 31> results{};
    std::latch ready(31);
    for (std::size_t i = 0; i < threads.size(); ++i)
    {
        threads[i] = std::thread([&, i] {
            Router router;
            bool good = system.Initialize(router);
            if (good)
            {
                void* block = router.heap().Allocate(73);
                good = block && reinterpret_cast<std::uintptr_t>(block) % 16 == 0;
                if (block)
                    std::memset(block, 0x17, 73);
                router.heap().Free(block, 73);
                Router::StackScope scope(router);
                void* scratch = router.AllocateStack(257);
                good = good && scratch && router.AllocateStack(1) == nullptr;
                if (scratch)
                    std::memset(scratch, 0x29, 257);
            }
            results[i] = good;
            ready.count_down();
            release[i].value.acquire();
            system.Quit(router);
        });
    }
    ready.wait();
    Router rejected;
    checks.Equal("main plus 31 rejects 33rd", false, system.Initialize(rejected));
    checks.Equal("rejected router detached", false, rejected.IsInitialized());
    release[0].value.release();
    threads[0].join();
    checks.Equal("joined release enables retry", true, system.Initialize(rejected));
    system.Quit(rejected);
    for (std::size_t i = 1; i < threads.size(); ++i)
    {
        release[i].value.release();
        threads[i].join();
    }
    for (bool good : results)
        checks.Equal("real worker heap and bounded scratch", true, good);
    system.Quit(main);
}

void TestPlanningLoad(Checks& checks)
{
    AlignedAllocator allocator;
    System system(allocator, ScratchBytes{0});
    // Conservative coexistence assumption: main + 16 tasklets + 2 AI-linear +
    // 3 AI-task + 6 pool + 2 audio = 30, not evidence those game owners migrated.
    std::array<Router, 33> routers;
    std::size_t index = 0;
    for (unsigned family : {1u, 16u, 2u, 3u, 6u, 2u})
        for (unsigned i = 0; i < family; ++i)
            checks.Equal("planning load admitted", true, system.Initialize(routers[index++]));
    checks.Equal("30 load leaves first record", true, system.Initialize(routers[30]));
    checks.Equal("30 load leaves second record", true, system.Initialize(routers[31]));
    checks.Equal("30 plus 2 bounded", false, system.Initialize(routers[32]));
    checks.Equal("heap only has no scratch", true, routers[0].AllocateStack(1) == nullptr);
    system.Quit(routers[12]);
    checks.Equal("planning release retry", true, system.Initialize(routers[32]));
    for (auto& router : routers)
        system.Quit(router);
}

int main()
{
    Checks checks("native memory prerequisite");
    TestBackend(checks);
    TestStacks(checks);
    TestRollback(checks);
    TestConcurrentCapacity(checks);
    TestPlanningLoad(checks);
    return checks.ExitCode();
}
