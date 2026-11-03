#pragma once

class CombatThreatMap;
class CombatCoverMap;
class CombatTargetMap;

// The leading data members of CombatManager (the object behind BGSSaveLoadGlobalDataWorldspacePtr), for units whose
// CombatManager stand-ins declare no fields. The 4-byte getters folded into 0x00825c00 (+0x14) and 0x009611e0 (+0x18)
// read `pThreatMap` and `pCoverMap` when called on the combat manager. Comments give the 32-bit offsets.
struct CombatManagerFields
{
    void* pCombatGroupsVtable;          // 0x00
    void* pCombatGroups;                // 0x04
    unsigned short usCombatGroupsMax;   // 0x08
    unsigned short usCombatGroupsSize;  // 0x0A
    unsigned short usCombatGroupsESize; // 0x0C
    unsigned short usCombatGroupsGrowBy;// 0x0E
    void* pActorCombatGroupMap;         // 0x10
    CombatThreatMap* pThreatMap;        // 0x14
    CombatCoverMap* pCoverMap;          // 0x18
    CombatTargetMap* pTargetMap;        // 0x1C
};
