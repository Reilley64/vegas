#include "fnv/memory/engine_heap_set.h"

#include <barrier>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <thread>
#include <type_traits>

namespace {
using fnv::memory::EngineHeap;
using fnv::memory::EngineHeapDomain;
using fnv::memory::EngineHeapSet;

void Require(bool condition, const char* expression, int line)
{
    if (!condition) {
        std::fprintf(stderr, "engine heap check at line %d: %s\n", line, expression);
        std::abort();
    }
}
#define REQUIRE(expression) Require(bool(expression), #expression, __LINE__)

void CheckPayload(const void* memory, std::size_t size, unsigned char value)
{
    const auto* bytes = static_cast<const unsigned char*>(memory);
    for (std::size_t i = 0; i < size; ++i) REQUIRE(bytes[i] == value);
}

void CheckArena()
{
    EngineHeap arena;
    REQUIRE(arena.Initialize(0x100000, 0x1000, "Arena test"));
    auto* a = arena.Allocate(8192);
    auto* b = arena.Allocate(4096);
    auto* c = arena.Allocate(8192);
    REQUIRE(a && b && c);
    REQUIRE(reinterpret_cast<std::uintptr_t>(a) % alignof(std::max_align_t) == 0);
    REQUIRE(arena.Size(static_cast<char*>(a) + 1) == 0);
    arena.Deallocate(b);
    REQUIRE(arena.Size(b) == 0);
    auto* split = arena.Allocate(1024);
    REQUIRE(split == b);
    arena.Deallocate(split);
    arena.Deallocate(a);
    auto* coalesced = arena.Allocate(9000);
    REQUIRE(coalesced == a);
    REQUIRE(arena.CheckIntegrity());
    const auto beforeFailure = arena.Statistics();
    REQUIRE(arena.Allocate(0x200000) == nullptr);
    REQUIRE(arena.Statistics().allocations == beforeFailure.allocations);
    REQUIRE(arena.Allocate((std::numeric_limits<std::size_t>::max)()) == nullptr);
    arena.Deallocate(coalesced);
    arena.Deallocate(c);
    REQUIRE(arena.Statistics().used == 0);
    REQUIRE(arena.Statistics().committed == fnv::memory::NativePageSize());
    REQUIRE(arena.CheckIntegrity());
    void* blocks[257]{};
    for (std::size_t i = 0; i < 257; ++i) {
        blocks[i] = arena.Allocate(8 + (i * 37) % 4096);
        REQUIRE(blocks[i]);
    }
    for (std::size_t i = 0; i < 257; i += 2) arena.Deallocate(blocks[i]);
    REQUIRE(arena.CheckIntegrity());
    for (std::size_t i = 1; i < 257; i += 2) arena.Deallocate(blocks[i]);
    REQUIRE(arena.Statistics().allocations == 0);
    REQUIRE(arena.Statistics().used == 0);
    REQUIRE(arena.CheckIntegrity());
    arena.Shutdown();
    REQUIRE(arena.Allocate(8) == nullptr);
    REQUIRE(arena.Size(a) == 0);
    REQUIRE(arena.Initialize(0x20000, 0, "Retry"));
    auto* retry = arena.Allocate(32);
    REQUIRE(retry);
    arena.Deallocate(retry);
}

void CheckHeapSet()
{
    static_assert(!std::is_copy_constructible_v<EngineHeapSet>);
    static_assert(!std::is_move_constructible_v<EngineHeapSet>);
    EngineHeapSet heaps;
    REQUIRE(!heaps.IsInitialized());
    REQUIRE(heaps.Allocate(8192, 36) == nullptr);
    REQUIRE(heaps.Initialize());
    REQUIRE(heaps.Initialize());
    REQUIRE(heaps.IsInitialized());
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).reserved == 0xc800000);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).committed == 0x5500000);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Context23).reserved == 0x4000000);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Context23).committed == 0x200000);
    // The auxiliary reserve is OS-page rounded; the source capacity is 0x183800.
    REQUIRE(heaps.Statistics(EngineHeapDomain::Auxiliary).used == 0);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).allocations == 0);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Context23).allocations == 0);

    auto* context9 = heaps.Allocate(8192, 9);
    auto* context23 = heaps.Allocate(8192, 23);
    auto* context36 = heaps.Allocate(8192, 36);
    REQUIRE(context9 && context23 && context36);
    REQUIRE(heaps.OwnerOf(context9) == EngineHeapDomain::Auxiliary);
    REQUIRE(heaps.OwnerOf(context23) == EngineHeapDomain::Context23);
    REQUIRE(heaps.OwnerOf(context36) == EngineHeapDomain::Main);
    REQUIRE(reinterpret_cast<std::uintptr_t>(context9) > UINT32_MAX);
    REQUIRE(reinterpret_cast<std::uintptr_t>(context23) > UINT32_MAX);
    REQUIRE(reinterpret_cast<std::uintptr_t>(context36) > UINT32_MAX);
    REQUIRE(heaps.OwnerOf(static_cast<char*>(context23) + 1) == EngineHeapDomain::None);
    REQUIRE(heaps.Size(reinterpret_cast<const void*>(std::uintptr_t(1))) == 0);
    std::memset(context23, 0x5a, 8192);
    // Both real target reservations are too small; the old block stays owned.
    REQUIRE(!heaps.Reallocate(context23, 0xd000000, 23));
    REQUIRE(heaps.OwnerOf(context23) == EngineHeapDomain::Context23);
    CheckPayload(context23, 8192, 0x5a);
    REQUIRE(!heaps.Reallocate(context23, (std::numeric_limits<std::size_t>::max)(), 36));
    REQUIRE(heaps.OwnerOf(context23) == EngineHeapDomain::Context23);
    CheckPayload(context23, 8192, 0x5a);
    auto* grown = heaps.Reallocate(context23, 16384, 36);
    REQUIRE(grown && heaps.OwnerOf(grown) == EngineHeapDomain::Main);
    CheckPayload(grown, 8192, 0x5a);
    REQUIRE(heaps.Size(context23) == 0);
    REQUIRE(heaps.Reallocate(grown, 0, 9) == nullptr);
    REQUIRE(heaps.Size(grown) == 0);
    const auto auxiliaryUsed = heaps.Statistics(EngineHeapDomain::Auxiliary).used;
    heaps.Deallocate(context9);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Auxiliary).used == auxiliaryUsed);
    heaps.Deallocate(context36);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).allocations == 0);
    for (int context = 0; context < 66; ++context) {
        auto* memory = heaps.Allocate(8192, context);
        const auto domain = context == 0 || context == 3 || context == 9 ? EngineHeapDomain::Auxiliary :
            context == 23 ? EngineHeapDomain::Context23 : EngineHeapDomain::Main;
        REQUIRE(memory && heaps.OwnerOf(memory) == domain);
        heaps.Deallocate(memory);
    }

    // Selected-heap exhaustion must use the genuine main arena, not CRT memory.
    auto* auxiliaryFallback = heaps.Allocate(0x200000, 9);
    REQUIRE(auxiliaryFallback && heaps.OwnerOf(auxiliaryFallback) == EngineHeapDomain::Main);
    heaps.Deallocate(auxiliaryFallback);
    auto* contextFallback = heaps.Allocate(0x4100000, 23);
    REQUIRE(contextFallback && heaps.OwnerOf(contextFallback) == EngineHeapDomain::Main);
    heaps.Deallocate(contextFallback);
    auto* growth = heaps.Allocate(0x5600000, 36);
    REQUIRE(growth);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).committed > 0x5500000);
    heaps.Deallocate(growth);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).committed == 0x5500000);

    // Actual C++ automatic owner cleanup on an exceptional exit. This exercises
    // only the heap supplier; it does not stand in for AutoMemContext or new.
    struct OwnedAllocation {
        EngineHeapSet& heaps;
        void* memory;
        ~OwnedAllocation() { heaps.Deallocate(memory); }
    };
    try {
        OwnedAllocation owner{heaps, heaps.Allocate(4096, 23)};
        REQUIRE(owner.memory);
        throw 7;
    } catch (int value) { REQUIRE(value == 7); }
    REQUIRE(heaps.Statistics(EngineHeapDomain::Context23).allocations == 0);

    std::barrier overlap(2);
    auto worker = [&](int context, EngineHeapDomain domain) {
        overlap.arrive_and_wait();
        for (int i = 0; i < 100; ++i) {
            auto* memory = heaps.Allocate(4096, context);
            REQUIRE(memory && heaps.OwnerOf(memory) == domain);
            std::memset(memory, context, 4096);
            CheckPayload(memory, 4096, static_cast<unsigned char>(context));
            heaps.Deallocate(memory);
        }
    };
    std::thread one(worker, 9, EngineHeapDomain::Auxiliary);
    std::thread two(worker, 23, EngineHeapDomain::Context23);
    one.join();
    two.join();
    REQUIRE(heaps.CheckIntegrity());
    REQUIRE(heaps.Statistics(EngineHeapDomain::Context23).allocations == 0);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Main).allocations == 0);
    heaps.Shutdown();
    REQUIRE(!heaps.IsInitialized());
    REQUIRE(heaps.OwnerOf(context9) == EngineHeapDomain::None);
    REQUIRE(heaps.Statistics(EngineHeapDomain::Auxiliary).reserved == 0);
    REQUIRE(heaps.CheckIntegrity());
    REQUIRE(heaps.Initialize());
    auto* zero = heaps.Allocate(0, 36);
    REQUIRE(zero && heaps.Size(zero) >= 8);
    heaps.Deallocate(zero);
    auto* invalidContext = heaps.Allocate(8192, -1);
    REQUIRE(invalidContext && heaps.OwnerOf(invalidContext) == EngineHeapDomain::Main);
    heaps.Deallocate(invalidContext);
}
}

int main()
{
    fnv::memory::VirtualRegion region;
    REQUIRE(!region.Reserve((std::numeric_limits<std::size_t>::max)(), 0));
    REQUIRE(region.Reserve(2 * fnv::memory::NativePageSize(), 0));
    REQUIRE(!region.CommitRange(1, fnv::memory::NativePageSize()));
    REQUIRE(!region.DecommitRange(0, 1));
    REQUIRE(region.Commit(fnv::memory::NativePageSize()));
    region.Trim(0);
    region.Release();
    fnv::memory::EngineLinearHeap linear;
    REQUIRE(linear.Initialize(2 * (alignof(std::max_align_t) + 16) - 1));
    auto* first = linear.Allocate(16);
    REQUIRE(first && linear.Size(first) == 16);
    REQUIRE(linear.Size(static_cast<char*>(first) + 1) == 0);
    REQUIRE(linear.Allocate(16) == nullptr);
    linear.Deallocate(first);
    REQUIRE(linear.Allocate(16) == nullptr);
    linear.Reset();
    REQUIRE(linear.Allocate(16) == first);
    CheckArena();
    CheckHeapSet();
}
