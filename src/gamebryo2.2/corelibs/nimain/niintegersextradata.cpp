// gamebryo2.2/corelibs/nimain/niintegersextradata.cpp: NiIntegersExtraData, NiExtraDataSaveHelperShell (19 functions)

#include <cstdint>
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00c53fa0_Class.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a64000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c54000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_010c2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01203000.h"
#include "niintegersextradata_decls.h"
#include <new>
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/FUN_00a99800_shell.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_011f5000.h"
#include <cstddef>
#include <windows.h>
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/symbols_0109b000.h"
struct NiFixedString
{
};

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

// @fnv 0x00c543e0
void FUN_00c543e0_shell::FUN_00c543e0()
{
    ::AssignFixedString((char *)this, (intptr_t)&(*DAT_012031c0), {});
}


struct FUN_00c54d60_shell
{
    int* FUN_00c54d60();
};

// @fnv 0x00c54d60
int* FUN_00c54d60_shell::FUN_00c54d60()
{
    return &(*reinterpret_cast<int *>(&::g_012031c4));
}

struct FUN_00c54030_shell
{
    intptr_t FUN_00c54030(int param_1);
};

// @fnv 0x00c54030
intptr_t FUN_00c54030_shell::FUN_00c54030(int param_1)
{
    return (intptr_t)this;
}

struct FUN_00a7b290_shell
{
};
struct FUN_00c54150_shell
{
    void FUN_00c54150(intptr_t param_1);
};
// @fnv 0x00c54150
void FUN_00c54150_shell::FUN_00c54150(intptr_t param_1)
{
    reinterpret_cast<::MyOwner *>((((FUN_00a7b290_shell*)this)))->FUN_00a7b290((*(::NiStream *)(param_1)));
}

struct C00c541e0
{
    bool FUN_00c541e0(intptr_t);
};
// Calls FUN_00a7b3d0 with the given int and returns its bool result.
// @fnv 0x00c541e0
bool C00c541e0::FUN_00c541e0(intptr_t a)
{
    bool b = ((bool)(reinterpret_cast<::NiObject_00a7b3d0 *>(this)->FUN_00a7b3d0((::NiObject_00a7b3d0 *)(a))));
    return b;
}

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
// @fnv 0x00c54660
void FUN_00c54660_shell::FUN_00c54660(NiStream& aStream)
{
    color.SaveBinary(aStream);
    ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)&(aStream), &fldC);
    ::FUN_00a29550((intptr_t)&(aStream), (intptr_t)(&fldE));
    ::FUN_00a29550((intptr_t)&(aStream), (intptr_t)(&fldE));
}

struct S_FUN_00c53fa0
{
};
struct S_FUN_00c547e0
{
    void* FUN_00c547e0(unsigned int);
};
// Calls FUN_00c53fa0 on this, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x00c547e0
void* S_FUN_00c547e0::FUN_00c547e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00c53fa0_Class *>((reinterpret_cast<S_FUN_00c53fa0*>(this)))->FUN_00c53fa0_Class::~FUN_00c53fa0_Class();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x1c);
    return this;
}

struct MM
{
};
struct S
{
    void* vtbl;
    void* ptr;
    void FUN_00c54810();
};
// Sets the object's vtable pointer to DAT_010c2b2c and deallocates its ptr through g_memoryManager.
// @fnv 0x00c54810
void S::FUN_00c54810()
{
    *(intptr_t*)this = (intptr_t)&::FNV_vtbl_NiTArrayBase;
    void* p1 = ptr;
    void* p2 = p1;
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(p2);
}

struct NiStream;
struct NiExtraDataSaveHelper : NiExtraData
{
};
struct NiExtraDataSaveHelperShell : NiExtraDataSaveHelper
{
    void FUN_00c54170(NiStream&);
};
// @fnv 0x00c54170
void NiExtraDataSaveHelperShell::FUN_00c54170(NiStream& stream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0(stream);
    unsigned int count = *(unsigned short*)((char*)this + 0x18);
    ::FUN_0044adf0((::MiddleHighProcess *)&(stream), (intptr_t)&(count));
    for (unsigned int i = 0; i < count; ++i)
        (*(FUN_00c54660_shell**)((char*)this + 0x10))[i].FUN_00c54660(stream);
}

struct A51BF0Base
{
};

struct FUN_00c53f10 : A51BF0Base
{
    unsigned char padding[28];
    FUN_00c53f10();
};

NiFixedString DAT_011f49e0;

