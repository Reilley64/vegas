// include/havok/hkpMultiRayShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPMULTIRAYSHAPE_H
#define FNV_HAVOK_HKPMULTIRAYSHAPE_H

#include "hkBase.h"
#include "hkpShape.h"
class hkpMultiRayShapeRay;
class hkpMultiRayShape : public hkpShape
{
  public:
    hkArray<hkpMultiRayShapeRay> m_kRays;  // +0x10
    hkReal m_fRayRadius;                   // +0x1C
};
#endif
