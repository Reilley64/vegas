
// src/havok/common/internal/convexhull/hkplaneequationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkplaneequationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00d74d40_cls.h"
#include "fnv/decl/S00d76120_cls.h"
#include "fnv/decl/enumeration_rework__PlaneHull.h"
#include "fnv/decl/fnv_00d76940__FUN_00d76940_cls.h"
#include "fnv/decl/fnv_00d76ca0__FUN_00d76ca0.h"
struct Arg
{
    void* data;
    int count;
};

struct B
{
    int f0;
    int f1;
    int f2;
    int f3;

};

struct A
{
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;

};

// @fnv 0x00dd6270
int __cdecl ProcessArg(Arg* a, int second)
{
    if (a->count < 4)
    {
        return 1;
    }

    B objB;
    A objA;

    new ((void *)&(objA)) ::fnv_00d76ca0::FUN_00d76ca0();

    int count = a->count;
    void* data = a->data;

    void* q = ((void *)(reinterpret_cast<::FUN_00d74d40_cls *>(&(objB))->FUN_00d74d40()));
    int iResult = reinterpret_cast<::enumeration_rework::PlaneHull *>(&(objA))->FUN_00d774a0((const ::enumeration_rework::PlaneVector *)(data), count, (int)(q));

    if (iResult != -1)
    {
        reinterpret_cast<::S00d76120_cls *>(&(objA))->FUN_00d76120(1, (*(::S00d76120_Arr *)(second)));
        reinterpret_cast<::fnv_00d76940::FUN_00d76940_cls *>(&(objA))->FUN_00d76940();
        return 0;
    }

    reinterpret_cast<::fnv_00d76940::FUN_00d76940_cls *>(&(objA))->FUN_00d76940();
    return 1;
}
