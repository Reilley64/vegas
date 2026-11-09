#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/list_node.h"
#include "fnv/symbols_00e6e000.h"
#include "fnv/ni_ref_object.h"
#include "fnv/tls.h"

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <thread>
#include <vector>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

#ifndef _WIN32
// Host sanitizer checks compile the same native NiRefObject protocol without
// the Windows-only complete game archive. These are the production bodies and
// storage identity for this executable, not a replacement node or allocator.
unsigned int NiRefObject::ms_lObjectCount = 0;
NiRefObject::~NiRefObject()
{
    NiAtomicSubtract(ms_lObjectCount);
}
void NiRefObject::DeleteThis()
{
    delete this;
}
#endif

namespace {
using Domain = fnv::memory::EngineHeapDomain;

struct Payload final : NiRefObject {
    explicit Payload(std::uintptr_t marker) : marker(marker) {}
    ~Payload() override { ++destroyed; }
    void DeleteThis() override { delete this; }

    std::uintptr_t marker;
    static inline std::atomic<unsigned int> destroyed{0};
};

void ProductionEntries()
{
#ifdef _WIN32
    FUN_0043a010_shell allocator;
    auto* raw = allocator.FUN_0043a010();
    CHECK(raw != nullptr);
    fnv::list::RecycleStorage(raw);

    auto* payload = new Payload(0x57);
    auto* node = fnv::list::AcquireNode<NiRefObject>();
    CHECK(fnv::list::TryRetainPayload(payload));
    node->payload = payload;
    ReleaseRefCountedNode(node);
    CHECK(Payload::destroyed.load() == 1);
#endif
}

void EmptyAndOne()
{
    const auto destroyedBefore = Payload::destroyed.load();
    fnv::list::RetainedList list;
    CHECK(!list.PopFront());
    CHECK(!list.PopBack());
    CHECK(list.Empty());

    auto* payload = new Payload(0x1234567887654321ULL);
    list.PushBack(payload);
    CHECK(list.count == 1);
    CHECK(list.head == list.tail);
    CHECK(list.head->payload == payload);
    CHECK(payload->m_uiRefCount == 1);
    {
        auto result = list.PopBack();
        CHECK(result.Get() == payload);
        CHECK(result.Get()->m_uiRefCount == 1);
        CHECK(static_cast<Payload*>(result.Get())->marker == 0x1234567887654321ULL);
    }
    CHECK(list.Empty());
    CHECK(Payload::destroyed.load() == destroyedBefore + 1);
}

void ManyAliasAndMemberRemoval()
{
    auto* first = new Payload(1);
    auto* alias = new Payload(2);
    fnv::list::RetainedPayload keepAlias(alias);
    {
        fnv::list::RetainedList list;
        list.PushBack(first);
        list.PushBack(alias);
        list.PushBack(alias);
        CHECK(list.count == 3);
        CHECK(alias->m_uiRefCount == 3);

        auto* middle = list.head->next;
        auto result = list.Remove(middle);
        CHECK(result.Get() == alias);
        CHECK(middle == list.tail);
        CHECK(list.count == 2);
        CHECK(list.head->next == list.tail);
        CHECK(list.tail->previous == list.head);

        auto front = list.PopFront();
        CHECK(static_cast<Payload*>(front.Get())->marker == 1);
        auto back = list.PopBack();
        CHECK(back.Get() == alias);
        CHECK(list.Empty());
    }
    CHECK(alias->m_uiRefCount == 1);
}

void FailurePreservesStructureAndTls()
{
    fnv::list::RetainedList list;
    auto* stable = new Payload(3);
    list.PushBack(stable);
    auto* head = list.head;
    const auto before = g_memoryManager.ListNodeStatistics();

    stable->m_uiRefCount = std::numeric_limits<unsigned int>::max();
    bool removalOverflow = false;
    try {
        list.PopBack();
    } catch (const std::overflow_error&) {
        removalOverflow = true;
    }
    CHECK(removalOverflow);
    CHECK(list.head == head && list.tail == head && list.count == 1);
    stable->m_uiRefCount = 1;

    auto* saturated = new Payload(4);
    saturated->m_uiRefCount = std::numeric_limits<unsigned int>::max();
    bool overflow = false;
    try {
        list.PushBack(saturated);
    } catch (const std::overflow_error&) {
        overflow = true;
    }
    CHECK(overflow);
    CHECK(list.head == head && list.tail == head && list.count == 1);
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == before.liveNodes);
    saturated->m_uiRefCount = 0;
    delete saturated;

