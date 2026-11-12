#pragma once

#include "fileformat/pack_catalogue.h"

#include <filesystem>
#include <functional>
#include <string>
#include <variant>

// The data pack stage of main (ADR 0001; docs/data-pack-catalogue.md,
// increment 2; docs/data-pack-startup.md).
namespace fnv::startup
{
// The file name of the data pack that setup installs beside the executable.
inline constexpr char dataPackFileName[] = "vegas-data.pack";

// The published C1 strings when every value is published, or one line that
// names the failure.
using DataPackLoad = std::variant<std::reference_wrapper<const fileformat::SingleInstanceStrings>, std::string>;

// Reads dataPackFileName in `executableFolder`, validates it with
// fileformat::OpenAndValidatePack and publishes each value to its native
// owner: C1 to fnv::startup::PublishSingleInstanceStrings. Returns the
// published C1 strings, so their consumer cannot read them before they are
// published.
//
// A missing, unreadable or invalid pack is normal validation, not a fault:
// the stage publishes nothing and returns one line, ending in a newline, that
// names the failure. Only the file in `executableFolder` is read, never one
// in the working directory. An allocation failure throws the standard
// exceptions. Call it on the main thread before any other thread exists.
DataPackLoad LoadDataPack(const std::filesystem::path& executableFolder);
}
