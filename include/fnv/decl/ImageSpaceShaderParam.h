#pragma once

class ImageSpaceShaderParam {
public:
    // 0x00b8a790
    void SetShaderConstantVector4(int, float, float, float, float);
    // 0x00b8a7c0
    void FUN_00b8a7c0();
    // 0x00b8a7e0
    void FUN_00b8a7e0();
    // 0x00b8a8b0
    void CopyParamData(int, const float *, unsigned int);
    // 0x00b8a8d0
    void SetRenderState(unsigned int, unsigned int);
    // 0x00b8ab10
    void AllocateShaderConstants(int, int);
};
