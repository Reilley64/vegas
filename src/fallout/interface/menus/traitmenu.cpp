
// src/fallout/interface/menus/traitmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/traitmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/simple_list_node_view.h"
#include "fnv/effect_item_fields.h"
#include "fallout/interface/menu_fields.h"
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/Counter_007878d0.h"
#include "fnv/decl/EB900Owner.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00460fb0_class.h"
#include "fnv/decl/FUN_00464e10_shell.h"
#include "fnv/decl/FUN_00525430_Class.h"
#include "fnv/decl/FUN_005d4ee0Class.h"
#include "fnv/decl/FUN_005eb5e0_t.h"
#include "fnv/decl/FUN_005eba00_shell.h"
#include "fnv/decl/FUN_00785150_This.h"
#include "fnv/decl/FUN_00787600_shell.h"
#include "fnv/decl/FUN_00787760_shell.h"
#include "fnv/decl/FUN_007877a0_Object.h"
#include "fnv/decl/FUN_00787950_shell.h"
#include "fnv/decl/FUN_00787c40_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a0b110_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LBItemListBox.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/PerkPrinter.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0077d000.h"
#include "fnv/symbols_007a9000.h"
#include "fnv/symbols_007df000.h"
#include "fnv/symbols_007e6000.h"
#include "fnv/symbols_007e7000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01071000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
struct TraitMenu
{
    int FUN_007e68a0();
};

// @fnv 0x007e68a0
int TraitMenu::FUN_007e68a0()
{
    return 0x43c;
}

// @fnv 0x007e6dc0
int FUN_007e6dc0()
{
    return 0x43c;
}

struct FUN_007e6dd0_shell
{
    void* m_kPointA[9];
    void* m_kPointB[9];
    void* m_iThirdValue[9];
    void* m_iFourthElementInteger[9];
    void* m_usTrailingValue[9];
    void* m_f[9];
    void* m_g[9];
    void* m_h[9];
    void* m_i[9];
    bool FUN_007e6dd0();
};

// @fnv 0x007e6dd0
bool FUN_007e6dd0_shell::FUN_007e6dd0()
{
    for (int i = 0; i < 9; ++i)
    {
        if ((&this->m_kPointB[1])[i] == 0)
            return false;
    }
    return true;
}

namespace fnv_007e73c0 {
struct Menu
{
    void SetMenuVisibility(bool);
};

struct HUDMainMenu
{
};

struct TraitMenu : Menu
{
    void FUN_007e73c0();
};


// @fnv 0x007e73c0
void TraitMenu::FUN_007e73c0()
{
    if (*(int*)((char*)this + 0x24) == 4)
    {
        if (!reinterpret_cast<::FUN_00525430_Class *>(&((*reinterpret_cast<::fnv_007e73c0::HUDMainMenu *>(&::g_011f2250))))->FUN_00525430())
        {
            SetMenuVisibility(false);
        }
    }
}
}  // namespace fnv_007e73c0

struct FUN_007e6910_shell
{
    void FUN_007e6910();
};
struct FUN_007e68e0_shell
{
    void* FUN_007e68e0(unsigned int);
};
extern intptr_t DAT_011daf74;
struct Tile
{
    void Set(int, int);
    void UpdateEffectChanges(Tile*);
public:
    static float GetInterfaceScale();
};
// @fnv 0x007e7630
void FUN_007e7630(Tile* apTile)
{
    if (reinterpret_cast<::FUN_00a01230_shell *>((apTile))->IsTraitNonZero(DAT_011daf5c))
    {
        apTile->Set(DAT_011daf5c, 0);
        ((Tile*)DAT_011daf74)->UpdateEffectChanges(apTile);
    }
}

struct Tile;
struct FUN_007e68b0_shell
{
    unsigned char _pad[0x28];
    Tile* m_pTiles[36];
    void SetTileById(int id, Tile* tile);
};

// Stores tile in the slot at index id when id is between 0 and 8.
// @fnv 0x007e68b0
void FUN_007e68b0_shell::SetTileById(int id, Tile* tile)
{
    if (id >= 0 && id < 9)
    {
        m_pTiles[id] = tile;
    }
}

