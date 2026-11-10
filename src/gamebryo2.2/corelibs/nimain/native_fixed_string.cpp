#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/native_fixed_string.h"

#include "AutoMemContext.h"
#include "fnv/symbols_00401000.h"

extern char* DAT_0109b220;
extern NiGlobalStringTable* DAT_011f42c0;

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>
#include <utility>

#ifndef FNV_NATIVE_FIXED_STRING_EXTERNAL_DATA
char* DAT_0109b220 = nullptr;
NiGlobalStringTable* DAT_011f42c0 = nullptr;
#endif

namespace {
char g_emptyString[] = "";
#if defined(__clang__)
[[clang::no_destroy]]
#endif
constinit NiGlobalStringTable g_nativeStringTable;

std::size_t HashString(const char* text, std::uint32_t length) noexcept
{
    std::uint32_t hash = 2166136261u;
    for (std::uint32_t index = 0; index < length; ++index) {
        hash ^= static_cast<unsigned char>(text[index]);
        hash *= 16777619u;
    }
    return hash % 0x201u;
}
} // namespace

struct NiGlobalStringTable::Node {
    Node* next;
    NiGlobalStringTable* owner;
    std::uint32_t refs;
    std::uint32_t length;
    char text[1];
};

NiGlobalStringTable::Node* NiGlobalStringTable::FindLocked(
    const char* text, std::uint32_t length, std::size_t bucket) noexcept
{
    for (Node* node = buckets_[bucket]; node; node = node->next) {
        if (node->length == length && std::memcmp(node->text, text, length + 1) == 0)
            return node;
    }
    return nullptr;
}

NiGlobalStringTable::Node** NiGlobalStringTable::FindHandleLinkLocked(const char* handle) noexcept
{
    for (auto& bucket : buckets_)
        for (Node** link = &bucket; *link; link = &(*link)->next)
            if ((*link)->owner == this && (*link)->text == handle)
                return link;
    return nullptr;
}

void NiGlobalStringTable::AddString() noexcept
{
    std::lock_guard guard(lock_);
    ++m_uiLockCount;
}

bool NiGlobalStringTable::Initialize() noexcept
{
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    if (table.initialized_)
        return true;
    if (table.liveNodeCount_ != 0)
        return false;
    table.initialized_ = true;
    DAT_0109b220 = g_emptyString;
    DAT_011f42c0 = &table;
    return true;
}

bool NiGlobalStringTable::Shutdown() noexcept
{
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    if (table.liveNodeCount_ != 0)
        return false;
    table.initialized_ = false;
    DAT_011f42c0 = nullptr;
    DAT_0109b220 = g_emptyString;
    return true;
}

char* NiGlobalStringTable::EmptyString() noexcept
{
    return g_emptyString;
}

char* NiGlobalStringTable::AddString(const char* text) noexcept
{
    if (!text)
        return nullptr;
    const std::size_t wideLength = std::strlen(text);
    if (wideLength > std::numeric_limits<std::uint32_t>::max())
        return nullptr;
    const auto length = static_cast<std::uint32_t>(wideLength);
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    if (!table.initialized_)
        return nullptr;
    const auto bucket = HashString(text, length);
    if (Node* existing = table.FindLocked(text, length, bucket)) {
        if (existing->refs == std::numeric_limits<std::uint32_t>::max())
            return nullptr;
        ++existing->refs;
        return existing->text;
    }
    if (wideLength > std::numeric_limits<unsigned int>::max() - offsetof(Node, text) - 1)
        return nullptr;
    const auto bytes = static_cast<unsigned int>(offsetof(Node, text) + wideLength + 1);
    AutoMemContext context(8);
    void* storage = FUN_00401000(bytes);
    if (!storage)
        return nullptr;
    Node* node = new (storage) Node{table.buckets_[bucket], &table, 1, length, {0}};
    std::memcpy(node->text, text, wideLength + 1);
    table.buckets_[bucket] = node;
    ++table.liveNodeCount_;
    return node->text;
}

bool NiGlobalStringTable::Retain(const char* handle) noexcept
{
    if (!handle || handle == g_emptyString)
        return handle == g_emptyString;
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    Node** link = table.FindHandleLinkLocked(handle);
    if (!link || (*link)->refs == std::numeric_limits<std::uint32_t>::max())
        return false;
    ++(*link)->refs;
    return true;
}

