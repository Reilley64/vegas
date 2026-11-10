// gamebryo2.2/corelibs/nimain/niglobalstringtable.cpp: NiGlobalStringTable, NiPlaybackFile (2 functions)

#include <cstdint>
#include <cstring>
#include "fnv/decl/EC2DF0Registry.h"
#include "fnv/decl/MovieSignalState.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
#include "niglobalstringtable_decls.h"

#pragma optimize("", off)
// @fnv 0x004f31b0
void NiGlobalStringTable::AddString()
{
    ++m_uiLockCount;
}

#pragma optimize("", off)

#pragma function(strlen, strcpy)
// Checks a non-empty name, resolves its path, opens the Bink file with preload/force flags, warns on failure, and returns whether it opened.
// @fnv 0x00ec0ac0
bool NiPlaybackFile::FindString(const char* name, bool silent, bool preload, bool force)
{

    struct Local
    {
        unsigned uiCurrentThreadID;
        int* piTimestamp;
        fnv::crt::FileStatus kStat;
        unsigned uiFlags;
        char pad[2];
        bool bSuccess;
        bool bOtherThread;
    } local;
    char acPath[260];

    if (!strlen(name))
        return false;
    if (!reinterpret_cast<::EC2DF0Registry *>(((*reinterpret_cast<::NiPlaybackManager * *>(&::DAT_0126fac4))))->GetNameByKey((uintptr_t)(name), acPath))
    {
        strcpy(acPath, "Data\\Video\\");
        std::strcat(acPath, name);
    }
    local.uiFlags = 0;
    if (preload || force)
    {
        unsigned reserved;
        if (fnv::crt::stat(acPath, &local.kStat) != -1)
        {
            local.piTimestamp = &(*reinterpret_cast<::NiPlaybackTimestamp *>(&::g_0126fad4)) ? &(*reinterpret_cast<::NiPlaybackTimestamp *>(&::g_0126fad4)).timestamp : &(DAT_01202800 = 0);
            if (static_cast<long long>(local.kStat.size) <= *local.piTimestamp || force)
                local.uiFlags |= 0x2000;
        }
    }
    local.bOtherThread = false;
    local.uiCurrentThreadID = GetCurrentThreadId();
    if (local.uiCurrentThreadID != (*reinterpret_cast<::NiPlaybackManager * *>(&::DAT_0126fac4))->vfn_3c())
    {
        local.bOtherThread = true;
        local.uiFlags |= 0x08000000;
    }
    (*reinterpret_cast<::NiPlaybackManager * *>(&::DAT_0126fac4))->vfn_14();
    handle = BinkOpen(acPath, local.uiFlags);
    local.bSuccess = true;
    if (!handle)
    {
        if (!handle)
        {
            if (!silent)
                ::FUN_005b5e40();
            state = 0;
            local.bSuccess = false;
        }
    }
    if (local.bOtherThread)
        reinterpret_cast<::MovieSignalState *>(((*reinterpret_cast<::NiPlaybackManager * *>(&::DAT_0126fac4))))->FUN_00ec1a00();
    (*reinterpret_cast<::NiPlaybackManager * *>(&::DAT_0126fac4))->vfn_18();
    return local.bSuccess;
}
