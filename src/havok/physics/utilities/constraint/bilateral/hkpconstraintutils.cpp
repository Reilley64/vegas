
// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cdea20_cls.h"
#include "fnv/decl/FUN_00cdea80_cls.h"
#include "fnv/decl/FUN_00cdeaa0_cls.h"
#include "fnv/decl/FUN_00cf3ea0.h"
#include "fnv/decl/FUN_00d4f2a0.h"
#include "fnv/decl/FUN_00d52fc0.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/hkPragdollLimitsData.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_01268000.h"


struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct hkMemoryRouter;
inline AudioMgr* audio()
{
    return (AudioMgr*)&hkMemoryRouter::getInstance();
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct Block5
{
    int unk00, unk04, unk08, unk0c, unk10;
};

struct Block5b
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    unsigned char unk07;
    int unk08, unk0c, unk10;
};

struct hkRefObj
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

struct CloneDataBase : hkRefObj
{
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    __m128 unk20, unk30, unk40, unk50, unk60, unk70;
};

struct CloneDataA : CloneDataBase
{
    Block5 unk80;
    Block5b unk94;
    Block5 unka8;
};

struct CloneDataB : CloneDataBase
{
    Block5 unk80;
};

struct SourceDataHeader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
};

struct SourceData : SourceDataHeader
{
    __m128 unk20, unk30, unk40, unk50, unk60, unk70, unk80;
};

struct SourceDataB : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Block5 unkc0;
};

struct SourceDataA : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc,
        unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    Block5 unkfc;
    Block5b unk110;
    Block5 unk124;
};

struct Instance;

struct Instance : hkRefObj
{
    int unk08;
    SourceData* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1c;
};

inline void* hkAlloc(int size)
{
    hkRefObj* p = (hkRefObj*)audio()->heap().blockAlloc(size);
    p->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}

// @fnv 0x00e5aac0
Instance* __cdecl CloneInstanceFromSource(Instance* apSource)
{
    SourceData* data = apSource->unk0c;
    CloneDataBase* clone;
    switch (data->getType())
    {
    case 7: {
        SourceDataA* s = (SourceDataA*)data;
        CloneDataA* pCloneTyped = ((::CloneDataA *)(new ((void *)(((CloneDataA*)hkAlloc(0xc0)))) ::FUN_00d4f2a0()));
        clone = pCloneTyped;
        pCloneTyped->unk20 = s->unk20;
        pCloneTyped->unk30 = s->unk30;
        pCloneTyped->unk40 = s->unk40;
        pCloneTyped->unk50 = s->unk60;
        pCloneTyped->unk60 = s->unk70;
        pCloneTyped->unk70 = s->unk80;
        pCloneTyped->unk80 = s->unkfc;
        pCloneTyped->unka8 = s->unk124;
        pCloneTyped->unk94 = s->unk110;
        hkBool flag(s->unk110.unk06 != 0);
        reinterpret_cast<::hkPragdollLimitsData *>((pCloneTyped))->FUN_00d4f270((*(bool *)&(const ::hkBool &)(flag)));
        break;
    }
    case 2: {
        SourceDataB* s = (SourceDataB*)data;
        CloneDataB* pCloneTyped = ((::CloneDataB *)(new ((void *)(((CloneDataB*)hkAlloc(0xa0)))) ::FUN_00d52fc0()));
        clone = pCloneTyped;
        pCloneTyped->unk20 = s->unk20;
        pCloneTyped->unk30 = s->unk30;
        pCloneTyped->unk40 = s->unk40;
        pCloneTyped->unk50 = s->unk60;
        pCloneTyped->unk60 = s->unk70;
        pCloneTyped->unk70 = s->unk80;
        pCloneTyped->unk80.unk00 = s->unkc0.unk00;
        pCloneTyped->unk80.unk04 = s->unkc0.unk04;
        pCloneTyped->unk80.unk08 = s->unkc0.unk08;
        pCloneTyped->unk80.unk0c = s->unkc0.unk0c;
        pCloneTyped->unk80.unk10 = s->unkc0.unk10;
        break;
    }
    case 18:
    case 19:
        reinterpret_cast<::FUN_00c90510_class *>((apSource))->FUN_00c90510();
        return apSource;
    default:
        return 0;
    }
    Instance* pInstanceMem = (Instance*)hkAlloc(0x38);
    int iPriority = apSource->unk1c;
    void* eb = apSource->unk18;
    void* ea = apSource->unk14;
    Instance* pInstance = ((::Instance *)(new ((void *)(pInstanceMem)) ::FUN_00cf3ea0((::ConstraintEntity *)(ea), (::ConstraintEntity *)(eb), (::ConstraintData *)(clone), (::ConstraintPriority)(iPriority))));
    reinterpret_cast<::hkReferencedObjectC905 *>((clone))->FUN_00c905b0();
    return pInstance;
}

