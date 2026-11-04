// include/havok/hkpStiffSpringChainDataConstraintInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPSTIFFSPRINGCHAINDATACONSTRAINTINFO_H
#define FNV_HAVOK_HKPSTIFFSPRINGCHAINDATACONSTRAINTINFO_H

#include "hkBase.h"
class hkpStiffSpringChainDataConstraintInfo
{
  public:
    hkVector4 m_kPivotInA;       // +0x0
    hkVector4 m_kPivotInB;       // +0x10
    hkReal m_fSpringRestLength;  // +0x20
    char pad24[0xC];
};
#endif
