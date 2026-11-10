#pragma once

#include "NiFixedString.h"

#include <cstddef>
#include <cstdint>

namespace fnv::strings {

// Source-backed native fixed-string array used by the GPU cache. Storage and
// every element are owned through the production MemoryManager boundary.
class FixedStringArray {
public:
    FixedStringArray() noexcept = default;
    FixedStringArray(const FixedStringArray&) = delete;
    FixedStringArray& operator=(const FixedStringArray&) = delete;
    FixedStringArray(FixedStringArray&& other) noexcept;
    FixedStringArray& operator=(FixedStringArray&& other) noexcept;
    ~FixedStringArray() noexcept;

    bool Reserve(std::uint32_t capacity) noexcept;
    bool PushBack(const NiFixedString& value) noexcept;
    void Clear() noexcept;

    const NiFixedString& operator[](std::size_t index) const noexcept { return data_[index]; }
    std::size_t Size() const noexcept { return count_; }
    std::size_t Capacity() const noexcept { return capacity_; }
    const NiFixedString* Data() const noexcept { return data_; }

private:
    NiFixedString* data_ = nullptr;
    std::uint32_t capacity_ = 0;
    std::uint32_t count_ = 0;
    std::uint32_t growBy_ = 0;
    std::uint32_t flags_ = 0;
};

struct GPUProgramCacheNames {
    NiFixedString name;
    NiFixedString profile;
    NiFixedString suffix;
    FixedStringArray fallbacks;

    bool Update(int kind, const NiFixedString& requested, const char* path) noexcept;
};

// Production NiObjectNET name update seam. Retain happens before retirement,
// so self-assignment and aliases are safe.
bool AssignObjectName(NiFixedString& destination, const NiFixedString& source) noexcept;

// Observable ownership facts used by bounded production-entry tests. These
// queries do not expose or depend on the node layout.
const void* TableIdentity() noexcept;
const void* NodeIdentity(const char* handle) noexcept;
bool Owns(const char* handle) noexcept;
std::uint32_t RefCount(const char* handle) noexcept;
std::size_t LiveNodeCount() noexcept;

} // namespace fnv::strings
