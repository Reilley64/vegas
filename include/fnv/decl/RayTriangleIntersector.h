#pragma once

class NiPoint3;

class RayTriangleIntersector {
public:
    // 0x00eadb90
    static bool IntersectRayTriangle(const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, bool, ::NiPoint3 &, float &, float &, float &);
};
