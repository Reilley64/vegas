// fallout_shared/tempeffects/bstempeffectsimpledecal.cpp: BSTempEffectSimpleDecal, NiPoint3, DecalStub, DecalHolder and more (27 functions)

#include <cstdint>
#include <new>
#include <cmath>
#include "fnv/decl/BSFaceGenKeyframe.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/DecalListManager.h"
#include "fnv/decl/FUN_00438230_Class.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a8030_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004bc480_shell.h"
#include "fnv/decl/FUN_004ee560_shell.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_00682810_shell.h"
#include "fnv/decl/FUN_006828a0_shell.h"
#include "fnv/decl/FUN_0068e740_class.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/FUN_009bd580_class.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00aa54a0_s.h"
#include "fnv/decl/FUN_00b66ad0_cls.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MLx.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/ResizeMesh.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/S_00592cf0.h"
#include "fnv/decl/S_00c4edf0_cls.h"
#include "fnv/decl/TESObjectREFR.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TargetClass.h"
#include "fnv/decl/This_004a8050.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0049ee30__NiObjectNET.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_0049e000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00688000.h"
#include "fnv/symbols_0068b000.h"
#include "fnv/symbols_0068c000.h"
#include "fnv/symbols_0068d000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a75000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f4000.h"
#include "original_bstempeffectsimpledecal.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include <math.h>

// Original PC source filename label passed to the preload memory context;
// contents and target are verified against the engine data section.
const char kBSTempEffectSimpleDecalFileLabel[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectSimpleDecal.cpp";

// Source line of the preload context in the original PC file (0x11f).
enum
{
    kPreloadDecalDataSourceLine = 0x11f
};

NiPointer<QueuedFile> BSTempEffectSimpleDecal::ms_pPreloadDecalDataFile;

// @fnv 0x0068b3e0
void BSTempEffectSimpleDecal::QueueDecalDataFile()
{
    if ((*reinterpret_cast<::NiPointer< ::QueuedFile> *>(&::g_011d6c40)))
        return;

    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_EFFECTS_OVERHEAD, true, kBSTempEffectSimpleDecalFileLabel,
                           kPreloadDecalDataSourceLine);
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)((*reinterpret_cast<::NiPointer< ::QueuedFile> *>(&::g_011d6c40))))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(new QueuedFile(5)));
}

// Returns the cross product of this NiPoint3 with point, computing each component from the other two axes.
// @fnv 0x004b3800
NiPoint3 NiPoint3::Cross(const NiPoint3& point) const
{
    return NiPoint3(y * point.z - z * point.y, z * point.x - x * point.z, x * point.y - y * point.x);
}

struct DecalStub
{
    char pad[0x3c];
    float v;
    void FUN_0068c9f0(float c);
public:
    void FUN_00654700(float);
};
// Stores c into v and calls FUN_004bc480 with 1.
// @fnv 0x0068c9f0
void DecalStub::FUN_0068c9f0(float afValue)
{
    v = afValue;
    reinterpret_cast<::FUN_004bc480_shell *>(this)->FUN_004bc480(1);
}

struct FUN_0068c890_shell
{
    unsigned short pad[12];
    unsigned short uiFlags;
    bool HasFlag(unsigned short aFlag);
};

// @fnv 0x0068c890
bool FUN_0068c890_shell::HasFlag(unsigned short aFlag)
{
    return (uiFlags & aFlag) != 0;
}

struct FUN_0068c8b0_shell
{
    char _pad[0xe8];
    float fE8;
    void SetFieldE8(float value);
};

// @fnv 0x0068c8b0
void FUN_0068c8b0_shell::SetFieldE8(float value)
{
    fE8 = value;
}

struct NiFixedString;


// @fnv 0x0068c8d0
NiFixedString* __cdecl FUN_0068c8d0()
{
    return ::DAT_011c622c;
}

struct NiRTTI;


struct FUN_0068acb0_shell
{
    NiRTTI* GetRTTI();
};

// @fnv 0x0068acb0
NiRTTI* FUN_0068acb0_shell::GetRTTI()
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_011d6bf0));
}

namespace fnv_0068c870 {
struct FUN_0068c890_shell
{
    bool FUN_0068c870();
};

// @fnv 0x0068c870
bool FUN_0068c890_shell::FUN_0068c870()
{
    return reinterpret_cast<::FUN_0068c890_shell *>(this)->HasFlag(1);
}
}  // namespace fnv_0068c870

struct S_0068b080
{
    void FUN_0068b080();
};
struct S_0068ace0
{
    void* FUN_0068ace0(unsigned int);
};
// Returns the larger of the two arguments, comparing the float against the double and returning a double.
// @fnv 0x0068b050
double FUN_0068b050(double adValue, float afValue)
{
    double dMax;
    if (afValue < adValue)
        dMax = adValue;
    else
        dMax = afValue;
    return dMax;
}

struct Flt
{
    operator unsigned int();
};
struct DecalHolder
{
    void FUN_0068b1e0();
};
namespace fnv_0068acc0 {
struct Flt
{
    operator unsigned int() const;
};

struct FUN_0068acc0_shell
{
    unsigned char _pad[0x28];
    Flt m_flt;
    void* FUN_0068acc0();
};

// @fnv 0x0068acc0
void* FUN_0068acc0_shell::FUN_0068acc0()
{
    return (void*)m_flt.operator unsigned int();
}
}  // namespace fnv_0068acc0

struct _ref_006815c0
{
    float x, y, z;
    _ref_006815c0();
};
struct FUN_0068d660_stand
{
    int ClipPolygonByPlanes(int count, float* a, _ref_006815c0* b, _ref_006815c0* c, float* d, _ref_006815c0* e,
                            _ref_006815c0* f);
};
// Clips the input polygon through six planes at offsets 0x64..0xb4, ping-ponging between temp and output buffers, and returns the surviving vertex count.
// @fnv 0x0068d660
int FUN_0068d660_stand::ClipPolygonByPlanes(int count, float* apInVerts, _ref_006815c0* apInB, _ref_006815c0* apInC,
                                            float* apOutB, _ref_006815c0* apOutPos, _ref_006815c0* apOutC)
{
    _ref_006815c0 tempPos[9];
    _ref_006815c0 tempC[9];
    float n[9];
    int tempB = ::DecalClipping::ClipPolygonToPlane((::DecalClipping::Plane *)(void *)((char*)this + 0x64), count, (const int *)(struct ::_ref_006815c0 *)((_ref_006815c0*)apInVerts), (const ::DecalClipping::Point *)(float *)((float*)apInB), (const ::DecalClipping::Point *)(apInC), (int *)(n),
                                   (::DecalClipping::Point *)(tempPos), (::DecalClipping::Point *)(tempC));
    if (tempB)
    {
        tempB = ::DecalClipping::ClipPolygonToPlane((::DecalClipping::Plane *)(void *)((char*)this + 0x74), tempB, (const int *)(struct ::_ref_006815c0 *)((_ref_006815c0*)n), (const ::DecalClipping::Point *)(float *)((float*)tempPos), (const ::DecalClipping::Point *)(tempC), (int *)(apOutB),
                                   (::DecalClipping::Point *)(apOutPos), (::DecalClipping::Point *)(apOutC));
        if (tempB)
        {
            tempB = ::DecalClipping::ClipPolygonToPlane((::DecalClipping::Plane *)(void *)((char*)this + 0x84), tempB, (const int *)(struct ::_ref_006815c0 *)((_ref_006815c0*)apOutB), (const ::DecalClipping::Point *)(float *)((float*)apOutPos), (const ::DecalClipping::Point *)(apOutC), (int *)(n),
                                       (::DecalClipping::Point *)(tempPos), (::DecalClipping::Point *)(tempC));
            if (tempB)
            {
                tempB = ::DecalClipping::ClipPolygonToPlane((::DecalClipping::Plane *)(void *)((char*)this + 0x94), tempB, (const int *)(struct ::_ref_006815c0 *)((_ref_006815c0*)n), (const ::DecalClipping::Point *)(float *)((float*)tempPos), (const ::DecalClipping::Point *)(tempC), (int *)(apOutB),
                                           (::DecalClipping::Point *)(apOutPos), (::DecalClipping::Point *)(apOutC));
                if (tempB)
                {
                    tempB = ::DecalClipping::ClipPolygonToPlane((::DecalClipping::Plane *)(void *)((char*)this + 0xb4), tempB, (const int *)(struct ::_ref_006815c0 *)((_ref_006815c0*)apOutB), (const ::DecalClipping::Point *)(float *)((float*)apOutPos),
                                               (const ::DecalClipping::Point *)(apOutC), (int *)(n), (::DecalClipping::Point *)(tempPos), (::DecalClipping::Point *)(tempC));
                    if (tempB)
                    {
                        tempB = ::DecalClipping::ClipPolygonToPlane((::DecalClipping::Plane *)(void *)((char*)this + 0xa4), tempB, (const int *)(struct ::_ref_006815c0 *)((_ref_006815c0*)n), (const ::DecalClipping::Point *)(float *)((float*)tempPos), (const ::DecalClipping::Point *)(tempC),
                                                   (int *)(apOutB), (::DecalClipping::Point *)(apOutPos), (::DecalClipping::Point *)(apOutC));
                    }
                }
            }
        }
    }
    return tempB;
}

