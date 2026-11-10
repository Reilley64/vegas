// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSPLACEABLEWATER_H
#define FNV_BGSPLACEABLEWATER_H

#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/HungerStageData.h"
#include "fnv/water/placeable_water.h"
#include "fnv/decl/S_00462230.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "layout_support.h"
struct BGSPlaceableWater;
class PlaceableWaterData;
class BSFileEntry;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESModel;
class TESFormList;
class FileEntryList;
struct TESWaterForm;
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
    TESBoundObject();
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
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    TESModel();
    static void LoadModelData(TESModel* model, TESFile* file);
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
struct BGSPlaceableWater : public TESBoundObject, public TESModel
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESModel at +0x30, size 24
    PlaceableWaterData Data;  // +0x48, 8 bytes
    BGSPlaceableWater();
    void ResetFormData();
    virtual void InitItem(void);
    virtual bool Load(TESFile* file);
    bool HasFlags(unsigned int);
    // BGSPlaceableWater
    // void __cdecl BGSPlaceableWater::*()
    // PlaceableWaterData* __cdecl BGSPlaceableWater::*()
    // void __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*(TESFile*)
    // void __cdecl BGSPlaceableWater::*()
    // void __cdecl BGSPlaceableWater::*(TESForm*)
    // bool __cdecl BGSPlaceableWater::*(TESForm*)
    // void __cdecl BGSPlaceableWater::*()
    // const char* __cdecl BGSPlaceableWater::*()
    // TESWaterForm* __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // bool __cdecl BGSPlaceableWater::*()
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(bool)
    // void __cdecl BGSPlaceableWater::*(TESWaterForm*)
    // bool __cdecl BGSPlaceableWater::*(BGSPlaceableWater::BGSPlaceableWaterFlags)
    // void __cdecl BGSPlaceableWater::*(BGSPlaceableWater::BGSPlaceableWaterFlags, bool)
    // bool __cdecl BGSPlaceableWater::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // BGSPlaceableWater& __cdecl BGSPlaceableWater::*(const BGSPlaceableWater&)
    // void __cdecl BGSPlaceableWater::*()
};
#endif
