
// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c285c0
#include "fnv/decl/C32060EmitterModifier.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00c32120_cls.h"
#include "fnv/decl/NiPSysFieldModifierImpl.h"
#include "fnv/decl/S_00c322b0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01202000.h"
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
    *(int*)this = (int)&DAT_010c0b5c;
}


// @fnv 0x00c285a0
unsigned char __stdcall FUN_00c285a0(void* p)
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
