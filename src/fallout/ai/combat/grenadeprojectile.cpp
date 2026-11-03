// fallout/ai/combat/grenadeprojectile.cpp: GrenadeProjectile, GPShell, ImpactProjectile (11 functions)

#include "fnv/form_fields.h"
#include "fnv/vats_camera_data_view.h"
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BeamEffect.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00525430_Class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00645c20_Class.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00885d70_Class.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009b7010_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/ImpulseSource.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/Projectile9c58.h"
#include "fnv/decl/ProjectileImpact__ImpProjectile.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_005726e0__FUN_005726e0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005de0a0__FUN_005de0a0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_0089a760__HActor.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00963eb0__PlayerView.h"
#include "fnv/decl/fnv_009bda10__ProjectileRuntime.h"
#include "fnv/decl/fnv_009c30d0__FUN_009c30d0_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009b5000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "grenadeprojectile_types.h"
#include <cstdint>
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_0087ce50_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/decl/S00561240_Vector.h"
#include <xmmintrin.h>
#include "fnv/decl/FUN_00885bd0_St.h"
#include "fnv/decl/ProjectileHit.h"
#include "fnv/decl/S.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_009c2000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_01017000.h"

// Returns true if the projectile's explosion detonates, or if it has an alt trigger and a positive explosion proximity.
// @fnv 0x009bdf80
bool GrenadeProjectile::IsProximityTriggered()
{
    return ((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))->GetHasExplosionDetonates() ||
           (((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))->GetHasExplosionAltTrigger() && ((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))->GetExplosionProximity() > 0.0);
}

struct S_004f15a0
{
};
struct GP_Base0
{
    virtual ~GP_Base0();
    char pad04[0x14];
};
struct GP_Base1
{
    virtual void f();
};
struct FUN_009bbc70 : public GP_Base0, public GP_Base1
{
    FUN_009bbc70(bool);
    virtual ~FUN_009bbc70();
    char pad1c[0x150 - 0x1c];
};
class FUN_009b3fa0 : public FUN_009bbc70
{
  public:
    bool bFlag150;
    FUN_009b3fa0(bool abFlag);
    virtual ~FUN_009b3fa0();
};
// Constructs the object via the base constructor with abFlag, clears bFlag150, and calls FUN_004f15a0 with 0x3e.
// @fnv 0x009b3fa0
FUN_009b3fa0::FUN_009b3fa0(bool abFlag) : FUN_009bbc70(abFlag)
{
    bFlag150 = false;
    reinterpret_cast<::FUN_004f15a0_shell *>((((S_004f15a0*)this)))->FUN_004f15a0(0x3e);
}

struct S4700
{
    bool FUN_009b4700(int, bool);
    virtual void f0(), f1(), f2(), f3(), f4(), f5(), f6(), f7(), f8(), f9(), f10(), f11(), f12(), f13(), f14(), f15(),
        f16(), f17(), f18(), f19(), f20(), f21(), f22(), f23(), f24(), f25(), f26(), f27(), f28(), f29(), f30(), f31(),
        f32(), f33(), f34(), f35(), f36(), f37(), f38(), f39(), f40(), f41(), f42(), f43(), f44(), f45(), f46(), f47(),
        f48(), f49(), f50(), f51(), f52(), f53(), f54(), f55(), f56(), f57(), f58(), f59(), f60(), f61(), f62(), f63(),
        f64();
    virtual void f65(), f66(), f67(), f68(), f69(), f70(), f71(), f72(), f73(), f74(), f75(), f76(), f77(), f78(),
        f79(), f80(), f81(), f82(), f83(), f84(), f85(), f86(), f87(), f88(), f89(), f90(), f91(), f92(), f93(), f94(),
        f95(), f96(), f97(), f98(), f99(), f100(), f101(), f102(), f103(), f104(), f105(), f106(), f107(), f108(),
        f109(), f110(), f111(), f112(), f113(), f114(), f115(), f116(), f117(), f118(), f119(), f120(), f121(), f122(),
        f123(), f124(), f125(), f126(), f127(), f128(), f129();
    virtual void f130(), f131(), f132(), f133(), f134(), f135(), f136(), f137(), f138(), f139(), f140(), f141(), f142(),
        f143(), f144(), f145(), f146(), f147(), f148(), f149(), f150(), f151(), f152(), f153(), f154(), f155(), f156(),
        f157(), f158(), f159(), f160(), f161(), f162(), f163(), f164(), f165(), f166(), f167(), f168(), f169(), f170(),
        f171(), f172(), f173(), f174(), f175(), f176(), f177(), f178(), f179(), f180(), f181(), f182(), f183(), f184(),
        f185(), f186(), f187(), f188(), f189(), f190(), f191(), f192(), f193(), f194();
    virtual void At30C();
};
// Calls FUN_009c43e0 with the given arguments, then invokes At30C, returning the result of the first call.
// @fnv 0x009b4700
bool S4700::FUN_009b4700(int aiArg, bool b)
{
    bool r = reinterpret_cast<::BeamEffect *>(this)->FUN_009c43e0(aiArg, b);
    At30C();
    return r;
}

