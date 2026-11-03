
// src/fallout/ai/highprocess_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (FleePackage, TESPackage). The skeleton of src/fallout/ai/highprocess.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/Actor87.h"
#include "fnv/decl/Actor897.h"
#include "fnv/decl/B968730Actor.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C.h"
#include "fnv/decl/C901C50Object.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Date.h"
#include "fnv/decl/DialogueItem_shell.h"
#include "fnv/decl/ExtraDataListRemoveTrespassPackage.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cd70_shell.h"
#include "fnv/decl/FUN_00422820_shell.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047d7c0_Class.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00497f20_shell.h"
#include "fnv/decl/FUN_00498d30_t.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_0050ead0_cls.h"
#include "fnv/decl/FUN_0050eb90_Class.h"
#include "fnv/decl/FUN_00544490_Class.h"
#include "fnv/decl/FUN_0059f610Class.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005ff160_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_0067a480_shell.h"
#include "fnv/decl/FUN_0067a770_shell.h"
#include "fnv/decl/FUN_0067efd0_shell.h"
#include "fnv/decl/FUN_0067f1c0_shell.h"
#include "fnv/decl/FUN_006e2b50_shell.h"
#include "fnv/decl/FUN_0083d0d0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00884f80_shell.h"
#include "fnv/decl/FUN_0088c570_shell.h"
#include "fnv/decl/FUN_00894cc0_shell.h"
#include "fnv/decl/FUN_00894d60_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008adcb0_shell.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_008b2010_shell.h"
#include "fnv/decl/FUN_008b39f0_shell.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc700_shell.h"
#include "fnv/decl/FUN_008c0050_cls.h"
#include "fnv/decl/FUN_008c51c0_shell.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/FUN_008d0300_shell.h"
#include "fnv/decl/FUN_008d72e0_Class.h"
#include "fnv/decl/FUN_008d7340StandIn.h"
#include "fnv/decl/FUN_008d7420.h"
#include "fnv/decl/FUN_008d74a0.h"
#include "fnv/decl/FUN_008dade0_shell.h"
#include "fnv/decl/FUN_008dbd80_class.h"
#include "fnv/decl/FUN_008dbda0Class.h"
#include "fnv/decl/FUN_008ff080_shell.h"
#include "fnv/decl/FUN_008ffdc0_Class.h"
#include "fnv/decl/FUN_009003e0_shell.h"
#include "fnv/decl/FUN_00900400_shell.h"
#include "fnv/decl/FUN_00903cd0_shell.h"
#include "fnv/decl/FUN_00905450_StandIn.h"
#include "fnv/decl/FUN_00915400_shell.h"
#include "fnv/decl/FUN_0091fe80_shell.h"
#include "fnv/decl/FUN_009280f0_Class.h"
#include "fnv/decl/FUN_0092bf20_cls.h"
#include "fnv/decl/FUN_0092ce00_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00953c20_shell.h"
#include "fnv/decl/FUN_00953c50_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009865b0_shell.h"
#include "fnv/decl/FUN_00992530_shell.h"
#include "fnv/decl/FUN_009de2b0_shell.h"
#include "fnv/decl/FUN_009f7d70_cls.h"
#include "fnv/decl/FUN_009f7f20_class.h"
#include "fnv/decl/FUN_009f8570_class.h"
#include "fnv/decl/FUN_009f8660_class.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/FormNode.h"
#include "fnv/decl/Holder_009f7fe0.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/Owner0092cec0.h"
#include "fnv/decl/Owner8ffe50.h"
#include "fnv/decl/Package8020.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Ref.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/ST_008c8bb0.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/Self.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESNPC_Sub.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/UpdateOwner.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0041cc90__ExtraDataListStandIn.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_004985f0__FUN_004985f0_s.h"
#include "fnv/decl/fnv_00498f80__FUN_00498f80_cls.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/decl/fnv_005710c0__ModelRef.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_006e29f0__FUN_006e29f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0084a810__FUN_0084a810_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/decl/fnv_008a5e80__FakeActor.h"
#include "fnv/decl/fnv_008a7870__FUN_008a7870_shell.h"
#include "fnv/decl/fnv_008a78f0__FUN_008a78f0_shell.h"
#include "fnv/decl/fnv_008ac6f0__ActorS_008ac6f0.h"
#include "fnv/decl/fnv_008acbe0__FUN_008acbe0_shell.h"
#include "fnv/decl/fnv_008b8e90__FUN_008b8e90_shell.h"
#include "fnv/decl/fnv_008bcc80__FUN_008bcc80_shell.h"
#include "fnv/decl/fnv_008bffc0__FUN_008bffc0_shell.h"
#include "fnv/decl/fnv_008ffd10__FUN_008ffdc0_Class.h"
#include "fnv/decl/fnv_00903de0__FUN_00903de0_shell.h"
#include "fnv/decl/fnv_00903e00__FUN_00903e00_shell.h"
#include "fnv/decl/fnv_00903e20__FUN_00903e20_shell.h"
#include "fnv/decl/fnv_00904160__FUN_00904160_shell.h"
#include "fnv/decl/fnv_009278d0__Target.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00972570__FUN_00972570_shell.h"
#include "fnv/decl/fnv_00992480__CombatOwner_SV.h"
#include "fnv/decl/fnv_009f8300__FUN_009f8300_class.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/xActor_2.h"
#include "fnv/decl/xProcess.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00546000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_005cc000.h"
#include "fnv/symbols_005d9000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00642000.h"
#include "fnv/symbols_00669000.h"
#include "fnv/symbols_008d7000.h"
#include "fnv/symbols_00903000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "highprocess_decls_rtti_variant.h"

