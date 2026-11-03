#pragma once
#include <cstdint>

class NavMesh;
template <class> class NiPointer;

// 0x00464f30
intptr_t FUN_00464f30(intptr_t);
// 0x00464fc0
::NiPointer< ::NavMesh> MakeNavMeshPointer(::NavMesh *);
