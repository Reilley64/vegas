// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H
#include "layout_support.h"
#include "BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
public:
    void SetFullName(const char *);
};
#endif
