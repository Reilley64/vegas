#include "check.h"
#include "fileformat/original_identity.h"
#include "fileformat/pe_file.h"
#include "fileformat/pe_fixture.h"
#include "fileformat/supported_release.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <format>
#include <initializer_list>
#include <span>
#include <string_view>
#include <vector>

namespace
{

using fileformat::OriginalIdentity;
using fileformat::OriginalProblem;

// The production name takes no set, neither a span nor an array of the
// source's type: only the form for tests of the comparison does.
template <typename Set>
concept IdentifyTakesSet = requires(const fileformat::PeFile& pe, const std::array<std::byte, 32>& sha256, Set set) {
    fileformat::IdentifyOriginal(pe, sha256, set);
};
template <typename Set>
concept AgainstTakesSet = requires(const fileformat::PeFile& pe, const std::array<std::byte, 32>& sha256, Set set) {
    fileformat::IdentifyOriginalAgainst(pe, sha256, set);
};
static_assert(!IdentifyTakesSet<std::span<const OriginalIdentity>>);
static_assert(!IdentifyTakesSet<std::array<OriginalIdentity, 1>>);
static_assert(AgainstTakesSet<std::span<const OriginalIdentity>>);

// Digests from Digest() are made up: none is the digest of a real file.
std::array<std::byte, 32> Digest(std::uint8_t seed)
{
    std::array<std::byte, 32> digest{};
    for (std::size_t i = 0; i < digest.size(); ++i)
        digest[i] = static_cast<std::byte>(seed + 7 * i);
    return digest;
}

fileformat::PeFile WithFileVersion(const std::array<std::uint16_t, 4>& version)
{
    pe_fixture::Layout layout = pe_fixture::Typical();
    layout.sections[3].raw = pe_fixture::VersionResource(0x5000, version, {9, 9, 9, 9});
    return fileformat::ParsePeFile(pe_fixture::Build(layout));
}

void Identifies(Checks& check, std::string_view name, const fileformat::PeFile& pe,
                const std::array<std::byte, 32>& digest, std::initializer_list<OriginalIdentity> supported,
                std::size_t expected)
{
    const std::span<const OriginalIdentity> set(supported.begin(), supported.size());
    const OriginalIdentity identity = fileformat::IdentifyOriginalAgainst(pe, digest, set);
    check.Equal(std::format("{}: version", name), true, identity.version == set[expected].version);
    check.Equal(std::format("{}: digest", name), true, identity.sha256 == set[expected].sha256);
}

void Refuses(Checks& check, std::string_view name, const fileformat::PeFile& pe,
             const std::array<std::byte, 32>& digest, std::initializer_list<OriginalIdentity> supported,
             OriginalProblem expected)
{
    try
    {
        fileformat::IdentifyOriginalAgainst(pe, digest, std::span(supported.begin(), supported.size()));
        check.Fail(name, "was identified");
    }
    catch (const fileformat::UnsupportedOriginalError& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was refused for another reason: {}", error.what()));
    }
}

void IdentifiesASupportedOriginal(Checks& check)
{
    const fileformat::PeFile pe = WithFileVersion({1, 4, 0, 525});
    Identifies(check, "only identity", pe, Digest(1), {{{1, 4, 0, 525}, Digest(1)}}, 0);
    Identifies(check, "second of three", pe, Digest(2),
               {{{1, 4, 0, 525}, Digest(1)}, {{1, 4, 0, 525}, Digest(2)}, {{1, 4, 0, 526}, Digest(2)}}, 1);
    Identifies(check, "after another version with the digest", pe, Digest(3),
               {{{1, 4, 0, 524}, Digest(3)}, {{1, 4, 0, 525}, Digest(3)}}, 1);

    const fileformat::PeFile limits = WithFileVersion({0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF});
    Identifies(check, "highest version", limits, Digest(4), {{{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, Digest(4)}}, 0);
}

void RefusesAnUnsupportedVersion(Checks& check)
{
    const fileformat::PeFile pe = WithFileVersion({1, 4, 0, 525});
    Refuses(check, "no supported identity", pe, Digest(1), {}, OriginalProblem::Version);
    for (const std::array<std::uint16_t, 4>& other :
         {std::array<std::uint16_t, 4>{2, 4, 0, 525}, {1, 5, 0, 525}, {1, 4, 1, 525}, {1, 4, 0, 524}, {525, 0, 4, 1}})
    {
        Refuses(check, std::format("version {}.{}.{}.{}", other[0], other[1], other[2], other[3]), pe, Digest(1),
                {{other, Digest(1)}}, OriginalProblem::Version);
    }
    // The product version is not the one compared.
    pe_fixture::Layout layout = pe_fixture::Typical();
    layout.sections[3].raw = pe_fixture::VersionResource(0x5000, {1, 0, 0, 0}, {1, 4, 0, 525});
    Refuses(check, "product version only", fileformat::ParsePeFile(pe_fixture::Build(layout)), Digest(1),
            {{{1, 4, 0, 525}, Digest(1)}}, OriginalProblem::Version);
}

void RefusesAnUnsupportedDigest(Checks& check)
{
    const fileformat::PeFile pe = WithFileVersion({1, 4, 0, 525});
    Refuses(check, "other digest", pe, Digest(2), {{{1, 4, 0, 525}, Digest(1)}}, OriginalProblem::Digest);
    for (std::size_t i = 0; i < 32; ++i)
    {
        std::array<std::byte, 32> changed = Digest(1);
        changed[i] ^= std::byte{0x80};
        Refuses(check, std::format("digest byte {} changed", i), pe, changed, {{{1, 4, 0, 525}, Digest(1)}},
                OriginalProblem::Digest);
    }
    // The digest of another supported version does not count.
    Refuses(check, "digest of another version", pe, Digest(3),
            {{{1, 4, 0, 525}, Digest(1)}, {{1, 4, 0, 526}, Digest(3)}}, OriginalProblem::Digest);
}

// The source owns one supported release, and a production call checks
// against it.
void SupportsTheRelease(Checks& check)
{
    const std::span<const OriginalIdentity> supported = fileformat::SupportedOriginals();
    check.Equal("supported releases", std::size_t{1}, supported.size());
    if (supported.size() != 1)
        return;
    check.Equal("release version", true, supported[0].version == supported_release::version);
    check.Equal("release SHA-256", true, supported[0].sha256 == supported_release::Sha256());

    const fileformat::PeFile pe = WithFileVersion(supported_release::version);
    const OriginalIdentity identity = fileformat::IdentifyOriginal(pe, supported_release::Sha256());
    check.Equal("release identified: version", true, identity.version == supported[0].version);
    check.Equal("release identified: digest", true, identity.sha256 == supported_release::Sha256());

    const auto refuses = [&](std::string_view name, const fileformat::PeFile& file,
                             const std::array<std::byte, 32>& digest, OriginalProblem expected) {
        try
        {
            fileformat::IdentifyOriginal(file, digest);
            check.Fail(name, "was identified");
        }
        catch (const fileformat::UnsupportedOriginalError& error)
        {
            if (error.Problem() != expected)
                check.Fail(name, std::format("was refused for another reason: {}", error.what()));
        }
    };
    for (std::size_t i = 0; i < 32; ++i)
    {
        std::array<std::byte, 32> changed = supported_release::Sha256();
        changed[i] ^= std::byte{0x01};
        refuses(std::format("release digest byte {} changed", i), pe, changed, OriginalProblem::Digest);
    }
    refuses("made-up digest", pe, Digest(1), OriginalProblem::Digest);
    for (const std::array<std::uint16_t, 4>& other :
         {std::array<std::uint16_t, 4>{2, 4, 0, 525}, {1, 5, 0, 525}, {1, 4, 1, 525}, {1, 4, 0, 524}, {1, 4, 0, 526}})
    {
        refuses(std::format("release digest, version {}.{}.{}.{}", other[0], other[1], other[2], other[3]),
                WithFileVersion(other), supported_release::Sha256(), OriginalProblem::Version);
    }
}

} // namespace

int main()
{
    Checks check("original identity");
    check.Run("supported", [&] { IdentifiesASupportedOriginal(check); });
    check.Run("version", [&] { RefusesAnUnsupportedVersion(check); });
    check.Run("digest", [&] { RefusesAnUnsupportedDigest(check); });
    check.Run("source-owned release", [&] { SupportsTheRelease(check); });
    return check.ExitCode();
}
