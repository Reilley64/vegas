#pragma once

class InventoryStackRecord;
struct ModObject;
struct ModTile;
template <class> struct ListBoxItem;

// 0x007836d0
void UpdateTileFromObject(::ModTile *, ::ModObject *);
// 0x00783810
int CompareItemVisibility(::ListBoxItem< ::InventoryStackRecord *> *, ::ListBoxItem< ::InventoryStackRecord *> *);
