#pragma once

struct Arg3;
struct Arg4;
struct Bounds;
struct Context;
struct Holder;
struct Shape;
struct Vec3;

struct Agent {
public:
    // 0x00b3ea10
    void FUN_00b3ea10(::Context *, ::Vec3, float, ::Bounds *);
    // 0x00d33f40
    void FUN_00d33f40(const ::Shape &, const ::Shape &, const ::Arg3 &, ::Arg4 &);
    // 0x00d43aa0
    void FUN_00d43aa0(::Holder *, int, int, int, int);
};
