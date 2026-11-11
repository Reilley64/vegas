#ifndef VEGAS_FILEFORMAT_DDS_HEADER_H
#define VEGAS_FILEFORMAT_DDS_HEADER_H

#include <cstddef>
#include <cstdint>
#include <span>

namespace fileformat
{

// Direct3D 9 surface formats that the public DDS programming guide gives
// header content for. The values are those of the public D3DFORMAT
// enumeration; the last nine are their own four-character codes.
enum class DdsFormat : std::uint32_t
{
    R8G8B8 = 20,
    A8R8G8B8 = 21,
    X8R8G8B8 = 22,
    R5G6B5 = 23,
    X1R5G5B5 = 24,
    A1R5G5B5 = 25,
    A4R4G4B4 = 26,
    A8 = 28,
    A8R3G3B2 = 29,
    X4R4G4B4 = 30,
    A8B8G8R8 = 32,
    X8B8G8R8 = 33,
    G16R16 = 34,
    A16B16G16R16 = 36,
    L8 = 50,
    A8L8 = 51,
    A4L4 = 52,
    L16 = 81,
    Q16W16V16U16 = 110,
    R16F = 111,
    G16R16F = 112,
    A16B16G16R16F = 113,
    R32F = 114,
    G32R32F = 115,
    A32B32G32R32F = 116,
    CxV8U8 = 117,
    Dxt1 = 0x31545844,
    Dxt2 = 0x32545844,
    Dxt3 = 0x33545844,
    Dxt4 = 0x34545844,
    Dxt5 = 0x35545844,
    Uyvy = 0x59565955,
    Yuy2 = 0x32595559,
    R8G8B8G8 = 0x47424752, // "RGBG"
    G8R8G8B8 = 0x42475247, // "GRGB"
};

// The values are those of the public D3DRESOURCETYPE enumeration.
enum class DdsResource : std::uint32_t
{
    Texture = 3,
    Volume = 4,
    Cube = 5,
};

// What the header of a DDS file says about its image. Width, height, depth
// and the mip level count are reported as stored, with only the checks listed
// at ReadDdsImageInfo: a consumer must bound them before it sizes or indexes
// anything with them.
struct DdsImageInfo
{
    std::uint32_t width;
    std::uint32_t height;
    std::uint32_t depth;     // 1 unless the file is a volume
    std::uint32_t mipLevels; // 1 when the header counts none
    DdsFormat format;
    DdsResource resource;
};

// Reads the magic number and header at the start of a DDS file. Throws
// FormatError when the bytes are not a DDS header or name a pixel format
// outside DdsFormat. The pixel data after the header is not read.
//
// Validated: at least 128 bytes, the magic number, header size 124, pixel
// format size 32, a pixel format of DdsFormat, a non-zero width and height,
// a non-zero depth for a volume, and not both a cube map and a volume.
// Trusted as stored: the values of width, height, depth and the mip level
// count (no upper bound, no check of the count against the dimensions, no
// check that the file holds the pixel data they imply). Not read: the cube
// map face flags (a cube map with fewer than six faces is reported as a cube
// map), the pitch or linear size, the first capability word and every header
// flag but the mip level count flag. The mip level count is the stored count
// when that flag is set and the count is not zero, and 1 otherwise; the
// public header page advises not to rely on that flag, so this rule is a
// decision to settle before a caller is bound.
DdsImageInfo ReadDdsImageInfo(std::span<const std::byte> file);

} // namespace fileformat

#endif