struct NiAVObject;
struct Creature
{
};
struct FUN_009b4c70_shell : public Projectile
{
    void FUN_009b4c70();
};
// @fnv 0x009b4c70
void FUN_009b4c70_shell::FUN_009b4c70()
{
    if (((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))->GetHasExplosionDetonates() ||
        (((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))->GetHasExplosionAltTrigger() &&
         ((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))->GetExplosionProximity() > ::_DAT_01012060))
    {
        ::FUN_00c6a350(reinterpret_cast<NiAVObject*>(GetNiNode()), 5, true, false, true);
    }
}

struct BGSLoadFormBuffer;
struct C009c58e0
{
};
struct S009b4d10 : public FUN_009b3fa0
{
    void FUN_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009b4d10
void S009b4d10::FUN_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Projectile9c58 *>((((C009c58e0*)this)))->FUN_009c58e0((::LoadBuffer9c58 *)(apLoadGameBuffer));
    bFlag150 = 0;
}

struct NiAVObject;

struct ObjHelper
{
    TESForm* FUN_00621a90();
};


struct FUN_009b4bf0_shell
{
    void DispatchReferenceSourceFiles(ObjHelper* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};

// If a1 is set and its object resolves, gets the reference and its source file list, then calls virtual slot 203 with them.
// @fnv 0x009b4bf0
void FUN_009b4bf0_shell::DispatchReferenceSourceFiles(ObjHelper* pObjHelper, void* a2, void* a3, void* a4, void* a5,
                                                      void* a6, void* a7)
{
    if (pObjHelper)
    {
        if (((void *)(reinterpret_cast<::FUN_00810660_Class *>((pObjHelper))->FUN_00810660())))
        {
            TESObjectREFR* pRef8;
            BSSimpleList<TESFile*>* m_kSourceFiles;
            int nCount2;
            pRef8 = ::FUN_0056f930((NiAVObject*)((void *)(reinterpret_cast<::FUN_00810660_Class *>((pObjHelper))->FUN_00810660())));
            m_kSourceFiles = ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((intptr_t)(pObjHelper->FUN_00621a90()))));
            nCount2 = -1;
            ((void(*)(void*, TESObjectREFR*, void**, void**, BSSimpleList<TESFile*>*, int, int))(
                (*(void***)this)[203]))(this, pRef8, &a2, &a5, m_kSourceFiles, nCount2, 0x24);
        }
    }
}

struct S9b46c0
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
    virtual void* GetLight();
    void SetLightEnabled();
};
// Enables or disables the light returned by GetLight based on whether flag 0x200 is set.
// @fnv 0x009b46c0
void S9b46c0::SetLightEnabled()
{
    reinterpret_cast<::fnv_005726e0::FUN_005726e0_shell *>(this)->FUN_005726e0((::fnv_005726e0::NiAVObject *)(void *)(GetLight()), !reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(0x200));
}

struct Base0
{
    virtual void vf0();
    char pad0[0x14];
};

struct Base1
{
    virtual void vf1();
};

struct FUN_009bbef0 : public Base0, public Base1
{
    FUN_009bbef0(void*, void*, void*, NiPoint3, float, float);
    ~FUN_009bbef0();
    char pad[0x150 - 0x1c];
};

struct FUN_009b4020 : public FUN_009bbef0
{
    bool bFlag150;

    virtual void vf0();
    virtual void vf1();

    FUN_009b4020(void* a1, void* a2, void* a3, NiPoint3 a4, float a5, float a6);
};

// Constructs the base object, clears bFlag150, and calls FUN_004f15a0 with 0x3e.
// @fnv 0x009b4020
FUN_009b4020::FUN_009b4020(void* a1, void* a2, void* a3, NiPoint3 aPoint, float a5, float a6)
    : FUN_009bbef0(a1, a2, a3, aPoint, a5, a6)
{
    bFlag150 = false;
    reinterpret_cast<::FUN_004f15a0_shell *>((((S_004f15a0*)this)))->FUN_004f15a0(0x3e);
}

