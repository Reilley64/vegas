
// src/fallout/ai/mobileobject_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/mobileobject_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/mobileobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/mobileobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSProjectile.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C70CharacterController.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00407860_class.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_0056e120_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_00810510_Class.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_00810590_Class.h"
#include "fnv/decl/FUN_008105c0_Class.h"
#include "fnv/decl/FUN_008105e0_Class.h"
#include "fnv/decl/FUN_00810640_class.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00966980_shell.h"
#include "fnv/decl/FUN_009ae4a0_class.h"
#include "fnv/decl/FUN_009beae0_class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00c6ffc0_Class.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Getter_9b8.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S005620e0_Object.h"
#include "fnv/decl/S_00c6d7a0_Obj.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/V.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_00810610__FUN_00810610_Class.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0057b000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ce000.h"
class ExtraDismemberedLimbs;
class bhkCharacterController;
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "mobileobject_private/mobileobject_types_TESPackage.h"
#include "mobileobject_private/mobileobject_interface.h"
#include "../../../include/BSAudio.h"
#include "../../../include/SoundPlaybackHandle.h"
#include "mobileobject_private/mobileobject_packet.h"
struct UnkCallee
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4(int, int);
};
struct UnkRet
{
    char _0[16];
    UnkCallee* p10;
};
struct UnkHolder
{
    char _0[12];
    volatile int mC;
    volatile int m10;
    volatile int m14;
    void FUN_00c72210();
};

struct bhkWorldObject;
class NiAVObject;
struct bhkCollisionObject
{
public:
    static ::bhkCollisionObject *GetFromNiAVObject(::NiAVObject *);
};
struct bhkRigidBody_shell
{
    int FUN_00517630();
};
struct FNV_ALIGN(16) bhkUnaryAction
{
    char buf[16];
    bhkUnaryAction();
    void Set(float, float, float, float);
};
struct Vec3Arg
{
};
class NiAVObject;
class NiNode
{
  public:
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};
class NiAVObject
{
  public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual NiNode* IsSceneNode();
};

// @fnv 0x0062b930
void __cdecl FUN_0062b930(NiAVObject* apObject, Vec3Arg* apVec, bool abFlag)
{
    if (apObject)
    {
        bhkCollisionObject* j = ::bhkCollisionObject::GetFromNiAVObject(apObject);
        if (j)
        {
            bhkRigidBody_shell* e = (bhkRigidBody_shell*)((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(j))));
            if (e)
            {
                int c = e->FUN_00517630();
                if (((bool)(::FUN_00c8cce0(&c))))
                {
                    bhkUnaryAction l;
                    l.Set(*((float *)&(reinterpret_cast<::bhkCharacterController *>((apVec))->GetVectorElement(0))), *((float *)&(reinterpret_cast<::bhkCharacterController *>((apVec))->GetVectorElement(1))), *((float *)&(reinterpret_cast<::bhkCharacterController *>((apVec))->GetVectorElement(2))), 0.0f);
                    if (!abFlag)
                    {
                        reinterpret_cast<::V *>(&(l))->FUN_00553f70((*(const ::V *)(((void *)&(::fnv_00560d80::FUN_00560d80((void *)(e)))))));
                    }
                    reinterpret_cast<::S *>((e))->FUN_00561690((int)(&l));
                }
            }
        }
        NiNode* k = apObject->IsSceneNode();
        if (k)
        {
            for (unsigned int ba = 0; ba < k->FUN_0043b480(); ba++)
            {
                NiAVObject* b = k->GetAt(ba);
                FUN_0062b930(b, apVec, abFlag);
            }
        }
    }
}

struct xFilter
{
    xFilter(int, unsigned int, int);
    unsigned int m_uiFilterValue;
};
struct xDH;
struct xCinfoSub
{
    int m_q[12];
};
struct __declspec(align(16)) xCinfo
{
    xCinfo();
    ~xCinfo();
    unsigned int m_uiFilterInfo;
    int m_pCollisionShape;
    int m_pad08[6];
    xCinfoSub m_20;
    int m_pad50[4];
};
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};
struct xBody : xNiAlloc
{
    xBody(xCinfo*);
    int m_auiShapeKeys[6];
};
struct xNode;
struct xWorld;
struct xCell;
struct xBodyV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void FUN_9c(xWorld*);
};

struct xPtr
{
    bool operator==(xNode*) const;
    void FUN_0066b0d0(void*);
    xBodyV* operator->();
    void* m_p;
};
struct xDHOwner
{
};
struct xRef
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v49();
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
    virtual void v64();
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
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x9c];
    xPtr m_a0;
    void FUN_009ae280();
};

