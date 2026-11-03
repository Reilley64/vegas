
#include <cstdint>
#include "fnv/symbols_00aa1000.h"
#include <new>
#include <cmath>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C326B0Modifier.h"
#include "fnv/decl/C32900Controller.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c32450_shell.h"
#include "fnv/decl/FUN_00c32490_shell.h"
#include "fnv/decl/FUN_00c32780.h"
#include "fnv/decl/FUN_00c329c0_object.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiPSysColliderStandin.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysplanarcollider_decls.h"

// Copies the base collider and the three collider parameters into dest, then clones and ref-counts the collider at offset 0x28.
// @fnv 0x00c32510
void NiPSysPlanarCollider::CopyMemberData(NiPSysPlanarCollider* dest, CloningProcess& process)
{
    reinterpret_cast<::FUN_00a5d450_class *>(this)->CreateVertexBufferSet((uintptr_t)(dest), (void *)&(process));

    dest->m_fBounceFactor = m_fBounceFactor;
    dest->m_bSpawnOnCollision = m_bSpawnOnCollision;
    dest->m_bDieOnCollision = m_bDieOnCollision;

    NiPSysCollider* sourceNext = this->m_spNextController.m_pObject;
    if (sourceNext)
    {
        NiPSysCollider* next = sourceNext->Clone(process);

        NiPSysCollider* destNext = dest->m_spNextController.m_pObject;
        if (destNext != next)
        {
            if (destNext)
            {
                destNext->DecRefCount();
            }
            dest->m_spNextController.m_pObject = next;
            if (next)
                next->IncRefCount();
        }
    }
}

// Loads the planar collider's stream fields: two floats, then two NiColor values, after the base collider's LoadBinary.
// @fnv 0x00c29770
void NiPSysPlanarCollider::LoadBinary(NiStream& stream)
{
    NiPSysCollider::LoadBinary(stream);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    PlanarReadFloat(stream, m_fOriginX);
    PlanarReadFloat(stream, m_fOriginZ);
    reinterpret_cast<NiColor*>(&m_kFirstVector)->LoadBinary(stream);
    reinterpret_cast<NiColor*>(&m_kSecondPlaneVector)->LoadBinary(stream);
}

struct FUN_00c299d0_shell : public NiPSysPlanarCollider
{
    void* FUN_00c299d0();
};

struct GlobalObjectO2_00a7b610;

// @fnv 0x00c299d0
void* FUN_00c299d0_shell::FUN_00c299d0()
{
    return &::g_012026c8;
}

void __cdecl _delete(void*, unsigned int);
struct FUN_00c299e0_Holder
{
    char _pad[0x28];
    NiObject* m_pObject;
    void* DestroyHolder(unsigned int);
};
// Releases m_pObject, destroys the NiRefObject base, and frees this with _delete when uiFlags has bit 0 set; returns this.
// @fnv 0x00c299e0
void* FUN_00c299e0_Holder::DestroyHolder(unsigned int uiFlags)
{
    if (m_pObject)
        m_pObject->DecRefCount();
    reinterpret_cast<class ::FUN_00a5d3d0 *>((((NiRefObject*)this)))->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (uiFlags & 1)
        _delete(this, 0x100);
    return this;
}

