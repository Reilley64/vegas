// src/staging/blk_00de0000_o2_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00de0000_o2_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00de0000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00de0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00de0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <xmmintrin.h>
#include <emmintrin.h>
#include <new>
#include <windows.h>
#include "fnv/decl/AnimationEndian.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00c983e0_Class.h"
#include "fnv/decl/FUN_00cdea00_cls.h"
#include "fnv/decl/FUN_00cdf760.h"
#include "fnv/decl/FUN_00ce5360_This.h"
#include "fnv/decl/FUN_00cf56f0.h"
#include "fnv/decl/FUN_00d21de0_cls.h"
#include "fnv/decl/FUN_00d51620_class.h"
#include "fnv/decl/FUN_00d59830.h"
#include "fnv/decl/FUN_00dfd380_cls.h"
#include "fnv/decl/FUN_00e0bf30_s.h"
#include "fnv/decl/FUN_00e0f700_s.h"
#include "fnv/decl/FUN_00e2d0d0_cls.h"
#include "fnv/decl/FUN_00e2ea20_class.h"
#include "fnv/decl/FUN_00e2ebc0_class.h"
#include "fnv/decl/FUN_00e34800.h"
#include "fnv/decl/FUN_00e3dbd0.h"
#include "fnv/decl/FUN_00e3df50_Class.h"
#include "fnv/decl/FUN_00e3e380.h"
#include "fnv/decl/FUN_00e46300.h"
#include "fnv/decl/FnvVtObj.h"
#include "fnv/decl/Hk_e05c20_track.h"
#include "fnv/decl/LunaOwner.h"
#include "fnv/decl/Node.h"
#include "fnv/decl/e319Cls.h"
#include "fnv/decl/fnv_00ce5370__FUN_00ce5370_cls.h"
#include "fnv/decl/fnv_00d53df0__FUN_00d53df0.h"
#include "fnv/decl/fnv_00ddc870__FUN_00ddc870_cls.h"
#include "fnv/decl/fnv_00dfb2d0__FUN_00dfb2d0.h"
#include "fnv/decl/fnv_00dfd440__FUN_00dfd440_cls.h"
#include "fnv/decl/fnv_00e45010__FUN_00e45010__hkpProjectileGun.h"
#include "fnv/decl/hkPragdollLimitsData.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb3000.h"
#include "fnv/symbols_00d04000.h"
#include "fnv/symbols_00d1b000.h"
#include "fnv/symbols_00d9d000.h"
#include "fnv/symbols_00ddf000.h"
#include "fnv/symbols_00de4000.h"
#include "fnv/symbols_00df0000.h"
#include "fnv/symbols_00df1000.h"
#include "fnv/symbols_00df2000.h"
#include "fnv/symbols_00df6000.h"
#include "fnv/symbols_00df7000.h"
#include "fnv/symbols_00dfb000.h"
#include "fnv/symbols_00dfc000.h"
#include "fnv/symbols_00dfd000.h"
#include "fnv/symbols_00dfe000.h"
#include "fnv/symbols_00dff000.h"
#include "fnv/symbols_00e2f000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_010c8000.h"
#include "fnv/symbols_010c9000.h"
#include "fnv/symbols_010cc000.h"
#include "fnv/symbols_010cd000.h"
#include "fnv/symbols_010d3000.h"
#include "fnv/symbols_010d7000.h"
#include "fnv/symbols_010de000.h"
#include "fnv/symbols_010df000.h"
#include "fnv/symbols_010e0000.h"
#include "fnv/symbols_010e3000.h"
#include "fnv/symbols_010e5000.h"
#include "fnv/symbols_010e6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
#include "fnv/symbols_0126a000.h"
#include "fnv/symbols_0126b000.h"
#include "fnv/symbols_0126c000.h"
#include "fnv/symbols_0126d000.h"
#include "../../include/layout_support.h"
void __cdecl FUN_00df64d0(void* p, int b);
struct FUN_00cb0c00_class
{
    void FUN_00cb0c00();
};
void FUN_00dfb490(FUN_00cb0c00_class* self);
struct hkReferencedObject
{
};
void FUN_00dfb9d0(hkReferencedObject** p);
extern int DAT_010df34c;
struct FUN_00dfbdf0_class
{
    void FUN_00cb0a70(int a);
};
struct FUN_00d21de0_Class
{
};
extern "C" void* DAT_010e222c;
struct FUN_00cb0a70_class
{
    void FUN_00cb0a70(int);
};
void __cdecl FUN_00dfd770(void* arg1, void* arg2);
struct FUN_00cb0a70_cls
{
    void FUN_00cb0a70(char*);
};
void FUN_00dfda10(char* b, char* a);
extern int DAT_010d3cc0;
extern int DAT_010d08f4;
struct FUN_00cb0a70_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void FUN_00cb0a70(int a);
};
struct FUN_00dff0f0_class
{
    int m;
    void FUN_00cb0a70(int);
};
extern int DAT_010cce28;
extern int DAT_010d07f4;
struct FUN_00cb0a70
{
};
struct FUN_00dff340_Class
{
    void* m_p;
    void FUN_00cb0a70(void* arg);
};
extern int DAT_010d0944;
void CopyFields(void* a, void* b);
void FUN_00dfbc70(FUN_00cb0c00_class* self);
extern int DAT_010df89c;
extern int DAT_010dff44;
typedef void(* VTable0)(void*, int);
extern int DAT_010e00cc;
extern int DAT_010e00dc;
extern int DAT_010e04ac;
extern int DAT_010d0a64;
extern int DAT_010d0aac;
extern int DAT_010e11ec;
extern int DAT_010da04c;
extern int DAT_010d0b3c;
extern int DAT_010d0be4;
typedef int(* VFunc0)(void*, int);
extern int DAT_010c91ec;
extern int DAT_010d0cd4;
struct FUN_00dfd7a0_vt
{
    virtual void v0(int);
    virtual void v1(int);
};
void __cdecl FUN_00dfd7c0(void* arg);
struct FUN_00dfd940_vt
{
    virtual void FUN_00dfd940(int);
};
void __cdecl FUN_00dfd940(FUN_00dfd940_vt* p);
void __cdecl FUN_00dfdb40(void* p);
extern int DAT_010e351c;
extern "C" void* DAT_010e352c;
void __cdecl FUN_00dfdf90(int a, int b);
extern int DAT_010e3e5c;
extern int DAT_010e5474;
struct FUN_00dfe430_class
{
    virtual int FUN_00cb0a70(int a);
};
extern int DAT_010e57a4;
struct FUN_00dfe670_vt
{
    virtual void m_iWordAt00(int);
};
extern int DAT_010e59ac;
extern int DAT_010e5b68;
extern int DAT_010e5b4c;
extern int DAT_010e5bfc;
extern int DAT_010e5d94;
extern int DAT_010e5da8;
extern int DAT_010e60c4;
extern int DAT_010e62a4;
extern int DAT_010e6394;
extern int DAT_010e66fc;
extern int DAT_010e676c;
extern int DAT_010c8e94;
struct FUN_00cb0a70_m_helper
{
    void m(int);
};
typedef void(* VTableFn)(void*, int);
extern int DAT_010e75cc;
extern int DAT_010e75dc;
extern int DAT_010e75ec;
typedef int(* Vfn)(void*, int);
extern int DAT_010e7c24;
extern int DAT_010cc0d8;
struct FUN_00dffdc0_vt
{
    virtual void m0(int);
};
extern int DAT_010d3838;
extern int DAT_010cb798;
struct FUN_00dfff60_vt
{
    virtual int v0(int);
};
struct FUN_00dfffc0_VT
{
    virtual void m0(int);
};
extern void* DAT_010e80b4;
struct FUN_00de87c0_class
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    void SwapFields();
};
void __cdecl FUN_00de81a0(void* self, void* arg);
struct FUN_00d21ce0_cls
{
    void FUN_00d21ce0(void*);
};
struct FUN_00de8550_t
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
void __cdecl FUN_00de8550(FUN_00de8550_t* a, int b);
struct FUN_00de8830_Class
{
    void CopyTransposedMatrix(float* src);
};
int __cdecl FUN_00df3250(int arg);
typedef void(* Vfn0)(void*, int);
typedef int(* VFunc_00dfb270)(void*, int);
void __cdecl CallMethodOnBothHelpers(FUN_00cb0a70_m_helper* a, int v);
typedef void(* VFunc00dfb3f0)(void*, int);
struct FUN_00dfb450_vt
{
    virtual void m0(int);
};
struct FUN_00dfb890_vt
{
    virtual void v0(int);
};
typedef void(* VTable0_00dfba70)(void*, int);
typedef void(* VFn0)(void*, int);
void __cdecl FUN_00dfbbf0(void* p, int a);
struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
void __cdecl FUN_00dfbc20(S_00d49310_Lock* self);
void __cdecl FUN_00dfbc30(void* a, void* b);
void __cdecl DispatchToHelper(void* a, int b);
struct S_00dfb720_Elem
{
    ~S_00dfb720_Elem();
};
void __cdecl FUN_00dfbca0(S_00dfb720_Elem* p);
typedef void(* VTable0)(void*, int);
typedef void(* VFunc1)(void*, int);
struct FUN_00dfc040_vt
{
    virtual void FUN_00dfc040(int);
};
void __cdecl FUN_00dfc040(FUN_00dfc040_vt* p);
typedef void(* V00dfc790)(void*, int);
typedef void(* Vfn_00dfcb60)(void*, int);
struct FUN_00dfcc30_vt
{
    virtual void v0(int);
};
struct FUN_00dd0420_Class
{
    FUN_00dd0420_Class* FUN_00dd0420(int);
};
void __cdecl FUN_00dfcd80(FUN_00dd0420_Class* self, int a);
struct FUN_00dfce00_vt
{
    virtual void v0(int);
};
struct FUN_00dfcf00_vt
{
    virtual void m_iWordAt00(int);
};
struct FUN_00dfd240_vt
{
    virtual void FUN_00dfd240(int);
};
void __cdecl FUN_00dfd240(FUN_00dfd240_vt* p);
typedef void(* Vfn_00dfd620)(void*, int);
struct DFD680MeshData
{
    void FUN_00dfd680();
};
void __cdecl FUN_00dfd670(DFD680MeshData* p);
extern int DAT_010e311c;
void FUN_00dfdad0(int* a, int b);
struct FUN_00dfdb20_vt
{
    virtual void v0(int);
};
void __cdecl CallHelperMethod(FUN_00cb0a70_m_helper* a, int b);
struct S_00e3eaa0_Elem
{
    ~S_00e3eaa0_Elem();
};
void __cdecl FUN_00dfdd50(S_00e3eaa0_Elem* p);
struct FUN_00e3f900_class
{
    int FUN_00e3f900(int);
};
void __cdecl FUN_00dfdd60(FUN_00e3f900_class* p, int a);
void CallHelperWithInt(FUN_00cb0a70_m_helper* p, int a);
struct ArrayPair
{
    ~ArrayPair();
};
void __cdecl FUN_00dfe0c0(ArrayPair* p);
typedef void(* Vfn_00dfe270)(void*, int);
extern int DAT_010cb864;
struct FUN_00ce5360_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
};
struct FUN_00dfe320_vt
{
    virtual void m_iWordAt00(int);
};
struct FUN_00dfe4e0_vt
{
    virtual void m0(int);
};
extern int DAT_010e587c;
extern int DAT_010e5a58;
typedef void(* Vfn0)(void*, int);
struct FUN_00dfec30_vt
{
    virtual void m0(int);
};
struct FUN_00dfecf0_vt
{
    virtual void v0(int);
};
struct FUN_00dfede0_vt
{
    virtual void v0(int);
};
typedef int(* Vfn_00dfeec0)(void*, int);
struct FUN_00dfef00_vt
{
    virtual void m0(int);
};
struct FUN_00dff1d0_vt
{
    virtual void m0(int);
};
typedef void(* VTable0)(void*, int);
struct FUN_00dff370_vt
{
    virtual void FUN_00dff370(int);
};
void __cdecl FUN_00dff370(FUN_00dff370_vt* p);
typedef void(* VTable0)(void*, int);
typedef void(* VTable0)(void*, int);
extern int DAT_010d0994;
struct FUN_00dff9b0_m : FUN_00cb0a70
{
    void m(int);
};
typedef void(* VTblFn0)(void*, int);
struct FUN_00dffc60_vt
{
    virtual void m0(int);
};
struct FUN_00dffd80_vt
{
    virtual void FUN_00cb0a70(int);
};
typedef void(* VTableFn)(void*, int);
struct FUN_00dffe60_vt
{
    virtual void m_iWordAt00(int);
};
typedef void(* Vfn0)(void*, int);
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
struct FUN_00de10e0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    void* m_p08;
    int m_0c;
    int m_10;

    FUN_00de10e0_cls* FUN_00de10e0(unsigned char acFlags);
};
struct FUN_00de3050
{
    float m_iWordAt00;
    FUN_00de3050();
};
extern int DAT_010d8214;
class FUN_00de3060
{
  public:
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int m_0c;

