// fallout/ai/combat/continuousbeamprojectile.cpp: ContinuousBeamProjectile, ScScaler, AlignOwner (7 functions)

#include <cstdint>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_0047d370_shell.h"
#include "fnv/decl/FUN_004d7d50_StandIn.h"
#include "fnv/decl/FUN_004ee4b0_shell.h"
#include "fnv/decl/FUN_00534570_shell.h"
#include "fnv/decl/FUN_005bfbd0_Class.h"
#include "fnv/decl/FUN_00979840_cls.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/GeometryVertexBuffer.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/Projectile.h"
#include "fnv/decl/ProjectileHit.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/fnv_005de0a0__FUN_005de0a0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/decl/fnv_009bda10__ProjectileRuntime.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009c2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
class ContinuousBeamProjectile
{
  public:
    int Initialize();
};

// @fnv 0x009da760
int ContinuousBeamProjectile::Initialize()
{
    return 5;
}

struct Pt
{
};

struct NiPoint3 : Pt
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

struct XActor
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual NiPoint3* GetPos();

};

struct S9b46c0 : XActor
{
};

struct FUN_009795c0_shell : S9b46c0
{
    void FUN_009795c0(float);
};

struct List_009e03e0
{
    char pad[8];
};


struct FUN_009ab9c0_struct : FUN_009795c0_shell
{
    char pad0[0x88 - 4];
    List_009e03e0 list_88;
    bool field_90;

    bool FUN_009ab9c0(void* arg1, NiPoint3* arg2, void* arg3, void* arg4, void* arg5, void* arg6);
};

// @fnv 0x009ab9c0
bool FUN_009ab9c0_struct::FUN_009ab9c0(void* arg1, NiPoint3* arg2, void* arg3, void* arg4, void* arg5, void* arg6)
{
    if (::fnv_009c2c80::CanProjectileHit((::fnv_009c2c80::RefObj *)(arg1), (::fnv_009c2c80::CdBody *)(arg4), (intptr_t)(this), (::fnv_009c2c80::ProjData *)(void *)(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))) && !reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(0x20) &&
        reinterpret_cast<::ProjectileHit *>(this)->ProcessHit((::Obj *)(arg1), (*(const ::Vec *)(arg2)), (*(const ::Vec *)(arg3)), (::Buffer *)(arg4), (intptr_t)(arg5), (intptr_t)(arg6)))
    {
        if (field_90)
        {
            reinterpret_cast<::FileMatchList *>(&(list_88))->RemoveAll();
        }
        field_90 = 0;
        FUN_009795c0(reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::Pt &)((*arg2 - *GetPos())))->ComputeMagnitude());
        return true;
    }
    return false;
}

struct NiRTTI;
struct NiAVObject;


struct NiGeometryData
{
    enum Consistency
    {
        MUTABLE = 0
    };
    void SetDataConsistency(Consistency);
public:
    bool IsGeometryDataStreamable(bool);
};

struct NiGeometry
{
};

struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};

struct NiPoint3;
struct NiAVObject
{
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual NiNode* GetAsNiNode();
public:
    ::NiPoint3 &FUN_0043c490();
};

struct FUN_009abe40_struct
{
    void MarkGeometryDataMutable(NiAVObject* ap3D);
};

// Recursively walks a NiAVObject tree; for NiGeometry objects it marks their geometry data mutable, otherwise recurses into child nodes.
// @fnv 0x009abe40
void FUN_009abe40_struct::MarkGeometryDataMutable(NiAVObject* ap3D)
{
    if (ap3D)
    {
        if (::FUN_0043b300((const NiRTTI*)&(*reinterpret_cast<const char *const *>(&::g_011f4acc)), ap3D))
        {
            NiGeometry* pgeom = (NiGeometry*)ap3D;
            NiGeometryData* pdata = ((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(pgeom))));
            if (pdata)
            {
                pdata->SetDataConsistency((NiGeometryData::Consistency)0);
            }
        }
        else
        {
            NiNode* pnode = ap3D->GetAsNiNode();
            if (pnode)
            {
                for (unsigned int uiIndex = 0; uiIndex < pnode->GetNumChildren(); ++uiIndex)
                {
                    NiAVObject* pChild = pnode->GetAt(uiIndex);
                    MarkGeometryDataMutable(pChild);
                }
            }
        }
    }
}

struct S_009ab280_Target
{
};
struct S_009ab280_Sub
{
    int unk00;
};
struct S_009ab280_Proj;
struct S_009ab280_Owner
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_009ab280_Sub m150;
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
    S_009ab280_Proj* unk1a0;
};
struct S_009ab280_Proj
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_009ab280_Sub m150;
    int unk154;
    void InitContinuousBeam();
};

