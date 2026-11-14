#pragma once

struct CloningProcess;
struct NiStream;

class NiSingleInterpController {
public:
    // 0x00a38f50
    void ProcessClone(::CloningProcess &);
    // 0x00a38f80
    void LoadBinary(::NiStream &);
};
