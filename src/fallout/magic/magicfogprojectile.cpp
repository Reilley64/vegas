
// src/fallout/magic/magicfogprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicfogprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/EffectItemListFind.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00444020_Class.h"
#include "fnv/decl/FUN_00484d20_Class.h"
#include "fnv/decl/FUN_00484d40_Host.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004d7d50_StandIn.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_00621b20_Class.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00819a50_shell.h"
#include "fnv/decl/FUN_00819a70_class.h"
#include "fnv/decl/FUN_0081c470_shell.h"
#include "fnv/decl/FUN_0081e830_shell.h"
#include "fnv/decl/FUN_0081e8c0_shell.h"
#include "fnv/decl/FUN_0081e980_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_00a59660_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00810ff0__Ths810.h"
#include "fnv/decl/fnv_0081ea40__MagicProjectile.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00932520__FUN_00932520_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0080f000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0107a000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_0081c4a0_cls.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/XRef.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_00819ca0__Actor.h"
#include "fnv/decl/xActor_2.h"
#include "fnv/symbols_00404000.h"
struct MagicFogProjectile
{
    void FUN_008196e0();
    void* DestroyIfFlagged(unsigned int);
};
struct RefH
{
};
struct FUN_0081a920_shell : public RefH
{
    bool FUN_0081a920();
};
// Returns true when the int at offset 0xb4 is not 1 and the object is not deleted.
// @fnv 0x0081a920
bool FUN_0081a920_shell::FUN_0081a920()
{
    return *(int*)((char*)this + 0xb4) != 1 && !reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80();
}

namespace fnv_0081ad00 {
struct TESSaveLoadGame
{
};
struct MagicFogProjectile
{
    unsigned short FUN_0081ad00(unsigned int flags);
};
// @fnv 0x0081ad00
unsigned short MagicFogProjectile::FUN_0081ad00(unsigned int flags)
{
    struct VirtualInterface
    {
        VirtualInterface* next;
    };
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_0081e830_shell *>(this)->GetSaveRecordSize(flags);
    isize += 4;
    isize += 4;
    isize += 4;
    isize += 4;
    isize += 4;
    if (*(int*)((char*)this + 0xb4) == 1)
        isize += 4;
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_0081ad00::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x71)
    {
        isize += 4;
        isize += 2;
        VirtualInterface* pNode = *(VirtualInterface**)((char*)this + 0xc8);
        while (pNode)
        {
            isize += 4;
            isize += 1;
            pNode = *(VirtualInterface**)((char*)pNode + 8);
        }
    }
    return isize;
}
}  // namespace fnv_0081ad00

namespace fnv_00818ba0 {
struct MagicFogProjectile
{
    unsigned char _pad[20];
    float _m14;
    bool IsAboveZero();
};
// Returns true when _m14 is greater than _gModifierZero.
// @fnv 0x00818ba0
bool MagicFogProjectile::IsAboveZero()
{
    return _m14 > ::_DAT_01012060;
}
}  // namespace fnv_00818ba0

namespace fnv_00819830 {
struct MagicFogProjectile
{
    char _pad[0xC8];
    struct VirtualInterface
    {
        char _pad2[8];
        VirtualInterface* next;
    }* pActiveTargetList;
    void DeleteAllNodes();
};
// @fnv 0x00819830
void MagicFogProjectile::DeleteAllNodes()
{
    VirtualInterface* pNode;
    while (pActiveTargetList)
    {
        pNode = pActiveTargetList;
        pActiveTargetList = pActiveTargetList->next;
        delete pNode;
    }
    pActiveTargetList = 0;
}
}  // namespace fnv_00819830

struct FUN_0081eb50_shell
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
    virtual void v49(int);
    char _pad[0x90];
    int m94;
    bool ClearIfMatches(int);
};
// If a equals m94, resets m94 to 0, calls v49(1), and returns true; otherwise returns false.
// @fnv 0x0081eb50
bool FUN_0081eb50_shell::ClearIfMatches(int aiValue)
{
    bool r = false;
    if (aiValue == m94)
    {
        m94 = 0;
        r = true;
        v49(1);
    }
    return r;
}

