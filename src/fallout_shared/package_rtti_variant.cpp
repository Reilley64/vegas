
// src/fallout_shared/package_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESPackage). The skeleton of src/fallout_shared/package.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00671a20_shell.h"
#include "fnv/decl/FUN_00672fc0_shell.h"
#include "fnv/decl/FUN_00674d70_shell.h"
#include "fnv/decl/FUN_0067a3f0_shell.h"
#include "fnv/decl/FUN_0067a460_shell.h"
#include "fnv/decl/FUN_0067a640_shell.h"
#include "fnv/decl/FUN_00833c20_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008a08c0_Class.h"
#include "fnv/decl/FUN_008bf4e0_cls.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009ec830_t.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/TESClass.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/ZOwner.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_0067fd40__FUN_0067fd40_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_00884350__FUN_00884350_shell.h"
#include "fnv/decl/fnv_009eb9c0__Crime.h"
#include "fnv/decl/fnv_009ec810__FUN_009ec810_t.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "package_decls_rtti_variant.h"

struct A;
struct P;
struct Proc;
struct Target;
struct Loc;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct P : TESPackage
{
};
struct TESObjectREFR;
class FleePackage : public P
{
  public:
public:
    void FUN_009f1310(::TESObjectREFR *);
};
struct Created : P
{
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
    Created(A*);
};
struct Loc
{
    int unk00, unk04, unk08;
    Loc();
    ~Loc();
};
struct Target
{
    int unk00, unk04, unk08, unk0c;
    Target();
    ~Target();
};
struct Cls
{
};
struct List
{
    int GetSize();
};
struct Lists
{
};
struct SettingLocal
{
};
struct Proc
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void Reset();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual A* GetTarget();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void Prepare();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual P* GetAssignedPackage();
    virtual void unused140();
    virtual void unused141();
    virtual void unused142();
    virtual void unused143();
    virtual void unused144();
    virtual void unused145();
    virtual void unused146();
    virtual void unused147();
    virtual void unused148();
    virtual void unused149();
    virtual void unused150();
    virtual void unused151();
    virtual void unused152();
    virtual void unused153();
    virtual void unused154();
    virtual void unused155();
    virtual void unused156();
    virtual void unused157();
    virtual void unused158();
    virtual void unused159();
    virtual void unused160();
    virtual void SetValue(int);
    virtual void unused162();
    virtual void unused163();
    virtual void unused164();
    virtual void unused165();
    virtual void unused166();
    virtual void unused167();
    virtual void unused168();
    virtual void unused169();
    virtual void unused170();
    virtual void unused171();
    virtual void unused172();
    virtual void unused173();
    virtual void unused174();
    virtual void unused175();
    virtual void unused176();
    virtual void unused177();
    virtual void unused178();
    virtual void unused179();
    virtual void unused180();
    virtual void unused181();
    virtual void unused182();
    virtual void unused183();
    virtual void unused184();
    virtual void unused185();
    virtual void unused186();
    virtual void unused187();
    virtual void unused188();
    virtual void unused189();
    virtual void unused190();
    virtual void unused191();
    virtual void unused192();
    virtual void unused193();
    virtual void unused194();
    virtual void unused195();
    virtual void unused196();
    virtual void unused197();
    virtual void unused198();
    virtual void unused199();
    virtual void unused200();
    virtual void unused201();
    virtual void unused202();
    virtual void unused203();
    virtual void unused204();
    virtual void unused205();
    virtual void unused206();
    virtual void Respond(A*, A*, int, int, int, int, int, int, int, int, int, int, int);
    virtual void unused208();
    virtual void React(A*, A*, A*);
    virtual void SetCount(int);
    virtual void unused211();
    virtual void unused212();
    virtual void unused213();
    virtual void unused214();
    virtual void unused215();
    virtual void unused216();
    virtual void unused217();
    virtual void unused218();
    virtual void unused219();
    virtual void unused220();
    virtual void unused221();
    virtual void unused222();
    virtual void unused223();
    virtual void unused224();
    virtual void unused225();
    virtual void unused226();
    virtual void unused227();
    virtual void unused228();
    virtual void unused229();
    virtual void unused230();
    virtual void unused231();
    virtual void unused232();
    virtual void unused233();
    virtual void unused234();
    virtual void unused235();
    virtual void unused236();
    virtual void unused237();
    virtual void unused238();
    virtual void unused239();
    virtual void unused240();
    virtual void unused241();
    virtual void unused242();
    virtual void unused243();
    virtual void unused244();
    virtual void unused245();
    virtual void unused246();
    virtual void unused247();
    virtual void unused248();
    virtual void unused249();
    virtual void unused250();
    virtual void unused251();
    virtual void unused252();
    virtual void unused253();
    virtual void unused254();
    virtual void unused255();
    virtual void unused256();
    virtual void unused257();
    virtual void unused258();
    virtual void unused259();
    virtual void unused260();
    virtual void unused261();
    virtual void unused262();
    virtual void unused263();
    virtual void unused264();
    virtual void unused265();
    virtual void unused266();
    virtual void unused267();
    virtual void unused268();
    virtual void unused269();
    virtual void unused270();
    virtual void unused271();
    virtual void unused272();
    virtual void unused273();
    virtual void unused274();
    virtual void unused275();
    virtual void unused276();
    virtual void unused277();
    virtual void unused278();
    virtual void unused279();
    virtual void unused280();
    virtual void unused281();
    virtual void unused282();
    virtual void unused283();
    virtual void unused284();
    virtual void unused285();
    virtual void unused286();
    virtual void unused287();
    virtual void unused288();
    virtual void unused289();
    virtual void unused290();
    virtual void unused291();
    virtual void unused292();
    virtual void unused293();
    virtual void unused294();
    virtual void unused295();
    virtual void unused296();
    virtual void unused297();
    virtual void unused298();
    virtual void unused299();
    virtual void unused300();
    virtual void unused301();
    virtual void unused302();
    virtual void unused303();
    virtual void unused304();
    virtual void unused305();
    virtual void unused306();
    virtual void unused307();
    virtual void unused308();
    virtual void unused309();
    virtual void unused310();
    virtual void unused311();
    virtual void unused312();
    virtual void unused313();
    virtual void unused314();
    virtual void unused315();
    virtual void unused316();
    virtual void unused317();
    virtual void unused318();
    virtual void unused319();
    virtual void unused320();
    virtual void unused321();
    virtual void unused322();
    virtual void unused323();
    virtual void unused324();
    virtual void unused325();
    virtual void unused326();
    virtual void unused327();
    virtual void unused328();
    virtual void unused329();
    virtual void unused330();
    virtual void unused331();
    virtual void unused332();
    virtual void unused333();
    virtual void unused334();
    virtual void unused335();
    virtual void unused336();
    virtual void unused337();
    virtual void unused338();
    virtual void unused339();
    virtual void unused340();
    virtual void unused341();
    virtual void unused342();
    virtual void unused343();
    virtual void unused344();
    virtual void unused345();
    virtual void unused346();
    virtual void unused347();
    virtual void unused348();
    virtual void unused349();
    virtual void unused350();
    virtual void unused351();
    virtual void unused352();
    virtual void unused353();
    virtual void unused354();
    virtual void unused355();
    virtual void unused356();
    virtual void unused357();
    virtual void unused358();
    virtual void unused359();
    virtual void unused360();
    virtual void unused361();
    virtual void unused362();
    virtual void unused363();
    virtual void unused364();
    virtual void unused365();
    virtual void unused366();
    virtual void unused367();
    virtual int GetCount();
    virtual void SetFlag(int);
    virtual void unused370();
    virtual void unused371();
    virtual void unused372();
    virtual void unused373();
    virtual void unused374();
    virtual void unused375();
    virtual void unused376();
    virtual void unused377();
    virtual void unused378();
    virtual void unused379();
    virtual void unused380();
    virtual void unused381();
    virtual void unused382();
    virtual void unused383();
    virtual void unused384();
    virtual void unused385();
    virtual void unused386();
    virtual void unused387();
    virtual void unused388();
    virtual void unused389();
    virtual void unused390();
    virtual void unused391();
    virtual void unused392();
    virtual void unused393();
    virtual void unused394();
    virtual void unused395();
    virtual void unused396();
    virtual void unused397();
    virtual void unused398();
    virtual void unused399();
    virtual void unused400();
    virtual void unused401();
    virtual void unused402();
    virtual void unused403();
    virtual void unused404();
    virtual void unused405();
    virtual void unused406();
    virtual void unused407();
    virtual void unused408();
    virtual void unused409();
    virtual void unused410();
    virtual void unused411();
    virtual void unused412();
    virtual void unused413();
    virtual void unused414();
    virtual void unused415();
    virtual void unused416();
    virtual void unused417();
    virtual void unused418();
    virtual void unused419();
    virtual void unused420();
    virtual void unused421();
    virtual void unused422();
    virtual void unused423();
    virtual void unused424();
    virtual void unused425();
    virtual void unused426();
    virtual void unused427();
    virtual void unused428();
    virtual void unused429();
    virtual void unused430();
    virtual void unused431();
    virtual void unused432();
    virtual void unused433();
    virtual void unused434();
    virtual void unused435();
    virtual void unused436();
    virtual void unused437();
    virtual void unused438();
    virtual void unused439();
    virtual void unused440();
    virtual void unused441();
    virtual void unused442();
    virtual void unused443();
    virtual void unused444();
    virtual void unused445();
    virtual void unused446();
    virtual void unused447();
    virtual void unused448();
    virtual void unused449();
    virtual void unused450();
    virtual void unused451();
    virtual void Notify(A*);
};
struct A
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual int GetType();
    virtual bool IsActor();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual bool IsState(int);
    virtual void unused140();
    virtual void unused141();
    virtual void unused142();
    virtual void unused143();
    virtual void unused144();
    virtual void unused145();
    virtual void unused146();
    virtual void unused147();
    virtual void unused148();
    virtual void unused149();
    virtual void unused150();
    virtual void unused151();
    virtual void unused152();
    virtual void unused153();
    virtual void unused154();
    virtual void unused155();
    virtual void unused156();
    virtual void unused157();
    virtual void unused158();
    virtual void unused159();
    virtual void unused160();
    virtual void unused161();
    virtual void unused162();
    virtual void unused163();
    virtual void unused164();
    virtual void unused165();
    virtual void unused166();
    virtual void unused167();
    virtual void unused168();
    virtual void unused169();
    virtual void unused170();
    virtual void unused171();
    virtual void unused172();
    virtual void unused173();
    virtual void unused174();
    virtual void unused175();
    virtual void unused176();
    virtual void unused177();
    virtual void unused178();
    virtual void unused179();
    virtual void unused180();
    virtual void unused181();
    virtual void unused182();
    virtual void unused183();
    virtual void unused184();
    virtual void unused185();
    virtual void unused186();
    virtual void unused187();
    virtual void unused188();
    virtual void SetPackage(P*, int, int);
    virtual void unused190();
    virtual void unused191();
    virtual void unused192();
    virtual bool IsSpecial();
    virtual void unused194();
    virtual void unused195();
    virtual void unused196();
    virtual void unused197();
    virtual void unused198();
    virtual void unused199();
    virtual void unused200();
    virtual void unused201();
    virtual void unused202();
    virtual void unused203();
    virtual void unused204();
    virtual void unused205();
    virtual void unused206();
    virtual void unused207();
    virtual void unused208();
    virtual void unused209();
    virtual void unused210();
    virtual void unused211();
    virtual void unused212();
    virtual void unused213();
    virtual void unused214();
    virtual void unused215();
    virtual void unused216();
    virtual void unused217();
    virtual void unused218();
    virtual void unused219();
    virtual void unused220();
    virtual void unused221();
    virtual void unused222();
    virtual void unused223();
    virtual void unused224();
    virtual void unused225();
    virtual void unused226();
    virtual void unused227();
    virtual void unused228();
    virtual void unused229();
    virtual void unused230();
    virtual void unused231();
    virtual void unused232();
    virtual void unused233();
    virtual void unused234();
    virtual void unused235();
    virtual void unused236();
    virtual void unused237();
    virtual void unused238();
    virtual void unused239();
    virtual void unused240();
    virtual void unused241();
    virtual void unused242();
    virtual void unused243();
    virtual void unused244();
    virtual void unused245();
    virtual void unused246();
    virtual void unused247();
    virtual void unused248();
    virtual void unused249();
    virtual void unused250();
    virtual void unused251();
    virtual void unused252();
    virtual void unused253();
    virtual void unused254();
    virtual void unused255();
    virtual void unused256();
    virtual void unused257();
    virtual void unused258();
    virtual void unused259();
    virtual void Flee(A*, int, int, int, int, int, float, float);
    virtual void unused261();
    virtual void ResetState();
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
    Proc* process;
    void FUN_008bed50(A*, int, bool, A*);
};
struct Extra
{
};
// @fnv 0x008bed50
void A::FUN_008bed50(A* source, int value, bool react, A* target)
{
    if (process && process->GetAssignedPackage() && reinterpret_cast<struct ::FUN_0041ca90 *>((process->GetAssignedPackage()))->get() == 21)
        return;
    if (IsSpecial())
    {
        if (source && !target)
            target = ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()));
        List* val;
        val = ((::List *)(reinterpret_cast<::ZOwner *>(&((*reinterpret_cast<::Lists *>(&::g_011e0e80))))->CollectActorsByPackage((int)(target), 21, 0)));
        if (!val)
            ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->SetCount(0);
        else
            ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->SetCount(val->GetSize());
        if (target && ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->GetCount() >= *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingLocal *>(&::g_011cd808)))))))
        {
            return;
        }
        else if (target)
        {
            if (target == (*reinterpret_cast<::A * *>(&::_g_thePlayer)) && ((unsigned char)(reinterpret_cast<::FUN_008a08c0_Class *>(((*reinterpret_cast<::A * *>(&::_g_thePlayer))))->GetByteAt7C4())))
            {
                process->Respond(this, target, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
                return;
            }
            else
                ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->SetFlag(1);
        }
    }
    if (GetType() == 9)
        ResetState();
    P* v = 0;
    P* package2;
    package2 = ((::P *)(reinterpret_cast<::Thing *>(this)->FUN_00881510()));
    if (package2 && reinterpret_cast<::TESPackage *>((package2))->IsPackageBlockingGreeting())
        package2 = ((::P *)(reinterpret_cast<::FUN_0041cb10_shell *>((((Extra*)((::P *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0())))))->FUN_0041cb10()));
    if ((((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())) || IsState(0) || reinterpret_cast<::FleeActorEntry *>(this)->FUN_008a6650(0) ||
         (package2 && reinterpret_cast<::FUN_0067a3f0_shell *>((package2))->HasFlag400000() && source &&
          ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((source))->GetName())) != (unsigned int)process->GetTarget())) &&
        react)
    {
        if (!IsState(0) && !((bool)(reinterpret_cast<::FUN_00833c20_shell *>((source))->FUN_00833c20())))
            process->React(this, ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0())), source);
        return;
    }
    process->Prepare();
    if (((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0())))
    {
        if (reinterpret_cast<struct ::FUN_0041ca90 *>((((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()))))->get() == 21)
            v = ((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()));
        else if (reinterpret_cast<::TESPackage *>((((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()))))->IsPackageBlockingGreeting())
            reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>(this)->FUN_00881680(0);
    }
    if (source && reinterpret_cast<::TESClass *>((((::Cls *)(reinterpret_cast<::fnv_00884350::FUN_00884350_shell *>(this)->FUN_00884350()))))->IsGuard())
    {
        reinterpret_cast<::FUN_008bf4e0_cls *>((source))->set(1);
        if (((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))->IsActor() && ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0())) != (*reinterpret_cast<::A * *>(&::_g_thePlayer)) &&
            !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))))->FUN_00493bb0())) && reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))))->FUN_005653d0())
        {
            A* locationX;
            locationX = ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()));
            if (!reinterpret_cast<::FleeActorEntry *>((locationX))->FUN_008a6650(0))
                locationX->Flee(this, 0, 1, 1, 0, 0, -1.0f, -1.0f);
            FleePackage* flee;
            flee = dynamic_cast<FleePackage*>(static_cast<TESPackage*>(((::P *)(reinterpret_cast<::FUN_009344a0_shell *>((locationX))->FUN_009344a0()))));
            if (flee)
                flee->FUN_009f1310((::TESObjectREFR *)(::A *)(this));
        }
    }
    if (!v)
    {
        P* tmp = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetAssignedPackage();
        Created* current;
        current = new Created(source);
        reinterpret_cast<::PackageEx *>((current))->SetPackageType(21);
        if (tmp)
        {
            reinterpret_cast<::FUN_00671a20_shell *>((current))->FUN_00671a20(reinterpret_cast<::FUN_0067a460_shell *>((tmp))->FUN_0067a460());
            reinterpret_cast<::FUN_0067a640_shell *>((current))->SetFlag200000(reinterpret_cast<::TESPackage *>((tmp))->GetForceUnequipWeapon());
        }
        reinterpret_cast<::TESPackage *>((current))->SetMustReachLocation(true);
        reinterpret_cast<::TESPackage *>((current))->SetMustComplete(true);
        Loc* s = new Loc;
        if (source)
            reinterpret_cast<::LocationDescriptor *>((s))->FUN_0067f3c0((::TESObjectREFR *)(::A *)(((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
        else
            reinterpret_cast<::LocationDescriptor *>((s))->FUN_0067f3c0((::TESObjectREFR *)(target));
        reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((current))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(s));
        delete s;
        Target* created;
        created = new Target;
        reinterpret_cast<::FUN_00672fc0_shell *>((current))->FUN_00672fc0((::PackageTargetRecord *)(created));
        delete created;
        reinterpret_cast<::TESPackage *>((current))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(11));
        reinterpret_cast<::PackageTargetRecord *>((((::Target *)(reinterpret_cast<::Script *>((current))->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(0));
        if (source)
            reinterpret_cast<::PackageTargetRecord *>((((::Target *)(reinterpret_cast<::Script *>((current))->GetData()))))->SetTargetObjectReference((::TESObjectREFR *)(::A *)(((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
        else
            reinterpret_cast<::PackageTargetRecord *>((((::Target *)(reinterpret_cast<::Script *>((current))->GetData()))))->SetTargetObjectReference((::TESObjectREFR *)(target));
        ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Reset();
        ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Notify(this);
        SetPackage(current, 0, 1);
        if (source)
            reinterpret_cast<::fnv_009eb9c0::Crime *>((source))->AddActor((::Actor *)(::A *)(this));
        process->SetValue(value);
    }
    else if (source && process->GetTarget() == ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0())) && !reinterpret_cast<::fnv_009ec810::FUN_009ec810_t *>((v))->IsSpellInList((::fnv_009ec810::SpellItem *)(source)))
        reinterpret_cast<::FUN_009ec830_t *>((v))->AddHeadAtOffset((int *)(source));
}
