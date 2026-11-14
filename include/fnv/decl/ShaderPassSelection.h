#pragma once

class NiGeometry;

struct ShaderPassSelection {
public:
    // 0x00bda030
    int AddAdditionalPass(::NiGeometry *, uintptr_t, bool, bool);
};
