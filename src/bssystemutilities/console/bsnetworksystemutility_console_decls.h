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
};
class MemoryManager
{
  public:
};
extern NetworkSystemUtility* DAT_011f7270;
