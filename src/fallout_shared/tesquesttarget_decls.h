// fallout_shared/tesquesttarget_decls.h: declares ExtraDataList, TESObjectREFR, TESQuestStageLegacyData
#ifndef FNV_TESQUESTTARGET_DECLS_H
#define FNV_TESQUESTTARGET_DECLS_H

#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/symbols_005b5000.h"
#include "TESForm.h"

class ExtraDataList
{
  public:
};

class TESObjectREFR : public TESForm
{
  public:
};

class TESConditionItem;
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
    void InitItem(TESForm* form);
};
FNV_STATIC_ASSERT(sizeof(PerkEntryConditionSet) == 8);

// The target prefix accessed by these methods; the teleport path follows it.
class RegionObjectEntry
{
  public:
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    TESObjectREFR* m_pReference;
    void InitItem(TESForm* form);
    TESObjectREFR* GetReference(bool resolveDeleted);
};
FNV_STATIC_ASSERT(offsetof(RegionObjectEntry, m_pReference) == 12);

class AnimationClipStatus
{
  public:
    unsigned char m_ucClipIdentifier;
    bool m_bCompleted;
};
FNV_STATIC_ASSERT(sizeof(AnimationClipStatus) == 2);

class PlayerQuestData;
class QuestStage
{
  public:
    AnimationClipStatus m_Data;
    BSSimpleList<PlayerQuestData*> m_kStageItems;
    void Load(TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(QuestStage) == 12);
FNV_STATIC_ASSERT(offsetof(QuestStage, m_kStageItems) == 4);

// Older INDX chunks occupy eight bytes; the remaining payload is reserved.
struct TESQuestStageLegacyData
{
    AnimationClipStatus data;
    unsigned int reserved;
};
FNV_STATIC_ASSERT(sizeof(TESQuestStageLegacyData) == 8);

#endif
