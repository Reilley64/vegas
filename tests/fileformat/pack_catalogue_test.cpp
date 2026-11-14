#include "check.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_structure.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <format>
#include <functional>
#include <initializer_list>
#include <span>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace
{

using fileformat::OriginalCheckedPack;
using fileformat::OriginalIdentity;
using fileformat::OriginalProblem;
using fileformat::LogPathSuffixes;
using fileformat::MainWindowClass;
using fileformat::PackCatalogueEntry;
using fileformat::PackCatalogueProblem;
using fileformat::PackStructureProblem;
using fileformat::PackWriteEntry;
using fileformat::SaveDirectoryStrings;
using fileformat::SingleInstanceStrings;
using fileformat::ValidatedPack;

// The test spells catalogue version 4 itself, so a change to the source's
// catalogue fails here instead of agreeing with itself.
constexpr std::array<char, 4> singleInstanceKey{'I', 'N', 'S', 'T'};
constexpr std::array<std::size_t, 4> fieldBytes{20, 60, 8, 52};
constexpr std::size_t entryBytes = 140;
constexpr std::array<char, 4> suffixesKey{'L', 'O', 'G', 'S'};
constexpr std::array<std::size_t, 4> suffixBytes{16, 16, 24, 16};
constexpr std::size_t suffixesBytes = 72;
constexpr std::array<char, 4> saveDirectoryKey{'S', 'D', 'I', 'R'};
constexpr std::array<std::size_t, 10> saveBytes{8, 12, 8, 24, 256, 12, 12, 12, 4, 20};
constexpr std::size_t saveDirectoryBytes = 368;
constexpr std::array<char, 4> windowClassKey{'W', 'N', 'D', 'C'};
constexpr std::size_t classBytes = 256;

constexpr bool SameEntry(const PackCatalogueEntry& entry, std::array<char, 4> key, std::uint32_t version,
                         std::size_t bytes)
{
    return entry.key == key && entry.version == version && entry.bytes == bytes;
}

static_assert(fileformat::packCatalogueVersion == 4);
static_assert(fileformat::packCatalogue.size() == 4);
static_assert(SameEntry(fileformat::packCatalogue[0], singleInstanceKey, 1, entryBytes));
static_assert(SameEntry(fileformat::packCatalogue[1], suffixesKey, 1, suffixesBytes));
static_assert(SameEntry(fileformat::packCatalogue[2], saveDirectoryKey, 1, saveDirectoryBytes));
static_assert(SameEntry(fileformat::packCatalogue[3], windowClassKey, 1, classBytes));
static_assert(SameEntry(fileformat::singleInstanceEntry, singleInstanceKey, 1, entryBytes));
static_assert(SameEntry(fileformat::logPathSuffixesEntry, suffixesKey, 1, suffixesBytes));
static_assert(SameEntry(fileformat::saveDirectoryEntry, saveDirectoryKey, 1, saveDirectoryBytes));
static_assert(SameEntry(fileformat::mainWindowClassEntry, windowClassKey, 1, classBytes));

// The save directory strings' ten fields: the recipe bounds, the bound of the
// string the pointer at 0x011a2ff4 reaches, and 256 bytes for the one the
// pointer at 0x011a2ff0 reaches.
static_assert(sizeof(SaveDirectoryStrings::iniPathFormat) == saveBytes[0]);
static_assert(sizeof(SaveDirectoryStrings::firstIniName) == saveBytes[1]);
static_assert(sizeof(SaveDirectoryStrings::iniSection) == saveBytes[2]);
static_assert(sizeof(SaveDirectoryStrings::settingKey) == saveBytes[3]);
static_assert(sizeof(SaveDirectoryStrings::secondIniName) == saveBytes[4]);
static_assert(sizeof(SaveDirectoryStrings::localFolder) == saveBytes[5]);
static_assert(sizeof(SaveDirectoryStrings::documentsFolder) == saveBytes[6]);
static_assert(sizeof(SaveDirectoryStrings::gameFolder) == saveBytes[7]);
static_assert(sizeof(SaveDirectoryStrings::workingFolder) == saveBytes[8]);
static_assert(sizeof(SaveDirectoryStrings::defaultIniName) == saveBytes[9]);

// The log path suffixes' four fields at their recipe bounds.
static_assert(sizeof(LogPathSuffixes::firstSuffix) == suffixBytes[0]);
static_assert(sizeof(LogPathSuffixes::secondSuffix) == suffixBytes[1]);
static_assert(sizeof(LogPathSuffixes::thirdSuffix) == suffixBytes[2]);
static_assert(sizeof(LogPathSuffixes::fourthSuffix) == suffixBytes[3]);

// The main window class's one field at the capacity of the ruling of
// 2026-11-13.
static_assert(sizeof(MainWindowClass::className) == classBytes);

// C1's four fields at the capacities of D8.
static_assert(sizeof(SingleInstanceStrings::mutexName) == fieldBytes[0]);
static_assert(sizeof(SingleInstanceStrings::firstMessageText) == fieldBytes[1]);
static_assert(sizeof(SingleInstanceStrings::messageCaption) == fieldBytes[2]);
static_assert(sizeof(SingleInstanceStrings::secondMessageText) == fieldBytes[3]);

// Only ValidatePack makes a ValidatedPack: nothing converts bytes, a parsed
// structure, a pack whose original was checked or decoded values into one,
// and it is moved, not copied.
static_assert(!std::is_default_constructible_v<ValidatedPack>);
static_assert(!std::is_constructible_v<ValidatedPack, std::vector<std::byte>>);
static_assert(!std::is_constructible_v<ValidatedPack, fileformat::PackStructure>);
static_assert(!std::is_constructible_v<ValidatedPack, OriginalCheckedPack>);
static_assert(!std::is_constructible_v<ValidatedPack, const OriginalCheckedPack&>);
static_assert(!std::is_constructible_v<ValidatedPack, const OriginalIdentity&, const SingleInstanceStrings&>);
static_assert(!std::is_constructible_v<ValidatedPack, const OriginalIdentity&, const SingleInstanceStrings&,
                                       const MainWindowClass&>);
static_assert(!std::is_constructible_v<ValidatedPack, const OriginalIdentity&, const SingleInstanceStrings&,
                                       const LogPathSuffixes&, const MainWindowClass&>);
static_assert(!std::is_constructible_v<ValidatedPack, const OriginalIdentity&, const SingleInstanceStrings&,
                                       const LogPathSuffixes&, const SaveDirectoryStrings&, const MainWindowClass&>);
static_assert(!std::is_copy_constructible_v<ValidatedPack>);
static_assert(!std::is_copy_assignable_v<ValidatedPack>);
static_assert(std::is_nothrow_move_constructible_v<ValidatedPack>);
static_assert(std::is_nothrow_move_assignable_v<ValidatedPack>);

// ValidatePack takes the bytes only: no supported set, no list of required
// entries or keys, and no intermediate pack.
template <typename... Args>
concept Validates = requires(Args&&... args) { fileformat::ValidatePack(std::forward<Args>(args)...); };
static_assert(Validates<std::vector<std::byte>>);
static_assert(!Validates<fileformat::PackStructure>);
static_assert(!Validates<OriginalCheckedPack>);
static_assert(!Validates<std::vector<std::byte>, std::span<const OriginalIdentity>>);
static_assert(!Validates<std::vector<std::byte>, std::array<OriginalIdentity, 1>>);
static_assert(!Validates<std::vector<std::byte>, std::span<const PackCatalogueEntry>>);
static_assert(!Validates<std::vector<std::byte>, std::array<PackCatalogueEntry, 1>>);
static_assert(!Validates<std::vector<std::byte>, std::span<const std::array<char, 4>>>);

// It offers decoded values, never the pack's bytes or directory, and only on
// a pack that outlives the call.
template <typename Pack>
concept OffersOriginal = requires(Pack&& pack) { std::forward<Pack>(pack).Original(); };
template <typename Pack>
concept OffersSingleInstance = requires(Pack&& pack) { std::forward<Pack>(pack).SingleInstance(); };
template <typename Pack>
concept OffersPathSuffixes = requires(Pack&& pack) { std::forward<Pack>(pack).PathSuffixes(); };
template <typename Pack>
concept OffersSaveDirectory = requires(Pack&& pack) { std::forward<Pack>(pack).SaveDirectory(); };
template <typename Pack>
concept OffersWindowClass = requires(Pack&& pack) { std::forward<Pack>(pack).WindowClass(); };
template <typename Pack>
concept OffersEntryBytes = requires(Pack&& pack) { std::forward<Pack>(pack).EntryBytes(0); };
template <typename Pack>
concept OffersEntries = requires(Pack&& pack) { std::forward<Pack>(pack).Entries(); };
template <typename Pack>
concept OffersBytes = requires(Pack&& pack) { std::forward<Pack>(pack).bytes; };
static_assert(OffersOriginal<const ValidatedPack&>);
static_assert(OffersSingleInstance<const ValidatedPack&>);
static_assert(!OffersOriginal<ValidatedPack>);
static_assert(!OffersOriginal<const ValidatedPack>);
static_assert(!OffersSingleInstance<ValidatedPack>);
static_assert(!OffersSingleInstance<const ValidatedPack>);
static_assert(OffersPathSuffixes<const ValidatedPack&>);
static_assert(!OffersPathSuffixes<ValidatedPack>);
static_assert(!OffersPathSuffixes<const ValidatedPack>);
static_assert(OffersSaveDirectory<const ValidatedPack&>);
static_assert(!OffersSaveDirectory<ValidatedPack>);
static_assert(!OffersSaveDirectory<const ValidatedPack>);
static_assert(OffersWindowClass<const ValidatedPack&>);
static_assert(!OffersWindowClass<ValidatedPack>);
static_assert(!OffersWindowClass<const ValidatedPack>);
static_assert(!OffersEntryBytes<const ValidatedPack&>);
static_assert(!OffersEntries<const ValidatedPack&>);
static_assert(!OffersBytes<const ValidatedPack&>);

// The fields of C1 as setup writes them: each string, then zeros to the end
// of its field. A string must leave room for its zero byte.
struct Strings
{
    std::string_view mutexName;
    std::string_view firstMessageText;
    std::string_view messageCaption;
    std::string_view secondMessageText;
};

// Made-up strings: none is a string of the original release.
constexpr Strings someStrings{"test mutex", "first test message", "Test", "second test message"};

std::vector<std::byte> Payload(const Strings& strings)
{
    std::vector<std::byte> payload;
    const std::array<std::string_view, 4> texts{strings.mutexName, strings.firstMessageText, strings.messageCaption,
                                                strings.secondMessageText};
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + fieldBytes[i] - texts[i].size());
    }
    return payload;
}

