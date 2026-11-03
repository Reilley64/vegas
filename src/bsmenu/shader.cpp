// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043b000.h"
#include <stdio.h>
#include <stdarg.h>
#include "fnv/symbols_011f6000.h"
struct FUN_0043ba10_shell
{
    int m;
    FUN_0043ba10_shell* FUN_0043ba10(FUN_0043ba10_shell* other);
};
// If other's m differs from this m, calls FUN_0043ba60 with other's m, calls FUN_004381d0 on this, then stores other's m; returns this.
// @fnv 0x0043ba10
FUN_0043ba10_shell* FUN_0043ba10_shell::FUN_0043ba10(FUN_0043ba10_shell* other)
{
    int tmp;
    if (m != other->m)
    {
        tmp = other->m;
        ::fnv_0043ba60::FUN_0043ba60((int *)&(tmp));
        FUN_004381d0(this);
        m = tmp;
    }
    return this;
}

struct LogSink
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int(__cdecl* pfnOutput)(char*, int, int);
};

// @fnv 0x00aa0020
int __cdecl FUN_00aa0020(int a1, int a2, const char* fmt, ...)
{
    char buf[0x800];
    va_list args;

    va_start(args, fmt);
    if (DAT_011f6044 != 0)
    {
        vsprintf_s(buf, 0x800, fmt, args);
        if (((LogSink*)DAT_011f6044)->pfnOutput != 0)
        {
            return ((LogSink*)DAT_011f6044)->pfnOutput(buf, a1, a2);
        }
    }
    return 0;
}
