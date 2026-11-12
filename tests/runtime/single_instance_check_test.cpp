#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fnv/single_instance_check.h"

#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <format>
#include <string>
#include <string_view>
#include <vector>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif

namespace
{

using fnv::startup::SingleInstanceOutcome;

// Made-up strings: none is a string of the original release.
constexpr std::string_view firstText = "test first message";
constexpr std::string_view caption = "Test";
constexpr std::string_view secondText = "test second message";

template <std::size_t N>
void Fill(std::array<char, N>& field, std::string_view text)
{
    field = {};
    std::memcpy(field.data(), text.data(), text.size());
}

fileformat::SingleInstanceStrings Strings(std::string_view mutexName)
{
    fileformat::SingleInstanceStrings strings;
    Fill(strings.mutexName, mutexName);
    Fill(strings.firstMessageText, firstText);
    Fill(strings.messageCaption, caption);
    Fill(strings.secondMessageText, secondText);
    return strings;
}

// The two calls the decision may make, recorded instead of made.
struct Box
{
    std::string text;
    std::string caption;
    unsigned int type;
};
std::vector<Box> s_boxes;
int s_queries;
bool s_remote;

int RecordBox(const char* text, const char* boxCaption, unsigned int type)
{
    s_boxes.push_back({text, boxCaption, type});
    return 1;
}

bool RemoteSession()
{
    ++s_queries;
    return s_remote;
}

const char* Name(SingleInstanceOutcome outcome)
{
    switch (outcome)
    {
    case SingleInstanceOutcome::Continue:
        return "Continue";
    case SingleInstanceOutcome::AlreadyRunning:
        return "AlreadyRunning";
    case SingleInstanceOutcome::RemoteSession:
        return "RemoteSession";
    }
    return "unknown";
}

// Runs the decision on `createMutexError` with the session reported as
// `remote` and checks its outcome, the box it showed and how often it asked
// whether the session is remote.
void Expect(Checks& checks, std::string_view test, unsigned long createMutexError, bool remote,
            SingleInstanceOutcome expected, std::string_view expectedText, int expectedQueries)
{
    s_boxes.clear();
    s_queries = 0;
    s_remote = remote;
    const SingleInstanceOutcome outcome =
        fnv::startup::CheckSingleInstance(Strings("test mutex"), createMutexError, RemoteSession, RecordBox);
    if (outcome != expected)
        checks.Fail(test, std::format("expected {}, got {}", Name(expected), Name(outcome)));
    checks.Equal(std::format("{}: questions about the session", test), expectedQueries, s_queries);
    if (expectedText.empty())
    {
        checks.Equal(std::format("{}: message boxes", test), std::size_t{0}, s_boxes.size());
        return;
    }
    if (s_boxes.size() != 1)
    {
        checks.Fail(test, std::format("expected one message box, got {}", s_boxes.size()));
        return;
    }
    checks.Equal(std::format("{}: text", test), std::string(expectedText), s_boxes[0].text);
    checks.Equal(std::format("{}: caption", test), std::string(caption), s_boxes[0].caption);
    checks.Equal(std::format("{}: type", test), 0u, s_boxes[0].type);
}

#ifdef _WIN32
// The child's side of the two-process test: it makes the calls that main
// makes, CreateMutexA on the name and then the decision on its last error,
// with the box recorded and the session reported as local. It exits 0 when
// the outcome is the one expected and the box is the one expected.
int RunInstance(std::string_view mutexName, bool expectRunning)
{
    const fileformat::SingleInstanceStrings strings = Strings(mutexName);
    s_remote = false;
    CreateMutexA(nullptr, FALSE, strings.mutexName.data());
    const SingleInstanceOutcome outcome =
        fnv::startup::CheckSingleInstance(strings, GetLastError(), RemoteSession, RecordBox);
    const SingleInstanceOutcome expected =
        expectRunning ? SingleInstanceOutcome::AlreadyRunning : SingleInstanceOutcome::Continue;
    const std::size_t expectedBoxes = expectRunning ? 1 : 0;
    if (outcome != expected || s_boxes.size() != expectedBoxes ||
        (expectRunning && (s_boxes[0].text != firstText || s_boxes[0].caption != caption)))
    {
        std::fprintf(stderr, "instance: expected %s with %zu box, got %s with %zu\n", Name(expected), expectedBoxes,
                     Name(outcome), s_boxes.size());
        return 1;
    }
    return 0;
}

// Runs this program again with `mode` and the mutex name and returns its exit
// code, or -1 when it cannot be started or does not end within 30 seconds.
long RunChild(Checks& checks, std::string_view mode, std::string_view mutexName)
{
    char program[MAX_PATH];
    const DWORD length = GetModuleFileNameA(nullptr, program, MAX_PATH);
    if (length == 0 || length == MAX_PATH)
    {
        checks.Fail(mode, "the test cannot find its own executable");
        return -1;
    }
    std::string commandLine = std::format("\"{}\" {} {}", program, mode, mutexName);
    STARTUPINFOA startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    if (!CreateProcessA(program, commandLine.data(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startup,
                        &process))
    {
        checks.Fail(mode, std::format("the second process did not start: {}", GetLastError()));
        return -1;
    }
    CloseHandle(process.hThread);
    long result = -1;
    DWORD code = 0;
    if (WaitForSingleObject(process.hProcess, 30000) != WAIT_OBJECT_0)
    {
        checks.Fail(mode, "the second process did not end within 30 seconds");
        TerminateProcess(process.hProcess, 1);
    }
    else if (GetExitCodeProcess(process.hProcess, &code))
        result = static_cast<long>(code);
    CloseHandle(process.hProcess);
    return result;
}
#endif

} // namespace

int main(int argc, char** argv)
{
#ifdef _WIN32
    if (argc == 3 && std::strcmp(argv[1], "--second-instance") == 0)
        return RunInstance(argv[2], true);
    if (argc == 3 && std::strcmp(argv[1], "--first-instance") == 0)
        return RunInstance(argv[2], false);
#else
    static_cast<void>(argc);
    static_cast<void>(argv);
#endif

    Checks checks("single-instance check");
    constexpr unsigned long noError = 0;
    constexpr unsigned long accessDenied = 5; // ERROR_ACCESS_DENIED
    const std::string_view none;

    checks.Run("first instance, local session", [&] {
        Expect(checks, "first instance, local session", noError, false, SingleInstanceOutcome::Continue, none, 1);
    });
    checks.Run("second instance, local session", [&] {
        Expect(checks, "second instance, local session", 0xb7, false, SingleInstanceOutcome::AlreadyRunning,
               firstText, 0);
    });
    checks.Run("second instance, remote session", [&] {
        Expect(checks, "second instance, remote session", 0xb7, true, SingleInstanceOutcome::AlreadyRunning,
               firstText, 0);
    });
    checks.Run("first instance, remote session", [&] {
        Expect(checks, "first instance, remote session", noError, true, SingleInstanceOutcome::RemoteSession,
               secondText, 1);
    });
    // Only ERROR_ALREADY_EXISTS refuses: another error of CreateMutexA goes on
    // to the remote-session check.
    checks.Run("other error, local session", [&] {
        Expect(checks, "other error, local session", accessDenied, false, SingleInstanceOutcome::Continue, none, 1);
    });
    checks.Run("other error, remote session", [&] {
        Expect(checks, "other error, remote session", accessDenied, true, SingleInstanceOutcome::RemoteSession,
               secondText, 1);
    });

#ifdef _WIN32
    // A second process: this one holds the mutex, the child makes main's
    // calls on the same name and must decide AlreadyRunning. After this one
    // closes its handle no process holds the mutex, and a child must decide
    // Continue. Every box is recorded, so none can appear.
    checks.Equal("ERROR_ALREADY_EXISTS", static_cast<unsigned long>(ERROR_ALREADY_EXISTS),
                 fnv::startup::mutexAlreadyExistsError);
    checks.Equal("MB_OK", static_cast<unsigned int>(MB_OK), fnv::startup::singleInstanceMessageType);
    checks.Run("second process", [&] {
        const std::string name = std::format("vegas-sit-{:08x}", GetCurrentProcessId());
        const HANDLE held = CreateMutexA(nullptr, FALSE, name.c_str());
        if (held == nullptr || GetLastError() == ERROR_ALREADY_EXISTS)
        {
            checks.Fail("second process", "the test could not create a new mutex");
            return;
        }
        checks.Equal("second process: exit code", 0L, RunChild(checks, "--second-instance", name));
        CloseHandle(held);
        checks.Equal("first process: exit code", 0L, RunChild(checks, "--first-instance", name));
    });
#endif
    return checks.ExitCode();
}
