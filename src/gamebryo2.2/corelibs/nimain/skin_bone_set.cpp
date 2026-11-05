#include "fnv/skin_bone_set.h"

// @fnv 0x00a82190
bool fnv::ContainsSortedSkinBones(SkinBoneSetView source, SkinBoneSetView subset)
{
    unsigned int src = 0;
    for (unsigned int dst = 0; dst < subset.count; ++dst)
    {
        while (src < source.count && source.data[src] < subset.data[dst])
            ++src;
        if (src == source.count)
            return false;
        if (source.data[src] != subset.data[dst])
            return false;
        ++src;
    }
    return true;
}
