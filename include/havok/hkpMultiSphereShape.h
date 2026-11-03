// include/havok/hkpMultiSphereShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xA0.
#ifndef FNV_HAVOK_HKPMULTISPHERESHAPE_H
#define FNV_HAVOK_HKPMULTISPHERESHAPE_H

#include "hkBase.h"
#include "hkpSphereRepShape.h"
class hkpMultiSphereShape : public hkpSphereRepShape
{
  public:
    hkInt32 m_iSphereCount;  // +0x10
    char pad14[0xC];
    hkVector4 m_kSpheres[8];  // +0x20
};
#endif
