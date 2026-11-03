
// src/staging/blk_00560000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00560000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00560000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <cstdint>
#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0041fbe0_shell.h"
#include "fnv/decl/FUN_004211a0_StandIn.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004b4cf0_shell.h"
#include "fnv/decl/FUN_005407b0_Class.h"
#include "fnv/decl/FUN_0056d2c0_cls.h"
#include "fnv/decl/FUN_0056e050_Class.h"
#include "fnv/decl/FUN_00577070_class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/S00ca4120_Geom.h"
#include "fnv/decl/S_00538f40.h"
#include "fnv/decl/S_00c85c10.h"
#include "fnv/decl/ShapeCa36a0.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056d000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_01268000.h"
#include "../../include/layout_support.h"

class LocalBlock20;
class FUN_00577110_slot;

class FUN_00577110_cls
{
  public:
    void FUN_00577110();
};

class __declspec(align(16)) LocalBlock20
{
  public:
    LocalBlock20();
    char buffer[0x10];
};

class FUN_00577110_slot
{
  public:
};

// @fnv 0x00577110
void FUN_00577110_cls::FUN_00577110()
{
    LocalBlock20 local;
    reinterpret_cast<::S_00538f40 *>(&(local))->FUN_00538f40();
    reinterpret_cast<::AlignedVector *>((((::FUN_00577110_slot *)(reinterpret_cast<::FUN_004b4cf0_shell *>(this)->FUN_004b4cf0(0)))))->FUN_004a3f10(*(const ::AlignedVector *)nullptr);
    reinterpret_cast<::AlignedVector *>((((::FUN_00577110_slot *)(reinterpret_cast<::FUN_004b4cf0_shell *>(this)->FUN_004b4cf0(1)))))->FUN_004a3f10(*(const ::AlignedVector *)nullptr);
    reinterpret_cast<::AlignedVector *>((((::FUN_00577110_slot *)(reinterpret_cast<::FUN_004b4cf0_shell *>(this)->FUN_004b4cf0(2)))))->FUN_004a3f10(*(const ::AlignedVector *)nullptr);
}

struct __declspec(align(16)) FUN_0056ded0
{
    unsigned char transformData[64];
    FUN_0056ded0();
};
struct NiTransform
{
    float rotation[9];
    float translation[3];
    float scale;
};
struct FUN_0056df20_Class
{
    void FUN_0056df20(const NiTransform& src);
};
// Built from prior 2026-10-25 contributions, with byte-addressable transform storage.
// @fnv 0x0056df20
void FUN_0056df20_Class::FUN_0056df20(const NiTransform& src)
{
    FUN_0056ded0 local;
    reinterpret_cast<::FUN_0056e050_Class *>(this)->FUN_0056e050((int)(&(*(::FUN_0056ded0 *)&(::FromHK((::hkTransform &)(local), src)))));
}

#include <xmmintrin.h>
class hkVector4_56D
{
  public:
    hkVector4_56D();
    hkVector4_56D& operator=(const hkVector4_56D& kOther);
    __m128 m_vComponents;
};

class Point56D
{
  public:
    Point56D();
    Point56D operator+(const Point56D& kPt) const;
    Point56D operator*(float fScalar) const;
    float x, y, z;
};

