#include "fnv/decl/MemoryManager.h"
#include "fnv/tls.h"
#include "fnv/symbols_00401000.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <limits>
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
    // Destruction requires detached clients. Retire scrap objects before their
    // backing bootstrap/heap allocations, including their actual destructor.
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
        // This heap-only lifecycle must not silently stand in for pool startup.
        if (!owner.poolAllocate_)
            return nullptr;
        if (auto* memory = owner.poolAllocate_(size))
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

std::size_t MemoryManager::Size(const void* memory) noexcept
{
    if (!memory)
        return 0;
    {
        std::lock_guard guard(bootstrapLock_);
        for (auto* block = bootstrap_; block; block = block->next)
            if (block + 1 == memory)
                return block->bytes;
    }
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
    if (heaps_.OwnerOf(memory) != fnv::memory::EngineHeapDomain::None) {
        if (bytes > std::numeric_limits<unsigned int>::max())
            return nullptr;
        // Replacement allocation crosses the same pool-policy gate as an
        // ordinary request. Failure leaves the original payload untouched.
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

void MemoryManager::ShutdownHeaps() noexcept
{
    // Scrap backing allocations must outlive their actual destructors.
    if (scraps_)
        std::abort();
    heaps_.Shutdown();
    std::lock_guard guard(bootstrapLock_);
    while (bootstrap_) {
        auto* block = bootstrap_;
        bootstrap_ = block->next;
        std::free(block);
    }
}
