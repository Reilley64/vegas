#pragma once

class CloningProcess;
class NiStream;

class NiLight {
public:
    // 0x00a68d40
    void CopyMemberData(::NiLight *, ::CloningProcess &);
    // 0x00a72080
    void LoadBinary(::NiStream &);
};
