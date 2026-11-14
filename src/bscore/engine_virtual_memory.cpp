#include "fnv/memory/engine_heap.h"
#include <limits>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace fnv::memory {
std::size_t NativePageSize() noexcept
{
#ifdef _WIN32
    SYSTEM_INFO info{};
    GetSystemInfo(&info);
    return info.dwPageSize;
#else
    const auto size = sysconf(_SC_PAGESIZE);
    return size > 0 ? static_cast<std::size_t>(size) : 0;
#endif
}
namespace {
bool RoundPages(std::size_t bytes, std::size_t& rounded) noexcept
{
    const auto page = NativePageSize();
    if (!page || bytes > (std::numeric_limits<std::size_t>::max)() - (page - 1)) return false;
    rounded = (bytes + page - 1) / page * page;
    return true;
}
}
// Native OS implementations of 00aa79a0 (reserve/commit), 00aa7a50
// (commit growth), and 00aa7a30 (release). A failed commit never publishes
// an inaccessible reservation as a usable heap.
bool VirtualRegion::Reserve(std::size_t reserve, std::size_t commit) noexcept
{
    if (base || !RoundPages(reserve, reserve) || !RoundPages(commit, commit) || !reserve || commit > reserve)
        return false;
#ifdef _WIN32
    auto* memory = static_cast<std::byte*>(VirtualAlloc(nullptr, reserve, MEM_RESERVE, PAGE_READWRITE));
    if (!memory) return false;
#else
    void* raw = mmap(nullptr, reserve, PROT_NONE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (raw == MAP_FAILED) return false;
    auto* memory = static_cast<std::byte*>(raw);
#endif
    base = memory;
    reserved = reserve;
    if (!Commit(commit)) { Release(); return false; }
    return true;
}
bool VirtualRegion::Commit(std::size_t bytes) noexcept
{
    if (!base || !RoundPages(bytes, bytes) || bytes > reserved) return false;
    if (bytes <= committed) return true;
    if (!CommitRange(committed, bytes - committed)) return false;
    committed = bytes;
    return true;
}
bool VirtualRegion::CommitRange(std::size_t offset, std::size_t bytes) noexcept
{
    const auto page = NativePageSize();
    if (!base || !page || offset % page || bytes % page ||
        offset > reserved || bytes > reserved - offset) return false;
    if (!bytes) return true;
#ifdef _WIN32
    return VirtualAlloc(base + offset, bytes, MEM_COMMIT, PAGE_READWRITE) != nullptr;
#else
    return mprotect(base + offset, bytes, PROT_READ | PROT_WRITE) == 0;
#endif
}
bool VirtualRegion::DecommitRange(std::size_t offset, std::size_t bytes) noexcept
{
    const auto page = NativePageSize();
    if (!base || !page || offset % page || bytes % page ||
        offset > reserved || bytes > reserved - offset) return false;
    if (!bytes) return true;
#ifdef _WIN32
    return VirtualFree(base + offset, bytes, MEM_DECOMMIT) != 0;
#else
    if (mprotect(base + offset, bytes, PROT_NONE)) return false;
    // Contents are no longer live. The kernel may discard the physical pages.
    madvise(base + offset, bytes, MADV_DONTNEED);
    return true;
#endif
}
void VirtualRegion::Trim(std::size_t bytes) noexcept
{
    if (!RoundPages(bytes, bytes) || bytes >= committed) return;
    if (DecommitRange(bytes, committed - bytes)) committed = bytes;
}
void VirtualRegion::Release() noexcept
{
    if (base) {
#ifdef _WIN32
        VirtualFree(base, 0, MEM_RELEASE);
#else
        munmap(base, reserved);
#endif
    }
    base = nullptr;
    reserved = committed = 0;
}
}
