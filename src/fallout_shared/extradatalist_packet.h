// fallout_shared/extradatalist_packet.h: declares BaseExtraList, ExtraDataList, TaskQueueInterface, TESPackage
#ifndef FNV_EXTRADATALIST_PACKET_H
#define FNV_EXTRADATALIST_PACKET_H

// Canonical layouts come from include/ (src/fallout_shared has same-named local headers, so the shadowed ones are
// included by path). This unit owns BaseExtraList and ExtraDataList, whose generated headers do not declare every
// member defined here yet, so both are declared as layout-identical supersets of include/BaseExtraList.h and
// include/ExtraDataList.h (their guards are pre-defined).
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
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void RemoveExtra(unsigned char);
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
public:
    void SetExtraHealth(float);
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
    char prefix[0x6c];
    BSSimpleList<BGSPerkEntry*> list;
    Script* GetNextScript();
public:
    bool IsMustComplete();
public:
    bool IsFlag10000Set();
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
