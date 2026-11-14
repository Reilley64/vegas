#ifndef VEGAS_FILEFORMAT_ORIGINAL_IDENTITY_H
#define VEGAS_FILEFORMAT_ORIGINAL_IDENTITY_H

#include "fileformat/pe_file.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <stdexcept>
#include <string>

namespace fileformat
{

// A supported original release: the file version of its executable and the
// SHA-256 of the whole file. These are the two values a data pack's header
// records as the original it was prepared from.
struct OriginalIdentity
{
    std::array<std::uint16_t, 4> version; // major, minor, patch, build
    std::array<std::byte, 32> sha256;
};

// The original releases the engine supports: exactly one, FalloutNV.exe of
// Fallout: New Vegas for PC as Steam distributes it, file version 1.4.0.525,
// 16,549,704 bytes. Adopted by the owner on VEGAS-52 on 2026-11-12. Only its
// identification is written here, its file version and the SHA-256 of the
// whole file, and in this comment its size: no other byte or value of the
// file.
inline constexpr std::array<OriginalIdentity, 1> supportedOriginalReleases{{
    {{1, 4, 0, 525},
     {std::byte{0x3a}, std::byte{0x87}, std::byte{0xf9}, std::byte{0x2f}, std::byte{0x01}, std::byte{0x1e},
      std::byte{0x5d}, std::byte{0xc9}, std::byte{0x17}, std::byte{0x9d}, std::byte{0xdf}, std::byte{0x73},
      std::byte{0x3c}, std::byte{0xf0}, std::byte{0x8b}, std::byte{0xe2}, std::byte{0xb3}, std::byte{0x9e},
      std::byte{0xa6}, std::byte{0xe5}, std::byte{0xb7}, std::byte{0xa8}, std::byte{0xa9}, std::byte{0xe3},
      std::byte{0xa9}, std::byte{0xa7}, std::byte{0x2d}, std::byte{0xaf}, std::byte{0xcc}, std::byte{0x1b},
      std::byte{0x10}, std::byte{0x4d}}},
}};

// The set the production forms, which take no set, check against.
constexpr std::span<const OriginalIdentity> SupportedOriginals()
{
    return supportedOriginalReleases;
}

// Why an executable is not a supported original release. Version is checked
// before Digest.
enum class OriginalProblem
{
    Version, // no supported identity has the file version
    Digest,  // supported identities have the file version, but none has the digest
};

// Thrown when an executable is not a supported original release. Its bytes may
// be well formed, so it is not a FormatError.
class UnsupportedOriginalError : public std::runtime_error
{
  public:
    UnsupportedOriginalError(OriginalProblem problem, const std::string& message)
        : std::runtime_error(message), problem(problem)
    {
    }

    OriginalProblem Problem() const { return problem; }

  private:
    OriginalProblem problem;
};

// Returns the supported identity whose version is the file version of `pe`
// and whose digest is `sha256`, where the supported identities are
// SupportedOriginals(). Throws UnsupportedOriginalError when there is none.
//
// The caller computes `sha256` over pe.bytes: how the digest is computed is
// not decided, so nothing here hashes.
OriginalIdentity IdentifyOriginal(const PeFile& pe, const std::array<std::byte, 32>& sha256);

// IdentifyOriginal against `supported` instead of SupportedOriginals(), also
// throwing when `supported` is empty. For tests of the comparison only: no
// file under src/ calls it.
OriginalIdentity IdentifyOriginalAgainst(const PeFile& pe, const std::array<std::byte, 32>& sha256,
                                         std::span<const OriginalIdentity> supported);

} // namespace fileformat

#endif
