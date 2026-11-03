
// src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00a4be10
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/DataA38.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00ba87d0_Class.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiQuatTransform.h"
#include "fnv/decl/QXformViewer.h"
#include "fnv/decl/T.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a57000.h"
#include "fnv/symbols_00a72000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a88000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
void* __cdecl FUN_00a4be10()
{
    return &(*reinterpret_cast<void * *>(&::g_011f3f90));
}

struct NiLookAtInterpolator
{
    virtual ~NiLookAtInterpolator();
    void* __thiscall FUN_00a4c5c0(unsigned int flags);
};

extern "C" void __cdecl FUN_00a4be20();

// @fnv 0x00a4c5c0
void* __thiscall NiLookAtInterpolator::FUN_00a4c5c0(unsigned int flags)
{
    FUN_00a4be20();
    if (flags & 1)
    {
        ::FUN_00aa1460(this, 0x44);
    }
    return this;
}

class NiAVObject;
struct NiFixedString
{
    void* p;
};
struct NiAVObjectPalette
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34();
    virtual NiAVObject* FindAVObject(NiFixedString&);
};
struct Holder_00a4b8d0
{
    bool ResolveTargetObject(NiAVObjectPalette* pkPalette);
};
// @fnv 0x00a4b8d0
bool Holder_00a4b8d0::ResolveTargetObject(NiAVObjectPalette* pkPalette)
{
    if (*(NiAVObject**)((char*)this + 0x10))
        return true;
    NiAVObject* pkTarget = pkPalette->FindAVObject(*(NiFixedString*)((char*)this + 0x14));
    if (pkTarget)
    {
        *(NiAVObject**)((char*)this + 0x10) = pkTarget;
        return true;
    }
    return false;
}

struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93060
{
};
struct CloningProcess
{
    NiTStringPointerMap_00e93060* m_pCloneMap;
};
struct NiObject
{
    virtual void ProcessClone(CloningProcess&);
};
struct Host_00a4bb80
{
    void __thiscall FUN_00a4bb80(CloningProcess&);
};
// @fnv 0x00a4bb80
void __thiscall Host_00a4bb80::FUN_00a4bb80(CloningProcess& kCloning)
{
    bool bCloned;
    NiObject* pkClone;
    NiLookAtInterpolator* pkDest;
    reinterpret_cast<::FUN_00a5d430_Class *>((((NiObject*)this)))->FUN_00a5d430((unsigned int)&(kCloning));
    pkClone = 0;
    reinterpret_cast<::A54440Hash *>((kCloning.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)((char const*)this), (::A54440Manager **)&((ShaderBufferRecord*&)pkClone));
    pkDest = (NiLookAtInterpolator*)pkClone;
    bCloned = reinterpret_cast<::A54440Hash *>((kCloning.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)((char const*)*(void**)((char*)this + 0x10)), (::A54440Manager **)&((ShaderBufferRecord*&)pkClone));
    if (bCloned)
        *(void**)((char*)pkDest + 0x10) = pkClone;
    else
        *(void**)((char*)pkDest + 0x10) = *(void**)((char*)this + 0x10);
}

class NiObject;
struct NiStream
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void Register(void*);
public:
    ::NiObject *DeserializeObject();
};
struct ObjType
{
    virtual void G0();
    virtual void G1();
    virtual void G2();
    virtual void G3();
    virtual void G4();
    virtual void G5();
    virtual void G6();
    virtual void G7();
    virtual void G8();
    virtual void G9();
    virtual void G10();
    virtual void G11();
    virtual void G12();
    virtual void G13();
    virtual void G14();
    virtual void G15();
    virtual void G16();
    virtual void G17();
    virtual void G18();
    virtual void G19();
    virtual void G20();
    virtual bool RegisterStreamables(NiStream*);
};
struct BaseInterp
{
    bool __thiscall FUN_00a81fe0(NiStream*);
};
struct MyInterp
{
    bool __thiscall FUN_00a4bbe0(NiStream*);
};
// @fnv 0x00a4bbe0
bool __thiscall MyInterp::FUN_00a4bbe0(NiStream* kStream)
{
    unsigned int ui;
    if (!((BaseInterp*)this)->FUN_00a81fe0(kStream))
        return false;
    for (ui = 0; ui < 3; ++ui)
    {
        ObjType* pkObj = ((ObjType**)((char*)this + 0x38))[ui];
        if (pkObj)
        {
            if (!pkObj->RegisterStreamables(kStream))
                return false;
        }
    }
    kStream->Register((void*)((char*)this + 0x14));
    return true;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    void* __thiscall FUN_00a4bcf0(unsigned int a, unsigned int b, unsigned int c);
};
// @fnv 0x00a4c5a0
void* __cdecl FUN_00a4c5a0()
{
    void* p = BSFadeNode::operator new(0x44);
    if (p)
        return ((BSFadeNode*)p)->FUN_00a4bcf0(0, 0, 0);
    return 0;
}

