// Source layout: BGSPerk. PC corrections are in generate_headers.py.
#ifndef FNV_BGSPERK_H
#define FNV_BGSPERK_H

#include "layout_support.h"
#include "PerkData.h"
#include "PerkEntryConditionSet.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
class BGSPerk : public TESForm
{
  public:
    TESFullName tESFullNameComponent;        // +0x18
    TESDescription tESDescriptionComponent;  // +0x24
    TESIcon tESIconComponent;                // +0x2C
    PerkData Data;                           // +0x38
    unsigned char layoutPadding3D;
    unsigned short layoutPadding3E;
    PerkEntryConditionSet m_kConditions;                // +0x40
    BSSimpleList<BGSPerkEntry*> m_kEntryList;  // +0x48
};
#endif
