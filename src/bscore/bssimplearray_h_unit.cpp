// bscore/bssimplearray_h_unit.cpp: PathOwner (1 function)

#include <new>
#include "fnv/decl/ArrQ0cd50.h"
#include "fnv/decl/ArrayStub.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_006cef10_shell.h"
#include "fnv/decl/FUN_006e3c90_cls.h"
#include "fnv/decl/FUN_006e8f40_shell.h"
#include "fnv/decl/FUN_00761540_cls.h"
#include "fnv/decl/FUN_007883b0.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00afcde0_shell.h"
#include "fnv/decl/S006d0510.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/S_00a0d000_Class.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_006f2290__CtorHelper.h"
#include "fnv/symbols_006e6000.h"
#include "fnv/symbols_0106c000.h"
#include "bssimplearray.h"


class TESForm
{
  public:
};

class PathNodeA
{
  public:
    char data[0x30];
    PathNodeA(void* a, TESForm* b);
};

class PathPool
{
  public:
};

class FormIDArray
{
  public:
};

class PathOwner
{
  public:
    void* vtable;
    int pad4;
    PathPool pool;
    char pad9[0x27];
    FormIDArray forms;

    void* CreatePathNode(void* a, TESForm* b);
};

// Allocates a path node from the pool, constructs it with a and b, and if b is non-null adds b's form ID to the forms array.
// @fnv 0x006ce7e0
void* PathOwner::CreatePathNode(void* a, TESForm* apForm)
{
    void* id = ((void *)(reinterpret_cast<::FUN_006cef10_shell *>(&(pool))->AdvanceCounter()));
    void* pNodePlace = ((void *)(reinterpret_cast<::FUN_006e8f40_shell *>(&(pool))->FUN_006e8f40((int)(id))));
    new (pNodePlace) PathNodeA(a, apForm);
    if (apForm)
    {
        reinterpret_cast<::FUN_00438690 *>(&(forms))->FUN_007cb2e0((unsigned int *)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apForm))->FUN_0084e3a0()))));
    }
    return id;
}
