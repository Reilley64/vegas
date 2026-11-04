#pragma once

class NiCullingProcess;

struct CullerOwner {
public:
    // 0x00b9d020
    bool CullSceneObjects(::NiCullingProcess &);
};