struct FUN_0068b4a0_shell : BSTempEffectSimpleDecal
{
    static void FUN_0068b4a0();
};

// @fnv 0x0068b4a0
void FUN_0068b4a0_shell::FUN_0068b4a0()
{
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)((*reinterpret_cast<::NiPointer< ::QueuedFile> *>(&::g_011d6c40))))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(0));
}

struct ScrapHeapBuffer
{
};

struct MemoryManager
{
    ScrapHeapBuffer* GetGeneralAllocator();
};

struct Arr
{
    unsigned int* GetAt(int index);
};

struct ArrSI
{
};

struct BSSimpleArrayActor
{
};

struct Date
{
  public:
    ~Date()
    {}
};


struct FUN_0068b220_shell
{
    void FUN_0068b220();
};

// If the flag at offset 0x2d is clear, deallocates the six pointers at 0xcc-0xf4 and nulls them, then deletes each element of the array at 0xf8 and clears it.
// @fnv 0x0068b220
void FUN_0068b220_shell::FUN_0068b220()
{
    ScrapHeapBuffer* pAllocator;

    if (!reinterpret_cast<unsigned char*>(this)[0x2d])
    {
        pAllocator = ::FUN_00401020()->GetGeneralAllocator();

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xcc))
            reinterpret_cast<::SHStub *>((pAllocator))->FUN_00aa5610(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xcc));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xd4))
            reinterpret_cast<::SHStub *>((pAllocator))->FUN_00aa5610(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xd4));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xdc))
            reinterpret_cast<::SHStub *>((pAllocator))->FUN_00aa5610(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xdc));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xe4))
            reinterpret_cast<::SHStub *>((pAllocator))->FUN_00aa5610(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xe4));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xec))
            reinterpret_cast<::SHStub *>((pAllocator))->FUN_00aa5610(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xec));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xf4))
            ::FUN_00aa10f0(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xf4));

        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xcc) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xd4) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xdc) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xe4) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xec) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xf4) = 0;
    }

    {
        int i;

        for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0xf8)))->GetName())); ++i)
        {
            delete reinterpret_cast<Date*>(
                reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0xf8)->GetAt(i)[0]);

            reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0xf8)->GetAt(i)[0] = 0;
        }
    }

    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<unsigned char*>(this) + 0xf8)))->Clear(true);
}

struct NiNode;
struct TESObjectCELL;

struct Pt3
{
    float x, y, z;
    Pt3();
    Pt3(float fx, float fy, float afDepth);
};

struct NiPlane
{
    float nx, ny, nz, c;
    NiPlane();
};

struct DecalList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DecalList();
    ~DecalList();
};

struct GlobalObject_004a4a40
{
};
extern int DAT_0119c298;
extern float DAT_0119c29c;

double FUN_0068b050(double param_1, float param_2);

struct DecalData
{
    Pt3 akStart;     // 00
    Pt3 kDirection;  // 0c
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    NiNode* pNode;  // 28
    int unk2C;
    int unk30;  // 30
    int unk34;
    float f38;
    float f3C;
    float f40;
    float f44;
    TESObjectCELL* pCell;  // 48
    float f4C;
    int unk50;
    float f54;
    float f58;
    int unk5C;
    Pt3 kColor;  // 60
    int unk6C;
    char b70;
    char b71;
    char b72;
    char b73;
    char b74;
    char b75;
    char b76;
    char b77;
    char b78;
    char b79;
};

class BSTempEffect
{
  public:
    BSTempEffect(TESObjectCELL* pCell, float m_fParticleParameter5);
    virtual ~BSTempEffect();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    char b18;
    char b19;
    char b1A;
};

class FUN_0068ad20 : public BSTempEffect
{
  public:
    FUN_0068ad20(int p1, float m_fParticleParameter5, DecalData* pData);
    virtual ~FUN_0068ad20();

    int unk1C;
    NiPointer<NiNode> spNode20;
    int unk24;
    NiPointer<NiNode> spNode28;
    char b2C;
    char b2D;
    char b2E;
    int unk30;
    Pt3 kPt34;
    Pt3 kPt40;
    Pt3 kPt4C;
    Pt3 kPt58;
    NiPlane g_kFrustumPlanes[6];
    int unkC4;
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
    DecalList kList;
    int unk108;
    NiPointer<NiNode> spNode10C;
    int unk110;
    float f114;
    float f118;
    float f11C;
    float f120;
    char b124;
    char b125;
    float f128;
    char b12C;
    char b12D;
    char b12E;
    float f130;
    Pt3 kPt134;
    char b140;
    char b141;
};

// @fnv 0x0068ad20
FUN_0068ad20::FUN_0068ad20(int p1, float m_fParticleParameter5, DecalData* pData)
    : BSTempEffect(pData->pCell, m_fParticleParameter5), kPt134(0.0f, 0.0f, 0.0f)
{
    b18 = 0;
    b2D = 0;
    b19 = 0;
    b1A = 0;
    unk30 = pData->unk30;
    if (DAT_0119c298 == -1)
    {
        DAT_0119c298 = *((int *)&(::FUN_0043d4d0((int *)&(::g_011c57fc))));
    }
    unk108 = p1;
    spNode10C = pData->pNode;
    spNode28 = 0;
    b2C = pData->b71;
    b2E = pData->b78;
    unkC4 = 0;
    unkC8 = 0;
    kPt34 = pData->akStart;
    kPt40 = pData->kDirection;
    f118 = pData->f38;
    f11C = pData->f3C;
    f120 = pData->f40;
    f114 = pData->f44;
    b124 = pData->b70;
    unk1C = 0;
    spNode20 = 0;
    DAT_0119c29c = cos((float)(pData->f58 * 0.01745329238474369));
    DAT_0119c29c = FUN_0068b050(1.1, DAT_0119c29c);
    b125 = pData->b73;
    f128 = pData->f4C;
    b12C = pData->b76;
    b12D = pData->b74;
    b12E = pData->b75;
    f130 = pData->f54;
    kPt134 = pData->kColor;
    b140 = pData->b77;
    b141 = pData->b79;
}


struct DecalEffect
{
};
struct DecalTarget
{
};
struct DecalState
{
};
struct DecalRef
{
};
struct DecalHost
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
    DecalRef decalRef;
    bool UpdateDecalFade(float alpha);
};
// @fnv 0x0068c8e0
bool DecalHost::UpdateDecalFade(float alpha)
{
    bool changed = reinterpret_cast<::FUN_006828a0_shell *>(this)->FUN_006828a0(alpha);
    DecalTarget* pDecalTarget;
    if (!changed && ((::DecalState *)(::FUN_00559450((int *)&(decalRef)))))
    {
        float elapsed = (float)(((double)(reinterpret_cast<::FUN_00621b00_shell *>(this)->FUN_00621b00())) - ((double)(reinterpret_cast<::BSFaceGenKeyframe *>(this)->GetTime())));
        float intensity;
        if (elapsed >= ::_DAT_01012060 && elapsed <= ::g_01012070)
        {
            intensity = (float)((1.0 - elapsed) / ::g_01012070);
            DecalEffect* pDecalEffect = ((::DecalEffect *)(reinterpret_cast<::FUN_00a59d30_C *>((((::DecalState *)(::FUN_00559450((int *)&(decalRef))))))->FUN_00a59d30((int)(((void *)(::FUN_004af350()))))));
            DecalEffect* pEffect = pDecalEffect;
            if (pEffect && reinterpret_cast<::TESObjectREFR *>((pEffect))->GetScale() != intensity)
                reinterpret_cast<::DecalStub *>((pEffect))->FUN_0068c9f0(intensity);
            return true;
        }
        pDecalTarget = ((::DecalTarget *)(reinterpret_cast<::FUN_009611e0_shell *>((((::DecalState *)(::FUN_00559450((int *)&(decalRef))))))->FUN_009611e0()));
        if (pDecalTarget)
            reinterpret_cast<::FUN_004ee560_shell *>((pDecalTarget))->FUN_004ee560((int)(this));
    }
    return changed;
}

