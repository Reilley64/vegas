#include "check.h"
#include "fileformat/pe_file.h"
#include "fileformat/pe_fixture.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <format>
#include <functional>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

using fileformat::PeProblem;
using pe_fixture::Layout;
using pe_fixture::Put16;
using pe_fixture::Put32;
namespace at = pe_fixture::at;

// StoredBytes points into the file, so only a file that outlives the call
// offers it.
template <typename File>
concept OffersStoredBytes = requires(File&& file, const fileformat::PeSection& section) {
    std::forward<File>(file).StoredBytes(section);
};
static_assert(OffersStoredBytes<fileformat::PeFile&>);
static_assert(OffersStoredBytes<const fileformat::PeFile&>);
static_assert(!OffersStoredBytes<fileformat::PeFile>);
static_assert(!OffersStoredBytes<const fileformat::PeFile>);

std::string Version(const std::array<std::uint16_t, 4>& version)
{
    return std::format("{}.{}.{}.{}", version[0], version[1], version[2], version[3]);
}

void Rejects(Checks& check, std::string_view name, std::vector<std::byte> bytes, PeProblem expected)
{
    try
    {
        fileformat::ParsePeFile(std::move(bytes));
        check.Fail(name, "was read");
    }
    catch (const fileformat::PeError& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was rejected for another reason: {}", error.what()));
    }
}

// Builds the typical file, changes it and expects the problem.
void RejectsChanged(Checks& check, std::string_view name, const std::function<void(std::vector<std::byte>&)>& change,
                    PeProblem expected)
{
    std::vector<std::byte> bytes = pe_fixture::Build(pe_fixture::Typical());
    change(bytes);
    Rejects(check, name, std::move(bytes), expected);
}

void RejectsLayout(Checks& check, std::string_view name, const std::function<void(Layout&)>& change,
                   PeProblem expected)
{
    Layout layout = pe_fixture::Typical();
    change(layout);
    Rejects(check, name, pe_fixture::Build(layout), expected);
}

void ReadsTheSections(Checks& check)
{
    const Layout layout = pe_fixture::Typical();
    const fileformat::PeFile pe = fileformat::ParsePeFile(pe_fixture::Build(layout));
    const std::vector<std::uint32_t> rawOffsets = pe_fixture::RawOffsets(layout);

    check.Equal("image base", std::uint32_t{0x00400000}, pe.imageBase);
    check.Equal("entry point", std::uint32_t{0x1010}, pe.entryPoint);
    check.Equal("entry section", std::size_t{0}, pe.entrySection);
    check.Equal("SteamStub", false, pe.steamStub);
    check.Equal("section count", std::size_t{4}, pe.sections.size());
    if (pe.sections.size() != 4)
        return;

    struct Expected
    {
        std::string_view name;
        std::uint32_t virtualAddress, virtualSize, rawSize, storedBytes, zeroBytes;
    };
    const Expected expected[] = {
        {".text", 0x1000, 0x30, 0x200, 0x30, 0},
        {".rdata", 0x2000, 0x100, 0x100, 0x100, 0},
        {".data", 0x3000, 0x1800, 0x200, 0x200, 0x1600},
        {".rsrc", 0x5000, at::versionResourceBytes, at::versionResourceBytes, at::versionResourceBytes, 0},
    };
    for (std::size_t i = 0; i < 4; ++i)
    {
        const fileformat::PeSection& section = pe.sections[i];
        const std::string field = std::string(expected[i].name);
        check.Equal(field + " name", std::string(expected[i].name), section.name);
        check.Equal(field + " virtual address", expected[i].virtualAddress, section.virtualAddress);
        check.Equal(field + " virtual size", expected[i].virtualSize, section.virtualSize);
        check.Equal(field + " raw offset", rawOffsets[i], section.rawOffset);
        check.Equal(field + " raw size", expected[i].rawSize, section.rawSize);
        check.Equal(field + " stored bytes", expected[i].storedBytes, section.storedBytes);
        check.Equal(field + " zero bytes", expected[i].zeroBytes, section.zeroBytes);
        check.Equal(field + " characteristics", std::uint32_t{0x40000040}, section.characteristics);
        // The stored bytes are the file's, unchanged.
        check.Equal(field + " stored bytes as written", true,
                    std::ranges::equal(pe.StoredBytes(section),
                                       std::span(layout.sections[i].raw).first(expected[i].storedBytes)));
    }
}

void ReadsTheVersions(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    layout.sections[3].raw = pe_fixture::VersionResource(0x5000, {1, 4, 0, 525}, {0xFFFF, 2, 3, 0x8000});
    const fileformat::PeFile pe = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("file version", std::string("1.4.0.525"), Version(pe.fileVersion));
    check.Equal("product version", std::string("65535.2.3.32768"), Version(pe.productVersion));

    layout.sections[3].raw = pe_fixture::VersionResource(0x5000, {0xFFFF, 0, 0xFFFF, 0}, {0, 0xFFFF, 0, 0xFFFF});
    const fileformat::PeFile other = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("other file version", std::string("65535.0.65535.0"), Version(other.fileVersion));
    check.Equal("other product version", std::string("0.65535.0.65535"), Version(other.productVersion));
}

