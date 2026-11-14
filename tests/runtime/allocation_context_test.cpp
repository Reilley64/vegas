#include "AutoMemContext.h"
#include "fnv/decl/AutoMemContext.h"
#include "fnv/tls.h"

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <new>
#include <thread>
#include <type_traits>

namespace
{
void Check(bool condition, int line)
{
    if (!condition)
    {
        std::fprintf(stderr, "allocation context check failed at line %d\n", line);
        std::abort();
    }
}
#define CHECK(condition) Check((condition), __LINE__)

void Set(int context)
{
    fnv_00404f30::FUN_00404f30(context);
    CHECK(GetTlsField() == context);
    CHECK(g_tlsBlock.memoryContext == context);
}

static_assert(!std::is_copy_constructible_v<AutoMemContext>);
static_assert(!std::is_copy_assignable_v<AutoMemContext>);
static_assert(!std::is_move_constructible_v<AutoMemContext>);
static_assert(!std::is_move_assignable_v<AutoMemContext>);
static_assert(std::is_nothrow_destructible_v<AutoMemContext>);
static_assert(!std::is_polymorphic_v<AutoMemContext>);

void NestedAndEarlyReturn()
{
    AutoMemContext outer(9, true, "context-test", 1);
    CHECK(GetTlsField() == 9);
    {
        AutoMemContext inner(23, false, "context-test", 2);
        CHECK(GetTlsField() == 23);
        // The source ignores overridable, not the requested context.
        {
            AutoMemContext distant(36, true, nullptr, 0);
            CHECK(GetTlsField() == 36);
        }
        CHECK(GetTlsField() == 23);
    }
    CHECK(GetTlsField() == 9);
    return; // Ordinary automatic cleanup is also the early-return cleanup.
}

int CallerReturn(bool early)
{
    AutoMemContext outer(9);
    AutoMemContext inner(36);
    CHECK(GetTlsField() == 36);
    if (early)
        return 1;
    return 2;
}

void ExplicitReuse()
{
    // The real staging caller leaves, re-enters, leaves, then destroys the
    // same automatic object. Changing TLS afterwards exposes a double restore.
    {
        AutoMemContext context(13, true, "context-test", 3526);
        CHECK(GetTlsField() == 13);
        context.Leave();
        CHECK(GetTlsField() == 59);
        context.Enter(11, true, "context-test", 3541);
        CHECK(GetTlsField() == 11);
        context.Leave();
        CHECK(GetTlsField() == 59);
        Set(7);
        context.Leave();
        CHECK(GetTlsField() == 7);
    }
    CHECK(GetTlsField() == 7);
    Set(59);

    // main's caller-owned complete object exists before its first entry.
    {
        AutoMemContext context;
        Set(8);
        context.Leave();
        CHECK(GetTlsField() == 8);
        context.Enter(16, true, nullptr, 0);
        CHECK(GetTlsField() == 16);
        context.Leave();
        CHECK(GetTlsField() == 8);
        context.Enter(15, true, nullptr, 0);
        CHECK(GetTlsField() == 15);
    }
    CHECK(GetTlsField() == 8);
    Set(59);
}

void BootInitEntries()
{
    // Source Enter replaces its snapshot on EVERY entry, including an active
    // guard. It does not push a stack or preserve the constructor's snapshot.
    {
        AutoMemContext memory(10, true, "context-test", 0xe4f);
        memory.Enter(10, true, "context-test", 0xe51);
        memory.Leave();
        CHECK(GetTlsField() == 10);
        memory.Enter(25, true, nullptr, 0);
        memory.Leave();
        CHECK(GetTlsField() == 10);
        memory.Enter(52, true, nullptr, 0);
        memory.Leave();
        memory.Enter(52, true, nullptr, 0);
        CHECK(GetTlsField() == 52);
    }
    CHECK(GetTlsField() == 10);
    Set(59);
    {
        AutoMemContext context(9);
        context.Enter(23, false, nullptr, 0);
        CHECK(GetTlsField() == 23);
        context.Leave();
        CHECK(GetTlsField() == 9);
    }
    CHECK(GetTlsField() == 9);
    Set(59);
}

struct UnwindObserver
{
    int expected;
    ~UnwindObserver() { CHECK(GetTlsField() == expected); }
};
struct Throws
{
    AutoMemContext context{36};
    Throws() { CHECK(GetTlsField() == 36); throw 42; }
};
void Exceptions()
{
    try
    {
        UnwindObserver restored{59};
        AutoMemContext outer(9);
        UnwindObserver innerRestored{9};
        AutoMemContext inner(23);
        CHECK(GetTlsField() == 23);
        throw 17;
    }
    catch (int value)
    {
        CHECK(value == 17);
        CHECK(GetTlsField() == 59);
    }
    try
    {
        AutoMemContext outer(9);
        Throws partial;
    }
    catch (int value)
    {
        CHECK(value == 42);
        CHECK(GetTlsField() == 59);
    }
    try
    {
        AutoMemContext context(36);
        context.Leave();
        Set(7);
        throw 1;
    }
    catch (int)
    {
        CHECK(GetTlsField() == 7);
    }
    Set(59);
}

void StorageReuse()
{
    // Native complete storage and ordinary construction; no historical size
    // or receiver cast. Each lifetime starts inactive before the ctor enters.
    alignas(AutoMemContext) std::byte storage[sizeof(AutoMemContext)];
    for (int tag : {9, 23, 36})
    {
        auto* context = ::new (storage) AutoMemContext(tag, true, nullptr, 0);
        CHECK(GetTlsField() == tag);
        std::destroy_at(context);
        CHECK(GetTlsField() == 59);
    }
}

void ThreadIsolation()
{
    std::atomic<int> entered{0};
    std::atomic<int> restored{0};
    auto worker = [&](int tag)
    {
        CHECK(GetTlsField() == 59); // Genuine production TLS initial value.
        {
            AutoMemContext outer(tag);
            entered.fetch_add(1, std::memory_order_release);
            while (entered.load(std::memory_order_acquire) != 2)
                std::this_thread::yield();
            CHECK(GetTlsField() == tag);
            {
                AutoMemContext inner(36);
                CHECK(GetTlsField() == 36);
            }
            CHECK(GetTlsField() == tag);
        }
        CHECK(GetTlsField() == 59);
        restored.fetch_add(1, std::memory_order_release);
    };
    Set(7);
    std::thread first(worker, 9);
    std::thread second(worker, 23);
    first.join();
    second.join();
    CHECK(restored.load(std::memory_order_acquire) == 2);
    CHECK(GetTlsField() == 7);
    Set(59);
}
}

int main()
{
    CHECK(GetTlsField() == 59);
    NestedAndEarlyReturn();
    CHECK(GetTlsField() == 59);
    CHECK(CallerReturn(true) == 1);
    CHECK(GetTlsField() == 59);
    CHECK(CallerReturn(false) == 2);
    CHECK(GetTlsField() == 59);
    ExplicitReuse();
    BootInitEntries();
    Exceptions();
    StorageReuse();
    ThreadIsolation();
    std::puts("production allocation-context protocol passed; heap routing not tested");
}
