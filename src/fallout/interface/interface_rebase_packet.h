// fallout/interface/interface_rebase_packet.h: declares EffectSetting, InterfaceManager
#ifndef FNV_INTERFACE_REBASE_CURRENT_PACKET_H
#define FNV_INTERFACE_REBASE_CURRENT_PACKET_H
#include "fnv/decl/MagicProjectile.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d9000.h"
class Tile;
class NiNode;
class TESSound;
class TESSound;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
public:
    ::TESSound *GetHitSound();
};
class FORenderedMenu;
class InterfaceManager
{
  public:
    char padding[0x4d0];
    float screenAspectRatio;
    static float UpdateInterfaceState();
    Tile* FUN_00586150();
public:
    ::FORenderedMenu *GetActiveRenderedMenu();
public:
    int GetTopEnterStackEntry();
public:
    int GetMenuStackEntry(int);
};
float FUN_00706e20();
float FUN_00706e50();
bool FUN_00707b50();
unsigned int FUN_00702440();
bool FUN_00705100();
unsigned int FUN_00706f20();


#endif
