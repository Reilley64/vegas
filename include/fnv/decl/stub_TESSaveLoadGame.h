#pragma once

struct stub_LoadBuffer;

struct stub_TESSaveLoadGame {
public:
    // 0x0085b170
    unsigned int ComputeFormTableChecksum(::stub_LoadBuffer *);
};
