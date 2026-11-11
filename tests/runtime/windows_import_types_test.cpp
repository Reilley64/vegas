// Type pin. Game units call these Windows functions by the name the Windows
// SDK headers declare. Each unit used to call through a pointer variable of
// its own for the import, declared with the type stated here. The call was
// changed only because the header's function has exactly that type, so no
// argument and no result is converted differently. This test fails to build
// if a header's type stops matching. It runs nothing of the game.

#include <windows.h>
#include <objbase.h>

#include <type_traits>
#include <utility>

namespace
{
static_assert(std::is_same_v<decltype(&DebugBreak), void (*)()>);
static_assert(std::is_same_v<decltype(&TlsAlloc), unsigned long (*)()>);
static_assert(std::is_same_v<decltype(&TlsSetValue), int (*)(unsigned long, void*)>);
static_assert(std::is_same_v<decltype(&EnterCriticalSection), void (*)(CRITICAL_SECTION*)>);
static_assert(std::is_same_v<decltype(&LeaveCriticalSection), void (*)(CRITICAL_SECTION*)>);
static_assert(std::is_same_v<decltype(&CoTaskMemFree), void (*)(void*)>);
static_assert(std::is_same_v<decltype(&FlushFileBuffers), int (*)(void*)>);
static_assert(std::is_same_v<decltype(&OutputDebugStringA), void (*)(const char*)>);
static_assert(std::is_same_v<decltype(&FindClose), int (*)(void*)>);
static_assert(std::is_same_v<decltype(&CopyFileA), int (*)(const char*, const char*, int)>);

// InterlockedExchangeAdd is a compiler intrinsic on this build target, so it
// has no address. The units' variable was long (*)(volatile long*, long).
static_assert(std::is_same_v<decltype(InterlockedExchangeAdd(std::declval<volatile long*>(), std::declval<long>())), long>);
} // namespace

int main()
{
    return 0;
}
