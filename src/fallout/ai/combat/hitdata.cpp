
// src/fallout/ai/combat/hitdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/hitdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/havok_array_view.h"
#include <cstdint>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_0046e8c0_class.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_0051f4d0_class.h"
#include "fnv/decl/FUN_005e50f0_Obj.h"
#include "fnv/decl/FUN_005e5190_Class.h"
#include "fnv/decl/FUN_00645c20_Class.h"
#include "fnv/decl/FUN_008b4360_Class.h"
#include "fnv/decl/FUN_008b4cd0_class.h"
#include "fnv/decl/FUN_008b4cf0_class.h"
#include "fnv/decl/FUN_008bc700_shell.h"
#include "fnv/decl/SightActor.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_009b5000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FNVEffectOwner.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_005e5130_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00822650_shell.h"
#include "fnv/decl/FUN_008a50f0_class.h"
#include "fnv/decl/FUN_008b3ef0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009c3ee0_shell.h"
#include "fnv/decl/Hld621210.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Obj5e5300.h"
#include "fnv/decl/ShapeCaster.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_008a50d0__bhkCharacterController.h"
#include "fnv/decl/fnv_008aff80__ActorStub.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_00626000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00c80000.h"
#include <xmmintrin.h>
struct FUN_009b7040_shell
{
    float GetField168();
    unsigned int pad00[0x5a];
    float unk168;
};

// @fnv 0x009b7040
float FUN_009b7040_shell::GetField168()
{
    return this->unk168;
}

struct FUN_009b73b0_shell
{
    char GetByteAtOffset() const;
    char pad00[0x1c8];
    char unk1c8;
};

// @fnv 0x009b73b0
char FUN_009b73b0_shell::GetByteAtOffset() const
{
    return *(char*)&this->unk1c8;
}

struct FUN_009b7840_shell
{
    void RaiseMaxValue(float a);
    unsigned int pad00[0x17];
    float unk5c;
};

// If a exceeds the float at offset 0x5c, stores a there, keeping the larger of the two.
// @fnv 0x009b7840
void FUN_009b7840_shell::RaiseMaxValue(float afValue)
{
    if (afValue > this->unk5c)
    {
        this->unk5c = afValue;
    }
}

// Returns true for the index values 0, 1, 2, 16, 17, 20 and 21, and false for any other value.
// @fnv 0x0066de30
bool FUN_0066de30(intptr_t a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 16:
    case 17:
    case 20:
    case 21:
        return true;
    default:
        return false;
    }
}


struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};


struct BooleanFloatQuery
{
    void* m_pAggressor;
    void* pTarget;
    void* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
    void FUN_009b4dc0();
};

// @fnv 0x009b4dc0
void BooleanFloatQuery::FUN_009b4dc0()
{
    m_pAggressor = 0;
    pTarget = 0;
    m_pSourceReference = 0;
    m_uiHitLocation = 0x4d;
    m_uiHitFlags = 0xffffffff;
    m_fDamage = 0.0f;
    m_fArmorDamage = 0.0f;
    m_fHealthDamage = 0.0f;
    m_fLimbDamage = 0.0f;
    m_fFatigueDamage = 0.0f;
    m_fSneakAttackMultiplier = 0.0f;
    m_fCriticalHitMultiplier = 0.0f;
    vOffset1 = ::NiPoint3::ZERO;
    vOffset2 = ::NiPoint3::ZERO;
    pWeapon = 0;
    m_fWeaponDamage = 0.0f;
    m_pHitDataObjectAtOffset50 = 0;
    m_pHitDataObjectAtOffset54 = 0;
    uiFlags = 0;
    BackgroundTask = 0;
    m_fHitValueAtOffset5C = 0.0f;
}

struct GlobalObject_00869f00
{
};

extern int DAT_0108f9e8;

struct FUN_009b7970_shell
{
    void InitializeAndClear();
};

// @fnv 0x009b7970
void FUN_009b7970_shell::InitializeAndClear()
{
    *reinterpret_cast<intptr_t*>(this) = (intptr_t)&DAT_0108f9e8;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}

struct FUN_009b7010_shell
{
    NiPoint3& FUN_009b7010(NiPoint3& akDest);
};
// Copies the NiPoint3 stored at offset 0x104 of this object into akDest and returns it.
// @fnv 0x009b7010
NiPoint3& FUN_009b7010_shell::FUN_009b7010(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x104);
    return akDest;
}