// Sets several flags via FUN_005de0a0, clears unk154, updates m150, and registers this as the owner's unk1a0 or logs an error and calls FUN_009bc8f0.
// @fnv 0x009ab280
void S_009ab280_Proj::InitContinuousBeam()
{
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x10, 0);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(1, 1);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(2, 0);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(8, 1);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x20, 0);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x100, 1);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x80, 1);
    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(0x2000, 1);
    unk154 = 0;
    reinterpret_cast<::fnv_009bda10::ProjectileRuntime *>(this)->FUN_009bda10();
    if (((::S_009ab280_Target *)(::FUN_00559450((int *)&(m150)))))
    {
        reinterpret_cast<::FUN_005bfbd0_Class *>((((::S_009ab280_Target *)(::FUN_00559450((int *)&(m150))))))->FUN_005bfbd0(reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter());
    }
    S_009ab280_Owner* owner = ((::S_009ab280_Owner *)(::FUN_00874480((char *)this)));
    if (owner)
    {
        if (owner->unk1a0)
        {
            reinterpret_cast<::Projectile *>((owner->unk1a0))->FUN_009bc8f0();
        }
        owner->unk1a0 = this;
    }
    else
    {
        ::FUN_005b5e40();
        reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
    }
}

struct ScPoint3
{
    float x, y, z;
};
struct ScPoint2
{
    float x, y;
};
struct ScRTTI
{
    int unk;
};

struct ScTransform
{
    char pad00[0xc];
    float m_fScale;
};
struct ScData
{
    virtual void v00();
};
struct ScGeomData
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
    virtual bool FUN_v8c();
};
struct ScAccess
{
    ScAccess();
    int pad[3];
};
struct ScGeom
{
};
struct ScChild
{
};
struct ScAVObject
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
    virtual void FUN_vd8(void* pkArg);
};

struct ScScaler
{
    void ScaleObject(ScAVObject* pkObject, float fScale);
};

// Scales pkObject's transform by fScale and scales its geometry vertices or child objects depending on the geometry type.
// @fnv 0x009aba90
void ScScaler::ScaleObject(ScAVObject* pkObject, float fScale)
{
    if (pkObject)
    {
        ((::ScTransform *)(::GetSourceFilesFromForm((char *)(pkObject))))->m_fScale *= fScale;
        reinterpret_cast<::MyPoint439180 *>((((::ScTransform *)(::GetSourceFilesFromForm((char *)(pkObject))))))->FUN_00439180(fScale);
        ScGeom* pkGeom = ((::ScGeom *)(::fnv_005495f0::FUN_005495f0((const char *)(pkObject))));
        if (pkGeom)
        {
            if (::FUN_0043b300((const ::NiRTTI *)(::ScRTTI *)(&(*reinterpret_cast<::ScRTTI *>(&::g_01202558))), (::NiAVObject *)(pkGeom)))
            {
                if (::FUN_0043b300((const ::NiRTTI *)(::ScRTTI *)(&(*reinterpret_cast<::ScRTTI *>(&::g_012024e0))), (::NiAVObject *)(pkObject)))
                {
                    ScAVObject* pkNode = pkObject;
                    for (unsigned int i = 0; i < reinterpret_cast<::FUN_004d7d50_StandIn *>((pkNode))->FUN_004d7d50(); i++)
                    {
                        ScAVObject* pkChild = ((::ScAVObject *)(reinterpret_cast<::Owner *>((pkNode))->GetByIndex(i)));
                        if (::FUN_0043b300((const ::NiRTTI *)(::ScRTTI *)(&(*reinterpret_cast<::ScRTTI *>(&::g_01202508))), (::NiAVObject *)(pkChild)))
                        {
                            ScChild* pkTarget = (ScChild*)pkChild;
                            reinterpret_cast<::FUN_004ee4b0_shell *>((pkTarget))->FUN_004ee4b0(reinterpret_cast<::TESGrass *>((pkTarget))->GetLowestAllowedSlope() * fScale);
                        }
                    }
                }
            }
            else if (((::ScGeomData *)(::fnv_004a8a90::FUN_004a8a90((char *)(pkGeom)))) && ((::ScGeomData *)(::fnv_004a8a90::FUN_004a8a90((char *)(pkGeom))))->FUN_v8c())
            {
                ScAccess kAccess;
                ScGeomData* pkData = ((::ScGeomData *)(::fnv_004a8a90::FUN_004a8a90((char *)(pkGeom))));
                if (reinterpret_cast<::NiGeometryData *>((pkGeom))->IsGeometryDataStreamable(1))
                {
                    reinterpret_cast<::S00a67410 *>((pkGeom))->FUN_00a67410((::BSFaceGenMorphData *)(::ScAccess *)(&kAccess));
                    for (int j = 0; j < reinterpret_cast<::FUN_0047d370_shell *>((((ScData*)pkData)))->FUN_0047d370(); j++)
                    {
                        ScPoint3 kPt = (*reinterpret_cast<::ScPoint3 *>((void *)&::NiPoint3::ZERO));
                        reinterpret_cast<::FUN_00534570_shell *>(&(kAccess))->FUN_00534570(j, (*(::NiPoint3 *)(&kPt)));
                        kPt.y *= fScale;
                        reinterpret_cast<::GeometryVertexBuffer *>(&(kAccess))->SetVertex(j, (*(const ::NiPoint3 *)(&kPt)));
                    }
                    reinterpret_cast<::FUN_00a673d0_shell *>((pkGeom))->FUN_00a673d0();
                }
            }
            else if (((::ScPoint3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkGeom))->FUN_007af430())))
            {
                for (int k = 0; k < reinterpret_cast<::TESActorBaseData *>((pkGeom))->GetFatigue(); k++)
                {
                    ((::ScPoint3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkGeom))->FUN_007af430()))[k].y *= fScale;
                    ((::ScPoint2 *)(reinterpret_cast<::BGSMessageInitAccess *>((pkGeom))->GetIconFormID()))[k].y *= fScale;
                }
                pkObject->FUN_vd8(((void *)(::FUN_0043c4b0())));
            }
        }
    }
}

