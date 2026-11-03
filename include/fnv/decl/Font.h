#pragma once

class FontCharacterInfo;
class NiPoint3;
class NiTriShape;
class RgbaColor;

class Font {
public:
    // 0x00a122b0
    static void MapCharacter(unsigned char &);
    // 0x00a142d0
    void AddCharacterToShape(::FontCharacterInfo *, int, ::NiTriShape *, ::NiPoint3 &, const ::RgbaColor *);
};
