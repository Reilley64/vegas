// bssystem/bsfilecache.cpp: BSFileCache, StandIn (15 functions)

#include <windows.h>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
#include "bsfilecache.h"

// @fnv 0x00b00f20
BSFileCache::BSFileCache()
{
    m_uiCacheIndex = 0;
    m_pFileCacheArray = 0;
    m_pCacheSyncObject = 0;
    m_eCacheState = FILE_CACHING_IN_PROGRESS;
    m_pActiveFileCache = 0;
    m_uiCacheEntryCount = 0;
    m_uiCachedBytes = 0;
    m_uiCacheByteCount = 0;
    m_uiCacheCapacity = 0;
    m_iCacheEntryIndex = -1;
    m_uiCacheLimit = 0;
    m_uiCacheRequestCount = 0;
    m_uiReferenceCount = 1;
    m_uiCacheFlags = 0;
    m_iCacheCount = 0;
    m_eDVDLayer = DVD_LAYER_FRONT;
    m_bCacheEnabled = false;
    m_bCacheReadPending = false;
    m_bCacheInitialized = false;
    m_iFileSize = 0;
    m_uiCacheOffset = 0;
    m_uiCacheBufferCount = 2;
    m_pfnCacheStatus = 0;
    m_pfnCacheProgress = 0;
}

struct FUN_00b011b0_shell : public BSFileCache
{
    bool FUN_00b011b0(const char*);
};

struct VT_00b011b0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(const char*);
};
struct ST_00b011b0
{
};
struct FUN_00b01020
{
    virtual ~FUN_00b01020();
};
// @fnv 0x00b01020
FUN_00b01020::~FUN_00b01020()
{}

struct VBase
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(int, int, int, int);
};
struct Unk00b01040 : VBase
{
    char pad04[0x34];
    int m_i38;
    void CallVirtualWithField38();
};
// Calls the virtual f11 on this with arguments 0, m_i38, 1 and 0.
// @fnv 0x00b01040
void Unk00b01040::CallVirtualWithField38()
{
    f11(0, m_i38, 1, 0);
}

struct FUN_00b01070_Class
{
    void FUN_00b01070();
};
// @fnv 0x00b01070
void FUN_00b01070_Class::FUN_00b01070()
{}

struct E00b011e0
{
    int pad0;
    int pad1;
    int pad2;
    int v;
};
struct M00b011e0
{
    int pad;
    E00b011e0** arr;
};
struct C00b011e0
{
    char _0[0x24];
    int cnt;
    char _1[0x28];
    M00b011e0* mid;
    bool FUN_00b011e0(int idx);
};
// Calls v5 on the argument, then forwards the result to FUN_00b011e0 and returns its bool result.
// @fnv 0x00b011b0
bool FUN_00b011b0_shell::FUN_00b011b0(const char* a)
{
    return reinterpret_cast<::C00b011e0 *>((((ST_00b011b0*)this)))->FUN_00b011e0(((VT_00b011b0*)this)->v5(a));
}
// Returns true when idx is within cnt and the entry at mid->arr[idx] has v equal to 2; otherwise false.
// @fnv 0x00b011e0
bool C00b011e0::FUN_00b011e0(int aiIndex)
{
    if (aiIndex < 0 || aiIndex >= cnt)
        return false;
    return mid->arr[aiIndex]->v == 2;
}

extern int DAT_011ad028;
extern int DAT_011ad02c;

struct FUN_00b012f0_shell
{
    void FUN_00b012f0(int param_1, int param_2);
};

// @fnv 0x00b012f0
void FUN_00b012f0_shell::FUN_00b012f0(int aiValue1, int aiValue2)
{
    DAT_011ad028 = aiValue1;
    DAT_011ad02c = aiValue2;
}

