#pragma once

class NiTransform;

struct NiBound {
public:
    // 0x00a7fb20
    char *FUN_00a7fb20(const char *);
    // 0x00a7fdd0
    void Update(const ::NiBound &, const ::NiTransform &);
    // 0x00a926b0
    bool FUN_00a926b0(const ::NiBound &);
};
