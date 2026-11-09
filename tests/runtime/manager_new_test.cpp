#include "fnv/decl/MemoryManager.h"
#include "fnv/symbols_00401000.h"
#include "fnv/tls.h"

#include <cstdio>
#include <cstdlib>
#include <limits>
#include <new>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

// A different TU's dynamic initialization calls actual global new before main.
// The constinit manager must already have its complete native lifetime.
static void* early = ::operator new(8192);
static void* failedConstruction = nullptr;
struct Throws {
    unsigned char bytes[8192];
    Throws() {
        CHECK(FUN_00401020()->Owns(this));
        failedConstruction = this;
        bytes[8191] = 0x57;
        throw 7;
    }
};

int main()
{
    auto* owner = FUN_00401020();
    CHECK(owner == &g_memoryManager);
    CHECK(!owner->HeapsInitialized());
    CHECK(owner->Size(early) == 8192);
    ::operator delete(early);
    CHECK(!owner->Owns(early));
    owner->InitializeHeaps();
    g_tlsBlock.memoryContext = 36;
    auto* memory = ::operator new(8192);
    CHECK(owner->HeapOwner(memory) == fnv::memory::EngineHeapDomain::Main);
    ::operator delete(memory);
    CHECK(!owner->Owns(memory));
    auto* array = new unsigned char[16384];
    CHECK(owner->Owns(array));
    array[16383] = 0x61;
    CHECK(array[16383] == 0x61);
    delete[] array;
    CHECK(!owner->Owns(array));
    try {
        auto* object = new Throws;
        (void)object;
        CHECK(false);
    } catch (int value) {
        CHECK(value == 7);
    }
    CHECK(failedConstruction && !owner->Owns(failedConstruction));
    try {
        (void)::operator new(16); // No fake native pool completion.
        CHECK(false);
    } catch (const std::bad_alloc&) {}
    try {
        (void)::operator new(std::numeric_limits<std::size_t>::max());
        CHECK(false);
    } catch (const std::bad_alloc&) {}
    ::operator delete(nullptr);
    owner->ShutdownHeaps();
    CHECK(!owner->HeapsInitialized());
    std::puts("actual manager global-new connection passed");
}
