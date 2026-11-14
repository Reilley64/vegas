#ifndef FNV_ENTRYPOINTPERKENTRYDATA_H
#define FNV_ENTRYPOINTPERKENTRYDATA_H

#include "layout_support.h"
class PerkEntryPointData
{
  public:
    unsigned char m_ucEntryPoint;      // +0x0
    unsigned char m_ucFunction;        // +0x1
    unsigned char m_ucConditionCount;  // +0x2
};
#endif
