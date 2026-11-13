#ifndef VEGAS_FILEFORMAT_PACK_VALIDATION_H
#define VEGAS_FILEFORMAT_PACK_VALIDATION_H

#include "fileformat/format_error.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_structure.h"

#include <array>
#include <cstddef>
#include <span>
#include <string>
#include <utility>
#include <vector>

namespace fileformat
{

// What CheckPackOriginal does not check. ValidatePack checks both; an
// OriginalCheckedPack lists both.
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
// ValidatePack checks the rest. A moved-from pack reports its original but
// has no entries.
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

// What makes a pack whose original is supported fail against the catalogue.
// MissingEntry is checked first, for each catalogue entry in turn. Then
// UnknownKey, EntryVersion and EntrySize are checked in that order for each
// entry of the pack in turn. FieldTerminator is checked last, for each field
// in turn, the entries in catalogue order.
enum class PackCatalogueProblem
{
    MissingEntry,    // the pack has no entry with the key of a catalogue entry
    UnknownKey,      // an entry's key is not in the catalogue
    EntryVersion,    // an entry's version is not the catalogue's for its key
    EntrySize,       // an entry's size is not the catalogue's for its key
    FieldTerminator, // a string field holds no zero byte
};

// A FormatError that also says which check of the catalogue failed.
class PackCatalogueError : public FormatError
{
  public:
    PackCatalogueError(PackCatalogueProblem problem, const std::string& message)
        : FormatError(message), problem(problem)
    {
    }

    PackCatalogueProblem Problem() const { return problem; }

  private:
    PackCatalogueProblem problem;
};

class ValidatedPack;

// The complete validator of a data pack, the one ADR 0001 requires setup and
// the engine to share. It takes the bytes of a file only: the supported set
// and the required entries are the source's. It runs CheckPackOriginal, then
// requires each entry of packCatalogue with its exact version and size,
// refuses any other key, and decodes every entry. Throws PackStructureError,
// then UnsupportedOriginalError, then PackCatalogueError, each in the order
// its enumeration gives.
//
// The pack's original is compared, not proved: nothing here reads an
// executable or computes a digest.
ValidatedPack ValidatePack(std::vector<std::byte> file);

// A data pack that passed ValidatePack, as the values decoded from it: it
// keeps neither the file nor its directory. Only ValidatePack makes one,
// and it can be moved but not copied. A moved-from pack keeps its values.
class ValidatedPack
{
  public:
    ValidatedPack(ValidatedPack&&) noexcept = default;
    ValidatedPack& operator=(ValidatedPack&&) noexcept = default;
    ValidatedPack(const ValidatedPack&) = delete;
    ValidatedPack& operator=(const ValidatedPack&) = delete;

    // The supported identity the pack's header matched.
    const OriginalIdentity& Original() const& { return original; }
    const OriginalIdentity& Original() const&& = delete;

    // C1's strings, each field its string, a zero byte and zeros to its end.
    const SingleInstanceStrings& SingleInstance() const& { return singleInstance; }
    const SingleInstanceStrings& SingleInstance() const&& = delete;

    // The main window class's class name, a zero byte and zeros to the end
    // of its field.
    const MainWindowClass& WindowClass() const& { return windowClass; }
    const MainWindowClass& WindowClass() const&& = delete;

  private:
    friend ValidatedPack ValidatePack(std::vector<std::byte> file);

    ValidatedPack(const OriginalIdentity& original, const SingleInstanceStrings& singleInstance,
                  const MainWindowClass& windowClass)
        : original(original), singleInstance(singleInstance), windowClass(windowClass)
    {
    }

    OriginalIdentity original;
    SingleInstanceStrings singleInstance;
    MainWindowClass windowClass;
};

} // namespace fileformat

#endif
