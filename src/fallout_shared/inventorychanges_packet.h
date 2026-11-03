// fallout_shared/inventorychanges_packet.h: declares InventoryChanges, ExtraDataList, TESBipedModelForm
#ifndef FNV_INVENTORYCHANGES_PACKET_H
#define FNV_INVENTORYCHANGES_PACKET_H

// Canonical layouts come from include/ (src/fallout_shared has same-named local headers, so the shadowed ones are
// headers do not declare yet, so those three classes are declared here as layout-identical supersets of
#include "fnv/decl/FUN_0041db00_Class.h"
#include "fnv/decl/fnv_0041d030__FUN_0041d030_shell.h"
#include "../../include/layout_support.h"
#include "BaseExtraList.h"
class BGSLoadFormBuffer;

#define FNV_INVENTORYCHANGES_H
#pragma pack(push, 4)
class InventoryChanges
{
  public:
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight, m_fArmorWeight;
    bool m_bChanged;
    unsigned char pad[3];
    InventoryChanges(TESObjectREFR*);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    InventoryChanges* CreateForReference();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InventoryChanges) == 0x14);

#define FNV_ITEMCHANGE_H
#pragma pack(push, 4)
class InventoryStackRecord
{
  public:
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    InventoryStackRecord();
    ~InventoryStackRecord();
    void* GetPayloadAddress();
    static float GetConditionPercent(float);
    static float RoundToNearestStep(float, float);
    void InitLoadGame(BGSLoadFormBuffer*);
    bool HasPerkEntry();
    bool HasApplicablePerkEntry();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InventoryStackRecord) == 0xC);

#define FNV_EXTRADATALIST_H
#pragma pack(push, 4)
class ExtraDismemberedLimbs;
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges*);
    bool HasExtraDataType0x2F();
    void InitLoadGame(BGSLoadFormBuffer*, TESForm*);
public:
    void SetExtraHealth(float);
public:
    ::ExtraDismemberedLimbs *GetDismemberedLimbs();
public:
    bool IsEmpty();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);

// No canonical header yet: API-only stub for the one flag this unit reads.
class BGSBipedModelList;
class TESForm;
enum BIPED_OBJECT;
class TESBipedModelForm
{
  public:
    unsigned int pad[2];
    unsigned char flags;
    bool GetIsHeavyArmor() const;
public:
    bool HasBipedModel(::BIPED_OBJECT, bool, ::BGSBipedModelList *);
public:
    bool IsPowerArmor();
public:
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
};
float TruncateToInt(float);
#endif
