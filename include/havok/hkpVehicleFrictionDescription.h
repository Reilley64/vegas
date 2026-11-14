// include/havok/hkpVehicleFrictionDescription.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xD0.
#ifndef FNV_HAVOK_HKPVEHICLEFRICTIONDESCRIPTION_H
#define FNV_HAVOK_HKPVEHICLEFRICTIONDESCRIPTION_H

#include "hkBase.h"
#include "hkpVehicleFrictionDescriptionAxisDescription.h"
class hkpVehicleFrictionDescription
{
  public:
    hkReal m_fFrictionEqualizer;                                          // +0x0
    hkReal m_fMaxVelocityForPositionalFriction;                           // +0x4
    hkpVehicleFrictionDescriptionAxisDescription m_kAxisDescriptions[2];  // +0x8
};
#endif
