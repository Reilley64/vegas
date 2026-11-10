#pragma once

class NiGeometry;

struct ShaderPassController {
public:
    // 0x00bde170
    void SetPassEnabled(::NiGeometry *, bool, bool);
};
