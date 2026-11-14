#pragma once

struct BGSLoadGameBuffer;

struct CombatTargetTimestamp {
public:
    // 0x006a7f50
    float FUN_006a7f50() const;
    // 0x009a5ff0
    void LoadGame(::BGSLoadGameBuffer *);
};
