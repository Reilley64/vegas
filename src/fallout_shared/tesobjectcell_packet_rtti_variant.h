// fallout_shared/tesobjectcell_packet_rtti_variant.h: declares TESFile, PlayerMover, SettingT_GameSettingCollection_, NiNode, TESDataHandler and more
#ifndef TESOBJECTCELL_PACKET_H
#define TESOBJECTCELL_PACKET_H

#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
struct TESRecordHeader;
class TESFile
{
  public:
    char pad[0x240];
    TESRecordHeader* GetRecordHeader();
};
class PlayerMover
{
  public:
    char pad[0x94];
    unsigned int moveMode;
    unsigned int GetActorStateFlags();
};
union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
};
class NiAVObject;
class NiAVObject;
class NiNode
{
  public:
public:
    ::NiAVObject *GetAt(unsigned int);
};
class TESImageSpaceModifier;
template <class T> class BSSimpleList;
class TESDataHandler
{
  public:
};
class BGSEncounterZone;
class BGSTerrainManager;
class TESWorldSpace
{
  public:
    virtual ~TESWorldSpace();  // the original class is polymorphic (rtti_variants.py)
  public:
public:
    ::BGSTerrainManager *GetWorldTerrainManager();
};
class TESForm;
class NiNode;
class NiAVObject
{
  public:
};
class ExtraRadioData;
class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // the original class is polymorphic (rtti_variants.py)
  public:
    static BGSEncounterZone* FindEncounterZone();
public:
    ::ExtraRadioData *GetExtraRadioData();
};
class DoorCell
{
  public:
    TESForm* GetOwner();
};
class TESSound
{
  public:
    char pad[0x45];
    unsigned char field45;
    unsigned char GetField45();
};
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* operator->() const;
};
class GlobalObject_00633c90 : public GarbageCollectorObjectPtr
{
};
struct InteriorCellData
{
    char pad[0x20];
    float clipDist;
};
class CellLightingTemplate
{
  public:
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
};
class BGSPerkEntry;
class BGSLoadedReferenceCollection
{
  public:
};
class ActorCause;
class BSExtraData;
class BaseExtraList
{
  public:
    char data[0x20];
};
class InventoryChanges;
class ExtraDataList : public BaseExtraList
{
  public:
public:
    ::InventoryChanges *GetContainerChangeData();
};
class RecursiveSpinLock
{
  public:
};
class ExteriorCellData
{
  public:
    int x;
    int y;
};
class TESWorldSpace;
class TESObjectCELL
{
  public:
    virtual ~TESObjectCELL();  // the original class is polymorphic (rtti_variants.py)
  public:
    char padToExtraData[32];
    unsigned char field24;
    char padToExtraData2[3];
    ExtraDataList extraDataList;
    void* cellData;
    char padToRefListLock[0x34];
    RecursiveSpinLock refListLock;
    char padToWorldSpace[0x3f];
    TESWorldSpace* worldSpace;
    char padToUnknownDC[0x18];
    unsigned int unknownDC;
    char padToField210[0x130];
    unsigned char field210;
    char padToField619[0x408];
    unsigned char field619;
    char padToField760[0x146];
    void* field760;
    char padToAudioMarkers[0x70];
    BSSimpleList<ActorCause*> audioMarkers;
    unsigned int audioMarkerCount;
    unsigned char GetField24();
    unsigned char FUN_00552bb0();
    unsigned char FUN_00542d20();
    void* FUN_005454d0();
    void ClearAudioMarkers();
    int GetCellGridX();
    int GetCellGridY();
    bool HasCellExtraData();
    bool IsCellInterior() const;
    TESWorldSpace* GetParentWorldSpace();
    void CellRefLockEnter();
    void ClearData();
    int GetCellStandValue();
    float GetInteriorLightValue();
    void ClearCellReferenceList();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    BGSEncounterZone* FindEncounterZone() const;
};

#endif
