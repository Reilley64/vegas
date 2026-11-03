
// src/fallout_shared/settings/xgamesetting_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/settings/xgamesetting.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_0043ba10_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00476980_S.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004f8940_class.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_004f8a30_shell2.h"
#include "fnv/decl/FUN_004f8a60_class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/SettingS.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "xgamesetting_decls.h"

class NiRTTI
{
  public:
    const char* m_pcName;
    NiRTTI* m_pBaseRTTI;
};
class GlobalObjectO2_00a7b610;
struct StrArr
{
    unsigned int FUN_00c4c8d0(char*& s);
};
struct FUN_00a4f300_shell
{
    int unk[16];
    unsigned short pad40;
    unsigned short m_usElementCount;
    void* GetEntryAt(int i);
};
class NiTimeController;
class NiProperty;
template <class T> struct NiPtr
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
};
class NiAVObject
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual NiRTTI* GetRTTI();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual int vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual int vf30();
};
struct NiNodeY
{
    int unk[0x28];
    NiPtr<NiAVObject>* m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    __forceinline NiPtr<NiAVObject>& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
__forceinline bool IsKindOfA(NiRTTI* r)
{
    while (r)
    {
        if (r == (NiRTTI*)&g_011f49a4)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}
__forceinline bool IsKindOfN(NiRTTI* r)
{
    while (r)
    {
        if (r == (NiRTTI*)&g_011f4428)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}
__forceinline NiAVObject* CastA(NiAVObject* p)
{
    if (!p)
        return 0;
    return (NiAVObject*)(IsKindOfA(p->GetRTTI()) ? p : 0);
}
__forceinline NiNodeY* CastN(NiAVObject* p)
{
    int u;
    if (!p)
        return 0;
    return (NiNodeY*)(IsKindOfN(p->GetRTTI()) ? p : 0);
}

// @fnv 0x00c4bd80
void __cdecl FUN_00c4bd80(NiAVObject* obj, StrArr* arr)
{
    NiNodeY* node7;
    FUN_00a4f300_shell* c7;
    NiAVObject* propA;
    NiAVObject* geom2;
    unsigned int count4;
    unsigned int i3;
    char* s2;
    unsigned int j;
    if (obj)
    {
        c7 = (FUN_00a4f300_shell*)((::NiTimeController *)(reinterpret_cast<::MyHost *>((obj))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)((const NiRTTI*)&g_011f3fd4))));
        if (!c7 && (obj->vf1c() || obj->vf30()))
        {
            geom2 = obj;
            propA = CastA((NiAVObject*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geom2))->FUN_00a59d30(5))));
            if (propA)
                c7 = (FUN_00a4f300_shell*)((::NiTimeController *)(reinterpret_cast<::MyHost *>((((NiAVObject*)propA)))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)((const NiRTTI*)&g_011f3fd4))));
        }
        if (c7)
        {
            count4 = c7->m_usElementCount;
            for (i3 = 0; i3 < count4; i3++)
            {
                s2 = (char*)c7->GetEntryAt(i3);
                if (s2)
                    arr->FUN_00c4c8d0(s2);
            }
        }
        node7 = CastN(obj);
        if (node7)
        {
            for (j = 0; j < node7->m_usSize; j++)
            {
                FUN_00c4bd80(node7->GetAt(j), arr);
            }
        }
    }
}

