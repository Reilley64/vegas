#include "GameTimerRecord.h"
#include "fileformat/pack_catalogue.h"
#include "fnv/data_pack_startup.h"
#include "fnv/game_timer.h"
#include "fnv/memory/process_startup.h"
#include "fnv/single_instance_check.h"

#include <cstdio>
#include <filesystem>
#include <optional>
#include <string>
#include <variant>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace
{
// The folder of the running executable, where setup installs the data pack.
// ADR 0001 resolves the pack there, never in the working directory.
std::optional<std::filesystem::path> ExecutableFolder()
{
    std::wstring name(MAX_PATH, L'\0');
    for (;;)
    {
        const DWORD length = GetModuleFileNameW(nullptr, name.data(), static_cast<DWORD>(name.size()));
        if (length == 0)
            return std::nullopt;
        if (length < name.size())
        {
            name.resize(length);
            return std::filesystem::path(name).parent_path();
        }
        name.resize(name.size() * 2);
    }
}

// The two calls that the single-instance check may make, as WinMain makes
// them.
bool IsRemoteSession()
{
    return GetSystemMetrics(SM_REMOTESESSION) != 0;
}

int ShowMessageBox(const char* text, const char* caption, unsigned int type)
{
    return MessageBoxA(nullptr, text, caption, type);
}
}

int main()
{
    if (!fnv::memory::StartProcessMemory())
        return 1;
    fnv::timer::Start(GameTimerTick());
    // A failed pack stage is reported on the standard error stream, never in
    // a message box, and ends the process with exit code 2.
    const std::optional<std::filesystem::path> folder = ExecutableFolder();
    if (!folder)
    {
        std::fputs("The folder of the executable cannot be found\n", stderr);
        return 2;
    }
    const fnv::startup::DataPackLoad load = fnv::startup::LoadDataPack(*folder);
    if (const std::string* failure = std::get_if<std::string>(&load))
    {
        std::fputs(failure->c_str(), stderr);
        return 2;
    }
    // The first statements of WinMain (0x0086a850), on the strings the pack
    // stage published: the single-instance and remote-session checks. The
    // mutex handle is never closed, so the process holds it until it ends.
    const fileformat::SingleInstanceStrings& singleInstance = std::get_if<0>(&load)->get();
    CreateMutexA(nullptr, FALSE, singleInstance.mutexName.data());
    if (fnv::startup::CheckSingleInstance(singleInstance, GetLastError(), IsRemoteSession, ShowMessageBox) !=
        fnv::startup::SingleInstanceOutcome::Continue)
        return 0; // WinMain returns 0 after either message box.
    // The statements of WinMain after the checks are not composed in main.
    return 0;
}
