#include "check.h"
#include "fileformat/pack_open.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/pe_fixture.h"
#include "fileformat/supported_release.h"
#include "setup/install_pack.h"
#include "setup/run_setup.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <iterator>
#include <random>
#include <set>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

namespace
{

namespace fs = std::filesystem;
using setup::InstallProblem;
using setup::SetupExit;

// The names the test spells itself.
constexpr std::string_view packName = "vegas-data.pack";
constexpr std::string_view stagedName = "vegas-data.pack.staged";
constexpr std::string_view executableName = "FalloutNV.exe";

// A new empty folder, removed with what it holds.
class Folder
{
  public:
    Folder()
    {
        std::random_device random;
        for (;;)
        {
            path = fs::temp_directory_path() / std::format("vegas-setup-{:08x}{:08x}", random(), random());
            if (fs::create_directory(path))
                return;
        }
    }
    Folder(const Folder&) = delete;
    Folder& operator=(const Folder&) = delete;
    ~Folder()
    {
        std::error_code ignored;
        fs::remove_all(path, ignored);
    }

    fs::path Write(std::string_view name, std::span<const std::byte> bytes) const
    {
        const fs::path file = path / name;
        std::ofstream out(file, std::ios::binary | std::ios::trunc);
        out.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
        out.close();
        if (!out)
            throw std::runtime_error("the test could not write its file");
        return file;
    }

    std::vector<std::byte> Read(std::string_view name) const
    {
        std::ifstream in(path / name, std::ios::binary);
        const std::vector<char> chars{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
        std::vector<std::byte> bytes(chars.size());
        for (std::size_t i = 0; i < chars.size(); ++i)
            bytes[i] = static_cast<std::byte>(chars[i]);
        return bytes;
    }

    // The names of what the folder holds.
    std::set<std::string> Names() const
    {
        std::set<std::string> names;
        for (const fs::directory_entry& entry : fs::directory_iterator(path))
            names.insert(entry.path().filename().string());
        return names;
    }

    fs::path path;
};

std::vector<std::byte> Bytes(std::string_view text)
{
    std::vector<std::byte> bytes;
    for (const char c : text)
        bytes.push_back(static_cast<std::byte>(c));
    return bytes;
}

// Checks that the folder holds exactly `expected`.
void HoldsNames(Checks& check, std::string_view name, const Folder& folder, const std::set<std::string>& expected)
{
    const std::set<std::string> names = folder.Names();
    if (names == expected)
        return;
    std::string held;
    for (const std::string& n : names)
        held += " " + n;
    check.Fail(name, std::format("the folder holds:{}", held));
}

// A complete pack of made-up strings that records the supported release's
// identity: it is compared, not proved.
std::vector<std::byte> CompletePack(std::string_view mutexName, std::string_view className = "window class")
{
    std::string payload(140, '\0');
    payload.replace(0, mutexName.size(), mutexName);
    payload.replace(20, 5, "first");
    payload.replace(80, 5, "Error");
    payload.replace(88, 6, "second");
    std::string windowClass(256, '\0');
    windowClass.replace(0, className.size(), className);
    const std::vector<std::byte> bytes = Bytes(payload);
    const std::vector<std::byte> classBytes = Bytes(windowClass);
    const std::array<fileformat::PackWriteEntry, 2> entries{
        {{{'I', 'N', 'S', 'T'}, 1, bytes}, {{'W', 'N', 'D', 'C'}, 1, classBytes}}};
    return fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), entries);
}

void RefusesToInstall(Checks& check, std::string_view name, const fs::path& folder, std::span<const std::byte> pack,
                      const fileformat::ValidatedPack& expected, InstallProblem problem)
{
    try
    {
        setup::InstallDataPack(folder, pack, expected);
        check.Fail(name, "was installed");
    }
    catch (const setup::InstallError& error)
    {
        if (error.Problem() != problem)
            check.Fail(name, std::format("failed at another step: {}", error.what()));
    }
    catch (const std::exception& error)
    {
        check.Fail(name, std::format("threw another error: {}", error.what()));
    }
}

// The pack is written, renamed over an existing one and read back; no staged
// file is left.
void Installs(Checks& check)
{
    const Folder folder;
    const std::vector<std::byte> pack = CompletePack("mutex");
    const fileformat::ValidatedPack expected = fileformat::ValidatePack(pack);
    setup::InstallDataPack(folder.path, pack, expected);
    HoldsNames(check, "installed: names", folder, std::set<std::string>{std::string(packName)});
    check.Equal("installed: bytes", true, folder.Read(packName) == pack);
    check.Run("installed: validates", [&] { fileformat::OpenAndValidatePack(folder.path / packName); });

    const std::vector<std::byte> other = CompletePack("other mutex");
    folder.Write(stagedName, Bytes("left from before"));
    setup::InstallDataPack(folder.path, other, fileformat::ValidatePack(other));
    HoldsNames(check, "replaced: names", folder, std::set<std::string>{std::string(packName)});
    check.Equal("replaced: bytes", true, folder.Read(packName) == other);
}

