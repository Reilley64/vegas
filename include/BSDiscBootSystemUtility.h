// Source layout: BSDiscBootSystemUtility. PC corrections are in generate_headers.py.
#ifndef FNV_BSDISCBOOTSYSTEMUTILITY_H
#define FNV_BSDISCBOOTSYSTEMUTILITY_H

#include "layout_support.h"
class BSDiscBootSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;                 // +0x0
    char m_acTitleID[64];            // +0x4
    unsigned int m_uiParentalLevel;  // +0x44
    bool m_bNotificationActive;      // +0x48
    unsigned char layoutPadding49;
    unsigned short layoutPadding4A;
    void___cdecl__BSDiscBootSystemUtility__NOTIFICATION_TYPE_* m_pNotificationCallback;  // +0x4C
    void Destroy();
};
#endif
