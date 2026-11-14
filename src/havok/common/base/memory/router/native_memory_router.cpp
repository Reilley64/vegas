#include "havok/hkMemoryRouter.h"

hkMemoryRouter::hkMemoryRouter()
{
    Clear();
}

// The memory system assigns m_threadSlot when it attaches the router.
// @fnv 0x00c85770
hkMemoryRouter* hkMemoryRouter::Clear()
{
    m_stackCurrent = nullptr;
    m_stack04 = nullptr;
    m_stack08 = nullptr;
    m_temp = nullptr;
    m_heap = nullptr;
    m_debug = nullptr;
    m_solver = nullptr;
    m_allocator = nullptr;
    return this;
}
