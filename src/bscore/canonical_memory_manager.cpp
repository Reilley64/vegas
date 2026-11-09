#include "fnv/decl/MemoryManager.h"
#include "fnv/list_node.h"
#include "fnv/ni_ref_object.h"
#include "fnv/tls.h"
#include "fnv/symbols_00401000.h"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <memory>
#include <new>

// Constant initialization binds the source-owned object before any dynamic
// initializer can call global new. The allocation service must outlive every
// static client, so Clang must not register its destructor; process reclamation
// ends its storage lifetime. Explicitly constructed local owners retain normal
// detached-client cleanup through MemoryManager::~MemoryManager.
[[clang::no_destroy]] constinit MemoryManager g_memoryManager;

// @fnv 0x00401020
MemoryManager* FUN_00401020()
{
    return &g_memoryManager;
}

// @fnv 0x00401000
void* FUN_00401000(unsigned int size)
{
    return FUN_00401020()->FUN_00aa3e40(size);
}

// @fnv 0x00401030
void FUN_00401030(void* memory)
{
    FUN_00401020()->FUN_00aa4060(memory);
}

struct alignas(std::max_align_t) MemoryManager::BootstrapBlock {
    BootstrapBlock* next;
    std::size_t bytes;
};

MemoryManager::~MemoryManager()
{
    // Destruction requires detached clients. List-node blocks retain their
    // original allocation domains and must retire before those domains.
    if (!ShutdownListNodes())
        std::abort();
    // Retire scrap objects before their backing bootstrap/heap allocations,
    // including their actual destructor.
    while (scraps_) {
        auto* entry = scraps_;
        scraps_ = entry->next;
        entry->retire(entry->heap);
        ReleaseOwned(entry);
    }
    ShutdownHeaps();
}

// @fnv 0x00aa3e40
void* MemoryManagerStandIn::FUN_00aa3e40(unsigned int size)
{
    auto& owner = *static_cast<MemoryManager*>(this);
    if (!owner.HeapsInitialized())
        return owner.AllocateBootstrap(size);
    if (size > std::numeric_limits<unsigned int>::max() - 3)
        return nullptr;
    if (size <= 0x3fc && owner.m_bPoolAllocationEnabled) {
        // A small request may fall through only after this same owner has
        // published all fixed families. Before publication the route remains
        // unavailable instead of substituting a heap for pool startup.
        if (!owner.PoolsInitialized())
            return nullptr;
        if (auto* memory = owner.AllocateFromPools(size))
            return memory;
    }
    return owner.AllocateFromHeaps(size);
}

// @fnv 0x00aa4060
void FNV_MemoryManager::FUN_00aa4060(void* memory)
{
    if (!static_cast<MemoryManager*>(this)->ReleaseOwned(memory))
        std::abort();
}

bool MemoryManager::HeapsInitialized() noexcept
{
    return heaps_.IsInitialized();
}

void* MemoryManager::AllocateBootstrap(std::size_t bytes) noexcept
{
    bytes = std::max(bytes, std::size_t{1});
    if (bytes > std::numeric_limits<std::size_t>::max() - sizeof(BootstrapBlock))
        return nullptr;
    auto* block = static_cast<BootstrapBlock*>(std::malloc(sizeof(BootstrapBlock) + bytes));
    if (!block)
        return nullptr;
    std::lock_guard guard(bootstrapLock_);
    new (block) BootstrapBlock{bootstrap_, bytes};
    bootstrap_ = block;
    return block + 1;
}

void* MemoryManager::AllocateFromHeaps(std::size_t bytes) noexcept
{
    if (!heaps_.IsInitialized())
        return AllocateBootstrap(bytes);
    return heaps_.Allocate(bytes, g_tlsBlock.memoryContext);
}

std::size_t MemoryManager::BootstrapSize(const void* memory) noexcept
{
    std::lock_guard guard(bootstrapLock_);
    for (auto* block = bootstrap_; block; block = block->next)
        if (block + 1 == memory)
            return block->bytes;
    return 0;
}

