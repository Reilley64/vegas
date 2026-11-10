#pragma once

struct NiPoint2;
struct NiPoint3;
struct RgbaColor;
enum NiGeometryData__DataFlags;

class NiTriBasedGeomData {
public:
    // 0x00a8a920
    NiTriBasedGeomData(unsigned short, ::NiPoint3 *, ::NiPoint3 *, ::RgbaColor *, ::NiPoint2 *, unsigned short, ::NiGeometryData__DataFlags, unsigned short);
};
