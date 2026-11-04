#pragma once

class NiShaderConstantMap {
public:
    // 0x00a9bfd0
    static bool FindConstantMapping(const char *, unsigned int &, unsigned int &);
    // 0x00a9c2a0
    static void InitializePoint3();
};
