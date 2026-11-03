// Source layout: TESGlobal. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTSTAT_PRIVATE_GLOBAL_H
#define FNV_TESOBJECTSTAT_PRIVATE_GLOBAL_H
#include "fnv/decl/FUN_0046dce0_class.h"
#include "layout_support.h"
#include "TESForm.h"
class TESGlobal : public TESForm
{
  public:
    TESGlobal();
    BSStringT<char> cGlobalEditorID;  // +0x18
    char cType;                       // +0x20
    unsigned char layoutPadding21[3];
    float fValue;  // +0x24
};
#endif
