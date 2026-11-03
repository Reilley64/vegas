// gamebryo2.2/corelibs/nimain/niintegersextradata.cpp: NiIntegersExtraData, NiExtraDataSaveHelperShell (19 functions)

#include <cstdint>
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00c53fa0_Class.h"
#include "fnv/decl/FUN_00c54a30.h"
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
struct NiFixedString
{
};

struct NiAVObject
{
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

struct FUN_00c54b70_cls
{
    unsigned int unk00[2];
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_00c54850(unsigned int n);
    unsigned int FUN_00c54b70(NiIntegerStreamEntry& e);
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

struct FUN_00c54cc0_cls
{
    float m_00;
    float m_04;
    float m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    bool FUN_00c54cc0(FUN_00c54cc0_cls* other);
};

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

#include "generated/data/gamebryo2.2/corelibs/nimain/niintegersextradata.inc"
