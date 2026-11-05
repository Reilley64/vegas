// src/havok/common/base/thread/thread/win32/hkwin32thread.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/thread/win32/hkwin32thread.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#ifdef _WIN32
#include <windows.h>
class FUN_00d87920_cls
{
  public:
    void FUN_00d87920();

    HANDLE m_hHandle;
};

// @fnv 0x00d87920
void FUN_00d87920_cls::FUN_00d87920()
{
    if (m_hHandle != 0)
    {
        CloseHandle(m_hHandle);
        m_hHandle = 0;
    }
}

#endif

#include "havok/hkCpuJobThreadPool.h"
#ifdef _WIN32
#include "fnv/decl/Dispatcher.h"
#include "fnv/symbols_00cbb000.h"
#endif
#include <exception>
#include <stdexcept>

namespace
{
#ifdef _WIN32
void NameThread(std::thread& thread, const char* name)
{
    struct ThreadName
    {
        DWORD type;
        const char* name;
        DWORD id;
        DWORD flags;
    } info{0x1000, name, GetThreadId(thread.native_handle()), 0};
    __try
    {
        RaiseException(0x406D1388, 0, sizeof(info) / sizeof(ULONG_PTR), reinterpret_cast<const ULONG_PTR*>(&info));
    }
    __except (GetExceptionCode() == 0x406D1388 ? EXCEPTION_CONTINUE_EXECUTION : EXCEPTION_EXECUTE_HANDLER)
    {}
}

hkMemorySystem& PublishedWorkerMemory()
{
    auto* memory = reinterpret_cast<hkMemorySystem*>(FUN_00cbbfc0());
    if (!memory)
        throw std::logic_error("worker memory system is not initialized");
    return *memory;
}
#endif
}

// @fnv 0x00d87940
bool havok::threading::Thread::Start(Entry function, void* data, const char* name, unsigned long)
{
    if (thread.joinable())
        std::terminate();
    try
    {
        thread = std::thread([function, data] { function(data); });
    }
    catch (const std::system_error&) { return false; }
    catch (const std::bad_alloc&) { return false; }
#ifdef _WIN32
    NameThread(thread, name);
#else
    (void)name;
#endif
    return true;
}

void havok::threading::Thread::JoinAndClose()
{
    if (thread.joinable())
        thread.join();
}

int havok::threading::ProcessorCount()
{
    const auto count = std::thread::hardware_concurrency();
    return count ? static_cast<int>(count) : 1;
}


#ifdef _WIN32
// @fnv 0x00d2cde0
void hkCpuJobThreadPool::ProcessJobs(Dispatcher* jobs)
{
    if (!jobs)
        throw std::invalid_argument("missing job queue");
    ProcessWork([](void* queue) { static_cast<Dispatcher*>(queue)->FUN_00d051b0(); }, jobs);
}

hkCpuJobThreadPool::hkCpuJobThreadPool(const Cinfo& config)
    : hkCpuJobThreadPool(PublishedWorkerMemory(), config)
{}
#endif