struct AX
{
};
struct FUN_009b7940_shell
{
    int* vtable;
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    FUN_009b7940_shell* Initialize();
};
// Sets the vtable to DAT_0108f9e8, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x009b7940
FUN_009b7940_shell* FUN_009b7940_shell::Initialize()
{
    vtable = &DAT_0108f9e8;
    FUN_006b3eb0(0, 0);
    return this;
}

template <typename T, unsigned int N> class BSSimpleArray
{
  public:
    void* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    unsigned int uiPad;
    unsigned int Add(T&);
};
struct BGSBodyPart
{
};
struct WeightedResultList
{
    BSSimpleArray<void*, 1024> kResults;
    BSSimpleArray<void*, 1024> kWeights;
    int m_iTotalWeight;
    void FUN_009b7990(BGSBodyPart* aResult, unsigned int aiWeight);
};
struct FUN_009ca4c0_shell
{
    void FreeStoredPointer();
    unsigned int pad00[0x5];
    void* unk14;
};
// If the pointer at offset 0x14 is set, deallocates it and clears that field.
// @fnv 0x009ca4c0
void FUN_009ca4c0_shell::FreeStoredPointer()
{
    if (this->unk14)
    {
        void* p = this->unk14;
        ::FUN_00401030(p);
        this->unk14 = 0;
    }
}

struct BaseS
{
    char data[12];
    BaseS();
};
struct FUN_009b4d90
{
    char _pad[56];
    BaseS m1;
    BaseS m2;
    FUN_009b4d90();
};
// Constructs the object by calling FUN_009b4dc0 on this.
// @fnv 0x009b4d90
FUN_009b4d90::FUN_009b4d90()
{
    ((BooleanFloatQuery*)this)->FUN_009b4dc0();
}

struct HitDataEx : BooleanFloatQuery
{
    void FUN_009b4ec0(const BooleanFloatQuery& src);
};

// @fnv 0x009b4ec0
void HitDataEx::FUN_009b4ec0(const BooleanFloatQuery& src)
{
    m_pAggressor = src.m_pAggressor;
    pTarget = src.pTarget;
    m_pSourceReference = src.m_pSourceReference;
    m_uiHitLocation = src.m_uiHitLocation;
    m_uiHitFlags = src.m_uiHitFlags;
    m_fDamage = src.m_fDamage;
    m_fArmorDamage = src.m_fArmorDamage;
    m_fHealthDamage = src.m_fHealthDamage;
    m_fLimbDamage = src.m_fLimbDamage;
    m_fFatigueDamage = src.m_fFatigueDamage;
    m_fSneakAttackMultiplier = src.m_fSneakAttackMultiplier;
    m_fCriticalHitMultiplier = src.m_fCriticalHitMultiplier;
    vOffset1 = src.vOffset1;
    vOffset2 = src.vOffset2;
    pWeapon = src.pWeapon;
    m_fWeaponDamage = src.m_fWeaponDamage;
    m_pHitDataObjectAtOffset50 = src.m_pHitDataObjectAtOffset50;
    m_pHitDataObjectAtOffset54 = src.m_pHitDataObjectAtOffset54;
    uiFlags = src.uiFlags;
    m_fHitValueAtOffset5C = src.m_fHitValueAtOffset5C;
}

struct SpawnObj
{
    unsigned int unk00;
    unsigned char flag4;
};

struct SpawnLocal
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float unk14;
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
    SpawnLocal();
    void FUN_00407e00(unsigned int a, bool b);
};


// @fnv 0x009b4fe0
float __cdecl FUN_009b4fe0(SpawnObj* pSpawnObj)
{
    if (pSpawnObj == 0)
    {
        return 0.0f;
    }
    SpawnLocal L;
    L.FUN_00407e00(0x800, true);
    L.FUN_00407e00(0x1000, true);
    unsigned char saved = pSpawnObj->flag4;
    pSpawnObj->flag4 = 1;
    ::SetContextInfo((::n9b::Ctx *)(::SpawnLocal *)(&L), (::n9b::Info *)(pSpawnObj));
    pSpawnObj->flag4 = saved;
    return L.unk14;
}

