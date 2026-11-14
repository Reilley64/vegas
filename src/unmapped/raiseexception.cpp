// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/symbols_01017000.h"

struct Unk65
{
    void FUN_0065de30(int);
    Unk65* CallAndReturnSelf(int a);
};

// @fnv 0x0044a7d0
Unk65* Unk65::CallAndReturnSelf(int a)
{
    FUN_0065de30(a);
    return this;
}

struct FUN_0044a500_s
{
    int AssignSubstring(int, int, void*);
    FUN_0044a500_s* FUN_0044a500(int);
};

// @fnv 0x0044a500
FUN_0044a500_s* FUN_0044a500_s::FUN_0044a500(int a)
{
    reinterpret_cast<::Unk65*>(this)->CallAndReturnSelf(a);
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls*>(this)->FUN_0044a730(0, 0);
    AssignSubstring(a, 0, *reinterpret_cast<void**>(&::g_010173f0));
    return this;
}
