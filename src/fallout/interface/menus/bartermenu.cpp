
// src/fallout/interface/menus/bartermenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/bartermenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/simple_list_node_view.h"
#include <new>
#include <cstdint>
#include <cstdlib>
#include "fnv/decl/Actor.h"
#include "fnv/decl/ActorGoldQuery.h"
#include "fnv/decl/ActorSoundStub.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00418630_Class.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00418690_shell.h"
#include "fnv/decl/FUN_004186c0_shell.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_0046f640_shell.h"
#include "fnv/decl/FUN_0046faf0_shell.h"
#include "fnv/decl/FUN_0047bcf0_class.h"
#include "fnv/decl/FUN_0047efe0_shell.h"
#include "fnv/decl/FUN_00480d90_shell.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_004c94d0_shell.h"
#include "fnv/decl/FUN_00567bd0_cls.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0070ec70_class.h"
#include "fnv/decl/FUN_0071ae60_shell.h"
#include "fnv/decl/FUN_00730e20_cls.h"
#include "fnv/decl/FUN_00740960_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00950030_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a03d40_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/FunctionOwner.h"
#include "fnv/decl/Host_004d4b00.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/Inv4cb320.h"
#include "fnv/decl/Inv4cb4b0.h"
#include "fnv/decl/InvOwner.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryHandler.h"
#include "fnv/decl/InventoryListBox.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ItemChangeValueShell.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/ListBoxZ.h"
#include "fnv/decl/ListBox_71a.h"
#include "fnv/decl/ListBox_71ad30.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/Menu.h"
#include "fnv/decl/Menu_007301f0.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/S.h"
#include "fnv/decl/Self567b50.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk00796f90.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00421400__FUN_00421400.h"
#include "fnv/decl/fnv_00567ad0__FUN_00567ad0.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/list71a__L71Menu.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00469000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00719000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_0072e000.h"
#include "fnv/symbols_0072f000.h"
#include "fnv/symbols_00730000.h"
#include "fnv/symbols_00764000.h"
#include "fnv/symbols_007ab000.h"
#include "fnv/symbols_007d6000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
struct FUN_0072d030_shell
{
    int FUN_0072d030();
};

// @fnv 0x0072d030
int FUN_0072d030_shell::FUN_0072d030()
{
    return 0x41d;
}

// @fnv 0x0072d6c0
int __cdecl FUN_0072d6c0()
{
    return 0x41d;
}

void __cdecl UpdateTopicMenu();

// @fnv 0x0072db40
void __cdecl FUN_0072db40()
{
    if (!ConsumeByteAtE4())
        UpdateTopicMenu();
}

struct FUN_0072dc30_shell
{
    void RebuildInventoryLists(int);
};

extern unsigned char DAT_011d8fc0;

// If abNow is set, calls RebuildInventoryLists(0) on DAT_011d8fa4 when non-null and clears DAT_011d8fc0; otherwise sets DAT_011d8fc0 to 1.
// @fnv 0x00730690
void __cdecl FUN_00730690(bool abNow)
{
    if (abNow)
    {
        if (DAT_011d8fa4 != 0)
        {
            reinterpret_cast<FUN_0072dc30_shell*>(DAT_011d8fa4)->RebuildInventoryLists(0);
        }
        DAT_011d8fc0 = 0;
    }
    else
    {
        DAT_011d8fc0 = 1;
    }
}

struct BarterMenu
{
    void* FUN_0072d070(unsigned int flags);
    void FUN_0072d0a0();
};

namespace fnv_0072e530 {
struct Tile
{
    void Set(int, int);
};
struct BarterMenu
{
    void FUN_0072e530(int, Tile*);
};
// Calls Set(0xfa3, 0) on the Tile objects at offsets 0x7c and 0x78 of this BarterMenu.
// @fnv 0x0072e530
void BarterMenu::FUN_0072e530(int aiID, Tile* apTarget)
{
    ((Tile*)*(int**)((char*)this + 0x7c))->Set(0xfa3, 0);
    ((Tile*)*(int**)((char*)this + 0x78))->Set(0xfa3, 0);
}
}  // namespace fnv_0072e530

struct WeatherEntry
{
};
struct BSSimpleList_WeatherEntry
{
};

struct FUN_0071a670_shell
{
};

struct FUN_00730b80_shell
{
    char pad[4];
    BSSimpleList_WeatherEntry list;
    void SortWeatherEntries(int(__cdecl* fn)(WeatherEntry*, WeatherEntry*));
};

// Sorts the weather entry list with the given comparison function, then calls UpdateItems on this object.
// @fnv 0x00730b80
void FUN_00730b80_shell::SortWeatherEntries(int(__cdecl* fn)(WeatherEntry*, WeatherEntry*))
{
    reinterpret_cast<::ItemChangeList *>(&(list))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(fn));
    reinterpret_cast<::ListBox_71a *>((reinterpret_cast<FUN_0071a670_shell*>(this)))->UpdateItems();
}

struct BaseProcess
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
    virtual bool v285(int a);
};
struct PlayerCharacter
{
};
struct Tile
{
public:
    void Set(int, int);
public:
    void SetName(const char *);
public:
    void Set(int, unsigned int);
public:
    static float GetInterfaceScale();
};
struct TopicMenu
{
    char pad0[4];
    Tile* pTile;
    char pad8[0x11c - 8];
    unsigned char bFlag;
};

// @fnv 0x0072d6d0
void __cdecl UpdateTopicMenu()
{
    if (DAT_011d8fa4 != 0)
    {
        BaseProcess* pAIProcess = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(::_g_thePlayer))->GetBaseTexture()));
        if (pAIProcess->v285(1))
            reinterpret_cast<::FUN_00950030_shell *>((::_g_thePlayer))->FUN_00950030();
        intptr_t iTopic = 0;
        if (((TopicMenu*)DAT_011d8fa4)->bFlag)
            iTopic = ((intptr_t)(::fnv_0061a2d0::GetTopicSubTypeName(5, 4)));
        ::StartDialogueForTopic((::TESTopic *)(iTopic));
        ((TopicMenu*)DAT_011d8fa4)->pTile->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((TopicMenu*)DAT_011d8fa4)))->FUN_00a1d910();
    }
}

class TESBoundObject
{
  public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual bool CannotSell();
    int FUN_00401170();
};
class TESFullName
{
  public:
    virtual void method0();
    unsigned int GetModelLength() const;
};
class TESObjectARMO : public TESBoundObject
{
  public:
};
class TESObjectWEAP : public TESBoundObject
{
  public:
};
class TESForm;
class TESBipedModelForm
{
  public:
public:
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
};
class InventoryEntry
{
  public:
};
// @fnv 0x0072e570
bool FUN_0072e570(InventoryEntry* entry)
{
    bool unavailable = false;
    {
        TESBoundObject* form;
        {
            TESFullName* name;
            {
                TESObjectWEAP* weapon;
                {
                    TESBipedModelForm* biped;
                    {
                        TESObjectARMO* armor;

                        form = entry ? ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) : 0;
                        biped = ::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(form));
                        name = dynamic_cast<TESFullName*>(form);
                        armor = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName()))->FUN_00401170() == 0x28
                                    ? static_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())))
                                    : 0;
                        weapon = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName()))->FUN_00401170() == 0x29
                                     ? static_cast<TESObjectWEAP*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())))
                                     : 0;
                        if (!form || (biped && !reinterpret_cast<::FUN_00480d90_shell *>((biped))->FUN_00480d90()) || form->CannotSell() || ::FUN_00481f10((::TESObject *)(form)) ||
                            !name || !name->GetModelLength() || (armor && !reinterpret_cast<::FUN_0047bcf0_class *>((armor))->IsFlag80Clear()) ||
                            (weapon && !((bool)(reinterpret_cast<::FUN_004c94d0_shell *>((weapon))->GetFlag()))) || form->FUN_00401170() == 0x2e)
                            unavailable = true;
                    }
                }
            }
        }
    }
    return unavailable;
}


struct FUN_0070ec70_This
{
};

struct FUN_0072f680_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Notify(int aiCode, int aiFlag);
    void FUN_0072f680(int aiType, int aiUnused);
};

