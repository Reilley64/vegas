#include "check.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_structure.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/pe_file.h"
#include "fileformat/pe_fixture.h"
#include "fileformat/supported_release.h"
#include "setup/prepare_pack.h"
#include "setup/staged_pack.h"

#include "mbedtls/sha256.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <format>
#include <functional>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

using fileformat::OriginalIdentity;
using fileformat::OriginalProblem;
using fileformat::PeProblem;
using setup::ExtractProblem;
namespace at = pe_fixture::at;

// PrepareDataPack takes the bytes only: no supported set.
template <typename... Args>
concept Prepares = requires(Args&&... args) { setup::PrepareDataPack(std::forward<Args>(args)...); };
static_assert(Prepares<std::vector<std::byte>>);
static_assert(!Prepares<std::vector<std::byte>, std::span<const OriginalIdentity>>);
static_assert(!Prepares<std::vector<std::byte>, std::array<OriginalIdentity, 1>>);

// Steps 1 to 5 of PrepareDataPack, the same code, with
// fileformat::IdentifyOriginalAgainst and `supported` in step 3; then
// fileformat::CheckPackOriginalAgainst of the written bytes with `supported`
// instead of step 6. The written bytes are returned: they are not a validated
// pack. It lives in the test only, so no file under src/ takes a set.
std::vector<std::byte> PrepareDataPackAgainst(std::vector<std::byte> executable,
                                              std::span<const OriginalIdentity> supported)
{
    std::vector<std::byte> bytes = setup::staged::StagePack(
        std::move(executable), [&](const fileformat::PeFile& pe, const std::array<std::byte, 32>& sha256) {
            return fileformat::IdentifyOriginalAgainst(pe, sha256, supported);
        });
    fileformat::CheckPackOriginalAgainst(bytes, supported);
    return bytes;
}

// The recipe facts of C1, spelled by the test itself so that a change to the
// source's table fails here instead of agreeing with itself: each field's
// original address and capacity, in catalogue order.
struct Field
{
    std::string_view name;
    std::uint32_t address;
    std::size_t capacity;
};
constexpr std::array<Field, 4> fields{{
    {"mutex name", 0x01082ab8, 20},
    {"first message text", 0x01082a7c, 60},
    {"message caption", 0x0104df38, 8},
    {"second message text", 0x01082a48, 52},
}};

constexpr std::uint32_t imageBase = 0x00400000;

// Made-up strings, none of them a string of the original release, except
// the caption, which the recipe's literal at its address fixes. The second
// message fills its field up to its zero byte.
using Texts = std::array<std::string, 4>;
const Texts someTexts{"test mutex", "first test message", "Error", std::string(51, 's')};

// Section characteristics of the Microsoft PE and COFF specification.
constexpr std::uint32_t code = 0x00000020;
constexpr std::uint32_t initializedData = 0x00000040;
constexpr std::uint32_t uninitializedData = 0x00000080;
constexpr std::uint32_t execute = 0x20000000;
constexpr std::uint32_t read = 0x40000000;
constexpr std::uint32_t write = 0x80000000;

// An executable with code, the caption in .rdata, the other three strings in
// .data, which has a zero tail, and a version resource. Its file version is
// 1.4.0.525. Each section's characteristics are the second member.
struct Synthetic
{
    pe_fixture::Layout layout;
    std::vector<std::uint32_t> characteristics;
    Texts texts = someTexts;
};

Synthetic Typical()
{
    Synthetic synthetic;
    pe_fixture::Layout& layout = synthetic.layout;
    layout.imageBase = imageBase;
    layout.entryPoint = 0x1010;
    layout.sections = {
        {".text", 0x1000, 0x30, pe_fixture::Pattern(0x200, 1)},
        {".rdata", 0xC4D000, 0x1000, pe_fixture::Pattern(0x1000, 2)},
        {".data", 0xC82000, 0x2000, pe_fixture::Pattern(0x1000, 3)},
        {".rsrc", 0xC84000, at::versionResourceBytes,
         pe_fixture::VersionResource(0xC84000, {1, 4, 0, 525}, {1, 4, 0, 525})},
    };
    layout.resourceAddress = 0xC84000;
    layout.resourceSize = at::versionResourceBytes;
    synthetic.characteristics = {code | execute | read, initializedData | read, initializedData | read | write,
                                 initializedData | read};
    return synthetic;
}

