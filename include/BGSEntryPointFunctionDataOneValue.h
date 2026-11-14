// Source layout: BGSEntryPointFunctionDataOneValue. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATAONEVALUE_H
#define FNV_BGSENTRYPOINTFUNCTIONDATAONEVALUE_H
#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
{
  public:
    float fValue;  // +0x4
};
#endif
