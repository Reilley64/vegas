
// src/fallout/magic/magicballprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicballprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/save_load_game_view.h"
#include "fnv/game_timer.h"
#include "fnv/magic_projectile_fields.h"
#include "fnv/simple_list_node_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/ArrowProjectile.h"
#include "fnv/decl/B5F750Owner.h"
#include "fnv/decl/B9B1320Request.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSOcclusionPlane.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/EffectBase.h"
#include "fnv/decl/FUN_004036b0_Class.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_0042e130_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004610f0_Class.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00484af0_t.h"
#include "fnv/decl/FUN_00484d20_Class.h"
#include "fnv/decl/FUN_00484d40_Host.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004e3cc0_Class.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_004f0180_Class.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_0055f5b0_Class.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_00621b20_Class.h"
#include "fnv/decl/FUN_0080fb30.h"
#include "fnv/decl/FUN_008106b0_Class.h"
#include "fnv/decl/FUN_00810f90_shell.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_00813370_class.h"
#include "fnv/decl/FUN_008133b0_class.h"
#include "fnv/decl/FUN_008133d0_shell.h"
#include "fnv/decl/FUN_0081c470_shell.h"
#include "fnv/decl/FUN_0081e8c0_shell.h"
#include "fnv/decl/FUN_0081e980_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857bd0.h"
#include "fnv/decl/FUN_0085a2e0_Class.h"
#include "fnv/decl/FUN_0085f710_class.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_008d8b80Class.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00906050_Class.h"
#include "fnv/decl/FUN_00931ff0_shell.h"
#include "fnv/decl/FUN_00932070_MobileObject.h"
#include "fnv/decl/FUN_00932490_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009ac9a0_cls.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/FUN_00a59660_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/ImpactOwner.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicEffectCollection.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/MatchContext.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiQuaternion.h"
#include "fnv/decl/P142Caster.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/RotationMatrix.h"
#include "fnv/decl/S_009b13a0_Cls.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/Spectrum4d50.h"
#include "fnv/decl/TESHealthForm.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/VectorSourceB00.h"
#include "fnv/decl/WorkerMobile.h"
#include "fnv/decl/bhkCharacterListener.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00810ff0__Ths810.h"
#include "fnv/decl/fnv_0081de70__FUN_0081de70_cls.h"
#include "fnv/decl/fnv_0081ea40__MagicProjectile.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008ccfb0__xActor.h"
#include "fnv/decl/fnv_0092ed60__FNVCurrent.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009320e0__FUN_009320e0_class.h"
#include "fnv/decl/fnv_00932520__FUN_00932520_shell.h"
#include "fnv/decl/fnv_009ef530__FUN_009ef530_cls.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0049b000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_0062a000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0080f000.h"
#include "fnv/symbols_00935000.h"
#include "fnv/symbols_009ee000.h"
#include "fnv/symbols_00bc2000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00ee8000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_0107a000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include <cstddef>
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/C70CharacterController.h"
#include "fnv/decl/FUN_00407860_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00810510_Class.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_00810590_Class.h"
#include "fnv/decl/FUN_008105c0_Class.h"
#include "fnv/decl/FUN_008105e0_Class.h"
#include "fnv/decl/FUN_00810640_class.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/S005620e0_Object.h"
#include "fnv/decl/S_00c6d7a0_Obj.h"
#include "fnv/decl/fnv_00810610__FUN_00810610_Class.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_0057b000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_008cd000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include <cmath>
struct FUN_00810a80_shell
{
    float GetFloatAtOffset53C();
    char pad00[0x53c];
    float unk53c;
};

// @fnv 0x00810a80
float FUN_00810a80_shell::GetFloatAtOffset53C()
{
    return unk53c;
}


struct FUN_00822a20_shell
{
    void CheckModifierNonZero(float a);
};

// @fnv 0x00822a20
void FUN_00822a20_shell::CheckModifierNonZero(float a)
{
    if (a != ::_DAT_01012060)
    {
    }
}

struct MagicBallProjectile
{
    void* FUN_0080f7e0(unsigned int);
};
// @fnv 0x0080f7e0
void* MagicBallProjectile::FUN_0080f7e0(unsigned int flags)
{
    reinterpret_cast<::FUN_0080fb30 *>(this)->FUN_0080fb30::~FUN_0080fb30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct RefH
{
};
struct FUN_00811030_shell
{
    bool FUN_00811030();
    unsigned int pad00[0x2b];
    int unkac;
};
// Returns true when the int at offset 0xac is not 2 and the object is not deleted.
// @fnv 0x00811030
bool FUN_00811030_shell::FUN_00811030()
{
    return this->unkac != 2 &&
           !reinterpret_cast<::FUN_00440d80_shell *>((void *)(reinterpret_cast<const RefH*>(this)))->FUN_00440d80();
}

struct TESSaveLoadGame
{
};

struct FUN_0081e830_shell
{
    unsigned short GetSaveRecordSize(unsigned int);
};

struct FUN_00811070_shell
{
    unsigned short FUN_00811070(unsigned int aiFlags);
    char pad00[0xac];
    int eState;
};

// @fnv 0x00811070
unsigned short FUN_00811070_shell::FUN_00811070(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_0081e830_shell*)this)->GetSaveRecordSize(aiFlags);
    isize += 4;
    isize += 4;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() < 0x64)
        isize += 4;
    isize += 4;
    isize += 4;
    if (eState == 2)
        isize += 4;
    return isize;
}

struct FUN_008229d0_shell
{
    void* FUN_008229d0(unsigned int);
};
struct FUN_0081de70_shell
{
};
struct FUN_00822a00_shell
{
    void FUN_00822a00();
};
// Calls FUN_00822a00, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x008229d0
void* FUN_008229d0_shell::FUN_008229d0(unsigned int flags)
{
    reinterpret_cast<::FUN_00822a00_shell *>(this)->FUN_00822a00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00822a00
void FUN_00822a00_shell::FUN_00822a00()
{
    reinterpret_cast<::fnv_0081de70::FUN_0081de70_cls *>((reinterpret_cast<FUN_0081de70_shell*>(this)))->fnv_0081de70::FUN_0081de70_cls::~FUN_0081de70_cls();
}

struct FUN_008cac30_shell
{
    void* FUN_008cac30(unsigned int flags);
    void FUN_008cac60();
};
namespace fnv_008cf740 {
struct TESSaveLoadGame
{
};
struct S00932750
{
};
struct Owner008cf740
{
    char _pad[0x88];
    void* f88;
    void FUN_008cf740(int);
};
// Calls FUN_00932750 with a, then if g_TESSaveLoadGame->FUN_0055f5b0() is true, deallocates f88 and sets it to 0.
// @fnv 0x008cf740
void Owner008cf740::FUN_008cf740(int a)
{
    reinterpret_cast<::WorkerMobile *>((((S00932750*)this)))->FUN_00932750(a);
    if (reinterpret_cast<::FUN_0055f5b0_Class *>(((*reinterpret_cast<::fnv_008cf740::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_0055f5b0())
    {
        if (f88 != 0)
        {
            void* tmp = f88;
            ::FUN_00401030(tmp);
        }
        f88 = 0;
    }
}
}  // namespace fnv_008cf740

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct FUN_008cb380_shell
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
    virtual void v190(float);
    void FUN_008cb380(float);
};
// @fnv 0x008cb380
void FUN_008cb380_shell::FUN_008cb380(float afUnused)
{
    float fTime = ::fnv::timer::Seconds();
    v190(fTime);
}

struct PC7d
{
};

struct SaveManager
{
};

class ActorPackageContext
{
};

struct TESSaveLoadGameHelper
{
    void FUN_008579b0(void*, int);
};

struct FUN_0081e8c0_shell_standin
{
};

struct FUN_00811110_shell
{
    void FUN_00811110(unsigned int);
    unsigned int pad00[0x22];
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int pad90[0x6];
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int padb4[0x3];
    void* unkc0;
};


// @fnv 0x00811110
void FUN_00811110_shell::FUN_00811110(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_0081e8c0_shell *>((reinterpret_cast<FUN_0081e8c0_shell_standin*>(this)))->FUN_0081e8c0(aiFlags);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&this->unka8, 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&this->unk88, 4);

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 100)
    {
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&this->unk8c, 4);
    }

    reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<TESSaveLoadGameHelper*>(g_TESSaveLoadGame)))->FUN_008579b0(reinterpret_cast<char*>(&this->unkac), 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&this->unkb0, 4);

    if (this->unkac == 2)
    {
        float ffadeTimer;
        ffadeTimer = 0.0f;

        if (*reinterpret_cast<ActorPackageContext**>(&this->unkc0))
        {
            ffadeTimer =
                reinterpret_cast<::FUN_00621b00_shell *>((reinterpret_cast<ActorPackageContext*>(*reinterpret_cast<ActorPackageContext**>(&this->unkc0))))->FUN_00621b00();
        }

        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&ffadeTimer, 4);
    }
}

namespace fnv_008111e0 {
struct STR00
{
};

class Projectile
{
};

struct SaveManager
{
};


struct TESSaveLoadGameLoadData
{
};

struct FUN_008111e0_vtable
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
};

struct FUN_008111e0_shell : FUN_008111e0_vtable
{
    unsigned char padding[0x84];
    unsigned int unk88;
    unsigned int unk8c;
    unsigned char pad90[0x18];
    unsigned int unka8;
    int eState;

    void LoadFromSave(unsigned int, unsigned int);
    unsigned int unkb0;
    unsigned int padb4[0x3];
    float unkc0;
};


// @fnv 0x008111e0
void FUN_008111e0_shell::LoadFromSave(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    float ffadeTimer;

    this->v113();

    reinterpret_cast<::FUN_0081e980_shell *>((reinterpret_cast<Projectile*>(this)))->FUN_0081e980(aiFlags, aiCurrentFlags);

    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<STR00*>(this)))->FUN_00484d00(reinterpret_cast<void*>(&this->unka8), 4);

    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<STR00*>(this)))->FUN_00484d00(reinterpret_cast<void*>(&this->unk88), 4);

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008111e0::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 100)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<STR00*>(this)))->FUN_00484d00(reinterpret_cast<void*>(&this->unk8c), 4);
    }

    reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<TESSaveLoadGameLoadData*>((*reinterpret_cast<::fnv_008111e0::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(reinterpret_cast<void*>(reinterpret_cast<char*>(&this->eState)), 4);

    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<STR00*>(this)))->FUN_00484d00(reinterpret_cast<void*>(&this->unkb0), 4);

    if (this->eState == 2)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<STR00*>(this)))->FUN_00484d00(&ffadeTimer, 4);

        ::__memcpy(&this->unkc0, &ffadeTimer, 4);
    }
}
}  // namespace fnv_008111e0

struct ProjectileFlags
{
    unsigned value;
};
struct ProjectileInfo
{
    ProjectileFlags FUN_0070c440();
};
struct ImpactPoint
{
    float x, y, z;
};
struct AreaSound
{
};
struct ProjectileEffect
{
};
struct ImpactHandle
{
    unsigned id, flags, state;
    ~ImpactHandle();
};
struct ImpactAudio
{
    ImpactHandle FUN_00ad73b0(unsigned, unsigned);
};
struct ProjectileEvent
{
};
struct ProjectileImpact
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual ImpactPoint& position();
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    float elapsed, duration;
    int unkb0, mode;
    void TriggerImpact(int, int, int, int, intptr_t, bool);
};
struct Mgr
{
    void FUN_0096d450(void*, int, int, int, int);
};
struct Obj
{
    virtual ~Obj();
    virtual void v1(Obj*);
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
};
struct FUN_008d7510 : Obj
{
    int unk04[282];
    FUN_008d7510();
};
struct Self
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127(int);
    char pad[0x64];
    Obj* m68;
    bool FUN_008cf7a0();
};
struct NiPoint3
{
  public:
    float x, y, z;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
struct _ref_006815c0
{
    _ref_006815c0();
};
struct ThreeByThreeMatrix : public _ref_006815c0
{
  public:
    float m_afEntries[3][3];
public:
    void FUN_00a59780(float, float, float);
};
struct NiRTTI;
struct NiObject
{
    virtual void Unk_00();
};
class NiTimeController : public NiObject
{
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char* pcString);
    ~NiFixedString();
};
struct NiUpdateData
{
  public:
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_iUnk;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);
};
struct NiObjectNET : public NiObject
{
  public:
};
struct NiPoint3;
class NiAVObject : public NiObjectNET
{
  public:
    void Update(const NiUpdateData& kData);
public:
    ::NiPoint3 &FUN_0043c490();
};
class NiControllerSequence
{
  public:
};
class NiControllerSequence;
struct NiControllerManager : public NiTimeController
{
  public:
public:
    bool ActivateControllerSequence(::NiControllerSequence *, int, bool, float, float, ::NiControllerSequence *);
public:
    bool StopSequence(::NiControllerSequence *, float);
public:
    void DeactivateAllSequences(float);
};
class TESObjectREFR
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
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
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual NiAVObject* Get3D();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos();
    char pad[0xb0 - 4];
    float fScale;
    void ResetProjectileIdleAnimation();
};