// The fields of the log path suffixes as setup writes them: each string,
// then zeros to the end of its field.
struct Suffixes
{
    std::string_view firstSuffix;
    std::string_view secondSuffix;
    std::string_view thirdSuffix;
    std::string_view fourthSuffix;
};

// Made-up suffixes: none is a string of the original release.
constexpr Suffixes someSuffixes{"first.test", "second.test", "third test suffix", "fourth.test"};

std::vector<std::byte> SuffixPayload(const Suffixes& suffixes)
{
    std::vector<std::byte> payload;
    const std::array<std::string_view, 4> texts{suffixes.firstSuffix, suffixes.secondSuffix, suffixes.thirdSuffix,
                                                suffixes.fourthSuffix};
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + suffixBytes[i] - texts[i].size());
    }
    return payload;
}

// The offset of field `index` in the log path suffixes' payload.
std::size_t SuffixOffset(std::size_t index)
{
    std::size_t offset = 0;
    for (std::size_t i = 0; i < index; ++i)
        offset += suffixBytes[i];
    return offset;
}

// The fields of the save directory strings as setup writes them: each string,
// then zeros to the end of its field, in catalogue order.
using SaveTexts = std::array<std::string_view, 10>;

// Made-up save directory strings: none is a string of the original release.
// The format holds its one %s. Each leaves at least two bytes of its field
// after its zero byte.
constexpr SaveTexts someSaveTexts{"<%s>",  "first.ini", "Test",      "test setting key", "second test.ini",
                                  "local", "docs test", "game test", "w",                "default.ini"};

std::vector<std::byte> SavePayload(const SaveTexts& texts)
{
    std::vector<std::byte> payload;
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + saveBytes[i] - texts[i].size());
    }
    return payload;
}

// The offset of field `index` in the save directory strings' payload.
std::size_t SaveOffset(std::size_t index)
{
    std::size_t offset = 0;
    for (std::size_t i = 0; i < index; ++i)
        offset += saveBytes[i];
    return offset;
}

// A made-up class name: not a string of the original release.
constexpr std::string_view someClass = "test window class";

// The main window class's field as setup writes it: the class name, then
// zeros to the end of the field.
std::vector<std::byte> ClassPayload(std::string_view className)
{
    std::vector<std::byte> payload;
    for (const char c : className)
        payload.push_back(static_cast<std::byte>(c));
    payload.resize(classBytes);
    return payload;
}

// The offset of field `index` in C1's payload.
std::size_t FieldOffset(std::size_t index)
{
    std::size_t offset = 0;
    for (std::size_t i = 0; i < index; ++i)
        offset += fieldBytes[i];
    return offset;
}

PackWriteEntry Entry(std::string_view key, std::uint32_t version, std::span<const std::byte> payload)
{
    PackWriteEntry entry{{}, version, payload};
    for (std::size_t i = 0; i < entry.key.size(); ++i)
        entry.key[i] = key[i];
    return entry;
}

std::vector<std::byte> Write(std::initializer_list<PackWriteEntry> entries,
                             const std::array<std::uint16_t, 4>& version = supported_release::version,
                             const std::array<std::byte, 32>& sha = supported_release::Sha256())
{
    return fileformat::WritePackStructure(version, sha, std::span(entries.begin(), entries.size()));
}

// A complete pack of catalogue version 4 that records the supported
// release's identity: it is compared, not proved.
std::vector<std::byte> CompletePack(std::span<const std::byte> payload,
                                    std::span<const std::byte> classPayload = ClassPayload(someClass),
                                    std::span<const std::byte> suffixPayload = SuffixPayload(someSuffixes),
                                    std::span<const std::byte> savePayload = SavePayload(someSaveTexts))
{
    return Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload), Entry("SDIR", 1, savePayload),
                  Entry("WNDC", 1, classPayload)});
}

// A complete pack with `savePayload` and made-up values elsewhere.
std::vector<std::byte> SavePack(std::span<const std::byte> savePayload)
{
    return CompletePack(Payload(someStrings), ClassPayload(someClass), SuffixPayload(someSuffixes), savePayload);
}

// Where the container decision puts the header fields this test changes.
namespace at
{
constexpr std::size_t magic = 0;
constexpr std::size_t catalogueVersion = 12;
constexpr std::size_t crc32 = 84;
constexpr std::size_t directory = 88;
constexpr std::size_t recordBytes = 24;
} // namespace at

// CRC-32 one bit at a time, so the test does not check zlib against zlib.
std::uint32_t Crc32(std::uint32_t crc, std::span<const std::byte> bytes)
{
    crc = ~crc;
    for (std::byte byte : bytes)
    {
        crc ^= static_cast<std::uint32_t>(byte);
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc >> 1) ^ ((crc & 1) != 0 ? 0xEDB88320u : 0u);
    }
    return ~crc;
}

void Put(std::vector<std::byte>& bytes, std::size_t offset, std::uint64_t value, std::size_t width)
{
    for (std::size_t i = 0; i < width; ++i)
        bytes[offset + i] = static_cast<std::byte>(value >> (8 * i));
}

// Stores the CRC-32 of the changed bytes, so only the change made is wrong.
void Reseal(std::vector<std::byte>& bytes)
{
    const std::span<const std::byte> all = bytes;
    Put(bytes, at::crc32, Crc32(Crc32(0, all.first(at::crc32)), all.subspan(at::crc32 + 4)), 4);
}

template <std::size_t Capacity>
std::string_view Text(const std::array<char, Capacity>& field)
{
    return {field.data(), static_cast<std::size_t>(std::ranges::find(field, '\0') - field.begin())};
}

// The field holds `text`, then zeros to its end.
template <std::size_t Capacity>
bool Holds(const std::array<char, Capacity>& field, std::string_view text)
{
    return text.size() < Capacity &&
           std::ranges::equal(field.begin(), field.begin() + text.size(), text.begin(), text.end()) &&
           std::all_of(field.begin() + text.size(), field.end(), [](char c) { return c == '\0'; });
}

void CheckStrings(Checks& check, std::string_view name, const ValidatedPack& pack, const Strings& expected)
{
    const SingleInstanceStrings& strings = pack.SingleInstance();
    check.Equal(std::format("{}: mutex name", name), expected.mutexName, Text(strings.mutexName));
    check.Equal(std::format("{}: first message text", name), expected.firstMessageText, Text(strings.firstMessageText));
    check.Equal(std::format("{}: message caption", name), expected.messageCaption, Text(strings.messageCaption));
    check.Equal(std::format("{}: second message text", name), expected.secondMessageText,
                Text(strings.secondMessageText));
    check.Equal(std::format("{}: mutex name field", name), true, Holds(strings.mutexName, expected.mutexName));
    check.Equal(std::format("{}: first message field", name), true,
                Holds(strings.firstMessageText, expected.firstMessageText));
    check.Equal(std::format("{}: caption field", name), true, Holds(strings.messageCaption, expected.messageCaption));
    check.Equal(std::format("{}: second message field", name), true,
                Holds(strings.secondMessageText, expected.secondMessageText));
}

