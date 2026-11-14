#pragma once

class FontCharacterInfo;
struct NiPoint3;
class NiTriShape;
struct RgbaColor;

class Font {
public:
    // 0x00a122b0
    static void MapCharacter(unsigned char &);
    // 0x00a142d0
    void AddCharacterToShape(::FontCharacterInfo *, int, ::NiTriShape *, ::NiPoint3 &, const ::RgbaColor *);
};
