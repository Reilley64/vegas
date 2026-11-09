#include "fnv/decl/FUN_0044a310.h"
#include "fnv/decl/FUN_0044a4c0.h"
#include "fnv/decl/FUN_00b09480.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/fnv_00ac87b0__String.h"
#include "fnv/symbols_00b18000.h"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>
#include <utility>

namespace {
void check(bool condition)
{
    if (!condition)
        std::abort();
}

void check_text(const FUN_0044a4c0& value, const char* expected)
{
    check(value.size() == std::strlen(expected));
    check(std::strcmp(value.c_str(), expected) == 0);
    check(value.data()[value.size()] == '\0');
}

void check_formatted(const char* text)
{
    FUN_0044a4c0 output;
    check(FUN_00b18860(&output, "%s", text) == &output);
    check_text(output, text);
}

void check_error(const char* text)
{
    FUN_00b09480 error(FUN_0044a4c0(text), false);
    FUN_0044a4c0 expected(text);
    expected.append(" []");
    check(std::strcmp(error.what(), expected.c_str()) == 0);
}

void check_error_constructor_kinds()
{
    const FUN_0044a4c0 message("byte constructor message");

    FUN_00b09480 byteZero(message, static_cast<unsigned char>(0));
    check(std::strcmp(byteZero.what(), "byte constructor message") == 0);

    FUN_00b09480 byteNonzero(message, static_cast<unsigned char>(7));
    check(std::strcmp(byteNonzero.what(), "e") == 0);

    FUN_00b09480 booleanFalse(message, false);
    check(std::strcmp(booleanFalse.what(), "byte constructor message []") == 0);
}

void check_canonical_throw_lifecycle()
{
    int payload = 73;
    const void* caughtMember = nullptr;
    try {
        FUN_0044a310 error(&payload);
        FUN_0044a310 copied(error);
        check(error.m_kMember.get() == &payload);
        check(copied.m_kMember.get() == &payload);
        throw copied;
    } catch (const FUN_00ec78e0& error) {
        const auto* typed = dynamic_cast<const FUN_0044a310*>(&error);
        check(typed != nullptr);
        caughtMember = typed->m_kMember.get();
    }
    check(caughtMember == &payload);
}

void check_staging_string_lifecycle()
{
    fnv_00ac87b0::String original("a staging string long enough for owned storage");
    fnv_00ac87b0::String copied(original);
    check_text(copied, "a staging string long enough for owned storage");

    original.assign("changed");
    check_text(original, "changed");
    check_text(copied, "a staging string long enough for owned storage");

    fnv_00ac87b0::String moved(std::move(copied));
    check_text(moved, "a staging string long enough for owned storage");
    check_text(copied, "");
}

void check_production_messages()
{
    static_assert(std::numeric_limits<int>::max() == 2147483647);
    static_assert(std::numeric_limits<unsigned int>::max() == 4294967295U);

    FUN_0044a4c0 output;
    const unsigned int aboveSignedMaximum =
        static_cast<unsigned int>(std::numeric_limits<int>::max()) + 1U;
    FUN_00b18860(
        &output,
        "collision object index (%u) exceeds maximum index (%u)",
        aboveSignedMaximum,
        std::numeric_limits<unsigned int>::max());
    check_text(
        output,
        "collision object index (2147483648) exceeds maximum index (4294967295)");

    FUN_00b18860(&output, "frond vertices exceed %d", 65535);
    check_text(output, "frond vertices exceed 65535");
}

struct LifetimeProbe {
    static int alive;
    LifetimeProbe() { ++alive; }
    ~LifetimeProbe() { --alive; }
};
int LifetimeProbe::alive = 0;

struct FailingMemberOwner {
    LifetimeProbe probe;
    FUN_0044a4c0 text;
    explicit FailingMemberOwner(const char* value) : text(value) {}
};

struct FailingErrorOwner {
    LifetimeProbe probe;
    FUN_00b09480 error;
    explicit FailingErrorOwner(const char* value) : error(FUN_0044a4c0(value), false) {}
};
}

