#pragma once
#include <mutex>
#include <cstddef>
#include <cstdint>

namespace fnv::memory {
// Production virtual-memory backend for the source reserve/commit heaps. No
// allocation from this API is in the C++ or CRT allocation domain.
std::size_t NativePageSize() noexcept;
struct VirtualRegion {
    constexpr VirtualRegion() noexcept = default;
    VirtualRegion(const VirtualRegion&) = delete;
    VirtualRegion& operator=(const VirtualRegion&) = delete;
    ~VirtualRegion() { Release(); }
    std::byte* base = nullptr;
    std::size_t reserved = 0;
    std::size_t committed = 0;
    bool Reserve(std::size_t reserve, std::size_t commit) noexcept;
    bool Commit(std::size_t bytes) noexcept;
    bool CommitRange(std::size_t offset, std::size_t bytes) noexcept;
    bool DecommitRange(std::size_t offset, std::size_t bytes) noexcept;
    void Trim(std::size_t bytes) noexcept;
    void Release() noexcept;
};
using LockGuard = std::lock_guard<std::mutex>;

// Values, not a layout view of a captured heap.
struct HeapStatistics {
    const char* name = nullptr;
    std::size_t reserved = 0;
    std::size_t committed = 0;
    std::size_t used = 0;
    std::size_t allocations = 0;
    std::size_t freeBytes = 0;
};

// Initialize/Shutdown/Reset require exclusive lifecycle ownership. Contains
// tests reservation membership only; Size validates an exact live allocation.
// Native form of the 00aa8f50/98f0 arena. Free links occupy the payload, so the
// minimum allocation is two native pointers, not the original two wire words.
class EngineHeap {
    struct alignas(std::max_align_t) Block {
        Block* previous;
        std::size_t sizeAndFlags;
    };
    struct Links { Block* next; Block* previous; };
    struct FreeList { Block* head = nullptr; Block* tail = nullptr; };
    static constexpr std::size_t Free = std::size_t(1) << (sizeof(std::size_t)*8-1);
    static std::size_t SizeOf(const Block* block) noexcept;
    static Block* Next(Block* block) noexcept;
    static Links LoadLinks(const Block* block) noexcept;
    static void StoreLinks(Block* block, Links links) noexcept;
    Block* FindAllocation(const void* memory) noexcept;
    std::size_t Bucket(std::size_t bytes) const noexcept;
    void AddFree(Block* block) noexcept;
    void RemoveFree(Block* block) noexcept;
    void Coalesce(Block* first, Block* second) noexcept;
    std::mutex lock_{};
    VirtualRegion region_{};
    const char* name_ = nullptr;
    std::size_t used_ = 0;
    std::size_t minimumCommit_ = 0;
    std::size_t allocated_ = 0;
    std::size_t allocationCount_ = 0;
    Block* last_ = nullptr;
    FreeList lists_[1025]{};
public:
    ~EngineHeap() { Shutdown(); }
    bool Initialize(std::size_t reserve, std::size_t commit, const char* name) noexcept;
    void Shutdown() noexcept;
    bool Contains(const void* memory) const noexcept;
    void* Allocate(std::size_t bytes) noexcept;
    void Deallocate(void* memory) noexcept;
    std::size_t Size(const void* memory) noexcept;
    HeapStatistics Statistics() noexcept;
    bool CheckIntegrity() noexcept;
    void Reset() noexcept;
    const VirtualRegion& Region() const noexcept { return region_; }
};

// Source 00aa7400/7530 auxiliary heap: bump allocation with a native aligned
// size header, released collectively. Individual deallocation is deliberately
// the source's empty operation, not a pretend arena implementation.
class EngineLinearHeap {
    std::mutex lock_{};
    VirtualRegion region_{};
    std::size_t used_ = 0;
    std::size_t capacity_ = 0;
    std::size_t FindAllocation(const void* memory) const noexcept;
public:
    ~EngineLinearHeap() { Shutdown(); }
    bool Initialize(std::size_t bytes) noexcept;
    void Shutdown() noexcept;
    bool Contains(const void* memory) const noexcept;
    void* Allocate(std::size_t bytes) noexcept;
    // Source individual release is a no-op; storage retires collectively.
    void Deallocate(void* memory) noexcept;
    std::size_t Size(const void* memory) noexcept;
    HeapStatistics Statistics() noexcept;
    bool CheckIntegrity() noexcept;
    void Reset() noexcept;
    const VirtualRegion& Region() const noexcept { return region_; }
};
}
