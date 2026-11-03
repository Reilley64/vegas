#pragma once

class hkVector4;
struct Point4;
struct VectorPairResult;

// 0x00d22120
int FUN_00d22120(void *, void *, void *);
// 0x00d224c0
void FUN_00d224c0(float *, float *, float *, float *);
// 0x00d22700
void GetClosestLinePoints(const ::Point4 &, const ::Point4 &, const ::Point4 &, const ::Point4 &, float *, float *, float *, ::Point4 *, ::Point4 *);
// 0x00d22e40
int FUN_00d22e40(const ::hkVector4 &, const ::hkVector4 &, const ::hkVector4 &, const ::hkVector4 &, ::VectorPairResult &);