struct SpawnedSub
{
    unsigned int unk00[4];
    SpawnedSub();
};

struct SpawnedBase
{
    SpawnedBase();
    ~SpawnedBase()
    {}
};

struct FUN_009b7870 : SpawnedBase
{
    unsigned int unk00[4];
    SpawnedSub m10;
    unsigned int m20;
    FUN_009b7870();
};

// Initializes the object by setting m20 to 0.
// @fnv 0x009b7870
FUN_009b7870::FUN_009b7870()
{
    m20 = 0;
}

class Actor;

struct FUN_009b7060_weapon
{
};

struct FUN_009b7060_actor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual bool v004();
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
    virtual bool v064();
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
    virtual bool v139(int aiFlag);
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
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool v216();
    int FUN_008a0d10(int a1, Actor* apActor, char* apDetected, int a4, int a5, int a6, int a7);
};

struct FUN_009b7060_shell
{
    Actor* pSource;
    Actor* pTarget;
    char pad[0x14 - 0x08];
    float afDamageAmount;
    char padCur[0x30 - 0x18];
    FUN_009b7060_weapon* pWeapon;
    char kad[0x50 - 0x34];
    unsigned int uiValue;
    int iValue;
    bool FUN_0058cba0(int aeFlag);
    void FUN_00407e00(int aeFlag, bool abSet);
    void ApplyCriticalHit();
};

// @fnv 0x009b7060
void FUN_009b7060_shell::ApplyCriticalHit()
{
    if (pTarget && ((FUN_009b7060_actor*)((char*)pTarget + 0x94))->v004())
        return;
    if (FUN_0058cba0(0x800))
        return;

    float fLimbDamage4 = 0.0f;
    float fCritChance =
        ::GetWeaponDPS((::ActorValueOwner646 *)(void *)(pSource ? (char*)pSource + 0xa4 : 0), (::TESObjectWEAP646 *)(void *)(pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278));
    ApplyPerkModifiers(1, pSource, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278, pTarget, &fCritChance);
    ApplyPerkModifiers(0x24, pTarget, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278, pSource, &fCritChance);
    if (iValue)
        fCritChance += FUN_00403e20((::Setting *)&(*reinterpret_cast<int *>(&::originalRuntimeFloatSetting553)));
    fCritChance *= 10.0;

    if (pSource && ((FUN_009b7060_actor*)pSource)->v216() && pTarget && ((FUN_009b7060_actor*)pTarget)->v064() &&
        !((FUN_009b7060_actor*)pTarget)->v139(0) && reinterpret_cast<::Actor *>((((FUN_009b7060_actor*)pSource)))->IsSneaking() &&
        !reinterpret_cast<::FUN_008bc700_shell *>((((FUN_009b7060_actor*)pTarget)))->FUN_008bc700(pSource))
    {
        char cDetected = reinterpret_cast<::SightActor *>((((FUN_009b7060_actor*)pTarget)))->FUN_0088b880(0, (::SightActor *)(pSource), 1, (int *)(0), 0);
        int iDetection = ((FUN_009b7060_actor*)pTarget)->FUN_008a0d10(0, pSource, &cDetected, 0, 0, 0, 0);
        if (iDetection <= 0)
        {
            fCritChance *= FUN_00403e20((::Setting *)&(*reinterpret_cast<int *>(&::originalRuntimeFloatSetting747)));
            FUN_00407e00(0x400, true);
        }
    }

    int iNewRoll = ::DialogueRandom() % 1000;
    if (iNewRoll < (int)fCritChance)
    {
        FUN_00407e00(4, true);
        FUN_009b7060_weapon* pCritWeapon = pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278;
        if (pCritWeapon)
        {
            fLimbDamage4 =
                pWeapon ? (double)reinterpret_cast<::FUN_00645c20_Class *>((pWeapon))->GetShortAtOffset1C0() : afDamageAmount * FUN_00403e20((::Setting *)&(*reinterpret_cast<int *>(&::originalRuntimeFloatSetting752)));
            ApplyPerkModifiers(2, pSource, pCritWeapon, pTarget, &fLimbDamage4);
            if (fLimbDamage4 > ::_DAT_01012060)
                afDamageAmount += fLimbDamage4;
            FUN_00407e00(8, ((bool)(reinterpret_cast<::FUN_009b73b0_shell *>((pCritWeapon))->GetByteAtOffset())));
            uiValue = reinterpret_cast<::FUN_0051f4d0_class *>((pCritWeapon))->GetField1CC();
        }
    }
}

