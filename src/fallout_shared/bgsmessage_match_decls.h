// fallout_shared/bgsmessage_match_decls.h: declares TESDescription, TESTopicInfo, BGSMessageInitAccess
#ifndef FNV_BGSMESSAGE_MATCH_DECLS_H
#define FNV_BGSMESSAGE_MATCH_DECLS_H


#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_005b5000.h"
#include "layout_support.h"

class TESForm;
class TESFile;
class TESObjectREFR;
class TESConditionItem;
class TESTopic;
class NiTexture;
class PerkButtonEntry;

#ifndef FNV_TESCONDITION_H
#define FNV_TESCONDITION_H
#pragma pack(push, 4)
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitializeConditionItems();
    void Load(TESFile* file);
    void InitItem(TESForm* form);
public:
    bool Compare(::PerkEntryConditionSet *);
};
#pragma pack(pop)
#endif

#ifndef FNV_TESDESCRIPTION_H
#define FNV_TESDESCRIPTION_H
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;
    static void ReadDescriptionFromFile(TESDescription* description, TESFile* file);
};
#pragma pack(pop)
#endif

class TESTopicInfo
{
  public:
    BSSimpleList<TESTopic*>* GetAddTopicList();
};

struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};

struct BGSMessageLoadAccess
{
};


#endif
