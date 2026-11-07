#include "havok/FastMeshPackfile.h"
#include "check.h"

#include <array>
#include <cstring>
#include <map>
#include <mutex>
#include <new>
#include <thread>

using namespace havok::fast_mesh;

class Backing final : public havok::native_memory::Allocator
{
  public:
    havok::native_memory::AlignedAllocator allocator;
    std::map<void*, std::size_t> blocks;
    std::mutex mutex;
    int failAfter = -1;
    bool throwFailure = false;
    void* Allocate(std::size_t bytes) override
    {
        std::lock_guard lock(mutex);
        if (failAfter == 0)
        {
            if (throwFailure) throw std::bad_alloc();
            return nullptr;
        }
        if (failAfter > 0) --failAfter;
        void* block = allocator.Allocate(bytes);
        if (block) blocks.emplace(block, bytes);
        return block;
    }
    void Free(void* block, std::size_t bytes) noexcept override
    {
        std::lock_guard lock(mutex);
        auto found = blocks.find(block);
        if (found == blocks.end() || found->second != bytes) std::abort();
        blocks.erase(found);
        allocator.Free(block, bytes);
    }
    ~Backing() override { if (!blocks.empty()) std::abort(); }
};

struct Fixture
{
    // Deliberately unaligned, padded streams: no SIMD load or native pointer cast.
    std::array<std::byte, 1 + 3 * 20> vertices{};
    std::array<std::byte, 1 + 2 * 8> indices{};
    std::array<std::byte, 2> materialIndices{std::byte{1}, std::byte{0}};
    std::array<std::byte, 12> materials{};
    std::array<std::uint16_t, 2> welding{0x1234, 0x5678};
    std::array<LoadedSubpart, 1> parts;
    LoadedMesh mesh;
    Fixture()
    {
        const std::array<Vec3, 3> values{{{0,0,0}, {1,0,0}, {0,1,0}}};
        for (std::size_t i=0; i<values.size(); ++i)
            std::memcpy(vertices.data()+1+i*20, &values[i], sizeof(Vec3));
        const std::uint16_t triangle[3]{0,1,2};
        for (int i=0; i<2; ++i) std::memcpy(indices.data()+1+i*8, triangle, sizeof(triangle));
        for (std::size_t i=0; i<materials.size(); ++i) materials[i]=std::byte(i+10);
        parts[0].vertices = std::span(vertices).subspan(1);
        parts[0].vertexCount = 3;
        parts[0].vertexStride = 20;
        parts[0].indices = std::span(indices).subspan(1);
        parts[0].triangleCount = 2;
        parts[0].triangleStride = 8;
        parts[0].indexType = 1;
        parts[0].flipAlternateTriangles = 1;
        parts[0].materialIndices = materialIndices;
        parts[0].materialIndexType = 0;
        parts[0].materialIndexStride = 1;
        parts[0].materials = materials;
        parts[0].materialStride = 6;
        parts[0].materialCount = 2;
        mesh.subparts = parts;
        mesh.welding = welding;
        mesh.scaling = {2,3,4};
        mesh.shapeType = 91;
        mesh.collectionType = 3;
        mesh.userData = 0x12345678;
        mesh.radius = 0.25f;
        mesh.disableWelding = true;
        mesh.weldingType = 2;
        mesh.shapeKeys = {7,8,9};
    }
};

