#include "setup/run_setup.h"

#include <filesystem>
#include <iostream>
#include <vector>

// vegas-setup <install folder> (docs/setup.md). The status is the
// setup::SetupExit that says how it ended.
#ifdef _WIN32
int wmain(int argc, wchar_t** argv)
#else
int main(int argc, char** argv)
#endif
{
    const std::vector<std::filesystem::path> arguments(argv + 1, argv + argc);
    return static_cast<int>(setup::RunSetup(arguments, std::cerr));
}
