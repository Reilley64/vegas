#ifndef FNV_BSAWARDSSYSTEMUTILITY_CONSOLE_DECLS_H
#define FNV_BSAWARDSSYSTEMUTILITY_CONSOLE_DECLS_H


#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Node185.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f7000.h"
#include "MemoryManager.h"

class ContentMountRecord;
class DownloadableContentEntry;
class DownloadableContentInfo;

class DownloadableContentManager
{
  public:
    unsigned int m_uiContentCount;
    DownloadableContentEntry* m_pFirstService;
    DownloadableContentInfo* m_pSecondService;
    BSSimpleList<ContentMountRecord*> m_kContentEntries;
    BSSimpleList<ContentMountRecord*> m_kMountedPackages;
    BSSimpleList<char*> m_kMountedPackageNames;

    DownloadableContentManager();
    static DownloadableContentManager& GetRandomGenerator();
    static __forceinline void* operator new(unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
    static __forceinline void operator delete(void* pointer)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pointer);
    }
};

class IdleSystem
{
  public:
    BSSimpleList<unsigned char*> m_kNode;

    IdleSystem();
    ~IdleSystem();
    void Idle();
    static void Shutdown();
    static void Startup();
    static IdleSystem& GetRandomGenerator();
    static bool Initialize();
    static __forceinline void* operator new(unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
    static __forceinline void operator delete(void* pointer)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pointer);
    }
};


extern IdleSystem* DAT_011f7178;

template <> __forceinline bool BSSimpleList<unsigned char*>::IsEmpty()
{
    return !m_pkNext && !m_item;
}
template <> __forceinline BSSimpleList<unsigned char*>::BSSimpleList()
{
    m_item = 0;
    m_pkNext = 0;
}
template <> __forceinline BSSimpleList<unsigned char*>::~BSSimpleList()
{
    int padding[3];
    reinterpret_cast<::Node185 *>(this)->FUN_00ae83e0();
}
class SteamUserStats
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual bool SetAchievement(const char*);
    virtual void vfn_20();
    virtual void vfn_24();
    virtual bool StoreStats();
};
extern "C" __declspec(dllimport) SteamUserStats* __cdecl SteamUserStats();
struct AwardData
{
    int id;
    static __forceinline void operator delete(void* pointer)
    {
        int padding[3];
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pointer);
    }
};
namespace std {
class StandardLibrarySingletonObject
{
  public:
    StandardLibrarySingletonObject();
    ~StandardLibrarySingletonObject();
};
}
#endif
