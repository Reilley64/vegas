// gamebryo2.2/corelibs/nimain/nitrishape.cpp: NiTriShape (16 functions)

#include "fnv/decl/FUN_00a98eb0_shell.h"
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a80610_shell.h"
#include "fnv/decl/FUN_00a89760_cls.h"
#include "fnv/decl/FUN_00a9b190.h"
#include "fnv/decl/FnvCpu_FUN_00a7b850_CpuObject.h"
#include "fnv/decl/ParticleLinkEndpoint.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00a9b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include "nitrishape_decls.h"

// @fnv 0x00A74410
NiTriShape::NiTriShape(unsigned short numVertices, NiPoint3* vertices, NiPoint3* normals, RgbaColor* colors,
                       NiPoint2* textures, unsigned short numTriangles, NiGeometryData__DataFlags dataFlags,
                       unsigned short sharedNormalsArraySize, unsigned short* m_kNavMeshTriangleList)
    : NiTriBasedGeom(new NiTriShapeData(numVertices, vertices, normals, colors, textures, numTriangles, dataFlags,
                                        sharedNormalsArraySize, m_kNavMeshTriangleList))
{}


struct FUN_00a74530_DelHelper : NiMemObject
{
};

// Calls FUN_00a89760 on pThis, frees pThis with operator delete when flags has bit 0 set, and returns pThis.
// @fnv 0x00a74530
void* DestroyNiTriShape(void* pThis, int, unsigned int flags)
{
    reinterpret_cast<::FUN_00a89760_cls *>((pThis))->FUN_00a89760_cls::~FUN_00a89760_cls();
    if (flags & 1)
        ::FUN_00aa1460(pThis, 0xc4);
    return pThis;
}

struct CloningProcess;
struct NiObject;
struct NiRenderer;
struct blob16
{
    char b[16];
};
struct BSScissorTriShape : public NiTriShape
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSScissorTriShape*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    void SetScissorRect(int, int, int, int);
    struct blob16 GetScissorRect();
    virtual void RenderImmediate(NiRenderer*);
    void __local_vftable_ctor_closure();
    char _pad_c4[44];
    char pDataToSerialize[16];
};
struct FUN_00a74600_shell : public NiTriShape
{
    void FUN_00a74600(NiRenderer*);
};

void FUN_00a80610();

// Calls FUN_00a80610 on this, then if the renderer's state at offset 0x200 is 1 or 2 and byte 0x208 is 1, invokes renderer vtable slot 0x1b4 with this.
// @fnv 0x00a74600
void FUN_00a74600_shell::FUN_00a74600(NiRenderer* apkRenderer)
{
    ((void(*)(NiTriShape*, NiRenderer*))FUN_00a80610)(this, apkRenderer);
    int state = *(int*)((char*)apkRenderer + 0x200);
    if ((state == 1 || state == 2) && *((char*)apkRenderer + 0x208) == 1)
    {
        ((void(*)(NiRenderer*, NiTriShape*))(*(void***)apkRenderer)[0x1b4 / 4])(apkRenderer, this);
    }
}

struct NiTriStrips
{
    NiTriStrips();
    virtual ~NiTriStrips();
    char pad[0xc0];
};
struct FUN_00a744a0 : NiTriStrips
{
    FUN_00a744a0();
    virtual ~FUN_00a744a0();
};
// @fnv 0x00a744a0
FUN_00a744a0::FUN_00a744a0()
{}

namespace fnv_00a744d0 {
struct BSFadeNode
{
};
struct NiTriStrips : BSFadeNode
{
    NiTriStrips() throw();
    virtual ~NiTriStrips() throw();
    char pad[0xc0];
};
struct NiTriShapeX : NiTriStrips
{
    NiTriShapeX() throw()
    {}
    virtual ~NiTriShapeX();
};
// Allocates and constructs a NiTriShapeX and returns it as a NiTriStrips pointer.
// @fnv 0x00a744d0
NiTriStrips* __cdecl CreateNiTriShapeX()
{
    return new NiTriShapeX;
}
}  // namespace fnv_00a744d0

// @fnv 0x00a74520
const char* __cdecl FUN_00a74520()
{
    return (*reinterpret_cast<const char (*)[]>(&::g_011f4a40));
}

