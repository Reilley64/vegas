#pragma once

class NiPoint3;
struct tagRECT;

// 0x004b10d0
short GetShortFromTable(int);
// 0x004b1230
int IsIntegerString(const char *);
// 0x004b12d0
int FUN_004b12d0(char *);
// 0x004b13c0
float GetDirectionAngle(const ::NiPoint3 *);
// 0x004b1460
float FUN_004b1460(float);
// 0x004b1480
float WrapAngle(float);
// 0x004b1500
float FUN_004b1500(float, float);
// 0x004b1520
float FUN_004b1520(float, float);
// 0x004b1550
float GetAngleFromVector(const ::NiPoint3 &);
// 0x004b15e0
float FUN_004b15e0(float, float, float *);
// 0x004b1680
int MapByteToIndex(unsigned char);
// 0x004b1b60
const char *FUN_004b1b60(unsigned char);
// 0x004b1e80
bool FUN_004b1e80(const ::tagRECT *, const ::NiPoint3 *, const ::NiPoint3 *, ::NiPoint3 *);
