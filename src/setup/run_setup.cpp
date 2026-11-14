#include "setup/run_setup.h"

#include "fileformat/original_identity.h"
#include "fileformat/pe_file.h"
#include "fnv/data_pack_startup.h"
#include "setup/install_pack.h"
#include "setup/prepare_pack.h"

#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <share.h>
#endif

namespace setup
{

namespace
{

struct CloseFile
{
    void operator()(std::FILE* file) const { std::fclose(file); }
};

// The bytes of the file at `path`, or the exit status that says why there are
// none.
struct Executable
{
    std::vector<std::byte> bytes;
    std::optional<SetupExit> failure;
};

// Reads to the end of the file, so the size used is the number of bytes read,
// not one taken before reading.
Executable ReadExecutable(const std::filesystem::path& path)
{
    errno = 0;
#ifdef _WIN32
    // The wide name, so a path outside the ANSI code page still opens. Others
    // may read the file meanwhile but not write it.
    std::unique_ptr<std::FILE, CloseFile> file(_wfsopen(path.c_str(), L"rb", _SH_DENYWR));
#else
    std::unique_ptr<std::FILE, CloseFile> file(std::fopen(path.c_str(), "rb"));
#endif
    if (!file)
        return {{}, errno == ENOENT ? SetupExit::ExecutableMissing : SetupExit::ExecutableUnreadable};
    constexpr std::size_t chunkBytes = std::size_t{1} << 20;
    std::vector<std::byte> bytes;
    std::size_t size = 0;
    for (;;)
    {
        bytes.resize(size + chunkBytes);
        const std::size_t read = std::fread(bytes.data() + size, 1, chunkBytes, file.get());
        size += read;
        if (read != chunkBytes)
            break;
    }
    if (std::ferror(file.get()) != 0)
        return {{}, SetupExit::ExecutableUnreadable};
    bytes.resize(size);
    return {std::move(bytes), std::nullopt};
}

SetupExit End(std::ostream& messages, SetupExit status, const std::string& line)
{
    messages << "vegas-setup: " << line << '\n';
    return status;
}

SetupExit Failed(std::ostream& messages, SetupExit status, const std::string& reason, const char* what)
{
    return End(messages, status, reason + ": " + what);
}

SetupExit InstallFailure(InstallProblem problem)
{
    switch (problem)
    {
    case InstallProblem::StagedWrite:
        return SetupExit::StagedWrite;
    case InstallProblem::StagedInvalid:
        return SetupExit::StagedInvalid;
    case InstallProblem::Replace:
        return SetupExit::Replace;
    case InstallProblem::Recheck:
        break;
    }
    return SetupExit::Recheck;
}

} // namespace

SetupExit RunSetup(std::span<const std::filesystem::path> arguments, std::ostream& messages)
{
    if (arguments.size() != 1)
        return End(messages, SetupExit::Usage, "usage: vegas-setup <install folder>");
    const std::filesystem::path& folder = arguments[0];
    const std::string executableName = originalExecutableName;

    Executable executable = ReadExecutable(folder / originalExecutableName);
    if (executable.failure == SetupExit::ExecutableMissing)
        return End(messages, SetupExit::ExecutableMissing, executableName + " is not in the install folder");
    if (executable.failure)
        return End(messages, *executable.failure, executableName + " in the install folder cannot be read");

    try
    {
        const PreparedPack prepared = PrepareDataPack(std::move(executable.bytes));
        InstallDataPack(folder, prepared.bytes, prepared.validated);
    }
    catch (const fileformat::PeError& error)
    {
        return Failed(messages, SetupExit::NotAnExecutable, executableName + " is not a readable 32-bit executable",
                      error.what());
    }
    catch (const fileformat::UnsupportedOriginalError& error)
    {
        return Failed(messages, SetupExit::UnsupportedOriginal,
                      executableName + " is not the executable of a supported original release", error.what());
    }
    catch (const ExtractError& error)
    {
        return Failed(messages, SetupExit::DataUnreadable,
                      "the data of " + executableName + " cannot be read as stored", error.what());
    }
    catch (const StagedPackError& error)
    {
        return Failed(messages, SetupExit::WrittenPackRefused, "setup wrote a data pack it refuses (a defect)",
                      error.what());
    }
    catch (const InstallError& error)
    {
        return Failed(messages, InstallFailure(error.Problem()),
                      std::string(fnv::startup::dataPackFileName) + " could not be installed", error.what());
    }
    return End(messages, SetupExit::Installed,
               std::string(fnv::startup::dataPackFileName) + " was written beside " + executableName);
}

} // namespace setup
