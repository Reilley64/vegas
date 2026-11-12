#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/data_pack_startup.h"
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

// Made-up strings: none is a string of the original release.
constexpr Strings firstStrings{"test mutex", "first test message", "Test", "second test message"};
constexpr Strings secondStrings{"other mutex", "another first message", "Other", "another second message"};

constexpr std::array<std::size_t, 4> fieldBytes{20, 60, 8, 52};

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

// A pack of one entry. With the defaults it is a complete pack of catalogue
// version 1 that records the supported release's identity: it is compared,
// not proved.
std::vector<std::byte> Pack(std::span<const std::byte> payload, std::array<char, 4> key = {'I', 'N', 'S', 'T'},
                            std::array<std::byte, 32> sha = supported_release::Sha256(), std::uint32_t version = 1)
{
    const std::array<fileformat::PackWriteEntry, 1> entries{{{key, version, payload}}};
    return fileformat::WritePackStructure(supported_release::version, sha, entries);
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

// A complete pack with the header field at `offset` set to `value` and the
// CRC-32 stored again, so only the field is wrong.
std::vector<std::byte> PackWithHeaderField(std::span<const std::byte> payload, std::size_t offset, std::uint32_t value)
{
    std::vector<std::byte> bytes = Pack(payload);
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

void ExpectPublished(Checks& checks, std::string_view test, const Strings& expected)
{
    const fileformat::SingleInstanceStrings& published = fnv::startup::PublishedSingleInstanceStrings();
    if (!SameField(published.mutexName, expected.mutexName) ||
        !SameField(published.firstMessageText, expected.firstMessageText) ||
        !SameField(published.messageCaption, expected.messageCaption) ||
        !SameField(published.secondMessageText, expected.secondMessageText))
        checks.Fail(test, std::format("the published strings are not those of the pack with \"{}\"",
                                      expected.mutexName));
}

// Loads the pack of `folder` and expects success with the owner's published
// strings returned.
void ExpectLoaded(Checks& checks, std::string_view test, const Folder& folder, const Strings& expected)
{
    const fnv::startup::DataPackLoad load = fnv::startup::LoadDataPack(folder.path);
    if (const std::string* failure = std::get_if<std::string>(&load))
        checks.Fail(test, std::format("the stage refused a complete pack: {}", *failure));
    else if (&std::get_if<0>(&load)->get() != &fnv::startup::PublishedSingleInstanceStrings())
        checks.Fail(test, "the stage did not return the owner's published strings");
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
    // A refused stage publishes nothing: the owner is still unpublished.
    if (argc == 2 && std::strcmp(argv[1], "--refused-then-read") == 0)
    {
        Folder empty;
        if (!std::holds_alternative<std::string>(fnv::startup::LoadDataPack(empty.path)))
            return 1;
        std::fprintf(stderr, "refused-then-read\n");
        fnv::startup::PublishedSingleInstanceStrings();
        return 0;
    }

    Checks checks("data pack startup");
    const std::vector<std::byte> first = Payload(firstStrings);
    const std::vector<std::byte> second = Payload(secondStrings);

    checks.Run("complete pack", [&] {
        Folder folder;
        folder.WritePack(Pack(first));
        ExpectLoaded(checks, "complete pack", folder, firstStrings);
    });

    // Each refused pack holds the second strings, so a pack whose values were
    // used before it failed would leave them published.
    checks.Run("missing pack", [&] {
        Folder folder;
        ExpectRefused(checks, "missing pack", folder.path, "vegas-data.pack is missing beside the executable");
        ExpectPublished(checks, "missing pack", firstStrings);
    });
    checks.Run("missing folder", [&] {
        Folder folder;
        ExpectRefused(checks, "missing folder", folder.path / "absent", "is missing beside the executable");
    });
    checks.Run("pack in a nested folder", [&] {
        Folder folder;
        fs::create_directory(folder.path / "Data");
        Folder::Write(folder.path / "Data" / fnv::startup::dataPackFileName, Pack(second));
        ExpectRefused(checks, "pack in a nested folder", folder.path, "is missing beside the executable");
        ExpectPublished(checks, "pack in a nested folder", firstStrings);
    });
    checks.Run("folder in place of the pack", [&] {
        Folder folder;
        fs::create_directory(folder.path / fnv::startup::dataPackFileName);
        ExpectRefused(checks, "folder in place of the pack", folder.path, "cannot be read");
        ExpectPublished(checks, "folder in place of the pack", firstStrings);
    });
    checks.Run("empty file", [&] {
        Folder folder;
        folder.WritePack({});
        ExpectRefused(checks, "empty file", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "empty file", firstStrings);
    });
    checks.Run("corrupt pack", [&] {
        Folder folder;
        std::vector<std::byte> bytes = Pack(second);
        bytes.back() ^= std::byte{1};
        folder.WritePack(bytes);
        ExpectRefused(checks, "corrupt pack", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "corrupt pack", firstStrings);
    });
    checks.Run("truncated pack", [&] {
        Folder folder;
        std::vector<std::byte> bytes = Pack(second);
        bytes.pop_back();
        folder.WritePack(bytes);
        ExpectRefused(checks, "truncated pack", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "truncated pack", firstStrings);
    });
    checks.Run("unsupported original", [&] {
        Folder folder;
        std::array<std::byte, 32> sha = supported_release::Sha256();
        sha[0] ^= std::byte{1};
        folder.WritePack(Pack(second, {'I', 'N', 'S', 'T'}, sha));
        ExpectRefused(checks, "unsupported original", folder.path, "was not prepared from a supported original release");
        ExpectPublished(checks, "unsupported original", firstStrings);
    });
    checks.Run("incomplete pack", [&] {
        Folder folder;
        folder.WritePack(Pack(second, {'I', 'N', 'S', 'U'}));
        ExpectRefused(checks, "incomplete pack", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "incomplete pack", firstStrings);
    });
    checks.Run("field without a zero byte", [&] {
        Folder folder;
        std::vector<std::byte> bytes = second;
        for (std::size_t i = fieldBytes[0] + fieldBytes[1]; i < fieldBytes[0] + fieldBytes[1] + fieldBytes[2]; ++i)
            bytes[i] = std::byte{'x'};
        folder.WritePack(Pack(bytes));
        ExpectRefused(checks, "field without a zero byte", folder.path, "is not a valid data pack");
        ExpectPublished(checks, "field without a zero byte", firstStrings);
    });

    // A pack of another catalogue version, with another version of the entry,
    // or made for another build: each is refused by the check that names it.
    checks.Run("catalogue version 2", [&] {
        Folder folder;
        folder.WritePack(PackWithHeaderField(second, at::catalogueVersion, 2));
        ExpectRefused(checks, "catalogue version 2", folder.path,
                      "is not a valid data pack: data pack: catalogue version: is not 1");
        ExpectPublished(checks, "catalogue version 2", firstStrings);
    });
    checks.Run("entry version 2", [&] {
        Folder folder;
        folder.WritePack(Pack(second, {'I', 'N', 'S', 'T'}, supported_release::Sha256(), 2));
        ExpectRefused(checks, "entry version 2", folder.path,
                      "is not a valid data pack: data pack: entry INST: version is not the catalogue's");
        ExpectPublished(checks, "entry version 2", firstStrings);
    });
    checks.Run("envelope version 2", [&] {
        Folder folder;
        folder.WritePack(PackWithHeaderField(second, at::envelopeVersion, 2));
        ExpectRefused(checks, "envelope version 2", folder.path,
                      "is not a valid data pack: data pack: envelope version: is not 1");
        ExpectPublished(checks, "envelope version 2", firstStrings);
    });
    checks.Run("native data contract 0", [&] {
        Folder folder;
        folder.WritePack(PackWithHeaderField(second, at::nativeDataContract, 0));
        ExpectRefused(checks, "native data contract 0", folder.path,
                      "is not a valid data pack: data pack: native data contract: is not 1");
        ExpectPublished(checks, "native data contract 0", firstStrings);
    });
    checks.Run("build target 2", [&] {
        Folder folder;
        folder.WritePack(PackWithHeaderField(second, at::buildTarget, 2));
        ExpectRefused(checks, "build target 2", folder.path,
                      "is not a valid data pack: data pack: build target: is not 1");
        ExpectPublished(checks, "build target 2", firstStrings);
    });

    checks.Run("another complete pack", [&] {
        Folder folder;
        folder.WritePack(Pack(second));
        ExpectLoaded(checks, "another complete pack", folder, secondStrings);
    });
    return checks.ExitCode();
}