class FnvSink
{
  public:
    virtual void Slot0() throw();
    virtual void Slot1() throw();
    virtual void Slot2() throw();
    virtual void Write(int level, unsigned int hash, const char* msg, const char* file, int line) throw();
};


class MsgWriter
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

class FnvInner
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1C() throw();
    virtual unsigned int GetKind() throw();

    char unk04[0x0c];
    __m128 m_20;
    __m128 m_30;
    char unk40[0x10];
    __m128 m_50;
    char unk60[0x30];
    __m128 m_90;
};

class FnvHolder
{
  public:
    char unk00[0x0c];
    FnvInner* m_0c;
};

// Reads the inner constraint's kind and copies two __m128 vectors into a1/a2, or logs an unsupported-type error and returns 1.
// @fnv 0x00e5ad40
int FUN_00e5ad40(FnvHolder* pHolder, __m128* pOutA, __m128* pOutB)
{
    FnvInner* inner = pHolder->m_0c;

    switch (inner->GetKind())
    {
    case 0:
        *pOutA = inner->m_20;
        *pOutB = inner->m_30;
        return 0;
    case 1:
        *pOutA = inner->m_50;
        *pOutB = inner->m_90;
        return 0;
    case 2:
        *pOutA = inner->m_50;
        *pOutB = inner->m_90;
        return 0;
    case 7:
        *pOutA = inner->m_50;
        *pOutB = inner->m_90;
        return 0;
    }

    MsgWriter writer;
    unsigned int bufStorage[0x80];
    char* buf = (char*)bufStorage;
    new ((void *)&(writer)) ::FUN_00cb1600(buf, 0x200);
    reinterpret_cast<::SinkOwner *>(&(writer))->FUN_00cc01c0("Unsupported type of constraint in prepareSystemForRagdoll()");
    (*reinterpret_cast<::FnvSink * *>(&::DAT_01268360))->Write(1, 0xabbabf3b, buf, ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 0xe2);
    reinterpret_cast<struct ::FUN_00cc00e0 *>(&(writer))->FUN_00cc00e0::~FUN_00cc00e0();
    return 1;
}

namespace fnv_00e5ae60 {
struct S_00e5ae60_Stream
{
    int unk00;
    int unk04;
    int unk08;
    S_00e5ae60_Stream(char* buf, int size) throw();
    ~S_00e5ae60_Stream() throw();
};

struct S_00e5ae60_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int FUN_message(int type, int id, const char* text, const char* file, int line) throw();
};

struct S_00e5ae60_Constraint
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType() throw();
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
    int m_b0;
};

// Reads motor values from the constraint into a, b and d based on its type; for unsupported types logs an error and returns 1.
// @fnv 0x00e5ae60
int __cdecl GetConstraintMotorValues(S_00e5ae60_Constraint* pConstraint, int* piValueA, int* piValueB,
                                     int* piValueD) throw()
{
    switch (pConstraint->GetType())
    {
    case 2:
        *piValueA = pConstraint->m_b0;
        *piValueB = 0;
        *piValueD = 0;
        return 0;
    case 7:
        *piValueA = reinterpret_cast<::FUN_00cdea20_cls *>((pConstraint))->FUN_00cdea20();
        *piValueB = reinterpret_cast<::FUN_00cdea80_cls *>((pConstraint))->FUN_00cdea80();
        *piValueD = ((int)(reinterpret_cast<::FUN_00cdeaa0_cls *>((pConstraint))->FUN_00cdeaa0()));
        return 0;
    default:
        *piValueD = 0;
        *piValueB = 0;
        *piValueA = 0;
        {
            unsigned int buf[128];  // 512-byte text buffer (int array avoids a GS cookie)
            S_00e5ae60_Stream s((char*)buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&(s))->FUN_00cc01c0("This type of constraint does not have motors");
            (*reinterpret_cast<::fnv_00e5ae60::S_00e5ae60_Err * *>(&::DAT_01268360))->FUN_message(1, 0xabbae233, (const char*)buf,
                                      ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 0x104);
        }
        return 1;
    }
}
}  // namespace fnv_00e5ae60

// Moved from hkpconstraintutils_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_00ca8800_Class.h"
#include "fnv/symbols_00e5a000.h"
#include "fnv/symbols_simd.h"

