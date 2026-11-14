// include/havok/hkpCompressedMeshShapeBigTriangle.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPCOMPRESSEDMESHSHAPEBIGTRIANGLE_H
#define FNV_HAVOK_HKPCOMPRESSEDMESHSHAPEBIGTRIANGLE_H

#include "hkBase.h"
class hkpCompressedMeshShapeBigTriangle
{
  public:
    hkUint16 m_kPointA;  // +0x0
    hkUint16 m_kPointB;  // +0x2
    hkUint16 m_iThirdValue;  // +0x4
    char pad6[0x2];
    hkUint32 m_iMaterialIndex;  // +0x8
    hkUint16 m_kWeldingInfo;    // +0xC
    char padE[0x2];
};
#endif