extern float DAT_010beaf8;
inline NiPoint3 NiPoint3::operator*(float s) const
{
    NiPoint3 result;
    result.x = x * s;
    result.y = y * s;
    result.z = z * s;
    return result;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 result;
    result.x = x - p.x;
    result.y = y - p.y;
    result.z = z - p.z;
    return result;
}
struct VelocityState
{
    NiPoint3 velocity;
    unsigned int unk0c, unk10, unk14, unk18;
};
struct BoundDataBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    uintptr_t unk20;
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
    VelocityState* velocities;
};
struct PlanarColliderResponse : NiPSysPlanarCollider
{
    void ApplyPlanarCollision(float, BoundDataBlock*, unsigned short);
};
// Projects the particle velocity onto the plane normal and reflects or removes the normal component, then calls FUN_00c32490.
// @fnv 0x00c29320
void PlanarColliderResponse::ApplyPlanarCollision(float time, BoundDataBlock* particles, unsigned short index)
{
    NiPoint3& velocity = particles->velocities[index].velocity;
    float dot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(m_kHalfSpacePlane.m_kPlaneNormal))->DotProduct((void *)&(velocity));
    NiPoint3 projection = m_kHalfSpacePlane.m_kPlaneNormal * dot;
    if (m_fSpawnRate == time && dot < DAT_010beaf8)
    {
        velocity.x -= projection.x;
        velocity.y -= projection.y;
        velocity.z -= projection.z;
    }
    else
    {
        NiPoint3 twice;
        twice.x = projection.x + projection.x;
        twice.y = projection.y + projection.y;
        twice.z = projection.z + projection.z;
        velocity.x = (float)(velocity.x - twice.x);
        velocity.y = (float)(velocity.y - twice.y);
        velocity.z = (float)(velocity.z - twice.z);
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(velocity))->FUN_00439180(m_fBounceFactor);
    }
    reinterpret_cast<::FUN_00c32490_shell *>(this)->FUN_00c32490(time, (::NiPSysData *)(particles), index);
}

class FUN_00c297f0_owner
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30(unsigned int a);
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    class FUN_00c297f0_io* m_250;
};

typedef unsigned int(__cdecl* FUN_00c297f0_read)(void* a, void* b, unsigned int c, unsigned int* d, unsigned int e);

class FUN_00c297f0_io
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    FUN_00c297f0_read m_0c;
};

class FUN_00c297f0_sub
{
  public:
    unsigned int unk00, unk04, unk08;
};

class FUN_00c297f0_cls
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    FUN_00c297f0_sub m_38;
    FUN_00c297f0_sub m_44;
    void FUN_00c297f0(FUN_00c297f0_owner* o);
};

// Calls Pre, writes m_2c via o->v30, then reads 4 bytes into m_30 and m_34 through o->m_250's read callback, and calls m_38 and m_44.
// @fnv 0x00c297f0
void FUN_00c297f0_cls::FUN_00c297f0(FUN_00c297f0_owner* apOwner)
{
    reinterpret_cast<::C32900Controller *>(this)->FUN_00c32900((*(::C32900Stream *)(apOwner)));
    apOwner->v30(m_2c);
    FUN_00c297f0_io* io = apOwner->m_250;
    {
        unsigned int out1 = 4;
        io->m_04 += io->m_0c(io, &m_30, 4, &out1, 1);
    }
    io = apOwner->m_250;
    {
        unsigned int out2 = 4;
        io->m_04 += io->m_0c(io, &m_34, 4, &out2, 1);
    }
    reinterpret_cast<::NiColor *>(&(m_38))->SaveBinary((*(::NiStream *)(apOwner)));
    reinterpret_cast<::NiColor *>(&(m_44))->SaveBinary((*(::NiStream *)(apOwner)));
}

struct Vec3f
{
    float x;
    float y;
    float z;
};




class SpawnedObject
{
  public:
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
    float m_f30;
    float m_f34;
    unsigned int m_u38;
    unsigned int m_u3c;
    unsigned int m_u40;
    Vec3f m_v44;

    SpawnedObject* Init(float a, int b, int c, int d, int e, float f, float g, Vec3f first, Vec3f second);
    SpawnedObject* CreateAndCopy(void* param);
};

