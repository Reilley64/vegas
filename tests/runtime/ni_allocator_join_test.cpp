// Runs the production entries only: the manager's heap and fixed-pool startup,
// the allocator publication step of 0x00866690, the holder's writer 0x00aa2020,
// and the allocation entries 0x00aa13e0 and 0x00aa1460. Every allocator, options
// and holder object here is constructed by those entries. Checks stay active
// under NDEBUG.
#include "AutoMemContext.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/ni_allocator.h"
#include "fnv/symbols_00aa1000.h"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <new>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

using Domain = fnv::memory::EngineHeapDomain;

static bool AllZero(const void* memory, std::size_t bytes)
{
    const auto* cursor = static_cast<const unsigned char*>(memory);
    for (std::size_t index = 0; index < bytes; ++index)
        if (cursor[index] != 0)
            return false;
    return true;
}

static bool Aligned(const void* memory, std::size_t alignment)
{
    return reinterpret_cast<std::uintptr_t>(memory) % alignment == 0;
}

static NiInitOptions* PublishedOptions()
{
    return static_cast<NiInitOptions*>(DAT_011f6118);
}

// Nothing is published before the manager startup step runs.
static void Unpublished()
{
    CHECK(DAT_011f6080 == nullptr);
    CHECK(DAT_011f6118 == nullptr);
    CHECK(FUN_00aa13e0(64) == nullptr);
    FUN_00aa1460(nullptr, 64);
    InitHolder(); // No options: the writer publishes nothing.
    CHECK(DAT_011f6080 == nullptr);
    CHECK(FUN_00aa13e0(64) == nullptr);
}

static void Startup()
{
    g_memoryManager.InitializeHeaps();
    // Fixed pools are not started, so the manager cannot supply the objects.
    try {
        fnv::memory::PublishManagerNiAllocator();
        CHECK(false);
    } catch (const std::bad_alloc&) {}
    CHECK(DAT_011f6080 == nullptr);
    CHECK(DAT_011f6118 == nullptr);
    CHECK(FUN_00aa13e0(64) == nullptr);

    g_memoryManager.FUN_00866770();
    fnv::memory::PublishManagerNiAllocator();

    auto* options = PublishedOptions();
    CHECK(options && options->allocator && !options->ownsAllocator);
    CHECK(dynamic_cast<BSNiAllocator*>(options->allocator) != nullptr);
    CHECK(DAT_011f6080 && DAT_011f6080->allocator == options->allocator);
    CHECK(g_memoryManager.Owns(options));
    CHECK(g_memoryManager.Owns(options->allocator));
    CHECK(g_memoryManager.Owns(DAT_011f6080));
}

// 0x00aa13e0 then 0x00aa1460, with the block's bytes dirtied before release so
// a reused block proves the zero fill.
static void AllocateAndFree()
{
    const std::size_t pooled[] = {0, 1, 4, 16, 0xc4, 0xd8, 0x3f0};
    for (std::size_t request : pooled) {
        const std::size_t bytes = request ? request : 1;
        for (int round = 0; round < 2; ++round) {
            auto* memory = static_cast<unsigned char*>(FUN_00aa13e0(request));
            CHECK(memory);
            CHECK(AllZero(memory, bytes));
            CHECK(Aligned(memory, alignof(std::max_align_t)));
            CHECK(g_memoryManager.Size(memory) >= bytes);
            // A size with no fixed family falls through to the default heap.
            CHECK(g_memoryManager.PoolOwnerIndex(memory) < g_memoryManager.PoolFamilyCount() ||
                  g_memoryManager.HeapOwner(memory) == Domain::Main);
            std::memset(memory, 0xa5, bytes);
            FUN_00aa1460(memory, static_cast<unsigned int>(bytes));
            CHECK(!g_memoryManager.Owns(memory));
        }
    }
    for (int context : {9, 23, 36}) {
        AutoMemContext scope(context);
        const auto expected = context == 9 ? Domain::Auxiliary
            : context == 23 ? Domain::Context23 : Domain::Main;
        for (std::size_t bytes : {std::size_t{0x400}, std::size_t{8192}}) {
            for (int round = 0; round < 2; ++round) {
                auto* memory = static_cast<unsigned char*>(FUN_00aa13e0(bytes));
                CHECK(memory);
                CHECK(AllZero(memory, bytes));
                CHECK(Aligned(memory, alignof(std::max_align_t)));
                CHECK(g_memoryManager.HeapOwner(memory) == expected);
                CHECK(g_memoryManager.PoolOwnerIndex(memory) == g_memoryManager.PoolFamilyCount());
                std::memset(memory, 0xa5, bytes);
                FUN_00aa1460(memory, static_cast<unsigned int>(bytes));
                // The linear heap releases collectively, not per block.
                CHECK(g_memoryManager.Owns(memory) == (expected == Domain::Auxiliary));
            }
        }
    }
}

