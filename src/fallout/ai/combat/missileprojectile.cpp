
// src/fallout/ai/combat/missileprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/missileprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x009b7cb0
#include "fnv/simple_array_item.h"
#include "fnv/vats_camera_data_view.h"
#include "fnv/tls.h"
#include <cstdint>
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Dispatch_00c89dd0.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_004610f0_Class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd420_shell.h"
#include "fnv/decl/FUN_00508070_class.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00628f30_shell.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00885bd0_St.h"
#include "fnv/decl/FUN_008d8b80Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00966980_shell.h"
#include "fnv/decl/FUN_009669c0_Class.h"
#include "fnv/decl/FUN_009a7f80_shell.h"
#include "fnv/decl/FUN_009b7010_shell.h"
#include "fnv/decl/FUN_009b8a20_class.h"
#include "fnv/decl/FUN_009d9f00_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c89640_cls.h"
#include "fnv/decl/FUN_00cbd970.h"
#include "fnv/decl/Getter_9b8.h"
#include "fnv/decl/LoadProjectile52.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/ObjB300.h"
#include "fnv/decl/OrientationObject.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Projectile.h"
#include "fnv/decl/Projectile9c58.h"
#include "fnv/decl/ProjectileHit.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/ST_00931e50.h"
#include "fnv/decl/S_009c8c40.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ZProjectile.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00573ed0___dummy_4d9fa0.h"
#include "fnv/decl/fnv_005de0a0__FUN_005de0a0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/decl/fnv_009bda10__ProjectileRuntime.h"
#include "fnv/decl/fnv_009bf470__Ref9bf.h"
#include "fnv/decl/fnv_00cbe240__hkpHingeConstraintDataEx.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00631000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_009b7000.h"
#include "fnv/symbols_009c2000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0108f000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/FUN_00c89c80_obj.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Owner89730.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/C8DAC0Owner.h"
#include "fnv/decl/CB2FC0Object.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045bb20_cls.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004ad240_c.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008126e0_shell.h"
#include "fnv/decl/FUN_008b42e0_shell.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/ImageSpaceEffectParam.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/SceneC8E.h"
#include "fnv/decl/TESObjectREFR.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00cbdcb0__CBDCB0Owner.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009c5000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01196000.h"
#include "fnv/symbols_011a9000.h"
int __cdecl FUN_009b7cb0()
{
    return (*reinterpret_cast<int *>(&::DAT_011c6278));
}


struct FUN_009ba4d0_shell
{
    char const* const* GetArg1Ptr();
};

// @fnv 0x009ba4d0
char const* const* FUN_009ba4d0_shell::GetArg1Ptr()
{
    return &(*reinterpret_cast<const char *const *>(&::g_0126818c));
}

extern "C" void __cdecl FUN_00c89640(void*);

struct bhkConstraint
{
    virtual ~bhkConstraint();
    void* DestroyConstraint(unsigned int);
};

// @fnv 0x009ba4e0
void* bhkConstraint::DestroyConstraint(unsigned int flags)
{
    reinterpret_cast<::FUN_00c89640_cls *>((this))->FUN_00c89640_cls::~FUN_00c89640_cls();
    if (flags & 1)
        ::FUN_00aa1460(this, 16);
    return this;
}

struct BGSLoadFormBuffer
{
};

struct BeamProjectile
{
};

struct MissileProjectile : BeamProjectile
{
    void FUN_009baad0(BGSLoadFormBuffer*);
};

// Calls the base BeamProjectile load routine, then reads 4 bytes from the load buffer into this+0x150.
// @fnv 0x009baad0
void MissileProjectile::FUN_009baad0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::LoadProjectile52 *>(this)->LoadProjectile((::LoadBuf52 *)(apLoadGameBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x150)), 4);
}

namespace fnv_009bab70 {
struct BGSLoadFormBuffer;
struct Projectile
{
    void FUN_009c58e0(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct MissileProjectile : Projectile
{
    void FUN_009bab70(BGSLoadFormBuffer* apLoadGameBuffer);
};

void Projectile::FUN_009c58e0(BGSLoadFormBuffer* apLoadGameBuffer)
{}

// @fnv 0x009bab70
void MissileProjectile::FUN_009bab70(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Projectile9c58 *>(this)->FUN_009c58e0((::LoadBuffer9c58 *)(apLoadGameBuffer));
    ((int*)this)[0x150 / 4] = 0;
}
}  // namespace fnv_009bab70

struct BGSProjectile
{
public:
    bool FUN_009b88e0();
};

struct FUN_009b7c90_shell : BGSProjectile
{
    bool FUN_009b7c90();
};

// @fnv 0x009b7c90
bool FUN_009b7c90_shell::FUN_009b7c90()
{
    return reinterpret_cast<::FUN_004fd420_shell *>((void *)this)->FUN_004fd420(0x100);
}


struct bhkHingeConstraint : bhkConstraint
{
    void* FUN_009ba520(unsigned int);
};

// Destroys the constraint and, when flags has bit 0 set, frees the 0x10-byte object; returns this.
// @fnv 0x009ba520
void* bhkHingeConstraint::FUN_009ba520(unsigned int flags)
{
    reinterpret_cast<::FUN_00cbd970 *>((this))->FUN_00cbd970::~FUN_00cbd970();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

struct FUN_009b7a20_holder
{
    void* FUN_009b7a20(unsigned int);
};
struct FUN_009ba320_shell
{
    void FUN_009ba320(uintptr_t a, uintptr_t b);
    void FUN_009ba390(unsigned int);
};
struct ScriptLocalsX
{
};
struct FUN_009ba350_shell
{
    void* m_p;
    void FUN_009ba350(ScriptLocalsX* p);
};
// Calls FUN_009ba350 with a and FUN_009ba390 with b.
// @fnv 0x009ba320
void FUN_009ba320_shell::FUN_009ba320(uintptr_t auiFirst, uintptr_t auiSecond)
{
    reinterpret_cast<::FUN_009ba350_shell *>(this)->FUN_009ba350((::ScriptLocalsX *)(auiFirst));
    FUN_009ba390(auiSecond);
}
// @fnv 0x009ba350
void FUN_009ba350_shell::FUN_009ba350(ScriptLocalsX* p)
{
    *(void**)((char*)this + 0xc) = p ? ((void *)(::FUN_004ae750((void *)(p)))) : 0;
}

namespace fnv_009ba390 {
struct ScriptLocalsX
{
};
struct FUN_009ba390_shell
{
    void FUN_009ba390(ScriptLocalsX*);
};
// @fnv 0x009ba390
void FUN_009ba390_shell::FUN_009ba390(ScriptLocalsX* apScriptLocals)
{
    *(void**)((char*)this + 0x10) = apScriptLocals ? ((void *)(::FUN_004ae750((void *)(apScriptLocals)))) : 0;
}
}  // namespace fnv_009ba390

struct FUN_00cbe240_shell
{
};

struct FUN_009ba3d0_shell
{
    int m_iWordAt00;
    int m_iWordAt04;
    void FUN_009ba3d0(intptr_t a, intptr_t b, intptr_t c, intptr_t d);
};

// If the object stored at this+4 is non-null, forwards the four arguments to its SetLocalTransforms method.
// @fnv 0x009ba3d0
void FUN_009ba3d0_shell::FUN_009ba3d0(intptr_t a, intptr_t b, intptr_t c, intptr_t d)
{
    intptr_t obj = this->m_iWordAt04;
    if (obj)
        reinterpret_cast<::fnv_00cbe240::hkpHingeConstraintDataEx *>((((FUN_00cbe240_shell*)obj)))->SetLocalTransforms((*(const ::hkTransform *)(a)), (*(const ::hkTransform *)(b)), (*(const ::hkVector4 *)(c)), (*(const ::hkVector4 *)(d)));
}

struct FUN_004b5120
{
    FUN_004b5120();
};
struct FUN_009ba4a0 : FUN_004b5120
{
    int* m_iWordAt00;
    FUN_009ba4a0();
};
// Points the object's pointer at DAT_0108febc and increments DAT_01268188.
// @fnv 0x009ba4a0
FUN_009ba4a0::FUN_009ba4a0() : FUN_004b5120()
{
    m_iWordAt00 = &DAT_0108febc;
    DAT_01268188++;
}

extern int DAT_0108ffb4;
struct BaseS
{
    int a;
    int b;
    int c;
    int d;
    BaseS();
};
struct FUN_009ba570
{
    intptr_t v0;
    BaseS m;
    FUN_009ba570();
};
// Initializes v0 to the address of DAT_0108ffb4 and sets the embedded BaseS fields to 0, 1, 0, 0.
// @fnv 0x009ba570
FUN_009ba570::FUN_009ba570()
{
    v0 = (intptr_t)&DAT_0108ffb4;
    m.a = 0;
    m.b = 1;
    m.c = 0;
    m.d = 0;
}


struct FUN_009ba5c0_shell
{
    void* FUN_009ba5c0(unsigned int flags);
};

extern int DAT_0108ffb4;

struct FUN_009ba5f0_shell
{
    void* p;
    void FUN_009ba5f0();
};
// Calls FUN_009ba5f0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x009ba5c0
void* FUN_009ba5c0_shell::FUN_009ba5c0(unsigned int flags)
{
    reinterpret_cast<::FUN_009ba5f0_shell *>(this)->FUN_009ba5f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x009ba5f0
void FUN_009ba5f0_shell::FUN_009ba5f0()
{
    p = &DAT_0108ffb4;
    reinterpret_cast<::C89AC0_Owner *>((this))->SetChildObject((::C89AC0_Child *)(0));
}

namespace fnv_009ba610 {
struct FUN_009ba5f0_shell
{
    void FUN_009ba610();
};
// @fnv 0x009ba610
void FUN_009ba5f0_shell::FUN_009ba610()
{
    reinterpret_cast<::FUN_009ba5f0_shell *>(this)->FUN_009ba5f0();
}
}  // namespace fnv_009ba610

struct FUN_009ba630_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009ba610, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009ba630
void* FUN_009ba630_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::fnv_009ba610::FUN_009ba5f0_shell *>(this)->FUN_009ba610();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BGSSaveFormBuffer
{
};
void __cdecl SaveProjectile(BGSLoadFormBuffer*);
struct FUN_009baaa0_shell
{
    void FUN_009baaa0(BGSLoadFormBuffer* buffer);
};
// @fnv 0x009baaa0
void FUN_009baaa0_shell::FUN_009baaa0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<void(*)(void*, BGSLoadFormBuffer*)>(SaveProjectile)(this, buffer);
    reinterpret_cast<::FUN_00865e50_shell *>((reinterpret_cast<BGSSaveFormBuffer*>(buffer)))->FUN_00865e50(reinterpret_cast<char*>(this) + 0x150, 4, 0);
}

struct S5870_Buf;
struct S5870_Holder
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
    virtual int v116();
    char _pad[0x14c];
    int unk150;
    unsigned char b154;
    void FUN_009babe0();
    void LoadForm(BGSLoadFormBuffer*);
public:
    void FUN_009c5870(::S5870_Buf *);
};
// Loads from the buffer via FUN_009c5870, then either calls FUN_009babe0 or sets b154 to 1 depending on v116().
// @fnv 0x009bab20
void S5870_Holder::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::S5870_Holder *>(this)->FUN_009c5870((::S5870_Buf *)(apLoadGameBuffer));
    if (v116())
        FUN_009babe0();
    else
        b154 = 1;
}

struct XActor
{
};

struct ArrSI
{
};

struct PathingRequest
{
    bool IsRandomBelowRadiusThreshold();
public:
    float GetTargetRadius();
};

struct FUN_009a7f00_obj
{
};

struct BeamEffect
{
};

struct FUN_009bda10_shell
{
};

struct FUN_009b7cc0_shell
{
    void UpdateBeamFlags();
};

int DAT_011f2250;
struct Big;
struct Str;
namespace fnv_009b90b0 {

struct Obj;
struct Big;
struct V9;

struct V
{
    float x;
    float y;
    float z;
    void FUN_0062aea0();
};

struct V5
{
    float a;
    float b;
    float c;
    float d;
    float e;
    void FUN_0062aea0();
};

struct V6
{
    V5 q;
    float f;
};

struct V9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    V9* FUN_0043f8d0(V9* out, V9* b);
};

struct Xform
{
    V9 rot;
    V pos;
    float scale;
    Xform* FUN_0062c250(Xform* out, Xform* b);
    V* FUN_00524c40(V* out, V* b);
};

struct Vec3
{
    float x;
    int y;
    int z;
};

struct Str
{
    int p;
    Str(int s);
    ~Str();
};

struct Ctrl
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Ctrl(float f);
    ~Ctrl();
};

