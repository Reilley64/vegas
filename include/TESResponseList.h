#ifndef FNV_RESPONSELISTWRAPPER_H
#define FNV_RESPONSELISTWRAPPER_H

#include "layout_support.h"
class TESResponseList
{
  public:
    TESResponse* pHead;  // +0x0
    void ClearResponses();
};
#endif
