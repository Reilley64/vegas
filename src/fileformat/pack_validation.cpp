#include "fileformat/pack_validation.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace fileformat
{

OriginalCheckedPack CheckPackOriginal(std::vector<std::byte> file, std::span<const OriginalIdentity> supported)
{
    PackStructure structure = ParsePackStructure(std::move(file));

    const auto sameVersion = [&](const OriginalIdentity& identity) {
        return identity.version == structure.originalVersion;
    };
    if (std::ranges::none_of(supported, sameVersion))
        throw UnsupportedOriginalError(OriginalProblem::Version, "data pack: original version: is not supported");
    const auto match = std::ranges::find_if(supported, [&](const OriginalIdentity& identity) {
        return sameVersion(identity) && identity.sha256 == structure.originalSha256;
    });
    if (match == supported.end())
        throw UnsupportedOriginalError(OriginalProblem::Digest,
                                       "data pack: original SHA-256: is not supported for this version");
    return OriginalCheckedPack(std::move(structure), *match);
}

std::span<const std::byte> OriginalCheckedPack::EntryBytes(std::size_t index) const&
{
    if (index >= structure.entries.size())
        throw std::out_of_range("data pack: entry index: is past the last entry");
    return structure.EntryBytes(structure.entries[index]);
}

} // namespace fileformat
