#pragma once

struct NiStream;
struct ObjB0;
struct Point3Lite;
struct Pt3;
struct Sphere;
struct SphereBVLite;

// 0x00eac240
bool SphereTriangleSweepTest(float, const ::SphereBVLite &, const ::Point3Lite &, const ::Point3Lite &, const ::Point3Lite &, const ::Point3Lite &, const ::Point3Lite &);
// 0x00eac3f0
bool SphereTriangleCollision(float, const ::Sphere &, const ::Pt3 &, const ::Pt3 &, const ::Pt3 &, const ::Pt3 &, const ::Pt3 &, float &, ::Pt3 &, bool, ::Pt3 &, ::Pt3 &);
// 0x00eacb00
::ObjB0 *ReadObjB0(::NiStream &);
// 0x00eacef0
char *FUN_00eacef0(const char *, unsigned int);
// 0x00eacfd0
char *FormatName(const char *, int);
