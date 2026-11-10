#pragma once

struct NiStream;

class NiSphere {
public:
    // 0x00a69ac0
    void LoadBinary(::NiStream &);
    // 0x00eb5410
    void SaveBinary(::NiStream &);
};
