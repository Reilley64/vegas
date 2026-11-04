// fallout_shared/miscstats_decls.h: declares MiscStatManager, MiscStatEntry, ChallengeManager, Menu, Tile and more
#ifndef MISCSTATS_DECLS_H
#define MISCSTATS_DECLS_H

#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_011c6000.h"
class MiscStatManager
{
  public:
    enum MiscStat
    {
        MS_COUNT = 43
    };
    static void AddMiscStat(MiscStat id, int delta);
};
struct MiscStatEntry
{
    const char* name;
    int value;
};
int FUN_004d5e00();
class TESForm;
enum CHALLENGE_TYPE
{
    CHALLENGE_MISCSTAT = 11
};
class ChallengeManager
{
  public:
    static bool UpdateChallengeProgress(CHALLENGE_TYPE, int, TESForm*, TESForm*, unsigned short, unsigned short,
                                        unsigned short);
};
class Menu
{
};
class Tile
{
  public:
};
enum MiscStatManager__MiscStatID;
class StatsMenu : public Menu
{
  public:
public:
    void RefreshMiscStat(::MiscStatManager__MiscStatID);
};
#endif
