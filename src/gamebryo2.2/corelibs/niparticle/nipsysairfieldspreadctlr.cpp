
// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldspreadctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldspreadctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_01202000.h"
struct ObjHdr
{
    int unk0;
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    unsigned short unkC;
    unsigned short unkE;
};

// Calls FUN_00c32f60 on p, gets a value from FUN_00a7d330, grows the buffer if unkA >= unk8, then stores the value at index unkA via FUN_0096ae90.
// @fnv 0x00c2f490
void __stdcall AppendElement(ObjHdr* apObj)
{
    ObjHdr* pObj = apObj;
    ::FUN_00c32f60((::StrArr *)(pObj));
    void* pValue = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<int *>(&::g_012027a0))))));
    unsigned int count = pObj->unkA;
    if (count >= pObj->unk8)
    {
        reinterpret_cast<::ViewerStrings *>((pObj))->SetSize((int)(pObj->unkE + count));
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pObj))->SetAt(count, (*(char * *)(&pValue)));
}