// Allocates a FUN_00c53f10 object, sets its name to DAT_011f49e0, and returns it as an NiAVObject pointer.
// @fnv 0x00c54210
NiAVObject* FUN_00c54210()
{
    NiAVObject* object = reinterpret_cast<NiAVObject*>(new FUN_00c53f10);
    ::AssignFixedString((char *)(object), (intptr_t)&(DAT_011f49e0), {});
    return object;
}

class NiStream;

struct FUN_00c54040_cls
{
    unsigned int baseData[3];
    unsigned int unk0c;
    char* entries;
    unsigned int unk14;
    unsigned short count;

    void FUN_00c54040(NiStream& stream, uintptr_t flags);
};

struct S_00c54130
{
    void FUN_00c54130(intptr_t a);
};

// @fnv 0x00c54130
void S_00c54130::FUN_00c54130(intptr_t a)
{
    reinterpret_cast<::NiExtraData *>(this)->LinkObject((*(::NiStream *)(a)));
}


struct S_00c54550_Foo
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;

    void FUN_00c54550(float param_1);
};

// @fnv 0x00c54550
void S_00c54550_Foo::FUN_00c54550(float param_1)
{
    while (param_1 < ::_DAT_01012060)
        param_1 += ::runtimeInitializationFloat4222;

    while (param_1 >= ::runtimeInitializationFloat4222)
        param_1 -= ::runtimeInitializationFloat4222;

    unk0c = (unsigned short)(param_1 * DAT_01017b70);
}

class NiStream;



struct FUN_00c545d0_cls
{
    unsigned int baseData[3];
    unsigned short fldC;
    unsigned short fldE;
    void FUN_00c545d0(NiStream& s);
};

// @fnv 0x00c545d0
void FUN_00c545d0_cls::FUN_00c545d0(NiStream& aStream)
{
    unsigned char flag;
    reinterpret_cast<::NiColor *>(this)->LoadBinary(aStream);
    ::FUN_00a30370((::Stream *)&(aStream), &fldC);
    ::FUN_00a643b0((::BA643B0Stream &)(aStream), (char *)(void *)(&fldE));
    ::FUN_00a643b0((::BA643B0Stream &)(aStream), (char *)(void *)(&flag));
    short sValue = (short)fldC;
    if (sValue < 0)
    {
        float fScaled = (float)((double)sValue / DAT_01017b70);
        reinterpret_cast<::S_00c54550_Foo *>(this)->FUN_00c54550(fScaled);
    }
}
struct FUN_00c54cc0_cls
{
    float m_00;
    float m_04;
    float m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    bool FUN_00c54cc0(FUN_00c54cc0_cls* other);
};
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

struct FUN_00c54b70_cls
{
    void* m_vtbl;
    void* m_pBase;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_00c54850(unsigned int n);
    unsigned int FUN_00c54b70(NiIntegerStreamEntry& e);
public:
    void FUN_00c54a30(unsigned int idx, NiIntegerStreamEntry& e);
};
// Loads the extra data from the stream: reads a count, resizes entries, then reads and appends that many NiIntegerStreamEntry objects.
// @fnv 0x00c540a0
void NiIntegersExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    unsigned int count;
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(count));
    if (count)
    {
        reinterpret_cast<::FUN_00c54b70_cls *>(&(entries))->FUN_00c54850(count);
        struct Flags
        {
            unsigned short value;
            unsigned char tag;
        } flags;
        flags.value = 0;
        flags.tag = 255;
        NiIntegerStreamEntry streamEntry;
        for (unsigned int i = 0; i < count; ++i)
        {
            reinterpret_cast<::FUN_00c545d0_cls *>(&(streamEntry))->FUN_00c545d0(stream);
            reinterpret_cast<::FUN_00c54b70_cls *>(&(entries))->FUN_00c54b70(streamEntry);
            // Preserve the original frame's 176-byte unused local region.
            struct ReservedStreamLocals
            {
                unsigned int slot0;
                unsigned int slot1;
                unsigned int slot2;
                unsigned int slot3;
                unsigned int slot4;
                unsigned int slot5;
                unsigned int slot6;
                unsigned int slot7;
                unsigned int slot8;
                unsigned int slot9;
                unsigned int slot10;
                unsigned int slot11;
                unsigned int slot12;
                unsigned int slot13;
                unsigned int slot14;
                unsigned int slot15;
                unsigned int slot16;
                unsigned int slot17;
                unsigned int slot18;
                unsigned int slot19;
                unsigned int slot20;
                unsigned int slot21;
                unsigned int slot22;
                unsigned int slot23;
                unsigned int slot24;
                unsigned int slot25;
                unsigned int slot26;
                unsigned int slot27;
                unsigned int slot28;
                unsigned int slot29;
                unsigned int slot30;
                unsigned int slot31;
                unsigned int slot32;
                unsigned int slot33;
                unsigned int slot34;
                unsigned int slot35;
                unsigned int slot36;
                unsigned int slot37;
                unsigned int slot38;
                unsigned int slot39;
                unsigned int slot40;
                unsigned int slot41;
                unsigned int slot42;
                unsigned int slot43;
            } reserved;
        }
    }
}
// Calls FUN_00a7b330, then loops over count entries and passes each entry to FUN_00c54b70 on the stream's array at offset 0xc.
// @fnv 0x00c54040
void FUN_00c54040_cls::FUN_00c54040(NiStream& stream, uintptr_t flags)
{
    unsigned char pad[0x58];
    unsigned int i;
    unsigned int n;
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)&(stream), (::CloningProcess *)(flags));
    n = count;
    for (i = 0; i < n; i++)
    {
        reinterpret_cast<::FUN_00c54b70_cls *>((((NiIntegerStreamArray*)((char*)&stream + 0xc))))->FUN_00c54b70(*(NiIntegerStreamEntry*)(entries + (i << 4)));
    }
}

