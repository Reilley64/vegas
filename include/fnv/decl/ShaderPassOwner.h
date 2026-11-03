#pragma once

struct NiGeometry;
struct ShadowSceneLight;

struct ShaderPassOwner {
public:
    // 0x00bdc530
    int AddShadowPass(::NiGeometry *, ::ShadowSceneLight *, ::ShadowSceneLight *, ::ShadowSceneLight *, unsigned short *, bool, bool *, bool, bool, bool, bool, bool, bool, bool);
};