// The file. Each text is stored at its field's address where a section's
// stored bytes hold it, then a zero byte when the field has room, then 0xAB
// bytes to the end of the field: bytes setup must not copy.
std::vector<std::byte> Build(const Synthetic& synthetic)
{
    const pe_fixture::Layout& layout = synthetic.layout;
    std::vector<std::byte> file = pe_fixture::Build(layout);
    const std::vector<std::uint32_t> rawOffsets = pe_fixture::RawOffsets(layout);
    for (std::size_t i = 0; i < layout.sections.size(); ++i)
        pe_fixture::Put32(file, at::Section(i, 36), synthetic.characteristics[i]);
    for (std::size_t f = 0; f < fields.size(); ++f)
    {
        std::vector<std::byte> stored(fields[f].capacity, std::byte{0xAB});
        const std::string& text = synthetic.texts[f];
        std::ranges::transform(text, stored.begin(), [](char c) { return static_cast<std::byte>(c); });
        if (text.size() < stored.size())
            stored[text.size()] = std::byte{0};
        for (std::size_t s = 0; s < layout.sections.size(); ++s)
        {
            const pe_fixture::Section& section = layout.sections[s];
            for (std::size_t b = 0; b < stored.size(); ++b)
            {
                const std::uint64_t at = std::uint64_t{fields[f].address} + b;
                if (at < layout.imageBase)
                    continue;
                const std::uint64_t rva = at - layout.imageBase;
                if (rva >= section.virtualAddress && rva - section.virtualAddress < section.raw.size())
                    file[rawOffsets[s] + (rva - section.virtualAddress)] = stored[b];
            }
        }
    }
    return file;
}

std::array<std::byte, 32> Sha256(std::span<const std::byte> bytes)
{
    std::array<std::byte, 32> digest{};
    if (mbedtls_sha256(reinterpret_cast<const unsigned char*>(bytes.data()), bytes.size(),
                       reinterpret_cast<unsigned char*>(digest.data()), 0) != 0)
        throw std::runtime_error("the test could not hash its executable");
    return digest;
}

// The identity of the synthetic executable `file`, version 1.4.0.525.
OriginalIdentity IdentityOf(std::span<const std::byte> file) { return {{1, 4, 0, 525}, Sha256(file)}; }

// PrepareDataPackAgainst with the synthetic executable's own identity.
std::vector<std::byte> PrepareAgainstItself(const std::vector<std::byte>& file)
{
    const std::array<OriginalIdentity, 1> supported{IdentityOf(file)};
    return PrepareDataPackAgainst(file, supported);
}

// C1's payload as setup writes it: each text, then zeros to its field's end.
std::vector<std::byte> Payload(const Texts& texts)
{
    std::vector<std::byte> payload;
    for (std::size_t f = 0; f < fields.size(); ++f)
    {
        std::ranges::transform(texts[f], std::back_inserter(payload), [](char c) { return static_cast<std::byte>(c); });
        payload.resize(payload.size() + fields[f].capacity - texts[f].size());
    }
    return payload;
}

template <std::size_t Capacity> bool Holds(const std::array<char, Capacity>& field, std::string_view text)
{
    return text.size() < Capacity &&
           std::ranges::equal(field.begin(), field.begin() + text.size(), text.begin(), text.end()) &&
           std::all_of(field.begin() + text.size(), field.end(), [](char c) { return c == '\0'; });
}

// Expects `body` to throw `Error` with the problem given and, when `field` is
// not empty, a message that names it.
template <typename Error, typename Problem>
void Refuses(Checks& check, std::string_view name, const std::function<void()>& body, Problem expected,
             std::string_view field = {})
{
    try
    {
        body();
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
        check.Fail(name, std::format("threw another error: {}", error.what()));
    }
}