struct Item
{
    unsigned char unk00;
    unsigned char unk01;
};

struct Arr
{
    Item** FUN_00877a30(unsigned int i);
};

struct Rec
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
    intptr_t unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
};

struct List
{
};

struct ListH
{
};

struct Big
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
    void FUN_004a3f70(int a);
};

struct __declspec(align(16)) Res
{
    int unk00[200];
    Res();
    ~Res();
};

void* FUN_00aa13e0(unsigned int n);

struct Path
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Path();
    ~Path();
};

struct PathRef
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    PathRef(Path* p);
};

struct Name
{
    char buf[64];
    Name(int a);
};

struct Color
{
    float r;
    float g;
    float b;
    float a;
};

struct Handle
{
    int val;
};

struct HandleSrc
{
    int val;
};

struct Sub
{
    int unk00;
    bool FUN_008256d0();
};

struct Actor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual Obj* vfc();
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
    virtual Obj* vf9c(const Str& s);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void vfb8(V* v);
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void vfc8(Big* b);
    virtual void v051();
    virtual void vfd0(Obj* a, int b, int c, int d, int e);
    virtual void v053();
    virtual void v054();
    virtual void vfdc(Obj* a, int b);
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool vf100();
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
    virtual Obj* vf1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual V* vf1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void vf2a4();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float vf2bc(int a);
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
    Sub unk88;
    unsigned char unk8C;
    unsigned char unk8D;
    unsigned char unk8E;
    unsigned char unk8F;
    unsigned char unk90;
    unsigned char unk91;
    unsigned char unk92;
    unsigned char unk93;
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
    int unk14C;
    int unk150;
    int unk154;
    float unk158;

    void FUN_009b90b0();
};

struct Obj
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual Obj* vfc();
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
    virtual Obj* vf9c(const Str& s);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void vfb8(V* v);
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void vfc8(Big* b);
    virtual void v051();
    virtual void vfd0(Obj* a, int b, int c, int d, int e);
    virtual void v053();
    virtual void v054();
    virtual void vfdc(Obj* a, int b);
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool vf100();
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
    virtual Obj* vf1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual V* vf1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void vf2a4();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float vf2bc(int a);
    void RemoveLimb(int a);
    unsigned int FUN_0043b480();
    HandleSrc* FUN_0070c440(int* out);
    HandleSrc* FUN_00931ed0(int* out);
    Obj* FUN_0043b4f0(int* out);
    void FUN_00c6e390(V5* v);
};

struct Owner
{
    Obj* unk00;
    V unk04;
    int pad10;
    int pad14;
    int pad18;
    int pad1C;
    int pad20;
    int unk24;
    unsigned char unk28;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Arr unk20;
};

struct Glob
{
};




struct VRes
{
    void FUN_0053d280();
};

}  // namespace fnv_009b90b0
// Computes flags from the actor base's pathing/target state and the global flags, then sets each beam flag via FUN_005de0a0 and calls FUN_009bda10.
// @fnv 0x009b7cc0
void FUN_009b7cc0_shell::UpdateBeamFlags()
{
    bool bTime = ((unsigned int)(reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode)) == 4;

    bool bTarget = reinterpret_cast<PathingRequest*>(((void *)(reinterpret_cast<::Actor *>((reinterpret_cast<XActor*>(this)))->GetActorBase())))
                       ->IsRandomBelowRadiusThreshold();

    bool bPathing =
        bTime ? false
              : reinterpret_cast<::FUN_009a7f80_shell *>((void *)(reinterpret_cast<FUN_009a7f00_obj*>(((void *)(reinterpret_cast<::Actor *>((reinterpret_cast<XActor*>(this)))->GetActorBase())))))->FUN_009a7f80();

    bool bNewGame =
        reinterpret_cast<::FUN_00966980_shell *>((reinterpret_cast<FUN_009a7f00_obj*>(((void *)(reinterpret_cast<::Actor *>((reinterpret_cast<XActor*>(this)))->GetActorBase())))))->FUN_00966980() > 0.0;

    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(0x10, bTarget);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(1, bPathing);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(8, bPathing);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(0x20, bTarget && bPathing);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(2, !bTarget && bPathing);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(0x40, bNewGame && !bPathing);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(0x100, true);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(0x8000, !bPathing);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((reinterpret_cast<BeamEffect*>(this)))->FUN_005de0a0(0x2000, bPathing);

    reinterpret_cast<::fnv_009bda10::ProjectileRuntime *>((reinterpret_cast<FUN_009bda10_shell*>(this)))->FUN_009bda10();
}

struct FUN_009babe0_object
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
    virtual bool Check();
};

struct FUN_009babe0_impact
{
    FUN_009babe0_object* pObject;
};

struct FUN_009babe0_list
{
};

struct FUN_009b90b0_shell
{
};

struct FUN_009ba660_shell
{
    void HandleMissileImpact();
};

// @fnv 0x009babe0
void S5870_Holder::FUN_009babe0()
{
    FUN_009babe0_impact* pimpact;

    if (this->unk150 == 4 ||
        this->unk150 == 3)
    {
        pimpact = *((::FUN_009babe0_impact **)(((::Vec3 *)(void *)(reinterpret_cast<FUN_009babe0_list*>(reinterpret_cast<char*>(this) + 0x88)))));

        if (this->unk150 == 4)
        {
            pimpact = ((::FUN_009babe0_list *)(reinterpret_cast<::Callees *>((reinterpret_cast<FUN_009babe0_list*>(reinterpret_cast<char*>(this) + 0x88)))->FUN_00726070()))
                          ? *((::FUN_009babe0_impact **)(((::Vec3 *)(void *)(((::FUN_009babe0_list *)(reinterpret_cast<::Callees *>((reinterpret_cast<FUN_009babe0_list*>(reinterpret_cast<char*>(this) + 0x88)))->FUN_00726070()))))))
                          : 0;
        }

        if (pimpact && pimpact->pObject && pimpact->pObject->Check())
            reinterpret_cast<::fnv_009b90b0::Actor *>((reinterpret_cast<FUN_009b90b0_shell*>(this)))->FUN_009b90b0();
    }

    if (this->unk150 == 4)
        reinterpret_cast<FUN_009ba660_shell*>(this)->HandleMissileImpact();
}