static void AllocationFailure()
{
    // Outside the manager's arena boundary.
    CHECK(FUN_00aa13e0(0x80000000u) == nullptr);
    CHECK(FUN_00aa13e0(std::numeric_limits<unsigned int>::max()) == nullptr);
    // Outside the allocator's unsigned boundary: never narrowed.
    CHECK(FUN_00aa13e0(std::size_t{std::numeric_limits<unsigned int>::max()} + 1) == nullptr);
    CHECK(FUN_00aa13e0(std::size_t{std::numeric_limits<unsigned int>::max()} + 65) == nullptr);
    CHECK(FUN_00aa13e0(std::numeric_limits<std::size_t>::max()) == nullptr);
    // A failed request leaves the route usable.
    auto* memory = FUN_00aa13e0(0xc4);
    CHECK(memory && AllZero(memory, 0xc4));
    FUN_00aa1460(memory, 0xc4);
}

// The published object's own interface, as the entries not converted in this
// increment reach it: the aligned events of both families and their failures.
static void PublishedInterface()
{
    NiAllocator* allocator = DAT_011f6080->allocator;
    struct Family {
        int allocate, alignedAllocate, release, alignedRelease;
        bool second;
    };
    const Family families[] = {{5, 7, 9, 10, false}, {0xb, 0xd, 0xf, 0x10, true}};
    for (const auto& family : families) {
        auto allocate = [&](unsigned int& size, unsigned int& alignment, int event) {
            return static_cast<unsigned char*>(family.second
                ? allocator->Alloc(size, alignment, event, false, nullptr, -1, nullptr)
                : allocator->Allocate(size, alignment, event, false, nullptr, -1, nullptr));
        };
        auto release = [&](void* memory, int event) {
            if (family.second)
                allocator->Free(memory, event, static_cast<unsigned int>(-1));
            else
                allocator->Deallocate(memory, event, static_cast<unsigned int>(-1));
        };
        for (unsigned int alignmentBytes : {4u, 16u, 64u}) {
            for (unsigned int bytes : {100u, 5000u}) {
                unsigned int size = bytes;
                unsigned int alignment = alignmentBytes;
                auto* memory = allocate(size, alignment, family.alignedAllocate);
                CHECK(memory && size == bytes && alignment == alignmentBytes);
                CHECK(Aligned(memory, alignmentBytes));
                CHECK(AllZero(memory, bytes));
                const unsigned char offset = memory[-1];
                CHECK(offset >= 1 && offset <= alignmentBytes);
                CHECK(g_memoryManager.Owns(memory - offset));
                std::memset(memory, 0x5a, bytes);
                release(memory, family.alignedRelease);
                CHECK(!g_memoryManager.Owns(memory - offset));
            }
        }
        unsigned int size = 300;
        unsigned int alignment = 4;
        auto* plain = allocate(size, alignment, family.allocate);
        CHECK(plain && AllZero(plain, 300) && g_memoryManager.Owns(plain));
        release(plain, family.release);
        CHECK(!g_memoryManager.Owns(plain));
        release(nullptr, family.alignedRelease);

        size = 0x80000000u;
        alignment = 16;
        CHECK(allocate(size, alignment, family.alignedAllocate) == nullptr);
        CHECK(allocate(size, alignment, family.allocate) == nullptr);
        size = std::numeric_limits<unsigned int>::max() - 3; // Size plus alignment would wrap.
        CHECK(allocate(size, alignment, family.alignedAllocate) == nullptr);
    }

    // Aligned reallocation keeps the payload and the offset byte.
    unsigned int size = 100;
    unsigned int alignment = 16;
    auto* memory = static_cast<unsigned char*>(
        allocator->Allocate(size, alignment, 7, false, nullptr, -1, nullptr));
    CHECK(memory);
    for (unsigned int index = 0; index < 100; ++index)
        memory[index] = static_cast<unsigned char>(index);
    size = 5000;
    auto* grown = static_cast<unsigned char*>(allocator->Reallocate(
        memory, size, alignment, 8, false, static_cast<unsigned int>(-1), nullptr, -1, nullptr));
    CHECK(grown && Aligned(grown, 16));
    for (unsigned int index = 0; index < 100; ++index)
        CHECK(grown[index] == static_cast<unsigned char>(index));
    CHECK(g_memoryManager.Owns(grown - grown[-1]));
    size = 0x80000000u;
    CHECK(allocator->Reallocate(grown, size, alignment, 8, false, 5000, nullptr, -1, nullptr) == nullptr);
    CHECK(g_memoryManager.Owns(grown - grown[-1])); // A failed replacement keeps the block.
    allocator->Deallocate(grown, 10, static_cast<unsigned int>(-1));

    // The same through slot 6 with its aligned event, 14.
    size = 100;
    memory = static_cast<unsigned char*>(allocator->Alloc(size, alignment, 0xd, false, nullptr, -1, nullptr));
    CHECK(memory);
    for (unsigned int index = 0; index < 100; ++index)
        memory[index] = static_cast<unsigned char>(index);
    size = 5000;
    grown = static_cast<unsigned char*>(allocator->Realloc(
        memory, size, alignment, 14, false, static_cast<unsigned int>(-1), nullptr, -1, nullptr));
    CHECK(grown && Aligned(grown, 16) && size == 5000 && alignment == 16);
    CHECK(grown[-1] >= 1 && grown[-1] <= 16);
    for (unsigned int index = 0; index < 100; ++index)
        CHECK(grown[index] == static_cast<unsigned char>(index));
    CHECK(g_memoryManager.Owns(grown - grown[-1]));
    CHECK(g_memoryManager.Size(grown - grown[-1]) >= 5016);
    size = 0x80000000u;
    CHECK(allocator->Realloc(grown, size, alignment, 14, false, 5000, nullptr, -1, nullptr) == nullptr);
    CHECK(g_memoryManager.Owns(grown - grown[-1]));
    size = 5000;
    CHECK(allocator->Realloc(nullptr, size, alignment, 14, false, 0, nullptr, -1, nullptr) == nullptr);
    allocator->Free(grown, 0x10, static_cast<unsigned int>(-1));
    CHECK(!g_memoryManager.Owns(grown - grown[-1]));
}

