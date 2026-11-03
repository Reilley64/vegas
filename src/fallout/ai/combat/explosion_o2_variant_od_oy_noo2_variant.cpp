
// src/fallout/ai/combat/explosion_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/explosion_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/explosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/explosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/Actor9af.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00452370_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00457880_Class.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_00477950_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a3fe0_shell.h"
#include "fnv/decl/FUN_004a40a0_Class.h"
#include "fnv/decl/FUN_004a40c0_Class.h"
#include "fnv/decl/FUN_004a41c0.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004a51b0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004fb7d0_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_006233c0.h"
#include "fnv/decl/FUN_0062e150_cls.h"
#include "fnv/decl/FUN_00632d40_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0068a810_class.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_008aff10_obj.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00c84f10_cls.h"
#include "fnv/decl/FUN_00c86800_Class.h"
#include "fnv/decl/FUN_00c868b0_cls.h"
#include "fnv/decl/FUN_00cbc740.h"
#include "fnv/decl/FnCls.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/ImageSpaceEffectParam.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/Owner623.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S009afc70.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/S819.h"
#include "fnv/decl/S_00c9f1e0_Obj.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Unk.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004a40e0__FUN_004a40e0.h"
#include "fnv/decl/fnv_004a4220__FUN_004a4220Class.h"
#include "fnv/decl/fnv_00623090__Host.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009b00a0__Obj082.h"
#include "fnv/decl/fnv_00c86790__Holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a1000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00689000.h"
#include "fnv/symbols_009b2000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00cbd000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
struct ActorCause
{
};
struct NiPointer
{
    NiPointer& operator=(ActorCause*);
};
struct FUN_009ac170_shell
{
    char m_auiShapeKeys[0xd0];
    NiPointer m_actorCause;
    void FUN_009ac170(ActorCause* apActorCause);
};
struct Explosion
{
    virtual ~Explosion();
    void* Destroy(unsigned int flags);
};
struct NiRTTI;
struct bhkLiquidAction
{
    const NiRTTI* GetRTTI() const;
};
struct NavMesh;
struct NavMeshPtr
{
};
struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
struct BSOcclusionPlane
{
    int IsNotCulled();
};
struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
};
extern "C" void __cdecl FUN_009afbe0(void*);
struct FUN_00621100_shell
{
    void SetVtable(void);
};
struct FUN_009afc10_shell
{
    void FUN_009afc10();
};
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
struct P03MM
{
};
struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00cbc650_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00cbc650_cls
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
    virtual FUN_00cbc650_obj* vGet(FUN_00cbc650_obj* volatile* pp);
    void FUN_00cbc650(FUN_00cbc650_obj* volatile a1);
};
struct FUN_00cbc6a0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
};
struct FUN_00cbc6a0_Class
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void FUN_00cbc6a0(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00cbc6a0_Data* vf45(int* value);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct AutoMemContext
{
    int oldContext;
    AutoMemContext()
    {
        oldContext = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~AutoMemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = oldContext;
    }
};
struct FUN_00cbc550_class
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
    static void* __cdecl operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    FUN_00cbc550_class();
};
struct FUN_00cbca20_class
{
    FUN_00cbc550_class* FUN_00cbca20(int flags);
};

