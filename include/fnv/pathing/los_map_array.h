#pragma once

#include <cstddef>
#include <cstdint>

class Actor;
class TESForm;
class TESObjectREFR;
class NavMeshInfo;
struct FUN_006e0480;

// The save-load buffer as the LOS map load reads it: the reader prefix that
// 008646b0 initializes behind the four virtual entries. The pointer has native
// width; the extent and cursor keep the source format's 32 bits.
struct BGSLoadFormBuffer {
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};

namespace fnv::pathing {

// Bounded view of one save-load buffer. It borrows the bytes and advances the
// owning buffer's own read cursor, so it interleaves with the other readers of
// the same buffer. Within the buffer's extent it reads exactly as the source
// readers 00864820 and 00864a60 do. Where they would read past the extent, the
// read is refused instead and changes neither cursor nor destination; that
// refusal is the one deliberate native difference.
class LOSSaveReader {
public:
    explicit LOSSaveReader(BGSLoadFormBuffer& buffer) noexcept;
    LOSSaveReader(const void* bytes, std::uint32_t size, std::uint32_t& readOffset) noexcept;

    std::size_t RemainingBytes() const noexcept;
    // Whether a payload of this size and its separator lie within the extent.
    bool CanReadRaw(std::size_t size) const noexcept;
    // 00864820: copies the payload and steps over the separator byte after it.
    // A separator other than '|' is reported through 00845cc0 and the read
    // still succeeds, as in the source.
    bool TryReadRaw(void* destination, std::size_t size);
    // 00864a60: a one-, two- or four-byte little-endian value whose low two
    // bits select the width; the count is the remaining 6, 14 or 30 bits. The
    // fourth tag reads as zero and consumes nothing, as in the source.
    bool TryReadElementCount(std::uint32_t& count);

private:
    const std::byte* bytes_;
    std::uint32_t size_;
    std::uint32_t* readOffset_;
};

// The byte array embedded in each LOS record. Its four virtual entries are the
// source table 0106cf0c: destroy, allocate, free and reallocate.
class LOSByteArray {
public:
    LOSByteArray() noexcept;
    LOSByteArray(const LOSByteArray&) = delete;
    LOSByteArray& operator=(const LOSByteArray&) = delete;
    virtual ~LOSByteArray() noexcept;

    bool Resize(std::uint32_t size, bool shrinkCapacity = false);
    void Clear(bool releaseStorage = true) noexcept;
    void Swap(LOSByteArray& other) noexcept;

    std::byte* Data() noexcept { return data_; }
    const std::byte* Data() const noexcept { return data_; }
    std::uint32_t Size() const noexcept { return size_; }
    std::uint32_t Capacity() const noexcept { return capacity_; }

protected:
    virtual std::byte* AllocateBytes(std::uint32_t count) noexcept;
    virtual void FreeBytes(std::byte* bytes) noexcept;
    virtual std::byte* ReallocateBytes(std::byte* bytes, std::uint32_t count) noexcept;

private:
    bool SetCapacity(std::uint32_t capacity) noexcept;

    std::byte* data_ = nullptr;
    std::uint32_t size_ = 0;
    std::uint32_t capacity_ = 0;
};

// The records of one 006e0d20 map load, held until the whole payload has
// loaded. Destruction deletes every record still held, newest first.
class LOSMapLoad {
public:
    LOSMapLoad() noexcept = default;
    LOSMapLoad(const LOSMapLoad&) = delete;
    LOSMapLoad& operator=(const LOSMapLoad&) = delete;
    ~LOSMapLoad() noexcept;

    // Reads the record count and reserves one slot per record.
    bool Begin(LOSSaveReader& reader);
    std::uint32_t Count() const noexcept { return count_; }

    // Allocates the next record through NewLOSRecord. Null when storage is
    // exhausted or every counted record exists.
    FUN_006e0480* NewRecord() noexcept;
    // Keeps the newest record under its nav mesh ID; a zero ID deletes it.
    void Keep(std::uint32_t navMeshID) noexcept;

    std::uint32_t KeptCount() const noexcept { return kept_; }
    std::uint32_t KeptID(std::uint32_t index) const noexcept;
    FUN_006e0480* KeptRecord(std::uint32_t index) const noexcept;
    // Ends this load's ownership of a kept record once the map has accepted it.
    void Release(std::uint32_t index) noexcept;

private:
    struct Slot {
        FUN_006e0480* record;
        std::uint32_t navMeshID;
    };

