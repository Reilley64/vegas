#include "havok/FastMesh.h"
#include "havok/NativeWorld.h"
#include <limits>
#include <stdexcept>

namespace havok::serialize
{
ClassLease NativeFastMeshClass() noexcept
{
    // These describe the actual source C++ types, NOT the 96-byte serialized
    // hkpFastMeshShape or missing game-default reflection. Both are opaque,
    // nonserializable native operation contracts: no fabricated field offsets.
    static char shapeName[] = "havok::fast_mesh::Shape";
    static char meshName[] = "havok::fast_mesh::FastMesh";
    static hkClass shape{shapeName, nullptr, sizeof(fast_mesh::Shape), 1, {}, {}, nullptr, nullptr,
        hkClass::FLAGS_NOT_SERIALIZABLE, 0};
    static hkClass mesh{meshName, &shape, sizeof(fast_mesh::FastMesh), 0, {}, {}, nullptr, nullptr,
        hkClass::FLAGS_NOT_SERIALIZABLE, 0};
    return {&mesh, {}};
}
ObjectImpl::ObjectImpl(std::shared_ptr<Resource> resource, ObjectReference object, void* legacy, ClassLease type)
    : type(std::move(type)), resource(std::move(resource)), object(std::move(object)), legacy(legacy)
{
    if (!this->type.descriptor || (!this->object.NativeAddress() && !legacy))
        throw std::invalid_argument("native world requires a constructed object and native class");
}
const void* ObjectImpl::Address() const noexcept { return object.NativeAddress() ? object.NativeAddress() : legacy; }
hkDataWorldNative::hkDataWorldNative(std::shared_ptr<Resource> resource, const ClassNameRegistry& classes)
    : resource(std::move(resource)), classes(classes)
{
    if (!this->resource) throw std::invalid_argument("native world requires an owning resource");
}
RootObject hkDataWorldNative::Publish(ObjectReference object, void* legacy)
{
    ClassLease type;
    if (object.Mesh()) type = NativeFastMeshClass();
    else if (object.NativeAddress()) type = {object.NativeClass(), object.ClassStorage()};
    else if (legacy)
    {
        type.descriptor = classes.Find(resource->name());
        if (!type.descriptor) throw std::runtime_error("no native class contract for resource root");
        type.storage = classes.Storage(type.descriptor);
        if (!type.storage) throw std::runtime_error("native world requires a class/member/name storage lease");
        // Legacy callbacks finish native-layout storage only. No cross-width
        // object or recorded-extent/native-size equivalence is inferred here.
        const auto& metadata = resource->NativeTypeContract();
        if (!metadata.nativeSize || metadata.nativeSize != static_cast<std::size_t>(type.descriptor->m_iObjectSize))
            throw std::runtime_error("legacy root native class extent mismatch");
        // The validated legacy root needs the same actual contents lease as
        // per-object native contracts, not merely the resource wrapper.
        object = ObjectReference(static_cast<ResourceStorage&>(*resource).KeepNativeObject(legacy),
            type.descriptor, type.storage);
    }
    else throw std::runtime_error("serialized bytes are not native world objects");
    const void* identity = object.NativeAddress() ? object.NativeAddress() : legacy;
    auto& slot = objects[identity];
    if (auto existing = slot.lock()) return RootObject(std::move(existing));
    resource->RetainClassStorage(type.storage);
    auto impl = std::make_shared<ObjectImpl>(resource, std::move(object), legacy, std::move(type));
    slot = impl;
    return RootObject(std::move(impl));
}
RootObject hkDataWorldNative::Root() { return Publish(resource->NativeContents(), resource->contents(nullptr, nullptr)); }
RootObject hkDataWorldNative::Object(Location loc) { return Publish(resource->NativeObject(loc)); }
RootObject hkDataWorldNative::Reference(Location loc) { return Publish(resource->NativeReference(loc)); }
}
ObjectResource::ObjectResource(std::shared_ptr<havok::serialize::Resource> resource,
    const havok::serialize::ClassNameRegistry& classes)
    : hkPackfileDataE055(std::move(resource), classes) {}
S_Obj::~S_Obj() = default;
void S_Obj::AddReference() noexcept
{
    if (references == std::numeric_limits<unsigned>::max()) std::terminate();
    ++references;
}
void S_Obj::ReleaseReference() noexcept { if (--references == 0) delete this; }

