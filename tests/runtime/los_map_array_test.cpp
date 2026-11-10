#include "fnv/decl/MemoryManager.h"
#include "fnv/pathing/los_map_array.h"

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
#include <new>
#include <vector>

namespace {
int g_diagnostics = 0;
const char* g_lastDiagnostic = nullptr;
}

// The save-load diagnostic the production reader reports through. This
// definition is the observation point; the game's own forwards to its log.
void FUN_00845cc0(const char* format, ...)
{
    ++g_diagnostics;
    g_lastDiagnostic = format;
}

namespace {
using fnv::pathing::LOSMapLoad;
using fnv::pathing::LOSSaveReader;

void check(bool condition)
{
    if (!condition)
        std::abort();
}

// Whether exactly one wrong separator was reported since the last call.
bool one_separator_report()
{
    const bool one = g_diagnostics == 1 && g_lastDiagnostic &&
                     std::strcmp(g_lastDiagnostic,
                                 "SAVELOAD: Invalid spacer hit while loading data from the buffer") == 0;
    g_diagnostics = 0;
    g_lastDiagnostic = nullptr;
    return one;
}

// Synthetic save bytes in the source format: every value is followed by '|'.
class SaveBytes {
public:
    void Raw(const void* value, std::size_t size)
    {
        const auto* bytes = static_cast<const std::uint8_t*>(value);
        bytes_.insert(bytes_.end(), bytes, bytes + size);
        bytes_.push_back('|');
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

    void FormID(std::uint32_t id)
    {
        const std::uint8_t packed[3] = {
            static_cast<std::uint8_t>(id), static_cast<std::uint8_t>(id >> 8U),
            static_cast<std::uint8_t>(id >> 16U)};
        Raw(packed, sizeof(packed));
    }

    std::vector<std::uint8_t>& Bytes() { return bytes_; }
    const std::uint8_t* Data() const { return bytes_.data(); }
    std::uint32_t Size() const { return static_cast<std::uint32_t>(bytes_.size()); }

private:
    std::vector<std::uint8_t> bytes_;
};

bool load_entries(FUN_006e0480& record, const std::uint8_t* bytes, std::uint32_t size,
                  std::uint32_t* consumed = nullptr)
{
    std::uint32_t offset = 0;
    LOSSaveReader reader(bytes, size, offset);
    const bool loaded = record.TryLoadEntries(reader);
    check(!loaded || offset == size);
    if (consumed)
        *consumed = offset;
    return loaded;
}

bool load_entries(FUN_006e0480& record, const SaveBytes& bytes)
{
    return load_entries(record, bytes.Data(), bytes.Size());
}

void check_zero_one_many_loads()
{
    FUN_006e0480 record;
    check(record.pNavMeshInfo == nullptr);
    check(record.kEntries.Size() == 0 && record.kEntries.Data() == nullptr);
    int navMeshInfoPlace = 0;
    record.pNavMeshInfo = reinterpret_cast<NavMeshInfo*>(&navMeshInfoPlace);
    auto& entries = record.kEntries;

    SaveBytes zero;
    zero.Count(0);
    check(load_entries(record, zero));
    check(entries.Size() == 0);

    const std::uint8_t oneIndices[] = {4, 8, 15};
    SaveBytes one;
    one.Count(1);
    one.Entry(false, 0x11223344U, oneIndices, 3);
    check(load_entries(record, one));
    check(entries.Size() == 1);
    check(entries.GetAt(0) != nullptr);
    check(g_memoryManager.Size(entries.GetAt(0)) >= sizeof(FUN_006e0190));
    check(!entries.GetAt(0)->m_bIsLoaded);
    check(entries.GetAt(0)->uiUnk18 == 0x11223344U);
    check(entries.GetAt(0)->pNavMeshInfo == record.pNavMeshInfo);
    check(entries.GetAt(0)->index.Size() == 3);
    check(g_memoryManager.Owns(entries.GetAt(0)->index.Data()));
    check(entries.GetAt(0)->index.Data()[0] == std::byte{4});
    check(entries.GetAt(0)->index.Data()[2] == std::byte{15});

    const std::uint8_t manyIndices[] = {16, 23, 42, 64};
    SaveBytes many;
    many.Count(4);
    many.Entry(true, 1, nullptr, 0);
    many.Entry(false, 2, manyIndices, 1);
    many.Entry(false, 3, manyIndices, 4);
    many.Entry(true, 4, nullptr, 0);
    check(load_entries(record, many));
    check(entries.Size() == 4);
    check(entries.GetAt(0)->m_bIsLoaded);
    check(entries.GetAt(0)->index.Size() == 0);
    check(entries.GetAt(1)->index.Size() == 1);
    check(entries.GetAt(2)->index.Size() == 4);
    check(entries.GetAt(2)->index.Data()[3] == std::byte{64});
    check(entries.GetAt(3)->uiUnk18 == 4);
    check(g_diagnostics == 0);
}

void check_resize_delete_and_reuse()
{
    FUN_006e1020_shell owner;
    check(owner.Resize(3));
    check(owner.Capacity() == 3);
    check(g_memoryManager.Size(owner.Data()) >= 3 * sizeof(FUN_006e0190*));
    for (std::uint32_t i = 0; i < owner.Size(); ++i) {
        check(owner.ConstructAt(i));
        owner.GetAt(i)->uiUnk18 = 100 + i;
    }
    auto* first = owner.GetAt(0);
    // A full block grows through the reallocation entry.
    check(owner.Resize(9));
    check(owner.GetAt(0) == first);
    check(owner.GetAt(2)->uiUnk18 == 102);
    check(owner.GetAt(8) == nullptr);
    check(owner.ConstructAt(8));
    auto* last = owner.GetAt(8);
    check(g_memoryManager.Owns(last));

    owner.DeleteAt(8);
    check(owner.GetAt(8) == nullptr);
    check(!g_memoryManager.Owns(last));
    check(owner.ConstructAt(8));
    check(owner.GetAt(8) != nullptr);

    // A partly used block grows through allocate, copy and free.
    auto* third = owner.GetAt(2);
    check(owner.Resize(2));
    check(owner.Capacity() == 9);
    check(!g_memoryManager.Owns(third));
    auto* partlyUsed = owner.Data();
    check(owner.Resize(12));
    check(owner.Capacity() == 12);
    check(!g_memoryManager.Owns(partlyUsed));
    check(owner.GetAt(0) == first);
    check(owner.GetAt(1)->uiUnk18 == 101);
    check(owner.GetAt(11) == nullptr);

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

void check_byte_array_reallocation()
{
    FUN_006e0190 record;
    auto& index = record.index;
    check(index.Data() == nullptr);
    check(index.Resize(4));
    check(g_memoryManager.Owns(index.Data()));
    for (std::uint32_t i = 0; i < 4; ++i)
        index.Data()[i] = std::byte(i + 1);
    check(index.Resize(8)); // full block: reallocation entry
    check(index.Capacity() == 8);
    check(index.Data()[3] == std::byte{4});
    check(index.Data()[7] == std::byte{0});
    check(index.Resize(2));
    check(index.Capacity() == 8);
    auto* partlyUsed = index.Data();
    check(index.Resize(16)); // partly used block: allocate, copy and free
    check(!g_memoryManager.Owns(partlyUsed));
    check(index.Data()[1] == std::byte{2});
    check(index.Data()[2] == std::byte{0});
    check(index.Resize(1, true));
    check(index.Capacity() == 1);
    check(index.Data()[0] == std::byte{1});
    auto* last = index.Data();
    check(index.Resize(0, true));
    check(index.Data() == nullptr);
    check(!g_memoryManager.Owns(last));
}

struct CountCase {
    std::uint32_t count;
    std::uint32_t width;
};

void check_count_widths_truncation_and_separators()
{
    const CountCase cases[] = {
        {0, 1}, {1, 1}, {0x3f, 1}, {0x40, 2}, {0x3fff, 2}, {0x4000, 4}, {0x3fffffff, 4}};
    for (const auto& item : cases) {
        SaveBytes bytes;
        bytes.Count(item.count);
        check(bytes.Size() == item.width + 1);

        std::uint32_t offset = 0;
        std::uint32_t count = 0xa5a5a5a5U;
        LOSSaveReader reader(bytes.Data(), bytes.Size(), offset);
        check(reader.TryReadElementCount(count));
        check(count == item.count);
        check(offset == item.width + 1);
        check(reader.RemainingBytes() == 0);

        // Every shorter extent, including the one lacking only the separator.
        for (std::uint32_t size = 0; size < bytes.Size(); ++size) {
            offset = 0;
            count = 0xa5a5a5a5U;
            LOSSaveReader truncated(bytes.Data(), size, offset);
            check(!truncated.TryReadElementCount(count));
            check(count == 0xa5a5a5a5U);
            check(offset == 0);
        }

        // A wrong separator is reported and the count still reads as the
        // source reads it.
        bytes.Bytes().back() = 0;
        offset = 0;
        count = 0xa5a5a5a5U;
        check(g_diagnostics == 0);
        LOSSaveReader unseparated(bytes.Data(), bytes.Size(), offset);
        check(unseparated.TryReadElementCount(count));
        check(count == item.count);
        check(offset == item.width + 1);
        check(one_separator_report());
    }

    // The fourth tag reads as zero and consumes nothing, at any extent that
    // holds the tag byte.
    const std::uint8_t reserved[] = {3, '|', 0, 0, '|'};
    std::uint32_t offset = 0;
    std::uint32_t count = 7;
    for (std::uint32_t size = 1; size <= sizeof(reserved); ++size) {
        count = 7;
        LOSSaveReader tagged(reserved, size, offset);
        check(tagged.TryReadElementCount(count));
        check(count == 0 && offset == 0);
    }
    LOSSaveReader reader(reserved, sizeof(reserved), offset);
    check(g_diagnostics == 0);

    // A cursor already past the extent, a null destination and a size whose
    // separator position would wrap are all refused without a read.
    count = 7;
    offset = 9;
    check(reader.RemainingBytes() == 0);
    check(!reader.CanReadRaw(0));
    check(!reader.TryReadElementCount(count));
    offset = 0;
    check(!reader.TryReadRaw(nullptr, 1));
    check(!reader.TryReadRaw(&count, SIZE_MAX));
    check(!reader.TryReadRaw(&count, sizeof(reserved)));
    check(!reader.CanReadRaw(sizeof(reserved)));
    check(reader.CanReadRaw(sizeof(reserved) - 1));
    check(count == 7 && offset == 0);

    std::uint32_t emptyOffset = 0;
    LOSSaveReader empty(nullptr, 16, emptyOffset);
    check(empty.RemainingBytes() == 0);
    check(!empty.TryReadElementCount(count));
    check(g_diagnostics == 0);
}

void check_wide_counts_through_loader()
{
    // 64 entries need the two-byte count; one entry has 64 index bytes.
    std::vector<std::uint8_t> indices(64);
    for (std::size_t i = 0; i < indices.size(); ++i)
        indices[i] = static_cast<std::uint8_t>(i * 3);
    SaveBytes wide;
    wide.Count(64);
    for (std::uint32_t i = 0; i < 64; ++i)
        wide.Entry(i != 5, i, indices.data(), 64);
    FUN_006e0480 record;
    auto& entries = record.kEntries;
    check(load_entries(record, wide));
    check(entries.Size() == 64);
    check(entries.GetAt(5)->index.Size() == 64);
    check(entries.GetAt(5)->index.Data()[63] == std::byte(63 * 3));
    check(entries.GetAt(63)->uiUnk18 == 63);

    // 0x4000 entries need the four-byte count.
    SaveBytes widest;
    widest.Count(0x4000);
    for (std::uint32_t i = 0; i < 0x4000; ++i)
        widest.Entry(true, i ^ 0x55aa0000U, nullptr, 0);
    check(load_entries(record, widest));
    check(entries.Size() == 0x4000);
    check(entries.GetAt(0x3fff)->uiUnk18 == (0x3fffU ^ 0x55aa0000U));
    check(entries.GetAt(0x3fff)->m_bIsLoaded);
}

void check_separators_truncation_bounds_and_retry()
{
    const std::uint8_t index = 9;
    SaveBytes valid;
    valid.Count(1);
    valid.Entry(false, 77, &index, 1);

    FUN_006e0480 record;
    auto& entries = record.kEntries;
    check(load_entries(record, valid));
    auto* retainedRecord = entries.GetAt(0);
    auto* retainedStorage = entries.Data();
    const auto retained = [&] {
        return entries.Size() == 1 && entries.GetAt(0) == retainedRecord &&
               entries.Data() == retainedStorage && entries.GetAt(0)->uiUnk18 == 77 &&
               entries.GetAt(0)->index.Size() == 1 &&
               entries.GetAt(0)->index.Data()[0] == std::byte{9};
    };

    const std::uint8_t indices[] = {1, 2, 3};
    SaveBytes payload;
    payload.Count(3);
    payload.Entry(true, 1, nullptr, 0);
    payload.Entry(false, 2, indices, 3);
    payload.Entry(false, 3, indices, 0);
    const auto payload_loaded = [&] {
        return entries.Size() == 3 && entries.GetAt(0)->m_bIsLoaded &&
               entries.GetAt(0)->uiUnk18 == 1 && entries.GetAt(0)->index.Size() == 0 &&
               !entries.GetAt(1)->m_bIsLoaded && entries.GetAt(1)->uiUnk18 == 2 &&
               entries.GetAt(1)->index.Size() == 3 &&
               entries.GetAt(1)->index.Data()[0] == std::byte{1} &&
               entries.GetAt(1)->index.Data()[2] == std::byte{3} &&
               !entries.GetAt(2)->m_bIsLoaded && entries.GetAt(2)->uiUnk18 == 3 &&
               entries.GetAt(2)->index.Size() == 0;
    };

    // Every truncation point, which includes every field boundary, fails
    // after any partial construction and keeps the published owner.
    for (std::uint32_t size = 0; size < payload.Size(); ++size) {
        check(!load_entries(record, payload.Data(), size));
        check(retained());
    }
    check(g_diagnostics == 0);

    // Every wrong separator is reported once and loading continues: the
    // result is the one the undamaged payload gives.
    std::uint32_t separators = 0;
    for (std::uint32_t i = 0; i < payload.Size(); ++i) {
        if (payload.Data()[i] != '|')
            continue;
        ++separators;
        SaveBytes damaged = payload;
        damaged.Bytes()[i] = ' ';
        check(load_entries(record, valid));
        check(g_diagnostics == 0);
        check(load_entries(record, damaged));
        check(one_separator_report());
        check(payload_loaded());
    }
    // 1 count, 3 flags, 3 values, 2 index counts and 3 index bytes.
    check(separators == 12);
    check(load_entries(record, valid));
    retainedRecord = entries.GetAt(0);
    retainedStorage = entries.Data();
    check(retained());

    // Counts larger than the remaining bytes can hold are refused before any
    // storage is requested or any entry is read: the cursor rests after the
    // count. Entries first, then index bytes.
    std::uint32_t consumed = 0;
    SaveBytes overflow;
    overflow.Count(0x3fffffff);
    overflow.Entry(true, 1, nullptr, 0);
    check(!load_entries(record, overflow.Data(), overflow.Size(), &consumed));
    check(consumed == 5);
    check(retained());
    // Two entries claimed where the bytes hold one complete entry.
    SaveBytes shortEntries;
    shortEntries.Count(2);
    shortEntries.Entry(true, 1, nullptr, 0);
    shortEntries.Entry(true, 2, nullptr, 0);
    check(!load_entries(record, shortEntries.Data(), shortEntries.Size() - 1, &consumed));
    check(consumed == 2);
    check(retained());
    SaveBytes indexOverflow;
    indexOverflow.Count(1);
    indexOverflow.Entry(false, 1, indices, 0);
    indexOverflow.Bytes().resize(indexOverflow.Size() - 2);
    const std::uint32_t indexCountAt = indexOverflow.Size();
    indexOverflow.Count(0x3fffffff);
    indexOverflow.Raw(indices, 1);
    check(!load_entries(record, indexOverflow.Data(), indexOverflow.Size(), &consumed));
    check(consumed == indexCountAt + 5);
    check(retained());
    // Two index bytes claimed where the bytes hold one and a half.
    SaveBytes shortIndex;
    shortIndex.Count(1);
    shortIndex.Entry(false, 1, indices, 2);
    check(!load_entries(record, shortIndex.Data(), shortIndex.Size() - 1, &consumed));
    check(consumed == shortIndex.Size() - 4);
    check(retained());
    check(g_diagnostics == 0);

    // The fourth count tag is zero entries: the record is emptied, and the tag
    // byte is not consumed.
    const std::uint8_t reservedCount[] = {3};
    std::uint32_t offset = 0;
    {
        LOSSaveReader reader(reservedCount, sizeof(reservedCount), offset);
        check(record.TryLoadEntries(reader));
    }
    check(offset == 0);
    check(entries.Size() == 0 && entries.Data() == nullptr);
    check(!g_memoryManager.Owns(retainedRecord));
    check(!g_memoryManager.Owns(retainedStorage));
    // The same tag as an index count gives an entry with no index bytes.
    const std::uint8_t reservedIndexCount[] = {4, '|', 0, '|', 5, 0, 0, 0, '|', 7};
    offset = 0;
    {
        LOSSaveReader reader(reservedIndexCount, sizeof(reservedIndexCount), offset);
        check(record.TryLoadEntries(reader));
    }
    check(offset == sizeof(reservedIndexCount) - 1);
    check(entries.Size() == 1 && entries.GetAt(0)->uiUnk18 == 5);
    check(!entries.GetAt(0)->m_bIsLoaded && entries.GetAt(0)->index.Size() == 0);

    check(load_entries(record, payload));
    check(payload_loaded());
    check(load_entries(record, valid));
    check(entries.Size() == 1);
    check(entries.GetAt(0)->uiUnk18 == 77);
    check(g_diagnostics == 0);
}

bool read_form_id(LOSSaveReader& reader, std::uint32_t& id)
{
    std::uint8_t packed[3] = {};
    if (!reader.CanReadRaw(sizeof(packed)) || !reader.TryReadRaw(packed, sizeof(packed)))
        return false;
    id = packed[0] | std::uint32_t(packed[1]) << 8U | std::uint32_t(packed[2]) << 16U;
    return true;
}

// The sequence 006e0d20 and 006e0070 run for each record. The packed form IDs
// are read as their raw bytes: translating them and finding the nav mesh
// belong to other owners. Null when the record cannot be made or loaded.
FUN_006e0480* load_record(LOSMapLoad& load, LOSSaveReader& reader, std::uint32_t& navMeshID)
{
    FUN_006e0480* record = load.NewRecord();
    std::uint32_t infoID = 0;
    if (!record || !read_form_id(reader, navMeshID) || !read_form_id(reader, infoID) ||
        !record->TryLoadEntries(reader))
        return nullptr;
    return record;
}

struct PublishedRecord {
    std::uint32_t navMeshID;
    FUN_006e0480* record;
};

// What a map holds and the three values beside it.
struct MapState {
    std::vector<PublishedRecord> records;
    float values[3] = {1.5F, 2.5F, 3.5F};
};

// The whole 006e0d20 sequence over the production owners, with a vector
// standing where the map's insert is. Every record the load ever made is
// appended to `made`.
bool load_map(MapState& map, const std::uint8_t* bytes, std::uint32_t size, std::uint32_t& offset,
              std::vector<FUN_006e0480*>& made)
{
    LOSSaveReader reader(bytes, size, offset);
    LOSMapLoad load;
    if (!load.Begin(reader))
        return false;
    for (std::uint32_t i = 0; i < load.Count(); ++i) {
        std::uint32_t navMeshID = 0;
        FUN_006e0480* record = load.NewRecord();
        if (record)
            made.push_back(record);
        std::uint32_t infoID = 0;
        if (!record || !read_form_id(reader, navMeshID) || !read_form_id(reader, infoID) ||
            !record->TryLoadEntries(reader))
            return false;
        load.Keep(navMeshID);
    }
    float values[3];
    for (float& value : values) {
        if (!reader.TryReadRaw(&value, sizeof(value)))
            return false;
    }
    std::memcpy(map.values, values, sizeof(values));
    for (std::uint32_t i = 0; i < load.KeptCount(); ++i) {
        map.records.push_back({load.KeptID(i), load.KeptRecord(i)});
        load.Release(i);
    }
    return true;
}

void append_map_record(SaveBytes& bytes, std::uint32_t navMeshID, std::uint32_t value)
{
    const std::uint8_t indices[] = {7, 8};
    bytes.FormID(navMeshID);
    bytes.FormID(navMeshID);
    bytes.Count(2);
    bytes.Entry(true, value, nullptr, 0);
    bytes.Entry(false, value + 1, indices, 2);
}

void check_map_load_publication_and_delete()
{
    SaveBytes bytes;
    bytes.Count(3);
    append_map_record(bytes, 0x00abcdefU, 10);
    append_map_record(bytes, 0, 20);
    append_map_record(bytes, 0x00000102U, 30);

    std::uint32_t offset = 0;
    std::uint32_t navMeshID = 0;
    LOSSaveReader reader(bytes.Data(), bytes.Size(), offset);
    FUN_006e0480* published[2] = {};
    void* discarded = nullptr;
    void* discardedEntry = nullptr;
    {
        LOSMapLoad load;
        check(load.Begin(reader));
        check(load.Count() == 3);

        FUN_006e0480* first = load_record(load, reader, navMeshID);
        check(first != nullptr);
        check(g_memoryManager.Size(first) >= sizeof(FUN_006e0480));
        check(first->kEntries.Size() == 2 && first->pNavMeshInfo == nullptr);
        // One record at a time: the next is refused until this one is kept.
        check(load.NewRecord() == nullptr);
        load.Keep(navMeshID);

        // A zero nav mesh ID deletes the record.
        FUN_006e0480* second = load_record(load, reader, navMeshID);
        check(second != nullptr && navMeshID == 0);
        discarded = second;
        discardedEntry = second->kEntries.GetAt(1);
        check(g_memoryManager.Owns(discardedEntry));
        load.Keep(navMeshID);
        check(!g_memoryManager.Owns(discarded));
        check(!g_memoryManager.Owns(discardedEntry));

        check(load_record(load, reader, navMeshID) != nullptr);
        load.Keep(navMeshID);
        check(offset == bytes.Size());

        check(load.KeptCount() == 2);
        check(load.KeptID(0) == 0x00abcdefU && load.KeptRecord(0) == first);
        check(load.KeptID(1) == 0x00000102U);
        check(load.KeptID(2) == 0 && load.KeptRecord(2) == nullptr);
        for (std::uint32_t i = 0; i < load.KeptCount(); ++i) {
            published[i] = load.KeptRecord(i);
            load.Release(i);
            check(load.KeptRecord(i) == nullptr);
        }
    }
    // Released records outlive the load; the map's delete retires each one
    // and everything it owns.
    check(published[0]->kEntries.GetAt(0)->uiUnk18 == 10);
    check(published[1]->kEntries.GetAt(1)->uiUnk18 == 31);
    for (FUN_006e0480* record : published) {
        void* entry = record->kEntries.GetAt(1);
        void* index = record->kEntries.GetAt(1)->index.Data();
        void* storage = record->kEntries.Data();
        check(g_memoryManager.Owns(index));
        delete record;
        check(!g_memoryManager.Owns(record));
        check(!g_memoryManager.Owns(entry));
        check(!g_memoryManager.Owns(index));
        check(!g_memoryManager.Owns(storage));
    }
    check(g_diagnostics == 0);
}

void check_map_load_rollback_and_retry()
{
    SaveBytes bytes;
    bytes.Count(3);
    append_map_record(bytes, 11, 1);
    append_map_record(bytes, 0, 2);
    append_map_record(bytes, 13, 3);
    const float saved[3] = {64.0F, 128.0F, -1.0F};
    for (const float& value : saved)
        bytes.Raw(&value, sizeof(value));

    // A map that already holds a record, as before the call.
    MapState map;
    FUN_006e0480* existing = new FUN_006e0480();
    map.records.push_back({99, existing});
    const auto unchanged = [&] {
        return map.records.size() == 1 && map.records[0].navMeshID == 99 &&
               map.records[0].record == existing && g_memoryManager.Owns(existing) &&
               map.values[0] == 1.5F && map.values[1] == 2.5F && map.values[2] == 3.5F;
    };

    // Truncation at every byte, which includes every field boundary of the
    // count, the records and the three trailing values: the load fails, every
    // record it made is retired, and the map and values are as before.
    std::uint32_t mostMade = 0;
    for (std::uint32_t size = 0; size < bytes.Size(); ++size) {
        std::uint32_t offset = 0;
        std::vector<FUN_006e0480*> made;
        check(!load_map(map, bytes.Data(), size, offset, made));
        check(offset <= size);
        for (FUN_006e0480* record : made)
            check(!g_memoryManager.Owns(record));
        if (made.size() > mostMade)
            mostMade = static_cast<std::uint32_t>(made.size());
        check(unchanged());
    }
    check(mostMade == 3);
    check(g_diagnostics == 0);

    // Retry after failure: the whole payload then loads and is published in
    // load order behind what the map held.
    std::uint32_t offset = 0;
    std::vector<FUN_006e0480*> made;
    check(load_map(map, bytes.Data(), bytes.Size(), offset, made));
    check(offset == bytes.Size());
    check(made.size() == 3);
    check(map.records.size() == 3 && map.records[0].record == existing);
    check(map.records[1].navMeshID == 11 && map.records[1].record == made[0]);
    check(map.records[2].navMeshID == 13 && map.records[2].record == made[2]);
    check(made[2]->kEntries.GetAt(1)->uiUnk18 == 4);
    check(std::memcmp(map.values, saved, sizeof(saved)) == 0);
    check(g_diagnostics == 0);

    // A wrong separator anywhere is reported once and the load gives the same
    // records and values.
    for (std::uint32_t i = 0; i < bytes.Size(); ++i) {
        if (bytes.Data()[i] != '|')
            continue;
        SaveBytes damaged = bytes;
        damaged.Bytes()[i] = 0;
        MapState other;
        std::vector<FUN_006e0480*> otherMade;
        offset = 0;
        check(load_map(other, damaged.Data(), damaged.Size(), offset, otherMade));
        check(one_separator_report());
        check(offset == bytes.Size());
        check(other.records.size() == 2);
        check(other.records[0].navMeshID == 11 && other.records[1].navMeshID == 13);
        check(other.records[1].record->kEntries.Size() == 2);
        check(other.records[1].record->kEntries.GetAt(0)->uiUnk18 == 3);
        check(other.records[1].record->kEntries.GetAt(1)->index.Size() == 2);
        check(other.records[1].record->kEntries.GetAt(1)->index.Data()[1] == std::byte{8});
        check(std::memcmp(other.values, saved, sizeof(saved)) == 0);
        for (const PublishedRecord& item : other.records)
            delete item.record;
    }
    for (const PublishedRecord& item : map.records)
        delete item.record;

    // A partly published load retires only what the map did not accept.
    offset = 0;
    std::uint32_t navMeshID = 0;
    FUN_006e0480* accepted = nullptr;
    void* unaccepted = nullptr;
    {
        LOSSaveReader reader(bytes.Data(), bytes.Size(), offset);
        LOSMapLoad load;
        check(load.Begin(reader));
        for (std::uint32_t i = 0; i < load.Count(); ++i) {
            check(load_record(load, reader, navMeshID) != nullptr);
            load.Keep(navMeshID);
        }
        check(load.KeptCount() == 2);
        accepted = load.KeptRecord(0);
        unaccepted = load.KeptRecord(1);
        load.Release(0);
    }
    check(g_memoryManager.Owns(accepted));
    check(!g_memoryManager.Owns(unaccepted));
    delete accepted;
    check(!g_memoryManager.Owns(accepted));

    // A record count the remaining bytes cannot hold is refused before any
    // slot or record is requested: the cursor rests after the count.
    SaveBytes overflow;
    overflow.Count(0x3fffffff);
    append_map_record(overflow, 1, 1);
    offset = 0;
    {
        LOSSaveReader reader(overflow.Data(), overflow.Size(), offset);
        LOSMapLoad load;
        check(!load.Begin(reader));
        check(load.Count() == 0 && offset == 5);
        check(load.NewRecord() == nullptr);
    }
    // Two records claimed where the bytes hold fifteen: no record is made.
    SaveBytes shortRecords;
    shortRecords.Count(2);
    shortRecords.FormID(1);
    shortRecords.FormID(1);
    shortRecords.FormID(2);
    shortRecords.FormID(2);
    offset = 0;
    made.clear();
    {
        MapState none;
        check(!load_map(none, shortRecords.Data(), shortRecords.Size() - 1, offset, made));
        check(made.empty() && offset == 2);
    }
    // The fourth tag is a count of zero and is not consumed; a second Begin
    // and a record beyond the count are refused.
    const std::uint8_t reserved[] = {7, '|'};
    offset = 0;
    {
        LOSSaveReader reader(reserved, sizeof(reserved), offset);
        LOSMapLoad load;
        check(load.Begin(reader));
        check(load.Count() == 0 && load.KeptCount() == 0 && offset == 0);
        check(load.NewRecord() == nullptr);
    }
    // Records whose entry count is that tag consume eight bytes each.
    SaveBytes tagged;
    tagged.Count(2);
    tagged.FormID(21);
    tagged.FormID(21);
    tagged.FormID(0x7f);
    tagged.FormID(22);
    const std::uint8_t tag = 3;
    tagged.Raw(&tag, 0);
    tagged.Bytes().back() = tag;
    offset = 0;
    {
        LOSSaveReader reader(tagged.Data(), tagged.Size(), offset);
        LOSMapLoad load;
        check(load.Begin(reader));
        check(load.Count() == 2);
        for (std::uint32_t i = 0; i < 2; ++i) {
            FUN_006e0480* record = load_record(load, reader, navMeshID);
            check(record != nullptr && record->kEntries.Size() == 0);
            load.Keep(navMeshID);
        }
        check(load.KeptCount() == 2 && load.KeptID(0) == 21 && load.KeptID(1) == 0x7f);
        check(offset == tagged.Size() - 1);
    }
    check(g_diagnostics == 0);
}

void check_allocation_failure_and_retry()
{
    // Partly used blocks: growth must allocate a replacement.
    FUN_006e1020_shell owner;
    check(owner.Resize(2));
    check(owner.ConstructAt(0));
    check(owner.Resize(1));
    owner.GetAt(0)->uiUnk18 = 0xdecafbadU;
    auto* originalData = owner.Data();
    auto* originalEntry = owner.GetAt(0);

    FUN_006e0190 record;
    check(record.index.Resize(4));
    check(record.index.Resize(2));
    record.index.Data()[1] = std::byte{0x5a};
    auto* originalIndex = record.index.Data();

    SaveBytes few;
    few.Count(2);
    append_map_record(few, 1, 40);
    append_map_record(few, 2, 50);
    // Enough records that the slot block is not a fixed-pool request.
    SaveBytes many;
    many.Count(64);
    for (std::uint32_t i = 0; i < 64; ++i)
        append_map_record(many, 100 + i, 1000 + i);

    FUN_006e0480 loaded;
    SaveBytes one;
    one.Count(1);
    one.Entry(true, 5, nullptr, 0);
    check(load_entries(loaded, one));
    auto* loadedEntry = loaded.kEntries.GetAt(0);

    g_memoryManager.InitializeHeaps();
    check(g_memoryManager.HeapsInitialized());
    check(!g_memoryManager.PoolsInitialized());

    // The actual manager rejects these small requests until its fixed pools
    // are published. Each owner must retain its old allocation and data.
    check(!owner.Resize(8));
    check(!owner.Resize(UINT32_MAX / sizeof(FUN_006e0190*) + 1));
    check(!owner.Resize(UINT32_MAX));
    check(owner.Data() == originalData);
    check(owner.Size() == 1 && owner.Capacity() == 2);
    check(owner.GetAt(0) == originalEntry);
    check(owner.GetAt(0)->uiUnk18 == 0xdecafbadU);

    check(!record.index.Resize(8));
    check(!record.index.Resize(UINT32_MAX));
    check(record.index.Data() == originalIndex);
    check(record.index.Size() == 2 && record.index.Capacity() == 4);
    check(record.index.Data()[1] == std::byte{0x5a});

    check(!load_entries(loaded, one));
    check(loaded.kEntries.Size() == 1 && loaded.kEntries.GetAt(0) == loadedEntry);

    // A small slot block cannot be allocated.
    std::uint32_t offset = 0;
    std::uint32_t navMeshID = 0;
    {
        LOSSaveReader reader(few.Data(), few.Size(), offset);
        LOSMapLoad load;
        check(!load.Begin(reader));
        check(load.Count() == 0);
    }
    // A larger one can, but the record cannot: the global new's failure ends
    // as a refused record, nothing is thrown and nothing is left behind.
    offset = 0;
    {
        LOSSaveReader reader(many.Data(), many.Size(), offset);
        LOSMapLoad load;
        check(load.Begin(reader));
        check(load.Count() == 64);
        check(load.NewRecord() == nullptr);
        check(load_record(load, reader, navMeshID) == nullptr);
        check(load.KeptCount() == 0);
    }
    {
        MapState map;
        std::vector<FUN_006e0480*> made;
        offset = 0;
        check(!load_map(map, many.Data(), many.Size(), offset, made));
        check(made.empty() && map.records.empty() && map.values[0] == 1.5F);
    }

    g_memoryManager.FUN_00866770();
    check(g_memoryManager.PoolsInitialized());
    check(owner.Resize(8));
    check(owner.GetAt(0) == originalEntry);
    check(owner.GetAt(0)->uiUnk18 == 0xdecafbadU);
    check(reinterpret_cast<std::uintptr_t>(owner.Data()) > UINT32_MAX);
    check(record.index.Resize(8));
    check(record.index.Data()[1] == std::byte{0x5a});
    check(load_entries(loaded, one));
    check(loaded.kEntries.GetAt(0)->uiUnk18 == 5);

    for (const SaveBytes* bytes : {&few, &many}) {
        offset = 0;
        LOSSaveReader reader(bytes->Data(), bytes->Size(), offset);
        LOSMapLoad load;
        check(load.Begin(reader));
        for (std::uint32_t i = 0; i < load.Count(); ++i) {
            FUN_006e0480* grid = load_record(load, reader, navMeshID);
            check(grid != nullptr);
            check(reinterpret_cast<std::uintptr_t>(grid) > UINT32_MAX);
            check(grid->kEntries.Size() == 2);
            load.Keep(navMeshID);
        }
        check(load.KeptCount() == load.Count());
        check(offset == bytes->Size());
    }
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
    check_byte_array_reallocation();
    check_count_widths_truncation_and_separators();
    check_wide_counts_through_loader();
    check_separators_truncation_bounds_and_retry();
    check_map_load_publication_and_delete();
    check_map_load_rollback_and_retry();
    check_allocation_failure_and_retry();
    check_normal_and_unwind_retirement();
    check(g_diagnostics == 0);
    g_memoryManager.ShutdownHeaps();
    check(!g_memoryManager.HeapsInitialized());
    return 0;
}
