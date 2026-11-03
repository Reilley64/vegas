#pragma once

struct NiGeometry;

struct ShaderPassSelection {
public:
    // 0x00bda030
    int AddAdditionalPass(::NiGeometry *, unsigned int, bool, bool);
};
