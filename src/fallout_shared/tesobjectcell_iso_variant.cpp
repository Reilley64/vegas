// src/fallout_shared/tesobjectcell_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectcell.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include <new>
#include "fnv/decl/Actor_0087f4a0.h"
#include "fnv/decl/B572270Object.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_0041de40_class.h"
#include "fnv/decl/FUN_0041df90_shell.h"
#include "fnv/decl/FUN_0041dfd0_Shell.h"
#include "fnv/decl/FUN_0041e310_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_0042cde0_shell.h"
#include "fnv/decl/FUN_0042e250_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00452370_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_00477090_Owner.h"
#include "fnv/decl/FUN_00484580_shell.h"
#include "fnv/decl/FUN_00484610_shell.h"
#include "fnv/decl/FUN_00526120_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_00565450_shell.h"
#include "fnv/decl/FUN_00569250_shell.h"
#include "fnv/decl/FUN_0056ae60_Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00881c90_cls.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00546b10__FUN_00546b10_class.h"
#include "fnv/decl/fnv_00550200__FUN_00550200.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s577de0__Owner.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00475000.h"
#include "fnv/symbols_00526000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

struct ExpiredRefPosition3
{
    float x, y, z;
};
class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
    int FUN_00401170();
};
struct FUN_00546af0_shell : public TESObjectCELL
{
    unsigned int FUN_00546af0();
};
struct BGSSaveLoadGame
{
};
struct RefNode;
struct RefrShell;
struct ExtraShell;
struct ZoneShell
{
};
struct Modelish
{
};
struct RefNode
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};
struct Inner3c
{
    virtual void v0();
    virtual bool v1();
};
class IngredientItem : public TESBoundObject
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;

    Inner3c m3c;
};
struct Obj34
{
};
struct ExtraShell : public ExtraDataList
{
};
struct RefrShell : public TESObjectREFR
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void V49(int a);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool V64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual bool V88();
    virtual void v89();
    virtual void v90();
    virtual ExpiredRefPosition3 V91();
    virtual void V92(ExpiredRefPosition3* p);
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void V130(bool b);
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool V139(int a);
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void* V165();
    virtual void* V166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void V201(int a, int b, int c);
    ZoneShell* FUN_00567d20();
    void FUN_00575700(ExpiredRefPosition3 p);
};
struct Calendar
{
public:
    unsigned int GetGameHoursPassed();
};
struct DHShell : public TESDataHandler
{
};
struct CellShell : public FUN_00546af0_shell
{
    bool FUN_0054df30();
};
// @fnv 0x0054df30
bool CellShell::FUN_0054df30()
{
    if (((unsigned char)(reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10())))
        return false;
    unsigned long _type;
    bool _changed;
    bool _allowed;
    ZoneShell* _special;
    unsigned int _oldState;
    RefNode* _item;
    bool _done;
    _oldState = reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::Calendar *>(&::g_011de7b8))))->GetGameHoursPassed();
    _changed = 0;
    _done = 0;
    _type = FUN_00546af0();
    if (_type == 0)
    {
        CellRefLockEnter();
        RefNode* a;
        a = ((::RefNode *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        for (; 0 != a && !a->FUN_008256d0();)
        {
            RefrShell* flag6;
            flag6 = *((::RefrShell **)(new ((void *)(a)) ::Vec3()));
            a = ((::RefNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
            switch (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((flag6))->FUN_007af430()))->FUN_00401170())
            {
            case 0x1b:
                if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((flag6))->FUN_005653d0())
                {
                    flag6->V130(!reinterpret_cast<::FUN_0056ae60_Class *>((flag6))->FUN_0056ae60());
                }
                break;
            case 0x2a:
            case 0x2b:
                if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((flag6))->FUN_005653d0())
                {
                    RefrShell* c;
                    c = flag6;
                    if (reinterpret_cast<::FUN_00881c90_cls *>((c))->IsExpired(_oldState))
                    {
                        flag6->V130(!reinterpret_cast<::FUN_0056ae60_Class *>((flag6))->FUN_0056ae60());
                    }
                }
                break;
            }
        }
        ::FUN_00541ae0((char *)this);
        return true;
    }
    _allowed = 0;
    _special = ((::ZoneShell *)(reinterpret_cast<::TESObjectCELL *>(this)->FindEncounterZone()));
    if (_type == 0xffffffff)
    {
        _changed = 1;
        _done = 1;
        _allowed = 1;
    }
    else
    {
        if (_oldState - _type > ((unsigned int)(::fnv_00526100::FUN_00526100())))
            _allowed = 1;
        if (0 != _special)
        {
            if (::FUN_005262a0((::BGSEncounterZone *)(_special)))
                _changed = reinterpret_cast<::FUN_00526120_shell *>((_special))->FUN_00526120(this);
            else
                _changed = 0;
        }
        else
        {
            _changed = _allowed;
        }
    }
    CellRefLockEnter();
    {
        _item = ((::RefNode *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        for (; 0 != _item && !_item->FUN_008256d0();)
        {
            RefrShell* refr2;
            refr2 = *((::RefrShell **)(new ((void *)(_item)) ::Vec3()));
            _item = ((::RefNode *)(reinterpret_cast<::Callees *>((_item))->FUN_00726070()));
            if (_done && reinterpret_cast<::BSShaderRenderUtility *>((((DHShell*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((refr2))->FUN_0084e3a0()))))
            {
                if (!refr2->V88() && !reinterpret_cast<::s577de0::Owner *>((refr2))->FUN_00577de0())
                    refr2->V49(1);
                continue;
            }
            RefrShell* cnt;
            cnt = 0;
            if (refr2->V64())
                cnt = refr2;
            if (0 != cnt)
            {
                if (!reinterpret_cast<::FUN_00881c90_cls *>((cnt))->IsExpired(_oldState))
                    continue;
            }
            else
            {
                if (_allowed)
                {
                    if (reinterpret_cast<::FUN_00452370_shell *>((refr2))->FUN_00452370())
                    {
                        Obj34* v;
                        v = ((::Obj34 *)(::FUN_00475400(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr2))->FUN_007af430())))));
                        reinterpret_cast<::FUN_00477090_Owner *>((v))->UpdateSoundLevel((::FUN_00477090_Ref *)(refr2));
                        if (!!((void *)(reinterpret_cast<::FUN_0042e250_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))))->FUN_0042e250())))
                            reinterpret_cast<::FUN_00484610_shell *>((refr2))->SetFlag2000(true);
                    }
                }
                ZoneShell* q;
                q = refr2->FUN_00567d20();
                if (q != _special)
                {
                    if (q)
                    {
                        if (!::FUN_005262a0((::BGSEncounterZone *)(q)))
                            continue;
                    }
                }
                else
                {
                    if (!_changed)
                        continue;
                }
            }
            if (0 != cnt)
            {
                if (reinterpret_cast<::Actor_0087f4a0 *>((cnt))->FUN_0087f4a0())
                {
                    cnt->V201(1, 0, 0);
                    RefNode* i;
                    i = ((::RefNode *)(reinterpret_cast<::FUN_0041df90_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041df90()));
                    if (0 != i)
                    {
                        for (; 0 != i && !i->FUN_008256d0();)
                        {
                            RefrShell* tmp;
                            tmp = *((::RefrShell **)(new ((void *)(i)) ::Vec3()));
                            reinterpret_cast<::FUN_0041de40_class *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((tmp))->FUN_005d43c0()))))->FUN_0041de40((::TESObjectREFR *)(0));
                            if (!tmp->V88())
                                reinterpret_cast<::B572270Object *>((tmp))->FUN_00572270();
                            i->FUN_0063f7b0();
                        }
                        reinterpret_cast<::FUN_0041dfd0_Shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041dfd0();
                    }
                    ExpiredRefPosition3 b;
                    cnt->V92(&b);
                    bool s;
                    s = 0;
                    if (cnt->V166() == this)
                    {
                        s = 1;
                    }
                    else
                    {
                        if (cnt->V165() == ((void *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())))
                        {
                            if (reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(&b))))
                                s = 1;
                        }
                    }
                    if (s)
                    {
                        reinterpret_cast<::Reference *>((cnt))->FUN_00575830((::Position *)(::ExpiredRefPosition3 *)(&b));
                        cnt->FUN_00575700(cnt->V91());
                    }
                }
                else
                {
                    if (cnt->V139(0))
                    {
                        if (!cnt->V88() && !reinterpret_cast<::s577de0::Owner *>((cnt))->FUN_00577de0())
                        {
                            reinterpret_cast<::B572270Object *>((cnt))->FUN_00572270();
                            RefrShell* x;
                            x = ((::RefrShell *)(reinterpret_cast<::FUN_0041e310_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041e310()));
                            if (!!x)
                                reinterpret_cast<::B572270Object *>((x))->FUN_00572270();
                        }
                        RefNode* p;
                        p = ((::RefNode *)(reinterpret_cast<::FUN_0041df90_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041df90()));
                        if (!!p)
                        {
                            for (; p && !p->FUN_008256d0();)
                            {
                                RefrShell* y;
                                y = *((::RefrShell **)(new ((void *)(p)) ::Vec3()));
                                reinterpret_cast<::FUN_0041de40_class *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((y))->FUN_005d43c0()))))->FUN_0041de40((::TESObjectREFR *)(0));
                                if (!y->V88())
                                    reinterpret_cast<::B572270Object *>((y))->FUN_00572270();
                                p->FUN_0063f7b0();
                            }
                            reinterpret_cast<::FUN_0041dfd0_Shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041dfd0();
                        }
                    }
                }
            }
            else
            {
                switch (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr2))->FUN_007af430()))->FUN_00401170())
                {
                case 0x1b:
                    if (reinterpret_cast<::FUN_0056ae60_Class *>((refr2))->FUN_0056ae60())
                    {
                        refr2->V130(0);
                        if (!!((::Modelish *)(reinterpret_cast<::ExtraDataList *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))))->GetContainerChangeData())))
                        {
                            if (!reinterpret_cast<::FUN_0042cde0_shell *>((((::Modelish *)(reinterpret_cast<::ExtraDataList *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))))->GetContainerChangeData()))))->FUN_0042cde0())
                                reinterpret_cast<::FUN_00569250_shell *>((refr2))->FUN_00569250();
                        }
                    }
                    break;
                case 0x26:
                    reinterpret_cast<::FUN_00484580_shell *>((refr2))->FUN_00484580(false);
                    break;
                case 0x1d:
                    if (reinterpret_cast<::FUN_00440d80_shell *>((refr2))->FUN_00440d80() && !reinterpret_cast<::FUN_00565450_shell *>((refr2))->FUN_00565450() && !refr2->V88())
                    {
                        IngredientItem* j;
                        j = dynamic_cast<IngredientItem*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr2))->FUN_007af430())));
                        if (0 != j)
                        {
                            if (j->m3c.v1())
                                refr2->V49(0);
                        }
                    }
                    break;
                }
            }
            ::FUN_005ac190((::TESObjectREFR *)(refr2), (::ExtraDataList *)(::ExtraShell *)(((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))));
            ::FUN_005ac750((::TESForm *)(refr2), (::ExtraDataList *)(::ExtraShell *)(((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))), 0x80000000);
        }
    }
    ::FUN_00541ae0((char *)this);
    reinterpret_cast<::fnv_00546b10::FUN_00546b10_class *>(this)->UpdateCellExtraData((::BSExtraData *)(0), false);
    return _changed;
}
