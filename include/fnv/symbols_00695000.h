#pragma once
#include <cstdint>

// 0x00695390
void *MemsetWrapper(void *, int, unsigned int);
// 0x006953b0
void RemoveNavMeshId(std::uintptr_t);