// The non-aligned events of slots 3 and 6 reach 0x00aa4200: 0xc is the event
// 0x00aa11b0 passes. The replacement is checked before the copy, and a block
// the manager does not own is refused, never handed to the CRT.
static void PlainReallocation()
{
    NiAllocator* allocator = DAT_011f6080->allocator;
    for (bool second : {false, true}) {
        auto reallocate = [&](void* block, unsigned int bytes) {
            unsigned int size = bytes;
            unsigned int alignment = 4;
            return static_cast<unsigned char*>(second
                ? allocator->Realloc(block, size, alignment, 0xc, false, static_cast<unsigned int>(-1),
                                     nullptr, -1, nullptr)
                : allocator->Reallocate(block, size, alignment, 0xc, false, static_cast<unsigned int>(-1),
                                        nullptr, -1, nullptr));
        };
        auto* memory = static_cast<unsigned char*>(FUN_00aa13e0(100));
        CHECK(memory);
        for (unsigned int index = 0; index < 100; ++index)
            memory[index] = static_cast<unsigned char>(index + 1);
        // Pool to heap.
        auto* grown = reallocate(memory, 5000);
        CHECK(grown && grown != memory);
        CHECK(!g_memoryManager.Owns(memory));
        CHECK(g_memoryManager.HeapOwner(grown) == Domain::Main && g_memoryManager.Size(grown) >= 5000);
        for (unsigned int index = 0; index < 100; ++index)
            CHECK(grown[index] == static_cast<unsigned char>(index + 1));
        // Heap to pool: only the new size is copied.
        auto* shrunk = reallocate(grown, 40);
        CHECK(shrunk && !g_memoryManager.Owns(grown));
        CHECK(g_memoryManager.PoolOwnerIndex(shrunk) < g_memoryManager.PoolFamilyCount());
        for (unsigned int index = 0; index < 40; ++index)
            CHECK(shrunk[index] == static_cast<unsigned char>(index + 1));
        // A refused replacement keeps the block and its bytes.
        CHECK(reallocate(shrunk, 0x80000000u) == nullptr);
        CHECK(g_memoryManager.Owns(shrunk));
        for (unsigned int index = 0; index < 40; ++index)
            CHECK(shrunk[index] == static_cast<unsigned char>(index + 1));
        // Blocks the manager does not own: null, an interior address, the
        // stack and a CRT block. None is replaced, moved or released.
        CHECK(reallocate(nullptr, 64) == nullptr);
        CHECK(reallocate(shrunk + 8, 64) == nullptr);
        CHECK(g_memoryManager.Owns(shrunk) && shrunk[8] == 9);
        unsigned char local[16] = {0x11};
        CHECK(reallocate(local, 64) == nullptr && local[0] == 0x11);
        auto* foreign = static_cast<unsigned char*>(std::malloc(16));
        CHECK(foreign);
        foreign[0] = 0x22;
        CHECK(reallocate(foreign, 64) == nullptr && foreign[0] == 0x22);
        std::free(foreign);
        FUN_00aa1460(shrunk, 40);
        CHECK(!g_memoryManager.Owns(shrunk));
    }
}

