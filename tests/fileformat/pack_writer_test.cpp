#include "check.h"
#include "fileformat/pack_structure.h"
#include "fileformat/pack_writer.h"

#include <algorithm>
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

using fileformat::PackWriteEntry;
using fileformat::PackWriteProblem;

// Where the writer must put things, by the container decision. The test
// states them itself and does not share them with the writer or the reader.
constexpr std::size_t headerBytes = 88;
constexpr std::size_t recordBytes = 24;
constexpr std::size_t crc32At = 84;

constexpr std::array<std::uint16_t, 4> someVersion{1, 4, 0, 525};

std::array<std::byte, 32> SomeSha256()
{
    std::array<std::byte, 32> sha{};
    for (std::size_t i = 0; i < sha.size(); ++i)
        sha[i] = static_cast<std::byte>(0xA0 + i);
    return sha;
}

// A minimal pack, byte by byte: one entry, key ONE1, version 7, payload "x".
// 88 header bytes, one 24-byte record and one payload byte.
constexpr std::array<unsigned char, 113> minimalPack{
    'V', 'E', 'G', 'A', 'S', 'P', 'K', 0x00,                // magic
    0x01, 0x00, 0x00, 0x00,                                 // envelope version 1
    0x01, 0x00, 0x00, 0x00,                                 // catalogue version 1
    0x01, 0x00, 0x00, 0x00,                                 // native data contract 1
    0x01, 0x00, 0x00, 0x00,                                 // build target 1
    0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0D, 0x02,         // original version 1.4.0.525
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,         // original SHA-256, as given
    0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,         //
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7,         //
    0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,         //
    0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // file bytes 113
    0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // directory bytes 24
    0x01, 0x00, 0x00, 0x00,                                 // entry count 1
    0xF0, 0x22, 0x68, 0x9B,                                 // CRC-32 of bytes 0 to 83 and 88 to 112
    'O', 'N', 'E', '1',                                     // entry key
    0x07, 0x00, 0x00, 0x00,                                 // entry version 7
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // payload offset 112
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // payload bytes 1
    'x',                                                    // payload
};

