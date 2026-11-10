#include "fnv/pathing/los_map_array.h"

#include "fnv/decl/MemoryManager.h"
#include "fnv/symbols_00401000.h"

#include <cstring>
#include <limits>
#include <new>
#include <utility>

// 00845cc0, the save-load diagnostic of the source readers.
void FUN_00845cc0(const char*, ...);

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

namespace fnv::pathing {

LOSSaveReader::LOSSaveReader(BGSLoadFormBuffer& buffer) noexcept
    : LOSSaveReader(buffer.pBuffer, buffer.iBufferSize, buffer.m_uiReadOffset)
{}

LOSSaveReader::LOSSaveReader(const void* bytes, std::uint32_t size, std::uint32_t& readOffset) noexcept
    : bytes_(static_cast<const std::byte*>(bytes)), size_(bytes ? size : 0), readOffset_(&readOffset)
{}

std::size_t LOSSaveReader::RemainingBytes() const noexcept
{
    return *readOffset_ <= size_ ? size_ - *readOffset_ : 0;
}

bool LOSSaveReader::CanReadRaw(std::size_t size) const noexcept
{
    return size < RemainingBytes();
}

bool LOSSaveReader::TryReadRaw(void* destination, std::size_t size)
{
    if ((size != 0 && !destination) || !CanReadRaw(size))
        return false;
    if (size != 0)
        std::memcpy(destination, bytes_ + *readOffset_, size);
    *readOffset_ += static_cast<std::uint32_t>(size);
    if (bytes_[*readOffset_] != std::byte{'|'})
        ::FUN_00845cc0("SAVELOAD: Invalid spacer hit while loading data from the buffer");
    *readOffset_ += 1;
    return true;
}

bool LOSSaveReader::TryReadElementCount(std::uint32_t& count)
{
    if (RemainingBytes() == 0)
        return false;

    const auto kind = std::to_integer<std::uint8_t>(bytes_[*readOffset_]) & 3U;
    const std::size_t width = kind == 0 ? 1 : kind == 1 ? 2 : kind == 2 ? 4 : 0;
    std::uint8_t encoded[4] = {};
    if (width != 0 && !TryReadRaw(encoded, width))
        return false;
    count = (std::uint32_t(encoded[0]) | std::uint32_t(encoded[1]) << 8U |
             std::uint32_t(encoded[2]) << 16U | std::uint32_t(encoded[3]) << 24U) >> 2U;
    return true;
}

LOSByteArray::LOSByteArray() noexcept = default;

LOSByteArray::~LOSByteArray() noexcept
{
    Clear(true);
}

std::byte* LOSByteArray::AllocateBytes(std::uint32_t count) noexcept
{
    return static_cast<std::byte*>(allocate_bytes(count));
}

void LOSByteArray::FreeBytes(std::byte* bytes) noexcept
{
    release_bytes(bytes);
}

std::byte* LOSByteArray::ReallocateBytes(std::byte* bytes, std::uint32_t count) noexcept
{
    return static_cast<std::byte*>(FUN_00401020()->Reallocate(bytes, count));
}

// 006e12c0: a full block is reallocated; otherwise the live bytes move to a
// new block before the old one is freed. Failure keeps the old block.
bool LOSByteArray::SetCapacity(std::uint32_t capacity) noexcept
{
    std::byte* replacement = nullptr;
    if (!data_) {
        replacement = AllocateBytes(capacity);
    } else if (size_ == capacity_) {
        replacement = ReallocateBytes(data_, capacity);
    } else if ((replacement = AllocateBytes(capacity))) {
        std::memcpy(replacement, data_, size_);
        FreeBytes(data_);
    }
    if (!replacement)
        return false;
    data_ = replacement;
    capacity_ = capacity;
    return true;
}

// 006e10c0.
bool LOSByteArray::Resize(std::uint32_t requested, bool shrinkCapacity)
{
    if (requested == 0) {
        Clear(shrinkCapacity);
        return true;
    }
    if (requested > capacity_ && !SetCapacity(requested))
        return false;
    const bool reduced = requested < size_;
    if (requested > size_)
        std::memset(data_ + size_, 0, requested - size_);
    size_ = requested;
    if (reduced && shrinkCapacity && requested <= capacity_ / 4U)
        SetCapacity(requested);
    return true;
}

void LOSByteArray::Clear(bool releaseStorage) noexcept
{
    size_ = 0;
    if (releaseStorage) {
        FreeBytes(data_);
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

LOSMapLoad::~LOSMapLoad() noexcept
{
    delete newest_;
    while (kept_ != 0)
        delete slots_[--kept_].record;
    release_bytes(slots_);
}

bool LOSMapLoad::Begin(LOSSaveReader& reader)
{
    // Each record consumes at least two packed 3-byte form IDs with their
    // separators; its entry count can be the tag that consumes nothing.
    constexpr std::size_t minimum_record_bytes = 8;
    std::uint32_t count = 0;
    if (slots_ || newest_ || !reader.TryReadElementCount(count))
        return false;
    if (count > reader.RemainingBytes() / minimum_record_bytes ||
        count > std::numeric_limits<unsigned int>::max() / sizeof(Slot))
        return false;
    if (count != 0) {
        slots_ = static_cast<Slot*>(allocate_bytes(std::size_t(count) * sizeof(Slot)));
        if (!slots_)
            return false;
    }
    count_ = count;
    return true;
}

FUN_006e0480* LOSMapLoad::NewRecord() noexcept
{
    if (newest_ || kept_ == count_)
        return nullptr;
    // The global new reports exhausted storage by throwing; no caller of the
    // map load handles an exception, so it ends here as a refused record.
    try {
        newest_ = new FUN_006e0480();
    } catch (const std::bad_alloc&) {
        newest_ = nullptr;
    }
    return newest_;
}

void LOSMapLoad::Keep(std::uint32_t navMeshID) noexcept
{
    if (navMeshID == 0 || !newest_)
        delete newest_;
    else
        slots_[kept_++] = Slot{newest_, navMeshID};
    newest_ = nullptr;
}

std::uint32_t LOSMapLoad::KeptID(std::uint32_t index) const noexcept
{
    return index < kept_ ? slots_[index].navMeshID : 0;
}

FUN_006e0480* LOSMapLoad::KeptRecord(std::uint32_t index) const noexcept
{
    return index < kept_ ? slots_[index].record : nullptr;
}

void LOSMapLoad::Release(std::uint32_t index) noexcept
{
    if (index < kept_)
        slots_[index].record = nullptr;
}

} // namespace fnv::pathing

FUN_006e0190::FUN_006e0190() noexcept = default;
FUN_006e0190::~FUN_006e0190() noexcept = default;

bool FUN_006e0190::TryLoad(fnv::pathing::LOSSaveReader& reader)
{
    std::uint8_t loaded = 0;
    std::uint32_t value = 0;
    if (!reader.TryReadRaw(&loaded, sizeof(loaded)) ||
        !reader.TryReadRaw(&value, sizeof(value)))
        return false;

    fnv::pathing::LOSByteArray replacement;
    if (loaded == 0) {
        std::uint32_t count = 0;
        if (!reader.TryReadElementCount(count) || count > reader.RemainingBytes() / 2U ||
            !replacement.Resize(count, true))
            return false;
        for (std::uint32_t i = 0; i < count; ++i) {
            if (!reader.TryReadRaw(replacement.Data() + i, 1))
                return false;
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

FUN_006e0190** FUN_006e1020_shell::ReallocateItems(FUN_006e0190** items, std::uint32_t count) noexcept
{
    if (count == 0 || count > maximum_pointer_count)
        return nullptr;
    return static_cast<FUN_006e0190**>(FUN_00401020()->Reallocate(
        items, static_cast<unsigned int>(std::size_t(count) * sizeof(FUN_006e0190*))));
}

// 006e12c0: a full block is reallocated; otherwise the live pointers move to a
// new block before the old one is freed. Failure keeps the old block.
bool FUN_006e1020_shell::SetCapacity(std::uint32_t capacity) noexcept
{
    FUN_006e0190** replacement = nullptr;
    if (!data_) {
        replacement = AllocateItems(capacity);
    } else if (size_ == capacity_) {
        replacement = ReallocateItems(data_, capacity);
    } else if ((replacement = AllocateItems(capacity))) {
        std::memcpy(replacement, data_, std::size_t(size_) * sizeof(*data_));
        FreeItems(data_);
    }
    if (!replacement)
        return false;
    data_ = replacement;
    capacity_ = capacity;
    return true;
}

// 006f2290.
bool FUN_006e1020_shell::Resize(std::uint32_t newSize, bool shrinkCapacity)
{
    if (newSize == 0) {
        Clear(shrinkCapacity);
        return true;
    }
    if (newSize > capacity_ && !SetCapacity(newSize))
        return false;
    if (newSize > size_)
        std::memset(data_ + size_, 0, std::size_t(newSize - size_) * sizeof(*data_));

    const bool reduced = newSize < size_;
    while (size_ > newSize) {
        DeleteAt(size_ - 1U);
        --size_;
    }
    size_ = newSize;
    if (reduced && shrinkCapacity && newSize <= capacity_ / 4U)
        SetCapacity(newSize);
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

FUN_006e0480::FUN_006e0480() noexcept = default;
FUN_006e0480::~FUN_006e0480() noexcept = default;

bool FUN_006e0480::TryLoadEntries(fnv::pathing::LOSSaveReader& reader)
{
    // Each entry holds at least its flag byte and 4-byte value, each followed
    // by its separator.
    constexpr std::size_t minimum_entry_bytes = 7;
    std::uint32_t count = 0;
    if (!reader.TryReadElementCount(count) || count > reader.RemainingBytes() / minimum_entry_bytes)
        return false;

    FUN_006e1020_shell replacement;
    if (!replacement.Resize(count, true))
        return false;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (!replacement.ConstructAt(i))
            return false;
        if (!replacement.GetAt(i)->TryLoad(reader))
            return false;
        replacement.GetAt(i)->pNavMeshInfo = pNavMeshInfo;
    }
    kEntries.Swap(replacement);
    return true;
}
