
// src/fallout/interface/menus/companionwheelmenu_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Tile). The skeleton of src/fallout/interface/menus/companionwheelmenu.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSAudio.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/CompanionWheelInventory.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_007563a0_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0083c850.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_0088b740_shell.h"
#include "fnv/decl/FUN_00893590_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008c16c0_cls.h"
#include "fnv/decl/FUN_008c1f80_shell.h"
#include "fnv/decl/FUN_00933150_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Player.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/ProcessListsSub.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S0042fa20.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WheelSelection.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_0057ace0__FUN_0057ace0_shell.h"
#include "fnv/decl/fnv_0057ad20__FUN_0057ad20_shell.h"
#include "fnv/decl/fnv_0057b7c0__Actor57.h"
#include "fnv/decl/fnv_0061a720__FUN_0061a720_shell.h"
#include "fnv/decl/fnv_007562b0__FUN_007562b0_shell.h"
#include "fnv/decl/fnv_007575b0__FUN_007575b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008a7a90__ActorAnimView.h"
#include "fnv/decl/fnv_008a8e50__ActorP_S.h"
#include "fnv/decl/fnv_008b3c30__FUN_008b3c30_shell.h"
#include "fnv/decl/fnv_008bb520__TES.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00564000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_00755000.h"
#include "fnv/symbols_008c1000.h"
#include "fnv/symbols_008d5000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00ad8000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "companionwheelmenu_decls.h"
struct FUN_00754bf0_shell
{
    int __thiscall GetClass();
};
struct FUN_00884480_shell
{
    bool __thiscall FUN_00884480(void);
};
struct Actor
{
public:
    bool IsSneaking();
public:
    void ConfigureActorState(bool, bool);
};
int __cdecl FUN_00755260();
float FUN_00755660(float value);
void __fastcall FUN_00756960(int thisPtr);
struct FUN_00755680_shell
{
    bool __thiscall FUN_00755680();
};
struct MyStandin754c30
{
    void __thiscall FUN_00754c60();
    void* __thiscall FUN_00754c30(unsigned int);
};
struct Tile
{
    virtual ~Tile();  // the original class is polymorphic (rtti_variants.py)
public:
    void Set(int, int);
};
struct Unk00755d90
{
    char _pad[0x4C];
    Tile* _tile;
    void __thiscall SetTileText(char const*);
};
struct FUN_008a7760_holder
{
};
struct FUN_00756930_shell
{
    char _pad[0x68];
    Actor* m_pDialogueActor;
    void __thiscall FUN_00756930();
};
struct TESForm
{
    virtual void v0();
public:
    void NotifySaveLoadGameOfFormChange();
};
struct TESTopic
{
    virtual void v0();
};
struct Tile2
{
};
struct FUN_007560c0_shell
{
    void __thiscall ToggleFollowersTacticsDistance();
};
struct MagicCaster
{
public:
    void RemoveCastingArt();
};
struct Date
{
    virtual ~Date();
};
struct Menu_007a8b10
{
    char _pad[0x70];
    virtual ~Menu_007a8b10();
};
struct FUN_00754c60 : Menu_007a8b10
{
    bool _flag;
    char _pad[7];
    Date _date;


    ~FUN_00754c60();
};
struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};
struct FUN_007552e0_shell
{
    void __thiscall FUN_007552e0(int, Tile*);

    unsigned char _pad[0x28];
    Tile* m_pTiles[64];
};
float __cdecl FUN_00755660(float value);
int __cdecl _FUN_00ec7d40(int value);
extern char $SG3295[];
extern double DAT_01071e20;
extern float DAT_01071e28;
extern float DAT_01071e2c;
struct FUN_00755480_shell
{
    char _pad[0x58];
    Tile* pTile;
    char _pad2[0x1C];
    unsigned int m_uiCurrentItemIndex;

