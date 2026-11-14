#pragma once

struct NiD3DShaderProgramCreator;

class NiD3DShaderProgramFactory {
public:
    // 0x00e93000
    const char *GetNextName(void *&);
    // 0x00e93e70
    static bool RegisterCreator(const char *, ::NiD3DShaderProgramCreator *);
};
