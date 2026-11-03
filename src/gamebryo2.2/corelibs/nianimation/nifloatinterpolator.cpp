
// NiFloatInterpolator constructor and binary loading for
// gamebryo2.2/corelibs/nianimation/nifloatinterpolator.cpp.
#include <cstdint>
#include <new>
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_00a3ce20_shell.h"
#include "fnv/decl/FUN_00a95ca0_shell.h"
#include "fnv/decl/S00a3cc40.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a3cbf0__NiKeyBasedInterpolator.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a57000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011f3000.h"
#include "nifloatinterpolator.h"

// NOTE (matcher worker): the constructor below compiles byte-identically for
// its 57 bytes under /O2 /GS /EHsc /Gy except that MSVC 9 hoists the `fld`
// of the m_fFloatValue store above the argument load and pushes the vtable
// store below the matching `fstp`; no C++ spelling of the member-initializer
// list, assignment order or statement order tried here keeps MSVC 9 from
// emitting that pair in the original position (argument load, vtable store,
// fld/fstp). Its mark is intentionally left off because the canonical span of
// 0x00A3C340 (70 bytes, see task.json/covered_functions.json) also absorbs
// the seven INT3 bytes and the 6-byte GetRTTI at 0x00A3C380, which is absent
// from the function index, so no /Gy compilation can ever fill those 13
// bytes. Full evidence is in this unit's matcher checks.
NiFloatInterpolator::NiFloatInterpolator(NiFloatData* pkFloatData)
    : m_fFloatValue(-FLT_MAX), m_spFloatData(pkFloatData), m_uiLastKeyIndex(0)
{}

// Loads the float value and a NiFloatData reference from the stream, releasing the old data and incrementing the new one's ref count.
// @fnv 0x00a3c800
void NiFloatInterpolator::LoadBinary(NiStream& kStream)
{
    ::FUN_00aa0ac0();

    ReadBinaryValue(kStream, m_fFloatValue);

    // FNV 2.2 NiPointer assignment order: release the old object before
    // retaining the new one (matches the original refcount sequence).
    NiFloatData* pkData = (NiFloatData*)kStream.DeserializeObject();
    if (m_spFloatData.m_pObject != pkData)
    {
        if (m_spFloatData.m_pObject)
            m_spFloatData.m_pObject->DecRefCount();
        m_spFloatData.m_pObject = pkData;
        if (m_spFloatData.m_pObject)
            m_spFloatData.m_pObject->IncRefCount();
    }
}

// @fnv 0x00a3c3c0
int FUN_00a3c3c0(void* thisPtr, int, unsigned short)
{
    void* pData = *(void**)((char*)thisPtr + 0x10);
    if (!pData)
        return 0;
    return *(int*)((char*)pData + 0x10);
}

// @fnv 0x00a3c3d0
unsigned char FUN_00a3c3d0(const void* self, int, unsigned short)
{
    const char* p = *(const char**)((const char*)self + 0x10);
    if (!p)
        return 0;
    return *(const unsigned char*)(p + 0x14);
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};

// @fnv 0x00a3c380
const GlobalObjectO2_00a7b610* __cdecl FUN_00a3c380()
{
    return &::g_011f3738;
}

struct FloatDataHelper
{
};
struct FloatInterpView
{
    char pad[0x10];
    FloatDataHelper* m_spFloatData;
};

// If m_spFloatData is set, forwards the two float arguments to its FUN_00a3cc40 method.
// @fnv 0x00a3c540
void FUN_00a3c540(FloatInterpView* self, int edx, float m_fStartTime, float m_fMaximumDistance)
{
    if (self->m_spFloatData)
        reinterpret_cast<::S00a3cc40 *>((self->m_spFloatData))->FUN_00a3cc40(m_fStartTime, m_fMaximumDistance);
}

struct FUN_00a3c500_shell : NiFloatInterpolator
{
    void SetFloatValue(float value);
};