extern int DAT_0108fa44;
extern int DAT_0108fa38;
struct BaseA
{
    void* vptr;
    int pad[5];
    BaseA(unsigned char a);
    ~BaseA();
};
struct FUN_009b7a50 : BaseA
{
    void* vptr2;
    int pad2[0x4d];
    int m150;
    unsigned char b154;
    float f158;
    float f15c;
    FUN_009b7a50(unsigned char a);
};
// Initialises the BaseA-derived object: sets both vtables, calls FUN_004f15a0(0x3d), and zeroes m150, b154, f158 and f15c.
// @fnv 0x009b7a50
FUN_009b7a50::FUN_009b7a50(unsigned char a) : BaseA(a)
{
    vptr = &DAT_0108fa44;
    vptr2 = &DAT_0108fa38;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x3d);
    m150 = 0;
    b154 = 0;
    f158 = 0.0f;
    f15c = 0.0f;
}

struct Vector3
{
    float x;
    float y;
    float z;
};
extern int DAT_0108fa44;
extern int DAT_0108fa38;

struct FUN_009bbef0
{
    int* m_primaryVtable;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    int* m_secondaryVtable;
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
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    FUN_009bbef0(int a, int b, int c, Vector3 position, float magnitude, float duration);
    ~FUN_009bbef0();
};

struct FUN_009b7af0 : FUN_009bbef0
{
    unsigned int unk150;
    unsigned char unk154;
    float unk158;
    float unk15c;

    FUN_009b7af0(int a, int b, int c, Vector3 position, float magnitude, float duration);
};

// Initialises the derived object: sets both vtables, calls FUN_004f15a0(61), and zeroes unk150, unk154, unk158 and unk15c.
// @fnv 0x009b7af0
FUN_009b7af0::FUN_009b7af0(int a, int b, int c, Vector3 position, float magnitude, float duration)
    : FUN_009bbef0(a, b, c, position, magnitude, duration)
{
    m_primaryVtable = &DAT_0108fa44;
    m_secondaryVtable = &DAT_0108fa38;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(61);
    unk150 = 0;
    unk154 = 0;
    unk158 = 0.0f;
    unk15c = 0.0f;
}

struct Base_b9999
{
    virtual ~Base_b9999();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct Sec_b9999
{
    virtual void v0();
};

struct Obj_b9999
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
    virtual Obj_b9999* v39(int);
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
    virtual void v58(Obj_b9999*);
};

struct FUN_009b7bc0_cls : Base_b9999, Sec_b9999
{
    virtual ~FUN_009b7bc0_cls();
};
// @fnv 0x009b7a20
void* FUN_009b7a20_holder::FUN_009b7a20(unsigned int flags)
{
    reinterpret_cast<::FUN_009b7bc0_cls *>(this)->FUN_009b7bc0_cls::~FUN_009b7bc0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x009b7bc0
FUN_009b7bc0_cls::~FUN_009b7bc0_cls()
{
    Obj_b9999* r;
    if (reinterpret_cast<FUN_009b7c90_shell*>(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))->FUN_009b7c90())
    {
        Obj_b9999* s;
        if (((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) != 0)
        {
            r = reinterpret_cast<Obj_b9999*>(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())))->v39(FUN_009b7cb0());
            if (r != 0)
            {
                s = ((::Obj_b9999 *)(reinterpret_cast<::FUN_009611e0_shell *>((r))->FUN_009611e0()));
                s->v58(r);
            }
        }
    }
}

struct NiRTTI
{
    int unk00;
};

struct NiPoint3s
{
    float x;
    float y;
    float z;
    NiPoint3s(float ax, float ay, float az);
    NiPoint3s operator-(const NiPoint3s& o) const;
};

struct NiBounds
{
    float cx;
    float cy;
    float cz;
    float radius;
};

struct NiUpdateDatas
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bUpdateSelected;
    int unk08;
    NiUpdateDatas(float t, bool a, bool b);
};

class NiAVObj
{
  public:
    virtual void a0();
};

class NiNodeS : public NiAVObj
{
  public:
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
    virtual void UpdateWorldData(NiUpdateDatas& data);
};


struct PathReq
{
};

class ProjS
{
  public:
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
    virtual NiAVObj* Get3D();

    void SetPosAndScale(float scale, NiPoint3s pt);
    void UpdateProjectileNodeVisibility();
};

// Updates the projectile's 3D node: toggles child culling by flag 0x10, rescales and repositions it from its bounds, and culls it when value A exceeds value B.
// @fnv 0x009b7e40
void ProjS::UpdateProjectileNodeVisibility()
{
    NiAVObj* p3D = Get3D();
    if (p3D && ::FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), (::NiAVObject *)(p3D)))
    {
        NiNodeS* pNode5 = (NiNodeS*)p3D;
        reinterpret_cast<::TaskQueueInterface *>((pNode5))->QueueActorDisarm(false);
        if (reinterpret_cast<::PathingRequest *>((((::PathReq *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetTargetRadius() > _DAT_01012060)
        {
            if (((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((pNode5))->FUN_0045bc00(0))))
                reinterpret_cast<::TaskQueueInterface *>((((::NiAVObj *)(reinterpret_cast<::NiNode *>((pNode5))->GetAt(0)))))->QueueActorDisarm(reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(0x10));
            if (((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((pNode5))->FUN_0045bc00(1))))
                reinterpret_cast<::TaskQueueInterface *>((((::NiAVObj *)(reinterpret_cast<::NiNode *>((pNode5))->GetAt(1)))))->QueueActorDisarm(!reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(0x10));
        }
        if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(0x10))
        {
            NiBounds bound5 = *((::NiBounds *)(reinterpret_cast<::FUN_0043d450_Owner *>((pNode5))->FUN_0043d450()));
            NiPoint3s diff2 = (*(::NiPoint3s *)&(reinterpret_cast<::NiAVObject *>((pNode5))->FUN_0043c490())) - *((::NiPoint3s *)(((::Vec3 *)(void *)&(bound5))));
            float fLen = reinterpret_cast<::NiPoint3 *>(&(diff2))->ComputeMagnitude() + reinterpret_cast<::Twin_0084d030 *>(&(bound5))->GetStoredFloatValue();
            float fScale3 = fLen / reinterpret_cast<::FUN_009669c0_Class *>(this)->FUN_009669c0();
            SetPosAndScale(fScale3, NiPoint3s(0.0f, fLen, 0.0f));
            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 1);
            NiUpdateDatas data(0.0f, false, false);
            pNode5->UpdateWorldData(data);
            if (reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070() > reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter())
                reinterpret_cast<::TaskQueueInterface *>((pNode5))->QueueActorDisarm(true);
        }
    }
}

struct HitItem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    bool flag;
};
struct HitList
{
    HitItem* value;
    void* next;
    bool FUN_008256d0();
};
struct Collider890
{
};
struct CF845
{
    int value;
    CF845(int);
};
struct Target890;
struct Target890
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
    HitList hits;
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
    int kind;
    bool FUN_009b8900(intptr_t, intptr_t, intptr_t, Collider890*, int, int);
};
// Checks the hit list and collider state, then calls ProcessHit and FUN_009b8a20 when the kind and collider conditions pass, returning true on success.
// @fnv 0x009b8900
bool Target890::FUN_009b8900(intptr_t aiArg1, intptr_t aiArg2, intptr_t aiArg3, Collider890* collider, int aiArg5, int aiArg6)
{
    bool p = hits.FUN_008256d0() || (*((::HitItem **)(((::Vec3 *)(void *)&(hits)))))->flag;
    int h = collider ? reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::CF845 &)(CF845(((int)(::FUN_0043b540((char *)(collider)))))))->FUN_0043b4d0() : 0;
    if (p && ::fnv_009c2c80::CanProjectileHit((::fnv_009c2c80::RefObj *)(aiArg1), (::fnv_009c2c80::CdBody *)(collider), (intptr_t)(this), (::fnv_009c2c80::ProjData *)(void *)(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))) &&
        (kind != 3 || h == 1 || h == 2 || h == 9 || h == 17 || h == 13 || h == 20) &&
        reinterpret_cast<::ProjectileHit *>(this)->ProcessHit((::Obj *)(aiArg1), (*(const ::Vec *)(aiArg2)), (*(const ::Vec *)(aiArg3)), (::Buffer *)(collider), aiArg5, aiArg6))
    {
        reinterpret_cast<::FUN_009b8a20_class *>(this)->FUN_009b8a20();
        return true;
    }
    return false;
}

