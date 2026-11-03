// fallout_shared/bgssleepdeprevation.h: declares SpellItem, SpellItemValueEntry, TESFormInitFlag, BGSSleepDeprevationStage, BGSDehydrationStage
#ifndef FNV_BGSSLEEPDEPREVATION_H
#define FNV_BGSSLEEPDEPREVATION_H


#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_011c3000.h"
#include "TESForm.h"

class SpellItem : public TESForm
{
  public:
    virtual ~SpellItem();
    char _pdbpad_18[28];
    char data_db[16];
};

class SpellItemValueEntry
{
  public:
    unsigned int m_uiSpellValue;
    SpellItem* m_pSpell;
};

class TESFormInitFlag
{
  public:
};

class BGSSleepDeprevationStage
{
  public:
    unsigned int formPrefix[5];
    SpellItemValueEntry data;

    static void ClearStageData(BGSSleepDeprevationStage* stage);
    void ClearData();
    void InitItem();
    virtual bool Load(TESFile* file);
};


class SpellItem;
class BGSDehydrationStage
{
  public:
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
public:
    void FUN_0050f9a0(::SpellItem *);
};

class FUN_005a71d0
{
  public:
};


void operator delete(void* pointer);

#endif
