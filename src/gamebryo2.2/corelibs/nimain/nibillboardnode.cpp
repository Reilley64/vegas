// gamebryo2.2/corelibs/nimain/nibillboardnode.cpp: NiBillboardNode (1 function)

#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_00aa1000.h"
#include <cstdint>
#include <new>
#include <cmath>
#include <cstring>
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a5dbe0_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiNodeEq.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/NodeA5E8.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a5dd40__FUN_00a5dd40_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_00a5e000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01095000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f6000.h"
#include <math.h>
struct NiRTTI;

class NiBillboardNode
{
  public:
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x0051cf90
const NiRTTI* NiBillboardNode::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4aa0));
}



class FUN_00a5ecb0
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    FUN_00a5ecb0(unsigned int flags);
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
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
};
class BillboardNode : public FUN_00a5ecb0
{
  public:
    unsigned short mode;
    unsigned short unknownAE;
    float angle;
    virtual const NiRTTI* GetRTTI() const;
    BillboardNode() throw() : FUN_00a5ecb0(0), angle(0.0f)
    {
        mode = 9;
    }
};
// @fnv 0x00a7e770
BillboardNode* FUN_00a7e770()
{
    return new BillboardNode;
}


struct NiUpdateData
{
    float m_fTime;
};
struct CloningProcess;
struct NiUpdateData;
class NiNode
{
  public:
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
public:
    void CopyMemberData(::NiNode *, ::CloningProcess &);
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
};
struct UnkBoard : NiNode
{
    void FUN_00a7da80(NiUpdateData&, unsigned int);
};
// @fnv 0x00a7da80
void UnkBoard::FUN_00a7da80(NiUpdateData& a, unsigned int b)
{
    *(float*)((char*)this + 0xB0) = a.m_fTime;
    NiNode::UpdateSelectedDownwardPass(a, b);
    f47();
}

namespace fnv_00a7dab0 {
struct NiUpdateData
{
    float m_fTime;
};
struct BaseNode
{
};
struct StandIn
{
    void FUN_00a7dab0(NiUpdateData&, uintptr_t);
};
// @fnv 0x00a7dab0
void StandIn::FUN_00a7dab0(NiUpdateData& UpdateData, uintptr_t uFlags)
{
    *(float*)((char*)this + 0xb0) = UpdateData.m_fTime;
    ::FUN_00a5e1f0((::NiNode *)(((BaseNode*)this)), (intptr_t)&(UpdateData), (*(::NiUpdateData *)(uFlags)), {});
    ((void(**)(void*)) * (void***)this)[47](this);
}
}  // namespace fnv_00a7dab0

class NiCullingProcess;
struct DummyNode
{
};
struct FUN_00a7de40_shell
{
};
struct FUN_00a7e610_shell : NiBillboardNode
{
    void FUN_00a7e610(NiCullingProcess* process);
};
class NiAVObject
{
  public:
    virtual void Dummy()
    {}
    NiAVObject();
    char _pad[0x98];
};
struct GlobalObject_004aff00
{
    GlobalObject_004aff00(int, int);
};
struct FUN_00a5ecb0_o2 : NiAVObject
{
    GlobalObject_004aff00 m;
    FUN_00a5ecb0_o2(unsigned int uiNumChildren);
};
// @fnv 0x00a5ecb0
FUN_00a5ecb0_o2::FUN_00a5ecb0_o2(unsigned int uiNumChildren) : m(uiNumChildren, 1)
{}