// Raw bytes may be fewer or more than the virtual size, or none.
void ReadsStoredAndZeroBytes(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    layout.sections.insert(layout.sections.begin() + 3, {".bss", 0x4800, 0x800, {}});
    layout.sections.insert(layout.sections.begin() + 4, {".empty", 0x5000, 0, {}});
    layout.sections.insert(layout.sections.begin() + 5, {".pad", 0x5000, 0x10, pe_fixture::Pattern(0x200, 4)});
    layout.sections.back().virtualAddress = 0x6000;
    layout.sections.back().raw = pe_fixture::VersionResource(0x6000, {1, 2, 3, 4}, {1, 2, 3, 4});
    layout.resourceAddress = 0x6000;
    const fileformat::PeFile pe = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("section count", std::size_t{7}, pe.sections.size());
    if (pe.sections.size() != 7)
        return;
    check.Equal(".bss stored bytes", std::uint32_t{0}, pe.sections[3].storedBytes);
    check.Equal(".bss zero bytes", std::uint32_t{0x800}, pe.sections[3].zeroBytes);
    check.Equal(".bss raw offset", std::uint32_t{0}, pe.sections[3].rawOffset);
    check.Equal(".bss stored span", std::size_t{0}, pe.StoredBytes(pe.sections[3]).size());
    check.Equal(".empty stored bytes", std::uint32_t{0}, pe.sections[4].storedBytes);
    check.Equal(".empty zero bytes", std::uint32_t{0}, pe.sections[4].zeroBytes);
    check.Equal(".pad stored bytes", std::uint32_t{0x10}, pe.sections[5].storedBytes);
    check.Equal(".pad zero bytes", std::uint32_t{0}, pe.sections[5].zeroBytes);
    check.Equal("file version", std::string("1.2.3.4"), Version(pe.fileVersion));
}

// The entry point in a section named .bind is reported; the code is not read.
void ReportsSteamStub(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    layout.sections.push_back({".bind", 0x6000, 0x400, pe_fixture::Pattern(0x400, 5)});
    layout.entryPoint = 0x63FF;
    const fileformat::PeFile wrapped = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("entry in .bind: SteamStub", true, wrapped.steamStub);
    check.Equal("entry in .bind: entry section", std::size_t{4}, wrapped.entrySection);
    check.Equal("entry in .bind: .text as stored", true,
                std::ranges::equal(wrapped.StoredBytes(wrapped.sections[0]),
                                   std::span(layout.sections[0].raw).first(0x30)));

    layout.entryPoint = 0x6000;
    check.Equal("entry at the start of .bind", true, fileformat::ParsePeFile(pe_fixture::Build(layout)).steamStub);

    layout.entryPoint = 0x1000;
    const fileformat::PeFile plain = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("entry in .text beside .bind: SteamStub", false, plain.steamStub);
    check.Equal("entry in .text beside .bind: entry section", std::size_t{0}, plain.entrySection);

    for (std::string_view name : {".bin", ".bindx", "bind", ".BIND"})
    {
        layout.sections.back().name = std::string(name);
        layout.entryPoint = 0x6000;
        check.Equal(std::format("entry in {}", name), false,
                    fileformat::ParsePeFile(pe_fixture::Build(layout)).steamStub);
    }
}

// Type entries with names and other types come before and after the version
// resource.
void FindsTheVersionAmongOtherResources(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    std::vector<std::byte>& raw = layout.sections[3].raw;
    // A root table with a named entry and type 3 before type 16 and type 24
    // after it, 0x18 bytes longer than the one-entry table; what follows it
    // moves by 0x18.
    const std::size_t shift = 0x18;
    std::vector<std::byte> rebuilt(0x30);
    Put16(rebuilt, at::tableNamedEntries, 1);
    Put16(rebuilt, at::tableIdEntries, 3);
    Put32(rebuilt, 0x10, 0x80000000 | 0x100); // a name, never read
    Put32(rebuilt, 0x14, 0x80000000 | (at::nameTable + shift));
    Put32(rebuilt, 0x18, 3);
    Put32(rebuilt, 0x1C, 0x80000000 | (at::nameTable + shift));
    Put32(rebuilt, 0x20, 16);
    Put32(rebuilt, 0x24, 0x80000000 | (at::nameTable + shift));
    Put32(rebuilt, 0x28, 24);
    Put32(rebuilt, 0x2C, 0x80000000 | (at::nameTable + shift));
    rebuilt.insert(rebuilt.end(), raw.begin() + at::nameTable, raw.end());
    Put32(rebuilt, at::nameEntry + shift + 4, 0x80000000 | (at::languageTable + shift));
    Put32(rebuilt, at::languageEntry + shift + 4, static_cast<std::uint32_t>(at::dataEntry + shift));
    Put32(rebuilt, at::dataEntry + shift, static_cast<std::uint32_t>(0x5000 + at::versionInfo + shift));
    raw = rebuilt;
    layout.resourceSize = static_cast<std::uint32_t>(raw.size());
    layout.sections[3].virtualSize = layout.resourceSize;
    const fileformat::PeFile pe = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("file version", std::string("1.4.0.525"), Version(pe.fileVersion));
}

