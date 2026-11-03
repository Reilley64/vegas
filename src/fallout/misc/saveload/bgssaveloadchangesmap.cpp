// fallout/misc/saveload/bgssaveloadchangesmap.cpp: BGSSaveLoadChangesMap, CombatTargetMap, FormChangeRecord, DelStandIn (17 functions)

#include "generated/data/vtables.h"
#include <cstring>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSFlags.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00841100_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011c3000.h"
#include "bgssaveloadchangesmap_decls.h"
#include <new>

struct FUN_00845b30_arg
{
    unsigned int val;
};

// @fnv 0x00845550
BGSSaveLoadChangesMap::BGSSaveLoadChangesMap()
{
    ::FUN_00845b30((int *)this, ::FUN_00845b30_arg{0x13AF});
    *(void**)this = (void*)fnv_vftable_BGSSaveLoadChangesMap;
}

// Looks up the actor in the map and returns its array of combat targets, or null if not present.
// @fnv 0x009a4250
BSSimpleArray<Actor*, 1024>* CombatTargetMap::GetTargetsForActor(Actor* actor)
{
    BSSimpleArray<Actor*, 1024>* array = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((NiTPointerMap<unsigned int, BSSimpleArray<Actor*, 1024>*>*)this)))->FUN_00853130((unsigned int)actor, (::fnv_00853130::CombatThreatRecord *&)(array)))
        return array;
    return 0;
}

// @fnv 0x00845720
bool BGSSaveLoadChangesMap::ContainsChangeFlags(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (changes)
        return reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((FormChangeMask*)changes)))->FUN_004280f0(::FUN_00559450((int *)&(flags)));
    return false;
}

// @fnv 0x008457b0
void BGSSaveLoadChangesMap::AddFormChangeFlags(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (!changes)
    {
        changes = new FormChangeRecord();
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(formID, (unsigned int)(changes));
    }
    else if (::FUN_00559450((int *)((&changes->flags))))
    {
        return;
    }

    reinterpret_cast<::FUN_00841100_shell *>((changes))->FUN_00841100((int)((char*)::FUN_00559450((int *)&(flags))));
}

// @fnv 0x00845880
FormChangeRecord::FormChangeRecord()
{}

// Looks up the change record for formID, creating and inserting a new one if absent, then sets its quantity from flags.
// @fnv 0x008458b0
void BGSSaveLoadChangesMap::ApplyFormQuantityChange(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (!changes)
    {
        changes = new FormChangeRecord();
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(formID, (unsigned int)(changes));
    }
    reinterpret_cast<::FUN_00537e90 *>((((QuantityData*)changes)))->SetQuantity(::FUN_00559450((int *)&(flags)));
}

// Looks up the change record for formID; if found, deletes it, removes it from the map, and returns true, otherwise returns false.
// @fnv 0x00845a20
bool BGSSaveLoadChangesMap::HasFormChanges(unsigned int formID)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (changes)
    {
        delete changes;
        reinterpret_cast<::NiTMap_S *>(this)->RemoveKey(formID);
        return true;
    }
    return false;
}

