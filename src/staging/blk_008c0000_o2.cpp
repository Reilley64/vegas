
// src/staging/blk_008c0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "../../include/layout_support.h"
#include <cstdint>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_00894d60_shell.h"
#include "fnv/decl/FUN_008a50f0_class.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/MyActor008A5300.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008a50d0__bhkCharacterController.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00cb9000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01085000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/CastingCheck.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00457880_Class.h"
#include "fnv/decl/FUN_004610f0_Class.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004f9bf0_shell.h"
#include "fnv/decl/FUN_005532a0_cls.h"
#include "fnv/decl/FUN_0081f1e0_Class.h"
#include "fnv/decl/FUN_008c5df0_Class.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_008d0200_Class.h"
#include "fnv/decl/FUN_008d0220_class.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/Object.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkRigidBody_2.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0062a000.h"
#include "fnv/symbols_009c6000.h"
#include "fnv/symbols_009ee000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011e0000.h"

// 'sub ecx,0x410; jmp FUN_008d1130' == MSVC adjustor thunk (11 bytes, thiscall).
// Derived overrides a virtual that both of its bases declare, so the second base's
// vtable gets a thunk that moves `this` back by the first base's size (0x410).
struct PrimaryBase
{
    virtual void FUN_008d1550();
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
};

struct SecondaryBase
{
    virtual void FUN_008d1550();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x008d1550
    virtual void FUN_008d1550();
};

Derived::Derived()
{}

struct FUN_004a3c90
{
    __m128 value;
    FUN_004a3c90(const FUN_004a3c90*);
};

class NiUpdateData
{
  public:
    float time;
    bool updateControllers, threaded, unk06, unk07, unk08;
    unsigned char unk09, unk0a, unk0b;
    NiUpdateData(float, bool, bool);
};

struct hkVector4
{
    __m128 value;
    hkVector4();
};

class ThreeByThreeMatrix;

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator*(float) const;
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    static const ::NiPoint3 ZERO;
    NiPoint3& operator*=(float fScalar);
    float ComputeMagnitude() const;
};

class ThreeByThreeMatrix
{
  public:
    float elements[3][3];
    ThreeByThreeMatrix();
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
public:
    bool Inverse(::ThreeByThreeMatrix &);
};

class NiTransform
{
  public:
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
    NiTransform();
    NiPoint3 FUN_00524c40(const NiPoint3&) const;
public:
    void CalculateInverse(::NiTransform &);
};

// Aligned sphere: xyz center and radius in one SIMD vector.
class __declspec(align(16)) FUN_006240d0
{
  public:
    __m128 centerAndRadius;
    FUN_006240d0();
};

struct Ref8;

struct Node8;

struct Form8;

struct Controller8;

struct Link8;

struct Material8;

struct Node8
{
    NiPoint3 FUN_004b4500(const NiPoint3&);
};

struct Form8
{
};

struct Link8
{
};

struct Material8
{
};

struct Controller8
{
};

struct FUN_008cc6f0
{
    int mode;
    NiPoint3 target, end, direction;
    Ref8* victim;
    Node8* node;
    ThreeByThreeMatrix rotation;
    FUN_008cc6f0();
};

struct Ref8
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
    virtual void v100();
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
    virtual void v190(void*, int, int);
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
    virtual Node8* v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual bool v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int);
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
    virtual float v2bc(int);
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
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual bool v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual Controller8* v428();

    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    FUN_008cc6f0* state;
    int active;
    unsigned int unk090;
    unsigned int unk094;
    float angle;
    unsigned int unk09c;
    unsigned int unk0a0;
    Ref8* actor;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned char unk0c0;
    bool requested;
    unsigned short unk0c2;
    void FUN_008d0020(NiPoint3, NiPoint3, Link8*);
    void FUN_008cba30(const NiPoint3*, const NiPoint3*, Ref8*);
};

struct FloatSetting8
{
};

struct IntSetting8
{
};

struct NiPoint3Local
{
    float x, y, z;
};

struct hkVector4D90
{
    unsigned char m_packedComponents[16];
};

class FUN_008c5d90_Class
{
  public:
    void FUN_008c5d90(const NiPoint3Local* source);
};

// @fnv 0x008c5d90
void FUN_008c5d90_Class::FUN_008c5d90(const NiPoint3Local* source)
{
    __declspec(align(16)) hkVector4D90 vector;
    reinterpret_cast<::FUN_008c5df0_Class *>(this)->FUN_008c5df0(((::hkVector4D90 *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vector)), (*(const ::fnv_004a3e00::NiPoint3 *)(source))))));
}

struct __declspec(align(16)) Rotation_8cc740
{
    char m_acRotationData[16];
    Rotation_8cc740(const char* pcName);
};

struct ProjectionData_8cc740
{
    int m_iFadeIndex;
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
    NiPoint3 m_kValue;
    int m_iArrayLength;
    int m_iFlags;
    ThreeByThreeMatrix m_kRotationMatrix;
    ProjectionData_8cc740();
};

struct Source_8cc740
{
};

struct Transform_8cc740
{
    NiPoint3 FUN_004b4500(const NiPoint3& kPt);
};

struct Node_8cc740
{
};

struct Listener_8cc740;

struct ListenerHost_8cc740
{
    int unk000, unk004, unk008, unk00c, unk010, unk014;
};

struct ListenerHost30_8cc740
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
};

struct Listener_8cc740
{
    int unk00;
};

struct Emitter18_8cc740 : ListenerHost_8cc740, Listener_8cc740
{
};

struct Emitter30_8cc740 : ListenerHost30_8cc740, Listener_8cc740
{
};

class Sink_8cc740
{
  public:
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void Attach(Listener_8cc740* pkListener);
    virtual void s044();
    virtual void SetActive(int iActive);
};

class Effect_8cc740
{
  public:
};

