#pragma once

struct InventoryEntry;
struct InventoryOwner;
struct Tile;

struct InventoryListBox {
public:
    // 0x00719ef0
    void PopulateInventoryList(::InventoryOwner *, bool (*)(InventoryEntry *), int, void (*)(Tile *, InventoryEntry *), bool, bool);
};
