#pragma once

struct Node_00b98e20;
struct ShaderPassEntry;

// 0x00b98070
void UpdateRendererStateCount(bool, int);
// 0x00b980c0
void FUN_00b980c0(int, int, int, int);
// 0x00b98180
void FUN_00b98180(int, int, int, int);
// 0x00b98230
void AddToSlot(void *, int);
// 0x00b98280
void UpdateSpawnedObjectFlags(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int);
// 0x00b98320
namespace fnv_00b98320 { void SendFloatAdd(float, int); }
// 0x00b98480
void FUN_00b98480(char, int);
// 0x00b984d0
void FUN_00b984d0(int);
// 0x00b98540
namespace fnv_00b98540 { void FUN_00b98540(bool, int); }
// 0x00b988e0
namespace fnv_00b988e0 { void FUN_00b988e0(); }
// 0x00b98b20
int CompareSortPassesByDepth(const void *, const void *);
// 0x00b98e20
void FUN_00b98e20(::Node_00b98e20 *, int, const unsigned short *);
// 0x00b98e80
void DrawGeometryPass(::ShaderPassEntry *, bool, bool, bool);