// The version data may be stored in another section than the directory.
void ReadsVersionDataInAnotherSection(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    std::vector<std::byte>& rdata = layout.sections[1].raw;
    const std::vector<std::byte> resource = layout.sections[3].raw;
    std::copy(resource.begin() + at::versionInfo, resource.end(), rdata.begin() + 0x20);
    Put32(layout.sections[3].raw, at::dataEntry, 0x2020);
    rdata[0x20 + 40 + 8] = std::byte{9}; // file version minor 9
    const fileformat::PeFile pe = fileformat::ParsePeFile(pe_fixture::Build(layout));
    check.Equal("file version from .rdata", std::string("1.9.0.525"), Version(pe.fileVersion));
}

void AcceptsTheBoundaries(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    layout.entryPoint = 0x102F; // the last byte of .text
    check.Equal("entry at the last byte", std::size_t{0},
                fileformat::ParsePeFile(pe_fixture::Build(layout)).entrySection);
    // The entry point is in a section's memory, which includes its
    // zero-initialised tail.
    layout.entryPoint = 0x3200; // the first byte after the stored bytes of .data
    check.Equal("entry at the start of the zero tail", std::size_t{2},
                fileformat::ParsePeFile(pe_fixture::Build(layout)).entrySection);
    layout.entryPoint = 0x47FF; // the last byte of .data
    check.Equal("entry at the end of the zero tail", std::size_t{2},
                fileformat::ParsePeFile(pe_fixture::Build(layout)).entrySection);

    // 96 sections, the most Windows loads.
    Layout many = pe_fixture::Typical();
    many.sections.pop_back();
    for (std::uint32_t i = 0; many.sections.size() < 95; ++i)
        many.sections.push_back({std::format(".s{}", i), 0x6000 + 0x1000 * i, 0x10, pe_fixture::Pattern(0x10, i)});
    const std::uint32_t last = 0x6000 + 0x1000 * 92;
    many.sections.push_back({".rsrc", last, at::versionResourceBytes,
                             pe_fixture::VersionResource(last, {9, 9, 9, 9}, {9, 9, 9, 9})});
    many.resourceAddress = last;
    const fileformat::PeFile pe = fileformat::ParsePeFile(pe_fixture::Build(many));
    check.Equal("96 sections", std::size_t{96}, pe.sections.size());
    check.Equal("96 sections: version", std::string("9.9.9.9"), Version(pe.fileVersion));

    // A virtual size of 1 is not 0: the section is read with one stored byte.
    Layout one = pe_fixture::Typical();
    one.sections[0].virtualSize = 1;
    one.entryPoint = 0x1000;
    const fileformat::PeFile small = fileformat::ParsePeFile(pe_fixture::Build(one));
    check.Equal("virtual size 1: stored bytes", std::uint32_t{1}, small.sections[0].storedBytes);

    // A section may end exactly at SizeOfImage.
    std::vector<std::byte> bytes = pe_fixture::Build(pe_fixture::Typical());
    Put32(bytes, at::sizeOfImage, 0x5000 + at::versionResourceBytes);
    check.Equal("section ends at SizeOfImage", std::size_t{4}, fileformat::ParsePeFile(bytes).sections.size());

    // A section may start where the one before it ends.
    bytes = pe_fixture::Build(pe_fixture::Typical());
    Put32(bytes, at::Section(1, at::sectionVirtualAddress), 0x1030);
    check.Equal("section at the end of the one before", std::uint32_t{0x1030},
                fileformat::ParsePeFile(bytes).sections[1].virtualAddress);

    // The directory may end with the data entry; the data is found by its
    // address, not inside the directory.
    Layout entryLast = pe_fixture::Typical();
    entryLast.resourceSize = at::dataEntry + 16;
    check.Equal("directory ends with the data entry", std::string("1.4.0.525"),
                Version(fileformat::ParsePeFile(pe_fixture::Build(entryLast)).fileVersion));

    // Three data directories are enough to hold the resource directory.
    bytes = pe_fixture::Build(pe_fixture::Typical());
    Put32(bytes, at::directoryCount, 3);
    check.Equal("three data directories", std::string("1.4.0.525"),
                Version(fileformat::ParsePeFile(bytes).fileVersion));
}

