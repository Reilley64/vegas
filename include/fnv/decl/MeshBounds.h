#pragma once

struct MeshPoint;

class MeshBounds {
public:
    // 0x0069bea0
    bool ContainsPoint(const ::MeshPoint *);
};
