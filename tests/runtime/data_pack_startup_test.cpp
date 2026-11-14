#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/data_pack_startup.h"
#include "fnv/log_path_suffixes.h"
#include "fnv/main_window_class.h"
#include "fnv/save_directory_strings.h"
#include "fnv/single_instance_strings.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <format>
#include <fstream>
#include <random>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <variant>
#include <vector>

namespace
{

namespace fs = std::filesystem;

struct Strings
{
    std::string_view mutexName;
    std::string_view firstMessageText;
    std::string_view messageCaption;
    std::string_view secondMessageText;
};

// The values of one pack: C1's strings, the main window class's name, the
// log path suffixes and the save directory strings.
struct Values
{
    Strings strings;
    std::string_view className;
    std::array<std::string_view, 4> suffixes;
    std::array<std::string_view, 10> saveTexts;
};

// Made-up values: none is a string of the original release. Each format of
// the INI paths holds its one %s.
constexpr Values firstValues{{"test mutex", "first test message", "Test", "second test message"},
                             "test window class",
                             {"first.test", "second.test", "third test suffix", "fourth.test"},
                             {"<%s>", "first.ini", "Test", "test setting key", "second test.ini", "local", "docs test",
                              "game test", "w", "default.ini"}};
constexpr Values secondValues{{"other mutex", "another first message", "Other", "another second message"},
                              "other window class",
                              {"one.other", "two.other", "three other suffix", "four.other"},
                              {"(%s)", "one.ini", "Other", "other setting key", "other second.ini", "local2",
                               "docs other", "game other", "v", "other.ini"}};

constexpr std::array<std::size_t, 4> fieldBytes{20, 60, 8, 52};
constexpr std::array<std::size_t, 4> suffixBytes{16, 16, 24, 16};
constexpr std::array<std::size_t, 10> saveBytes{8, 12, 8, 24, 256, 12, 12, 12, 4, 20};
constexpr std::size_t classBytes = 256;
constexpr std::array<char, 4> singleInstanceKey{'I', 'N', 'S', 'T'};
constexpr std::array<char, 4> suffixesKey{'L', 'O', 'G', 'S'};
constexpr std::array<char, 4> saveDirectoryKey{'S', 'D', 'I', 'R'};
constexpr std::array<char, 4> windowClassKey{'W', 'N', 'D', 'C'};

std::vector<std::byte> Payload(const Strings& strings)
{
    const std::array<std::string_view, 4> texts{strings.mutexName, strings.firstMessageText, strings.messageCaption,
                                                strings.secondMessageText};
    std::vector<std::byte> payload;
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + fieldBytes[i] - texts[i].size());
    }
    return payload;
}

