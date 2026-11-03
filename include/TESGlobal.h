// Source layout: TESGlobal. PC corrections are in generate_headers.py.
#ifndef FNV_TESGLOBAL_H
#define FNV_TESGLOBAL_H
#include "fnv/decl/FUN_0046dce0_class.h"
#include "layout_support.h"
#include "TESForm.h"
class TESGlobal : public TESForm
{
  public:
    BSStringT<char> cGlobalEditorID;  // +0x18
    char cType;                       // +0x20
    unsigned char layoutPadding21;
    unsigned short layoutPadding22;
    float fValue;  // +0x24
};
#endif