std::size_t MemoryManager::Size(const void* memory) noexcept
{
    if (!memory)
        return 0;
    if (const auto bytes = BootstrapSize(memory))
        return bytes;
    if (const auto bytes = PoolSize(memory))
        return bytes;
    return heaps_.Size(memory);
}

bool MemoryManager::Owns(const void* memory) noexcept
{
    return Size(memory) != 0;
}

bool MemoryManager::ReleaseOwned(void* memory) noexcept
{
    if (!memory)
        return true;
    {
        std::lock_guard guard(bootstrapLock_);
        auto** link = &bootstrap_;
        while (*link) {
            auto* block = *link;
            if (block + 1 == memory) {
                *link = block->next;
                std::free(block);
                return true;
            }
            link = &block->next;
        }
    }
    if (ReleasePoolOwned(memory))
        return true;
    if (heaps_.OwnerOf(memory) == fnv::memory::EngineHeapDomain::None)
        return false;
    heaps_.Deallocate(memory);
    return true;
}

void* MemoryManager::Reallocate(void* memory, unsigned int bytes) noexcept
{
    return ResizeOwned(memory, static_cast<std::size_t>(bytes));
}

void* MemoryManager::ResizeOwned(void* memory, std::size_t bytes) noexcept
{
    if (!memory) {
        if (bytes > std::numeric_limits<unsigned int>::max())
            return nullptr;
        return FUN_00aa3e40(static_cast<unsigned int>(bytes));
    }
    const auto oldSize = Size(memory);
    if (!oldSize)
        return nullptr; // A foreign/interior pointer is never passed to CRT.
    if (!bytes) {
        ReleaseOwned(memory);
        return nullptr;
    }
    if (!BootstrapSize(memory)) {
        if (bytes > std::numeric_limits<unsigned int>::max())
            return nullptr;
        // Pool and heap replacement allocation cross the same policy gate.
        // Allocate before retirement so failure preserves owner and bytes.
        auto* replacement = FUN_00aa3e40(static_cast<unsigned int>(bytes));
        if (!replacement)
            return nullptr;
        std::memcpy(replacement, memory, std::min(bytes, oldSize));
        ReleaseOwned(memory);
        return replacement;
    }
    // Keep pre-startup allocations in their genuine bootstrap domain, even
    // after publication. Allocate before retiring; failure retains the payload.
    auto* replacement = AllocateBootstrap(bytes);
    if (!replacement)
        return nullptr;
    std::memcpy(replacement, memory, std::min(bytes, oldSize));
    ReleaseOwned(memory);
    return replacement;
}

fnv::memory::EngineHeapDomain MemoryManager::HeapOwner(const void* memory) noexcept
{
    return heaps_.OwnerOf(memory);
}

struct MemoryManager::ListNodeBlock {
    ListNodeBlock* next;
    std::size_t nodeCount;
    std::size_t nodeOffset;
    std::size_t bitmapOffset;
};

struct MemoryManager::ListNodeFreeLink {
    ListNodeFreeLink* next;
};

namespace {
constexpr std::size_t NativeListNodeBytes = 3 * sizeof(void*);
constexpr std::size_t NativeListNodeAlignment = alignof(void*);

std::size_t AlignUp(std::size_t value, std::size_t alignment)
{
    return (value + alignment - 1) & ~(alignment - 1);
}
} // namespace

