// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSDEHYDRATIONSTAGE_H
#define FNV_BGSDEHYDRATIONSTAGE_H

#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
class SpellItem;
#include "layout_support.h"
#include "TESForm.h"
class BGSDehydrationStage;
class StageRecordData;
class StageRecordData
{
  public:
    unsigned int m_uiStageIndex;  // +0x0, 4 bytes
    SpellItem* m_pSpell;          // +0x4, 4 bytes
    // void __cdecl StageRecordData::*()
    // void __cdecl StageRecordData::*()
    // void __cdecl StageRecordData::*()
};
class FUN_005a71d0 : public StageRecordData
{
  public:
    FUN_005a71d0();
};
class BGSDehydrationStage : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    FUN_005a71d0 data;  // +0x18, 8 bytes
    // BGSDehydrationStage
    // void __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*()
    // bool __cdecl BGSDehydrationStage::*(TESFile*)
    // void __cdecl BGSDehydrationStage::*(TESForm*)
    // bool __cdecl BGSDehydrationStage::*(TESForm*)
    // void __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*()
    // StageRecordData* __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*()
    // SpellItem* __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*(SpellItem*)
    // unsigned int __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*(unsigned int)
    // unsigned int __cdecl BGSDehydrationStage::*()
    // BGSDehydrationStage* __cdecl BGSDehydrationStage::*(unsigned int)
    // BGSDehydrationStage* __cdecl BGSDehydrationStage::*(float)
    // BGSDehydrationStage** __cdecl BGSDehydrationStage::*(unsigned int)
    // void __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*(BGSDehydrationStage*)
    // ClearStageData
    // BGSDehydrationStage& __cdecl BGSDehydrationStage::*(const BGSDehydrationStage&)
    // void __cdecl BGSDehydrationStage::*()
    static BGSDehydrationStage* GetStage(unsigned int index);
    static BGSDehydrationStage* FindStage(float level);
    void ClearData();
    static void ClearStageData(BGSDehydrationStage* stage);
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
    BGSDehydrationStage();
    void InitItem();
    bool Load(TESFile* file);
    void FUN_0050f9a0(SpellItem* spell);
};
#endif
