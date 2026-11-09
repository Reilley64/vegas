#include "fnv/decl/MemoryManager.h"
#include "fnv/pathing/los_map_array.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <limits>

namespace {
void check(bool condition)
{
    if (!condition)
        std::abort();
}

class SaveBytes {
public:
    void Raw(const void* value, std::size_t size)
    {
        check(position_ + size + 1 <= bytes_.size());
        std::memcpy(bytes_.data() + position_, value, size);
        position_ += size;
        bytes_[position_++] = std::byte{'|'};
    }

    void Count(std::uint32_t count)
    {
        if (count <= 0x3fU) {
            const std::uint8_t value = static_cast<std::uint8_t>(count << 2U);
            Raw(&value, sizeof(value));
        } else if (count <= 0x3fffU) {
            const std::uint16_t value = static_cast<std::uint16_t>((count << 2U) | 1U);
            Raw(&value, sizeof(value));
        } else {
            const std::uint32_t value = (count << 2U) | 2U;
            Raw(&value, sizeof(value));
        }
    }

    void Entry(bool loaded, std::uint32_t value, const std::uint8_t* indices, std::uint32_t count)
    {
        const std::uint8_t flag = loaded ? 1U : 0U;
        Raw(&flag, sizeof(flag));
        Raw(&value, sizeof(value));
        if (!loaded) {
            Count(count);
            for (std::uint32_t i = 0; i < count; ++i)
                Raw(indices + i, 1);
        }
    }

