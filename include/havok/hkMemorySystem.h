#pragma once

#include "havok/hkMemoryRouter.h"
#include "runtime/havok_memory_prerequisite.h"

#include <array>
#include <atomic>
#include <cstddef>
#include <mutex>

class hkSystemMemoryAllocator;

// Native owners. These are not overlays for the original release's objects.
class hkNativeThreadMemory final : public hkMemoryAllocator
{
  public:
    ~hkNativeThreadMemory() override;
    void Attach(hkSystemMemoryAllocator& allocator);
    void Release();
    bool HasLiveAllocations() const { return liveBlocks.load(std::memory_order_acquire) != 0; }
    void* blockAlloc(int bytes) override;
    void blockFree(void* block, int bytes) override;
    void* bufAlloc(int& bytes) override;
    int getAllocatedSize(const void*, int bytes) override;
    void getMemoryStatistics(MemoryStatistics& statistics) override;
    void resetPeakMemoryStatistics() override;

  private:
    struct Node { Node* next; };
    struct Cache { Node* head = nullptr; int count = 0; };
    static int SizeClass(int bytes);
    static constexpr std::array<int, 17> sizes{
        0, 16, 32, 48, 64, 96, 128, 160, 192, 256, 320, 512, 640, 1024, 2048, 4096, 8192};
    std::array<Cache, 17> caches{};
    hkSystemMemoryAllocator* allocator = nullptr;
    std::atomic<std::size_t> liveBlocks{0};
};

// The published memory-system pointer and CPU worker use this same native type.
class hkMemorySystem
{
  public:
    virtual ~hkMemorySystem() = default;
    virtual bool InitializeThreadRouter(hkMemoryRouter&, const char* name, int flags) = 0;
    virtual void ThreadQuit(hkMemoryRouter&, int flags) = 0;
};

class hkSystemMemoryAllocator final : public hkMemoryAllocator
{
  public:
    explicit hkSystemMemoryAllocator(havok::native_memory::Allocator& backing) : backing(backing) {}
    ~hkSystemMemoryAllocator() override;
    // Client claims retain their supplying cache, independently of cache residency.
    void ClaimAllocation(void* block, std::atomic<std::size_t>& owner);
    void RelinquishAllocation(void* block);
    void* blockAlloc(int bytes) override;
    void blockFree(void* block, int bytes) override;
    void* bufAlloc(int& bytes) override;
    int getAllocatedSize(const void*, int bytes) override;
    void getMemoryStatistics(MemoryStatistics& statistics) override;
    void resetPeakMemoryStatistics() override;
  private:
    havok::native_memory::Allocator& backing;
    std::mutex mutex;
    std::size_t liveBlocks = 0;
    std::size_t liveBytes = 0;
    std::size_t peakBytes = 0;
};

// Shared bounded solver arena. Free ranges live in their released storage.
class hkNativeSolverAllocator final : public hkMemoryAllocator
{
  public:
    explicit hkNativeSolverAllocator(hkMemoryAllocator& allocator) : allocator(allocator) {}
    ~hkNativeSolverAllocator() override;
    bool Initialize(int bytes);
    bool canAllocTotal(int bytes) override;
    void Release();
    void* blockAlloc(int bytes) override;
    void blockFree(void* block, int bytes) override;
    void* bufAlloc(int& bytes) override;
    int getAllocatedSize(const void*, int bytes) override;
    void getMemoryStatistics(MemoryStatistics& statistics) override;
    void resetPeakMemoryStatistics() override;
  private:
    void* Allocate(int& bytes, bool adjust);
    struct Range { Range* next; int bytes; };
    hkMemoryAllocator& allocator;
    std::mutex mutex;
    char* start = nullptr;
    int capacity = 0;
    int cursor = 0;
    int liveBlocks = 0;
    int liveBytes = 0;
    int peakBytes = 0;
    Range* freeRanges = nullptr;
};
