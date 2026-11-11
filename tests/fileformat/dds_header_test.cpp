#include "check.h"
#include "fileformat/dds_header.h"
#include "fileformat/fixture.h"
#include "fileformat/format_error.h"

#include <cstdint>
#include <format>
#include <string>
#include <string_view>

namespace
{

using fileformat::DdsFormat;
using fileformat::DdsResource;

// The fields of a DDS header that the tests vary.
struct Header
{
    std::string magic = "DDS ";
    std::uint32_t size = 124;
    std::uint32_t flags = 0x1 | 0x2 | 0x4 | 0x1000; // capabilities, height, width, pixel format
    std::uint32_t height = 256;
    std::uint32_t width = 512;
    std::uint32_t depth = 0;
    std::uint32_t mipMapCount = 0;
    std::uint32_t pixelFormatSize = 32;
    std::uint32_t pixelFormatFlags = 0x41; // RGB with alpha
    std::uint32_t code = 0;
    std::uint32_t bits = 32;
    std::uint32_t red = 0x00ff0000, green = 0x0000ff00, blue = 0x000000ff, alpha = 0xff000000;
    std::uint32_t capabilities = 0x1000; // texture
    std::uint32_t capabilities2 = 0;
};

void U32(Fixture& f, std::string_view field, std::uint32_t value)
{
    f.Bytes(field, {static_cast<std::uint8_t>(value), static_cast<std::uint8_t>(value >> 8),
                    static_cast<std::uint8_t>(value >> 16), static_cast<std::uint8_t>(value >> 24)});
}

Fixture File(const Header& h)
{
    Fixture f;
    f.Text("magic number", h.magic);
    U32(f, "header size", h.size);
    U32(f, "flags", h.flags);
    U32(f, "height", h.height);
    U32(f, "width", h.width);
    U32(f, "pitch or linear size", 0);
    U32(f, "depth", h.depth);
    U32(f, "mipmap count", h.mipMapCount);
    for (int i = 0; i < 11; ++i)
        U32(f, "reserved words", 0);
    U32(f, "pixel format size", h.pixelFormatSize);
    U32(f, "pixel format flags", h.pixelFormatFlags);
    U32(f, "pixel format four-character code", h.code);
    U32(f, "pixel format bit count", h.bits);
    U32(f, "pixel format red mask", h.red);
    U32(f, "pixel format green mask", h.green);
    U32(f, "pixel format blue mask", h.blue);
    U32(f, "pixel format alpha mask", h.alpha);
    U32(f, "capabilities", h.capabilities);
    U32(f, "second capabilities", h.capabilities2);
    for (int i = 0; i < 3; ++i)
        U32(f, "unused capabilities and reserved word", 0);
    return f;
}

std::uint32_t Value(DdsFormat format) { return static_cast<std::uint32_t>(format); }
std::uint32_t Value(DdsResource resource) { return static_cast<std::uint32_t>(resource); }

void Expect(Checks& check, std::string_view name, const Header& h, std::uint32_t width, std::uint32_t height,
            std::uint32_t depth, std::uint32_t mipLevels, DdsFormat format, DdsResource resource)
{
    const Fixture file = File(h);
    check.Equal(std::format("{}: fixture size", name), std::size_t{128}, file.Data().size());
    const fileformat::DdsImageInfo info = fileformat::ReadDdsImageInfo(file.Data());
    check.Equal(std::format("{}: width", name), width, info.width);
    check.Equal(std::format("{}: height", name), height, info.height);
    check.Equal(std::format("{}: depth", name), depth, info.depth);
    check.Equal(std::format("{}: mip levels", name), mipLevels, info.mipLevels);
    check.Equal(std::format("{}: format", name), Value(format), Value(info.format));
    check.Equal(std::format("{}: resource", name), Value(resource), Value(info.resource));
}

void Rejects(Checks& check, std::string_view name, std::span<const std::byte> file, std::string_view field)
{
    try
    {
        fileformat::ReadDdsImageInfo(file);
        check.Fail(name, "was read without an error");
    }
    catch (const fileformat::FormatError& error)
    {
        const std::string expected = std::format("DDS header: {}: ", field);
        if (std::string(error.what()).rfind(expected, 0) != 0)
            check.Fail(name, std::format("expected an error about '{}', got '{}'", field, error.what()));
    }
}

void Rejects(Checks& check, std::string_view name, const Header& h, std::string_view field)
{
    Rejects(check, name, File(h).Data(), field);
}

void ReadsHeaders(Checks& check)
{
    Expect(check, "plain texture", Header{}, 512, 256, 1, 1, DdsFormat::A8R8G8B8, DdsResource::Texture);

    // The header's fields are read in file order: height comes before width.
    Header tall;
    tall.height = 1024;
    tall.width = 4;
    Expect(check, "tall texture", tall, 4, 1024, 1, 1, DdsFormat::A8R8G8B8, DdsResource::Texture);

    Header mipmapped;
    mipmapped.flags |= 0x20000;
    mipmapped.mipMapCount = 10;
    mipmapped.pixelFormatFlags = 0x4;
    mipmapped.code = 0x31545844; // "DXT1"
    mipmapped.bits = 0;
    mipmapped.red = mipmapped.green = mipmapped.blue = mipmapped.alpha = 0;
    Expect(check, "block-compressed mipmapped texture", mipmapped, 512, 256, 1, 10, DdsFormat::Dxt1,
           DdsResource::Texture);

    // A count without its flag, and a flag with a zero count, both mean one level.
    Header unflagged = Header{};
    unflagged.mipMapCount = 7;
    Expect(check, "mipmap count without its flag", unflagged, 512, 256, 1, 1, DdsFormat::A8R8G8B8,
           DdsResource::Texture);
    Header zeroCount = Header{};
    zeroCount.flags |= 0x20000;
    Expect(check, "mipmap flag with a zero count", zeroCount, 512, 256, 1, 1, DdsFormat::A8R8G8B8,
           DdsResource::Texture);

    Header cube = Header{};
    cube.width = cube.height = 64;
    cube.capabilities2 = 0x200 | 0xfc00; // cube map with all six faces
    cube.depth = 9;                      // unused outside a volume
    Expect(check, "cube map", cube, 64, 64, 1, 1, DdsFormat::A8R8G8B8, DdsResource::Cube);

    Header volume = Header{};
    volume.flags |= 0x800000;
    volume.width = volume.height = 32;
    volume.depth = 16;
    volume.capabilities2 = 0x200000;
    Expect(check, "volume", volume, 32, 32, 16, 1, DdsFormat::A8R8G8B8, DdsResource::Volume);

    // Bytes after the header are not read.
    Fixture withData = File(Header{});
    withData.Bytes("pixel data", {1, 2, 3});
    check.Equal("texture with pixel data: width", std::uint32_t{512},
                fileformat::ReadDdsImageInfo(withData.Data()).width);
}

struct MaskRow
{
    const char* name;
    std::uint32_t flags, bits, red, green, blue, alpha;
    DdsFormat format;
};

void ReadsEveryFormat(Checks& check)
{
    // The uncompressed rows of the public guide's table: flags, bit count and masks.
    const MaskRow rows[] = {
        {"A8B8G8R8", 0x41, 32, 0xff, 0xff00, 0xff0000, 0xff000000, DdsFormat::A8B8G8R8},
        {"G16R16 with the alpha flag", 0x41, 32, 0xffff, 0xffff0000, 0, 0, DdsFormat::G16R16},
        {"G16R16", 0x40, 32, 0xffff, 0xffff0000, 0, 0, DdsFormat::G16R16},
        {"A1R5G5B5", 0x41, 16, 0x7c00, 0x3e0, 0x1f, 0x8000, DdsFormat::A1R5G5B5},
        {"R5G6B5", 0x40, 16, 0xf800, 0x7e0, 0x1f, 0, DdsFormat::R5G6B5},
        {"A8", 0x2, 8, 0, 0, 0, 0xff, DdsFormat::A8},
        {"A8R8G8B8", 0x41, 32, 0xff0000, 0xff00, 0xff, 0xff000000, DdsFormat::A8R8G8B8},
        {"X8R8G8B8", 0x40, 32, 0xff0000, 0xff00, 0xff, 0, DdsFormat::X8R8G8B8},
        {"X8B8G8R8", 0x40, 32, 0xff, 0xff00, 0xff0000, 0, DdsFormat::X8B8G8R8},
        {"R8G8B8", 0x40, 24, 0xff0000, 0xff00, 0xff, 0, DdsFormat::R8G8B8},
        {"X1R5G5B5", 0x40, 16, 0x7c00, 0x3e0, 0x1f, 0, DdsFormat::X1R5G5B5},
        {"A4R4G4B4", 0x41, 16, 0xf00, 0xf0, 0xf, 0xf000, DdsFormat::A4R4G4B4},
        {"X4R4G4B4", 0x40, 16, 0xf00, 0xf0, 0xf, 0, DdsFormat::X4R4G4B4},
        {"A8R3G3B2", 0x41, 16, 0xe0, 0x1c, 0x3, 0xff00, DdsFormat::A8R3G3B2},
        {"A8L8", 0x20000, 16, 0xff, 0, 0, 0xff00, DdsFormat::A8L8},
        {"A8L8 with the alpha flag", 0x20001, 16, 0xff, 0, 0, 0xff00, DdsFormat::A8L8},
        {"L16", 0x20000, 16, 0xffff, 0, 0, 0, DdsFormat::L16},
        {"L8", 0x20000, 8, 0xff, 0, 0, 0, DdsFormat::L8},
        {"A4L4", 0x20000, 8, 0xf, 0, 0, 0xf0, DdsFormat::A4L4},
        // An alpha mask that the flags do not declare valid is not compared.
        {"X8R8G8B8 with a stale alpha mask", 0x40, 32, 0xff0000, 0xff00, 0xff, 0xff000000, DdsFormat::X8R8G8B8},
        {"A8 with stale colour masks", 0x2, 8, 0xff0000, 0xff00, 0xff, 0xff, DdsFormat::A8},
    };
    for (const MaskRow& row : rows)
    {
        Header h;
        h.pixelFormatFlags = row.flags;
        h.bits = row.bits;
        h.red = row.red;
        h.green = row.green;
        h.blue = row.blue;
        h.alpha = row.alpha;
        Expect(check, row.name, h, 512, 256, 1, 1, row.format, DdsResource::Texture);
    }

    // The rows that name a format by code. The value read is the code itself.
    const std::uint32_t codes[] = {0x31545844, 0x32545844, 0x33545844, 0x34545844, 0x35545844, 0x59565955,
                                   0x32595559, 0x47424752, 0x42475247, 36,         110,        111,
                                   112,        113,        114,        115,        116,        117};
    for (const std::uint32_t code : codes)
    {
        Header h;
        h.pixelFormatFlags = 0x4;
        h.code = code;
        h.bits = 0;
        h.red = h.green = h.blue = h.alpha = 0;
        Expect(check, std::format("code 0x{:08X}", code), h, 512, 256, 1, 1, static_cast<DdsFormat>(code),
               DdsResource::Texture);
    }
}

void RejectsMalformedHeaders(Checks& check)
{
    // Every file shorter than the magic number and header ends early.
    const Fixture whole = File(Header{});
    for (std::size_t size = 0; size < whole.Data().size(); ++size)
    {
        const std::span<const std::byte> cut = whole.Data().first(size);
        try
        {
            fileformat::ReadDdsImageInfo(cut);
            check.Fail(std::format("file cut to {} bytes", size), "was read without an error");
        }
        catch (const fileformat::FormatError& error)
        {
            if (std::string(error.what()).find("ends early") == std::string::npos)
                check.Fail(std::format("file cut to {} bytes", size), error.what());
        }
    }

    Header h;
    h.magic = "DDS\0";
    h.magic.resize(4);
    Rejects(check, "wrong magic number", h, "magic number");
    h = Header{};
    h.magic = "RIFF";
    Rejects(check, "another file type", h, "magic number");

    h = Header{};
    h.size = 123;
    Rejects(check, "short header size", h, "header size");
    h.size = 0;
    Rejects(check, "zero header size", h, "header size");
    h.size = 0xffffffff;
    Rejects(check, "huge header size", h, "header size");

    h = Header{};
    h.pixelFormatSize = 0;
    Rejects(check, "zero pixel format size", h, "pixel format size");
    h.pixelFormatSize = 124;
    Rejects(check, "header size as pixel format size", h, "pixel format size");

    h = Header{};
    h.width = 0;
    Rejects(check, "zero width", h, "width");
    h = Header{};
    h.height = 0;
    Rejects(check, "zero height", h, "height");

    h = Header{};
    h.capabilities2 = 0x200 | 0x200000;
    Rejects(check, "cube map and volume", h, "second capabilities");
    h = Header{};
    h.capabilities2 = 0x200000;
    Rejects(check, "volume without depth", h, "depth");

    // Formats outside the guide's Direct3D 9 rows.
    h = Header{};
    h.pixelFormatFlags = 0x4;
    h.code = 0x30315844; // "DX10": an extension header follows, which Direct3D 9 does not read
    Rejects(check, "extension header code", h, "pixel format four-character code");
    h.code = 0x32495441; // "ATI2"
    Rejects(check, "code without a Direct3D 9 format", h, "pixel format four-character code");
    h.code = 0;
    Rejects(check, "zero code", h, "pixel format four-character code");
    h.code = 21; // the value of an uncompressed format is not one of the guide's codes
    Rejects(check, "uncompressed format as a code", h, "pixel format four-character code");

    h = Header{};
    h.pixelFormatFlags = 0;
    Rejects(check, "no pixel kind flag", h, "pixel format masks");
    h = Header{};
    h.pixelFormatFlags = 0x40 | 0x20000;
    Rejects(check, "two pixel kind flags", h, "pixel format masks");
    h = Header{};
    h.bits = 24;
    Rejects(check, "alpha in 24 bits", h, "pixel format masks");
    h = Header{};
    h.green = 0x00ff0000;
    Rejects(check, "overlapping masks", h, "pixel format masks");
    h = Header{};
    h.red = 0x3ff00000;
    h.green = 0x000ffc00;
    h.blue = 0x000003ff;
    h.alpha = 0xc0000000;
    Rejects(check, "ten-bit masks", h, "pixel format masks");
    h = Header{};
    h.pixelFormatFlags = 0x200; // YUV
    Rejects(check, "unlisted pixel kind", h, "pixel format masks");
}

} // namespace

int main()
{
    Checks check("DDS header");
    check.Run("read", [&] { ReadsHeaders(check); });
    check.Run("formats", [&] { ReadsEveryFormat(check); });
    check.Run("malformed", [&] { RejectsMalformedHeaders(check); });
    return check.ExitCode();
}
