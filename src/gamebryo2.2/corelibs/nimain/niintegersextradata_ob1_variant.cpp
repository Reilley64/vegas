
// src/gamebryo2.2/corelibs/nimain/niintegersextradata_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/gamebryo2.2/corelibs/nimain/niintegersextradata.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include <windows.h>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00c53fa0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a64000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c54000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c2000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01203000.h"
#include "niintegersextradata_decls.h"
struct NiFixedString
{
};
class NiExtraData;
class NiFixedString;
struct NiAVObject
{
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};
extern NiFixedString* DAT_012031c0;
struct FUN_00c543e0_shell : NiAVObject
{
    void FUN_00c543e0();
};
struct FUN_00c54d60_shell
{
    int* FUN_00c54d60();
};
struct FUN_00c54030_shell
{
    int FUN_00c54030(int param_1);
};
struct FUN_00a7b290_shell
{
};
struct FUN_00c54150_shell
{
    void FUN_00c54150(int param_1);
};
struct C00c541e0
{
    bool FUN_00c541e0(int);
};
class NiStream;
class NiStream;
struct NiColor
{
    float r;
    float g;
    float b;
    void SaveBinary(NiStream&);
public:
    void LoadBinary(::NiStream &);
};
struct FUN_00c54660_shell
{
    NiColor color;
    unsigned short fldC;
    unsigned char fldE;
    void FUN_00c54660(NiStream&);
};
struct S_FUN_00c53fa0
{
};
struct S_FUN_00c547e0
{
    void* FUN_00c547e0(unsigned int);
};
struct MM
{
};
struct S
{
    void* vtbl;
    void* ptr;
    void FUN_00c54810();
};
struct NiStream;
struct NiExtraDataSaveHelper : NiExtraData
{
};
struct NiExtraDataSaveHelperShell : NiExtraDataSaveHelper
{
    void FUN_00c54170(NiStream&);
};
struct A51BF0Base
{
    static void* __cdecl operator new(size_t size);
};
struct FUN_00c53f10 : A51BF0Base
{
    unsigned char padding[28];
    FUN_00c53f10();
};
NiFixedString DAT_011f49e0;
class NiStream;
struct FUN_00c54040_cls
{
    unsigned int baseData[3];
    unsigned int unk0c;
    char* entries;
    unsigned int unk14;
    unsigned short count;

    void FUN_00c54040(NiStream& stream, unsigned int flags);
};
struct S_00c54130
{
    void FUN_00c54130(int a);
};
struct S_00c54550_Foo
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;

    void FUN_00c54550(float param_1);
};
class NiStream;
struct FUN_00c545d0_cls
{
    unsigned int baseData[3];
    unsigned short fldC;
    unsigned short fldE;
    void FUN_00c545d0(NiStream& s);
};
struct FUN_00c54b70_cls
{
    unsigned int unk00[2];
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_00c54850(unsigned int n);
    void FUN_00c54a30(unsigned int idx, NiIntegerStreamEntry& e);
    unsigned int FUN_00c54b70(NiIntegerStreamEntry& e);
};
struct FUN_00c54c50_shell
{
    void* vtbl;
    void* ptr;
    unsigned short fld8;
    unsigned short fldA;
    unsigned short fldC;
    unsigned short fldE;

    FUN_00c54c50_shell* FUN_00c54c50(unsigned short param_1, unsigned short param_2);
};
void* __cdecl FUN_00c54bc0(unsigned int);
struct FUN_00c54cc0_cls
{
    float m_00;
    float m_04;
    float m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    bool FUN_00c54cc0(FUN_00c54cc0_cls* other);
};

// Deletes the global NiFixedString instance and clears the pointer; the fixed string's inline
// destructor releases its global-string-table handle unless it is the shared null handle.

struct NiFixedStringD
{
    char* m_kHandle;
    ~NiFixedStringD()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        volatile long* pRefCount = (volatile long*)(m_kHandle - 8);
        InterlockedDecrement(pRefCount);
    }
    static void operator delete(void* pvMem)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(pvMem);
    }
};

// @fnv 0x00c54760
void FUN_00c54760()
{
    delete (NiFixedStringD*)DAT_012031c0;
    DAT_012031c0 = 0;
}