    FUN_00de3060(const unsigned int* src);
};
class FUN_00de3090_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_00de3090();
};
struct Quad16
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};
class FUN_00de48a0_cls
{
  public:
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
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    Quad16 GetQuad16();
};
// CopyStatsTo
// thiscall member of a game object class: copies the 16 bytes of the
// trailing "m_stats" block (this+0x70..0x7c) into the caller's output
// buffer and returns. One stack argument (the output pointer), callee-cleared.
struct StatsBlock
{
    int m_iStat00;
    int m_iStat04;
    int m_iStat08;
    int m_iStat0c;
};
struct GameObject
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
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    StatsBlock m_stats;

    void CopyStatsTo(int* __restrict pOut);
};
class FNVFloatGetter_cls
{
  public:
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
    float m_90;
    float FUN_00de48e0();
};
struct FUN_00de48f0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    float m_94;
    float FUN_00de48f0();
};
struct CpuObject
{
    unsigned int unk00;
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
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    float value;
    float FUN_00de4900();
};
struct FUN_00de4910_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int FUN_00de4910();
};
// CopyVec4ToBuffer: copies the 16-byte vector stored at this+0x80 into the
// 4-int block pointed to by the stack parameter.
struct Vec4
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_w;
};
struct FUN_00de4920_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    Vec4 m_v80;
    void CopyVec4ToBuffer(int* volatile pOut);
};
struct FUN_00de4e10_cls
{
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

    char* FUN_00de4e10();
};
struct FUN_00de5320_vec4
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_w;
};
class FUN_00de5320_cls
{
  public:
    FUN_00de5320_vec4 GetVec4At70();
};
struct FUN_00de5350_cls
{
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
    float m_84;
    float FUN_00de5350();
};
class FUN_00de5360_cls
{
  public:
    void* FUN_00de5360();
};
int __cdecl FUN_00de8150();
int* __cdecl FUN_00de8170();
void* FUN_00de8190();
void* __cdecl FUN_00de81d0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00de81f0();
void* __cdecl FUN_00de8210();
int* FUN_00de8230();
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;
GlobalObject* __cdecl FUN_00de8250();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00de8270();
void* __cdecl FUN_00de8290();
void* __cdecl FUN_00de82b0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269ef8;
GlobalObjectO2_00d472a0* __cdecl FUN_00de82d0();
void* __cdecl FUN_00de82f0();
void* __cdecl FUN_00de8310();
void* __cdecl FUN_00de8330();
// FUN_00de8350 : a one-line function - getter
void* FUN_00de8350();
void* __cdecl FUN_00de8390();
int* FUN_00de83b0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00de83d0();
void* __cdecl FUN_00de83f0();
void* __cdecl FUN_00de8410();
int* __cdecl FUN_00de8430();
void* __cdecl FUN_00de8450();
void* __cdecl FUN_00de8470();
int* __cdecl FUN_00de8490();
void* __cdecl FUN_00de84b0();
FUN_00de87c0_class* __cdecl FUN_00de84d0();
// FUN_00de84f0 : returns the address of a global data object.
// Original: mov eax, offset DAT_0126a228 ; ret
int* __cdecl FUN_00de84f0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00de8510();
int* __cdecl FUN_00de8530();
struct FUN_00de8570_cls
{
    int m_00;
    int m_04;
    int m_08;
};
void __cdecl FUN_00de8570(FUN_00de8570_cls* pTarget, int nIndex);
void* __cdecl FUN_00de8750();
void* __cdecl FUN_00de8770();
class FUN_00de8780_cls
{
  public:
    float m_fValues[16];

    unsigned char* HasNoNaNOrInf(unsigned char* pResult);
};
struct JacRow
{
    float x;
    float y;
    float z;
    float w;
};
struct JacBlock
{
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    JacRow rows[6];
};
struct DF25D0State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char m_ucFlags;
};
struct DF25D0Owner
{
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
    DF25D0State* m_pkState;
};
static void SetOwnerStateFlags(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType);
void DF25D0Attach(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType);
class FUN_00df3110
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int m_iArrayLength;

    FUN_00df3110();
};
struct FUN_00df3140_pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
void CopyPairToIndex(FUN_00df3140_pair* dst, unsigned int idx, FUN_00df3140_pair* src);
struct Handler_cls
{
    void Handle(int value);
};
int* __cdecl FUN_00df6490();
void* __cdecl FUN_00df64b0();
// @fnv 0x00df64c0
extern "C" void* __cdecl FUN_00df64c0()
{
    return &(*reinterpret_cast<int *>(&::g_0126a4a8));
}
struct FUN_00df7a60_class
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int unk14;
    int unk18;
    void* m_p1c;

    void FUN_00df7a60();
};
extern float DAT_010dbb3c;
struct ParserContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, result44;
    int FUN_00e63af0(int, void*, float*);
};
struct FloatPair
{
    float first, second;
    int FUN_00dfb040(ParserContext*, int, int*, ParserContext**);
};
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfb260();
int* __cdecl FUN_00dfb280();
struct FUN_00dfb2d0_class
{
};
int* __cdecl FUN_00dfb360();
void* __cdecl FUN_00dfb380();
int* __cdecl FUN_00dfb3c0(void);
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (ecx = object, one stack argument).
struct FUN_00dfb3d0_cls
{
};
void* __cdecl FUN_00dfb420();
struct FUN_00e2ebc0_cls
{
};
int* __cdecl FUN_00dfb480(void);
int __cdecl FUN_00dfb4d0();
void* __cdecl FUN_00dfb4f0();
void* __cdecl FUN_00dfb510();
int __cdecl FUN_00dfb540();
class DFB550Object
{
  public:
    virtual ~DFB550Object();
};
int* __cdecl FUN_00dfb560();
struct DFB570FinishFlag
{
    int m_bFinishing;
};
class DFB570Object
{
  public:
    DFB570Object(DFB570FinishFlag flag)
    {
        if (flag.m_bFinishing)
            ::FUN_00e2fc10((::hkaWaveletCompressedAnimation *)this);
    }