class Controller_8cc740
{
  public:
    virtual void c000();
    virtual void c004();
    virtual void c008();
    virtual void c00c();
    virtual void c010();
    virtual void c014();
    virtual void c018();
    virtual void c01c();
    virtual void c020();
    virtual void c024();
    virtual void c028();
    virtual void c02c();
    virtual void c030();
    virtual void c034();
    virtual void c038();
    virtual void c03c();
    virtual void c040();
    virtual void c044();
    virtual void c048();
    virtual void c04c();
    virtual void c050();
    virtual void c054();
    virtual void c058();
    virtual void c05c();
    virtual void c060();
    virtual void c064();
    virtual void c068();
    virtual void c06c();
    virtual void c070();
    virtual void c074();
    virtual void c078();
    virtual void c07c();
    virtual void c080();
    virtual void c084();
    virtual void c088();
    virtual void c08c();
    virtual void c090();
    virtual void c094();
    virtual void c098();
    virtual void c09c();
    virtual void c0a0();
    virtual void c0a4();
    virtual void c0a8();
    virtual void c0ac();
    virtual void c0b0();
    virtual void c0b4();
    virtual void c0b8();
    virtual void c0bc();
    virtual void c0c0();
    virtual void c0c4();
    virtual void c0c8();
    virtual void c0cc();
    virtual void c0d0();
    virtual void c0d4();
    virtual void c0d8();
    virtual void c0dc();
    virtual void c0e0();
    virtual void c0e4();
    virtual void c0e8();
    virtual void c0ec();
    virtual void c0f0();
    virtual void c0f4();
    virtual void c0f8();
    virtual void c0fc();
    virtual void c100();
    virtual void c104();
    virtual void c108();
    virtual void c10c();
    virtual void c110();
    virtual void c114();
    virtual void c118();
    virtual void c11c();
    virtual void c120();
    virtual void c124();
    virtual void c128();
    virtual void c12c();
    virtual void c130();
    virtual void c134();
    virtual void c138();
    virtual void c13c();
    virtual void c140();
    virtual void c144();
    virtual void c148();
    virtual void c14c();
    virtual void c150();
    virtual void c154();
    virtual void c158();
    virtual void c15c();
    virtual void c160();
    virtual void c164();
    virtual void c168();
    virtual void c16c();
    virtual void c170();
    virtual void c174();
    virtual void c178();
    virtual void c17c();
    virtual void c180();
    virtual void c184();
    virtual void c188();
    virtual void c18c();
    virtual void c190();
    virtual void c194();
    virtual void c198();
    virtual void c19c();
    virtual void c1a0();
    virtual void c1a4();
    virtual void c1a8();
    virtual void c1ac();
    virtual void c1b0();
    virtual void c1b4();
    virtual void c1b8();
    virtual void c1bc();
    virtual void c1c0();
    virtual void c1c4();
    virtual void c1c8();
    virtual void c1cc();
    virtual void c1d0();
    virtual void c1d4();
    virtual void c1d8();
    virtual void c1dc();
    virtual void c1e0();
    virtual void c1e4();
    virtual void c1e8();
    virtual void c1ec();
    virtual void c1f0();
    virtual void c1f4();
    virtual void c1f8();
    virtual void c1fc();
    virtual void c200();
    virtual void c204();
    virtual void c208();
    virtual void c20c();
    virtual void c210();
    virtual void c214();
    virtual void c218();
    virtual void c21c();
    virtual void c220();
    virtual void c224();
    virtual void c228();
    virtual void c22c();
    virtual void c230();
    virtual void c234();
    virtual void c238();
    virtual void c23c();
    virtual void c240();
    virtual void c244();
    virtual void c248();
    virtual void c24c();
    virtual void c250();
    virtual void c254();
    virtual void c258();
    virtual void c25c();
    virtual void c260();
    virtual void c264();
    virtual void c268();
    virtual void c26c();
    virtual void c270();
    virtual void c274();
    virtual void c278();
    virtual void c27c();
    virtual void c280();
    virtual void c284();
    virtual void c288();
    virtual void c28c();
    virtual void c290();
    virtual void c294();
    virtual void c298();
    virtual void c29c();
    virtual void c2a0();
    virtual void c2a4();
    virtual void c2a8();
    virtual void c2ac();
    virtual void c2b0();
    virtual void c2b4();
    virtual void c2b8();
    virtual void c2bc();
    virtual void c2c0();
    virtual void c2c4();
    virtual void c2c8();
    virtual void c2cc();
    virtual void c2d0();
    virtual void c2d4();
    virtual void c2d8();
    virtual void c2dc();
    virtual void c2e0();
    virtual void c2e4();
    virtual void c2e8();
    virtual void c2ec();
    virtual void c2f0();
    virtual void c2f4();
    virtual void c2f8();
    virtual void c2fc();
    virtual void c300();
    virtual void c304();
    virtual void c308();
    virtual void c30c();
    virtual void c310();
    virtual void c314();
    virtual void c318();
    virtual void c31c();
    virtual void c320();
    virtual void c324();
    virtual void c328();
    virtual void c32c();
    virtual void c330();
    virtual void c334();
    virtual void c338();
    virtual void c33c();
    virtual void c340();
    virtual void c344();
    virtual void c348();
    virtual void c34c();
    virtual void c350();
    virtual void c354();
    virtual void c358();
    virtual void c35c();
    virtual void c360();
    virtual void c364();
    virtual void c368();
    virtual void c36c();
    virtual void c370();
    virtual void c374();
    virtual void c378();
    virtual void c37c();
    virtual void c380();
    virtual void c384();
    virtual void c388();
    virtual void c38c();
    virtual void c390();
    virtual void c394();
    virtual void c398();
    virtual void c39c();
    virtual void c3a0();
    virtual void c3a4();
    virtual void c3a8();
    virtual void c3ac();
    virtual void c3b0();
    virtual void c3b4();
    virtual void c3b8();
    virtual void c3bc();
    virtual void c3c0();
    virtual void c3c4();
    virtual void c3c8();
    virtual void c3cc();
    virtual void c3d0();
    virtual void c3d4();
    virtual void c3d8();
    virtual void c3dc();
    virtual void c3e0();
    virtual void c3e4();
    virtual void c3e8();
    virtual void c3ec();
    virtual void c3f0();
    virtual void c3f4();
    virtual void c3f8();
    virtual void c3fc();
    virtual void c400();
    virtual void c404();
    virtual void c408();
    virtual void c40c();
    virtual void c410();
    virtual void c414();
    virtual void c418();
    virtual void c41c();
    virtual void c420();
    virtual void c424();
    virtual Effect_8cc740* GetEffect();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084;
    Sink_8cc740 m_kSink;
};

