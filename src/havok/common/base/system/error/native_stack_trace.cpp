#include "havok/hkBaseSystem.h"

#include <cstdio>
#ifdef _WIN32
#include <windows.h>
#else
#include <execinfo.h>
#endif

namespace havok::base
{
void WriteStackTrace(ErrorCallback callback, void* user)
{
    void* frames[20];
#ifdef _WIN32
    const int count = CaptureStackBackTrace(0, 20, frames, nullptr);
#else
    const int count = backtrace(frames, 20);
#endif
    if (count <= 2)
        return;
    callback("Stack trace is:\n", user);
    for (int i = 2; i < count; ++i)
    {
        char text[64];
        std::snprintf(text, sizeof(text), "%p\n", frames[i]);
        callback(text, user);
    }
}
}