namespace fnv_00a7dae0 {
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
};
class NiNode
{
  public:
    virtual void F00() = 0;
    virtual void F01() = 0;
    virtual void F02() = 0;
    virtual void F03() = 0;
    virtual void F04() = 0;
    virtual void F05() = 0;
    virtual void F06() = 0;
    virtual void F07() = 0;
    virtual void F08() = 0;
    virtual void F09() = 0;
    virtual void F10() = 0;
    virtual void F11() = 0;
    virtual void F12() = 0;
    virtual void F13() = 0;
    virtual void F14() = 0;
    virtual void F15() = 0;
    virtual void F16() = 0;
    virtual void F17() = 0;
    virtual void F18() = 0;
    virtual void F19() = 0;
    virtual void F20() = 0;
    virtual void F21() = 0;
    virtual void F22() = 0;
    virtual void F23() = 0;
    virtual void F24() = 0;
    virtual void F25() = 0;
    virtual void F26() = 0;
    virtual void F27() = 0;
    virtual void F28() = 0;
    virtual void F29() = 0;
    virtual void F30() = 0;
    virtual void F31() = 0;
    virtual void F32() = 0;
    virtual void F33() = 0;
    virtual void F34() = 0;
    virtual void F35() = 0;
    virtual void F36() = 0;
    virtual void F37() = 0;
    virtual void F38() = 0;
    virtual void F39() = 0;
    virtual void F40() = 0;
    virtual void F41() = 0;
    virtual void F42() = 0;
    virtual void F43() = 0;
    virtual void F44() = 0;
    virtual void F45() = 0;
    virtual void F46() = 0;
    virtual void F47() = 0;
    char _pad[0xA8];
    unsigned short m_flags;
    char _pad2[2];
    float m_uiCommandId;
    void FUN_00a7dae0(NiUpdateData&, unsigned int);
};
// @fnv 0x00a7dae0
void NiNode::FUN_00a7dae0(NiUpdateData& UpdateData, unsigned int uFlags)
{
    m_uiCommandId = UpdateData.m_fTime;
    if (UpdateData.m_bUpdate)
        m_flags |= 8;
    else
        m_flags &= 0xFFF7;
    reinterpret_cast<::NiNode *>(this)->UpdateDownwardPass((::NiUpdateData &)(UpdateData), uFlags);
    F47();
}
}  // namespace fnv_00a7dae0

struct NiObject;
struct BaseForCall
{
};
struct MyNode
{
    char _pad[0xac];
    unsigned char unkac;
    unsigned char FUN_00a7db30(NiObject* pkObject);
};
// @fnv 0x00a7db30
unsigned char MyNode::FUN_00a7db30(NiObject* pkObject)
{
    NiBillboardNode* pkNode = (NiBillboardNode*)pkObject;
    if (!reinterpret_cast<::NiNodeEq *>((((BaseForCall*)this)))->FUN_00a5e600((::NiAVObject *)(pkObject)))
        return 0;
    return ((((unsigned char*)pkNode)[0xAC] ^ this->unkac) & 7) == 0;
}

struct NiBinaryStream
{
    int _m0;
    int m_pos;
    void* m_pfnRead;
    int(__cdecl* m_pfnWrite)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[592];
    NiBinaryStream* m_pBackingStream;
};
struct NiNodeBase
{
};
struct StandIn
{
    char _pad[172];
    short m_field;
    void FUN_00a7e850(NiStream&);
};
// @fnv 0x00a7e850
void StandIn::FUN_00a7e850(NiStream& kStream)
{
    reinterpret_cast<::NodeA5E8 *>((((NiNodeBase*)this)))->FUN_00a5e880((::NiStreamA5E8 &)(kStream));
    NiBinaryStream* __restrict pkOstr = kStream.m_pBackingStream;
    unsigned int size = 2;
    pkOstr->m_pos += pkOstr->m_pfnWrite(pkOstr, &m_field, 2, &size, 1);
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    NiPoint3 operator-() const
    {
        return NiPoint3(-x, -y, -z);
    }
    float operator*(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float SqrLength() const
    {
        return y * y + x * x + z * z;
    }
public:
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
public:
    static const ::NiPoint3 ZERO;
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    NiPoint3 GetCol(int c) const
    {
        return NiPoint3(m_afEntries[0][c], m_afEntries[1][c], m_afEntries[2][c]);
    }
    void MakeAxisAngleRotation(float angle, float x, float y, float z);
    NiPoint3 operator*(const NiPoint3& p) const;
};

inline float SqrLength3(float a, float b, float c)
{
    return a * a + b * b + c * c;
}

struct NiCameraStandIn
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
    ThreeByThreeMatrix m_kWorldRotate;
    NiPoint3 m_kWorldTranslate;
};

