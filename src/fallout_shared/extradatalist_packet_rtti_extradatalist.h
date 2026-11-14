// fallout_shared/extradatalist_packet_rtti_extradatalist.h: declares BaseExtraList, ExtraDataList, TaskQueueInterface, TESPackage
#ifndef FNV_EXTRADATALIST_PACKET_H
#define FNV_EXTRADATALIST_PACKET_H

// Canonical layouts come from include/ (src/fallout_shared has same-named local headers, so the shadowed ones are
// included by path). This unit owns BaseExtraList and ExtraDataList, whose generated headers do not declare every
// member defined here yet, so both are declared as layout-identical supersets of include/BaseExtraList.h and
// include/ExtraDataList.h (their guards are pre-defined).
#include "fnv/decl/FUN_0040fe80_shell.h"
#include "fnv/decl/FUN_004182b0_shell.h"
#include "fnv/decl/FUN_00421910_shell.h"
#include "fnv/decl/FUN_00421d20_shell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_01014000.h"
#include "fnv/symbols_011df000.h"
#include "../../include/layout_support.h"
#define FNV_BASEEXTRALIST_H
#define FNV_EXTRADATALIST_H
class ExtraDismemberedLimbs;
class SeenData;
class LockExtraData;
class TESImageSpaceModifier;
class BaseExtraList
{
  public:
    void** m_ppVirtualMethodTable;
    BSExtraData* pHead;
    unsigned char iFlags[21];
    unsigned char layoutPadding1D[3];
};
class ExtraDataList : public BaseExtraList
{
  public:
    ExtraDataList();
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges*);
    bool HasExtraDataType0x2F();
    void RemoveExtraDataType0x15();
    bool IsEmpty();
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
#include "../../include/TESObjectREFR.h"
#include "Actor.h"
#include "BaseProcess.h"
#include "RecursiveSpinLock.h"
#include "NiMemObject.h"
// No canonical headers yet for these.
struct TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
};
class TESPackage
{
  public:
    virtual ~TESPackage();  // the original class is polymorphic (rtti_variants.py)
  public:
    char prefix[104];
    BSSimpleList<BGSPerkEntry*> list;
    Script* GetNextScript();
};
// include/layout_support.h declares TESObjectCELL, TESDataHandler and TESObjectREFR without these members.
class ExtraDataList;
struct FUN_004610d0_shell : public TESDataHandler
{
public:
    ::ExtraDataList *GetExtraDataList();
};
struct FUN_00555bc0_shell : public TESObjectCELL
{
    SeenData* FindSeenData();
};
struct FUN_00569140_shell : public TESObjectREFR
{
    LockExtraData* GetMyLock();
};
struct FUN_00569580_shell : public TESObjectREFR
{
    TESForm* GetOwnerForm();
};
#endif