struct FUN_00a4b900_V
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
};
struct FUN_00a4b900_Holder
{
    void FUN_00a4b900();
};
// Iterates three pointers starting at offset 0x38 and calls v47 on each non-null one.
// @fnv 0x00a4b900
void FUN_00a4b900_Holder::FUN_00a4b900()
{
    unsigned int ui;
    FUN_00a4b900_V** pp = (FUN_00a4b900_V**)((char*)this + 0x38);
    for (ui = 3; ui > 0; --ui)
    {
        FUN_00a4b900_V* p = *pp;
        if (p)
            p->v47();
        pp++;
    }
}

struct FakeInterp
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void SetActiveTimeRange(float, float);
};
struct Holder
{
    void __thiscall FUN_00a4b9f0(float m_fStartTime, float m_fMaximumDistance);
};
// Calls the two-float virtual method on each of the three FakeInterp pointers stored at offset 0x38, skipping null entries.
// @fnv 0x00a4b9f0
void __thiscall Holder::FUN_00a4b9f0(float afValue1, float afValue2)
{
    unsigned int ui;
    for (ui = 0; ui < 3; ui++)
    {
        FakeInterp* p = ((FakeInterp**)((char*)this + 0x38))[ui];
        if (p)
            p->SetActiveTimeRange(afValue1, afValue2);
    }
}

extern "C" const float g_01098b04;

struct FUN_00a4b930_item
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void GetRange(float* pMin, float* pMax);
};

struct FUN_00a4b930_cls
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
    FUN_00a4b930_item* m_pItems[3];

    void __thiscall GetItemsRange(float* pStart, float* pEnd);
};

// @fnv 0x00a4b930
void __thiscall FUN_00a4b930_cls::GetItemsRange(float* pfMin, float* pfMax)
{
    float a;
    float b;
    *pfMin = g_01098b04;
    *pfMax = ::DAT_01015f5c;
    FUN_00a4b930_item** pp = m_pItems;
    unsigned int n = 3;
    do
    {
        FUN_00a4b930_item* item = *pp;
        if (item != 0)
        {
            item->GetRange(&a, &b);
            if (a != b)
            {
                if (*pfMin > a)
                    *pfMin = a;
                if (*pfMax < b)
                    *pfMax = b;
            }
        }
        ++pp;
    } while (--n != 0);
    if (*pfMin == ::_DAT_010231b0 && *pfMax == ::DAT_010241b0)
    {
        *pfMin = 0.0f;
        *pfMax = 0.0f;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* pTarget);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* pTarget);

struct RegObj
{
    int m_i00;
    int m_i04;
    void* m_08;
};

struct FUN_00a4bae0_cls
{
    int m_i00;
    int m_i01;
    int m_i02;
    int m_i03;
    RegObj* m_pReg;
    void* m_hCur;
    bool FUN_00a4bae0();
};