class B68CA10Object
{
  public:

    B68CA10Object(unsigned int uiArg);
    virtual ~B68CA10Object();

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
    int unkB8;
    int unkBC;
    int unkC0;
};

// Allocates and constructs a B68CA10Object with the given argument, returning the new object.
// @fnv 0x0068ca10
B68CA10Object* __cdecl CreateB68CA10Object(unsigned int uiArg)
{
    return new B68CA10Object(uiArg);
}

class B68CA90Geometry
{
  public:

    B68CA90Geometry(unsigned short usVertices, void* pvPositions, void* pvNormals, void* pvColors, void* pvTexture,
                    int iTextureSets, int iDataFlags, unsigned short usTriangles, void* pvTriList);

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
};

class B68CA90Builder
{
  public:
    B68CA90Geometry* FUN_0068ca90();

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
    int unkB8;
    int unkBC;
    int unkC0;
    unsigned short m_usVertices;
    unsigned short unkC6;
    unsigned short m_usTriangles;
    unsigned short unkCA;
    int unkCC;
    void* m_pvPositions;
    int unkD4;
    void* m_pvNormals;
    int unkDC;
    void* m_pvTexture;
    int unkE4;
    void* m_pvColors;
    int unkEC;
    void* m_pvTriList;
};

// Allocates a B68CA90Geometry from the builder's vertex, normal, color, texture and triangle data and returns it.
// @fnv 0x0068ca90
B68CA90Geometry* B68CA90Builder::FUN_0068ca90()
{
    B68CA90Geometry* pkGeometry = new B68CA90Geometry(m_usVertices, m_pvPositions, m_pvNormals, m_pvColors, m_pvTexture,
                                                      1, 0, m_usTriangles, m_pvTriList);
    return pkGeometry;
}

struct DecalTextureObject
{
    ~DecalTextureObject();
};

struct FUN_0068de30_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DecalTextureObject* unk1c;
    int unk20;
    unsigned int unk24;
    bool ReleaseTextureObject();
};

// Calls FUN_00c4edf0 on unk1c with unk24; on success deletes unk1c, nulls it and returns true, otherwise returns false.
// @fnv 0x0068de30
bool FUN_0068de30_holder::ReleaseTextureObject()
{
    if (!reinterpret_cast<::S_00c4edf0_cls *>((unk1c))->FUN_00c4edf0((std::intptr_t)(&unk24), 0))
    {
        return false;
    }
    else
    {
        delete unk1c;
        unk1c = 0;
        return true;
    }
}

struct TESObjectCELL;
struct DecalNode;

void __cdecl FUN_00b5b0e0(void* pObject);

struct DecalOwner
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void DetachDecal(DecalNode* pNode);
};

struct DecalNode
{
};

struct DecalPointList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~DecalPointList();
};

extern int DAT_011c57ec;

class FUN_0068b080 : public BSTempEffect
{
  public:
    virtual ~FUN_0068b080();

    int unk1C;
    NiPointer<DecalNode> spNode20;
    int unk24;
    NiPointer<DecalNode> spNode28;
    bool b2C;
    bool b2D;
    char b2E;
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
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
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
    DecalPointList kList;
    int unk108;
    NiPointer<DecalNode> spNode10C;
};
// Calls FUN_0068b080 on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x0068ace0
void* S_0068ace0::FUN_0068ace0(unsigned int flags)
{
    reinterpret_cast<::FUN_0068b080 *>((((S_0068b080*)this)))->FUN_0068b080::~FUN_0068b080();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x144);
    return this;
}

// Releases the decal nodes, detaches the node from its owner, calls FUN_0068b220, and decrements DAT_011c57ec when b2D is set.
// @fnv 0x0068b080
FUN_0068b080::~FUN_0068b080()
{
    spNode10C = 0;
    unk108 = 0;
    DecalNode* pNode;
    if (!b2C && (DecalNode*)spNode28)
    {
        pNode = spNode28;
        FUN_00b5b0e0(pNode);
        if (((::DecalOwner *)(reinterpret_cast<::FUN_009611e0_shell *>((((DecalNode*)spNode28)))->FUN_009611e0())))
        {
            ((::DecalOwner *)(reinterpret_cast<::FUN_009611e0_shell *>((((DecalNode*)spNode28)))->FUN_009611e0()))->DetachDecal(spNode28);
        }
        spNode28 = 0;
    }
    reinterpret_cast<::FUN_0068b220_shell *>(this)->FUN_0068b220();
    if (b2D)
    {
        DAT_011c57ec--;
    }
}