namespace fnv_00a74560 {
struct CloningProcess;
struct NiObject;
struct NiRenderer;
struct NiStream;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct BSResizableTriShape : public NiTriShape
{
    virtual void __vslot_0();
    virtual void SetLocalBound(struct blob16);
    virtual void* GetBoundingVolume();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSResizableTriShape*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    void SetNumPrimitives(unsigned int);
    unsigned int GetNumPrimitives();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual void RenderImmediate(NiRenderer*);
    virtual void RenderWithRenderer(NiRenderer*);
    virtual void UpdateWorldBound();
    void __local_vftable_ctor_closure();
    char _pad_c4[44];
    unsigned int m_uiValueBeforeLocalBound;
    char LocalBound[16];
    char _pad_104[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
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
struct FUN_00a74560_shell : public NiTriShape
{
    void GetTriangleVertices(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
};

struct TriListHelper
{
};
// @fnv 0x00a74560
void FUN_00a74560_shell::GetTriangleVertices(unsigned short ausTriangleIndex, NiPoint3** pkP0, NiPoint3** pkP1,
                                             NiPoint3** pkP2)
{
    NiTriShapeData* pkModelData = *(NiTriShapeData**)((char*)this + 0xb8);
    NiPoint3* pkVertex = *(NiPoint3**)((char*)pkModelData + 0x20);
    unsigned short* pusTriList = ((unsigned short *)(reinterpret_cast<::FnvCpu_FUN_00a7b850_CpuObject *>((((TriListHelper*)pkModelData)))->FUN_00a7b850()));
    unsigned short usIndexOffset = ausTriangleIndex * 3;
    *pkP0 = &pkVertex[pusTriList[usIndexOffset++]];
    *pkP1 = &pkVertex[pusTriList[usIndexOffset++]];
    *pkP2 = &pkVertex[pusTriList[usIndexOffset++]];
}
}  // namespace fnv_00a74560

namespace fnv_00a74640 {
struct BSFadeNode
{
};
struct NiTriStrips : BSFadeNode
{
    NiTriStrips() throw();
    virtual ~NiTriStrips();
    char pad[0xc0];
};
struct NiTriShapeX : NiTriStrips
{
    NiTriShapeX() throw()
    {}
    virtual ~NiTriShapeX();
};
struct CloningProcess;
struct FUN_00a74640
{
    NiTriStrips* Clone(CloningProcess& kCloning);
};
// @fnv 0x00a74640
NiTriStrips* FUN_00a74640::Clone(CloningProcess& kCloning)
{
    NiTriStrips* pkClone = new NiTriShapeX;
    ::FUN_00a9b140();
    return pkClone;
}
}  // namespace fnv_00a74640

struct FUN_00a804e0
{
    FUN_00a804e0(void* a);
    virtual ~FUN_00a804e0();
};
struct FUN_00a89720 : FUN_00a804e0
{
    FUN_00a89720(void* a);
    virtual ~FUN_00a89720();
};
// @fnv 0x00a89720
FUN_00a89720::FUN_00a89720(void* a) : FUN_00a804e0(a)
{}

struct FUN_00a80610_This
{
};
struct FUN_00a745c0_This
{
    void FUN_00a745c0(void*);
};
// Calls FUN_00a80610 on the renderer, then if renderer state at 0x200 is 1 or 2 and byte at 0x208 is 1, invokes vtable slot 107 with this.
// @fnv 0x00a745c0
void FUN_00a745c0_This::FUN_00a745c0(void* apkRenderer)
{
    void* pkRenderer = apkRenderer;
    reinterpret_cast<::FUN_00a80610_shell *>((((FUN_00a80610_This*)this)))->FUN_00a80610((::NiRenderer *)(pkRenderer));
    if ((*(int*)((char*)pkRenderer + 0x200) == 1 || *(int*)((char*)pkRenderer + 0x200) == 2) &&
        *(char*)((char*)pkRenderer + 0x208) == 1)
    {
        ((void(**)(void*, void*))(*(void***)pkRenderer))[107](pkRenderer, this);
    }
}

namespace fnv_00a74690 {
struct StrArr
{
};
struct BaseA
{
};
struct FUN_00a74690_shell : BaseA
{
    void FUN_00a74690(StrArr* pkStrings);
};
// Calls the base handler, resolves g_011f5b34_arg1 to a string, grows pkStrings if its index reached the size, then stores the string at that index.
// @fnv 0x00a74690
void FUN_00a74690_shell::FUN_00a74690(StrArr* pkStrings)
{
    ::FUN_00a897c0((::TriGeomViewerDetail::EntryArray *)this);
    char* pStr = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f4a40)));
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)pkStrings + 8))
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiIndex + *(unsigned short*)((char*)pkStrings + 0xe));
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, pStr);
}
}  // namespace fnv_00a74690

struct FUN_00a74480 : public NiTriBasedGeom
{
    explicit FUN_00a74480(NiTriBasedGeomData* geometry);
    virtual ~FUN_00a74480();
};
// @fnv 0x00a74480
FUN_00a74480::FUN_00a74480(NiTriBasedGeomData* geometry) : NiTriBasedGeom(geometry)
{}


// @fnv 0x00a744c0
void __cdecl FUN_00a744c0()
{
    FUN_00a9b140();
}

// @fnv 0x00a74500
void FUN_00a74500()
{
    static_cast<struct ::FUN_00a9b190 *>(nullptr)->FUN_00a9b190_Impl(*(::NiStream *)nullptr);
}

// @fnv 0x00a74510
void FUN_00a74510()
{
    FUN_00a89770();
}

class NiStream;


// @fnv 0x00a98eb0
void FUN_00a98eb0_shell::FUN_00a98eb0(NiStream& stream)
{
    reinterpret_cast<::ParticleLinkEndpoint *>(this)->FUN_00a74780(stream);
}


// @fnv 0x00a71d10
void __cdecl FUN_00a71d10()
{
    FUN_00a9b1a0();
}


class NiTriGeom2
{
  public:
    void FUN_0051d000(unsigned short a);
    void FUN_0051d020(unsigned short a, unsigned short b, unsigned short c);
};

// @fnv 0x0051d000
void NiTriGeom2::FUN_0051d000(unsigned short a)
{
    reinterpret_cast<::NiTriBasedGeom *>((this))->SetBitfield(a, 7, 0);
}

void NiTriGeom2::FUN_0051d020(unsigned short a, unsigned short b, unsigned short c)
{
    (void)a;
    (void)b;
    (void)c;
}
