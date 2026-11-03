// fallout/ai/falloutcharacterprogression.cpp: Flt, NiNodeBooleanState (11 functions)

#include "fnv/decl/BGSSaveLoadUI.h"
#include "fnv/decl/FUN_00464e10_shell.h"
#include "fnv/decl/FUN_0094ed40_cls.h"
#include "fnv/decl/FUN_00975ea0_shell.h"
#include "fnv/decl/GlobalObject_0045cf30.h"
#include "fnv/decl/StatsMenu.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/fnv_0047dfe0__TABStub.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_00ad7fa0__AudioUpdateStand.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_0077c000.h"
#include "fnv/symbols_007df000.h"
#include "fnv/symbols_00a25000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "falloutcharacterprogression_decls.h"

// @fnv 0x008d51f0
bool NiNodeBooleanState::GetBooleanValue()
{
    return *reinterpret_cast<const bool*>(pData.operator->());
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct PlayerProgressionData
{
    void Initialize();
    bool CheckCanLevelUp(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    bool m_bFirstProgressionFlag;
    char _pad_1[3];
    int m_iProgressionValue;
    bool m_bSecondProgressionFlag;
    char _pad_9[3];
};
struct FUN_008d55e0_shell : public PlayerProgressionData
{
    bool FUN_008d55e0(int);
};

class GlobalObject2_0040c150
{
  public:
};

class ActorValueUtility
{
  public:
    static int __cdecl ConvertActorValue(int);
};

class ActorValueOwner
{
  public:
    virtual void v0();
    virtual void v1();
    virtual int GetActorValueI(int);
};

class TESActorBase;
class Actor
{
  public:
    char _pad[0xa4];
    ActorValueOwner avOwner;
public:
    ::TESActorBase *GetActorBase();
};

class PlayerCharacter : public Actor
{
};


// Returns true and sets the flag when the player is below the level cap and their actor value 0x18 meets the threshold for aiToLevel.
// @fnv 0x008d55e0
bool FUN_008d55e0_shell::FUN_008d55e0(int aiToLevel)
{
    bool bresult = false;
    if (reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((::_g_thePlayer))->FUN_0087f9f0() >= *((int *)&(::FUN_0043d4d0((int *)&(g_011d0c60)))))
    {
        return false;
    }
    int inextThreshold = ActorValueUtility::ConvertActorValue(aiToLevel);
    if (::_g_thePlayer->avOwner.GetActorValueI(0x18) >= inextThreshold)
    {
        m_bFirstProgressionFlag = true;
        bresult = true;
    }
    return bresult;
}

struct FUN_008d54e0_shell
{
    unsigned short FUN_008d54e0(unsigned int);
};

// Returns the sum of the constants 1 and 4 as an unsigned short.
// @fnv 0x008d54e0
unsigned short FUN_008d54e0_shell::FUN_008d54e0(unsigned int)
{
    unsigned short usTotal = 0;
    usTotal = usTotal + 1;
    usTotal = usTotal + 4;
    return usTotal;
}

namespace fnv_008d55b0 {
struct ActorValueUtility
{
};

struct FUN_008d55b0_shell
{
    unsigned char m_b0;
    int m_i4;
    unsigned char m_b8;
    void FUN_008d55b0();
};

// @fnv 0x008d55b0
void FUN_008d55b0_shell::FUN_008d55b0()
{
    m_b0 = 0;
    m_i4 = ::ActorValueUtility::ConvertActorValue(2);
    m_b8 = 0;
}
}  // namespace fnv_008d55b0

namespace fnv_008d5210 {
struct Flt
{
    operator unsigned int() const;
    void LevelUpPlayer();
};
struct Snd_
{
};
struct BSAudio : Snd_
{
};
struct XActor
{
};
struct Actor : XActor
{
};
struct PC7d : Actor
{
};
struct TESActorBaseData
{
};
// If the flag is set, plays the UILevelUp sound, raises the player's actor base level by one and calls FUN_00706270.
// @fnv 0x008d5210
void Flt::LevelUpPlayer()
{
    if (!*(unsigned char*)(unsigned int)(*this))
        return;
    reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((((::fnv_008d5210::BSAudio *)(::FUN_00453a70()))))->FUN_00ad7fa0((char *)("UILevelUp"), 0x121);
    reinterpret_cast<::fnv_0047dfe0::TABStub *>((((TESActorBaseData*)((char*)((void *)(reinterpret_cast<::Actor *>(((*reinterpret_cast<::fnv_008d5210::PC7d * *>(&::_g_thePlayer))))->GetActorBase())) + 0x30))))->FUN_0047dfe0(reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::fnv_008d5210::PC7d * *>(&::_g_thePlayer))))->FUN_0087f9f0() + 1);
    ::fnv_00706270::FUN_00706270();
}
}  // namespace fnv_008d5210

