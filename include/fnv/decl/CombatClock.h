#pragma once

struct TimeInput;

struct CombatClock {
public:
    // 0x00985b40
    float GetAdjustedTime(::TimeInput *);
};
