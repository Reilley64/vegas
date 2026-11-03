// Source layout: INFO_LINK_ELEMENT. PC corrections are in generate_headers.py.
#ifndef FNV_INFO_LINK_ELEMENT_H
#define FNV_INFO_LINK_ELEMENT_H

#include "layout_support.h"
class INFO_LINK_ELEMENT
{
  public:
    unsigned int nID;     // +0x0
    TESTopicInfo* pInfo;  // +0x4
    int m_iIndex;         // +0x8
};
#endif
