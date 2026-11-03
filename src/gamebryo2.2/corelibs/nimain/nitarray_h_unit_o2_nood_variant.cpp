
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00c8ad40_cls.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WorldObjectCC3.h"
#include "fnv/decl/fnv_00a5ed10__ChildArray.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
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


struct PrimitiveStringArray
{
    virtual ~PrimitiveStringArray();
    void** data_at_04;
    unsigned short capacity_at_08, size_at_0a, used_at_0c, growth_at_0e;
};
struct MemoryContextScope
{
    int previous;
    __forceinline MemoryContextScope() : previous((*reinterpret_cast<int *>(&::currentAllocationContext)))
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    __forceinline ~MemoryContextScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};
struct __declspec(align(16)) ScalarVector4
{
    float x, y, z, w;
};
struct OperationParameters
{
    void* field_at_00;
    void* field_at_04;
    void* field_at_08;
    ScalarVector4 vector_at_10;
    ScalarVector4 vector_at_20;
    float value_at_30;
    float value_at_34;
};
struct HavokOperation
{
    void FUN_00cc4070(PrimitiveStringArray*);
};
// @fnv 0x00cc4070
void HavokOperation::FUN_00cc4070(PrimitiveStringArray* array)
{
    MemoryContextScope context;
    reinterpret_cast<::FUN_00c8ad40_cls *>(this)->FUN_00c8ad40((::BC8AD40StringArray *)(array));
    void* entry = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_012685c8))))));
    unsigned int index = array->size_at_0a;
    if (index >= array->capacity_at_08)
        reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->growth_at_0e);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, (char *&)(entry));
    OperationParameters parameters = {0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.1f, 0.01f};
    reinterpret_cast<::WorldObjectCC3 *>(this)->FUN_00cc3a50((::PropertiesCC3 *)(&parameters));
}
