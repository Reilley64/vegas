#pragma once

struct E05F60Header;
struct hkHeaderE05E;

// 0x00e05e20
void SwapHeaderBytesAndAdvance(unsigned char *);
// 0x00e05e50
void SwapQuadBytes(unsigned char *);
// 0x00e05eb0
void FUN_00e05eb0(unsigned char *);
// 0x00e05ef0
void SwapHkHeaderE05E(::hkHeaderE05E *);
// 0x00e05f60
void SwapHeaderEndianness(::E05F60Header *);
// 0x00e05fe0
void FUN_00e05fe0(unsigned char *);
