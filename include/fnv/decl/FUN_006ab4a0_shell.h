#pragma once
#include <cstdint>

class PathBuilderDetailedPathInfos;
class PathingLocation;
struct NavMeshSearchLocation;

struct FUN_006ab4a0_shell {
public:
    // 0x006ab4a0
    bool StartSearch(std::intptr_t, ::NavMeshSearchLocation *, ::PathingLocation *, ::PathBuilderDetailedPathInfos *, ::PathBuilderDetailedPathInfos *);
};
