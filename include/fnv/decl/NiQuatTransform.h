#pragma once

struct NiStream;

class NiQuatTransform {
public:
    // 0x00494260
    NiQuatTransform();
    // 0x00a38bb0
    void LoadBinary(::NiStream &);
    // 0x00a39180
    bool IsInvalid() const;
};