    void __thiscall UpdateTileTimerAndInputAngle();
};
struct MenuFactory
{
};
extern "C" bool __cdecl FUN_00702450(int);
struct Foo
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf(int, Tile*);
    char _pad[0x24];
    Tile* m_pTiles[18];
    int idx;
    bool HandleTileAction(int arg, int unused);
};
struct WheelHost
{
    char unk00[0x28];
    int m_aiIndexedValues[16];
    void __thiscall FUN_00755760(int a, int b);
};
bool __cdecl FUN_00702450(int);
struct InteractionActor;
struct PackageNode
{
};
struct TESPackage
{
    virtual ~TESPackage();
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
public:
    bool IsPackageBlockingGreeting();
};
struct DialoguePackage : TESPackage
{
    unsigned int topic;
};
struct ActorLevelInfo
{
    unsigned int unk00, unk04, unk08;
    unsigned short unk0c;
    unsigned char level;
};
struct DialoguePolicy
{
};
class DialogueResponse;
class TESObjectREFR;
struct DialogueItem
{
    ~DialogueItem();
    static void operator delete(void*);
public:
    ::TESObjectREFR *SelectDefaultResponseList();
public:
    bool SelectDefaultResponseList();
public:
    ::DialogueResponse *GetActiveResponse();
};
struct DialogueManager
{
};
struct ActorPosition
{
    float x, y, z;
};
struct ActorExtraData
{
};
struct ActorLock
{
};
struct InteractionActor
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
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
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
    virtual ActorPosition* GetPosition(int);
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int GetState();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsUnavailable(int);
    virtual bool CanInteract();
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
    virtual TESPackage* GetAssignedPackage();
    virtual void slot160();
    virtual void slot161();
    virtual void SetPackage(InteractionActor*, int);
    virtual void slot163();
    virtual void slot164();
    virtual void Prepare(InteractionActor*);
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
    virtual InteractionActor* GetRelated();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual bool IsDead();
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
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual bool AllowTarget(InteractionActor*);
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void ResetDialogue();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual ActorLock* GetLock();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual void slot306();
    virtual void slot307();
    virtual void slot308();
    virtual ActorLevelInfo* GetLevelInfo();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual void slot321();
    virtual void slot322();
    virtual void slot323();
    virtual void slot324();
    virtual void slot325();
    virtual void slot326();
    virtual void slot327();
    virtual void slot328();
    virtual void slot329();
    virtual void slot330();
    virtual int IsRestricted();
    virtual void slot332();
    virtual void slot333();
    virtual void slot334();
    virtual void slot335();
    virtual void slot336();
    virtual void slot337();
    virtual void slot338();
    virtual void slot339();
    virtual void slot340();
    virtual void slot341();
    virtual void slot342();
    virtual void slot343();
    virtual void slot344();
    virtual void slot345();
    virtual void slot346();
    virtual void slot347();
    virtual void slot348();
    virtual void slot349();
    virtual void slot350();
    virtual void slot351();
    virtual void slot352();
    virtual void slot353();
    virtual void slot354();
    virtual void slot355();
    virtual void slot356();
    virtual void slot357();
    virtual void slot358();
    virtual void slot359();
    virtual void slot360();
    virtual void slot361();
    virtual void slot362();
    virtual void slot363();
    virtual void slot364();
    virtual void slot365();
    virtual void slot366();
    virtual void slot367();
    virtual void slot368();
    virtual void slot369();
    virtual void slot370();
    virtual void slot371();
    virtual void slot372();
    virtual void slot373();
    virtual void slot374();
    virtual void slot375();
    virtual void slot376();
    virtual void slot377();
    virtual void slot378();
    virtual void slot379();
    virtual void slot380();
    virtual void slot381();
    virtual void slot382();
    virtual void slot383();
    virtual void SetDialogue(bool);
    virtual bool CanDialogue();
    virtual void slot386();
    virtual void slot387();
    virtual int IsBusy();
    virtual void SetFlags(int);
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
    ActorExtraData extras;
};
struct DialogueDisplay
{
};
struct InputState
{
};
struct MessageSetting
{
};
int sprintf(char*, const char*, ...);
struct InteractionMenu
{
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
    InteractionActor* companion;
    void UpdateCompanionInteraction();
};
struct BSStringT
{
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    BSStringT(const BSStringT& src);
    ~BSStringT();
    const char* CStr();
};
struct SoundPlaybackHandle
{
    unsigned int soundID;
    bool assumeSuccess;
    unsigned int state;
    SoundPlaybackHandle(const SoundPlaybackHandle& src);
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& src);
    ~SoundPlaybackHandle();
public:
    bool StopWithFade(unsigned int);