void RejectsEveryPrefix(Checks& check)
{
    const std::vector<std::byte> bytes = pe_fixture::Build(pe_fixture::Typical());
    for (std::size_t size = 0; size < bytes.size(); ++size)
    {
        try
        {
            fileformat::ParsePeFile(std::vector<std::byte>(bytes.begin(), bytes.begin() + size));
            check.Fail(std::format("prefix of {} bytes", size), "was read");
        }
        catch (const fileformat::PeError&)
        {
        }
    }
    Rejects(check, "prefix in the MS-DOS header", std::vector<std::byte>(bytes.begin(), bytes.begin() + 63),
            PeProblem::DosHeaderTruncated);
    Rejects(check, "no bytes", {}, PeProblem::DosHeaderTruncated);
    Rejects(check, "prefix in the last section", std::vector<std::byte>(bytes.begin(), bytes.end() - 1),
            PeProblem::SectionOutOfFile);
}

void RejectsBadHeaders(Checks& check)
{
    RejectsChanged(check, "ZM", [](auto& b) { Put16(b, 0, 0x4D5A); }, PeProblem::DosMagic);
    RejectsChanged(check, "MZ lower case", [](auto& b) { Put16(b, 0, 0x7A6D); }, PeProblem::DosMagic);
    RejectsChanged(check, "PE header at the end",
                   [](auto& b) { Put32(b, at::peHeaderOffset, static_cast<std::uint32_t>(b.size())); },
                   PeProblem::PeHeaderTruncated);
    RejectsChanged(check, "PE header 23 bytes before the end",
                   [](auto& b) { Put32(b, at::peHeaderOffset, static_cast<std::uint32_t>(b.size() - 23)); },
                   PeProblem::PeHeaderTruncated);
    RejectsChanged(check, "PE header offset 2^32 - 1", [](auto& b) { Put32(b, at::peHeaderOffset, 0xFFFFFFFF); },
                   PeProblem::PeHeaderTruncated);
    RejectsChanged(check, "PE header offset 0", [](auto& b) { Put32(b, at::peHeaderOffset, 0); },
                   PeProblem::PeSignature);
    RejectsChanged(check, "PE signature with a one", [](auto& b) { b[at::peHeader + 3] = std::byte{1}; },
                   PeProblem::PeSignature);
    RejectsChanged(check, "NE signature", [](auto& b) { b[at::peHeader] = std::byte{'N'}; }, PeProblem::PeSignature);
    RejectsChanged(check, "machine ARM", [](auto& b) { Put16(b, at::machine, 0x1C4); }, PeProblem::Machine);
    RejectsChanged(check, "machine unknown", [](auto& b) { Put16(b, at::machine, 0); }, PeProblem::Machine);
    RejectsChanged(check, "machine ARM64", [](auto& b) { Put16(b, at::machine, 0xAA64); }, PeProblem::Machine);
    RejectsChanged(check, "no sections", [](auto& b) { Put16(b, at::sectionCount, 0); }, PeProblem::SectionCount);
    RejectsChanged(check, "optional header of 95 bytes", [](auto& b) { Put16(b, at::optionalHeaderSize, 95); },
                   PeProblem::OptionalHeaderSize);
    RejectsChanged(check, "optional header of 0 bytes", [](auto& b) { Put16(b, at::optionalHeaderSize, 0); },
                   PeProblem::OptionalHeaderSize);
    RejectsChanged(check, "optional header past the end",
                   [](auto& b) {
                       b.resize(at::optionalHeader + 0x100);
                       Put16(b, at::optionalHeaderSize, 0x101);
                   },
                   PeProblem::OptionalHeaderSize);
    RejectsChanged(check, "17 data directories in 16", [](auto& b) { Put32(b, at::directoryCount, 17); },
                   PeProblem::OptionalHeaderSize);
    RejectsChanged(check, "2^32 - 1 data directories", [](auto& b) { Put32(b, at::directoryCount, 0xFFFFFFFF); },
                   PeProblem::OptionalHeaderSize);
    RejectsChanged(check, "PE32+ magic", [](auto& b) { Put16(b, at::optionalMagic, 0x20B); },
                   PeProblem::OptionalHeaderMagic);
    RejectsChanged(check, "ROM magic", [](auto& b) { Put16(b, at::optionalMagic, 0x107); },
                   PeProblem::OptionalHeaderMagic);
    RejectsChanged(check, "section table past the end", [](auto& b) { Put16(b, at::sectionCount, 96); },
                   PeProblem::SectionTableTruncated);
    RejectsChanged(check, "97 sections", [](auto& b) { Put16(b, at::sectionCount, 97); }, PeProblem::SectionCount);
    RejectsChanged(check, "65535 sections", [](auto& b) { Put16(b, at::sectionCount, 0xFFFF); },
                   PeProblem::SectionCount);
}

// A 64-bit executable, such as this project's windows-x64 one, is refused.
void RefusesA64BitExecutable(Checks& check)
{
    Layout layout = pe_fixture::Typical();
    layout.machine = 0x8664;
    layout.optionalMagic = 0x20B;
    try
    {
        fileformat::ParsePeFile(pe_fixture::Build(layout));
        check.Fail("x64 executable", "was read");
    }
    catch (const fileformat::PeError& error)
    {
        check.Equal("x64 executable: problem", true, error.Problem() == PeProblem::Machine);
        check.Equal("x64 executable: message names x64", true,
                    std::string_view(error.what()).find("x64 (0x8664)") != std::string_view::npos);
    }
    RejectsLayout(check, "x86 machine with the x64 magic", [](Layout& l) { l.optionalMagic = 0x20B; },
                  PeProblem::OptionalHeaderMagic);
}

