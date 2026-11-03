// Source layout: BGSEntryPointPerkEntry. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTPERKENTRY_H
#define FNV_BGSENTRYPOINTPERKENTRY_H

#include "layout_support.h"
#include "BGSPerkEntry.h"
#include "PerkEntryPointData.h"
class BGSEntryPointPerkEntry : public BGSPerkEntry
{
  public:
    PerkEntryPointData Data;  // +0x8
    unsigned char layoutPaddingB;
    BGSEntryPointFunctionData* m_pFunctionData;  // +0xC
    PerkEntryConditionSet* m_pConditions;                 // +0x10
};
#endif
