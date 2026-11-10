#include "fnv/decl/MemoryManager.h"
#include "fnv/list_node.h"
#include "fnv/ni_ref_object.h"
#include "fnv/tls.h"

#include <atomic>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include <stdexcept>
#include <thread>
#include <vector>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

namespace {
using Domain = fnv::memory::EngineHeapDomain;

// The object count, destructor, deletion and type identity all come from the
// production NiRefObject lifetime unit.
struct Payload final : NiRefObject {
    explicit Payload(std::uintptr_t marker) : marker(marker) {}
    ~Payload() override { ++destroyed; }

    std::uintptr_t marker;
    static inline std::atomic<unsigned int> destroyed{0};
};

// A node whose element has its own construction and destruction, as the
// property-pointer nodes of the migrated consumers do.
struct Element {
    explicit Element(int* live) : live(live)
    {
        if (!live)
            throw std::invalid_argument("element");
        ++*live;
    }
    Element(const Element&) = delete;
    ~Element() { --*live; }
    int* live;
};
struct ElementNode {
    ElementNode(ElementNode* next, ElementNode* previous, int* live)
        : next(next), previous(previous), value(live)
    {}
    ElementNode* next;
    ElementNode* previous;
    Element value;
};

void EmptyAndOne()
{
    const auto destroyedBefore = Payload::destroyed.load();
    const auto objectsBefore = NiRefObject::ms_lObjectCount;
    fnv::list::RetainedList list;
    CHECK(!list.PopFront());
    CHECK(!list.PopBack());
    CHECK(list.Empty());

    auto* payload = new Payload(0x1234567887654321ULL);
    CHECK(NiRefObject::ms_lObjectCount == objectsBefore + 1);
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
    CHECK(NiRefObject::ms_lObjectCount == objectsBefore);
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

void NontrivialNodeLifetime()
{
    const auto before = g_memoryManager.ListNodeStatistics();
    int live = 0;
    auto* node = fnv::list::ConstructNode<ElementNode>(nullptr, nullptr, &live);
    CHECK(live == 1);
    CHECK(node->value.live == &live && !node->next && !node->previous);
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == before.liveNodes + 1);
    fnv::list::DestroyNode(node);
    CHECK(live == 0);
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == before.liveNodes);

    // The slot was a free link in between; the next occupant is a complete
    // new object of another node type.
    auto* reused = fnv::list::AcquireNode<int>();
    CHECK(static_cast<void*>(reused) == static_cast<void*>(node));
    CHECK(!reused->next && !reused->previous && !reused->payload);
    auto* adopted = fnv::list::AdoptNode<ElementNode>(reused, nullptr, nullptr, &live);
    CHECK(static_cast<void*>(adopted) == static_cast<void*>(node) && live == 1);
    fnv::list::DestroyNode(adopted);
    CHECK(live == 0);

    // A unit that did not begin a node recycles it through its own
    // three-pointer view; the slot returns to the pool as storage.
    struct View { View* next; View* previous; unsigned int item; };
    auto* begun = fnv::list::AcquireNode<int>();
    fnv::list::RecycleViewedNode(reinterpret_cast<View*>(begun));
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == before.liveNodes);

    // A node constructor that throws returns its slot.
    bool threw = false;
    try {
        fnv::list::ConstructNode<ElementNode>(nullptr, nullptr, nullptr);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    CHECK(threw);
    const auto after = g_memoryManager.ListNodeStatistics();
    CHECK(after.liveNodes == before.liveNodes);
    CHECK(after.freeNodes + after.liveNodes == after.blocks * 2048);
}

void OverflowPreservesStructure()
{
    fnv::list::RetainedList list;
    auto* stable = new Payload(3);
    list.PushBack(stable);
    auto* head = list.head;
    const auto before = g_memoryManager.ListNodeStatistics();

    stable->m_uiRefCount = UINT_MAX;
    bool removalOverflow = false;
    try {
        list.PopBack();
    } catch (const std::overflow_error&) {
        removalOverflow = true;
    }
    CHECK(removalOverflow);
    CHECK(list.head == head && list.tail == head && list.count == 1);
    CHECK(stable->m_uiRefCount == UINT_MAX);
    stable->m_uiRefCount = 1;

    auto* saturated = new Payload(4);
    saturated->m_uiRefCount = UINT_MAX;
    bool overflow = false;
    try {
        list.PushBack(saturated);
    } catch (const std::overflow_error&) {
        overflow = true;
    }
    CHECK(overflow);
    CHECK(list.head == head && list.tail == head && list.count == 1);
    CHECK(saturated->m_uiRefCount == UINT_MAX);
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == before.liveNodes);
    saturated->m_uiRefCount = 0;
    delete saturated;

    // A full 32-bit list count refuses another node before acquiring storage
    // or retaining the payload.
    auto* extra = new Payload(5);
    fnv::list::RetainedPayload keepExtra(extra);
    list.count = UINT32_MAX;
    bool countOverflow = false;
    try {
        list.PushBack(extra);
    } catch (const std::length_error&) {
        countOverflow = true;
    }
    CHECK(countOverflow);
    CHECK(list.head == head && list.tail == head && list.count == UINT32_MAX);
    CHECK(!head->next && !head->previous && head->payload == stable);
    CHECK(extra->m_uiRefCount == 1 && stable->m_uiRefCount == 1);
    const auto after = g_memoryManager.ListNodeStatistics();
    CHECK(after.liveNodes == before.liveNodes && after.freeNodes == before.freeNodes);
    list.count = 1;
    list.PushBack(extra);
    CHECK(list.count == 2 && list.tail->payload == extra && extra->m_uiRefCount == 2);
}

