
// src/staging/blk_00540000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <cstddef>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00454380_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005532a0_cls.h"
#include "fnv/decl/FUN_005533f0_cls.h"
#include "fnv/decl/FUN_006242a0_cls.h"
#include "fnv/decl/FUN_00c6a620_cls.h"
#include "fnv/decl/Root.h"
#include "fnv/decl/S_00c90db0_Foo.h"
#include "fnv/decl/ScriptLocals.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/_Helper_005534f0.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/fnv_00553440__S.h"
#include "fnv/decl/fnv_00553480__FUN_00553480_cls.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00456000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_011ca000.h"
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/Vec3.h"

typedef unsigned int U32;

struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();

};

struct FourFloatVector
{
    __m128 values;
};

struct FUN_00404eb0
{
    U32 flags;
    FUN_00404eb0(int context, int enabled, const char* filename, int line);
    ~FUN_00404eb0()
    {
        FUN_00404ee0();
    }
    void FUN_00404ee0();
};

struct __declspec(align(16)) FUN_00c681c0
{
    U32 header0, header1, header2, header3;
    FourFloatVector orientation;
    U32 unk20;
    U32 unk24;
    U32 unk28;
    U32 unk2c;
    U32 unk30;
    U32 unk34;
    U32 unk38;
    U32 unk3c;
    U32 unk40;
    U32 unk44;
    U32 unk48;
    U32 unk4c;
    U32 unk50;
    float alpha;
    U32 unk58;
    U32 unk5c;
    U32 unk60;
    U32 unk64;
    U32 unk68;
    U32 unk6c;
    U32 unk70;
    U32 unk74;
    U32 unk78;
    U32 unk7c;
    U32 unk80;
    U32 unk84;
    U32 unk88;
    U32 unk8c;
    U32 unk90;
    U32 unk94;
    U32 unk98;
    U32 unk9c;
    U32 unka0;
    U32 unka4;
    U32 unka8;
    U32 unkac;
    U32 unkb0;
    U32 unkb4;
    U32 unkb8;
    U32 unkbc;
    U32 unkc0;
    U32 unkc4;
    U32 unkc8;
    U32 unkcc;
    U32 unkd0;
    U32 unkd4;
    U32 unkd8;
    U32 unkdc;
    U32 unke0;
    U32 unke4;
    U32 unke8;
    U32 unkec;
    FUN_00c681c0();
    ~FUN_00c681c0()
    {
        FUN_00553520();
    }
    void FUN_00553520();
};

struct Component
{
};

void* __cdecl FUN_00553300(unsigned int);

struct CurveBase
{
    U32 field08, field0c, field10, field14, field18, field1c, field20;
};

struct CurveOwner
{
    U32 field00, field04;
};

struct ParticleSystem
{
    virtual void VFunction0();
    virtual void VFunction1();
    virtual void VFunction2();
    virtual void VFunction3();
    virtual void VFunction4();
    virtual void VFunction5();
    virtual void VFunction6();
    virtual void VFunction7();
    virtual void VFunction8();
    virtual void VFunction9();
    virtual void VFunction10();
    virtual void VFunction11();
    virtual void VFunction12();
    virtual void VFunction13();
    virtual void VFunction14();
    virtual void VFunction15();
    virtual void VFunction16();
    virtual void VFunction17();
    virtual void VFunction18();
    virtual void VFunction19();
    virtual void VFunction20();
    virtual void VFunction21();
    virtual void VFunction22();
    virtual void VFunction23();
    virtual void VFunction24();
    virtual void VFunction25();
    virtual void VFunction26();
    virtual void VFunction27();
    virtual void VFunction28();
    virtual void VFunction29();
    virtual void VFunction30();
    virtual void VFunction31();
    virtual void VFunction32();
    virtual void VFunction33();
    virtual void VFunction34();
    virtual void VFunction35();
    virtual void VFunction36();
    virtual void VFunction37();
    virtual void VFunction38();
    virtual void VFunction39();
    virtual void VFunction40();
    virtual void VFunction41();
    virtual void VFunction42();
    virtual void VFunction43();
    virtual void VFunction44();
    virtual void VFunction45();
    virtual void VFunction46();
    virtual void VFunction47();
    virtual void VFunction48();
    virtual void Update();
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
    unsigned int fieldc0;
    unsigned int fieldc4;
    unsigned int fieldc8;
    static void* operator new(std::size_t n)
    {
        return FUN_00553300(n);
    }
};

struct FUN_00c99ff0 : ParticleSystem
{
    FUN_00c99ff0(FUN_00c681c0*, FUN_006815c0*, FUN_006815c0*);
};

struct FUN_00554590
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    FUN_00554590();
};

struct FUN_0062d5c0 : CurveOwner, CurveBase
{
    FUN_0062d5c0();
};

struct FUN_0061f460
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    FUN_0061f460();
};

struct FUN_0062a460
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    FUN_0062a460();
};

