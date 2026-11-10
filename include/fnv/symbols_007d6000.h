#pragma once

class BGSSaveLoadFileEntry;
namespace fnv_007d67b0 { class Tile; }
namespace fnv_anon_startmenu { struct Dummy7d6e90; }

// 0x007d61b0
int *AdvanceCounter(int *);
// 0x007d67b0
namespace fnv_007d67b0 { void InitSaveLoadTile(::fnv_007d67b0::Tile *, ::BGSSaveLoadFileEntry *); }
// 0x007d6950
int FUN_007d6950(::BGSSaveLoadFileEntry *);
// 0x007d6970
char *FUN_007d6970(::BGSSaveLoadFileEntry *);
// 0x007d6990
void FUN_007d6990(int);
// 0x007d69d0
namespace fnv_007d69d0 { void FUN_007d69d0(); }
// 0x007d69f0
namespace fnv_007d69f0 { void FUN_007d69f0(); }
// 0x007d6d70
namespace fnv_007d6d70 { void FUN_007d6d70(); }
// 0x007d6e90
void* CallVirtualZero(::fnv_anon_startmenu::Dummy7d6e90 *);
