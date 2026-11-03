// fallout_shared/bgsequiptype.cpp: BGSEquipType, QueryObject (8 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004036b0_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00409a30_shell.h"
#include "fnv/decl/FUN_008c6060_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00479000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c4000.h"
#include "bgsequiptype_decls.h"

// @fnv 0x00479430
BGSEquipType::EQUIP_TYPE BGSEquipType::GetEquipType(TESForm* form)
{
    EQUIP_TYPE result = ET_NONE;
    if (form)
    {
        switch (form->GetFormType())
        {
        case 40:
            result = (EQUIP_TYPE)(int)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0xc4))))->FUN_00726070()));
            break;
        case 24:
            result = (EQUIP_TYPE)(int)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x154))))->FUN_00726070()));
            break;
        case 26:
            result = (EQUIP_TYPE)(int)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x14c))))->FUN_00726070()));
            break;
        case 47:
            result = (EQUIP_TYPE)(int)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x9c))))->FUN_00726070()));
            break;
        case 29:
            result = (EQUIP_TYPE)(int)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x8c))))->FUN_00726070()));
            break;
        }
    }
    return result;
}

extern int DAT_0101aa14;

class BaseFormComponent
{
  public:
    BaseFormComponent();
};

// Initializes the BaseFormComponent base, sets the vtable pointer to DAT_0101aa14, calls FUN_008c6060, and returns pThis.
// @fnv 0x00479320
void* FUN_00479320(int* pFormComponent)
{
    ::FUN_00402d30((int *)(((BaseFormComponent*)pFormComponent)));
    *pFormComponent = (int)&DAT_0101aa14;
    reinterpret_cast<::FUN_008c6060_shell *>((pFormComponent))->FUN_008c6060();
    return pFormComponent;
}


// Returns DAT_011c4b54[a1] when a1 is between 0 and 13, otherwise returns 0.
// @fnv 0x00479510
int __cdecl FUN_00479510(int aiIndex)
{
    int iValue = 0;
    if (aiIndex > -1 && aiIndex < 14)
    {
        iValue = (*reinterpret_cast<int (*)[14]>(&::DAT_011c4b54))[aiIndex];
    }
    return iValue;
}

namespace fnv_00479540 {
struct FNStub
{
    const char* GetFullName(void);
};

struct BGSMenuIcon
{
    const char* GetFullName(void);
};

extern const char $SG5812[];

// Looks up the BGSMenuIcon for aeType and returns its full name, or a fallback string when none exists.
// @fnv 0x00479540
const char* __cdecl GetMenuIconName(int aeType)
{
    BGSMenuIcon* picon = ((::fnv_00479540::BGSMenuIcon *)(::FUN_00479510(aeType)));
    if (picon)
        return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(picon + 0x18)))->FUN_00408da0()));
    return $SG5812;
}
}  // namespace fnv_00479540

struct FUN_004029d0_shell
{
    bool FUN_004029d0(int);
};
struct S_004036b0
{
};
struct Actor;
struct S_004063e0
{
public:
    float GetTotalCost(::Actor *);
};
struct FUN_00403660_shell
{
    float GetValue(int);
};
// @fnv 0x00403660
float FUN_00403660_shell::GetValue(int)
{
    if (((FUN_004029d0_shell*)((char*)this - 0x3c))->FUN_004029d0(1))
    {
        return (float)((int)(reinterpret_cast<::FUN_004036b0_Class *>((((S_004036b0*)((char*)this - 0x3c))))->FUN_004036b0()));
    }
    else
    {
        return ((S_004063e0*)this)->GetTotalCost((::Actor *)(0));
    }
}

struct S_0040a0a0_Primary
{
    virtual void vfn_00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct S_0040a0a0_AVOwner
{
    virtual float FUN_0040a0a0(int avCode);
};

struct S_0040a0a0_Actor : S_0040a0a0_Primary, S_0040a0a0_AVOwner
{
    virtual float FUN_0040a0a0(int avCode);
};

// @fnv 0x0040a0a0
float S_0040a0a0_Actor::FUN_0040a0a0(int avCode)
{
    if (reinterpret_cast<::FUN_00409a30_shell *>(this)->FUN_00409a30(1))
    {
        return ((int)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()));
    }
    else
    {
        return reinterpret_cast<::S_004063e0 *>(this)->GetTotalCost((::Actor *)(0));
    }
}

extern const char DAT_01183290[];
extern "C" void* __cdecl FUN_00ec43fb(int, int, const char*, const char*, int);
struct LookupObject
{
};
struct QueryObject
{
    bool FUN_004793d0(int);
};
// @fnv 0x004793d0
bool QueryObject::FUN_004793d0(int argument)
{
    void* found = FUN_00ec43fb(argument, 0, (*reinterpret_cast<const char (*)[]>(&::DAT_01183040)), DAT_01183290, 0);
    if (found == 0)
        return true;
    if (((int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) != ((int)(reinterpret_cast<::Callees *>((((LookupObject*)found)))->FUN_00726070())))
        return true;
    return false;
}

extern const char DAT_01183290[];
extern "C" void* __cdecl FUN_00ec43fb(int, int, const char*, const char*, int);

struct FUN_00479380_cls
{
    void SetFromLookup(int a1);
};

// @fnv 0x00479380
void FUN_00479380_cls::SetFromLookup(int a1)
{
    LookupObject* obj = (LookupObject*)FUN_00ec43fb(a1, 0, (*reinterpret_cast<const char (*)[]>(&::DAT_01183040)), DAT_01183290, 0);
    if (obj == 0)
    {
    }
    else
    {
        reinterpret_cast<::CombatProcedure *>((this))->Initialize((::CombatController *)(((int)(reinterpret_cast<::Callees *>((obj))->FUN_00726070()))));
    }
}