struct ElemZ
{
    int a, b, c;
    unsigned short m_usD;
    unsigned char m_ucE;
    ElemZ()
    {
        m_usD = 0;
        m_ucE = 0;
    }
    bool operator!=(const ElemZ& kOther) const
    {
        return !reinterpret_cast<::FUN_00c54cc0_cls *>((void *)this)->FUN_00c54cc0((::FUN_00c54cc0_cls *)&(kOther));
    }
};
struct FUN_00c54a30
{
    void* m_pv0;
    ElemZ* m_pUserData;
    unsigned short m_us8;
    unsigned short m_usSize;
    unsigned short m_usUsed;
    void SetAt(unsigned int uiIndex, const ElemZ& kElem);
};
// @fnv 0x00c54a30
void FUN_00c54a30::SetAt(unsigned int uiIndex, const ElemZ& kElem)
{
    static ElemZ s_kEmpty;
    if (uiIndex >= m_usSize)
    {
        m_usSize = uiIndex + 1;
        if (kElem != s_kEmpty)
            m_usUsed++;
    }
    else if (kElem != s_kEmpty)
    {
        if (reinterpret_cast<::FUN_00c54cc0_cls *>((void *)&(m_pUserData[uiIndex]))->FUN_00c54cc0((::FUN_00c54cc0_cls *)&(s_kEmpty)))
            m_usUsed++;
    }
    else
    {
        ElemZ* pkCur = &m_pUserData[uiIndex];
        if (*pkCur != s_kEmpty)
            m_usUsed--;
    }
    m_pUserData[uiIndex] = kElem;
}

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
    const NiRTTI* GetBaseRTTI() const
    {
        return m_pBaseRTTI;
    }
};

class NiObject
{
  public:
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOfType(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->GetBaseRTTI();
        }
        return false;
    }
};

struct C54400Owner
{
};

// @fnv 0x00c54400
NiObject* __cdecl FUN_00c54400(C54400Owner* pkOwner)
{
    NiObject* pkResult = 0;
    if (pkOwner)
    {
        const NiFixedString& kName = *DAT_012031c0;
        NiObject* pkTarget = ((::NiObject *)(reinterpret_cast<::NiAVObject *>((pkOwner))->GetExtraData(kName)));
        if (!pkTarget)
            pkResult = 0;
        else
            pkResult = pkTarget->IsKindOfType((const NiRTTI*)&(*reinterpret_cast<int *>(&::g_012031c4))) ? pkTarget : 0;
    }
    return pkResult;
}

struct NiIntegerStreamColor
{
    float r;
    float g;
    float b;
};

struct NiIntegerStreamEntryData
{
    NiIntegerStreamColor m_kFogTint;
    unsigned short m_usValue;
    unsigned char m_ucFlag;

    NiIntegerStreamEntryData(int iValue)
    {
        m_usValue = (unsigned short)iValue;
        m_ucFlag = 0;
    }

    bool operator==(const NiIntegerStreamEntryData& kOther) const
    {
        return ((FUN_00c54cc0_cls*)this)->FUN_00c54cc0((FUN_00c54cc0_cls*)&kOther);
    }
    bool operator!=(const NiIntegerStreamEntryData& kOther) const
    {
        return !(*this == kOther);
    }
    bool IsLess(const NiIntegerStreamEntryData& kOther) const
    {
        return m_ucFlag < kOther.m_ucFlag;
    }
};

class NiIntegerStreamEntryArray
{
  public:
    void* m_pvVtbl;
    NiIntegerStreamEntryData* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned int GetEffectiveSize() const
    {
        return m_usESize;
    }
    NiIntegerStreamEntryData& GetAt(unsigned int uiIndex)
    {
        return m_pBase[uiIndex];
    }
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const NiIntegerStreamEntryData& element)
    {
        static NiIntegerStreamEntryData s_kZero(0);
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != s_kZero)
                m_usESize++;
        }
        else
        {
            if (element != s_kZero)
            {
                if (m_pBase[uiIndex] == s_kZero)
                    m_usESize++;
            }
            else
            {
                NiIntegerStreamEntryData& kOld = m_pBase[uiIndex];
                if (kOld != s_kZero)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
};

class NiIntegerStreamExtraData : public NiExtraData
{
  public:
    NiIntegerStreamEntryArray m_kEntries;
    void FUN_00c54490(const NiIntegerStreamEntryData& kEntry);
};

// @fnv 0x00c54490
void NiIntegerStreamExtraData::FUN_00c54490(const NiIntegerStreamEntryData& kEntry)
{
    unsigned int uiSize = m_kEntries.GetEffectiveSize();
    unsigned int i;
    for (i = 0; i < uiSize; i++)
    {
        NiIntegerStreamEntryData& kElem = m_kEntries.GetAt(i);
        if (kEntry.IsLess(kElem))
            break;
    }

    reinterpret_cast<::FUN_00c54b70_cls *>(&(m_kEntries))->FUN_00c54b70((::NiIntegerStreamEntry &)(kEntry));

    if (i < uiSize)
    {
        while (uiSize > i)
        {
            reinterpret_cast<::FUN_00c54a30 *>(&(m_kEntries))->SetAt(uiSize, (const ::ElemZ &)(m_kEntries.GetAt(uiSize - 1)));
            uiSize--;
        }
        reinterpret_cast<::FUN_00c54a30 *>(&(m_kEntries))->SetAt(i, (const ::ElemZ &)(kEntry));
    }
}

struct StreamHeap
{
};

inline void* operator new[](size_t size)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::StreamHeap *>(&::g_memoryManager))))->FUN_00aa3e40(size);
}

struct StreamEntry
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    unsigned char m_0f;
    StreamEntry()
    {
        m_0c = 0;
        m_0e = 0xff;
    }
};

// @fnv 0x00c54bc0
void* FUN_00c54bc0(unsigned int count)
{
    return new StreamEntry[count];
}

