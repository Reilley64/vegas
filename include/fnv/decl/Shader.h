#pragma once

struct Arg;
struct Context;
struct Geom;
struct NiGeometry;
struct Passes;
struct ShadowSceneLight;
struct Transform;

struct Shader {
public:
    // 0x00b67be0
    ::Passes *GetPasses(::Geom *, unsigned int, unsigned short *, unsigned int, ::Context *, unsigned char);
    // 0x00b7ded0
    void SetupTextureStages(::Arg *);
    // 0x00b8ede0
    ::Shader *DestroyShader(unsigned char);
    // 0x00baa850
    void FUN_00baa850(int, const struct ::Transform *);
    // 0x00bdd050
    int FUN_00bdd050(::NiGeometry *, ::ShadowSceneLight *, unsigned short *, unsigned char, bool *, bool, bool, bool, bool, bool, bool, bool, bool);
};