struct Ent
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    __m128 unkf0;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    __m128 unk120;
    int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    int unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    __m128 unk1b0;
    __m128 unk1c0;
};

struct FnvHolder2 : FnvHolder
{
    int unk10;
    Ent* unk14;
    Ent* unk18;
};

struct Conv
{
    __m128 m;
    void FUN_00c7f640(__m128* src, __m128* arg);
};

// Constraint pivots followed by their transformed positions.
struct WorkVectors
{
    __m128 va;
    __m128 vb;
    Conv cb;
    Conv ca;
};


extern "C"
{
    const __m128 DAT_010ec7f0 = {1.0f, 1.0f, 1.0f, 1.0f};
    const float DAT_010959f4 = 1e-6f;
}

// @fnv 0x00e5af80
bool* FUN_00e5af80(bool* out, FnvHolder2* h, float t, float t2)
{
    float d;
    WorkVectors v;
    Ent* a;
    Ent* b;

    if (FUN_00e5ad40(h, &v.va, &v.vb) == 0)
    {
        {
            __m128 sq = _mm_mul_ps(v.va, v.va);
            __m128 lo = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
            __m128 hi = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), lo);
            _mm_store_ss(&d, hi);
        }
        if (d > DAT_010959f4)
        {
            char buf[0x200];
            MsgWriter w;
            new ((void *)&(w)) ::FUN_00cb1600(buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&(w))->FUN_00cc01c0("Pivot of child rigid body (A) is expected to be aligned with the constraint at setup time.");
            (*reinterpret_cast<::FnvSink * *>(&::DAT_01268360))->Write(1, 0xabba5dffu, buf, ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 285);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(w))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        b = h->unk18;
        a = h->unk14;
        v.cb.FUN_00c7f640(&b->unkf0, &v.vb);
        v.ca.FUN_00c7f640(&a->unkf0, &v.va);
        {
            __m128 cbv = v.cb.m;
            __m128 cav = v.ca.m;
            __m128 dd = _mm_sub_ps(cbv, cav);
            __m128 sq = _mm_mul_ps(dd, dd);
            __m128 lo = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
            __m128 hi = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), lo);
            _mm_store_ss(&d, hi);
        }
        if (d > t * t)
        {
            {
                __m128 t2v = _mm_set_ps1(t2);
                __m128 r = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t2v), v.cb.m),
                                      _mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&b->unk120)), t2v));
                reinterpret_cast<::FUN_00ca8800_Class *>((a))->FUN_00ca8800(reinterpret_cast<intptr_t>(&r));
            }
            reinterpret_cast<::FUN_005616d0_Owner *>((a))->OnTrigger((::TriggerContext *)(&b->unk1b0));
            reinterpret_cast<::FUN_00561800_Class *>((a))->FUN_00561800((::FUN_00561730_Obj *)(void *)(&b->unk1c0));
            *out = true;
            return out;
        }
    }
    *out = false;
    return out;
}

// Moved from hkpconstraintutils_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00cd5880_cls.h"
#include "fnv/decl/S_00cd4b60.h"
bool* FUN_00e5af80(bool* out, FnvHolder2* h, float t, float t2);


class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue(const __m128& x) : m_vValue(x)
    {}
    __forceinline VectorComponentValue(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    __m128 m_vValue;
};

class hkVector4
{
  public:
    __forceinline hkVector4()
    {}
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void addMul4(const VectorComponentValue& r, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline VectorComponentValue getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    __m128 m_vComponents;
};

class hkRotation;
class hkMatrix3
{
  public:
    __forceinline hkMatrix3()
    {}
    __forceinline hkVector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
class hkRotation : public hkMatrix3
{
  public:
    __forceinline hkRotation(const hkRotation& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
    }
};
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline hkVector4& getTranslation()
    {
        return m_vTranslation;
    }
};
struct hkpSetLocalTransformsConstraintAtom
{
    int unk00, unk04, unk08, unk0c;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
};
struct hkpMotionBase
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
    virtual void GetInertiaInvLocal(hkMatrix3& inertiaInv);
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
};
struct hkpMotion : hkpMotionBase
{
    hkVector4 m_vCenterOfMassLocal;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    hkVector4 m_kInertiaAndMassInv;
    __forceinline VectorComponentValue getMassInv() const
    {
        return m_kInertiaAndMassInv.getSimdAt3();
    }
};
struct hkpRigidBody
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
    hkpMotion m_pMotionState;
    __forceinline hkpMotion* getRigidMotion()
    {
        return &m_pMotionState;
    }
    __forceinline void GetInertiaInvLocal(hkMatrix3& m)
    {
        getRigidMotion()->GetInertiaInvLocal(m);
    }
    __forceinline float getMassInv()
    {
        return getRigidMotion()->getMassInv();
    }
    __forceinline const hkVector4& getCenterOfMassLocal()
    {
        return m_pMotionState.m_vCenterOfMassLocal;
    }
};