#include <xmmintrin.h>
struct Vec4810;
struct Vec810
{
    float x, y, z;
    Vec810();
    Vec810 operator-(const Vec810&) const;
    Vec810& operator=(const Vec4810&);
};
Vec810 __cdecl FUN_004a3760(float, const Vec810&);
struct Color810
{
    float r, g, b, a;
    Color810(float, float, float, float);
};
struct Hit810;
struct Snapshot810;
struct Query810;
struct Hit810
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    float unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    Hit810(void*);
};
struct __declspec(align(16)) Snapshot810
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    Snapshot810();
    ~Snapshot810();
};
struct HitArray810
{
};
struct HitContainer810
{
    HitArray810* FUN_00460140();
};
struct __declspec(align(16)) Query810
{
    __m128 m_quad000;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    Query810();
    void FUN_004a3f70(unsigned);
};
struct Filter810
{
    unsigned value;
    Filter810(int);
};
struct Setting810
{
};
struct Position810
{
};
struct Object810
{
};
struct Body810
{
};
struct World810
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
    virtual void vc8(Query810*);
};
struct Cell810
{
};
struct Process810
{
};
struct Test810
{
};
struct Actor810
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
    virtual bool v100();
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
    virtual Body810* v1d0();
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
    virtual int v214();
};
struct Vec4810
{
    float x, y, z;
};
struct Array810
{
    Vec4810 ApplyScaled(float);
};
struct Host810
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    Array810 array;
    bool FUN_009b1810(Vec810, Actor810*);
};
struct Debug810
{
};
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3 ApplyScaled(float f) const;
};
// @fnv 0x009b1810
bool Host810::FUN_009b1810(Vec810 pos, Actor810* actor)
{
    Object810* base = ((::Object810 *)(reinterpret_cast<::Actor *>(this)->GetActorBase()));
    if (reinterpret_cast<::FUN_00477950_shell *>((base))->HasAnyFlags(16))
        return true;
    Body810* body = actor ? actor->v1d0() : 0;
    if (actor == (*reinterpret_cast<::Actor810 * *>(&::_g_thePlayer)))
        body = ((::Body810 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::Actor810 * *>(&::_g_thePlayer))))->FUN_00950bb0(0)));
    if (!body || !reinterpret_cast<::NiAVObject *>((body))->IsVisualObject())
        return false;
    World810* world = ((::Cell810 *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget())) ? ((::World810 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell810 *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()))))->FUN_004543c0())) : 0;
    if (!world)
        return false;
    unsigned mask = 0x26206;
    ::ShadowLightData::SetTargetMaskForSelection(39, mask);
    Vec810 points[7];
    points[0] = *((::Vec810 *)(new ((void *)(((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450())))) ::Vec3()));
    bool multiple = false;
    if (actor->v100())
    {
        Actor810* checkActor = actor;
        if (checkActor->v214())
        {
            multiple = true;
            points[1] = points[0];
            points[1].z += reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[2] = points[0];
            points[2].z -= reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[3] = points[0];
            points[3].y += reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[4] = points[0];
            points[4].y -= reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[5] = points[0];
            points[5].x += reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[6] = points[0];
            points[6].x -= reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
        }
    }
    Query810 query;
    Filter810 filter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(39);
    Actor810* checkActor = actor->v100() ? actor : 0;
    if (checkActor && ((::Process810 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((checkActor))->FUN_009306d0())))
        reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80((unsigned int)(((void *)(reinterpret_cast<::S819 *>((((::Process810 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((checkActor))->FUN_009306d0()))))->FUN_00819250()))));
    else
        reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80((unsigned int)(((void *)(::FUN_005dbe10()))));
    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Vec810 &)(pos))->FUN_0063c8a0((void *)&(const ::Vec4810 &)(array.ApplyScaled(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting810 *>(&::originalRuntimeFloatSetting1032)))))))));
    query.FUN_004a3f70(filter.value);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(query))->FUN_004a3da0((void *)&(pos));
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(query))->FUN_004a3eb0((void *)&(points[0]));
    Snapshot810 snapshot;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(query))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Snapshot810 *)(&snapshot));
    bool blocked = false;
    world->vc8(&query);
    for (int i = 0; !blocked && i < ((int)(reinterpret_cast<::Callees *>((((::HitArray810 *)(::FUN_00460140((int)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90()))))))))->FUN_00726070())); i++)
    {
        Hit810 hit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray810 *)(::FUN_00460140((int)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90()))))))))->GetEntryAt(i))));
        Vec810 dir = points[0] - pos;
        Vec810 delta = FUN_004a3760(hit.unk10, dir);
        if (!(*reinterpret_cast<::FUN_004a51b0_shell *>(&(array))->FUN_004a51b0(2) < -0.98) || !(((double)(reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude())) < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting810 *>(&::originalRuntimeFloatSetting1029))))))))
        {
            if (!((::Test810 *)(reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8())) || !reinterpret_cast<::FUN_00452370_shell *>((((::Test810 *)(reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8()))))->FUN_00452370())
            {
                if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting810 *>(&::g_011d0a78)))))) > 0)
                    ::FUN_005b5e40();
                blocked = true;
            }
        }
    }
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting810 *>(&::g_011d0a78)))))) > 0)
    {
        Color810 color = blocked ? Color810(1, 0, 0, 1) : Color810(0, 1, 0, 1);
        void* line = ((void *)(::fnv_004b3890::FUN_004b3890((const class ::FUN_006815c0 &)(pos), (const ::fnv_004b3890::FUN_004a7800 &)(color), (const class ::FUN_006815c0 &)(points[0]), (const ::fnv_004b3890::FUN_004a7800 &)(color), 1)));
        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Debug810 * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(line), 25.0f);
    }
    if (multiple && blocked)
    {
        for (int i = 1; blocked && i < 7; i++)
        {
            blocked = false;
            Snapshot810 snapshot;
            reinterpret_cast<::FUN_004a3fb0_shell *>(&(query))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Snapshot810 *)(&snapshot));
            reinterpret_cast<::FUN_004a3eb0_shell *>(&(query))->FUN_004a3eb0((void *)&(points[i]));
            world->vc8(&query);
            for (int j = 0; !blocked && j < ((int)(reinterpret_cast<::Callees *>((((::HitArray810 *)(::FUN_00460140((int)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90()))))))))->FUN_00726070())); j++)
            {
                Hit810 hit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray810 *)(::FUN_00460140((int)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90()))))))))->GetEntryAt(j))));
                Vec810 dir = points[j] - pos;
                Vec810 delta = FUN_004a3760(hit.unk10, dir);
                if (!(*reinterpret_cast<::FUN_004a51b0_shell *>(&(array))->FUN_004a51b0(2) < -0.98) || !(((double)(reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude())) < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting810 *>(&::originalRuntimeFloatSetting1029))))))))
                    blocked = true;
            }
        }
    }
    return !blocked;
}

