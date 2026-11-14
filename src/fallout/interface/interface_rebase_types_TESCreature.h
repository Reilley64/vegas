// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_CREATURE_TESCREATURE_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_CREATURE_TESCREATURE_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_ActorValueOwner.h"
#include "interface_rebase_BaseFormComponent.h"
#include "interface_rebase_TESForm.h"
#include "interface_rebase_TESFullName.h"
#include "interface_rebase_TESHealthForm.h"
#include "interface_rebase_TESScriptableForm.h"
#include "interface_rebase_layout_support.h"
class ActorBaseAttributes;
class PackedRecordData;
class BGSBodyPartData;
class BGSDestructibleObjectForm;
class BGSImpactDataSet;
class BGSTouchSpellForm;
class BGSVoiceType;
class BSFileEntry;
class TypedData;
struct InventoryItemEntry;
class CreatureSoundCollection;
class CollisionComponent;
class FactionReaction;
class MagicItemForm;
class ShortPoint3;
class PackageList;
class TESAIForm;
class TESActorBaseData;
class TESAnimation;
class TESAttackDamageForm;
class TESAttributes;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESCombatStyle;
class TESContainer;
class TESCreature;
class TESLevSpell;
class TESModel;
class TESModelList;
class TESFormList;
class TESSpellList;
class FileEntryList;
class FileEntryListCollection;
enum BGSImpactDataSet__IMPACT_MATERIAL_TYPE
{
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_STONE = 0,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_DIRT = 1,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_GRASS = 2,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_GLASS = 3,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_METAL = 4,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_WOOD = 5,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC = 6,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_CLOTH = 7,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_WATER = 8,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_HOLLOW_METAL = 9,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC_BUG = 10,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC_GLOW = 11,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_COUNT = 12
};
enum SOUND_LEVEL
{
    SOUND_LEVEL_SOUND_LEVEL_LOUD = 0,
    SOUND_LEVEL_SOUND_LEVEL_NORMAL = 1,
    SOUND_LEVEL_SOUND_LEVEL_SILENT = 2,
    SOUND_LEVEL_SOUND_LEVEL_COUNT = 3
};
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
    // TESObject
    // void __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // TESFormList* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // bool __cdecl TESObject::*()
    // char* __cdecl TESObject::*()
    // void __cdecl TESObject::*(TESFormList*)
    // void __cdecl TESObject::*(TESObject*)
    // void __cdecl TESObject::*(TESObject*)
    // TESObject* __cdecl TESObject::*()
    // TESObject* __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*(NiAVObject*, const char*)
    // const char* __cdecl TESObject::*(TESObjectREFR*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // TESObject& __cdecl TESObject::*(const TESObject&)
    // void __cdecl TESObject::*()
};
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
    // ShortPoint3
    // short& __cdecl ShortPoint3::*(int)
    // operator=
    // operator==
    // operator!=
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // operator-
    // operator*
    // ShortPoint3 __cdecl ShortPoint3::*(float)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&, const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // float __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(NiStream&)
    // void __cdecl ShortPoint3::*(NiStream&)
    // char* __cdecl ShortPoint3::*(const char*)
};
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
    // TESBoundObject
    // void __cdecl TESBoundObject::*()
    // bool __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(NiAVObject*)
    // void __cdecl TESBoundObject::*(TESBoundObject*)
    // NiPoint3 __cdecl TESBoundObject::*()
    // NiPoint3 __cdecl TESBoundObject::*()
    // float __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(TESFile*)
    // bool __cdecl TESBoundObject::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // bool __cdecl TESBoundObject::*(bool)
    // TESBoundObject& __cdecl TESBoundObject::*(const TESBoundObject&)
    // void __cdecl TESBoundObject::*()
};
class TESBoundAnimObject : public TESBoundObject
{
  public:
    // base TESBoundObject at +0x0, size 48
    // TESBoundAnimObject
    // void __cdecl TESBoundAnimObject::*()
    // bool __cdecl TESBoundAnimObject::*()
    // void __cdecl TESBoundAnimObject::*(NiAVObject*, bool)
    // bool __cdecl TESBoundAnimObject::*(const char*)
    // TESBoundAnimObject& __cdecl TESBoundAnimObject::*(const TESBoundAnimObject&)
    // void __cdecl TESBoundAnimObject::*()
};
class ActorBaseAttributes
{
  public:
    int m_uiActorFlags;          // +0x0, 4 bytes
    unsigned short m_usField04;  // +0x4, 2 bytes
    unsigned short m_usField06;  // +0x6, 2 bytes
    unsigned short sLevel;       // +0x8, 2 bytes
    unsigned short m_usField0A;  // +0xA, 2 bytes
    unsigned short m_usField0C;  // +0xC, 2 bytes
    unsigned short m_usField0E;  // +0xE, 2 bytes
    float m_fField10;            // +0x10, 4 bytes
    unsigned short m_usField14;  // +0x14, 2 bytes
    unsigned short m_usField16;  // +0x16, 2 bytes
    // void __cdecl ActorBaseAttributes::*()
};
class TESActorBaseData : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    ActorBaseAttributes actorData;             // +0x4, 24 bytes
    TESLevItem* m_pBaseTemplateForm;           // +0x1C, 4 bytes
    BGSVoiceType* m_kFactionList;              // +0x20, 4 bytes
    TESForm* m_ppTemplateForms;                // +0x24, 4 bytes
    int m_pDeathItem;                          // +0x28, 4 bytes
    BSSimpleList<FactionReaction*> m_pVoiceType;  // +0x2C, 8 bytes
    // TESActorBaseData
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(BaseFormComponent*)
    // bool __cdecl TESActorBaseData::*(BaseFormComponent*)
    // void __cdecl TESActorBaseData::*(TESForm*)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(TESActorBaseData::TEMPLATE_USE_FLAG, bool)
    // bool __cdecl TESActorBaseData::*(TESActorBaseData::TEMPLATE_USE_FLAG)
    // TESForm* __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESForm*)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // bool __cdecl TESActorBaseData::*()
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESObjectREFR*)
    // TESActorBase* __cdecl TESActorBaseData::*(TESActorBase*, TESActorBase*)
    // bool __cdecl TESActorBaseData::*(TESActorBase*)
    // bool __cdecl TESActorBaseData::*(TESActorBase*, TESActorBase*)
    // TESForm* __cdecl TESActorBaseData::*(TESActorBase*, unsigned short&)
    // int* __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(int)
    // bool __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int, bool, bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool, bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // unsigned short __cdecl TESActorBaseData::*()
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // TESLevItem* __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESLevItem*)
    // void __cdecl TESActorBaseData::*(unsigned short)
    // const char* __cdecl TESActorBaseData::*(Actor*)
    // void __cdecl TESActorBaseData::*(float)
    // void __cdecl TESActorBaseData::*(float)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // int __cdecl TESActorBaseData::*(TESActorBase*, int&)
    // int __cdecl TESActorBaseData::*(TESFaction*, bool)
    // void __cdecl TESActorBaseData::*(TESFaction*, char)
    // void __cdecl TESActorBaseData::*(TESFaction*, char, bool)
    // bool __cdecl TESActorBaseData::*()
    // bool __cdecl TESActorBaseData::*()
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // void __cdecl TESActorBaseData::*(BGSVoiceType*)
    // void __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int)
    // int __cdecl TESActorBaseData::*()
    // unsigned short __cdecl TESActorBaseData::*(unsigned int)
    // SaveGame
    // LoadGame
    // void __cdecl TESActorBaseData::*(PC_FACTION_FLAG)
    // bool __cdecl TESActorBaseData::*(TESFaction*)
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESActorBaseData*)
    // TESActorBaseData& __cdecl TESActorBaseData::*(const TESActorBaseData&)
    // void* __cdecl TESActorBaseData::*(unsigned int)
};
class TESContainer : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<InventoryItemEntry*> objectList;  // +0x4, 8 bytes
    // TESContainer
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*(BaseFormComponent*)
    // bool __cdecl TESContainer::*(BaseFormComponent*)
    // void __cdecl TESContainer::*(TESForm*)
    // void __cdecl TESContainer::*()
    // AddObject
    // void __cdecl TESContainer::*(InventoryItemEntry*)
    // InventoryItemEntry* __cdecl TESContainer::*()
    // void __cdecl TESContainer::*(InventoryItemEntry*)
    // void __cdecl TESContainer::*(TESObject*, TESObject*)
    // bool __cdecl TESContainer::*(TESObject*)
    // float __cdecl TESContainer::*(bool)
    // int __cdecl TESContainer::*(TESObject*)
    // char __cdecl TESContainer::*(InventoryItemEntry*, InventoryItemEntry*)
    // float __cdecl TESContainer::*()
    // bool __cdecl TESContainer::*(unsigned char)
    // bool __cdecl TESContainer::*(TESObject*)
    // void __cdecl TESContainer::*(TESContainer*)
    // void __cdecl TESContainer::*(int)
    // void __cdecl TESContainer::*(float)
    // void __cdecl TESContainer::*(TESObjectREFR*, bool)
    // void __cdecl TESContainer::*(int, InventoryChanges*)
    // TESAmmo* __cdecl TESContainer::*(TESActorBase*)
    // TESObjectWEAP* __cdecl TESContainer::*(TESActorBase*)
    // TESObjectARMO* __cdecl TESContainer::*(TESActorBase*, BIPED_OBJECT)
    // TESObjectCLOT* __cdecl TESContainer::*(TESActorBase*, BIPED_OBJECT)
    // TESBoundObject* __cdecl TESContainer::*(BIPED_OBJECT)
    // BSSimpleList<InventoryItemEntry *>* __cdecl TESContainer::*()
    // BSSimpleList<InventoryItemEntry *>* __cdecl TESContainer::*()
    // TESContainer& __cdecl TESContainer::*(const TESContainer&)
    // void* __cdecl TESContainer::*(unsigned int)
};
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    MagicItemForm* m_pMagicItem;        // +0x4, 4 bytes
    unsigned short m_usTouchSpellType;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    // BGSTouchSpellForm
    // void __cdecl BGSTouchSpellForm::*()
    // void __cdecl BGSTouchSpellForm::*()
    // void __cdecl BGSTouchSpellForm::*()
    // void __cdecl BGSTouchSpellForm::*(TESForm*)
    // void __cdecl BGSTouchSpellForm::*(BaseFormComponent*)
    // bool __cdecl BGSTouchSpellForm::*(BaseFormComponent*)
    // GetFormTouchSpell
    // void __cdecl BGSTouchSpellForm::*(MagicItemForm*)
    // GetFormTouchSpellAnimation
    // void __cdecl BGSTouchSpellForm::*(unsigned short)
    // BGSTouchSpellForm& __cdecl BGSTouchSpellForm::*(const BGSTouchSpellForm&)
};
class TESSpellList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<SpellItem*> spellList;           // +0x4, 8 bytes
    BSSimpleList<TESLevSpell*> leveledSpellList;  // +0xC, 8 bytes
    // TESSpellList
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*(BaseFormComponent*)
    // bool __cdecl TESSpellList::*(BaseFormComponent*)
    // void __cdecl TESSpellList::*(TESForm*)
    // void __cdecl TESSpellList::*()
    // AddSpell
    // RemoveSpell
    // bool __cdecl TESSpellList::*(SpellItem*)
    // unsigned int __cdecl TESSpellList::*()
    // bool __cdecl TESSpellList::*(TESLevSpell*)
    // unsigned int __cdecl TESSpellList::*()
    // BSSimpleList<SpellItem *>* __cdecl TESSpellList::*()
    // BSSimpleList<TESLevSpell *>* __cdecl TESSpellList::*()
    // SaveGame
    // LoadGame
    // TESSpellList& __cdecl TESSpellList::*(const TESSpellList&)
    // void* __cdecl TESSpellList::*(unsigned int)
};
class PackedRecordData
{
  public:
    unsigned char m_ucField00;  // +0x0, 1 bytes
    unsigned char m_ucField01;  // +0x1, 1 bytes
    unsigned char m_ucField02;  // +0x2, 1 bytes
    unsigned char m_ucField03;  // +0x3, 1 bytes
    unsigned char m_ucField04;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    unsigned int m_uiField08;   // +0x8, 4 bytes
    unsigned char m_ucField0C;  // +0xC, 1 bytes
    unsigned char m_ucField0D;  // +0xD, 1 bytes
    unsigned char m_ucField0E;  // +0xE, 1 bytes
    bool m_bField0F;            // +0xF, 1 bytes
    unsigned int m_uiField10;   // +0x10, 4 bytes
    // void __cdecl PackedRecordData::*()
};
class PackageList
{
  public:
    BSSimpleList<TESPackage*> m_kPackages;  // +0x0, 8 bytes
    // PackageList
    // void __cdecl PackageList::*()
    // bool __cdecl PackageList::*(TESPackage*)
    // void __cdecl PackageList::*(TESPackage*)
    // bool __cdecl PackageList::*(TESPackage*, bool)
    // void __cdecl PackageList::*(TESPackage*, TESPackage*, bool)
    // void __cdecl PackageList::*(TESPackage*)
    // void __cdecl PackageList::*()
    // void __cdecl PackageList::*()
    // void __cdecl PackageList::*(PackageList*)
    // bool __cdecl PackageList::*(PackageList*)
    // void __cdecl PackageList::*(TESForm*)
    // TESPackage* __cdecl PackageList::*(Actor*)
    // void __cdecl PackageList::*(Actor*, BSSimpleList<TESPackage *>*, float, float)
    // bool __cdecl PackageList::*()
    // unsigned int __cdecl PackageList::*()
    // BSSimpleList<TESPackage *>* __cdecl PackageList::*()
    // PackageList& __cdecl PackageList::*(const PackageList&)
    // void* __cdecl PackageList::*(unsigned int)
};
class TESAIForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    PackedRecordData m_kAIData;  // +0x4, 20 bytes
    PackageList m_kPackageList;  // +0x18, 8 bytes
    // TESAIForm
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(BaseFormComponent*)
    // bool __cdecl TESAIForm::*(BaseFormComponent*)
    // void __cdecl TESAIForm::*(TESForm*)
    // void __cdecl TESAIForm::*(TESAIForm*)
    // void __cdecl TESAIForm::*(TESAIForm*)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char)
    // GetConfidenceLevel
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char)
    // unsigned int __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned int, bool)
    // bool __cdecl TESAIForm::*(unsigned int)
    // void __cdecl TESAIForm::*(unsigned int, bool)
    // ActorValue::Index __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(ActorValue::Index)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char)
    // void __cdecl TESAIForm::*(PackedRecordData*)
    // bool __cdecl TESAIForm::*(TESObject*)
    // bool __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(bool)
    // unsigned int __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned int)
    // bool __cdecl TESAIForm::*(TESPackage*)
    // void __cdecl TESAIForm::*(TESPackage*)
    // bool __cdecl TESAIForm::*(TESPackage*, bool)
    // void __cdecl TESAIForm::*(TESPackage*, TESPackage*, bool)
    // void __cdecl TESAIForm::*(TESPackage*)
    // TESPackage* __cdecl TESAIForm::*(Actor*)
    // void __cdecl TESAIForm::*(Actor*, BSSimpleList<TESPackage *>*, float, float)
    // void __cdecl TESAIForm::*(int)
    // SaveGame
    // LoadGame
    // PackageList* __cdecl TESAIForm::*()
    // TESAIForm& __cdecl TESAIForm::*(const TESAIForm&)
    // void* __cdecl TESAIForm::*(unsigned int)
