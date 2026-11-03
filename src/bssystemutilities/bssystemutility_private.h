#ifndef BSSYSTEMUTILITY_PRIVATE_H
#define BSSYSTEMUTILITY_PRIVATE_H


#include "runtime/crt.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_00af2db0_cls.h"
#include "fnv/decl/FnvEmptyThiscall_Class.h"
#include "fnv/symbols_00af2000.h"
class CountingSemaphore
{
  public:
    volatile int iCount;
    void* hSemaphore;
    int m_iMaximumCount;
};

class BSSystemUtility
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    unsigned char storage[0x94];
    void Update();
    void Initialize(const char*, const char*, unsigned int);
    void Destroy();
    void FUN_00af3340();
};

class IdleSystem
{
  public:
    static IdleSystem& GetRandomGenerator();
    void Idle();
    static void Initialize();
public:
    static void Startup();
public:
    static void Shutdown();
};

class NetworkSystemUtility
{
  public:
    static NetworkSystemUtility& GetRandomGenerator();
};

class DownloadableContentManager
{
  public:
    static DownloadableContentManager& GetRandomGenerator();
};

class FNVVTableSlot4
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
};

class FNVVTableSlot8
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
};

class FNVVTableSlot8Args
{
  public:
    virtual void vfn_00();
    virtual void vfn_04(const char*, unsigned int);
    virtual void vfn_08();
};

void FUN_00af2760();
void FUN_00af2d30();
FNVVTableSlot8* FUN_00af3850();
FNVVTableSlot8Args* GetStaticSlot();
FNVVTableSlot8* FUN_00af2e50();
FNVVTableSlot8* GetVTableSlot8();
FNVVTableSlot8* FUN_00af34f0();
FNVVTableSlot8* GetInitObj();

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

#endif