// gamebryo2.2/corelibs/nimain/native_fixed_string.cpp: the one native global string table and the owning NiFixedString operations.

#include "fnv/native_fixed_string.h"

#include "AutoMemContext.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/symbols_00401000.h"

#include <atomic>
#include <cstring>
#include <limits>
#include <mutex>
#include <new>

namespace {

constexpr unsigned int BucketCount = 0x201;

struct Node {
    Node* next;
    std::atomic<std::int32_t> refs;
    std::uint32_t length;
    char text[1];
};

// Older units update the count at text - 8 with interlocked 32-bit operations
// and read the length at text - 4.
static_assert(std::atomic<std::int32_t>::is_always_lock_free);
static_assert(sizeof(std::atomic<std::int32_t>) == 4);
static_assert(offsetof(Node, text) - offsetof(Node, refs) == 8);
static_assert(offsetof(Node, text) - offsetof(Node, length) == 4);

Node* NodeOf(const char* handle) noexcept
{
    return reinterpret_cast<Node*>(const_cast<char*>(handle) - offsetof(Node, text));
}

struct Table {
    std::mutex lock;
    Node* buckets[BucketCount]{};
    std::size_t nodeCount = 0;
    bool started = false;

    // 0x00a5b300
    Node* Find(const char* text, std::uint32_t length, unsigned int bucket) noexcept
    {
        for (Node* node = buckets[bucket]; node; node = node->next)
            if (node->text == text || (node->length == length && std::strcmp(node->text, text) == 0))
                return node;
        return nullptr;
    }

    Node* FindHandle(const char* handle) noexcept
    {
        for (Node* bucket : buckets)
            for (Node* node = bucket; node; node = node->next)
                if (node->text == handle)
                    return node;
        return nullptr;
    }

    // 0x00a5b3c0
    void CollectUnreferenced() noexcept
    {
        for (Node*& bucket : buckets) {
            Node** link = &bucket;
            while (Node* node = *link) {
                if (node->refs.load() != 0) {
                    link = &node->next;
                    continue;
                }
                *link = node->next;
                --nodeCount;
                node->~Node();
                FUN_00401030(node);
            }
        }
    }
};

// The table serves handles held by static objects in other units, so it is
// constant-initialized and its destructor is never registered.
[[clang::no_destroy]] constinit Table g_table;

} // namespace

// @fnv 0x00a5b270
unsigned int fnv::strings::HashString(const char* text, unsigned int length) noexcept
{
    unsigned int hash = 0;
    for (unsigned int index = 0; index < length; ++index)
        hash = hash * 33 + static_cast<unsigned int>(static_cast<signed char>(text[index]));
    return hash % BucketCount;
}

// @fnv 0x00a5b630
void FUN_00a5b630()
{
    std::lock_guard guard(g_table.lock);
    g_table.started = true;
}

// @fnv 0x00a5b460
void FUN_00a5b460()
{
    std::lock_guard guard(g_table.lock);
    g_table.CollectUnreferenced();
}

bool fnv::strings::ShutdownTable() noexcept
{
    std::lock_guard guard(g_table.lock);
    g_table.CollectUnreferenced();
    if (g_table.nodeCount != 0)
        return false;
    g_table.started = false;
    return true;
}

// Looks up or allocates a reference-counted copy of text under the table lock and returns the handle with one more reference.
// @fnv 0x00a5b690
char* NiGlobalStringTable::AddString(const char* text)
{
    if (!text)
        return nullptr;
    const std::size_t wideLength = std::strlen(text);
    // The node size is a 32-bit request rounded up to four bytes.
    if (wideLength > std::numeric_limits<unsigned int>::max() - offsetof(Node, text) - 4)
        return nullptr;
    const auto length = static_cast<std::uint32_t>(wideLength);
    std::lock_guard guard(g_table.lock);
    if (!g_table.started)
        return nullptr;
    const unsigned int bucket = fnv::strings::HashString(text, length);
    if (Node* existing = g_table.Find(text, length, bucket)) {
        existing->refs.fetch_add(1);
        return existing->text;
    }
    AutoMemContext context(8);
    unsigned int bytes = static_cast<unsigned int>(offsetof(Node, text)) + length + 1;
    if (bytes & 3)
        bytes += 4 - (bytes & 3);
    void* storage = FUN_00401000(bytes);
    if (!storage)
        return nullptr;
    Node* node = new (storage) Node{g_table.buckets[bucket], 1, length, {0}};
    std::memcpy(node->text, text, wideLength + 1);
    g_table.buckets[bucket] = node;
    ++g_table.nodeCount;
    return node->text;
}

void fnv::strings::RetainHandle(char* handle) noexcept
{
    if (handle)
        NodeOf(handle)->refs.fetch_add(1);
}

void fnv::strings::ReleaseHandle(char* handle) noexcept
{
    if (handle)
        NodeOf(handle)->refs.fetch_sub(1);
}

void fnv::strings::AssignHandle(char*& slot, char* incoming) noexcept
{
    if (slot == incoming)
        return;
    RetainHandle(incoming);
    ReleaseHandle(slot);
    slot = incoming;
}

const void* fnv::strings::TableIdentity() noexcept
{
    return &g_table;
}

bool fnv::strings::Owns(const char* handle) noexcept
{
    std::lock_guard guard(g_table.lock);
    return handle && g_table.FindHandle(handle);
}

std::uint32_t fnv::strings::RefCount(const char* handle) noexcept
{
    return handle ? static_cast<std::uint32_t>(NodeOf(handle)->refs.load()) : 0;
}

std::uint32_t fnv::strings::Length(const char* handle) noexcept
{
    return handle ? NodeOf(handle)->length : 0;
}

std::size_t fnv::strings::NodeCount() noexcept
{
    std::lock_guard guard(g_table.lock);
    return g_table.nodeCount;
}

NiFixedString::NiFixedString() noexcept : m_kHandle(nullptr) {}

// @fnv 0x00438170
NiFixedString::NiFixedString(const char* text) noexcept : m_kHandle(NiGlobalStringTable::AddString(text)) {}

// @fnv 0x0048af40
NiFixedString::NiFixedString(const NiFixedString& other) noexcept : m_kHandle(other.m_kHandle)
{
    fnv::strings::RetainHandle(m_kHandle);
}

// @fnv 0x004381b0
NiFixedString::~NiFixedString() noexcept
{
    fnv::strings::ReleaseHandle(m_kHandle);
}

// @fnv 0x00a2e750
NiFixedString& NiFixedString::operator=(const char* text) noexcept
{
    char* old = m_kHandle;
    if (old != text) {
        m_kHandle = NiGlobalStringTable::AddString(text);
        fnv::strings::ReleaseHandle(old);
    }
    return *this;
}

NiFixedString& NiFixedString::operator=(const NiFixedString& other) noexcept
{
    fnv::strings::AssignHandle(m_kHandle, other.m_kHandle);
    return *this;
}

// @fnv 0x0048af70
int NiFixedString::IsNotEmpty() const noexcept
{
    return m_kHandle != nullptr;
}
