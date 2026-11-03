#pragma once

struct A77740Format;
struct BitPackDesc;
struct BitPackLayout;
struct FUN_00a77110_info;
struct FnvPixelFormat;
struct NiPixelChannelsA773;
struct NiPixelChannelsA776;
struct NiPixelChannelsA77;
struct NiPixelFormatA775;
struct PixelChannels;
struct S_00a77800_Layout;

// 0x00a77040
void ConvertRGBAToPacked(unsigned int, unsigned int, unsigned int, unsigned char *, const void *, const ::NiPixelFormatA775 &, const unsigned char *, const ::NiPixelFormatA775 &);
// 0x00a77110
void FUN_00a77110(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int, ::FUN_00a77110_info *, const unsigned char *);
// 0x00a771d0
void FUN_00a771d0(unsigned int, unsigned int, unsigned int, unsigned int *, unsigned int, const ::NiPixelFormatA775 *, const unsigned char *, const ::NiPixelFormatA775 &);
// 0x00a772b0
void UnpackPixels(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int, unsigned int, unsigned int, const ::BitPackLayout *);
// 0x00a77330
void ConvertPixelsToBytes(unsigned int, unsigned int, unsigned int, char *, unsigned int, void *, unsigned short *, ::FnvPixelFormat *);
// 0x00a773d0
void FUN_00a773d0(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int, unsigned int, const unsigned short *, const ::NiPixelChannelsA773 *);
// 0x00a77460
namespace fnv_00a77460 { void ConvertRgbToRgba(unsigned int, unsigned int, int, unsigned char *, int, int, const unsigned char *, const unsigned int *); }
// 0x00a77510
void ConvertPixelsToRgb(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int, unsigned int, const unsigned int *, const ::NiPixelChannelsA77 *);
// 0x00a77590
void ConvertPixelFormat(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int, unsigned int, const unsigned char *, const ::NiPixelFormatA775 *);
// 0x00a77630
void ConvertPackedPixelsToRGBA(unsigned int, unsigned int, unsigned int, char *, unsigned int, unsigned int, const unsigned int *, const ::PixelChannels *);
// 0x00a776b0
void FUN_00a776b0(unsigned int, unsigned int, unsigned int, unsigned int *, unsigned int, const ::NiPixelChannelsA776 *, const unsigned char *, const ::NiPixelChannelsA776 *);
// 0x00a77740
void ConvertRgbToPacked16(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int, const ::A77740Format *, const unsigned char *);
// 0x00a77800
void FUN_00a77800(unsigned int, unsigned int, unsigned int, unsigned int *, unsigned int, const ::S_00a77800_Layout *, const unsigned char *);
// 0x00a77880
void FUN_00a77880(unsigned int, unsigned int, void *, unsigned short *, void *, ::BitPackDesc *, const unsigned char *, void *);
// 0x00a77920
bool FUN_00a77920(int);