struct Setting
{
};
struct RTTI
{
};
struct Object
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void* AsNode();
};
struct Emitter
{
};
struct Controller
{
};
struct Particle : Object
{
};
struct Node : Object
{
    unsigned FUN_0043b480();
};
struct Effect
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    float sizeScale, speedScale;
    void ScaleEffect(Object*);
};
// Scales the effect's size and speed settings and applies the scaled values to each particle's emitter and controller, recursing into child nodes.
// @fnv 0x00819890
void Effect::ScaleEffect(Object* object)
{
    float fSpeedFactor;
    {
        float fSpeedFactor2;
        {
            float fSizeFactor = sizeScale * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1142))))));
            fSpeedFactor = speedScale * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1144))))));
            fSpeedFactor2 = speedScale * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1143))))));
            if (::FUN_0043b300((const ::NiRTTI *)(const ::RTTI *)(&(*reinterpret_cast<::RTTI *>(&::g_012024e0))), (::NiAVObject *)(object)))
            {
                Particle* particle = (Particle*)object;
                for (unsigned i = 0; i < reinterpret_cast<::FUN_004d7d50_StandIn *>((particle))->FUN_004d7d50(); ++i)
                {
                    Controller* controller;
                    {
                        Emitter* emitter;
                        {
                            Object* entry = ((::Object *)(reinterpret_cast<::Owner *>((particle))->GetByIndex(i)));
                            emitter = (Emitter*)((void *)(::FUN_00653270((const ::NiRTTI *)(const ::RTTI *)(&(*reinterpret_cast<::RTTI *>(&::g_01202550))), (::NiObject *)(entry))));
                            if (emitter)
                                reinterpret_cast<::FUN_00819a70_class *>((emitter))->FUN_00819a70(reinterpret_cast<::FUN_00759450_shell *>((emitter))->FUN_00759450() * fSizeFactor);
                            controller = (Controller*)((void *)(::FUN_00653270((const ::NiRTTI *)(const ::RTTI *)(&(*reinterpret_cast<::RTTI *>(&::g_01202540))), (::NiObject *)(entry))));
                            if (controller)
                            {
                                reinterpret_cast<::FUN_0098adb0_shell *>((controller))->FUN_0098adb0(reinterpret_cast<::FUN_00639aa0_shell *>((controller))->FUN_00639aa0() * fSizeFactor);
                                reinterpret_cast<::FUN_00819a50_shell *>((controller))->FUN_00819a50(reinterpret_cast<::BSMultiBoundSphere *>((controller))->GetRadius() * fSpeedFactor2);
                                reinterpret_cast<::FUN_00444020_Class *>((controller))->FUN_00444020(reinterpret_cast<::FUN_00792760_shell *>((controller))->FUN_00792760() * fSpeedFactor);
                            }
                        }
                    }
                }
            }
            else if (object && object->AsNode())
            {
                Node* node = (Node*)object;
                for (unsigned i = 0; i < node->FUN_0043b480(); ++i)
                {
                    Object* child = ((::Object *)(reinterpret_cast<::NiNode *>((node))->GetAt(i)));
                    ScaleEffect(child);
                }
            }
        }
    }
}

struct Form
{
};
struct FUN_0081aa80
{
    Form* form;
    unsigned char flags;
    FUN_0081aa80* next;
    FUN_0081aa80(Form*, unsigned char, FUN_0081aa80*);
};
struct SaveManager
{
};
struct Projectile
{
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
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
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
    virtual void Reset();
    int unk4;
    int unk8;
    int unkC;
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
    FUN_0081aa80* head;
    unsigned id;
    void LoadFromStream(int, int);
};
// Resets the projectile, reads several 4-byte fields and a form ID from the stream, then reads a list of form/flag records when the save version is at least 0x71.
// @fnv 0x0081afa0
void Projectile::LoadFromStream(int a, int b)
{
    reinterpret_cast<::fnv_00819830::MagicFogProjectile *>(this)->DeleteAllNodes();
    Reset();
    reinterpret_cast<::FUN_0081e980_shell *>(this)->FUN_0081e980(a, b);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&unkA8, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&unk88, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&unkAC, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&unkB4, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&unkB8, 4);
    if (unkB4 == 1)
    {
        unsigned formID;
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&formID, 4);
        ::__memcpy(&id, &formID, 4);
    }
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x71)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&unkB0, 4);
        unsigned short count;
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&count, 2);
        for (unsigned i = 0; i < count; ++i)
        {
            FUN_0081aa80* record;
            {
                Form* form;
                {
                    unsigned char flags;
                    reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40((unsigned int *)(void *)(&form), 4);
                    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&flags, 1);
                    record = new FUN_0081aa80(form, flags, head);
                    head = record;
                }
            }
        }
    }
}

