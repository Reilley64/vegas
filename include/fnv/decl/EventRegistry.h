#pragma once
#include <cstdint>

struct EventData;

struct EventRegistry {
public:
    // 0x00982f40
    bool RegisterEvent(intptr_t, ::EventData *);
};