struct Grid_8cc740
{
};

class Owner_8cc740
{
  public:
    virtual void o000();
    virtual void o004();
    virtual void o008();
    virtual void o00c();
    virtual void o010();
    virtual void o014();
    virtual void o018();
    virtual void o01c();
    virtual void o020();
    virtual void o024();
    virtual void o028();
    virtual void o02c();
    virtual void o030();
    virtual void o034();
    virtual void o038();
    virtual void o03c();
    virtual void o040();
    virtual void o044();
    virtual void o048();
    virtual void o04c();
    virtual void o050();
    virtual void o054();
    virtual void o058();
    virtual void o05c();
    virtual void o060();
    virtual void o064();
    virtual void o068();
    virtual void o06c();
    virtual void o070();
    virtual void o074();
    virtual void o078();
    virtual void o07c();
    virtual void o080();
    virtual void o084();
    virtual void o088();
    virtual void o08c();
    virtual void o090();
    virtual void o094();
    virtual void o098();
    virtual void o09c();
    virtual void o0a0();
    virtual void o0a4();
    virtual void o0a8();
    virtual void o0ac();
    virtual void o0b0();
    virtual void o0b4();
    virtual void o0b8();
    virtual void o0bc();
    virtual void o0c0();
    virtual void o0c4();
    virtual void o0c8();
    virtual void o0cc();
    virtual void o0d0();
    virtual void o0d4();
    virtual void o0d8();
    virtual void o0dc();
    virtual void o0e0();
    virtual void o0e4();
    virtual void o0e8();
    virtual void o0ec();
    virtual void o0f0();
    virtual void o0f4();
    virtual void o0f8();
    virtual void o0fc();
    virtual void o100();
    virtual void o104();
    virtual void o108();
    virtual void o10c();
    virtual void o110();
    virtual void o114();
    virtual void o118();
    virtual void o11c();
    virtual void o120();
    virtual void o124();
    virtual void o128();
    virtual void o12c();
    virtual void o130();
    virtual void o134();
    virtual void o138();
    virtual void o13c();
    virtual void o140();
    virtual void o144();
    virtual void o148();
    virtual void o14c();
    virtual void o150();
    virtual void o154();
    virtual void o158();
    virtual void o15c();
    virtual void o160();
    virtual void o164();
    virtual void o168();
    virtual void o16c();
    virtual void o170();
    virtual void o174();
    virtual void o178();
    virtual void o17c();
    virtual void o180();
    virtual void o184();
    virtual void o188();
    virtual void o18c();
    virtual void o190();
    virtual void o194();
    virtual void o198();
    virtual void o19c();
    virtual void o1a0();
    virtual void o1a4();
    virtual void o1a8();
    virtual void o1ac();
    virtual void o1b0();
    virtual void o1b4();
    virtual void o1b8();
    virtual void o1bc();
    virtual void o1c0();
    virtual void o1c4();
    virtual void o1c8();
    virtual void o1cc();
    virtual Node_8cc740* GetNode();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084;
    ProjectionData_8cc740* m_pUserData;
    int m_iActive;
    int unk90, unk94;
    float m_fScale;
    int unk9c, unka0;
    Controller_8cc740* m_pkController;
    int unka8, unkac, unkb0;
    NiPoint3 m_kOffset;

    void FUN_008cc740(const NiPoint3& kPos, const NiPoint3& kWorldPosition);
};

struct xP3
{
    float x, y, z;
    bool FUN_00439090(const xP3&) const;
    xP3 operator*(float) const;
};

struct xMat
{
    float m[9];
};

union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};

struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(const xP3&);
};

struct xData
{
    xData();
    int m_iWordAt00;
    xP3 m_iWordAt04;
    xP3 m_10;
    xP3 m_1c;
    void* m_28;
    int m_2c;
    xMat m_30;
};

struct xHolder
{
};

struct xDH
{
    xP3 FUN_004b4500(const xP3&);
};

struct xDHOwner
{
};

struct xActor
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x84];
    xData* m_88;
    int m_8c;
    int m_90, m_94;
    float m_98;
    void FUN_008ccce0(const xP3& akA, const xP3& akB);
};

namespace fnv_008ccfb0 {
struct xP3
{
    float x, y, z;
    bool FUN_00439090(const xP3&) const;
    xP3 operator*(float) const;
};
struct xMat
{
    float m[9];
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(const xP3&);
};
struct xData
{
    xData();
    int m_iWordAt00;
    xP3 m_iWordAt04;
    xP3 m_10;
    xP3 m_1c;
    void* m_28;
    int m_2c;
    xMat m_30;
};
struct xHolder
{
    const xP3* FUN_00807080();
};
struct xDH
{
    xP3 FUN_004b4500(const xP3&);
};
struct xDHOwner
{
};
struct xActor
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x84];
    xData* m_88;
    int m_8c;
    int m_90, m_94;
    float m_98;
    void FUN_008ccfb0(void* aiValue);
};

// @fnv 0x008ccfb0
void xActor::FUN_008ccfb0(void* aiValue)
{
    if (m_88)
        m_88->m_iWordAt00 = 4;
    else
    {
        m_88 = new xData;
        m_88->m_iWordAt00 = 4;
        m_88->m_2c = 0;
        m_88->m_28 = aiValue;
        m_88->m_10 = (*reinterpret_cast<::fnv_008ccfb0::xP3 *>((void *)&::NiPoint3::ZERO));
        m_88->m_iWordAt04 = (*reinterpret_cast<::fnv_008ccfb0::xP3 *>((void *)&::NiPoint3::ZERO));
        m_88->m_30 = (*reinterpret_cast<::fnv_008ccfb0::xMat *>(&::DAT_011a9448));
        m_88->m_1c = (*reinterpret_cast<::fnv_008ccfb0::xP3 *>((void *)&::NiPoint3::ZERO));
        if (((::fnv_008ccfb0::xHolder *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
        {
            xVec4 V(*((::fnv_008ccfb0::xHolder *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_00807080());
            if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_008ccfb0::xVec4 &)((*(::fnv_008ccfb0::xVec4 *)(reinterpret_cast<::Holder *>((void *)&(V))->FUN_00458700((::Holder *)(0), {})))))->FUN_004586d0() == -::DAT_01085910)
            {
                if (FUN_1d0())
                    m_88->m_1c = ((::fnv_008ccfb0::xDH *)(::FUN_00461130((std::intptr_t)(FUN_1d0()))))->FUN_004b4500((*reinterpret_cast<::fnv_008ccfb0::xP3 *>(&::DAT_011a9478)) * m_98);
            }
            else
                ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&m_88->m_1c)), (*(const ::hkVector4 *)(&V)));
        }
    }
    m_8c = 1;
}
}

