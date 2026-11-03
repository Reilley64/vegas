
// src/havok/unplaced/loadedareabound.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/loadedareabound.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DurationData.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00450b60_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004938e0_shell.h"
#include "fnv/decl/FUN_0055ac00_t.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00568680_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_006270f0.h"
#include "fnv/decl/FUN_00628d10_cls.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009f3390_shell.h"
#include "fnv/decl/IOManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Me.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/Pathing.h"
#include "fnv/decl/Ref_891d30.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S00628c50_Box.h"
#include "fnv/decl/SitTarget.h"
#include "fnv/decl/TESFurniture.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_005682c0__FUN_005682c0_shell.h"
#include "fnv/decl/fnv_00568500__FUN_00568500_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008a7870__FUN_008a7870_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00562000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00886000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01202000.h"
struct LoadedAreaBound
{
    virtual ~LoadedAreaBound();
    void* FUN_006270c0(unsigned int flags);
    static void operator delete(void* p, size_t size);
};

// Calls FUN_006270f0, then deletes this with size 0x44 when flags has bit 0 set, and returns this.
// @fnv 0x006270c0
void* LoadedAreaBound::FUN_006270c0(unsigned int flags)
{
    reinterpret_cast<::FUN_006270f0 *>((this))->FUN_006270f0::~FUN_006270f0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x44);
    return this;
}

struct Point3
{
    float x;
    float y;
    float z;
};
struct Actor;
struct Refr;
struct ObjA
{
};
struct Refr
{
};
struct Obj44
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual int v008();
};
struct Proc
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
    virtual Obj44* v274();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void v284(int a);
    virtual void v288(Actor* a, int b);
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
    virtual void vtbl306();
    virtual void vtbl307();
    virtual void vtbl308();
    virtual int v4d4();
    virtual void vtbl310();
    virtual void vtbl311();
    virtual void vtbl312();
    virtual void vtbl313();
    virtual void vtbl314();
    virtual void vtbl315();
    virtual void vtbl316();
    virtual void vtbl317();
    virtual void vtbl318();
    virtual void vtbl319();
    virtual void vtbl320();
    virtual void vtbl321();
    virtual void vtbl322();
    virtual void vtbl323();
    virtual void vtbl324();
    virtual Refr* v514();
};
struct Actor : Refr
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
    virtual bool v100();
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
    virtual int v1d0();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual Point3* v1f4();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void v200(int a);
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual int v214();
    virtual bool v218();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual bool v22c(int flags);
public:
    bool IsMoving();
