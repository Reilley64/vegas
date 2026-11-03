#pragma once

class FORenderedMenu;
class NiNode;
class QuantityData;
struct DisplayItem;
struct DisplayTile;

// 0x00707010
int FUN_00707010(int, float, float);
// 0x00707070
int GetFieldD0();
// 0x007070c0
bool FUN_007070c0(const char *, char *, unsigned int, bool);
// 0x00707330
namespace fnv_00707330 { int FindSettingIndex(const char *); }
// 0x007073d0
namespace fnv_007073d0 { bool ResolveSettingString(const char *, char *); }
// 0x00707640
void FUN_00707640(const char *);
// 0x00707660
::NiNode *FUN_00707660(const char *, bool *);
// 0x00707820
void FUN_00707820();
// 0x00707870
unsigned int FUN_00707870(unsigned int);
// 0x00707930
namespace fnv_00707930 { void FUN_00707930(bool); }
// 0x007079b0
bool FUN_007079b0();
// 0x00707a30
bool FUN_00707a30(::QuantityData *);
// 0x00707ad0
::FORenderedMenu *FUN_00707ad0();
// 0x00707b30
namespace fnv_00707b30 { void FUN_00707b30(); }
// 0x00707b50
bool FUN_00707b50();
// 0x00707e30
void FUN_00707e30(::DisplayItem *, ::DisplayTile *);