struct hkpRigidBody;
struct hkVector4;
struct bhkCollisionObject
{
    static bhkCollisionObject* __cdecl GetFromRigidBody(const hkpRigidBody*);
public:
    static ::bhkCollisionObject *GetFromNiAVObject(::NiAVObject *);
};
struct ArrSI
{
};
struct FUN_00624020_Class
{
    FUN_00624020_Class* GetLastNode();
};
struct GPCdBody
{
};
struct NiColor
{
    NiColor& operator*=(float);
};
struct GPContact
{
    FUN_00624020_Class* pBodyA;
    FUN_00624020_Class* pBodyB;
    int pad08, pad0c;
    GPCdBody* pPoint;
    int pad14, pad18, pad1c;
    int iFlag;
};
struct GPRefVt
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r040();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void r114();
    virtual void r115();
    virtual void r116();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual void r125();
    virtual void r126();
    virtual void r127();
    virtual void r128();
    virtual void r129();
    virtual void r130();
    virtual void r131();
    virtual void r132();
    virtual void r133();
    virtual void r134();
    virtual void r135();
    virtual void r136();
    virtual bool Unk_89b();
};
struct GPShell
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void HandleHit(TESObjectREFR*, NiPoint3*, NiPoint3*, int, int, int);
    void HandleContactHit(GPContact* apContact);
};

struct FUN_009b40d0_owner
{
    bool CheckC();
};

class FUN_009b40d0_cls : public Projectile
{
  public:
    void InitProjectileFlags();
};

// Sets projectile flags based on the 0x400 test and owner cell checks, then calls FinishSetup.
// @fnv 0x009b40d0
void FUN_009b40d0_cls::InitProjectileFlags()
{
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(4, true);
    if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(0x400))
    {
        reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(2, true);
        reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x100, false);
    }
    else
    {
        reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x100, true);
    }

    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x2000,
                (reinterpret_cast<::BGSProjectile *>((((::FUN_009b40d0_owner *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fd360() && !reinterpret_cast<::BGSProjectile *>((((::FUN_009b40d0_owner *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetHasExplosionAltTrigger() && !((::FUN_009b40d0_owner *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))->CheckC()) ? true : false);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x8000, true);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x40000, true);
    reinterpret_cast<::fnv_009bda10::ProjectileRuntime *>(this)->FUN_009bda10();
}

struct Vec3
{
    float x, y, z;
public:
    Vec3();
};
// Resolves the reference behind each contact body, picks the hit target and position/normal, calls HandleHit, and flags the contact when both bodies are present.
// @fnv 0x009b4950
void GPShell::HandleContactHit(GPContact* apContact)
{
    void* pCollA2 = FUN_004b59f0(apContact->pBodyA->GetLastNode());
    bhkCollisionObject* pbhkA8 = pCollA2 ? bhkCollisionObject::GetFromRigidBody((const hkpRigidBody*)pCollA2) : 0;
    NiAVObject* pNiA2 = pbhkA8 ? ((::NiAVObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pbhkA8)))->GetName())) : 0;
    TESObjectREFR* pRefA_ = pNiA2 ? ::FUN_0056f930(pNiA2) : 0;
    void* pCollB3 = FUN_004b59f0(apContact->pBodyB->GetLastNode());
    bhkCollisionObject* pbhkB_ = pCollB3 ? bhkCollisionObject::GetFromRigidBody((const hkpRigidBody*)pCollB3) : 0;
    NiAVObject* pNiB = pbhkB_ ? ((::NiAVObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pbhkB_)))->GetName())) : 0;
    TESObjectREFR* pRefB = pNiB ? ::FUN_0056f930(pNiB) : 0;
    TESObjectREFR* kPTarget = 0;
    NiPoint3 kPos = NiPoint3::ZERO;
    NiPoint3 _kNormal = NiPoint3::ZERO;
    intptr_t iShapeKey = 0;
    int iBody5 = -1;
    if (pRefA_ && ((GPRefVt*)pRefA_)->Unk_89b())
    {
        kPTarget = pRefB;
        ::SetNiPoint3FromHkVector4(kPos, *(const hkVector4*)((void *)(((::Vec3 *)(void *)(apContact->pPoint)))));
        ::SetNiPoint3FromHkVector4(_kNormal, *(const hkVector4*)((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((intptr_t)(((TESForm*)apContact->pPoint))))));
        reinterpret_cast<::MyPoint439180 *>((((NiColor*)&_kNormal)))->FUN_00439180(-1.0f);
        iShapeKey = (intptr_t)apContact->pBodyB->GetLastNode();
        iBody5 = (int)((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<TESFile*>*)apContact->pBodyB)))->FUN_00726070()));
    }
    else if (pRefB && ((GPRefVt*)pRefB)->Unk_89b())
    {
        kPTarget = pRefA_;
        ::SetNiPoint3FromHkVector4(kPos, *(const hkVector4*)((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((intptr_t)(((TESForm*)apContact->pPoint))))));
        ::SetNiPoint3FromHkVector4(_kNormal, *(const hkVector4*)((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((intptr_t)(((TESForm*)apContact->pPoint))))));
        iShapeKey = (intptr_t)apContact->pBodyA->GetLastNode();
        iBody5 = (int)((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<TESFile*>*)apContact->pBodyA)))->FUN_00726070()));
    }
    HandleHit(kPTarget, &kPos, &_kNormal, iShapeKey, iBody5, 0x24);
    if (kPTarget && kPTarget->IsActor() && pCollA2 && pCollB3)
        apContact->iFlag = 1;
}

