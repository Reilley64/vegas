#pragma once

struct ByteFloatStream;
struct FUN_00e79370_Info;
struct FUN_00e79f40_Stream;
struct NormalizedStream;
struct PixRow_00e79760;

// 0x00e79160
unsigned int DecodeVertexData(::NormalizedStream *);
// 0x00e79370
unsigned int FUN_00e79370(::FUN_00e79370_Info *);
// 0x00e79540
unsigned int ConvertNormalizedShortsToFloats(::NormalizedStream *);
// 0x00e79760
unsigned int FUN_00e79760(::PixRow_00e79760 *);
// 0x00e79920
unsigned int ConvertByteFloatStream(::ByteFloatStream *);
// 0x00e79b40
unsigned int NormalizeVertexStream(::NormalizedStream *);
// 0x00e79d00
unsigned int FUN_00e79d00(::NormalizedStream *);
// 0x00e79f40
int FUN_00e79f40(::FUN_00e79f40_Stream *);