// 0x00aa13e0 serves a zero size as a one-byte request: the same pool family
// and capacity, a zeroed first byte, and a block that frees normally. The
// manager also rounds a zero size up to its smallest family, and a released
// pool block's first bytes hold the pool's free links, so a request passed
// through as zero is not separable from this by behaviour.
static void ZeroSizeDefault()
{
    auto* one = static_cast<unsigned char*>(FUN_00aa13e0(1));
    CHECK(one);
    const auto family = g_memoryManager.PoolOwnerIndex(one);
    CHECK(family < g_memoryManager.PoolFamilyCount());
    const auto capacity = g_memoryManager.Size(one);
    std::memset(one, 0xa5, capacity);
    for (int round = 0; round < 2; ++round) {
        auto* zero = static_cast<unsigned char*>(FUN_00aa13e0(0));
        CHECK(zero && zero != one);
        CHECK(g_memoryManager.PoolOwnerIndex(zero) == family && g_memoryManager.Size(zero) == capacity);
        CHECK(zero[0] == 0);
        std::memset(zero, 0xa5, capacity);
        FUN_00aa1460(zero, 0);
        CHECK(!g_memoryManager.Owns(zero));
    }
    CHECK(one[0] == 0xa5);
    FUN_00aa1460(one, 1);
}

// 0x00aa13e0 and 0x00aa1460 use the plain events (1 and 3), not the aligned
// ones. The allocation returns the manager's own block start, which an aligned
// allocation never does, and the free releases exactly the address it is
// given. The allocator treats every plain free event alike, so the literal 3
// is not separable from 4 or 9 by behaviour; --free-aligned-block shows the
// event is not the aligned one.
static void PlainEvents()
{
    NiAllocator* allocator = DAT_011f6080->allocator;
    auto* plain = static_cast<unsigned char*>(FUN_00aa13e0(300));
    CHECK(plain && g_memoryManager.Owns(plain));
    unsigned int size = 300;
    unsigned int alignment = 16;
    auto* aligned = static_cast<unsigned char*>(
        allocator->Allocate(size, alignment, 7, false, nullptr, -1, nullptr));
    CHECK(aligned && !g_memoryManager.Owns(aligned) && g_memoryManager.Owns(aligned - aligned[-1]));
    // An aligned free of the plain block would step back by plain[-1] first.
    FUN_00aa1460(plain, 300);
    CHECK(!g_memoryManager.Owns(plain));
    allocator->Deallocate(aligned, 10, static_cast<unsigned int>(-1));
}

