#pragma once

class BGSLoadGameBuffer;
struct BGSSaveFormBuffer;

class CombatThreatMap {
public:
    // 0x00991080
    CombatThreatMap();
    // 0x00993800
    void FUN_00993800(int);
    // 0x009a59e0
    void SaveThreats(::BGSSaveFormBuffer *);
    // 0x009a5c40
    void ApplyLoadBuffer(::BGSLoadGameBuffer *);
};
