#pragma once

#include "fnv/memory/engine_heap.h"

namespace fnv::memory {
enum class EngineHeapDomain { None, Main, Auxiliary, Context23 };

// The heap-owned portion of MemoryManager startup (00866e00), not a second
// manager or a replacement pool/CRT provider. The manager must call Allocate
// only after its pool decision and pass the actual allocation TLS context.
// Publication into the legacy manager is deliberately not part of this module.
class EngineHeapSet {
    std::mutex lock_{};
    EngineHeap main_{};
    EngineLinearHeap auxiliary_{};
    EngineHeap context23_{};
    EngineHeapDomain contexts_[66]{};
    bool initialized_ = false;

    void ReleaseHeaps() noexcept;
    void* AllocateLocked(std::size_t bytes, int context) noexcept;
    EngineHeapDomain OwnerLocked(const void* memory) noexcept;
    void DeallocateLocked(void* memory) noexcept;
    std::size_t SizeLocked(const void* memory) noexcept;
public:
    EngineHeapSet() noexcept = default;
    EngineHeapSet(const EngineHeapSet&) = delete;
    EngineHeapSet& operator=(const EngineHeapSet&) = delete;
    ~EngineHeapSet() { Shutdown(); }

    // All three real heaps must initialize before the set is usable. Failure
    // retires acquired regions and leaves a retryable, unpublished owner.
    bool Initialize() noexcept;
    bool IsInitialized() noexcept;
    void* Allocate(std::size_t bytes, int context) noexcept;
    void* Reallocate(void* memory, std::size_t bytes, int context) noexcept;
    void Deallocate(void* memory) noexcept;
    std::size_t Size(const void* memory) noexcept;
    EngineHeapDomain OwnerOf(const void* memory) noexcept;
    HeapStatistics Statistics(EngineHeapDomain domain) noexcept;
    bool CheckIntegrity() noexcept;
    // All external clients must have detached. Auxiliary allocations have the
    // source's collective lifetime; individual Deallocate does not reclaim them.
    void Shutdown() noexcept;
};
}
