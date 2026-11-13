#ifndef VEGAS_FILEFORMAT_PACK_CATALOGUE_H
#define VEGAS_FILEFORMAT_PACK_CATALOGUE_H

#include <array>
#include <cstddef>
#include <cstdint>

// The catalogue of the data pack, the source's list of the entries a pack
// holds, by the pack decision record, ADR 0001, and the catalogue decisions
// of VEGAS-52 (docs/data-pack-catalogue.md).
namespace fileformat
{

// The catalogue version this catalogue is. By ADR 0001 as amended on
// 2026-11-13, a pack's header field must equal it, and any change to the
// required entries raises it by one. It is its own constant, not the
// container's revision.
inline constexpr std::uint32_t packCatalogueVersion = 1;

// One entry of the catalogue: a pack holds it under `key`, with exactly
// `version` and exactly `bytes` bytes.
struct PackCatalogueEntry
{
    std::array<char, 4> key; // four ASCII bytes; no key encodes an address
    std::uint32_t version;
    std::size_t bytes;
};

// The values of C1: the four strings that the single-instance and
// remote-session checks at the start of WinMain read, one field per string.
// Each capacity is the distance from the string's address to the next address
// the recipe binds. A field holds its string, then a zero byte, then zeros to
// its end.
struct SingleInstanceStrings
{
    std::array<char, 20> mutexName;         // the name of the mutex
    std::array<char, 60> firstMessageText;  // the text of the first message box
    std::array<char, 8> messageCaption;     // the caption of both message boxes
    std::array<char, 52> secondMessageText; // the text of the second message box
};

// C1's entry: its four fields in order, end to end.
inline constexpr PackCatalogueEntry singleInstanceEntry{
    {'I', 'N', 'S', 'T'},
    1,
    sizeof(SingleInstanceStrings::mutexName) + sizeof(SingleInstanceStrings::firstMessageText) +
        sizeof(SingleInstanceStrings::messageCaption) + sizeof(SingleInstanceStrings::secondMessageText),
};
static_assert(singleInstanceEntry.bytes == 140);

// Every entry of catalogue version 1, in ascending key order. A pack holds
// each of them and no other.
inline constexpr std::array<PackCatalogueEntry, 1> packCatalogue{singleInstanceEntry};

} // namespace fileformat

#endif
