// Layout asserts are preserved; the member declarations used by
// fallout_shared/bgsbodypartdata.cpp are added below each class.
#ifndef FNV_TASK_BGSBODYPARTDATA_COPY_H
#define FNV_TASK_BGSBODYPARTDATA_COPY_H

#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/Obj5e5300.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFile.h"
#include "NiPoint3.h"

class BGSBodyPart;
class BGSBodyPartData;
class BGSDebris;
class BGSExplosion;
class BGSImpactDataSet;
class BGSPreloadable;
class BGSRagdoll;
class BSFileEntry;
class BodyPartInfo;
class QueuedFile;
class TESModel;
class TESModelPSA;
class FileEntryList;

enum IO_TASK_PRIORITY
{
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_CRITICAL = 0,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_VERY_HIGH = 1,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_HIGH = 2,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_MID = 3,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_LOW = 4,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_VERY_LOW = 5,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_COUNT = 6,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_INVALID = 7,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_HIGHEST = 0,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_LOWEST = 5
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
class BGSPreloadable : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSPreloadable();
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*(BaseFormComponent*)
    // bool __cdecl BGSPreloadable::*(BaseFormComponent*)
    // BGSPreloadable
    // BGSPreloadable& __cdecl BGSPreloadable::*(const BGSPreloadable&)
};
class TESModelPSA : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    // TESModelPSA
    // void __cdecl TESModelPSA::*()
    // TESModelPSA& __cdecl TESModelPSA::*(const TESModelPSA&)
    // void __cdecl TESModelPSA::*()
};
class BodyPartInfo
{
  public:
    float m_fDamageMultiplier;              // +0x0, 4 bytes
    unsigned char cFlags;                   // +0x4, 1 bytes
    unsigned char cType;                    // +0x5, 1 bytes
    unsigned char m_ucPartID;               // +0x6, 1 bytes
    char m_cActorValue;                     // +0x7, 1 bytes
    unsigned char m_ucHealthPercent;        // +0x8, 1 bytes
    unsigned char m_ucHitChance;            // +0x9, 1 bytes
    unsigned char m_ucLimbReplacementType;  // +0xA, 1 bytes
    unsigned char layoutPaddingB[1];
    BGSDebris* m_pExplosion;        // +0xC, 4 bytes
    BGSExplosion* m_pDebrisObject;  // +0x10, 4 bytes
    float m_fExplosionChance;       // +0x14, 4 bytes
    float m_fDebrisScale;           // +0x18, 4 bytes
    unsigned char m_ucSeverable;    // +0x1C, 1 bytes
    unsigned char layoutPadding1D[3];
    BGSDebris* m_pRelatedObject1;         // +0x20, 4 bytes
    BGSExplosion* m_pRelatedObject2;      // +0x24, 4 bytes
    float m_fValue3;                      // +0x28, 4 bytes
    NiPoint3 m_kPoint1;                   // +0x2C, 12 bytes
    NiPoint3 m_kPoint2;                   // +0x38, 12 bytes
    BGSImpactDataSet* m_pRelatedObject3;  // +0x44, 4 bytes
    BGSImpactDataSet* m_pRelatedObject4;  // +0x48, 4 bytes
    unsigned char m_ucByte1;              // +0x4C, 1 bytes
    unsigned char m_ucByte2;              // +0x4D, 1 bytes
    unsigned char layoutPadding4E[2];
    float m_fValue4;  // +0x50, 4 bytes
    // void __cdecl BodyPartInfo::*()
    // void __cdecl BodyPartInfo::*()
    // void __cdecl BodyPartInfo::*()
};
class BGSBodyPart
{
  public:
    // is called through vtable slot 0), so MSVC lays out the hidden vptr at
    // +0x0 itself; keeping both would shift every member by 4. The member is
    // therefore dropped and the virtual declared below; all other offsets and
    // the size are preserved verbatim.
    BSStringT<char> NodeName;         // +0x4, 8 bytes
    BSStringT<char> TargetName;       // +0xC, 8 bytes
    BSStringT<char> m_kVATSNodeName;  // +0x14, 8 bytes
    BSStringT<char> m_kPartName;      // +0x1C, 8 bytes
    BSStringT<char> m_kGoreName;      // +0x24, 8 bytes
    TESModel m_kModel;                // +0x2C, 24 bytes
    TESModelPSA m_kRagdollModel;      // +0x44, 24 bytes
    BodyPartInfo Data;                // +0x5C, 84 bytes
    BGSBodyPart();
    ~BGSBodyPart();
    bool Load(TESFile* file);
    void InitItem(TESForm* parent);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
    // BGSBodyPart
    // void __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*()
    // bool __cdecl BGSBodyPart::*(TESFile*)
    // void __cdecl BGSBodyPart::*(TESForm*, BGSBodyPart*)
    // bool __cdecl BGSBodyPart::*(BGSBodyPart*)
    // void __cdecl BGSBodyPart::*(TESForm*)
    // bool __cdecl BGSBodyPart::*()
    // bool __cdecl BGSBodyPart::*()
    // bool __cdecl BGSBodyPart::*()
    // bool __cdecl BGSBodyPart::*()
    // bool __cdecl BGSBodyPart::*()
    // bool __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*(bool)
    // bool __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*(bool)
    // void __cdecl BGSBodyPart::*(float)
    // float __cdecl BGSBodyPart::*()
    // BGSBodyPart::LIMB_ENUM __cdecl BGSBodyPart::*()
    // float __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // char __cdecl BGSBodyPart::*()
    // const char* __cdecl BGSBodyPart::*()
    // const char* __cdecl BGSBodyPart::*()
    // const char* __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*(char*)
    // const char* __cdecl BGSBodyPart::*()
    // const char* __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // BGSExplosion* __cdecl BGSBodyPart::*()
    // TESModel* __cdecl BGSBodyPart::*()
    // const char* __cdecl BGSBodyPart::*()
    // BGSDebris* __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // float __cdecl BGSBodyPart::*()
    // float __cdecl BGSBodyPart::*()
    // BGSImpactDataSet* __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // BGSExplosion* __cdecl BGSBodyPart::*()
    // BGSDebris* __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // float __cdecl BGSBodyPart::*()
    // BGSImpactDataSet* __cdecl BGSBodyPart::*()
    // unsigned char __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*(BGSExplosion*)
    // void __cdecl BGSBodyPart::*(BGSDebris*)
    // void __cdecl BGSBodyPart::*(BGSImpactDataSet*)
    // void __cdecl BGSBodyPart::*(BGSExplosion*)
    // void __cdecl BGSBodyPart::*(BGSDebris*)
    // void __cdecl BGSBodyPart::*(BGSImpactDataSet*)
    // void __cdecl BGSBodyPart::*(const char*)
    // void __cdecl BGSBodyPart::*(NiPoint3)
    // NiPoint3 __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*(NiPoint3)
    // NiPoint3 __cdecl BGSBodyPart::*()
    // void __cdecl BGSBodyPart::*(BGSBodyPart::LIMB_ENUM, NiAVObject*)
    // void __cdecl BGSBodyPart::*(BGSBodyPart::LIMB_ENUM, NiAVObject*)
    // void __cdecl BGSBodyPart::*(BGSBodyPart::LIMB_ENUM, NiAVObject*)
    // bool __cdecl BGSBodyPart::*(NiAVObject*)
    // void __cdecl BGSBodyPart::*()
    // BGSBodyPart& __cdecl BGSBodyPart::*(const BGSBodyPart&)
    // void* __cdecl BGSBodyPart::*(unsigned int)
};
// Note: no offsetof assert for the vtable pointer; it is the compiler-laid-out
// vptr at +0x0 (see member note above), not a declared member.
class BGSBodyPartData : public TESForm, public TESModel, public BGSPreloadable
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModel at +0x18, size 24
    // base BGSPreloadable at +0x30, size 4
    BGSBodyPart* m_apBodyParts[15];  // +0x34, 60 bytes
    BGSRagdoll* m_pRagdoll;          // +0x70, 4 bytes
    BGSBodyPartData();
    void ResetFormData();
    virtual void ClearData();
    void ClearBodyParts();
    bool Load(TESFile* file);
    virtual void InitItem();
    void AddBodyPart(BGSBodyPart* part);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
    static void InitializeBodyPartData();
    static BGSBodyPartData* ms_pBodyPartData;
    static BGSBodyPartData* ms_pBodyPartDataInstance;
    // BGSBodyPartData
    // void __cdecl BGSBodyPartData::*()
    // void __cdecl BGSBodyPartData::*()
    // void __cdecl BGSBodyPartData::*()
    // bool __cdecl BGSBodyPartData::*(TESFile*)
    // void __cdecl BGSBodyPartData::*()
    // BGSBodyPart** __cdecl BGSBodyPartData::*()
    // void __cdecl BGSBodyPartData::*()
    // void __cdecl BGSBodyPartData::*(BGSBodyPart*)
    // void __cdecl BGSBodyPartData::*(NiAVObject*, NiAVObject*, BGSBodyPart::LIMB_ENUM, NiAVObject*)
    // void __cdecl BGSBodyPartData::*(NiAVObject*, NiAVObject*, BGSBodyPart::LIMB_ENUM, NiAVObject*)
    // bool __cdecl BGSBodyPartData::*()
    // bool __cdecl BGSBodyPartData::*(NiNode*)
    // void __cdecl BGSBodyPartData::*(BSDismemberRoots*)
    // void __cdecl BGSBodyPartData::*(BSSimpleList<BGSBodyPart *>*)
    // void __cdecl BGSBodyPartData::*(IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSBodyPartData::*()
    // BGSRagdoll* __cdecl BGSBodyPartData::*()
    // void __cdecl BGSBodyPartData::*()
    // BGSBodyPartData& __cdecl BGSBodyPartData::*(const BGSBodyPartData&)
    // void __cdecl BGSBodyPartData::*()
};
// Unit-local shims for fallout_shared/bgsbodypartdata.cpp Load/InitItem,
// following the accepted bgsimpactdata.h precedent. TESFileFormInt recovers
// the 32-bit GetTESForm the 2008 Load compares with cmp eax,imm.
// resolver. BGSRagdoll is a minimal polymorphic scaffold so InitItem's
// dynamic_cast has a complete target type; only its name matters for codegen
// and manifest RTTI bindings. TESDataHandlerForms extends the minimal canonical
// TESDataHandler with the direct-called AddFormToDataHandler used by
// InitializeBodyPartData (the shared header cannot be edited here).
struct TESFileFormInt : public TESFile
{
};
struct TESFormInitFlag : public TESForm
{
};
class BGSRagdoll : public TESForm
{
  public:
    virtual ~BGSRagdoll();
};
class TESForm;
class TESDataHandler
{
public:
    bool AddFormToDataHandler(::TESForm *);
};  // only a base for the stand-in below (the unit-local layout_support.h declares no TESDataHandler)
struct TESDataHandlerForms : public TESDataHandler
{
};
#endif
