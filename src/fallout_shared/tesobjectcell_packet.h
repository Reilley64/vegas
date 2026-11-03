// fallout_shared/tesobjectcell_packet.h: declares TESFile, PlayerMover, SettingT_GameSettingCollection_, NiNode, TESDataHandler and more
#ifndef TESOBJECTCELL_PACKET_H
#define TESOBJECTCELL_PACKET_H

#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
struct TESRecordHeader;
class TESFile
{
  public:
    char pad[0x240];
    TESRecordHeader* GetRecordHeader();
public:
    bool IsEndianConversionRequired();
public:
    unsigned int GetOffset();
public:
    bool IsMasterFile();
public:
    bool NextChunk();
public:
    bool IsGroupOpen();
public:
    ::TESFile *GetParentTESFile();
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
class TESFile;
class TESForm;
class TESDataHandler
{
  public:
public:
    bool ConstructObject(::TESFile *, bool, ::TESForm *, bool);
};
class BGSEncounterZone;
class BGSTerrainManager;
class TESFile;
class TESObjectCELL;
class TESWorldSpace
{
  public:
public:
    static bool IsFormIDOwnedByFile(unsigned int, ::TESFile *);
public:
    ::BGSTerrainManager *GetWorldTerrainManager();
public:
    ::TESObjectCELL *GetCellAtGridPosition(int, int);
};
class TESForm;
class NiNode;
class NiExtraData;
class NiFixedString;
struct NiPoint3;
class NiAVObject
{
  public:
public:
    ::NiPoint3 &FUN_0043c490();
public:
    void EnsureWorldBound();
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};
class BSExtraData;
class ExtraRadioData;
class TESObjectREFR
{
  public:
    static BGSEncounterZone* GetDefaultEncounterZone();
public:
    ::BSExtraData *GetExtraData(unsigned char) const;
public:
    ::ExtraRadioData *GetExtraRadioData();
public:
    float GetScale();
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
extern GlobalObject_00633c90 g_011deda4;
struct InteriorCellData
{
    char pad[0x4];
    unsigned int unk04;
    int unk08;
    float unk0c;
    float unk10;
    char pad14[0xc];
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
class TESObjectREFR;
template <> class BSSimpleList<TESObjectREFR*>
{
  public:
    TESObjectREFR* item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
    bool FUN_008256d0();
    void AddHead(TESObjectREFR* const& item);
};
class BGSLoadedReferenceCollection
{
  public:
public:
    void FUN_005270b0(::TESObjectREFR *);
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
public:
    void FUN_0040fba0();
};
class ExteriorCellData
{
  public:
    int x;
    int y;
};
class TESWorldSpace;
class TESRegionList;
class TESObjectCELL
{
  public:
    char padToExtraData[0x24];
    unsigned char field24;
    char padToExtraData2[3];
    ExtraDataList extraDataList;
    void* cellData;
    void* unk4c;
    char pad50[0x14];
    void* unk64;
    char pad68[0x14];
    void* unk7c;
    RecursiveSpinLock refListLock;
    char padToWorldSpace[0x27];
    unsigned short unka8;
    char padaa[0x16];
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
    void SetLightingTemplate(void* value);
    int GetCellStandValue();
    bool FUN_00558b80(int mask);
    CellLightingTemplate* GetLightingTemplate();
    float GetInteriorLightValue();
    BSSimpleList<BGSPerkEntry*>* FUN_009604f0();
    void ClearCellReferenceList();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    BGSEncounterZone* FindEncounterZone() const;
public:
    ::TESRegionList *GetRegionList(bool);
public:
    void RemoveNonPersistentRefs();
    void FUN_005571a0(bool active);
    bool FUN_005434d0(struct FormGroupQuery* group);
};

#endif
