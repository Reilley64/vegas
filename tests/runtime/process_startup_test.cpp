// Runs fnv::memory::StartProcessMemory, the function main runs, and then the
// production entries through what it established: the Ni allocation entries
// 0x00aa13e0 and 0x00aa1460 and the replaceable global new and delete. Nothing
// here starts a heap, a pool or the allocator itself, and no global is set by
// hand except the thread's allocation context. Checks stay active under NDEBUG.
#include "AutoMemContext.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/memory/process_startup.h"
#include "fnv/ni_allocator.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/tls.h"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

using Domain = fnv::memory::EngineHeapDomain;

namespace
{
// Takes address space from the operating system until no free range is as
// large as 128 MB, so the system itself refuses the manager's 200 MB main
// reservation. Nothing is committed, and smaller ranges stay free.
struct AddressSpaceHold
{
    static constexpr std::size_t Limit = 8192;
    static constexpr std::size_t Smallest = std::size_t{1} << 27;
    void* base[Limit];
    std::size_t bytes[Limit];
    std::size_t count = 0;

    static void* Reserve(std::size_t size)
    {
#ifdef _WIN32
        return VirtualAlloc(nullptr, size, MEM_RESERVE, PAGE_NOACCESS);
#else
        void* memory = mmap(nullptr, size, PROT_NONE, MAP_PRIVATE | MAP_ANON, -1, 0);
        return memory == MAP_FAILED ? nullptr : memory;
#endif
    }

    void Take()
    {
        for (std::size_t size = std::size_t{1} << 44; size >= Smallest; size >>= 1) {
            while (count < Limit) {
                void* memory = Reserve(size);
                if (!memory)
                    break;
                base[count] = memory;
                bytes[count] = size;
                ++count;
            }
        }
        CHECK(count < Limit);
        CHECK(Reserve(Smallest) == nullptr);
    }