class BA410Base
{
  public:
    BA410Base();
    virtual ~BA410Base();
};

class BA410Interface
{
  public:
    int unk00;
};

class BA410Source : public BA410Interface
{
  public:
    int unk04;
};

class BA410SourceLink
{
  public:
    int unk00;
};

class BA410Target : public BA410SourceLink, public BA410Source
{
};

class FUN_009ba410 : public BA410Base
{
  public:
    FUN_009ba410(BA410Target* pkTarget);
    virtual ~FUN_009ba410();


};

// Stores pkTarget as the source via SetSource and increments the static instance counter.
// @fnv 0x009ba410
FUN_009ba410::FUN_009ba410(BA410Target* pkTarget)
{
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach((intptr_t)(pkTarget));
    ++(*reinterpret_cast<unsigned int *>(&::DAT_01268434));
}

struct SpawnedBase
{
    virtual ~SpawnedBase();
    SpawnedBase();
};

struct FUN_009ba550 : SpawnedBase
{
    FUN_009ba550();
    virtual ~FUN_009ba550();
};

// @fnv 0x009ba550
FUN_009ba550::FUN_009ba550()
{}

struct UpdateVec
{
    float x, y, z;
    UpdateVec operator-(const UpdateVec&) const;
};
struct UpdateMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    UpdateMatrix();
    UpdateMatrix FUN_0043f8d0(const UpdateMatrix&);
};
struct UpdateTransform
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    UpdateVec translation;
    float scale;
    UpdateTransform FUN_0062c250(const UpdateTransform&);
};
struct UpdateNode
{
};
struct UpdateRef
{
    UpdateVec GetTargetPosition();
};
struct UpdateImpact
{
    unsigned int unk00;
    UpdateVec position;
    unsigned int unk10, unk14, unk18;
    UpdateRef* reference;
    unsigned int unk20, unk24;
    bool flag;
};
struct UpdateList
{
    UpdateImpact* value;
    void* next;
    bool FUN_008256d0();
};
struct UpdateBase
{
};
struct UpdateFloatSetting
{
};
struct UpdateBoolSetting
{
    bool* FUN_00408d60();
};
struct UpdateWorld
{
};
extern const char DAT_0108fd78[];
struct UpdateColor
{
    float r, g, b, a;
    UpdateColor(float, float, float, float);
};
struct UpdateProjectile
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
    virtual UpdateNode* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual UpdateVec* GetPosition();
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
    UpdateList hits;
    bool pending;
    UpdateTransform transform;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    int kind;
    bool active;
    float timeout;
    float angle;
    void FUN_009b8030(float);
};
// @fnv 0x009b8030
void UpdateProjectile::FUN_009b8030(float afDeltaTime)
{
    if (active && Get3D())
        reinterpret_cast<::S5870_Holder *>(this)->FUN_009babe0();
    if (reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070() > reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter() && (hits.FUN_008256d0() || pending))
        reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
    if (reinterpret_cast<::FUN_00440d80_shell *>(this)->FUN_00440d80() || reinterpret_cast<::TESForm *>(this)->GetDisabled())
        return;
    if (kind == 4)
    {
        timeout -= afDeltaTime;
        if (timeout <= 0.0)
            reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
    }
    if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(128) && kind == 4)
    {
        UpdateImpact* impact = *((::UpdateImpact **)(((::Vec3 *)(void *)&(hits))));
        if (impact)
        {
            UpdateRef* node = impact->reference ? ((::UpdateRef *)(::FUN_004b5820((::FormLike *)(void *)(((void *)(::FUN_00460140((intptr_t)(impact->reference)))))))) : 0;
            UpdateNode* reference = Get3D();
            if (node && reference)
            {
                UpdateTransform worldTransform = ((::UpdateTransform *)(::FUN_00461130((intptr_t)(node))))->FUN_0062c250(transform);
                reinterpret_cast<::FUN_0043fa80_s *>((reference))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&worldTransform)));
                reinterpret_cast<::ST_00931e50 *>(this)->FUN_009c6330((::ST_00a59400 *)(::UpdateTransform *)(&worldTransform));
                reinterpret_cast<::FUN_00440460_S *>((reference))->FUN_00440460((const ::V3 *)(::UpdateVec *)(&worldTransform.translation));
                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(&worldTransform.translation));
            }
            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(true, false);
        }
    }
    else if (!pending || reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(1) || kind == 3)
    {
        bool stopped = !(reinterpret_cast<::FUN_00885bd0_St *>(this)->FUN_00885bd0() > 0.0);
        bool skipPosition = false;
        if (((::UpdateRef *)(reinterpret_cast<::FUN_008d8b80Class *>(this)->FUN_008d8b80())))
        {
            reinterpret_cast<::OrientationObject *>(this)->SetOrientationFromDirection((*(::Vector3 *)&(const ::UpdateVec &)(((::UpdateRef *)(reinterpret_cast<::FUN_008d8b80Class *>(this)->FUN_008d8b80()))->GetTargetPosition())));
        }
        if (!stopped)
        {
            if (((::UpdateRef *)(reinterpret_cast<::FUN_008d8b80Class *>(this)->FUN_008d8b80())))
            {
                UpdateVec positionDelta = ((::UpdateRef *)(reinterpret_cast<::FUN_008d8b80Class *>(this)->FUN_008d8b80()))->GetTargetPosition() - *GetPosition();
                if (reinterpret_cast<::NiPoint3 *>(&(positionDelta))->ComputeMagnitude() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateFloatSetting *>(&::originalRuntimeFloatSetting803)))))))
                    skipPosition = true;
            }
            if (*(*reinterpret_cast<::UpdateBoolSetting *>(&::g_011f20ec)).FUN_00408d60())
            {
                UpdateVec newPosition = *GetPosition();
                reinterpret_cast<::ObjB300 *>(this)->ApplyScale(afDeltaTime);
                UpdateVec color = *GetPosition();
                UpdateColor debugColor(1.0f, 1.0f, 0.0f, 1.0f);
                void* pDebugLine = ((void *)(::fnv_004b3890::FUN_004b3890((*(const class ::FUN_006815c0 *)(&newPosition)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&debugColor)), (*(const class ::FUN_006815c0 *)(&color)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&debugColor)), 1)));
                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::UpdateWorld * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(pDebugLine), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateFloatSetting *>(&::g_011f210c)))))));
            }
            else
                reinterpret_cast<::ObjB300 *>(this)->ApplyScale(afDeltaTime);
        }
        bool nearby = hits.FUN_008256d0() || (*((::UpdateImpact **)(((::Vec3 *)(void *)&(hits)))))->flag;
        if (!nearby && (!reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(1) || reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070() > reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter()))
            reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(&(*((::UpdateImpact **)(((::Vec3 *)(void *)&(hits)))))->position));
        reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(skipPosition, !stopped);
        if (Get3D())
            reinterpret_cast<::NiAVObject *>((Get3D()))->UpdateWorldLoc();
        if (reinterpret_cast<::BGSProjectile *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88e0())
        {
            UpdateMatrix rotation;
            if (reinterpret_cast<::FUN_00812870_t *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetUnka4() > 0.0)
            {
                angle += reinterpret_cast<::FUN_00812870_t *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetUnka4() * afDeltaTime;
                reinterpret_cast<::FUN_00524ac0_shell *>(&(rotation))->FUN_00524ac0(angle);
            }
            else if (reinterpret_cast<::LowProcess *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetCurrentDetectionAmount() > 0.0)
            {
                angle += reinterpret_cast<::LowProcess *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetCurrentDetectionAmount() * afDeltaTime;
                reinterpret_cast<::ThreeByThreeMatrix *>(&(rotation))->SetYRotation(angle);
            }
            else if (reinterpret_cast<::Getter_9b8 *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88c0() > 0.0)
            {
                angle += reinterpret_cast<::Getter_9b8 *>((((::UpdateBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88c0() * afDeltaTime;
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rotation))->FUN_004a0c90(angle);
            }
            if (Get3D())
            {
                UpdateMatrix matrix = *((struct ::UpdateMatrix *)(::FUN_006a9540((char *)(Get3D()))));
                matrix = matrix.FUN_0043f8d0(rotation);
                reinterpret_cast<::FUN_0043fa80_s *>((Get3D()))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&matrix)));
            }
            else
                ::FUN_005b5e40();
        }
    }
    reinterpret_cast<::ZProjectile *>(this)->UpdateDetonation(afDeltaTime);
    if (reinterpret_cast<::FUN_00885bd0_St *>(this)->FUN_00885bd0() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateFloatSetting *>(&::originalRuntimeFloatSetting648)))))) && kind != 4)
        reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
    if (reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070() > reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter() && (hits.FUN_008256d0() || pending))
    {
        if (Get3D())
            reinterpret_cast<::TaskQueueInterface *>((Get3D()))->QueueActorDisarm(true);
        reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
    }
}

namespace ImpactResponse {
struct Impact;
struct Vector
{
    float x, y;

  private:
    float z;
    friend struct Impact;

