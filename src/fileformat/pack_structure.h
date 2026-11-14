#ifndef VEGAS_FILEFORMAT_PACK_STRUCTURE_H
#define VEGAS_FILEFORMAT_PACK_STRUCTURE_H

#include "fileformat/format_error.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <vector>

namespace fileformat
{

// What makes bytes fail as the container of a data pack. The header checks,
// HeaderTruncated to Checksum, run in the order listed. Then the four
// directory checks, KeyOrder to EmptyPayload, run in that order for each
// record in turn, so a problem in an earlier record is reported before any
// problem in a later record. TrailingBytes is checked last.
enum class PackStructureProblem
{
    HeaderTruncated,    // fewer bytes than the 88-byte header
    Magic,              // does not start with VEGASPK and a zero byte
    EnvelopeVersion,    // not 1
    CatalogueVersion,   // not packCatalogueVersion, the source catalogue's
    NativeDataContract, // not 1
    BuildTarget,        // not 1, windows-x64
    FileBytes,          // not the number of bytes given
    DirectoryBytes,     // the directory does not fit after the header
    EntryCount,         // not the number of 24-byte records in the directory
    NoEntries,          // the directory is empty
    Checksum,           // the stored CRC-32 is not that of the other bytes
    KeyOrder,           // a key is not greater, as bytes, than the one before
    PayloadOutOfBounds, // a payload starts or ends after the end of the file
    PayloadPlacement,   // a payload does not start where the one before ends
    EmptyPayload,       // a payload of no bytes
    TrailingBytes,      // the last payload ends before the end of the file
};

// A FormatError that also says which check failed.
class PackStructureError : public FormatError
{
  public:
    PackStructureError(PackStructureProblem problem, const std::string& message)
        : FormatError(message), problem(problem)
    {
    }

    PackStructureProblem Problem() const { return problem; }

  private:
    PackStructureProblem problem;
};

// One directory record. The offset counts bytes from the start of the file.
struct PackEntry
{
    std::array<char, 4> key;
    std::uint32_t version; // as stored, not compared with any supported version
    std::size_t offset;
    std::size_t size;
};

// A data pack whose container is well formed: its header, directory, payload
// placement and CRC-32 are those of envelope version 1 for windows-x64.
//
// This is not a validated pack and does not allow the engine to start. Three
// things remain unchecked: what the entries mean, including their keys and
// versions; whether the original release named by `originalVersion` and
// `originalSha256` is one the engine supports; and whether every entry the
// engine requires is present. The CRC-32 detects damage only.
struct PackStructure
{
    std::array<std::uint16_t, 4> originalVersion; // major, minor, patch, build, as claimed
    std::array<std::byte, 32> originalSha256;     // as claimed
    std::vector<std::byte> bytes;                 // the whole file
    std::vector<PackEntry> entries;               // in directory order

    // The span points into `bytes`, so it is not offered on a temporary.
    std::span<const std::byte> EntryBytes(const PackEntry& entry) const&
    {
        return std::span<const std::byte>(bytes).subspan(entry.offset, entry.size);
    }
    std::span<const std::byte> EntryBytes(const PackEntry& entry) const&& = delete;
};

// Checks the container of a data pack and takes ownership of its bytes. Throws
// PackStructureError when the bytes are not a well-formed container. Success
// says nothing about the three unchecked things listed at PackStructure.
PackStructure ParsePackStructure(std::vector<std::byte> file);

} // namespace fileformat

#endif
