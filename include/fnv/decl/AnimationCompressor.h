#pragma once

struct Vector4Array;

struct AnimationCompressor {
public:
    // 0x00e31b20
    void WriteCompressedAnimation(unsigned char, int, const float *, const float *, const float *, int, const ::Vector4Array *);
};
