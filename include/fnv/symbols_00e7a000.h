#pragma once

struct ColorStream;
struct E7Descriptor;
struct E7Skin;
struct NiGeometryData;

// 0x00e7a0a0
unsigned int ConvertColorStream(::ColorStream *);
// 0x00e7a200
unsigned int ConvertGeometryData(unsigned short, ::NiGeometryData *, unsigned int, ::E7Skin *, ::E7Descriptor *, unsigned int, void *, bool, unsigned int);
// 0x00e7a6a0
void DestroyBucketTable();
// 0x00e7a760
bool FUN_00e7a760();
// 0x00e7a860
void FUN_00e7a860();
// 0x00e7a8b0
void FUN_00e7a8b0(int, int *, int *);
// 0x00e7acb0
int FUN_00e7acb0(int);
