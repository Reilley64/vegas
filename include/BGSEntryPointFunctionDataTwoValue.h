// Source layout: BGSEntryPointFunctionDataTwoValue. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATATWOVALUE_H
#define FNV_BGSENTRYPOINTFUNCTIONDATATWOVALUE_H

#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
  public:
    float EntryPointTwoValueFunctionData;  // +0x4
    float fSecondFunctionValue;            // +0x8
};
#endif
