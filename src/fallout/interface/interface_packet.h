// fallout/interface/interface_packet.h: declares EffectSetting, InterfaceManager

#include "fnv/decl/FUN_00706d90_shell.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d9000.h"
class Tile;
class NiNode;
class TESSound;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
};
class InterfaceManager
{
  public:
    char padding[0x4d0];
    float screenAspectRatio;
    static float UpdateInterfaceState();
    Tile* FUN_00586150();
};
unsigned int FUN_00702440();

