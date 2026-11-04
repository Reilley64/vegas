#ifndef FNV_SCRIPT_REFERENCED_OBJECT_H
#define FNV_SCRIPT_REFERENCED_OBJECT_H

#include "layout_support.h"
class ScriptReferencedObject
{
  public:
    BSStringT<char> m_kFormName;  // +0x0
    TESForm* pForm;               // +0x8
    unsigned int m_uiFormID;      // +0xC
    ScriptReferencedObject();
};
#endif
