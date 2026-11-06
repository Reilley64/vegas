#include "havok/NativeWorld.h"
#include <cstring>

hkPackfileDataE055::hkPackfileDataE055(std::shared_ptr<havok::serialize::Resource> resource,
    const havok::serialize::ClassNameRegistry& classes) : resource(std::move(resource)),
    world(std::make_unique<havok::serialize::hkDataWorldNative>(this->resource, classes)), root(world->Root()) {}
hkPackfileDataE055::~hkPackfileDataE055() { FUN_00e057c0(); }

// @fnv 0x00e057c0
void hkPackfileDataE055::FUN_00e057c0() noexcept
{
    root.FUN_00dba7f0();
    world.reset();
    resource.reset();
}
// @fnv 0x00e05140
const hkClass* hkPackfileDataE055::FUN_00e05140() const noexcept { return root ? &root->Class() : nullptr; }
havok::serialize::RootObject hkPackfileDataE055::Object(havok::serialize::Location location)
{
    return world ? world->Object(location) : havok::serialize::RootObject{};
}
havok::serialize::RootObject hkPackfileDataE055::Reference(havok::serialize::Location location)
{
    return world ? world->Reference(location) : havok::serialize::RootObject{};
}
std::vector<ExportedNativeObject> hkPackfileDataE055::Exports()
{
    std::vector<ExportedNativeObject> result;
    if (resource) for (const auto& symbol : resource->NativeSymbols(false))
        result.push_back({symbol.name, world->Object(symbol.location)});
    return result;
}
std::vector<havok::serialize::SymbolLocation> hkPackfileDataE055::Imports() const
{
    return resource ? resource->NativeSymbols(true) : std::vector<havok::serialize::SymbolLocation>{};
}

// @fnv 0x00e055f0
const void* hkPackfileDataE055::FUN_00e055f0(const char* expected,
    const havok::serialize::TypeRegistry* finish) noexcept
{
    if (!root || !resource) return nullptr;
    if (expected)
    {
        bool matches = false;
        for (auto* type = &root->Class(); type; type = type->m_parent)
            if (type->m_name && std::strcmp(type->m_name, expected) == 0) { matches = true; break; }
        if (!matches) return nullptr;
    }
    // Null means no new finish request, as in the retained consumer. A supplied
    // registry must agree with the production completion ledger's exact mode.
    // Mode changes require a new load, not a second placement-construction over
    // a living C++ object. All completed identities retain one reverse cleanup.
    if (finish && !resource->FinishedWith(*finish, root->Address())) return nullptr;
    return root->Address();
}
