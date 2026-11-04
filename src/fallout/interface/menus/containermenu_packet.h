// fallout/interface/menus/containermenu_packet.h: declares SaveLoadFile, BGSLoadGameBuffer, BGSAcousticSpace, TESEnchantableForm, BGSQuestObjective and more
#ifndef CONTAINERMENU_PACKET_H
#define CONTAINERMENU_PACKET_H

#include <cstring>
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_00864740_shell.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/WeaponQueue.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_01018000.h"
class SaveLoadFile
{
  public:
    void SetFilePosition(int);
    unsigned Read(void*, unsigned);
    unsigned GetFilePosition();
};
class BGSLoadGameBuffer
{
  public:
    char data[16];
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
};
class TESSound;
class TESLandTexture;
class TESQuest;
class SpellItem;
enum MagicSystem__CastingType
{
    castingZero
};
class BGSAcousticSpace
{
  public:
};
class TESEnchantableForm
{
  public:
};
class TESQuest;
class BGSQuestObjective
{
  public:
public:
    void SetOwner(::TESQuest *);
};
class TESRegionGrassObject
{
  public:
    void AssignLandTexture(TESLandTexture*);
};
class BGSDehydrationStage
{
  public:
    void FUN_0050f9a0(SpellItem*);
};
class TESFile
{
  public:
    bool NextChunk();
};
class TESConditionItem
{
  public:
};
namespace ActorValue { enum Index; }
class TESRecipe
{
  public:
public:
    void SetRequiredSkill(::ActorValue::Index);
};
class Tile;
class InterfaceManager
{
  public:
public:
    ::Tile *FUN_00586150();
};
class SaveHeaderOps
{
  public:
};
class TESIdleForm;
class TESResponse
{
  public:
};
extern char* DAT_011a2224;
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned);
#endif
