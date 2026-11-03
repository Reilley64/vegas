
// src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a53070
#include <cstdint>
#include <windows.h>
#include "fnv/decl/A53480Object.h"
#include "fnv/decl/FUN_00a95ca0_shell.h"
#include "fnv/decl/StandIn_00a537a0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a3cbf0__NiKeyBasedInterpolator.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/decl/FUN_00a53910_shell.h"
#include "fnv/symbols_00a57000.h"
#include "fnv/symbols_00c85000.h"
int FUN_00a53070(unsigned short usChannel)
{
    return 5;
}

struct FUN_00a53080_shell
{
    int GetThirdValue(int arg);
};

// @fnv 0x00a53080
int FUN_00a53080_shell::GetThirdValue(int arg)
{
    int* p = *(int**)((char*)this + 0x10);
    if (!p)
        return 0;
    return p[2];
}

struct FUN_00a53090_shell
{
    int GetValueFromMember(void* arg);
};

// @fnv 0x00a53090
int FUN_00a53090_shell::GetValueFromMember(void* apUnused)
{
    void* p = *(void**)((char*)this + 0x10);
    if (!p)
        return 0;
    return *(int*)((char*)p + 0xc);
}

class NiObject;
struct NiStream
{
    int _d;
public:
    ::NiObject *DeserializeObject();
};
struct HC1Base
{
    int _p[4];
    bool FUN_00aa0ad0(NiStream*);
};
struct NiBoolData
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
    virtual void vf20();
    virtual void vf21(NiStream*);
};
template <class T> struct NiPointer
{
    T* m_pObject;
};
struct NiBoolInterpolator : HC1Base
{
    NiPointer<NiBoolData> m_spBoolData;
    bool FUN_00a3c5b0(NiStream*);
};
// @fnv 0x00a3c5b0
bool NiBoolInterpolator::FUN_00a3c5b0(NiStream* kStream)
{
    if (!HC1Base::FUN_00aa0ad0(kStream))
        return false;
    NiBoolData* pkBoolData = m_spBoolData.m_pObject;
    if (pkBoolData)
        pkBoolData->vf21(kStream);
    return true;
}

namespace fnv_00a531a0 {
struct NiBoolData
{
    virtual void F0();
    virtual void F1();
    volatile long m_uiRefCount;
    void DecrementRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            F1();
    }
};
struct NiPointer
{
    NiBoolData* m_pObject;
    NiPointer& operator=(NiBoolData* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecrementRefCount();
            m_pObject = p;
        }
        return *this;
    }
};
struct FUN_00a531a0_shell
{
    char _0[12];
    unsigned char m_bBoolValue;
    char _pad[3];
    NiPointer m_spBoolData;
    void SetBoolValue(bool bPoseValue);
};
// Clears the NiPointer member and stores the given bool into m_bBoolValue.
// @fnv 0x00a531a0
void FUN_00a531a0_shell::SetBoolValue(bool abValue)
{
    m_spBoolData = 0;
    m_bBoolValue = abValue;
}
}  // namespace fnv_00a531a0

void __cdecl FUN_00a537a0(float m_fStartTime, float m_fMaximumDistance);

struct NiBoolData_shell
{
};

struct NiBoolInterpolator_shell
{
    int _pad[4];
    NiBoolData_shell* m_spBoolData;
    void FUN_00a531f0(float m_fStartTime, float m_fMaximumDistance);
};

// @fnv 0x00a531f0
void NiBoolInterpolator_shell::FUN_00a531f0(float afArg1, float afArg2)
{
    if (m_spBoolData)
    {
        reinterpret_cast<::StandIn_00a537a0 *>((m_spBoolData))->FUN_00a537a0(afArg1, afArg2);
    }
}

struct FUN_00a530a0_shell
{
    int unk00;
    int unk04;
    int unk08;
    volatile unsigned char unk0c;
    int unk10;

    unsigned char FUN_00a530a0(int unused);
};


// @fnv 0x00a530a0
unsigned char FUN_00a530a0_shell::FUN_00a530a0(int unused)
{
    if (unk10 != 0)
        return 0;

    return unk0c != DAT_0109a914;
}