struct DecalSetup;
struct Color4
{
    float r, g, b, a;
    Color4(float, float, float, float);
};
struct UpdateInfo
{
    float time;
    bool a, b;
    int unk08;
    UpdateInfo(float, bool, bool);
};
struct Graph;
template <class T> class NiPointer;
struct Graph
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void texture(int, NiPointer<Graph>*);
    virtual void slot094();
    virtual Graph* geometry(int);
    virtual void slot09C();
    virtual void slot0A0();
    virtual void slot0A4();
    virtual void slot0A8();
    virtual void slot0AC();
    virtual void slot0B0();
    virtual void slot0B4();
    virtual void slot0B8();
    virtual void slot0BC();
    virtual void slot0C0();
    virtual void slot0C4();
    virtual void slot0C8();
    virtual void slot0CC();
    virtual void slot0D0();
    virtual void slot0D4();
    virtual void slot0D8();
    virtual void slot0DC();
    virtual void slot0E0();
    virtual void slot0E4();
    virtual void slot0E8();
    virtual void slot0EC();
    virtual void slot0F0();
    virtual int hasFlag(int, int);
    virtual void slot0F8();
    virtual void slot0FC();
    virtual void slot100();
    virtual void attach(DecalSetup*, int);
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
    Graph* list;
    Graph* FUN_00458b50();
    unsigned int FUN_0043b480();
    float scale();
};
struct Material
{
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
    Material();
};
struct Alpha
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    Alpha();
    void flags(unsigned short);
};
struct Stencil
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    Stencil();
};
struct Shader
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09C();
    virtual void slot0A0();
    virtual void slot0A4();
    virtual void slot0A8();
    virtual void slot0AC();
    virtual void slot0B0();
    virtual void slot0B4();
    virtual void slot0B8();
    virtual void slot0BC();
    virtual void slot0C0();
    virtual void slot0C4();
    virtual void slot0C8();
    virtual void slot0CC();
    virtual void slot0D0();
    virtual void slot0D4();
    virtual void slot0D8();
    virtual void slot0DC();
    virtual void slot0E0();
    virtual void slot0E4();
    virtual void slot0E8();
    virtual void slot0EC();
    virtual void slot0F0();
    virtual int hasFlag(int, int);
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
    Shader();
    void flag(int, bool);
    void intensity(float);
};
struct Lighting
{
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
    Lighting();
    void flag(int, bool);
};
struct Attachment
{
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
    Attachment(Graph*, int);
};
struct TextureAccessor
{
};
struct TextureOwner
{
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
    Graph texturePart;
};
struct EffectList
{
};
struct Manager
{
};
struct Setting
{
    unsigned char* Bool();
};
extern int DAT_0119c298;
struct NiFixedString;
NiFixedString* __cdecl FUN_0068c8d0();
struct SceneOps
{
};
struct DecalSetup
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void slot090();
    virtual void slot094();
    virtual Graph* geometry(int);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    bool b018;
    bool b019;
    bool b01A;
    bool b01B;
    int unk01C;
    int unk020;
    int unk024;
    NiPointer<Graph> p028;
    bool b02C;
    bool b02D;
    bool b02E;
    bool b02F;
    TextureOwner* textures;
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
    Graph* attachment;
    NiPointer<Graph> p10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    bool b124;
    bool b125;
    bool b126;
    bool b127;
    float f128;
    unsigned char b12C;
    bool b12D;
    bool b12E;
    bool b12F;
    float f130;
    int unk134;
    int unk138;
    int unk13C;
    bool b140;
    bool b141;
    bool b142;
    bool b143;
    bool Initialize();
};
// @fnv 0x0068be90
bool DecalSetup::Initialize()
{
    bool disabled = false;
    if ((Graph*)p028)
    {
        Material* l = new Material;
        reinterpret_cast<::DecalStub *>((l))->FUN_00654700(f130);
        reinterpret_cast<::FUN_00439410_cls *>((((Graph*)p028)))->FUN_00439410((::ArgObject *)(l));
        Alpha* e = new Alpha;
        reinterpret_cast<::FUN_0049ed90_shell *>((e))->FUN_0049ed90(b12E);
        reinterpret_cast<::Flag512Receiver *>((e))->SetFlag512(b12D);
        reinterpret_cast<::NiObjectNET *>((e))->SetFlags(4);
        reinterpret_cast<::FUN_0094db80_shell *>((e))->FUN_0094db80(128);
        reinterpret_cast<::FUN_00439410_cls *>((((Graph*)p028)))->FUN_00439410((::ArgObject *)(e));
        if (b141)
        {
            Stencil* stencil = new Stencil;
            reinterpret_cast<::fnv_0049ee30::NiObjectNET *>((stencil))->FUN_0049ee30(3);
            reinterpret_cast<::FUN_00439410_cls *>((((Graph*)p028)))->FUN_00439410((::ArgObject *)(stencil));
        }
        Shader* c = 0;
        c = new Shader;
        reinterpret_cast<::LowProcess *>((c))->SetPackageObjectType(29);
        c->flag(5, true);
        reinterpret_cast<::FUN_00b66ad0_cls *>((c))->FUN_00b66ad0(0, (::FnvTarget *)(void *)(reinterpret_cast<::S_00592cf0 *>((((TextureAccessor*)textures)))->FUN_00592cf0()));
        if (c->hasFlag(1, 0) && !disabled)
        {
            if (c->hasFlag(3, 0))
            {
                c->flag(11, true);
                if (b125)
                {
                    c->flag(28, true);
                    reinterpret_cast<::FUN_009bd580_class *>((c))->FUN_009bd580(f128);
                    reinterpret_cast<::FUN_0068c8b0_shell *>((c))->SetFieldE8((float)(unsigned char)b12C);
                }
            }
            c->flag(27, true);
            Graph* eb = (Graph*)p10C;
            Graph* cf = ((::Graph *)(reinterpret_cast<::FUN_0050d100_shell *>((eb))->FUN_0050d100()));
            bool q = reinterpret_cast<::fnv_0068c870::FUN_0068c890_shell *>((cf->FUN_00458b50()))->FUN_0068c870();
            if (q)
                c->flag(53, true);
            reinterpret_cast<::FUN_00439410_cls *>((((Graph*)p028)))->FUN_00439410((::ArgObject *)(c));
            ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::Graph *)((Graph*)p028), 0, 0);
        }
        else
        {
            Lighting* cf = new Lighting;
            if (!disabled && textures && !((*reinterpret_cast<int *>(&::DAT_011c57f4)) & 32))
            {
                NiPointer<Graph> texture(0);
                textures->texturePart.texture(0, &texture);
                reinterpret_cast<::FUN_00438230_Class *>((cf))->FUN_00438230((::NiNode *)(::Graph *)((Graph*)texture));
            }
            cf->flag(27, true);
            Graph* f = (Graph*)p10C;
            Graph* eb = ((::Graph *)(reinterpret_cast<::FUN_0050d100_shell *>((f))->FUN_0050d100()));
            bool q = reinterpret_cast<::fnv_0068c870::FUN_0068c890_shell *>((eb->FUN_00458b50()))->FUN_0068c870();
            if (q)
                cf->flag(53, true);
            reinterpret_cast<::FUN_00439410_cls *>((((Graph*)p028)))->FUN_00439410((::ArgObject *)(cf));
            if ((*reinterpret_cast<int *>(&::DAT_011c57f4)) & 32)
            {
                Graph* geom = (Graph*)p028;
                Color4* colors = ((::Color4 *)(reinterpret_cast<::This_004a8050 *>((geom))->GetNextProc()));
                for (int index = 0; index < reinterpret_cast<::FUN_00456650_shell *>((geom))->FUN_00456650(); index++)
                    colors[index] = Color4(1, 1, 0, 1);
            }
            ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::Graph *)((Graph*)p028), 0, 0);
        }
        if (b02C)
            ::AssignFixedString((char *)(((Graph*)p028)), (int)(FUN_0068c8d0()), {});
        else
            ::AssignFixedString((char *)(((Graph*)p028)), (int)(((void *)(::FUN_00688460()))), {});
        ::FUN_0062bc10((::FUN_0062bc10_obj *)(::Graph *)((Graph*)p028));
        ::ProcessPropertyTree((::PropHelper *)(::Graph *)((Graph*)p028), 5);
        if (!b02C)
        {
            if (b02E)
                reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::Manager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(::DecalSetup *)(this));
            else
            {
                reinterpret_cast<::TargetClass *>(&((*reinterpret_cast<::EffectList *>(&::g_011d6a30))))->FUN_0052a9b0((const ::NiPointer< ::NiNode> &)((const ::NiPointer< ::Graph> &)((Graph*)this)));
                (*reinterpret_cast<int *>(&::DAT_011d6a20))++;
                if ((*reinterpret_cast<int *>(&::DAT_011d6a20)) > DAT_0119c298)
                {
                    reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::Manager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(::DecalSetup *)((DecalSetup*)(Graph*)(*(::NiPointer< ::Graph> *)((void *)&((*reinterpret_cast<::EffectList *>(&::g_011d6a30)))))));
                    reinterpret_cast<::DecalListManager *>(&((*reinterpret_cast<::EffectList *>(&::g_011d6a30))))->PopHead();
                    (*reinterpret_cast<int *>(&::DAT_011d6a20))--;
                    if (*(*reinterpret_cast<::Setting *>(&::g_011c5904)).Bool())
                        ::FUN_005b5e40();
                }
            }
        }
        Graph* k = ((::Graph *)(reinterpret_cast<::FUN_009611e0_shell *>((((Graph*)p10C)))->FUN_009611e0()));
        Graph* ba = 0;
        bool b = false;
        if (k)
        {
            for (unsigned int childIndex = 0; childIndex < k->FUN_0043b480(); childIndex++)
            {
                Graph* child = ((::Graph *)(reinterpret_cast<::NiNode *>((k))->GetAt(childIndex)));
                if (child && ::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011c7d34))), (const ::fnv_0045bad0::NiObject *)(child)))
                {
                    b = true;
                    ba = child;
                    break;
                }
            }
        }
        else
        {
            b018 = true;
            return false;
        }
        if (!b)
            attachment = (Graph*)new Attachment(((::Graph *)(reinterpret_cast<::FUN_009611e0_shell *>((((Graph*)p10C)))->FUN_009611e0())), 0);
        else
            attachment = ba;
        attachment->attach(this, 1);
        reinterpret_cast<::FUN_00440460_S *>((((Graph*)p028)))->FUN_00440460((const ::V3 *)(void *)(((void *)&(reinterpret_cast<::NiAVObject *>((((Graph*)p10C)))->FUN_0043c490()))));
        reinterpret_cast<::FUN_0043fa80_s *>((((Graph*)p028)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(((Graph*)p10C))))));
        reinterpret_cast<::FUN_00440490_shell *>((((Graph*)p028)))->FUN_00440490(reinterpret_cast<::FUN_009cdae0_shell *>((((Graph*)p10C)))->GetFloatAt64());
        reinterpret_cast<::FUN_00a5a040_Class *>((((Graph*)p028)))->FUN_00a5a040();
        UpdateInfo j(::fnv_00563f30::DAT_011c3c08, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((Graph*)p028)))->FUN_00a59c60((std::intptr_t)&(j));
        reinterpret_cast<::S00b5d9f0_Owner *>((((SceneOps*)((::Graph *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(::Graph *)(geometry(0)), {});
        reinterpret_cast<::fnv_00631540::TargetClass *>((attachment->list))->FUN_00631540((const ::NiPointer< ::NiNode> &)((const ::NiPointer< ::Graph> &)((Graph*)this)));
        reinterpret_cast<::FUN_0068b220_shell *>(this)->FUN_0068b220();
        b019 = false;
        b02D = true;
        b018 = true;
        return true;
    }
    else
    {
        b018 = true;
        return false;
    }
}

struct DecalPoint
{
    float x, y, z;
};
struct DecalColor
{
    float r, g, b, a;
    DecalColor(float, float, float, float);
};
struct DecalPointRecord
{
    DecalPoint position;
    short index;
    short flags;
    DecalPointRecord();
};
struct DecalVertices
{
    unsigned count;
    DecalPointRecord** data;
    unsigned capacity;
    unsigned growth;
    DecalPointRecord*& FUN_00877a30(unsigned);
};
struct DecalGeometry
{
    unsigned short FUN_004a1ff0();
};
struct DecalGeometryRef
{
    DecalGeometry* object;
};
struct DecalHeap
{
};
struct DecalMemoryManager
{
    DecalHeap* FUN_00aa42e0();
};

extern float DAT_0119c29c;
struct DecalBuilder
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    DecalPoint direction;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    int vertexCount;
    int triangleCount;
    DecalPoint* positions;
    unsigned unkD0;
    DecalPoint* normals;
    unsigned unkD8;
    void* texcoords;
    unsigned unkE0;
    DecalColor* colors;
    unsigned unkE8;
    unsigned short* triangles;
    unsigned unkF0;
    short* remap;
    DecalVertices vertices;
    unsigned unk108;
    DecalGeometryRef geometry;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    float red, green, blue;
    bool AddDecalGeometry(int, int*, DecalPoint*, DecalPoint*);
};
// @fnv 0x0068cb60
bool DecalBuilder::AddDecalGeometry(int count, int* paiIndices, DecalPoint* points, DecalPoint* vectors)
{
    long used2;
    used2 = vertexCount;
    if (used2 + count >= 512)
        return false;
    if (positions == 0)
    {
        DecalHeap* vertex_;
        vertex_ = reinterpret_cast<DecalMemoryManager*>(::FUN_00401020())->FUN_00aa42e0();
        positions = (DecalPoint*)reinterpret_cast<::FUN_00aa54a0_s *>((vertex_))->FUN_00aa54a0(6144, DAT_010a2720);
        normals = (DecalPoint*)reinterpret_cast<::FUN_00aa54a0_s *>((vertex_))->FUN_00aa54a0(6144, DAT_010a2720);
        texcoords = reinterpret_cast<::FUN_00aa54a0_s *>((vertex_))->FUN_00aa54a0(4096, DAT_010a2720);
        colors = (DecalColor*)reinterpret_cast<::FUN_00aa54a0_s *>((vertex_))->FUN_00aa54a0(8192, DAT_010a2720);
        triangles = (unsigned short*)reinterpret_cast<::FUN_00aa54a0_s *>((vertex_))->FUN_00aa54a0(6144, DAT_010a2720);
        DecalGeometry* aMesh = ((::DecalGeometry *)(::FUN_00559450((int *)&(geometry))));
        int _numTriangles = aMesh->FUN_004a1ff0();
        remap = (short*)FUN_00aa1070(_numTriangles * 3 * 2);
        ::FUN_00403d30(remap, -1, _numTriangles * 3 * 2);
    }
    float scale = 1.0f / (1.0f - DAT_0119c29c);
    for (int i = 0; i < count; ++i)
    {
        unsigned int mapped8 = paiIndices[i];
        if (mapped8 != -1)
        {
            if (remap[mapped8] != -1)
            {
                paiIndices[i] = remap[mapped8];
            }
            else
            {
                positions[used2] = points[i];
                remap[mapped8] = (short)used2;
                normals[used2] = vectors[i];
                float a;
                DecalPoint normal = normals[used2];
                a = (((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(direction))->DotProduct((void *)&(normal)))) / ((double)(reinterpret_cast<::NiPoint3 *>(&(normal))->ComputeMagnitude())) - DAT_0119c29c) * scale;
                colors[used2] = DecalColor(red, green, blue, a > 0.0 ? a : 0.0f);
                paiIndices[i] = used2;
                used2++;
            }
        }
        else
        {
            for (unsigned jA = 0; jA < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(vertices))->GetName())); ++jA)
            {
                if (::AreVectorsEqual((const float *)(const ::DecalPoint *)(&points[i]), (const float *)(vertices.FUN_00877a30(jA)), 0.01f))
                {
                    mapped8 = vertices.FUN_00877a30(jA)->index;
                    break;
                }
            }
            if (mapped8 != -1)
            {
                paiIndices[i] = mapped8;
            }
            else
            {
                positions[used2] = points[i];
                DecalPointRecord* s = new DecalPointRecord;
                s->position = positions[used2];
                s->index = (short)used2;
                reinterpret_cast<::FUN_00438690 *>(&(vertices))->FUN_007cb2e0((unsigned int *)&(s));
                normals[used2] = vectors[i];
                DecalPoint normal = normals[used2];
                float a = (((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(direction))->DotProduct((void *)&(normal)))) / ((double)(reinterpret_cast<::NiPoint3 *>(&(normal))->ComputeMagnitude())) - DAT_0119c29c) * scale;
                colors[used2] = DecalColor(red, green, blue, a > 0.0 ? a : 0.0f);
                paiIndices[i] = used2;
                used2++;
            }
        }
    }
    unsigned short* output;
    output = &triangles[triangleCount * 3];
    triangleCount += count - 2;
    int outIndex8 = 0;
    for (int i = 2; i < count; ++i)
    {
        output[outIndex8] = (unsigned short)paiIndices[0];
        outIndex8 += 1;
        output[outIndex8] = (unsigned short)paiIndices[i - 1];
        ++outIndex8;
        output[outIndex8] = (unsigned short)paiIndices[i];
        outIndex8 += 1;
    }
    vertexCount = used2;
    return true;
}