void RejectsBadSections(Checks& check)
{
    RejectsChanged(check, "raw offset past the end",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionRawOffset), static_cast<std::uint32_t>(b.size() + 1));
                   },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "raw size past the end",
                   [](auto& b) { Put32(b, at::Section(0, at::sectionRawSize), static_cast<std::uint32_t>(b.size())); },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "raw extent wraps 2^32",
                   [](auto& b) {
                       Put32(b, at::Section(0, at::sectionRawOffset), 0xFFFFFF00);
                       Put32(b, at::Section(0, at::sectionRawSize), 0x200);
                   },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "empty raw extent past the end",
                   [](auto& b) {
                       Put32(b, at::Section(0, at::sectionRawOffset), static_cast<std::uint32_t>(b.size() + 1));
                       Put32(b, at::Section(0, at::sectionRawSize), 0);
                   },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "SizeOfImage one short",
                   [](auto& b) { Put32(b, at::sizeOfImage, 0x5000 + at::versionResourceBytes - 1); },
                   PeProblem::SectionBeyondSizeOfImage);
    RejectsChanged(check, "virtual extent wraps 2^32",
                   [](auto& b) {
                       Put32(b, at::sizeOfImage, 0xFFFFFFFF);
                       Put32(b, at::Section(3, at::sectionVirtualAddress), 0xFFFFF000);
                       Put32(b, at::Section(3, at::sectionVirtualSize), 0x2000);
                   },
                   PeProblem::SectionBeyondSizeOfImage);
    // A virtual size of 0 with bytes in the file is refused; with none it is
    // an empty section (see ReadsStoredAndZeroBytes).
    RejectsChanged(check, "virtual size 0 with bytes in the file",
                   [](auto& b) { Put32(b, at::Section(1, at::sectionVirtualSize), 0); },
                   PeProblem::SectionVirtualSize);
    RejectsChanged(check, "virtual size 0 with one byte in the file",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionVirtualSize), 0);
                       Put32(b, at::Section(1, at::sectionRawSize), 1);
                   },
                   PeProblem::SectionVirtualSize);
    RejectsChanged(check, "out of file before virtual size 0",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionVirtualSize), 0);
                       Put32(b, at::Section(1, at::sectionRawOffset), 0xFFFFFFFF);
                   },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "virtual size 0 before beyond SizeOfImage",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionVirtualSize), 0);
                       Put32(b, at::Section(1, at::sectionVirtualAddress), 0xFFFFF000);
                   },
                   PeProblem::SectionVirtualSize);
    RejectsChanged(check, "overlaps the section before",
                   [](auto& b) { Put32(b, at::Section(1, at::sectionVirtualAddress), 0x102F); },
                   PeProblem::SectionOrder);
    RejectsChanged(check, "starts before the section before",
                   [](auto& b) { Put32(b, at::Section(1, at::sectionVirtualAddress), 0x0800); },
                   PeProblem::SectionOrder);
    // Ends before the next section, and is compared with the one before it
    // only: the first section starts after the second.
    RejectsChanged(check, "first section after the second",
                   [](auto& b) { Put32(b, at::Section(0, at::sectionVirtualAddress), 0x2200); },
                   PeProblem::SectionOrder);
    // Overlaps .rdata, the section before, but not .text: the order is
    // compared with the section before.
    RejectsChanged(check, "third section overlaps the second only",
                   [](auto& b) { Put32(b, at::Section(2, at::sectionVirtualAddress), 0x20FF); },
                   PeProblem::SectionOrder);
    RejectsLayout(check, "two .data sections", [](Layout& l) { l.sections[2].name = ".rdata"; },
                  PeProblem::DuplicateSectionName);
    // Every earlier name is compared, not only the one before.
    RejectsLayout(check, "first and third sections named alike", [](Layout& l) { l.sections[2].name = ".text"; },
                  PeProblem::DuplicateSectionName);
    RejectsLayout(check, "two empty names", [](Layout& l) { l.sections[0].name = l.sections[1].name = ""; },
                  PeProblem::DuplicateSectionName);
    RejectsLayout(check, "names equal before a zero byte",
                  [](Layout& l) {
                      l.sections[0].name = std::string(".a\0b", 4);
                      l.sections[1].name = std::string(".a\0c", 4);
                  },
                  PeProblem::DuplicateSectionName);
    // Problems of an earlier section come first.
    RejectsChanged(check, "earlier section first",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionRawOffset), 0xFFFFFFFF);
                       Put32(b, at::Section(2, at::sectionVirtualAddress), 0);
                   },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "out of file before beyond SizeOfImage",
                   [](auto& b) {
                       Put32(b, at::Section(0, at::sectionRawOffset), 0xFFFFFFFF);
                       Put32(b, at::sizeOfImage, 0);
                   },
                   PeProblem::SectionOutOfFile);
    RejectsChanged(check, "beyond SizeOfImage before the order",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionVirtualAddress), 0x1000);
                       Put32(b, at::sizeOfImage, 0x1080);
                   },
                   PeProblem::SectionBeyondSizeOfImage);
    RejectsChanged(check, "order before the name",
                   [](auto& b) {
                       Put32(b, at::Section(1, at::sectionVirtualAddress), 0x1000);
                       b[at::Section(1, 0) + 1] = std::byte{'t'};
                       b[at::Section(1, 0) + 2] = std::byte{'e'};
                       b[at::Section(1, 0) + 3] = std::byte{'x'};
                       b[at::Section(1, 0) + 4] = std::byte{'t'};
                       b[at::Section(1, 0) + 5] = std::byte{0};
                   },
                   PeProblem::SectionOrder);
}