// @fnv 0x00845a80
bool BGSSaveLoadChangesMap::ClearChangeFlags(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (changes && !::FUN_00559450((int *)&(changes->flags)))
    {
        reinterpret_cast<::BSFlags *>((changes))->Clear(::FUN_00559450((int *)&(flags)));
        if (::FUN_00559450((int *)(((FormChangeMask*)changes))))
            return false;
        if (reinterpret_cast<::BSShaderRenderUtility *>((((TESDataHandlerAccess*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->IsRenderTargetId(formID))
            return false;
        delete changes;
        reinterpret_cast<::NiTMap_S *>(this)->RemoveKey(formID);
    }
    return true;
}

struct CF845
{
    int f;
    CF845(int);
};
struct Arr845
{
    CF845 first;
};
struct Ctm845
{
    Arr845* GetTargetsForActor(void*);
    CF845 GetFirstEntry(void* actor);
};
// @fnv 0x008456e0
CF845 Ctm845::GetFirstEntry(void* actor)
{
    Arr845* a = GetTargetsForActor(actor);
    if (a)
        return a->first;
    return CF845(0);
}

extern int DAT_01031fac;

void FUN_005890c0(int* self, FUN_00845b30_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00845b30
int* FUN_00845b30(int* self, FUN_00845b30_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}


struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_00845c00 : FUN_009a5df0
{
    ~FUN_00845c00();
};

// Destructor that calls DeleteAllEntries on this object.
// @fnv 0x00845c00
FUN_00845c00::~FUN_00845c00()
{
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00845580
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::BGSSaveLoadChangesMap *>((((DtorStandIn*)this)))->BGSSaveLoadChangesMap::~BGSSaveLoadChangesMap();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FUN_00845610_shell : public BGSSaveLoadChangesMap
{
    void DeleteAllChanges();
};

struct NavMeshVertexMap
{
};
namespace p07 {
template <class K, class V> struct NiTPointerMap
{
    void GetNext(void*& pos, K& key, V& val);
    void RemoveAll();
};
}
// Iterates the map's entries, deletes each stored change object, then clears the map.
// @fnv 0x00845610
void FUN_00845610_shell::DeleteAllChanges()
{
    void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((NavMeshVertexMap*)this)))->GetFirstPos();
    while (it)
    {
        FormChangeRecord* pchanges = 0;
        unsigned int iformID = 0;
        reinterpret_cast<::C6b7f20_Map *>((((p07::NiTPointerMap<unsigned int, void*>*)this)))->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(iformID), (void **)&((void*&)pchanges));
        delete pchanges;
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((p07::NiTPointerMap<unsigned int, unsigned int>*)this)))->FUN_00438af0();
}

namespace fnv_00845760 {
struct CF845
{
    CF845(int);
    int data;
};
struct Fake845
{
    int unk;
    CF845 buf;
};
struct S845
{
    CF845 FUN_00845760(unsigned int aiFormID);
};
// @fnv 0x00845760
CF845 S845::FUN_00845760(unsigned int aiFormID)
{
    FormChangeRecord* pEntry;
    pEntry = (FormChangeRecord*)((CombatTargetMap*)this)->GetTargetsForActor((Actor*)aiFormID);
    if (pEntry)
        return ((Fake845*)pEntry)->buf;
    return 0;
}
}  // namespace fnv_00845760


struct FUN_00845960_shell : CombatTargetMap
{
    void SetCombatTargetQuantity(unsigned int formID, unsigned int quantity, unsigned int extra);
};

// Looks up or creates a per-form entry in the map, sets its quantity from FUN_00559450(quantity) and stores extra at offset 4.
// @fnv 0x00845960
void FUN_00845960_shell::SetCombatTargetQuantity(unsigned int formID, unsigned int quantity, unsigned int extra)
{
    BSSimpleArray<Actor*, 1024>* array = GetTargetsForActor((Actor*)formID);
    if (!array)
    {
        array = (BSSimpleArray<Actor*, 1024>*)new FormChangeRecord;
        reinterpret_cast<::FUN_00844700_Class *>((((BGSSaveLoadChangesMap*)this)))->FUN_00844700(formID, (unsigned int)((FormChangeRecord*)array));
    }
    reinterpret_cast<::FUN_00537e90 *>((((QuantityData*)array)))->SetQuantity(FUN_00559450((int*)&quantity));
    ((unsigned int*)((char*)array + 4))[0] = extra;
}

extern int DAT_0107eda8;
struct FUN_00845b90_shell
{
    int* vtable_;
    int count_;
    void* data_;
    int tail_;
    FUN_00845b90_shell* InitArray(int size);
};

// Sets the vtable, stores size in count_, allocates count_*4 bytes for data_, zeroes them, and returns this.
// @fnv 0x00845b90
FUN_00845b90_shell* FUN_00845b90_shell::InitArray(int aiCount)
{
    vtable_ = &DAT_0107eda8;
    count_ = aiCount;
    tail_ = 0;
    unsigned int bytes = count_ * 4;
    data_ = ::FUN_00aa1070(bytes);
    memset(data_, 0, count_ * 4);
    return this;
}

struct FUN_00845b60 : BGSSaveLoadChangesMapBase
{
    virtual ~FUN_00845b60();
};
// @fnv 0x00845b60
FUN_00845b60::~FUN_00845b60()
{}
