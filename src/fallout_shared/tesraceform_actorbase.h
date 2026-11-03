// fallout_shared/tesraceform_actorbase.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, TESBoundAnimObject and more
#ifndef FNV_TESRACEFORM_ACTORBASE_H
#define FNV_TESRACEFORM_ACTORBASE_H

#include "layout_support.h"
#include "ActorValueOwner.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESHealthForm.h"
#include "TESScriptableForm.h"
#include "layout_support.h"
class ActorBaseAttributes;
class PackedRecordData;
class BGSDestructibleObjectForm;
class BGSTouchSpellForm;
class BGSVoiceType;
class BSFileEntry;
class InventoryItemEntry;
class CollisionComponent;
class FactionReaction;
class MagicItemForm;
class ShortPoint3;
class PackageList;
class TESAIForm;
class TESActorBaseData;
class TESAnimation;
class TESAttributes;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESContainer;
class TESLevSpell;
class TESModel;
class TESFormList;
class TESSpellList;
class FileEntryList;
class TESObject : public TESForm
{
  public:
    virtual unsigned int vfn_138();
    virtual bool vfn_13c();
    virtual unsigned int vfn_140();
    virtual bool Unk_51();
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
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
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
class TESBoundAnimObject : public TESBoundObject
{
  public:
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
};
class TESActorBaseData : public BaseFormComponent
{
  public:
    ActorBaseAttributes actorData;             // +0x4, 24 bytes
    TESLevItem* m_pBaseTemplateForm;           // +0x1C, 4 bytes
    BGSVoiceType* m_kFactionList;              // +0x20, 4 bytes
    TESForm* m_ppTemplateForms;                // +0x24, 4 bytes
    int m_pDeathItem;                          // +0x28, 4 bytes
    BSSimpleList<FactionReaction*> m_pVoiceType;  // +0x2C, 8 bytes
};
class TESContainer : public BaseFormComponent
{
  public:
    BSSimpleList<InventoryItemEntry*> objectList;  // +0x4, 8 bytes
};
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    MagicItemForm* m_pMagicItem;        // +0x4, 4 bytes
    unsigned short m_usTouchSpellType;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
};
class TESSpellList : public BaseFormComponent
{
  public:
    BSSimpleList<SpellItem*> spellList;           // +0x4, 8 bytes
    BSSimpleList<TESLevSpell*> leveledSpellList;  // +0xC, 8 bytes
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
};
class PackageList
{
  public:
    BSSimpleList<TESPackage*> m_kPackages;  // +0x0, 8 bytes
};
class TESAIForm : public BaseFormComponent
{
  public:
    PackedRecordData m_kAIData;  // +0x4, 20 bytes
    PackageList m_kPackageList;  // +0x18, 8 bytes
};
class TESAttributes : public BaseFormComponent
{
  public:
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];
};
class TESAnimation : public BaseFormComponent
{
  public:
    BSSimpleList<const char*> m_kKFFileList;  // +0x4, 8 bytes
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
class TESModel : public BaseFormComponent
{
  public:
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    CollisionComponent* pData;  // +0x4, 4 bytes
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
    virtual float GetCurrentActorValue(ActorValue::Index actorValue);
};
#endif