namespace fnv_007e75d0 {
struct Tile
{
};
struct Interface
{
};
struct FUN_007e75d0_shell
{
    virtual void _v0();
    virtual void _v1();
    virtual void _v2();
    virtual void _v3(int, int);
    char _pad[0x3C];
    Tile* m_40;
    bool HandleButton(int aiButton, float afValue);
};
// @fnv 0x007e75d0
bool FUN_007e75d0_shell::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 11:
        if (reinterpret_cast<::FUN_00a01230_shell *>((m_40))->IsTraitNonZero(0xFAF))
        {
            ::FUN_00706f30(1);
            _v3(6, 0);
            bhandled = true;
        }
    }
    return bhandled;
}
}  // namespace fnv_007e75d0

namespace fnv_007e76e0 {
struct Tile
{
};
struct BGSPerk
{
};
struct PC7d
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
    virtual void F498(BGSPerk*, int);
    virtual void vfill();
    virtual bool F4A0(BGSPerk*, int, int);
};
// @fnv 0x007e76e0
void FUN_007e76e0(Tile* apTile, BGSPerk* apPerk)
{
    if (reinterpret_cast<::FUN_00a01230_shell *>((apTile))->IsTraitNonZero(::DAT_011daf5c))
        (*reinterpret_cast<::fnv_007e76e0::PC7d * *>(&::_g_thePlayer))->F498(apPerk, (*reinterpret_cast<::fnv_007e76e0::PC7d * *>(&::_g_thePlayer))->F4A0(apPerk, 0, 0) + 1);
}
}  // namespace fnv_007e76e0

struct BGSPerk;
struct FNStub
{
};
struct BGSPerk
{
    virtual ~BGSPerk();
    unsigned char m_ucFormType;
    unsigned char cFormTypePad05;
    unsigned short usFormTypePad06;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    void* pSourceFilesHead;
    void* pSourceFilesNext;
    FNStub fullName;
};
struct BSSimpleList
{
};
struct PlayerCharacter
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual unsigned char GetPerkRank(BGSPerk* perk, bool team);
};
struct StartMenu
{
    const char* GetMenuTitle();
};
extern int DAT_011daf78;
struct LBH
{
    void Initialize(Tile*, const char*);
};
struct FUN_007e7030_shell
{
    void PopulatePerkList();
};
// Initializes the LUM_PerkTemplate list and adds a tile per perk with its name and rank, setting two tile values.
// @fnv 0x007e7030
void FUN_007e7030_shell::PopulatePerkList()
{
    int itotalSkillPoints = 0;
    int inumSkills = 0;
    ((LBH*)((char*)this + 0x54))->Initialize(*(Tile**)((char*)this + 0x2c), "LUM_PerkTemplate");
    for (BSSimpleList* pcurrentPerk = (BSSimpleList*)((char*)this + 0x84); pcurrentPerk && *((::BGSPerk **)(&reinterpret_cast<::SimpleListNodeView*>(pcurrentPerk)->m_item));
         pcurrentPerk = ((::BSSimpleList *)(reinterpret_cast<::Callees *>((pcurrentPerk))->FUN_00726070())))
    {
        Tile* pnew;
        int icurrRank;
        char strtemp[64];
        icurrRank = ::_g_thePlayer->GetPerkRank(*((::BGSPerk **)(&reinterpret_cast<::SimpleListNodeView*>(pcurrentPerk)->m_item)), false);
        pnew = 0;
        ::TaskQueueInterface::CopyStringToBuffer(strtemp, 64, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*((::BGSPerk **)(&reinterpret_cast<::SimpleListNodeView*>(pcurrentPerk)->m_item)))->fullName))->FUN_00408da0())));
        if (!::FUN_0044a670(strtemp))
            ::TaskQueueInterface::CopyStringToBuffer(strtemp, 64, (*reinterpret_cast<::StartMenu *>(&::g_011d35b8)).GetMenuTitle());
        if (((unsigned char)(reinterpret_cast<::FUN_005d4ee0Class *>(((*((::BGSPerk **)(&reinterpret_cast<::SimpleListNodeView*>(pcurrentPerk)->m_item)))))->FUN_005d4ee0())) > 1 && icurrRank > 0)
            ::FUN_00406d00(strtemp, 64, "%s (%d)", strtemp, icurrRank + 1);
        pnew = ((::Tile *)(reinterpret_cast<::LBItemListBox *>((((LBH*)((char*)this + 0x54))))->AddItemTile((intptr_t)(*((::BGSPerk **)(&reinterpret_cast<::SimpleListNodeView*>(pcurrentPerk)->m_item))), strtemp, (int (*)(LBItem *, LBItem *))(0), (const char *)(0))));
        pnew->Set(0xfaa, 10);
        pnew->Set(DAT_011daf78, icurrRank + 1);
    }
}

