// src/fallout/interface/menus/startmenu_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/interface/menus/startmenu.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "fnv/decl/BSAudioManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_007d0b90_cls.h"
#include "fnv/decl/FUN_009698a0_shell.h"
#include "fnv/decl/FalloutAudioMedia.h"
#include "fnv/decl/GlobalObject_0045cf30.h"
#include "fnv/decl/S457d70.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00761000.h"
#include "fnv/symbols_007d1000.h"
#include "fnv/symbols_007d3000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00a25000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "startmenu_packet.h"
void FUN_007d1b30();

#include <string.h>
#include <stdio.h>
struct MainMenuDeletable
{
    virtual ~MainMenuDeletable();
};
struct MainMenuAudioAccess
{
};
struct MainMenuResetAccess
{
};
struct MainMenuWorldAccess
{
};
struct MainMenuPlayerAccess
{
};
class TES;
struct PC7d;

// @fnv 0x007d0a70
void FUN_007d0a70()
{
    char acMusicPath[64];
    delete (MainMenuDeletable*)(*reinterpret_cast<::StartMenu * *>(&::fnv_007d0700::DAT_011daac0));
    ::fnv_00703610::FUN_00703610();
    FUN_00706320(0);
    reinterpret_cast<::BSAudioManager *>((((MainMenuAudioAccess*)::FUN_00453a70())))->FUN_00ad84e0((void *)(-1), (void *)(false));
    ResetTaskQueueGlobals();
    {
        int bIsChild = ((int)(reinterpret_cast<::FUN_009698a0_shell *>((((MainMenuPlayerAccess*)(*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))))->GetMediaLocationController()));
        bIsChild = 0;
    }
    if (((::BGSSaveLoadUI *)(::FUN_00a25920())))
    {
        ((::BGSSaveLoadUI *)(::FUN_00a25920()))->FUN_007d0bd0(false);
        ((::BGSSaveLoadUI *)(::FUN_00a25920()))->FUN_007d0bb0();
    }
    DAT_011daacd = true;
    reinterpret_cast<::FUN_007d0b90_cls *>((((MainMenuResetAccess*)g_osGlobals)))->FUN_007d0b90();
    reinterpret_cast<::S457d70 *>((((MainMenuWorldAccess*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00457d70(1, (::Form457 *)(0), 0);
    memset(acMusicPath, 0, 64);
    sprintf_s(acMusicPath, 64, "Data\\Music\\Special\\MainTitle.mp3");
    ::FUN_00761460(true);
    ::fnv_008300c0::PlayAudioMedia(8, acMusicPath, 5000, true, true, 0.0f, 0);
    ::FalloutAudioMedia::EndMediaUpdate();
}
