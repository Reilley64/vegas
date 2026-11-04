#include "runtime/havok_memory_prerequisite.h"

#include <cstdint>
#include <cstdlib>
#include <limits>
#include <new>

namespace havok::native_memory
{
namespace
{
struct Header
{
    void* raw;
    std::size_t bytes;
};
constexpr std::size_t alignment = 16;
}

void* AlignedAllocator::Allocate(std::size_t bytes)
{
    constexpr std::size_t overhead = sizeof(Header) + alignment - 1;
    if (!bytes || bytes > std::numeric_limits<std::size_t>::max() - overhead)
        return nullptr;
    void* raw = std::malloc(bytes + overhead);
    if (!raw)
        return nullptr;
    auto address = reinterpret_cast<std::uintptr_t>(raw) + sizeof(Header);
    address = (address + alignment - 1) & ~(alignment - 1);
    auto* block = reinterpret_cast<void*>(address);
    ::new (static_cast<char*>(block) - sizeof(Header)) Header{raw, bytes};
    return block;
}

void AlignedAllocator::Free(void* block, std::size_t bytes) noexcept
{
    if (!block)
        return;
    auto* header = reinterpret_cast<Header*>(static_cast<char*>(block) - sizeof(Header));
    if (header->bytes != bytes)
        std::abort();
    std::free(header->raw);
}

Router::~Router()
{
    if (owner)
        std::abort();
}

Allocator& Router::heap() const noexcept
{
    if (!allocator)
        std::abort();
    return *allocator;
}

void* Router::AllocateStack(std::size_t bytes) noexcept
{
    if (!stack || !bytes)
        return nullptr;
    const std::size_t padding = (alignment - cursor % alignment) % alignment;
    if (padding > stackBytes - cursor || bytes > stackBytes - cursor - padding)
        return nullptr;
    cursor += padding;
    auto* result = static_cast<char*>(stack) + cursor;
    cursor += bytes;
    return result;
}

Router::StackScope::StackScope(Router& router) noexcept
    : router(router), previous(router.scope), saved(router.cursor)
{
    if (!router.IsInitialized())
        std::abort();
    router.scope = this;
}

Router::StackScope::~StackScope()
{
    if (router.scope != this)
        std::abort();
    router.cursor = saved;
    router.scope = previous;
}

System::System(Allocator& allocator, ScratchBytes workerScratch) noexcept
    : allocator(allocator), workerScratch(workerScratch) {}

System::~System()
{
    for (const auto& record : records)
        if (record.occupied)
            std::abort();
}

bool System::Reserve(Router& router)
{
    if (router.IsInitialized())
        return false;
    std::lock_guard lock(mutex);
    std::size_t index = 0;
    while (index < records.size() && records[index].occupied)
        ++index;
    if (index == records.size())
        return false;
    records[index].occupied = true;
    router.owner = this;
    router.allocator = &allocator;
    router.slot = index;
    return true;
}

bool System::Initialize(Router& router)
{
    if (!Reserve(router))
        return false;
    try
    {
        if (workerScratch.value)
        {
            router.stack = allocator.Allocate(workerScratch.value);
            if (!router.stack)
            {
                Quit(router);
                return false;
            }
            router.stackBytes = workerScratch.value;
            router.ownsStack = true;
        }
    }
    catch (...)
    {
        Quit(router);
        throw;
    }
    return true;
}

bool System::InitializeBorrowed(Router& router, void* stack, std::size_t bytes)
{
    const auto address = reinterpret_cast<std::uintptr_t>(stack);
    if (!stack || !bytes || address % alignment || bytes > std::numeric_limits<std::uintptr_t>::max() - address)
        return false;
    if (!Reserve(router))
        return false;
    router.stack = stack;
    router.stackBytes = bytes;
    return true;
}

void System::Cleanup(Router& router, bool releaseRecord) noexcept
{
    if (!router.owner)
        return;
    if (router.owner != this || router.scope)
        std::abort();
    if (router.ownsStack)
        allocator.Free(router.stack, router.stackBytes);
    router.stack = nullptr;
    router.stackBytes = 0;
    router.cursor = 0;
    router.ownsStack = false;
    if (releaseRecord)
    {
        std::lock_guard lock(mutex);
        if (router.slot >= records.size() || !records[router.slot].occupied)
            std::abort();
        records[router.slot].occupied = false;
        router.owner = nullptr;
        router.allocator = nullptr;
        router.slot = 0;
    }
}

void System::ReleaseScratch(Router& router) noexcept { Cleanup(router, false); }
void System::Quit(Router& router) noexcept { Cleanup(router, true); }
}
