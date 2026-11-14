#pragma once

struct BoundVolLite;
struct Point3Lite;

struct SphereBVLite {
public:
    // 0x00eab9d0
    static bool CheckSweptSphereOverlap(float, const ::BoundVolLite &, const ::Point3Lite &, const ::BoundVolLite &, const ::Point3Lite &);
};
