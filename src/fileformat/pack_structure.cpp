#include "fileformat/pack_structure.h"

#include "fileformat/byte_reader.h"

#include <zlib.h>

#include <algorithm>
#include <limits>
#include <string_view>
#include <utility>

namespace fileformat
{

namespace
{

constexpr std::string_view format = "data pack";
constexpr std::string_view magic{"VEGASPK\0", 8};
constexpr std::size_t headerBytes = 88;
constexpr std::size_t checksumOffset = 84;
constexpr std::size_t recordBytes = 24;

[[noreturn]] void Fail(PackStructureProblem problem, std::string_view field, std::string_view text)
{
    throw PackStructureError(problem, std::string(format) + ": " + std::string(field) + ": " + std::string(text));
}

void RequireOne(std::uint32_t value, PackStructureProblem problem, std::string_view field)
{
    if (value != 1)
        Fail(problem, field, "is not 1");
}

// The CRC-32 of the file without the four bytes that store it.
std::uint32_t Checksum(std::span<const std::byte> file)
{
    uLong crc = crc32(0L, Z_NULL, 0);
    for (std::span<const std::byte> part : {file.first(checksumOffset), file.subspan(headerBytes)})
    {
        while (!part.empty())
        {
            const std::size_t chunk = std::min<std::size_t>(part.size(), std::numeric_limits<uInt>::max());
            crc = crc32(crc, reinterpret_cast<const Bytef*>(part.data()), static_cast<uInt>(chunk));
            part = part.subspan(chunk);
        }
    }
    return static_cast<std::uint32_t>(crc);
}

} // namespace

PackStructure ParsePackStructure(std::vector<std::byte> file)
{
    const std::span<const std::byte> bytes = file;
    if (bytes.size() < headerBytes)
        Fail(PackStructureProblem::HeaderTruncated, "header", "ends early");

    ByteReader header(bytes.first(headerBytes), format);
    const std::span<const std::byte> fileMagic = header.Take(magic.size(), "magic");
    if (!std::ranges::equal(fileMagic, magic, [](std::byte byte, char c) { return byte == static_cast<std::byte>(c); }))
        Fail(PackStructureProblem::Magic, "magic", "is not VEGASPK and a zero byte");
    RequireOne(header.U32("envelope version"), PackStructureProblem::EnvelopeVersion, "envelope version");
    RequireOne(header.U32("catalogue version"), PackStructureProblem::CatalogueVersion, "catalogue version");
    RequireOne(header.U32("native data contract"), PackStructureProblem::NativeDataContract, "native data contract");
    RequireOne(header.U32("build target"), PackStructureProblem::BuildTarget, "build target");

    PackStructure pack{};
    for (std::uint16_t& part : pack.originalVersion)
        part = header.U16("original version");
    std::ranges::copy(header.Take(pack.originalSha256.size(), "original SHA-256"), pack.originalSha256.begin());

    if (header.U64("file bytes") != bytes.size())
        Fail(PackStructureProblem::FileBytes, "file bytes", "is not the size of the file");
    const std::uint64_t directoryBytes = header.U64("directory bytes");
    if (directoryBytes > bytes.size() - headerBytes)
        Fail(PackStructureProblem::DirectoryBytes, "directory bytes", "is more than follows the header");
    const std::uint32_t entryCount = header.U32("entry count");
    if (directoryBytes % recordBytes != 0 || entryCount != directoryBytes / recordBytes)
        Fail(PackStructureProblem::EntryCount, "entry count", "is not the number of records in the directory");
    if (entryCount == 0)
        Fail(PackStructureProblem::NoEntries, "entry count", "is zero");
    if (header.U32("CRC-32") != Checksum(bytes))
        Fail(PackStructureProblem::Checksum, "CRC-32", "is not that of the file");

    // The directory fits in the file, so its end and every offset accepted
    // below fit in size_t.
    std::size_t end = headerBytes + static_cast<std::size_t>(directoryBytes);
    ByteReader directory(bytes.subspan(headerBytes, end - headerBytes), format);
    pack.entries.reserve(entryCount);
    for (std::uint32_t i = 0; i < entryCount; ++i)
    {
        const std::string_view key = directory.Tag("entry key");
        PackEntry entry{};
        std::ranges::copy(key, entry.key.begin());
        entry.version = directory.U32("entry version");
        const std::uint64_t offset = directory.U64("payload offset");
        const std::uint64_t size = directory.U64("payload bytes");

        if (i != 0 && !(std::string_view(pack.entries.back().key.data(), 4) < key))
            Fail(PackStructureProblem::KeyOrder, "entry key", "is not greater than the key before it");
        if (offset > bytes.size() || size > bytes.size() - offset)
            Fail(PackStructureProblem::PayloadOutOfBounds, "payload", "is not inside the file");
        if (offset != end)
            Fail(PackStructureProblem::PayloadPlacement, "payload offset", "is not the end of what comes before");
        if (size == 0)
            Fail(PackStructureProblem::EmptyPayload, "payload bytes", "is zero");

        entry.offset = static_cast<std::size_t>(offset);
        entry.size = static_cast<std::size_t>(size);
        end = entry.offset + entry.size;
        pack.entries.push_back(entry);
    }
    if (end != bytes.size())
        Fail(PackStructureProblem::TrailingBytes, "last payload", "ends before the end of the file");

    pack.bytes = std::move(file);
    return pack;
}

} // namespace fileformat
