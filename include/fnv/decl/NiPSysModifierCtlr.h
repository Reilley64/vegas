#pragma once

class CloningProcess;
class NiStream;

class NiPSysModifierCtlr {
public:
    // 0x00a571a0
    void LoadBinary(::NiStream &);
    // 0x00c31340
    void ProcessClone(::CloningProcess &);
};
