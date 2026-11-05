#include "havok/InlineStorageString.h"
#include "havok/hkMemoryRouter.h"

#include <algorithm>
#include <cstring>
#include <cstdint>
#include <new>
#include <stdexcept>

namespace
{
constexpr int capacityMask = 0x3fffffff;
int Length(const char* text)
{
    const auto length = std::strlen(text);
    if (length >= capacityMask)
        throw std::length_error("Havok string capacity");
    return static_cast<int>(length);
}
int AliasOffset(const char* text, const char* data, int count)
{
    auto address = reinterpret_cast<std::uintptr_t>(text);
    auto start = reinterpret_cast<std::uintptr_t>(data);
    return address >= start && address - start < static_cast<unsigned int>(count)
               ? static_cast<int>(address - start) : -1;
}
int CombinedLength(int first, int second)
{
    if (second > capacityMask - 1 - first)
        throw std::length_error("Havok string capacity");
    return first + second;
}
}

// @fnv 0x00d623d0
InlineStorageString::InlineStorageString(const char* first, const char* second, const char* third,
                                       const char* fourth, const char* fifth, const char* sixth)
    : m_data(m_kStorage), m_iElementCount(1), m_iCapacityState(static_cast<int>(0x80000080u))
{
    m_data[0] = 0;
    try
    {
        AppendStrings(first, second, third, fourth, fifth, sixth);
    }
    catch (...)
    {
        if (allocator)
            allocator->bufFree(m_data, getCapacity());
        throw;
    }
}

// @fnv 0x00d61b10
InlineStorageString::InlineStorageString(const char* text, int length) : InlineStorageString()
{
    Append(text, length);
}

// @fnv 0x00d61f30
void InlineStorageString::AssignStrings(const char* first, const char* second, const char* third,
                                      const char* fourth, const char* fifth, const char* sixth)
{
    Clear();
    AppendStrings(first, second, third, fourth, fifth, sixth);
}

// @fnv 0x00d62140
void InlineStorageString::TrimToDirectory()
{
    const char* slash = std::strrchr(m_data, '/');
    const char* backslash = std::strrchr(m_data, '\\');
    const char* last = slash;
    if (backslash && (!last || backslash > last))
        last = backslash;
    SetLength(last ? static_cast<int>(last - m_data) : 0);
}

// @fnv 0x00d61b80
InlineStorageString::InlineStorageString(const InlineStorageString& other)
    : m_data(m_kStorage), m_iElementCount(1), m_iCapacityState(static_cast<int>(0x80000080u))
{
    m_data[0] = 0;
    if (other.m_iElementCount > getCapacity())
    {
        hkMemoryAllocator& owner = hkMemoryRouter::getInstance().temp();
        int bytes = other.m_iElementCount;
        void* block = owner.bufAlloc(bytes);
        if (!block)
            throw std::bad_alloc();
        m_data = static_cast<char*>(block);
        m_iCapacityState = bytes;
        allocator = &owner;
    }
    std::memcpy(m_data, other.m_data, other.m_iElementCount);
    m_iElementCount = other.m_iElementCount;
}

InlineStorageString::~InlineStorageString()
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000u) == 0)
        allocator->bufFree(m_data, getCapacity());
}

void InlineStorageString::Reserve(int count)
{
    const int capacity = getCapacity();
    if (capacity >= count)
        return;
    int bytes = std::max(count, capacity > capacityMask / 2 ? capacityMask : capacity * 2);
    hkMemoryAllocator& owner = allocator ? *allocator : hkMemoryRouter::getInstance().temp();
    void* block = owner.bufAlloc(bytes);
    if (!block)
        throw std::bad_alloc();
    std::memcpy(block, m_data, m_iElementCount);
    if ((m_iCapacityState & 0x80000000u) == 0)
        owner.bufFree(m_data, capacity);
    m_data = static_cast<char*>(block);
    m_iCapacityState = bytes;
    allocator = &owner;
}

void InlineStorageString::SetLength(int length)
{
    Reserve(length + 1);
    m_data[length] = 0;
    m_iElementCount = length + 1;
}