// @fnv 0x0080fcf0
void TESObjectREFR::ResetProjectileIdleAnimation()
{
    NiAVObject* pNode = Get3D();
    if (pNode)
    {
        reinterpret_cast<::FUN_00440490_shell *>((pNode))->FUN_00440490(fScale);
        reinterpret_cast<::FUN_00440460_S *>((pNode))->FUN_00440460((const ::V3 *)&(*GetPos()));
        NiPoint3 kAngles = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)this)->GetData()));
        ThreeByThreeMatrix kRotate;
        reinterpret_cast<::FUN_00a59660_cls *>(&(kRotate))->FUN_00a59660(kAngles.z, kAngles.x, kAngles.y);
        reinterpret_cast<::FUN_0043fa80_s *>((pNode))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&kRotate)));
        ::fnv_00c4b500::FUN_00c4b500((::fnv_00c4b500::Node *)(pNode));
        NiControllerManager* pManager = (NiControllerManager*)FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(pNode)))));
        if (pManager)
        {
            NiControllerSequence* pSequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("SpecialIdle_Projectile")))));
            if (pSequence)
            {
                pManager->DeactivateAllSequences(0.0f);
                pManager->ActivateControllerSequence(pSequence, 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::TaskQueueInterface *>((pManager))->QueueReferenceStateTask(true);
                reinterpret_cast<::FUN_0098adb0_shell *>((pSequence))->FUN_0098adb0(-DAT_0107a510);
                NiUpdateData kUpdateData(::fnv_00563f30::DAT_011c3c08 - (double)0.1f, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((pNode))->FUN_00a59c60((std::intptr_t)&(kUpdateData));
            }
        }
    }
}

namespace fnv_008106d0 {
struct Vec
{
    float x, y, z;
    Vec(float, float, float);
    Vec operator-(const Vec&) const;
};
struct Sequence
{
};
struct Fixed
{
    const char* text;
    Fixed(const char*);
    ~Fixed();
};
struct Controller
{
};
struct Model
{
};
struct Effect
{
};
struct Info
{
};
struct Setting
{
};
struct AreaProjectile
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
    virtual void Kill(int);
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
    virtual Model* GetModelFilePath();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const Vec& Position();
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
    virtual void Move(float, Vec*, int);
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
    virtual void SetPosition(Vec, int, int, int);
    virtual void v194();
    virtual bool Active();
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
    float speed;
    float distance;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int state;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    Effect* effect;
    void FUN_008106d0(float dt);
};
// Advances the projectile by dt: kills it on large dt, moves it along its speed, accumulates distance, and handles the idle/effect state.
// @fnv 0x008106d0
void AreaProjectile::FUN_008106d0(float afDeltaTime)
{
    if (afDeltaTime >= 60.0)
        Kill(1);
    if (afDeltaTime >= 0.0)
    {
        switch (state)
        {
        case 0:
            state = 1;
        case 1: {
            if (reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
                break;
            if (((double)(::FUN_004587d0(reinterpret_cast<::FUN_00810a80_shell *>((((::fnv_008106d0::Info *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->GetFloatAtOffset53C()))) >= Position().z)
                SetPosition(Position(), 0, 0, 1);
            Vec newPosition(0.0f, speed * afDeltaTime, 0.0f);
            Vec oldPosition = Position();
            Move(afDeltaTime, &newPosition, 15);
            if (!Active())
                break;
            Vec velocity = Position();
            if (GetModelFilePath())
                reinterpret_cast<::FUN_00440460_S *>((GetModelFilePath()))->FUN_00440460((const ::V3 *)(const ::fnv_008106d0::Vec *)(&velocity));
            distance += reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_008106d0::Vec &)((velocity - oldPosition)))->ComputeMagnitude();
            if (distance > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008106d0::Setting *>(&::originalRuntimeFloatSetting1130)))))))
                Kill(1);
            if (effect)
                reinterpret_cast<::MagicEffectCollection *>((effect))->UpdateLightFade(afDeltaTime);
            break;
        }
        case 2: {
            Model* animation = GetModelFilePath();
            Controller* ctrl = animation ? ((::fnv_008106d0::Controller *)(::fnv_0043b230::FUN_0043b230((const char *)(animation)))) : 0;
            Controller* swapModel = ((::fnv_008106d0::Controller *)(::FUN_00653270((const ::NiRTTI *)(const int *)(&(*reinterpret_cast<int *>(&::g_011f36ac))), (::NiObject *)(ctrl))));
            if (swapModel)
            {
                Sequence* sequence = ((::fnv_008106d0::Sequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((swapModel))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::fnv_008106d0::Fixed &)(Fixed("SpecialIdle_AreaEffect")))));
                if (!sequence || (sequence && (reinterpret_cast<::BSFaceGenMorphData *>((sequence))->FUN_00508120() > reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100() ||
                                               ((intptr_t)(reinterpret_cast<::LowProcess *>((sequence))->GetActiveCombatTarget())) == 0)))
                {
                    reinterpret_cast<::NiControllerManager *>((swapModel))->DeactivateAllSequences(0.0f);
                    reinterpret_cast<::FUN_00484af0_t *>(this)->FUN_00484af0(1);
                    Kill(1);
                }
            }
            else
            {
                Kill(1);
                reinterpret_cast<::FUN_00484af0_t *>(this)->FUN_00484af0(1);
            }
            if (effect)
                reinterpret_cast<::MagicEffectCollection *>((effect))->UpdateLightFade(afDeltaTime);
            break;
        }
        }
    }
}
}  // namespace fnv_008106d0

struct Cls;
struct Ctrl;
struct Refr;
struct Refr2;
struct CollObj;
struct WorldObj;
struct SettingObj;

struct Filter
{
    unsigned int info;
};

struct RetObj
{
    int f0;
};

struct Ctrl
{
    RetObj FUN_0070c440();
};

struct Refr
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual Refr2* tv11();
};

struct Refr2
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual Refr2* tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual bool tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual void tv96();
    virtual void tv97();
    virtual void tv98();
    virtual void tv99();
    virtual void tv100();
    virtual void tv101();
    virtual void tv102();
    virtual void tv103();
    virtual void tv104();
    virtual void tv105();
    virtual void tv106();
    virtual void tv107();
    virtual void tv108();
    virtual void tv109();
    virtual void tv110();
    virtual void tv111();
    virtual void tv112();
    virtual void tv113();
    virtual void tv114();
    virtual void tv115();
    virtual void* tv116();
    Filter FUN_00931ed0();
};

struct CollObj
{
};

struct WorldObj
{
    Filter FUN_0043b4f0();
};

struct SettingObj
{
};



struct Cls
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual void tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual void tv96();
    virtual void tv97();
    virtual void tv98();
    virtual void tv99();
    virtual void tv100();
    virtual void tv101();
    virtual void tv102();
    virtual void tv103();
    virtual void tv104();
    virtual void tv105();
    virtual void tv106();
    virtual void tv107();
    virtual void tv108();
    virtual void tv109();
    virtual void tv110();
    virtual void tv111();
    virtual void tv112();
    virtual void tv113();
    virtual void tv114();
    virtual void tv115();
    virtual void* tv116();
    void FUN_008115c0(int a1, int a2);
};

// @fnv 0x008115c0
void Cls::FUN_008115c0(int aiArg1, int aiArg2)
{
    reinterpret_cast<::fnv_00932520::FUN_00932520_shell *>(this)->UpdateFlags(aiArg1, aiArg2);
    Ctrl* ctrl4 = ((::Ctrl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (ctrl4)
    {
        unsigned int _result;
        if (((::Refr *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)) && ((::Refr *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->tv11())
        {
            Refr2* obj4 = ((::Refr *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->tv11();
            Refr2* filtered = obj4->tv64() ? obj4 : 0;
            if (filtered)
            {
                _result = ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter &)(filtered->FUN_00931ed0()))->FUN_004a3a20()));
            }
            else
            {
                CollObj* co = ((::CollObj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(void *)(obj4->tv116()))));
                WorldObj* world1;
                world1 = co ? ((::WorldObj *)(::fnv_006fa820::FUN_006fa820((const char *)(co)))) : 0;
                _result = world1 ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter &)(world1->FUN_0043b4f0()))->FUN_004a3a20())) : FUN_005dbe10();
            }
        }
        else
        {
            CollObj* co5 = ((::CollObj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(void *)(tv116()))));
            WorldObj* world3;
            world3 = co5 ? ((::WorldObj *)(::fnv_006fa820::FUN_006fa820((const char *)(co5)))) : 0;
            _result = world3 ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter &)(world3->FUN_0043b4f0()))->FUN_004a3a20())) : FUN_005dbe10();
        }
        RetObj retObjTmp = ctrl4->FUN_0070c440();
        reinterpret_cast<::FUN_004a39f0_shell *>(&(retObjTmp))->FUN_004a39f0(7);
        reinterpret_cast<::FUN_0059ce80_shell *>(&(retObjTmp))->FUN_0059ce80(_result);
        reinterpret_cast<::fnv_00810ff0::Ths810 *>((ctrl4))->FUN_00810ff0(retObjTmp.f0);
    }
    Refr2* tailObjVal;
    tailObjVal = ((::Refr *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)) ? ((::Refr *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->tv11() : 0;
    if (tailObjVal != (*reinterpret_cast<::Refr2 * *>(&::_g_thePlayer)))
    {
        FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::g_011d1c28)))))));
    }
}

