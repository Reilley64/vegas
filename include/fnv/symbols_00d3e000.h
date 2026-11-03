#pragma once

struct CollisionAgentContext;
struct D3E270_obj;
struct S_00d3ef70_CdBody;
struct S_00d3ef70_Collector;
struct S_00d3ef70_Dispatcher;
struct S_00d3ef70_Input;
struct hkpCdBody;
struct hkpCdPointCollector;

// 0x00d3e110
void FUN_00d3e110(const void *, const void *, const void *, void *);
// 0x00d3e270
::D3E270_obj *FUN_00d3e270(int, int, int, int);
// 0x00d3e2f0
void FUN_00d3e2f0(int, int, int, int);
// 0x00d3e330
void FUN_00d3e330(const ::S_00d3ef70_CdBody &, const ::S_00d3ef70_CdBody &, const ::S_00d3ef70_Input &, ::S_00d3ef70_Collector &);
// 0x00d3e510
void FUN_00d3e510(const void *, const void *, const void *, void *);
// 0x00d3e850
namespace fnv_00d3e850 { struct hkpCdBody; struct CollisionAgentContext; struct hkpCdPointCollector; void FUN_00d3e850(const ::fnv_00d3e850::hkpCdBody &, const ::fnv_00d3e850::hkpCdBody &, const ::fnv_00d3e850::CollisionAgentContext &, ::fnv_00d3e850::hkpCdPointCollector &); }
// 0x00d3ef70
void FUN_00d3ef70(::S_00d3ef70_Dispatcher *);
