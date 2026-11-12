#ifndef VEGAS_TESTS_FILEFORMAT_PE_FIXTURE_H
#define VEGAS_TESTS_FILEFORMAT_PE_FIXTURE_H

#include "fileformat/byte_writer.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

// Synthetic 32-bit x86 Windows executables, built in memory by the tests.
// Every field offset is stated here from the Microsoft PE and COFF
// specification, not shared with the reader. The files hold no code: section
// bytes are a pattern the test chooses.
namespace pe_fixture
{

// Where the fields are, for a file built by Build with 16 data directories.
namespace at
{
constexpr std::size_t peHeaderOffset = 0x3C;
constexpr std::size_t peHeader = 0x40;
constexpr std::size_t machine = peHeader + 4;
constexpr std::size_t sectionCount = peHeader + 6;
constexpr std::size_t optionalHeaderSize = peHeader + 20;
constexpr std::size_t optionalHeader = peHeader + 24;
constexpr std::size_t optionalMagic = optionalHeader;
constexpr std::size_t entryPoint = optionalHeader + 16;
constexpr std::size_t imageBase = optionalHeader + 28;
constexpr std::size_t sizeOfImage = optionalHeader + 56;
constexpr std::size_t directoryCount = optionalHeader + 92;
constexpr std::size_t resourceDirectory = optionalHeader + 96 + 2 * 8;
constexpr std::size_t sectionTable = optionalHeader + 96 + 16 * 8;
constexpr std::size_t sectionHeaderBytes = 40;
constexpr std::size_t sectionVirtualSize = 8;
constexpr std::size_t sectionVirtualAddress = 12;
constexpr std::size_t sectionRawSize = 16;
constexpr std::size_t sectionRawOffset = 20;

constexpr std::size_t Section(std::size_t i, std::size_t field)
{
    return sectionTable + sectionHeaderBytes * i + field;
}

// Inside the version resource that VersionResource builds, from its start.
constexpr std::size_t typeTable = 0x00;
constexpr std::size_t typeEntry = 0x10;
constexpr std::size_t nameTable = 0x18;
constexpr std::size_t nameEntry = 0x28;
constexpr std::size_t languageTable = 0x30;
constexpr std::size_t languageEntry = 0x40;
constexpr std::size_t dataEntry = 0x48;
constexpr std::size_t versionInfo = 0x58;
constexpr std::size_t tableIdEntries = 14; // in a directory table
constexpr std::size_t tableNamedEntries = 12;
constexpr std::size_t versionInfoLength = versionInfo;
constexpr std::size_t versionInfoValueLength = versionInfo + 2;
constexpr std::size_t versionInfoType = versionInfo + 4;
constexpr std::size_t versionInfoKey = versionInfo + 6;
constexpr std::size_t fixedFileInfo = versionInfo + 40;
constexpr std::size_t fileVersion = fixedFileInfo + 8;
constexpr std::size_t productVersion = fixedFileInfo + 16;
constexpr std::size_t versionResourceBytes = versionInfo + 92;
} // namespace at

constexpr std::uint32_t fileAlignment = 0x200;
constexpr std::uint32_t sectionAlignment = 0x1000;

struct Section
{
    std::string name; // up to 8 bytes
    std::uint32_t virtualAddress;
    std::uint32_t virtualSize;
    std::vector<std::byte> raw; // stored in the file, at the next multiple of fileAlignment
};

struct Layout
{
    std::uint16_t machine = 0x14C;
    std::uint16_t optionalMagic = 0x10B;
    std::uint32_t imageBase = 0x00400000;
    std::uint32_t entryPoint = 0;
    std::uint32_t resourceAddress = 0;
    std::uint32_t resourceSize = 0;
    std::vector<Section> sections;
};

inline std::vector<std::byte> Pattern(std::size_t size, std::uint32_t seed)
{
    std::vector<std::byte> bytes(size);
    std::uint32_t x = seed * 2654435761u + 1;
    for (std::byte& byte : bytes)
    {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        byte = static_cast<std::byte>(x >> 24);
    }
    return bytes;
}

inline std::uint32_t Pack(std::uint16_t high, std::uint16_t low)
{
    return (std::uint32_t{high} << 16) | low;
}

// A resource directory with one version resource: type 16, name 1, language
// 0x409. `address` is where the resource section starts in memory.
inline std::vector<std::byte> VersionResource(std::uint32_t address, const std::array<std::uint16_t, 4>& fileVersion,
                                              const std::array<std::uint16_t, 4>& productVersion)
{
    fileformat::ByteWriter w;
    auto table = [&](std::uint32_t nameOrId, std::uint32_t offset) {
        w.U32(0);  // characteristics
        w.U32(0);  // time stamp
        w.U16(0);  // major version
        w.U16(0);  // minor version
        w.U16(0);  // named entries
        w.U16(1);  // ID entries
        w.U32(nameOrId);
        w.U32(offset);
    };
    table(16, 0x80000000 | at::nameTable);
    table(1, 0x80000000 | at::languageTable);
    table(0x409, at::dataEntry);
    w.U32(address + at::versionInfo);
    w.U32(92);
    w.U32(0); // code page
    w.U32(0); // reserved
    w.U16(92);
    w.U16(52);
    w.U16(0);
    for (char c : std::string("VS_VERSION_INFO"))
        w.U16(static_cast<std::uint16_t>(c));
    w.U16(0);
    w.U16(0); // padding to a 32-bit boundary
    w.U32(0xFEEF04BD);
    w.U32(0x00010000);
    w.U32(Pack(fileVersion[0], fileVersion[1]));
    w.U32(Pack(fileVersion[2], fileVersion[3]));
    w.U32(Pack(productVersion[0], productVersion[1]));
    w.U32(Pack(productVersion[2], productVersion[3]));
    w.U32(0x3F);       // file flags mask
    w.U32(0);          // file flags
    w.U32(0x00040004); // VOS_NT_WINDOWS32
    w.U32(1);          // VFT_APP
    w.U32(0);          // subtype
    w.U32(0);          // date
    w.U32(0);
    return w.Take();
}

// Where each section's raw bytes start when Build lays out `layout`.
inline std::vector<std::uint32_t> RawOffsets(const Layout& layout)
{
    std::vector<std::uint32_t> offsets;
    std::size_t at = at::sectionTable + at::sectionHeaderBytes * layout.sections.size();
    for (const Section& section : layout.sections)
    {
        at = (at + fileAlignment - 1) / fileAlignment * fileAlignment;
        offsets.push_back(static_cast<std::uint32_t>(at));
        at += section.raw.size();
    }
    return offsets;
}

// The file: headers, then each section's raw bytes at the next multiple of
// the file alignment. The file ends where the last section's bytes end.
inline std::vector<std::byte> Build(const Layout& layout)
{
    std::uint32_t sizeOfImage = sectionAlignment;
    for (const Section& section : layout.sections)
        sizeOfImage = std::max(sizeOfImage, (section.virtualAddress + section.virtualSize + sectionAlignment - 1) /
                                                sectionAlignment * sectionAlignment);
    const std::vector<std::uint32_t> rawOffsets = RawOffsets(layout);
    const std::uint32_t sizeOfHeaders =
        (static_cast<std::uint32_t>(at::sectionTable + at::sectionHeaderBytes * layout.sections.size()) +
         fileAlignment - 1) /
        fileAlignment * fileAlignment;

    fileformat::ByteWriter w;
    w.Text("MZ");
    while (w.Size() < at::peHeaderOffset)
        w.U16(0);
    w.U32(at::peHeader);
    w.Text(std::string("PE\0\0", 4));
    w.U16(layout.machine);
    w.U16(static_cast<std::uint16_t>(layout.sections.size()));
    w.U32(0);         // time stamp
    w.U32(0);         // symbol table
    w.U32(0);         // symbols
    w.U16(96 + 16 * 8);
    w.U16(0x0102);    // executable, 32-bit machine

    w.U16(layout.optionalMagic);
    w.U16(0x000E);    // linker version
    w.U32(0);         // size of code
    w.U32(0);         // size of initialized data
    w.U32(0);         // size of uninitialized data
    w.U32(layout.entryPoint);
    w.U32(0);         // base of code
    w.U32(0);         // base of data
    w.U32(layout.imageBase);
    w.U32(sectionAlignment);
    w.U32(fileAlignment);
    for (int i = 0; i < 6; ++i)
        w.U16(i == 0 || i == 4 ? 5 : 0); // operating system, image and subsystem versions
    w.U32(0);         // Win32 version value
    w.U32(sizeOfImage);
    w.U32(sizeOfHeaders);
    w.U32(0);         // checksum
    w.U16(2);         // Windows GUI subsystem
    w.U16(0);         // DLL characteristics
    w.U32(0x100000);  // stack reserve
    w.U32(0x1000);    // stack commit
    w.U32(0x100000);  // heap reserve
    w.U32(0x1000);    // heap commit
    w.U32(0);         // loader flags
    w.U32(16);        // data directories
    for (std::uint32_t i = 0; i < 16; ++i)
    {
        w.U32(i == 2 ? layout.resourceAddress : 0);
        w.U32(i == 2 ? layout.resourceSize : 0);
    }

    for (std::size_t i = 0; i < layout.sections.size(); ++i)
    {
        const Section& section = layout.sections[i];
        std::string name = section.name;
        name.resize(8, '\0');
        w.Text(name);
        w.U32(section.virtualSize);
        w.U32(section.virtualAddress);
        w.U32(static_cast<std::uint32_t>(section.raw.size()));
        w.U32(section.raw.empty() ? 0 : rawOffsets[i]);
        w.U32(0); // relocations
        w.U32(0); // line numbers
        w.U16(0);
        w.U16(0);
        w.U32(0x40000040); // initialised data, readable
    }
    for (std::size_t i = 0; i < layout.sections.size(); ++i)
    {
        while (w.Size() < rawOffsets[i])
            w.U16(0);
        w.Append(layout.sections[i].raw);
    }
    return w.Take();
}

// A small executable with code, constants, data with a zero-initialised tail
// and a version resource. Its file version is 1.4.0.525.
inline Layout Typical()
{
    Layout layout;
    layout.entryPoint = 0x1010;
    layout.sections = {
        {".text", 0x1000, 0x30, Pattern(0x200, 1)},  // stored bytes beyond the virtual size are padding
        {".rdata", 0x2000, 0x100, Pattern(0x100, 2)},
        {".data", 0x3000, 0x1800, Pattern(0x200, 3)}, // 0x1600 zero bytes after the stored ones
        {".rsrc", 0x5000, at::versionResourceBytes, VersionResource(0x5000, {1, 4, 0, 525}, {1, 4, 0, 525})},
    };
    layout.resourceAddress = 0x5000;
    layout.resourceSize = at::versionResourceBytes;
    return layout;
}

inline void Put(std::vector<std::byte>& bytes, std::size_t offset, std::uint64_t value, std::size_t width)
{
    for (std::size_t i = 0; i < width; ++i)
        bytes[offset + i] = static_cast<std::byte>(value >> (8 * i));
}

inline void Put16(std::vector<std::byte>& bytes, std::size_t offset, std::uint16_t value)
{
    Put(bytes, offset, value, 2);
}

inline void Put32(std::vector<std::byte>& bytes, std::size_t offset, std::uint32_t value)
{
    Put(bytes, offset, value, 4);
}

} // namespace pe_fixture

#endif