class TESFormRef8CD
{
  public:
    TESFormRef8CD();
    void* m_pkForm;
};

class MagicItem8CD;

class TESObjectREFR8CD
{
  public:
};

class MagicItem8CD
{
  public:
    TESFormRef8CD GetSpell() const;
};

class SpellHandle8CD
{
  public:
    SpellHandle8CD(int iType, int iValue, int iFlags);
    int m_iHandle;
};

class Transform8CD
{
  public:
    Transform8CD();
    __m128 m_vComponents;
};

class Caster8CD
{
  public:
    virtual void vc000();
    virtual void vc004();
    virtual void vc008();
    virtual void vc00c();
    virtual void vc010();
    virtual void vc014();
    virtual void vc018();
    virtual void vc01c();
    virtual void vc020();
    virtual void vc024();
    virtual void vc028();
    virtual void vc02c();
    virtual void vc030();
    virtual void vc034();
    virtual void vc038();
    virtual void vc03c();
    virtual void vc040();
    virtual void vc044();
    virtual void vc048();
    virtual void vc04c();
    virtual void vc050();
    virtual void vc054();
    virtual void vc058();
    virtual void vc05c();
    virtual void vc060();
    virtual void vc064();
    virtual void vc068();
    virtual void vc06c();
    virtual void vc070();
    virtual void vc074();
    virtual void vc078();
    virtual void vc07c();
    virtual void vc080();
    virtual void vc084();
    virtual void vc088();
    virtual void vc08c();
    virtual void vc090();
    virtual void vc094();
    virtual void vc098();
    virtual void vc09c();
    virtual void vc0a0();
    virtual void vc0a4();
    virtual void vc0a8();
    virtual void vc0ac();
    virtual void vc0b0();
    virtual void vc0b4();
    virtual void vc0b8();
    virtual void vc0bc();
    virtual void vc0c0();
    virtual void vc0c4();
    virtual void vc0c8();
    virtual void vc0cc();
    virtual void vc0d0();
    virtual void vc0d4();
    virtual void vc0d8();
    virtual void vc0dc();
    virtual void vc0e0();
    virtual void vc0e4();
    virtual void vc0e8();
    virtual void vc0ec();
    virtual void GetTransform(Transform8CD& kOut);
    void SetHandle(SpellHandle8CD kHandle);
};

class Listener8CD
{
  public:
    void Add(void* const& rpvSource);
};

class ListenerList8CD
{
  public:
};

class Target8CD
{
  public:
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
    int m_iActive;
    void* m_pvTarget;
};

class Projectile8CD
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual void vp078();
    virtual void vp07c();
    virtual void vp080();
    virtual void vp084();
    virtual void vp088();
    virtual void vp08c();
    virtual void vp090();
    virtual void vp094();
    virtual void vp098();
    virtual void vp09c();
    virtual void vp0a0();
    virtual void vp0a4();
    virtual void vp0a8();
    virtual void vp0ac();
    virtual void vp0b0();
    virtual void vp0b4();
    virtual void vp0b8();
    virtual void vp0bc();
    virtual void vp0c0();
    virtual void vp0c4();
    virtual void vp0c8();
    virtual void vp0cc();
    virtual void vp0d0();
    virtual void vp0d4();
    virtual void vp0d8();
    virtual void vp0dc();
    virtual void vp0e0();
    virtual void vp0e4();
    virtual void vp0e8();
    virtual void vp0ec();
    virtual void vp0f0();
    virtual void vp0f4();
    virtual void vp0f8();
    virtual void vp0fc();
    virtual void vp100();
    virtual void vp104();
    virtual void vp108();
    virtual void vp10c();
    virtual void vp110();
    virtual void vp114();
    virtual void vp118();
    virtual void vp11c();
    virtual void vp120();
    virtual void vp124();
    virtual void vp128();
    virtual void vp12c();
    virtual void vp130();
    virtual void vp134();
    virtual void vp138();
    virtual void vp13c();
    virtual void vp140();
    virtual void vp144();
    virtual void vp148();
    virtual void vp14c();
    virtual void vp150();
    virtual void vp154();
    virtual void vp158();
    virtual void vp15c();
    virtual void vp160();
    virtual void vp164();
    virtual void vp168();
    virtual void vp16c();
    virtual void vp170();
    virtual void vp174();
    virtual void vp178();
    virtual void vp17c();
    virtual void vp180();
    virtual void vp184();
    virtual void vp188();
    virtual void vp18c();
    virtual void vp190();
    virtual void vp194();
    virtual void vp198();
    virtual void vp19c();
    virtual void vp1a0();
    virtual void vp1a4();
    virtual void vp1a8();
    virtual void vp1ac();
    virtual void vp1b0();
    virtual void vp1b4();
    virtual void vp1b8();
    virtual void vp1bc();
    virtual void vp1c0();
    virtual void vp1c4();
    virtual void vp1c8();
    virtual void vp1cc();
    virtual void* GetSource();
    virtual void vq000();
    virtual void vq004();
    virtual void vq008();
    virtual void vq00c();
    virtual void vq010();
    virtual void vq014();
    virtual void vq018();
    virtual void vq01c();
    virtual void vq020();
    virtual void vq024();
    virtual void vq028();
    virtual void vq02c();
    virtual void vq030();
    virtual void vq034();
    virtual void vq038();
    virtual void vq03c();
    virtual void vq040();
    virtual void vq044();
    virtual void vq048();
    virtual void vq04c();
    virtual void vq050();
    virtual void vq054();
    virtual void vq058();
    virtual void vq05c();
    virtual void vq060();
    virtual void vq064();
    virtual void vq068();
    virtual void vq06c();
    virtual void vq070();
    virtual void vq074();
    virtual void vq078();
    virtual void vq07c();
    virtual void vq080();
    virtual void vq084();
    virtual void vq088();
    virtual void vq08c();
    virtual void vq090();
    virtual void vq094();
    virtual void vq098();
    virtual void vq09c();
    virtual void vq0a0();
    virtual void vq0a4();
    virtual void vq0a8();
    virtual void vq0ac();
    virtual void vq0b0();
    virtual void vq0b4();
    virtual void vq0b8();
    virtual void vq0bc();
    virtual void vq0c0();
    virtual void vq0c4();
    virtual void vq0c8();
    virtual void Prepare();
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
    Target8CD* m_pkTarget;

    bool FUN_008cd520(Caster8CD* pkCaster);
};