// @fnv 0x00a7dc40
bool FUN_00a7dc40(NiCameraStandIn* pkCamera, const NiPoint3& kPos, NiPoint3& kWorldPosition, NiPoint3& kUp,
                            NiPoint3& kRight)
{
    NiPoint3 kDelta = pkCamera->m_kWorldTranslate - kPos;
    float fLenSq = SqrLength3(kDelta.x, kDelta.y, kDelta.z);
    if (fLenSq < 0.001f)
        return false;

    reinterpret_cast<::FUN_004a0c10_s *>(&(kDelta))->FUN_004a0c10();
    kWorldPosition = -pkCamera->m_kWorldRotate.GetCol(0);
    kUp = pkCamera->m_kWorldRotate.GetCol(1);
    kRight = pkCamera->m_kWorldRotate.GetCol(2);

    float fDot = kWorldPosition * kDelta;
    if (fDot < (double)0.999999f)
    {
        ThreeByThreeMatrix kRot;
        {
            NiPoint3 kAxis = reinterpret_cast<::NiPoint3 *>((void *)&(kDelta))->CrossProduct(kWorldPosition);
            kRot.MakeAxisAngleRotation(::AcosClamped(fDot), kAxis.x, kAxis.y, kAxis.z);
        }
        kWorldPosition = kDelta;
        kUp = kRot * kUp;
        kRight = kRot * kRight;
    }
    return true;
}

struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    template <class T> unsigned int Read(T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pValue, sizeof(T), &uiSize, 1);
    }
};

struct NiStreamImpl
{
    char pad[0xd8];
    unsigned int m_uiFileVersion;
    char pad2[0x24c - 0xdc];
    NiBinaryStreamStandIn* m_pUnderlyingStream;
    char pad3[0x284 - 0x250];
    unsigned short m_usOldFlags;
    unsigned int GetFileVersion() const
    {
        return m_uiFileVersion;
    }
};

template <class T> inline void ReadBinaryValue(NiStreamImpl& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value);
}

class Prop
{
  public:
    char unk00[0xac];
    unsigned short m_usFlags;

    void FUN_00a7e7b0(NiStreamImpl& stream);
};

// @fnv 0x00a7e7b0
void Prop::FUN_00a7e7b0(NiStreamImpl& stream)
{
    reinterpret_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>(this)->FUN_00a5dd40((::NiStream *)&(stream));
    if (stream.GetFileVersion() < 0x0a000102)
    {
        m_usFlags = stream.m_usOldFlags;
        if (stream.GetFileVersion() < 0x04020003)
        {
            unsigned short us = m_usFlags;
            m_usFlags = (m_usFlags & 0xe000) << 1;
            m_usFlags |= us & 0x1fff;
        }
        m_usFlags >>= 6;
    }
    else
    {
        ReadBinaryValue(stream, m_usFlags);
    }
    m_usFlags |= 8;
}

class NiMemManagerA7E
{
  public:
};


class NiPoint3A7E
{
  public:
    float x, y, z;


    NiPoint3A7E operator-(const NiPoint3A7E& pt) const
    {
        NiPoint3A7E kResult;
        kResult.x = x - pt.x;
        kResult.y = y - pt.y;
        kResult.z = z - pt.z;
        return kResult;
    }

    float Length() const;
};

inline float NiSqrtA7E(float fValue)
{
    return (float)sqrt(fValue);
}

inline float NiPoint3A7E::Length() const
{
    return NiSqrtA7E(x * x + (y * y) + z * z);
}

class NiBoundA7E
{
  public:

    NiPoint3A7E m_kCenter;
    float m_fBoundRadius;

    void SetCenterAndRadius(const NiPoint3A7E& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }
};

class NiNodeA7E
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void SetWorldBound(NiBoundA7E* pkBound);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBoundA7E* m_pkWorldBound;
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
    NiPoint3A7E m_kWorldTranslate;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned short m_usChildCount;

    void FUN_00a7e630();
};

