
// src/fallout_shared/pathfinding/pathingdebuggeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingdebuggeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// FUN_00574400 - TESObjectREFR method, /Od /Oy- frame 0x44
#include <new>
#include "fnv/decl/ActorDeletionQueue.h"
#include "fnv/decl/B572270Object.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6760Ref.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Dfcfa0Manager.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0041de40_class.h"
#include "fnv/decl/FUN_0041df90_shell.h"
#include "fnv/decl/FUN_0041e310_shell.h"
#include "fnv/decl/FUN_00484af0_t.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_0056c780_t.h"
#include "fnv/decl/FUN_0056c880_S.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008b01c0_shell.h"
#include "fnv/decl/FUN_008c2b60_shell.h"
#include "fnv/decl/FUN_0093a660_class.h"
#include "fnv/decl/FUN_00952c30_shell.h"
#include "fnv/decl/FUN_00967350_shell.h"
#include "fnv/decl/FUN_0096e6f0_shell.h"
#include "fnv/decl/Fn56ac90.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/RefObj.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0041dbd0__FUN_0041dbd0_Class.h"
#include "fnv/decl/fnv_00545560__FUN_00545560Class.h"
#include "fnv/decl/fnv_00564d80__ArrSI.h"
#include "fnv/decl/fnv_005656d0__Thing.h"
#include "fnv/decl/fnv_00568020__FUN_00568020_shell.h"
#include "fnv/decl/fnv_00573f40__R.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_0088d640__FUN_0088d640_shell.h"
#include "fnv/decl/fnv_0096f600__FUN_0096f600_shell.h"
#include "fnv/symbols_00570000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_007eb000.h"
#include "fnv/symbols_00835000.h"
#include "fnv/symbols_008cd000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include <windows.h>
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/symbols_007f6000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01203000.h"
struct Ref;
struct ExtraList;
struct Proc;
struct ObjX;
struct MagicSub
{
};

struct Ref
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vt4c(int a);
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtc8(int a);
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual bool vtfc();
    virtual bool vt100();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vt1cc(int a, int b);
    virtual void vtbl116();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual void vtbl125();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void vtbl128();
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual void vtbl133();
    virtual void vtbl134();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual void vtbl139();
    virtual void vtbl140();
    virtual void vtbl141();
    virtual void vtbl142();
    virtual void vtbl143();
    virtual void vtbl144();
    virtual void vtbl145();
    virtual void vtbl146();
    virtual void vtbl147();
    virtual void vtbl148();
    virtual void vtbl149();
    virtual void vtbl150();
    virtual void vtbl151();
    virtual void vtbl152();
    virtual void vtbl153();
    virtual void vtbl154();
    virtual void vtbl155();
    virtual void vtbl156();
    virtual void vtbl157();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void vtbl161();
    virtual void vt288();
    virtual void vtbl163();
    virtual void vtbl164();
    virtual void vtbl165();
    virtual void vtbl166();
    virtual void vtbl167();
    virtual void vtbl168();
    virtual void vtbl169();
    virtual void vtbl170();
    virtual void vtbl171();
    virtual void vtbl172();
    virtual void vtbl173();
    virtual void vtbl174();
    virtual void vtbl175();
    virtual void vtbl176();
    virtual void vtbl177();
    virtual void vtbl178();
    virtual void vtbl179();
    virtual void vtbl180();
    virtual void vtbl181();
    virtual void vtbl182();
    virtual void vtbl183();
    virtual void vtbl184();
    virtual void vtbl185();
    virtual bool vt2e8();
    virtual void vtbl187();
    virtual void vtbl188();
    virtual void vtbl189();
    virtual void vtbl190();
    virtual void vt2fc();
    int FUN_00931850();
    void FUN_00574400();
};
struct ExtraList
{
};
struct Iter
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};