// Allocates a 0x100-byte SpawnedObject, initialises it, passes it to FUN_00c32510, then copies m_f30..m_v44 from this into it and returns it.
// @fnv 0x00c29a30
SpawnedObject* SpawnedObject::CreateAndCopy(void* param)
{
    SpawnedObject* obj;
    void* mem = FUN_00aa13e0(0x100);
    if (mem != 0)
    {
        obj = reinterpret_cast<SpawnedObject*>(mem)->Init(1.0f, 0, 0, 0, 0, 1.0f, 1.0f,
                                                          *reinterpret_cast<Vec3f*>(&(*reinterpret_cast<float *>(&::DAT_011a946c))),
                                                          *reinterpret_cast<Vec3f*>(&(*reinterpret_cast<float *>(&::DAT_011a9478))));
    }
    else
    {
        obj = 0;
    }
    reinterpret_cast<::NiPSysPlanarCollider *>(this)->CopyMemberData((::NiPSysPlanarCollider *)(obj), (*(::CloningProcess *)(param)));
    obj->m_f30 = m_f30;
    obj->m_f34 = m_f34;
    obj->m_u38 = m_u38;
    obj->m_u3c = m_u3c;
    obj->m_u40 = m_u40;
    obj->m_v44 = m_v44;
    return obj;
}

namespace fnv_00c29af0 {
struct Vector3f
{
    float x, y, z;
};
struct CollisionHelper
{
    int FUN_00c29900(float, unsigned int, unsigned int, unsigned int, unsigned int, float, float, Vector3f,
                                Vector3f);
};


// @fnv 0x00c29af0
int __cdecl FUN_00c29af0()
{
    CollisionHelper* helper = FUN_00aa13e0(0x100);
    if (helper)
    {
        return helper->FUN_00c29900(1.0f, 0, 0, 0, 0, 1.0f, 1.0f, (*reinterpret_cast<::fnv_00c29af0::Vector3f *>(&::DAT_011a946c)), (*reinterpret_cast<::fnv_00c29af0::Vector3f *>(&::DAT_011a9478)));
    }
    return 0;
}
}  // namespace fnv_00c29af0

// NiPSysPlanarCollider::LinkObject(NiStream&): base LinkObject, then resolve the collider object link.
struct NiPSysColliderLinkBase
{
};
struct NiStreamLinkResolver
{
};
struct FUN_00c27ac0_shell : public NiPSysPlanarCollider
{
    void LinkColliderObject(NiStream& kStream);
};

// @fnv 0x00c27ac0
void FUN_00c27ac0_shell::LinkColliderObject(NiStream& kStream)
{
    reinterpret_cast<::NiPSysCollider *>((reinterpret_cast<NiPSysColliderLinkBase*>(this)))->LinkObject(kStream);
    m_pkColliderObject = (NiAVObject*)reinterpret_cast<::NiStream *>(&(reinterpret_cast<NiStreamLinkResolver&>(kStream)))->GetLoadedObject();
}

struct GlobalObjectO2_00a7b610
{
    const char* m_pcName;
};


struct NiViewerStringsArray
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char* element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct NiAVObjectView
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    const char* m_kName;
};

struct NiPoint3View : public NiPoint3
{
};

struct NiPSysColliderView : public NiPSysCollider
{
};

struct NiPSysPlanarColliderView : public NiPSysPlanarCollider
{
    void FUN_00c29b70(NiViewerStringsArray* pkStrings);
};

// Appends the base collider strings plus collider object name, width, height and X/Y axis strings to pkStrings.
// @fnv 0x00c29b70
void NiPSysPlanarColliderView::FUN_00c29b70(NiViewerStringsArray* pkStrings)
{
    reinterpret_cast<::FUN_00c329c0_object *>((static_cast<NiPSysColliderView*>(static_cast<NiPSysCollider*>(this))))->AppendProperties((::StrArr *)(pkStrings));
    pkStrings->Add(FUN_00a7d330(::g_012026c8.m_pcName));
    NiAVObjectView* pkObj = reinterpret_cast<NiAVObjectView*>(m_pkColliderObject);
    pkStrings->Add(::fnv_00a7d5e0::FUN_00a7d5e0("Collider Object", pkObj ? pkObj->m_kName : "None"));
    pkStrings->Add(FUN_00a7d550("Width", m_fOriginX));
    pkStrings->Add(FUN_00a7d550("Height", m_fOriginZ));
    pkStrings->Add(reinterpret_cast<::NiPoint3 *>((void *)&(static_cast<NiPoint3View&>(m_kFirstVector)))->FUN_00a59af0("X-Axis"));
    pkStrings->Add(reinterpret_cast<::NiPoint3 *>((void *)&(static_cast<NiPoint3View&>(m_kSecondPlaneVector)))->FUN_00a59af0("Y-Axis"));
}

