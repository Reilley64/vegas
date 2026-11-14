#include "fnv/log_path_suffixes.h"

#include "fileformat/pack_validation.h"

#include <cstdlib>

namespace
{
fileformat::LogPathSuffixes s_suffixes;
bool s_published;
}

void fnv::startup::PublishLogPathSuffixes(const fileformat::ValidatedPack& pack) noexcept
{
    s_suffixes = pack.PathSuffixes();
    s_published = true;
}

const fileformat::LogPathSuffixes& fnv::startup::PublishedLogPathSuffixes() noexcept
{
    if (!s_published)
        std::abort();
    return s_suffixes;
}