void CheckSuffixes(Checks& check, std::string_view name, const ValidatedPack& pack, const Suffixes& expected)
{
    const LogPathSuffixes& suffixes = pack.PathSuffixes();
    check.Equal(std::format("{}: first suffix", name), expected.firstSuffix, Text(suffixes.firstSuffix));
    check.Equal(std::format("{}: second suffix", name), expected.secondSuffix, Text(suffixes.secondSuffix));
    check.Equal(std::format("{}: third suffix", name), expected.thirdSuffix, Text(suffixes.thirdSuffix));
    check.Equal(std::format("{}: fourth suffix", name), expected.fourthSuffix, Text(suffixes.fourthSuffix));
    check.Equal(std::format("{}: first suffix field", name), true, Holds(suffixes.firstSuffix, expected.firstSuffix));
    check.Equal(std::format("{}: second suffix field", name), true,
                Holds(suffixes.secondSuffix, expected.secondSuffix));
    check.Equal(std::format("{}: third suffix field", name), true, Holds(suffixes.thirdSuffix, expected.thirdSuffix));
    check.Equal(std::format("{}: fourth suffix field", name), true,
                Holds(suffixes.fourthSuffix, expected.fourthSuffix));
}

void CheckSaveDirectory(Checks& check, std::string_view name, const ValidatedPack& pack, const SaveTexts& expected)
{
    const SaveDirectoryStrings& strings = pack.SaveDirectory();
    const auto field = [&](std::string_view what, const auto& actual, std::size_t index) {
        check.Equal(std::format("{}: {}", name, what), expected[index], Text(actual));
        check.Equal(std::format("{}: {} field", name, what), true, Holds(actual, expected[index]));
    };
    field("INI path format", strings.iniPathFormat, 0);
    field("first INI name", strings.firstIniName, 1);
    field("INI section", strings.iniSection, 2);
    field("setting key", strings.settingKey, 3);
    field("second INI name", strings.secondIniName, 4);
    field("local folder", strings.localFolder, 5);
    field("documents folder", strings.documentsFolder, 6);
    field("game folder", strings.gameFolder, 7);
    field("working folder", strings.workingFolder, 8);
    field("default INI name", strings.defaultIniName, 9);
}

void CheckClass(Checks& check, std::string_view name, const ValidatedPack& pack, std::string_view expected)
{
    const MainWindowClass& windowClass = pack.WindowClass();
    check.Equal(std::format("{}: class name", name), expected, Text(windowClass.className));
    check.Equal(std::format("{}: class name field", name), true, Holds(windowClass.className, expected));
}

void Accepts(Checks& check, std::string_view name, const std::vector<std::byte>& file, const Strings& expected,
             std::string_view expectedClass = someClass, const Suffixes& expectedSuffixes = someSuffixes,
             const SaveTexts& expectedSave = someSaveTexts)
{
    const ValidatedPack pack = fileformat::ValidatePack(file);
    check.Equal(std::format("{}: original version", name), true, pack.Original().version == supported_release::version);
    check.Equal(std::format("{}: original SHA-256", name), true, pack.Original().sha256 == supported_release::Sha256());
    CheckStrings(check, name, pack, expected);
    CheckSuffixes(check, name, pack, expectedSuffixes);
    CheckSaveDirectory(check, name, pack, expectedSave);
    CheckClass(check, name, pack, expectedClass);
}

// A complete pack whose save directory strings are `texts` is accepted with
// them.
void AcceptsSave(Checks& check, std::string_view name, const SaveTexts& texts)
{
    Accepts(check, name, SavePack(SavePayload(texts)), someStrings, someClass, someSuffixes, texts);
}

// Expects ValidatePack to throw `Error` with the problem given and, when
// `field` is not empty, a message that names it.
template <typename Error, typename Problem>
void Refuses(Checks& check, std::string_view name, const std::vector<std::byte>& file, Problem expected,
             std::string_view field = {})
{
    try
    {
        fileformat::ValidatePack(file);
        check.Fail(name, "was accepted");
    }
    catch (const Error& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was refused for another reason: {}", error.what()));
        else if (std::string_view(error.what()).find(field) == std::string_view::npos)
            check.Fail(name, std::format("was refused for another field: {}", error.what()));
    }
    catch (const std::exception& error)
    {
        check.Fail(name, std::format("was refused with another kind of error: {}", error.what()));
    }
}

void RefusesForTheCatalogue(Checks& check, std::string_view name, const std::vector<std::byte>& file,
                            PackCatalogueProblem expected, std::string_view field = {})
{
    Refuses<fileformat::PackCatalogueError>(check, name, file, expected, field);
}

void AcceptsACompletePack(Checks& check)
{
    Accepts(check, "complete pack", CompletePack(Payload(someStrings)), someStrings);

    // Each string as long as its field allows, its zero byte the field's last.
    const std::string longest0(fieldBytes[0] - 1, 'm');
    const std::string longest1(fieldBytes[1] - 1, 'f');
    const std::string longest2(fieldBytes[2] - 1, 'c');
    const std::string longest3(fieldBytes[3] - 1, 's');
    const Strings longest{longest0, longest1, longest2, longest3};
    const std::string longestClass(classBytes - 1, 'w');
    const std::string longestSuffix0(suffixBytes[0] - 1, '0');
    const std::string longestSuffix1(suffixBytes[1] - 1, '1');
    const std::string longestSuffix2(suffixBytes[2] - 1, '2');
    const std::string longestSuffix3(suffixBytes[3] - 1, '3');
    const Suffixes longestSuffixes{longestSuffix0, longestSuffix1, longestSuffix2, longestSuffix3};
    Accepts(check, "longest strings",
            CompletePack(Payload(longest), ClassPayload(longestClass), SuffixPayload(longestSuffixes)), longest,
            longestClass, longestSuffixes);

    // Each field only its zero byte and zeros.
    const Strings empty{"", "", "", ""};
    const Suffixes emptySuffixes{"", "", "", ""};
    Accepts(check, "empty strings", CompletePack(Payload(empty), ClassPayload(""), SuffixPayload(emptySuffixes)),
            empty, "", emptySuffixes);

    // Every byte value but zero is kept as it is. C1's fields hold 136
    // characters, so two packs carry the 255 values; the class name holds
    // all 255.
    std::string everyByte;
    for (int c = 1; c < 256; ++c)
        everyByte.push_back(static_cast<char>(c));
    const Strings allBytes{std::string_view(everyByte).substr(0, 19), std::string_view(everyByte).substr(19, 59),
                           std::string_view(everyByte).substr(78, 7), std::string_view(everyByte).substr(85, 51)};
    Accepts(check, "byte values 1 to 136", CompletePack(Payload(allBytes), ClassPayload(everyByte)), allBytes,
            everyByte);
    const std::string_view rest = std::string_view(everyByte).substr(136);
    const Strings restBytes{rest.substr(0, 19), rest.substr(19, 59), rest.substr(78, 7), rest.substr(85)};
    Accepts(check, "byte values 137 to 255", CompletePack(Payload(restBytes)), restBytes);

    // Every byte value that a suffix may hold, all but zero, the control
    // characters below 0x20, '/', ':' and '\\' (RefusesASuffixPath), is kept
    // as it is. The suffixes' fields hold 68 characters, so four packs carry
    // the 221 values.
    std::string suffixByte;
    for (int c = 0x20; c < 256; ++c)
    {
        if (c != '/' && c != ':' && c != '\\')
            suffixByte.push_back(static_cast<char>(c));
    }
    check.Equal("suffix byte values", std::size_t{221}, suffixByte.size());
    for (std::size_t first = 0; first < suffixByte.size(); first += 68)
    {
        const std::string_view part = std::string_view(suffixByte).substr(first, 68);
        const auto piece = [&](std::size_t at, std::size_t count) {
            return at < part.size() ? part.substr(at, count) : std::string_view();
        };
        const Suffixes bytes{piece(0, 15), piece(15, 15), piece(30, 23), piece(53, 15)};
        Accepts(check, std::format("suffix byte values from {}", first),
                CompletePack(Payload(someStrings), ClassPayload(someClass), SuffixPayload(bytes)), someStrings,
                someClass, bytes);
    }

    // Each save directory string as long as its field allows, the format
    // with its %s; each only its zero byte, but the format, which needs its
    // %s; and the second INI name, of 256 bytes, holding the 255 values.
    std::array<std::string, 10> longestSaveTexts;
    SaveTexts longestSave;
    for (std::size_t i = 0; i < saveBytes.size(); ++i)
    {
        longestSaveTexts[i] = std::string(saveBytes[i] - 1, static_cast<char>('a' + i));
        if (i == 0)
            longestSaveTexts[i].replace(0, 2, "%s");
        longestSave[i] = longestSaveTexts[i];
    }
    AcceptsSave(check, "longest save directory strings", longestSave);
    AcceptsSave(check, "empty save directory strings", {"%s", "", "", "", "", "", "", "", "", ""});
    SaveTexts saveBytesTexts = someSaveTexts;
    saveBytesTexts[4] = everyByte;
    AcceptsSave(check, "second INI name byte values 1 to 255", saveBytesTexts);
}

