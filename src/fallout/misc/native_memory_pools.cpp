#include "fnv/decl/MemoryManager.h"
#include "AutoMemContext.h"

#include <algorithm>
#include <cstring>
#include <iterator>
#include <new>

namespace {
struct PoolConfiguration {
    unsigned int blockBytes;
    unsigned int reserveBytes;
    const char* name;
};

// Source 00866770 order, sizes, capacities, and names. This table describes
// values; the actual producer below still calls CreateMemoryPool for every
// family on its own receiver.
constexpr PoolConfiguration PoolConfigurations[] = {
    {8, 0x600000, "Pool 8"}, {12, 0x500000, "Pool 12"},
    {16, 0x400000, "Pool 16"}, {20, 0x400000, "Pool 20"},
    {24, 0x800000, "Pool 24"}, {28, 0x400000, "Pool 28"},
    {32, 0x800000, "Pool 32"}, {36, 0x300000, "Pool 36"},
    {40, 0x200000, "Pool 40"}, {44, 0x400000, "Pool 44"},
    {48, 0x200000, "Pool 48"}, {52, 0x300000, "Pool 52"},
    {56, 0x100000, "Pool 56"}, {64, 0x200000, "Pool 64"},
    {72, 0xd00000, "Pool 72"}, {76, 0x100000, "Pool 76"},
    {80, 0x300000, "Pool 80"}, {92, 0x200000, "Pool 92"},
    {96, 0xf00000, "Pool 96"}, {100, 0x100000, "Pool 100"},
    {104, 0x400000, "Pool 104"}, {120, 0x400000, "Pool 120"},
    {128, 0x100000, "Pool 128"}, {160, 0x200000, "Pool 160"},
    {192, 0x200000, "Pool 192"}, {200, 0x300000, "Pool 200"},
    {208, 0x300000, "Pool 208"}, {240, 0x300000, "Pool 240"},
    {256, 0x100000, "Pool 256"}, {272, 0x200000, "Pool 272"},
    {288, 0x300000, "Pool 288"}, {400, 0x100000, "Pool 400"},
    {448, 0x100000, "Pool 448"}, {480, 0x400000, "Pool 480"},
    {508, 0x400000, "Pool 508"}, {576, 0x200000, "Pool 576"},
    {596, 0x100000, "Pool 596"},
};
static_assert(std::size(PoolConfigurations) == 37);
} // namespace

bool MemoryManager::BeginPoolStartup()
{
    if (!HeapsInitialized())
        throw std::bad_alloc();
    std::lock_guard guard(poolLock_);
    if (poolsPublished_)
        return false;
    // A caller that stopped after direct CreateMemoryPool staging did not
    // publish anything. Retire that partial transaction before a full retry.
    if (poolStartupActive_)
        RetirePoolsLocked();
    poolStartupActive_ = true;
    return true;
}

void MemoryManager::CompletePoolStartup()
{
    std::lock_guard guard(poolLock_);
    if (!poolStartupActive_ || stagedPoolCount_ != FixedPoolCount) {
        RetirePoolsLocked();
        throw std::bad_alloc();
    }
    // The allocation route becomes visible only after every owner is live.
    poolsPublished_ = true;
    poolStartupActive_ = false;
}

void MemoryManager::CancelPoolStartup() noexcept
{
    std::lock_guard guard(poolLock_);
    RetirePoolsLocked();
}

void MemoryManager::RetirePoolsLocked() noexcept
{
    poolsPublished_ = false;
    poolStartupActive_ = false;
    stagedPoolCount_ = 0;
    for (auto& pool : pools_)
        pool.Shutdown();
}

// @fnv 0x00866770
void MemoryManager::FUN_00866770()
{
    std::lock_guard startupGuard(poolStartupLock_);
    if (!BeginPoolStartup())
        return;
    try {
        for (const auto& configuration : PoolConfigurations) {
            CreateMemoryPoolStaged(configuration.blockBytes, configuration.reserveBytes,
                                   const_cast<char*>(configuration.name));
        }
        CompletePoolStartup();
    } catch (...) {
        CancelPoolStartup();
        throw;
    }
}

