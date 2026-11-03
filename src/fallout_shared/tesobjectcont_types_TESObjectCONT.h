// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESOBJECTCONT_H
#define FNV_TESOBJECTCONT_H

#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00478000.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESScriptableForm.h"
#include "layout_support.h"
class BGSDestructibleObjectForm;
class BGSOpenCloseForm;
class BSFileEntry;
class TESObjectCONTData;
class InventoryItemEntry;
class CollisionComponent;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESContainer;
class TESMagicCasterForm;
class TESMagicTargetForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectCONT;
class TESFormList;
class FileEntryList;
class TESWeightForm;
class DistantTreeTextureInfo;
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
class TESContainer : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<InventoryItemEntry*> objectList;  // +0x4, 8 bytes
    void InitItem(TESForm*);
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
    static void LoadModelData(TESModel*, TESFile*);
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
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    void InitItem(TESForm*);
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
class TESWeightForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    float fWeight;  // +0x4, 4 bytes
    ~TESWeightForm();
    // TESWeightForm
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*(BaseFormComponent*)
    // bool __cdecl TESWeightForm::*(BaseFormComponent*)
    // void __cdecl TESWeightForm::*(float)
    // TESWeightForm& __cdecl TESWeightForm::*(const TESWeightForm&)
    // void* __cdecl TESWeightForm::*(unsigned int)
};
class TESMagicCasterForm
{
  public:
    // bool __cdecl TESMagicCasterForm::*(TESForm*)
};
class TESMagicTargetForm
{
  public:
    // bool __cdecl TESMagicTargetForm::*(TESForm*)
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm*);
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
class BGSOpenCloseForm
{
  public:
    BGSOpenCloseForm();
    virtual BGSOpenCloseForm* InitItem(TESForm*);
    virtual bool Load(TESForm*);
    virtual bool IsOpen();
    // BGSOpenCloseForm* __cdecl BGSOpenCloseForm::*(TESForm*)
    // bool __cdecl BGSOpenCloseForm::*(TESForm*)
    // bool __cdecl BGSOpenCloseForm::*(NiNode*)
    // void __cdecl BGSOpenCloseForm::*(TESObjectREFR*, TESObjectREFR*, BGSOpenCloseForm*)
    // void __cdecl BGSOpenCloseForm::*(TESObjectREFR*, NiControllerSequence*)
    // bool __cdecl BGSOpenCloseForm::*(TESObjectREFR*, NiControllerSequence*)
    // bool __cdecl BGSOpenCloseForm::*(TESObjectREFR*, bool, bool)
    // BGSOpenCloseForm::OPEN_STATE __cdecl BGSOpenCloseForm::*(TESObjectREFR*)
    // void __cdecl BGSOpenCloseForm::*(TESObjectREFR*)
    // BGSOpenCloseForm
    // BGSOpenCloseForm& __cdecl BGSOpenCloseForm::*(const BGSOpenCloseForm&)
};
class TESObjectCONTData
{
  public:
    char m_cValue;  // +0x0, 1 bytes
    // void __cdecl TESObjectCONTData::*()
};
class __declspec(novtable) TESObjectCONT : public TESBoundAnimObject,
                                           public TESContainer,
                                           public TESFullName,
                                           public TESModelTextureSwap,
                                           public TESScriptableForm,
                                           public TESWeightForm,
                                           public BGSDestructibleObjectForm,
                                           public BGSOpenCloseForm,
                                           public TESMagicCasterForm,
                                           public TESMagicTargetForm
{
  public:
    // base TESBoundAnimObject at +0x0, size 48
    // base TESContainer at +0x30, size 12
    // base TESFullName at +0x3C, size 12
    // base TESModelTextureSwap at +0x48, size 32
    // base TESScriptableForm at +0x68, size 12
    // base TESWeightForm at +0x74, size 8
    // base BGSDestructibleObjectForm at +0x7C, size 8
    // base BGSOpenCloseForm at +0x84, size 4
    // base TESMagicCasterForm at +0x88, size 1
    // base TESMagicTargetForm at +0x89, size 1
    unsigned char layoutPadding89[3];
    TESSound* m_pOpenSound;       // +0x8C, 4 bytes
    TESSound* m_pSecondarySound;  // +0x90, 4 bytes
    TESSound* pLoopingSound;      // +0x94, 4 bytes
    TESObjectCONTData Data;       // +0x98, 1 bytes
    unsigned char layoutPadding99[3];
    // TESObjectCONT
    // void __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*()
    // bool __cdecl TESObjectCONT::*(TESFile*)
    // void __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*(TESForm*)
    // bool __cdecl TESObjectCONT::*(TESForm*)
    // void __cdecl TESObjectCONT::*()
    // char* __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*(char)
    // bool __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*(bool)
    // TESSound* __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*(TESSound*)
    // TESSound* __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*(TESSound*)
    // TESSound* __cdecl TESObjectCONT::*()
    // void __cdecl TESObjectCONT::*(TESSound*)
    // bool __cdecl TESObjectCONT::*(TESObjectREFR*, TESObjectREFR*, bool)
    // bool __cdecl TESObjectCONT::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // void __cdecl TESObjectCONT::*(TESObjectREFR*, TESObjectREFR*)
    // bool __cdecl TESObjectCONT::*()
    // TESObjectCONT& __cdecl TESObjectCONT::*(const TESObjectCONT&)
    // void __cdecl TESObjectCONT::*()
    void ResetFormData();
    TESObjectCONT();
    bool IsFormInitialized() const;
    virtual bool Load(TESFile*);
    virtual void InitItem();
};
#endif