// @fnv 0x00d61cc0
void InlineStorageString::Clear() { SetLength(0); }

// @fnv 0x00d61e30
void InlineStorageString::AppendStrings(const char* first, const char* second, const char* third,
                                      const char* fourth, const char* fifth, const char* sixth)
{
    const char* strings[] = {first, second, third, fourth, fifth, sixth, nullptr};
    int lengths[6];
    int offsets[6];
    int total = getLength();
    int count = 0;
    while (strings[count])
    {
        offsets[count] = AliasOffset(strings[count], m_data, m_iElementCount);
        lengths[count] = Length(strings[count]);
        total = CombinedLength(total, lengths[count]);
        ++count;
    }
    Reserve(total + 1);
    int destination = getLength();
    for (int i = 0; i < count; ++i)
    {
        const char* source = offsets[i] < 0 ? strings[i] : m_data + offsets[i];
        std::memmove(m_data + destination, source, lengths[i]);
        destination += lengths[i];
    }
    m_data[total] = 0;
    m_iElementCount = total + 1;
}

void InlineStorageString::Append(const char* text, int length)
{
    if (length < 0)
        length = Length(text);
    const int offset = AliasOffset(text, m_data, m_iElementCount);
    const int previous = getLength();
    const int total = CombinedLength(previous, length);
    Reserve(total + 1);
    if (offset >= 0)
        text = m_data + offset;
    std::memmove(m_data + previous, text, length);
    m_data[total] = 0;
    m_iElementCount = total + 1;
}

InlineStorageString& InlineStorageString::operator=(const InlineStorageString& other)
{
    if (this != &other)
    {
        Reserve(other.m_iElementCount);
        std::memcpy(m_data, other.m_data, other.m_iElementCount);
        m_iElementCount = other.m_iElementCount;
    }
    return *this;
}

InlineStorageString& InlineStorageString::operator=(const char* text)
{
    const int length = text ? Length(text) : 0;
    Reserve(length + 1);
    if (length)
        std::memmove(m_data, text, length);
    m_data[length] = 0;
    m_iElementCount = length + 1;
    return *this;
}
InlineStorageString& InlineStorageString::operator+=(const char* text)
{
    Append(text);
    return *this;
}

// @fnv 0x00d62190
int InlineStorageString::FUN_00d62190(const char* from, const char* to, int replaceAll)
{
    const int fromLength = Length(from);
    const int toLength = Length(to);
    // An empty needle cannot advance the source cursor.
    if (!fromLength)
        return 0;
    int replaced = 0;
    if (toLength > fromLength)
    {
        InlineStorageString result;
        int start = 0;
        const char* match = std::strstr(m_data, from);
        if (!match)
            return 0;
        do
        {
            const int index = static_cast<int>(match - m_data);
            result.Append(m_data + start, index - start);
            result.Append(to, toLength);
            start = index + fromLength;
            replaced = 1;
            if (!replaceAll)
                break;
            match = std::strstr(m_data + start, from);
        } while (match);
        result.Append(m_data + start, getLength() - start);
        *this = result;
    }
    else
    {
        int source = 0;
        int destination = 0;
        const char* match = std::strstr(m_data, from);
        while (match)
        {
            const int index = static_cast<int>(match - m_data);
            while (source < index)
                m_data[destination++] = m_data[source++];
            for (int i = 0; i < toLength; ++i)
                m_data[destination++] = to[i];
            source += fromLength;
            if (!replaceAll)
                break;
            match = std::strstr(m_data + index + fromLength, from);
        }
        while (source < getLength())
            m_data[destination++] = m_data[source++];
        SetLength(destination);
    }
    return replaced;
}

// @fnv 0x00d2b360
const char* __cdecl FUN_00d2b360(const char* path, InlineStorageString* result)
{
    *result = path;
    for (char* character = result->m_data; *character; ++character)
        if (*character == '\\')
            *character = '/';
    result->FUN_00d62190("/./", "/", 1);
    if (std::strncmp(result->cString(), "./", 2) == 0)
        *result = result->cString() + 2;
    return result->cString();
}