void MemoryManager::RefillListNodesLocked(std::size_t count)
{
    if (!count || count > std::numeric_limits<std::size_t>::max() - freeListNodeCount_ ||
        listNodeBlockCount_ == std::numeric_limits<std::size_t>::max())
        throw std::bad_alloc();
    const auto bitmapBytes = count > std::numeric_limits<std::size_t>::max() - 7
                                 ? std::numeric_limits<std::size_t>::max()
                                 : (count + 7) / 8;
    if (bitmapBytes == std::numeric_limits<std::size_t>::max() ||
        bitmapBytes > std::numeric_limits<std::size_t>::max() - sizeof(ListNodeBlock))
        throw std::bad_alloc();
    const auto nodeOffset = AlignUp(sizeof(ListNodeBlock) + bitmapBytes,
                                    NativeListNodeAlignment);
    if (count > (std::numeric_limits<std::size_t>::max() - nodeOffset) /
                    NativeListNodeBytes)
        throw std::bad_alloc();
    const auto bytes = nodeOffset + count * NativeListNodeBytes;
    if (bytes > std::numeric_limits<unsigned int>::max())
        throw std::bad_alloc();

    auto* allocation = FUN_00aa3e40(static_cast<unsigned int>(bytes));
    if (!allocation)
        throw std::bad_alloc();

    auto* block = std::construct_at(static_cast<ListNodeBlock*>(allocation),
                                    ListNodeBlock{nullptr, count, nodeOffset,
                                                  sizeof(ListNodeBlock)});
    auto* blockBytes = static_cast<std::byte*>(allocation);
    std::memset(blockBytes + block->bitmapOffset, 0, bitmapBytes);

    ListNodeFreeLink* first = nullptr;
    ListNodeFreeLink* last = nullptr;
    for (std::size_t index = 0; index < count; ++index) {
        auto* storage = blockBytes + nodeOffset + index * NativeListNodeBytes;
        auto* link = std::construct_at(reinterpret_cast<ListNodeFreeLink*>(storage),
                                       ListNodeFreeLink{first});
        first = link;
        if (!last)
            last = link;
    }

    // Publish only after the complete block and free chain exist. Nothing in
    // the owner changes if allocation or checked sizing fails above.
    block->next = listNodeBlocks_;
    listNodeBlocks_ = block;
    last->next = freeListNodes_;
    freeListNodes_ = first;
    freeListNodeCount_ += count;
    ++listNodeBlockCount_;
}

void MemoryManager::RefillListNodes(std::size_t count)
{
    std::lock_guard guard(listNodeLock_);
    RefillListNodesLocked(count);
}

void* MemoryManager::AcquireListNodeStorage()
{
    std::lock_guard guard(listNodeLock_);
    if (!freeListNodes_)
        RefillListNodesLocked(2048);

    auto* storage = freeListNodes_;
    freeListNodes_ = storage->next;

    const auto address = reinterpret_cast<std::uintptr_t>(storage);
    bool found = false;
    for (auto* block = listNodeBlocks_; block; block = block->next) {
        auto* bytes = reinterpret_cast<std::byte*>(block);
        const auto begin = reinterpret_cast<std::uintptr_t>(bytes + block->nodeOffset);
        const auto extent = block->nodeCount * NativeListNodeBytes;
        if (address < begin || address >= begin + extent)
            continue;
        const auto delta = address - begin;
        if (delta % NativeListNodeBytes)
            std::abort();
        const auto index = delta / NativeListNodeBytes;
        auto* bitmap = reinterpret_cast<unsigned char*>(bytes + block->bitmapOffset);
        const auto mask = static_cast<unsigned char>(1u << (index & 7));
        if (bitmap[index >> 3] & mask)
            std::abort();
        bitmap[index >> 3] |= mask;
        found = true;
        break;
    }
    if (!found || !freeListNodeCount_)
        std::abort();

    std::destroy_at(storage);
    --freeListNodeCount_;
    ++liveListNodeCount_;
    return storage;
}