struct Color4
{
    float r, g, b, a;
};

struct Color3
{
    float r, g, b;
};

struct Ptr4
{
    void* p;
};

struct Setting
{
};
extern int g_dummy;

struct FloatSetting
{
};

struct __declspec(align(16)) Elem70
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    void* unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    Vec3* FUN_00460140();
};

struct HitInfo
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    int unk20[8];
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    Ptr4* unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
};

struct HitArray
{
    HitArray* FUN_00460140();
};

struct HitHolder
{
    HitArray* FUN_00460140();
};

struct Flag1
{
    char c;
};

struct Flag1Ptr
{
};

struct ResList
{
    void* p0;
    int i4;
    int i8;
    int iC;
    ResList(int v);
    ~ResList();
};

struct ProjList
{
    void* p0;
    int i4;
    int i8;
    int iC;
    int i10;
    int i14;
    ProjList(void* a, int b);
    ~ProjList();
};

struct Shape
{
};

struct Drawer
{
};

struct Params
{
    Vec3 unk00;
    Vec3 unk0C;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    void* unk28;
    int unk2C;
    void* unk30;
    int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    int unk48;
    float unk4C;
    int unk50;
    float unk54;
    float unk58;
    int unk5C;
    Color3 unk60;
    int unk6C;
    char unk70;
    char unk71;
    char unk72;
    char unk73;
    char unk74;
    char unk75;
    char unk76;
    char unk77;
    int unk78;
    int unk7C;
    Params();
};

struct Mgr
{
};

struct Wrap4
{
    int v;
};

struct RefObj
{
    virtual void vf00();
};

struct Hand4
{
    void* p;
};
struct Hand8
{
    void* p;
    int i;
};

struct Sub
{
};

struct Proc
{
    virtual void vf00();
};

struct Owner
{
    virtual void vf00();
};

struct VTbl;

struct NodeRef
{
    unsigned int unk00;
    unsigned int unk04;
    RefObj* unk08;
    int unk0C;
};

struct NodeList
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    NodeList();
    ~NodeList();
};

struct Query
{
};

struct NameHolder
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual char* GetName();
};

