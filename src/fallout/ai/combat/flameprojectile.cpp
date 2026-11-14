
// src/fallout/ai/combat/flameprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/flameprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004d7d50_StandIn.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_009bbc40.h"
#include "fnv/decl/LoadProjectile52.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/Projectile9c58.h"
#include "fnv/decl/ProjectileHelper.h"
#include "fnv/decl/ProjectileHit.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_009bda10__ProjectileRuntime.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009b3000.h"
#include "fnv/symbols_009c2000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_00508070_class.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_00632ce0_Class.h"
#include "fnv/decl/FUN_00645ce0_class.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/image_space_effect_param.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_009c0000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include <xmmintrin.h>
struct Flt
{
    operator unsigned int() const;
};

struct FUN_009b3cb0_shell
{
    uintptr_t FUN_009b3cb0();
};

// @fnv 0x009b3cb0
uintptr_t FUN_009b3cb0_shell::FUN_009b3cb0()
{
    return ((Flt*)((char*)this + 0x11c))->operator unsigned int();
}

struct BGSLoadFormBuffer
{
};

struct BeamProjectile
{
};

struct FlameProjectile : BeamProjectile
{
    FlameProjectile();
    void FUN_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Loads the base BeamProjectile data, then reads two 4-byte values from the buffer into this+0x150 and this+0x154.
// @fnv 0x009b3f00
void FlameProjectile::FUN_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::LoadProjectile52 *>(this)->LoadProjectile((::LoadBuf52 *)(apLoadGameBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x150), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x154), 4);
}

namespace fnv_009b3f50 {
struct BGSLoadFormBuffer;
class Projectile
{
};
struct FlameProjectile : Projectile
{
    void FUN_009b3f50(BGSLoadFormBuffer* apLoadGameBuffer);
    unsigned int pad00[0x54];
    float unk150;
    float unk154;
};

// Calls the base Projectile load routine, then zeroes the two floats at offsets 0x150 and 0x154.
// @fnv 0x009b3f50
void FlameProjectile::FUN_009b3f50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Projectile9c58 *>(this)->FUN_009c58e0((::LoadBuffer9c58 *)(apLoadGameBuffer));
    this->unk150 = 0.0f;
    this->unk154 = 0.0f;
}
}  // namespace fnv_009b3f50

// placeholder declarations
struct FUN_009b32b0_shell
{
    void ConfigureFlags();
};

struct FUN_005de0a0_shell
{
    void FUN_005de0a0(int, int);
};

struct FUN_009bda10_shell
{
};

// Calls FUN_005de0a0 with several bit flags and values, then calls FUN_009bda10.
// @fnv 0x009b32b0
void FUN_009b32b0_shell::ConfigureFlags()
{
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(0x10, 0);
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(1, 0);
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(2, 0);
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(8, 1);
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(0x20, 0);
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(0x80, 1);
    ((FUN_005de0a0_shell*)this)->FUN_005de0a0(0x100, 1);
    reinterpret_cast<::fnv_009bda10::ProjectileRuntime *>((((FUN_009bda10_shell*)this)))->FUN_009bda10();
}

struct BGSSaveFormBuffer
{
};
struct FUN_009c4ff0_cls
{
};
struct StandInFlame
{
    void Save(BGSSaveFormBuffer*);
};
// @fnv 0x009b3eb0
void StandInFlame::Save(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::ProjectileHelper *>((((FUN_009c4ff0_cls*)this)))->SaveProjectile(apSaveGameBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)this + 0x150, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)this + 0x154, 4, 0);
}

class Projectile
{
};
struct FUN_009b3f80_shell : Projectile
{
    void FUN_009b3f80();
};
// @fnv 0x009b3f80
void FUN_009b3f80_shell::FUN_009b3f80()
{
    reinterpret_cast<::FUN_009bbc40 *>(this)->FUN_009bbc40::~FUN_009bbc40();
}

