#pragma once

struct FUN_00e10740_a;
struct FUN_00e10740_b;
struct S_00e10760_Item;
struct SearchContainer;
struct SearchItem;

// 0x00e10740
int FUN_00e10740(const ::FUN_00e10740_a *, const ::FUN_00e10740_b *);
// 0x00e10760
void FUN_00e10760(::S_00e10760_Item **, int, int, bool (*)(S_00e10760_Item *, S_00e10760_Item *));
// 0x00e10820
::SearchItem *FUN_00e10820(::SearchContainer *, double, int);