// @fnv 0x00c54b70
unsigned int FUN_00c54b70_cls::FUN_00c54b70(NiIntegerStreamEntry& aEntry)
{
    unsigned int scratch[0x16];
    unsigned int tmp;
    {
        unsigned int index = m_0a;
        if (index >= m_08)
        {
            FUN_00c54850(m_0e + index);
        }
        reinterpret_cast<::FUN_00c54a30 *>(this)->SetAt(index, (const ::ElemZ &)(aEntry));
        return index;
    }
}

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


// @fnv 0x00c54c50
FUN_00c54c50_shell* FUN_00c54c50_shell::FUN_00c54c50(unsigned short param_1, unsigned short param_2)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    this->vtbl = &::FNV_vtbl_NiTArrayBase;
    this->fld8 = param_1;
    this->fldE = param_2;
    this->fldA = 0;
    this->fldC = 0;

    if (this->fld8 > 0)
        this->ptr = FUN_00c54bc0(this->fld8);
    else
        this->ptr = 0;

    return this;
}


// Compares m_00, m_04, m_08, m_0e and m_0c against another instance and returns whether all match.
// @fnv 0x00c54cc0
bool FUN_00c54cc0_cls::FUN_00c54cc0(FUN_00c54cc0_cls* other)
{
    return (bool)(((m_00 == other->m_00) && (m_04 == other->m_04) && (m_08 == other->m_08)) ? 1 : 0) &&
           (m_0e == other->m_0e) && (m_0c == other->m_0c);
}

static const char* dummy = "";

struct NiPoint3
{
    float x, y, z;
    char* FUN_00a59af0(char const*);
};

struct Entry_00c542a0
{
    NiPoint3 pos;
    unsigned short heading;
    unsigned char number;
    unsigned char pad0f;
};

struct ViewerStringsArray
{
};

struct MarkerText_00c542a0
{
    int scratch0;
    int scratch1;
    int scratch2;
    int scratch3;
    float headingValue;
    int scratch5;
    int scratch6;
    int scratch7;
    int scratch8;
    int scratch9;
    unsigned int numberValue;
    int scratch11;
    int scratch12;
    int scratch13;
};

struct FUN_00c542a0_shell : NiExtraData
{
    unsigned int unk0c;
    Entry_00c542a0* entries;
    unsigned int unk14;
    unsigned short count;

    void FUN_00c542a0(ViewerStringsArray*);
};


// Appends marker count and per-marker number, position, and heading strings to the viewer strings array.
// @fnv 0x00c542a0
void FUN_00c542a0_shell::FUN_00c542a0(ViewerStringsArray* strings)
{
    unsigned long iMarkers;
    unsigned int aIndex;
    Entry_00c542a0* marker;
    char* aRtti;
    char* pMark;
    char* aPMarker;
    char* animationType;
    char* aCurrentPos;
    char* aHeadingY;
    intptr_t aNameValue;
    MarkerText_00c542a0 val;

    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(strings));

    aNameValue = (*reinterpret_cast<int *>(&::g_012031c4));
    aRtti = ::FUN_00a7d330((const char *)(aNameValue));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(aRtti));

    iMarkers = count;
    pMark = FUN_00a7d510("iMarks", iMarkers);
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(pMark));

    for (aIndex = 0; aIndex < iMarkers; ++aIndex)
    {
        aPMarker = FUN_00a7d510("Mark", aIndex);
        reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(aPMarker));

        marker = &entries[aIndex];
        val.numberValue = marker->number;
        animationType = FUN_00a7d510(" Number", val.numberValue);
        reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(animationType));

        aCurrentPos = marker->pos.FUN_00a59af0(" Pos");
        reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(aCurrentPos));

        val.headingValue = (float)(marker->heading / 1000.0);
        aHeadingY = FUN_00a7d550(" Heading", val.headingValue);
        reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(aHeadingY));
    }
}



