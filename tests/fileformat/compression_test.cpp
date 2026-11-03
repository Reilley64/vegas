#include "check.h"
#include "fileformat/byte_reader.h"
#include "fileformat/compression.h"
#include "fileformat/fixture.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <span>
#include <string_view>
#include <vector>

namespace
{

// The data of a compressed record: the size of the data once inflated, then
// the zlib stream of an EDID and a FULL subrecord.
Fixture CompressedRecordFixture()
{
    Fixture f;
    f.Bytes("decompressed size", {0x1F, 0x00, 0x00, 0x00});
    f.Bytes("zlib header", {0x78, 0x9C});
    f.Bytes("deflate data", {0x73, 0x75, 0xF1, 0x74, 0xE1, 0x64, 0x08, 0x49, 0x2D, 0x2E, 0x71, 0xCA,
                               0xCF, 0xCF, 0x66, 0x70, 0x0B, 0xF5, 0xF1, 0xE1, 0x02, 0x73, 0x15, 0xC0,
                               0x7C, 0x00});
    f.Bytes("Adler-32", {0x8A, 0x45, 0x08, 0xD3});
    return f;
}

constexpr std::string_view recordData{"EDID\x09\x00TestBook\x00" "FULL\x0A\x00Test Book\x00", 31};

// A compressed file in a BSA: its size once inflated, then its zlib stream.
Fixture CompressedBsaFileFixture(std::initializer_list<std::uint8_t> adler32)
{
    Fixture f;
    f.Bytes("original size", {0x84, 0x00, 0x00, 0x00});
    f.Bytes("zlib header", {0x78, 0x9C});
    f.Bytes("deflate data", {0xA5, 0xCC, 0xD1, 0x0D, 0x80, 0x30, 0x08, 0x05, 0xC0, 0x55, 0xDE, 0x04,
                               0x6E, 0x62, 0xD2, 0x15, 0x88, 0xA1, 0xB6, 0x4A, 0x21, 0x01, 0xAA, 0x71,
                               0x7B, 0xDD, 0xC1, 0xDF, 0xFB, 0xB8, 0x42, 0xE9, 0x26, 0xD2, 0x75, 0x47,
                               0x36, 0xC6, 0x6A, 0x07, 0x5D, 0x0C, 0x92, 0x61, 0x91, 0x18, 0x74, 0x72,
                               0xE0, 0xB1, 0x89, 0xBB, 0x47, 0x43, 0x35, 0x07, 0x41, 0xE7, 0x26, 0x4C,
                               0xFE, 0x91, 0x26, 0xFB, 0x82, 0xF2, 0x7B, 0x78, 0x01});
    f.Bytes("Adler-32", adler32);
    return f;
}

constexpr std::initializer_list<std::uint8_t> bsaFileAdler32{0xB0, 0x24, 0x30, 0x63};
constexpr std::string_view bsaFileText = "Patrolling the Mojave almost makes you wish for a nuclear winter. "
                                         "Patrolling the Mojave almost makes you wish for a nuclear winter. ";

std::vector<std::byte> Bytes(std::string_view text)
{
    const auto* data = reinterpret_cast<const std::byte*>(text.data());
    return {data, data + text.size()};
}

void CheckEnded(Checks& check, fileformat::InflateStatus status)
{
    if (status != fileformat::InflateStatus::End)
        check.Fail("zlib stream", status == fileformat::InflateStatus::Error ? "is corrupt" : "does not end");
}

void CheckInflated(Checks& check, std::string_view expected, std::span<const std::byte> inflated)
{
    Fixture f;
    f.Text("inflated byte", expected);
    CheckBytes(check, f, inflated);
}

// Inflates the way the compressed-record reader does: the whole stream into a
// buffer of the size the record gives.
void ReadsACompressedRecord(Checks& check)
{
    const Fixture fixture = CompressedRecordFixture();
    fileformat::ByteReader record(fixture.Data(), "compressed record");
    std::vector<std::byte> inflated(record.U32("decompressed size"));
    std::span<const std::byte> input = record.Take(fixture.Data().size() - 4, "zlib stream");
    std::span<std::byte> output = inflated;

    fileformat::Inflater inflater;
    CheckEnded(check, inflater.Inflate(input, output));
    check.Equal("zlib stream bytes left", std::size_t{0}, input.size());
    CheckInflated(check, recordData, inflated);
}

void WritesACompressedRecord(Checks& check)
{
    const Fixture fixture = CompressedRecordFixture();
    std::vector<std::byte> deflated(2 * recordData.size());
    deflated.resize(fileformat::Deflate(Bytes(recordData), deflated));

    Fixture stream;
    for (std::size_t i = 4; i < fixture.Data().size(); ++i)
        stream.Bytes(fixture.FieldAt(i), {static_cast<std::uint8_t>(fixture.Data()[i])});
    CheckBytes(check, stream, deflated);
}

// Inflates the way the BSA reader does: a few input bytes at a time into a
// small output buffer, through the one stream the reader keeps.
std::vector<std::byte> InflateInChunks(Checks& check, fileformat::Inflater& inflater, const Fixture& fixture)
{
    fileformat::ByteReader file(fixture.Data(), "BSA file");
    const std::uint32_t size = file.U32("original size");
    std::span<const std::byte> stream = file.Take(fixture.Data().size() - 4, "zlib stream");

    std::vector<std::byte> inflated;
    fileformat::InflateStatus status = fileformat::InflateStatus::More;
    while (status == fileformat::InflateStatus::More)
    {
        std::span<const std::byte> input = stream.first(std::min<std::size_t>(stream.size(), 5));
        std::byte buffer[16];
        std::span<std::byte> output = buffer;
        status = inflater.Inflate(input, output);

        const std::size_t consumed = std::min<std::size_t>(stream.size(), 5) - input.size();
        const std::size_t produced = sizeof(buffer) - output.size();
        inflated.insert(inflated.end(), buffer, buffer + produced);
        stream = stream.subspan(consumed);
        if (consumed == 0 && produced == 0)
            break;
    }
    CheckEnded(check, status);
    check.Equal("original size", std::size_t{size}, inflated.size());
    return inflated;
}

void ReadsCompressedBsaFiles(Checks& check)
{
    fileformat::Inflater inflater;
    CheckInflated(check, bsaFileText, InflateInChunks(check, inflater, CompressedBsaFileFixture(bsaFileAdler32)));
    inflater.Reset();
    CheckInflated(check, bsaFileText, InflateInChunks(check, inflater, CompressedBsaFileFixture(bsaFileAdler32)));
}

// The original release does not check the Adler-32 trailer.
void ReadsAStreamWithAWrongAdler32(Checks& check)
{
    fileformat::Inflater inflater;
    CheckInflated(check, bsaFileText,
                  InflateInChunks(check, inflater, CompressedBsaFileFixture({0x12, 0x34, 0x56, 0x78})));
}

} // namespace

int main()
{
    Checks check("zlib compression");
    check.Run("compressed record read", [&] { ReadsACompressedRecord(check); });
    check.Run("compressed record write", [&] { WritesACompressedRecord(check); });
    check.Run("compressed BSA files read", [&] { ReadsCompressedBsaFiles(check); });
    check.Run("wrong Adler-32 read", [&] { ReadsAStreamWithAWrongAdler32(check); });
    return check.ExitCode();
}
