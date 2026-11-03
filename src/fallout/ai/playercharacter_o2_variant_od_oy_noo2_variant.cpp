
// src/fallout/ai/playercharacter_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/playercharacter_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/playercharacter_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/playercharacter.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C00624070.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FNV_AnimationOwner.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/decl/FUN_004b4e50_shell.h"
#include "fnv/decl/FUN_004b4f40.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0082aeb0_shell.h"
#include "fnv/decl/FUN_0082aee0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008c5d90_Class.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00961200_Class.h"
#include "fnv/decl/FUN_00961260_Class.h"
#include "fnv/decl/FUN_0096a350_class.h"
#include "fnv/decl/FUN_0096a370_Class.h"
#include "fnv/decl/FUN_00c66fb0_Class.h"
#include "fnv/decl/FUN_00c6e280_cls.h"
#include "fnv/decl/FUN_00c9c390_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/V.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00494740__FUN_00494740_t.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004b4d10__UnaryActionSettings.h"
#include "fnv/decl/fnv_004b4ea0__TESDataHandler.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/decl/fnv_008aff80__ActorStub.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00961230__FUN_00961230_Class.h"
#include "fnv/decl/fnv_00961280__FUN_00961280_shell.h"
#include "fnv/decl/fnv_00963eb0__PlayerView.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0062c000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00960000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00c66000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01197000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "PlayerCharacter.h"
struct FUN_00c6fd20_class
{
    void* m_60c;
    int FUN_00c6fd20();
};

#include <xmmintrin.h>
struct GrabVector
{
    __m128 value;
};
struct GrabPoint
{
    float x, y, z;
    GrabPoint operator*(float) const;
    GrabPoint operator+(const GrabPoint&) const;
    GrabPoint operator-(const GrabPoint&) const;
};
struct GrabMatrix
{
    GrabPoint FUN_004b4500(const GrabPoint*) const;
};
struct GrabPosition
{
    GrabVector value;
};
struct GrabBody;
struct GrabConstraintData
{
    int unk00;
    GrabBody* body;
    int unk08, unk0c;
    GrabPosition angular;
    GrabPosition position;
    float f30, f34, f38, f3c;
};
struct GrabRay
{
    GrabVector from, to;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    float hitFraction;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    void FUN_004a3f70(int);
};
struct GrabFilter
{
    int bits;
    GrabFilter(int);
};
struct GrabController
{
};
struct GrabCell;
struct GrabRef;
struct GrabShape;
struct GrabItem
{
};
struct GrabItems
{
};
struct GrabBody
{
    void* FUN_004b4ec0();
};
struct GrabWorld
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual bool Cast(GrabRay*);
};
struct GrabShape
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual int GetType();
};
struct GrabPhysics
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void GetNavMeshData(GrabVector*);
    GrabFilter FUN_0043b4f0();
};
struct GrabRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsDead();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual GrabRef* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool IsActor();
    virtual void v228();
    virtual bool AllowGrab(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual int GetState();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual bool IsStateValid();

};
struct GrabCell
{
};
struct GrabSetting
{
    bool* FUN_00408d60();
};
struct GrabSave
{
};
struct GrabConstraint
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();

    virtual void SetWorld(GrabWorld*);
    int unk04, unk08, unk0c;
    static void* operator new(unsigned);
    GrabConstraint(const GrabConstraintData*);
};
struct GrabPointer
{
    GrabConstraint* ptr;
    GrabPointer& FUN_0066b0d0(GrabConstraint*);
};
struct GrabHost
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;

    GrabPointer constraint;
    GrabRef* target;
    int mode;
    float mass;
    float distance;
    GrabFilter* FUN_00931ed0(int*);
    void FUN_0095f930(GrabRef*, int, float);
};

