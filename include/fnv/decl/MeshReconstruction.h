#pragma once

class NiGeometry;
struct NiPoint3;
struct NiSkinInstance;

class MeshReconstruction {
public:
    // 0x00c1e080
    bool FUN_00c1e080(::NiSkinInstance *, ::NiGeometry *, ::NiPoint3 &, ::NiPoint3 &);
};