void RefusesExtraction(Checks& check, std::string_view name, const Synthetic& synthetic, ExtractProblem expected,
                       std::string_view field)
{
    const std::vector<std::byte> file = Build(synthetic);
    Refuses<setup::ExtractError>(check, name, [&] { PrepareAgainstItself(file); }, expected, field);
}

// The pack written from a synthetic executable records its identity and
// holds C1 as setup writes it. Setup does not yet read the main window class,
// so the same entry, written again with the supported release's identity
// (compared, not proved), is refused by the complete validator for the
// missing WNDC entry; with a made-up WNDC entry beside it, it passes with the
// same strings.
void PreparesAPack(Checks& check)
{
    const std::vector<std::byte> file = Build(Typical());
    const std::array<OriginalIdentity, 1> supported{IdentityOf(file)};
    const std::vector<std::byte> staged = PrepareDataPackAgainst(file, supported);

    const fileformat::OriginalCheckedPack pack = fileformat::CheckPackOriginalAgainst(staged, supported);
    check.Equal("staged: original version", true, pack.Original().version == supported[0].version);
    check.Equal("staged: original SHA-256", true, pack.Original().sha256 == supported[0].sha256);
    check.Equal("staged: entries", std::size_t{1}, pack.Entries().size());
    check.Equal("staged: key", std::string_view("INST"), std::string_view(pack.Entries()[0].key.data(), 4));
    check.Equal("staged: entry version", std::uint32_t{1}, pack.Entries()[0].version);
    const std::vector<std::byte> payload(pack.EntryBytes(0).begin(), pack.EntryBytes(0).end());
    check.Equal("staged: payload size", std::size_t{140}, payload.size());
    check.Equal("staged: payload is each string, then zeros", true, payload == Payload(someTexts));

    Refuses<fileformat::UnsupportedOriginalError>(
        check, "staged: complete validator", [&] { fileformat::ValidatePack(staged); }, OriginalProblem::Digest);

    const std::array<fileformat::PackWriteEntry, 1> entries{{{{'I', 'N', 'S', 'T'}, 1, payload}}};
    Refuses<fileformat::PackCatalogueError>(
        check, "C1 alone: complete validator",
        [&] {
            fileformat::ValidatePack(
                fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), entries));
        },
        fileformat::PackCatalogueProblem::MissingEntry, "entry WNDC");
    std::vector<std::byte> madeUpClass(256);
    madeUpClass[0] = std::byte{'w'};
    const std::array<fileformat::PackWriteEntry, 2> withClass{
        {{{'I', 'N', 'S', 'T'}, 1, payload}, {{'W', 'N', 'D', 'C'}, 1, madeUpClass}}};
    const fileformat::ValidatedPack validated = fileformat::ValidatePack(
        fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), withClass));
    const fileformat::SingleInstanceStrings& strings = validated.SingleInstance();
    check.Equal("validated: mutex name", true, Holds(strings.mutexName, someTexts[0]));
    check.Equal("validated: first message text", true, Holds(strings.firstMessageText, someTexts[1]));
    check.Equal("validated: message caption", true, Holds(strings.messageCaption, someTexts[2]));
    check.Equal("validated: second message text", true, Holds(strings.secondMessageText, someTexts[3]));
}