struct FxPoint3
{
    float x, y, z;
};
struct FxMatrix3
{
    float m[9];
    FxMatrix3();
};
struct FxFixedString
{
    const char* m_kHandle;
    FxFixedString(const char* pcString);
    ~FxFixedString();
};
struct FxTransformTime
{
    int unk00, unk04, unk08;
    FxTransformTime(float fTime, int a2, int a3);
};

struct FxAVObject;
struct FxSequence
{
};
struct FxControllerManager
{
};
struct FxNode
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
    virtual FxAVObject* GetObjectByName(const FxFixedString& kName);

};

static const char s_szAreaEffect[] = "AreaEffect";
static const char s_szSpecialIdle[] = "SpecialIdle_Projectile";
extern const char g_szFogInitEnd[] = "";

struct FogProjectileInit
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

    virtual FxNode* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const FxPoint3& GetPos();

    char pad004[0xb8 - 4];
    float m_fScale;

    void InitProjectileEffect();
};

// @fnv 0x00819a90
void FogProjectileInit::InitProjectileEffect()
{
    FxNode* pkNode = Get3D();
    if (pkNode)
    {
        reinterpret_cast<::FUN_00440490_shell *>((pkNode))->FUN_00440490(m_fScale);
        reinterpret_cast<::FUN_00440460_S *>((pkNode))->FUN_00440460((const ::V3 *)&(GetPos()));
        FxPoint3 kAngleX = (*(const ::FxPoint3 *)(reinterpret_cast<::TESRecipe *>(this)->GetData()));
        FxMatrix3 kKRot;
        reinterpret_cast<::FUN_00a59660_cls *>(&(kKRot))->FUN_00a59660(kAngleX.z, kAngleX.x, kAngleX.y);
        reinterpret_cast<::FUN_0043fa80_s *>((pkNode))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(kKRot));
        ::fnv_00c4b500::FUN_00c4b500((::fnv_00c4b500::Node *)(pkNode));
        FxAVObject* pkArea_2 = pkNode->GetObjectByName(FxFixedString(s_szAreaEffect));
        if (pkArea_2)
            reinterpret_cast<::Effect *>(this)->ScaleEffect((::Object *)(pkArea_2));
        FxControllerManager* pkManagerTmp = ((::FxControllerManager *)(::FUN_00653270((const ::NiRTTI *)((*reinterpret_cast<char (*)[]>(&::g_011f36ac))), (::NiObject *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(pkNode))))))));
        if (pkManagerTmp)
        {
            FxSequence* pkSeqCur = ((::FxSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkManagerTmp))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::FxFixedString &)(FxFixedString(s_szSpecialIdle)))));
            if (pkSeqCur)
            {
                reinterpret_cast<::NiControllerManager *>((pkManagerTmp))->DeactivateAllSequences(0.0f);
                reinterpret_cast<::NiControllerManager *>((pkManagerTmp))->ActivateControllerSequence((::NiControllerSequence *)(pkSeqCur), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::TaskQueueInterface *>((pkManagerTmp))->QueueReferenceStateTask(1);
                reinterpret_cast<::FUN_0098adb0_shell *>((pkSeqCur))->FUN_0098adb0(-g_fInfinity_0107ad40);
                FxTransformTime kTimeY(::fnv_00563f30::DAT_011c3c08 - 0.1f, 1, 0);
                reinterpret_cast<::FUN_00a59c60_cls *>((pkNode))->FUN_00a59c60((std::intptr_t)(&kTimeY));
            }
        }
    }
}

struct ItemA
{
};
struct ItemB
{
};
struct ItemC
{
};
struct Node2
{
    ItemA* m0;
    void* m4;
    Node2* next;
};
struct SaveMgrExt
{
};

class FUN_0081ade0_cls
{
  public:
    void SaveToStream(int a1);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84;
    int m88;
    int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int unkBC, unkC0, unkC4;
    Node2* m_c8;
    ItemC* m_cc;
};

