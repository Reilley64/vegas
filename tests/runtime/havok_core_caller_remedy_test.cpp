#include "havok/PhysicsMemory.h"
#include "check.h"

#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <new>
#include <semaphore>
#include <string_view>
#include <thread>

void StartupWorkerResources(Checks& checks)
{
    HavokPhysicsMemory physics;
    alignas(16) std::array<char, 257> borrowed{};
    hkMemoryRouter* main = physics.Initialize(borrowed.data() + 1, 256);
    checks.Equal("production entry accepts borrowed stack", true, main != nullptr);
    if (!main)
        return;
    checks.Equal("main keeps borrowed end", true, main->m_stack08 == borrowed.data() + borrowed.size());
    checks.Equal("main preserves heap-backed solver role", true, main->m_solver == main->m_heap);
    bool admitted = false;
    bool stackUsable = false;
    bool solverUsable = false;
    bool stackIndependent = false;
    std::thread worker([&] {
        hkMemoryRouter router;
        admitted = physics.GetSystem()->InitializeThreadRouter(router, "cpu-worker", 3);
        if (!admitted)
            return;
        SetThreadLocalValue(&router);
        if (router.m_stackCurrent && router.m_stack08 &&
            static_cast<char*>(router.m_stack08) - router.m_stackCurrent >= 256)
        {
            char* saved = router.m_stackCurrent;
            auto* scratch = static_cast<unsigned char*>(router.allocateStack(256));
            std::memset(scratch, 0x5a, 256);
            stackUsable = scratch[255] == 0x5a &&
                          reinterpret_cast<std::uintptr_t>(scratch) % 16 == 0;
            stackIndependent = router.m_stack04 != main->m_stack04;
            router.deallocateStack(saved);
        }
        int bytes = 9001;
        void* solution = router.solver().bufAlloc(bytes);
        if (solution)
        {
            std::memset(solution, 0x36, bytes);
            solverUsable = static_cast<unsigned char*>(solution)[9000] == 0x36;
            router.solver().bufFree(solution, bytes);
        }
        SetThreadLocalValue(nullptr);
        physics.GetSystem()->ThreadQuit(router, 3);
    });
    worker.join();
    checks.Equal("startup owner admits actual worker", true, admitted);
    checks.Equal("worker owns usable aligned stack", true, stackUsable);
    checks.Equal("worker stack is not borrowed main storage", true, stackIndependent);
    checks.Equal("worker uses heap-backed solver", true, solverUsable);
    checks.Equal("production shutdown releases worker resources", true, physics.Shutdown());
    borrowed.back() = 1;
    checks.Equal("borrowed owner remains usable", 1, int(borrowed.back()));
}

