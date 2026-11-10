#include "fnv/memory/process_startup.h"

#include "fnv/decl/MemoryManager.h"
#include "fnv/ni_allocator.h"
#include "fnv/tls.h"

#include <new>

namespace
{
bool s_started;
}

bool fnv::memory::StartProcessMemory() noexcept
{
    if (s_started)
        return true;
    try
    {
        // 0x00aa39c0. Both entries leave an already started stage as it is.
        g_memoryManager.InitializeHeaps();
        g_memoryManager.FUN_00866770();
        ::g_tlsBlock.memoryContext = 0;
        // 0x00866690.
        PublishManagerNiAllocator();
    }
    catch (const std::bad_alloc&)
    {
        return false;
    }
    s_started = true;
    return true;
}

bool fnv::memory::ProcessMemoryStarted() noexcept
{
    return s_started;
}

void fnv::memory::RetireProcessMemory() noexcept
{
    RetireManagerNiAllocator();
    g_memoryManager.ShutdownHeaps();
    s_started = false;
}
