#pragma once

#include <cstddef>
#include <mutex>
#include <type_traits>
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/memory/engine_heap_set.h"

class ScrapHeapBuffer;

// Native owner. Legacy allocation/release entries are real bases in one
// inheritance chain, not alternate owner declarations. No PC offsets describe it.
// The global/getter owns this complete, constant-initialized object. Full legacy
// startup remains fail-closed until pool/range/recovery and callback joins exist.
struct MemoryManager : FNV_MemoryManager {
private:
    friend struct MemoryManagerStandIn;
    struct BootstrapBlock;
    fnv::memory::EngineHeapSet heaps_{};
    std::mutex bootstrapLock_{};
    BootstrapBlock* bootstrap_ = nullptr;

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
    // Unavailable until genuine pool startup and matching ownership operations
    // are joined. Neither heap initialization nor pool construction publishes it.
    static void* AllocateFromPools(unsigned int);
    void* (*poolAllocate_)(unsigned int) = nullptr;
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
    // Detached heap/bootstrap clients only. Full engine shutdown is separate.
    void ShutdownHeaps() noexcept;

    // Unjoined production interfaces, not publication permission.
    void FUN_00866770();
    void CreateMemoryPool(unsigned int, unsigned int, char*);
    void* Allocate(unsigned int, const char*, const int, const char*);
    ScrapHeapBuffer* GetGeneralAllocator();
};

// This checks base/owner pointer interconvertibility, NOT construction. The
// source-owned constant-initialized global supplies the actual receiver lifetime.
static_assert(std::is_standard_layout_v<MemoryManager>);

extern MemoryManager g_memoryManager;
