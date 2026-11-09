#include "fnv/decl/MemoryManager.h"
#include "fnv/tls.h"
#include "AutoMemContext.h"
#include "fnv/symbols_00401000.h"
#include "fnv/decl/FUN_00aa39c0_cls.h"
#include "fnv/memory/legacy_manager_startup.h"
#include "fnv/memory/palette_allocation.h"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>
#include <thread>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

using Domain = fnv::memory::EngineHeapDomain;

static void Bootstrap()
{
    MemoryManager owner;
    CHECK(!owner.HeapsInitialized());
    void* memory = owner.FUN_00aa3e40(8192);
    CHECK(memory && owner.Size(memory) == 8192);
    CHECK(owner.HeapOwner(memory) == Domain::None);
    std::memset(memory, 0x5a, 8192);
    owner.InitializeHeaps();
    CHECK(owner.HeapsInitialized());
    // Bootstrap storage retains its own allocation/release domain after init.
    CHECK(owner.Owns(memory));
    void* replacement = owner.Reallocate(memory, 16384u);
    CHECK(replacement && !owner.Owns(memory));
    CHECK(owner.HeapOwner(replacement) == Domain::None);
    CHECK(static_cast<unsigned char*>(replacement)[8191] == 0x5a);
    CHECK(!owner.ResizeOwned(replacement, std::numeric_limits<std::size_t>::max()));
    CHECK(owner.Owns(replacement));
    owner.FUN_00aa4060(replacement);
    CHECK(!owner.Owns(replacement));
    CHECK(!owner.AllocateBootstrap(std::numeric_limits<std::size_t>::max()));
}

static void Routing()
{
    MemoryManager owner;
    MemoryManager other;
    other.InitializeHeaps();
    owner.InitializeHeaps();
    owner.InitializeHeaps(); // Idempotent heap-only startup.
    CHECK(owner.HeapsInitialized());
    for (int context = 0; context < 66; ++context) {
        g_tlsBlock.memoryContext = context;
        void* memory = owner.FUN_00aa3e40(8192);
        CHECK(memory && owner.Size(memory) >= 8192);
        CHECK(reinterpret_cast<std::uintptr_t>(memory) > UINT32_MAX);
        const auto expected = context == 0 || context == 3 || context == 9
            ? Domain::Auxiliary : context == 23 ? Domain::Context23 : Domain::Main;
        CHECK(owner.HeapOwner(memory) == expected);
        CHECK(!other.Owns(memory));
        CHECK(!other.ReleaseOwned(memory));
        CHECK(!other.Reallocate(memory, 16384u));
        CHECK(!owner.Owns(static_cast<char*>(memory) + 1));
        CHECK(!owner.ReleaseOwned(static_cast<char*>(memory) + 1));
        owner.FUN_00aa4060(memory);
        // Genuine linear-heap individual release is deliberately a no-op.
        CHECK(owner.Owns(memory) == (expected == Domain::Auxiliary));
    }
    for (int context : {-1, 36, 66, 9999}) {
        g_tlsBlock.memoryContext = context;
        void* memory = owner.FUN_00aa3e40(8192);
        CHECK(memory && owner.HeapOwner(memory) == Domain::Main);
        owner.FUN_00aa4060(memory);
    }
    int foreign = 0;
    CHECK(owner.Size(&foreign) == 0);
    CHECK(!owner.ReleaseOwned(&foreign));
    CHECK(!owner.Reallocate(&foreign, 8192u));
    CHECK(!owner.FUN_00aa3e40(UINT32_MAX));
    CHECK(!owner.AllocateFromHeaps(std::numeric_limits<std::size_t>::max()));
    // Pools were not constructed by InitializeHeaps; do not fake their startup.
    CHECK(!owner.FUN_00aa3e40(16));
    owner.FUN_00aa4060(nullptr);
}