class NiUpdateData
{
  public:
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bUpdateRelatives);
    float m_fTime;
    bool m_bUpdate;
    bool m_bUpdateRelatives;
    int m_iFlags;
};

class AlignMatrix
{
  public:
    float m_afEntry[9];
                               // Transpose
    AlignMatrix FUN_0043f8d0(const AlignMatrix& kOther) const;  // operator*
};

class AlignSceneObject
{
  public:
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_00A();
    virtual void Unk_00B();
    virtual void Unk_00C();
    virtual void Unk_00D();
    virtual void Unk_00E();
    virtual void Unk_00F();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_01A();
    virtual void Unk_01B();
    virtual void Unk_01C();
    virtual void Unk_01D();
    virtual void Unk_01E();
    virtual void Unk_01F();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_02A();
    virtual void Unk_02B();
    virtual void Unk_02C();
    virtual void Unk_02D();
    virtual void UpdateWorldData(NiUpdateData& kData);  // +0xb8
    AlignMatrix& FUN_00461130();                        // rotation
};

class AlignTargetSource
{
  public:
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_00A();
    virtual void Unk_00B();
    virtual void Unk_00C();
    virtual void Unk_00D();
    virtual void Unk_00E();
    virtual void Unk_00F();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_01A();
    virtual void Unk_01B();
    virtual void Unk_01C();
    virtual void Unk_01D();
    virtual void Unk_01E();
    virtual void Unk_01F();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_02A();
    virtual void Unk_02B();
    virtual void Unk_02C();
    virtual void Unk_02D();
    virtual void Unk_02E();
    virtual void Unk_02F();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_03A();
    virtual void Unk_03B();
    virtual void Unk_03C();
    virtual void Unk_03D();
    virtual void Unk_03E();
    virtual void Unk_03F();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_04A();
    virtual void Unk_04B();
    virtual void Unk_04C();
    virtual void Unk_04D();
    virtual void Unk_04E();
    virtual void Unk_04F();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_05A();
    virtual void Unk_05B();
    virtual void Unk_05C();
    virtual void Unk_05D();
    virtual void Unk_05E();
    virtual void Unk_05F();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_06A();
    virtual void Unk_06B();
    virtual void Unk_06C();
    virtual void Unk_06D();
    virtual void Unk_06E();
    virtual void Unk_06F();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual void Unk_074();
    virtual void Unk_075();
    virtual void Unk_076();
    virtual void Unk_077();
    virtual void Unk_078();
    virtual void Unk_079();
    virtual void Unk_07A();
    virtual void Unk_07B();
    virtual void Unk_07C();
    virtual void Unk_07D();
    virtual void Unk_07E();
    virtual void Unk_07F();
    virtual void Unk_080();
    virtual void Unk_081();
    virtual void Unk_082();
    virtual AlignSceneObject* GetTargetNode();  // +0x20c
};

