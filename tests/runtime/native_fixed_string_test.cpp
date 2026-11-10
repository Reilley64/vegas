#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/native_fixed_string.h"
#include "fnv/tls.h"

#include <array>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <thread>

#ifndef _WIN32
#include <sys/mman.h>
#endif

#define CHECK(expression) do { if (!(expression)) { \
    std::fprintf(stderr, "check failed: %s at line %d\n", #expression, __LINE__); \
    std::abort(); } } while (false)

namespace {

// The update an older unit performs on the count eight bytes before the text.
std::atomic<std::int32_t>& LegacyCount(char* handle)
{
    return *reinterpret_cast<std::atomic<std::int32_t>*>(handle - 8);
}

// The 0x00a5b270 source form: four characters at a time, then the tail.
unsigned int SourceHash(const char* text, unsigned int length)
{
    unsigned int hash = 0;
    length &= 0xfffffffc;
    if (length > 0) {
        unsigned int count = (length - 1) / 4 + 1;
        do {
            hash = hash * 33 + static_cast<unsigned int>(static_cast<signed char>(text[0]));
            hash = hash * 33 + static_cast<unsigned int>(static_cast<signed char>(text[1]));
            hash = hash * 33 + static_cast<unsigned int>(static_cast<signed char>(text[2]));
            hash = hash * 33 + static_cast<unsigned int>(static_cast<signed char>(text[3]));
            text += 4;
        } while (--count);
    }
    while (*text)
        hash = hash * 33 + static_cast<unsigned int>(static_cast<signed char>(*text++));
    return hash % 513;
}

void CheckHash(const char* text)
{
    const auto length = static_cast<unsigned int>(std::strlen(text));
    CHECK(fnv::strings::HashString(text, length) == SourceHash(text, length));
}

void ThrowWithLiveOwners(const NiFixedString& shared)
{
    NiFixedString copy(shared);
    NiFixedString name("unwind-name");
    CHECK(fnv::strings::RefCount(shared.m_kHandle) == 2);
    throw std::runtime_error("expected");
}

void CheckHashes()
{
    CHECK(fnv::strings::HashString("", 0) == 0);
    CHECK(fnv::strings::HashString("a", 1) == 97);
    CHECK(fnv::strings::HashString("ab", 2) == (97u * 33u + 98u) % 513u);
    // A character above 0x7f is added as a negative value.
    CHECK(fnv::strings::HashString("\x80", 1) == 0xffffff80u % 513u);
    for (const char* text : {"abc", "abcd", "abcde", "RenderPasses", "ps_2_0", "Bip01 L Finger0\xe9",
                             "a string long enough to wrap the 32-bit accumulator several times over"})
        CheckHash(text);
}

void CheckOversizedText()
{
#ifndef _WIN32
    // A text whose node size cannot be a 32-bit request is refused before the
    // table is touched.
    const std::size_t bytes = (std::size_t{1} << 32) + 4096;
    void* mapping = mmap(nullptr, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    CHECK(mapping != MAP_FAILED);
    char* text = static_cast<char*>(mapping);
    std::memset(text, 'a', bytes - 1);
    const std::size_t before = fnv::strings::NodeCount();
    const int context = g_tlsBlock.memoryContext;
    CHECK(NiGlobalStringTable::AddString(text) == nullptr);
    CHECK(fnv::strings::NodeCount() == before);
    CHECK(g_tlsBlock.memoryContext == context);
    CHECK(munmap(mapping, bytes) == 0);
#endif
}

} // namespace

int main()
{
    // Before startup the table interns nothing.
    CHECK(NiGlobalStringTable::AddString("early") == nullptr);
    FUN_00a5b630();
    CHECK(fnv::strings::TableIdentity() != nullptr);
    CHECK(fnv::strings::NodeCount() == 0);
    CheckHashes();

    {
        // The null handle is the null string and has no node.
        NiFixedString none;
        NiFixedString nullName(nullptr);
        CHECK(none.m_kHandle == nullptr);
        CHECK(nullName.m_kHandle == nullptr);
        CHECK(!none.IsNotEmpty());
        CHECK(NiGlobalStringTable::AddString(nullptr) == nullptr);
        CHECK(fnv::strings::RefCount(nullptr) == 0);
        CHECK(!fnv::strings::Owns(nullptr));
        fnv::strings::RetainHandle(nullptr);
        fnv::strings::ReleaseHandle(nullptr);
        CHECK(fnv::strings::NodeCount() == 0);

        // An empty text is an ordinary interned string.
        NiFixedString empty("");
        CHECK(empty.m_kHandle != nullptr);
        CHECK(empty.IsNotEmpty());
        CHECK(fnv::strings::Length(empty.m_kHandle) == 0);
        CHECK(fnv::strings::Owns(empty.m_kHandle));

        NiFixedString alpha("alpha");
        NiFixedString duplicate("alpha");
        NiFixedString beta("beta");
        char local[] = "alpha";
        CHECK(alpha.m_kHandle == duplicate.m_kHandle);
        CHECK(alpha.m_kHandle != beta.m_kHandle);
        CHECK(alpha.m_kHandle != local);
        CHECK(std::strcmp(alpha.m_kHandle, "alpha") == 0);
        CHECK(fnv::strings::Owns(alpha.m_kHandle));
        CHECK(fnv::strings::Owns(beta.m_kHandle));
        CHECK(!fnv::strings::Owns(local));
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 2);
        CHECK(fnv::strings::RefCount(beta.m_kHandle) == 1);
        CHECK(fnv::strings::Length(alpha.m_kHandle) == 5);
        CHECK(fnv::strings::NodeCount() == 3);
        if (sizeof(void*) == 8)
            CHECK(reinterpret_cast<std::uintptr_t>(alpha.m_kHandle) > UINT32_MAX);

        // The count and length sit where older units read them.
        std::uint32_t storedLength = 0;
        std::memcpy(&storedLength, alpha.m_kHandle - 4, sizeof(storedLength));
        CHECK(storedLength == 5);
        CHECK(LegacyCount(alpha.m_kHandle).load() == 2);

        // Copy construction and both assignments.
        NiFixedString copied(alpha);
        CHECK(copied.m_kHandle == alpha.m_kHandle);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 3);
        NiFixedString assigned("old-name");
        char* oldName = assigned.m_kHandle;
        assigned = alpha;
        CHECK(assigned.m_kHandle == alpha.m_kHandle);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 4);
        CHECK(fnv::strings::RefCount(oldName) == 0);
        assigned = assigned;
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 4);
        assigned = "beta";
        CHECK(assigned.m_kHandle == beta.m_kHandle);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 3);
        CHECK(fnv::strings::RefCount(beta.m_kHandle) == 2);
        // Assigning a handle its own text pointer changes nothing.
        assigned = static_cast<const char*>(assigned.m_kHandle);
        CHECK(fnv::strings::RefCount(beta.m_kHandle) == 2);
        assigned = static_cast<const char*>(nullptr);
        CHECK(assigned.m_kHandle == nullptr);
        CHECK(fnv::strings::RefCount(beta.m_kHandle) == 1);

        // The object-name slot update: retain the new name, then release the old.
        char* nameSlot = nullptr;
        fnv::strings::AssignHandle(nameSlot, alpha.m_kHandle);
        CHECK(nameSlot == alpha.m_kHandle);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 4);
        fnv::strings::AssignHandle(nameSlot, nameSlot);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 4);
        fnv::strings::AssignHandle(nameSlot, beta.m_kHandle);
        CHECK(nameSlot == beta.m_kHandle);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 3);
        CHECK(fnv::strings::RefCount(beta.m_kHandle) == 2);
        fnv::strings::AssignHandle(nameSlot, nullptr);
        CHECK(nameSlot == nullptr);
        CHECK(fnv::strings::RefCount(beta.m_kHandle) == 1);

        // A release never frees. The unreferenced node stays interned, a new
        // intern revives the same node, and only the sweep retires it.
        CHECK(fnv::strings::Owns(oldName));
        CHECK(fnv::strings::NodeCount() == 4);
        char* revived = NiGlobalStringTable::AddString("old-name");
        CHECK(revived == oldName);
        CHECK(fnv::strings::RefCount(oldName) == 1);
        FUN_00a5b460();
        CHECK(fnv::strings::Owns(oldName));
        fnv::strings::ReleaseHandle(revived);
        FUN_00a5b460();
        CHECK(!fnv::strings::Owns(oldName));
        CHECK(fnv::strings::NodeCount() == 3);

        // An older unit's direct count updates and the owner's operations act
        // on the same count, and the same sweep retires the node either way.
        char* mixed = NiGlobalStringTable::AddString("mixed");
        LegacyCount(mixed).fetch_add(1);
        CHECK(fnv::strings::RefCount(mixed) == 2);
        fnv::strings::ReleaseHandle(mixed);
        FUN_00a5b460();
        CHECK(fnv::strings::Owns(mixed));
        {
            NiFixedString owner;
            fnv::strings::AssignHandle(owner.m_kHandle, mixed);
            LegacyCount(mixed).fetch_sub(1);
            CHECK(fnv::strings::RefCount(mixed) == 1);
        }
        CHECK(fnv::strings::RefCount(mixed) == 0);
        CHECK(fnv::strings::Owns(mixed));
        FUN_00a5b460();
        CHECK(!fnv::strings::Owns(mixed));
        CHECK(fnv::strings::NodeCount() == 3);

        // The manager has heaps but no fixed pools yet, so a new small node
        // cannot be allocated through the real route. Nothing is published
        // and the lock and the thread's allocation context are restored.
        g_memoryManager.InitializeHeaps();
        CHECK(!g_memoryManager.PoolsInitialized());
        g_tlsBlock.memoryContext = 23;
        CHECK(NiGlobalStringTable::AddString("new-intern-must-fail") == nullptr);
        CHECK(g_tlsBlock.memoryContext == 23);
        CHECK(fnv::strings::NodeCount() == 3);
        NiFixedString failed("new-owner-must-fail");
        CHECK(failed.m_kHandle == nullptr);
        NiFixedString replaced(alpha);
        replaced = "new-text-must-fail";
        CHECK(replaced.m_kHandle == nullptr);
        CHECK(fnv::strings::RefCount(alpha.m_kHandle) == 3);
        CHECK(g_tlsBlock.memoryContext == 23);
        // An existing string needs no allocation and the lock is free.
        char* again = NiGlobalStringTable::AddString("alpha");
        CHECK(again == alpha.m_kHandle);
        fnv::strings::ReleaseHandle(again);

        g_memoryManager.FUN_00866770();
        CHECK(g_memoryManager.PoolsInitialized());
        NiFixedString pooled("pooled-after-startup");
        CHECK(pooled.m_kHandle != nullptr);
        CHECK(g_tlsBlock.memoryContext == 23);
        CHECK(fnv::strings::NodeCount() == 4);
        CheckOversizedText();

        // Concurrent interning, copying and releasing while another thread sweeps.
        NiFixedString concurrentRoot("concurrent-intern");
        char* concurrentHandle = concurrentRoot.m_kHandle;
        std::atomic<bool> sweeping{true};
        std::thread sweeper([&] {
            while (sweeping.load())
                FUN_00a5b460();
        });
        std::array<std::thread, 8> threads;
        for (std::size_t index = 0; index < threads.size(); ++index) {
            threads[index] = std::thread([&, index] {
                char own[32];
                std::snprintf(own, sizeof(own), "thread-own-%u", static_cast<unsigned>(index));
                for (int iteration = 0; iteration < 500; ++iteration) {
                    NiFixedString value("concurrent-intern");
                    CHECK(value.m_kHandle == concurrentHandle);
                    NiFixedString copy(value);
                    CHECK(copy.m_kHandle == concurrentHandle);
                    NiFixedString mine(own);
                    CHECK(std::strcmp(mine.m_kHandle, own) == 0);
                }
            });
        }
        for (auto& thread : threads)
            thread.join();
        sweeping = false;
        sweeper.join();
        CHECK(fnv::strings::RefCount(concurrentHandle) == 1);
        FUN_00a5b460();
        CHECK(fnv::strings::NodeCount() == 5);

        // Unwinding releases every owner on the way out.
        try {
            ThrowWithLiveOwners(concurrentRoot);
            CHECK(false);
        } catch (const std::runtime_error&) {}
        CHECK(fnv::strings::RefCount(concurrentHandle) == 1);
        FUN_00a5b460();
        CHECK(fnv::strings::NodeCount() == 5);

        // Live handles refuse the shutdown and stay usable.
        CHECK(!fnv::strings::ShutdownTable());
        CHECK(fnv::strings::Owns(beta.m_kHandle));
        CHECK(NiGlobalStringTable::AddString("beta") == beta.m_kHandle);
        fnv::strings::ReleaseHandle(beta.m_kHandle);
    }

    CHECK(fnv::strings::ShutdownTable());
    CHECK(fnv::strings::NodeCount() == 0);
    CHECK(g_tlsBlock.memoryContext == 23);
    CHECK(NiGlobalStringTable::AddString("late") == nullptr);
    g_memoryManager.ShutdownHeaps();
    return 0;
}
