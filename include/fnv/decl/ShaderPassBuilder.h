#pragma once

class NiGeometry;
class ShadowSceneLight;

struct ShaderPassBuilder {
public:
    // 0x00b887c0
    bool InitPasses();
    // 0x00bdd520
    int FUN_00bdd520(::NiGeometry *, ::ShadowSceneLight *, ::ShadowSceneLight *, unsigned short *, unsigned char, bool *, bool, bool, bool, bool, bool, bool, bool, bool);
};