namespace fnv_00c4c2d0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    inline float GetEntry(int uiRow, int uiCol) const
    {
        return m_afEntries[uiRow][uiCol];
    }
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
struct NiAVObject
{
};
struct Mat4
{
    float m[4][4];
};
inline void Dead21()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
}
// @fnv 0x00c4c2d0
void __cdecl FUN_00c4c2d0(NiAVObject* pObj, int bInverse, Mat4* pOut)
{
    if (!bInverse)
    {
        NiTransform kXf;
        reinterpret_cast<::NiTransform *>((pObj))->CalculateInverse((*(::NiTransform *)(&kXf)));
        Dead21();
        pOut->m[0][0] = kXf.m_kOrientation.GetEntry(0, 0) * kXf.m_fScale;
        pOut->m[0][1] = kXf.m_kOrientation.GetEntry(1, 0) * kXf.m_fScale;
        pOut->m[0][2] = kXf.m_kOrientation.GetEntry(2, 0) * kXf.m_fScale;
        pOut->m[0][3] = 0.0f;
        pOut->m[1][0] = kXf.m_kOrientation.GetEntry(0, 1) * kXf.m_fScale;
        pOut->m[1][1] = kXf.m_kOrientation.GetEntry(1, 1) * kXf.m_fScale;
        pOut->m[1][2] = kXf.m_kOrientation.GetEntry(2, 1) * kXf.m_fScale;
        pOut->m[1][3] = 0.0f;
        pOut->m[2][0] = kXf.m_kOrientation.GetEntry(0, 2) * kXf.m_fScale;
        pOut->m[2][1] = kXf.m_kOrientation.GetEntry(1, 2) * kXf.m_fScale;
        pOut->m[2][2] = kXf.m_kOrientation.GetEntry(2, 2) * kXf.m_fScale;
        pOut->m[2][3] = 0.0f;
        pOut->m[3][0] = kXf.m_kTranslation.x;
        pOut->m[3][1] = kXf.m_kTranslation.y;
        pOut->m[3][2] = kXf.m_kTranslation.z;
        pOut->m[3][3] = 1.0f;
    }
    else
    {
        Mat4 kM;
        kM.m[3][2] = 0.0f;
        kM.m[3][1] = 0.0f;
        kM.m[3][0] = 0.0f;
        kM.m[2][3] = 0.0f;
        kM.m[2][1] = 0.0f;
        kM.m[2][0] = 0.0f;
        kM.m[1][3] = 0.0f;
        kM.m[1][2] = 0.0f;
        kM.m[1][0] = 0.0f;
        kM.m[0][3] = 0.0f;
        kM.m[0][2] = 0.0f;
        kM.m[0][1] = 0.0f;
        kM.m[3][3] = 1.0f;
        kM.m[2][2] = 1.0f;
        kM.m[1][1] = 1.0f;
        kM.m[0][0] = 1.0f;
        const NiPoint3& rPos = (*reinterpret_cast<::fnv_00c4c2d0::NiPoint3 *>(&::DAT_011f474c));
        kM.m[3][0] = rPos.x;
        kM.m[3][1] = rPos.y;
        kM.m[3][2] = rPos.z;
        ::FUN_00ee6dda();
    }
}
}  // namespace fnv_00c4c2d0

class NiPoint3
{
  public:
    float x, y, z;
};
class ThreeByThreeMatrix
{
  public:
    enum Axis
    {
        X,
        Y,
        Z
    };
    float m_entry[3][3];

    inline float GetEntry(unsigned int uiRow, unsigned int uiCol) const
    {
        return m_entry[uiRow][uiCol];
    }
};
struct Transform
{
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
};
// @fnv 0x00c4c530
void __cdecl FUN_00c4c530(const Transform& transform, unsigned int count, const NiPoint3* positions,
                          NiPoint3* transformedPositions, const NiPoint3* normals, NiPoint3* transformedNormals)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        if (transformedPositions)
        {
            {
                float a = transform.rotate.GetEntry(0, 0);
                float b = transform.rotate.GetEntry(0, 1);
                float c = transform.rotate.GetEntry(0, 2);
                transformedPositions[i].x =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.translate.x);
            }
            {
                float a = transform.rotate.GetEntry(1, 0);
                float b = transform.rotate.GetEntry(1, 1);
                float c = transform.rotate.GetEntry(1, 2);
                transformedPositions[i].y =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.translate.y);
            }
            {
                float a = transform.rotate.GetEntry(2, 0);
                float b = transform.rotate.GetEntry(2, 1);
                float c = transform.rotate.GetEntry(2, 2);
                transformedPositions[i].z =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.translate.z);
            }
        }
        if (transformedNormals)
        {
            {
                float a = transform.rotate.GetEntry(0, 0);
                float b = transform.rotate.GetEntry(0, 1);
                float c = transform.rotate.GetEntry(0, 2);
                transformedNormals[i].x = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
            {
                float a = transform.rotate.GetEntry(1, 0);
                float b = transform.rotate.GetEntry(1, 1);
                float c = transform.rotate.GetEntry(1, 2);
                transformedNormals[i].y = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
            {
                float a = transform.rotate.GetEntry(2, 0);
                float b = transform.rotate.GetEntry(2, 1);
                float c = transform.rotate.GetEntry(2, 2);
                transformedNormals[i].z = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
        }
    }
}

class NiRTTIC4BB
{
  public:
    const NiRTTIC4BB* GetBaseRTTI() const
    {
        return m_pBaseRTTI;
    }
    const char* m_pcName;
    const NiRTTIC4BB* m_pBaseRTTI;
};

class NiObjectC4BB
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const NiRTTIC4BB* GetRTTI() const;
};