// The decoded field holds nothing after its first zero byte, whatever the
// pack holds there.
void KeepsNothingAfterTheZeroByte(Checks& check)
{
    for (std::size_t field = 0; field < fieldBytes.size(); ++field)
    {
        std::vector<std::byte> payload = Payload(someStrings);
        const std::size_t end = FieldOffset(field) + fieldBytes[field];
        payload[end - 1] = std::byte{'x'};
        payload[end - 2] = std::byte{0xFF};
        Accepts(check, std::format("bytes after the zero byte of field {}", field), CompletePack(payload), someStrings);
    }
    for (std::size_t field = 0; field < suffixBytes.size(); ++field)
    {
        std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
        const std::size_t end = SuffixOffset(field) + suffixBytes[field];
        suffixPayload[end - 1] = std::byte{'x'};
        suffixPayload[end - 2] = std::byte{0xFF};
        Accepts(check, std::format("bytes after the zero byte of suffix {}", field),
                CompletePack(Payload(someStrings), ClassPayload(someClass), suffixPayload), someStrings);
    }
    for (std::size_t field = 0; field < saveBytes.size(); ++field)
    {
        std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
        const std::size_t end = SaveOffset(field) + saveBytes[field];
        savePayload[end - 1] = std::byte{'x'};
        savePayload[end - 2] = std::byte{0xFF};
        Accepts(check, std::format("bytes after the zero byte of save directory field {}", field),
                SavePack(savePayload), someStrings);
    }
    // Conversions after the format's zero byte are not part of it.
    std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    savePayload[5] = std::byte{'%'};
    savePayload[6] = std::byte{'n'};
    Accepts(check, "a conversion after the zero byte of the format", SavePack(savePayload), someStrings);
    std::vector<std::byte> classPayload = ClassPayload(someClass);
    classPayload[classBytes - 1] = std::byte{'x'};
    classPayload[classBytes - 2] = std::byte{0xFF};
    Accepts(check, "bytes after the zero byte of the class name", CompletePack(Payload(someStrings), classPayload),
            someStrings);
}

// The format of the INI paths holds exactly one %s, which reads the one
// argument its consumer passes; a %% writes a '%' and reads no argument, so
// it may stand beside it.
void AcceptsOneStringFormats(Checks& check)
{
    for (const std::string_view format : {"%s", "<%s>", "%%%s", "%s%%", "a%%b%s", "%%%%%s", "%s%%%%"})
    {
        check.Equal(std::format("one string: \"{}\"", format), true, fileformat::HoldsOneStringConversion(format));
        SaveTexts texts = someSaveTexts;
        texts[0] = format;
        AcceptsSave(check, std::format("format \"{}\"", format), texts);
    }
}

// Every other format is refused: no %s, a second %s, a conversion the
// consumer passes no argument for, %n among them, which writes through one,
// a flag, width, precision or length, and a '%' at the end.
void RefusesOtherFormats(Checks& check)
{
    for (const std::string_view format :
         {"", "abc", "%%s", "%n", "%s%n", "%n%s", "%s%s", "%s-%s", "%d", "%p", "%c%s", "%S", "%5s", "%-s", "%.3s",
          "%*s", "%ls", "%hs", "%", "%s%", "%%%", "% s"})
    {
        check.Equal(std::format("not one string: \"{}\"", format), false,
                    fileformat::HoldsOneStringConversion(format));
        SaveTexts texts = someSaveTexts;
        texts[0] = format;
        RefusesForTheCatalogue(check, std::format("format \"{}\"", format), SavePack(SavePayload(texts)),
                               PackCatalogueProblem::FormatConversion, "entry SDIR: INI path format");
    }
    // The other fields are not formats.
    SaveTexts texts = someSaveTexts;
    texts[1] = "%n%s%s";
    AcceptsSave(check, "conversions in the first INI name", texts);
}

void RefusesAMissingEntry(Checks& check)
{
    const std::vector<std::byte> payload = Payload(someStrings);
    const std::vector<std::byte> classPayload = ClassPayload(someClass);
    const std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
    const std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    for (const std::string_view key : {"AAAA", "INSS", "INSU", "inst", "\x7F\x7F\x7F\x7F"})
        RefusesForTheCatalogue(check, std::format("only {}", key), Write({Entry(key, 1, payload)}),
                               PackCatalogueProblem::MissingEntry, "entry INST");
    RefusesForTheCatalogue(check, "two other entries", Write({Entry("AAAA", 1, payload), Entry("ZZZZ", 1, payload)}),
                           PackCatalogueProblem::MissingEntry, "entry INST");
    RefusesForTheCatalogue(check, "only WNDC", Write({Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::MissingEntry, "entry INST");
    RefusesForTheCatalogue(check, "only LOGS", Write({Entry("LOGS", 1, suffixPayload)}),
                           PackCatalogueProblem::MissingEntry, "entry INST");
    RefusesForTheCatalogue(check, "only SDIR", Write({Entry("SDIR", 1, savePayload)}),
                           PackCatalogueProblem::MissingEntry, "entry INST");

    // C1 alone is the complete pack of catalogue version 1, C1 and the main
    // window class that of version 2, and those and the log path suffixes
    // that of version 3; version 4 also requires the save directory strings.
    RefusesForTheCatalogue(check, "only INST", Write({Entry("INST", 1, payload)}), PackCatalogueProblem::MissingEntry,
                           "entry LOGS");
    RefusesForTheCatalogue(check, "INST and WNDC", Write({Entry("INST", 1, payload), Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::MissingEntry, "entry LOGS");
    for (const std::string_view key : {"LOGR", "LOGT", "LOG\x7F"})
        RefusesForTheCatalogue(check, std::format("INST, {}, SDIR and WNDC", key),
                               Write({Entry("INST", 1, payload), Entry(key, 1, suffixPayload),
                                      Entry("SDIR", 1, savePayload), Entry("WNDC", 1, classPayload)}),
                               PackCatalogueProblem::MissingEntry, "entry LOGS");
    RefusesForTheCatalogue(check, "INST, SDIR, WNDC and logs",
                           Write({Entry("INST", 1, payload), Entry("SDIR", 1, savePayload),
                                  Entry("WNDC", 1, classPayload), Entry("logs", 1, suffixPayload)}),
                           PackCatalogueProblem::MissingEntry, "entry LOGS");
    RefusesForTheCatalogue(check, "INST, LOGS and WNDC",
                           Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                  Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::MissingEntry, "entry SDIR");
    for (const std::string_view key : {"SDIQ", "SDIS", "SDI\x7F"})
        RefusesForTheCatalogue(check, std::format("INST, LOGS, {} and WNDC", key),
                               Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                      Entry(key, 1, savePayload), Entry("WNDC", 1, classPayload)}),
                               PackCatalogueProblem::MissingEntry, "entry SDIR");
    RefusesForTheCatalogue(check, "INST, LOGS, WNDC and sdir",
                           Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                  Entry("WNDC", 1, classPayload), Entry("sdir", 1, savePayload)}),
                           PackCatalogueProblem::MissingEntry, "entry SDIR");
    for (const std::string_view key : {"WNDB", "WNDD", "wndc", "ZZZZ"})
        RefusesForTheCatalogue(check, std::format("INST, LOGS, SDIR and {}", key),
                               Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                      Entry("SDIR", 1, savePayload), Entry(key, 1, classPayload)}),
                               PackCatalogueProblem::MissingEntry, "entry WNDC");
}