public:
    unsigned char GetAssistance();
};
class TESAttributes : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];
    // TESAttributes
    // void __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*()
    // unsigned int __cdecl TESAttributes::*(void*)
    // unsigned int __cdecl TESAttributes::*(void*)
    // void __cdecl TESAttributes::*(BaseFormComponent*)
    // bool __cdecl TESAttributes::*(BaseFormComponent*)
    // unsigned int __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*(ActorValue::Index)
    // void __cdecl TESAttributes::*(ActorValue::Index, unsigned char, bool)
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // unsigned short __cdecl TESAttributes::*(unsigned int)
    // SaveGame
    // LoadGame
    // TESAttributes& __cdecl TESAttributes::*(const TESAttributes&)
    // void* __cdecl TESAttributes::*(unsigned int)
};
class TESAnimation : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<const char*> m_kKFFileList;  // +0x4, 8 bytes
    // TESAnimation
    // void __cdecl TESAnimation::*()
    // void __cdecl TESAnimation::*()
    // void __cdecl TESAnimation::*()
    // bool __cdecl TESAnimation::*(const char*)
    // void __cdecl TESAnimation::*(const char*)
    // bool __cdecl TESAnimation::*()
    // BSSimpleList<char const *>* __cdecl TESAnimation::*()
    // void __cdecl TESAnimation::*(CHUNK_ID)
    // void __cdecl TESAnimation::*(TESAnimation*, TESFile*)
    // void __cdecl TESAnimation::*(BaseFormComponent*)
    // bool __cdecl TESAnimation::*(BaseFormComponent*)
    // TESAnimation& __cdecl TESAnimation::*(const TESAnimation&)
    // void* __cdecl TESAnimation::*(unsigned int)
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    // BGSDestructibleObjectForm
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(BGSDestructibleObjectForm*, TESFile*)
    // void __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // bool __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // void __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
    // unsigned char __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(unsigned int)
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // int __cdecl BGSDestructibleObjectForm::*(TESForm*, TESModel*)
    // TESModel* __cdecl BGSDestructibleObjectForm::*(TESForm*, int)
    // bool __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float, bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // bool __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, bool)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // bool __cdecl BGSDestructibleObjectForm::*(NiAVObject*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*)
    // void __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CalculateDangerousExplosionHealth
    // float __cdecl BGSDestructibleObjectForm::*(unsigned char, float, float, BGSExplosion**)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // NiTMap<TESObjectREFR *,unsigned int>* __cdecl BGSDestructibleObjectForm::*()
    // float __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(float)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // BGSDestructibleObjectForm& __cdecl BGSDestructibleObjectForm::*(const BGSDestructibleObjectForm&)
    // void* __cdecl BGSDestructibleObjectForm::*(unsigned int)
};
class TESActorBase : public TESBoundAnimObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
    // base TESBoundAnimObject at +0x0, size 48
    // base TESActorBaseData at +0x30, size 52
    // base TESContainer at +0x64, size 12
    // base BGSTouchSpellForm at +0x70, size 12
    // base TESSpellList at +0x7C, size 20
    // base TESAIForm at +0x90, size 32
    // base TESHealthForm at +0xB0, size 8
    // base TESAttributes at +0xB8, size 12
    // base TESAnimation at +0xC4, size 12
    // base TESFullName at +0xD0, size 12
    // base TESModel at +0xDC, size 24
    // base TESScriptableForm at +0xF4, size 12
    // base ActorValueOwner at +0x100, size 4
    // base BGSDestructibleObjectForm at +0x104, size 8
    // bool __cdecl TESActorBase::*()
    // int __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(int)
    // int __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(int)
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // SEX __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(bool)
    // float __cdecl TESActorBase::*(TESForm*)
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(bool)
    // unsigned short __cdecl TESActorBase::*()
    // int __cdecl TESActorBase::*(ActorValue::Index)
    // float __cdecl TESActorBase::*(ActorValue::Index)
    // SetActorValue
    // ModActorValue
    // void __cdecl TESActorBase::*(HWND__*)
    // TESForm* __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*(TESObjectREFR*)
    // void __cdecl TESActorBase::*(int)
    // void __cdecl TESActorBase::*(int)
    // unsigned short __cdecl TESActorBase::*(unsigned int)
    // SaveGame
    // LoadGame
    // Revert
    // void __cdecl TESActorBase::*(unsigned char)
    // TESActorBase
    // void __cdecl TESActorBase::*()
    // TESActorBase& __cdecl TESActorBase::*(const TESActorBase&)
    // void __cdecl TESActorBase::*()
};
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned short m_usAttackDamage;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // TESAttackDamageForm
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*(BaseFormComponent*)
    // bool __cdecl TESAttackDamageForm::*(BaseFormComponent*)
    // GetAttackDamage
    // void __cdecl TESAttackDamageForm::*(unsigned short)
    // TESAttackDamageForm& __cdecl TESAttackDamageForm::*(const TESAttackDamageForm&)
    // void* __cdecl TESAttackDamageForm::*(unsigned int)
};
class FileEntryListCollection
{
  public:
    unsigned int m_uiFileEntryCount;    // +0x0, 4 bytes
    FileEntryList** m_ppElementArray;  // +0x4, 4 bytes
    // void __cdecl FileEntryListCollection::*()
    // void __cdecl FileEntryListCollection::*(CHUNK_ID)
    // void __cdecl FileEntryListCollection::*(TESModelList*, TESFile*)
    // void __cdecl FileEntryListCollection::*(FileEntryListCollection*)
    // void __cdecl FileEntryListCollection::*()
    // FileEntryList* __cdecl FileEntryListCollection::*(unsigned int)
};
class TESModelList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<const char*> m_kModelPaths;  // +0x4, 8 bytes
    FileEntryListCollection m_kModelData;     // +0xC, 8 bytes
    // TESModelList
    // void __cdecl TESModelList::*()
    // void __cdecl TESModelList::*()
    // void __cdecl TESModelList::*()
    // bool __cdecl TESModelList::*(const char*)
    // void __cdecl TESModelList::*(const char*)
    // bool __cdecl TESModelList::*()
    // BSSimpleList<char const *>* __cdecl TESModelList::*()
    // void __cdecl TESModelList::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModelList::*(TESModelList*, TESFile*)
    // void __cdecl TESModelList::*(BaseFormComponent*)
    // bool __cdecl TESModelList::*(BaseFormComponent*)
    // FileEntryListCollection* __cdecl TESModelList::*()
    // TESModelList& __cdecl TESModelList::*(const TESModelList&)
    // void* __cdecl TESModelList::*(unsigned int)
};
class TypedData
{
  public:
    char eType;                            // +0x0, 1 bytes
    unsigned char m_ucFirstByteAfterType;  // +0x1, 1 bytes
    unsigned char iOtherSignFlags;         // +0x2, 1 bytes
    unsigned char m_ucPayloadByte3;        // +0x3, 1 bytes
    // void __cdecl TypedData::*()
};
class TESCreature : public TESActorBase, public TESAttackDamageForm, public TESModelList
{
  public:
    signed char GetCreatureType() const;
    // base TESActorBase at +0x0, size 268
    // base TESAttackDamageForm at +0x10C, size 8
    // base TESModelList at +0x114, size 20
    union
    {                                                // overlapping CodeView storage
        TESCreature* m_pCreature;                    // +0x128, 4 bytes
        CreatureSoundCollection* m_pCreatureSounds;  // +0x128, 4 bytes
    };
    TypedData Data;                  // +0x12C, 4 bytes
    unsigned char m_ucCreatureType;  // +0x130, 1 bytes
    unsigned char layoutPadding131[3];
    float m_fFirstCreatureStat;                                // +0x134, 4 bytes
    float m_fSecondCreatureStat;                               // +0x138, 4 bytes
    float m_fThirdCreatureStatCur;                             // +0x13C, 4 bytes
    TESCombatStyle* m_pCombatStyle;                            // +0x140, 4 bytes
    BGSBodyPartData* m_pBodyPartDataCur;                       // +0x144, 4 bytes
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE m_eImpactMaterial;  // +0x148, 4 bytes
    BGSImpactDataSet* m_pImpactDataSet;                        // +0x14C, 4 bytes
    bool m_bHasImpactDataSet;                                  // +0x150, 1 bytes
    unsigned char layoutPadding151[3];
    SOUND_LEVEL m_eSoundLevel;         // +0x154, 4 bytes
    BGSListForm* m_pCreatureListForm;  // +0x158, 4 bytes
    char m_cCreatureDataFlag;          // +0x15C, 1 bytes
    unsigned char layoutPadding15D[3];
    // TESCreature
    // void __cdecl TESCreature::*()
    // void __cdecl TESCreature::*()
    // void __cdecl TESCreature::*()
    // void __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*(TESFile*)
    // void __cdecl TESCreature::*(TESForm*)
    // bool __cdecl TESCreature::*(TESForm*)
    // void __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(TESActorBase*)
    // void __cdecl TESCreature::*(NiAVObject*)
    // NiAVObject* __cdecl TESCreature::*(TESObjectREFR*)
    // void __cdecl TESCreature::*(TESObjectREFR*)
    // unsigned char __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(unsigned char)
    // unsigned char __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(unsigned char)
    // unsigned char __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(unsigned char)
    // unsigned char __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(unsigned char)
    // char __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(char)
    // bool __cdecl TESCreature::*()
    // float __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(float)
    // float __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(float)
    // SOUND_LEVEL __cdecl TESCreature::*()
    // int __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(SOUND_LEVEL)
    // BGSImpactDataSet* __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(BGSImpactDataSet*)
    // BGSListForm* __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(BGSListForm*)
    // BGSTextureSet* __cdecl TESCreature::*(MATERIAL_TYPE)
    // BGSImpactData* __cdecl TESCreature::*(MATERIAL_TYPE)
    // unsigned short __cdecl TESCreature::*()
    // unsigned int __cdecl TESCreature::*()
    // unsigned short __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(bool)
    // bool __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(bool)
    // BGSImpactDataSet::IMPACT_MATERIAL_TYPE __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(BGSImpactDataSet::IMPACT_MATERIAL_TYPE)
    // bool __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*()
    // bool __cdecl TESCreature::*()
    // TESCreature* __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(TESCreature*)
    // CreatureSoundCollection* __cdecl TESCreature::*()
    // CreatureSoundCollection* __cdecl TESCreature::*()
    // const char* __cdecl TESCreature::*(CREATURE_SOUND_TYPE)
    // TESSound* __cdecl TESCreature::*(CREATURE_SOUND_TYPE)
    // TESCombatStyle* __cdecl TESCreature::*()
    // BGSBodyPartData* __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(BGSBodyPartData*)
    // void __cdecl TESCreature::*(TESObjectREFR*)
    // void __cdecl TESCreature::*(TESObjectREFR*)
    // float __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(float)
    // bool __cdecl TESCreature::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // int __cdecl TESCreature::*(ActorValue::Index)
    // void __cdecl TESCreature::*(ActorValue::Index, int)
    // void __cdecl TESCreature::*(TESObjectREFR*, bool, bool, bool)
    // void __cdecl TESCreature::*(TESObjectREFR*)
    // bool __cdecl TESCreature::*(TESForm*)
    // unsigned short __cdecl TESCreature::*(unsigned int)
    // SaveGame
    // LoadGame
    // void __cdecl TESCreature::*(BGSLoadFormBuffer*)
    // void __cdecl TESCreature::*()
    // TypedData* __cdecl TESCreature::*()
    // void __cdecl TESCreature::*(TESCombatStyle*)
    // TESCreature& __cdecl TESCreature::*(const TESCreature&)
    // void __cdecl TESCreature::*()
};
#endif
