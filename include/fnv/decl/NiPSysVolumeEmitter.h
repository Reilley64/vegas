#pragma once

struct NiStream;

class NiPSysVolumeEmitter {
public:
    // 0x00c31b20
    void LoadBinary(::NiStream &);
    // 0x00c31b40
    void LinkObject(::NiStream &);
};