struct S_00a53680_Stream;
struct S_00a53680_Bin
{
    int unk00;
    int unk04;
    int unk08;
    int(__cdecl* unk0C)(S_00a53680_Bin* o, void* p, unsigned bytes, unsigned* sz, unsigned n);
};
struct S_00a53680_Obj
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(int v);
};
struct S_00a53680_Stream : S_00a53680_Obj
{
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
    int unk24C;
    S_00a53680_Bin* unk250;
};
__forceinline void S_00a53680_Save(S_00a53680_Bin* o, void* v, unsigned n, unsigned elem)
{
    unsigned sz = elem;
    o->unk04 += o->unk0C(o, v, n, &sz, 1);
}
struct S_00a53680_Base
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00a53680_Child : S_00a53680_Base
{
    char unk0C;
    int unk10;
    void SaveToStream(S_00a53680_Stream* kStream);
};
// @fnv 0x00a53680
void S_00a53680_Child::SaveToStream(S_00a53680_Stream* kStream)
{
    reinterpret_cast<::FUN_00a95ca0_shell *>(this)->FUN_00a95ca0((*(::S_00a58160_Stream *)(kStream)));
    S_00a53680_Save(kStream->unk250, &unk0C, 1, 1);
    kStream->vf12(unk10);
}

struct FUN_00a536d0_arr
{
    int unk00;
    int unk04;
    unsigned short m_usCapacity;
    unsigned short m_usElementCount;
    unsigned short unk0c;
    unsigned short m_usGrowBy;
};

struct FUN_00a536d0_self
{
    int unk00[3];
    unsigned char m_bBoolValue;
    unsigned char unk0d[3];
    void* m_spBoolData;
};


struct FUN_00a536d0_cls
{
    void FUN_00a536d0(FUN_00a536d0_arr* pArr);
};

// @fnv 0x00a536d0
void FUN_00a536d0_cls::FUN_00a536d0(FUN_00a536d0_arr* pArr)
{
    FUN_00a536d0_self* self = reinterpret_cast<FUN_00a536d0_self*>(this);
    void* v;
    unsigned int idx;

    reinterpret_cast<::fnv_00a3cbf0::NiKeyBasedInterpolator *>((self))->FUN_00a3cbf0((::fnv_00a3cbf0::StrArr *)(pArr));
    v = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<intptr_t *>(&::g_011f404c))))));
    idx = pArr->m_usElementCount;
    if (idx >= pArr->m_usCapacity)
    {
        reinterpret_cast<::ViewerStrings *>((pArr))->SetSize(idx + pArr->m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pArr))->SetAt(idx, (*(char * *)(&v)));

    v = ((void *)(::FUN_00a7d410("m_bBoolValue", self->m_bBoolValue)));
    idx = pArr->m_usElementCount;
    if (idx >= pArr->m_usCapacity)
    {
        reinterpret_cast<::ViewerStrings *>((pArr))->SetSize(idx + pArr->m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pArr))->SetAt(idx, (*(char * *)(&v)));

    void* pBoolData = self->m_spBoolData;
    v = ((void *)(::FUN_00a7d5a0("m_spBoolData", pBoolData)));
    idx = pArr->m_usElementCount;
    if (idx >= pArr->m_usCapacity)
    {
        reinterpret_cast<::ViewerStrings *>((pArr))->SetSize(idx + pArr->m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pArr))->SetAt(idx, (*(char * *)(&v)));
}

// Based on unverified previous work by another contributor (2026-10-22).
struct BoolData
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
    virtual bool IsEqual(BoolData* other);
};
struct BoolInterpolator
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_uiFilterValue, unk0D, unk0E, unk0F;
    BoolData* m_data;
    bool FUN_00c85800(BoolInterpolator* other);
    bool FUN_00a53220(BoolInterpolator* other);
};
// @fnv 0x00a53220
bool BoolInterpolator::FUN_00a53220(BoolInterpolator* other)
{
    if (!FUN_00c85800(other))
        return false;
    if (m_uiFilterValue != other->m_uiFilterValue)
        return false;
    BoolData* data = m_data;
    if ((m_data && !other->m_data) || (!m_data && other->m_data))
        return false;
    if (m_data)
    {
        BoolData* otherData = other->m_data;
        if (!data->IsEqual(otherData))
            return false;
    }
    return true;
}

class A32D0KeyBasedInterpolator
{
  public:
    A32D0KeyBasedInterpolator();
    virtual ~A32D0KeyBasedInterpolator();

    int unk04;
    int unk08;
};

