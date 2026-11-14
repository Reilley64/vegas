// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

#include "fnv/decl/FUN_00408da0_Class.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
};
#endif
