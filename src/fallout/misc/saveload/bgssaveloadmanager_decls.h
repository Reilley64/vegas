// fallout/misc/saveload/bgssaveloadmanager_decls.h: declares TaskQueueInterface, TESFile, BGSLoadGameBuffer, SaveLoadHeader, BGSSaveLoadGame and more
#ifndef BGSSAVELOADMANAGER_DECLS_H
#define BGSSAVELOADMANAGER_DECLS_H

#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BSAudioManager.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00525430_Class.h"
#include "fnv/decl/FUN_00527fc0_cls.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_006ebcd0_shell.h"
#include "fnv/decl/FUN_006ebcf0_cls.h"
#include "fnv/decl/FUN_00714d70.h"
#include "fnv/decl/FUN_0084cc40_shell.h"
#include "fnv/decl/FUN_0084ff90_shell.h"
#include "fnv/decl/FUN_00850030_shell.h"
#include "fnv/decl/FUN_0086f670_shell.h"
#include "fnv/decl/FUN_009ca410_shell.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/FUN_00ad7230_shell.h"
#include "fnv/decl/FUN_00ad8740_shell.h"
#include "fnv/decl/FadeAttachedTES.h"
#include "fnv/decl/ReconstructSession.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/fnv_00448420__ModelLoader.h"
#include "fnv/decl/fnv_00448620__FUN_00448620_cls.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006c3640__C006c3640.h"
#include "fnv/decl/fnv_006c39c0__FUN_006c39c0_shell.h"
#include "fnv/decl/fnv_0086f6a0__FUN_0086f6a0_shell.h"
#include "fnv/decl/fnv_00877430__FUN_00877430_shell.h"
#include "fnv/decl/fnv_00977660__FUN_00977660_shell.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_005a9000.h"
#include "fnv/symbols_005ae000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_00850000.h"
#include "fnv/symbols_0086d000.h"
#include "fnv/symbols_0093a000.h"
#include "fnv/symbols_00a25000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0105d000.h"
#include "fnv/symbols_011a2000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
class TESFile
{
  public:
};
char* __cdecl FUN_00c3bc20();
extern const char g_011dece4_arg1[];
extern const char DAT_01082d70[];
extern const char DAT_01082d88[];
extern const char DAT_01082d94[];
extern const char DAT_01082da0[];
extern const char DAT_01082dac[];
extern const char DAT_01082dc4[];
extern int(* DAT_00fdf0c4)(const char*, const char*, int, const char*);
extern int(* DAT_00fdf274)(void*, int, void*, unsigned int, char*);
extern int(* DAT_00fdf0b8)(const char*, void*);
extern int(__cdecl* DAT_00fdf0d4)(char*);
extern int(* DAT_00fdf1b8)(const char*, const char*, int);

class SaveLoadFile;
class BGSLoadGameBuffer
{
  public:
};
class SaveLoadHeader
{
  public:
};
class BGSSaveLoadGame
{
  public:
};
class InterfaceManager
{
  public:
};
class Interface
{
  public:
    static bool IsInterfaceActive();
};
union SETTING_VALUE
{
    bool b;
    float f;
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
    SETTING_VALUE* Float();
};
class SettingT_GameSettingCollection_
{
  public:
};
class GlobalObject_0040c150
{
};
class GlobalObject_0045cf30
{
};
extern GlobalObject_0040c150 g_011d2100;
extern GlobalObject_0045cf30 g_011de248;
class OSGlobals;
class Main
{
  public:
};
void __cdecl DumpTextAndOpen(const char*);

enum FADER_ENUM
{
    FADER_NONE = 0
};
enum FADER_ENUM;
class FaderManager
{
  public:
    bool HasFader(FADER_ENUM);
public:
    void AddFader(::FADER_ENUM, float, bool);
};
class BGSSaveLoadManager;

class ChallengeManager
{
  public:
    static void CheckCompletedChallenges();
};
class ModelLoader
{
  public:
};
class TES
{
  public:
    void** m_ppVirtualMethodTable;
    void* pGridDistantArray;
    void* pGridCellArray;
};
class ActorMover
{
  public:
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};
class GridCellArray
{
  public:
    void ReleaseGridCells();
};
class VATS
{
  public:
    void Update(int, bool);
public:
    void FUN_009c8950(bool, bool);
};
class GlobalObject_009c6a30
{
};
class NiPoint3;
struct NiPoint3;
class BGSTerrainManager
{
  public:
public:
    unsigned int GetMinLevel();
public:
    void FUN_006fca90(const ::NiPoint3 &, int);
};
class TESWorldSpace
{
  public:
    BGSTerrainManager* GetWorldTerrainManager();
};
class TESObjectREFR
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPos() const;
};
class PlayerCharacter : public TESObjectREFR
{
  public:
};
class BGSSaveLoadUI
{
  public:
    void FUN_007d0bd0(bool);
    void FUN_007d0bb0();
};
class GameSettingCollection
{
  public:
};
class LoadingMenu
{
  public:
    static void UpdateLoadingScreenThread();
};
class BSAudio
{
  public:
    void Update(bool);
};
class GlobalObject_0096d020
{
  public:
};
class NavMeshObstacleManager
{
  public:
};
class PathManager
{
  public:
    bool CallMemberFunction();
};

class TESQueuedCellManager
{
  public:
};
void __cdecl FUN_005b4940();
class HUDMainMenu
{
  public:
};
class InventoryStackRecord
{
  public:
};
class NiPoint3Interpolator
{
  public:
    void CreateObject(int, bool);
};
class TimeGlobal;
class GameTimerRecord
{
  public:
};
class ScriptLocals
{
  public:
    void ProcessPendingTasks();
};

class DownloadableContentManager
{
  public:
    const char* IsDLCAvailable();
};
extern GlobalObject_0040c150 g_011d3d0c;
extern const char DAT_0107fb78[];
extern const char DAT_0107faf8[];
class SaveLoadHeader;
class BGSSaveLoadManager
{
  public:
    unsigned char prefix[15];
    unsigned char m_cQueuedSaveLoad;
    unsigned char m_cAutosaveCountdown;
    unsigned char cQueuedQuicksave;
    unsigned char reserved12[0x2];
    char* unk14;
    int unk18;
    unsigned char pad1c[0x4];
    SaveLoadFile* m_pSaveFile;
    bool m_bSaveOperationActive;
    bool m_bLoadOperationPending;
    bool m_bLoadingGame;
    bool LoadGame(const char*, int, bool, bool);
    bool CanLoadSaveGame(SaveLoadFile*);
    void FinishLoadingGame();
    void ProcessQueuedLoads();
    void ProcessQueuedSaveLoad();
    void FUN_00850a90();
    static void GetSaveDirectory(char* output);
    bool IsQuickSaveFileName(const char* name);
    bool IsAutoSaveFileName(const char* name);
    void SanitizeSaveFileName(char* name);
    void GetFNVVersionInfo(char* output, unsigned int capacity);
    bool CanSave(bool);
    bool IsSaveFileNameDefault(const char*);
    bool IsSaveFileNameLegacyAutosave(const char*);
    bool IsSaveFileNameCustom(const char*);
    void UpdateSaveTimestamp();
    static void BuildAutosaveName(char*);
public:
    void FUN_00850100(::SaveLoadHeader *, int);
};
extern const char DAT_0107fae0[];
extern GlobalObject_0040c150 g_011d4060;
unsigned int FUN_00702440();
unsigned int FUN_008510e0();
#endif
