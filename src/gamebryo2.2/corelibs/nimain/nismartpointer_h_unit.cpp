// gamebryo2.2/corelibs/nimain/nismartpointer_h_unit.cpp: free functions (1 function)

#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0042fdc0_class.h"
#include "fnv/decl/NiPtr.h"
#include "fnv/decl/fnv_0044b010__FUN_0044b010_shell.h"
#include "fnv/decl/fnv_0044b050__FUN_0044b050_shell.h"
#include "fnv/decl/fnv_0044b0f0__FUN_0044b0f0_shell.h"
#include "fnv/decl/fnv_0044b180__FUN_0044b180_shell.h"
#include "fnv/symbols_011f6000.h"
#include "nismartpointer.h"

struct Helper62d0
{
    void* p;
    Helper62d0& operator=(void const*);
};
struct Struct6c89e0
{
    Helper62d0 f0;
    int f4;
    int f8;
    NavMeshPtr fC;
    Struct6c89e0& AssignFrom(Struct6c89e0 const*);
};
// @fnv 0x006c89e0
Struct6c89e0& Struct6c89e0::AssignFrom(Struct6c89e0 const* apSource)
{
    f0 = apSource;
    f4 = apSource->f4;
    f8 = apSource->f8;
    fC = apSource->fC;
    return *this;
}
