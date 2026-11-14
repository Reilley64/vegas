#pragma once
#include <cstdint>

class NiPixelFormat;
namespace fnv_00a8cc40 { struct NiBinaryStream; }
namespace fnv_00a8cc40 { struct NiPixelData; }
struct BinaryStreamView;
struct ImgObj;
struct PixelDataView;
struct ReadCtx;

// 0x00a8c100
bool IsValidBitDepth(intptr_t, int, int, int, unsigned int);
// 0x00a8c120
::NiPixelFormat NormalizePixelFormat(::NiPixelFormat);
// 0x00a8c6e0
void FUN_00a8c6e0(::ReadCtx *, ::ImgObj *, ::NiPixelFormat, ::NiPixelFormat, unsigned int, unsigned int);
// 0x00a8c7a0
void FUN_00a8c7a0(::BinaryStreamView *, ::PixelDataView *, ::NiPixelFormat, ::NiPixelFormat, unsigned int, unsigned int);
// 0x00a8cc40
namespace fnv_00a8cc40 { void FUN_00a8cc40(::fnv_00a8cc40::NiBinaryStream *, ::fnv_00a8cc40::NiPixelData *, ::NiPixelFormat, ::NiPixelFormat, unsigned int, unsigned int); }
