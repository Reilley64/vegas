#include <cstddef>
// bssystemutilities/console/bsnetworksystemutility_console_decls.h: declares NetworkSystemUtility, MemoryManager

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
class NetworkSystemUtility
{
  public:
    enum NetEvent
    {
        NetworkStatusChanged = 0
    };
    bool m_bSteamRunning;
    void(__cdecl* m_callback)(NetEvent, unsigned int);
    void RegisterCallback(void(__cdecl* callback)(NetEvent, unsigned int));
    static NetworkSystemUtility& GetRandomGenerator();
    NetworkSystemUtility();
    static void* operator new(std::size_t size);
    static void operator delete(void* pointer);
};
class MemoryManager
{
  public:
};
extern NetworkSystemUtility* DAT_011f7270;
__forceinline void* NetworkSystemUtility::operator new(std::size_t size)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
}
__forceinline void NetworkSystemUtility::operator delete(void* pointer)
{
    reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pointer);
}
