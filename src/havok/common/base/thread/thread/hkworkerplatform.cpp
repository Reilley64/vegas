#include "havok/hkCpuJobThreadPool.h"

#include <mutex>
#include <new>
#include <stdexcept>
#ifdef _WIN32
#include "fnv/symbols_01268000.h"
#include <windows.h>
#endif
#if defined(__SSE__) || defined(_M_X64) || defined(_M_IX86)
#include <xmmintrin.h>
#endif

namespace
{
#ifdef _WIN32
std::once_flag workerSlot;
thread_local bool workerContextPublished = false;

void EnsureWorkerSlot()
{
    std::call_once(workerSlot, [] {
        DWORD slot = TlsAlloc();
        if (slot == TLS_OUT_OF_INDEXES)
            throw std::bad_alloc();
        g_dwTlsIndex = slot;
    });
}
#else
thread_local int workerNumber = 0;
#endif

}

void havok::threading::SetPlatformWorkerContext(int number, int processor)
{
#if defined(__SSE__) || defined(_M_X64) || defined(_M_IX86)
    _mm_setcsr(_mm_getcsr() | 0x8000);
#endif
#ifdef _WIN32
    EnsureWorkerSlot();
    SetThreadIdealProcessor(GetCurrentThread(), processor);
    if (!TlsSetValue(g_dwTlsIndex, reinterpret_cast<void*>(static_cast<std::uintptr_t>(number))))
        throw std::runtime_error("worker TLS initialization failed");
    workerContextPublished = true;
#else
    (void)processor;
    workerNumber = number;
#endif
}

void havok::threading::ClearPlatformWorkerContext()
{
#ifdef _WIN32
    if (!workerContextPublished)
        return;
    if (!TlsSetValue(g_dwTlsIndex, nullptr))
        std::terminate();
    workerContextPublished = false;
#else
    workerNumber = 0;
#endif
}
