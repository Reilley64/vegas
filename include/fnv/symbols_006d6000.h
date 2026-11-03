#pragma once

struct GeometrySource;
struct OutputList;

// 0x006d6200
bool GetObjectFloat(void *, void *, float *);
// 0x006d62c0
void *CallWithNullArgs(void *, void *, void *);
// 0x006d62e0
unsigned int FindNearbyTriangles(::GeometrySource *, ::OutputList *);
// 0x006d6f40
void FUN_006d6f40(void *);
// 0x006d6f60
namespace fnv_006d6f60 { void ForwardToPathing(void *, void *); }