struct Vec
{
    float x, y, z;
    Vec();
    Vec(float, float, float);
    Vec operator-(const Vec&) const;
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Matrix();
};
struct Node
{
    Vec& FUN_0045bb80();
};
struct Flags
{
    unsigned value;
};
struct Controller
{
    Flags FUN_0070c440();
};
struct Anim
{
};
template <class T> struct Ptr
{
    T* ptr;
    operator T*() const;
    Ptr& operator=(T*);
};
struct Link
{
    Ptr<Anim> anim;
    Ptr<Node> node;
    int unk08, unk0c, unk10;
    Ptr<Node> first, second;
    Link* next;
    ~Link();
};
struct Owner
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
    virtual void Detach(Node*);
};
struct ParentNode : Node
{
};
struct FloatSetting
{
};
struct IntSetting
{
};
extern bool DAT_011dc55c;
struct Sound
{
    unsigned id, flags, state;
};
class Projectile
{
  public:
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
    virtual void Mark(int);
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
    virtual Node* Root();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec& Position();
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
    virtual void Move(float, Vec&, int);
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
    virtual void Relocate(Vec, int, int, int);
    virtual void v194();
    virtual bool Active();
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
    float speed;
    float distance;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    Ptr<Anim> animation;
    int mode;
    Link* links;
    Ptr<Node> node;
    int unkb8;
    Ptr<ParentNode> target;
    Ptr<Node> effect;
    int unkc4;
    Sound sound;
    float start;
    void UpdateMotion(float delta);
};
// Advances the projectile each frame: moves it, updates its animation and links, rotates toward the target, and marks it for removal when finished.
// @fnv 0x00812b60
void Projectile::UpdateMotion(float delta)
{
    if (delta == 0.0)
        return;
    if (reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
        return;
    Vec original = (*(::Vec *)&(reinterpret_cast<::NiAVObject *>((Root()))->FUN_0043c490()));
    if ((Anim*)animation && mode == 0)
    {
        if (FUN_004587d0(reinterpret_cast<::FUN_00810a80_shell *>((((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->GetFloatAtOffset53C()) >= Position().z)
            Relocate(Position(), 0, 0, 1);
        Vec movementVal(0.0f, speed * delta, 0.0f);
        Vec before = (*reinterpret_cast<::Vec *>((void *)&::NiPoint3::ZERO));
        if (((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
            reinterpret_cast<::VectorSourceB00 *>((((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00812b00((void *)&(before));
        Move(delta, movementVal, 15);
        Vec after = (*reinterpret_cast<::Vec *>((void *)&::NiPoint3::ZERO));
        if (((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
            reinterpret_cast<::VectorSourceB00 *>((((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00812b00((void *)&(after));
        distance += reinterpret_cast<::NiPoint3 *>((void *)&(const ::Vec &)((after - before)))->ComputeMagnitude();
        if (distance > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1130)))))))
            Mark(1);
        if (!Active())
            return;
    }
    else if (mode == 1)
    {
        Link* current3 = links;
        Link* previousTmp = 0;
        Link* next = 0;
        while (current3)
        {
            reinterpret_cast<::EffectBase *>(this)->FUN_00812700(delta, (::EffectParams *)(current3));
            next = current3->next;
            if (((unsigned char)(reinterpret_cast<::FUN_00813370_class *>((((Anim*)current3->anim)))->FUN_00813370())))
            {
                Owner* owner = ((::Owner *)(reinterpret_cast<::FUN_009611e0_shell *>((((ParentNode*)(Node*)current3->node)))->FUN_009611e0()));
                if (owner)
                    owner->Detach(current3->node);
                if (previousTmp == 0)
                    links = current3->next;
                else
                    previousTmp->next = current3->next;
                current3->node = 0;
                current3->anim = 0;
                current3->first = 0;
                current3->second = 0;
                delete current3;
            }
            else
                previousTmp = current3;
            current3 = next;
        }
    }
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting *>(&::g_011d1afc)))))) > 0 || DAT_011dc55c)
    {
    }
    else
    {
        bool moving = mode != 0;
        if ((ParentNode*)target)
        {
            Vec difference2 = ((ParentNode*)target)->FUN_0045bb80() - original;
            if (!moving ||
                ::GetField90Float((char *)this) * speed > ((intptr_t)(reinterpret_cast<::FUN_008d8b80Class *>((((Anim*)animation)))->FUN_008d8b80())) * reinterpret_cast<::FUN_008133b0_class *>((((Anim*)animation)))->GetFloatAt144())
                ::DispatchFloatPair(((Anim*)animation), delta, reinterpret_cast<::NiPoint3 *>(&(difference2))->ComputeMagnitude(), speed);
            Matrix rotation;
            float vertical = difference2.z;
            difference2.z = 0.0f;
            float horizontal_ = reinterpret_cast<::NiPoint3 *>(&(difference2))->ComputeMagnitude();
            reinterpret_cast<::ThreeByThreeMatrix *>(&(rotation))->FUN_00a59780(FUN_004b5550(difference2.x, difference2.y), 0.0f,
                                  -FUN_004b5550(vertical, horizontal_));
            reinterpret_cast<::FUN_0043fa80_s *>((((Node*)node)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
        }
        else if (((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
        {
            Vec position;
            reinterpret_cast<::VectorSourceB00 *>((((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00812b00((void *)&(position));
            float length = reinterpret_cast<::NiPoint3 *>((void *)&(const ::Vec &)((original - position)))->ComputeMagnitude();
            if (!moving ||
                ::GetField90Float((char *)this) * speed > ((intptr_t)(reinterpret_cast<::FUN_008d8b80Class *>((((Anim*)animation)))->FUN_008d8b80())) * reinterpret_cast<::FUN_008133b0_class *>((((Anim*)animation)))->GetFloatAt144())
                ::DispatchFloatPair(((Anim*)animation), delta, length, speed);
            if (::FUN_00ee8990())
            {
                reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(2);
                Flags state = ((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440();
                reinterpret_cast<::FUN_00810f90_shell *>(&(state))->SetFlag4000(true);
                reinterpret_cast<::fnv_00810ff0::Ths810 *>((((::Controller *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00810ff0(state.value);
            }
        }
    }
    if ((Node*)effect)
        reinterpret_cast<::FUN_004f00e0_shell *>((((Node*)effect)))->FUN_004f00e0((void *)(&Position()));
    if (((unsigned char)(reinterpret_cast<::FUN_00813370_class *>((((Anim*)animation)))->FUN_00813370())) || (mode == 1 && reinterpret_cast<::FUN_00812870_t *>(this)->GetUnka4() - start > 3.0))
    {
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->IsValid())
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sound))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->Release();
        }
        if (!links)
            Mark(1);
    }
}

namespace fnv_0081a320 {
struct Vec3
{

    float x, y, z;



};

struct FUN_00440460_shell
{
};

struct FUN_008106b0_shell : FUN_00810a80_shell
{
};

struct FUN_0081c320_shell
{
};

struct FUN_00ad8ce0_shell
{



    unsigned int unkBC, unkC0, unkC4, unkC8;
};

struct FUN_00403e20_shell
{
};

struct FUN_00817160_shell
{
};





int __cdecl FUN_00ec62c0();

struct FUN_0081a320_class;

struct FUN_00440d80_shell
{
};

struct FUN_009306d0_shell
{
};

struct FUN_0081a320_class
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

    virtual void v49(int value);

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

    virtual FUN_00440460_shell* v116(Vec3* point);

    virtual void v117();

    virtual void v118();

    virtual void v119();

    virtual void v120();

    virtual void v121();

    virtual void v122();

    virtual void v123();

    virtual void v124();

    virtual Vec3* v125();

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

    virtual void v148(float time, Vec3* aim, int flags);

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

    virtual void v193(Vec3 point, int a, int b, int c);

    virtual void v194();

    virtual unsigned char v195();

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    float m_88;

    float m_8c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    float m_a8;

    float m_ac;

    unsigned int unk0b0;

    int m_b4;

    unsigned int unk0b8;

    FUN_00ad8ce0_shell m_bc;

    FUN_0081c320_shell* m_cc;


    int FUN_00810fd0(int);


    void FUN_0081a320(float dt);
};

// @fnv 0x0081a320
void FUN_0081a320_class::FUN_0081a320(float afDeltaTime)
{

    if (afDeltaTime >= ::DAT_01012638)
        v49(1);

    if (afDeltaTime >= ::_DAT_01012060)
    {

        switch (m_b4)
        {
        case 0: {

            if (((unsigned char)(reinterpret_cast<::FUN_00440d80_shell *>((((FUN_00440d80_shell*)this)))->FUN_00440d80())))
                return;

            if (((double)(::FUN_004587d0(((::fnv_0081a320::FUN_008106b0_shell *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((FUN_009306d0_shell*)this)))->FUN_009306d0()))->GetFloatAtOffset53C()))) >= v125()->z)
                v193(*v125(), 0, 0, 1);

            float distanceTraveled;
            Vec3 aim;

            reinterpret_cast<::FUN_00416870_t *>(&(aim))->FUN_00416870(0.0f, m_88 * afDeltaTime, 0.0f);

            reinterpret_cast<::FUN_008106b0_Class *>((((::fnv_0081a320::FUN_008106b0_shell *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((FUN_009306d0_shell*)this)))->FUN_009306d0()))))->FUN_008106b0(1.0f - afDeltaTime * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0081a320::FUN_00403e20_shell *>(&::originalRuntimeFloatSetting1145)))))));

            Vec3 start = *v125();

            v148(afDeltaTime, &aim, 15);

            if (!v195())
            {
            }
            else
            {

                Vec3 vCurrentPosition = *v125();

                reinterpret_cast<::FUN_00440460_S *>((v116(&vCurrentPosition)))->FUN_00440460({});
                distanceTraveled = reinterpret_cast<::NiPoint3 *>((void *)&(const ::fnv_0081a320::Vec3 &)(([&] { ::fnv_0081a320::Vec3 difference; reinterpret_cast<::FUN_00439ef0_class *>(&(vCurrentPosition))->FUN_00439ef0((::NiPoint3 *)&difference, *(const ::NiPoint3 *)((::NiPoint3 *)(&start))); return difference; }())))->ComputeMagnitude();

                m_8c += distanceTraveled;

                if (m_8c > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0081a320::FUN_00403e20_shell *>(&::originalRuntimeFloatSetting1130)))))))
                    v49(1);

                if ((double)(distanceTraveled / afDeltaTime) < ::DAT_01020998)
                    v193((*reinterpret_cast<::fnv_0081a320::Vec3 *>((void *)&::NiPoint3::ZERO)), 0, 0, 0);
            }
        }
        break;
        }
        float fPreviousTime = m_a8;

        m_a8 += afDeltaTime;

        if (m_a8 > m_ac)
        {
            v49(1);
        }
        else
        {

            if (m_cc)
                reinterpret_cast<::MagicEffectCollection *>((m_cc))->UpdateLightFade(afDeltaTime);

            if (((unsigned char)(reinterpret_cast<::SoundPlaybackHandle *>(&(m_bc))->IsValid())))
            {

                float fSegmentTime = (float)(m_ac / ::DAT_01011590);

                if (m_a8 > fSegmentTime)
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(m_bc))->FUN_00ad89e0(1.0f * (1.0f - ((m_a8 - fSegmentTime) / fSegmentTime)));
            }

            if ((int)::std::floor(fPreviousTime / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0081a320::FUN_00403e20_shell *>(&::originalRuntimeFloatSetting1146))))))) !=
                (int)::std::floor(m_a8 / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0081a320::FUN_00403e20_shell *>(&::originalRuntimeFloatSetting1146))))))))
            {

                float ratio = (m_ac - m_a8) / m_ac;

                if (::_DAT_01012060 < ratio)
                {

                    reinterpret_cast<::P142Caster *>(reinterpret_cast<::MagicProjectileFields *>(this)->caster)->ApplySpellEffects((::P142Spell *)(reinterpret_cast<::MagicProjectileFields *>(this)->spell), (std::intptr_t)(((void *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), *(::NiPoint3 *)(v125()), (::P142Ref *)(void *)(this), 0, 0, ratio, 1.0f);
                }
            }
        }
    }
}
}  // namespace fnv_0081a320

struct SaveStream
{




    void FUN_008579b0(const void*, int);

};

struct SaveFlag
{

    unsigned char* FUN_00408d60();
};


extern unsigned char UNK_01085d58;







struct SaveHandle
{

};

struct StateProcessor
{

};

struct Vec3f
{
    float x, y, z;
};

struct MotionStateRecord
{

    int type;

    Vec3f origin;

    Vec3f axis;

    Vec3f velocity;

    StateProcessor* handle;

    intptr_t packed;

    char extended[16];
};

struct FourInts
{

    int x0, x1, x2, x3;


};

struct FUN_008ce610_owner : PC7d
{



    void FUN_008ce610(int);
    char pad00[0x88];
    MotionStateRecord* pMotionState;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    SaveHandle* unka4;
    SaveHandle* unka8;
    int eState;
    SaveHandle* unkb0;
    Vec3f unkb4;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    char padc3[0x4];
};

namespace fnv_008ceb50 {
static const char underrunMessage[] =
    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X";
static const char overrunMessage[] =
    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X";
struct Matrix
{
    float a, b, c, d, e, f, g, h, i;
    Matrix();
};
struct Vec4
{
    float x, y, z, w;
    Vec4();
};
struct ExtraData
{
    int kind;
    float x, y, z, rx, ry, rz, sx, sy, sz;
    unsigned ref;
    void* name;
    Matrix matrix;
    ExtraData();
};
struct Record
{
    unsigned id;
    unsigned char kind;
    char payload0, payload1, payload2, payload3;
    unsigned char subtype;
};
struct Word
{
    unsigned value;
};
struct Form
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
    virtual void slot64();
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
    virtual const char* describe();
};
struct Loader
{
    unsigned position();
};
struct Loaded
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
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    ExtraData* extra;
    unsigned mode, a90, a94, a98, a9c, aa0, refA, refB, unknownAc, refC;
    float x, y, z;
    unsigned char c0, c1, c2;
    void FUN_008ceb50(void*, void*);
};
// Loads the block header, mode, refs, position and extra data (with optional rotation and name) from the loader, then warns on buffer overrun or underrun.
// @fnv 0x008ceb50
void Loaded::FUN_008ceb50(void* arg1, void* arg2)
{
    reinterpret_cast<::fnv_009320e0::FUN_009320e0_class *>(this)->SetProcessLevel(arg1, arg2);
    unsigned short a = 0;
    char* i = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned tag;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            Record* rec = ((::fnv_008ceb50::Record *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))));
            if (rec)
            {
                Form* form = ((::fnv_008ceb50::Form *)(::FUN_004839c0(rec->id)));
                ::FUN_005b5e40(
                    );
            }
            else
                ::FUN_005b5e40(
                    );
        }
        i = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&a, 2);
    }
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&mode, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&a90, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&a94, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&a98, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&a9c, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&aa0, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&x, 12);
    unsigned h;
    reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&h, 4);
    refA = h;
    unsigned f;
    reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&f, 4);
    refB = f;
    unsigned s;
    reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&s, 4);
    refC = s;
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 32)
        reinterpret_cast<::FUN_00857bd0 *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->Init(8);
    bool p = false;
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 32)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&p, 1);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 32)
        p = mode == 1 || mode == 2;
    if (p)
    {
        extra = new ExtraData;
        extra->name = 0;
        extra->ref = 0;
        extra->matrix = (*reinterpret_cast<::fnv_008ceb50::Matrix *>(&::DAT_011a9448));
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&extra->kind, 4);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&extra->x, 12);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&extra->rx, 12);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&extra->sx, 12);
        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 80)
        {
            Vec4 rotation;
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&rotation, 16);
            Matrix temp;
            reinterpret_cast<::FUN_004f0180_Class *>(&(rotation))->FUN_004f0180((::M3_ *)(::fnv_008ceb50::Matrix *)(&extra->matrix));
        }
        if (extra->kind == 1 || extra->kind == 0)
        {
            unsigned ref;
            reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&ref, 4);
            extra->ref = ref;
            if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 32)
            {
                unsigned short h;
                short p;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&h, 2);
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&p, 2);
                uintptr_t a = (h << 16) + p;
                extra->name = (void*)a;
            }
            if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 32)
            {
                unsigned char p;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&p, 1);
                char* h = (char*)operator new(p + 1);
                ::FUN_00403d30(h, 0, p + 1);
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(h, p);
                extra->name = h;
            }
        }
    }
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 84)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&c1, 1);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 85)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&c2, 1);
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        char* end = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        Record* recEnd = ((::fnv_008ceb50::Record *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_008ceb50::Loader * *>(&::g_TESSaveLoadGame))))));
        if (recEnd)
        {
            Form* formEnd = ((::fnv_008ceb50::Form *)(::FUN_004839c0(recEnd->id)));
            if (end > i + a)
                ::FUN_005b5e40();
            else if (end < i + a)
                ::FUN_005b5e40();
        }
        else
        {
            if (end > i + a)
                ::FUN_005b5e40();
            else if (end < i + a)
                ::FUN_005b5e40();
        }
    }
}
}  // namespace fnv_008ceb50
struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct xFilter
{
    unsigned int m_uiFilterValue;
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
    virtual void v50();
    virtual void v51();
    virtual void FUN_d0(void*, int, int, unsigned int, int);
};
struct xAVOwner
{
};
struct xActor;
void* __cdecl xFUN_00553300(std::size_t);
struct __declspec(align(16)) xCtlCinfo
{
    xCtlCinfo(int);
    ~xCtlCinfo();
    xM128 m_q[12];
};
struct xCharCtl
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
    virtual void FUN_d0(int);
    static void* operator new(std::size_t n)
    {
        return xFUN_00553300(n);
    }
    static void operator delete(void*);
    xCharCtl(xCtlCinfo*, xActor*);
    xWorld* FUN_00621ad0();
    xFilter FUN_0070c440();
    int m_auiShapeKeys[0x197];
};
struct xCtlPtr
{
    xCtlPtr(xCharCtl*);
    ~xCtlPtr();
    void* m_p;
};
struct xMid
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
    virtual void FUN_290(xCtlPtr);
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
    char m_pad04[0x64];
    xMid* m_68;
    char m_pad6c[0x38];
    xAVOwner m_a4;
    xFilter FUN_00931ed0();
    void FUN_008caea0(xActor* apOther, float afVal);
public:
    void FUN_0081eba0();
    bool FUN_0088c240(const ::xP3 &, bool, bool);
    float FUN_008bd830(intptr_t, float);
    void FUN_008ccce0(const ::xP3 &, const ::xP3 &);
    bool FUN_009c40c0();
};

namespace fnv_008cf440 {
struct Mid;
struct Node;
struct FlagObj
{
    char pad00[8];
    void* pObject;
};
struct Node
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
    virtual void slot64();
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
    virtual int slot76();
    bool FUN_00440da0();
};
struct Mid
{
    int f00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    Node* f28;
    std::uintptr_t f2c;
};
struct Mgr85
{
};
extern char DAT_01085d9c[];
struct Cls
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
    virtual void slot49(int);
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    Mid* f88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    intptr_t fa4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    unsigned char fc0;
    unsigned char uc1;
    unsigned char uc2;
    unsigned char uc3;
    int fc4;
    void FUN_008cf440(int, int);
};