// Releases the NiFloatData pointer at offset 0x10 if set, then stores value at offset 0xc.
// @fnv 0x00a3c500
void FUN_00a3c500_shell::SetFloatValue(float value)
{
    if (this->m_spFloatData.m_pObject)
    {
        this->m_spFloatData.m_pObject->DecRefCount();
        this->m_spFloatData.m_pObject = 0;
    }
    this->m_fFloatValue = value;
}

extern char DAT_01096f34;

extern void(* FUN_00fdf1c0)(int);

struct S_00a3c340_Class
{
    void* unk00;
    int unk04;
    int unk08;
    float unk0c;
    void* unk10;
    int unk14;

    void FUN_00a3ca10();
    S_00a3c340_Class* Initialize(intptr_t arg);
};

// NiFloatInterpolator::NiFloatInterpolator(float)
class FUN_00a3c390 : public NiKeyBasedInterpolator
{
  public:
    FUN_00a3c390(float fPoseValue);
    virtual ~FUN_00a3c390();

    float m_fFloatValue;
    NiPointer<NiFloatData> m_spFloatData;
    unsigned int m_uiLastKeyIndex;
};

// Constructs a float interpolator, initialising the pose value from the argument and clearing the float data pointer and the extra field.
// @fnv 0x00a3c390
FUN_00a3c390::FUN_00a3c390(float fPoseValue) : m_fFloatValue(fPoseValue), m_spFloatData(0), m_uiLastKeyIndex(0)
{}

namespace fnv_00a3c3f0 {

struct NiFloatInterpolatorShell_00a3c3f0 : NiFloatInterpolator
{
    unsigned char FUN_00a3c3f0(unsigned int unused) const;
};

// Returns 0 if m_spFloatData.m_pObject is set or m_fFloatValue equals DAT_0109a918, otherwise returns 1.
// @fnv 0x00a3c3f0
unsigned char NiFloatInterpolatorShell_00a3c3f0::FUN_00a3c3f0(unsigned int unused) const
{
    if (m_spFloatData.m_pObject)
        return 0;
    if (m_fFloatValue == ::DAT_0109a918)
        return 0;
    return 1;
}
}  // namespace fnv_00a3c3f0

struct NiBaseEqualityView
{
    unsigned char FUN_00c85800(const NiObject* other);
};
struct NiFloatDataEqualityView
{
    virtual void ScalarDeletingDestructor();
    virtual void DeleteThis();
    virtual void LoadBinary();
    virtual void GetRTTI();
    virtual void MakeClone();
    virtual void LinkObject();
    virtual void RegisterStreamables();
    virtual void SaveBinary();
    virtual void GetViewerStrings();
    virtual void AsNiNode();
    virtual void AsNiAVObject();
    virtual void AsNiGeometry();
    virtual void AsNiTriBasedGeom();
    virtual void AsNiTriShape();
    virtual void AsNiTriStrips();
    virtual void AsNiProperty();
    virtual void AsNiTimeController();
    virtual void AsNiTexture();
    virtual void AsNiSourceTexture();
    virtual void AsNiPixelData();
    virtual void IsKindOfType();
    virtual void IsExactKindOf();
    virtual void IsDerivedKindOf();
    virtual bool IsEqual(const NiFloatData* other);
};
struct NiFloatInterpolatorEquality : NiFloatInterpolator
{
    bool FUN_00a3c5e0(const NiObject* otherObject);
};
// @fnv 0x00a3c5e0
bool NiFloatInterpolatorEquality::FUN_00a3c5e0(const NiObject* otherObject)
{
    if (!reinterpret_cast<NiBaseEqualityView*>(this)->FUN_00c85800(otherObject))
        return false;
    const NiFloatInterpolator* other = static_cast<const NiFloatInterpolator*>(otherObject);
    if (m_fFloatValue != other->m_fFloatValue)
        return false;
    if ((m_spFloatData.m_pObject && !other->m_spFloatData.m_pObject) ||
        (!m_spFloatData.m_pObject && other->m_spFloatData.m_pObject))
        return false;
    if (m_spFloatData.m_pObject)
    {
        NiFloatDataEqualityView& data = *reinterpret_cast<NiFloatDataEqualityView*>(m_spFloatData.m_pObject);
        NiFloatData* otherData = other->m_spFloatData.m_pObject;
        if (!data.IsEqual(otherData))
            return false;
    }
    return true;
}

