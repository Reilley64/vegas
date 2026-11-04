// Source layout: BSSysInfoSystemUtility. PC corrections are in generate_headers.py.
#ifndef FNV_BSSYSINFOSYSTEMUTILITY_H
#define FNV_BSSYSINFOSYSTEMUTILITY_H

#include "layout_support.h"
class BSSysInfoSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;                               // +0x0
    BSSysInfoSystemUtility__LANGUAGE m_eLanguage;  // +0x4
    unsigned int SystemUtilityData[16];            // +0x8
    void Initialize();
};
#endif
