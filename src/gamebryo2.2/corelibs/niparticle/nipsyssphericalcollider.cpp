
// src/gamebryo2.2/corelibs/niparticle/nipsyssphericalcollider.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsyssphericalcollider.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c281f0
#include <windows.h>
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/C326B0Modifier.h"
#include "fnv/decl/C32900Controller.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c32450_shell.h"
#include "fnv/decl/FUN_00c32490_shell.h"
#include "fnv/decl/FUN_00c32780.h"
#include "fnv/decl/FUN_00c329c0_object.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/Transform3D.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
const void* __cdecl FUN_00c281f0()
{
    return &(*reinterpret_cast<const void * *>(&::g_012026a0));
}

struct NiBinaryStream
{
    unsigned int _0;
    unsigned int _4;
    unsigned int(__cdecl* _8)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& f)
    {
        unsigned int uiSize = 4;
        _4 += _8(this, &f, 4, &uiSize, 1);
    }
};
struct NiStream
{
    char _pad0[0xD8];
    unsigned int m_uiNifVersion;
    char _pad1[0x24C - 0xD8 - 4];
    NiBinaryStream* m_pUnderlyingStream;
};
class CloningProcess;
struct NiPSysCollider
{
    virtual void LoadBinary(NiStream&);
    char _pad[0x2C];
public:
    void ProcessClone(::CloningProcess &);
};
struct NiPSysSphericalCollider : NiPSysCollider
{
    float m_fBoundRadius;
    void FUN_00c28070(NiStream&);
};
// @fnv 0x00c28070
void NiPSysSphericalCollider::FUN_00c28070(NiStream& kStream)
{
    NiPSysCollider::LoadBinary(kStream);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    if (kStream.m_uiNifVersion >= 0x0A000113)
        kStream.m_pUnderlyingStream->ReadFloat(m_fBoundRadius);
}

namespace fnv_00c28200 {
struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct NiPSysSphericalCollider : NiRefObject
{
    char _pad[0x20];
    NiRefObject* m_ptr;
    char _pad2[0xB0 - 0x2C];
    void* FUN_00c28200(unsigned int);
};
// Releases m_ptr, runs the base destructor, and frees this with _delete when flags has bit 0 set; returns this.
// @fnv 0x00c28200
void* NiPSysSphericalCollider::FUN_00c28200(unsigned int flags)
{
    if (m_ptr)
        m_ptr->DecRefCount();
    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xb0);
    return this;
}
}  // namespace fnv_00c28200

struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};
struct Collider : BSFadeNode
{
    Collider* FUN_00c28110(float, int, int, int, int, float);
};
// @fnv 0x00c282a0
Collider* CreateCollider()
{
    Collider* p = (Collider*)BSFadeNode::operator new(0xb0);
    if (p)
        return p->FUN_00c28110(1.0f, 0, 0, 0, 0, 1.0f);
    return 0;
}

namespace fnv_00c29450 {
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

struct NiObject
{
    virtual ~NiObject();
};

struct NiAVObject : NiObject
{
};

struct ShaderBufferRecord;

struct NiTStringPointerMap_SBE
{
};

struct NiPSysCollider
{
    virtual void ProcessClone(CloningProcess&);
};

struct NiPSysPlanarCollider : NiPSysCollider
{
    char _pad[0x28];
    void* unk2c;
    NiAVObject* m_pkColliderObject;
    void FUN_00c29450(CloningProcess&);
};

// @fnv 0x00c29450
void NiPSysPlanarCollider::FUN_00c29450(CloningProcess& kCloning)
{
    reinterpret_cast<::NiPSysCollider *>(this)->ProcessClone((::CloningProcess &)(kCloning));
    ShaderBufferRecord* pkClone = 0;
    reinterpret_cast<::A54440Hash *>((((NiTStringPointerMap_SBE*)kCloning.m_pCloneMap)))->FUN_00a53c30((::A54440Manager *)((const char*)this), (::A54440Manager **)&(pkClone));
    NiPSysPlanarCollider* pkDest = (NiPSysPlanarCollider*)pkClone;
    if (*(NiAVObject**)&this->unk2c)
    {
        if (reinterpret_cast<::A54440Hash *>((((NiTStringPointerMap_SBE*)kCloning.m_pCloneMap)))->FUN_00a53c30((::A54440Manager *)((const char*)*(NiAVObject**)&this->unk2c), (::A54440Manager **)&(pkClone)))
            *(NiAVObject**)&pkDest->unk2c = (NiAVObject*)pkClone;
        else
            *(NiAVObject**)&pkDest->unk2c = *(NiAVObject**)&this->unk2c;
    }
}
}  // namespace fnv_00c29450

