#pragma once

struct CloningProcess;

struct NiRangeLODData {
public:
    // 0x00a978a0
    void SetRangeCount(unsigned int);
    // 0x00a97ba0
    void CopyTo(::NiRangeLODData *, ::CloningProcess *);
};