int main()
{
    check(!g_memoryManager.HeapsInitialized());

    {
        FUN_0044a4c0 retryAfterPublication("retry");
        FUN_0044a4c0 empty;
        check_text(empty, "");
        empty.assign(nullptr);
        check_text(empty, "");

        FUN_0044a4c0 nullText(nullptr);
        check_text(nullText, "");

        FUN_0044a4c0 small("123456789012345");
        check(small.uses_small_buffer());
        check(small.capacity() == 15);
        check_text(small, "123456789012345");

        FUN_0044a4c0 boundary("1234567890123456");
        check(!boundary.uses_small_buffer());
        check(reinterpret_cast<std::uintptr_t>(boundary.data()) >
              std::numeric_limits<std::uint32_t>::max());
        check(g_memoryManager.Owns(boundary.data()));
        check_text(boundary, "1234567890123456");

        FUN_0044a4c0 large("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
        check(!large.uses_small_buffer());
        check_text(large, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

        FUN_0044a4c0 copy(large);
        copy.data()[0] = 'A';
        check(large.data()[0] == 'a');
        check(copy.data() != large.data());

        FUN_0044a4c0 assigned("independent destination");
        assigned = large;
        assigned.data()[1] = 'B';
        check(large.data()[1] == 'b');

        const char* retained = large.data();
        const auto retainedCapacity = large.capacity();
        large.assign("short");
        check(large.data() == retained);
        check(large.capacity() == retainedCapacity);
        check_text(large, "short");
        large.assign("grow this value beyond the retained allocation capacity by a useful margin");
        check_text(large, "grow this value beyond the retained allocation capacity by a useful margin");

        FUN_0044a4c0 self("self assignment survives");
        self = self;
        check_text(self, "self assignment survives");
        self.assign(self.data() + 5, 10);
        check_text(self, "assignment");

        FUN_0044a4c0 overlap("0123456789");
        overlap.append(overlap.data() + 2, 5);
        check_text(overlap, "012345678923456");
        overlap.append(overlap);
        check_text(overlap, "012345678923456012345678923456");

        FUN_0044a4c0 moved(std::move(overlap));
        check_text(moved, "012345678923456012345678923456");
        check_text(overlap, "");
        FUN_0044a4c0 moveAssigned("old heap allocation that must be retired");
        moveAssigned = std::move(moved);
        check_text(moveAssigned, "012345678923456012345678923456");
        check_text(moved, "");

        check_formatted("");
        check_formatted("123456789012345");
        check_formatted("1234567890123456");
        check_error("");
        check_error("123456789012345");
        check_error("1234567890123456");
        check_error("a production parser error message large enough to require owned heap storage");
        check_error_constructor_kinds();
        check_production_messages();
        check_canonical_throw_lifecycle();
        check_staging_string_lifecycle();

        const void* thrownMessageStorage = nullptr;
        try {
            FUN_0044a4c0 message("malformed branch data");
            FUN_00b09480 error(message, false);
            throw error;
        } catch (const FUN_00b09480& error) {
            check(std::strcmp(error.what(), "malformed branch data []") == 0);
            thrownMessageStorage = error.message.data();
            check(g_memoryManager.Owns(thrownMessageStorage));
        }
        check(!g_memoryManager.Owns(thrownMessageStorage));

        char formattedLarge[1401];
        std::memset(formattedLarge, 'x', sizeof(formattedLarge) - 1);
        formattedLarge[sizeof(formattedLarge) - 1] = '\0';
        check_formatted(formattedLarge);

        FUN_0044a4c0 retainedOnFailure("original bootstrap allocation remains intact");
        const char* originalPointer = retainedOnFailure.data();
        g_memoryManager.InitializeHeaps();
        check(g_memoryManager.HeapsInitialized());
        check(!g_memoryManager.PoolsInitialized());
        bool failed = false;
        try {
            retainedOnFailure.assign(
                "replacement needs a new allocation while the production small-allocation route is unavailable");
        } catch (const std::bad_alloc&) {
            failed = true;
        }
        check(failed);
        check(retainedOnFailure.data() == originalPointer);
        check_text(retainedOnFailure, "original bootstrap allocation remains intact");

        FUN_0044a4c0 formattedOnFailure("original");
        failed = false;
        try {
            FUN_00b18860(&formattedOnFailure, "%s", "formatting needs heap storage");
        } catch (const std::bad_alloc&) {
            failed = true;
        }
        check(failed);
        check_text(formattedOnFailure, "original");

        failed = false;
        try {
            retryAfterPublication.assign("1234567890123456");
        } catch (const std::bad_alloc&) {
            failed = true;
        }
        check(failed);
        check_text(retryAfterPublication, "retry");

        try {
            FailingMemberOwner owner("1234567890123456");
            (void)owner;
            check(false);
        } catch (const std::bad_alloc&) {
        }
        check(LifetimeProbe::alive == 0);
        try {
            FailingErrorOwner owner("123456789012345");
            (void)owner;
            check(false);
        } catch (const std::bad_alloc&) {
        }
        check(LifetimeProbe::alive == 0);

        g_memoryManager.FUN_00866770();
        check(g_memoryManager.PoolsInitialized());
        retryAfterPublication.assign("1234567890123456");
        check_text(retryAfterPublication, "1234567890123456");

        FUN_0044a4c0 pooled("1234567890123456");
        check(g_memoryManager.Owns(pooled.data()));
        check(g_memoryManager.PoolOwnerIndex(pooled.data()) != std::numeric_limits<std::size_t>::max());

        const char* pooledPointer = pooled.data();
        bool poolFailed = false;
        try {
            pooled.reserve(static_cast<std::size_t>(std::numeric_limits<unsigned int>::max()) - 1U);
        } catch (const std::bad_alloc&) {
            poolFailed = true;
        }
        check(poolFailed);
        check(pooled.data() == pooledPointer);
        check_text(pooled, "1234567890123456");

        void* retiredDuringUnwind = nullptr;
        try {
            FUN_0044a4c0 unwind("heap text retired while an enclosing operation unwinds");
            retiredDuringUnwind = unwind.data();
            check(g_memoryManager.Owns(retiredDuringUnwind));
            throw 7;
        } catch (int value) {
            check(value == 7);
        }
        check(!g_memoryManager.Owns(retiredDuringUnwind));

        // The accepted inventory has seven complete requiring objects. Repeated
        // construction and retirement uses the same production owner they now
        // name; complete-TU/object evidence separately accounts for each caller.
        for (int requiringObject = 0; requiringObject < 7; ++requiringObject) {
            for (int iteration = 0; iteration < 64; ++iteration) {
                FUN_0044a4c0 text("repeated parser error string retirement");
                check(g_memoryManager.Owns(text.data()));
            }
        }
    }

    g_memoryManager.ShutdownHeaps();
    check(!g_memoryManager.HeapsInitialized());
    return 0;
}
