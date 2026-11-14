#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/single_instance_strings.h"

#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <format>
#include <span>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

namespace
{

// The owner's storage is the catalogue's declaration itself, so its four
// capacities are the entry's (review condition of VEGAS-52).
static_assert(std::is_same_v<decltype(fnv::startup::PublishedSingleInstanceStrings()),
                             const fileformat::SingleInstanceStrings&>);

// The one writer takes a validated pack: no bytes, no structure, no strings.
static_assert(std::is_invocable_v<decltype(&fnv::startup::PublishSingleInstanceStrings),
                                  const fileformat::ValidatedPack&>);
static_assert(!std::is_invocable_v<decltype(&fnv::startup::PublishSingleInstanceStrings),
                                   const fileformat::SingleInstanceStrings&>);
static_assert(!std::is_invocable_v<decltype(&fnv::startup::PublishSingleInstanceStrings),
                                   std::span<const std::byte>>);

struct Strings
{
    std::string_view mutexName;
    std::string_view firstMessageText;
    std::string_view messageCaption;
    std::string_view secondMessageText;
};

// Made-up strings: none is a string of the original release.
constexpr Strings firstStrings{"test mutex", "first test message", "Test", "second test message"};
constexpr Strings secondStrings{"other mutex", "another first message", "Other", "another second message"};

// A complete pack of catalogue version 4 holding `strings`, made-up log path
// suffixes, made-up save directory strings and a made-up class name. It
// records the supported release's identity: it is compared, not proved.
fileformat::ValidatedPack Validated(const Strings& strings)
{
    constexpr std::array<std::size_t, 4> fieldBytes{20, 60, 8, 52};
    const std::array<std::string_view, 4> texts{strings.mutexName, strings.firstMessageText, strings.messageCaption,
                                                strings.secondMessageText};
    std::vector<std::byte> payload;
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + fieldBytes[i] - texts[i].size());
    }
    std::vector<std::byte> suffixPayload(72);
    suffixPayload[0] = std::byte{'s'};
    std::vector<std::byte> classPayload(256);
    classPayload[0] = std::byte{'w'};
    std::vector<std::byte> savePayload(368);
    savePayload[0] = std::byte{'%'};
    savePayload[1] = std::byte{'s'};
    const std::array<fileformat::PackWriteEntry, 4> entries{{{{'I', 'N', 'S', 'T'}, 1, payload},
                                                             {{'L', 'O', 'G', 'S'}, 1, suffixPayload},
                                                             {{'S', 'D', 'I', 'R'}, 1, savePayload},
                                                             {{'W', 'N', 'D', 'C'}, 1, classPayload}}};
    return fileformat::ValidatePack(
        fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), entries));
}

template <std::size_t N>
void ExpectField(Checks& checks, std::string_view field, const std::array<char, N>& actual, std::string_view expected)
{
    std::array<char, N> wanted{};
    std::memcpy(wanted.data(), expected.data(), expected.size());
    if (actual != wanted)
        checks.Fail(field, std::format("expected \"{}\" and zeros to the end of the field", expected));
}

void ExpectPublished(Checks& checks, const Strings& expected)
{
    const fileformat::SingleInstanceStrings& published = fnv::startup::PublishedSingleInstanceStrings();
    ExpectField(checks, "mutexName", published.mutexName, expected.mutexName);
    ExpectField(checks, "firstMessageText", published.firstMessageText, expected.firstMessageText);
    ExpectField(checks, "messageCaption", published.messageCaption, expected.messageCaption);
    ExpectField(checks, "secondMessageText", published.secondMessageText, expected.secondMessageText);
}

} // namespace

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--read-unpublished") == 0)
    {
        std::fprintf(stderr, "read-unpublished\n");
        fnv::startup::PublishedSingleInstanceStrings();
        return 0;
    }

    Checks checks("single-instance strings");
    checks.Run("publish", [&] {
        fnv::startup::PublishSingleInstanceStrings(Validated(firstStrings));
        ExpectPublished(checks, firstStrings);
    });
    checks.Run("publish again", [&] {
        fnv::startup::PublishSingleInstanceStrings(Validated(secondStrings));
        ExpectPublished(checks, secondStrings);
    });
    checks.Run("the same storage", [&] {
        const fileformat::SingleInstanceStrings* before = &fnv::startup::PublishedSingleInstanceStrings();
        fnv::startup::PublishSingleInstanceStrings(Validated(firstStrings));
        if (&fnv::startup::PublishedSingleInstanceStrings() != before)
            checks.Fail("storage", "a publication moved the owner's storage");
        ExpectPublished(checks, firstStrings);
    });
    return checks.ExitCode();
}
