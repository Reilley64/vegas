#pragma once
#include "havok/PackfileLoad.h"
namespace havok::serialize
{
class ClassNameRegistry;
struct SerializeOptions
{
    const ClassNameRegistry& classes;
    const TypeRegistry& types;
    const LoadPolicy& packfiles;
};
}
struct S_Obj;
class hkClass;
// Native public serializer entry. Options are a real owning-domain contract,
// not a four-byte integer masquerading as a registry or dictionary receiver.
S_Obj* FUN_00d48d30(havok::serialize::LoadStream*, havok::serialize::LoadError*,
    const havok::serialize::SerializeOptions*) noexcept;
namespace fnv_00d48f00
{
// Retained buffer entry: bounded input, the same native domain/error contract
// and one genuine S_Obj cleanup protocol for every supported format.
S_Obj* FUN_00d48f00(std::span<const std::byte>, havok::serialize::LoadError*,
    const havok::serialize::SerializeOptions*) noexcept;
}
// Retained root-container consumer: source-established primary-class lookup,
// then SnapshotSave/name and hkpPhysicsData/name. The native caller supplies
// the real primary class contract instead of viewing a generated global as one.
const void* FUN_00cc0850(havok::serialize::LoadStream*, const havok::serialize::SerializeOptions*,
    const hkClass*, S_Obj**, havok::serialize::LoadError*) noexcept;
