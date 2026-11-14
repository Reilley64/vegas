#include "setup/staged_pack.h"

#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_writer.h"
#include "setup/log_path_suffix_ranges.h"
#include "setup/main_window_class_range.h"
#include "setup/prepare_pack.h"
#include "setup/single_instance_ranges.h"

#include "mbedtls/sha256.h"

#include <algorithm>
#include <cstdint>
#include <format>
#include <iterator>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>

namespace setup::staged
{

namespace
{

using fileformat::PeFile;
using fileformat::PeSection;

// Section characteristics of the Microsoft PE and COFF specification.
constexpr std::uint32_t sectionCode = 0x00000020;
constexpr std::uint32_t sectionInitializedData = 0x00000040;
constexpr std::uint32_t sectionExecute = 0x20000000;
constexpr std::uint32_t sectionWrite = 0x80000000;

// Where a PE32 file keeps the data directory of its base relocation table,
// and the relocation type of a 32-bit address, by the same specification.
// ParsePeFile has checked that the headers up to the data directories it
// counts lie in the file.
constexpr std::size_t peHeaderOffsetField = 0x3C;
constexpr std::size_t optionalHeaderFromSignature = 24;
constexpr std::size_t directoryCountField = 92;
constexpr std::size_t directoriesField = 96;
constexpr std::uint32_t baseRelocationIndex = 5;
constexpr std::uint16_t relocationHighLow = 3;

[[noreturn]] void Fail(ExtractProblem problem, std::string_view field, std::string_view what)
{
    throw ExtractError(problem, std::format("original release: {}: {}", field, what));
}

std::uint16_t U16(std::span<const std::byte> bytes, std::size_t at)
{
    return static_cast<std::uint16_t>(std::to_integer<unsigned>(bytes[at]) |
                                      std::to_integer<unsigned>(bytes[at + 1]) << 8);
}

std::uint32_t U32(std::span<const std::byte> bytes, std::size_t at)
{
    return std::uint32_t{U16(bytes, at)} | std::uint32_t{U16(bytes, at + 2)} << 16;
}

// The section whose memory holds `rva`, or none.
const PeSection* SectionAt(const PeFile& pe, std::uint32_t rva)
{
    const auto section = std::ranges::find_if(pe.sections, [&](const PeSection& candidate) {
        return rva >= candidate.virtualAddress && rva - candidate.virtualAddress < candidate.virtualSize;
    });
    return section == pe.sections.end() ? nullptr : &*section;
}

// The section that holds `address`, after the section checks.
const PeSection& DataSection(const PeFile& pe, std::string_view field, std::uint32_t address)
{
    if (address < pe.imageBase)
        Fail(ExtractProblem::NoSection, field, "is below the image base");
    const PeSection* section = SectionAt(pe, address - pe.imageBase);
    if (section == nullptr)
        Fail(ExtractProblem::NoSection, field, "is in no section");
    if (section->name == ".bind")
        Fail(ExtractProblem::SteamStubSection, field, "is in .bind");
    if ((section->characteristics & (sectionCode | sectionExecute)) != 0)
        Fail(ExtractProblem::CodeSection, field, "is in a section marked as code or executable");
    if ((section->characteristics & sectionInitializedData) == 0)
        Fail(ExtractProblem::NotInitializedData, field, "is in a section not marked as initialized data");
    return *section;
}

// The stored `bytes` bytes at `address`, after the section checks.
std::span<const std::byte> StoredRange(const PeFile& pe, std::string_view field, std::uint32_t address,
                                       std::size_t bytes)
{
    const PeSection& section = DataSection(pe, field, address);
    const std::uint32_t offset = address - pe.imageBase - section.virtualAddress;
    if (std::uint64_t{offset} + bytes > section.storedBytes)
        Fail(ExtractProblem::ZeroTail, field, "runs past the stored bytes of its section");
    return pe.StoredBytes(section).subspan(offset, bytes);
}

// Whether a HIGHLOW base relocation covers the 32-bit pointer at `rva`. The
// whole table is read, so a malformed block is refused wherever it is.
bool HasHighLowRelocation(const PeFile& pe, std::uint32_t rva, std::string_view field)
{
    const std::span<const std::byte> file = pe.bytes;
    const std::size_t optionalHeader = U32(file, peHeaderOffsetField) + optionalHeaderFromSignature;
    if (U32(file, optionalHeader + directoryCountField) <= baseRelocationIndex)
        return false;
    const std::size_t directory = optionalHeader + directoriesField + 8 * baseRelocationIndex;
    const std::uint32_t tableRva = U32(file, directory);
    const std::uint32_t tableBytes = U32(file, directory + 4);
    if (tableBytes == 0)
        return false;
    const PeSection* section = SectionAt(pe, tableRva);
    if (section == nullptr ||
        std::uint64_t{tableRva - section->virtualAddress} + tableBytes > section->storedBytes)
        Fail(ExtractProblem::RelocationTable, field, "base relocation table: is not stored in one section");
    const std::span<const std::byte> table =
        pe.StoredBytes(*section).subspan(tableRva - section->virtualAddress, tableBytes);
    bool covered = false;
    for (std::size_t block = 0; block < table.size();)
    {
        if (table.size() - block < 8)
            Fail(ExtractProblem::RelocationTable, field, "base relocation table: ends inside a block header");
        const std::uint32_t page = U32(table, block);
        const std::uint32_t blockBytes = U32(table, block + 4);
        if (blockBytes < 8 || blockBytes % 2 != 0 || blockBytes > table.size() - block)
            Fail(ExtractProblem::RelocationTable, field, "base relocation table: a block's size does not fit it");
        for (std::size_t entry = block + 8; entry < block + blockBytes; entry += 2)
        {
            const std::uint16_t value = U16(table, entry);
            if (value >> 12 == relocationHighLow && std::uint64_t{page} + (value & 0x0FFF) == rva)
                covered = true;
        }
        block += blockBytes;
    }
    return covered;
}

constexpr auto toChar = [](std::byte b) { return static_cast<char>(b); };

// Copies the string at `range` through its first zero byte into `field`,
// which holds zeros. No byte after that zero byte is copied.
template <std::size_t Capacity>
void CopyString(const PeFile& pe, const RecipeRange& range, std::array<char, Capacity>& field)
{
    const std::span<const std::byte> bytes = StoredRange(pe, range.field, range.address, range.capacity);
    const auto zero = std::ranges::find(bytes, std::byte{0});
    if (zero == bytes.end())
        Fail(ExtractProblem::NoTerminator, range.field, "holds no zero byte");
    if (!range.literalName.empty() &&
        !std::ranges::equal(bytes.begin(), zero, range.literalText.begin(), range.literalText.end(), {}, toChar))
        Fail(ExtractProblem::KnownString, range.field, std::format("is not the text of {}", range.literalName));
    std::ranges::transform(bytes.begin(), zero, field.begin(), toChar);
}

// Copies the string that the pointer of `range` points to through its first
// zero byte into `field`, which holds zeros. The pointer must be stored and
// covered by a HIGHLOW base relocation, and the string must lie in the stored
// bytes of a read-only data section with its zero byte within the capacity.
// No byte after that zero byte is copied.
template <std::size_t Capacity>
void CopyPointedString(const PeFile& pe, const PointerRange& range, std::array<char, Capacity>& field)
{
    const std::string pointer = std::string(range.field) + " pointer";
    const std::string text = std::string(range.field) + " string";
    const std::span<const std::byte> slot = StoredRange(pe, pointer, range.slotAddress, 4);
    if (!HasHighLowRelocation(pe, range.slotAddress - pe.imageBase, pointer))
        Fail(ExtractProblem::NoRelocation, pointer, "has no 32-bit base relocation");
    const std::uint32_t target = U32(slot, 0);
    const PeSection& section = DataSection(pe, text, target);
    if ((section.characteristics & sectionWrite) != 0)
        Fail(ExtractProblem::WritableSection, text, "is in a section marked as writable");
    const std::size_t offset = target - pe.imageBase - section.virtualAddress;
    const std::span<const std::byte> stored =
        pe.StoredBytes(section).subspan(std::min<std::size_t>(offset, section.storedBytes));
    const std::span<const std::byte> bytes = stored.first(std::min(stored.size(), Capacity));
    const auto zero = std::ranges::find(bytes, std::byte{0});
    if (zero == bytes.end() && bytes.size() < Capacity)
        Fail(ExtractProblem::ZeroTail, text, "runs past the stored bytes of its section before a zero byte");
    if (zero == bytes.end())
        Fail(ExtractProblem::NoTerminator, text, "holds no zero byte");
    std::ranges::transform(bytes.begin(), zero, field.begin(), toChar);
}

template <std::size_t Capacity> void Append(std::vector<std::byte>& payload, const std::array<char, Capacity>& field)
{
    std::ranges::transform(field, std::back_inserter(payload), [](char c) { return static_cast<std::byte>(c); });
}

} // namespace

std::array<std::byte, 32> Sha256(const std::vector<std::byte>& bytes)
{
    std::array<std::byte, 32> digest{};
    if (mbedtls_sha256(reinterpret_cast<const unsigned char*>(bytes.data()), bytes.size(),
                       reinterpret_cast<unsigned char*>(digest.data()), 0) != 0)
        throw std::logic_error("setup: SHA-256: failed");
    return digest;
}

std::vector<std::byte> WriteDataPack(const PeFile& pe, const fileformat::OriginalIdentity& original)
{
    fileformat::SingleInstanceStrings strings{};
    CopyString(pe, singleInstanceRanges[0], strings.mutexName);
    CopyString(pe, singleInstanceRanges[1], strings.firstMessageText);
    CopyString(pe, singleInstanceRanges[2], strings.messageCaption);
    CopyString(pe, singleInstanceRanges[3], strings.secondMessageText);
    fileformat::LogPathSuffixes suffixes{};
    CopyString(pe, logPathSuffixRanges[0], suffixes.firstSuffix);
    CopyString(pe, logPathSuffixRanges[1], suffixes.secondSuffix);
    CopyString(pe, logPathSuffixRanges[2], suffixes.thirdSuffix);
    CopyString(pe, logPathSuffixRanges[3], suffixes.fourthSuffix);
    fileformat::MainWindowClass windowClass{};
    CopyPointedString(pe, mainWindowClassRange, windowClass.className);

    std::vector<std::byte> payload;
    Append(payload, strings.mutexName);
    Append(payload, strings.firstMessageText);
    Append(payload, strings.messageCaption);
    Append(payload, strings.secondMessageText);
    std::vector<std::byte> suffixPayload;
    Append(suffixPayload, suffixes.firstSuffix);
    Append(suffixPayload, suffixes.secondSuffix);
    Append(suffixPayload, suffixes.thirdSuffix);
    Append(suffixPayload, suffixes.fourthSuffix);
    std::vector<std::byte> classPayload;
    Append(classPayload, windowClass.className);

    const fileformat::PackCatalogueEntry& first = fileformat::singleInstanceEntry;
    const fileformat::PackCatalogueEntry& second = fileformat::logPathSuffixesEntry;
    const fileformat::PackCatalogueEntry& third = fileformat::mainWindowClassEntry;
    const std::array<fileformat::PackWriteEntry, 3> entries{{{first.key, first.version, payload},
                                                             {second.key, second.version, suffixPayload},
                                                             {third.key, third.version, classPayload}}};
    return fileformat::WritePackStructure(original.version, original.sha256, entries);
}

} // namespace setup::staged
