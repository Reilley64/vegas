#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fnv/second_window_check.h"

#include <cstring>
#include <format>
#include <string>
#include <string_view>
#include <vector>

namespace
{

using fnv::startup::SecondWindowOutcome;

// A made-up class name: not a string of the original release.
constexpr std::string_view className = "test window class";

fileformat::MainWindowClass WindowClass()
{
    fileformat::MainWindowClass windowClass{};
    std::memcpy(windowClass.className.data(), className.data(), className.size());
    return windowClass;
}

// The two calls the decision may make, recorded instead of made. No real
// window is looked for or touched.
int s_window;
void* s_found;
std::vector<const char*> s_searched;
std::vector<void*> s_foreground;

void* FindRecorded(const char* name)
{
    s_searched.push_back(name);
    return s_found;
}

int ForegroundRecorded(void* window)
{
    s_foreground.push_back(window);
    return 1;
}

const char* Name(SecondWindowOutcome outcome)
{
    switch (outcome)
    {
    case SecondWindowOutcome::Continue:
        return "Continue";
    case SecondWindowOutcome::AlreadyOpen:
        return "AlreadyOpen";
    }
    return "unknown";
}

// Runs the decision with `found` as the window the search returns and checks
// its outcome, that it searched once for the field's own class name and
// which window, if any, it brought to the foreground.
void Expect(Checks& checks, std::string_view test, void* found, SecondWindowOutcome expected)
{
    s_found = found;
    s_searched.clear();
    s_foreground.clear();
    const fileformat::MainWindowClass windowClass = WindowClass();
    const SecondWindowOutcome outcome = fnv::startup::CheckSecondWindow(windowClass, FindRecorded, ForegroundRecorded);
    if (outcome != expected)
        checks.Fail(test, std::format("expected {}, got {}", Name(expected), Name(outcome)));
    checks.Equal(std::format("{}: searches", test), std::size_t{1}, s_searched.size());
    if (s_searched.size() == 1)
    {
        checks.Equal(std::format("{}: the field's own storage searched for", test), true,
                     s_searched[0] == windowClass.className.data());
        checks.Equal(std::format("{}: class name searched for", test), std::string(className),
                     std::string(s_searched[0]));
    }
    if (found == nullptr)
    {
        checks.Equal(std::format("{}: windows brought to the foreground", test), std::size_t{0}, s_foreground.size());
        return;
    }
    checks.Equal(std::format("{}: windows brought to the foreground", test), std::size_t{1}, s_foreground.size());
    if (s_foreground.size() == 1)
        checks.Equal(std::format("{}: the window found", test), true, s_foreground[0] == found);
}

} // namespace

int main()
{
    Checks checks("second-window check");
    checks.Run("no window", [&] { Expect(checks, "no window", nullptr, SecondWindowOutcome::Continue); });
    checks.Run("a window", [&] { Expect(checks, "a window", &s_window, SecondWindowOutcome::AlreadyOpen); });
    return checks.ExitCode();
}
