
// src/fallout_shared/extradatalist_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BSExtraData, TESPackage). The skeleton of src/fallout_shared/extradatalist.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include <new>
#include "fnv/decl/ActiveEffect.h"
#include "fnv/decl/ActorD.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/Actor_8b6ae0.h"
#include "fnv/decl/BGSChangeFlagsState.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSSimpleArrayActor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/EntryCollection.h"
#include "fnv/decl/ExtraSecuritronFace.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0040fe80_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_004182b0_shell.h"
#include "fnv/decl/FUN_00418460_shell.h"
#include "fnv/decl/FUN_0041aa20_shell.h"
#include "fnv/decl/FUN_0041ab70_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00421910_shell.h"
#include "fnv/decl/FUN_00421d20_shell.h"
#include "fnv/decl/FUN_00422670_Cls.h"
#include "fnv/decl/FUN_00428130_Class.h"
#include "fnv/decl/FUN_0042cde0_shell.h"
#include "fnv/decl/FUN_0042ce90_class.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438280_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047cdb0_shell.h"
#include "fnv/decl/FUN_0047e340_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004d1610_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0083fbe0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008adc50_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FakeGame.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/Holder0042f780.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/Inv4d1440.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESLeveledList.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0086cf00.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0041a960__FUN_0041a960_shell.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00438260__FUN_00438260.h"
#include "fnv/decl/fnv_0043aaa0__FUN_0043aaa0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004d1960__InvInventory.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005a9f20__FUN_005a9f20_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_009724e0__FUN_009724e0_shell.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00475000.h"
#include "fnv/symbols_00477000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00806000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_01014000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "extradatalist_packet_rtti_extradatalist.h"
#include "ExtraDataList.h"
#include "ExtraContainerChanges_rtti_extradatalist.h"
#include "InventoryChanges.h"
#include "game_constants.h"

struct P3Q
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
    virtual bool IsX();
};
struct MTQ
{
    virtual void m0();
    virtual void m1();
    virtual int GetCaster();
};
class NonActorMagicTarget : public BSExtraData
{
  public:
    MTQ kMT;
};
struct ResQ
{
};
struct OwnQ
{
    void FUN_00426720(unsigned int uiFlags, int a2, P3Q* p3);
};
// @fnv 0x00426720
void OwnQ::FUN_00426720(unsigned int uiFlags, int a2, P3Q* p3)
{
    bool bSkip = false;
    if (p3 && p3->IsX())
        bSkip = true;
    if (!bSkip)
    {
        if (uiFlags & 0x20000)
        {
            ResQ* pRes = ((::ResQ *)(reinterpret_cast<::FUN_00418460_shell *>(this)->FUN_00418460()));
            reinterpret_cast<::TESForm *>((pRes))->ClearData();
        }
        if (uiFlags & 0)
        {
            NonActorMagicTarget* pTarget = dynamic_cast<NonActorMagicTarget*>(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x33));
            if (pTarget)
                ::FUN_00806130((::ActiveEffectListBridge *)(pTarget->kMT.GetCaster()), (::ActorBridge *)(0));
        }
    }
}

