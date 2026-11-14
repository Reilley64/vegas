#pragma once

struct NiStream;

class NiPSysEmitter {
public:
    // 0x00c21f00
    NiPSysEmitter();
    // 0x00c223b0
    void LoadBinary(::NiStream &);
};