bool NiGlobalStringTable::Release(const char* handle) noexcept
{
    if (!handle || handle == g_emptyString)
        return handle == g_emptyString;
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    Node** link = table.FindHandleLinkLocked(handle);
    if (!link || (*link)->refs == 0)
        return false;
    Node* node = *link;
    if (--node->refs != 0)
        return true;
    *link = node->next;
    --table.liveNodeCount_;
    node->~Node();
    FUN_00401030(node);
    return true;
}

const void* NiGlobalStringTable::Identity() noexcept
{
    return &g_nativeStringTable;
}

const void* NiGlobalStringTable::NodeIdentity(const char* handle) noexcept
{
    if (!handle || handle == g_emptyString)
        return nullptr;
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    Node** link = table.FindHandleLinkLocked(handle);
    return link ? static_cast<const void*>(*link) : nullptr;
}

bool NiGlobalStringTable::Owns(const char* handle) noexcept
{
    if (handle == g_emptyString)
        return true;
    return NodeIdentity(handle) != nullptr;
}

std::uint32_t NiGlobalStringTable::RefCount(const char* handle) noexcept
{
    if (handle == g_emptyString)
        return std::numeric_limits<std::uint32_t>::max();
    if (!handle)
        return 0;
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    Node** link = table.FindHandleLinkLocked(handle);
    return link ? (*link)->refs : 0;
}

std::uint32_t NiGlobalStringTable::Length(const char* handle) noexcept
{
    if (handle == g_emptyString)
        return 0;
    if (!handle)
        return 0;
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    Node** link = table.FindHandleLinkLocked(handle);
    return link ? (*link)->length : 0;
}

std::size_t NiGlobalStringTable::LiveNodeCount() noexcept
{
    auto& table = g_nativeStringTable;
    std::lock_guard guard(table.lock_);
    return table.liveNodeCount_;
}

void FUN_00a5b630()
{
    NiGlobalStringTable::Initialize();
}

bool ShutdownGlobalStringTable() noexcept
{
    return NiGlobalStringTable::Shutdown();
}

NiFixedString::NiFixedString() noexcept : m_kHandle(NiGlobalStringTable::EmptyString()) {}

NiFixedString::NiFixedString(const char* source)
    : m_kHandle(NiGlobalStringTable::EmptyString())
{
    if (!source)
        return;
    char* handle = NiGlobalStringTable::AddString(source);
    if (!handle)
        throw std::bad_alloc();
    m_kHandle = handle;
}

NiFixedString::NiFixedString(const NiFixedString& other)
    : m_kHandle(NiGlobalStringTable::EmptyString())
{
    if (!NiGlobalStringTable::Retain(other.m_kHandle))
        throw std::runtime_error("stale NiFixedString handle");
    m_kHandle = other.m_kHandle;
}

NiFixedString::NiFixedString(NiFixedString&& other) noexcept : m_kHandle(other.m_kHandle)
{
    other.m_kHandle = NiGlobalStringTable::EmptyString();
}

NiFixedString::~NiFixedString() noexcept
{
    NiGlobalStringTable::Release(m_kHandle);
    m_kHandle = NiGlobalStringTable::EmptyString();
}

NiFixedString& NiFixedString::operator=(const char* source)
{
    char* incoming = NiGlobalStringTable::EmptyString();
    if (source) {
        incoming = NiGlobalStringTable::AddString(source);
        if (!incoming)
            throw std::bad_alloc();
    }
    char* outgoing = m_kHandle;
    m_kHandle = incoming;
    NiGlobalStringTable::Release(outgoing);
    return *this;
}

NiFixedString& NiFixedString::operator=(const NiFixedString& other)
{
    if (m_kHandle == other.m_kHandle)
        return *this;
    if (!NiGlobalStringTable::Retain(other.m_kHandle))
        throw std::runtime_error("stale NiFixedString handle");
    char* outgoing = m_kHandle;
    m_kHandle = other.m_kHandle;
    NiGlobalStringTable::Release(outgoing);
    return *this;
}

NiFixedString& NiFixedString::operator=(NiFixedString&& other) noexcept
{
    if (this == &other)
        return *this;
    char* outgoing = m_kHandle;
    m_kHandle = other.m_kHandle;
    other.m_kHandle = NiGlobalStringTable::EmptyString();
    NiGlobalStringTable::Release(outgoing);
    return *this;
}

