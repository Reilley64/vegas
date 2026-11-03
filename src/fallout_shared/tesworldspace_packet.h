// fallout_shared/tesworldspace_packet.h: declares TESForm, TESObjectREFR, TESObjectCELL, TESFile, TESRegion and more
#ifndef TESWORLDSPACE_PACKET_H
#define TESWORLDSPACE_PACKET_H

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/fnv_0054db50__FUN_0054db50_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
class TESWorldSpace;
class BGSTerrainManager;
class TESFile;
class TESObjectREFR;
class TESFile;
class TESForm
{
  public:
public:
    void SetInitializationState(bool);
public:
    bool IsReservedFormID();
public:
    ::TESFile *GetFile(int);
};
class TESObjectREFR : public TESForm
{
};
template <class T, int N> class BSSimpleArray
{
  public:
    char data[16];
};
class TESRegionList;
class TESObjectCELL
{
  public:
    char pad[0x24];
    unsigned char flags;
    bool IsCellInterior() const;
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::TESRegionList *GetRegionList(bool);
};
template <class T> class BSStringT
{
  public:
    bool Set(const T*, unsigned int);
};
template <class K, class V> class NiTPointerMap
{
  public:
    bool GetAt(K, V&) const;
};
struct TESRecordHeader;
class TESFile
{
  public:
    TESFile* GetThreadSafeRootFile();
public:
    bool IsEndianConversionRequired();
public:
    ::TESRecordHeader *GetRecordHeader();
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
class TESRegion : public TESForm
{
  public:
    char pad[0x20];
    TESWorldSpace* world;
    void AssignWorldSpace(TESWorldSpace*);
};
class TESFile;
class TESForm;
class TESDataHandler
{
  public:
    bool LoadDescriptionForForm();
public:
    static bool LoadForm(::TESForm *, ::TESFile *);
};
class TESWorldSpace
{
  public:
    enum PARENT_USE_FLAG
    {
        USE_LAND = 1
    };
    char pad0[0x30];
    NiTPointerMap<unsigned int, TESObjectREFR*>* cellMap;
    void* unk34;
    char pad38[0x4];
    BGSTerrainManager* terrain;
    void* unk40;
    void* unk44;
    void* unk48;
    unsigned char flags4C;
    char pad4D[1];
    unsigned short field4E;
    char pad50[0x20];
    TESWorldSpace* parent;
    void* unk74;
    void* unk78;
    float unk7c;
    char pad80[0x10];
    float unk90;
    float unk94;
    float unk98;
    void* unk9c;
    char pada0[0x20];
    BSStringT<char> mapName;
    char padC1[7];
    float fC8;
    float fCC;
    unsigned int fieldD0;
    bool SetDateTimeText(const char*);
    BGSTerrainManager* GetWorldTerrainManager();
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG);
    TESObjectCELL* GetCellByKey(unsigned int);
    void AddPersistentReference(TESObjectREFR*);
    static bool IsFormIDOwnedByFile(unsigned int, TESFile*);
    void ClearWorldSpaceReferences();
    TESObjectCELL* GetCellAtGridPosition(int, int);
    void FUN_00584150(float);
    void FUN_00586110(float);
    void FUN_00586130(float);
    bool GetSmallWorld();
    bool IsFlag4C20Set();
    void SetParent(TESWorldSpace*);
    void SetFieldD0(unsigned int);
    void FUN_00588270(BSSimpleArray<TESObjectREFR*, 1024>&);
};
class Tile;
class InterfaceManager
{
  public:
    char pad[0x9C];
    Tile* pTile;
    Tile* FUN_00586150();
};
#endif
class TESSound;
class TESQuest;
class TESEffectShader;
class BGSAcousticSpace
{
  public:
};
class TESSound;
class TESObjectACTI
{
  public:
    void SetLoopingSound(TESSound*);
public:
    void SetActivateSound(::TESSound *);
};
class EffectSetting
{
  public:
};
class TESFullName
{
  public:
    void SetFullName(const char*);
};
extern float DAT_01031920;
