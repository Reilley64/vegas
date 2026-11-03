// include/havok/hkpSetLocalRotationsConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPSETLOCALROTATIONSCONSTRAINTATOM_H
#define FNV_HAVOK_HKPSETLOCALROTATIONSCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpSetLocalRotationsConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0xE];
    hkRotation m_kRotationA;  // +0x10
    hkRotation m_kRotationB;  // +0x40
};
#endif