struct Ref
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void slot8();

    virtual void slot9();

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

    virtual void slot40();

    virtual void slot41();

    virtual void slot42();

    virtual void slot43();

    virtual void slot44();

    virtual void slot45();

    virtual void slot46();

    virtual void slot47();

    virtual void slot48();

    virtual void slot49();

    virtual void slot50();

    virtual void slot51();

    virtual void slot52();

    virtual void slot53();

    virtual void slot54();

    virtual void slot55();

    virtual void slot56();

    virtual void slot57();

    virtual void slot58();

    virtual void slot59();

    virtual void slot60();

    virtual void slot61();

    virtual void slot62();

    virtual void slot63();

    virtual bool IsActor();

    virtual void slot65();

    virtual void slot66();

    virtual void slot67();

    virtual void slot68();

    virtual void slot69();

    virtual void slot70();

    virtual void slot71();

    virtual void slot72();

    virtual void slot73();

    virtual void slot74();

    virtual void slot75();

    virtual void slot76();

    virtual void slot77();

    virtual void slot78();

    virtual void slot79();

    virtual void slot80();

    virtual void ApplyTime(float, int);

    virtual void slot82();

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void ApplyValue(int);

    virtual int GetValue();

    virtual void slot91();

    virtual void slot92();

    virtual void slot93();

    virtual void slot94();

    virtual void slot95();

    virtual void slot96();

    virtual void slot97();

    virtual void slot98();

    virtual void slot99();

    virtual void slot100();

    virtual void slot101();

    virtual void slot102();

    virtual void slot103();

    virtual void slot104();

    virtual void slot105();

    virtual void slot106();

    virtual void slot107();

    virtual void slot108();

    virtual void slot109();

    virtual void slot110();

    virtual void slot111();

    virtual void slot112();

    virtual void slot113();

    virtual void slot114();

    virtual void slot115();

    virtual void slot116();

    virtual void slot117();

    virtual void slot118();

    virtual void slot119();

    virtual void slot120();

    virtual void slot121();

    virtual void slot122();

    virtual void slot123();

    virtual void slot124();

    virtual void slot125();

    virtual void slot126();

    virtual void slot127();

    virtual void slot128();

    virtual void slot129();

    virtual void slot130();

    virtual void slot131();

    virtual void slot132();

    virtual void slot133();

    virtual void slot134();

    virtual void slot135();

    virtual void slot136();

    virtual void slot137();

    virtual void slot138();

    virtual bool CheckFlag(int);

    virtual void slot140();

    virtual void slot141();

    virtual void slot142();

    virtual void slot143();

    virtual void slot144();

    virtual void slot145();

    virtual void slot146();

    virtual void slot147();

    virtual void slot148();

    virtual void slot149();

    virtual void slot150();

    virtual void slot151();

    virtual void slot152();

    virtual void slot153();

    virtual void slot154();

    virtual void slot155();

    virtual void slot156();

    virtual void slot157();

    virtual void slot158();

    virtual void slot159();

    virtual void slot160();

    virtual void slot161();

    virtual void slot162();

    virtual void slot163();

    virtual void slot164();

    virtual void slot165();

    virtual void slot166();

    virtual void slot167();

    virtual void slot168();

    virtual void slot169();

    virtual void slot170();

    virtual void slot171();

    virtual void slot172();

    virtual void slot173();

    virtual void slot174();

    virtual void slot175();

    virtual void slot176();

    virtual void slot177();

    virtual void slot178();

    virtual void slot179();

    virtual void slot180();

    virtual void slot181();

    virtual void slot182();

    virtual void slot183();

    virtual void slot184();

    virtual void slot185();

    virtual void slot186();

    virtual void slot187();

    virtual void slot188();

    virtual void slot189();

    virtual void slot190();

    virtual void slot191();

    virtual void slot192();

    virtual void slot193();

    virtual void slot194();

    virtual void slot195();

    virtual void slot196();

    virtual void slot197();

    virtual void slot198();

    virtual void slot199();

    virtual void slot200();

    virtual void slot201();

    virtual void slot202();

    virtual void slot203();

    virtual void slot204();

    virtual void slot205();

    virtual void slot206();

    virtual void slot207();

    virtual void slot208();

    virtual void slot209();

    virtual void slot210();

    virtual void slot211();

    virtual void slot212();

    virtual void slot213();

    virtual void slot214();

    virtual void slot215();

    virtual bool IsValidTarget();

    int FUN_0043fcd0();





    int FUN_00517630();


};

