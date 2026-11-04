#pragma once

class NiPoint2;
class NiPoint3;
class RgbaColor;
enum NiGeometryData__DataFlags;

class NiTriShape {
public:
    // 0x00a74410
    NiTriShape(unsigned short, ::NiPoint3 *, ::NiPoint3 *, ::RgbaColor *, ::NiPoint2 *, unsigned short, ::NiGeometryData__DataFlags, unsigned short, unsigned short *);
};
