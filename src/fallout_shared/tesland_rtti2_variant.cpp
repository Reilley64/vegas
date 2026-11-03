
// src/fallout_shared/tesland_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py (flags of tesland_od_variant.cpp) for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesland.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_01187000.h"
#include "tesland_decls.h"
#pragma optimize("", off)

struct TESForm
{
    virtual ~TESForm();
    void Revert(unsigned int);
};

struct TESObjectLAND : ::TESForm
{
};
struct LandDuplicateCalls
{
};
struct LandDuplicateEntry : LandDuplicateCalls
{
    ::TESForm* FUN_00534880(bool createEditorID, void* copyMap);
};
// @fnv 0x00534880
::TESForm* LandDuplicateEntry::FUN_00534880(bool createEditorID, void* copyMap)
{
    ::TESObjectLAND* duplicate;
    duplicate = dynamic_cast< ::TESObjectLAND*>(((::TESForm *)(reinterpret_cast<::FUN_004867a0_cls *>(this)->FUN_004867a0((void *)(false), copyMap))));
    return duplicate;
}

__if_exists(::TESForm::Revert)
{
    __if_not_exists(::TESObjectCELL::Revert)
    {
        struct TESObjectCELL : ::TESForm
        {
        };
    }
}


struct LandSaveGroup5391
{
    void* typeTag;
    unsigned int unk04;
    unsigned int formID;
    unsigned int groupType;
};

struct LandSaveCell5391
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual bool ContainsGroup(LandSaveGroup5391* group);
};

struct FUN_005391d0_class
{
    bool FUN_005391d0(LandSaveGroup5391* apGroupFORM);
};

// @fnv 0x005391d0
bool FUN_005391d0_class::FUN_005391d0(LandSaveGroup5391* apGroupFORM)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->typeTag == (*reinterpret_cast<void * *>(&::fnv_00543df0::kGroupFormType)))
    {
        switch (apGroupFORM->groupType)
        {
        case 8:
        case 9: {
            void* found = dynamic_cast< ::TESObjectCELL*>(::FUN_004839c0(apGroupFORM->formID));
            if (found && ((::LandSaveCell5391 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) == found)
                bretval = false;
            break;
        }
        default: {
            LandSaveCell5391* pCell = ((::LandSaveCell5391 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
            bretval = pCell->ContainsGroup(apGroupFORM);
            break;
        }
        }
    }
    return bretval;
}
