
// tesobjectcell_ctx_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellLike.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00545960__S.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_005656d0__Thing.h"
#include "fnv/decl/fnv_00569ac0__FUN_00569ac0_shell.h"
#include "fnv/decl/fnv_0056a250__FUN_0056a250_shell.h"
#include "fnv/decl/fnv_00587870__OverlapHolder.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011dd000.h"
#include "tesobjectcell_packet.h"
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

template <> class BSSimpleList<TESObjectREFR*>
{
  public:
    TESObjectREFR* item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
    bool FUN_008256d0();
    void AddHead(TESObjectREFR* const& item);
};

class Cell_Sub;

class FUN_00544f60
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    BSSimpleList<TESObjectREFR*> list4C;
    BSSimpleList<TESObjectREFR*> list54;
    int unk5c, unk60;

    FUN_00544f60();
};

struct CellC4Holder
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c;
    int f60, f64, f68, f6c, f70, f74, f78, f7c;
    int f80, f84, f88, f8c, f90, f94, f98, f9c;
    int fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc;
    int fc0;
    FUN_00544f60* unkC4;
};

class BGSSaveLoadGame
{
  public:
};

class TESForm
{
  public:
};

class FUN_00439f90_shell
{
  public:
    bool FUN_00439f90();
};

class FUN_00569ac0_shell
{
  public:
};

class FUN_005656d0_shell
{
  public:
};

class FUN_0056a250_shell
{
  public:
};

class FUN_00545740_shell
{
  public:
};

class FUN_00545960_shell
{
  public:
};

class FUN_00587870_shell
{
  public:
};

class BSSimpleList_standin
{
  public:
    void FUN_0063f7b0();
};

class PolymorphicRef
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3a();
    virtual void Unk_3b();
    virtual void Unk_3c();
    virtual void Unk_3d();
    virtual void Unk_3e();
    virtual void Unk_3f();
    virtual bool Unk_40();
};

class CellSubTarget
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37(CellSubTarget* a, int val);
};

class Cell_Sub : public TESObjectCELL
{
  public:
    void FUN_00544ce0();
};

// @fnv 0x00544ce0
void Cell_Sub::FUN_00544ce0()
{
    if (((CellC4Holder*)this)->unkC4 == 0)
    {
        ((CellC4Holder*)this)->unkC4 = new FUN_00544f60();
    }
    CellRefLockEnter();
    BSSimpleList<TESObjectREFR*> localList9;
    BSSimpleList<TESObjectREFR*>* iter = (BSSimpleList<TESObjectREFR*>*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (iter != 0 && !iter->FUN_008256d0())
    {
        TESObjectREFR* item5 = ((::TESObjectREFR *)(new ((void *)(iter)) ::Vec3()));
        iter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)(((TESForm*)item5)))->FUN_00440d80() || reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
        {
            if (((FUN_00439f90_shell*)item5)->FUN_00439f90())
            {
                reinterpret_cast<::CellLike *>((((FUN_00545740_shell*)this)))->GetOrCreateFaceGenNode((::RefForm *)(item5));
                if (reinterpret_cast<::fnv_00569ac0::FUN_00569ac0_shell *>((((FUN_00569ac0_shell*)item5)))->FUN_00569ac0())
                {
                    localList9.AddHead(item5);
                }
            }
            else
            {
                if (!((PolymorphicRef*)item5)->Unk_40())
                {
                    if (reinterpret_cast<::fnv_005656d0::Thing *>((((FUN_005656d0_shell*)item5)))->FUN_005656d0())
                    {
                        ((CellC4Holder*)this)->unkC4->list4C.AddHead(item5);
                    }
                }
                if (reinterpret_cast<::fnv_0056a250::FUN_0056a250_shell *>((((FUN_0056a250_shell*)item5)))->FUN_0056a250())
                {
                    ((CellC4Holder*)this)->unkC4->list54.AddHead(item5);
                }
            }
        }
    }
    ::FUN_00541ae0((char *)this);
    while (!localList9.FUN_008256d0())
    {
        TESObjectREFR* item3 = ((::TESObjectREFR *)(new ((void *)&(localList9)) ::Vec3()));
        ((BSSimpleList_standin*)&localList9)->FUN_0063f7b0();
        TESObjectREFR* other = reinterpret_cast<::fnv_00569ac0::FUN_00569ac0_shell *>((((FUN_00569ac0_shell*)item3)))->FUN_00569ac0();
        CellSubTarget* a8 = (CellSubTarget*)reinterpret_cast<::fnv_00545960::S *>((((FUN_00545960_shell*)this)))->FUN_00545960((::fnv_00545960::A *)(item3));
        CellSubTarget* b2 = (CellSubTarget*)reinterpret_cast<::fnv_00545960::S *>((((FUN_00545960_shell*)this)))->FUN_00545960((::fnv_00545960::A *)(other));
        if (a8 != b2)
        {
            b2->Unk_37(a8, 1);
        }
    }
    TESWorldSpace* extra9 = GetParentWorldSpace();
    if (extra9 != 0)
    {
        iter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::fnv_00587870::OverlapHolder *>((((FUN_00587870_shell*)extra9)))->FUN_00587870((::fnv_00587870::CellH *)(::TESObjectCELL *)(this))));
        while (iter != 0 && !iter->FUN_008256d0())
        {
            reinterpret_cast<::CellLike *>((((FUN_00545740_shell*)this)))->GetOrCreateFaceGenNode((::RefForm *)(((::TESObjectREFR *)(new ((void *)(iter)) ::Vec3()))));
            iter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        }
    }
}
