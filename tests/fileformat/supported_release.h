#ifndef VEGAS_TESTS_FILEFORMAT_SUPPORTED_RELEASE_H
#define VEGAS_TESTS_FILEFORMAT_SUPPORTED_RELEASE_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <string_view>

// The identity of the supported original release, spelled by the tests
// themselves so that they do not share the source's bytes. A fixture that
// records it claims the release's identity: it is compared, not proved.
namespace supported_release
{

constexpr std::array<std::uint16_t, 4> version{1, 4, 0, 525};

inline std::array<std::byte, 32> Sha256()
{
    constexpr std::string_view hex = "3a87f92f011e5dc9179ddf733cf08be2b39ea6e5b7a8a9e3a9a72dafcc1b104d";
    static_assert(hex.size() == 64);
    const auto nibble = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
    std::array<std::byte, 32> digest{};
    for (std::size_t i = 0; i < digest.size(); ++i)
        digest[i] = static_cast<std::byte>(nibble(hex[2 * i]) * 16 + nibble(hex[2 * i + 1]));
    return digest;
}

} // namespace supported_release

#endif