void RejectsAnEntryPointOutsideTheSections(Checks& check)
{
    RejectsLayout(check, "entry at the end of .text", [](Layout& l) { l.entryPoint = 0x1030; }, PeProblem::EntryPoint);
    RejectsLayout(check, "entry before the first section", [](Layout& l) { l.entryPoint = 0x0FFF; },
                  PeProblem::EntryPoint);
    RejectsLayout(check, "entry 0", [](Layout& l) { l.entryPoint = 0; }, PeProblem::EntryPoint);
    RejectsLayout(check, "entry after the last section", [](Layout& l) { l.entryPoint = 0xFFFFFFFF; },
                  PeProblem::EntryPoint);
    RejectsLayout(check, "entry in an empty section",
                  [](Layout& l) {
                      l.sections.insert(l.sections.begin() + 3, {".empty", 0x4800, 0, {}});
                      l.entryPoint = 0x4800;
                  },
                  PeProblem::EntryPoint);
}

// Changes the resource section of the typical file.
void RejectsResource(Checks& check, std::string_view name, const std::function<void(std::vector<std::byte>&)>& change,
                     PeProblem expected)
{
    Layout layout = pe_fixture::Typical();
    change(layout.sections[3].raw);
    Rejects(check, name, pe_fixture::Build(layout), expected);
}

void RejectsAMissingVersionResource(Checks& check)
{
    RejectsChanged(check, "two data directories", [](auto& b) { Put32(b, at::directoryCount, 2); },
                   PeProblem::NoVersionResource);
    RejectsChanged(check, "no data directories", [](auto& b) { Put32(b, at::directoryCount, 0); },
                   PeProblem::NoVersionResource);
    RejectsLayout(check, "resource directory address 0", [](Layout& l) { l.resourceAddress = 0; },
                  PeProblem::NoVersionResource);
    RejectsLayout(check, "resource directory size 0", [](Layout& l) { l.resourceSize = 0; },
                  PeProblem::NoVersionResource);
    RejectsResource(check, "type 3 only", [](auto& r) { Put32(r, at::typeEntry, 3); }, PeProblem::NoVersionResource);
    RejectsResource(check, "type 16 as a name entry",
                    [](auto& r) {
                        Put16(r, at::tableNamedEntries, 1);
                        Put16(r, at::tableIdEntries, 0);
                    },
                    PeProblem::NoVersionResource);
    RejectsResource(check, "no type entries", [](auto& r) { Put16(r, at::tableIdEntries, 0); },
                    PeProblem::NoVersionResource);
    RejectsResource(check, "no name entries", [](auto& r) { Put16(r, at::nameTable + at::tableIdEntries, 0); },
                    PeProblem::NoVersionResource);
    RejectsResource(check, "no language entries", [](auto& r) { Put16(r, at::languageTable + at::tableIdEntries, 0); },
                    PeProblem::NoVersionResource);
}