    virtual void vfunc00();

};
extern int DAT_010ddc5c;
void* __cdecl FUN_00dfb590();
int* __cdecl FUN_00dfb860();
void* FUN_00dfb880();
// FUN_00dfb8a0 : a one-line function - getter
void* FUN_00dfb8a0();
// ResetVTable -- installs a fixed vtable on an object and, when the second
// argument is set, runs the object's update step afterwards.
extern int DAT_010de0ec;
// vtable that gets installed
struct ResetVTableObj
{
    void* m_vptr;  // virtual table pointer, offset 0
};
struct ResetVTableTarget
{
};
extern int DAT_010de0ec;
void* FUN_00dfb8d0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfb920();
void* __cdecl FUN_00dfb940();
class CalleeObj
{
  public:
};
void __cdecl FUN_00dfb950(CalleeObj* pFirst, void* pSecond);
int* __cdecl FUN_00dfb970();
struct FUN_00ce5370_cls
{
};
void __cdecl FUN_00dfb980(FUN_00ce5370_cls* p);
int* __cdecl FUN_00dfb990();
// FUN_00dfb9a0 : __cdecl, 13 bytes
//   mov ecx, dword ptr [esp + 4]
//   mov eax, dword ptr [ecx]
//   mov edx, dword ptr [eax]
//   push 0
//   call edx
//   ret
// Calls vtable slot 0 of the object passed in, with the argument 0.
struct FUN_00dfb9a0_cls
{
    virtual int v00(int a);
};
int* __cdecl FUN_00dfb9b0(void);
int* FUN_00dfba40();
// FUN_00dfba50: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfba50_cls
{
  public:
};
void* __cdecl FUN_00dfbaa0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfbb20();
void* __cdecl FUN_00dfbb40();
// FUN_00dfbb50 : installs the class vtable into the object and, when the
// second argument is non-zero, tail-calls the routine at FUN_00e35050 with
// the object as 'this'.
extern int DAT_010de90c;
struct FUN_00dfbb50_cls
{
    void* m_vtbl;
};
extern int DAT_010de90c;
void* __cdecl FUN_00dfbb70();
// @fnv 0x00dfbc10
extern "C" void* __cdecl FUN_00dfbc10()
{
    return &(*reinterpret_cast<int *>(&::g_0126b078));
}
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfbc50();
int* __cdecl FUN_00dfbc60();
void* __cdecl FUN_00dfbce0();
// InitVTable : __cdecl initializer for an object with several vtable slots.
// The first vtable is installed, a flag byte at +9 is cleared when the flag is
// set, then the second vtable is installed along with two secondary vtables
// at +0x24 and +0x1c. Finally the flag byte is set to 2 when the flag is set.
extern int DAT_010dec04;
extern int DAT_010dec3c;
struct FUN_00dfbcf0_obj
{
    void* m_pVTable00;
    int m_iValue04;
    unsigned char m_bValue08;
    unsigned char m_bFlag09;
    unsigned short m_wValue0a;
    int m_iValue0c;
    int m_iValue10;
    int m_iValue14;
    int m_iValue18;
    void* m_pVTable1c;
    int m_iValue20;
    void* m_pVTable24;
};
extern int DAT_010dec3c;
void* __cdecl FUN_00dfbd30();
void* __cdecl FUN_00dfbdc0();
void* __cdecl FUN_00dfbde0();
void* __cdecl FUN_00dfbe90();
void* __cdecl FUN_00dfbeb0();
void* __cdecl FUN_00dfbed0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfbef0();
void* __cdecl FUN_00dfbf20();
struct FUN_00dfbf30_class
{
    virtual void m0(int);
};
int* __cdecl FUN_00dfbf40();
void* __cdecl FUN_00dfc030();
// FUN_00dfc050 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
void* __cdecl FUN_00dfc050();
// FUN_00dfc070 : a one-line function - getter
void* FUN_00dfc070();
int* __cdecl FUN_00dfc100();
struct S_00dfc110_vt
{
    virtual void m0(int);
};
void S_00dfc110_vt::m0(int)
{}
int* __cdecl FUN_00dfc120();
extern int DAT_010dff44;
void* __cdecl FUN_00dfc220();
char* __cdecl FUN_00dfc260();
extern int DAT_010e00cc;
void* FUN_00dfc290();
extern int DAT_010e00dc;
// FUN_00dfc360: cdecl no-arg getter returning the address of a global.
int* __cdecl FUN_00dfc360();
void* __cdecl FUN_00dfc370();
void* FUN_00dfc390();
struct FUN_00e05c20_class
{
};
void __cdecl FUN_00dfc3a0(FUN_00e05c20_class* p);
struct FUN_00dfc3b0_target
{
};
void __cdecl FUN_00dfc3b0(FUN_00dfc3b0_target* pTarget);
// FUN_00dfc440 : a one-line function - getter
void* FUN_00dfc440();
class VirtualDispatchObj
{
  public:
    virtual void Invoke0(int arg);
};
int __cdecl FUN_00dfc460();
extern int DAT_010e04ac;
void* __cdecl FUN_00dfc480();
void* __cdecl FUN_00dfc4d0();
int* __cdecl FUN_00dfc4f0();
int* __cdecl FUN_00dfc510();
int* __cdecl FUN_00dfc590(void);
// FUN_00dfc5b0 : a one-line function - getter
void* FUN_00dfc5b0();
int* __cdecl FUN_00dfc5d0();
void* __cdecl FUN_00dfc5f0();
struct FUN_00dfc600_vt
{
    virtual void m0(int);
};
void* __cdecl FUN_00dfc610();
int* __cdecl FUN_00dfc660();
// FUN_00dfc680 : a one-line function - getter
void* FUN_00dfc680();
struct FUN_00dfc690_vt
{
    virtual void m0(int);
};
void* __cdecl FUN_00dfc6a0();
extern int DAT_010d0a64;
void* FUN_00dfc6f0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126b888;
GlobalObjectO2_00d472a0* __cdecl FUN_00dfc710();
extern int DAT_010d0aac;
int* __cdecl FUN_00dfc760();
int* __cdecl FUN_00dfc7c0();
int* __cdecl FUN_00dfc7e0();
void* __cdecl FUN_00dfc800();
class DFC810Object
{
  public:
};
class SpawnedBase
{
  public:
    virtual ~SpawnedBase();
    virtual void Tick();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    SpawnedBase(int a);
};
class SpawnedMid
{
  public:
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SpawnedMid()
    {
        *(volatile int*)&m_8c = 0;
        *(volatile int*)&m_90 = 0;
        *(volatile int*)&m_94 = (int)0x80000000;
        *(volatile int*)&m_98 = 0;
        *(volatile int*)&m_9c = 0;
        *(volatile int*)&m_a0 = (int)0x80000000;
    }
};
class FUN_00dfc850 : public SpawnedBase, public SpawnedMid
{
  public:
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    virtual ~FUN_00dfc850();
    FUN_00dfc850(int a1);
};
int* __cdecl FUN_00dfc8c0();
int* __cdecl FUN_00dfc8e0();
extern int DAT_010e11ec;
int* __cdecl FUN_00dfc930();
struct FUN_00dfc940_class
{
    virtual void m0(int);
};
void* __cdecl FUN_00dfc950();
extern int DAT_010d0af4;
struct S_00dfc970_Flag
{
    char v;
    S_00dfc970_Flag(char c)
    {
        v = c;
    }
    S_00dfc970_Flag(const S_00dfc970_Flag& o)
    {
        v = o.v;
    }
};
struct S_00dfc970_Obj
{
    void* vptr;
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    short unk98;
    char unk9a;
};
extern int DAT_010d0af4;
int* __cdecl FUN_00dfc9c0();
class DFC9D0Object
{
  public:
    virtual ~DFC9D0Object();
};
int* __cdecl FUN_00dfc9e0();
extern int DAT_010cb71c;
void* __cdecl FUN_00dfca30();
void* __cdecl FUN_00dfca50();
class DFCA60Object
{
  public:
    virtual ~DFCA60Object();
};
void* __cdecl FUN_00dfca70();
extern int DAT_010da04c;
int* __cdecl FUN_00dfcac0();
int __cdecl FUN_00dfcae0();
extern int DAT_010d0b3c;
void* __cdecl FUN_00dfcb30();
int* __cdecl FUN_00dfcb90();
int* __cdecl FUN_00dfcbb0();
// Stand-in for the object whose virtual slot 0 is invoked with argument 0.
struct FUN_00dfcbc0_vt
{
    virtual void m0(int a);
};
void* __cdecl FUN_00dfcbd0();
// FUN_00dfcc20 : a one-line function - getter
void* FUN_00dfcc20();
struct S_00dfcc40_Obj
{
    int unk00;
};
S_00dfcc40_Obj* __cdecl FUN_00dfcc40();
// FUN_00dfcc70 : a one-line function - getter
void* FUN_00dfcc70();
int* __cdecl FUN_00dfcc90();
// Forwarder: takes the object pointer, calls its first virtual slot with a
// literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};
// FUN_00dfccb0 : a one-line function - getter
void* FUN_00dfccb0();
extern int DAT_010d0be4;
void* __cdecl FUN_00dfcce0();
void* __cdecl FUN_00dfcd00();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfcd20();
extern int DAT_010c91ec;
int* __cdecl FUN_00dfcd70();
void* __cdecl FUN_00dfcda0();
struct FUN_00dfcdb0_target
{
};
void __cdecl FUN_00dfcdb0(FUN_00dfcdb0_target* pTarget);
void* __cdecl FUN_00dfcdd0();
struct DFD5E0
{
};
void* __cdecl FUN_00dfce30();
int* __cdecl FUN_00dfce50();
void* __cdecl FUN_00dfce70();
extern int DAT_010d0cd4;
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfcec0();
void* __cdecl FUN_00dfcef0();
void* __cdecl FUN_00dfcf10();
struct FUN_00dfcf20_cls
{
};
extern "C" void* DAT_010e2144;
extern "C" void* DAT_010e2124;
struct FUN_00dfcf60_cls
{
    void* m_vptr00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_vptr10;
    char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;

