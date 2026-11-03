#pragma once

class CloningProcess;
class NiStream;

class NiPSysModifier {
public:
    // 0x00c31650
    void LinkObject(::NiStream &);
    // 0x00c31780
    void CopyMemberData(::NiPSysModifier *, ::CloningProcess &);
    // 0x00c317e0
    void ProcessClone(::CloningProcess &);
    // 0x00c318b0
    void LoadBinary(::NiStream &);
};
