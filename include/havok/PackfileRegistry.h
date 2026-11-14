#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <span>
#include <cstddef>

class hkClass;
namespace havok::native_memory { class Allocator; }
#include <string>
#include <utility>
#include <vector>

// Native type metadata is borrowed, never confused with a finished object.
// Its owner must outlive registries and loaded resources referring to it.
// Cleanup must not throw. A throwing finish owns its own partial construction.
struct hkEntryD479
{
    const char* name = nullptr;
    std::function<void(void*, int)> m_func;
    std::function<void(void*)> cleanup;
    const void* vtable = nullptr;
    int size = 0;
    const void* auxiliary = nullptr;
    // Explicit opt-in from a complete, genuine native type contract. Recorded
    // size and generated callback declarations do not establish native layout.
    std::size_t nativeSize = 0;
    std::size_t nativeAlignment = 0;
    // Optional separate allocating decoder for a source-proved serialized
    // representation. Never invoke the in-place legacy callback on wire bytes.
    std::function<std::shared_ptr<void>(std::span<const std::byte>, int,
        std::shared_ptr<havok::native_memory::Allocator>)> materialize{};
    const hkClass* nativeClass = nullptr;
    std::shared_ptr<const void> nativeClassStorage{};
    template<class Object> void SetNativeLayout() noexcept
    {
        nativeSize = sizeof(Object);
        nativeAlignment = alignof(Object);
    }
};

namespace havok::serialize
{
struct RegistryBase
{
    virtual ~RegistryBase() = default;
    virtual void AddReference() noexcept = 0;
    virtual void ReleaseReference() noexcept = 0;
    unsigned short allocationSize = 0;
    unsigned short references = 1;
};
struct StringMapState
{
    std::vector<std::pair<std::string, hkEntryD479*>> entries;
    hkEntryD479* Lookup(const char*) const noexcept;
    void Insert(const char*, hkEntryD479*);
    void clear() noexcept { entries.clear(); }
};
// This is also the actual hkserializeutil caller's TypeRegistry. It is not a
// view onto another registry, nor an unrelated legacy string-map protocol.
}

struct hkObjD479 : havok::serialize::RegistryBase
{
    explicit hkObjD479(int flag = 1) noexcept : finish(flag) {}
    havok::serialize::StringMapState types;
    int finish;
    void AddReference() noexcept override;
    void ReleaseReference() noexcept override;
    virtual void Register(hkEntryD479*);
    virtual hkEntryD479* FindEntryAndCall(void*, void*);
    virtual void* FUN_00d47940(void*, intptr_t);
    virtual void Import(const hkObjD479&);
    virtual void* FUN_00d479e0(const void*) const noexcept;
    void clear() noexcept { types.clear(); }
};
namespace havok::serialize
{
using TypeRegistry = hkObjD479;
TypeRegistry& DefaultPackfileRegistry() noexcept;
}

int PackfileRegistryFinishing(void*) noexcept;
const void* PackfileRegistryTypeInfo(void*, const char*);
