#pragma once

struct NiGeometry;
struct ShadowSceneLight;

struct BDBF60_Shader {
public:
    // 0x00bdbf60
    int FUN_00bdbf60(::NiGeometry *, ::ShadowSceneLight *, ::ShadowSceneLight *, unsigned short *, unsigned char, bool *, bool, bool, bool);
};