void CrossThreadTransfer(Checks& checks, int requested)
{
    HavokPhysicsMemory physics;
    alignas(16) std::array<char, 256> borrowed{};
    hkMemoryRouter* main = physics.Initialize(borrowed.data(), int(borrowed.size()));
    checks.Equal("transfer startup", true, main != nullptr);
    if (!main)
        return;
    auto* origin = static_cast<hkNativeThreadMemory*>(main->m_heap);
    int bytes = requested;
    void* transferred = main->heap().bufAlloc(bytes);
    std::memset(transferred, 0x4c, bytes);
    // The allocating router stays exclusive to this thread. The receiver first
    // detaches its own router while retaining the external allocation.
    std::binary_semaphore received(0);
    std::binary_semaphore release(0);
    std::binary_semaphore returned(0);
    std::binary_semaphore originDetached(0);
    bool admitted = false;
    bool content = false;
    bool receiverEmpty = false;
    bool receiverReusable = false;
    std::thread receiver([&] {
        hkMemoryRouter router;
        admitted = physics.GetSystem()->InitializeThreadRouter(router, "receiver", 3);
        if (admitted)
        {
            content = static_cast<unsigned char*>(transferred)[requested - 1] == 0x4c;
            receiverEmpty = !static_cast<hkNativeThreadMemory*>(router.m_heap)->HasLiveAllocations();
            physics.GetSystem()->ThreadQuit(router, 3);
        }
        received.release();
        release.acquire();
        if (!admitted)
        {
            returned.release();
            return;
        }
        physics.GetSystem()->InitializeThreadRouter(router, "receiver", 3);
        SetThreadLocalValue(&router);
        router.heap().bufFree(transferred, bytes);
        returned.release();
        originDetached.acquire();
        int reusedBytes = requested;
        void* reused = router.heap().bufAlloc(reusedBytes);
        if (reused)
        {
            std::memset(reused, 0x65, reusedBytes);
            receiverReusable = (requested > 8192 || reused == transferred) &&
                               static_cast<unsigned char*>(reused)[requested - 1] == 0x65;
            router.heap().bufFree(reused, reusedBytes);
        }
        SetThreadLocalValue(nullptr);
        physics.GetSystem()->ThreadQuit(router, 3);
    });
    received.acquire();
    checks.Equal("receiving thread admitted", true, admitted);
    checks.Equal("transferred bytes remain valid", true, content);
    checks.Equal("receiver has no local live allocations", true, receiverEmpty);
    checks.Equal("origin pinned by external block", true, origin->HasLiveAllocations());
    checks.Equal("supplying owner refuses destruction with external block", false, physics.Shutdown());
    release.release();
    returned.acquire();
    checks.Equal("transfer clears origin ownership", false, origin->HasLiveAllocations());
    physics.GetSystem()->ThreadQuit(*main, 3);
    checks.Equal("origin detaches after external block returned", true, main->m_heap == nullptr);
    originDetached.release();
    receiver.join();
    checks.Equal("receiver can allocate after transferred block returned", true, receiverReusable);
    checks.Equal("owner can shut down after transfer release", true, physics.Shutdown());
}

class FailingBacking final : public havok::native_memory::Allocator
{
  public:
    void* Allocate(std::size_t bytes) override
    {
        if (throwNext)
        {
            throwNext = false;
            throw std::bad_alloc();
        }
        if (fail)
            return nullptr;
        void* block = backing.Allocate(bytes);
        if (block)
        {
            ++live;
            allocatedBytes += bytes;
        }
        return block;
    }
    void Free(void* block, std::size_t bytes) noexcept override
    {
        if (block)
        {
            --live;
            freedBytes += bytes;
        }
        backing.Free(block, bytes);
    }
    bool fail = false;
    bool throwNext = false;
    int live = 0;
    std::size_t allocatedBytes = 0;
    std::size_t freedBytes = 0;
  private:
    havok::native_memory::AlignedAllocator backing;
};

void SharedHeapTransfer(Checks& checks, int requested, int sharedExtent, int threadExtent)
{
    FailingBacking backing;
    FUN_00cd0a60 system(backing, 0);
    alignas(16) std::array<char, 256> borrowed{};
    hkMemoryRouter* main = system.MainInitBorrowed(borrowed.data(), int(borrowed.size()));
    checks.Equal("shared transfer startup", true, main != nullptr);
    if (!main)
        return;
    void* cachedExtent = main->heap().blockAlloc(requested);
    checks.Equal("thread block retains actual class extent", threadExtent,
                 main->heap().getAllocatedSize(cachedExtent, requested));
    main->heap().blockFree(cachedExtent, requested);
    // The shared heap can own less storage than the receiving cache's class.
    void* exact = main->m_debug->blockAlloc(requested);
    checks.Equal("shared heap reports actual extent", sharedExtent,
                 main->m_debug->getAllocatedSize(exact, requested));
    std::memset(exact, 0x2a, sharedExtent);
    bool noFalseOwnership = false;
    bool refillUsable = false;
    std::thread receiver([&] {
        hkMemoryRouter router;
        system.InitializeThreadRouter(router, "shared-receiver", 3);
        if (router.heap().getAllocatedSize(exact, requested) != sharedExtent)
            std::abort();
        router.heap().blockFree(exact, requested);
        noFalseOwnership = !static_cast<hkNativeThreadMemory*>(router.m_heap)->HasLiveAllocations();
        int bytes = threadExtent;
        auto* refill = static_cast<unsigned char*>(router.heap().bufAlloc(bytes));
        std::memset(refill, 0x75, bytes);
        refillUsable = bytes >= threadExtent && refill[threadExtent - 1] == 0x75;
        router.heap().bufFree(refill, bytes);
        system.ThreadQuit(router, 3);
    });
    receiver.join();
    checks.Equal("shared allocation is not receiver-origin allocation", true, noFalseOwnership);
    checks.Equal("shared transfer cannot overexpose cache class", true, refillUsable);
    checks.Equal("shared transfer shutdown", true, system.TryMainQuit());
    checks.Equal("shared transfer releases every real backend allocation", 0, backing.live);
    checks.Equal("shared transfer matches complete backend extents", backing.allocatedBytes, backing.freedBytes);
}