// @fnv 0x00a4bae0
bool FUN_00a4bae0_cls::FUN_00a4bae0()
{
    RegObj* pRegObj = m_pReg;
    void* p = pRegObj->m_08;
    if (p != 0)
    {
        void* pNewHandle = ((void *)(::NiGlobalStringTable::AddString((const char *)(p))));
        long(__stdcall * pfnDecrement)(volatile long*) = InterlockedDecrement;
        if (m_hCur != pNewHandle)
        {
            if (pNewHandle != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
                (void)InterlockedIncrement((volatile long*)((char*)pNewHandle - 8));
            if (m_hCur != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
                (void)pfnDecrement((volatile long*)((char*)m_hCur - 8));
            m_hCur = pNewHandle;
        }
        if (pNewHandle != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            (void)pfnDecrement((volatile long*)((char*)pNewHandle - 8));
        m_pReg = 0;
        return true;
    }
    void* pFallbackHandle = (*reinterpret_cast<void * *>(&::DAT_011f49e0));
    if (m_hCur != pFallbackHandle)
    {
        if (pFallbackHandle != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            (void)InterlockedIncrement((volatile long*)((char*)pFallbackHandle - 8));
        if (m_hCur != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            (void)InterlockedDecrement((volatile long*)((char*)m_hCur - 8));
        m_hCur = pFallbackHandle;
    }
    return false;
}

class A4BC40Object
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
    virtual bool IsEqual(A4BC40Object* pkObject);
};

struct A4BC40Transform
{
    bool operator==(const A4BC40Transform& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class A4BC40Base : public A4BC40Object
{
  public:

    int unk04;
    int unk08;
};

class A4BC40Data : public A4BC40Base
{
  public:
    unsigned short m_usFlags;
    unsigned short unk0E;
    A4BC40Object* m_pkRotation;
    int unk14;
    A4BC40Transform m_kTransform;
    A4BC40Object* m_ppKeyData[3];

    bool FUN_00a4bc40(A4BC40Object* pkObject);
};

// @fnv 0x00a4bc40
bool A4BC40Data::FUN_00a4bc40(A4BC40Object* pkObject)
{
    if (!reinterpret_cast<::FUN_00ba87d0_Class *>(this)->FUN_00ba87d0((::NiObj_s *)(pkObject)))
        return false;

    A4BC40Data* pkData = (A4BC40Data*)pkObject;
    if (m_usFlags != pkData->m_usFlags)
        return false;

    if ((m_pkRotation && !pkData->m_pkRotation) || (!m_pkRotation && pkData->m_pkRotation))
        return false;
    if (m_pkRotation && pkData->m_pkRotation && !m_pkRotation->IsEqual(pkData->m_pkRotation))
        return false;

    if (!(reinterpret_cast<::T *>((void *)&(const ::A4BC40Transform &)(m_kTransform))->Equals((const ::T &)(pkData->m_kTransform))))
        return false;

    for (unsigned int i = 0; i < 3; i++)
    {
        A4BC40Object* pkKey = m_ppKeyData[i];
        A4BC40Object* pkOtherKey = pkData->m_ppKeyData[i];
        if ((pkKey && !pkOtherKey) || (!pkKey && pkOtherKey))
            return false;
        if (pkKey && pkOtherKey && !pkKey->IsEqual(pkOtherKey))
            return false;
    }
    return true;
}

struct Builder
{
    void FUN_00a4c4b0(BSFadeNode*, unsigned int);
    BSFadeNode* CreateFadeNode(unsigned int);
};
struct Arg_b9286
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m08;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short m0e;
};

struct Holder_b9286
{
};

struct Obj_b9286
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
    virtual void Visit(Arg_b9286* a);
};


struct FUN_00a4c780_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    Obj_b9286* m38;
    Obj_b9286* m3c;
    Obj_b9286* m40;


    void FUN_00a4c780(Arg_b9286* a);
};

// @fnv 0x00a4c780
void FUN_00a4c780_cls::FUN_00a4c780(Arg_b9286* a)
{
    ::FUN_00a570b0((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)this);
    void* p = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_011f3f90))))));
    unsigned int b = a->m0a;
    unsigned int c = a->m08;
    if (b >= c)
    {
        reinterpret_cast<::ViewerStrings *>((a))->SetSize((unsigned int)a->m0e + b);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((a))->SetAt(b, (*(char * *)(&p)));
    p = ((void *)(::FUN_00a7d5a0("m_pkLookAt", m10)));
    b = a->m0a;
    c = a->m08;
    if (b >= c)
    {
        reinterpret_cast<::ViewerStrings *>((a))->SetSize((unsigned int)a->m0e + b);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((a))->SetAt(b, (*(char * *)(&p)));
    reinterpret_cast<::QXformViewer *>((reinterpret_cast<Holder_b9286*>(&unk18)))->FUN_00a38cb0((::ViewerStrings *)(a));
    Obj_b9286** pp = &m38;
    for (unsigned int i = 3; i != 0; --i)
    {
        Obj_b9286* o = *pp;
        if (o)
        {
            o->Visit(a);
        }
        ++pp;
    }
}

namespace fnv_00eea6d0 {

struct NiFixedString
{
    char* m_kHandle;
};

struct NiLookAtInterpolator
{
    int _pad[5];
    NiFixedString m_kTargetNodeName;
    void FUN_00eea6d0(const NiFixedString& kName);
};

// Assigns kName's handle to the interpolator's name field, incrementing the new string's refcount and decrementing the old one's.
// @fnv 0x00eea6d0
void NiLookAtInterpolator::FUN_00eea6d0(const NiFixedString& kName)
{
    char* pcNewHandle = kName.m_kHandle;
    if (m_kTargetNodeName.m_kHandle != pcNewHandle)
    {
        if (pcNewHandle != ::DAT_0109b220)
            InterlockedIncrement((long*)(pcNewHandle - 8));
        char* pcOldHandle = m_kTargetNodeName.m_kHandle;
        if (pcOldHandle != ::DAT_0109b220)
            InterlockedDecrement((long*)(pcOldHandle - 8));
        m_kTargetNodeName.m_kHandle = pcNewHandle;
    }
}
}  // namespace fnv_00eea6d0

// LoadBinary: base interpolator data, flags, the linked object, the name, the transform and three linked interpolators.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class C630RefObject
{
  public:
    virtual void Unk00();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }

    long m_lRefCount;
};

