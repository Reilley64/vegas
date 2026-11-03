// bssystemutilities/console/bsawardssystemutility_console.cpp: IdleSystem, DownloadableContentManager (12 functions)

#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Node185.h"
#include "fnv/decl/TemplateList_00a0ae70.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f7000.h"
#include "bsawardssystemutility_console_decls.h"

// @fnv 0x00af26c0
DownloadableContentManager& DownloadableContentManager::GetRandomGenerator()
{
    if (!DAT_011f7244)
        DAT_011f7244 = new DownloadableContentManager;
    return *DAT_011f7244;
}

// Returns the singleton instance, allocating a new one if DAT_011f7178 is null.
// @fnv 0x00af22d0
IdleSystem& IdleSystem::GetRandomGenerator()
{
    if (!DAT_011f7178)
        DAT_011f7178 = new IdleSystem;
    return *DAT_011f7178;
}

// @fnv 0x00af2d20
bool IdleSystem::Initialize()
{
    return true;
}

// @fnv 0x00af2480
void IdleSystem::Idle()
{
    if (!m_kNode.IsEmpty())
    {
        BSSimpleList<unsigned char*>* pListIter;
        pListIter = &m_kNode;
        {
            int iAwardId;
            while (pListIter && !pListIter->IsEmpty())
            {
                AwardData* pAwardData = (AwardData*)pListIter->m_item;
                iAwardId = pAwardData->id;
                delete pAwardData;
                if (iAwardId > 100)
                {
                    ::FUN_005b5e40();
                    continue;
                }
                if (SteamUserStats())
                {
                    char name[4];
                    ::FUN_00406d00(name, 4, "A%02d", iAwardId);
                    name[3] = 0;
                    SteamUserStats()->SetAchievement(name);
                }
                pListIter = pListIter->m_pkNext;
            }
        }
        if (SteamUserStats())
            SteamUserStats()->StoreStats();
        reinterpret_cast<::Node185 *>(&(m_kNode))->FUN_00ae83e0();
    }
}

namespace std {
// Returns a reference to a function-local static object, creating it on first call.
// @fnv 0x00af2640
template <class T> T& _Immortalize()
{
    static T object;
    return object;
}
template StandardLibrarySingletonObject& _Immortalize<StandardLibrarySingletonObject>();
}

// Deletes the global object pointed to by DAT_011f7178 and resets the pointer to null if it is set.
// @fnv 0x00af2370
void IdleSystem::Shutdown()
{
    if (DAT_011f7178)
    {
        delete DAT_011f7178;
        DAT_011f7178 = 0;
    }
}

// Default constructor for the class; does nothing.
// @fnv 0x00af23d0
IdleSystem::IdleSystem()
{}

// @fnv 0x00af2400
IdleSystem::~IdleSystem()
{}

// @fnv 0x00af2360
void IdleSystem::Startup()
{
    GetRandomGenerator();
}

struct FUN_00af2470_class
{
    bool FUN_00af2470();
};
// @fnv 0x00af2470
bool FUN_00af2470_class::FUN_00af2470()
{
    return false;
}

struct FUN_00af2420_class
{
    bool FUN_00af2420(int value);
};

// @fnv 0x00af2420
bool FUN_00af2420_class::FUN_00af2420(int value)
{
    void* q = reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(4);
    void *p = q ? *(void**)q = (void*)value, q : 0;
    char buf[8];
    reinterpret_cast<::TemplateList_00a0ae70 *>(this)->AddTail((::TileTemplate_00a0ae70 **)(void **)(&p));
    return true;
}

struct FUN_00af2f80_class
{
    char _pad[12];
    char _buf[32];
    bool CopyBufferIfNotEmpty(char*);
};
// @fnv 0x00af2f80
bool FUN_00af2f80_class::CopyBufferIfNotEmpty(char* pDest)
{
    if (::std::strlen(_buf) > 0)
    {
        fnv::crt::strcpy_s(pDest, 32, _buf);
        return true;
    }
    return false;
}

#include "generated/data/bssystemutilities/console/bsawardssystemutility_console.inc"
