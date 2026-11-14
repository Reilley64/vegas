#pragma once

struct NiBinaryStream;

struct RleDecoder {
public:
    // 0x00a8d8e0
    void Decode(::NiBinaryStream &, unsigned char *, unsigned int);
};
