#pragma once

#include "fileformat/pack_catalogue.h"

// The decision of the second-window check of WinMain (0x0086a850), on the
// main window class (docs/data-pack-startup.md). WinMain makes the check
// after the single-instance and remote-session checks and eight statements
// that main does not compose. The caller passes the two calls the decision
// may make; the decision makes no system call itself.
namespace fnv::startup
{
enum class SecondWindowOutcome
{
    Continue,    // no window of the class was found: the statements after the check run
    AlreadyOpen, // a window of the class was found and brought to the foreground
};

// Finds a top-level window whose class name is `className`, whatever its
// title. Production passes FindWindowA with no window name. Returns the
// window, or null when there is none.
using FindWindowFunction = void* (*)(const char* className);

// Brings `window` to the foreground. Production passes SetForegroundWindow;
// the result is not read.
using SetForegroundFunction = int (*)(void* window);

// Calls `findWindow` once on windowClass.className. When it returns a window,
// the decision calls `setForeground` once on that window and returns
// AlreadyOpen; WinMain then returns 0. Otherwise it returns Continue and
// makes no other call.
[[nodiscard]] SecondWindowOutcome CheckSecondWindow(const fileformat::MainWindowClass& windowClass,
                                                    FindWindowFunction findWindow,
                                                    SetForegroundFunction setForeground);
}