    FUN_00dfcf60_cls* InitializeVtables(int flag);
};
void* FUN_00dfd0c0();
struct FUN_00dfd0d0_cls
{
    virtual void Call(int a);
};
void* FUN_00dfd0e0();
extern "C" void* DAT_010e222c;
void* __cdecl FUN_00dfd120();
unsigned char* __cdecl FUN_00dfd1b0();
void* __cdecl FUN_00dfd1d0();
// FUN_00dfd1e0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfd1e0_cls
{
  public:
};
int* __cdecl FUN_00dfd230();
// FUN_00dfd250 : a one-line function - getter
void* FUN_00dfd250();
struct S_00dfd260_Foo
{
};
int* __cdecl FUN_00dfd2a0();
int* __cdecl FUN_00dfd2c0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c230;
GlobalObjectO2_00d472a0* __cdecl FUN_00dfd2d0();
struct FUN_00dfd2e0_Class
{
    virtual void VF00(int value);
};
// FUN_00dfd2f0 : a one-line function - getter
void* FUN_00dfd2f0();
struct FUN_00e3dbd0_class
{
};
struct FUN_00dfd380_Class
{
};
void __cdecl FUN_00dfd360(int* param_1);
struct FnvCpu_FUN_00dfd370_CpuTarget
{
};
void __cdecl FUN_00dfd370(FnvCpu_FUN_00dfd370_CpuTarget* target);
// FUN_00dfd4e0 : a one-line function - getter
void* FUN_00dfd4e0();
void* __cdecl FUN_00dfd500();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfd540();
int* __cdecl FUN_00dfd560();
// FUN_00dfd570: null-guarded forwarder. The first argument (an object
// pointer) is loaded and tested; when it is not null the second argument
// is passed on to a non-virtual member function of that object.
class FUN_00dfd570_cls
{
  public:
};
void __cdecl FUN_00dfd570(FUN_00dfd570_cls* pObject, int a1);
int* __cdecl FUN_00dfd590();
int __cdecl FUN_00dfd5f0();
class FUN_00dfd600_cls
{
  public:
};
// FUN_00dfd650 : a one-line function - getter
void* FUN_00dfd650();
int* __cdecl FUN_00dfd790();
void* __cdecl FUN_00dfd7b0();
void* __cdecl FUN_00dfd930();
int* __cdecl FUN_00dfd950();
struct FUN_00dfd990_class
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int field10;
    FUN_00cb0a70_class field14;
};
void* FUN_00dfda40();
struct S_00e3f510_Foo
{
};
int* __cdecl FUN_00dfdaa0();
struct AdjacentObjects
{
    FUN_00cb0c00_class first;
    __declspec(align(4)) FUN_00cb0c00_class second;
};
void __cdecl FUN_00dfdab0(AdjacentObjects* objects);
void* __cdecl FUN_00dfdaf0();
// FUN_00dfdb10 : a one-line function - getter
void* FUN_00dfdb10();
void* __cdecl FUN_00dfdb30();
extern int DAT_010e351c;
extern "C" void* DAT_010e352c;
void* __cdecl FUN_00dfdb80();
int* FUN_00dfdd20();
int __cdecl FUN_00dfdd80();
int* __cdecl FUN_00dfddc0();
void* FUN_00dfdde0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfde00();
struct FUN_00dfde10_vtable
{
    virtual void slot0(int value)
    {}
};
int __cdecl FUN_00dfde20();
extern int DAT_010d3cc0;
char* __cdecl FUN_00dfde70(void);
void* __cdecl FUN_00dfde90();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfdeb0();
// FUN_00dfdec0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdec0_cls
{
  public:
};
void __cdecl FUN_00dfdec0(FUN_00dfdec0_cls* pObject, int a1);
void* __cdecl FUN_00dfdee0();
// FUN_00dfdef0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdef0_cls
{
  public:
};
void __cdecl FUN_00dfdef0(FUN_00dfdef0_cls* pObject, int a1);
void* __cdecl FUN_00dfdf10();
int* __cdecl FUN_00dfdf30();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfdf40();
class DFDF50Object
{
  public:
    virtual ~DFDF50Object();
};
int* __cdecl FUN_00dfdf60();
extern int DAT_010e3e5c;
struct FUN_00ddc870_class
{
};
void __cdecl FUN_00dfdfd0(FUN_00ddc870_class* self);
int* __cdecl FUN_00dfe090();
void* __cdecl FUN_00dfe0a0();
void* __cdecl FUN_00dfe0e0();
void* __cdecl FUN_00dfe100();
// FUN_00dfe120 : a one-line function - getter
void* FUN_00dfe120();
void* __cdecl FUN_00dfe140();
// FUN_00dfe160 : a one-line function - getter
void* FUN_00dfe160();
int* __cdecl FUN_00dfe180();
int __cdecl FUN_00dfe1a0();
int* __cdecl FUN_00dfe1c0();
void* __cdecl FUN_00dfe1e0();
void* __cdecl FUN_00dfe1f0();
// FUN_00dfe250: null-guarded forwarding of a second argument to a
// non-virtual member function of the first (object) argument.
class FUN_00dfe250_cls
{
  public:
};
// FUN_00dfe2a0: cdecl, returns the address of a global object.
void* __cdecl FUN_00dfe2a0();
int __cdecl FUN_00dfe2c0();
// FUN_00dfe330 : a one-line function - getter
void* FUN_00dfe330();
extern int DAT_010e5474;
// Helper object whose virtual-like member performs the work.
struct FUN_00cb0a70_obj
{
    void m_00cb0a70(int value);
};
// FUN_00dfe460 : a one-line function - getter
void* FUN_00dfe460();
void* __cdecl FUN_00dfe480();
// FUN_00dfe4f0: cdecl, returns the address of a global object.
void* __cdecl FUN_00dfe4f0();
extern int DAT_010e57a4;
// FUN_00dfe5a0: cdecl, returns the address of a global object.
void* __cdecl FUN_00dfe5a0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dfe680();
struct FUN_00dfe6e0_Class
{
    virtual void vf00(int value);
};
void* __cdecl FUN_00dfe6f0();
extern int DAT_010e59ac;
struct FUN_00dfe970_class
{
    virtual void m_iWordAt00(int);
};
void* __cdecl FUN_00dfe980();
int __cdecl FUN_00dfeab0();
extern int DAT_010dec04;
extern int DAT_010e5ae4;
extern int DAT_010e5ae4;
int* __cdecl FUN_00dfeb50();
extern int DAT_010e5b68;
int* __cdecl FUN_00dfebc0();
extern int DAT_010e5b4c;
int* __cdecl FUN_00dfec00();
extern int DAT_010e5bfc;
// FUN_00dfec40 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
void* __cdecl FUN_00dfec40();
class DFEC50Object
{
  public:
    virtual ~DFEC50Object();
};
// FUN_00dfec60 : a one-line function - getter
void* FUN_00dfec60();
// FUN_00dfec80: cdecl, returns the address of a global data symbol.
extern int DAT_010e5d94;
extern int DAT_010e5da8;
void* __cdecl FUN_00dfeca0();
void* __cdecl FUN_00dfecc0();
// FUN_00dfed00 : a one-line function - getter
void* FUN_00dfed00();
int __cdecl FUN_00dfedf0();
extern int DAT_010e60c4;
int* __cdecl FUN_00dfee90();
extern int DAT_010e62a4;
void* __cdecl FUN_00dfeeb0();
int __cdecl FUN_00dfeed0();
extern int DAT_010e6394;
void* __cdecl FUN_00dfef10();
class DFEF80Object
{
  public:
    virtual ~DFEF80Object();
};
// FUN_00dfefc0: returns the address of the global object at DAT_0126d190.
int* FUN_00dfefc0();
// FUN_00dfefd0 : cdecl, 13 bytes
// Calls slot 0 of the object's vtable with the argument 0 and returns the result.
struct FUN_00dfefd0_cls
{
    virtual int v00(int a);
};
void* __cdecl FUN_00dfefe0();
extern int DAT_010e66fc;
struct FUN_00dff0b0_class
{
    virtual void m0(int);
};
void* __cdecl FUN_00dff0c0();
extern int DAT_010e676c;
struct FUN_00dff120_Class
{
    virtual void vf00(int value);
};
// Getter returning the address of a global object.
int* __cdecl FUN_00dff160();
// Null-guarded forwarder: the first argument is an object pointer; when it is
// non-null the second argument is passed to a member function of that object.
struct FUN_00dff170_cls
{
};
struct FUN_00dff190_cls
{
    virtual void m_v00(int arg);
};
int __cdecl FUN_00dff1c0();
int __cdecl FUN_00dff1e0();
struct FUN_00dff250_class
{
    virtual void m0(int);
};
void* __cdecl FUN_00dff260();
struct DFF2E0FinishFlag
{
    int m_bFinishing;
};
class DFF2E0Object
{
  public:
    DFF2E0Object(DFF2E0FinishFlag flag);

};
int* __cdecl FUN_00dff330();
int __cdecl FUN_00dff3b0();
int* __cdecl FUN_00dff3d0();
struct CpuOpaque;
extern CpuOpaque DAT_010e6dec;
struct FUN_00e46300_class
{
};
struct DFF4E0Object
{
    virtual void Destroy(bool bFree);
};
void* __cdecl FUN_00dff510();
struct DFF520FinishFlag
{
    int m_bFinishing;
};
class DFF520Object
{
  public:
    DFF520Object(DFF520FinishFlag flag);

};
int __cdecl FUN_00dff570();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dff590();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dff5b0();
void* __cdecl FUN_00dff5d0();
extern int DAT_010e75cc;
extern int DAT_010e75dc;
extern int DAT_010e75ec;
// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dff870_cls
{
  public:
    virtual int v0(int a) = 0;
};
int* __cdecl FUN_00dff880();
// FUN_00dff890: forwards a second argument to a method of the first argument
// when that pointer is non-null.
struct FUN_00dff890_cls
{
};
extern "C" char DAT_010e7700;
extern "C" char DAT_010e76f4;
extern "C" char DAT_010e76e0;
extern "C" char DAT_010e76d4;
extern "C" char DAT_010e76c8;
extern "C" char DAT_010e76ac;
struct FNVRecordPointers
{
    void* volatile m00;
    void* m04;
    void* volatile m08;
    void* volatile m0c;
    void* volatile m10;
    void* volatile m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    void* volatile m30;
    FNVRecordPointers* InitializeRecordPointers(int unused);
};
void* __cdecl FUN_00dffa20();
void* __cdecl FUN_00dffa40();
// FUN_00dffa50: forwards a value to a helper on the passed-in object
// when that object is present.
struct FUN_00dffa50_cls
{
    void FUN_00dffa90(int value);
};
struct DFFA90FinishFlag
{
    int m_bFinishing;
};
class DFFA90ReferencedObject
{
  public:
    DFFA90ReferencedObject(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DFFA90ListenerA
{
  public:
    DFFA90ListenerA(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerA();
};
class DFFA90ListenerB
{
  public:
    DFFA90ListenerB(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerB();
};
class DFFA90ListenerC
{
  public:
    DFFA90ListenerC(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerC();
};
class DFFA90ListenerD
{
  public:
    DFFA90ListenerD(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerD();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class DFFA90ListenerE
{
  public:
    DFFA90ListenerE(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerE();
};
class FUN_00dffa90 : public DFFA90ReferencedObject,
                     public DFFA90ListenerA,
                     public DFFA90ListenerB,
                     public DFFA90ListenerC,
                     public DFFA90ListenerD,
                     public DFFA90ListenerE
{
  public:
    FUN_00dffa90(DFFA90FinishFlag flag);
    virtual ~FUN_00dffa90();
};
class FUN_00dffba0_cls
{
  public:
    virtual void v0(int arg);
};
int* __cdecl FUN_00dffbd0();
void* __cdecl FUN_00dffc50();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00dffc70();
extern int DAT_010e7c24;
void* FUN_00dffd90();
extern int DAT_010cc0d8;
// FUN_00dffdd0 : a one-line function - getter
void* FUN_00dffdd0();
extern int DAT_010c6e34;
void* FUN_00dffe10();
void* __cdecl FUN_00dffe30();
extern int DAT_010d3838;
void* __cdecl FUN_00dffe50();
void* __cdecl FUN_00dffe70();
// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dffec0_cls
{
  public:
    virtual int v0(int a) = 0;
};
void* __cdecl FUN_00dffed0();
extern int DAT_010cb798;
int __cdecl FUN_00dfff10();
extern int DAT_010da004;
struct SpawnedSub
{
    int unk00;
    int unk04;
    unsigned int unk08;
};
struct SpawnedObject
{
    int* vptr;
    int unk04;
    int unk08;
    SpawnedSub m_0c;
};
extern int DAT_010da004;
int* __cdecl FUN_00dfff70();
struct S_00dfff80_Foo
{
};
// FUN_00dfffd0 : a one-line function - getter
void* FUN_00dfffd0();
extern void* DAT_010e80b4;
class hkVector4_de1210
{
  public:
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4_de1210& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents[i];
    }
};
class hkMatrix3_de1210
{
  public:
    hkVector4_de1210 m_kColumn0;
    hkVector4_de1210 m_kColumn1;
    hkVector4_de1210 m_kColumn2;
    __forceinline void setIdentity()
    {
        hkVector4_de1210 zero;
        zero.setZero();
        const float one = 1.0f;
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn0(0) = one;
        m_kColumn1(1) = one;
        m_kColumn2(2) = one;
    }
};
class hkReferencedObject_de1210
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObject_de1210()
    {
        m_sReferenceCount = 1;
    }
};
class Base_de1210 : public hkReferencedObject_de1210
{
  public:
    int m_iUnk08;
    hkMatrix3_de1210 m_kRotationMatrix;
    hkVector4_de1210 m_kVec40;
    int m_iUnk50;

    Base_de1210()
    {
        m_iUnk08 = 0;
        m_iUnk50 = 3;
        m_kRotationMatrix.setIdentity();
        m_kVec40.setZero();
    }
    virtual void v00();
};
class FUN_00de1210 : public Base_de1210
{
  public:
    hkVector4_de1210 m_kVec60;
    hkVector4_de1210 m_kVec70;

    FUN_00de1210();
    virtual void v00();
};
struct DE1FC0Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};
struct DE1FC0Rotation
{
    DE1FC0Vector4 m_kColumn0;
    DE1FC0Vector4 m_kColumn1;
    DE1FC0Vector4 m_kColumn2;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};
class DE1FC0ReferencedObject
{
  public:
    DE1FC0ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfunc00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DE1FC0Transform : public DE1FC0ReferencedObject
{
  public:
    DE1FC0Transform()
    {
        m_ulUserData = 0;
        m_type = 2;
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }

    int m_ulUserData;
    int unk0C;
    DE1FC0Rotation m_rotation;
    DE1FC0Vector4 m_vTranslation;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de1fc0 : public DE1FC0Transform
{
  public:
    FUN_00de1fc0();
    virtual void vfunc01();

    DE1FC0Vector4 m_extra;
};
// Return a copy of the stored 4-float value.
struct DE5300Vector4
{
    float x;
    float y;
    float z;
    float w;
};
class DE5300Object
{
  public:
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    DE5300Vector4 m_kValue;

    DE5300Vector4 GetValue() const;
};
struct DE5450Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents[i];
    }
    void operator=(const DE5450Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct DE5450Transform
{
    DE5450Vector4 m_kColumn0;
    DE5450Vector4 m_kColumn1;
    DE5450Vector4 m_kColumn2;
    DE5450Vector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};
class DE5450ReferencedObject
{
  public:
    DE5450ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DE5450Shape : public DE5450ReferencedObject
{
  public:
    DE5450Shape() : m_ulUserData(0), m_type(4)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE5450Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de5450 : public DE5450Shape
{
  public:
    FUN_00de5450();
    virtual void unk00();

    DE5450Vector4 m_vecA;
    DE5450Vector4 m_vecB;
    int m_uiItemCount;
    float m_valueA;
    float m_valueB;
};
struct FourFloatVector
{
    float x, y, z, w;
};
struct Matrix64
{
    FourFloatVector a, b, c, d;
};
struct Input
{
    int count;
    float a, b;
    FourFloatVector vector;
    unsigned* values;
    void* source;
    Matrix64* matrices;
    float scale;
    unsigned flags;
};
struct Header
{
    union
    {
        float epsilon;
        unsigned char type;
    };
    unsigned short count, pad06;
    unsigned flags, unk0c, size;
    float scale, a, b;
};
extern "C" const __m128 DAT_011b9490;
// @fnv 0x00df2740
extern "C" __m128 __cdecl FUN_00df2740()
{
    return DAT_011b9490;
}
// which resets the runtime caches and re-links the embedded collidable to its owner.
struct DF6500FinishFlag
{
    int m_bFinishing;
};
struct DF6500Collidable
{
    int m_pCollisionShape;
    char m_type;
    signed char m_iOwnerOffset;
    short m_pad06;
    int m_unk08;
    void SetOwnerPointer(void* owner)
    {
        m_iOwnerOffset = (signed char)((unsigned int)owner - (unsigned int)this);
    }
};
struct DF6500Object
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    DF6500Collidable m_kCollidable;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    short m_unk40;
    short m_unk42;
    int m_unk44;
    int m_unk48;

    DF6500Object(DF6500FinishFlag flag)
    {
        if (flag.m_bFinishing)
        {
            m_unk40 = 0;
            m_unk42 = 0;
            m_unk44 = 0;
            m_unk48 = 0;
            m_unk30 = 0;
            m_unk20 = 1;
            m_kCollidable.SetOwnerPointer(this);
        }
    }
};
void FUN_00df6500(void* p, int finishing);
struct BDFCA00FinishFlag
{
    int m_bFinishing;
};
struct BDFCA00UpdateFlag
{
    BDFCA00UpdateFlag(char cValue) : m_cValue(cValue)
    {}
    BDFCA00UpdateFlag(const BDFCA00UpdateFlag& kOther) : m_cValue(kOther.m_cValue)
    {}

    char m_cValue;
};
class BDFCA00Object
{
  public:
    __forceinline BDFCA00Object(BDFCA00FinishFlag kFlag)
    {
        if (kFlag.m_bFinishing && m_bModifierActive)
        {
            reinterpret_cast<::FUN_00cdea00_cls *>(this)->FUN_00cdea00((*(char *)&(const ::BDFCA00UpdateFlag &)(BDFCA00UpdateFlag(1))));
        }
    }
    virtual ~BDFCA00Object();


    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    short unk114;
    bool m_bModifierActive;
};
struct FnvCpu_FUN_00de1150_CpuObject
{
    char* FUN_00de1150();
};
struct FnvCpu_FUN_00de1160_CpuObject
{
    char* FUN_00de1160();
};
struct FnvCpu_FUN_00de4de0_CpuObject
{
    char* FUN_00de4de0();
};
void __cdecl FUN_00de8140();
void __cdecl FUN_00de8160();
void __cdecl FUN_00de8180(void);
void FUN_00de81c0();
void FUN_00de81e0();
void __cdecl FUN_00de8200();
void FUN_00de8220();
void __cdecl FUN_00de8240();
void __cdecl FUN_00de8260();
void __cdecl FUN_00de8280();
void __cdecl FUN_00de82a0();
void __cdecl FUN_00de82c0();
void __cdecl FUN_00de82e0();
void __cdecl FUN_00de8300();
void __cdecl FUN_00de8320();
void __cdecl FUN_00de8340();
void __cdecl FUN_00de8360();
void __cdecl FUN_00de8380(void);
void __cdecl FUN_00de83a0();
void __cdecl FUN_00de83c0();
void FUN_00de83e0();
void FUN_00de8400();
void __cdecl FUN_00de8420();
void FUN_00de8440();
void FUN_00de8460();
void __cdecl FUN_00de8480();
void FUN_00de84a0();
void __cdecl FUN_00de84c0();
void __cdecl FUN_00de84e0();
void FUN_00de8500();
void FUN_00de8520();
void FUN_00de8540();
void FUN_00de8590();
void FUN_00de85a0();
void FUN_00de85b0();
void FUN_00de85c0();
void __cdecl FUN_00de85d0();
void FUN_00de85e0();
void __cdecl FUN_00de85f0();
void __cdecl FUN_00de8600(void);
void __cdecl FUN_00de8610();
void __cdecl FUN_00de8620();
void __cdecl FUN_00de8630();
void __cdecl FUN_00de8640();
void __cdecl FUN_00de8650();
void __cdecl FUN_00de8660();
void FUN_00de8670();
void __cdecl FUN_00de8680();
void FUN_00de8690();
void FUN_00de86a0();
void FUN_00de86b0();
void __cdecl FUN_00de86c0();
void FUN_00de86d0();
void __cdecl FUN_00de86e0();
void FUN_00de86f0();
void __cdecl FUN_00de8700();
void FUN_00de8710();
void FUN_00de8720();
void __cdecl FUN_00de8730();
void __cdecl FUN_00de8740();
void __cdecl FUN_00de8760();
struct stub_cls
{
    int unk00;
};
static void FUN_00df30c0(stub_cls* self, int v);
extern "C" int stub_val(void);
void stub_caller(stub_cls* self);
struct DF30D0Pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
static void CopyPairAtIndex(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void DF30D0Caller(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void FUN_00df3160();
void FUN_00df64a0();
void __cdecl FUN_00df6540();
struct FUN_00df7210_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m14;
};
struct FUN_00df7210_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df7210_Inner* m10;
    char* FUN_00df7210(char* out);
};
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010dba3c[];
struct MonitorStreamKd
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_capacityEnd;
};
struct TimerCommandKd
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};
static inline void TimerCommandKdWrite(const char* name)
{
    MonitorStreamKd* s = (MonitorStreamKd*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd)
    {
        TimerCommandKd* h = (TimerCommandKd*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
struct KdPair
{
    int m_kPointA;
    int m_kPointB;
};
struct KdJob
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int* m_2c;
    int m_30;
    int m_34;
    KdPair m_38;
};
struct KdQueue
{
};
struct FnvCpu_FUN_00df8920_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float FUN_00df8920();
};
void __cdecl FUN_00df9870();
void FUN_00df9b10();
void __cdecl FUN_00dfb250();
void FUN_00dfb350();
void FUN_00dfb370();
void FUN_00dfb4b0();
void __cdecl FUN_00dfb4c0();
void __cdecl FUN_00dfb4e0();
void __cdecl FUN_00dfb500(void);
void __cdecl FUN_00dfb520();
void FUN_00dfb530();
void __cdecl FUN_00dfb850();
void __cdecl FUN_00dfb870();
void __cdecl FUN_00dfb910();
void FUN_00dfb930(void);
void __cdecl FUN_00dfb9c0();
void __cdecl FUN_00dfbab0();
void FUN_00dfbb00();
void __cdecl FUN_00dfbb10();
void __cdecl FUN_00dfbcb0();
void __cdecl FUN_00dfbdb0();
void __cdecl FUN_00dfbe80();
void FUN_00dfbea0();
void FUN_00dfbec0();
void FUN_00dfbee0();
void __cdecl FUN_00dfbf00();
void __cdecl FUN_00dfbf10();
void FUN_00dfc020();
void FUN_00dfc0f0();
void FUN_00dfc210();
void __cdecl FUN_00dfc270();
void FUN_00dfc3c0();
void __cdecl FUN_00dfc3d0();
void __cdecl FUN_00dfc430(void);
void __cdecl FUN_00dfc4c0();
void __cdecl FUN_00dfc4e0();
void FUN_00dfc570();
void FUN_00dfc580();
void __cdecl FUN_00dfc5a0();
void FUN_00dfc5c0();
void __cdecl FUN_00dfc5e0();
void FUN_00dfc640();
void __cdecl FUN_00dfc650();
void FUN_00dfc670();
void FUN_00dfc6b0();
void __cdecl FUN_00dfc6e0();
void __cdecl FUN_00dfc720(void);
void __cdecl FUN_00dfc750();
void __cdecl FUN_00dfc7d0();
void __cdecl FUN_00dfc8b0();
void __cdecl FUN_00dfc8f0();
void FUN_00dfc920();
void FUN_00dfc960();
void __cdecl FUN_00dfc9b0();
void FUN_00dfc9f0();
void __cdecl FUN_00dfca40();
void __cdecl FUN_00dfca80();
void __cdecl FUN_00dfcab0();
void FUN_00dfcaf0();
void __cdecl FUN_00dfcb20(void);
void FUN_00dfcba0();
void __cdecl FUN_00dfcbe0();
void __cdecl FUN_00dfcc10();
void __cdecl FUN_00dfcc50();
void __cdecl FUN_00dfcc80();
void FUN_00dfccc0();
void __cdecl FUN_00dfccf0();
void __cdecl FUN_00dfcd30();
void FUN_00dfcd60();
void FUN_00dfcdc0();
void FUN_00dfce40();
void FUN_00dfce80();
void __cdecl FUN_00dfceb0();
void FUN_00dfced0();
void __cdecl FUN_00dfcee0();
void __cdecl FUN_00dfd0b0();
void __cdecl FUN_00dfd1a0();
void __cdecl FUN_00dfd220();
void __cdecl FUN_00dfd2b0();
void __cdecl FUN_00dfd340();
void FUN_00dfd350();
void __cdecl FUN_00dfd4d0();
void __cdecl FUN_00dfd4f0();
void __cdecl FUN_00dfd510();
void __cdecl FUN_00dfd520();
void __cdecl FUN_00dfd530();
void __cdecl FUN_00dfd550();
void __cdecl FUN_00dfd660();
void FUN_00dfd960();
void FUN_00dfddd0();
void FUN_00dfddf0();
void __cdecl FUN_00dfde60();
void __cdecl FUN_00dfde80();
void __cdecl FUN_00dfdea0();
void __cdecl FUN_00dfdf20();
void __cdecl FUN_00dfe080();
void __cdecl FUN_00dfe0b0();
void __cdecl FUN_00dfe0d0(void);
void FUN_00dfe0f0();
void FUN_00dfe110();
void FUN_00dfe130();
void FUN_00dfe150();
void FUN_00dfe170();
void FUN_00dfe190();
void FUN_00dfe1b0();
void __cdecl FUN_00dfe1d0();
void __cdecl FUN_00dfe200();
struct FnvCpu_FUN_00dfee80_CpuInterface
{
    virtual void Invoke(int value);
};
struct DestructibleDFF
{
    virtual ~DestructibleDFF();
};
struct S00de0fe0_Element
{
    virtual void vf00(int value);
};
struct S00de0fe0_Arr
{
    S00de0fe0_Element** data;
    int count;
    int cap;
    void FUN_00ddfb70();
};
struct S00de0fe0_Obj10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S00de0fe0_Local
{
    S00de0fe0_Arr arr;
    S00de0fe0_Obj10 o;
};
struct S00de0fe0_C983Obj
{
};
__declspec(noinline) void S00de0fe0_Arr::FUN_00ddfb70()
{
    count = 0;
}
void __cdecl FUN_00de0fe0(int arg1, int arg2, int arg3, int arg4);
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269fe8;
GlobalObjectO2_00d472a0* __cdecl FUN_00de8370();
struct cls_d530
{
    int unk00;
    float m_04;
};
extern "C" cls_d530* d530_target(void);
static void FUN_00def530(float value, cls_d530* target);
void d530_caller(cls_d530* self, float f);
struct d540_cls
{
    float unk00;
    float unk04;
};
extern "C" d540_cls* d540_target(void);
static void FUN_00def540(float a, float b, d540_cls* t);
void d540_caller(float fa, float fb);
struct def550_vec4
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
};
extern "C" def550_vec4* def550_target(void);
static void SetVec4(float a, float b, float c, float d, def550_vec4* t);
void def550_caller(float a, float b, float c, float d);
void FUN_00df0690();
static void FUN_00df30a0(int* piTarget, int iValue);
void E30A0Store(int* piTarget, int iValue);
struct ProfileEvent
{
    const void* volatile label;
    unsigned int cycles;
    unsigned int extra;
};
struct ThreadProfile
{
    void* owner;
    ProfileEvent* next;
    unsigned int capacity;
    ProfileEvent* end;
};
struct WorkItem
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    int remaining;
    unsigned int value;
    int processed;
    unsigned int unk2c;
};
struct WorkQueue
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20;
    WorkItem* tasks;
    int taskCount;
    int processorCount;
    void* processors[1];
};
struct ExecutionContext
{
};
extern unsigned long DAT_0126835c;
extern "C" const char str_010db918[];
extern "C" unsigned long DAT_0126835c;
struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};
struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};
static inline void TimerMark(const char* name)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
struct Key
{
    unsigned char m_type;
    unsigned char m_slot;
};
struct Job
{
    unsigned char m_type;
    unsigned char m_slot;
    unsigned char m_gap[0x16];
    int m_18;
    unsigned char m_gap2[0xc];
    int m_28;
    int m_2c;
};
struct Scheduler
{
};
struct FUN_00df9840_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* member10;
    int unk14;
    volatile long* member18;
    void FUN_00df9840();
};
extern "C" unsigned int df9ae0_val(void);
static float FUN_00df9ae0(unsigned int state);
volatile float df9ae0_sink;
void q_call_df9ae0(void);
static int g_w1 = 1;
static int g_ws = 3;
static float g_wv = 1.0f;
static __declspec(noinline) float FUN_00df9ae0(void)
{
    g_w1 = (g_w1 * 3) << (g_ws & 31);
    return g_wv;
}
static void WriteFloatToVector(float a, float b, float* out);
void dummy_caller(void);
struct FUN_00dfb5a0_cls
{
    int unk00;
    char* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FUN_00dfb5a0();
};
template <class T> inline void DestructElementsDFB5A0(T* p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i].FUN_00cb0c00();
    }
}
struct ElemDFB5A0
{
    int unk00;
    FUN_00cb0c00_class m_04;
    void FUN_00cb0c00()
    {
        ::FUN_00cb0c00((int)&(m_04));
    }
};
extern "C" void* df3210_target(void);
static void FUN_00df3210(__m128* p);
void df3210_caller(void);
struct Dst
{
    __m128 q;
};
static void FUN_00df3170(const unsigned short* src, Dst* d);
void CallerStandIn(Dst* d, const unsigned short* src);


