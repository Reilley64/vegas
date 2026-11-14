#include "fnv/decl/MemoryManager.h"
#include "fnv/symbols_00401000.h"

#include <cstdio>
#include <cstdlib>
#include <new>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

namespace {
struct StaticAllocationClient {
    unsigned char* early = static_cast<unsigned char*>(::operator new(8192));
    unsigned char* heap = nullptr;

    StaticAllocationClient()
    {
        CHECK(FUN_00401020()->Owns(early));
        early[8191] = 0x57;
    }

    ~StaticAllocationClient()
    {
        auto* owner = FUN_00401020();
        CHECK(early[8191] == 0x57 && owner->Owns(early));
        CHECK(heap && heap[8191] == 0x63 && owner->Owns(heap));
        ::operator delete(early);
        ::operator delete(heap);
        CHECK(!owner->Owns(early) && !owner->Owns(heap));
        // Matching delete and a fresh allocation must still have live metadata,
        // heaps and mutexes even if the manager TU has already finalized.
        void* last = ::operator new(8192);
        CHECK(owner->Owns(last));
        ::operator delete(last);
        CHECK(!owner->Owns(last));
        std::puts("static allocation client retired safely");
    }
};
StaticAllocationClient client;
}

void VerifyManagerStaticClient()
{
    CHECK(client.early[8191] == 0x57);
    CHECK(FUN_00401020()->Size(client.early) == 8192);
}

void RetainManagerStaticHeapAllocation()
{
    CHECK(!client.heap);
    client.heap = static_cast<unsigned char*>(::operator new(8192));
    CHECK(FUN_00401020()->HeapOwner(client.heap) == fnv::memory::EngineHeapDomain::Main);
    client.heap[8191] = 0x63;
}