std::vector<std::byte> SuffixPayload(const std::array<std::string_view, 4>& suffixes)
{
    std::vector<std::byte> payload;
    for (std::size_t i = 0; i < suffixes.size(); ++i)
    {
        for (const char c : suffixes[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + suffixBytes[i] - suffixes[i].size());
    }
    return payload;
}

std::vector<std::byte> SavePayload(const std::array<std::string_view, 10>& texts)
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

std::vector<std::byte> ClassPayload(std::string_view className)
{
    std::vector<std::byte> payload;
    for (const char c : className)
        payload.push_back(static_cast<std::byte>(c));
    payload.resize(classBytes);
    return payload;
}

// A pack of these entries that records the supported release's version and
// `sha`.
std::vector<std::byte> Write(std::span<const fileformat::PackWriteEntry> entries,
                             std::array<std::byte, 32> sha = supported_release::Sha256())
{
    return fileformat::WritePackStructure(supported_release::version, sha, entries);
}

// A pack of C1's payload under `key` with `version`, the log path suffixes,
// the save directory strings and the main window class. With the defaults it
// is a complete pack of catalogue version 4 that records the supported
// release's identity: it is compared, not proved.
std::vector<std::byte> Pack(const Values& values, std::array<char, 4> key = singleInstanceKey,
                            std::array<std::byte, 32> sha = supported_release::Sha256(), std::uint32_t version = 1)
{
    const std::vector<std::byte> payload = Payload(values.strings);
    const std::vector<std::byte> suffixPayload = SuffixPayload(values.suffixes);
    const std::vector<std::byte> savePayload = SavePayload(values.saveTexts);
    const std::vector<std::byte> classPayload = ClassPayload(values.className);
    const std::array<fileformat::PackWriteEntry, 4> entries{{{key, version, payload},
                                                             {suffixesKey, 1, suffixPayload},
                                                             {saveDirectoryKey, 1, savePayload},
                                                             {windowClassKey, 1, classPayload}}};
    return Write(entries, sha);
}

// Where the container decision puts the header fields this test changes. The
// test states them itself and does not share them with the reader or the
// writer.
namespace at
{
constexpr std::size_t envelopeVersion = 8;
constexpr std::size_t catalogueVersion = 12;
constexpr std::size_t nativeDataContract = 16;
constexpr std::size_t buildTarget = 20;
constexpr std::size_t crc32 = 84;
} // namespace at

// CRC-32 one bit at a time, so the test does not check zlib against zlib.
std::uint32_t Crc32(std::uint32_t crc, std::span<const std::byte> bytes)
{
    crc = ~crc;
    for (const std::byte byte : bytes)
    {
        crc ^= static_cast<std::uint32_t>(byte);
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc >> 1) ^ ((crc & 1) != 0 ? 0xEDB88320u : 0u);
    }
    return ~crc;
}

void Put32(std::vector<std::byte>& bytes, std::size_t offset, std::uint32_t value)
{
    for (std::size_t i = 0; i < 4; ++i)
        bytes[offset + i] = static_cast<std::byte>(value >> (8 * i));
}

// `bytes` with the header field at `offset` set to `value` and the CRC-32
// stored again, so only the field is changed.
std::vector<std::byte> WithHeaderField(std::vector<std::byte> bytes, std::size_t offset, std::uint32_t value)
{
    Put32(bytes, offset, value);
    const std::span<const std::byte> all = bytes;
    Put32(bytes, at::crc32, Crc32(Crc32(0, all.first(at::crc32)), all.subspan(at::crc32 + 4)));
    return bytes;
}

// A folder of the test's own under the temporary folder, standing in for the
// executable's folder, removed with what it holds when the test ends.
class Folder
{
  public:
    Folder()
    {
        std::random_device random;
        for (;;)
        {
            path = fs::temp_directory_path() / std::format("vegas-data-pack-startup-{:08x}{:08x}", random(), random());
            if (fs::create_directory(path))
                return;
        }
    }
    Folder(const Folder&) = delete;
    Folder& operator=(const Folder&) = delete;
    ~Folder()
    {
        std::error_code ignored;
        fs::remove_all(path, ignored);
    }

    void WritePack(std::span<const std::byte> bytes) const { Write(path / fnv::startup::dataPackFileName, bytes); }

    static void Write(const fs::path& file, std::span<const std::byte> bytes)
    {
        std::ofstream out(file, std::ios::binary | std::ios::trunc);
        out.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
        out.close();
        if (!out)
            throw std::runtime_error("the test could not write its pack");
    }

    fs::path path;
};

template <std::size_t N>
bool SameField(const std::array<char, N>& actual, std::string_view expected)
{
    std::array<char, N> wanted{};
    std::memcpy(wanted.data(), expected.data(), expected.size());
    return actual == wanted;
}