struct ListBox_TESObjectREFR
{
};
struct TileCenterX
{
};
struct NiNodeBooleanState
{
    bool GetBooleanValue();
};
struct Actor
{
    void ConfigureActorState(bool, bool);
};
struct CharacterProgressionShell
{
};
struct StatsMenu
{
    static void __cdecl UpdateStatusEffects();
};
struct Menu
{
};
// @fnv 0x007e6e10
void __cdecl FUN_007e6e10()
{
    ::fnv_0077da30::FUN_0077da30();
    if (DAT_011daf74)
    {
        reinterpret_cast<::LBList_7314c0 *>((((ListBox_TESObjectREFR*)((char*)DAT_011daf74 + 0x54))))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(Tile *, void *))::fnv_007e76e0::FUN_007e76e0)), 0, 0x7fffffff);
        if (reinterpret_cast<::FUN_00464e10_shell *>((((CharacterProgressionShell*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->FUN_00464e10()->GetBooleanValue())
            (*reinterpret_cast<::Actor * *>(&::_g_thePlayer))->ConfigureActorState(true, false);
        ::fnv_007df4e0::UpdateStatsMenuLevelText();
        StatsMenu::UpdateStatusEffects();
        ((::Tile *)(reinterpret_cast<::MenuFields *>((((TileCenterX*)DAT_011daf74)))->tile))->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((Menu*)DAT_011daf74)))->FUN_00a1d910();
        DAT_011daf74 = 0;
    }
}

struct TGF
{
};

struct FUN_006aabf0_shell
{
    signed char GetByteAt39();
};

struct FUN_007e7740_TileString
{
};

template <class T> struct ListBoxItem
{
    Tile* pTile;
    FUN_006aabf0_shell* pValue;
};



// @fnv 0x007e7740
int FUN_007e7740(ListBoxItem<BGSPerk*>* apItem1, ListBoxItem<BGSPerk*>* apItem2)
{
    int iresult;

    iresult = 0;
    if (reinterpret_cast<::TileListBoxCalls *>((((TGF*)apItem1->pTile)))->GetFloat(DAT_011daf70) < reinterpret_cast<::TileListBoxCalls *>((((TGF*)apItem2->pTile)))->GetFloat(DAT_011daf70))
    {
        iresult = 1;
    }
    else if (reinterpret_cast<::TileListBoxCalls *>((((TGF*)apItem1->pTile)))->GetFloat(DAT_011daf70) > reinterpret_cast<::TileListBoxCalls *>((((TGF*)apItem2->pTile)))->GetFloat(DAT_011daf70))
    {
        iresult = -1;
    }
    else if (apItem1->pValue->GetByteAt39() < apItem2->pValue->GetByteAt39())
    {
        iresult = -1;
    }
    else if (apItem1->pValue->GetByteAt39() > apItem2->pValue->GetByteAt39())
    {
        iresult = 1;
    }
    else
    {
        iresult = FUN_00408b20(reinterpret_cast<::FUN_00a011f0_shell *>((((FUN_007e7740_TileString*)apItem1->pTile)))->FUN_00a011f0(0xfc4),
                               reinterpret_cast<::FUN_00a011f0_shell *>((((FUN_007e7740_TileString*)apItem2->pTile)))->FUN_00a011f0(0xfc4));
    }

    return iresult;
}

