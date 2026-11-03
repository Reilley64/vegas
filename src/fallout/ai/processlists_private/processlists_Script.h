// Source layout: Script. PC corrections are in generate_headers.py.
#ifndef FNV_SCRIPT_H
#define FNV_SCRIPT_H

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/symbols_005ac000.h"
#include "processlists_layout_support.h"
#include "processlists_SCRIPT_HEADER.h"
#include "processlists_TESForm.h"
class Script : public TESForm
{
  public:
    ScriptHeaderData m_kHeader;                                          // +0x18
    char* m_pText;                                                    // +0x2C
    char* m_data;                                                     // +0x30
    float m_fValueAtOffset34;                                         // +0x34
    float fValueAtOffset38;                                           // +0x38
    float m_fValueAtOffset3C;                                         // +0x3C
    TESQuest* m_pOwnerQuest;                                          // +0x40
    BSSimpleList<ScriptReferencedObject*> m_kReferencedObjectList;  // +0x44
    BSSimpleList<ScriptVariableInfo*> m_kVariableList;                    // +0x4C
    Script();
    virtual ~Script();
    virtual void InitializeComponent();
    char* GetData();
    void InitItem(TESForm* form);
public:
    static bool IsConsolePlatform();
};
FNV_STATIC_ASSERT(sizeof(Script) == 0x54);
FNV_STATIC_ASSERT(offsetof(Script, m_kHeader) == 0x18);
FNV_STATIC_ASSERT(offsetof(Script, m_pText) == 0x2C);
FNV_STATIC_ASSERT(offsetof(Script, m_data) == 0x30);
FNV_STATIC_ASSERT(offsetof(Script, m_fValueAtOffset34) == 0x34);
FNV_STATIC_ASSERT(offsetof(Script, fValueAtOffset38) == 0x38);
FNV_STATIC_ASSERT(offsetof(Script, m_fValueAtOffset3C) == 0x3C);
FNV_STATIC_ASSERT(offsetof(Script, m_pOwnerQuest) == 0x40);
FNV_STATIC_ASSERT(offsetof(Script, m_kReferencedObjectList) == 0x44);
FNV_STATIC_ASSERT(offsetof(Script, m_kVariableList) == 0x4C);
#endif