struct ExtraDataBase
{
    ExtraDataBase();
    virtual ~ExtraDataBase();

    unsigned int m_04;
    unsigned int m_08;
};

struct MemoryManagerShell
{
    void* Allocate(unsigned int size);
};
extern MemoryManagerShell g_memoryManagerShell;

struct IntegerEntry
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned short m_0c;
    unsigned char m_0e;

    IntegerEntry()
    {
        m_0c = 0;
        m_0e = 0xff;
    }
    static void* operator new[](size_t size)
    {
        return g_memoryManagerShell.Allocate(size);
    }
};

struct IntegerStreamArrayBase
{
    IntegerStreamArrayBase(unsigned short maxSize, unsigned short growBy)
    {
        m_usMaxSize = maxSize;
        m_usGrowBy = growBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~IntegerStreamArrayBase();

    static IntegerEntry* Allocate(unsigned int n)
    {
        return new IntegerEntry[n];
    }

    IntegerEntry* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct IntegerStreamArray : IntegerStreamArrayBase
{
    IntegerStreamArray() : IntegerStreamArrayBase(0, 1)
    {}
    virtual ~IntegerStreamArray();
};

struct IntegersExtraData : ExtraDataBase
{
    IntegerStreamArray m_entries;

    IntegersExtraData();
    virtual ~IntegersExtraData();
};

// @fnv 0x00c53f10
IntegersExtraData::IntegersExtraData()
{
    reinterpret_cast<::FUN_00c543e0_shell *>(this)->FUN_00c543e0();
}

namespace fnv_00c546c0 {
struct DynamicMemoryAllocator
{
};

struct NiGlobalStringTable
{
};

struct NiFS
{
    int handle;

    __forceinline void* operator new(size_t size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00c546c0::DynamicMemoryAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(size);
    }

    __forceinline NiFS(char const* s)
    {
        if (s == 0)
            handle = (*reinterpret_cast<int *>(&::DAT_0109b220));
        else
            handle = (int)::NiGlobalStringTable::AddString(s);
    }
};

// @fnv 0x00c546c0
void __cdecl FUN_00c546c0()
{
    DAT_012031c0 = (NiFixedString*)new NiFS("FRN");
}
}  // namespace fnv_00c546c0

struct NiIntStreamColorC
{
    float r;
    float g;
    float b;

    bool operator==(const NiIntStreamColorC& c) const
    {
        return (r == c.r && g == c.g && b == c.b);
    }
};

struct NiIntStreamMemoryC
{
    void* Allocate(unsigned int stSize);
};
struct NiIntStreamEntryC
{
    NiIntStreamColorC m_kFogTint;
    unsigned short m_usValue;
    unsigned char m_ucFlag;

    NiIntStreamEntryC()
    {
        m_usValue = 0;
        m_ucFlag = 0xff;
    }
    NiIntStreamEntryC(int iValue)
    {
        m_usValue = (unsigned short)iValue;
        m_ucFlag = 0;
    }

    bool operator!=(NiIntStreamEntryC& kOther)
    {
        return !((FUN_00c54cc0_cls*)this)->FUN_00c54cc0((FUN_00c54cc0_cls*)&kOther);
    }
    static void* operator new[](size_t stSize)
    {
        return ((NiIntStreamMemoryC*)&(*reinterpret_cast<::MM *>(&::g_memoryManager)))->Allocate(stSize);
    }
    static void operator delete[](void* pvMem)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(pvMem);
    }
};
struct NiIntStreamAllocatorC
{
    static NiIntStreamEntryC* Allocate(unsigned int auiCount)
    {
        return new NiIntStreamEntryC[auiCount];
    }
    static void Deallocate(NiIntStreamEntryC* pArray)
    {
        delete[] pArray;
    }
};

// @fnv 0x00c54850
void FUN_00c54b70_cls::FUN_00c54850(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_08)
        return;

    unsigned short i;
    if (uiMaxSize < m_0a)
    {
        for (i = (unsigned short)uiMaxSize; i < m_0a; i++)
        {
            if (((NiIntStreamEntryC*)unk00[1])[i] != NiIntStreamEntryC(0))
            {
                ((NiIntStreamEntryC*)unk00[1])[i] = NiIntStreamEntryC(0);
                unk0c--;
            }
        }
        m_0a = (unsigned short)uiMaxSize;
    }

    NiIntStreamEntryC* pSaveBase = (NiIntStreamEntryC*)unk00[1];
    m_08 = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        unk00[1] = (unsigned int)((::NiIntStreamEntryC *)(::FUN_00c54bc0(m_08)));

        for (i = 0; i < m_0a; i++)
            ((NiIntStreamEntryC*)unk00[1])[i] = pSaveBase[i];

        for (i = m_0a; i < m_08; i++)
            ((NiIntStreamEntryC*)unk00[1])[i] = NiIntStreamEntryC(0);
    }
    else
    {
        unk00[1] = 0;
    }

    NiIntStreamAllocatorC::Deallocate(pSaveBase);
}
