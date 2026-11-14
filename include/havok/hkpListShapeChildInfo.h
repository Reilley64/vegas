// include/havok/hkpListShapeChildInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPLISTSHAPECHILDINFO_H
#define FNV_HAVOK_HKPLISTSHAPECHILDINFO_H

#include "hkBase.h"
class hkpShape;
class hkpListShapeChildInfo
{
  public:
    hkpShape* m_pCollisionShape;       // +0x0
    hkUint32 m_uiCollisionFilterData;  // +0x4
    hkInt32 m_iShapeKey;               // +0x8
    hkInt32 m_iChildShapeCount;        // +0xC
};
#endif