void ExpectPublished(Checks& checks, std::string_view test, const Values& expected)
{
    const fileformat::SingleInstanceStrings& published = fnv::startup::PublishedSingleInstanceStrings();
    if (!SameField(published.mutexName, expected.strings.mutexName) ||
        !SameField(published.firstMessageText, expected.strings.firstMessageText) ||
        !SameField(published.messageCaption, expected.strings.messageCaption) ||
        !SameField(published.secondMessageText, expected.strings.secondMessageText))
        checks.Fail(test, std::format("the published strings are not those of the pack with \"{}\"",
                                      expected.strings.mutexName));
    if (!SameField(fnv::startup::PublishedMainWindowClass().className, expected.className))
        checks.Fail(test, std::format("the published class name is not \"{}\"", expected.className));
    const fileformat::LogPathSuffixes& suffixes = fnv::startup::PublishedLogPathSuffixes();
    if (!SameField(suffixes.firstSuffix, expected.suffixes[0]) ||
        !SameField(suffixes.secondSuffix, expected.suffixes[1]) ||
        !SameField(suffixes.thirdSuffix, expected.suffixes[2]) ||
        !SameField(suffixes.fourthSuffix, expected.suffixes[3]))
        checks.Fail(test, std::format("the published log path suffixes are not those of the pack with \"{}\"",
                                      expected.suffixes[0]));
    const fileformat::SaveDirectoryStrings& saves = fnv::startup::PublishedSaveDirectoryStrings();
    if (!SameField(saves.iniPathFormat, expected.saveTexts[0]) ||
        !SameField(saves.firstIniName, expected.saveTexts[1]) || !SameField(saves.iniSection, expected.saveTexts[2]) ||
        !SameField(saves.settingKey, expected.saveTexts[3]) ||
        !SameField(saves.secondIniName, expected.saveTexts[4]) ||
        !SameField(saves.localFolder, expected.saveTexts[5]) ||
        !SameField(saves.documentsFolder, expected.saveTexts[6]) ||
        !SameField(saves.gameFolder, expected.saveTexts[7]) ||
        !SameField(saves.workingFolder, expected.saveTexts[8]) ||
        !SameField(saves.defaultIniName, expected.saveTexts[9]))
        checks.Fail(test, std::format("the published save directory strings are not those of the pack with \"{}\"",
                                      expected.saveTexts[1]));
}

// Loads the pack of `folder` and expects success with the owner's published
// strings returned.
void ExpectLoaded(Checks& checks, std::string_view test, const Folder& folder, const Values& expected)
{
    const fnv::startup::DataPackLoad load = fnv::startup::LoadDataPack(folder.path);
    if (const std::string* failure = std::get_if<std::string>(&load))
        checks.Fail(test, std::format("the stage refused a complete pack: {}", *failure));
    else if (&std::get_if<0>(&load)->singleInstance.get() != &fnv::startup::PublishedSingleInstanceStrings())
        checks.Fail(test, "the stage did not return the owner's published strings");
    else if (&std::get_if<0>(&load)->mainWindowClass.get() != &fnv::startup::PublishedMainWindowClass())
        checks.Fail(test, "the stage did not return the owner's published main window class");
    else if (&std::get_if<0>(&load)->logPathSuffixes.get() != &fnv::startup::PublishedLogPathSuffixes())
        checks.Fail(test, "the stage did not return the owner's published log path suffixes");
    else if (&std::get_if<0>(&load)->saveDirectory.get() != &fnv::startup::PublishedSaveDirectoryStrings())
        checks.Fail(test, "the stage did not return the owner's published save directory strings");
    ExpectPublished(checks, test, expected);
}

// Loads `folder` and expects a refusal reported as one line holding `what`.
void ExpectRefused(Checks& checks, std::string_view test, const fs::path& folder, std::string_view what)
{
    const fnv::startup::DataPackLoad load = fnv::startup::LoadDataPack(folder);
    const std::string* failure = std::get_if<std::string>(&load);
    if (failure == nullptr)
    {
        checks.Fail(test, "the stage accepted the pack");
        return;
    }
    const std::string& line = *failure;
    if (line.find(what) == std::string::npos)
        checks.Fail(test, std::format("expected a report holding \"{}\", got \"{}\"", what, line));
    if (line.empty() || line.find('\n') != line.size() - 1)
        checks.Fail(test, std::format("expected one line, got \"{}\"", line));
}

} // namespace