namespace fnv_005de0a0 {
struct FUN_005de0a0_shell
{
    char _pad[0xc8];
    unsigned int m_flags;
    void FUN_005de0a0(unsigned int aFlags, bool abSet);
};

// Sets or clears the given flag bits in m_flags depending on abSet.
// @fnv 0x005de0a0
void FUN_005de0a0_shell::FUN_005de0a0(unsigned int aFlags, bool abSet)
{
    if (abSet)
        m_flags |= aFlags;
    else
        m_flags &= ~aFlags;
}
}  // namespace fnv_005de0a0

struct RTTI;
class NiNode;

struct Object
{
    virtual void Slot0()
    {}
    virtual void Slot1()
    {}
    virtual void Slot2()
    {}
    virtual NiNode* Slot3();
};

class NiAVObject;

class NiNode : public Object
{
  public:
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int index);
};

class NiAVObject : public NiNode
{
};

struct Particle
{
};

struct TESGlobal : Object
{
};



float GetMaxParticleGlobalValue(NiNode* node);

// @fnv 0x009b3da0
float GetMaxParticleGlobalValue(NiNode* node)
{
    float result = 0.0f;

    if (node)
    {
        NiNode* root;

        if (::FUN_0043b300((const ::NiRTTI *)(const ::RTTI *)(reinterpret_cast<RTTI const*>(&(*reinterpret_cast<void * *>(&::g_01202560)))), (::NiAVObject *)(node)))
        {
            Particle* particle = reinterpret_cast<Particle*>(node);

            for (unsigned int i = 0; result == _DAT_01012060 && i < reinterpret_cast<::FUN_004d7d50_StandIn *>((particle))->FUN_004d7d50(); ++i)
            {
                Object* object = ((::Object *)(reinterpret_cast<::Owner *>((particle))->GetByIndex(i)));

                if (object && ::FUN_0043b300((const ::NiRTTI *)(const ::RTTI *)(reinterpret_cast<RTTI const*>(&(*reinterpret_cast<int *>(&::g_01202540)))), (::NiAVObject *)(object)))
                {
                    TESGlobal* global = reinterpret_cast<TESGlobal*>(object);
                    result = reinterpret_cast<::FUN_00526ac0_shell *>((global))->FUN_00526ac0();
                }
            }
        }

        root = node->Slot3();

        if (root)
        {
            for (unsigned int i = 0; i < root->GetNumChildren(); ++i)
            {
                float childValue = GetMaxParticleGlobalValue(root->GetAt(i));

                if (childValue > result)
                    result = childValue;
            }
        }
    }

    return result;
}