struct Hit
{

    Ref* reference;

    Vec3 position;

    Vec3 normal;

    intptr_t itemID;

    int unk20;

    int unk24;

    bool valid28;

    bool valid29;
};

struct HitList
{

    Hit* data;

    HitList* next;

    bool FUN_008256d0();


};

struct ContactHelper
{
    void* reference;

    ContactHelper(void*);

    ~ContactHelper();

};

struct LoadedProjectile
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;

    LoadedProjectile();

    ~LoadedProjectile();
};

struct Resource
{

    int FUN_0043fcd0();

    int FUN_00517630();
};

struct EventStatus
{



    bool FUN_005de080();
};






struct TargetSettings
{
};

extern void __cdecl PlayMysteriousStrangerSound();


struct FormID
{
};

extern LoadedProjectile* __cdecl FUN_009b4d90();


struct ImpactProjectile : Ref
{

    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    int unk030;

    int unk034;

    int unk038;

    int unk03c;

    int unk040;

    int unk044;

    int unk048;

    int unk04c;

    int unk050;

    int unk054;

    int unk058;

    int unk05c;

    int unk060;

    int unk064;

    int unk068;

    int unk06c;

    int unk070;

    int unk074;

    int unk078;

    int unk07c;

    int unk080;

    int unk084;

    HitList list88;

    bool impacted90;

    bool ProcessHits();








};

