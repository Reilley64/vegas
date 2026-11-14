// include/havok/hkpSpringDamperConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPSPRINGDAMPERCONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPSPRINGDAMPERCONSTRAINTMOTOR_H

#include "hkBase.h"
#include "hkpLimitedForceConstraintMotor.h"
class hkpSpringDamperConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkReal m_fSpringConstant;  // +0x14
    hkReal m_fSpringDamping;   // +0x18
};
#endif
