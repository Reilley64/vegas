#include "fnv/memory/engine_heap_set.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace fnv::memory {
void EngineHeapSet::ReleaseHeaps() noexcept
{
    initialized_ = false;
    for (auto& context : contexts_) context = EngineHeapDomain::None;
    context23_.Shutdown();
    auxiliary_.Shutdown();
    main_.Shutdown();
}

bool EngineHeapSet::Initialize() noexcept
{
    LockGuard guard(lock_);
    if (initialized_) return true;
    // Exact heap families and capacities from appmemory_console::00866e00.
    // Native metadata and pointer alignment replace the PC byte-layout clear.
    if (!main_.Initialize(0xc800000, 0x5500000, "Main") ||
        !auxiliary_.Initialize(0x183800) ||
        !context23_.Initialize(0x4000000, 0x200000, "Context 23")) {
        ReleaseHeaps();
        return false;
    }
    for (auto& context : contexts_) context = EngineHeapDomain::None;
    contexts_[65] = EngineHeapDomain::Main;
    contexts_[0] = contexts_[3] = contexts_[9] = EngineHeapDomain::Auxiliary;
    contexts_[23] = EngineHeapDomain::Context23;
    initialized_ = true;
    return true;
}

bool EngineHeapSet::IsInitialized() noexcept
{
    LockGuard guard(lock_);
    return initialized_;
}

void* EngineHeapSet::AllocateLocked(std::size_t bytes, int context) noexcept
{
    // The source arena encodes size in 28 bits. Reject before alignment or any
    // legacy unsigned boundary; an oversized request must never wrap small.
    if (!initialized_ || bytes > 0x0ffffff0) return nullptr;
    bytes = (std::max(bytes, std::size_t(8)) + 3) & ~std::size_t(3);
    const auto selected = context >= 0 && context < 66 ? contexts_[context] : EngineHeapDomain::None;
    void* memory = nullptr;
    if (selected == EngineHeapDomain::Auxiliary) memory = auxiliary_.Allocate(bytes);
    else if (selected == EngineHeapDomain::Context23) memory = context23_.Allocate(bytes);
    // 00aa3e40 retries the main heap if a selected heap cannot allocate. Context
    // 36 has no dedicated mapping and uses this same default path immediately.
    return memory ? memory : main_.Allocate(bytes);
}

void* EngineHeapSet::Allocate(std::size_t bytes, int context) noexcept
{
    LockGuard guard(lock_);
    return AllocateLocked(bytes, context);
}

EngineHeapDomain EngineHeapSet::OwnerLocked(const void* memory) noexcept
{
    if (!memory || !initialized_) return EngineHeapDomain::None;
    if (main_.Size(memory)) return EngineHeapDomain::Main;
    if (context23_.Size(memory)) return EngineHeapDomain::Context23;
    if (auxiliary_.Size(memory)) return EngineHeapDomain::Auxiliary;
    return EngineHeapDomain::None;
}

EngineHeapDomain EngineHeapSet::OwnerOf(const void* memory) noexcept
{
    LockGuard guard(lock_);
    return OwnerLocked(memory);
}

std::size_t EngineHeapSet::SizeLocked(const void* memory) noexcept
{
    if (!initialized_ || !memory) return 0;
    if (const auto bytes = main_.Size(memory)) return bytes;
    if (const auto bytes = context23_.Size(memory)) return bytes;
    return auxiliary_.Size(memory);
}

std::size_t EngineHeapSet::Size(const void* memory) noexcept
{
    LockGuard guard(lock_);
    return SizeLocked(memory);
}

void EngineHeapSet::DeallocateLocked(void* memory) noexcept
{
    if (!memory) return;
    switch (OwnerLocked(memory)) {
    case EngineHeapDomain::Main: main_.Deallocate(memory); return;
    case EngineHeapDomain::Context23: context23_.Deallocate(memory); return;
    case EngineHeapDomain::Auxiliary: auxiliary_.Deallocate(memory); return;
    case EngineHeapDomain::None: std::abort();
    }
}

void EngineHeapSet::Deallocate(void* memory) noexcept
{
    LockGuard guard(lock_);
    DeallocateLocked(memory);
}

void* EngineHeapSet::Reallocate(void* memory, std::size_t bytes, int context) noexcept
{
    LockGuard guard(lock_);
    if (!memory) return AllocateLocked(bytes, context);
    const auto oldBytes = SizeLocked(memory);
    if (!oldBytes) return nullptr;
    if (!bytes) { DeallocateLocked(memory); return nullptr; }
    auto* replacement = AllocateLocked(bytes, context);
    if (!replacement) return nullptr;
    std::memmove(replacement, memory, std::min(oldBytes, bytes));
    DeallocateLocked(memory);
    return replacement;
}

HeapStatistics EngineHeapSet::Statistics(EngineHeapDomain domain) noexcept
{
    LockGuard guard(lock_);
    switch (domain) {
    case EngineHeapDomain::Main: return main_.Statistics();
    case EngineHeapDomain::Context23: return context23_.Statistics();
    case EngineHeapDomain::Auxiliary: return auxiliary_.Statistics();
    case EngineHeapDomain::None: return {};
    }
    return {};
}

bool EngineHeapSet::CheckIntegrity() noexcept
{
    LockGuard guard(lock_);
    return main_.CheckIntegrity() && auxiliary_.CheckIntegrity() && context23_.CheckIntegrity();
}

void EngineHeapSet::Shutdown() noexcept
{
    LockGuard guard(lock_);
    ReleaseHeaps();
}
}