// For type 3 or 8, checks FUN_0070ec70() and calls Notify with 2/7 when negative, otherwise 4/9.
// @fnv 0x0072f680
void FUN_0072f680_cls::FUN_0072f680(int aiType, int aiUnused)
{
    if (aiType == 3 || aiType == 8)
    {
        if (((int)(reinterpret_cast<::FUN_0070ec70_class *>((((FUN_0070ec70_This*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0070ec70())) < 0)
            Notify(aiType == 3 ? 2 : 7, 0);
        else
            Notify(aiType == 3 ? 4 : 9, 0);
    }
}

struct S_Node
{
    int unk00, unk04;
};
struct S_Item
{
    int FUN_004459e0(int);
};
struct S_Holder
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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    S_Node list1;
    S_Node list2;
};
struct S_Mgr
{
};
struct S_ListA
{
    int unk00, unk04;
    ~S_ListA();
};
struct S_ListB
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
    ~S_ListB();
};
struct S_Base
{
    virtual ~S_Base();
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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
};

struct FUN_0072d0a0 : S_Base
{
    S_ListB m_a8;
    S_ListB m_d8;
    int unk108;
    S_ListA m_10c;
    S_ListA m_114;
    ~FUN_0072d0a0();
};
// Calls FUN_0072d0a0, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0072d070
void* BarterMenu::FUN_0072d070(unsigned int flags)
{
    reinterpret_cast<::FUN_0072d0a0 *>(this)->FUN_0072d0a0::~FUN_0072d0a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0072d0a0
FUN_0072d0a0::~FUN_0072d0a0()
{
    S_Node* cur;
    S_Node* cur2;
    if (DAT_011d8fa4 != 0)
    {
        for (cur = &((S_Holder*)DAT_011d8fa4)->list1; cur != 0 && *((::S_Item **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)) != 0; cur = ((::S_Node *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
        {
            S_Item* item = *((::S_Item **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item));
            S_Item* obj = item;
            obj != 0 ? obj->FUN_004459e0(1) : 0;
        }
        for (cur2 = &((S_Holder*)DAT_011d8fa4)->list2; cur2 != 0 && *((::S_Item **)(&reinterpret_cast<::SimpleListNodeView*>(cur2)->m_item)) != 0;
             cur2 = ((::S_Node *)(reinterpret_cast<::Callees *>((cur2))->FUN_00726070())))
        {
            S_Item* item2 = *((::S_Item **)(&reinterpret_cast<::SimpleListNodeView*>(cur2)->m_item));
            S_Item* obj2 = item2;
            obj2 != 0 ? obj2->FUN_004459e0(1) : 0;
        }
        reinterpret_cast<::FileMatchList *>(&(((S_Holder*)DAT_011d8fa4)->list1))->RemoveAll();
        reinterpret_cast<::FileMatchList *>(&(((S_Holder*)DAT_011d8fa4)->list2))->RemoveAll();
    }
    reinterpret_cast<::FUN_0046faf0_shell *>(((*reinterpret_cast<::S_Mgr * *>(&::g_dataHandler))))->FUN_0046faf0();
    DAT_011d8fa4 = 0;
}

extern const char str_010707d0[];
extern const char str_010707b4[];
extern const char str_01070760[];
extern const char str_010704d4[];
extern const char str_0107074c[];
extern const char str_01070740[];
extern const char str_01070734[];

struct Obj135
{
};

struct SubA0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void FUN_0075a0d0(Obj135* a, const char* b);
};

struct BigObj
{
    virtual int v00(int a);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    Obj135* m_34;
    int m_38;
    int m_3c;
    Obj135* m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    Obj135* m_54;
    int m_58;
    Obj135* m_5c;
    Obj135* m_60;
    Obj135* m_64;
    Obj135* m_68;
    Obj135* m_6c;
    Obj135* m_70;
    Obj135* m_74;
    int m_78;
    int m_7c;
    int m_80;
    float m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    SubA0 m_a8;
    SubA0 m_d8;
    void RebuildInventoryLists(int a);
};

struct ObjA
{
    virtual int v0(int a);
};

struct ObjB
{
};

struct ObjX
{
};

struct SelfObj
{
};

struct InventoryMenuSetting
{
};

struct SubEA
{
};

struct ErrLog
{
};

int __cdecl FUN_0072d6c0();
void __cdecl FUN_00763ff0();

// Validates arg0, resolves the inventory menu object, initializes its labels and settings from the config, and stores it in DAT_011d8fa4.
// @fnv 0x0072d250
intptr_t __cdecl InitInventoryMenu(int arg0, int aiValue)
{
    int aT30;
    BigObj* t2c15;
    int t28a;
    BigObj* cb8;
    BigObj* kCb2;
    ObjA* aChain1;
    ObjA* chain2j;
    int xTmp14;
    Obj135* tmp10o;
    void* selfa = ((void *)(::fnv_004b7210::FUN_004b7210()));
    ObjB* bb;
    ObjA* ah;

    if (arg0 == 0)
    {
        ::FUN_005b5e40();
        return 0;
    }
    ah = ((::ObjA *)(::FUN_00a09030(FUN_0072d6c0())));
    if (ah != 0)
    {
        aChain1 = ah;
        chain2j = aChain1;
        if (chain2j != 0)
            t28a = chain2j->v0(1);
        else
            t28a = 0;
    }
    bb = ((::ObjB *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::ObjX *)(reinterpret_cast<::InterfaceManager *>((((SelfObj*)selfa)))->FUN_00586150()))))->FUN_00a01b00({})));
    if (bb != 0)
        t2c15 = ((::BigObj *)(reinterpret_cast<::FUN_00a03c90_shell *>((bb))->FUN_00a03c90()));
    else
        t2c15 = 0;
    DAT_011d8fa4 = (intptr_t)t2c15;
    if (DAT_011d8fa4 != 0 && ((BigObj*)DAT_011d8fa4)->v13() == FUN_0072d6c0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((((BigObj*)DAT_011d8fa4)))->FUN_00a1dc70((::TileMenu *)(bb), 0);
        if (((unsigned char)(reinterpret_cast<::Unk00796f90 *>((((BigObj*)DAT_011d8fa4)))->HasNoZeroEntries())) == 0)
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (((double)(reinterpret_cast<::TileListBoxCalls *>((bb))->GetFloat(0xfa7))) == DAT_010704f0 || ((double)(reinterpret_cast<::TileListBoxCalls *>((bb))->GetFloat(0xfa7))) == DAT_010704e8)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((bb))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), {});
        }
        FUN_00763ff0();
        reinterpret_cast<::TutorialMessageGate718 *>((((SelfObj*)((char*)selfa + 0x4d4))))->FUN_00718630(0x17, FUN_0072d6c0(), 0x200);
        ((BigObj*)DAT_011d8fa4)->m_a8.FUN_0075a0d0(((BigObj*)DAT_011d8fa4)->m_40, str_010704d4);
        ((BigObj*)DAT_011d8fa4)->m_d8.FUN_0075a0d0(((BigObj*)DAT_011d8fa4)->m_54, str_010704d4);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_34))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d4378))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::Obj135 *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((bb))->FUN_00a03da0((char *)(str_0107074c))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d25b0))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_5c))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d26f4))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_74))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d33fc))))->GetMenuTitle()))), true);
        xTmp14 = FUN_00a01860(::DAT_0106ed20);
        tmp10o = ((::Obj135 *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((bb))->FUN_00a03da0((char *)(str_01070740))));
        if (tmp10o != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tmp10o))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d2aa8))))->GetMenuTitle()))), true);
        tmp10o = ((::Obj135 *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((bb))->FUN_00a03da0((char *)(str_01070734))));
        if (tmp10o != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tmp10o))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d26a0))))->GetMenuTitle()))), true);
        if (((BigObj*)DAT_011d8fa4)->m_60 != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_60))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
        if (((BigObj*)DAT_011d8fa4)->m_64 != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_64))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d412c))))->GetMenuTitle()))), true);
        if (((BigObj*)DAT_011d8fa4)->m_68 != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_68))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d330c))))->GetMenuTitle()))), true);
        if (((BigObj*)DAT_011d8fa4)->m_6c != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_6c))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
        if (((BigObj*)DAT_011d8fa4)->m_70 != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BigObj*)DAT_011d8fa4)->m_70))->FUN_00a01350(xTmp14, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
        ((BigObj*)DAT_011d8fa4)->m_80 = arg0;
        ((BigObj*)DAT_011d8fa4)->m_88 = MinInt(FUN_00647b70(aiValue, -100), 100);
        ((BigObj*)DAT_011d8fa4)->m_84 = 0.0f;
        ::fnv_00649050::FUN_00649050(reinterpret_cast<::ActorValueOwner *>((((SubEA*)((char*)(*reinterpret_cast<char * *>(&::_g_thePlayer)) + 0xa4))))->GetActorValueAsInteger((::ActorValue::Index)(0x20)), (float *)(int *)(&((BigObj*)DAT_011d8fa4)->m_94),
                     (float *)(int *)(&((BigObj*)DAT_011d8fa4)->m_98));
        ::s717280::FUN_00717280(0x24);
        reinterpret_cast<::Menu *>((((BigObj*)DAT_011d8fa4)))->SetMenuVisibility(0);
        ((BigObj*)DAT_011d8fa4)->RebuildInventoryLists(0);
        return (intptr_t)bb;
    }
    else if (DAT_011d8fa4 != 0 && ((std::intptr_t)(reinterpret_cast<::Callees *>((((BigObj*)DAT_011d8fa4)))->FUN_00726070())) != 0)
    {
        cb8 = (BigObj*)DAT_011d8fa4;
        kCb2 = cb8;
        if (kCb2 != 0)
            aT30 = kCb2->v00(1);
        else
            aT30 = 0;
    }
    return 0;
}

struct BmTile
{
};

struct BmRef
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
    virtual const char* GetEditorID();
};

struct BmExtraList
{
};
struct BmExtraNode
{
};
struct BmItem
{
    BmExtraNode* FUN_00559450();
};

struct BmIntSetting
{
};
struct BmStrSetting
{
};

struct BmPopup
{
    virtual void Destroy(bool bFree);
};

struct BmItemList
{
    int FUN_005ae380();
};
struct BmFilteredList
{
};

void __cdecl FUN_0072db40();
void __cdecl UpdateTopicMenu();

static const char s_szNumBartered[] = "_NumBartered";
static const char s_szOrigRef[] = "Original Container Ref: '%s' (%08x)";
static const char s_szOrigRefNone[] = "Original Container Ref: NONE";
extern const char g_szBarterClickEnd[] = "";

struct BarterMenuClick
{
    char pad00[0x28];
    BmTile* m_apTiles[0x16];
    char pad80[0x9c - 0x80];
    int m_iMerchantFilter;
    int m_iPlayerFilter;
    void* unka4;
    BmFilteredList m_kMerchantList;
    char pada9[0xd8 - 0xa9];
    BmFilteredList m_kPlayerList;
    char padd9[0x108 - 0xd9];
    BmPopup* unk108;
    BmItemList m_kMerchantItems;
    char pad10d[0x114 - 0x10d];
    BmItemList m_kPlayerItems;

    void CompleteBarterTransaction();
    void HandleTileClick(int m_uiSoundID, BmTile* pkTile);
};

namespace fnv_0072db60 {
// FUN_0072db60: thiscall, /GS, two identical formatted-label blocks.
struct SysVA
{
};
struct SysVC
{
};
struct SysVB
{
};
struct SysStr
{
};
struct Obj3c
{
};
extern "C" void __cdecl FUN_00ec408c();

struct FUN_0072db60_cls
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
    Obj3c* m_3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    Obj3c* m_50;
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
    int unk88;
    int m_8c;
    int m_90;
    void FUN_0072db60();
};

// Stores two values from global subsystems into m_8c and m_90, then formats each with a string and passes it to m_3c and m_50 via FUN_00a01350.
// @fnv 0x0072db60
void FUN_0072db60_cls::FUN_0072db60()
{
    char buf[0x40];
    m_8c = (int)((reinterpret_cast<::ActorGoldQuery *>(((*reinterpret_cast<::fnv_0072db60::SysVA * *>(&::_g_thePlayer))))->FUN_00891d70()));
    m_90 = (int)((reinterpret_cast<::Inv4cb320 *>((((::fnv_0072db60::SysVC *)(reinterpret_cast<::FUN_00740960_Class *>(((*reinterpret_cast<::fnv_0072db60::SysVB * *>(&::g_dataHandler))))->FUN_00740960()))))->GetCountableItemCount()));
    ::FUN_00406d00(buf, 0x40, "%s   %d", ((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0072db60::SysStr *>(&::g_011d25b0))))->GetMenuTitle())), m_8c);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_3c))->FUN_00a01350(0xfc4, buf, 1);
    ::FUN_00406d00(buf, 0x40, "%s   %d", ((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0072db60::SysStr *>(&::g_011d25b0))))->GetMenuTitle())), m_90);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_50))->FUN_00a01350(0xfc4, buf, 1);
}
}  // namespace fnv_0072db60

