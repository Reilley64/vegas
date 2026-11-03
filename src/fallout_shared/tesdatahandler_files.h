// fallout_shared/tesdatahandler_files.h: declares NiFile, FILETIME, TESRecordHeader, BSFile, TESFile and more
#ifndef FNV_TESDATAHANDLER_FILES_H
#define FNV_TESDATAHANDLER_FILES_H

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_00471110_Class.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00471a10_shell.h"
#include "fnv/decl/FUN_00471ad0_shell.h"
#include "fnv/decl/FUN_00471af0_shell.h"
#include "fnv/decl/FUN_00471e60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00473880_Class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00867890_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MessageHandler.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S69570.h"
#include "fnv/decl/fnv_00471a60__FUN_00471a60.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00473000.h"
#include "fnv/symbols_005fd000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY = 0,
        WRITE_ONLY = 1
    };
};
struct FILETIME
{
    unsigned int low, high;
};
struct WIN32_FIND_DATAA
{
    unsigned int attributes;
    FILETIME created, accessed, written;
    unsigned int sizeHigh, sizeLow, reserved0, reserved1;
    char name[260];
    char alternate[14];
};
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void*, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindClose(void*);
struct TESRecordHeader
{
    unsigned int type, size, flags, formID;
};
class BSFile
{
  public:
    BSFile(const char*, NiFile::OpenMode, unsigned int, bool);
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void Seek(int, int);
    virtual void vfn_24();
    virtual unsigned int GetSize();
    bool IsOpen();
    unsigned char fileData[0x154];
};
class TESFile
{
  public:
    unsigned int error;
    unsigned char data004[12];
    BSFile* stream;
    unsigned char data014[12];
    char fileName[260];
    char directory[260];
    unsigned int data228;
    unsigned int bufferSize;
    unsigned char data230[40];
    unsigned int currentChunk;
    unsigned int data25c;
    unsigned int fileSize;
    unsigned char data264[56];
    WIN32_FIND_DATAA fileData;
    unsigned char data3dc[12];
    unsigned int fileFlags;
    void SetGroupMode(bool);
    unsigned char GetFileCompileIndex();
    TESRecordHeader* GetRecordHeader();
    bool IsEndianConversionRequired();
    ~TESFile();
    TESFile* GetParentTESFile();
    int ReadTESInfo();
    bool GetIsChecked();
    void SetChecked(bool);
    bool IsMasterFile();
    bool IsValidFileVersion();
    bool GetActive();
    void SetCompileIndex(unsigned char);
    bool OpenTESFile(NiFile::OpenMode, bool);
    unsigned int GetFieldAt3E0();
    bool GetByteAt428();
public:
    bool NextChunk();
};
class CompileWarningSetting
{
  public:
    const char* GetText();
};
extern CompileWarningSetting DAT_011c4024, DAT_011c4048;
extern unsigned int DAT_011c3f24, DAT_011c3f28;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
class Archive;
class ArchiveManager
{
  public:
    static Archive* PluginFile(const char*, unsigned short, bool);
};
Archive* FindArchiveByName(const char*);
class TESTopic : public TESForm
{
  public:
    TESTopic(int);
    unsigned char topicData[0x30];
    static void RemoveQuestInfo(TESQuest*);
    static void ReorderTopics(bool, BSSimpleList<TESTopic*>*);
};
class PlayerCharacter
{
  public:
    BSSimpleList<TESTopic*>* GetSelfOffset6A8();
    class PlayerBase* FUN_00464e10();
public:
    bool IsSleepingOrResting();
};
class PlayerBase
{
  public:
    void FUN_008d50e0();
};
class IdleAnimationManager
{
  public:
    void InitializeIdleAnimations();
};
void FUN_00408df0();

class Calendar
{
  public:
    void ResetCachedValues();
};
class TESDataHandler;

class TESTopic;
template <class> class BSSimpleList;
class TESTopicInfo : public TESForm
{
  public:
    TESTopicInfo(int);
    unsigned char infoData[0x38];
public:
    ::BSSimpleList< ::TESTopic *> *GetAddTopicList();
};
class InventoryChanges;
class ExtraDataList
{
  public:
public:
    ::InventoryChanges *GetContainerChangeData();
public:
    void RemoveExtraDataType0x15();
};
class BGSSaveLoadGame
{
  public:
};
class TESSaveLoadGame
{
  public:
};
class ActorDeletionQueue
{
  public:
    void FUN_0096d470(MobileObject*, int);
};
class GameSettingCollection
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28(TESFile*, const char*);
};
class NavMeshInfoMap : public TESForm
{
  public:
    NavMeshInfoMap();
    unsigned char mapData[0x28];
};
template <class T> class NiPointer
{
    T* pointer;

  public:
    NiPointer(T*);
    NiPointer(const NiPointer&);
    ~NiPointer();
    T* Get();
};
class NavMeshCollection
{
  public:
    NavMeshCollection();
    unsigned int data[4];
    void AppendNavMesh(NiPointer<NavMesh>);
};
template <int N> struct EndianSizeTag
{
};
struct FormTypeDescription
{
    const char* name;
    unsigned int data[2];
};
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)


int strcat_s(char*, unsigned int, const char*);
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char*, const char*);
extern "C" __declspec(dllimport) char* __stdcall lstrcatA(char*, const char*);
char* strchr(char*, int);
int FUN_00ec4835(const void*, const void*, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" int* _errno();

extern "C" int _mbsnicmp(const unsigned char*, const unsigned char*, unsigned int);
extern "C" int _mbsicmp(const unsigned char*, const unsigned char*);
class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    unsigned int thread, count;
public:
    void FUN_0040fba0();
};
class BSFlags
{
  public:
    unsigned int flags;
    void Clear(unsigned int);
};

class BSThread
{
  public:
    BSThread();
    virtual ~BSThread();
    virtual void Run();
    unsigned char threadData[0x2c];
};
class FAMThread : public BSThread
{
  public:
    FAMThread();
    virtual void Run();
    void* event;
    RecursiveSpinLock lock;
    unsigned int state;
    void* work;
    void* result;
    unsigned int threadID;
};
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);

#endif
