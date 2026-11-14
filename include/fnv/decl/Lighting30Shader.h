#pragma once

class BSShader;

class Lighting30Shader {
public:
    // 0x00bbb840
    static void InvalidateShaderConstants();
    // 0x00bbd0d0
    static ::BSShader *CreateShader();
};
