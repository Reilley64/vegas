#include "check.h"
#include "fileformat/byte_writer.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_structure.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <format>
#include <initializer_list>
#include <span>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

using fileformat::PackStructureProblem;

constexpr std::size_t headerBytes = 88;
constexpr std::size_t recordBytes = 24;
constexpr std::uint64_t maxU64 = ~std::uint64_t{0};

// EntryBytes points into the pack, so only a pack that outlives the call
// offers it.
template <typename Pack>
concept OffersEntryBytes = requires(Pack&& pack, const fileformat::PackEntry& entry) {
    std::forward<Pack>(pack).EntryBytes(entry);
};
static_assert(OffersEntryBytes<fileformat::PackStructure&>);
static_assert(OffersEntryBytes<const fileformat::PackStructure&>);
static_assert(!OffersEntryBytes<fileformat::PackStructure>);
static_assert(!OffersEntryBytes<const fileformat::PackStructure>);

// Where the fields are, by the container decision. The test states them
// itself and does not share them with the reader.
namespace at
{
constexpr std::size_t magic = 0;
constexpr std::size_t envelopeVersion = 8;
constexpr std::size_t catalogueVersion = 12;
constexpr std::size_t nativeDataContract = 16;
constexpr std::size_t buildTarget = 20;
constexpr std::size_t fileBytes = 64;
constexpr std::size_t directoryBytes = 72;
constexpr std::size_t entryCount = 80;
constexpr std::size_t crc32 = 84;
constexpr std::size_t recordKey = 0;
constexpr std::size_t recordOffset = 8;
constexpr std::size_t recordSize = 16;
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

void Put(std::vector<std::byte>& pack, std::size_t offset, std::uint64_t value, std::size_t width)
{
    for (std::size_t i = 0; i < width; ++i)
        pack[offset + i] = static_cast<std::byte>(value >> (8 * i));
}

void Put32(std::vector<std::byte>& pack, std::size_t offset, std::uint32_t value)
{
    Put(pack, offset, value, 4);
}

void Put64(std::vector<std::byte>& pack, std::size_t offset, std::uint64_t value)
{
    Put(pack, offset, value, 8);
}

// Stores the CRC-32 of the pack as it is now.
void Seal(std::vector<std::byte>& pack)
{
    const std::span<const std::byte> bytes = pack;
    Put32(pack, at::crc32, Crc32(Crc32(0, bytes.first(at::crc32)), bytes.subspan(headerBytes)));
}

struct Entry
{
    std::string_view key;
    std::uint32_t version;
    std::string_view payload;
};

// A well-formed pack of these entries, in the order given.
std::vector<std::byte> Pack(std::initializer_list<Entry> entries)
{
    std::size_t payloadBytes = 0;
    for (const Entry& entry : entries)
        payloadBytes += entry.payload.size();
    const std::size_t directoryBytes = recordBytes * entries.size();

    fileformat::ByteWriter pack;
    pack.ZString("VEGASPK");
    pack.U32(1); // envelope version
    pack.U32(fileformat::packCatalogueVersion); // catalogue version, the source catalogue's
    pack.U32(1); // native data contract
    pack.U32(1); // build target
    for (std::uint16_t part : std::initializer_list<std::uint16_t>{1, 4, 0, 525})
        pack.U16(part);
    for (int i = 0; i < 32; ++i)
        pack.Append(std::array{static_cast<std::byte>(0xA0 + i)}); // original SHA-256
    pack.U64(headerBytes + directoryBytes + payloadBytes);
    pack.U64(directoryBytes);
    pack.U32(static_cast<std::uint32_t>(entries.size()));
    pack.U32(0); // CRC-32, stored by Seal
    std::size_t offset = headerBytes + directoryBytes;
    for (const Entry& entry : entries)
    {
        pack.Text(entry.key);
        pack.U32(entry.version);
        pack.U64(offset);
        pack.U64(entry.payload.size());
        offset += entry.payload.size();
    }
    for (const Entry& entry : entries)
        pack.Text(entry.payload);
    std::vector<std::byte> bytes = pack.Take();
    Seal(bytes);
    return bytes;
}

std::vector<std::byte> TwoEntryPack()
{
    return Pack({{"AAAA", 1, "abc"}, {"BBBB", 1, "defgh"}});
}

std::size_t Record(std::size_t index, std::size_t field)
{
    return headerBytes + recordBytes * index + field;
}

void Rejects(Checks& check, std::string_view name, std::vector<std::byte> pack, PackStructureProblem expected)
{
    try
    {
        fileformat::ParsePackStructure(std::move(pack));
        check.Fail(name, "was accepted");
    }
    catch (const fileformat::PackStructureError& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was rejected for another reason: {}", error.what()));
    }
}

void CheckText(Checks& check, std::string_view field, std::string_view expected, std::span<const std::byte> actual)
{
    check.Equal(field, expected, std::string_view(reinterpret_cast<const char*>(actual.data()), actual.size()));
}

void TheTestChecksumIsCrc32(Checks& check)
{
    const std::string_view digits = "123456789";
    check.Equal("CRC-32 of 123456789", std::uint32_t{0xCBF43926},
                Crc32(0, std::as_bytes(std::span(digits.data(), digits.size()))));
}

void ReadsAMinimalPack(Checks& check)
{
    const std::vector<std::byte> bytes = Pack({{"ONE1", 7, "x"}});
    check.Equal("file size", headerBytes + recordBytes + 1, bytes.size());

    const fileformat::PackStructure pack = fileformat::ParsePackStructure(bytes);
    check.Equal("original version", std::array<std::uint16_t, 4>{1, 4, 0, 525} == pack.originalVersion, true);
    for (std::size_t i = 0; i < pack.originalSha256.size(); ++i)
        check.Equal("original SHA-256", static_cast<unsigned>(0xA0 + i), static_cast<unsigned>(pack.originalSha256[i]));
    check.Equal("owned bytes", true, bytes == pack.bytes);
    check.Equal("entry count", std::size_t{1}, pack.entries.size());
    check.Equal("entry key", std::string_view("ONE1"), std::string_view(pack.entries[0].key.data(), 4));
    check.Equal("entry version", std::uint32_t{7}, pack.entries[0].version);
    check.Equal("payload offset", headerBytes + recordBytes, pack.entries[0].offset);
    check.Equal("payload bytes", std::size_t{1}, pack.entries[0].size);
    CheckText(check, "payload", "x", pack.EntryBytes(pack.entries[0]));
}

void ReadsEntriesInDirectoryOrder(Checks& check)
{
    // Keys compare as unsigned bytes: 0xE9 sorts after every ASCII letter.
    fileformat::PackStructure parsed =
        fileformat::ParsePackStructure(Pack({{"AAAA", 1, "abc"}, {"AAAB", 2, "defgh"}, {"\xE9\x01\x01\x01", 3, "i"}}));
    // The result holds offsets, so it still reads its payloads after a move.
    const fileformat::PackStructure pack = std::move(parsed);
    check.Equal("entry count", std::size_t{3}, pack.entries.size());
    if (pack.entries.size() != 3)
        return;
    check.Equal("second entry version", std::uint32_t{2}, pack.entries[1].version);
    CheckText(check, "first payload", "abc", pack.EntryBytes(pack.entries[0]));
    CheckText(check, "second payload", "defgh", pack.EntryBytes(pack.entries[1]));
    CheckText(check, "third payload", "i", pack.EntryBytes(pack.entries[2]));
}

// The structural stage passes these on unchecked.
void LeavesIdentityAndEntryVersionsUnchecked(Checks& check)
{
    std::vector<std::byte> bytes = Pack({{"\x01\x02\x03\x04", 0xFFFFFFFF, "x"}});
    Put(bytes, 24, 0xFFFF000200030009, 8);
    Seal(bytes);
    const fileformat::PackStructure pack = fileformat::ParsePackStructure(std::move(bytes));
    check.Equal("original version", std::array<std::uint16_t, 4>{9, 3, 2, 0xFFFF} == pack.originalVersion, true);
    check.Equal("entry version", std::uint32_t{0xFFFFFFFF}, pack.entries[0].version);
}

void RejectsATruncatedHeader(Checks& check)
{
    Rejects(check, "no bytes", {}, PackStructureProblem::HeaderTruncated);
    std::vector<std::byte> pack = TwoEntryPack();
    pack.resize(headerBytes - 1);
    Rejects(check, "87 bytes", pack, PackStructureProblem::HeaderTruncated);
}

void RejectsAWrongMagic(Checks& check)
{
    for (std::size_t i = 0; i < 8; ++i)
    {
        std::vector<std::byte> pack = TwoEntryPack();
        pack[at::magic + i] ^= std::byte{0x20};
        Seal(pack);
        Rejects(check, std::format("magic byte {}", i), pack, PackStructureProblem::Magic);
    }
}

void RejectsUnsupportedRevisions(Checks& check)
{
    const std::pair<std::size_t, PackStructureProblem> fields[] = {
        {at::envelopeVersion, PackStructureProblem::EnvelopeVersion},
        {at::nativeDataContract, PackStructureProblem::NativeDataContract},
        {at::buildTarget, PackStructureProblem::BuildTarget},
    };
    for (const auto& [offset, problem] : fields)
    {
        for (std::uint32_t value : {0u, 2u, 0x100u, 0x01000000u, 0xFFFFFFFFu})
        {
            std::vector<std::byte> pack = TwoEntryPack();
            Put32(pack, offset, value);
            Seal(pack);
            Rejects(check, std::format("field at {} is {}", offset, value), pack, problem);
        }
    }
}

// The catalogue version is the source catalogue's, whatever its value: the
// versions next to it and values that differ from it in a higher byte only
// are refused.
void RejectsAnotherCatalogueVersion(Checks& check)
{
    constexpr std::uint32_t version = fileformat::packCatalogueVersion;
    for (std::uint32_t value : {0u, version - 1, version + 1, version + 0x100u, version + 0x01000000u, 0xFFFFFFFFu})
    {
        if (value == version)
            continue;
        std::vector<std::byte> pack = TwoEntryPack();
        Put32(pack, at::catalogueVersion, value);
        Seal(pack);
        Rejects(check, std::format("catalogue version {}", value), pack, PackStructureProblem::CatalogueVersion);
    }
}

void RejectsAWrongFileSize(Checks& check)
{
    const std::vector<std::byte> valid = TwoEntryPack();
    const std::uint64_t size = valid.size();
    for (std::uint64_t value : std::initializer_list<std::uint64_t>{0, size - 1, size + 1, size + (1ull << 32), maxU64})
    {
        std::vector<std::byte> pack = valid;
        Put64(pack, at::fileBytes, value);
        Seal(pack);
        Rejects(check, std::format("file bytes {}", value), pack, PackStructureProblem::FileBytes);
    }

    std::vector<std::byte> shorter = valid;
    shorter.pop_back();
    Seal(shorter);
    Rejects(check, "file one byte short", shorter, PackStructureProblem::FileBytes);

    std::vector<std::byte> longer = valid;
    longer.push_back(std::byte{0});
    Seal(longer);
    Rejects(check, "one byte after the file", longer, PackStructureProblem::FileBytes);
}

void RejectsADirectoryThatDoesNotFit(Checks& check)
{
    const std::vector<std::byte> valid = TwoEntryPack();
    const std::uint64_t size = valid.size();
    for (std::uint64_t value : std::initializer_list<std::uint64_t>{size - headerBytes + 1, size, maxU64 - 87, maxU64})
    {
        std::vector<std::byte> pack = valid;
        Put64(pack, at::directoryBytes, value);
        Seal(pack);
        Rejects(check, std::format("directory bytes {}", value), pack, PackStructureProblem::DirectoryBytes);
    }

    // A header alone, whose directory would start at the end of the file.
    std::vector<std::byte> headerOnly = valid;
    headerOnly.resize(headerBytes);
    Put64(headerOnly, at::fileBytes, headerBytes);
    Seal(headerOnly);
    Rejects(check, "header only", headerOnly, PackStructureProblem::DirectoryBytes);
}

void RejectsAWrongEntryCount(Checks& check)
{
    const std::vector<std::byte> valid = TwoEntryPack();
    // 0x20000002 * 24 is 48 in 32 bits.
    for (std::uint32_t count : {0u, 1u, 3u, 0x20000001u, 0x20000002u, 0xFFFFFFFFu})
    {
        std::vector<std::byte> pack = valid;
        Put32(pack, at::entryCount, count);
        Seal(pack);
        Rejects(check, std::format("entry count {}", count), pack, PackStructureProblem::EntryCount);
    }
    // Directory sizes that fit in the file and are not two whole records.
    for (std::uint64_t size : std::initializer_list<std::uint64_t>{0, 1, 23, 24, 25, 47, 49})
    {
        std::vector<std::byte> pack = valid;
        Put64(pack, at::directoryBytes, size);
        Seal(pack);
        Rejects(check, std::format("directory bytes {}", size), pack, PackStructureProblem::EntryCount);
    }
}

void RejectsAnEmptyDirectory(Checks& check)
{
    std::vector<std::byte> pack = TwoEntryPack();
    Put64(pack, at::directoryBytes, 0);
    Put32(pack, at::entryCount, 0);
    Seal(pack);
    Rejects(check, "no entries, payload bytes kept", pack, PackStructureProblem::NoEntries);

    pack.resize(headerBytes);
    Put64(pack, at::fileBytes, headerBytes);
    Seal(pack);
    Rejects(check, "no entries, header only", pack, PackStructureProblem::NoEntries);
}

void RejectsAWrongChecksum(Checks& check)
{
    const std::vector<std::byte> valid = TwoEntryPack();

    std::vector<std::byte> stored = valid;
    stored[at::crc32] ^= std::byte{1};
    Rejects(check, "stored CRC-32 changed", stored, PackStructureProblem::Checksum);

    std::vector<std::byte> payload = valid;
    payload.back() ^= std::byte{1};
    Rejects(check, "payload changed", payload, PackStructureProblem::Checksum);

    std::vector<std::byte> identity = valid;
    identity[40] ^= std::byte{0x80};
    Rejects(check, "original SHA-256 changed", identity, PackStructureProblem::Checksum);

    // The stored bytes are left out of the sum, not summed as zeros.
    std::vector<std::byte> zeros = valid;
    Put32(zeros, at::crc32, 0);
    const std::uint32_t overZeros = Crc32(0, zeros);
    Put32(zeros, at::crc32, overZeros);
    Rejects(check, "CRC-32 over zeros in its place", zeros, PackStructureProblem::Checksum);

    std::vector<std::byte> headerSum = valid;
    Put32(headerSum, at::crc32, Crc32(0, std::span<const std::byte>(valid).first(at::crc32)));
    Rejects(check, "CRC-32 of the header only", headerSum, PackStructureProblem::Checksum);
}

void RejectsKeysOutOfOrder(Checks& check)
{
    Rejects(check, "equal keys", Pack({{"AAAA", 1, "abc"}, {"AAAA", 1, "defgh"}}), PackStructureProblem::KeyOrder);
    Rejects(check, "descending keys", Pack({{"BBBB", 1, "abc"}, {"AAAA", 1, "defgh"}}), PackStructureProblem::KeyOrder);
    Rejects(check, "third key equals first", Pack({{"AAAA", 1, "a"}, {"BBBB", 1, "b"}, {"AAAA", 1, "c"}}),
            PackStructureProblem::KeyOrder);
    // Greater than the first key is not enough: each key is compared with
    // the one before it.
    Rejects(check, "third key between the first and the second",
            Pack({{"AAAA", 1, "a"}, {"CCCC", 1, "b"}, {"BBBB", 1, "c"}}), PackStructureProblem::KeyOrder);
    // As signed bytes 0xE9 would sort first; as bytes it sorts last.
    Rejects(check, "high byte before a letter", Pack({{"\xE9\x01\x01\x01", 1, "a"}, {"AAAA", 1, "b"}}),
            PackStructureProblem::KeyOrder);
}

void RejectsPayloadsOutsideTheFile(Checks& check)
{
    const std::vector<std::byte> valid = TwoEntryPack();
    const std::uint64_t size = valid.size();
    const std::uint64_t first = headerBytes + 2 * recordBytes;
    struct Case
    {
        std::string_view name;
        std::size_t record;
        std::uint64_t offset;
        std::uint64_t bytes;
    };
    const Case cases[] = {
        {"offset after the file", 0, size + 1, 3},
        {"offset 2^64-1, whose end wraps to 2", 0, maxU64, 3},
        {"size 2^64-1, whose end wraps", 0, first, maxU64},
        {"second offset and size wrap to the end of the file", 1, maxU64 - 1, size + 2},
        {"offset 2^32 more", 0, first + (1ull << 32), 3},
        {"one byte past the file", 1, first + 3, 6},
        {"at the end of the file with one byte", 1, size, 1},
    };
    for (const Case& c : cases)
    {
        std::vector<std::byte> pack = valid;
        Put64(pack, Record(c.record, at::recordOffset), c.offset);
        Put64(pack, Record(c.record, at::recordSize), c.bytes);
        Seal(pack);
        Rejects(check, c.name, pack, PackStructureProblem::PayloadOutOfBounds);
    }

    // Only the size bound refuses this pack. The first payload starts where
    // the directory ends and its end wraps to 0, where the second payload
    // starts and spans the whole file, so every other check holds.
    std::vector<std::byte> wrapped = valid;
    Put64(wrapped, Record(0, at::recordSize), maxU64 - first + 1);
    Put64(wrapped, Record(1, at::recordOffset), 0);
    Put64(wrapped, Record(1, at::recordSize), size);
    Seal(wrapped);
    Rejects(check, "first size 2^64-136 wraps to a second payload over the whole file", wrapped,
            PackStructureProblem::PayloadOutOfBounds);
}

void RejectsPayloadsOutOfPlace(Checks& check)
{
    const std::vector<std::byte> valid = TwoEntryPack();
    const std::uint64_t first = headerBytes + 2 * recordBytes;
    struct Case
    {
        std::string_view name;
        std::size_t record;
        std::uint64_t offset;
        std::uint64_t bytes;
    };
    const Case cases[] = {
        {"first payload leaves a hole after the directory", 0, first + 1, 2},
        {"first payload over the directory", 0, headerBytes, 2 * recordBytes + 3},
        {"first payload over the header", 0, 0, first + 3},
        {"second payload over the first", 1, first, 8},
        {"second payload overlaps the first's last byte", 1, first + 2, 6},
        {"second payload leaves a hole", 1, first + 4, 4},
        {"second payload at the end of the file with no bytes", 1, first + 8, 0},
    };
    for (const Case& c : cases)
    {
        std::vector<std::byte> pack = valid;
        Put64(pack, Record(c.record, at::recordOffset), c.offset);
        Put64(pack, Record(c.record, at::recordSize), c.bytes);
        Seal(pack);
        Rejects(check, c.name, pack, PackStructureProblem::PayloadPlacement);
    }

    // Payloads stored in the other order than the directory.
    std::vector<std::byte> swapped = valid;
    Put64(swapped, Record(0, at::recordOffset), first + 5);
    Put64(swapped, Record(1, at::recordOffset), first);
    Seal(swapped);
    Rejects(check, "payloads in reverse order", swapped, PackStructureProblem::PayloadPlacement);
}

void RejectsAnEmptyPayload(Checks& check)
{
    Rejects(check, "first payload empty", Pack({{"AAAA", 1, ""}, {"BBBB", 1, "defgh"}}),
            PackStructureProblem::EmptyPayload);
    Rejects(check, "last payload empty", Pack({{"AAAA", 1, "abc"}, {"BBBB", 1, ""}}),
            PackStructureProblem::EmptyPayload);
    Rejects(check, "only payload empty", Pack({{"AAAA", 1, ""}}), PackStructureProblem::EmptyPayload);
}

void RejectsBytesAfterTheLastPayload(Checks& check)
{
    std::vector<std::byte> pack = TwoEntryPack();
    Put64(pack, Record(1, at::recordSize), 4);
    Seal(pack);
    Rejects(check, "last payload one byte short", pack, PackStructureProblem::TrailingBytes);

    std::vector<std::byte> longer = TwoEntryPack();
    longer.push_back(std::byte{0});
    Put64(longer, at::fileBytes, longer.size());
    Seal(longer);
    Rejects(check, "one byte after the last payload", longer, PackStructureProblem::TrailingBytes);
}

// A file with several problems reports the one checked first.
void ReportsTheFirstProblem(Checks& check)
{
    std::vector<std::byte> pack = TwoEntryPack();
    Put32(pack, Record(1, at::recordKey), 0);
    Rejects(check, "unsealed key change", pack, PackStructureProblem::Checksum);
    Put32(pack, at::buildTarget, 2);
    Rejects(check, "and a wrong build target", pack, PackStructureProblem::BuildTarget);
    Put32(pack, at::envelopeVersion, 2);
    Rejects(check, "and a wrong envelope version", pack, PackStructureProblem::EnvelopeVersion);
    pack[at::magic] = std::byte{0};
    Rejects(check, "and a wrong magic", pack, PackStructureProblem::Magic);
}

// Whatever the cut or the damage, the reader throws its own error: it reads
// nothing outside the bytes, which the sanitizer build of this test watches.
void RejectsEveryPrefixAndEveryChangedByte(Checks& check)
{
    const std::vector<std::byte> valid = Pack({{"AAAA", 1, "abc"}, {"BBBB", 1, "defgh"}, {"CCCC", 1, "i"}});
    for (std::size_t size = 0; size < valid.size(); ++size)
    {
        std::vector<std::byte> prefix(valid.begin(), valid.begin() + static_cast<std::ptrdiff_t>(size));
        Rejects(check, std::format("first {} bytes", size), prefix,
                size < headerBytes ? PackStructureProblem::HeaderTruncated : PackStructureProblem::FileBytes);

        // The same cut with the size and the checksum made to agree with it.
        if (size >= headerBytes)
        {
            Put64(prefix, at::fileBytes, size);
            Seal(prefix);
            try
            {
                fileformat::ParsePackStructure(std::move(prefix));
                check.Fail(std::format("first {} bytes, resealed", size), "was accepted");
            }
            catch (const fileformat::PackStructureError&)
            {
            }
        }
    }
    for (std::size_t i = 0; i < valid.size(); ++i)
    {
        for (int bit = 0; bit < 8; ++bit)
        {
            std::vector<std::byte> changed = valid;
            changed[i] ^= static_cast<std::byte>(1 << bit);
            try
            {
                fileformat::ParsePackStructure(std::move(changed));
                check.Fail(std::format("bit {} of byte {} changed", bit, i), "was accepted");
            }
            catch (const fileformat::PackStructureError&)
            {
            }
        }
    }
}

} // namespace