class Matrix56D
{
  public:
    bool operator==(const Matrix56D& kMat) const;
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class Transform56D
{
  public:
    Transform56D();
    Matrix56D m_kRotate;
    Point56D m_kTranslate;
    float m_fScale;
};

class Color56D
{
  public:
    Color56D(float fR, unsigned int uiG, unsigned int uiB);
    float r, g, b;
};

class MotionType56D
{
  public:
    unsigned int m_uiType;
};

class Shape56D
{
  public:
    void* m_pvVtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class BoxShape56D : public Shape56D
{
  public:
    BoxShape56D(const hkVector4_56D& m_kPoint2);
};

class SphereShape56D : public Shape56D
{
  public:
    SphereShape56D(float fRadius, int iFlags);
};

class MotionInfo56D
{
  public:
    MotionInfo56D();
    hkVector4_56D m_kA;
    hkVector4_56D m_kB;
    hkVector4_56D m_kC;
    hkVector4_56D m_kCubicCoefficient;
};

class BoxBodyCinfo56D
{
  public:
    BoxBodyCinfo56D();
    ~BoxBodyCinfo56D();
    unsigned int m_uiFilterInfo;
    int unk04;
    MotionType56D m_kMotion;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4_56D m_kMin;
    hkVector4_56D m_kMax;
};

class BodyCinfo56D
{
  public:
    BodyCinfo56D();
    ~BodyCinfo56D();
    unsigned int m_uiFilterInfo;
    void* m_pvShape;
    MotionType56D m_kMotion;
    int unk0c;
    hkVector4_56D m_kPathOffset;
    hkVector4_56D m_kRotationMatrix;
    hkVector4_56D m_kLinearVelocity;
    hkVector4_56D m_kAngularVelocity;
    hkVector4_56D m_kInertia;
};

class BoxBody56D
{
  public:
    BoxBody56D(BoxBodyCinfo56D& kInfo);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

class Body56D
{
  public:
    Body56D(BodyCinfo56D& kInfo);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

class Node56D;

class Collision56D
{
  public:
    Collision56D(Node56D* pkNode);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};

class Property56D
{
  public:
    Property56D();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

class Node56D
{
  public:
};

class Physics56D
{
  public:
};

class Holder56D
{
  public:
    void Add(void* pvObject);
};

class Loaded56D
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Holder56D m_kHolder;
};

class Bound56D
{
  public:
    Point56D GetExtents();
};

class Layer56D
{
  public:
};

class ExtraList56D
{
  public:
};

class World56D
{
  public:
};

class Middle56D
{
  public:
};


class Ref56D
{
  public:
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
    virtual Node56D* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Point56D* GetPos();
    Matrix56D GetRotation();
    void FUN_0056d7e0();
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
    Loaded56D* m_pkLoaded;
};

// @fnv 0x0056d7e0
void Ref56D::FUN_0056d7e0()
{
    Bound56D* pkBound = ((::Bound56D *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::ExtraList56D *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041fbe0()));
    World56D* pkWorld = ((::Middle56D *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) ? ((::World56D *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Middle56D *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) : 0;
    if (pkWorld)
    {
        Shape56D* pkShape = 0;
        MotionInfo56D kUnused;
        hkVector4_56D m_kPoint2;
        reinterpret_cast<::fnv_00567490::ScaleReference *>(this)->FUN_00567490(1.0f);
        reinterpret_cast<::FUN_00440490_shell *>((Get3D()))->FUN_00440490(1.0f);
        Color56D kColor(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((Get3D()))->FUN_00a59c60((std::intptr_t)&(kColor));
        Transform56D kXform;
        kXform.m_kRotate = GetRotation();
        kXform.m_kTranslate = *GetPos();
        kXform.m_fScale = 1.0f;
        Layer56D* pkLayer = ((::Layer56D *)(reinterpret_cast<::FUN_004211a0_StandIn *>((((::ExtraList56D *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_004211a0()));
        unsigned int uiLayer = pkLayer ? ((unsigned int)(::FUN_00559450((int *)(pkLayer)))) : 0x16;
        if (uiLayer != 0x17 && ((int)(reinterpret_cast<::Callees *>((pkBound))->FUN_00726070())) == 1 && reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(const ::Matrix56D &)(kXform.m_kRotate))->operator==((const ::ThreeByThreeMatrix &)((*reinterpret_cast<const ::Matrix56D *>(&::DAT_011a9448)))))
        {
            BoxBodyCinfo56D kInfo;
            hkVector4_56D kVec;
            Point56D kPt;
            kPt = pkBound->GetExtents() + kXform.m_kTranslate;
            ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kVec), (const ::fnv_004a3e00::NiPoint3 &)(kPt));
            reinterpret_cast<::AlignedVector *>((void *)&(const ::hkVector4_56D &)(kInfo.m_kMax))->FUN_004a3f10((const ::AlignedVector &)(kVec));
            kPt = pkBound->GetExtents() * -1.0f + kXform.m_kTranslate;
            ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kVec), (const ::fnv_004a3e00::NiPoint3 &)(kPt));
            reinterpret_cast<::AlignedVector *>((void *)&(const ::hkVector4_56D &)(kInfo.m_kMin))->FUN_004a3f10((const ::AlignedVector &)(kVec));
            reinterpret_cast<::FUN_005407b0_Class *>(&(kInfo.m_kMotion))->FUN_005407b0(2);
            unsigned int uiFilterInfo = 0x50000;
            uiFilterInfo |= uiLayer;
            kInfo.m_uiFilterInfo = uiFilterInfo;
            m_pkLoaded->m_kHolder.Add(new BoxBody56D(kInfo));
        }
        else
        {
            if (((int)(reinterpret_cast<::Callees *>((pkBound))->FUN_00726070())) == 1)
            {
                ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(m_kPoint2), (const ::fnv_004a3e00::NiPoint3 &)((const ::Point56D &)(pkBound->GetExtents())));
                pkShape = new BoxShape56D(m_kPoint2);
            }
            if (((int)(reinterpret_cast<::Callees *>((pkBound))->FUN_00726070())) == 2)
                pkShape = new SphereShape56D(FUN_004a3e90(pkBound->GetExtents().x), 0);
            BodyCinfo56D kInfo;
            kInfo.m_pvShape = ((void *)(reinterpret_cast<::FUN_00620b80_shell *>((pkShape))->GetReferenceFlags()));
            reinterpret_cast<::FUN_005407b0_Class *>(&(kInfo.m_kMotion))->FUN_005407b0(2);
            unsigned int uiFilterInfo = 0x50000;
            uiFilterInfo |= uiLayer;
            kInfo.m_uiFilterInfo = uiFilterInfo;
            Body56D* pkBody = new Body56D(kInfo);
            reinterpret_cast<::FUN_0056df20_Class *>((pkBody))->FUN_0056df20((const ::NiTransform &)(kXform));
            m_pkLoaded->m_kHolder.Add(pkBody);
        }
        Collision56D* pkCollision = new Collision56D(Get3D());
        Property56D* pkProperty = new Property56D();
        reinterpret_cast<::BSXFlags_shell *>((pkProperty))->FUN_00519230(2, 1);
        reinterpret_cast<::FUN_00a5bca0_shell *>((Get3D()))->SetExtraDataName((::NiExtraData *)(pkProperty));
        reinterpret_cast<::S_00c85c10 *>((((::Physics56D *)(::FUN_00559450((int *)&(m_pkLoaded->m_kHolder))))))->FUN_00c85c10((int *)(::Node56D *)(Get3D()), (int *)(0));
        reinterpret_cast<::FUN_0056d2c0_cls *>((pkWorld))->FUN_0056d2c0((::Arg56d2c0 *)(::Physics56D *)(((::Physics56D *)(::FUN_00559450((int *)&(m_pkLoaded->m_kHolder))))));
    }
}

struct UpdateData264
{
    float time;
    bool updateControllers, isMultiThreaded, flags6, flags7, flags8;
    UpdateData264(float, bool, bool);
};
struct Transform264
{
    float rotation[9];
    float translation[3];
    float scale;
};
struct HavokTransform264
{
    __m128 rotation[3];
    __m128 translation;
    HavokTransform264();
};
struct NativeA264
{
};
struct NativeB264
{
};
struct Shape264
{
};
struct ShapeA264 : Shape264
{
};
struct ShapeB264 : Shape264
{
};
struct WrappedShape264 : Shape264
{
};
struct World264
{
};
struct Collision264
{
};
struct Scene264;
struct SceneChildren264
{
    unsigned int FUN_0043b480();
};
struct Scene264
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual SceneChildren264* AsNode();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void Update(UpdateData264&);
    const Transform264& FUN_00461130();
};
struct Owner264
{
    void FUN_00576d50(Scene264*);
};
// @fnv 0x00576d50
void Owner264::FUN_00576d50(Scene264* scene)
{
    if (!scene)
        return;
    UpdateData264 update(0.0f, true, false);
    scene->Update(update);
    Transform264 transform = scene->FUN_00461130();
    HavokTransform264 converted;
    reinterpret_cast<::FUN_00577070_class *>(&(converted))->FUN_00577070();
    ::FromHK((*(::hkTransform *)(&converted)), (*(const ::NiTransform *)(&transform)));
    Collision264* collision = ((::Collision264 *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(scene))));
    World264* world = collision ? ((::World264 *)(::fnv_006fa820::FUN_006fa820((const char *)(collision)))) : 0;
    Shape264* shape = world ? ((::Shape264 *)(reinterpret_cast<::FUN_004ae6a0_shell *>((world))->FUN_004ae6a0())) : 0;
    if (shape)
    {
        NativeA264* nativeA = 0;
        NativeB264* nativeB = 0;
        if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012682e8))), (::NiAVObject *)(shape)))
        {
            ShapeA264* typed = (ShapeA264*)shape;
            nativeA = ((::NativeA264 *)(reinterpret_cast<::FUN_00620b80_shell *>((typed))->GetReferenceFlags()));
        }
        else if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012682dc))), (::NiAVObject *)(shape)))
        {
            ShapeB264* typed = (ShapeB264*)shape;
            nativeB = ((::NativeB264 *)(reinterpret_cast<::FUN_00620b80_shell *>((typed))->GetReferenceFlags()));
        }
        else if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012682d0))), (::NiAVObject *)(shape)))
        {
            WrappedShape264* typed = (WrappedShape264*)shape;
            Shape264* child = ((::Shape264 *)(::FUN_00577190((void *)(typed))));
            if (child && ::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012682e8))), (::NiAVObject *)(child)))
            {
                ShapeA264* typedA = (ShapeA264*)child;
                nativeA = ((::NativeA264 *)(reinterpret_cast<::FUN_00620b80_shell *>((typedA))->GetReferenceFlags()));
            }
            else if (child && ::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012682dc))), (::NiAVObject *)(child)))
            {
                ShapeB264* typedB = (ShapeB264*)child;
                nativeB = ((::NativeB264 *)(reinterpret_cast<::FUN_00620b80_shell *>((typedB))->GetReferenceFlags()));
            }
        }
        if (nativeA)
            reinterpret_cast<::S00ca4120_Geom *>((nativeA))->FUN_00ca4120((const ::S00ca4120_Xf *)&(converted));
        if (nativeB)
            reinterpret_cast<::ShapeCa36a0 *>((nativeB))->FUN_00ca36a0((const ::hkTransform &)(converted));
    }
    SceneChildren264* children = scene->AsNode();
    if (children)
    {
        unsigned int count = children->FUN_0043b480();
        for (unsigned int i = 0; i < count; ++i)
            FUN_00576d50(((::Scene264 *)(reinterpret_cast<::NiNode *>((children))->GetAt(i))));
    }
}