struct CloningProcess;
struct NiPSysPlanarCollider
{
    void CopyMemberData(NiPSysPlanarCollider*, CloningProcess&);
};
struct FUN_00c28250_shell : NiPSysSphericalCollider
{
    Collider* CloneCollider(CloningProcess& kCloning);
};
// @fnv 0x00c28250
Collider* FUN_00c28250_shell::CloneCollider(CloningProcess& kCloning)
{
    Collider* pkObject = (Collider*)BSFadeNode::operator new(0xb0);
    if (pkObject)
        pkObject = pkObject->FUN_00c28110(1.0f, 0, 0, 0, 0, 1.0f);
    else
        pkObject = 0;
    ((NiPSysPlanarCollider*)this)->CopyMemberData((NiPSysPlanarCollider*)pkObject, kCloning);
    ((NiPSysSphericalCollider*)pkObject)->m_fBoundRadius = m_fBoundRadius;
    return pkObject;
}

struct ColliderPoint
{
    float x, y, z;
};
struct NiTransform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ColliderPoint translation;
    float scale;
    bool operator!=(const NiTransform& other) const
    {
        return ((bool)(reinterpret_cast<::Transform3D *>((void *)this)->FUN_00a86c30((const ::Transform3D &)(other))));
    }
    NiTransform operator*(const NiTransform&) const;
public:
    void CalculateInverse(::NiTransform &);
public:
    void ResetToIdentity();
};
struct ColliderNode
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
    NiTransform world;
};
struct ColliderOwner
{
    int unk00, unk04, unk08, unk0C;
    ColliderNode* node;
    ColliderNode* GetNode() const
    {
        return node;
    }
};
struct ColliderNext
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void update();
};
struct UpdateCollider
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    ColliderOwner* owner;
    ColliderNext* next;
    ColliderNode* node;
    float radius, scaledRadius, squaredRadius;
    ColliderPoint center;
    NiTransform cachedNode, cachedOwner;
    void UpdateColliderTransform();
};
// Recomputes the collider's center, scaled radius and squared radius from the node and owner world transforms when either has changed, then calls next->update().
// @fnv 0x00c27f60
void UpdateCollider::UpdateColliderTransform()
{
    if (cachedNode != node->world || cachedOwner != owner->GetNode()->world)
    {
        NiTransform nodeTransform;
        if (node)
            nodeTransform = node->world;
        else
            reinterpret_cast<::NiTransform *>(&(nodeTransform))->ResetToIdentity();
        NiTransform ownerTransform = owner->GetNode()->world;
        NiTransform inverse;
        reinterpret_cast<::NiTransform *>((void *)&(ownerTransform))->CalculateInverse(inverse);
        NiTransform relative = inverse * nodeTransform;
        float newRadius = radius * relative.scale;
        center = relative.translation;
        scaledRadius = newRadius;
        squaredRadius = scaledRadius * scaledRadius;
        cachedOwner = ownerTransform;
        cachedNode = nodeTransform;
    }
    if (next)
        next->update();
}

struct InputBinaryStream2
{
    unsigned int streamFlags;
    unsigned int bytesRead;
    unsigned int readMode;
    unsigned int(__cdecl* readData)(InputBinaryStream2*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& value)
    {
        unsigned int bytes = 4;
        bytesRead += readData(this, &value, 4, &bytes, 1);
    }
};
struct StreamView
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void ReadObject(unsigned int) = 0;
    InputBinaryStream2* Input()
    {
        return *reinterpret_cast<InputBinaryStream2**>(reinterpret_cast<char*>(this) + 0x250);
    }
};
struct SphericalColliderReader : NiPSysCollider
{
    unsigned int& linkId()
    {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x2c);
    }
    float& radius()
    {
        return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x30);
    }
    void ReadSphericalCollider(NiStream& stream);
};
// Reads the base collider data, then reads the link id and radius float from the stream.
// @fnv 0x00c280c0
void SphericalColliderReader::ReadSphericalCollider(NiStream& stream)
{
    reinterpret_cast<::C32900Controller *>(this)->FUN_00c32900((::C32900Stream &)(stream));
    StreamView& reader = reinterpret_cast<StreamView&>(stream);
    reader.ReadObject(linkId());
    reader.Input()->ReadFloat(radius());
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    NiPoint3 operator*(float s) const
    {
        return NiPoint3(x * s, y * s, z * s);
    }
    NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return NiPoint3(x * inv, y * inv, z * inv);
    }
    float operator*(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    NiPoint3& operator-=(const NiPoint3& p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
    NiPoint3& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
public:
    static const ::NiPoint3 ZERO;
};

inline NiPoint3 operator*(float s, const NiPoint3& p)
{
    return NiPoint3(s * p.x, s * p.y, s * p.z);
}

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
};