struct S_0072e370_Tile : Tile
{
};

struct S_0072e370_Item
{
};

struct S_0072e370_Sub
{
    virtual void vfn0(int);
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

    S_0072e370_Item* FUN_007a1910();
};



struct S_0072e370
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10(int);
    virtual void vfn14(int, int);

    Tile* tile04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S_0072e370_Tile* tiles[22];
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    S_0072e370_Sub subA8;
    S_0072e370_Sub subD8;
    S_0072e370_Sub* unk108;

    void UpdateTileState(int a1, Tile* a2);
};

// @fnv 0x0072e370
void S_0072e370::UpdateTileState(int aiIndex, Tile* pTile)
{
    if (pTile == 0)
    {
        if (aiIndex >= 0 && aiIndex < 22)
        {
            pTile = this->tiles[aiIndex];
        }
    }

    switch (aiIndex)
    {
    case 0:
        this->vfn14(0x17, 0);
        this->subD8.vfn0(0);
        ((::Tile *)(reinterpret_cast<::Callees *>((this))->FUN_00726070()))->Set(DAT_011d8fb8, 0);
        this->unk108 = &this->subA8;
        break;

    case 1:
        this->vfn14(0x17, 0);
        this->subA8.vfn0(0);
        ((::Tile *)(reinterpret_cast<::Callees *>((this))->FUN_00726070()))->Set(DAT_011d8fb8, 1);
        this->unk108 = &this->subD8;
        break;

    case 23:
        DAT_0119fdb0 = 1;
        if (this->unk108 == 0)
        {
            this->vfn10(reinterpret_cast<::ListOwner *>(&(this->subD8))->ContainsKey((void *)(pTile)) ? 1 : 0);
        }
        DAT_011d8fa8 = this->unk108->FUN_007a1910();
        if (DAT_011d8fa8 != 0)
        {
            ::FUN_00707e30((::DisplayItem *)(DAT_011d8fa8), (::DisplayTile *)(this->tiles[21]));
            this->tiles[21]->Set(0xfa3, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->tiles[20]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::ItemChange_004be200 *>((DAT_011d8fa8))->GetIconFilename((::TESObjectREFR *)(0))), {});
            this->tiles[20]->Set(0xfa3, 1);
        }
        break;
    }
}

struct OwnExtraList
{
};

struct OwnNode
{
};

struct OwnExtraContainer
{
};

struct OwnItem
{
    OwnNode* FUN_00559450();
};
struct OwnItemExtra
{
};

struct OwnList : OwnNode
{
    OwnExtraList* m_pkItem;
    OwnNode* m_pkNext;
    OwnList();
    ~OwnList();
    void FUN_005ae3d0(OwnExtraList* const& pkItem);
};

struct OwnActor
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

    virtual bool IsActor();
};

struct OwnCheck
{
    char acData[0x68];
    OwnCheck();
    ~OwnCheck();
};

struct OwnBarterMenu
{
    char pad00[0x80];
    OwnActor* m_pkMerchant;
};

// @fnv 0x0072eac0
void __cdecl FUN_0072eac0(int iUnused, OwnItem* pkItem)
{
    OwnActor* pkMerchant_ = (*reinterpret_cast<::OwnBarterMenu * *>(&::DAT_011d8fa4))->m_pkMerchant && (*reinterpret_cast<::OwnBarterMenu * *>(&::DAT_011d8fa4))->m_pkMerchant->IsActor()
                                ? (*reinterpret_cast<::OwnBarterMenu * *>(&::DAT_011d8fa4))->m_pkMerchant
                                : 0;
    OwnList kRemoveY;
    for (OwnNode* pkNode = ((::OwnNode *)(::FUN_00559450((int *)(pkItem)))); pkNode && *((::OwnExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)); pkNode = ((::OwnNode *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())))
    {
        OwnExtraList* pkExtra = *((::OwnExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item));
        if (pkMerchant_ && ((void *)(reinterpret_cast<::FUN_00418660_shell *>((pkExtra))->FUN_00418660())))
        {
            OwnCheck kCheck;
            reinterpret_cast<::fnv_00567ad0::FUN_00567ad0 *>(&(kCheck))->SetOwner(((void *)(reinterpret_cast<::FUN_00418660_shell *>((pkExtra))->FUN_00418660())));
            reinterpret_cast<::Self567b50 *>(&(kCheck))->FUN_00567b50((::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_00418690_shell *>((pkExtra))->FUN_00418690()))));
            reinterpret_cast<::FUN_00567bd0_cls *>(&(kCheck))->FUN_00567bd0((unsigned int)(((reinterpret_cast<::FUN_004186c0_shell *>((pkExtra))->FUN_004186c0()))));
            reinterpret_cast<::Fn575690 *>(&(kCheck))->FUN_00575690(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((pkItem))->GetName())));
            if (reinterpret_cast<::OwnershipReferenceView *>(&(kCheck))->FUN_005785e0((::Actor *)(pkMerchant_), 1))
                kRemoveY.FUN_005ae3d0(pkExtra);
        }
    }
    for (OwnNode* pkIter = &kRemoveY; pkIter && *((::OwnExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item)); pkIter = ((::OwnNode *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070())))
    {
        reinterpret_cast<::CombatProcedure *>((pkItem))->Initialize((::CombatController *)(((std::intptr_t)(reinterpret_cast<::Callees *>((pkItem))->FUN_00726070())) - reinterpret_cast<::FUN_00418770_shell *>(((*((::OwnExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item)))))->FUN_00418770()));
        reinterpret_cast<::ItemChangeListNode *>((((OwnExtraContainer*)((::OwnNode *)(::FUN_00559450((int *)(pkItem)))))))->FUN_00905330((*(::InventoryStackRecord *const *)(((::OwnExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item)))));
    }
    reinterpret_cast<::FileMatchList *>(&(kRemoveY))->RemoveAll();
}

struct S_0072ed00_Tile
{
};
struct S_0072ed00_List
{
    int unk00;
};
struct S_0072ed00_Settings
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
    int unk88;
    int unk8c;
    int unk90;
    float unk94;
    float unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    S_0072ed00_List list_d8;
};
struct S_0072ed00_Item : InventoryEntry
{
};

// @fnv 0x0072ed00
float __cdecl FUN_0072ed00(S_0072ed00_Tile* tile, S_0072ed00_Item* item)
{
    float amount = reinterpret_cast<::ItemChangeValueShell *>((item))->FUN_004bd400();
    float base = amount;
    bool b5 = reinterpret_cast<::ListOwner *>(&(((S_0072ed00_Settings*)DAT_011d8fa4)->list_d8))->ContainsKey((void *)(tile));
    bool b8 = reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(DAT_011d8fb4);
    float result = 0.0f;
    if (amount < 0.0)
    {
        result = -1.0f;
    }
    else if ((b5 && !b8) || (!b5 && b8))
    {
        bool isEquip = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->FUN_00401170() == 0x6c || ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->FUN_00401170() == 0x74;
        amount *= isEquip ? 1.0f : ((S_0072ed00_Settings*)DAT_011d8fa4)->unk94;
        if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 > 0)
        {
            amount = (1.0 - std::abs(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0) * amount;
        }
        else if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 < 0)
        {
            amount = (std::abs(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0 + 1.0) * amount;
        }
        ::ApplyPerkModifiers(0x11, (::Actor *)(::_g_thePlayer), ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName())), &amount);
        if (FUN_00408860(amount) > 1.0)
            amount = ::InventoryStackRecord::RoundToNearestStep(amount, 1.0f);
        else
            amount = ::InventoryStackRecord::RoundToNearestStep(amount, 0.1f);
        result = FUN_00404010(amount, base);
    }
    else if ((b5 && b8) || (!b5 && !b8))
    {
        bool isEquip = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->FUN_00401170() == 0x6c || ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->FUN_00401170() == 0x74;
        amount *= isEquip ? 1.0f : ((S_0072ed00_Settings*)DAT_011d8fa4)->unk98;
        if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 > 0)
        {
            amount = (std::abs(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0 + 1.0) * amount;
        }
        else if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 < 0)
        {
            amount = (1.0 - std::abs(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0) * amount;
        }
        if (FUN_00408860(amount) > 1.0)
            amount = ::InventoryStackRecord::RoundToNearestStep(amount, 1.0f);
        else
            amount = ::InventoryStackRecord::RoundToNearestStep(amount, 0.1f);
        result = FUN_0040ebd0(amount, base);
    }
    return result;
}

struct SubNode
{
};

struct EntryEx : InventoryEntry
{
    SubNode* FUN_00559450();
};

struct ListNode
{
};

struct TargetClass
{
    InventoryEntry* FindMatchingEntry(ListNode* head, EntryEx* target);
};

// Walks the linked list and returns the first entry whose FUN_0044ddc0 value and FUN_00559450 sub-node value both match the target's.
// @fnv 0x0072f120
InventoryEntry* TargetClass::FindMatchingEntry(ListNode* head, EntryEx* target)
{
    InventoryEntry* result2 = 0;
    for (ListNode* node2 = head; !result2 && node2 && *((::EntryEx **)(&reinterpret_cast<::SimpleListNodeView*>(node2)->m_item)); node2 = ((::ListNode *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070())))
    {
        EntryEx* item5 = *((::EntryEx **)(&reinterpret_cast<::SimpleListNodeView*>(node2)->m_item));
        if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((target))->GetName())) == ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item5))->GetName())))
        {
            void* local7 = ((::SubNode *)(::FUN_00559450((int *)(target)))) ? *((void **)(&reinterpret_cast<::SimpleListNodeView*>(((::SubNode *)(::FUN_00559450((int *)(target)))))->m_item)) : 0;
            void* local_14 = ((::SubNode *)(::FUN_00559450((int *)(item5)))) ? *((void **)(&reinterpret_cast<::SimpleListNodeView*>(((::SubNode *)(::FUN_00559450((int *)(item5)))))->m_item)) : 0;
            if (local7 == local_14)
            {
                result2 = item5;
            }
        }
    }
    return result2;
}