int main(int argc, char** argv)
{
    // A refused stage publishes nothing: each owner is still unpublished.
    if (argc == 2 && std::strcmp(argv[1], "--refused-then-read") == 0)
    {
        Folder empty;
        if (!std::holds_alternative<std::string>(fnv::startup::LoadDataPack(empty.path)))
            return 1;
        std::fprintf(stderr, "refused-then-read\n");
        fnv::startup::PublishedSingleInstanceStrings();
        return 0;
    }
    if (argc == 2 && std::strcmp(argv[1], "--refused-then-read-window-class") == 0)
    {
        Folder empty;
        if (!std::holds_alternative<std::string>(fnv::startup::LoadDataPack(empty.path)))
            return 1;
        std::fprintf(stderr, "refused-then-read-window-class\n");
        fnv::startup::PublishedMainWindowClass();
        return 0;
    }
    if (argc == 2 && std::strcmp(argv[1], "--refused-then-read-log-path-suffixes") == 0)
    {
        Folder empty;
        if (!std::holds_alternative<std::string>(fnv::startup::LoadDataPack(empty.path)))
            return 1;
        std::fprintf(stderr, "refused-then-read-log-path-suffixes\n");
        fnv::startup::PublishedLogPathSuffixes();
        return 0;
    }
    if (argc == 2 && std::strcmp(argv[1], "--refused-then-read-save-directory-strings") == 0)
    {
        Folder empty;
        if (!std::holds_alternative<std::string>(fnv::startup::LoadDataPack(empty.path)))
            return 1;
        std::fprintf(stderr, "refused-then-read-save-directory-strings\n");
        fnv::startup::PublishedSaveDirectoryStrings();
        return 0;
    }

    Checks checks("data pack startup");

    checks.Run("complete pack", [&] {
        Folder folder;
        folder.WritePack(Pack(firstValues));
        ExpectLoaded(checks, "complete pack", folder, firstValues);
    });

    // Each refused pack holds the second strings, so a pack whose values were
    // used before it failed would leave them published.
    checks.Run("missing pack", [&] {
        Folder folder;
        ExpectRefused(checks, "missing pack", folder.path, "vegas-data.pack is missing beside the executable");
        ExpectPublished(checks, "missing pack", firstValues);
    });
    checks.Run("missing folder", [&] {
        Folder folder;
        ExpectRefused(checks, "missing folder", folder.path / "absent", "is missing beside the executable");
    });
    checks.Run("pack in a nested folder", [&] {
        Folder folder;
        fs::create_directory(folder.path / "Data");
        Folder::Write(folder.path / "Data" / fnv::startup::dataPackFileName, Pack(secondValues));
        ExpectRefused(checks, "pack in a nested folder", folder.path, "is missing beside the executable");
        ExpectPublished(checks, "pack in a nested folder", firstValues);
    });
    checks.Run("folder in place of the pack", [&] {
        Folder folder;
        fs::create_directory(folder.path / fnv::startup::dataPackFileName);
        ExpectRefused(checks, "folder in place of the pack", folder.path, "cannot be read");
        ExpectPublished(checks, "folder in place of the pack", firstValues);
    });
    checks.Run("empty file", [&] {
        Folder folder;
        folder.WritePack({});
        ExpectRefused(checks, "empty file", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "empty file", firstValues);
    });
    checks.Run("corrupt pack", [&] {
        Folder folder;
        std::vector<std::byte> bytes = Pack(secondValues);
        bytes.back() ^= std::byte{1};
        folder.WritePack(bytes);
        ExpectRefused(checks, "corrupt pack", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "corrupt pack", firstValues);
    });
    checks.Run("truncated pack", [&] {
        Folder folder;
        std::vector<std::byte> bytes = Pack(secondValues);
        bytes.pop_back();
        folder.WritePack(bytes);
        ExpectRefused(checks, "truncated pack", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "truncated pack", firstValues);
    });
    checks.Run("unsupported original", [&] {
        Folder folder;
        std::array<std::byte, 32> sha = supported_release::Sha256();
        sha[0] ^= std::byte{1};
        folder.WritePack(Pack(secondValues, {'I', 'N', 'S', 'T'}, sha));
        ExpectRefused(checks, "unsupported original", folder.path, "was not prepared from a supported original release");
        ExpectPublished(checks, "unsupported original", firstValues);
    });
    checks.Run("incomplete pack", [&] {
        Folder folder;
        folder.WritePack(Pack(secondValues, {'I', 'N', 'S', 'U'}));
        ExpectRefused(checks, "incomplete pack", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "incomplete pack", firstValues);
    });
    checks.Run("field without a zero byte", [&] {
        Folder folder;
        std::vector<std::byte> bytes = Payload(secondValues.strings);
        for (std::size_t i = fieldBytes[0] + fieldBytes[1]; i < fieldBytes[0] + fieldBytes[1] + fieldBytes[2]; ++i)
            bytes[i] = std::byte{'x'};
        const std::vector<std::byte> suffixPayload = SuffixPayload(secondValues.suffixes);
        const std::vector<std::byte> classPayload = ClassPayload(secondValues.className);
        const std::vector<std::byte> savePayload = SavePayload(secondValues.saveTexts);
        const std::array<fileformat::PackWriteEntry, 4> entries{{{singleInstanceKey, 1, bytes},
                                                                 {suffixesKey, 1, suffixPayload},
                                                                 {saveDirectoryKey, 1, savePayload},
                                                                 {windowClassKey, 1, classPayload}}};
        folder.WritePack(Write(entries));
        ExpectRefused(checks, "field without a zero byte", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "field without a zero byte", firstValues);
    });

    // A pack without the main window class, and a class name without a zero
    // byte.
    checks.Run("pack without the main window class", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::vector<std::byte> suffixPayload = SuffixPayload(secondValues.suffixes);
        const std::vector<std::byte> savePayload = SavePayload(secondValues.saveTexts);
        const std::array<fileformat::PackWriteEntry, 3> entries{
            {{singleInstanceKey, 1, payload}, {suffixesKey, 1, suffixPayload}, {saveDirectoryKey, 1, savePayload}}};
        folder.WritePack(Write(entries));
        ExpectRefused(checks, "pack without the main window class", folder.path,
                      "is not a valid data pack: data pack: entry WNDC: is not in the pack");
        ExpectPublished(checks, "pack without the main window class", firstValues);
    });
    checks.Run("class name without a zero byte", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::vector<std::byte> suffixPayload = SuffixPayload(secondValues.suffixes);
        const std::vector<std::byte> classPayload(classBytes, std::byte{'x'});
        const std::vector<std::byte> savePayload = SavePayload(secondValues.saveTexts);
        const std::array<fileformat::PackWriteEntry, 4> entries{{{singleInstanceKey, 1, payload},
                                                                 {suffixesKey, 1, suffixPayload},
                                                                 {saveDirectoryKey, 1, savePayload},
                                                                 {windowClassKey, 1, classPayload}}};
        folder.WritePack(Write(entries));
        ExpectRefused(checks, "class name without a zero byte", folder.path,
                      "is not a valid data pack: data pack: entry WNDC: class name: holds no zero byte");
        ExpectPublished(checks, "class name without a zero byte", firstValues);
    });

    // A pack without the log path suffixes, and a suffix without a zero byte.
    checks.Run("pack without the log path suffixes", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::vector<std::byte> savePayload = SavePayload(secondValues.saveTexts);
        const std::vector<std::byte> classPayload = ClassPayload(secondValues.className);
        const std::array<fileformat::PackWriteEntry, 3> entries{
            {{singleInstanceKey, 1, payload}, {saveDirectoryKey, 1, savePayload}, {windowClassKey, 1, classPayload}}};
        folder.WritePack(Write(entries));
        ExpectRefused(checks, "pack without the log path suffixes", folder.path,
                      "is not a valid data pack: data pack: entry LOGS: is not in the pack");
        ExpectPublished(checks, "pack without the log path suffixes", firstValues);
    });
    checks.Run("suffix without a zero byte", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        std::vector<std::byte> suffixPayload = SuffixPayload(secondValues.suffixes);
        for (std::size_t i = suffixBytes[0] + suffixBytes[1]; i < suffixBytes[0] + suffixBytes[1] + suffixBytes[2]; ++i)
            suffixPayload[i] = std::byte{'x'};
        const std::vector<std::byte> classPayload = ClassPayload(secondValues.className);
        const std::vector<std::byte> savePayload = SavePayload(secondValues.saveTexts);
        const std::array<fileformat::PackWriteEntry, 4> entries{{{singleInstanceKey, 1, payload},
                                                                 {suffixesKey, 1, suffixPayload},
                                                                 {saveDirectoryKey, 1, savePayload},
                                                                 {windowClassKey, 1, classPayload}}};
        folder.WritePack(Write(entries));
        ExpectRefused(checks, "suffix without a zero byte", folder.path,
                      "is not a valid data pack: data pack: entry LOGS: third suffix: holds no zero byte");
        ExpectPublished(checks, "suffix without a zero byte", firstValues);
    });

    // A pack without the save directory strings, as catalogue version 3 was,
    // a save directory string without a zero byte, and a format of the INI
    // paths with a conversion besides its %s.
    checks.Run("pack without the save directory strings", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::vector<std::byte> suffixPayload = SuffixPayload(secondValues.suffixes);
        const std::vector<std::byte> classPayload = ClassPayload(secondValues.className);
        const std::array<fileformat::PackWriteEntry, 3> entries{
            {{singleInstanceKey, 1, payload}, {suffixesKey, 1, suffixPayload}, {windowClassKey, 1, classPayload}}};
        folder.WritePack(Write(entries));
        ExpectRefused(checks, "pack without the save directory strings", folder.path,
                      "is not a valid data pack: data pack: entry SDIR: is not in the pack");
        ExpectPublished(checks, "pack without the save directory strings", firstValues);
    });
    checks.Run("save directory string without a zero byte", [&] {
        Folder folder;
        Values values = secondValues;
        const std::string full(saveBytes[4], 'x');
        values.saveTexts[4] = full;
        folder.WritePack(Pack(values));
        ExpectRefused(checks, "save directory string without a zero byte", folder.path,
                      "is not a valid data pack: data pack: entry SDIR: second INI name: holds no zero byte");
        ExpectPublished(checks, "save directory string without a zero byte", firstValues);
    });
    checks.Run("format with another conversion", [&] {
        Folder folder;
        Values values = secondValues;
        values.saveTexts[0] = "%s%n";
        folder.WritePack(Pack(values));
        ExpectRefused(checks, "format with another conversion", folder.path,
                      "is not a valid data pack: data pack: entry SDIR: INI path format: does not hold exactly one "
                      "%s and no other conversion");
        ExpectPublished(checks, "format with another conversion", firstValues);
    });

    // A pack of catalogue version 1 as setup prepared it, C1 alone, one of
    // catalogue version 2, C1 and the main window class, and one of catalogue
    // version 3, those and the log path suffixes: each refused for its
    // catalogue version.
    checks.Run("catalogue version 1 pack", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::array<fileformat::PackWriteEntry, 1> entries{{{singleInstanceKey, 1, payload}}};
        folder.WritePack(WithHeaderField(Write(entries), at::catalogueVersion, 1));
        ExpectRefused(checks, "catalogue version 1 pack", folder.path,
                      "is not a valid data pack: data pack: catalogue version: is not 4");
        ExpectPublished(checks, "catalogue version 1 pack", firstValues);
    });
    checks.Run("catalogue version 2 pack", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::vector<std::byte> classPayload = ClassPayload(secondValues.className);
        const std::array<fileformat::PackWriteEntry, 2> entries{
            {{singleInstanceKey, 1, payload}, {windowClassKey, 1, classPayload}}};
        folder.WritePack(WithHeaderField(Write(entries), at::catalogueVersion, 2));
        ExpectRefused(checks, "catalogue version 2 pack", folder.path,
                      "is not a valid data pack: data pack: catalogue version: is not 4");
        ExpectPublished(checks, "catalogue version 2 pack", firstValues);
    });
    checks.Run("catalogue version 3 pack", [&] {
        Folder folder;
        const std::vector<std::byte> payload = Payload(secondValues.strings);
        const std::vector<std::byte> suffixPayload = SuffixPayload(secondValues.suffixes);
        const std::vector<std::byte> classPayload = ClassPayload(secondValues.className);
        const std::array<fileformat::PackWriteEntry, 3> entries{
            {{singleInstanceKey, 1, payload}, {suffixesKey, 1, suffixPayload}, {windowClassKey, 1, classPayload}}};
        folder.WritePack(WithHeaderField(Write(entries), at::catalogueVersion, 3));
        ExpectRefused(checks, "catalogue version 3 pack", folder.path,
                      "is not a valid data pack: data pack: catalogue version: is not 4");
        ExpectPublished(checks, "catalogue version 3 pack", firstValues);
    });

    // A pack of another catalogue version, with another version of the entry,
    // or made for another build: each is refused by the check that names it.
    checks.Run("next catalogue version", [&] {
        Folder folder;
        folder.WritePack(
            WithHeaderField(Pack(secondValues), at::catalogueVersion, fileformat::packCatalogueVersion + 1));
        ExpectRefused(checks, "next catalogue version", folder.path,
                      std::format("is not a valid data pack: data pack: catalogue version: is not {}",
                                  fileformat::packCatalogueVersion));
        ExpectPublished(checks, "next catalogue version", firstValues);
    });
    checks.Run("previous catalogue version", [&] {
        Folder folder;
        folder.WritePack(
            WithHeaderField(Pack(secondValues), at::catalogueVersion, fileformat::packCatalogueVersion - 1));
        ExpectRefused(checks, "previous catalogue version", folder.path,
                      std::format("is not a valid data pack: data pack: catalogue version: is not {}",
                                  fileformat::packCatalogueVersion));
        ExpectPublished(checks, "previous catalogue version", firstValues);
    });
    checks.Run("entry version 2", [&] {
        Folder folder;
        folder.WritePack(Pack(secondValues, {'I', 'N', 'S', 'T'}, supported_release::Sha256(), 2));
        ExpectRefused(checks, "entry version 2", folder.path,
                      "is not a valid data pack: data pack: entry INST: version is not the catalogue's");
        ExpectPublished(checks, "entry version 2", firstValues);
    });
    checks.Run("envelope version 2", [&] {
        Folder folder;
        folder.WritePack(WithHeaderField(Pack(secondValues), at::envelopeVersion, 2));
        ExpectRefused(checks, "envelope version 2", folder.path,
                      "is not a valid data pack: data pack: envelope version: is not 1");
        ExpectPublished(checks, "envelope version 2", firstValues);
    });
    checks.Run("native data contract 0", [&] {
        Folder folder;
        folder.WritePack(WithHeaderField(Pack(secondValues), at::nativeDataContract, 0));
        ExpectRefused(checks, "native data contract 0", folder.path,
                      "is not a valid data pack: data pack: native data contract: is not 1");
        ExpectPublished(checks, "native data contract 0", firstValues);
    });
    checks.Run("build target 2", [&] {
        Folder folder;
        folder.WritePack(WithHeaderField(Pack(secondValues), at::buildTarget, 2));
        ExpectRefused(checks, "build target 2", folder.path,
                      "is not a valid data pack: data pack: build target: is not 1");
        ExpectPublished(checks, "build target 2", firstValues);
    });

    checks.Run("another complete pack", [&] {
        Folder folder;
        folder.WritePack(Pack(secondValues));
        ExpectLoaded(checks, "another complete pack", folder, secondValues);
    });
    return checks.ExitCode();
}
