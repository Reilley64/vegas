#include "fnv/decl/MemoryManager.h"
#include "fnv/tls.h"
#include "AutoMemContext.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
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

int main()
{
    Bootstrap();
    Routing();
    ResizeAndRetire();
    CapacityFailure();
    Threaded();
    GuardRouting();
    Unwind();
    std::puts("canonical heap-owned manager seam passed");
}