void ResourceRollbackAndBoundedMode(Checks& checks)
{
    FailingBacking backing;
    FUN_00cd0a60 system(backing, 0);
    alignas(16) std::array<char, 256> borrowed{};
    hkMemoryRouter* main = system.MainInitBorrowed(borrowed.data(), int(borrowed.size()));
    checks.Equal("borrowed startup for rollback", true, main != nullptr);
    hkMemoryRouter worker;
    backing.fail = true;
    checks.Equal("worker scratch null refuses publication", false,
                 system.InitializeThreadRouter(worker, "null", 3));
    checks.Equal("null scratch rolls back slot and heap", true,
                 worker.m_threadSlot == -1 && worker.m_heap == nullptr && worker.m_solver == nullptr);
    backing.fail = false;
    backing.throwNext = true;
    bool threw = false;
    try { system.InitializeThreadRouter(worker, "throw", 3); }
    catch (const std::bad_alloc&) { threw = true; }
    checks.Equal("scratch exception propagates", true, threw);
    checks.Equal("throwing scratch rolls back slot and heap", true,
                 worker.m_threadSlot == -1 && worker.m_heap == nullptr && worker.m_solver == nullptr);
    checks.Equal("worker retries after scratch failures", true,
                 system.InitializeThreadRouter(worker, "retry", 3));
    system.ThreadQuit(worker, 3);
    checks.Equal("borrowed owner shutdown", true, system.TryMainQuit());
    checks.Equal("worker backing released without freeing borrowed main", 0, backing.live);

    FUN_00cd0a60 bounded(backing, 256);
    main = bounded.MainInit(256, 3, 8192);
    checks.Equal("explicit bounded mode initializes", true, main != nullptr);
    checks.Equal("bounded worker admission", true, bounded.InitializeThreadRouter(worker, "bounded", 3));
    checks.Equal("bounded mode shares configured solver not cache", true,
                 worker.m_solver == main->m_solver && worker.m_solver != worker.m_heap);
    int bytes = 8192;
    void* full = worker.solver().bufAlloc(bytes);
    checks.Equal("configured solver full capacity usable", true, full != nullptr);
    checks.Equal("configured solver stays bounded", true, main->solver().blockAlloc(16) == nullptr);
    worker.solver().bufFree(full, bytes);
    bounded.ThreadQuit(worker, 3);
    checks.Equal("bounded owner shutdown", true, bounded.TryMainQuit());
    checks.Equal("bounded backing released", 0, backing.live);
}

int main(int argc, char** argv)
{
    Checks checks("runtime.havok_core_caller_remedy");
    const std::string_view mode = argc > 1 ? argv[1] : "all";
    if (mode == "startup" || mode == "all")
        StartupWorkerResources(checks);
    if (mode == "transfer" || mode == "all")
    {
        CrossThreadTransfer(checks, 113);
        CrossThreadTransfer(checks, 9001);
    }
    if (mode == "shared" || mode == "all")
    {
        SharedHeapTransfer(checks, 65, 80, 96);
        SharedHeapTransfer(checks, 97, 112, 128);
        SharedHeapTransfer(checks, 641, 641, 1024);
        SharedHeapTransfer(checks, 128, 128, 128);
        SharedHeapTransfer(checks, 9001, 9001, 9001);
    }
    if (mode == "rollback" || mode == "all")
        ResourceRollbackAndBoundedMode(checks);
    return checks.ExitCode();
}