public:
    void SetCompletionCallback(void (*)(void *, bool), void *);
};
struct TESQuest;
struct TESTopicInfo;
struct TESObjectREFR;
struct TESTopic;
struct SoundFile
{
};
struct SoundPath
{
    const char* CStr();
};
struct DialogueResponse
{
};
struct CompActor
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
    virtual float Speak(const char* voicePath, unsigned int flags, unsigned int soundID, unsigned int textLen,
                        int emotionType, int emotionValue, CompActor* target, bool a8, bool a9, bool a10, bool a11,
                        bool a12);

};
struct TopicInfoStandin
{
};
struct TopicInfoQ
{
};
struct DialogueItemStandin
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    DialogueItemStandin(TESQuest* quest, TopicInfoStandin* topic, TopicInfoQ* info, CompActor* speaker);
    ~DialogueItemStandin();
};
struct CompanionWheelStandin
{
    char unk00;
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
    CompActor* companion;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    SoundPlaybackHandle sound;

    void PlayTopicResponse(TopicInfoStandin* topic);
};
struct CStringArg_757690
{
    unsigned data;
    unsigned length;
    ~CStringArg_757690();
};
struct CValueArg_757690
{
    unsigned value;
    unsigned kind;
    unsigned other;
    ~CValueArg_757690();
};
struct CWheelItem_757690
{
};
struct CRelatedActor_757690
{
};
struct CInterface_757690
{
    unsigned char* __thiscall FUN_00408d60();
};
struct CRandom_757690
{
};
unsigned __cdecl FUN_00ec6130(int);
struct CWheelMenu_757690
{
    void __thiscall SetItemTextAndValue(CStringArg_757690 text, CValueArg_757690 value);
};
namespace ScriptAnimation {
struct Reference;
struct Actor;
struct Idle;
struct Process;
struct Sequence;
struct ResultList
{
    int head, tail, count;
    ~ResultList();
};
struct Sequence
{
    ~Sequence();
};
struct Idle
{
};
struct Reference
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~Reference();
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
    virtual bool IsSpecial();
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
    virtual ResultList Play(Idle*, Reference*, bool, bool, int, int, bool);
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
    virtual void* GetNode();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* GetParent();
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
    virtual bool IsDead(int);
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
    virtual ResultList PlayActor(Idle*, Actor*, bool, bool, int, int);
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
    virtual void Clear(int);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void Reset();
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
    virtual void Update();
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
    virtual void Play(Actor*, Idle*, bool, int, int, int);
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
    virtual void SetAlert(int);
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
    virtual void RestoreState(int);
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void SetState(int);
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
    virtual int GetState(int);
};
struct Actor : Reference
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
    float animationTime;
    int FUN_00931850();
};
struct Setting
{
};
Actor* FUN_00ec43fb(Reference*, int, const void*, const void*, int);
// @fnv 0x005c8a50
bool FUN_005c8a50(void* paramInfo, void* scriptData, Reference* source, void* containing, void* script, void* locals,
                  double* result, void* offset)
{
    *result = 0.0;
    Idle* idleVal = 0;
    int force = 0;
    void* object4 = 0;
    int immediateA = 0;
    int _usePriority = 0;
    if (!::FUN_005accb0((const ::ExtractParameter *)(paramInfo), (const char *)(scriptData), (unsigned int *)(offset), (::TESObjectREFR *)(source), (::TESObjectREFR *)(containing), (::ExtractScript *)(script), (::ScriptLocals *)(locals), &idleVal, &force, &object4,
                      &immediateA, &_usePriority))
        return false;
    bool forceFlag4 = false;
    bool immediateFlag4 = false;
    bool priorityFlag = false;
    if (immediateA)
        immediateFlag4 = true;
    if (force > 0)
        forceFlag4 = true;
    if (_usePriority > 0)
        priorityFlag = true;
    Actor* actor = FUN_00ec43fb(source, 0, &::DAT_011841cc, &::DAT_011846d4, 0);
    int previous = *((const int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ScriptAnimation::Setting *>(&::g_011cd378))))));
    reinterpret_cast<::S0042fa20 *>(&((*reinterpret_cast<::ScriptAnimation::Setting *>(&::g_011cd378))))->FUN_0045ce80(0x7fffffff);
    if (idleVal)
    {
        if (actor)
        {
            if (((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && !actor->IsDead(1))
            {
                actor->animationTime = ::DAT_01012054;
                ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->SetAlert(0);
                ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Reset();
                if (!actor->FUN_00931850())
                {
                    int state = ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetState(2);
                    ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->SetState(0);
                    ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->RestoreState(state);
                    ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Update();
                }
                else if (immediateA)
                {
                    reinterpret_cast<::fnv_0057ad20::FUN_0057ad20_shell *>((actor))->FUN_0057ad20((::fnv_0057ad20::TESTopic *)(idleVal));
                    Sequence* chosen = ((::ScriptAnimation::Sequence *)(reinterpret_cast<::FUN_0061b320_shell *>((idleVal))->FUN_0061b320((::TESObjectREFR *)(actor), (::TESObjectREFR *)(0), (::TESTopic *)(0), (void *)(0), 0)));
                    if (chosen)
                        reinterpret_cast<::fnv_0057ace0::FUN_0057ace0_shell *>((source))->FUN_0057ace0((::fnv_0057ace0::TESTopicInfo *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((chosen))->FUN_0084e3a0()))));
                    ResultList events = actor->PlayActor(idleVal, actor, immediateFlag4, priorityFlag, 0, 0);
                    reinterpret_cast<::SoundPlaybackHandle *>(&(events))->SetCompletionCallback((void (*)(void *, bool))(::fnv_005790f0::FUN_005790f0), (void *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
                    return true;
                }
                if (reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::ScriptAnimation::Actor * *>(&::_g_thePlayer))))->IsSleepingOrResting() || ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))))->FUN_0045cd60())) != 0 ||
                    (reinterpret_cast<::FUN_0087f3d0_shell *>((actor))->FUN_0087f3d0() && reinterpret_cast<::FUN_004f8960_shell *>((actor))->FUN_004f8960() == 6))
                {
                    Sequence* selected = ((::ScriptAnimation::Sequence *)(reinterpret_cast<::FUN_0061b320_shell *>((idleVal))->FUN_0061b320((::TESObjectREFR *)(actor), (::TESObjectREFR *)(0), (::TESTopic *)(0), (void *)(0), 1)));
                    if (selected)
                    {
                        reinterpret_cast<::DialogueItem *>((selected))->SelectDefaultResponseList();
                        int unused = ((int)(reinterpret_cast<::DialogueItem *>((selected))->GetActiveResponse()));
                        reinterpret_cast<::FUN_0083c850 *>((selected))->AppendTopicInfo(0);
                        reinterpret_cast<::FUN_0083c850 *>((selected))->AppendTopicInfo(1);
                        ::FUN_005ac750((::TESForm *)(idleVal), (::ExtraDataList *)(((unsigned int)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))), 0x40000);
                        delete selected;
                    }
                }
                else
                    ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Play(actor, idleVal, forceFlag4, 0, 1, 1);
            }
            else if (((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
            {
                ::FUN_005ac750((::TESForm *)(idleVal), (::ExtraDataList *)(((unsigned int)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))), 0x40000);
                ((::ScriptAnimation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Clear(0);
            }
        }
        else if (source && object4)
        {
            Reference* created = ((::ScriptAnimation::Reference *)(::FUN_00564480(59, 0)));
            reinterpret_cast<::TESForm *>((created))->NotifySaveLoadGameOfFormChange();
            reinterpret_cast<::Fn575690 *>((created))->FUN_00575690(object4);
            reinterpret_cast<::Reference *>((created))->FUN_00575830((::Position *)(void *)(source->GetParent()));
            reinterpret_cast<::fnv_0057ad20::FUN_0057ad20_shell *>((source))->FUN_0057ad20((::fnv_0057ad20::TESTopic *)(idleVal));
            Sequence* chosen2 = ((::ScriptAnimation::Sequence *)(reinterpret_cast<::FUN_0061b320_shell *>((idleVal))->FUN_0061b320((::TESObjectREFR *)(created), (::TESObjectREFR *)(0), (::TESTopic *)(0), (void *)(0), 0)));
            if (chosen2)
                reinterpret_cast<::fnv_0057ace0::FUN_0057ace0_shell *>((source))->FUN_0057ace0((::fnv_0057ace0::TESTopicInfo *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((chosen2))->FUN_0084e3a0()))));
            ResultList events7 = created->Play(idleVal, created, immediateFlag4, priorityFlag, 0, 0, forceFlag4);
            reinterpret_cast<::SoundPlaybackHandle *>(&(events7))->SetCompletionCallback((void (*)(void *, bool))(::fnv_005790f0::FUN_005790f0), (void *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
            delete created;
        }
        else if (source->GetNode() || (source->IsSpecial() && ((::ScriptAnimation::Reference *)(reinterpret_cast<::DialogueItem *>((source))->SelectDefaultResponseList()))->GetNode()))
        {
            reinterpret_cast<::fnv_0057ad20::FUN_0057ad20_shell *>((source))->FUN_0057ad20((::fnv_0057ad20::TESTopic *)(idleVal));
            Sequence* chosen3 = ((::ScriptAnimation::Sequence *)(reinterpret_cast<::FUN_0061b320_shell *>((idleVal))->FUN_0061b320((::TESObjectREFR *)(source), (::TESObjectREFR *)(0), (::TESTopic *)(0), (void *)(0), 0)));
            if (chosen3)
                reinterpret_cast<::fnv_0057ace0::FUN_0057ace0_shell *>((source))->FUN_0057ace0((::fnv_0057ace0::TESTopicInfo *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((chosen3))->FUN_0084e3a0()))));
            ResultList events3 = source->Play(idleVal, 0, immediateFlag4, priorityFlag, 0, 0, forceFlag4);
            reinterpret_cast<::SoundPlaybackHandle *>(&(events3))->SetCompletionCallback((void (*)(void *, bool))(::fnv_005790f0::FUN_005790f0), (void *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
        }
    }
    reinterpret_cast<::S0042fa20 *>(&((*reinterpret_cast<::ScriptAnimation::Setting *>(&::g_011cd378))))->FUN_0045ce80(previous);
    return true;
}
}

