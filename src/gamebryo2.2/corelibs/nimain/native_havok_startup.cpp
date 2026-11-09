#include "fnv/tls.h"
#include "havok/PhysicsMemory.h"
#include "havok/hkBaseSystem.h"
#include "fnv/symbols_0084c000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_01272000.h"

extern uintptr_t DAT_01268418;

#include <cstdlib>
#include <exception>

// @fnv 0x00cbbfb0
void FUN_00cbbfb0(uintptr_t a1)
{
    DAT_01268418 = a1;
}

class AutoMemContextC68
{
  public:
    AutoMemContextC68(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextC68()
    {
        ::g_tlsBlock.memoryContext = m_uiPrevious;
    }
    unsigned int m_uiPrevious;
};

extern char g_acStackBufferC68[0x60000];

namespace
{
void HavokErrorCallback(const char* message, void*)
{
    ::FUN_0084cbd0("%s", message);
}
}


// Stage native base owners, then stop before the unmigrated game singleton graph.
// @fnv 0x00c68230
void InitHavokPhysics()
{
    AutoMemContextC68 kContext(0x10);
    bool bNeedsInit = !havok::base::IsInitialized();
    if (bNeedsInit)
    {
        hkMemoryRouter* pkRouter = g_havokPhysicsMemory.Initialize(g_acStackBufferC68, sizeof(g_acStackBufferC68));
        if (!pkRouter)
            std::abort();
        ::FUN_00cbbfb0(reinterpret_cast<uintptr_t>(g_havokPhysicsMemory.GetSystem()));

        try
        {
            if (::fnv_00cbbb10::FUN_00cbbb10(pkRouter, HavokErrorCallback, nullptr) != 0)
            {
                if (!g_havokPhysicsMemory.Shutdown())
                    std::terminate();
                ::FUN_00cbbfb0(0);
                std::abort();
            }
        }
        catch (...)
        {
            if (!g_havokPhysicsMemory.Shutdown())
                std::terminate();
            ::FUN_00cbbfb0(0);
            throw;
        }
    }

    // Legacy singleton and diagnostic consumers still need native receiver migration.
    // Do not publish a game-ready physics system with that graph incomplete.
    HavokErrorCallback("Havok native base owners are ready, but the legacy singleton graph is not migrated.\n", nullptr);
    ShutdownIfInitialized();
    if (!g_havokPhysicsMemory.Shutdown())
        std::terminate();
    ::FUN_00cbbfb0(0);
    std::abort();
}
