#include "fnv/single_instance_strings.h"

#include "fileformat/pack_validation.h"

#include <cstdlib>

namespace
{
fileformat::SingleInstanceStrings s_strings;
bool s_published;
}

void fnv::startup::PublishSingleInstanceStrings(const fileformat::ValidatedPack& pack) noexcept
{
    s_strings = pack.SingleInstance();
    s_published = true;
}

const fileformat::SingleInstanceStrings& fnv::startup::PublishedSingleInstanceStrings() noexcept
{
    if (!s_published)
        std::abort();
    return s_strings;
}
