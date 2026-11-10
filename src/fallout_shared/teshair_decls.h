// fallout_shared/teshair_decls.h: declares TESActorBase, TESHairRaceResult, TESHairCanBeNPCData, TESTextureLoader, TESFileFormInt
#ifndef FNV_TESHAIR_DECLS_H
#define FNV_TESHAIR_DECLS_H


#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/RefList.h"
#include "fnv/symbols_0045b000.h"
#include "TESForm.h"

class TESActorBase;
enum SEX
{
    eSex_Male = 0,
    eSex_Female = 1
};
class TESActorBase
{
  public:
    SEX GetSex() const;
};

class BGSQuestObjective;

class TESHairRaceResult
{
  public:
};

class TESHairCanBeNPCData
{
  public:
};

class TESTextureLoader
{
  public:
};

class TESFileFormInt
{
  public:
};

#endif
