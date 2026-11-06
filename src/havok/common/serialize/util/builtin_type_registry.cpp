#include "havok/BuiltinTypeRegistry.h"
#include "fnv/decl/FUN_00d472a0.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include <cstring>
#include <limits>
#include <memory>
#include <stdexcept>

// Canonical native storage. The generated placeholder definitions are retired
// by the corresponding source-ownership registration, not aliased as objects.
std::intptr_t DAT_01269b10 = 0;
std::intptr_t DAT_01269b14 = 0;
std::intptr_t DAT_01269b18 = 0;

// The retained source constructor writes name, parent, object extent,
// implemented-interface count, enum/member arrays, defaults, attributes,
// flags and version, skipping its unused fourth argument. Construct those
// exact hkClass fields rather than writing 12 words into an 11-word array.
// @fnv 0x00d472a0
FUN_00d472a0::FUN_00d472a0(char* name, hkClass* parent, int objectSize,
    const void*, int interfaces, hkClassEnum* enums, int enumCount,
    hkClassMember* members, int memberCount, void* defaults,
    hkCustomAttributes* attributes, unsigned int flags, int version)
{
    m_name = name;
    m_parent = parent;
    m_iObjectSize = objectSize;
    m_iNumImplementedInterfaces = interfaces;
    m_kDeclaredEnums = {enums, enumCount};
    m_kDeclaredMembers = {members, memberCount};
    m_pDefaultObject = defaults;
    m_pCustomAttributes = attributes;
    m_flags = flags;
    m_iDescribedVersion = version;
}

