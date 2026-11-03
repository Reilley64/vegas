#pragma once

class CloningProcess;
class NiStream;

struct NiObjectNET {
public:
    // 0x00439340
    void FUN_00439340(unsigned short);
    // 0x00439360
    void FUN_00439360(unsigned short, unsigned int, unsigned int);
    // 0x004393e0
    void SetFlags(unsigned short);
    // 0x0043b480
    void GetNumChildren();
    // 0x0049edb0
    void FUN_0049edb0(unsigned short);
    // 0x00533fb0
    void FUN_00533fb0(unsigned short);
    // 0x00a5b8f0
    void ProcessClone(::CloningProcess &);
    // 0x00a5b990
    void DeleteExtraData(unsigned short);
    // 0x00a5bba0
    bool ResizeExtraData(unsigned short);
    // 0x00a5bf50
    bool FUN_00a5bf50(unsigned short);
    // 0x00a5c050
    void FUN_00a5c050();
    // 0x00a5c080
    void LoadBinary(::NiStream &);
    // 0x00a5c0e0
    void LinkObject(::NiStream &);
};
