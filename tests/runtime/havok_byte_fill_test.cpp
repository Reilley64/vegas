#include "check.h"
#include "fnv/symbols_00cb1000.h"

#include <array>

int main()
{
    Checks checks("runtime.havok_byte_fill");
    std::array<unsigned char, 8> bytes{0xa1, 1, 2, 3, 4, 5, 6, 0xb2};
    const auto original = bytes;
    ::FUN_00cb1280(bytes.data(), 0xff, 0);
    ::FUN_00cb1280(bytes.data() + bytes.size(), 0xff, 0);
    checks.Equal("zero length leaves every byte unchanged", true, bytes == original);

    ::FUN_00cb1280(bytes.data() + 2, 0x1ab, 3);
    const std::array<unsigned char, 8> partial{0xa1, 1, 0xab, 0xab, 0xab, 5, 6, 0xb2};
    checks.Equal("partial range truncates the fill byte and keeps surrounding bytes", true, bytes == partial);

    ::FUN_00cb1280(bytes.data() + 1, -1, 6);
    const std::array<unsigned char, 8> filled{0xa1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb2};
    checks.Equal("negative fill uses its low byte and keeps both guards", true, bytes == filled);
    return checks.ExitCode();
}