// @fnv 0x0081ade0
void FUN_0081ade0_cls::SaveToStream(int a1)
{
    float f;
    unsigned short* out;
    reinterpret_cast<::FUN_0081e8c0_shell *>(this)->FUN_0081e8c0(a1);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&m_a8, 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&m88, 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&m_ac, 4);
    reinterpret_cast<::FUN_008579b0_shell *>((((SaveMgrExt*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&m_b4, 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&m_b8, 4);
    if (m_b4 == 1)
    {
        f = 0.0f;
        if (m_cc != 0)
        {
            f = reinterpret_cast<::FUN_00621b00_shell *>((m_cc))->FUN_00621b00();
        }
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&f, 4);
    }
    if ((int)reinterpret_cast<::FUN_008df040_shell *>((((SaveMgrExt*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 0x71)
    {
        Node2* cur;
        unsigned short cnt;
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&m_b0, 4);
        cnt = 0;
        out = ((unsigned short *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveMgrExt*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&cnt, 2);
        cur = m_c8;
        while (cur != 0)
        {
            int tmp = 0;
            if (cur->m0 != 0)
            {
                tmp = reinterpret_cast<::FUN_0084e3a0_Class *>((cur->m0))->FUN_0084e3a0();
            }
            reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((int)(&tmp), 4);
            unsigned char flag = 0;
            if (reinterpret_cast<::EffectSetting *>(this)->GetArchetype() != 0 && cur->m4 != 0)
            {
                flag = reinterpret_cast<::EffectItemListFind *>((((ItemB*)(reinterpret_cast<::EffectSetting *>(this)->GetArchetype() + 0xc))))->FindEffectItemIndex({});
            }
            reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flag, 1);
            cnt++;
            cur = cur->next;
        }
        *out = cnt;
    }
}

class TESForm
{
  public:
    virtual void v000();
};
class TESObjectREFR : public TESForm
{
  public:
};

struct FogSoundHandle
{
    int unk00, unk04, unk08;
    ~FogSoundHandle();
    FogSoundHandle& operator=(const FogSoundHandle& kOther);
};

struct FogSoundForm
{
};
struct FogBaseForm
{
};

struct FogLight
{
    int unk00[7];
    FogLight(unsigned int auiFormId, void* pkNode);
};

struct FogProcess
{
};

struct FogRefNode
{
    TESForm* m_pkForm;
    int m_iValue;
    FogRefNode* m_pkNext;
};

struct FogIndexList
{
};
struct FogFile
{
    int unk00, unk04, unk08;
    FogIndexList kList;
};

struct FogSaveManager
{
};

struct FogProjectileLoad
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

    virtual void* Get3D();

    char pad004[0xac - 4];
    float m_fBoundRadius;
    char pad0b0[0xb4 - 0xb0];
    int unkb4;
    char pad0b8[0xbc - 0xb8];
    FogSoundHandle m_kSound;
    FogRefNode* m_pkRefs;
    FogLight* m_pkLight;

    FogSoundHandle PlaySoundByFormID(unsigned int auiFormId, int a2, int a3, int a4);
    void LoadProjectile(int a1, int a2);
};

// Runs the projectile load steps, rebuilds the sound handle and light, and remaps reference forms and indices when the save version is at least 0x71.
// @fnv 0x0081b180
void FogProjectileLoad::LoadProjectile(int a1, int a2)
{
    reinterpret_cast<::fnv_0081ea40::MagicProjectile *>(this)->ResolveMagicReferences(a1, a2);
    reinterpret_cast<::FogProjectileInit *>(this)->InitProjectileEffect();
    reinterpret_cast<::CellView *>((((::FogProcess *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(void *)(this), 0);
    if (unkb4 != 1 && ((::FogSoundForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::FogBaseForm *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
    {
        unsigned int uiProjectileSoundFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::FogSoundForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::FogBaseForm *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_kSound))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(m_kSound))->Release();
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::FogSoundHandle &)(m_kSound))->operator=((const ::SoundPlaybackHandle &)((const ::FogSoundHandle &)(PlaySoundByFormID(uiProjectileSoundFormID, 1, 0x40000102, 1))));
    }
    float fFadeAmount;
    ::__memcpy(&fFadeAmount, &m_pkLight, 4);
    m_pkLight = 0;
    if (Get3D() && ((::FogSoundForm *)(reinterpret_cast<::FUN_004fd380_shell *>((((::FogBaseForm *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_004fd380())))
    {
        m_pkLight = new FogLight(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::FogSoundForm *)(reinterpret_cast<::FUN_004fd380_shell *>((((::FogBaseForm *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_004fd380()))))->FUN_0084e3a0())), Get3D());
        if (m_pkLight)
        {
            reinterpret_cast<::FUN_0081c470_shell *>((m_pkLight))->FUN_0081c470(0, m_fBoundRadius);
            reinterpret_cast<::FUN_00621b20_Class *>((m_pkLight))->FUN_00621b20(fFadeAmount);
        }
    }
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::FogSaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x71)
    {
        FogRefNode* pkNode = m_pkRefs;
        while (pkNode)
        {
            unsigned int uiFormID_2 = (unsigned int)pkNode->m_pkForm;
            unsigned char ucIndexZ = (unsigned char)pkNode->m_iValue;
            if (uiFormID_2)
                pkNode->m_pkForm = dynamic_cast<TESObjectREFR*>(FUN_004839c0(uiFormID_2));
            if (((::FogFile *)(reinterpret_cast<::EffectSetting *>(this)->GetArchetype())))
                pkNode->m_iValue = ((int)(reinterpret_cast<::HX *>(&(((::FogFile *)(reinterpret_cast<::EffectSetting *>(this)->GetArchetype()))->kList))->FUN_00406ee0(ucIndexZ)));
            pkNode = pkNode->m_pkNext;
        }
    }
}

void __cdecl FUN_0080fc90(float);

struct FUN_0080fcc0
{
    ~FUN_0080fcc0();
};

struct FUN_00483710
{
    int unk00, unk04, unk08, unk0C;
    ~FUN_00483710();
};

struct MagicFogObject8196
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
    virtual unsigned int v11();
};

struct FUN_0081de70
{
    virtual ~FUN_0081de70();
    int unk04, unk08, unk0C, unk10, unk14;
};

struct MagicFogIface8196
{
    virtual void v00();
};

struct FUN_008196e0 : public FUN_0081de70, public MagicFogIface8196
{
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8;
    FUN_00483710 m_kSound;
    FUN_0080fcc0* m_pkCc;
    virtual ~FUN_008196e0();
};
// Calls FUN_008196e0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00819330
void* MagicFogProjectile::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_008196e0 *>(this)->FUN_008196e0::~FUN_008196e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x008196e0
FUN_008196e0::~FUN_008196e0()
{
    unsigned int uiValue = ((void *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) ? ((MagicFogObject8196*)((void *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())))->v11() : 0;
    if (uiValue != (*reinterpret_cast<unsigned int *>(&::_g_thePlayer)))
        FUN_0080fc90(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::g_011d15f8)))))));
    reinterpret_cast<::fnv_00819830::MagicFogProjectile *>(this)->DeleteAllNodes();
    if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_kSound))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(m_kSound))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(m_kSound))->Release();
    }
    if (m_pkCc)
        delete m_pkCc;
    m_pkCc = 0;
}