// @fnv 0x008cf440
void Cls::FUN_008cf440(int a1, int a2)
{
    void* saved;
    intptr_t saved2c5;
    intptr_t result;
    unsigned short wordres;
    int hi5;
    intptr_t lo_;
    bool _flag;
    reinterpret_cast<::FUN_0046a010_shell *>(this)->FUN_0046a010(0);
    saved = ((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()));
    if (!((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())))
    {
        if (f88 != 0 && f88->f28 != 0 && f88->f28->FUN_00440da0() && reinterpret_cast<::FUN_00440d80_shell *>((f88->f28))->FUN_00440d80())
        {
            slot49(1);
            f88->f2c = 0;
            return;
        }
        fc0 = 1;
        fc4 = a1;
        return;
    }
    reinterpret_cast<::xActor *>(this)->FUN_008caea0((::xActor *)(fa4), 1.0f);
    reinterpret_cast<::fnv_00932520::FUN_00932520_shell *>(this)->UpdateFlags(a1, a2);
    if (f88 != 0 && (f88->f00 == 1 || f88->f00 == 0))
    {
        if ((int)reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x20)
        {
            _flag = f88->f00 == 0;
            lo_ = f88->f2c;
            hi5 = (int)((unsigned int)f88->f2c >> 0x10);
            f88->f2c = 0;
            if (f88->f28 != 0)
            {
                wordres = ((unsigned short)(::CountCollisionObjects((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((f88->f28))->FUN_0043fcd0()))), _flag, _flag, 1)));
                if (hi5 != (int)wordres)
                {
                    ::FUN_005b5e40();
                }
                else if (lo_ != -1)
                {
                    result = (intptr_t)((::fnv_008cf440::FlagObj *)(::FUN_004b6980((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((f88->f28))->FUN_0043fcd0()))), (void *)(lo_), _flag, _flag, 1)));
                    if (result != 0)
                    {
                        f88->f2c = reinterpret_cast<std::uintptr_t>(((FlagObj*)result)->pObject);
                    }
                }
            }
        }
        if ((int)reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 0x20)
        {
            saved2c5 = f88->f2c;
            if (f88->f28 != 0)
            {
                f88->f2c = (intptr_t)((void *)(::FUN_004aae30((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((f88->f28))->FUN_0043fcd0()))), (::NiFixedString *)(saved2c5))));
            }
            else
            {
                f88->f2c = 0;
            }
            ::FUN_00401030((void*)saved2c5);
        }
        if (f88->f2c == 0)
        {
            f88->f00 = 3;
        }
    }
    reinterpret_cast<::FUN_0085f710_class *>((((Mgr85*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->AddActorToList((int*)this);
}
}  // namespace fnv_008cf440


struct SpinLock_931710
{
};

struct Self_931710 : Self
{
    bool FUN_00931710();
};

namespace fnv_00935820 {

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& other) const;
};


struct ProjectileImpactCandidate : ProjectileImpact
{
    bool IsPointWithinImpactRange(const NiPoint3& point, float value, bool adjust, int unused_stack);
};

// @fnv 0x00935820
bool ProjectileImpactCandidate::IsPointWithinImpactRange(const NiPoint3& point, float value, bool adjust,
                                                         int unused_stack)
{
    float upper;
    float lower;
    float upperBase;
    {
        NiPoint3 origin = reinterpret_cast<NiPoint3&>(this->position());
        NiPoint3 result = origin - point;

        upper = ::DAT_0101e704;
        lower = origin.z - ::DAT_0101db88;
        upperBase = origin.z + upper + ::DAT_0101db88;
        if (point.z > lower && point.z < upperBase)
        {
            result.z = 0.0f;
        }
        if (adjust)
        {
            float adjustment = ::g_011db514_arg1;
            value += adjustment;
        }
        return ::FUN_004b5470((::TESCombatStyle *)(::fnv_00935820::NiPoint3 *)(&result), value) <= 0;
    }
}
}  // namespace fnv_00935820

struct SaveState
{
};

struct ValueReferencePair
{
    unsigned id;
    unsigned char kind;
    unsigned char flags0, flags1, flags2, flags3;
};
struct SaveSetting
{
    bool* Bool();
};
struct SaveForm
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
    virtual const char* GetName();
};
struct ProjectileData
{
    int type;
};
struct ArrowSave
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
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    ProjectileData* data;
    unsigned short FUN_008ce3b0(unsigned);
};

struct ActorTarget
{
    virtual void vfa_00();
    virtual void vfa_01();
    virtual void vfa_02();
    virtual void vfa_03();
    virtual void vfa_04();
    virtual void vfa_05();
    virtual void vfa_06();
    virtual void vfa_07();
    virtual void vfa_08();
    virtual void vfa_09();
    virtual void vfa_10();
    virtual void vfa_11();
    virtual void vfa_12();
    virtual void vfa_13();
    virtual void vfa_14();
    virtual void vfa_15();
    virtual void vfa_16();
    virtual void vfa_17();
    virtual void vfa_18();
    virtual void vfa_19();
    virtual void vfa_20();
    virtual void vfa_21();
    virtual void vfa_22();
    virtual void vfa_23();
    virtual void vfa_24();
    virtual void vfa_25();
    virtual void vfa_26();
    virtual void vfa_27();
    virtual void vfa_28();
    virtual void vfa_29();
    virtual void vfa_30();
    virtual void vfa_31();
    virtual void vfa_32();
    virtual void vfa_33();
    virtual void vfa_34();
    virtual void vfa_35();
    virtual void vfa_36();
    virtual void vfa_37();
    virtual void vfa_38();
    virtual void vfa_39();
    virtual void vfa_40();
    virtual void vfa_41();
    virtual void vfa_42();
    virtual void vfa_43();
    virtual void vfa_44();
    virtual void vfa_45();
    virtual void vfa_46();
    virtual void vfa_47();
    virtual void vfa_48();
    virtual void vfa_49();
    virtual void vfa_50();
    virtual void vfa_51();
    virtual void vfa_52();
    virtual void vfa_53();
    virtual void vfa_54();
    virtual void vfa_55();
    virtual void vfa_56();
    virtual void vfa_57();
    virtual void vfa_58();
    virtual void vfa_59();
    virtual void vfa_60();
    virtual void vfa_61();
    virtual void vfa_62();
    virtual void vfa_63();
    virtual bool IsActor();
};

struct PointProvider
{
    NiPoint3 FUN_004b4500(const NiPoint3&) const;
};

struct NiNodeStandin : NiAVObject
{
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual NiAVObject* GetObjectByName(const NiFixedString&);
};

struct CustomSequence : NiControllerSequence
{
};

struct CustomFlags
{
    unsigned int value;
    CustomFlags()
    {}
    CustomFlags(const CustomFlags& o) : value(o.value)
    {}
};

struct Sub410
{
};

struct ProjectileNodeStandin
{
    int unks_000;
    int unks_004;
    int unks_008;
    int unks_00c;
    int unks_010;
    int unks_014;
    int unks_018;
    int unks_01c;
    int unks_020;
    int unks_024;
    int unks_028;
    int unks_02c;
    int unks_030;
    int unks_034;
    int unks_038;
    int unks_03c;
    int unks_040;
    int unks_044;
    int unks_048;
    int unks_04c;
    int unks_050;
    int unks_054;
    int unks_058;
    int unks_05c;
    int unks_060;
    int unks_064;
    int unks_068;
    int unks_06c;
    int unks_070;
    int unks_074;
    int unks_078;
    int unks_07c;
    int unks_080;
    int unks_084;
    int unks_088;
    int unks_08c;
    int unks_090;
    int unks_094;
    int unks_098;
    int unks_09c;
    int unks_0a0;
    int unks_0a4;
    int unks_0a8;
    int unks_0ac;
    int unks_0b0;
    int unks_0b4;
    int unks_0b8;
    int unks_0bc;
    int unks_0c0;
    int unks_0c4;
    int unks_0c8;
    int unks_0cc;
    int unks_0d0;
    int unks_0d4;
    int unks_0d8;
    int unks_0dc;
    int unks_0e0;
    int unks_0e4;
    int unks_0e8;
    int unks_0ec;
    int unks_0f0;
    int unks_0f4;
    int unks_0f8;
    int unks_0fc;
    int unks_100;
    int unks_104;
    int unks_108;
    int unks_10c;
    int unks_110;
    int unks_114;
    int unks_118;
    int unks_11c;
    int unks_120;
    int unks_124;
    int unks_128;
    int unks_12c;
    int unks_130;
    int unks_134;
    int unks_138;
    int unks_13c;
    int unks_140;
    int unks_144;
    int unks_148;
    int unks_14c;
    int unks_150;
    int unks_154;
    int unks_158;
    int unks_15c;
    int unks_160;
    int unks_164;
    int unks_168;
    int unks_16c;
    int unks_170;
    int unks_174;
    int unks_178;
    int unks_17c;
    int unks_180;
    int unks_184;
    int unks_188;
    int unks_18c;
    int unks_190;
    int unks_194;
    int unks_198;
    int unks_19c;
    int unks_1a0;
    int unks_1a4;
    int unks_1a8;
    int unks_1ac;
    int unks_1b0;
    int unks_1b4;
    int unks_1b8;
    int unks_1bc;
    int unks_1c0;
    int unks_1c4;
    int unks_1c8;
    int unks_1cc;
    int unks_1d0;
    int unks_1d4;
    int unks_1d8;
    int unks_1dc;
    int unks_1e0;
    int unks_1e4;
    int unks_1e8;
    int unks_1ec;
    int unks_1f0;
    int unks_1f4;
    int unks_1f8;
    int unks_1fc;
    int unks_200;
    int unks_204;
    int unks_208;
    int unks_20c;
    int unks_210;
    int unks_214;
    int unks_218;
    int unks_21c;
    int unks_220;
    int unks_224;
    int unks_228;
    int unks_22c;
    int unks_230;
    int unks_234;
    int unks_238;
    int unks_23c;
    int unks_240;
    int unks_244;
    int unks_248;
    int unks_24c;
    int unks_250;
    int unks_254;
    int unks_258;
    int unks_25c;
    int unks_260;
    int unks_264;
    int unks_268;
    int unks_26c;
    int unks_270;
    int unks_274;
    int unks_278;
    int unks_27c;
    int unks_280;
    int unks_284;
    int unks_288;
    int unks_28c;
    int unks_290;
    int unks_294;
    int unks_298;
    int unks_29c;
    int unks_2a0;
    int unks_2a4;
    int unks_2a8;
    int unks_2ac;
    int unks_2b0;
    int unks_2b4;
    int unks_2b8;
    int unks_2bc;
    int unks_2c0;
    int unks_2c4;
    int unks_2c8;
    int unks_2cc;
    int unks_2d0;
    int unks_2d4;
    int unks_2d8;
    int unks_2dc;
    int unks_2e0;
    int unks_2e4;
    int unks_2e8;
    int unks_2ec;
    int unks_2f0;
    int unks_2f4;
    int unks_2f8;
    int unks_2fc;
    int unks_300;
    int unks_304;
    int unks_308;
    int unks_30c;
    int unks_310;
    int unks_314;
    int unks_318;
    int unks_31c;
    int unks_320;
    int unks_324;
    int unks_328;
    int unks_32c;
    int unks_330;
    int unks_334;
    int unks_338;
    int unks_33c;
    int unks_340;
    int unks_344;
    int unks_348;
    int unks_34c;
    int unks_350;
    int unks_354;
    int unks_358;
    int unks_35c;
    int unks_360;
    int unks_364;
    int unks_368;
    int unks_36c;
    int unks_370;
    int unks_374;
    int unks_378;
    int unks_37c;
    int unks_380;
    int unks_384;
    int unks_388;
    int unks_38c;
    int unks_390;
    int unks_394;
    int unks_398;
    int unks_39c;
    int unks_3a0;
    int unks_3a4;
    int unks_3a8;
    int unks_3ac;
    int unks_3b0;
    int unks_3b4;
    int unks_3b8;
    int unks_3bc;
    int unks_3c0;
    int unks_3c4;
    int unks_3c8;
    int unks_3cc;
    int unks_3d0;
    int unks_3d4;
    int unks_3d8;
    int unks_3dc;
    int unks_3e0;
    int unks_3e4;
    int unks_3e8;
    int unks_3ec;
    int unks_3f0;
    int unks_3f4;
    int unks_3f8;
    int unks_3fc;
    int unks_400;
    int unks_404;
    int unks_408;
    int unks_40c;
    Sub410 sub410;
    CustomFlags FUN_0070c440();
};

class EffectItem
{
};

class TESSound
{
};

