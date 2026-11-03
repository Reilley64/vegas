#pragma once

#include <cstdint>

class CollisionAgentContext;
class hkpCdBody;
class hkpCdBodyPairCollector;
namespace fnv_00d442c0 { class D442C0Agent; }
struct Agent;
struct Input_d2e9;
struct RegistryOwner;

// 0x00d44280
namespace fnv_00d44280 { void AllocateAndInitBlock(intptr_t, intptr_t, intptr_t, intptr_t); }
// 0x00d442c0
namespace fnv_00d442c0 { ::fnv_00d442c0::D442C0Agent *FUN_00d442c0(const void *, const void *, const void *, void *); }
// 0x00d44310
void FUN_00d44310(::Agent *);
// 0x00d445e0
void FUN_00d445e0(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdBodyPairCollector &);
// 0x00d447f0
void ProcessMultiSphereCollision(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, void *, void *);
// 0x00d449f0
void FUN_00d449f0(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdBodyPairCollector &);
// 0x00d44cc0
void FUN_00d44cc0(int, int, int, int);
// 0x00d44d00
void *FUN_00d44d00(int, int, int, int);
// 0x00d44d50
void RegisterTwoTables(::RegistryOwner *);
// 0x00d44de0
void FUN_00d44de0(void *, void *, void *, unsigned int);
// 0x00d44e20
void FUN_00d44e20(void *, void *, void *, int);
// 0x00d44e60
void FUN_00d44e60(int, int, const ::Input_d2e9 *, int, int);
