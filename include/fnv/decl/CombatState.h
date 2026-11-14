#pragma once
#include <cstdint>

class TESForm;

struct CombatState {
public:
    // 0x00575610
    intptr_t GetInventoryItemCount(::TESForm *);
    // 0x0064bf90
    void UpdateCombatStateData(int, float *, float *, float);
    // 0x008be1b0
    void ProcessCoverLOSResult();
};