inline bool IsKindOfC4BB(const NiRTTIC4BB* pkRTTI, const NiObjectC4BB* pkObject)
{
    const NiRTTIC4BB* pkTmp = pkObject->GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->GetBaseRTTI();
    }
    return false;
}

class TargetC4BB : public NiObjectC4BB
{
  public:
    void* GetDataImpl() const
    {
        return m_pResource;
    }
    void* GetData() const
    {
        return GetDataImpl();
    }
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
    void* m_pResource;
};

inline TargetC4BB* DynamicCastC4BB(NiObjectC4BB* pkObject)
{
    return !pkObject ? 0 : (TargetC4BB*)(IsKindOfC4BB(&(*reinterpret_cast<const ::NiRTTIC4BB *>(&::g_011f444c)), pkObject) ? pkObject : 0);
}

// @fnv 0x00c4bb40
void* __cdecl FUN_00c4bb40(NiObjectC4BB* pkObject)
{
    void* pvData = 0;
    TargetC4BB* pkTarget;
    if (!pkObject)
        pkTarget = 0;
    else
        pkTarget = (TargetC4BB*)(IsKindOfC4BB(&(*reinterpret_cast<const ::NiRTTIC4BB *>(&::g_011f444c)), pkObject) ? pkObject : 0);
    if (pkTarget)
        pvData = pkTarget->GetData();
    return pvData;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
int __cdecl FUN_00ec65a6(char* dst, unsigned size, const char* src);
int __cdecl FUN_00ec6bd2(char* dst, unsigned size, const char* src);
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ1()
{
    int dq[1];
}
struct FixStrQ
{
    char* m_kHandle;
    FixStrQ(const char* s)
    {
        if (s == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = ::NiGlobalStringTable::AddString(s);
    }
    ~FixStrQ()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        long* pRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(pRef);
    }
    const char* CStr()
    {
        const char* p = m_kHandle;
        return p;
    }
};
struct NamedQ
{
    int unk00, unk04;
    FixStrQ m_kName;
    const char* GetName()
    {
        return m_kName.CStr();
    }
    void SetName(const FixStrQ& kName)
    {
        DeadQ3();
        reinterpret_cast<::FUN_0043ba10_shell *>(&(m_kName))->FUN_0043ba10((::FUN_0043ba10_shell *)&(kName));
    }
};
struct PathQ
{
    char m_szDir[0x203];
    char m_szName[0x100];
    char m_szExt[0x105];
    PathQ(const char* p);
};
// @fnv 0x00c4bbc0
void __cdecl FUN_00c4bbc0(NamedQ* pObj, const char* pcPath)
{
    const char* pcOld_ = pObj->GetName();
    PathQ kKPath(pcPath);
    char acBuf[0x100];
    if (pcOld_)
        FUN_00ec65a6(acBuf, 0x100, pcOld_);
    else
        acBuf[0] = 0;
    FUN_00ec6bd2(acBuf, 0x100, "_:");
    FUN_00ec6bd2(acBuf, 0x100, kKPath.m_szName);
    pObj->SetName(FixStrQ(acBuf));
}

class NiPoint3R
{
  public:
    float x, y, z;

    NiPoint3R()
    {}
    NiPoint3R(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    NiPoint3R operator-() const
    {
        return NiPoint3R(-x, -y, -z);
    }
    NiPoint3R operator*(float f) const
    {
        return NiPoint3R(f * x, f * y, f * z);
    }
    NiPoint3R operator+(const NiPoint3R& p) const
    {
        return NiPoint3R(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3R operator-(const NiPoint3R& p) const
    {
        return NiPoint3R(x - p.x, y - p.y, z - p.z);
    }
    float Length() const;
    void FUN_004a0c10()
    {
        float len = Length();
        if (len > 1e-06)
        {
            float inv = 1.0f / len;
            x *= inv;
            y *= inv;
            z *= inv;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
};
inline NiPoint3R __cdecl operator*(float f, const NiPoint3R& p)
{
    return NiPoint3R(f * p.x, f * p.y, f * p.z);
}
extern "C" NiPoint3R __cdecl FUN_004a3760(float f, const NiPoint3R& p);
class NiMatrix3R
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3R Column(unsigned int column) const
    {
        NiPoint3R result;
        reinterpret_cast<::FUN_00439f50_class *>((void *)this)->FUN_00439f50(column, (::NiPoint3 *)&(result));
        return result;
    }
};
struct NiUpdateData
{
    float time;
    bool controllers, geometry;
    bool unk06, unk07, unk08;
    NiUpdateData(float, bool, bool);
};
struct NiFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
};
struct Source
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
    NiMatrix3R rotation;
    NiPoint3R position;
    float scale;
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
    NiFrustum property;
};
struct NiCamera
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
    NiMatrix3R rotation;
    NiPoint3R position;
    float scale;
    void UpdateViewFrustum(const NiFrustum&);
};
struct Plane
{
    NiPoint3R normal;
    float distance;
    float Distance(const NiPoint3R& p) const
    {
        return reinterpret_cast<::FUN_004b6190_shell *>((void *)&(normal))->DotProduct((void *)&(p)) - distance;
    }
};
double __cdecl _fabs(double);
inline double Abs(float value)
{
    return (float)_fabs(value);
}
// @fnv 0x00c4bf40
void __cdecl FUN_00c4bf40(Source* source, Plane* plane, NiCamera* dest)
{
    NiPoint3R position = source->position;
    NiPoint3R first7 = source->rotation.Column(0);
    NiPoint3R second3 = source->rotation.Column(2);
    NiPoint3R thirdB = source->rotation.Column(1);
    NiPoint3R reflected6 = position + (-plane->normal) * (float)(2.0 * plane->Distance(position));
    NiPoint3R direction6 = -first7;
    reinterpret_cast<::FUN_004a0c10_s *>(&(direction6))->FUN_004a0c10();
    NiPoint3R axisA = (float)(2.0 * reinterpret_cast<::FUN_004b6190_shell *>((void *)&(plane->normal))->DotProduct((void *)&(direction6))) * plane->normal - direction6;
    direction6 = -second3;
    reinterpret_cast<::FUN_004a0c10_s *>(&(direction6))->FUN_004a0c10();
    NiPoint3R axis2 = FUN_004a3760((float)(2.0 * reinterpret_cast<::FUN_004b6190_shell *>((void *)&(plane->normal))->DotProduct((void *)&(direction6))), plane->normal) - direction6;
    direction6 = thirdB;
    reinterpret_cast<::FUN_004a0c10_s *>(&(direction6))->FUN_004a0c10();
    NiPoint3R axis7 = FUN_004a3760((float)(2.0 * reinterpret_cast<::FUN_004b6190_shell *>((void *)&(plane->normal))->DotProduct((void *)&(direction6))), plane->normal) - direction6;
    NiMatrix3R matrix;
    reinterpret_cast<::FUN_00476980_S *>(&(matrix))->FUN_00476980((int)&(axisA), (int)&(axis7), (int)&(axis2));
    dest->position = reflected6;
    dest->rotation = matrix;
    dest->scale = Abs(source->scale);
    dest->UpdateViewFrustum(source->property);
    NiUpdateData update2(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((dest))->FUN_00a59c60((int)&(update2));
}