struct Weap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    NameHolder unk18;
    void* FUN_006733e0();
    char FUN_004a4140();
    char CallMemberAtOffset54();
    char FUN_004a4100();
    char FUN_004a41e0();
};

struct SndSrc
{
};

struct Snd
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ~Snd();
};

struct WeapHolder
{
};

struct Picker
{
    virtual void vf00();
};

struct Proc2
{
};

struct Big4c0
{
    unsigned int unk00;
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
    unsigned int unk30;
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
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    Big4c0();
    ~Big4c0();
};

struct __declspec(align(16)) Big570
{
    __m128 quad00;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
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
    Big570();
    void FUN_004a3f70(void* p);
};

struct PlayerX
{
};

struct Cell
{
    Hand4* FUN_0043b4f0(Hand4* out);
};

struct CellPtr
{
    void* p;
};

Vec3 __cdecl FUN_004a3760(float f, const Vec3& v);
extern "C" bool __cdecl FUN_004b61d0(Vec3 p, PlayerX* pl, float f);
extern "C" float __cdecl FUN_00406cc0(float a);
extern "C" Sub* __cdecl FUN_00c85ef0(Hand8* out, void* a, void* b);
struct AudioMgr
{
    Snd FUN_00ad7480(void* a, SndSrc* b);
};

struct ProjCls
{
    virtual void vf00();
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
    unsigned int unk30;
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
    CellPtr unkA0;
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
    bool unkD4;
    bool unkD5;
    bool unkD6;
    bool unkD7;
    bool unkD8;
    bool unkD9;
    unsigned short unkDA;
    unsigned int unkDC;
    unsigned int unkE0;
    int unkE4;
    Vec3 unkE8;
    Vec3 unkF4;
    void FUN_009ae6e0();
};

struct ProjVt
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
    virtual bool IsDead();
};

struct PickVt
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
    virtual bool Pick(Big570* p);
    virtual Owner* GetOwner();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int GetId(int i);
};

struct SelfVt
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
    virtual Vec3* GetPos();
};

