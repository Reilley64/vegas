#ifndef VEGAS_FILEFORMAT_PACK_WRITER_H
#define VEGAS_FILEFORMAT_PACK_WRITER_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <stdexcept>
#include <string>
#include <vector>

namespace fileformat
{

// What makes entries unfit to be written as a data pack. TooManyEntries and
// NoEntries are checked first. Then KeyNotAscii, KeyOrder and EmptyPayload
// are checked in that order for each entry in turn, so a problem in an
// earlier entry is reported before any problem in a later entry.
enum class PackWriteProblem
{
    TooManyEntries, // more entries than the 32-bit entry count holds
    NoEntries,      // no entry
    KeyNotAscii,    // a key byte is above 0x7F
    KeyOrder,       // a key is not greater, as unsigned bytes, than the one before
    EmptyPayload,   // a payload of no bytes
};

// Thrown when the entries given to WritePackStructure break a rule of the
// container. It also says which rule.
class PackWriteError : public std::invalid_argument
{
  public:
    PackWriteError(PackWriteProblem problem, const std::string& message)
        : std::invalid_argument(message), problem(problem)
    {
    }

    PackWriteProblem Problem() const { return problem; }

  private:
    PackWriteProblem problem;
};

// One entry to write. The payload is copied; the caller keeps it.
struct PackWriteEntry
{
    std::array<char, 4> key;
    std::uint32_t version; // written as given, not compared with any supported version
    std::span<const std::byte> payload;
};

// Returns the bytes of a data pack container, envelope version 1 for
// windows-x64, that holds the entries in the order given, with the original
// version and SHA-256 written as given. The payloads follow the directory end
// to end. The file size and then the CRC-32 are stored last.
//
// Throws PackWriteError when the entries break a rule of the container: there
// must be at least one, no more than 2^32 - 1; each key is four ASCII bytes,
// greater as unsigned bytes than the key before it; and no payload is empty.
// Which keys and versions mean what, which entries a pack needs, and which
// original releases are supported are not decided here, so the writer takes
// them as given.
std::vector<std::byte> WritePackStructure(const std::array<std::uint16_t, 4>& originalVersion,
                                          const std::array<std::byte, 32>& originalSha256,
                                          std::span<const PackWriteEntry> entries);

} // namespace fileformat

#endif
