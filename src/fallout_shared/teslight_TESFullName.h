// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

class Script;
class TESFormInitFlag
{
  public:
};
#include "layout_support.h"
#include "BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
    void SetFullName(const char* name);
};
#endif
