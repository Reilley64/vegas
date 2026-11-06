#include "havok/hkpMeshShape.h"
#include "havok/hkpShapeBuffer.h"
#include "havok/hkAabb.h"
#include "havok/hkMemoryRouter.h"

#include <algorithm>
#include <cstring>
#include <new>
#include <stdexcept>

namespace
{
template<class T>
hkArray<T> CopyArray(std::span<const T> input, hkMemoryAllocator& heap, int& allocationBytes)
{
    if (input.empty())
        return {nullptr, 0, static_cast<int>(0x80000000u)};
    if (input.size_bytes() > 0x3fffffffu)
        throw std::length_error("Mesh array exceeds native capacity");
    int bytes = static_cast<int>(input.size_bytes());
    auto* data = static_cast<T*>(heap.bufAlloc(bytes));
    if (!data)
        throw std::bad_alloc();
    if (bytes < static_cast<int>(input.size_bytes()) || bytes > 0x3fffffff)
    {
        heap.bufFree(data, bytes);
        throw std::length_error("Mesh allocator returned an invalid capacity");
    }
    // These are trivial descriptor/value types, not serialized object layouts.
    std::memcpy(data, input.data(), input.size_bytes());
    allocationBytes = bytes;
    return {data, static_cast<int>(input.size()), bytes / static_cast<int>(sizeof(T))};
}

template<class T>
void FreeArray(hkArray<T>& array, hkMemoryAllocator* heap, int allocationBytes)
{
    if (array.m_data)
        heap->bufFree(array.m_data, allocationBytes);
}

template<class T>
T Read(const void* base, std::size_t offset)
{
    T value;
    std::memcpy(&value, static_cast<const char*>(base) + offset, sizeof(value));
    return value;
}

// The names in the reflected descriptor are misleading: the existing
// 00dccf60 and 00dccdd0 operations use the first pointer/stride for vertices,
// and the fourth pointer/material stride for triangle indices.
hkVector4 Vertex(const hkpMeshShapeSubpart& part, hkUint32 face, unsigned corner,
                 const hkVector4& scaling)
{
    const std::size_t indexOffset = std::size_t(part.m_iMaterialStriding) * face;
    const hkUint32 index = part.m_ucIndexStridingType == hkpMeshShape::INDICES_INT16
        ? Read<hkUint16>(part.m_pMaterialDataBase, indexOffset + corner * sizeof(hkUint16))
        : Read<hkUint32>(part.m_pMaterialDataBase, indexOffset + corner * sizeof(hkUint32));
    const std::size_t offset = std::size_t(index) * part.m_iTriangleIndexStride;
    return {Read<float>(part.m_pMaterialIndexBase, offset) * scaling.x,
            Read<float>(part.m_pMaterialIndexBase, offset + sizeof(float)) * scaling.y,
            Read<float>(part.m_pMaterialIndexBase, offset + 2 * sizeof(float)) * scaling.z, 0};
}
}

// Fresh construction follows 00dcd310 -> 00d21410. The descriptor and welding
// copies own only their arrays; vertex/index backing remains caller-owned.
hkpMeshShape::hkpMeshShape(hkReal radius, int subpartBits,
                         std::span<const hkpMeshShapeSubpart> subparts,
                         std::span<const hkUint16> welding)
    : hkpShapeCollection(0x17, COLLECTION_MESH_SHAPE), m_kScaling{1, 1, 1, 1},
      m_iNumBitsForSubpartIndex(subpartBits),
      m_kSubparts{nullptr, 0, static_cast<int>(0x80000000u)},
      m_kWeldingInfo{nullptr, 0, static_cast<int>(0x80000000u)},
      m_eWeldingType(6), m_fSphereRadius(radius)
{
    if (!subparts.empty() || !welding.empty())
    {
        arrayAllocator = &hkMemoryRouter::getInstance().heap();
        m_kSubparts = CopyArray(subparts, *arrayAllocator, subpartAllocationBytes);
        try { m_kWeldingInfo = CopyArray(welding, *arrayAllocator, weldingAllocationBytes); }
        catch (...)
        {
            FreeArray(m_kSubparts, arrayAllocator, subpartAllocationBytes);
            throw;
        }
    }
}

hkpMeshShape::~hkpMeshShape()
{
    FreeArray(m_kWeldingInfo, arrayAllocator, weldingAllocationBytes);
    FreeArray(m_kSubparts, arrayAllocator, subpartAllocationBytes);
}

