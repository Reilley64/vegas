#pragma once

#include "havok/PackfileRegistry.h"
#include "havok/PackfileTypeInfo.h"
#include "havok/hkClass.h"
#include <span>
#include <memory>

// Global initialization, catalogue selection, registration and shutdown are
// serialized startup/shutdown operations. References are intrusive, not atomic.
namespace havok::serialize
{
// Descriptors are the existing hkClass, not metadata records or objects to
// finish. Source descriptor/name storage must outlive all registry references.
class ClassNameRegistry final : public RegistryBase
{
public:
    void AddReference() noexcept override;
    void ReleaseReference() noexcept override;
    void RegisterClass(const hkClass*);
    void RegisterClass(const hkClass*, std::shared_ptr<const void> storage);
    const hkClass* Find(const char*) const noexcept;
    std::shared_ptr<const void> Storage(const hkClass*) const noexcept;
    void SwapContents(ClassNameRegistry& other) noexcept { classes.swap(other.classes); leases.swap(other.leases); }
private:
    std::vector<std::pair<std::string, const hkClass*>> classes;
    std::vector<std::pair<const hkClass*, std::shared_ptr<const void>>> leases;
};

enum class BuiltinCatalogStatus { MissingClassDescriptors, ClassDescriptorsProvided };
// The reconstructed generated module supplies bounded tables; a missing class
// seed is explicit capability absence, never a zero-filled hkClass. Entries
// end at the first null, as in the original caller, within the supplied bounds.
struct BuiltinCatalog
{
    std::span<void* const> types;
    std::span<const hkClass* const> classes;
    const hkClass* classDescriptor = nullptr;
};
void SetBuiltinCatalog(BuiltinCatalog);
BuiltinCatalogStatus GetBuiltinCatalogStatus() noexcept;
void ShutdownBuiltinRegistries() noexcept;
ClassNameRegistry* GlobalClassRegistry() noexcept;
TypeRegistry* GlobalTypeRegistry() noexcept;
}

class FUN_00db78a0_cls : public havok::serialize::RegistryBase
{
public:
    void AddReference() noexcept override;
    void ReleaseReference() noexcept override;
    void RegisterLink(const void*, const hkClass*);
    const hkClass* FindVtable(const void*) const noexcept;
    void SwapContents(FUN_00db78a0_cls& other) noexcept { entries.swap(other.entries); }
    // Actual retained metadata-table reader, now with genuine class values.
    void FUN_00db78a0(void* const*, const hkClass* const*);
    void RegisterTables(std::span<void* const>, std::span<const hkClass* const>);
private:
    std::vector<std::pair<const void*, const hkClass*>> entries;
};

struct hkVtableClassRegistry final : FUN_00db78a0_cls
{
    std::uintptr_t LookupClassByVtable(const unsigned long*);
    const hkClass* LookupObject(const void*) const noexcept;
};

struct hkDefaultBuiltinTypeRegistry : havok::serialize::RegistryBase
{
    hkDefaultBuiltinTypeRegistry() = default;
    hkDefaultBuiltinTypeRegistry(const hkDefaultBuiltinTypeRegistry&) = delete;
    hkDefaultBuiltinTypeRegistry& operator=(const hkDefaultBuiltinTypeRegistry&) = delete;
    ~hkDefaultBuiltinTypeRegistry() override;
    hkDefaultBuiltinTypeRegistry* Initialize();
    void AddReference() noexcept override;
    void ReleaseReference() noexcept override;
    havok::serialize::ClassNameRegistry* Classes() const noexcept { return classes; }
    havok::serialize::TypeRegistry* Types() const noexcept { return types; }
    hkVtableClassRegistry* Vtables() const noexcept { return vtables; }
private:
    havok::serialize::ClassNameRegistry* classes = nullptr;
    havok::serialize::TypeRegistry* types = nullptr;
    hkVtableClassRegistry* vtables = nullptr;
};
namespace fnv_00d47d70
{
struct FUN_00d47d70_class : hkDefaultBuiltinTypeRegistry
{
    void InitGlobalObjects();
};
}

hkDefaultBuiltinTypeRegistry* FUN_00d47820();
void RegisterInputSource(Agg6*, const hkClass*);
void FUN_00d47860();
std::intptr_t FUN_00d47a00();
std::intptr_t FUN_00d47a10();
std::intptr_t FUN_00d47a20();