struct Base753230
{
    unsigned int field_04, field_08, field_0c, field_10, field_14, field_18;
    unsigned int field_1c, field_20, field_24, field_28, field_2c, field_30;
    unsigned int field_34, field_38, field_3c, field_40, field_44;
    Base753230();
    virtual ~Base753230();
};
struct Member753230
{
    Member753230();
    ~Member753230();
};
extern int DAT_011d9214;
extern int DAT_011d9218, DAT_011d921c, DAT_011d9220;
struct FUN_00753230 : Base753230
{
    int field_48, field_4c;
    float field_50;
    bool field_54, field_55;
    unsigned short field_56;
    Member753230 field_58;
    FUN_00753230();
    virtual ~FUN_00753230();
};
// @fnv 0x00753230
FUN_00753230::FUN_00753230()
{
    DAT_011d9210 = FUN_00a00940(::DAT_01071ba0, -1);
    DAT_011d9214 = FUN_00a00940(::DAT_01071b94, -1);
    DAT_011d9224 = FUN_00a00940(::DAT_01071b88, -1);
    DAT_011d9218 = FUN_00a00940(::DAT_01071b7c, -1);
    DAT_011d921c = FUN_00a00940(::DAT_01071b70, -1);
    DAT_011d9220 = FUN_00a00940(::DAT_01071b64, -1);
    field_48 = 0;
    field_50 = ::DAT_01012054;
    field_55 = false;
    field_54 = false;
}

extern intptr_t DAT_011daf74;
struct MenuBase
{
    virtual ~MenuBase();
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
};
struct TraitEntries
{
    ~TraitEntries();
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
};
struct SelectionState
{
    ~SelectionState();
};
struct FUN_007e6910 : MenuBase
{
    TraitEntries entries;
    SelectionState selection;
    virtual ~FUN_007e6910();
};
// Calls FUN_007e6910 on this, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x007e68e0
void* FUN_007e68e0_shell::FUN_007e68e0(unsigned int flags)
{
    reinterpret_cast<::FUN_007e6910 *>((((FUN_007e6910_shell*)this)))->FUN_007e6910::~FUN_007e6910();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x007e6910
FUN_007e6910::~FUN_007e6910()
{
    DAT_011daf74 = 0;
}

struct MenuDisplay
{
};
struct MessageTemplate
{
    const char* FUN_00403df0();
};
struct TraitMenu_007e71b0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    MenuDisplay* tile38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    int firstValue;
    int lastValue;
    void UpdateValueDifferenceMessage();
};
// Computes lastValue - firstValue, formats it into a message via one of two templates, and passes it to tile38 with a fixed id.
// @fnv 0x007e71b0
void TraitMenu_007e71b0::UpdateValueDifferenceMessage()
{
    char message[64];
    {
        int difference = lastValue - firstValue;
        if (difference == 1)
        {
            ::FUN_00406d00(message, 64, (*reinterpret_cast<::MessageTemplate *>(&::g_011d4558)).FUN_00403df0(), difference);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile38))->FUN_00a01350(0xfc4, (char *)(message), 1);
            reinterpret_cast<::Tile *>((tile38))->Set(0xfa3, 1);
        }
        else
        {
            ::FUN_00406d00(message, 64, (*reinterpret_cast<::MessageTemplate *>(&::g_011d2c10)).FUN_00403df0(), difference);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile38))->FUN_00a01350(0xfc4, (char *)(message), 1);
            reinterpret_cast<::Tile *>((tile38))->Set(0xfa3, 1);
        }
    }
}

struct InputManager
{
};
struct OSGlobals
{
};
extern unsigned int DAT_011db004;
struct ChoiceTile
{
};
struct ScrollTile
{
};
struct SelectionList
{
    virtual void unused();
    virtual ChoiceTile* Selected();
};
struct ProgressMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Handle(int, ChoiceTile*);
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
    ScrollTile* scroll;
    int unk4c;
    int unk50;
    SelectionList list;
    bool HandleKey(int, int);
};
// @fnv 0x007e73f0
bool ProgressMenu::HandleKey(int key, int unused)
{
    bool handled = false;
    switch (key)
    {
    case 9:
        if (list.Selected())
        {
            reinterpret_cast<::FUN_00a0b110_shell *>((list.Selected()))->FUN_00a0b110(0xfcb);
            Handle(10, list.Selected());
            handled = true;
        }
        break;
    }
    if (FUN_00709d40() && reinterpret_cast<::FUN_00a01230_shell *>((scroll))->IsTraitNonZero(0xfa3))
    {
        int delta = 0;
        int step = 0;
        delta = reinterpret_cast<::FUN_00a23390_t *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720()))))->GetAxisState({}, {});
        if (((float)(::FUN_00408820((float)delta))) <= 8689.0)
            delta = 0;
        if (delta != 0)
            step = delta < 0 ? 1 : -1;
        if (step != 0 && ((unsigned int)(::FUN_00457fe0())) > DAT_011db004)
        {
            ScrollTile* trait = scroll;
            int iValueId = FUN_00a01860("_current_value");
            int tile = (int)reinterpret_cast<::TileListBoxCalls *>((trait))->GetFloat(iValueId);
            reinterpret_cast<::FUN_00a012d0_t *>((trait))->FUN_00a012d0(iValueId, (float)(tile + step), false);
            if (tile != reinterpret_cast<::TileListBoxCalls *>((trait))->GetFloat(iValueId))
            {
                reinterpret_cast<::FUN_00a01290_shell *>((trait))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
            }
            DAT_011db004 = ((unsigned int)(::FUN_00457fe0())) + (DAT_011db004 ? 50 : 500);
        }
        else if (step == 0)
            DAT_011db004 = 0;
    }
    return handled;
}

