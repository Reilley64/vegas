// Source layout: PerkData. PC corrections are in generate_headers.py.
#ifndef FNV_PERKDATA_H
#define FNV_PERKDATA_H

#include "layout_support.h"
class PerkData
{
  public:
    bool m_bTrait;                // +0x0
    unsigned char cLevel;         // +0x1
    unsigned char m_ucRankCount;  // +0x2
    bool bPlayable;               // +0x3
    bool bHidden;                 // +0x4
};
#endif
