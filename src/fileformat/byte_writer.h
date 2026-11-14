#ifndef VEGAS_FILEFORMAT_BYTE_WRITER_H
#define VEGAS_FILEFORMAT_BYTE_WRITER_H

#include <bit>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>
#include <utility>
#include <vector>

namespace fileformat
{

// Appends little-endian values of fixed widths to a byte vector.
class ByteWriter
{
  public:
    void Append(std::span<const std::byte> values) { bytes.insert(bytes.end(), values.begin(), values.end()); }

    void Text(std::string_view text)
    {
        for (char c : text)
            bytes.push_back(static_cast<std::byte>(c));
    }

    void ZString(std::string_view text)
    {
        Text(text);
        bytes.push_back(std::byte{0});
    }

    void U16(std::uint16_t value) { Unsigned(value, 2); }
    void U32(std::uint32_t value) { Unsigned(value, 4); }
    void U64(std::uint64_t value) { Unsigned(value, 8); }
    void F32(float value) { U32(std::bit_cast<std::uint32_t>(value)); }

    std::span<const std::byte> Bytes() const { return bytes; }
    std::size_t Size() const { return bytes.size(); }
    std::vector<std::byte> Take() { return std::move(bytes); }

  private:
    void Unsigned(std::uint64_t value, std::size_t width)
    {
        for (std::size_t i = 0; i < width; ++i)
            bytes.push_back(static_cast<std::byte>(value >> (8 * i)));
    }

    std::vector<std::byte> bytes;
};

} // namespace fileformat

#endif
