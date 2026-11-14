#pragma once

class NiGeometry;
class ShadowSceneLight;

struct ShaderPassOwner {
public:
    // 0x00bdc530
    int AddShadowPass(::NiGeometry *, ::ShadowSceneLight *, ::ShadowSceneLight *, ::ShadowSceneLight *, unsigned short *, bool, bool *, bool, bool, bool, bool, bool, bool, bool);
};
