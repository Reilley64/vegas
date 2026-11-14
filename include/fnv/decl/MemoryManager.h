#pragma once

#include <cstddef>
#include <cstdint>
#include <mutex>
#include <type_traits>
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/memory/engine_heap_set.h"
#include "fnv/memory/fixed_pool.h"

struct ScrapHeapBuffer;

// Native owner. Legacy allocation/release entries are real bases in one
// inheritance chain, not alternate owner declarations. No PC offsets describe it.
// The global/getter owns this complete, constant-initialized process-lifetime
// object. Full startup stays fail-closed until the remaining domain joins exist.
struct MemoryManager : FNV_MemoryManager {
private:
    friend struct MemoryManagerStandIn;
    struct BootstrapBlock;
    fnv::memory::EngineHeapSet heaps_{};
    std::mutex bootstrapLock_{};
    BootstrapBlock* bootstrap_ = nullptr;

    static constexpr std::size_t FixedPoolCount = 37;
    std::mutex poolStartupLock_{};
    std::mutex poolLock_{};
    fnv::memory::FixedPool pools_[FixedPoolCount]{};
    std::size_t stagedPoolCount_ = 0;
    bool poolStartupActive_ = false;
    bool poolsPublished_ = false;

    // Source thread-id -> scrap-heap association, with native links and keys.
    // Retirement is installed only by the actual scrap construction body.
    struct ScrapEntry {
        ScrapEntry* next;
        unsigned long thread;
        ScrapHeapBuffer* heap;
        void (*retire)(ScrapHeapBuffer*) noexcept;
    };
    std::mutex scrapLock_{};
    ScrapEntry* scraps_ = nullptr;

    struct ListNodeBlock;
    struct ListNodeFreeLink;
    std::mutex listNodeLock_{};
    ListNodeBlock* listNodeBlocks_ = nullptr;
    ListNodeFreeLink* freeListNodes_ = nullptr;
    std::size_t freeListNodeCount_ = 0;
    std::size_t liveListNodeCount_ = 0;
    std::size_t listNodeBlockCount_ = 0;
    void RefillListNodesLocked(std::size_t);

    bool BeginPoolStartup();
    void CompletePoolStartup();
    void CancelPoolStartup() noexcept;
    void CreateMemoryPoolStaged(unsigned int, unsigned int, char*);
    void RetirePoolsLocked() noexcept;
    fnv::memory::FixedPool* SelectPoolLocked(unsigned int) noexcept;
    std::size_t BootstrapSize(const void*) noexcept;
    std::size_t PoolSize(const void*) noexcept;
    bool ReleasePoolOwned(void*) noexcept;
    void* AllocateFromPools(unsigned int) noexcept;
    bool m_bPoolAllocationEnabled = true;

public:
    MemoryManager() noexcept = default;
    MemoryManager(const MemoryManager&) = delete;
    MemoryManager& operator=(const MemoryManager&) = delete;
    ~MemoryManager();

    // 00866e00: initializes all three owned heaps or throws bad_alloc.
    void InitializeHeaps();
    bool HeapsInitialized() noexcept;
    // Production non-pool allocation boundary, after the pool decision. Reads
    // the real allocation TLS context; before heap startup uses tracked CRT
    // bootstrap storage (4290), never a host replacement for initialized heaps.
    void* AllocateFromHeaps(std::size_t) noexcept;
    void* AllocateBootstrap(std::size_t) noexcept;
    bool ReleaseOwned(void*) noexcept;
    bool Owns(const void*) noexcept;
    std::size_t Size(const void*) noexcept;
    // Existing requiring objects retain their unsigned entry; widening here
    // reaches the same owner, without a nominal compatibility receiver.
    void* Reallocate(void*, unsigned int) noexcept;
    void* ResizeOwned(void*, std::size_t) noexcept;
    fnv::memory::EngineHeapDomain HeapOwner(const void*) noexcept;
    bool PoolsInitialized() noexcept;
    std::size_t PoolFamilyCount() const noexcept { return FixedPoolCount; }
    fnv::memory::FixedPoolStatistics PoolStatistics(std::size_t) noexcept;
    std::size_t PoolOwnerIndex(const void*) noexcept;

    struct ListNodePoolStatistics {
        std::size_t blocks;
        std::size_t freeNodes;
        std::size_t liveNodes;
    };
    // Native storage for the common three-pointer list node. The storage is
    // supplied and retired by this same allocation owner under the caller's
    // real TLS context. Acquire throws bad_alloc without publishing a partial
    // refill; recycle terminates on a foreign, interior, or duplicate node.
    void RefillListNodes(std::size_t count = 2048);
    void* AcquireListNodeStorage();
    void RecycleListNodeStorage(void*) noexcept;
    ListNodePoolStatistics ListNodeStatistics() noexcept;
    fnv::memory::EngineHeapDomain ListNodeAllocationDomain(const void*) noexcept;
    bool ShutdownListNodes() noexcept;

    // Detached heap/bootstrap/pool/list clients only. Full engine shutdown is separate.
    void ShutdownHeaps() noexcept;

    // Source fixed-pool startup. Publication occurs only after all 37 exact
    // CreateMemoryPool calls complete successfully on this owner.
    void FUN_00866770();
    void CreateMemoryPool(unsigned int, unsigned int, char*);
    void* Allocate(unsigned int, const char*, const int, const char*);
    ScrapHeapBuffer* GetGeneralAllocator();
};

// This checks base/owner pointer interconvertibility, NOT construction. The
// source-owned constant-initialized global supplies the actual receiver lifetime.
static_assert(std::is_standard_layout_v<MemoryManager>);

// The process-lifetime owner itself, not a pointer or historical receiver prefix.
// Local owners still have ordinary destruction.
extern MemoryManager g_memoryManager;
