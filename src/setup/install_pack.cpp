#include "setup/install_pack.h"

#include "fileformat/format_error.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_open.h"
#include "fnv/data_pack_startup.h"

#include <fstream>
#include <ios>
#include <system_error>

namespace setup
{

namespace
{

namespace fs = std::filesystem;

bool SameValues(const fileformat::ValidatedPack& a, const fileformat::ValidatedPack& b)
{
    const fileformat::SingleInstanceStrings& x = a.SingleInstance();
    const fileformat::SingleInstanceStrings& y = b.SingleInstance();
    return a.Original().version == b.Original().version && a.Original().sha256 == b.Original().sha256 &&
           x.mutexName == y.mutexName && x.firstMessageText == y.firstMessageText &&
           x.messageCaption == y.messageCaption && x.secondMessageText == y.secondMessageText;
}

// Reads `file` back and fails with `problem` unless it validates and holds
// the values of `expected`.
void ReadBack(const fs::path& file, const fileformat::ValidatedPack& expected, InstallProblem problem,
              const std::string& name)
{
    try
    {
        if (!SameValues(fileformat::OpenAndValidatePack(file), expected))
            throw InstallError(problem, name + ": does not hold the values prepared");
    }
    catch (const fileformat::PackOpenError& error)
    {
        throw InstallError(problem, name + ": " + error.what());
    }
    catch (const fileformat::FormatError& error)
    {
        throw InstallError(problem, name + ": " + error.what());
    }
    catch (const fileformat::UnsupportedOriginalError& error)
    {
        throw InstallError(problem, name + ": " + error.what());
    }
}

// Removes the staged file, but nothing else of that name, such as a folder.
void RemoveStaged(const fs::path& staged)
{
    std::error_code ignored;
    if (fs::is_regular_file(staged, ignored))
        fs::remove(staged, ignored);
}

} // namespace

void InstallDataPack(const fs::path& folder, std::span<const std::byte> pack, const fileformat::ValidatedPack& expected)
{
    const fs::path staged = folder / stagedPackFileName;
    const fs::path target = folder / fnv::startup::dataPackFileName;
    {
        std::ofstream out(staged, std::ios::binary | std::ios::trunc);
        out.write(reinterpret_cast<const char*>(pack.data()), static_cast<std::streamsize>(pack.size()));
        out.close();
        if (!out)
        {
            RemoveStaged(staged);
            throw InstallError(InstallProblem::StagedWrite, std::string(stagedPackFileName) + ": cannot be written");
        }
    }
    try
    {
        ReadBack(staged, expected, InstallProblem::StagedInvalid, stagedPackFileName);
    }
    catch (const InstallError&)
    {
        RemoveStaged(staged);
        throw;
    }
    std::error_code error;
    fs::rename(staged, target, error);
    if (error)
    {
        RemoveStaged(staged);
        throw InstallError(InstallProblem::Replace, std::string(stagedPackFileName) + ": cannot be renamed to " +
                                                        fnv::startup::dataPackFileName);
    }
    ReadBack(target, expected, InstallProblem::Recheck, fnv::startup::dataPackFileName);
}

} // namespace setup