struct Point
{
    float x, y, z;
    Point();
    Point operator-(const Point&) const;
    Point Cross(const Point&) const;
};
struct UnsignedShortBuffer
{
};
struct FixedName
{
    operator const char*() const;
};
struct Geometry
{
    unsigned short FUN_004a1ff0();
};
extern float DAT_0119c29c;
struct FUN_0068d230_Class
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54;
    Point direction;
    void ProcessDecalTriangles(Geometry*);
};
// Iterates triangle strips from the geometry, skips degenerate triangles, and clips those whose face normal faces along direction past a threshold.
// @fnv 0x0068d230
void FUN_0068d230_Class::ProcessDecalTriangles(Geometry* input)
{
    Geometry* data = input;
    Point* normals = ((::Point *)(reinterpret_cast<::FUN_0049ec60 *>((data))->GetNext()));
    Point* geometry = ((::Point *)(reinterpret_cast<::FUN_004a8030_shell *>((data))->FUN_004a8030()));
    UnsignedShortBuffer* vertices = ((::UnsignedShortBuffer *)(::fnv_005495f0::FUN_005495f0((const char *)(data))));
    if (normals && !geometry)
    {
        ::FUN_005b5e40();
        return;
    }
    if (!vertices)
        return;
    {
        Point third[9];
        Point strip[9];
        unsigned short old;
        UnsignedShortBuffer* count = vertices;
        int first = data->FUN_004a1ff0();
        unsigned short* positions = ((unsigned short *)(::FUN_00a75f10((char *)(count))));
        unsigned second[9];
        unsigned short indices, bridge;
        for (int i = 0; i < first; i++)
        {
            if (positions[i] == positions[i + 1] || positions[i] == positions[i + 2] ||
                positions[i + 1] == positions[i + 2])
                continue;
            if (i % 2 == 0)
            {
                old = positions[i];
                indices = positions[i + 1];
                bridge = positions[i + 2];
            }
            else
            {
                old = positions[i + 1];
                indices = positions[i];
                bridge = positions[i + 2];
            }
            const Point& edge3 = normals[old];
            const Point& edge1 = normals[indices];
            const Point& a = normals[bridge];
            Point edge2 = edge1 - edge3;
            Point b = a - edge3;
            Point c = edge2.Cross(b);
            if (reinterpret_cast<::FUN_004b6190_shell *>((void *)&(direction))->DotProduct((void *)&(c)) > reinterpret_cast<::NiPoint3 *>((void *)&(c))->ComputeMagnitude() * DAT_0119c29c)
            {
                second[0] = old;
                second[1] = indices;
                second[2] = bridge;
                third[0] = edge3;
                third[1] = edge1;
                third[2] = a;
                strip[0] = geometry[old];
                strip[1] = geometry[indices];
                strip[2] = geometry[bridge];
                int clipped = reinterpret_cast<::FUN_0068d660_stand *>(this)->ClipPolygonByPlanes(3, (float *)(second), (struct ::_ref_006815c0 *)(third), (struct ::_ref_006815c0 *)(strip), (float *)(second), (struct ::_ref_006815c0 *)(third), (struct ::_ref_006815c0 *)(strip));
                if (clipped)
                {
                    if (!reinterpret_cast<::DecalBuilder *>(this)->AddDecalGeometry(clipped, (int *)(second), (::DecalPoint *)(third), (::DecalPoint *)(strip)))
                        break;
                }
            }
        }
    }
}

namespace DecalClipping {
struct Point
{
  private:
    float x, y, z;

