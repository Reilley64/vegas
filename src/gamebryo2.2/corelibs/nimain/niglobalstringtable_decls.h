// gamebryo2.2/corelibs/nimain/niglobalstringtable_decls.h: declares NiGlobalStringTable, NiPlaybackStat, NiPlaybackTimestamp, NiPlaybackManager, NiPlaybackFile
#ifndef NIGLOBALSTRINGTABLE_DECLS_H
#define NIGLOBALSTRINGTABLE_DECLS_H

#include <string.h>
#include "fnv/decl/EC2DF0Registry.h"
#include "fnv/decl/MovieSignalState.h"
#include "fnv/decl/StringTable169.h"
#include "fnv/decl/ThreadedTable.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
class NiGlobalStringTable
{
  public:
    void AddString();
    static char* AddString(const char*);
    unsigned char padding[0x68];
    unsigned m_uiLockCount;
};
extern "C" unsigned long __readfsdword(unsigned long);
#pragma intrinsic(__readfsdword)
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
struct NiPlaybackStat
{
    int pad[5];
    int timestamp;
    int rest[6];
};
struct NiPlaybackTimestamp
{
    int pad;
    int timestamp;
};
class NiPlaybackManager
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual unsigned vfn_3c();
};
class NiPlaybackFile
{
  public:
    bool FindString(const char*, bool, bool, bool);
    void* handle;
    char pad[28];
    unsigned state;
};
char* FUN_00ec6380(char*, const char*);
int FUN_00ec923c(const char*, NiPlaybackStat*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall BinkOpen(const char*, unsigned);
#endif

extern "C" void* fnv_zlib_memcpy(void*, const void*, unsigned);