struct NiPSysData
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
    Point3ParameterData* m_pkParticleInfo;
};

struct NiPSysColliderBase
{
    int vtbl00;
    int unk04;
    float m_fBounceFactor;
    int unk0C;
    int unk10;
    NiPoint3 m_kCollisionPosition;
};

struct NiPSysSphericalColliderX : NiPSysColliderBase
{
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    float m_fSphereRadius;
    int unk38;
    NiPoint3 m_kPathOffset;
    void ResolveSphericalCollision(float fInitialTime, NiPSysData* pkData, unsigned short usCurrentParticle);
};

// @fnv 0x00c27e20
void NiPSysSphericalColliderX::ResolveSphericalCollision(float fInitialTime, NiPSysData* pkData,
                                                         unsigned short usCurrentParticle)
{
    Point3ParameterData* pkCurrentParticle = &pkData->m_pkParticleInfo[usCurrentParticle];
    NiPoint3& kVel = pkCurrentParticle->m_kValue;
    NiPoint3 kNormal = (m_kCollisionPosition - m_kPathOffset) / m_fSphereRadius;
    float fProjection = kVel * kNormal;
    NiPoint3 kTemp = fProjection * kNormal;
    kVel -= kTemp + kTemp;
    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(kVel))->FUN_00439180(m_fBounceFactor);
    reinterpret_cast<::FUN_00c32490_shell *>(this)->FUN_00c32490(fInitialTime, pkData, usCurrentParticle);
}

struct StrArr
{
    int unk00;
    char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growth;
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
};
extern const char DAT_010be8cc[];
struct InfoName
{
    int unk00;
    int unk04;
    const char* name;
};
struct ColliderInfo
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
    InfoName* info;
    float radius;
    void FUN_00c282d0(StrArr* strings);
};
// @fnv 0x00c282d0
void ColliderInfo::FUN_00c282d0(StrArr* strings)
{
    reinterpret_cast<::FUN_00c329c0_object *>(this)->AppendProperties(strings);
    strings->Add(::FUN_00a7d330((const char *)((*reinterpret_cast<const void * *>(&::g_012026a0)))));
    strings->Add(::fnv_00a7d5e0::FUN_00a7d5e0(DAT_010be8cc, info ? info->name : (*reinterpret_cast<const char (*)[]>((void *)&::g_011d1f8c_arg1))));
    strings->Add(FUN_00a7d550((*reinterpret_cast<const char (*)[]>(&::UNK_01015a9c)), radius));
}

struct FUN_00c27ae0_obj
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
    virtual bool IsEqual(FUN_00c27ae0_obj* pkObject);
};

struct FUN_00c27ae0_base
{
};

struct FUN_00c27ae0_cls : FUN_00c27ae0_base
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
    FUN_00c27ae0_obj* m_pkColliderObject;
    float m_fBoundRadius;
    bool FUN_00c27ae0(FUN_00c27ae0_cls* pkObject);
};

// Returns false if the base comparison, collider-object comparison, or bound-radius comparison fails.
// @fnv 0x00c27ae0
bool FUN_00c27ae0_cls::FUN_00c27ae0(FUN_00c27ae0_cls* pkObject)
{
    if (!reinterpret_cast<::C326B0Modifier *>(this)->FUN_00c326b0((::C326B0Object *)(pkObject)))
        return false;

    FUN_00c27ae0_cls* pkDest = pkObject;

    if ((m_pkColliderObject && !pkDest->m_pkColliderObject) || (!m_pkColliderObject && pkDest->m_pkColliderObject) ||
        (m_pkColliderObject && pkDest->m_pkColliderObject && !m_pkColliderObject->IsEqual(pkDest->m_pkColliderObject)))
    {
        return false;
    }

    if (m_fBoundRadius != pkDest->m_fBoundRadius)
        return false;

    return true;
}

