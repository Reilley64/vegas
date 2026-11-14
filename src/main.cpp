#include "GameTimerRecord.h"
#include "fileformat/pack_catalogue.h"
#include "fnv/data_pack_startup.h"
#include "fnv/game_timer.h"
#include "fnv/memory/process_startup.h"
#include "fnv/second_window_check.h"
#include "fnv/single_instance_check.h"
#include "fnv/symbols_00c3b000.h"

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

// The two calls that the second-window check may make, as WinMain makes them.
void* FindWindowOfClass(const char* className)
{
    return FindWindowA(className, nullptr);
}

int BringToForeground(void* window)
{
    return SetForegroundWindow(static_cast<HWND>(window));
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
    const fnv::startup::PublishedPackValues& values = *std::get_if<0>(&load);
    const fileformat::SingleInstanceStrings& singleInstance = values.singleInstance.get();
    CreateMutexA(nullptr, FALSE, singleInstance.mutexName.data());
    if (fnv::startup::CheckSingleInstance(singleInstance, GetLastError(), IsRemoteSession, ShowMessageBox) !=
        fnv::startup::SingleInstanceOutcome::Continue)
        return 0; // WinMain returns 0 after either message box.
    // WinMain's statements S2 to S5, on the suffixes the stage published: each
    // log-path builder copies the user folder into its buffer and appends its
    // suffix. Of the eight statements WinMain runs between the checks above
    // and the next one, main composes these four; S1, S6, S7 and S8 are
    // skipped (docs/data-pack-startup.md).
    const fileformat::LogPathSuffixes& suffixes = values.logPathSuffixes.get();
    FUN_00c3bb90(suffixes.firstSuffix.data());
    fnv_00c3bbe0::FUN_00c3bbe0(suffixes.secondSuffix.data());
    FUN_00c3bc30(suffixes.thirdSuffix.data());
    fnv_00c3bc80::FUN_00c3bc80(suffixes.fourthSuffix.data());
    // WinMain's second-window check, on the class name the stage published.
    if (fnv::startup::CheckSecondWindow(values.mainWindowClass.get(), FindWindowOfClass, BringToForeground) !=
        fnv::startup::SecondWindowOutcome::Continue)
        return 0; // WinMain returns 0 after bringing the window to the foreground.
    // The statements of WinMain after the second-window check are not
    // composed in main.
    return 0;
}
