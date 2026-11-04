// include/havok/hkpStorageMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPSTORAGEMESHSHAPE_H
#define FNV_HAVOK_HKPSTORAGEMESHSHAPE_H

#include "hkBase.h"
#include "hkpMeshShape.h"
class hkpStorageMeshShapeSubpartStorage;
class hkpStorageMeshShape : public hkpMeshShape
{
  public:
    hkArray<hkpStorageMeshShapeSubpartStorage*> m_kStorage;  // +0x60
    char pad6C[0x4];
};
#endif
