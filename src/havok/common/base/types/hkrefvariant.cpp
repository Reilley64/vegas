
// src/havok/common/base/types/hkrefvariant.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/hkrefvariant.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/ReferencedObjectHolder.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_01269000.h"
struct hkReferencedObject
{
};

struct FUN_00d47770
{
    hkReferencedObject* m_pObject;
    void SetObject(hkReferencedObject* object, intptr_t extra);
};

// @fnv 0x00d47770
void FUN_00d47770::SetObject(hkReferencedObject* object, intptr_t extra)
{
    if (object)
        reinterpret_cast<::FUN_00c90510_class *>((object))->FUN_00c90510();
    if (m_pObject)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pObject))->FUN_00c905b0();
    m_pObject = object;
}


// ReferencedObjectHolder::FUN_00d477a0 is owned by the native builtin module.

extern int DAT_010cf9c8;

struct SetBlk
{
    void* f00;
    unsigned short f04;
    unsigned short f06;
};

extern int(* DAT_010cf9d4)(SetBlk* object, int value, int extra, int result);

extern "C" int stub_a(void);
extern "C" int stub_b(void);
extern "C" int stub_c(void);

// FUN_00d48560 is reached by the game with a private convention:
// the enable flag arrives in eax, the extra word in edx, the value on the
// stack. The trailing stub_caller exists only so VC9 negotiates that
// convention for the out-of-line body above.
// If enable is set, builds a SetBlk with f06=1 and f00 pointing to DAT_010cf9c8, then calls DAT_010cf9d4; otherwise returns 1.
// @fnv 0x00d48560
static __declspec(noinline) int FUN_00d48560(int enable, int extra, int value)
{
    SetBlk v;
    if (enable)
    {
        v.f06 = 1;
        v.f00 = (void*)&DAT_010cf9c8;
        return DAT_010cf9d4(&v, value, enable, extra);
    }
    return 1;
}

int stub_caller(void)
{
    return FUN_00d48560(stub_a(), stub_b(), stub_c());
}

// @fnv 0x00d48620
int __cdecl FUN_00d48620(int iThirdArg, int iFirstArg, int iUnused)
{
    return FUN_00d48560(iFirstArg, 0, iThirdArg);
}

#include "generated/data/havok/common/base/types/hkrefvariant.inc"
