#include "fileformat/pe_file.h"

#include "fileformat/byte_reader.h"

#include <algorithm>
#include <optional>
#include <string_view>
#include <utility>

namespace fileformat
{

namespace
{

// Sizes and values of the Microsoft PE and COFF specification.
constexpr std::size_t dosHeaderBytes = 64;
constexpr std::size_t peHeaderOffsetAt = 0x3C;
constexpr std::size_t fileHeaderBytes = 20;
constexpr std::size_t pe32FieldBytes = 96; // the PE32 optional header before its data directories
constexpr std::size_t directoryEntryBytes = 8;
constexpr std::size_t sectionHeaderBytes = 40;
constexpr std::uint16_t maxSections = 96; // the limit of the Windows loader that the specification states
constexpr std::uint16_t machineX86 = 0x14C;
constexpr std::uint16_t machineX64 = 0x8664;
constexpr std::uint16_t pe32Magic = 0x10B;
constexpr std::uint32_t resourceDirectoryIndex = 2;
constexpr std::uint32_t versionResourceType = 16;
constexpr std::size_t resourceTableBytes = 16;
constexpr std::size_t resourceEntryBytes = 8;
constexpr std::size_t resourceDataEntryBytes = 16;
constexpr std::uint32_t subdirectoryFlag = 0x80000000;
constexpr std::size_t fixedFileInfoAt = 40; // after the header, the key and its padding
constexpr std::size_t fixedFileInfoBytes = 52;
constexpr std::uint32_t fixedFileInfoSignature = 0xFEEF04BD;
constexpr std::u16string_view versionInfoKey{u"VS_VERSION_INFO\0", 16};

constexpr std::string_view format = "PE file";

[[noreturn]] void Fail(PeProblem problem, std::string_view field, std::string_view text)
{
    throw PeError(problem, std::string(format) + ": " + std::string(field) + ": " + std::string(text));
}

// Whether `size` bytes at `offset` lie inside `bytes`, without adding the two.
bool Fits(std::span<const std::byte> bytes, std::uint64_t offset, std::uint64_t size)
{
    return offset <= bytes.size() && size <= bytes.size() - offset;
}

// A reader of fields at `offset`. The caller has checked that `size` bytes fit.
ByteReader At(std::span<const std::byte> bytes, std::size_t offset, std::size_t size)
{
    return ByteReader(bytes.subspan(offset, size), format);
}

// The stored bytes of memory from `rva` to `rva + size`, when one section's
// stored bytes hold all of them.
std::optional<std::span<const std::byte>> Stored(const PeFile& pe, std::uint32_t rva, std::uint32_t size)
{
    for (const PeSection& section : pe.sections)
    {
        if (rva >= section.virtualAddress && rva - section.virtualAddress <= section.storedBytes &&
            size <= section.storedBytes - (rva - section.virtualAddress))
            return pe.StoredBytes(section).subspan(rva - section.virtualAddress, size);
    }
    return std::nullopt;
}

// One resource directory table, at `offset` in the resource directory.
struct ResourceTable
{
    std::size_t entriesAt;
    std::uint32_t namedEntries;
    std::uint32_t idEntries;
};

ResourceTable ReadResourceTable(std::span<const std::byte> resources, std::uint32_t offset)
{
    if (!Fits(resources, offset, resourceTableBytes))
        Fail(PeProblem::ResourceMalformed, "resource directory table", "is not inside the resource directory");
    ByteReader table = At(resources, offset, resourceTableBytes);
    table.Take(12, "resource directory table");
    ResourceTable result{offset + resourceTableBytes, table.U16("named entries"), table.U16("ID entries")};
    if (!Fits(resources, result.entriesAt,
              std::uint64_t{resourceEntryBytes} * (result.namedEntries + result.idEntries)))
        Fail(PeProblem::ResourceMalformed, "resource directory entries", "are not inside the resource directory");
    return result;
}

struct ResourceEntry
{
    std::uint32_t nameOrId;
    std::uint32_t offset;
};

ResourceEntry ReadResourceEntry(std::span<const std::byte> resources, const ResourceTable& table, std::size_t i)
{
    ByteReader entry = At(resources, table.entriesAt + resourceEntryBytes * i, resourceEntryBytes);
    const std::uint32_t nameOrId = entry.U32("resource name or ID");
    return {nameOrId, entry.U32("resource offset")};
}

// The only entry of the version resource's name or language table.
ResourceEntry OnlyEntry(std::span<const std::byte> resources, const ResourceTable& table, std::string_view level)
{
    const std::uint32_t count = table.namedEntries + table.idEntries;
    if (count == 0)
        Fail(PeProblem::NoVersionResource, level, "is empty");
    if (count != 1)
        Fail(PeProblem::VersionResourceAmbiguous, level, "has more than one entry");
    return ReadResourceEntry(resources, table, 0);
}

std::uint32_t Subdirectory(const ResourceEntry& entry, std::string_view level)
{
    if ((entry.offset & subdirectoryFlag) == 0)
        Fail(PeProblem::ResourceMalformed, level, "is not a directory");
    return entry.offset & ~subdirectoryFlag;
}

std::array<std::uint16_t, 4> Version(std::uint32_t mostSignificant, std::uint32_t leastSignificant)
{
    return {static_cast<std::uint16_t>(mostSignificant >> 16), static_cast<std::uint16_t>(mostSignificant),
            static_cast<std::uint16_t>(leastSignificant >> 16), static_cast<std::uint16_t>(leastSignificant)};
}

// Finds the one version resource and reads its VS_FIXEDFILEINFO.
void ReadVersionResource(PeFile& pe, std::uint32_t directoryRva, std::uint32_t directorySize)
{
    if (directoryRva == 0 || directorySize == 0)
        Fail(PeProblem::NoVersionResource, "resource directory", "is absent");
    const std::optional<std::span<const std::byte>> resources = Stored(pe, directoryRva, directorySize);
    if (!resources)
        Fail(PeProblem::ResourceMalformed, "resource directory", "is not stored in one section");

    // Name entries come before ID entries; the type is an ID.
    const ResourceTable types = ReadResourceTable(*resources, 0);
    std::optional<ResourceEntry> type;
    for (std::size_t i = types.namedEntries; i < std::size_t{types.namedEntries} + types.idEntries; ++i)
    {
        const ResourceEntry entry = ReadResourceEntry(*resources, types, i);
        if (entry.nameOrId != versionResourceType)
            continue;
        if (type)
            Fail(PeProblem::VersionResourceAmbiguous, "resource type 16", "is listed twice");
        type = entry;
    }
    if (!type)
        Fail(PeProblem::NoVersionResource, "resource type 16", "is absent");

    const ResourceTable names = ReadResourceTable(*resources, Subdirectory(*type, "resource type 16"));
    const ResourceTable languages =
        ReadResourceTable(*resources, Subdirectory(OnlyEntry(*resources, names, "version resource name"),
                                                   "version resource name"));
    const ResourceEntry language = OnlyEntry(*resources, languages, "version resource language");
    if ((language.offset & subdirectoryFlag) != 0)
        Fail(PeProblem::ResourceMalformed, "version resource language", "is not a data entry");
    if (!Fits(*resources, language.offset, resourceDataEntryBytes))
        Fail(PeProblem::ResourceMalformed, "version resource data entry", "is not inside the resource directory");
    ByteReader dataEntry = At(*resources, language.offset, resourceDataEntryBytes);
    const std::uint32_t dataRva = dataEntry.U32("version resource data address");
    const std::uint32_t dataSize = dataEntry.U32("version resource data size");
    const std::optional<std::span<const std::byte>> data = Stored(pe, dataRva, dataSize);
    if (!data)
        Fail(PeProblem::ResourceMalformed, "version resource data", "is not stored in one section");

    if (data->size() < fixedFileInfoAt + fixedFileInfoBytes)
        Fail(PeProblem::VersionInfo, "VS_VERSIONINFO", "is shorter than its header and VS_FIXEDFILEINFO");
    ByteReader info(*data, format);
    const std::uint16_t length = info.U16("VS_VERSIONINFO length");
    const std::uint16_t valueLength = info.U16("VS_VERSIONINFO value length");
    const std::uint16_t valueType = info.U16("VS_VERSIONINFO type");
    if (length < fixedFileInfoAt + fixedFileInfoBytes || length > data->size())
        Fail(PeProblem::VersionInfo, "VS_VERSIONINFO length", "is not inside the resource data");
    if (valueLength != fixedFileInfoBytes)
        Fail(PeProblem::VersionInfo, "VS_VERSIONINFO value length", "is not 52");
    if (valueType != 0)
        Fail(PeProblem::VersionInfo, "VS_VERSIONINFO type", "is not 0, binary");
    for (char16_t c : versionInfoKey)
    {
        if (info.U16("VS_VERSIONINFO key") != c)
            Fail(PeProblem::VersionInfo, "VS_VERSIONINFO key", "is not VS_VERSION_INFO");
    }

    ByteReader fixed = At(*data, fixedFileInfoAt, fixedFileInfoBytes);
    if (fixed.U32("VS_FIXEDFILEINFO signature") != fixedFileInfoSignature)
        Fail(PeProblem::VersionInfo, "VS_FIXEDFILEINFO signature", "is not 0xFEEF04BD");
    fixed.U32("VS_FIXEDFILEINFO structure version");
    const std::uint32_t fileMs = fixed.U32("file version");
    const std::uint32_t fileLs = fixed.U32("file version");
    const std::uint32_t productMs = fixed.U32("product version");
    const std::uint32_t productLs = fixed.U32("product version");
    pe.fileVersion = Version(fileMs, fileLs);
    pe.productVersion = Version(productMs, productLs);
}

} // namespace

PeFile ParsePeFile(std::vector<std::byte> file)
{
    const std::span<const std::byte> bytes = file;
    if (bytes.size() < dosHeaderBytes)
        Fail(PeProblem::DosHeaderTruncated, "MS-DOS header", "ends early");
    ByteReader dos = At(bytes, 0, dosHeaderBytes);
    if (dos.U16("MS-DOS magic") != 0x5A4D)
        Fail(PeProblem::DosMagic, "MS-DOS magic", "is not MZ");
    const std::uint32_t peHeaderAt = At(bytes, peHeaderOffsetAt, 4).U32("PE header offset");
    if (!Fits(bytes, peHeaderAt, 4 + fileHeaderBytes))
        Fail(PeProblem::PeHeaderTruncated, "PE header", "ends after the end of the file");

    ByteReader header = At(bytes, peHeaderAt, 4 + fileHeaderBytes);
    if (header.U32("PE signature") != 0x00004550)
        Fail(PeProblem::PeSignature, "PE signature", "is not PE and two zero bytes");
    const std::uint16_t machine = header.U16("machine");
    if (machine == machineX64)
        Fail(PeProblem::Machine, "machine", "is x64 (0x8664), as is this project's windows-x64 executable, not x86");
    if (machine != machineX86)
        Fail(PeProblem::Machine, "machine", "is not x86 (0x14C)");
    const std::uint16_t sectionCount = header.U16("number of sections");
    if (sectionCount == 0 || sectionCount > maxSections)
        Fail(PeProblem::SectionCount, "number of sections", "is zero or more than 96");
    header.Take(12, "symbol table and time stamp");
    const std::uint16_t optionalHeaderBytes = header.U16("size of optional header");

    const std::size_t optionalHeaderAt = peHeaderAt + 4 + fileHeaderBytes;
    if (optionalHeaderBytes < pe32FieldBytes || !Fits(bytes, optionalHeaderAt, optionalHeaderBytes))
        Fail(PeProblem::OptionalHeaderSize, "size of optional header",
             "is less than the PE32 fields or runs past the end of the file");
    ByteReader optional = At(bytes, optionalHeaderAt, optionalHeaderBytes);
    if (optional.U16("optional header magic") != pe32Magic)
        Fail(PeProblem::OptionalHeaderMagic, "optional header magic", "is not PE32 (0x10B)");
    PeFile pe{};
    optional.Take(14, "code and data sizes");
    pe.entryPoint = optional.U32("address of entry point");
    optional.Take(8, "bases of code and data");
    pe.imageBase = optional.U32("image base");
    optional.Take(24, "alignment and versions");
    const std::uint32_t sizeOfImage = optional.U32("size of image");
    optional.Take(32, "sizes, checksum, subsystem and flags");
    const std::uint32_t directoryCount = optional.U32("number of data directories");
    if (directoryCount > (optionalHeaderBytes - pe32FieldBytes) / directoryEntryBytes)
        Fail(PeProblem::OptionalHeaderSize, "number of data directories", "does not fit in the optional header");
    std::uint32_t resourceRva = 0;
    std::uint32_t resourceSize = 0;
    if (directoryCount > resourceDirectoryIndex)
    {
        optional.Take(directoryEntryBytes * resourceDirectoryIndex, "data directories");
        resourceRva = optional.U32("resource directory address");
        resourceSize = optional.U32("resource directory size");
    }

    const std::size_t sectionTableAt = optionalHeaderAt + optionalHeaderBytes;
    if (!Fits(bytes, sectionTableAt, std::uint64_t{sectionHeaderBytes} * sectionCount))
        Fail(PeProblem::SectionTableTruncated, "section table", "runs past the end of the file");
    ByteReader table = At(bytes, sectionTableAt, sectionHeaderBytes * sectionCount);
    pe.sections.reserve(sectionCount);
    for (std::uint16_t i = 0; i < sectionCount; ++i)
    {
        PeSection section{};
        const std::span<const std::byte> name = table.Take(8, "section name");
        const auto end = std::ranges::find(name, std::byte{0});
        section.name.assign(reinterpret_cast<const char*>(name.data()),
                            static_cast<std::size_t>(end - name.begin()));
        section.virtualSize = table.U32("section virtual size");
        section.virtualAddress = table.U32("section virtual address");
        section.rawSize = table.U32("section raw size");
        section.rawOffset = table.U32("section raw offset");
        table.Take(12, "section relocations and line numbers");
        section.characteristics = table.U32("section characteristics");
        section.storedBytes = std::min(section.rawSize, section.virtualSize);
        section.zeroBytes = section.virtualSize - section.storedBytes;

        if (!Fits(bytes, section.rawOffset, section.rawSize))
            Fail(PeProblem::SectionOutOfFile, "section " + section.name, "is not inside the file");
        // Not defined by the PE specification;
        // refused to fail closed.
        if (section.virtualSize == 0 && section.rawSize != 0)
            Fail(PeProblem::SectionVirtualSize, "section " + section.name,
                 "has bytes in the file but a virtual size of 0");
        if (section.virtualAddress > sizeOfImage || section.virtualSize > sizeOfImage - section.virtualAddress)
            Fail(PeProblem::SectionBeyondSizeOfImage, "section " + section.name, "ends after SizeOfImage");
        if (i != 0 && (section.virtualAddress < pe.sections.back().virtualAddress ||
                       section.virtualAddress - pe.sections.back().virtualAddress < pe.sections.back().virtualSize))
            Fail(PeProblem::SectionOrder, "section " + section.name, "starts before the end of the one before");
        if (std::ranges::any_of(pe.sections, [&](const PeSection& other) { return other.name == section.name; }))
            Fail(PeProblem::DuplicateSectionName, "section " + section.name, "has the name of another section");
        pe.sections.push_back(std::move(section));
    }

    const auto entry = std::ranges::find_if(pe.sections, [&](const PeSection& section) {
        return pe.entryPoint >= section.virtualAddress && pe.entryPoint - section.virtualAddress < section.virtualSize;
    });
    if (entry == pe.sections.end())
        Fail(PeProblem::EntryPoint, "address of entry point", "is in no section");
    pe.entrySection = static_cast<std::size_t>(entry - pe.sections.begin());
    pe.steamStub = entry->name == ".bind";

    pe.bytes = std::move(file);
    ReadVersionResource(pe, resourceRva, resourceSize);
    return pe;
}

} // namespace fileformat
