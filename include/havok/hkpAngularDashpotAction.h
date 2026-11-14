// include/havok/hkpAngularDashpotAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPANGULARDASHPOTACTION_H
#define FNV_HAVOK_HKPANGULARDASHPOTACTION_H
#include "hkBase.h"
#include "hkpBinaryAction.h"
class hkpAngularDashpotAction : public hkpBinaryAction
{
  public:
    hkQuaternion m_rotation;   // +0x20
    hkReal m_fSpringStrength;  // +0x30
    hkReal m_fMotorDamping;    // +0x34
    char pad38[0x8];
};
#endif
