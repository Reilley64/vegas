
// src/fallout_shared/teswater_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Ob1 /GF /Oy- (unit src/fallout_shared/teswater_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /Ob1 /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/teswater_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teswater.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/C00c66300.h"
#include "fnv/decl/C6B540Manager.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00452df0_class.h"
#include "fnv/decl/FUN_00452e50_class.h"
#include "fnv/decl/FUN_00452e90_Class.h"
#include "fnv/decl/FUN_0045c780_shell.h"
#include "fnv/decl/FUN_0045c840_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004ed110_shell.h"
#include "fnv/decl/FUN_004ed1f0_shell.h"
#include "fnv/decl/FUN_004ed210_shell.h"
#include "fnv/decl/FUN_005281f0_Class.h"
#include "fnv/decl/FUN_005282d0_cls.h"
#include "fnv/decl/FUN_005285a0_Class.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_00a5a390_shell.h"
#include "fnv/decl/FUN_00c66310_class.h"
#include "fnv/decl/GridRefresh__Grid.h"
#include "fnv/decl/Host_4ed190.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/Shell451.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WS458200_Shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00452490__FUN_00452490_shell.h"
#include "fnv/decl/fnv_00452ed0__FUN_00452ed0_shell.h"
#include "fnv/decl/fnv_00454d50__FUN_00454d50_shell.h"
#include "fnv/decl/fnv_00457070__FUN_00457070_shell.h"
#include "fnv/decl/fnv_00457be0__OwnerProxy.h"
#include "fnv/decl/fnv_004581e0__FUN_004581e0_Class.h"
#include "fnv/decl/fnv_005283c0__QCellQueue.h"
#include "fnv/decl/fnv_006271b0__Owner.h"
#include "fnv/decl/fnv_00628da0__LoadedAreaBound.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s4e5e50__Owner.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00451000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_0049e000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "teswater_decls.h"
#include "teswater_work.h"
extern int DAT_0109cb9c;
struct FUN_00a6fae0_Class
{
    void FUN_00a6fae0();
};
// Lazily create the shader property for this geometry, picking the shader type by whether the geometry is skinned.
class B9F30MemoryManager
{
  public:
    void Deallocate(void* pvMem);
};
struct B9F30SkinData
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
    void* m_pkSkinInstance;
};
class B9F30Geometry
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
    B9F30SkinData* m_pkSkinData;
};
class B9F30Property
{
  public:
    B9F30Property(B9F30Geometry* pkGeometry, int m_iPassId, ...);

    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::B9F30MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        (*reinterpret_cast<::B9F30MemoryManager *>(&::g_memoryManager)).Deallocate(pvMem);
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
class B9F30Owner
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
    B9F30Property* m_pkProperty;

    B9F30Property* FUN_00b69f30(B9F30Geometry* pkGeometry);
};

struct B006815c0
{
    float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    B006815c0();
};
struct NiMatrix
{
    float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    NiMatrix FUN_004ed140(const NiMatrix&);
};
struct NiMatrixEx : NiMatrix
{
    float unk40, unk44;
};
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    hkVector4();
};
struct CameraMatrixSource
{
};
struct NiPoint3_ext : NiPoint3
{
};
NiPoint3* FUN_004ed180();
struct NiVec4
{
    float x, y, z, w;
};
struct NiRenderer
{
};
struct WaterPlaneHost
{
    void FUN_004ecef0(float, float, float, float, int);
};
// @fnv 0x004ecef0
void WaterPlaneHost::FUN_004ecef0(float x, float y, float z, float w, int unused)
{
    B006815c0 view, projection, inverse;
    NiMatrixEx translated;
    reinterpret_cast<::FUN_004ed110_shell *>(&(translated))->CopyFrom(reinterpret_cast<::FUN_004ed1f0_shell *>((((::CameraMatrixSource *)(::FUN_004a0e90()))))->GetOffset980());
    translated.m41 =
        -reinterpret_cast<::FUN_004b6190_shell *>((void *)(static_cast<NiPoint3_ext*>(FUN_004ed180())))->DotProduct((void *)&(const ::NiPoint3 &)(NiPoint3(translated.m11, translated.m21, translated.m31)));
    translated.m42 =
        -reinterpret_cast<::FUN_004b6190_shell *>((void *)(static_cast<NiPoint3_ext*>(FUN_004ed180())))->DotProduct((void *)&(const ::NiPoint3 &)(NiPoint3(translated.m12, translated.m22, translated.m32)));
    translated.m43 =
        -reinterpret_cast<::FUN_004b6190_shell *>((void *)(static_cast<NiPoint3_ext*>(FUN_004ed180())))->DotProduct((void *)&(const ::NiPoint3 &)(NiPoint3(translated.m13, translated.m23, translated.m33)));
    NiMatrixEx project;
    reinterpret_cast<::FUN_004ed110_shell *>(&(project))->CopyFrom(reinterpret_cast<::FUN_004ed210_shell *>((((::CameraMatrixSource *)(::FUN_004a0e90()))))->GetOffsetPointer());
    NiMatrix transform = translated.FUN_004ed140(project);
    ::FUN_00ee6dda();
    ::FUN_00ee6dd4();
    hkVector4 plane, result;
    plane.x = x;
    plane.y = y;
    plane.z = z;
    plane.w = w;
    ::FUN_00ee6dce(&plane, &plane);
    ::FUN_00ee6dc8((::D3DXPLANE *)(::hkVector4 *)(&result), (const ::D3DXPLANE *)(const ::hkVector4 *)(&plane), (const ::D3DXMATRIX *)(const void *)(&transform));
    NiVec4 output;
    output.x = result.x;
    output.y = result.y;
    output.z = result.z;
    output.w = result.w;
    reinterpret_cast<::Host_4ed190 *>((::FUN_0043c4b0()))->CallFooForEachElement((char *)(0), 1, (int *)(&output));
}
