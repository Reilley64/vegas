#pragma once

struct CloningProcess;
struct NiPSysModifier;

struct NiPSysBoxEmitter {
public:
    // 0x00c21f60
    void CopyTo(::NiPSysModifier *, ::CloningProcess &);
};