void RefillFailurePreservesStructureAndTls()
{
    fnv::list::RetainedList list;
    auto* stable = new Payload(6);
    list.PushBack(stable);
    auto* head = list.head;

    const int context = g_tlsBlock.memoryContext = 36;
    const auto stats = g_memoryManager.ListNodeStatistics();

    // Checked sizing rejects an unrepresentable request before allocation.
    bool sizingFailure = false;
    try {
        g_memoryManager.RefillListNodes(SIZE_MAX);
    } catch (const std::bad_alloc&) {
        sizingFailure = true;
    }
    CHECK(sizingFailure);

    // Exhaust the selected engine heap so that the manager itself refuses the
    // ordinary 2,048-node block after the refill has entered allocation.
    std::vector<void*> held;
    for (unsigned int bytes : {32u * 1024 * 1024, 1024u * 1024, 16u * 1024}) {
        while (void* memory = g_memoryManager.FUN_00aa3e40(bytes))
            held.push_back(memory);
    }
    CHECK(!held.empty());

    std::vector<fnv::list::Node<int>*> drained;
    for (std::size_t index = 0; index < stats.freeNodes; ++index)
        drained.push_back(fnv::list::AcquireNode<int>());
    const auto empty = g_memoryManager.ListNodeStatistics();
    CHECK(empty.freeNodes == 0 && empty.blocks == stats.blocks);

    bool refillFailure = false;
    try {
        fnv::list::RefillStorage();
    } catch (const std::bad_alloc&) {
        refillFailure = true;
    }
    CHECK(refillFailure);

    auto* payload = new Payload(7);
    fnv::list::RetainedPayload keep(payload);
    bool pushFailure = false;
    try {
        list.PushBack(payload);
    } catch (const std::bad_alloc&) {
        pushFailure = true;
    }
    CHECK(pushFailure);
    CHECK(payload->m_uiRefCount == 1);
    CHECK(list.head == head && list.tail == head && list.count == 1);
    CHECK(!head->next && !head->previous && head->payload == stable);
    CHECK(g_tlsBlock.memoryContext == context);
    const auto failed = g_memoryManager.ListNodeStatistics();
    CHECK(failed.blocks == empty.blocks && failed.freeNodes == 0);
    CHECK(failed.liveNodes == empty.liveNodes);

    // The owner lock was released on both failures: the same thread and
    // another thread can recycle and acquire again.
    for (auto* node : drained)
        fnv::list::RecycleNode(node);
    std::thread([] {
        g_tlsBlock.memoryContext = 36;
        fnv::list::RecycleNode(fnv::list::AcquireNode<int>());
    }).join();
    for (void* memory : held)
        g_memoryManager.FUN_00aa4060(memory);
    list.PushBack(payload);
    CHECK(list.count == 2 && list.tail->payload == payload);
    CHECK(g_tlsBlock.memoryContext == context);
    const auto after = g_memoryManager.ListNodeStatistics();
    CHECK(after.blocks == stats.blocks && after.liveNodes == stats.liveNodes + 1);
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
        owner.PushBack(new Payload(8));
        owner.PushBack(new Payload(9));
        throw std::runtime_error("unwind");
    } catch (const std::runtime_error&) {
    }
    CHECK(Payload::destroyed.load() == destroyedBefore + 2);
    CHECK(g_memoryManager.ListNodeStatistics().liveNodes == 0);
}

// expect_abort.cmake requires the mode's marker on stderr before the abort.
void Reached(const char* marker)
{
    std::fprintf(stderr, "%s\n", marker);
    std::fflush(stderr);
}

// Each mode must terminate inside the production recycler.
[[noreturn]] void InvalidRecycle(const char* mode)
{
    g_memoryManager.InitializeHeaps();
    auto* node = fnv::list::AcquireNode<void>();
    if (!std::strcmp(mode, "--recycle-foreign")) {
        void* foreign[3]{};
        Reached("recycle-foreign");
        fnv::list::RecycleStorage(foreign);
    } else if (!std::strcmp(mode, "--recycle-interior")) {
        Reached("recycle-interior");
        fnv::list::RecycleStorage(reinterpret_cast<unsigned char*>(node) + sizeof(void*));
    } else if (!std::strcmp(mode, "--recycle-duplicate")) {
        // A second live node keeps the live count above zero, so only the
        // slot's own allocated bit can reject the repeat.
        fnv::list::AcquireNode<void>();
        fnv::list::RecycleNode(node);
        Reached("recycle-duplicate");
        fnv::list::RecycleStorage(node);
    } else if (!std::strcmp(mode, "--recycle-null")) {
        Reached("recycle-null");
        fnv::list::RecycleStorage(nullptr);
    }
    std::fprintf(stderr, "invalid recycle was accepted: %s\n", mode);
    std::exit(2);
}
} // namespace

int main(int argc, char** argv)
{
    if (argc == 2)
        InvalidRecycle(argv[1]);

    g_memoryManager.InitializeHeaps();
    EmptyAndOne();
    ManyAliasAndMemberRemoval();
    NontrivialNodeLifetime();
    OverflowPreservesStructure();
    RefillFailurePreservesStructureAndTls();
    AllocationDomainsReuseAndShutdown();
    ConcurrentContexts();
    UnwindRetires();
    CHECK(g_memoryManager.ShutdownListNodes());
    g_memoryManager.ShutdownHeaps();
    std::puts("native list-node recycling passed");
    return 0;
}
