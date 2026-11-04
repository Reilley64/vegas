#pragma once

class MersenneTwister {
public:
    // 0x00476c00
    static ::MersenneTwister *GetRandomGenerator();
    // 0x004dff60
    float Float0To1();
    // 0x00aa5140
    MersenneTwister();
    // 0x00aa5230
    unsigned int GetRandomUInt(unsigned int);
};
