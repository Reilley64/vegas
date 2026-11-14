#include "havok/InlineStorageString.h"
#include "check.h"
#include <cstring>

int main()
{
    Checks checks("runtime.havok_inline_string");
    InlineStorageString heading("\nEntries for (continuous)", "BOX");
    checks.Equal("dispatcher heading", 0, std::strcmp(heading.cString(), "\nEntries for (continuous)BOX"));
    InlineStorageString copy(heading);
    heading = "changed";
    checks.Equal("copy owns its inline content", 0, std::strcmp(copy.cString(), "\nEntries for (continuous)BOX"));
    InlineStorageString path("a/./b/./c");
    path.FUN_00d62190("/./", "/", 1);
    checks.Equal("path replacement", 0, std::strcmp(path.cString(), "a/b/c"));
    InlineStorageString longer("a-a");
    checks.Equal("longer replacement result", 1, longer.FUN_00d62190("a", "word", 1));
    checks.Equal("longer replacement content", 0, std::strcmp(longer.cString(), "word-word"));
    InlineStorageString first("a-a");
    first.FUN_00d62190("a", "word", 0);
    checks.Equal("first replacement", 0, std::strcmp(first.cString(), "word-a"));
    InlineStorageString stop("first", nullptr, "ignored");
    checks.Equal("append stops at null", 0, std::strcmp(stop.cString(), "first"));
    stop += " last";
    checks.Equal("append preserves content", 0, std::strcmp(stop.cString(), "first last"));
    const InlineStorageString* same = &copy;
    copy = *same;
    checks.Equal("self copy assignment", 0, std::strcmp(copy.cString(), "\nEntries for (continuous)BOX"));
    InlineStorageString normalized;
    const char* normalizedResult = FUN_00d2b360(".\\a\\.\\b", &normalized);
    checks.Equal("actual path caller", 0, std::strcmp(normalizedResult, "a/b"));
    checks.Equal("caller returns owner content", true, normalizedResult == normalized.cString());
    return checks.ExitCode();
}
