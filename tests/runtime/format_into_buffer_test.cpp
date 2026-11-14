#include "check.h"
#include "fnv/symbols_00406000.h"

#include <cstring>
#include <string>

// FUN_00406d00 (VEGAS-131) formats its variable arguments into a buffer of
// the given size. The calls pass more arguments than registers hold, so
// some are read from the caller's stack.
int main()
{
    Checks checks("runtime.format_into_buffer");

    char text[64];
    std::memset(text, '#', sizeof(text));
    int written = FUN_00406d00(text, static_cast<int>(sizeof(text)), "%d %s %c %u %x %d %.2f", -42, "list", 'x', 7u,
                               0xbeefu, 123456, 2.5);
    checks.Equal<std::string>("text", "-42 list x 7 beef 123456 2.50", text);
    checks.Equal("result", 29, written);

    // A buffer of five bytes keeps four characters and the terminator; the
    // result is the length of the whole text and the bytes after the
    // buffer are not written.
    char truncated[8];
    std::memset(truncated, '#', sizeof(truncated));
    written = FUN_00406d00(truncated, 5, "%d-%d", 1234, 5678);
    checks.Equal<std::string>("truncated text", "1234", truncated);
    checks.Equal("truncated result", 9, written);
    checks.Equal<std::string>("bytes after the buffer", "###", std::string(truncated + 5, 3));

    return checks.ExitCode();
}