#include <math.h>
extern "C" float g_010be824;
struct CollisionVector
{
    float x, y, z;
    CollisionVector()
    {}
    CollisionVector(float a, float b, float c) : x(a), y(b), z(c)
    {}
    CollisionVector operator-(const CollisionVector& b) const
    {
        return CollisionVector(x - b.x, y - b.y, z - b.z);
    }
    CollisionVector operator+(const CollisionVector& b) const
    {
        return CollisionVector(x + b.x, y + b.y, z + b.z);
    }
    CollisionVector operator*(float s) const
    {
        return CollisionVector(x * s, y * s, z * s);
    }
    float operator*(const CollisionVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    float SquaredLength() const
    {
        return (*this) * (*this);
    }
};
struct CollisionParticle
{
    CollisionVector velocity;
    float age, lifespan, lastUpdate, generation;
};
struct CollisionParticles
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CollisionVector* positions;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    CollisionParticle* particles;
};
struct SphereCollision
{
    int unk00, unk04, unk08, unk0c, unk10;
    CollisionVector hitPoint;
    float hitTime;
    ColliderOwner* owner;
    ColliderNext* next;
    ColliderNode* node;
    float radius, scaledRadius, squaredRadius;
    CollisionVector center;
    SphereCollision* TestSphereCollision(float, float&, CollisionParticles*, unsigned short);
};
// Tests if a particle at the given index hits this sphere, updating earliest and hitPoint if so, then delegates to FUN_00c32450.
// @fnv 0x00c27b40
SphereCollision* SphereCollision::TestSphereCollision(float time, float& earliest, CollisionParticles* data,
                                                      unsigned short index)
{
    bool hit = false;
    const CollisionVector& position = data->positions[index];
    const CollisionVector& velocity = data->particles[index].velocity;
    CollisionVector difference = position - center;
    float c = difference.SquaredLength() - squaredRadius;
    bool inside = -c > g_010be824;
    if (inside || c > g_010be824)
    {
        float projection = -(difference * velocity);
        if (inside || projection > 0.0f)
        {
            float speedSquared = velocity.SquaredLength();
            float t = projection / speedSquared;
            difference = (position + velocity * t) - center;
            const CollisionVector& relative = difference;
            float distanceSquared = relative.SquaredLength();
            if (inside || distanceSquared < squaredRadius)
            {
                float delta = squaredRadius - distanceSquared;
                if (inside)
                    t += sqrtf(delta / speedSquared);
                else
                    t -= sqrtf(delta / speedSquared);
                if (t < earliest - time)
                {
                    hit = true;
                    float collisionTime = time + t;
                    hitTime = earliest = collisionTime;
                    hitPoint = position + velocity * t;
                }
            }
        }
    }
    SphereCollision* result = ((::SphereCollision *)(reinterpret_cast<::FUN_00c32450_shell *>(this)->FUN_00c32450(time, (unsigned int)&(earliest), (unsigned int)(data), index)));
    return result ? result : (hit ? this : 0);
}