static void FixedPools()
{
    constexpr std::array<unsigned int, 37> blocks{
        8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 64, 72, 76,
        80, 92, 96, 100, 104, 120, 128, 160, 192, 200, 208, 240, 256,
        272, 288, 400, 448, 480, 508, 576, 596};
    constexpr std::array<std::size_t, 37> reserves{
        0x600000, 0x500000, 0x400000, 0x400000, 0x800000, 0x400000,
        0x800000, 0x300000, 0x200000, 0x400000, 0x200000, 0x300000,
        0x100000, 0x200000, 0xd00000, 0x100000, 0x300000, 0x200000,
        0xf00000, 0x100000, 0x400000, 0x400000, 0x100000, 0x200000,
        0x200000, 0x300000, 0x300000, 0x300000, 0x100000, 0x200000,
        0x300000, 0x100000, 0x100000, 0x400000, 0x400000, 0x200000,
        0x100000};
    constexpr std::array<const char*, 37> names{
        "Pool 8", "Pool 12", "Pool 16", "Pool 20", "Pool 24", "Pool 28",
        "Pool 32", "Pool 36", "Pool 40", "Pool 44", "Pool 48", "Pool 52",
        "Pool 56", "Pool 64", "Pool 72", "Pool 76", "Pool 80", "Pool 92",
        "Pool 96", "Pool 100", "Pool 104", "Pool 120", "Pool 128",
        "Pool 160", "Pool 192", "Pool 200", "Pool 208", "Pool 240",
        "Pool 256", "Pool 272", "Pool 288", "Pool 400", "Pool 448",
        "Pool 480", "Pool 508", "Pool 576", "Pool 596"};

    MemoryManager owner;
    try {
        owner.FUN_00866770();
        CHECK(false);
    } catch (const std::bad_alloc&) {}
    CHECK(!owner.PoolsInitialized());
    auto* bootstrap = owner.FUN_00aa3e40(0x60);
    CHECK(bootstrap && owner.Size(bootstrap) == 0x60);
    owner.FUN_00aa4060(bootstrap);
    owner.InitializeHeaps();
    CHECK(!owner.FUN_00aa3e40(0x60));
    g_tlsBlock.memoryContext = 36;
    char pool8[] = "Pool 8";
    owner.CreateMemoryPool(8, 0x600000, pool8);
    CHECK(!owner.PoolsInitialized() && !owner.FUN_00aa3e40(0x60));
    char pool16[] = "Pool 16";
    try {
        owner.CreateMemoryPool(16, 0x400000, pool16); // Pool 12 must be next.
        CHECK(false);
    } catch (const std::bad_alloc&) {}
    CHECK(GetTlsField() == 36 && !owner.PoolsInitialized());
    CHECK(owner.PoolStatistics(0).reservedBytes == 0);
    CHECK(!owner.FUN_00aa3e40(0x60));
    owner.FUN_00866770();
    owner.FUN_00866770(); // Published startup is idempotent.
    CHECK(owner.PoolsInitialized() && owner.PoolFamilyCount() == blocks.size());

    for (std::size_t family = 0; family < blocks.size(); ++family) {
        const auto initial = owner.PoolStatistics(family);
        CHECK(initial.name && std::strcmp(initial.name, names[family]) == 0);
        CHECK(initial.blockBytes == blocks[family]);
        CHECK(initial.reservedBytes == reserves[family]);
        CHECK(initial.capacityBlocks > 0 && initial.allocatedBlocks == 0);

        std::array<void*, 4> allocations{};
        for (auto& allocation : allocations) {
            allocation = owner.FUN_00aa3e40(blocks[family]);
            CHECK(allocation);
            CHECK(reinterpret_cast<std::uintptr_t>(allocation) > UINT32_MAX);
            CHECK(reinterpret_cast<std::uintptr_t>(allocation) % alignof(std::max_align_t) == 0);
            CHECK(owner.Size(allocation) == blocks[family]);
            CHECK(owner.PoolOwnerIndex(allocation) == family);
        }
        CHECK(owner.PoolStatistics(family).allocatedBlocks == allocations.size());
        CHECK(!owner.Owns(static_cast<char*>(allocations[0]) + 1));
        CHECK(!owner.ReleaseOwned(static_cast<char*>(allocations[0]) + 1));
        for (auto* allocation : allocations)
            owner.FUN_00aa4060(allocation);
        CHECK(owner.PoolStatistics(family).allocatedBlocks == 0);
        auto* reused = owner.FUN_00aa3e40(blocks[family]);
        CHECK(reused == allocations.back());
        owner.FUN_00aa4060(reused);
    }

    auto* zero = owner.FUN_00aa3e40(0);
    auto* one = owner.FUN_00aa3e40(1);
    auto* task = owner.FUN_00aa3e40(0x60);
    auto* filename = owner.FUN_00aa3e40(37);
    CHECK(zero && one && task && filename);
    CHECK(owner.Size(zero) == 8 && owner.Size(one) == 8);
    CHECK(owner.Size(task) == 96 && owner.Size(filename) == 40);
    owner.FUN_00aa4060(zero);
    owner.FUN_00aa4060(one);
    owner.FUN_00aa4060(task);
    owner.FUN_00aa4060(filename);

    // Exhaust the complete smallest-capacity family. Its next request follows
    // the source order into the selected heap, then released slots are reused.
    const std::size_t last = blocks.size() - 1;
    const auto lastStats = owner.PoolStatistics(last);
    std::array<void*, 2048> full{};
    CHECK(lastStats.capacityBlocks <= full.size());
    for (std::size_t index = 0; index < lastStats.capacityBlocks; ++index) {
        full[index] = owner.FUN_00aa3e40(blocks[last]);
        CHECK(full[index] && owner.PoolOwnerIndex(full[index]) == last);
    }
    auto* fallback = owner.FUN_00aa3e40(blocks[last]);
    CHECK(fallback && owner.PoolOwnerIndex(fallback) == owner.PoolFamilyCount());
    CHECK(owner.HeapOwner(fallback) == Domain::Main);
    owner.FUN_00aa4060(fallback);
    for (std::size_t index = 0; index < lastStats.capacityBlocks; ++index)
        owner.FUN_00aa4060(full[index]);
    auto* afterExhaustion = owner.FUN_00aa3e40(blocks[last]);
    CHECK(afterExhaustion == full[lastStats.capacityBlocks - 1]);
    owner.FUN_00aa4060(afterExhaustion);

    auto* resized = static_cast<unsigned char*>(owner.FUN_00aa3e40(16));
    CHECK(resized && owner.Size(resized) == 16);
    for (unsigned int index = 0; index < 16; ++index)
        resized[index] = static_cast<unsigned char>(index + 1);
    auto* shrunk = static_cast<unsigned char*>(owner.Reallocate(resized, 12));
    CHECK(shrunk && !owner.Owns(resized) && owner.Size(shrunk) == 12);
    for (unsigned int index = 0; index < 12; ++index)
        CHECK(shrunk[index] == index + 1);
    auto* grown = static_cast<unsigned char*>(owner.Reallocate(shrunk, 96));
    CHECK(grown && !owner.Owns(shrunk) && owner.Size(grown) == 96);
    for (unsigned int index = 0; index < 12; ++index)
        CHECK(grown[index] == index + 1);
    CHECK(!owner.ResizeOwned(grown, std::numeric_limits<std::size_t>::max()));
    CHECK(owner.Owns(grown) && grown[0] == 1 && grown[11] == 12);
    auto* heapReplacement = static_cast<unsigned char*>(owner.Reallocate(grown, 1024));
    CHECK(heapReplacement && owner.HeapOwner(heapReplacement) == Domain::Main);
    CHECK(heapReplacement[0] == 1 && heapReplacement[11] == 12);
    owner.FUN_00aa4060(heapReplacement);

    MemoryManager other;
    other.InitializeHeaps();
    other.FUN_00866770();
    auto* foreign = owner.FUN_00aa3e40(80);
    CHECK(foreign && !other.Owns(foreign) && !other.ReleaseOwned(foreign));
    owner.FUN_00aa4060(foreign);

    for (int context : {9, 23, 36}) {
        g_tlsBlock.memoryContext = context;
        auto* allocation = owner.FUN_00aa3e40(0x60);
        CHECK(allocation && owner.Size(allocation) == 96);
        owner.FUN_00aa4060(allocation);
    }

    auto worker = [&owner](unsigned int bytes) {
        for (unsigned int iteration = 0; iteration < 1000; ++iteration) {
            auto* allocation = static_cast<unsigned char*>(owner.FUN_00aa3e40(bytes));
            CHECK(allocation && owner.Size(allocation) >= bytes);
            allocation[0] = static_cast<unsigned char>(iteration);
            owner.FUN_00aa4060(allocation);
        }
    };
    std::thread first(worker, 40);
    std::thread second(worker, 96);
    first.join();
    second.join();

    owner.ShutdownHeaps();
    CHECK(!owner.PoolsInitialized() && !owner.HeapsInitialized());
    owner.InitializeHeaps();
    CHECK(!owner.FUN_00aa3e40(0x60));
    owner.FUN_00866770();
    auto* retried = owner.FUN_00aa3e40(0x60);
    CHECK(retried && owner.Size(retried) == 96);
    owner.FUN_00aa4060(retried);

    try {
        MemoryManager local;
        local.InitializeHeaps();
        local.FUN_00866770();
        CHECK(local.FUN_00aa3e40(80));
        throw std::runtime_error("pool owner lifetime");
    } catch (const std::runtime_error&) {}
}