struct Call_439090_tgt : NiPoint3
{
};
namespace c29 {
struct Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual bool IsEqual(Sub* p);
};
struct Coll
{
    char pad[0x2c];
    Sub* m_spSub;
    float m_f30;
    float m_f34;
    Call_439090_tgt m_k38;
    Call_439090_tgt m_k44;
    bool FUN_00c29870(Coll* p);
};
// @fnv 0x00c29870
bool Coll::FUN_00c29870(Coll* p)
{
    if (!reinterpret_cast<::C326B0Modifier *>(this)->FUN_00c326b0((::C326B0Object *)(p)))
        return false;
    if ((m_spSub && !p->m_spSub) || (!m_spSub && p->m_spSub) ||
        (m_spSub && p->m_spSub && !m_spSub->IsEqual(p->m_spSub)))
        return false;
    if (m_f30 != p->m_f30 || m_f34 != p->m_f34 || reinterpret_cast<::NiPlane *>(&(m_k38))->operator==((const ::NiPlane &)(p->m_k38)) || reinterpret_cast<::NiPlane *>(&(m_k44))->operator==((const ::NiPlane &)(p->m_k44)))
        return false;
    return true;
}
}

struct FUN_00c32680_Obj
{
};
struct FUN_00c28d00_cls
{
    bool FUN_00c28d00(void* a1);
};
// @fnv 0x00c28d00
bool FUN_00c28d00_cls::FUN_00c28d00(void* a1)
{
    return reinterpret_cast<::NiPSysColliderStandin *>((reinterpret_cast<FUN_00c32680_Obj*>(this)))->FUN_00c32680((const char *)(a1));
}

