#pragma once

struct ShadowSceneNode;

class NiAdditionalGeometryData {
public:
    // 0x00450b80
    static ::ShadowSceneNode *GetShadowSceneNodeForIndex(int);
};
