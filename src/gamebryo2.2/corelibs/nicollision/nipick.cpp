// gamebryo2.2/corelibs/nicollision/nipick.cpp: Results, NiPick (10 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S_00e98aa0_Holder.h"
#include "fnv/decl/SphereBVLite.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a63000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00e9c000.h"
#include "fnv/symbols_00e9d000.h"
#include "fnv/symbols_00e9e000.h"
#include "fnv/symbols_00e9f000.h"
#include "fnv/symbols_00ea0000.h"
#include "fnv/symbols_00ea2000.h"
#include "fnv/symbols_00ea3000.h"
#include "fnv/symbols_00ea7000.h"
#include "fnv/symbols_00eab000.h"
#include "fnv/symbols_00eac000.h"
#include "fnv/symbols_00ead000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "nipick_decls.h"

// @fnv 0x00e98b40
void NiPick::Results::InvokeCallbacks()
{
    for (unsigned int i = 0; i < m_uiValidCount; ++i)
    {
        Record* record = GetAt(i);
        for (unsigned int j = i + 1; j < m_uiValidCount; ++j)
        {
            Record* other = GetAt(j);
            if (other->m_fHitDistance < record->m_fHitDistance)
            {
                SetAt(j, record);
                SetAt(i, other);
                record = other;
            }
        }
    }
}

// Destructor for NiPick that calls Clear on the object's member.
// @fnv 0x00e98fa0
NiPick::~NiPick()
{
    m_kResults.Clear();
}

// Releases each record's two referenced objects, deallocates the records, then frees the base array.
// @fnv 0x00e98e90
void NiPick::Results::Clear() throw()
{
    m_ppVirtualMethodTable = DAT_010f16ec;
    for (unsigned int i = 0; i < m_usSize; ++i)
    {
        Record* record = m_pBase[i];
        if (record)
        {
            if (record->m_pParentNode.m_pObject)
                record->m_pParentNode.m_pObject->DecRefCount();
            if (record->m_pReferencedObject.m_pObject)
                record->m_pReferencedObject.m_pObject->DecRefCount();
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(record);
        }
    }
    m_ppVirtualMethodTable = DAT_010f16dc;
    ::FUN_00aa10f0(m_pBase);
}

struct FUN_00e98fd0_shell : NiPick::Results
{
    void* DestroyResults(bool free);
};

