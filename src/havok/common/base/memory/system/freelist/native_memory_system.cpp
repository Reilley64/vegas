#include "fnv/decl/FUN_00cd0a60.h"
#include "havok/PhysicsMemory.h"

#include <cstdlib>
#include <cstdint>

// @fnv 0x00cd0a60
FUN_00cd0a60::FUN_00cd0a60() : heap(backing), solver(heap) {}
FUN_00cd0a60::FUN_00cd0a60(havok::native_memory::Allocator& allocator, int scratchBytes)
    : heap(allocator), solver(heap), scratchBytes(scratchBytes)
{
    if (scratchBytes < 0)
        std::abort();
}

FUN_00cd0a60::~FUN_00cd0a60()
{
    for (const auto& record : records)
        if (record.router)
            std::abort();
}

// Retained 0x00cd0830 reserves one of 32 records before installing router fields.
// Failure rolls back the reservation before the router can be published.
bool FUN_00cd0a60::InitializeThreadRouter(hkMemoryRouter& router, const char*, int flags)
{
    std::lock_guard lock(mutex);
    if (closing)
        return false;
    if (flags & 1)
    {
        if (router.m_threadSlot != -1 || router.m_heap)
            return false;
        int slot = 0;
        while (slot < 32 && records[slot].router)
            ++slot;
        if (slot == 32)
            return false;
        Record& record = records[slot];
        record.cache.Attach(heap);
        record.router = &router;
        router.m_heap = &record.cache;
        router.m_debug = &heap;
        router.m_allocator = &heap;
        router.m_threadSlot = slot;
    }
    const int slot = router.m_threadSlot;
    if (slot < 0 || slot >= 32 || records[slot].router != &router)
        return false;
    Record& record = records[slot];
    if (flags & 2)
    {
        if (router.m_temp)
            return false;
        try
        {
            if (scratchBytes)
            {
                int bytes = scratchBytes;
                void* block = heap.bufAlloc(bytes);
                if (!block)
                {
                    if (flags & 1)
                    {
                        record.cache.Release();
                        record.router = nullptr;
                        router.Clear();
                        router.m_threadSlot = -1;
                    }
                    return false;
                }
                record.scratchCapacity = bytes;
                router.m_stackCurrent = static_cast<char*>(block);
                router.m_stack04 = block;
                router.m_stack08 = static_cast<char*>(block) + bytes;
            }
        }
        catch (...)
        {
            if (flags & 1)
            {
                record.cache.Release();
                record.router = nullptr;
                router.Clear();
                router.m_threadSlot = -1;
            }
            throw;
        }
        router.m_temp = &record.cache;
        // Borrowed-stack startup uses heap-backed solvers. Keep each worker's
        // cache exclusive to that worker rather than sharing the main cache.
        router.m_solver = mainRouter.m_solver && mainRouter.m_solver == mainRouter.m_heap
                              ? &record.cache : static_cast<hkMemoryAllocator*>(&solver);
    }
    return true;
}

void FUN_00cd0a60::ReleaseScratch(hkMemoryRouter& router)
{
    Record& record = records[router.m_threadSlot];
    if (record.scratchCapacity)
        heap.bufFree(router.m_stack04, record.scratchCapacity);
    record.scratchCapacity = 0;
    router.m_stackCurrent = nullptr;
    router.m_stack04 = nullptr;
    router.m_stack08 = nullptr;
    router.m_temp = nullptr;
    router.m_solver = nullptr;
}

// Retained 0x00cd0940 separates scratch release from cache/record release.
void FUN_00cd0a60::ThreadQuit(hkMemoryRouter& router, int flags)
{
    std::lock_guard lock(mutex);
    if (router.m_threadSlot == -1)
        return;
    const int slot = router.m_threadSlot;
    if (slot < 0 || slot >= 32 || records[slot].router != &router)
        std::abort();
    if (flags & 3)
        ReleaseScratch(router);
    if (flags & 1)
    {
        Record& record = records[slot];
        record.cache.Release();
        record.router = nullptr;
        router.Clear();
        router.m_threadSlot = -1;
    }
}

hkMemoryRouter* FUN_00cd0a60::MainInit(int bytes, int flags, int solverBytes)
{
    if (bytes < 0 || mainRouter.m_threadSlot != -1)
        return nullptr;
    scratchBytes = bytes;
    try
    {
        if ((flags & 2) && !solver.Initialize(solverBytes))
            return nullptr;
        if (InitializeThreadRouter(mainRouter, "main", flags))
            return &mainRouter;
    }
    catch (...)
    {
        if (flags & 2)
            solver.Release();
        throw;
    }
    if (flags & 2)
        solver.Release();
    return nullptr;
}
bool FUN_00cd0a60::TryMainQuit()
{
    {
        std::lock_guard lock(mutex);
        for (const auto& record : records)
            if (record.router && (record.router != &mainRouter || record.cache.HasLiveAllocations()))
                return false;
        closing = true;
    }
    MainQuit(3);
    return true;
}

void FUN_00cd0a60::MainQuit(int flags)
{
    ThreadQuit(mainRouter, flags);
    if (flags & 2)
        solver.Release();
}

// The supplied stack extent also configures independently owned worker stacks.
// Main keeps borrowed storage and the retained heap-backed temporary/solver roles.
// Align the start while retaining the caller's original end.
hkMemoryRouter* FUN_00cd0a60::MainInitBorrowed(void* stack, int bytes)
{
    if (!stack || bytes <= 0)
        return nullptr;
    auto address = reinterpret_cast<std::uintptr_t>(stack);
    const int padding = static_cast<int>((16 - address % 16) % 16);
    if (bytes <= padding)
        return nullptr;
    hkMemoryRouter* router = MainInit(bytes, 1);
    if (!router)
        return nullptr;
    router->m_temp = router->m_heap;
    router->m_solver = router->m_heap;
    router->m_stackCurrent = static_cast<char*>(stack) + padding;
    router->m_stack04 = router->m_stackCurrent;
    router->m_stack08 = static_cast<char*>(stack) + bytes;
    return router;
}

HavokPhysicsMemory g_havokPhysicsMemory;

hkMemoryRouter* HavokPhysicsMemory::Initialize(void* borrowedStack, int bytes)
{
    if (system)
        return nullptr;
    auto candidate = std::make_unique<FUN_00cd0a60>();
    hkMemoryRouter* router = candidate->MainInitBorrowed(borrowedStack, bytes);
    if (router)
        system = std::move(candidate);
    return router;
}

bool HavokPhysicsMemory::Shutdown()
{
    if (!system)
        return true;
    if (!system->TryMainQuit())
        return false;
    SetThreadLocalValue(nullptr);
    system.reset();
    return true;
}
