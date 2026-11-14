#pragma once

#include "fnv/memory/engine_heap.h"

#include <cstddef>
#include <cstdint>
#include <mutex>

namespace fnv::memory {

struct FixedPoolStatistics {
    const char* name = nullptr;
    std::size_t blockBytes = 0;
    std::size_t blockStride = 0;
    std::size_t reservedBytes = 0;
    std::size_t capacityBlocks = 0;
    std::size_t committedPages = 0;
    std::size_t allocatedBlocks = 0;
};

// Native semantic storage for one source fixed-block pool. Reservations and
// allocation bits belong to the pool itself; no truncated address cache or
// allocation from the manager is needed to establish its metadata.
class FixedPool {
    struct FreeBlock {
        FreeBlock* previous;
        FreeBlock* next;
    };

    mutable std::mutex lock_{};
    VirtualRegion region_{};
    VirtualRegion metadata_{};
    FreeBlock* free_ = nullptr;
    std::byte* pageCounts_ = nullptr;
    std::byte* allocationBits_ = nullptr;
    std::size_t pageCount_ = 0;
    std::size_t bitWordCount_ = 0;
    std::size_t slotsPerPage_ = 0;
    std::size_t blockBytes_ = 0;
    std::size_t stride_ = 0;
    std::size_t committedPages_ = 0;
    std::size_t allocatedBlocks_ = 0;
    const char* name_ = nullptr;

    std::uint16_t* PageCountAt(std::size_t index) noexcept;
    const std::uint16_t* PageCountAt(std::size_t index) const noexcept;
    std::uint64_t* AllocationWordAt(std::size_t index) noexcept;
    const std::uint64_t* AllocationWordAt(std::size_t index) const noexcept;
    bool IsExactSlotLocked(const void* memory, std::size_t& slot) const noexcept;
    bool IsAllocatedLocked(std::size_t slot) const noexcept;
    void SetAllocatedLocked(std::size_t slot, bool allocated) noexcept;
    void PushLocked(void* memory) noexcept;
    bool CommitPageLocked(std::size_t pageIndex) noexcept;

public:
    constexpr FixedPool() noexcept = default;
    FixedPool(const FixedPool&) = delete;
    FixedPool& operator=(const FixedPool&) = delete;
    ~FixedPool() { Shutdown(); }

    bool Initialize(std::size_t blockBytes, std::size_t reserveBytes,
                    const char* name) noexcept;
    void Shutdown() noexcept;
    void* Allocate() noexcept;
    bool Deallocate(void* memory) noexcept;
    bool ContainsAddress(const void* memory) const noexcept;
    std::size_t Size(const void* memory) const noexcept;
    FixedPoolStatistics Statistics() const noexcept;
    bool IsInitialized() const noexcept;
};

} // namespace fnv::memory