struct S_007e7670_Player
{
    char GetByteAt39();
};
struct S_007e7670_Dest
{
};
struct S_007e7670_Ref
{
};
// @fnv 0x007e7670
void FUN_007e7670(S_007e7670_Dest* pDest, S_007e7670_Player* pPlayer)
{
    float fValue;
    if (reinterpret_cast<::FUN_00785150_This *>((pPlayer))->FUN_00785150((::TESObjectREFR *)((*reinterpret_cast<::S_007e7670_Ref * *>(&::_g_thePlayer)))) && pPlayer->GetByteAt39() <= reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::S_007e7670_Ref * *>(&::_g_thePlayer))))->FUN_0087f9f0())
        fValue = DAT_01023cd8;
    else
        fValue = DAT_0101e704;
    reinterpret_cast<::FUN_00a012d0_t *>((pDest))->FUN_00a012d0(DAT_011daf70, fValue, 1);
}

struct EffectSetting
{
    bool IsDetrimentalToActorValue(int);
};
struct EffectItem
{
public:
    int GetAffectedActorValue();
};
struct EffectNode
{
};
struct EffectList
{
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
    EffectNode list;
};
struct PerkEntry
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int GetType();
};
struct PerkRankList
{
};
struct ValueTile
{
};
struct Tile;
struct LBList
{
public:
    void *FindItemData(::Tile *);
};
struct EffectChange
{
    int magnitude;
    int unk04;
    int unk08;
    int unk0C;
    EffectChange();
};
struct EffectChangeList
{
};
extern int DAT_011daf78;

struct PerkMenuX
{
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
    LBList list54;
    void UpdateEffectChanges(ValueTile* tile);
};

// @fnv 0x007e7850
void PerkMenuX::UpdateEffectChanges(ValueTile* tile)
{
    PerkRankList* item7 = ((::PerkRankList *)(reinterpret_cast<::LBList *>(&(list54))->FindItemData((::Tile *)(tile))));
    unsigned char rank4 = (unsigned char)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(DAT_011daf78);
    PerkEntry* cur = ((::PerkEntry *)(reinterpret_cast<::EB900Owner *>((item7))->FindEntryByLevel(rank4)));
    PerkEntry* prev6 = rank4 > 1 ? ((::PerkEntry *)(reinterpret_cast<::EB900Owner *>((item7))->FindEntryByLevel(rank4 - 1))) : 0;
    if (cur && cur->GetType() == 1)
    {
        EffectList* curEffects = ((::EffectList *)(reinterpret_cast<::Twin_0044ddc0 *>((cur))->GetName()));
        EffectList* prevEffects = prev6 ? ((::EffectList *)(reinterpret_cast<::Twin_0044ddc0 *>((prev6))->GetName())) : 0;
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&((*reinterpret_cast<::EffectChangeList *>(&::g_011daff0))))->Clear(true);
        for (EffectNode* node3 = curEffects ? &curEffects->list : 0; node3 && *((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(node3)->m_item));
             node3 = ((::EffectNode *)(reinterpret_cast<::Callees *>((node3))->FUN_00726070())))
        {
            EffectChange changeVal;
            int id9 = (*((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(node3)->m_item)))->GetAffectedActorValue();
            changeVal.magnitude = reinterpret_cast<::FUN_00404390_shell *>(((*((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(node3)->m_item)))))->FUN_00404390();
            if (id9 == -1)
                continue;
            for (EffectNode* prevNodeTmp = prevEffects ? &prevEffects->list : 0; prevNodeTmp && *((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(prevNodeTmp)->m_item));
                 prevNodeTmp = ((::EffectNode *)(reinterpret_cast<::Callees *>((prevNodeTmp))->FUN_00726070())))
            {
                if ((*((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(prevNodeTmp)->m_item)))->GetAffectedActorValue() == id9)
                    changeVal.magnitude -= reinterpret_cast<::FUN_00404390_shell *>(((*((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(prevNodeTmp)->m_item)))))->FUN_00404390();
            }
            if (!reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(DAT_011daf5c))
                changeVal.magnitude *= -1;
            if (((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((*((::EffectItem **)(&reinterpret_cast<::SimpleListNodeView*>(node3)->m_item)))))->setting))->IsDetrimentalToActorValue(id9))
                changeVal.magnitude *= -1;
            reinterpret_cast<::FUN_00787950_shell *>(&((*reinterpret_cast<::EffectChangeList *>(&::g_011daff0))))->AppendMember((::CombatMember_1024 *)(::EffectChange *)(&changeVal));
        }
    }
}