// @fnv 0x00aa3cc0
void MemoryManager::CreateMemoryPool(unsigned int blockBytes,
                                     unsigned int reserveBytes, char* description)
{
    std::lock_guard startupGuard(poolStartupLock_);
    CreateMemoryPoolStaged(blockBytes, reserveBytes, description);
}

void MemoryManager::CreateMemoryPoolStaged(unsigned int blockBytes,
                                           unsigned int reserveBytes, char* description)
{
    AutoMemContext poolContext(3);
    const bool heapsReady = HeapsInitialized();
    std::lock_guard guard(poolLock_);
    // Direct source-entry use may stage the first family, but only the complete
    // FUN_00866770 transaction can publish allocation routing.
    if (!poolStartupActive_) {
        if (!heapsReady || poolsPublished_ || stagedPoolCount_ != 0 ||
            blockBytes != PoolConfigurations[0].blockBytes ||
            reserveBytes != PoolConfigurations[0].reserveBytes || !description ||
            std::strcmp(description, PoolConfigurations[0].name) != 0)
            throw std::bad_alloc();
        poolStartupActive_ = true;
    }
    if (stagedPoolCount_ >= FixedPoolCount) {
        RetirePoolsLocked();
        throw std::bad_alloc();
    }
    const auto& expected = PoolConfigurations[stagedPoolCount_];
    if (blockBytes != expected.blockBytes || reserveBytes != expected.reserveBytes ||
        !description || std::strcmp(description, expected.name) != 0 ||
        !pools_[stagedPoolCount_].Initialize(blockBytes, reserveBytes, expected.name)) {
        RetirePoolsLocked();
        throw std::bad_alloc();
    }
    ++stagedPoolCount_;
}

fnv::memory::FixedPool* MemoryManager::SelectPoolLocked(unsigned int requested) noexcept
{
    auto size = std::max(requested, 8u);
    size = (size + 3u) & ~3u;
    auto find = [&](unsigned int blockBytes) -> fnv::memory::FixedPool* {
        for (std::size_t index = 0; index < FixedPoolCount; ++index)
            if (PoolConfigurations[index].blockBytes == blockBytes)
                return &pools_[index];
        return nullptr;
    };

    if (auto* exact = find(size))
        return exact;
    if (size < 0x12c)
        return find((size + 15u) & ~15u);
    if (size < 0x200) {
        if (auto* pool = find((size + 15u) & ~15u))
            return pool;
        return find((size + 31u) & ~31u);
    }
    return size < 0x240 ? find(0x240) : nullptr;
}

void* MemoryManager::AllocateFromPools(unsigned int requested) noexcept
{
    std::lock_guard guard(poolLock_);
    if (!poolsPublished_)
        return nullptr;
    auto* pool = SelectPoolLocked(requested);
    return pool ? pool->Allocate() : nullptr;
}

std::size_t MemoryManager::PoolSize(const void* memory) noexcept
{
    std::lock_guard guard(poolLock_);
    if (!poolsPublished_)
        return 0;
    for (auto& pool : pools_)
        if (const auto bytes = pool.Size(memory))
            return bytes;
    return 0;
}

bool MemoryManager::ReleasePoolOwned(void* memory) noexcept
{
    std::lock_guard guard(poolLock_);
    if (!poolsPublished_)
        return false;
    for (auto& pool : pools_) {
        if (!pool.ContainsAddress(memory))
            continue;
        return pool.Deallocate(memory);
    }
    return false;
}

bool MemoryManager::PoolsInitialized() noexcept
{
    std::lock_guard guard(poolLock_);
    return poolsPublished_;
}

fnv::memory::FixedPoolStatistics MemoryManager::PoolStatistics(std::size_t index) noexcept
{
    std::lock_guard guard(poolLock_);
    return index < FixedPoolCount ? pools_[index].Statistics()
                                  : fnv::memory::FixedPoolStatistics{};
}

std::size_t MemoryManager::PoolOwnerIndex(const void* memory) noexcept
{
    std::lock_guard guard(poolLock_);
    if (!poolsPublished_)
        return FixedPoolCount;
    for (std::size_t index = 0; index < FixedPoolCount; ++index)
        if (pools_[index].Size(memory))
            return index;
    return FixedPoolCount;
}