struct Proc
{
    virtual void* vt000(int a);
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual void vtbl116();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual void vtbl125();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void vtbl128();
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual void vtbl133();
    virtual void vtbl134();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual int vt22c();
    virtual void vtbl140();
    virtual void vtbl141();
    virtual void vtbl142();
    virtual void vtbl143();
    virtual void vtbl144();
    virtual void vtbl145();
    virtual void vtbl146();
    virtual void vtbl147();
    virtual void vtbl148();
    virtual void vtbl149();
    virtual void vtbl150();
    virtual void vtbl151();
    virtual void vtbl152();
    virtual void vtbl153();
    virtual void vtbl154();
    virtual void vtbl155();
    virtual void vtbl156();
    virtual void vtbl157();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void vtbl161();
    virtual void vtbl162();
    virtual void vtbl163();
    virtual void vtbl164();
    virtual void vtbl165();
    virtual void vtbl166();
    virtual void vtbl167();
    virtual void vtbl168();
    virtual void vtbl169();
    virtual void vtbl170();
    virtual void vtbl171();
    virtual void vtbl172();
    virtual void vtbl173();
    virtual void vtbl174();
    virtual void vtbl175();
    virtual void vtbl176();
    virtual void vtbl177();
    virtual void vtbl178();
    virtual void vtbl179();
    virtual void vtbl180();
    virtual void vtbl181();
    virtual void vtbl182();
    virtual void vtbl183();
    virtual void vtbl184();
    virtual void vtbl185();
    virtual void vtbl186();
    virtual void vtbl187();
    virtual void vtbl188();
    virtual void vtbl189();
    virtual void vtbl190();
    virtual void vtbl191();
    virtual void vtbl192();
    virtual void vtbl193();
    virtual void vtbl194();
    virtual void vtbl195();
    virtual void vtbl196();
    virtual void vtbl197();
    virtual void vtbl198();
    virtual void vtbl199();
    virtual void vtbl200();
    virtual void vtbl201();
    virtual void vtbl202();
    virtual void vtbl203();
    virtual void vtbl204();
    virtual void vtbl205();
    virtual void vtbl206();
    virtual void vtbl207();
    virtual void vtbl208();
    virtual void vtbl209();
    virtual void vtbl210();
    virtual void vtbl211();
    virtual void vtbl212();
    virtual void vtbl213();
    virtual void vtbl214();
    virtual void vtbl215();
    virtual void vtbl216();
    virtual void vtbl217();
    virtual void vtbl218();
    virtual void vtbl219();
    virtual void vtbl220();
    virtual void vtbl221();
    virtual void vtbl222();
    virtual void vtbl223();
    virtual void vtbl224();
    virtual void vtbl225();
    virtual void vtbl226();
    virtual void vtbl227();
    virtual void vtbl228();
    virtual void vtbl229();
    virtual void vtbl230();
    virtual void vtbl231();
    virtual void vtbl232();
    virtual void vtbl233();
    virtual void vtbl234();
    virtual void vtbl235();
    virtual void vtbl236();
    virtual void vtbl237();
    virtual void vtbl238();
    virtual void vtbl239();
    virtual void vtbl240();
    virtual void vtbl241();
    virtual void vtbl242();
    virtual void vtbl243();
    virtual void vtbl244();
    virtual void vtbl245();
    virtual void vtbl246();
    virtual void vtbl247();
    virtual void vtbl248();
    virtual void vtbl249();
    virtual void vtbl250();
    virtual void vtbl251();
    virtual void vtbl252();
    virtual void vtbl253();
    virtual void vtbl254();
    virtual void vtbl255();
    virtual void vtbl256();
    virtual void vtbl257();
    virtual void vtbl258();
    virtual void vtbl259();
    virtual void vtbl260();
    virtual void vtbl261();
    virtual void vtbl262();
    virtual void vtbl263();
    virtual void vtbl264();
    virtual void vtbl265();
    virtual void vtbl266();
    virtual void vtbl267();
    virtual void vtbl268();
    virtual void vtbl269();
    virtual void vtbl270();
    virtual void vtbl271();
    virtual void vtbl272();
    virtual void vtbl273();
    virtual void vtbl274();
    virtual void vtbl275();
    virtual void vtbl276();
    virtual void vtbl277();
    virtual void vtbl278();
    virtual void vtbl279();
    virtual void vtbl280();
    virtual void vtbl281();
    virtual void vtbl282();
    virtual void vtbl283();
    virtual void vtbl284();
    virtual void vtbl285();
    virtual void vtbl286();
    virtual void vtbl287();
    virtual void vtbl288();
    virtual void vtbl289();
    virtual void vtbl290();
    virtual void vtbl291();
    virtual void vtbl292();
    virtual void vtbl293();
    virtual void vtbl294();
    virtual void vtbl295();
    virtual void vtbl296();
    virtual void vtbl297();
    virtual void vtbl298();
    virtual void vtbl299();
    virtual void vtbl300();
    virtual void vtbl301();
    virtual void vtbl302();
    virtual void vtbl303();
    virtual void vtbl304();
    virtual void vtbl305();
    virtual ObjX* vt4c8();
    virtual void vtbl307();
    virtual int vt4d0(int a);
};
struct ObjX
{
};
struct Tes
{
};
struct GlobalObj
{
};

