// gamebryo2.2/corelibs/nimain/nitristrips.cpp: NiTriStrips, Holder (10 functions)

#include <cstddef>
#include <new>
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/LineLoadEntry__LineReceiver.h"
#include "fnv/decl/NiLines.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00a9b000.h"
#include "fnv/symbols_0109c000.h"
#include "fnv/symbols_0109e000.h"
#include "fnv/symbols_010a1000.h"
#include "fnv/symbols_011f4000.h"
#include "nitristrips_decls.h"
// @fnv 0x00a89740
NiTriStrips::NiTriStrips()
{
    vtable = &::DAT_0109ed94;
}

struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FUN_00a71e00_shell : public NiTriStrips
{
    void GetTriangleVertices(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
};

struct _FakeTriData
{
    char pad[0x1c];
    NiPoint3* m_pkVertex;
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
    virtual void GetTriangleVertexIndices(unsigned short, unsigned short&, unsigned short&, unsigned short&);
};

// @fnv 0x00a71e00
void FUN_00a71e00_shell::GetTriangleVertices(unsigned short m_usTriangleID, NiPoint3** pkP0, NiPoint3** pkP1,
                                             NiPoint3** pkP2)
{
    _FakeTriData* pkModelData = *reinterpret_cast<_FakeTriData**>(reinterpret_cast<char*>(this) + 0xb8);
    NiPoint3* pkVertex = pkModelData->m_pkVertex;
    unsigned short usIndex0, usIndex1, usIndex2;
    pkModelData->GetTriangleVertexIndices(m_usTriangleID, usIndex0, usIndex1, usIndex2);
    *pkP0 = &pkVertex[usIndex0];
    *pkP1 = &pkVertex[usIndex1];
    *pkP2 = &pkVertex[usIndex2];
}


// @fnv 0x00a71d20
char const* const* __cdecl FUN_00a71d20()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f4a20));
}

struct NiGeometry
{
    NiGeometry(void);
};

struct NiParticleMeshes
{
};

struct BSFadeNode
{
};

// Allocates 0xc4 bytes, constructs a NiGeometry in place, sets its vtable to NiParticleMeshes::vftable, and returns the pointer or 0 on failure.
// @fnv 0x00a9b150
void* __cdecl FUN_00a9b150()
{
    void* pObject = ::operator new(0xc4);
    if (pObject)
    {
        NiGeometry* obj = static_cast<NiGeometry*>(pObject);
        obj->NiGeometry::NiGeometry();
        *reinterpret_cast<void**>(pObject) = &(*reinterpret_cast<const void * *>(&::DAT_010a11d4));
        return pObject;
    }
    return 0;
}

struct NiRenderer;
struct FUN_00a80610_shell
{
    void FUN_00a80610(NiRenderer*);
};
struct FUN_00a71d70_shell
{
    void FUN_00a71d70(NiRenderer*);
};
// Calls FUN_00a80610, then if the renderer's field at 0x200 is 1 or 2 and the byte at 0x208 is 1, invokes virtual slot 110 with this.
// @fnv 0x00a71d70
void FUN_00a71d70_shell::FUN_00a71d70(NiRenderer* apkRenderer)
{
    ((FUN_00a80610_shell*)this)->FUN_00a80610(apkRenderer);
    int i = *(int*)((char*)apkRenderer + 0x200);
    if ((i == 1 || i == 2) && *(char*)((char*)apkRenderer + 0x208) == 1)
    {
        void** vtbl = *(void***)apkRenderer;
        ((void(*)(NiRenderer*, void*))vtbl[110])(apkRenderer, this);
    }
}

struct StrArr
{
    char _0[8];
    unsigned short m8;
    unsigned short mA;
    char _C[2];
    unsigned short mE;
};
struct BaseA
{
};
struct Holder : BaseA
{
    void AppendString(StrArr*);
};
// Calls the base handler, then appends the string returned by _FUN_00a7d330 to pkStrings, growing it by mE when mA has reached m8.
// @fnv 0x00a71e70
void Holder::AppendString(StrArr* pkStrings)
{
    ::FUN_00a897c0((::TriGeomViewerDetail::EntryArray *)this);
    char* tmp = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f4a20)));
    unsigned int sz = pkStrings->mA;
    if (sz >= pkStrings->m8)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(sz + pkStrings->mE);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(sz, tmp);
}

namespace fnv_00a71d30 {
struct NiRenderer
{
    char _pad0[0x200];
    int m_iRendererState;
    char _pad1[4];
    unsigned char m_bRendererFlagA;
};
struct NiDX9Renderer : NiRenderer
{
};
struct FUN_00a80610_shell
{
};
struct FUN_00a71d30_shell
{
    void FUN_00a71d30(NiRenderer*);
};
// @fnv 0x00a71d30
void FUN_00a71d30_shell::FUN_00a71d30(NiRenderer* apkRenderer)
{
    NiDX9Renderer* pkRenderer = (NiDX9Renderer*)apkRenderer;
    reinterpret_cast<::FUN_00a80610_shell *>((((FUN_00a80610_shell*)this)))->FUN_00a80610((::NiRenderer *)(apkRenderer));
    if ((pkRenderer->m_iRendererState == 1 || pkRenderer->m_iRendererState == 2) && pkRenderer->m_bRendererFlagA == 1)
        ((void(**)(NiRenderer*, void*)) * (void***)pkRenderer)[108](pkRenderer, this);
}
}  // namespace fnv_00a71d30

void* __cdecl FUN_00aa13e0(unsigned int size);
struct NiTriStripsObject
{
    void* vtable;
    static void* operator new(std::size_t size, unsigned int extraBytes)
    {
        return FUN_00aa13e0(size + extraBytes);
    }
    NiTriStripsObject()
    {
        new ((void *)this) ::NiTriStrips();
        vtable = &(*reinterpret_cast<void * *>(&::DAT_0109cd44));
    }
};
struct FUN_00a71db0_class
{
    NiTriStripsObject* CreateTriStripsObject(int value);
};
// @fnv 0x00a71db0
NiTriStripsObject* FUN_00a71db0_class::CreateTriStripsObject(int value)
{
    NiTriStripsObject* strips = new (0xc0) NiTriStripsObject;
    ::FUN_00a9b140();
    return strips;
}


// @fnv 0x00a9b140
void __cdecl FUN_00a9b140()
{
    static_cast<::NiLines *>(nullptr)->CopyMemberData({}, *(::CloningProcess *)nullptr);
}

// @fnv 0x00a98ea0
void __cdecl FUN_00a98ea0()
{
    static_cast<::LineLoadEntry::LineReceiver *>(nullptr)->FUN_00a9b180(*(::LineLoadEntry::BinaryDataRecord *)nullptr);
}