struct FogColor
{
    unsigned int m_uiColor;
    FogColor();
};

struct FogColorSource
{
    unsigned int m_uiCurrentValue;
    FogColorSource();
};
struct FogColorHolder
{
    FogColorSource FUN_0043b4f0();
};
struct FogRace
{
};

class FogReference3DView
{
  public:
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

    virtual void* Get3D();
};
class Actor : public TESObjectREFR
{
  public:
    FogColorSource FUN_00931ed0();
};

struct FogCasterSrc
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
    virtual TESObjectREFR* GetRef();
};

struct FogShader
{
    FogColor FUN_0070c440();
};

struct SettingStandIn
{
};

struct FogProjectileImpl
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

    virtual void* Get3D();

    void FUN_0081b430(int a1, int a2);
};

// @fnv 0x0081b430
void FogProjectileImpl::FUN_0081b430(int a1, int a2)
{
    reinterpret_cast<::fnv_00932520::FUN_00932520_shell *>(this)->UpdateFlags(a1, a2);
    FogShader* pkShaderZ = ((::FogShader *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (pkShaderZ)
    {
        int iColor;
        if (((::FogCasterSrc *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) && ((::FogCasterSrc *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->GetRef())
        {
            TESObjectREFR* pkRef = ((::FogCasterSrc *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->GetRef();
            Actor* pkActor = dynamic_cast<Actor*>(pkRef);
            if (pkActor)
            {
                iColor = ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::FogColorSource &)(pkActor->FUN_00931ed0()))->FUN_004a3a20()));
            }
            else
            {
                FogRace* pkRaceA = ((::FogRace *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(void *)(reinterpret_cast<FogReference3DView*>(pkRef)->Get3D()))));
                FogColorHolder* pkHolderPtr = pkRaceA ? ((::FogColorHolder *)(::fnv_006fa820::FUN_006fa820((const char *)(pkRaceA)))) : 0;
                iColor = pkHolderPtr ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::FogColorSource &)(pkHolderPtr->FUN_0043b4f0()))->FUN_004a3a20())) : ((int)(::FUN_005dbe10()));
            }
        }
        else
        {
            FogRace* pkRace2 = ((::FogRace *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(void *)(Get3D()))));
            FogColorHolder* pkHolder2 = pkRace2 ? ((::FogColorHolder *)(::fnv_006fa820::FUN_006fa820((const char *)(pkRace2)))) : 0;
            iColor = pkHolder2 ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::FogColorSource &)(pkHolder2->FUN_0043b4f0()))->FUN_004a3a20())) : ((int)(::FUN_005dbe10()));
        }
        FogColor kColor = pkShaderZ->FUN_0070c440();
        reinterpret_cast<::FUN_004a39f0_shell *>(&(kColor))->FUN_004a39f0(7);
        reinterpret_cast<::FUN_0059ce80_shell *>(&(kColor))->FUN_0059ce80(iColor);
        reinterpret_cast<::fnv_00810ff0::Ths810 *>((pkShaderZ))->FUN_00810ff0((*(int *)&(const ::FogColor &)(kColor)));
    }
    TESObjectREFR* _pkCaster = ((::FogCasterSrc *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) ? ((::FogCasterSrc *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->GetRef() : 0;
    if (_pkCaster != (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
        FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingStandIn *>(&::g_011d15f8)))))));
}

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
};
extern xFltSetting xg_11d1c28;
struct xItem
{
};
struct xRadius
{
};
struct xSndForm
{
};
struct xEffect
{
};
struct xCtl
{
};
struct xCell
{
};
struct xOwner
{
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(int, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
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
    virtual void* FUN_2c();
};

struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    float m_a8;
    float m_ac;
    float m_b0;
    int m_b4;
    float m_b8;
    xSound m_bc;
    int m_c8;
    xOwner* m_cc;
    xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner);
    xSound PlaySoundByFormID(void*, int, unsigned int, int);
};
// @fnv 0x00819360
xProj::xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner) : xBase(a, b, c, d, kP1, kP2)
{
    m_ac = ::FUN_00404010((float)reinterpret_cast<::FUN_004044d0_shell *>((((::xItem *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_004044d0(), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1147)))))));
    m_b0 = ::FUN_00404010((float)reinterpret_cast<::FUN_00404420_shell *>((((::xItem *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_00404420(), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d15c8)))))));
    m_88 = reinterpret_cast<::PathingRequest *>((((xRadius*)((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))->GetCenterRadius() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1140))))));
    m_b4 = 0;
    m_a8 = 0.0f;
    m_b8 = 1.0f;
    m_cc = 0;
    m_c8 = 0;
    if (apE)
        reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((int)(apE));
    else
        reinterpret_cast<::XRef *>(this)->FUN_0081e570(0);
    reinterpret_cast<::FogProjectileInit *>(this)->InitProjectileEffect();
    reinterpret_cast<::fnv_00819ca0::Actor *>(this)->FUN_00819ca0();
    xVec4 V(-::g_fInfinity_0107ad40, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((((::xCtl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_0080fb00((int)(&V));
    reinterpret_cast<::CellView *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(void *)(this), false);
    if (((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
    {
        void* NAME = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_bc))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(m_bc))->Release();
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::xSound &)(m_bc))->operator=((const ::SoundPlaybackHandle &)((const ::xSound &)(PlaySoundByFormID(NAME, 1, 0x40000102, 1))));
        reinterpret_cast<::FUN_00ad89e0_shell *>(&(m_bc))->FUN_00ad89e0(1.0f);
    }
    if (apOwner)
    {
        reinterpret_cast<::FUN_0081c4a0_cls *>((apOwner))->FUN_0081c4a0((::VTableTarget116 *)(void *)(this));
        m_cc = apOwner;
        reinterpret_cast<::FUN_0081c470_shell *>((m_cc))->FUN_0081c470(false, m_ac);
    }
    reinterpret_cast<::xActor *>(this)->FUN_0081eba0();
    void* SHOOTER = ((::xActorV *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) ? ((::xActorV *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->FUN_2c() : 0;
    if (SHOOTER != (*reinterpret_cast<void * *>(&::_g_thePlayer)))
        ::FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d15f8)))))));
}
#include "generated/data/fallout/magic/magicfogprojectile.inc"
