#pragma once

class InventoryStackRecord;
namespace fnv_007824e0 { template <class> struct ListBoxItem; }
struct Entry;
struct ItemLabelSource;
struct ItemLabelTile;

// 0x00782470
void FUN_00782470(bool);
// 0x007824e0
namespace fnv_007824e0 { int FUN_007824e0(::fnv_007824e0::ListBoxItem< ::InventoryStackRecord *> *, ::fnv_007824e0::ListBoxItem< ::InventoryStackRecord *> *); }
// 0x00782620
bool FUN_00782620(::Entry *);
// 0x00782810
unsigned char IsNotFormType2E(void *);
// 0x00782850
void UpdateItemLabel(::ItemLabelTile *, ::ItemLabelSource *);
// 0x00782a90
void FUN_00782a90();