struct Flt
{
    operator unsigned int() const;
    void FUN_008d5510(int);
};
struct PC7d
{
};
// @fnv 0x008d5510
void Flt::FUN_008d5510(int aiUnused)
{
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))))->FUN_00484ce0((void *)((unsigned int)*this), 1);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))))->FUN_00484ce0((void *)((unsigned int)*this + 4), 4);
}

namespace fnv_008d5550 {
struct Flt
{
    operator unsigned int() const;
    void FUN_008d5550(int, int);
};
struct PC7d
{
};
// Calls FUN_00484d00 on g_thePlayer twice, passing the value of *this and *this + 4 with sizes 1 and 4.
// @fnv 0x008d5550
void Flt::FUN_008d5550(int, int)
{
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(((*reinterpret_cast<::fnv_008d5550::PC7d * *>(&::_g_thePlayer))))->FUN_00484d00((void *)((unsigned int)*this), 1);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(((*reinterpret_cast<::fnv_008d5550::PC7d * *>(&::_g_thePlayer))))->FUN_00484d00((void *)((unsigned int)*this + 4), 4);
}
}  // namespace fnv_008d5550

struct FUN_008d5590_shell
{
    void* FUN_008d5590();
};

// @fnv 0x008d5590
void* FUN_008d5590_shell::FUN_008d5590()
{
    reinterpret_cast<::fnv_008d55b0::FUN_008d55b0_shell *>(this)->FUN_008d55b0();
    return this;
}

namespace fnv_008d5270 {
struct Flt
{
    operator unsigned int();
};

struct FUN_008d55e0_shell
{
};

struct Actor
{
};

struct PlayerCharacter : public Actor
{
};

struct TESDataHandler
{
};

struct DAT_011e0e80_class
{
};

struct BGSSaveLoadUI
{
};

struct G7d1
{
};

struct FUN_008d5270_shell : public Flt
{
    void FUN_008d5270();
};

// @fnv 0x008d5270
void FUN_008d5270_shell::FUN_008d5270()
{
    if (!reinterpret_cast<::FUN_008d55e0_shell *>((((FUN_008d55e0_shell*)(unsigned int)*this)))->FUN_008d55e0(reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::fnv_008d5270::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_0087f9f0() + 1))
    {
        *(char*)(unsigned int)*this = 0;
        reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_008d5270::TESDataHandler * *>(&::g_dataHandler))))->GetRegions();
        reinterpret_cast<::FUN_00975ea0_shell *>(&((*reinterpret_cast<::fnv_008d5270::DAT_011e0e80_class *>(&::g_011e0e80))))->FUN_00975ea0();
        if (((::fnv_008d5270::BGSSaveLoadUI *)(::FUN_00a25920())))
        {
            reinterpret_cast<::BGSSaveLoadUI *>((((::fnv_008d5270::BGSSaveLoadUI *)(::FUN_00a25920()))))->FUN_007d0bb0();
        }
        if (((bool)(reinterpret_cast<::GlobalObject_0045cf30 *>(&((*reinterpret_cast<::fnv_008d5270::G7d1 *>(&::g_011e0a30))))->GetBoolValue())))
        {
            reinterpret_cast<::FUN_0094ed40_cls *>(((*reinterpret_cast<::fnv_008d5270::PlayerCharacter * *>(&::_g_thePlayer))))->WriteProgressData(0);
        }
    }
}
}  // namespace fnv_008d5270

