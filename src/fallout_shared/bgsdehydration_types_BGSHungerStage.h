// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSHUNGERSTAGE_H
#define FNV_BGSHUNGERSTAGE_H

#include "fnv/decl/FUN_00843170_shell.h"
class SpellItem;
#include "layout_support.h"
#include "TESForm.h"
class BGSHungerStage;
class HungerStageData;
class HungerStageData
{
  public:
    HungerStageData();
    unsigned int m_uiStageLevel;  // +0x0, 4 bytes
    SpellItem* m_pSpell;          // +0x4, 4 bytes
    // void __cdecl HungerStageData::*()
    // void __cdecl HungerStageData::*()
    // void __cdecl HungerStageData::*()
};
class BGSHungerStage : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    HungerStageData data;  // +0x18, 8 bytes
    // BGSHungerStage
    // void __cdecl BGSHungerStage::*()
    // void __cdecl BGSHungerStage::*()
    // bool __cdecl BGSHungerStage::*(TESFile*)
    // void __cdecl BGSHungerStage::*(TESForm*)
    // bool __cdecl BGSHungerStage::*(TESForm*)
    // void __cdecl BGSHungerStage::*()
    // void __cdecl BGSHungerStage::*()
    // HungerStageData* __cdecl BGSHungerStage::*()
    // void __cdecl BGSHungerStage::*()
    // SpellItem* __cdecl BGSHungerStage::*()
    // void __cdecl BGSHungerStage::*(SpellItem*)
    // unsigned int __cdecl BGSHungerStage::*()
    // void __cdecl BGSHungerStage::*(unsigned int)
    // unsigned int __cdecl BGSHungerStage::*()
    // BGSHungerStage* __cdecl BGSHungerStage::*(unsigned int)
    // BGSHungerStage* __cdecl BGSHungerStage::*(float)
    // BGSHungerStage** __cdecl BGSHungerStage::*(unsigned int)
    // void __cdecl BGSHungerStage::*()
    // void __cdecl BGSHungerStage::*(BGSHungerStage*)
    // BGSHungerStage& __cdecl BGSHungerStage::*(const BGSHungerStage&)
    // void __cdecl BGSHungerStage::*()
    BGSHungerStage();
    void ResetFormData();
};
#endif
