
// src/fallout/magic/demoralizeeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/demoralizeeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/active_effect_fields.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/EffectSaveShell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00804f80_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_008a6730__FUN_008a6730_shell.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a1000.h"
#include "fnv/symbols_011de000.h"
class Actor;
class ActiveEffect
{
};
struct DemoralizeEffect : ActiveEffect
{
    unsigned short FUN_0080ccf0(Actor* apActor);
};
// Returns the save size of the effect: the base ActiveEffect save size plus one byte.
// @fnv 0x0080ccf0
unsigned short DemoralizeEffect::FUN_0080ccf0(Actor* apActor)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00804f80_shell *>(this)->FUN_00804f80(apActor);
    isize += 1;
    return isize;
}

class MagicCaster;
class MagicItem;
class EffectItem;
extern int DAT_01079ddc;
struct FUN_0080bc70_base
{
    FUN_0080bc70_base(MagicCaster*, MagicItem*, EffectItem*);
};
struct DemoralizeEffectFields : ActiveEffectFields
{
    unsigned char unk48;
};

struct FUN_0080c890 : FUN_0080bc70_base
{
    FUN_0080c890(MagicCaster*, MagicItem*, EffectItem*);
};
// Initializes the object's vtable pointer and clears the byte after the ActiveEffect members after constructing the base with the caster, item and effect item.
// @fnv 0x0080c890
FUN_0080c890::FUN_0080c890(MagicCaster* a, MagicItem* pItem, EffectItem* pEffectItem)
    : FUN_0080bc70_base(a, pItem, pEffectItem)
{
    *(void**)this = (void*)&DAT_01079ddc;
    reinterpret_cast<DemoralizeEffectFields*>(this)->unk48 = 0;
}

struct TESSaveLoadGame
{
};

struct SaveGameHelper
{
};

struct DemoralizeEffectShell : DemoralizeEffect
{
    void FUN_0082b750(Actor* apActor);
    char pad01[0x48];
    unsigned char unk48;
    char pad49[0x2];
};

// Saves the game for apActor, then calls FUN_008579b0 on this+0x48 with 1.
// @fnv 0x0082b750
void DemoralizeEffectShell::FUN_0082b750(Actor* apActor)
{
    reinterpret_cast<::EffectSaveShell *>((reinterpret_cast<SaveGameHelper*>(this)))->FUN_008050d0(apActor);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&this->unk48, 1);
}