// @fnv 0x008cd520
bool Projectile8CD::FUN_008cd520(Caster8CD* pkCaster)
{
    Prepare();
    if (m_pkTarget->m_iActive)
    {
        TESObjectREFR8CD* pkRef = (TESObjectREFR8CD*)((void *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(m_pkTarget->m_pvTarget))));
        if (!pkRef)
            return false;
        MagicItem8CD* pkItem = ((::MagicItem8CD *)(::fnv_006fa820::FUN_006fa820((const char *)(pkRef))));
        ::FUN_00c6a350((::NiAVObject *)(void *)(GetSource()), 4, 1, 0, 1);
        SpellHandle8CD kHandle(6, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)(void *)&(const ::TESFormRef8CD &)(pkItem->GetSpell()))->FUN_004a3a20())), 0);
        if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)(void *)&(const ::TESFormRef8CD &)(pkItem->GetSpell()))->FUN_0043b4d0() != 4)
            reinterpret_cast<::FUN_004a39f0_shell *>(&(kHandle))->FUN_004a39f0(0xf);
        pkCaster->SetHandle(kHandle);
        Listener8CD* pkListener = ((::Listener8CD *)(reinterpret_cast<::FUN_004610f0_Class *>(&((*reinterpret_cast<::ListenerList8CD *>(&::g_011e0e80))))->GetOffset70Ptr()));
        if (pkListener)
            pkListener->Add((void*)this);
        if (pkCaster)
        {
            if (reinterpret_cast<::bhkRigidBody *>((void *)(pkItem))->GetBodyMass() > 0.0)
            {
                Transform8CD kTransform;
                pkCaster->GetTransform(kTransform);
                ::FUN_0062a7e0((*(const ::hkVector4V *)(&kTransform)), m_pkTarget->m_pvTarget);
            }
        }
    }
    else
    {
        ::FUN_005b5e40(
            );
        return false;
    }
    return true;
}

struct Vec3D0020
{
    float x, y, z;
};

struct __declspec(align(16)) VecD0020
{
    __m128 quad;
    VecD0020();
    VecD0020(float);
};

struct SettingD0020
{
};

struct TypeD0020
{
    int value;
};

struct BodyD0020
{
};

struct ResultD0020
{
};

struct ObjectD0020
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
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
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
    virtual BodyD0020* GetBody();
    void FUN_0043b4f0(TypeD0020*);
};

struct TargetD0020
{
    void FUN_008d0020(Vec3D0020 position, Vec3D0020 direction, ObjectD0020* object);
};

// @fnv 0x008d0020
void TargetD0020::FUN_008d0020(Vec3D0020 position, Vec3D0020 direction, ObjectD0020* object)
{
    if (!object || ((bool)(reinterpret_cast<::FUN_008d0200_Class *>(this)->GetByteAtOffsetC3())))
        return;
    BodyD0020* body = object->GetBody();
    if (body)
    {
        float strength = reinterpret_cast<::FUN_008d01e0_Class *>(this)->FUN_008d01e0();
        TypeD0020 type;
        object->FUN_0043b4f0(&type);
        switch (reinterpret_cast<::FUN_0043b4d0_shell *>(&(type))->FUN_0043b4d0())
        {
        case 14:
            strength *= ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::originalRuntimeFloatSetting679))));
            break;
        case 8:
            strength *= ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::originalRuntimeFloatSetting678))));
            break;
        case 10:
            strength *= ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::g_011cf9d4))));
            break;
        default:
            strength *= ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::originalRuntimeFloatSetting677))));
            break;
        }
        float weight = ::FUN_004b5400((void *)(object));
        if (weight < ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::originalRuntimeFloatSetting680)))))
            strength *= weight / ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::originalRuntimeFloatSetting680))));
        strength *= ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD0020 *>(&::g_011ce224))));
        VecD0020 dir;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&dir)), (*(const ::fnv_004a3e00::NiPoint3 *)(&direction)));
        VecD0020 pos;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&pos)), (*(const ::fnv_004a3e00::NiPoint3 *)(&position)));
        reinterpret_cast<::S0062aea0_Vector *>(&(dir))->FUN_0062aea0();
        VecD0020 scale(strength);
        reinterpret_cast<::S_00627920 *>(&(dir))->FUN_00627920((::S_00561240 *)&(scale));
        reinterpret_cast<::TESForm *>((body))->ClearData();
        reinterpret_cast<::FUN_0081f1e0_Class *>((((::ResultD0020 *)(::FUN_004ae750((void *)(object))))))->ApplyVirtualCall({}, {});
        reinterpret_cast<::TESForm *>((body))->ClearData();
    }
    reinterpret_cast<::FUN_008d0220_class *>(this)->SetByteAtOffsetC3(true);
}

struct __declspec(align(16)) Quat08
{
    __m128 quad;
};

struct Row08
{
    float x, y, z, w;
};

struct Rec08
{
    Row08 a, b, c, d;
};

struct Data08
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
    Rec08* records;
    int count;
};

struct Col_0043b4f0
{
};

struct Node08
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
    Col_0043b4f0* collision;
};

struct FUN_00807770_Class
{
    char* FUN_00807770(int);
};

struct GlobalObject_008c71b0
{
    int value;
    GlobalObject_008c71b0(int);
};

struct FUN_0089f4e0_shell
{
    void* FUN_0089f4e0();
};

struct Holder00807080
{
    const char* FUN_00807080();
    void FUN_008d1180(FUN_00807770_Class*, Data08*);
};