// @fnv 0x00e05700
std::unique_ptr<ObjectResource> S00e05700_Class::FUN_00e05700(const S_PH& source, const S_Dom& domain)
{
    if (!source.resource) throw std::invalid_argument("legacy builder requires a materialized source owner");
    return std::unique_ptr<ObjectResource>(new ObjectResource(source.resource, domain.classes));
}
S_Obj* S_toResource(S_Ctx* context, S_PH* source, havok::serialize::LoadError* error) noexcept
{
    try
    {
        if (!context) throw std::invalid_argument("missing resource builder context");
        context->pending.reset();
        if (!source) throw std::invalid_argument("missing source object handle");
        context->pending = S00e05700_Class::FUN_00e05700(*source, context->domain);
        // Native ownership transfer never repeats placement construction. The
        // actual loader already populated one completion/cleanup ledger.
        // Validate the constructed root here. Export records may also designate
        // serialized data without a native class; typed queries reject those
        // identities on demand, rather than inventing classes or rejecting an
        // otherwise valid explicitly materialized root.
        if (error) error->set(0, "");
        return context->pending.release();
    }
    catch (const std::exception& failure)
    {
        if (context) context->pending.reset();
        if (error) try { error->set(1, failure.what()); } catch (...) {}
    }
    catch (...)
    {
        if (context) context->pending.reset();
        if (error) try { error->set(1, "resource builder failed"); } catch (...) {}
    }
    return nullptr;
}
// @fnv 0x00dc3300
S_Obj* FUN_00dc3300(S_PH* source, S_Dom* domain)
{
    if (!domain) return nullptr;
    try
    {
        S_Ctx context(*domain);
        return S_toResource(&context, source);
    }
    catch (...) { return nullptr; }
}
// @fnv 0x00dc4710
S_Obj* S_00dc4710_Cls::FUN_00dc4710(S_PH* source, const havok::serialize::TypeRegistry* finish,
    havok::serialize::LoadError* error) noexcept
{
    std::unique_ptr<S_Obj> result(S_toResource(&context, source, error));
    if (!result) return nullptr;
    if (!finish || !result->FUN_00e055f0(nullptr, finish))
    {
        if (error) try { error->set(1, "resource finishing registry does not match completed source"); } catch (...) {}
        return nullptr;
    }
    return result.release();
}
namespace fnv_00dc3530
{
// @fnv 0x00dc3530
S_Obj* FUN_00dc3530(S_PH* source, havok::serialize::LoadError* error) noexcept
{
    try
    {
        auto* classes = havok::serialize::GlobalClassRegistry();
        if (!classes) throw std::runtime_error("native class registry is not initialized");
        S_Dom domain(*classes);
        S_Ctx context(domain);
        return S_toResource(&context, source, error);
    }
    catch (const std::exception& failure)
    {
        if (error) try { error->set(1, failure.what()); } catch (...) {}
    }
    catch (...) { if (error) try { error->set(1, "global resource construction failed"); } catch (...) {} }
    return nullptr;
}
}

// @fnv 0x00d48840
ObjectResource* FUN_00d48840(havok::serialize::LoadStream* input, const havok::serialize::LoadFormat& format,
    havok::serialize::LoadError* error, const havok::serialize::ClassNameRegistry* classes,
    const havok::serialize::TypeRegistry* types, const havok::serialize::LoadPolicy& policy) noexcept
{
    using namespace havok::serialize;
    try
    {
        if (!input || !classes || !types) throw std::invalid_argument("missing heap loader owner");
        // This producer finishes once in the exact requested mode. Its ledger
        // and cleanup owner are shared with the second consumer, not rebuilt
        // from a map of unrelated raw addresses.
        std::shared_ptr<Resource> resource(FUN_00d48760(*input, format, error, *types, policy),
            [](Resource* value) { if (value) value->ReleaseReference(); });
        if (!resource) return nullptr;
        S_PH source(std::move(resource));
        S_Dom domain(*classes);
        S_Ctx context(domain);
        std::unique_ptr<S_Obj> result(S_toResource(&context, &source, error));
        if (!result) return nullptr;
        if (!result->Data().FUN_00e055f0(nullptr, types))
            throw std::runtime_error("heap loader root finishing incomplete");
        auto* publication = dynamic_cast<ObjectResource*>(result.get());
        if (!publication) throw std::runtime_error("resource builder produced an incompatible publication owner");
        result.release();
        return publication;
    }
    catch (const std::exception& failure)
    {
        if (error) try { error->set(1, failure.what()); } catch (...) {}
    }
    catch (...)
    {
        if (error) try { error->set(1, "heap loader construction failed"); } catch (...) {}
    }
    return nullptr;
}