// @fnv 0x00574400
void Ref::FUN_00574400()
{
    Ref* p;
    Iter* val;
    {
        Iter* it1;
        Ref* var1;
        Ref* q;
        Ref* r;
        {
            Ref* procCopy;
            Proc* t3;
            Ref* i;
            Proc* d1;
            Ref* it2;
            if (!reinterpret_cast<::TESForm *>(this)->GetDisabled())
            {
                if (this == (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)))
                    return;
                {
                    vt1cc(0, 0);
                    var1 = ((::Ref *)(reinterpret_cast<::FUN_0041e310_shell *>((((::ExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041e310()));
                    if (var1 != 0)
                    {
                        if (((::Ref *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) != DAT_011ca27c)
                        {
                            if (((::Ref *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) != DAT_011ca280)
                            {
                                var1->FUN_00574400();
                            }
                        }
                    }
                    reinterpret_cast<::C6760Ref *>(this)->FUN_00576760();
                    vtc8(1);
                    reinterpret_cast<::FUN_00484af0_t *>(this)->FUN_00484af0(1);
                    p = 0;
                    if (vtfc())
                        p = this;
                    if (p != 0)
                    {
                        if (((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture())) != 0)
                        {
                            if (p->vt100())
                            {
                                q = p;
                                reinterpret_cast<::FUN_008c2b60_shell *>((q))->ApplyActorSpells();
                                reinterpret_cast<::MagicTarget *>((((MagicSub*)((char*)q + 0x94))))->DispelAllEffects();
                                if (FUN_00570f60() > 0)
                                {
                                    ::FUN_008cddd0((::MobileObject *)(::Ref *)(this), 1);
                                }
                                reinterpret_cast<::FUN_0093a660_class *>(((*reinterpret_cast<::Ref * *>(&::_g_thePlayer))))->FUN_0093a660((int)(q));
                                reinterpret_cast<::FUN_00967350_shell *>(((*reinterpret_cast<::Ref * *>(&::_g_thePlayer))))->FUN_00967350((int)(q));
                                reinterpret_cast<::FUN_0096e6f0_shell *>(&((*reinterpret_cast<::GlobalObj *>(&::g_011e0e80))))->RemoveActor((::Actor *)(q));
                                if (((::Ref *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) != 0)
                                {
                                    if (reinterpret_cast<::fnv_005656d0::Thing *>(this)->FUN_005656d0())
                                    {
                                        reinterpret_cast<::fnv_00545560::FUN_00545560Class *>((((::Ref *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00545560((int)(this));
                                    }
                                }
                                if (q->vt2e8())
                                {
                                    reinterpret_cast<::FUN_008b01c0_shell *>((q))->FUN_008b01c0();
                                }
                            }
                            p->vt2fc();
                            reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::GlobalObj *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(p), p->FUN_00931850());
                            if (vt100() || reinterpret_cast<::fnv_00564d80::ArrSI *>(this)->FUN_00564d80())
                            {
                                reinterpret_cast<::fnv_0096f600::FUN_0096f600_shell *>(&((*reinterpret_cast<::GlobalObj *>(&::g_011e0e80))))->FUN_0096f600((::Actor *)(::Ref *)(this), 0);
                            }
                            if (((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture())) != 0)
                            {
                                if (((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture()))->vt22c() != 0)
                                {
                                    r = 0;
                                    if (p != 0)
                                    {
                                        if (p->vt100())
                                            r = p;
                                    }
                                    if (r != 0)
                                    {
                                        r->vt288();
                                        reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((r))->FUN_00881680(0);
                                    }
                                    else
                                    {
                                        if (((bool)(::FUN_00574900((const unsigned char *)(p)))))
                                        {
                                            p->vt288();
                                        }
                                    }
                                }
                            }
                            if (vt100())
                            {
                                vt4c(0x100000);
                                vt4c(0x200000);
                            }
                            if (((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture())) != 0)
                            {
                                if (((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture()))->vt4c8() != 0)
                                {
                                    if (p->vt100())
                                    {
                                        i = p;
                                        reinterpret_cast<::fnv_0088d640::FUN_0088d640_shell *>((i))->FUN_0088d640();
                                    }
                                    else
                                    {
                                        reinterpret_cast<::fnv_00568020::FUN_00568020_shell *>((((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture()))->vt4c8()))->FUN_00568020(((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture()))->vt4d0(0), {});
                                    }
                                }
                                d1 = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((p))->GetBaseTexture()));
                                t3 = d1;
                                (t3 != 0) ? t3->vt000(1) : 0;
                                reinterpret_cast<::MiddleHighProcess *>((p))->SetFaceAnimationData((::TargetDoorController *)(::Proc *)((Proc*)0));
                            }
                        }
                    }
                    if (reinterpret_cast<::FUN_00549580_shell *>((((::Ref *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))))->FUN_00549580())
                    {
                        reinterpret_cast<::Dfcfa0Manager *>((((::ObjX *)(reinterpret_cast<::TESWorldSpace *>((((::ObjX *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::Tes * *>(&::g_TES))))->GetHitSound()))))->GetWorldTerrainManager()))))->FUN_006fcfa0({}, {});
                    }
                    reinterpret_cast<::FUN_0056c880_S *>(this)->FUN_0056c880(1, 0);
                    reinterpret_cast<::FUN_00952c30_shell *>(((*reinterpret_cast<::Ref * *>(&::_g_thePlayer))))->FUN_00952c30((::TESObjectREFR *)(::Ref *)(this));
                    it1 = (Iter*)reinterpret_cast<::Fn56ac90 *>(this)->FUN_0056ac90();
                    while (it1 != 0 && !it1->FUN_008256d0())
                    {
                        procCopy = *((::Ref **)((void *)(it1)));
                        if (((bool)(reinterpret_cast<::InventoryChanges *>((procCopy))->CreateForReference())))
                        {
                            if (reinterpret_cast<::fnv_0041dbd0::FUN_0041dbd0_Class *>((((::ExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>((procCopy))->FUN_005d43c0()))))->FUN_0041dbd0())
                            {
                                reinterpret_cast<::FUN_0056c780_t *>((procCopy))->FUN_0056c780(1);
                            }
                            reinterpret_cast<::fnv_00573f40::R *>((procCopy))->FUN_00573f40();
                        }
                        else
                        {
                            procCopy->FUN_00574400();
                        }
                        it1 = ((::Iter *)(reinterpret_cast<::Callees *>((it1))->FUN_00726070()));
                    }
                    val = (Iter*)reinterpret_cast<::FUN_0041df90_shell *>((((::ExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041df90();
                    while (val != 0 && !val->FUN_008256d0())
                    {
                        it2 = *((::Ref **)((void *)(val)));
                        reinterpret_cast<::FUN_0041de40_class *>((((::ExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>((it2))->FUN_005d43c0()))))->FUN_0041de40((::TESObjectREFR *)(::Ref *)(0));
                        reinterpret_cast<::B572270Object *>((it2))->FUN_00572270();
                        val->FUN_0063f7b0();
                    }
                    reinterpret_cast<::RefObj *>(this)->FUN_00579ac0(0);
                    if (vt100())
                    {
                        ::FUN_00835980((::TESObjectREFR_Stub *)(::Ref *)(this));
                    }
                }
            }
        }
    }
}

struct ObjectResolver
{
    int unk00;
};

struct ListNode
{
    bool Probe();
};

struct EventTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(int a, int b);
};



// @fnv 0x007f6a20
void __cdecl FUN_007f6a20(int a1)
{
    if ((*reinterpret_cast<::ListNode *>(&::g_011db150)).Probe())
    {
        return;
    }
    ListNode* pNode = &(*reinterpret_cast<::ListNode *>(&::g_011db150));
    while (pNode != 0 && !pNode->Probe())
    {
        if ((*(int**)((::ObjectResolver *)((void *)(pNode))))[0] == a1)
        {
            if ((*reinterpret_cast<int *>(&::DAT_011f21cc)) == a1 && DAT_011db0d4 != 0)
            {
                ((EventTarget*)DAT_011db0d4)->v0c(2, 0);
            }
            reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::ListNode *>(&::g_011db150))))->FUN_00905330((*(::InventoryStackRecord *const *)(((::ObjectResolver *)((void *)(pNode))))));
            if ((*reinterpret_cast<::ListNode *>(&::g_011db150)).Probe() && DAT_011db0d4 != 0)
            {
                ::ShutdownVats();
            }
        }
        pNode = ((::ListNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    int last = *(int*)((::ObjectResolver *)(new ((void *)&((*reinterpret_cast<::ListNode *>(&::g_011db150)))) ::Vec3()));
}

struct Ref_ob1;

struct Ref_ob1
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vt4c(int a);
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtc8(int a);
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual bool vtfc();
    virtual bool vt100();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vt1cc(int a, int b);
    virtual void vtbl116();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual void vtbl125();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void vtbl128();
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual void vtbl133();
    virtual void vtbl134();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual void vtbl139();
    virtual void vtbl140();
    virtual void vtbl141();
    virtual void vtbl142();
    virtual void vtbl143();
    virtual void vtbl144();
    virtual void vtbl145();
    virtual void vtbl146();
    virtual void vtbl147();
    virtual void vtbl148();
    virtual void vtbl149();
    virtual void vtbl150();
    virtual void vtbl151();
    virtual void vtbl152();
    virtual void vtbl153();
    virtual void vtbl154();
    virtual void vtbl155();
    virtual void vtbl156();
    virtual void vtbl157();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void vtbl161();
    virtual void vt288();
    virtual void vtbl163();
    virtual void vtbl164();
    virtual void vtbl165();
    virtual void vtbl166();
    virtual void vtbl167();
    virtual void vtbl168();
    virtual void vtbl169();
    virtual void vtbl170();
    virtual void vtbl171();
    virtual void vtbl172();
    virtual void vtbl173();
    virtual void vtbl174();
    virtual void vtbl175();
    virtual void vtbl176();
    virtual void vtbl177();
    virtual void vtbl178();
    virtual void vtbl179();
    virtual void vtbl180();
    virtual void vtbl181();
    virtual void vtbl182();
    virtual void vtbl183();
    virtual void vtbl184();
    virtual void vtbl185();
    virtual bool vt2e8();
    virtual void vtbl187();
    virtual void vtbl188();
    virtual void vtbl189();
    virtual void vtbl190();
    virtual void vt2fc();
    void FUN_00574400();
};

struct PointJack
{
    float x, y, z;
    PointJack()
    {}
    PointJack(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

struct ColorJack
{
    float r, g, b, a;
    ColorJack() : r(0), g(0), b(0), a(0)
    {}
};

struct MatrixJack
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};

struct PoolJack
{
};

extern ColorJack DAT_01203308, DAT_01203318;

struct NameJack
{
    char* p;
    NameJack(const char* text)
    {
        if (!text)
            p = DAT_0109b220;
        else
            p = ::NiGlobalStringTable::AddString(text);
    }
    ~NameJack()
    {
        if (p == DAT_0109b220)
        {
        }
        else
        {
            long* q = (long*)(p - 8);
            InterlockedDecrement(q);
        }
    }
};

struct JackGeometry
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30;
    MatrixJack matrix;
    PointJack position;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    JackGeometry(int, PointJack*, ColorJack*, int, int, int, char*);
};

// @fnv 0x00c59200
JackGeometry* __cdecl FUN_00c59200(float scale)
{
    PointJack* positions = new PointJack[6];
    positions[0] = PointJack(0, 0, 0);
    positions[1] = PointJack(scale, 0, 0);
    positions[2] = PointJack(0, 0, 0);
    positions[3] = PointJack(0, scale, 0);
    positions[4] = PointJack(0, 0, 0);
    positions[5] = PointJack(0, 0, scale);
    ColorJack* colors = new ColorJack[6];
    colors[0] = (*reinterpret_cast<::ColorJack *>(&::DAT_012032f8));
    colors[1] = (*reinterpret_cast<::ColorJack *>(&::DAT_012032f8));
    colors[2] = DAT_01203308;
    colors[3] = DAT_01203308;
    colors[4] = DAT_01203318;
    colors[5] = DAT_01203318;
    char* flags3 = new char[6];
    flags3[0] = 1;
    flags3[1] = 0;
    flags3[2] = 1;
    flags3[3] = 0;
    flags3[4] = 1;
    flags3[5] = 0;
    JackGeometry* result9 = new JackGeometry(6, positions, colors, 0, 0, 0, flags3);
    result9->position = (*reinterpret_cast<::PointJack *>((void *)&::NiPoint3::ZERO));
    result9->matrix = (*reinterpret_cast<::MatrixJack *>(&::DAT_011a9448));
    ::AssignFixedString((char *)(result9), (int)&(const ::NameJack &)(NameJack("BSTestObjects Coordinate Jack")), {});
    return result9;
}
#include "generated/data/fallout_shared/pathfinding/pathingdebuggeometry_ob1_variant.inc"
