#include "havok/hkReferencedObject.h"
#include "havok/hkMemoryRouter.h"
#include "runtime/havok_memory_prerequisite.h"

#include <atomic>
#include <cstdlib>
#include <limits>
#include <new>

namespace
{
// Native allocation bookkeeping, never an original-release object prefix.
// A pending allocation is consumed by its base constructor, so stack objects
// never read bytes before their storage or inherit an uninitialized heap flag.
struct alignas(16) Allocation
{
    hkMemoryAllocator* allocator;
    std::shared_ptr<havok::native_memory::Allocator> supplier;
    int bytes;
    hkUint16 objectBytes;
    Allocation* next;
};
thread_local Allocation* pending = nullptr;

Allocation* TakePending(void* object) noexcept
{
    for (Allocation** entry = &pending; *entry; entry = &(*entry)->next)
        if (*entry + 1 == object)
        {
            Allocation* result = *entry;
            *entry = result->next;
            return result;
        }
    return nullptr;
}

void* Allocate(std::size_t bytes, hkMemoryAllocator* heap,
               std::shared_ptr<havok::native_memory::Allocator> supplier)
{
    if (bytes > std::numeric_limits<hkUint16>::max() ||
        bytes > std::size_t(std::numeric_limits<int>::max()) - sizeof(Allocation))
        throw std::bad_alloc();
    const int extent = static_cast<int>(bytes + sizeof(Allocation));
    void* storage = supplier ? supplier->Allocate(extent) : heap->blockAlloc(extent);
    if (!storage)
        throw std::bad_alloc();
    auto* allocation = ::new (storage) Allocation{heap, std::move(supplier), extent,
                                                 static_cast<hkUint16>(bytes), pending};
    pending = allocation;
    return allocation + 1;
}
}

// The base destructor has no resources (formerly defined in hkxenvironment.cpp).
hkBaseObject::~hkBaseObject() = default;

hkReferencedObject::hkReferencedObject() noexcept : m_usMemSizeAndFlags(0), m_sReferenceCount(1)
{
    if (auto* allocation = TakePending(this))
        m_usMemSizeAndFlags = allocation->objectBytes;
}

void* hkReferencedObject::operator new(std::size_t bytes)
{
    return Allocate(bytes, &hkMemoryRouter::getInstance().heap(), {});
}

void* hkReferencedObject::operator new(std::size_t bytes,
                                     std::shared_ptr<havok::native_memory::Allocator> supplier)
{
    if (!supplier)
        throw std::bad_alloc();
    return Allocate(bytes, nullptr, std::move(supplier));
}

void hkReferencedObject::operator delete(void* object,
                                       std::shared_ptr<havok::native_memory::Allocator>) noexcept
{
    hkReferencedObject::operator delete(object);
}

void hkReferencedObject::operator delete(void* object) noexcept
{
    if (!object)
        return;
    // Also removes a pending record when evaluating constructor arguments throws.
    TakePending(object);
    auto* allocation = static_cast<Allocation*>(object) - 1;
    auto* allocator = allocation->allocator;
    auto supplier = std::move(allocation->supplier);
    const int bytes = allocation->bytes;
    allocation->~Allocation();
    if (supplier)
        supplier->Free(allocation, bytes);
    else
        allocator->blockFree(allocation, bytes);
}

void hkReferencedObject::addReference() const noexcept
{
    if (!m_usMemSizeAndFlags)
        return;
    std::atomic_ref<hkInt16> count(m_sReferenceCount);
    hkInt16 previous = count.load(std::memory_order_relaxed);
    do
    {
        if (previous <= 0 || previous == std::numeric_limits<hkInt16>::max())
            std::abort();
    } while (!count.compare_exchange_weak(previous, static_cast<hkInt16>(previous + 1),
                                         std::memory_order_relaxed));
}

void hkReferencedObject::removeReference() const noexcept
{
    if (!m_usMemSizeAndFlags)
        return;
    std::atomic_ref<hkInt16> count(m_sReferenceCount);
    const hkInt16 previous = count.fetch_sub(1, std::memory_order_acq_rel);
    if (previous <= 0)
        std::abort();
    if (previous == 1)
        delete this;
}