// A staged file that does not validate, or holds other values, is removed and
// the existing pack is left as it was.
void KeepsTheExistingPack(Checks& check)
{
    const Folder folder;
    const std::vector<std::byte> old = Bytes("the existing pack");
    folder.Write(packName, old);
    const std::vector<std::byte> pack = CompletePack("mutex");
    const fileformat::ValidatedPack expected = fileformat::ValidatePack(pack);

    RefusesToInstall(check, "not a pack", folder.path, Bytes("not a pack"), expected, InstallProblem::StagedInvalid);
    HoldsNames(check, "not a pack: names", folder, std::set<std::string>{std::string(packName)});
    check.Equal("not a pack: existing pack", true, folder.Read(packName) == old);

    RefusesToInstall(check, "other values", folder.path, CompletePack("other mutex"), expected,
                     InstallProblem::StagedInvalid);
    HoldsNames(check, "other values: names", folder, std::set<std::string>{std::string(packName)});
    check.Equal("other values: existing pack", true, folder.Read(packName) == old);

    RefusesToInstall(check, "other class name", folder.path, CompletePack("mutex", "other window class"), expected,
                     InstallProblem::StagedInvalid);
    HoldsNames(check, "other class name: names", folder, std::set<std::string>{std::string(packName)});
    check.Equal("other class name: existing pack", true, folder.Read(packName) == old);

    RefusesToInstall(check, "truncated", folder.path, std::span(pack).first(pack.size() - 1), expected,
                     InstallProblem::StagedInvalid);
    HoldsNames(check, "truncated: names", folder, {std::string(packName)});
    check.Equal("truncated: existing pack", true, folder.Read(packName) == old);
}

// A step that cannot write leaves what was there.
void ReportsFileFailures(Checks& check)
{
    const std::vector<std::byte> pack = CompletePack("mutex");
    const fileformat::ValidatedPack expected = fileformat::ValidatePack(pack);

    const Folder staged;
    fs::create_directory(staged.path / stagedName);
    RefusesToInstall(check, "staged name is a folder", staged.path, pack, expected, InstallProblem::StagedWrite);
    HoldsNames(check, "staged name is a folder: names", staged, std::set<std::string>{std::string(stagedName)});
    check.Equal("staged name is a folder: still a folder", true, fs::is_directory(staged.path / stagedName));

    const Folder target;
    fs::create_directory(target.path / packName);
    target.Write(std::string(packName) + "/kept", Bytes("kept"));
    RefusesToInstall(check, "pack name is a folder", target.path, pack, expected, InstallProblem::Replace);
    HoldsNames(check, "pack name is a folder: names", target, std::set<std::string>{std::string(packName)});
    check.Equal("pack name is a folder: kept", true, target.Read(std::string(packName) + "/kept") == Bytes("kept"));

    const Folder absent;
    RefusesToInstall(check, "no folder", absent.path / "absent", pack, expected, InstallProblem::StagedWrite);
}

SetupExit Run(std::vector<fs::path> arguments, std::string* messages = nullptr)
{
    std::ostringstream out;
    const SetupExit status = setup::RunSetup(arguments, out);
    if (messages != nullptr)
        *messages = out.str();
    return status;
}

void CheckExit(Checks& check, std::string_view name, SetupExit expected, SetupExit actual)
{
    check.Equal(name, static_cast<int>(expected), static_cast<int>(actual));
}

// vegas-setup takes the install folder only, and writes nothing to it unless
// the executable there is a supported original release.
void RunsSetup(Checks& check)
{
    const Folder folder;
    std::string messages;
    CheckExit(check, "no argument", SetupExit::Usage, Run({}, &messages));
    check.Equal("no argument: message", true,
                messages.find("usage: vegas-setup <install folder>") != std::string::npos);
    CheckExit(check, "two arguments", SetupExit::Usage, Run({folder.path, folder.path}));

    CheckExit(check, "no executable", SetupExit::ExecutableMissing, Run({folder.path}));
    HoldsNames(check, "no executable: names", folder, std::set<std::string>{});
    CheckExit(check, "no folder", SetupExit::ExecutableMissing, Run({folder.path / "absent"}));

    const std::vector<std::byte> old = Bytes("the existing pack");
    folder.Write(packName, old);
    const std::set<std::string> both{std::string(executableName), std::string(packName)};

    fs::create_directory(folder.path / executableName);
    CheckExit(check, "executable is a folder", SetupExit::ExecutableUnreadable, Run({folder.path}));
    fs::remove(folder.path / executableName);

    folder.Write(executableName, Bytes("not an executable"));
    CheckExit(check, "not an executable", SetupExit::NotAnExecutable, Run({folder.path}));
    HoldsNames(check, "not an executable: names", folder, both);

    pe_fixture::Layout x64 = pe_fixture::Typical();
    x64.machine = 0x8664;
    folder.Write(executableName, pe_fixture::Build(x64));
    CheckExit(check, "64-bit executable", SetupExit::NotAnExecutable, Run({folder.path}));

    folder.Write(executableName, pe_fixture::Build(pe_fixture::Typical()));
    CheckExit(check, "synthetic executable", SetupExit::UnsupportedOriginal, Run({folder.path}, &messages));
    check.Equal("synthetic executable: message", true,
                messages.find("FalloutNV.exe is not the executable of a supported original release") !=
                    std::string::npos);
    HoldsNames(check, "synthetic executable: names", folder, both);
    check.Equal("synthetic executable: existing pack", true, folder.Read(packName) == old);
}

} // namespace

int main()
{
    Checks check("setup install");
    check.Run("installs", [&] { Installs(check); });
    check.Run("keeps the existing pack", [&] { KeepsTheExistingPack(check); });
    check.Run("file failures", [&] { ReportsFileFailures(check); });
    check.Run("runs setup", [&] { RunsSetup(check); });
    return check.ExitCode();
}
