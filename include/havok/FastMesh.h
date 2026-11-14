#pragma once

#include "runtime/havok_memory_prerequisite.h"
#include "havok/hkpShapeCollection.h"
#include "havok/hkpTriangleShape.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <memory_resource>
#include <span>
#include <vector>

// Native materialization, not a view of reflected or serialized object storage.
// Never cast a serialized hkpFastMeshShape, or a legacy shape table, to these types.
namespace havok::fast_mesh
{
struct Vec3 { float x = 0, y = 0, z = 0; };
struct Transform
{
    std::array<Vec3,3> columns{{{1,0,0},{0,1,0},{0,0,1}}};
    Vec3 translation;
};
struct Aabb
{
    Vec3 min, max;
    bool Empty() const noexcept { return min.x > max.x || min.y > max.y || min.z > max.z; }
};
struct RayHit
{
    float fraction = 1;
    Vec3 normal;
    std::uint32_t key = ~0u;
};
struct Triangle
{
    std::array<Vec3,3> vertices;
    float radius = 0;
    std::uint16_t welding = 0;
    std::uint8_t weldingType = 0;
};

// Decoded, bounded streams supplied by a packfile owner after pointer fixups.
// These are not file-format layouts. Geometry names describe the operations in
// CreateTriangle/FUN_00e48cb0, not the misleading reflected pointer names.
struct LoadedSubpart
{
    std::span<const std::byte> vertices;
    int vertexCount = 0;
    int vertexStride = 0;
    std::span<const std::byte> indices;
    int triangleCount = 0;
    int triangleStride = 0;
    unsigned indexType = 1; // 1: uint16, 2: uint32
    unsigned flipAlternateTriangles = 0;
    std::span<const std::byte> materialIndices;
    unsigned materialIndexType = 0; // 0 is fixed to 1 only when finishing
    int materialIndexStride = 0;
    std::span<const std::byte> materials;
    int materialCount = 0;
    int materialStride = 0;
    int weldingOffset = 0;
};
struct LoadedMesh
{
    Vec3 scaling{1,1,1};
    int subpartBits = 12;
    std::span<const LoadedSubpart> subparts;
    std::span<const std::uint16_t> welding;
    unsigned weldingType = 0;
    float radius = 0;
    std::uintptr_t userData = 0;
    unsigned shapeType = 0x17;
    unsigned collectionType = 5;
    bool disableWelding = false;
    std::array<int,3> shapeKeys{};
};

class Shape
{
  public:
    virtual ~Shape() = default;
    virtual Aabb GetAabb(const Transform&, float tolerance) const = 0;
    // Segment query, double-sided triangles. Closest hit before hit.fraction wins.
    // Radius is the collision margin used by AABB, not a ray-triangle extrusion.
    virtual bool CastRay(Vec3 from, Vec3 to, RayHit&) const = 0;
};
class FastMesh;
using Handle = std::shared_ptr<const FastMesh>;

// The allocating decoder publishes this genuine native collection. Its handle
// owns one native reference; native shape owners may retain it independently.
class FastMesh final : public hkpShapeCollection, public Shape
{
  public:
    // The shared supplier is captured before allocation and survives final Free.
    // Geometry, indices, materials and welding are copied, never adopted from a
    // serializer buffer. No allocation prefix is read from caller-owned storage.
    static Handle Create(float radius, int subpartBits, std::shared_ptr<native_memory::Allocator>);
    static Handle Finish(const LoadedMesh&, int finishing, std::shared_ptr<native_memory::Allocator>);
    ~FastMesh() override;
    FastMesh(const FastMesh&) = delete;
    FastMesh& operator=(const FastMesh&) = delete;
    bool GetTriangle(std::uint32_t key, Triangle&) const noexcept;
    // Valid keys use the shared native collection protocol. The returned child
    // is borrowed from the scoped buffer, not serialized/legacy scratch storage.
    const hkpTriangleShape* getChildShape(hkUint32 key, hkpShapeBuffer&) const noexcept override;
    std::span<const std::byte> Material(std::uint32_t key) const noexcept;
    LoadedSubpart Subpart(std::size_t) const;
    std::size_t SubpartCount() const noexcept { return parts.size(); }
    unsigned ShapeType() const noexcept { return getType(); }
    unsigned CollectionType() const noexcept { return m_eCollectionType; }
    std::uintptr_t UserData() const noexcept { return m_ulUserData; }
    bool DisableWelding() const noexcept { return m_bDisableWelding != 0; }
    unsigned WeldingType() const noexcept { return weldingType; }
    const std::array<int,3>& ShapeKeys() const noexcept { return shapeKeys; }
    Aabb GetAabb(const Transform&, float tolerance) const override;
    bool CastRay(Vec3 from, Vec3 to, RayHit&) const override;

  private:
    class Resource final : public std::pmr::memory_resource
    {
      public:
        explicit Resource(std::shared_ptr<native_memory::Allocator> supplier) : supplier(std::move(supplier)) {}
      private:
        void* do_allocate(std::size_t, std::size_t) override;
        void do_deallocate(void*, std::size_t, std::size_t) override;
        bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override { return this == &other; }
        std::shared_ptr<native_memory::Allocator> supplier;
    };
    struct Part
    {
        explicit Part(const LoadedSubpart&, std::pmr::memory_resource*);
        LoadedSubpart View() const noexcept;
        LoadedSubpart state;
        std::pmr::vector<std::byte> vertices, indices, materialIndices, materials;
    };
    FastMesh(const LoadedMesh&, int finishing, std::shared_ptr<native_memory::Allocator>);
    static void Validate(const LoadedMesh&, int finishing);
    bool DecodeKey(std::uint32_t, std::size_t& part, std::size_t& triangle) const noexcept;
    // Destruction order is intentional: stream vectors precede their resource.
    Resource resource;
    std::pmr::vector<Part> parts;
    std::pmr::vector<std::uint16_t> welding;
    Vec3 scaling;
    int subpartBits;
    unsigned weldingType;
    float radius;
    std::array<int,3> shapeKeys;
};
}