namespace fnv_009b73d0 {
struct Item;
struct Process;
struct ActorBase;
struct Parts;
struct Part;
struct ValueInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float Value(int);
};
struct StateInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Test();
};
struct ActorCore
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
    virtual bool Ready();
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
    virtual bool IsPlayer();
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
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    StateInterface state;
    int unk98;
    int unk9c;
    int unka0;
};
class Actor : public ActorCore, public ValueInterface
{
};
struct Process
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
    virtual Item* GetItem();
};
struct ActorBase
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
    virtual Parts* GetParts();
};
struct Item
{
};
struct Parts
{
};
struct Part
{
};
struct Command
{
    int unk00;
    int unk04;
    unsigned char count;
};
struct Weapon
{
};
struct Setting
{
};
struct Hit
{
    Actor* source;
    Actor* target;
    void* ref;
    int skill;
    int limb;
    float health;
    float total;
    float fatigue;
    float limbDamage;
    float blocked;
    float armor;
    float weaponDamage;
    Weapon* weapon;
    float weaponHealth;
    NiPoint3 offset1;
    NiPoint3 offset2;
    void* critical;
    Command* command;
    unsigned flags;
    float bonus;
    int refs;
    bool GetFlag(unsigned);
    void SetFlag(unsigned, bool);
    void ApplyDamageEffects();
};
// @fnv 0x009b73d0
void Hit::ApplyDamageEffects()
{
    if (!target || !target->Ready())
        return;
    if (target->state.Test())
        return;
    if (bonus > 0.0)
    {
        if (bonus >= 1.0 && GetFlag(0x400))
        {
            if (!weapon || ::FUN_006450c0((::TESObjectWEAP *)(weapon)))
                bonus *= *((float *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::fnv_009b73d0::Setting *>(&::originalRuntimeFloatSetting748))))));
            else
                bonus *= *((float *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::fnv_009b73d0::Setting *>(&::g_011cf794))))));
        }
        health *= bonus;
        if (source && !source->IsPlayer() && skill == 45)
            fatigue *= bonus;
        total *= bonus;
    }
    float count = 1.0f;
    if (command && command->count > 1)
        count = command->count;
    int current = 0;
    bool guaranteed = false;
    bool criticalFlagX = false;
    if (limb == 14)
    {
        Item* item_ = ((::fnv_009b73d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->GetItem();
        Parts* flags_ = item_ ? ((::fnv_009b73d0::Parts *)(reinterpret_cast<::Twin_0044ddc0 *>((item_))->GetName())) : 0;
        if (flags_)
        {
            float itemHealth4 = reinterpret_cast<::FUN_004bcdb0_shell *>((item_))->FUN_004bcdb0(0);
            if (itemHealth4 - limbDamage <= 0.0)
            {
                if (target->IsPlayer() || reinterpret_cast<::FUN_0046e8c0_class *>((flags_))->FUN_0046e8c0())
                    SetFlag(0x200, true);
                else
                    SetFlag(0x100, true);
            }
        }
    }
    else if (limb != -1)
    {
        Parts* partsX = ((::fnv_009b73d0::ActorBase *)(reinterpret_cast<::Actor *>((target))->GetActorBase()))->GetParts();
        if (partsX)
        {
            Part* part = ((::fnv_009b73d0::Part *)(reinterpret_cast<::FUN_005e50f0_Obj *>((partsX))->GetValueByIndex(limb)));
            if (part && reinterpret_cast<::FUN_008b4360_Class *>((part))->FUN_008b4360())
            {
                current = reinterpret_cast<::FUN_008b4cf0_class *>((part))->GetByte65();
                criticalFlagX = reinterpret_cast<::FUN_008b4cd0_class *>((part))->IsFlag40Set();
                guaranteed = criticalFlagX && current >= 100;
                int index7 = ((signed char)(reinterpret_cast<::FUN_005e5190_Class *>((part))->GetByte63()));
                float valueVal = target->Value(index7);
                if (valueVal > 0.0 && valueVal - limbDamage <= 0.0)
                    SetFlag(0x80, true);
            }
        }
    }
    float chance9 = target->Value(16);
    if (chance9 - health * count <= 0.0)
    {
        SetFlag(0x10, true);
        if (limb != -1)
        {
            bool explodeTmp = false;
            bool dismember8 = guaranteed;
            if (!dismember8)
                ::RollChanceOutcome(static_cast<ValueInterface*>(target), (::ChanceModifier *)(::fnv_009b73d0::Weapon *)(weapon ? weapon : (skill == 45 ? (*reinterpret_cast<::fnv_009b73d0::Weapon * *>(&::DAT_011ca278)) : 0)),
                        current, 0, 0, criticalFlagX, (unsigned char *)(bool *)(&explodeTmp), (unsigned char *)(bool *)(&dismember8));
            if (explodeTmp)
                SetFlag(0x20, true);
            if (dismember8)
                SetFlag(0x40, true);
        }
    }
}
}  // namespace fnv_009b73d0