template <class T> class C630Pointer
{
  public:
    C630Pointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    T* m_pObject;
};

class C630BinaryStream
{
  public:
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C630BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void C630LoadBinary(C630BinaryStream& kStream, T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&rValue, sizeof(T), &uiSize, 1);
}

class C630FixedString
{
  public:
    const char* m_pcHandle;
};

class C630Stream
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
    C630BinaryStream* m_pUnderlyingStream;

};

class C630Transform
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
};

class C630Interpolator
{
  public:
};

class C630Blend : public C630Interpolator
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0E;
    void* m_pkTarget;
    C630FixedString m_kName;
    C630Transform m_kTransform;
    C630Pointer<C630RefObject> m_akReferencedObjects[3];

    void FUN_00a4c630(C630Stream& kStream);
};

// Loads the blend from the stream: base interpolator data, flags, target, name (version-dependent), transform, and three ref objects.
// @fnv 0x00a4c630
void C630Blend::FUN_00a4c630(C630Stream& kStream)
{
    ::FUN_00a88a40();

    C630LoadBinary(*kStream.m_pUnderlyingStream, m_usFlags);
    m_pkTarget = ((void *)(reinterpret_cast<::NiStream *>(&(kStream))->DeserializeObject()));
    if (kStream.m_uiFileVersion < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kName));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kName));
    reinterpret_cast<::NiQuatTransform *>(&(m_kTransform))->LoadBinary((::NiStream &)(kStream));

    for (unsigned int i = 0; i < 3; i++)
        m_akReferencedObjects[i] = (C630RefObject*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->DeserializeObject()));
}

