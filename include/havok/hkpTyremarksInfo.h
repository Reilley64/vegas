// include/havok/hkpTyremarksInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPTYREMARKSINFO_H
#define FNV_HAVOK_HKPTYREMARKSINFO_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpTyremarksWheel;
class hkpTyremarksInfo : public hkReferencedObject
{
  public:
    hkReal m_fMinTyremarkPointDistance;              // +0x8
    hkReal m_fMaxTyremarkPointDistance;              // +0xC
    hkArray<hkpTyremarksWheel*> m_kTyremarksWheels;  // +0x10
};
#endif