void RefusesAnUnknownKey(Checks& check)
{
    const std::vector<std::byte> payload = Payload(someStrings);
    const std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
    const std::vector<std::byte> classPayload = ClassPayload(someClass);
    const std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    const std::vector<std::byte> one(1, std::byte{1});
    const PackWriteEntry inst = Entry("INST", 1, payload);
    const PackWriteEntry logs = Entry("LOGS", 1, suffixPayload);
    const PackWriteEntry sdir = Entry("SDIR", 1, savePayload);
    const PackWriteEntry wndc = Entry("WNDC", 1, classPayload);
    RefusesForTheCatalogue(check, "a key before", Write({Entry("AAAA", 1, payload), inst, logs, sdir, wndc}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key between INST and LOGS",
                           Write({inst, Entry("KKKK", 1, one), logs, sdir, wndc}), PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key between LOGS and SDIR",
                           Write({inst, logs, Entry("MMMM", 1, one), sdir, wndc}), PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key between SDIR and WNDC",
                           Write({inst, logs, sdir, Entry("TTTT", 1, one), wndc}), PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key after", Write({inst, logs, sdir, wndc, Entry("ZZZZ", 1, one)}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key one byte above INST",
                           Write({inst, Entry("INSU", 1, payload), logs, sdir, wndc}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key one byte above LOGS",
                           Write({inst, logs, Entry("LOGT", 1, suffixPayload), sdir, wndc}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key one byte above SDIR",
                           Write({inst, logs, sdir, Entry("SDIS", 1, savePayload), wndc}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a key one byte above WNDC", Write({inst, logs, sdir, wndc, Entry("WNDD", 1, one)}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(check, "a lowest key",
                           Write({Entry(std::string_view("\0\0\0\0", 4), 1, one), inst, logs, sdir, wndc}),
                           PackCatalogueProblem::UnknownKey);

    // A key that is not ASCII, which the writer refuses to write: the reader
    // leaves it to the catalogue.
    std::vector<std::byte> file = Write({inst, logs, sdir, wndc, Entry("ZZZZ", 1, one)});
    file[at::directory + 4 * at::recordBytes] = std::byte{0x80};
    Reseal(file);
    RefusesForTheCatalogue(check, "a key that is not ASCII", file, PackCatalogueProblem::UnknownKey);
}

void RefusesAnotherEntryVersion(Checks& check)
{
    const std::vector<std::byte> payload = Payload(someStrings);
    const std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
    const std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    const std::vector<std::byte> classPayload = ClassPayload(someClass);
    for (const std::uint32_t version : {0u, 2u, 0x80000001u, 0xFFFFFFFFu})
    {
        RefusesForTheCatalogue(check, std::format("INST version {}", version),
                               Write({Entry("INST", version, payload), Entry("LOGS", 1, suffixPayload),
                                      Entry("SDIR", 1, savePayload), Entry("WNDC", 1, classPayload)}),
                               PackCatalogueProblem::EntryVersion, "entry INST");
        RefusesForTheCatalogue(check, std::format("LOGS version {}", version),
                               Write({Entry("INST", 1, payload), Entry("LOGS", version, suffixPayload),
                                      Entry("SDIR", 1, savePayload), Entry("WNDC", 1, classPayload)}),
                               PackCatalogueProblem::EntryVersion, "entry LOGS");
        RefusesForTheCatalogue(check, std::format("SDIR version {}", version),
                               Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                      Entry("SDIR", version, savePayload), Entry("WNDC", 1, classPayload)}),
                               PackCatalogueProblem::EntryVersion, "entry SDIR");
        RefusesForTheCatalogue(check, std::format("WNDC version {}", version),
                               Write({Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                      Entry("SDIR", 1, savePayload), Entry("WNDC", version, classPayload)}),
                               PackCatalogueProblem::EntryVersion, "entry WNDC");
    }
}

void RefusesAnotherSize(Checks& check)
{
    const std::vector<std::byte> payload = Payload(someStrings);
    for (const std::size_t size : {std::size_t{1}, entryBytes - 1, entryBytes + 1, 2 * entryBytes})
    {
        std::vector<std::byte> other(payload.begin(), payload.begin() + std::min(size, payload.size()));
        other.resize(size);
        RefusesForTheCatalogue(check, std::format("INST size {}", size), CompletePack(other),
                               PackCatalogueProblem::EntrySize, "entry INST");
    }
    const std::vector<std::byte> classPayload = ClassPayload(someClass);
    for (const std::size_t size : {std::size_t{1}, classBytes - 1, classBytes + 1, 2 * classBytes})
    {
        std::vector<std::byte> other(classPayload.begin(),
                                     classPayload.begin() + static_cast<std::ptrdiff_t>(std::min(size, classBytes)));
        other.resize(size);
        RefusesForTheCatalogue(check, std::format("WNDC size {}", size), CompletePack(payload, other),
                               PackCatalogueProblem::EntrySize, "entry WNDC");
    }
    const std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
    for (const std::size_t size : {std::size_t{1}, suffixesBytes - 1, suffixesBytes + 1, 2 * suffixesBytes})
    {
        std::vector<std::byte> other(suffixPayload.begin(),
                                     suffixPayload.begin() +
                                         static_cast<std::ptrdiff_t>(std::min(size, suffixesBytes)));
        other.resize(size);
        RefusesForTheCatalogue(check, std::format("LOGS size {}", size), CompletePack(payload, classPayload, other),
                               PackCatalogueProblem::EntrySize, "entry LOGS");
    }
    const std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    for (const std::size_t size :
         {std::size_t{1}, saveDirectoryBytes - 1, saveDirectoryBytes + 1, 2 * saveDirectoryBytes})
    {
        std::vector<std::byte> other(savePayload.begin(),
                                     savePayload.begin() +
                                         static_cast<std::ptrdiff_t>(std::min(size, saveDirectoryBytes)));
        other.resize(size);
        RefusesForTheCatalogue(check, std::format("SDIR size {}", size), SavePack(other),
                               PackCatalogueProblem::EntrySize, "entry SDIR");
    }
}

constexpr std::array<std::string_view, 4> fieldNames{"mutex name", "first message text", "message caption",
                                                     "second message text"};
constexpr std::array<std::string_view, 4> suffixNames{"entry LOGS: first suffix", "entry LOGS: second suffix",
                                                      "entry LOGS: third suffix", "entry LOGS: fourth suffix"};
constexpr std::array<std::string_view, 10> saveNames{
    "entry SDIR: INI path format", "entry SDIR: first INI name",   "entry SDIR: INI section",
    "entry SDIR: setting key",     "entry SDIR: second INI name",  "entry SDIR: local folder",
    "entry SDIR: documents folder", "entry SDIR: game folder",     "entry SDIR: working folder",
    "entry SDIR: default INI name"};

// A field with no zero byte is refused, even when the next field is all
// zeros: the zero byte must be inside the field.
void RefusesAFieldWithNoZeroByte(Checks& check)
{
    for (std::size_t field = 0; field < fieldBytes.size(); ++field)
    {
        for (const bool emptyAfter : {false, true})
        {
            std::vector<std::byte> payload = Payload(someStrings);
            std::fill_n(payload.begin() + static_cast<std::ptrdiff_t>(FieldOffset(field)), fieldBytes[field],
                        std::byte{'x'});
            if (emptyAfter)
                std::fill(payload.begin() + static_cast<std::ptrdiff_t>(FieldOffset(field) + fieldBytes[field]),
                          payload.end(), std::byte{0});
            RefusesForTheCatalogue(check,
                                   std::format("field {}, no zero byte{}", field, emptyAfter ? ", zeros after" : ""),
                                   CompletePack(payload), PackCatalogueProblem::FieldTerminator, fieldNames[field]);
        }
    }
    for (std::size_t field = 0; field < suffixBytes.size(); ++field)
    {
        for (const bool emptyAfter : {false, true})
        {
            std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
            std::fill_n(suffixPayload.begin() + static_cast<std::ptrdiff_t>(SuffixOffset(field)), suffixBytes[field],
                        std::byte{'x'});
            if (emptyAfter)
                std::fill(suffixPayload.begin() +
                              static_cast<std::ptrdiff_t>(SuffixOffset(field) + suffixBytes[field]),
                          suffixPayload.end(), std::byte{0});
            RefusesForTheCatalogue(
                check, std::format("suffix {}, no zero byte{}", field, emptyAfter ? ", zeros after" : ""),
                CompletePack(Payload(someStrings), ClassPayload(someClass), suffixPayload),
                PackCatalogueProblem::FieldTerminator, suffixNames[field]);
        }
    }
    for (std::size_t field = 0; field < saveBytes.size(); ++field)
    {
        for (const bool emptyAfter : {false, true})
        {
            std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
            std::fill_n(savePayload.begin() + static_cast<std::ptrdiff_t>(SaveOffset(field)), saveBytes[field],
                        std::byte{'x'});
            if (emptyAfter)
                std::fill(savePayload.begin() + static_cast<std::ptrdiff_t>(SaveOffset(field) + saveBytes[field]),
                          savePayload.end(), std::byte{0});
            RefusesForTheCatalogue(
                check, std::format("save directory field {}, no zero byte{}", field, emptyAfter ? ", zeros after" : ""),
                SavePack(savePayload), PackCatalogueProblem::FieldTerminator, saveNames[field]);
        }
    }
    // A format whose %s fills it with no zero byte is refused for the zero
    // byte.
    std::vector<std::byte> formatNoZero = SavePayload(someSaveTexts);
    for (std::size_t i = 0; i < saveBytes[0]; ++i)
        formatNoZero[i] = std::byte{static_cast<unsigned char>(i == 0 ? '%' : i == 1 ? 's' : 'x')};
    RefusesForTheCatalogue(check, "format with its %s, no zero byte", SavePack(formatNoZero),
                           PackCatalogueProblem::FieldTerminator, saveNames[0]);
    const std::vector<std::byte> noZero(classBytes, std::byte{'x'});
    RefusesForTheCatalogue(check, "class name, no zero byte", CompletePack(Payload(someStrings), noZero),
                           PackCatalogueProblem::FieldTerminator, "entry WNDC: class name");
}

// A log path suffix that holds a path separator, a colon or a control
// character, or is a .. part, is refused in each of the four fields, with
// the field and the reason in the message (VEGAS-130). Ordinary names, dots
// and spaces among them, are accepted.
void RefusesASuffixPath(Checks& check)
{
    struct Refused
    {
        std::string_view suffix;
        std::string_view reason;
    };
    const std::array<Refused, 14> refused{{
        {"a\\b", "holds a path separator"},
        {"\\a", "holds a path separator"},
        {"a\\", "holds a path separator"},
        {"a/b", "holds a path separator"},
        {"/a", "holds a path separator"},
        {"..\\a", "holds a path separator"},
        {"../a", "holds a path separator"},
        {"C:a", "holds a colon"},
        {"a:b", "holds a colon"},
        {"a\tb", "holds a control character"},
        {"\x01", "holds a control character"},
        {"a\x1f", "holds a control character"},
        {"\n", "holds a control character"},
        {"..", "is a .. part"},
    }};
    const std::array<std::string_view, 9> accepted{".", "...", "..a", "a..", "a..b", ". .", "a b", "test.log", "\x7f"};
    const std::array<std::string_view, 4> ordinary{someSuffixes.firstSuffix, someSuffixes.secondSuffix,
                                                   someSuffixes.thirdSuffix, someSuffixes.fourthSuffix};
    for (std::size_t field = 0; field < suffixBytes.size(); ++field)
    {
        std::array<std::string_view, 4> texts = ordinary;
        for (std::size_t i = 0; i < refused.size(); ++i)
        {
            texts[field] = refused[i].suffix;
            const Suffixes suffixes{texts[0], texts[1], texts[2], texts[3]};
            RefusesForTheCatalogue(check, std::format("suffix {}, refused case {}", field, i),
                                   CompletePack(Payload(someStrings), ClassPayload(someClass), SuffixPayload(suffixes)),
                                   PackCatalogueProblem::SuffixPath,
                                   std::format("{}: {}", suffixNames[field], refused[i].reason));
        }
        for (std::size_t i = 0; i < accepted.size(); ++i)
        {
            texts[field] = accepted[i];
            const Suffixes suffixes{texts[0], texts[1], texts[2], texts[3]};
            Accepts(check, std::format("suffix {}, accepted case {}", field, i),
                    CompletePack(Payload(someStrings), ClassPayload(someClass), SuffixPayload(suffixes)), someStrings,
                    someClass, suffixes);
        }
    }
}

// A save directory folder that holds a colon or a control character, or
// has a .. part, is refused in each of the four folder fields that it fits,
// with the field and the reason in the message; FolderPathRefusal gives the
// same reason. Folder names with separators, leading, inner or last, and
// names of dots other than .. are accepted (ruling of 2026-11-14). The
// other fields are not folders.
void RefusesAFolderPath(Checks& check)
{
    struct Refused
    {
        std::string_view folder;
        std::string_view reason;
    };
    const std::array<Refused, 20> refused{{
        {"C:", "holds a colon"},
        {"C:a", "holds a colon"},
        {"C:\\a", "holds a colon"},
        {"a:b", "holds a colon"},
        {":", "holds a colon"},
        {"\x01", "holds a control character"},
        {"a\tb", "holds a control character"},
        {"a\x1f", "holds a control character"},
        {"\n", "holds a control character"},
        {"\\a\r", "holds a control character"},
        {"..", "holds a .. part"},
        {"..\\", "holds a .. part"},
        {"\\..", "holds a .. part"},
        {"../", "holds a .. part"},
        {"/..", "holds a .. part"},
        {"..\\a", "holds a .. part"},
        {"a\\..\\b", "holds a .. part"},
        {"a/../b", "holds a .. part"},
        {"\\..\\", "holds a .. part"},
        {"a\\/..", "holds a .. part"},
    }};
    const std::array<std::string_view, 18> accepted{
        "\\a", "a\\b", "a\\",  "/a/b/", "\\",   "/",    ".",     "...",  "..a",
        "a..", ".\\", "\\.\\", "a b",  "\x7f", "a..\\b", "\\...", "\\\\a", ""};
    constexpr std::array<std::size_t, 4> folders{5, 6, 7, 8};
    for (const Refused& item : refused)
        check.Equal(std::format("folder refusal of \"{}\"", item.folder), item.reason,
                    fileformat::FolderPathRefusal(item.folder));
    for (const std::string_view folder : accepted)
        check.Equal(std::format("folder accepted: \"{}\"", folder), std::string_view(),
                    fileformat::FolderPathRefusal(folder));
    std::size_t refusedPacks = 0;
    std::size_t acceptedPacks = 0;
    for (const std::size_t field : folders)
    {
        for (std::size_t i = 0; i < refused.size(); ++i)
        {
            if (refused[i].folder.size() >= saveBytes[field])
                continue;
            SaveTexts texts = someSaveTexts;
            texts[field] = refused[i].folder;
            RefusesForTheCatalogue(check, std::format("save directory field {}, refused case {}", field, i),
                                   SavePack(SavePayload(texts)), PackCatalogueProblem::FolderPath,
                                   std::format("{}: {}", saveNames[field], refused[i].reason));
            ++refusedPacks;
        }
        for (std::size_t i = 0; i < accepted.size(); ++i)
        {
            if (accepted[i].size() >= saveBytes[field])
                continue;
            SaveTexts texts = someSaveTexts;
            texts[field] = accepted[i];
            AcceptsSave(check, std::format("save directory field {}, accepted case {}", field, i), texts);
            ++acceptedPacks;
        }
    }
    check.Equal("refused folder packs", std::size_t{3 * 20 + 14}, refusedPacks);
    check.Equal("accepted folder packs", std::size_t{3 * 18 + 15}, acceptedPacks);

    // The other fields are not folders.
    for (const std::size_t field : {std::size_t{1}, std::size_t{2}, std::size_t{3}, std::size_t{4}, std::size_t{9}})
    {
        SaveTexts texts = someSaveTexts;
        texts[field] = "C:\\..";
        AcceptsSave(check, std::format("save directory field {}, not a folder", field), texts);
    }
}

// The source's catalogue version is accepted (AcceptsACompletePack); the
// versions next to it are refused.
void RefusesAnotherCatalogueVersion(Checks& check)
{
    constexpr std::uint32_t source = fileformat::packCatalogueVersion;
    for (const std::uint32_t version : {0u, source - 1, source + 1, 0xFFFFFFFFu})
    {
        if (version == source)
            continue;
        std::vector<std::byte> file = CompletePack(Payload(someStrings));
        Put(file, at::catalogueVersion, version, 4);
        Reseal(file);
        Refuses<fileformat::PackStructureError>(check, std::format("catalogue version {}", version), file,
                                                PackStructureProblem::CatalogueVersion);
    }
}

// A pack of catalogue version 1, C1 alone with version 1 in its header, as
// setup prepared it before version 2: refused for its catalogue version,
// before its entries are looked at.
void RefusesAVersionOnePack(Checks& check)
{
    std::vector<std::byte> file = Write({Entry("INST", 1, Payload(someStrings))});
    Put(file, at::catalogueVersion, 1, 4);
    Reseal(file);
    Refuses<fileformat::PackStructureError>(check, "version 1 pack", file, PackStructureProblem::CatalogueVersion,
                                            "catalogue version: is not 4");
}

// A pack of catalogue version 2, C1 and the main window class with version 2
// in its header, as setup prepared it before version 3: refused for its
// catalogue version, before its entries are looked at.
void RefusesAVersionTwoPack(Checks& check)
{
    std::vector<std::byte> file =
        Write({Entry("INST", 1, Payload(someStrings)), Entry("WNDC", 1, ClassPayload(someClass))});
    Put(file, at::catalogueVersion, 2, 4);
    Reseal(file);
    Refuses<fileformat::PackStructureError>(check, "version 2 pack", file, PackStructureProblem::CatalogueVersion,
                                            "catalogue version: is not 4");
}

// A pack of catalogue version 3, C1, the log path suffixes and the main
// window class with version 3 in its header, as setup prepared it before
// version 4: refused for its catalogue version, before its entries are
// looked at.
void RefusesAVersionThreePack(Checks& check)
{
    std::vector<std::byte> file = Write({Entry("INST", 1, Payload(someStrings)),
                                         Entry("LOGS", 1, SuffixPayload(someSuffixes)),
                                         Entry("WNDC", 1, ClassPayload(someClass))});
    Put(file, at::catalogueVersion, 3, 4);
    Reseal(file);
    Refuses<fileformat::PackStructureError>(check, "version 3 pack", file, PackStructureProblem::CatalogueVersion,
                                            "catalogue version: is not 4");
}

void RefusesAnotherOriginal(Checks& check)
{
    const std::vector<std::byte> payload = Payload(someStrings);
    const std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
    const std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    const std::vector<std::byte> classPayload = ClassPayload(someClass);
    const std::initializer_list<PackWriteEntry> entries{Entry("INST", 1, payload), Entry("LOGS", 1, suffixPayload),
                                                        Entry("SDIR", 1, savePayload), Entry("WNDC", 1, classPayload)};
    for (std::size_t part = 0; part < supported_release::version.size(); ++part)
    {
        std::array<std::uint16_t, 4> other = supported_release::version;
        ++other[part];
        Refuses<fileformat::UnsupportedOriginalError>(check, std::format("version part {} differs", part),
                                                      Write(entries, other), OriginalProblem::Version);
    }
    for (const std::size_t i : {std::size_t{0}, std::size_t{31}})
    {
        std::array<std::byte, 32> other = supported_release::Sha256();
        other[i] ^= std::byte{0x01};
        Refuses<fileformat::UnsupportedOriginalError>(check, std::format("digest byte {} differs", i),
                                                      Write(entries, supported_release::version, other),
                                                      OriginalProblem::Digest);
    }
}

// Each stage reports its problem before any later stage's.
void ChecksInOrder(Checks& check)
{
    const std::vector<std::byte> payload = Payload(someStrings);
    const std::vector<std::byte> suffixPayload = SuffixPayload(someSuffixes);
    const std::vector<std::byte> savePayload = SavePayload(someSaveTexts);
    const std::vector<std::byte> classPayload = ClassPayload(someClass);
    const std::vector<std::byte> one(1, std::byte{1});
    const PackWriteEntry logs = Entry("LOGS", 1, suffixPayload);
    const PackWriteEntry sdir = Entry("SDIR", 1, savePayload);

    // The container before the original, the original before the catalogue.
    std::vector<std::byte> damaged = Write({Entry("AAAA", 1, one)}, {1, 4, 0, 524});
    damaged[at::magic] = std::byte{'W'};
    Refuses<fileformat::PackStructureError>(check, "container first", damaged, PackStructureProblem::Magic);
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "original before catalogue", Write({Entry("AAAA", 1, one)}, {1, 4, 0, 524}), OriginalProblem::Version);

    // The catalogue's entries in its order: a missing INST before a missing
    // LOGS, a missing LOGS before a missing SDIR, a missing SDIR before a
    // missing WNDC.
    RefusesForTheCatalogue(check, "INST missing before LOGS", Write({Entry("AAAA", 1, one)}),
                           PackCatalogueProblem::MissingEntry, "entry INST");
    RefusesForTheCatalogue(check, "LOGS missing before SDIR", Write({Entry("INST", 1, payload)}),
                           PackCatalogueProblem::MissingEntry, "entry LOGS");
    RefusesForTheCatalogue(check, "SDIR missing before WNDC", Write({Entry("INST", 1, payload), logs}),
                           PackCatalogueProblem::MissingEntry, "entry SDIR");

    // A missing entry before an unknown key, an unknown key before a later
    // entry's version, each entry in turn.
    RefusesForTheCatalogue(check, "missing before unknown", Write({Entry("AAAA", 7, one)}),
                           PackCatalogueProblem::MissingEntry);
    RefusesForTheCatalogue(check, "missing WNDC before unknown",
                           Write({Entry("AAAA", 7, one), Entry("INST", 1, payload), logs, sdir}),
                           PackCatalogueProblem::MissingEntry, "entry WNDC");
    RefusesForTheCatalogue(check, "unknown before a later version",
                           Write({Entry("AAAA", 1, one), Entry("INST", 2, one), Entry("LOGS", 2, one),
                                  Entry("SDIR", 2, one), Entry("WNDC", 2, one)}),
                           PackCatalogueProblem::UnknownKey);
    RefusesForTheCatalogue(
        check, "version before a later unknown",
        Write({Entry("INST", 2, one), logs, sdir, Entry("WNDC", 1, classPayload), Entry("ZZZZ", 1, one)}),
        PackCatalogueProblem::EntryVersion, "entry INST");
    RefusesForTheCatalogue(
        check, "size before a later unknown",
        Write({Entry("INST", 1, one), logs, sdir, Entry("WNDC", 1, classPayload), Entry("ZZZZ", 1, one)}),
        PackCatalogueProblem::EntrySize, "entry INST");
    RefusesForTheCatalogue(check, "INST size before LOGS version",
                           Write({Entry("INST", 1, one), Entry("LOGS", 2, suffixPayload), sdir,
                                  Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::EntrySize, "entry INST");
    RefusesForTheCatalogue(check, "LOGS size before SDIR version",
                           Write({Entry("INST", 1, payload), Entry("LOGS", 1, one), Entry("SDIR", 2, savePayload),
                                  Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::EntrySize, "entry LOGS");
    RefusesForTheCatalogue(check, "SDIR size before WNDC version",
                           Write({Entry("INST", 1, payload), logs, Entry("SDIR", 1, one),
                                  Entry("WNDC", 2, classPayload)}),
                           PackCatalogueProblem::EntrySize, "entry SDIR");

    // The version before the size, the size before the fields.
    RefusesForTheCatalogue(check, "version before size",
                           Write({Entry("INST", 2, one), logs, sdir, Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::EntryVersion);
    RefusesForTheCatalogue(check, "LOGS version before size",
                           Write({Entry("INST", 1, payload), Entry("LOGS", 2, one), sdir,
                                  Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::EntryVersion, "entry LOGS");
    RefusesForTheCatalogue(check, "SDIR version before size",
                           Write({Entry("INST", 1, payload), logs, Entry("SDIR", 2, one),
                                  Entry("WNDC", 1, classPayload)}),
                           PackCatalogueProblem::EntryVersion, "entry SDIR");
    RefusesForTheCatalogue(check, "WNDC version before size",
                           Write({Entry("INST", 1, payload), logs, sdir, Entry("WNDC", 2, one)}),
                           PackCatalogueProblem::EntryVersion, "entry WNDC");
    const std::vector<std::byte> noZero(entryBytes - 1, std::byte{'x'});
    RefusesForTheCatalogue(check, "size before fields", CompletePack(noZero), PackCatalogueProblem::EntrySize);
    const std::vector<std::byte> classNoZero(classBytes - 1, std::byte{'x'});
    const std::vector<std::byte> fieldsNoZero(entryBytes, std::byte{'x'});
    RefusesForTheCatalogue(check, "WNDC size before INST fields", CompletePack(fieldsNoZero, classNoZero),
                           PackCatalogueProblem::EntrySize, "entry WNDC");
    const std::vector<std::byte> suffixesNoZero(suffixesBytes - 1, std::byte{'x'});
    RefusesForTheCatalogue(check, "LOGS size before INST fields",
                           CompletePack(fieldsNoZero, ClassPayload(someClass), suffixesNoZero),
                           PackCatalogueProblem::EntrySize, "entry LOGS");
    const std::vector<std::byte> saveNoZero(saveDirectoryBytes - 1, std::byte{'x'});
    RefusesForTheCatalogue(check, "SDIR size before INST fields",
                           CompletePack(fieldsNoZero, ClassPayload(someClass), SuffixPayload(someSuffixes), saveNoZero),
                           PackCatalogueProblem::EntrySize, "entry SDIR");

    // The fields in order, INST's before LOGS's, LOGS's before SDIR's, SDIR's
    // before WNDC's.
    std::vector<std::byte> twoFields = Payload(someStrings);
    std::fill_n(twoFields.begin() + static_cast<std::ptrdiff_t>(FieldOffset(1)), fieldBytes[1], std::byte{'x'});
    std::fill_n(twoFields.begin() + static_cast<std::ptrdiff_t>(FieldOffset(3)), fieldBytes[3], std::byte{'x'});
    RefusesForTheCatalogue(check, "earlier field first", CompletePack(twoFields), PackCatalogueProblem::FieldTerminator,
                           fieldNames[1]);
    const std::vector<std::byte> classAllX(classBytes, std::byte{'x'});
    const std::vector<std::byte> suffixesAllX(suffixesBytes, std::byte{'x'});
    const std::vector<std::byte> saveAllX(saveDirectoryBytes, std::byte{'x'});
    std::vector<std::byte> lastField = Payload(someStrings);
    std::fill_n(lastField.begin() + static_cast<std::ptrdiff_t>(FieldOffset(3)), fieldBytes[3], std::byte{'x'});
    RefusesForTheCatalogue(check, "INST's fields before LOGS's",
                           CompletePack(lastField, classAllX, suffixesAllX, saveAllX),
                           PackCatalogueProblem::FieldTerminator, fieldNames[3]);
    std::vector<std::byte> twoSuffixes = SuffixPayload(someSuffixes);
    std::fill_n(twoSuffixes.begin() + static_cast<std::ptrdiff_t>(SuffixOffset(1)), suffixBytes[1], std::byte{'x'});
    std::fill_n(twoSuffixes.begin() + static_cast<std::ptrdiff_t>(SuffixOffset(3)), suffixBytes[3], std::byte{'x'});
    RefusesForTheCatalogue(check, "earlier suffix first",
                           CompletePack(Payload(someStrings), classAllX, twoSuffixes, saveAllX),
                           PackCatalogueProblem::FieldTerminator, suffixNames[1]);

    // Each suffix's path check right after its zero byte, so a suffix's path
    // before a later suffix's zero byte and after an earlier one's, INST's
    // fields before it and SDIR's and WNDC's after it; within a suffix, a
    // separator before a colon before a control character.
    std::vector<std::byte> pathThenNoZero = SuffixPayload({"a/b", "second.test", "third test suffix", "fourth.test"});
    std::fill_n(pathThenNoZero.begin() + static_cast<std::ptrdiff_t>(SuffixOffset(1)), suffixBytes[1], std::byte{'x'});
    RefusesForTheCatalogue(check, "suffix path before a later zero byte",
                           CompletePack(Payload(someStrings), classAllX, pathThenNoZero),
                           PackCatalogueProblem::SuffixPath, suffixNames[0]);
    std::vector<std::byte> noZeroThenPath = SuffixPayload({"first.test", "a/b", "third test suffix", "fourth.test"});
    std::fill_n(noZeroThenPath.begin() + static_cast<std::ptrdiff_t>(SuffixOffset(0)), suffixBytes[0], std::byte{'x'});
    RefusesForTheCatalogue(check, "earlier zero byte before suffix path",
                           CompletePack(Payload(someStrings), classAllX, noZeroThenPath),
                           PackCatalogueProblem::FieldTerminator, suffixNames[0]);
    const std::vector<std::byte> lastSuffixPath =
        SuffixPayload({"first.test", "second.test", "third test suffix", "C:a"});
    RefusesForTheCatalogue(check, "INST's fields before suffix path", CompletePack(lastField, classAllX, lastSuffixPath),
                           PackCatalogueProblem::FieldTerminator, fieldNames[3]);
    RefusesForTheCatalogue(check, "suffix path before SDIR's and WNDC's fields",
                           CompletePack(Payload(someStrings), classAllX, lastSuffixPath, saveAllX),
                           PackCatalogueProblem::SuffixPath, suffixNames[3]);
    RefusesForTheCatalogue(check, "separator before colon",
                           CompletePack(Payload(someStrings), ClassPayload(someClass),
                                        SuffixPayload({"\x01:/", "second.test", "third test suffix", "fourth.test"})),
                           PackCatalogueProblem::SuffixPath, "first suffix: holds a path separator");
    RefusesForTheCatalogue(check, "colon before control character",
                           CompletePack(Payload(someStrings), ClassPayload(someClass),
                                        SuffixPayload({"\x01:", "second.test", "third test suffix", "fourth.test"})),
                           PackCatalogueProblem::SuffixPath, "first suffix: holds a colon");

    std::vector<std::byte> twoSaveFields = SavePayload(someSaveTexts);
    std::fill_n(twoSaveFields.begin() + static_cast<std::ptrdiff_t>(SaveOffset(4)), saveBytes[4], std::byte{'x'});
    std::fill_n(twoSaveFields.begin() + static_cast<std::ptrdiff_t>(SaveOffset(9)), saveBytes[9], std::byte{'x'});
    RefusesForTheCatalogue(check, "earlier save directory field first",
                           CompletePack(Payload(someStrings), classAllX, SuffixPayload(someSuffixes), twoSaveFields),
                           PackCatalogueProblem::FieldTerminator, saveNames[4]);

    // The format's zero byte before its conversions; its conversions before
    // a later field's zero byte and before WNDC's fields; LOGS's fields
    // before the format's conversions.
    std::vector<std::byte> formatNoZero = SavePayload(someSaveTexts);
    std::fill_n(formatNoZero.begin(), saveBytes[0], std::byte{'%'});
    RefusesForTheCatalogue(check, "format's zero byte before its conversions", SavePack(formatNoZero),
                           PackCatalogueProblem::FieldTerminator, saveNames[0]);
    SaveTexts badFormat = someSaveTexts;
    badFormat[0] = "%s%n";
    std::vector<std::byte> badFormatThenField = SavePayload(badFormat);
    std::fill_n(badFormatThenField.begin() + static_cast<std::ptrdiff_t>(SaveOffset(1)), saveBytes[1],
                std::byte{'x'});
    RefusesForTheCatalogue(check, "format's conversions before the next field",
                           CompletePack(Payload(someStrings), classAllX, SuffixPayload(someSuffixes),
                                        badFormatThenField),
                           PackCatalogueProblem::FormatConversion, saveNames[0]);
    std::vector<std::byte> lastSuffix = SuffixPayload(someSuffixes);
    std::fill_n(lastSuffix.begin() + static_cast<std::ptrdiff_t>(SuffixOffset(3)), suffixBytes[3], std::byte{'x'});
    RefusesForTheCatalogue(check, "LOGS's fields before the format's conversions",
                           CompletePack(Payload(someStrings), ClassPayload(someClass), lastSuffix,
                                        SavePayload(badFormat)),
                           PackCatalogueProblem::FieldTerminator, suffixNames[3]);

    // Each folder's path check right after its zero byte: after the format's
    // conversions and an earlier field's zero byte, before a later field's
    // zero byte and before WNDC's fields; across folders, the earlier first;
    // within a folder, a colon before a control character before a .. part.
    SaveTexts badFolder = someSaveTexts;
    badFolder[6] = "a\\..";
    std::vector<std::byte> folderThenNoZero = SavePayload(badFolder);
    std::fill_n(folderThenNoZero.begin() + static_cast<std::ptrdiff_t>(SaveOffset(7)), saveBytes[7], std::byte{'x'});
    RefusesForTheCatalogue(check, "folder path before a later zero byte",
                           CompletePack(Payload(someStrings), classAllX, SuffixPayload(someSuffixes),
                                        folderThenNoZero),
                           PackCatalogueProblem::FolderPath, saveNames[6]);
    std::vector<std::byte> noZeroThenFolder = SavePayload(badFolder);
    std::fill_n(noZeroThenFolder.begin() + static_cast<std::ptrdiff_t>(SaveOffset(5)), saveBytes[5], std::byte{'x'});
    RefusesForTheCatalogue(check, "earlier zero byte before folder path", SavePack(noZeroThenFolder),
                           PackCatalogueProblem::FieldTerminator, saveNames[5]);
    SaveTexts formatThenFolder = badFolder;
    formatThenFolder[0] = "%n";
    RefusesForTheCatalogue(check, "format's conversions before folder path", SavePack(SavePayload(formatThenFolder)),
                           PackCatalogueProblem::FormatConversion, saveNames[0]);
    SaveTexts twoFolders = someSaveTexts;
    twoFolders[5] = "..";
    twoFolders[8] = "C:";
    RefusesForTheCatalogue(check, "earlier folder path first", SavePack(SavePayload(twoFolders)),
                           PackCatalogueProblem::FolderPath, std::format("{}: holds a .. part", saveNames[5]));
    SaveTexts colonFirst = someSaveTexts;
    colonFirst[5] = "\x01:..";
    RefusesForTheCatalogue(check, "colon before control character", SavePack(SavePayload(colonFirst)),
                           PackCatalogueProblem::FolderPath, std::format("{}: holds a colon", saveNames[5]));
    SaveTexts controlFirst = someSaveTexts;
    controlFirst[5] = "..\\\x01";
    RefusesForTheCatalogue(check, "control character before .. part", SavePack(SavePayload(controlFirst)),
                           PackCatalogueProblem::FolderPath,
                           std::format("{}: holds a control character", saveNames[5]));
}

// A moved pack has the values; the pack it was moved from, by construction
// or by assignment, keeps them too.
void Moves(Checks& check)
{
    ValidatedPack first = fileformat::ValidatePack(CompletePack(Payload(someStrings)));
    ValidatedPack second = std::move(first);
    CheckStrings(check, "moved", second, someStrings);
    CheckSuffixes(check, "moved", second, someSuffixes);
    CheckSaveDirectory(check, "moved", second, someSaveTexts);
    CheckClass(check, "moved", second, someClass);
    CheckStrings(check, "moved-from", first, someStrings);
    CheckSuffixes(check, "moved-from", first, someSuffixes);
    CheckSaveDirectory(check, "moved-from", first, someSaveTexts);
    CheckClass(check, "moved-from", first, someClass);

    const Strings empty{"", "", "", ""};
    const Suffixes emptySuffixes{"", "", "", ""};
    const SaveTexts emptySave{"%s", "", "", "", "", "", "", "", "", ""};
    ValidatedPack third = fileformat::ValidatePack(
        CompletePack(Payload(empty), ClassPayload(""), SuffixPayload(emptySuffixes), SavePayload(emptySave)));
    third = std::move(second);
    CheckStrings(check, "move-assigned", third, someStrings);
    CheckSuffixes(check, "move-assigned", third, someSuffixes);
    CheckSaveDirectory(check, "move-assigned", third, someSaveTexts);
    CheckClass(check, "move-assigned", third, someClass);
    check.Equal("move-assigned original", true, third.Original().sha256 == supported_release::Sha256());
}

} // namespace

int main()
{
    Checks check("data pack catalogue");
    check.Run("complete pack", [&] { AcceptsACompletePack(check); });
    check.Run("after the zero byte", [&] { KeepsNothingAfterTheZeroByte(check); });
    check.Run("missing entry", [&] { RefusesAMissingEntry(check); });
    check.Run("unknown key", [&] { RefusesAnUnknownKey(check); });
    check.Run("entry version", [&] { RefusesAnotherEntryVersion(check); });
    check.Run("entry size", [&] { RefusesAnotherSize(check); });
    check.Run("field with no zero byte", [&] { RefusesAFieldWithNoZeroByte(check); });
    check.Run("suffix path", [&] { RefusesASuffixPath(check); });
    check.Run("one string formats", [&] { AcceptsOneStringFormats(check); });
    check.Run("other formats", [&] { RefusesOtherFormats(check); });
    check.Run("folder path", [&] { RefusesAFolderPath(check); });
    check.Run("catalogue version", [&] { RefusesAnotherCatalogueVersion(check); });
    check.Run("version 1 pack", [&] { RefusesAVersionOnePack(check); });
    check.Run("version 2 pack", [&] { RefusesAVersionTwoPack(check); });
    check.Run("version 3 pack", [&] { RefusesAVersionThreePack(check); });
    check.Run("original", [&] { RefusesAnotherOriginal(check); });
    check.Run("order", [&] { ChecksInOrder(check); });
    check.Run("move", [&] { Moves(check); });
    return check.ExitCode();
}
