#include "havok/hkMonitorStream.h"
#include "fnv/symbols_00cb0000.h"

#include <algorithm>
#include <cstdlib>
#include <new>
#ifdef _WIN32
#include "fnv/symbols_01268000.h"
#include <mutex>
#include <windows.h>
#endif

namespace
{
#ifdef _WIN32
std::once_flag monitorSlot;
void EnsureMonitorSlot()
{
    std::call_once(monitorSlot, [] {
        const DWORD slot = TlsAlloc();
        if (slot == TLS_OUT_OF_INDEXES)
            throw std::bad_alloc();
        DAT_0126835c = slot;
    });
}

#else
thread_local SpawnedBuffer* monitor = nullptr;
void EnsureMonitorSlot() {}
#endif
}
namespace havok::base
{
void SetMonitor(SpawnedBuffer* value)
{
    EnsureMonitorSlot();
#ifdef _WIN32
    if (!TlsSetValue(DAT_0126835c, value))
        throw std::bad_alloc();
#else
    monitor = value;
#endif
}

SpawnedBuffer* GetMonitor()
{
#ifdef _WIN32
    EnsureMonitorSlot();
    return static_cast<SpawnedBuffer*>(TlsGetValue(DAT_0126835c));
#else
    return monitor;
#endif
}
}

SpawnedBuffer::~SpawnedBuffer()
{
    if (m_10 && m_00)
        allocator.bufFree(m_00, capacity);
}
void SpawnedBuffer::Resize(int bytes)
{
    if (bytes == capacity)
        return;
    // Keep every cursor within the allocation, including its reserved tail.
    int adjusted = std::max(bytes, 0x20);
    auto* storage = static_cast<char*>(allocator.bufAlloc(adjusted));
    if (!storage)
        throw std::bad_alloc();
    if (m_10 && m_00)
        allocator.bufFree(m_00, capacity);
    m_00 = storage;
    m_04 = storage;
    m_08 = storage + adjusted;
    m_0c = m_08 - 0x20;
    m_10 = 1;
    capacity = adjusted;
}

struct S_00cb0da0;
// @fnv 0x00cb0da0
void FUN_00cb0da0(S_00cb0da0* buffer)
{
    reinterpret_cast<SpawnedBuffer*>(buffer)->Reset();
}

namespace fnv_00cb0db0
{
// @fnv 0x00cb0db0
void FUN_00cb0db0()
{
    EnsureMonitorSlot();
    if (havok::base::GetMonitor())
        return;
    auto* router = static_cast<hkMemoryRouter*>(::FUN_00c85750());
    if (!router || !router->m_debug)
        throw std::bad_alloc();
    hkMemoryAllocator& allocator = *router->m_debug;
    void* storage = allocator.blockAlloc(sizeof(SpawnedBuffer));
    if (!storage)
        throw std::bad_alloc();
    auto* buffer = new (storage) SpawnedBuffer(allocator);
    try { havok::base::SetMonitor(buffer); }
    catch (...)
    {
        buffer->~SpawnedBuffer();
        allocator.blockFree(buffer, sizeof(SpawnedBuffer));
        throw;
    }
}
}

namespace fnv_00cb0df0
{
// @fnv 0x00cb0df0
void FUN_00cb0df0(SpawnedBuffer* buffer)
{
    if (!buffer)
        return;
    if (buffer != havok::base::GetMonitor())
        std::abort();
    hkMemoryAllocator& allocator = buffer->allocator;
    havok::base::SetMonitor(nullptr);
    buffer->~SpawnedBuffer();
    allocator.blockFree(buffer, sizeof(SpawnedBuffer));
}
}

// @fnv 0x00cb0e50
void ResizeBuffer(SpawnedBuffer* buffer, int bytes)
{
    if (bytes > 0)
        buffer->Resize(bytes);
    else
        fnv_00cb0df0::FUN_00cb0df0(buffer);
}
