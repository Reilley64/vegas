#pragma once

class CloningProcess;
class NiStream;

class NiPSysCollider {
public:
    // 0x00c32580
    void ProcessClone(::CloningProcess &);
    // 0x00c32610
    void LinkObject(::NiStream &);
    // 0x00c32840
    void LoadBinary(::NiStream &);
};