namespace fnv_0072f210 {
struct BarterItem
{
};

struct BarterItemList;

struct BarterTile
{
};

struct BarterMenuStandIn
{
    char pad000[0x10c];
    int m_kMerchantItems[2];
    int m_kPlayerItems[2];

};


static const char s_szNumBartered[] = "_NumBartered";
static const char s_szCountFormat[] = "%s (%d)";
static const char s_szIsEquipped[] = "_IsEquipped";
static const char s_szNoValue[] = "--";
static const char s_szValueFormat1[] = "%.1f";
static const char s_szValueFormat0[] = "%.0f";
extern const char g_szBarterTileEnd[] = "";

// @fnv 0x0072f210
void __cdecl UpdateBarterItemTile(BarterTile* pkTile, BarterItem* pkItem)
{
    char acBuffer[0x80];
    float fValue = ::FUN_0072ed00((::S_0072ed00_Tile *)(pkTile), (::S_0072ed00_Item *)(pkItem));
    int iCount = 0;
    if (!reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(::DAT_011d8fb4))
    {
        BarterItem* pkOther =
            ((::fnv_0072f210::BarterItem *)(reinterpret_cast<::TargetClass *>(((*reinterpret_cast<::fnv_0072f210::BarterMenuStandIn * *>(&::DAT_011d8fa4))))->FindMatchingEntry((::ListNode *)((*reinterpret_cast<::fnv_0072f210::BarterMenuStandIn * *>(&::DAT_011d8fa4))->m_kMerchantItems), (::EntryEx *)(pkItem))));
        if (!pkOther)
            pkOther = ((::fnv_0072f210::BarterItem *)(reinterpret_cast<::TargetClass *>(((*reinterpret_cast<::fnv_0072f210::BarterMenuStandIn * *>(&::DAT_011d8fa4))))->FindMatchingEntry((::ListNode *)((*reinterpret_cast<::fnv_0072f210::BarterMenuStandIn * *>(&::DAT_011d8fa4))->m_kPlayerItems), (::EntryEx *)(pkItem))));
        iCount = ((int)(reinterpret_cast<::Callees *>((pkItem))->FUN_00726070())) - (pkOther ? ((int)(reinterpret_cast<::Callees *>((pkOther))->FUN_00726070())) : 0);
        reinterpret_cast<::Tile *>((pkTile))->Set(::FUN_00a01860(s_szNumBartered), pkOther ? ((int)(reinterpret_cast<::Callees *>((pkOther))->FUN_00726070())) : 0);
    }
    else
    {
        iCount = ((int)(reinterpret_cast<::Callees *>((pkItem))->FUN_00726070()));
    }
    if (iCount > 1)
    {
        ::FUN_00406d00(acBuffer, 0x80, s_szCountFormat, reinterpret_cast<::FUN_004be2d0_shell *>((pkItem))->GetTargetFullName(), iCount);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pkTile))->FUN_00a01350(0xfc4, (char *)(acBuffer), true);
    }
    if (reinterpret_cast<::FUN_004bddd0_shell *>((pkItem))->FUN_004bddd0(0) && !reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(::DAT_011d8fb4))
        reinterpret_cast<::Tile *>((pkTile))->Set(::FUN_00a00940(s_szIsEquipped, -1), 1);
    if (fValue <= 0.0)
        ::TaskQueueInterface::CopyStringToBuffer(acBuffer, 0x80, s_szNoValue);
    else if (fValue > 0.0 && fValue < 1.0)
        ::FUN_00406d00(acBuffer, 0x80, s_szValueFormat1, fValue);
    else
        ::FUN_00406d00(acBuffer, 0x80, s_szValueFormat0, fValue);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pkTile))->FUN_00a01350(g_iTileIDValue_011d8fb0, (char *)(acBuffer), true);
    reinterpret_cast<::Tile *>((pkTile))->SetName(reinterpret_cast<::FUN_004be2d0_shell *>((pkItem))->GetTargetFullName());
    reinterpret_cast<::FUN_00a012d0_t *>((pkTile))->FUN_00a012d0(0xfb0, 0.0f, true);
}
}  // namespace fnv_0072f210

// HandleAction candidate
bool __cdecl FUN_00702450(int aiId);

struct FUN_007312e0_shell
{
    void FUN_007312e0();
};
struct FUN_00731360_shell
{
};
struct FUN_00730e20_shell
{
};
struct FUN_00726c40_shell
{
};

struct FUN_0072f4b0_sub
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
};

class FUN_0072f4b0_cls
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(int aiA, int aiB);
    virtual void v04(int aiA, int aiB);
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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    FUN_0072f4b0_sub m_a8;
    FUN_0072f4b0_sub m_d8;
    void* m_108;

    bool HandleAction(int a1, int a2);
};

namespace fnv_0072f6f0 {
struct QtyTile
{
};

struct QtyForm;
struct QtyItem
{
};

struct QtyItemList
{
};
struct QtyChangeList
{
    bool FUN_008256d0();
};

struct QtyPlayer
{
};

struct QtyBarterMenu
{
    int unk00;
    QtyTile* unk04;
    char pad08[0x58 - 8];
    QtyTile* unk58;
    QtyTile* unk5c;
    char pad60[0x84 - 0x60];
    float m_fBarterTotal;
    int unk88;
    int m_iMerchantCaps;
    int unk90;
    char pad94[0xa8 - 0x94];
    QtyItemList m_kMerchantList;
    char pada9[0xd8 - 0xa9];
    QtyItemList m_kPlayerList;
    char padd9[0x108 - 0xd9];
    QtyItemList* m_pkActiveList;
    QtyChangeList m_kMerchantItems;
    char pad10d[0x114 - 0x10d];
    QtyChangeList m_kPlayerItems;

    void DecrementEntryCount(int iCount);
    void RebuildInventoryLists(QtyForm* pkForm);
};

int __cdecl FUN_0072fa60(int i);

static const char s_szIntFormat[] = "%d";
extern const char g_szBarterQtyEnd[] = "";

// @fnv 0x0072f6f0
void __cdecl UpdateBarterQuantity(int iCount)
{
    QtyTile* pkTile = ((::fnv_0072f6f0::QtyTile *)(reinterpret_cast<::Owner *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_pkActiveList))->FindItemData((int *)(::fnv_0072f6f0::QtyItem **)(&(*reinterpret_cast<::fnv_0072f6f0::QtyItem * *>(&::DAT_011d8fa8))))));
    if (!iCount || !(*reinterpret_cast<::fnv_0072f6f0::QtyItem * *>(&::DAT_011d8fa8)) || !pkTile)
        return;
    (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal +=
        ::FUN_0072ed00((::S_0072ed00_Tile *)(pkTile), (::S_0072ed00_Item *)((*reinterpret_cast<::fnv_0072f6f0::QtyItem * *>(&::DAT_011d8fa8)))) *
        ((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_pkActiveList == &(*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_kMerchantList ? 1 : -1) * iCount;
    reinterpret_cast<::ActorSoundStub *>(((*reinterpret_cast<::fnv_0072f6f0::QtyPlayer * *>(&::_g_thePlayer))))->PlayActorSound(
        (int)(((::fnv_0072f6f0::QtyForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_0072f6f0::QtyItem * *>(&::DAT_011d8fa8))))->GetName()))),
        (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_pkActiveList == &(*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_kPlayerList, 0);
    if (reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(::DAT_011d8fb4))
        (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->DecrementEntryCount(iCount);
    else
        reinterpret_cast<::InvOwner *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))))->AddOrUpdateEntryCount(iCount);
    (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->RebuildInventoryLists(((::fnv_0072f6f0::QtyForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_0072f6f0::QtyItem * *>(&::DAT_011d8fa8))))->GetName())));
    if (!(*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_kMerchantItems.FUN_008256d0() ||
        !(*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_kPlayerItems.FUN_008256d0())
    {
        char acBufferTmp[0x10];
        int iCaps_2 = ::FUN_00406d90(::FUN_00406ce0((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal));
        reinterpret_cast<::Tile *>((((::fnv_0072f6f0::QtyTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))))->FUN_00726070()))))->Set(g_iTileIDState_011d8fbc,
                                                              (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal > 0.0 ? 2 : 1);
        ::FUN_00406d00(acBufferTmp, 0x10, s_szIntFormat, FUN_0072fa60(::MinInt(iCaps_2, (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk90)));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk58))->FUN_00a01350(::fnv_0072f210::g_iTileIDValue_011d8fb0, (char *)(acBufferTmp), true);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk58))->Set(0xfa3, 1);
        if ((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal > 0.0 ||
            ((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal <= 0.0 &&
             (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_iMerchantCaps >= -(*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal))
        {
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk5c))->Set(0xfaf, 1);
            if ((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal > 0.0 &&
                (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->m_fBarterTotal > (*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk90)
                reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk58))->FUN_00a012d0(0xfa9, 64.0f, true);
            else
                reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk58))->FUN_00a012d0(0xfa9, 255.0f, true);
        }
        else
        {
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk5c))->Set(0xfaf, 0);
            reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk58))->FUN_00a012d0(0xfa9, 64.0f, true);
        }
    }
    else
    {
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk5c))->Set(0xfaf, 0);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_0072f6f0::QtyBarterMenu * *>(&::DAT_011d8fa4))->unk58))->Set(0xfa3, 0);
    }
}
}  // namespace fnv_0072f6f0

struct FC30Data
{
};

struct FC30Entry
{
    ~FC30Entry();

};

struct FC30List
{
    int m_pHead;
    int m_pTail;

};

struct FC30State
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
};


struct FC30Container
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    FC30State m_kState;
    FC30State* m_pkState;
    FC30List m_kListA;
    FC30List m_kListB;

    void DecrementEntryCount(int iCount);
};

// @fnv 0x0072fc30
void FC30Container::DecrementEntryCount(int iCount)
{
    int iValue;
    FC30List* pkListA = (m_pkState == &m_kState) ? &m_kListA : &m_kListB;
    FC30Entry* pkEntry = ((::FC30Entry *)(reinterpret_cast<::TargetClass *>(this)->FindMatchingEntry((::ListNode *)(pkListA), (::EntryEx *)((*reinterpret_cast<void * *>(&::DAT_011d8fa8))))));
    iValue = ((::FC30Data *)(::FUN_00559450((int *)(pkEntry)))) ? *((int *)(&reinterpret_cast<::SimpleListNodeView*>(((::FC30Data *)(::FUN_00559450((int *)(pkEntry)))))->m_item)) : 0;
    if (((std::intptr_t)(reinterpret_cast<::Callees *>((pkEntry))->FUN_00726070())) - iCount <= 0)
    {
        reinterpret_cast<::ItemChangeListNode *>((pkListA))->FUN_00905330((::InventoryStackRecord *const &)(pkEntry));
        delete pkEntry;
    }
    else
    {
        reinterpret_cast<::CombatProcedure *>((pkEntry))->Initialize((::CombatController *)(((std::intptr_t)(reinterpret_cast<::Callees *>((pkEntry))->FUN_00726070())) - iCount));
    }
}

