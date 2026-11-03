#pragma once

class NiPoint3;

struct NavMeshGrid {
public:
    // 0x00691260
    int GetCellIndex(const ::NiPoint3 &);
    // 0x0069dd50
    void FUN_0069dd50(::NavMeshGrid *) const;
};