class type_info;
// ExtraDataList::LoadGame (FUN_00428150)
class TESGlobal : public TESForm
{
};
class ScriptEventList;
class Script : public TESForm
{
  public:
};
class TESAmmo : public TESForm
{
};
class BGSEncounterZone : public TESForm
{
};
class TESKey : public TESForm
{
};
class TESFaction : public TESForm
{
};
class TESTopic : public TESForm
{
};
class TESTopicInfo : public TESForm
{
};
class TESBoundObject : public TESForm
{
};
class ActorBaseData
{
  public:
      // 0x47cdb0
};
class TESActorBase : public TESForm
{
  public:
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ActorBaseData kBaseData;
};
class MagicItem
{
  public:
    virtual ~MagicItem();
public:
    static ::MagicItem *GetMagicItemByID(unsigned int);
};
class AlchemyItem : public MagicItem
{
};
struct ExtraSpecialRenderFlags
{
  public:
    virtual ~ExtraSpecialRenderFlags();
                // 0x84e3a0
      // 0x41fd00
};
extern "C" void* __cdecl __RTDynamicCast(void* inptr, long vfdelta, void* srcType, void* targetType, int isReference);
struct LoadFlags
{
    unsigned int uiFlags;
    LoadFlags(unsigned int flags);  // 0x8c71b0
      // 0x4280f0
};
class LoadBuffer
{
  public:
    virtual unsigned char GetVersion();
    virtual void v01();
    virtual class LoadRef* GetRef();
    virtual class LoadRef* GetActor();
      // 0x864980
                    // 0x8648e0
                      // 0x8648a0
                     // 0x864a60
                   // 0x8649a0
    LoadFlags GetFlags();                     // 0x428110
               // 0x428130
    LoadFlags GetFlags2();                    // 0x42ce30
              // 0x86cf00
                  // 0x42ce90
            // 0x42ce50
                     // 0x7037c0
};
class RefSub
{
  public:
      // 0x41aeb0
};
class RefProc
{
  public:
      // 0x4d1440
      // 0x4d1610
      // 0x4d1960
       // 0x42cde0
};
class LoadRef
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
    virtual const char* GetName();
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
    virtual void v115(int a, int b);
    virtual int v116();
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
    virtual bool v134();
            // 0x84e3a0
                     // 0x8b6820
                     // 0x8b6ae0
                    // 0x5d43c0
                     // 0x8adc50
              // 0x4181e0
      // 0x575690
};
class ObjData30
{
  public:
      // 0x47e340
};
class DelObj
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~DelObj();
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void LoadGame(LoadBuffer* buf);
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
    ObjData30 kData30;
      // 0x84e3a0
};
class DelObj20C : public DelObj
{
  public:
    DelObj20C();
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
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
};
class DelObj160 : public DelObj
{
  public:
    DelObj160();
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
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
};
class LoadObj70
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void LoadGame(LoadBuffer* buf);
};
class LoadForm
{
  public:
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void LoadGame(LoadBuffer* buf);
      // 0x84e3a0
};
class ScriptEventList
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ScriptEventList();               // 0x5a8b80
    ~ScriptEventList();              // 0x5a8bc0
    void LoadGame(LoadBuffer* buf);  // 0x5a9f20
};
class FormList
{
  public:
    void AddHead(void* const& item);  // 0x5ae3d0
    void AddHead(struct XPackEntry* const& item);
    void AddHead(struct XTopicEntry* const& item);
    void AddHead(struct XEntry24* const& item);
                  // 0x6815c0
    bool IsEmpty();                // 0x8256d0
      // 0x905330
               // 0x726070
    void RemoveHead();             // 0x63f7b0
};
class FormArray
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
       // 0x6f2290
      // 0x42f5f0
    void** GetAt(unsigned int i);                // 0x6a7ad0
                         // 0x44ddc0
            // 0x9a4320
};
class AnimItem
{
  public:
    void LoadGame(LoadBuffer* buf);  // 0x9a5ff0
};
class IdList
{
  public:
    void Add(void* item);  // 0x42f780
               // 0x559450
};
class ExtraData110 : public BSExtraData
{
  public:
      // 0x4f1540
      // 0x44ddc0
};
class XSub2C
{
  public:
      // 0x42e680
};
class XObj20
{
  public:
    XObj20();  // 0x43a160
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    void LoadGame(LoadBuffer* buf);  // 0x43aaa0
};
class XScriptState
{
  public:
    void LoadGame(LoadBuffer* buf);  // 0x83fbe0
};
struct XKeyData
{
    unsigned char b00;
    TESForm* pKey;
    unsigned char b08;
    unsigned int u0C;
    unsigned int u10;
};
struct XPackEntry
{
    void* pForm;
    unsigned char b04;
};
struct XTopicEntry
{
    TESForm* pInfo;
    unsigned int u04;
    unsigned int u08;
    XTopicEntry();  // 0x42cc10
};
struct XListEntry
{
    unsigned char b00;
    unsigned char b01;
    unsigned char b02;
    unsigned char b03;
    FormArray kItems;
    XListEntry();  // 0x42c470
};
struct XEntry24
{
    unsigned int f00[3];
    unsigned int u0C;
    unsigned int f10[3];
    unsigned int u1C;
    unsigned char b20;
    XEntry24();  // 0x437c10
};
class CrimeList
{
  public:
      // 0x9724e0
};
class DataHandler
{
  public:
      // 0x84aa30
                                     // 0x42ce10
};
class ProcMgr
{
  public:
      // 0x469860
};
                 // 0x4839c0
                    // 0x845cc0
              // 0x477bc0
          // 0x477ce0
     // 0x4759a0
                                   // 0x42ce00
                    // 0x670b90
                      // 0x40a250
                               // 0x66e330
LoadObj70* __cdecl CreateObj70(int c);                            // 0x8c6ca0
             // 0x806a90
  // 0x47d130
                        // 0x4bf220
