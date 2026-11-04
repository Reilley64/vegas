
// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c285c0
#include <cstdint>
#include "fnv/decl/C32060EmitterModifier.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00c32120_cls.h"
#include "fnv/decl/NiPSysFieldModifierImpl.h"
#include "fnv/decl/S_00c322b0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_00aa1000.h"
#include <new>
#include "fnv/decl/NiPSysParticle.h"
#include <cmath>
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/symbols_00404000.h"
void* __cdecl FUN_00c285c0()
{
    return &(*reinterpret_cast<void * *>(&::g_012026b0));
}

struct NiBinaryStream
{
    int _0;
    int _4;
    int _8;
    int(__cdecl* _12)(NiBinaryStream*, void*, int, unsigned int*, int);
};
struct NiStream
{
    char _0[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct NiPSysFieldModifier
{
    char _0[0x30];
};
struct NiPSysRadialFieldModifier : NiPSysFieldModifier
{
    float _30;
    void FUN_00c27770(NiStream&);
};
// @fnv 0x00c27770
void NiPSysRadialFieldModifier::FUN_00c27770(NiStream& kStream)
{
    reinterpret_cast<::NiPSysFieldModifierImpl *>(this)->FUN_00c321f0(kStream);
    NiBinaryStream* __restrict output = kStream.m_pBackingStream;
    unsigned int size = 4;
    output->_4 += output->_12(output, &_30, 4, &size, 1);
}

namespace fnv_00c28760 {
struct NiBinaryStream
{
    int _pad;
    int position;
    int(__cdecl* read)(NiBinaryStream*, void*, int, unsigned int*, int);
};
struct NiStream
{
    char _pad[0x24C];
    NiBinaryStream* m_pUnderlyingStream;
};
struct NiPSysFieldModifier
{
    char _pad[0x30];
};
struct NiPSysRadialFieldModifier : NiPSysFieldModifier
{
    float m_fBoundRadius;
    void FUN_00c28760(NiStream&);
};
// @fnv 0x00c28760
void NiPSysRadialFieldModifier::FUN_00c28760(NiStream& stream)
{
    reinterpret_cast<::FUN_00c32120_cls *>(this)->LoadFromStream((::StreamOwner *)&(stream));
    NiBinaryStream* __restrict input = stream.m_pUnderlyingStream;
    unsigned int size = 4;
    input->position += input->read(input, &m_fBoundRadius, 4, &size, 1);
}
}  // namespace fnv_00c28760

struct NiPSysPositionModifier
{
    char _pad[0x18];
    NiPSysPositionModifier();
};
extern int DAT_010c0b5c;
struct FUN_00c31ff0 : NiPSysPositionModifier
{
    int _m18;
    float _m1c;
    float _m20;
    bool _m24;
    float _m28;
    float _m2c;
    FUN_00c31ff0();
};
// Initializes the position modifier's fields to zero and installs the vtable pointer from DAT_010c0b5c.
// @fnv 0x00c31ff0
FUN_00c31ff0::FUN_00c31ff0() : _m18(0), _m1c(0.0f), _m20(0.0f), _m24(0), _m28(0.0f), _m2c(0.0f)
{
    *(intptr_t*)this = (intptr_t)&DAT_010c0b5c;
}


// @fnv 0x00c285a0
unsigned char FUN_00c285a0(void* p)
{
    return ((char)(reinterpret_cast<::C32060EmitterModifier *>((p))->FUN_00c32060({}))) != 0;
}

struct S_00c28a90_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
};
struct S_00c28a90_Base
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
};
struct S_00c28a90 : S_00c28a90_Base
{
    float m30;
    void WriteToArray(S_00c28a90_Arr* a);
};
__forceinline void S_00c28a90_Add(S_00c28a90_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        reinterpret_cast<::ViewerStrings *>((a))->SetSize(i + a->growBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((a))->SetAt(i, s);
}
// @fnv 0x00c28a90
void S_00c28a90::WriteToArray(S_00c28a90_Arr* pArray)
{
    reinterpret_cast<::S_00c322b0 *>(this)->FUN_00c322b0((::S_00c322b0_Arr *)(pArray));
    S_00c28a90_Add(pArray, FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_012026b0))));
    S_00c28a90_Add(pArray, FUN_00a7d550("RadialType", m30));
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3 operator*(float fScalar) const
    {
        return NiPoint3(fScalar * x, fScalar * y, fScalar * z);
    }
    NiPoint3& operator+=(const NiPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
public:
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
    void AddZTo(float& dst) const
    {
        dst = z + dst;
    }
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
public:
    void CalculateInverse(::NiTransform &);
public:
    ::NiTransform operator*(const ::NiTransform &) const;
};
struct NiAVObjectStandIn
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
    NiTransform m_kWorldSpaceTransform;
};
struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};
struct NiPSysDataStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* m_pkVertex;
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
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};
struct FieldMod
{
    void* vtbl;
    int m_uiRefCount;
    int m_kName;
    int m_uiUpdateOrder;
    NiAVObjectStandIn* m_pkTarget;
    int m_bModifierActive;
    NiAVObjectStandIn* m_pkFieldObject;
    float m_fInfluence;
    void Update(float fTime, NiPSysDataStandIn* pkData);
};
// Applies a time-scaled field influence to each active particle's position using the delta between the field object and target transforms.
// @fnv 0x00c28620
void FieldMod::Update(float fTime, NiPSysDataStandIn* pkData)
{
    NiTransform kField = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInv;
    {
        NiTransform kPrev = m_pkTarget->m_kWorldSpaceTransform;
        reinterpret_cast<::NiTransform *>((void *)&(kPrev))->CalculateInverse(kInv);
    }
    {
        NiTransform kDelta = reinterpret_cast<::NiTransform *>((void *)&(kInv))->operator*(kField);
        NiPoint3* pkPos = pkData->m_pkVertex;
        float fMag = m_fInfluence;
        for (unsigned short i = 0; i < pkData->m_usActiveVertices; i++)
        {
            Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[i];
            float fDt = fTime - pkInfo->m_fZValue;
            if (fDt != 0.0f)
            {
                NiPoint3 kWorldPosition = *pkPos++ - kDelta.m_kTranslation;
                float fS = fDt * fMag;
                kWorldPosition = kWorldPosition * fS;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(pkInfo->m_kValue))->FUN_0063c8a0((void *)&(kWorldPosition));
            }
        }
    }
}

