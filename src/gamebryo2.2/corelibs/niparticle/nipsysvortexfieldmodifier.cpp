
// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c26810
#include <cstdint>
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00c32120_cls.h"
#include "fnv/decl/NiPSysParticle.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/S_00c322b0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c26000.h"
#include "fnv/symbols_01202000.h"
#include <cmath>
#include "fnv/decl/MyPoint439180.h"
void* __cdecl FUN_00c26810()
{
    return &(*reinterpret_cast<void * *>(&::g_01202688));
}

struct NiStream;
struct NiColor
{
    void LoadBinary(NiStream&);
};
struct NiPSysFieldModifier
{
};
struct NiPSysVortexFieldModifier : NiPSysFieldModifier
{
    NiColor m_kFogTint;
    void FUN_00c267d0(NiStream& stream);
};
// @fnv 0x00c267d0
void NiPSysVortexFieldModifier::FUN_00c267d0(NiStream& stream)
{
    reinterpret_cast<::FUN_00c32120_cls *>(this)->LoadFromStream((::StreamOwner *)&(stream));
    ((NiColor*)((char*)this + 0x30))->LoadBinary(stream);
}


struct FUN_00c26920_shell
{
    FUN_00c26920_shell* DestroyIfFlagged(int a);
};

// Calls FUN_00c31750, then deletes this with size 0x3c when bit 0 of a is set, and returns this.
// @fnv 0x00c26920
FUN_00c26920_shell* FUN_00c26920_shell::DestroyIfFlagged(int a)
{
    static_cast<::PositionState *>(nullptr)->FUN_00c31750();
    if (a & 1)
        ::FUN_00aa1460(this, 0x3c);
    return this;
}

struct NiMemObject
{
    char _pad_0[1];
};
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};

struct NiObject;
struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93060
{
};
struct CloningProcess;
struct NiPSysModifier
{
    virtual void ProcessClone(CloningProcess&);
};
struct NiPSysAirFieldModifier_00c2c110 : NiPSysModifier
{
    void FUN_00c2c110(CloningProcess&);
};
// Calls NiPSysModifier::ProcessClone, then remaps the object at offset 0x18 through the clone map, falling back to the original pointer.
// @fnv 0x00c2c110
void NiPSysAirFieldModifier_00c2c110::FUN_00c2c110(CloningProcess& aCloneProcess)
{
    NiPSysModifier::ProcessClone(aCloneProcess);
    ShaderBufferRecord* pMappedObject = 0;
    reinterpret_cast<::A54440Hash *>((((NiTStringPointerMap_00e93060*)aCloneProcess.m_pCloneMap)))->FUN_00a53c30((::A54440Manager *)((const char*)this), (::A54440Manager **)&(pMappedObject));
    ShaderBufferRecord* destination = pMappedObject;
    if (*(NiObject**)((char*)this + 0x18))
    {
        if (reinterpret_cast<::A54440Hash *>((((NiTStringPointerMap_00e93060*)aCloneProcess.m_pCloneMap)))->FUN_00a53c30((::A54440Manager *)((const char*)*(NiObject**)((char*)this + 0x18)), (::A54440Manager **)&(pMappedObject)))
        {
            *(NiObject**)((char*)destination + 0x18) = (NiObject*)pMappedObject;
            return;
        }
        *(NiObject**)((char*)destination + 0x18) = *(NiObject**)((char*)this + 0x18);
    }
}

struct StrArr
{
    char _pad_0[8];
    unsigned short m_usCapacity;  // +0x08
    unsigned short m_usSize;      // +0x0a
    char _pad_c[2];
    unsigned short m_usGrowBy;  // +0x0e
};

