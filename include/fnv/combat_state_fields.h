#pragma once

class CombatCoverPointData;

// Members of CombatState (CombatControllerFields::pCombatState) that combat code reads directly. The release build
// reads them through the folded 4-byte getters at 0x0097b050 (GetFieldValue, +0xE4) and 0x0097fb60 (GetFieldAtE8).
// The padding keeps the 32-bit offsets until the members before them are modelled.
struct CombatStateFields
{
    char pad000[0xe4];
    void* pUnknownE4;
    CombatCoverPointData* pCoverPointData;
};
