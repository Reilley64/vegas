#pragma once

class BSFogProperty;
struct BSRenderedTexture;
class NiAVObject;
class NiTexture;
template <class> class NiPointer;

class BSShaderManager {
public:
    // 0x00b4f450
    static void SetRenderMode(unsigned int);
    // 0x00b4f4a0
    static char *GetRenderModeName();
    // 0x00b4f530
    static ::BSRenderedTexture *GetSceneDepthRenderedTexture();
    // 0x00b4f5e0
    static void BuildTexturePath(char *, const char *, const char *, bool);
    // 0x00b54000
    static void SetFOV(float);
    // 0x00b55540
    static void SetFogPropertyForIndex(int, ::BSFogProperty *);
    // 0x00b55840
    static void GetTexture(const char *, bool, ::NiPointer< ::NiTexture> &, bool, bool);
    // 0x00b57e30
    static void UpdateObjectTypeRecurse(::NiAVObject *, bool, bool);
};