// @fnv 0x009ae6e0
void ProjCls::FUN_009ae6e0()
{
    if (((::Cell *)(::FUN_00559450((int *)&(unkA0)))) == 0)
        return;
    if (unkE4 > 0 && unkD6 && !unkD7)
        reinterpret_cast<::Actor9af *>(this)->FUN_009afef0();
    if (unkD5 && !unkD4)
    {
        unkD4 = 1;
        ResList res(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d10a4)))))));
        ProjList list(((void *)(::FUN_00559450((int *)&(res)))), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d10a4)))))));
        ::FUN_00cbd960();
        reinterpret_cast<::S_00c9f1e0_Obj *>((((::Cell *)(::FUN_00559450((int *)&(unkA0))))))->FUN_00c9f1e0((::S_00c9f1e0_Range *)(::ProjList *)(&list));
        Flag1 fl;
        if (reinterpret_cast<::FUN_005609f0_shell *>((((::Flag1Ptr *)(reinterpret_cast<::S009afc70 *>(&(list))->FUN_009afc70(&fl)))))->FUN_005609f0())
            ::FUN_009b2e00(((void *)(::FUN_00559450((int *)&(res)))), ((int)(reinterpret_cast<::FUN_009afc50_shell *>(&(list))->FUN_009afc30())));
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d0a78)))))) > 1)
        {
            for (int i = 0; i < ((int)(reinterpret_cast<::FUN_009afc50_shell *>(&(list))->FUN_009afc30())); i++)
            {
                Elem70 e;
                reinterpret_cast<::FUN_00632d40_shell *>(&(e))->FUN_00632d40((*(const ::FUN_00632d40_shell *)(((::Elem70 *)(reinterpret_cast<::FUN_009afc30_shell *>(&(list))->FUN_009afc30())) + i)));
                Vec3 a;
                ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&a)), (*(const ::hkVector4 *)(new ((void *)&(e)) ::Vec3())));
                Vec3 b;
                ::FUN_004a3970((*(::NiPoint3_local *)(&b)), (*(const ::hkVector4 *)(((::Vec3 *)(::FUN_00460140((int)&(e)))))));
                Color4 c;
                new ((void *)&(c)) ::ImageSpaceEffectParam(1.0f, 0.0f, 0.0f, ::g_011d86d4_arg1);
                Shape* s = ((::Shape *)(::CreateOctahedron(::DAT_01016088, (const struct ::FUN_004a7800 *)(const ::Color4 *)(&c), 1)));
                reinterpret_cast<::FUN_00a5a040_Class *>((s))->FUN_00a5a040();
                reinterpret_cast<::FUN_00440460_S *>((s))->FUN_00440460((const ::V3 *)(const ::Vec3 *)(&a));
                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
                s = ((::Shape *)(::fnv_004b3890::FUN_004b3890((*(const class class ::FUN_006815c0 *)(&a)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), (*(const class class ::FUN_006815c0 *)(&(*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(a))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(b.ApplyScaled(::DAT_01017b78)), {}))))), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), 1)));
                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
            }
        }
        bool done = false;
        for (int j = 0; !done && j < ((int)(reinterpret_cast<::FUN_009afc50_shell *>(&(list))->FUN_009afc30())); j++)
        {
            Elem70 e;
            reinterpret_cast<::FUN_00632d40_shell *>(&(e))->FUN_00632d40((*(const ::FUN_00632d40_shell *)(((::Elem70 *)(reinterpret_cast<::FUN_009afc30_shell *>(&(list))->FUN_009afc30())) + j)));
            if (e.unk48)
            {
                void* r = ((void *)(::FUN_004b5820((::FormLike *)(e.unk48))));
                Proc* u = ((::Proc *)(::FUN_0056f930((::NiAVObject *)(r))));
                if (!u || !((ProjVt*)u)->IsDead())
                {
                    Vec3 pos;
                    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&pos)), (*(const ::hkVector4 *)(new ((void *)&(e)) ::Vec3())));
                    Vec3 dir;
                    ::FUN_004a3970((*(::NiPoint3_local *)(&dir)), (*(const ::hkVector4 *)(((::Vec3 *)(::FUN_00460140((int)&(e)))))));
                    Big4c0 q;
                    Big570 p;
                    Vec3 v = *((SelfVt*)this)->GetPos();
                    Vec3 w = FUN_004a3760(::DAT_010162c0, (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(pos))->FUN_00439ef0((::NiPoint3 *)&(v), *(const ::NiPoint3 *)nullptr))));
                    if (((double)(reinterpret_cast<::NiPoint3 *>((void *)&(w))->ComputeMagnitude())) < ::g_01012070)
                    {
                        reinterpret_cast<::NiPoint3 *>(&(v))->Subtract((const ::NiPoint3 &)((const ::Vec3 &)(dir.ApplyScaled(::g_011c9040_arg1))));
                        w = dir.ApplyScaled(::g_011db514_arg1);
                    }
                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(p))->FUN_004a3da0((void *)(&v));
                    reinterpret_cast<::Class_007f68a0 *>(&(p))->FUN_007f68a0((*(const ::NiPoint3 *)(&w)));
                    Hand4 h4;
                    p.FUN_004a3f70(((::Cell *)(::FUN_00559450((int *)&(unkA0))))->FUN_0043b4f0(&h4)->p);
                    reinterpret_cast<::FUN_004a3fb0_shell *>(&(p))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Big4c0 *)(&q));
                    int target = 0x24;
                    bool found = false;
                    if (((::Picker *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
                    {
                        Picker* pk = ((::Picker *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                        if (((PickVt*)pk)->Pick(&p))
                        {
                            bool stop = false;
                            for (int k = 0; !found && !stop && k < ((int)(reinterpret_cast<::Callees *>((((::HitArray *)(::FUN_00460140((int)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(p))->FUN_008cdd90()))))))))->FUN_00726070()));
                                 k++)
                            {
                                HitInfo h;
                                reinterpret_cast<::S50 *>(&(h))->FUN_00696c30((::S50 *)(((::HitInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((int)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(p))->FUN_008cdd90()))))))))->GetEntryAt(k)))));
                                void* r2 = ((void *)(::FUN_004b5820((::FormLike *)(h.unk50))));
                                Proc* u2 = ((::Proc *)(::FUN_0056f930((::NiAVObject *)(r2))));
                                if (r == r2)
                                {
                                    found = true;
                                    int last = -1;
                                    for (int m = 0; m < 8 && h.unk20[m] != -1; m++)
                                        last = h.unk20[m];
                                    Wrap4 wr;
                                    bool isActor =
                                        ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::Wrap4 *)(new ((void *)&(wr)) ::GlobalObject_008c71b0((int)(((void *)(::FUN_0043b540((char *)(((RefObj*)h.unk50)))))))))))->FUN_004a3a20())) == 1;
                                    if (isActor)
                                    {
                                        target = ((int)(reinterpret_cast<::FUN_00457880_Class *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00457880((int)(&pos))));
                                    }
                                    else
                                    {
                                        Owner* ow = ((::Owner *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(h.unk50))))))));
                                        if (ow)
                                            target = reinterpret_cast<::FUN_00c84f10_cls *>((ow))->FUN_00c84f10(last);
                                    }
                                }
                                else if (!u2 || !((ProjVt*)u2)->IsDead())
                                {
                                    stop = true;
                                }
                            }
                        }
                    }
                    if (found)
                    {
                        unkE8 = pos;
                        if (reinterpret_cast<::NiPoint3 *>((void *)&(unkF4))->FUN_004390c0((*(const ::NiPoint3 *)(&(*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO))))))
                            unkF4 = dir;
                        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d0a78)))))) > 1)
                        {
                            Color4 c;
                            new ((void *)&(c)) ::ImageSpaceEffectParam(0.0f, 1.0f, 0.0f, ::g_011d86d4_arg1);
                            Shape* s = ((::Shape *)(::CreateOctahedron(::DAT_0101712c, (const struct ::FUN_004a7800 *)(const ::Color4 *)(&c), 1)));
                            reinterpret_cast<::FUN_00a5a040_Class *>((s))->FUN_00a5a040();
                            reinterpret_cast<::FUN_00440460_S *>((s))->FUN_00440460((const ::V3 *)(const ::Vec3 *)(&unkE8));
                            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
                            s = ((::Shape *)(::fnv_004b3890::FUN_004b3890((*(const class class ::FUN_006815c0 *)(&unkE8)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), (*(const class class ::FUN_006815c0 *)(&(*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(unkE8))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(unkF4.ApplyScaled(::DAT_01017868)), {}))))), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), 1)));
                            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
                        }
                        done = true;
                        Weap* wt = ((::Weap *)(reinterpret_cast<::FUN_004fb7d0_shell *>((((::WeapHolder *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fb7d0({})));
                        if (wt)
                        {
                            bool flag = true;
                            Vec3 dd = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(pos))->FUN_00439ef0((::NiPoint3 *)&(*((::Vec3 *)(::FUN_0045bb80((int)(((::PlayerX *)(::FUN_00524c90()))))))), *(const ::NiPoint3 *)nullptr)));
                            if (((bool)(::FUN_00525420())) || ((double)(reinterpret_cast<::NiPoint3 *>((void *)&(dd))->ComputeMagnitude())) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting642)))))) ||
                                !FUN_004b61d0(pos, ((::PlayerX *)(::FUN_00524c90())), ::g_011db514_arg1))
                                flag = false;
                            void* proj = wt->FUN_006733e0();
                            if (proj)
                            {
                                float spd = ::RandomFloat(reinterpret_cast<::FUN_004a40a0_Class *>((wt))->FUN_004a40a0(), reinterpret_cast<::FUN_004a40c0_Class *>((wt))->GetModifierValue());
                                Query* qq = ((::Query *)(::ScreenSplatter::Activate(spd, 1)));
                                reinterpret_cast<::FUN_006233c0 *>((qq))->GetImpactDataForMaterial(0);
                                reinterpret_cast<::Unk *>((qq))->FUN_004a1a10(8, 0);
                                reinterpret_cast<::Unk *>((qq))->FUN_004a1a10(0x1d, 0);
                                Proc2* p2 = ((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
                                Picker* t = p2 ? ((::Picker *)(reinterpret_cast<::FUN_004543c0_cls *>((p2))->FUN_004543c0())) : 0;
                                if (t)
                                {
                                    reinterpret_cast<::Owner623 *>((qq))->FUN_006231a0((::NiNode623 *)(t));
                                    NodeList nl;
                                    reinterpret_cast<::fnv_00623090::Host *>((qq))->FUN_00623090((void *)(&pos), (::fnv_00623090::Vir *)(::NodeList *)(&nl));
                                    int n = ((int)(reinterpret_cast<::Callees *>((((::NodeList *)(reinterpret_cast<::TESTopicInfoData *>(&(nl))->GetLinkToList()))))->FUN_00726070()));
                                    float fade = ((float)(::FUN_004a4240()));
                                    char cc = (char)FUN_00406cc0(::RandomFloat(0.0f, ::DAT_0101e570));
                                    for (int k = 0; k < n; k++)
                                    {
                                        RefObj* ref = ((::NodeRef *)(reinterpret_cast<::FUN_0062e150_cls *>((((::NodeList *)(reinterpret_cast<::TESTopicInfoData *>(&(nl))->GetLinkToList()))))->FUN_0062e150(k)))->unk08;
                                        if (ref)
                                        {
                                            int id = target;
                                            int idx = ((::NodeRef *)(reinterpret_cast<::FUN_0062e150_cls *>((((::NodeList *)(reinterpret_cast<::TESTopicInfoData *>(&(nl))->GetLinkToList()))))->FUN_0062e150(k)))->unk0C;
                                            if (idx != -1)
                                            {
                                                Owner* ow = ((::Owner *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(ref))))))));
                                                if (!ow)
                                                    continue;
                                                Owner* o2 = ((PickVt*)ow)->GetOwner();
                                                if (o2)
                                                    id = ((PickVt*)o2)->GetId(idx);
                                            }
                                            else
                                            {
                                                Owner* ow = ((::Owner *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(ref))))))));
                                                if (!ow)
                                                    continue;
                                                id = reinterpret_cast<::FUN_006205a0_Class *>((ow))->FUN_006205a0();
                                            }
                                            if (id == target)
                                            {
                                                Wrap4 wr;
                                                bool isActor =
                                                    ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::Wrap4 *)(new ((void *)&(wr)) ::GlobalObject_008c71b0((int)(((void *)(::FUN_0043b540((char *)(ref))))))))))->FUN_004a3a20())) == 1;
                                                Sub* node = 0;
                                                if (isActor)
                                                {
                                                    void* a = ::FUN_004b59f0(ref);
                                                    if (a)
                                                    {
                                                        Hand8 hh;
                                                        node = (Sub*)((void *)(::FUN_00559450((int *)(FUN_00c85ef0(&hh, a, &(*reinterpret_cast<int *>(&::g_011f4a20)))))));
                                                        if (node && reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0())
                                                            node = (Sub*)reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0();
                                                    }
                                                }
                                                else
                                                {
                                                    node = ((::Sub *)(::FUN_00c7fa90((::S_Obj *)(ref))));
                                                }
                                                Proc* u3 = ((::Proc *)(::FUN_0056f930((::NiAVObject *)(node))));
                                                if (!isActor && (!u3 || !::IsAcousticSpaceFormTypeAllowed((::Refr_C *)(u3), 1)))
                                                    continue;
                                                Mgr* mg = ((::Mgr *)(reinterpret_cast<::FnCls *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_004519d0((*(float *)&(const ::Vec3 &)(pos)), {}, {})));
                                                Params prm;
                                                prm.unk00 = unkE8;
                                                prm.unk0C = unkF4;
                                                prm.unk38 = spd;
                                                prm.unk3C = spd;
                                                prm.unk40 = reinterpret_cast<::FUN_008aff10_obj *>((wt))->GetNestedValue();
                                                prm.unk28 = node;
                                                prm.unk30 = proj;
                                                prm.unk44 = fade;
                                                prm.unk70 = cc;
                                                prm.unk75 = wt->FUN_004a4140();
                                                prm.unk74 = wt->CallMemberAtOffset54();
                                                prm.unk73 = wt->FUN_004a4100();
                                                prm.unk4C = reinterpret_cast<::FUN_004a41c0 *>((wt))->GetRadius();
                                                prm.unk76 = wt->FUN_004a41e0();
                                                prm.unk54 = reinterpret_cast<::fnv_004a40e0::FUN_004a40e0 *>((wt))->GetHealthRegeneration();
                                                prm.unk58 = reinterpret_cast<::BGSImpactData *>((wt))->FUN_009a9350();
                                                Color3 col;
                                                prm.unk60 = *((::Color3 *)(reinterpret_cast<::FUN_00416870_t *>(&(col))->FUN_00416870(
                                                    (float)(((unsigned char)((reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((wt))->GetNextFromSubobject()) & 0xff)) / ::DAT_0101e568),
                                                    (float)(((unsigned char)((((unsigned short)(reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((wt))->GetNextFromSubobject())) >>
                                                                              8) &
                                                                             0xff)) /
                                                            ::DAT_0101e568),
                                                    (float)(((unsigned char)(((reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((wt))->GetNextFromSubobject()) >> 16) & 0xff)) /
                                                            ::DAT_0101e568))));
                                                reinterpret_cast<::FUN_004a3fe0_shell *>((mg))->FUN_004a3fe0(&prm, 1, 0);
                                            }
                                        }
                                    }
                                    qq = 0;
                                }
                            }
                            if (flag && !unkD9)
                            {
                                char* name = wt->unk18.GetName();
                                if (name && *name)
                                {
                                    Vec3 dv;
                                    switch (((int)(reinterpret_cast<::BGSCameraPath *>((wt))->GetPrevPath())))
                                    {
                                    case 0:
                                        dv = dir;
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(dv))->FUN_004a0c10();
                                        break;
                                    case 1:
                                        dv = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((SelfVt*)this)->GetPos()))->FUN_00439ef0((::NiPoint3 *)&(pos), *(const ::NiPoint3 *)nullptr)));
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(dv))->FUN_004a0c10();
                                        break;
                                    case 2: {
                                        Vec3 a = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((SelfVt*)this)->GetPos()))->FUN_00439ef0((::NiPoint3 *)&(pos), *(const ::NiPoint3 *)nullptr)));
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(a))->FUN_004a0c10();
                                        Vec3 b = dir;
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(b))->FUN_004a0c10();
                                        dv = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::Vec3 &)(FUN_004a3760((float)(reinterpret_cast<::FUN_004b6190_shell *>((void *)&(b))->DotProduct((void *)&(a)) * ::DAT_01011590), b)))->FUN_00439ef0((::NiPoint3 *)&(a), *(const ::NiPoint3 *)nullptr)));
                                        break;
                                    }
                                    default:
                                        dv = dir;
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(dv))->FUN_004a0c10();
                                        break;
                                    }
                                    ::FUN_006890b0((::World *)(void *)(((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), reinterpret_cast<::FUN_00508100_shell *>((wt))->FUN_00508100(), (int)(name), dv, pos, 1.0f, 7, 0);
                                }
                            }
                            SndSrc* s1 = ((::SndSrc *)(reinterpret_cast<::FUN_0068a810_class *>((wt))->GetField4C()));
                            if (s1)
                            {
                                Snd snd = ((::AudioMgr *)(::FUN_00453a70()))->FUN_00ad7480(((void *)(::FUN_00511840((char *)(s1)))), s1);
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(snd))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd))->FUN_00ad8830(0);
                            }
                            SndSrc* s2 = ((::SndSrc *)(reinterpret_cast<::FUN_0068a830_shell *>((wt))->GetGrass()));
                            if (s2)
                            {
                                Snd snd = ((::AudioMgr *)(::FUN_00453a70()))->FUN_00ad7480(((void *)(::FUN_00511840((char *)(s2)))), s2);
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(snd))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd))->FUN_00ad8830(0);
                            }
                        }
                    }
                }
            }
        }
        if (unkD5 && !unkD6)
            reinterpret_cast<::fnv_009b00a0::Obj082 *>(this)->ProcessHits();
    }
}
