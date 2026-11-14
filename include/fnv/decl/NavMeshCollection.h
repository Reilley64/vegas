#pragma once

class NavMesh;
template <class> class NiPointer;

class NavMeshCollection {
public:
    // 0x00464f60
    ::NiPointer< ::NavMesh> GetNavMeshAt(unsigned int);
};
