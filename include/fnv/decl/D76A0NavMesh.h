#pragma once

struct D76A0EdgeExtraInfo;

class D76A0NavMesh {
public:
    // 0x006976a0
    ::D76A0EdgeExtraInfo *GetOrCreateEdgeInfo(unsigned short, int);
};