// @fnv 0x00a7e630
void NiNodeA7E::FUN_00a7e630()
{
    if (!m_usChildCount)
        return;

    if (!m_pkWorldBound)
    {
        SetWorldBound(new NiBoundA7E);
        m_pkWorldBound->SetCenterAndRadius((*reinterpret_cast<const ::NiPoint3A7E *>((void *)&::NiPoint3::ZERO)), 0.0f);
    }

    NiPoint3A7E kDiff = m_pkWorldBound->m_kCenter - m_kWorldTranslate;
    float fRadius = m_pkWorldBound->m_fBoundRadius;
    m_pkWorldBound->SetCenterAndRadius(m_kWorldTranslate, kDiff.Length() + fRadius);
}

struct StrArr
{
    int unk;
    int unkCur;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short unk0c;
    unsigned short m_usGrowBy;
    void Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
    }
};

struct FUN_00a5ea70_t
{
    void FUN_00a5ea70(StrArr* array);
};

class GlobalObjectO2_00a7b610
{
  public:
    char* m_pString;
};

struct PropTarget : Prop
{
    void FUN_00a7e890(StrArr* array);
};

// @fnv 0x00a7e890
void PropTarget::FUN_00a7e890(StrArr* array)
{
    ((FUN_00a5ea70_t*)this)->FUN_00a5ea70(array);
    array->Add(::FUN_00a7d330(g_011f4aa0.m_pString));
    unsigned int uiFlags = m_usFlags & 7;
    array->Add(::FUN_00a7db60("m_eMode", uiFlags));
}

void* __cdecl FUN_00aa1070(unsigned int size);

