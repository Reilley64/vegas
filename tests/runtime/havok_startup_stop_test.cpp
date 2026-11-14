#include "havok/PhysicsMemory.h"
#include "havok/hkBaseSystem.h"
#include "havok/hkMonitorStream.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_00c85000.h"

#include <csignal>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#ifndef _WIN32
#include <unistd.h>
#endif

void InitHavokPhysics();
alignas(16) char g_acStackBufferC68[0x60000];
unsigned int currentAllocationContext;
uintptr_t DAT_01268418;
#ifdef _WIN32
unsigned long DAT_0126835c;
#endif

void FUN_0084cbd0(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    std::vfprintf(stderr, format, arguments);
    va_end(arguments);
}
void Receive(const char*, void*) {}
void ObserveAbort(int)
{
#ifndef _WIN32
    const char text[] = "actual-game-entry-abort\n";
    (void)!write(STDERR_FILENO, text, sizeof(text) - 1);
#endif
    // Return so the real abort terminates, rather than escaping through a test hook.
}
int main(int argc, char** argv)
{
    if (argc != 2)
        return 2;
    std::signal(SIGABRT, ObserveAbort);
    if (std::strcmp(argv[1], "direct") == 0)
    {
        auto* router = g_havokPhysicsMemory.Initialize(g_acStackBufferC68, sizeof(g_acStackBufferC68));
        if (!router)
            return 3;
        FUN_00cbbfb0(reinterpret_cast<uintptr_t>(g_havokPhysicsMemory.GetSystem()));
        if (fnv_00cbbb10::FUN_00cbbb10(router, Receive, nullptr) != 0)
            return 4;
    }
    InitHavokPhysics();
    std::fputs("ERROR: incomplete game entry returned\n", stderr);
    ShutdownIfInitialized();
    g_havokPhysicsMemory.Shutdown();
    FUN_00cbbfb0(0);
    return 1;
}
