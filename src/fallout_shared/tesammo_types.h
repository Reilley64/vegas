// only the include guard was renamed and member declarations needed by
// fallout_shared/tesammo.cpp were added (no layout change).
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESAMMO_H
#define FNV_TESAMMO_H

#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "layout_support.h"
class AmmoCharacteristics;
class AmmoProjectileData;
class BGSClipRoundsForm;
class BGSDestructibleObjectForm;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSProjectile;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class TESAmmo;
class TESAmmoEffect;
class TESBoundObject__BOUND_DATA;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class TESValueForm;
class DistantTreeTextureInfo;
class Script;
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char layoutPadding9[3];
    void InitItem(TESForm*);
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
    static void LoadModelData(TESModel*, TESFile*);
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
class TESModelTextureSwap : public TESModel
{
  public:
    void InitItem(TESForm*);
    TESModelTextureSwap();
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    // TESModelTextureSwap
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(CHUNK_ID, CHUNK_ID, CHUNK_ID)
    // bool __cdecl TESModelTextureSwap::*(void*&, unsigned int&)
    // bool __cdecl TESModelTextureSwap::*(void*, unsigned int, unsigned int)
    // void __cdecl TESModelTextureSwap::*(TESModelTextureSwap*, TESFile*)
    // void __cdecl TESModelTextureSwap::*(TESForm*)
    // void __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // bool __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // BSSimpleList<DistantTreeTextureInfo *>* __cdecl TESModelTextureSwap::*()
    // DistantTreeTextureInfo* __cdecl TESModelTextureSwap::*(int)
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(const char*, int, BGSTextureSet*)
    // void __cdecl TESModelTextureSwap::*(int)
    // int __cdecl TESModelTextureSwap::*(NiAVObject*, const NiFixedString&)
    // void __cdecl TESModelTextureSwap::*(NiAVObject*)
    // bool __cdecl TESModelTextureSwap::*(NiAVObject*, BSMap<int,DistantTreeTextureInfo *>*, int&)
    // bool __cdecl TESModelTextureSwap::*(TESForm*, TESObjectREFR*)
    // TESModelTextureSwap* __cdecl TESModelTextureSwap::*()
    // TESModelTextureSwap& __cdecl TESModelTextureSwap::*(const TESModelTextureSwap&)
    // void __cdecl TESModelTextureSwap::*()
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    BGSMessageIcon();
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
    // BGSMessageIcon
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(CHUNK_ID)
    // void __cdecl BGSMessageIcon::*(BGSMessageIcon*, TESFile*)
    // void __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // bool __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // TESIcon* __cdecl BGSMessageIcon::*()
    // const char* __cdecl BGSMessageIcon::*()
    // unsigned int __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(const char*)
    // BGSMessageIcon& __cdecl BGSMessageIcon::*(const BGSMessageIcon&)
    // void* __cdecl BGSMessageIcon::*(unsigned int)
};
class TESValueForm : public BaseFormComponent
{
  public:
    TESValueForm();
    ~TESValueForm();
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
    // TESValueForm
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*(BaseFormComponent*)
    // bool __cdecl TESValueForm::*(BaseFormComponent*)
    // void __cdecl TESValueForm::*(int)
    // SaveGame
    // LoadGame
    // TESValueForm& __cdecl TESValueForm::*(const TESValueForm&)
    // void* __cdecl TESValueForm::*(unsigned int)
};
class BGSClipRoundsForm : public BaseFormComponent
{
  public:
    BGSClipRoundsForm();
    ~BGSClipRoundsForm();
    // base BaseFormComponent at +0x0, size 4
    unsigned char m_ucClipRounds;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    // BGSClipRoundsForm
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*(BaseFormComponent*)
    // bool __cdecl BGSClipRoundsForm::*(BaseFormComponent*)
    // void __cdecl BGSClipRoundsForm::*(int)
    // BGSClipRoundsForm& __cdecl BGSClipRoundsForm::*(const BGSClipRoundsForm&)
    // void* __cdecl BGSClipRoundsForm::*(unsigned int)
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    void InitItem(TESForm*);
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
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
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    void InitItem(TESForm*);
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
    // BGSPickupPutdownSounds
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*(TESFile*)
    // void __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // bool __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // void __cdecl BGSPickupPutdownSounds::*(TESForm*)
    // GetPickupSound
    // GetPutdownSound
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // BGSPickupPutdownSounds& __cdecl BGSPickupPutdownSounds::*(const BGSPickupPutdownSounds&)
    // void* __cdecl BGSPickupPutdownSounds::*(unsigned int)
};
class AmmoCharacteristics
{
  public:
    float fSpeed;          // +0x0, 4 bytes
    unsigned char cFlags;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    // void __cdecl AmmoCharacteristics::*()
};
class AmmoProjectileData
{
  public:
    unsigned char m_ucFlags;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BGSProjectile* m_pProjectile;  // +0x4, 4 bytes
    float m_fProjectileSpeed;      // +0x8, 4 bytes
    TESForm* m_pShellCasing;       // +0xC, 4 bytes
    float m_fDamageMultiplier;     // +0x10, 4 bytes
    // void __cdecl AmmoProjectileData::*()
};
class TESAmmo : public TESBoundObject,
                public TESFullName,
                public TESModelTextureSwap,
                public TESIcon,
                public BGSMessageIcon,
                public TESValueForm,
                public BGSClipRoundsForm,
                public BGSDestructibleObjectForm,
                public BGSPickupPutdownSounds,
                public TESScriptableForm
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base BGSMessageIcon at +0x68, size 16
    // base TESValueForm at +0x78, size 8
    // base BGSClipRoundsForm at +0x80, size 8
    // base BGSDestructibleObjectForm at +0x88, size 8
    // base BGSPickupPutdownSounds at +0x90, size 12
    // base TESScriptableForm at +0x9C, size 12
    AmmoCharacteristics data;                 // +0xA8, 8 bytes
    AmmoProjectileData m_kProjectileData;     // +0xB0, 20 bytes
    BSStringT<char> m_kPrimaryString;         // +0xC4, 8 bytes
    BSStringT<char> m_kSecondaryString;       // +0xCC, 8 bytes
    BSSimpleList<TESAmmoEffect*> m_kEffects;  // +0xD4, 8 bytes
    TESAmmo();
    void ResetFormData();
    void InitItem();
    bool Load(TESFile* file);
    // TESAmmo
    // void __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*()
    // bool __cdecl TESAmmo::*(TESFile*)
    // void __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(TESForm*)
    // bool __cdecl TESAmmo::*(TESForm*)
    // void __cdecl TESAmmo::*()
    // NiAVObject* __cdecl TESAmmo::*(TESObjectREFR*, bool)
    // float __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(float)
    // float __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(float)
    // unsigned char __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(unsigned char)
    // BGSProjectile* __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(BGSProjectile*)
    // BSSimpleList<TESAmmoEffect *>* __cdecl TESAmmo::*()
    // bool __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(bool)
    // bool __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(bool)
    // const char* __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(const char*)
    // const char* __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(const char*)
    // TESForm* __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(TESForm*)
    // float __cdecl TESAmmo::*()
    // void __cdecl TESAmmo::*(float)
    // unsigned short __cdecl TESAmmo::*(unsigned int)
    // SaveGame
    // LoadGame
    // void __cdecl TESAmmo::*(char*, unsigned int)
    // AmmoCharacteristics* __cdecl TESAmmo::*()
    // AmmoProjectileData* __cdecl TESAmmo::*()
    // TESAmmo& __cdecl TESAmmo::*(const TESAmmo&)
    // void __cdecl TESAmmo::*()
};
#endif