struct LbTile
{
};

struct LbItem
{
    LbTile* m_pkTile;
    void* m_pPointer;
    bool m_bFiltered;
};

struct LbNode
{
};

struct LbMenuBase
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual LbTile* GetTileAt(int iIndex, int i);
};

struct LbList : LbNode
{
    LbItem* m_pkItem;
    LbNode* m_pkNext;
};

static const char s_szNumFiltered[] = "_num_filtered";
extern const char g_szListBoxEnd[] = "";

struct ListBoxImpl : LbMenuBase, LbList
{
    LbTile* m_pkParentTile;
    LbTile* m_pkSelected;
    int unk14;
    int unk18;
    unsigned short m_usElementCount;
    float m_fScroll;

    void ApplyFilter(bool(__cdecl* pfnFilter)(void* pkObject));
};

// Marks each item as filtered by pfnFilter, renumbers the visible tiles, updates the filtered count, and restores the selection.
// @fnv 0x00730bb0
void ListBoxImpl::ApplyFilter(bool(__cdecl* pfnFilter)(void* pkObject))
{
    int iFilteredCount = 0;
    int iSelectedIndex = -1;
    static int s_iNumFilteredID = FUN_00a00940(s_szNumFiltered, -1);
    m_usElementCount = 0;
    m_fScroll = 0.0f;
    for (LbNode* pkNode = this; pkNode && *((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)); pkNode = ((::LbNode *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())))
    {
        (*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_bFiltered = pfnFilter && pfnFilter((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pPointer) ? 1 : 0;
        if ((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_bFiltered)
        {
            if ((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pkTile == m_pkSelected)
            {
                iSelectedIndex = (int)reinterpret_cast<::TileListBoxCalls *>(((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pkTile))->GetFloat(0xfac);
                m_pkSelected = 0;
            }
            reinterpret_cast<::Tile *>(((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pkTile))->Set(0xfac, -1);
            iFilteredCount++;
        }
        else
        {
            if (iSelectedIndex >= 0 && m_usElementCount == iSelectedIndex)
                m_pkSelected = (*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pkTile;
            reinterpret_cast<::Tile *>(((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pkTile))->Set(0xfac, m_usElementCount++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::LbItem **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item)))->m_pkTile));
        }
    }
    reinterpret_cast<::Tile *>((m_pkParentTile))->Set(s_iNumFilteredID, iFilteredCount);
    reinterpret_cast<::ListBox_71ad30 *>(this)->UpdateScrollPages();
    if (!m_pkSelected && iSelectedIndex >= 0)
        m_pkSelected = GetTileAt(iSelectedIndex, 0);
    if (!m_pkSelected && iSelectedIndex >= 0)
        m_pkSelected = ((::LbTile *)(reinterpret_cast<::S *>(this)->FUN_007315b0()));
    reinterpret_cast<::ListBoxZ *>(this)->FUN_0071a740();
}

class C72CEB0Menu
{
  public:
    C72CEB0Menu();
    virtual ~C72CEB0Menu();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class C72CEB0ListBox
{
  public:
    C72CEB0ListBox();
    ~C72CEB0ListBox();

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
};

class C72CEB0StringList
{
  public:
    C72CEB0StringList();
    ~C72CEB0StringList();

    void* m_pvHead;
    void* m_pvTail;
};


extern const char g_ac72CEB0Trait2[];
extern const char g_ac72CEB0Trait3[];
extern const char g_ac72CEB0Trait4[];

extern int g_i72CEB0Trait0;

class FUN_0072ceb0 : public C72CEB0Menu
{
  public:
    FUN_0072ceb0();
    virtual ~FUN_0072ceb0();

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
    int unk88;
    int m_i8C;
    int m_i90;
    float m_f94;
    float m_f98;
    int m_i9C;
    int m_iA0;
    int m_iA4;
    C72CEB0ListBox m_kFirstList;
    C72CEB0ListBox m_kSecondList;
    int m_i108;
    C72CEB0StringList m_kFirstStrings;
    C72CEB0StringList m_kSecondStrings;
    bool m_b11C;
};

// @fnv 0x0072ceb0
FUN_0072ceb0::FUN_0072ceb0()
{
    g_i72CEB0Trait0 = ::FUN_00a01860(::DAT_0106ed20);
    ::fnv_0072f210::g_iTileIDValue_011d8fb0 = ::FUN_00a01860(::DAT_0106ed18);
    ::DAT_011d8fb4 = ::FUN_00a01860(g_ac72CEB0Trait2);
    ::DAT_011d8fb8 = ::FUN_00a01860(g_ac72CEB0Trait3);
    ::fnv_0072f6f0::g_iTileIDState_011d8fbc = ::FUN_00a01860(g_ac72CEB0Trait4);
    (*reinterpret_cast<int *>(&::DAT_011d8fa8)) = 0;
    m_i108 = 0;
    m_i8C = 0;
    m_i90 = 0;
    m_f94 = 1.0f;
    m_f98 = 1.0f;
    m_b11C = false;
    m_i9C = 0;
    m_iA0 = 0;
    m_iA4 = 3;
}

struct ListObj;
struct NodeS;
struct PtrObj
{
    PtrObj* FUN_00559450();
    void FUN_005ae3d0(void** pp);
};
struct EntryObj
{
    ~EntryObj();
    int FUN_004459e0(int a);
    PtrObj* FUN_00559450();
};
struct NodeS
{
    void* m_00;
    void* m_04;
};
struct ListObj
{
    virtual void vtbl000();
    virtual int PredHead();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void Virt20(void* fn);
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
};
struct LocalList
{
    void* m_00;
    void* m_04;
    LocalList();
    ~LocalList();
};
struct NewObj
{
    void* m_00;
    int m_04;
    void* m_08;
    NewObj(void* a, int b);
    PtrObj* FUN_00559450();
};
struct DataSource
{
};
struct DataHandler
{
};
struct TileLike
{
};
struct PlayerCharacter;
class InventoryEntry;
bool __cdecl IsFilteredFromBarter(EntryObj* e);
void __cdecl AddHeadImpl(void* list, void** pp);
struct IMObj
{
};

struct Self72
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void Virt0c(int a, int b);
    virtual void Virt10(int a, int b);
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
    void* m_80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int m_a4;
    ListObj m_a8;
    ListObj m_d8;
    ListObj* m_108;
    NodeS m_10c;
    NodeS m_114;
    void RebuildInventoryLists(intptr_t arg);
};
// @fnv 0x0072d770
void BarterMenuClick::HandleTileClick(int iTileIndex, BmTile* pkTile)
{
    if (!pkTile && iTileIndex >= 0 && iTileIndex < 0x16)
        pkTile = m_apTiles[iTileIndex];
    switch (iTileIndex)
    {
    case 23:
        if ((*reinterpret_cast<::BmItem * *>(&::DAT_011d8fa8)) && pkTile)
        {
            ::DAT_0119fdb0 = 0;
            int iCount = ((int)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::BmItem * *>(&::DAT_011d8fa8))))->FUN_00726070())) -
                         ::FUN_00406d90(reinterpret_cast<::TileListBoxCalls *>((pkTile))->GetFloat(FUN_00a01860(s_szNumBartered)));
            if (::fnv_00703d50::FUN_00703d50())
            {
                BmRef* pkOrig = ((::BmExtraNode *)(::FUN_00559450((int *)((*reinterpret_cast<::BmItem * *>(&::DAT_011d8fa8)))))) &&
                                        *((::BmExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(((::BmExtraNode *)(::FUN_00559450((int *)((*reinterpret_cast<::BmItem * *>(&::DAT_011d8fa8)))))))->m_item))
                                    ? ((::BmRef *)(reinterpret_cast<::FUN_00418630_Class *>(((*((::BmExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(((::BmExtraNode *)(::FUN_00559450((int *)((*reinterpret_cast<::BmItem * *>(&::DAT_011d8fa8)))))))->m_item)))))->FUN_00418630()))
                                    : 0;
                if (pkOrig)
                    ::FUN_00703c00(s_szOrigRef, pkOrig->GetEditorID());
                else
                    ::FUN_00703c00(s_szOrigRefNone, {});
            }
            else if (iCount > *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::BmIntSetting *>(&::g_011d2418)))))))
            {
                reinterpret_cast<::FUN_007312e0_shell *>((unk108))->FUN_007312e0();
                unk108->Destroy(false);
                ::CreateQuantityMenu(iCount, ::fnv_0072f6f0::UpdateBarterQuantity, 0x7fffffff);
            }
            else
            {
                ::fnv_0072f6f0::UpdateBarterQuantity(1);
            }
        }
        break;
    case 13:
        ::DAT_0119fdb0 = 0;
        CompleteBarterTransaction();
        reinterpret_cast<::Self72 *>(this)->RebuildInventoryLists(0);
        break;
    case 19:
        if (m_kMerchantItems.FUN_005ae380() || m_kPlayerItems.FUN_005ae380())
            ::fnv_00703e80::FUN_00703e80((const char *)(0), (const char *)(0), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::BmStrSetting *>(&::g_011d1fa4))))->GetMenuTitle())), FUN_0072db40, 0, 0x17, 0.0f, 0.0f,
                         ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::BmStrSetting *>(&::g_011d34f8))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::BmStrSetting *>(&::g_011d3684))))->GetMenuTitle())), 0);
        else
            UpdateTopicMenu();
        break;
    case 2:
    case 3:
    case 4:
        ::FUN_00706f30((intptr_t)(unka4));
        do
        {
            m_iMerchantFilter += (iTileIndex != 2 ? 1 : -1);
            if (m_iMerchantFilter < 0)
                m_iMerchantFilter = 5;
            else if (m_iMerchantFilter > 5)
                m_iMerchantFilter = 0;
            reinterpret_cast<::Menu_007301f0 *>(this)->UpdateTileText((::P09TileS *)((std::intptr_t)m_apTiles[3]));
            reinterpret_cast<::ListBoxImpl *>(&(m_kMerchantList))->ApplyFilter((bool (*)(void *))(((int (&)(void *))::FUN_007304b0)));
        } while (!((int)(reinterpret_cast<::FUN_0071ae60_shell *>(&(m_kMerchantList))->FUN_0071ae60())) && m_iMerchantFilter != 0);
        break;
    case 7:
    case 8:
    case 9:
        ::FUN_00706f30((intptr_t)(unka4));
        do
        {
            m_iPlayerFilter += (iTileIndex != 7 ? 1 : -1);
            if (m_iPlayerFilter < 0)
                m_iPlayerFilter = 5;
            else if (m_iPlayerFilter > 5)
                m_iPlayerFilter = 0;
            reinterpret_cast<::Menu_007301f0 *>(this)->UpdateTileText((::P09TileS *)((std::intptr_t)m_apTiles[8]));
            reinterpret_cast<::ListBoxImpl *>(&(m_kPlayerList))->ApplyFilter((bool (*)(void *))(((int (&)(void *))::FUN_007304b0)));
        } while (!((int)(reinterpret_cast<::FUN_0071ae60_shell *>(&(m_kPlayerList))->FUN_0071ae60())) && m_iPlayerFilter != 0);
        break;
    }
}

