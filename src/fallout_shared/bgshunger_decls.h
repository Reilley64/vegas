// fallout_shared/bgshunger_decls.h: declares HungerStageData, BGSHungerStage, BGSDehydrationStage, SpellItem
#ifndef FNV_BGSHUNGER_DECLS_H
#define FNV_BGSHUNGER_DECLS_H


#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "TESForm.h"

class SpellItem;

// Shared endian helper already bound by the stage loader in canonical source.
class FUN_005a71d0
{
  public:
    unsigned int m_uiStageLevel;
    SpellItem* m_pSpell;
};

class HungerStageData
{
  public:
    unsigned int m_uiStageLevel;
    SpellItem* m_pSpell;
};

class BGSHungerStage
{
  public:
    TESForm form;
    FUN_005a71d0 data;
    void ClearData();
    static void ClearStageData(BGSHungerStage*);
    bool Load(TESFile* file);
    void InitItem();
};

// These shared stage helpers retain their canonical decorated bindings.
class BGSDehydrationStage
{
  public:
    static BGSDehydrationStage** AllocateStageArray(unsigned int);
    void FUN_0050f9a0(SpellItem* spell);
};

class SpellItem : public TESForm
{
};
void InsertHungerStage(BGSHungerStage* stage);


#endif