std::vector<std::byte> MinimalPackBytes()
{
    std::vector<std::byte> bytes;
    for (unsigned char byte : minimalPack)
        bytes.push_back(static_cast<std::byte>(byte));
    return bytes;
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

std::uint32_t StoredCrc32(std::span<const std::byte> pack)
{
    std::uint32_t value = 0;
    for (std::size_t i = 0; i < 4; ++i)
        value |= static_cast<std::uint32_t>(pack[crc32At + i]) << (8 * i);
    return value;
}

std::uint32_t ExpectedCrc32(std::span<const std::byte> pack)
{
    return Crc32(Crc32(0, pack.first(crc32At)), pack.subspan(headerBytes));
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

std::vector<std::byte> Write(std::initializer_list<PackWriteEntry> entries)
{
    return fileformat::WritePackStructure(someVersion, SomeSha256(), std::span(entries.begin(), entries.size()));
}

// Writes the entries, reads the result back and expects what was written.
void RoundTrips(Checks& check, std::string_view name, const std::array<std::uint16_t, 4>& version,
                const std::array<std::byte, 32>& sha, std::span<const PackWriteEntry> entries)
{
    const std::vector<std::byte> bytes = fileformat::WritePackStructure(version, sha, entries);
    std::size_t payloadBytes = 0;
    for (const PackWriteEntry& entry : entries)
        payloadBytes += entry.payload.size();
    check.Equal(std::format("{}: size", name), headerBytes + recordBytes * entries.size() + payloadBytes,
                bytes.size());
    check.Equal(std::format("{}: CRC-32", name), ExpectedCrc32(bytes), StoredCrc32(bytes));

    const fileformat::PackStructure pack = fileformat::ParsePackStructure(bytes);
    check.Equal(std::format("{}: original version", name), true, version == pack.originalVersion);
    check.Equal(std::format("{}: original SHA-256", name), true, sha == pack.originalSha256);
    check.Equal(std::format("{}: entry count", name), entries.size(), pack.entries.size());
    if (pack.entries.size() != entries.size())
        return;
    for (std::size_t i = 0; i < entries.size(); ++i)
    {
        const std::span<const std::byte> payload = pack.EntryBytes(pack.entries[i]);
        check.Equal(std::format("{}: key {}", name, i), true, entries[i].key == pack.entries[i].key);
        check.Equal(std::format("{}: version {}", name, i), entries[i].version, pack.entries[i].version);
        check.Equal(std::format("{}: payload {}", name, i), true,
                    std::ranges::equal(entries[i].payload, payload));
    }
}

void RoundTrips(Checks& check, std::string_view name, std::initializer_list<PackWriteEntry> entries)
{
    RoundTrips(check, name, someVersion, SomeSha256(), std::span(entries.begin(), entries.size()));
}

void Rejects(Checks& check, std::string_view name, std::initializer_list<PackWriteEntry> entries,
             PackWriteProblem expected)
{
    try
    {
        Write(entries);
        check.Fail(name, "was written");
    }
    catch (const fileformat::PackWriteError& error)
    {
        if (error.Problem() != expected)
            check.Fail(name, std::format("was rejected for another reason: {}", error.what()));
    }
}

void TheTestChecksumIsCrc32(Checks& check)
{
    check.Equal("CRC-32 of 123456789", std::uint32_t{0xCBF43926}, Crc32(0, Bytes("123456789")));
    check.Equal("CRC-32 of the minimal pack", ExpectedCrc32(MinimalPackBytes()), StoredCrc32(MinimalPackBytes()));
}

// The reader accepts the spelled-out pack and the writer reproduces it, so
// the two cannot agree on a layout that is not the decision's.
void WritesTheMinimalPackByteForByte(Checks& check)
{
    const fileformat::PackStructure pack = fileformat::ParsePackStructure(MinimalPackBytes());
    check.Equal("read entry count", std::size_t{1}, pack.entries.size());
    check.Equal("read payload offset", std::size_t{112}, pack.entries[0].offset);

    const std::vector<std::byte> written = Write({Entry("ONE1", 7, "x")});
    check.Equal("written size", minimalPack.size(), written.size());
    for (std::size_t i = 0; i < written.size() && i < minimalPack.size(); ++i)
        check.Equal(std::format("written byte {}", i), static_cast<unsigned>(minimalPack[i]),
                    static_cast<unsigned>(written[i]));
}

void RoundTripsOneEntry(Checks& check)
{
    RoundTrips(check, "one entry", {Entry("ONE1", 7, "x")});
}

void RoundTripsSeveralEntries(Checks& check)
{
    RoundTrips(check, "three entries",
               {Entry("AAAA", 0, "abc"), Entry("AAAB", 0xFFFFFFFF, "defgh"), Entry("ZZZZ", 2, "i")});

    std::array<std::byte, 32> sha{};
    for (std::size_t i = 0; i < sha.size(); ++i)
        sha[i] = static_cast<std::byte>(0xFF - 3 * i);
    const PackWriteEntry entries[] = {Entry("A000", 1, "1"), Entry("A001", 2, "22"), Entry("B000", 3, "333"),
                                      Entry("a000", 4, "4444"), Entry("z999", 5, "55555")};
    RoundTrips(check, "five entries, other identity", {0xFFFF, 0, 0x1234, 1}, sha, entries);
}

// The lowest and highest ASCII bytes are both written.
void RoundTripsTheExtremeKeyBytes(Checks& check)
{
    RoundTrips(check, "lowest and highest key bytes",
               {Entry(std::string_view("\0\0\0\0", 4), 1, "low"), Entry("\x7F\x7F\x7F\x7F", 1, "high")});
    RoundTrips(check, "highest byte in each place",
               {Entry("\x7F" "AAA", 1, "a"), Entry("\x7F\x7F" "AA", 1, "b"), Entry("\x7F\x7F\x7F" "A", 1, "c"),
                Entry("\x7F\x7F\x7F\x7F", 1, "d")});
}

void RoundTripsALargePayload(Checks& check)
{
    std::vector<std::byte> large((std::size_t{1} << 24) + 3);
    for (std::size_t i = 0; i < large.size(); ++i)
        large[i] = static_cast<std::byte>(i * 131 + (i >> 16));
    const PackWriteEntry entries[] = {Entry("AAAA", 1, "a"), PackWriteEntry{{'B', 'I', 'G', '1'}, 9, large},
                                      Entry("ZZZZ", 1, "z")};
    RoundTrips(check, "16 MiB payload between two small ones", someVersion, SomeSha256(), entries);
}

void RejectsNoEntries(Checks& check)
{
    Rejects(check, "no entries", {}, PackWriteProblem::NoEntries);
}

void RejectsKeysThatAreNotAscii(Checks& check)
{
    for (std::size_t place = 0; place < 4; ++place)
    {
        for (int byte : {0x80, 0xE9, 0xFF})
        {
            PackWriteEntry entry = Entry("AAAA", 1, "a");
            entry.key[place] = static_cast<char>(byte);
            Rejects(check, std::format("byte {:#x} at {} of the only key", byte, place), {entry},
                    PackWriteProblem::KeyNotAscii);
            // After a key below it, so only the byte is wrong.
            Rejects(check, std::format("byte {:#x} at {} of the second key", byte, place),
                    {Entry(std::string_view("\0\0\0\0", 4), 1, "a"), entry}, PackWriteProblem::KeyNotAscii);
        }
    }
}

void RejectsKeysOutOfOrder(Checks& check)
{
    Rejects(check, "equal keys", {Entry("AAAA", 1, "a"), Entry("AAAA", 1, "b")}, PackWriteProblem::KeyOrder);
    Rejects(check, "descending keys", {Entry("BBBB", 1, "a"), Entry("AAAA", 1, "b")}, PackWriteProblem::KeyOrder);
    Rejects(check, "last byte descending", {Entry("AAAB", 1, "a"), Entry("AAAA", 1, "b")},
            PackWriteProblem::KeyOrder);
    Rejects(check, "third key equals first", {Entry("AAAA", 1, "a"), Entry("BBBB", 1, "b"), Entry("AAAA", 1, "c")},
            PackWriteProblem::KeyOrder);
    // Greater than the first key is not enough: each key is compared with
    // the one before it.
    Rejects(check, "third key between the first and the second",
            {Entry("AAAA", 1, "a"), Entry("CCCC", 1, "b"), Entry("BBBB", 1, "c")}, PackWriteProblem::KeyOrder);
}

void RejectsAnEmptyPayload(Checks& check)
{
    Rejects(check, "only payload empty", {Entry("AAAA", 1, "")}, PackWriteProblem::EmptyPayload);
    Rejects(check, "first payload empty", {Entry("AAAA", 1, ""), Entry("BBBB", 1, "b")},
            PackWriteProblem::EmptyPayload);
    Rejects(check, "last payload empty", {Entry("AAAA", 1, "a"), Entry("BBBB", 1, "")},
            PackWriteProblem::EmptyPayload);
}

// Entries with several problems report the one checked first.
void ReportsTheFirstProblem(Checks& check)
{
    PackWriteEntry high = Entry("AAAA", 1, "");
    high.key[3] = static_cast<char>(0x80);
    Rejects(check, "key not ASCII before an empty payload", {high}, PackWriteProblem::KeyNotAscii);
    Rejects(check, "key not ASCII before the order", {Entry("BBBB", 1, "b"), high}, PackWriteProblem::KeyNotAscii);
    Rejects(check, "order before an empty payload", {Entry("BBBB", 1, "b"), Entry("AAAA", 1, "")},
            PackWriteProblem::KeyOrder);
    Rejects(check, "earlier entry first", {Entry("AAAA", 1, ""), high}, PackWriteProblem::EmptyPayload);
}

} // namespace

int main()
{
    Checks check("data pack writer");
    check.Run("test checksum", [&] { TheTestChecksumIsCrc32(check); });
    check.Run("minimal pack byte for byte", [&] { WritesTheMinimalPackByteForByte(check); });
    check.Run("one entry", [&] { RoundTripsOneEntry(check); });
    check.Run("several entries", [&] { RoundTripsSeveralEntries(check); });
    check.Run("extreme key bytes", [&] { RoundTripsTheExtremeKeyBytes(check); });
    check.Run("large payload", [&] { RoundTripsALargePayload(check); });
    check.Run("no entries", [&] { RejectsNoEntries(check); });
    check.Run("keys that are not ASCII", [&] { RejectsKeysThatAreNotAscii(check); });
    check.Run("keys out of order", [&] { RejectsKeysOutOfOrder(check); });
    check.Run("empty payload", [&] { RejectsAnEmptyPayload(check); });
    check.Run("first problem", [&] { ReportsTheFirstProblem(check); });
    return check.ExitCode();
}