    const int context = g_tlsBlock.memoryContext = 23;
    const auto stats = g_memoryManager.ListNodeStatistics();
    bool allocationFailure = false;
    try {
        g_memoryManager.RefillListNodes(std::numeric_limits<std::size_t>::max());
    } catch (const std::bad_alloc&) {
        allocationFailure = true;
    }
    CHECK(allocationFailure);
    CHECK(g_tlsBlock.memoryContext == context);
    const auto after = g_memoryManager.ListNodeStatistics();
    CHECK(after.blocks == stats.blocks);
    CHECK(after.freeNodes == stats.freeNodes);
    CHECK(after.liveNodes == stats.liveNodes);
    CHECK(list.head == head && list.tail == head && list.count == 1);
}

void AllocationDomainsReuseAndShutdown()
{
    CHECK(g_memoryManager.ShutdownListNodes());
    g_tlsBlock.memoryContext = 23;
    auto* contextNode = fnv::list::AcquireNode<void>();
    CHECK(reinterpret_cast<std::uintptr_t>(contextNode) > UINT32_MAX);
    CHECK(g_memoryManager.ListNodeAllocationDomain(contextNode) == Domain::Context23);
    fnv::list::RecycleNode(contextNode);

    auto* reused = fnv::list::AcquireNode<void>();
    CHECK(reused == contextNode);
    CHECK(!g_memoryManager.ShutdownListNodes());
    fnv::list::RecycleNode(reused);
    CHECK(g_memoryManager.ShutdownListNodes());
    CHECK(g_memoryManager.ListNodeStatistics().blocks == 0);

    g_tlsBlock.memoryContext = 9;
    auto* auxiliaryNode = fnv::list::AcquireNode<void>();
    CHECK(g_memoryManager.ListNodeAllocationDomain(auxiliaryNode) == Domain::Auxiliary);
    fnv::list::RecycleNode(auxiliaryNode);
    CHECK(g_memoryManager.ShutdownListNodes());
}

void ConcurrentContexts()
{
    CHECK(g_memoryManager.ShutdownListNodes());
    constexpr int threadCount = 8;
    constexpr int iterations = 2000;
    std::vector<std::thread> threads;
    threads.reserve(threadCount);
    for (int thread = 0; thread < threadCount; ++thread) {
        threads.emplace_back([thread] {
            const int original = thread % 2 ? 9 : 23;
            g_tlsBlock.memoryContext = original;
            for (int iteration = 0; iteration < iterations; ++iteration) {
                auto* node = fnv::list::AcquireNode<int>();
                int payload = iteration + thread;
                node->payload = &payload;
                CHECK(node->payload == &payload);
                CHECK(g_tlsBlock.memoryContext == original);
                fnv::list::RecycleNode(node);
            }
            CHECK(g_tlsBlock.memoryContext == original);
        });
    }
    for (auto& thread : threads)
        thread.join();
    const auto stats = g_memoryManager.ListNodeStatistics();
    CHECK(stats.liveNodes == 0);
    CHECK(stats.freeNodes == stats.blocks * 2048);
}

void UnwindRetires()
{
    const auto destroyedBefore = Payload::destroyed.load();
    try {
        fnv::list::RetainedList owner;
        owner.PushBack(new Payload(5));
        owner.PushBack(new Payload(6));
        throw std::runtime_error("unwind");
    } catch (const std::runtime_error&) {
    }
    CHECK(Payload::destroyed.load() == destroyedBefore + 2);
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == 0);
}
} // namespace

int main()
{
    g_memoryManager.InitializeHeaps();
    ProductionEntries();
    EmptyAndOne();
    ManyAliasAndMemberRemoval();
    FailurePreservesStructureAndTls();
    AllocationDomainsReuseAndShutdown();
    ConcurrentContexts();
    UnwindRetires();
    CHECK(g_memoryManager.ShutdownListNodes());
    g_memoryManager.ShutdownHeaps();
    return 0;
}