  public:
    Point ApplyScaled(float);
};
struct Plane
{
};
extern const double DAT_01069ff0;
extern const char DAT_01069f88[];
// Clips a polygon against a plane, emitting intersection vertices where edges cross it and dropping vertices outside, and returns the output vertex count.
// @fnv 0x0068d820
int ClipPolygonToPlane(Plane* plane, int count, const int* indices, const Point* positions, const Point* attributes,
                       int* outIndices, Point* outPositions, Point* outAttributes)
{
    bool outside4[10];
    int rejected = 0;
    for (int i = 0; i < count; ++i)
    {
        if (reinterpret_cast<::NiCamera *>((plane))->ClassifyPoint((const ::NiPoint3 *)&(positions[i])) == 2)
        {
            outside4[i] = true;
            ++rejected;
        }
        else
            outside4[i] = false;
    }
    if (rejected == count)
        return 0;
    int output = 0;
    for (int current = 0; current < count; ++current)
    {
        int previous = current ? current - 1 : count - 1;
        if (outside4[current])
        {
            if (!outside4[previous])
            {
                Point start4 = positions[previous];
                Point _end = positions[current];
                Point edgeTmp = (*(::DecalClipping::Point *)(reinterpret_cast<::FUN_00439ef0_class *>(&(start4))->FUN_00439ef0((::NiPoint3 *)&(_end), *(const ::NiPoint3 *)nullptr)));
                Point normal = (*(const ::DecalClipping::Point *)((void *)(plane)));
                float fraction = (((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(normal))->DotProduct((void *)&(start4)))) + -((double)(reinterpret_cast<::Twin_0084d030 *>((plane))->GetStoredFloatValue()))) / ((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(normal))->DotProduct((void *)&(edgeTmp))));
                if (fraction > ::g_01012070 && fraction <= DAT_01069ff0)
                    fraction = 1.0f;
                if (fraction < ::_DAT_01012060)
                {
                    ::FUN_005b5e40();
                    fraction = 0.0f;
                }
                else if (fraction > ::g_01012070)
                {
                    ::FUN_005b5e40();
                    fraction = 1.0f;
                }
                outIndices[output] = -1;
                outPositions[output] = (*(::DecalClipping::Point *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::DecalClipping::Point &)(start4.ApplyScaled(1.0f - fraction)))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalClipping::Point &)(_end.ApplyScaled(fraction)), {})));
                Point _startAttr = attributes[previous];
                Point endAttr = attributes[current];
                outAttributes[output] =
                    (*(::DecalClipping::Point *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::DecalClipping::Point &)(endAttr.ApplyScaled(1.0f - fraction)))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalClipping::Point &)(_startAttr.ApplyScaled(fraction)), {})));
                ++output;
            }
        }
        else
        {
            if (outside4[previous])
            {
                Point start_ = positions[current];
                Point end2 = positions[previous];
                Point edge_ = (*(::DecalClipping::Point *)(reinterpret_cast<::FUN_00439ef0_class *>(&(start_))->FUN_00439ef0((::NiPoint3 *)&(end2), *(const ::NiPoint3 *)nullptr)));
                Point normal3 = (*(const ::DecalClipping::Point *)((void *)(plane)));
                float fraction2 = (((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(normal3))->DotProduct((void *)&(start_)))) + -((double)(reinterpret_cast<::Twin_0084d030 *>((plane))->GetStoredFloatValue()))) / ((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(normal3))->DotProduct((void *)&(edge_))));
                if (fraction2 < ::_DAT_01012060)
                {
                    ::FUN_005b5e40();
                    fraction2 = 0.0f;
                }
                else if (fraction2 > ::g_01012070)
                {
                    ::FUN_005b5e40();
                    fraction2 = 1.0f;
                }
                outIndices[output] = -1;
                outPositions[output] = (*(::DecalClipping::Point *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::DecalClipping::Point &)(start_.ApplyScaled(1.0f - fraction2)))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalClipping::Point &)(end2.ApplyScaled(fraction2)), {})));
                Point startAttr6 = attributes[current];
                Point endAttr4 = attributes[previous];
                outAttributes[output] =
                    (*(::DecalClipping::Point *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::DecalClipping::Point &)(endAttr4.ApplyScaled(1.0f - fraction2)))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalClipping::Point &)(startAttr6.ApplyScaled(fraction2)), {})));
                ++output;
            }
            outIndices[output] = indices[current];
            outPositions[output] = positions[current];
            outAttributes[output] = attributes[current];
            ++output;
        }
    }
    return output;
}
}

extern char str_01069efc;

struct P3
{
    float x;
    float y;
    float z;
    P3 ApplyScaled(float);
};
struct M3
{
    float m[9];
    P3 FUN_004b4500(P3*);
};
struct Plane
{
    float x;
    float y;
    float z;
    float w;
    Plane* FUN_00a69970(P3*, float);
};
struct V2
{
    float x;
    float y;
    V2* FUN_00452dc0(float, float);
};
struct H36
{
    float m[9];
    M3 FUN_0043f8d0(M3*);
};
struct SubOut
{
    float x;
    float y;
    float z;
};
struct PtSet
{
    P3* FUN_00416870(float, float, float);
};
struct Param
{
};
struct Sub28
{
    int dummy;
    void FUN_0066b0d0(int);
};
struct StrObj
{
    const char* FUN_0043b1b0();
};
struct MidObj
{
};
struct Sing
{
    unsigned char b0;
    Sing* FUN_00408d60();
};
struct Node8
{
    void* p;
    V2* secondary;
};

void __cdecl FUN_00c4b600(M3*, P3);

struct FUN_00416870 : P3
{
    FUN_00416870(float, float, float);
};
struct FUN_00a69970 : Plane
{
    FUN_00a69970(const P3&, float);
};
struct FUN_00452dc0 : V2
{
    FUN_00452dc0(float, float);
};

struct Host
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    unsigned char m_18;
    unsigned char m_19;
    unsigned char u1a;
    unsigned char u1b;
    int u1c;
    int u20;
    int u24;
    Sub28 m_28;
    unsigned char flag2c;
    unsigned char u2d;
    unsigned char u2e;
    unsigned char u2f;
    int u30;
    P3 m_34;
    P3 m_40;
    P3 m_4c;
    P3 m_58;
    Plane m_64;
    Plane m_74;
    Plane m_84;
    Plane m_94;
    Plane m_a4;
    Plane m_b4;
    int m_c4;
    int m_c8;
    P3* m_cc;
    Node8 m_kNodeCollection[5];
    unsigned int unknownf8;
    int uf8;
    int ufc;
    int u100;
    int u104;
    ::Param* m_10c;
    int u110;
    float f114;
    float f118;
    float f11c;
    float f120;
    unsigned char mode124;
    unsigned char u125;
    unsigned char u126;
    unsigned char u127;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    unsigned char flag140;
    bool FUN_0068b4c0(Param*);
};
// @fnv 0x0068b1e0
void DecalHolder::FUN_0068b1e0()
{
    if (!reinterpret_cast<::Host *>(this)->FUN_0068b4c0(reinterpret_cast<::Host *>(this)->m_10c))
        return;
    reinterpret_cast<::FUN_00682810_shell *>(this)->FUN_00682810();
}