// @fnv 0x008cc740
void Owner_8cc740::FUN_008cc740(const NiPoint3& kPos, const NiPoint3& kWorldPosition)
{
    m_pUserData = new ProjectionData_8cc740;
    NiPoint3 kIntersectionOffset = m_kOffset;
    ::FUN_00525340((float *)(::NiPoint3 *)(&kIntersectionOffset));
    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(kIntersectionOffset))->FUN_00439180(24.0f);
    m_pUserData->m_iFadeIndex = 2;
    m_pUserData->m_iFlags = 0;
    m_pUserData->m_iArrayLength = 0;
    m_pUserData->m_kLightVector = kWorldPosition;
    m_pUserData->m_kStartPoint = kPos + kIntersectionOffset;
    m_pUserData->m_kRotationMatrix = DAT_011a9448;
    m_pUserData->m_kValue = ::NiPoint3::ZERO;
    if (((::Source_8cc740 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        Rotation_8cc740 kRot(reinterpret_cast<::Holder00807080 *>((((::Source_8cc740 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00807080());
        if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::Rotation_8cc740 &)((*(::Rotation_8cc740 *)(reinterpret_cast<::Holder *>((void *)&(kRot))->FUN_00458700((::Holder *)(0), {})))))->FUN_004586d0() == -DAT_01085910)
        {
            if (GetNode())
                m_pUserData->m_kValue = ((::Transform_8cc740 *)(::FUN_00461130((std::intptr_t)(GetNode()))))->FUN_004b4500(DAT_011a9478 * m_fScale);
        }
        else
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&m_pUserData->m_kValue)), (*(const ::hkVector4 *)(&kRot)));
    }
    unsigned int uiType = reinterpret_cast<::FUN_00457880_Class *>(((*reinterpret_cast<::Grid_8cc740 * *>(&::g_TES))))->FUN_00457880((std::intptr_t)&(kPos));
    switch (uiType)
    {
    case 0:
    case 3:
    case 5:
    case 10:
    case 11:
    case 13:
    case 15:
        reinterpret_cast<::xActor *>(this)->FUN_008ccce0((const ::xP3 &)(kPos), (const ::xP3 &)(kWorldPosition));
        break;
    }
    m_iActive = 1;
    reinterpret_cast<::Object *>(this)->FUN_008cfad0(reinterpret_cast<::NiPoint3 *>((void *)&(m_pUserData->m_kValue))->ComputeMagnitude(), (*(int *)&(const ::NiPoint3 &)(kPos)), 0, uiType, {}, {});
    if (m_pkController && m_pkController->GetEffect())
        reinterpret_cast<::FUN_008d0600_s *>((m_pkController->GetEffect()))->FUN_008d0600((int)(std::uintptr_t)&(kPos), 0);
    if (m_pkController)
    {
        if (((::Emitter18_8cc740 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(this)->FUN_008cdd90())))
        {
            m_pkController->m_kSink.Attach(((::Emitter18_8cc740 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(this)->FUN_008cdd90())));
            m_pkController->m_kSink.SetActive(0);
            reinterpret_cast<::CastingCheck *>(&(m_pkController->m_kSink))->TryCast((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))));
        }
        if (((::Emitter30_8cc740 *)(std::uintptr_t)(::FUN_009ee040((char *)this))))
        {
            m_pkController->m_kSink.Attach(((::Emitter30_8cc740 *)(std::uintptr_t)(::FUN_009ee040((char *)this))));
            m_pkController->m_kSink.SetActive(0);
            reinterpret_cast<::CastingCheck *>(&(m_pkController->m_kSink))->TryCast((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))));
        }
        if (((::Emitter18_8cc740 *)(std::uintptr_t)(reinterpret_cast<::FUN_004f9bf0_shell *>(this)->FUN_004f9bf0())))
        {
            m_pkController->m_kSink.Attach(((::Emitter18_8cc740 *)(std::uintptr_t)(reinterpret_cast<::FUN_004f9bf0_shell *>(this)->FUN_004f9bf0())));
            m_pkController->m_kSink.SetActive(0);
            reinterpret_cast<::CastingCheck *>(&(m_pkController->m_kSink))->TryCast((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))));
        }
    }
    if (((::Emitter18_8cc740 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(this)->FUN_008cdd90())))
        reinterpret_cast<::FUN_008cc6d0_class *>(this)->FUN_008cc6d0(3);
}

// @fnv 0x008ccce0
void xActor::FUN_008ccce0(const xP3& akA, const xP3& akB)
{
    if (m_88)
    {
        if (reinterpret_cast<::NiPlane *>((void *)&(akB))->operator==((const ::NiPlane &)((*reinterpret_cast<::xP3 *>((void *)&::NiPoint3::ZERO)))))
            m_88->m_10 = akB;
        if (reinterpret_cast<::NiPlane *>((void *)&(akA))->operator==((const ::NiPlane &)((*reinterpret_cast<::xP3 *>((void *)&::NiPoint3::ZERO)))))
            m_88->m_iWordAt04 = akA;
        m_88->m_iWordAt00 = 3;
        m_88->m_28 = 0;
        return;
    }
    m_88 = new xData;
    m_88->m_iWordAt00 = 3;
    m_88->m_2c = 0;
    m_88->m_28 = 0;
    m_88->m_10 = akB;
    m_88->m_iWordAt04 = akA;
    m_88->m_30 = (*reinterpret_cast<::xMat *>(&::DAT_011a9448));
    m_88->m_1c = (*reinterpret_cast<::xP3 *>((void *)&::NiPoint3::ZERO));
    if (((::xHolder *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        xVec4 V(*((const ::xP3 *)(reinterpret_cast<::Holder00807080 *>((((::xHolder *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00807080())));
        if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::xVec4 &)((*(::xVec4 *)(reinterpret_cast<::Holder *>((void *)&(V))->FUN_00458700((::Holder *)(0), {})))))->FUN_004586d0() == -::DAT_01085910)
        {
            if (FUN_1d0())
                m_88->m_1c = ((::xDH *)(::FUN_00461130((std::intptr_t)(FUN_1d0()))))->FUN_004b4500((*reinterpret_cast<::xP3 *>(&::DAT_011a9478)) * m_98);
        }
        else
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&m_88->m_1c)), (*(const ::hkVector4 *)(&V)));
    }
    m_8c = 1;
}

