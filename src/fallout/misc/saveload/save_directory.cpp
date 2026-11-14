// BGSSaveLoadManager::GetSaveDirectory, WinMain's statement S7, in a unit of
// its own (VEGAS-135). It was defined in bgssaveloadmanager.cpp, whose
// declarations it keeps; that unit's generated data still defines the
// strings it reads.
#include <windows.h>
// SHGetFolderPathA. shlguid.h, which shlobj.h includes, defines two GUIDs
// unless told not to; this unit uses none.
#define NO_SHDOCVW_GUIDS
#include <shlobj.h>
#include "fnv/symbols_00406000.h"
#include "bgssaveloadmanager_decls.h"

// @fnv 0x00876ad0
void BGSSaveLoadManager::GetSaveDirectory(char* pcPath)
{
    bool useMyGames = true;
    ::FUN_00406d00(pcPath, 260, DAT_01082dc4, DAT_011a2ff4);
    if (!GetPrivateProfileIntA(g_011d3eb0_arg1, DAT_01082dac, 1, pcPath))
        useMyGames = false;
    ::FUN_00406d00(pcPath, 260, DAT_01082dc4, ::_DAT_011a2ff0);
    if (useMyGames && !GetPrivateProfileIntA(g_011d3eb0_arg1, DAT_01082dac, 1, pcPath))
        useMyGames = false;
    if (useMyGames)
    {
        char folder[260];
        pcPath[0] = 0;
        SHGetFolderPathA(0, 28, 0, 0, folder);
        fnv::crt::strcat_s(folder, 260, DAT_01082da0);
        CreateDirectoryA(folder, 0);
        TaskQueueInterface::CopyStringToBuffer(::FUN_0086d480(), 260, folder);
        SHGetFolderPathA(0, 5, 0, 0, folder);
        fnv::crt::strcat_s(folder, 260, DAT_01082d94);
        CreateDirectoryA(folder, 0);
        fnv::crt::strcat_s(folder, 260, DAT_01082d88);
        CreateDirectoryA(folder, 0);
        TaskQueueInterface::CopyStringToBuffer(::FUN_004dc110(), 260, folder);
    }
    else
    {
        TaskQueueInterface::CopyStringToBuffer(::FUN_0086d480(), 260, g_011dece4_arg1);
        TaskQueueInterface::CopyStringToBuffer(::FUN_004dc110(), 260, g_011dece4_arg1);
    }
    TaskQueueInterface::CopyStringToBuffer(pcPath, 260, ::FUN_004dc110());
    fnv::crt::strcat_s(pcPath, 260, ::_DAT_011a2ff0);
    DeleteFileA(::FUN_00c3bb80());
    DeleteFileA(::FUN_00c3bbd0());
    DeleteFileA(FUN_00c3bc20());
    if (fnv::crt::access(pcPath, 0) == -1)
    {
        char defaultIni[260];
        TaskQueueInterface::CopyStringToBuffer(defaultIni, 260, DAT_01082d70);
        CopyFileA(defaultIni, pcPath, 1);
    }
}
