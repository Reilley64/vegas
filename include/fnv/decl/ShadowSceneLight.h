#pragma once

class NiAVObject;
struct NiSphere;

class ShadowSceneLight {
public:
    // 0x00b9bbb0
    bool TestSphereFrustum(const ::NiSphere &);
    // 0x00b9fda0
    ShadowSceneLight();
    // 0x00ba0110
    void AddObject(::NiAVObject *);
};
