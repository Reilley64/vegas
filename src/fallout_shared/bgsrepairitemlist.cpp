// fallout_shared/bgsrepairitemlist.cpp: BGSRepairItemList, MyHolder, RepairListComparison (6 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008c6060_shell.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsrepairitemlist_decls.h"

// Resolves pRepairItemList's form ID to a BGSListForm and warns if the lookup fails, naming the owner when available.
// @fnv 0x0047b8e0
void BGSRepairItemList::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)pRepairItemList;
    if (formID)
    {
        TESFile* file = owner ? owner->GetFile(-1) : 0;
        ::ResolveFormID((unsigned int *)&(formID), file);
        pRepairItemList = dynamic_cast<BGSListForm*>(::FUN_004839c0(formID));
        if (!pRepairItemList)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }
    }
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent()
    {}
};
struct TESRaceForm
{
};
struct Unnamed07
{
};
struct MyHolder
{
    void CopyFrom(BaseFormComponent* apCopyFC);
};

extern int DAT_0101a4c4;

// @fnv 0x0047b850
void* FUN_0047b850(void* pThis)
{
    ::FUN_00402d30((int *)(((BaseFormComponent*)pThis)));
    *(int**)pThis = &DAT_0101a4c4;
    reinterpret_cast<::FUN_008c6060_shell *>((pThis))->FUN_008c6060();
    return pThis;
}

namespace fnv_0047b880 {
extern int DAT_0101a4c4;
struct TESFile
{
    void InitializeComponent(void);
};
struct FUN_0047b880
{
    virtual ~FUN_0047b880();
};
// @fnv 0x0047b880
FUN_0047b880::~FUN_0047b880()
{
    reinterpret_cast<::TESForm *>((reinterpret_cast<TESFile*>(this)))->ClearData();
}
}  // namespace fnv_0047b880

struct S0047b8a0
{
    int _00;
    TESForm* _04;
    void FUN_0047b8a0();
};
// @fnv 0x0047b8a0
void S0047b8a0::FUN_0047b8a0()
{
    unsigned int formID;
    if (_04 != 0)
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((_04))->FUN_0084e3a0()));
        ::FUN_00485910(0x4C504552, formID);
    }
}

// If apCopyFC is a BGSRepairItemList, passes its accessor's result to this object's TESRaceForm::Initialize.
// @fnv 0x0047b9d0
void MyHolder::CopyFrom(BaseFormComponent* apCopyFC)
{
    BGSRepairItemList* pcopy = dynamic_cast<BGSRepairItemList*>(apCopyFC);
    if (!pcopy)
        return;
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)(((unsigned int)(reinterpret_cast<::Callees *>((((Unnamed07*)pcopy)))->FUN_00726070()))));
}

struct RepairListComparison : BGSRepairItemList
{
    bool FUN_0047ba20(BaseFormComponent* component);
};

// Returns true if the component is not a BGSRepairItemList or if its _ref_00726070 differs from this list's _ref_00726070.
// @fnv 0x0047ba20
bool RepairListComparison::FUN_0047ba20(BaseFormComponent* component)
{
    BGSRepairItemList* other = dynamic_cast<BGSRepairItemList*>(component);
    if (!other)
        return true;
    if (((unsigned int)(reinterpret_cast<::Callees *>((reinterpret_cast<Unnamed07*>(other)))->FUN_00726070())) != ((unsigned int)(reinterpret_cast<::Callees *>((reinterpret_cast<Unnamed07*>(this)))->FUN_00726070())))
        return true;
    return false;
}