void* __cdecl FUN_00c285c0();
unsigned char FUN_00c285a0(void* p);

extern int DAT_010be99c;


struct RadialFieldObject_00c285d0 : FUN_00c31ff0
{
    float m30;
    RadialFieldObject_00c285d0()
    {
        m30 = 0.0f;
        *((intptr_t*)this) = (intptr_t)&DAT_010be99c;
    }
};

struct FUN_00c285d0_cls
{
    int unk0;
    void* FUN_00c285d0(uintptr_t a1);
};

// @fnv 0x00c285d0
void* FUN_00c285d0_cls::FUN_00c285d0(uintptr_t a1)
{
    RadialFieldObject_00c285d0* p = new (FUN_00aa13e0(0x34)) RadialFieldObject_00c285d0;
    reinterpret_cast<::NiPSysParticle *>(this)->FUN_00c32020((::NiPSysParticle *)(p), (::CloningProcess *)(a1));
    return p;
}



inline NiPoint3 ScalePoint(float s, float x, const NiPoint3& d)
{
    return NiPoint3(s * x, d.y * s, s * d.z);
}
struct NiTransform_od_o2_gs_nood_nogs
{
    float rotation[3][3];
    NiPoint3 translation;
    float scale;
    NiTransform_od_o2_gs_nood_nogs operator*(const NiTransform_od_o2_gs_nood_nogs& rhs) const;
public:
    void CalculateInverse(::NiTransform_od_o2_gs_nood_nogs &);
};

struct SceneObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    NiTransform_od_o2_gs_nood_nogs world;
    NiTransform_od_o2_gs_nood_nogs GetWorldTransform() const
    {
        return world;
    }
};

struct Particle
{
    NiPoint3 velocity;
    float unk0c, unk10, birthTime, unk18;
};

struct ParticleSystem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    NiPoint3* positions;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    unsigned short count, unk52;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    Particle* particles;
};

inline float NiPow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

class RadialField
{
  public:
    int unk00, unk04, unk08, unk0c;
    SceneObject* target;
    int unk14;
    SceneObject* source;
    float strength;
    float exponent;
    bool useRadius;
    float unk28;
    float radiusSquared;
    float attenuation;
    void FUN_00c287a0(float time, ParticleSystem* system);
};

// @fnv 0x00c287a0
void RadialField::FUN_00c287a0(float time, ParticleSystem* system)
{
    if (strength == 0.0f || system->count == 0 || source == 0)
        return;
    if (!useRadius && (exponent == 0.0f || attenuation == 0.0f))
    {
        reinterpret_cast<::FieldMod *>(this)->Update(time, (::NiPSysDataStandIn *)(system));
        return;
    }
    NiTransform_od_o2_gs_nood_nogs sourceTransform = source->world;
    NiTransform_od_o2_gs_nood_nogs inverse;
    {
        NiTransform_od_o2_gs_nood_nogs targetTransform = target->world;
        reinterpret_cast<::NiTransform_od_o2_gs_nood_nogs *>((void *)&(targetTransform))->CalculateInverse(inverse);
    }
    {
        NiTransform_od_o2_gs_nood_nogs fieldToSystem = inverse * sourceTransform;
        float halfExponent = exponent * 0.5;
        for (unsigned short i = 0; i < system->count; ++i)
        {
            Particle& particle = system->particles[i];
            float deltaTime = time - particle.birthTime;
            if (deltaTime == 0.0f)
                continue;
            NiPoint3 position = system->positions[i];
            NiPoint3 difference = position - fieldToSystem.translation;
            float distanceSquared = reinterpret_cast<::TESCombatStyle *>((void *)&(difference))->UpdateCombatStyle();
            if (useRadius && !(radiusSquared >= distanceSquared))
                continue;
            NiPoint3 change;
            if (exponent != 0.0f && distanceSquared != 0.0f)
            {
                change = ScalePoint((deltaTime * strength) /
                                        FUN_00404010(1.0f, NiPow(distanceSquared, halfExponent) * attenuation),
                                    difference.x, difference);
            }
            else
            {
                float scale = deltaTime * strength;
                change = difference * scale;
            }
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(particle.velocity))->FUN_0063c8a0((void *)&(change));
        }
    }
}