// The production preparation takes no set, so a synthetic executable is
// never a supported original release; identification comes before any field
// is read.
void RefusesUnsupportedExecutables(Checks& check)
{
    const std::vector<std::byte> file = Build(Typical());
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "production: synthetic", [&] { setup::PrepareDataPack(file); }, OriginalProblem::Digest);

    Synthetic other = Typical();
    other.layout.sections[3].raw = pe_fixture::VersionResource(0xC84000, {1, 4, 0, 524}, {1, 4, 0, 525});
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "production: another version", [&] { setup::PrepareDataPack(Build(other)); }, OriginalProblem::Version);

    Synthetic unreadable = Typical();
    unreadable.layout.sections.erase(unreadable.layout.sections.begin() + 1);
    unreadable.characteristics.erase(unreadable.characteristics.begin() + 1);
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "production: identity before data", [&] { setup::PrepareDataPack(Build(unreadable)); },
        OriginalProblem::Digest);

    // The digest is of every byte of the file.
    std::array<OriginalIdentity, 1> supported{IdentityOf(std::span(file).first(file.size() - 1))};
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "against: digest of all but the last byte", [&] { PrepareDataPackAgainst(file, supported); },
        OriginalProblem::Digest);
    supported[0] = IdentityOf(file);
    supported[0].sha256[31] ^= std::byte{1};
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "against: another digest", [&] { PrepareDataPackAgainst(file, supported); }, OriginalProblem::Digest);
    supported[0] = IdentityOf(file);
    supported[0].version = {1, 4, 0, 524};
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "against: another version", [&] { PrepareDataPackAgainst(file, supported); }, OriginalProblem::Version);
    Refuses<fileformat::UnsupportedOriginalError>(
        check, "against: identity before data",
        [&] {
            const std::vector<std::byte> bytes = Build(unreadable);
            const std::array<OriginalIdentity, 1> other{IdentityOf(file)};
            PrepareDataPackAgainst(bytes, other);
        },
        OriginalProblem::Digest);
}

// Bytes that are not a 32-bit executable, including a 64-bit one such as the
// replacement this project builds, are refused before identification.
void RefusesOtherFiles(Checks& check)
{
    const std::vector<std::byte> text{std::byte{'M'}, std::byte{'Z'}};
    Refuses<fileformat::PeError>(
        check, "production: two bytes", [&] { setup::PrepareDataPack(text); }, PeProblem::DosHeaderTruncated);
    Synthetic x64 = Typical();
    x64.layout.machine = 0x8664;
    const std::vector<std::byte> file = Build(x64);
    Refuses<fileformat::PeError>(
        check, "production: 64-bit", [&] { setup::PrepareDataPack(file); }, PeProblem::Machine);
    Refuses<fileformat::PeError>(check, "against: 64-bit", [&] { PrepareAgainstItself(file); }, PeProblem::Machine);
}

// A field is read only from the stored bytes of a section marked as
// initialized data and not as code or executable, and never from .bind.
void RefusesUnreadableSections(Checks& check)
{
    Synthetic bind = Typical();
    bind.layout.sections[1].name = ".bind";
    RefusesExtraction(check, "caption in .bind", bind, ExtractProblem::SteamStubSection, "message caption");
    bind.characteristics[1] = code | execute | read;
    RefusesExtraction(check, "caption in .bind, as code", bind, ExtractProblem::SteamStubSection, "message caption");

    Synthetic text = Typical();
    text.characteristics[1] = code | read;
    RefusesExtraction(check, "caption in code", text, ExtractProblem::CodeSection, "message caption");
    text.characteristics[1] = execute | initializedData | read;
    RefusesExtraction(check, "caption in an executable section", text, ExtractProblem::CodeSection, "message caption");
    text.characteristics[1] = code | execute | read;
    RefusesExtraction(check, "caption in code not marked as data", text, ExtractProblem::CodeSection,
                      "message caption");

    Synthetic notData = Typical();
    notData.characteristics[1] = read;
    RefusesExtraction(check, "caption in a section without data", notData, ExtractProblem::NotInitializedData,
                      "message caption");
    notData.characteristics[1] = uninitializedData | read | write;
    RefusesExtraction(check, "caption in uninitialized data", notData, ExtractProblem::NotInitializedData,
                      "message caption");
}

