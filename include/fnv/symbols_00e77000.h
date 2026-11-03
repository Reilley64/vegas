#pragma once

struct ByteVertexConversion;
struct FUN_00e77590_Info;
struct FUN_00e77950_Info;
struct FUN_00e77b50_Info;
struct FUN_00e77eb0_Info;
struct PackByteInfo;
struct PackShortInfo;
struct StreamCopyInfo;

// 0x00e77010
unsigned int CopyVertexStream(::StreamCopyInfo *);
// 0x00e771f0
unsigned int CopyPackedVerts(::PackShortInfo *);
// 0x00e773b0
unsigned int PackShortVertexData(::PackShortInfo *);
// 0x00e77590
unsigned int FUN_00e77590(::FUN_00e77590_Info *);
// 0x00e77770
unsigned int ConvertVertexFormat(::ByteVertexConversion *);
// 0x00e77950
unsigned int FUN_00e77950(::FUN_00e77950_Info *);
// 0x00e77b50
unsigned int FUN_00e77b50(::FUN_00e77b50_Info *);
// 0x00e77d00
unsigned int PackByteElements(::PackByteInfo *);
// 0x00e77eb0
unsigned int FUN_00e77eb0(::FUN_00e77eb0_Info *);