    const void* Data() const { return bytes_.data(); }
    std::size_t Size() const { return position_; }

private:
    std::array<std::byte, 2048> bytes_{};
    std::size_t position_ = 0;
};

void set(BGSLoadGameBuffer& buffer, const SaveBytes& bytes)
{
    buffer.SetBuffer(bytes.Data(), bytes.Size());
}

void check_zero_one_many_loads()
{
    BGSLoadGameBuffer reader;
    FUN_006e0e80 record;

    SaveBytes zero;
    zero.Count(0);
    set(reader, zero);
    check(record.TryLoadEntries(reader));
    check(record.Size() == 0);

    const std::uint8_t oneIndices[] = {4, 8, 15};
    SaveBytes one;
    one.Count(1);
    one.Entry(false, 0x11223344U, oneIndices, 3);
    set(reader, one);
    check(record.TryLoadEntries(reader));
    check(record.Size() == 1);
    check(record.GetAt(0) != nullptr);
    check(!record.GetAt(0)->m_bIsLoaded);
    check(record.GetAt(0)->uiUnk18 == 0x11223344U);
    check(record.GetAt(0)->index.Size() == 3);
    check(record.GetAt(0)->index.Data()[0] == std::byte{4});
    check(record.GetAt(0)->index.Data()[2] == std::byte{15});

    const std::uint8_t manyIndices[] = {16, 23, 42, 64};
    SaveBytes many;
    many.Count(4);
    many.Entry(true, 1, nullptr, 0);
    many.Entry(false, 2, manyIndices, 1);
    many.Entry(false, 3, manyIndices, 4);
    many.Entry(true, 4, nullptr, 0);
    set(reader, many);
    check(record.TryLoadEntries(reader));
    check(record.Size() == 4);
    check(record.GetAt(0)->m_bIsLoaded);
    check(record.GetAt(1)->index.Size() == 1);
    check(record.GetAt(2)->index.Size() == 4);
    check(record.GetAt(3)->uiUnk18 == 4);
}

void check_resize_delete_and_reuse()
{
    FUN_006e1020_shell owner;
    check(owner.Resize(3));
    check(owner.Capacity() == 3);
    for (std::uint32_t i = 0; i < owner.Size(); ++i) {
        check(owner.ConstructAt(i));
        owner.GetAt(i)->uiUnk18 = 100 + i;
    }
    auto* first = owner.GetAt(0);
    check(owner.Resize(9));
    check(owner.GetAt(0) == first);
    check(owner.GetAt(0)->uiUnk18 == 100);
    check(owner.GetAt(8) == nullptr);
    check(owner.ConstructAt(8));
    auto* last = owner.GetAt(8);
    check(g_memoryManager.Owns(last));

    owner.DeleteAt(8);
    check(owner.GetAt(8) == nullptr);
    check(!g_memoryManager.Owns(last));
    check(owner.ConstructAt(8));
    check(owner.GetAt(8) != nullptr);

    check(owner.Resize(1, true));
    check(owner.Size() == 1);
    check(owner.Capacity() == 1);
    check(owner.GetAt(0) == first);
    auto* finalStorage = owner.Data();
    check(owner.FUN_006e1020() == &owner);
    check(owner.Data() == nullptr);
    check(owner.Capacity() == 0);
    check(!g_memoryManager.Owns(first));
    check(!g_memoryManager.Owns(finalStorage));
}

void check_malformed_truncated_and_retry()
{
    const std::uint8_t index = 9;
    SaveBytes valid;
    valid.Count(1);
    valid.Entry(false, 77, &index, 1);

    BGSLoadGameBuffer reader;
    FUN_006e0e80 record;
    set(reader, valid);
    check(record.TryLoadEntries(reader));
    auto* retainedRecord = record.GetAt(0);
    auto* retainedStorage = record.Data();

    const std::array<std::byte, 2> invalidCount{std::byte{3}, std::byte{'|'}};
    reader.SetBuffer(invalidCount.data(), invalidCount.size());
    check(!record.TryLoadEntries(reader));
    check(record.GetAt(0) == retainedRecord);
    check(record.Data() == retainedStorage);
    check(record.GetAt(0)->uiUnk18 == 77);

    SaveBytes truncated;
    truncated.Count(3);
    truncated.Entry(true, 1, nullptr, 0);
    truncated.Entry(true, 2, nullptr, 0);
    const std::uint8_t flag = 0;
    truncated.Raw(&flag, sizeof(flag)); // third record lacks its fixed value
    set(reader, truncated);
    check(!record.TryLoadEntries(reader));
    check(record.GetAt(0) == retainedRecord);
    check(record.Data() == retainedStorage);

    set(reader, valid);
    check(record.TryLoadEntries(reader));
    check(record.Size() == 1);
    check(record.GetAt(0)->uiUnk18 == 77);
}

void check_reallocation_failure_and_retry()
{
    FUN_006e1020_shell owner;
    check(owner.Resize(1));
    check(owner.ConstructAt(0));
    owner.GetAt(0)->uiUnk18 = 0xdecafbadU;
    auto* originalData = owner.Data();
    auto* originalEntry = owner.GetAt(0);

    g_memoryManager.InitializeHeaps();
    check(g_memoryManager.HeapsInitialized());
    check(!g_memoryManager.PoolsInitialized());

    // The actual manager rejects this small replacement until its fixed pools
    // are published. The native owner must retain the old allocation and data.
    check(!owner.Resize(8));
    check(owner.Data() == originalData);
    check(owner.GetAt(0) == originalEntry);
    check(owner.GetAt(0)->uiUnk18 == 0xdecafbadU);

    g_memoryManager.FUN_00866770();
    check(g_memoryManager.PoolsInitialized());
    check(owner.Resize(8));
    check(owner.GetAt(0) == originalEntry);
    check(owner.GetAt(0)->uiUnk18 == 0xdecafbadU);
    check(reinterpret_cast<std::uintptr_t>(owner.Data()) >
          std::numeric_limits<std::uint32_t>::max());
}

void check_normal_and_unwind_retirement()
{
    void* normalData = nullptr;
    void* normalEntry = nullptr;
    {
        FUN_006e1020_shell owner;
        check(owner.Resize(2));
        check(owner.ConstructAt(0));
        normalData = owner.Data();
        normalEntry = owner.GetAt(0);
        check(g_memoryManager.Owns(normalData));
        check(g_memoryManager.Owns(normalEntry));
    }
    check(!g_memoryManager.Owns(normalData));
    check(!g_memoryManager.Owns(normalEntry));

    void* unwindData = nullptr;
    void* unwindEntry = nullptr;
    try {
        FUN_006e1020_shell owner;
        check(owner.Resize(4));
        check(owner.ConstructAt(3));
        unwindData = owner.Data();
        unwindEntry = owner.GetAt(3);
        throw 77;
    } catch (int value) {
        check(value == 77);
    }
    check(!g_memoryManager.Owns(unwindData));
    check(!g_memoryManager.Owns(unwindEntry));
}
}

int main()
{
    check(!g_memoryManager.HeapsInitialized());
    check_zero_one_many_loads();
    check_resize_delete_and_reuse();
    check_malformed_truncated_and_retry();
    check_reallocation_failure_and_retry();
    check_normal_and_unwind_retirement();
    g_memoryManager.ShutdownHeaps();
    check(!g_memoryManager.HeapsInitialized());
    return 0;
}
