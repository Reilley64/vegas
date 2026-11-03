#ifndef FNV_SCRIPT_HEADER_H
#define FNV_SCRIPT_HEADER_H
#include "fnv/decl/FUN_00414220_shell.h"
#include "layout_support.h"
#pragma pack(push, 4)
class ScriptHeaderData
{
  public:
    unsigned int variableCount;    // +0x0
    unsigned int m_uiReferenceID;  // +0x4
    unsigned int dataSize;         // +0x8
    unsigned int m_uiDataOffset;   // +0xC
    bool m_bQuest;                 // +0x10
    bool m_bEffect;                // +0x11
    bool m_bCompiled;              // +0x12
};
#pragma pack(pop)
#endif
