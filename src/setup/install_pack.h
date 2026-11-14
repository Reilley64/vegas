#ifndef VEGAS_SETUP_INSTALL_PACK_H
#define VEGAS_SETUP_INSTALL_PACK_H

#include "fileformat/pack_validation.h"

#include <cstddef>
#include <filesystem>
#include <span>
#include <stdexcept>
#include <string>

namespace setup
{

// The file setup writes first, in the install folder, before it replaces the
// data pack.
inline constexpr char stagedPackFileName[] = "vegas-data.pack.staged";

// Which step of InstallDataPack failed, in the order they run.
enum class InstallProblem
{
    StagedWrite,   // the staged file could not be written
    StagedInvalid, // the staged file, read back, is refused or does not hold the expected values
    Replace,       // the staged file could not be renamed over the data pack
    Recheck,       // the installed data pack, read back, is refused or does not hold the expected values
};

class InstallError : public std::runtime_error
{
  public:
    InstallError(InstallProblem problem, const std::string& message) : std::runtime_error(message), problem(problem) {}

    InstallProblem Problem() const { return problem; }

  private:
    InstallProblem problem;
};

// Installs `pack` as fnv::startup::dataPackFileName in `folder`:
//
// 1. writes it to stagedPackFileName in `folder`, replacing a file of that
//    name;
// 2. reads the staged file back with fileformat::OpenAndValidatePack and
//    requires the original and the values of `expected`;
// 3. renames the staged file over the data pack;
// 4. reads the data pack back the same way.
//
// Throws InstallError with the step that failed. When step 1, 2 or 3 fails,
// a staged file is removed, but not a folder of its name, and an existing
// data pack is left as it was. Nothing else in `folder` is read or written. An allocation failure
// throws the standard exceptions.
void InstallDataPack(const std::filesystem::path& folder, std::span<const std::byte> pack,
                     const fileformat::ValidatedPack& expected);

} // namespace setup

#endif
