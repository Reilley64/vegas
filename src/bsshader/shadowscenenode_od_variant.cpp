
// src/bsshader/shadowscenenode_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/shadowscenenode.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00b9bc50_t.h"
#include "fnv/decl/MultiBoundOwner.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01203000.h"
#include "shadowscenenode_local.h"

struct FUN_00c5b5a0_cls
{
    int __thiscall FUN_00c5b5a0(int idx);
};

// @fnv 0x00c5b5a0
int __thiscall FUN_00c5b5a0_cls::FUN_00c5b5a0(int idx)
{
    int* p = *(int**)((char*)this + 0x40) + idx;
    int result = *p;
    return result;
}

extern "C" char DAT_01070c70;
struct Rect2180
{
    float x[4];
    Rect2180(float, float, float, float);
};
struct Frustum2180
{
    float left, right, top, bottom, nearz, farz;
    bool ortho;
    Frustum2180(bool);
};
struct Point2180
{
    float x, y, z;
    Point2180(float, float, float);
};
struct Update2180
{
    int data[3];
};
struct String2180
{
    int value;
    String2180(const char*);
    ~String2180();
};
struct Setting2180
{
};
struct Provider2180
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual float get();
};
struct FUN_00a712f0
{
    int bytes[0x114 / 4];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
};
struct Target2180
{
    FUN_00a712f0* FUN_007c2180();
};
// @fnv 0x007c2180
FUN_00a712f0* Target2180::FUN_007c2180()
{
    FUN_00a712f0* camera5 = new FUN_00a712f0;
    Rect2180 rect(0.0f, 1.0f, 1.0f, 0.0f);
    reinterpret_cast<::_Cam_00712e60 *>((camera5))->FUN_00712e60((const ::_Rect16_00712e60 &)(rect));
    Frustum2180 frustum5(false);
    frustum5.farz = ((::Provider2180 *)(::FUN_0045c670()))->get();
    frustum5.nearz = *((float *)&(::FUN_00403e20((float *)(((Setting2180*)&(*reinterpret_cast<char *>(&::g_01203144)))))));
    reinterpret_cast<::FUN_00507700_cls *>((camera5))->FUN_00507700(frustum5.farz / frustum5.nearz);
    float ratio3 = (double)(*(unsigned char*)&(*reinterpret_cast<char *>(&::DAT_011f9426)) ? *(int*)&(*reinterpret_cast<char *>(&::DAT_011f9434)) : FUN_004dc200()) / ((int)(::FUN_004dc1f0()));
    float nearz = *(float*)&(*reinterpret_cast<char *>(&::DAT_01016264));
    float angle = *((float *)&(::FUN_00403e20((float *)(((Setting2180*)&(*reinterpret_cast<char *>(&::g_01203150))))))) * *(double*)&(*reinterpret_cast<char *>((void *)&::DAT_01023128)) * *(double*)&DAT_01070c80;
    frustum5.left = -FUN_0057dd70(angle) * nearz;
    frustum5.right = FUN_0057dd70(angle) * nearz;
    frustum5.bottom = -FUN_0057dd70(angle) * ratio3 * nearz;
    frustum5.top = FUN_0057dd70(angle) * ratio3 * nearz;
    frustum5.ortho = false;
    reinterpret_cast<::NiCamera *>((camera5))->UpdateViewFrustum((const ::NiFrustum &)(frustum5));
    reinterpret_cast<::CamLook *>((camera5))->SetLookAt((const ::CamPoint &)((const ::Point2180 &)(Point2180(0.0f, 0.0f, 1.0f))), (const ::CamPoint &)((const ::Point2180 &)(Point2180(0.0f, 0.0f, 1.0f))));
    reinterpret_cast<::FUN_00733fd0_shell *>((camera5))->FUN_00733fd0(1.0f);
    Update2180 update2;
    new ((void *)&(update2)) ::NiUpdateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((camera5))->FUN_00a59c60((int)&(update2));
    ::AssignFixedString((char *)(camera5), (int)&(const ::String2180 &)(String2180(&DAT_01070c70)), {});
    return camera5;
}
