#include "fileformat/pack_writer.h"

#include "fileformat/byte_writer.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_container.h"

#include <limits>
#include <string_view>

namespace fileformat
{

namespace
{

constexpr std::string_view format = "data pack";

// The writer writes pack_container::revision as the catalogue version, which
// must be the source catalogue's.
static_assert(packCatalogueVersion == pack_container::revision);

[[noreturn]] void Fail(PackWriteProblem problem, std::string_view field, std::string_view text)
{
    throw PackWriteError(problem, std::string(format) + ": " + std::string(field) + ": " + std::string(text));
}

std::string_view Key(const PackWriteEntry& entry)
{
    return {entry.key.data(), entry.key.size()};
}

// Overwrites `width` bytes at `offset` with `value`, little-endian.
void Store(std::vector<std::byte>& bytes, std::size_t offset, std::uint64_t value, std::size_t width)
{
    for (std::size_t i = 0; i < width; ++i)
        bytes[offset + i] = static_cast<std::byte>(value >> (8 * i));
}

} // namespace

std::vector<std::byte> WritePackStructure(const std::array<std::uint16_t, 4>& originalVersion,
                                          const std::array<std::byte, 32>& originalSha256,
                                          std::span<const PackWriteEntry> entries)
{
    if (entries.size() > std::numeric_limits<std::uint32_t>::max())
        Fail(PackWriteProblem::TooManyEntries, "entry count", "is more than 2^32 - 1");
    if (entries.empty())
        Fail(PackWriteProblem::NoEntries, "entry count", "is zero");
    for (std::size_t i = 0; i < entries.size(); ++i)
    {
        for (char c : entries[i].key)
        {
            if (static_cast<unsigned char>(c) > 0x7F)
                Fail(PackWriteProblem::KeyNotAscii, "entry key", "is not ASCII");
        }
        // string_view compares chars as unsigned bytes.
        if (i != 0 && !(Key(entries[i - 1]) < Key(entries[i])))
            Fail(PackWriteProblem::KeyOrder, "entry key", "is not greater than the key before it");
        if (entries[i].payload.empty())
            Fail(PackWriteProblem::EmptyPayload, "payload bytes", "is zero");
    }

    const std::size_t directoryBytes = pack_container::recordBytes * entries.size();
    ByteWriter pack;
    pack.Text(pack_container::magic);
    pack.U32(pack_container::revision); // envelope version
    pack.U32(pack_container::revision); // catalogue version
    pack.U32(pack_container::revision); // native data contract
    pack.U32(pack_container::revision); // build target
    for (std::uint16_t part : originalVersion)
        pack.U16(part);
    pack.Append(originalSha256);
    const std::size_t fileBytesOffset = pack.Size();
    pack.U64(0); // file bytes, stored below
    pack.U64(directoryBytes);
    pack.U32(static_cast<std::uint32_t>(entries.size()));
    pack.U32(0); // CRC-32, stored below

    std::size_t offset = pack_container::headerBytes + directoryBytes;
    for (const PackWriteEntry& entry : entries)
    {
        pack.Text(Key(entry));
        pack.U32(entry.version);
        pack.U64(offset);
        pack.U64(entry.payload.size());
        offset += entry.payload.size();
    }
    for (const PackWriteEntry& entry : entries)
        pack.Append(entry.payload);

    std::vector<std::byte> bytes = pack.Take();
    Store(bytes, fileBytesOffset, bytes.size(), 8);
    Store(bytes, pack_container::checksumOffset, pack_container::Checksum(bytes), 4);
    return bytes;
}

} // namespace fileformat