struct A32D0KeyArray
{
    A32D0KeyArray() : m_pKeyArray(0), m_uiNumKeys(0)
    {}

    void* m_pKeyArray;
    unsigned int m_uiNumKeys;
};

class FUN_00a532d0 : public A32D0KeyBasedInterpolator
{
  public:
    FUN_00a532d0(bool bFlag);
    virtual ~FUN_00a532d0();

    bool m_bFlag;
    A32D0KeyArray m_kKeys;
};

// Constructor that initializes m_bFlag from the given flag and default-constructs the key array.
// @fnv 0x00a532d0
FUN_00a532d0::FUN_00a532d0(bool bFlag) : m_bFlag(bFlag)
{}

struct S_00a533c0_Data
{
    int unk00;
    int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned char unk14;
};
struct S_00a533c0_Class
{
    int unk00;
    int unk04;
    float unk08;
    unsigned char unk0c;
    S_00a533c0_Data* unk10;
    unsigned char unk14;
    bool UpdateValue(float fValue, int iValue, unsigned char* pOut);
};
// @fnv 0x00a533c0
bool S_00a533c0_Class::UpdateValue(float fValue, int iValue, unsigned char* pucOut)
{
    if (unk08 == fValue)
    {
        if (unk0c == DAT_0109a914)
        {
            *pucOut = 0;
            return false;
        }
        *pucOut = (unk0c != 0);
        return true;
    }

    S_00a533c0_Data* pData = unk10;
    if (pData != 0)
    {
        unsigned int uiOther = pData->unk10;
        unsigned int ItemUpdateArray = pData->unk08;
        unsigned char ucFlag = pData->unk14;
        uintptr_t uiKey = pData->unk0c;
        if (ItemUpdateArray > 0)
        {
            unk0c = ((unsigned char)((int)(::InterpolateBooleanKey(fValue, (const ::AnimationKey *)(uiKey), uiOther, ItemUpdateArray, (unsigned int *)(void *)(&unk14), ucFlag))) != 0);
        }
    }

    if (unk0c == DAT_0109a914)
    {
        *pucOut = 0;
        return false;
    }
    *pucOut = (unk0c != 0);
    unk08 = fValue;
    return true;
}


// @fnv 0x00aa0ab0
void __cdecl FUN_00aa0ab0()
{
    FUN_00aa1000();
}

class CloningProcessA535;

class TESObjectDoorController
{
  public:
};

class FUN_00a3ca10
{
  public:
    FUN_00a3ca10() throw();
    virtual ~FUN_00a3ca10() throw();
    int unk04[2];
};

namespace ni535 {
}

template <class T> class NiPointerA535
{
  public:
    NiPointerA535() : m_pObject(0)
    {}
    T* m_pObject;
};

class NiBoolInterpA535 : public FUN_00a3ca10
{
  public:
    NiBoolInterpA535() throw() : m_bBoolValue((*reinterpret_cast<bool *>(&::DAT_0109a914)))
    {
        m_uiLastKeyIndex = 0;
    }
    virtual ~NiBoolInterpA535() throw();


    bool m_bBoolValue;
    NiPointerA535<void> m_spBoolData;
    unsigned int m_uiLastKeyIndex;

    NiBoolInterpA535* FUN_00a53590(CloningProcessA535& cloning);
};

// Allocates a new NiBoolInterpA535, copies this object into it via CloneTo, and returns the new instance.
// @fnv 0x00a53590
NiBoolInterpA535* NiBoolInterpA535::FUN_00a53590(CloningProcessA535& cloning)
{
    NiBoolInterpA535* p = new NiBoolInterpA535;
    reinterpret_cast<::A53480Object *>(this)->CloneTo((::A53480Object *)(p), (::A53480CloningProcess &)(cloning));
    return p;
}


namespace A536 {

class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Read(T& value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, &value, sizeof(T), &uiSize, 1);
    }
};

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;

    NiPointer& operator=(T* pObject)
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
};

class NiBoolData : public NiRefObject
{
};

struct NiStreamData
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248;
    NiBinaryStream* m_pUnderlyingStream;

};

}

class NiKeyBasedInterpolator_LoadBinary_Helper
{
  public:
    int unk04;
    int unk08;
    virtual void LoadBinary(NiStream& kStream);
};