namespace PackagePathing {
struct Actor;
struct Request;
struct List;
struct Vec
{
    float x, y, z;
    Vec();
};
struct Cell
{
};
struct Setting
{
};
struct Package
{
    virtual void PackageTypeAnchor();
    void FUN_009f1310(void*);
};
struct List
{
    unsigned int unk0, unk4, unk8, unkc;
    List();
    ~List();
};
struct Values
{
    virtual void slot0();
    virtual void slot4();
    virtual int Value(int);
};
struct Process
{
};
struct Race
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual bool Flag();
};
struct Base
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    Race race;
};
struct Location
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    Location(const Vec&, Actor*);
    ~Location();
};
struct Request
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Request();
    ~Request();
};
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual const Vec& Position();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual bool Alternate();
    virtual bool HasRace();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual Package* Current();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void SetPath(Actor*, int, int);
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void Start(void*, int, int, int, int, int, float, float);
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    Values values;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    Process* process;
    bool FUN_008bb630(Request*);
    void FUN_008db810(Actor*);
};
struct System
{
};
struct Timer
{
};

// @fnv 0x008db810
void Actor::FUN_008db810(Actor* actor)
{
    Package* current = Current();
    Package* package = 0;
    if (current && reinterpret_cast<struct ::FUN_0041ca90 *>((current))->get() == 24)
        package = current;
    if (!package)
        return;
    if (reinterpret_cast<::FUN_008d0300_shell *>(((*reinterpret_cast<::PackagePathing::System * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_008d0300((::Actor *)(actor), (::Actor *)(0)) || actor->values.Value(1) <= 0)
    {
        List targetsSlot0;
        reinterpret_cast<::FUN_009f8660_class *>((package))->FUN_009f8660((*(::BSSimpleArrayActor *)(&targetsSlot0)));
        int count = ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(targetsSlot0))->GetName()));
        if (count > 0)
        {
            reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((actor))->FUN_00881680(0);
            actor->Start(*((void **)(reinterpret_cast<::S3e60 *>(&(targetsSlot0))->FUN_006a7ad0(0))), 1, 1, 1, 0, 0, ::DAT_01012054, ::DAT_01012054);
            ::FleePackage* following = dynamic_cast< ::FleePackage*>(reinterpret_cast<::FUN_009344a0_shell *>((actor))->FUN_009344a0());
            if (following)
            {
                for (int index = 0; index < count; index++)
                    following->FUN_009f1310((::TESObjectREFR *)(::Actor *)(static_cast< ::Actor*>(*((void **)(reinterpret_cast<::S3e60 *>(&(targetsSlot0))->FUN_006a7ad0(index))))));
            }
            return;
        }
    }
    if (reinterpret_cast<::Holder_009f7fe0 *>((package))->FUN_009f7fe0())
    {
        reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((actor))->FUN_00881680(0);
        return;
    }
    float nearDistanceSlot10 = 0.0f;
    float farDistanceSlot35 = 0.0f;
    Vec unusedSlot11;
    int flagsSlot15 = 513;
    Vec pointSlot13 = (*(::PackagePathing::Vec *)&(reinterpret_cast<::fnv_009f8300::FUN_009f8300_class *>((package))->FUN_009f8300(*(::fnv_009f8300::NiPoint3 *)nullptr)));
    float distanceSlot14 = reinterpret_cast<::fnv_00572380::Fn572380 *>((actor))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(pointSlot13));
    Cell* cell = ((::PackagePathing::Cell *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()));
    bool nearSlot19 = false;
    if (cell && reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
    {
        nearDistanceSlot10 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PackagePathing::Setting *>(&::originalRuntimeFloatSetting189))))));
        farDistanceSlot35 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PackagePathing::Setting *>(&::originalRuntimeFloatSetting188))))));
        if (distanceSlot14 < nearDistanceSlot10)
            nearSlot19 = true;
    }
    else
    {
        nearDistanceSlot10 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PackagePathing::Setting *>(&::originalRuntimeFloatSetting187))))));
        farDistanceSlot35 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PackagePathing::Setting *>(&::originalRuntimeFloatSetting186))))));
        if (distanceSlot14 < farDistanceSlot35)
            nearSlot19 = true;
    }
    reinterpret_cast<::Package8020 *>((package))->FUN_009f8020((::Actor8020 *)(actor));
    if (((bool)(reinterpret_cast<::TeleportableReference *>((actor))->GetTeleportDestinationForm())))
    {
        reinterpret_cast<::FUN_009f7f20_class *>((package))->FUN_009f7f20((::MobileObject *)(actor), 1);
        reinterpret_cast<::FUN_009f7d70_cls *>((package))->FUN_009f7d70((::Actor9f7d *)(actor), 1);
        unsigned int time = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::PackagePathing::Timer *>(&::g_timeGlobal))))->FUN_00825c00();
        if (time > ((unsigned int)(reinterpret_cast<::EffectSetting *>((package))->GetCastSound())) + 1500)
        {
            reinterpret_cast<::FUN_008ac890_shell *>((package))->SetWaterForm((::TESWaterForm *)(time));
            Vec oldSlot17Slot17 = actor->Position();
            Request requestSlot13;
            reinterpret_cast<::fnv_006e29f0::FUN_006e29f0_shell *>(&(requestSlot13))->InitFromActor((::Actor *)(actor));
            if (actor->HasRace())
                reinterpret_cast<::FUN_006e2b50_shell *>(&(requestSlot13))->SetCantOpenDoors(((::PackagePathing::Base *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()))->race.Flag());
            reinterpret_cast<::FUN_008dbda0Class *>(&(requestSlot13))->SetPathingLocation((const ::PathingLocation &)((const ::PackagePathing::Location &)(Location((*(::PackagePathing::Vec *)&(reinterpret_cast<::fnv_009f8300::FUN_009f8300_class *>((package))->FUN_009f8300(*(::fnv_009f8300::NiPoint3 *)nullptr))), actor))));
            reinterpret_cast<::FUN_008dbd80_class *>(&(requestSlot13))->FUN_008dbd80(reinterpret_cast<::FUN_00507e10_shell *>((package))->FUN_00507e10() + ::DAT_0102e430);
            reinterpret_cast<::PathingRequest *>(&(requestSlot13))->SetCenterRadius(::DAT_0101e6ec);
            int mode = ((int)(reinterpret_cast<::FUN_009f8570_class *>((package))->FUN_009f8570()));
            reinterpret_cast<::PathingRequest *>(&(requestSlot13))->SetAvoidNodeArray((::BSSimpleArray<void *, 1024> *)(mode));
            if (!actor->FUN_008bb630(&requestSlot13))
                return;
            if (reinterpret_cast<::FUN_00894d60_shell *>((actor))->FUN_00894d60())
                reinterpret_cast<::FUN_00894cc0_shell *>((actor))->FUN_00894cc0(0);
            reinterpret_cast<::FUN_008b39f0_shell *>((actor))->FUN_008b39f0(512);
            Vec targetSlot6Slot10;
            if (reinterpret_cast<::FUN_009de2b0_shell *>((actor->process))->GetPathCoordinate((::NiPoint3 *)(::PackagePathing::Vec *)(&targetSlot6Slot10)))
            {
                float targetDistanceSlot1 = reinterpret_cast<::fnv_00572380::Fn572380 *>((actor))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(targetSlot6Slot10));
                if (targetDistanceSlot1 <= ::DAT_010240c0)
                    flagsSlot15 = 257;
                SetPath(actor, flagsSlot15, 1);
            }
        }
    }
    else if (actor->Alternate())
    {
        reinterpret_cast<::FUN_009f7f20_class *>((package))->FUN_009f7f20((::MobileObject *)(actor), 1);
        reinterpret_cast<::FUN_009f7d70_cls *>((package))->FUN_009f7d70((::Actor9f7d *)(actor), 1);
    }
    if (reinterpret_cast<::FUN_008b3b90_shell *>((actor))->FUN_008b3b90())
        return;
    if (distanceSlot14 > farDistanceSlot35 * 2.0f)
    {
    }
}
}