struct NiPoint3U : NiPoint3
{
    NiPoint3U()
    {}
    NiPoint3U(const NiPoint3& p) : NiPoint3(p)
    {}
    NiPoint3U(float a, float b, float c) : NiPoint3(a, b, c)
    {}
    NiPoint3U& operator=(const NiPoint3& p)
    {
        NiPoint3::operator=(p);
        return *this;
    }
    static NiPoint3U Cross(const NiPoint3& a, const NiPoint3& b)
    {
        const float& az = a.z;
        return NiPoint3U(a.y * b.z - az * b.y, az * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }
};
struct NiPlane
{
    NiPoint3 normal;
    float constant;
    NiPlane(const NiPoint3&, float);
    NiPlane(const NiPoint3&, const NiPoint3&);
    bool operator==(const NiPlane& p) const
    {
        return normal.x == p.normal.x && normal.y == p.normal.y && normal.z == p.normal.z && constant == p.constant;
    }
public:
    bool operator==(const ::NiPlane &);
};
struct ColliderMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3 operator*(const NiPoint3& p) const
    {
        double y1 = m11 * p.y;
        double z1 = m21 * p.y;
        return NiPoint3(m00 * p.x + m01 * p.y + m02 * p.z, m10 * p.x + y1 + m12 * p.z, m20 * p.x + z1 + m22 * p.z);
    }
};
struct PlanarColliderUpdate
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ColliderOwner* owner;
    ColliderNext* next;
    ColliderNode* node;
    float width, height;
    NiPoint3 axis1, axis2;
    float squareWidth, squareHeight;
    NiPlane plane;
    NiPoint3 center;
    ColliderMatrix rotation;
    NiTransform cachedNode, cachedOwner;
    void Update();
};
// Recomputes plane, center, rotation, and squared dimensions when the plane is zero or transforms differ, then updates the next collider.
// @fnv 0x00c294b0
void PlanarColliderUpdate::Update()
{
    if (reinterpret_cast<::NiPlane *>((void *)&(const ::NiPlane &)(plane))->operator==(NiPlane(::NiPoint3::ZERO, 0.0f)) ||
        (node && (cachedNode != node->world || cachedOwner != owner->GetNode()->world)))
    {
        center = ::NiPoint3::ZERO;
        rotation = (*reinterpret_cast<const ::ColliderMatrix *>(&::DAT_011a9448));
        NiPoint3U normal = NiPoint3U::Cross(axis1, axis2);
        reinterpret_cast<::FUN_004a0c10_s *>(&(static_cast<NiPoint3U&>(normal)))->FUN_004a0c10();
        float w = width;
        float h = height;
        if (node)
        {
            NiTransform nodeWorld = node->world;
            NiTransform ownerWorld = owner->GetNode()->world;
            NiTransform inverse;
            reinterpret_cast<::NiTransform *>((void *)&(ownerWorld))->CalculateInverse(inverse);
            NiTransform relative = inverse * nodeWorld;
            center = reinterpret_cast<const NiPoint3&>(relative.translation);
            rotation = reinterpret_cast<const ColliderMatrix&>(relative.m00);
            static_cast<NiPoint3&>(normal) = rotation * normal;
            reinterpret_cast<::FUN_004a0c10_s *>(&(static_cast<NiPoint3U&>(normal)))->FUN_004a0c10();
            w *= relative.scale;
            h *= relative.scale;
            cachedNode = nodeWorld;
            cachedOwner = ownerWorld;
        }
        w *= 0.5;
        h *= 0.5;
        squareWidth = w * w;
        squareHeight = h * h;
        plane = NiPlane(normal, center);
    }
    if (next)
        next->update();
}

extern const char DAT_010be834[];
struct NiPSysColliderInit
{
};

// Initializes collider fields, passes settings to the base initializer, sets a nonnegative radius, and initializes cached transforms.
// @fnv 0x00c28110
Collider* Collider::FUN_00c28110(float fBounce, int bSpawnOnCollide, int bDieOnCollide, int pkSpawnModifier,
                                 int pkColliderObj, float fRadius)
{
    UpdateCollider* p = (UpdateCollider*)this;
    new ((void *)(((NiPSysColliderInit*)this))) ::FUN_00c32780(fBounce, bSpawnOnCollide, bDieOnCollide, (::NiPSysSpawnModifier *)(pkSpawnModifier));
    p->node = (ColliderNode*)pkColliderObj;
    p->radius = 1.0f;
    p->squaredRadius = 1.0f;
    *(const void**)this = DAT_010be834;
    p->center = reinterpret_cast<const ColliderPoint&>(::NiPoint3::ZERO);
    if (fRadius >= 0.0f)
        p->radius = fRadius;
    ColliderPoint kMaxPoint = {-3.402823466e+38F, -3.402823466e+38F, -3.402823466e+38F};
    p->cachedNode.translation = p->cachedOwner.translation = kMaxPoint;
    reinterpret_cast<ColliderMatrix&>(p->cachedNode.m00) = reinterpret_cast<ColliderMatrix&>(p->cachedOwner.m00) =
        (*reinterpret_cast<const ::ColliderMatrix *>(&::DAT_011f4248));
    p->cachedNode.scale = p->cachedOwner.scale = -3.402823466e+38F;
    return this;
}

#include "generated/data/gamebryo2.2/corelibs/niparticle/nipsyssphericalcollider.inc"