namespace fnv_008d5300 {

struct StatsMenu
{
};

struct ActorValueUtility
{
};

struct TESActorBaseData
{
};

struct XActor
{
};

struct Flt
{
    operator unsigned int();
};

struct NiNodeBooleanState;

struct FUN_00464e10_shell
{
};

struct SubA4
{
    virtual void v0();
    virtual void v4();
    virtual int vfunc_8(int av);
};

struct Actor
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
    virtual void vfn_3a8(int, int, int);

};

struct PlayerCharacter : public Actor
{
};

struct FUN_008d5300_shell
{
    void SetPlayerLevel(int aLevel);
};

// @fnv 0x008d5300
void FUN_008d5300_shell::SetPlayerLevel(int aLevel)
{
    if (aLevel == reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::fnv_008d5300::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_0087f9f0())
        return;

    int currentXP;
    char* data;
    int diff;

    {
        NiNodeBooleanState* prog = ((::fnv_008d5300::NiNodeBooleanState *)(reinterpret_cast<::FUN_00464e10_shell *>((((FUN_00464e10_shell*)(void*)(*reinterpret_cast<::fnv_008d5300::PlayerCharacter * *>(&::_g_thePlayer)))))->FUN_00464e10()));
        data = (char*)((Flt*)prog)->operator unsigned int();
    }

    currentXP = ((SubA4*)((char*)(*reinterpret_cast<::fnv_008d5300::PlayerCharacter * *>(&::_g_thePlayer)) + 0xa4))->vfunc_8(0x18);

    {
        int reqXP = ::ActorValueUtility::ConvertActorValue(aLevel - 1);
        diff = reqXP - currentXP;
    }

    data[8] = 1;
    (*reinterpret_cast<::fnv_008d5300::PlayerCharacter * *>(&::_g_thePlayer))->vfn_3a8(0x18, diff, 0);
    data[8] = 0;
    data[0] = 0;
    *(int*)(data + 4) = ::ActorValueUtility::ConvertActorValue(aLevel + 1);

    reinterpret_cast<::fnv_0047dfe0::TABStub *>((((TESActorBaseData*)((char*)((void *)(reinterpret_cast<::Actor *>((((XActor*)(void*)(*reinterpret_cast<::fnv_008d5300::PlayerCharacter * *>(&::_g_thePlayer)))))->GetActorBase())) + 0x30))))->FUN_0047dfe0(aLevel);
    reinterpret_cast<::fnv_008d5270::FUN_008d5270_shell *>(this)->FUN_008d5270();
    ::fnv_007df4e0::UpdateStatsMenuLevelText();
    ::StatsMenu::UpdateStatusEffects();
}
}  // namespace fnv_008d5300

namespace fnv_008d53f0 {


struct GlobalObject2_0040c150
{
};

struct Flt
{
    operator unsigned int();
};

struct FUN_008d55e0_shell
{
};

struct FUN_00464e10_shell
{
};

struct Actor
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
    virtual bool vfn_360();

};

struct PlayerCharacter : public Actor
{
};

// @fnv 0x008d53f0
void FUN_008d53f0(void* apTarget, int a2, int aiUnused, float afValue)
{
    Actor* pActor = apTarget ? (Actor*)((char*)apTarget - 0xa4) : 0;
    if (pActor && pActor->vfn_360())
    {
        NiNodeBooleanState* prog = reinterpret_cast<::FUN_00464e10_shell *>((((FUN_00464e10_shell*)(*reinterpret_cast<::fnv_008d53f0::PlayerCharacter * *>(&::_g_thePlayer)))))->FUN_00464e10();
        if (*(bool*)(((Flt*)prog)->operator unsigned int() + 8))
            return;
        if (a2 == 0x18 && afValue > ::_DAT_01012060)
        {
            if ((int)afValue > 0)
                ::QueueLevelUpNotification((int)afValue);
            if (reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::fnv_008d53f0::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_0087f9f0() < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_008d53f0::GlobalObject2_0040c150 *>(&::g_011d0c60)))))))
                reinterpret_cast<::FUN_008d55e0_shell *>((((FUN_008d55e0_shell*)((Flt*)prog)->operator unsigned int())))->FUN_008d55e0(reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::fnv_008d53f0::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_0087f9f0() + 1);
        }
    }
}
}  // namespace fnv_008d53f0