struct BinaryOutput341
{
    void* state;
    unsigned int position;
    void* read;
    unsigned int(__cdecl* write)(BinaryOutput341*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Write(const void* data, unsigned int length, unsigned int* sizes, unsigned int count)
    {
        unsigned int bytes = write(this, data, length, sizes, count);
        position += bytes;
        return bytes;
    }
};
template <class T> inline void SaveBinary341(BinaryOutput341& output, const T& value)
{
    unsigned int size = sizeof(T);
    output.Write(&value, sizeof(T), &size, 1);
}
struct Stream341
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
    virtual void SaveLink(void*);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    BinaryOutput341* output;
};
struct Transform341
{
    float translationX, translationY, translationZ;
    float rotationW, rotationX, rotationY, rotationZ;
    float scale;
};
struct Interpolator341
{
    virtual ~Interpolator341();
    unsigned int referenceCount;
    float lastTime;
};
struct LookAt341 : Interpolator341
{
    unsigned short flags, unk0e;
    void* target;
    const char* targetName;
    Transform341 transform;
    void* interpolators[3];
    void SaveToStream(Stream341* stream);
};
// Serializes the LookAt's flags, target link, target name, transform and three interpolator links to the stream.
// @fnv 0x00a4c700
void LookAt341::SaveToStream(Stream341* stream)
{
    ::FUN_00a724d0();
    SaveBinary341(*stream->output, flags);
    stream->SaveLink(target);
    reinterpret_cast<::FUN_00a641f0_cls *>((stream))->WriteObjectLink((void *)(&targetName));
    reinterpret_cast<::DataA38 *>(&(transform))->FUN_00a38b60((*(::NiStreamA38 *)(stream)));
    for (unsigned int i = 0; i < 3; ++i)
        stream->SaveLink(interpolators[i]);
}

#include <windows.h>
struct S_00a4ba30_Ref
{
    virtual void v00();
    virtual void v01();
    LONG unk04;
};

struct S_00a4ba30_Elem : S_00a4ba30_Ref
{
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
    virtual S_00a4ba30_Ref* v50(float a, float b);
};

struct S_00a4ba30_Ptr
{
    S_00a4ba30_Ref* m_p;
    operator S_00a4ba30_Elem*() const
    {
        return (S_00a4ba30_Elem*)m_p;
    }
    S_00a4ba30_Ptr& operator=(S_00a4ba30_Ref* p)
    {
        S_00a4ba30_Ref* old = m_p;
        if (old != p)
        {
            if (old)
            {
                if (!InterlockedDecrement(&old->unk04))
                    old->v01();
            }
            m_p = p;
            if (p)
                InterlockedIncrement(&p->unk04);
        }
        return *this;
    }
};

struct S_00a4ba30_Cls
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
    S_00a4ba30_Ptr unk38[3];
    S_00a4ba30_Cls* __thiscall FUN_00a4ba30(float a, float b);
};

// Calls FUN_00a57050 with the two floats, then assigns each non-null unk38[i] entry's v50 result to the corresponding entry in r.
// @fnv 0x00a4ba30
S_00a4ba30_Cls* __thiscall S_00a4ba30_Cls::FUN_00a4ba30(float a, float b)
{
    S_00a4ba30_Cls* pResult = ((::S_00a4ba30_Cls *)(::FUN_00a57050((int)this, a)));
    for (int i = 0; i < 3; i++)
    {
        if (unk38[i])
            pResult->unk38[i] = ((S_00a4ba30_Elem*)unk38[i])->v50(a, b);
    }
    return pResult;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);


struct RefObj
{
    virtual void Destroy();
    virtual void DeleteThis();
    long m_uiRefCount;
    inline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiInterpolator
{
    int unk04;
    int unk08;
    NiInterpolator();
    virtual void v0();
};

struct SmartPtr
{
    RefObj* m_pObject;
    SmartPtr(RefObj* p = 0)
    {
        if (p)
            m_pObject = p;
        else
            memset(&m_pObject, 0, sizeof(m_pObject));
    }
    SmartPtr& operator=(RefObj* p)
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
};

struct NiPoint3
{
    int x, y, z;
    NiPoint3() : x((*reinterpret_cast<int *>(&::DAT_011a8400))), y(DAT_011a8404), z(DAT_011a8408)
    {}
};

class ThreeByThreeMatrix;
struct NiQuaternion
{
    int w, x, y, z;
    NiQuaternion() : w((*reinterpret_cast<int *>(&::DAT_011f3704))), x(DAT_011f3708), y(DAT_011f370c), z(DAT_011f3710)
    {}
public:
    void FromRotationMatrix(const ::ThreeByThreeMatrix &);
};

struct FixedStr
{
    int p;
    FixedStr() : p((*reinterpret_cast<int *>(&::DAT_0109b220)))
    {}
};

struct FUN_00a4bcf0 : public NiInterpolator
{
    unsigned short m_uiObjectFlags;
    unsigned int m_pkLookAt;
    FixedStr m_kTargetNodeName;
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    SmartPtr m_akReferencedObjects[3];

