#pragma once

#include "fnv/decl/BGSLoadFormBuffer.h"

#include <cstddef>
#include <cstdint>

struct NavMeshInfo;

namespace fnv::pathing {

class LOSByteArray {
public:
    LOSByteArray() noexcept = default;
    LOSByteArray(const LOSByteArray&) = delete;
    LOSByteArray& operator=(const LOSByteArray&) = delete;
    ~LOSByteArray() noexcept;

    bool Resize(std::uint32_t size, bool shrinkCapacity = false);
    void Clear(bool releaseStorage = true) noexcept;
    void Swap(LOSByteArray& other) noexcept;

    std::byte* Data() noexcept { return data_; }
    const std::byte* Data() const noexcept { return data_; }
    std::uint32_t Size() const noexcept { return size_; }
    std::uint32_t Capacity() const noexcept { return capacity_; }

private:
    std::byte* data_ = nullptr;
    std::uint32_t size_ = 0;
    std::uint32_t capacity_ = 0;
};

} // namespace fnv::pathing

// One genuine LOS save record. The native NavMeshInfo pointer is not serialized;
// the fixed-width value and byte indices are read from the save buffer.
struct FUN_006e0190 {
    FUN_006e0190() noexcept;
    FUN_006e0190(const FUN_006e0190&) = delete;
    FUN_006e0190& operator=(const FUN_006e0190&) = delete;
    ~FUN_006e0190() noexcept;

    bool TryLoad(BGSLoadGameBuffer& buffer);

    bool m_bIsLoaded = false;
    fnv::pathing::LOSByteArray index;
    NavMeshInfo* pNavMeshInfo = nullptr;
    std::uint32_t uiUnk18 = ~std::uint32_t{0};
};

// Native owner for the pointer array initialized by the historical 006e1020
// entry. Its virtual allocation/free/reallocation operations are a real C++
// protocol; no generated vptr or fixed 32-bit pointer stride is installed.
class FUN_006e1020_shell {
public:
    FUN_006e1020_shell() noexcept;
    FUN_006e1020_shell(const FUN_006e1020_shell&) = delete;
    FUN_006e1020_shell& operator=(const FUN_006e1020_shell&) = delete;
    virtual ~FUN_006e1020_shell() noexcept;

    // Canonical provider for the retained source entry. The C++ constructor
    // calls it, and a repeated source call safely retires the prior contents.
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
    virtual FUN_006e0190** ReallocateItems(
        FUN_006e0190** items, std::uint32_t oldCount, std::uint32_t newCount) noexcept;

private:
    FUN_006e0190** data_ = nullptr;
    std::uint32_t size_ = 0;
    std::uint32_t capacity_ = 0;
};

class FUN_006e0480 : public FUN_006e1020_shell {
public:
    FUN_006e0480() noexcept = default;
    ~FUN_006e0480() noexcept override;

    // Reads the count and every derived record into a temporary owner. The live
    // array is published only after the whole payload succeeds.
    bool TryLoadEntries(BGSLoadGameBuffer& buffer);
    void FUN_006e0070(BGSLoadFormBuffer* buffer);

    NavMeshInfo* pNavMeshInfo = nullptr;
};

// The actual allocated production type. Its extent follows the native base
// layout and pointer width rather than the historical 0x14-byte shell.
class FUN_006e0e80 final : public FUN_006e0480 {
public:
    FUN_006e0e80() noexcept;
    ~FUN_006e0e80() noexcept override = default;
};
