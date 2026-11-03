// include/havok/hkpConstrainedSystemFilter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x38.
#ifndef FNV_HAVOK_HKPCONSTRAINEDSYSTEMFILTER_H
#define FNV_HAVOK_HKPCONSTRAINEDSYSTEMFILTER_H

#include "hkBase.h"
#include "hkpCollisionFilter.h"
class hkpConstrainedSystemFilter : public hkpCollisionFilter
{
  public:
    char pad30[0x4];
    hkpCollisionFilter* m_pChildFilter;  // +0x34
};
#endif
