#pragma once

struct BSRenderedTexture;
class NiCamera;

class BSShaderAccumulator {
public:
    // 0x00b63120
    void FUN_00b63120(unsigned int, int);
    // 0x00b65550
    void SetupDepth(::NiCamera *, ::NiCamera *, ::BSRenderedTexture *);
};
