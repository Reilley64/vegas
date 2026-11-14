#pragma once

class NiGeometry;
class ShadowSceneLight;

struct ShaderTwoLightSelector {
public:
    // 0x00bdca60
    int SelectTwoLightPass(::NiGeometry *, ::ShadowSceneLight *, ::ShadowSceneLight *, unsigned short *, unsigned char, bool *, bool, bool, bool, bool, bool, bool, bool, bool);
};
