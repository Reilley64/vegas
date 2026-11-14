#include "fnv/decl/FUN_0044a4c0.h"
#include "fnv/decl/FUN_00b09480.h"
#include "fnv/symbols_00401000.h"

#include <algorithm>
#include <cerrno>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>
#include <utility>

namespace {
constexpr auto maximum_capacity = static_cast<FUN_0044a4c0::size_type>(
    std::numeric_limits<unsigned int>::max() - 1U);

int compare_ranges(const char* left, std::size_t leftSize, const char* right, std::size_t rightSize) noexcept
{
    const auto common = std::min(leftSize, rightSize);
    if (common != 0) {
        const int result = std::memcmp(left, right, common);
        if (result != 0)
            return result;
    }
    return leftSize < rightSize ? -1 : leftSize > rightSize ? 1 : 0;
}
}

FUN_0044a4c0::FUN_0044a4c0() noexcept
{
    storage_.small[0] = '\0';
}

FUN_0044a4c0::FUN_0044a4c0(const char* text) : FUN_0044a4c0()
{
    assign(text);
}

FUN_0044a4c0::FUN_0044a4c0(const FUN_0044a4c0& other) : FUN_0044a4c0()
{
    assign(other.data(), other.size());
}

FUN_0044a4c0::FUN_0044a4c0(FUN_0044a4c0&& other) noexcept : FUN_0044a4c0()
{
    move_from(other);
}

FUN_0044a4c0::~FUN_0044a4c0() noexcept
{
    retire_heap();
}

FUN_0044a4c0& FUN_0044a4c0::operator=(const FUN_0044a4c0& other)
{
    if (this != &other)
        assign(other.data(), other.size());
    return *this;
}

FUN_0044a4c0& FUN_0044a4c0::operator=(FUN_0044a4c0&& other) noexcept
{
    if (this != &other) {
        retire_heap();
        reset_small();
        move_from(other);
    }
    return *this;
}

FUN_0044a4c0& FUN_0044a4c0::operator=(const char* text)
{
    return assign(text);
}

FUN_0044a4c0::size_type FUN_0044a4c0::checked_capacity(size_type required, size_type current)
{
    if (required > maximum_capacity)
        throw std::length_error("native string is too long");
    if (required <= current)
        return current;
    const auto growth = current <= (maximum_capacity - 1U) / 2U ? current + current / 2U + 1U : maximum_capacity;
    return std::max(required, growth);
}

char* FUN_0044a4c0::allocate(size_type capacity)
{
    if (capacity > maximum_capacity)
        throw std::length_error("native string is too long");
    auto* memory = static_cast<char*>(FUN_00401000(static_cast<unsigned int>(capacity + 1U)));
    if (!memory)
        throw std::bad_alloc();
    return memory;
}

void FUN_0044a4c0::release(char* memory) noexcept
{
    FUN_00401030(memory);
}

void FUN_0044a4c0::retire_heap() noexcept
{
    if (!uses_small_buffer())
        release(storage_.pointer);
}

void FUN_0044a4c0::reset_small() noexcept
{
    size_ = 0;
    capacity_ = small_capacity;
    storage_.small[0] = '\0';
}

