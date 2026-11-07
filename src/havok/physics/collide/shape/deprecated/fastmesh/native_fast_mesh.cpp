#include "havok/FastMesh.h"
#include "havok/hkpShapeBuffer.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>

namespace havok::fast_mesh
{
namespace
{
bool Finite(Vec3 v) { return std::isfinite(v.x) && std::isfinite(v.y) && std::isfinite(v.z); }
Vec3 Subtract(Vec3 a, Vec3 b) { return {a.x-b.x,a.y-b.y,a.z-b.z}; }
Vec3 Cross(Vec3 a, Vec3 b) { return {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x}; }
double Dot(Vec3 a, Vec3 b) { return double(a.x)*b.x+double(a.y)*b.y+double(a.z)*b.z; }
Vec3 Apply(const Transform& t, Vec3 v)
{
    return {t.translation.x+t.columns[0].x*v.x+t.columns[1].x*v.y+t.columns[2].x*v.z,
            t.translation.y+t.columns[0].y*v.x+t.columns[1].y*v.y+t.columns[2].y*v.z,
            t.translation.z+t.columns[0].z*v.x+t.columns[1].z*v.y+t.columns[2].z*v.z};
}
void Include(Aabb& a, Vec3 v)
{
    a.min = {std::min(a.min.x,v.x), std::min(a.min.y,v.y), std::min(a.min.z,v.z)};
    a.max = {std::max(a.max.x,v.x), std::max(a.max.y,v.y), std::max(a.max.z,v.z)};
}
void Require(bool condition)
{
    if (!condition) throw std::invalid_argument("Invalid fast-mesh stream or state");
}
void CheckStream(std::span<const std::byte> bytes, int count, int stride, std::size_t width,
                 std::size_t minimumStride, bool allowConstant = false)
{
    Require(count >= 0 && stride >= 0);
    if (!count) return;
    if (allowConstant && stride == 0)
    {
        Require(bytes.size() >= width);
        return;
    }
    Require(stride > 0 && std::size_t(stride) >= minimumStride);
    const std::size_t last = std::size_t(count-1);
    Require(last <= (std::numeric_limits<std::size_t>::max()-width)/std::size_t(stride));
    Require(bytes.size() >= last*std::size_t(stride)+width);
}
std::uint32_t ReadIndex(std::span<const std::byte> bytes, std::size_t offset, unsigned type) noexcept
{
    if (type == 1)
    {
        std::uint16_t value;
        std::memcpy(&value,bytes.data()+offset,sizeof(value));
        return value;
    }
    std::uint32_t value;
    std::memcpy(&value,bytes.data()+offset,sizeof(value));
    return value;
}
std::uint32_t ReadMaterial(const LoadedSubpart& p, std::size_t triangle) noexcept
{
    const std::size_t offset = triangle*std::size_t(p.materialIndexStride);
    if (p.materialIndexType == 1) return std::to_integer<unsigned char>(p.materialIndices[offset]);
    std::uint16_t value;
    std::memcpy(&value,p.materialIndices.data()+offset,sizeof(value));
    return value;
}
Vec3 Vertex(const LoadedSubpart& p, std::size_t index, Vec3 scale) noexcept
{
    Vec3 v;
    std::memcpy(&v,p.vertices.data()+index*std::size_t(p.vertexStride),sizeof(v));
    return {v.x*scale.x,v.y*scale.y,v.z*scale.z};
}
}

void* FastMesh::Resource::do_allocate(std::size_t bytes, std::size_t alignment)
{
    if (alignment > 16) throw std::bad_alloc();
    void* block = supplier->Allocate(std::max(bytes,std::size_t(1)));
    if (!block) throw std::bad_alloc();
    return block;
}
void FastMesh::Resource::do_deallocate(void* block, std::size_t bytes, std::size_t)
{
    supplier->Free(block,std::max(bytes,std::size_t(1)));
}

FastMesh::Part::Part(const LoadedSubpart& source, std::pmr::memory_resource* resource)
    : state(source), vertices(source.vertices.begin(),source.vertices.end(),resource),
      indices(source.indices.begin(),source.indices.end(),resource),
      materialIndices(source.materialIndices.begin(),source.materialIndices.end(),resource),
      materials(source.materials.begin(),source.materials.end(),resource)
{
    // Only owned vectors retain addresses after materialization.
    state.vertices = {}; state.indices = {}; state.materialIndices = {}; state.materials = {};
}
LoadedSubpart FastMesh::Part::View() const noexcept
{
    LoadedSubpart result = state;
    result.vertices = vertices; result.indices = indices;
    result.materialIndices = materialIndices; result.materials = materials;
    return result;
}

void FastMesh::Validate(const LoadedMesh& mesh, int finishing)
{
    Require(mesh.subpartBits > 0 && mesh.subpartBits < 32);
    Require(Finite(mesh.scaling) && std::isfinite(mesh.radius) && mesh.radius >= 0);
    Require(mesh.weldingType <= 255 && mesh.collectionType <= 255);
    const std::uint64_t partCapacity = std::uint64_t(1) << mesh.subpartBits;
    Require(mesh.subparts.size() <= partCapacity);
    const std::uint32_t triangleMask = ~0u >> mesh.subpartBits;
    for (const auto& p : mesh.subparts)
    {
        Require(p.triangleCount >= 0 && std::uint64_t(p.triangleCount) <= std::uint64_t(triangleMask)+1);
        // Only the final key of the full partition collides with the sentinel.
        if (mesh.subparts.size() == partCapacity && &p == &mesh.subparts.back())
            Require(std::uint64_t(p.triangleCount) <= triangleMask);
        Require(p.indexType == 1 || p.indexType == 2);
        Require(p.flipAlternateTriangles <= 1 && p.weldingOffset >= 0);
        Require(p.materialIndexType <= 2 && p.materialCount >= 0 && p.materialStride >= 0);
        CheckStream(p.vertices,p.vertexCount,p.vertexStride,sizeof(Vec3),sizeof(Vec3));
        const unsigned indexBytes = p.indexType == 1 ? 2 : 4;
        // Strip triangles share indices: the readable record is three indices,
        // but its next start may advance by only one or two index widths.
        CheckStream(p.indices,p.triangleCount,p.triangleStride,3*indexBytes,indexBytes);
        CheckStream(p.materials,p.materialCount,p.materialStride,std::size_t(p.materialStride),std::size_t(p.materialStride));
        const unsigned materialType = finishing && p.materialIndexType == 0 ? 1 : p.materialIndexType;
        if (p.materialCount)
        {
            Require(p.materialStride > 0);
            if (materialType)
                CheckStream(p.materialIndices,p.triangleCount,p.materialIndexStride,materialType,materialType,true);
        }
        if (!mesh.welding.empty())
        {
            Require(std::size_t(p.weldingOffset) <= mesh.welding.size());
            Require(std::size_t(p.triangleCount) <= mesh.welding.size()-std::size_t(p.weldingOffset));
        }
        for (int i=0; i<p.vertexCount; ++i) Require(Finite(Vertex(p,std::size_t(i),mesh.scaling)));
        for (int i=0; i<p.triangleCount; ++i)
        {
            for (unsigned j=0; j<3; ++j)
                Require(ReadIndex(p.indices,std::size_t(i)*p.triangleStride+j*indexBytes,p.indexType) < unsigned(p.vertexCount));
            if (p.materialCount && materialType)
            {
                auto effective = p;
                effective.materialIndexType = materialType;
                Require(ReadMaterial(effective,std::size_t(i)) < unsigned(p.materialCount));
            }
        }
    }
}

FastMesh::FastMesh(const LoadedMesh& mesh, int finishing, std::shared_ptr<native_memory::Allocator> supplier)
    : hkpShapeCollection(mesh.shapeType, static_cast<hkUint8>(mesh.collectionType)),
      resource(std::move(supplier)), parts(&resource), welding(mesh.welding.begin(),mesh.welding.end(),&resource),
      scaling(mesh.scaling), subpartBits(mesh.subpartBits), weldingType(mesh.weldingType), radius(mesh.radius),
      shapeKeys(mesh.shapeKeys)
{
    m_ulUserData = mesh.userData;
    m_bDisableWelding = mesh.disableWelding;
    parts.reserve(mesh.subparts.size());
    for (const auto& p : mesh.subparts) parts.emplace_back(p,&resource);
    if (finishing)
    {
        for (auto& p : parts) if (p.state.materialIndexType == 0) p.state.materialIndexType = 1;
        m_type = 0x17;
        m_eCollectionType = COLLECTION_MESH_SHAPE;
    }
}
FastMesh::~FastMesh() = default;

Handle FastMesh::Finish(const LoadedMesh& mesh, int finishing, std::shared_ptr<native_memory::Allocator> supplier)
{
    Require(bool(supplier));
    Validate(mesh,finishing);
    auto* object = new (supplier) FastMesh(mesh,finishing,supplier);
    // The handle owns the initial native reference. Other real shape owners
    // (including MOPP containers) can retain the same object after it is reset.
    // shared_ptr also invokes this deleter if control-block allocation throws.
    return Handle(object,[](const FastMesh* mesh) noexcept { mesh->removeReference(); });
}
Handle FastMesh::Create(float radius, int subpartBits, std::shared_ptr<native_memory::Allocator> supplier)
{
    LoadedMesh mesh;
    mesh.radius = radius;
    mesh.subpartBits = subpartBits;
    mesh.weldingType = 6; // FUN_00dcd310 fresh-construction default, not a finish override.
    return Finish(mesh,1,std::move(supplier));
}

bool FastMesh::DecodeKey(std::uint32_t key, std::size_t& part, std::size_t& triangle) const noexcept
{
    if (key == ~0u) return false;
    part = key >> (32-subpartBits);
    triangle = key & (~0u >> subpartBits);
    return part < parts.size() && triangle < std::size_t(parts[part].state.triangleCount);
}
LoadedSubpart FastMesh::Subpart(std::size_t index) const { return parts.at(index).View(); }
bool FastMesh::GetTriangle(std::uint32_t key, Triangle& result) const noexcept
{
    std::size_t part, triangle;
    if (!DecodeKey(key,part,triangle)) return false;
    hkpShapeBuffer buffer;
    const hkpShapeCollection& collection = *this;
    const auto* child = static_cast<const hkpTriangleShape*>(collection.getChildShape(key,buffer));
    Triangle output;
    for (int i=0; i<3; ++i)
    {
        const auto& v = child->getVertex(i);
        output.vertices[i] = {v.x,v.y,v.z};
    }
    output.radius = child->getRadius();
    output.welding = child->getWeldingInfo();
    output.weldingType = child->getWeldingType();
    result = output;
    return true;
}

const hkpTriangleShape* FastMesh::getChildShape(hkUint32 key, hkpShapeBuffer& buffer) const noexcept
{
    const auto part = key >> (32-subpartBits);
    const auto triangle = key & (~0u >> subpartBits);
    const auto p = parts[part].View();
    const unsigned width = p.indexType == 1 ? 2 : 4;
    const unsigned flip = p.flipAlternateTriangles & triangle;
    const std::array<unsigned,3> order{0,1+flip,1+(flip^1)};
    std::array<hkVector4,3> vertices;
    for (unsigned i=0; i<3; ++i)
    {
        const auto v = Vertex(p,ReadIndex(p.indices,std::size_t(triangle)*p.triangleStride+order[i]*width,p.indexType),scaling);
        vertices[i] = {v.x,v.y,v.z,0};
    }
    return &buffer.setTriangle(radius, welding.empty() ? 0 : welding[std::size_t(p.weldingOffset)+triangle],
                               std::uint8_t(weldingType), vertices[0], vertices[1], vertices[2]);
}
std::span<const std::byte> FastMesh::Material(std::uint32_t key) const noexcept
{
    std::size_t part, triangle;
    if (!DecodeKey(key,part,triangle)) return {};
    const auto p = parts[part].View();
    if (!p.materialCount || !p.materialIndexType) return {};
    return p.materials.subspan(std::size_t(ReadMaterial(p,triangle))*p.materialStride,std::size_t(p.materialStride));
}

Aabb FastMesh::GetAabb(const Transform& transform, float tolerance) const
{
    Require(Finite(transform.translation) && std::isfinite(tolerance) && tolerance >= 0);
    for (auto column : transform.columns) Require(Finite(column));
    const float infinity = std::numeric_limits<float>::infinity();
    Aabb bounds{{infinity,infinity,infinity},{-infinity,-infinity,-infinity}};
    for (const auto& part : parts)
    {
        const auto p = part.View();
        for (int i=0; i<p.vertexCount; ++i) Include(bounds,Apply(transform,Vertex(p,std::size_t(i),scaling)));
    }
    if (!bounds.Empty())
    {
        // Also conservative for a finite affine transform, not just a rotation.
        const auto& c = transform.columns;
        const Vec3 margin{
            float(radius*std::sqrt(double(c[0].x)*c[0].x+double(c[1].x)*c[1].x+double(c[2].x)*c[2].x)+tolerance),
            float(radius*std::sqrt(double(c[0].y)*c[0].y+double(c[1].y)*c[1].y+double(c[2].y)*c[2].y)+tolerance),
            float(radius*std::sqrt(double(c[0].z)*c[0].z+double(c[1].z)*c[1].z+double(c[2].z)*c[2].z)+tolerance)};
        bounds.min = Subtract(bounds.min,margin);
        bounds.max = {bounds.max.x+margin.x,bounds.max.y+margin.y,bounds.max.z+margin.z};
    }
    return bounds;
}

bool FastMesh::CastRay(Vec3 from, Vec3 to, RayHit& hit) const
{
    Require(Finite(from) && Finite(to) && std::isfinite(hit.fraction) && hit.fraction >= 0 && hit.fraction <= 1);
    const Vec3 direction = Subtract(to,from);
    bool found = false;
    for (std::size_t part=0; part<parts.size(); ++part)
    {
        // Validate rejects negative counts before this signed-to-unsigned boundary.
        for (std::uint32_t triangle=0; triangle<std::uint32_t(parts[part].state.triangleCount); ++triangle)
        {
            const auto key = (std::uint32_t(part) << (32-subpartBits)) | triangle;
            Triangle t;
            if (!GetTriangle(key,t)) continue;
            const Vec3 edge1 = Subtract(t.vertices[1],t.vertices[0]);
            const Vec3 edge2 = Subtract(t.vertices[2],t.vertices[0]);
            const Vec3 p = Cross(direction,edge2);
            const double determinant = Dot(edge1,p);
            if (determinant == 0) continue;
            const Vec3 distance = Subtract(from,t.vertices[0]);
            const double u = Dot(distance,p)/determinant;
            if (u < 0 || u > 1) continue;
            const Vec3 q = Cross(distance,edge1);
            const double v = Dot(direction,q)/determinant;
            if (v < 0 || u+v > 1) continue;
            const double fraction = Dot(edge2,q)/determinant;
            if (fraction < 0 || fraction >= hit.fraction) continue;
            const Vec3 normal = Cross(edge1,edge2);
            const double length = std::sqrt(Dot(normal,normal));
            if (!std::isfinite(fraction) || !std::isfinite(length) || length == 0) continue;
            hit.fraction = float(fraction);
            hit.normal = {float(normal.x/length),float(normal.y/length),float(normal.z/length)};
            hit.key = key;
            found = true;
        }
    }
    return found;
}
}