class A3C640FloatData
{
  public:
    virtual ~A3C640FloatData();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

template <class T> class A3C640Pointer
{
  public:
    T* m_pObject;

    A3C640Pointer() : m_pObject(0)
    {}
    ~A3C640Pointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
};

class A3C640FloatDataOps : public A3C640FloatData
{
  public:
};

class A3C640Interpolator
{
  public:
    int unk00;
    int unk04;
    int unk08;
    float m_fFloatValue;
    A3C640FloatDataOps* m_spFloatData;
    unsigned int m_uiLastKeyIndex;


    A3C640Interpolator* FUN_00a3c640(float m_fStartTime, float m_fMaximumDistance) const;
};

// @fnv 0x00a3c640
A3C640Interpolator* A3C640Interpolator::FUN_00a3c640(float m_fStartTime, float m_fMaximumDistance) const
{
    A3C640Interpolator* pkSeqInterp = ((::A3C640Interpolator *)(::FUN_00a57050((intptr_t)this, m_fStartTime)));
    if (m_spFloatData && pkSeqInterp)
    {
        A3C640Pointer<A3C640FloatData> spNewFloatData;
        reinterpret_cast<::FUN_00a3ce20_shell *>((void *)(m_spFloatData))->FUN_00a3ce20(m_fStartTime, m_fMaximumDistance, (::NiFloatData **)&(spNewFloatData));
        reinterpret_cast<::FORenderedMenu *>((pkSeqInterp))->SetDefaultTexture((::NiTexture *)(::A3C640FloatData *)(spNewFloatData));
        pkSeqInterp->m_uiLastKeyIndex = 0;
    }
    return pkSeqInterp;
}

struct BA3C6D0FloatKey
{
};

class BA3C6D0FloatData
{
  public:
    BA3C6D0FloatKey* ComputePositionAtTime(unsigned int& uiNumKeys, unsigned int& eType, unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }

    int unk00;
    int unk04;
    unsigned int m_uiNumKeys;
    BA3C6D0FloatKey* m_pKeyArray;
    unsigned int m_eRequestType;
    unsigned char m_ucKeyDataSize;
};

static const float NI_INFINITY = 3.402823466e+38f;
static const float INVALID_FLOAT = -NI_INFINITY;

class BA3C6D0Interpolator
{
  public:
    bool TimeHasChanged(float fTime) const
    {
        return m_fLastTime != fTime;
    }
    bool EvaluateFloatAtTime(float fTime, void* pkInterpTarget, float& fValue);

