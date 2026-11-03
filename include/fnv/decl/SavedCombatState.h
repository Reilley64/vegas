#pragma once

struct CombatWriter;

struct SavedCombatState {
public:
    // 0x0098de90
    void WriteToStream(::CombatWriter *);
};