int main()
{
    Checks checks("runtime.havok_fast_mesh_materialization");
    auto backing = std::make_shared<Backing>();
    std::weak_ptr<Backing> weakBacking = backing;
    Handle retained;
    {
        Fixture fixture;
        FastMeshPackfileData data(backing);
        const FastMesh& finished = data.FinishObject(fixture.mesh, 1);
        checks.Equal("finish shape type", 0x17u, finished.ShapeType());
        checks.Equal("finish collection type", 5u, finished.CollectionType());
        checks.Equal("conditional material index fixup", 1u, finished.Subpart(0).materialIndexType);
        checks.Equal("source material index remains borrowed", 0u, fixture.parts[0].materialIndexType);
        checks.Equal("loaded user data", std::uintptr_t(0x12345678), finished.UserData());
        checks.Equal("loaded welding state", true, finished.DisableWelding());
        checks.Equal("loaded shape keys", 8, finished.ShapeKeys()[1]);
        Triangle triangle;
        checks.Equal("real triangle extraction", true, finished.GetTriangle(1, triangle));
        checks.Equal("scaled and flipped vertex", 3.0f, triangle.vertices[1].y);
        checks.Equal("welding", std::uint16_t(0x5678), triangle.welding);
        checks.Equal("welding type", std::uint8_t(2), triangle.weldingType);
        checks.Equal("material bytes", 10u, std::to_integer<unsigned>(finished.Material(1)[0]));
        checks.Equal("material stride retained", std::size_t(6), finished.Material(1).size());
        auto untouched = FastMesh::Finish(fixture.mesh, 0, backing);
        checks.Equal("nonfinishing shape type", 91u, untouched->ShapeType());
        checks.Equal("nonfinishing collection type", 3u, untouched->CollectionType());
        checks.Equal("nonfinishing material type remains zero", 0u, untouched->Subpart(0).materialIndexType);
        fixture.mesh.collectionType = 255;
        auto byteCollection = FastMesh::Finish(fixture.mesh, 0, backing);
        checks.Equal("nonfinishing collection state retains the full byte", 255u, byteCollection->CollectionType());
        fixture.mesh.collectionType = 3;
        fixture.parts[0].materialIndexType = 2;
        std::array<std::byte,4> index16{std::byte{1},std::byte{0},std::byte{0},std::byte{0}};
        fixture.parts[0].materialIndices = index16;
        fixture.parts[0].materialIndexStride = 2;
        auto type2 = FastMesh::Finish(fixture.mesh, 7, backing);
        checks.Equal("finish does not overwrite material index type 2", 2u, type2->Subpart(0).materialIndexType);
        retained = data.Retain(0);
        data.Cleanup();
        checks.Equal("tracked cleanup clears records", std::size_t(0), data.Size());
        checks.Equal("retained native object survives resource cleanup", true, retained->GetTriangle(0, triangle));
        fixture.vertices.fill(std::byte{0x7f});
        fixture.indices.fill(std::byte{0x7f});
        fixture.materials.fill(std::byte{0x7f});
        checks.Equal("geometry is not borrowed", true, retained->GetTriangle(0, triangle));
        checks.Equal("geometry preserved after input overwrite", 2.0f, triangle.vertices[1].x);
        checks.Equal("materials preserved after input overwrite", 16u, std::to_integer<unsigned>(retained->Material(0)[0]));
    }
    // Calls through the real typed interface, never through a generated table.
    const Shape& shape = *retained;
    Transform transform;
    transform.translation = {10,20,30};
    const Aabb bounds = shape.GetAabb(transform, 0.5f);
    checks.Equal("AABB transformed min", 9.25f, bounds.min.x);
    checks.Equal("AABB scaled max", 23.75f, bounds.max.y);
    RayHit hit;
    checks.Equal("typed ray hits geometry", true, shape.CastRay({0.25f,0.25f,1},{0.25f,0.25f,-1},hit));
    checks.Equal("ray fraction", 0.5f, hit.fraction);
    checks.Equal("typed ray miss", false, shape.CastRay({5,5,1},{5,5,-1},hit));
    checks.Equal("miss preserves previous hit", 0.5f, hit.fraction);
    checks.Equal("ray reports native key", 0u, hit.key);
    checks.Equal("ray reports geometry normal", 1.0f, hit.normal.z);
    Transform stretched;
    stretched.columns[0].x = 2;
    checks.Equal("affine AABB includes transformed margin", 4.5f, shape.GetAabb(stretched,0).max.x);
    auto empty = FastMesh::Create(0.1f,12,backing);
    Triangle triangle;
    checks.Equal("fresh empty mesh type", 0x17u, empty->ShapeType());
    checks.Equal("fresh constructor welding type", 6u, empty->WeldingType());
    checks.Equal("fresh empty mesh has no child", false, empty->GetTriangle(0,triangle));
    checks.Equal("empty AABB is empty", true, empty->GetAabb({},0).Empty());
    empty.reset();
    retained.reset();
    checks.Equal("all native allocations released", std::size_t(0), backing->blocks.size());

    // Finish a valid object, then fail each allocation of the next finish. The
    // real resource must unwind both the partial object and its finished prefix.
    int failures = 0;
    for (bool throwing : {false,true})
    {
        bool succeeded = false;
        for (int n=0; n<40 && !succeeded; ++n)
        {
            Fixture fixture;
            FastMeshPackfileData data(backing);
            data.FinishObject(fixture.mesh,1);
            backing->failAfter = n;
            backing->throwFailure = throwing;
            try { data.FinishObject(fixture.mesh,1); succeeded = true; }
            catch (const std::bad_alloc&) { ++failures; checks.Equal("failed finish unwinds prefix", std::size_t(0), data.Size()); }
            backing->failAfter = -1;
            data.Cleanup();
            checks.Equal("partial finish leaves no allocations", std::size_t(0), backing->blocks.size());
        }
        checks.Equal("failure sweep reaches successful finish", true, succeeded);
    }
    checks.Equal("sweep exercised construction allocations", true, failures >= 10);
    {
        Fixture fixture;
        FastMeshPackfileData data(backing);
        data.FinishObject(fixture.mesh,1);
        fixture.parts[0].triangleCount = -1;
        bool rejected = false;
        try { data.FinishObject(fixture.mesh,1); }
        catch (const std::invalid_argument&) { rejected = true; }
        checks.Equal("negative count rejected", true, rejected);
        checks.Equal("validation failure unwinds finished prefix", std::size_t(0), data.Size());
        checks.Equal("validation failure releases geometry", std::size_t(0), backing->blocks.size());
    }
    {
        Fixture fixture;
        fixture.parts[0].materialIndexStride = 0;
        fixture.parts[0].materialIndices = std::span(fixture.materialIndices).first(1);
        bool accepted = false;
        try
        {
            FastMeshPackfileData data(backing);
            const auto& mesh = data.FinishObject(fixture.mesh,1);
            checks.Equal("constant material index applies to both triangles", 16u, std::to_integer<unsigned>(mesh.Material(1)[0]));
            accepted = true;
        }
        catch (const std::invalid_argument&) {}
        checks.Equal("zero material index stride is a constant stream", true, accepted);
    }
    // Key partition, empty-part traversal and 32-bit index reads use the same
    // typed operations as ordinary geometry, with no legacy slot assumptions.
    {
        Fixture fixture;
        std::array<std::byte, 1+24> indices32{};
        const std::array<std::uint32_t,6> triangles{0,1,2,0,1,2};
        std::memcpy(indices32.data()+1,triangles.data(),24);
        std::array<LoadedSubpart,2> parts{LoadedSubpart{},fixture.parts[0]};
        parts[1].indices = std::span(indices32).subspan(1);
        parts[1].indexType = 2;
        parts[1].triangleStride = 12;
        fixture.mesh.subparts = parts;
        auto mesh = FastMesh::Finish(fixture.mesh,1,backing);
        const std::uint32_t key = 1u << 20;
        checks.Equal("second subpart 32-bit child", true, mesh->GetTriangle(key,triangle));
        checks.Equal("32-bit child vertex", 2.0f, triangle.vertices[1].x);
        checks.Equal("empty first subpart has no child", false, mesh->GetTriangle(0,triangle));
        checks.Equal("invalid sentinel has no child", false, mesh->GetTriangle(~0u,triangle));
        RayHit second;
        checks.Equal("ray traverses empty first subpart", true, mesh->CastRay({0.5f,0.5f,1},{0.5f,0.5f,-1},second));
        checks.Equal("ray preserves subpart in key", key, second.key);
    }
    {
        Fixture fixture;
        fixture.mesh.subpartBits = 31;
        auto mesh = FastMesh::Finish(fixture.mesh,1,backing);
        checks.Equal("all non-sentinel keys in partition remain valid", true, mesh->GetTriangle(1,triangle));
        checks.Equal("partition mask does not truncate last child", 3.0f, triangle.vertices[1].y);
    }
    // A failed later finish releases its tracked ownership, not a separately
    // retained first object. That reference owns its streams until final release.
    {
        Fixture fixture;
        FastMeshPackfileData data(backing);
        data.FinishObject(fixture.mesh,1);
        auto first = data.Retain(0);
        fixture.parts[0].materialCount = 0;
        fixture.parts[0].materials = {};
        backing->failAfter = 0;
        bool failed = false;
        try { data.FinishObject(fixture.mesh,1); }
        catch (const std::bad_alloc&) { failed = true; }
        backing->failAfter = -1;
        checks.Equal("later allocation failure observed", true, failed);
        checks.Equal("failed finish clears records with retained owner", std::size_t(0), data.Size());
        checks.Equal("retained prefix survives unwind", true, first->GetTriangle(0,triangle));
    }
    // Malformed stream rejection precedes allocation and cannot read past a
    // bounded serializer span. Each case follows a successful production finish.
    for (int bad=0; bad<7; ++bad)
    {
        Fixture fixture;
        FastMeshPackfileData data(backing);
        data.FinishObject(fixture.mesh,1);
        if (bad == 0) fixture.parts[0].vertexStride = 0;
        if (bad == 1) fixture.parts[0].indices = fixture.parts[0].indices.first(3);
        if (bad == 2) fixture.mesh.subpartBits = 32;
        if (bad == 3) fixture.materialIndices[0] = std::byte{2};
        if (bad == 4) fixture.parts[0].materialStride = 0;
        if (bad == 5) fixture.parts[0].weldingOffset = 1;
        if (bad == 6) fixture.parts[0].indexType = 3;
        bool failed = false;
        try { data.FinishObject(fixture.mesh,1); }
        catch (const std::invalid_argument&) { failed = true; }
        checks.Equal("malformed finish rejected", true, failed);
        checks.Equal("malformed finish cleans finished prefix", std::size_t(0), data.Size());
        checks.Equal("malformed finish releases native allocations", std::size_t(0), backing->blocks.size());
    }
    {
        Fixture fixture;
        retained = FastMesh::Finish(fixture.mesh,1,backing);
    }
    backing.reset();
    checks.Equal("supplying allocator retained by native owner", false, weakBacking.expired());
    std::thread release([owner=std::move(retained)]() mutable { owner.reset(); });
    release.join();
    checks.Equal("last release destroys supplier after frees", true, weakBacking.expired());
    if (!checks.ExitCode())
        std::printf("fast-mesh native materialization: geometry, finish state, typed queries, cleanup, %d allocation failures, malformed streams and last release passed\n", failures);
    return checks.ExitCode();
}
