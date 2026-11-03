// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSEXPLOSION_H
#define FNV_BGSEXPLOSION_H

#include "fnv/decl/BGSTalkingActivator.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/symbols_004fa000.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "layout_support.h"
class BGSExplosion;
class ExplosionEffectSettings;
class BGSImpactDataSet;
class BGSPreloadable;
class BSFileEntry;
class EnchantmentItem;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESEnchantableForm;
class TESImageSpaceModifiableForm;
class TESImageSpaceModifier;
class TESModel;
class TESObjectLIGH;
class TESFormList;
class FileEntryList;
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
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
    TESBoundObject();
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
    TESModel();
    static void LoadModelData(TESModel* model, TESFile* file);
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
class TESEnchantableForm : public BaseFormComponent
{
  public:
    TESEnchantableForm();
    void InitItem(TESForm* form);
    // base BaseFormComponent at +0x0, size 4
    EnchantmentItem* m_pEnchantment;       // +0x4, 4 bytes
    unsigned short m_usEnchantmentAmount;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;  // +0xC, 4 bytes
    // TESEnchantableForm
    // void __cdecl TESEnchantableForm::*(MagicSystem::CastingType)
    // void __cdecl TESEnchantableForm::*()
    // void __cdecl TESEnchantableForm::*()
    // void __cdecl TESEnchantableForm::*()
    // void __cdecl TESEnchantableForm::*(TESForm*)
    // void __cdecl TESEnchantableForm::*(BaseFormComponent*)
    // bool __cdecl TESEnchantableForm::*(BaseFormComponent*)
    // void __cdecl TESEnchantableForm::*(EnchantmentItem*)
    // GetFormEnchantmentAmount
    // void __cdecl TESEnchantableForm::*(unsigned short)
    // TESEnchantableForm& __cdecl TESEnchantableForm::*(const TESEnchantableForm&)
public:
    void SetFormEnchantmentAmount(unsigned short);
};
class BGSPreloadable : public BaseFormComponent
{
  public:
    BGSPreloadable();
    // base BaseFormComponent at +0x0, size 4
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*(BaseFormComponent*)
    // bool __cdecl BGSPreloadable::*(BaseFormComponent*)
    // BGSPreloadable
    // BGSPreloadable& __cdecl BGSPreloadable::*(const BGSPreloadable&)
};
class TESImageSpaceModifiableForm : public BaseFormComponent
{
  public:
    TESImageSpaceModifiableForm();
    void InitItem(TESForm* form);
    // base BaseFormComponent at +0x0, size 4
    TESImageSpaceModifier* m_pImageSpaceModifier;  // +0x4, 4 bytes
    // TESImageSpaceModifiableForm
    // void __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*(TESForm*)
    // void __cdecl TESImageSpaceModifiableForm::*(BaseFormComponent*)
    // bool __cdecl TESImageSpaceModifiableForm::*(BaseFormComponent*)
    // TESImageSpaceModifier* __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*(TESImageSpaceModifier*)
    // TESImageSpaceModifiableForm& __cdecl TESImageSpaceModifiableForm::*(const TESImageSpaceModifiableForm&)
};
class ExplosionEffectSettings
{
  public:
    float fForce;                        // +0x0, 4 bytes
    float afDamageAmount;                // +0x4, 4 bytes
    float fRadius;                       // +0x8, 4 bytes
    TESObjectLIGH* apTargetLight;               // +0xC, 4 bytes
    TESSound* m_pPrimaryImpactSound;     // +0x10, 4 bytes
    unsigned int iFlags;                 // +0x14, 4 bytes
    float ExplosionRuntimeData;          // +0x18, 4 bytes
    BGSImpactDataSet* m_pImpactDataSet;  // +0x1C, 4 bytes
    TESSound* m_pSecondaryImpactSound;   // +0x20, 4 bytes
    float ImpactSoundSettings;           // +0x24, 4 bytes
    float m_fImpactSecondValue;          // +0x28, 4 bytes
    float m_fImpactThirdValue;           // +0x2C, 4 bytes
    SOUND_LEVEL m_eSoundLevel;           // +0x30, 4 bytes
    // void __cdecl ExplosionEffectSettings::*()
    // void __cdecl ExplosionEffectSettings::*()
    // void __cdecl ExplosionEffectSettings::*()
};
class BGSExplosion : public TESBoundObject,
                     public TESFullName,
                     public TESModel,
                     public TESEnchantableForm,
                     public BGSPreloadable,
                     public TESImageSpaceModifiableForm
{
  public:
    BGSExplosion();
    void ResetFormData();
    ExplosionEffectSettings* FUN_004fadc0();
    void InitItem();
    bool Load(TESFile* file);
    void FUN_004fb0b0(BGSImpactDataSet* value);
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModel at +0x3C, size 24
    // base TESEnchantableForm at +0x54, size 16
    // base BGSPreloadable at +0x64, size 4
    // base TESImageSpaceModifiableForm at +0x68, size 8
    TESBoundObject* m_pExplosionBoundObject;  // +0x70, 4 bytes
    ExplosionEffectSettings Data;             // +0x74, 52 bytes
    // BGSExplosion
    // void __cdecl BGSExplosion::*()
    // ExplosionEffectSettings* __cdecl BGSExplosion::*()
    // void __cdecl BGSExplosion::*()
    // bool __cdecl BGSExplosion::*(TESFile*)
    // void __cdecl BGSExplosion::*()
    // void __cdecl BGSExplosion::*(TESForm*)
    // bool __cdecl BGSExplosion::*(TESForm*)
    // void __cdecl BGSExplosion::*()
    // NiAVObject* __cdecl BGSExplosion::*(TESObjectREFR*, bool)
    // void __cdecl BGSExplosion::*(TESObjectREFR*)
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // TESObjectLIGH* __cdecl BGSExplosion::*()
    // TESSound* __cdecl BGSExplosion::*()
    // TESSound* __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // float __cdecl BGSExplosion::*()
    // BGSImpactDataSet* __cdecl BGSExplosion::*()
    // SOUND_LEVEL __cdecl BGSExplosion::*()
    // int __cdecl BGSExplosion::*()
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(TESObjectLIGH*)
    // void __cdecl BGSExplosion::*(TESSound*)
    // void __cdecl BGSExplosion::*(TESSound*)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(float)
    // void __cdecl BGSExplosion::*(BGSImpactDataSet*)
    // void __cdecl BGSExplosion::*(int)
    // bool __cdecl BGSExplosion::*(BGSExplosion::BGSExplosionFlags)
    // void __cdecl BGSExplosion::*(BGSExplosion::BGSExplosionFlags, bool)
    // BGSTextureSet* __cdecl BGSExplosion::*(MATERIAL_TYPE)
    // BGSImpactData* __cdecl BGSExplosion::*(MATERIAL_TYPE)
    // TESBoundObject* __cdecl BGSExplosion::*()
    // void __cdecl BGSExplosion::*(TESBoundObject*)
    // void __cdecl BGSExplosion::*(IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSExplosion::*()
    // BGSExplosion& __cdecl BGSExplosion::*(const BGSExplosion&)
    // void __cdecl BGSExplosion::*()
};
#endif