// @fnv 0x0068b4c0
bool Host::FUN_0068b4c0(Param* apParam)
{
    float vValue40;
    int modeValue10;
    float uValue22;
    P3 diffValue4;
    int iValue13;
    int tValue0;
    float inv11cValue22;
    float inv118Value2;
    M3 mecValue16;
    float dotValue29;
    P3 gValue23;
    M3 m1Value12;
    P3 fValue3;
    M3 m2Value40;
    H36 hValue8;
    P3 eValue2;
    P3 d40Value6;
    P3 c34Value43;
    P3 aValue1;
    P3 bValue0;
    bool resultValue23;


    if (apParam && ::FUN_0043b300((const ::NiRTTI *)(const char *)((const char*)&(*reinterpret_cast<int *>(&::g_011f4a20))), (::NiAVObject *)(apParam)))
    {

        c34Value43 = m_34;

        d40Value6 = m_40;



        if (flag140)
            m1Value12 = *((::M3 *)(::FUN_006a9540((char *)(apParam))));
        else
            m1Value12 = *((::M3 *)(::FUN_00461130((int)(apParam))));

        reinterpret_cast<::ThreeByThreeMatrix *>(&(m1Value12))->FUN_004b45b0((::ThreeByThreeMatrix *)(::M3 *)(&mecValue16));
        fValue3 = mecValue16.FUN_004b4500(&d40Value6);

        if (flag140)
        {
            eValue2 = c34Value43;
        }
        else
        {
            eValue2 = (*(::P3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(c34Value43))->FUN_00439ef0((::NiPoint3 *)(::P3 *)(((::P3 *)(::FUN_0045bb80((int)(apParam))))), *(const ::NiPoint3 *)nullptr)));
            eValue2 = eValue2.ApplyScaled(1.0f / reinterpret_cast<::FUN_008d01e0_Class *>((apParam))->FUN_008d01e0());
        }
        ::FUN_00a582f0((const float *)(::M3 *)(&mecValue16), (const float *)(const char *)((const char*)&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO))), 1, (const ::Point314 *)(::P3 *)(&eValue2), (::Point314 *)(::P3 *)(&gValue23));
        f118 *= 1.0f / reinterpret_cast<::FUN_008d01e0_Class *>((apParam))->FUN_008d01e0();
        f11c *= 1.0f / reinterpret_cast<::FUN_008d01e0_Class *>((apParam))->FUN_008d01e0();
        f120 *= 1.0f / reinterpret_cast<::FUN_008d01e0_Class *>((apParam))->FUN_008d01e0();
        m_4c = gValue23;
        m_58 = fValue3;

        FUN_00c4b600(&m2Value40, fValue3);

        reinterpret_cast<::FUN_004a0c90_shell *>(&(hValue8))->FUN_004a0c90(f114);
        m2Value40 = hValue8.FUN_0043f8d0(&m2Value40);
        reinterpret_cast<::ThreeByThreeMatrix *>(&(m2Value40))->GetRow(0, (*(::NiPoint3 *)(&aValue1)));
        reinterpret_cast<::ThreeByThreeMatrix *>(&(m2Value40))->GetRow(1, (*(::NiPoint3 *)(&bValue0)));

        dotValue29 = reinterpret_cast<::FUN_004b6190_shell *>(&(m_4c))->DotProduct(&aValue1);
        {
            m_64 = FUN_00a69970(FUN_00416870(aValue1.x, aValue1.y, aValue1.z), -(f118 * 0.5 - dotValue29));
        }
        {
            m_74 = FUN_00a69970(FUN_00416870(-aValue1.x, -aValue1.y, -aValue1.z), -(f118 * 0.5 + dotValue29));
        }
        dotValue29 = reinterpret_cast<::FUN_004b6190_shell *>(&(m_4c))->DotProduct(&bValue0);
        {
            m_84 = FUN_00a69970(FUN_00416870(bValue0.x, bValue0.y, bValue0.z), -(f11c * 0.5 - dotValue29));
        }
        {
            m_94 = FUN_00a69970(FUN_00416870(-bValue0.x, -bValue0.y, -bValue0.z), -(f11c * 0.5 + dotValue29));
        }
        dotValue29 = reinterpret_cast<::FUN_004b6190_shell *>(&(m_4c))->DotProduct(&m_58);
        {
            m_a4 = FUN_00a69970(FUN_00416870(-m_58.x, -m_58.y, -m_58.z), -(f120 + dotValue29));
        }
        {
            m_b4 = FUN_00a69970(FUN_00416870(m_58.x, m_58.y, m_58.z), -(f120 - dotValue29));
        }
        reinterpret_cast<::FUN_0068d230_Class *>(this)->ProcessDecalTriangles((::Geometry *)(apParam));
        if (m_c8 == 0)
        {
            m_18 = 1;
            if ((*reinterpret_cast<::Sing *>(&::g_011c5904)).FUN_00408d60()->b0)
            {
                ::FUN_005b5e40();
            }
            resultValue23 = false;
        }
        else
        {
            inv118Value2 = 1.0f / f118;
            inv11cValue22 = 1.0f / f11c;

            for (iValue13 = 0; iValue13 < m_c4; iValue13++)
            {

                reinterpret_cast<::FUN_00439ef0_class *>((((SubOut*)&m_cc[iValue13])))->FUN_00439ef0((::NiPoint3 *)(::P3 *)(&diffValue4), (*(const ::NiPoint3 *)(&m_4c)));
                uValue22 = reinterpret_cast<::FUN_004b6190_shell *>(&(diffValue4))->DotProduct(&aValue1) * inv118Value2 + 0.5;
                vValue40 = reinterpret_cast<::FUN_004b6190_shell *>(&(diffValue4))->DotProduct(&bValue0) * inv11cValue22 + 0.5;
                modeValue10 = mode124;
                uValue22 = uValue22 / 2.0;
                vValue40 = vValue40 / 2.0;
                switch (modeValue10)
                {
                case 0:
                    break;
                case 1:
                    uValue22 = uValue22 + 0.5;
                    break;
                case 2:
                    vValue40 = vValue40 + 0.5;
                    break;
                case 3:
                    uValue22 = uValue22 + 0.5;
                    vValue40 = vValue40 + 0.5;
                    break;
                default:
                    uValue22 = uValue22 * 2.0;
                    vValue40 = vValue40 * 2.0;
                    break;
                }
                if (flag2c)
                {
                    m_kNodeCollection[1].secondary[iValue13] = FUN_00452dc0(1.0f - uValue22, vValue40);
                }
                else
                {
                    m_kNodeCollection[1].secondary[iValue13] = FUN_00452dc0(uValue22, vValue40);
                }
            }
            reinterpret_cast<::ResizeMesh *>(this)->ResizeMeshBuffers();
            tValue0 = ((int)(reinterpret_cast<::B68CA90Builder *>(this)->FUN_0068ca90()));
            m_28.FUN_0066b0d0(((int)(::CreateB68CA10Object(tValue0))));
            if (((void *)(::FUN_00559450((int *)&(m_28)))))
            {
                m_kNodeCollection[0].p = 0;
                m_kNodeCollection[1].p = 0;
                m_kNodeCollection[2].p = 0;
                m_kNodeCollection[3].p = 0;
                m_kNodeCollection[4].p = 0;
            }
            m_19 = 1;
            resultValue23 = true;
        }
    }
    else
    {
        m_18 = 1;
        resultValue23 = false;
    }
    return resultValue23;
}

struct xPoint3
{
    float x, y, z;
};
struct xColorA
{
    float r, g, b, a;
};
struct xMat
{
    xMat();
    xPoint3 operator*(const xPoint3&) const;
    xMat operator*(const xMat&) const;
    float m[9];
};
xMat xFromEuler(xPoint3);
struct xFixedStr
{
    xFixedStr(const char*);
    ~xFixedStr();
    const char* m_p;
};
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB;
    int m_iThirdValue;
};
struct xNode;
struct xGO;

struct xVObj
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
    virtual void Refresh();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AddNode(xNode*, bool);
};
struct xAV
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
    virtual struct xAV* GetObjectByName(const xFixedStr&);
    const xMat& GetWorldRotate();
};

struct xNode : xAV
{
};
struct xGeom : xAV
{
};
struct xGO
{
    xGO(xAV*);
    ~xGO();
    operator xNode*();
    xNode* operator->();
    void operator=(xAV*);
    xAV* m_p;
};
struct xStream
{
    xStream();
    ~xStream();
    char m_auiShapeKeys[0x5d0];
};
struct xNiObj
{
};
struct xAlpha : xNiObj
{
    xAlpha();
    int m_auiShapeKeys[7];
};
struct xShaderProp : xNiObj
{
    xShaderProp();
    void SetFlag(int, int);
    int m_auiShapeKeys[0x20];
};
struct xDecalNode : xNiObj
{
    xDecalNode(float);
    int m_auiShapeKeys[0x2c];
};
struct xTES
{
};
struct FUN_0068dea0_cls
{
    int m_auiShapeKeys[13];
    xPoint3 m_34, m_40, m_4c, m_58;
    int m_pad64[0x2a];
    xGO m_10c;
    int m_110;
    float m_114, m_118, m_11c, m_120;
    int m_pad124[7];
    bool m_140;
    void UpdateDebugDecalBox(const xColorA*, bool);
};

