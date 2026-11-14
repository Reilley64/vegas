// include/havok/hkaWaveletCompressedAnimationQuantizationFormat.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKAWAVELETCOMPRESSEDANIMATIONQUANTIZATIONFORMAT_H
#define FNV_HAVOK_HKAWAVELETCOMPRESSEDANIMATIONQUANTIZATIONFORMAT_H
#include "hkBase.h"
class hkaWaveletCompressedAnimationQuantizationFormat
{
  public:
    hkUint8 m_ucFirstQuantizationParameter;   // +0x0
    hkUint8 m_ucSecondQuantizationParameter;  // +0x1
    char pad2[0x2];
    hkUint32 m_uiDynamicDofCount;      // +0x4
    hkUint32 m_uiOffsetIndexOffset;    // +0x8
    hkUint32 m_uiScaleIndexOffset;     // +0xC
    hkUint32 m_uiBitWidthIndexOffset;  // +0x10
};
#endif
