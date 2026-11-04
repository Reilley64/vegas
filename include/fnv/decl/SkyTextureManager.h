#pragma once

class NiTexture;
template <class> class NiPointer;

class SkyTextureManager {
public:
    // 0x0063fb70
    static void LoadTextureFromPath(::NiPointer< ::NiTexture> *, const char *);
};
