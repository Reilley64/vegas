#pragma once

class NiGeometry;
class ShadowSceneLight;

struct ShaderBdaf10 {
public:
    // 0x00bdaf10
    void EmitShadowPasses(::NiGeometry *, ::ShadowSceneLight *, unsigned short *, unsigned char, bool *, bool);
};
