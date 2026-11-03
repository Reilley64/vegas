
// src/staging/blk_00c80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C68D50World.h"
#include "fnv/decl/EntityOwner_c87b.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004ee840_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00a6d730_shell.h"
#include "fnv/decl/FUN_00ba87d0_Class.h"
#include "fnv/decl/FUN_00c6aca0.h"
#include "fnv/decl/FUN_00c6b320_Class.h"
#include "fnv/decl/FUN_00c6b730_cls.h"
#include "fnv/decl/FUN_00c6b980_cls.h"
#include "fnv/decl/FUN_00c71120.h"
#include "fnv/decl/FUN_00c7fc60_cls.h"
#include "fnv/decl/FUN_00c878c0_cls.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c9bff0_Class.h"
#include "fnv/decl/FUN_00ca86c0_class.h"
#include "fnv/decl/FUN_00ca9360_cls.h"
#include "fnv/decl/FUN_00caa140_cls.h"
#include "fnv/decl/FUN_00cf3ea0.h"
#include "fnv/decl/FUN_00cf4490_cls.h"
#include "fnv/decl/FUN_00cf4ce0_class.h"
#include "fnv/decl/FUN_00cf4d30_class.h"
#include "fnv/decl/FUN_00d065e0.h"
#include "fnv/decl/FUN_00d08130.h"
#include "fnv/decl/FloatMatrix3.h"
#include "fnv/decl/GeomNormals.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiTimeControllerCM.h"
#include "fnv/decl/NiTimeController_Luna.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/ProjectileListener.h"
#include "fnv/decl/QueueManager.h"
#include "fnv/decl/ReportOwner.h"
#include "fnv/decl/S00c87a70_Obj.h"
#include "fnv/decl/S00c92a80_cls.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/S_00c6b760_Cls.h"
#include "fnv/decl/SerializableCF42.h"
#include "fnv/decl/SerializableCF44.h"
#include "fnv/decl/SerializedObject.h"
#include "fnv/decl/SerializedRecord.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/Stub65800.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/WorldWithPending.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c65b00__CollisionSync.h"
#include "fnv/decl/fnv_00c99eb0__FUN_00c99eb0.h"
#include "fnv/decl/fnv_00cd2fd0__Object.h"
#include "fnv/decl/hkMultiThreadCheckCF6E.h"
#include "fnv/decl/hkObjCF46.h"
#include "fnv/decl/hkPListShape.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a6c000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a81000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c65000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6b000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00c81000.h"
#include "fnv/symbols_00c82000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c88000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c92000.h"
#include "fnv/symbols_00c9b000.h"
#include "fnv/symbols_00cb7000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_00ce0000.h"
#include "fnv/symbols_00cf0000.h"
#include "fnv/symbols_00cf1000.h"
#include "fnv/symbols_00cf6000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01056000.h"
#include "fnv/symbols_01066000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011b0000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"
#include <xmmintrin.h>

struct Scene892;
struct SharedBody;
struct Shape892
{
    int unk00, unk04;
    Scene892* scene;
    unsigned short flags;
    unsigned short unk0E;
    SharedBody* body;
    int unk14;
    float scale18, scale1C;
    int mode;
    struct Pair
    {
        volatile int first, second;
        Pair& operator=(const Pair& other)
        {
            first = other.first;
            second = other.second;
            return *this;
        }
    } values;
    void FUN_00c89050(int, intptr_t, intptr_t, int);
    void FUN_00c892c0(intptr_t, intptr_t, intptr_t, Shape892*, int);
};

extern int DAT_010c53dc;
extern int DAT_01267e60;

struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};

struct FUN_00c81550_holder
{
    void FUN_00c81550();
};

struct FUN_00c82580_result
{
    char pad[0x18];
    float m_fValue;
};

// Calls FUN_00c81c50 on arg and returns the float m_fValue of the result, or 1.0f if the result is null.
// @fnv 0x00c82580
float FUN_00c82580(void* arg)
{
    void* p = ::FUN_00c81c50((::S00c81c50_Obj *)(arg));
    return p ? static_cast<FUN_00c82580_result*>(p)->m_fValue : 1.0f;
}

extern int DAT_011b09d8[];

// Copies the three ints of entry a from DAT_011b09d8 into the buffer c.
// @fnv 0x00c84cd0
struct FUN_00c84cd0_entry
{
    int a;
    int b;
    int c;
};

void __cdecl FUN_00c84cd0(int aiIndex, void* apOut)
{
    int* p = &DAT_011b09d8[aiIndex * 3];
    FUN_00c84cd0_entry* out = static_cast<FUN_00c84cd0_entry*>(apOut);
    out->a = p[0];
    out->b = p[1];
    out->c = p[2];
}

struct bhkRefObject
{
};
struct bhkBoxShape
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    void FUN_00c84e50(bool b);
};
struct NiStream;
class NiRTTI;
struct NiObject
{
    virtual void LinkObject(NiStream&);
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
struct FUN_00c87670_Class;
struct FUN_00c87670_vtable
{
    void* slots[44];
    void (*LinkField)(FUN_00c87670_Class*, void*);
};
struct FUN_00c87670_Class : NiObject
{
    void FUN_00c87670(NiStream& stream);
    void* m_pad_0x4;
    void* m_pad_0x8;
    void* m_field_0xc;
};
// @fnv 0x00c87670
void FUN_00c87670_Class::FUN_00c87670(NiStream& stream)
{
    ::FUN_00a89af0((std::intptr_t)this);
    if (m_field_0xc)
        (*reinterpret_cast<FUN_00c87670_vtable**>(this))->LinkField(this, m_field_0xc);
}

struct FUN_00c88a20_cls
{
    void FUN_00c88930();
    void* FUN_00c88a20(unsigned int flags);
};
struct FUN_00cf4ce0_cls
{
};

struct FUN_00c8aa40_cls
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    void FUN_00c8aa40(int* arg);
};

// @fnv 0x00c8aa40
void FUN_00c8aa40_cls::FUN_00c8aa40(int* pOther)
{
    if (this && m_p8)
        reinterpret_cast<::FUN_00cf4ce0_class *>((reinterpret_cast<FUN_00cf4ce0_cls*>(m_p8)))->FUN_00cf4ce0(reinterpret_cast<FUN_00c8aa40_cls*>(pOther)->m_p8);
}

// @fnv 0x00c8cce0
char FUN_00c8cce0(int* piValue)
{
    char result = 0;
    int v = *piValue;
    if (v > 0 && (v <= 3 || v == 6))
        result = 1;
    return result;
}

struct MemoryManager
{
    void Deallocate(void*);
};
// The byte before an aligned block holds the distance back to the start of its allocation.
struct FUN_00c8cd00_prefix
{
    unsigned char m_ucOffset;
};

// @fnv 0x00c8cd00
void FUN_00c8cd00(void* apBlock)
{
    if (apBlock)
    {
        const FUN_00c8cd00_prefix* prefix = static_cast<const FUN_00c8cd00_prefix*>(apBlock) - 1;
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060((char*)apBlock - prefix->m_ucOffset);
    }
}

struct C9A6E0Entry;
struct C9A6E0Array
{
    int unk00;
    C9A6E0Entry* m_pkEntryArray;
    int unk08;
    unsigned int m_uiCount;
    unsigned int m_uiAllocatedCapacity;
    void FUN_00c9a6e0();
};

struct FUN_00c9a820_class
{
    char pad[0x38];
    C9A6E0Array m_kArray;
    int unk4c;
    float m_f50;
    float m_f54;
    int m_i58;
    void Reset();
};

void __cdecl FUN_00c9ad60();
void __cdecl _delete(void* ptr, unsigned int size);
struct FUN_00c9af20_class
{
    void FUN_00c9ad60();
    void* FUN_00c9af20(int flag);
};
extern void(* DAT_010c53bc)(int*);
struct FUN_00c80630_holder
{
    int* m_vtbl;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void ResetHolder();
};
// @fnv 0x00c80630
void FUN_00c80630_holder::ResetHolder()
{
    int* old = m_p4;
    m_vtbl = (int*)&DAT_010c53b4;
    if (old)
    {
        DAT_010c53bc(old);
        m_p4 = 0;
        m_pc = 0;
        m_p8 = 0;
    }
}

struct FUN_00c81640_cls
{
    void* FUN_00c81640(bool flag);
};

struct NiPoint3
{
    float x, y, z;
public:
    char *FUN_00a59af0(const char *);
public:
    static const ::NiPoint3 ZERO;
};
struct FUN_00c84ec0_object
{
    char pad[0x10];
    NiPoint3 m_kPoint;
};

// Checks whether the object's m_kPoint equals DAT_011a9490 and returns 1 if so, otherwise 0.
// @fnv 0x00c84ec0
int FUN_00c84ec0(void* apObject)
{
    NiPoint3* v = &static_cast<FUN_00c84ec0_object*>(apObject)->m_kPoint;
    if (v->x == DAT_011a9490.x && v->y == DAT_011a9490.y && v->z == DAT_011a9490.z)
        return 1;
    return 0;
}

extern CRITICAL_SECTION DAT_0126813c;
// @fnv 0x00c876f0
void FUN_00c876f0()
{
    EnterCriticalSection(&DAT_0126813c);
}

extern int DAT_010c69f4;
struct FUN_00c6aca0_holder
{
};
struct FUN_00c9a040_cls
{
    void* FUN_00c9a040(bool b);
};
// @fnv 0x00c9a040
void* FUN_00c9a040_cls::FUN_00c9a040(bool abFree)
{
    *(void**)this = (void*)&DAT_010c69f4;
    reinterpret_cast<::FUN_00c6aca0 *>((((FUN_00c6aca0_holder*)this)))->FUN_00c6aca0::~FUN_00c6aca0();
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this - *(unsigned char*)(this - 1));
    return this;
}

__forceinline int Sign_00c9a070(float f)
{
    return f < 0.0f ? -1 : 1;
}

struct Range_00c9a070
{
    float fHi;
    float fLo;
    Range_00c9a070(float h, float l) : fHi(h), fLo(l)
    {}
};

__forceinline void Adjust_00c9a070(float& out, float v, float fHi, float fLo)
{
    Range_00c9a070 r(fHi, fLo);
    float s = (float)Sign_00c9a070(v);
    float t = v + (r.fHi - r.fLo) * s;
    if (t * s > 0.0f)
        out -= t;
}

struct FUN_00c9a070_shell
{
    char _pad0[0xa0];
    float fLo[3];
    char _padac[0x14];
    float fHi[3];
    void AdjustVector(float* p);
};

// Adjusts each of the three components of p using the corresponding fHi/fLo bounds via Adjust_00c9a070.
// @fnv 0x00c9a070
void FUN_00c9a070_shell::AdjustVector(float* afVector)
{
    Adjust_00c9a070(afVector[0], afVector[0], fHi[0], fLo[0]);
    Adjust_00c9a070(afVector[1], afVector[1], fHi[1], fLo[1]);
    Adjust_00c9a070(afVector[2], afVector[2], fHi[2], fLo[2]);
}

namespace fnv_00c9a2c0 {
struct hkVector4
{
    float v[4];
};
struct NiPoint3
{
    float x, y, z;
};

struct StrArr
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct MemContextScope
{
    int iSaved;
    MemContextScope(int aiMemoryContext)
    {
        iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~MemContextScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = iSaved;
    }
};

struct FUN_00c9a2c0_shell
{
    char _pad0[0xa0];
    hkVector4 kWorldTotalSize;
    hkVector4 kBorderSize;
    void AppendWorldSizeStrings(StrArr* pkStrings);
};

// @fnv 0x00c9a2c0
void FUN_00c9a2c0_shell::AppendWorldSizeStrings(StrArr* pkStrings)
{
    MemContextScope kScope(0x10);
    reinterpret_cast<::ReportOwner *>(this)->AppendReport((::StrArr *)(pkStrings));
    char* pcString = ::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_012681e8)));
    pkStrings->Add(pcString);
    NiPoint3 kPoint;
    ::SetNiPoint3FromHkVector4((::NiPoint3 &)(kPoint), (const ::hkVector4 &)(kWorldTotalSize));
    pcString = reinterpret_cast<::NiPoint3 *>(&(kPoint))->FUN_00a59af0("WorldTotalSize");
    pkStrings->Add(pcString);
    ::SetNiPoint3FromHkVector4((::NiPoint3 &)(kPoint), (const ::hkVector4 &)(kBorderSize));
    pcString = reinterpret_cast<::NiPoint3 *>(&(kPoint))->FUN_00a59af0("BorderSize");
    pkStrings->Add(pcString);
}
}  // namespace fnv_00c9a2c0

extern int DAT_010c6b04;
extern "C" void __cdecl NiFree(void*);
struct FUN_00c9ae80_class
{
    void* m_p0;
    void* m_p4;
    void* FUN_00c9ae80(unsigned char b);
};
// Sets m_p0 to DAT_010c6b04, frees m_p4 with NiFree, and if bit 0 of b is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00c9ae80
void* FUN_00c9ae80_class::FUN_00c9ae80(unsigned char abFree)
{
    void* p = m_p4;
    m_p0 = &DAT_010c6b04;
    NiFree(p);
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00c80660_t
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void* FUN_00c80660(bool b);
};

// @fnv 0x00c80660
void* FUN_00c80660_t::FUN_00c80660(bool abFree)
{
    int* p = m_p4;
    m_p0 = &DAT_010c53b4;
    if (p)
    {
        DAT_010c53bc(p);
        m_p4 = 0;
        m_pc = 0;
        m_p8 = 0;
    }
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00c9aeb0_t
{
    char m_data[0x5c];
    FUN_00c9aeb0_t();
    ~FUN_00c9aeb0_t();
};
// Allocates and constructs a new FUN_00c9aeb0_t object, returning its pointer.
// @fnv 0x00c9b020
FUN_00c9aeb0_t* FUN_00c9b020()
{
    return new FUN_00c9aeb0_t;
}

struct FUN_00c9eba0_IFace
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
    virtual void FUN_00c9eba0_call(intptr_t a, intptr_t b, intptr_t c, int d);
};
struct ScriptX
{
    void* unk00;
    void* unk04;
    FUN_00c9eba0_IFace* m_pIFace;
    void InvokeInterfaceCall(intptr_t a, intptr_t b, intptr_t c, int d);
};
extern CRITICAL_SECTION DAT_0126820c;
// @fnv 0x00c9eba0
void ScriptX::InvokeInterfaceCall(intptr_t aiArg1, intptr_t aiArg2, intptr_t aiArg3, int aiArg4)
{
    if (this)
    {
        FUN_00c9eba0_IFace* iface = m_pIFace;
        if (iface)
        {
            EnterCriticalSection(&DAT_0126820c);
            ::FUN_00a29680();
            iface->FUN_00c9eba0_call(aiArg1, aiArg2, aiArg3, aiArg4);
            ::FUN_00a29680();
            LeaveCriticalSection(&DAT_0126820c);
        }
    }
}

struct A51BF0Base
{
};

struct FUN_00c6b910 : A51BF0Base
{
    FUN_00c6b910();
};

struct bhkBlendCollisionObject : FUN_00c6b910
{
    void* m_vtbl;
    unsigned char m_pad_04[8];
    unsigned short m_flags;
    unsigned char m_pad_0e[6];
    unsigned char m_flag14;
    unsigned char m_pad_15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;


    bhkBlendCollisionObject()
    {
        m_vtbl = &DAT_010c53dc;
        ++DAT_01267e60;
        m_f18 = 0.0f;
        m_flags &= 0xfeff;
        m_f1c = 1.0f;
        m_i20 = 8;
        m_i24 = 0;
        m_i28 = 0;
        m_flag14 = 0;
    }

    bhkBlendCollisionObject* FUN_00c81670(int value);
};

// @fnv 0x00c81670
bhkBlendCollisionObject* bhkBlendCollisionObject::FUN_00c81670(int value)
{
    bhkBlendCollisionObject* p = new bhkBlendCollisionObject;

    ::FUN_00c657f0();

    p->m_f1c = this->m_f1c;
    p->m_f18 = this->m_f18;
    p->m_i24 = this->m_i24;

    return p;
}

namespace fnv_00c81730 {
struct A51BF0Base
{
    int* m_vtbl;
    int m_pad4;
    int m_pad8;
    unsigned short m_flags;
    unsigned char m_pad10;
    char m_pad11[3];

};

struct FUN_00c6b910_cls
{
    void FUN_00c6b910();
};

struct bhkBlendCollisionObject : A51BF0Base
{
    unsigned char m_flag14;
    char m_pad15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;

    bhkBlendCollisionObject()
    {
        ::FUN_00c6b910((void *)(reinterpret_cast<FUN_00c6b910_cls*>(this)));
        m_vtbl = reinterpret_cast<int*>(&DAT_010c53dc);
        ++DAT_01267e60;
        m_f18 = 0.0f;
        m_flags &= 0xfeff;
        m_f1c = 1.0f;
        m_i20 = 8;
        m_i24 = 0;
        m_i28 = 0;
        m_flag14 = 0;
    }
};

// Allocates and constructs a new bhkBlendCollisionObject, returning the pointer.
// @fnv 0x00c81730
bhkBlendCollisionObject* CreateBlendCollisionObject()
{
    return new bhkBlendCollisionObject;
}
}  // namespace fnv_00c81730

struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const* str);
};

extern int _data_011c16bc;

struct DynCastHelper
{
};

struct GetFloatProperty_object
{
    char pad[0x1c];
    DynCastHelper* m_spCollisionObject;
};


// The global string table stores a reference count and the length before each string.
struct StringHolderHeader
{
    long m_lRefCount;
    unsigned int m_uiLength;
};

struct StringHolder
{
    char* p;

    StringHolder(char const* str) : p(NiGlobalStringTable::AddString(str))
    {}

    ~StringHolder()
    {
        if (p != ::DAT_0109b220)
        {
            InterlockedDecrement(&(reinterpret_cast<StringHolderHeader*>(p) - 1)->m_lRefCount);
        }
    }
};

// Looks up a named node under param_1, dynamic-casts its collision object to Shape892, and returns its scale18, defaulting to 1.0f.
// @fnv 0x00c81b90
float GetFloatProperty(intptr_t aiObject, char const* apName)
{
    float result = 1.0f;

    if (aiObject != 0)
    {
        GetFloatProperty_object* object;

        if (apName != 0)
        {
            {
                StringHolder str(apName);
                object = ((GetFloatProperty_object *)(::FUN_00c4b470((::FUN_00c4b470_owner *)(aiObject), (void **)(&str.p), 0)));
            }

            if (object == 0)
            {
                object = reinterpret_cast<GetFloatProperty_object*>(aiObject);
            }
        }
        else
        {
            object = reinterpret_cast<GetFloatProperty_object*>(aiObject);
        }

        DynCastHelper* field = object->m_spCollisionObject;

        if (field != 0)
        {
            NiObject* casted = reinterpret_cast<::NiObject *>((reinterpret_cast<DynCastHelper*>(field)))->DynamicCast(
                (const ::NiRTTI *)(const unsigned int *)(reinterpret_cast<unsigned int const*>(&(*reinterpret_cast<const char *const *>(&::g_01267e64)))));

            if (casted != 0)
            {
                result = reinterpret_cast<Shape892*>(casted)->scale18;
            }
        }
    }

    return result;
}

struct FUN_00c85ec0_target;
struct FUN_00c85ec0_vtable
{
    void* slots[54];
    void (*Call)(FUN_00c85ec0_target*);
};
struct FUN_00c85ec0_target
{
    FUN_00c85ec0_vtable* vtable;
};
struct FUN_00c85ec0_mid
{
    char pad[8];
    FUN_00c85ec0_target* m_08;
};
struct FUN_00c85ec0_outer
{
    char pad[0x10];
    FUN_00c85ec0_mid* m_10;
};
struct FUN_00c85ec0_t
{
    int* m_p0;
    int* m_p4;
    FUN_00c85ec0_outer* m_p8;
    int* m_pc;
    void CallVirtualOnNestedPointer();
};
// Follows m_p8 to a nested pointer chain and, if the final object exists, calls its vtable slot 54 (byte offset 0xd8 on x86).
// @fnv 0x00c85ec0
void FUN_00c85ec0_t::CallVirtualOnNestedPointer()
{
    if (this && m_p8)
    {
        FUN_00c85ec0_mid* q = m_p8->m_10;
        if (q && q->m_08)
        {
            FUN_00c85ec0_target* r = q->m_08;
            r->vtable->Call(r);
            return;
        }
    }
}

struct NiObjLB
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void LoadBinary(NiStream& stream);
};

struct FUN_00c87650_t : NiObjLB
{
    virtual void LoadBinary(NiStream& stream);
};

// Calls the base NiObjLB::LoadBinary, then dispatches virtual slot 43 on this with the stream.
// @fnv 0x00c87650
void FUN_00c87650_t::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    ((void(*)(void*, NiStream&))(*(void***)this)[43])(this, stream);
}

// @fnv 0x00c87700
void FUN_00c87700()
{
    LeaveCriticalSection(&DAT_0126813c);
}

struct FUN_00c88410_t
{
    void* FUN_00c88410(unsigned int flags);
};

// Calls FUN_00caa140, then deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x00c88410
void* FUN_00c88410_t::FUN_00c88410(unsigned int flags)
{
    reinterpret_cast<::FUN_00caa140_cls *>(this)->FUN_00caa140_cls::~FUN_00caa140_cls();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

// @fnv 0x00c899c0
int FUN_00c899c0(char* p, int edx)
{
    p = *(char**)(p + 8);
    int r = 0;
    if (p)
        r = *(int*)(p + 0x18);
    return r;
}

struct FUN_00c8a7e0_t
{
    void FUN_00c8a720();
    void* FUN_00c8a7e0(bool b);
};
struct FUN_00cf4d30_holder
{
};
struct FUN_00c8aa60_holder
{
    int* m_auiShapeKeys;
    int* m_pAuxiliaryObject;
    int* m_target;
    void FUN_00c8aa60(void* arg);
};
// @fnv 0x00c8aa60
void FUN_00c8aa60_holder::FUN_00c8aa60(void* arg)
{
    if (this && m_target)
    {
        void** p = (void**)arg;
        reinterpret_cast<::FUN_00cf4d30_class *>((((FUN_00cf4d30_holder*)m_target)))->SetRefObject(p[2]);
    }
}

struct H_00c8c810
{
    void ReleaseReferencedObjects();
    void FUN_00c8b410(bool b);
};
namespace fnv_00c8c090 {
struct A51BF0Base
{
};

struct S_00cb79d0_Base : public A51BF0Base
{
    S_00cb79d0_Base();
    int* volatile m_p0;
    int m_p4;
    int m_p8;
};


struct Object_00c8c090 : public S_00cb79d0_Base
{
    int m_iThirdValue;
    int m_10;

    Object_00c8c090()
    {
        m_p0 = (int*)&::DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++::DAT_012680f8;
        m_p0 = (int*)&(*reinterpret_cast<int *>(&::DAT_01066d44));
        ++(*reinterpret_cast<int *>(&::DAT_012681b0));
    }

    ~Object_00c8c090()
    {}
};

// Allocates and constructs a new Object_00c8c090, returning it as an S_00cb79d0_Base pointer.
// @fnv 0x00c8c090
S_00cb79d0_Base* FUN_00c8c090()
{
    return new Object_00c8c090;
}
}  // namespace fnv_00c8c090

struct FUN_00c9d890_t
{
    int* m_p0;
    FUN_00c9d890_t(char b);
    ~FUN_00c9d890_t();
};
// Sets m_p0 to point at DAT_010c6fb0 and, if bit 0 of b is set, deletes this object.
// @fnv 0x00c9d890
FUN_00c9d890_t::FUN_00c9d890_t(char abDelete)
{
    m_p0 = &DAT_010c6fb0;
    if (abDelete & 1)
        ::FUN_00401030(this);
}


struct ScopedMemoryCategory
{
    unsigned int previous;
    ScopedMemoryCategory() : previous(::currentAllocationContext)
    {
        ::currentAllocationContext = 16;
    }
    ~ScopedMemoryCategory()
    {
        ::currentAllocationContext = previous;
    }
};

struct ArenaAllocator
{
    virtual void Reserved();
    virtual char* Allocate(unsigned int bytes);
};

struct ArenaMemoryManager : MemoryManager
{
    void* Allocate(unsigned int bytes);
};

struct TemporaryArena
{
    char* start;
    char* cursor;
    char* end;
    ArenaAllocator* current;
    ArenaAllocator* allocator;
    unsigned int unk14;
    ArenaAllocator* saved;
    unsigned int unk1C;
    unsigned int unk20;
    TemporaryArena();
};

struct ArenaRegistrationFlag
{
    unsigned int value;
    ArenaRegistrationFlag() : value(1)
    {}
    ArenaRegistrationFlag(const ArenaRegistrationFlag& other) : value(other.value)
    {}
};

struct ArenaRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Register(TemporaryArena*, const char*, ArenaRegistrationFlag);
};

extern const char DAT_010c53c4[];
extern CRITICAL_SECTION DAT_01267e48;

struct ArenaOwner
{
    TemporaryArena* arena;
    char* buffer;
};

// If owner->arena is null, allocates a 0x5000-byte arena under a critical section, registers and initialises it, and stores it in owner->arena.
// @fnv 0x00c80130
void EnsureArenaAllocated(ArenaOwner* owner)
{
    ScopedMemoryCategory category;
    if (!owner->arena)
    {
        EnterCriticalSection(&DAT_01267e48);
        TemporaryArena scratch;
        TemporaryArena* arena = new TemporaryArena;
        ((::ArenaRegistry *)(::FUN_00cbbfc0()))->Register(arena, DAT_010c53c4, ArenaRegistrationFlag());
        ::FUN_00cbb930(arena);
        arena->current = arena->allocator;
        arena->saved = arena->allocator;
        arena->start = arena->cursor = owner->buffer = arena->allocator->Allocate(0x5000);
        arena->end = arena->start + 0x5000;
        owner->arena = arena;
        LeaveCriticalSection(&DAT_01267e48);
    }
}

struct FlaggedObj_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct WalkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FlaggedObj_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// @fnv 0x00c80330
void SetFlagRecursive(bool abSet, WalkNode_cls* node)
{
    FlaggedObj_cls* f = node->m_1c;
    if (f != 0)
    {
        if (abSet)
        {
            f->m_0c |= 0x20;
        }
        else
        {
            f->m_0c &= 0xffdf;
        }
    }

    WalkNode_cls* child = node->v03();
    if (child != 0)
    {
        unsigned int i = 0;
        while (i < child->m_a6)
        {
            WalkNode_cls** arr = child->m_a0;
            WalkNode_cls* item = arr[i];
            if (item != 0)
            {
                SetFlagRecursive(abSet, item);
            }
            ++i;
        }
    }
}

class AnimIdle
{
  public:
    virtual void FUN_00c80570_slot0();
    virtual void FUN_00c80570_slot1();
    long refs;
    void IncRefCount();
    void DecRefCount();
};
struct MM
{
    void Deallocate(void* mem);
};
struct GlobalObject_004ee810
{
    ~GlobalObject_004ee810();
};
struct FUN_00c80570_Node
{
    NiPointer<AnimIdle> key;
    FUN_00c80570_Node* next;
    void RemoveNode(const NiPointer<AnimIdle>* keyp);
};
// @fnv 0x00c80570
void FUN_00c80570_Node::RemoveNode(const NiPointer<AnimIdle>* apKey)
{
    AnimIdle* k = apKey->m_pObject;
    if (!k)
        return;
    FUN_00c80570_Node* nx = next;
    if (!nx && !key.m_pObject)
        return;
    FUN_00c80570_Node* cur = this;
    FUN_00c80570_Node* prev = this;
    do
    {
        if (cur->key.m_pObject == k)
            break;
        prev = cur;
        cur = cur->next;
    } while (cur);
    if (!cur)
        return;
    if (cur == this)
    {
        if (nx)
        {
            next = nx->next;
            key = nx->key;
            nx->next = 0;
            reinterpret_cast<::FUN_004ee840_cls *>((reinterpret_cast<GlobalObject_004ee810*>(nx)))->FUN_004ee840_cls::~FUN_004ee840_cls();
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(nx);
            return;
        }
        AnimIdle* r = key.m_pObject;
        if (r)
        {
            if (InterlockedDecrement(&r->refs) == 0)
                r->FUN_00c80570_slot1();
            key.m_pObject = 0;
        }
        return;
    }
    prev->next = cur->next;
    cur->next = 0;
    reinterpret_cast<::FUN_004ee840_cls *>((reinterpret_cast<GlobalObject_004ee810*>(cur)))->FUN_004ee840_cls::~FUN_004ee840_cls();
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(cur);
}

struct SpawnedAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct SpawnedPtrArray
{
    void** m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};

extern "C" void _ReadWriteBarrier(void);

// Resolves an item from a1, grows arr by 4 if full, then stores the item at the next slot and increments the count.
// @fnv 0x00c809e0
void AppendSpawnedPtr(void* a1, SpawnedPtrArray* arr)
{
    void* item = ((void *)(::FUN_00c7fb50((::S_00c7fb50_portal *)(a1))));
    SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
    if (arr->m_uiCount == (arr->m_uiCapacity & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(arr), 4);
    }
    void** slot = (void**)((uintptr_t)arr->m_pData + arr->m_uiCount * 4);
    _ReadWriteBarrier();
    *slot = item;
    arr->m_uiCount++;
}

struct NiAllocator
{
};
struct RefObject
{
    int unk00;
    volatile long referenceCount;
};
struct RefNode
{
    RefObject* item;
    RefNode* next;
    __forceinline RefNode(RefObject* p)
    {
        item = p;
        if (p)
            InterlockedIncrement(&p->referenceCount);
        next = 0;
    }
};
struct RefOwner
{
    RefObject* item;
    RefNode* head;
    void FUN_006e5cc0(int* param);
    void FUN_00c80a30(int* param);
};
// If *param is set, prepends a RefNode holding item to head (when item exists) and calls FUN_006e5cc0(param).
// @fnv 0x00c80a30
void RefOwner::FUN_00c80a30(int* param)
{
    if (*param)
    {
        if (item)
        {
            void* memory = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::NiAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(8);
            RefNode* node = memory ? new (memory) RefNode(item) : 0;
            node->next = head;
            head = node;
            FUN_006e5cc0(param);
            return;
        }
        FUN_006e5cc0(param);
    }
}

struct FUN_00c80b20_item8
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct FUN_00c80b20_cls
{
    virtual void Slot0();
    virtual void* AllocBuffer(unsigned int count);
    virtual void FreeBuffer(void* buffer);
    FUN_00c80b20_item8* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    void InsertItemAt(unsigned int index, FUN_00c80b20_item8& item);
};

// Inserts an item at the given index, growing the buffer if full and shifting later items up by one slot.
// @fnv 0x00c80b20
void FUN_00c80b20_cls::InsertItemAt(unsigned int index, FUN_00c80b20_item8& item)
{
    if (index == m_uiLogicalSize)
    {
        unsigned int slot = reinterpret_cast<::FUN_00c7fc60_cls *>(this)->PushSlot();
        m_pBuffer[slot] = item;
        return;
    }
    if (m_uiLogicalSize == m_iReservedSize)
    {
        unsigned int newCap = m_iReservedSize > 0x400 ? m_iReservedSize + 0x400 : m_iReservedSize * 2;
        char* newBuf = (char*)AllocBuffer(newCap);
        ::FUN_00c7f900(newBuf, (char*)m_pBuffer, index);
        ::FUN_00c7f900(newBuf + index * 8 + 8, (char*)m_pBuffer + index * 8, m_uiLogicalSize - index);
        FreeBuffer(m_pBuffer);
        m_pBuffer = (FUN_00c80b20_item8*)newBuf;
        m_iReservedSize = newCap;
    }
    else
    {
        ::FUN_00c7f900((char*)m_pBuffer + index * 8 + 8, (char*)m_pBuffer + index * 8, m_uiLogicalSize - index);
    }
    m_uiLogicalSize++;
    m_pBuffer[index] = item;
}

// FUN_00c81570 : a one-line function - getter
// @fnv 0x00c81570
void* FUN_00c81570()
{
    return &(*reinterpret_cast<int *>(&::g_01267e64));
}

struct FUN_00c81580_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1C;
    int unk20;
    int m_i24;
    void FUN_00c81580(FUN_00c81580_cls* dest, void* other);
};

// @fnv 0x00c81580
void FUN_00c81580_cls::FUN_00c81580(FUN_00c81580_cls* dest, void* other)
{
    ::FUN_00c657f0();
    dest->m_f1C = m_f1C;
    dest->m_f18 = m_f18;
    dest->m_i24 = m_i24;
}

class C815B0Base
{
  public:
    bool IsEqual(C815B0Base* pkOther);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C815B0Constraint : public C815B0Base
{
  public:
    float m_fMinAngle;
    float m_fMaxAngle;

    bool FUN_00c815b0(C815B0Constraint* pkOther);
};

// Compares the base fields via C815B0Base::IsEqual, then checks that m_fMaxAngle and m_fMinAngle match the other constraint's values.
// @fnv 0x00c815b0
bool C815B0Constraint::FUN_00c815b0(C815B0Constraint* pkOther)
{
    bool bEqual = C815B0Base::IsEqual(pkOther);
    if (bEqual)
    {
        bEqual = pkOther->m_fMaxAngle == m_fMaxAngle;
        bEqual &= pkOther->m_fMinAngle == m_fMinAngle;
    }
    return bEqual;
}

extern int DAT_010c53dc;
extern int DAT_01267e60;

struct FUN_00c6b910_holder
{
    void FUN_00c6b910();
};

struct FUN_00c81600_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    float m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    FUN_00c81600_cls* Initialize();
};

// @fnv 0x00c81600
FUN_00c81600_cls* FUN_00c81600_cls::Initialize()
{
    ::FUN_00c6b910((void *)(reinterpret_cast<FUN_00c6b910_holder*>(this)));
    *(int**)this = &DAT_010c53dc;
    DAT_01267e60++;
    m_18 = 0.0f;
    m_1c = 1.0f;
    m_24 = 0;
    m_28 = 0;
    m_14 = 0;
    m_0c &= 0xfeff;
    m_20 = 8;
    return this;
}

struct C819A0Range
{
    float m_fMinimum;
    float m_fMaximum;
};


class C819A0Primary
{
  public:
    virtual ~C819A0Primary();

    int unk04;
    int unk08;
    int unk0C;
};

class C819A0Secondary
{
  public:
    virtual ~C819A0Secondary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiValue1;
};

class C819A0Object : public C819A0Primary, public C819A0Secondary
{
};

class C819A0Holder
{
  public:
    int unk00;
    int unk04;
    C819A0Object* m_pPointer;
};

class C819A0Base
{
  public:

    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    short unk0E;
    C819A0Holder* m_pkHolder;
    int unk14;
};

class C819A0Derived : public C819A0Base
{
  public:
    void InitFromFlags(void* pvParam);

    float m_fMinimum;
    float m_fMaximum;
};

// @fnv 0x00c819a0
void C819A0Derived::InitFromFlags(void* pvParam)
{
    ::FUN_00c65810();
    m_usFlags |= 0x28;

    C819A0Secondary* pkSecondary = m_pkHolder->m_pPointer;
    unsigned int uiFlags = pkSecondary ? pkSecondary->m_uiValue1 : 0;
    unsigned int uiIndex = (uiFlags >> 8) & 0x1f;
    m_fMinimum = g_akC819A0Ranges[uiIndex].m_fMinimum;
    m_fMaximum = g_akC819A0Ranges[uiIndex].m_fMaximum;
}

struct FUN_00c81aa0_collidable
{
    char pad[0x1c];
    unsigned int m_collisionFilterInfo;
};

struct FUN_00c81aa0_worldObject
{
    char pad[0x10];
    FUN_00c81aa0_collidable m_collidable;
};

class FUN_00c81aa0_poly
{
  public:
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
    virtual void v39(int a);
    int unk04;
    FUN_00c81aa0_worldObject* m_08;
};

class FUN_00c81aa0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_00c81aa0_poly* m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    int m_24;
    void FUN_00c81aa0();
};

// Reads a masked type from m_10's m_08 chain and, if it is 8 or 0x1d and m_24 is nonzero, calls the poly's v39 with m_24.
// @fnv 0x00c81aa0
void FUN_00c81aa0_cls::FUN_00c81aa0()
{
    FUN_00c81aa0_poly* p = m_10;
    if (p != 0)
    {
        FUN_00c81aa0_worldObject* object = p->m_08;
        unsigned int t = object != 0 ? object->m_collidable.m_collisionFilterInfo : 0;
        t &= 0x7f;
        if (t == 8 || t == 0x1d)
        {
            if (m_24 != 0)
            {
                p->v39(m_24);
            }
        }
    }
}

struct FUN_00c81ae0_target
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
    virtual void v39(void* arg);
    int unk04;
    FUN_00c81aa0_worldObject* m_08;
};

struct FUN_00c81ae0_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FUN_00c81ae0_target* m_10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* m_24;
    unsigned int m_28;

    void InitOnce();
};

struct TreeResult_cls
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual TreeResult_cls* v0f();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    struct TreeResultData* unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int m_24;
};

struct TreeHost_cls
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
};

struct TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual TreeNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TreeHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};


// Recursively stores value into the result's m_24 for node and all children found via v03 and m_a0.
// @fnv 0x00c81db0
void SetTreeValue(TreeNode_cls* node, unsigned int value)
{
    if (node == 0)
    {
        return;
    }

    TreeHost_cls* host = node->m_1c;
    if (host != 0)
    {
        TreeResult_cls* result = ((::TreeResult_cls *)(reinterpret_cast<::NiObject *>((host))->DynamicCast((const ::NiRTTI *)(unsigned int *)(&(*reinterpret_cast<unsigned int *>(&::g_012043f8))))));
        if (result != 0)
        {
            TreeResult_cls* r = result->v0f();
            if (r != 0)
            {
                r->m_24 = value;
            }
        }
    }

    TreeNode_cls* child = node->v03();
    if (child != 0)
    {
        for (unsigned int i = 0; i < child->m_a6; i++)
        {
            SetTreeValue(child->m_a0[i], value);
        }
    }
}


// Sets or clears the symmetric bits for uiA and uiB in selected_target_masks according to bSelected.
// @fnv 0x00c827f0
void SetSelectionMask(unsigned int uiIndexA, unsigned int uiIndexB, bool bSelected)
{
    if (bSelected)
    {
        selected_target_masks[uiIndexA] |= (unsigned __int64)1 << uiIndexB;
        selected_target_masks[uiIndexB] |= (unsigned __int64)1 << uiIndexA;
    }
    else
    {
        selected_target_masks[uiIndexA] &= ~((unsigned __int64)1 << uiIndexB);
        selected_target_masks[uiIndexB] &= ~((unsigned __int64)1 << uiIndexA);
    }
}

struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    NiColor(float fR, float fG, float fB) : r(fR), g(fG), b(fB)
    {}
};


// Writes the NiColor associated with the low 7 bits of layer into out, falling back to DAT_011a9b7c for unknown layers.
// @fnv 0x00c84470
void __cdecl GetLayerColor(unsigned int layer, NiColor& rColor)
{
    switch (layer & 0x7f)
    {
    case 1:
        rColor = NiColor(1.0f, 0.0f, 0.0f);
        break;
    case 2:
    case 10:
        rColor = NiColor(0.9f, 0.24f, 0.92f);
        break;
    case 3:
        rColor = NiColor(0.96f, 0.8f, 0.8f);
        break;
    case 4:
        rColor = NiColor(0.27f, 0.41f, 0.94f);
        break;
    case 5:
        rColor = NiColor(0.85f, 0.61f, 0.16f);
        break;
    case 6:
        rColor = NiColor(0.9f, 0.73f, 0.42f);
        break;
    case 7:
        rColor = NiColor(0.23f, 0.97f, 0.9f);
        break;
    case 8:
        rColor = NiColor(0.0f, 1.0f, 0.0f);
        break;
    case 9:
        rColor = NiColor(0.8f, 0.62f, 0.45f);
        break;
    case 11:
        rColor = NiColor(0.51f, 0.98f, 0.98f);
        break;
    case 12:
    case 14:
        rColor = NiColor(0.73f, 0.76f, 0.75f);
        break;
    case 16:
        rColor = NiColor(0.73f, 0.78f, 0.7f);
        break;
    case 13:
        rColor = NiColor(0.96f, 0.97f, 0.52f);
        break;
    case 17:
        rColor = NiColor(0.96f, 0.97f, 0.52f);
        break;
    case 18:
        rColor = NiColor(0.0f, 0.7f, 0.0f);
        break;
    case 30:
        rColor = NiColor(1.0f, 1.0f, 0.0f);
        break;
    case 31:
        rColor = NiColor(1.0f, 0.8f, 0.0f);
        break;
    case 24:
        rColor = NiColor(0.45f, 0.6f, 0.1f);
        break;
    default:
        rColor = DAT_011a9b7c;
        break;
    }
}

struct ObjA
{
    unsigned char m_flag;
    unsigned char unk01[0x1b];
    unsigned int m_uiCollisionFilterInfo;
};
// Calls FUN_00c84740 with the collision filter infos of p2 and p3, stores the returned byte in p1->m_flag and returns p1.
// @fnv 0x00c84880
ObjA* FUN_00c84880(ObjA* p1, ObjA* p2, ObjA* p3)
{
    unsigned int uiB = p2->m_uiCollisionFilterInfo;
    unsigned int uiA = p3->m_uiCollisionFilterInfo;
    unsigned char result = ((unsigned char)(::FUN_00c84740(uiB, uiA)));
    p1->m_flag = result;
    return p1;
}

struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};


// @fnv 0x00c848b0
unsigned char* FUN_00c848b0(unsigned char* pResult, int a2, ChainNode* pChainA, ChainNode* pChainB, int a5,
                                      int a6)
{
    ChainNode* p = pChainB;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    int tailB = ((volatile ChainNode*)p)->m_1c;

    ChainNode* q = pChainA;
    while (q->m_0c != 0)
    {
        q = q->m_0c;
    }
    int tailA = q->m_1c;
    *pResult = ((unsigned char)(::FUN_00c84740(tailA, tailB)));
    return pResult;
}

// FUN_00c84930: stdcall 3-arg wrapper.
//   a2->m_24 and a3->m_1c are passed to the cdecl helper FUN_00c84740,
//   the resulting byte is written through the first (out) parameter, which is returned.

struct NodeA
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
};

struct NodeB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

// @fnv 0x00c84930
unsigned char* FUN_00c84930(unsigned char* pResult, NodeA* pNodeA, NodeB* pNodeB)
{
    int v1 = pNodeB->m_1c;
    int v2 = pNodeA->m_24;
    *pResult = ((unsigned char)(::FUN_00c84740(v2, v1)));
    return pResult;
}

namespace fnv_00c84960 {
struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};


// @fnv 0x00c84960
unsigned char* FUN_00c84960(unsigned char* pResult, int aiUnused, ChainNode* pChainA, ChainNode* pChainB,
                                      int a5, int a6, int a7, int a8)
{
    ChainNode* q = pChainA;
    while (q->m_0c != 0)
    {
        q = q->m_0c;
    }
    int tailA = q->m_1c;

    ChainNode* p = pChainB;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    int tailB = p->m_1c;

    *pResult = ((unsigned char)(::FUN_00c84740(tailA, tailB)));
    return pResult;
}
}  // namespace fnv_00c84960

struct FUN_00c84dc0_param
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00c84dc0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool FUN_00ba87d0(FUN_00c84dc0_param* p);
    bool FUN_00c84dc0(FUN_00c84dc0_param* p);
};

// Calls FUN_00ba87d0 on p and, if true, checks that the low 5 bits of p->m_10 XOR this->m_10 are zero.
// @fnv 0x00c84dc0
bool FUN_00c84dc0_cls::FUN_00c84dc0(FUN_00c84dc0_param* pParam)
{
    bool b = reinterpret_cast<::FUN_00ba87d0_Class *>((this))->FUN_00ba87d0((::NiObj_s *)(pParam));
    if (b)
    {
        unsigned int x = pParam->m_10 ^ this->m_10;
        b = (x & 0x1f) == 0;
    }
    return b;
}

class FUN_00c84df0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_10;

    void FUN_00c84df0(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
};

struct FUN_00c84e80_data
{
    int unk00;
    float m_fValue;
};

struct FUN_00c84e80_holder
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    int ApplyToNext(int* arg_2);
};


// If this and m_next are non-null, passes m_next, the data's m_fValue and the data to FUN_00cf0690; otherwise returns 1.
// @fnv 0x00c84e80
int FUN_00c84e80_holder::ApplyToNext(int* pData)
{
    int result = 0;

    if (this != 0 && m_next != 0)
    {
        float value = reinterpret_cast<FUN_00c84e80_data*>(pData)->m_fValue;
        ::FUN_00cf0690(m_next, value, (::S00cf0690_Mass *)(pData));
    }
    else
    {
        result = 1;
    }

    return result;
}

// Target class of the first virtual call
class TargetCls
{
  public:
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual int v56(int a);
};

class FUN_00c84f10_cls
{
  public:
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual TargetCls* v51();
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int FUN_00c84f10(int a);
};

// If a is not -1 and v51() returns an object, forwards a to its v56; otherwise returns m_i10 masked to 0x1f.
// @fnv 0x00c84f10
int FUN_00c84f10_cls::FUN_00c84f10(int a)
{
    if (a != -1)
    {
        TargetCls* p = v51();
        if (p)
        {
            return p->v56(a);
        }
    }
    return m_i10 & 0x1f;
}

class FUN_00c84f50_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual FUN_00c84f50_cls* GetNext();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags10;
    bool FUN_00c84f50(int a1, unsigned int a2);
};

// @fnv 0x00c84f50
bool FUN_00c84f50_cls::FUN_00c84f50(int a1, unsigned int auiFlags)
{
    FUN_00c84f50_cls* p = this;
    while (a1 != -1)
    {
        FUN_00c84f50_cls* n = p->GetNext();
        if (n == 0 || n == p)
            break;
        p = n;
    }
    return ((p->m_flags10 & auiFlags) != 0) == auiFlags;
}

struct NiStream;

struct BaseThunk
{
};

struct C_t
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(NiStream* a);
};

struct B_t
{
    int unk00;
    int unk04;
    C_t* unk08;
};

struct A_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    B_t* unk10;
};

struct FUN_00c85ac0_cls : BaseThunk
{
    int unk00;
    int unk04;
    A_t* unk08;

    void FUN_00c85ac0(NiStream* a);
};

// Walks this->unk08 to a nested object and calls its v15 with the stream, then calls FUN_00a81fe0 on the stream.
// @fnv 0x00c85ac0
void FUN_00c85ac0_cls::FUN_00c85ac0(NiStream* pStream)
{
    if (this)
    {
        A_t* pa = this->unk08;
        if (pa)
        {
            B_t** ppb = &pa->unk10;
            if (ppb)
            {
                B_t* pb = *ppb;
                if (pb)
                {
                    C_t* pc = pb->unk08;
                    if (pc)
                        pc->v15(pStream);
                }
            }
        }
    }
    ::FUN_00a81fe0((intptr_t)(this));
}

struct TlsBlock_t
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

class RefLeaf_t
{
  public:
    virtual void unk00();
    virtual void unk04();
    unsigned int m_04;
};

struct Inner_t;

struct Mid_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Inner_t* m_10;
};

struct Inner_t
{
    int unk00;
    int unk04;
    RefLeaf_t* m_08;
};

struct FUN_00c85b00_cls
{
    int unk00;
    int unk04;
    Mid_t* m_08;

    void FUN_00c85b00();
};

// @fnv 0x00c85b00
void FUN_00c85b00_cls::FUN_00c85b00()
{
    TlsGuard_t guard;
    if (this != 0)
    {
        Mid_t* a = m_08;
        if (a)
        {
            Inner_t** pb = &a->m_10;
            Inner_t* b = 0;
            if (pb)
                b = *pb;
            if (b)
            {
                RefLeaf_t* c = b->m_08;
                if (c)
                {
                    if (InterlockedDecrement((volatile long*)&c->m_04) == 0)
                    {
                        c->unk04();
                    }
                }
            }
        }
    }
}

class BC85BA0Target
{
  public:
    int unk00;
    long m_lRefCount;
};

class BC85BA0Link
{
  public:
    int unk00;
    int unk04;
    BC85BA0Target* m_pkTarget;
};

class BC85BA0Holder
{
  public:
    BC85BA0Link* m_pkLink;
};

class BC85BA0HkObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_pvUserData;
    BC85BA0Holder m_kHolder;
};

class BC85BA0RefObject
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void RegisterWithWorld();
};

class BC85BA0WorldObject : public BC85BA0RefObject
{
  public:
    void SetHkObjectUserData(bool bAdd);

    int unk04;
    BC85BA0HkObject* m_pkHkObject;
};

struct S_00c85ce0_First
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c85ce0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_00c85ce0_Obj : S_00c85ce0_First, S_00c85ce0_Inner
{
};
struct S_00c85ce0
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vfc4();
    int unk04;
    S_00c85ce0_Obj* unk08;
    void FUN_00c85ce0(unsigned int a1);
};
// Replaces the high 16 bits of unk08->unk1c with a1, keeping the low 16 bits, then calls vfc4.
// @fnv 0x00c85ce0
void S_00c85ce0::FUN_00c85ce0(unsigned int uiHighWord)
{
    S_00c85ce0_Obj* p = unk08;
    unsigned int old = (p && (S_00c85ce0_Inner*)p) ? ((S_00c85ce0_Inner*)p)->unk1c : 0;
    unsigned int flags = (old & 0xffff) | (uiHighWord << 16);
    if (p && (S_00c85ce0_Inner*)p)
        ((S_00c85ce0_Inner*)p)->unk1c = flags;
    vfc4();
}

struct FUN_00c87600_Base
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
};

struct FUN_00c87600_Arg : FUN_00c87600_Base
{
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
};

struct FUN_00c87600_Obj : FUN_00c87600_Base
{
    virtual void vfA4(int value);
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
    virtual void* vfB4(void* value);

    void FUN_00c87600(void* arg1, void* arg2);
};
// Calls FUN_00c87600 with first and second, then copies the low 5 bits of m_10 into first->m_10.
// @fnv 0x00c84df0
void FUN_00c84df0_cls::FUN_00c84df0(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second)
{
    reinterpret_cast<::FUN_00c87600_Obj *>(this)->FUN_00c87600(first, second);
    first->m_10 = m_10 & 0x1f;
}

struct FUN_00a5d450_helper
{
};

// Calls the base helper with arg1 and arg2, passes the result of vfB4 to arg1's vfB0, then calls vfA4 with 1.
// @fnv 0x00c87600
void FUN_00c87600_Obj::FUN_00c87600(void* pTarget, void* arg2)
{
    reinterpret_cast<::FUN_00a5d450_class *>((reinterpret_cast<FUN_00a5d450_helper*>(this)))->CreateVertexBufferSet((uintptr_t)(pTarget), arg2);

    void* result = this->vfB4(&arg2);
    reinterpret_cast<FUN_00c87600_Arg*>(pTarget)->vfB0(result);

    this->vfA4(1);
}

// TailOne: thiscall, 18 bytes. Self virtual call at slot 0xa4 (index 41) tail-jumped with constant 1 in the stack arg.
struct FUN_00c876d0_cls
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
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void Tail(int a);
    void TailOne(intptr_t a);
};

// @fnv 0x00c876d0
void FUN_00c876d0_cls::TailOne(intptr_t a)
{
    this->Tail(1);
}

class C87710BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(C87710BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

class C87710Stream
{
  public:
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    C87710BinaryStream* m_pUnderlyingStream;
};

class C87710HavokObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual unsigned int GetDataSize();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void* GetData(bool& bIsValid);

    unsigned int FUN_00c87710(C87710Stream& kStream);
};

// Reads the object's data block of GetDataSize() bytes from the stream into the buffer returned by GetData and returns that size.
// @fnv 0x00c87710
unsigned int C87710HavokObject::FUN_00c87710(C87710Stream& kStream)
{
    bool bIsValid;
    void* pvData = GetData(bIsValid);
    unsigned int uiSize = GetDataSize();
    kStream.m_pUnderlyingStream->BinaryRead(pvData, uiSize, 0, 0);
    return uiSize;
}

class BC87850BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC87850BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BC87850BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BC87850Stream
{
  public:
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
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BC87850BinaryStream* m_pUnderlyingStream;
    BC87850BinaryStream* m_pBackingStream;
};

template <class T>
inline void BC87850BinaryStreamSave(BC87850BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BC87850SaveBinary(BC87850Stream& kStream, const T& value)
{
    BC87850BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BC87850RefObject
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void FreeSerializeData(int iHandle);
    virtual unsigned int GetSerializeSize();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual char* GetSerializeData(int* piHandle);

    void SaveSerializeData(BC87850Stream& kStream);
};

// Gets the serialize data buffer and handle, saves the base binary, writes the buffer to the stream, then frees the serialize data.
// @fnv 0x00c87850
void BC87850RefObject::SaveSerializeData(BC87850Stream& kStream)
{
    int iHandle;
    char* pSerializeData = GetSerializeData(&iHandle);
    ::FUN_00a89af0((std::intptr_t)this);
    BC87850BinaryStreamSave(*kStream.m_pBackingStream, pSerializeData, GetSerializeSize());
    FreeSerializeData(iHandle);
}

struct NiObjectData
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    unsigned int m_uiFilterValue;
};

struct FUN_00c879e0_Class
{
    void* m_p0;
    void* m_p4;
    NiObjectData* m_p8;

    void FUN_00c879e0(unsigned int* result);
};

// @fnv 0x00c879e0
void FUN_00c879e0_Class::FUN_00c879e0(unsigned int* result)
{
    *result = (this != 0 && m_p8 != 0) ? m_p8->m_uiFilterValue : 0u;
}

struct C87A10HavokObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_ulUserData;
};

class C87A10RefObject
{
  public:
    int unk00;
    int unk04;
    C87A10HavokObject* m_pPointer;

};

class C87A10WorldObject : public C87A10RefObject
{
  public:
    void FUN_00c87a10(bool bAdd);
};


// @fnv 0x00c88370
void* __cdecl FUN_00c88370()
{
    return &(*reinterpret_cast<int *>(&::g_0126817c));
}

// Constructor of a two-level Havok wrapper: attach the given Havok object (through its referenced-object base).


class C88380ReferencedObject
{
  public:
    int m_iMemSizeAndFlags;
};

class C88380HavokBase
{
  public:
    virtual ~C88380HavokBase();
};

class C88380HavokObject : public C88380HavokBase, public C88380ReferencedObject
{
};

class C88380Root
{
  public:
    C88380Root();
    virtual ~C88380Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class C88380Holder : public C88380Root
{
  public:
    C88380Holder() : m_pkHavokObject(0)
    {}
    virtual ~C88380Holder();
    void* m_pkHavokObject;
};

class C88380RefObject : public C88380Holder
{
  public:
    C88380RefObject()
    {
        ++::DAT_01268188;
    }
    virtual ~C88380RefObject();
};

class FUN_00c88380 : public C88380RefObject
{
  public:
    FUN_00c88380(C88380HavokObject* pkObject);
    virtual ~FUN_00c88380();
};


// @fnv 0x00c88400
int* __cdecl FUN_00c88400()
{
    return &(*reinterpret_cast<int *>(&::g_0126831c));
}

struct FNVTransformState
{
    int component00, component04, component08, component0c;
    int component10, component14, component18, component1c;
    int component20, component24, component28, component2c;
    int component30;
};

struct FNVTraversalNode
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14;
    FNVTraversalNode* parent;
    int unknown1c, unknown20, unknown24;
    int unknown28, unknown2c, unknown30;
    FNVTransformState state;
};

struct FNVTraversalOutput : FNVTransformState
{
    FNVTransformState FUN_0062c250(FNVTransformState* state);
};

// Walks up the parent chain from node to stop, applying each node's state to output and finalizing when stop is reached.
// @fnv 0x00c884c0
void __cdecl AccumulateParentTransforms(FNVTraversalNode* node, FNVTraversalNode* stop, FNVTraversalOutput* output)
{
    if (node == 0)
        return;
    if (node == stop)
    {
        reinterpret_cast<::NiTransform *>((output))->ResetToIdentity();
        return;
    }
    AccumulateParentTransforms(node->parent, stop, output);
    static_cast<FNVTransformState&>(*output) = output->FUN_0062c250(&node->state);
}

struct ThreadTlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = (*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        (*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

class TlsCallTarget
{
  public:
    void Apply(unsigned int v);
};

class FUN_00c886c0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    TlsCallTarget* m_08;
    void CallTargetWithArgs();
};

class C88930Base
{
  public:
    virtual ~C88930Base();
};

class FUN_00c88930 : public C88930Base
{
  public:
    void Release();

    virtual ~FUN_00c88930();
};
// Calls FUN_00c88930, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c88a20
void* FUN_00c88a20_cls::FUN_00c88a20(unsigned int flags)
{
    reinterpret_cast<::FUN_00c88930 *>(this)->FUN_00c88930::~FUN_00c88930();
    if (flags & 1)
        operator delete(this, 0x2c);
    return this;
}

// @fnv 0x00c88930
FUN_00c88930::~FUN_00c88930()
{
    reinterpret_cast<::FUN_00c886c0_cls *>(this)->CallTargetWithArgs();
}

class SpawnedBase_b7559
{
  public:
    virtual void unk00();
    int m_04;

    SpawnedBase_b7559();
    ~SpawnedBase_b7559();
};

class FUN_00c894d0 : public SpawnedBase_b7559
{
  public:
    FUN_00c894d0(intptr_t a, intptr_t b, intptr_t c, intptr_t d, int e);
    virtual void unk00();
};

// Constructs the object by forwarding all five arguments to Init_b7559.
// @fnv 0x00c894d0
FUN_00c894d0::FUN_00c894d0(intptr_t a, intptr_t b, intptr_t c, intptr_t d, int e)
{
    reinterpret_cast<::Shape892 *>(this)->FUN_00c892c0(a, b, c, (::Shape892 *)(d), e);
}

namespace fnv_00c89540 {
void* __cdecl FUN_00aa13e0(size_t);
struct FUN_00c894d0
{
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
    FUN_00c894d0(intptr_t, intptr_t, intptr_t, intptr_t, int);
};
struct ScopedMemoryMode
{
    unsigned int previousMode;
    explicit ScopedMemoryMode(unsigned int mode) : previousMode(::currentAllocationContext)
    {
        ::currentAllocationContext = mode;
    }
    ~ScopedMemoryMode()
    {
        ::currentAllocationContext = previousMode;
    }
};
// @fnv 0x00c89540
FUN_00c894d0* __cdecl CreateResourceObject(intptr_t first, intptr_t second, intptr_t resourceId, int finalArgument)
{
    ScopedMemoryMode scopedMode(16);
    FUN_00c894d0* result = 0;
    if (resourceId != 0)
    {
        intptr_t info = ((intptr_t)(::FUN_00c802d0((::MyNode *)(resourceId))));
        if (info != 0)
        {
            result = new FUN_00c894d0(first, second, resourceId, info, finalArgument);
        }
    }
    return result;
}
}  // namespace fnv_00c89540


class PolyBase
{
  public:
    virtual ~PolyBase();
};

class FUN_00c89640_cls : public PolyBase
{
  public:
    virtual ~FUN_00c89640_cls();
};

// @fnv 0x00c89640
FUN_00c89640_cls::~FUN_00c89640_cls()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268188;
}

class C896C0Object
{
  public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual int GetA();
    virtual int GetB();

    bool IsEqualWithValues(C896C0Object* pkObject);
};

// Compares against pkObject: if IsEqualBase passes, also requires matching GetA and GetB values; returns the combined result.
// @fnv 0x00c896c0
bool C896C0Object::IsEqualWithValues(C896C0Object* pkObject)
{
    bool bEqual = reinterpret_cast<::FUN_00ba87d0_Class *>(this)->FUN_00ba87d0((::NiObj_s *)(pkObject));
    if (bEqual)
    {
        int iA = pkObject->GetA();
        bEqual = GetA() == iA;
        int iB = pkObject->GetB();
        bEqual = bEqual & (GetB() == iB);
    }
    return bEqual;
}

struct S_00c89810_ResultInner
{
    void* unk0;
    void* unk4;
    int unk8;
};

struct S_00c89810_ResultVirtuals
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2(int value)
    {}
};
struct S_00c89810_ResultLink
{
    S_00c89810_ResultInner* m_p4;
};
// mB4 returns the address of m_p4; the cast back to the whole object is null-checked.
struct S_00c89810_Result : S_00c89810_ResultVirtuals, S_00c89810_ResultLink
{
};

struct S_00c89810_Owner
{
    virtual void d00()
    {}
    virtual void d01()
    {}
    virtual void d02()
    {}
    virtual void d03()
    {}
    virtual void d04()
    {}
    virtual void d05()
    {}
    virtual void d06()
    {}
    virtual void d07()
    {}
    virtual void d08()
    {}
    virtual void d09()
    {}
    virtual void d0a()
    {}
    virtual void d0b()
    {}
    virtual void d0c()
    {}
    virtual void d0d()
    {}
    virtual void d0e()
    {}
    virtual void d0f()
    {}
    virtual void d10()
    {}
    virtual void d11()
    {}
    virtual void d12()
    {}
    virtual void d13()
    {}
    virtual void d14()
    {}
    virtual void d15()
    {}
    virtual void d16()
    {}
    virtual void d17()
    {}
    virtual void d18()
    {}
    virtual void d19()
    {}
    virtual void d1a()
    {}
    virtual void d1b()
    {}
    virtual void d1c()
    {}
    virtual void d1d()
    {}
    virtual void d1e()
    {}
    virtual void d1f()
    {}
    virtual void d20()
    {}
    virtual void d21()
    {}
    virtual void d22()
    {}
    virtual void d23()
    {}
    virtual void d24()
    {}
    virtual void d25()
    {}
    virtual void d26()
    {}
    virtual void d27()
    {}
    virtual void d28()
    {}
    virtual void d29()
    {}

    virtual void mA8()
    {}
    virtual void mA9()
    {}
    virtual void mAA()
    {}
    virtual void* mB4(char* value)
    {
        return 0;
    }

    void SetValueAndReset(int value);
};

// Calls mB4 to obtain a result object, invokes its v2 with value, clears m_p4->unk8, then calls mA8.
// @fnv 0x00c89810
void S_00c89810_Owner::SetValueAndReset(int value)
{
    char local;

    void* returned = this->mB4(&local);
    S_00c89810_Result* result = static_cast<S_00c89810_Result*>(static_cast<S_00c89810_ResultLink*>(returned));

    result->v2(value);
    result->m_p4->unk8 = 0;

    this->mA8();
}

struct FUN_00c898e0_Inner
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
    virtual void Slot21(int a);
};

struct FUN_00c898e0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c898e0_Inner* m_0c;
};

struct FUN_00c898e0_Holder
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual FUN_00c898e0_Sub* GetSub();
    void DispatchToInnerSlot(int arg);
};

// Gets the sub-object, forwards arg to its inner object's Slot21 if present, then calls FUN_00a81fe0(arg).
// @fnv 0x00c898e0
void FUN_00c898e0_Holder::DispatchToInnerSlot(int arg)
{
    FUN_00c898e0_Sub* sub = GetSub();
    if (sub != 0)
    {
        FUN_00c898e0_Inner* p = sub->m_0c;
        if (p != 0)
        {
            p->Slot21(arg);
        }
    }
    ::FUN_00a81fe0((intptr_t)this);
}

struct RefTargetVirtuals
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03(int a)
    {}
};
struct RefTargetPart
{
    void* unk00;
};
// GetRef returns the address of the RefTargetPart base.
struct RefTarget : RefTargetVirtuals, RefTargetPart
{
};

struct FUN_00c89920_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual unsigned char* GetRef(unsigned char* flag);
    void InvokeRefTarget(int a);
};

// Gets a reference via GetRef, adjusts it to the RefTarget base, and calls its v03 with a.
// @fnv 0x00c89920
void FUN_00c89920_cls::InvokeRefTarget(int a)
{
    unsigned char flag;
    unsigned char* r = GetRef(&flag);
    RefTarget* p = static_cast<RefTarget*>(reinterpret_cast<RefTargetPart*>(r));
    p->v03(a);
}

struct FUN_00c89960_innerVirtuals
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(uintptr_t a);
};
struct FUN_00c89960_innerPart
{
    void* unk00;
};
// v45 returns the address of the FUN_00c89960_innerPart base.
struct FUN_00c89960_inner : FUN_00c89960_innerVirtuals, FUN_00c89960_innerPart
{
};

struct FUN_00c89960_cls
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
    virtual void v41(int flag);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void* v45(uintptr_t* p);
    void FUN_00c89960(uintptr_t a1);
};

// Calls FUN_00c878c0 with a1, resolves an inner object via v45, calls its v5 with a1, then v41(1).
// @fnv 0x00c89960
void FUN_00c89960_cls::FUN_00c89960(uintptr_t uiValue)
{
    uintptr_t v = *(volatile uintptr_t*)&uiValue;
    reinterpret_cast<::FUN_00c878c0_cls *>(this)->FUN_00c878c0((::BC878C0StringArray *)(v));
    FUN_00c89960_inner* q = static_cast<FUN_00c89960_inner*>(static_cast<FUN_00c89960_innerPart*>(v45(&uiValue)));
    q->v5(v);
    v41(1);
}

class FUN_00c899b0_target
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
};

class FUN_00c899b0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00c899b0_target* m_08;

    int FUN_00c899b0();
};

// @fnv 0x00c899b0
int FUN_00c899b0_cls::FUN_00c899b0()
{
    int result = 0;
    if (m_08 != 0)
    {
        result = m_08->m_14;
    }
    return result;
}

struct FUN_00c899d0_Target
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
    void* unk2c;
};

struct FUN_00c899d0_Class
{
    int unk00;
    int unk04;
    FUN_00c899d0_Target* unk08;

    void ReleaseReference(bool b);
    void FUN_00c899d0(bool b);
};
// Links m_next to this when b is set, otherwise clears it, then calls UpdateReference(b) on this as a bhkRefObject.
// @fnv 0x00c84e50
void bhkBoxShape::FUN_00c84e50(bool b)
{
    if (this && m_next)
    {
        struct bhkBoxShape* p = (struct bhkBoxShape*)m_next;
        p->m_next = b ? this : 0;
    }
    reinterpret_cast<::FUN_00c899d0_Class *>((reinterpret_cast<bhkRefObject*>(this)))->ReleaseReference(b);
}
// @fnv 0x00c85ba0
void BC85BA0WorldObject::SetHkObjectUserData(bool bAdd)
{
    BC85BA0WorldObject* pkUser;
    if (bAdd)
    {
        if (this && m_pkHkObject)
        {
            BC85BA0Holder* pkHolder = &m_pkHkObject->m_kHolder;
            if (pkHolder && pkHolder->m_pkLink && pkHolder->m_pkLink->m_pkTarget)
                InterlockedIncrement(&pkHolder->m_pkLink->m_pkTarget->m_lRefCount);
        }
        pkUser = this;
    }
    else
    {
        RegisterWithWorld();
        reinterpret_cast<::FUN_00c85b00_cls *>(this)->FUN_00c85b00();
        pkUser = 0;
    }
    if (this && m_pkHkObject)
        m_pkHkObject->m_pvUserData = pkUser;
    reinterpret_cast<::FUN_00c899d0_Class *>(this)->ReleaseReference(bAdd);
}
// @fnv 0x00c87a10
void C87A10WorldObject::FUN_00c87a10(bool bAdd)
{
    if (this && m_pPointer)
        m_pPointer->m_ulUserData = bAdd ? this : 0;
    reinterpret_cast<::FUN_00c899d0_Class *>(this)->ReleaseReference(bAdd);
}

// If this and unk08 are non-null, stores this or null into unk08->unk2c depending on b, then calls ReleaseReference(b).
// @fnv 0x00c899d0
void FUN_00c899d0_Class::FUN_00c899d0(bool b)
{
    if (this && unk08)
    {
        unk08->unk2c = b ? this : 0;
    }
    ReleaseReference(b);
}

struct S_00c89a30_Obj;
struct S_00c89a30_Owner;
struct S_00c89a30_Obj
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
    virtual int v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(S_00c89a30_Obj* o, int f);
    int unk04;
    S_00c89a30_Owner* unk08;
    bool FUN_00c89a30(S_00c89a30_Obj* other);
};
// @fnv 0x00c89a30
bool S_00c89a30_Obj::FUN_00c89a30(S_00c89a30_Obj* other)
{
    S_00c89a30_Owner* owner = this ? unk08 : 0;
    bool r = false;
    if (owner)
    {
        if (other)
        {
            int a = v37();
            int b = other->v37();
            if (a != b)
            {
                v40();
                v53(other, 1);
                reinterpret_cast<::FUN_00c6b320_Class *>((other))->FUN_00c6b320((::hkReferencedObject *)(owner));
                r = true;
            }
        }
        else
        {
            v40();
        }
    }
    return r;
}

namespace fnv_00c89d10 {
struct TlsBlock_t
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};


struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00c89d10::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00c89d10::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00c89d10::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct FUN_00c89d10_P;
class VObjA
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Notify(FUN_00c89d10_P* p);
};

struct FUN_00c89d10_R
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
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_94;
};

struct FUN_00c89d10_Q
{
    int unk00;
    int unk04;
    FUN_00c89d10_R* m_08;
};

struct FUN_00c89d10_P
{
    int unk00;
    int unk04;
    class VObjA* m_08;
    int unk0C;
    int unk10;
    FUN_00c89d10_Q* m_14;
};

class FUN_00c89d10_cls
{
  public:
    int unk00;
    int unk04;
    FUN_00c89d10_P* m_08;
    void Helper(int a);
    void FUN_00c89d10(int arg);
};

// @fnv 0x00c89d10
void FUN_00c89d10_cls::FUN_00c89d10(int arg)
{
    TlsGuard_t guard;
    FUN_00c89d10_P* p = this != 0 ? m_08 : 0;
    if (arg != (intptr_t)p)
    {
        if (p != 0)
        {
            VObjA* o = p->m_08;
            if (o != 0)
            {
                FUN_00c89d10_R* r = p->m_14->m_08;
                if (r != 0)
                    r->m_94++;
                o->Notify(p);
                if (r != 0)
                    r->m_94--;
            }
        }
        Helper(arg);
    }
}
}  // namespace fnv_00c89d10

struct hkReferencedObject
{
};
struct FUN_009ba5f0_shell
{
    void ReleaseObject(hkReferencedObject*, intptr_t);
};
struct TlsGuard
{
    int old;
    TlsGuard() : old((*reinterpret_cast<int *>(&::currentAllocationContext)))
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~TlsGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = old;
    }
};
struct S_00c8a280_Child
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct S_00c8a280_Bin
{
    void* __vf;
    unsigned int m_uiPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(S_00c8a280_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
};
inline void S_00c8a280_Save(S_00c8a280_Bin* b, const void* buf, unsigned int bytes)
{
    unsigned int comp = bytes;
    unsigned int n = b->m_pfnWrite(b, buf, bytes, &comp, 1);
    b->m_uiPos += n;
}
struct S_00c8a280_Stream
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
    virtual void v12(int a);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    S_00c8a280_Bin* m_pBackingStream;
};
struct S_00c8a280_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int m_04;
    unsigned int m_08;
    S_00c8a280_Child* m_0c;
    S_00c8a280_Child* m_10;
    void FUN_00c8a280(S_00c8a280_Stream& kStream);
};
// Writes a version value, the m_0c values of m_0c and m_10 (or 0), calls v4, then writes m_08 to the stream.
// @fnv 0x00c8a280
void S_00c8a280_Obj::FUN_00c8a280(S_00c8a280_Stream& kStream)
{
    unsigned int uiVersion = 2;
    S_00c8a280_Save(kStream.m_pBackingStream, &uiVersion, 4);
    kStream.v12(m_0c ? m_0c->m_0c : 0);
    kStream.v12(m_10 ? m_10->m_0c : 0);
    v4();
    S_00c8a280_Save(kStream.m_pBackingStream, &m_08, 4);
}

class C8A4B0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C8A4B0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C8A4B0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class C8A4B0Object;

class C8A4B0Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(C8A4B0Object* pkObject);

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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    C8A4B0BinaryStream* m_pBackingStream;
};

template <class T>
inline void C8A4B0BinaryStreamSave(C8A4B0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C8A4B0SaveBinary(C8A4B0Stream& kStream, const T& value)
{
    C8A4B0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class C8A4B0Shape
{
  public:

    int unk00;
    int unk04;
    char m_cType;
};

// Writes the shape's type byte to the stream, then dispatches to SaveSphere, SaveBox or SaveCapsule; writes a zero byte if pkShape is null.
// @fnv 0x00c8a4b0
void SaveShape(C8A4B0Shape* pkShape, C8A4B0Stream& kStream)
{
    if (pkShape)
    {
        C8A4B0SaveBinary(kStream, pkShape->m_cType);
        switch (pkShape->m_cType)
        {
        case 1:
            reinterpret_cast<::SerializableCF42 *>((pkShape))->FUN_00cf4260((::NiStreamCF42 &)(kStream));
            break;
        case 2:
            reinterpret_cast<::FUN_00cf4490_cls *>((pkShape))->FUN_00cf4490((void *)&(kStream));
            break;
        case 3:
            reinterpret_cast<::SerializedObject *>((pkShape))->SerializeToStream((intptr_t)&(kStream));
            break;
        }
    }
    else
    {
        char cNone = 0;
        C8A4B0SaveBinary(kStream, cNone);
    }
}

struct GlobalObject
{
    int unk00;
};

// @fnv 0x00c8a790
GlobalObject* __cdecl FUN_00c8a790()
{
    return &(*reinterpret_cast<::GlobalObject *>(&::g_01268198));
}

struct FUN_00c8a7a0_cls;

struct Callee_a645
{
};

struct FUN_00c8a7a0_cls
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
    virtual void* v2D(unsigned int* out);
    void FUN_00c8a7a0(uintptr_t a1);
};

// Calls Run twice on the object, calls Init, then obtains a pointer via v2D and zeroes its second and third words.
// @fnv 0x00c8a7a0
void FUN_00c8a7a0_cls::FUN_00c8a7a0(volatile uintptr_t uiObj)
{
    uintptr_t obj = uiObj;
    reinterpret_cast<::FUN_00a645b0_cls *>((((Callee_a645*)obj)))->FUN_00a645b0();
    reinterpret_cast<::FUN_00a645b0_cls *>((((Callee_a645*)obj)))->FUN_00a645b0();
    reinterpret_cast<::FUN_00c87650_t *>(this)->LoadBinary((*(::NiStream *)(obj)));
    unsigned int* r = (unsigned int*)v2D((unsigned int*)&uiObj);
    r[1] = 0;
    r[2] = 0;
}

// Result block filled in by WriteScriptTargetInfo.
struct ScriptOutBlock
{
    int unk00;
    int unk04;
    void* unk08;
};

// Object reached through the member pointer of the owner.
struct ScriptTarget
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    void* m_1c;
};

class ScriptOwnerBase
{
  public:
};

class FUN_00c8a800_cls : public ScriptOwnerBase
{
  public:
    int unk00;
    int unk04;
    ScriptTarget* m_pFlagTarget;
    void WriteScriptTargetInfo(ScriptOutBlock* pOut);
};

// Calls the base writer, then stores the target's m_18 and m_1c into pOut->unk04 and pOut->unk08, or 0 when this or the target is null.
// @fnv 0x00c8a800
void FUN_00c8a800_cls::WriteScriptTargetInfo(ScriptOutBlock* pOut)
{
    reinterpret_cast<::FUN_00c879e0_Class *>((this))->FUN_00c879e0((unsigned int *)(pOut));
    pOut->unk04 = (this != 0 && m_pFlagTarget != 0) ? m_pFlagTarget->m_18 : 0;
    pOut->unk08 = (this != 0 && m_pFlagTarget != 0) ? m_pFlagTarget->m_1c : 0;
}

struct Ca980Block
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
    unsigned int m_1C;
};

class FUN_00c8a980_cls
{
  public:
    int unk00;
    int unk04;
    Ca980Block* m_08;
    bool FUN_00ba87d0(FUN_00c8a980_cls* p);
    bool FUN_00c8a980(FUN_00c8a980_cls* p);
};

// Calls FUN_00ba87d0 and, if it succeeds, also compares m_18 and m_1C of both objects' m_08 blocks, returning whether all match.
// @fnv 0x00c8a980
bool FUN_00c8a980_cls::FUN_00c8a980(FUN_00c8a980_cls* apOther)
{
    bool result = reinterpret_cast<::FUN_00ba87d0_Class *>((this))->FUN_00ba87d0((::NiObj_s *)(apOther));
    if (result)
    {
        unsigned int a = (this != 0 && this->m_08 != 0) ? this->m_08->m_18 : 0;
        unsigned int b = (apOther != 0 && apOther->m_08 != 0) ? apOther->m_08->m_18 : 0;
        result = (a == b);
        unsigned int c = (this != 0 && this->m_08 != 0) ? this->m_08->m_1C : 0;
        unsigned int d = (apOther != 0 && apOther->m_08 != 0) ? apOther->m_08->m_1C : 0;
        result = result & (c == d);
    }
    return result;
}


class FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_base();
};

class FUN_00c8adf0_cls : public FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_cls();
};

// @fnv 0x00c8adf0
FUN_00c8adf0_cls::~FUN_00c8adf0_cls()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_012681a0;
}

struct FUN_00c8b000_Node
{
    int m_00;
    void* m_04;
    void* m_08;
};

struct FUN_00c8b000_Item;

struct FUN_00c8b000_Obj
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
    virtual FUN_00c8b000_Node* v18(intptr_t a);
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual bool v52(intptr_t a);
};

struct FUN_00c8b000_Item
{
    int m_00;
    int m_04;
    FUN_00c8b000_Obj* m_08;
};

struct FUN_00c8b000_List
{
    int m_00;
    FUN_00c8b000_Item** m_04;
    int m_08;
};

struct FUN_00c8b000_cls
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
    virtual FUN_00c8b000_List* v45(bool* out);
    void UpdateListEntries(intptr_t a1, intptr_t a2);
};

// @fnv 0x00c8b000
void FUN_00c8b000_cls::UpdateListEntries(intptr_t a1, intptr_t a2)
{
    bool flag;
    FUN_00c8b000_List* list = v45(&flag);
    for (int i = 0; i < list->m_08; ++i)
    {
        FUN_00c8b000_Item* item = list->m_04[i];
        if (item != 0)
        {
            FUN_00c8b000_Obj* obj = item->m_08;
            if (obj != 0 && !obj->v52(a2))
            {
                FUN_00c8b000_Node* node = obj->v18(a2);
                FUN_00c8b000_Item* result = node != 0 ? (FUN_00c8b000_Item*)node->m_08 : 0;
                list->m_04[i] = result;
            }
        }
    }
    reinterpret_cast<::FUN_00c84df0_cls *>(this)->FUN_00c84df0((::FUN_00c84df0_cls *)(a1), (::FUN_00c84df0_cls *)(a2));
}

struct FileContext
{
};
struct H_00c8b1d0
{
    virtual void reservedVirtual0();
    virtual void reservedVirtual1();
    virtual void reservedVirtual2();
    virtual void reservedVirtual3();
    virtual void reservedVirtual4();
    virtual void reservedVirtual5();
    virtual void reservedVirtual6();
    virtual void reservedVirtual7();
    virtual void reservedVirtual8();
    virtual void reservedVirtual9();
    virtual void reservedVirtual10();
    virtual void reservedVirtual11();
    virtual void reservedVirtual12();
    virtual void reservedVirtual13();
    virtual void reservedVirtual14();
    virtual void reservedVirtual15();
    virtual void reservedVirtual16();
    virtual void reservedVirtual17();
    virtual void reservedVirtual18();
    virtual void reservedVirtual19();
    virtual void reservedVirtual20();
    virtual void reservedVirtual21();
    virtual void reservedVirtual22();
    virtual void reservedVirtual23();
    virtual void reservedVirtual24();
    virtual void reservedVirtual25();
    virtual void reservedVirtual26();
    virtual void reservedVirtual27();
    virtual void reservedVirtual28();
    virtual void reservedVirtual29();
    virtual void reservedVirtual30();
    virtual void reservedVirtual31();
    virtual void reservedVirtual32();
    virtual void reservedVirtual33();
    virtual void reservedVirtual34();
    virtual void reservedVirtual35();
    virtual void reservedVirtual36();
    virtual void reservedVirtual37();
    virtual void reservedVirtual38();
    virtual void reservedVirtual39();
    virtual void reservedVirtual40();
    virtual void reservedVirtual41();
    virtual int GetDataSize();
    virtual void reservedVirtual43();
    virtual void reservedVirtual44();
    virtual char* GetDataPosition(FileContext* volatile* object);
    void ProcessFileContext(FileContext* object);
};
// HandleAllEntries — walks the entry array of the list object held at this+0x08
// and forwards the parameter to each entry's handler-object virtual
// (vtable slot 21), then calls the member routine FUN_00aa0ad0 on this.
//
// Count source: vtable slot 1 of the sub-object embedded at list+0x10, with
// the owner chain (this, list) null-checked; the entry walk re-checks the
// chain on every iteration and skips null slots / null handler objects.
//
// Target: (this in ecx), callee pops 4 bytes (1 stack parameter),
// size 109, /MT /O2 /GS /EHsc /Gy.

// Sub-object embedded at list+0x10; its vtable slot 1 returns the entry
// count as an unsigned value.
struct SubObj00
{
    virtual void v0();
    virtual unsigned int GetCount();  // vtable +0x04
};

// Handler object; vtable slot 21 (+0x54) is invoked with the parameter.
struct Handler00;

// Entry object referenced by a slot; field +0x08 points at the handler
// object that receives the per-entry virtual call.
struct Entry00;

// One 16-byte slot of the entry array at list+0x18; only the first dword
// (a pointer to the entry object) is read here.
struct Slot00
{
    Entry00* p0;  // +0x00
    int unk04;
    int unk08;
    int unk0C;
};

struct Entry00
{
    int unk00;
    int unk04;
    Handler00* unk08;  // +0x08
};

struct Handler00
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
    virtual void Handle(void* param);  // vtable +0x54
};

// The list object held at this+0x08: embedded polymorphic sub-object at
// +0x10, spare dword at +0x14, entry array base at +0x18.
struct List00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SubObj00 sub;  // +0x10
    int unk14;
    Slot00* arr;  // +0x18
};

// Owning class of the target member.
struct Owner00
{
    int unk00;
    int unk04;
    List00* unk08;  // +0x08

      // defined elsewhere
    void HandleAllEntries(void* param);
};

// Calls Handle(param) on each entry's handler in the list, then calls FUN_00aa0ad0(param).
// @fnv 0x00c8b240
void Owner00::HandleAllEntries(void* param)
{
    unsigned int count;
    if (this != 0)
    {
        List00* list = this->unk08;
        if (list != 0)
            count = list->sub.GetCount();
        else
            count = 0;
    }
    else
        count = 0;

    for (unsigned int i = 0; i < count; i++)
    {
        if (this != 0)
        {
            List00* list = this->unk08;
            if (list != 0)
            {
                Entry00* entry = list->arr[i].p0;
                if (entry != 0)
                {
                    Handler00* h = entry->unk08;
                    if (h != 0)
                        h->Handle(param);
                }
            }
        }
    }

    ::FUN_00aa0ad0();
}

struct DecCountProvider
{
    virtual void Slot00();
    virtual int GetCount();
};

struct DecTarget
{
    int unk00;
    int unk04;
};

struct DecItem
{
    int unk00;
    int unk04;
    DecTarget* m_08;
};

struct DecEntry
{
    DecItem* m_00;
    int unk04;
    int unk08;
    int unk0C;
};

struct DecOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DecCountProvider m_10;
    int unk14;
    DecEntry* m_18;
};

typedef void(* DecCallback)(void* arg);
extern "C" DecCallback DAT_00fdf1c0;

struct FUN_00c8b2b0_cls
{
    int unk00;
    int unk04;
    DecOwner* m_08;
    void InvokeCallbacksOnEntries();
};
// Calls one of two methods depending on b, then forwards b to FUN_00c84e50.
// @fnv 0x00c8b410
void H_00c8c810::FUN_00c8b410(bool b)
{
    if (b)
        reinterpret_cast<::FUN_00c8b2b0_cls *>(this)->InvokeCallbacksOnEntries();
    else
        ReleaseReferencedObjects();
    reinterpret_cast<::bhkBoxShape *>(this)->FUN_00c84e50(b);
}

// Calls DAT_00fdf1c0 for each entry's item target in reverse order, stopping early if the owner or count is null/zero.
// @fnv 0x00c8b2b0
void FUN_00c8b2b0_cls::InvokeCallbacksOnEntries()
{
    if (this == 0)
        return;
    DecOwner* p = m_08;
    if (p == 0)
        return;
    int n = p->m_10.GetCount();
    if (n == 0)
        return;
    DecCallback fn = DAT_00fdf1c0;
    do
    {
        DecOwner* o = m_08;
        --n;
        if (o != 0)
        {
            DecEntry* e = &o->m_18[n];
            DecItem* it = e->m_00;
            if (it != 0 && it->m_08 != 0)
                fn((void*)&it->m_08->unk04);
        }
    } while (n != 0);
}


struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~MemoryContextScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previousContext;
    }
};

struct RefCountedEntry
{
    virtual void UnusedVirtual();
    virtual void Release();
    volatile long referenceCount;
};

struct Record
{
    int firstField;
    int secondField;
    RefCountedEntry* referencedObject;
};

struct CollectionSlot
{
    Record* record;
    int key;
    int status;
    int extra;
};

struct IndexedRecords
{
    virtual void FirstVirtual();
    virtual unsigned int GetSize();
    int capacity;
    CollectionSlot* entries;
};

struct RecordCollection
{
    int header0;
    int header4;
    int header8;
    int headerC;
    IndexedRecords items;
};

struct CollectionHolderLayout
{
    int state;
    int reserved;
    RecordCollection* collection;
};

// Iterates the collection's entries backwards and releases each record's referenced object when its reference count drops to zero.
// @fnv 0x00c8b310
void H_00c8c810::ReleaseReferencedObjects()
{
    MemoryContextScope m_uiMemoryContext;
    CollectionHolderLayout* holder = reinterpret_cast<CollectionHolderLayout*>(this);

    if (this != 0)
    {
        RecordCollection* records = holder->collection;
        if (records != 0)
        {
            unsigned int count = records->items.GetSize();
            if (count != 0)
            {
                unsigned int offset = count << 4;
                do
                {
                    --count;
                    offset -= 16;
                    if (holder->collection != 0)
                    {
                        Record* record = *reinterpret_cast<Record**>(
                            reinterpret_cast<unsigned char*>(holder->collection->items.entries) + offset);
                        if (record != 0)
                        {
                            RefCountedEntry* reference = record->referencedObject;
                            if (reference != 0 && InterlockedDecrement(&reference->referenceCount) == 0)
                            {
                                reference->Release();
                            }
                        }
                    }
                } while (count != 0);
            }
        }
    }
}


struct MemContextScope
{
    int iOld;
    MemContextScope(int iNew)
    {
        iOld = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = iNew;
    }
    ~MemContextScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = iOld;
    }
};


struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    unsigned int Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }
};

struct NiRTTIStub
{
    const char* m_pcName;
    const NiRTTIStub* m_pBaseRTTI;
};

struct hkpShapeContainerStub
{
    virtual ~hkpShapeContainerStub();
    virtual int GetNumChildShapes();
};

struct hkpListShapeStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpShapeContainerStub kContainer;
};

struct bhkShapeCollectionBase
{
};

struct bhkListShapeStub : bhkShapeCollectionBase
{
    int unk00;
    int unk04;
    hkpListShapeStub* m_pHavokObject;

    void FUN_00c8bcd0(ViewerStrings* pkStrings);
};

static inline hkpListShapeStub* GetHkListShape(bhkListShapeStub* p)
{
    return p ? p->m_pHavokObject : 0;
}

// @fnv 0x00c8bcd0
void bhkListShapeStub::FUN_00c8bcd0(ViewerStrings* pkStrings)
{
    MemContextScope kScope(0x10);
    reinterpret_cast<::fnv_00cd2fd0::Object *>(this)->FUN_00cd2fd0((::fnv_00cd2fd0::StrArr *)(pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<::NiRTTIStub *>(&::g_012681a8)).m_pcName));
    hkpListShapeStub* pHk = GetHkListShape(this);
    int iShapeCount = pHk ? pHk->kContainer.GetNumChildShapes() : 0;
    pkStrings->Add(::FUN_00a7d4d0("Shapes", iShapeCount));
    for (int i = 0; i < iShapeCount; i++)
    {
        char acBuf[32];
        ::FUN_00406d00(acBuf, 32, "Shape%d", i);
    }
}

namespace fnv_00c8be30 {
struct TlsBlock_t
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00c8be30::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00c8be30::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00c8be30::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct Owned_t
{
    void Destroy();
};

struct PoolFree_t
{
    void Free(void* p);
};


struct FUN_00c8be30_cls
{
    int unk00;
    int unk04;
    int unk08;
    Owned_t* m_0c;

    void ReleaseOwned(bool flag);
};

// If flag is set, destroys and frees the owned object at m_0c, then clears the pointer.
// @fnv 0x00c8be30
void FUN_00c8be30_cls::ReleaseOwned(bool abRelease)
{
    TlsGuard_t guard;
    if (abRelease)
    {
        Owned_t* p = m_0c;
        if (p)
        {
            reinterpret_cast<::FUN_00c71120 *>((p))->FUN_00c71120::~FUN_00c71120();
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c8be30::PoolFree_t *>(&::g_memoryManager))))->FUN_00aa4060(p);
        }
        m_0c = 0;
    }
}
}  // namespace fnv_00c8be30

class C8CCC0Base
{
  public:
    bool IsEqual(const C8CCC0Base& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class C8CCC0Derived : public C8CCC0Base
{
  public:
    bool FUN_00c8ccc0(const C8CCC0Derived& kOther) const;

    int m_iValue;
};

// Calls the base IsEqual and, if it succeeds, also compares m_iValue with the other object's m_iValue.
// @fnv 0x00c8ccc0
bool C8CCC0Derived::FUN_00c8ccc0(const C8CCC0Derived& kOther) const
{
    bool bEqual = IsEqual(kOther);
    if (bEqual)
        bEqual = m_iValue == kOther.m_iValue;
    return bEqual;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);

struct SwapMatrix_c8ce70
{
    unsigned long m00;
    unsigned long m04;
    unsigned long m08;
    unsigned long m0c;
    unsigned long m10;
    unsigned long m14;
    unsigned long m18;
    unsigned long m1c;
    unsigned long m20;
    unsigned long m24;
    unsigned long m28;
    unsigned long m2c;
};

inline void Swap32_c8ce70(void* p)
{
    unsigned long* q = (unsigned long*)p;
    *q = _byteswap_ulong(*q);
}
inline void Swap16_c8ce70(void* p)
{
    unsigned short* q = (unsigned short*)p;
    *q = _byteswap_ushort(*q);
}


struct SwapBlock_c8ce70
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
    unsigned short unk2c;
    short unk2e;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    SwapMatrix_c8ce70 unk70;
    float unka0;
    float unka4;
    float unka8;
    float unkac;
    float unkb0;
    float unkb4;
    float unkb8;
    float unkbc;
    float unkc0;
    float unkc4;
    float unkc8;
    float unkcc;
    float unkd0;

    void SwapEndian();
};

// @fnv 0x00c8ce70
void SwapBlock_c8ce70::SwapEndian()
{
    Swap32_c8ce70(&unk30);
    Swap32_c8ce70(&unk34);
    Swap32_c8ce70(&unk38);
    Swap32_c8ce70(&unk3c);
    Swap32_c8ce70(&unk40);
    Swap32_c8ce70(&unk44);
    Swap32_c8ce70(&unk48);
    Swap32_c8ce70(&unk4c);
    Swap32_c8ce70(&unk50);
    Swap32_c8ce70(&unk54);
    Swap32_c8ce70(&unk58);
    Swap32_c8ce70(&unk5c);
    Swap32_c8ce70(&unk60);
    Swap32_c8ce70(&unk64);
    Swap32_c8ce70(&unk68);
    Swap32_c8ce70(&unk6c);
    ::SwapEndianBlocks((unsigned int *)(::SwapMatrix_c8ce70 *)(&unk70));
    Swap32_c8ce70(&unka0);
    Swap32_c8ce70(&unka4);
    Swap32_c8ce70(&unka8);
    Swap32_c8ce70(&unkac);
    Swap16_c8ce70(&unk2e);
    Swap32_c8ce70(&unkb0);
    Swap32_c8ce70(&unkb4);
    Swap32_c8ce70(&unkb8);
    Swap32_c8ce70(&unkbc);
    Swap32_c8ce70(&unkc0);
    Swap32_c8ce70(&unkc4);
    Swap32_c8ce70(&unkc8);
    Swap32_c8ce70(&unkcc);
    Swap32_c8ce70(&unkd0);
}

class FUN_00c8d090_item
{
  public:
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
    virtual void v15(int a);
};

struct FUN_00c8d090_node
{
    FUN_00c8d090_item* m_pInventoryEntryData;
    FUN_00c8d090_node* m_pNext;
};

struct FUN_00c8d090_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00c8d090_node m_14;

    bool Check(int a);
    bool CheckAndNotify(int a);
};

// Calls Check(a); if it succeeds, walks the m_14 linked list and calls v15(a) on each item, returning the Check result.
// @fnv 0x00c8d090
bool FUN_00c8d090_cls::CheckAndNotify(int a)
{
    bool ok = Check(a);
    if (ok)
    {
        FUN_00c8d090_node* node = &m_14;
        if (node != 0)
        {
            do
            {
                FUN_00c8d090_item* item = node->m_pInventoryEntryData;
                if (item == 0)
                {
                    break;
                }
                item->v15(a);
                node = node->m_pNext;
            } while (node != 0);
        }
    }
    return ok;
}

struct FUN_00c8d0d0_Node
{
    void* m_item;
    FUN_00c8d0d0_Node* m_next;
};

struct FUN_00c8d0d0_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00c8d0d0_Node m_list;

    int GetNodeCount();
};

// @fnv 0x00c8d0d0
int FUN_00c8d0d0_Object::GetNodeCount()
{
    int count = 0;
    FUN_00c8d0d0_Node* node = &this->m_list;

    while (node && node->m_item)
    {
        ++count;
        node = node->m_next;
    }

    return count;
}


// The referenced-object lock singleton that DAT_012681d4 points to.
struct FUN_00c90820_lock
{
    void* unk00;
    int unk04;
    int m_multiThreaded;
    int m_lLockCount;
    int unk10;
    int unk14;
    CRITICAL_SECTION m_kCriticalSection;
};

// @fnv 0x00c90820
CRITICAL_SECTION* __cdecl FUN_00c90820(void)
{
    return &reinterpret_cast<FUN_00c90820_lock*>(DAT_012681d4)->m_kCriticalSection;
}

class C90830ReferencedObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    C90830ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual ~C90830ReferencedObject()
    {}
};

struct C90830Stream
{
    int m_iHandle;
    unsigned short m_usFlags;

    C90830Stream() : m_iHandle(-15), m_usFlags(0x8000)
    {}
};

struct C90830CriticalSection
{
    CRITICAL_SECTION m_kSection;

    C90830CriticalSection(int iSpinCount) throw();
};

class FUN_00c90830 : public C90830ReferencedObject
{
  public:
    int m_iFadeIndex;
    int m_iArrayLength;
    C90830Stream m_kVertexStream;
    C90830CriticalSection m_kLock;

    FUN_00c90830();
    virtual ~FUN_00c90830();
};

// @fnv 0x00c90830
FUN_00c90830::FUN_00c90830() : m_kLock(4000)
{
    m_iFadeIndex = 1;
    reinterpret_cast<::hkMultiThreadCheckCF6E *>(&(m_kVertexStream))->ResetThreadCheck();
    m_iArrayLength = 0;
}


struct FUN_00c90e00
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float m_24;

    FUN_00c90e00(int flag);
};

// If flag is set and m_24 equals DAT_01012060, sets m_24 to 1.0f.
// @fnv 0x00c90e00
FUN_00c90e00::FUN_00c90e00(int flag)
{
    if (flag)
    {
        if ((double)m_24 == ::_DAT_01012060)
            m_24 = 1.0f;
    }
}

namespace fnv_00c99f80 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};


struct SpawnedObject18
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* Tail();
};

// @fnv 0x00c99f80
void* __cdecl AllocateSpawnedObject()
{
    AllocHolder* holder = static_cast<AllocHolder*>(::FUN_00c85750());
    SpawnedObject18* obj = (SpawnedObject18*)holder->m_pAllocator->Alloc(0x18);
    obj->m_w04 = 0x18;
    return ((void *)(new ((void *)(obj)) ::fnv_00c99eb0::FUN_00c99eb0()));
}
}  // namespace fnv_00c99f80


// @fnv 0x00c99fe0
void* __cdecl FUN_00c99fe0()
{
    return &(*reinterpret_cast<int *>(&::g_012681e8));
}

struct FUN_00653290_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_00c9a430_arg
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00653290_cls* unk0C;
};

struct FUN_00c9a430_cls
{
    int unk00;
    int unk04;
    FUN_00653290_cls* GetMatchingObject(FUN_00c9a430_arg* arg);
};


// @fnv 0x00c9a430
FUN_00653290_cls* FUN_00c9a430_cls::GetMatchingObject(FUN_00c9a430_arg* arg)
{
    if (arg == 0)
        return 0;

    FUN_00653290_cls* object = arg->unk0C;
    if (object == 0)
        return 0;

    FUN_00653290_cls* result = ((::FUN_00653290_cls *)(reinterpret_cast<::NiObject *>((object))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681c0))))));
    if (result != 0 && (this->unk04 & result->unk10) != 0)
        return result;

    return 0;
}

struct FUN_00c9a660_cls
{
    float m_00;
    float m_04;
    float m_08;

    bool NotEqual(const FUN_00c9a660_cls* other) const;
};

// Returns true when any of the three floats differs from the corresponding float in other.
// @fnv 0x00c9a660
bool FUN_00c9a660_cls::NotEqual(const FUN_00c9a660_cls* other) const
{
    int r = (m_00 == other->m_00 && m_04 == other->m_04 && m_08 == other->m_08) ? 1 : 0;
    return !(char)r;
}

struct FUN_00c9a840_cls
{
    struct Vec3
    {
        float x;
        float y;
        float z;
    };
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
    Vec3* m_pVerts;
    int unk40;
    int unk44;
    unsigned int m_uiItemCount;

    bool FUN_00c9a840(FUN_00c9a840_cls* other);
};
// @fnv 0x00c9a840
bool FUN_00c9a840_cls::FUN_00c9a840(FUN_00c9a840_cls* other)
{
    bool eq = ::FUN_00a6cc80((::TCEq *)this, (intptr_t)(other), {});
    if (eq)
    {
        eq = (m_uiItemCount == other->m_uiItemCount);
        unsigned int i = 0;
        while (eq && i < m_uiItemCount)
        {
            unsigned int off = i * 12;
            Vec3* pb = (Vec3*)((char*)other->m_pVerts + off);
            Vec3* pa = (Vec3*)((char*)m_pVerts + off);
            eq = (pa->x == pb->x) && (pa->y == pb->y) && (pa->z == pb->z);
            i++;
        }
    }
    return eq;
}


struct FUN_00c9ab10_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float* unk3c;
    int unk40;
    int unk44;
    int unk48;

    void FUN_00c9ab10();
};

// @fnv 0x00c9ab10
void FUN_00c9ab10_class::FUN_00c9ab10()
{
    float value = 0.0f;
    float result = 0.0f;

    int count = this->unk48;
    if (count != 0)
    {
        float* values = this->unk3c;
        float first = values[0];

        value = this->unk14;
        result = this->unk18;

        if (value > first || value == ::_DAT_010231b0)
        {
            value = first;
        }

        float last = values[count * 3 - 3];

        if (result > last || result == ::DAT_010241b0)
        {
            result = last;
        }
    }

    this->unk14 = value;
    this->unk18 = result;
}

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct Elem_c9ac00
{
    float a;
    float b;
    float c;
    Elem_c9ac00()
    {}
    Elem_c9ac00(int i)
    {
        float f = (float)(i / 100.0);
        a = -1.0f;
        b = f;
        c = f;
    }
    Elem_c9ac00& operator=(const Elem_c9ac00& o)
    {
        a = o.a;
        b = o.b;
        c = o.c;
        return *this;
    }
    bool operator!=(const Elem_c9ac00& o) const
    {
        return a != o.a || b != o.b || c != o.c;
    }
};

struct LargeArray_c9ac00
{
    void** m_ppVirtualMethodTable;
    Elem_c9ac00* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};

// @fnv 0x00c9ac00
void LargeArray_c9ac00::Resize(unsigned int uiNewMaxSize)
{
    if (uiNewMaxSize == m_uiMaxSize)
        return;

    unsigned int i;
    if (uiNewMaxSize < m_uiSize)
    {
        for (i = uiNewMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != Elem_c9ac00(0))
            {
                m_pBase[i] = Elem_c9ac00(0);
                m_uiESize--;
            }
        }
        m_uiSize = uiNewMaxSize;
    }

    Elem_c9ac00* pOldElements = m_pBase;
    m_uiMaxSize = uiNewMaxSize;
    if (uiNewMaxSize > 0)
    {
        m_pBase = (Elem_c9ac00*)NiMalloc(sizeof(Elem_c9ac00) * m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
            m_pBase[i] = pOldElements[i];
        for (i = m_uiSize; i < m_uiMaxSize; i++)
            m_pBase[i] = Elem_c9ac00(0);
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pOldElements);
}

void FUN_00aa10f0(int value);

struct SubObject_c9ad60
{
    int m_00;

    virtual ~SubObject_c9ad60();
};

struct Base_c9ad60
{
    virtual void unk00();
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

    ~Base_c9ad60();
};

class FUN_00c9ad60_cls : public Base_c9ad60
{
  public:
    SubObject_c9ad60 m_38;

    virtual ~FUN_00c9ad60_cls();
};
// @fnv 0x00c9af20
void* FUN_00c9af20_class::FUN_00c9af20(int aiFlags)
{
    reinterpret_cast<::FUN_00c9ad60_cls *>(this)->FUN_00c9ad60_cls::~FUN_00c9ad60_cls();
    if (aiFlags & 1)
        _delete(this, 0x5c);
    return this;
}

SubObject_c9ad60::~SubObject_c9ad60()
{
    FUN_00aa10f0(m_00);
}

// Destructor of the class; the empty body relies on the implicit destruction of the m_38 sub-object, which releases its m_00 via FUN_00aa10f0.
// @fnv 0x00c9ad60
FUN_00c9ad60_cls::~FUN_00c9ad60_cls()
{}

// FUN_00c9add0 : a one-line function - getter
// @fnv 0x00c9add0
void* FUN_00c9add0()
{
    return &(*reinterpret_cast<int *>(&::g_012681f0));
}

struct S_00c9af40_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_00c9af40_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(S_00c9af40_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_00c9af40_Stream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    char unk1e4;
    char unk1e5, unk1e6, unk1e7;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    S_00c9af40_BinStream* unk250;
};

struct S_00c9af40_Point
{
    float x, y, z;
    S_00c9af40_Point()
    {}
    S_00c9af40_Point(const S_00c9af40_Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};
template <class T> inline void WriteBinaryArray(S_00c9af40_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
inline void SwapFloat(float& f)
{
    unsigned int u = *(unsigned int*)&f;
    *(unsigned int*)&f = _byteswap_ulong(u);
}
inline void SwapPoint(S_00c9af40_Point& p)
{
    SwapFloat(p.y);
    SwapFloat(p.x);
    SwapFloat(p.z);
}
struct S_00c9af40_Base
{
};
struct S_00c9af40_Obj : S_00c9af40_Base
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    S_00c9af40_Point* unk3c;
    int unk40;
    int unk44;
    unsigned int unk48;
    void WriteToStream(S_00c9af40_Stream& kStream);
};
// @fnv 0x00c9af40
void S_00c9af40_Obj::WriteToStream(S_00c9af40_Stream& kStream)
{
    reinterpret_cast<::FUN_00a6d730_shell *>(this)->FUN_00a6d730((::Stream_a6d730 &)(kStream));
    unsigned int uiPointCount = unk48;
    WriteBinaryArray(*kStream.unk250, &uiPointCount, 1);
    for (unsigned int i = 0; i < uiPointCount; i++)
    {
        S_00c9af40_Point kPoint = unk3c[i];
        if (kStream.unk1e4 != 1)
            SwapPoint(kPoint);
        WriteBinaryArray(*kStream.unk250, &kPoint, 1);
    }
}

namespace fnv_00c9b1a0 {
struct TlsBlock_t
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00c9b1a0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00c9b1a0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00c9b1a0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct ItemArraySub_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int unk10;
    unsigned int m_14;
    void SetElement(unsigned int a, uintptr_t b);
};

struct FUN_00c9b1a0_cls
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
    int m_34;
    ItemArraySub_cls m_38;
    void FUN_00c9b1a0(uintptr_t arg);
};

// @fnv 0x00c9b1a0
void FUN_00c9b1a0_cls::FUN_00c9b1a0(uintptr_t arg)
{
    TlsGuard_t guard;
    ItemArraySub_cls* p = &m_38;
    unsigned int count = p->m_0C;
    if (count >= p->m_08)
    {
        reinterpret_cast<::LargeArray_c9ac00 *>((p))->Resize(p->m_14 + count);
    }
    p->SetElement(count, arg);
    m_34 = 0;
    reinterpret_cast<::FUN_00c9ab10_class *>(this)->FUN_00c9ab10();
}
}  // namespace fnv_00c9b1a0


class C9B970MemContext
{
  public:
    C9B970MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~C9B970MemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious;
    }

    int m_iPrevious;
};

struct C9B970Entry
{
    int unk00;
    int unk04;
    int unk08;
};

class C9B970Array
{
  public:

    int unk00;
    C9B970Entry* m_pkEntryArray;
    int unk08;
    int unk0C;
    unsigned int m_uiSize;
};

class C9B970Base
{
  public:

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
};

class C9B970Object : public C9B970Base
{
  public:
    void CloneTo(C9B970Object* pkDest, void* pvCloning);

    int m_iValue;
    C9B970Array m_kEntries;
};

// @fnv 0x00c9b970
void C9B970Object::CloneTo(C9B970Object* pkDest, void* pvCloning)
{
    C9B970MemContext kContext(0x10);
    reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(pkDest), (*(::CloningProcess *)(pvCloning)));
    pkDest->m_iValue = m_iValue;
    reinterpret_cast<::LargeArray_c9ac00 *>(&(pkDest->m_kEntries))->Resize(m_kEntries.m_uiSize);
    for (unsigned int i = 0; i < m_kEntries.m_uiSize; i++)
        reinterpret_cast<::fnv_00c9b1a0::FUN_00c9b1a0_cls *>((pkDest))->FUN_00c9b1a0((uintptr_t)(&m_kEntries.m_pkEntryArray[i]));
}

namespace fnv_00c9ba40 {
struct ReadScope
{
    int previous;
    ReadScope() : previous((*reinterpret_cast<int *>(&::currentAllocationContext)))
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~ReadScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};
struct BinaryInput
{
    void* vtable;
    unsigned int position;
    unsigned int (*read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadCount(unsigned int& value)
    {
        unsigned int componentSize = 4;
        Read(&value, 4, &componentSize, 1);
    }
    void Read(void* data, unsigned int bytes, unsigned int* components, unsigned int count)
    {
        position += read(this, data, bytes, components, count);
    }
};
struct StreamInput
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned char unk1E4;
    unsigned char nativeEndian;
    unsigned short unk1E6;
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
    BinaryInput* input;
};
struct SerializedPoint
{
    float first, second, third;
    SerializedPoint(float value = -1.0f, float percentage = 0.0f)
        : first(value), second(percentage / 100.0), third(percentage / 100.0)
    {}
};
struct PointCollection
{
};
struct PointLoader
{
    unsigned int unk00;
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
    PointCollection points;
    void FUN_00c9ba40(StreamInput*);
};
// @fnv 0x00c9ba40
void PointLoader::FUN_00c9ba40(StreamInput* stream)
{
    ReadScope scope;
    reinterpret_cast<::NiTimeController_Luna *>(this)->FUN_00a6d5e0((*(::NiStream *)(stream)));
    unsigned int count;
    stream->input->ReadCount(count);
    reinterpret_cast<::LargeArray_c9ac00 *>(&(points))->Resize(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        SerializedPoint point;
        stream->input->Read(&point, 12, 0, 0);
        if (stream->nativeEndian != 1)
        {
            *reinterpret_cast<unsigned long*>(&point.second) =
                _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.second));
            *reinterpret_cast<unsigned long*>(&point.first) =
                _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.first));
            *reinterpret_cast<unsigned long*>(&point.third) =
                _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.third));
        }
        reinterpret_cast<::fnv_00c9b1a0::FUN_00c9b1a0_cls *>(this)->FUN_00c9b1a0((uintptr_t)&(point));
    }
}
}  // namespace fnv_00c9ba40

namespace fnv_00c9bef0 {
struct TlsBlock_t
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct FUN_00c9bef0_cls
{
    FUN_00c9aeb0_t* CreateObject(intptr_t arg);
};

// @fnv 0x00c9bef0
FUN_00c9aeb0_t* FUN_00c9bef0_cls::CreateObject(intptr_t arg)
{
    TlsGuard_t guard;
    FUN_00c9aeb0_t* obj = new FUN_00c9aeb0_t();
    reinterpret_cast<::C9B970Object *>((this))->CloneTo((::C9B970Object *)(obj), (void *)(arg));
    return obj;
}
}  // namespace fnv_00c9bef0

struct FUN_00c9ea90_Base
{
    virtual void b0();
    FUN_00c9ea90_Base(int a, int b);
};

struct FUN_00c9ea90 : FUN_00c9ea90_Base
{
    virtual void v0();

    FUN_00c9ea90(int a1);
};

// @fnv 0x00c9ea90
FUN_00c9ea90::FUN_00c9ea90(int aiValue) : FUN_00c9ea90_Base(aiValue, 2)
{
    char* self = (char*)this;
    *(volatile int*)(self + 0x8c) = 0;
    *(volatile int*)(self + 0x90) = 0;
    *(volatile unsigned int*)(self + 0x94) = 0x80000000u;
    *(volatile int*)(self + 0x98) = 0;
    *(volatile int*)(self + 0x9c) = 0;
    *(volatile unsigned int*)(self + 0xa0) = 0x80000000u;
    char* pa = self + 0x10;
    *(unsigned char*)(pa + 0x10) = (unsigned char)((uintptr_t)self - (uintptr_t)pa);
}

namespace fnv_00c9eae0 {
// FUN_00c9eae0 : cdecl one-arg entry point that forwards a record pointer and
// a 16-bit count field to the game allocator's virtual slot 2.

struct FUN_00c9eae0_alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned short count);
};

struct FUN_00c9eae0_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00c9eae0_alloc* m_pAllocator;
};


struct FUN_00c9eae0_rec
{
    int unk00;
    unsigned short m_w04;
};

// @fnv 0x00c9eae0
void __cdecl FUN_00c9eae0(FUN_00c9eae0_rec* rec)
{
    FUN_00c9eae0_holder* holder = static_cast<FUN_00c9eae0_holder*>(::FUN_00c85750());
    FUN_00c9eae0_alloc* allocator = holder->m_pAllocator;
    unsigned short count = rec->m_w04;
    allocator->v2(rec, count);
}
}  // namespace fnv_00c9eae0

namespace fnv_00c9eb00 {
struct FnvCpu_FUN_00c9eb00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00c9eb00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00c9eb00_CpuAllocator* allocator;
};
struct FnvCpu_FUN_00c9eb00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00c9eb00_CpuObject* FUN_00c9eb00(unsigned int flags);
};
// @fnv 0x00c9eb00
FnvCpu_FUN_00c9eb00_CpuObject* FnvCpu_FUN_00c9eb00_CpuObject::FUN_00c9eb00(unsigned int flags)
{
    reinterpret_cast<::FUN_00d08130 *>(this)->FUN_00d08130::~FUN_00d08130();
    if (flags & 1)
    {
        FnvCpu_FUN_00c9eb00_CpuAllocatorHolder* holder = static_cast<FnvCpu_FUN_00c9eb00_CpuAllocatorHolder*>(::FUN_00c85750());
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00c9eb00

struct TreeResultData
{
    int unk00;
    int unk04;
    void* m_pIntegerData;
};

// Recursively walks the node tree, appending each node's result value to arr, growing arr via ResizeAudioStream when full.
// @fnv 0x00c80930
void __cdecl CollectTreeResultValues(TreeNode_cls* node, SpawnedPtrArray* arr)
{
    TreeHost_cls* host;
    TreeResult_cls* result;
    TreeResultData* data;
    void* value;
    SpawnedAllocHolder* holder;
    TreeNode_cls* child;
    void** slot;
    unsigned int i;

    if (node)
    {
        host = node->m_1c;
        if (host)
        {
            result = ((::TreeResult_cls *)(reinterpret_cast<::NiObject *>((host))->DynamicCast((const ::NiRTTI *)(unsigned int *)(&(*reinterpret_cast<unsigned int *>(&::g_012043f8))))));
            if (result)
            {
                data = result->unk10;
                if (data)
                {
                    value = data->m_pIntegerData;
                    holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
                    if (arr->m_uiCount == (arr->m_uiCapacity & 0x3fffffff))
                    {
                        ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(arr), 4);
                    }
                    slot = arr->m_pData + arr->m_uiCount;
                    *slot = value;
                    slot[0] = value;
                    arr->m_uiCount++;
                }
            }
        }
        child = node->v03();
        if (child)
        {
            i = 0;
            while (i < child->m_a6)
            {
                CollectTreeResultValues(child->m_a0[i], arr);
                i++;
            }
        }
    }
}

// Give the object an emissive material of the given color, notify listeners, then update it through the owner.

struct C11F0Color
{
    float r;
    float g;
    float b;
};

class C11F0Object;



class C11F0Material
{
  public:
    C11F0Material();
    virtual ~C11F0Material();


    void SetEmittance(const C11F0Color& kColor)
    {
        m_kEmissive = kColor;
        m_uiRevisionID++;
    }

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    C11F0Color m_kEmissive;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int m_uiRevisionID;
    int unk48;
};

class C11F0Object
{
  public:
};

class C11F0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void UnkC4();
    virtual void UnkC8();
    virtual void UnkCC();
    virtual void UnkD0();
    virtual void UnkD4();
    virtual void UnkD8();
    virtual void UpdateObject(C11F0Object* pkObject, bool bForce);
};

// @fnv 0x00c811f0
void AttachEmissiveMaterial(C11F0Object* pkObject, C11F0Owner* pkOwner, int m_uiSoundID, C11F0Color* pkColor)
{
    C11F0Color kColor = *pkColor;
    if (g_bC11F0Debug)
        ::FUN_00c84cd0(m_uiSoundID, &kColor);

    C11F0Material* pkMaterial = new C11F0Material;
    pkMaterial->SetEmittance(kColor);
    reinterpret_cast<::FUN_00439410_cls *>((pkObject))->FUN_00439410((::ArgObject *)(pkMaterial));

    if (g_pfnC11F0EmissiveChanged)
        g_pfnC11F0EmissiveChanged(pkObject, &kColor);

    pkOwner->UpdateObject(pkObject, true);
}

typedef int(__cdecl* NiBinaryStream_fn)(void* s, void* buf, unsigned int n, int* out, int flag);

struct NiBinaryStream
{
    void* m_00;
    unsigned int m_04;
    NiBinaryStream_fn m_08;

    unsigned int BinaryRead(void* p, unsigned int n, int* sizes, unsigned int count)
    {
        unsigned int read = m_08(this, p, n, sizes, count);
        m_04 += read;
        return read;
    }
};

class NiObject;
struct NiStream
{
    int m_00;
    unsigned int m_04;
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
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_24c;
public:
    ::NiObject *GetLoadedObject();
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    int uiSize = sizeof(T);
    kIstr->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream* kStream, T& value)
{
    NiBinaryStreamLoad(kStream->m_24c, &value);
}

struct C818F0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00c818f0(NiStream* p);
};

// @fnv 0x00c818f0
void C818F0_cls::FUN_00c818f0(NiStream* pStream)
{
    int buf;
    reinterpret_cast<::Stub65800 *>(this)->FUN_00c65800((*(::BC6C330Stream *)(pStream)));
    ReadBinaryValue(pStream, m_18);
    ReadBinaryValue(pStream, m_1c);
    if (pStream->m_04 < 8)
    {
        ReadBinaryValue(pStream, buf);
        ReadBinaryValue(pStream, buf);
    }
}

struct S_00c81b40_Callee
{
    virtual void m_v01();
    virtual void m_v02();
    virtual void m_v03();
    virtual void m_v04();
    virtual void m_v05();
    virtual void m_v06();
    virtual void m_v07();
    virtual void m_v08();
    virtual void m_v09();
    virtual void m_v10();
    virtual void m_v11();
    virtual void m_v12();
    virtual void m_v13();
    virtual void m_v14();
    virtual void m_v15();
    virtual void m_v16();
    virtual void m_v17();
    virtual void m_v18();
    virtual void m_v19();
    virtual void m_v20();
    virtual void m_v21();
    virtual void m_v22();
    virtual void m_v23();
    virtual void m_v24();
    virtual void m_v25();
    virtual void m_v26();
    virtual void m_v27();
    virtual void m_v28();
    virtual void m_v29();
    virtual void m_v30();
    virtual void m_v31();
    virtual void m_v32();
    virtual void m_v33();
    virtual void m_v34();
    virtual void m_v35();
    virtual void m_v36();
    virtual void m_v37();
    virtual void m_v38();
    virtual void m_v39();
    virtual void m_v40(int* argument);

    int unk04;
    unsigned char* m_data8;
};

struct S_00c81b40_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c81b40_Callee* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int* unk24;
    int unk28;

    void UpdateCountdown();
};

// Decrements unk28; when it reaches zero, checks the callee's data flags for 8 or 0x1d and calls m_v40 with unk24.
// @fnv 0x00c81b40
void S_00c81b40_Owner::UpdateCountdown()
{
    unk28--;

    if (unk28 > 0)
        return;

    S_00c81b40_Callee* callee = unk10;
    unk28 = 0;

    if (callee == 0)
        return;

    unsigned char* data = callee->m_data8;

    if (data != 0)
        data += 0x10;

    unsigned int flags = data ? *(unsigned int*)(data + 0x1c) : 0;

    flags &= 0x7f;

    if (flags != 8 && flags != 0x1d)
        return;

    int* argument = unk24;
    if (argument == 0)
        return;

    callee->m_v40(argument);
}


__forceinline bool GetFlagBit8(unsigned short f)
{
    return (f >> 8) & 1;
}
__forceinline bool GetFlagBit9(unsigned short f)
{
    return (f >> 9) & 1;
}
struct FUN_00c825b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1c;
    int unk20;
    int m_i24;

    void FUN_00c66060(ViewerStrings* pkStrings);
    void AddToViewerStrings(ViewerStrings* pkStrings);
};

// @fnv 0x00c825b0
void FUN_00c825b0_cls::AddToViewerStrings(ViewerStrings* pkStrings)
{
    TlsGuard_t guard;
    FUN_00c66060(pkStrings);
    char* pcString;
    pcString = ::FUN_00a7d330((*reinterpret_cast<char * *>(&::g_01267e64)));
    pkStrings->Add(pcString);
    pcString = ::FUN_00a7d550("fHeirGain", m_f18);
    pkStrings->Add(pcString);
    pcString = ::FUN_00a7d550("fVelGain", m_f1c);
    pkStrings->Add(pcString);
    pcString = ::FUN_00a7d370("bBlendPos", GetFlagBit8(m_usFlags));
    pkStrings->Add(pcString);
    pcString = ::FUN_00a7d370("bAlwaysBlend", GetFlagBit9(m_usFlags));
    pkStrings->Add(pcString);
    char buf[64];
    ::FUN_00406d00(buf, 64, "0x%08X", m_i24);
    pcString = ::fnv_00a7d5e0::FUN_00a7d5e0("Stored World", buf);
    pkStrings->Add(pcString);
}

struct FUN_00c84900_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int FUN_00c84900_call(unsigned int value);
};
struct FUN_00c84900_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int field20;
};
// Calls the caller's virtual method with value, passes the result and object->field20 to FUN_00c84740, and stores the returned byte in output.
// @fnv 0x00c84900
unsigned char* CallAndStoreResult(unsigned char* output, FUN_00c84900_object* object, int unused,
                                            FUN_00c84900_vtbl* caller, unsigned int value)
{
    unsigned int result = caller->FUN_00c84900_call(value);
    unsigned int field = object->field20;
    *output = ((unsigned char)(::FUN_00c84740(field, result)));
    return output;
}


extern const char* kFilterLayers[];
extern const char* kFilterParts[];

struct HavokFilterInfo
{
    unsigned int m_uFilterInfo;

    unsigned short GetGroup() const
    {
        return (unsigned short)(m_uFilterInfo >> 16);
    }
    unsigned int GetLayer() const
    {
        return m_uFilterInfo & 0x7F;
    }
    bool GetLink() const
    {
        return (m_uFilterInfo >> 15) & 1;
    }
    unsigned int GetPart() const
    {
        return (m_uFilterInfo >> 8) & 0x1F;
    }
    bool GetNoCol() const
    {
        return (m_uFilterInfo >> 14) & 1;
    }
    bool GetScaled() const
    {
        return (m_uFilterInfo >> 13) & 1;
    }

    void AppendToViewerStrings(ViewerStrings* pkStrings);
};

static __forceinline void AddString(ViewerStrings* pkStrings, char* pcString)
{
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, pcString);
}

// Formats the filter info and its group, layer, link, part, no-collision and scaled flags into prefixed strings appended to pkStrings.
// @fnv 0x00c849b0
void HavokFilterInfo::AppendToViewerStrings(ViewerStrings* pkStrings)
{
    char acBuffer[128];

    ::FUN_00406d00(acBuffer, sizeof(acBuffer), "0x%08X", m_uFilterInfo);
    AddString(pkStrings, ::fnv_00a7d5e0::FUN_00a7d5e0("COLFILTER", acBuffer));

    ::FUN_00406d00(acBuffer, sizeof(acBuffer), "0x%X", GetGroup());
    AddString(pkStrings, ::fnv_00a7d5e0::FUN_00a7d5e0("-GROUP", acBuffer));

    AddString(pkStrings, ::fnv_00a7d5e0::FUN_00a7d5e0("-LAYER", kFilterLayers[GetLayer()]));

    AddString(pkStrings, FUN_00a7d370("-LINK", GetLink()));

    if (GetLayer() == 8)
        goto LABEL_PART_STR;
    if (GetLayer() == 0x1D)
    {
    LABEL_PART_STR:
        const char* pszPart = kFilterParts[GetPart()];
        AddString(pkStrings, ::fnv_00a7d5e0::FUN_00a7d5e0("-PART", pszPart));
    }
    else if (GetLink())
    {
        AddString(pkStrings, FUN_00a7d510("-PART", GetPart()));
    }

    AddString(pkStrings, FUN_00a7d370("-NOCOL", GetNoCol()));

    AddString(pkStrings, FUN_00a7d370("-SCALED", GetScaled()));
}

struct FUN_00c84d50_arg
{
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00c;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01c;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02c;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03c;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04c;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05c;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06c;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07c;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08c;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09c;
    int m_unk0a0;
    int m_unk0a4;
    int m_unk0a8;
    int m_unk0ac;
    int m_unk0b0;
    int m_unk0b4;
    int m_unk0b8;
    int m_unk0bc;
    int m_unk0c0;
    int m_unk0c4;
    int m_unk0c8;
    int m_unk0cc;
    int m_unk0d0;
    int m_unk0d4;
    int m_unk0d8;
    int m_unk0dc;
    int m_unk0e0;
    int m_unk0e4;
    int m_unk0e8;
    int m_unk0ec;
    int m_unk0f0;
    int m_unk0f4;
    int m_unk0f8;
    int m_unk0fc;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10c;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11c;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12c;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13c;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14c;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15c;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16c;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17c;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18c;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19c;
    int m_unk1a0;
    int m_unk1a4;
    int m_unk1a8;
    int m_unk1ac;
    int m_unk1b0;
    int m_unk1b4;
    int m_unk1b8;
    int m_unk1bc;
    int m_unk1c0;
    int m_unk1c4;
    int m_unk1c8;
    int m_unk1cc;
    int m_unk1d0;
    int m_unk1d4;
    int m_unk1d8;
    int m_unk1dc;
    int m_unk1e0;
    unsigned char m_unk1e4;
};

struct FUN_00c84d50_cls
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
    virtual void v41(void* object);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual int* v45(void*& object);

    int m_unk04;
    int m_unk08;
    int m_unk0c;
    unsigned int m_flags;

    void FUN_00c84d50(void* arg);
};

// @fnv 0x00c84d50
void FUN_00c84d50_cls::FUN_00c84d50(void* arg)
{
    void* object;
    int* result = v45(object);
    unsigned int value = m_flags & 0x1fu;
    *result = value;

    FUN_00c84d50_arg* data = static_cast<FUN_00c84d50_arg*>(arg);
    if (data->m_unk1e4 != 1)
        *result = _byteswap_ulong(value);

    reinterpret_cast<::BC87850RefObject *>(this)->SaveSerializeData((*(::BC87850Stream *)(arg)));

    if (data->m_unk1e4 != 1)
        *result = _byteswap_ulong(*result);

    v41(object);
}

struct Out_00c85880
{
    int m_00;
    int m_04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    int unk0C;
    int m_10;
};

struct Sub_00c85880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char m_18;
    int m_1C;
};

struct State_00c85880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Sub_00c85880 m_10;
};

struct Owner_00c85880
{
    int unk00;
    int unk04;
    State_00c85880* m_08;

    void FillOutputFromState(Out_00c85880* o);
};

// Copies fields from the state's sub-structure into the output, then sets m_10 to 0 and m_00 from the sub-structure's m_1C or 0.
// @fnv 0x00c85880
void Owner_00c85880::FillOutputFromState(Out_00c85880* pOut)
{
    TlsGuard_t guard;

    State_00c85880* q = this->m_08;
    if (q)
    {
        Sub_00c85880* s = &q->m_10;
        if (s != 0)
        {
            pOut->m_04 = s->unk00;
            pOut->m_08 = s->m_18;
        }
    }

    pOut->m_10 = 0;

    State_00c85880* r = this->m_08;
    Sub_00c85880* sub = (r != 0) ? &r->m_10 : 0;
    pOut->m_00 = (sub != 0) ? sub->m_1C : 0;
}

struct NiFixedStrX
{
    char* m_str;
    NiFixedStrX(const char* str)
    {
        m_str = NiGlobalStringTable::AddString(str);
    }
    __forceinline ~NiFixedStrX()
    {
        if (m_str != ::DAT_0109b220)
            InterlockedDecrement((long*)(m_str - 8));
    }
};

struct NiNodeX
{
    int unk00;
    int unk04;
    char* m_name;
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
    NiNodeX(unsigned short count);
};

struct bhkWorldX
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void AddDebugNode(NiNodeX* node, NiPoint3* offset);
};

struct WorldHolder
{
    int unk00;
    int unk04;
    bhkWorldX* m_pOwningWorld;
};

struct PhantomData
{
    WorldHolder* m_holder;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_pCollisionShape;
};

struct WorldObjectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhantomData m_data;
};


struct bhkWorldObjectX
{
    int unk00;
    int unk04;
    WorldObjectX* m_obj;
    NiNodeX* AddDebugNodeToWorld(NiNodeX* node);
};

// Ensures node has a name, computes a point via GetLayerColor and adds the node to the world's debug nodes, returning the node.
// @fnv 0x00c85d70
NiNodeX* bhkWorldObjectX::AddDebugNodeToWorld(NiNodeX* node)
{
    PhantomData* data;
    WorldHolder* holder;
    bhkWorldX* world;
    if (this && m_obj && (data = &m_obj->m_data) != 0 && (holder = data->m_holder) != 0 &&
        (world = holder->m_pOwningWorld) != 0)
    {
        if (!node)
            node = new NiNodeX(0);
        if (!node->m_name)
        {
            NiFixedStrX name("bhkWorldObject");
            ::AssignFixedString((char *)(node), (intptr_t)&(name), {});
        }
        NiPoint3 pt;
        pt.x = 0.0f;
        pt.y = 0.0f;
        pt.z = 0.0f;
        PhantomData* pData2 = m_obj ? &m_obj->m_data : 0;
        ::GetLayerColor(pData2 ? pData2->m_pCollisionShape : 0, (*(::NiColor *)(&pt)));
        world->AddDebugNode(node, &pt);
        return node;
    }
    return node;
}


struct BC88760AllocTagScope
{
    int m_iSaved;

    BC88760AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BC88760AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class BC88760CloningProcess;

class BC88760Base
{
  public:

    BC88760Base();
    virtual ~BC88760Base();

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
};

class BC88760Derived : public BC88760Base
{
  public:
    BC88760Derived()
    {}
    virtual ~BC88760Derived();

    BC88760Derived* FUN_00c88760(BC88760CloningProcess& kCloning);
};

// @fnv 0x00c88760
BC88760Derived* BC88760Derived::FUN_00c88760(BC88760CloningProcess& kCloning)
{
    BC88760AllocTagScope kScope(0x10);
    BC88760Derived* pkClone = new BC88760Derived;
    reinterpret_cast<::FUN_00c81580_cls *>(this)->FUN_00c81580((::FUN_00c81580_cls *)(pkClone), (void *)&(kCloning));
    return pkClone;
}

class NiNode;
class NiAVObject;
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* pcString) : m_kHandle(NiGlobalStringTable::AddString(pcString))
    {}
    ~NiFixedString()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement(reinterpret_cast<long*>(m_kHandle - 8));
    }
};
class NiUpdateData
{
  public:
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bUnk8;
    NiUpdateData()
        : m_fTime(0.0f), m_bUpdate(false), m_bIsMultiThreaded(false), m_bUpdateGeomorphs(false),
          m_bUpdateShadowSceneNode(false), m_bUnk8(false)
    {}
};
struct FUN_00c88810_Collision
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
};
class NiAVObject
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* IsSceneNode();
    char pad04[0x14];
    NiNode* m_pParentNode;
    FUN_00c88810_Collision* m_spCollisionObject;
    void Update(const NiUpdateData& kUpdateData);
public:
    void UpdateWorldLoc();
};
class NiNode : public NiAVObject
{
  public:
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
    char pad20[0x9c - 0x20];
    NiTObjectArray<NiAVObject*> m_kChildList;
};
// Updates apObject, then for each child of the Chain01 node's parent with a collision object, calls Unk_2A and FUN_00c6a350.
// @fnv 0x00c88810
void UpdateChainCollision(NiAVObject* apObject)
{
    NiNode* pkRoot = apObject->IsSceneNode();
    if (!pkRoot)
        return;
    NiAVObject* pkChain = pkRoot->GetObjectByName("Chain01");
    if (!pkChain)
        return;
    reinterpret_cast<::FUN_00a59c60_cls *>((apObject))->FUN_00a59c60((std::intptr_t)&(const ::NiUpdateData &)(NiUpdateData()));
    NiNode* pkParent = pkChain->m_pParentNode;
    if (!pkParent)
        return;
    for (unsigned int i = 0; i < pkParent->m_kChildList.m_usSize; i++)
    {
        NiAVObject* pkChild = pkParent->m_kChildList.m_pBase[i];
        if (pkChild)
        {
            FUN_00c88810_Collision* pkCollision = pkChild->m_spCollisionObject;
            if (pkCollision)
            {
                pkCollision->Unk_2A();
                ::FUN_00c6a350((::NiAVObject *)(::NiNode *)((NiNode*)pkChild), 1, false, true, true);
            }
        }
    }
}

// LinkObject: resolve the two linked bodies and store their Havok entities in the constraint data.

class C8A910Stream
{
  public:
};

class C8A910Body
{
  public:
    int unk00;
    int unk04;
    void* m_pkEntity;
};

struct C8A910ConstraintData
{
    int unk00;
    void* m_pkEntityA;
    void* m_pkEntityB;
};

class C8A910Constraint
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual C8A910ConstraintData* GetConstraintData(unsigned int& ruiType);

    void FUN_00c8a910(C8A910Stream& kStream);
};

// @fnv 0x00c8a910
void C8A910Constraint::FUN_00c8a910(C8A910Stream& kStream)
{
    C8A910Body* pkBodyA = (C8A910Body*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject()));
    C8A910Body* pkBodyB = (C8A910Body*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject()));
    unsigned int uiType;
    C8A910ConstraintData* pkData = GetConstraintData(uiType);
    if (pkBodyA)
    {
        pkData->m_pkEntityA = pkBodyA->m_pkEntity;
        pkData->m_pkEntityB = pkBodyB ? pkBodyB->m_pkEntity : 0;
    }
    reinterpret_cast<::FUN_00c87670_Class *>(this)->FUN_00c87670((::NiStream &)(kStream));
}

class Dispatcher
{
  public:
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
    virtual void Dispatch(void* p);
};

class Node1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};

class Mid
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Node1* m_18;
    Node1* m_1c;
};

class RefChainOwner
{
  public:
    int unk00;
    int unk04;
    Mid* m_08;
    void DispatchChainNodes(Dispatcher* arg);
};

// Dispatches the m_0c payloads of the m_18 and m_1c nodes reached through m_08, then calls SaveSerializeData.
// @fnv 0x00c8aac0
void RefChainOwner::DispatchChainNodes(Dispatcher* pDispatcher)
{
    Node1* n = (this && m_08) ? m_08->m_18 : 0;
    void* q;
    switch (n != 0)
    {
    case 0:
        q = 0;
        break;
    default:
        q = n->m_0c;
        break;
    }
    pDispatcher->Dispatch(q);

    Node1* k = (this && m_08) ? m_08->m_1c : 0;
    void* r;
    switch (k != 0)
    {
    case 0:
        r = 0;
        break;
    default:
        r = k->m_0c;
        break;
    }
    pDispatcher->Dispatch(r);

    reinterpret_cast<::BC87850RefObject *>(this)->SaveSerializeData((*(::BC87850Stream *)(pDispatcher)));
}

extern void* __cdecl FUN_00aa13e0(size_t size);

struct Base_00c8ae60
{
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00c87c30();
    Base_00c8ae60()
    {
        FUN_00c87c30();
    }
};
struct Object_00c8ae60 : Base_00c8ae60
{
    Object_00c8ae60()
    {
        vtable = &DAT_01030bf4;
        unk0c = 0;
        unk10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
// Allocates and constructs a new Object_00c8ae60, returning the pointer.
// @fnv 0x00c8ae60
Object_00c8ae60* __cdecl FUN_00c8ae60()
{
    return new Object_00c8ae60;
}

// Forward a call to every child wrapper of this group's Havok object.

class C8B4D0Wrapper
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Apply(int iArg1, int iArg2);
};

struct C8B4D0Child
{
    int unk00;
    int unk04;
    C8B4D0Wrapper* m_pkWrapper;
};

struct C8B4D0Slot
{
    C8B4D0Child* m_pkChild;
    int unk04;
    int unk08;
    int unk0C;
};

class C8B4D0Counter
{
  public:
    virtual void Unk_00();
    virtual int GetCount();
};

struct C8B4D0HavokGroup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B4D0Counter m_kCounter;
    int unk14;
    C8B4D0Slot* m_pkSlots;
};

class C8B4D0Group
{
  public:
    int unk00;
    int unk04;
    C8B4D0HavokGroup* m_pkHavok;

    C8B4D0HavokGroup* GetHavok()
    {
        return this ? m_pkHavok : 0;
    }
    int GetChildCount()
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_kCounter.GetCount() : 0;
    }
    C8B4D0Child* GetChild(int i)
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_pkSlots[i].m_pkChild : 0;
    }

    void ApplyToChildren(int iArg1, int iArg2);
};

// Iterates all children of the group's havok data and calls Apply(iArg1, iArg2) on each child's wrapper if present.
// @fnv 0x00c8b4d0
void C8B4D0Group::ApplyToChildren(int iArg1, int iArg2)
{
    int iChildCount = GetChildCount();
    for (int i = 0; i < iChildCount; i++)
    {
        C8B4D0Child* pkChild = GetChild(i);
        C8B4D0Wrapper* pkWrapper = pkChild ? pkChild->m_pkWrapper : 0;
        if (pkWrapper)
            pkWrapper->Apply(iArg1, iArg2);
    }
}


struct C8B8A0Alloc;
struct C8B8A0Array;
struct C8B8A0Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(C8B8A0Alloc& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(::C8B8A0Alloc *)(&alloc), (::SpawnedArray *)(::C8B8A0Array *)(this), newSize, sizeof(int));
        }
    }
    void _setSize(C8B8A0Alloc& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        SpawnedAllocHolder* router = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        C8B8A0Alloc* allocator = (C8B8A0Alloc*)router->m_pAllocator;
        _setSize(*allocator, n);
    }
    void clear()
    {
        m_iElementCount = 0;
    }
};

struct C8B8A0Out
{
    int unk00;
    C8B8A0Array m_keys;
    C8B8A0Array m_iSlotIds;
};

struct C8B8A0Iface
{
    virtual void v00();
    virtual int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
    virtual int GetValue(void* it);
};

struct C8B8A0Entry
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
};

struct C8B8A0Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B8A0Iface m_iface;
    int unk14;
    C8B8A0Entry* m_entries;
};

struct MyObj
{
    int unk00;
    int unk04;
    C8B8A0Map* m_map;
    void FillKeyValueArrays(C8B8A0Out* out);
};

// Resizes the output key and value arrays to the map's entry count, then fills them with each entry's key and interface value.
// @fnv 0x00c8b8a0
void MyObj::FillKeyValueArrays(C8B8A0Out* out)
{
    reinterpret_cast<::This *>(this)->FUN_00c84e20((unsigned int *)(out));
    C8B8A0Map* m;
    unsigned int n = (this && (m = m_map) != 0) ? m->m_iface.GetCount() : 0;
    out->m_keys.clear();
    C8B8A0Array* keys = &out->m_keys;
    keys->SetSizeAndGrow(n);
    C8B8A0Array* values = &out->m_iSlotIds;
    values->SetSizeAndGrow(n);
    void* it = (this && (m = m_map) != 0) ? m->m_iface.GetFirst() : 0;
    for (unsigned int i = 0; i < n; i++)
    {
        keys->m_data[i] = (this && (m = m_map) != 0) ? m->m_entries[i].m_key : 0;
        values->m_data[i] = (this && (m = m_map) != 0) ? m->m_iface.GetValue(it) : 0;
        it = (this && (m = m_map) != 0) ? m->m_iface.GetNext(it) : 0;
    }
}


struct C8B9E0AllocTagScope
{
    int m_iSaved;

    C8B9E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~C8B9E0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class C8B9E0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};


template <class T> class C8B9E0Array
{
  public:
    C8B9E0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class C8B9E0Listener
{
  public:

    C8B9E0Listener() : m_pkOwnerManager(0)
    {}

    void* m_pkOwnerManager;
    C8B9E0Array<void*> m_kAdded;
    C8B9E0Array<void*> m_kRemoved;
};

class C8B9E0Owner
{
  public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    C8B9E0Listener* m_pkListener;

    C8B9E0Listener* GetOrCreateListener(bool* pbCreated);
};

// Sets *pbCreated when m_pkListener is null, allocates a listener and attaches it if m_pkWorld is set, then returns m_pkListener.
// @fnv 0x00c8b9e0
C8B9E0Listener* C8B9E0Owner::GetOrCreateListener(bool* pbCreated)
{
    C8B9E0AllocTagScope kScope(0x10);
    *pbCreated = (m_pkListener == 0);
    if (*pbCreated)
    {
        m_pkListener = new C8B9E0Listener;
        if (m_pkWorld)
            reinterpret_cast<::MyObj *>(this)->FillKeyValueArrays((::C8B8A0Out *)(m_pkListener));
    }
    return m_pkListener;
}

struct ListAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* data, int bytes);
};
struct ShapeArray
{
    FUN_00c8b000_Item** data;
    int size;
    int capacity;
    ShapeArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ShapeArray()
    {
        SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        ListAllocator* alloc = (ListAllocator*)holder->m_pAllocator;
        size = 0;
        if (!(capacity & 0x80000000))
        {
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        }
        data = 0;
        capacity = 0x80000000;
    }
    void swap(ShapeArray& other)
    {
        FUN_00c8b000_Item** oldData = data;
        data = other.data;
        other.data = oldData;
        int oldSize = size;
        size = other.size;
        other.size = oldSize;
        int oldCapacity = capacity;
        capacity = other.capacity;
        other.capacity = oldCapacity;
    }
};
struct ListShapeData
{
    unsigned int header;
    ShapeArray shapes;
    ShapeArray keys;
};
struct ListShapeSave
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
    virtual int GetDataSize();
    virtual void v43();
    virtual void v44();
    virtual ListShapeData* GetDataPosition(bool* owned);
    void SaveListShape(C8A4B0Stream* stream);
};
// @fnv 0x00c8baa0
void ListShapeSave::SaveListShape(C8A4B0Stream* stream)
{
    bool owned;
    ListShapeData* data = GetDataPosition(&owned);
    ShapeArray shapes;
    ShapeArray keys;
    data->shapes.swap(shapes);
    data->keys.swap(keys);
    if (reinterpret_cast<S_00c9af40_Stream*>(stream)->unk1e4 != 1)
    {
        int size = GetDataSize();
        ::FUN_00cf0930(reinterpret_cast<char*>(data), size, (::Vector3 *)(char *)(reinterpret_cast<char*>(&data->keys)));
        ::FUN_00cf0930(reinterpret_cast<char*>(data), size, (::Vector3 *)(char *)(reinterpret_cast<char*>(&data->shapes)));
    }
    unsigned int count = shapes.size;
    C8A4B0SaveBinary(*stream, count);
    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_00c8b000_Item* item = shapes.data[i];
        stream->SaveLinkID(item ? reinterpret_cast<C8A4B0Object*>(item->m_08) : 0);
    }
    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50(stream);
    ::SaveUIntArray((*(::CF4BC0Stream *)(stream)), (*(const ::ArrayData *)(&keys)));
    if (reinterpret_cast<S_00c9af40_Stream*>(stream)->unk1e4 != 1)
    {
        int size = GetDataSize();
        ::FUN_00cf0930(reinterpret_cast<char*>(data), size, (::Vector3 *)(char *)(reinterpret_cast<char*>(&data->keys)));
        ::FUN_00cf0930(reinterpret_cast<char*>(data), size, (::Vector3 *)(char *)(reinterpret_cast<char*>(&data->shapes)));
    }
}

// @fnv 0x00c8cdb0
unsigned int* __cdecl SwapEndianBlocks(unsigned int* auiData)
{
    volatile unsigned int* p = auiData + 2;
    int n = 3;
    do
    {
        p[-2] = _byteswap_ulong(p[-2]);
        p[-1] = _byteswap_ulong(p[-1]);
        p[0] = _byteswap_ulong(p[0]);
        p[1] = _byteswap_ulong(p[1]);
        p += 4;
    } while (--n != 0);
    return auiData;
}



struct AllocTagScopeC9A
{
    int m_iSaved;

    AllocTagScopeC9A(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~AllocTagScopeC9A()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class ObstacleDataC9A
{
  public:
    virtual ~ObstacleDataC9A();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class NiPointerC9A
{
  public:
    NiPointerC9A(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC9A()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

void __cdecl FreeNodeC9A(void* pvNode);

template <class T> class BSSimpleListC9A
{
  public:
    __declspec(noinline) void Remove(const T& kItem)
    {
        for (BSSimpleListC9A* pkNode = this; pkNode->m_pkNext; pkNode = pkNode->m_pkNext)
        {
            BSSimpleListC9A* pkNext = pkNode->m_pkNext;
            if (pkNext->m_item.m_pObject == kItem.m_pObject)
            {
                pkNode->m_pkNext = pkNext->m_pkNext;
                FreeNodeC9A(pkNext);
                return;
            }
        }
    }

    T m_item;
    BSSimpleListC9A* m_pkNext;
};

class ObstacleManagerC9A
{
  public:
    int unk00;
    int unk04;
    int unk08;
    BSSimpleListC9A<NiPointerC9A<ObstacleDataC9A> > m_kObstacles;

    void FUN_00c9a520(ObstacleDataC9A* pkData);
};

// Removes the given obstacle from m_kObstacles when pkData is non-null and its ref count is above zero.
// @fnv 0x00c9a520
void ObstacleManagerC9A::FUN_00c9a520(ObstacleDataC9A* pkData)
{
    AllocTagScopeC9A kScope(0x10);
    if (pkData && pkData->m_uiRefCount > 0)
        reinterpret_cast<::ListReader *>(&(m_kObstacles))->FUN_00631620((const ::NodeValue &)((const ::NiPointerC9A< ::ObstacleDataC9A> &)(pkData)));
}

struct FUN_00c9abc0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    short unk0a;
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
    float unk50;
    float unk54;
    void FUN_00c9abc0(intptr_t param2);
};

// If the flag bit in unk09 is set and unk50 is non-negative, writes unk50 and unk54 into param2 at offsets 0x18/0x1c and resets both to -1.0f.
// @fnv 0x00c9abc0
void FUN_00c9abc0_cls::FUN_00c9abc0(intptr_t param2)
{
    if ((unk09 & 1) != 0 && unk50 >= 0.0f)
    {
        *(float*)(param2 + 0x18) = unk50;
        *(float*)(param2 + 0x1c) = unk54;
        unk50 = unk54 = -1.0f;
    }
    return;
}

struct FUN_00c9a6c0
{
    float time, value1, value2;
    FUN_00c9a6c0();
};
struct TargetFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct TargetBody
{
    int unk00, unk04, unk08, unk0c;
    TargetFlags flags;
};
struct TargetLink
{
    int unk00, unk04;
    TargetBody* body;
    unsigned int GetFlags() const
    {
        TargetFlags* info = body ? &body->flags : 0;
        return info ? info->flags : 0;
    }
};
struct TargetExtra
{
    int unk00, unk04, unk08, unk0c;
    TargetLink* link;
    int unk14;
    float start, end;
    float GetStart() const
    {
        return start;
    }
    float GetEnd() const
    {
        return end;
    }
};
struct ExtraList
{
};
struct TargetController
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
    virtual void v35(float time);
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    float frequency, phase, start, end;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    LargeArray_c9ac00 keys;
    int unk50, unk54;
    unsigned int mode;
    void Reset();
};
struct SceneNode;
struct SceneObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneNode* AsNode();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    ExtraList* extras;
};
struct SceneNode : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity, childCount;
};
struct TimeRange
{
    float start, end;
};
extern TimeRange DAT_011b1090[];
extern TimeRange DAT_011b0f90[];
// Returns the smaller of two values by comparing b < a and returning b when true, otherwise a.
// @fnv 0x00c9b250
template <class T> inline T Minimum(const T& a, const T& b)
{
    return b < a ? b : a;
}
void FUN_00c9b250(SceneObject* object, float middle, bool alternate)
{
    if (!object)
        return;
    if (object->extras)
    {
        TargetExtra* extra = ((::TargetExtra *)(reinterpret_cast<::NiObject *>((object->extras))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_01267e64))))));
        if (extra)
        {
            unsigned int flags = 0;
            if (extra->link)
                flags = extra->link->GetFlags();
            unsigned int index = (flags >> 8) & 31;
            float first, last;
            if (alternate)
            {
                first = DAT_011b1090[index].start;
                last = DAT_011b1090[index].end;
            }
            else
            {
                first = DAT_011b0f90[index].start;
                last = DAT_011b0f90[index].end;
            }
            float start = Minimum(first, extra->GetStart());
            float end = Minimum(last, extra->GetEnd());
            TargetController* controller = ((::TargetController *)(reinterpret_cast<::MyHost *>((object))->FUN_00a5c570((const ::MyRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681f0))))));
            if (controller && controller->mode <= 1)
            {
                reinterpret_cast<::FUN_00c9a820_class *>((controller))->Reset();
                controller->mode = 1;
                if (controller->keys.m_uiESize == 0)
                {
                    FUN_00c9a6c0 keys[3];
                    keys[0].value1 = start;
                    keys[0].value2 = end;
                    keys[0].time = 0.0f;
                    keys[1].value1 = first;
                    keys[1].value2 = last;
                    keys[1].time = 0.15f;
                    keys[2].value2 = keys[2].value1 = 1.0f;
                    keys[2].time = 0.5f;
                    controller->keys.Resize(3);
                    for (unsigned int i = 0; i < 3; ++i)
                        reinterpret_cast<::fnv_00c9b1a0::FUN_00c9b1a0_cls *>((controller))->FUN_00c9b1a0((uintptr_t)(&keys[i]));
                    controller->start = 0.0f;
                    controller->end = 1.0f;
                    controller->frequency = 1.0f;
                    controller->phase = 0.0f;
                    controller->flags = (controller->flags & 0xfff5) | 0x1c5;
                    controller->v35(::DAT_01015f5c);
                }
            }
        }
    }
    SceneNode* node = object->AsNode();
    if (node)
        for (unsigned int i = 0; i < node->childCount; ++i)
            FUN_00c9b250(node->children[i], middle, alternate);
}

namespace fnv_00c9b470 {
struct LocalRTTI
{
};
extern float DAT_011b1190[];
struct PairRange
{
    float hi, lo;
};
struct bhkFilter
{
    unsigned int value;
};
using HavokPart = ::FUN_00c81aa0_worldObject;
struct Entity
{
    unsigned int unk00, unk04;
    HavokPart* unk08;
    void FUN_00626cb0(unsigned int);
};
struct Collision
{
    unsigned int unk00, unk04, unk08, unk0C;
    Entity* unk10;
};
struct Physics
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57(int);
    bhkFilter FUN_0043b4f0();
};
struct CollisionPhysics
{
    unsigned int unk00, unk04, unk08, unk0C;
    Physics* unk10;
};
struct FUN_00c9a6c0
{
    float x, y, z;
    FUN_00c9a6c0();
};
struct ControllerArray
{
};
struct Controller
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
    virtual void v35(float);
    unsigned int unk04;
    unsigned short flags;
    unsigned short unk0A;
    float unk0C, unk10, unk14, unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    ControllerArray unk38;
    unsigned int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
};
struct CastSource
{
};
struct Scene
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Scene* v3();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    CastSource* unk1C;
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
    Scene** children;
    unsigned short cap, count;
};
// Looks up collision/physics data on the object, configures a controller with scaled key points, and recurses into child scenes.
// @fnv 0x00c9b470
void ApplyCollisionEffect(Scene* object, float time)
{
    if (!object)
        return;
    Collision* collision;
    if (object->unk1C && (collision = (Collision*)((void *)(reinterpret_cast<::NiObject *>((object->unk1C))->DynamicCast((const ::NiRTTI *)(const ::fnv_00c9b470::LocalRTTI *)(&(*reinterpret_cast<::fnv_00c9b470::LocalRTTI *>(&::g_01267e64))))))) != 0)
    {
        unsigned int filter = 0;
        Entity* entity = collision->unk10;
        if (entity)
        {
            HavokPart* part = entity->unk08;
            filter = part ? part->m_collidable.m_collisionFilterInfo : 0;
            filter = (filter & ~0x77u) | 8;
            entity->FUN_00626cb0(filter);
        }
        unsigned int layer = (filter >> 8) & 31;
        float scale = DAT_011b1190[layer];
        Controller* controller = ((::fnv_00c9b470::Controller *)(reinterpret_cast<::MyHost *>((object))->FUN_00a5c570((const ::MyRTTI *)(const ::fnv_00c9b470::LocalRTTI *)(&(*reinterpret_cast<::fnv_00c9b470::LocalRTTI *>(&::g_012681f0))))));
        if (controller && scale >= 0.0f)
        {
            float hi = (*reinterpret_cast<fnv_00c9b470::PairRange (*)[]>(&::g_akC819A0Ranges))[layer].hi;
            float lo = (*reinterpret_cast<fnv_00c9b470::PairRange (*)[]>(&::g_akC819A0Ranges))[layer].lo;
            reinterpret_cast<::FUN_00c9a820_class *>((controller))->Reset();
            controller->unk58 = 2;
            if (!controller->unk48)
            {
                FUN_00c9a6c0 points[2];
                points[0].x = points[0].z = points[0].y = 0.0f;
                points[1].y = hi;
                points[1].z = lo;
                points[1].x = scale;
                reinterpret_cast<::LargeArray_c9ac00 *>(&(controller->unk38))->Resize(2);
                for (int i = 0; i < 2; ++i)
                    reinterpret_cast<::fnv_00c9b1a0::FUN_00c9b1a0_cls *>((controller))->FUN_00c9b1a0((uintptr_t)(&points[i]));
                controller->flags = (controller->flags & 0xfef5) | 0xc5;
                controller->unk14 = time;
                controller->unk18 = scale;
                controller->unk10 = 0.0f;
                controller->unk0C = 1.0f;
                controller->v35(::DAT_01015f5c);
            }
        }
    }
    else if (object->unk1C)
    {
        CollisionPhysics* pCollisionPhysics = (CollisionPhysics*)((void *)(reinterpret_cast<::NiObject *>((object->unk1C))->DynamicCast((const ::NiRTTI *)(const ::fnv_00c9b470::LocalRTTI *)(&(*reinterpret_cast<::fnv_00c9b470::LocalRTTI *>(&::g_012043f8))))));
        if (pCollisionPhysics && pCollisionPhysics->unk10)
        {
            Physics* physics = pCollisionPhysics->unk10;
            unsigned int filter = physics->FUN_0043b4f0().value;
            unsigned int layer = filter & 0x7f;
            if ((layer != 8 && layer != 29) || (filter & 0x1f00) == 0x1400)
                physics->v57(4);
        }
    }
    Scene* node = object->v3();
    if (node)
        for (unsigned int i = 0; i < node->count; ++i)
            ApplyCollisionEffect(node->children[i], time);
}
}  // namespace fnv_00c9b470

struct Node253;
struct HavokObject253
{
    int unk00, unk04, unk08;
    Node253* owner;
};
struct PhysicsData253
{
    int unk00;
    HavokObject253* first;
    HavokObject253* second;
};
struct Map253
{
};
struct CloneProcess253
{
    Map253* map;
};
struct Node253
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
    virtual Node253* Clone(void* process);
    int references;
    HavokObject253* object;
};
struct Owner253
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual PhysicsData253* GetData(bool* temporary);
    void ClonePhysicsData(void* destination, void* process);
};
// @fnv 0x00c8a850
void Owner253::ClonePhysicsData(void* destination, void* process)
{
    bool temporary;
    PhysicsData253* data = GetData(&temporary);
    Node253* first = data->first ? data->first->owner : 0;
    Node253* second = data->second ? data->second->owner : 0;
    CloneProcess253* context = static_cast<CloneProcess253*>(process);
    data->first = 0;
    data->second = 0;
    if (reinterpret_cast<::A54440Hash *>((context->map))->FUN_00a53c30((::A54440Manager *)(first), (::A54440Manager **)&(process)))
    {
        Node253* clone = static_cast<Node253*>(process);
        data->first = clone ? clone->object : 0;
    }
    if (second)
    {
        Node253* clone;
        if (reinterpret_cast<::A54440Hash *>((context->map))->FUN_00a53c30((::A54440Manager *)(second), (::A54440Manager **)&(process)))
            clone = static_cast<Node253*>(process);
        else
            clone = second->Clone(context);
        data->second = clone ? clone->object : 0;
    }
    reinterpret_cast<::FUN_00c87600_Obj *>(this)->FUN_00c87600(destination, context);
}

class GlobalObjectO2_00a7b610;
struct Param5380d0;
struct This5380d0
{
    bool FUN_005380d0(Param5380d0*);
};
struct ControllerRTTI
{
    const char* name;
    const ControllerRTTI* base;
};
class NiTimeController;
struct ControllerOwner
{
    unsigned int unkCur;
    unsigned int unkValue;
    unsigned int uNewnk;
    unsigned int unk00C;
    unsigned int uTmpnk;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    This5380d0* manager;
public:
    void FUN_00a5c480(::NiTimeController *);
};
// Creates a TLS flag guard, then if m_08 is set calls CallWithArgs(t,1,1), looks up DAT_012681f0 and applies the result if nonzero.
// @fnv 0x00c886c0
void FUN_00c886c0_cls::CallTargetWithArgs()
{
    TlsFlagGuard guard;
    TlsCallTarget* t = m_08;
    if (t != 0)
    {
        ::FUN_00c69ee0((::NiAVObject *)(t), 1, 1);
        uintptr_t r = ((uintptr_t)(reinterpret_cast<::MyHost *>((t))->FUN_00a5c570((const ::MyRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681f0))))));
        if (r != 0)
        {
            reinterpret_cast<::ControllerOwner *>((t))->FUN_00a5c480((::NiTimeController *)(r));
        }
    }
}
struct ControllerObject
{
    virtual void slot();
    virtual void slotCur();
    virtual void slotValue();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual unsigned int GetType();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual ControllerOwner* GetOwner();
};
struct ControllerLink
{
    unsigned int unk, unk04;
    void* active;
    ControllerObject* object;
    void Process()
    {
        ::EnableConstraintsAndZeroArrays((::CE0020Target *)(void *)(this), (::CE0020Subject *)(active));
    }
    bool IsActive() const
    {
        return active != 0;
    }
    void Update()
    {
        if (IsActive())
            Process();
    }
    void ProcessIfActive()
    {
        if (active)
            ::EnableConstraintsAndZeroArrays((::CE0020Target *)(void *)(this), (::CE0020Subject *)(active));
    }
};
struct ControllerFallback
{
    ControllerObject* object;
};
struct IdleController
{
    virtual void slot();
    virtual void DeleteThis();
    virtual const ControllerRTTI* GetRTTI();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void HandleControllerData(This5380d0*);
    virtual void slot28();
    virtual void slot29();
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual ControllerLink* GetLink();
    long refs;
    ControllerLink* link;
    ControllerFallback* fallback;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    bool IsKindOfType(const ControllerRTTI* wanted)
    {
        const ControllerRTTI* type = GetRTTI();
        while (type)
        {
            if (type == wanted)
                return true;
            type = type->base;
        }
        return false;
    }
    void ProcessActive()
    {
        if (link->active)
            link->Process();
    }
    ControllerObject* GetObject()
    {
        return link ? link->object : (fallback ? fallback->object : 0);
    }
};
struct ControllerPtr
{
    IdleController* m_pObject;
    __forceinline ControllerPtr(IdleController* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~ControllerPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ControllerPtr& operator=(const ControllerPtr& other);
};
struct ControllerList
{
    ControllerPtr item;
    ControllerList* next;
    ~ControllerList();
    void RemoveNode(const ControllerPtr& key);
};
void ControllerList::RemoveNode(const ControllerPtr& key)
{
    if (!key.m_pObject)
        return;
    if (!next && !item.m_pObject)
        return;
    ControllerList* prev = this;
    ControllerList* cur = this;
    while (cur->item.m_pObject != key.m_pObject)
    {
        prev = cur;
        cur = cur->next;
        if (!cur)
            return;
    }
    if (cur == this)
    {
        ControllerList* pNext = next;
        if (pNext)
        {
            next = pNext->next;
            item = pNext->item;
            pNext->next = 0;
            pNext->~ControllerList();
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(pNext);
        }
        else if (item.m_pObject)
        {
            item.m_pObject->DecRefCount();
            item.m_pObject = 0;
        }
    }
    else
    {
        prev->next = cur->next;
        cur->next = 0;
        cur->~ControllerList();
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(cur);
    }
}
struct ControllerCollection
{
    unsigned int unk, unk04, unk08, unk0C, unk10;
    ControllerList head;
};
struct ControllerExtra
{
    unsigned int unk, unk04, unk08, unk0C;
    ControllerCollection* collection;
};
// Walks the node's controller collection, activating or removing controllers by type, then recurses into child nodes.
// @fnv 0x00c80700
void ProcessControllerList(WalkNode_cls* node)
{
    if (node)
    {
        if (node->m_1c)
        {
            ControllerExtra* extra = reinterpret_cast<ControllerExtra*>(
                reinterpret_cast<::NiObject *>((reinterpret_cast<DynCastHelper*>(node->m_1c)))->DynamicCast((const ::NiRTTI *)(const unsigned int *)(reinterpret_cast<const unsigned int*>(&g_012043f8))));
            if (extra && extra->collection)
            {
                ControllerList* entry = &extra->collection->head;
                while (entry && entry->item.m_pObject)
                {
                    IdleController* original = entry->item.m_pObject;
                    IdleController* controller =
                        original->IsKindOfType(reinterpret_cast<const ControllerRTTI*>(&g_0126818c)) ? original : 0;
                    if (controller)
                    {
                        switch (controller->GetObject()->GetType())
                        {
                        case 2:
                        case 7:
                        case 13:
                            if (!controller->link->active)
                            {
                                ControllerLink* link = controller->GetLink();
                                ControllerObject* object = link ? link->object : 0;
                                ControllerOwner* owner = object->GetOwner();
                                controller->HandleControllerData(owner ? owner->manager : 0);
                            }
                            if (controller->link->IsActive())
                                ::EnableConstraintsAndZeroArrays((::CE0020Target *)(controller->link), (::CE0020Subject *)(controller->link->active));
                            break;
                        case 8: {
                            ControllerLink* link = controller->GetLink();
                            ControllerObject* object = link ? link->object : 0;
                            if (object)
                            {
                                ControllerOwner* owner = object->GetOwner();
                                This5380d0* manager = owner ? owner->manager : 0;
                                manager->FUN_005380d0(reinterpret_cast<Param5380d0*>(controller));
                            }
                            ControllerPtr spKey(controller);
                            reinterpret_cast<::FUN_00c80570_Node *>((entry))->RemoveNode((const ::NiPointer< ::AnimIdle> *)&(spKey));
                        }
                        break;
                        }
                    }
                    entry = entry->next;
                }
            }
        }
        WalkNode_cls* children = node->v03();
        if (children)
        {
            for (unsigned int i = 0; i < children->m_a6; ++i)
                ProcessControllerList(children->m_a0[i]);
        }
    }
}

struct C817D0Node
{
};

struct C817D0RefNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags;
};

struct C817D0TlsBlock
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int m_2c0;
};

__declspec(thread) C817D0TlsBlock g_c817d0Tls;

struct C817D0Cls
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfA0();
    virtual void vfA4();

    unsigned int unk04;
    C817D0Node* m_08;
    unsigned short m_0c;
    unsigned short unk0e;
    C817D0RefNode* m_10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    void UpdateNodeState(intptr_t);
};

// @fnv 0x00c817d0
void C817D0Cls::UpdateNodeState(intptr_t)
{
    int state = (*reinterpret_cast<::C817D0TlsBlock *>(&::g_tlsBlock)).m_2c0;
    if (state == 3)
        return;
    if (m_14 != 0)
    {
        if (m_08 != 0)
            reinterpret_cast<::NiAVObject *>((m_08))->UpdateWorldLoc();
        m_14 = 0;
        return;
    }
    C817D0RefNode* pRefNode = m_10;
    if (pRefNode == 0 || (bool)((pRefNode->m_flags >> 6) & 1) == 0)
    {
        if ((bool)((m_0c >> 6) & 1) != 0)
        {
            if (state != 2)
            {
                reinterpret_cast<::fnv_00c65b00::CollisionSync *>(this)->FUN_00c65b00();
                m_0c = (unsigned short)(m_0c & 0xffbf);
                return;
            }
        }
        else if ((bool)(m_0c & 1) != 0)
        {
            if (pRefNode != 0 || m_18 < 1.0f || m_20 == 1)
                vfA4();
            return;
        }
    }
    if (m_08 != 0)
        reinterpret_cast<::NiAVObject *>((m_08))->UpdateWorldLoc();
}


// @fnv 0x00c84cc0
void __cdecl FUN_00c84cc0(int* param_1, uintptr_t param_2)
{
    reinterpret_cast<::FUN_00c87670_Class *>((param_1))->FUN_00c87670((*(::NiStream *)(param_2)));
}

// Fallout: New Vegas — FUN_00c85620
// __cdecl aligned-allocation helper: requests an over-sized block from the
// heap object's virtual allocator, aligns the returned pointer up to the
// requested alignment, and stores a small header immediately below the
// aligned pointer: {owner, end, offset-to-raw}.

struct FUN_00c85620_heap
{
    virtual void v0();
    virtual void* Allocate(unsigned int uiSize);
};

// Sits immediately below the aligned pointer; FUN_00c85660 reads it to free the block.
struct FUN_00c85620_header
{
    FUN_00c85620_heap* owner;
    unsigned int end;
    unsigned int rawOffset;
};

// @fnv 0x00c85620
void* __cdecl FUN_00c85620(FUN_00c85620_heap* pkHeap, unsigned int uiSize, unsigned int uiAlignment)
{
    unsigned int uiEnd = uiSize + uiAlignment;
    void* pvRaw = pkHeap->Allocate(uiEnd + 0x10);

    uintptr_t uiAligned = (uintptr_t)pvRaw + uiAlignment + 0xf;
    uiAligned &= ~(uiAlignment - 1);

    FUN_00c85620_header* header = (FUN_00c85620_header*)uiAligned - 1;
    header->end = uiEnd;
    header->owner = pkHeap;
    header->rawOffset = (unsigned int)(uiAligned - (uintptr_t)pvRaw);

    return (void*)uiAligned;
}

struct FUN_00ba87d0_holder
{
    bool FUN_00ba87d0();
};
// @fnv 0x00c85800
void __cdecl FUN_00c85800()
{
    extern void __cdecl FUN_00ba87d0();
    static_cast<::FUN_00ba87d0_Class *>(nullptr)->FUN_00ba87d0({});
}

struct FUN_00c87a40_ref
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct FUN_00c87a40_obj
{
    void* unk00;
    void* unk04;
    FUN_00c87a40_ref* unk08;

    void* FUN_00c87a40();
};

// @fnv 0x00c87a40
void* FUN_00c87a40_obj::FUN_00c87a40()
{
    if (unk08 != 0)
        return unk08->unk08;
    return 0;
}

extern void __cdecl FUN_00a5d3a0();
extern int DAT_010c5b54;
struct FUN_00c87c30_t
{
    int* pVTable;
    int unk04;
    int unk08;
    FUN_00c87c30_t* FUN_00c87c30();
};
// @fnv 0x00c87c30
FUN_00c87c30_t* FUN_00c87c30_t::FUN_00c87c30()
{
    FUN_00a5d3a0();
    pVTable = &DAT_010c5b54;
    unk08 = 0;
    return this;
}

struct FUN_00c87c50_cls
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot36(bool b);
    int unk04;
    NiObject* unk08;
    void FUN_00c87c50(NiObject* arg);
};
// @fnv 0x00c87c50
void FUN_00c87c50_cls::FUN_00c87c50(NiObject* apObject)
{
    if (unk08 != apObject)
    {
        slot36(false);
        unk08 = apObject;
        slot36(true);
    }
}


// @fnv 0x00c87c80
int* __cdecl FUN_00c87c80()
{
    return &(*reinterpret_cast<int *>(&::g_01268160));
}

struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard() : previous((*reinterpret_cast<int *>(&::currentAllocationContext)))
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~MemoryContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};
struct FUN_00c905b0_Class
{
};
struct FUN_00a5d3d0
{
    virtual ~FUN_00a5d3d0();
};
struct FUN_00c87d20 : FUN_00a5d3d0
{
    int m_field04;
    FUN_00c905b0_Class* m_ref;
    virtual ~FUN_00c87d20();
};
// Destructor that enters a memory context and, if m_ref is set, calls FUN_00c905b0 on it.
// @fnv 0x00c87d20
FUN_00c87d20::~FUN_00c87d20()
{
    MemoryContextGuard guard;
    if (m_ref)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_ref))->FUN_00c905b0();
}

struct FUN_00c87dc0_class
{
    void FUN_00c87d20();
    void* FUN_00c87dc0(unsigned char param_2);
};


// Calls FUN_00c87d20, then deletes this (0xC bytes) when bit 0 of param_2 is set, and returns this.
// @fnv 0x00c87dc0
void* FUN_00c87dc0_class::FUN_00c87dc0(unsigned char param_2)
{
    reinterpret_cast<::FUN_00c87d20 *>(this)->FUN_00c87d20::~FUN_00c87d20();
    if ((param_2 & 1) != 0)
    {
        ::operator delete(this, 0xC);
    }
    return this;
}

namespace fnv_00c87de0 {

struct StrArr;
struct Base380
{
    void* vtbl;
    int unk04;
};

struct hkReferencedObject_c87de0 : hkReferencedObject
{
    int unk00;
    short unk04;
    short m_sReferenceCount;
};

struct bhkRefObject_Class : Base380
{
    hkReferencedObject_c87de0* m_pPointer;

    void AddDebugStrings(ViewerStrings* pkStrings);
};

// @fnv 0x00c87de0
void bhkRefObject_Class::AddDebugStrings(ViewerStrings* pkStrings)
{
    MemContextScope kScope(16);

    reinterpret_cast<::A5D6E0This *>(this)->AppendCameraPathEntries((::NiTArray< ::BGSCameraPath *, ::NiTMallocInterface< ::BGSCameraPath *>> *)(::fnv_00c87de0::StrArr *)((StrArr*)pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268160))));

    char acBuffer[32];
    ::FUN_00406d00(acBuffer, 32, "0x%08X", (uintptr_t)m_pPointer);
    pkStrings->Add(::fnv_00a7d5e0::FUN_00a7d5e0("hkObject", acBuffer));

    if (m_pPointer)
    {
        pkStrings->Add(::FUN_00a7d4d0("hkRefcount", m_pPointer->m_sReferenceCount));
    }
}
}  // namespace fnv_00c87de0

// @fnv 0x00c87fa0
void __cdecl FUN_00c87fa0()
{
    static_cast<::FUN_00c6b730_cls *>(nullptr)->DispatchToTarget({});
}


// @fnv 0x00c87fb0
void FUN_00c87fb0()
{
    static_cast<::S_00c6b760_Cls *>(nullptr)->FUN_00c6b760({});
}


struct FUN_00c88430_t
{
    int* m_p0;
    int m_i4;
    int m_i8;
    int m_ic;
    int m_i10;
    FUN_00c88430_t();
};

// @fnv 0x00c88430
FUN_00c88430_t::FUN_00c88430_t()
{
    m_i4 = 0;
    m_i8 = 1;
    m_ic = 0;
    m_i10 = 0;
    m_p0 = &DAT_010c5dc0;
}

struct Flagged_c891
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
    int flag30;
};
struct Facade_c891
{
    int unk00;
    int unk04;
    Flagged_c891* value08;
};
struct Result_c891
{
    Facade_c891* facade00;
    int unk04;
};
struct Elem_c891
{
    int unk00;
    int unk04;
    Elem_c891* unk08;
    Elem_c891* getE() const
    {
        return unk08;
    }
};
struct Holder_c891
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Elem_c891* elem10;
};
struct Heap_c891
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};
struct Arr_c891
{
    Elem_c891** m_data;
    int m_iElementCount;
    int m_cap;
    Arr_c891() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    Elem_c891*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    ~Arr_c891()
    {
        SpawnedAllocHolder* r = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        Heap_c891* heap = (Heap_c891*)r->m_pAllocator;
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap->ReturnMemory(m_data, (m_cap & 0x3fffffff) * 4);
    }
};
Result_c891* __cdecl FUN_00c85ef0(Result_c891*, Elem_c891*, int*);
struct Cls_c891
{
    int unk00;
    int unk04;
    int m_08;
    void FUN_00c891c0();
};
// @fnv 0x00c891c0
void Cls_c891::FUN_00c891c0()
{
    intptr_t obj = m_08;
    if (obj != 0)
    {
        Holder_c891* holder = ((::Holder_c891 *)(::FUN_00c802d0((::MyNode *)(obj))));
        Elem_c891* target = holder ? holder->elem10 : 0;
        Arr_c891 arr;
        ::CollectTreeResultValues((::TreeNode_cls *)(obj), (::SpawnedPtrArray *)(::Arr_c891 *)(&arr));
        for (int i = 0; i < arr.GetLogicalSize(); i++)
        {
            if (!target)
                break;
            Elem_c891* t = target->unk08;
            if (arr[i] != t && arr[i]->unk08 == 0)
            {
                Elem_c891* e = arr[i];
                Result_c891 res;
                Facade_c891* f = FUN_00c85ef0(&res, e, &(*reinterpret_cast<int *>(&::g_01267b70)))->facade00;
                f->value08->flag30 |= 1;
            }
        }
    }
}


// @fnv 0x00c896b0
void FUN_00c896b0()
{
    static_cast<::FUN_00c87650_t *>(nullptr)->LoadBinary(*(::NiStream *)nullptr);
}

struct FnvCpu_FUN_00c89720_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void Invoke();
    void FUN_00c89720();
};
// @fnv 0x00c89720
void FnvCpu_FUN_00c89720_CpuInterface::FUN_00c89720()
{
    Invoke();
}

struct AttachObject;
struct AttachData;
struct AttachObject
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
    virtual AttachData* GetData();
    virtual void v38();
    virtual void Add(AttachObject*);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void Set(AttachObject*);
    virtual AttachObject* GetTarget();
    virtual AttachData* GetConstraint();
    int unk04;
    AttachData* owner;
    int unk0c;
    unsigned int flags;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    AttachData* data24;
    int unk28;
    unsigned int id;
    bool AddOrRemoveConstraint(AttachObject* body, bool add);
};
struct AttachData
{
    unsigned char HasObjectOfType()
    {
        return object08 != 0;
    }
    int unk00;
    int unk04;
    AttachObject* object08;
    AttachObject* object0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AttachObject* object24;
    int unk28;
    unsigned int id;
};
struct DiagFlag
{
    bool enabled;
    DiagFlag(bool value) : enabled(value)
    {}
    DiagFlag(const DiagFlag& other) : enabled(other.enabled)
    {}
};
struct DiagString
{
    int a, b, c;
    DiagString(char*, unsigned int, DiagFlag);
    void Append(const char*);
    ~DiagString();
};
struct DiagSink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int, unsigned int, char*, const char*, int);
};
// Adds or removes a constraint body on the target, fixing the constraint id and reporting when the target bodies are not yet in the world.
// @fnv 0x00c89f90
bool AttachObject::AddOrRemoveConstraint(AttachObject* body, bool add)
{
    MemContextScope scope(16);
    bool result = false;
    AttachData* constraint = GetConstraint();
    if (add)
    {
        if (constraint && constraint->object0c)
        {
            AttachObject* target = constraint->object0c;
            AttachData* owner = target->owner;
            bool present = false;
            if (owner)
            {
                ::FUN_00a29680();
                unsigned char b = owner->object08 != 0;
                present = b ? true : false;
                ::FUN_00a29680();
            }
            if (!present)
            {
                unsigned int t = GetTarget()->id;
                constraint->id = (t & 0xffff0000) | (unsigned short)constraint->id;
            }
            if (body->count <= 0)
            {
                target->Add(body);
                if (!target->GetData() && !(target->flags & 0x30))
                {
                    {
                        char buffer[512];
                        DiagString diagText(buffer, 512, DiagFlag(true));
                        reinterpret_cast<::SinkOwner *>(&(diagText))->FUN_00cc01c0(
                            "A Constraint is being added to the world before its target bodies have been added. Did an bad actor skeleton just switch from keyframed?\n");
                        (*reinterpret_cast<::DiagSink * *>(&::DAT_01268360))->Report(1, 0x234f24fc, buffer,
                                               "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkConstraint.cpp",
                                               749);
                    }
                    target->Set(body);
                }
            }
        }
        else
        {
            *(volatile bool*)&result = true;
            AttachData* data = body->GetData();
            AttachObject* object = 0;
            if (data)
                object = data->object24;
            Set(object);
        }
    }
    else
    {
        AttachData* data = body->GetData();
        AttachObject* object = 0;
        if (data)
            object = data->object24;
        if (constraint == (AttachData*)object)
            Set(0);
    }
    return result;
}

struct Alloc8b_c8b090
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
    virtual void ReleaseBlock(void* p, int size);
};

struct hkThreadLocals_c8b090
{
    int value;
};

struct TlsScope_c8b090
{
    int m_old;
    TlsScope_c8b090(int v)
    {
        m_old = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = v;
    }
    ~TlsScope_c8b090()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_old;
    }
};

struct hkRefObj_c8b090
{
    virtual void vf0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(std::size_t size)
    {
        SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        hkRefObj_c8b090* b = (hkRefObj_c8b090*)alloc->AllocateMemoryBlock(static_cast<int>(size));
        b->m_usMemSizeAndFlags = (unsigned short)size;
        return b;
    }
    static void operator delete(void* p, std::size_t size)
    {
        SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        alloc->ReleaseBlock(p, static_cast<int>(size));
    }
};

struct hkShapeContainer_c8b090
{
    virtual void v0();
    virtual int GetNumChildShapes();
    virtual int GetFirstKey();
    virtual int GetNextShapeKey(int key);
};

struct hkShape_c8b090
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct hkShapeBase_c8b090 : hkRefObj_c8b090
{
    int unk08;
    int unk0c;
};

struct hkListShape_c8b090 : hkShapeBase_c8b090, hkShapeContainer_c8b090
{
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
    hkListShape_c8b090(void* shapes, unsigned int count, int policy);
};

struct ListInfo_c8b090
{
    int unk00;
    void* m_shapes;
    unsigned int m_numShapes;
    int unk0c;
    void** m_iSlotIds;
    unsigned int m_uiArrayCount;
};

struct bhkListOwner_c8b090
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void SetShape(hkListShape_c8b090* shape);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void SetListInfo(ListInfo_c8b090* info);
    void SetListShape(ListInfo_c8b090* info);
};

// @fnv 0x00c8b090
void bhkListOwner_c8b090::SetListShape(ListInfo_c8b090* info)
{
    TlsScope_c8b090 scope(0x10);
    void* shapes = info->m_shapes;
    unsigned int count = info->m_numShapes;
    hkListShape_c8b090* shape = new hkListShape_c8b090(shapes, count, 1);
    int key = shape->GetFirstKey();
    if (!(count < info->m_uiArrayCount))
        count = info->m_uiArrayCount;
    for (unsigned int i = 0; i < count; i++)
    {
        reinterpret_cast<::hkPListShape *>((shape))->SetChildShape(key, info->m_iSlotIds[i]);
        shape->GetNextShapeKey(key);
    }
    SetShape(shape);
    reinterpret_cast<::hkReferencedObjectC905 *>((shape))->FUN_00c905b0();
    SetListInfo(info);
}

struct C8B540Selected;

class C8B540Wrapper
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual C8B540Selected* Select();
};

class C8B540Selected
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual int GetResult(int iArg);
};

struct C8B540Group : C8B4D0Group
{
    int unk0C;
    int m_iFallback;

    int GetSelectedResult(int iArg);
};

// Iterates children, calls Select on each child's wrapper and returns the first non-0x24 GetResult result, else m_iFallback masked with 0x1f.
// @fnv 0x00c8b540
int C8B540Group::GetSelectedResult(int iArg)
{
    int result = 0x24;
    unsigned int count = GetChildCount();
    for (unsigned int i = 0; i < count; i++)
    {
        if (result != 0x24)
            break;

        C8B4D0Child* pkChild = GetChild(i);
        C8B540Wrapper* pkWrapper = pkChild ? (C8B540Wrapper*)pkChild->m_pkWrapper : 0;
        C8B540Selected* pkSelected = pkWrapper->Select();
        if (pkSelected)
            result = pkSelected->GetResult(iArg);
    }

    if (result == 0x24)
        result = m_iFallback & 0x1f;

    return result;
}


// @fnv 0x00c8ff70
void* __cdecl FUN_00c8ff70()
{
    return &::g_012681cc;
}


// @fnv 0x00c8ff80
void __cdecl FUN_00c8ff80(intptr_t param_1, intptr_t param_2)
{
    reinterpret_cast<::C818F0_cls *>((param_1))->FUN_00c818f0((::NiStream *)(param_2));
}

struct FUN_00c819a0_holder
{
};

// @fnv 0x00c8ff90
void __cdecl FUN_00c8ff90()
{
    static_cast<::C819A0Derived *>(nullptr)->InitFromFlags({});
}


// @fnv 0x00c8ffa0
void __cdecl FUN_00c8ffa0()
{
    ::FUN_00cb7610();
}

extern void __cdecl FUN_00c819f0();

// @fnv 0x00c8ffb0
void __cdecl FUN_00c8ffb0()
{
    FUN_00c819f0();
}


// @fnv 0x00c8ffc0
bool __cdecl FUN_00c8ffc0(C815B0Constraint* pkOther)
{
    return reinterpret_cast<::C815B0Constraint *>((pkOther))->FUN_00c815b0({});
}

struct C90160Matrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class C90160Derived : public BC88760Base
{
  public:
    C90160Matrix matrix;
    C90160Derived() : matrix((*reinterpret_cast<const ::C90160Matrix *>(&::DAT_011a9448)))
    {}
    virtual ~C90160Derived();

    C90160Derived* FUN_00c90160(BC88760CloningProcess& cloning);
};

// @fnv 0x00c90160
C90160Derived* C90160Derived::FUN_00c90160(BC88760CloningProcess& cloning)
{
    BC88760AllocTagScope allocationCategory(16);
    C90160Derived* destination = new C90160Derived;
    reinterpret_cast<::FUN_00c81580_cls *>(this)->FUN_00c81580((::FUN_00c81580_cls *)(destination), (void *)&(cloning));
    destination->matrix = matrix;
    return destination;
}

// @fnv 0x00c90330
void __cdecl FUN_00c90330()
{}

// @fnv 0x00c90340
void __cdecl FUN_00c90340()
{}

// 0x00c90350  xor eax,eax; ret
// @fnv 0x00c90350
int __cdecl FUN_00c90350()
{
    return 0;
}

struct FunctionContext
{
    void FUN_00c90360(void* context, void* object);
};
// @fnv 0x00c90360
void FunctionContext::FUN_00c90360(void* context, void* object)
{
    void* const cachedObject = object;
    if (cachedObject != 0 && cachedObject != &(*reinterpret_cast<int *>(&::g_01268748)))
    {
        void* pointer;
        if (*((const char *)(::FUN_00cf6170((unsigned char *)(void **)(&pointer), (::FUN_00d46f70_Obj *)(cachedObject)))))
        {
            ::FUN_00cf6920(this, (::Node *)(cachedObject), context);
        }
    }
}


struct FUN_00c90880_Srv
{
    virtual void m_00();
    virtual void m_04();
    virtual void m_08(void* p, unsigned short w);
};

struct FUN_00c90880_Class
{
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    CRITICAL_SECTION m_kLock;

    void* FUN_00c90880(unsigned int flags);
};

// @fnv 0x00c90880
void* FUN_00c90880_Class::FUN_00c90880(unsigned int flags)
{
    DeleteCriticalSection(&m_kLock);
    m_00 = &(*reinterpret_cast<int *>(&::DAT_0102e388));
    if (flags & 1)
    {
        SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        FUN_00c90880_Srv* pService = static_cast<FUN_00c90880_Srv*>(holder->m_pAllocator);
        pService->m_08(this, m_04);
    }
    return this;
}

// @fnv 0x00c90e30
int FUN_00c90e30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
    return 0;
}

struct FUN_00c92b00_Entry
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    int value48;
    int value4c;
};

struct FUN_00c92b00_Class
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    FUN_00c92b00_Entry** entries28;
    int count2c;
    int unk30;
    FUN_00c92b00_Entry** entries34;
    int count38;

    void ApplyEntries();
};

// Calls FUN_00c92a80 with value48 and value4c for every entry in entries28 (count2c) and entries34 (count38).
// @fnv 0x00c92b00
void FUN_00c92b00_Class::ApplyEntries()
{
    for (int i = 0; i < count2c; ++i)
    {
        FUN_00c92b00_Entry* entry = entries28[i];
        reinterpret_cast<::S00c92a80_cls *>(this)->FUN_00c92a80(entry->value48, entry->value4c);
    }
    for (int i = 0; i < count38; ++i)
    {
        FUN_00c92b00_Entry* entry = entries34[i];
        reinterpret_cast<::S00c92a80_cls *>(this)->FUN_00c92a80(entry->value48, entry->value4c);
    }
}

struct FUN_00c9a620_Obj
{
    float unk00;
    float unk04;
    float unk08;

    int FUN_00c9a620(float* other);
};

// Returns 1 if the three floats at unk00, unk04 and unk08 all equal the corresponding elements of other, otherwise 0.
// @fnv 0x00c9a620
int FUN_00c9a620_Obj::FUN_00c9a620(float* other)
{
    if (unk00 == other[0] && unk04 == other[1] && unk08 == other[2])
    {
        return 1;
    }
    return 0;
}

void FUN_00cbb990();
struct ArenaReleaseAllocator : ArenaAllocator
{
    virtual void Deallocate(void* p, unsigned int bytes);
};
struct ArenaRegistryRelease
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Release(TemporaryArena* arena, ArenaRegistrationFlag flag);
};
struct ArenaManagedOwner
{
    TemporaryArena* arena;
    void* buffer;
    unsigned long threadId;
};
// Frees the owner's buffer from its temporary arena, resets the arena state, and releases the arena registration under a critical section.
// @fnv 0x00c80240
void FUN_00c80240(ArenaManagedOwner* owner)
{
    if (owner->arena)
    {
        EnterCriticalSection(&DAT_01267e48);
        TemporaryArena* arena = owner->arena;
        ArenaReleaseAllocator* allocator = static_cast<ArenaReleaseAllocator*>(arena->allocator);
        allocator->Deallocate(owner->buffer, 0x5000);
        owner->buffer = 0;
        if (GetCurrentThreadId() == owner->threadId)
            FUN_00cbb990();
        ArenaRegistryRelease* registry = (ArenaRegistryRelease*)((::ArenaRegistry *)(::FUN_00cbbfc0()));
        registry->Release(arena, ArenaRegistrationFlag());
        arena->cursor = 0;
        arena->start = 0;
        arena->end = 0;
        owner->arena = 0;
        LeaveCriticalSection(&DAT_01267e48);
    }
}


class RefObject0AA0
{
  public:
    virtual ~RefObject0AA0();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    long m_uiRefCount;
};

template <class T> class NiPointer0AA0
{
  public:
    NiPointer0AA0(const NiPointer0AA0& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer0AA0& operator=(const NiPointer0AA0& ptr);
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct MemoryManager0AA0
{
    void* Allocate(unsigned int uiSize);
};

class ListNode0AA0
{
  public:
    ListNode0AA0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject) : m_pReferencedObject(spRetainedObject)
    {
        m_pkNext = 0;
    }
    void FUN_00c80aa0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject);

    NiPointer0AA0<RefObject0AA0> m_pReferencedObject;
    ListNode0AA0* m_pkNext;
};

// Appends spRetainedObject to the tail of the linked list, reusing the last node's slot if it is empty.
// @fnv 0x00c80aa0
void ListNode0AA0::FUN_00c80aa0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject)
{
    if (!spRetainedObject)
        return;
    ListNode0AA0* pkNode = this;
    while (pkNode->m_pkNext)
        pkNode = pkNode->m_pkNext;
    if (pkNode->m_pReferencedObject)
        pkNode->m_pkNext = new ListNode0AA0(spRetainedObject);
    else
        pkNode->m_pReferencedObject = spRetainedObject;
}

struct FUN_00c819f0_stream
{
    void* vtable;
    unsigned int m_04;
    unsigned int unk08;
    unsigned int(__cdecl* m_0c)(FUN_00c819f0_stream* self, void* buffer, unsigned int size, unsigned int* sizes,
                                unsigned int count);
};

class FUN_00c819f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int m_1c;
    void FUN_00c819f0(intptr_t a1);
};

// Calls Callee65820, then twice calls the m_0c callback of the stream at a1+0x250 on m_18 and m_1c (4 bytes each), adding each result to the stream's m_04.
// @fnv 0x00c819f0
void FUN_00c819f0_cls::FUN_00c819f0(intptr_t a1)
{
    char* obj = (char*)a1;
    FUN_00c819f0_stream* __restrict o;
    unsigned int(__cdecl * fn)(FUN_00c819f0_stream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int* cnt = (unsigned int*)&a1;
    ::FUN_00c65820();
    o = *(FUN_00c819f0_stream**)(obj + 0x250);

    o->m_04 += o->m_0c((a1 = 4, o), &m_18, 4, cnt, 1);
    o = *(FUN_00c819f0_stream**)(obj + 0x250);

    o->m_04 += o->m_0c((a1 = 4, o), &m_1c, 4, cnt, 1);
}

struct MeshMemoryScope
{
    int saved;
    MeshMemoryScope()
    {
        saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 16;
    }
    ~MeshMemoryScope()
    {
        g_tlsBlock.m_2b4 = saved;
    }
};
struct FourFloatComponents
{
    float unk00, unk04, unk08, unk0c;
};
struct SourceTriangle
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct SourceMesh
{
    FourFloatComponents* unk00;
    unsigned int unk04;
    unsigned int unk08;
    SourceTriangle* unk0c;
    unsigned int unk10;
};
struct GeometryData
{
};
class NiMemObject
{
  public:
};
class NiTriShape : public NiMemObject
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, void*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
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
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    GeometryData* unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
};
struct MeshBuilder
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    void BuildTriShape(uintptr_t unused, SourceMesh* mesh, uintptr_t arg2, const char* name);
};
// Copies SourceMesh vertex and triangle data into a new NiTriShape, sets its name, ensures normals, and attaches an emissive material.
// @fnv 0x00c84fa0
void MeshBuilder::BuildTriShape(uintptr_t unused, SourceMesh* mesh, uintptr_t arg2, const char* name)
{
    MeshMemoryScope scope;
    if (mesh)
    {
        unsigned int vertexCount = mesh->unk04;
        unsigned int triangleCount = mesh->unk10;
        if (vertexCount && triangleCount)
        {
            NiPoint3* vertices = new NiPoint3[vertexCount];
            unsigned short* indices = new unsigned short[triangleCount * 3];
            for (unsigned int i = 0; i < vertexCount; ++i)
                ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&vertices[i])), (*(const ::hkVector4 *)(&mesh->unk00[i])));
            for (unsigned int j = 0; j < triangleCount; ++j)
            {
                SourceTriangle triangle = mesh->unk0c[j];
                indices[j * 3] = (unsigned short)triangle.unk00;
                indices[j * 3 + 1] = (unsigned short)triangle.unk04;
                indices[j * 3 + 2] = (unsigned short)triangle.unk08;
            }
            NiTriShape* shape = new NiTriShape((unsigned short)vertexCount, vertices, 0, 0, 0, 0, 0,
                                               (unsigned short)triangleCount, indices);
            if (name)
                ::AssignFixedString((char *)(shape), (intptr_t)&(const ::NiFixedString &)(NiFixedString(name)), {});
            reinterpret_cast<::GeomNormals *>((shape->unkb8))->EnsureNormals(true);
            ::AttachEmissiveMaterial((::C11F0Object *)(shape), (::C11F0Owner *)(unused), unk10 & 31, (::C11F0Color *)(arg2));
        }
    }
}

struct PropertyKey
{
    unsigned int first, second;
};
struct PropertyValue
{
    int value;
    unsigned int extra;
};
struct PropertyEntry
{
    void* key;
    unsigned int flags;
    PropertyValue data;
};
struct PropertyStore
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    PropertyEntry* entries;
    int count;
    PropertyValue FindEntry(void* key, int flags);
};
struct PropertyOwner
{
    unsigned int unknown00, unknown04;
    PropertyStore* store;
    int ReadProperty(void* key);
    int FUN_00c85c80(void* key);
};
__forceinline int PropertyOwner::ReadProperty(void* key)
{
    PropertyStore* object = store;
    int result = 0;
    if (object)
        result = object->FindEntry(key, 0).value;
    return result;
}
// Defaults key to DAT_011f4280 if null; if a store entry has that key, returns ReadProperty(key), otherwise 0.
// @fnv 0x00c85c80
int PropertyOwner::FUN_00c85c80(void* key)
{
    int result = 0;
    if (!key)
        key = &(*reinterpret_cast<::PropertyKey *>(&::g_011f4280));
    PropertyStore* object = store;
    if (object)
    {
        int count = object->count;
        int i = 0;
        if (count > 0)
        {
            PropertyEntry* current = object->entries;
            do
            {
                if (current->key == key)
                {
                    result = ReadProperty(key);
                    break;
                }
                ++i;
                ++current;
            } while (i < count);
        }
    }
    return result;
}

struct ObjectController
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void* v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();

    void* unk04;
    void* m_pObject;
    void SetObject(void* replacement);
};

// If replacement differs from m_pObject, calls v28() when v25()'s state has a nonzero field at 0x350, then calls FUN_00c87c50(replacement).
struct ObjectControllerState
{
    char pad[0x350];
    int m_iActive;
};

// @fnv 0x00c87760
void ObjectController::SetObject(void* replacement)
{
    void* current = this ? m_pObject : 0;
    if (replacement != current)
    {
        if (current)
        {
            void* state = v25();
            if (state && static_cast<ObjectControllerState*>(state)->m_iActive)
                v28();
        }
        reinterpret_cast<::FUN_00c87c50_cls *>(this)->FUN_00c87c50((::NiObject *)(replacement));
    }
}

struct FUN_00c87a50_inner
{
    void* unk00;
    void* unk04;
    void* m_08;
};

struct FUN_00c87a50_t
{
    void* unk00;
    void* unk04;
    FUN_00c87a50_inner* unk08;
    void* FUN_00c87a50();
};

// @fnv 0x00c87a50
void* FUN_00c87a50_t::FUN_00c87a50()
{
    if (this && unk08)
    {
        return unk08->m_08;
    }
    return 0;
}

struct C87c90HkRef
{
};

// Releases the reference held in unk08, calling FUN_00c90510 when b is true or removeReference when false.
// @fnv 0x00c87c90
void FUN_00c899d0_Class::ReleaseReference(bool b)
{
    TlsGuard_t guard;
    if (unk08)
    {
        if (b)
        {
            reinterpret_cast<::FUN_00c90510_class *>((((C87c90HkRef*)unk08)))->FUN_00c90510();
        }
        else
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((((hkReferencedObject*)unk08)))->FUN_00c905b0();
        }
    }
}

struct NiPlane
{
    int unk00;
    int unk04;
    int unk08;

    bool operator==(const NiPlane& other) const;
public:
    bool operator==(const ::NiPlane &);
};

struct Mat364
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

};


struct Target_00c88450
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
    Mat364 unk34;
    NiPlane unk58;
};

struct Cinfo_00c88450
{
    int unk00;
    int unk04;
    Target_00c88450* unk08;

    void FUN_00c88450(void* arg);
};

// If unk08's plane equals DAT_011f426c or its matrix check against DAT_011a9448 fails, sets both to those values; then always calls UpdateNodeState(arg).
// @fnv 0x00c88450
void Cinfo_00c88450::FUN_00c88450(void* arg)
{
    Target_00c88450* target = unk08;

    if (target != 0)
    {
        NiPlane* plane = &target->unk58;

        if (reinterpret_cast<::NiPlane *>((void *)&(const ::NiPlane &)(*plane))->operator==(*reinterpret_cast<NiPlane const*>(&(*reinterpret_cast<unsigned char *>((void *)&::NiPoint3::ZERO)))) ||
            !reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(target->unk34))->operator==((const ::ThreeByThreeMatrix &)(*reinterpret_cast<Mat364 const*>(&(*reinterpret_cast<const ::C90160Matrix *>(&::DAT_011a9448))))))
        {
            target->unk34 = *reinterpret_cast<Mat364 const*>(&(*reinterpret_cast<const ::C90160Matrix *>(&::DAT_011a9448)));
            plane->unk00 = *reinterpret_cast<int*>(&(*reinterpret_cast<unsigned char *>((void *)&::NiPoint3::ZERO)));
            plane->unk04 = *reinterpret_cast<int*>(&(*reinterpret_cast<unsigned char *>(&::_DAT_011f4270)));
            plane->unk08 = *reinterpret_cast<int*>(&(*reinterpret_cast<unsigned char *>(&::_DAT_011f4274)));
        }
    }

    reinterpret_cast<::C817D0Cls *>(this)->UpdateNodeState((intptr_t)(arg));
}

struct Process89730
{
    Map253* map;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};
struct Poly89730
{
    virtual void slot0();
    virtual void Scale(int iUnused, Process89730* pkProcess);
};
struct Data89730Base
{
    int unk00;
};
struct Data89730 : public Poly89730, public Data89730Base
{
    int unk08;
    HavokObject253* m_pkFirst;
    HavokObject253* m_pkSecond;
};
struct Owner89730
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual Data89730Base* GetData(bool* pbTemporary);
    void FUN_00c89730(void* pkDestination, Process89730* pkProcess);
};

// Scales the data from GetData if pkProcess->m_fScale is not 1, re-links its two object pointers via the process map or Clone, then calls FUN_00c87600.
// @fnv 0x00c89730
void Owner89730::FUN_00c89730(void* pkDestination, Process89730* pkProcess)
{
    bool bTemporary;
    Data89730* pkData = static_cast<Data89730*>(GetData(&bTemporary));
    if (pkProcess->m_fScale != 1.0f)
        pkData->Scale(0, pkProcess);
    Node253* pkFirstOwner = pkData->m_pkFirst ? pkData->m_pkFirst->owner : 0;
    Node253* pkSecondOwner = pkData->m_pkSecond ? pkData->m_pkSecond->owner : 0;
    pkData->m_pkFirst = 0;
    pkData->m_pkSecond = 0;
    if (pkFirstOwner)
    {
        void* pkClone;
        if (reinterpret_cast<::A54440Hash *>((pkProcess->map))->FUN_00a53c30((::A54440Manager *)(pkFirstOwner), (::A54440Manager **)&(pkClone)))
            pkData->m_pkFirst = pkClone ? ((Node253*)pkClone)->object : 0;
        if (pkSecondOwner)
        {
            Node253* pkSecondClone;
            if (reinterpret_cast<::A54440Hash *>((pkProcess->map))->FUN_00a53c30((::A54440Manager *)(pkSecondOwner), (::A54440Manager **)&(pkClone)))
                pkSecondClone = (Node253*)pkClone;
            else
                pkSecondClone = pkSecondOwner->Clone(pkProcess);
            pkData->m_pkSecond = pkSecondClone ? pkSecondClone->object : 0;
        }
    }
    reinterpret_cast<::FUN_00c87600_Obj *>(this)->FUN_00c87600(pkDestination, pkProcess);
}

struct FUN_00d53200_class
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    int unk04;
    int unk08;
    void FUN_00c8a230(NiStream& kStream);
};
// Calls FUN_00a64670 on kStream, calls vfn10, then calls ReadBinaryValue(&kStream, unk08).
// @fnv 0x00c8a230
void FUN_00d53200_class::FUN_00c8a230(NiStream& kStream)
{
    reinterpret_cast<::S_00a64670_Foo *>((((FileContext*)&kStream)))->FUN_00a64670();
    vfn10();
    ReadBinaryValue(&kStream, unk08);
}


struct ActorBase
{
    virtual ~ActorBase();
};
struct FUN_00c8a720 : ActorBase
{
    virtual ~FUN_00c8a720();
};
// Calls FUN_00c8a720, then deletes this with size 0x10 when b has bit 0 set, and returns this.
// @fnv 0x00c8a7e0
void* FUN_00c8a7e0_t::FUN_00c8a7e0(bool abDelete)
{
    reinterpret_cast<::FUN_00c8a720 *>(this)->FUN_00c8a720::~FUN_00c8a720();
    if (abDelete & 1)
        _delete(this, 0x10);
    return this;
}
// @fnv 0x00c8a720
FUN_00c8a720::~FUN_00c8a720()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268194;
}

class C8AAResult
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};

class C8AASub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    C8AAResult* m_18;
    C8AAResult* m_1c;
};

class C8AAHost
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    C8AASub* m_08;
    C8AAResult* GetA()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_18;
        else
            r = 0;
        return r;
    }
    C8AAResult* GetOther()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_1c;
        else
            r = 0;
        return r;
    }
    int GetResultValue(char c);
};

// Returns the m_0c field of the C8AAResult selected by c ('A'/'a' picks GetA, otherwise GetOther), or 0 if the result is null.
// @fnv 0x00c8aa00
int C8AAHost::GetResultValue(char c)
{
    C8AAResult* y;
    if (c == 'A' || c == 'a')
        y = GetA();
    else
        y = GetOther();
    return y ? y->m_0c : 0;
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00c8aa80_cls : BaseThunk
{
    int unk00;
    int unk04;
    Mid* m_08;
    void FUN_00c8aa80(NiStream* a);
};

// Looks up m_08->m_1c, calls v15(a) on its m_0c object if present, then calls FUN_00a81fe0 on the stream.
// @fnv 0x00c8aa80
void FUN_00c8aa80_cls::FUN_00c8aa80(NiStream* apStream)
{
    Node1* node = this && m_08 ? m_08->m_1c : 0;
    _ReadWriteBarrier();
    if (node)
    {
        C_t* t = (C_t*)node->m_0c;
        if (t)
            t->v15(apStream);
    }
    ::FUN_00a81fe0((intptr_t)this);
}


struct Ffd0base
{
};

struct Arr9
{
    int v[9];
};

struct FUN_00c8ffd0
{
    void* m_vtbl;
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
    Arr9 tab;
    FUN_00c8ffd0();
};

// Initializes the base class, sets the vtable pointer, and copies a 9-element array from a global data location.
// @fnv 0x00c8ffd0
FUN_00c8ffd0::FUN_00c8ffd0()
{
    reinterpret_cast<::FUN_00c81600_cls *>((((Ffd0base*)this)))->Initialize();
    m_vtbl = &DAT_010c6234;
    tab = *(const Arr9*)&(*reinterpret_cast<const ::C90160Matrix *>(&::DAT_011a9448));
}

namespace fnv_00c90000 {
void __cdecl FUN_00aa1460(void* object, unsigned int size);
struct FUN_00c90000_Object
{
    int* m_vftable;
    FUN_00c90000_Object* FUN_00c90000(unsigned int flags);
};
// Sets m_vftable to DAT_010c6234, calls FUN_00c81550, and if bit 0 of flags is set calls FUN_00aa1460(this, 0x50); returns this.
// @fnv 0x00c90000
FUN_00c90000_Object* FUN_00c90000_Object::FUN_00c90000(unsigned int flags)
{
    m_vftable = &(*reinterpret_cast<int *>(&::DAT_010c6234));
    reinterpret_cast<::FUN_00c81550_holder *>(this)->FUN_00c81550();
    if (flags & 1)
        FUN_00aa1460(this, 0x50);
    return this;
}
}  // namespace fnv_00c90000

// @fnv 0x00c910c0
void FUN_00c910c0()
{}

// @fnv 0x00c911c0
bool FUN_00c911c0()
{
    return true;
}

struct OperationPacket
{
    unsigned char operation;
    void* target;
    unsigned int value;
};
struct CommandTarget
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Receive(unsigned int value);
};
struct CommandDispatcher
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
    CommandTarget* DispatchCommand(CommandTarget* target, unsigned int value);
};
// If unk94 is set, builds an OperationPacket with operation 0x24 and calls FUN_00c91160; otherwise calls target->Receive(value) and returns target.
// @fnv 0x00c92a30
CommandTarget* CommandDispatcher::DispatchCommand(CommandTarget* target, unsigned int value)
{
    if (unk94)
    {
        OperationPacket packet;
        packet.operation = 0x24;
        packet.target = target;
        packet.value = value;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
    }
    else
    {
        target->Receive(value);
    }
    return target;
}



struct C99F10Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiBytes) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiBytes) throw();
};

struct C99F10Array
{
    void** m_ppData;
    int m_uiLogicalSize;
    int m_iCapacity;
    ~C99F10Array() throw()
    {
        SpawnedAllocHolder* pHolder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_pAllocator;
        m_uiLogicalSize = 0;
        if (!(m_iCapacity & 0x80000000))
        {
            pAlloc->FreeArray(m_ppData, (m_iCapacity & 0x3fffffff) * 4);
        }
        m_ppData = 0;
        m_iCapacity = 0x80000000;
    }
};

struct C99F10Base
{
    virtual ~C99F10Base() throw()
    {}
    int unk04;
};

struct FUN_00c99f10 : C99F10Base
{
    C99F10Array m_kArray;
    CRITICAL_SECTION* m_pUserData;
    virtual ~FUN_00c99f10() throw();
};

// Deletes the critical section stored in m_pUserData and frees its 0x18-byte allocation via the spawned allocator.
// @fnv 0x00c99f10
FUN_00c99f10::~FUN_00c99f10() throw()
{
    CRITICAL_SECTION* pCS = m_pUserData;
    if (pCS)
    {
        DeleteCriticalSection(pCS);
        SpawnedAllocHolder* pHolder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_pAllocator;
        pAlloc->Free(pCS, sizeof(CRITICAL_SECTION));
    }
}

struct FUN_00c9a520_shell
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
    virtual void* v9(void* pvArg);

    void FUN_00c9a5e0(void* pvArg);
};

// @fnv 0x00c9a5e0
void FUN_00c9a520_shell::FUN_00c9a5e0(void* pvArg)
{
    reinterpret_cast<::ObstacleManagerC9A *>(this)->FUN_00c9a520((::ObstacleDataC9A *)(void *)(v9(pvArg)));
}

struct DispatchObject;
typedef int(* DispatchAction)(DispatchObject*, void*);
struct DispatchObject
{
    void** vtable;
    void* unk04;
    DispatchObject* unk08;
    int type;
    int Dispatch(void* argument)
    {
        return reinterpret_cast<DispatchAction>(vtable[0x38])(this, argument);
    }
};
struct DispatchContainer
{
    void* unk00;
    void* argument;
    void* unk08;
    void* objectLink;
};
typedef void*(* GetTarget)(DispatchObject*);
// The type 8 and 10 objects return the address of m_part inside this wrapper.
struct DispatchWrapper
{
    void* unk00;
    void* unk04;
    DispatchObject* m_target;
    void* unk0c;
    int m_part;
};
// Finds a target from container->objectLink (or container) by object type 8/10 via vtable slot 4, or type 9 via unk08; returns target->Dispatch(argument) or 0x24.
// @fnv 0x00c80020
int __cdecl FUN_00c80020(DispatchContainer* container)
{
    void* link = container->objectLink;
    if (!link)
        link = container;
    DispatchObject* target = 0;
    if (link)
    {
        DispatchObject* object = *reinterpret_cast<DispatchObject**>(link);
        int type = object->type;
        if (type == 8 || type == 10)
        {
            void* result = reinterpret_cast<GetTarget>(object->vtable[4])(object);
            if (result)
            {
                DispatchWrapper* wrapper = reinterpret_cast<DispatchWrapper*>(static_cast<char*>(result) - offsetof(DispatchWrapper, m_part));
                if (wrapper)
                    target = wrapper->m_target;
                else
                    target = 0;
            }
            else
                target = 0;
        }
        else
        {
            DispatchObject* checked = *reinterpret_cast<DispatchObject**>(link);
            if (checked && type == 9)
                target = checked->unk08;
        }
    }
    int result = 0x24;
    if (target)
        result = target->Dispatch(container->argument);
    return result;
}

// FUN_00c80090: cdecl, one pointer arg; probes nested object chain.
class ProbeX;
class ProbeY;
class ProbeZ;
class ProbeE;
class ProbeD;
class ProbeC;
class ProbeObj;


struct PackedPropertyByte
{
    unsigned char value;
    PackedPropertyByte()
    {}
    inline bool operator!=(int rhs) const
    {
        return value != rhs;
    }
};
class ProbeZ
{
  public:
};

class ProbeX
{
  public:
};

class ProbeY
{
  public:
    int unk00;
    int unk04;
    ProbeZ* m_08;
};

struct SelectedBits
{
    unsigned int bits;
    inline operator bool() const
    {
        return bits != 0;
    }
};
class ProbeE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
    inline SelectedBits SelectedFlag() const
    {
        SelectedBits result = {m_0c & 2};
        return result;
    }
};

class ProbeD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ProbeX* m_10;
};

class ProbeC
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual ProbeD* GetD();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
};

class ProbeObj
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
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
    ProbeC** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
    inline unsigned int ChildCount() const
    {
        return m_a6;
    }
    inline ProbeC* FirstChild() const
    {
        return ChildCount() <= 0 ? 0 : *m_a0;
    }
};

static inline bool CheckBody(ProbeD* body, ProbeObj*& obj)
{
    ProbeX* object = body->m_10;
    if (object)
    {
        ProbeY* rigid = ((::ProbeY *)(reinterpret_cast<::NiObject *>((object))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_012681c0))))));
        if (rigid && rigid->m_08)
            return (*(::PackedPropertyByte *)(reinterpret_cast<::FUN_00c9bff0_Class *>((void *)(rigid->m_08))->FUN_00c9bff0({}))) != 0;
    }
    return false;
}
// Gets a body via obj->m_1c->GetD(), or via the first child's m_1c when extra data bit 1 is set; returns whether CheckBody is true for it.
// @fnv 0x00c80090
bool FUN_00c80090(ProbeObj* obj)
{
    bool result = false;
    ProbeC* c = obj->m_1c;
    ProbeD* body = c ? c->GetD() : 0;
    if (!body)
    {
        ProbeE* extra = ((::ProbeE *)(::GetExtraDataChecked((::NiAVObjectX *)(obj))));
        unsigned int sel = extra ? extra->m_0c & 2 : 0;
        if (sel)
        {
            ProbeC* collision = obj->FirstChild()->m_1c;
            if (collision)
                body = collision->GetD();
        }
    }
    if (body)
    {
        if (CheckBody(body, obj))
            result = true;
        else
            result = false;
    }
    return result;
}

struct WalkBits_c804
{
    union
    {
        unsigned int raw;
        struct
        {
            unsigned int lo : 7;
            unsigned int hi : 25;
        };
    };
    WalkBits_c804()
    {}
    WalkBits_c804(unsigned int r) : raw(r)
    {}
    void SetLo(unsigned int f)
    {
        lo = f;
    }
};

class WalkLookup_c804
{
  public:
};

class WalkMid_c804
{
  public:
    void* unk00;
    int unk04;
    ::FUN_00c81aa0_worldObject* m_08;
    void Apply(unsigned int value);
    void Apply2(WalkBits_c804 value);
};

struct WalkHit_c804
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    WalkMid_c804* m_10;
};

struct WalkNode_c804
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_c804* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    WalkLookup_c804* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_c804** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// For node and recursively each child, looks up DAT_012043f8 in m_1c and, if found, applies a value with its low 7 bits set to flag via Apply2.
// @fnv 0x00c804d0
void FUN_00c804d0(WalkNode_c804* node, unsigned int flag)
{
    if (node == 0)
    {
        return;
    }
    if (node->m_1c != 0)
    {
        WalkHit_c804* hit = (WalkHit_c804*)((void *)(reinterpret_cast<::NiObject *>((node->m_1c))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned int *>(&::g_012043f8))))));
        if (hit != 0 && hit->m_10 != 0)
        {
            WalkMid_c804* mid = hit->m_10;
            ::FUN_00c81aa0_worldObject* q = mid->m_08;
            WalkBits_c804 b(q != 0 ? q->m_collidable.m_collisionFilterInfo : 0);
            b.SetLo(flag);
            mid->Apply2(b);
        }
    }
    WalkNode_c804* child = node->v03();
    if (child != 0)
    {
        unsigned int i = 0;
        while (i < child->m_a6)
        {
            WalkNode_c804** arr = child->m_a0;
            WalkNode_c804* item = arr[i];
            FUN_00c804d0(item, flag);
            ++i;
        }
    }
}


struct WorkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    DynCastHelper* unk1C;
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
    WorkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct NodeDepth
{
    WorkNode_cls* node;
    unsigned int depth;
};

struct WorkStack_cls
{
    unsigned int unk00;
    unsigned int* m_04;
    unsigned int m_08;
};

// Recursively searches a work stack for a node matching a dynamic cast, pushing children with increased depth when no match is found.
// @fnv 0x00c80c00
NiObject* __cdecl FUN_00c80c00(WorkNode_cls* apNode, WorkStack_cls* apStack, unsigned int uiMaxDepth,
                               unsigned int uiDepth)
{
    NiObject* result;
    if (apNode->unk1C == 0)
        result = 0;
    else
        result = reinterpret_cast<::NiObject *>((apNode->unk1C))->DynamicCast((const ::NiRTTI *)(const unsigned int *)((unsigned int const*)&(*reinterpret_cast<unsigned int *>(&::g_012043f8))));

    _ReadWriteBarrier();
    if (result == 0)
    {
        if (apNode->v03() != 0 && uiDepth < uiMaxDepth)
        {
            unsigned int index = 0;
            while (index < apNode->m_a6)
            {
                WorkNode_cls* item = apNode->m_a0[index];
                if (item != 0)
                {
                    NodeDepth entry;
                    entry.node = item;
                    entry.depth = uiDepth + 1;
                    reinterpret_cast<::FUN_00c80b20_cls *>((apStack))->InsertItemAt(0, (*(::FUN_00c80b20_item8 *)(&entry)));
                }
                ++index;
            }
        }
    }
    if (apStack->m_08 != 0 && result == 0)
    {
        unsigned int count = apStack->m_08;
        unsigned int* entries = apStack->m_04;
        uintptr_t uiNodePtr = entries[count * 2 - 2];
        unsigned int high = entries[count * 2 - 1];
        apStack->m_08 = count - 1;
        result = FUN_00c80c00((WorkNode_cls*)uiNodePtr, apStack, uiMaxDepth, high);
    }
    return result;
}

// FUN_00c81890 (unit_a1df186ed60f.cpp) - 95B, /MT /O2 /GS /EHsc /Gy
// v4: extern __declspec(thread) int DAT_tls_0x2c0 (probe-exact a1+64 8b 0d+8b 14 81+8b 82 c0020000);
//     uchar bitfield f6/f0 (probe-exact mov cl/shr/test forms); m_bits word AND per v3 match
extern __declspec(thread) int DAT_tls_0x2c0;  // TLS slot +0x2C0 (module index 0x126fd98)
struct FUN_00c65b00_holder
{
    int FUN_00c65b00();
};
struct FUN_00a68bf0_holder
{
    int FUN_00a68bf0();
};  // ?UpdateWorldLoc@NiAVObject@@QAEXXZ

typedef int(* FN_00c81890_VT)(void*);

union U_00c81890
{
    unsigned short m_bits;  // +0xC word member
    struct
    {
        unsigned char f0 : 1;
        unsigned char : 5;
        unsigned char f6 : 1;
        unsigned char : 1;
    } bf;
};

struct E_T
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
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual int va4();
    void* m_p4;
    void* m_p8;
    U_00c81890 u_c;

    bool GetBit(int n) const
    {
        return (u_c.m_bits >> n) & 1;
    }
    void ClearBit(int n)
    {
        u_c.m_bits &= ~(1 << n);
    }
    int FUN_00c81890();
};
// @fnv 0x00c81ae0
void FUN_00c81ae0_cls::InitOnce()
{
    bool first = m_28 == 0;
    m_28++;
    if (first)
    {
        reinterpret_cast<::E_T *>(this)->FUN_00c81890();
        FUN_00c81ae0_target* obj = m_10;
        if (obj != 0)
        {
            FUN_00c81aa0_worldObject* object = obj->m_08;
            unsigned int flags = object != 0 ? object->m_collidable.m_collisionFilterInfo : 0;
            flags &= 0x7f;
            if (flags == 8 || flags == 0x1d)
            {
                void* arg = m_24;
                if (arg != 0)
                {
                    obj->v39(arg);
                }
            }
        }
    }
}

// Returns DAT_tls_0x2c0 if it is 3; otherwise calls FUN_00c65b00 (clearing bit 6), va4, or m_p8->FUN_00a68bf0 depending on bits 6 and 0, else returns it.
// @fnv 0x00c81890
int E_T::FUN_00c81890()
{
    int result = DAT_tls_0x2c0;
    if (result != 3)
    {
        if (GetBit(6))
        {
            if (result != 2)
            {
                result = ((FUN_00c65b00_holder*)this)->FUN_00c65b00();
                ClearBit(6);
                return result;
            }
        }
        else if (GetBit(0))
            return va4();
        if (m_p8)
            return ((FUN_00a68bf0_holder*)m_p8)->FUN_00a68bf0();
    }
    return result;
}

struct A50Inner
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
    int unke0;
    int unke4;
    unsigned char m_e8;
};
class A50Obj
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
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4(int t);
    int m_04;
    A50Inner* m_08;
};
struct A50Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    A50Obj* m_10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    void FUN_00c81a50();
};
// If m_10 is set, calls its ve4(m_20) when m_20 is 4 and kind m_08->m_e8 is not 4, or m_20 is 1 and kind is 4 or 5; a null m_08 also calls.
// @fnv 0x00c81a50
void A50Cls::FUN_00c81a50()
{
    A50Obj* p = m_10;
    if (!p)
        return;
    if (m_20 == 4)
    {
        A50Inner* q = p->m_08;
        int kind = q ? q->m_e8 : 0;
        if (!q)
            goto call;
        if (kind != m_20)
            goto call;
    }
    if (m_20 == 1)
    {
        A50Inner* q = p->m_08;
        int kind = q ? q->m_e8 : 0;
        if (!q)
            goto call;
        if (kind == 4)
            goto call;
        if (kind != 5)
            return;
    }
    else
    {
        return;
    }
call:
    p->ve4(m_20);
}

namespace fnv_00c828f0 {
void FUN_00ec61c0(void*, int, unsigned int);
extern int DAT_01267ea4;
extern int DAT_01267e94;
extern int DAT_01267e9c;

inline void SetSelectionMask(unsigned int uiA, unsigned int uiB, bool bSelected)
{
    if (bSelected)
    {
        ::selected_target_masks[uiA] |= (unsigned __int64)1 << uiB;
        ::selected_target_masks[uiB] |= (unsigned __int64)1 << uiA;
    }
    else
    {
        ::selected_target_masks[uiA] &= ~((unsigned __int64)1 << uiB);
        ::selected_target_masks[uiB] &= ~((unsigned __int64)1 << uiA);
    }
}


inline void SetFlagPair(unsigned int uiA, unsigned int uiB, bool bSelected)
{
    if (bSelected)
    {
        (*reinterpret_cast<unsigned int (*)[32]>(&::DAT_01268078))[uiA] |= 1 << uiB;
        (*reinterpret_cast<unsigned int (*)[32]>(&::DAT_01268078))[uiB] |= 1 << uiA;
    }
    else
    {
        (*reinterpret_cast<unsigned int (*)[32]>(&::DAT_01268078))[uiA] &= ~(1 << uiB);
        (*reinterpret_cast<unsigned int (*)[32]>(&::DAT_01268078))[uiB] &= ~(1 << uiA);
    }
}

// Zeroes DAT_01268078 and DAT_01267e70, fills DAT_01267f20 with 0xFF, applies many pair flag and mask updates, calls FUN_00c82870(34, ...), and sets three ints.
// @fnv 0x00c828f0
void InitializeSelectionMasks()
{
    FUN_00ec61c0((*reinterpret_cast<unsigned int (*)[32]>(&::DAT_01268078)), 0, sizeof((*reinterpret_cast<unsigned int (*)[32]>(&::DAT_01268078))));
    FUN_00ec61c0(::selected_target_masks, 0xFF, sizeof(::selected_target_masks));
    FUN_00ec61c0(DAT_01267e70, 0, sizeof(DAT_01267e70));
    SetFlagPair(6, 1, true);
    SetFlagPair(12, 1, true);
    SetFlagPair(7, 1, true);
    SetFlagPair(13, 1, true);
    SetFlagPair(17, 1, true);
    SetFlagPair(6, 2, true);
    SetFlagPair(12, 2, true);
    SetFlagPair(7, 2, true);
    SetFlagPair(13, 2, true);
    SetFlagPair(6, 3, true);
    SetFlagPair(12, 3, true);
    SetFlagPair(7, 3, true);
    SetFlagPair(13, 3, true);
    SetFlagPair(4, 6, true);
    SetFlagPair(4, 12, true);
    SetFlagPair(4, 7, true);
    SetFlagPair(4, 13, true);
    SetFlagPair(4, 17, true);
    SetFlagPair(5, 12, true);
    SetFlagPair(6, 12, true);
    SetFlagPair(13, 5, true);
    SetFlagPair(6, 13, true);
    SetFlagPair(6, 17, true);
    SetFlagPair(6, 8, true);
    SetFlagPair(6, 14, true);
    SetFlagPair(7, 13, true);
    SetFlagPair(7, 8, true);
    SetFlagPair(7, 14, true);
    SetFlagPair(7, 9, true);
    SetFlagPair(18, 13, true);
    SetFlagPair(18, 8, true);
    SetFlagPair(18, 14, true);
    SetFlagPair(18, 9, true);
    SetFlagPair(15, 7, true);
    SetFlagPair(8, 14, true);
    SetFlagPair(7, 10, true);
    SetFlagPair(18, 15, true);
    SetFlagPair(9, 15, true);
    SetFlagPair(10, 18, true);
    SetFlagPair(16, 7, true);
    SetFlagPair(14, 9, true);
    SetFlagPair(16, 18, true);
    SetFlagPair(10, 14, true);
    SetFlagPair(10, 15, true);
    SetFlagPair(6, 11, true);
    SetFlagPair(7, 11, true);
    SetFlagPair(12, 6, true);
    SetFlagPair(12, 7, true);
    SetFlagPair(12, 17, true);
    SetFlagPair(12, 14, true);
    SetFlagPair(12, 8, true);
    SetFlagPair(13, 8, true);
    SetFlagPair(13, 14, true);
    SetFlagPair(13, 9, true);
    SetFlagPair(13, 15, true);
    SetFlagPair(10, 13, true);
    SetFlagPair(16, 13, true);
    SetFlagPair(8, 15, true);
    SetFlagPair(16, 8, true);
    SetFlagPair(16, 9, true);
    SetFlagPair(22, 7, true);
    SetFlagPair(22, 5, true);
    SetFlagPair(22, 6, true);
    SetFlagPair(22, 13, true);
    SetFlagPair(22, 11, true);
    SetFlagPair(22, 12, true);
    SetFlagPair(22, 1, true);
    SetFlagPair(22, 4, true);
    SetFlagPair(22, 3, true);
    SetFlagPair(22, 2, true);
    SetFlagPair(22, 8, true);
    SetFlagPair(22, 9, true);
    SetFlagPair(22, 10, true);
    SetFlagPair(22, 14, true);
    SetFlagPair(15, 22, true);
    SetFlagPair(16, 22, true);
    SetFlagPair(18, 22, true);
    SetFlagPair(20, 22, true);
    SetFlagPair(21, 22, true);
    SetFlagPair(17, 22, true);
    SetFlagPair(24, 4, true);
    SetFlagPair(24, 3, true);
    SetFlagPair(24, 8, true);
    SetFlagPair(24, 9, true);
    SetFlagPair(24, 10, true);
    SetFlagPair(24, 14, true);
    SetFlagPair(24, 15, true);
    SetFlagPair(24, 16, true);
    SetFlagPair(2, 24, true);
    ::SetSelectionMask(19, 3, false);
    ::SetSelectionMask(19, 26, false);
    ::SetSelectionMask(19, 28, false);
    ::SetSelectionMask(19, 6, false);
    ::SetSelectionMask(19, 7, false);
    ::SetSelectionMask(19, 8, false);
    ::SetSelectionMask(19, 12, false);
    ::SetSelectionMask(19, 15, false);
    ::SetSelectionMask(19, 16, false);
    ::SetSelectionMask(19, 18, false);
    ::SetSelectionMask(19, 30, false);
    ::SetSelectionMask(31, 19, false);
    ::SetSelectionMask(19, 35, false);
    ::SetSelectionMask(19, 33, false);
    ::SetSelectionMask(19, 36, false);
    ::SetSelectionMask(19, 37, false);
    ::SetSelectionMask(38, 19, false);
    ::SetSelectionMask(42, 19, false);
    ::SetSelectionMask(19, 11, false);
    ::SetSelectionMask(20, 15, false);
    ::SetSelectionMask(20, 16, false);
    ::SetSelectionMask(20, 18, false);
    ::SetSelectionMask(20, 37, false);
    ::SetSelectionMask(20, 11, false);
    ::SetSelectionMask(8, 20, false);
    ::SetSelectionMask(21, 1, false);
    ::SetSelectionMask(21, 2, false);
    ::SetSelectionMask(21, 3, false);
    ::SetSelectionMask(21, 26, false);
    ::SetSelectionMask(21, 28, false);
    ::SetSelectionMask(21, 4, false);
    ::SetSelectionMask(21, 5, false);
    ::SetSelectionMask(21, 6, false);
    ::SetSelectionMask(21, 7, false);
    ::SetSelectionMask(21, 8, false);
    ::SetSelectionMask(21, 29, false);
    ::SetSelectionMask(21, 9, false);
    ::SetSelectionMask(21, 10, false);
    ::SetSelectionMask(21, 11, false);
    ::SetSelectionMask(21, 12, false);
    ::SetSelectionMask(21, 13, false);
    ::SetSelectionMask(21, 14, false);
    ::SetSelectionMask(21, 15, false);
    ::SetSelectionMask(21, 17, false);
    ::SetSelectionMask(21, 21, false);
    ::SetSelectionMask(21, 16, false);
    ::SetSelectionMask(21, 30, true);
    ::SetSelectionMask(21, 31, false);
    ::SetSelectionMask(21, 35, false);
    ::SetSelectionMask(21, 33, true);
    ::SetSelectionMask(37, 21, false);
    ::SetSelectionMask(38, 21, false);
    ::SetSelectionMask(39, 21, false);
    ::SetSelectionMask(30, 8, false);
    ::SetSelectionMask(21, 40, false);
    ::SetSelectionMask(21, 41, false);
    ::SetSelectionMask(21, 0, false);
    ::SetSelectionMask(21, 27, false);
    ::SetSelectionMask(30, 29, false);
    ::SetSelectionMask(18, 1, false);
    ::SetSelectionMask(30, 11, true);
    ::SetSelectionMask(18, 2, false);
    ::SetSelectionMask(18, 3, false);
    ::SetSelectionMask(18, 26, false);
    ::SetSelectionMask(18, 28, false);
    ::SetSelectionMask(18, 4, false);
    ::SetSelectionMask(18, 5, false);
    ::SetSelectionMask(18, 6, false);
    ::SetSelectionMask(18, 7, false);
    ::SetSelectionMask(18, 8, false);
    ::SetSelectionMask(18, 29, false);
    ::SetSelectionMask(18, 9, false);
    ::SetSelectionMask(18, 10, false);
    ::SetSelectionMask(18, 11, false);
    ::SetSelectionMask(18, 12, false);
    ::SetSelectionMask(18, 13, false);
    ::SetSelectionMask(18, 14, false);
    ::SetSelectionMask(18, 15, false);
    ::SetSelectionMask(18, 17, false);
    ::SetSelectionMask(18, 18, false);
    ::SetSelectionMask(18, 16, false);
    ::SetSelectionMask(18, 30, false);
    ::SetSelectionMask(18, 31, false);
    ::SetSelectionMask(18, 35, false);
    ::SetSelectionMask(18, 37, false);
    ::SetSelectionMask(29, 8, false);
    ::SetSelectionMask(38, 18, false);
    ::SetSelectionMask(39, 18, false);
    ::SetSelectionMask(40, 18, false);
    ::SetSelectionMask(41, 18, false);
    ::SetSelectionMask(8, 5, false);
    ::SetSelectionMask(8, 4, false);
    ::SetSelectionMask(10, 8, false);
    ::SetSelectionMask(15, 1, false);
    ::SetSelectionMask(15, 2, false);
    ::SetSelectionMask(15, 3, false);
    ::SetSelectionMask(15, 26, false);
    ::SetSelectionMask(15, 28, false);
    ::SetSelectionMask(15, 4, false);
    ::SetSelectionMask(15, 5, false);
    ::SetSelectionMask(15, 6, false);
    ::SetSelectionMask(15, 7, false);
    ::SetSelectionMask(15, 8, false);
    ::SetSelectionMask(15, 29, false);
    ::SetSelectionMask(15, 9, false);
    ::SetSelectionMask(15, 10, false);
    ::SetSelectionMask(15, 11, false);
    ::SetSelectionMask(15, 12, false);
    ::SetSelectionMask(15, 13, false);
    ::SetSelectionMask(15, 14, false);
    ::SetSelectionMask(15, 15, false);
    ::SetSelectionMask(15, 17, false);
    ::SetSelectionMask(15, 16, false);
    ::SetSelectionMask(15, 30, false);
    ::SetSelectionMask(15, 31, false);
    ::SetSelectionMask(15, 35, false);
    ::SetSelectionMask(15, 37, false);
    ::SetSelectionMask(15, 38, false);
    ::SetSelectionMask(15, 39, false);
    ::SetSelectionMask(15, 40, false);
    ::SetSelectionMask(15, 41, false);
    ::SetSelectionMask(33, 1, false);
    ::SetSelectionMask(33, 2, false);
    ::SetSelectionMask(33, 3, false);
    ::SetSelectionMask(33, 26, false);
    ::SetSelectionMask(33, 28, false);
    ::SetSelectionMask(33, 4, false);
    ::SetSelectionMask(33, 5, false);
    ::SetSelectionMask(33, 6, false);
    ::SetSelectionMask(33, 7, false);
    ::SetSelectionMask(33, 8, false);
    ::SetSelectionMask(33, 29, false);
    ::SetSelectionMask(33, 9, false);
    ::SetSelectionMask(33, 10, false);
    ::SetSelectionMask(33, 11, true);
    ::SetSelectionMask(33, 12, false);
    ::SetSelectionMask(33, 13, false);
    ::SetSelectionMask(33, 14, false);
    ::SetSelectionMask(33, 33, false);
    ::SetSelectionMask(33, 17, false);
    ::SetSelectionMask(33, 15, false);
    ::SetSelectionMask(33, 16, false);
    ::SetSelectionMask(33, 30, false);
    ::SetSelectionMask(33, 31, false);
    ::SetSelectionMask(33, 35, false);
    ::SetSelectionMask(33, 37, false);
    ::SetSelectionMask(33, 38, false);
    ::SetSelectionMask(33, 39, false);
    ::SetSelectionMask(33, 40, false);
    ::SetSelectionMask(33, 41, false);
    ::SetSelectionMask(35, 5, false);
    ::SetSelectionMask(35, 7, false);
    ::SetSelectionMask(35, 12, false);
    ::SetSelectionMask(35, 35, false);
    ::SetSelectionMask(35, 11, false);
    ::SetSelectionMask(35, 6, false);
    ::SetSelectionMask(36, 7, false);
    ::SetSelectionMask(36, 12, false);
    ::SetSelectionMask(36, 11, false);
    ::SetSelectionMask(37, 3, false);
    ::SetSelectionMask(37, 26, false);
    ::SetSelectionMask(37, 28, false);
    ::SetSelectionMask(37, 7, false);
    ::SetSelectionMask(37, 11, false);
    ::SetSelectionMask(37, 12, false);
    ::SetSelectionMask(37, 30, false);
    ::SetSelectionMask(38, 31, false);
    ::SetSelectionMask(38, 4, false);
    ::SetSelectionMask(38, 5, false);
    ::SetSelectionMask(38, 6, false);
    ::SetSelectionMask(38, 7, false);
    ::SetSelectionMask(38, 8, false);
    ::SetSelectionMask(38, 29, false);
    ::SetSelectionMask(38, 30, false);
    ::SetSelectionMask(38, 10, false);
    ::SetSelectionMask(38, 35, false);
    ::SetSelectionMask(38, 12, false);
    ::SetSelectionMask(38, 14, false);
    ::SetSelectionMask(38, 16, false);
    ::SetSelectionMask(38, 41, false);
    ::SetSelectionMask(38, 36, false);
    ::SetSelectionMask(38, 37, false);
    ::SetSelectionMask(31, 31, false);
    ::SetSelectionMask(31, 1, false);
    ::SetSelectionMask(31, 4, false);
    ::SetSelectionMask(31, 5, false);
    ::SetSelectionMask(31, 6, false);
    ::SetSelectionMask(31, 7, false);
    ::SetSelectionMask(31, 8, false);
    ::SetSelectionMask(31, 29, false);
    ::SetSelectionMask(31, 9, false);
    ::SetSelectionMask(31, 10, false);
    ::SetSelectionMask(31, 11, false);
    ::SetSelectionMask(31, 13, false);
    ::SetSelectionMask(31, 15, false);
    ::SetSelectionMask(31, 17, false);
    ::SetSelectionMask(31, 35, false);
    ::SetSelectionMask(31, 41, false);
    ::SetSelectionMask(31, 36, false);
    ::SetSelectionMask(31, 37, false);
    ::SetSelectionMask(41, 3, false);
    ::SetSelectionMask(41, 26, false);
    ::SetSelectionMask(41, 28, false);
    ::SetSelectionMask(41, 7, false);
    ::SetSelectionMask(41, 11, false);
    ::SetSelectionMask(41, 35, false);
    ::SetSelectionMask(41, 36, false);
    ::SetSelectionMask(41, 37, false);
    ::SetSelectionMask(41, 39, false);
    ::SetSelectionMask(41, 40, false);
    ::SetSelectionMask(41, 38, false);
    ::SetSelectionMask(41, 41, false);
    ::SetSelectionMask(6, 7, false);
    ::SetSelectionMask(6, 16, false);
    ::SetSelectionMask(6, 3, false);
    ::SetSelectionMask(12, 1, false);
    ::SetSelectionMask(12, 2, false);
    ::SetSelectionMask(12, 3, false);
    ::SetSelectionMask(12, 26, false);
    ::SetSelectionMask(12, 28, false);
    ::SetSelectionMask(12, 9, false);
    ::SetSelectionMask(12, 10, false);
    ::SetSelectionMask(12, 11, false);
    ::SetSelectionMask(12, 12, false);
    ::SetSelectionMask(12, 13, false);
    ::SetSelectionMask(12, 15, false);
    ::SetSelectionMask(12, 16, false);
    ::SetSelectionMask(12, 17, false);
    ::SetSelectionMask(12, 22, false);
    ::SetSelectionMask(12, 32, false);
    ::SetSelectionMask(12, 38, false);
    ::SetSelectionMask(12, 42, false);
    ::SetSelectionMask(12, 37, false);
    ::SetSelectionMask(12, 36, false);
    ::SetSelectionMask(12, 41, false);
    ::SetSelectionMask(22, 1, false);
    ::SetSelectionMask(22, 2, false);
    ::SetSelectionMask(22, 3, false);
    ::SetSelectionMask(22, 26, false);
    ::SetSelectionMask(22, 4, false);
    ::SetSelectionMask(22, 5, false);
    ::SetSelectionMask(22, 6, false);
    ::SetSelectionMask(22, 7, false);
    ::SetSelectionMask(22, 8, false);
    ::SetSelectionMask(22, 29, false);
    ::SetSelectionMask(22, 9, false);
    ::SetSelectionMask(22, 10, false);
    ::SetSelectionMask(22, 11, false);
    ::SetSelectionMask(22, 12, false);
    ::SetSelectionMask(22, 13, false);
    ::SetSelectionMask(22, 14, false);
    ::SetSelectionMask(22, 15, false);
    ::SetSelectionMask(22, 16, false);
    ::SetSelectionMask(22, 17, false);
    ::SetSelectionMask(22, 18, false);
    ::SetSelectionMask(22, 19, false);
    ::SetSelectionMask(22, 20, false);
    ::SetSelectionMask(22, 22, false);
    ::SetSelectionMask(22, 23, false);
    ::SetSelectionMask(22, 25, false);
    ::SetSelectionMask(22, 31, false);
    ::SetSelectionMask(22, 32, false);
    ::SetSelectionMask(22, 33, false);
    ::SetSelectionMask(22, 35, false);
    ::SetSelectionMask(22, 36, false);
    ::SetSelectionMask(22, 37, false);
    ::SetSelectionMask(22, 38, false);
    ::SetSelectionMask(22, 41, false);
    ::SetSelectionMask(22, 42, false);
    ::SetSelectionMask(22, 27, false);
    ::SetSelectionMask(22, 34, false);
    ::SetSelectionMask(22, 0, false);
    ::SetSelectionMask(23, 1, false);
    ::SetSelectionMask(23, 2, false);
    ::SetSelectionMask(23, 3, false);
    ::SetSelectionMask(23, 26, false);
    ::SetSelectionMask(23, 28, false);
    ::SetSelectionMask(23, 4, false);
    ::SetSelectionMask(23, 5, false);
    ::SetSelectionMask(23, 7, false);
    ::SetSelectionMask(23, 8, false);
    ::SetSelectionMask(23, 29, false);
    ::SetSelectionMask(23, 9, false);
    ::SetSelectionMask(23, 10, false);
    ::SetSelectionMask(23, 11, false);
    ::SetSelectionMask(23, 12, false);
    ::SetSelectionMask(23, 13, false);
    ::SetSelectionMask(23, 14, false);
    ::SetSelectionMask(23, 15, false);
    ::SetSelectionMask(23, 16, false);
    ::SetSelectionMask(23, 17, false);
    ::SetSelectionMask(23, 18, false);
    ::SetSelectionMask(23, 19, false);
    ::SetSelectionMask(23, 20, false);
    ::SetSelectionMask(23, 22, false);
    ::SetSelectionMask(23, 23, false);
    ::SetSelectionMask(23, 25, false);
    ::SetSelectionMask(23, 30, false);
    ::SetSelectionMask(23, 31, false);
    ::SetSelectionMask(23, 32, false);
    ::SetSelectionMask(23, 33, false);
    ::SetSelectionMask(23, 35, false);
    ::SetSelectionMask(23, 36, false);
    ::SetSelectionMask(23, 37, false);
    ::SetSelectionMask(23, 38, false);
    ::SetSelectionMask(23, 41, false);
    ::SetSelectionMask(23, 42, false);
    ::SetSelectionMask(24, 1, false);
    ::SetSelectionMask(24, 2, false);
    ::SetSelectionMask(24, 3, false);
    ::SetSelectionMask(24, 26, false);
    ::SetSelectionMask(24, 28, false);
    ::SetSelectionMask(24, 4, false);
    ::SetSelectionMask(24, 5, false);
    ::SetSelectionMask(24, 7, false);
    ::SetSelectionMask(24, 8, false);
    ::SetSelectionMask(24, 29, false);
    ::SetSelectionMask(24, 9, false);
    ::SetSelectionMask(24, 10, false);
    ::SetSelectionMask(24, 11, false);
    ::SetSelectionMask(24, 12, false);
    ::SetSelectionMask(24, 13, false);
    ::SetSelectionMask(24, 14, false);
    ::SetSelectionMask(24, 15, false);
    ::SetSelectionMask(24, 16, false);
    ::SetSelectionMask(24, 17, false);
    ::SetSelectionMask(24, 18, false);
    ::SetSelectionMask(24, 19, false);
    ::SetSelectionMask(24, 20, false);
    ::SetSelectionMask(24, 21, false);
    ::SetSelectionMask(24, 22, false);
    ::SetSelectionMask(24, 23, false);
    ::SetSelectionMask(24, 24, false);
    ::SetSelectionMask(24, 25, false);
    ::SetSelectionMask(24, 31, false);
    ::SetSelectionMask(24, 32, false);
    ::SetSelectionMask(24, 33, false);
    ::SetSelectionMask(24, 35, false);
    ::SetSelectionMask(24, 36, false);
    ::SetSelectionMask(24, 37, false);
    ::SetSelectionMask(24, 38, false);
    ::SetSelectionMask(24, 42, false);
    ::SetSelectionMask(25, 3, false);
    ::SetSelectionMask(25, 26, false);
    ::SetSelectionMask(25, 28, false);
    ::SetSelectionMask(25, 6, false);
    ::SetSelectionMask(25, 7, false);
    ::SetSelectionMask(25, 8, false);
    ::SetSelectionMask(25, 12, false);
    ::SetSelectionMask(25, 15, false);
    ::SetSelectionMask(25, 16, false);
    ::SetSelectionMask(25, 18, false);
    ::SetSelectionMask(25, 30, false);
    ::SetSelectionMask(25, 31, false);
    ::SetSelectionMask(25, 35, false);
    ::SetSelectionMask(25, 36, false);
    ::SetSelectionMask(25, 37, false);
    ::SetSelectionMask(25, 38, false);
    ::SetSelectionMask(25, 42, false);
    ::SetSelectionMask(25, 11, false);
    ::SetSelectionMask(7, 7, false);
    ::SetSelectionMask(7, 16, false);
    ::SetSelectionMask(7, 3, false);
    ::SetSelectionMask(7, 26, false);
    ::SetSelectionMask(7, 28, false);
    ::SetSelectionMask(42, 4, false);
    ::SetSelectionMask(42, 6, false);
    ::SetSelectionMask(42, 5, false);
    ::SetSelectionMask(42, 11, false);
    ::SetSelectionMask(42, 29, false);
    ::SetSelectionMask(42, 31, false);
    ::SetSelectionMask(42, 38, false);
    ::SetSelectionMask(42, 35, false);
    ::SetSelectionMask(42, 41, false);
    ::SetSelectionMask(42, 37, false);
    ::SetSelectionMask(27, 19, false);
    ::SetSelectionMask(27, 25, false);
    ::SetSelectionMask(27, 31, false);
    ::SetSelectionMask(27, 32, false);
    ::SetSelectionMask(27, 33, false);
    ::SetSelectionMask(27, 35, false);
    ::SetSelectionMask(27, 37, false);
    ::SetSelectionMask(27, 42, false);
    ::SetSelectionMask(27, 5, false);
    ::SetSelectionMask(3, 0, false);
    ::SetSelectionMask(3, 13, false);
    ::ShadowLightData::SetTargetMaskForSelection(34, 0x10000004);
    DAT_01267ea4 = 2;
    DAT_01267e94 = 3;
    DAT_01267e9c = 4;
}
}  // namespace fnv_00c828f0

struct FUN_00c84d00_obj
{
    unsigned int unk00;
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00c84d00_cls
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
    virtual int* vGet(FUN_00c84d00_obj** pp);
    void FUN_00c84d00(FUN_00c84d00_obj* a1);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_10;
};
// @fnv 0x00c8b1d0
void H_00c8b1d0::ProcessFileContext(FileContext* volatile object)
{
    FileContext* stableObject = object;
    reinterpret_cast<::S_00a64670_Foo *>((stableObject))->FUN_00a64670();
    reinterpret_cast<::FUN_00c84d00_cls *>(this)->FUN_00c84d00((::FUN_00c84d00_obj *)(stableObject));
    char* data = GetDataPosition(&object);
    if (reinterpret_cast<S_00c9af40_Stream*>(stableObject)->unk1e5 != 1)
    {
        int size = GetDataSize();
        ::FUN_00cf0930(data, size, (::Vector3 *)(char *)(data + 0x10));
        ::FUN_00cf0930(data, size, (::Vector3 *)(char *)(data + 4));
    }
    ::LoadIntArray((::S_00cf10f0_Stream *)(stableObject), (::S_00cf10f0_Arr4 *)(char *)(data + 0x10));
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// @fnv 0x00c84d00
void FUN_00c84d00_cls::FUN_00c84d00(FUN_00c84d00_obj* apObj)
{
    reinterpret_cast<::FUN_00c87650_t *>(this)->LoadBinary((*(::NiStream *)(apObj)));
    FUN_00c84d00_obj* out;
    int* p = vGet(&out);
    if (apObj->m_1e5 != 1)
    {
        *p = (int)_byteswap_ulong((unsigned long)*p);
    }
    if (*p >= 0x24)
    {
        *p = 0;
    }
    m_10 = *p;
    *p = 0;
}

class Obj
{
  public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0a();
    virtual void* v0b();
    virtual void* v0c();
    virtual void* v0d();
    virtual void* v0e();
    virtual void* v0f();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1a();
    virtual void* v1b();
    virtual void* v1c();
    virtual void* v1d();
    virtual void* v1e();
    virtual void* v1f();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    unsigned int unk04;
    Obj* m_08;
    bool FUN_00c85810(Obj* a);
};
// If m_08 is set: with a null, calls v28; otherwise if v25() differs from a->m_08, calls v28, passes m_08 to a->FUN_00c6b0a0 and returns true.
// @fnv 0x00c85810
bool Obj::FUN_00c85810(Obj* a)
{
    Obj* p = this ? m_08 : 0;
    bool r = false;
    if (p)
    {
        if (a)
        {
            Obj* w = (Obj*)this->v25();
            if (w != a->m_08)
            {
                this->v28();
                reinterpret_cast<::QueueManager *>((a))->FUN_00c6b0a0((::IntegerMapEntry *)(p));
                r = true;
            }
        }
        else
        {
            this->v28();
        }
    }
    return r;
}


struct FUN_00a63430_class
{
};

struct FUN_00653290_class
{
};

struct FUN_00cca4e0
{
    void* m_00;
    void* m_04;
    void* m_08;
    int m_0c;
    int m_10;
    FUN_00cca4e0(void* value);
};

struct FUN_00c87670_class
{
};

struct S00c859e0_holder
{
    void* m_00;
    void* m_04;
};

typedef S00c859e0_holder*(* S00c859e0_slot45)(void*, uintptr_t*);

struct S00c859e0_found
{
    void* vtable;
    unsigned int m_uiRefCount;
    void* m_08;
};

struct S00c859e0_cls
{
    void FUN_00c859e0(uintptr_t value);
};

// Calls vtable slot 45 for a holder, sets its m_04 from FUN_00a63430's result (or a new FUN_00cca4e0's m_08 under type checks), then calls FUN_00c87670.
// @fnv 0x00c859e0
void S00c859e0_cls::FUN_00c859e0(uintptr_t value)
{
    uintptr_t id = value;
    _ReadWriteBarrier();
    void* found = ((void *)(reinterpret_cast<::NiStream *>((reinterpret_cast<FUN_00a63430_class*>(id)))->GetLoadedObject()));
    void** table = *reinterpret_cast<void***>(this);
    S00c859e0_holder* holder = reinterpret_cast<S00c859e0_slot45>(table[45])(this, &value);
    if (found != 0)
    {
        holder->m_04 = static_cast<S00c859e0_found*>(found)->m_08;
        if (((intptr_t)(reinterpret_cast<::NiObject *>((reinterpret_cast<FUN_00653290_class*>(this)))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681c0)))))) != 0)
        {
            if (((intptr_t)(reinterpret_cast<::NiObject *>((reinterpret_cast<FUN_00653290_class*>(found)))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012682e8)))))) != 0 ||
                ((intptr_t)(reinterpret_cast<::NiObject *>((reinterpret_cast<FUN_00653290_class*>(found)))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012682dc)))))) != 0)
            {
                FUN_00cca4e0* created = new FUN_00cca4e0(found);
                void* tail = created ? created->m_08 : 0;
                if (created != 0)
                {
                    holder->m_04 = tail;
                }
            }
        }
    }
    reinterpret_cast<::FUN_00c87670_Class *>((reinterpret_cast<FUN_00c87670_class*>(this)))->FUN_00c87670((*(::NiStream *)(id)));
}


inline unsigned int GetMemContextC877()
{
    return ::currentAllocationContext;
}

inline void SetMemContextC877(unsigned int m_uiGeometryShaderFlags)
{
    ::currentAllocationContext = m_uiGeometryShaderFlags;
}

class AutoMemContextC877
{
  public:
    AutoMemContextC877(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC877();
        SetMemContextC877(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC877()
    {
        SetMemContextC877(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

struct BlockPool_c877
{
};

class PoolOwnerBase_c877
{
  public:
    virtual void v00();
    ~PoolOwnerBase_c877();
    int unk04;
    int unk08;
};

class FUN_00c877b0 : public PoolOwnerBase_c877
{
  public:
    virtual void v00();
    ~FUN_00c877b0();
    void* m_pvBlock;
};

// Sets the thread memory context to 0x10 while freeing m_pvBlock through the allocator at DAT_011f6238, then nulls m_pvBlock and restores the context.
// @fnv 0x00c877b0
FUN_00c877b0::~FUN_00c877b0()
{
    AutoMemContextC877 kContext(0x10);
    void* pvBlock = m_pvBlock;
    reinterpret_cast<::FNV_MemoryManager *>((((BlockPool_c877*)&(*reinterpret_cast<::NiAllocator *>(&::g_memoryManager)))))->FUN_00aa4060(pvBlock);
    m_pvBlock = 0;
}

struct C89AC0_Owner;
struct C89AC0_Child
{
    int unk00;
    int unk04;
    C89AC0_Owner* m_pSharedOwner;
};
struct C89AC0_Owner
{
    int unk00;
    C89AC0_Child* m_pChildObject;
    void SetChildObject(C89AC0_Child* child);
};
// Sets the TLS field to 16 for the call, invokes SetChildObject on object, then calls object->removeReference().
// @fnv 0x00c8a1b0
void FUN_009ba5f0_shell::ReleaseObject(hkReferencedObject* object, intptr_t unused)
{
    TlsGuard guard;
    reinterpret_cast<::C89AC0_Owner *>(this)->SetChildObject((::C89AC0_Child *)((intptr_t)object));
    reinterpret_cast<::hkReferencedObjectC905 *>((object))->FUN_00c905b0();
}
// @fnv 0x00c89ac0
void C89AC0_Owner::SetChildObject(C89AC0_Child* child)
{
    MemoryContextGuard guard;
    if (m_pChildObject)
    {
        m_pChildObject->m_pSharedOwner = 0;
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pChildObject))->FUN_00c905b0();
    }
    if (child)
    {
        reinterpret_cast<::FUN_00c90510_class *>((child))->FUN_00c90510();
        child->m_pSharedOwner = this;
    }
    m_pChildObject = child;
}

struct ThreadData674
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};
struct Context674
{
    unsigned int previous;
    Context674()
    {
        previous = (*reinterpret_cast<::ThreadData674 *>(&::g_tlsBlock)).context;
        (*reinterpret_cast<::ThreadData674 *>(&::g_tlsBlock)).context = 16;
    }
    ~Context674()
    {
        (*reinterpret_cast<::ThreadData674 *>(&::g_tlsBlock)).context = previous;
    }
};
struct Input674
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(Input674*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes)
    {
        unsigned int size = bytes;
        position += read(this, data, bytes, &size, 1);
    }
};
struct Stream674
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    Input674* input;
    Input674* Input()
    {
        return input;
    }
};
struct Heap674
{
    virtual void v0();
    virtual void* Allocate(unsigned int);
};
struct Router674
{
    int unk00, unk04, unk08, unk0C;
    Heap674* heap;
};
struct Base674
{
    virtual ~Base674();
    unsigned short size;
    unsigned short flags;
    static void* operator new(std::size_t size)
    {
        SpawnedAllocHolder* r = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
        Heap674* heap = (Heap674*)r->m_pAllocator;
        Base674* b = (Base674*)heap->Allocate(size);
        b->size = (unsigned short)size;
        return b;
    }
    static void operator delete(void* memory);
};
struct FUN_00cf4190_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00cf4190_class();
};
struct FUN_00cf43b0_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    FUN_00cf43b0_class();
};
struct FUN_00cf45d0_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18;
    FUN_00cf45d0_class();
};
// Reads a type byte and, for types 1 to 3, allocates the matching Base674 subclass, calls its stream method and returns it; otherwise returns null.
// @fnv 0x00c8a330
void* FUN_00c8a330(Stream674* stream)
{
    Context674 context;
    Base674* result = 0;

    unsigned char type = 0;
    stream->Input()->Read(&type, 1);
    switch (type)
    {
    case 1: {
        FUN_00cf4190_class* o = new FUN_00cf4190_class;
        reinterpret_cast<::SerializedRecord *>((o))->FUN_00cf41c0((::StreamView *)(stream));
        result = o;
        break;
    }
    case 2: {
        FUN_00cf43b0_class* o = new FUN_00cf43b0_class;
        reinterpret_cast<::SerializableCF44 *>((o))->FUN_00cf4400((*(::NiStreamCF44 *)(stream)));
        result = o;
        break;
    }
    case 3: {
        FUN_00cf45d0_class* o = new FUN_00cf45d0_class;
        reinterpret_cast<::hkObjCF46 *>((o))->SaveToArchive((::hkArchiveCF46 *)(stream));
        result = o;
        break;
    }
    }
    return result;
}

struct C8AC00_Info
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
    int id;
};

struct C8AC00_Target
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
    virtual C8AC00_Info* GetInfo();
};

struct C8AC00_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    C8AC00_Target* target;
};

struct C8AC00_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int id;
};

struct C8AC00_Self
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
    virtual C8AC00_Owner* GetOwner();
    int unk04;
    C8AC00_Sub* sub;
    bool FUN_00c8ac00();
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);

// Returns false if the owner has no target; otherwise returns FUN_00c87b40(), first calling sub->SetRefObject(0) if sub's id equals the target info's id.
// @fnv 0x00c8ac00
bool C8AC00_Self::FUN_00c8ac00()
{
    ScopedMemoryCategory guard;
    C8AC00_Owner* owner = GetOwner();
    C8AC00_Target* target = owner ? owner->target : 0;
    _ReadWriteBarrier();
    if (target)
    {
        bool result = reinterpret_cast<::EntityOwner_c87b *>(this)->FUN_00c87b40();
        int id = sub ? sub->id : 0;
        C8AC00_Info* info = target->GetInfo();
        int infoId = 0;
        if (info)
            infoId = info->id;
        if (id == infoId)
        {
            if (sub)
            {
                reinterpret_cast<::FUN_00cf4d30_class *>((sub))->SetRefObject((void *)(0));
                return result;
            }
            return result;
        }
        return result;
    }
    return false;
}

namespace fnv_00c8af10 {
void* __cdecl FUN_00aa13e0(size_t size);
struct NewShape
{
    int* vtable;
    int field04, field08, field0c, field10;
    NewShape()
    {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        vtable = &::DAT_01030bf4;
        field0c = 0;
        field10 = 0;
        ++::DAT_012680f8;
        vtable = &::DAT_010c44e4;
        ++::DAT_012686d0;
        vtable = &::DAT_010c485c;
        ++::DAT_012681a0;
    }
};
struct MemoryCategoryScope
{
    unsigned int previous;
    MemoryCategoryScope() : previous(::currentAllocationContext)
    {
        ::currentAllocationContext = 16;
    }
    ~MemoryCategoryScope()
    {
        ::currentAllocationContext = previous;
    }
};
struct FUN_00c8af10_holder
{
    unsigned int* FUN_00c8af10(unsigned int param);
};
// Allocates and constructs a NewShape, calls this object's virtual at slot 49 with it and param, and returns the new object.
// @fnv 0x00c8af10
unsigned int* FUN_00c8af10_holder::FUN_00c8af10(unsigned int param)
{
    MemoryCategoryScope scope;
    ::FUN_00c876f0();
    NewShape* result = new NewShape;
    typedef void(* Dispatch)(FUN_00c8af10_holder*, NewShape*, unsigned int);
    void** vtable = *(void***)this;
    ((Dispatch)vtable[49])(this, result, param);
    ::FUN_00c87700();
    return (unsigned int*)result;
}
}  // namespace fnv_00c8af10

struct AllocLocal;
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n);
struct TypeInfoLocal
{
    const char* name;
    TypeInfoLocal* base;
};
struct ShapeLocal
{
    virtual void v0();
    virtual void v1();
    virtual TypeInfoLocal* GetType();
    int reference;
    ShapeLocal* object;
    bool IsType(const TypeInfoLocal* type)
    {
        const TypeInfoLocal* current = GetType();
        while (current)
        {
            if (current == type)
                return true;
            current = current->base;
        }
        return false;
    }
};
struct WrapperLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    WrapperLocal(ShapeLocal*);
};

struct AllocLocal;
struct AllocTableLocal
{
    void(* v0)(AllocLocal*);
    void(* v1)(AllocLocal*);
    void(* v2)(AllocLocal*);
    void(* v3)(AllocLocal*);
    void(* free)(AllocLocal*, void*, int);
};
struct AllocViewLocal
{
    AllocTableLocal* table;
};
struct AllocLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
    void Clear(SpawnedPtrArray& arr)
    {
        int cap = arr.m_uiCapacity;
        arr.m_uiCount = 0;
        if (!(cap & 0x80000000))
        {
            void* p = arr.m_pData;
            DeallocateLocal(this, p, cap & 0x3fffffff);
        }
        arr.m_pData = 0;
        arr.m_uiCapacity = 0x80000000;
    }
};
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n)
{
    a->Free(p, n * 4);
}
template <class T> inline void ConstructLocal(T* dest, int n, const T& value)
{
    for (int k = 0; k < n; ++k)
        dest[k] = value;
}
struct ArrayLocal : SpawnedPtrArray
{
    void Clear(AllocLocal& allocator)
    {
        m_uiCount = 0;
        if ((int)m_uiCapacity >= 0)
            allocator.Free(m_pData, (m_uiCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_uiCapacity = 0x80000000;
    }
    void Reserve(void* allocator, int count)
    {
        int capacity = m_uiCapacity & 0x3fffffff;
        if (capacity < count)
        {
            int desired = capacity * 2;
            if (count >= desired)
                desired = count;
            ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(::SpawnedPtrArray *)(this), desired, 4);
        }
    }
    void Append(SpawnedAllocHolder* holder, ShapeLocal* raw)
    {
        if (m_uiCount == (m_uiCapacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(::SpawnedPtrArray *)(this), 4);
        ConstructLocal(m_pData + m_uiCount, 1, (void*)raw);
        ++m_uiCount;
    }
};
struct LoadStreamLocal
{
    int unk00;
    unsigned int version;
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
    char filename;
};
struct ListLocal
{
    int unk00;
    ArrayLocal items;
};
struct LoaderLocal
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
    virtual ListLocal* GetList(bool*);
    void LoadShapes(LoadStreamLocal*);
};
// Refills items with shapes read from stream (some wrapped in WrapperLocal), builds an old-version message when version < 17, then calls FUN_00c84cc0.
// @fnv 0x00c8b5e0
void LoaderLocal::LoadShapes(LoadStreamLocal* stream)
{
    MemContextScope context(16);
    bool shared;
    ListLocal* list = GetList(&shared);
    unsigned int count = reinterpret_cast<::FUN_00a63460_shell *>((stream))->FUN_00a63460();
    ArrayLocal& items = list->items;
    SpawnedAllocHolder* h1 = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
    ((AllocLocal*)h1->m_pAllocator)->Clear(items);
    SpawnedAllocHolder* h2 = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
    items.Reserve(h2->m_pAllocator, count);
    if (count > 0)
    {
        unsigned int remaining = count;
        do
        {
            ShapeLocal* object = ((::ShapeLocal *)(reinterpret_cast<::NiStream *>((stream))->GetLoadedObject()));
            if (object)
            {
                ShapeLocal* converted = object->IsType(&(*reinterpret_cast<::TypeInfoLocal *>(&::g_012682e8))) ? object : 0;
                if (converted || ((::ShapeLocal *)(reinterpret_cast<::NiObject *>((object))->DynamicCast((const ::NiRTTI *)(const ::TypeInfoLocal *)(&(*reinterpret_cast<::TypeInfoLocal *>(&::g_012682dc)))))))
                {
                    WrapperLocal* wrapper = new WrapperLocal(object);
                    if (wrapper)
                        object = (ShapeLocal*)wrapper;
                }
                ShapeLocal* raw = object ? object->object : 0;
                items.Append(static_cast<SpawnedAllocHolder*>(::FUN_00c85750()), raw);
            }
        } while (--remaining);
    }
    if (stream->version < 17)
    {
        unsigned int size = list->items.m_uiCount;
        unsigned int index = 0;
        for (; index < size; ++index)
        {
            ShapeLocal* entry = (ShapeLocal*)items.m_pData[index];
            if (entry && entry->object)
            {
                ShapeLocal* shape = entry->object;
                if (!shape->IsType(&(*reinterpret_cast<::TypeInfoLocal *>(&::g_012686a0))) && !shape->IsType(&(*reinterpret_cast<::TypeInfoLocal *>(&::g_01268264))))
                    goto finished;
            }
        }
        {
            char message[1000];
            ::FUN_00406d00(message, 1000,
                      "HAVOK: %s contains an old (Havok 3.3) hkpConvexListShape (%d) and should be re-exported to 17.",
                      &stream->filename, stream->version);
        }
    }
finished:
    ::FUN_00c84cc0((int *)this, (uintptr_t)(stream));
}

class S00c8bf40_Flags
{
  public:
    bool FUN_00c8bf40(const S00c8bf40_Flags* pkOther) const;
};

// @fnv 0x00c8bf40
bool S00c8bf40_Flags::FUN_00c8bf40(const S00c8bf40_Flags* pkOther) const
{
    return reinterpret_cast<::FUN_00c84dc0_cls *>((void *)this)->FUN_00c84dc0((::FUN_00c84dc0_param *)(pkOther));
}


struct FUN_00c6c290
{
public:
    ~FUN_00c6c290();
};
// @fnv 0x00c81550
void FUN_00c81550_holder::FUN_00c81550()
{
    *(void**)this = (void*)&DAT_010c53dc;
    --DAT_01267e60;
    reinterpret_cast<::FUN_00c6c290 *>((((FUN_00c6c290_holder*)this)))->FUN_00c6c290::~FUN_00c6c290();
}
// @fnv 0x00c81640
void* FUN_00c81640_cls::FUN_00c81640(bool abFree)
{
    *reinterpret_cast<void**>(this) = &DAT_010c53dc;
    --DAT_01267e60;
    reinterpret_cast<::FUN_00c6c290 *>((reinterpret_cast<FUN_00c6c290_holder*>(this)))->FUN_00c6c290::~FUN_00c6c290();
    if (abFree & 1)
        _delete(this, 0x2c);
    return this;
}
struct S00c90090_Obj
{
    virtual void S00c90090_v0();
    virtual void S00c90090_v1();
    int m_ref;
};
struct S00c90090_Ptr
{
    S00c90090_Obj* p;
    S00c90090_Ptr(S00c90090_Obj* q) : p(q)
    {
        if (p)
            InterlockedIncrement((long volatile*)&p->m_ref);
    }
    ~S00c90090_Ptr()
    {
        if (p)
        {
            if (!InterlockedDecrement((long volatile*)&p->m_ref))
                p->S00c90090_v1();
        }
    }
};
struct S00c90090_Self
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C(int i);
    int m_p4;
    int m_p8;
    int m_pc;
    S00c90090_Obj* m_p10;
    int m_p14;
    float m_f18;
    float m_f1c;
    int m_p20;
    int m_p24;
    float GetF1C() const
    {
        return m_f1c;
    }
    void SetF1C(float f)
    {
        m_f1c = f;
    }
    float GetF18() const
    {
        return m_f18;
    }
    void SetF18(float f)
    {
        m_f18 = f;
    }
    void FUN_00c90090(S00c90090_Self* src);
};
// Copies src's m_p10 object (via FUN_00c6b980), the two floats and m_p24, then calls vf8C with src->m_p8.
// @fnv 0x00c90090
void S00c90090_Self::FUN_00c90090(S00c90090_Self* src)
{
    S00c90090_Ptr r(src->m_p10);
    reinterpret_cast<::FUN_00c6b980_cls *>((((FUN_00c6c290*)src)))->FUN_00c6b980((::World_c6b *)(0));
    reinterpret_cast<::FUN_00c6b980_cls *>((((FUN_00c6c290*)this)))->FUN_00c6b980((::World_c6b *)((intptr_t)r.p));
    SetF1C(src->GetF1C());
    SetF18(src->GetF18());
    int t24 = src->m_p24;
    m_p24 = t24;
    int n = src->m_p8;
    vf8C(n);
}

struct NiMatrix3Stub
{
    float m[9];
};

struct bhkTransformShapeStub : FUN_00c825b0_cls
{
    int unk28;
    NiMatrix3Stub m_kAdditionalRotation;

    void FUN_00c90240(ViewerStrings* pkStrings);
};

// Calls AddToViewerStrings, adds a debug string made from DAT_012681cc, then adds m_kAdditionalRotation formatted as AdditionalRotation to pkStrings.
// @fnv 0x00c90240
void bhkTransformShapeStub::FUN_00c90240(ViewerStrings* pkStrings)
{
    TlsGuard_t guard;
    AddToViewerStrings(pkStrings);
    pkStrings->Add(::FUN_00a7d330(*reinterpret_cast<const char* const*>(&::g_012681cc)));
    pkStrings->Add(reinterpret_cast<::FloatMatrix3 *>((void *)&(m_kAdditionalRotation))->ToString("AdditionalRotation"));
}


struct MotionSettings
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
    float first;
    float second;
    int mode;
    void SetPreset(int preset);
};

// Sets first, second, and mode fields from preset-specific constants based on the preset index.
// @fnv 0x00c90a60
void MotionSettings::SetPreset(int preset)
{
    switch (preset)
    {
    case 1:
        first = ::DAT_01017870;
        mode = 2;
        second = DAT_010177e8;
        break;
    case 2:
        first = ::DAT_01018180;
        mode = 2;
        second = 1.0f;
        break;
    case 3:
        mode = 2;
        first = DAT_010177e8;
        second = ::runtimeFloatSettingDefault1085;
        break;
    case 4:
        first = ::DAT_01017870;
        mode = 4;
        second = DAT_010177e8;
        break;
    case 5:
        first = ::DAT_01018180;
        mode = 4;
        second = 1.0f;
        break;
    case 6:
        mode = 4;
        first = DAT_010177e8;
        second = ::runtimeFloatSettingDefault1085;
        break;
    case 7:
        first = ::DAT_01017870;
        mode = 8;
        second = DAT_010177e8;
        break;
    case 8:
        first = ::DAT_01018180;
        mode = 8;
        second = 1.0f;
        break;
    case 9:
        mode = 8;
        first = DAT_010177e8;
        second = ::runtimeFloatSettingDefault1085;
        break;
    }
}

struct SpawnedAllocHolder;

extern "C" void __cdecl FUN_00c92950(void*);
extern "C" double clobber_c929e0(double);

struct FUN_00c929e0_Alloc
{
    virtual void vf00();
    virtual void* vf04(unsigned int size);
};

struct FUN_00d065e0_class
{
};

static __declspec(noinline) void FUN_00c927c0(void* p, void* q)
{
    volatile int sink = 0;
    char* s = (char*)static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
    if (p)
        sink = 1;
    if (q)
        sink = 2;
    clobber_c929e0(1.0);
    sink += s[0];
    if (p)
        sink = 3;
    if (q)
        sink = 4;
    if (p)
        sink = 5;
}

static __declspec(noinline) void InvokeOnAllOwners(void* a, void* b)
{
    volatile int sink = 0;
    if (a)
        sink = 1;
    clobber_c929e0(2.0);
    if (a)
        sink = 2;
    if (b)
        sink = 3;
}

class FUN_00c929e0_ThisClass
{
  public:
    void* FUN_00c929e0();
};

// Allocates 0x44 bytes from the holder's allocator, sets its size field, constructs it via FUN_00d065e0, runs setup calls with this, and returns it.
// @fnv 0x00c929e0
void* FUN_00c929e0_ThisClass::FUN_00c929e0()
{
    SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
    FUN_00c929e0_Alloc* alloc = *(FUN_00c929e0_Alloc**)&holder->m_pAllocator;
    void* b = alloc->vf04(0x44);
    static_cast<hkRefObj_c8b090*>(b)->m_usMemSizeAndFlags = 0x44;
    void* ret = ((void *)(new ((void *)(((FUN_00d065e0_class*)b))) ::FUN_00d065e0()));
    FUN_00c927c0(ret, ret);
    FUN_00c92950(ret);
    InvokeOnAllOwners(this, ret);
    ::FUN_00c928c0((::FUN_00c928c0_Context *)(void *)(this), (::hkpPhysicsSystem *)(ret));
    return ret;
}

struct RefObjectC9
{
    virtual void Unknown();
    virtual void Destroy();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            Destroy();
    }
};
struct SmartC9
{
    RefObjectC9* pointer;
    SmartC9(RefObjectC9* p = 0) : pointer(p)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    SmartC9(const SmartC9& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~SmartC9()
    {
        if (pointer)
            pointer->DecRefCount();
    }
    SmartC9& operator=(const SmartC9& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = other.pointer;
            if (pointer)
                pointer->IncRefCount();
        }
        return *this;
    }
};
struct ListC9
{
    SmartC9 item;
    ListC9* next;
    ListC9(const SmartC9& p) : item(p), next(0)
    {}
    __declspec(noinline) void FUN_00631540(const SmartC9& p)
    {
        if (!p.pointer)
            return;
        if (item.pointer)
        {
            ListC9* node = new ListC9(item);
            node->next = next;
            next = node;
        }
        item = p;
    }
};
struct OwnerC9Body
{
    int unk00, unk04, unk08;
    ListC9 list;
    void AddObject(RefObjectC9* object);
};
// Adds a reference-counted object to the owner's list, wrapping it in a SmartC9 and delegating to the list's insert routine.
// @fnv 0x00c9a460
void OwnerC9Body::AddObject(RefObjectC9* object)
{
    TlsGuard_t context;
    if (object)
        reinterpret_cast<::fnv_00631540::TargetClass *>(&(list))->FUN_00631540((const ::NiPointer< ::NiNode> &)((const ::SmartC9 &)(SmartC9(object))));
}

struct C9A6E0Entry
{
    float fA;
    float fB;
    float fC;
    void Set(float a, float b, float c)
    {
        fA = a;
        fB = b;
        fC = c;
    }
    void Set3(float a, float p)
    {
        float z = (float)(p / 100.0);
        fA = a;
        fB = z;
        fC = z;
    }
};
static inline float Pct(float f)
{
    return (float)(f / 100.0);
}
static inline float Pct2(int f)
{
    return (float)(f / 100.0);
}
// Resets m_kArray, then sets m_f54 and m_f50 to -1.0 and m_i58 to 0.
// @fnv 0x00c9a820
void FUN_00c9a820_class::Reset()
{
    m_kArray.FUN_00c9a6e0();
    m_f54 = -1.0f;
    m_i58 = 0;
    m_f50 = -1.0f;
}

// Resets all entries to (-1, 0, 0) and zeroes the count and allocated capacity.
// @fnv 0x00c9a6e0
void C9A6E0Array::FUN_00c9a6e0()
{
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        float fZero = Pct(0.0f);
        m_pkEntryArray[i].Set(-1.0f, fZero, fZero);
    }
    m_uiCount = 0;
    m_uiAllocatedCapacity = 0;
}

namespace fnv_00c9a730 {

class FNVVec3Elem
{
  public:
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};

class FNVVec3Range
{
  public:
    void* unk00;
    FNVVec3Elem* m_pBase;
    unsigned int unk08;
    unsigned int m_uiSize;
    int m_iArrayLength;
    void SetElement(unsigned int index, FNVVec3Elem* v);
};

// @fnv 0x00c9a730
void FNVVec3Range::SetElement(unsigned int index, FNVVec3Elem* apElem)
{
    FNVVec3Elem dir;
    dir.m_uiX = ::DAT_01012054;
    double rest = 0.0 / ::g_d100;
    if (index >= m_uiSize)
    {
        float r = (float)rest;
        dir.m_uiY = r;
        dir.m_uiZ = r;
        m_uiSize = index + 1;
        if (reinterpret_cast<::FUN_00c9a660_cls *>((apElem))->NotEqual((const ::FUN_00c9a660_cls *)(float *)((float*)&dir)))
            m_iArrayLength++;
    }
    else
    {
        float t = (float)rest;
        dir.m_uiY = t;
        dir.m_uiZ = t;
        bool ok = reinterpret_cast<::FUN_00c9a660_cls *>((apElem))->NotEqual((const ::FUN_00c9a660_cls *)(float *)((float*)&dir));
        dir.m_uiX = ::DAT_01012054;
        float u = (float)rest;
        dir.m_uiY = u;
        dir.m_uiZ = u;
        if (ok)
        {
            if (((bool)(reinterpret_cast<::FUN_00c9a620_Obj *>(&(m_pBase[index]))->FUN_00c9a620((float*)&dir))))
                m_iArrayLength++;
        }
        else
        {
            if (reinterpret_cast<::FUN_00c9a660_cls *>(&(m_pBase[index]))->NotEqual((const ::FUN_00c9a660_cls *)(float *)((float*)&dir)))
                m_iArrayLength--;
        }
    }
    FNVVec3Elem* dst = &m_pBase[index];
    dst->m_uiX = apElem->m_uiX;
    dst->m_uiY = apElem->m_uiY;
    dst->m_uiZ = apElem->m_uiZ;
}
}  // namespace fnv_00c9a730

float __cdecl FUN_00a42050(float t, float a, float b);
struct KeyPair
{
    float time;
    float first;
    float second;
};
struct KeyPairInterpolator
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    unsigned int lastIndex;
    int unk38;
    KeyPair* keys;
    int unk40, unk44;
    unsigned int count;
    bool Interpolate(float time, float& first, float& second);
};
// Finds the keys bracketing time, advancing a cached index, and interpolates first and second between them via FUN_00a42050; returns false if there are no keys.
// @fnv 0x00c9a8c0
bool KeyPairInterpolator::Interpolate(float time, float& first, float& second)
{
    if (count)
    {
        if (count == 1)
        {
            first = keys[0].first;
            second = keys[0].second;
            return true;
        }
        unsigned int last = count - 1;
        float previousTime = keys[lastIndex].time;
        if (time < previousTime)
        {
            lastIndex = 0;
            previousTime = keys[0].time;
        }
        float nextTime = previousTime;
        unsigned int next;
        next = lastIndex + 1;
        __assume(next <= last);
        for (; next <= last; ++next)
        {
            nextTime = keys[next].time;
            if (time <= nextTime)
                break;
            ++lastIndex;
            previousTime = nextTime;
        }
        float delta = nextTime - previousTime;
        float firstValue = keys[lastIndex].first;
        float secondValue = keys[lastIndex].second;
        if (delta != 0.0f)
        {
            float ratio = (time - previousTime) / delta;
            float nextFirst = keys[next].first;
            first = FUN_00a42050(ratio, firstValue, nextFirst);
            float nextSecond = keys[next].second;
            second = FUN_00a42050(ratio, secondValue, nextSecond);
        }
        else
        {
            first = firstValue;
            second = secondValue;
        }
        return true;
    }
    return false;
}


struct TlsGuardS00c9_t
{
    int m_saved;

    TlsGuardS00c9_t()
    {
        m_saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }

    ~TlsGuardS00c9_t()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_saved;
    }
};

struct HeldSub_t
{
};

struct S00c9ade0_Obj
{
    int unk00;
    int unk04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    HeldSub_t* m_2c;

    bool FUN_00c9ade0();
};


// If the high bit of m_08 is set, look up DAT_012683f4 in m_2c and call FUN_00a5c480 on the found entry, returning true on success.
// @fnv 0x00c9ade0
bool S00c9ade0_Obj::FUN_00c9ade0()
{
    TlsGuardS00c9_t guard;
    bool result = false;
    unsigned char flag = m_08 >> 7;
    unsigned char keep = flag;
    if ((flag & keep & 1) != 0)
    {
        HeldSub_t* sub = m_2c;
        void* entry = ((void *)(reinterpret_cast<::MyHost *>((sub))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_012683f4))))));
        if (entry)
        {
            reinterpret_cast<::ControllerOwner *>((sub))->FUN_00a5c480((::NiTimeController *)(entry));
            result = true;
        }
    }
    return result;
}

// @fnv 0x00c9e3e0
void __cdecl FUN_00c9e3e0(void)
{
    return;
}

#include <stdlib.h>
struct C00624070
{
    unsigned int value;
    __declspec(noinline) bool FUN_00624070();
};



__forceinline bool Mask135(unsigned int a, unsigned int b)
{
    return (DAT_01268078[(a >> 8) & 31] & (1 << ((b >> 8) & 31))) != 0;
}

// Returns whether values a and b pass a check using their low 7 layer bits, flag bits, and Mask135 or selected_target_masks lookups.
// @fnv 0x00c84740
bool FUN_00c84740(unsigned int a, unsigned int b)
{

    unsigned int cachedA = a;

    unsigned int cachedB = b;

    unsigned int layerA = cachedA & 0x7f;

    if (layerA != 40 && (((unsigned char)(cachedA >> 14) & 1) || ((unsigned char)(cachedB >> 14) & 1)))
        return false;

    if (!(cachedA & 0xffff0000) || !(cachedB & 0xffff0000))
        return true;

    unsigned int different = (cachedA ^ cachedB) & 0xffff0000;

    unsigned int layerB = cachedB & 0x7f;

    if (layerA == 8 && layerB == layerA && !different)
    {

        return Mask135(cachedA, cachedB);
    }

    if (layerA == 8 && layerB == layerA)
        return false;
    if (different)
        return (selected_target_masks[layerA] & (1ULL << layerB)) != 0;

    if ((cachedA & cachedB) & 0x8000)
    {

        if (!(selected_target_masks[layerA] & (1ULL << layerB)))
            return false;

        return abs(int((cachedA >> 8) & 31) - int((cachedB >> 8) & 31)) != 1;
    }

    if (!((C00624070*)&a)->FUN_00624070() || !((C00624070*)&b)->FUN_00624070())
        return false;

    return Mask135(cachedA, cachedB);
}

__declspec(noinline) bool C00624070::FUN_00624070()
{
    unsigned int layer = value & 127;
    return layer == 8 || layer == 29;
}

// @fnv 0x00c85d20
struct B0
{
    int a, b, c, d;
};
struct F
{
    unsigned a, b, c, d, e, f, g, bits;
};
struct O : B0, F
{
};
unsigned Apply(unsigned bits, char on)
{
    if (on == 0)
        bits |= 0x4000u;
    else
        bits &= ~0x4000u;
    return bits;
}
struct C;
struct C_vtable
{
    void* slots[49];
    void (*Update)(C*);
};
struct C
{
    C_vtable* vt;
    int x;
    O* object;
    void FUN_00c85d20(char active);
};
void C::FUN_00c85d20(char active)
{
    O* item = object;
    F* part = item;
    unsigned bits = part ? part->bits : 0;
    bits = Apply(bits, active);
    part = item;
    if (part)
        part->bits = bits;
    vt->Update(this);
}

extern "C" unsigned long __readfsdword(unsigned long);

struct MemoryCategoryScope_00c89dd0
{
    int previous;
    MemoryCategoryScope_00c89dd0(int* block) : previous(block[0x2b4 / 4])
    {
        block[0x2b4 / 4] = 16;
    }
    ~MemoryCategoryScope_00c89dd0()
    {
        previous = 0;
    }
};

struct PendingAllocation_00c89dd0
{
    void* pointer;
    PendingAllocation_00c89dd0(void* value) : pointer(value)
    {}
    ~PendingAllocation_00c89dd0()
    {
        pointer = 0;
    }
};

struct Allocator_00c89dd0
{
    virtual void reserved();
    virtual void* allocate(unsigned int bytes);
};

struct CloneData_00c89dd0
{
    int unknown00;
    void* first;
    int second;
    void* third;
    void* fourth;
};
struct Instance_00c89dd0
{
};
struct RefCounted_00c89dd0
{
};
struct Dispatch_00c89dd0
{
    virtual void reserved00();
    virtual void reserved01();
    virtual void reserved02();
    virtual void reserved03();
    virtual void reserved04();
    virtual void reserved05();
    virtual void reserved06();
    virtual void reserved07();
    virtual void reserved08();
    virtual void reserved09();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void attach(Instance_00c89dd0*);
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void finish(intptr_t);
    void SpawnAndAttach(intptr_t data);
};
// Constructs a wrapper that stores the given Havok object via SetReferencedObject and increments the wrapper count.
// @fnv 0x00c88380
FUN_00c88380::FUN_00c88380(C88380HavokObject* pkObject)
{
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach((intptr_t)(pkObject));
    ++::DAT_01268318;
}

// Allocates an instance from CloneData, attaches it to the dispatch, releases the refcount, and calls finish with the original data.
// @fnv 0x00c89dd0
void Dispatch_00c89dd0::SpawnAndAttach(intptr_t data)
{
    Dispatch_00c89dd0* owner = this;
    unsigned int slot = (*reinterpret_cast<volatile unsigned long *>(&::DAT_0126fd98));
    int* block = (int*)((void**)__readfsdword(0x2c))[slot];
    MemoryCategoryScope_00c89dd0 memoryScope(block);
    CloneData_00c89dd0* clone = data ? (CloneData_00c89dd0*)(data - offsetof(CloneData_00c89dd0, first)) : 0;
    SpawnedAllocHolder* holder = static_cast<SpawnedAllocHolder*>(::FUN_00c85750());
    Allocator_00c89dd0* allocator = (Allocator_00c89dd0*)holder->m_pAllocator;
    void* memory = allocator->allocate(0x38);
    static_cast<hkRefObj_c8b090*>(memory)->m_usMemSizeAndFlags = 0x38;
    Instance_00c89dd0* instance;
    {
        PendingAllocation_00c89dd0 pending(memory);
        void* argFourth = clone->fourth;
        void* argFirst = clone->third;
        int argLast = clone->second;
        void* argThird = clone->first;
        instance = ((::Instance_00c89dd0 *)(new ((void *)(((Instance_00c89dd0*)memory))) ::FUN_00cf3ea0((::ConstraintEntity *)(argFirst), (::ConstraintEntity *)(argFourth), (::ConstraintData *)(argThird), (::ConstraintPriority)(argLast))));
    }
    owner->attach(instance);
    reinterpret_cast<::hkReferencedObjectC905 *>((((RefCounted_00c89dd0*)instance)))->FUN_00c905b0();
    owner->finish(data);
    block[0x2b4 / 4] = memoryScope.previous;
}

#include <string.h>
#include "fnv/decl/CC5AE0Owner.h"
#include "fnv/decl/ColObj_c65f40.h"
#include "fnv/decl/CollObj.h"
#include "fnv/decl/ControllerC66.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0045cec0_Class.h"
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/decl/FUN_00632c60_Class.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/KFRigidBody.h"
#include "fnv/decl/MalleableGetterStandIn.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/Obj577.h"
#include "fnv/decl/Owner62B.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S_00ca8f50_Src.h"
#include "fnv/decl/fnv_005617c0__FUN_005617c0_.h"
#include "fnv/decl/fnv_00626cb0__FUN_00626cb0_Class.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_0056d000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00c8a000.h"
#include "fnv/symbols_00cdf000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_simd.h"
struct FUN_00c90030_Matrix
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
};

struct FUN_00c90030_Transform
{
    void* FUN_0043f8d0(void* a, void* b, void* c, void* d);
};

struct FUN_00c90030_Result
{
    void* FUN_0043f8d0();
};

struct FUN_00c90030_Outer
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
    FUN_00c90030_Transform unk68;
};

struct FUN_00c90030_Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    struct FUN_00c90030_Outer* unk18;
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

};

struct FUN_00c90030_holder
{
    void* unk00;
    void* unk04;
    FUN_00c90030_Source* unk08;
    void* unk0C;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    FUN_00c90030_Matrix unk2C;

    void FUN_00c90030(int value);
};

// If unk10 is set, calls UpdateNodeState; otherwise calls FUN_00a68bf0 on unk08, then computes a transform and copies 9 ints into source at offset 0x68.
// @fnv 0x00c90030
void FUN_00c90030_holder::FUN_00c90030(int aiState)
{
    FUN_00c90030_Matrix local00;
    FUN_00c90030_Matrix local24;

    if (unk10 != 0)
    {
        reinterpret_cast<::C817D0Cls *>(this)->UpdateNodeState(aiState);
    }
    else if (unk08 != 0)
    {
        reinterpret_cast<::NiAVObject *>((unk08))->UpdateWorldLoc();
    }

    FUN_00c90030_Source* source = unk08;
    FUN_00c90030_Outer* outer = source->unk18;

    void* result = outer->unk68.FUN_0043f8d0(&local24, reinterpret_cast<char*>(&source->unk34), &local00, &unk2C);

    FUN_00c90030_Result* resultObject = reinterpret_cast<FUN_00c90030_Result*>(result);

    void* matrix = resultObject->FUN_0043f8d0();

    memcpy(reinterpret_cast<char*>(&source->unk68), matrix, 9 * sizeof(int));
}

extern char DAT_010c6b0c[];

void* __cdecl NiMalloc(unsigned int size);

struct NiTLargeArrayStub
{
    void* m_vtbl;
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;

    NiTLargeArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_vtbl = &DAT_010c6b04;
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiMaxSize > 0)
            m_pBase = (void**)NiMalloc(sizeof(void*) * m_uiMaxSize);
        else
            m_pBase = 0;
    }
};

struct NiTLargePrimitiveArrayStub : NiTLargeArrayStub
{
    NiTLargePrimitiveArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTLargeArrayStub(uiMaxSize, uiGrowBy)
    {
        m_vtbl = DAT_010c6b0c;
    }
    ~NiTLargePrimitiveArrayStub();
};

struct BaseC9
{
    virtual void v00();
    int unk04[0xc];
    BaseC9();
    ~BaseC9();
};

struct FUN_00c9aeb0 : BaseC9
{
    int unk34;
    NiTLargePrimitiveArrayStub m_kArray;
    float unk50;
    float unk54;
    int unk58;

    virtual void v00();
    FUN_00c9aeb0();
};

// Initializes the FUN_00c9aeb0 object by zeroing unk34, setting unk50 and unk54 to -1.0f, and zeroing unk58.
// @fnv 0x00c9aeb0
FUN_00c9aeb0::FUN_00c9aeb0()
{
    unk34 = 0;
    unk50 = -1.0f;
    unk54 = -1.0f;
    unk58 = 0;
}


struct S00c81c50_Obj;
struct S00c81c50_Arr
{
    S00c81c50_Obj** data;
    unsigned short cap;
    unsigned short size;
    unsigned short esize;
    unsigned short grow;
    unsigned short GetSize() const
    {
        return size;
    }
    S00c81c50_Obj* GetAt(unsigned int i) const
    {
        return data[i];
    }
};

struct S00c81c50_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00c81c50_Obj* IsSceneNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S00c81c50_Obj* collision;
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
    S00c81c50_Arr children;


    __forceinline S00c81c50_Obj* GetCollision()
    {
        S00c81c50_Obj* c = collision;
        if (!c)
            return 0;
        return ((::S00c81c50_Obj *)(reinterpret_cast<::NiObject *>((c))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_01267e64))))));
    }
    __forceinline S00c81c50_Obj* FirstNode()
    {
        S00c81c50_Obj* c = children.size > 0 ? children.data[0] : 0;
        if (!c)
            return 0;
        return ((::S00c81c50_Obj *)(reinterpret_cast<::NiObject *>((c))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_011f4428))))));
    }
};

struct S00c81c50_Ptr
{
    S00c81c50_Obj* m_p;
    S00c81c50_Ptr(S00c81c50_Obj* p) : m_p(p)
    {}
    S00c81c50_Ptr& operator=(S00c81c50_Obj* p)
    {
        m_p = p;
        return *this;
    }
    operator S00c81c50_Obj*() const
    {
        return m_p;
    }
};

// Returns pkNode's collision object, else searches its first node, a child chosen by esize, and that child's children for one; returns null if none.
// @fnv 0x00c81c50
void* __cdecl FUN_00c81c50(S00c81c50_Obj* pkNode)
{
    S00c81c50_Ptr pkResult = 0;
    if (pkNode)
    {
        pkResult = pkNode->GetCollision();
        if (!pkResult)
        {
            S00c81c50_Obj* pkParent = pkNode;
            pkNode = pkParent->FirstNode();
            if (pkNode)
                pkResult = pkNode->GetCollision();
            if (!pkResult)
            {
                pkNode = pkParent->FirstNode();
                if (pkNode)
                    pkResult = pkNode->GetCollision();
            }
            if (!pkNode)
                pkNode = pkParent;
            if (!pkResult)
            {
                unsigned int idx = pkNode->children.esize != 1;
                if (pkNode->children.size > idx)
                {
                    pkNode = pkNode->children.data[idx];
                    if (pkNode)
                    {
                        pkResult = pkNode->GetCollision();
                        if (!pkResult)
                        {
                            S00c81c50_Obj* pkNodeNode = pkNode->IsSceneNode();
                            if (pkNodeNode)
                            {
                                for (unsigned int i = 0; i < pkNodeNode->children.GetSize(); i++)
                                {
                                    pkResult = pkNodeNode->children.data[i]->GetCollision();
                                    if (pkResult)
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return pkResult;
}

struct C8AB30_Sub
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98();
    virtual bool v9c(intptr_t a);
};

struct C8AB30_Mid
{
    int unk00;
    int unk04;
    int unk08;
    C8AB30_Sub* m_0c;
};

struct C8AB30_Ref
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    C8AB30_Mid* m_1c;
};

struct C8AB30_Cls
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98(), v9c();
    virtual void vA0();

    int unk04;
    C8AB30_Ref* m_08;

    bool FUN_00c8ab30(intptr_t a);
};

// For nonzero a, returns FUN_00c87a70(a) unless the sub-object's v9c(a) fails; for zero a, calls vA0() and returns false (requires this and m_08).
// @fnv 0x00c8ab30
bool C8AB30_Cls::FUN_00c8ab30(intptr_t a)
{
    TlsGuard_t kGuard;
    bool bResult = false;
    if (this != 0 && m_08 != 0)
    {
        if (a != 0)
        {
            C8AB30_Ref* pRef = m_08;
            _ReadWriteBarrier();
            C8AB30_Mid* pMid = pRef ? pRef->m_1c : 0;
            _ReadWriteBarrier();
            bool bSubOk = true;
            if (pMid != 0)
            {
                C8AB30_Sub* pSub = pMid->m_0c;
                if (pSub != 0)
                    bSubOk = pSub->v9c(a);
            }
            if (bSubOk)
                bResult = reinterpret_cast<::S00c87a70_Obj *>(this)->FUN_00c87a70((::Item *)(a));
        }
        else
        {
            vA0();
        }
    }
    return bResult;
}


struct Z577
{
    unsigned char index;
};

struct Y577
{
    unsigned char unk00[0xbd];
    Z577 z;
};

struct A577
{
    unsigned char unk00[0x19d];
    unsigned char unk19d;
};

struct S_00c8cd20_object
{
    unsigned int unk00;
    unsigned int unk04;
    A577* unk08;

    float GetFloatValue();
};

// Returns the DAT_010c7948 entry for a Z577's index (from the owner's FUN_00ca86c0 result, or a local one filled via FUN_00ca9360), else 0.0.
// @fnv 0x00c8cd20
float S_00c8cd20_object::GetFloatValue()
{
    volatile float ret;
    if (this && this->unk08)
    {
        A577* owner = this->unk08;
        Y577* result = ((::Y577 *)(reinterpret_cast<::FUN_00ca86c0_class *>((owner))->FUN_00ca86c0()));
        Z577* z;
        Z577 local_z;
        if (result)
        {
            z = &result->z;
        }
        else
        {
            ret = DAT_010c7948[owner->unk19d];
            reinterpret_cast<::FUN_00ca9360_cls *>(&(local_z))->FUN_00ca9360((float*)&ret);
            z = &local_z;
        }
        ret = DAT_010c7948[z->index];
        return ret;
    }
    ret = 0.0f;
    return ret;
}


struct S00c89ec0_Scope
{
    int saved;
    S00c89ec0_Scope()
    {
        saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~S00c89ec0_Scope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = saved;
    }
};

struct S00c89ec0_Res
{
};

struct S00c89ec0_Owner
{
    int unk00;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    S00c89ec0_Res* unk350;
    S00c89ec0_Res* GetRes()
    {
        return unk350;
    }
};

struct S00c89ec0_cls
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
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual S00c89ec0_Owner* getOwner();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void process(S00c89ec0_Res* r, int flag);
    int unk04;
    ::C68D50Entity* unk08;
    bool FUN_00c89ec0();
};

// Gets the owner's resource; if present, calls FUN_00c68d50 on it with unk08, then process(res, 0), and returns FUN_00c68d50's result, else false.
// @fnv 0x00c89ec0
bool S00c89ec0_cls::FUN_00c89ec0()
{
    S00c89ec0_Scope scope;
    S00c89ec0_Owner* owner = getOwner();
    S00c89ec0_Res* res = owner ? owner->GetRes() : 0;
    if (res)
    {
        bool r = reinterpret_cast<::C68D50World *>((res))->FUN_00c68d50(unk08);
        process(res, 0);
        return r;
    }
    return false;
}

__declspec(noinline) int FUN_00c84ec0(void* apObject);

struct ShareChildShape
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual bool V52(intptr_t a1);
};

struct ShareChildObject
{
    int unk0;
    int unk4;
    ShareChildShape* shape;
};

struct ShareChildEntry
{
    ShareChildObject* pObj;
    int unk4;
    int unk8;
    int unkC;
};

struct ShareListData : hkpListShapeStub
{
    int unk14;
    ShareChildEntry* arr;
};

class ListShapeSharingView : public bhkListShapeStub
{
  public:
    __forceinline ShareListData* GetNode()
    {
        return this != 0 ? (ShareListData*)m_pHavokObject : 0;
    }

    unsigned char FUN_00c8b440(intptr_t a1);
};

// Returns FUN_00c84ec0(a1) ANDed with V52(a1) of each non-null child shape in the list, stopping early once the result is zero.
// @fnv 0x00c8b440
unsigned char ListShapeSharingView::FUN_00c8b440(intptr_t a1)
{
    unsigned char result = (unsigned char)FUN_00c84ec0((void*)a1);
    while (true)
    {
        if (result == 0)
        {
            break;
        }
        int count;
        if (ShareListData* pNode = GetNode())
        {
            count = pNode->kContainer.GetNumChildShapes();
        }
        else
        {
            count = 0;
        }
        int i = 0;
        do
        {
            if (i >= count)
            {
                break;
            }
            if (ShareListData* pNode = GetNode())
            {
                ShareChildObject* pObj = pNode->arr[i].pObj;
                if (pObj != 0)
                {
                    ShareChildShape* q = pObj->shape;
                    if (q != 0)
                    {
                        result &= (unsigned char)q->V52(a1);
                    }
                }
            }
            i++;
        } while (result != 0);
        break;
    }
    return result;
}

struct c9b090_material
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float first, second;
};
struct c9b090_owner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    DynCastHelper* helper;
};
struct Target_c9b090
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
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual float compute(float);
    unsigned int unk04;
    unsigned short flags, unk0a;
    unsigned int unk0c, unk10, unk14;
    float time;
    unsigned int unk1c;
    float lastTime;
    unsigned int unk24, unk28;
    c9b090_owner* object;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    void* data;
    unsigned int unk4c;
    float savedFirst, savedSecond;
    bool IsActive() const
    {
        return (flags >> 3) & 1;
    }
    bool MustReset() const
    {
        return (flags >> 6) & 1;
    }
    void FUN_00c9b090(float* input);
};
// @fnv 0x00c9b090
void Target_c9b090::FUN_00c9b090(float* apTime)
{
    if (!object || !IsActive() || !data)
        return;
    if (object->helper)
    {
        c9b090_material* mat = (c9b090_material*)reinterpret_cast<::NiObject *>((object->helper))->DynamicCast((const ::NiRTTI *)(const unsigned int *)((unsigned int const*)&(*reinterpret_cast<int *>(&::g_01267e64))));
        if (mat)
        {
            float value = compute(*apTime);
            float first, second;
            if (((KeyPairInterpolator*)this)->Interpolate(value, first, second))
            {
                if (savedFirst < 0.0f)
                {
                    savedFirst = mat->first;
                    savedSecond = mat->second;
                }
                mat->first = first;
                mat->second = second;
            }
            if (value == time && (flags & 6) == 4)
            {
                if (MustReset())
                    ((FUN_00c9a820_class*)this)->Reset();
                ((S00c9ade0_Obj*)this)->FUN_00c9ade0();
                ((FUN_00c9abc0_cls*)this)->FUN_00c9abc0((intptr_t)mat);
                v90();
            }
            return;
        }
    }
    lastTime = *apTime;
}

void FUN_00c8cd00(void* apBlock);



int FUN_00c899c0(char* p, int edx);

// FUN_00c81570 : a one-line function - getter
void* FUN_00c81570();


ObjA* FUN_00c84880(ObjA* p1, ObjA* p2, ObjA* p3);

unsigned char* FUN_00c848b0(unsigned char* pResult, int a2, ChainNode* pChainA, ChainNode* pChainB, int a5,
                                      int a6);

unsigned char* FUN_00c84930(unsigned char* pResult, NodeA* pNodeA, NodeB* pNodeB);

void* __cdecl FUN_00c88370();

int* __cdecl FUN_00c88400();


extern GlobalObject g_global;

GlobalObject* __cdecl FUN_00c8a790();


CRITICAL_SECTION* __cdecl FUN_00c90820(void);

void* __cdecl FUN_00c99fe0();


// FUN_00c9add0 : a one-line function - getter
void* FUN_00c9add0();


unsigned char* CallAndStoreResult(unsigned char* output, FUN_00c84900_object* object, int unused,
                                            FUN_00c84900_vtbl* caller, unsigned int value);


void* __cdecl FUN_00c85620(FUN_00c85620_heap* pkHeap, unsigned int uiSize, unsigned int uiAlignment);

void __cdecl FUN_00c85800();

int* __cdecl FUN_00c87c80();

void __cdecl DispatchToTarget();

void __cdecl FUN_00c87fa0();

void FUN_00c896b0();

void* __cdecl FUN_00c8ff70();

void __cdecl FUN_00c8ff80(intptr_t param_1, intptr_t param_2);

void __cdecl FUN_00c8ff90();

void __cdecl FUN_00c8ffa0();

void __cdecl FUN_00c8ffb0();

bool __cdecl FUN_00c8ffc0(C815B0Constraint* pkOther);

void __cdecl FUN_00c90330();

void __cdecl FUN_00c90340();

int __cdecl FUN_00c90350();

int FUN_00c90e30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);


void FUN_00c910c0();

bool FUN_00c911c0();






void __cdecl FUN_00c9e3e0(void);




extern int DAT_0108ffb4;

struct FnvMat4
{
    __m128 m_uiX, m_uiY, m_uiZ, m_w;
};

struct ChildGroup;

struct Attachment;

struct DirectNode;

struct RuntimeObject
{

    virtual void v00();

    virtual void v01();

    virtual void v02();

    virtual ChildGroup* GetChildren();

    virtual void v04();

    virtual void v05();

    virtual void v06();

    virtual void v07();

    virtual int GetKind();

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

    virtual Attachment* GetAttachment();

    virtual void v38();

    virtual void Attach(unsigned);

    virtual void v40();

    virtual void v41();

    virtual void v42();

    virtual void v43();

    virtual void v44();

    virtual void v45();

    virtual void v46();

    virtual void v47();

    virtual void v48();

    virtual void v49();

    virtual void v50();

    virtual DirectNode* GetFirst();

    virtual DirectNode* GetSecond();

    virtual void v53();

    virtual void v54();

    virtual void v55();

    virtual void v56();

    virtual void v57();

    virtual void v58();

    virtual void v59();

    virtual void v60();

    virtual void GetMatrix(FnvMat4*);
};

struct Vec
{

    __m128 value;

    void FUN_00c7f640(const void*, const void*);
};

struct CastObject;

struct SceneObjectLocal : RuntimeObject
{

    int unk04, unk08, unk0c, unk10, unk14;

    SceneObjectLocal* unk18;

    CastObject* unk1c;

    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c,
        unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;

    float unk98;
};

struct Endpoint;

struct DirectNode
{
    int unk00, unk04;
    void* unk08;
    Endpoint* body;
    __forceinline void* GetOwner()
    {
        return unk08;
    }
};

struct AlternativeNode;

struct GraphicsObject : RuntimeObject
{

    int unk04;

    DirectNode* direct;
    __forceinline DirectNode* Gethk()
    {
        return direct;
    }

    AlternativeNode** alternate;

    __forceinline AlternativeNode* GetBody()
    {
        if (direct)
            return reinterpret_cast<AlternativeNode*>(direct->body);
        if (alternate)
            return *alternate;
        return 0;
    }
};

struct AlternativeNode : RuntimeObject
{

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c;

    __m128 position, unk60, unk70, unk80, rotation;

};

struct Endpoint : RuntimeObject
{

    int unk04;

    unsigned id;
};

struct CastObject
{
    int unk00, unk04, unk08, unk0c;
    void* body;
};

struct ResultData
{

    __m128 unk00, unk10, position, rotation;

    float unk40, distance;
};

struct Context
{

    void* vtable;

    ResultData* synthesized;

    unsigned type, firstId, secondId;



    __forceinline Context() : synthesized(0), type(1), firstId(0), secondId(0)
    {
        vtable = &DAT_010c5398;
    }

    ~Context()
    {
        vtable = &DAT_0108ffb4;
        reinterpret_cast<::C89AC0_Owner *>(this)->SetChildObject((::C89AC0_Child *)(0));
    }
};

void* __cdecl FUN_00aa13e0(unsigned);

struct FUN_00c7f9e0 : RuntimeObject
{

    long refs;

    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }

    void DecRefCount();

    unsigned unk08, unk0c;


    FUN_00c7f9e0(const Context&);
};

typedef FUN_00c7f9e0 Result;

struct ReleaseHandle
{
};

struct Handle
{
    Result* m_pObject;
    __forceinline Handle(Result* p) : m_pObject(p)
    {
        if (p)
            InterlockedIncrement(&p->refs);
    }
    __forceinline ~Handle()
    {
        reinterpret_cast<::FUN_0045cec0_Class *>((reinterpret_cast<ReleaseHandle*>(this)))->FUN_0045cec0();
    }
};

struct ListNode
{

    CastObject* item;

    ListNode* next;


};

struct Parent
{
    int unk00, unk04, unk08, unk0c, unk10;
    ListNode entries;
};

struct ChildGroup
{

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;

    SceneObjectLocal** children;

    unsigned short capacity, count;
};

struct Attachment
{

    unsigned unk000;

    unsigned unk004;

    unsigned unk008;

    unsigned unk00c;

    unsigned unk010;

    unsigned unk014;

    unsigned unk018;

    unsigned unk01c;

    unsigned unk020;

    unsigned unk024;

    unsigned unk028;

    unsigned unk02c;

    unsigned unk030;

    unsigned unk034;

    unsigned unk038;

    unsigned unk03c;

    unsigned unk040;

    unsigned unk044;

    unsigned unk048;

    unsigned unk04c;

    unsigned unk050;

    unsigned unk054;

    unsigned unk058;

    unsigned unk05c;

    unsigned unk060;

    unsigned unk064;

    unsigned unk068;

    unsigned unk06c;

    unsigned unk070;

    unsigned unk074;

    unsigned unk078;

    unsigned unk07c;

    unsigned unk080;

    unsigned unk084;

    unsigned unk088;

    unsigned unk08c;

    unsigned unk090;

    unsigned unk094;

    unsigned unk098;

    unsigned unk09c;

    unsigned unk0a0;

    unsigned unk0a4;

    unsigned unk0a8;

    unsigned unk0ac;

    unsigned unk0b0;

    unsigned unk0b4;

    unsigned unk0b8;

    unsigned unk0bc;

    unsigned unk0c0;

    unsigned unk0c4;

    unsigned unk0c8;

    unsigned unk0cc;

    unsigned unk0d0;

    unsigned unk0d4;

    unsigned unk0d8;

    unsigned unk0dc;

    unsigned unk0e0;

    unsigned unk0e4;

    unsigned unk0e8;

    unsigned unk0ec;

    unsigned unk0f0;

    unsigned unk0f4;

    unsigned unk0f8;

    unsigned unk0fc;

    unsigned unk100;

    unsigned unk104;

    unsigned unk108;

    unsigned unk10c;

    unsigned unk110;

    unsigned unk114;

    unsigned unk118;

    unsigned unk11c;

    unsigned unk120;

    unsigned unk124;

    unsigned unk128;

    unsigned unk12c;

    unsigned unk130;

    unsigned unk134;

    unsigned unk138;

    unsigned unk13c;

    unsigned unk140;

    unsigned unk144;

    unsigned unk148;

    unsigned unk14c;

    unsigned unk150;

    unsigned unk154;

    unsigned unk158;

    unsigned unk15c;

    unsigned unk160;

    unsigned unk164;

    unsigned unk168;

    unsigned unk16c;

    unsigned unk170;

    unsigned unk174;

    unsigned unk178;

    unsigned unk17c;

    unsigned unk180;

    unsigned unk184;

    unsigned unk188;

    unsigned unk18c;

    unsigned unk190;

    unsigned unk194;

    unsigned unk198;

    unsigned unk19c;

    unsigned unk1a0;

    unsigned unk1a4;

    unsigned unk1a8;

    unsigned unk1ac;

    unsigned unk1b0;

    unsigned unk1b4;

    unsigned unk1b8;

    unsigned unk1bc;

    unsigned unk1c0;

    unsigned unk1c4;

    unsigned unk1c8;

    unsigned unk1cc;

    unsigned unk1d0;

    unsigned unk1d4;

    unsigned unk1d8;

    unsigned unk1dc;

    unsigned unk1e0;

    unsigned unk1e4;

    unsigned unk1e8;

    unsigned unk1ec;

    unsigned unk1f0;

    unsigned unk1f4;

    unsigned unk1f8;

    unsigned unk1fc;

    unsigned unk200;

    unsigned unk204;

    unsigned unk208;

    unsigned unk20c;

    unsigned unk210;

    unsigned unk214;

    unsigned unk218;

    unsigned unk21c;

    unsigned unk220;

    unsigned unk224;

    unsigned unk228;

    unsigned unk22c;

    unsigned unk230;

    unsigned unk234;

    unsigned unk238;

    unsigned unk23c;

    unsigned unk240;

    unsigned unk244;

    unsigned unk248;

    unsigned unk24c;

    unsigned unk250;

    unsigned unk254;

    unsigned unk258;

    unsigned unk25c;

    unsigned unk260;

    unsigned unk264;

    unsigned unk268;

    unsigned unk26c;

    unsigned unk270;

    unsigned unk274;

    unsigned unk278;

    unsigned unk27c;

    unsigned unk280;

    unsigned unk284;

    unsigned unk288;

    unsigned unk28c;

    unsigned unk290;

    unsigned unk294;

    unsigned unk298;

    unsigned unk29c;

    unsigned unk2a0;

    unsigned unk2a4;

    unsigned unk2a8;

    unsigned unk2ac;

    unsigned unk2b0;

    unsigned unk2b4;

    unsigned unk2b8;

    unsigned unk2bc;

    unsigned unk2c0;

    unsigned unk2c4;

    unsigned unk2c8;

    unsigned unk2cc;

    unsigned unk2d0;

    unsigned unk2d4;

    unsigned unk2d8;

    unsigned unk2dc;

    unsigned unk2e0;

    unsigned unk2e4;

    unsigned unk2e8;

    unsigned unk2ec;

    unsigned unk2f0;

    unsigned unk2f4;

    unsigned unk2f8;

    unsigned unk2fc;

    unsigned unk300;

    unsigned unk304;

    unsigned unk308;

    unsigned unk30c;

    unsigned unk310;

    unsigned unk314;

    unsigned unk318;

    unsigned unk31c;

    unsigned unk320;

    unsigned unk324;

    unsigned unk328;

    unsigned unk32c;

    unsigned unk330;

    unsigned unk334;

    unsigned unk338;

    unsigned unk33c;

    unsigned unk340;

    unsigned unk344;

    unsigned unk348;

    unsigned unk34c;

    unsigned value;
};

static __forceinline int kind(AlternativeNode* p)
{
    return p->GetKind();
}

static __forceinline Endpoint* getFirst(GraphicsObject* p)
{
    DirectNode* d = p->GetFirst();
    return d ? d->body : 0;
}

static __forceinline Endpoint* getSecond(GraphicsObject* p)
{
    DirectNode* d = p->GetSecond();
    return d ? d->body : 0;
}

static __forceinline float length3(__m128 value)
{

    __m128 n = _mm_mul_ps(value, value);

    __m128 sq = _mm_shuffle_ps(n, n, 0x55);

    sq = _mm_add_ss(sq, n);

    n = _mm_shuffle_ps(n, n, 0xaa);

    n = _mm_add_ss(n, sq);

    float f;
    _mm_store_ss(&f, _mm_sqrt_ss(n));
    return f;
}

struct SceneModeGuard
{

    int m_saved;

    SceneModeGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~SceneModeGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

// @fnv 0x00c80ce0
void __cdecl FUN_00c80ce0(SceneObjectLocal* owner, int notification)
{

    SceneModeGuard mode;

    if (!owner || notification != 8)
        return;

    if (owner->unk1c)
    {

        CastObject* v = ((::CastObject *)(reinterpret_cast<::NiObject *>((owner->unk1c))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned int *>(&::g_012043f8))))));

        Parent* parent = v ? (Parent*)v->body : 0;

        if (parent)
        {

            ListNode* entries = &parent->entries;

            for (; entries && entries->item; entries = entries->next)
            {

                GraphicsObject* current = (GraphicsObject*)((::CastObject *)(reinterpret_cast<::NiObject *>((entries->item))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned int *>(&::g_0126818c))))));

                if (current != 0)
                {

                    Endpoint* first = 0;

                    Endpoint* context = 0;

                    Vec pos, rot;

                    switch (kind(current->GetBody()))
                    {

                    case 7: {

                        AlternativeNode* node = current->GetBody();

                        pos.value = node->position;
                        rot.value = node->rotation;

                        first = getFirst(current);
                        context = getSecond(current);

                        break;
                    }

                    case 2: {

                        AlternativeNode* node = current->GetBody();

                        pos.value = node->position;
                        rot.value = node->rotation;

                        first = getFirst(current);
                        context = getSecond(current);

                        break;
                    }

                    case 13: {

                        AlternativeNode* node = ((::AlternativeNode *)(reinterpret_cast<::MalleableGetterStandIn *>((current->GetBody()))->FUN_00cdf6c0()));

                        if (kind(node) == 7)
                        {

                            pos.value = node->position;
                            rot.value = node->rotation;

                            first = getFirst(current);
                            context = getSecond(current);
                        }

                        if (kind(node) == 2)
                        {

                            pos.value = node->position;
                            rot.value = node->rotation;

                            first = getFirst(current);
                            context = getSecond(current);
                        }

                        break;
                    }

                    default:
                        continue;
                    }

                    if (first && context)
                    {

                        Context second;

                        reinterpret_cast<::CC5AE0Owner *>(&(second))->EnsureHelperAllocated();

                        second.firstId = first->id;
                        second.secondId = context->id;

                        if (second.synthesized)
                        {
                            second.synthesized->position = pos.value;
                            second.synthesized->rotation = rot.value;
                        }

                        FnvMat4 firstRecord, secondRecord;

                        Vec transformedFirst, transformedSecond;

                        first->GetMatrix(&firstRecord);

                        context->GetMatrix(&secondRecord);

                        transformedFirst.FUN_00c7f640(&firstRecord, &pos);

                        transformedSecond.FUN_00c7f640(&secondRecord, &rot);

                        transformedFirst.value = _mm_sub_ps(transformedFirst.value, transformedSecond.value);

                        float distance = length3(transformedFirst.value);

                        if (distance == 0.0f)
                            distance = ::AngularDashpotApplyD4DCB0::DAT_01017d00;

                        if (second.synthesized)
                            second.synthesized->distance = distance;

                        Result* cast = new Result(second);

                        Attachment* attach = first->GetAttachment();

                        unsigned idx = attach ? attach->value : 0;
                        if (current->Gethk()->GetOwner())
                            ::FUN_00cdff60(current->Gethk(), (::ConstraintInput *)(void *)(current->Gethk()->GetOwner()));

                        if (entries->next)
                            reinterpret_cast<::RefOwner *>((entries->next))->FUN_00c80a30((int *)&(const ::Handle &)(cast));

                        else
                            reinterpret_cast<::ListNode0AA0 *>((entries))->FUN_00c80aa0((const ::NiPointer0AA0< ::RefObject0AA0> &)((const ::Handle &)(cast)));

                        if (cast)
                            cast->Attach(idx);
                    }
                }
            }
        }
    }

    ChildGroup* children = owner->GetChildren();

    if (children)
        for (unsigned i = 0; i < children->count; ++i)
            FUN_00c80ce0(children->children[i], 8);
}

namespace BlendTransformDetail {
struct VecLocal
{
    __m128 v;
    VecLocal& operator=(const VecLocal& b)
    {
        v = b.v;
        return *this;
    }
};
struct QuatLocal : VecLocal
{
    void FUN_00cb2850(const QuatLocal&, const QuatLocal&, float);
};
struct RotLocal
{
    VecLocal columns[3];
};
struct TransLocal
{
    RotLocal rotation;
    VecLocal position;
};
struct MatrixLocal
{
    float m[3][3];
};
struct SceneTransLocal
{
    MatrixLocal rotation;
    NiPoint3 position;
    float scale;
};
struct SceneLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    SceneTransLocal local, world;
};
struct BodyLocal
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void GetPosition(VecLocal&);
    virtual void GetRotation(QuatLocal&);

};
struct TargetLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int count;
};
struct LockLocal
{
    unsigned int owner, count;
    void Unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern float DAT_01267e6c;
extern __m128 DAT_010ec7f0;
struct BlendLocal
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
    virtual void Reset();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void Publish(SceneTransLocal*);

    int unk04;
    SceneLocal* scene;
    unsigned short flags, unk0e;
    BodyLocal* body;
    unsigned int unk14;
    float heirGain, velGain;
    unsigned int motion;
    TargetLocal* target;
    unsigned int unk28;
    void FUN_00c81e30();
};
struct TlsModeLocal
{
    int value;
};
struct TlsLocal : ThreadTlsBlock
{
    int unk2b8, unk2bc;
    TlsModeLocal mode;
};
inline TlsModeLocal& GetBlendMode()
{
    return ((TlsLocal*)&(*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)))->mode;
}
// @fnv 0x00c81e30
void BlendLocal::FUN_00c81e30()
{
    SceneLocal* node = scene;
    BodyLocal* rigid = body;
    bool forced = (flags & 0x100) != 0;
    float timestep = ::DAT_011afe64;
    unsigned int desiredMotion = 1;
    int mode;
    TlsModeLocal* tls;
    if (heirGain == 0.0f)
    {
        int state = GetBlendMode().value;
        tls = &GetBlendMode();
        if (state == 1)
        {
            reinterpret_cast<::NiAVObject *>((node))->UpdateWorldLoc();
            return;
        }
        mode = velGain == 0.0f || forced ? 1 : 0;
    }
    else if (heirGain == 1.0f)
    {
        tls = &GetBlendMode();
        mode = GetBlendMode().value == 2 ? 1 : 2;
        desiredMotion = 4;
    }
    else
    {
        tls = &GetBlendMode();
        mode = GetBlendMode().value == 2 ? 1 : 0;
    }
    bool changed = false;
    if (motion != desiredMotion)
    {
        if (motion == 4)
            Reset();
        else if (rigid)
        {
            reinterpret_cast<::S *>((rigid))->FUN_00561690((std::intptr_t)&((*reinterpret_cast<::BlendTransformDetail::VecLocal *>(&::DAT_01267e30))));
            reinterpret_cast<::fnv_005617c0::FUN_005617c0_ *>((rigid))->FUN_005617c0((std::intptr_t)&((*reinterpret_cast<::BlendTransformDetail::VecLocal *>(&::DAT_01267e30))));
        }
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::BlendTransformDetail::LockLocal *>(&::DAT_01267b80))))->FUN_0040fbf0(0);
        reinterpret_cast<::ColObj_c65f40 *>(this)->FUN_00c65f40(desiredMotion, (::NiObj_c65f40 *)(rigid), false);
        (*reinterpret_cast<::BlendTransformDetail::LockLocal *>(&::DAT_01267b80)).Unlock();
        motion = desiredMotion;
        changed = true;
    }
    switch (mode)
    {
    case 0: {
        reinterpret_cast<::NiAVObject *>((node))->UpdateWorldLoc();
        SceneTransLocal& world = node->world;
        NiPoint3& worldPosition = world.position;
        VecLocal position;
        position.v[0] = worldPosition.x * DAT_01267e6c;
        position.v[1] = worldPosition.y * DAT_01267e6c;
        position.v[2] = worldPosition.z * DAT_01267e6c;
        position.v[3] = 0.0f;
        RotLocal converted;
        ::VisitAndFetchThree((::FetcherC *)(::BlendTransformDetail::RotLocal *)(&converted), (::VisitorB *)(&world.rotation));
        QuatLocal desiredRotation;
        reinterpret_cast<::FUN_00827200_class *>(&(desiredRotation))->FUN_00cb26e0((intptr_t)&(converted));
        VecLocal currentPosition;
        rigid->GetPosition(currentPosition);
        QuatLocal currentRotation;
        rigid->GetRotation(currentRotation);
        VecLocal blendedPosition;
        float blend = heirGain;
        __m128 t = _mm_load_ss(&blend);
        t = _mm_shuffle_ps(t, t, 0);
        blendedPosition.v =
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), currentPosition.v), _mm_mul_ps(position.v, t));
        QuatLocal blendedRotation;
        blendedRotation.FUN_00cb2850(currentRotation, desiredRotation, heirGain);
        reinterpret_cast<::FUN_005611c0_t *>(&(blendedRotation))->FUN_005611c0();
        TransLocal output;
        output.position = forced ? blendedPosition : position;
        reinterpret_cast<::RotationRows *>(&(output.rotation))->FUN_00cb2d90((void *)&(blendedRotation));
        ::FUN_00624b10((::FUN_004769c0_shell *)(::BlendTransformDetail::MatrixLocal *)(&world.rotation), (::FUN_004b4cf0_shell *)(::BlendTransformDetail::RotLocal *)(&output.rotation));
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&worldPosition)), (*(const ::hkVector4 *)(&output.position)));
        if (tls->value == 0)
            Publish(&world);
        float inverseTimestep = timestep != 0.0f ? 1.0f / timestep : 1.0f;
        float gain = forced ? 1.0f : velGain;
        reinterpret_cast<::KFRigidBody *>((rigid))->FUN_00c8de20((const ::KFVector4 &)(blendedPosition), (const ::KFQuaternion &)(blendedRotation), inverseTimestep, gain);
        break;
    }
    case 1:
        reinterpret_cast<::CollObj *>(this)->FUN_00c65a80();
        break;
    case 2:
        Reset();
        break;
    }
    if (changed && target && target->count <= 0)
        reinterpret_cast<::FUN_00c81aa0_cls *>(this)->FUN_00c81aa0();
}
}

struct LayerGain
{
    float fHeir;
    float fVel;
};

struct HkObjBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct HkCollidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiFilterInfo;
};

struct HkWorldObj : HkObjBase, HkCollidable
{
};

struct WorldObj
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
    virtual void SetBlendTarget(int target);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual bool SetMotionType(int motion);

    int unk04;
    HkWorldObj* m_pkHkObj;
    int unk0C;
    unsigned int m_uiValue1;


    unsigned int GetFilterInfo()
    {
        HkCollidable* c = m_pkHkObj;
        return c ? c->m_uiFilterInfo : 0;
    }
    static bool IsBlendLayer(unsigned int uiInfo)
    {
        unsigned int uiLayer = uiInfo & 0x7f;
        return uiLayer == 8 || uiLayer == 0x1d;
    }
};

struct TimeCtrl
{
    int unk00;
    int unk04;
    unsigned short m_usFlags;
};

struct SceneObj
{
};

struct BlendCollObj
{
    int unk00;
    int unk04;
    SceneObj* m_pkSceneObject;
    unsigned short m_usFlags;
    unsigned short unk0E;
    WorldObj* m_spWorldObject;
    int unk14;
    float m_fHeirGain;
    float m_fVelGain;
    int m_iMotion;
    int m_iBlendTarget;

    void FUN_00c823b0(int iMotion, DynCastHelper* pkObj, bool bFlag);
};

// @fnv 0x00c823b0
void BlendCollObj::FUN_00c823b0(int iMotion, DynCastHelper* pkObj, bool bFlag)
{
    WorldObj* pkBody = pkObj == 0 ? 0 : (WorldObj*)reinterpret_cast<::NiObject *>((pkObj))->DynamicCast((const ::NiRTTI *)(const unsigned int *)((unsigned int const*)&(*reinterpret_cast<int *>(&::g_012681c0))));
    float fHeir = FUN_00c8cce0(&iMotion) ? 0.0f : 1.0f;
    float fVel = fHeir;
    if (pkBody || (pkBody = m_spWorldObject) != 0)
    {
        unsigned int uiInfo = pkBody->GetFilterInfo();
        if (WorldObj::IsBlendLayer(uiInfo))
        {
            unsigned int uiIdx = (uiInfo >> 8) & 0x1f;
            float fScale = (*reinterpret_cast<LayerGain (*)[]>(&::g_akC819A0Ranges))[uiIdx].fHeir;
            if (fScale > 1.0f)
            {
                fHeir = 1.0f;
                fVel = 1.0f;
            }
            else
            {
                fVel = (*reinterpret_cast<LayerGain (*)[]>(&::g_akC819A0Ranges))[uiIdx].fVel * fHeir;
                fHeir = fHeir * fScale;
            }
            m_usFlags &= 0xfdff;
            if (FUN_00c8cce0(&iMotion))
            {
                if (bFlag)
                {
                    HkWorldObj* pkHk = pkBody->m_pkHkObj;
                    if (pkHk)
                    {
                        ::FUN_00a29680();
                        reinterpret_cast<::hkpEntityC9C *>((pkHk))->FUN_00c9c1d0();
                        ::FUN_00a29680();
                    }
                }
                if (m_pkSceneObject)
                {
                    TimeCtrl* pkCtrl = ((::TimeCtrl *)(reinterpret_cast<::MyHost *>((m_pkSceneObject))->FUN_00a5c570((const ::MyRTTI *)(const int *)(&(*reinterpret_cast<int *>(&::g_012681f0))))));
                    if (pkCtrl)
                        pkCtrl->m_usFlags &= 0xfff7;
                }
            }
        }
        else if (!pkBody->SetMotionType(iMotion) && FUN_00c8cce0(&iMotion))
        {
            fHeir = 1.0f;
            fVel = 1.0f;
        }
    }
    m_fVelGain = fVel;
    m_fHeirGain = fHeir;
    if (m_iMotion != iMotion && !(bool)(m_usFlags >> 6 & 1) && !(bool)(pkBody->m_uiValue1 >> 6 & 1))
        reinterpret_cast<::E_T *>(this)->FUN_00c81890();
    reinterpret_cast<::A50Cls *>(this)->FUN_00c81a50();
    WorldObj* pkWorld = m_spWorldObject;
    if (pkWorld)
    {
        if (WorldObj::IsBlendLayer(pkWorld->GetFilterInfo()) && m_iBlendTarget)
            pkWorld->SetBlendTarget(m_iBlendTarget);
    }
}

struct PhysicsInfo
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
    unsigned char motionType;
};

struct PhysicsLink
{
    int unk00, unk04;
    PhysicsInfo* info;
};

struct SharedBody
{
    virtual void slot00();
    virtual void release();
    volatile long references;
    PhysicsInfo* info;
};

struct BodyReference
{
    SharedBody* body;
    BodyReference(SharedBody* value) : body(value)
    {
        if (body)
            InterlockedIncrement(&body->references);
    }
    ~BodyReference()
    {
        if (body)
        {
            if (InterlockedDecrement(&body->references) == 0)
                body->release();
        }
    }
};

struct Controller892 : TargetController
{
    virtual void slot90();
    virtual void slot94();
    virtual void setTarget(void*);
};

struct Scene892 : SceneObject
{
};

// @fnv 0x00c892c0
void Shape892::FUN_00c892c0(intptr_t arg0, intptr_t arg1, intptr_t arg2, Shape892* source, int arg4)
{
    TlsFlagGuard context;
    if (arg1 && arg2 && source)
    {
        flags |= 0x41;
        int value;
        const Shape892* settings = ((::Shape892 *)(reinterpret_cast<::NiObject *>((source))->DynamicCast((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_01267e64))))));
        if (settings)
        {
            scale18 = settings->scale18;
            scale1C = settings->scale1C;
            value = settings->values.first;
            values.first = value;
            value = settings->values.second;
            values.second = value;
            value = settings->mode;
            mode = value;
        }
        else
        {
            scale1C = scale18 = 1.0f;
            mode = 4;
        }
        BodyReference saved(source->body);
        reinterpret_cast<::FUN_00c6b980_cls *>((source))->FUN_00c6b980((::World_c6b *)(::SharedBody *)(0));
        Scene892* scene = source->scene;
        reinterpret_cast<::Owner62B *>((scene))->AttachTarget(this);
        reinterpret_cast<::FUN_00c6b980_cls *>(this)->FUN_00c6b980((::World_c6b *)(saved.body));
        FUN_00c89050(1, arg0, arg1, arg4);
        if (body)
        {
            int motion = body->info ? body->info->motionType : 5;
            if (FUN_00c8cce0(&motion))
            {
                scale1C = scale18 = 0.0f;
                mode = 1;
            }
        }
        Controller892* controller = static_cast<Controller892*>(((::TargetController *)(reinterpret_cast<::MyHost *>((scene))->FUN_00a5c570((const ::MyRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681f0)))))));
        if (!controller)
            controller = reinterpret_cast<Controller892*>(new FUN_00c9aeb0_t);
        controller->flags |= 8;
        controller->setTarget(scene);
    }
}

struct EventE610
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_pvSource;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    const void* m_pkPair;
    int unk4c;
    __m128 m_vContactPosition;
    __m128 m_vHitNormal;
};

class ListenerE610
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void OnEvent(EventE610& kEvent);
};

struct WorldE610
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
    ListenerE610* m_pkListener;
};

struct EntityE610
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    WorldE610* m_pkWorld;
};

struct PairE610
{
    int unk00;
    int unk04;
    EntityE610* m_apkEntities[2];
    char m_cEntityOffset;
    EntityE610* GetEntity() const
    {
        return *(EntityE610* const*)((const char*)m_apkEntities + m_cEntityOffset);
    }
};

// @fnv 0x00c9e610
void FUN_00c9e610(void* pvSource, const PairE610* pkPair, void* pvUnused)
{
    EventE610 kEvent;
    kEvent.m_pvSource = pvSource;
    kEvent.m_pkPair = pkPair;
    EntityE610* pkEntity = pkPair->GetEntity();
    WorldE610* pkWorld = pkEntity ? pkEntity->m_pkWorld : 0;
    pkWorld->m_pkListener->OnEvent(kEvent);
}

union __declspec(intrin_type) __declspec(align(16)) WaterLeaveVector
{
    struct
    {
        float x, y, z, w;
    };
    signed char bytes[16];
};

struct WaterLeaveListener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void OnEvent(void* pkEvent);
};

struct WaterLeaveUserWorld
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
    WaterLeaveListener* m_pkListener;
};

struct WaterLeavePhysicsWorld
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    WaterLeaveUserWorld* m_pkUserWorld;

    WaterLeaveUserWorld* WaterLeaveGetUserWorld() const
    {
        return m_pkUserWorld;
    }
};

struct WaterLeaveWorldObject
{
    void* vptr;
    int m_usMemSizeAndFlags;
    WaterLeavePhysicsWorld* m_pOwningWorld;
    struct UserObject
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0c;
        unsigned int m_uiValue1;
    }* m_ulUserData;
};

struct WaterLeaveCollidable
{
    void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    signed char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};

struct __declspec(align(16)) WaterLeaveContact
{
    WaterLeaveVector position;
    WaterLeaveVector separatingNormal;
    void* rootCollidableA;
    unsigned int shapeKeyA;
    unsigned int shapeKeysA[8];
    WaterLeaveCollidable* rootCollidableB;
    unsigned int shapeKeyB;
    unsigned int shapeKeysB[8];
};

inline WaterLeaveUserWorld* WaterLeaveGetUserWorld(WaterLeaveWorldObject* pkObject)
{
    WaterLeavePhysicsWorld* pkWorld = pkObject->m_pOwningWorld;
    return pkWorld ? pkWorld->WaterLeaveGetUserWorld() : 0;
}

// @fnv 0x00c9e670
void FUN_00c9e670(void* pArg, WaterLeaveCollidable* pkCollidable)
{
    WaterLeaveContact kEvent;
    kEvent.rootCollidableA = pArg;
    kEvent.rootCollidableB = pkCollidable;
    WaterLeaveUserWorld* pkWorld =
        WaterLeaveGetUserWorld(static_cast<WaterLeaveWorldObject*>(pkCollidable->getOwner()));
    if (pkWorld)
        pkWorld->m_pkListener->OnEvent(&kEvent);

    if (pkCollidable->m_cBroadPhaseType == 1)
    {
        WaterLeaveWorldObject* pkOwner = static_cast<WaterLeaveWorldObject*>(pkCollidable->getOwner());
        if (pkOwner)
        {
            WaterLeaveWorldObject::UserObject* pkUser = pkOwner->m_ulUserData;
            if (pkUser)
                pkUser->m_uiValue1 &= ~8u;
        }
    }
}

union __declspec(align(16)) NormalE700
{
    float components[4];
    unsigned char bytes[16];
};

struct BoolE700
{
    char m_cBooleanValue;
    BoolE700()
    {}
    BoolE700(bool b)
    {
        m_cBooleanValue = b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct RayInputE700;

struct RayOutputE700
{
    NormalE700 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_unk18;
    int m_unk1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    RayOutputE700() : m_fHitFraction(1.0f), m_iExtraInfo(-1)
    {
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

class ShapeE700
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
    virtual BoolE700 CastRay(const RayInputE700& kInput, RayOutputE700& kOutput) const;
};

struct ContainerShapeE700
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
    const ShapeE700* m_pkChild;
};

struct CdBodyE700;

struct ParentE700
{
    const ContainerShapeE700* m_pkShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pvMotion;
};

struct CdBodyE700
{
    const void* m_pkShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pvMotion;
    const ParentE700* m_pParentNode;
};

class RayHitCollectorE700
{
  public:
    virtual void AddRayHit(const CdBodyE700& kBody, const RayOutputE700& kOutput);
};

// @fnv 0x00c9e700
void FUN_00c9e700(const RayInputE700& kInput, const CdBodyE700& kBody, RayHitCollectorE700* pkCollector)
{
    ScopedMemoryCategory kScope;
    const ParentE700* pkParent = kBody.m_pParentNode;
    if (pkParent)
    {
        const ContainerShapeE700* pkShape = pkParent->m_pkShape;
        if (pkParent->m_pvMotion && pkShape && pkShape->m_type == 0x1b)
        {
            const ShapeE700* pkChild = pkShape->m_pkChild;
            if (pkChild)
            {
                RayOutputE700 kOutput;
                pkChild->CastRay(kInput, kOutput);
                if ((*(::BoolE700 *)(reinterpret_cast<::FUN_00632c60_Class *>((void *)&(kOutput))->FUN_00632c60({}))))
                    pkCollector->AddRayHit(kBody, kOutput);
            }
        }
    }
}

struct __declspec(align(16)) Vector482
{
    __m128 value;
};

struct Config482
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

    Vector482 inertia;

    unsigned unk60;

    unsigned unk64;

    unsigned unk68;

    unsigned unk6c;

    unsigned unk70;

    unsigned unk74;

    unsigned unk78;

    unsigned unk7c;

    Vector482 centerOfMass;

    float mass, linearDamping, angularDamping;

    unsigned unk9c, unka0, unka4;

    float maxLinearVelocity, maxAngularVelocity;

    unsigned unkb0, unkb4, unkb8, unkbc;
};

struct Info482
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Config482 config;
};

struct MotionInterface482
{

    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
    virtual void Method3();
    virtual void Method4();

    virtual void GetInertia(Vector482*);
};

struct Motion482 : MotionInterface482
{

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

    unsigned unk58;

    unsigned unk5c;

    unsigned unk60;

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

    Vector482 centerOfMass;

    unsigned unka0, unka4, unka8, unkac, unkb0;

    float linearDamping, angularDamping;

};

struct Collidable482
{
};

struct Body482
{

    unsigned unk00, unk04, unk08, unk0c;

    Collidable482 collidable;

    Collidable482* GetCollidable()
    {
        return &collidable;
    }


};

struct WrapperInterface482
{
    virtual void Method();
};

struct Wrapper482 : WrapperInterface482
{

    unsigned unk04;

    Body482* body;




    void FUN_00c8cfd0(Info482*);
};

// @fnv 0x00c8cfd0
void Wrapper482::FUN_00c8cfd0(Info482* info)
{

    reinterpret_cast<::Owner_00c85880 *>(this)->FillOutputFromState((::Out_00c85880 *)(info));

    if (body)
    {

        reinterpret_cast<::S_00ca8f50_Src *>((body))->WriteToInfo((::S_00ca8f50_Info *)(::Config482 *)(&info->config));

        Motion482* motion = body ? ((::Motion482 *)(reinterpret_cast<::FUN_00ca86c0_class *>((body))->FUN_00ca86c0())) : 0;

        if (motion)
        {

            info->config.mass = reinterpret_cast<::MotionMassView *>((motion))->FUN_00c86430();

            _mm_store_ps((float*)reinterpret_cast<unsigned char*>(&info->config.centerOfMass.value),
                                         _mm_load_ps((float*)reinterpret_cast<unsigned char*>(&motion->centerOfMass.value)));

            info->config.linearDamping = motion->linearDamping;

            info->config.angularDamping = motion->angularDamping;

            motion->GetInertia(&info->config.inertia);

            _mm_store_ps((float*)reinterpret_cast<unsigned char*>(&info->config.centerOfMass.value),
                                         _mm_load_ps((float*)reinterpret_cast<unsigned char*>(&motion->centerOfMass.value)));
        }

        if (body && body->GetCollidable())
        {

            info->config.maxLinearVelocity = reinterpret_cast<::Obj577 *>(this)->FUN_00577b50();

            info->config.maxAngularVelocity = reinterpret_cast<::S_00c8cd20_object *>(this)->GetFloatValue();
        }
    }
}

namespace WorldPositionDetail {

extern "C" double fabs(double);


struct WorldWrapAdjust : FUN_00c9a070_shell
{
    void AdjustVector(float*);
};

__declspec(noinline) void WorldWrapAdjust::AdjustVector(float* p)
{
    Adjust_00c9a070(p[0], p[0], fHi[0], fLo[0]);
    Adjust_00c9a070(p[1], p[1], fHi[1], fLo[1]);
    Adjust_00c9a070(p[2], p[2], fHi[2], fLo[2]);
}
struct PositionTarget
{
};

struct MotionBounds
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
    __m128 m_60;
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
    float m_b0[3];

    bool FUN_00c9a1f0(__m128* value);
};

// @fnv 0x00c9a1f0
bool MotionBounds::FUN_00c9a1f0(__m128* value)
{
    bool hit = false;
    __m128 base = m_60;
    __m128 input = *value;
    __m128 d = _mm_sub_ps(input, base);
    for (unsigned int i = 0; i < 3; ++i)
    {
        if (hit)
            break;
        float t = (float)fabs(((float*)&d)[i]);
        hit = (t >= m_b0[i]);
    }
    if (hit)
    {
        d = input;
        reinterpret_cast<::FUN_00c9a070_shell *>((((WorldWrapAdjust*)this)))->AdjustVector((float*)&d);
        __m128 diff = _mm_sub_ps(d, base);
        __m128 absdiff = _mm_and_ps(diff, (*reinterpret_cast<__m128 *>((void *)&::DAT_01017d10)));
        __m128 cmp = _mm_cmple_ps(absdiff, _mm_set_ps1(::fnv_00c88020::DAT_01016248));
        unsigned int mask = _mm_movemask_ps(cmp) & 7;
        bool result = mask != 7;
        if (result)
            reinterpret_cast<::ControllerC66 *>((((PositionTarget*)this)))->FUN_00c66c00((*(const ::hkVector4C66 *)((float*)&d)));
        hit = result;
    }
    return hit;
}

}

inline float multiplyValue(float a, float b)
{
    return a * b;
}

inline void multiplyRef(float& a, float b)
{
    a *= b;
}

class ScaleOwner
{
  public:
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

    float unk70;
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    float unk98;
    float unk9C;

    __m128 unkA0;
    float unkB0;

    void FUN_00c8cdf0(float scale);
};

// @fnv 0x00c8cdf0
void ScaleOwner::FUN_00c8cdf0(float scale)
{
    float scale3 = scale * scale * scale;

    unkA0 = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scale), _mm_load_ss(&scale), 0), unkA0);

    float* current = &unk80;
    unsigned int count = 3;

    do
    {
        current[-4] = (float)(scale3 * current[-4]);
        current[0] = current[0] * scale3;
        current[4] = current[4] * scale3;
        ++current;
    } while (--count);

    unkB0 = unkB0 * scale;
}

#include "generated/data/staging/blk_00c80000_o2.inc"
#include "generated/data/staging/blk_00c80000_o2_rtm_variant.inc"
