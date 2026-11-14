#pragma once

class BSShader;
class NiRefObject;

class BSShaderBloodSplatter {
public:
    // 0x00b80600
    void FUN_00b80600(::NiRefObject *);
    // 0x00b80e70
    ::BSShader *CreateShader();
};
