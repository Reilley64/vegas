// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

#include "processlists_layout_support.h"
#include "processlists_BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
};
#endif
