#include "fileformat/dds_header.h"

#include "fileformat/byte_reader.h"

#include <array>
#include <string_view>

namespace fileformat
{

namespace
{

constexpr std::string_view format = "DDS header";

// Pixel format flags.
constexpr std::uint32_t AlphaPixels = 0x1;
constexpr std::uint32_t Alpha = 0x2;
constexpr std::uint32_t FourCC = 0x4;
constexpr std::uint32_t Rgb = 0x40;
constexpr std::uint32_t Luminance = 0x20000;

// Header flag and second capability flags.
constexpr std::uint32_t HasMipMapCount = 0x20000;
constexpr std::uint32_t CubeMap = 0x200;
constexpr std::uint32_t Volume = 0x200000;

struct MaskFormat
{
    std::uint32_t kind; // Rgb, Luminance or Alpha
    std::uint32_t bits;
    std::array<std::uint32_t, 4> masks; // red, green, blue, alpha
    DdsFormat result;
};

// The uncompressed rows of the guide's table of common formats. The two
// ten-bit rows are left out: the guide marks them as written inconsistently.
constexpr MaskFormat maskFormats[] = {
    {Rgb, 32, {0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000}, DdsFormat::A8R8G8B8},
    {Rgb, 32, {0x00ff0000, 0x0000ff00, 0x000000ff, 0}, DdsFormat::X8R8G8B8},
    {Rgb, 32, {0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000}, DdsFormat::A8B8G8R8},
    {Rgb, 32, {0x000000ff, 0x0000ff00, 0x00ff0000, 0}, DdsFormat::X8B8G8R8},
    {Rgb, 32, {0x0000ffff, 0xffff0000, 0, 0}, DdsFormat::G16R16},
    {Rgb, 24, {0x00ff0000, 0x0000ff00, 0x000000ff, 0}, DdsFormat::R8G8B8},
    {Rgb, 16, {0xf800, 0x07e0, 0x001f, 0}, DdsFormat::R5G6B5},
    {Rgb, 16, {0x7c00, 0x03e0, 0x001f, 0x8000}, DdsFormat::A1R5G5B5},
    {Rgb, 16, {0x7c00, 0x03e0, 0x001f, 0}, DdsFormat::X1R5G5B5},
    {Rgb, 16, {0x0f00, 0x00f0, 0x000f, 0xf000}, DdsFormat::A4R4G4B4},
    {Rgb, 16, {0x0f00, 0x00f0, 0x000f, 0}, DdsFormat::X4R4G4B4},
    {Rgb, 16, {0x00e0, 0x001c, 0x0003, 0xff00}, DdsFormat::A8R3G3B2},
    {Luminance, 16, {0x00ff, 0, 0, 0xff00}, DdsFormat::A8L8},
    {Luminance, 16, {0xffff, 0, 0, 0}, DdsFormat::L16},
    {Luminance, 8, {0xff, 0, 0, 0}, DdsFormat::L8},
    {Luminance, 8, {0x0f, 0, 0, 0xf0}, DdsFormat::A4L4},
    {Alpha, 8, {0, 0, 0, 0xff}, DdsFormat::A8},
};

// The rows of the guide's table that name a Direct3D 9 format by code.
constexpr DdsFormat codeFormats[] = {
    DdsFormat::Dxt1,          DdsFormat::Dxt2,         DdsFormat::Dxt3,     DdsFormat::Dxt4,
    DdsFormat::Dxt5,          DdsFormat::Uyvy,         DdsFormat::Yuy2,     DdsFormat::R8G8B8G8,
    DdsFormat::G8R8G8B8,      DdsFormat::A16B16G16R16, DdsFormat::Q16W16V16U16,
    DdsFormat::R16F,          DdsFormat::G16R16F,      DdsFormat::A16B16G16R16F,
    DdsFormat::R32F,          DdsFormat::G32R32F,      DdsFormat::A32B32G32R32F,
    DdsFormat::CxV8U8,
};

DdsFormat ReadPixelFormat(ByteReader& header)
{
    if (header.U32("pixel format size") != 32)
        header.Fail("pixel format size", "is not 32");
    const std::uint32_t flags = header.U32("pixel format flags");
    const std::uint32_t code = header.U32("pixel format four-character code");
    const std::uint32_t bits = header.U32("pixel format bit count");
    std::array<std::uint32_t, 4> masks{};
    for (std::uint32_t& mask : masks)
        mask = header.U32("pixel format masks");

    if (flags & FourCC)
    {
        for (const DdsFormat known : codeFormats)
            if (code == static_cast<std::uint32_t>(known))
                return known;
        header.Fail("pixel format four-character code", "is not a supported format");
    }

    // Only the masks that the flags declare valid are compared.
    const std::uint32_t kind = flags & (Rgb | Luminance | Alpha);
    if (kind == Rgb && !(flags & AlphaPixels))
        masks[3] = 0;
    if (kind == Alpha)
        masks[0] = masks[1] = masks[2] = 0;
    for (const MaskFormat& known : maskFormats)
        if (known.kind == kind && known.bits == bits && known.masks == masks)
            return known.result;
    header.Fail("pixel format masks", "are not a supported format");
}

} // namespace

DdsImageInfo ReadDdsImageInfo(std::span<const std::byte> file)
{
    ByteReader reader(file, format);
    if (reader.Tag("magic number") != "DDS ")
        reader.Fail("magic number", "is not 'DDS '");
    if (reader.U32("header size") != 124)
        reader.Fail("header size", "is not 124");
    ByteReader header = reader.Sub(120, "header");

    DdsImageInfo info{};
    const std::uint32_t flags = header.U32("flags");
    info.height = header.U32("height");
    info.width = header.U32("width");
    header.U32("pitch or linear size");
    const std::uint32_t depth = header.U32("depth");
    const std::uint32_t mipMapCount = header.U32("mipmap count");
    header.Take(11 * 4, "reserved words");
    info.format = ReadPixelFormat(header);
    header.U32("capabilities");
    const std::uint32_t capabilities2 = header.U32("second capabilities");
    header.Take(3 * 4, "unused capabilities and reserved word");
    header.Finish("header");

    if (info.width == 0)
        reader.Fail("width", "is zero");
    if (info.height == 0)
        reader.Fail("height", "is zero");
    if ((capabilities2 & CubeMap) && (capabilities2 & Volume))
        reader.Fail("second capabilities", "name both a cube map and a volume");
    info.resource = capabilities2 & CubeMap ? DdsResource::Cube :
                    capabilities2 & Volume ? DdsResource::Volume : DdsResource::Texture;
    info.depth = 1;
    if (info.resource == DdsResource::Volume)
    {
        if (depth == 0)
            reader.Fail("depth", "is zero in a volume");
        info.depth = depth;
    }
    // Writers that store one level may leave both the flag and the count clear.
    info.mipLevels = (flags & HasMipMapCount) && mipMapCount != 0 ? mipMapCount : 1;
    return info;
}

} // namespace fileformat
