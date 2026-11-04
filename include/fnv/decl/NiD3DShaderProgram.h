#pragma once

struct NiD3DShaderProgramCreator;

class NiD3DShaderProgram {
public:
    // 0x00dbbc10
    unsigned int GetCodeSize() const;
    // 0x00eea540
    void FUN_00eea540(::NiD3DShaderProgramCreator *);
};