class X24 : public ExtraData110
{
  public:
    X24();
    unsigned short u0C;
};
class X25 : public ExtraData110
{
  public:
    X25();
    unsigned int u0C;
};
class X8D : public ExtraData110
{
  public:
    X8D();
    unsigned char b0C;
};
class X30 : public ExtraData110
{
  public:
    X30();
    unsigned int u0C;
};
class X21 : public ExtraData110
{
  public:
    X21();
    TESForm* pForm;
};
class X23 : public ExtraData110
{
  public:
    X23();
    unsigned int u0C;
};
class X22 : public ExtraData110
{
  public:
    X22();
    TESForm* pForm;
};
class X1C : public ExtraData110
{
  public:
    X1C();
    unsigned int u0C;
};
class X49 : public ExtraData110
{
  public:
    X49();
    TESForm* pForm;
};
class X56 : public ExtraData110
{
  public:
    X56();
    float f0C;
};
class X0D : public ExtraData110
{
  public:
    X0D();
    Script* pScript;
    ScriptEventList* pEventList;
};
class X5B : public ExtraData110
{
  public:
    X5B();
    TESForm* pItem;
    TESForm* pForm;
};
class X19 : public ExtraData110
{
  public:
    X19();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
};
class X18 : public ExtraData110
{
  public:
    X18();
    TESForm* pForm;
    float pos[3];
    unsigned int u1C;
};
class X1B : public ExtraData110
{
  public:
    X1B();
    FormList* pList;
};
class X1D : public ExtraData110
{
  public:
    X1D();
    FormList* pList;
};
class X6C : public ExtraData110
{
  public:
    X6C();
    unsigned int u0C;
};
class X73 : public ExtraData110
{
  public:
    X73();
    FormList* pList;
};
class X75 : public ExtraData110
{
  public:
    X75();
    TESForm* pInfo;
    TESForm* pTopic;
    unsigned int u14;
    unsigned char b18;
};
class X4A : public ExtraData110
{
  public:
    X4A();
    unsigned char b0C;
};
class X35 : public ExtraData110
{
  public:
    X35();
    FormList* pList;
};
class X45 : public ExtraData110
{
  public:
    X45();
    FormArray kArray;
};
class X5E : public ExtraData110
{
  public:
    X5E();
    FormList* pList;
};
class X70 : public ExtraData110
{
  public:
    X70();
    LoadObj70* pObj;
};
class X2C : public ExtraData110
{
  public:
    XSub2C* pSub;
};
class X7C : public ExtraData110
{
  public:
    X7C();
    FormArray kArray;
};
class X74 : public ExtraData110
{
  public:
    X74();
    TESForm* m_pEncounterZone;
};
class X5C : public ExtraData110
{
  public:
    X5C();
    unsigned int u0C;
};
class X5D : public ExtraData110
{
  public:
    X5D();
    unsigned int u0C;
};
class X6E : public ExtraData110
{
  public:
    X6E();
    TESForm* pAmmo;
    unsigned int u10;
};
class X1E : public ExtraData110
{
  public:
    X1E();
    unsigned int u0C;
};
class X1A : public ExtraData110
{
  public:
    X1A();
    LoadForm* pForm;
};
class X26 : public ExtraData110
{
  public:
    X26();
    unsigned char b0C;
};
class X27 : public ExtraData110
{
  public:
    X27();
    unsigned int u0C;
};
class X28 : public ExtraData110
{
  public:
    X28();
    unsigned int u0C;
};
class X2A : public ExtraData110
{
  public:
    X2A();
    XKeyData* pData;
};
class X2F : public ExtraData110
{
  public:
    X2F();
    unsigned int u0C;
    unsigned char b10;
};
class X32 : public ExtraData110
{
  public:
    X32();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1C;
    unsigned int u20;
};
class X33 : public ExtraData110
{
  public:
    X33();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1C;
    unsigned int u20;
    unsigned int u24;
};
class X39 : public ExtraData110
{
  public:
    X39();
    unsigned int u0C;
};
class X3F : public ExtraData110
{
  public:
    X3F();
    void* pItem;
};
class X46 : public ExtraData110
{
  public:
    X46();
    unsigned int u0C;
};
class X4D : public ExtraData110
{
  public:
    X4D();
    XScriptState* pState;
};
class X4E : public ExtraData110
{
  public:
    X4E();
    unsigned char b0C;
};
class X5F : public ExtraData110
{
  public:
    X5F();
    unsigned short u0C;
    unsigned short pad0E;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned char b1C;
    FormArray kArray;
      // 0x430660
};
class X55 : public ExtraData110
{
  public:
    X55();
    unsigned int u0C;
};
class X60 : public ExtraData110
{
  public:
    X60();
    IdList kList;
};
class X2B : public ExtraData110
{
  public:
    X2B();
    XObj20* pObj;
};
class X3C : public ExtraData110
{
  public:
    X3C();
    unsigned int u0C;
};
class X2E : public ExtraData110
{
  public:
    X2E();
    TESActorBase* pBase;
    TESActorBase* pBase2;
};
class X54 : public ExtraData110
{
  public:
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
};
class X50 : public ExtraData110
{
  public:
    X50();
    unsigned char b0C;
    unsigned char b0D;
};
class X89 : public ExtraData110
{
  public:
    X89();
    unsigned int u0C;
};
class X8B : public ExtraData110
{
  public:
    X8B();
    unsigned int u0C;
    unsigned int u10[3];
    unsigned int u1C;
    FormList kList;
    unsigned int u24;
};
class X8F : public ExtraData110
{
  public:
    X8F();
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
      // 0x438260
      // 0x438280
};
class X92 : public ExtraData110
{
  public:
    X92();
    unsigned int u0C;
    unsigned int u10;
};
class ExtraDataLoader : public ExtraDataList
{
  public:
        // 0x410220
         // 0x40ff60
             // 0x410140
      // 0x410020
                       // 0x41aa20
                               // 0x41ab70
                               // 0x41a960
                                     // 0x422670
    void FUN_00428150(LoadBuffer* buf);
};
// @fnv 0x00428150
void ExtraDataLoader::FUN_00428150(LoadBuffer* buf)
{
    LoadRef* pRef = buf->GetRef();
    LoadRef* actor = buf->GetActor();
    {
        bool abHas[0x93];
        ::FUN_00403d30(abHas, 0, 0x93);
        ExtraData110* iter6 = (ExtraData110*)pHead;
        while (iter6 != 0)
        {
            unsigned char cIterType = ((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((iter6))->IsPatrolling()));
            if ((*reinterpret_cast<unsigned int (*)[]>(&::fnv_0042dae0::DAT_01183d30))[cIterType] != 0 && reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::LoadFlags &)(buf->GetFlags()))->FUN_004280f0((*reinterpret_cast<unsigned int (*)[]>(&::fnv_0042dae0::DAT_01183d30))[cIterType]))
            {
                abHas[cIterType] = 1;
            }
            iter6 = ((::ExtraData110 *)(reinterpret_cast<::Twin_0044ddc0 *>((iter6))->GetName()));
        }
        unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            unsigned char cType = 0;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&cType), 1);
            switch (cType)
            {
            case 0x16:
                reinterpret_cast<::FUN_0041aa20_shell *>(this)->SetWornState(1, 0);
                break;
            case 0x3e:
                reinterpret_cast<::FUN_0041ab70_shell *>(this)->FUN_0041ab70(1);
                break;
            case 0x24: {
                X24* p24 = (X24*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X24)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p24->u0C), 2);
                break;
            }
            case 0x25: {
                X25* p25 = (X25*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X25)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p25->u0C), 4);
                break;
            }
            case 0x8d: {
                X8D* p8D = (X8D*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X8D)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p8D->b0C), 1);
                break;
            }
            case 0x30: {
                X30* p30 = (X30*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X30)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p30->u0C), 4);
                break;
            }
            case 0x21: {
                X21* p21 = (X21*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X21)))));
                p21->pForm = ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0());
                break;
            }
            case 0x23: {
                X23* p23 = (X23*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X23)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p23->u0C), 4);
                break;
            }
            case 0x22: {
                X22* p22 = (X22*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X22)))));
                p22->pForm = dynamic_cast<TESGlobal*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                break;
            }
            case 0x1c: {
                X1C* p1C = (X1C*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X1C)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p1C->u0C));
                break;
            }
            case 0x49: {
                X49* p49 = (X49*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X49)))));
                p49->pForm = ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0());
                break;
            }
            case 0x56: {
                X56* p56 = (X56*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X56)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p56->f0C), 4);
                void* value = ((void *)(::GetDestructionStageSelfDamage((::TESObjectREFR *)(pRef), p56->f0C)));
                if (value != 0)
                {
                    ::fnv_00477ce0::SetOrRemoveMapEntry((unsigned int)(pRef), (unsigned int)(value));
                }
                break;
            }
            case 0x0d: {
                X0D* p0D = (X0D*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X0D)))));
                p0D->pScript = dynamic_cast<Script*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                if (p0D->pEventList == 0)
                {
                    p0D->pEventList = p0D->pScript ? ((::ScriptEventList *)(reinterpret_cast<::FUN_005abf60_shell *>((p0D->pScript))->FUN_005abf60())) : 0;
                }
                if (pRef == 0)
                {
                    reinterpret_cast<::TESRecipe *>((buf))->SetRequiredSkill((::ActorValue::Index)(((void *)(::ExtraSecuritronFace::GetPersonality()))));
                }
                if (p0D->pEventList == 0)
                {
                    ScriptEventList kTemp;
                    reinterpret_cast<::fnv_005a9f20::FUN_005a9f20_shell *>(&(kTemp))->FUN_005a9f20((::fnv_005a9f20::BGSLoadFormBuffer *)(buf));
                }
                else
                {
                    reinterpret_cast<::fnv_005a9f20::FUN_005a9f20_shell *>((p0D->pEventList))->FUN_005a9f20((::fnv_005a9f20::BGSLoadFormBuffer *)(buf));
                }
                if (pRef == 0)
                {
                    reinterpret_cast<::TESRecipe *>((buf))->SetRequiredSkill((::ActorValue::Index)(0));
                }
                break;
            }
            case 0x5b: {
                X5B* p5B = (X5B*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X5B)))));
                p5B->pForm = ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0());
                int iValue = -1;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iValue), 4);
                if (p5B->pForm != 0)
                {
                    p5B->pItem = ((::TESForm *)(::GetElementValue(p5B->pForm, iValue)));
                }
                if (p5B->pForm != 0 && p5B->pItem != 0)
                {
                    if (pRef != 0)
                    {
                        pRef->v115(0, 1);
                    }
                }
                else
                {
                    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x5b);
                }
                break;
            }
            case 0x19: {
                X19* p19 = (X19*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X19)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p19->u0C));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p19->u14));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p19->u10), 4);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p19->b18), 1);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p19->b19), 1);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p19->b1A), 1);
                break;
            }
            case 0x18: {
                X18* p18 = (X18*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X18)))));
                p18->pForm = ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0());
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(p18->pos), 0xc);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p18->u1C), 4);
                break;
            }
            case 0x1b: {
                X1B* extra_ = (X1B*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X1B)))));
                unsigned int uiPkgCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                for (unsigned int j = 0; j < uiPkgCount; j++)
                {
                    XPackEntry* pEntry = new XPackEntry;
                    pEntry->pForm = dynamic_cast<TESPackage*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pEntry->b04), 1);
                    extra_->pList->AddHead(pEntry);
                }
                break;
            }
            case 0x1d: {
                X1D* p1D = (X1D*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X1D)))));
                unsigned int uiIdCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                for (unsigned int j = 0; j < uiIdCount; j++)
                {
                    void* pId = 0;
                    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&pId));
                    p1D->pList->AddHead(pId);
                }
                break;
            }
            case 0x6c: {
                X6C* p6C = (X6C*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X6C)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p6C->u0C));
                break;
            }
            case 0x73: {
                X73* extra_ = (X73*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X73)))));
                unsigned int uiTopicCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                for (unsigned int j = 0; j < uiTopicCount; j++)
                {
                    XTopicEntry* pTopic = new XTopicEntry;
                    pTopic->pInfo = dynamic_cast<TESTopicInfo*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pTopic->u04), 4);
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pTopic->u08), 4);
                    extra_->pList->AddHead(pTopic);
                }
                break;
            }
            case 0x75: {
                X75* p75 = (X75*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X75)))));
                p75->pTopic = dynamic_cast<TESTopic*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                p75->pInfo = dynamic_cast<TESTopicInfo*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p75->b18), 1);
                break;
            }
            case 0x4a: {
                X4A* p4A = (X4A*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X4A)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p4A->b0C), 1);
                break;
            }
            case 0x35: {
                X35* extra_ = (X35*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X35)))));
                unsigned int uiCrimeCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                for (unsigned int j = 0; j < uiCrimeCount; j++)
                {
                    int iCrimeID = 0;
                    int iCrimeType = -1;
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iCrimeID), 4);
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iCrimeType), 4);
                    void* pInventoryObject = ((void *)(reinterpret_cast<::fnv_009724e0::FUN_009724e0_shell *>(&((*reinterpret_cast<::CrimeList *>(&::g_011e0e80))))->FindMobileObjectByValue(iCrimeType, iCrimeID)));
                    if (pInventoryObject != 0)
                    {
                        extra_->pList->AddHead(pInventoryObject);
                    }
                    else
                    {
                        ::FUN_00845cc0(
                            "Could not find crime %i with crime type %i in the global crime list for ref %s (%08X)",
                            iCrimeID, iCrimeType, pRef ? pRef->GetName() : "UNKNOWN", pRef ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRef))->FUN_0084e3a0())) : 0);
                    }
                }
                if (*((void **)(new ((void *)(extra_->pList)) ::Vec3())) == 0)
                {
                    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x35);
                }
                break;
            }
            case 0x45: {
                X45* extra_ = (X45*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X45)))));
                unsigned int uiAnimCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                reinterpret_cast<::BSSimpleArrayActor *>(&(extra_->kArray))->FUN_0042f5f0(uiAnimCount, 1);
                for (unsigned int j = 0; j < uiAnimCount; j++)
                {
                    AnimItem* pAnim = (AnimItem*)((void **)(reinterpret_cast<::S3e60 *>(&(extra_->kArray))->FUN_006a7ad0(j)));
                    reinterpret_cast<::CombatTargetTimestamp *>((pAnim))->LoadGame((::BGSLoadGameBuffer *)(buf));
                }
                if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(extra_->kArray))->GetName())) == 0)
                {
                    reinterpret_cast<::FUN_00422670_Cls *>(this)->RemoveExtra045();
                }
                break;
            }
            case 0x5e: {
                X5E* extra_ = (X5E*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X5E)))));
                unsigned int uiFactionCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                for (unsigned int j = 0; j < uiFactionCount; j++)
                {
                    XPackEntry* pRank = new XPackEntry;
                    pRank->pForm = dynamic_cast<TESFaction*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pRank->b04), 1);
                    extra_->pList->AddHead(pRank);
                }
                {
                    FormList* pNode = extra_->pList;
                    FormList* pPrev = 0;
                    while (pNode != 0 && !pNode->IsEmpty())
                    {
                        XPackEntry* data5 = (XPackEntry*)*((void **)(new ((void *)(pNode)) ::Vec3()));
                        bool bRemove = false;
                        if (data5 != 0)
                        {
                            if (data5->pForm == 0)
                            {
                                delete data5;
                                bRemove = true;
                            }
                        }
                        else
                        {
                            bRemove = true;
                        }
                        if (bRemove)
                        {
                            if (pPrev != 0)
                            {
                                reinterpret_cast<::ItemChangeListNode *>((pPrev))->FUN_00905330((*(::InventoryStackRecord *const *)(((void **)(new ((void *)(pNode)) ::Vec3())))));
                                pNode = ((::FormList *)(reinterpret_cast<::Callees *>((pPrev))->FUN_00726070()));
                            }
                            else
                            {
                                pNode->RemoveHead();
                            }
                        }
                        else
                        {
                            pPrev = pNode;
                            pNode = ((::FormList *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                        }
                    }
                }
                break;
            }
            case 0x70: {
                X70* p70 = (X70*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X70)))));
                char cObj = -1;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&cObj), 1);
                if (cObj != -1)
                {
                    p70->pObj = CreateObj70(cObj);
                    p70->pObj->LoadGame(buf);
                }
                break;
            }
            case 0x2c: {
                unsigned char cValue = 0;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&cValue), 1);
                X2C* extra_ = (X2C*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : 0);
                if (extra_ != 0 && extra_->pSub != 0)
                {
                    reinterpret_cast<::TESLeveledList *>((extra_->pSub))->FUN_0042e680(cValue);
                }
                break;
            }
            case 0x90:
            case 0x91:
                break;
            case 0x7c: {
                X7C* extra_ = (X7C*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X7C)))));
                unsigned int count = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(extra_->kArray))->FUN_006f2290(count, 1);
                for (unsigned int j = 0; j < count; j++)
                {
                    void** ppRef = ((void **)(reinterpret_cast<::S3e60 *>(&(extra_->kArray))->FUN_006a7ad0(j)));
                    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(ppRef));
                }
                break;
            }
            case 0x74: {
                X74* p74 = (X74*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X74)))));
                p74->m_pEncounterZone = dynamic_cast<BGSEncounterZone*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                break;
            }
            case 0x5c: {
                X5C* p5C = (X5C*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X5C)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p5C->u0C), 4);
                break;
            }
            case 0x5d: {
                X5D* p5D = (X5D*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X5D)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p5D->u0C), 4);
                break;
            }
            case 0x6e: {
                X6E* p6E = (X6E*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X6E)))));
                p6E->pAmmo = dynamic_cast<TESAmmo*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p6E->u10), 4);
                break;
            }
            case 0x1e: {
                X1E* p1E = (X1E*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X1E)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p1E->u0C), 4);
                break;
            }
            case 0x1a: {
                X1A* p1A = (X1A*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X1A)))));
                int iMapID = 0;
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&iMapID));
                if (iMapID != 0)
                {
                    p1A->pForm = ((::LoadForm *)(::CreatePackageByType(0x17)));
                    reinterpret_cast<::FakeGame *>(((*reinterpret_cast<::DataHandler * *>(&::g_BGSSaveLoadGame))))->SetFormIDMapping(iMapID, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1A->pForm))->FUN_0084e3a0())));
                    p1A->pForm->LoadGame(buf);
                }
                break;
            }
            case 0x1f:
                reinterpret_cast<::fnv_0041a960::FUN_0041a960_shell *>(this)->SetGhost(1);
                break;
            case 0x26: {
                X26* p26 = (X26*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X26)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p26->b0C), 1);
                break;
            }
            case 0x27: {
                X27* p27 = (X27*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X27)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p27->u0C), 4);
                break;
            }
            case 0x28: {
                X28* p28 = (X28*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X28)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p28->u0C), 4);
                break;
            }
            case 0x2a: {
                X2A* p2A = (X2A*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X2A)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p2A->pData->b00), 1);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p2A->pData->b08), 1);
                p2A->pData->pKey = dynamic_cast<TESKey*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                if (buf->GetVersion() >= 0x10)
                {
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p2A->pData->u0C), 4);
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p2A->pData->u10), 4);
                }
                break;
            }
            case 0x2f: {
                X2F* p2F = (X2F*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X2F)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p2F->u0C), 4);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p2F->b10), 1);
                break;
            }
            case 0x32: {
                X32* p32 = (X32*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X32)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p32->u18));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p32->u1C));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p32->u20));
                break;
            }
            case 0x33: {
                X33* p33 = (X33*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X33)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p33->u1C));
                ::ActiveEffect::LoadActiveEffectList((::BGSLoadFormBuffer *)(buf), (::BSSimpleList< ::ActiveEffect *> *)(void *)(&p33->u20));
                break;
            }
            case 0x39: {
                X39* p39 = (X39*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X39)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p39->u0C));
                break;
            }
            case 0x3f: {
                X3F* p3F = (X3F*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X3F)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p3F->pItem));
                p3F->pItem = dynamic_cast<AlchemyItem*>(::MagicItem::GetMagicItemByID((unsigned int)(p3F->pItem)));
                break;
            }
            case 0x46: {
                X46* p46 = (X46*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X46)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p46->u0C));
                break;
            }
            case 0x4d: {
                X4D* p4D = (X4D*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X4D)))));
                reinterpret_cast<::FUN_0083fbe0_Class *>((p4D->pState))->FUN_0083fbe0((::BGSLoadGameBuffer *)(buf));
                break;
            }
            case 0x4e: {
                X4E* p4E = (X4E*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X4E)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p4E->b0C), 1);
                break;
            }
            case 0x5f: {
                X5F* pOld5F = (X5F*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : 0);
                if (pOld5F != 0)
                {
                    reinterpret_cast<::FUN_00410020_t *>(this)->FUN_00410020((::BSExtraData *)(pOld5F), 0);
                }
                else if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::LoadFlags &)(buf->GetFlags2()))->FUN_004280f0(0x20000))
                {
                    if (actor->v116())
                    {
                        reinterpret_cast<::ActorD *>((actor))->UpdateDismemberedLimbs();
                    }
                }
                X5F* extra_ = new X5F;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&extra_->u0C), 2);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&extra_->u10), 4);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&extra_->u18), 4);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&extra_->b1C), 1);
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&extra_->u14));
                unsigned int count_ = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(extra_->kArray))->FUN_006f2290(count_, 1);
                for (unsigned int j = 0; j < count_; j++)
                {
                    XListEntry** ppList = (XListEntry**)((void **)(reinterpret_cast<::S3e60 *>(&(extra_->kArray))->FUN_006a7ad0(j)));
                    *ppList = new XListEntry;
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&(*ppList)->b00), 1);
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&(*ppList)->b01), 1);
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&(*ppList)->b02), 1);
                    if (buf->GetVersion() >= 0x10)
                    {
                        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&(*ppList)->b03), 1);
                    }
                    unsigned int uCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&((*ppList)->kItems))->FUN_006f2290(uCount, 1);
                    for (unsigned int k = 0; k < uCount; k++)
                    {
                        void** ppItem = ((void **)(reinterpret_cast<::S3e60 *>(&((*ppList)->kItems))->FUN_006a7ad0(k)));
                        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(ppItem));
                    }
                    {
                        unsigned int uiValid = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*ppList)->kItems))->GetName()));
                        for (unsigned int m = 0; m < uiValid; m++)
                        {
                            bool bBad = false;
                            TESForm** ppForm = (TESForm**)((void **)(reinterpret_cast<::S3e60 *>(&((*ppList)->kItems))->FUN_006a7ad0(m)));
                            *ppForm =
                                *ppForm ? dynamic_cast<TESBoundObject*>(::FUN_004839c0((unsigned int)*ppForm)) : 0;
                            if (*ppForm == 0)
                            {
                                bBad = true;
                            }
                            if (bBad)
                            {
                                reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&((*ppList)->kItems))->FUN_009a4320(m, 1);
                                m--;
                                uiValid--;
                            }
                        }
                    }
                }
                bool bAny = false;
                if (pOld5F != 0)
                {
                    if (reinterpret_cast<::EntryCollection *>((pOld5F))->FUN_00430660((::EntryCollection *)(extra_)))
                    {
                        bAny = true;
                    }
                    else
                    {
                        reinterpret_cast<::ActorD *>((actor))->UpdateDismemberedLimbs();
                    }
                    delete pOld5F;
                }
                reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(extra_));
                if (!bAny)
                {
                    reinterpret_cast<::Actor_8b6ae0 *>((actor))->FUN_008b6ae0();
                }
                break;
            }
            case 0x55: {
                X55* p55 = (X55*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X55)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p55->u0C));
                break;
            }
            case 0x60: {
                X60* extra8 = (X60*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X60)))));
                int iItemID = -1;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iItemID), 4);
                reinterpret_cast<::Holder0042f780 *>(&(extra8->kList))->FUN_0042f780((::AC_0042f730 *)(void *)(((void *)(::FindStateByValue(iItemID)))));
                if (!::FUN_00559450((int *)&(extra8->kList)))
                {
                    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x60);
                }
                break;
            }
            case 0x2b: {
                X2B* p2B = (X2B*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X2B)))));
                if (p2B->pObj == 0)
                {
                    p2B->pObj = new XObj20;
                }
                reinterpret_cast<::fnv_0043aaa0::FUN_0043aaa0_shell *>((p2B->pObj))->LoadGame((::fnv_0043aaa0::BGSLoadFormBuffer *)(buf));
                break;
            }
            case 0x3c: {
                X3C* p3C = (X3C*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X3C)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p3C->u0C));
                break;
            }
            case 0x2e: {
                X2E* _extra = (X2E*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X2E)))));
                TESActorBase* base8 = _extra->pBase;
                TESActorBase* fBase = _extra->pBase2;
                _extra->pBase = dynamic_cast<TESActorBase*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                _extra->pBase2 = dynamic_cast<TESActorBase*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buf))->FUN_008648a0()));
                int iFlags = 0;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iFlags), 4);
                if (actor != 0 && actor->v116() && fBase != 0 && _extra->pBase2 != fBase)
                {
                    actor->v115(0, 0);
                }
                else if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::DataHandler * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    actor->v115(0, 0);
                }
                DelObj* kObj = 0;
                bool bActive3 = false;
                bool bFound0 = false;
                if (fBase != _extra->pBase2 && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::LoadFlags &)(buf->GetFlags()))->FUN_004280f0(0x8000020))
                {
                    bFound0 = true;
                }
                if (bFound0)
                {
                    reinterpret_cast<::ExtraDataList *>((((::RefSub *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))))->RemoveExtraDataType0x15();
                    reinterpret_cast<::FUN_008adc50_shell *>((actor))->FUN_008adc50();
                }
                if (actor != 0 && _extra->pBase != 0 && _extra->pBase2 != 0 && reinterpret_cast<::FUN_0047cdb0_shell *>(&(_extra->pBase->kBaseData))->FUN_0047cdb0())
                {
                    kObj = ((::DelObj *)(::FUN_0047d130(_extra->pBase, _extra->pBase2)));
                    DelObj* pCur = ((::DelObj *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()));
                    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::ProcMgr * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pCur))->FUN_0084e3a0()))))
                    {
                        delete pCur;
                    }
                    reinterpret_cast<::Fn575690 *>((actor))->FUN_00575690(kObj);
                }
                else if (base8 != 0 && fBase != 0)
                {
                    _extra->pBase = base8;
                    _extra->pBase2 = fBase;
                }
                else
                {
                    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x2e);
                }
                if (bFound0)
                {
                    RefProc* pProc = ((::RefProc *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(actor))));
                    reinterpret_cast<::Inv4d1440 *>((pProc))->FUN_004d1440();
                    reinterpret_cast<::FUN_004d1610_shell *>((pProc))->FUN_004d1610();
                    reinterpret_cast<::fnv_004d1960::InvInventory *>((pProc))->FUN_004d1960();
                    if (reinterpret_cast<::FUN_0042cde0_shell *>((pProc))->FUN_0042cde0())
                    {
                        reinterpret_cast<::ExtraDataList *>((((::RefSub *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))))->RemoveExtraDataType0x15();
                    }
                }
                if (kObj == 0)
                {
                    kObj = actor->v134() ? (DelObj*)new DelObj20C : (DelObj*)new DelObj160;
                    bActive3 = true;
                }
                LoadFlags saved = buf->GetFlags();
                LoadFlags saved_ = buf->GetFlags2();
                unsigned char _saved = ((unsigned char)(reinterpret_cast<::FUN_0042ce90_class *>((buf))->FUN_0042ce90()));
                reinterpret_cast<::FUN_00428130_Class *>((buf))->SetValue((*(int *)&(const ::LoadFlags &)(iFlags)));
                reinterpret_cast<::Twin_0086cf00 *>((buf))->SetD3DPixelShader((*(::GeometryRelatedType *const *)&(const ::LoadFlags &)(0)));
                reinterpret_cast<::BGSChangeFlagsState *>((buf))->CombineFlags(0);
                kObj->LoadGame(buf);
                reinterpret_cast<::FUN_0047e340_shell *>(&(kObj->kData30))->FUN_0047e340(iFlags);
                reinterpret_cast<::FUN_00428130_Class *>((buf))->SetValue((*(int *)&(const ::LoadFlags &)(saved)));
                reinterpret_cast<::Twin_0086cf00 *>((buf))->SetD3DPixelShader((*(::GeometryRelatedType *const *)&(const ::LoadFlags &)(saved_)));
                reinterpret_cast<::BGSChangeFlagsState *>((buf))->CombineFlags(_saved);
                if (bActive3)
                {
                    delete kObj;
                }
                break;
            }
            case 0x54: {
                X54* p54 = (X54*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : 0);
                if (p54 != 0)
                {
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p54->u14), 4);
                }
                else
                {
                    int iDummy;
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iDummy), 4);
                }
                break;
            }
            case 0x50: {
                X50* p50 = (X50*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X50)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p50->b0C), 1);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p50->b0D), 1);
                break;
            }
            case 0x89: {
                X89* p89 = (X89*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X89)))));
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p89->u0C));
                break;
            }
            case 0x8b: {
                X8B* p8B = (X8B*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X8B)))));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(p8B->u10), 0xc);
                if (buf->GetVersion() >= 0x12)
                {
                    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&p8B->u1C));
                }
                else
                {
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p8B->u1C), 4);
                }
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p8B->u0C), 4);
                unsigned int uiEntryCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buf))->FUN_00864a60()));
                for (unsigned int j = 0; j < uiEntryCount; j++)
                {
                    XEntry24* pE = new XEntry24;
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(pE), 0xc);
                    if (buf->GetVersion() >= 0x12)
                    {
                        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&pE->u0C));
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pE->u0C), 4);
                    }
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(pE->f10), 0xc);
                    if (buf->GetVersion() >= 0x12)
                    {
                        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buf))->FUN_008648e0((unsigned int *)(void *)(&pE->u1C));
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pE->u1C), 4);
                    }
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pE->b20), 1);
                    p8B->kList.AddHead(pE);
                }
                break;
            }
            case 0x8f: {
                X8F* p8F = (X8F*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X8F)))));
                char acName[0x100];
                reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((buf))->FUN_008649a0(acName);
                reinterpret_cast<::fnv_00438260::FUN_00438260 *>((p8F))->SetStr(acName);
                reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((buf))->FUN_008649a0(acName);
                reinterpret_cast<::FUN_00438280_class *>((p8F))->FUN_00438280(acName);
                break;
            }
            case 0x92: {
                X92* p92 = (X92*)(abHas[cType] ? reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(cType) : ((::ExtraData110 *)(reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(::ExtraData110 *)(new X92)))));
                unsigned int uiRender;
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&uiRender), 4);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buf))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&p92->u10), 4);
                reinterpret_cast<::FUN_0041fd00_shell *>((p92))->FUN_0041fd00(uiRender);
                break;
            }
            default:
                ::FUN_00845cc0("Unknown extra data type %i found in ExtraDataList::LoadGame", cType);
                break;
            }
            abHas[cType] = 0;
        }
        for (unsigned int uiType = 0; uiType < 0x93; uiType++)
        {
            bool bRemove = abHas[uiType];
            if (bRemove)
            {
                switch (uiType)
                {
                case 0x2e:
                    bRemove = false;
                    break;
                case 0x92: {
                    ExtraSpecialRenderFlags* pFlags = dynamic_cast<ExtraSpecialRenderFlags*>(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x92));
                    if (pFlags != 0)
                    {
                        reinterpret_cast<::FUN_0041fd00_shell *>((pFlags))->FUN_0041fd00(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pFlags))->FUN_0084e3a0())) & 7);
                    }
                    bRemove = false;
                    break;
                }
                }
            }
            if (bRemove)
            {
                reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra((unsigned char)uiType);
            }
        }
    }
}