// @fnv 0x009ae280
void xRef::FUN_009ae280()
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::xPtr &)(m_a0))->operator==((int)(0)) && ((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
    {
        xCinfo CINFO;
        xShape* SHAPE = new xShape(reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930(), true);
        CINFO.m_pCollisionShape = ::FUN_004ae750(SHAPE);
        CINFO.m_uiFilterInfo = ((unsigned int)(::FUN_00559450((int *)&(xFilter(0x29, ::FUN_005dbe10(), 0)))));
        if (FUN_1d0())
            reinterpret_cast<::FUN_009ae4a0_class *>(&(CINFO.m_20))->FUN_009ae4a0(((::xDH *)(::FUN_00461130((int)(FUN_1d0())))));
        else
            reinterpret_cast<::FUN_0056e120_shell *>(&(CINFO.m_20))->FUN_0056e120();
        m_a0.FUN_0066b0d0(new xBody(&CINFO));
        m_a0->FUN_9c(((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())));
    }
}

#include <xmmintrin.h>
class Point9BE
{
  public:
    Point9BE();
    Point9BE(float fX, float fY, float fZ);
    float x, y, z;
};

class Matrix9BE
{
  public:
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class hkVector4_9BE
{
  public:
    hkVector4_9BE();
    hkVector4_9BE(float fX, float fY, float fZ, float fW);
    __m128 m_vComponents;
};

class Filter9BE
{
  public:
    Filter9BE();
    unsigned int m_uiBits;
};

class Node9BE;

class Entity9BE
{
  public:
};

class WorldObject9BE
{
  public:
    Filter9BE GetFilter();
};

class CollisionObject9BE
{
  public:
};

class NiNode9BE;

class Node9BE
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual NiNode9BE* IsSceneNode();
    const Matrix9BE& GetRotate();
};

class NiNode9BE : public Node9BE
{
  public:
    Node9BE* GetAt(unsigned int uiIndex);
};

class Shape9BE
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    Shape9BE(float fRadius, int iType);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class World9BE
{
  public:
    virtual void v000();
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
    virtual void HandleNode(Node9BE* pkNode, int iA, int iB, unsigned int uiFilterInfo, int iC);
};

class ControllerInfo9BE
{
  public:
    ControllerInfo9BE(int iType);
    ~ControllerInfo9BE();
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
};

class Actor9BE;

class Controller9BE
{
  public:
    virtual void v000();
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
    virtual void SetState(int iState);
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    Controller9BE(ControllerInfo9BE& kInfo, Actor9BE* pkActor);
    World9BE* GetWorld();
    Filter9BE GetFilter();
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
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
};

class ControllerPtr9BE
{
  public:
    ControllerPtr9BE(Controller9BE* pkController);
    ControllerPtr9BE(const ControllerPtr9BE& kOther);
    ~ControllerPtr9BE();
    Controller9BE* m_pPointer;
};

class Process9BE
{
  public:
    virtual void v000();
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
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void SetController(ControllerPtr9BE spController);
};

class Middle9BE
{
  public:
};

class Perks9BE
{
  public:
    virtual void v00();
    virtual void v04();
    virtual int GetLevel(int iPerk);
};

class Target9BE
{
  public:
    virtual void v000();
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
    virtual bool IsActor();
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
    virtual Node9BE* Get3D();
    Filter9BE GetFilter();
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
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    Perks9BE m_kPerks;
};

class Base9BE
{
  public:
};

class Actor9BE
{
  public:
    virtual void v000();
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
    virtual Node9BE* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Point9BE* GetPos();
    void FUN_009be0a0();
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
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    Process9BE* m_pkProcess;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    Target9BE* m_pkTarget;
};

class Setting9BE
{
  public:
};
extern const float g_fMaxValue9BE;


// @fnv 0x009be0a0
void Actor9BE::FUN_009be0a0()
{
    Node9BE* pkNode = Get3D();
    if (!pkNode || !m_pkProcess || ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60())))
        return;
    Middle9BE* pkMiddle = ((::Middle9BE *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    World9BE* pkWorld = pkMiddle ? ((::World9BE *)(reinterpret_cast<::FUN_004543c0_cls *>((pkMiddle))->FUN_004543c0())) : 0;
    if (pkWorld)
    {
        if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(8))
        {
            ::FUN_00c6a0b0((::NiAVObject *)(pkNode), 0, 1, 0);
            ::FUN_00c6a350((::NiAVObject *)(pkNode), 4, 1, 0, 1);
            return;
        }
        CollisionObject9BE* pkCollision = ((::CollisionObject9BE *)(::FUN_004a8b00((::BGSBodyPart *)(pkNode))));
        WorldObject9BE* pkWorldObject = 0;
        Entity9BE* pkEntity = 0;
        if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(4))
        {
            ::FUN_00c6a350((::NiAVObject *)(::Node9BE *)(Get3D()), 1, 1, 0, 1);
            if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce308)))))) != 0.0)
            {
                if (reinterpret_cast<::FUN_006d2c20_Class *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetFloatAtOffsetB0() > 0.0)
                    ::SetSelectionValue((int)(pkNode), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce308)))))) * reinterpret_cast<::FUN_006d2c20_Class *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetFloatAtOffsetB0(), 1, 0);
                else
                    ::SetSelectionValue((int)(pkNode), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce308)))))), 1, 0);
            }
            if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce5e8)))))) != 0.0)
                ::ApplyCollisionObjectCount((::NiAVObject *)(pkNode), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce5e8)))))), 1, 0);
            ::TraverseObject((::C6A2E0AVObject *)(pkNode), (void *)(6), 0, 1, 0);
            if (((::Target9BE *)(::FUN_00874480((char *)this))))
            {
                if (((::Target9BE *)(::FUN_00874480((char *)this)))->IsActor())
                {
                    Target9BE* pkOwner = ((::Target9BE *)(::FUN_00874480((char *)this)));
                    ::FUN_00c6a3d0(pkNode, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter9BE &)(pkOwner->GetFilter()))->FUN_004a3a20(), 1, 0);
                }
                else
                {
                    CollisionObject9BE* pkOwnerCollision = ((::CollisionObject9BE *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::Node9BE *)(((::Target9BE *)(::FUN_00874480((char *)this)))->Get3D()))));
                    WorldObject9BE* pkOwnerObject = pkOwnerCollision ? ((::WorldObject9BE *)(::fnv_006fa820::FUN_006fa820((const char *)(pkOwnerCollision)))) : 0;
                    if (pkOwnerObject)
                        ::FUN_00c6a3d0(pkNode, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter9BE &)(pkOwnerObject->GetFilter()))->FUN_004a3a20(), 1, 0);
                }
            }
            pkWorld->HandleNode(pkNode, 1, 1, 0, 0);
            if (pkCollision)
            {
                pkWorldObject = ((::WorldObject9BE *)(::FUN_004b5a80(((::Entity9BE *)(reinterpret_cast<::FUN_00620b80_shell *>((((::WorldObject9BE *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision))))))->GetReferenceFlags())))));
            }
            else if (pkNode->IsSceneNode())
            {
                NiNode9BE* pkParent = (NiNode9BE*)pkNode;
                if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkParent))->FUN_00453470())))
                {
                    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkParent))->FUN_00453470())); i++)
                    {
                        Node9BE* pkChild = ((::Node9BE *)(reinterpret_cast<::NiNode *>((pkParent))->GetAt(i)));
                        pkCollision = ((::CollisionObject9BE *)(::FUN_004a8b00((::BGSBodyPart *)(pkChild))));
                        if (pkCollision)
                        {
                            pkWorldObject = ((::WorldObject9BE *)(::FUN_004b5a80(((::Entity9BE *)(reinterpret_cast<::FUN_00620b80_shell *>((((::WorldObject9BE *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision))))))->GetReferenceFlags())))));
                            break;
                        }
                    }
                }
            }
            if (pkWorldObject && reinterpret_cast<::BGSProjectile *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88e0())
            {
                pkEntity = ((::Entity9BE *)(reinterpret_cast<::FUN_00620b80_shell *>((pkWorldObject))->GetReferenceFlags()));
                Point9BE kIntersectionOffset(reinterpret_cast<::FUN_00812870_t *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetUnka4(), reinterpret_cast<::LowProcess *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetCurrentDetectionAmount(), reinterpret_cast<::Getter_9b8 *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88c0());
                Point9BE kMotionVelocity;
                hkVector4_9BE kHkVelocity;
                Matrix9BE kRot = Get3D()->GetRotate();
                ::FUN_00a582f0((const float *)&(kRot), (const float *)&(const ::Point9BE &)(Point9BE(0.0f, 0.0f, 0.0f)), 1, (const ::Point314 *)&(kIntersectionOffset), (::Point314 *)&(kMotionVelocity));
                reinterpret_cast<::bhkUnaryAction *>(&(kHkVelocity))->Set(kMotionVelocity.x, kMotionVelocity.y, kMotionVelocity.z, 0.0f);
                reinterpret_cast<::FUN_00561800_Class *>((pkEntity))->FUN_00561800((::FUN_00561730_Obj *)&(kHkVelocity));
            }
            return;
        }
        Controller9BE* pkController = ((::Controller9BE *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
        if (!pkController)
        {
            ControllerInfo9BE kInfo(1);
            reinterpret_cast<::FUN_00857230_shell *>(&(kInfo))->SetSound((::TESSound *)(pkWorld));
            reinterpret_cast<::FUN_00810550_class *>(&(kInfo))->FUN_00810550(1.0f);
            reinterpret_cast<::FUN_008ac890_shell *>(&(kInfo))->SetWaterForm((::TESWaterForm *)(pkNode));
            reinterpret_cast<::FUN_00810510_Class *>(&(kInfo))->FUN_00810510((*(const ::NiPoint3 *)(GetPos())));
            if (reinterpret_cast<::BGSProjectile *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88e0())
                reinterpret_cast<::FUN_008105c0_Class *>(&(kInfo))->SetPointer(new Shape9BE(1.0f, 1));
            else
                reinterpret_cast<::FUN_008105c0_Class *>(&(kInfo))->SetPointer(new Shape9BE(0.1f, 1));
            reinterpret_cast<::FUN_009beae0_class *>(&(kInfo))->SetByte95(0);
            reinterpret_cast<::FUN_00810530_c *>(&(kInfo))->FUN_00810530(0);
            float m_fGlyphExtent = reinterpret_cast<::FUN_00966980_shell *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_00966980();
            if (m_pkTarget && m_pkTarget->IsActor())
            {
                Target9BE* pkTarget = m_pkTarget;
                reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(6, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter9BE &)(pkTarget->GetFilter()))->FUN_004a3a20());
                if (pkTarget->m_kPerks.GetLevel(0x33) > 0)
                    m_fGlyphExtent *= 1.0f / FUN_00716440();
            }
            reinterpret_cast<::FUN_00407860_class *>(&(kInfo))->FUN_00407860(m_fGlyphExtent);
            reinterpret_cast<::FUN_00810570_shell *>(&(kInfo))->SetAssociatedActorValue(6);
            pkController = new Controller9BE(kInfo, this);
            reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((pkController))->FUN_00810610(((bool)(::FUN_00525420())));
            reinterpret_cast<::FUN_008105e0_Class *>((pkController))->FUN_008105e0(1);
            hkVector4_9BE kUp(-g_fMaxValue9BE, 0.0f, 0.0f, 0.0f);
            reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((pkController))->FUN_0080fb00((int)&(kUp));
            m_pkProcess->SetController(pkController);
            reinterpret_cast<::FUN_00810640_class *>((pkController))->FUN_00810640((int)(this));
            ::FUN_00c6a0b0((::NiAVObject *)(pkNode), 0, 1, 0);
        }
        if (pkController)
        {
            if (pkMiddle)
                ::FUN_0057b1d0((char *)(pkController), reinterpret_cast<::FUN_005471e0_shell *>((pkMiddle))->FUN_005471e0());
            else
                ::FUN_0057b1d0((char *)(pkController), ::DAT_01015f5c);
            World9BE* pkOldWorld = pkController->GetWorld();
            reinterpret_cast<::C70CharacterController *>((pkController))->FUN_00c70c90((::WorldProxy *)(pkWorld));
            Node9BE* pkOldNode = ((::Node9BE *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660()));
            bool bReset = true;
            if (pkOldNode != pkNode)
            {
                reinterpret_cast<::S_00c6d7a0_Obj *>((pkController))->FUN_00c6d7a0((int)(pkNode));
                if (pkWorld && ::FUN_004bae00((const char *)(pkWorld)))
                {
                    pkController->SetState(0);
                    ::CopyBlock48(((::Node9BE *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660())), (const void *)(1));
                }
                ::FUN_00c6a350((::NiAVObject *)(pkNode), 4, 1, 0, 1);
                bReset = true;
            }
            Point9BE kPos = *GetPos();
            if (pkOldWorld != pkWorld)
            {
                if (pkOldWorld)
                    ::FUN_00c69ee0((::NiAVObject *)(pkNode), 1, 0);
                kPos.z += 8.0;
                bReset = true;
            }
            if (pkWorld)
            {
                reinterpret_cast<::S005620e0_Object *>((pkController))->FUN_005620e0((const ::S005620e0_Source *)&(kPos));
                if (bReset)
                {
                    Filter9BE kFilter = pkController->GetFilter();
                    unsigned int uiFilterInfo = reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(kFilter))->FUN_004a3a20();
                    pkWorld->HandleNode(pkNode, 1, 0, uiFilterInfo, 0);
                }
                else
                {
                    ::FUN_00c69f50((::S_00c69f50_Obj *)(pkNode), 1, 0);
                }
            }
        }
    }
}