static void ResizeAndRetire()
{
    MemoryManager owner;
    owner.InitializeHeaps();
    g_tlsBlock.memoryContext = 23;
    auto* memory = static_cast<unsigned char*>(owner.FUN_00aa3e40(8192));
    CHECK(memory && owner.HeapOwner(memory) == Domain::Context23);
    std::memset(memory, 0x6b, 8192);
    CHECK(!owner.ResizeOwned(memory, std::numeric_limits<std::size_t>::max()));
    CHECK(owner.Size(memory) >= 8192 && memory[8191] == 0x6b);
    CHECK(!owner.Reallocate(nullptr, 16u));
    CHECK(!owner.Reallocate(memory, 16u));
    CHECK(owner.Owns(memory) && owner.HeapOwner(memory) == Domain::Context23);
    CHECK(memory[0] == 0x6b && memory[8191] == 0x6b);
    g_tlsBlock.memoryContext = 36;
    auto* replacement = static_cast<unsigned char*>(owner.Reallocate(memory, 16384u));
    CHECK(replacement && owner.HeapOwner(replacement) == Domain::Main);
    CHECK(!owner.Owns(memory) && replacement[8191] == 0x6b);
    CHECK(!owner.Reallocate(replacement, 0u));
    CHECK(!owner.Owns(replacement));
    void* fromNull = owner.Reallocate(nullptr, 8192u);
    CHECK(fromNull && owner.Owns(fromNull));
    owner.FUN_00aa4060(fromNull);
    owner.ShutdownHeaps();
    CHECK(!owner.HeapsInitialized());
    CHECK(!owner.Owns(fromNull));
    owner.InitializeHeaps();
    void* again = owner.FUN_00aa3e40(8192);
    CHECK(again && owner.HeapOwner(again) == Domain::Main);
    owner.FUN_00aa4060(again);
}