void MemoryManager::RecycleListNodeStorage(void* storage) noexcept
{
    if (!storage)
        std::abort();
    std::lock_guard guard(listNodeLock_);

    const auto address = reinterpret_cast<std::uintptr_t>(storage);
    bool found = false;
    for (auto* block = listNodeBlocks_; block; block = block->next) {
        auto* bytes = reinterpret_cast<std::byte*>(block);
        const auto begin = reinterpret_cast<std::uintptr_t>(bytes + block->nodeOffset);
        const auto extent = block->nodeCount * NativeListNodeBytes;
        if (address < begin || address >= begin + extent)
            continue;
        const auto delta = address - begin;
        if (delta % NativeListNodeBytes)
            std::abort();
        const auto index = delta / NativeListNodeBytes;
        auto* bitmap = reinterpret_cast<unsigned char*>(bytes + block->bitmapOffset);
        const auto mask = static_cast<unsigned char>(1u << (index & 7));
        if (!(bitmap[index >> 3] & mask))
            std::abort();
        bitmap[index >> 3] &= static_cast<unsigned char>(~mask);
        found = true;
        break;
    }
    if (!found || !liveListNodeCount_)
        std::abort();

    auto* link = std::construct_at(static_cast<ListNodeFreeLink*>(storage),
                                   ListNodeFreeLink{freeListNodes_});
    freeListNodes_ = link;
    ++freeListNodeCount_;
    --liveListNodeCount_;
}

MemoryManager::ListNodePoolStatistics MemoryManager::ListNodeStatistics() noexcept
{
    std::lock_guard guard(listNodeLock_);
    return {listNodeBlockCount_, freeListNodeCount_, liveListNodeCount_};
}

fnv::memory::EngineHeapDomain MemoryManager::ListNodeAllocationDomain(
    const void* storage) noexcept
{
    if (!storage)
        return fnv::memory::EngineHeapDomain::None;
    std::lock_guard guard(listNodeLock_);
    const auto address = reinterpret_cast<std::uintptr_t>(storage);
    for (auto* block = listNodeBlocks_; block; block = block->next) {
        auto* bytes = reinterpret_cast<std::byte*>(block);
        const auto begin = reinterpret_cast<std::uintptr_t>(bytes + block->nodeOffset);
        const auto extent = block->nodeCount * NativeListNodeBytes;
        if (address >= begin && address < begin + extent &&
            (address - begin) % NativeListNodeBytes == 0)
            return HeapOwner(block);
    }
    return fnv::memory::EngineHeapDomain::None;
}

bool MemoryManager::ShutdownListNodes() noexcept
{
    ListNodeBlock* blocks;
    {
        std::lock_guard guard(listNodeLock_);
        if (liveListNodeCount_)
            return false;
        blocks = listNodeBlocks_;
        listNodeBlocks_ = nullptr;
        freeListNodes_ = nullptr;
        freeListNodeCount_ = 0;
        listNodeBlockCount_ = 0;
    }
    while (blocks) {
        auto* block = blocks;
        blocks = block->next;
        std::destroy_at(block);
        if (!ReleaseOwned(block))
            std::abort();
    }
    return true;
}

bool fnv::list::TryRetainPayload(NiRefObject* payload) noexcept
{
    return !payload || payload->TryIncRefCount();
}

void fnv::list::ReleasePayload(NiRefObject* payload) noexcept
{
    if (payload)
        payload->DecRefCount();
}

void fnv::list::RefillStorage()
{
    g_memoryManager.RefillListNodes();
}

void* fnv::list::AcquireStorage()
{
    return g_memoryManager.AcquireListNodeStorage();
}

void fnv::list::RecycleStorage(void* storage) noexcept
{
    g_memoryManager.RecycleListNodeStorage(storage);
}

bool fnv::list::ShutdownStorage() noexcept
{
    return g_memoryManager.ShutdownListNodes();
}

void MemoryManager::ShutdownHeaps() noexcept
{
    // Scrap and list-node backing allocations must outlive their clients.
    if (scraps_ || !ShutdownListNodes())
        std::abort();
    {
        std::lock_guard startupGuard(poolStartupLock_);
        std::lock_guard guard(poolLock_);
        RetirePoolsLocked();
    }
    heaps_.Shutdown();
    std::lock_guard guard(bootstrapLock_);
    while (bootstrap_) {
        auto* block = bootstrap_;
        bootstrap_ = block->next;
        std::free(block);
    }
}