struct FUN_00438fc0_file;
struct NiPoint3
{
    char* FUN_00a59af0(char const*);
public:
    static const ::NiPoint3 ZERO;
public:
    unsigned char ReadFromFile(::FUN_00438fc0_file *);
    bool FUN_004390c0(const ::NiPoint3 &);
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
    float GetLengthSquared();
    float ComputeMagnitude() const;
    ::NiPoint3 Cross(const ::NiPoint3 &) const;
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
    ::NiPoint3 &FUN_00b2a1c0(const ::NiPoint3 &);
};



struct C27A30Base
{
};

struct FUN_00c27060_shell : C27A30Base
{
    void AppendNameAndDirection(StrArr* pkStrings);
};

// @fnv 0x00c27060
void FUN_00c27060_shell::AppendNameAndDirection(StrArr* pkStrings)
{
    reinterpret_cast<::S_00c322b0 *>(this)->FUN_00c322b0((::S_00c322b0_Arr *)(pkStrings));
    char* pcStr = ::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_01202688))));
    unsigned int uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usCapacity)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(pkStrings->m_usGrowBy + uiIdx);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIdx, pcStr);
    pcStr = ((NiPoint3*)((char*)this + 0x30))->FUN_00a59af0("Direction");
    uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usCapacity)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(pkStrings->m_usGrowBy + uiIdx);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIdx, pcStr);
}

struct CloneVec3
{
    int x;
    int y;
    int z;
};


struct CloneItemBase
{
    CloneItemBase();
    virtual void Vfn0();
    char _pad_4[0x2c];
};

struct CloneItem : CloneItemBase
{
    CloneItem() throw()
    {
        m_30 = (*reinterpret_cast<::CloneVec3 *>((void *)&::NiPoint3::ZERO));
    }
    virtual void Vfn0();
    CloneVec3 m_30;
};

struct CloneHost
{
    char _pad_0[0x30];
    CloneVec3 m_30;
    CloneItem* FUN_00c26940(intptr_t a);
};

// Allocates a CloneItem, passes it with a to FUN_00c32020, copies m_30 into the item's m_30, and returns it.
// @fnv 0x00c26940
CloneItem* CloneHost::FUN_00c26940(intptr_t a)
{
    CloneItem* pItem = new CloneItem;
    reinterpret_cast<::NiPSysParticle *>((this))->FUN_00c32020((::NiPSysParticle *)(pItem), (::CloningProcess *)(a));
    pItem->m_30 = m_30;
    return pItem;
}

struct Pt_c268
{
    float x;
    float y;
    float z;
    Pt_c268()
    {}
    Pt_c268(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    Pt_c268 operator-(const Pt_c268& o) const
    {
        return Pt_c268(x - o.x, y - o.y, z - o.z);
    }
    Pt_c268 operator*(float f) const
    {
        return Pt_c268(x * f, y * f, z * f);
    }
    float operator*(const Pt_c268& o) const
    {
        return x * o.x + y * o.y + z * o.z;
    }
    // The game helper forms the unit cross product with this vector as receiver.
    Pt_c268 FUN_0053d1a0(const Pt_c268& value) const;
    Pt_c268& operator-=(const Pt_c268& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
};

// @fnv 0x00c26820
Pt_c268 FUN_00c26820(const Pt_c268& origin, const Pt_c268& direction, const Pt_c268& point)
{
    Pt_c268 vDifference = point - origin;
    float dot = vDifference * direction;
    vDifference -= direction * dot;
    if (vDifference.x == (*reinterpret_cast<const ::Pt_c268 *>((void *)&::NiPoint3::ZERO)).x && vDifference.y == (*reinterpret_cast<const ::Pt_c268 *>((void *)&::NiPoint3::ZERO)).y && vDifference.z == (*reinterpret_cast<const ::Pt_c268 *>((void *)&::NiPoint3::ZERO)).z)
        return vDifference;
    return direction.FUN_0053d1a0(vDifference);
}

#include <math.h>
inline float NiSqrt(float fValue)
{
    return sqrtf(fValue);
}

struct Vec3
{
    float x;
    float y;
    float z;

    Vec3()
    {}
    Vec3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }

    Vec3 operator-(const Vec3& pt) const
    {
        Vec3 res;
        res.x = x - pt.x;
        res.y = y - pt.y;
        res.z = z - pt.z;
        return res;
    }

    float Length() const
    {
        return NiSqrt(x * x + y * y + z * z);
    }

    Vec3& operator*=(float fScalar)
    {
        x *= fScalar;
        y *= fScalar;
        z *= fScalar;
        return *this;
    }

    Vec3& operator+=(const Vec3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
};

struct Mat3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;

    Vec3 operator*(const Vec3& pt) const
    {
        return Vec3(m00 * pt.x + m01 * pt.y + m02 * pt.z, m10 * pt.x + m11 * pt.y + m12 * pt.z,
                    m20 * pt.x + m21 * pt.y + m22 * pt.z);
    }
};

class NiTransform
{
  public:
    Mat3 m_kOrientation;
    Vec3 m_kTranslation;
    float m_fScale;