inline float absf(float x)
{
    return (float)fabs(x);
}
extern "C" unsigned int DAT_012026c4;
extern "C" float DAT_012026c0;
struct PlaneVector : NiPoint3
{
    PlaneVector()
    {}
    PlaneVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    PlaneVector(const NiPoint3& p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    float Dot(const PlaneVector& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float operator*(const PlaneVector& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    PlaneVector operator*(float s) const
    {
        return PlaneVector(x * s, y * s, z * s);
    }
    PlaneVector operator+(const PlaneVector& p) const
    {
        return PlaneVector(x + p.x, y + p.y, z + p.z);
    }
    PlaneVector operator-(const PlaneVector& p) const
    {
        return PlaneVector(x - p.x, y - p.y, z - p.z);
    }
    PlaneVector& operator+=(PlaneVector p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    PlaneVector& operator-=(PlaneVector p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
};
inline PlaneVector operator*(float s, const PlaneVector& p)
{
    PlaneVector r;
    const float* src = &p.y;
    float* dst = &r.x;
    for (int i = 1; i < 4; ++i)
        dst[i - 1] = s * src[i - 2];
    return r;
}

inline PlaneVector ScaleVectorD(const PlaneVector& v, float s)
{
    PlaneVector r;
    const float* a = &v.z;
    float* b = &r.z;
    for (int i = -2; i < 1; ++i)
        b[i] = s * a[i];
    return r;
}
inline float SpecialLength(const PlaneVector& p)
{
    double b = p.y;
    double a = p.x;
    double c = p.z;
    double d = a * a;
    d += b * b;
    d += c * c;
    return d;
}
struct CollisionPlane : NiPlane
{
    float Distance(const NiPoint3& p) const
    {
        float d = reinterpret_cast<const PlaneVector&>(m_kPlaneNormal) * reinterpret_cast<const PlaneVector&>(p);
        return d - m_fPlaneConstant;
    }
};
struct RotationHelper
{
    void FUN_004b4500(PlaneVector* result, const NiPoint3* direction);
};
struct PlanarColliderExt : NiPSysPlanarCollider
{
    NiPSysCollider* FUN_00c28d10(float time, float* collisionTime, BoundDataBlock* data, unsigned short particleId);
};
// Tests a particle against the planar collider's half-space plane, computes a collision fraction if crossing, and falls back to ResolveTail.
// @fnv 0x00c28d10
NiPSysCollider* PlanarColliderExt::FUN_00c28d10(float time, float* collisionTime, BoundDataBlock* data,
                                                unsigned short particleId)
{
    bool bCollided = false;
    const PlaneVector& particle = reinterpret_cast<const PlaneVector*>(data->unk20)[particleId];
    const PlaneVector& velocity = reinterpret_cast<const PlaneVector&>(data->velocities[particleId].velocity);
    const PlaneVector& normal = reinterpret_cast<const PlaneVector&>(m_kHalfSpacePlane.m_kPlaneNormal);
    double planeSum;
    planeSum = normal.y * particle.y;
    const float* planeN = &normal.y;
    const float* planeP = &particle.y;
    for (int i = 2; i < 3; ++i)
        planeSum += planeN[i - 3] * planeP[i - 3];
    const float* nz = &normal.y;
    const float* pz = &particle.z;
    for (int j = 0; 1 > j; ++j)
        planeSum += nz[j + 1] * pz[j + 0];
    float distance = (float)planeSum;
    distance -= m_kHalfSpacePlane.m_fPlaneConstant;
    if (DAT_010beaf8 > distance && DAT_010beaf8 > -distance)
    {
        PlaneVector relative = particle - reinterpret_cast<const PlaneVector&>(m_kPathOffset);
        PlaneVector xAxis, yAxis;
        reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&xAxis, &m_kFirstVector);
        reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&yAxis, &m_kSecondPlaneVector);
        NiPoint3 kAlongX = (NiPoint3)xAxis * (double)(relative * xAxis);
        NiPoint3 kAlongY = (NiPoint3)yAxis * (double)(yAxis * relative);
        if (reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kAlongX))->DotProduct((void *)&(kAlongX)) < m_fWidthSquared && reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kAlongY))->DotProduct((void *)&(kAlongY)) < m_fHeightSquared)
        {
            *collisionTime = time;
            m_fSpawnRate = time;
            reinterpret_cast<PlaneVector&>(m_kCollisionPosition) = particle;
            return this;
        }
    }
    else
    {
        float duration;
        duration = *collisionTime - time;
        PlaneVector delta;
        delta.x = duration * velocity.x;
        delta.y = duration * velocity.y;
        delta.z = duration * velocity.z;
        double projectedSum = delta.y * planeN[0];
        const float* nn1 = &normal.x;
        const float* dd1 = &delta.x;
        for (int l1 = 2; l1 < 3; ++l1)
            projectedSum += nn1[l1 - (2)] * dd1[l1 - (2)];
        const float* nn2 = &normal.z;
        const float* dd2 = &delta.z;
        for (int l2 = 2; l2 < 3; ++l2)
            projectedSum += nn2[l2 - (2)] * dd2[l2 - (2)];
        float projected = (float)projectedSum;
        float terminalDistance = projected + distance;
        if (absf(terminalDistance) < DAT_010beaf8)
            terminalDistance = 0.0f;
        if (terminalDistance * distance < ::_DAT_01012060)
        {
            float fraction = (-distance * duration) / projected;
            PlaneVector hitDelta;
            hitDelta.x = fraction * velocity.x;
            hitDelta.y = fraction * velocity.y;
            hitDelta.z = fraction * velocity.z;
            PlaneVector hit;
            hit.x = particle.x + hitDelta.x;
            hit.y = particle.y + hitDelta.y;
            hit.z = particle.z + hitDelta.z;
            if (!(DAT_012026c4 & 1u))
            {
                DAT_012026c4 |= 1u;
                double fTolInit = (float)pow(2.0, -21.0);
                DAT_012026c0 = fTolInit;
            }
            float adjustedDistance;
            adjustedDistance = reinterpret_cast<const CollisionPlane&>(m_kHalfSpacePlane).Distance(hit);
            if (adjustedDistance * distance < ::_DAT_01012060)
            {
                double absX = absf(hit.x);
                float maxCoord = absX;
                float fAbsY = absf(hit.y);
                if (fAbsY > maxCoord)
                    maxCoord = fAbsY;
                float fAbsZ;
                fAbsZ = absf(hit.z);
                maxCoord = (fAbsZ > maxCoord) ? fAbsZ : maxCoord;
                if (distance < 0.0f)
                {
                    hit -= ScaleVectorD(normal, maxCoord * DAT_012026c0);
                }
                else
                {
                    hit += (maxCoord * DAT_012026c0) * normal;
                }
            }
            PlaneVector relative = hit - reinterpret_cast<const PlaneVector&>(m_kPathOffset);
            PlaneVector xAxis, yAxis;
            reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&xAxis, &m_kFirstVector);
            reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&yAxis, &m_kSecondPlaneVector);
            PlaneVector kAlongX = xAxis * (relative * xAxis);
            PlaneVector kAlongY = yAxis * (yAxis * relative);
            if (SpecialLength(kAlongX) < m_fWidthSquared && SpecialLength(kAlongY) < m_fHeightSquared)
            {
                *collisionTime = fraction + time;
                reinterpret_cast<PlaneVector&>(m_kCollisionPosition) = hit;
                bCollided = true;
                m_fSpawnRate = fraction + time;
            }
        }
    }
    NiPSysCollider* result;
    result = ((::NiPSysCollider *)(reinterpret_cast<::FUN_00c32450_shell *>(this)->FUN_00c32450(time, (uintptr_t)(collisionTime), (uintptr_t)(data), particleId)));
    return result ? result : (bCollided ? this : 0);
}

