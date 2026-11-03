#pragma once
#include <cstdint>

class FlaggedData {
public:
    // 0x0040e210
    int ContainsAnyFlag(unsigned int);
    // 0x00703350
    static intptr_t GetPlayerValue();
    // 0x008c2e30
    int FUN_008c2e30();
};
