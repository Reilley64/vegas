// Native mesh. Descriptor/welding arrays are owned; vertex/index streams are borrowed.
#ifndef FNV_HAVOK_HKPMESHSHAPE_H
#define FNV_HAVOK_HKPMESHSHAPE_H

#include "hkBase.h"
#include "hkpShapeCollection.h"
#include "hkpMeshShapeSubpart.h"
#include "hkpTriangleShape.h"
#include <span>
class hkMemoryAllocator;
class hkAabb;
class hkpMeshShape : public hkpShapeCollection
{
  public:
    enum MeshShapeIndexStridingType
    {
        INDICES_INVALID = 0,
        INDICES_INT16 = 1,
        INDICES_INT32 = 2,
        INDICES_MAX_ID = 3
    };
    enum MeshShapeMaterialIndexStridingType
    {
        MATERIAL_INDICES_INVALID = 0,
        MATERIAL_INDICES_INT8 = 1,
        MATERIAL_INDICES_INT16 = 2,
        MATERIAL_INDICES_MAX_ID = 3
    };
    // Valid keys and live, suitably strided streams are caller prerequisites.
    // Borrowed streams must outlive this mesh, including retained MOPP owners.
    hkpMeshShape(hkReal radius, int subpartBits,
                 std::span<const hkpMeshShapeSubpart> subparts = {},
                 std::span<const hkUint16> welding = {});
    ~hkpMeshShape() override;
    const hkpTriangleShape* getChildShape(hkUint32 key, hkpShapeBuffer& buffer) const override;
    void getAabb(const hkTransform& placement, hkReal margin, hkAabb& bounds) const;
    void setScaling(const hkVector4& scaling) noexcept;
    hkpMeshShape(const hkpMeshShape&) = delete;
    hkpMeshShape& operator=(const hkpMeshShape&) = delete;
    hkVector4 m_kScaling;
    hkInt32 m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpart> m_kSubparts;
    hkArray<hkUint16> m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    hkReal m_fSphereRadius;
    hkInt32 m_auiShapeKeys[3];        // Not initialized by fresh construction.

  private:
    hkMemoryAllocator* arrayAllocator = nullptr;
    int subpartAllocationBytes = 0;
    int weldingAllocationBytes = 0;
};
#endif