class Actor;
struct PackageNodeHandler
{
    virtual void method000();
    virtual void method001();
    virtual void method002();
    virtual void method003();
    virtual void method004();
    virtual void method005();
    virtual void method006();
    virtual void method007();
    virtual void method008();
    virtual void method009();
    virtual void method010();
    virtual void method011();
    virtual void method012();
    virtual void method013();
    virtual void method014();
    virtual void method015();
    virtual void method016();
    virtual void method017();
    virtual void method018();
    virtual void method019();
    virtual void method020();
    virtual void method021();
    virtual void method022();
    virtual void method023();
    virtual void method024();
    virtual void method025();
    virtual void method026();
    virtual void method027();
    virtual void method028();
    virtual void method029();
    virtual void method030();
    virtual void method031();
    virtual void method032();
    virtual void method033();
    virtual void method034();
    virtual void method035();
    virtual void method036();
    virtual void method037();
    virtual void method038();
    virtual void method039();
    virtual void method040();
    virtual void method041();
    virtual void method042();
    virtual void method043();
    virtual void method044();
    virtual void method045();
    virtual void method046();
    virtual void method047();
    virtual void method048();
    virtual void method049();
    virtual void method050();
    virtual void method051();
    virtual void method052();
    virtual void method053();
    virtual void method054();
    virtual void method055();
    virtual void method056();
    virtual void method057();
    virtual void method058();
    virtual void method059();
    virtual void method060();
    virtual void method061();
    virtual void method062();
    virtual void method063();
    virtual void method064();
    virtual void method065();
    virtual void method066();
    virtual void method067();
    virtual void method068();
    virtual void method069();
    virtual void method070();
    virtual void method071();
    virtual void method072();
    virtual void method073();
    virtual void method074();
    virtual void method075();
    virtual void method076();
    virtual void method077();
    virtual void method078();
    virtual void method079();
    virtual void method080();
    virtual void method081();
    virtual void method082();
    virtual void method083();
    virtual void method084();
    virtual void method085();
    virtual void method086();
    virtual void method087();
    virtual void method088();
    virtual void method089();
    virtual void method090();
    virtual void method091();
    virtual void method092();
    virtual void method093();
    virtual void method094();
    virtual void method095();
    virtual void method096();
    virtual void method097();
    virtual void method098();
    virtual void method099();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual void method125();
    virtual void method126();
    virtual void method127();
    virtual void method128();
    virtual void method129();
    virtual void method130();
    virtual void method131();
    virtual void method132();
    virtual void method133();
    virtual void method134();
    virtual void method135();
    virtual void method136();
    virtual void method137();
    virtual void method138();
    virtual void method139();
    virtual void method140();
    virtual void method141();
    virtual void method142();
    virtual void method143();
    virtual void method144();
    virtual void method145();
    virtual void method146();
    virtual void method147();
    virtual void method148();
    virtual void method149();
    virtual void method150();
    virtual void method151();
    virtual void method152();
    virtual void method153();
    virtual void method154();
    virtual void method155();
    virtual void method156();
    virtual void method157();
    virtual void method158();
    virtual void method159();
    virtual void method160();
    virtual void method161();
    virtual void method162();
    virtual void method163();
    virtual void method164();
    virtual void method165();
    virtual void method166();
    virtual void method167();
    virtual void method168();
    virtual void method169();
    virtual void method170();
    virtual void method171();
    virtual void method172();
    virtual void method173();
    virtual void method174();
    virtual void method175();
    virtual void method176();
    virtual void method177();
    virtual void method178();
    virtual void method179();
    virtual void method180();
    virtual void method181();
    virtual void method182();
    virtual void method183();
    virtual void method184();
    virtual void method185();
    virtual void method186();
    virtual void method187();
    virtual void method188();
    virtual void method189();
    virtual void method190();
    virtual void method191();
    virtual void method192();
    virtual void method193();
    virtual void method194();
    virtual void method195();
    virtual void method196();
    virtual void method197();
    virtual void method198();
    virtual void method199();
    virtual void method200();
    virtual void method201();
    virtual void method202();
    virtual void method203();
    virtual void method204();
    virtual void method205();
    virtual void method206();
    virtual void Restore(Actor*, Actor*, int, int, int, int, int, int, int, int, int, int, int);
};
class Actor
{
  public:
    virtual void method000();
    virtual void method001();
    virtual void method002();
    virtual void method003();
    virtual void method004();
    virtual void method005();
    virtual void method006();
    virtual void method007();
    virtual void method008();
    virtual void method009();
    virtual void method010();
    virtual void method011();
    virtual void method012();
    virtual void method013();
    virtual void method014();
    virtual void method015();
    virtual void method016();
    virtual void method017();
    virtual void method018();
    virtual void method019();
    virtual void method020();
    virtual void method021();
    virtual void method022();
    virtual void method023();
    virtual void method024();
    virtual void method025();
    virtual void method026();
    virtual void method027();
    virtual void method028();
    virtual void method029();
    virtual void method030();
    virtual void method031();
    virtual void method032();
    virtual void method033();
    virtual void method034();
    virtual void method035();
    virtual void method036();
    virtual void method037();
    virtual void method038();
    virtual void method039();
    virtual void method040();
    virtual void method041();
    virtual void method042();
    virtual void method043();
    virtual void method044();
    virtual void method045();
    virtual void method046();
    virtual void method047();
    virtual void method048();
    virtual void method049();
    virtual void method050();
    virtual void method051();
    virtual void method052();
    virtual void method053();
    virtual void method054();
    virtual void method055();
    virtual void method056();
    virtual void method057();
    virtual void method058();
    virtual void method059();
    virtual void method060();
    virtual void method061();
    virtual void method062();
    virtual void method063();
    virtual void method064();
    virtual void method065();
    virtual void method066();
    virtual void method067();
    virtual void method068();
    virtual void method069();
    virtual void method070();
    virtual void method071();
    virtual void method072();
    virtual void method073();
    virtual void method074();
    virtual void method075();
    virtual void method076();
    virtual void method077();
    virtual void method078();
    virtual void method079();
    virtual void method080();
    virtual void method081();
    virtual void method082();
    virtual void method083();
    virtual void method084();
    virtual void method085();
    virtual void method086();
    virtual void method087();
    virtual void method088();
    virtual void method089();
    virtual void method090();
    virtual void method091();
    virtual void method092();
    virtual void method093();
    virtual void method094();
    virtual void method095();
    virtual void method096();
    virtual void method097();
    virtual void method098();
    virtual void method099();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual void method125();
    virtual void method126();
    virtual void method127();
    virtual void method128();
    virtual void method129();
    virtual void method130();
    virtual void method131();
    virtual void method132();
    virtual void method133();
    virtual void method134();
    virtual void method135();
    virtual void method136();
    virtual void method137();
    virtual void method138();
    virtual void method139();
    virtual void method140();
    virtual void method141();
    virtual void method142();
    virtual void method143();
    virtual void method144();
    virtual void method145();
    virtual void method146();
    virtual void method147();
    virtual void method148();
    virtual void method149();
    virtual void method150();
    virtual void method151();
    virtual void method152();
    virtual void method153();
    virtual void method154();
    virtual void method155();
    virtual void method156();
    virtual void method157();
    virtual void method158();
    virtual void method159();
    virtual void method160();
    virtual void method161();
    virtual void method162();
    virtual void method163();
    virtual void method164();
    virtual void method165();
    virtual void method166();
    virtual void method167();
    virtual void method168();
    virtual void method169();
    virtual void method170();
    virtual void method171();
    virtual void method172();
    virtual void method173();
    virtual void method174();
    virtual void method175();
    virtual void method176();
    virtual void method177();
    virtual void method178();
    virtual void method179();
    virtual void method180();
    virtual void method181();
    virtual void method182();
    virtual void method183();
    virtual void method184();
    virtual void method185();
    virtual void method186();
    virtual void method187();
    virtual void method188();
    virtual void method189();
    virtual void method190();
    virtual void method191();
    virtual void method192();
    virtual void method193();
    virtual void method194();
    virtual void method195();
    virtual void method196();
    virtual void method197();
    virtual void method198();
    virtual void method199();
    virtual void method200();
    virtual void method201();
    virtual void method202();
    virtual void method203();
    virtual void method204();
    virtual void method205();
    virtual void method206();
    virtual void method207();
    virtual void method208();
    virtual void method209();
    virtual void method210();
    virtual void method211();
    virtual void method212();
    virtual void method213();
    virtual void method214();
    virtual void method215();
    virtual void method216();
    virtual void method217();
    virtual void method218();
    virtual void method219();
    virtual void method220();
    virtual void method221();
    virtual void method222();
    virtual void method223();
    virtual void method224();
    virtual void method225();
    virtual void method226();
    virtual void method227();
    virtual void method228();
    virtual void method229();
    virtual void method230();
    virtual void method231();
    virtual void method232();
    virtual void method233();
    virtual void method234();
    virtual void method235();
    virtual void method236();
    virtual void method237();
    virtual void method238();
    virtual void method239();
    virtual void method240();
    virtual void method241();
    virtual void method242();
    virtual void method243();
    virtual void method244();
    virtual void method245();
    virtual void method246();
    virtual void method247();
    virtual void method248();
    virtual void method249();
    virtual void method250();
    virtual void method251();
    virtual void method252();
    virtual void method253();
    virtual void method254();
    virtual void method255();
    virtual void method256();
    virtual void method257();
    virtual void method258();
    virtual void method259();
    virtual void method260();
    virtual void method261();
    virtual void method262();
    virtual void method263();
    virtual void method264();
    virtual void method265();
    virtual void method266();
    virtual void method267();
    virtual void method268();
    virtual void Reset(Actor*);
};
class Actor;
class MagicTarget
{
public:
    ::Actor *GetOwnerActor() const;
};
class Actor;
class MagicCaster
{
public:
    ::Actor *GetCasterActor();
};
struct EffectController
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44;
    bool enabled;
    void RestoreEffect();
};
// @fnv 0x0080cb60
void EffectController::RestoreEffect()
{
    if (!enabled)
        return;
    Actor* target = ((::MagicTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::MagicTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetOwnerActor() : 0;
    Actor* caster = reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60() ? reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()->GetCasterActor() : 0;
    if (target)
    {
        if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((target))->FUN_00493bb0())))
        {
            target->Reset(caster);
            if (caster && ((::PackageNodeHandler *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture())))
            {
                ((::PackageNodeHandler *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->Restore(target, caster, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
            }
        }
        else if (reinterpret_cast<::FleeActorEntry *>((target))->FUN_008a6650(0))
            reinterpret_cast<::fnv_008a6730::FUN_008a6730_shell *>((target))->FUN_008a6730((::TESObjectREFR *)(caster));
    }
}

class MagicCaster;
class MagicItem;
class EffectItem;

struct C70ActiveEffect
{
};

struct C70DemoralizeEffect : C70ActiveEffect
{
    C70DemoralizeEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);

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
};

// Allocates and constructs a C70DemoralizeEffect from the given caster, magic item and effect item, returning it as a C70ActiveEffect pointer.
// @fnv 0x0080cc70
C70ActiveEffect* __cdecl CreateDemoralizeEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
{
    return new C70DemoralizeEffect(caster, item, effect);
}

struct SpawnedEffectObj : FUN_0080c890
{
    SpawnedEffectObj(MagicCaster* a, MagicItem* b, EffectItem* c) : FUN_0080c890(a, b, c)
    {}
    int unk00;
    int unk04;
    MagicItem* m_08;
    EffectItem* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    MagicCaster* m_28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    unsigned char m_48;
};

struct FUN_0080c8d0_cls
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(FUN_0080c890* p);
    int unk04;
    MagicItem* m_08;
    EffectItem* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    MagicCaster* m_28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    unsigned char m_48;
    FUN_0080c890* CreateSpawnedEffect();
};

