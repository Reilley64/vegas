#ifndef VEGAS_FILEFORMAT_PACK_VALIDATION_H
#define VEGAS_FILEFORMAT_PACK_VALIDATION_H

#include "fileformat/original_identity.h"
#include "fileformat/pack_structure.h"

#include <array>
#include <cstddef>
#include <span>
#include <utility>
#include <vector>

namespace fileformat
{

// What CheckPackOriginal does not check yet, because what it would be
// checked against is not decided. An OriginalCheckedPack lists both.
enum class UncheckedPackRequirement
{
    Catalogue,   // which keys exist, which version of each is supported, which entries are required
    EntryValues, // what an entry's bytes mean: no entry is decoded
};

class OriginalCheckedPack;

// Checks the container of a data pack, then that the original release its
// header records, version and SHA-256, is one of SupportedOriginals().
// Throws PackStructureError for the container and then
// UnsupportedOriginalError, Version before Digest.
//
// The pack's claim is compared, not proved: nothing here reads an executable
// or computes a digest.
OriginalCheckedPack CheckPackOriginal(std::vector<std::byte> file);

// CheckPackOriginal against `supported` instead of SupportedOriginals(), also
// throwing when `supported` is empty. For tests of the comparison only: no
// file under src/ calls it.
OriginalCheckedPack CheckPackOriginalAgainst(std::vector<std::byte> file, std::span<const OriginalIdentity> supported);

// A data pack that passed CheckPackOriginal: a well-formed container whose
// recorded original is one of the supported set it was checked against.
// Only CheckPackOriginal and CheckPackOriginalAgainst make one, and it can
// be moved but not copied.
//
// It is not a complete pack: Unchecked() lists what is not checked. No entry
// is required, known or decoded, so it does not allow the engine to start.
// The names ValidatePack and ValidatedPack are kept for the complete
// validator. A moved-from pack reports its original but has no entries.
class OriginalCheckedPack
{
  public:
    OriginalCheckedPack(OriginalCheckedPack&&) noexcept = default;
    OriginalCheckedPack& operator=(OriginalCheckedPack&&) noexcept = default;
    OriginalCheckedPack(const OriginalCheckedPack&) = delete;
    OriginalCheckedPack& operator=(const OriginalCheckedPack&) = delete;

    // The supported identity the pack's header matched.
    const OriginalIdentity& Original() const& { return original; }
    const OriginalIdentity& Original() const&& = delete;

    // The directory, in order. Keys and versions are as stored. The span
    // points into the pack, so it is not offered on a temporary.
    std::span<const PackEntry> Entries() const& { return structure.entries; }
    std::span<const PackEntry> Entries() const&& = delete;

    // The payload of the entry at `index` in Entries(). Throws
    // std::out_of_range when there is no such entry. The span points into the
    // pack, so it is not offered on a temporary.
    std::span<const std::byte> EntryBytes(std::size_t index) const&;
    std::span<const std::byte> EntryBytes(std::size_t index) const&& = delete;

    static std::span<const UncheckedPackRequirement> Unchecked() { return unchecked; }

  private:
    friend OriginalCheckedPack CheckPackOriginal(std::vector<std::byte> file);
    friend OriginalCheckedPack CheckPackOriginalAgainst(std::vector<std::byte> file,
                                                        std::span<const OriginalIdentity> supported);

    OriginalCheckedPack(PackStructure structure, const OriginalIdentity& original)
        : structure(std::move(structure)), original(original)
    {
    }

    static constexpr std::array<UncheckedPackRequirement, 2> unchecked{
        UncheckedPackRequirement::Catalogue,
        UncheckedPackRequirement::EntryValues,
    };

    PackStructure structure;
    OriginalIdentity original;
};

} // namespace fileformat

#endif
