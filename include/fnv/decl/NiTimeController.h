#pragma once

struct CloningProcess;
struct NiObjectNET;
struct NiStream;

class NiTimeController {
public:
    // 0x00a6d0c0
    void ProcessClone(::CloningProcess &);
    // 0x00a6d450
    void SetTarget(::NiObjectNET *);
    // 0x00a6d500
    void LinkObject(::NiStream &);
};