// @fnv 0x008d1180
void Holder00807080::FUN_008d1180(FUN_00807770_Class* nodes, Data08* data)
{
    int count = data->count;
    for (int i = 0; i < count; i++)
    {
        Rec08* record = &data->records[i];
        Node08* node = (Node08*)nodes->FUN_00807770(i);
        void* collision = FUN_004b59f0(node->collision);
        GlobalObject_008c71b0 filter(((int)(::FUN_0043b540((char *)(node->collision)))));
        int layer = reinterpret_cast<::FUN_0043b4d0_shell *>(&(filter))->FUN_0043b4d0();
        if (!collision)
        {
            if (layer != 30)
            {
                reinterpret_cast<::AlignedVector *>(&(record->b))->FUN_004a3f10((*(const ::AlignedVector *)(FUN_00807080())));
                Quat08 q;
                reinterpret_cast<::AlignedVector *>(&(record->a))->FUN_004a3f10((*(const ::AlignedVector *)(((void *)(reinterpret_cast<::FUN_005532a0_cls *>(&(q))->FUN_005532a0(0.0f, 0.0f, 0.0f, 1.0f))))));
            }
        }
        else
        {
            void* ref = ((void *)(::GetReferenceFromObject((::NiAVObject *)(node->collision))));
            if (ref && ref == (*reinterpret_cast<::FUN_0089f4e0_shell * *>(&::_g_thePlayer))->FUN_0089f4e0())
            {
                reinterpret_cast<::AlignedVector *>(&(record->b))->FUN_004a3f10((*(const ::AlignedVector *)(FUN_00807080())));
                Quat08 q;
                reinterpret_cast<::AlignedVector *>(&(record->a))->FUN_004a3f10((*(const ::AlignedVector *)(((void *)(reinterpret_cast<::FUN_005532a0_cls *>(&(q))->FUN_005532a0(0.0f, 0.0f, 0.0f, 1.0f))))));
                break;
            }
        }
    }
}

extern float DAT_01085c58, DAT_01047224;

extern double DAT_010356f0;

Node8* FUN_008cfbc0(Node8*, NiPoint3, NiPoint3, float*, bool);