    int unk00;
    int unk04;
    float m_fLastTime;
    float m_fFloatValue;
    BA3C6D0FloatData* m_spFloatData;
    unsigned int m_uiLastKeyIndex;
};

// @fnv 0x00a3c6d0
bool BA3C6D0Interpolator::EvaluateFloatAtTime(float fTime, void* pkInterpTarget, float& fValue)
{
    if (!TimeHasChanged(fTime))
    {
        fValue = m_fFloatValue;
        if (m_fFloatValue == INVALID_FLOAT)
            return false;
        return true;
    }

    if (m_spFloatData)
    {
        unsigned int uiNumKeys;
        unsigned int eType;
        unsigned char ucSize;
        BA3C6D0FloatKey* pkKeys = m_spFloatData->ComputePositionAtTime(uiNumKeys, eType, ucSize);
        if (uiNumKeys > 0)
            m_fFloatValue =
                ::InterpolateKey(fTime, (const ::S00a26b40_Key *)(pkKeys), eType, uiNumKeys, (unsigned int *)&(m_uiLastKeyIndex), ucSize);
    }

    if (m_fFloatValue == INVALID_FLOAT)
        return false;

    fValue = m_fFloatValue;
    m_fLastTime = fTime;
    return true;
}

struct FUN_00a3c780_cls : NiFloatInterpolator
{
    void FUN_00a3c780(NiFloatInterpolator* dst, unsigned int uiArg);
};

// @fnv 0x00a3c780
void FUN_00a3c780_cls::FUN_00a3c780(NiFloatInterpolator* dst, unsigned int uiArg)
{
    ::FUN_00aa0ab0();
    *(volatile float*)&dst->m_fFloatValue = m_fFloatValue;
    NiFloatData* pOld = *(NiFloatData* volatile*)&dst->m_spFloatData.m_pObject;
    if (pOld != m_spFloatData.m_pObject)
    {
        if (pOld)
        {
            pOld->DecRefCount();
        }
        NiFloatData* pNew = m_spFloatData.m_pObject;
        dst->m_spFloatData.m_pObject = pNew;
        if (pNew)
        {
            pNew->IncRefCount();
        }
    }
    dst->m_uiLastKeyIndex = m_uiLastKeyIndex;
}

// GetViewerStrings: base strings, then the class name, m_fFloatValue and m_spFloatData.

class C940StringArray
{
  public:
    virtual ~C940StringArray();

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class C940Pointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class C940FloatData;



class C940FloatInterpolator
{
  public:
    int unk00;
    int unk04;
    int unk08;
    float m_fFloatValue;
    C940Pointer<C940FloatData> m_spFloatData;

    void FUN_00a3c940(C940StringArray* pkStrings);
};

// Appends the base viewer strings plus the class name, m_fFloatValue and m_spFloatData entries to pkStrings.
// @fnv 0x00a3c940
void C940FloatInterpolator::FUN_00a3c940(C940StringArray* pkStrings)
{
    reinterpret_cast<::fnv_00a3cbf0::NiKeyBasedInterpolator *>(this)->FUN_00a3cbf0((::fnv_00a3cbf0::StrArr *)(pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f3738))));
    pkStrings->Add(::FUN_00a7d550("m_fFloatValue", m_fFloatValue));
    pkStrings->Add(::FUN_00a7d5a0("m_spFloatData", m_spFloatData));
}

class NiStreamW;

class NiBinaryStreamW
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStreamW* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    virtual ~NiBinaryStreamW();

    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NIBINARYSTREAM_WRITEFN m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

class NiStreamW
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
    virtual void SaveLinkID(const void* pkObject);

    unsigned char m_auPad[0x248];
    NiBinaryStreamW* m_pUnderlyingStream;
    NiBinaryStreamW* m_pBackingStream;
};

template <class T> inline void WriteBinaryArray(NiBinaryStreamW& os, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    os.BinaryWrite(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> inline void SerializeValue(NiStreamW& kStream, const T& value)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &value, 1);
}

class FUN_00a95ca0_helper
{
  public:
};

class NiFloatInterpolatorW : public FUN_00a95ca0_helper
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    float m_fFloatValue;
    void* m_spFloatData;

    void SaveToStream(NiStreamW& kStream);
};

// @fnv 0x00a3c880
void NiFloatInterpolatorW::SaveToStream(NiStreamW& kStream)
{
    reinterpret_cast<::FUN_00a95ca0_shell *>(this)->FUN_00a95ca0((*(::S_00a58160_Stream *)(&kStream)));
    SerializeValue(kStream, m_fFloatValue);
    kStream.SaveLinkID(m_spFloatData);
}

class TimedAnimationKey
{
  public:
    float m_fTime;
    float m_fValue;

    FNV_FORCEINLINE float GetValue() const
    {
        return m_fValue;
    }
    FNV_FORCEINLINE TimedAnimationKey* GetKeyPointerByIndex(unsigned int uiIndex, unsigned char ucKeySize)
    {
        return (TimedAnimationKey*)((char*)this + uiIndex * ucKeySize);
    }
};