// Calls Clear, then frees this object through g_memoryManager when free is set, and returns this.
// @fnv 0x00e98fd0
void* FUN_00e98fd0_shell::DestroyResults(bool free)
{
    Clear();
    if (free & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

extern int DAT_0126fa60;
void __cdecl InitNiStreamCallbacks();
void __cdecl FUN_00e99260();

struct FUN_00e99300_shell
{
    void* __thiscall FUN_00e99300();
};

// Increments DAT_0126fa60 and, when the previous value was zero, registers InitNiStreamCallbacks and FUN_00e99260 via FUN_00aa2080; returns this.
// @fnv 0x00e99300
void* __thiscall FUN_00e99300_shell::FUN_00e99300()
{
    void* result = this;
    int iPreviousCount = DAT_0126fa60;
    DAT_0126fa60 = DAT_0126fa60 + 1;
    if (iPreviousCount == 0)
        ::FUN_00aa2080((void (*)())(void *)((void*)InitNiStreamCallbacks), (int)((void*)FUN_00e99260));
    return result;
}

struct NiObject;
struct NiStream
{
    static int __cdecl RegisterObjectLoader(const char*, NiObject*(__cdecl*)(void));
};
typedef void(__cdecl* PFN)();
extern const char g_0126fab4_arg0[];
int* __cdecl FUN_00e9c7d0(float, int*);
struct Obj;
Obj* __cdecl FUN_00e9c800(float, int*);
struct D_00e9e980;
bool __cdecl FUN_00e9e980(float, D_00e9e980*, void*, void*, void*);
struct NiStream;
struct FUN_00eac170_Ret;
FUN_00eac170_Ret* __cdecl FUN_00eac170(NiStream&);
extern bool DAT_0126fa5c;
extern PFN DAT_0126fa7c;
extern PFN DAT_0126fa80;
extern PFN DAT_0126fa84;
extern PFN DAT_0126fa88;
extern PFN DAT_0126fa8c;
extern PFN DAT_0126fa90;
extern PFN DAT_0126faa4;
extern PFN DAT_0126faa8;
extern PFN DAT_0126faac;

// @fnv 0x00e98ff0
void __cdecl InitNiStreamCallbacks()
{
    if (DAT_0126fa5c)
        return;
    DAT_0126fa5c = true;
    NiStream::RegisterObjectLoader(g_0126fab4_arg0, ((NiObject *(&)())::sead090::FUN_00ead090));
    DAT_0126fa80 = ((void (&)())::FUN_00ea7490);
    DAT_0126fa84 = ((void (&)())::fnv_00ea04b0::CreateObjWithArg);
    DAT_0126fa90 = ((void (&)())::CreateBoundingVolumeAndCall);
    DAT_0126fa88 = ((void (&)())::ReadObjB0);
    DAT_0126fa7c = (PFN)FUN_00eac170;
    DAT_0126fa8c = ((void (&)())::FUN_00e9efe0);

    PFN* a = (PFN*)::FUN_00aa1070(0x90);
    a[0] = ((void (&)())::SphereBVLite::CheckSweptSphereOverlap);
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = ((void (&)())::fnv_00ea7530::IntersectsSphereAndBox);
    a[7] = ((void (&)())::FUN_00ea0ad0);
    a[8] = ((void (&)())::fnv_00ea2030::FUN_00ea2030);
    a[9] = 0;
    a[10] = 0;
    a[11] = 0;
    a[12] = ((void (&)())::SweepSphereAgainstCapsule);
    a[13] = 0;
    a[14] = ((void (&)())::IsCapsuleSweptHit);
    a[15] = 0;
    a[16] = 0;
    a[17] = 0;
    a[18] = 0;
    a[19] = 0;
    a[20] = 0;
    a[21] = 0;
    a[22] = 0;
    a[23] = 0;
    a[24] = (PFN)FUN_00e9e980;
    a[25] = (PFN)FUN_00e9e980;
    a[26] = (PFN)FUN_00e9e980;
    a[27] = 0;
    a[28] = ((void (&)())::FindMatchingItemPair);
    a[29] = (PFN)FUN_00e9e980;
    a[30] = ((void (&)())::FUN_00e9cd10);
    a[31] = ((void (&)())::fnv_00e9cde0::IsIntersectingFogPlane);
    a[32] = ((void (&)())::FUN_00e9cf50);
    a[33] = 0;
    a[34] = 0;
    a[35] = ((void (&)())::FUN_00e9d070);

    PFN* b = (PFN*)::FUN_00aa1070(0x90);
    b[0] = ((void (&)())::IntersectSpheres);
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    b[5] = 0;
    b[6] = ((void (&)())::FUN_00ea3950);
    b[7] = ((void (&)())::FUN_00ea7d40);
    b[8] = ((void (&)())::FUN_00ea3c50);
    b[9] = 0;
    b[10] = 0;
    b[11] = 0;
    b[12] = ((void (&)())::FUN_00e9f400);
    b[13] = 0;
    b[14] = ((void (&)())::FUN_00e9f510);
    b[15] = 0;
    b[16] = 0;
    b[17] = 0;
    b[18] = 0;
    b[19] = 0;
    b[20] = 0;
    b[21] = 0;
    b[22] = 0;
    b[23] = 0;
    b[24] = ((void (&)())::FindItemByPredicate);
    b[25] = ((void (&)())::FindItemByPredicate);
    b[26] = ((void (&)())::FindItemByPredicate);
    b[27] = ((void (&)())::FindItemByPredicate);
    b[28] = ((void (&)())::FindMatchingPair);
    b[29] = ((void (&)())::FindItemByPredicate);
    b[30] = ((void (&)())::FUN_00e9d2c0);
    b[31] = ((void (&)())::FUN_00e9d540);
    b[32] = ((void (&)())::SweepCapsuleAgainstHalf);
    b[33] = 0;
    b[34] = 0;
    b[35] = ((void (&)())::IntersectPlanes);

    PFN* pTableC = (PFN*)::FUN_00aa1070(0x18);
    pTableC[0] = ((void (&)())::SphereTriangleSweepTest);
    pTableC[1] = ((void (&)())::IntersectsTriangle);
    pTableC[2] = ((void (&)())::CapsuleTriangleIntersect);
    pTableC[3] = 0;
    pTableC[4] = ((void (&)())::FUN_00e9ea70);
    pTableC[5] = ((void (&)())::FUN_00e9d150);

    PFN* pTableD = (PFN*)::FUN_00aa1070(0x18);
    pTableD[0] = ((void (&)())::SphereTriangleCollision);
    pTableD[1] = ((void (&)())::FUN_00ea3d60);
    pTableD[2] = ((void (&)())::fnv_00e9fdc0::FUN_00e9fdc0);
    pTableD[3] = 0;
    pTableD[4] = ((void (&)())::FUN_00e9ec10);
    pTableD[5] = ((void (&)())::FUN_00e9e2c0);

    (*reinterpret_cast<void (***)()>(&::DAT_0126fa94)) = a;
    (*reinterpret_cast<void (***)()>(&::DAT_0126fa98)) = b;
    (*reinterpret_cast<void (***)()>(&::DAT_0126fa9c)) = pTableC;
    (*reinterpret_cast<void (***)()>(&::DAT_0126faa0)) = pTableD;
    DAT_0126faa4 = (PFN)FUN_00e9c7d0;
    DAT_0126faa8 = (PFN)FUN_00e9c800;
    DAT_0126faac = ((void (&)())::FUN_00e9c850);
}

struct NiStreamUnreg
{
};
// @fnv 0x00e99260
void __cdecl FUN_00e99260()
{
    if (DAT_0126fa5c)
    {
        DAT_0126fa5c = false;
        ::fnv_00a63520::FUN_00a63520(g_0126fab4_arg0);
        DAT_0126fa80 = 0;
        DAT_0126fa84 = 0;
        DAT_0126fa90 = 0;
        DAT_0126fa88 = 0;
        DAT_0126fa7c = 0;
        DAT_0126fa8c = 0;
        ::FUN_00aa10f0((*reinterpret_cast<void (***)()>(&::DAT_0126fa94)));
        ::FUN_00aa10f0((*reinterpret_cast<void (***)()>(&::DAT_0126fa98)));
        ::FUN_00aa10f0((*reinterpret_cast<void (***)()>(&::DAT_0126fa9c)));
        ::FUN_00aa10f0((*reinterpret_cast<void (***)()>(&::DAT_0126faa0)));
        (*reinterpret_cast<void (***)()>(&::DAT_0126fa94)) = 0;
        (*reinterpret_cast<void (***)()>(&::DAT_0126fa98)) = 0;
        (*reinterpret_cast<void (***)()>(&::DAT_0126fa9c)) = 0;
        (*reinterpret_cast<void (***)()>(&::DAT_0126faa0)) = 0;
        DAT_0126faa4 = 0;
        DAT_0126faa8 = 0;
        DAT_0126faac = 0;
    }
}

class ImageSpaceEffectParam
{
  public:
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    float fPriority;
};

template <> class NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceEffectParam** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetAt(unsigned int uiIndex, ImageSpaceEffectParam* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = uiIndex + 1;
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
};

class FUN_00e98be0_queue : public NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >
{
  public:
    unsigned int m_uiCount;

    void MoveLowestPriorityToFront();
};
// @fnv 0x00e98e20
bool NiPick::PerformPick(const NiPoint3& origin, const NiPoint3& direction, bool append)
{
    if (!append)
        m_kResults.m_uiValidCount = 0;
    if (!::FUN_00e9c490((::S_00e9c490_Pt *)&(origin), (::S_00e9c490_Pt *)&(direction), (::S_00e9c490_Ctx *)&(*this), (::S_00e9c490_Node *)(::NiAVObject *)(GetRoot())) || !m_kResults.m_uiValidCount)
        return false;
    if (m_eSortMode != NO_SORT && m_eIntersectionMode != BOUND_INTERSECT && m_kResults.m_uiValidCount > 1)
    {
        if (m_ePickMode == FIND_ALL)
            m_kResults.InvokeCallbacks();
        else
            reinterpret_cast<::FUN_00e98be0_queue *>(&(m_kResults))->MoveLowestPriorityToFront();
    }
    return true;
}

// Finds the element with the lowest fPriority, swaps it with the first element, and sets m_uiCount to 1.
// @fnv 0x00e98be0
void FUN_00e98be0_queue::MoveLowestPriorityToFront()
{
    if (m_uiCount)
    {
        ImageSpaceEffectParam* pFirst = m_pBase[0];
        ImageSpaceEffectParam* pLowestPriority = m_pBase[0];
        unsigned int uiLowestIndex = 0;
        for (unsigned int i = uiLowestIndex + 1; i < m_uiCount; i++)
        {
            if (m_pBase[i]->fPriority < pLowestPriority->fPriority)
            {
                pLowestPriority = m_pBase[i];
                uiLowestIndex = i;
            }
        }
        ImageSpaceEffectParam* pFirstElement = pFirst;
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(uiLowestIndex, (::KeyPair **)&(pFirstElement));
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(0, (::KeyPair **)&(pLowestPriority));
        m_uiCount = 1;
    }
}

class FUN_00a5e3a0_Helper
{
  public:
};

struct NiColorAE993
{
    float r, g, b, a;
    NiColorAE993(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f) : r(fR), g(fG), b(fB), a(fA)
    {}
};

class ImageSpaceTextureE993
{
  public:
    int m_unk00;
    int m_unk04;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30;
    NiColorAE993 m_kFogTint;

    ImageSpaceTextureE993(int iParam) : m_unk00(0), m_unk04(0)
    {
        reinterpret_cast<::S_00e98aa0_Holder *>(this)->SetObject((::S_00e98aa0_RefObj *)(iParam));
    }

    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>((((FUN_00a5e3a0_Helper*)&::g_memoryManager)))->FUN_00aa3e40(uiSize);
    }
    static void operator delete(void*, int, int);
};

class TexturePoolE993
{
  public:
    virtual ~TexturePoolE993();
    ImageSpaceTextureE993** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int m_uiNext;


    unsigned int Add(ImageSpaceTextureE993* pkElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(uiIndex + m_usGrowBy);
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(uiIndex, (::KeyPair **)&(pkElement));
        return uiIndex;
    }

    ImageSpaceTextureE993* GetTexture(int iParam);
};

// Returns the next ImageSpaceTextureE993 from the pool, reusing an existing slot or allocating a new one when the pool is exhausted.
// @fnv 0x00e99330
ImageSpaceTextureE993* TexturePoolE993::GetTexture(int iParam)
{
    if (m_uiNext < m_usSize)
    {
        ImageSpaceTextureE993* pkTexture = m_pBase[m_uiNext];
        reinterpret_cast<::S_00e98aa0_Holder *>((pkTexture))->SetObject((::S_00e98aa0_RefObj *)(iParam));
        m_uiNext++;
        return pkTexture;
    }

    ImageSpaceTextureE993* pkTexture = new ImageSpaceTextureE993(iParam);
    Add(pkTexture);
    m_uiNext++;
    return pkTexture;
}
