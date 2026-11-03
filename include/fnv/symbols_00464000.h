#pragma once

#include <cstdint>

class NavMesh;
template <class> class NiPointer;

// 0x00464f30
int FUN_00464f30(std::intptr_t);
// 0x00464fc0
::NiPointer< ::NavMesh> MakeNavMeshPointer(::NavMesh *);
