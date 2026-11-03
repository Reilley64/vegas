
// src/staging/blk_00800000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <new>
#include "fnv/decl/Actor80F.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_005dbf20.h"
#include "fnv/decl/FUN_0081c4a0_cls.h"
#include "fnv/decl/FUN_0081f1e0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESObjectREFR.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/XRef.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_0070c000.h"
#include "fnv/symbols_0080f000.h"
#include "fnv/symbols_01054000.h"
#include "fnv/symbols_0107a000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include <xmmintrin.h>

// Read a vector property from this object into an aligned local and hand it to a setter on
// the target passed in.

struct hkVector4B00
{
    __m128 m_vComponents;
    hkVector4B00();
};

struct VectorSourceB00
{
    void SubtractVectors(hkVector4B00& arOut);
    void FUN_00812b00(void* apTarget);
};

// @fnv 0x00812b00
void VectorSourceB00::FUN_00812b00(void* apTarget)
{
    hkVector4B00 kVector;
    SubtractVectors(kVector);
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(apTarget)), (const ::hkVector4 &)(kVector));
}

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator-(const xP3&) const;
    xP3 operator+(const xP3&) const;
    xP3 operator*(float) const;
};

struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};

struct __declspec(align(16)) xHitInfo
{
    xHitInfo(const xHitInfo*);
    int m_iWordAt00[4];
    float m_10;
    int m_14[15];
    void* m_50;
    int m_54[3];
};

struct xHitList
{
};

struct __declspec(align(16)) xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc7];
};

struct __declspec(align(16)) xPick
{
    xPick();
    void FUN_004a3f70(xFilter);
    char m_buf[0xb0];
};

struct xWorld
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
    virtual bool FUN_c8(xPick*);
};

struct xCell;

struct xOwner
{
    xFilter FUN_0070c440();
};

struct xActor;

struct xShooterV
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
    virtual xActor* FUN_2c();
};

struct xActor
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
    virtual bool FUN_100();
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
    virtual void* FUN_1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
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
    virtual void v165();
    virtual void v166();
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
    virtual void FUN_304(xP3, void*, xActor*, int);
    xFilter FUN_00931ed0();
    void FUN_0081eba0();
};

// @fnv 0x0081eba0
void xActor::FUN_0081eba0()
{
    void* EFFECT = FUN_1d0();
    if ((((::xShooterV *)(std::uintptr_t)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) && ((::xShooterV *)(std::uintptr_t)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->FUN_2c() != (*reinterpret_cast<::xActor * *>(&::_g_thePlayer))) || !EFFECT)
        return;
    xPick PICK;
    xP3 PLPOS;
    xP3 MYPOS;
    xP3 DIR;
    MYPOS = *FUN_1f4();
    PLPOS = *(*reinterpret_cast<::xActor * *>(&::_g_thePlayer))->FUN_1f4();
    PLPOS.z = PLPOS.z + ::FUN_0070c3b0((::FUN_0070c3b0_Dummy *)((*reinterpret_cast<::xActor * *>(&::_g_thePlayer)))) * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->FUN_00567400();
    DIR = MYPOS - PLPOS;
    xOwner* OWNER = ((::xOwner *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    xFilter FILTER(0);
    if (OWNER)
        FILTER = OWNER->FUN_0070c440();
    else
        FILTER = (*reinterpret_cast<::xActor * *>(&::_g_thePlayer))->FUN_00931ed0();
    PICK.FUN_004a3f70(FILTER);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(PICK))->FUN_004a3da0(&PLPOS);
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(PICK))->FUN_004a3eb0((void *)&(const ::xP3 &)(PLPOS + DIR));
    xAllHits HITS;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(PICK))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::xAllHits *)(&HITS));
    bool DONE = false;
    if (((::xCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->GetTarget())) && ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()))->FUN_c8(&PICK))
    {
        bool GO = true;
        for (int I = 0; GO && I < ((intptr_t)(reinterpret_cast<::Callees *>((((::xHitList *)(::FUN_00460140((intptr_t)&(HITS))))))->FUN_00726070())) && !DONE; I++)
        {
            xHitInfo INFO(((::xHitInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::xHitList *)(::FUN_00460140((intptr_t)&(HITS))))))->GetEntryAt(I))));
            void* OBJ = ((void *)(::FUN_004b5820((::FormLike *)(INFO.m_50))));
            if (OBJ)
            {
                void* FormRecordHeader = ::FUN_004b5a80(::FUN_004b59f0(INFO.m_50));
                xActor* ACTOR = ((::xActor *)(::FUN_0056f930((::NiAVObject *)(OBJ))));
                if (ACTOR != (*reinterpret_cast<::xActor * *>(&::_g_thePlayer)) && ACTOR != this && !ACTOR->FUN_100() && FormRecordHeader)
                {
                    xP3 HITPOS = PLPOS + DIR * INFO.m_10;
                    FUN_304(HITPOS, FormRecordHeader, ACTOR, 0);
                    GO = false;
                }
            }
        }
    }
}

struct ImpactValue
{
};

struct ImpactState
{
};

struct ImpactType
{
    int value;
};

struct __declspec(align(16)) ImpactVector
{
    __m128 coordinates;
};

struct ImpactResult
{
};

