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
void FUN_00d3e510(int, int, int, int);
// 0x00d3e850
void FUN_00d3e850(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdPointCollector &);
// 0x00d3ef70
void FUN_00d3ef70(::S_00d3ef70_Dispatcher *);
