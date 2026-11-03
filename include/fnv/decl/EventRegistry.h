#pragma once

struct EventData;

struct EventRegistry {
public:
    // 0x00982f40
    bool RegisterEvent(int, ::EventData *);
};