class TESSound;
class EffectSetting
{
public:
    ::TESSound *GetHitSound();
public:
    int GetArchetype();
};
// @fnv 0x0081a760
void ProjectileImpact::TriggerImpact(int aiUnused1, int aiUnused2, int aiUnused3, int aiUnused4, intptr_t aiEventArg,
                                     bool abSuppress)
{
    ProjectileFlags a = ((::ProjectileInfo *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440();
    reinterpret_cast<::FUN_00810f90_shell *>(&(a))->SetFlag4000(true);
    reinterpret_cast<::fnv_00810ff0::Ths810 *>((((::ProjectileInfo *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00810ff0(a.value);
    mode = 1;
    float b = (duration - elapsed) / duration;
    if (!abSuppress && b > 0.0)
    {
        reinterpret_cast<::P142Caster *>(reinterpret_cast<::MagicProjectileFields *>(this)->caster)->ApplySpellEffects((::P142Spell *)(reinterpret_cast<::MagicProjectileFields *>(this)->spell), (std::intptr_t)(((void *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), (*(::NiPoint3 *)&(const ::ImpactPoint &)(position())), (::P142Ref *)(void *)(this), (::P142Ref *)(aiEventArg), 0, b, 1.0f);
    }
    if (((::AreaSound *)(reinterpret_cast<::FUN_008ce390_shell *>((((::ProjectileEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_008ce390())) && !abSuppress)
    {
        unsigned e = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::AreaSound *)(reinterpret_cast<::FUN_008ce390_shell *>((((::ProjectileEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_008ce390()))))->FUN_0084e3a0()));
        ImpactHandle d = ((::ImpactAudio *)(::FUN_00453a70()))->FUN_00ad73b0(e, 0x102);
        ImpactPoint c = position();
        reinterpret_cast<::FUN_00ad8b60_h *>(&(d))->FUN_00ad8b60(c.x, c.y, c.z);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(d))->FUN_00ad8830(false);
    }
}
// @fnv 0x008ce610
void FUN_008ce610_owner::FUN_008ce610(int arg)
{

    reinterpret_cast<::FUN_00932070_MobileObject *>(this)->SaveProcess(arg);

    unsigned short idB = 0;

    unsigned short* pLength = 0;

    char* start = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;

    if (*(*reinterpret_cast<::SaveFlag *>(&::g_011de4e8)).FUN_00408d60())
    {

        start = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
    }

    if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {

        unsigned int magic = 0x424c4f4b;

        reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<TESSaveLoadGameHelper*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&magic, 4);

        pLength = reinterpret_cast<unsigned short*>(reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor);

        reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<TESSaveLoadGameHelper*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&idB, 2);
    }

    reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<TESSaveLoadGameHelper*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&unk8c, 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unk90, 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unk94, 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unk98, 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unk9c, 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unka0, 4);

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unkb4, 12);

    unsigned int hasState = 0;

    if (unka4)
        hasState = reinterpret_cast<::FUN_0084e3a0_Class *>((unka4))->FUN_0084e3a0();

    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&hasState), 4);

    unsigned int idA = 0;

    if (unka8)
        idA = reinterpret_cast<::FUN_0084e3a0_Class *>((unka8))->FUN_0084e3a0();

    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&idA), 4);

    unsigned int blockLength = 0;

    if (unkb0)
        blockLength = reinterpret_cast<::FUN_0084e3a0_Class *>((unkb0))->FUN_0084e3a0();

    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&blockLength), 4);

    bool idC = false;

    if (pMotionState)
        idC = true;

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&idC, 1);

    if (idC)
    {

        reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<TESSaveLoadGameHelper*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(pMotionState, 4);

        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&pMotionState->origin, 12);

        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&pMotionState->axis, 12);

        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&pMotionState->velocity, 12);

        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x50)
        {

            FourInts transform;


            reinterpret_cast<::NiQuaternion *>(&(transform))->FromRotationMatrix(
                (*(const ::ThreeByThreeMatrix *)(&pMotionState->extended)));

            reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<TESSaveLoadGameHelper*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&transform, 16);
        }

        if (pMotionState->type == 1 ||
            pMotionState->type == 0)
        {

            unsigned int handleID = 0;

            if (pMotionState->handle)
                handleID = reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<SaveHandle*>(
                               pMotionState->handle)))->FUN_0084e3a0();

            reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&handleID), 4);

            unsigned short low = 0;

            short high = -1;

            if (pMotionState->handle &&
                pMotionState->packed)
            {

                if (this->unkc0 == 0)
                {

                    bool invert =
                        pMotionState->type == 0;

                    low = ((unsigned short)(::CountCollisionObjects((::NiAVObject *)(((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((pMotionState
                                           ->handle))->FUN_0043fcd0()))),
                                       invert, invert, 1)));

                    int prepared = ((int)(::FUN_004a8b00(
                        (::BGSBodyPart *)(pMotionState->packed))));

                    high = ((unsigned short)(::FilterByFlags((void *)(((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((pMotionState
                                             ->handle))->FUN_0043fcd0()))),
                                         prepared, invert, invert, 1)));
                }
                else
                {

                    unsigned int packedValue =
                        pMotionState->packed;

                    low = static_cast<unsigned short>(packedValue >> 16);

                    high = static_cast<unsigned short>((packedValue << 16) >> 16);
                }
            }

            reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&low, 2);

            reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&high, 2);
        }
    }

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x54)
    {

        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&this->unkc1, 1);
    }

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x55)
    {

        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&this->unkc2, 1);
    }

    if (*(*reinterpret_cast<::SaveFlag *>(&::g_011de4e8)).FUN_00408d60())
    {

        char* info = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;

        unsigned int* finished =
            static_cast<unsigned int*>(((void *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->GetHitSound())));

        if (finished)
        {

            intptr_t manager = ((intptr_t)(::FUN_004839c0(*finished)));

            typedef int(* LogFunction)(void*);

            ::FUN_0040fbe0();
        }
        else
        {

            ::FUN_0040fbe0();
        }
    }

    if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {

        char* lengthFieldPointer = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;

        unsigned short* info = pLength;

        if (lengthFieldPointer > reinterpret_cast<char*>(info) + 0xffffU)
        {

            ::FUN_005b5e40();
        }

        *pLength = static_cast<unsigned short>(lengthFieldPointer - reinterpret_cast<char*>(info));
    }
}
// Computes the serialized save size of an ArrowSave, adding field sizes conditionally on save version and projectile type, and logs the result.
// @fnv 0x008ce3b0
unsigned short ArrowSave::FUN_008ce3b0(unsigned flags)
{
    unsigned short size7 = 0;
    size7 += reinterpret_cast<::FUN_00931ff0_shell *>(this)->FUN_00931ff0(flags);
    unsigned short start = size7;
    if (reinterpret_cast<::FUN_00862110_cls *>((((SaveState*)g_TESSaveLoadGame)))->FUN_00862110())
    {
        size7 += 4;
        size7 += 2;
    }
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 12;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    bool present = false;
    if (data != 0)
        present = true;
    size7 += 1;
    if (present)
    {
        size7 += 4;
        size7 += 12;
        size7 += 12;
        size7 += 12;
        if (reinterpret_cast<::FUN_008df040_shell *>((((SaveState*)g_TESSaveLoadGame)))->FUN_008df040() >= 80)
            size7 += 16;
        if (data->type == 1 || data->type == 0)
        {
            size7 += 4;
            size7 += 2;
            size7 += 2;
        }
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((((SaveState*)g_TESSaveLoadGame)))->FUN_008df040() >= 84)
        size7 += 1;
    if (reinterpret_cast<::FUN_008df040_shell *>((((SaveState*)g_TESSaveLoadGame)))->FUN_008df040() >= 85)
        size7 += 1;
    if (*(*reinterpret_cast<::SaveSetting *>(&::g_011de4e8)).Bool())
    {
        ValueReferencePair* entry = ((::ValueReferencePair *)(reinterpret_cast<::EffectSetting *>((((SaveState*)g_TESSaveLoadGame)))->GetHitSound()));
        if (entry)
        {
            SaveForm* form = ((::SaveForm *)(::FUN_004839c0(entry->id)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size7;
}

struct NodeEffect
{
};

struct ContinuousBeamProjectile
{
    virtual void vfp_000();
    virtual void vfp_001();
    virtual void vfp_002();
    virtual void vfp_003();
    virtual void vfp_004();
    virtual void vfp_005();
    virtual void vfp_006();
    virtual void vfp_007();
    virtual void vfp_008();
    virtual void vfp_009();
    virtual void vfp_010();
    virtual void vfp_011();
    virtual void vfp_012();
    virtual void vfp_013();
    virtual void vfp_014();
    virtual void vfp_015();
    virtual void vfp_016();
    virtual void vfp_017();
    virtual void vfp_018();
    virtual void vfp_019();
    virtual void vfp_020();
    virtual void vfp_021();
    virtual void vfp_022();
    virtual void vfp_023();
    virtual void vfp_024();
    virtual void vfp_025();
    virtual void vfp_026();
    virtual void vfp_027();
    virtual void vfp_028();
    virtual void vfp_029();
    virtual void vfp_030();
    virtual void vfp_031();
    virtual void vfp_032();
    virtual void vfp_033();
    virtual void vfp_034();
    virtual void vfp_035();
    virtual void vfp_036();
    virtual void vfp_037();
    virtual void vfp_038();
    virtual void vfp_039();
    virtual void vfp_040();
    virtual void vfp_041();
    virtual void vfp_042();
    virtual void vfp_043();
    virtual void vfp_044();
    virtual void vfp_045();
    virtual void vfp_046();
    virtual void vfp_047();
    virtual void vfp_048();
    virtual void vfp_049();
    virtual void vfp_050();
    virtual void vfp_051();
    virtual void vfp_052();
    virtual void vfp_053();
    virtual void vfp_054();
    virtual void vfp_055();
    virtual void vfp_056();
    virtual void vfp_057();
    virtual void vfp_058();
    virtual void vfp_059();
    virtual void vfp_060();
    virtual void vfp_061();
    virtual void vfp_062();
    virtual void vfp_063();
    virtual void vfp_064();
    virtual void vfp_065();
    virtual void vfp_066();
    virtual void vfp_067();
    virtual void vfp_068();
    virtual void vfp_069();
    virtual void vfp_070();
    virtual void vfp_071();
    virtual void vfp_072();
    virtual void vfp_073();
    virtual void vfp_074();
    virtual void vfp_075();
    virtual void vfp_076();
    virtual void vfp_077();
    virtual void vfp_078();
    virtual void vfp_079();
    virtual void vfp_080();
    virtual void vfp_081();
    virtual void vfp_082();
    virtual void vfp_083();
    virtual void vfp_084();
    virtual void vfp_085();
    virtual void vfp_086();
    virtual void vfp_087();
    virtual void vfp_088();
    virtual void vfp_089();
    virtual void vfp_090();
    virtual void vfp_091();
    virtual void vfp_092();
    virtual void vfp_093();
    virtual void vfp_094();
    virtual void vfp_095();
    virtual void vfp_096();
    virtual void vfp_097();
    virtual void vfp_098();
    virtual void vfp_099();
    virtual void vfp_100();
    virtual void vfp_101();
    virtual void vfp_102();
    virtual void vfp_103();
    virtual void vfp_104();
    virtual void vfp_105();
    virtual void vfp_106();
    virtual void vfp_107();
    virtual void vfp_108();
    virtual void vfp_109();
    virtual void vfp_110();
    virtual void vfp_111();
    virtual void vfp_112();
    virtual void vfp_113();
    virtual void vfp_114();
    virtual void vfp_115();
    virtual NiNodeStandin* Root();
    virtual void vfp_117();
    virtual void vfp_118();
    virtual void vfp_119();
    virtual void vfp_120();
    virtual void vfp_121();
    virtual void vfp_122();
    virtual void vfp_123();
    virtual void vfp_124();
    virtual NiPoint3* Position();
    virtual void vfp_126();
    virtual void vfp_127();
    virtual void vfp_128();
    virtual void vfp_129();
    virtual void vfp_130();
    virtual void vfp_131();
    virtual void vfp_132();
    virtual void vfp_133();
    virtual void vfp_134();
    virtual void vfp_135();
    virtual void vfp_136();
    virtual void vfp_137();
    virtual void vfp_138();
    virtual void vfp_139();
    virtual void vfp_140();
    virtual void vfp_141();
    virtual void vfp_142();
    virtual void vfp_143();
    virtual void vfp_144();
    virtual void vfp_145();
    virtual void vfp_146();
    virtual void vfp_147();
    virtual void vfp_148();
    virtual void vfp_149();
    virtual void vfp_150();
    virtual void vfp_151();
    virtual void vfp_152();
    virtual void vfp_153();
    virtual void vfp_154();
    virtual void vfp_155();
    virtual void vfp_156();
    virtual void vfp_157();
    virtual void vfp_158();
    virtual void vfp_159();
    virtual void vfp_160();
    virtual void vfp_161();
    virtual void vfp_162();
    virtual void vfp_163();
    virtual void vfp_164();
    virtual void vfp_165();
    virtual void vfp_166();
    virtual void vfp_167();
    virtual void vfp_168();
    virtual void vfp_169();
    virtual void vfp_170();
    virtual void vfp_171();
    virtual void vfp_172();
    virtual void vfp_173();
    virtual void vfp_174();
    virtual void vfp_175();
    virtual void vfp_176();
    virtual void vfp_177();
    virtual void vfp_178();
    virtual void vfp_179();
    virtual void vfp_180();
    virtual void vfp_181();
    virtual void vfp_182();
    virtual void vfp_183();
    virtual void vfp_184();
    virtual void vfp_185();
    virtual void vfp_186();
    virtual void vfp_187();
    virtual void vfp_188();
    virtual void vfp_189();
    virtual void vfp_190();
    virtual void vfp_191();
    virtual void vfp_192();
    virtual void vfp_193();
    virtual void vfp_194();
    virtual void vfp_195();
    virtual void v310();
    int unkp_004;
    int unkp_008;
    int unkp_00c;
    int unkp_010;
    int unkp_014;
    int unkp_018;
    int unkp_01c;
    int unkp_020;
    int unkp_024;
    int unkp_028;
    int unkp_02c;
    int unkp_030;
    int unkp_034;
    int unkp_038;
    int unkp_03c;
    int unkp_040;
    int unkp_044;
    int unkp_048;
    int unkp_04c;
    int unkp_050;
    int unkp_054;
    int unkp_058;
    int unkp_05c;
    int unkp_060;
    int unkp_064;
    int unkp_068;
    int unkp_06c;
    int unkp_070;
    int unkp_074;
    int unkp_078;
    int unkp_07c;
    int unkp_080;
    int unkp_084;
    int unkp_088;
    int unkp_08c;
    int unkp_090;
    int unkp_094;
    int unkp_098;
    int unkp_09c;
    int unkp_0a0;
    int unkp_0a4;
    int unkp_0a8;
    int unkac;
    float unkb0;
    Sound sound;
    NodeEffect* effect;


    void ApplyAreaEffect(NiPoint3 point, unsigned int variant, TESObjectREFR* target, bool silent);
};

// @fnv 0x00810aa0
void ContinuousBeamProjectile::ApplyAreaEffect(NiPoint3 point, unsigned int variant, TESObjectREFR* target, bool silent)
{
    ActorTarget* pActor2 = (target && ((ActorTarget*)target)->IsActor()) ? (ActorTarget*)target : 0;
    if (pActor2 && reinterpret_cast<::FUN_008ace90_shell *>((pActor2))->FUN_008ace90())
        return;

    this->unkb0 = (float)((double)reinterpret_cast<::FUN_00404420_shell *>((((::EffectItem *)(reinterpret_cast<::InterfaceManager *>((this))->FUN_00586150()))))->FUN_00404420() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1137)))))));
    if (this->unkb0 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1138)))))))
    {
        this->unkb0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1138))))));
    }
    else if (this->unkb0 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1139)))))))
    {
        this->unkb0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1139))))));
    }

    reinterpret_cast<::Reference *>((this))->FUN_00575830((::Position *)(&point));

    NiNodeStandin* pNode2 = this->Root();
    if (pNode2)
    {
        reinterpret_cast<::ImpactOwner *>((this))->FUN_0081f000((*(float *)&(const ::NiPoint3 &)(point)), (*(float *)&(const ::NiPoint3 &)(((::PointProvider *)(::FUN_00461130((intptr_t)(pNode2))))->FUN_004b4500(DAT_011a9478))), variant, {}, {}, {}, {});
    }

    if (pNode2 && !silent)
    {
        reinterpret_cast<::FUN_00440460_S *>((pNode2))->FUN_00440460((const ::V3 *)&(point));
        NiAVObject* effect20 = pNode2->GetObjectByName(NiFixedString("AreaEffect"));
        if (effect20)
        {
            reinterpret_cast<::FUN_00440490_shell *>((effect20))->FUN_00440490(this->unkb0);
        }
    }

    if (reinterpret_cast<::SoundPlaybackHandle *>(&(this->sound))->IsValid())
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(this->sound))->FUN_00ad88f0();

    if (((::ProjectileNodeStandin *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((this))->FUN_009306d0())) && !silent)
    {
        if (((int)(reinterpret_cast<::bhkCharacterListener *>(&(((::ProjectileNodeStandin *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((this))->FUN_009306d0()))->sub410))->FUN_00621270(0x8000))))
        {
            this->v310();
        }
        CustomFlags aFlags3 = ((::ProjectileNodeStandin *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((this))->FUN_009306d0()))->FUN_0070c440();
        reinterpret_cast<::FUN_00810f90_shell *>(&(aFlags3))->SetFlag4000(true);
        reinterpret_cast<::fnv_00810ff0::Ths810 *>((((::ProjectileNodeStandin *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((this))->FUN_009306d0()))))->FUN_00810ff0(aFlags3.value);
    }

    this->unkac = 2;
    if (!silent)
    {
        reinterpret_cast<::P142Caster *>(reinterpret_cast<::MagicProjectileFields *>(this)->caster)->ApplySpellEffects((::P142Spell *)(reinterpret_cast<::MagicProjectileFields *>(this)->spell), (std::intptr_t)(((void *)(reinterpret_cast<::LowProcess *>((this))->GetTarget()))),
                                                (*(::NiPoint3 *)&(const ::ImpactPoint &)(*(ImpactPoint*)this->Position())), (::P142Ref *)(void *)(this), (::P142Ref *)(target), 0, 1.0f, 1.0f);
    }

    NiAVObject* pRoot4 = this->Root();
    NiTimeController* pCtrl5 = pRoot4 ? ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(pRoot4)))) : 0;
    NiControllerManager* pManagerTmp = (NiControllerManager*)FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), pCtrl5);
    if (pManagerTmp)
    {
        CustomSequence* aPSeq5 = (CustomSequence*)((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pManagerTmp))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("SpecialIdle_AreaEffect")))));
        if (aPSeq5)
        {
            pManagerTmp->DeactivateAllSequences(0.0f);
            pManagerTmp->ActivateControllerSequence((NiControllerSequence*)aPSeq5, 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((pManagerTmp))->QueueReferenceStateTask(true);
            reinterpret_cast<::FUN_0098adb0_shell *>((aPSeq5))->FUN_0098adb0(-DAT_0107a510);
            if (this->effect)
            {
                reinterpret_cast<::FUN_0081c470_shell *>((this->effect))->FUN_0081c470(false, (float)(reinterpret_cast<::FUN_00508100_shell *>((aPSeq5))->FUN_00508100() * DAT_0101de30));
            }
        }
    }

    if (reinterpret_cast<::FUN_008ce390_shell *>((reinterpret_cast<::MagicProjectile *>((this))->FUN_004fd400()))->FUN_008ce390() && !silent)
    {
        unsigned int soundID3 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<::FUN_008ce390_shell *>((reinterpret_cast<::MagicProjectile *>((this))->FUN_004fd400()))->FUN_008ce390()))->FUN_0084e3a0()));
        ImpactHandle handleA = ((::ImpactAudio *)(::FUN_00453a70()))->FUN_00ad73b0(soundID3, 0x102);
        NiPoint3 aEPos = *this->Position();
        reinterpret_cast<::FUN_00ad8b60_h *>(&(handleA))->FUN_00ad8b60(aEPos.x, aEPos.y, aEPos.z);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(handleA))->FUN_00ad8830(false);
    }
}

