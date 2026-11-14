// Shared native reference-counted base; not a serialized object layout.
#ifndef FNV_HAVOK_HKREFERENCEDOBJECT_H
#define FNV_HAVOK_HKREFERENCEDOBJECT_H
#include "hkBase.h"
#include <cstddef>
#include <memory>
namespace havok::native_memory { class Allocator; }
class hkReferencedObject : public hkBaseObject
{
  public:
    hkReferencedObject() noexcept;
    hkReferencedObject(const hkReferencedObject&) = delete;
    hkReferencedObject& operator=(const hkReferencedObject&) = delete;
    // Heap objects start with one owned reference. Stack/placement objects
    // retain the source's zero-flag, non-deleting reference behavior.
    // Fresh heap construction uses the published router. Its supplying heap
    // must outlive the allocation; final release needs no published router.
    void addReference() const noexcept;
    void removeReference() const noexcept;
    static void* operator new(std::size_t);
    // Materialized packfile objects use their existing owning supplier, without
    // requiring router TLS. The allocation retains it through the final Free.
    static void* operator new(std::size_t, std::shared_ptr<havok::native_memory::Allocator>);
    static void operator delete(void*, std::shared_ptr<havok::native_memory::Allocator>) noexcept;
    static void operator delete(void*) noexcept;
    static void* operator new(std::size_t, void* storage) noexcept { return storage; }
    static void operator delete(void*, void*) noexcept {}

    hkUint16 m_usMemSizeAndFlags;
    mutable hkInt16 m_sReferenceCount;
};
#endif