// A field lies in one section's stored bytes: not in its zero tail, not
// across its end and not outside every section.
void RefusesRangesOutsideStoredBytes(Checks& check)
{
    // .data at 0xC82000; the mutex name is at 0xC82AB8 to 0xC82ACB.
    Synthetic tail = Typical();
    tail.layout.sections[2].raw.resize(0xA00);
    RefusesExtraction(check, "mutex name in the zero tail", tail, ExtractProblem::ZeroTail, "mutex name");
    tail.layout.sections[2].raw = pe_fixture::Pattern(0xAC0, 3);
    RefusesExtraction(check, "mutex name into the zero tail", tail, ExtractProblem::ZeroTail, "mutex name");
    // The fixture pads sections to even file offsets, so the stored size is even.
    tail.layout.sections[2].raw = pe_fixture::Pattern(0xACA, 3);
    RefusesExtraction(check, "mutex name's last two bytes in the zero tail", tail, ExtractProblem::ZeroTail,
                      "mutex name");
    tail.layout.sections[2].raw = pe_fixture::Pattern(0xACC, 3);
    check.Run("mutex name ends with the stored bytes", [&] { PrepareAgainstItself(Build(tail)); });

    Synthetic end = Typical();
    end.layout.sections[2].virtualSize = 0xAC0;
    end.layout.sections[2].raw = pe_fixture::Pattern(0xAC0, 3);
    RefusesExtraction(check, "mutex name across the end of its section", end, ExtractProblem::ZeroTail, "mutex name");

    Synthetic none = Typical();
    none.layout.sections.erase(none.layout.sections.begin() + 1);
    none.characteristics.erase(none.characteristics.begin() + 1);
    RefusesExtraction(check, "caption in no section", none, ExtractProblem::NoSection, "message caption");

    Synthetic high = Typical();
    high.layout.imageBase = 0x02000000;
    RefusesExtraction(check, "below the image base", high, ExtractProblem::NoSection,
                      "mutex name: is below the image base");
}

// A string is copied through its first zero byte, which must lie within its
// field, and the caption is exactly the recipe literal's text.
void RefusesStrings(Checks& check)
{
    Synthetic noZero = Typical();
    noZero.texts[1] = std::string(60, 'f');
    RefusesExtraction(check, "first message without a zero byte", noZero, ExtractProblem::NoTerminator,
                      "first message text");
    noZero.texts[1] = std::string(59, 'f');
    check.Run("first message with its zero byte last", [&] { PrepareAgainstItself(Build(noZero)); });

    for (const std::string& caption :
         {std::string("Errox"), std::string("Err"), std::string("Error!"), std::string(""), std::string("error")})
    {
        Synthetic other = Typical();
        other.texts[2] = caption;
        RefusesExtraction(check, std::format("caption \"{}\"", caption), other, ExtractProblem::KnownString,
                          "message caption");
    }
}

// The fields are checked in catalogue order, and each field's checks in the
// order of ExtractProblem.
void ReportsTheFirstProblem(Checks& check)
{
    Synthetic two = Typical();
    two.texts[0] = std::string(20, 'm');
    two.layout.sections[1].name = ".bind";
    RefusesExtraction(check, "mutex name before caption", two, ExtractProblem::NoTerminator, "mutex name");

    Synthetic order = Typical();
    order.texts[2] = "Errox";
    order.texts[3] = std::string(52, 's');
    RefusesExtraction(check, "caption before second message", order, ExtractProblem::KnownString, "message caption");

    Synthetic sections = Typical();
    sections.characteristics[1] = code;
    sections.layout.sections[1].raw.resize(0xF00);
    RefusesExtraction(check, "code before zero tail", sections, ExtractProblem::CodeSection, "message caption");
}

} // namespace

int main()
{
    Checks check("setup prepare");
    check.Run("prepares a pack", [&] { PreparesAPack(check); });
    check.Run("unsupported executables", [&] { RefusesUnsupportedExecutables(check); });
    check.Run("other files", [&] { RefusesOtherFiles(check); });
    check.Run("unreadable sections", [&] { RefusesUnreadableSections(check); });
    check.Run("ranges outside stored bytes", [&] { RefusesRangesOutsideStoredBytes(check); });
    check.Run("strings", [&] { RefusesStrings(check); });
    check.Run("first problem", [&] { ReportsTheFirstProblem(check); });
    return check.ExitCode();
}
