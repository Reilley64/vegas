// gamebryo2.2/corelibs/nianimation/nibsplinebasisdata.cpp: NiBSplineBasisData, SplineOwner (10 functions)

#include <cstdint>
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a57f20_cls.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011f4000.h"
#include "nibsplinebasisdata_decls.h"

// Calls the base NiObject::LoadBinary, then reads a scalar from the stream into the basis data's field.
// @fnv 0x00a52c10
void NiBSplineBasisData::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    stream.m_pUnderlyingStream->ReadScalar(m_kBSplineBasis.m_iNumControlPoints);
}

struct FUN_00a52bb0_shell : public NiBSplineBasisData
{
    bool FUN_00a52bb0(NiObject*);
};


// @fnv 0x00a52bb0
bool FUN_00a52bb0_shell::FUN_00a52bb0(NiObject* pkObject)
{
    if (!reinterpret_cast<::A5d470Class *>((pkObject))->IsSameAs({}))
        return false;

    return *(int*)((char*)pkObject + 8) == this->m_kBSplineBasis.m_iNumControlPoints;
}

extern int DAT_01099f24;
void __cdecl FUN_00aa1460(void* pMem, unsigned int uiSize);

// @fnv 0x00a52be0
void* FUN_00a52be0(void* pThis, int, unsigned char flags)
{
    *reinterpret_cast<int**>(pThis) = &DAT_01099f24;
    reinterpret_cast<class ::FUN_00a5d3d0 *>((pThis))->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x28);
    }
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
// @fnv 0x00a52af0
GlobalObjectO2_00a7b610* FUN_00a52af0()
{
    return &::g_011f403c;
}

namespace fnv_00a52c90 {
struct ActorCombatGroup;
struct ArrX
{
    unsigned char pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
// @fnv 0x00a52c90
void FUN_00a52c90(ArrX* pArray)
{
    reinterpret_cast<::A5D6E0This *>((pArray))->AppendCameraPathEntries({});
    ActorCombatGroup* pObject = ((::fnv_00a52c90::ActorCombatGroup *)(::FUN_00a7d330((const char *)((*reinterpret_cast<intptr_t *>(&::g_011f403c))))));
    unsigned n = pArray->m_usSize;
    if (n >= pArray->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pArray))->SetSize(n + pArray->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pArray))->SetAt(n, (char *&)(pObject));
}
}  // namespace fnv_00a52c90

extern int DAT_01099d3c;

struct FUN_00a51ab0_base
{
};

struct FUN_00a51ab0_cls : FUN_00a51ab0_base
{
    intptr_t m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    int m_2c;

    FUN_00a51ab0_cls* FUN_00a51ab0(intptr_t a1, int a2, intptr_t a3);
};

// Calls InitBase, sets the vtable pointer, zeroes four floats and stores a2 into m_2c, then returns this.
// @fnv 0x00a51ab0
FUN_00a51ab0_cls* FUN_00a51ab0_cls::FUN_00a51ab0(intptr_t a1, int a2, intptr_t a3)
{
    reinterpret_cast<::FUN_00a57f20_cls *>(this)->FUN_00a57f20((void *)(a1), (void *)(a3));
    m_vptr00 = (intptr_t)&DAT_01099d3c;
    *(volatile float*)&m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = 0.0f;
    m_28 = 0.0f;
    *(volatile int*)&m_2c = a2;
    return this;
}



class SplineBase
{
  public:
    SplineBase() throw();
    virtual ~SplineBase() throw();
    unsigned int unk04;
};

struct SplineBlock
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    float m_14;
    unsigned int m_18;
    unsigned int m_1c;
};

class SplineObj : public SplineBase
{
  public:
    SplineObj()
    {
        *(volatile float*)&m_08.m_14 = -1.0f;
        m_08.m_00 = 0;
        m_08.m_18 = 0;
        m_08.m_1c = 3;
    }
    virtual ~SplineObj() throw();
    static void* operator new(size_t n) throw()
    {
        return FUN_00aa13e0(n);
    }
    SplineBlock m_08;
};

struct SplineOwner
{
    unsigned int unk00;
    unsigned int unk04;
    SplineBlock m_08;
    SplineObj* CreateSplineObj(unsigned char flags);
};

// @fnv 0x00a52b00
SplineObj* SplineOwner::CreateSplineObj(unsigned char flags)
{
    SplineObj* pResult = new SplineObj;
    reinterpret_cast<::FUN_00a5d450_class *>(this)->CreateVertexBufferSet((uintptr_t)(pResult), (void *)(flags));
    pResult->m_08 = m_08;
    return pResult;
}



class NiSplineBase
{
  public:
    NiSplineBase();
    virtual ~NiSplineBase();
    static void* operator new(size_t uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void*)
    {}
    unsigned int m_uiRefCount;
};

template <class T, int Degree> class NiBSplineBasisT
{
  public:
    NiBSplineBasisT() : m_iNumControlPoints(0), m_fLastTime(-1.0f), m_iMinControlPoint(0), m_iMaxControlPoint(3)
    {}
    int m_iNumControlPoints;
    T m_afWeights[Degree + 1];
    T m_fLastTime;
    int m_iMinControlPoint;
    int m_iMaxControlPoint;
};

class NiSplineImpl : public NiSplineBase
{
  public:
    NiSplineImpl() throw()
    {}
    virtual ~NiSplineImpl();
    NiBSplineBasisT<float, 3> m_kBasis;
};

// Allocates and constructs a NiSplineImpl via its operator new and returns the new object.
// @fnv 0x00a52b60
NiSplineImpl* CreateNiSplineImpl()
{
    return new NiSplineImpl;
}

class NiStreamSave : public NiStream
{
  public:
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteScalar(NiBinaryStream* pkOstr, const T& value)
{
    unsigned int componentSize = sizeof(T);
    unsigned int bytesWritten = pkOstr->m_pfnWrite(pkOstr, &value, sizeof(T), &componentSize, 1);
    pkOstr->m_uiStreamFlags += bytesWritten;
}
class FUN_00a52c50_BasisData : public NiObject
{
  public:
    BSplineBasis<float, 3> m_kBSplineBasis;
    void FUN_00a52c50(NiStream& stream);
};

// Saves the base NiObject data and the BSplineBasis control point count to the given NiStream.
// @fnv 0x00a52c50
void FUN_00a52c50_BasisData::FUN_00a52c50(NiStream& stream)
{
    ::FUN_00a89af0((intptr_t)this);
    WriteScalar(static_cast<NiStreamSave&>(stream).m_pBackingStream, m_kBSplineBasis.m_iNumControlPoints);
}

extern int DAT_0109a2a4;
void* NiMalloc(unsigned int size);

struct FUN_00a54190_cls
{
    intptr_t m_vt;
    void* m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    FUN_00a54190_cls* FUN_00a54190(int n, short a2);
};

// Sets object fields and allocates 4 times m_08 bytes when m_08 is positive.
// @fnv 0x00a54190
FUN_00a54190_cls* FUN_00a54190_cls::FUN_00a54190(int n, short a2)
{
    m_vt = (intptr_t)&DAT_0109a2a4;
    m_08 = n;
    m_0e = a2;
    m_0a = 0;
    m_0c = 0;
    if (m_08 > 0)
    {
        unsigned int sz = m_08;
        m_04 = NiMalloc(sz * 4);
    }
    else
    {
        m_04 = 0;
    }
    return this;
}