// List sort comparator: entries whose tile has the highlight trait come first, then order by tile text.



class F070Tile
{
  public:
};

struct F070Entry
{
    F070Tile* m_pkTile;
    void* m_pvItem;
};

// Compares two entries by the highlight trait first, then by the string from trait 0xfc4, returning -1, 1 or the string comparison result.
// @fnv 0x0072f070
int CompareF070Entries(F070Entry* pkA, F070Entry* pkB)
{
    void* pvItemA = pkA->m_pvItem;
    void* pvDataB = pkB->m_pvItem;
    int iResult = 0;
    bool bHighlightA = reinterpret_cast<::FUN_00a01230_shell *>((pkA->m_pkTile))->IsTraitNonZero(::DAT_011d8fb4);
    bool bB = reinterpret_cast<::FUN_00a01230_shell *>((pkB->m_pkTile))->IsTraitNonZero(::DAT_011d8fb4);
    if (bHighlightA && !bB)
        iResult = -1;
    else if (!bHighlightA && bB)
        iResult = 1;
    else
        iResult = ::FUN_00469880((void *)((const unsigned char*)reinterpret_cast<::FUN_00a011f0_shell *>((pkA->m_pkTile))->FUN_00a011f0(0xfc4)),
                          (void *)((const unsigned char*)reinterpret_cast<::FUN_00a011f0_shell *>((pkB->m_pkTile))->FUN_00a011f0(0xfc4)));
    return iResult;
}

namespace fnv_0072fd10 {
struct ExtraDataList;
struct TESObjectREFR;
struct InventoryStackRecord;

struct ExtraDataListNode
{
};

struct InventoryStackRecord
{
    ExtraDataListNode* m_extendData;
    int m_countDelta;
    TESBoundObject* m_type;

    InventoryStackRecord(TESBoundObject* apType, int aiCount);
    ~InventoryStackRecord();
    ExtraDataListNode* FUN_00559450();
};

struct ItemChangeNode
{
    InventoryStackRecord* m_item;
    ItemChangeNode* m_next;
};

struct InventoryChangesStandIn
{
};

struct ProcessStandIn
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
    virtual InventoryStackRecord* GetActiveWeapon();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void SetCurrentArmor(InventoryStackRecord* apWeapon);
};

struct ActorStandIn
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
    virtual void AddItem(TESBoundObject* apItem, ExtraDataList* apExtraList, int aiCount, int a3, int a4,
                         TESObjectREFR* apOther, int a6, int a7, int a8, int a9);
};


struct TESQuestStageList
{
};

struct TESObjectREFR
{
};

struct ItemTransferManager
{
};

void __cdecl FUN_004d5e10(int aiID, const char* apText);

struct SoundPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    ~SoundPlaybackHandle();
};

struct BSAudioStandIn
{
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* apName, unsigned int auiFlags, int aiUnk);
};

struct BarterMenuGlobals
{
    char pad00[0x58];
    Tile* unk58;
    Tile* unk5c;
    char pad60[0x24];
    float unk84;
};

struct BarterMenuImpl
{
    char pad00[0x80];
    TESObjectREFR* m_merchant;
    float m_barterTotal;
    char pad88[8];
    int unk90;
    char pad94[0x10c - 0x94];
    ItemChangeNode m_merchantItems;
    ItemChangeNode m_playerItems;
    unsigned char unk11c;

    void CompleteBarterTransaction();
};

// Transfers merchant and player barter items, adjusts caps based on m_barterTotal, plays a sound, resets totals and clears the equipped weapon if it was sold.
// @fnv 0x0072fd10
void BarterMenuImpl::CompleteBarterTransaction()
{
    TESObjectREFR* pTarget3 =
        ((::fnv_0072fd10::TESObjectREFR *)(reinterpret_cast<::fnv_00421400::FUN_00421400 *>((((::fnv_0072fd10::TESQuestStageList *)(reinterpret_cast<::FUN_005d43c0_ *>((m_merchant))->FUN_005d43c0()))))->GetMerchantContainer())) ? ((::fnv_0072fd10::TESObjectREFR *)(reinterpret_cast<::fnv_00421400::FUN_00421400 *>((((::fnv_0072fd10::TESQuestStageList *)(reinterpret_cast<::FUN_005d43c0_ *>((m_merchant))->FUN_005d43c0()))))->GetMerchantContainer())) : m_merchant;
    InventoryStackRecord* pWeapon3 = ((::fnv_0072fd10::ProcessStandIn *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetActiveWeapon();

    for (ItemChangeNode* pNode6 = &m_merchantItems; pNode6 && *((::fnv_0072fd10::InventoryStackRecord **)(&reinterpret_cast<::SimpleListNodeView*>(pNode6)->m_item)); pNode6 = ((::fnv_0072fd10::ItemChangeNode *)(reinterpret_cast<::Callees *>((pNode6))->FUN_00726070())))
    {
        InventoryStackRecord* pItem = *((::fnv_0072fd10::InventoryStackRecord **)(&reinterpret_cast<::SimpleListNodeView*>(pNode6)->m_item));
        ExtraDataList* pExtraList = ((::fnv_0072fd10::ExtraDataListNode *)(::FUN_00559450((int *)(pItem)))) ? *((::fnv_0072fd10::ExtraDataList **)(&reinterpret_cast<::SimpleListNodeView*>(((::fnv_0072fd10::ExtraDataListNode *)(::FUN_00559450((int *)(pItem)))))->m_item)) : 0;
        if (pExtraList)
            ::FUN_005ac750((::TESForm *)(m_merchant), (::ExtraDataList *)(pExtraList), 0x4000);
        reinterpret_cast<::FUN_0046f640_shell *>(((*reinterpret_cast<::fnv_0072fd10::ItemTransferManager * *>(&::g_dataHandler))))->ProcessInventoryRecords((::FNVFile *)(pItem), ((int)(reinterpret_cast<::Callees *>((pItem))->FUN_00726070())), (intptr_t)(m_merchant));
        delete pItem;
    }

    for (ItemChangeNode* pNode3 = &m_playerItems; pNode3 && *((::fnv_0072fd10::InventoryStackRecord **)(&reinterpret_cast<::SimpleListNodeView*>(pNode3)->m_item)); pNode3 = ((::fnv_0072fd10::ItemChangeNode *)(reinterpret_cast<::Callees *>((pNode3))->FUN_00726070())))
    {
        InventoryStackRecord* pItem3 = *((::fnv_0072fd10::InventoryStackRecord **)(&reinterpret_cast<::SimpleListNodeView*>(pNode3)->m_item));
        ExtraDataList* pExtraList5 = ((::fnv_0072fd10::ExtraDataListNode *)(::FUN_00559450((int *)(pItem3)))) ? *((::fnv_0072fd10::ExtraDataList **)(&reinterpret_cast<::SimpleListNodeView*>(((::fnv_0072fd10::ExtraDataListNode *)(::FUN_00559450((int *)(pItem3)))))->m_item)) : 0;
        if (pExtraList5)
            ::FUN_005ac750((::TESForm *)(::fnv_0072fd10::TESObjectREFR *)((TESObjectREFR*)(*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))), (::ExtraDataList *)(pExtraList5), 0x4000);
        (*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))->AddItem(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pItem3))->GetName())), pExtraList5, ((int)(reinterpret_cast<::Callees *>((pItem3))->FUN_00726070())), 0, 0, pTarget3, 0, 0, 1,
                                   0);
        delete pItem3;
    }

    ((BarterMenuGlobals*)DAT_011d8fa4)->unk5c->Set(0xfaf, 0);
    ((BarterMenuGlobals*)DAT_011d8fa4)->unk58->Set(0xfa3, 0);

    InventoryChangesStandIn* pChanges = 0;
    int iAmount5 = ::FUN_00406d90(::FUN_00406ce0(((BarterMenuGlobals*)DAT_011d8fa4)->unk84));
    FUN_004d5e10(0x27, ((const char *)(std::uintptr_t)(std::abs(iAmount5))));

    if (m_barterTotal > 0.0)
    {
        InventoryStackRecord kCaps9(((::TESBoundObject *)(::FUN_004839c0(0xf))), 0);
        pChanges = ((::fnv_0072fd10::InventoryChangesStandIn *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(pTarget3))));
        if (pChanges)
            reinterpret_cast<::FUN_0046f640_shell *>(((*reinterpret_cast<::fnv_0072fd10::ItemTransferManager * *>(&::g_dataHandler))))->ProcessInventoryRecords((::FNVFile *)(::fnv_0072fd10::InventoryStackRecord *)(&kCaps9), ::MinInt(iAmount5, unk90), (intptr_t)(m_merchant));
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0072fd10::SoundPlaybackHandle &)(((::fnv_0072fd10::BSAudioStandIn *)(::FUN_00453a70()))->GetSoundHandleByEditorID("ITMBottlecapsUp", 0x101, 0)))->FUN_00ad8830({});
    }
    else if (m_barterTotal < 0.0)
    {
        pChanges = ((::fnv_0072fd10::InventoryChangesStandIn *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(::fnv_0072fd10::TESObjectREFR *)((TESObjectREFR*)(*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))))));
        if (pChanges)
            reinterpret_cast<::Inv4cb4b0 *>((pChanges))->FUN_004cb4b0((intptr_t)((TESObjectREFR*)(*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))), -iAmount5, (intptr_t)(pTarget3));
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0072fd10::SoundPlaybackHandle &)(((::fnv_0072fd10::BSAudioStandIn *)(::FUN_00453a70()))->GetSoundHandleByEditorID("ITMBottlecapsDown", 0x101, 0)))->FUN_00ad8830({});
    }

    m_barterTotal = 0.0f;
    reinterpret_cast<::FileMatchList *>(&(m_merchantItems))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(m_playerItems))->RemoveAll();
    unk11c = 1;

    if (pWeapon3 && !reinterpret_cast<::FUN_004c8f30_shell *>((((::fnv_0072fd10::InventoryChangesStandIn *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(::fnv_0072fd10::TESObjectREFR *)((TESObjectREFR*)(*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))))))))->FUN_004c8f30((int)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeapon3))->GetName())))))
        ((::fnv_0072fd10::ProcessStandIn *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_0072fd10::ActorStandIn * *>(&::_g_thePlayer))))->GetBaseTexture()))->SetCurrentArmor(0);
}
}  // namespace fnv_0072fd10


