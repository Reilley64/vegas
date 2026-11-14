#pragma once

struct EquipActor;
struct EquipExtra;
struct EquipForm;

struct EquipInv {
public:
    // 0x004bffe0
    void AddItemToInventory(::EquipForm *, int, ::EquipActor *, ::EquipExtra *, bool, bool);
};
