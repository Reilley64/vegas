#pragma once

#include <cstdint>

class hkpCdBody;
class hkpCdPointCollector;
namespace fnv_00d37da0 { struct S_00d37da0_Agent; }
namespace fnv_00d37da0 { struct S_00d37da0_CdBody; }
struct CollisionAgentContext;
struct RayBody;
struct RayCollector;
struct S_00d374f0_CdBody;
struct S_00d374f0_Collector;
struct S_00d37e60_Agent;
struct S_00d37e60_CdBody;

// 0x00d37010
void FUN_00d37010(const ::RayBody *, const ::RayBody *, void *, ::RayCollector *);
// 0x00d37280
void FUN_00d37280(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdPointCollector &);
// 0x00d374f0
void FUN_00d374f0(const ::S_00d374f0_CdBody &, const ::S_00d374f0_CdBody &, int, ::S_00d374f0_Collector *);
// 0x00d37740
namespace fnv_00d37740 { void FUN_00d37740(int, int, int, int); }
// 0x00d37780
namespace fnv_00d37780 { void *FUN_00d37780_impl(int, int, int, int); }
// 0x00d377d0
void FUN_00d377d0(intptr_t);
// 0x00d37860
void FUN_00d37860(void *, void *, void *, int);
// 0x00d37da0
namespace fnv_00d37da0 { ::fnv_00d37da0::S_00d37da0_Agent *CreateTriAgent(const void *, const ::fnv_00d37da0::S_00d37da0_CdBody &, const void *, void *); }
// 0x00d37e60
::S_00d37e60_Agent *CreateTriAgent2(const ::S_00d37e60_CdBody &, const ::S_00d37e60_CdBody &, const void *, void *);