    NiTransform operator*(const NiTransform& xform) const;
public:
    void CalculateInverse(::NiTransform &);
};

struct AVObj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    NiTransform m_kWorldSpaceTransform;
};

struct ParticleInfo
{
    Vec3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct PSysData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec3* m_pkVertex;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    ParticleInfo* m_pkParticleInfo;
    Vec3* GetVertices()
    {
        return m_pkVertex;
    }
    ParticleInfo* GetParticleInfo()
    {
        return m_pkParticleInfo;
    }
};

struct VortexModifier
{
    int unk00, unk04, unk08, unk0c;
    AVObj* m_pkTarget;
    int unk14;
    AVObj* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    int unk2c;
    Vec3 m_kLightVector;

    Vec3 FUN_00c26820(const Vec3& akStart, const Vec3& kDirection, const Vec3& kPoint);
    void FUN_00c269b0(float fTime, PSysData* pkData);
};

// For each active particle with nonzero time delta, adds a scaled vector to its velocity when distance is at most m_fDistanceLimit squared.
// @fnv 0x00c269b0
void VortexModifier::FUN_00c269b0(float fTime, PSysData* pkData)
{
    NiTransform kField = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInvPSys;
    {
        NiTransform kPSys = m_pkTarget->m_kWorldSpaceTransform;
        reinterpret_cast<::NiTransform *>((void *)&(kPSys))->CalculateInverse(kInvPSys);
    }
    {
        NiTransform kFieldToPSys = kInvPSys * kField;
        Vec3 kPosition = kFieldToPSys.m_kTranslation;
        Vec3 kDirection = kFieldToPSys.m_kOrientation * m_kLightVector;
        reinterpret_cast<::FUN_004a0c10_s *>(&(kDirection))->FUN_004a0c10();
        float fMaxDistanceSqr = m_fDistanceLimit * m_fDistanceLimit;
        for (unsigned short us = 0; us < pkData->m_usActiveVertices; us++)
        {
            ParticleInfo* pkCurrentParticle = &pkData->GetParticleInfo()[us];
            float fDeltaT = fTime - pkCurrentParticle->m_fZValue;
            if (fDeltaT != 0.0f)
            {
                Vec3* __restrict pkVertex = pkData->m_pkVertex;
                Vec3 kParticlePosition = pkVertex[us];
                float fDistance = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::Vec3 &)((kParticlePosition - kFieldToPSys.m_kTranslation)))->FUN_00589850();
                if (fDistance != 0.0f && fDistance <= fMaxDistanceSqr)
                {
                    Vec3 kDeltaV = FUN_00c26820(kPosition, kDirection, kParticlePosition);
                    kDeltaV *= m_fInfluence * fDeltaT;
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Vec3 &)(pkCurrentParticle->m_kValue))->FUN_0063c8a0((void *)&(kDeltaV));
                }
            }
        }
    }
}