// @fnv 0x00a7db60
char* __cdecl FUN_00a7db60(const char* name, int type)
{
    unsigned int size = strlen(name) + 0x16;
    char* buffer = (char*)FUN_00aa1070(size);
    switch (type)
    {
    case 0:
        ::NiSprintf(buffer, size, "%s = ALWAYS_FACE_CAMERA", name);
        break;
    case 1:
        ::NiSprintf(buffer, size, "%s = ROTATE_ABOUT_UP", name);
        break;
    case 2:
        ::NiSprintf(buffer, size, "%s = RIGID_FACE_CAMERA", name);
        break;
    case 3:
        ::NiSprintf(buffer, size, "%s = ALWAYS_FACE_CENTER", name);
        break;
    case 4:
        ::NiSprintf(buffer, size, "%s = RIGID_FACE_CENTER", name);
        break;
    case 5:
        ::NiSprintf(buffer, size, "%s = BSROTATE_ABOUT_UP", name);
        break;
    }
    return buffer;
}
inline float BoardRootFloat(float v)
{
    return (float)sqrt(v);
}
struct XY
{
    float x, y;
};
struct BoardVector : XY
{
    float z;
    void Negate(BoardVector& out) const
    {
        out.x = -x;
        out.y = -y;
        out.z = -z;
    }
};
inline float LengthPair(float a, float b)
{
    return (float)sqrt((double)(float)(a * a + b * b));
}
struct BoardMatrix : ThreeByThreeMatrix
{
    void GetColumn(unsigned int column, BoardVector& v) const
    {
        v.x = m_afEntries[0][column];
        v.y = m_afEntries[1][column];
        v.z = m_afEntries[2][column];
    }
    void SetColumn(unsigned int column, const BoardVector& v)
    {
        m_afEntries[0][column] = v.x;
        m_afEntries[1][column] = v.y;
        m_afEntries[2][column] = v.z;
    }
    void Identity()
    {
        float& e00 = m_afEntries[0][0];
        float& e01 = m_afEntries[0][1];
        float& e02 = m_afEntries[0][2];
        float& e10 = m_afEntries[1][0];
        float& e11 = m_afEntries[1][1];
        float& e12 = m_afEntries[1][2];
        float& e20 = m_afEntries[2][0];
        float& e21 = m_afEntries[2][1];
        float& e22 = m_afEntries[2][2];
        e00 = 1.0f;
        e10 = 0.0f;
        e20 = 0.0f;
        e01 = 0.0f;
        e21 = 0.0f;
        e11 = 1.0f;
        e02 = 0.0f;
        e12 = 0.0f;
        e22 = 1.0f;
    }
    BoardMatrix* FUN_0043f8d0(BoardMatrix*, const BoardMatrix&) const;
};
struct BoardTransform
{
    BoardMatrix rotate;
    BoardVector translate;
    float scale;
    BoardTransform* FUN_0062c250(BoardTransform*, const BoardTransform&) const;
};
extern const float DAT_010959f4 = 1.0e-6f;
extern const float DAT_0109deb8 = 1.0e-12f;
struct BoardUpdate
{
    float time;
    bool updateControllers, dirty, unk06, unk07, unk08;
};
struct BillboardResults
{
    BoardUpdate update;
    BoardVector up03, dir24, right03, dir5, right24, dir03, dir1, up24;
};
struct DirectionLength
{
    BoardVector kWorldPosition;
    union
    {
        float fScaleMultiplier, fInvLength, fSin;
    };
};
inline void LengthInPlace(float& value, float a, float b)
{
    value = a * a + b * b;
    value = (float)sqrt((double)value);
    static_cast<volatile float&>(value) = static_cast<const volatile float&>(value);
}
inline float RoundTo(float& out, float value)
{
    out = value;
    return out;
}
inline float CopyScalar(float value)
{
    return value;
}
union CompositionResult
{
    BoardTransform composed;
    BoardMatrix product;
};
struct BoardObject
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Update(BoardUpdate&, unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    BoardObject* parent;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    BoardTransform local, world;
    unsigned int unk9C;
    BoardObject** children;
    unsigned short capacity, count;
    unsigned int unkA8;
    unsigned short flags, unkAE;
    float time;
    void FUN_00a7de40(const BoardObject*);
};
// @fnv 0x00a7e610
void FUN_00a7e610_shell::FUN_00a7e610(NiCullingProcess* process)
{
    reinterpret_cast<::BoardObject *>((((FUN_00a7de40_shell*)this)))->FUN_00a7de40((const ::BoardObject *)(*(NiCullingProcess**)((char*)process + 0xc)));
    reinterpret_cast<::FUN_00a5dbe0_shell *>((((DummyNode*)this)))->FUN_00a5dbe0(process);
}
// @fnv 0x00a7de40
void BoardObject::FUN_00a7de40(const BoardObject* camera)
{
    CompositionResult composition;
    BillboardResults results;
    BoardTransform kParentWorld;
    if (parent)
        kParentWorld = parent->world;
    else
        reinterpret_cast<::NiTransform *>(&(kParentWorld))->ResetToIdentity();
    world = *kParentWorld.FUN_0062c250(&composition.composed, local);
    unsigned int mode = flags & 7;
    BoardMatrix kRot = (*reinterpret_cast<const ::BoardMatrix *>(&::DAT_011a9448));
    DirectionLength work;
    BoardVector& kWorldPosition = work.kWorldPosition;
    float& fScaleMultiplier = work.fScaleMultiplier;
    BoardVector kRight, kUp, kTmp;
    switch (mode)
    {
    case 0:
    case 3:
        if (mode == 3)
        {
            if (!::FUN_00a7dc40((::NiCameraStandIn *)(camera), (const ::NiPoint3 &)(world.translate), (::NiPoint3 &)(kWorldPosition), (::NiPoint3 &)(kUp), (::NiPoint3 &)(kRight)))
                break;
        }
        else
        {
            camera->world.rotate.GetColumn(0, kWorldPosition);
            kWorldPosition.Negate(kUp);
            kWorldPosition = kUp;
            camera->world.rotate.GetColumn(1, kRight);
            kUp = kRight;
            camera->world.rotate.GetColumn(2, kTmp);
            kRight = kTmp;
        }
        kWorldPosition = (*((::BoardVector *)(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.dir03), (const ::NiPoint3 &)(kWorldPosition), (const float *)&(world.rotate)))));
        kUp = (*((::BoardVector *)(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.up03), (const ::NiPoint3 &)(kUp), (const float *)&(world.rotate)))));
        kRight = (*((::BoardVector *)(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.right03), (const ::NiPoint3 &)(kRight), (const float *)&(world.rotate)))));
        LengthInPlace(fScaleMultiplier, kUp.y, kRight.y);
        if (fScaleMultiplier > DAT_010959f4)
        {
            float& fInvLength = work.fInvLength;
            fInvLength = 1.0f / fScaleMultiplier;
            float fCos;
            fCos = fInvLength * kUp.y;
            float fSin = (work.fSin = fInvLength * -kRight.y);
            kRot.m_afEntries[0][0] = fSin * kUp.x + fCos * kRight.x;
            kRot.m_afEntries[1][0] = fSin * kUp.y + fCos * kRight.y;
            kRot.m_afEntries[2][0] = fSin * kUp.z + fCos * kRight.z;
            kRot.m_afEntries[0][1] = fCos * kUp.x - fSin * kRight.x;
            kRot.m_afEntries[1][1] = fCos * kUp.y - fSin * kRight.y;
            kRot.m_afEntries[2][1] = fCos * kUp.z - fSin * kRight.z;
        }
        else
        {
            kTmp.x = -kRight.x;
            kTmp.y = -kRight.y;
            kTmp.z = -kRight.z;
            kRot.SetColumn(0, kTmp);
            kTmp.x = -kUp.x;
            kTmp.y = -kUp.y;
            kTmp.z = -kUp.z;
            kRot.SetColumn(1, kTmp);
        }
        kRot.SetColumn(2, kWorldPosition);
        break;
    case 1:
        kTmp.x = camera->world.translate.x - world.translate.x;
        kTmp.y = camera->world.translate.y - world.translate.y;
        kTmp.z = camera->world.translate.z - world.translate.z;
        *reinterpret_cast<::NiPoint3 *>(&kWorldPosition) = reinterpret_cast<const ::Point3_0053d280 *>(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.dir1), (const ::NiPoint3 &)(kTmp), (const float *)&(world.rotate)))->FUN_0053d280(world.scale);
        fScaleMultiplier = BoardRootFloat(kWorldPosition.x * kWorldPosition.x + kWorldPosition.z * kWorldPosition.z);
        if (!(fScaleMultiplier < DAT_0109deb8))
        {
            fScaleMultiplier = 1.0f / fScaleMultiplier;
            kWorldPosition.x = fScaleMultiplier * static_cast<const volatile float&>(kWorldPosition.x);
            kWorldPosition.z = fScaleMultiplier * kWorldPosition.z;
            kRot.m_afEntries[0][0] = kWorldPosition.z;
            kRot.m_afEntries[1][0] = 0;
            kRot.m_afEntries[2][0] = -kWorldPosition.x;
            kRot.m_afEntries[0][1] = 0;
            kRot.m_afEntries[1][1] = 1;
            kRot.m_afEntries[2][1] = 0;
            kRot.m_afEntries[1][2] = 0;
            kRot.m_afEntries[0][2] = kWorldPosition.x;
            kRot.m_afEntries[2][2] = kWorldPosition.z;
        }
        break;
    case 2:
    case 4:
        if (mode == 4)
        {
            if (!::FUN_00a7dc40((::NiCameraStandIn *)(camera), (const ::NiPoint3 &)(world.translate), (::NiPoint3 &)(kRight), (::NiPoint3 &)(kUp), (::NiPoint3 &)(kWorldPosition)))
                break;
        }
        else
        {
            camera->world.rotate.GetColumn(0, kTmp);
            kTmp.Negate(kWorldPosition);
            kRight = kWorldPosition;
            camera->world.rotate.GetColumn(1, kTmp);
            kUp = kTmp;
            camera->world.rotate.GetColumn(2, kTmp);
            kWorldPosition = kTmp;
        }
        kRight = (*((::BoardVector *)(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.right24), (const ::NiPoint3 &)(kRight), (const float *)&(world.rotate)))));
        kUp = (*((::BoardVector *)(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.up24), (const ::NiPoint3 &)(kUp), (const float *)&(world.rotate)))));
        kWorldPosition = (*((::BoardVector *)(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.dir24), (const ::NiPoint3 &)(kWorldPosition), (const float *)&(world.rotate)))));
        kRot.SetColumn(0, kWorldPosition);
        kRot.SetColumn(1, kUp);
        kRot.SetColumn(2, kRight);
        break;
    case 5:
        world.rotate.Identity();
        kTmp.x = camera->world.translate.x - world.translate.x;
        kTmp.y = camera->world.translate.y - world.translate.y;
        kTmp.z = camera->world.translate.z - world.translate.z;
        *reinterpret_cast<::NiPoint3 *>(&kWorldPosition) = reinterpret_cast<const ::Point3_0053d280 *>(::FUN_004b3ae0((::NiPoint3 *)(::BoardVector *)(&results.dir5), (const ::NiPoint3 &)(kTmp), (const float *)&(world.rotate)))->FUN_0053d280(world.scale);
        double vy = kWorldPosition.y;
        double vx = kWorldPosition.x;
        fScaleMultiplier = BoardRootFloat((float)(vx * vx + vy * vy));
        if (!(fScaleMultiplier < DAT_0109deb8))
        {
            fScaleMultiplier = 1.0f / fScaleMultiplier;
            kWorldPosition.x = fScaleMultiplier * static_cast<const volatile float&>(kWorldPosition.x);
            kWorldPosition.y = fScaleMultiplier * kWorldPosition.y;
            kRot.m_afEntries[0][0] = -kWorldPosition.y;
            kRot.m_afEntries[1][0] = kWorldPosition.x;
            kRot.m_afEntries[2][0] = 0;
            kRot.m_afEntries[2][1] = 0;
            kRot.m_afEntries[0][2] = 0;
            kRot.m_afEntries[1][2] = 0;
            kRot.m_afEntries[0][1] = kWorldPosition.x;
            kRot.m_afEntries[1][1] = kWorldPosition.y;
            kRot.m_afEntries[2][2] = 1;
        }
        break;
    }
    world.rotate = *world.rotate.FUN_0043f8d0(&composition.product, kRot);
    BoardUpdate& kUpdate = results.update;
    kUpdate.time = time;
    kUpdate.updateControllers = (flags & 8) != 0;
    kUpdate.dirty = false;
    kUpdate.unk06 = false;
    kUpdate.unk07 = false;
    kUpdate.unk08 = false;
    for (unsigned int i = 0; i < count; ++i)
    {
        BoardObject* child = children[i];
        if (child)
            child->Update(kUpdate, 0);
    }
}



struct BillboardCloneBaseCall
{
    void FUN_00a5ecb0_o2(unsigned int childCount);
};

extern const void* DAT_0102bf44[];

struct BillboardCloneVptr
{
    const void** vtable;
};

struct BillboardClone : StandIn
{
    float m_uiFilterValue;


    __forceinline BillboardClone()
    {
        new ((void *)(((BillboardCloneBaseCall*)this))) ::FUN_00a5ecb0_o2(0);
        m_uiFilterValue = 0.0f;
        ((BillboardCloneVptr*)this)->vtable = DAT_0102bf44;
        m_field = 9;
    }
};

struct BillboardCloneSource : StandIn
{
    BillboardClone* FUN_00a7e710(void* context);
};

// @fnv 0x00a7e710
BillboardClone* BillboardCloneSource::FUN_00a7e710(void* context)
{
    void* storage = FUN_00aa13e0(sizeof(BillboardClone));
    BillboardClone* clone = storage ? new (storage) BillboardClone() : 0;
    reinterpret_cast<::NiNode *>(this)->CopyMemberData((::NiNode *)(clone), (*(::CloningProcess *)(context)));
    clone->m_field = m_field;
    return clone;
}