struct Mat36
{
    int d[9];
};

extern int DAT_010beb0c;

struct DummyBase
{
};

struct DummyPlane
{
};

struct DummyTransform
{
};

// Calls the base initializer, stores the collider object and axis vectors, initializes plane and matrix data, and resets two transforms.
// @fnv 0x00c29900
void* FUN_00c29900(void* this_ptr, int, float fBounce, int bSpawnOnCollide, int bDieOnCollide,
                              void* pkSpawnModifier, void* pkColliderObj, float m_fGlyphWidthInPixels, float m_fGlyphExtent, NiPoint3 kXAxis,
                              NiPoint3 kYAxis)
{
    new ((void *)(((DummyBase*)this_ptr))) ::FUN_00c32780(fBounce, bSpawnOnCollide, bDieOnCollide, (::NiPSysSpawnModifier *)(pkSpawnModifier));
    *(int**)this_ptr = &DAT_010beb0c;
    *(void**)((char*)this_ptr + 0x2c) = pkColliderObj;
    *(float*)((char*)this_ptr + 0x30) = m_fGlyphWidthInPixels;
    *(float*)((char*)this_ptr + 0x34) = m_fGlyphExtent;
    *(NiPoint3*)((char*)this_ptr + 0x38) = kXAxis;
    *(NiPoint3*)((char*)this_ptr + 0x44) = kYAxis;
    *(float*)((char*)this_ptr + 0x50) = 0.5f;
    *(float*)((char*)this_ptr + 0x54) = 0.5f;
    new ((void *)(((DummyPlane*)((char*)this_ptr + 0x58)))) ::NiPlane(::NiPoint3::ZERO, 0.0f);
    *(NiPoint3*)((char*)this_ptr + 0x68) = ::NiPoint3::ZERO;
    *(Mat36*)((char*)this_ptr + 0x74) = (*reinterpret_cast<::Mat36 *>(&::DAT_011a9448));
    reinterpret_cast<::NiTransform *>((((DummyTransform*)((char*)this_ptr + 0x98))))->ResetToIdentity();
    reinterpret_cast<::NiTransform *>((((DummyTransform*)((char*)this_ptr + 0xcc))))->ResetToIdentity();
    return this_ptr;
}

#include "generated/data/gamebryo2.2/corelibs/niparticle/nipsysplanarcollider.inc"