struct NiRTTI;
struct Val
{
};
struct Sub;
struct MyCtrl
{
};
struct AVNode : public NiAVObject
{
};
struct AVObj
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
    virtual AVNode* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
};
struct Proc
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void v453();
    virtual void v454();
    virtual void v455();
    virtual void v456();
    virtual void v457();
    virtual void v458();
    virtual void v459();
    virtual void v460();
    virtual void v461();
    virtual void v462();
    virtual void v463();
    virtual void v464();
    virtual void v465(int);
    virtual Val* v466();
    virtual void v467(int);
    virtual unsigned int v468();
};

struct Host
{
    int fld00;
    int fld01;
    int fld02;
    int fld03;
    int fld04;
    int fld05;
    int fld06;
    int fld07;
    int fld08;
    int fld09;
    int fld10;
    int fld11;
    int fld12;
    int fld13;
    int fld14;
    int fld15;
    int fld16;
    int fld17;
    int fld18;
    int fld19;
    int fld20;
    int fld21;
    int fld22;
    int fld23;
    int fld24;
    int fld25;
    int fld26;
    AVObj* m6c;
    void FUN_00936b20(int);
};

// If active, finds the controller and sequence for the global time, advances the sequence by the elapsed time, and updates the node.
// @fnv 0x00936b20
void Host::FUN_00936b20(int aiUnused)
{
    if (((bool)(::FUN_00574900((const unsigned char *)this))))
    {
        AVObj* pSceneObject = m6c;
        if (pSceneObject->v116())
        {
            MyCtrl* pkCtrl = reinterpret_cast<::MyHost *>((pSceneObject->v116()))->FUN_00a5c570((const ::MyRTTI *)(::NiRTTI *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))));
            if (pkCtrl)
            {
                Sub* pkSeq = ((::Sub *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkCtrl))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(void *)(((void *)(::fnv_00935ef0::FUN_00935ef0()))))));
                if (pkSeq)
                {
                    unsigned int uiDiff = 0;
                    if (::fnv::timer::Time() > ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v468())
                        uiDiff = (::fnv::timer::Time() - ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v468()) / 33;
                    if (((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v466())
                    {
                        float fWeight = reinterpret_cast<::Spectrum4d50 *>((((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v466()))->FUN_004d50e0(uiDiff);
                        if (fWeight < (double)0.01f)
                            fWeight = 0.01f;
                        ::fnv_0049bf10::SetSequenceProgress(fWeight, (::fnv_0049bf10::ManagerStub *)(pkCtrl), (::fnv_0049bf10::SeqStub *)(pkSeq));
                        if (uiDiff > ((unsigned int)(::FUN_00559450((int *)(((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v466())))))
                        {
                            ::fnv_0049bf10::SetSequenceProgress(0.0f, (::fnv_0049bf10::ManagerStub *)(pkCtrl), (::fnv_0049bf10::SeqStub *)(pkSeq));
                            reinterpret_cast<::NiControllerManager *>((pkCtrl))->StopSequence((::NiControllerSequence *)(pkSeq), 0.0f);
                            ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v465(0);
                            ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v467(0);
                        }
                        else
                        {
                            ::fnv_0049bf10::SetSequenceProgress(fWeight, (::fnv_0049bf10::ManagerStub *)(pkCtrl), (::fnv_0049bf10::SeqStub *)(pkSeq));
                        }
                    }
                }
            }
            m6c->v120();
            NiUpdateData uData((float)((double)::fnv::timer::Time() / 1000.0), true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((pSceneObject->v116()))->FUN_00a59c60((std::intptr_t)&(uData));
        }
    }
}

namespace s5722c0 {

struct Form;


class Actor
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
    virtual bool IsReady();

    bool FUN_005722c0(int iUnused);
};

// @fnv 0x005722c0
bool Actor::FUN_005722c0(int iUnused)
{
    bool bResult = false;
    if (IsReady() && reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() != 7)
    {
        float fValue = ::TESHealthForm::GetBaseHealth((::TESForm *)(::s5722c0::Form *)(((::s5722c0::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))));
        if (fValue <= 0.0)
            bResult = true;
    }
    else if (reinterpret_cast<::FUN_00477ba0_shell *>(this)->FUN_00477ba0())
    {
        bResult = true;
    }
    return bResult;
}

}

#include <xmmintrin.h>
// Destruction of the reference and its transient physics/actor state.
extern int DAT_01085954, DAT_01085948;
extern int DAT_011dfc98;
struct __declspec(align(16)) CleanupVector
{
    __m128 components;
};
struct CleanupWorld
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
    virtual void GetAudioPosition(CleanupVector&);
};
struct CleanupCollision
{
};
struct CleanupProcess
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void RemoveReference(void*);
};
struct CleanupActor
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
    virtual bool IsActor();
};
struct CleanupData
{
    int kind;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    CleanupActor* actor;
    void* worldHandle;
};
struct FUN_0092ec40
{
    virtual void Primary();
    int unk04, unk08, unk0c, unk10, unk14;
    ~FUN_0092ec40();
};
struct CleanupSecondary
{
    virtual void Secondary();
};
struct CleanupReference : FUN_0092ec40, CleanupSecondary
{
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    CleanupData* data;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    bool detached;
};
struct CleanupList
{
};
struct CleanupManager
{
};
struct CleanupHandler
{
};
struct FUN_008cac60 : CleanupReference
{
    virtual ~FUN_008cac60();
};
// @fnv 0x008cac30
void* FUN_008cac30_shell::FUN_008cac30(unsigned int flags)
{
    reinterpret_cast<::FUN_008cac60 *>(this)->FUN_008cac60::~FUN_008cac60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x008cac60
FUN_008cac60::~FUN_008cac60()
{
    --DAT_011dfc98;
    CleanupList* pCleanupList = ((::CleanupList *)(reinterpret_cast<::FUN_004610f0_Class *>((reinterpret_cast<CleanupManager*>(&(*reinterpret_cast<::Mgr *>(&::g_011e0e80)))))->GetOffset70Ptr()));
    if (pCleanupList)
    {
        FUN_0092ec40* reference = this;
        reinterpret_cast<::ItemChangeListNode *>((pCleanupList))->FUN_00905330((::InventoryStackRecord *const &)(reference));
    }
    void* scene = ((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()));
    if (scene && data && data->kind == 1)
    {
        CleanupCollision* collision = reinterpret_cast<CleanupCollision*>(((::CollObj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(scene)))));
        CleanupWorld* world = collision ? ((::CleanupWorld *)(::fnv_006fa820::FUN_006fa820((const char *)(collision)))) : 0;
        if (world)
        {
            CleanupVector audioVector;
            world->GetAudioPosition(audioVector);
            ::fnv_0062ab60::FUN_0062ab60((const ::fnv_0062ab60::hkVector4V &)(audioVector), data->worldHandle);
        }
    }
    if (!detached && data && data->kind == 0 && data->actor && data->actor->IsActor())
    {
        CleanupActor* actor = data->actor;
        if (actor && ((::CleanupProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
        {
            CleanupProcess* process = ((::CleanupProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()));
            process->RemoveReference(this);
        }
    }
    delete data;
    reinterpret_cast<::Ref3 *>(this)->FUN_005702e0((::Obj3 *)(void *)(0), true);
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::CleanupHandler * *>(&::g_dataHandler))))->FUN_004226e0())
        reinterpret_cast<::fnv_0092ed60::FNVCurrent *>(this)->FUN_0092ed60(false);
}

namespace fnv_008112c0 {
struct EffB
{
};
struct EffA
{
};
struct Handle
{
    int h00;
    int h04;
    int h08;
};
struct V116
{
};
struct C0Obj
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    C0Obj(int, void*);
};
struct Ret8d
{
};
struct Obj30
{
    int o00;
    int o04;
    int o08;
    ~Obj30();
};
struct StrObj
{
    int s00;
    StrObj(const char*);
    ~StrObj();
};
struct Obj1c
{
};
struct Obj24
{
};

