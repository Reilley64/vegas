// include/havok/hkpVehicleLinearCastWheelCollideWheelState.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPVEHICLELINEARCASTWHEELCOLLIDEWHEELSTATE_H
#define FNV_HAVOK_HKPVEHICLELINEARCASTWHEELCOLLIDEWHEELSTATE_H

#include "hkBase.h"
class hkpAabbPhantom;
class hkpShape;
class hkpVehicleLinearCastWheelCollideWheelState
{
  public:
    hkpAabbPhantom* m_pPhantom;   // +0x0
    hkpShape* m_pCollisionShape;  // +0x4
    char pad8[0x8];
    hkTransform m_kMotionTransform;  // +0x10
    hkVector4 m_vTo;                 // +0x50
};
#endif
