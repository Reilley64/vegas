#pragma once

class BSFileEntry;
class NiTexture;

class TextureFileEntrySetter {
public:
    // 0x00a61c50
    static void SetTexture(::NiTexture *, const ::BSFileEntry *);
};
