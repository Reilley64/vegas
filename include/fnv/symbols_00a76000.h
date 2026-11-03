#pragma once
#include <cstdint>

class NiImageConverter;
struct Fmt;
struct NiPalette;
struct NiPixelFormatA775;
struct PixelConvertFormat;
struct PixelFormatBitLayout;

// 0x00a768b0
char *GetPathWithExtension(const char *);
// 0x00a76960
namespace fnv_00a76960 { void FUN_00a76960(char **, char **); }
// 0x00a76b30
namespace fnv_00a76b30 { void FUN_00a76b30(); }
// 0x00a76b60
namespace fnv_00a76b60 { void AssignImageConverter(::NiImageConverter *); }
// 0x00a76d70
void FUN_00a76d70(unsigned int, unsigned int, unsigned int, unsigned char *, uintptr_t, const ::Fmt *, const unsigned char *, const ::Fmt *);
// 0x00a76e90
void FUN_00a76e90(unsigned int, unsigned int, unsigned int, unsigned char *, const ::NiPalette *, const ::PixelFormatBitLayout &, const unsigned char *, const ::PixelFormatBitLayout &);
// 0x00a76ea0
void ConvertPixelsTo16Bit(unsigned int, unsigned int, unsigned int, unsigned short *, unsigned int, const ::PixelConvertFormat *, const unsigned char *, const ::PixelConvertFormat *);
// 0x00a76f80
void ConvertRGBToFormat(unsigned int, unsigned int, unsigned int, unsigned int *, unsigned int, const ::NiPixelFormatA775 *, const unsigned char *, unsigned int);
