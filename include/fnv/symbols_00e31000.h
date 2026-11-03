#pragma once

namespace SplineMax { struct Points; }
namespace SplineMax { struct Vec; }
namespace fnv_00e31800 { struct Buf; }
namespace fnv_00e31850 { struct BufferInfo; }
namespace fnv_00e318a0 { struct FUN_00e318a0_buf; }
namespace fnv_00e31ad0 { struct Buffer; }
struct E317C0CharArray;
struct Mat34;
struct MemWriter;
struct MinVec4;
struct MinVec4Array;
struct S00e311f0_PA;
struct S00e311f0_PB;
struct S00e311f0_T;
struct S00e311f0_V;
struct hkVector4Stub;

// 0x00e31010
void AlignAndAdvance(char, int, int, int *);
// 0x00e310c0
void FUN_00e310c0(const ::Mat34 *, int, int, int, int, ::hkVector4Stub **, ::hkVector4Stub **, ::hkVector4Stub **);
// 0x00e311f0
unsigned char FUN_00e311f0(::S00e311f0_PA, ::S00e311f0_PB, const ::S00e311f0_V *, ::S00e311f0_T, const ::S00e311f0_V *);
// 0x00e31470
::MinVec4 FUN_00e31470(const ::MinVec4Array &);
// 0x00e314c0
::SplineMax::Vec FUN_00e314c0(const ::SplineMax::Points &);
// 0x00e31510
void SwapBytesAndAdvance(int, unsigned char **);
// 0x00e31570
namespace fnv_00e31570 { unsigned int FUN_00e31570(unsigned char, unsigned int *); }
// 0x00e315a0
void FUN_00e315a0(unsigned char, unsigned int, unsigned int, unsigned int *);
// 0x00e31650
void FillInterpolatedValues(int, float **, float, float);
// 0x00e31740
void FUN_00e31740(unsigned char, unsigned int, unsigned int *);
// 0x00e31780
void FUN_00e31780(int, int, int *);
// 0x00e317c0
void AppendChar(char, ::E317C0CharArray &);
// 0x00e31800
namespace fnv_00e31800 { void FUN_00e31800(int, ::fnv_00e31800::Buf *); }
// 0x00e31850
namespace fnv_00e31850 { void FUN_00e31850(unsigned int, ::fnv_00e31850::BufferInfo *); }
// 0x00e318a0
namespace fnv_00e318a0 { void FUN_00e318a0(unsigned int, ::fnv_00e318a0::FUN_00e318a0_buf *); }
// 0x00e31ad0
namespace fnv_00e31ad0 { void WriteUInt16ToBuffer(unsigned short, ::fnv_00e31ad0::Buffer *); }
// 0x00e31b00
void WriteFloatToMemWriter(float, ::MemWriter *);
