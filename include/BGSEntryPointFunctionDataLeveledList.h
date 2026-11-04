// Source layout: BGSEntryPointFunctionDataLeveledList. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATALEVELEDLIST_H
#define FNV_BGSENTRYPOINTFUNCTIONDATALEVELEDLIST_H
#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
class BGSEntryPointFunctionDataLeveledList : public BGSEntryPointFunctionData
{
  public:
    TESLevItem* pLeveledList;  // +0x4
};
#endif
