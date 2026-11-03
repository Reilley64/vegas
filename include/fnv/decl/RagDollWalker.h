#pragma once

class NiNode;

struct RagDollWalker {
public:
    // 0x004d9bd0
    bool CollectBoneTransforms(::NiNode *, unsigned int &, bool);
};