namespace fnv_00c26c00 {
typedef Pt_c268 Vec3;
inline Vec3& operator+=(Vec3& a, Vec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
struct NormVec3
{
    float x;
    float y;
    float z;
};
class NiTransform
{
  public:
    float rotation[9];
    Vec3 translation;
    float scale;
};
struct TransformNode
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
    NiTransform transform;
};
struct Particle
{
    Vec3 velocity;
    float unk0c;
    float unk10;
    float age;
    float unk18;
};
struct ParticleList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec3* positions;
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
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle* particles;
    Vec3* GetPositions()
    {
        return positions;
    }
};

inline Vec3 RotMul(const float* m, const Vec3& v)
{
    return Vec3(m[0] * v.x + m[1] * v.y + m[2] * v.z, m[4] * v.y + m[3] * v.x + m[5] * v.z,
                m[6] * v.x + m[7] * v.y + m[8] * v.z);
}
struct ForceOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TransformNode* node10;
    int unk14;
    TransformNode* node18;
    float unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Vec3 m_dir;
    void FUN_00c26c00(float, ParticleList*);
    Vec3 Force(const Vec3& origin, const Vec3& axis, Vec3 point)
    {
        const Vec3 kPoint = point;
        ::Pt_c268 kForce = ::FUN_00c26820(reinterpret_cast<const ::Pt_c268&>(origin), reinterpret_cast<const ::Pt_c268&>(axis),
                                          reinterpret_cast<const ::Pt_c268&>(kPoint));
        return reinterpret_cast<const Vec3&>(kForce);
    }
};
// Computes the force on each particle in list from node10's transform and m_dir, scaled by age, and adds it to each particle's velocity.
// @fnv 0x00c26c00
void ForceOwner::FUN_00c26c00(float delta, ParticleList* list)
{
    NiTransform transformB;
    NiTransform transformA;
    transformB = node18->transform;
    transformA = node10->transform;
    NiTransform combined;
    NiTransform* pA = &transformA;
    reinterpret_cast<::NiTransform *>((pA))->CalculateInverse((::NiTransform &)(combined));
    reinterpret_cast<::NiTransform *>(&(combined))->operator*((const ::NiTransform &)(*pA));
    Vec3 axis = RotMul(transformA.rotation, m_dir);
    Vec3 origin = transformA.translation;
    reinterpret_cast<::FUN_004a0c10_s *>((((NormVec3*)&axis)))->FUN_004a0c10();
    for (unsigned short i = 0; i < list->count; ++i)
    {
        Particle* pParticle = list->particles + i;
        float age = delta;
        age -= pParticle->age;
        if (age != 0.0f)
        {
            Vec3& vel = pParticle->velocity;
            Vec3 result = Force(origin, axis, list->GetPositions()[i]);
            age = unk1c * age;
            result.x = age * result.x;
            result.y = age * result.y;
            result.z = age * result.z;
            vel += (const Vec3&)result;
        }
    }
}
}  // namespace fnv_00c26c00

