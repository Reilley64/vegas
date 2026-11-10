#include "NiFixedString.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/native_fixed_string.h"
#include "fnv/tls.h"

extern char* DAT_0109b220;
extern NiGlobalStringTable* DAT_011f42c0;

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <thread>
#include <utility>

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

namespace {
void ThrowWithLiveOwners()
{
    NiFixedString name("unwind-name");
    fnv::strings::GPUProgramCacheNames cache;
    CHECK(cache.Update(2, NiFixedString("ps_1_2"), "unwind-cache"));
    throw std::runtime_error("expected");
}
}

int main()
{
    CHECK(NiGlobalStringTable::Initialize());
    CHECK(DAT_011f42c0 == fnv::strings::TableIdentity());
    CHECK(DAT_0109b220 == NiGlobalStringTable::EmptyString());
    CHECK(fnv::strings::LiveNodeCount() == 0);

    const char* stale = nullptr;
    {
        NiFixedString sentinel;
        NiFixedString nullName(nullptr);
        NiFixedString empty("");
        CHECK(sentinel.m_kHandle == DAT_0109b220);
        CHECK(nullName.m_kHandle == DAT_0109b220);
        CHECK(empty.m_kHandle != DAT_0109b220);
        CHECK(std::strcmp(empty.m_kHandle, "") == 0);
        CHECK(fnv::strings::NodeIdentity(empty.m_kHandle));

        NiFixedString alpha("alpha");
        NiFixedString duplicate("alpha");
        NiFixedString beta("beta");
        CHECK(alpha.m_kHandle == duplicate.m_kHandle);
        CHECK(alpha.m_kHandle != beta.m_kHandle);
        CHECK(fnv::strings::NodeIdentity(alpha.m_kHandle) ==
              fnv::strings::NodeIdentity(duplicate.m_kHandle));
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 2);
        CHECK(reinterpret_cast<std::uintptr_t>(alpha.m_kHandle) > UINT32_MAX);

        NiFixedString copied(alpha);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 3);
        NiFixedString assigned("old-name");
        CHECK(fnv::strings::AssignObjectName(assigned, alpha));
        CHECK(assigned.m_kHandle == alpha.m_kHandle);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 4);
        NiFixedString moved(std::move(copied));
        CHECK(moved.m_kHandle == alpha.m_kHandle);
        CHECK(copied.m_kHandle == DAT_0109b220);

        fnv::strings::GPUProgramCacheNames cache;
        NiFixedString requested("ps_2_0");
        CHECK(cache.Update(2, requested, "shader-cache"));
        CHECK(std::strcmp(cache.name.m_kHandle, "shader-cache_ps_2_0_DX9.cache") == 0);
        CHECK(cache.profile.m_kHandle == requested.m_kHandle);
        CHECK(cache.fallbacks.Size() == 5);
        CHECK(std::strcmp(cache.fallbacks[0].m_kHandle, "ps_2_0") == 0);
        CHECK(std::strcmp(cache.fallbacks[4].m_kHandle, "ps_1_1") == 0);

        const char* oldName = cache.name.m_kHandle;
        const void* oldNameNode = fnv::strings::NodeIdentity(oldName);
        const char* oldFirst = cache.fallbacks[0].m_kHandle;
        const std::size_t oldCount = cache.fallbacks.Size();
        char* alphaHandle = alpha.m_kHandle;

        // The accepted manager has heap storage but no fixed pools yet. New
        // small intern/array allocations fail closed through the real route.
        g_memoryManager.InitializeHeaps();
        CHECK(!g_memoryManager.PoolsInitialized());
        g_tlsBlock.memoryContext = 23;
        bool assignmentFailed = false;
        try {
            alpha = "allocation-must-fail";
        } catch (const std::bad_alloc&) {
            assignmentFailed = true;
        }
        CHECK(assignmentFailed);
        CHECK(alpha.m_kHandle == alphaHandle);
        CHECK(g_tlsBlock.memoryContext == 23);
        CHECK(NiGlobalStringTable::AddString("new-intern-must-fail") == nullptr);
        CHECK(g_tlsBlock.memoryContext == 23);

        // Every value used by this update is already interned. The array
        // allocation is therefore the failing operation, and publication is
        // transactional.
        CHECK(!cache.Update(2, requested, "shader-cache"));
        CHECK(cache.name.m_kHandle == oldName);
        CHECK(fnv::strings::NodeIdentity(cache.name.m_kHandle) == oldNameNode);
        CHECK(cache.fallbacks.Size() == oldCount);
        CHECK(cache.fallbacks[0].m_kHandle == oldFirst);
        CHECK(g_tlsBlock.memoryContext == 23);
        CHECK(NiGlobalStringTable::AddString("alpha") == alphaHandle);
        CHECK(NiGlobalStringTable::Release(alphaHandle));

        g_memoryManager.FUN_00866770();
        CHECK(g_memoryManager.PoolsInitialized());
        CHECK(cache.Update(0, NiFixedString("vs_3_0"), "updated-cache"));
        CHECK(cache.fallbacks.Size() == 4);
        CHECK(std::strcmp(cache.name.m_kHandle, "updated-cache_vs_3_0_DX9.cache") == 0);

        NiFixedString concurrentRoot("concurrent-intern");
        const char* concurrentHandle = concurrentRoot.m_kHandle;
        std::array<const char*, 8> shared{};
        std::array<std::thread, 8> threads;
        for (std::size_t index = 0; index < threads.size(); ++index) {
            threads[index] = std::thread([&, index] {
                for (int iteration = 0; iteration < 500; ++iteration) {
                    NiFixedString value("concurrent-intern");
                    if (!shared[index])
                        shared[index] = value.m_kHandle;
                    CHECK(shared[index] == value.m_kHandle);
                    NiFixedString copy(value);
                    CHECK(copy.m_kHandle == value.m_kHandle);
                }
            });
        }
        for (auto& thread : threads)
            thread.join();
        for (std::size_t index = 0; index < shared.size(); ++index)
            CHECK(shared[index] == concurrentHandle);
        CHECK(fnv::strings::RefCount(concurrentHandle) == 1);
        concurrentRoot.Clear();
        CHECK(!fnv::strings::Owns(concurrentHandle));

        const std::size_t beforeUnwind = fnv::strings::LiveNodeCount();
        try {
            ThrowWithLiveOwners();
            CHECK(false);
        } catch (const std::runtime_error&) {}
        CHECK(fnv::strings::LiveNodeCount() == beforeUnwind);

        stale = beta.m_kHandle;
        CHECK(fnv::strings::Owns(stale));
        CHECK(!NiGlobalStringTable::Shutdown());
    }

    CHECK(!fnv::strings::Owns(stale));
    CHECK(!NiGlobalStringTable::Retain(stale));
    CHECK(!NiGlobalStringTable::Release(stale));
    CHECK(fnv::strings::LiveNodeCount() == 0);
    CHECK(ShutdownGlobalStringTable());
    CHECK(DAT_011f42c0 == nullptr);
    g_memoryManager.ShutdownHeaps();
    return 0;
}