void RejectsMalformedResources(Checks& check)
{
    RejectsLayout(check, "resource directory in the zero tail of .data",
                  [](Layout& l) { l.resourceAddress = 0x3200; }, PeProblem::ResourceMalformed);
    RejectsLayout(check, "resource directory past its section",
                  [](Layout& l) { l.resourceSize = at::versionResourceBytes + 1; }, PeProblem::ResourceMalformed);
    RejectsLayout(check, "resource directory across two sections",
                  [](Layout& l) {
                      l.resourceAddress = 0x20F0;
                      l.resourceSize = 0x20;
                  },
                  PeProblem::ResourceMalformed);
    RejectsLayout(check, "resource directory between sections", [](Layout& l) { l.resourceAddress = 0x4900; },
                  PeProblem::ResourceMalformed);
    RejectsLayout(check, "resource directory too short for its table", [](Layout& l) { l.resourceSize = 15; },
                  PeProblem::ResourceMalformed);
    RejectsLayout(check, "resource directory too short for its entries", [](Layout& l) { l.resourceSize = 23; },
                  PeProblem::ResourceMalformed);
    RejectsResource(check, "too many type entries", [](auto& r) { Put16(r, at::tableIdEntries, 0xFFFF); },
                    PeProblem::ResourceMalformed);
    // The named entries count towards the entries that must fit, though the
    // type is searched among the ID entries after them.
    RejectsResource(check, "too many named type entries", [](auto& r) { Put16(r, at::tableNamedEntries, 0xFFFF); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "type entry not a directory", [](auto& r) { Put32(r, at::typeEntry + 4, at::nameTable); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "name table outside",
                    [](auto& r) { Put32(r, at::typeEntry + 4, 0x80000000 | (at::versionResourceBytes - 15)); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "name table offset 0x7FFFFFFF",
                    [](auto& r) { Put32(r, at::typeEntry + 4, 0xFFFFFFFF); }, PeProblem::ResourceMalformed);
    RejectsResource(check, "name entry not a directory",
                    [](auto& r) { Put32(r, at::nameEntry + 4, at::languageTable); },
                    PeProblem::ResourceMalformed);
    try
    {
        Layout layout = pe_fixture::Typical();
        Put32(layout.sections[3].raw, at::languageEntry + 4, 0x80000000 | at::dataEntry);
        fileformat::ParsePeFile(pe_fixture::Build(layout));
        check.Fail("language entry a directory", "was read");
    }
    catch (const fileformat::PeError& error)
    {
        check.Equal("language entry a directory: problem", true, error.Problem() == PeProblem::ResourceMalformed);
        check.Equal("language entry a directory: message", true,
                    std::string_view(error.what()).find("is not a data entry") != std::string_view::npos);
    }
    RejectsResource(check, "data entry outside",
                    [](auto& r) { Put32(r, at::languageEntry + 4, at::versionResourceBytes - 15); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "data outside every section", [](auto& r) { Put32(r, at::dataEntry, 0x9000); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "data past its section", [](auto& r) { Put32(r, at::dataEntry + 4, 93); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "data size 2^32 - 1", [](auto& r) { Put32(r, at::dataEntry + 4, 0xFFFFFFFF); },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "data in the zero tail", [](auto& r) { Put32(r, at::dataEntry, 0x3200); },
                    PeProblem::ResourceMalformed);
    // The directory ends before the data entry, which is still in the file.
    RejectsLayout(check, "data entry after the end of the directory",
                  [](Layout& l) { l.resourceSize = at::dataEntry + 8; }, PeProblem::ResourceMalformed);
    RejectsLayout(check, "data entry one byte past the end of the directory",
                  [](Layout& l) { l.resourceSize = at::dataEntry + 15; }, PeProblem::ResourceMalformed);
}

void RejectsAnAmbiguousVersionResource(Checks& check)
{
    // Each table gains a second entry; the one after it in the file is
    // read as its second entry, inside the directory.
    RejectsResource(check, "two type 16 entries",
                    [](auto& r) {
                        Put16(r, at::tableIdEntries, 2);
                        Put32(r, at::typeEntry + 8, 16);
                    },
                    PeProblem::VersionResourceAmbiguous);
    RejectsResource(check, "two names", [](auto& r) { Put16(r, at::nameTable + at::tableIdEntries, 2); },
                    PeProblem::VersionResourceAmbiguous);
    RejectsResource(check, "a named and an ID name",
                    [](auto& r) { Put16(r, at::nameTable + at::tableNamedEntries, 1); },
                    PeProblem::VersionResourceAmbiguous);
    RejectsResource(check, "two languages", [](auto& r) { Put16(r, at::languageTable + at::tableIdEntries, 2); },
                    PeProblem::VersionResourceAmbiguous);
}

void RejectsABadVersionInfo(Checks& check)
{
    RejectsResource(check, "data of 91 bytes", [](auto& r) { Put32(r, at::dataEntry + 4, 91); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "data of 0 bytes", [](auto& r) { Put32(r, at::dataEntry + 4, 0); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "data of 0 bytes at the end of the section",
                    [](auto& r) {
                        Put32(r, at::dataEntry, 0x5000 + at::versionResourceBytes);
                        Put32(r, at::dataEntry + 4, 0);
                    },
                    PeProblem::VersionInfo);
    RejectsResource(check, "length 91", [](auto& r) { Put16(r, at::versionInfoLength, 91); }, PeProblem::VersionInfo);
    RejectsResource(check, "length past the data", [](auto& r) { Put16(r, at::versionInfoLength, 93); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "value length 0", [](auto& r) { Put16(r, at::versionInfoValueLength, 0); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "value length 53", [](auto& r) { Put16(r, at::versionInfoValueLength, 53); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "text type", [](auto& r) { Put16(r, at::versionInfoType, 1); }, PeProblem::VersionInfo);
    for (std::size_t i = 0; i < 16; ++i)
        RejectsResource(check, std::format("key character {}", i),
                        [&](auto& r) { Put16(r, at::versionInfoKey + 2 * i, 'x'); }, PeProblem::VersionInfo);
    RejectsResource(check, "key in the high bytes", [](auto& r) { Put16(r, at::versionInfoKey, 0x5600); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "key character with a high byte", [](auto& r) { Put16(r, at::versionInfoKey, 0x0156); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "signature", [](auto& r) { Put32(r, at::fixedFileInfo, 0xFEEF04BE); },
                    PeProblem::VersionInfo);
    RejectsResource(check, "signature reversed", [](auto& r) { Put32(r, at::fixedFileInfo, 0xBD04EFFE); },
                    PeProblem::VersionInfo);

    // A longer resource, with children after the fixed information, is read.
    Layout layout = pe_fixture::Typical();
    std::vector<std::byte>& raw = layout.sections[3].raw;
    raw.resize(raw.size() + 8);
    Put32(raw, at::dataEntry + 4, 100);
    Put16(raw, at::versionInfoLength, 100);
    layout.sections[3].virtualSize = static_cast<std::uint32_t>(raw.size());
    layout.resourceSize = layout.sections[3].virtualSize;
    check.Equal("longer resource", std::string("1.4.0.525"),
                Version(fileformat::ParsePeFile(pe_fixture::Build(layout)).fileVersion));
}

// With two problems, the one met first is reported: the checks up to the
// entry point in the order of PeProblem, except that the data-directory count,
// checked after the magic, also reports OptionalHeaderSize; then the resource
// in the order it is walked.
void ReportsTheFirstProblemMet(Checks& check)
{
    RejectsLayout(check, "entry point before the resource directory",
                  [](Layout& l) {
                      l.entryPoint = 0;
                      l.resourceAddress = 0;
                  },
                  PeProblem::EntryPoint);
    RejectsResource(check, "type entry not a directory before an empty name table",
                    [](auto& r) {
                        Put32(r, at::typeEntry + 4, at::nameTable);
                        Put16(r, at::nameTable + at::tableIdEntries, 0);
                    },
                    PeProblem::ResourceMalformed);
    RejectsResource(check, "empty name table before two languages",
                    [](auto& r) {
                        Put16(r, at::nameTable + at::tableIdEntries, 0);
                        Put16(r, at::languageTable + at::tableIdEntries, 2);
                    },
                    PeProblem::NoVersionResource);
    RejectsResource(check, "two names before a language that is a directory",
                    [](auto& r) {
                        Put16(r, at::nameTable + at::tableIdEntries, 2);
                        Put32(r, at::languageEntry + 4, 0x80000000 | at::dataEntry);
                    },
                    PeProblem::VersionResourceAmbiguous);
    RejectsResource(check, "two languages before a bad signature",
                    [](auto& r) {
                        Put16(r, at::languageTable + at::tableIdEntries, 2);
                        Put32(r, at::fixedFileInfo, 0);
                    },
                    PeProblem::VersionResourceAmbiguous);
    RejectsResource(check, "data past its section before a short length",
                    [](auto& r) {
                        Put32(r, at::dataEntry + 4, 93);
                        Put16(r, at::versionInfoLength, 91);
                    },
                    PeProblem::ResourceMalformed);
}

// The error names the format and the field.
void NamesTheField(Checks& check)
{
    try
    {
        fileformat::ParsePeFile({});
        check.Fail("empty file", "was read");
    }
    catch (const fileformat::FormatError& error)
    {
        check.Equal("message", std::string("PE file: MS-DOS header: ends early"), std::string(error.what()));
    }
}

} // namespace

int main()
{
    Checks check("PE file");
    check.Run("sections", [&] { ReadsTheSections(check); });
    check.Run("versions", [&] { ReadsTheVersions(check); });
    check.Run("stored and zero bytes", [&] { ReadsStoredAndZeroBytes(check); });
    check.Run("SteamStub", [&] { ReportsSteamStub(check); });
    check.Run("other resources", [&] { FindsTheVersionAmongOtherResources(check); });
    check.Run("version data in another section", [&] { ReadsVersionDataInAnotherSection(check); });
    check.Run("boundaries", [&] { AcceptsTheBoundaries(check); });
    check.Run("prefixes", [&] { RejectsEveryPrefix(check); });
    check.Run("headers", [&] { RejectsBadHeaders(check); });
    check.Run("64-bit executable", [&] { RefusesA64BitExecutable(check); });
    check.Run("sections refused", [&] { RejectsBadSections(check); });
    check.Run("entry point", [&] { RejectsAnEntryPointOutsideTheSections(check); });
    check.Run("missing version resource", [&] { RejectsAMissingVersionResource(check); });
    check.Run("malformed resources", [&] { RejectsMalformedResources(check); });
    check.Run("ambiguous version resource", [&] { RejectsAnAmbiguousVersionResource(check); });
    check.Run("version info", [&] { RejectsABadVersionInfo(check); });
    check.Run("first problem met", [&] { ReportsTheFirstProblemMet(check); });
    check.Run("message", [&] { NamesTheField(check); });
    return check.ExitCode();
}