    Slot* slots_ = nullptr;
    std::uint32_t count_ = 0;
    std::uint32_t kept_ = 0;
    FUN_006e0480* newest_ = nullptr;
};

// Every producer of a map record allocates it here, with the global new the
// map's delete pairs with. Null when storage is exhausted.
// 006e0e80: an empty record with a null nav mesh info.
FUN_006e0480* NewLOSRecord() noexcept;
// 006e0730: an empty record that 006dfba0 then builds from the nav mesh, given
// here as the two values 006dfba0 reads from it. A record whose entries cannot
// be allocated is deleted.
FUN_006e0480* NewLOSRecord(NavMeshInfo* info, std::uint32_t entryCount) noexcept;

} // namespace fnv::pathing

// One genuine LOS save record. The native NavMeshInfo pointer is not serialized;
// the fixed-width value and byte indices are read from the save buffer.
struct FUN_006e0190 {
    FUN_006e0190() noexcept;
    FUN_006e0190(const FUN_006e0190&) = delete;
    FUN_006e0190& operator=(const FUN_006e0190&) = delete;
    ~FUN_006e0190() noexcept;

    bool TryLoad(fnv::pathing::LOSSaveReader& reader);

    // The flag byte exactly as saved. The source reads and writes it as one raw
    // byte and takes zero to mean that index bytes follow.
    std::uint8_t m_bIsLoaded = 0;
    fnv::pathing::LOSByteArray index;
    NavMeshInfo* pNavMeshInfo = nullptr;
    std::uint32_t uiUnk18 = ~std::uint32_t{0};
};

// Native owner for the pointer array initialized by the historical 006e1020
// entry. Its four virtual entries are the source table 0106cef8: destroy,
// allocate, free and reallocate. No generated vptr or fixed 32-bit pointer
// stride is installed.
struct FUN_006e1020_shell {
    FUN_006e1020_shell() noexcept;
    FUN_006e1020_shell(const FUN_006e1020_shell&) = delete;
    FUN_006e1020_shell& operator=(const FUN_006e1020_shell&) = delete;
    virtual ~FUN_006e1020_shell() noexcept;

    // Canonical provider for the retained source entry. The C++ constructor
    // calls it. It releases the existing contents, so unlike the source entry
    // it must only be called on a constructed array, never on raw storage.
    FUN_006e1020_shell* FUN_006e1020() noexcept;

    bool Resize(std::uint32_t newSize, bool shrinkCapacity = false);
    bool ConstructAt(std::uint32_t index);
    void DeleteAt(std::uint32_t index) noexcept;
    void Clear(bool releaseStorage = true) noexcept;
    void Swap(FUN_006e1020_shell& other) noexcept;

    FUN_006e0190* GetAt(std::uint32_t index) noexcept;
    const FUN_006e0190* GetAt(std::uint32_t index) const noexcept;
    FUN_006e0190** Data() noexcept { return data_; }
    FUN_006e0190* const* Data() const noexcept { return data_; }
    std::uint32_t Size() const noexcept { return size_; }
    std::uint32_t Capacity() const noexcept { return capacity_; }

protected:
    virtual FUN_006e0190** AllocateItems(std::uint32_t count) noexcept;
    virtual void FreeItems(FUN_006e0190** items) noexcept;
    virtual FUN_006e0190** ReallocateItems(FUN_006e0190** items, std::uint32_t count) noexcept;

private:
    bool SetCapacity(std::uint32_t capacity) noexcept;

    FUN_006e0190** data_ = nullptr;
    std::uint32_t size_ = 0;
    std::uint32_t capacity_ = 0;
};

// One LOS map record: the entry array at its start and the nav mesh it
// belongs to. 006e0e80, 006e0730 and 006e0a90 are its constructors and 006e04b0
// its destructor; none installs a table of its own, so the record contains the
// array rather than deriving from it, and it is deleted through its own type.
struct FUN_006e0480 {
    FUN_006e0480() noexcept;
    FUN_006e0480(const FUN_006e0480&) = delete;
    FUN_006e0480& operator=(const FUN_006e0480&) = delete;
    ~FUN_006e0480() noexcept;

    // Reads the count and every entry into a temporary owner. The live array
    // is replaced only after the whole payload has loaded.
    bool TryLoadEntries(fnv::pathing::LOSSaveReader& reader);
    // 006e0070 with its outcome: false leaves the record as it was.
    bool TryLoadGame(BGSLoadFormBuffer* buffer);
    void FUN_006e0070(BGSLoadFormBuffer* buffer);
    // 006dfba0, given the nav mesh's info and entry count. Unless the record
    // already has an info and that many entries, it gets one entry per index,
    // each with a zero flag, this info and its index, and then the info. False
    // when storage is exhausted, which leaves the record as it was.
    bool Rebuild(NavMeshInfo* info, std::uint32_t entryCount);

    FUN_006e1020_shell kEntries;
    NavMeshInfo* pNavMeshInfo = nullptr;
};
