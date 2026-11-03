
// src/fallout_shared/tesworldspace_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00584e60: the skeleton of src/fallout_shared/tesworldspace_rtti_variant.cpp
// with declarations corrected to what the original code does (tesworldspace_packet_rtti_variant.h: public: bool IsTemporary() const; bool GetHasSpok -> public: virtual void F01(); virtual void F02(); v; tesworldspace_packet_rtti_variant.h: class TESObjectCELL { public: virtual ~TESObje -> class TESObjectCELL : public TESForm { public:; tesworldspace_packet_rtt). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesworldspace_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectCELL, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/CPMap00993a80.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/CombatThreatMap.h"
#include "fnv/decl/FNV_BucketMap.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00484150_shell.h"
#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_00586280_shell.h"
#include "fnv/decl/FUN_00587670_shell.h"
#include "fnv/decl/FUN_00588070_shell.h"
#include "fnv/decl/FUN_00588120_host.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/Unk00586340.h"
#include "fnv/decl/UpdateOwner.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_0054db50__FUN_0054db50_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "tesworldspace_packet_rtti_variant_decl_tesworldspace_rtti_variant.h"
struct GROUP_HEADER
{
    unsigned int uiType;
    unsigned int uiSize;
    unsigned int uiLabel;
    int iGroupType;
};
class FormGroupOwner
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual bool IsParentForm(TESForm* pkForm);
    bool FUN_00584d40(GROUP_HEADER* pkGroup);
};
class MobileObject : public TESObjectREFR
{
};
class Actor : public MobileObject
{
};
struct MapPosition532;
struct FUN_00993820
{
    virtual ~FUN_00993820();
    unsigned int bucketCount;
    MapPosition532** buckets;
    unsigned int size;
    FUN_00993820(int);
};
struct Child532
{
};
struct Tail532
{
};
struct ReferenceArray532
{
    virtual ~ReferenceArray532();
    Child532** data;
    unsigned short capacity, size, effectiveSize, grow;
    Child532*& FUN_00877a30(unsigned int);
};
struct CombatGroup532 : ReferenceArray532
{
    FUN_00993820* map;
    Tail532* tail;
    void FUN_00993600(void* stream);
};

// The native map enumerates form pointers while cloning each cell into the new world.
struct CellMapAccess545 : NiTPointerMap<unsigned int, TESObjectREFR*>
{
};
struct WorldClone545 : TESWorldSpace
{
    TESWorldSpace* FUN_00584e60(bool temporary, TESFile* file);
};
// @fnv 0x00584e60
TESWorldSpace* WorldClone545::FUN_00584e60(bool temporary, TESFile* file)
{
    TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(((::TESForm *)(reinterpret_cast<::FUN_004867a0_cls *>(this)->FUN_004867a0((void *)(temporary), file))));
    reinterpret_cast<::FUN_00438af0_Class *>((static_cast<CellMapAccess545*>(world->cellMap)))->FUN_00438af0();
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((static_cast<CellMapAccess545*>(cellMap)))->GetFirstPos();
    while (position)
    {
        TESForm* form2 = 0;
        unsigned int key;
        reinterpret_cast<::C6b7f20_Map *>((static_cast<CellMapAccess545*>(cellMap)))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(form2));
        if (form2)
        {
            TESObjectCELL* cell3 = dynamic_cast<TESObjectCELL*>(form2->CloneForm(false, file));
            if (cell3)
            {
                cell3->SetAltered(true);
                reinterpret_cast<::FUN_00587670_shell *>((static_cast<WorldClone545*>(world)))->FUN_00587670(cell3);
            }
        }
    }
    TESObjectCELL* persistent3 = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (persistent3)
    {
        TESObjectCELL* copy = dynamic_cast<TESObjectCELL*>(persistent3->CloneForm(false, file));
        if (copy)
        {
            world->m_pCell = copy;
            copy->SetAltered(true);
        }
    }
    reinterpret_cast<::FUN_00588120_host *>((static_cast<WorldClone545*>(world)))->FUN_00588120();
    return world;
}
