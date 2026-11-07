#include "havok/FastMesh.h"
#include "havok/NativePackfile.h"
#include "havok/hkpShapeBuffer.h"
#include "havok/hkpMoppBvTreeShape.h"
#include "havok/hkpMoppCode.h"
#include "havok/hkMemorySystem.h"
#include "check.h"
#include "fast_mesh_fixture.h"

#include <algorithm>
#include <stdexcept>
#include <thread>

namespace
{
int InUse(hkMemoryAllocator& heap)
{
    hkMemoryAllocator::MemoryStatistics stats;
    heap.getMemoryStatistics(stats);
    return stats.inUse;
}
hkVector4 ThrowVertex()
{
    throw std::runtime_error("vertex argument failed");
}
}

int main()
{
    Checks checks("runtime.havok_loaded_mesh_collection");
    havok::native_memory::AlignedAllocator backing;
    hkSystemMemoryAllocator heap(backing);
    hkMemoryRouter router;
    router.m_heap = &heap;
    SetThreadLocalValue(&router);

    auto supplier = std::make_shared<havok::native_memory::AlignedAllocator>();
    std::weak_ptr<havok::native_memory::AlignedAllocator> supplierLifetime = supplier;
    havok::serialize::TypeRegistry types(1);
    hkEntryD479 metadata;
    metadata.name = "hkpFastMeshShape";
    metadata.size = 96; // Serialized extent, never a native layout assertion.
    types.Register(&metadata);
    havok::serialize::LoadContext context;
    context.registry = &types;
    context.lookupType = PackfileRegistryTypeInfo;
    context.nativeTypes = &types;
    context.supplier = supplier;

    hkpMoppBvTreeShape* first = nullptr;
    hkpMoppBvTreeShape* second = nullptr;
    hkpShapeBuffer survivingBuffer;
    const hkpTriangleShape* survivingTriangle = nullptr;
    {
        Fixture fixture;
        havok::serialize::PackfileResource resource(fixture.input, context);
        checks.Equal("actual packfile decoding succeeds", std::string{}, resource.Error());
        auto loaded = resource.Root().Mesh();
        checks.Equal("actual packfile publishes native collection", true, bool(loaded));
        if (!loaded) return 1;
        const hkpShapeCollection& collection = *loaded;
        checks.Equal("finishing establishes native mesh kind", 0x17u, collection.getType());
        const auto* triangle = static_cast<const hkpTriangleShape*>(collection.getChildShape(0, survivingBuffer));
        checks.Equal("native triangle kind", 3u, triangle->getType());
        checks.Equal("decoded scaled vertex x", 2.0f, triangle->getVertex(1).x);
        checks.Equal("decoded scaled vertex y", 3.0f, triangle->getVertex(2).y);
        checks.Equal("native vertex w", 0.0f, triangle->getVertex(2).w);
        checks.Equal("loaded collision radius", 0.25f, triangle->getRadius());
        checks.Equal("loaded welding value", hkUint16(0x1234), triangle->getWeldingInfo());
        checks.Equal("loaded welding kind", hkUint8(2), triangle->getWeldingType());
        survivingTriangle = triangle;
        auto* code = new hkpMoppCode;
        // Finish constructs a mutable FastMesh and publishes a const handle.
        // The existing MOPP ownership entry takes a mutable shape pointer, but
        // only retains it; this removes const, never changes the object type.
        auto* produced = const_cast<havok::fast_mesh::FastMesh*>(loaded.get());
        first = new hkpMoppBvTreeShape(produced, *code);
        second = new hkpMoppBvTreeShape(produced, *code);
        checks.Equal("MOPP publishes the exact produced object", true, first->getChild() == loaded.get());
        checks.Equal("both MOPPs retain one produced identity", true, first->getChild() == second->getChild());
        code->removeReference();
        resource.Cleanup();
        std::fill(fixture.input.begin(), fixture.input.end(), std::byte{0xcc});
        loaded.reset();
    }
    context.supplier.reset();
    supplier.reset();
    checks.Equal("MOPP owners retain supplying allocator after loader release", false, supplierLifetime.expired());
    first->removeReference();
    const auto* child = static_cast<const havok::fast_mesh::FastMesh*>(second->getChild());
    const hkpShapeCollection& retainedCollection = *child;
    hkpShapeBuffer buffer;
    const auto* retainedTriangle = static_cast<const hkpTriangleShape*>(retainedCollection.getChildShape(0, buffer));
    checks.Equal("MOPP retained collection survives input and resource cleanup", 2.0f, retainedTriangle->getVertex(1).x);
    havok::fast_mesh::RayHit hit;
    const havok::fast_mesh::Shape& rayConsumer = *child;
    checks.Equal("actual ray consumer traverses native triangle collection", true,
        rayConsumer.CastRay({0.25f,0.25f,1}, {0.25f,0.25f,-1}, hit));
    checks.Equal("ray fraction independent oracle", 0.5f, hit.fraction);
    checks.Equal("ray normal independent oracle", 1.0f, hit.normal.z);
    checks.Equal("ray child key independent oracle", 0u, hit.key);
    checks.Equal("material consumer retains copied bytes", 42u, std::to_integer<unsigned>(child->Material(0)[0]));
    SetThreadLocalValue(nullptr);
    std::thread([second] { second->removeReference(); }).join();
    checks.Equal("last native reference frees loader supplier without TLS", true, supplierLifetime.expired());
    checks.Equal("MOPP and code return all supplying heap allocations", 0, InUse(heap));
    checks.Equal("scoped triangle survives producer destruction", 3.0f, survivingTriangle->getVertex(2).y);
    checks.Equal("independent scoped triangle remains usable", 0.25f, retainedTriangle->getRadius());

    // Match the owning-supplier new/delete pair even when argument evaluation
    // fails before the base constructor can consume its pending allocation.
    auto argumentSupplier = std::make_shared<havok::native_memory::AlignedAllocator>();
    bool threw = false;
    try { new (argumentSupplier) hkpTriangleShape(0, 0, 6, ThrowVertex(), {}, {}); }
    catch (const std::runtime_error&) { threw = true; }
    checks.Equal("owning-supplier argument exception propagates", true, threw);
    auto* later = new (argumentSupplier) hkpTriangleShape(1, 0, 6, {}, {}, {});
    checks.Equal("later genuine construction remains usable", 1.0f, later->getRadius());
    later->removeReference();
    std::weak_ptr<havok::native_memory::AlignedAllocator> argumentLifetime = argumentSupplier;
    argumentSupplier.reset();
    checks.Equal("failed new and later final release retain no supplier", true, argumentLifetime.expired());
    return checks.ExitCode();
}
