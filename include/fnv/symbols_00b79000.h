#pragma once

class NiRefObject;
struct GO;
struct NiD3DPass;
struct Params;

// 0x00b79050
void ResetTransform(int);
// 0x00b790d0
void UpdateScaledValue(const char *);
// 0x00b79100
void FUN_00b79100(int);
// 0x00b79180
void FUN_00b79180(void *);
// 0x00b791f0
void FUN_00b791f0(unsigned int, ::Params *, ::Params *);
// 0x00b79410
void FUN_00b79410(unsigned int, unsigned char *);
// 0x00b796f0
void FUN_00b796f0(const char *);
// 0x00b79730
void UpdatePlaneFromPoint();
// 0x00b798c0
void FUN_00b798c0(const float *);
// 0x00b79930
void FUN_00b79930(::NiD3DPass **);
// 0x00b79950
void FUN_00b79950(char *, int, ::NiRefObject *);
// 0x00b799a0
void FUN_00b799a0(float *, const char *);
// 0x00b79a60
::GO *AllocateGOArray(unsigned int);
