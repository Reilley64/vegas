// Source layout: BGSEntryPointFunctionDataActivateChoice. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATAACTIVATECHOICE_H
#define FNV_BGSENTRYPOINTFUNCTIONDATAACTIVATECHOICE_H

#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
{
  public:
    BSStringT<char> m_kChoiceText;  // +0x4
    Script* m_pChoiceScript;        // +0xC
    unsigned int cFlags;            // +0x10
};
#endif
