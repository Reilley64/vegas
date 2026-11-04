// include/havok/hkpPulleyConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPPULLEYCONSTRAINTATOM_H
#define FNV_HAVOK_HKPPULLEYCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpPulleyConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0xE];
    hkVector4 m_kFixedPivotA;   // +0x10
    hkVector4 m_kFixedPivotB;   // +0x20
    hkReal m_fLeverageOnBodyB;  // +0x30
    hkReal m_fRopeLength;       // +0x34
    char pad38[0x8];
};
#endif
