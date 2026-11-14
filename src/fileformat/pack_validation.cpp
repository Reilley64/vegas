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

// Decodes the next log path suffix as DecodeString does, then refuses one
// that holds a path separator, '\\' or '/', a colon, which names a drive or
// a stream, or a control character, a byte below 0x20, or is a .. part
// (VEGAS-130). With the separators refused, a .. part is the whole suffix.
// The message names the field and the reason, never the text.
template <std::size_t Capacity>
void DecodeSuffix(ByteReader& reader, std::array<char, Capacity>& field, std::string_view name)
{
    DecodeString(reader, field, name);
    const std::string_view suffix(field.data());
    if (suffix.find_first_of("\\/") != std::string_view::npos)
        Fail(PackCatalogueProblem::SuffixPath, name, "holds a path separator");
    if (suffix.find(':') != std::string_view::npos)
        Fail(PackCatalogueProblem::SuffixPath, name, "holds a colon");
    if (std::ranges::any_of(suffix, [](char c) { return static_cast<unsigned char>(c) < 0x20; }))
        Fail(PackCatalogueProblem::SuffixPath, name, "holds a control character");
    if (suffix == "..")
        Fail(PackCatalogueProblem::SuffixPath, name, "is a .. part");
}

// The log path suffixes' four fields in order. The payload is
// logPathSuffixesEntry.bytes long, and every field starts as zeros.
LogPathSuffixes DecodeLogPathSuffixes(std::span<const std::byte> payload)
{
    ByteReader reader(payload, format);
    LogPathSuffixes suffixes{};
    DecodeSuffix(reader, suffixes.firstSuffix, "entry LOGS: first suffix");
    DecodeSuffix(reader, suffixes.secondSuffix, "entry LOGS: second suffix");
    DecodeSuffix(reader, suffixes.thirdSuffix, "entry LOGS: third suffix");
    DecodeSuffix(reader, suffixes.fourthSuffix, "entry LOGS: fourth suffix");
    return suffixes;
}

// Decodes the next save directory folder as DecodeString does, then refuses
// one that FolderPathRefusal refuses, naming the field and the reason.
template <std::size_t Capacity>
void DecodeFolder(ByteReader& reader, std::array<char, Capacity>& field, std::string_view name)
{
    DecodeString(reader, field, name);
    const std::string_view refusal = FolderPathRefusal(field.data());
    if (!refusal.empty())
        Fail(PackCatalogueProblem::FolderPath, name, refusal);
}

// The save directory strings' ten fields in order; the format of the INI
// paths must also hold exactly one %s and no other conversion, and the four
// folders pass FolderPathRefusal. The payload is saveDirectoryEntry.bytes
// long, and every field starts as zeros.
SaveDirectoryStrings DecodeSaveDirectory(std::span<const std::byte> payload)
{
    ByteReader reader(payload, format);
    SaveDirectoryStrings strings{};
    DecodeString(reader, strings.iniPathFormat, "entry SDIR: INI path format");
    if (!HoldsOneStringConversion(strings.iniPathFormat.data()))
        Fail(PackCatalogueProblem::FormatConversion, "entry SDIR: INI path format",
             "does not hold exactly one %s and no other conversion");
    DecodeString(reader, strings.firstIniName, "entry SDIR: first INI name");
    DecodeString(reader, strings.iniSection, "entry SDIR: INI section");
    DecodeString(reader, strings.settingKey, "entry SDIR: setting key");
    DecodeString(reader, strings.secondIniName, "entry SDIR: second INI name");
    DecodeFolder(reader, strings.localFolder, "entry SDIR: local folder");
    DecodeFolder(reader, strings.documentsFolder, "entry SDIR: documents folder");
    DecodeFolder(reader, strings.gameFolder, "entry SDIR: game folder");
    DecodeFolder(reader, strings.workingFolder, "entry SDIR: working folder");
    DecodeString(reader, strings.defaultIniName, "entry SDIR: default INI name");
    return strings;
}

// The main window class's one field. The payload is
// mainWindowClassEntry.bytes long, and the field starts as zeros.
MainWindowClass DecodeMainWindowClass(std::span<const std::byte> payload)
{
    ByteReader reader(payload, format);
    MainWindowClass windowClass{};
    DecodeString(reader, windowClass.className, "entry WNDC: class name");
    return windowClass;
}

} // namespace

bool HoldsOneStringConversion(std::string_view format)
{
    int strings = 0;
    for (std::size_t at = 0; at < format.size(); ++at)
    {
        if (format[at] != '%')
            continue;
        ++at;
        if (at == format.size())
            return false;
        if (format[at] == 's')
            ++strings;
        else if (format[at] != '%')
            return false;
    }
    return strings == 1;
}

std::string_view FolderPathRefusal(std::string_view folder)
{
    if (folder.find(':') != std::string_view::npos)
        return "holds a colon";
    if (std::ranges::any_of(folder, [](char c) { return static_cast<unsigned char>(c) < 0x20; }))
        return "holds a control character";
    for (std::size_t start = 0;;)
    {
        const std::size_t end = folder.find_first_of("\\/", start);
        if (folder.substr(start, end == std::string_view::npos ? end : end - start) == "..")
            return "holds a .. part";
        if (end == std::string_view::npos)
            return {};
        start = end + 1;
    }
}

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
    const SingleInstanceStrings singleInstance = DecodeSingleInstance(Payload(pack, singleInstanceEntry));
    const LogPathSuffixes logPathSuffixes = DecodeLogPathSuffixes(Payload(pack, logPathSuffixesEntry));
    const SaveDirectoryStrings saveDirectory = DecodeSaveDirectory(Payload(pack, saveDirectoryEntry));
    return ValidatedPack(pack.Original(), singleInstance, logPathSuffixes, saveDirectory,
                         DecodeMainWindowClass(Payload(pack, mainWindowClassEntry)));
}

std::span<const std::byte> OriginalCheckedPack::EntryBytes(std::size_t index) const&
{
    if (index >= structure.entries.size())
        throw std::out_of_range("data pack: entry index: is past the last entry");
    return structure.EntryBytes(structure.entries[index]);
}

} // namespace fileformat