struct Vec3
{
    float x, y, z;
public:
    Vec3();
};
struct FloatMatrix3
{
    float xx, xy, xz;
    float yx, yy, yz;
    float zx, zy, zz;
    FloatMatrix3* FUN_0043f8d0(intptr_t);
};
struct GameNode
{
};
struct OtherNode
{
    virtual void UnknownVirtual000();
    virtual void UnknownVirtual001();
    virtual void UnknownVirtual002();
    virtual void UnknownVirtual003();
    virtual void UnknownVirtual004();
    virtual void UnknownVirtual005();
    virtual void UnknownVirtual006();
    virtual void UnknownVirtual007();
    virtual void UnknownVirtual008();
    virtual void UnknownVirtual009();
    virtual void UnknownVirtual010();
    virtual void UnknownVirtual011();
    virtual void UnknownVirtual012();
    virtual void UnknownVirtual013();
    virtual void UnknownVirtual014();
    virtual void UnknownVirtual015();
    virtual void UnknownVirtual016();
    virtual void UnknownVirtual017();
    virtual void UnknownVirtual018();
    virtual void UnknownVirtual019();
    virtual void UnknownVirtual020();
    virtual void UnknownVirtual021();
    virtual void UnknownVirtual022();
    virtual void UnknownVirtual023();
    virtual void UnknownVirtual024();
    virtual void UnknownVirtual025();
    virtual void UnknownVirtual026();
    virtual void UnknownVirtual027();
    virtual void UnknownVirtual028();
    virtual void UnknownVirtual029();
    virtual void UnknownVirtual030();
    virtual void UnknownVirtual031();
    virtual void UnknownVirtual032();
    virtual void UnknownVirtual033();
    virtual void UnknownVirtual034();
    virtual void UnknownVirtual035();
    virtual void UnknownVirtual036();
    virtual void UnknownVirtual037();
    virtual void UnknownVirtual038();
    virtual void UnknownVirtual039();
    virtual void UnknownVirtual040();
    virtual void UnknownVirtual041();
    virtual void UnknownVirtual042();
    virtual void UnknownVirtual043();
    virtual void UnknownVirtual044();
    virtual void UnknownVirtual045();
    virtual void UnknownVirtual046();
    virtual void UnknownVirtual047();
    virtual void UnknownVirtual048();
    virtual void UnknownVirtual049();
    virtual void UnknownVirtual050();
    virtual void UnknownVirtual051();
    virtual void UnknownVirtual052();
    virtual void UnknownVirtual053();
    virtual void UnknownVirtual054();
    virtual void UnknownVirtual055();
    virtual void UnknownVirtual056();
    virtual void UnknownVirtual057();
    virtual void UnknownVirtual058();
    virtual void UnknownVirtual059();
    virtual void UnknownVirtual060();
    virtual void UnknownVirtual061();
    virtual void UnknownVirtual062();
    virtual void UnknownVirtual063();
    virtual void UnknownVirtual064();
    virtual void UnknownVirtual065();
    virtual void UnknownVirtual066();
    virtual void UnknownVirtual067();
    virtual void UnknownVirtual068();
    virtual void UnknownVirtual069();
    virtual void UnknownVirtual070();
    virtual void UnknownVirtual071();
    virtual void UnknownVirtual072();
    virtual void UnknownVirtual073();
    virtual void UnknownVirtual074();
    virtual void UnknownVirtual075();
    virtual void UnknownVirtual076();
    virtual void UnknownVirtual077();
    virtual void UnknownVirtual078();
    virtual void UnknownVirtual079();
    virtual void UnknownVirtual080();
    virtual void UnknownVirtual081();
    virtual void UnknownVirtual082();
    virtual void UnknownVirtual083();
    virtual void UnknownVirtual084();
    virtual void UnknownVirtual085();
    virtual void UnknownVirtual086();
    virtual void UnknownVirtual087();
    virtual void UnknownVirtual088();
    virtual void UnknownVirtual089();
    virtual void UnknownVirtual090();
    virtual void UnknownVirtual091();
    virtual void UnknownVirtual092();
    virtual void UnknownVirtual093();
    virtual void UnknownVirtual094();
    virtual void UnknownVirtual095();
    virtual void UnknownVirtual096();
    virtual void UnknownVirtual097();
    virtual void UnknownVirtual098();
    virtual void UnknownVirtual099();
    virtual void UnknownVirtual100();
    virtual void UnknownVirtual101();
    virtual void UnknownVirtual102();
    virtual void UnknownVirtual103();
    virtual void UnknownVirtual104();
    virtual void UnknownVirtual105();
    virtual void UnknownVirtual106();
    virtual void UnknownVirtual107();
    virtual void UnknownVirtual108();
    virtual void UnknownVirtual109();
    virtual void UnknownVirtual110();
    virtual void UnknownVirtual111();
    virtual void UnknownVirtual112();
    virtual void UnknownVirtual113();
    virtual void UnknownVirtual114();
    virtual void UnknownVirtual115();
    virtual void UnknownVirtual116();
    virtual void UnknownVirtual117();
    virtual void UnknownVirtual118();
    virtual void UnknownVirtual119();
    virtual void UnknownVirtual120();
    virtual void UnknownVirtual121();
    virtual void UnknownVirtual122();
    virtual void UnknownVirtual123();
    virtual void UnknownVirtual124();
    virtual void UnknownVirtual125();
    virtual void UnknownVirtual126();
    virtual void UnknownVirtual127();
    virtual void UnknownVirtual128();
    virtual void UnknownVirtual129();
    virtual void UnknownVirtual130();
    virtual GameNode* GetSecondary();
};
typedef GameNode*(* NodeGetter)(void*);
typedef void(* VectorSetter)(GameNode*, Vec3*);
typedef GameNode*(* SecondaryGetter)(void*);
struct ProjectileObject
{
    void UpdateProjectileNode();
};
// Gets the projectile's node and secondary node, sets a zero vector on the node, copies a matrix into this+0x94, and stores a scaled value at this+0x154.
// @fnv 0x009b3320
void ProjectileObject::UpdateProjectileNode()
{
    GameNode* node = ((NodeGetter)(*reinterpret_cast<void***>(this))[0x1d0 / 4])(this);
    if (node)
    {
        GameNode* secondary = ((::OtherNode *)(::FUN_00874480((char *)this)))->GetSecondary();
        if (secondary)
        {
            Vec3 vec;
            new ((void *)&(vec)) ::NiUpdateData(0.0f, 0, 0);
            ((VectorSetter)(*reinterpret_cast<void***>(node))[0xb8 / 4])(node, &vec);
            FloatMatrix3 firstMatrix;
            FloatMatrix3 second;
            *reinterpret_cast<FloatMatrix3*>(reinterpret_cast<char*>(this) + 0x94) = *(
                ((::FloatMatrix3 *)(::FUN_00461130((intptr_t)(((NodeGetter)(*reinterpret_cast<void***>(this))[0x1d0 / 4])(this)))))->FUN_0043f8d0(
                    ((intptr_t)(reinterpret_cast<::ThreeByThreeMatrix *>((((::FloatMatrix3 *)(::FUN_00461130((intptr_t)(secondary))))))->FUN_004b45b0({})))));
        }
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x154) =
            ::GetMaxParticleGlobalValue((::NiNode *)(node)) * ::DAT_0106b9e8;
    }
}

