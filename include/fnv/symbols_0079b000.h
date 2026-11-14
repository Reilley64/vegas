#pragma once

class FUN_00a011b0_owner_b9258;
class Target79B;
class Tile;
namespace fnv_0079b720 { struct TESChallenge; }
struct B79B820Item;
struct FUN_0079bd70_data;
struct MagicCaster_shell;
struct RefH;

// 0x0079b390
bool FUN_0079b390(::Target79B *);
// 0x0079b430
void FUN_0079b430(int);
// 0x0079b720
namespace fnv_0079b720 { bool FUN_0079b720(::fnv_0079b720::TESChallenge *); }
// 0x0079b820
int CompareItems(::B79B820Item *, ::B79B820Item *);
// 0x0079bc50
bool FUN_0079bc50(::MagicCaster_shell *);
// 0x0079bc90
int FUN_0079bc90(::FUN_00a011b0_owner_b9258 **, ::FUN_00a011b0_owner_b9258 **);
// 0x0079bd70
int CompareMobileObjects(::FUN_0079bd70_data *, ::FUN_0079bd70_data *);
// 0x0079be30
bool FUN_0079be30(::RefH *);
// 0x0079be80
void FUN_0079be80(::Tile *);
