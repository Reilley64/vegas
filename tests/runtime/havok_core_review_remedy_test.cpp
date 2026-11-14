#include "havok/hkMemorySystem.h"
#include "check.h"

#include <array>
#include <cstdint>
#include <cstdlib>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif

// OS boundary fixture: full writable virtual extents, demand-zero physical pages.
// Large accounting requests touch only endpoints, not gigabytes of resident data.
class MappedBacking final : public havok::native_memory::Allocator
{
  public:
    ~MappedBacking() override
    {
        for (const auto& mapping : mappings)
            if (mapping.block)
                std::abort();
    }

    void* Allocate(std::size_t bytes) override
    {
        for (auto& mapping : mappings)
            if (!mapping.block)
            {
#ifdef _WIN32
                void* block = VirtualAlloc(nullptr, bytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
#else
                void* block = mmap(nullptr, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
                if (block == MAP_FAILED)
                    return nullptr;
#endif
                if (block)
                    mapping = {block, bytes};
                return block;
            }
        return nullptr;
    }

    void Free(void* block, std::size_t bytes) noexcept override
    {
        if (!block)
            return;
        for (auto& mapping : mappings)
            if (mapping.block == block)
            {
                if (mapping.bytes != bytes)
                    std::abort();
#ifdef _WIN32
                if (!VirtualFree(block, 0, MEM_RELEASE))
#else
                if (munmap(block, bytes) != 0)
#endif
                    std::abort();
                mapping = {};
                return;
            }
        std::abort();
    }

  private:
    struct Mapping { void* block = nullptr; std::size_t bytes = 0; };
    std::array<Mapping, 2> mappings{};
};

// Requirement: native x64 aggregate accounting must not overflow the legacy int API.
void HeapAggregateBoundary(Checks& checks)
{
    MappedBacking backing;
    hkSystemMemoryAllocator heap(backing);
    hkMemoryAllocator& allocator = heap;
    constexpr int gib = 1073741824;
    void* first = allocator.blockAlloc(gib);
    void* second = allocator.blockAlloc(gib);
    if (!first || !second)
    {
        allocator.blockFree(first, gib);
        allocator.blockFree(second, gib);
        checks.Fail("aggregate boundary", "blocked: OS virtual mapping unavailable");
        return;
    }
    checks.Equal("disjoint real mappings", true, first != second);
    for (void* block : {first, second})
    {
        checks.Equal("backing alignment", std::uintptr_t(0), reinterpret_cast<std::uintptr_t>(block) % 16);
        auto* bytes = static_cast<volatile unsigned char*>(block);
        bytes[0] = 0x5a;
        bytes[gib - 1] = 0xa5;
        checks.Equal("writable full requested extent", 0xa5, int(bytes[gib - 1]));
    }
    hkMemoryAllocator::MemoryStatistics statistics;
    allocator.getMemoryStatistics(statistics);
    checks.Equal("aggregate allocated clamps at legacy limit", (std::numeric_limits<int>::max)(), statistics.allocated);
    checks.Equal("aggregate in-use clamps at legacy limit", (std::numeric_limits<int>::max)(), statistics.inUse);
    checks.Equal("aggregate peak clamps at legacy limit", (std::numeric_limits<int>::max)(), statistics.peakInUse);
    allocator.resetPeakMemoryStatistics();
    allocator.blockFree(first, gib);
    allocator.getMemoryStatistics(statistics);
    checks.Equal("free recovers exact below-limit aggregate", gib, statistics.inUse);
    checks.Equal("allocated recovers exact below-limit aggregate", gib, statistics.allocated);
    checks.Equal("reset above limit retains wide peak", (std::numeric_limits<int>::max)(), statistics.peakInUse);
    allocator.resetPeakMemoryStatistics();
    allocator.getMemoryStatistics(statistics);
    checks.Equal("reset below limit publishes exact live bytes", gib, statistics.peakInUse);
    allocator.blockFree(second, gib);
    allocator.getMemoryStatistics(statistics);
    checks.Equal("all aggregate storage released", 0, statistics.inUse);
    checks.Equal("peak survives last free", gib, statistics.peakInUse);
    allocator.resetPeakMemoryStatistics();
    allocator.getMemoryStatistics(statistics);
    checks.Equal("empty peak reset", 0, statistics.peakInUse);
}

// Requirement: retained 0x00d5e8a0 admits by total arena capacity, not current holes.
void SolverCapacity(Checks& checks)
{
    havok::native_memory::AlignedAllocator backing;
    hkSystemMemoryAllocator heap(backing);
    hkNativeSolverAllocator solver(heap);
    hkMemoryAllocator& allocator = solver;
    checks.Equal("uninitialized arena rejects positive request", false, allocator.canAllocTotal(1));
    checks.Equal("initialize arena", true, solver.Initialize(8192));
    checks.Equal("below capacity", true, allocator.canAllocTotal(8191));
    checks.Equal("at capacity", true, allocator.canAllocTotal(8192));
    checks.Equal("above capacity", false, allocator.canAllocTotal(8193));
    checks.Equal("forwarding retains bounded predicate", false, allocator.forwardToCanAllocTotal(8193));
    int bytes = 8192;
    void* all = allocator.bufAlloc(bytes);
    checks.Equal("allocate whole arena", true, all != nullptr);
    checks.Equal("capacity predicate is not current free space", true, allocator.canAllocTotal(8192));
    checks.Equal("full arena cannot allocate another block", true, allocator.blockAlloc(16) == nullptr);
    allocator.bufFree(all, bytes);
    solver.Release();
    checks.Equal("released arena rejects positive request", false, allocator.canAllocTotal(1));
}

int main()
{
    Checks checks("runtime.havok_core_review_remedy");
    checks.Run("solver capacity", [&] { SolverCapacity(checks); });
    checks.Run("heap aggregate boundary", [&] { HeapAggregateBoundary(checks); });
    return checks.ExitCode();
}
