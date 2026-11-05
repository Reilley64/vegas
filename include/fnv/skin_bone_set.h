#pragma once

namespace fnv {

// Borrows count readable unsigned-short elements in nondecreasing order.
struct SkinBoneSetView
{
    const unsigned short* data;
    unsigned int count;
};

// Each matching element is consumed once, including duplicate values.
bool ContainsSortedSkinBones(SkinBoneSetView source, SkinBoneSetView subset);

}  // namespace fnv
