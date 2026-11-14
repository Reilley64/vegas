#include "havok/PackfileRegistry.h"
#include "havok/BuiltinTypeRegistry.h"
#include <algorithm>
#include <stdexcept>
#include <limits>

namespace
{
havok::serialize::TypeRegistry& FallbackRegistry() noexcept
{
    static havok::serialize::TypeRegistry registry(1);
    return registry;
}
}
havok::serialize::TypeRegistry& havok::serialize::DefaultPackfileRegistry() noexcept
{
    auto* registry = GlobalTypeRegistry();
    return registry ? *registry : FallbackRegistry();
}

hkEntryD479* havok::serialize::StringMapState::Lookup(const char* name) const noexcept
{
    if (!name) return nullptr;
    auto it = std::find_if(entries.begin(), entries.end(),
        [&](const auto& entry) { return entry.first == name; });
    return it == entries.end() ? nullptr : it->second;
}
void havok::serialize::StringMapState::Insert(const char* name, hkEntryD479* metadata)
{
    if (!name || !metadata) throw std::invalid_argument("invalid registry entry");
    for (auto& entry : entries)
        if (entry.first == name) { entry.second = metadata; return; }
    entries.emplace_back(name, metadata);
}
void hkObjD479::AddReference() noexcept
{
    // Same bounded-retain policy as class/vtable/builtin registry owners.
    // Wrapping or saturation would lose the number of outstanding leases.
    if (references == std::numeric_limits<unsigned short>::max()) std::terminate();
    ++references;
}
void hkObjD479::ReleaseReference() noexcept
{
    // The process registry is source-owned static storage, not a heap object.
    if (this == &FallbackRegistry())
    {
        if (references > 1) --references;
        return;
    }
    if (--references == 0) delete this;
}
void hkObjD479::Register(hkEntryD479* metadata)
{
    if (!metadata) throw std::invalid_argument("null registry metadata");
    types.Insert(metadata->name, metadata);
}
void hkObjD479::Import(const hkObjD479& source)
{
    if (this == &source) return;
    // Preserve the destination's exact finishing state. Build before swapping
    // so allocation failure cannot leave a partially imported registry.
    auto merged = types;
    for (const auto& entry : source.types.entries)
        merged.Insert(entry.first.c_str(), entry.second);
    types.entries.swap(merged.entries);
}
const void* PackfileRegistryTypeInfo(void* registry, const char* name)
{
    return registry ? static_cast<hkObjD479*>(registry)->types.Lookup(name) : nullptr;
}
int PackfileRegistryFinishing(void* registry) noexcept
{
    return static_cast<hkObjD479*>(registry)->finish;
}
// Genuine legacy finishing is distinct from native allocating materialization.
// @fnv 0x00d47900
hkEntryD479* hkObjD479::FindEntryAndCall(void* object, void* name)
{
    auto* metadata = types.Lookup(static_cast<const char*>(name));
    if (metadata && metadata->m_func) metadata->m_func(object, finish);
    return metadata;
}
// @fnv 0x00d479e0
void* hkObjD479::FUN_00d479e0(const void* name) const noexcept
{
    return types.Lookup(static_cast<const char*>(name));
}
// @fnv 0x00d47940
void* hkObjD479::FUN_00d47940(void* object, intptr_t name)
{
    auto* metadata = types.Lookup(reinterpret_cast<const char*>(name));
    if (metadata && metadata->cleanup) metadata->cleanup(object);
    return metadata;
}
