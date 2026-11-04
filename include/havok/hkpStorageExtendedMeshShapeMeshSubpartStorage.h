// include/havok/hkpStorageExtendedMeshShapeMeshSubpartStorage.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x68.
#ifndef FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPEMESHSUBPARTSTORAGE_H
#define FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPEMESHSUBPARTSTORAGE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpNamedMeshMaterial;
class hkpStorageExtendedMeshShapeMaterial;
class hkpStorageExtendedMeshShapeMeshSubpartStorage : public hkReferencedObject
{
  public:
    hkArray<hkVector4> m_kVertices;                             // +0x8
    hkArray<hkUint8> m_kIndices8;                               // +0x14
    hkArray<hkUint16> m_kIndices16;                             // +0x20
    hkArray<hkUint32> m_kIndices32;                             // +0x2C
    hkArray<hkUint8> m_kMaterialIndices8;                       // +0x38
    hkArray<hkpStorageExtendedMeshShapeMaterial> m_kMaterials;  // +0x44
    hkArray<hkpNamedMeshMaterial> m_kNamedMaterials;            // +0x50
    hkArray<hkUint16> m_kMaterialIndices16;                     // +0x5C
};
#endif