struct FUN_00624150
{
    U32 header, body;
    FUN_00624150();
};

extern "C"
{
    extern float DAT_0102f104, DAT_0102f100, DAT_0102f0fc;
}

// @fnv 0x00554010
ParticleSystem* __cdecl FUN_00554010(const FUN_006815c0* origin)
{
    FUN_00404eb0 context(16, 1, str_0102ed68, 0x3c1b);
    FUN_00c681c0 source;
    FourFloatVector rotation;
    reinterpret_cast<::AlignedVector *>(&(source.orientation))->FUN_004a3f10((*(const ::AlignedVector *)(((::FourFloatVector *)(reinterpret_cast<::FUN_005532a0_cls *>(&(rotation))->FUN_005532a0(0.0f, 0.0f, ::runtimeInitializationFloat2390, 0.0f))))));
    reinterpret_cast<::S_00c90db0_Foo *>(&(source))->FUN_00c90db0(FUN_004a3e90(DAT_0102f104));
    FUN_006815c0 direction;
    direction = *origin;
    direction.z = 0.0f;
    source.alpha = 1.0f;
    __declspec(align(16)) FUN_006815c0 velocity;
    *((float *)&(reinterpret_cast<::bhkCharacterController *>(&(velocity))->GetVectorElement(0))) = FUN_004a3e90(DAT_0102f100);
    *((float *)&(reinterpret_cast<::bhkCharacterController *>(&(velocity))->GetVectorElement(1))) = FUN_004a3e90(DAT_0102f100);
    *((float *)&(reinterpret_cast<::bhkCharacterController *>(&(velocity))->GetVectorElement(2))) = FUN_004a3e90(DAT_0102f100);
    __declspec(align(16)) FUN_006815c0 acceleration;
    *((float *)&(reinterpret_cast<::bhkCharacterController *>(&(acceleration))->GetVectorElement(0))) = FUN_004a3e90(DAT_0102f0fc);
    *((float *)&(reinterpret_cast<::bhkCharacterController *>(&(acceleration))->GetVectorElement(1))) = FUN_004a3e90(DAT_0102f0fc);
    *((float *)&(reinterpret_cast<::bhkCharacterController *>(&(acceleration))->GetVectorElement(2))) = FUN_004a3e90(DAT_0102f0fc);
    ParticleSystem* system = new FUN_00c99ff0(&source, &velocity, &acceleration);
    reinterpret_cast<::TESForm *>((((::Component *)(reinterpret_cast<::ScriptLocals *>((system))->GetLocalData()))))->ClearData();
    reinterpret_cast<::FUN_005533f0_cls *>((system))->FUN_005533f0((uintptr_t)(new FUN_00554590()));
    reinterpret_cast<::fnv_00553480::FUN_00553480_cls *>((system))->FUN_00553480((char *)(::CurveBase *)(new FUN_0062d5c0()));
    reinterpret_cast<::FUN_00c6a620_cls *>((system))->SetField(((void *)(::FUN_0062f3d0())));
    reinterpret_cast<::_Helper_005534f0 *>((system))->FUN_005534f0(new FUN_0061f460());
    reinterpret_cast<::fnv_00553440::S *>((system))->FUN_00553440((intptr_t)(((void *)(::FUN_00453720()))));
    reinterpret_cast<::FUN_005533f0_cls *>((system))->FUN_005533f0((uintptr_t)(new FUN_0062a460()));
    if (!DAT_011ca088)
        DAT_011ca088 = new FUN_00624150();
    reinterpret_cast<::FUN_006242a0_cls *>((DAT_011ca088))->NotifyActivation((::ActivationListener *)(::Component *)(((::Component *)(reinterpret_cast<::ScriptLocals *>((system))->GetLocalData()))));
    ::FUN_00c68750((const ::SourcePoint *)(system));
    reinterpret_cast<::TESForm *>((((::Component *)(reinterpret_cast<::ScriptLocals *>((system))->GetLocalData()))))->ClearData();
    system->Update();
    reinterpret_cast<::FUN_00454380_Class *>((system))->FUN_00454380(!((bool)(::FUN_00456c70())));
    reinterpret_cast<::Root *>((system))->SetProcessEnabled(0);
    return system;
}

class NiPoint3;

struct hkVector4
{
    __m128 m_vComponents;
};

class Obj554720
{
  public:
    void FUN_00c9a1f0(const hkVector4& v);
    void FUN_00554720(const NiPoint3& pt);
};

// @fnv 0x00554720
void Obj554720::FUN_00554720(const NiPoint3& pt)
{
    hkVector4 v;
    new ((void *)&(v)) ::Vec3();
    FUN_00c9a1f0((*(::hkVector4 *)&(::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(v), (const ::fnv_004a3e00::NiPoint3 &)(pt)))));
}

#include "generated/data/staging/blk_00540000_o2_od_noo2_variant.inc"
