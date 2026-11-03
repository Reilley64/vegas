#pragma once

class BSFaceGenAnimationData;

class BSFaceGenNiNode {
public:
    // 0x00439920
    void SetAnimationData(::BSFaceGenAnimationData *);
    // 0x006629f0
    ::BSFaceGenAnimationData *GetAnimationData();
    // 0x0097ce70
    void SetApplyRotToParent(bool);
};
