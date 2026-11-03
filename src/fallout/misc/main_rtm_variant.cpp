
// src/fallout/misc/main_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/misc/main.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include <cstdio>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/EffectSettingCollection.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_01082000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "main.h"

#include <stdio.h>
int __cdecl strcat_s(char*, unsigned int, const char*);
struct PluginListEntry
{
};
struct PluginListHandler
{
};
struct Receiver86;

struct PluginListReader
{
    bool FUN_00872430(const char* pDir, const char* pName);
};

// @fnv 0x00872430
bool PluginListReader::FUN_00872430(const char* pDir, const char* pName)
{
    char acPath[260];
    char acLine[512];
    FILE* pFile;
    {
        bool m_bHeaderParsed = false;
        ::TaskQueueInterface::CopyStringToBuffer(acPath, 260, pDir);
        strcat_s(acPath, 260, pName);
        pFile = fopen(acPath, DAT_01082cb8);
        if (pFile)
        {
            while (std::fgets(acLine, 512, (std::FILE *)(pFile)))
            {
                unsigned int uiLen = ::FUN_0044a670(acLine);
                if (acLine[0] != '#' && uiLen > 1)
                {
                    if (acLine[uiLen - 1] == '\n')
                        acLine[uiLen - 1] = 0;
                    TESFile* m_pFileEntry = reinterpret_cast<::TESDataHandler *>((((PluginListHandler*)(*reinterpret_cast<::Receiver86 * *>(&::g_dataHandler)))))->LookupTESFile(acLine);
                    if (m_pFileEntry)
                    {
                        reinterpret_cast<::EffectSettingCollection *>((((PluginListEntry*)m_pFileEntry)))->InitializeCollection(true);
                        m_bHeaderParsed = true;
                    }
                }
            }
            fclose(pFile);
        }
        return m_bHeaderParsed;
    }
}