struct ImpactObject
{
    virtual void unknown_0000();
    virtual void unknown_0004();
    virtual void unknown_0008();
    virtual void unknown_000c();
    virtual void unknown_0010();
    virtual void unknown_0014();
    virtual void unknown_0018();
    virtual void unknown_001c();
    virtual void unknown_0020();
    virtual void unknown_0024();
    virtual void unknown_0028();
    virtual void unknown_002c();
    virtual void unknown_0030();
    virtual void unknown_0034();
    virtual void unknown_0038();
    virtual void unknown_003c();
    virtual void unknown_0040();
    virtual void unknown_0044();
    virtual void unknown_0048();
    virtual void unknown_004c();
    virtual void unknown_0050();
    virtual void unknown_0054();
    virtual void unknown_0058();
    virtual void unknown_005c();
    virtual void unknown_0060();
    virtual void unknown_0064();
    virtual void unknown_0068();
    virtual void unknown_006c();
    virtual void unknown_0070();
    virtual void unknown_0074();
    virtual void unknown_0078();
    virtual void unknown_007c();
    virtual void unknown_0080();
    virtual void unknown_0084();
    virtual void unknown_0088();
    virtual void unknown_008c();
    virtual void unknown_0090();
    virtual void unknown_0094();
    virtual ImpactState* unknown_0098();
    void FUN_0043b4f0(ImpactType*);
};

struct ImpactOwner
{
    void FUN_0081f000(float x, float y, float z, float dx, float dy, float dz, ImpactObject* object);
};

// @fnv 0x0081f000
void ImpactOwner::FUN_0081f000(float x, float y, float z, float dx, float dy, float dz, ImpactObject* object)
{
    if (!object)
        return;
    ImpactState* state = object->unknown_0098();
    if (state)
    {
        float scale = DAT_010546cc;
        ImpactType type;
        object->FUN_0043b4f0(&type);
        switch (reinterpret_cast<::FUN_0043b4d0_shell *>(&(type))->FUN_0043b4d0())
        {
        case 14:
            scale *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::originalRuntimeFloatSetting679))))));
            break;
        case 8:
        case 29:
            scale *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::originalRuntimeFloatSetting678))))));
            break;
        case 2:
        case 10:
            scale *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::g_011cf9d4))))));
            break;
        default:
            scale *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::originalRuntimeFloatSetting677))))));
            break;
        }
        float weight = ::FUN_004b5400((void *)(object));
        if (weight < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::originalRuntimeFloatSetting680)))))))
            scale = weight / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::originalRuntimeFloatSetting680)))))) * scale;
        scale *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactValue *>(&::g_011ce224))))));
        ImpactVector direction;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&direction)), (*(const ::fnv_004a3e00::NiPoint3 *)(&dx)));
        ImpactVector position;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&position)), (*(const ::fnv_004a3e00::NiPoint3 *)(&x)));
        reinterpret_cast<::S0062aea0_Vector *>(&(direction))->FUN_0062aea0();
        ImpactVector amount;
        new ((void *)&(amount)) ::FUN_005dbf20(scale);
        reinterpret_cast<::S_00627920 *>(&(direction))->FUN_00627920((::S_00561240 *)(::ImpactVector *)(&amount));
        reinterpret_cast<::TESForm *>((state))->ClearData();
        reinterpret_cast<::FUN_0081f1e0_Class *>((((::ImpactResult *)(::FUN_004ae750((void *)(object))))))->ApplyVirtualCall({}, {});
        reinterpret_cast<::TESForm *>((state))->ClearData();
    }
}

namespace fnv_0080f810 {
struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
};
struct xRadius
{
};
struct xSndForm
{
};
struct xEffect
{
};
struct xCtl
{
};
struct xCell
{
};
struct xOwner
{
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(int, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
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
    virtual void* FUN_2c();
};

struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    float m_a8;
    int m_ac;
    float m_b0;
    xSound m_b4;
    xOwner* m_c0;
    xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner);
    xSound PlaySoundByFormID(void*, int, unsigned int, int);
};
// @fnv 0x0080f810
xProj::xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner) : xBase(a, b, c, d, kP1, kP2)
{
    m_88 = reinterpret_cast<::PathingRequest *>((((xRadius*)((::fnv_0080f810::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))->GetCenterRadius() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0080f810::xFltSetting *>(&::originalRuntimeFloatSetting1140))))));
    m_ac = 0;
    m_a8 = 0.0f;
    m_b0 = 1.0f;
    m_c0 = 0;
    if (apE)
        reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((int)(std::uintptr_t)(apE));
    else
        reinterpret_cast<::XRef *>(this)->FUN_0081e570(0);
    reinterpret_cast<::TESObjectREFR *>(this)->ResetProjectileIdleAnimation();
    reinterpret_cast<::Actor80F *>(this)->FUN_0080feb0();
    xVec4 V(-::DAT_0107a510, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((((::fnv_0080f810::xCtl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_0080fb00((std::intptr_t)(&V));
    reinterpret_cast<::CellView *>((((::fnv_0080f810::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(void *)(this), false);
    if (((::fnv_0080f810::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::fnv_0080f810::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
    {
        void* NAME = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_0080f810::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::fnv_0080f810::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_b4))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(m_b4))->Release();
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_0080f810::xSound &)(m_b4))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_0080f810::xSound &)(PlaySoundByFormID(NAME, 1, 0x40000102, 1))));
    }
    if (apOwner)
    {
        reinterpret_cast<::FUN_0081c4a0_cls *>((apOwner))->FUN_0081c4a0((::VTableTarget116 *)(void *)(this));
        m_c0 = apOwner;
    }
    reinterpret_cast<::xActor *>(this)->FUN_0081eba0();
    void* SHOOTER = ((::fnv_0080f810::xActorV *)(std::uintptr_t)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) ? ((::fnv_0080f810::xActorV *)(std::uintptr_t)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->FUN_2c() : 0;
    if (SHOOTER != (*reinterpret_cast<void * *>(&::_g_thePlayer)))
        ::FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0080f810::xFltSetting *>(&::g_011d1c28)))))));
    FUN_00484b60(0x10000000);
}
}
