#ifndef VEGAS_TESTS_FILEFORMAT_FIXTURE_H
#define VEGAS_TESTS_FILEFORMAT_FIXTURE_H

#include "check.h"

#include <cstddef>
#include <cstdint>
#include <format>
#include <initializer_list>
#include <span>
#include <string>
#include <string_view>
#include <vector>

// A file built byte by byte, with the name of the field each byte belongs to.
class Fixture
{
  public:
    Fixture& Bytes(std::string_view field, std::initializer_list<std::uint8_t> values)
    {
        for (std::uint8_t value : values)
            Append(field, static_cast<std::byte>(value));
        return *this;
    }

    Fixture& Text(std::string_view field, std::string_view text)
    {
        for (char c : text)
            Append(field, static_cast<std::byte>(c));
        return *this;
    }

    std::span<const std::byte> Data() const { return data; }

    const std::string& FieldAt(std::size_t offset) const { return fields[offset]; }

  private:
    void Append(std::string_view field, std::byte value)
    {
        data.push_back(value);
        fields.emplace_back(field);
    }

    std::vector<std::byte> data;
    std::vector<std::string> fields;
};

// Checks that written bytes are exactly the fixture's, naming the field of the
// first byte that differs.
inline void CheckBytes(Checks& check, const Fixture& expected, std::span<const std::byte> written)
{
    const std::span<const std::byte> bytes = expected.Data();
    for (std::size_t i = 0; i < bytes.size() && i < written.size(); ++i)
    {
        if (bytes[i] != written[i])
        {
            check.Fail(expected.FieldAt(i), std::format("byte 0x{:X} is 0x{:02X}, expected 0x{:02X}", i,
                                                        static_cast<unsigned>(written[i]),
                                                        static_cast<unsigned>(bytes[i])));
            return;
        }
    }
    check.Equal("written size", bytes.size(), written.size());
}

#endif
