#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/log_path_suffixes.h"

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

// The owner's storage is the catalogue's declaration itself, so its four
// capacities are the entry's.
static_assert(std::is_same_v<decltype(fnv::startup::PublishedLogPathSuffixes()), const fileformat::LogPathSuffixes&>);

// The one writer takes a validated pack: no bytes, no structure, no strings.
static_assert(std::is_invocable_v<decltype(&fnv::startup::PublishLogPathSuffixes), const fileformat::ValidatedPack&>);
static_assert(
    !std::is_invocable_v<decltype(&fnv::startup::PublishLogPathSuffixes), const fileformat::LogPathSuffixes&>);
static_assert(!std::is_invocable_v<decltype(&fnv::startup::PublishLogPathSuffixes), std::span<const std::byte>>);

using Suffixes = std::array<std::string_view, 4>;

// Made-up suffixes: none is a string of the original release.
constexpr Suffixes firstSuffixes{"first.test", "second.test", "third test suffix", "fourth.test"};
constexpr Suffixes secondSuffixes{"one.other", "two.other", "three other suffix", "four.other"};

constexpr std::array<std::size_t, 4> suffixBytes{16, 16, 24, 16};

// A complete pack of catalogue version 3 holding `suffixes`, made-up C1
// strings and a made-up class name. It records the supported release's
// identity: it is compared, not proved.
fileformat::ValidatedPack Validated(const Suffixes& suffixes)
{
    std::vector<std::byte> payload(140);
    payload[0] = std::byte{'m'};
    std::vector<std::byte> suffixPayload;
    for (std::size_t i = 0; i < suffixes.size(); ++i)
    {
        for (const char c : suffixes[i])
            suffixPayload.push_back(static_cast<std::byte>(c));
        suffixPayload.resize(suffixPayload.size() + suffixBytes[i] - suffixes[i].size());
    }
    std::vector<std::byte> classPayload(256);
    classPayload[0] = std::byte{'w'};
    const std::array<fileformat::PackWriteEntry, 3> entries{{{{'I', 'N', 'S', 'T'}, 1, payload},
                                                             {{'L', 'O', 'G', 'S'}, 1, suffixPayload},
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

void ExpectPublished(Checks& checks, std::string_view test, const Suffixes& expected)
{
    const fileformat::LogPathSuffixes& published = fnv::startup::PublishedLogPathSuffixes();
    const std::array<bool, 4> same{SameField(published.firstSuffix, expected[0]),
                                   SameField(published.secondSuffix, expected[1]),
                                   SameField(published.thirdSuffix, expected[2]),
                                   SameField(published.fourthSuffix, expected[3])};
    for (std::size_t i = 0; i < same.size(); ++i)
    {
        if (!same[i])
            checks.Fail(test, std::format("suffix {}: expected \"{}\" and zeros to the end of the field", i,
                                          expected[i]));
    }
}

} // namespace

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--read-unpublished") == 0)
    {
        std::fprintf(stderr, "read-unpublished\n");
        fnv::startup::PublishedLogPathSuffixes();
        return 0;
    }

    Checks checks("log path suffixes");
    checks.Run("publish", [&] {
        fnv::startup::PublishLogPathSuffixes(Validated(firstSuffixes));
        ExpectPublished(checks, "publish", firstSuffixes);
    });
    checks.Run("publish again", [&] {
        fnv::startup::PublishLogPathSuffixes(Validated(secondSuffixes));
        ExpectPublished(checks, "publish again", secondSuffixes);
    });
    checks.Run("the same storage", [&] {
        const fileformat::LogPathSuffixes* before = &fnv::startup::PublishedLogPathSuffixes();
        fnv::startup::PublishLogPathSuffixes(Validated(firstSuffixes));
        if (&fnv::startup::PublishedLogPathSuffixes() != before)
            checks.Fail("storage", "a publication moved the owner's storage");
        ExpectPublished(checks, "the same storage", firstSuffixes);
    });
    return checks.ExitCode();
}
