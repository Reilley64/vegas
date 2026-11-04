#pragma once

namespace fnv_007596a0 { struct Tile; }
struct MenuTile;
struct NoteEntry;
struct S_7597c0;

// 0x00759560
void UpdateNoteTile(::MenuTile *, ::NoteEntry *);
// 0x007596a0
namespace fnv_007596a0 { void FUN_007596a0(::fnv_007596a0::Tile *, void *); }
// 0x007596d0
::S_7597c0 *GetStorageSingleton();