class AlignOwner
{
  public:
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_00A();
    virtual void Unk_00B();
    virtual void Unk_00C();
    virtual void Unk_00D();
    virtual void Unk_00E();
    virtual void Unk_00F();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_01A();
    virtual void Unk_01B();
    virtual void Unk_01C();
    virtual void Unk_01D();
    virtual void Unk_01E();
    virtual void Unk_01F();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_02A();
    virtual void Unk_02B();
    virtual void Unk_02C();
    virtual void Unk_02D();
    virtual void Unk_02E();
    virtual void Unk_02F();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_03A();
    virtual void Unk_03B();
    virtual void Unk_03C();
    virtual void Unk_03D();
    virtual void Unk_03E();
    virtual void Unk_03F();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_04A();
    virtual void Unk_04B();
    virtual void Unk_04C();
    virtual void Unk_04D();
    virtual void Unk_04E();
    virtual void Unk_04F();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_05A();
    virtual void Unk_05B();
    virtual void Unk_05C();
    virtual void Unk_05D();
    virtual void Unk_05E();
    virtual void Unk_05F();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_06A();
    virtual void Unk_06B();
    virtual void Unk_06C();
    virtual void Unk_06D();
    virtual void Unk_06E();
    virtual void Unk_06F();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual AlignSceneObject* Get3D();  // +0x1d0
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
    AlignMatrix m_kRotate;  // +0x94

    void UpdateAlignment();
};

struct Point3_bd00
{
    float x, y, z;
    Point3_bd00& operator*=(float s);
};

struct Node_bd00;

struct AVObject_bd00
{
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual Node_bd00* GetAsNiNode();
};

struct Node_bd00 : AVObject_bd00
{
    unsigned int FUN_0043b480();
    AVObject_bd00* FUN_0043b4a0(unsigned int);
};

struct Rtti_bd00
{
};

struct BeamScaler_bd00
{
    void FUN_009abd00(AVObject_bd00* obj, float f1, float f2);
};
// Updates the 3D object's world data and recomputes m_kRotate from the target node's transform when a target node exists.
// @fnv 0x009ab160
void AlignOwner::UpdateAlignment()
{
    AlignSceneObject* pkObject2 = Get3D();
    if (pkObject2)
    {
        float fScale = reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter();
        if (fScale < 1.0)
            fScale = 1.0f;
        reinterpret_cast<::BeamScaler_bd00 *>(this)->FUN_009abd00((::AVObject_bd00 *)(pkObject2), fScale, 0.0f);
        AlignSceneObject* pkTarget2 = ((::AlignTargetSource *)(::FUN_00874480((char *)this))) ? ((::AlignTargetSource *)(::FUN_00874480((char *)this)))->GetTargetNode() : 0;
        if (pkTarget2)
        {
            NiUpdateData kData2(0.0f, false, false);
            pkObject2->UpdateWorldData(kData2);
            m_kRotate = Get3D()->FUN_00461130().FUN_0043f8d0((*(::AlignMatrix *)(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(pkTarget2->FUN_00461130()))->FUN_004b45b0({}))));
        }
    }
}

// If obj is non-null, scales its point when f2 > 0, then scales it or recursively processes its child nodes.
// @fnv 0x009abd00
void BeamScaler_bd00::FUN_009abd00(AVObject_bd00* apObject, float f1, float f2)
{
    if (apObject)
    {
        if (f2 > 0.0f)
        {
            float scale = f1 / f2;
            Point3_bd00 translate8 = (*(::Point3_bd00 *)&(reinterpret_cast<::NiAVObject *>((apObject))->FUN_0043c490()));
            reinterpret_cast<::MyPoint439180 *>((void *)&(const ::Point3_bd00 &)(translate8))->FUN_00439180(scale);
            reinterpret_cast<::FUN_00440460_S *>((apObject))->FUN_00440460((const ::V3 *)&(translate8));
        }

        if (::FUN_0043b300((const ::NiRTTI *)(const ::Rtti_bd00 *)(&(*reinterpret_cast<::Rtti_bd00 *>(&::g_011f4acc))), (::NiAVObject *)(apObject)))
        {
            AVObject_bd00* target2 = apObject;
            float val3 = (f2 > 0.0f) ? f2 : reinterpret_cast<::FUN_00979840_cls *>((this))->FUN_00979840((::ArgRef *)(target2));
            if (val3 != 0.0f)
            {
                float fRatio = f1 / val3;
                reinterpret_cast<::ScScaler *>((this))->ScaleObject((::ScAVObject *)(target2), fRatio);
            }
        }
        else
        {
            Node_bd00* pNode = apObject->GetAsNiNode();
            if (pNode)
            {
                for (unsigned int iIndex = 0; iIndex < pNode->FUN_0043b480(); ++iIndex)
                {
                    AVObject_bd00* pChild = pNode->FUN_0043b4a0(iIndex);
                    this->FUN_009abd00(pChild, f1, f2);
                }
            }
        }
    }
}
