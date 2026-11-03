
// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a5ed10__ChildArray.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_004ed000.h"
#include "nitarray.inl"

void NiTArray_UnitReference()
{
    NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >* pGroups = 0;
    ActorCombatGroup* pGroup = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pGroups))->SetAt(0, (char *&)(pGroup));
    reinterpret_cast<::ViewerStrings *>((pGroups))->SetSize(0);
    pGroups->SetAtGrow(0, pGroup);
}

struct Arr
{
};
struct StrArr
{
};
struct FUN_0096aca0_shell : Arr
{
    void ResizeAndClear(int b);
};
// @fnv 0x0096aca0
void FUN_0096aca0_shell::ResizeAndClear(int aiCount)
{
    unsigned int uiOldSize = reinterpret_cast<::FUN_00658930_class *>(this)->GetShortAtOffsetA();
    reinterpret_cast<::ViewerStrings *>((((StrArr*)this)))->SetSize(uiOldSize + aiCount);
    for (unsigned int uiIndex = uiOldSize; uiIndex < reinterpret_cast<::FUN_00658930_class *>((((StrArr*)this)))->GetShortAtOffsetA(); ++uiIndex)
    {
        char* pElement = 0;
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((((StrArr*)this)))->SetAt(uiIndex, pElement);
    }
}
