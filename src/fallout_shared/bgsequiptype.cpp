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
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_01186000.h"
#include "fnv/symbols_011c3000.h"
#include "bgsequiptype_decls_decl_bgsequiptype.h"

// @fnv 0x00479430
BGSEquipType::EQUIP_TYPE BGSEquipType::GetEquipType(TESForm* form)
{
    EQUIP_TYPE result = ET_NONE;
    if (form)
    {
        switch (form->GetFormType())
        {
        case 40:
            result = (EQUIP_TYPE)(std::intptr_t)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0xc4))))->FUN_00726070()));
            break;
        case 24:
            result = (EQUIP_TYPE)(std::intptr_t)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x154))))->FUN_00726070()));
            break;
        case 26:
            result = (EQUIP_TYPE)(std::intptr_t)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x14c))))->FUN_00726070()));
            break;
        case 47:
            result = (EQUIP_TYPE)(std::intptr_t)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x9c))))->FUN_00726070()));
            break;
        case 29:
            result = (EQUIP_TYPE)(std::intptr_t)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x8c))))->FUN_00726070()));
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
    *reinterpret_cast<void**>(pFormComponent) = &DAT_0101aa14;
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
    BGSMenuIcon* picon = ((::fnv_00479540::BGSMenuIcon *)(std::uintptr_t)(::FUN_00479510(aeType)));
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
class Actor;
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
        return ((int)(std::intptr_t)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()));
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
    if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) != ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((LookupObject*)found)))->FUN_00726070())))
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
        reinterpret_cast<::CombatProcedure *>((this))->Initialize((::CombatController *)(((std::intptr_t)(reinterpret_cast<::Callees *>((obj))->FUN_00726070()))));
    }
}

struct IconString
{
    char* data;
    unsigned short length, capacity;
};

class BaseFormComponent_decl
{
  public:
    virtual ~BaseFormComponent_decl();
};

class TESTexture : public BaseFormComponent_decl
{
  public:
    IconString textureName;
};

class TESIcon : public TESTexture
{
};

class BGSMenuIcon : public TESForm, public TESIcon
{
  public:
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void SetFormID(unsigned int id, int flag);
    virtual void v12c();
    virtual void v130();
    virtual void SetEditorID(const char* name);
    BGSMenuIcon();
};

class TESDataHandler
{
  public:
    bool AddFormToDataHandler(TESForm* form);
};

int __cdecl FUN_00406d50(char*, unsigned int, const char*);

// @fnv 0x00479570
void FUN_00479570()
{
    static unsigned int prefixLength = FUN_0044a670("MenuIconEquipType");
    for (int i = 0; i < 14; ++i)
    {
        unsigned int formIDB = i + 0x258;
        BGSMenuIcon* entry = dynamic_cast<BGSMenuIcon*>(::FUN_004839c0(formIDB));
        if (!entry)
        {
            entry = new BGSMenuIcon;
            entry->SetFormID(formIDB, 1);
            char buffer[260];
            ::TaskQueueInterface::CopyStringToBuffer(buffer, 260, "MenuIconEquipType");
            FUN_00406d50(buffer, 260, (*reinterpret_cast<const char * (*)[14]>((void *)&::DAT_011869bc))[i]);
            entry->SetEditorID(buffer);
            ::TaskQueueInterface::CopyStringToBuffer(buffer, 260, "TypeIcons\\hot_keys_icon_");
            FUN_00406d50(buffer, 260, (*reinterpret_cast<const char * (*)[14]>((void *)&::DAT_011869bc))[i]);
            FUN_00406d50(buffer, 260, ".dds");
            reinterpret_cast<::TESFullName *>((entry))->SetFullName(buffer);
            (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->AddFormToDataHandler(entry);
        }
        DAT_011c4b54[i] = entry;
    }
}

#include "generated/data/fallout_shared/bgsequiptype.inc"