struct TraitView;
struct TileView
{
};
struct ResourceProvider
{
};
struct SettingView
{
    unsigned char* Bool();
    const char* String();
};
struct PerkView : BGSPerk
{
    signed char Level();
};
struct PlayerLevel
{
};
struct PerkNode
{
};
struct DataHandlerView
{
};
struct PerkList
{
};
struct PerkListBox
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Sort(int(__cdecl*)(ListBoxItem<BGSPerk*>*, ListBoxItem<BGSPerk*>*));
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct TraitView
{
    virtual ~TraitView();
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
    virtual int GetID();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    TileView* tile28;
    int unk2c, unk30, unk34, unk38;
    TileView* tile3c;
    TileView* tile40;
    int unk44, unk48;
    int selected;
    int count;
    PerkListBox box;
    PerkList perks;
};
extern int DAT_011daf68;
// Loads trait_menu.xml, builds the trait menu, fills its perk list with eligible perks, sets its labels and counts, and returns the menu tile or 0 on failure.
// @fnv 0x007e6990
TileView* __cdecl FUN_007e6990()
{
    TraitView* oldMenu = ((::TraitView *)(::FUN_00a09030(1084)));
    ResourceProvider* root = ((::ResourceProvider *)(::fnv_004b7210::FUN_004b7210()));
    if (oldMenu)
        delete oldMenu;
    TileView* manager = ((::TileView *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::TileView *)(reinterpret_cast<::InterfaceManager *>((root))->FUN_00586150()))))->FUN_00a01b00({})));
    DAT_011daf74 = (intptr_t)((::TraitView *)(reinterpret_cast<::FUN_00a03c90_shell *>((manager))->FUN_00a03c90()));
    if (DAT_011daf74 && ((TraitView*)DAT_011daf74)->GetID() == FUN_007e6dc0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((((TraitView*)DAT_011daf74)))->FUN_00a1dc70((::TileMenu *)(manager), false);
        if (!reinterpret_cast<::FUN_007e6dd0_shell *>((((TraitView*)DAT_011daf74)))->FUN_007e6dd0())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((manager))->GetFloat(4007) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((manager))->GetFloat(4007) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((manager))->FUN_00a012d0(4013, ::Tile::GetInterfaceScale(), {});
        int count = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingView *>(&::g_011d2f94))))));
        ((TraitView*)DAT_011daf74)->selected = 0;
        ((TraitView*)DAT_011daf74)->count = count;
        char text[64];
        if (count == 1)
            ::FUN_00406d00(text, 64, (*reinterpret_cast<::SettingView *>(&::g_011d351c)).String(), count);
        else
            ::FUN_00406d00(text, 64, (*reinterpret_cast<::SettingView *>(&::g_011d2310)).String(), count);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TraitView*)DAT_011daf74)->tile28))->FUN_00a01350(4036, (char *)(text), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TraitView*)DAT_011daf74)->tile3c))->FUN_00a01350(4036, (char *)((*reinterpret_cast<::SettingView *>(&::g_011d33d8)).String()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TraitView*)DAT_011daf74)->tile40))->FUN_00a01350(FUN_00a01860("_Title"), (char *)((*reinterpret_cast<::SettingView *>(&::g_011d35c4)).String()), true);
        for (PerkNode* node = ((::PerkNode *)(reinterpret_cast<::FUN_00460fb0_class *>(((*reinterpret_cast<::DataHandlerView * *>(&::g_dataHandler))))->FUN_00460fb0())); node && *((::PerkView **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::PerkNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
        {
            PerkView* perk = *((::PerkView **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
            if (perk->Level() > 0 && ::_g_thePlayer->GetPerkRank(perk, false) < ((unsigned char)(reinterpret_cast<::FUN_005d4ee0Class *>((perk))->FUN_005d4ee0())) &&
                ((bool)(::GetByteAtOffset56((char *)(perk)))) && reinterpret_cast<::FUN_005eba00_shell *>((perk))->FUN_005eba00((::TESObjectREFR *)(::_g_thePlayer)) && reinterpret_cast<::FUN_005eb5e0_t *>((perk))->CheckPlayerConditions())
            {
                bool valid = true;
                if (*(*reinterpret_cast<::SettingView *>(&::g_011da034)).Bool())
                {
                    if (!reinterpret_cast<::FUN_00785150_This *>((perk))->FUN_00785150((::TESObjectREFR *)(::_g_thePlayer)) || perk->Level() > reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((PlayerLevel*)::_g_thePlayer)))->FUN_0087f9f0())
                        valid = false;
                }
                if (valid)
                    reinterpret_cast<::Callees *>(&(((TraitView*)DAT_011daf74)->perks))->FUN_00905820((void *)&(perk));
            }
        }
        reinterpret_cast<::FUN_007e7030_shell *>((((TraitView*)DAT_011daf74)))->PopulatePerkList();
        ((::Tile *)(reinterpret_cast<::MenuFields *>((((TraitView*)DAT_011daf74)))->tile))->Set(DAT_011daf64, ((TraitView*)DAT_011daf74)->selected);
        ((::Tile *)(reinterpret_cast<::MenuFields *>((((TraitView*)DAT_011daf74)))->tile))->Set(DAT_011daf68, ((TraitView*)DAT_011daf74)->count);
        reinterpret_cast<::TraitMenu_007e71b0 *>((((TraitView*)DAT_011daf74)))->UpdateValueDifferenceMessage();
        reinterpret_cast<::LBList_7314c0 *>(&(((TraitView*)DAT_011daf74)->box))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(Tile *, void *))::FUN_007e7670)), 0, 0x7fffffff);
        ((TraitView*)DAT_011daf74)->box.Sort(FUN_007e7740);
        reinterpret_cast<::FUN_00787600_shell *>(&(((TraitView*)DAT_011daf74)->box))->UpdateScrollTile(true);
        return manager;
    }
    else
    {
        if (DAT_011daf74 && ((::Tile *)(reinterpret_cast<::MenuFields *>((((TraitView*)DAT_011daf74)))->tile)))
            delete (TraitView*)DAT_011daf74;
    }
    return 0;
}