// Startup publishes twice in the recorded order: 0x00866690 and then 0x00aa3050
// both call the writer. A second run of the startup step is also defined.
static void DoublePublication()
{
    HolderB3718* firstHolder = DAT_011f6080;
    NiInitOptions* firstOptions = PublishedOptions();
    NiAllocator* firstAllocator = firstOptions->allocator;
    void* early = FUN_00aa13e0(0xc4);
    CHECK(early);

    InitHolder();
    HolderB3718* secondHolder = DAT_011f6080;
    CHECK(secondHolder && secondHolder != firstHolder);
    CHECK(secondHolder->allocator == firstAllocator);
    CHECK(PublishedOptions() == firstOptions);
    // The earlier holder is never retired.
    CHECK(g_memoryManager.Owns(firstHolder) && firstHolder->allocator == firstAllocator);
    void* middle = FUN_00aa13e0(8192);
    CHECK(middle && AllZero(middle, 8192));

    fnv::memory::PublishManagerNiAllocator();
    NiInitOptions* secondOptions = PublishedOptions();
    CHECK(secondOptions != firstOptions && !secondOptions->ownsAllocator);
    CHECK(secondOptions->allocator != firstAllocator);
    CHECK(dynamic_cast<BSNiAllocator*>(secondOptions->allocator) != nullptr);
    CHECK(DAT_011f6080 != secondHolder && DAT_011f6080->allocator == secondOptions->allocator);
    // The earlier objects stay live, and blocks from them release into the
    // same manager through the current holder.
    CHECK(g_memoryManager.Owns(firstOptions) && g_memoryManager.Owns(firstAllocator));
    CHECK(dynamic_cast<BSNiAllocator*>(firstAllocator) != nullptr);
    FUN_00aa1460(early, 0xc4);
    FUN_00aa1460(middle, 8192);
    CHECK(!g_memoryManager.Owns(early) && !g_memoryManager.Owns(middle));
}

// The recorded shutdown 0x00aa2170 destroys the options (0x00aa21e0) and then
// frees them through the manager, and only options made by 0x00aa2200 own
// their allocator. Options that name the Bethesda allocator never own it, so
// retiring them leaves the allocator and the holder serving.
static void Retirement()
{
    NiAllocator* allocator = DAT_011f6080->allocator;
    void* before = FUN_00aa13e0(0xc4);
    CHECK(before);

    void* storage = g_memoryManager.FUN_00aa3e40(sizeof(NiInitOptions));
    CHECK(storage);
    auto* options = new (storage) NiInitOptions(allocator);
    CHECK(options->allocator == allocator && !options->ownsAllocator);
    options->~NiInitOptions();
    g_memoryManager.FUN_00aa4060(storage);
    CHECK(!g_memoryManager.Owns(storage));

    CHECK(g_memoryManager.Owns(allocator));
    CHECK(dynamic_cast<BSNiAllocator*>(allocator) != nullptr);
    CHECK(DAT_011f6080->allocator == allocator);
    FUN_00aa1460(before, 0xc4);
    CHECK(!g_memoryManager.Owns(before));
    void* after = FUN_00aa13e0(0xc4);
    CHECK(after && AllZero(after, 0xc4));
    FUN_00aa1460(after, 0xc4);
}

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--free-without-holder") == 0) {
        int block = 0;
        std::fprintf(stderr, "free-without-holder\n");
        FUN_00aa1460(&block, sizeof(block));
        return 0;
    }
    if (argc == 2 && std::strcmp(argv[1], "--free-aligned-block") == 0) {
        // An aligned block's address is inside the manager's block. 0x00aa1460
        // frees with a plain event, so the manager sees an address it does not
        // own and terminates; an aligned event would have released the block.
        g_memoryManager.InitializeHeaps();
        g_memoryManager.FUN_00866770();
        fnv::memory::PublishManagerNiAllocator();
        unsigned int size = 300;
        unsigned int alignment = 16;
        void* aligned = DAT_011f6080->allocator->Allocate(size, alignment, 7, false, nullptr, -1, nullptr);
        CHECK(aligned);
        std::fprintf(stderr, "free-aligned-block\n");
        FUN_00aa1460(aligned, 300);
        return 0;
    }
    Unpublished();
    Startup();
    AllocateAndFree();
    AllocationFailure();
    PublishedInterface();
    PlainReallocation();
    ZeroSizeDefault();
    PlainEvents();
    DoublePublication();
    Retirement();
    return 0;
}
