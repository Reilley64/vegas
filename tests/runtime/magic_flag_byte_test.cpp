#include "fnv/magic/flag_byte.h"

#include <cstdio>

namespace
{
int failures;

void Check(bool condition, const char* name)
{
    if (!condition)
    {
        std::fprintf(stderr, "magic flags: %s\n", name);
        ++failures;
    }
}

void Query()
{
    const fnv::magic::FlagByte empty{};
    Check(empty.ContainsAnyFlag(0xffffffffu) == 0, "empty flags reject every mask");
    const fnv::magic::FlagByte flags{0x85};
    Check(flags.ContainsAnyFlag(1) == 1, "bit 1");
    Check(flags.ContainsAnyFlag(2) == 0, "missing bit 2");
    Check(flags.ContainsAnyFlag(4) == 1, "bit 4");
    Check(flags.ContainsAnyFlag(0x10) == 0, "missing bit 0x10");
    Check(flags.ContainsAnyFlag(0x20) == 0, "missing bit 0x20");
    Check(flags.ContainsAnyFlag(0x40) == 0, "missing bit 0x40");
    Check(flags.ContainsAnyFlag(0x80) == 1, "unsigned high byte bit");
    Check(flags.ContainsAnyFlag(0x82) == 1, "combined mask means any, not all");
    Check(flags.ContainsAnyFlag(0) == 0, "zero mask");
    Check(flags.ContainsAnyFlag(0xffffff00u) == 0, "mask bits beyond the stored byte");
    Check(flags.ContainsAnyFlag(0x80000080u) == 1, "high mask bits do not hide matching low bits");
}

void Mutation()
{
    fnv::magic::FlagByte flags{0xa5};
    flags.SetFlags(0x42, true);
    Check(flags.Value() == 0xe7, "set selected bits without clearing existing bits");
    flags.SetFlags(0x21, false);
    Check(flags.Value() == 0xc6, "clear selected bits without setting other bits");
    flags.SetFlags(0xffffff00u, true);
    Check(flags.Value() == 0xc6, "setting high mask bits cannot widen the stored byte");
    flags.SetFlags(0xffffff00u, false);
    Check(flags.Value() == 0xc6, "clearing high mask bits preserves the stored byte");
    flags.SetFlags(0, true);
    flags.SetFlags(0, false);
    Check(flags.Value() == 0xc6, "zero-mask mutations are inert");
    flags.SetFlags(0xffffffffu, true);
    Check(flags.Value() == 0xff, "setting every mask bit stores one unsigned byte");
    flags.SetFlags(0xffffffffu, false);
    Check(flags.Value() == 0, "clearing every mask bit empties the byte");
}

void ResetAndCopy()
{
    fnv::magic::FlagByte original{0xa5};
    fnv::magic::FlagByte copy = original;
    original.Reset();
    Check(original.Value() == 0, "reset clears the producer byte");
    Check(copy.Value() == 0xa5, "copy owns an independent byte");
    copy = original;
    Check(copy.Value() == 0, "copy assignment replaces rather than combines flags");
    copy.Reset();
    Check(copy.ContainsAnyFlag(0xffffffffu) == 0, "reset is repeatable");
}

void CallerBits()
{
    // These are literal masks used by the spell/enchantment callers, plus the
    // remaining bit of the byte. No engine receiver or vtable is fabricated.
    const unsigned char bits[] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
    for (unsigned char bit : bits)
    {
        fnv::magic::FlagByte flags{};
        flags.SetFlags(bit, true);
        Check(flags.Value() == bit, "isolated caller bit is stored unchanged");
        Check(flags.ContainsAnyFlag(bit) == 1, "each caller bit returns normalized one");
        Check(flags.ContainsAnyFlag(0xffu - bit) == 0, "isolated bit cannot satisfy another caller");
        flags.SetFlags(bit, false);
        Check(flags.Value() == 0, "each caller bit can be cleared");
    }
}
}

int main()
{
    Query();
    Mutation();
    ResetAndCopy();
    CallerBits();
    return failures ? 1 : 0;
}