struct PerkItem_7e6ea0
{
    int unk00[11];
    struct Icon_7e6ea0
    {
    } icon2C;
};

struct PerkList_7e6ea0
{
};

struct Tile_7e6ea0
{
};


struct TraitMenu_7e6ea0
{
    int unk00[12];
    Tile_7e6ea0* tile30;
    Tile_7e6ea0* tile34;
    Tile_7e6ea0* tile38;
    Tile_7e6ea0* tile3C;
    Tile_7e6ea0* tile40;
    Tile_7e6ea0* tile44;
    ScrollTile* tile48;
    int unk4C;
    int unk50;
    PerkList_7e6ea0 list54;

    void UpdatePerkTile(int id, Tile* tile);
};

// For id 10, fills the icon and description tiles from the perk list item, toggles their visibility, and updates the scroll tile's current value.
// @fnv 0x007e6ea0
void TraitMenu_7e6ea0::UpdatePerkTile(int id, Tile* tile)
{
    switch (id)
    {
    case 10:
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->tile30))->FUN_00a01350(0xFCC, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::PerkItem_7e6ea0 *)(reinterpret_cast<::LBList *>(&(this->list54))->FindItemData(tile)))->icon2C))->FUN_00408da0()))), true);
        char buf[0x200];
        reinterpret_cast<::PerkPrinter *>((((::PerkItem_7e6ea0 *)(reinterpret_cast<::LBList *>(&(this->list54))->FindItemData(tile)))))->BuildDescription(buf, 0x200);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->tile34))->FUN_00a01350(0xFC4, (char *)(buf), true);
        if (::FUN_0044a670(reinterpret_cast<::FUN_00a011f0_shell *>((this->tile30))->FUN_00a011f0(0xFCC)) > 1)
        {
            reinterpret_cast<::Tile *>((this->tile30))->Set(0xFA3, 1);
        }
        else
        {
            reinterpret_cast<::Tile *>((this->tile30))->Set(0xFA3, 0);
        }
        reinterpret_cast<::Tile *>((this->tile34))->Set(0xFA3, 1);
        reinterpret_cast<::Tile *>((this->tile44))->Set(0xFA3, 0);
        FUN_00706f30(4);
        ScrollTile* scroll2 = this->tile48;
        int traitVal = FUN_00a01860("_current_value");
        reinterpret_cast<::FUN_00a012d0_t *>((scroll2))->FUN_00a012d0(traitVal, 0.0f, false);
        reinterpret_cast<::FUN_00a01290_shell *>((scroll2))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
        break;
    }
}

