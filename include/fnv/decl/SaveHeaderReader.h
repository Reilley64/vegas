#pragma once

struct NiBinaryStream;

struct SaveHeaderReader {
public:
    // 0x00860e20
    unsigned int FUN_00860e20(::NiBinaryStream *, bool);
};