// @fnv 0x00e5a800
void __cdecl FUN_00e5a800(Instance* constraint)
{
    SourceData* data = constraint->unk0c;
    hkpSetLocalTransformsConstraintAtom* transformsAtom = 0;
    switch (data->getType())
    {
    case 1:
        transformsAtom = (hkpSetLocalTransformsConstraintAtom*)&data->unk10;
        break;
    case 2:
        transformsAtom = (hkpSetLocalTransformsConstraintAtom*)&data->unk10;
        break;
    default:
        return;
    }

    hkpRigidBody* bodyA = (hkpRigidBody*)constraint->unk14;
    hkpRigidBody* bodyB = (hkpRigidBody*)constraint->unk18;

    const bool useRelativeInertia = true;

    float invInertiaA = 0.0f;
    {
        hkMatrix3 inertiaLocA;
        bodyA->GetInertiaInvLocal(inertiaLocA);
        hkRotation invRot = transformsAtom->m_kBodyALocalFrame.getRotation();
        reinterpret_cast<::S_00cd4b60 *>(&(invRot))->FUN_00cd4b60();
        reinterpret_cast<::FUN_00cd5880_cls *>(&(inertiaLocA))->FUN_00cd5880(reinterpret_cast<uintptr_t>(&(invRot)));
        invInertiaA = float(inertiaLocA(1, 1) + inertiaLocA(2, 1)) + float(inertiaLocA(1, 2) + inertiaLocA(2, 2));
        if (useRelativeInertia && bodyA->getMassInv() > 1.192092896e-07f)
        {
            invInertiaA /= bodyA->getMassInv();
        }
    }

    float invInertiaB = 0.0f;
    {
        hkMatrix3 inertiaLocB;
        bodyB->GetInertiaInvLocal(inertiaLocB);
        hkRotation invRot = transformsAtom->m_kBodyBLocalFrame.getRotation();
        reinterpret_cast<::S_00cd4b60 *>(&(invRot))->FUN_00cd4b60();
        reinterpret_cast<::FUN_00cd5880_cls *>(&(inertiaLocB))->FUN_00cd5880(reinterpret_cast<uintptr_t>(&(invRot)));
        invInertiaB = float(inertiaLocB(1, 1) + inertiaLocB(2, 1)) + float(inertiaLocB(1, 2) + inertiaLocB(2, 2));
        if (useRelativeInertia && bodyB->getMassInv() > 1.192092896e-07f)
        {
            invInertiaB /= bodyB->getMassInv();
        }
    }

    hkVector4& axisA = transformsAtom->m_kBodyALocalFrame.getRotation().getColumn(0);
    hkVector4 pivotA;
    pivotA.setSub4(transformsAtom->m_kBodyALocalFrame.getTranslation(), bodyA->getCenterOfMassLocal());
    float pivotLengthAlongAxisA = pivotA.dot3(axisA);

    hkVector4& axisB = transformsAtom->m_kBodyBLocalFrame.getRotation().getColumn(0);
    hkVector4 pivotB;
    pivotB.setSub4(transformsAtom->m_kBodyBLocalFrame.getTranslation(), bodyB->getCenterOfMassLocal());
    float pivotLengthAlongAxisB = pivotB.dot3(axisB);

    float invSumInertias = 1.0f / (invInertiaA + invInertiaB);
    float totalPivotLengthAlongAxis = pivotLengthAlongAxisA - pivotLengthAlongAxisB;
    float newPivotLenghtAlongAxisA = totalPivotLengthAlongAxis * invInertiaB * invSumInertias;
    float newPivotLenghtAlongAxisB = -totalPivotLengthAlongAxis * invInertiaA * invSumInertias;

    pivotA.addMul4(newPivotLenghtAlongAxisA - pivotLengthAlongAxisA, axisA);
    pivotB.addMul4(newPivotLenghtAlongAxisB - pivotLengthAlongAxisB, axisB);

    transformsAtom->m_kBodyALocalFrame.getTranslation().setAdd4(pivotA, bodyA->getCenterOfMassLocal());
    transformsAtom->m_kBodyBLocalFrame.getTranslation().setAdd4(pivotB, bodyB->getCenterOfMassLocal());
}
