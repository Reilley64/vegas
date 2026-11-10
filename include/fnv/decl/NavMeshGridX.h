#pragma once

struct NiPoint3;

struct NavMeshGridX {
public:
    // 0x006912a0
    void GetCellCoords(const ::NiPoint3 &, unsigned int &, unsigned int &);
};