    FUN_00a4bcf0(unsigned int pkLookAt, unsigned int eAxis, bool bFlip);
};
// @fnv 0x00a4c5e0
BSFadeNode* Builder::CreateFadeNode(unsigned int flags)
{
    BSFadeNode* allocated = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x44));
    BSFadeNode* node = allocated ? static_cast<BSFadeNode*>(((void *)(new ((void *)(allocated)) ::FUN_00a4bcf0(0, 0, 0)))) : 0;
    FUN_00a4c4b0(node, flags);
    return node;
}

// @fnv 0x00a4bcf0
FUN_00a4bcf0::FUN_00a4bcf0(unsigned int pkLookAt, unsigned int eAxis, bool bFlip)
    : m_uiObjectFlags(0), m_pkLookAt(pkLookAt), m_fScale(DAT_01096b8c)
{
    if (bFlip)
        m_uiObjectFlags |= 1;
    else
        m_uiObjectFlags &= 0xFFFE;
    m_uiObjectFlags = (m_uiObjectFlags & 0xFFF9) | (eAxis * 2);
    m_akReferencedObjects[0] = 0;
    m_akReferencedObjects[1] = 0;
    m_akReferencedObjects[2] = 0;
}

extern "C" void _ReadWriteBarrier(void);
const float DAT_01015f5c = -3.4028234663852886e38f;
const float DAT_01017d00 = 0.0010000000474974513f;
const float DAT_01098c00 = 1.0010000467300415f;
const double DAT_01098bf8 = 0.9990000128746033;
const float DAT_01098bf0 = -1.0010000467300415f;
const double DAT_01098be8 = -0.9990000128746033;
const double DAT_010241b0 = -3.4028234663852886e38;
struct LookNode;
struct LookVector
{
    float x, y, z;
    const float& GetX() const
    {
        return x;
    }
    const float& GetY() const
    {
        return y;
    }
    const float& GetZ() const
    {
        return z;
    }
    LookVector()
    {}
    LookVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    LookVector operator+(const LookVector& v) const
    {
        return LookVector(x + v.x, y + v.y, z + v.z);
    }
    LookVector operator-(const LookVector& v) const
    {
        LookVector result;
        result.x = x - v.x;
        result.y = y - v.y;
        result.z = z - v.z;
        return result;
    }
    LookVector operator-() const
    {
        return LookVector(-x, -y, -z);
    }
    LookVector operator*(float k) const
    {
        LookVector result;
        result.x = x * k;
        result.y = y * k;
        result.z = z * k;
        return result;
    }
    LookVector& operator-=(const LookVector& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    LookVector Cross(const LookVector& v) const
    {
        return LookVector(y * v.GetZ() - z * v.GetY(), z * v.GetX() - x * v.GetZ(), x * v.GetY() - y * v.GetX());
    }
};
struct LookMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    LookVector FUN_004b4500(const LookVector&) const;
    LookMatrix FUN_00a588a0(const LookMatrix&) const;
    LookMatrix FUN_0043f8d0(const LookMatrix&) const;
    void Identity()
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m10 = 0.0f;
        m12 = 0.0f;
        m20 = 0.0f;
        m21 = 0.0f;
        m11 = 1.0f;
        m22 = 1.0f;
    }
    void Column0(const LookVector& v)
    {
        m00 = v.x;
        m10 = v.y;
        m20 = v.z;
    }
    void Column1(const LookVector& v)
    {
        m01 = v.x;
        m11 = v.y;
        m21 = v.z;
    }
    void Column2(const LookVector& v)
    {
        m02 = v.x;
        m12 = v.y;
        m22 = v.z;
    }
};
struct LookQuaternion
{
    float w, x, y, z;
};
struct LookTransform
{
    LookVector translation;
    LookQuaternion rotation;
    float scale;
    void Invalid()
    {
        translation.x = DAT_01015f5c;
        rotation.x = DAT_01015f5c;
        scale = DAT_01015f5c;
    }
    bool IsInvalid() const
    {
        return scale == DAT_010241b0 && rotation.x == DAT_010241b0 && translation.x == DAT_010241b0;
    }
};
struct LookNode
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    LookNode* parent;
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
    LookVector localPosition;
    float localScale;
    LookMatrix worldRotation;
    LookVector worldPosition;
    float worldScale;
};
struct LookInterpolator
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual bool UpdateVector(float, LookNode*, LookVector&);
    virtual void Slot98();
    virtual bool UpdateFloat(float, LookNode*, float&);
};
struct LookAt
{
    int unk00, unk04;
    float lastTime;
    unsigned short flags;
    unsigned short unk0E;
    LookNode* target;
    int unk14;
    LookTransform value;
    LookInterpolator* translation;
    LookInterpolator* roll;
    LookInterpolator* scale;
    bool Update(float, LookNode*, LookTransform&);
};
// Computes the look-at transform for a node by calculating world position, orientation toward target, and optional roll/scale, storing the result in output.
// @fnv 0x00a4bec0
bool LookAt::Update(float time, LookNode* apNode, LookTransform& apTransform)
{
    if (!target)
    {
        apTransform.Invalid();
        value.Invalid();
        return false;
    }
    LookVector vTargetPosition = target->worldPosition;
    LookNode* parent = apNode->parent;
    LookVector localPosition;
    if (translation)
    {
        if (!translation->UpdateVector(time, apNode, localPosition))
        {
            value.Invalid();
            return false;
        }
        value.translation = localPosition;
    }
    else
        localPosition = apNode->localPosition;
    LookMatrix mParentRotation;
    LookVector worldPosition;
    if (parent)
    {
        mParentRotation = parent->worldRotation;
        float parentScale = parent->worldScale;
        worldPosition = parent->worldPosition + mParentRotation.FUN_004b4500(localPosition) * parentScale;
    }
    else
    {
        mParentRotation = (*reinterpret_cast<const ::LookMatrix *>(&::DAT_011a9448));
        worldPosition = localPosition;
    }
    LookVector vDirection = vTargetPosition - worldPosition;
    LookMatrix rotation;
    if (vDirection.SquaredLength() < DAT_01017d00)
        rotation.Identity();
    else
    {
        reinterpret_cast<::FUN_004a0c10_s *>(&(vDirection))->FUN_004a0c10();
        LookVector vUp;
        float projection;
        if ((vDirection.z < DAT_01098c00 && vDirection.z > DAT_01098bf8) ||
            (vDirection.z > DAT_01098bf0 && vDirection.z < DAT_01098be8))
        {
            vUp = (*reinterpret_cast<const ::LookVector *>(&::DAT_011a9478));
            projection = vDirection.y;
        }
        else
        {
            vUp = (*reinterpret_cast<const ::LookVector *>((void *)&::DAT_011a9484));
            projection = vDirection.z;
        }
        vUp -= vDirection * projection;
        reinterpret_cast<::FUN_004a0c10_s *>(&(vUp))->FUN_004a0c10();
        if (!bool(flags & 1))
            vDirection = -vDirection;

        LookVector vRight;
        vRight = vUp.Cross(vDirection);
        switch ((flags >> 1) & 3)
        {
        case 0:
            rotation.Column0(vDirection);
            rotation.Column1(vUp);
            rotation.Column2(-vRight);
            break;
        case 1:
            rotation.Column0(vRight);
            rotation.Column1(vDirection);
            rotation.Column2(-vUp);
            break;
        case 2:
            rotation.Column0(vRight);
            rotation.Column1(vUp);
            rotation.Column2(vDirection);
            break;
        }
        rotation = mParentRotation.FUN_00a588a0(rotation);
        if (roll)
        {
            float angle;
            if (!roll->UpdateFloat(time, apNode, angle))
            {
                value.Invalid();
                return false;
            }
            LookMatrix mRollRotation;
            reinterpret_cast<::FUN_004a0c90_shell *>(&(mRollRotation))->FUN_004a0c90(-angle);
            rotation = rotation.FUN_0043f8d0(mRollRotation);
        }
    }
    LookQuaternion qRotation;
    reinterpret_cast<::NiQuaternion *>(&(qRotation))->FromRotationMatrix((const ::ThreeByThreeMatrix &)(rotation));
    value.rotation = qRotation;
    _ReadWriteBarrier();
    if (scale)
    {
        float amount;
        if (!scale->UpdateFloat(time, apNode, amount))
        {
            value.Invalid();
            return false;
        }
        value.scale = amount;
    }
    if (value.IsInvalid())
    {
        apTransform.Invalid();
        return false;
    }
    apTransform = value;
    lastTime = time;
    return true;
}

