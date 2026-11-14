#pragma once

struct ShaderState;

struct ShaderUpdate {
public:
    // 0x00507e30
    void UpdateShaderState(::ShaderState *, float, float, float, unsigned char);
};
