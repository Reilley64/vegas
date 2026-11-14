#include "fileformat/pack_container.h"

#include <zlib.h>

#include <algorithm>
#include <limits>

namespace fileformat::pack_container
{

std::uint32_t Checksum(std::span<const std::byte> file)
{
    uLong crc = crc32(0L, Z_NULL, 0);
    for (std::span<const std::byte> part : {file.first(checksumOffset), file.subspan(headerBytes)})
    {
        while (!part.empty())
        {
            const std::size_t chunk = std::min<std::size_t>(part.size(), std::numeric_limits<uInt>::max());
            crc = crc32(crc, reinterpret_cast<const Bytef*>(part.data()), static_cast<uInt>(chunk));
            part = part.subspan(chunk);
        }
    }
    return static_cast<std::uint32_t>(crc);
}

} // namespace fileformat::pack_container
