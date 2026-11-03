#pragma once

struct MeanCovObbFlag;
struct MeanCovObbRot;
struct MeanCovObbStride;
struct MeanCovObbVec;
struct S00d5c060_Result;
struct S00d5c060_Src;

// 0x00d5c060
::S00d5c060_Result FUN_00d5c060(const ::S00d5c060_Src *, float);
// 0x00d5c1a0
extern "C" void FUN_00d5c1a0(const void *, int, ::MeanCovObbStride, ::MeanCovObbRot *, ::MeanCovObbVec *, ::MeanCovObbFlag);
