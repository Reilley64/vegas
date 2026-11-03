// Source layout: ScriptLocals. PC corrections are in generate_headers.py.
#ifndef FNV_SCRIPTLOCALS_H
#define FNV_SCRIPTLOCALS_H

#include "fnv/decl/FUN_005a9290_shell.h"
#include "layout_support.h"
class ScriptLocals
{
  public:
    Script* m_pOwnerScript;  // +0x0
    char m_cActionFlags;     // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSimpleList<FormFlagRecord*>* m_pLocalVariableList;  // +0x8
    BSSimpleList<ScriptLocalVariable*>* m_pVariableList;        // +0xC
    ScriptDefinition* m_pExtendedLocals;               // +0x10
};
#endif