struct FUN_00717e50_shell;
struct ProjMgr;
struct ProjObj
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
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual unsigned char v137();
};
struct FUN_004181e0_shell
{
};
struct FUN_00874480_shell
{
};
struct FUN_005be5c0_shell
{
    unsigned int FUN_005be5c0();
public:
    unsigned int FUN_005be5c0(int);
};
struct FUN_00968670_shell
{
    ProjObj* FUN_00968670();
};
struct ProjMgr
{
    unsigned int FUN_005be5c0();
    ProjObj* FUN_00968670();
};
struct FUN_00717e50_shell
{
};

// Scans the project manager's objects for one whose v137 is set and whose FUN_004181e0 equals b and FUN_00874480 equals a, returning the first match or null.
// @fnv 0x009bd780
ProjObj* FindProjectObject(uintptr_t a, uintptr_t b)
{
    ProjObj* result = 0;
    for (unsigned int i = 0; result == 0 && i < reinterpret_cast<::FUN_005be5c0_shell *>((((::ProjMgr *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::FUN_00717e50_shell *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({}); ++i)
    {
        ProjObj* pObj = ((::ProjObj *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ProjMgr *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::FUN_00717e50_shell *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({})));
        if (pObj != 0)
        {
            if (pObj->v137() != 0)
            {
                ProjObj* pCandidate = pObj;
                if (((uintptr_t)(reinterpret_cast<::Actor *>((((FUN_004181e0_shell*)pCandidate)))->GetActorBase())) == b)
                {
                    if (((unsigned int)(::FUN_00874480((char *)(((FUN_00874480_shell*)pCandidate))))) == a)
                    {
                        result = pCandidate;
                    }
                }
            }
        }
    }
    return result;
}

class Ref9B3
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual bool IsDead();
};

struct HitEntry9B3
{
    Ref9B3* m_pkRef;
    int m_iArrayLength;
};

class HitNode9B3
{
  public:
    bool IsEmpty();

    HitEntry9B3* m_pkItem;
    HitNode9B3* m_pkNext;
};

class ProjectileBase9B3;
class Projectile9B3;


class Projectile9B3
{
  public:
    int unk00;
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    HitNode9B3 m_kHitList;

    bool CanProcessHit(Ref9B3* pkTarget, intptr_t iArg1, intptr_t iArg2, intptr_t iPart, int iArg4, int iArg5);
};

// @fnv 0x009b3cd0
bool Projectile9B3::CanProcessHit(Ref9B3* pkTarget, intptr_t iArg1, intptr_t iArg2, intptr_t iPart, int iArg4, int iArg5)
{
    if (::fnv_009c2c80::CanProjectileHit((::fnv_009c2c80::RefObj *)(pkTarget), (::fnv_009c2c80::CdBody *)(iPart), (intptr_t)(this), (::fnv_009c2c80::ProjData *)(::ProjectileBase9B3 *)(((::ProjectileBase9B3 *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase())))))
    {
        HitNode9B3* pkNode = &m_kHitList;
        while (pkNode && !pkNode->IsEmpty())
        {
            if (pkTarget == (*((::HitEntry9B3 **)(((::Vec3 *)(void *)(pkNode)))))->m_pkRef)
            {
                if (pkTarget && pkTarget->IsDead())
                    return false;
                else
                    return true;
            }
            pkNode = ((::HitNode9B3 *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        }
        if (reinterpret_cast<::ProjectileHit *>(this)->ProcessHit((::Obj *)(pkTarget), (*(const ::Vec *)(iArg1)), (*(const ::Vec *)(iArg2)), (::Buffer *)(iPart), iArg4, iArg5))
            return true;
    }
    return false;
}

struct FilterKey
{
    unsigned int m_uiCurrentValue;
    FilterKey();
};
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3& kPt) const;
    NiPoint3 operator+(const NiPoint3& kPt) const;
    NiPoint3 operator*(float fScalar) const;
};
struct NiMatrix33
{
    float rows[9];
    NiMatrix33* FUN_0043f8d0(NiMatrix33* result, NiMatrix33* rhs);
};
struct __declspec(align(16)) VisualState
{
    __m128 m_quad000;
    unsigned unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    unsigned unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    unsigned unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
};
struct Handle
{
    unsigned int id;
};
struct Controller
{
};
struct Source
{
    Controller* FUN_009b3cb0();
};
struct AttachedObject
{
    unsigned int* FUN_0070c440(unsigned int* out);
};
struct BoundForm;
struct FireObject
{
    virtual void fo000();
    virtual void fo004();
    virtual void fo008();
    virtual void fo00c();
    virtual void fo010();
    virtual void fo014();
    virtual void fo018();
    virtual void fo01c();
    virtual void fo020();
    virtual void fo024();
    virtual void fo028();
    virtual void fo02c();
    virtual void fo030();
    virtual void fo034();
    virtual void fo038();
    virtual void fo03c();
    virtual void fo040();
    virtual void fo044();
    virtual void fo048();
    virtual void fo04c();
    virtual void fo050();
    virtual void fo054();
    virtual void fo058();
    virtual void fo05c();
    virtual void fo060();
    virtual void fo064();
    virtual void fo068();
    virtual void fo06c();
    virtual void fo070();
    virtual void fo074();
    virtual void fo078();
    virtual void fo07c();
    virtual void fo080();
    virtual void fo084();
    virtual void fo088();
    virtual void fo08c();
    virtual void fo090();
    virtual void fo094();
    virtual void fo098();
    virtual void fo09c();
    virtual void fo0a0();
    virtual void fo0a4();
    virtual void fo0a8();
    virtual void fo0ac();
    virtual void fo0b0();
    virtual void fo0b4();
    virtual void fo0b8();
    virtual void fo0bc();
    virtual void fo0c0();
    virtual void fo0c4();
    virtual void fo0c8();
    virtual void fo0cc();
    virtual void fo0d0();
    virtual void fo0d4();
    virtual void fo0d8();
    virtual void fo0dc();
    virtual void fo0e0();
    virtual void fo0e4();
    virtual void fo0e8();
    virtual void fo0ec();
    virtual void fo0f0();
    virtual void fo0f4();
    virtual void fo0f8();
    virtual void fo0fc();
    virtual bool IsEnabled();
    BoundForm* FUN_00931ed0();
};
struct BoundForm
{
    FilterKey FUN_004a3a20();
};
struct ActorRef
{
};
struct Tester
{
    virtual void t000();
    virtual void t004();
    virtual void t008();
    virtual void t00c();
    virtual void t010();
    virtual void t014();
    virtual void t018();
    virtual void t01c();
    virtual void t020();
    virtual void t024();
    virtual void t028();
    virtual void t02c();
    virtual void t030();
    virtual void t034();
    virtual void t038();
    virtual void t03c();
    virtual void t040();
    virtual void t044();
    virtual void t048();
    virtual void t04c();
    virtual void t050();
    virtual void t054();
    virtual void t058();
    virtual void t05c();
    virtual void t060();
    virtual void t064();
    virtual void t068();
    virtual void t06c();
    virtual void t070();
    virtual void t074();
    virtual void t078();
    virtual void t07c();
    virtual void t080();
    virtual void t084();
    virtual void t088();
    virtual void t08c();
    virtual void t090();
    virtual void t094();
    virtual void t098();
    virtual void t09c();
    virtual void t0a0();
    virtual void t0a4();
    virtual void t0a8();
    virtual void t0ac();
    virtual void t0b0();
    virtual void t0b4();
    virtual void t0b8();
    virtual void t0bc();
    virtual void t0c0();
    virtual void t0c4();
    virtual bool Query(VisualState* state);
};
struct GameObject
{
};
struct FlagSetting
{
    unsigned char* FUN_00408d60();
};
struct FloatSetting
{
};
struct ImpactManager
{
};
struct ImpactData
{
    unsigned unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    void FUN_004a3a70();
    void FUN_004a3bc0();
    ImpactData()
    {
        FUN_004a3a70();
    }
    ~ImpactData()
    {
        FUN_004a3bc0();
    }
};
struct Color4
{
    float r, g, b, a;
};
extern const FilterKey& FUN_005dbe10();
extern void GenerateSpherePoints(NiPoint3*, int, NiPoint3, float, float, float, float, float);
struct ProjectileEffect
{
    virtual ~ProjectileEffect();
    virtual void pe004();
    virtual void pe008();
    virtual void pe00c();
    virtual void pe010();
    virtual void pe014();
    virtual void pe018();
    virtual void pe01c();
    virtual void pe020();
    virtual void pe024();
    virtual void pe028();
    virtual void pe02c();
    virtual void pe030();
    virtual void pe034();
    virtual void pe038();
    virtual void pe03c();
    virtual void pe040();
    virtual void pe044();
    virtual void pe048();
    virtual void pe04c();
    virtual void pe050();
    virtual void pe054();
    virtual void pe058();
    virtual void pe05c();
    virtual void pe060();
    virtual void pe064();
    virtual void pe068();
    virtual void pe06c();
    virtual void pe070();
    virtual void pe074();
    virtual void pe078();
    virtual void pe07c();
    virtual void pe080();
    virtual void pe084();
    virtual void pe088();
    virtual void pe08c();
    virtual void pe090();
    virtual void pe094();
    virtual void pe098();
    virtual void pe09c();
    virtual void pe0a0();
    virtual void pe0a4();
    virtual void pe0a8();
    virtual void pe0ac();
    virtual void pe0b0();
    virtual void pe0b4();
    virtual void pe0b8();
    virtual void pe0bc();
    virtual void pe0c0();
    virtual void pe0c4();
    virtual void pe0c8();
    virtual void pe0cc();
    virtual void pe0d0();
    virtual void pe0d4();
    virtual void pe0d8();
    virtual void pe0dc();
    virtual void pe0e0();
    virtual void pe0e4();
    virtual void pe0e8();
    virtual void pe0ec();
    virtual void pe0f0();
    virtual void pe0f4();
    virtual void pe0f8();
    virtual void pe0fc();
    virtual void pe100();
    virtual void pe104();
    virtual void pe108();
    virtual void pe10c();
    virtual void pe110();
    virtual void pe114();
    virtual void pe118();
    virtual void pe11c();
    virtual void pe120();
    virtual void pe124();
    virtual void pe128();
    virtual void pe12c();
    virtual void pe130();
    virtual void pe134();
    virtual void pe138();
    virtual void pe13c();
    virtual void pe140();
    virtual void pe144();
    virtual void pe148();
    virtual void pe14c();
    virtual void pe150();
    virtual void pe154();
    virtual void pe158();
    virtual void pe15c();
    virtual void pe160();
    virtual void pe164();
    virtual void pe168();
    virtual void pe16c();
    virtual void pe170();
    virtual void pe174();
    virtual void pe178();
    virtual void pe17c();
    virtual void pe180();
    virtual void pe184();
    virtual void pe188();
    virtual void pe18c();
    virtual void pe190();
    virtual void pe194();
    virtual void pe198();
    virtual void pe19c();
    virtual void pe1a0();
    virtual void pe1a4();
    virtual void pe1a8();
    virtual void pe1ac();
    virtual void pe1b0();
    virtual void pe1b4();
    virtual void pe1b8();
    virtual void pe1bc();
    virtual void pe1c0();
    virtual void pe1c4();
    virtual void pe1c8();
    virtual void pe1cc();
    virtual void pe1d0();
    virtual void pe1d4();
    virtual void pe1d8();
    virtual void pe1dc();
    virtual void pe1e0();
    virtual void pe1e4();
    virtual void pe1e8();
    virtual void pe1ec();
    virtual void pe1f0();
    virtual NiPoint3* GetFiringPosition();
    virtual void pe1f8();
    virtual void pe1fc();
    virtual void pe200();
    virtual void pe204();
    virtual void pe208();
    virtual void pe20c();
    virtual void pe210();
    virtual void pe214();
    virtual void pe218();
    virtual void pe21c();
    virtual void pe220();
    virtual void pe224();
    virtual void pe228();
    virtual void pe22c();
    virtual void pe230();
    virtual void pe234();
    virtual void pe238();
    virtual void pe23c();
    virtual void pe240();
    virtual void pe244();
    virtual void pe248();
    virtual void pe24c();
    virtual void pe250();
    virtual void pe254();
    virtual void pe258();
    virtual void pe25c();
    virtual void pe260();
    virtual void pe264();
    virtual void pe268();
    virtual void pe26c();
    virtual void pe270();
    virtual void pe274();
    virtual void pe278();
    virtual void pe27c();
    virtual void pe280();
    virtual void pe284();
    virtual void pe288();
    virtual void pe28c();
    virtual void pe290();
    virtual void pe294();
    virtual void pe298();
    virtual void pe29c();
    virtual void pe2a0();
    virtual void pe2a4();
    virtual void pe2a8();
    virtual void pe2ac();
    virtual void pe2b0();
    virtual void pe2b4();
    virtual void pe2b8();
    virtual float GetProjectileSpread(int iMode);
    Controller* FUN_009b3cb0();
    bool FUN_009b36f0();
};
struct EmitterProperties
{
};
// @fnv 0x009b36f0
bool ProjectileEffect::FUN_009b36f0()
{
    if (!((::ActorRef *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) || !((::BoundForm *)(reinterpret_cast<::FUN_004543c0_cls *>((((::ActorRef *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
        return false;
    bool emitted = false;
    void* pWorld = ((::BoundForm *)(reinterpret_cast<::FUN_004543c0_cls *>((((::ActorRef *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
    VisualState visual;
    new ((void *)&(visual)) ::FUN_004a3c20();
    NiPoint3 position;
    NiPoint3 direction;
    position = *GetFiringPosition();
    NiMatrix33 rotation;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(rotation))->FUN_004a0c90(GetProjectileSpread(0));
    NiMatrix33 spin;
    reinterpret_cast<::FUN_00524ac0_shell *>(&(spin))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
    NiMatrix33 result;
    rotation = *rotation.FUN_0043f8d0(&result, &spin);
    reinterpret_cast<::FUN_00439f50_class *>(&(rotation))->FUN_00439f50(1, &direction);
    reinterpret_cast<::FUN_004a0c10_s *>(&(direction))->FUN_004a0c10();
    Handle objectHandle;
    new ((void *)&(objectHandle)) ::GlobalObject_008c71b0(0);
    if (((::AttachedObject *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        unsigned int handleId;
        objectHandle.id = *((::AttachedObject *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&handleId);
    }
    else
    {
        reinterpret_cast<::FUN_004a39f0_shell *>(&(objectHandle))->FUN_004a39f0(6);
        if (((::FireObject *)(::FUN_00874480((char *)this))) && ((::FireObject *)(::FUN_00874480((char *)this)))->IsEnabled())
        {
            reinterpret_cast<::FUN_0059ce80_shell *>(&(objectHandle))->FUN_0059ce80((uintptr_t)&(const ::FilterKey &)(((::FireObject *)(::FUN_00874480((char *)this)))->FUN_00931ed0()->FUN_004a3a20()));
        }
        else
        {
            reinterpret_cast<::FUN_0059ce80_shell *>(&(objectHandle))->FUN_0059ce80((uintptr_t)&(FUN_005dbe10()));
        }
    }
    if (((::Controller *)(reinterpret_cast<::FUN_009b3cb0_shell *>(this)->FUN_009b3cb0())) && ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((::Controller *)(reinterpret_cast<::FUN_009b3cb0_shell *>(this)->FUN_009b3cb0()))))->GetName())))
        reinterpret_cast<::InterfaceManager *>(&(visual))->FUN_00500a20((::Tile *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((::Controller *)(reinterpret_cast<::FUN_009b3cb0_shell *>(this)->FUN_009b3cb0()))))->GetName()))));
    int iNumPoints = 4;
    NiPoint3 points[4];
    GenerateSpherePoints(points, 3, position, GetProjectileSpread(0), reinterpret_cast<::MobileObject *>(this)->GetLooking(), reinterpret_cast<::FUN_00645ce0_class *>(this)->GetField154(),
                         reinterpret_cast<::PathingRequest *>((((EmitterProperties*)((::GameObject *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))))->GetActorRadius(), ((float)(::FUN_004a4240())));
    points[3] = position + direction * (float)(((double)(reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter())) - ((double)(reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070())));
    ::FUN_004a3f70((char *)&(visual), *reinterpret_cast<const ::Flt *>(&objectHandle.id));
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(visual))->FUN_004a3da0(&position);
    for (int i = 0; i < 4; ++i)
    {
        reinterpret_cast<::Class_007f68a0 *>(&(visual))->FUN_007f68a0(points[i] - position);
        ImpactData impact;
        reinterpret_cast<::FUN_004a3fb0_shell *>(&(visual))->FUN_004a3fb0((::hkpAllRayHitCollector *)(void *)(&impact));
        Tester* tester = (Tester*)((::BoundForm *)(reinterpret_cast<::FUN_004543c0_cls *>((((::ActorRef *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::GameObject * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
        bool accepted = tester->Query(&visual);
        if (accepted)
            accepted = ::FUN_009c0d80((::Scene *)(::VisualState *)(&visual), (::Controller *)(void *)(this), 0, (float *)(0), 0, DAT_01016970) != 0;
        if (accepted)
            emitted = true;
        if (*(*reinterpret_cast<::FlagSetting *>(&::g_011f20ec)).FUN_00408d60())
        {
            Color4 greenColor;
            Color4 yellowColor;
            Color4* pColor = ((bool)(reinterpret_cast<::FUN_00632ce0_Class *>(&(visual))->FUN_00632ce0())) ? ((::Color4 *)(new ((void *)&(greenColor)) ::ImageSpaceEffectParam(1.0f, 0.0f, 0.0f, 1.0f)))
                                                   : ((::Color4 *)(new ((void *)&(yellowColor)) ::ImageSpaceEffectParam(1.0f, 1.0f, 0.0f, 1.0f)));
            __declspec(align(16)) Color4 color = *pColor;
            void* marker = ((void *)(::fnv_004b3890::FUN_004b3890((*(const class ::FUN_006815c0 *)(&position)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&color)), (*(const class ::FUN_006815c0 *)(&points[i])), (*(const ::fnv_004b3890::FUN_004a7800 *)(&color)), 1)));
            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::ImpactManager * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(marker), *((float *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::FloatSetting *>(&::g_011f210c)))))));
        }
    }
    return emitted;
}
#include "generated/data/fallout/ai/combat/flameprojectile.inc"