public:
    void ConfigureActorState(bool, bool);
};
struct Pkg
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
    virtual bool v13c(Actor* a, int b, float c, int e);
};
struct TopicArr
{
};
struct MgrNode
{
    bool FUN_008256d0();
};
struct TES
{
};
struct IOMgr
{
};
struct ThisCls
{
    int m_00;
    TopicArr m_04;
    void FUN_00972d30();
};
// @fnv 0x00972d30
void ThisCls::FUN_00972d30()
{
    bool resultFlag;
    {
        MgrNode* iter = ((::MgrNode *)(reinterpret_cast<::FUN_0055ac00_t *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0055ac00()));
        Refr* currentReference;
        currentReference = 0;
        ObjA* chosen;
        chosen = 0;
        {
            resultFlag = 0;
            Actor* b;
            b = 0;
            int slot;
            for (slot = 0; slot < reinterpret_cast<::FUN_005be5c0_shell *>(&(m_04))->FUN_005be5c0(0); slot++)
            {
                Actor* j;
                b = ((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>(&(m_04))->FUN_00968670(slot)));
                j = 0;
                if (!!b)
                {
                    if (b->v100())
                        j = b;
                }
                if (j != 0)
                {
                    if (!j->v22c(0))
                    {
                        if (j->v218())
                        {
                            if (!reinterpret_cast<::FUN_004938e0_shell *>((j))->FUN_004938e0())
                            {
                                if (!j->IsMoving())
                                {
                                    if (j->v214() == 0)
                                    {
                                        if (((::Refr *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture()))))->FUN_0045cd60())) != 0)
                                            continue;
                                        {
                                            j->ConfigureActorState(0, 0);
                                            intptr_t pObj4 = ((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((j))->FUN_00575ca0()));
                                            Refr* accepted = 0;
                                            bool visible = false;
                                            bool _x = false;
                                            Refr* refr38;
                                            Refr* found = ((::Refr *)(::FUN_00886080((char *)(j))));
                                            refr38 = ((::Refr *)(reinterpret_cast<::FUN_00881650_shell *>((j))->FUN_00881650()));
                                            Pkg* tmp26 = ((::Pkg *)(reinterpret_cast<::FUN_009344a0_shell *>((j))->FUN_009344a0()));
                                            if (!!tmp26)
                                            {
                                                if (reinterpret_cast<struct ::FUN_0041ca90 *>((tmp26))->get() == 13)
                                                {
                                                    Obj44* p5c;
                                                    p5c = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture()))->v274();
                                                    if (0 != p5c)
                                                    {
                                                        if (p5c->v008() == 13)
                                                        {
                                                            Obj44* tmp78;
                                                            tmp78 = p5c;
                                                            refr38 = (Refr*)((::Refr *)(reinterpret_cast<::FUN_009f3390_shell *>((tmp78))->FUN_009f3390()));
                                                        }
                                                    }
                                                }
                                            }
                                            Refr* q = 0;
                                            if (found != 0)
                                                q = ((::Refr *)(reinterpret_cast<::LocationDescriptor *>((found))->GetLocationReference()));
                                            if (found != 0)
                                            {
                                                if (reinterpret_cast<::DurationData *>((found))->FUN_00678ca0() == 6)
                                                    q = ((::Refr *)(reinterpret_cast<::FUN_00569b80_shell *>((j))->FUN_00569b80()));
                                            }
                                            if (!q)
                                            {
                                                q = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture())) ? ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture()))->v514() : 0;
                                            }
                                            intptr_t _object;
                                            _object = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture()))->v4d4();
                                            unsigned int idx13 = -1;
                                            if (refr38 != 0 && reinterpret_cast<::FUN_00568680_shell *>((refr38))->FUN_00568680() &&
                                                ((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((refr38))->FUN_00575ca0())) == pObj4)
                                            {
                                                accepted = refr38;
                                                chosen = ((::ObjA *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((accepted))->FUN_007af430()));
                                                if (reinterpret_cast<::TESFurniture *>((chosen))->GetCanSleepOn())
                                                    visible = true;
                                                idx13 = reinterpret_cast<::fnv_005682c0::FUN_005682c0_shell *>((accepted))->FUN_005682c0(true);
                                                if (idx13 == -1 || !reinterpret_cast<::fnv_00568500::FUN_00568500_shell *>((accepted))->FUN_00568500(idx13, (::fnv_00568500::FurnitureMark *)(_object)))
                                                {
                                                    accepted = 0;
                                                    _x = true;
                                                }
                                            }
                                            else if (q != 0 && reinterpret_cast<::FUN_00568680_shell *>((q))->FUN_00568680() && ((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((q))->FUN_00575ca0())) == pObj4)
                                            {
                                                accepted = q;
                                                chosen = ((::ObjA *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((accepted))->FUN_007af430()));
                                                if (reinterpret_cast<::TESFurniture *>((chosen))->GetCanSleepOn())
                                                    visible = true;
                                                idx13 = reinterpret_cast<::fnv_005682c0::FUN_005682c0_shell *>((accepted))->FUN_005682c0(true);
                                                if (idx13 == -1 || !reinterpret_cast<::fnv_00568500::FUN_00568500_shell *>((accepted))->FUN_00568500(idx13, (::fnv_00568500::FurnitureMark *)(_object)))
                                                {
                                                    accepted = 0;
                                                    _x = true;
                                                }
                                            }
                                            else if (tmp26 != 0 && reinterpret_cast<struct ::FUN_0041ca90 *>((tmp26))->get() == 4 &&
                                                     tmp26->v13c(j, 0, -1.0f, 0))
                                            {
                                                if (!::FUN_00579670((char *)(j)))
                                                {
                                                    ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture()))->v284(1);
                                                }
                                                while (0 != iter && !iter->FUN_008256d0() && accepted == 0)
                                                {
                                                    currentReference = *((::Refr **)(new ((void *)(iter)) ::Vec3()));
                                                    bool flag49 = false;
                                                    if (((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((currentReference))->FUN_00575ca0())) == pObj4)
                                                    {
                                                        if (((void *)(reinterpret_cast<::OwnerLookupView *>((currentReference))->FUN_00567790())) == 0 ||
                                                            reinterpret_cast<::OwnershipReferenceView *>((currentReference))->FUN_005785e0(j, true))
                                                        {
                                                            chosen = ((::ObjA *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((currentReference))->FUN_007af430()));
                                                            if (reinterpret_cast<::TESFurniture *>((chosen))->GetCanSleepOn())
                                                            {
                                                                idx13 = reinterpret_cast<::fnv_005682c0::FUN_005682c0_shell *>((currentReference))->FUN_005682c0(true);
                                                                if (idx13 == -1 ||
                                                                    !reinterpret_cast<::fnv_00568500::FUN_00568500_shell *>((currentReference))->FUN_00568500(idx13, (::fnv_00568500::FurnitureMark *)(_object)))
                                                                {
                                                                    reinterpret_cast<::ItemChangeListNode *>((iter))->FUN_00905330((*(::InventoryStackRecord *const *)(&currentReference)));
                                                                    iter = ((::MgrNode *)(reinterpret_cast<::FUN_0055ac00_t *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0055ac00()));
                                                                    flag49 = true;
                                                                }
                                                                else
                                                                {
                                                                    accepted = currentReference;
                                                                    visible = true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (!flag49)
                                                        iter = ((::MgrNode *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
                                                }
                                            }
                                            else if (tmp26 != 0 && reinterpret_cast<struct ::FUN_0041ca90 *>((tmp26))->get() == 3 &&
                                                     tmp26->v13c(j, 0, -1.0f, 0))
                                            {
                                                if (((void *)(reinterpret_cast<::Ref_891d30 *>((j))->FUN_00891d30())) != 0)
                                                {
                                                    if (!reinterpret_cast<::fnv_008a7870::FUN_008a7870_shell *>((j))->FUN_008a7870())
                                                    {
                                                        ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((j))->GetBaseTexture()))->v288(j, 1);
                                                        j->v200(1);
                                                    }
                                                    while (iter != 0 && !iter->FUN_008256d0() && accepted == 0)
                                                    {
                                                        currentReference = *((::Refr **)(new ((void *)(iter)) ::Vec3()));
                                                        bool flag4a = false;
                                                        if (((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((currentReference))->FUN_00575ca0())) == pObj4 &&
                                                            currentReference != 0)
                                                        {
                                                            if (((void *)(reinterpret_cast<::OwnerLookupView *>((currentReference))->FUN_00567790())) == 0 ||
                                                                reinterpret_cast<::OwnershipReferenceView *>((currentReference))->FUN_005785e0(j, true))
                                                            {
                                                                chosen = ((::ObjA *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((currentReference))->FUN_007af430()));
                                                                if (reinterpret_cast<::TESFurniture *>((chosen))->GetCanSitOn())
                                                                {
                                                                    idx13 = reinterpret_cast<::fnv_005682c0::FUN_005682c0_shell *>((currentReference))->FUN_005682c0(true);
                                                                    if (idx13 == -1 ||
                                                                        !reinterpret_cast<::fnv_00568500::FUN_00568500_shell *>((currentReference))->FUN_00568500(idx13, (::fnv_00568500::FurnitureMark *)(_object)))
                                                                    {
                                                                        reinterpret_cast<::ItemChangeListNode *>((iter))->FUN_00905330((*(::InventoryStackRecord *const *)(&currentReference)));
                                                                        iter = ((::MgrNode *)(reinterpret_cast<::FUN_0055ac00_t *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0055ac00()));
                                                                        flag4a = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        accepted = currentReference;
                                                                        visible = false;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        if (!flag4a)
                                                            iter = ((::MgrNode *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
                                                    }
                                                }
                                            }
                                            if (accepted != 0 && j->v1d0() != 0)
                                            {
                                                resultFlag = reinterpret_cast<::SitTarget *>((j))->FUN_0088d2f0((::SitReference *)(accepted), (::SitReference *)(_object), idx13, visible);
                                            }
                                            else if (_x)
                                            {
                                                Point3* _origin;
                                                _origin = j->v1f4();
                                                Point3 pt = *_origin;
                                                ::Pathing::FindClosestPathingPoint((::TESWorldSpace *)(void *)(((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((j))->FUN_00575d70()))), (::TESObjectCELL *)(void *)(((void *)(reinterpret_cast<::LowProcess *>((j))->GetTarget()))), (*(const ::NiPoint3 *)(_origin)), (::NiPoint3 *)(::Point3 *)(&pt));
                                                reinterpret_cast<::Reference *>((j))->FUN_00575830((::Position *)(::Point3 *)(&pt));
                                                ::fnv_00562020::FUN_00562020((::TESObjectREFR *)(j));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (resultFlag)
                reinterpret_cast<::IOManager *>(((*reinterpret_cast<::IOMgr * *>(&::DAT_01202d98))))->FUN_00c3dfa0(0);
        }
        reinterpret_cast<::FUN_00450b60_Class *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->ClearList();
    }
}

#include <xmmintrin.h>
struct FUN_00437c10
{
    FUN_00437c10();
    __m128 m_00;
    __m128 m_10;
};

struct CF845
{
    CF845(void* p);
    int unk;
};

struct TESObjectREFR
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
    virtual bool vfunc_0x100();
};


struct PickedObj
{
};

struct Arg1
{
};

struct ItemObj
{
};

struct Arg2Item
{
    ItemObj* pItem;
};

struct Arg2
{
};

struct TargetObj
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
    virtual void vfunc_0x3c(void* effectList, FUN_00437c10* t);
};

struct Arg3
{
};

struct FUN_00628df0_class
{
    void FUN_00628df0(Arg1* a1, Arg2* a2, Arg3* a3);
};

// For each a2 item with a string, calls a3's target vfunc_0x3c; if the a1 checks fail and the item type is 0x1e, passes its REFR to FUN_006295e0.
// @fnv 0x00628df0
void FUN_00628df0_class::FUN_00628df0(Arg1* a1, Arg2* apItems, Arg3* apTarget)
{
    FUN_00437c10 tmp;
    for (int i = 0; i < ((intptr_t)(reinterpret_cast<::Callees *>((apItems))->FUN_00726070())); ++i)
    {
        ItemObj* p38 = (ItemObj*)((void *)(::FUN_00460140((intptr_t)(((::Arg2Item *)&(reinterpret_cast<::FUN_00629ab0_shell *>((apItems))->FUN_00629ab0(i)))->pItem))));
        if (((const char *)(::FUN_00559450((int *)(p38)))))
        {
            TargetObj* pTarget = ((::TargetObj *)(reinterpret_cast<::LowProcess *>((apTarget))->GetPackageObjectType()));
            pTarget->vfunc_0x3c(((void *)(reinterpret_cast<::NonActorMagicTarget *>((p38))->GetActiveEffectList())), &tmp);
            char flag;
            if (!reinterpret_cast<::FUN_005609f0_shell *>((((::PickedObj *)(reinterpret_cast<::FUN_00628d10_cls *>((a1))->FUN_00628d10((::FUN_00628d10_cls *)(char *)(&flag), (::FUN_00628d10_cls *)(::FUN_00437c10 *)(&tmp))))))->FUN_005609f0() || !((int)(reinterpret_cast<::S00628c50_Box *>((a1))->FUN_00628c50((const ::S00628c50_Box *)(::FUN_00437c10 *)(&tmp)))))
            {
                CF845 filter(((void *)(::FUN_0043b540((char *)(p38)))));
                if (reinterpret_cast<::FUN_0043b4d0_shell *>(&(filter))->FUN_0043b4d0() == 0x1e)
                {
                    TESObjectREFR* refr = FUN_0062b4e0(p38);
                    if (refr && refr->vfunc_0x100())
                    {
                        TESObjectREFR* pRefr = refr;
                        reinterpret_cast<::Me *>((this))->FUN_006295e0((::Ref *)(pRefr));
                    }
                }
            }
        }
    }
}
