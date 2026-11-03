// Source layout: BSGameDataSystemUtility. PC corrections are in generate_headers.py.
#ifndef FNV_BSGAMEDATASYSTEMUTILITY_H
#define FNV_BSGAMEDATASYSTEMUTILITY_H

#include "layout_support.h"
class BSGameDataSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;       // +0x0
    bool bIsActive;        // +0x4
    bool m_bGameDataFlag;  // +0x5
    unsigned short layoutPadding6;
    GAMEDATA_STATUS m_eGameDataStatus;  // +0x8
    char m_acFirstLargeBuffer[1055];    // +0xC
    char m_acSecondaryPath[1055];       // +0x42B
    unsigned short layoutPadding84A;
    int m_iBufferValue;  // +0x84C
    void Destroy();
};
#endif
