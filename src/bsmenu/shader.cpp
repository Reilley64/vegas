// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043b000.h"
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
