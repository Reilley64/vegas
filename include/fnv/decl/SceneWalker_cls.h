#pragma once

#include <cstdint>

struct SceneNode_cls;

struct SceneWalker_cls {
public:
    // 0x00ca1f00
    void TraverseSceneNode(::SceneNode_cls *, void *, void *);
};
