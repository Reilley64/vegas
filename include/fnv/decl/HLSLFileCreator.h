#pragma once

struct ID3DXConstantTable;

struct HLSLFileCreator {
public:
    // 0x00e962a0
    bool CompileShaderFromFile(const char *, const char *, const char *, void *&, unsigned int &, ::ID3DXConstantTable *&, bool);
};
