#pragma once

class NiPoint3;

struct NavMeshAdjust {
public:
    // 0x00697d40
    ::NiPoint3 AdjustPointToNavMesh(const ::NiPoint3 &, float);
};
