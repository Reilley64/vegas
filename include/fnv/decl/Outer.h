#pragma once

struct Aabb;
struct ParamOwner;
struct hkVector4;

struct Outer {
public:
    // 0x0084a520
    void FUN_0084a520(::ParamOwner *);
    // 0x008c4850
    float FUN_008c4850();
    // 0x00c8d240
    ::hkVector4 GetVec() const;
    // 0x00d9d110
    int FUN_00d9d110(const ::Aabb *, int);
};
