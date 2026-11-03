// Steam probe: starts the Steam API as app 22380 the way the game will, then sets
// one achievement, stores it, clears it and stores again, reporting each result.
// It writes everything to standard output and to steam-probe.log next to itself,
// because a program that Steam starts has no visible console.

#include <steam/steam_api.h>

#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <optional>
#include <string>
#include <thread>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

namespace
{
constexpr AppId_t kAppId = 22380;
constexpr const char* kDefaultAchievement = "A28"; // Caravan Master

#if defined(_WIN32)
constexpr const char* kBuildTarget = "windows-x64";
#elif defined(__APPLE__)
constexpr const char* kBuildTarget = "macos-arm64";
#else
constexpr const char* kBuildTarget = "linux-x64";
#endif

std::filesystem::path ExecutablePath()
{
#if defined(_WIN32)
    wchar_t buffer[MAX_PATH];
    GetModuleFileNameW(nullptr, buffer, MAX_PATH);
    return buffer;
#elif defined(__APPLE__)
    char buffer[4096];
    uint32_t size = sizeof(buffer);
    _NSGetExecutablePath(buffer, &size);
    return std::filesystem::canonical(buffer);
#else
    return std::filesystem::read_symlink("/proc/self/exe");
#endif
}

std::ofstream g_log;

void Report(const char* format, ...)
{
    char line[2048];
    va_list args;
    va_start(args, format);
    std::vsnprintf(line, sizeof(line), format, args);
    va_end(args);
    std::printf("%s\n", line);
    std::fflush(stdout);
    g_log << line << '\n' << std::flush;
}

const char* InitResultName(ESteamAPIInitResult result)
{
    switch (result)
    {
    case k_ESteamAPIInitResult_OK:
        return "OK";
    case k_ESteamAPIInitResult_FailedGeneric:
        return "FailedGeneric";
    case k_ESteamAPIInitResult_NoSteamClient:
        return "NoSteamClient";
    case k_ESteamAPIInitResult_VersionMismatch:
        return "VersionMismatch";
    }
    return "unknown";
}

const char* EnvOrUnset(const char* name)
{
    const char* value = std::getenv(name);
    return value ? value : "(unset)";
}

void SetSteamAppId()
{
#if defined(_WIN32)
    _putenv_s("SteamAppId", "22380");
#else
    setenv("SteamAppId", "22380", 1);
#endif
}

// Steam answers StoreStats with a UserStatsStored_t callback, and with a
// UserAchievementStored_t callback for each achievement it unlocks.
class StoreWatcher
{
public:
    std::optional<EResult> stored;

    STEAM_CALLBACK(StoreWatcher, OnStatsStored, UserStatsStored_t);
    STEAM_CALLBACK(StoreWatcher, OnAchievementStored, UserAchievementStored_t);
};

void StoreWatcher::OnStatsStored(UserStatsStored_t* callback)
{
    if (callback->m_nGameID == kAppId)
        stored = callback->m_eResult;
}

void StoreWatcher::OnAchievementStored(UserAchievementStored_t* callback)
{
    if (callback->m_nGameID == kAppId)
        Report("  UserAchievementStored_t: %s", callback->m_rgchAchievementName);
}

bool StoreAndWait(StoreWatcher& watcher)
{
    watcher.stored.reset();
    const bool called = SteamUserStats()->StoreStats();
    Report("StoreStats() = %s", called ? "true" : "false");
    if (!called)
        return false;

    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(15);
    while (!watcher.stored && std::chrono::steady_clock::now() < deadline)
    {
        SteamAPI_RunCallbacks();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    if (!watcher.stored)
    {
        Report("  UserStatsStored_t: none within 15 seconds");
        return false;
    }
    Report("  UserStatsStored_t: EResult %d%s", *watcher.stored, *watcher.stored == k_EResultOK ? " (OK)" : "");
    return *watcher.stored == k_EResultOK;
}

std::optional<bool> ReportAchievement(const char* name)
{
    bool achieved = false;
    const bool called = SteamUserStats()->GetAchievement(name, &achieved);
    Report("GetAchievement(\"%s\") = %s, achieved = %s", name, called ? "true" : "false", achieved ? "true" : "false");
    if (!called)
        return std::nullopt;
    return achieved;
}

int Probe(const char* achievement)
{
    Report("Build target: %s", kBuildTarget);
    Report("Working folder: %s", std::filesystem::current_path().string().c_str());
    Report("SteamAppId before the probe sets it: %s", EnvOrUnset("SteamAppId"));
    Report("SteamGameId: %s", EnvOrUnset("SteamGameId"));
    Report("STEAM_COMPAT_DATA_PATH (set by Proton): %s", EnvOrUnset("STEAM_COMPAT_DATA_PATH"));

    SetSteamAppId();
    Report("SteamAppId set to %s", EnvOrUnset("SteamAppId"));

    SteamErrMsg message = {};
    const ESteamAPIInitResult init = SteamAPI_InitEx(&message);
    Report("SteamAPI_Init: %s (%d)%s%s", InitResultName(init), init, message[0] ? ": " : "", message);
    if (init != k_ESteamAPIInitResult_OK)
        return 1;

    Report("SteamUtils()->GetAppID() = %u", SteamUtils()->GetAppID());

    int exitCode = 0;
    StoreWatcher watcher;
    const std::optional<bool> before = ReportAchievement(achievement);
    if (!before)
    {
        Report("Steam does not know the achievement \"%s\" for this app. Nothing was changed.", achievement);
        exitCode = 1;
    }
    else if (*before)
    {
        Report("\"%s\" is already unlocked on this account, so the probe leaves it alone.", achievement);
        Report("Run the probe again with the API name of a locked achievement as its argument.");
        exitCode = 1;
    }
    else
    {
        const bool set = SteamUserStats()->SetAchievement(achievement);
        Report("SetAchievement(\"%s\") = %s", achievement, set ? "true" : "false");
        const bool setStored = StoreAndWait(watcher);
        const std::optional<bool> afterSet = ReportAchievement(achievement);

        const bool cleared = SteamUserStats()->ClearAchievement(achievement);
        Report("ClearAchievement(\"%s\") = %s", achievement, cleared ? "true" : "false");
        const bool clearStored = StoreAndWait(watcher);
        const std::optional<bool> afterClear = ReportAchievement(achievement);

        if (!set || !setStored || afterSet != true || !cleared || !clearStored || afterClear != false)
            exitCode = 1;
        if (afterClear != false)
            Report("WARNING: \"%s\" may still be unlocked. Check the account's achievements page.", achievement);
    }

    SteamAPI_Shutdown();
    return exitCode;
}
} // namespace

int main(int argc, char** argv)
{
    const std::filesystem::path logPath = ExecutablePath().parent_path() / "steam-probe.log";
    g_log.open(logPath, std::ios::app);

    char started[64];
    const std::time_t now = std::time(nullptr);
    std::strftime(started, sizeof(started), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    Report("=== Steam probe, %s ===", started);
    Report("Log: %s", logPath.string().c_str());

    const int exitCode = Probe(argc > 1 ? argv[1] : kDefaultAchievement);
    Report("Result: %s", exitCode == 0 ? "PASS" : "FAIL");
    return exitCode;
}