struct FUN_00438690
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~FUN_00438690();
public:
    unsigned int FUN_007cb2e0(unsigned int *);
};
// @fnv 0x009b7990
void WeightedResultList::FUN_009b7990(BGSBodyPart* aResult, unsigned int aiWeight)
{
    m_iTotalWeight += aiWeight;
    reinterpret_cast<::FUN_00438690 *>(&(kWeights))->FUN_007cb2e0((unsigned int *)&((void*&)aiWeight));
    reinterpret_cast<::FUN_00438690 *>(&(kResults))->FUN_007cb2e0((unsigned int *)&((void*&)aResult));
}

struct Base_009b78e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Base_009b78e0();
};

struct FUN_009b78e0 : Base_009b78e0
{
    FUN_00438690 m10;
    int m20;
    ~FUN_009b78e0();
};

// @fnv 0x009b78e0
FUN_009b78e0::~FUN_009b78e0()
{}

namespace n9b {
struct Tgt
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual intptr_t v52();
};
struct Mgr
{
};
struct Info
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    char pad[7];
    Tgt* m_iThirdValue;
};
struct Ctx
{
    char pad[0x54];
    Info* m_54;
};
}
bool __cdecl FUN_0066de30(intptr_t v);
// @fnv 0x009b5050
void __cdecl SetContextInfo(n9b::Ctx* ctx, n9b::Info* info)
{
    if (!ctx || !info || !info->m_iThirdValue)
        return;
    ctx->m_54 = info;
    bool flag = FUN_0066de30(info->m_iWordAt00) && info->m_iWordAt04;
    ::InitHitData((::BooleanFloatQuery *)(ctx), (::ActorHit *)((*reinterpret_cast<::n9b::Mgr * *>(&::_g_thePlayer))), (::ActorHit *)(::n9b::Tgt *)(info->m_iThirdValue->v40() ? info->m_iThirdValue : 0), (::RefHit *)(((::n9b::Tgt *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::n9b::Mgr * *>(&::_g_thePlayer))))->GetBaseTexture()))->v52()), flag);
}

class hkVector4_9B6
{
  public:
    hkVector4_9B6();
    __m128 m_vComponents;
};

class Point9B6
{
  public:
    Point9B6();
    Point9B6 operator+(const Point9B6& kPt) const;
    Point9B6 operator-(const Point9B6& kPt) const;
    Point9B6 operator*(float fScalar) const;
    Point9B6 operator-() const;
    Point9B6& operator+=(const Point9B6& kPt);
    Point9B6 UnitizeScaled(float fScaleMultiplier) const;
    float x, y, z;
};

class hkBool9B6
{
  public:
    hkBool9B6();
    char m_cBooleanValue;
};

class Transform9B6
{
  public:
};

class NiAVObject9B6
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiAVObject9B6* GetBone();
};

class Collidable9B6;

class Collision9B6
{
  public:
};

class Entity9B6;

class Hit9B6
{
  public:
    Hit9B6(const Hit9B6& kOther);
    hkVector4_9B6 m_kPathOffset;
    hkVector4_9B6 m_kPlaneNormal;
    float m_fHitFraction;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    Collidable9B6* m_pkCollidable;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};

class HitArray9B6
{
  public:
    Hit9B6& GetAt(int i);
};

class Results9B6
{
  public:
};

