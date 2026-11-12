#include "setup/staged_pack.h"

#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_writer.h"
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

[[noreturn]] void Fail(ExtractProblem problem, const RecipeRange& range, std::string_view what)
{
    throw ExtractError(problem, std::format("original release: {}: {}", range.field, what));
}

// The stored bytes of `range`, after the section checks.
std::span<const std::byte> StoredRange(const PeFile& pe, const RecipeRange& range)
{
    if (range.address < pe.imageBase)
        Fail(ExtractProblem::NoSection, range, "is below the image base");
    const std::uint32_t start = range.address - pe.imageBase;
    const auto section = std::ranges::find_if(pe.sections, [&](const PeSection& candidate) {
        return start >= candidate.virtualAddress && start - candidate.virtualAddress < candidate.virtualSize;
    });
    if (section == pe.sections.end())
        Fail(ExtractProblem::NoSection, range, "is in no section");
    if (section->name == ".bind")
        Fail(ExtractProblem::SteamStubSection, range, "is in .bind");
    if ((section->characteristics & (sectionCode | sectionExecute)) != 0)
        Fail(ExtractProblem::CodeSection, range, "is in a section marked as code or executable");
    if ((section->characteristics & sectionInitializedData) == 0)
        Fail(ExtractProblem::NotInitializedData, range, "is in a section not marked as initialized data");
    const std::uint32_t offset = start - section->virtualAddress;
    if (std::uint64_t{offset} + range.capacity > section->storedBytes)
        Fail(ExtractProblem::ZeroTail, range, "runs past the stored bytes of its section");
    return pe.StoredBytes(*section).subspan(offset, range.capacity);
}

// Copies the string at `range` through its first zero byte into `field`,
// which holds zeros. No byte after that zero byte is copied.
template <std::size_t Capacity>
void CopyString(const PeFile& pe, const RecipeRange& range, std::array<char, Capacity>& field)
{
    const std::span<const std::byte> bytes = StoredRange(pe, range);
    const auto zero = std::ranges::find(bytes, std::byte{0});
    if (zero == bytes.end())
        Fail(ExtractProblem::NoTerminator, range, "holds no zero byte");
    const auto toChar = [](std::byte b) { return static_cast<char>(b); };
    if (!range.literalName.empty() &&
        !std::ranges::equal(bytes.begin(), zero, range.literalText.begin(), range.literalText.end(), {}, toChar))
        Fail(ExtractProblem::KnownString, range, std::format("is not the text of {}", range.literalName));
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

std::vector<std::byte> WriteSingleInstancePack(const PeFile& pe, const fileformat::OriginalIdentity& original)
{
    fileformat::SingleInstanceStrings strings{};
    CopyString(pe, singleInstanceRanges[0], strings.mutexName);
    CopyString(pe, singleInstanceRanges[1], strings.firstMessageText);
    CopyString(pe, singleInstanceRanges[2], strings.messageCaption);
    CopyString(pe, singleInstanceRanges[3], strings.secondMessageText);

    std::vector<std::byte> payload;
    Append(payload, strings.mutexName);
    Append(payload, strings.firstMessageText);
    Append(payload, strings.messageCaption);
    Append(payload, strings.secondMessageText);

    const fileformat::PackCatalogueEntry& entry = fileformat::singleInstanceEntry;
    const std::array<fileformat::PackWriteEntry, 1> entries{{{entry.key, entry.version, payload}}};
    return fileformat::WritePackStructure(original.version, original.sha256, entries);
}

} // namespace setup::staged
