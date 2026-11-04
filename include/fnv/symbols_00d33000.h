#pragma once

#include <cstdint>

class hkpCollisionAgentD33D;
class hkpCollisionDispatcherD331;
struct hkpCdBodyD33D;
struct hkpCollisionInputD33D;
struct hkpContactMgrD33D;

// 0x00d33140
void FUN_00d33140(struct hkpAgent3FuncsD331 *);
// 0x00d331a0
void RegisterAgent3Entries(::hkpCollisionDispatcherD331 *);
// 0x00d339d0
extern "C" void FUN_00d339d0(const void *, const void *, const void *, void *);
// 0x00d33b90
extern "C" void FUN_00d33b90(void *, void *, void *, void *);
// 0x00d33ca0
namespace fnv_00d33ca0 { extern "C" void FUN_00d33ca0(const void *, const void *, const void *, void *, void *); }
// 0x00d33da0
void *FUN_00d33da0(void *, void *, void *, void *, void *);
// 0x00d33dd0
void *CreateConvexListAgent(const ::hkpCdBodyD33D &, const ::hkpCdBodyD33D &, const ::hkpCollisionInputD33D &, ::hkpContactMgrD33D *);
