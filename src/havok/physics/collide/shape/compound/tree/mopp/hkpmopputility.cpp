#include <cstdint>

// src/havok/physics/collide/shape/compound/tree/mopp/hkpmopputility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/hkpmopputility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>

struct CallTarget_00d5ed80
{
};
struct SearchObject
{
    int FUN_00d5eda0(unsigned int arg0, unsigned int arg1, uintptr_t arg2);
public:
    int Search_00d5ed80(uintptr_t, unsigned int, uintptr_t, unsigned int);
};
// @fnv 0x00d5eda0
int SearchObject::FUN_00d5eda0(unsigned int arg0, unsigned int arg1, uintptr_t arg2)
{
    unsigned int callResult0 =
        (unsigned int)reinterpret_cast<::SearchObject *>((((CallTarget_00d5ed80*)this)))->Search_00d5ed80(arg0, arg1, arg2, 1u);
    return (int)callResult0;
}
