#pragma once

class TESFile;
template <class> class BSStringT;

class TESTexture {
public:
    // 0x0048e270
    TESTexture();
    // 0x0048e3d0
    static void ReadTextureData(::TESTexture *, ::TESFile *);
    // 0x0048e5b0
    static const char *NormalizeTextureFilePath(::BSStringT<char> &, const char *);
};