namespace fnv_00c2c170 {
struct AirVector
{
    float x, y, z;
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    AirVector operator-(const AirVector& b) const
    {
        AirVector r = {x - b.x, y - b.y, z - b.z};
        return r;
    }
    AirVector operator*(float f) const
    {
        AirVector r = {x * f, y * f, z * f};
        return r;
    }
    AirVector& operator+=(const AirVector& b)
    {
        x = b.x + x;
        y += b.y;
        z += b.z;
        return *this;
    }
    float Dot(const AirVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};
class NiTransform
{
  public:
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
    AirVector translate;
    float scale;
    AirVector FUN_004b4500(const AirVector&);
};
struct AirNode
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    NiTransform world;
};
struct AirParticle
{
    AirVector velocity;
    float unk0c, unk10, birthTime, unk18;
};
struct AirParticles
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    AirVector* positions;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned short count, unk52;
    unsigned int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    AirParticle* particles;
    AirVector* GetVertices() const
    {
        return positions;
    }
    AirParticle* GetParticleInfo() const
    {
        return particles;
    }
};
inline AirVector Scale(AirVector a, float f)
{
    AirVector r = {f * a.x, f * a.y, f * a.z};
    return r;
}
struct AirField
{
    unsigned int unk00, unk04, unk08, unk0c;
    AirNode* owner;
    unsigned int unk14;
    AirNode* field;
    AirVector direction;
    float magnitude, nearDistance, farDistance;
    void FUN_00c2c170(float time, const AirParticles* data);
};
// Updates each particle's velocity along the normalized axis, with distance falloff above nearDistance and a time-based scale.
// @fnv 0x00c2c170
void AirField::FUN_00c2c170(float time, const AirParticles* apParticles)
{
    if (!(magnitude > 0.0f))
        return;
    if (apParticles->count <= 0)
        return;
    if (!field)
        return;
    NiTransform fieldWorld = field->world;
    NiTransform transform = owner->world;
    NiTransform inverse;
    reinterpret_cast<::NiTransform *>(&(transform))->CalculateInverse((::NiTransform &)(inverse));
    reinterpret_cast<::NiTransform *>((void *)&(inverse))->operator*((const ::NiTransform &)(transform));
    AirVector axis;
    axis = transform.FUN_004b4500(direction);
    reinterpret_cast<::FUN_004a0c10_s *>(&(axis))->FUN_004a0c10();
    float axisSquared = axis.SquaredLength();
    float range = farDistance - nearDistance;
    for (unsigned short i = 0; i < apParticles->count; ++i)
    {
        AirVector position = apParticles->GetVertices()[i];
        AirVector displacement = position - transform.translate;
        AirParticle* pAlias0 = &apParticles->GetParticleInfo()[i];
        AirParticle* pAlias1 = pAlias0;
        AirParticle* particle = pAlias1;
        float distance = (float)sqrt(displacement.SquaredLength());
        float force = magnitude;
        float age = (float)((time - particle->birthTime) / 0.03333330154418945);
        if (distance > nearDistance)
        {
            if (distance >= farDistance)
                continue;
            distance -= nearDistance;
            force *= 1.0f - distance / range;
        }
        float along = axis.Dot(particle->velocity);
        if (force * age > 1.0)
        {
            age = -along / axisSquared;
            particle->velocity += Scale(axis, age);
        }
        else
        {
            age = -force * age * (along / axisSquared);
            particle->velocity += Scale(axis, age);
        }
    }
}
}  // namespace fnv_00c2c170

void* __cdecl FUN_00c26810();

// FUN_00c26de0: NiPSysFieldModifier-style Update with attenuation - per-particle
// force from FUN_00c26820, scaled by magnitude * dt / dist^attenuation.
struct TPoint3
{
    float x, y, z;

    TPoint3()
    {}
    TPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    TPoint3 operator-(const TPoint3& kPt) const
    {
        return TPoint3(x - kPt.x, y - kPt.y, z - kPt.z);
    }
};


struct TMatrix3
{
    float m_afEntries[3][3];

    TPoint3 FUN_004b4500(const TPoint3& kPt) const;
};

struct NiTransform_od_o2_nood
{
    TMatrix3 m_kOrientation;
    TPoint3 m_kTranslation;
    float m_fScale;

public:
    void CalculateInverse(::NiTransform_od_o2_nood &);
public:
    ::NiTransform_od_o2_nood operator*(const ::NiTransform_od_o2_nood &) const;
};

struct TAVObject
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
    NiTransform_od_o2_nood m_kWorldSpaceTransform;
};

struct TParticleInfo
{
    TPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    int unk18;
};

struct TPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TPoint3* m_pkVertex;
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
    unsigned short m_usVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    TParticleInfo* m_pkParticleInfo;

    unsigned short GetShaderParticleCount() const
    {
        return m_usVertices;
    }
    TPoint3* GetVertices() const
    {
        return m_pkVertex;
    }
    TParticleInfo* GetParticleInfo() const
    {
        return m_pkParticleInfo;
    }
};

