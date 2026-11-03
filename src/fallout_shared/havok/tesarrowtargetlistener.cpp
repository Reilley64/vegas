
// src/fallout_shared/havok/tesarrowtargetlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/tesarrowtargetlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_00563200_Struct.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/Projectile.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_01268000.h"
struct Obj;

struct Obj
{
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
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool v224();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int FUN_00401170();
};


struct FUN_0062a510_cls
{
    void FUN_0062a510(int a1);
};

struct UnknownBlock
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct ListNodeHelper
{
    void* item;
};
struct Owner_0062a670
{
    UnknownBlock prefix00;
    UnknownBlock prefix10;
    UnknownBlock prefix20;
    UnknownBlock prefix30;
    UnknownBlock prefix40;
    UnknownBlock prefix50;
    UnknownBlock prefix60;
    UnknownBlock prefix70;
    unsigned int unk80, unk84;
    ListNodeHelper node;
    void* GetNodeItem();
};
// @fnv 0x0062a510
void FUN_0062a510_cls::FUN_0062a510(int a1)
{
    Obj* o_tmp = ((::Obj *)(::FUN_004b5a80((const void *)(a1))));
    Obj* p = ((::Obj *)(::FUN_00653270((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681c0))), (::NiObject *)(o_tmp))));
    if (p != 0 && reinterpret_cast<::FUN_00563200_Struct *>((p))->MaskWithField(0x100) != 0)
    {
        Obj* m_tmp = ((::Obj *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(::Obj *)(((::Obj *)(::FUN_004ae750((void *)(p))))))));
        Obj* r = (m_tmp != 0) ? ((::Obj *)(reinterpret_cast<::Twin_0044ddc0 *>((m_tmp))->GetName())) : 0;
        int g_tmp = ((int)(::FUN_0056f930((::NiAVObject *)(r))));
        Obj* t = ((::Obj *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::Obj *>(&::g_011e0e80))))->GetCurrentProcessData()));
        for (unsigned int i = 0; i < reinterpret_cast<::FUN_005be5c0_shell *>((t))->FUN_005be5c0(0); ++i)
        {
            Obj* e = ((::Obj *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((t))->FUN_00968670(i)));
            if (e != 0)
            {
                if (e->v224())
                {
                    Obj* u = e;
                    if (u != 0)
                    {
                        if (reinterpret_cast<::FUN_00444d00_Class *>((u))->FUN_00444d00(0x80))
                        {
                            if (u->FUN_00401170() == 0x3d)
                            {
                                if (((int)((::Obj *)(reinterpret_cast<::Twin_0044ddc0 *>((u))->GetName())) & 0x20) == 0)
                                {
                                    Obj* v = ((::Obj *)(reinterpret_cast<::Owner_0062a670 *>((u))->GetNodeItem()));
                                    if (v->unk1c == a1)
                                    {
                                        if (::FUN_00472380((int)(u)) == 4)
                                        {
                                            reinterpret_cast<::Projectile *>((u))->FUN_009bc8f0();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
// @fnv 0x0062a670
void* Owner_0062a670::GetNodeItem()
{
    return *((void **)(new ((void *)&(node)) ::Vec3()));
}

namespace fnv_0062a690 {
struct S_0062a690_Extra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct S_0062a690_Actor
{
    virtual void unk_000();
    virtual void unk_001();
    virtual void unk_002();
    virtual void unk_003();
    virtual void unk_004();
    virtual void unk_005();
    virtual void unk_006();
    virtual void unk_007();
    virtual void unk_008();
    virtual void unk_009();
    virtual void unk_010();
    virtual void unk_011();
    virtual void unk_012();
    virtual void unk_013();
    virtual void unk_014();
    virtual void unk_015();
    virtual void unk_016();
    virtual void unk_017();
    virtual void unk_018();
    virtual void unk_019();
    virtual void unk_020();
    virtual void unk_021();
    virtual void unk_022();
    virtual void unk_023();
    virtual void unk_024();
    virtual void unk_025();
    virtual void unk_026();
    virtual void unk_027();
    virtual void unk_028();
    virtual void unk_029();
    virtual void unk_030();
    virtual void unk_031();
    virtual void unk_032();
    virtual void unk_033();
    virtual void unk_034();
    virtual void unk_035();
    virtual void unk_036();
    virtual void unk_037();
    virtual void unk_038();
    virtual void unk_039();
    virtual void unk_040();
    virtual void unk_041();
    virtual void unk_042();
    virtual void unk_043();
    virtual void unk_044();
    virtual void unk_045();
    virtual void unk_046();
    virtual void unk_047();
    virtual void unk_048();
    virtual void unk_049();
    virtual void unk_050();
    virtual void unk_051();
    virtual void unk_052();
    virtual void unk_053();
    virtual void unk_054();
    virtual void unk_055();
    virtual void unk_056();
    virtual void unk_057();
    virtual void unk_058();
    virtual void unk_059();
    virtual void unk_060();
    virtual void unk_061();
    virtual void unk_062();
    virtual void unk_063();
    virtual void unk_064();
    virtual void unk_065();
    virtual void unk_066();
    virtual void unk_067();
    virtual void unk_068();
    virtual void unk_069();
    virtual void unk_070();
    virtual void unk_071();
    virtual void unk_072();
    virtual void unk_073();
    virtual void unk_074();
    virtual void unk_075();
    virtual void unk_076();
    virtual void unk_077();
    virtual void unk_078();
    virtual void unk_079();
    virtual void unk_080();
    virtual void unk_081();
    virtual void unk_082();
    virtual void unk_083();
    virtual void unk_084();
    virtual void unk_085();
    virtual void unk_086();
    virtual void unk_087();
    virtual void unk_088();
    virtual void unk_089();
    virtual void unk_090();
    virtual void unk_091();
    virtual void unk_092();
    virtual void unk_093();
    virtual void unk_094();
    virtual void unk_095();
    virtual void unk_096();
    virtual void unk_097();
    virtual void unk_098();
    virtual void unk_099();
    virtual void unk_100();
    virtual void unk_101();
    virtual void unk_102();
    virtual void unk_103();
    virtual void unk_104();
    virtual void unk_105();
    virtual void unk_106();
    virtual void unk_107();
    virtual void unk_108();
    virtual void unk_109();
    virtual void unk_110();
    virtual void unk_111();
    virtual void unk_112();
    virtual void unk_113();
    virtual void unk_114();
    virtual void unk_115();
    virtual void unk_116();
    virtual void unk_117();
    virtual void unk_118();
    virtual void unk_119();
    virtual void unk_120();
    virtual void unk_121();
    virtual void unk_122();
    virtual void unk_123();
    virtual void unk_124();
    virtual void unk_125();
    virtual void unk_126();
    virtual void unk_127();
    virtual void unk_128();
    virtual void unk_129();
    virtual void unk_130();
    virtual void unk_131();
    virtual void unk_132();
    virtual void unk_133();
    virtual void unk_134();
    virtual void unk_135();
    virtual void unk_136();
    virtual bool vfn_0224();

    unsigned int FUN_00401170();
};

struct S_0062a690_ProcessArray
{
};

struct S_0062a690_ProcessLists
{
};


struct S_0062a690_A
{
};

struct S_0062a690_B
{
};


struct S_0062a690_Class
{
    void FUN_0062a690(int arg0);
};

// @fnv 0x0062a690
void S_0062a690_Class::FUN_0062a690(int arg0)
{
    void* v_08 = ::FUN_004b5a80((const void *)(arg0));
    S_0062a690_A* v_04 = ((::fnv_0062a690::S_0062a690_A *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_012681c0))), (::NiObject *)(v_08))));
    if (v_04 && reinterpret_cast<::FUN_00563200_Struct *>((v_04))->MaskWithField(0x100))
    {
        S_0062a690_B* v_18 = ((::fnv_0062a690::S_0062a690_B *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(void *)(((void *)(::FUN_004ae750((void *)(v_04))))))));
        void* ptr = v_18 ? ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((v_18))->GetName())) : 0;
        void* v_0c = ((void *)(::FUN_0056f930((::NiAVObject *)(ptr))));
        S_0062a690_ProcessArray* v_14 = ((::fnv_0062a690::S_0062a690_ProcessArray *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_0062a690::S_0062a690_ProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()));

        for (unsigned int v_1c = 0; v_1c < reinterpret_cast<::FUN_005be5c0_shell *>((v_14))->FUN_005be5c0(0); v_1c++)
        {
            S_0062a690_Actor* v_20 = ((::fnv_0062a690::S_0062a690_Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((v_14))->FUN_00968670(v_1c)));
            if (v_20 && v_20->vfn_0224())
            {
                S_0062a690_Actor* v_24 = v_20;
                if (v_24 && reinterpret_cast<::FUN_00444d00_Class *>((v_24))->FUN_00444d00(0x80) && v_24->FUN_00401170() == 0x3d)
                {
                    S_0062a690_Extra* v_28 = ((::fnv_0062a690::S_0062a690_Extra *)(reinterpret_cast<::Owner_0062a670 *>((v_24))->GetNodeItem()));
                    if (v_28->unk1c == arg0 && ::FUN_00472380((int)(v_24)) == 4)
                    {
                        reinterpret_cast<::Projectile *>((v_24))->FUN_009bc8f0();
                    }
                }
            }
        }
    }
}
}  // namespace fnv_0062a690
