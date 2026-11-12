#include "fileformat/original_identity.h"

#include <algorithm>

namespace fileformat
{

OriginalIdentity IdentifyOriginal(const PeFile& pe, const std::array<std::byte, 32>& sha256,
                                  std::span<const OriginalIdentity> supported)
{
    const auto sameVersion = [&](const OriginalIdentity& identity) { return identity.version == pe.fileVersion; };
    if (std::ranges::none_of(supported, sameVersion))
        throw UnsupportedOriginalError(OriginalProblem::Version, "original release: file version: is not supported");
    const auto match = std::ranges::find_if(supported, [&](const OriginalIdentity& identity) {
        return sameVersion(identity) && identity.sha256 == sha256;
    });
    if (match == supported.end())
        throw UnsupportedOriginalError(OriginalProblem::Digest,
                                       "original release: SHA-256: is not that of a supported file of this version");
    return *match;
}

} // namespace fileformat