bool NiFixedString::operator==(const char* other) const noexcept
{
    return other && (m_kHandle == other || std::strcmp(m_kHandle, other) == 0);
}

bool NiFixedString::Exists() const noexcept { return m_kHandle != NiGlobalStringTable::EmptyString(); }
int NiFixedString::IsNotEmpty() const noexcept { return Exists() && *m_kHandle != '\0'; }
unsigned int NiFixedString::GetLength() const noexcept { return NiGlobalStringTable::Length(m_kHandle); }
unsigned int NiFixedString::GetRefCount() const noexcept { return NiGlobalStringTable::RefCount(m_kHandle); }
bool NiFixedString::Equals(char* other) const noexcept { return *this == other; }

bool NiFixedString::EqualsNoCase(char* other) const noexcept
{
    if (!other)
        return false;
    const unsigned char* left = reinterpret_cast<const unsigned char*>(m_kHandle);
    const unsigned char* right = reinterpret_cast<const unsigned char*>(other);
    while (*left && *right) {
        if (std::tolower(*left++) != std::tolower(*right++))
            return false;
    }
    return *left == *right;
}

bool NiFixedString::Contains(char* other) const noexcept
{
    return other && std::strstr(m_kHandle, other) != nullptr;
}

bool NiFixedString::HasSuffix(char* other) const noexcept
{
    if (!other)
        return false;
    const auto left = std::strlen(m_kHandle);
    const auto right = std::strlen(other);
    return right <= left && std::memcmp(m_kHandle + left - right, other, right) == 0;
}

void NiFixedString::Init() noexcept
{
    m_kHandle = NiGlobalStringTable::EmptyString();
}

void NiFixedString::Assign(const char* source)
{
    *this = source;
}

void NiFixedString::Clear() noexcept
{
    char* outgoing = m_kHandle;
    m_kHandle = NiGlobalStringTable::EmptyString();
    NiGlobalStringTable::Release(outgoing);
}

void NiFixedString::Release() noexcept
{
    Clear();
}

void NiFixedString::AssignInternedString(const NiFixedString& source)
{
    *this = source;
}

