// Source layout: BSCacheDriveSystemUtility. PC corrections are in generate_headers.py.
#ifndef FNV_BSCACHEDRIVESYSTEMUTILITY_H
#define FNV_BSCACHEDRIVESYSTEMUTILITY_H

#include "layout_support.h"
class BSCacheDriveSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
    bool bIsActive;   // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    CACHEDRIVE_STATUS m_eDriveStatus;  // +0x8
    char m_acDrivePath[1055];          // +0xC
    unsigned char layoutPadding42B;
    void Destroy();
};
#endif
