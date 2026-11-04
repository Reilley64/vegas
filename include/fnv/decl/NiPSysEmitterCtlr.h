#pragma once

class CloningProcess;
class NiStream;

class NiPSysEmitterCtlr {
public:
    // 0x00c1bd30
    void CopyMemberData(::NiPSysEmitterCtlr *, ::CloningProcess &);
    // 0x00c1bdc0
    void ProcessClone(::CloningProcess &);
    // 0x00c1bdf0
    void LoadBinary(::NiStream &);
    // 0x00c1c0e0
    void LinkObject(::NiStream &);
};
