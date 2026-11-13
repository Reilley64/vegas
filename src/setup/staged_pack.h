#ifndef VEGAS_SETUP_STAGED_PACK_H
#define VEGAS_SETUP_STAGED_PACK_H

#include "fileformat/original_identity.h"
#include "fileformat/pe_file.h"

#include <array>
#include <cstddef>
#include <utility>
#include <vector>

// Steps 1 to 5 of setup::PrepareDataPack, shared by it and a test-only form
// in tests/setup. The two differ only in how they identify the executable
// and check the written bytes. Not for other callers.
namespace setup::staged
{

// The SHA-256 of `bytes`, in one operation.
std::array<std::byte, 32> Sha256(const std::vector<std::byte>& bytes);

// Reads C1's fields and the main window class from `pe` and writes them as a
// data pack that records `original`. Throws setup::ExtractError.
std::vector<std::byte> WriteDataPack(const fileformat::PeFile& pe, const fileformat::OriginalIdentity& original);

// Parses `executable`, identifies it with `identify` from the SHA-256 of the
// bytes it parsed, and writes its pack.
template <typename Identify> std::vector<std::byte> StagePack(std::vector<std::byte> executable, Identify identify)
{
    const fileformat::PeFile pe = fileformat::ParsePeFile(std::move(executable));
    const fileformat::OriginalIdentity original = identify(pe, Sha256(pe.bytes));
    return WriteDataPack(pe, original);
}

} // namespace setup::staged

#endif