void FUN_0044a4c0::move_from(FUN_0044a4c0& other) noexcept
{
    if (other.uses_small_buffer()) {
        size_ = other.size_;
        capacity_ = small_capacity;
        std::memcpy(storage_.small, other.storage_.small, size_ + 1U);
    } else {
        storage_.pointer = other.storage_.pointer;
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
    other.reset_small();
}

char* FUN_0044a4c0::data() noexcept
{
    return uses_small_buffer() ? storage_.small : storage_.pointer;
}

const char* FUN_0044a4c0::data() const noexcept
{
    return uses_small_buffer() ? storage_.small : storage_.pointer;
}

FUN_0044a4c0& FUN_0044a4c0::assign(const char* text)
{
    return text ? assign(text, std::strlen(text)) : assign("", 0);
}

FUN_0044a4c0& FUN_0044a4c0::assign(const char* text, size_type count)
{
    if (!text) {
        if (count != 0)
            throw std::invalid_argument("null native string source");
        clear();
        return *this;
    }
    if (count <= capacity_) {
        if (count != 0)
            std::memmove(data(), text, count);
        size_ = count;
        data()[size_] = '\0';
        return *this;
    }

    const auto replacementCapacity = checked_capacity(count, capacity_);
    char* replacement = allocate(replacementCapacity);
    if (count != 0)
        std::memcpy(replacement, text, count);
    replacement[count] = '\0';
    retire_heap();
    storage_.pointer = replacement;
    size_ = count;
    capacity_ = replacementCapacity;
    return *this;
}

FUN_0044a4c0& FUN_0044a4c0::assign(
    const FUN_0044a4c0& other, unsigned int offset, unsigned int count)
{
    if (offset > other.size())
        throw std::out_of_range("native string offset");
    const auto start = static_cast<size_type>(offset);
    const auto available = other.size() - start;
    const auto selected = std::min<size_type>(count, available);
    return assign(other.data() + start, selected);
}

FUN_0044a4c0& FUN_0044a4c0::AssignSubstring(
    const FUN_0044a4c0& other, unsigned int offset, unsigned int count)
{
    return assign(other, offset, count);
}

FUN_0044a4c0& FUN_0044a4c0::append(const char* text)
{
    return text ? append(text, std::strlen(text)) : *this;
}

FUN_0044a4c0& FUN_0044a4c0::append(const char* text, size_type count)
{
    if (!text) {
        if (count != 0)
            throw std::invalid_argument("null native string source");
        return *this;
    }
    if (count > maximum_capacity - size_)
        throw std::length_error("native string is too long");

    const auto oldSize = size_;
    const auto required = oldSize + count;
    if (required <= capacity_) {
        if (count != 0)
            std::memmove(data() + oldSize, text, count);
        size_ = required;
        data()[size_] = '\0';
        return *this;
    }

    const auto replacementCapacity = checked_capacity(required, capacity_);
    char* replacement = allocate(replacementCapacity);
    if (oldSize != 0)
        std::memcpy(replacement, data(), oldSize);
    if (count != 0)
        std::memcpy(replacement + oldSize, text, count);
    replacement[required] = '\0';
    retire_heap();
    storage_.pointer = replacement;
    size_ = required;
    capacity_ = replacementCapacity;
    return *this;
}

FUN_0044a4c0& FUN_0044a4c0::append(const FUN_0044a4c0& other)
{
    return append(other.data(), other.size());
}

void FUN_0044a4c0::clear() noexcept
{
    size_ = 0;
    data()[0] = '\0';
}

void FUN_0044a4c0::reserve(size_type requested)
{
    if (requested <= capacity_)
        return;
    const auto replacementCapacity = checked_capacity(requested, capacity_);
    char* replacement = allocate(replacementCapacity);
    std::memcpy(replacement, data(), size_ + 1U);
    retire_heap();
    storage_.pointer = replacement;
    capacity_ = replacementCapacity;
}

void FUN_0044a4c0::resize(size_type requested, char value)
{
    if (requested > capacity_)
        reserve(requested);
    if (requested > size_)
        std::memset(data() + size_, static_cast<unsigned char>(value), requested - size_);
    size_ = requested;
    data()[size_] = '\0';
}

void FUN_0044a4c0::swap(FUN_0044a4c0& other) noexcept
{
    if (this == &other)
        return;
    FUN_0044a4c0 temporary(std::move(other));
    other = std::move(*this);
    *this = std::move(temporary);
}

int FUN_0044a4c0::compare(const FUN_0044a4c0& other) const noexcept
{
    return compare_ranges(data(), size(), other.data(), other.size());
}

int FUN_0044a4c0::compare(const char* text) const noexcept
{
    if (!text)
        text = "";
    return compare_ranges(data(), size(), text, std::strlen(text));
}

int FUN_0044a4c0::ComparePart(
    unsigned int offset, unsigned int count, const char* text, unsigned int textCount) const
{
    if (offset > size_)
        throw std::out_of_range("native string offset");
    const auto selected = std::min<size_type>(count, size_ - offset);
    if (!text) {
        if (textCount != 0)
            throw std::invalid_argument("null native string source");
        text = "";
    }
    return compare_ranges(data() + offset, selected, text, textCount);
}

FUN_0044a4c0 FUN_00ad4210(const FUN_0044a4c0& left, const char* right)
{
    FUN_0044a4c0 result(left);
    result.append(right);
    return result;
}

FUN_0044a4c0 FUN_00ad42e0(const FUN_0044a4c0& left, const FUN_0044a4c0& right)
{
    FUN_0044a4c0 result(left);
    result.append(right);
    return result;
}

namespace {
FUN_0044a4c0 make_error_message(const FUN_0044a4c0& message, bool includeSystemError)
{
    FUN_0044a4c0 result(message);
    result.append(" [");
    if (includeSystemError)
        result.append(std::strerror(errno));
    result.append("]");
    return result;
}
}

FUN_00ec78e0::FUN_00ec78e0() noexcept = default;
FUN_00ec78e0::~FUN_00ec78e0() noexcept = default;

FUN_00b096a0::FUN_00b096a0(const FUN_0044a4c0& text) : message(text)
{}

FUN_00b096a0::~FUN_00b096a0() noexcept = default;

FUN_00b09480::FUN_00b09480(const FUN_0044a4c0& message, bool includeSystemError)
    : FUN_00b096a0(make_error_message(message, includeSystemError))
{}

FUN_00b09480::FUN_00b09480(const FUN_0044a4c0& message, unsigned char includeSystemError)
    : FUN_00b096a0(includeSystemError ? FUN_0044a4c0("e") : message)
{}

FUN_00b09480::~FUN_00b09480() noexcept = default;

// Formats the production SpeedTree parser/error text directly into the
// canonical owner. The destination is already a live object and is updated only
// after formatting succeeds.
FUN_0044a4c0* FUN_00b18860(FUN_0044a4c0* out, const char* format, ...)
{
    if (!out)
        return nullptr;
    if (!format) {
        out->clear();
        return out;
    }

    va_list arguments;
    va_start(arguments, format);
    va_list measured;
    va_copy(measured, arguments);
    const int required = std::vsnprintf(nullptr, 0, format, measured);
    va_end(measured);
    va_end(arguments);
    if (required < 0)
        throw std::runtime_error("native string formatting failed");

    char stack[1024];
    if (static_cast<std::size_t>(required) < sizeof(stack)) {
        va_start(arguments, format);
        const int written = std::vsnprintf(stack, sizeof(stack), format, arguments);
        va_end(arguments);
        if (written != required)
            throw std::runtime_error("native string formatting failed");
        out->assign(stack, static_cast<std::size_t>(written));
        return out;
    }

    FUN_0044a4c0 replacement;
    replacement.resize(static_cast<std::size_t>(required));
    va_start(arguments, format);
    const int written = std::vsnprintf(replacement.data(), replacement.size() + 1U, format, arguments);
    va_end(arguments);
    if (written != required)
        throw std::runtime_error("native string formatting failed");
    *out = std::move(replacement);
    return out;
}
