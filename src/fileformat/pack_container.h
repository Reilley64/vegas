#ifndef VEGAS_FILEFORMAT_PACK_CONTAINER_H
#define VEGAS_FILEFORMAT_PACK_CONTAINER_H

#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>

// The layout of the data pack container, envelope version 1, by the pack
// decision record. The reader and the writer of the container share it;
// nothing else is meant to include it.
namespace fileformat::pack_container
{

inline constexpr std::string_view magic{"VEGASPK\0", 8};
inline constexpr std::size_t headerBytes = 88;
inline constexpr std::size_t checksumOffset = 84;
inline constexpr std::size_t recordBytes = 24;

// The only supported value of each of three revision and target fields:
// envelope version, native data contract and build target (1 is
// windows-x64). The catalogue version is the source catalogue's,
// packCatalogueVersion in pack_catalogue.h, which changes on its own.
inline constexpr std::uint32_t revision = 1;

// The zlib CRC-32 of a file of at least headerBytes bytes, without the four
// bytes at checksumOffset that store it.
std::uint32_t Checksum(std::span<const std::byte> file);

} // namespace fileformat::pack_container

#endif
