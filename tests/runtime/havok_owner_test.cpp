#include "fnv/decl/FUN_00cd0a60.h"
#include "havok/InlineStorageString.h"
#include "havok/PhysicsMemory.h"
#include "havok/TokenReader.h"
#include <algorithm>
#include "runtime/havok_memory_prerequisite.h"
#include "check.h"

#include <array>
#include <memory>
#include <latch>
#include <semaphore>
#include <cstring>
#include <new>
#include <string>
#include <thread>

class Backing final : public havok::native_memory::Allocator
{
  public:
    havok::native_memory::AlignedAllocator native;
    bool fail = false;
    int throwAfter = -1;
    int live = 0;
    void* Allocate(std::size_t bytes) override
    {
        if (fail)
            return nullptr;
        if (throwAfter == 0)
            throw std::bad_alloc();
        if (throwAfter > 0)
            --throwAfter;
        void* result = native.Allocate(bytes);
        if (result)
            ++live;
        return result;
    }
    void Free(void* block, std::size_t bytes) noexcept override
    {
        if (block)
            --live;
        native.Free(block, bytes);
    }
};

class InputStream final : public fnv_00dcc8e0::TokenStream
{
  public:
    explicit InputStream(std::string input) : input(std::move(input)) {}
    void v00() override {}
    void v01() override {}
    void v02() override {}
    void v03() override {}
    int v04(char* buffer, int count) override
    {
        const int available = std::min(count, static_cast<int>(input.size() - position));
        std::memcpy(buffer, input.data() + position, available);
        position += available;
        return available;
    }
    void v05(int count) override { position += count; }
    void v06() override {}
    void v07(int) override { saved = position; }
    void v08() override { position = saved; }
  private:
    std::string input;
    std::size_t position = 0;
    std::size_t saved = 0;
};

void ConcurrentOwners(Checks& checks)
{
    FUN_00cd0a60 system;
    hkMemoryRouter* main = system.MainInit(257, 3, 8192);
    checks.Equal("controller initialized", true, main != nullptr);
    std::array<std::thread, 31> workers;
    std::array<bool, 31> results{};
    std::latch ready(31);
    std::counting_semaphore<31> finish(0);
    for (int i = 0; i < 31; ++i)
        workers[i] = std::thread([&, i] {
            hkMemoryRouter router;
            bool good = system.InitializeThreadRouter(router, "worker", 3);
            if (good)
            {
                SetThreadLocalValue(&router);
                {
                    InlineStorageString text(std::string(200, 'a').c_str());
                    int count = 32;
                    void* block = router.solver().bufAlloc(count);
                    good = text.getLength() == 200 && block;
                    router.solver().bufFree(block, count);
                }
                SetThreadLocalValue(nullptr);
            }
            results[i] = good;
            ready.count_down();
            finish.acquire();
            system.ThreadQuit(router, 3);
        });
    ready.wait();
    hkMemoryRouter overflow;
    checks.Equal("concurrent 33rd rejected", false, system.InitializeThreadRouter(overflow, "overflow", 3));
    finish.release(31);
    for (auto& worker : workers)
        worker.join();
    for (bool good : results)
        checks.Equal("worker string solver and teardown", true, good);
    system.MainQuit(3);
}