class NiBoolInterpolatorA536 : public NiKeyBasedInterpolator_LoadBinary_Helper
{
  public:
    bool m_bBoolValue;
    A536::NiPointer<A536::NiBoolData> m_spBoolData;

    void FUN_00a53600(NiStream& kStream);
};

// Calls base LoadBinary, reads m_bBoolValue from the underlying stream, then assigns m_spBoolData from FUN_00a64620().
// @fnv 0x00a53600
void NiBoolInterpolatorA536::FUN_00a53600(NiStream& kStream)
{
    ::FUN_00aa0ac0();
    A536::NiStreamData& kData = reinterpret_cast<A536::NiStreamData&>(kStream);
    kData.m_pUnderlyingStream->Read(m_bBoolValue);
    m_spBoolData = ((::A536::NiBoolData *)(reinterpret_cast<::NiStream *>(&(kData))->DeserializeObject()));
}


struct BRef
{
    virtual void vf00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct BKey
{
    float m_fTime;
    unsigned char m_bValue;
    static BKey* GetKeyPointerByIndex(BKey* p, unsigned i, unsigned char s)
    {
        return (BKey*)((char*)p + i * s);
    }
};

struct BDat : BRef
{
    unsigned int m_uiNumKeys;
    BKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    BKey* ComputePositionAtTime(unsigned int& n, int& t, unsigned char& s) const
    {
        t = m_eRequestType;
        s = m_ucKeyDataSize;
        n = m_uiNumKeys;
        return m_pKeyArray;
    }
};

template <class T> struct BPtr
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    BPtr& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
};

struct BInterp
{
    int unk00, unk04, unk08;
    unsigned char m_bBoolValue;
    BPtr<BDat> m_spBoolData;
    void FinalizeBoolValue();
};

// Resolves the boolean data into m_bBoolValue, clearing m_spBoolData when keys are absent or all values are constant.
// @fnv 0x00a530c0
void BInterp::FinalizeBoolValue()
{
    if (m_spBoolData)
    {
        unsigned int uiNumKeys;
        int eRequestType;
        unsigned char ucKeyDataSize;
        BKey* pkKeys = m_spBoolData->ComputePositionAtTime(uiNumKeys, eRequestType, ucKeyDataSize);
        if (uiNumKeys == 0)
        {
            m_spBoolData = 0;
            m_bBoolValue = DAT_0109a914;
        }
        else
        {
            unsigned char ucFirstValue = BKey::GetKeyPointerByIndex(pkKeys, 0, ucKeyDataSize)->m_bValue;
            bool bConstant;
            if (uiNumKeys == 1)
                bConstant = true;
            else if (eRequestType == 1 || eRequestType == 5)
            {
                bConstant = true;
                for (unsigned int i = 1; bConstant && i < uiNumKeys; i++)
                    if (BKey::GetKeyPointerByIndex(pkKeys, i, ucKeyDataSize)->m_bValue != ucFirstValue)
                        bConstant = false;
            }
            else
                bConstant = false;
            if (bConstant)
            {
                m_spBoolData = 0;
                m_bBoolValue = ucFirstValue;
            }
        }
    }
}

int FUN_00a53070(unsigned short usChannel);


class NiRefObject3300
{
  public:
    virtual ~NiRefObject3300();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointer3300
{
  public:
    NiPointer3300(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer3300()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer3300& operator=(const NiPointer3300& ptr)
    {
        T* pObject = ptr.m_pObject;
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

class Interpolator3300 : public NiRefObject3300
{
  public:
};

class Controller3300
{
  public:
    Controller3300* FUN_00a53300(float fA, float fB);

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiPointer3300<Interpolator3300> m_spInterp;
    int m_iFadeIndex;
};

// @fnv 0x00a53300
Controller3300* Controller3300::FUN_00a53300(float fA, float fB)
{
    Controller3300* pkCopy = ((::Controller3300 *)(::FUN_00a57050((intptr_t)this, fA)));
    if (m_spInterp.m_pObject)
    {
        NiPointer3300<Interpolator3300> spInterp;
        reinterpret_cast<::FUN_00a53910_shell *>((m_spInterp.m_pObject))->FUN_00a53910(fA, fB, (::NiPointer< ::NiBoolData> &)(spInterp));
        pkCopy->m_spInterp = spInterp;
        pkCopy->m_iFadeIndex = 0;
    }
    return pkCopy;
}