static void CapacityFailure()
{
    MemoryManager owner;
    owner.InitializeHeaps();
    fnv_00404f30::FUN_00404f30(36);
    auto* original = static_cast<unsigned char*>(owner.FUN_00aa3e40(8192));
    CHECK(original);
    original[0] = 0x31;
    original[8191] = 0x73;
    void* blocks[16]{};
    unsigned count = 0;
    while (count < 16) {
        void* memory = owner.FUN_00aa3e40(32u * 1024 * 1024);
        if (!memory)
            break;
        blocks[count++] = memory;
    }
    CHECK(count > 0 && count < 16); // Real main reservation exhaustion.
    CHECK(!owner.Reallocate(original, 16u * 1024 * 1024));
    CHECK(owner.Owns(original) && original[0] == 0x31 && original[8191] == 0x73);
    for (unsigned i = 0; i < count; ++i)
        owner.FUN_00aa4060(blocks[i]);
    auto* replacement = static_cast<unsigned char*>(owner.Reallocate(original, 16u * 1024 * 1024));
    CHECK(replacement && replacement[0] == 0x31 && replacement[8191] == 0x73);
    CHECK(!owner.Owns(original));
    owner.FUN_00aa4060(replacement);
}

static void Threaded()
{
    MemoryManager owner;
    owner.InitializeHeaps();
    auto worker = [&](int context, Domain domain) {
        CHECK(g_tlsBlock.memoryContext == 59); // Actual production TLS initializer.
        g_tlsBlock.memoryContext = context;
        for (int i = 0; i < 32; ++i) {
            auto* memory = static_cast<unsigned char*>(owner.FUN_00aa3e40(8192));
            CHECK(memory && owner.HeapOwner(memory) == domain);
            std::memset(memory, context, 8192);
            CHECK(memory[8191] == context);
            owner.FUN_00aa4060(memory);
        }
        CHECK(g_tlsBlock.memoryContext == context);
    };
    std::thread first(worker, 9, Domain::Auxiliary);
    std::thread second(worker, 23, Domain::Context23);
    first.join();
    second.join();
}

static void GuardRouting()
{
    MemoryManager owner;
    owner.InitializeHeaps();
    fnv_00404f30::FUN_00404f30(36);
    auto allocate = [&](Domain domain) {
        void* memory = owner.FUN_00aa3e40(8192);
        CHECK(memory && owner.HeapOwner(memory) == domain);
        owner.FUN_00aa4060(memory);
    };
    allocate(Domain::Main);
    {
        AutoMemContext outer(9);
        allocate(Domain::Auxiliary);
        {
            AutoMemContext inner(23);
            allocate(Domain::Context23);
            {
                AutoMemContext normal(36);
                allocate(Domain::Main);
            }
            CHECK(GetTlsField() == 23);
            allocate(Domain::Context23);
        }
        CHECK(GetTlsField() == 9);
        allocate(Domain::Auxiliary);
    }
    CHECK(GetTlsField() == 36);
    try {
        AutoMemContext exceptional(23);
        allocate(Domain::Context23);
        throw std::runtime_error("routing scope");
    } catch (const std::runtime_error&) {}
    CHECK(GetTlsField() == 36);
    allocate(Domain::Main);
    auto earlyReturn = [&] {
        AutoMemContext early(9);
        allocate(Domain::Auxiliary);
        return;
    };
    earlyReturn();
    CHECK(GetTlsField() == 36);
    allocate(Domain::Main);
}

