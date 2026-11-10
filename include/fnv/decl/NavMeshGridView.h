#pragma once

struct NiPoint3;
struct NavMeshTriList;

struct NavMeshGridView {
public:
    // 0x0069d370
    void GetTriListAtPosition(const ::NiPoint3 &, ::NavMeshTriList **);
};