// Iterates the hit list, applies impact effects to each hit's target, and marks the projectile as impacted.
// @fnv 0x009c1b70
bool ImpactProjectile::ProcessHits()
{

    bool processed = false;

    bool inverse = false;

    if (!impacted90 && !list88.FUN_008256d0())
    {

        HitList* node = &list88;

        while (node && !node->FUN_008256d0())
        {

            Hit* hit = *((::Hit **)(((::Vec3 *)(void *)(node))));

            node = ((::HitList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));

            bool aChanged = false;

            Ref* aTarget = hit->reference;

            if (aTarget && reinterpret_cast<::FUN_00885d70_Class *>(this)->GetFieldDC() > ::_DAT_01012060 && hit->valid29)
            {

                intptr_t oldState = ((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((hit->reference))->FUN_0043fcd0()));

                if (((::Ref *)(::FUN_00874480((char *)this))) && ((::Ref *)(::FUN_00874480((char *)this)))->IsActor() &&

                    aTarget->IsActor() && !reinterpret_cast<::FUN_00437b90_shell *>((((::Ref *)(::FUN_00874480((char *)this)))))->FUN_00437b90())
                {

                    inverse = !aTarget->CheckFlag(0);

                    reinterpret_cast<::fnv_009c30d0::FUN_009c30d0_shell *>(this)->NotifyActorIfEligible((::fnv_009c30d0::Actor *)(aTarget), 0);
                }
                else
                {

                    Ref* form = ((::Ref *)(::FUN_004b5a80((const void *)(hit->itemID))));

                    if (form && reinterpret_cast<::bhkRigidBody_shell *>((form))->FUN_00517630() < 4)

                        aTarget->ApplyValue(GetValue());

                    Ref* attacker = (((::Ref *)(::FUN_00874480((char *)this))) && ((::Ref *)(::FUN_00874480((char *)this)))->IsActor()) ? ((::Ref *)(::FUN_00874480((char *)this))) : 0;

                    float jump = 0.0f;

                    if (attacker && attacker->IsValidTarget() && reinterpret_cast<::FUN_00525430_Class *>(&((*reinterpret_cast<::TargetSettings *>(&::g_011f2250))))->FUN_00525430() && ((::Ref *)(reinterpret_cast<::FUN_00476c90_Class *>(this)->FUN_00476c90())))

                        jump = (float)reinterpret_cast<::FUN_00645c20_Class *>((((::Ref *)(reinterpret_cast<::FUN_00476c90_Class *>(this)->FUN_00476c90()))))->GetShortAtOffset1C0();

                    float delay = reinterpret_cast<::FUN_00885d70_Class *>(this)->GetFieldDC() + jump;

                    if (aTarget->IsActor())
                    {

                        Ref* actor = aTarget;
                        ContactHelper helper(new LoadedProjectile());

                        ::fnv_009b5650::InitFromObjects((::fnv_009b5650::BooleanFloatQuery *)(::Ref *)(((::Ref *)(::FUN_00559450((int *)&(helper))))), (void *)(0), actor, (void *)(0), this);

                        inverse = !actor->CheckFlag(0);

                        reinterpret_cast<::fnv_0089a760::HActor *>((actor))->FUN_0089a760((::fnv_0089a760::HHit *)(void *)(((::Ref *)(::FUN_00559450((int *)&(helper))))), 0);
                    }
                    else
                    {

                        hit->reference->ApplyTime(delay, 0);
                    }

                    if (reinterpret_cast<::FUN_00477ba0_shell *>((aTarget))->FUN_00477ba0() && ((::Ref *)(::FUN_00874480((char *)this))) == (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)))

                        reinterpret_cast<::fnv_00963eb0::PlayerView *>(((*reinterpret_cast<::Ref * *>(&::_g_thePlayer))))->SetEffectValue((void *)(10), DAT_0102918c, (::fnv_00963eb0::EffectSource *)(0));
                }

                if (oldState != ((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((aTarget))->FUN_0043fcd0())))
                    aChanged = true;
            }

            if (!aTarget || !(reinterpret_cast<FormFields*>((aTarget))->m_uiFormFlags & 0x20))
            {

                if (!reinterpret_cast<::BGSProjectile *>((((::EventStatus *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fd360() || reinterpret_cast<::BGSProjectile *>((((::EventStatus *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetHasExplosionAltTrigger() || ((::EventStatus *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))->FUN_005de080())
                {

                    if (!aChanged)
                    {

                        if ((*reinterpret_cast<::Ref * *>(&::DAT_011f21e8)) && (*reinterpret_cast<::Ref * *>(&::DAT_011f21e8)) == ((::Ref *)(::FUN_00874480((char *)this))) && aTarget && aTarget->IsActor())

                            PlayMysteriousStrangerSound();

                        if ((*reinterpret_cast<::Ref * *>(&::DAT_011f21ec)) && (*reinterpret_cast<::Ref * *>(&::DAT_011f21ec)) == ((::Ref *)(::FUN_00874480((char *)this))) && aTarget && aTarget->IsActor() &&
                            aTarget->CheckFlag(0) && inverse)

                            PlayMysteriousStrangerSound();

                        Ref* form = hit->itemID ? ((::Ref *)(::FUN_00460140((intptr_t)(((FormID*)hit->itemID))))) : 0;

                        reinterpret_cast<::ProjectileImpact::ImpProjectile *>(this)->ApplyImpact((::ProjectileImpact::ImpTarget *)(aTarget), (::ProjectileImpact::ImpPoint *)(&hit->position), (::ProjectileImpact::ImpPoint *)(&hit->normal), (intptr_t)(form), hit->unk20);

                        reinterpret_cast<::ImpulseSource *>(this)->FUN_009c2e80((*(::NiPoint3 *)&(const ::Vec3 &)(hit->position)), (*(::NiPoint3 *)&(const ::Vec3 &)((*(::Vec3 *)&(reinterpret_cast<::FUN_009b7010_shell *>(this)->FUN_009b7010((*(::NiPoint3 *)(form))))))), {});
                    }
                }
            }

            processed = true;

            if (reinterpret_cast<::FUN_00437b90_shell *>(this)->FUN_00437b90())

                break;
        }

        impacted90 = true;
    }

    return processed;
}

class ActorCause;
class GrenadeProjectile;
class NiLight;
class ThreeByThreeMatrix;
class NiPoint4;
class NiTransform;
class Projectile;
class Projectile__ImpactData;
class ProjectileAuxiliaryData;
class ProjectileSupportData;
class TESObjectWEAP;
class FourComponentNumericValue;

class Projectile__ImpactData
{
  public:
    void* unk00;
    NiPoint3 position;
    NiPoint3 normal;
};
class NiUpdateData
{
  public:
    float time;
    bool controllers, multithreaded, geometry, bounds, unknown;
    NiUpdateData(float, bool, bool);
};
class NiAVObject
{
  public:
    const ThreeByThreeMatrix& FUN_00461130() const;
};
class NiNode : public NiAVObject
{
};
class TESSaveLoadGame
{
  public:
};
NiPoint3 operator*(float, const NiPoint3&);

// @fnv 0x009b4740
bool GrenadeProjectile::FUN_009b4740()
{
    if (!m_kProjectileImpactList.IsEmpty())
    {
        NiNode* node1 = GetNiNode();
        Projectile__ImpactData* impact = ((::Projectile__ImpactData *)(((::Vec3 *)(void *)&(m_kProjectileImpactList))));
        if (!reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
        {
            ::FUN_00c69f50((::S_00c69f50_Obj *)(node1), true, false);
            reinterpret_cast<::FUN_00440460_S *>((node1))->FUN_00440460((const ::V3 *)&(const ::NiPoint3 &)(impact->position + impact->normal * reinterpret_cast<::FUN_0087ce50_cls *>((node1))->GetHeadTail()));
            NiUpdateData update0(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((node1))->FUN_00a59c60((std::intptr_t)&(update0));
            NiPoint3 velocity6 = NiPoint3::ZERO;
            NiPoint3 forward1;
            reinterpret_cast<::FUN_00439f50_class *>((void *)&(node1->FUN_00461130()))->FUN_00439f50(1, (::NiPoint3 *)&(forward1));
            reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(forward1))->FUN_00439180(-1.0f);
            ::FUN_00525340((float *)(::NiPoint3 *)(&forward1));
            ::FUN_00525340((float *)(::NiPoint3 *)(&impact->normal));
            float dot0 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(impact->normal))->DotProduct((void *)&(forward1));
            NiPoint3 deflection = 2.0f * (dot0 * impact->normal - forward1);
            velocity6 = forward1 + deflection;
            reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(velocity6))->FUN_00439180(::GetFloatAtOffset68((const char *)(((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase())))));
            if (reinterpret_cast<::FUN_006d2c20_Class *>((((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))))->GetFloatAtOffsetB0() > 0.0)
                reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(velocity6))->FUN_00439180(reinterpret_cast<::FUN_006d2c20_Class *>((((::BGSProjectile *)(reinterpret_cast<::Actor *>((void *)this)->GetActorBase()))))->GetFloatAtOffsetB0());
            ::FUN_0062b8d0(node1, (const void *)&(velocity6), true);
        }
    }
    return true;
}

struct S_00561240
{
};

struct S_00627920
{
    __m128 unk00;
    void FUN_00627920(S_00561240* param);
};

// @fnv 0x00627920
void S_00627920::FUN_00627920(S_00561240* param)
{
    __m128 tmp;
    unk00 = _mm_mul_ps(*((::__m128 *)(reinterpret_cast<::S00561240_Vector *>((param))->FUN_00561240((::S00561240_Vector *)(::__m128 *)(&tmp)))), unk00);
}


class NiColorA9B4
{
  public:
    NiColorA9B4();
    __m128 m_vComponents;
};

class GameModeState9B4
{
  public:
};

class ActorValueOwner9B4
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual int GetActorValue(int iAV);
};

class PlayerCharacter9B4
{
  public:
    unsigned int unk00;
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
    ActorValueOwner9B4 m_kAVOwner;
};

class NiAVObject9B4
{
  public:
};

class NiNode9B4
{
  public:
};

class TESObjectREFR9B4
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual bool IsActor();
};

class HighProcess9B4
{
  public:
    bool IsReady();
};


class Actor9B4
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual void va0c8();
    virtual void va0cc();
    virtual void va0d0();
    virtual void va0d4();
    virtual void va0d8();
    virtual void va0dc();
    virtual void va0e0();
    virtual void va0e4();
    virtual void va0e8();
    virtual void va0ec();
    virtual void va0f0();
    virtual void va0f4();
    virtual void va0f8();
    virtual void va0fc();
    virtual void va100();
    virtual void va104();
    virtual void va108();
    virtual void va10c();
    virtual void va110();
    virtual void va114();
    virtual void va118();
    virtual void va11c();
    virtual void va120();
    virtual void va124();
    virtual void va128();
    virtual void va12c();
    virtual void va130();
    virtual void va134();
    virtual void va138();
    virtual void va13c();
    virtual void va140();
    virtual void va144();
    virtual void va148();
    virtual void va14c();
    virtual void va150();
    virtual void va154();
    virtual void va158();
    virtual void va15c();
    virtual void va160();
    virtual void va164();
    virtual void va168();
    virtual void va16c();
    virtual void va170();
    virtual void va174();
    virtual void va178();
    virtual void va17c();
    virtual void va180();
    virtual void va184();
    virtual void va188();
    virtual void va18c();
    virtual void va190();
    virtual void va194();
    virtual void va198();
    virtual void va19c();
    virtual void va1a0();
    virtual void va1a4();
    virtual void va1a8();
    virtual void va1ac();
    virtual void va1b0();
    virtual void va1b4();
    virtual void va1b8();
    virtual void va1bc();
    virtual void va1c0();
    virtual void va1c4();
    virtual void va1c8();
    virtual void va1cc();
    virtual void* Get3D();
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
    HighProcess9B4 m_kProcess;
    unsigned int unk8c;
    bool m_bFiring;

    bool FUN_009b4460(TESObjectREFR9B4* pkTarget, intptr_t a2, intptr_t a3, intptr_t a4, int a5, int a6);
};

// hkVector4::mul4(const hkVector4&): component-wise multiply in place.

struct hkVector4Mul
{
    __m128 m_vComponents;
    void FUN_009b4670(const hkVector4Mul& a);
};
// @fnv 0x009b4460
bool Actor9B4::FUN_009b4460(TESObjectREFR9B4* pkTarget, intptr_t a2, intptr_t a3, intptr_t a4, int a5, int a6)
{
    if (((int)(reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode)) == 4)
    {
        NiNode9B4* pkNode = ((::NiNode9B4 *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(void *)(Get3D()))));
        if (pkNode)
        {
            NiAVObject9B4* pkObject = ((::NiAVObject9B4 *)(::fnv_006fa820::FUN_006fa820((const char *)(pkNode))));
            if (pkObject)
            {
                int iFlags = reinterpret_cast<::bhkRigidBody_shell *>((pkObject))->FUN_00517630();
                if (((bool)(::FUN_00c8cce0(&iFlags))))
                {
                    NiColorA9B4 kColor;
                    float fAlpha = ::DAT_010177e8;
                    fAlpha = (100 - (*reinterpret_cast<::PlayerCharacter9B4 * *>(&::_g_thePlayer))->m_kAVOwner.GetActorValue(0x23)) / 100.0 * fAlpha;
                    fAlpha = fAlpha + (double)0.1f;
                    reinterpret_cast<::bhkUnaryAction *>(&(kColor))->Set(fAlpha, fAlpha, fAlpha, 0.0f);
                    reinterpret_cast<::hkVector4Mul *>(&(kColor))->FUN_009b4670((*(const ::hkVector4Mul *)(((void *)&(::fnv_00560d80::FUN_00560d80((void *)(pkObject)))))));
                    reinterpret_cast<::S *>((pkObject))->FUN_00561690((std::intptr_t)(&kColor));
                }
            }
        }
    }
    if (m_kProcess.IsReady() && ::fnv_009c2c80::CanProjectileHit((::fnv_009c2c80::RefObj *)(pkTarget), (::fnv_009c2c80::CdBody *)(a4), (intptr_t)(this), (::fnv_009c2c80::ProjData *)(void *)(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))) &&
        reinterpret_cast<::ProjectileHit *>(this)->ProcessHit((::Obj *)(pkTarget), (*(const ::Vec *)(a2)), (*(const ::Vec *)(a3)), (::Buffer *)(a4), a5, a6))
    {
        if (pkTarget && pkTarget->IsActor())
        {
            ::FUN_0062b8d0(Get3D(), (*reinterpret_cast<const float (*)[3]>((void *)&::NiPoint3::ZERO)), 1);
        }
        else if (reinterpret_cast<::FUN_00885bd0_St *>(this)->FUN_00885bd0() == 0.0)
        {
            reinterpret_cast<::GrenadeProjectile *>(this)->FUN_009b4740();
            m_bFiring = true;
        }
        return true;
    }
    return false;
}
// @fnv 0x009b4670
void hkVector4Mul::FUN_009b4670(const hkVector4Mul& a)
{
    m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
}
#include "generated/data/fallout/ai/combat/grenadeprojectile.inc"
#include "generated/data/fallout/ai/combat/grenadeprojectile_decl_variant.inc"
#include "generated/data/fallout/ai/combat/grenadeprojectile_o2_variant_od_oy_noo2_variant.inc"
