#include "check.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_open.h"
#include "fileformat/pack_structure.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <random>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

namespace
{

namespace fs = std::filesystem;

using fileformat::OriginalCheckedPack;
using fileformat::OriginalIdentity;
using fileformat::OriginalProblem;
using fileformat::PackOpenProblem;
using fileformat::PackStructureProblem;
using fileformat::PackWriteEntry;

// Where the container decision puts the fields this test changes. The test
// states them itself and does not share them with the reader or the writer.
namespace at
{
constexpr std::size_t envelopeVersion = 8;
constexpr std::size_t catalogueVersion = 12;
constexpr std::size_t nativeDataContract = 16;
constexpr std::size_t buildTarget = 20;
constexpr std::size_t fileBytes = 64;
constexpr std::size_t directoryBytes = 72;
constexpr std::size_t entryCount = 80;
constexpr std::size_t crc32 = 84;
constexpr std::size_t directory = 88;
constexpr std::size_t recordBytes = 24;
constexpr std::size_t recordOffset = 8;
constexpr std::size_t recordSize = 16;
} // namespace at

constexpr std::array<std::uint16_t, 4> someVersion{1, 4, 0, 525};

// Digests are made up: nothing here is the digest of a real file.
std::array<std::byte, 32> Digest(std::uint8_t seed)
{
    std::array<std::byte, 32> digest{};
    for (std::size_t i = 0; i < digest.size(); ++i)
        digest[i] = static_cast<std::byte>(seed + 7 * i);
    return digest;
}

const std::array<OriginalIdentity, 1> supported{{{someVersion, Digest(1)}}};

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

const std::array<PackWriteEntry, 3> threeEntries{
    Entry("AAAA", 1, "a"),
    Entry("BBBB", 2, "bb"),
    Entry("CCCC", 3, "ccc"),
};

std::vector<std::byte> ThreeEntryPack(const std::array<std::byte, 32>& sha = Digest(1))
{
    return fileformat::WritePackStructure(someVersion, sha, threeEntries);
}

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

std::size_t Record(std::size_t index, std::size_t field)
{
    return at::directory + index * at::recordBytes + field;
}

// A folder of the test's own under the temporary folder, removed with what
// it holds when the test ends.
class Folder
{
  public:
    Folder()
    {
        std::random_device random;
        for (;;)
        {
            path = fs::temp_directory_path() / std::format("vegas-pack-open-{:08x}{:08x}", random(), random());
            if (fs::create_directory(path))
                return;
        }
    }
    Folder(const Folder&) = delete;
    Folder& operator=(const Folder&) = delete;
    ~Folder()
    {
        std::error_code ignored;
        fs::permissions(path / "unreadable.pack", fs::perms::owner_all, ignored);
        fs::remove_all(path, ignored);
    }

    fs::path Write(std::string_view name, std::span<const std::byte> bytes) const
    {
        const fs::path file = path / name;
        std::ofstream out(file, std::ios::binary | std::ios::trunc);
        out.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
        out.close();
        if (!out)
            throw std::runtime_error("the test could not write its pack");
        return file;
    }

