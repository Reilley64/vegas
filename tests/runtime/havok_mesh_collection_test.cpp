#include "check.h"
#include "havok/hkpMeshShape.h"
#include "havok/hkpShapeBuffer.h"
#include "havok/hkpMoppBvTreeShape.h"
#include "havok/hkpMoppCode.h"
#include "havok/hkMemorySystem.h"
#include "havok/hkAabb.h"

#include <array>
#include <thread>

namespace
{
int InUse(hkMemoryAllocator& heap)
{
    hkMemoryAllocator::MemoryStatistics statistics;
    heap.getMemoryStatistics(statistics);
    return statistics.inUse;
}
void Vector(Checks& checks, const hkVector4& actual, hkVector4 expected)
{
    checks.Equal("vertex x", expected.x, actual.x);
    checks.Equal("vertex y", expected.y, actual.y);
    checks.Equal("vertex z", expected.z, actual.z);
    checks.Equal("vertex w", expected.w, actual.w);
}
struct Fixture
{
    std::array<std::array<float, 4>, 5> first{{{1,2,3,91}, {4,2,3,92}, {1,6,3,93}, {4,6,7,94}, {1000,1000,1000,95}}};
    std::array<std::array<hkUint16, 4>, 2> indices16{{{0,1,2,99}, {1,2,3,99}}};
    std::array<std::array<float, 4>, 3> second{{{-2,-1,0,81}, {0,-1,2,82}, {-2,3,2,83}}};
    std::array<hkUint32, 5> indices32{2,0,1,99,99};
    std::array<hkpMeshShapeSubpart, 2> parts{};
    std::array<hkUint16, 5> welding{98,11,22,97,33};
    Fixture()
    {
        parts[0].m_pMaterialIndexBase = first.data();
        parts[0].m_iTriangleIndexStride = 16;
        parts[0].m_iStridedVertexCount = 5;
        parts[0].m_pMaterialDataBase = indices16.data();
        parts[0].m_ucIndexStridingType = hkpMeshShape::INDICES_INT16;
        parts[0].m_iMaterialStriding = 8;
        parts[0].m_bFlipAlternateTriangles = 1;
        parts[0].m_iTriangleCount = 2;
        parts[0].m_iTriangleOffset = 1;
        parts[1].m_pMaterialIndexBase = second.data();
        parts[1].m_iTriangleIndexStride = 16;
        parts[1].m_iStridedVertexCount = 3;
        parts[1].m_pMaterialDataBase = indices32.data();
        parts[1].m_ucIndexStridingType = hkpMeshShape::INDICES_INT32;
        parts[1].m_iMaterialStriding = 20;
        parts[1].m_iTriangleCount = 1;
        parts[1].m_iTriangleOffset = 4;
    }
};

void CollectionAndConsumer(Checks& checks, hkSystemMemoryAllocator& heap)
{
    Fixture fixture;
    auto* mesh = new hkpMeshShape(0.25f, 3, fixture.parts, fixture.welding);
    checks.Equal("source-established accepted mesh kind", 0x17u, mesh->getType());
    hkpShapeCollection& collection = *mesh;
    hkpShapeBuffer buffer, independentBuffer;
    const hkpShape* child = collection.getChildShape(0, buffer);
    checks.Equal("triangle public shape type", 3u, child->getType());
    const auto* triangle = static_cast<const hkpTriangleShape*>(child);
    Vector(checks, triangle->getVertex(0), {1,2,3,0});
    Vector(checks, triangle->getVertex(1), {4,2,3,0});
    Vector(checks, triangle->getVertex(2), {1,6,3,0});
    checks.Equal("triangle radius", 0.25f, triangle->getRadius());
    checks.Equal("fresh welding kind", 6, int(triangle->getWeldingType()));
    checks.Equal("first welding offset", 11, int(triangle->getWeldingInfo()));
    const auto* independent = mesh->getChildShape(1, independentBuffer);
    Vector(checks, independent->getVertex(1), {4,6,7,0});
    Vector(checks, independent->getVertex(2), {1,6,3,0});
    checks.Equal("alternate winding welding", 22, int(independent->getWeldingInfo()));

    mesh->setScaling({2,-3,0.5f,8});
    const auto* scaled = mesh->getChildShape(1, buffer);
    Vector(checks, scaled->getVertex(0), {8,-6,1.5f,0});
    Vector(checks, scaled->getVertex(1), {8,-18,3.5f,0});
    Vector(checks, scaled->getVertex(2), {2,-18,1.5f,0});
    // Another buffer retains an independent complete triangle, not mesh aliases.
    Vector(checks, independent->getVertex(1), {4,6,7,0});
    const auto* second = mesh->getChildShape(1u << 29, buffer);
    Vector(checks, second->getVertex(0), {-4,-9,1,0});
    Vector(checks, second->getVertex(1), {-4,3,0,0});
    Vector(checks, second->getVertex(2), {0,3,1,0});
    checks.Equal("32-bit part welding offset", 33, int(second->getWeldingInfo()));

    hkTransform placement{{{{0,1,0,0}, {-1,0,0,0}, {0,0,1,0}}}, {10,-5,2,0}};
    hkAabb bounds;
    mesh->getAabb(placement, 0.5f, bounds);
    // Hand-derived indexed-vertex bounds under a quarter-turn plus translation.
    // The unused outlier must not participate in this real collection consumer.
    checks.Equal("bounds min x", 6.25f, bounds.m_kMinimumCorner.x);
    checks.Equal("bounds min y", -9.75f, bounds.m_kMinimumCorner.y);
    checks.Equal("bounds min z", 1.25f, bounds.m_kMinimumCorner.z);
    checks.Equal("bounds max x", 28.75f, bounds.m_kMaximumCorner.x);
    checks.Equal("bounds max y", 3.75f, bounds.m_kMaximumCorner.y);
    checks.Equal("bounds max z", 6.25f, bounds.m_kMaximumCorner.z);

    // Descriptors and welding are copied; vertex/index streams are borrowed.
    fixture.parts[0].m_iTriangleIndexStride = 0;
    fixture.welding[1] = 88;
    fixture.first[0][0] = 9;
    const auto* changed = mesh->getChildShape(0, buffer);
    Vector(checks, changed->getVertex(0), {18,-6,1.5f,0});
    checks.Equal("owned welding is independent", 11, int(changed->getWeldingInfo()));
    mesh->removeReference();
    checks.Equal("native mesh arrays and object released", 0, InUse(heap));
    Vector(checks, changed->getVertex(0), {18,-6,1.5f,0});
    Vector(checks, independent->getVertex(1), {4,6,7,0});
}

void OverlappingStrip(Checks& checks, hkSystemMemoryAllocator& heap)
{
    Fixture fixture;
    std::array<hkUint16, 4> strip{0,1,2,3};
    fixture.parts[0].m_pMaterialDataBase = strip.data();
    fixture.parts[0].m_iMaterialStriding = 2;
    auto* mesh = new hkpMeshShape(0.5f, 3, std::span{fixture.parts}.first(1));
    hkpShapeBuffer buffer;
    const auto* triangle = mesh->getChildShape(1, buffer);
    Vector(checks, triangle->getVertex(0), {4,2,3,0});
    Vector(checks, triangle->getVertex(1), {4,6,7,0});
    Vector(checks, triangle->getVertex(2), {1,6,3,0});
    strip[1] = 0;
    triangle = mesh->getChildShape(1, buffer);
    Vector(checks, triangle->getVertex(0), {1,2,3,0});
    mesh->removeReference();
    checks.Equal("overlapping strip descriptor cleanup", 0, InUse(heap));
}

void RetainedMesh(Checks& checks, hkSystemMemoryAllocator& heap, hkMemoryRouter& router,
                  hkSystemMemoryAllocator& otherHeap, hkMemoryRouter& other)
{
    Fixture fixture;
    auto* mesh = new hkpMeshShape(1.5f, 3, fixture.parts);
    const std::array<hkUint8, 3> bytes{3,1,4};
    auto* code = new hkpMoppCode({}, bytes);
    auto* first = new hkpMoppBvTreeShape(mesh, *code);
    auto* second = new hkpMoppBvTreeShape(mesh, *code);
    mesh->removeReference();
    code->removeReference();
    first->removeReference();
    checks.Equal("MOPP retains exact real mesh", true, second->getChild() == mesh);
    checks.Equal("MOPP retains owned code", bytes[2], second->getMoppData()[2]);
    hkpShapeBuffer buffer;
    const auto& collection = static_cast<const hkpShapeCollection&>(*second->getChild());
    const auto* triangle = static_cast<const hkpTriangleShape*>(collection.getChildShape(1, buffer));
    Vector(checks, triangle->getVertex(1), {4,6,7,0});
    checks.Equal("absent welding stream gives source default", 0, int(triangle->getWeldingInfo()));
    checks.Equal("retained mesh triangle radius", 1.5f, triangle->getRadius());
    SetThreadLocalValue(&other);
    second->removeReference();
    checks.Equal("mesh cleanup uses supplying heap", 0, InUse(heap));
    checks.Equal("mesh cleanup does not use current heap", 0, InUse(otherHeap));
    Vector(checks, triangle->getVertex(1), {4,6,7,0});
    SetThreadLocalValue(&router);
    auto* detached = new hkpMeshShape(0.25f, 3, fixture.parts, fixture.welding);
    std::thread([detached] { detached->removeReference(); }).join();
    checks.Equal("mesh release needs no router TLS", 0, InUse(heap));
}

void FailureAndScoped(Checks& checks, hkSystemMemoryAllocator& heap, hkMemoryRouter& router)
{
    Fixture fixture;
    {
        hkpMeshShape mesh(0.5f, 3, fixture.parts);
        hkpShapeBuffer buffer;
        auto* triangle = mesh.getChildShape(0, buffer);
        triangle->addReference();
        triangle->removeReference();
        checks.Equal("buffer triangle is non-deleting", 0.5f, triangle->getRadius());
        mesh.addReference();
        mesh.removeReference();
    }
    checks.Equal("scoped mesh cleans descriptor storage", 0, InUse(heap));
    hkpShape* ownedTriangle = new hkpTriangleShape(2.0f, 45, 6,
        hkVector4{1,2,3,0}, hkVector4{4,5,6,0}, hkVector4{7,8,9,0});
    const auto* triangle = static_cast<const hkpTriangleShape*>(ownedTriangle);
    Vector(checks, triangle->getVertex(2), {7,8,9,0});
    checks.Equal("owned triangle welding", 45, int(triangle->getWeldingInfo()));
    ownedTriangle->removeReference();
    checks.Equal("heap triangle typed cleanup balances", 0, InUse(heap));
    hkNativeSolverAllocator bounded(heap);
    checks.Equal("real bounded allocator initialized", true, bounded.Initialize(1024));
    router.m_heap = &bounded;
    const std::array<hkUint16, 1024> largeWelding{};
    bool threw = false;
    try { new hkpMeshShape(0.5f, 3, fixture.parts, largeWelding); }
    catch (const std::bad_alloc&) { threw = true; }
    checks.Equal("welding allocation failure propagated", true, threw);
    checks.Equal("failed construction frees descriptor and object", 0, InUse(bounded));
    hkMemoryAllocator::MemoryStatistics statistics;
    bounded.getMemoryStatistics(statistics);
    checks.Equal("allocation failure after real allocations", true, statistics.peakInUse > 0);
    router.m_heap = &heap;
    bounded.Release();
    checks.Equal("bounded arena released", 0, InUse(heap));
    // Ensure constructor-failure bookkeeping does not poison subsequent owners.
    auto* later = new hkpMeshShape(0.5f, 3, fixture.parts);
    hkpShapeBuffer buffer;
    checks.Equal("later real mesh remains usable", 3u, later->getChildShape(0, buffer)->getType());
    delete static_cast<hkpShapeContainer*>(later);
    checks.Equal("virtual collection cleanup balances", 0, InUse(heap));
}
}

int main()
{
    Checks checks("Native mesh collection");
    havok::native_memory::AlignedAllocator backing;
    hkSystemMemoryAllocator heap(backing), otherHeap(backing);
    hkMemoryRouter router, other;
    router.m_heap = &heap;
    other.m_heap = &otherHeap;
    SetThreadLocalValue(&router);
    CollectionAndConsumer(checks, heap);
    OverlappingStrip(checks, heap);
    RetainedMesh(checks, heap, router, otherHeap, other);
    FailureAndScoped(checks, heap, router);
    SetThreadLocalValue(nullptr);
    return checks.ExitCode();
}
