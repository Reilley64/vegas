#pragma once

#include <type_traits>

namespace fnv::magic
{
// The stored byte of a spell or enchantment record, not a complete form or a
// receiver view. Value-initialization clears it; default-initialization retains
// the same uninitialized-storage behavior as the byte it replaces.
class FlagByte
{
  public:
    FlagByte() = default;
    explicit constexpr FlagByte(unsigned char bits) noexcept : bits(bits) {}

    constexpr int ContainsAnyFlag(unsigned int mask) const noexcept
    {
        return (bits & mask) != 0;
    }

    constexpr unsigned char Value() const noexcept { return bits; }
    constexpr void Reset() noexcept { bits = 0; }

    constexpr void SetFlags(unsigned int mask, bool set) noexcept
    {
        bits = static_cast<unsigned char>(set ? bits | mask : bits & ~mask);
    }

  private:
    unsigned char bits;
};

// This subobject must not introduce padding, initialization or cleanup into the
// existing record representation. These are byte-storage guarantees, not proof
// of any complete form's native layout or receiver adjustment.
static_assert(sizeof(FlagByte) == sizeof(unsigned char));
static_assert(alignof(FlagByte) == alignof(unsigned char));
static_assert(std::is_standard_layout_v<FlagByte>);
static_assert(std::is_trivially_copyable_v<FlagByte>);
static_assert(std::is_trivially_default_constructible_v<FlagByte>);
}