class KdSimdReal
{
  public:
    __forceinline KdSimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __m128 m_vValue;
};
class KdVector4
{
  public:
    __forceinline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setMul4(const KdVector4& a, const KdVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const KdSimdReal& r, const KdVector4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    __forceinline void setAdd4(const KdVector4& a, const KdVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const KdVector4& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline float& operator()(int a)
    {
        return ((float*)&m_vComponents)[a];
    }
    __forceinline const float& operator()(int a) const
    {
        return ((const float*)&m_vComponents)[a];
    }
    __m128 m_vComponents;
};
class KdVector4Comparison
{
  public:
    enum Mask
    {
        MASK_X = 1,
        MASK_Y = 2,
        MASK_Z = 4
    };
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(m_uiMask);
    }
    __m128 m_uiMask;
};
class KdBool
{
  public:
    __forceinline KdBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct KdProjectedEntry
{
    __declspec(align(16)) unsigned short m_kMinimumCorner[3];
    unsigned short m_usFirstVectorPadding;
    unsigned short m_kMaximumCorner[3];
    unsigned short m_usSecondVectorPadding;
    __forceinline void operator=(const KdProjectedEntry& other)
    {
        *(__m128*)this = *(const __m128*)&other;
    }
};
struct KdWorkingSet
{
    KdProjectedEntry* m_pProjectedEntryBegin;
    KdProjectedEntry* m_pProjectedEntryEnd;
};
struct KdSplitResults
{
    int m_iFirstSplitValue;
    int m_iSecondSplitValue;
    unsigned short m_eLeftSplitType;
    unsigned short m_eRightSplitType;
};
namespace KdMath {
template <typename T> __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

static __forceinline __m128 KdToF32(__m128i v)
{
    __m128 two16 = _mm_setr_ps(DAT_010cd644, DAT_010cd644, DAT_010cd644, DAT_010cd644);
    __m128i hi = _mm_srli_epi32(v, 16);
    __m128i lo = _mm_srli_epi32(_mm_slli_epi32(v, 16), 16);
    return _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(hi), two16), _mm_cvtepi32_ps(lo));
}
static __declspec(noinline) void FUN_00df3170(const KdProjectedEntry& bounds, KdVector4& extentOut)
{
    __m128i packed = _mm_loadu_si128((const __m128i*)&bounds);
    __m128i zero = _mm_setzero_si128();
    __m128 lo = KdToF32(_mm_unpacklo_epi16(packed, zero));
    __m128 hi = KdToF32(_mm_unpackhi_epi16(packed, zero));
    extentOut.m_vComponents = _mm_sub_ps(hi, lo);
}
static __declspec(noinline) void FUN_00df3210(void* dst)
{
    __m128 zero = _mm_setzero_ps();
    __m128* p = (__m128*)dst;
    p[0] = zero;
    p[1] = zero;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    p[5] = zero;
    p[6] = zero;
    p[7] = zero;
}
__declspec(noinline) int __cdecl FUN_00df3250(unsigned short x)
{
    int y = x - 0x100;
    int n = (y >> 16) & 8;
    x = (unsigned short)(x << n);
    y = x - 0x1000;
    int m = (y >> 16) & 4;
    n += m;
    x = (unsigned short)(x << m);
    y = x - 0x4000;
    m = (y >> 16) & 2;
    n += m;
    x = (unsigned short)(x << m);
    y = x >> 14;
    m = y & ~(y >> 1);
    return n + 2 - m;
}
int __cdecl FUN_00df33b0(const KdWorkingSet& buffersIn, int startPrimIdx, int endPrimIdx, KdSplitResults& results,
                         KdWorkingSet& buffersOut, const KdProjectedEntry& bounds);

static __forceinline void KdGetDeltaSurfaceArea(const KdVector4& extent, KdVector4& areaOut, KdVector4& deltaOut)
{
    KdVector4 a;
    a.set(extent(1), extent(2), extent(0), 0.0f);
    KdVector4 b;
    b.set(extent(2), extent(0), extent(1), 0.0f);
    areaOut.setMul4(a, b);
    KdVector4 c;
    c.setMul4(0.125f, extent);
    deltaOut.setAdd4(a, b);
    deltaOut.mul4(c);
}

static __forceinline void initializeIterator(const KdProjectedEntry*& it, const KdProjectedEntry* p)
{
    it = p;
}
static __forceinline void reinitializeIterator(const KdProjectedEntry*& it, const KdProjectedEntry* p)
{
    it = p;
}
static __forceinline void initializeIterator(KdProjectedEntry* __restrict& it, KdProjectedEntry* p)
{
    it = p;
}

struct KdTreeBuilder
{
    static int __cdecl FUN_00df4ec0(const KdWorkingSet& buffersIn, int startPrimIdx, int endPrimIdx,
                                    KdSplitResults& results, int& numAvailableEmptyNodes, KdWorkingSet& buffersOut,
                                    const KdProjectedEntry& bounds, const KdVector4Comparison& allowedEmptySplits);
};

// @fnv 0x00df4ec0
int __cdecl KdTreeBuilder::FUN_00df4ec0(const KdWorkingSet& buffersIn, int startPrimIdx, int endPrimIdx,
                                        KdSplitResults& results, int& numAvailableEmptyNodes, KdWorkingSet& buffersOut,
                                        const KdProjectedEntry& bounds, const KdVector4Comparison& allowedEmptySplits)
{
    const int numPrims = endPrimIdx - startPrimIdx;
    if (numPrims == 2)
    {
        const KdProjectedEntry* readIt;
        initializeIterator(readIt, buffersIn.m_pProjectedEntryBegin + startPrimIdx);
        KdProjectedEntry* __restrict writeIt;
        initializeIterator(writeIt, buffersIn.m_pProjectedEntryEnd + startPrimIdx);
        KdProjectedEntry pe0 = *readIt;
        readIt++;
        KdProjectedEntry pe1 = *readIt;
        unsigned short size[3];
        size[0] = (unsigned short)(bounds.m_kMaximumCorner[0] - bounds.m_kMinimumCorner[0]);
        size[1] = (unsigned short)(bounds.m_kMaximumCorner[1] - bounds.m_kMinimumCorner[1]);
        size[2] = (unsigned short)(bounds.m_kMaximumCorner[2] - bounds.m_kMinimumCorner[2]);
        const int axis = size[0] > size[1] ? (size[0] > size[2] ? 0 : 2) : (size[1] > size[2] ? 1 : 2);
        const int splitIndex = startPrimIdx + 1;
        if (pe0.m_kMinimumCorner[axis] > pe1.m_kMinimumCorner[axis])
        {
            *writeIt = pe1;
            writeIt++;
            *writeIt = pe0;
            writeIt++;
            results.m_eRightSplitType = pe1.m_kMaximumCorner[axis];
            results.m_eLeftSplitType = pe0.m_kMinimumCorner[axis];
        }
        else
        {
            *writeIt = pe0;
            writeIt++;
            *writeIt = pe1;
            writeIt++;
            results.m_eRightSplitType = pe0.m_kMaximumCorner[axis];
            results.m_eLeftSplitType = pe1.m_kMinimumCorner[axis];
        }
        results.m_iFirstSplitValue = axis;
        results.m_iSecondSplitValue = splitIndex;
        buffersOut.m_pProjectedEntryEnd = buffersIn.m_pProjectedEntryBegin;
        buffersOut.m_pProjectedEntryBegin = buffersIn.m_pProjectedEntryEnd;
        return 0;
    }
    if (numPrims < 8)
    {
        return FUN_00df33b0(buffersIn, startPrimIdx, endPrimIdx, results, buffersOut, bounds);
    }

    const KdProjectedEntry* entriesIn = buffersIn.m_pProjectedEntryBegin;
    KdVector4 surfaceArea, surfaceDelta;
    KdVector4 extent;
    FUN_00df3170(bounds, extent);
    int splitBin = 0;
    int splitAxis = 0;
    KdGetDeltaSurfaceArea(extent, surfaceArea, surfaceDelta);
    __declspec(align(128)) int minBins[8][4];
    __declspec(align(128)) int maxBins[8][4];
    FUN_00df3210(minBins);
    FUN_00df3210(maxBins);
    int binShift[4];
    binShift[0] =
        KdMath::max2(13 - FUN_00df3250((unsigned short)(bounds.m_kMaximumCorner[0] - bounds.m_kMinimumCorner[0])), 0);
    binShift[1] =
        KdMath::max2(13 - FUN_00df3250((unsigned short)(bounds.m_kMaximumCorner[1] - bounds.m_kMinimumCorner[1])), 0);
    binShift[2] =
        KdMath::max2(13 - FUN_00df3250((unsigned short)(bounds.m_kMaximumCorner[2] - bounds.m_kMinimumCorner[2])), 0);

    const KdProjectedEntry* readIt;
    initializeIterator(readIt, entriesIn + startPrimIdx);
    int step = 1;
    if (numPrims > 10)
        step = 2;
    if (numPrims > 100)
        step = 3;
    if (numPrims > 1000)
        step = 4;
    if (numPrims > 10000)
        step = 5;

    for (int i = startPrimIdx; i < endPrimIdx; i += step)
    {
        KdProjectedEntry e = *readIt;
        minBins[(e.m_kMinimumCorner[0] - bounds.m_kMinimumCorner[0]) >> binShift[0]][0]++;
        maxBins[(e.m_kMaximumCorner[0] - bounds.m_kMinimumCorner[0]) >> binShift[0]][0]++;
        minBins[(e.m_kMinimumCorner[1] - bounds.m_kMinimumCorner[1]) >> binShift[1]][1]++;
        maxBins[(e.m_kMaximumCorner[1] - bounds.m_kMinimumCorner[1]) >> binShift[1]][1]++;
        minBins[(e.m_kMinimumCorner[2] - bounds.m_kMinimumCorner[2]) >> binShift[2]][2]++;
        maxBins[(e.m_kMaximumCorner[2] - bounds.m_kMinimumCorner[2]) >> binShift[2]][2]++;
        readIt += step;
    }

    const int numSamples = (numPrims + step - 1) / step;
    int bestLeft = numSamples;
    int bestRight = numSamples;
    float bestCost = 3.40282e+38f;
    KdBool allowEmpty = numAvailableEmptyNodes > 1;
    int masks[3] = {KdVector4Comparison::MASK_X, KdVector4Comparison::MASK_Y, KdVector4Comparison::MASK_Z};

    for (int axis = 0; axis < 3; axis++)
    {
        const float delta = surfaceDelta(axis);
        int numLeft = 0;
        int numRight = numSamples;
        float areaLeft = surfaceArea(axis);
        float areaRight = (float)(delta * 8.0 + surfaceArea(axis));
        for (int bin = 0; bin < 7; bin++)
        {
            numLeft += minBins[bin][axis];
            numRight -= maxBins[bin][axis];
            areaLeft += delta;
            areaRight -= delta;
            const float cost = numLeft * areaLeft + numRight * areaRight;
            KdBool valid =
                (allowEmpty && (allowedEmptySplits.GetLaneMask() & masks[axis]) != 0) || (numLeft > 0 && numRight > 0);
            if (cost < bestCost && valid)
            {
                splitAxis = axis;
                bestCost = cost;
                splitBin = bin;
                bestLeft = numLeft;
                bestRight = numRight;
            }
        }
    }

    const int splitValue =
        bounds.m_kMinimumCorner[(short)splitAxis] + (1 << binShift[(short)splitAxis]) * (splitBin + 1);
    unsigned short rightMin = bounds.m_kMaximumCorner[(short)splitAxis];
    unsigned short leftMax = bounds.m_kMinimumCorner[(short)splitAxis];
    KdProjectedEntry* __restrict left;
    initializeIterator(left, buffersIn.m_pProjectedEntryEnd + startPrimIdx);
    KdProjectedEntry* __restrict right;
    initializeIterator(right, buffersIn.m_pProjectedEntryEnd + (endPrimIdx - 1));
    reinitializeIterator(readIt, entriesIn + startPrimIdx);
    const KdProjectedEntry* endIt = entriesIn + endPrimIdx;
    int splitIndex;
    if (bestLeft >= numSamples && bestRight >= numSamples)
    {
        splitIndex = startPrimIdx + (numPrims >> 1);
        int i;
        for (i = startPrimIdx; i < splitIndex; i++)
        {
            const unsigned short maxE = readIt->m_kMaximumCorner[(short)splitAxis];
            *left = *readIt;
            left++;
            leftMax = KdMath::max2(leftMax, maxE);
            readIt++;
        }
        for (; i < endPrimIdx; i++)
        {
            const unsigned short minE = readIt->m_kMinimumCorner[(short)splitAxis];
            *left = *readIt;
            left++;
            rightMin = KdMath::min2(rightMin, minE);
            readIt++;
        }
    }
    else if (bestLeft >= numSamples)
    {
        while (readIt < endIt)
        {
            const unsigned short minE = readIt->m_kMinimumCorner[(short)splitAxis];
            const unsigned short maxE = readIt->m_kMaximumCorner[(short)splitAxis];
            if (maxE >= splitValue)
            {
                *right = *readIt;
                right--;
                rightMin = KdMath::min2(rightMin, minE);
            }
            else
            {
                *left = *readIt;
                left++;
                leftMax = KdMath::max2(leftMax, maxE);
            }
            readIt++;
        }
        splitIndex = (int)(left - buffersIn.m_pProjectedEntryEnd);
    }
    else
    {
        while (readIt < endIt)
        {
            const unsigned short minE = readIt->m_kMinimumCorner[(short)splitAxis];
            const unsigned short maxE = readIt->m_kMaximumCorner[(short)splitAxis];
            if (minE >= splitValue)
            {
                *right = *readIt;
                right--;
                rightMin = KdMath::min2(rightMin, minE);
            }
            else
            {
                *left = *readIt;
                left++;
                leftMax = KdMath::max2(leftMax, maxE);
            }
            readIt++;
        }
        splitIndex = (int)(left - buffersIn.m_pProjectedEntryEnd);
    }

    if (splitIndex == startPrimIdx || splitIndex == endPrimIdx)
    {
        numAvailableEmptyNodes -= 2;
    }
    results.m_eLeftSplitType = rightMin;
    results.m_eRightSplitType = leftMax;
    results.m_iSecondSplitValue = splitIndex;
    results.m_iFirstSplitValue = splitAxis;
    buffersOut.m_pProjectedEntryEnd = buffersIn.m_pProjectedEntryBegin;
    buffersOut.m_pProjectedEntryBegin = buffersIn.m_pProjectedEntryEnd;
    return 0;
}
