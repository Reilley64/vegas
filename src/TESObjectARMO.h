// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESOBJECTARMO_H
#define FNV_TESOBJECTARMO_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "tesobjectarmo_TESForm.h"
#include "TESFullName.h"
#include "TESHealthForm.h"
#include "TESIcon.h"
#include "tesobjectarmo_TESScriptableForm.h"
#include "layout_support.h"
class BGSBipedModelList;
class BGSDestructibleObjectForm;
class BGSEquipType;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSRepairItemList;
class BipedModelForm;
class BSFileEntry;
class CollisionComponent;
class EnchantmentItem;
// Only corroborated SoundDescriptor fields are exposed; the middle four bytes have
// conflicting chance-field offsets in public declarations and are not accessed.
class SoundDescriptor
{
  public:
    TESSound* SoundAssetTmp;
    unsigned char layoutPadding4[4];
    int eType;
};
class ShortPoint3;
class ArmorData;
class TESBipedModelForm;
class TESBoundObject__BOUND_DATA;
class TESEnchantableForm;
class TESModel;
class TESModelRDT;
class TESModelTextureSwap;
class TESObjectARMO;
class TESFormList;
class FileEntryList;
class TESValueForm;
class TESWeightForm;
class DistantTreeTextureInfo;
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
};
enum BGSEquipType__EQUIP_TYPE
{
    BGSEquipType__EQUIP_TYPE_ET_NONE = -1,
    BGSEquipType__EQUIP_TYPE_ET_BIG_GUN = 0,
    BGSEquipType__EQUIP_TYPE_ET_ENERGY_WEAPON = 1,
    BGSEquipType__EQUIP_TYPE_ET_SMALL_GUN = 2,
    BGSEquipType__EQUIP_TYPE_ET_MELEE_WEAPON = 3,
    BGSEquipType__EQUIP_TYPE_ET_UNARMED_WEAPON = 4,
    BGSEquipType__EQUIP_TYPE_ET_THROWN_WEAPON = 5,
    BGSEquipType__EQUIP_TYPE_ET_MINE = 6,
    BGSEquipType__EQUIP_TYPE_ET_BODY_WEAR = 7,
    BGSEquipType__EQUIP_TYPE_ET_HEAD_WEAR = 8,
    BGSEquipType__EQUIP_TYPE_ET_HAND_WEAR = 9,
    BGSEquipType__EQUIP_TYPE_ET_CHEMS = 10,
    BGSEquipType__EQUIP_TYPE_ET_STIMPACK = 11,
    BGSEquipType__EQUIP_TYPE_ET_FOOD = 12,
    BGSEquipType__EQUIP_TYPE_ET_ALCOHOL = 13,
    BGSEquipType__EQUIP_TYPE_ET_COUNT = 14
};
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
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
    // short& __cdecl ShortPoint3::*(int)
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
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
};
class TESEnchantableForm : public BaseFormComponent
{
  public:
    void SetCastingType(MagicSystem__CastingType);
    void SetFormEnchantmentAmount(unsigned short);
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    EnchantmentItem* m_pEnchantment;       // +0x4, 4 bytes
    unsigned short m_usEnchantmentAmount;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;  // +0xC, 4 bytes
};
class TESValueForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
};
class TESWeightForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    float fWeight;  // +0x4, 4 bytes
};
class BipedModelForm
{
  public:
    unsigned int m_uiBipedModelFlags;  // +0x0, 4 bytes
    unsigned char m_ucBipedModelData;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // BSFileEntry** __cdecl FileEntryList::*()
};
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
class TESModelTextureSwap : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    // BSSimpleList<DistantTreeTextureInfo *>* __cdecl TESModelTextureSwap::*()
    // DistantTreeTextureInfo* __cdecl TESModelTextureSwap::*(int)
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
};
class TESModelRDT : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
};
class TESBipedModelForm : public BaseFormComponent
{
  public:
    bool GetIsHeavyArmor() const;
    bool GetIsMediumArmor() const;
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    BipedModelForm m_kBipedModelForm;   // +0x4, 8 bytes
    TESModelTextureSwap bipedModel[2];  // +0xC, 64 bytes
    TESModelTextureSwap worldModel[2];  // +0x4C, 64 bytes
    TESIcon m_kIcon[2];                 // +0x8C, 24 bytes
    BGSMessageIcon messageIcon[2];      // +0xA4, 32 bytes
    TESModelRDT m_kFaceGenModel;        // +0xC4, 24 bytes
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
};
class BGSEquipType : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSEquipType__EQUIP_TYPE m_eEquipType;  // +0x4, 4 bytes
};
class BGSRepairItemList : public BaseFormComponent
{
  public:
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
    // BSSimpleList<TESForm *>* __cdecl BGSRepairItemList::*(TESForm*)
};
class BGSBipedModelList : public BaseFormComponent
{
  public:
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
};
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
};
class ArmorData
{
  public:
    unsigned short m_usArmorRating;  // +0x0, 2 bytes
    unsigned char layoutPadding2[2];
    float fArmorProtectionValue;  // +0x4, 4 bytes
    unsigned char cFlags;         // +0x8, 1 bytes
    unsigned char m_ucSubtype;    // +0x9, 1 bytes
    unsigned char layoutPaddingA[2];
};
class TESObjectARMO : public TESBoundObject,
                      public TESFullName,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESBipedModelForm,
                      public BGSDestructibleObjectForm,
                      public BGSEquipType,
                      public BGSRepairItemList,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
  public:
    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    unsigned char GetArmorType();
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESScriptableForm at +0x3C, size 12
    // base TESEnchantableForm at +0x48, size 16
    // base TESValueForm at +0x58, size 8
    // base TESWeightForm at +0x60, size 8
    // base TESHealthForm at +0x68, size 8
    // base TESBipedModelForm at +0x70, size 220
    // base BGSDestructibleObjectForm at +0x14C, size 8
    // base BGSEquipType at +0x154, size 8
    // base BGSRepairItemList at +0x15C, size 8
    // base BGSBipedModelList at +0x164, size 8
    // base BGSPickupPutdownSounds at +0x16C, size 12
    ArmorData data;      // +0x178, 12 bytes
    unsigned int flags;  // +0x184, 4 bytes
    union
    {                                                               // overlapping CodeView storage
        BSSimpleList<SoundDescriptor*>* m_pPickupPutdownSoundList;  // +0x188, 4 bytes
        TESObjectARMO* m_pSoundSourceArmor;                         // +0x188, 4 bytes
    };
    bool m_bUsesSoundList;  // +0x18C, 1 bytes
    unsigned char layoutPadding18D[3];
};
#endif
