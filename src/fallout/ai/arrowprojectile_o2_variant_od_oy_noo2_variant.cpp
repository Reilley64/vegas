
// src/fallout/ai/arrowprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/arrowprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/arrowprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/arrowprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/arrowprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/arrowprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00632c30_Class.h"
#include "fnv/decl/FUN_00632c60_Class.h"
#include "fnv/decl/FUN_008cd6a0_Class.h"
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/decl/Holder_cffa0.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S632.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/bhkFilter.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_0056d000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_008cf000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
struct Vec3
{
    float x, y, z;
    Vec3 ApplyScaled(float f);
};

struct __declspec(align(16)) Vec4
{
    __m128 quad;
    Vec4();
};


struct Filter
{
    int v;
    Filter();
};

struct Shape;
struct EObj;
struct WorldObj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void GetTransform(EObj*);
    Filter FUN_0043b4f0();
};

struct CollObj
{
};


struct EObj
{
    struct RawVector
    {
        __m128 quad;
    };
    RawVector storage[4];
    EObj();
    void FUN_00cb2240(void* g, void* f);
};

struct GObj
{
    struct RawVector
    {
        __m128 quad;
    };
    RawVector storage[4];
    GObj(EObj* e);
};


struct CSub
{
    __m128 quad;
};

struct __declspec(align(16)) CObj
{
    CSub m0;
    CSub m1;
    unsigned int flags20, filter24;
};

struct Sub2;
struct DObj;
struct ResObj
{
};

struct Sub2
{
    bool value;
};

struct __declspec(align(16)) DObj
{
    float normalX, normalY, normalZ, normalW;
    float fraction;
    int m_uiExtraInfo, unk18, unk1c;
    unsigned int shapeKeys[8];
    void* rootCollidable;
};

struct Shape
{
};

class NiAVObject;
struct NiNode
{
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};

struct P1Obj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual NiNode* getNode();
};

// @fnv 0x008cfbc0
void* __cdecl FUN_008cfbc0(void* p1, Vec3 a, Vec3 b, float* p4, bool p5)
{
    bool flag = false;
    if (p1)
    {
        CollObj* coll = ((::CollObj *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(p1))));
        if (coll)
        {
            WorldObj* world = ((::WorldObj *)(::fnv_006fa820::FUN_006fa820((const char *)(coll))));
            Shape* shape = world ? ((::Shape *)(reinterpret_cast<::FUN_004ae6a0_shell *>((world))->FUN_004ae6a0())) : 0;
            if (shape)
            {
                if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_0043b4d0() == 8)
                {
                    if (reinterpret_cast<::bhkFilter *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_006240b0() != 0x12)
                    {
                        if (reinterpret_cast<::bhkFilter *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_006240b0() != 0x13)
                        {
                            if (!p5 || reinterpret_cast<::bhkFilter *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_006240b0() != 1)
                            {
                                Vec4 va;
                                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&va)), (const ::fnv_004a3e00::NiPoint3 &)(a));
                                Vec4 vb;
                                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vb)), (const ::fnv_004a3e00::NiPoint3 &)((const ::Vec3 &)((*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(a))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(b.ApplyScaled(*p4)), {}))))));
                                CObj oc;
                                reinterpret_cast<::S632 *>(&(oc))->FUN_00632ca0();
                                DObj od;
                                ::FUN_004a3d20((void *)&(od));
                                EObj oe;
                                if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_01267e64))), (::NiAVObject *)(coll)))
                                {
                                    CollObj* scaledColl = coll;
                                    if (!reinterpret_cast<::Holder_cffa0 *>((world))->FUN_008cffa0() || reinterpret_cast<::BSMultiBoundSphere *>((scaledColl))->GetRadius() == 1.0)
                                    {
                                        ::FromHK((*(::hkTransform *)(&oe)), (*(const ::NiTransform *)(((void *)(::FUN_00461130((int)(((P1Obj*)p1))))))));
                                        if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012683c8))), (::NiAVObject *)(world)))
                                        {
                                            WorldObj* transformedWorld = world;
                                            EObj of;
                                            GObj og(&oe);
                                            reinterpret_cast<::FUN_008cd6a0_Class *>(&(of))->FUN_008cd6a0(((void *)(reinterpret_cast<::BGSCameraPath *>((transformedWorld))->GetShotList())),
                                                            ((void *)(reinterpret_cast<::TESTopicInfo *>((transformedWorld))->GetAddTopicList())));
                                            oe.FUN_00cb2240(&og, &of);
                                        }
                                    }
                                    else
                                    {
                                        world->GetTransform(&oe);
                                    }
                                }
                                else
                                {
                                    world->GetTransform(&oe);
                                }
                                reinterpret_cast<::FUN_00c7f690_cls *>(&(oc.m0))->FUN_00c7f690((const ::S_00c7f690_M *)(::EObj *)(&oe), (const ::S_00c7f690_V *)(::Vec4 *)(&va));
                                reinterpret_cast<::FUN_00c7f690_cls *>(&(oc.m1))->FUN_00c7f690((const ::S_00c7f690_M *)(::EObj *)(&oe), (const ::S_00c7f690_V *)(::Vec4 *)(&vb));
                                Sub2 bt;
                                reinterpret_cast<::FUN_00632c30_Class *>((((::ResObj *)(::FUN_004ae750((void *)(shape))))))->ForwardToV8(&bt, &oc, &od);
                                Sub2 bt2;
                                if (reinterpret_cast<::FUN_005609f0_shell *>((((::Sub2 *)(reinterpret_cast<::FUN_00632c60_Class *>(&(od))->FUN_00632c60((::CalleeObj *)(::Sub2 *)(&bt2))))))->FUN_005609f0())
                                {
                                    *p4 *= od.fraction;
                                    flag = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        NiNode* node = ((P1Obj*)p1)->getNode();
        if (node)
        {
            unsigned int i;
            for (i = 0; i < node->FUN_0043b480(); i++)
            {
                void* childItem = ((void *)(node->GetAt(i)));
                void* r = FUN_008cfbc0(childItem, a, b, p4, p5);
                if (r)
                    return r;
            }
        }
    }
    if (flag)
        return p1;
    return 0;
}
