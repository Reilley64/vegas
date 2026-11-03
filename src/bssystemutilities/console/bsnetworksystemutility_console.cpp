// bssystemutilities/console/bsnetworksystemutility_console.cpp: NetworkSystemUtility (4 functions)

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "bsnetworksystemutility_console_decls.h"
// @fnv 0x00af2d70
void NetworkSystemUtility::RegisterCallback(void(__cdecl* callback)(NetEvent, unsigned int))
{
    m_callback = callback;
    if (callback)
        callback(NetworkStatusChanged, m_bSteamRunning != 0);
}
// @fnv 0x00af2c90
NetworkSystemUtility& NetworkSystemUtility::GetRandomGenerator()
{
    if (!DAT_011f7270)
        DAT_011f7270 = new NetworkSystemUtility;
    return *DAT_011f7270;
}

// The two fields FUN_00af2d40 clears.
struct FUN_00af2d40_View
{
    bool m_bFlag;
    void* m_pValue;
};

// @fnv 0x00af2d40
void* FUN_00af2d40(void* pThis)
{
    ((FUN_00af2d40_View*)pThis)->m_bFlag = false;
    ((FUN_00af2d40_View*)pThis)->m_pValue = 0;
    return pThis;
}

struct FUN_00af2d60_Class
{
    void FUN_00af2d60();
};
// @fnv 0x00af2d60
void FUN_00af2d60_Class::FUN_00af2d60()
{}

#include "generated/data/bssystemutilities/console/bsnetworksystemutility_console.inc"
