// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CHECKLINEOFSIGHTFILTERWATER_H
#define FNV_CHECKLINEOFSIGHTFILTERWATER_H

#include "layout_support.h"
class CheckLineOfSightFilterWater;
class Pathing__CheckLineOfSightFilter;
class Pathing__CheckLineOfSightFilter
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    // CheckLineOfSightFilter
    // Pathing::CheckLineOfSightFilter& __cdecl Pathing::CheckLineOfSightFilter::*(const Pathing::CheckLineOfSightFilter&)
};
class CheckLineOfSightFilterWater : public Pathing__CheckLineOfSightFilter
{
  public:
    // base Pathing::CheckLineOfSightFilter at +0x0, size 4
    bool m_bCheckWater;  // +0x4, 1 bytes
    bool IsLineOfSightClear(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned char layoutPadding5[3];
    // CheckLineOfSightFilterWater
    // CheckLineOfSightFilterWater& __cdecl CheckLineOfSightFilterWater::*(const CheckLineOfSightFilterWater&)
};
#endif