// @fnv 0x008cba30
void Ref8::FUN_008cba30(const NiPoint3* start, const NiPoint3* end, Ref8* victim)
{
    state = new FUN_008cc6f0;
    state->mode = 0;
    state->node = 0;
    state->victim = 0;
    state->end = *end;
    state->target = *start;
    state->rotation = DAT_011a9448;
    state->direction = ::NiPoint3::ZERO;
    if (((::Ref8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        FUN_004a3c90 direction(((::FUN_004a3c90 *)(reinterpret_cast<::Holder00807080 *>((((::Ref8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00807080())));
        if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::FUN_004a3c90 &)((*(::FUN_004a3c90 *)(reinterpret_cast<::Holder *>((void *)&(direction))->FUN_00458700((::Holder *)(0), {})))))->FUN_004586d0() == -DAT_01085910)
        {
            if (v1d0())
                state->direction = ((::Node8 *)(::FUN_00461130((std::intptr_t)(v1d0()))))->FUN_004b4500(DAT_011a9478 * angle);
        }
        else
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&state->direction)), (*(const ::hkVector4 *)(&direction)));
    }
    active = 1;
    if (victim)
    {
        Node8* root = v1d0();
        if (actor && actor->v428())
            reinterpret_cast<::FUN_008d0600_s *>((actor->v428()))->FUN_008d0600((int)(std::uintptr_t)(victim->v1f4()), 1);
        state->victim = victim;
        if (victim)
            reinterpret_cast<::MyActor008A5300 *>((victim))->CallProcessAt778();
        ::FUN_005ac750((::TESForm *)(((intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((state->victim))->FUN_005d43c0()), 0x100);
        if (actor)
        {
            if (actor != (*reinterpret_cast<::Ref8 * *>(&::_g_thePlayer)) && !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((actor))->FUN_00493bb0())))
                goto sceneReady;
            bool blocked = victim->v22c(0);
            if (!blocked && victim->v22c(0) && (!victim->v21c() || victim->v38c()))
            {
                Node8* scene = ((::Node8 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((victim))->FUN_0043fcd0()));
                if (scene)
                {
                    float setting = ::RemapValueBySettings(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting8 *>(&::originalRuntimeFloatSetting701)))))), 1);
                    ::FUN_00cb9650((::FUN_00cb9650_Object *)(scene));
                    ::FUN_00c6a350((::NiAVObject *)(scene), 1, 1, 0, 1);
                    NiUpdateData zero(0.0f, false, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((scene))->FUN_00a59c60((std::intptr_t)&(zero));
                    NiPoint3 offset = ((::Node8 *)(::FUN_00461130((std::intptr_t)(root))))->FUN_004b4500(DAT_011a9478);
                    reinterpret_cast<::FUN_004a0c10_s *>(&(offset))->FUN_004a0c10();
                    offset = *v1f4() + (offset * DAT_01085c58);
                    hkVector4 position;
                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&position)), (*(const ::fnv_004a3e00::NiPoint3 *)(&offset)));
                    ::SetCollisionScale((::SceneNode *)(scene), (unsigned int)(std::uintptr_t)&(position), setting, (::MaterialSelector *)(0));
                }
            }
        }
    sceneReady:
        Link8* linked = 0;
        Node8* victimScene;
        if (victim == (*reinterpret_cast<::Ref8 * *>(&::_g_thePlayer)))
            victimScene = ((::Node8 *)(std::uintptr_t)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::Ref8 * *>(&::_g_thePlayer))))->FUN_00950bb0(0)));
        else
            victimScene = ((::Node8 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((victim))->FUN_0043fcd0()));
        float range = DAT_010231a0;
        NiPoint3 direction;
        ThreeByThreeMatrix pitch;
        ThreeByThreeMatrix heading;
        reinterpret_cast<::FUN_004a0c90_shell *>(&(pitch))->FUN_004a0c90(v2bc(0));
        reinterpret_cast<::FUN_00524ac0_shell *>(&(heading))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
        pitch = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(pitch))->operator+(heading);
        reinterpret_cast<::FUN_00439f50_class *>((void *)&(pitch))->FUN_00439f50(1, &direction);
        ::FUN_00525340((float *)(::NiPoint3 *)(&direction));
        NiPoint3 ray = *v1f4() - reinterpret_cast<::Point3_0053d280 *>((void *)(void *)&(const ::NiPoint3 &)((direction * range)))->FUN_0053d280(DAT_010162c0);
        bool found = false;
        Node8* hit = FUN_008cfbc0(victim->v1d0(), ray, direction, &range, !victim->v22c(1));
        if (hit)
        {
            NiPoint3 scaled = direction * (float)(range + DAT_010356f0);
            NiTransform transform;
            reinterpret_cast<::NiTransform *>((((::Node8 *)(::FUN_00461130((std::intptr_t)(hit))))))->CalculateInverse((*(::NiTransform *)(&transform)));
            state->target = transform.FUN_00524c40(ray + scaled);
            ThreeByThreeMatrix inverse;
            reinterpret_cast<::ThreeByThreeMatrix *>((((::Node8 *)(::FUN_00461130((std::intptr_t)(hit))))))->Inverse((*(::ThreeByThreeMatrix *)(&inverse)));
            state->rotation = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(inverse))->operator+(*reinterpret_cast<ThreeByThreeMatrix*>(((::Node8 *)(::FUN_00461130((std::intptr_t)(root))))));
            state->node = hit;
            Form8* form = ((::Form8 *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(hit))));
            if (form)
                linked = ((::Link8 *)(::fnv_006fa820::FUN_006fa820((const char *)(form))));
            found = true;
        }
        bool overrideHit = false;
        if (reinterpret_cast<::FUN_00894d60_shell *>((victim))->FUN_00894d60() && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((victim))->GetBaseTexture())) && ::IsTargetInCone((::ConeRef *)(victim), (::ConeRef *)(::Ref8 *)(this), (float *)(0)))
        {
            NiPoint3 position = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((victim))->GetAddTopicList()));
            float top = reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((victim))->GetActorHeight() / DAT_01011590 + position.z;
            if (top <= start->z)
                overrideHit = true;
        }
        if (!found || overrideHit)
        {
            FUN_006240d0 bound;
            hkVector4 center;
            ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&center)), (*(const ::fnv_004a3e00::NiPoint3 *)(start)));
            reinterpret_cast<::FUN_008a50f0_class *>(&(bound))->FUN_008a50f0((int)(std::uintptr_t)&(center));
            reinterpret_cast<::fnv_008a50d0::bhkCharacterController *>(&(bound))->FUN_008a50d0(::g_011c72ac_arg1);
            Link8* candidate = 0;
            if (overrideHit)
                candidate = ((::Link8 *)(::FindPhysicsBodyByLayer((::SearchObject *)(victimScene), 7)));
            else
                candidate = ((::Link8 *)(::FUN_00c806b0(victimScene, &bound, !victim->v22c(1))));
            if (candidate)
            {
                linked = candidate;
                Form8* object = ((::Form8 *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(::Form8 *)(((::Form8 *)(::FUN_004ae750((void *)(linked))))))));
                if (object)
                {
                    hit = ((::Node8 *)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName()));
                    NiPoint3 scaled = direction * DAT_01047224;
                    NiTransform transform;
                    reinterpret_cast<::NiTransform *>((((::Node8 *)(::FUN_00461130((std::intptr_t)(hit))))))->CalculateInverse((*(::NiTransform *)(&transform)));
                    state->target = transform.FUN_00524c40(*((::NiPoint3 *)(::FUN_0045bb80((std::intptr_t)(hit)))) + scaled);
                    ThreeByThreeMatrix inverse;
                    reinterpret_cast<::ThreeByThreeMatrix *>((((::Node8 *)(::FUN_00461130((std::intptr_t)(hit))))))->Inverse((*(::ThreeByThreeMatrix *)(&inverse)));
                    state->rotation = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(inverse))->operator+(*reinterpret_cast<ThreeByThreeMatrix*>(((::Node8 *)(::FUN_00461130((std::intptr_t)(root))))));
                    state->node = hit;
                }
            }
            if (!state->node)
            {
                reinterpret_cast<::fnv_008ccfb0::xActor *>(this)->FUN_008ccfb0(victim);
                return;
            }
        }
        if (linked)
            FUN_008d0020(*start, ((::Node8 *)(::FUN_00461130((std::intptr_t)(root))))->FUN_004b4500(DAT_011a9478), linked);
        if (state->node)
        {
            Form8* form = ((::Form8 *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(state->node))));
            Link8* object = form ? ((::Link8 *)(::fnv_006fa820::FUN_006fa820((const char *)(form)))) : 0;
            Material8* material = object ? ((::Material8 *)(reinterpret_cast<::FUN_004ae6a0_shell *>((object))->FUN_004ae6a0())) : 0;
            if (material)
            {
                switch (((unsigned int)(reinterpret_cast<::FUN_006205a0_Class *>((material))->FUN_006205a0())))
                {
                case 0:
                case 3:
                case 5:
                case 10:
                case 11:
                case 13:
                case 15:
                    reinterpret_cast<::xActor *>(this)->FUN_008ccce0((*(const ::xP3 *)(start)), (*(const ::xP3 *)(end)));
                    return;
                default:
                    break;
                }
            }
        }
        if (victim->v21c() && !victim->v38c())
        {
            reinterpret_cast<::fnv_008ccfb0::xActor *>(this)->FUN_008ccfb0(victim);
            reinterpret_cast<::FUN_008cc6d0_class *>(this)->FUN_008cc6d0(3);
            return;
        }
        else
        {
            if (!((intptr_t)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(this)->FUN_008cdd90())) && ::DialogueRandom() % 100 < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting8 *>(&::g_011cf510)))))))
            {
                victim->v190(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430(), 0, 1);
                requested = true;
            }
        }
    }
}

#include "generated/data/staging/blk_008c0000_o2_od_noo2_variant.inc"
#include "generated/data/staging/blk_008c0000_o2_od_oy_noo2_variant.inc"
