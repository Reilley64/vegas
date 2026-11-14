#include "fnv/save_directory_strings.h"

#include "fileformat/pack_validation.h"

#include <cstdlib>

namespace
{
fileformat::SaveDirectoryStrings s_strings;
bool s_published;
}

void fnv::startup::PublishSaveDirectoryStrings(const fileformat::ValidatedPack& pack) noexcept
{
    s_strings = pack.SaveDirectory();
    s_published = true;
}

const fileformat::SaveDirectoryStrings& fnv::startup::PublishedSaveDirectoryStrings() noexcept
{
    if (!s_published)
        std::abort();
    return s_strings;
}
