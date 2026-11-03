// include/havok/hkpCompressedMeshShapeConvexPiece.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPCOMPRESSEDMESHSHAPECONVEXPIECE_H
#define FNV_HAVOK_HKPCOMPRESSEDMESHSHAPECONVEXPIECE_H

#include "hkBase.h"
class hkpCompressedMeshShapeConvexPiece
{
  public:
    hkVector4 m_offset;                // +0x0
    hkArray<hkUint16> m_kVertices;     // +0x10
    hkArray<hkUint8> m_kFaceVertices;  // +0x1C
    hkArray<hkUint16> m_kIndices;      // +0x28
    hkUint16 m_kSmartReference;        // +0x34
    hkUint16 m_iSectionVertexCount;    // +0x36
    char pad38[0x8];
};
#endif