struct FUN_00b01020_Holder
{
    void FUN_00b01020();
};
struct MemoryManager
{
};
struct FUN_00b01310_shell
{
    void* FUN_00b01310(unsigned int flags);
};
// Calls FUN_00b01020 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00b01310
void* FUN_00b01310_shell::FUN_00b01310(unsigned int flags)
{
    reinterpret_cast<::FUN_00b01020 *>((((FUN_00b01020_Holder*)this)))->FUN_00b01020::~FUN_00b01020();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00b01340_Shell
{
    int FUN_00b01340(const char* apFileList, unsigned int aiCurrentPriority);
};
// @fnv 0x00b01340
int FUN_00b01340_Shell::FUN_00b01340(const char* apFileList, unsigned int aiCurrentPriority)
{
    return 0;
}

struct FUN_00b01350_shell
{
    bool FUN_00b01350(void* apCachedFile);
};

// @fnv 0x00b01350
bool FUN_00b01350_shell::FUN_00b01350(void* apCachedFile)
{
    return false;
}

struct FUN_00b01360_Cls
{
    void FUN_00b01360(int a, int b, int c, int d);
};
// @fnv 0x00b01360
void FUN_00b01360_Cls::FUN_00b01360(int a, int b, int c, int d)
{}

struct StandIn
{
    char pad00[0x60];
    void* m_p60;
    void ClearPointerAt60();
};
// @fnv 0x00b01370
void StandIn::ClearPointerAt60()
{
    m_p60 = 0;
}


class B01130Task
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    bool m_bTaskActive;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_iFadeIndex;
    void* m_pvThread;

    void FUN_00b01130();
};

// @fnv 0x00b01130
void B01130Task::FUN_00b01130()
{
    if (!m_pvThread)
        return;
    if (m_iFadeIndex == 1 || m_iFadeIndex == 2)
        m_iFadeIndex = 3;
    if ((bool)((m_iFadeIndex == 2 || m_iFadeIndex == 3) ? 1 : 0))
    {
        while (!m_bTaskActive)
            Sleep(10);
    }
}

struct S : public BSFileCache
{
    void WaitWhilePaused();
};
// @fnv 0x00b01080
void S::WaitWhilePaused()
{
    while ((bool)((m_eCacheState == FILE_CACHING_PAUSED || m_eCacheState == FILE_CACHING_FORCE_PAUSED) ? 1 : 0))
    {
        m_bCacheInitialized = true;
        Sleep(50);
    }
    m_bCacheInitialized = false;
}

struct FUN_00b010d0_cls : public BSFileCache
{
    void FUN_00b010d0();
};

// @fnv 0x00b010d0
void FUN_00b010d0_cls::FUN_00b010d0()
{
    if (m_eCacheState == FILE_CACHING_IN_PROGRESS)
    {
        m_eCacheState = FILE_CACHING_PAUSED;
    }
    if ((bool)((m_eCacheState == FILE_CACHING_PAUSED || m_eCacheState == FILE_CACHING_FORCE_PAUSED) ? 1 : 0))
    {
        while (m_bCacheInitialized == 0)
        {
            Sleep(10);
        }
    }
}

inline bool IsCacheFinished(BSFileCache* m_pAabbCache)
{
    return m_pAabbCache->m_eCacheState == FILE_CACHING_FINISHED;
}

inline bool IsCachePaused(BSFileCache* m_pAabbCache)
{
    return m_pAabbCache->m_eCacheState == FILE_CACHING_PAUSED ||
           m_pAabbCache->m_eCacheState == FILE_CACHING_FORCE_PAUSED;
}

struct Cls00b01220
{
    unsigned char unk00;
    Cls00b01220* FUN_00b01220(int unused);
};

// @fnv 0x00b01220
Cls00b01220* Cls00b01220::FUN_00b01220(int unused)
{
    BSFileCache* pCache1 = ((::BSFileCache *)&(::BSFileCache::GetRandomGenerator()));
    if (!IsCacheFinished(pCache1))
    {
        BSFileCache* pCache2 = ((::BSFileCache *)&(::BSFileCache::GetRandomGenerator()));
        this->unk00 = IsCachePaused(pCache2);

        BSFileCache* pCache3 = ((::BSFileCache *)&(::BSFileCache::GetRandomGenerator()));
        if (pCache3->m_eCacheState == FILE_CACHING_IN_PROGRESS)
        {
            pCache3->m_eCacheState = FILE_CACHING_PAUSED;
        }
    }

    return this;
}

class FUN_00b012a0_cls
{
  public:
    unsigned char m_00;
    void FUN_00b012a0();
};

// @fnv 0x00b012a0
void FUN_00b012a0_cls::FUN_00b012a0()
{
    BSFileCache* cache = ((::BSFileCache *)&(::BSFileCache::GetRandomGenerator()));
    if (!IsCacheFinished(cache) && m_00 == 0)
    {
        BSFileCache* cache2 = ((::BSFileCache *)&(::BSFileCache::GetRandomGenerator()));
        if (cache2->m_eCacheState == FILE_CACHING_PAUSED)
            cache2->m_eCacheState = FILE_CACHING_IN_PROGRESS;
    }
}

#include "generated/data/bssystem/bsfilecache.inc"