// Loads and clones the debug decal box, scales its vertices, sets its color and rotation, attaches alpha and shader properties, and adds it to the scene.
// @fnv 0x0068dea0
void FUN_0068dea0_cls::UpdateDebugDecalBox(const xColorA* COLOR, bool FLAG)
{
    if (!(*reinterpret_cast<::xGO *>(&::g_011c58e0)))
    {
        xStream qfTOqo;
        if (reinterpret_cast<::FUN_00c3a8a0_cls *>(&(qfTOqo))->FUN_00c3a8a0((unsigned int)("Data\\Meshes\\Decals\\DebugDecalBox.NIF"), false))
        {
            if (::GetRefAt21C((const char *)(::xStream *)(&qfTOqo)) == 1)
                (*reinterpret_cast<::xGO *>(&::g_011c58e0)) = ((::xAV *)(reinterpret_cast<::MLx *>(&(qfTOqo))->GetStringAt(0)));
            ::AssignFixedString((char *)(((*reinterpret_cast<::xGO *>(&::g_011c58e0))).operator->()), (int)&(const ::xFixedStr &)(xFixedStr("Debug Decal Box")), {});
        }
    }
    if ((*reinterpret_cast<::xGO *>(&::g_011c58e0)))
    {
        xGO qrzAir(0);
        reinterpret_cast<::NiObjectD510 *>((((*reinterpret_cast<::xGO *>(&::g_011c58e0))).operator->()))->FUN_00a5d510((::NiPointerD510 &)(qrzAir));
        xNode* qbXcw = qrzAir;
        xAV* qrKBG = qbXcw->GetObjectByName(xFixedStr("DebugDecalBox01:0"));
        xGeom* qZAdkzg = (xGeom*)qrKBG;
        ::FUN_0062bc10((::FUN_0062bc10_obj *)(qbXcw));
        xPoint3* qGfbX = ((::xPoint3 *)(reinterpret_cast<::FUN_0049ec60 *>((qZAdkzg))->GetNext()));
        xColorA* qArxcFu = ((::xColorA *)(reinterpret_cast<::This_004a8050 *>((qZAdkzg))->GetNextProc()));
        for (int qJDuOZ = 0; qJDuOZ < reinterpret_cast<::FUN_00456650_shell *>((qZAdkzg))->FUN_00456650(); qJDuOZ++)
        {
            qGfbX[qJDuOZ].x = qGfbX[qJDuOZ].x * m_118;
            qGfbX[qJDuOZ].y = qGfbX[qJDuOZ].y * m_11c;
            qGfbX[qJDuOZ].z *= m_120 * 2.0f;
            qArxcFu[qJDuOZ] = *COLOR;
        }
        if (::FUN_0040eb10(m_58.x, 0.0f, 0.001f))
            m_58.x = 0.0f;
        if (::FUN_0040eb10(m_58.y, 0.0f, 0.001f))
            m_58.y = 0.0f;
        if (::FUN_0040eb10(m_58.z, 0.0f, 0.001f))
            m_58.z = 0.0f;
        xPoint3 qxQHW = m_58;
        if (reinterpret_cast<::NiPoint3 *>(&(qxQHW))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<const ::xPoint3 *>((void *)&::NiPoint3::ZERO)))))
        {
            qxQHW = m_40;
            xMat qpia;
            if (m_140)
                qpia = (*(const ::xMat *)(::FUN_006a9540((char *)((m_10c).operator->()))));
            else
                qpia = m_10c->GetWorldRotate();
            xMat qZWI = (*(::xMat *)(reinterpret_cast<::ThreeByThreeMatrix *>(&(qpia))->FUN_004b45b0({})));
            qxQHW = qZWI * qxQHW;
        }
        xMat qRqUtp = xFromEuler(qxQHW);
        xMat qAhbO;
        reinterpret_cast<::FUN_004a0c90_shell *>(&(qAhbO))->FUN_004a0c90(-m_114);
        if (m_140)
        {
            reinterpret_cast<::FUN_00440460_S *>((qbXcw))->FUN_00440460((const ::V3 *)(const ::xPoint3 *)(((const ::xPoint3 *)&(reinterpret_cast<::NiAVObject *>(((m_10c).operator->()))->FUN_0043c490()))));
            reinterpret_cast<::FUN_0043fa80_s *>((qbXcw))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((*(const ::xMat *)(::FUN_006a9540((char *)((m_10c).operator->()))))));
            reinterpret_cast<::FUN_00440490_shell *>((qbXcw))->FUN_00440490(reinterpret_cast<::FUN_009cdae0_shell *>(((m_10c).operator->()))->GetFloatAt64());
            xMat qXMUYT = qRqUtp * qAhbO;
            reinterpret_cast<::FUN_0043fa80_s *>((qrKBG))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(qXMUYT));
            reinterpret_cast<::FUN_00440460_S *>((qrKBG))->FUN_00440460((const ::V3 *)(const ::xPoint3 *)(&m_4c));
        }
        else
        {
            xMat qbfQdhM = m_10c->GetWorldRotate() * qRqUtp * qAhbO;
            reinterpret_cast<::FUN_0043fa80_s *>((qrKBG))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(qbfQdhM));
            reinterpret_cast<::FUN_00440460_S *>((qrKBG))->FUN_00440460((const ::V3 *)(const ::xPoint3 *)(&m_34));
        }
        reinterpret_cast<::FUN_0068e740_class *>((qbXcw))->FUN_0068e740();
        {
            xAlpha* qAXSCg = new xAlpha();
            reinterpret_cast<::FUN_0049ed90_shell *>((qAXSCg))->FUN_0049ed90(true);
            reinterpret_cast<::FUN_00439410_cls *>((qbXcw))->FUN_00439410((::ArgObject *)(qAXSCg));
        }
        xShaderProp* qsTDDg = new xShaderProp();
        if (FLAG)
            qsTDDg->SetFlag(0x30, 1);
        reinterpret_cast<::FUN_00439410_cls *>((qrKBG))->FUN_00439410((::ArgObject *)(qsTDDg));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(qrKBG), 0, 0);
        if (m_140)
        {
            xVObj* qBLsiu = (xVObj*)new xDecalNode(30.0f);
            qBLsiu->AddNode(qbXcw, true);
            ((::xVObj *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_10c).operator->()))->FUN_009611e0()))->AddNode((xNode*)qBLsiu, true);
        }
        else
            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::xTES * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(qbXcw), 30.0f);
        ((::xVObj *)(reinterpret_cast<::FUN_009611e0_shell *>((qbXcw))->FUN_009611e0()))->Refresh();
        xUpdateData qBCzzXA(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((qbXcw))->FUN_00a59c60((std::intptr_t)&(qBCzzXA));
    }
}

inline float NiSqrt(float fValue)
{
    return sqrt(fValue);
}

struct Pt
{
    float x, y, z;
    Pt()
    {}
    Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    float FUN_00457990() const
    {
        return NiSqrt(x * x + y * y + z * z);
    }
    void FUN_004a0c10()
    {
        float fScaleMultiplier = FUN_00457990();
        if (fScaleMultiplier > 1e-06)
        {
            float fRecip = 1.0f / fScaleMultiplier;
            x *= fRecip;
            y *= fRecip;
            z *= fRecip;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
    Pt FUN_004b3800(const Pt& kPt) const
    {
        return Pt(y * kPt.z - z * kPt.y, z * kPt.x - x * kPt.z, x * kPt.y - y * kPt.x);
    }
};

struct Mat3
{
    float m_afEntries[3][3];
    void SetRow(unsigned int uiRow, const Pt& kRow)
    {
        m_afEntries[uiRow][0] = kRow.x;
        m_afEntries[uiRow][1] = kRow.y;
        m_afEntries[uiRow][2] = kRow.z;
    }
};

inline float NiAbs(float fValue)
{
    return (float)fabs(fValue);
}

// @fnv 0x00c4b600
Mat3 __cdecl FUN_00c4b600(Pt kWorldPosition)
{
    Pt kAt = kWorldPosition;
    reinterpret_cast<::FUN_004a0c10_s *>(&(kAt))->FUN_004a0c10();
    float fX = NiAbs(kAt.x);
    float fY2 = NiAbs(kAt.y);
    float fZ2 = NiAbs(kAt.z);
    Pt kRight2;
    if (fX <= fY2 && fX <= fZ2)
        kRight2 = Pt(0.0f, -kAt.z, kAt.y);
    else if (fY2 <= fX && fY2 <= fZ2)
        kRight2 = Pt(-kAt.z, 0.0f, kAt.x);
    else
        kRight2 = Pt(-kAt.y, kAt.x, 0.0f);
    reinterpret_cast<::FUN_004a0c10_s *>(&(kRight2))->FUN_004a0c10();
    Pt kUpVal;
    kUpVal = kRight2.FUN_004b3800(kAt);
    reinterpret_cast<::FUN_004a0c10_s *>(&(kUpVal))->FUN_004a0c10();
    kRight2 = kUpVal.FUN_004b3800(kAt);
    reinterpret_cast<::FUN_004a0c10_s *>(&(kRight2))->FUN_004a0c10();
    Mat3 kMatX;
    kMatX.SetRow(0, kRight2);
    kMatX.SetRow(1, kUpVal);
    kMatX.SetRow(2, kAt);
    return kMatX;
}

#include "generated/data/fallout_shared/tempeffects/bstempeffectsimpledecal.inc"