// Native port of 00dccf60. Valid keys are decoded once; no new malformed-input
// semantics are implied. The scoped output owns the constructed triangle.
const hkpTriangleShape* hkpMeshShape::getChildShape(hkUint32 key, hkpShapeBuffer& buffer) const
{
    const hkUint32 face = key & (~0u >> m_iNumBitsForSubpartIndex);
    const auto& part = m_kSubparts.m_data[key >> (32 - m_iNumBitsForSubpartIndex)];
    const unsigned flip = part.m_bFlipAlternateTriangles & face;
    const hkUint16 welding = m_kWeldingInfo.m_iElementCount == 0
        ? 0 : m_kWeldingInfo.m_data[part.m_iTriangleOffset + face];
    return &buffer.triangle.emplace(m_fSphereRadius, welding, m_eWeldingType,
        Vertex(part, face, 0, m_kScaling),
        Vertex(part, face, 1 + flip, m_kScaling),
        Vertex(part, face, 1 + (flip ^ 1), m_kScaling));
}

// Native port of the existing 00dccdd0 collection consumer: include indexed
// triangle vertices (not unused vertices), transform, then expand by radius
// plus margin. This is a rigid-placement operation, not a new affine contract.
void hkpMeshShape::getAabb(const hkTransform& placement, hkReal margin, hkAabb& bounds) const
{
    bounds.m_kMinimumCorner = {3.402820018375656e+38f, 3.402820018375656e+38f, 3.402820018375656e+38f, 0};
    bounds.m_kMaximumCorner = {-3.402820018375656e+38f, -3.402820018375656e+38f, -3.402820018375656e+38f, 0};
    hkpShapeBuffer buffer;
    const hkpShapeCollection& collection = *this;
    for (int p = 0; p < m_kSubparts.m_iElementCount; ++p)
        for (hkUint32 face = 0; face < static_cast<hkUint32>(m_kSubparts.m_data[p].m_iTriangleCount); ++face)
        {
            const auto key = (hkUint32(p) << (32 - m_iNumBitsForSubpartIndex)) | face;
            const auto* triangle = static_cast<const hkpTriangleShape*>(collection.getChildShape(key, buffer));
            for (int i = 0; i < 3; ++i)
            {
                const auto& v = triangle->getVertex(i);
                const auto& r = placement.m_rotation;
                const hkVector4 world{
                    (r.m_kColumn1.x * v.y + r.m_kColumn0.x * v.x) + (r.m_kColumn2.x * v.z + placement.m_vTranslation.x),
                    (r.m_kColumn1.y * v.y + r.m_kColumn0.y * v.x) + (r.m_kColumn2.y * v.z + placement.m_vTranslation.y),
                    (r.m_kColumn1.z * v.y + r.m_kColumn0.z * v.x) + (r.m_kColumn2.z * v.z + placement.m_vTranslation.z),
                    (r.m_kColumn1.w * v.y + r.m_kColumn0.w * v.x) + (r.m_kColumn2.w * v.z + placement.m_vTranslation.w)};
                bounds.m_kMinimumCorner.x = std::min(bounds.m_kMinimumCorner.x, world.x);
                bounds.m_kMinimumCorner.y = std::min(bounds.m_kMinimumCorner.y, world.y);
                bounds.m_kMinimumCorner.z = std::min(bounds.m_kMinimumCorner.z, world.z);
                bounds.m_kMinimumCorner.w = std::min(bounds.m_kMinimumCorner.w, world.w);
                bounds.m_kMaximumCorner.x = std::max(bounds.m_kMaximumCorner.x, world.x);
                bounds.m_kMaximumCorner.y = std::max(bounds.m_kMaximumCorner.y, world.y);
                bounds.m_kMaximumCorner.z = std::max(bounds.m_kMaximumCorner.z, world.z);
                bounds.m_kMaximumCorner.w = std::max(bounds.m_kMaximumCorner.w, world.w);
            }
        }
    const float expansion = margin + m_fSphereRadius;
    bounds.m_kMinimumCorner.x -= expansion;
    bounds.m_kMinimumCorner.y -= expansion;
    bounds.m_kMinimumCorner.z -= expansion;
    bounds.m_kMinimumCorner.w -= expansion;
    bounds.m_kMaximumCorner.x += expansion;
    bounds.m_kMaximumCorner.y += expansion;
    bounds.m_kMaximumCorner.z += expansion;
    bounds.m_kMaximumCorner.w += expansion;
}

// 00dccf40, without assuming SIMD alignment of an ordinary native value.
void hkpMeshShape::setScaling(const hkVector4& scaling) noexcept { m_kScaling = scaling; }
