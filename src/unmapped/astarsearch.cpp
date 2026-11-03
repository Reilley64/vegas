
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_0052ce20_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
struct AlphaColor
{
};
struct FUN_006a7d30_shell
{
    void FUN_006a7d30(float f);
};
// @fnv 0x006a7d30
void FUN_006a7d30_shell::FUN_006a7d30(float afValue)
{
    reinterpret_cast<::FUN_0052ce20_shell *>((((AlphaColor*)((char*)this + 0x1ff4))))->FUN_0052ce20(afValue);
}

struct CombatTargetTimestamp
{
    float fTime;
    float __thiscall FUN_006a7f50() const;
};

// @fnv 0x006a7f50
float __thiscall CombatTargetTimestamp::FUN_006a7f50() const
{
    return fTime;
}

extern int DAT_0106b660;

struct GlobalObject_00869f00
{
    void FUN_006a7f90();
};

// @fnv 0x006a7f90
void GlobalObject_00869f00::FUN_006a7f90()
{
    *(int*)this = (int)&DAT_0106b660;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(true);
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_006a7f60
{
    int* vtable;
    FUN_006a7f60();
};
// Sets the vtable pointer to DAT_0106b660 and calls FUN_006b3eb0 with 0 and 0 on this object.
// @fnv 0x006a7f60
FUN_006a7f60::FUN_006a7f60()
{
    vtable = &DAT_0106b660;
    ((AX*)this)->FUN_006b3eb0(0, 0);
}
