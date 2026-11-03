#pragma once

class BSFaceGenNiNode;
class BipedAnim;
class TESObjectREFR;

struct TESNPC_Sub {
public:
    // 0x00607420
    void AttachHeadModels(::TESObjectREFR *, ::BipedAnim *, ::BSFaceGenNiNode *, ::BSFaceGenNiNode *);
};