static void Unwind()
{
    try {
        MemoryManager owner;
        CHECK(owner.FUN_00aa3e40(8192));
        owner.InitializeHeaps();
        g_tlsBlock.memoryContext = 36;
        CHECK(owner.FUN_00aa3e40(8192));
        // The real owner's destructor retires outstanding backing allocations.
        throw std::runtime_error("owner lifetime");
    } catch (const std::runtime_error&) {}
}

static void ProductionBinding()
{
    auto* owner = FUN_00401020();
    CHECK(owner == &g_memoryManager);
    CHECK(!owner->HeapsInitialized());
    auto* bootstrap = FUN_00401000(8192);
    CHECK(bootstrap && owner->Size(bootstrap) == 8192);
    std::memset(bootstrap, 0x35, 8192);
    fnv_00404f30::FUN_00404f30(36);

    auto rejectStartup = [&] {
        try {
            FUN_00aa3880 startup;
            CHECK(false);
        } catch (const fnv::memory::MemoryManagerStartupUnavailable&) {}
        FUN_00aa39c0_cls adapter;
        try {
            adapter.FUN_00aa39c0();
            CHECK(false);
        } catch (const fnv::memory::MemoryManagerStartupUnavailable&) {}
        CHECK(FUN_00401020() == owner);
        CHECK(GetTlsField() == 36); // Failed startup never clears typed TLS.
        CHECK(owner->Owns(bootstrap));
        CHECK(static_cast<unsigned char*>(bootstrap)[8191] == 0x35);
    };
    rejectStartup();
    CHECK(!owner->HeapsInitialized());
    owner->InitializeHeaps(); // Actual admitted typed production init.
    CHECK(owner->HeapsInitialized());
    rejectStartup(); // Never writes the native owner's first byte, even now.
    CHECK(owner->HeapsInitialized());
    fnv::memory::ReleasePaletteAllocation(bootstrap);
    CHECK(!owner->Owns(bootstrap));

    for (int context : {9, 23, 36}) {
        AutoMemContext scope(context);
        auto* memory = FUN_00401000(8192);
        CHECK(memory && FUN_00401020()->Owns(memory));
        CHECK(reinterpret_cast<std::uintptr_t>(memory) > UINT32_MAX);
        const auto expected = context == 9 ? Domain::Auxiliary
            : context == 23 ? Domain::Context23 : Domain::Main;
        CHECK(owner->HeapOwner(memory) == expected);
        std::memset(memory, context, 8192);
        // The exact boundary used by all three changed NiPalette releases,
        // not a second provider or a direct local-owner test.
        fnv::memory::ReleasePaletteAllocation(memory);
        CHECK(owner->Owns(memory) == (expected == Domain::Auxiliary));
    }
    CHECK(!FUN_00401000(16)); // Pool route remains closed before fixed startup.
    owner->FUN_00866770();
    CHECK(owner->PoolsInitialized());
    auto* pooled = FUN_00401000(16);
    CHECK(pooled && owner->Size(pooled) == 16);
    FUN_00401030(pooled);
    auto* poolRangeFallback = FUN_00401000(0x3fc);
    CHECK(poolRangeFallback && owner->HeapOwner(poolRangeFallback) == Domain::Main);
    FUN_00401030(poolRangeFallback);
    auto* nonPool = FUN_00401000(0x400);
    CHECK(nonPool);
    FUN_00401030(nonPool);
    CHECK(!owner->Owns(nonPool));
    fnv::memory::ReleasePaletteAllocation(nullptr);
    owner->ShutdownHeaps(); // Detached bounded heap clients; not engine exit.
    CHECK(!owner->HeapsInitialized());
    owner->InitializeHeaps();
    auto* memory = FUN_00401000(8192);
    CHECK(memory);
    fnv::memory::ReleasePaletteAllocation(memory);
    owner->ShutdownHeaps();
}

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--reject-foreign-palette") == 0) {
        int foreign = 0;
        fnv::memory::ReleasePaletteAllocation(&foreign);
        CHECK(false);
    }
    FixedPools();
    ProductionBinding();
    Bootstrap();
    Routing();
    ResizeAndRetire();
    CapacityFailure();
    Threaded();
    GuardRouting();
    Unwind();
    std::puts("canonical heap-owned manager seam passed");
}
