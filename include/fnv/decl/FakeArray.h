#pragma once

struct InstanceData;
struct NavMeshEdgePoint;

struct FakeArray {
public:
    // 0x006db400
    unsigned int FUN_006db400(const ::NavMeshEdgePoint &);
    // 0x006f9800
    unsigned int AppendInstance(::InstanceData *);
    // 0x006f9f60
    void ResizeAndFill(unsigned int, unsigned int);
};
