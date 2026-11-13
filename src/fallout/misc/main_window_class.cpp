#include "fnv/main_window_class.h"

#include "fileformat/pack_validation.h"

#include <cstdlib>

namespace
{
fileformat::MainWindowClass s_windowClass;
bool s_published;
}

void fnv::startup::PublishMainWindowClass(const fileformat::ValidatedPack& pack) noexcept
{
    s_windowClass = pack.WindowClass();
    s_published = true;
}

const fileformat::MainWindowClass& fnv::startup::PublishedMainWindowClass() noexcept
{
    if (!s_published)
        std::abort();
    return s_windowClass;
}