class World9B6;

class Query9B6
{
  public:
};

class Middle9B6
{
  public:
};

class SpherePick9B6
{
  public:
    SpherePick9B6();
    hkVector4_9B6 m_kPathOffset;
};

class BodyPart9B6
{
  public:
};

class BodyPartData9B6
{
  public:
};

class Base9B6
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
    virtual BodyPartData9B6* GetBodyPartData();
};

class ActorValueOwner9B6
{
  public:
    virtual void v00();
};

class PartSet9B6
{
  public:
    PartSet9B6();
    ~PartSet9B6();
    bool Contains(BodyPart9B6* pkPart);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

class Ref9B6
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
    virtual NiAVObject9B6* Get3D();
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
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual bool IsCrippled();
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
};

class Actor9B6 : public Ref9B6, public ActorValueOwner9B6
{
};

class Attacker9B6
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
    virtual NiAVObject9B6* Get3D();
    Point9B6 GetEyePosition(int iMode);
};

class Weapon9B6
{
  public:
};

class LinkInfo9B6
{
  public:
    void* m_pvForm;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int m_iPart;
};

class Contact9B6
{
  public:
    int unk00;
    Point9B6 m_kPathOffset;
    Point9B6 m_kPlaneNormal;
    unsigned int unk1c;
    unsigned int unk20;
    int m_iPart;
};

class Event9B6
{
  public:
};

class FloatSetting9B6
{
  public:
};


class Target9B6
{
  public:
    bool HasFlag(int iFlag);
    void FUN_009b6620(Event9B6* pkEvent);
    Attacker9B6* m_pkAttacker;
    Ref9B6* m_pkTarget;
    int unk08;
    int unk0c;
    int m_iPart;
    float m_fBaseChance;
    int unk18;
    int unk1c;
    float m_fChance;
    int unk24;
    int unk28;
    int unk2c;
    Weapon9B6* m_pkWeapon;
    int unk34;
    Point9B6 m_kPathOffset;
    Point9B6 m_kLightVector;
    int unk50;
    LinkInfo9B6* m_pkLink;
};