  public:
};
Vector FUN_004a3760(float, const Vector&);
struct Matrix
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    Matrix();
    Vector FUN_004b4500(const Vector&);
};
struct Update
{
    float time;
    int flags, unknown;
    Update(float, int, int);
};
struct Node
{
};
struct Contact
{
    int unk00;
    Vector position, normal;
};
struct ContactList
{
    bool FUN_008256d0();
};
struct Physics
{
};
struct Game
{
};
struct Impact;
struct Selection
{
};
struct Setting
{
};
struct Base
{
};
struct Impact
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
    virtual Node* GetNode();
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
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void Refresh();
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
    ContactList contacts;
    bool HandleContactResponse();
};
// If the node has contacts, clears the selection, refreshes, applies physics and impulse/angular responses, and returns true.
// @fnv 0x009b8c90
bool Impact::HandleContactResponse()
{
    if (GetNode() && !contacts.FUN_008256d0())
    {
        if (((::ImpactResponse::Impact *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(&((*reinterpret_cast<::ImpactResponse::Selection *>(&::g_011f2250))))->FUN_007af430())) == this)
            reinterpret_cast<::S_009c8c40 *>(&((*reinterpret_cast<::ImpactResponse::Selection *>(&::g_011f2250))))->SetValue(0);
        Node* node7 = GetNode();
        Contact* contact = *((::ImpactResponse::Contact **)(((::Vec3 *)(void *)&(contacts))));
        reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(4, 1);
        Refresh();
        Physics* physics = ((::ImpactResponse::Physics *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(node7))));
        if (physics)
            reinterpret_cast<::fnv_00573ed0::_dummy_4d9fa0 *>((physics))->FUN_00573ed0(true);
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ImpactResponse::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && !((int)(reinterpret_cast<::FUN_009d9f00_Class *>(this)->FUN_009d9f00())))
        {
            reinterpret_cast<::FUN_00440460_S *>((node7))->FUN_00440460((const ::V3 *)&(contact->position));
            Update update(0.0f, 0, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((node7))->FUN_00a59c60((std::intptr_t)&(update));
        }
        ::FUN_00c6a350((::NiAVObject *)(node7), 1, 1, 0, 1);
        ::FUN_00c6a3d0(node7, ((int)(::FUN_005dbe10())), 1, 0);
        ::FUN_00c6a0b0((::NiAVObject *)(node7), 1, 1, 0);
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ImpactResponse::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
        {
            Vector linear_ = (*reinterpret_cast<::ImpactResponse::Vector *>((void *)&::NiPoint3::ZERO));
            Vector direction3;
            direction3 = FUN_004a3760(::DAT_01012054, (*(::ImpactResponse::Vector *)&(reinterpret_cast<::FUN_009b7010_shell *>(this)->FUN_009b7010(*(::NiPoint3 *)nullptr))));
            direction3 = direction3;
            ::FUN_00525340((float *)&(direction3));
            ::FUN_00525340((float *)&(contact->normal));
            float dot = reinterpret_cast<::FUN_004b6190_shell *>(&(contact->normal))->DotProduct((void *)&(direction3));
            Vector correctionTmp =
                FUN_004a3760(::DAT_010162c0, (*(::ImpactResponse::Vector *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(const ::ImpactResponse::Vector &)(FUN_004a3760(dot, contact->normal)))->FUN_00439ef0((::NiPoint3 *)&(direction3), *(const ::NiPoint3 *)nullptr))));
            linear_ = (*(::ImpactResponse::Vector *)(reinterpret_cast<::Point3Offset *>(&(direction3))->ProjectileLaunched((::NiPoint3 *)&(correctionTmp), {})));
            reinterpret_cast<::MyPoint439180 *>(&(linear_))->FUN_00439180(*((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactResponse::Setting *>(&::originalRuntimeFloatSetting650)))))) * ::GetFloatAtOffset68((const char *)(((::ImpactResponse::Base *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))));
            ::FUN_0062b8d0(node7, (const void *)&(linear_), 1);
            Vector kAngular = (*reinterpret_cast<::ImpactResponse::Vector *>((void *)&::NiPoint3::ZERO));
            Matrix rotation;
            reinterpret_cast<::ThreeByThreeMatrix *>((((::ImpactResponse::Matrix *)(::FUN_00461130((intptr_t)(GetNode()))))))->Inverse((::ThreeByThreeMatrix &)(rotation));
            Vector local = rotation.FUN_004b4500(contact->normal);
            if (::FUN_00408820(local.y) > ::FUN_00408820(local.z))
                local.z = ::FUN_00408820(local.y) * ((double)(::SignOfFloat(local.z)));
            local.y = 0.0f;
            ::FUN_00525340((float *)&(local));
            Vector spin2;
            reinterpret_cast<::FUN_00416870_t *>(&(spin2))->FUN_00416870(-local.z, 0.0f, -local.x);
            kAngular = ((::ImpactResponse::Matrix *)(::FUN_00461130((intptr_t)(node7))))->FUN_004b4500(spin2);
            reinterpret_cast<::MyPoint439180 *>(&(kAngular))->FUN_00439180(*((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ImpactResponse::Setting *>(&::originalRuntimeFloatSetting650)))))));
            ::FUN_0062ba80(node7, (const ::NiPoint3 &)(kAngular), 1);
        }
    }
    return true;
}
}

namespace fnv_009ba660 {
struct MissileActor;
struct MissileNode;
struct MissileBody;
struct MissileVector
{
    float x, y, z;
    MissileVector ApplyScaled(float) const;
};
struct MissileTransform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    MissileVector translation;
    float scale;
    MissileTransform();
    MissileTransform FUN_0062c250(const MissileTransform&) const;
};
struct MissileUpdate
{
    float time;
    int flags;
    int frame;
    MissileUpdate(float, bool, bool);
};
struct MissileHandle
{
    unsigned value;
};
struct MissileBody
{
    MissileHandle FUN_0043b4f0();
    void FUN_00626cb0(unsigned);
};
struct MissileCollision
{
};
struct MissileSetting
{
};
struct MissilePause
{
};
struct MissileVats
{
};
struct MissileQueue
{
    void FUN_005ae3d0(MissileActor* const&);
};
struct MissileManager
{
};
struct MissileReference
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual bool IsActor();
};
struct MissileHit
{
    MissileReference* reference;
    MissileVector position;
    int unk10, unk14, unk18;
    MissileNode* node;
};
struct MissileHitHandle
{
    unsigned value;
    bool FUN_008256d0();
};
const float DAT_01017b78 = 10.0f;
struct MissileNode
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual MissileNode* Find(int);
};
struct MissileActor
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10C();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11C();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12C();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13C();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14C();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15C();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16C();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17C();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18C();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19C();
    virtual void Slot1A0();
    virtual void Slot1A4();
    virtual void Slot1A8();
    virtual void Slot1AC();
    virtual void Slot1B0();
    virtual void Slot1B4();
    virtual void Slot1B8();
    virtual void Slot1BC();
    virtual void Slot1C0();
    virtual void Slot1C4();
    virtual void Slot1C8();
    virtual void Slot1CC();
    virtual MissileNode* Get3D();
    virtual void Slot1D4();
    virtual void Slot1D8();
    virtual void Slot1DC();
    virtual void Slot1E0();
    virtual void Slot1E4();
    virtual void Slot1E8();
    virtual void Slot1EC();
    virtual void Slot1F0();
    virtual void Slot1F4();
    virtual void Slot1F8();
    virtual void Slot1FC();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20C();
    virtual void Slot210();
    virtual void Slot214();
    virtual void Slot218();
    virtual void Slot21C();
    virtual void Slot220();
    virtual void Slot224();
    virtual void Slot228();
    virtual void Slot22C();
    virtual void Slot230();
    virtual void Slot234();
    virtual void Slot238();
    virtual void Slot23C();
    virtual void Slot240();
    virtual void Slot244();
    virtual void Slot248();
    virtual void Slot24C();
    virtual void Slot250();
    virtual void Slot254();
    virtual void Slot258();
    virtual void Slot25C();
    virtual void Slot260();
    virtual void Slot264();
    virtual void Slot268();
    virtual void Slot26C();
    virtual void Slot270();
    virtual void Slot274();
    virtual void Slot278();
    virtual void Slot27C();
    virtual void Slot280();
    virtual void Slot284();
    virtual void Slot288();
    virtual void Slot28C();
    virtual void Slot290();
    virtual void Slot294();
    virtual void Slot298();
    virtual void Slot29C();
    virtual void Slot2A0();
    virtual void Detach();
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
    MissileHitHandle hitHandle;
    int unk8C, unk90;
    MissileTransform impactTransform;
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
    float distance;
    void HandleMissileImpact();
};
// @fnv 0x009ba660
void MissileActor::HandleMissileImpact()
{
    static float impactScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009ba660::MissileSetting *>(&::originalRuntimeFloatSetting398))))));
    bool paused = reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_009ba660::MissilePause * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10();
    if (Get3D() && !hitHandle.FUN_008256d0())
    {
        if (((::fnv_009ba660::MissileActor *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((MissileVats*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->FUN_007af430())) == this)
            reinterpret_cast<::S_009c8c40 *>((((MissileVats*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->SetValue(0);
        distance = DAT_01017b78;
        MissileHit* hit31 = *((::fnv_009ba660::MissileHit **)(((::Vec3 *)(void *)&(hitHandle))));
        if (!hit31 || !hit31->node)
            return;
        MissileNode* node3 = Get3D();
        MissileNode* parent41 = ((::fnv_009ba660::MissileNode *)(::FUN_004b5820((::FormLike *)(void *)(((void *)(::FUN_00460140((intptr_t)(hit31->node))))))));
        MissileBody* body20 = ((::fnv_009ba660::MissileBody *)(::FUN_004b5a80(hit31->node)));
        unsigned layer1 = body20 ? ((unsigned int)(reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::fnv_009ba660::MissileHandle &)(body20->FUN_0043b4f0()))->FUN_0043b4d0())) : 0;
        if (body20 && layer1 != 19 && (!hit31->reference || !hit31->reference->IsActor()))
        {
            reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(4, true);
            Detach();
            MissileCollision* collision9 = ((::fnv_009ba660::MissileCollision *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(node3))));
            MissileBody* ownBody53 = collision9 ? ((::fnv_009ba660::MissileBody *)(::fnv_006fa820::FUN_006fa820((const char *)(collision9)))) : 0;
            if (ownBody53)
            {
                MissileHandle handle = ownBody53->FUN_0043b4f0();
                reinterpret_cast<::FUN_004a39f0_shell *>(&(handle))->FUN_004a39f0(15);
                ownBody53->FUN_00626cb0(handle.value);
            }
            if (!paused)
                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)&(const ::fnv_009ba660::MissileVector &)((*(::fnv_009ba660::MissileVector *)(reinterpret_cast<::Point3Offset *>((void *)&(hit31->position))->ProjectileLaunched({}, {})))));
            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
            ::FUN_00c69f50((::S_00c69f50_Obj *)(node3), 1, 1);
            MissileUpdate update53(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((node3))->FUN_00a59c60((std::intptr_t)(&update53));
            if (reinterpret_cast<::bhkRigidBody_shell *>((body20))->FUN_00517630() == 5)
                ::FUN_00c6a350((::NiAVObject *)(node3), 5, 1, 0, 1);
            else
            {
                ::FUN_00c6a350((::NiAVObject *)(node3), 4, 1, 0, 1);
                if (!reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(128))
                {
                    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(128, true);
                    MissileQueue* queue = ((::fnv_009ba660::MissileQueue *)(reinterpret_cast<::FUN_004610f0_Class *>(&((*reinterpret_cast<::fnv_009ba660::MissileManager *>(&::g_011e0e80))))->GetOffset70Ptr()));
                    if (queue)
                        queue->FUN_005ae3d0(this);
                }
                reinterpret_cast<::FUN_00628f30_shell *>((body20))->SetFlag(256, true);
                if (!paused && parent41)
                {
                    MissileTransform inverse;
                    reinterpret_cast<::NiTransform *>((((::fnv_009ba660::MissileTransform *)(::FUN_00461130((intptr_t)(parent41))))))->CalculateInverse((::NiTransform &)(inverse));
                    impactTransform = inverse.FUN_0062c250(*((::fnv_009ba660::MissileTransform *)(::FUN_00461130((intptr_t)(node3)))));
                }
            }
            MissileNode* child2 = node3 ? node3->Find(::FUN_009b7cb0()) : 0;
            if (child2)
                ::FUN_00c6a350((::NiAVObject *)(child2), 1, 1, 1, 1);
        }
        else
            reinterpret_cast<::ImpactResponse::Impact *>(this)->HandleContactResponse();
    }
}
}  // namespace fnv_009ba660

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
extern "C" void __cdecl _delete(void*, unsigned int);



struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }

    ~TlsGuard_t()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

void* __cdecl FUN_00aa13e0(unsigned int size);

class OwnerBase_t
{
  public:
    OwnerBase_t();
    virtual void unkB0();
    virtual ~OwnerBase_t();
    unsigned int m_04;
    unsigned int m_08;

};

class ChainA_t : public OwnerBase_t
{
  public:
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_t()
    {
        m_0c = 0;
        ::DAT_01268188 += 1;
    }
};

class SpawnedObject_t : public ChainA_t
{
  public:
    virtual void unkD2();
    SpawnedObject_t()
    {
        ::DAT_01268434 += 1;
    }
};

struct FUN_00cbdd60_cls
{
    int unk00;
    int unk04;
    SpawnedObject_t* FUN_00cbdd60(uintptr_t arg);
};

// @fnv 0x00cbdd60
SpawnedObject_t* FUN_00cbdd60_cls::FUN_00cbdd60(uintptr_t arg)
{
    TlsGuard_t guard;
    SpawnedObject_t* result = 0;
    FUN_00c876f0();
    result = new SpawnedObject_t();
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(result, (::Process89730 *)(arg));
    FUN_00c87700();
    return result;
}

struct S_cbde40_Guard
{
    int saved;
    S_cbde40_Guard()
    {
        saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }
    ~S_cbde40_Guard()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};
struct S_cbde40_Pool
{
};
extern int DAT_0108ff98;
struct S_cbde40_Base
{
    int unk00;
};
struct S_cbde40_Obj
{
    int* unk00;
    S_cbde40_Base base;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_cbde40
{
    int unk00;
    int unk04;
    int unk08;
    S_cbde40_Base* unk0c;
    S_cbde40_Base* FUN_00cbde40(bool* created);
};
// @fnv 0x00cbde40
S_cbde40_Base* S_cbde40::FUN_00cbde40(bool* created)
{
    S_cbde40_Guard guard;
    bool b = (unk0c == 0);
    *created = b;
    if (b)
    {
        S_cbde40_Obj* c = new S_cbde40_Obj;
        S_cbde40_Base* r;
        if (c)
        {
            S_cbde40_Base* bp = &c->base;
            c->unk08 = 1;
            c->unk0c = 0;
            c->unk10 = 0;
            c->unk00 = &DAT_0108ff98;
            bp->unk00 = 0;
            r = bp;
        }
        else
        {
            r = 0;
        }
        unk0c = r;
        if (unk08)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((uintptr_t)(unk0c ? (S_cbde40_Obj*)((char*)unk0c - 4) : 0));
    }
    return unk0c;
}

class NiAVObject;
class NiCollisionObject;

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    unsigned int uiValue;
    int unk10;
    int unk14;
    int unk18;
};

typedef void (*CollisionObjectCountCallback)(NiCollisionObject*, CollisionObjectCountContext*);
extern CollisionObjectCountCallback DAT_011afec0;

struct C6A0B0Properties
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;
};
static inline unsigned int C6A0B0IsEnabled(NiAVObject* pkObject)
{
    C6A0B0Properties* pkProps = ((::C6A0B0Properties *)(::GetExtraDataChecked((::NiAVObjectX *)(pkObject))));
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

// @fnv 0x00c6a0b0
bool FUN_00c6a0b0(NiAVObject* pkObject, bool bValue, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A0B0IsEnabled(pkObject)))
    {
        CollisionObjectCountContext kContext;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 0xe;
        kContext.uiValue = bValue;
        if (DAT_011afec0)
            ::FUN_00c68900((::S_00c68900_Node *)(pkObject), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(&kContext), (void (*)(void *, S_00c68900_Context *))(DAT_011afec0));
    }
    return bResult;
}



