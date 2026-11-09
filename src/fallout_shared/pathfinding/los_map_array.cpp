#include "fnv/pathing/los_map_array.h"

#include "fnv/symbols_00401000.h"

#include <algorithm>
#include <cstring>
#include <limits>
#include <new>
#include <utility>

namespace {
constexpr std::uint32_t maximum_pointer_count =
    std::numeric_limits<unsigned int>::max() / sizeof(FUN_006e0190*);

void* allocate_bytes(std::size_t bytes) noexcept
{
    if (bytes > std::numeric_limits<unsigned int>::max())
        return nullptr;
    return FUN_00401000(static_cast<unsigned int>(bytes == 0 ? 1 : bytes));
}

void release_bytes(void* memory) noexcept
{
    if (memory)
        FUN_00401030(memory);
}
}

BGSLoadGameBuffer::BGSLoadGameBuffer() noexcept : pBuffer(nullptr), iBufferSize(0), m_uiReadOffset(0)
{}

BGSLoadGameBuffer::~BGSLoadGameBuffer() noexcept = default;

unsigned char BGSLoadGameBuffer::GetVersion()
{
    return 0;
}

TESForm* BGSLoadGameBuffer::GetForm()
{
    return nullptr;
}

TESObjectREFR* BGSLoadGameBuffer::GetReference()
{
    return nullptr;
}

Actor* BGSLoadGameBuffer::GetActor()
{
    return nullptr;
}

void BGSLoadGameBuffer::SetBuffer(const void* buffer, std::size_t size, std::size_t position) noexcept
{
    if ((!buffer && size != 0) || position > size ||
        size > std::numeric_limits<std::uint32_t>::max()) {
        pBuffer = nullptr;
        iBufferSize = 0;
        m_uiReadOffset = 0;
        return;
    }
    pBuffer = static_cast<const std::byte*>(buffer);
    iBufferSize = static_cast<std::uint32_t>(size);
    m_uiReadOffset = static_cast<std::uint32_t>(position);
}

const std::byte* BGSLoadGameBuffer::GetCurrentBufferPointer() const noexcept
{
    return pBuffer ? pBuffer + m_uiReadOffset : nullptr;
}

std::size_t BGSLoadGameBuffer::RemainingBytes() const noexcept
{
    return m_uiReadOffset <= iBufferSize ? iBufferSize - m_uiReadOffset : 0;
}

bool BGSLoadGameBuffer::TryReadRaw(void* destination, std::size_t size) noexcept
{
    if ((size != 0 && !destination) || !pBuffer || size == std::numeric_limits<std::size_t>::max())
        return false;
    const auto needed = size + 1;
    if (needed > RemainingBytes() || pBuffer[m_uiReadOffset + size] != std::byte{'|'})
        return false;
    if (size != 0)
        std::memcpy(destination, pBuffer + m_uiReadOffset, size);
    m_uiReadOffset += needed;
    return true;
}

bool BGSLoadGameBuffer::TryReadElementCount(std::uint32_t& count) noexcept
{
    if (!pBuffer || RemainingBytes() == 0)
        return false;

    const auto tag = std::to_integer<std::uint8_t>(pBuffer[m_uiReadOffset]);
    const auto kind = tag & 3U;
    const std::size_t width = kind == 0 ? 1 : kind == 1 ? 2 : kind == 2 ? 4 : 0;
    if (width == 0 || width + 1 > RemainingBytes() ||
        pBuffer[m_uiReadOffset + width] != std::byte{'|'})
        return false;

    std::uint32_t encoded = 0;
    for (std::size_t i = 0; i < width; ++i)
        encoded |= std::uint32_t(std::to_integer<std::uint8_t>(pBuffer[m_uiReadOffset + i])) << (i * 8U);
    const auto decoded = encoded >> 2U;
    m_uiReadOffset += width + 1;
    count = decoded;
    return true;
}