struct Cls8112c0
{
    virtual void virt_000();
    virtual void virt_001();
    virtual void virt_002();
    virtual void virt_003();
    virtual void virt_004();
    virtual void virt_005();
    virtual void virt_006();
    virtual void virt_007();
    virtual void virt_008();
    virtual void virt_009();
    virtual void virt_010();
    virtual void virt_011();
    virtual void virt_012();
    virtual void virt_013();
    virtual void virt_014();
    virtual void virt_015();
    virtual void virt_016();
    virtual void virt_017();
    virtual void virt_018();
    virtual void virt_019();
    virtual void virt_020();
    virtual void virt_021();
    virtual void virt_022();
    virtual void virt_023();
    virtual void virt_024();
    virtual void virt_025();
    virtual void virt_026();
    virtual void virt_027();
    virtual void virt_028();
    virtual void virt_029();
    virtual void virt_030();
    virtual void virt_031();
    virtual void virt_032();
    virtual void virt_033();
    virtual void virt_034();
    virtual void virt_035();
    virtual void virt_036();
    virtual void virt_037();
    virtual void virt_038();
    virtual void virt_039();
    virtual void virt_040();
    virtual void virt_041();
    virtual void virt_042();
    virtual void virt_043();
    virtual void virt_044();
    virtual void virt_045();
    virtual void virt_046();
    virtual void virt_047();
    virtual void virt_048();
    virtual void virt_049();
    virtual void virt_050();
    virtual void virt_051();
    virtual void virt_052();
    virtual void virt_053();
    virtual void virt_054();
    virtual void virt_055();
    virtual void virt_056();
    virtual void virt_057();
    virtual void virt_058();
    virtual void virt_059();
    virtual void virt_060();
    virtual void virt_061();
    virtual void virt_062();
    virtual void virt_063();
    virtual void virt_064();
    virtual void virt_065();
    virtual void virt_066();
    virtual void virt_067();
    virtual void virt_068();
    virtual void virt_069();
    virtual void virt_070();
    virtual void virt_071();
    virtual void virt_072();
    virtual void virt_073();
    virtual void virt_074();
    virtual void virt_075();
    virtual void virt_076();
    virtual void virt_077();
    virtual void virt_078();
    virtual void virt_079();
    virtual void virt_080();
    virtual void virt_081();
    virtual void virt_082();
    virtual void virt_083();
    virtual void virt_084();
    virtual void virt_085();
    virtual void virt_086();
    virtual void virt_087();
    virtual void virt_088();
    virtual void virt_089();
    virtual void virt_090();
    virtual void virt_091();
    virtual void virt_092();
    virtual void virt_093();
    virtual void virt_094();
    virtual void virt_095();
    virtual void virt_096();
    virtual void virt_097();
    virtual void virt_098();
    virtual void virt_099();
    virtual void virt_100();
    virtual void virt_101();
    virtual void virt_102();
    virtual void virt_103();
    virtual void virt_104();
    virtual void virt_105();
    virtual void virt_106();
    virtual void virt_107();
    virtual void virt_108();
    virtual void virt_109();
    virtual void virt_110();
    virtual void virt_111();
    virtual void virt_112();
    virtual void virt_113();
    virtual void virt_114();
    virtual void virt_115();
    virtual V116* virt_116();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int m_ac;
    float m_b0;
    Handle m_b4;
    C0Obj* m_c0;
    Obj30 PlaySoundByFormID(int, int, int, int);
    void FUN_008112c0(int, int);
};

// Calls FUN_0081ea40 and FUN_0080fcf0, updates m_b4 from an Obj30 result, and may allocate C0Obj using the named SpecialIdle_AreaEffect entry.
// @fnv 0x008112c0
void Cls8112c0::FUN_008112c0(int aiParam1, int aiParam2)
{
    float f10;
    reinterpret_cast<::fnv_0081ea40::MagicProjectile *>(this)->ResolveMagicReferences(aiParam1, aiParam2);
    reinterpret_cast<::TESObjectREFR *>(this)->ResetProjectileIdleAnimation();
    reinterpret_cast<::CellView *>((((::fnv_008112c0::Ret8d *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230({}, {});
    if (m_ac != 2)
    {
        if (((::fnv_008112c0::EffB *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::fnv_008112c0::EffA *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
        {
            int v14;
            v14 = reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_008112c0::EffB *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::fnv_008112c0::EffA *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0();
            if (((unsigned char)(reinterpret_cast<::SoundPlaybackHandle *>(&(m_b4))->IsValid())))
            {
                reinterpret_cast<::SoundPlaybackHandle *>(&(m_b4))->Release();
            }
            {
                Obj30 sound = PlaySoundByFormID(v14, 1, 0x40000102, 1);
                reinterpret_cast<::SoundPlaybackHandle *>(&(m_b4))->operator=((*(const ::SoundPlaybackHandle *)(&sound)));
            }
        }
    }
    if (virt_116())
    {
        reinterpret_cast<::FUN_00440490_shell *>((virt_116()))->FUN_00440490(m_b0);
    }
    ::__memcpy(&f10, &m_c0, 4);
    m_c0 = 0;
    if (virt_116())
    {
        if (((::fnv_008112c0::EffB *)(reinterpret_cast<::FUN_004fd380_shell *>((((::fnv_008112c0::EffA *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_004fd380())))
        {
            m_c0 = new C0Obj(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_008112c0::EffB *)(reinterpret_cast<::FUN_004fd380_shell *>((((::fnv_008112c0::EffA *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_004fd380()))))->FUN_0084e3a0(), virt_116());
            if (m_ac == 2 && m_c0 != 0)
            {
                V116* v20;
                intptr_t t18;
                Obj1c* foundEffect;
                intptr_t result;
                v20 = virt_116();
                t18 = v20 ? ((intptr_t)(::fnv_0043b230::FUN_0043b230((const char *)(v20)))) : 0;
                foundEffect = (Obj1c*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f36ac))), (::NiObject *)(t18))));
                if (foundEffect)
                {
                    StrObj idleName("SpecialIdle_AreaEffect");
                    result = ((int)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((foundEffect))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::fnv_008112c0::StrObj *)(&idleName))));
                    if (result)
                    {
                        reinterpret_cast<::FUN_0081c470_shell *>((m_c0))->FUN_0081c470(0, reinterpret_cast<::FUN_00508100_shell *>((((Obj24*)result)))->FUN_00508100() * ::DAT_0101de30);
                        reinterpret_cast<::FUN_00621b20_Class *>((m_c0))->FUN_00621b20(f10);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_008112c0

namespace fnv_008cb3c0 {
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3(float, float, float);
    Vec3 operator-(const Vec3&) const;
};
struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct RefObject
{
};
struct TrackedHandle
{
    int kind;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    RefObject* target;
};
struct NiUpdateData
{
    float time;
    int flags;
    int unk8;
    NiUpdateData(float, bool, bool);
};
struct PackageNodeHandler
{
};
struct MotionController
{
};
struct SaveService
{
};
struct Clock
{
};
struct MainState
{
};


struct Controller
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
    virtual void v27(void*, int);
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
    virtual void v49(int);
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
    virtual struct PackageNodeHandler* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual struct Vec3* v125();
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
    virtual void v148(float, struct Vec3*, int);

    int unk4;
    int unk8;
    int unkc;
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
    TrackedHandle* handle;
    int phase;
    float fadeLeft, elapsed, velocity, acceleration, lifetime;
    int unkA4, unkA8, unkAC, unkB0;
    Vec3 lastDirection;
    unsigned char pending;
    unsigned char unkC1, unkC2, unkC3;
    void* releaseData;

    void FUN_008cb3c0(float dt);
};

// Updates elapsed time, position, orientation, and fadeLeft, with phase-dependent calls to v27, v49, and other handlers.
// @fnv 0x008cb3c0
void Controller::FUN_008cb3c0(float afDelta)
{
    if (pending)
    {
        bool shouldRelease = true;
        if (handle && (handle->kind == 1 || handle->kind == 0) && handle->target)
        {
            if (!((reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((handle->target))->FUN_0043fcd0())))
            {
                shouldRelease = false;
            }
        }
        if (shouldRelease)
        {
            pending = 0;
            v27(releaseData, 0);
            reinterpret_cast<::B5F750Owner *>((reinterpret_cast<SaveService*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->DetachProjectiles();
        }
    }
    PackageNodeHandler* actor = v116();
    if (afDelta >= ::_DAT_01012060)
    {
        elapsed = elapsed + afDelta;
        if (elapsed > *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008cb3c0::Clock *>(&::originalRuntimeFloatSetting648)))))))
        {
            phase = 3;
        }
        if (reinterpret_cast<::FUN_00440d80_shell *>(this)->FUN_00440d80())
        {
            return;
        }
        if (phase == 0 && ((::fnv_008cb3c0::MotionController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
        {
            Vec3 delta_pos(0.0f, velocity * afDelta, 0.0f);
            Vec3 oldPosition = *v125();
            if (((double)(::FUN_004587d0(reinterpret_cast<::FUN_00810a80_shell *>((((::fnv_008cb3c0::MotionController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->GetFloatAtOffset53C()))) >= v125()->z)
            {
                float stepScale = (lifetime - 1.0f * afDelta) / lifetime;
                velocity = velocity * stepScale;
                acceleration = acceleration * stepScale;
                reinterpret_cast<::FUN_008106b0_Class *>((((::fnv_008cb3c0::MotionController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_008106b0(stepScale);
                lifetime = lifetime - 1.0f * afDelta;
                if (lifetime < ::DAT_01011588)
                {
                    reinterpret_cast<::fnv_008ccfb0::xActor *>(this)->FUN_008ccfb0(0);
                    reinterpret_cast<::ArrowProjectile *>(this)->ProcessImpact();
                }
            }
            v148(afDelta, &delta_pos, 15);
            if (phase != 0)
            {
                int phase3 = (phase == 3) + 2;
                if (reinterpret_cast<::ArrowProjectile *>(this)->ProcessImpact())
                {
                    if (actor)
                    {
                        reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(&(reinterpret_cast<::NiAVObject *>((actor))->FUN_0043c490())));
                    }
                    phase = phase3;
                    return;
                }
            }
            Vec3 vPos = *v125();
            if (actor)
            {
                reinterpret_cast<::FUN_00440460_S *>((actor))->FUN_00440460((const ::V3 *)(::fnv_008cb3c0::Vec3 *)(&vPos));
                FloatMatrix3 rot = *((::fnv_008cb3c0::FloatMatrix3 *)(::FUN_006a9540((char *)(actor))));
                float roll, pitchNew, yawVal;
                reinterpret_cast<::RotationMatrix *>(&(rot))->FUN_00a59400((*(float *)(&roll)), (*(float *)(&pitchNew)), (*(float *)(&yawVal)));
                lastDirection = vPos - oldPosition;
                float dirZ_ = lastDirection.z;
                float len = reinterpret_cast<::NiPoint3 *>(&(lastDirection))->ComputeMagnitude();
                pitchNew = -::FUN_004b54c0(dirZ_ / len);
                reinterpret_cast<::FUN_00a59660_cls *>(&(rot))->FUN_00a59660(roll, pitchNew, yawVal);
                reinterpret_cast<::FUN_0043fa80_s *>((actor))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rot)));
            }
        }
        else if (phase == 2 && handle)
        {
            int ref_kind = handle->kind;
            if (actor && ref_kind == 0)
            {
                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::FUN_0045bb80((intptr_t)(actor))));
                intptr_t refIndex = 0;
                if (handle->target)
                {
                    refIndex = ((intptr_t)(reinterpret_cast<::LowProcess *>((handle->target))->GetTarget()));
                }
                if (refIndex != ((intptr_t)(reinterpret_cast<::LowProcess *>(this)->GetTarget())))
                {
                    if (!refIndex)
                    {
                        v49(1);
                    }
                    else
                    {
                        reinterpret_cast<::ProcessLists *>((reinterpret_cast<MainState*>(&(*reinterpret_cast<::Mgr *>(&::g_011e0e80)))))->AddMobileObjectToList((::MobileObject *)(void *)(this));
                    }
                }
            }
            if (actor && ref_kind == 1 && (!handle || !handle->target || !((reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((handle->target))->FUN_0043fcd0()))))
            {
                v49(1);
            }
        }
        else if (phase == 3)
        {
            fadeLeft -= afDelta / ::DAT_01021928;
            if (fadeLeft <= ::_DAT_01012060)
            {
                fadeLeft = 0.0f;
                v49(1);
            }
            if (actor)
            {
                ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(actor), fadeLeft);
            }
        }
    }
    if (actor)
    {
        NiUpdateData updateInfo(afDelta, 1, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((actor))->FUN_00a59c60((std::intptr_t)(&updateInfo));
    }
}
}  // namespace fnv_008cb3c0

namespace fnv_009ae5d0 {
struct ItemA4
{
    int field0;
};

struct ListA4
{
    bool FUN_008256d0();
};

struct FUN_008d0600_s
{
};

struct FUN_004e3cc0_Class
{
};

struct FUN_009ae5d0_shell
{
    int unk00[36];
    float f90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    ListA4 listA4;
    int unka8[11];
    char padD4;
    bool bD5;
    char padD6[2];
    int unkd8;
    int unkdc;
    int unke0;
    int iE4;

    FUN_004e3cc0_Class* GetActorBase();
    void FUN_009ae5d0(int a1);
};

// Checks iE4, goal Z delta, bD5, and actor-base values while conditionally calling four functions.
// @fnv 0x009ae5d0
void FUN_009ae5d0_shell::FUN_009ae5d0(int a1)
{
    if (iE4 == 0)
    {
        int val = 0;
        if (!listA4.FUN_008256d0())
        {
            val = (*((::fnv_009ae5d0::ItemA4 **)(&reinterpret_cast<::SimpleListNodeView*>(&(listA4))->m_item)))->field0;
        }
        reinterpret_cast<::FUN_008d0600_s *>(&((*reinterpret_cast<::fnv_009ae5d0::FUN_008d0600_s *>(&::g_011e0e80))))->FUN_008d0600(reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8(), val);
    }
    if (reinterpret_cast<::PathingRequest *>(this)->GetGoalZDelta() >= f90 && !bD5)
    {
        reinterpret_cast<::MatchContext *>(this)->UpdateMatchingActors();
    }
    iE4 = iE4 + 1;
    if (!((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())))
    {
        reinterpret_cast<::S_009b13a0_Cls *>(this)->FUN_009b13a0();
        reinterpret_cast<::B9B1320Request *>(this)->UpdateLightFade();
    }
    if (reinterpret_cast<::PathingRequest *>(this)->GetGoalZDelta() > reinterpret_cast<::FUN_00507e10_shell *>(this)->FUN_00507e10() && reinterpret_cast<::PathingRequest *>(this)->GetGoalZDelta() > reinterpret_cast<::FUN_004e3cc0_Class *>((GetActorBase()))->GetFloatAtOffset9C())
    {
        reinterpret_cast<::FUN_009ac9a0_cls *>(this)->FUN_009ac9a0();
    }
}
}  // namespace fnv_009ae5d0

struct DialogueActor;
struct DialogueProcess;
struct Animation
{
    void SpecialIdleFree(bool, bool);
};
class TESPackage
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~TESPackage();
};
struct DialoguePackage : TESPackage
{
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
    Sound sound;
    char pad8c[0xb0 - 0x8c];
    DialogueActor* pFirstSpeaker;
    DialogueActor* pSecondSpeaker;
};
struct DialogueProcess
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
    virtual void Start(DialogueActor*, int);
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
    virtual void v137();
    virtual void v138();
    virtual void* Active();
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
    virtual void Clear2(int);
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
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void Clear(int);
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void Partner(DialogueActor*);
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void Reset(int);
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual DialogueActor* Find(int);
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void Update(DialogueActor*);
};
struct DialogueActor
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
    virtual bool IsActor();
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
    virtual Animation* Anim();
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
    virtual TESPackage* Package();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void Cancel(int);
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
    DialogueActor* process;
    int unk6c;
    int unk70;
    float timer;
    int unk78;
    int unk7c;
    bool flag;
    void FUN_00933d20();
};
struct Extra
{
    void Clear();
};
struct Save
{
};
struct Handler
{
};
struct Manager
{
};
extern Manager manager;
struct Queue
{
};
class TESForm
{
  public:
    virtual void v0();
};
class Actor : public TESForm
{
};
class EnchantmentItem : public TESForm
{
};
class AlchemyItem : public TESForm
{
};
struct Data88
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    TESObjectREFR* unk28;
};
class MobileObject
{
  public:
    int FUN_00931850();
    void FUN_008cf2c0(unsigned int, unsigned int);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    Data88* unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    Actor* unkA4;
    EnchantmentItem* unkA8;
    unsigned int unkAC;
    AlchemyItem* unkB0;
public:
    bool IsCombatStateActive() const;
};
class ActorDeletionQueue
{
  public:
    void FUN_0096d470(MobileObject*, intptr_t);
    void FUN_0096d450(MobileObject*, int, bool, bool, bool);
};
// @fnv 0x008cf7a0
bool Self::FUN_008cf7a0()
{
    if (m68 && !(reinterpret_cast<::FUN_0045cd60_shell *>((m68))->FUN_0045cd60()))
        return true;
    Obj* n;
    intptr_t r7 = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((m68))->FUN_0045cd60()));
    reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::Mgr *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(void *)(this), r7);
    n = new FUN_008d7510;
    n->v1(m68);
    delete m68;
    m68 = n;
    reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::Mgr *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(void *)(this), 0, 0, 0, (::MobileObject *)(0));
    s127(0);
    m68->v18();
    return true;
}
// @fnv 0x00931710
bool Self_931710::FUN_00931710()
{
    intptr_t level = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((this->m68))->FUN_0045cd60()));
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::SpinLock_931710 *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::Mgr *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(void *)(this), level);
    Obj* newProc2 = new FUN_008d7510();
    newProc2->v1(this->m68);
    delete this->m68;
    this->m68 = newProc2;
    reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::Mgr *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(void *)(this), 0, 0, 0, (::MobileObject *)(0));
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::SpinLock_931710 *>(&::DAT_011f11a0))))->FUN_0040fba0();
    this->s127(0);
    this->m68->v18();
    return true;
}
// Cancels the process; for package type 28, handles both participants, frees special idles, and deletes the dialogue package.
// @fnv 0x00933d20
void DialogueActor::FUN_00933d20()
{
    if (!process || reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::Save * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
        return;
    process->Cancel(0);
    if (process->Package() && reinterpret_cast<struct ::FUN_0041ca90 *>((process->Package()))->get() == 28)
    {
        DialoguePackage* dialogueB = dynamic_cast<DialoguePackage*>(process->Package());
        if (dialogueB)
        {
            if (reinterpret_cast<::SoundPlaybackHandle *>(&(dialogueB->sound))->IsValid())
                reinterpret_cast<::fnv_009ef530::FUN_009ef530_cls *>((dialogueB))->FUN_009ef530();
            DialogueActor* first7 = ((::DialogueActor *)(::FUN_009ee040((char *)(dialogueB))));
            DialogueActor* second = dialogueB->pSecondSpeaker;
            if (first7)
            {
                if (first7->IsActor())
                    reinterpret_cast<::FUN_00906050_Class *>(&((*reinterpret_cast<::Manager *>(&::fnv_008a20d0::g_011f11e0))))->FUN_00906050((intptr_t)(first7));
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Reset(1);
                first7->flag = true;
            }
            if (second)
            {
                if (second->IsActor())
                    reinterpret_cast<::FUN_00906050_Class *>(&((*reinterpret_cast<::Manager *>(&::fnv_008a20d0::g_011f11e0))))->FUN_00906050((intptr_t)(second));
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->Reset(1);
                second->flag = true;
            }
            if (first7 && second)
            {
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Partner(second);
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->Partner(first7);
                first7->timer = 1.0f;
                second->timer = 1.0f;
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Clear(0);
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->Clear(0);
            }
            Animation* animation6 = first7->Anim();
            if (animation6)
                animation6->SpecialIdleFree(true, false);
            animation6 = second->Anim();
            if (animation6)
                animation6->SpecialIdleFree(true, false);
            bool same9 = false;
            if (first7 && ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture())))
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Clear2(0);
            if (second && ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture())))
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->Clear2(0);
            if (reinterpret_cast<::FUN_009344a0_shell *>((first7))->FUN_009344a0() == reinterpret_cast<::FUN_009344a0_shell *>((second))->FUN_009344a0())
                same9 = true;
            ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Update(first7);
            if (first7->IsActor() && !((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Active() && !reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->FUN_004226e0())
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first7))->GetBaseTexture()))->Start(first7, 1);
            if (second && reinterpret_cast<::MobileObject *>((second))->IsCombatStateActive() && ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture())))
            {
                ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->Update(second);
                if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->FUN_004226e0() && second->IsActor())
                    ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->Start(second, 1);
            }
            DialogueActor* target = ((::DialogueActor *)(reinterpret_cast<::FUN_004036b0_Class *>((dialogueB))->FUN_004036b0()));
            if (target)
            {
                DialogueActor* referenceA = ((::DialogueActor *)(reinterpret_cast<::DialogueItem *>((target))->FUN_005e3fa0()));
                reinterpret_cast<::FUN_0042e130_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((referenceA))->FUN_005d43c0()))))->FUN_0042e130();
                reinterpret_cast<::FUN_0042e130_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((((::DialogueActor *)(reinterpret_cast<::DialogueItem *>((target))->FUN_005e3fa0()))))->FUN_005d43c0()))))->FUN_0042e130();
                reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::Queue *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(target), 0);
                reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::Queue *>(&::g_011e0e80))))->AddMobileObjectToList((::MobileObject *)(target));
            }
            if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::Save * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
                reinterpret_cast<::FUN_0085a2e0_Class *>(((*reinterpret_cast<::Save * *>(&::g_TESSaveLoadGame))))->FUN_0085a2e0((::TESForm *)(dialogueB));
            else
                delete dialogueB;
        }
    }
    else
    {
        DialogueActor* partner2 = ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Find(4);
        ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Reset(1);
        ((::DialogueProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Partner(partner2);
        timer = 1.0f;
    }
}
// Calls FUN_00932490, resolves three form fields and unk88->unk28 through FUN_004839c0, then calls two functions on DAT_011e0e80.
// @fnv 0x008cf2c0
void MobileObject::FUN_008cf2c0(unsigned int auiArg1, unsigned int auiArg2)
{
    reinterpret_cast<::FUN_00932490_shell *>(this)->SetProcessFlags(auiArg1, auiArg2);
    uintptr_t enchantment = (uintptr_t)unkA4;
    if (enchantment)
        unkA4 = dynamic_cast<Actor*>((TESForm*)((::SaveForm *)(::FUN_004839c0(enchantment))));
    uintptr_t actor = (uintptr_t)unkA8;
    if (actor)
        unkA8 = dynamic_cast<EnchantmentItem*>((TESForm*)((::SaveForm *)(::FUN_004839c0(actor))));
    uintptr_t alchemy = (uintptr_t)unkB0;
    if (alchemy)
        unkB0 = dynamic_cast<AlchemyItem*>((TESForm*)((::SaveForm *)(::FUN_004839c0(alchemy))));
    if (unk88 && (unk88->unk00 == 1 || unk88->unk00 == 0))
    {
        uintptr_t reference = (uintptr_t)unk88->unk28;
        if (reference)
            unk88->unk28 = dynamic_cast<TESObjectREFR*>((TESForm*)((::SaveForm *)(::FUN_004839c0(reference))));
    }
    reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::Mgr *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(void *)(this), FUN_00931850());
    reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::Mgr *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(void *)(this), FUN_00931850(), false, false, (::MobileObject *)(false));
}


