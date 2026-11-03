#ifndef VEGAS_FILEFORMAT_BYTE_READER_H
#define VEGAS_FILEFORMAT_BYTE_READER_H

#include "fileformat/format_error.h"

#include <bit>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>

namespace fileformat
{

// Reads little-endian values of fixed widths from a byte span. `format` names
// the file format in error messages, and each read names its field.
class ByteReader
{
  public:
    ByteReader(std::span<const std::byte> bytes, std::string_view format) : bytes(bytes), format(format) {}

    bool AtEnd() const { return position == bytes.size(); }

    std::span<const std::byte> Take(std::size_t size, std::string_view field)
    {
        if (bytes.size() - position < size)
            Fail(field, "ends early");
        std::span<const std::byte> taken = bytes.subspan(position, size);
        position += size;
        return taken;
    }

    ByteReader Sub(std::size_t size, std::string_view field) { return ByteReader(Take(size, field), format); }

    std::string_view Tag(std::string_view field)
    {
        std::span<const std::byte> tag = Take(4, field);
        return {reinterpret_cast<const char*>(tag.data()), tag.size()};
    }

    std::uint16_t U16(std::string_view field) { return static_cast<std::uint16_t>(Unsigned(2, field)); }
    std::uint32_t U32(std::string_view field) { return static_cast<std::uint32_t>(Unsigned(4, field)); }
    std::uint64_t U64(std::string_view field) { return Unsigned(8, field); }
    float F32(std::string_view field) { return std::bit_cast<float>(U32(field)); }

    // A string that fills the rest of the bytes and ends in a zero byte.
    std::string ZString(std::string_view field)
    {
        std::span<const std::byte> text = Take(bytes.size() - position, field);
        if (text.empty() || text.back() != std::byte{0})
            Fail(field, "does not end in a zero byte");
        return {reinterpret_cast<const char*>(text.data()), text.size() - 1};
    }

    // Fails when bytes are left over after the last field.
    void Finish(std::string_view field) const
    {
        if (!AtEnd())
            Fail(field, "is longer than its fields");
    }

    [[noreturn]] void Fail(std::string_view field, std::string_view problem) const
    {
        throw FormatError(std::string(format) + ": " + std::string(field) + ": " + std::string(problem));
    }

  private:
    std::uint64_t Unsigned(std::size_t width, std::string_view field)
    {
        std::span<const std::byte> value = Take(width, field);
        std::uint64_t result = 0;
        for (std::size_t i = 0; i < width; ++i)
            result |= static_cast<std::uint64_t>(value[i]) << (8 * i);
        return result;
    }

    std::span<const std::byte> bytes;
    std::string_view format;
    std::size_t position = 0;
};

} // namespace fileformat

#endif
