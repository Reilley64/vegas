#pragma once

#include <cstdint>

struct Elem9f6340;

struct Host9f6340 {
public:
    // 0x009f6340
    unsigned int AppendElement(::Elem9f6340 *);
    // 0x009f6460
    void FUN_009f6460(std::intptr_t, int);
    // 0x009f65f0
    void ResetAndWrite(unsigned int, unsigned int);
};
