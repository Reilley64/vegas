#pragma once

struct FUN_00438fc0_file;

struct NiPoint3 {
public:
    // 0x00438fc0
    unsigned char ReadFromFile(::FUN_00438fc0_file *);
    // 0x004390c0
    bool FUN_004390c0(const ::NiPoint3 &);
    // 0x004578c0
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
    // 0x00457910
    float GetLengthSquared();
    // 0x00457990
    float ComputeMagnitude() const;
    // 0x004b3800
    ::NiPoint3 Cross(const ::NiPoint3 &) const;
    // 0x0053d1a0
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
    // 0x00633b40
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
    // 0x00a59af0
    char *FUN_00a59af0(const char *);
    // 0x00b2a1c0
    ::NiPoint3 &FUN_00b2a1c0(const ::NiPoint3 &);
    // 0x011f426c
    static const ::NiPoint3 ZERO;
};
