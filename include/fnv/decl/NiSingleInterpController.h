#pragma once

class CloningProcess;
class NiStream;

class NiSingleInterpController {
public:
    // 0x00a38f50
    void ProcessClone(::CloningProcess &);
    // 0x00a38f80
    void LoadBinary(::NiStream &);
};
