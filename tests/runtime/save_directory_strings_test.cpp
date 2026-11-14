#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/save_directory_strings.h"

#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <format>
#include <span>
#include <string_view>
#include <type_traits>
#include <vector>

namespace
{

// The owner's storage is the catalogue's declaration itself, so its ten
// capacities are the entry's.
static_assert(std::is_same_v<decltype(fnv::startup::PublishedSaveDirectoryStrings()),
                             const fileformat::SaveDirectoryStrings&>);

// The one writer takes a validated pack: no bytes, no structure, no strings.
static_assert(
    std::is_invocable_v<decltype(&fnv::startup::PublishSaveDirectoryStrings), const fileformat::ValidatedPack&>);
static_assert(!std::is_invocable_v<decltype(&fnv::startup::PublishSaveDirectoryStrings),
                                   const fileformat::SaveDirectoryStrings&>);
static_assert(!std::is_invocable_v<decltype(&fnv::startup::PublishSaveDirectoryStrings), std::span<const std::byte>>);

using SaveTexts = std::array<std::string_view, 10>;

// Made-up save directory strings: none is a string of the original release.
// Each format holds its one %s.
constexpr SaveTexts firstTexts{"<%s>",  "first.ini", "Test",      "test setting key", "second test.ini",
                               "local", "docs test", "game test", "w",                "default.ini"};
constexpr SaveTexts secondTexts{"(%s)",   "one.ini",    "Other",      "other setting key", "other second.ini",
                                "local2", "docs other", "game other", "v",                 "other.ini"};

constexpr std::array<std::size_t, 10> saveBytes{8, 12, 8, 24, 256, 12, 12, 12, 4, 20};

// A complete pack of catalogue version 4 holding `texts`, made-up C1
// strings, made-up log path suffixes and a made-up class name. It records the
// supported release's identity: it is compared, not proved.
fileformat::ValidatedPack Validated(const SaveTexts& texts)
{
    std::vector<std::byte> payload(140);
    payload[0] = std::byte{'m'};
    std::vector<std::byte> suffixPayload(72);
    suffixPayload[0] = std::byte{'s'};
    std::vector<std::byte> savePayload;
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            savePayload.push_back(static_cast<std::byte>(c));
        savePayload.resize(savePayload.size() + saveBytes[i] - texts[i].size());
    }
    std::vector<std::byte> classPayload(256);
    classPayload[0] = std::byte{'w'};
    const std::array<fileformat::PackWriteEntry, 4> entries{{{{'I', 'N', 'S', 'T'}, 1, payload},
                                                             {{'L', 'O', 'G', 'S'}, 1, suffixPayload},
                                                             {{'S', 'D', 'I', 'R'}, 1, savePayload},
                                                             {{'W', 'N', 'D', 'C'}, 1, classPayload}}};
    return fileformat::ValidatePack(
        fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), entries));
}

template <std::size_t N> bool SameField(const std::array<char, N>& actual, std::string_view expected)
{
    std::array<char, N> wanted{};
    std::memcpy(wanted.data(), expected.data(), expected.size());
    return actual == wanted;
}

void ExpectPublished(Checks& checks, std::string_view test, const SaveTexts& expected)
{
    const fileformat::SaveDirectoryStrings& published = fnv::startup::PublishedSaveDirectoryStrings();
    const std::array<bool, 10> same{SameField(published.iniPathFormat, expected[0]),
                                    SameField(published.firstIniName, expected[1]),
                                    SameField(published.iniSection, expected[2]),
                                    SameField(published.settingKey, expected[3]),
                                    SameField(published.secondIniName, expected[4]),
                                    SameField(published.localFolder, expected[5]),
                                    SameField(published.documentsFolder, expected[6]),
                                    SameField(published.gameFolder, expected[7]),
                                    SameField(published.workingFolder, expected[8]),
                                    SameField(published.defaultIniName, expected[9])};
    for (std::size_t i = 0; i < same.size(); ++i)
    {
        if (!same[i])
            checks.Fail(test, std::format("field {}: expected \"{}\" and zeros to the end of the field", i,
                                          expected[i]));
    }
}

} // namespace

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--read-unpublished") == 0)
    {
        std::fprintf(stderr, "read-unpublished\n");
        fnv::startup::PublishedSaveDirectoryStrings();
        return 0;
    }

    Checks checks("save directory strings");
    checks.Run("publish", [&] {
        fnv::startup::PublishSaveDirectoryStrings(Validated(firstTexts));
        ExpectPublished(checks, "publish", firstTexts);
    });
    checks.Run("publish again", [&] {
        fnv::startup::PublishSaveDirectoryStrings(Validated(secondTexts));
        ExpectPublished(checks, "publish again", secondTexts);
    });
    checks.Run("the same storage", [&] {
        const fileformat::SaveDirectoryStrings* before = &fnv::startup::PublishedSaveDirectoryStrings();
        fnv::startup::PublishSaveDirectoryStrings(Validated(firstTexts));
        if (&fnv::startup::PublishedSaveDirectoryStrings() != before)
            checks.Fail("storage", "a publication moved the owner's storage");
        ExpectPublished(checks, "the same storage", firstTexts);
    });
    return checks.ExitCode();
}
