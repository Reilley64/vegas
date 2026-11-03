#ifndef FNV_SCRIPTVARIABLE_H
#define FNV_SCRIPTVARIABLE_H

#include "layout_support.h"
#include "ScriptLocalVariable.h"
class ScriptVariableInfo
{
  public:
    ScriptLocalVariable data;        // +0x0
    BSStringT<char> m_kName;  // +0x18
    ScriptVariableInfo();
    void Load(TESFile* file);
};
#endif
