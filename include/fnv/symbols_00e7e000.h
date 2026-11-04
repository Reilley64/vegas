#pragma once
#include <cstdint>

namespace fnv_00e7e880 { class SpawnedObject; }
struct StageReturn;

// 0x00e7e7a0
namespace fnv_00e7e7a0 { void *FUN_00e7e7a0(void *, int, unsigned int); }
// 0x00e7e880
namespace fnv_00e7e880 { ::fnv_00e7e880::SpawnedObject *FUN_00e7e880(unsigned int); }
// 0x00e7e8d0
void FUN_00e7e8d0(intptr_t);
// 0x00e7ec90
void CreateStagePool();
// 0x00e7ed80
namespace fnv_00e7ed80 { void DestroyStagePool(); }
// 0x00e7edf0
void AssignStageFromPool(::StageReturn *&);