namespace fnv_009b90b0 {
// @fnv 0x009b90b0
void Actor::FUN_009b90b0()
{
    static float s_offset = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::originalRuntimeFloatSetting399))))));
    bool noMove = reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_009b90b0::Glob * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10();
    if (!unk88.FUN_008256d0())
    {
        Obj* p24 = vf1d0();
        Obj* p28 = p24->vfc();
        Owner* owner = (Owner*)*((::fnv_009b90b0::Obj **)(((::Vec3 *)(void *)&(unk88))));
        unk158 = 10.0f;
        if (unk150 == 4)
        {
            owner = (Owner*)(((::fnv_009b90b0::Obj *)(reinterpret_cast<::Callees *>(&(unk88))->FUN_00726070())) ? *((::fnv_009b90b0::Obj **)(((::Vec3 *)(void *)(((::fnv_009b90b0::Obj *)(reinterpret_cast<::Callees *>(&(unk88))->FUN_00726070())))))) : 0);
        }
        if (owner && owner->unk00 && owner->unk00->vf100())
        {
            if (owner->unk28)
                return;
            Obj* p34 = owner->unk00;
            if (reinterpret_cast<::TESObjectREFR *>((p34))->IsLimbMissing(owner->unk24))
            {
                Holder* p38 = (Holder*)((::fnv_009b90b0::Obj *)(reinterpret_cast<::ExtraDataList *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_005d43c0_ *>((p34))->FUN_005d43c0()))))->GetDismemberedLimbs()));
                bool found = false;
                for (unsigned int i = 0; i < SimpleArraySize(&(p38->unk20)); i++)
                {
                    if ((*p38->unk20.FUN_00877a30(i))->unk00 == (char)owner->unk24 &&
                        (*p38->unk20.FUN_00877a30(i))->unk01)
                        found = true;
                }
                Obj* p48 = owner->unk00 ? owner->unk00->vf1d0() : 0;
                if (p48 && !found)
                {
                    int p4c = (*reinterpret_cast<int (*)[]>((void *)&::DAT_01196d6c))[owner->unk24];
                    Obj* p60 = p48 ? p48->vf9c(Str(p4c)) : 0;
                    float f64 = reinterpret_cast<::FUN_008d01e0_Class *>((p60))->FUN_008d01e0();
                    if (p60 == 0)
                    {
                        unk90 = 0;
                        return;
                    }
                    {
                        Ctrl ctrl(1.0f);
                        reinterpret_cast<::FUN_004ad240_c *>(&(ctrl))->SetScale(1.0f);
                        Obj* p84 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::A5D2C0Object *>((p60))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&ctrl)))));
                        p34->RemoveLimb(owner->unk24);
                        p60 = p84;
                        reinterpret_cast<::TaskQueueInterface *>((p60))->QueueActorDisarm(0);
                        reinterpret_cast<::FUN_00440490_shell *>((p60))->FUN_00440490(f64);
                        Obj* p88 = p60->vfc();
                        if (p88)
                        {
                            for (unsigned int j = 0; j < p88->FUN_0043b480(); j++)
                            {
                                Obj* p90 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(j)));
                                if (p90 && ::FUN_004910d0((::NiAVObject *)(p90)))
                                    ::FUN_004ade40((::NiNode *)(p88), (::NiAVObject *)(p90), (::NiAVObject *)(p88), 0);
                            }
                        }
                        Vec3 v9c;
                        new ((void *)&(v9c)) ::NiUpdateData(0.0f, 0, 0);
                        reinterpret_cast<::FUN_00a59c60_cls *>((p60))->FUN_00a59c60((std::intptr_t)(&v9c));
                        Obj* pa0 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                        if (pa0)
                            pa0->vfd0(p60, 1, 0, 0, 1);
                        reinterpret_cast<::FUN_00440460_S *>((p60))->FUN_00440460((const ::V3 *)(void *)(&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO))));
                        reinterpret_cast<::FUN_0043fa80_s *>((p60))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<int *>(&::DAT_011a9448)))));
                        if (p88 && ((int)(reinterpret_cast<::S_FUN_0045bc00 *>((p88))->FUN_0045bc00(0))))
                        {
                            Xform xd4 = *((::fnv_009b90b0::Xform *)(::FUN_00461130((intptr_t)(((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))));
                            if (!noMove)
                                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::fnv_009b90b0::V *)(&owner->unk04));
                            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
                            Vec3 ve0;
                            new ((void *)&(ve0)) ::NiUpdateData(0.0f, 0, 0);
                            p28->vfb8((V*)&ve0);
                            Xform x114 = *((::fnv_009b90b0::Xform *)(::FUN_00461130((intptr_t)(p28))));
                            Xform x148;
                            reinterpret_cast<::_dummy_476a80 *>(&(x148))->FUN_00476a80();
                            reinterpret_cast<::FUN_008b42e0_shell *>(&(x114))->InvertTransform((::NiTransform *)(::fnv_009b90b0::Xform *)(&x148));
                            Xform x17c;
                            xd4 = *x148.FUN_0062c250(&x17c, &xd4);
                            xd4.pos.y -= s_offset;
                            reinterpret_cast<::FUN_00440460_S *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))->FUN_00440460((const ::V3 *)(void *)(&xd4.pos));
                            reinterpret_cast<::FUN_0043fa80_s *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&xd4)));
                            reinterpret_cast<::FUN_00440490_shell *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))->FUN_00440490(xd4.scale);
                        }
                        p28->vfdc(p60, 1);
                        ::AssignFixedString((char *)(p60), ::FUN_009b7cb0(), {});
                        ::FUN_00c69f50((::S_00c69f50_Obj *)(p60), 1, 1);
                        ::FUN_00c6a350((::NiAVObject *)(p60), 4, 1, 1, 1);
                        Vec3 v188;
                        new ((void *)&(v188)) ::NiUpdateData(0.0f, 0, 0);
                        reinterpret_cast<::FUN_00a59c60_cls *>((p28))->FUN_00a59c60((std::intptr_t)(&v188));
                        bool blocked = false;
                        if (p60)
                        {
                            intptr_t p190 = 0;
                            Obj* p194 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                            Big big;
                            new ((void *)&(big)) ::FUN_004a3c20();
                            V v25c;
                            V v268;
                            v25c = *vf1f4();
                            V9 m28c;
                            reinterpret_cast<::FUN_004a0c90_shell *>(&(m28c))->FUN_004a0c90(vf2bc(0));
                            V9 m2b0;
                            reinterpret_cast<::FUN_00524ac0_shell *>(&(m2b0))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
                            V9 m2d4;
                            m28c = *m28c.FUN_0043f8d0(&m2d4, &m2b0);
                            reinterpret_cast<::FUN_00439f50_class *>(&(m28c))->FUN_00439f50(1, (::NiPoint3 *)(::fnv_009b90b0::V *)(&v268));
                            reinterpret_cast<::FUN_004a0c10_s *>(&(v268))->FUN_004a0c10();
                            V t2e0;
                            V t2ec;
                            reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(big))->FUN_004a3da0((void *)(((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_00439ef0_class *>(&(v25c))->FUN_00439ef0((::NiPoint3 *)(::fnv_009b90b0::V *)(&t2ec), (*(const ::NiPoint3 *)(((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_0045bb20_cls *>(&(v268))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&t2e0), 512.0f))))))))));
                            V t2f8;
                            reinterpret_cast<::Class_007f68a0 *>(&(big))->FUN_007f68a0((*(const ::NiPoint3 *)(((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_0045bb20_cls *>(&(v268))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&t2f8), 1024.0f))))));
                            {
                                Res res;
                                reinterpret_cast<::FUN_004a3fb0_shell *>(&(big))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::fnv_009b90b0::Res *)(&res));
                                bool ok = ::FUN_009c5ba0((::World9C *)(::fnv_009b90b0::Big *)(&big), (::NiAVObject9C *)(p60), 0, 1);
                                if (ok && ((int)(reinterpret_cast<::Callees *>((((::fnv_009b90b0::List *)(::FUN_00460140((intptr_t)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big))->FUN_008cdd90()))))))))->FUN_00726070())) > 0)
                                    p190 = ((int)(::FUN_004b5820((::FormLike *)(((::fnv_009b90b0::Rec *)(reinterpret_cast<::FUN_004a46b0_class *>((((::fnv_009b90b0::List *)(::FUN_00460140((intptr_t)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big))->FUN_008cdd90()))))))))->GetEntryAt(0)))->unk50))));
                            }
                            if (p190)
                            {
                                Obj* p628 = ((::fnv_009b90b0::Obj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::fnv_009b90b0::Obj *)(vf1d0()))));
                                Obj* p630 = p628 ? ((::fnv_009b90b0::Obj *)(::fnv_006fa820::FUN_006fa820((const char *)(p628)))) : 0;
                                Obj* p634 = ((::fnv_009b90b0::Obj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::fnv_009b90b0::Obj *)((Obj*)p190))));
                                Obj* p63c = p634 ? ((::fnv_009b90b0::Obj *)(::fnv_006fa820::FUN_006fa820((const char *)(p634)))) : 0;
                                if (p63c && p63c != p630)
                                {
                                    Path path;
                                    reinterpret_cast<::fnv_00cbdcb0::CBDCB0Owner *>(&(path))->EnsureChild();
                                    reinterpret_cast<::FUN_009ba320_shell *>(&(path))->FUN_009ba320((uintptr_t)(p63c), (uintptr_t)(p630));
                                    Name n690(::FUN_004b4f00((::TESDataHandler *)(((::fnv_009b90b0::Obj *)(::FUN_004ae750((void *)(p63c)))))));
                                    Name n6d0(::FUN_004b4f00((::TESDataHandler *)(((::fnv_009b90b0::Obj *)(::FUN_004ae750((void *)(p630)))))));
                                    reinterpret_cast<::CB2FC0Object *>((((::fnv_009b90b0::Obj *)(((::Vec3 *)(void *)&(n690))))))->FUN_00cb2fc0();
                                    reinterpret_cast<::CB2FC0Object *>((((::fnv_009b90b0::Obj *)(((::Vec3 *)(void *)&(n6d0))))))->FUN_00cb2fc0();
                                    V v6dc;
                                    reinterpret_cast<::FUN_00439f50_class *>(&(((::fnv_009b90b0::Xform *)(::FUN_00461130((intptr_t)(vf1d0()))))->rot))->FUN_00439f50(1, (::NiPoint3 *)(::fnv_009b90b0::V *)(&v6dc));
                                    V5 v6f0;
                                    ::CopyCharacterControllerVector((::bhkCharacterController *)(::fnv_009b90b0::V5 *)(&v6f0), (*(const ::NiPoint3 *)(&v6dc)));
                                    reinterpret_cast<::S0062aea0_Vector *>(&(v6f0))->FUN_0062aea0();
                                    Xform x724 = *((::fnv_009b90b0::Xform *)(::FUN_00461130((intptr_t)(vf1d0()))));
                                    V v730;
                                    V v73c;
                                    V v748;
                                    reinterpret_cast<::FUN_0045bb20_cls *>((((::fnv_009b90b0::V *)(reinterpret_cast<::P3 *>(&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::DAT_011a9478))))->FUN_004a0bd0((::P3 *)(::fnv_009b90b0::V *)(&v73c))))))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&v730), s_offset);
                                    x724.FUN_00524c40(&v748, &v730);
                                    V6 v760;
                                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&v760)), (*(const ::fnv_004a3e00::NiPoint3 *)(&v748)));
                                    reinterpret_cast<::FUN_009ba3d0_shell *>(&(path))->FUN_009ba3d0((intptr_t)(&n690), (intptr_t)(&n6d0), (intptr_t)(&v760.q), (intptr_t)(&v6f0));
                                    PathRef* ref = new PathRef(&path);
                                    reinterpret_cast<::SceneC8E *>((p63c))->FUN_00c8ef80((::NiObjectC8E *)(ref));
                                    reinterpret_cast<::C8DAC0Owner *>((p63c))->UpdateMatchingNodes(((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())));
                                    Obj* p774 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                                    Big big2;
                                    new ((void *)&(big2)) ::FUN_004a3c20();
                                    V v83c;
                                    V v848;
                                    v83c = *vf1f4();
                                    V9 m86c;
                                    reinterpret_cast<::FUN_004a0c90_shell *>(&(m86c))->FUN_004a0c90(vf2bc(0));
                                    V9 m890;
                                    reinterpret_cast<::FUN_00524ac0_shell *>(&(m890))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
                                    V9 m8b4;
                                    m86c = *m86c.FUN_0043f8d0(&m8b4, &m890);
                                    reinterpret_cast<::FUN_00439f50_class *>(&(m86c))->FUN_00439f50(1, (::NiPoint3 *)(::fnv_009b90b0::V *)(&v848));
                                    reinterpret_cast<::FUN_004a0c10_s *>(&(v848))->FUN_004a0c10();
                                    Handle h;
                                    new ((void *)&(h)) ::GlobalObject_008c71b0(0);
                                    int t8bc;
                                    if (((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
                                    {
                                        h.val = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&t8bc)->val;
                                    }
                                    else
                                    {
                                        reinterpret_cast<::FUN_004a39f0_shell *>(&(h))->FUN_004a39f0(6);
                                        Obj* p8c0;
                                        int t8c4;
                                        if (((::fnv_009b90b0::Obj *)(::FUN_00874480((char *)this))) && (p8c0 = ((::fnv_009b90b0::Obj *)(::FUN_00874480((char *)this))), p8c0->vf100()))
                                            reinterpret_cast<::FUN_0059ce80_shell *>(&(h))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::fnv_009b90b0::Obj *)(::FUN_00874480((char *)this)))->FUN_00931ed0(&t8c4)))->FUN_004a3a20())));
                                        else
                                            reinterpret_cast<::FUN_0059ce80_shell *>(&(h))->FUN_0059ce80(((int)(::FUN_005dbe10())));
                                    }
                                    V v8e0;
                                    reinterpret_cast<::FUN_0045bb20_cls *>(&(v848))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&v8e0), (float)(reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter() - reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070()));
                                    big2.FUN_004a3f70(h.val);
                                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(big2))->FUN_004a3da0((void *)(&v83c));
                                    reinterpret_cast<::Class_007f68a0 *>(&(big2))->FUN_007f68a0((*(const ::NiPoint3 *)(&v8e0)));
                                    Res res2;
                                    reinterpret_cast<::FUN_004a3fb0_shell *>(&(big2))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::fnv_009b90b0::Res *)(&res2));
                                    Obj* pc04 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                                    pc04->vfc8(&big2);
                                    if (0)
                                    {
                                        Color c;
                                        new ((void *)&(c)) ::ImageSpaceEffectParam(1.0f, 0.5f, 0.5f, 1.0f);
                                        V tc20;
                                        intptr_t c24 = ((intptr_t)(::fnv_004b3890::FUN_004b3890((*(const class ::FUN_006815c0 *)(&v83c)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), (*(const class ::FUN_006815c0 *)(((::fnv_009b90b0::V *)(reinterpret_cast<::Point3Offset *>(&(v83c))->ProjectileLaunched((::NiPoint3 *)(::fnv_009b90b0::V *)(&tc20), (::NiPoint3 *)(::fnv_009b90b0::V *)(&v8e0)))))), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), 1)));
                                        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::fnv_009b90b0::Glob * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(c24), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::g_011f210c)))))));
                                    }
                                    for (int k = 0; !blocked && k < ((int)(reinterpret_cast<::Callees *>((((::fnv_009b90b0::List *)(::FUN_00460140((intptr_t)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big2))->FUN_008cdd90()))))))))->FUN_00726070()));
                                         k++)
                                    {
                                        Rec rec;
                                        reinterpret_cast<::S50 *>(&(rec))->FUN_00696c30((::S50 *)(::fnv_009b90b0::Rec *)(((::fnv_009b90b0::Rec *)(reinterpret_cast<::FUN_004a46b0_class *>((((::fnv_009b90b0::List *)(::FUN_00460140((intptr_t)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big2))->FUN_008cdd90()))))))))->GetEntryAt(k)))));
                                        intptr_t pc94 = ((int)(::FUN_004b5820((::FormLike *)(rec.unk50))));
                                        Obj* pc98 = ((::fnv_009b90b0::Obj *)(::FUN_004b5a80((const void *)(((intptr_t)(::FUN_004b59f0((const void *)(rec.unk50))))))));
                                        Obj* pc9c = ((::fnv_009b90b0::Obj *)(::FUN_0056f930((::NiAVObject *)(pc94))));
                                        int tca0;
                                        int type = pc98 ? reinterpret_cast<::FUN_0043b4d0_shell *>((pc98->FUN_0043b4f0(&tca0)))->FUN_0043b4d0() : 0;
                                        if (pc98 &&
                                            (type == 1 || type == 2 || type == 9 || type == 0x11 || type == 0xd ||
                                             type == 0x14) &&
                                            (reinterpret_cast<::bhkRigidBody_shell *>((pc98))->FUN_00517630() == 5 || reinterpret_cast<::bhkRigidBody_shell *>((pc98))->FUN_00517630() == 4))
                                        {
                                            blocked = true;
                                        }
                                        else if (pc98 && pc9c != (Obj*)this && pc9c && pc9c != owner->unk00)
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        owner->unk28 = 1;
                        if (blocked)
                        {
                            if (((intptr_t)(reinterpret_cast<::FUN_008d8b80Class *>(this)->FUN_008d8b80())))
                                reinterpret_cast<::FUN_008126e0_shell *>(this)->SetWhich(0);
                            ::FUN_00c69f50((::S_00c69f50_Obj *)(p60), 1, 1);
                            ::FUN_00c6a350((::NiAVObject *)(p60), 4, 1, 1, 1);
                            if (((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
                            {
                                int tcac;
                                ::FUN_00c6a3d0(p60, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&tcac)))->FUN_004a3a20())), 1, 1);
                                if (!noMove)
                                {
                                    reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::fnv_009b90b0::V *)(&owner->unk04));
                                    V5 vcc0;
                                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vcc0)), (*(const ::fnv_004a3e00::NiPoint3 *)(&owner->unk04)));
                                    ((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_00c6e390(&vcc0);
                                }
                                reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
                            }
                            if (!noMove)
                                unk90 = 0;
                        }
                        else
                        {
                            if (!noMove)
                                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::fnv_009b90b0::V *)(&owner->unk04));
                            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
                            reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(4, 1);
                            vf2a4();
                            ::FUN_00c69f50((::S_00c69f50_Obj *)(p60), 1, 1);
                            int tcc4;
                            ::FUN_00c6a3d0(p28, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((p34->FUN_00931ed0(&tcc4)))->FUN_004a3a20())), 1, 1);
                            ::FUN_00c6a350((::NiAVObject *)(p28), 1, 1, 1, 1);
                            ::FUN_00c6a0b0((::NiAVObject *)(p28), 1, 1, 0);
                            V vcd0;
                            {
                                V vcdc;
                                V vce8;
                                ((VRes*)((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_0045bb20_cls *>((((::fnv_009b90b0::V *)&(reinterpret_cast<::FUN_009b7010_shell *>(this)->FUN_009b7010((*(::NiPoint3 *)(&vce8)))))))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&vcdc), reinterpret_cast<::FUN_009669c0_Class *>(this)->FUN_009669c0()))))
                                    ->FUN_0053d280();
                            }
                            ::FUN_0062b8d0(p28, &vcd0, 1);
                            if (((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::g_011f2250))))->FUN_007af430())) == (Obj*)this)
                                reinterpret_cast<::S_009c8c40 *>(&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::g_011f2250))))->SetValue(0);
                        }
                    }
                    return;
                }
            }
            reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
            return;
        }
    }
    unk150 = 4;
    reinterpret_cast<::fnv_009ba660::MissileActor *>(this)->HandleMissileImpact();
}
}  // namespace fnv_009b90b0
#include "generated/data/fallout/ai/combat/missileprojectile.inc"
#include "generated/data/fallout/ai/combat/missileprojectile_o2_variant.inc"