class NiFloatDataEx : public NiFloatData
{
  public:
    FNV_FORCEINLINE TimedAnimationKey* ComputePositionAtTime(unsigned int& uiNumKeys, NiAnimationKey__KeyType& eType,
                                                             unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }
};

template <class T> FNV_FORCEINLINE void NiPointerAssign(NiPointer<T>& sp, T* pObject)
{
    if (sp.m_pObject != pObject)
    {
        if (pObject)
            pObject->IncRefCount();
        if (sp.m_pObject)
            sp.m_pObject->DecRefCount();
        sp.m_pObject = pObject;
    }
}


class FUN_00a3c420_cls : public NiFloatInterpolator
{
  public:
    void CollapseConstantKeys();
};

// When the key data is empty or collapsible, clears m_spFloatData and stores a float value in m_fFloatValue.
// @fnv 0x00a3c420
void FUN_00a3c420_cls::CollapseConstantKeys()
{
    if (m_spFloatData.m_pObject)
    {
        unsigned int uiNumKeys;
        NiAnimationKey__KeyType eType;
        unsigned char ucSize;
        TimedAnimationKey* pkKeys =
            ((NiFloatDataEx*)m_spFloatData.m_pObject)->ComputePositionAtTime(uiNumKeys, eType, ucSize);
        if (uiNumKeys == 0)
        {
            NiPointerAssign<NiFloatData>(m_spFloatData, 0);
            m_fFloatValue = DAT_0109a918;
            return;
        }

        float fValue = pkKeys->GetKeyPointerByIndex(0, ucSize)->GetValue();
        if (uiNumKeys != 1)
        {
            if (eType != NiAnimationKey__KeyType_LINKEY && eType != NiAnimationKey__KeyType_STEPKEY)
                return;
            bool bPosed = true;
            for (unsigned int ui = 1; bPosed && ui < uiNumKeys; ui++)
            {
                if (pkKeys->GetKeyPointerByIndex(ui, ucSize)->GetValue() != fValue)
                    bPosed = false;
            }
            if (!bPosed)
                return;
        }
        NiPointerAssign<NiFloatData>(m_spFloatData, 0);
        m_fFloatValue = fValue;
    }
}

void* __cdecl FUN_00aa13e0(unsigned int size);
class FUN_00a3ca10
{
  public:
    virtual void vf00();
    int unk04;
    int unk08;
    FUN_00a3ca10() throw();
};
// @fnv 0x00a3c340
S_00a3c340_Class* S_00a3c340_Class::Initialize(intptr_t arg)
{
    new ((void *)this) ::FUN_00a3ca10();

    unk00 = &DAT_01096f34;
    unk0c = DAT_0109a918;
    unk10 = (void*)arg;

    if (arg != 0)
    {
        FUN_00fdf1c0(arg + 4);
    }

    unk14 = 0;
    return this;
}
class A3C8D0_Object : public FUN_00a3ca10
{
  public:
    float m_0C;
    int m_10;
    NiPointer<NiObject> m_14;

    static void* operator new(size_t size)
    {
        return FUN_00aa13e0(size);
    }
    A3C8D0_Object() : m_0C(DAT_0109a918), m_10(0)
    {}
    virtual void vf00();
};
struct A3C8D0_Owner
{
    A3C8D0_Object* CreateObject(int arg);
};
// Allocates an A3C8D0_Object, calls FUN_00a3c780 with the object and arg, and returns the object.
// @fnv 0x00a3c8d0
A3C8D0_Object* A3C8D0_Owner::CreateObject(int arg)
{
    A3C8D0_Object* object = new A3C8D0_Object;
    reinterpret_cast<::FUN_00a3c780_cls *>(this)->FUN_00a3c780((::NiFloatInterpolator *)(object), arg);
    return object;
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nifloatinterpolator.inc"
