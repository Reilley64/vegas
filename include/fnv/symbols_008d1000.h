#pragma once
#include <cstdint>

class NiPoint3;
struct MatrixView;
struct SourceData;
struct TargetOwner;

// 0x008d1030
void ClearField44(intptr_t);
// 0x008d12e0
void FUN_008d12e0(::TargetOwner *, ::SourceData *, int, int);
// 0x008d1560
void FUN_008d1560();
// 0x008d15b0
void FUN_008d15b0(const void *);
// 0x008d1820
void InitializeCameraShake();
// 0x008d1920
void FUN_008d1920();
// 0x008d1960
void UpdateDistanceFade(float, const ::NiPoint3 &);
// 0x008d1b30
float UpdateCameraShake(float, ::MatrixView *);
// 0x008d1cf0
float FUN_008d1cf0();
// 0x008d1d00
float FUN_008d1d00();
