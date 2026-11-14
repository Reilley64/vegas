#include "check.h"
#include "fnv/skin_bone_set.h"

int main()
{
    Checks checks("runtime.skin_bone_set");
    const fnv::SkinBoneSetView empty{nullptr, 0};
    const unsigned short source[]{1, 3, 3, 7, 65535};
    const fnv::SkinBoneSetView all{source, 5};
    const unsigned short subset[]{3, 7};
    const unsigned short missing[]{1, 4};
    const unsigned short before[]{0};
    const unsigned short after[]{65535, 65535};
    const unsigned short duplicates[]{3, 3};
    const unsigned short excessDuplicates[]{3, 3, 3};
    checks.Equal("empty contains empty", true, fnv::ContainsSortedSkinBones(empty, empty));
    checks.Equal("nonempty contains empty", true, fnv::ContainsSortedSkinBones(all, empty));
    checks.Equal("empty misses nonempty", false, fnv::ContainsSortedSkinBones(empty, all));
    checks.Equal("equal ranges", true, fnv::ContainsSortedSkinBones(all, all));
    checks.Equal("proper subset", true, fnv::ContainsSortedSkinBones(all, {subset, 2}));
    checks.Equal("missing middle value", false, fnv::ContainsSortedSkinBones(all, {missing, 2}));
    checks.Equal("missing first value", false, fnv::ContainsSortedSkinBones(all, {before, 1}));
    checks.Equal("source exhausted", false, fnv::ContainsSortedSkinBones(all, {after, 2}));
    checks.Equal("duplicates consume separate matches", true,
                 fnv::ContainsSortedSkinBones(all, {duplicates, 2}));
    checks.Equal("too many duplicates", false,
                 fnv::ContainsSortedSkinBones(all, {excessDuplicates, 3}));
    checks.Equal("count limits the readable range", true,
                 fnv::ContainsSortedSkinBones({source + 1, 2}, {duplicates, 2}));
    checks.Equal("maximum unsigned short is an element", true,
                 fnv::ContainsSortedSkinBones(all, {source + 4, 1}));
    return checks.ExitCode();
}