struct TESBoundObjectExt
{
};

struct FUN_007306d0_cls
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
    int unk54;
    int unk58;
    int unk5C;
    intptr_t m_60;
    intptr_t m_64;
    intptr_t m_68;
    int m_6c;
    int m_70;

    void FUN_007306d0();
};

// @fnv 0x007306d0
void FUN_007306d0_cls::FUN_007306d0()
{
    if (DAT_011d8fc0 == 1)
    {
        FUN_00730690(true);
    }
    if (DAT_0119fdb0 != 0)
    {
        if (DAT_011d8fa8 != 0)
        {
            if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)DAT_011d8fa8)))->GetName()))->FUN_00401170() == 0x28)
            {
                ::UpdateAnimationTileFade((::AnimationTile *)(m_60), (::AnimationTile *)(m_64), (::AnimationTile *)(m_68), (::AnimationReference *)(DAT_011d8fa8), 0);
                return;
            }
        }
        if (DAT_011d8fa8 != 0)
        {
            if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)DAT_011d8fa8)))->GetName()))->FUN_00401170() == 0x18)
            {

                ::UpdateAnimationTileFade(
                    (::AnimationTile *)((DAT_011d8fa8 != 0 &&
                     ::_DAT_01012060 !=
                         ((double)(::FUN_004be060((void *)(((TESBoundObjectExt*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)DAT_011d8fa8)))->GetName()))))))))
                        ? m_6c
                        : 0),
                    (::AnimationTile *)((DAT_011d8fa8 != 0 &&
                     ::_DAT_01012060 !=
                         ((double)(::FUN_004be180((char *)(((TESBoundObjectExt*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)DAT_011d8fa8)))->GetName()))))))))
                        ? m_70
                        : 0),
                    (::AnimationTile *)(0), (::AnimationReference *)(DAT_011d8fa8), 0);
            }
        }
    }
}

struct Tile7313
{
};
struct Menu7313
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void SetValue7313(int iValue, Tile7313* pTile);
};
struct Holder7313
{
};
struct Traits7313
{
};
struct IM7313
{
};
struct List7313
{
    virtual void SetSelected7313(Tile7313* pTile);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual Tile7313* GetTile7313(unsigned int uiIndex);
    void* pad[2];
    Holder7313* m_0c;
    void* padCur;
    Traits7313* m_14;
    void* kad[3];
    float m_24;
    float m_28;
    void UpdateCurrentValueTile(bool abFlag);
};
// @fnv 0x0072f4b0
bool FUN_0072f4b0_cls::HandleAction(int aiAction, int aiUnused)
{
    bool bHandled = false;
    if (FUN_00702450(0x41d))
    {
        switch (aiAction)
        {
        case 13:
            if (!reinterpret_cast<::FUN_00730e20_cls *>((reinterpret_cast<FUN_00730e20_shell*>(&m_a8)))->FUN_00730e20())
            {
                if (((unsigned int)(::GetRaceCount((char *)(reinterpret_cast<FUN_00726c40_shell*>(&m_a8))))) > 0)
                {
                    reinterpret_cast<FUN_007312e0_shell*>(&m_d8)->FUN_007312e0();
                    v04(0, 0);
                    reinterpret_cast<::List7313 *>((reinterpret_cast<FUN_00731360_shell*>(&m_a8)))->UpdateCurrentValueTile(1);
                    bHandled = true;
                }
            }
            break;
        case 14:
            if (!reinterpret_cast<::FUN_00730e20_cls *>((reinterpret_cast<FUN_00730e20_shell*>(&m_d8)))->FUN_00730e20())
            {
                if (((unsigned int)(::GetRaceCount((char *)(reinterpret_cast<FUN_00726c40_shell*>(&m_d8))))) > 0)
                {
                    reinterpret_cast<FUN_007312e0_shell*>(&m_a8)->FUN_007312e0();
                    v04(1, 0);
                    reinterpret_cast<::List7313 *>((reinterpret_cast<FUN_00731360_shell*>(&m_d8)))->UpdateCurrentValueTile(1);
                    bHandled = true;
                }
            }
            break;
        case 3:
        case 4:
            if (m_108 == &m_a8)
            {
                reinterpret_cast<FUN_007312e0_shell*>(&m_a8)->FUN_007312e0();
                v03((aiAction != 4) ? 4 : 2, 0);
                reinterpret_cast<::List7313 *>((reinterpret_cast<FUN_00731360_shell*>(&m_a8)))->UpdateCurrentValueTile(0);
            }
            else
            {
                reinterpret_cast<FUN_007312e0_shell*>(&m_d8)->FUN_007312e0();
                v03((aiAction != 4) ? 9 : 7, 0);
                reinterpret_cast<::List7313 *>((reinterpret_cast<FUN_00731360_shell*>(&m_d8)))->UpdateCurrentValueTile(0);
            }
            bHandled = true;
            break;
        }
    }
    return bHandled;
}
// Rebuilds the m_a8/m_d8 lists from the player and data handler for the given form, then selects and activates m_108 and calls FUN_0072db60.
// @fnv 0x0072dc30
void Self72::RebuildInventoryLists(intptr_t arg)
{
    long i = 0;
    if (m_108 != 0)
    {
        if (m_108->PredHead())
        {
            reinterpret_cast<::FUN_007312e0_shell *>((m_108))->FUN_007312e0();
        }
    }
    if (arg != 0)
    {
        LocalList b;
        void* n;
        n = ((void *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(void *)((void*)::_g_thePlayer))));
        void* res = ((void *)(reinterpret_cast<::FUN_00740960_Class *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->FUN_00740960()));
        if (n != 0)
        {
            reinterpret_cast<::Host_004d4b00 *>((((DataSource*)n)))->FindEntriesByType(arg, (::Output_004d4b00 *)(::LocalList *)(&b));
            reinterpret_cast<::FunctionOwner *>(&(m_a8))->FUN_0071a200(arg);
            NodeS* kZero = (NodeS*)&b;
            for (; kZero != 0 && *((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)) != 0; kZero = ((::NodeS *)(reinterpret_cast<::Callees *>((kZero))->FUN_00726070())))
            {
                if (!(bool)FUN_0072e570((InventoryEntry*)*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item))))
                {
                    reinterpret_cast<::list71a::L71Menu *>(&(m_a8))->FUN_0071a320((intptr_t)(*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item))), reinterpret_cast<::FUN_004be2d0_shell *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0));
                }
                else
                {
                    delete *((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item));
                }
            }
            reinterpret_cast<::FileMatchList *>(&(b))->RemoveAll();
        }
        if (res != 0)
        {
            reinterpret_cast<::Host_004d4b00 *>((((DataSource*)res)))->FindEntriesByType(arg, (::Output_004d4b00 *)(::LocalList *)(&b));
            reinterpret_cast<::FunctionOwner *>(&(m_d8))->FUN_0071a200(arg);
            NodeS* kZero;
            kZero = (NodeS*)&b;
            for (; kZero != 0 && *((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)) != 0; kZero = ((::NodeS *)(reinterpret_cast<::Callees *>((kZero))->FUN_00726070())))
            {
                if (!(bool)IsFilteredFromBarter(*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item))))
                {
                    reinterpret_cast<::list71a::L71Menu *>(&(m_d8))->FUN_0071a320((intptr_t)(*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item))), reinterpret_cast<::FUN_004be2d0_shell *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0));
                }
                else
                {
                    delete *((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item));
                }
            }
            reinterpret_cast<::FileMatchList *>(&(b))->RemoveAll();
        }
    }
    else
    {
        reinterpret_cast<::InventoryHandler *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->UpdateInventoryForReference((::TESObjectREFR *)(m_80));
        reinterpret_cast<::InventoryListBox *>(&(m_a8))->PopulateInventoryList((::InventoryOwner *)(void *)((void*)::_g_thePlayer), (bool (*)(InventoryEntry *))(void *)((void*)::FUN_0072e570), 0, (void (*)(Tile *, InventoryEntry *))(0), 0, 0);
        reinterpret_cast<::InventoryListBox *>(&(m_d8))->PopulateInventoryList((::InventoryOwner *)(m_80), (bool (*)(InventoryEntry *))(void *)((void*)IsFilteredFromBarter), 0, (void (*)(Tile *, InventoryEntry *))(0), 0, 1);
    }
    {
        NodeS* kZero;
        kZero = &m_10c;
        for (; kZero != 0 && *((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)) != 0; kZero = ((::NodeS *)(reinterpret_cast<::Callees *>((kZero))->FUN_00726070())))
        {
            if (arg == 0 || ((void *)(reinterpret_cast<::Twin_0044ddc0 *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->GetName())) == (void*)arg)
            {
                intptr_t tmp;
                NewObj* r =
                    new NewObj(((void *)(reinterpret_cast<::Twin_0044ddc0 *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->GetName())), (int)reinterpret_cast<::Callees *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->FUN_00726070());
                void* _tempExtra;
                _tempExtra = ((::PtrObj *)(::FUN_00559450((int *)((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))))
                                 ? *(void**)((void **)(&reinterpret_cast<::SimpleListNodeView*>(((::PtrObj *)(::FUN_00559450((int *)((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item))))))))->m_item))
                                 : 0;
                tmp = 0;
                if (0 != _tempExtra)
                {
                    ((::PtrObj *)(::FUN_00559450((int *)(r))))->FUN_005ae3d0(&_tempExtra);
                }
                tmp = ((intptr_t)(reinterpret_cast<::list71a::L71Menu *>(&(m_a8))->FUN_0071a320((intptr_t)(r), reinterpret_cast<::FUN_004be2d0_shell *>((r))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                reinterpret_cast<::Tile *>((((TileLike*)tmp)))->Set(DAT_011d8fb4, 1);
            }
        }
    }
    {
        NodeS* kZero;
        kZero = &m_114;
        for (; kZero != 0 && *((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)) != 0; kZero = ((::NodeS *)(reinterpret_cast<::Callees *>((kZero))->FUN_00726070())))
        {
            if (arg == 0 || ((void *)(reinterpret_cast<::Twin_0044ddc0 *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->GetName())) == (void*)arg)
            {
                intptr_t tmp;
                NewObj* r;
                void* _tempExtra;
                r = new NewObj(((void *)(reinterpret_cast<::Twin_0044ddc0 *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->GetName())), (int)reinterpret_cast<::Callees *>(((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))->FUN_00726070());
                _tempExtra = ((::PtrObj *)(::FUN_00559450((int *)((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item)))))))
                                 ? *(void**)((void **)(&reinterpret_cast<::SimpleListNodeView*>(((::PtrObj *)(::FUN_00559450((int *)((*((::EntryObj **)(&reinterpret_cast<::SimpleListNodeView*>(kZero)->m_item))))))))->m_item))
                                 : 0;
                tmp = 0;
                if (_tempExtra != 0)
                {
                    ((::PtrObj *)(::FUN_00559450((int *)(r))))->FUN_005ae3d0(&_tempExtra);
                }
                tmp = ((intptr_t)(reinterpret_cast<::list71a::L71Menu *>(&(m_d8))->FUN_0071a320((intptr_t)(r), reinterpret_cast<::FUN_004be2d0_shell *>((r))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                reinterpret_cast<::Tile *>((((TileLike*)tmp)))->Set(DAT_011d8fb4, 1);
            }
        }
    }
    reinterpret_cast<::LBList_7314c0 *>(&(m_a8))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void *)((void*)FUN_0072eac0), 0, 0x7fffffff);
    reinterpret_cast<::LBList_7314c0 *>(&(m_a8))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void *)((void*)((void (&)())::fnv_0072f210::UpdateBarterItemTile)), 0, 0x7fffffff);
    reinterpret_cast<::ListBoxImpl *>(&(m_a8))->ApplyFilter((bool (*)(void *))(void *)((void*)((int (&)(void *))::FUN_007304b0)));
    m_a8.Virt20((void*)((void (&)())::CompareF070Entries));
    reinterpret_cast<::LBList_7314c0 *>(&(m_d8))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void *)((void*)((void (&)())::fnv_0072f210::UpdateBarterItemTile)), 0, 0x7fffffff);
    reinterpret_cast<::ListBoxImpl *>(&(m_d8))->ApplyFilter((bool (*)(void *))(void *)((void*)((int (&)(void *))::FUN_007304b0)));
    m_d8.Virt20((void*)((void (&)())::CompareF070Entries));
    if (0 == m_108)
    {
        if (((unsigned char)(::FUN_004b71d0())))
        {
            m_108 = &m_d8;
        }
    }
    if (0 != m_108)
    {
        if (reinterpret_cast<::FUN_0071ae60_shell *>((m_108))->FUN_0071ae60() > 0)
        {
            reinterpret_cast<::List7313 *>((m_108))->UpdateCurrentValueTile(1);
        }
        else
        {
            m_a4 = -1;
            Virt0c((m_108 == &m_a8) ? 4 : 9, 0);
            m_a4 = 3;
            if (reinterpret_cast<::FUN_0071ae60_shell *>((m_108))->FUN_0071ae60() > 0)
            {
                reinterpret_cast<::List7313 *>((m_108))->UpdateCurrentValueTile(1);
            }
            else
            {
                Virt10((m_108 == &m_a8) ? 1 : 0, 0);
                if (((unsigned char)(::FUN_004b71d0())))
                {
                    reinterpret_cast<::FocusManager *>((((IMObj*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)(void *)(((void *)(::CallVirtualZero((::fnv_anon_startmenu::Dummy7d6e90 *)(m_108))))), {}, {});
                }
            }
        }
    }
    reinterpret_cast<::fnv_0072db60::FUN_0072db60_cls *>(this)->FUN_0072db60();
}

// @fnv 0x00731360
void List7313::UpdateCurrentValueTile(bool abFlag)
{
    Tile7313* pTile = 0;
    if (m_0c && m_14)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((m_14))->FUN_00a012d0(FUN_00a01860("_current_value"), m_28, false);
        reinterpret_cast<::FUN_00a01290_shell *>((m_14))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
        pTile = GetTile7313((unsigned int)FUN_0040ebd0(m_24, (float)(reinterpret_cast<::FUN_0071ae60_shell *>(this)->FUN_0071ae60() - 1.0)));
        reinterpret_cast<::FocusManager *>((((IM7313*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)(pTile), 0xfc3, abFlag);
        SetSelected7313(pTile);
        if (!((unsigned char)(::FUN_004b71d0())))
        {
            if (pTile)
                ((::Menu7313 *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::Holder7313 *)(reinterpret_cast<::FUN_00a03d40_shell *>((m_0c))->FUN_00a03d40()))))->FUN_00a03c90()))->SetValue7313((int)reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfaa), pTile);
            SetSelected7313(0);
        }
    }
}

