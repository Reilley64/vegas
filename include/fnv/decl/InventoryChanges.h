#pragma once

class TESObjectREFR;

struct InventoryChanges {
public:
    // 0x004bf220
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
    // 0x0056aa70
    ::InventoryChanges *CreateForReference();
};