struct xCell;

struct xNiAlloc
{
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};


// @fnv 0x008caea0
void xActor::FUN_008caea0(xActor* apOther, float afVal)
{
    if (!m_68 || ((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_68))->FUN_0045cd60())))
        return;
    xCharCtl* CTL = ((::xCharCtl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    xCell* CELL = ((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    xWorld* WORLD = CELL ? ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((CELL))->FUN_004543c0())) : 0;
    if (!CTL)
    {
        xCtlCinfo CI(1);
        reinterpret_cast<::FUN_00810550_class *>(&(CI))->FUN_00810550(0.0f);
        if (apOther)
            reinterpret_cast<::FUN_00407860_class *>(&(CI))->FUN_00407860(::FUN_00646660(afVal, 50.0f));
        reinterpret_cast<::FUN_008ac890_shell *>(&(CI))->SetWaterForm((::TESWaterForm *)(void *)(FUN_1d0()));
        reinterpret_cast<::FUN_00810510_Class *>(&(CI))->FUN_00810510((const ::NiPoint3 &)(*FUN_1f4()));
        reinterpret_cast<::FUN_00857230_shell *>(&(CI))->SetSound((::TESSound *)(WORLD));
        reinterpret_cast<::FUN_008105c0_Class *>(&(CI))->SetPointer(new xShape(0.1f, true));
        reinterpret_cast<::FUN_00810530_c *>(&(CI))->FUN_00810530(false);
        if (apOther)
            reinterpret_cast<::FUN_00810590_Class *>(&(CI))->FUN_00810590(6, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::xFilter &)(apOther->FUN_00931ed0()))->FUN_004a3a20());
        else
            reinterpret_cast<::FUN_00810590_Class *>(&(CI))->FUN_00810590(6, ::GetCachedValue());
        reinterpret_cast<::FUN_00810570_shell *>(&(CI))->SetAssociatedActorValue(6);
        CTL = new xCharCtl(&CI, this);
        reinterpret_cast<::FUN_008106b0_Class *>((CTL))->FUN_008106b0(1.0f);
        reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((CTL))->FUN_00810610(((bool)(::FUN_00525420())));
        reinterpret_cast<::FUN_008105e0_Class *>((CTL))->FUN_008105e0(true);
        m_68->FUN_290(CTL);
        reinterpret_cast<::FUN_00810640_class *>((CTL))->FUN_00810640((intptr_t)(this));
    }
    if (CTL)
    {
        if (CELL && WORLD)
            ::FUN_0057b1d0((char *)(CTL), reinterpret_cast<::FUN_005471e0_shell *>((CELL))->FUN_005471e0());
        else
            ::FUN_0057b1d0((char *)(CTL), ::DAT_01015f5c);
        xWorld* PREV = CTL->FUN_00621ad0();
        reinterpret_cast<::C70CharacterController *>((CTL))->FUN_00c70c90((::WorldProxy *)(WORLD));
        void* NODE = FUN_1d0();
        void* CUR = ((void *)(reinterpret_cast<::FUN_00810660_Class *>((CTL))->FUN_00810660()));
        bool ADD = true;
        if (CUR != NODE)
        {
            reinterpret_cast<::S_00c6d7a0_Obj *>((CTL))->FUN_00c6d7a0((intptr_t)(NODE));
            if (WORLD && ::FUN_004bae00((const char *)(WORLD)))
            {
                CTL->FUN_d0(0);
                ::CopyBlock48(((void *)(reinterpret_cast<::FUN_00810660_Class *>((CTL))->FUN_00810660())), (const void *)(1));
            }
            ::FUN_00c6a350((::NiAVObject *)(NODE), 4, true, false, true);
            ADD = true;
        }
        xP3 POS = *FUN_1f4();
        if (PREV != WORLD)
        {
            if (PREV)
                ::FUN_00c69ee0((::NiAVObject *)(NODE), 1, 0);
            POS.z = POS.z + 8.0;
            ADD = true;
        }
        if (WORLD)
        {
            reinterpret_cast<::S005620e0_Object *>((CTL))->FUN_005620e0((const ::S005620e0_Source *)(::xP3 *)(&POS));
            if (ADD)
            {
                xFilter FILTER = CTL->FUN_0070c440();
                unsigned int LAYER = reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(FILTER))->FUN_004a3a20();
                WORLD->FUN_d0(NODE, 1, 0, LAYER, 0);
            }
            else
                ::FUN_00c69f50((::S_00c69f50_Obj *)(NODE), 1, 0);
        }
    }
}
#include "generated/data/fallout/magic/magicballprojectile.inc"