struct MerchantServices
{
};
struct MerchantBase
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
    int unk88;
    int unk8C;
    MerchantServices services;
};
struct MerchantActor : OwnActor
{
};
int __cdecl FUN_00479430(TESBoundObject*);

// Checks if an inventory entry should be hidden from the barter menu based on merchant service flags and form validity.
// @fnv 0x0072e6c0
bool __cdecl IsFilteredFromBarter(EntryObj* apEntry)
{
    MerchantActor* merchant4;
    bool filteredVal = false;
    TESBoundObject* formTmp;
    TESFullName* name;
    TESObjectWEAP* weapon_;
    TESBipedModelForm* bipedVal;
    TESObjectARMO* armor;
    merchant4 =
        (((OwnBarterMenu*)DAT_011d8fa4)->m_pkMerchant && ((OwnBarterMenu*)DAT_011d8fa4)->m_pkMerchant->IsActor())
            ? (MerchantActor*)((OwnBarterMenu*)DAT_011d8fa4)->m_pkMerchant
            : 0;
    formTmp = apEntry ? ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName())) : 0;
    if (merchant4)
    {
        switch (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName()))->FUN_00401170())
        {
        case 40:
        case 41:
            filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(1) == false;
            break;
        case 24:
            filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(2) == false;
            break;
        case 31:
        case 50:
        case 103:
            filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(0x400) == false;
            break;
        case 46:
            filteredVal = true;
            break;
        case 49:
            filteredVal = (formTmp && ::FUN_0048e8a0((::TESForm *)(formTmp)) > 0)
                              ? (reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(0x400) == false)
                              : true;
            break;
        case 25:
            filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(8) == false;
            break;
        case 47:
            switch (FUN_00479430(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName()))))
            {
            case 10:
                filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(0x20) == false;
                break;
            case 11:
                filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(0x40) == false;
                break;
            case 12:
                filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(0x10) == false;
                break;
            case 13:
                filteredVal = reinterpret_cast<::FUN_0047efe0_shell *>(&(((::MerchantBase *)(reinterpret_cast<::Actor *>((merchant4))->GetActorBase()))->services))->HasFlags(4) == false;
                break;
            }
            break;
        }
    }
    bipedVal = ::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(formTmp));
    name = dynamic_cast<TESFullName*>(formTmp);
    armor = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName()))->FUN_00401170() == 40
                ? (TESObjectARMO*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName()))
                : 0;
    weapon_ = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName()))->FUN_00401170() == 41
                  ? (TESObjectWEAP*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryEntry*)apEntry)))->GetName()))
                  : 0;
    if (!formTmp || (bipedVal && !reinterpret_cast<::FUN_00480d90_shell *>((bipedVal))->FUN_00480d90()) || ::FUN_00481f10((::TESObject *)(formTmp)) || !name ||
        !name->GetModelLength() || (armor && !reinterpret_cast<::FUN_0047bcf0_class *>((armor))->IsFlag80Clear()) || (weapon_ && !((bool)(reinterpret_cast<::FUN_004c94d0_shell *>((weapon_))->GetFlag()))))
    {
        filteredVal = true;
    }
    return filteredVal;
}

struct Fr7304Form
{
    int FUN_00401170();
};
struct Fr7304Entry
{
};
struct Fr7304Tile
{
};
struct Fr7304List
{
};
struct Fr7304Menu
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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    Fr7304List kListA8;
    char cA9;
    char cAA;
    char cAB;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    Fr7304List kListD8;
};

// Evaluates the item type against a filter and, when a tile exists, combines the result with a comparison to _num_bartered.
// @fnv 0x007304b0
bool __cdecl FUN_007304b0(Fr7304Entry* pkItem)
{
    bool bResult = false;
    int iType = ((::Fr7304Form *)(reinterpret_cast<::Twin_0044ddc0 *>((pkItem))->GetName()))->FUN_00401170();
    Fr7304Tile* pkTile = ((::Fr7304Tile *)(reinterpret_cast<::Owner *>(&(((Fr7304Menu*)DAT_011d8fa4)->kListA8))->FindItemData((int *)(::Fr7304Entry **)(&pkItem))));
    int iFilter_2 = 0;
    if (pkTile)
    {
        iFilter_2 = ((Fr7304Menu*)DAT_011d8fa4)->unk9C;
    }
    else
    {
        pkTile = ((::Fr7304Tile *)(reinterpret_cast<::Owner *>(&(((Fr7304Menu*)DAT_011d8fa4)->kListD8))->FindItemData((int *)(::Fr7304Entry **)(&pkItem))));
        iFilter_2 = ((Fr7304Menu*)DAT_011d8fa4)->unkA0;
    }
    switch (iFilter_2)
    {
        break;
    case 1:
        bResult = iType != 0x28;
        break;
    case 2:
        bResult = iType != 0x18 && iType != 0x1a;
        break;
    case 3:
        bResult = iType != 0x1d && iType != 0x2f && iType != 0x19;
        break;
    case 4:
        bResult = iType == 0x28 || iType == 0x18 || iType == 0x1a || iType == 0x1d || iType == 0x2f || iType == 0x29 ||
                  iType == 0x19 || iType == 0x6c || iType == 0x73 || iType == 0x74;
        break;
    case 5:
        bResult = iType != 0x29;
        break;
    }
    if (pkTile)
    {
        bResult =
            bResult || (double)((std::intptr_t)(reinterpret_cast<::Callees *>((pkItem))->FUN_00726070())) - reinterpret_cast<::TileListBoxCalls *>((pkTile))->GetFloat(FUN_00a01860(s_szNumBartered)) <= 0.0;
    }
    return bResult;
}

#include "generated/data/fallout/interface/menus/bartermenu.inc"