// @fnv 0x009b6620
void Target9B6::FUN_009b6620(Event9B6* pkEvent)
{
    if (!m_pkTarget || !m_pkTarget->IsActor())
        return;
    Base9B6* pkBase = ((::Base9B6 *)(reinterpret_cast<::Actor *>((m_pkTarget))->GetActorBase()));
    BodyPartData9B6* pkParts = pkBase->GetBodyPartData();
    BodyPart9B6* pkPart = 0;
    bool bSearch = false;
    if (m_pkLink)
    {
        if (m_pkLink->m_iPart != -1)
        {
            if (pkParts)
            {
                pkPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e5130_Class *>((pkParts))->FUN_005e5130(m_pkLink->m_iPart)));
                m_iPart = pkPart ? ((int)(reinterpret_cast<::Obj5e5300 *>((pkPart))->GetByte61())) : 0xe;
            }
        }
        else if (::FUN_0066de30((intptr_t)(m_pkLink->m_pvForm)))
        {
            if (HasFlag(0x800))
                m_iPart = 0;
            else
                bSearch = true;
        }
        else
        {
            m_iPart = 0xe;
        }
    }
    else if (pkEvent)
    {
        bSearch = false;
        Contact9B6* pkContact = ((::Contact9B6 *)(reinterpret_cast<::FUN_009c3ee0_shell *>((pkEvent))->FindItemByKey(m_pkTarget)));
        if (pkContact)
        {
            m_iPart = pkContact->m_iPart;
            pkPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pkParts))->GetValueByIndex(m_iPart)));
            m_kPathOffset = pkContact->m_kPathOffset;
            m_kLightVector = (*(::Point9B6 *)&(reinterpret_cast<::FUN_009b7010_shell *>((pkEvent))->FUN_009b7010(*(::NiPoint3 *)nullptr)));
            reinterpret_cast<::FUN_004a0c10_s *>(&(m_kLightVector))->FUN_004a0c10();
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Point9B6 &)(m_kLightVector))->FUN_0063c8a0((void *)&(const ::Point9B6 &)(-pkContact->m_kPlaneNormal));
            reinterpret_cast<::FUN_004a0c10_s *>(&(m_kLightVector))->FUN_004a0c10();
        }
    }
    else
    {
        bSearch = true;
    }
    if (bSearch)
    {
        Point9B6 kHitPos = m_pkAttacker->GetEyePosition(1);
        Point9B6 kLookPos;
        Point9B6 kLookDir;
        reinterpret_cast<::fnv_008aff80::ActorStub *>((m_pkAttacker))->GetCameraPosAndDir((::fnv_008aff80::Vec3 *)&(kLookPos), (::fnv_008aff80::Vec3 *)&(kLookDir), 0);
        Point9B6 kFrom = kLookPos;
        Point9B6 kRay = kLookDir * 200.0f;
        float fScaleMultiplier = 200.0f;
        bool bFound = false;
        PartSet9B6 kParts;
        Middle9B6* pkMiddle = ((::Middle9B6 *)(reinterpret_cast<::LowProcess *>((m_pkAttacker))->GetTarget()));
        if (pkMiddle)
        {
            Query9B6* pkQuery = ((::Query9B6 *)(::FUN_00626dd0(m_pkAttacker != (*reinterpret_cast<::Attacker9B6 * *>(&::_g_thePlayer)), 1)));
            reinterpret_cast<::FNVEffectOwner *>((pkQuery))->ApplyEffectToTarget(((::World9B6 *)(reinterpret_cast<::FUN_004543c0_cls *>((pkMiddle))->FUN_004543c0())));
            reinterpret_cast<::ShapeCaster *>((pkQuery))->FUN_00626b30((const ::NiPoint3 &)(kFrom), (const ::NiPoint3 &)(kLookDir), fScaleMultiplier);
            Results9B6* pkResults = ((::Results9B6 *)(((::Vec3 *)(void *)(pkQuery))));
            if (reinterpret_cast<::FUN_005609f0_shell *>((void *)(void *)&(const ::hkBool9B6 &)((*(::hkBool9B6 *)(reinterpret_cast<::Hld621210 *>((pkResults))->FUN_00621210({})))))->FUN_005609f0())
            {
                for (int i = 0; i < HavokArraySize((((::HitArray9B6 *)(::FUN_00460140((intptr_t)(pkResults)))))); i++)
                {
                    Hit9B6 kHit(((::HitArray9B6 *)(::FUN_00460140((intptr_t)(pkResults))))->GetAt(i));
                    NiAVObject9B6* pkObject = ((::NiAVObject9B6 *)(::FUN_004b5820((::FormLike *)(kHit.m_pkCollidable))));
                    Ref9B6* pkRef = ((::Ref9B6 *)(::FUN_0056f930((::NiAVObject *)(pkObject))));
                    if (pkRef && pkRef == m_pkTarget)
                    {
                        ::SetNiPoint3FromHkVector4((::NiPoint3 &)(kHitPos), (const ::hkVector4 &)((*(const ::hkVector4_9B6 *)(((::Vec3 *)(void *)&(kHit))))));
                        Entity9B6* pkEntity = ((::Entity9B6 *)(::FUN_004b59f0(kHit.m_pkCollidable)));
                        if (pkEntity)
                        {
                            if (!bFound)
                            {
                                bFound = true;
                                ::SetNiPoint3FromHkVector4((::NiPoint3 &)(m_kPathOffset), (const ::hkVector4 &)((*(const ::hkVector4_9B6 *)(((::Vec3 *)(void *)&(kHit))))));
                                m_kLightVector = kLookDir;
                            }
                            int iIndex = pkObject->GetBone() ? reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(pkObject->GetBone()))
                                                             : reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(((::NiAVObject9B6 *)(reinterpret_cast<::FUN_009611e0_shell *>((pkObject))->FUN_009611e0()))));
                            if (iIndex != -1 && iIndex != 0xe)
                            {
                                BodyPart9B6* pkHitPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pkParts))->GetValueByIndex(iIndex)));
                                if (pkHitPart && !kParts.Contains(pkHitPart))
                                    reinterpret_cast<::WeightedResultList *>(&(kParts))->FUN_009b7990((::BGSBodyPart *)(pkHitPart), ((bool)(::FUN_005dc980((const char *)(pkHitPart)))));
                            }
                        }
                    }
                }
            }
        }
        if (!bFound && m_pkTarget->Get3D() && m_pkAttacker->Get3D())
        {
            Point9B6 kTargetPos = *((const ::Point9B6 *)(((::Vec3 *)(void *)(((::Transform9B6 *)(reinterpret_cast<::FUN_0043d450_Owner *>((m_pkTarget->Get3D()))->FUN_0043d450()))))));
            Point9B6 kAttackerPos = *((const ::Point9B6 *)(((::Vec3 *)(void *)(((::Transform9B6 *)(reinterpret_cast<::FUN_0043d450_Owner *>((m_pkAttacker->Get3D()))->FUN_0043d450()))))));
            m_kPathOffset = kTargetPos + (m_pkAttacker->GetEyePosition(1) - kTargetPos).UnitizeScaled(6.0f);
            m_kLightVector = kTargetPos - kAttackerPos;
            SpherePick9B6 kPick;
            hkVector4_9B6 kTargetCenter;
            ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kTargetCenter), (const ::fnv_004a3e00::NiPoint3 &)(kHitPos));
            reinterpret_cast<::FUN_008a50f0_class *>(&(kPick))->FUN_008a50f0((intptr_t)&(kTargetCenter));
            reinterpret_cast<::fnv_008a50d0::bhkCharacterController *>(&(kPick))->FUN_008a50d0(200.0f);
            Collision9B6* pkCollision = ((::Collision9B6 *)(::FUN_00c806b0(m_pkTarget->Get3D(), &kPick, 0)));
            if (pkCollision)
            {
                bFound = true;
                NiAVObject9B6* pkObject = ((::NiAVObject9B6 *)(::FUN_004b5820((::FormLike *)(::Collidable9B6 *)(((::Collidable9B6 *)(reinterpret_cast<::FUN_0043b560_shell *>((pkCollision))->GetSourceFilesFromObject()))))));
                if (pkObject)
                {
                    int iIndex = pkObject->GetBone() ? reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(pkObject->GetBone()))
                                                     : reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(((::NiAVObject9B6 *)(reinterpret_cast<::FUN_009611e0_shell *>((pkObject))->FUN_009611e0()))));
                    if (iIndex != -1)
                    {
                        BodyPart9B6* pkHitPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pkParts))->GetValueByIndex(iIndex)));
                        if (pkHitPart && !kParts.Contains(pkHitPart))
                            reinterpret_cast<::WeightedResultList *>(&(kParts))->FUN_009b7990((::BGSBodyPart *)(pkHitPart), ((bool)(::FUN_005dc980((const char *)(pkHitPart)))));
                    }
                }
            }
        }
        if (bFound)
        {
            pkPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_00822650_shell *>(&(kParts))->FindFirstItemExceedingRemaining()));
            m_iPart = pkPart ? ((int)(reinterpret_cast<::Obj5e5300 *>((pkPart))->GetByte61())) : -1;
        }
    }
    if (m_iPart == 0xe)
    {
        m_fChance = m_fBaseChance;
        if (m_pkLink)
            m_fChance *= *((float *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::FloatSetting9B6 *>(&::originalRuntimeFloatSetting759))))));
        m_fBaseChance = 0.0f;
        return;
    }
    if (pkPart)
    {
        m_iPart = pkPart ? ((int)(reinterpret_cast<::Obj5e5300 *>((pkPart))->GetByte61())) : -1;
        m_fChance = ::FUN_00647a30((::FUN_00647a30_Obj *)(::ActorValueOwner9B6 *)((Actor9B6*)m_pkTarget), (::FUN_00647a30_Flag *)(pkPart), m_fBaseChance);
        if (m_pkTarget->IsCrippled())
            m_fChance *= *((float *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::FloatSetting9B6 *>(&::originalRuntimeFloatSetting750))))));
        float fBodyPartChance = reinterpret_cast<::TESGrass *>((pkPart))->GetLowestAllowedSlope();
        if (!m_pkWeapon || ::FUN_006450c0((::TESObjectWEAP *)(m_pkWeapon)))
            fBodyPartChance = 1.0f;
        if (m_pkWeapon)
            m_fChance *= reinterpret_cast<::FUN_009b7040_shell *>((m_pkWeapon))->GetField168();
        reinterpret_cast<::FUN_009b7840_shell *>(this)->RaiseMaxValue(fBodyPartChance);
    }
}