namespace fnv_00a4c4b0 {

struct S_00a4c4b0_Ref
{
    virtual void vf0();
    virtual void vf1();
    long m_refs;
};
struct S_00a4c4b0_Ptr
{
    S_00a4c4b0_Ref* m_p;
    S_00a4c4b0_Ptr& operator=(S_00a4c4b0_Ref* p)
    {
        S_00a4c4b0_Ref* old = m_p;
        if (old != p)
        {
            if (old)
            {
                if (InterlockedDecrement(&old->m_refs) == 0)
                    old->vf1();
            }
            m_p = p;
            if (p)
                InterlockedIncrement(&p->m_refs);
        }
        return *this;
    }
};
union S_00a4c4b0_Flags
{
    unsigned short w;
    struct
    {
        unsigned short b0 : 1;
        unsigned short mid : 2;
        unsigned short rest : 13;
    } f;
};
struct S_00a4c4b0_Xform
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
struct S_00a4c4b0_Cloning;
struct S_00a4c4b0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00a4c4b0_Flags m_flags;
    int unk10;
    char* m_name;
    S_00a4c4b0_Xform m_kObjectTransform;
    S_00a4c4b0_Ptr m_ptr[3];
    void __thiscall FUN_00a4c4b0(S_00a4c4b0_Obj* dest, S_00a4c4b0_Cloning& c);
};
// Copies flags, unk10, m_name, m_kObjectTransform, and m_ptr entries from this object to dest after calling FUN_00aa1000.
// @fnv 0x00a4c4b0
void __thiscall S_00a4c4b0_Obj::FUN_00a4c4b0(S_00a4c4b0_Obj* dest, S_00a4c4b0_Cloning& c)
{
    ::FUN_00aa1000();
    unsigned int f = m_flags.w;
    dest->m_flags.w = f;
    dest->m_flags.w = (m_flags.w & 1) ? (f | 1) : (f & 0xfffe);
    {
        S_00a4c4b0_Flags* pDestFlags = &dest->m_flags;
        pDestFlags->f.mid = m_flags.f.mid;
    }
    dest->unk10 = unk10;
    char* s = (*reinterpret_cast<char * *>(&::DAT_011f49e0));
    if (dest->m_name != s)
    {
        if (s != ::DAT_0109b220)
            InterlockedIncrement((volatile LONG*)(s - 8));
        char* o = dest->m_name;
        if (o != ::DAT_0109b220)
            InterlockedDecrement((volatile LONG*)(o - 8));
        dest->m_name = s;
    }
    dest->m_kObjectTransform = m_kObjectTransform;
    for (int i = 0; i < 3; i++)
    {
        if (m_ptr[i].m_p)
            dest->m_ptr[i] = ((::fnv_00a4c4b0::S_00a4c4b0_Ref *)(reinterpret_cast<::CloneSourceA5d6 *>((m_ptr[i].m_p))->FUN_00a5d680()));
    }
}
}  // namespace fnv_00a4c4b0