namespace fnv::pathing {

LOSByteArray::~LOSByteArray() noexcept
{
    Clear(true);
}

bool LOSByteArray::Resize(std::uint32_t requested, bool shrinkCapacity)
{
    if (requested > capacity_) {
        auto* replacement = static_cast<std::byte*>(allocate_bytes(requested));
        if (!replacement)
            return false;
        if (size_ != 0)
            std::memcpy(replacement, data_, size_);
        std::memset(replacement + size_, 0, requested - size_);
        release_bytes(data_);
        data_ = replacement;
        capacity_ = requested;
    } else if (requested > size_) {
        std::memset(data_ + size_, 0, requested - size_);
    }
    size_ = requested;

    if (shrinkCapacity && requested <= capacity_ / 4U) {
        if (requested == 0) {
            Clear(true);
        } else {
            auto* replacement = static_cast<std::byte*>(allocate_bytes(requested));
            if (replacement) {
                std::memcpy(replacement, data_, requested);
                release_bytes(data_);
                data_ = replacement;
                capacity_ = requested;
            }
        }
    }
    return true;
}

void LOSByteArray::Clear(bool releaseStorage) noexcept
{
    size_ = 0;
    if (releaseStorage) {
        release_bytes(data_);
        data_ = nullptr;
        capacity_ = 0;
    }
}

void LOSByteArray::Swap(LOSByteArray& other) noexcept
{
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

} // namespace fnv::pathing

FUN_006e0190::FUN_006e0190() noexcept = default;
FUN_006e0190::~FUN_006e0190() noexcept = default;

bool FUN_006e0190::TryLoad(BGSLoadGameBuffer& buffer)
{
    std::uint8_t loaded = 0;
    std::uint32_t value = 0;
    if (!buffer.TryReadRaw(&loaded, sizeof(loaded)) ||
        !buffer.TryReadRaw(&value, sizeof(value)))
        return false;

    fnv::pathing::LOSByteArray replacement;
    if (loaded == 0) {
        std::uint32_t count = 0;
        if (!buffer.TryReadElementCount(count) || count > buffer.RemainingBytes() / 2U ||
            !replacement.Resize(count))
            return false;
        for (std::uint32_t i = 0; i < count; ++i) {
            std::byte byte{};
            if (!buffer.TryReadRaw(&byte, sizeof(byte)))
                return false;
            replacement.Data()[i] = byte;
        }
    }

    index.Swap(replacement);
    m_bIsLoaded = loaded != 0;
    uiUnk18 = value;
    return true;
}

FUN_006e1020_shell::FUN_006e1020_shell() noexcept
{
    FUN_006e1020();
}

FUN_006e1020_shell::~FUN_006e1020_shell() noexcept
{
    Clear(true);
}

FUN_006e1020_shell* FUN_006e1020_shell::FUN_006e1020() noexcept
{
    Clear(true);
    return this;
}

FUN_006e0190** FUN_006e1020_shell::AllocateItems(std::uint32_t count) noexcept
{
    if (count == 0 || count > maximum_pointer_count)
        return nullptr;
    auto* items = static_cast<FUN_006e0190**>(
        allocate_bytes(std::size_t(count) * sizeof(FUN_006e0190*)));
    if (items)
        std::memset(items, 0, std::size_t(count) * sizeof(*items));
    return items;
}

void FUN_006e1020_shell::FreeItems(FUN_006e0190** items) noexcept
{
    release_bytes(items);
}

FUN_006e0190** FUN_006e1020_shell::ReallocateItems(
    FUN_006e0190** items, std::uint32_t oldCount, std::uint32_t newCount) noexcept
{
    if (newCount == 0) {
        FreeItems(items);
        return nullptr;
    }
    auto* replacement = AllocateItems(newCount);
    if (!replacement)
        return nullptr;
    const auto preserved = std::min(oldCount, newCount);
    if (preserved != 0)
        std::memcpy(replacement, items, std::size_t(preserved) * sizeof(*items));
    FreeItems(items);
    return replacement;
}

bool FUN_006e1020_shell::Resize(std::uint32_t newSize, bool shrinkCapacity)
{
    if (newSize > maximum_pointer_count)
        return false;

    if (newSize > capacity_) {
        auto* replacement = ReallocateItems(data_, size_, newSize);
        if (!replacement)
            return false;
        data_ = replacement;
        capacity_ = newSize;
    } else if (newSize > size_) {
        std::memset(data_ + size_, 0, std::size_t(newSize - size_) * sizeof(*data_));
    }

    while (size_ > newSize) {
        DeleteAt(size_ - 1U);
        --size_;
    }
    size_ = newSize;

    if (shrinkCapacity && newSize <= capacity_ / 4U) {
        if (newSize == 0) {
            FreeItems(data_);
            data_ = nullptr;
            capacity_ = 0;
        } else if (auto* replacement = ReallocateItems(data_, newSize, newSize)) {
            data_ = replacement;
            capacity_ = newSize;
        }
    }
    return true;
}

bool FUN_006e1020_shell::ConstructAt(std::uint32_t index)
{
    if (index >= size_)
        return false;
    if (data_[index])
        return true;
    void* storage = allocate_bytes(sizeof(FUN_006e0190));
    if (!storage)
        return false;
    data_[index] = new (storage) FUN_006e0190();
    return true;
}

void FUN_006e1020_shell::DeleteAt(std::uint32_t index) noexcept
{
    if (index >= size_ || !data_[index])
        return;
    data_[index]->~FUN_006e0190();
    release_bytes(data_[index]);
    data_[index] = nullptr;
}

void FUN_006e1020_shell::Clear(bool releaseStorage) noexcept
{
    while (size_ != 0) {
        DeleteAt(size_ - 1U);
        --size_;
    }
    if (releaseStorage) {
        FreeItems(data_);
        data_ = nullptr;
        capacity_ = 0;
    }
}

void FUN_006e1020_shell::Swap(FUN_006e1020_shell& other) noexcept
{
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

FUN_006e0190* FUN_006e1020_shell::GetAt(std::uint32_t index) noexcept
{
    return index < size_ ? data_[index] : nullptr;
}

const FUN_006e0190* FUN_006e1020_shell::GetAt(std::uint32_t index) const noexcept
{
    return index < size_ ? data_[index] : nullptr;
}

FUN_006e0480::~FUN_006e0480() noexcept = default;

bool FUN_006e0480::TryLoadEntries(BGSLoadGameBuffer& buffer)
{
    std::uint32_t count = 0;
    if (!buffer.TryReadElementCount(count) || count > buffer.RemainingBytes() / 7U)
        return false;

    FUN_006e1020_shell replacement;
    if (!replacement.Resize(count))
        return false;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (!replacement.ConstructAt(i))
            return false;
        replacement.GetAt(i)->pNavMeshInfo = pNavMeshInfo;
        if (!replacement.GetAt(i)->TryLoad(buffer))
            return false;
    }
    Swap(replacement);
    return true;
}

FUN_006e0e80::FUN_006e0e80() noexcept = default;