int main()
{
    Checks check("data pack structure");
    check.Run("test checksum", [&] { TheTestChecksumIsCrc32(check); });
    check.Run("minimal pack", [&] { ReadsAMinimalPack(check); });
    check.Run("entries in directory order", [&] { ReadsEntriesInDirectoryOrder(check); });
    check.Run("unchecked fields", [&] { LeavesIdentityAndEntryVersionsUnchecked(check); });
    check.Run("truncated header", [&] { RejectsATruncatedHeader(check); });
    check.Run("wrong magic", [&] { RejectsAWrongMagic(check); });
    check.Run("unsupported revisions", [&] { RejectsUnsupportedRevisions(check); });
    check.Run("another catalogue version", [&] { RejectsAnotherCatalogueVersion(check); });
    check.Run("wrong file size", [&] { RejectsAWrongFileSize(check); });
    check.Run("directory that does not fit", [&] { RejectsADirectoryThatDoesNotFit(check); });
    check.Run("wrong entry count", [&] { RejectsAWrongEntryCount(check); });
    check.Run("empty directory", [&] { RejectsAnEmptyDirectory(check); });
    check.Run("wrong checksum", [&] { RejectsAWrongChecksum(check); });
    check.Run("keys out of order", [&] { RejectsKeysOutOfOrder(check); });
    check.Run("payloads outside the file", [&] { RejectsPayloadsOutsideTheFile(check); });
    check.Run("payloads out of place", [&] { RejectsPayloadsOutOfPlace(check); });
    check.Run("empty payload", [&] { RejectsAnEmptyPayload(check); });
    check.Run("bytes after the last payload", [&] { RejectsBytesAfterTheLastPayload(check); });
    check.Run("first problem", [&] { ReportsTheFirstProblem(check); });
    check.Run("every prefix and changed byte", [&] { RejectsEveryPrefixAndEveryChangedByte(check); });
    return check.ExitCode();
}
