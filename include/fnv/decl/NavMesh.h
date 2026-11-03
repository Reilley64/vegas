#pragma once
#include <cstdint>

class NavMeshClosedDoorInfo;
class NavMeshStaticAvoidNode;
class NavMeshTriangle;
class NiPoint3;

class NavMesh {
public:
    // 0x0042fb00
    ::NavMeshStaticAvoidNode *GetStaticAvoidNodeData();
    // 0x00464ff0
    ::NavMesh *FUN_00464ff0(intptr_t);
    // 0x00558220
    ::NiPoint3 GetNavMeshData(unsigned short);
    // 0x005582f0
    ::NavMeshTriangle *GetTriangle(unsigned short);
    // 0x006942c0
    void ForceSetFormID(unsigned int);
    // 0x006971e0
    ::NiPoint3 GetPlaneNormal(unsigned short);
    // 0x00697730
    bool FindHeightOnTriangle(unsigned short, const ::NiPoint3 &, float &, float, float);
    // 0x00699af0
    ::NavMeshClosedDoorInfo *GetClosedDoorInfo(unsigned short);
};
