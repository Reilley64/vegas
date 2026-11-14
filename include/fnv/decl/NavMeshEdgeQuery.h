#pragma once
#include <cstdint>

class NavMesh;
template <class> class NiPointer;

class NavMeshEdgeQuery {
public:
    // 0x0068f3b0
    bool FUN_0068f3b0(unsigned short, int, ::NiPointer< ::NavMesh> &, std::intptr_t, int);
};
