#pragma once

class Sphere;
class SphereTangents;
enum ANGLE_DIRECTION;

class NavMeshPOVSearch {
public:
    // 0x006bb570
    static int FindSphereTangents(const ::Sphere &, const ::Sphere &, ::ANGLE_DIRECTION, ::SphereTangents &);
};