    fs::path path;
};

void Opens(Checks& check, std::string_view name, const Folder& folder, std::span<const PackWriteEntry> entries)
{
    const fs::path file =
        folder.Write(std::format("{}.pack", name), fileformat::WritePackStructure(someVersion, Digest(1), entries));
    const OriginalCheckedPack pack = fileformat::OpenPack(file, supported);
    check.Equal(std::format("{}: original version", name), true, pack.Original().version == someVersion);
    check.Equal(std::format("{}: original SHA-256", name), true, pack.Original().sha256 == Digest(1));
    check.Equal(std::format("{}: entry count", name), entries.size(), pack.Entries().size());
    if (pack.Entries().size() != entries.size())
        return;
    for (std::size_t i = 0; i < entries.size(); ++i)
    {
        check.Equal(std::format("{}: key {}", name, i), true, entries[i].key == pack.Entries()[i].key);
        check.Equal(std::format("{}: version {}", name, i), entries[i].version, pack.Entries()[i].version);
        check.Equal(std::format("{}: payload {}", name, i), true,
                    std::ranges::equal(entries[i].payload, pack.EntryBytes(i)));
    }
}

// Expects OpenPack to throw `Error` with the problem given.
template <typename Error, typename Problem>
void Refuses(Checks& check, std::string_view name, const fs::path& file, Problem expected,
             std::span<const OriginalIdentity> identities = supported)
{
    try
    {
        fileformat::OpenPack(file, identities);
        check.Fail(name, "was opened");
    }
    catch (const Error& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was refused for another reason: {}", error.what()));
    }
    catch (const std::exception& error)
    {
        check.Fail(name, std::format("was refused with another kind of error: {}", error.what()));
    }
}

void OpensAValidPack(Checks& check)
{
    const Folder folder;
    Opens(check, "three entries", folder, threeEntries);

    // Files of one read chunk, 1 MiB, exactly, one byte more and more than
    // two: the reader reads to the end in chunks.
    for (const std::size_t total : {std::size_t{1} << 20, (std::size_t{1} << 20) + 1, (std::size_t{2} << 20) + 7})
    {
        const std::string payload(total - at::directory - at::recordBytes, 'p');
        const std::array<PackWriteEntry, 1> one{Entry("DATA", 1, payload)};
        Opens(check, std::format("file of {} bytes", total), folder, one);
    }
}

// The pack is read from its own file only; a pack beside no executable at
// all opens the same way.
void OpensAPackAlone(Checks& check)
{
    const Folder folder;
    const fs::path file = folder.Write("vegas-data.pack", ThreeEntryPack());
    std::size_t others = 0;
    for (const fs::directory_entry& entry : fs::directory_iterator(folder.path))
        others += entry.path() != file ? 1 : 0;
    check.Equal("files beside the pack", std::size_t{0}, others);
    const OriginalCheckedPack pack = fileformat::OpenPack(file, supported);
    check.Equal("entries of a pack alone", threeEntries.size(), pack.Entries().size());
}

void RefusesAMissingFile(Checks& check)
{
    const Folder folder;
    Refuses<fileformat::PackOpenError>(check, "no file", folder.path / "vegas-data.pack", PackOpenProblem::Missing);
    Refuses<fileformat::PackOpenError>(check, "no folder", folder.path / "absent" / "vegas-data.pack",
                                       PackOpenProblem::Missing);
}

void RefusesAnUnreadableFile(Checks& check)
{
    const Folder folder;
    fs::create_directory(folder.path / "folder.pack");
    Refuses<fileformat::PackOpenError>(check, "a folder", folder.path / "folder.pack", PackOpenProblem::Unreadable);

    // A file its owner may not read. Where permissions do not stop the test
    // reading it, as on Windows or for an administrator, the case is skipped
    // and says so.
    const fs::path file = folder.Write("unreadable.pack", ThreeEntryPack());
    fs::permissions(file, fs::perms::none);
    if (std::ifstream(file, std::ios::binary).is_open())
    {
        std::printf("data pack open: a file without read permission: not run, permissions do not stop reading\n");
        return;
    }
    Refuses<fileformat::PackOpenError>(check, "no read permission", file, PackOpenProblem::Unreadable);
}

// Each problem of the container, one change at a time, through the file.
void RefusesACorruptContainer(Checks& check)
{
    const Folder folder;
    const std::vector<std::byte> valid = ThreeEntryPack();
    const auto refuses = [&](std::string_view name, PackStructureProblem expected,
                             const std::function<void(std::vector<std::byte>&)>& change) {
        std::vector<std::byte> bytes = valid;
        change(bytes);
        Refuses<fileformat::PackStructureError>(check, name, folder.Write(std::format("{}.pack", name), bytes),
                                                expected);
    };

    refuses("empty", PackStructureProblem::HeaderTruncated, [](auto& b) { b.clear(); });
    refuses("header short", PackStructureProblem::HeaderTruncated, [](auto& b) { b.resize(87); });
    refuses("magic", PackStructureProblem::Magic, [](auto& b) { b[7] = std::byte{1}; Reseal(b); });
    refuses("envelope version 2", PackStructureProblem::EnvelopeVersion,
            [](auto& b) { Put(b, at::envelopeVersion, 2, 4); Reseal(b); });
    refuses("catalogue version 2", PackStructureProblem::CatalogueVersion,
            [](auto& b) { Put(b, at::catalogueVersion, 2, 4); Reseal(b); });
    refuses("native data contract 0", PackStructureProblem::NativeDataContract,
            [](auto& b) { Put(b, at::nativeDataContract, 0, 4); Reseal(b); });
    refuses("build target 2", PackStructureProblem::BuildTarget,
            [](auto& b) { Put(b, at::buildTarget, 2, 4); Reseal(b); });
    refuses("one byte appended", PackStructureProblem::FileBytes,
            [](auto& b) { b.push_back(std::byte{0}); Reseal(b); });
    refuses("directory past the end", PackStructureProblem::DirectoryBytes,
            [](auto& b) { Put(b, at::directoryBytes, b.size() - at::directory + 1, 8); Reseal(b); });
    refuses("entry count 4", PackStructureProblem::EntryCount,
            [](auto& b) { Put(b, at::entryCount, 4, 4); Reseal(b); });
    refuses("no entries", PackStructureProblem::NoEntries, [](auto& b) {
        b.resize(at::directory);
        Put(b, at::fileBytes, b.size(), 8);
        Put(b, at::directoryBytes, 0, 8);
        Put(b, at::entryCount, 0, 4);
        Reseal(b);
    });
    refuses("payload byte changed", PackStructureProblem::Checksum, [](auto& b) { b.back() ^= std::byte{1}; });
    refuses("keys swapped", PackStructureProblem::KeyOrder, [](auto& b) {
        std::swap_ranges(b.begin() + Record(0, 0), b.begin() + Record(0, 4), b.begin() + Record(1, 0));
        Reseal(b);
    });
    refuses("payload past the end", PackStructureProblem::PayloadOutOfBounds,
            [](auto& b) { Put(b, Record(0, at::recordOffset), b.size() + 1, 8); Reseal(b); });
    refuses("payload size past the end", PackStructureProblem::PayloadOutOfBounds,
            [](auto& b) { Put(b, Record(2, at::recordSize), 4, 8); Reseal(b); });
    refuses("payload a byte late", PackStructureProblem::PayloadPlacement,
            [](auto& b) { Put(b, Record(0, at::recordOffset), Record(3, 0) + 1, 8); Reseal(b); });
    refuses("empty payload", PackStructureProblem::EmptyPayload,
            [](auto& b) { Put(b, Record(0, at::recordSize), 0, 8); Reseal(b); });
    refuses("last payload short", PackStructureProblem::TrailingBytes,
            [](auto& b) { Put(b, Record(2, at::recordSize), 2, 8); Reseal(b); });
}

void RefusesAnUnsupportedOriginal(Checks& check)
{
    const Folder folder;
    const fs::path file = folder.Write("vegas-data.pack", ThreeEntryPack());
    Refuses<fileformat::UnsupportedOriginalError>(check, "no supported identity", file, OriginalProblem::Version,
                                                  std::span<const OriginalIdentity>());
    const std::array<OriginalIdentity, 1> otherVersion{{{{1, 4, 0, 524}, Digest(1)}}};
    Refuses<fileformat::UnsupportedOriginalError>(check, "another version", file, OriginalProblem::Version,
                                                  otherVersion);
    const std::array<OriginalIdentity, 1> otherDigest{{{someVersion, Digest(2)}}};
    Refuses<fileformat::UnsupportedOriginalError>(check, "another digest", file, OriginalProblem::Digest,
                                                  otherDigest);
}

} // namespace

int main()
{
    Checks check("data pack open");
    check.Run("valid pack", [&] { OpensAValidPack(check); });
    check.Run("pack alone", [&] { OpensAPackAlone(check); });
    check.Run("missing file", [&] { RefusesAMissingFile(check); });
    check.Run("unreadable file", [&] { RefusesAnUnreadableFile(check); });
    check.Run("corrupt container", [&] { RefusesACorruptContainer(check); });
    check.Run("unsupported original", [&] { RefusesAnUnsupportedOriginal(check); });
    return check.ExitCode();
}