inline float NiPow(float fBase, float fExp)
{
    return (float)pow(fBase, fExp);
}

struct TFieldModifier
{
    void* m_pVtbl;
    int m_iRefCount;
    int m_kName;
    unsigned int m_uiUpdateOrder;
    TAVObject* m_pkTarget;
    bool m_bModifierActive;
    TAVObject* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    float m_fFieldStrength;
    TPoint3 m_kLightVector;

    void FUN_00c26de0(float fTime, TPSysData* pkData);
    __declspec(noalias) TPoint3 FUN_00c26820(const TPoint3& kFieldPos, const TPoint3& kFieldDir, const TPoint3& kPos);
};

// @fnv 0x00c26de0
void TFieldModifier::FUN_00c26de0(float fTime, TPSysData* pkData)
{
    if (m_fInfluence == 0.0f)
        return;
    if (pkData->GetShaderParticleCount() == 0)
        return;
    if (reinterpret_cast<::NiPoint3 *>((void *)&(m_kLightVector))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<const ::TPoint3 *>((void *)&::NiPoint3::ZERO)))))
        return;
    if (!m_pkFieldObject)
        return;

    if (m_fFieldAttenuation == 0.0f)
    {
        if (m_bEnableMaxDistance)
            reinterpret_cast<::VortexModifier *>(this)->FUN_00c269b0(fTime, (::PSysData *)(pkData));
        else
            reinterpret_cast<::fnv_00c26c00::ForceOwner *>(this)->FUN_00c26c00(fTime, (::fnv_00c26c00::ParticleList *)(pkData));
        return;
    }

    NiTransform_od_o2_nood kFieldXform = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform_od_o2_nood kInvPSys;
    {
        NiTransform_od_o2_nood kPSysXform = m_pkTarget->m_kWorldSpaceTransform;
        reinterpret_cast<::NiTransform_od_o2_nood *>((void *)&(kPSysXform))->CalculateInverse(kInvPSys);
    }

    {
        NiTransform_od_o2_nood kFieldToPSys = reinterpret_cast<::NiTransform_od_o2_nood *>((void *)&(kInvPSys))->operator*(kFieldXform);
        TPoint3 kFieldPos = kFieldToPSys.m_kTranslation;
        TPoint3 kFieldDir = kFieldToPSys.m_kOrientation.FUN_004b4500(m_kLightVector);
        reinterpret_cast<::FUN_004a0c10_s *>(&(kFieldDir))->FUN_004a0c10();

        for (unsigned short i = 0; i < pkData->GetShaderParticleCount(); i++)
        {
            TParticleInfo* pkInfo = &pkData->GetParticleInfo()[i];
            float fDeltaT = fTime - pkInfo->m_fZValue;
            if (fDeltaT != 0.0f)
            {
                TPoint3 kPos = pkData->GetVertices()[i];
                TPoint3 kDiff = kPos - kFieldToPSys.m_kTranslation;
                float fDist = reinterpret_cast<::NiPoint3 *>((void *)&(kDiff))->ComputeMagnitude();
                if (fDist != 0.0f)
                {
                    if (!m_bEnableMaxDistance || fDist <= m_fDistanceLimit)
                    {
                        TPoint3 kForce = FUN_00c26820(kFieldPos, kFieldDir, kPos);
                        if (m_fFieldAttenuation == 0.0f)
                            reinterpret_cast<::MyPoint439180 *>(&(kForce))->FUN_00439180(fDeltaT * m_fInfluence);
                        else
                            reinterpret_cast<::MyPoint439180 *>(&(kForce))->FUN_00439180(fDeltaT * m_fInfluence / NiPow(fDist, m_fFieldAttenuation));
                        reinterpret_cast<::FUN_0063c8a0_shell *>(&(pkInfo->m_kValue))->FUN_0063c8a0((void *)&(kForce));
                    }
                }
            }
        }
    }
}