// @fnv 0x00a99940
char const* const* __cdecl FUN_00a99940()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5f24));
}

struct FUN_00a7b300_shell
{
    void FUN_00a7b300();
};
struct FUN_00a99950_shell
{
    int vtbl;
    int f04;
    int f08;
    int f0c;
    int f10;
    void FUN_00a99950();
};
// @fnv 0x00a99950
void FUN_00a99950_shell::FUN_00a99950()
{
    void* p = *(void**)((char*)this + 0x10);
    *(intptr_t*)this = (intptr_t)&(*reinterpret_cast<int *>(&::fnv_00a99a50::DAT_010a0c7c));
    ::FUN_00aa10f0(p);
    this->f10 = 0;
    ((FUN_00a7b300_shell*)this)->FUN_00a7b300();
}

struct PB_00a7b2e0
{
};
struct PB_00a99800
{
};
struct ST_00a99980 : NiExtraData
{
    ST_00a99980* FUN_00a99980(int a, intptr_t b);
};
// @fnv 0x00a99980
ST_00a99980* ST_00a99980::FUN_00a99980(int a, intptr_t b)
{
    reinterpret_cast<::ExtraDataObject *>((((PB_00a7b2e0*)this)))->FUN_00a7b2e0();
    *(intptr_t*)this = (intptr_t)&(*reinterpret_cast<int *>(&::fnv_00a99a50::DAT_010a0c7c));
    *(int*)((char*)this + 0x10) = 0;
    reinterpret_cast<::FUN_00a99800_shell *>((((PB_00a99800*)this)))->AssignPointerArray(a, (const void *)(b));
    return this;
}

struct BSFadeNode
{
};
struct NiExtraDataShell : NiExtraData
{
};
// @fnv 0x00a99a10
NiExtraData* FUN_00a99a10()
{
    NiExtraData* data = static_cast<NiExtraData*>(::operator new(0x14));
    if (data)
    {
        reinterpret_cast<::ExtraDataObject *>((static_cast<NiExtraDataShell*>(data)))->FUN_00a7b2e0();
        data->baseData[0] = reinterpret_cast<uintptr_t>(&(*reinterpret_cast<int *>(&::fnv_00a99a50::DAT_010a0c7c)));
        data->baseData[4] = 0;
        data->baseData[3] = 0;
        return data;
    }
    return 0;
}

namespace fnv_00a99a50 {
void __cdecl FUN_00a7b300();
struct FUN_00a99a50_shell
{
    intptr_t vtbl;
    int a;
    int b;
    int c;
    intptr_t d;
    void FUN_00a7b300();
    FUN_00a99a50_shell* FUN_00a99a50(int);
};
// @fnv 0x00a99a50
FUN_00a99a50_shell* FUN_00a99a50_shell::FUN_00a99a50(int flag)
{
    vtbl = (intptr_t)&DAT_010a0c7c;
    ::FUN_00aa10f0((void*)d);
    d = 0;
    reinterpret_cast<::FUN_00a7b300_shell *>(this)->FUN_00a7b300();
    if (flag & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}
}  // namespace fnv_00a99a50

struct Extra_00a998e0
{
    unsigned char _pad0[12];
    unsigned int m_uiSize;
    int* m_piValue;
    bool FUN_00a998e0(Extra_00a998e0* pObject);
};
// @fnv 0x00a998e0
bool Extra_00a998e0::FUN_00a998e0(Extra_00a998e0* pObject)
{
    Extra_00a998e0* pExtra = pObject;
    unsigned int i;
    if (!pExtra)
        return false;
    if (m_uiSize != pExtra->m_uiSize)
        return false;
    if (m_piValue && !pExtra->m_piValue)
        return false;
    if (!m_piValue && pExtra->m_piValue)
        return false;
    if (m_piValue)
    {
        for (i = 0; i < m_uiSize; i++)
        {
            if (m_piValue[i] != pExtra->m_piValue[i])
                return false;
        }
    }
    return true;
}

struct FUN_00a99870_shell : public NiExtraData
{
    unsigned int m_uiSize;
    int* m_piValue;
    void FUN_00a99870(FUN_00a99870_shell* pDest, void* pCloning);
};
// @fnv 0x00a99870
void FUN_00a99870_shell::FUN_00a99870(FUN_00a99870_shell* pDest, void* pCloning)
{
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(pDest), (::CloningProcess *)(pCloning));
    if (m_piValue && m_uiSize > 0)
    {
        pDest->m_uiSize = m_uiSize;
        pDest->m_piValue = (int*)::FUN_00aa1070(m_uiSize * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pDest->m_piValue[i] = m_piValue[i];
    }
    else
    {
        pDest->m_piValue = 0;
        pDest->m_uiSize = 0;
    }
}

template <class T> class NiTPrimitiveArray
{
  public:
    void* m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    inline void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else if (element)
        {
            if (!m_pBase[uiIndex])
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex])
                m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
    inline unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
};