namespace fnv::strings {

FixedStringArray::FixedStringArray(FixedStringArray&& other) noexcept
    : data_(std::exchange(other.data_, nullptr)),
      capacity_(std::exchange(other.capacity_, 0)),
      count_(std::exchange(other.count_, 0)),
      growBy_(std::exchange(other.growBy_, 0)),
      flags_(std::exchange(other.flags_, 0))
{}

FixedStringArray& FixedStringArray::operator=(FixedStringArray&& other) noexcept
{
    if (this == &other)
        return *this;
    Clear();
    data_ = std::exchange(other.data_, nullptr);
    capacity_ = std::exchange(other.capacity_, 0);
    count_ = std::exchange(other.count_, 0);
    growBy_ = std::exchange(other.growBy_, 0);
    flags_ = std::exchange(other.flags_, 0);
    return *this;
}

FixedStringArray::~FixedStringArray() noexcept
{
    Clear();
}

bool FixedStringArray::Reserve(std::uint32_t requested) noexcept
{
    if (requested <= capacity_)
        return true;
    if (requested > std::numeric_limits<unsigned int>::max() / sizeof(NiFixedString))
        return false;
    AutoMemContext context(8);
    auto* replacement = static_cast<NiFixedString*>(
        FUN_00401000(static_cast<unsigned int>(requested * sizeof(NiFixedString))));
    if (!replacement)
        return false;
    std::uint32_t constructed = 0;
    try {
        for (; constructed < count_; ++constructed)
            new (replacement + constructed) NiFixedString(data_[constructed]);
    } catch (...) {
        while (constructed)
            replacement[--constructed].~NiFixedString();
        FUN_00401030(replacement);
        return false;
    }
    for (std::uint32_t index = 0; index < count_; ++index)
        data_[index].~NiFixedString();
    FUN_00401030(data_);
    data_ = replacement;
    capacity_ = requested;
    return true;
}

bool FixedStringArray::PushBack(const NiFixedString& value) noexcept
{
    if (count_ == capacity_) {
        const std::uint32_t next = capacity_ ? capacity_ * 2 : 1;
        if (next <= capacity_ || !Reserve(next))
            return false;
    }
    try {
        new (data_ + count_) NiFixedString(value);
    } catch (...) {
        return false;
    }
    ++count_;
    return true;
}

void FixedStringArray::Clear() noexcept
{
    while (count_)
        data_[--count_].~NiFixedString();
    FUN_00401030(data_);
    data_ = nullptr;
    capacity_ = 0;
    growBy_ = 0;
    flags_ = 0;
}

bool GPUProgramCacheNames::Update(int kind, const NiFixedString& requested, const char* path) noexcept
{
    try {
        GPUProgramCacheNames staged;
        staged.profile = requested;
        staged.suffix = path;
        char filename[260];
        const int length = std::snprintf(filename, sizeof(filename), "%s_%s_DX9.cache",
                                         path ? path : "", requested.m_kHandle);
        if (length < 0 || static_cast<std::size_t>(length) >= sizeof(filename))
            return false;
        staged.name = filename;

        auto append = [&staged](const char* value) noexcept {
            try {
                NiFixedString fixed(value);
                return staged.fallbacks.PushBack(fixed);
            } catch (...) {
                return false;
            }
        };
        const char* const* values = nullptr;
        std::size_t count = 0;
        static const char* const vs11[] = {"vs_1_1"};
        static const char* const vs20[] = {"vs_2_0", "vs_1_1"};
        static const char* const vs2a[] = {"vs_2_a", "vs_2_0", "vs_1_1"};
        static const char* const vs30[] = {"vs_3_0", "vs_2_a", "vs_2_0", "vs_1_1"};
        static const char* const ps11[] = {"ps_1_1"};
        static const char* const ps12[] = {"ps_1_2", "ps_1_1"};
        static const char* const ps13[] = {"ps_1_3", "ps_1_2", "ps_1_1"};
        static const char* const ps14[] = {"ps_1_4", "ps_1_3", "ps_1_2", "ps_1_1"};
        static const char* const ps20[] = {"ps_2_0", "ps_1_4", "ps_1_3", "ps_1_2", "ps_1_1"};
        static const char* const ps2a[] = {"ps_2_a", "ps_2_0", "ps_1_4", "ps_1_3", "ps_1_2", "ps_1_1"};
        static const char* const ps2b[] = {"ps_2_b", "ps_2_0", "ps_1_4", "ps_1_3", "ps_1_2", "ps_1_1"};
        static const char* const ps30[] = {"ps_3_0", "ps_2_a", "ps_2_0", "ps_1_4", "ps_1_3", "ps_1_2", "ps_1_1"};
#define SELECT(values_) do { values = values_; count = std::size(values_); } while (false)
        if (kind == 0) {
            if (requested == "vs_1_1") SELECT(vs11);
            else if (requested == "vs_2_0") SELECT(vs20);
            else if (requested == "vs_2_a") SELECT(vs2a);
            else if (requested == "vs_3_0") SELECT(vs30);
        } else if (kind == 2) {
            if (requested == "ps_1_1") SELECT(ps11);
            else if (requested == "ps_1_2") SELECT(ps12);
            else if (requested == "ps_1_3") SELECT(ps13);
            else if (requested == "ps_1_4") SELECT(ps14);
            else if (requested == "ps_2_0") SELECT(ps20);
            else if (requested == "ps_2_a") SELECT(ps2a);
            else if (requested == "ps_2_b") SELECT(ps2b);
            else if (requested == "ps_3_0") SELECT(ps30);
        }
#undef SELECT
        for (std::size_t index = 0; index < count; ++index)
            if (!append(values[index]))
                return false;

        name = std::move(staged.name);
        profile = std::move(staged.profile);
        suffix = std::move(staged.suffix);
        fallbacks = std::move(staged.fallbacks);
        return true;
    } catch (...) {
        return false;
    }
}

bool AssignObjectName(NiFixedString& destination, const NiFixedString& source) noexcept
{
    try {
        destination = source;
        return true;
    } catch (...) {
        return false;
    }
}

const void* TableIdentity() noexcept { return NiGlobalStringTable::Identity(); }
const void* NodeIdentity(const char* handle) noexcept { return NiGlobalStringTable::NodeIdentity(handle); }
bool Owns(const char* handle) noexcept { return NiGlobalStringTable::Owns(handle); }
std::uint32_t RefCount(const char* handle) noexcept { return NiGlobalStringTable::RefCount(handle); }
std::size_t LiveNodeCount() noexcept { return NiGlobalStringTable::LiveNodeCount(); }

} // namespace fnv::strings
