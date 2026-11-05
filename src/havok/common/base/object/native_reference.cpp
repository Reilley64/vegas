#include "havok/hkBaseSystem.h"

#include <cstdlib>
#include <limits>

namespace havok::base
{
void Reference::AddReference()
{
    const int previous = references.fetch_add(1, std::memory_order_relaxed);
    if (previous <= 0 || previous == std::numeric_limits<int>::max())
        std::abort();
}
void Reference::RemoveReference()
{
    const int previous = references.fetch_sub(1, std::memory_order_acq_rel);
    if (previous <= 0)
        std::abort();
    if (previous == 1)
        Destroy();
}
void* AllocatorResource::do_allocate(std::size_t bytes, std::size_t alignment)
{
    if (alignment > 16 || bytes > static_cast<std::size_t>(std::numeric_limits<int>::max()))
        throw std::bad_alloc();
    void* result = allocator.blockAlloc(static_cast<int>(bytes));
    if (!result)
        throw std::bad_alloc();
    return result;
}
void AllocatorResource::do_deallocate(void* memory, std::size_t bytes, std::size_t)
{
    allocator.blockFree(memory, static_cast<int>(bytes));
}
}
