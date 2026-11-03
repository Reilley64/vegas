#pragma once

#include <cstdint>

namespace fnv_00d343f0 { class hkpCollisionAgentD343; }
namespace fnv_00d343f0 { struct hkpCdBodyD343; }
namespace fnv_00d343f0 { struct hkpCollisionInputD343; }
namespace fnv_00d343f0 { struct hkpContactMgrD343; }
namespace fnv_00d34510 { struct AgentCollisionInput; }
namespace fnv_00d34810 { struct Input_d2e9; }
namespace fnv_00d349b0 { struct Input_d2e9; }
struct hkpConvexListAgent;

// 0x00d343f0
namespace fnv_00d343f0 { ::fnv_00d343f0::hkpCollisionAgentD343 *FUN_00d343f0(const ::fnv_00d343f0::hkpCdBodyD343 &, const ::fnv_00d343f0::hkpCdBodyD343 &, const ::fnv_00d343f0::hkpCollisionInputD343 &, ::fnv_00d343f0::hkpContactMgrD343 *); }
// 0x00d34510
namespace fnv_00d34510 { void *FUN_00d34510(void *, void *, ::fnv_00d34510::AgentCollisionInput *, void *); }
// 0x00d346b0
void RegisterConvexListAgentCollisionFuncs(::hkpConvexListAgent *);
// 0x00d34790
void FUN_00d34790(void *, void *, void *, int);
// 0x00d347d0
void QueryClosestPoints(void *, void *, void *, unsigned int);
// 0x00d34810
namespace fnv_00d34810 { void FUN_00d34810(intptr_t, intptr_t, const ::fnv_00d34810::Input_d2e9 *, int, int); }
// 0x00d34930
void InitSpawnedBuffer(intptr_t, intptr_t, intptr_t, int);
// 0x00d34970
void FUN_00d34970(int, int, int, int);
// 0x00d349b0
namespace fnv_00d349b0 { void FUN_00d349b0(intptr_t, intptr_t, const ::fnv_00d349b0::Input_d2e9 *, int, int); }
// 0x00d34d30
void FUN_00d34d30(void *, void *, void *, void *);
// 0x00d34d60
void ForwardCall(int, intptr_t, intptr_t);
// 0x00d34d80
void FUN_00d34d80(void *, void *, float, float, void *);
// 0x00d34db0
void FUN_00d34db0(void *, void *, void *, void *, void *, void *, void *);
