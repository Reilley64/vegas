#pragma once

struct NiStream;

class NiGeometryData {
public:
    // 0x004410f0
    void SetCompressFlags(unsigned char);
    // 0x00a67090
    void SetDirtyFlags(unsigned int);
    // 0x00a67360
    bool IsGeometryDataStreamable(bool);
    // 0x00a677e0
    void LinkObject(::NiStream &);
};
