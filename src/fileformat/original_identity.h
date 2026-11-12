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
// and whose digest is `sha256`. Throws UnsupportedOriginalError when there is
// none, also when `supported` is empty.
//
// The caller computes `sha256` over pe.bytes: how the digest is computed is
// not decided, so nothing here hashes. The supported set is the caller's: no
// digest is written into the source.
OriginalIdentity IdentifyOriginal(const PeFile& pe, const std::array<std::byte, 32>& sha256,
                                  std::span<const OriginalIdentity> supported);

} // namespace fileformat

#endif