class Tile755
{
  public:
};
class Fader755
{
  public:
};
class Menu755
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
    Fader755 m_kFader;
};
class SaveLoad755
{
  public:
};
class Manager755
{
  public:
};
struct Tile_Set_Helper
{
};
struct ScriptTile256
{
};
struct MenuGlobal256
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
    ScriptTile256* script;
};
struct Wheel256
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
    Tile_Set_Helper* tile;
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
    unsigned char unk6c;
    bool aggressive;
    void ToggleAggressive();
};
class TESBoundObject : public TESForm
{
};
class AlchemyItem : public TESBoundObject
{
};
struct HealingExtra
{
    int unk00;
};
struct HealingExtraList
{
};
struct HealingInventoryEntry
{
    void* FUN_004459e0(unsigned int);
};
struct HealingActorBase
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
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void RemoveItem(void*, HealingExtra*, int, int, int, int, int, int, int, int);
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
};
struct HealingActorValues
{
    int unk00;
};
struct HealingActor : HealingActorBase, HealingActorValues
{
};
extern char DAT_01183108, DAT_01183028, DAT_011830cc;
void* FUN_00ec43fb(void*, int, void*, void*, int);
struct CompanionHealingMenu
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
    HealingActor* companion;
    void HealCompanion();
};

class RadialTile : public Tile
{
  public:
};
struct WheelMenuV
{
    virtual ~WheelMenuV();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    Tile* tiles[16];
    void __thiscall FUN_00755c50(float angle);
};

// @fnv 0x00755c50
void WheelMenuV::FUN_00755c50(float angle)
{
    if (angle >= 0.0 && angle < 0.5235980153083801)
        angle = 0.55f;
    else if (angle >= 2.617990016937256 && angle < 3.141590118408203)
        angle = 2.6f;
    else if (angle >= 3.14159 && angle < 3.665186)
        angle = 3.7f;
    else if (angle >= 5.759578)
        angle = 5.7f;

    int k;
    RadialTile* radialTile;
    float a;
    float high;
    for (k = 0; k < 16; k++)
    {
        radialTile = dynamic_cast<RadialTile*>(tiles[k]);
        if (radialTile)
        {
            a = reinterpret_cast<::TileListBoxCalls *>((radialTile))->GetFloat(0x1006);
            high = reinterpret_cast<::TileListBoxCalls *>((radialTile))->GetFloat(0x1007);
            if (angle >= a && angle < high)
            {
                reinterpret_cast<::WheelSelection *>(this)->SelectTile(k, false);
                break;
            }
        }
    }
}
