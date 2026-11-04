// include/havok/hkpStorageMeshShapeSubpartStorage.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPSTORAGEMESHSHAPESUBPARTSTORAGE_H
#define FNV_HAVOK_HKPSTORAGEMESHSHAPESUBPARTSTORAGE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpStorageMeshShapeSubpartStorage : public hkReferencedObject
{
  public:
    hkArray<hkReal> m_kVertices;             // +0x8
    hkArray<hkUint16> m_kIndices16;          // +0x14
    hkArray<hkUint32> m_kIndices32;          // +0x20
    hkArray<hkUint8> m_kMaterialIndices8;    // +0x2C
    hkArray<hkUint32> m_kMaterials;          // +0x38
    hkArray<hkUint16> m_kMaterialIndices16;  // +0x44
};
#endif
