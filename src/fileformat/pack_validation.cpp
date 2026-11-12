#include "fileformat/pack_validation.h"

#include "fileformat/byte_reader.h"

#include <algorithm>
#include <stdexcept>
#include <string_view>
#include <utility>

namespace fileformat
{

namespace
{

// The identity of `supported` that the parsed pack records.
const OriginalIdentity& RecordedOriginal(const PackStructure& structure, std::span<const OriginalIdentity> supported)
{
    const auto sameVersion = [&](const OriginalIdentity& identity) {
        return identity.version == structure.originalVersion;
    };
    if (std::ranges::none_of(supported, sameVersion))
        throw UnsupportedOriginalError(OriginalProblem::Version, "data pack: original version: is not supported");
    const auto match = std::ranges::find_if(supported, [&](const OriginalIdentity& identity) {
        return sameVersion(identity) && identity.sha256 == structure.originalSha256;
    });
    if (match == supported.end())
        throw UnsupportedOriginalError(OriginalProblem::Digest,
                                       "data pack: original SHA-256: is not supported for this version");
    return *match;
}

constexpr std::string_view format = "data pack";

[[noreturn]] void Fail(PackCatalogueProblem problem, std::string_view field, std::string_view text)
{
    throw PackCatalogueError(problem, std::string(format) + ": " + std::string(field) + ": " + std::string(text));
}

std::string EntryName(const PackCatalogueEntry& entry)
{
    return "entry " + std::string(entry.key.data(), entry.key.size());
}

// Requires each catalogue entry, then that each entry of the pack is a
// catalogue entry with its version and size.
void CheckCatalogue(std::span<const PackEntry> entries)
{
    for (const PackCatalogueEntry& required : packCatalogue)
    {
        if (std::ranges::find(entries, required.key, &PackEntry::key) == entries.end())
            Fail(PackCatalogueProblem::MissingEntry, EntryName(required), "is not in the pack");
    }
    for (const PackEntry& entry : entries)
    {
        const auto known = std::ranges::find(packCatalogue, entry.key, &PackCatalogueEntry::key);
        if (known == packCatalogue.end())
            Fail(PackCatalogueProblem::UnknownKey, "entry key", "is not in the catalogue");
        if (entry.version != known->version)
            Fail(PackCatalogueProblem::EntryVersion, EntryName(*known), "version is not the catalogue's");
        if (entry.size != known->bytes)
            Fail(PackCatalogueProblem::EntrySize, EntryName(*known), "size is not the catalogue's");
    }
}

// The payload of the catalogue entry `wanted`, which CheckCatalogue found.
std::span<const std::byte> Payload(const OriginalCheckedPack& pack, const PackCatalogueEntry& wanted)
{
    const std::span<const PackEntry> entries = pack.Entries();
    const auto entry = std::ranges::find(entries, wanted.key, &PackEntry::key);
    return pack.EntryBytes(static_cast<std::size_t>(entry - entries.begin()));
}

// Copies the next field's string through its first zero byte into `field`,
// which holds zeros. No byte after that zero byte is copied.
template <std::size_t Capacity>
void DecodeString(ByteReader& reader, std::array<char, Capacity>& field, std::string_view name)
{
    const std::span<const std::byte> bytes = reader.Take(Capacity, name);
    const auto zero = std::ranges::find(bytes, std::byte{0});
    if (zero == bytes.end())
        Fail(PackCatalogueProblem::FieldTerminator, name, "holds no zero byte");
    std::ranges::transform(bytes.begin(), zero, field.begin(), [](std::byte b) { return static_cast<char>(b); });
}

// C1's four fields in order. The payload is singleInstanceEntry.bytes long,
// and every field starts as zeros.
SingleInstanceStrings DecodeSingleInstance(std::span<const std::byte> payload)
{
    ByteReader reader(payload, format);
    SingleInstanceStrings strings{};
    DecodeString(reader, strings.mutexName, "entry INST: mutex name");
    DecodeString(reader, strings.firstMessageText, "entry INST: first message text");
    DecodeString(reader, strings.messageCaption, "entry INST: message caption");
    DecodeString(reader, strings.secondMessageText, "entry INST: second message text");
    return strings;
}

} // namespace

OriginalCheckedPack CheckPackOriginal(std::vector<std::byte> file)
{
    PackStructure structure = ParsePackStructure(std::move(file));
    const OriginalIdentity& original = RecordedOriginal(structure, SupportedOriginals());
    return OriginalCheckedPack(std::move(structure), original);
}

OriginalCheckedPack CheckPackOriginalAgainst(std::vector<std::byte> file, std::span<const OriginalIdentity> supported)
{
    PackStructure structure = ParsePackStructure(std::move(file));
    const OriginalIdentity& original = RecordedOriginal(structure, supported);
    return OriginalCheckedPack(std::move(structure), original);
}

ValidatedPack ValidatePack(std::vector<std::byte> file)
{
    const OriginalCheckedPack pack = CheckPackOriginal(std::move(file));
    CheckCatalogue(pack.Entries());
    return ValidatedPack(pack.Original(), DecodeSingleInstance(Payload(pack, singleInstanceEntry)));
}

std::span<const std::byte> OriginalCheckedPack::EntryBytes(std::size_t index) const&
{
    if (index >= structure.entries.size())
        throw std::out_of_range("data pack: entry index: is past the last entry");
    return structure.EntryBytes(structure.entries[index]);
}

} // namespace fileformat
