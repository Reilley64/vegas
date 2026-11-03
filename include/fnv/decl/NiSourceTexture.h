#pragma once

class NiFixedString;
class NiTexture__FormatPrefs;
struct TextureLoadStream;

class NiSourceTexture {
public:
    // 0x00a5fd70
    static ::NiSourceTexture *Create(const ::NiFixedString &, ::NiTexture__FormatPrefs &, bool, bool);
    // 0x00a60180
    void FUN_00a60180(::TextureLoadStream &);
};