namespace
{
havok::serialize::BuiltinCatalog catalog;

void Retain(havok::serialize::RegistryBase& owner) noexcept
{
    if (owner.references == std::numeric_limits<unsigned short>::max()) std::terminate();
    ++owner.references;
}
void ValidateClass(const hkClass* descriptor)
{
    if (!descriptor || !descriptor->m_name || descriptor->m_iObjectSize < 0)
        throw std::invalid_argument("invalid native class descriptor");
    // The source count provider follows parents and sums interface counts.
    // Validate that same graph without treating a metadata pointer as a class.
    auto* slow = descriptor;
    auto* fast = descriptor;
    while (fast && fast->m_parent)
    {
        slow = slow->m_parent;
        fast = fast->m_parent->m_parent;
        if (slow == fast) throw std::invalid_argument("cyclic class parent chain");
    }
    for (auto* current = descriptor; current; current = current->m_parent)
        if (current->m_iNumImplementedInterfaces < 0)
            throw std::invalid_argument("invalid class interface count");
}
bool HasInterfaces(const hkClass* descriptor) noexcept
{
    for (; descriptor; descriptor = descriptor->m_parent)
        if (descriptor->m_iNumImplementedInterfaces) return true;
    return false;
}
hkVtableClassRegistry* GlobalVtables() noexcept
{
    return reinterpret_cast<hkVtableClassRegistry*>(DAT_01269b10);
}
void RequireGlobals()
{
    if (!havok::serialize::GlobalClassRegistry() || !havok::serialize::GlobalTypeRegistry() || !GlobalVtables())
        throw std::logic_error("builtin registries are not initialized");
}
}
namespace havok::serialize
{
ClassNameRegistry* GlobalClassRegistry() noexcept { return reinterpret_cast<ClassNameRegistry*>(DAT_01269b14); }
TypeRegistry* GlobalTypeRegistry() noexcept { return reinterpret_cast<TypeRegistry*>(DAT_01269b18); }
void ClassNameRegistry::AddReference() noexcept { Retain(*this); }
void ClassNameRegistry::ReleaseReference() noexcept { if (--references == 0) delete this; }
void ClassNameRegistry::RegisterClass(const hkClass* descriptor)
{
    ValidateClass(descriptor);
    for (auto& entry : classes)
        if (entry.first == descriptor->m_name)
        {
            const auto* displaced = entry.second;
            entry.second = descriptor;
            bool visible = false;
            for (const auto& current : classes) if (current.second == displaced) visible = true;
            if (!visible)
            {
                for (auto lease = leases.begin(); lease != leases.end(); )
                    if (lease->first == displaced) lease = leases.erase(lease);
                    else ++lease;
            }
            return;
        }
    classes.emplace_back(descriptor->m_name, descriptor);
}
void ClassNameRegistry::RegisterClass(const hkClass* descriptor, std::shared_ptr<const void> storage)
{
    if (!storage) throw std::invalid_argument("missing class storage lease");
    auto next = *this;
    next.RegisterClass(descriptor);
    // An explicit lease replaces that identity's previous lease, including a
    // same-pointer refresh. All changes remain staged until publication.
    for (auto lease = next.leases.begin(); lease != next.leases.end(); )
        if (lease->first == descriptor) lease = next.leases.erase(lease);
        else ++lease;
    next.leases.emplace_back(descriptor, std::move(storage));
    SwapContents(next);
}
std::shared_ptr<const void> ClassNameRegistry::Storage(const hkClass* descriptor) const noexcept
{
    for (const auto& entry : leases) if (entry.first == descriptor) return entry.second;
    return {};
}
const hkClass* ClassNameRegistry::Find(const char* name) const noexcept
{
    if (name) for (const auto& entry : classes) if (entry.first == name) return entry.second;
    return nullptr;
}
void SetBuiltinCatalog(BuiltinCatalog source)
{
    // This is borrowed source-owned data, not deserialized native addresses.
    // Validate class identities before making the catalogue visible.
    if (source.classDescriptor) ValidateClass(source.classDescriptor);
    for (auto* descriptor : source.classes)
    {
        if (!descriptor) break;
        ValidateClass(descriptor);
    }
    catalog = source;
}
BuiltinCatalogStatus GetBuiltinCatalogStatus() noexcept
{
    return catalog.classDescriptor ? BuiltinCatalogStatus::ClassDescriptorsProvided : BuiltinCatalogStatus::MissingClassDescriptors;
}
void ShutdownBuiltinRegistries() noexcept
{
    auto* classes = GlobalClassRegistry();
    auto* types = GlobalTypeRegistry();
    auto* vtables = GlobalVtables();
    DAT_01269b14 = DAT_01269b18 = DAT_01269b10 = 0;
    if (classes) classes->ReleaseReference();
    if (types) types->ReleaseReference();
    if (vtables) vtables->ReleaseReference();
}
}
void FUN_00db78a0_cls::AddReference() noexcept { Retain(*this); }
void FUN_00db78a0_cls::ReleaseReference() noexcept { if (--references == 0) delete this; }
void FUN_00db78a0_cls::RegisterLink(const void* identity, const hkClass* descriptor)
{
    ValidateClass(descriptor);
    if (!identity) return;
    for (auto& entry : entries)
        if (entry.first == identity) { entry.second = descriptor; return; }
    entries.emplace_back(identity, descriptor);
}
const hkClass* FUN_00db78a0_cls::FindVtable(const void* identity) const noexcept
{
    for (const auto& entry : entries) if (entry.first == identity) return entry.second;
    return nullptr;
}
// @fnv 0x00db78a0
void FUN_00db78a0_cls::FUN_00db78a0(void* const* items, const hkClass* const* values)
{
    if (!items) throw std::invalid_argument("missing metadata table");
    // Preserve the leading-null short circuit without reading a missing value
    // table. Callers of this legacy entry provide null-terminated arrays.
    for (; *items; ++items, ++values)
    {
        if (!values) throw std::invalid_argument("missing class table");
        if (!*values) break;
        RegisterLink(static_cast<Agg6*>(*items)->Metadata()->vtable, *values);
    }
}
void FUN_00db78a0_cls::RegisterTables(std::span<void* const> items, std::span<const hkClass* const> values)
{
    for (std::size_t i = 0; i < items.size() && items[i]; ++i)
    {
        if (i >= values.size()) throw std::invalid_argument("incomplete builtin class table");
        if (!values[i]) break;
        RegisterLink(static_cast<Agg6*>(items[i])->Metadata()->vtable, values[i]);
    }
}
const hkClass* hkVtableClassRegistry::LookupObject(const void* object) const noexcept
{
    if (!object) return nullptr;
    // Copy only the native identity word from a source-owned polymorphic
    // object. Never read slots of a compiler vtable as a legacy protocol.
    const void* identity;
    std::memcpy(&identity, object, sizeof(identity));
    return FindVtable(identity);
}
// @fnv 0x00d477a0
void* ReferencedObjectHolder::FUN_00d477a0()
{
    auto* registry = GlobalVtables();
    return registry ? const_cast<hkClass*>(registry->LookupObject(m_pObject)) : nullptr;
}
// @fnv 0x00d47c40
std::uintptr_t hkVtableClassRegistry::LookupClassByVtable(const unsigned long* object)
{
    return reinterpret_cast<std::uintptr_t>(LookupObject(object));
}
// @fnv 0x00d47a00
std::intptr_t FUN_00d47a00() { return DAT_01269b18; }
// @fnv 0x00d47a10
std::intptr_t FUN_00d47a10() { return DAT_01269b14; }
// @fnv 0x00d47a20
std::intptr_t FUN_00d47a20() { return DAT_01269b10; }
// @fnv 0x00d477c0
void RegisterInputSource(Agg6* input, const hkClass* source)
{
    RequireGlobals();
    if (!input) throw std::invalid_argument("missing input source");
    ValidateClass(source);
    auto* metadata = input->Metadata();
    auto* names = havok::serialize::GlobalClassRegistry();
    auto* types = havok::serialize::GlobalTypeRegistry();
    auto* vtables = GlobalVtables();
    // Stage all allocations before publishing any registration. Metadata is
    // borrowed, but each map's storage and names have genuine native owners.
    auto nextNames = *names;
    auto nextTypes = *types;
    auto nextVtables = *vtables;
    nextNames.RegisterClass(source);
    nextTypes.Register(metadata);
    if (HasInterfaces(source)) nextVtables.RegisterLink(metadata->vtable, source);
    names->SwapContents(nextNames);
    types->types.entries.swap(nextTypes.types.entries);
    vtables->SwapContents(nextVtables);
}
// @fnv 0x00d47860
void FUN_00d47860()
{
    RequireGlobals();
    // A scalar generated placeholder is not a native hkClass. Explicit
    // registration remains available while default descriptor capability is
    // absent; do not manufacture a populated default catalogue.
    if (!catalog.classDescriptor) return;
    auto* names = havok::serialize::GlobalClassRegistry();
    auto* types = havok::serialize::GlobalTypeRegistry();
    auto* vtables = GlobalVtables();
    auto nextNames = *names;
    auto nextTypes = *types;
    auto nextVtables = *vtables;
    nextNames.RegisterClass(catalog.classDescriptor);
    for (std::size_t i = 0; i < catalog.types.size() && catalog.types[i]; ++i)
    {
        if (i >= catalog.classes.size() || !catalog.classes[i])
            throw std::invalid_argument("incomplete builtin catalogue");
        auto* descriptor = catalog.classes[i];
        ValidateClass(descriptor);
        auto* metadata = static_cast<Agg6*>(catalog.types[i])->Metadata();
        nextNames.RegisterClass(descriptor);
        nextTypes.Register(metadata);
    }
    nextVtables.RegisterTables(catalog.types, catalog.classes);
    names->SwapContents(nextNames);
    types->types.entries.swap(nextTypes.types.entries);
    vtables->SwapContents(nextVtables);
}
// @fnv 0x00d47d70
void fnv_00d47d70::FUN_00d47d70_class::InitGlobalObjects()
{
    auto names = std::make_unique<havok::serialize::ClassNameRegistry>();
    auto types = std::make_unique<havok::serialize::TypeRegistry>(1);
    auto vtables = std::make_unique<hkVtableClassRegistry>();
    const auto oldNames = DAT_01269b14, oldTypes = DAT_01269b18, oldVtables = DAT_01269b10;
    DAT_01269b14 = reinterpret_cast<std::intptr_t>(names.get());
    DAT_01269b18 = reinterpret_cast<std::intptr_t>(types.get());
    DAT_01269b10 = reinterpret_cast<std::intptr_t>(vtables.get());
    try { FUN_00d47860(); }
    catch (...)
    {
        DAT_01269b14 = oldNames; DAT_01269b18 = oldTypes; DAT_01269b10 = oldVtables;
        throw;
    }
    names.release(); types.release(); vtables.release();
    if (oldNames) reinterpret_cast<havok::serialize::ClassNameRegistry*>(oldNames)->ReleaseReference();
    if (oldTypes) reinterpret_cast<havok::serialize::TypeRegistry*>(oldTypes)->ReleaseReference();
    if (oldVtables) reinterpret_cast<hkVtableClassRegistry*>(oldVtables)->ReleaseReference();
}
hkDefaultBuiltinTypeRegistry::~hkDefaultBuiltinTypeRegistry()
{
    if (classes) classes->ReleaseReference();
    if (types) types->ReleaseReference();
    if (vtables) vtables->ReleaseReference();
}
void hkDefaultBuiltinTypeRegistry::AddReference() noexcept { Retain(*this); }
void hkDefaultBuiltinTypeRegistry::ReleaseReference() noexcept { if (--references == 0) delete this; }
// @fnv 0x00d478c0
hkDefaultBuiltinTypeRegistry* hkDefaultBuiltinTypeRegistry::Initialize()
{
    FUN_00d47860();
    auto* nextClasses = havok::serialize::GlobalClassRegistry();
    auto* nextTypes = havok::serialize::GlobalTypeRegistry();
    auto* nextVtables = GlobalVtables();
    nextClasses->AddReference(); nextTypes->AddReference(); nextVtables->AddReference();
    if (classes) classes->ReleaseReference();
    if (types) types->ReleaseReference();
    if (vtables) vtables->ReleaseReference();
    classes = nextClasses; types = nextTypes; vtables = nextVtables;
    return this;
}
// @fnv 0x00d47820
hkDefaultBuiltinTypeRegistry* FUN_00d47820()
{
    if (!DAT_01269b10 || !DAT_01269b14 || !DAT_01269b18) return nullptr;
    auto registry = std::make_unique<hkDefaultBuiltinTypeRegistry>();
    registry->Initialize();
    return registry.release();
}
