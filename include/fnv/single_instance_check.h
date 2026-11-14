#pragma once

#include "fileformat/pack_catalogue.h"

// The decision of the single-instance and remote-session checks, the first
// statements of WinMain (0x0086a850), on C1's strings
// (docs/data-pack-startup.md). The caller makes the calls whose results the
// decision reads and passes the two calls it may make; the decision makes no
// system call itself.
namespace fnv::startup
{
enum class SingleInstanceOutcome
{
    Continue,       // neither check refused: the statements after them run
    AlreadyRunning, // the mutex existed: the first message box was shown
    RemoteSession,  // a remote session: the second message box was shown
};

// The error code that the check compares the last error of CreateMutexA with,
// ERROR_ALREADY_EXISTS.
inline constexpr unsigned long mutexAlreadyExistsError = 0xb7;

// The type of both message boxes, MB_OK.
inline constexpr unsigned int singleInstanceMessageType = 0;

// Returns whether the process runs in a remote session. Production passes
// GetSystemMetrics(SM_REMOTESESSION) != 0.
using RemoteSessionQuery = bool (*)();

// Shows a message box with no owner window. Production passes MessageBoxA
// with a null owner; the result is not read.
using MessageBoxFunction = int (*)(const char* text, const char* caption, unsigned int type);

// `createMutexError` is the last error just after CreateMutexA on
// strings.mutexName. When it is mutexAlreadyExistsError the decision shows the
// first message text and returns AlreadyRunning, without asking whether the
// session is remote. Otherwise, when `isRemoteSession` returns true, it shows
// the second message text and returns RemoteSession. Otherwise it returns
// Continue and shows nothing. Both boxes have the caption and
// singleInstanceMessageType. WinMain returns 0 after either box.
[[nodiscard]] SingleInstanceOutcome CheckSingleInstance(const fileformat::SingleInstanceStrings& strings,
                                                        unsigned long createMutexError,
                                                        RemoteSessionQuery isRemoteSession,
                                                        MessageBoxFunction showMessage);
}
