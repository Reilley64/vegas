#include "check.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_structure.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <format>
#include <initializer_list>
#include <limits>
#include <span>
#include <stdexcept>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace
{

using fileformat::OriginalCheckedPack;
using fileformat::OriginalIdentity;
using fileformat::OriginalProblem;
using fileformat::PackWriteEntry;
using fileformat::UncheckedPackRequirement;

// Only CheckPackOriginal and CheckPackOriginalAgainst make an
// OriginalCheckedPack: nothing converts a parsed structure into one, and it is
// moved, not copied.
static_assert(!std::is_default_constructible_v<OriginalCheckedPack>);
static_assert(!std::is_constructible_v<OriginalCheckedPack, fileformat::PackStructure>);
static_assert(!std::is_constructible_v<OriginalCheckedPack, fileformat::PackStructure, const OriginalIdentity&>);
static_assert(!std::is_copy_constructible_v<OriginalCheckedPack>);
static_assert(!std::is_copy_assignable_v<OriginalCheckedPack>);
static_assert(std::is_nothrow_move_constructible_v<OriginalCheckedPack>);
static_assert(std::is_nothrow_move_assignable_v<OriginalCheckedPack>);

// The production name takes no set, neither a span nor an array of the
// source's type: only the form for tests of the comparison does.
template <typename Set>
concept CheckTakesSet = requires(std::vector<std::byte> file, Set set) {
    fileformat::CheckPackOriginal(std::move(file), set);
};
template <typename Set>
concept AgainstTakesSet = requires(std::vector<std::byte> file, Set set) {
    fileformat::CheckPackOriginalAgainst(std::move(file), set);
};
static_assert(!CheckTakesSet<std::span<const OriginalIdentity>>);
static_assert(!CheckTakesSet<std::array<OriginalIdentity, 1>>);
static_assert(AgainstTakesSet<std::span<const OriginalIdentity>>);

// Original, Entries and EntryBytes point into the pack, so only a pack that
// outlives the call offers them.
template <typename Pack>
concept OffersOriginal = requires(Pack&& pack) { std::forward<Pack>(pack).Original(); };
template <typename Pack>
concept OffersEntries = requires(Pack&& pack) { std::forward<Pack>(pack).Entries(); };
template <typename Pack>
concept OffersEntryBytes = requires(Pack&& pack) { std::forward<Pack>(pack).EntryBytes(0); };
static_assert(OffersOriginal<const OriginalCheckedPack&>);
static_assert(OffersEntries<const OriginalCheckedPack&>);
static_assert(OffersEntryBytes<const OriginalCheckedPack&>);
static_assert(!OffersOriginal<OriginalCheckedPack>);
static_assert(!OffersOriginal<const OriginalCheckedPack>);
static_assert(!OffersEntries<OriginalCheckedPack>);
static_assert(!OffersEntries<const OriginalCheckedPack>);
static_assert(!OffersEntryBytes<OriginalCheckedPack>);
static_assert(!OffersEntryBytes<const OriginalCheckedPack>);

constexpr std::array<std::uint16_t, 4> someVersion{1, 4, 0, 525};

// Digests from Digest() are made up: none is the digest of a real file.
std::array<std::byte, 32> Digest(std::uint8_t seed)
{
    std::array<std::byte, 32> digest{};
    for (std::size_t i = 0; i < digest.size(); ++i)
        digest[i] = static_cast<std::byte>(seed + 7 * i);
    return digest;
}

std::span<const std::byte> Bytes(std::string_view text)
{
    return std::as_bytes(std::span(text.data(), text.size()));
}

PackWriteEntry Entry(std::string_view key, std::uint32_t version, std::string_view payload)
{
    PackWriteEntry entry{{}, version, Bytes(payload)};
    for (std::size_t i = 0; i < entry.key.size(); ++i)
        entry.key[i] = key[i];
    return entry;
}

// Three entries of made-up keys and payloads.
const std::array<PackWriteEntry, 3> threeEntries{
    Entry("AAAA", 1, "a"),
    Entry("BBBB", 2, "bb"),
    Entry("CCCC", 3, "ccc"),
};

std::vector<std::byte> Write(const std::array<std::uint16_t, 4>& version, const std::array<std::byte, 32>& sha)
{
    return fileformat::WritePackStructure(version, sha, threeEntries);
}

OriginalCheckedPack CheckOriginal(const std::vector<std::byte>& file, std::initializer_list<OriginalIdentity> supported)
{
    return fileformat::CheckPackOriginalAgainst(file, std::span(supported.begin(), supported.size()));
}

void Accepts(Checks& check, std::string_view name, const std::array<std::uint16_t, 4>& version,
             const std::array<std::byte, 32>& sha, std::initializer_list<OriginalIdentity> supported,
             std::size_t expected)
{
    const std::span<const OriginalIdentity> set(supported.begin(), supported.size());
    const OriginalCheckedPack pack = fileformat::CheckPackOriginalAgainst(Write(version, sha), set);
    check.Equal(std::format("{}: original version", name), true, pack.Original().version == set[expected].version);
    check.Equal(std::format("{}: original SHA-256", name), true, pack.Original().sha256 == set[expected].sha256);
    check.Equal(std::format("{}: entry count", name), threeEntries.size(), pack.Entries().size());
    if (pack.Entries().size() != threeEntries.size())
        return;
    for (std::size_t i = 0; i < threeEntries.size(); ++i)
    {
        check.Equal(std::format("{}: key {}", name, i), true, threeEntries[i].key == pack.Entries()[i].key);
        check.Equal(std::format("{}: version {}", name, i), threeEntries[i].version, pack.Entries()[i].version);
        check.Equal(std::format("{}: payload {}", name, i), true,
                    std::ranges::equal(threeEntries[i].payload, pack.EntryBytes(i)));
    }
}

void Refuses(Checks& check, std::string_view name, const std::vector<std::byte>& file,
             std::initializer_list<OriginalIdentity> supported, OriginalProblem expected)
{
    try
    {
        CheckOriginal(file, supported);
        check.Fail(name, "was accepted");
    }
    catch (const fileformat::UnsupportedOriginalError& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was refused for another reason: {}", error.what()));
    }
}

void AcceptsASupportedOriginal(Checks& check)
{
    Accepts(check, "only identity", someVersion, Digest(1), {{someVersion, Digest(1)}}, 0);
    Accepts(check, "second of three", someVersion, Digest(2),
            {{someVersion, Digest(1)}, {someVersion, Digest(2)}, {{1, 4, 0, 526}, Digest(2)}}, 1);
    Accepts(check, "after another version with the digest", someVersion, Digest(3),
            {{{1, 4, 0, 524}, Digest(3)}, {someVersion, Digest(3)}}, 1);
    Accepts(check, "highest version", {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, Digest(4),
            {{{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, Digest(4)}}, 0);
}

void RefusesAnUnsupportedVersion(Checks& check)
{
    const std::vector<std::byte> file = Write(someVersion, Digest(1));
    Refuses(check, "no supported identity", file, {}, OriginalProblem::Version);
    for (std::size_t part = 0; part < someVersion.size(); ++part)
    {
        std::array<std::uint16_t, 4> other = someVersion;
        ++other[part];
        Refuses(check, std::format("version part {} differs", part), file, {{other, Digest(1)}},
                OriginalProblem::Version);
    }
}

void RefusesAnUnsupportedDigest(Checks& check)
{
    const std::vector<std::byte> file = Write(someVersion, Digest(1));
    for (std::size_t i = 0; i < 32; ++i)
    {
        std::array<std::byte, 32> other = Digest(1);
        other[i] ^= std::byte{0x01};
        Refuses(check, std::format("digest byte {} differs", i), file, {{someVersion, other}},
                OriginalProblem::Digest);
    }
    Refuses(check, "digest of another supported version", file,
            {{{1, 4, 0, 524}, Digest(1)}, {someVersion, Digest(2)}}, OriginalProblem::Digest);
}

void RefusesTheMagic(Checks& check, std::string_view name, const std::vector<std::byte>& file,
                     std::initializer_list<OriginalIdentity> supported)
{
    try
    {
        CheckOriginal(file, supported);
        check.Fail(name, "was accepted");
    }
    catch (const fileformat::PackStructureError& error)
    {
        if (error.Problem() != fileformat::PackStructureProblem::Magic)
            check.Fail(name, std::format("was refused for another reason: {}", error.what()));
    }
    catch (const fileformat::UnsupportedOriginalError&)
    {
        check.Fail(name, "was refused for its original before its container");
    }
}

// The container is checked before the original, so a damaged pack is
// reported as damaged even when its original would not be supported.
void ChecksTheContainerFirst(Checks& check)
{
    std::vector<std::byte> file = Write(someVersion, Digest(1));
    file[0] = std::byte{'W'};
    RefusesTheMagic(check, "bad magic, supported original", file, {{someVersion, Digest(1)}});
    RefusesTheMagic(check, "bad magic, no supported identity", file, {});
}

void RefusesAnEntryIndexPastTheEnd(Checks& check)
{
    const OriginalCheckedPack pack =
        fileformat::CheckPackOriginal(Write(supported_release::version, supported_release::Sha256()));
    for (const std::size_t index : {threeEntries.size(), std::numeric_limits<std::size_t>::max()})
    {
        try
        {
            pack.EntryBytes(index);
            check.Fail(std::format("entry {}", index), "was read");
        }
        catch (const std::out_of_range&)
        {
        }
    }
}

void ListsWhatIsUnchecked(Checks& check)
{
    const std::array<UncheckedPackRequirement, 2> expected{
        UncheckedPackRequirement::Catalogue,
        UncheckedPackRequirement::EntryValues,
    };
    check.Equal("unchecked", true, std::ranges::equal(expected, OriginalCheckedPack::Unchecked()));
}

// A moved pack keeps its bytes: the spans it gives still read the payloads.
// The pack it was moved from, by construction or by assignment, keeps its
// original and has no entries.
void MovesWithItsBytes(Checks& check)
{
    OriginalCheckedPack first =
        fileformat::CheckPackOriginal(Write(supported_release::version, supported_release::Sha256()));
    OriginalCheckedPack second = std::move(first);
    check.Equal("moved payload", true, std::ranges::equal(threeEntries[2].payload, second.EntryBytes(2)));
    check.Equal("moved-from original", true, first.Original().sha256 == supported_release::Sha256());
    check.Equal("moved-from entries", std::size_t{0}, first.Entries().size());

    OriginalCheckedPack third = fileformat::CheckPackOriginal(fileformat::WritePackStructure(
        supported_release::version, supported_release::Sha256(), std::span(threeEntries).first(1)));
    third = std::move(second);
    check.Equal("move-assigned entries", threeEntries.size(), third.Entries().size());
    check.Equal("move-assigned payload", true, std::ranges::equal(threeEntries[2].payload, third.EntryBytes(2)));
    check.Equal("move-assigned original", true, third.Original().sha256 == supported_release::Sha256());
    check.Equal("assigned-from original", true, second.Original().sha256 == supported_release::Sha256());
    check.Equal("assigned-from entries", std::size_t{0}, second.Entries().size());
}

// Without a set, the pack is checked against the source's: a synthetic pack
// that records the supported release's version and digest passes, and one
// that records any other fails.
void ChecksAgainstTheSupportedRelease(Checks& check)
{
    const OriginalCheckedPack pack =
        fileformat::CheckPackOriginal(Write(supported_release::version, supported_release::Sha256()));
    check.Equal("release: original version", true, pack.Original().version == supported_release::version);
    check.Equal("release: original SHA-256", true, pack.Original().sha256 == supported_release::Sha256());
    check.Equal("release: entry count", threeEntries.size(), pack.Entries().size());

    const auto refuses = [&](std::string_view name, const std::array<std::uint16_t, 4>& version,
                             const std::array<std::byte, 32>& sha, OriginalProblem expected) {
        try
        {
            fileformat::CheckPackOriginal(Write(version, sha));
            check.Fail(name, "was accepted");
        }
        catch (const fileformat::UnsupportedOriginalError& error)
        {
            if (error.Problem() != expected)
                check.Fail(name, std::format("was refused for another reason: {}", error.what()));
        }
    };
    for (std::size_t i = 0; i < 32; ++i)
    {
        std::array<std::byte, 32> other = supported_release::Sha256();
        other[i] ^= std::byte{0x01};
        refuses(std::format("release digest byte {} differs", i), supported_release::version, other,
                OriginalProblem::Digest);
    }
    refuses("made-up digest", supported_release::version, Digest(1), OriginalProblem::Digest);
    for (std::size_t part = 0; part < supported_release::version.size(); ++part)
    {
        std::array<std::uint16_t, 4> other = supported_release::version;
        ++other[part];
        refuses(std::format("release digest, version part {} differs", part), other, supported_release::Sha256(),
                OriginalProblem::Version);
    }
}

} // namespace

int main()
{
    Checks check("data pack validation");
    check.Run("supported original", [&] { AcceptsASupportedOriginal(check); });
    check.Run("unsupported version", [&] { RefusesAnUnsupportedVersion(check); });
    check.Run("unsupported digest", [&] { RefusesAnUnsupportedDigest(check); });
    check.Run("container first", [&] { ChecksTheContainerFirst(check); });
    check.Run("entry index past the end", [&] { RefusesAnEntryIndexPastTheEnd(check); });
    check.Run("unchecked requirements", [&] { ListsWhatIsUnchecked(check); });
    check.Run("move", [&] { MovesWithItsBytes(check); });
    check.Run("source-owned release", [&] { ChecksAgainstTheSupportedRelease(check); });
    return check.ExitCode();
}