int main()
{
    Checks checks("runtime.havok_owner");
    Backing backing;
    {
        FUN_00cd0a60 system(backing, 257);
        hkMemoryRouter router;
        checks.Equal("thread init", true, system.InitializeThreadRouter(router, "test", 3));
        SetThreadLocalValue(&router);
        {
            InlineStorageString text(std::string(128, 'a').c_str());
            checks.Equal("heap content", 128, text.getLength());
            checks.Equal("adjusted thread capacity", 256, text.getCapacity());
            InlineStorageString slice("abcXYZ", 3);
            checks.Equal("explicit string extent", std::string("abc"), std::string(slice.cString()));
            slice.AssignStrings("path", "/", "file", nullptr, nullptr, nullptr);
            checks.Equal("six-string assignment replaces old content", std::string("path/file"), std::string(slice.cString()));
            slice.TrimToDirectory();
            checks.Equal("directory trim removes final component", std::string("path"), std::string(slice.cString()));
            slice.TrimToDirectory();
            checks.Equal("directory trim without separator clears", 0, slice.getLength());
            InlineStorageString longSlice(std::string(200, 's').c_str(), 200);
            const int retainedCapacity = longSlice.getCapacity();
            longSlice.Clear();
            checks.Equal("clear retains allocated extent", retainedCapacity, longSlice.getCapacity());
            checks.Equal("clear writes empty terminator", std::string(), std::string(longSlice.cString()));
            InputStream input("  first "+ std::string(200, 't') + "\n");
            fnv_00dcc8e0::TokenReader reader{0, 0, &input};
            InlineStorageString token("old content");
            reader.ReadToken(&token);
            checks.Equal("production token caller clears and reads", std::string("first"), std::string(token.cString()));
            reader.ReadToken(&token);
            checks.Equal("production token caller grows exact text", std::string(200, 't'), std::string(token.cString()));
            reader.ReadToken(&token);
            checks.Equal("production token caller clears at eof", 0, token.getLength());
            InlineStorageString copy(text);
            text.Append(text.cString(), text.getLength());
            checks.Equal("aliased append", 256, text.getLength());
            checks.Equal("copy independent", 128, copy.getLength());
            checks.Equal("copy honors adjusted allocation", 160, copy.getCapacity());
            InlineStorageString aliased(std::string(120, 'd').c_str());
            aliased.AppendStrings(aliased.cString(), aliased.cString() + 1, nullptr, nullptr, nullptr, nullptr);
            checks.Equal("multi append remaps aliases on growth", 359, aliased.getLength());
            checks.Equal("multi append content", std::string(359, 'd'), std::string(aliased.cString()));
            auto* retained = new InlineStorageString(copy);
            SetThreadLocalValue(nullptr);
            delete retained;
            SetThreadLocalValue(&router);
            text = "a-a";
            text.FUN_00d62190("a", std::string(200, 'b').c_str(), 1);
            checks.Equal("replacement publishes all content", 401, text.getLength());
            std::string before = text.cString();
            backing.fail = true;
            bool caught = false;
            try { text.FUN_00d62190("b", std::string(9000, 'c').c_str(), 1); }
            catch (const std::bad_alloc&) { caught = true; }
            checks.Equal("replacement failure", true, caught);
            checks.Equal("replacement rollback", before, std::string(text.cString()));
            backing.fail = false;
        }
        const int liveBeforeBatch = backing.live;
        backing.throwAfter = 2;
        bool batchCaught = false;
        try { router.temp().blockAlloc(8192); }
        catch (const std::bad_alloc&) { batchCaught = true; }
        backing.throwAfter = -1;
        checks.Equal("partial batch failure propagated", true, batchCaught);
        checks.Equal("partial batch allocation released", liveBeforeBatch, backing.live);
        int bytes = 641;
        void* block = router.temp().bufAlloc(bytes);
        checks.Equal("large thread class", 1024, bytes);
        std::memset(block, 0x5a, bytes);
        int grown = 9001;
        backing.fail = true;
        void* failed = router.temp().bufRealloc(block, bytes, grown);
        checks.Equal("failed resize returns null", true, failed == nullptr);
        checks.Equal("failed resize leaves size", 9001, grown);
        checks.Equal("failed resize retains old", 0x5a, int(static_cast<unsigned char*>(block)[640]));
        backing.fail = false;
        grown = 9001;
        void* replacement = router.temp().bufRealloc(block, bytes, grown);
        checks.Equal("resize copies old bytes", 0x5a, int(static_cast<unsigned char*>(replacement)[640]));
        router.temp().bufFree(replacement, grown);
        SetThreadLocalValue(nullptr);
        system.ThreadQuit(router, 2);
        checks.Equal("scratch released", true, router.m_stackCurrent == nullptr);
        checks.Equal("heap retained until thread quit", true, router.m_heap != nullptr);
        system.ThreadQuit(router, 1);
        checks.Equal("heap detached", true, router.m_heap == nullptr);
        checks.Equal("cache and scratch released", 0, backing.live);
        system.ThreadQuit(router, 3);
        backing.fail = true;
        checks.Equal("scratch failure rollback", false, system.InitializeThreadRouter(router, "fail", 3));
        checks.Equal("failed init detached", true, router.m_heap == nullptr);
        backing.fail = false;
        backing.throwAfter = 0;
        bool scratchCaught = false;
        try { system.InitializeThreadRouter(router, "throw", 3); }
        catch (const std::bad_alloc&) { scratchCaught = true; }
        checks.Equal("scratch exception propagated", true, scratchCaught);
        checks.Equal("scratch exception leaves router detached", true, router.m_heap == nullptr);
        backing.throwAfter = -1;
        std::array<hkMemoryRouter, 33> routers;
        for (int i = 0; i < 32; ++i)
            checks.Equal("record admitted", true, system.InitializeThreadRouter(routers[i], "record", 1));
        checks.Equal("record exhaustion", false, system.InitializeThreadRouter(routers[32], "full", 1));
        system.ThreadQuit(routers[7], 3);
        checks.Equal("record reusable", true, system.InitializeThreadRouter(routers[32], "retry", 3));
        for (auto& item : routers)
            system.ThreadQuit(item, 3);
        checks.Equal("all storage released", 0, backing.live);
        hkMemoryRouter* main = system.MainInit(257, 3, 8192);
        checks.Equal("main router initialized", true, main != nullptr);
        int solverBytes = 2048;
        void* first = main->solver().bufAlloc(solverBytes);
        int nextBytes = 2048;
        void* second = main->solver().bufAlloc(nextBytes);
        checks.Equal("solver allocation", true, first && second);
        main->solver().bufFree(first, solverBytes);
        int reuseBytes = 1536;
        void* reused = main->solver().bufAlloc(reuseBytes);
        checks.Equal("solver best fit reuses hole", true, reused == first);
        checks.Equal("solver adjusted extent", 2048, reuseBytes);
        main->solver().bufFree(reused, reuseBytes);
        main->solver().bufFree(second, nextBytes);
        int allBytes = 8192;
        void* all = main->solver().bufAlloc(allBytes);
        checks.Equal("solver coalesces and restores bump", true, all == first);
        main->solver().bufFree(all, allBytes);
        system.MainQuit(3);
        checks.Equal("main releases solver storage", 0, backing.live);
        alignas(16) std::array<char, 257> borrowed{};
        main = system.MainInitBorrowed(borrowed.data() + 1, 256);
        checks.Equal("borrowed main aligns start", true, main && main->m_stackCurrent == borrowed.data() + 16);
        checks.Equal("borrowed main keeps exact end", true, main->m_stack08 == borrowed.data() + 257);
        checks.Equal("startup aliases temporary allocator to heap", true, main->m_temp == main->m_heap);
        checks.Equal("startup aliases solver allocator to heap", true, main->m_solver == main->m_heap);
        system.MainQuit(3);
        borrowed[256] = 1;
        checks.Equal("borrowed storage not freed", 0, backing.live);
    }
    ConcurrentOwners(checks);
    {
        alignas(16) std::array<char, 257> stack{};
        checks.Equal("invalid game stack leaves no owner", true,
                     g_havokPhysicsMemory.Initialize(nullptr, 256) == nullptr && !g_havokPhysicsMemory.GetSystem());
        hkMemoryRouter* main = g_havokPhysicsMemory.Initialize(stack.data() + 1, 256);
        auto* actual = g_havokPhysicsMemory.GetSystem();
        SetThreadLocalValue(main);
        checks.Equal("game stack exact end", true, main && main->m_stack08 == stack.data() + 257);
        hkMemoryRouter attachedWorker;
        checks.Equal("published game owner admits worker", true, actual->InitializeThreadRouter(attachedWorker, "worker", 3));
        checks.Equal("game owner retains attached worker", false, g_havokPhysicsMemory.Shutdown());
        actual->ThreadQuit(attachedWorker, 3);
        auto text = std::make_unique<InlineStorageString>(std::string(200, 'g').c_str());
        checks.Equal("game owner retained with heap string", false, g_havokPhysicsMemory.Shutdown());
        checks.Equal("failed shutdown preserves supplying owner", true, actual == g_havokPhysicsMemory.GetSystem());
        SetThreadLocalValue(nullptr);
        text.reset();
        checks.Equal("game shutdown releases owner", true, g_havokPhysicsMemory.Shutdown());
        checks.Equal("game owner no longer published", true, g_havokPhysicsMemory.GetSystem() == nullptr && FUN_00c85750() == nullptr);
        checks.Equal("repeated game shutdown", true, g_havokPhysicsMemory.Shutdown());
    }
    {
        FUN_00cd0a60 system;
        alignas(16) std::array<char, 257> stack{};
        hkMemoryRouter* main = system.MainInitBorrowed(stack.data() + 1, 256);
        SetThreadLocalValue(main);
        auto text = std::make_unique<InlineStorageString>(std::string(200, 'x').c_str());
        checks.Equal("main quit refuses live heap strings", false, system.TryMainQuit());
        checks.Equal("refused quit keeps allocator attached", true, main->m_heap != nullptr);
        SetThreadLocalValue(nullptr);
        text.reset();
        hkMemoryRouter worker;
        checks.Equal("worker admitted before closing", true, system.InitializeThreadRouter(worker, "worker", 3));
        checks.Equal("main quit refuses attached worker", false, system.TryMainQuit());
        system.ThreadQuit(worker, 3);
        checks.Equal("main quit after string release and worker quit", true, system.TryMainQuit());
        checks.Equal("shutdown rejects new worker admission", false, system.InitializeThreadRouter(worker, "late", 3));
    }
    return checks.ExitCode();
}