// @fnv 0x0095f930
void GrabHost::FUN_0095f930(GrabRef* ref, int newMode, float range)
{
    if (!*(*reinterpret_cast<::GrabSetting *>(&::g_011e0b1c)).FUN_00408d60() && ref->IsDead() && !ref->AllowGrab(0))
        return;
    if (ref && ref->IsActor())
    {
        GrabRef* actor = ref;
        if (actor->GetState() == 3)
        {
            GrabRef* actor2 = actor;
            if (actor2->IsStateValid() && !reinterpret_cast<::FUN_00444d00_Class *>((actor2))->FUN_00444d00(0x200))
                return;
        }
    }
    if (ref && ((::GrabCell *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())))
    {
        GrabRef* root = ref->Get3D();
        GrabPhysics* physics = ((::GrabPhysics *)(::FUN_004b52f0(root)));
        if (physics)
        {
            bool character = ((int)(::GetBSXFlags((unsigned int)(root), 8))) || ref->IsDead();
            target = ref;
            ::FUN_005ac750((::TESForm *)(0), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((target))->FUN_005d43c0()), 0x80000);
            mode = newMode;
            distance = range;
            GrabConstraintData data;
            new ((void *)&(data)) ::FUN_004b4f40();
            float ignored = 0.0f;
            GrabVector center;
            new ((void *)&(center)) ::Vec3();
            if (character && ref->IsDead())
                ::GetScalarAndVector(root, (::__m128 *)(::GrabVector *)(&center), &ignored);
            else
                physics->GetNavMeshData(&center);
            GrabPoint direction;
            new ((void *)&(direction)) ::Vec3();
            GrabPoint origin;
            new ((void *)&(origin)) ::Vec3();
            reinterpret_cast<::fnv_008aff80::ActorStub *>(this)->GetCameraPosAndDir((::fnv_008aff80::Vec3 *)(::GrabPoint *)(&origin), (::fnv_008aff80::Vec3 *)(::GrabPoint *)(&direction), true);
            bool selected = false;
            GrabWorld* world = ((::GrabWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::GrabCell *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()))))->FUN_004543c0()));
            if (mode == 1 && world && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::GrabSave * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
            {
                if (!((bool)(::fnv_00703430::FUN_00703430())) || !((::GrabPhysics *)(::FUN_00960510())))
                {
                    GrabRay ray;
                    new ((void *)&(ray)) ::FUN_004a3c20();
                    GrabFilter filter(0);
                    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(0x24);
                    int filterTemp;
                    reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((FUN_00931ed0(&filterTemp)))->FUN_004a3a20())));
                    ray.FUN_004a3f70(filter.bits);
                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0((void *)(&origin));
                    reinterpret_cast<::Class_007f68a0 *>(&(ray))->FUN_007f68a0((*(const ::NiPoint3 *)(&(direction * distance))));
                    if (world->Cast(&ray))
                    {
                        GrabBody* hit = ((::GrabBody *)(::FUN_00c66fd0((::BhkPickData *)&(ray))));
                        GrabRef* hitRef = ((::GrabRef *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(hit))));
                        GrabRef* hitNode = hitRef ? ((::GrabRef *)(reinterpret_cast<::Twin_0044ddc0 *>((hitRef))->GetName())) : 0;
                        GrabRef* resolved = ((::GrabRef *)(::FUN_0056f930((::NiAVObject *)(hitNode))));
                        if (hit && resolved == ref)
                        {
                            if (!character)
                            {
                                GrabPhysics* hitPhysics = ((::GrabPhysics *)(::FUN_004b5a80(hit)));
                                hitPhysics->GetNavMeshData(&center);
                            }
                            selected = true;
                            data.body = hit;
                            distance *= ray.hitFraction;
                            GrabPoint destination = origin + direction * distance;
                            reinterpret_cast<::FUN_004b4e50_shell *>(&(data.position))->SetFromScaledVector3((void *)&(destination));
                        }
                    }
                }
                else
                {
                    GrabPoint picked;
                    ::FUN_007033d0((int *)(::GrabPoint *)(&picked));
                    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::GrabSave * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                        distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::GrabPoint &)((picked - origin)))->ComputeMagnitude();
                    reinterpret_cast<::FUN_004b4e50_shell *>(&(data.position))->SetFromScaledVector3((void *)&(picked));
                    GrabPhysics* pickedPhysics = ((::GrabPhysics *)(::FUN_00960510()));
                    data.body = ((::GrabBody *)(::FUN_004ae750((void *)(pickedPhysics))));
                    selected = true;
                }
            }
            if (!selected)
            {
                reinterpret_cast<::S004b4db0_Quaternion *>(&(data.position))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(&center)));
                GrabVector position;
                new ((void *)&(position)) ::Vec3();
                if (character)
                {
                    GrabVector scratch;
                    new ((void *)&(scratch)) ::Vec3();
                    GrabVector rotated;
                    new ((void *)&(rotated)) ::Vec3();
                    ::CopyCharacterControllerVector((::bhkCharacterController *)(::GrabVector *)(&rotated), (*(const ::NiPoint3 *)(&(((::GrabMatrix *)(::FUN_00461130((int)(root))))->FUN_004b4500(&(*reinterpret_cast<const ::GrabPoint *>((void *)&::DAT_011a9484)))))));
                    reinterpret_cast<::fnv_004b4d10::UnaryActionSettings *>(&(data.position))->ApplyToAction((::fnv_004b4d10::bhkUnaryAction *)(::GrabVector *)(&position));
                    reinterpret_cast<::V *>(&(position))->FUN_00553f70((*(const ::V *)(&rotated)));
                    reinterpret_cast<::S004b4db0_Quaternion *>(&(data.position))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(&position)));
                }
                if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::GrabSave * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    GrabPoint point;
                    new ((void *)&(point)) ::Vec3();
                    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&point)), (*(const ::hkVector4 *)(((::GrabVector *)(reinterpret_cast<::fnv_004b4d10::UnaryActionSettings *>(&(data.position))->ApplyToAction((::fnv_004b4d10::bhkUnaryAction *)(::GrabVector *)(&position)))))));
                    distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::GrabPoint &)((point - origin)))->ComputeMagnitude();
                }
                data.body = ((::GrabBody *)(::FUN_004ae750((void *)(physics))));
            }
            if (mode == 1)
                reinterpret_cast<::fnv_00963eb0::PlayerView *>(this)->SetEffectValue((void *)(5), DAT_01017868, (::fnv_00963eb0::EffectSource *)(ref));
            GrabBody* body = data.body;
            if (!((void *)(reinterpret_cast<::Twin_0044ddc0 *>((body))->GetName())) || ::FUN_00517670((::TESDataHandler *)(body)) == 5 || ::FUN_00517670((::TESDataHandler *)(body)) == 4)
            {
                reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(this)->FUN_00961280();
                return;
            }
            GrabController* controller = ((::GrabController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
            if (controller)
            {
                float minDistance = FUN_004587d0(reinterpret_cast<::FUN_00c6e280_cls *>((controller))->GetSettingFloat()) + DAT_01020998;
                if (distance < minDistance)
                    distance = minDistance;
            }
            if (mode == 3)
            {
                if (character)
                {
                    data.f30 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1177))))));
                    data.f34 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1178))))));
                    data.f3c = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1179))))));
                    data.f38 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1180))))));
                }
                else
                {
                    data.f30 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1173))))));
                    data.f34 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1174))))));
                    data.f3c = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1175))))));
                    data.f38 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1176))))));
                }
            }
            else
            {
                float angularScale = 1.0f;
                float linearScale = 1.0f;
                if (target->IsDead())
                {
                    float upper = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::g_011d1260))))));
                    float lower = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1054))))));
                    float minScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::g_011d0220))))));
                    float maxScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1053))))));
                    float clamped = FUN_0040ebd0(lower, FUN_00404010(upper, ::FUN_0062c300((::NiAVObject *)(root))));
                    angularScale *= LinearInterpolate(maxScale, minScale, lower, upper, clamped);
                    bool allCharacter = true;
                    for (int i = 0; i < ((int)(reinterpret_cast<::FUN_0096a350_class *>((((::GrabItems *)(reinterpret_cast<::FUN_009604f0_shell *>((body))->FUN_009604f0()))))->GetShortAtOffset4())) && allCharacter; ++i)
                    {
                        GrabShape* shape = ((::GrabShape *)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*((::GrabItem **)(reinterpret_cast<::FUN_0096a370_Class *>((((::GrabItems *)(reinterpret_cast<::FUN_009604f0_shell *>((body))->FUN_009604f0()))))->FUN_0096a370(i))))))->FUN_0084e3a0()));
                        allCharacter = shape->GetType() == 0xb;
                    }
                    if (allCharacter)
                    {
                        linearScale *= DAT_0101ffa0;
                        angularScale *= DAT_01018a90;
                    }
                }
                else if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::GrabFilter &)(physics->FUN_0043b4f0()))->FUN_0043b4d0() == 0xe)
                {
                    linearScale *= DAT_0101ffa0;
                    angularScale *= ::DAT_01011588;
                }
                data.f30 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1049))))));
                data.f34 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1050)))))) * linearScale;
                data.f3c = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1051))))));
                data.f38 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GrabSetting *>(&::originalRuntimeFloatSetting1052)))))) * angularScale;
            }
            GrabVector localPosition;
            new ((void *)&(localPosition)) ::Vec3();
            GrabVector localRotation;
            new ((void *)&(localRotation)) ::Vec3();
            reinterpret_cast<::fnv_004b4d10::UnaryActionSettings *>(&(data.position))->ApplyToAction((::fnv_004b4d10::bhkUnaryAction *)(::GrabVector *)(&localPosition));
            reinterpret_cast<::V *>(&(localPosition))->FUN_00961190((*(const ::V *)(body->FUN_004b4ec0())));
            reinterpret_cast<::FUN_004b4ab0_Class *>((((::GrabVector *)(reinterpret_cast<::fnv_004b4d10::UnaryActionSettings *>(&(data.angular))->ApplyToAction((::fnv_004b4d10::bhkUnaryAction *)(::GrabVector *)(&localRotation))))))->FUN_004b4ab0((int)(&(*(::GrabVector *)(new ((void *)(((::GrabVector *)(::FUN_004b4f00((::TESDataHandler *)(body)))))) ::Vec3()))), {});
            reinterpret_cast<::S004b4db0_Quaternion *>(&(data.angular))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(&localRotation)));
            reinterpret_cast<::Script *>((((::GrabWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::GrabCell *)(reinterpret_cast<::LowProcess *>((target))->GetTarget()))))->FUN_004543c0()))))->GetLocalData();
            constraint.FUN_0066b0d0(new GrabConstraint(&data));
            GrabConstraint* created = ((::GrabConstraint *)(::FUN_00559450((int *)&(constraint))));
            created->SetWorld(((::GrabWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::GrabCell *)(reinterpret_cast<::LowProcess *>((target))->GetTarget()))))->FUN_004543c0())));
            reinterpret_cast<::Script *>((((::GrabWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::GrabCell *)(reinterpret_cast<::LowProcess *>((target))->GetTarget()))))->FUN_004543c0()))))->GetLocalData();
            mass = ::FUN_0062c300((::NiAVObject *)(::GrabRef *)(ref->Get3D()));
        }
        else if (newMode == 2)
        {
            target = ref;
            ::FUN_005ac750((::TESForm *)(0), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((target))->FUN_005d43c0()), 0x80000);
            mode = 2;
            distance = range;
        }
    }
}

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
namespace fnv_00960520 {
#include <xmmintrin.h>
/* UNVERIFIED previous contributor's C++ reconstruction, 2026-10-23; preserved for official recheck. */

struct ObjF0;
struct HkTransform;
class Vec3
{
  public:
    float x;
    float y;
    float z;
    Vec3();
    Vec3 Add(const Vec3& o) const;
    Vec3 Scale(float s) const;
};
class HkVec
{
  public:
    __m128 m_v;
    HkVec();
    HkVec(float s);
    void SetTransformedPos(HkTransform* t, HkVec* p);
    HkVec Delta(void) const;
};
struct HkTransform
{
    HkVec m_row0, m_row1, m_row2, m_row3;
    HkTransform();
};
class Handle
{
  public:
    unsigned int m_val;
    Handle();
};
class Handle2
{
  public:
    unsigned int m_val;
    Handle2();
};
struct VObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual VObj* vGet0C();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int vGetType();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual bool vTest(ObjF0* p);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void vGetTransform(HkTransform* t);
    virtual void v3E();
    virtual void v3F();
    virtual bool vIsDead();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
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
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
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
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual VObj* vGet1D0();
    Handle GetHandle();
    Handle2 GetHandle2();
    VObj* Get3D();
    Vec3* GetPos();
    VObj* GetAt(int i);
};
struct ItemList
{
};
struct Obj4A0
{
    int unk00, unk04, unk08, unk0C;
    float fValue;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int iRef;
    int unk54, unk58, unk5C;
    Obj4A0(void* p);
};
struct Obj430
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C;
    int unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C;
    int unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC;
    int unk2C0, unk2C4, unk2C8, unk2CC, unk2D0, unk2D4, unk2D8, unk2DC;
    int unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318;
    Obj430();
    ~Obj430();
};
struct ObjF0
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8;
    ObjF0();
    void SetHandle(Handle h);
};
struct PickTarget
{
    int GetState();
};
struct RefHandle
{
};
struct Setting
{
};
extern const double DAT_01072f98;
struct Projectile
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C;
    int unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C;
    int unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC;
    int unk2C0, unk2C4, unk2C8, unk2CC, unk2D0, unk2D4, unk2D8, unk2DC;
    int unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318, unk31C;
    int unk320, unk324, unk328, unk32C, unk330, unk334, unk338, unk33C;
    int unk340, unk344, unk348, unk34C, unk350, unk354, unk358, unk35C;
    int unk360, unk364, unk368, unk36C, unk370, unk374, unk378, unk37C;
    int unk380, unk384, unk388, unk38C, unk390, unk394, unk398, unk39C;
    int unk3A0, unk3A4, unk3A8, unk3AC, unk3B0, unk3B4, unk3B8, unk3BC;
    int unk3C0, unk3C4, unk3C8, unk3CC, unk3D0, unk3D4, unk3D8, unk3DC;
    int unk3E0, unk3E4, unk3E8, unk3EC, unk3F0, unk3F4, unk3F8, unk3FC;
    int unk400, unk404, unk408, unk40C, unk410, unk414, unk418, unk41C;
    int unk420, unk424, unk428, unk42C, unk430, unk434, unk438, unk43C;
    int unk440, unk444, unk448, unk44C, unk450, unk454, unk458, unk45C;
    int unk460, unk464, unk468, unk46C, unk470, unk474, unk478, unk47C;
    int unk480, unk484, unk488, unk48C, unk490, unk494, unk498, unk49C;
    int unk4A0, unk4A4, unk4A8, unk4AC, unk4B0, unk4B4, unk4B8, unk4BC;
    int unk4C0, unk4C4, unk4C8, unk4CC, unk4D0, unk4D4, unk4D8, unk4DC;
    int unk4E0, unk4E4, unk4E8, unk4EC, unk4F0, unk4F4, unk4F8, unk4FC;
    int unk500, unk504, unk508, unk50C, unk510, unk514, unk518, unk51C;
    int unk520, unk524, unk528, unk52C, unk530, unk534, unk538, unk53C;
    int unk540, unk544, unk548, unk54C, unk550, unk554, unk558, unk55C;
    int unk560, unk564, unk568, unk56C, unk570, unk574, unk578, unk57C;
    int unk580, unk584, unk588, unk58C, unk590, unk594, unk598, unk59C;
    int unk5A0, unk5A4, unk5A8, unk5AC, unk5B0, unk5B4, unk5B8, unk5BC;
    int unk5C0, unk5C4, unk5C8, unk5CC, unk5D0, unk5D4, unk5D8, unk5DC;
    int unk5E0, unk5E4, unk5E8, unk5EC, unk5F0, unk5F4, unk5F8, unk5FC;
    int unk600, unk604, unk608, unk60C, unk610, unk614, unk618, unk61C;
    int unk620, unk624, unk628, unk62C, unk630;
    RefHandle m_634;
    VObj* m_638;
    int m_63c;
    int unk640;
    float m_644;
    void FUN_00960520(int a);
};
// @fnv 0x00960520
void Projectile::FUN_00960520(int a)
{
    if (m_638 == 0 || ((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634)))) == 0 || ((int)(reinterpret_cast<::FUN_0082aeb0_shell *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->FUN_0082aeb0())) == 0)
    {
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(this)->FUN_00961280();
        return;
    }
    PickTarget* pick = ((::fnv_00960520::PickTarget *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (pick != 0 && reinterpret_cast<::FUN_00c6fd20_class *>((pick))->FUN_00c6fd20() == ((int)(reinterpret_cast<::FUN_0082aeb0_shell *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->FUN_0082aeb0())) && ((int)(reinterpret_cast<::FUN_00961260_Class *>((pick))->GetFieldAt608())) == 1)
    {
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(this)->FUN_00961280();
        return;
    }
    float base = 0.0f;
    float speed = m_644 + base;
    Vec3 pos;
    Vec3 dir;
    reinterpret_cast<::fnv_008aff80::ActorStub *>(this)->GetCameraPosAndDir((::fnv_008aff80::Vec3 *)(::fnv_00960520::Vec3 *)(&pos), (::fnv_008aff80::Vec3 *)(::fnv_00960520::Vec3 *)(&dir), true);
    ObjF0 ray;
    VObj* weapon = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_0082aee0_shell *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->FUN_0082aee0()));
    VObj* shooter = ((::fnv_00960520::VObj *)(::FUN_004b5a80(weapon)));
    Handle owner = shooter->GetHandle();
    reinterpret_cast<::FUN_0059ce80_shell *>(&(owner))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::fnv_00960520::Handle2 &)((*reinterpret_cast<::fnv_00960520::VObj * *>(&::_g_thePlayer))->GetHandle2()))->FUN_004a3a20())));
    ray.SetHandle(owner);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0(&pos);
    reinterpret_cast<::Class_007f68a0 *>(&(ray))->FUN_007f68a0((const ::NiPoint3 &)((const ::fnv_00960520::Vec3 &)(dir.Scale(speed))));
    Obj430 hits;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(ray))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::fnv_00960520::Obj430 *)(&hits));
    VObj* world = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_00960520::VObj *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_00960520::VObj * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
    if (world->vTest(&ray))
    {
        float frac = 1.0f;
        for (int i = 0; frac == ::g_01012070 && i < ((int)(reinterpret_cast<::Callees *>((((::fnv_00960520::ItemList *)(::FUN_00460140((int)&(hits))))))->FUN_00726070())); i++)
        {
            Obj4A0 hit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::fnv_00960520::ItemList *)(::FUN_00460140((int)&(hits))))))->GetEntryAt(i))));
            VObj* form = ((::fnv_00960520::VObj *)(::FUN_004b5820((::FormLike *)(hit.iRef))));
            if (form != 0)
            {
                VObj* actor = ((::fnv_00960520::VObj *)(::FUN_0056f930((::NiAVObject *)(form))));
                if (actor != 0 && actor != m_638 && actor != (*reinterpret_cast<::fnv_00960520::VObj * *>(&::_g_thePlayer)))
                {
                    frac = hit.fValue;
                }
            }
        }
        speed = ::FUN_00404010(0.0f, (double)frac * speed - base);
        if (m_63c == 3)
        {
            m_644 = speed;
        }
    }
    if (m_63c == 3)
    {
        ObjF0 ray2;
        ray2.SetHandle(shooter->GetHandle());
        reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray2))->FUN_004a3da0(&pos);
        Vec3 tgt = *((::fnv_00960520::Vec3 *)(new ((void *)(((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_0043d450_Owner *>((m_638->vGet1D0()))->FUN_0043d450())))) ::Vec3()));
        reinterpret_cast<::FUN_004a3eb0_shell *>(&(ray2))->FUN_004a3eb0(&tgt);
        if (((::fnv_00960520::VObj *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_00960520::VObj * *>(&::_g_thePlayer))))->GetTarget())) != 0)
        {
            VObj* world2 = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_00960520::VObj *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_00960520::VObj * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
            if (world2->vTest(&ray2))
            {
                VObj* hitId = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_00c66fb0_Class *>(&(ray2))->FUN_00c66fb0()));
                VObj* hitActor = ((::fnv_00960520::VObj *)(::FUN_0056f930((::NiAVObject *)(hitId))));
                if (hitActor != 0 && m_638 != hitActor && !hitActor->vIsDead())
                {
                    reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(this)->FUN_00961280();
                    return;
                }
            }
        }
    }
    HkVec delta;
    HkVec vel;
    HkVec dirv;
    HkTransform xf;
    reinterpret_cast<::FUN_00961200_Class *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->ApplyToScriptLocals(&dirv);
    reinterpret_cast<::fnv_00961230::FUN_00961230_Class *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->FUN_00961230((::fnv_00961230::T_ *)(::fnv_00960520::HkVec *)(&vel));
    shooter->vGetTransform(&xf);
    delta.SetTransformedPos(&xf, &vel);
    reinterpret_cast<::V *>(&(delta))->FUN_00961190((*(const ::V *)(&dirv)));
    float len = ::FUN_004587d0(reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_00960520::HkVec &)(delta.Delta()))->FUN_004586d0());
    if (m_63c != 3 && len > DAT_01072f98)
    {
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(this)->FUN_00961280();
        return;
    }
    int count = ::FUN_00c9c380((void *)(weapon), {});
    float best = 0.0f;
    for (int j = 0; j < count; j++)
    {
        VObj* item = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_00c9c390_Class *>((weapon))->GetEntry(j)));
        if (item != 0)
        {
            VObj* owner2 = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((item))->FUN_0084e3a0()));
            if (owner2->vGetType() == 0xb)
            {
                VObj* src = (((::fnv_00960520::VObj *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((item))->FUN_00825c00())) == weapon) ? ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_009611e0_shell *>((item))->FUN_009611e0())) : ((::fnv_00960520::VObj *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((item))->FUN_00825c00()));
                if (src != 0 && best < reinterpret_cast<::fnv_004b4ea0::TESDataHandler *>((src))->FUN_004b4ea0())
                {
                    best = reinterpret_cast<::fnv_004b4ea0::TESDataHandler *>((src))->FUN_004b4ea0();
                }
            }
        }
    }
    float ratio = best / reinterpret_cast<::fnv_004b4ea0::TESDataHandler *>((weapon))->FUN_004b4ea0();
    if (len > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::originalRuntimeFloatSetting1056)))))) && ratio > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::originalRuntimeFloatSetting1055)))))))
    {
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(this)->FUN_00961280();
        return;
    }
    VObj* target = m_638->vGet1D0();
    bool flagA = ((int)(::GetBSXFlags((unsigned int)(target), 8))) != 0 ? 1 : 0;
    bool flagB = ((int)(::GetBSXFlags((unsigned int)(target), 0x80))) != 0 ? 1 : 0;
    if (m_638->vIsDead() && reinterpret_cast<::C00624070 *>((void *)&(const ::fnv_00960520::Handle &)(shooter->GetHandle()))->FUN_00624070())
    {
        flagA = false;
        VObj* parent = target->vGet0C();
        if (parent != 0 && ((::fnv_00960520::VObj *)(reinterpret_cast<::NiNode *>((parent))->GetAt(0))) != 0)
        {
            target = ((::fnv_00960520::VObj *)(reinterpret_cast<::NiNode *>((parent))->GetAt(0)));
        }
        VObj* proc = ((::fnv_00960520::VObj *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(weapon))));
        VObj* node = proc ? ((::fnv_00960520::VObj *)(reinterpret_cast<::Twin_0044ddc0 *>((proc))->GetName())) : 0;
        while (node != 0 && node != parent)
        {
            if (node == target)
            {
                flagA = true;
            }
            node = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0()));
        }
    }
    if (target != 0 && flagA && len > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::originalRuntimeFloatSetting1057)))))))
    {
        float force = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::originalRuntimeFloatSetting1058)))))) * (len - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::originalRuntimeFloatSetting1057))))))) / len;
        float fScaledValue = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::g_011d04d8))))));
        float fMin = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00960520::Setting *>(&::originalRuntimeFloatSetting1059))))));
        float scale = ::FUN_0040ebd0(fMin, ::FUN_00404010(fScaledValue, ::FUN_0062c300((::NiAVObject *)(target))));
        float t = ::LinearInterpolate(0.0f, 1.0f, fMin, fScaledValue, scale);
        HkVec mul(force * ::DAT_0101a6b0 * t);
        reinterpret_cast<::S_00627920 *>(&(delta))->FUN_00627920((::S_00561240 *)(::fnv_00960520::HkVec *)(&mul));
        if (flagB || m_638->vIsDead())
        {
            Vec3 imp;
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&imp)), (*(const ::hkVector4 *)(&delta)));
            ::FUN_0062b8d0(target, &imp, 0);
        }
        else
        {
            VObj* body = ((::fnv_00960520::VObj *)(reinterpret_cast<::FUN_0082aee0_shell *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->FUN_0082aee0()));
            if (body != 0)
            {
                VObj* bodyProc = ((::fnv_00960520::VObj *)(::FUN_004b5a80(body)));
                HkVec v;
                reinterpret_cast<::bhkUnaryAction *>(&(v))->Set(reinterpret_cast<::bhkCharacterController *>(&(delta))->GetVectorElement(0), reinterpret_cast<::bhkCharacterController *>(&(delta))->GetVectorElement(1), reinterpret_cast<::bhkCharacterController *>(&(delta))->GetVectorElement(2), 0.0f);
                reinterpret_cast<::V *>(&(v))->FUN_00553f70((*(const ::V *)(((void *)&(::fnv_00560d80::FUN_00560d80((void *)(bodyProc)))))));
                reinterpret_cast<::S *>((bodyProc))->FUN_00561690((int)(&v));
            }
        }
    }
    Vec3 dest = (*(::fnv_00960520::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(pos))->ProjectileLaunched((::NiPoint3 *)&(const ::fnv_00960520::Vec3 &)(dir.Scale(speed)), {})));
    if (pick != 0)
    {
        Vec3 step = dir.Scale(speed);
        if (dir.z < ::_DAT_01012060)
        {
            step.z = 0.0f;
            float horiz = reinterpret_cast<::NiPoint3 *>((void *)&(step))->GetLengthSquared();
            float range = ::FUN_004587d0(reinterpret_cast<::FUN_00c6e280_cls *>((pick))->GetSettingFloat()) + ::DAT_01020998;
            if (horiz < range)
            {
                float extra = range - horiz;
                reinterpret_cast<::FUN_0063c8a0_shell *>(&(dest))->FUN_0063c8a0((void *)&(const ::fnv_00960520::Vec3 &)(step.Scale(extra)));
            }
        }
    }
    reinterpret_cast<::FUN_008c5d90_Class *>((((::fnv_00960520::VObj *)(::FUN_00559450((int *)&(m_634))))))->FUN_008c5d90((const ::NiPoint3Local *)(::fnv_00960520::Vec3 *)(&dest));
}
}  // namespace fnv_00960520

#include "generated/data/fallout/ai/playercharacter_o2_variant_od_oy_noo2_variant.inc"
