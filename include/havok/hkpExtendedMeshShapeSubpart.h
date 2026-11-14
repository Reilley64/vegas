// include/havok/hkpExtendedMeshShapeSubpart.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPEXTENDEDMESHSHAPESUBPART_H
#define FNV_HAVOK_HKPEXTENDEDMESHSHAPESUBPART_H

#include "hkBase.h"
class hkpExtendedMeshShapeSubpart
{
  public:
    hkInt8 m_type;                // +0x0 (SubpartType)
    hkInt8 m_iMaterialIndexType;  // +0x1 (MaterialIndexStridingType)
    hkInt16 m_iIndexStriding;     // +0x2
    void* m_pVertexBase;          // +0x4
    hkUint16 m_iVertexStriding;   // +0x8
    hkUint16 m_iNumTriangles;     // +0xA
    void* m_pIndexBase;           // +0xC
    void* m_pMaterialBase;        // +0x10
};
#endif