// Allocates a SpawnedEffectObj from m_28, m_08 and m_0c, copies m_48 into it, calls v17 on it and returns it.
// @fnv 0x0080c8d0
FUN_0080c890* FUN_0080c8d0_cls::CreateSpawnedEffect()
{
    SpawnedEffectObj* obj = new SpawnedEffectObj(m_28, m_08, m_0c);
    obj->m_48 = m_48;
    v17(obj);
    return obj;
}


struct S_0080ca50_Actor;
struct S_0080ca50_Sub
{
};
struct S_0080ca50_Actor
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
    virtual void v410(S_0080ca50_Actor* t, bool a, bool b, bool c, int d, int e, float f, float g);
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual S_0080ca50_Sub* v428();
};
struct S_0080ca50_Actor2
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
    virtual S_0080ca50_Sub* v428(S_0080ca50_Actor* t, int a);
};
struct S_0080ca50_Caster
{
};
struct S_0080ca50_Target
{
};
struct S_0080ca50_Effect
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    char unk48;
    void FUN_0080ca50();
};

// Resolves caster and target actors; if both exist, either runs the caster's v428 path or calls FUN_00881680 and v410 on the caster, then sets unk48 to 1.
// @fnv 0x0080ca50
void S_0080ca50_Effect::FUN_0080ca50()
{
    S_0080ca50_Actor* caster = ((::S_0080ca50_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::S_0080ca50_Actor *)(reinterpret_cast<::MagicTarget *>((((::S_0080ca50_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    S_0080ca50_Actor* target2 = ((::S_0080ca50_Target *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())) ? ((::S_0080ca50_Actor *)(reinterpret_cast<::MagicCaster *>((((::S_0080ca50_Target *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()))))->GetCasterActor())) : 0;
    if (caster && target2)
    {
        if (caster->v428())
        {
            reinterpret_cast<::FUN_008d0600_s *>((((S_0080ca50_Actor2*)caster)->v428(target2, 0)))->FUN_008d0600({}, {});
            unk48 = 1;
        }
        else if (!reinterpret_cast<::FleeActorEntry *>((caster))->FUN_008a6650(0))
        {
            reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((caster))->FUN_00881680(0);
            caster->v410(target2, 1, 1, 1, 0, 0, ::DAT_01012054, ::DAT_01012054);
            unk48 = 1;
        }
    }
}


struct Actor_80c980;
int FUN_00ec43fb(Actor_80c980*, int, int*, int*, int);

struct Actor_80c980
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual bool v8b(int);
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual void va5();
    virtual void va6();
    virtual void va7();
    virtual void va8();
    virtual void va9();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual bool vba();
};

struct FUN_0080c980_cls
{
    bool FUN_0080c980(Actor_80c980* apActor);
};

// @fnv 0x0080c980
bool FUN_0080c980_cls::FUN_0080c980(Actor_80c980* apActor)
{
    Actor_80c980* Actor_80c980 = apActor ? ((::Actor_80c980 *)(reinterpret_cast<::MagicTarget *>((apActor))->GetOwnerActor())) : 0;
    if (Actor_80c980 != 0 && !Actor_80c980->v8b(0) && !Actor_80c980->vba() &&
        ::FUN_006494d0(reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((Actor_80c980))->FUN_0087f9f0(), ::GetFloatAtOffset1C((char *)(this))))
    {
        int result = FUN_00ec43fb(apActor, 0, &DAT_011a0ef8, &(*reinterpret_cast<int *>(&::_data_011a106c)), 0);
        if (result != 0)
        {
        }
        else
        {
            if (reinterpret_cast<::FUN_00608d80_shell *>((Actor_80c980))->FUN_00608d80())
                return false;
        }
        return true;
    }
    return false;
}
