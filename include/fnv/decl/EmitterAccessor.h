#pragma once

class NiGeometry;
struct NiPoint3;
struct NiSkinInstance;

struct EmitterAccessor {
public:
    // 0x00c1e4e0
    bool FUN_00c1e4e0(::NiSkinInstance *, ::NiGeometry *, ::NiPoint3 &, ::NiPoint3 &);
};
