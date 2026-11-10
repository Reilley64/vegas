#pragma once

class NiAVObject;
class NiLight;
struct NiPoint3;

struct ShadowSceneNode {
public:
    // 0x00b5b4d0
    float CalculateLightingAtPoint(::NiPoint3, int &, float &, float &, ::NiLight *);
    // 0x00b5c3c0
    void UpdateShadowLights();
    // 0x00b5eeb0
    void AddObject(::NiAVObject *);
};