namespace fnv_007e7280 {
struct Tile;
struct TileValues
{
};

struct PerkListBox
{
};

struct MenuTileHolder
{
};


struct PerkSelectMenu : MenuTileHolder
{
    int unk00;
    void* unk04;
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
    int iNumSelected;
    int iMaxSelected;
    PerkListBox kList;

    void HandleTileAction(int aiTileID, Tile* apTile);
};

// Handles tile actions by ID: toggles perk selection and refreshes the tile, or resets the selection and traverses the list.
// @fnv 0x007e7280
void PerkSelectMenu::HandleTileAction(int aiTileID, Tile* apTile)
{
    switch (aiTileID)
    {
    case 10:
        if (reinterpret_cast<::FUN_007877a0_Object *>(&(kList))->FUN_007877a0((::LevelOption *)(apTile)))
        {
            reinterpret_cast<::FUN_00787c40_shell *>(&(kList))->FUN_00787780((intptr_t)(apTile));
            reinterpret_cast<::PerkMenuX *>(this)->UpdateEffectChanges((::ValueTile *)(apTile));
        }
        else if (reinterpret_cast<::TileListBoxCalls *>((((TileValues*)apTile)))->GetFloat(::DAT_011daf70) == 255.0 && iNumSelected < iMaxSelected)
        {
            reinterpret_cast<::FUN_00787760_shell *>(&(kList))->FUN_00787760((intptr_t)(apTile));
            reinterpret_cast<::PerkMenuX *>(this)->UpdateEffectChanges((::ValueTile *)(apTile));
        }
        iNumSelected = reinterpret_cast<::Counter_007878d0 *>(&(kList))->FUN_007878d0();
        reinterpret_cast<::Tile *>((((::fnv_007e7280::TileValues *)(this->unk04))))->Set(::DAT_011daf64, iNumSelected);
        reinterpret_cast<::TraitMenu_007e71b0 *>(this)->UpdateValueDifferenceMessage();
        break;
    case 6:
        ::FUN_007e6e10();
        break;
    case 5:
        ::FUN_00706f30(1);
        iNumSelected = 0;
        reinterpret_cast<::Tile *>((((::fnv_007e7280::TileValues *)(this->unk04))))->Set(::DAT_011daf64, iNumSelected);
        reinterpret_cast<::LBList_7314c0 *>(&(kList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(fnv_007e7280::Tile *))::FUN_007e7630)), 0, 0x7fffffff);
        reinterpret_cast<::TraitMenu_007e71b0 *>(this)->UpdateValueDifferenceMessage();
        break;
    }
}
}  // namespace fnv_007e7280

#include "generated/data/fallout/interface/menus/traitmenu.inc"
