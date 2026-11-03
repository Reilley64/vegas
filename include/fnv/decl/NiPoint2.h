#pragma once

class NiStream;

class NiPoint2 {
public:
    // 0x00452dc0
    NiPoint2(float, float);
    // 0x004a4f40
    ::NiPoint2 operator*(float) const;
    // 0x00a68c80
    void LoadBinary(::NiStream &);
};