    void Release()
    {
        while (count) {
            --count;
#ifdef _WIN32
            VirtualFree(base[count], 0, MEM_RELEASE);
#else
            munmap(base[count], bytes[count]);
#endif
        }
    }
};
AddressSpaceHold s_hold;

NiInitOptions* PublishedOptions()
{
    return static_cast<NiInitOptions*>(DAT_011f6118);
}

bool AllZero(const void* memory, std::size_t bytes)
{
    const auto* cursor = static_cast<const unsigned char*>(memory);
    for (std::size_t index = 0; index < bytes; ++index)
        if (cursor[index] != 0)
            return false;
    return true;
}

void NothingStarted()
{
    CHECK(!fnv::memory::ProcessMemoryStarted());
    CHECK(!g_memoryManager.HeapsInitialized());
    CHECK(!g_memoryManager.PoolsInitialized());
    CHECK(DAT_011f6080 == nullptr && DAT_011f6118 == nullptr);
    CHECK(FUN_00aa13e0(64) == nullptr);
}

// Every stage is up, in the state the recorded order leaves.
void Started()
{
    CHECK(fnv::memory::ProcessMemoryStarted());
    CHECK(g_memoryManager.HeapsInitialized());
    CHECK(g_memoryManager.PoolsInitialized());
    CHECK(g_tlsBlock.memoryContext == 0);
    NiInitOptions* options = PublishedOptions();
    CHECK(options && options->allocator && !options->ownsAllocator);
    CHECK(dynamic_cast<BSNiAllocator*>(options->allocator) != nullptr);
    CHECK(DAT_011f6080 && DAT_011f6080->allocator == options->allocator);
    // Publication came after the pools: its three objects are pool blocks.
    for (const void* object : {static_cast<const void*>(options), static_cast<const void*>(options->allocator),
                               static_cast<const void*>(DAT_011f6080)})
        CHECK(g_memoryManager.PoolOwnerIndex(object) < g_memoryManager.PoolFamilyCount());
    // The options 0x00aa20b0 would keep are the published ones.
    CHECK(fnv::memory::RequirePublishedNiOptions() == options);
}

struct Counted
{
    static int live;
    unsigned char payload[0x60];
    Counted() { ++live; std::memset(payload, 0x3c, sizeof(payload)); }
    ~Counted() { --live; }
};
int Counted::live;

void AllocateAndFree()
{
    for (std::size_t request : {std::size_t{0}, std::size_t{1}, std::size_t{16}, std::size_t{0xc4},
                                std::size_t{0x3f0}}) {
        const std::size_t bytes = request ? request : 1;
        for (int round = 0; round < 2; ++round) {
            auto* memory = static_cast<unsigned char*>(FUN_00aa13e0(request));
            CHECK(memory && AllZero(memory, bytes));
            CHECK(reinterpret_cast<std::uintptr_t>(memory) % alignof(std::max_align_t) == 0);
            CHECK(g_memoryManager.Size(memory) >= bytes);
            std::memset(memory, 0xa5, bytes);
            // Startup leaves this thread in context 0, whose heap is the linear
            // one: a size with no pool family lands there and stays owned.
            const bool linear = g_memoryManager.HeapOwner(memory) == Domain::Auxiliary;
            CHECK(linear == (request == 0x3f0));
            FUN_00aa1460(memory, static_cast<unsigned int>(bytes));
            CHECK(g_memoryManager.Owns(memory) == linear);
        }
    }
    for (int context : {9, 23, 36}) {
        AutoMemContext scope(context);
        const auto expected = context == 9 ? Domain::Auxiliary
            : context == 23 ? Domain::Context23 : Domain::Main;
        auto* memory = static_cast<unsigned char*>(FUN_00aa13e0(8192));
        CHECK(memory && AllZero(memory, 8192));
        CHECK(g_memoryManager.HeapOwner(memory) == expected);
        FUN_00aa1460(memory, 8192);
        // The linear heap releases collectively, not per block.
        CHECK(g_memoryManager.Owns(memory) == (expected == Domain::Auxiliary));

        auto* array = new unsigned char[8192];
        CHECK(g_memoryManager.HeapOwner(array) == expected);
        delete[] array;
        CHECK(g_memoryManager.Owns(array) == (expected == Domain::Auxiliary));
    }
    CHECK(g_tlsBlock.memoryContext == 0);

    const int liveBefore = Counted::live;
    auto* object = new Counted;
    CHECK(Counted::live == liveBefore + 1);
    CHECK(g_memoryManager.PoolOwnerIndex(object) < g_memoryManager.PoolFamilyCount());
    CHECK(object->payload[0x5f] == 0x3c);
    delete object;
    CHECK(Counted::live == liveBefore && !g_memoryManager.Owns(object));

    auto* large = new unsigned char[0x10000];
    CHECK(g_memoryManager.HeapOwner(large) == Domain::Auxiliary); // Context 0.
    delete[] large;
    {
        AutoMemContext scope(36);
        large = new unsigned char[0x10000];
        CHECK(g_memoryManager.HeapOwner(large) == Domain::Main);
        std::memset(large, 0x7e, 0x10000);
        delete[] large;
        CHECK(!g_memoryManager.Owns(large));
    }
}
}

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--ni-startup-unpublished") == 0) {
        std::fprintf(stderr, "ni-startup-unpublished\n");
        fnv::memory::RequirePublishedNiOptions();
        return 0;
    }

    const int initialContext = g_tlsBlock.memoryContext;
    CHECK(initialContext == 59);
    NothingStarted();
    // Allocated before startup: a bootstrap block, as a static initializer's is.
    auto* early = new Counted;
    CHECK(g_memoryManager.Owns(early) && g_memoryManager.HeapOwner(early) == Domain::None);

    // The operating system refuses the heap reservation.
    s_hold.Take();
    const bool refused = !fnv::memory::StartProcessMemory();
    const bool repeatedRefusal = !fnv::memory::StartProcessMemory();
    s_hold.Release();
    CHECK(refused && repeatedRefusal);
    NothingStarted();
    CHECK(g_tlsBlock.memoryContext == initialContext);
    CHECK(g_memoryManager.Owns(early) && early->payload[0] == 0x3c);

    // The same call succeeds once the reservation is available.
    CHECK(fnv::memory::StartProcessMemory());
    Started();
    CHECK(g_memoryManager.Owns(early) && g_memoryManager.HeapOwner(early) == Domain::None);
    CHECK(early->payload[0x5f] == 0x3c);

    // A second startup changes nothing.
    HolderB3718* holder = DAT_011f6080;
    NiInitOptions* options = PublishedOptions();
    NiAllocator* allocator = options->allocator;
    void* held = FUN_00aa13e0(0xc4);
    CHECK(held);
    g_tlsBlock.memoryContext = 36;
    CHECK(fnv::memory::StartProcessMemory());
    CHECK(g_tlsBlock.memoryContext == 36);
    g_tlsBlock.memoryContext = 0;
    Started();
    CHECK(DAT_011f6080 == holder && PublishedOptions() == options && options->allocator == allocator);
    CHECK(g_memoryManager.Owns(held));
    FUN_00aa1460(held, 0xc4);

    AllocateAndFree();
    delete early;
    CHECK(Counted::live == 0 && !g_memoryManager.Owns(early));

    // Ordered retirement with every client detached. The holder, the options
    // and the allocator go back into the manager while it still owns them (a
    // release after the pools or heaps were gone would terminate), then the
    // pools and the heaps go.
    fnv::memory::RetireProcessMemory();
    NothingStarted();
    CHECK(!g_memoryManager.Owns(holder) && !g_memoryManager.Owns(options) && !g_memoryManager.Owns(allocator));
    FUN_00aa1460(nullptr, 0);
    fnv::memory::RetireProcessMemory(); // Nothing left to retire.
    NothingStarted();

    // Startup after retirement is a complete startup again.
    g_tlsBlock.memoryContext = initialContext;
    CHECK(fnv::memory::StartProcessMemory());
    Started();
    AllocateAndFree();
    // Left started, as main leaves it: the manager serves until the process ends.
    return 0;
}
