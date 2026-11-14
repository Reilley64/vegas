// include/havok/hkpLinFrictionConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPLINFRICTIONCONSTRAINTATOM_H
#define FNV_HAVOK_HKPLINFRICTIONCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpLinFrictionConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_bLimitEnabled;   // +0x2
    hkUint8 m_ucFrictionAxis;  // +0x3
    hkReal m_fFriction;        // +0x4
};
#endif
