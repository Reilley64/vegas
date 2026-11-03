// include/havok/hkpGenericConstraintDataScheme.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPGENERICCONSTRAINTDATASCHEME_H
#define FNV_HAVOK_HKPGENERICCONSTRAINTDATASCHEME_H

#include "hkBase.h"
#include "hkpGenericConstraintDataSchemeConstraintInfo.h"
class hkpConstraintMotor;
class hkpGenericConstraintDataScheme
{
  public:
    hkpGenericConstraintDataSchemeConstraintInfo m_info;  // +0x0
    hkArray<hkVector4> m_data;                            // +0x10
    hkArray<hkInt32> m_commands;                          // +0x1C
    hkArray<void*> m_ppModifiers;                         // +0x28
    hkArray<hkpConstraintMotor*> m_ppMotors;              // +0x34
};
#endif