typedef NiTPrimitiveArray<char*> NiViewerStringsArray;



struct NiIntegersExtraDataView : NiExtraData
{
    unsigned int m_uiSize;
    int* m_piValue;
    void FUN_00a99b20(NiViewerStringsArray* pkStrings);
};

// @fnv 0x00a99b20
void NiIntegersExtraDataView::FUN_00a99b20(NiViewerStringsArray* pkStrings)
{
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f5f24))));
    pkStrings->Add(::FUN_00a7d510("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
        pkStrings->Add(::FUN_00a7d4d0("m_piValue[i]", m_piValue[i]));
}

class NiPSysBaseA99
{
  public:
    NiPSysBaseA99() throw();
    virtual ~NiPSysBaseA99();


    int unk04, unk08;
};

class NiPSysDerivedA99 : public NiPSysBaseA99
{
  public:
    NiPSysDerivedA99() throw()
    {
        m_pkSecond = 0;
        m_pkFirst = 0;
    }
    virtual ~NiPSysDerivedA99();

    void* m_pkFirst;
    void* m_pkSecond;
};

class NiPSysOwnerA99
{
  public:
    NiPSysBaseA99* FUN_00a999b0(void* pvProcess);
};

// @fnv 0x00a999b0
NiPSysBaseA99* NiPSysOwnerA99::FUN_00a999b0(void* pvProcess)
{
    NiPSysDerivedA99* pkClone = new NiPSysDerivedA99;
    reinterpret_cast<::FUN_00a99870_shell *>(this)->FUN_00a99870((::FUN_00a99870_shell *)(pkClone), pvProcess);
    return pkClone;
}

class NiExtraData;
class NiFixedString;
void* __cdecl FUN_00c54bc0(unsigned int);

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
};

// @fnv 0x00c54760
void FUN_00c54760()
{
    delete (NiFixedStringD*)DAT_012031c0;
    DAT_012031c0 = 0;
}

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
    static void* operator new[](std::size_t size)
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
    intptr_t handle;


    __forceinline NiFS(char const* s)
    {
        if (s == 0)
            handle = (*reinterpret_cast<int *>(&::DAT_0109b220));
        else
            handle = (intptr_t)::NiGlobalStringTable::AddString(s);
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

    bool operator!=(const NiIntStreamEntryC& kOther)
    {
        return !((FUN_00c54cc0_cls*)this)->FUN_00c54cc0((FUN_00c54cc0_cls*)&kOther);
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
            if (((NiIntStreamEntryC*)m_pBase)[i] != NiIntStreamEntryC(0))
            {
                ((NiIntStreamEntryC*)m_pBase)[i] = NiIntStreamEntryC(0);
                unk0c--;
            }
        }
        m_0a = (unsigned short)uiMaxSize;
    }

    NiIntStreamEntryC* pSaveBase = (NiIntStreamEntryC*)m_pBase;
    m_08 = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = ::FUN_00c54bc0(m_08);

        for (i = 0; i < m_0a; i++)
            ((NiIntStreamEntryC*)m_pBase)[i] = pSaveBase[i];

        for (i = m_0a; i < m_08; i++)
            ((NiIntStreamEntryC*)m_pBase)[i] = NiIntStreamEntryC(0);
    }
    else
    {
        m_pBase = 0;
    }

    NiIntStreamAllocatorC::Deallocate(pSaveBase);
}
#include "generated/data/gamebryo2.2/corelibs/nimain/niintegersextradata.inc"
