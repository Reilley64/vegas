#pragma once

class NavMeshPtr;

class NavMeshInfo {
public:
    // 0x00690860
    bool AcquireNavMesh(::NavMeshPtr &);
    // 0x0069ad00
    bool ResolveNavMesh(::NavMeshPtr &);
    // 0x006b46a0
    NavMeshInfo();
};
