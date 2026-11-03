
// src/staging/blk_00ce0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include "fnv/decl/fnv_00cd9d10__Q_00cd9d10.h"
#include <intrin.h>
#include <new>
#include <windows.h>
#include "fnv/decl/AttributeFormatter.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/D06D50Finder.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb24c0_cls.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cf6da0_cls.h"
#include "fnv/decl/HostWorld_00c951b0.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/ShapeData.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/Transform.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cde000.h"
#include "fnv/symbols_00cf4000.h"
#include "fnv/symbols_00cf6000.h"
#include "fnv/symbols_00d27000.h"
#include "fnv/symbols_00d86000.h"
#include "fnv/symbols_00d87000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_010cc000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include "fnv/decl/C97E80World.h"
#include "fnv/decl/Cls_c7f4e0.h"
#include "fnv/decl/FUN_00d86220_Class.h"
#include "fnv/symbols_00ce0000.h"
#include "fnv/symbols_00ce2000.h"
#include "fnv/symbols_00ce4000.h"
#include "fnv/symbols_00ce5000.h"
#include "fnv/symbols_00cf0000.h"
#include "fnv/symbols_00cf7000.h"
#include "fnv/symbols_00cfb000.h"
#include "fnv/symbols_00cfc000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/decl/Quat74.h"

extern int DAT_010cc164;
void __cdecl FUN_00d86220();

struct FUN_00cf45d0_class
{
    intptr_t vtable;
    FUN_00cf45d0_class();
};

// @fnv 0x00cf45d0
FUN_00cf45d0_class::FUN_00cf45d0_class()
{
    FUN_00d86220();
    vtable = (intptr_t)&DAT_010cc164;
}

struct hkReferencedObject
{
};

struct FUN_00cf4ca0_class
{
    int m_auiShapeKeys[6];
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    void FUN_00cf4ca0();
};

// @fnv 0x00cf4ca0
void FUN_00cf4ca0_class::FUN_00cf4ca0()
{
    if (m_kPointA)
        reinterpret_cast<::FUN_00c90510_class *>((m_kPointA))->FUN_00c90510();
    if (m_kPointB)
        reinterpret_cast<::FUN_00c90510_class *>((m_kPointB))->FUN_00c90510();
}

struct FUN_00d06d50_cls
{
};

// Calls FindClass on b with a; if it returns nonzero, passes a, the result and b to FUN_00cf6920.
// @fnv 0x00cf6950
void __cdecl FUN_00cf6950(intptr_t a, intptr_t apObject)
{
    intptr_t c = ((intptr_t)(reinterpret_cast<::D06D50Finder *>((((FUN_00d06d50_cls*)apObject)))->FindClass((const ::D06D50Object *)(a))));
    if (c)
        ::FUN_00cf6920((void *)(a), (::Node *)(c), (void *)(apObject));
}

struct FUN_00cf86f0_class
{
    int IsFieldEqual();
};

// @fnv 0x00cf86f0
int FUN_00cf86f0_class::IsFieldEqual()
{
    if (*(float*)((char*)this + 0x14) == *(float*)((char*)this + 0x20))
        return 1;
    return 0;
}

// @fnv 0x00cfcb80
unsigned short FUN_00cfcb80(unsigned short a, unsigned short b)
{
    unsigned short r = a;
    if (a < b)
        r = a;
    else
        r = b;
    return r;
}

extern int DAT_010cb864;
struct FUN_00ce4ae0_cls
{
};
struct FUN_00ce4a20_cls
{
    intptr_t m_kPointA;
    short m_kPointB;
    short m_iThirdValue;
    int m_iFourthElementInteger;
    intptr_t FUN_00ce4a20(intptr_t a);
};
extern int DAT_0102e378;
// @fnv 0x00cf69a0
void __cdecl FUN_00cf69a0(intptr_t* a)
{
    if (a)
        *a = (intptr_t)&DAT_0102e378;
}

struct FUN_00cf69c0_class
{
    intptr_t m_kPointA;
    int m_auiShapeKeys;
    intptr_t m_kPointB;
    intptr_t FUN_00cf69c0(intptr_t a);
};


// @fnv 0x00cf69c0
intptr_t FUN_00cf69c0_class::FUN_00cf69c0(intptr_t a)
{
    FUN_00cf69c0_class* self = this;
    for (;;)
    {
        if (self->m_kPointA && !::fnv_00cb0fa0::FUN_00cb0fa0((const char *)(a), (const char *)(self->m_kPointA)))
            return (intptr_t)self;
        if (!self->m_kPointB)
            return 0;
        self = (FUN_00cf69c0_class*)self->m_kPointB;
    }
}

struct FUN_00cf86e0_class
{
    void FUN_00cf86e0(float f);
};
// @fnv 0x00cf86e0
void FUN_00cf86e0_class::FUN_00cf86e0(float f)
{
    *(float*)((char*)this + 0x20) = *(float*)((char*)this + 0x14) + f;
}

extern int DAT_010cc2e0;

struct FUN_00cf4820_class
{
    int* vtbl;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00cf4820_class();
};

// @fnv 0x00cf4820
FUN_00cf4820_class::FUN_00cf4820_class()
{
    m1 = 0;
    m2 = 1;
    m3 = 0;
    m4 = 0;
    vtbl = &DAT_010cc2e0;
}


struct FUN_00cf86d0_cls
{
    void FUN_00cf86d0();
};

// @fnv 0x00cf86d0
void FUN_00cf86d0_cls::FUN_00cf86d0()
{
    *(intptr_t*)this = (intptr_t)&::DAT_0102e388;
}

// FUN_00ce29e0: member function that (re)initialises the object.
//   - installs the base vtable pointer at [this],
//   - calls the constructor of the sub-object living at this+0x10,
//   - then installs the vtable pointer of the derived class at [this].
extern int DAT_010cb864;

// Sub-object at +0x10; FUN_00ce5370 is the game's constructor for it.
struct FUN_00ce5370_cls
{
    void FUN_00ce5370();
};

struct FUN_00ce29e0_cls
{
    int* m_pVTable;          // +0x00
    int unk04;               // +0x04
    int unk08;               // +0x08
    int unk0C;               // +0x0C
    FUN_00ce5370_cls m_sub;  // +0x10
    void FUN_00ce29e0();
};

// @fnv 0x00ce29e0
void FUN_00ce29e0_cls::FUN_00ce29e0()
{
    m_pVTable = &DAT_010cb864;
    m_sub.FUN_00ce5370();
    m_pVTable = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct FnvSpawnedObject;

struct FnvProbe
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char* Check(FnvSpawnedObject** ref);
};

struct FnvSpawnedObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FnvProbe m_10;
    FnvProbe m_20;
    unsigned char* Check(FnvSpawnedObject** ref);
};

// Returns false if the first probe's Match or the object's Check fails, otherwise returns the result of the second probe's Check.
// @fnv 0x00ce2a00
bool __cdecl FUN_00ce2a00(int unused, FnvSpawnedObject* obj)
{
    FnvSpawnedObject* self = obj;
    if (*reinterpret_cast<::FUN_00cb24c0_cls *>(&(self->m_10))->IsNormalized((unsigned char *)(::FnvSpawnedObject **)(&obj)) == 0)
    {
        return false;
    }
    if (*self->Check(&obj) == 0)
    {
        return false;
    }
    return *self->m_20.Check(&obj) ? true : false;
}


// @fnv 0x00ce2cf0
void __cdecl FUN_00ce2cf0(intptr_t pObject, intptr_t param_2, intptr_t param_3)
{
    ::FUN_00ce2ca0((void *)(*reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(pObject) + 0x74)), (__m128 *)(param_3),
                 (const __m128 *)(int *)(reinterpret_cast<int*>(reinterpret_cast<char*>(pObject) + 0x40)), (const __m128 *)(param_2));
}



namespace fnv_00ce5370 {
extern "C" void _ReadWriteBarrier(void);

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    intptr_t unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct AudioObjectRef
{
};

struct FUN_00ce5370_cls
{
    AudioObjectRef* m_pObj0;
    AudioObjectRef* m_pObj4;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FUN_00ce5370();
};

// Frees the three arrays through the audio allocator, resets their counts, pointers and capacities, then releases and clears both object references.
// @fnv 0x00ce5370
void FUN_00ce5370_cls::FUN_00ce5370()
{
    AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    AudioHolder* pHolder2 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        pAllocator2->FreeArray(m_pDataB, (uCapB & 0x3fffffffu) * 0x70);
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    AudioHolder* pHolder3 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator3 = pHolder3->m_pAllocator;
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        pAllocator3->FreeArray(m_pDataC, (uCapC & 0x3fffffffu) * 0x40);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;

    _ReadWriteBarrier();
    AudioObjectRef* pObj4 = m_pObj4;
    if (pObj4 != 0)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((pObj4))->FUN_00c905b0();
    }
    m_pObj4 = 0;
    _ReadWriteBarrier();
    AudioObjectRef* pObj0 = m_pObj0;
    if (pObj0 != 0)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((pObj0))->FUN_00c905b0();
    }
    m_pObj0 = 0;
}
}  // namespace fnv_00ce5370

struct FnvKeyRec
{
    unsigned short m_iOwnerObjectOffset;
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
    int unk38;
    int unk3c;
};

struct FUN_00ce5480_cls
{
    int unk00;
    int unk04;
    FnvKeyRec* m_pRecords;
    int m_uiItemCount;
};

// @fnv 0x00ce5480
void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pKeyBox)
{
    for (int i = 0; i < pKeyBox->m_uiItemCount; i++)
    {
        if (pKeyBox->m_pRecords[i].m_iOwnerObjectOffset == aKey)
        {
            return &pKeyBox->m_pRecords[i];
        }
    }
    return 0;
}


struct DragBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(DragBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct DragStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    DragBinaryStreamView* m_pUnderlyingStream;
};

struct FUN_00cf4490_cls
{
    char unk00[0x14];
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    void FUN_00cf4490(void* stream);
};

// Reads three fields (m_14, m_18, m_1c) from the stream after calling FUN_00d86160.
// @fnv 0x00cf4490
void FUN_00cf4490_cls::FUN_00cf4490(void* stream)
{
    ::FUN_00d86160((*(::NiStreamD8616 *)(stream)), (::DataD8616 *)(void *)(this));
    DragStreamView* s = reinterpret_cast<DragStreamView*>(stream);
    s->m_pUnderlyingStream->Load(&m_14);
    s->m_pUnderlyingStream->Load(&m_18);
    s->m_pUnderlyingStream->Load(&m_1c);
}

struct CpuOpaque;
// @fnv 0x00cf45f0
CpuOpaque* __cdecl FUN_00cf45f0()
{
    return &(*reinterpret_cast<::CpuOpaque *>(&::g_01268740));
}

struct PacketSerializer
{
    int metadata, bytesWritten, reserved;
    typedef int(__cdecl* Fn)(PacketSerializer*, const void*, int, int*, int);
    Fn write;
};
struct SerializedObject
{
    int base00, base04, base08, base0C, base10, word14, word18;
    void SerializeToStream(intptr_t source);
};
// Writes word14 and word18 to the stream at source+0x250, accumulating bytesWritten, after calling FUN_00d86160.
// @fnv 0x00cf4670
void SerializedObject::SerializeToStream(intptr_t source)
{
    intptr_t saved = source;
    ::FUN_00d86160((*(::NiStreamD8616 *)(saved)), (::DataD8616 *)(::SerializedObject *)(this));
    PacketSerializer* __restrict stream = *reinterpret_cast<PacketSerializer**>(saved + 0x250);
    int size = 4;
    stream->bytesWritten += stream->write(stream, &word14, 4, &size, 1);
    stream = *reinterpret_cast<PacketSerializer**>(saved + 0x250);
    size = 4;
    stream->bytesWritten += stream->write(stream, &word18, 4, &size, 1);
}

// Save a Havok-wrapped object: write its type id, then let a type-specific saver write the rest.


struct CF4BC0AllocTagScope
{
    int m_iSaved;

    CF4BC0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CF4BC0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class CF4BC0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CF4BC0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CF4BC0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class CF4BC0Stream
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
    int unk0D8;
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
    int unk24C;
    CF4BC0BinaryStream* m_pBackingStream;
};

template <class T>
inline void CF4BC0BinaryStreamSave(CF4BC0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void CF4BC0SaveBinary(CF4BC0Stream& kStream, const T& value)
{
    CF4BC0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class CF4BC0Object
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual unsigned int GetSaveType();
};

class CF4BC0Saver
{
  public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void SaveBinary(CF4BC0Stream& kStream);

};


// @fnv 0x00cf4bc0
void __cdecl FUN_00cf4bc0(CF4BC0Stream& kStream, CF4BC0Object* pkObject)
{
    CF4BC0AllocTagScope kScope(0x10);
    unsigned int uiType = pkObject->GetSaveType();
    CF4BC0Saver* pkSaver = ((::CF4BC0Saver *)(::CreateSaver(uiType)));
    reinterpret_cast<::C89AC0_Owner *>((pkSaver))->SetChildObject((::C89AC0_Child *)(pkObject));
    CF4BC0SaveBinary(kStream, uiType);
    pkSaver->SaveBinary(kStream);
    pkSaver->DeleteThis(true);
}


struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    intptr_t unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct SubObject_b3813
{
    int unk00;
};

struct FUN_00cf4eb0_cls
{
    intptr_t m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    SubObject_b3813 m_sub;

    FUN_00cf4eb0_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00cf4eb0
FUN_00cf4eb0_cls* FUN_00cf4eb0_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (intptr_t)&DAT_010cc2fc;
    ::FUN_00cb0c00((intptr_t)&(m_sub));
    m_vptr = (intptr_t)&::DAT_0102e388;
    if (acFlags & 1)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}

struct S_00cf4f00
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
    short unk24;
    unsigned short m_uiItemCount;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned int m_bits[1];
    void ClearBit(unsigned int idx);
};
// Clears bit idx in the m_bits array and increments the counter if the bit was set.
// @fnv 0x00cf4f00
void S_00cf4f00::ClearBit(unsigned int auiBitIndex)
{
    unsigned int i = auiBitIndex >> 5;
    unsigned int old = m_bits[i];
    unsigned int nw = old & ~(1u << (auiBitIndex & 0x1f));
    if (old != nw)
    {
        m_bits[i] = nw;
        m_uiItemCount++;
    }
}

struct FUN_00cf4f30_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    short unk24;
    unsigned short counter;
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
    unsigned int bits[8];
    void SetBit(unsigned int index);
};
// Sets bit (index & 31) in bits[index >> 5] and decrements counter by one if the bit was not already set.
// @fnv 0x00cf4f30
void FUN_00cf4f30_class::SetBit(unsigned int index)
{
    unsigned int mask = 1u << (index & 31);
    unsigned int group = index >> 5;
    unsigned int old = bits[group];
    unsigned int updated = old | mask;
    if (old != updated)
    {
        bits[group] = updated;
        counter += 0xffff;
    }
}

struct FUN_00cf4f70_src
{
    int* m_00;
    int m_04;
};


class FUN_00cf4f70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    int unk20;
    unsigned short unk24;
    unsigned short m_26;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int m_50;

    void InitFromSource(FUN_00cf4f70_src* src);
};

// Copies src->m_04 ints from src->m_00 into the array at this+0x50, then stores m_1c minus CountBitsInWords(src->m_00, src->m_04) into m_26.
// @fnv 0x00cf4f70
void FUN_00cf4f70_cls::InitFromSource(FUN_00cf4f70_src* pSource)
{
    int* dst;
    int i = 0;
    if (pSource->m_04 > 0)
    {
        dst = &this->m_50;
        do
        {
            *dst = pSource->m_00[i];
            dst++;
            i++;
        } while (i < pSource->m_04);
    }
    int base = m_1c;
    int r = ::CountBitsInWords((const unsigned int *)(pSource->m_00), pSource->m_04);
    m_26 = (unsigned short)(base - r);
}

struct FUN_00cf6980_class
{
    virtual void FUN_00cf6980(int);
};

// @fnv 0x00cf6980
void __cdecl FUN_00cf6980(FUN_00cf6980_class* object)
{
    object->FUN_00cf6980(0);
}

// @fnv 0x00cf6990
int* __cdecl FUN_00cf6990()
{
    return &(*reinterpret_cast<int *>(&::g_01268748));
}

extern int DAT_0102e378;
// @fnv 0x00cf69b0
int* __cdecl FUN_00cf69b0()
{
    return &DAT_0102e378;
}

namespace fnv_00cf6b10 {

class SpawnedAllocator
{
  public:
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};


struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

// Allocates a 0x18-byte SpawnedObject via the holder's allocator, initializes it with count 0x3e8, and stores the result in DAT_01268794.
// @fnv 0x00cf6b10
void __cdecl FUN_00cf6b10()
{
    AllocHolder* pAllocHolder = static_cast<AllocHolder*>(::FUN_00c85750());
    SpawnedAllocator* alloc = pAllocHolder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x18);
    if (obj != 0)
    {
        ::DAT_01268794 = (::_RTL_CRITICAL_SECTION *)(reinterpret_cast<::FUN_00cf6da0_cls *>((obj))->FUN_00cf6da0(0x3e8));
        return;
    }
    ::DAT_01268794 = 0;
}
}  // namespace fnv_00cf6b10



struct S_00cf6b50_Foo
{
    int m_iWordAt00;
    short m_iWordAt04;
    unsigned short m_6;

    void UpdateState(int a);
};

// @fnv 0x00cf6b50
void S_00cf6b50_Foo::UpdateState(int a)
{
    short flag = m_iWordAt04;
    flag = (short)((unsigned short)flag >> 15);

    unsigned char byteFlag = (unsigned char)~flag;
    if ((byteFlag & 1) == 0)
    {
        return;
    }

    if (m_iWordAt00 == -63 || m_iWordAt00 == -31 || m_iWordAt00 == -15)
    {
        EnterCriticalSection(DAT_01268794);

        m_iWordAt00 = (a == 1) ? -31 : -63;
    }
    else
    {
        EnterCriticalSection(DAT_01268794);
    }

    m_6 <<= 1;
    ++m_iWordAt04;

    LeaveCriticalSection(DAT_01268794);
}

struct FUN_00cf6d50_cls
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void FUN_00cf6d50();
};

// @fnv 0x00cf6d50
void FUN_00cf6d50_cls::FUN_00cf6d50()
{
    m_04 &= 0x7fff;
}

struct FUN_00cf6f80_cls
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    unsigned __int64 FUN_00cf6f80();
};

// @fnv 0x00cf6f80
unsigned __int64 FUN_00cf6f80_cls::FUN_00cf6f80()
{
    return *(unsigned __int64*)&m_ucLowNibble;
}

// FUN_00cf8710 : thiscall member returning a bool.
//
// Original shape (24 bytes):
//   fld  dword ptr [ecx+0x18]
//   fld  dword ptr [ecx+0x14]
//   fucompp
//   fnstsw ax
//   test ah,0x44
//   jp   <not equal>
//   mov  eax,1
//   ret
//   <not equal>: xor eax,eax ; ret
//
// i.e. a plain float equality test between the two float members at +0x14 and
// +0x18 of the object, with the +0x18 member loaded first.

struct FUN_00cf8710_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float m_14;
    float m_18;

    bool FUN_00cf8710();
};

// @fnv 0x00cf8710
bool FUN_00cf8710_cls::FUN_00cf8710()
{
    return m_18 == m_14;
}

class MemoryManager
{
  public:
};

class CF4840Saver
{
  public:
    virtual void DeleteThis(bool bFree);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct Saver00 : CF4840Saver
{
    Saver00() throw();
};
struct Saver01 : CF4840Saver
{
    Saver01() throw();
};
struct Saver02 : CF4840Saver
{
    Saver02() throw();
};
struct Saver03 : CF4840Saver
{
    Saver03() throw();
};
struct Saver06 : CF4840Saver
{
    Saver06() throw();
};
struct Saver07 : CF4840Saver
{
    Saver07() throw();
};
struct Saver08 : CF4840Saver
{
    Saver08() throw();
};
struct Saver09 : CF4840Saver
{
    Saver09() throw();
};
struct Saver10 : CF4840Saver
{
    Saver10() throw();
};
struct Saver12 : CF4840Saver
{
    Saver12() throw();
};
struct Saver13 : CF4840Saver
{
    Saver13() throw();
};

// Allocates and returns a CF4840Saver-derived object chosen by uiType, or null for unsupported types.
// @fnv 0x00cf4840
CF4840Saver* __cdecl CreateSaver(uintptr_t uiType)
{
    CF4BC0AllocTagScope kScope(0x10);
    switch (uiType)
    {
    case 0:
        return new Saver00;
    case 1:
        return new Saver01;
    case 2:
        return new Saver02;
    case 3:
        return new Saver03;
    case 6:
        return new Saver06;
    case 7:
        return new Saver07;
    case 8:
        return new Saver08;
    case 9:
        return new Saver09;
    case 10:
        return new Saver10;
    case 12:
        return new Saver12;
    case 13:
        return new Saver13;
    }
    return 0;
}

// Build the Havok object for a serialized node: find its creator, run it, keep the result and delete the creator.


struct F4A30AllocTagScope
{
    int m_iSaved;

    F4A30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~F4A30AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class F4A30Result
{
  public:
};

class F4A30Node
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual int GetTypeID();
};

class F4A30Creator
{
  public:
    virtual ~F4A30Creator();
    virtual void Create(int iFlags, void* pvContext);


    F4A30Result* m_pkResult;
};


// @fnv 0x00cf4a30
F4A30Result* CreateF4A30Result(F4A30Node* pkNode, void* pvContext)
{
    F4A30AllocTagScope kScope(0x10);
    F4A30Creator* pkCreator = ((::F4A30Creator *)(::CreateSaver(pkNode->GetTypeID())));
    if (pkCreator)
    {
        reinterpret_cast<::C89AC0_Owner *>((pkCreator))->SetChildObject((::C89AC0_Child *)(pkNode));
        pkCreator->Create(0, pvContext);
        F4A30Result* pkResult = pkCreator->m_pkResult;
        reinterpret_cast<::FUN_00c90510_class *>((pkResult))->FUN_00c90510();
        delete pkCreator;
        return pkResult;
    }
    return 0;
}

// @fnv 0x00ce5300
void __cdecl FUN_00ce5300()
{
    static_cast<struct ::Transform *>(nullptr)->FUN_00ce51f0({});
}

class FUN_00ce5360_This
{
  public:
    virtual ~FUN_00ce5360_This()
    {}
    uintptr_t FUN_00ce5360(uintptr_t arg);
};

// @fnv 0x00ce5360
uintptr_t FUN_00ce5360_This::FUN_00ce5360(uintptr_t arg)
{
    return reinterpret_cast<uintptr_t>(this);
}

class FUN_00ce9800_obj
{
  public:
    virtual ~FUN_00ce9800_obj();
};

// @fnv 0x00ce9800
void __cdecl DeleteObjectIfNotNull(FUN_00ce9800_obj* pkObject)
{
    if (pkObject)
        delete pkObject;
}

struct FUN_00ce9820_vt
{
    virtual void FUN_00ce9820_v0(int a);
    virtual void FUN_00ce9820_v1(int a);
};
// @fnv 0x00ce9820
void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* pObject)
{
    if (pObject)
        pObject->FUN_00ce9820_v0(1);
}

struct Stream;
typedef int (*StreamIOFunc)(Stream* stream, void* data, int size, int* count, int flag);

struct Stream
{
    int unk00;
    int pos;
    int unk08;
    StreamIOFunc io;
};

struct StreamOwner
{
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
    int unk0D8;
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
    int unk24C;
    Stream* stream;
};

struct Record
{
    int unk00;
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
};

static inline void WriteData(Stream* s, void* data, int size)
{
    int count = size;
    s->pos += s->io(s, data, size, &count, 1);
}

// Writes each 4-byte field of the Record to the owner's stream via WriteData, skipping unk0C.
// @fnv 0x00cf09a0
void FUN_00cf09a0(StreamOwner* owner, Record* rec)
{
    WriteData(owner->stream, &rec->unk00, 4);
    WriteData(owner->stream, &rec->unk04, 4);
    WriteData(owner->stream, &rec->unk08, 4);
    WriteData(owner->stream, &rec->unk10, 4);
    WriteData(owner->stream, &rec->unk14, 4);
    WriteData(owner->stream, &rec->unk18, 4);
    WriteData(owner->stream, &rec->unk1C, 4);
    WriteData(owner->stream, &rec->unk20, 4);
    WriteData(owner->stream, &rec->unk24, 4);
    WriteData(owner->stream, &rec->unk28, 4);
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct ArrayData
{
    unsigned int* m_data;
    int m_iElementCount;
};

// @fnv 0x00cf0e90
extern "C" unsigned int __cdecl SaveUIntArray(CF4BC0Stream& kStream, const ArrayData& kArray)
{
    unsigned int count = kArray.m_iElementCount;
    CF4BC0SaveBinary(kStream, count);

    unsigned int totalSize = count * sizeof(unsigned int);
    int i = 0;
    if ((int)count > 0)
    {
        do
        {
            unsigned int val = kArray.m_data[i];
            if ((unsigned char)kStream.unk1E4 != 1)
            {
                val = _byteswap_ulong(val);
            }
            CF4BC0SaveBinary(kStream, val);
            ++i;
        } while (i < (int)count);
    }

    return totalSize;
}

extern int DAT_010cc064;
struct FUN_00cdf560
{
    intptr_t m0;
    int m4;
    int m8;
    FUN_00cdf560(float);
};
struct FUN_00cf4190 : FUN_00cdf560
{
    FUN_00cf4190();
};
// @fnv 0x00cf4190
FUN_00cf4190::FUN_00cf4190() : FUN_00cdf560(0.0f)
{
    m0 = (intptr_t)&DAT_010cc064;
}


// @fnv 0x00cf41b0
int* FUN_00cf41b0()
{
    return &(*reinterpret_cast<int *>(&::g_01268730));
}


struct BinaryStream
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest)
    {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, sizeof(T), &byteCount, 1);
    }
};
struct StreamView
{
    BinaryStream* stream()
    {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};
struct SerializedRecord
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int m_14, m_18, m_1c, m_20;
    void FUN_00cf41c0(StreamView* view);
};
// Calls FUN_00d86100 with the view and this record, then loads m_14, m_18, m_1c and m_20 from the view's stream.
// @fnv 0x00cf41c0
void SerializedRecord::FUN_00cf41c0(StreamView* view)
{
    ::FUN_00d86100((*(::NiStreamD861 *)(view)), (::DataD861 *)(void *)(this));
    view->stream()->Load(&m_14);
    view->stream()->Load(&m_18);
    view->stream()->Load(&m_1c);
    view->stream()->Load(&m_20);
}

struct CpuOpaque;
// @fnv 0x00cf43f0
CpuOpaque* __cdecl FUN_00cf43f0()
{
    return &(*reinterpret_cast<::CpuOpaque *>(&::g_01268738));
}

class NiBinaryStreamCF46
{
  public:
    typedef unsigned int (*WriteFn)(NiBinaryStreamCF46* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                    unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    WriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

template <class T> inline void NiStreamSaveBinaryCF46(NiBinaryStreamCF46& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

struct hkArchiveCF46
{
    int unk000[0x93];
    NiBinaryStreamCF46* m_stream;
};


class hkObjCF46
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_kPointA;
    int m_kPointB;

    void SaveToArchive(hkArchiveCF46* ar);
};

// @fnv 0x00cf4600
void hkObjCF46::SaveToArchive(hkArchiveCF46* ar)
{
    ::FUN_00d86100((*(::NiStreamD861 *)(ar)), (::DataD861 *)(void *)(this));
    NiStreamSaveBinaryCF46(*ar->m_stream, m_kPointA);
    NiStreamSaveBinaryCF46(*ar->m_stream, m_kPointB);
}



struct hkCriticalSectionCF6B
{
    CRITICAL_SECTION m_kCriticalSection;
};

struct hkCriticalSectionLockCF6B
{
    hkCriticalSectionCF6B* m_kCriticalSection;
    hkCriticalSectionLockCF6B(hkCriticalSectionCF6B* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6B()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF6B
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void MarkForRead();
};

// @fnv 0x00cf6bc0
void hkMultiThreadCheckCF6B::MarkForRead()
{
    if (isCheckingEnabled())
    {
        hkCriticalSectionLockCF6B lock((hkCriticalSectionCF6B*)DAT_01268794);
        unsigned int threadId = ((unsigned int)(::FUN_00d87a40()));
        m_usMarkedForWrite++;
        m_usMarkCount = (m_usMarkCount << 1) | 1;
        if (m_uiThreadId == 0xfffffff1)
            m_uiThreadId = threadId;
    }
}



struct hkCriticalSectionCF61
{
    CRITICAL_SECTION m_kCriticalSection;
};

struct hkCriticalSectionLockCF61
{
    hkCriticalSectionCF61* m_kCriticalSection;
    hkCriticalSectionLockCF61(hkCriticalSectionCF61* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF61()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF61
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    bool IsCurrentThreadOwner();
};

// Returns true if multithread checking is disabled or the stored thread id matches the current thread id, otherwise false.
// @fnv 0x00cf6c10
bool hkMultiThreadCheckCF61::IsCurrentThreadOwner()
{
    if (!isCheckingEnabled())
        return true;
    hkCriticalSectionLockCF61 lock((hkCriticalSectionCF61*)DAT_01268794);
    if (m_uiThreadId == ((unsigned int)(::FUN_00d87a40())))
        return true;
    return false;
}


struct hkCriticalSectionCF6C
{
    CRITICAL_SECTION m_kCriticalSection;
};

struct hkCriticalSectionLockCF6C
{
    hkCriticalSectionCF6C* m_kCriticalSection;
    hkCriticalSectionLockCF6C(hkCriticalSectionCF6C* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6C()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF6C
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void FUN_00cf6c60();
};

// @fnv 0x00cf6c60
void hkMultiThreadCheckCF6C::FUN_00cf6c60()
{
    if (isCheckingEnabled())
    {
        hkCriticalSectionLockCF6C lock((hkCriticalSectionCF6C*)DAT_01268794);
        m_usMarkCount >>= 1;
        m_usMarkedForWrite--;
        if (m_usMarkedForWrite == 0)
            m_uiThreadId = 0xfffffff1;
    }
}


struct hkCriticalSectionCF6D
{
    CRITICAL_SECTION m_kCriticalSection;
};

struct hkCriticalSectionLockCF6D
{
    hkCriticalSectionCF6D* m_kCriticalSection;
    hkCriticalSectionLockCF6D(hkCriticalSectionCF6D* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6D()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF6D
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void FUN_00cf6cb0();
};

// @fnv 0x00cf6cb0
void hkMultiThreadCheckCF6D::FUN_00cf6cb0()
{
    if (isCheckingEnabled())
    {
        hkCriticalSectionLockCF6D lock((hkCriticalSectionCF6D*)DAT_01268794);
        m_usMarkCount >>= 1;
        m_usMarkedForWrite--;
        if (m_usMarkedForWrite == 0)
            m_uiThreadId = 0xfffffff1;
    }
}

struct hkMultiThreadCheckCF6E
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void ResetThreadCheck();
};

// @fnv 0x00cf6d30
void hkMultiThreadCheckCF6E::ResetThreadCheck()
{
    if (!isCheckingEnabled())
    {
        m_uiThreadId = 0xfffffff1;
        m_usMarkedForWrite = 0;
    }
}

struct CC9F10Shape
{
};

struct FUN_00cf7490_class
{
    void FUN_00cf7490();
};

// @fnv 0x00cf7490
void FUN_00cf7490_class::FUN_00cf7490()
{
    reinterpret_cast<::FUN_00c90510_class *>((((CC9F10Shape*)this)))->FUN_00c90510();
}

// @fnv 0x00cf74a0
void __cdecl FUN_00cf74a0(void)
{
    static_cast<::hkReferencedObjectC905 *>(nullptr)->FUN_00c905b0();
}

struct hkOwnerCF74;

struct hkEntryCF74
{
    hkOwnerCF74* m_pOwnerObject;
    int unk04;
    unsigned int m_08;
};

struct hkOwnerCF74
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0;
    unsigned int m_d4;
};

// @fnv 0x00cf74b0
int __cdecl FUN_00cf74b0(const hkEntryCF74& aEntryA, const hkEntryCF74& aEntryB)
{
    if (aEntryA.m_pOwnerObject == aEntryB.m_pOwnerObject)
        return aEntryA.m_08 > aEntryB.m_08;
    return aEntryA.m_pOwnerObject->m_d4 < aEntryB.m_pOwnerObject->m_d4;
}

struct hkBoolCF74
{
    char m_cBooleanValue;
    hkBoolCF74()
    {}
    hkBoolCF74(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkQualityCF74
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_priority;
};

struct hkEntityCF74
{
    int unk00;
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
    hkQualityCF74* m_quality;
};

struct hkPairCF74
{
    int unk00;
    hkEntityCF74* m_kPointA;
    hkEntityCF74* m_kPointB;
};

// Compares two pairs by their entities' quality priority, falling back to the second entity's priority when the first priorities are equal.
// @fnv 0x00cf74e0
hkBoolCF74 __cdecl LessThanPairPriority(const hkPairCF74& aPairA, const hkPairCF74& aPairB)
{
    unsigned int a = aPairA.m_kPointA->m_quality->m_priority;
    unsigned int b = aPairB.m_kPointA->m_quality->m_priority;
    return a < b || (a == b && aPairA.m_kPointB->m_quality->m_priority < aPairB.m_kPointB->m_quality->m_priority);
}

// @fnv 0x00cfb050
void* __cdecl FUN_00cfb050(void* pvUnused, bool* pbOut, void* pvResult)
{
    *pbOut = false;
    return pvResult;
}

// @fnv 0x00cfb060
void FUN_00cfb060()
{}

// @fnv 0x00cfb070
int __cdecl FUN_00cfb070(int a, int b, int c)
{
    return c;
}

// @fnv 0x00cfc580
void FUN_00cfc580(int, int, int, int, int)
{}


struct FUN_00cfc590_class
{
    int* vtable;

    void FUN_00cfc590();
};

// @fnv 0x00cfc590
void FUN_00cfc590_class::FUN_00cfc590()
{
    vtable = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

extern int DAT_010cc86c;

struct S_00cfc5a0
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short unkA8;
    unsigned short unkAA;
};

struct FUN_00cfc5a0
{
    int* vtbl;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    S_00cfc5a0* unk10;
    S_00cfc5a0* unk14;
    unsigned short unk18;

    FUN_00cfc5a0(int a1, S_00cfc5a0* a2, S_00cfc5a0* a3);
};

// Sets up the object with a1, stores a2 and a3, and records the smaller of their unkAA values in unk18.
// @fnv 0x00cfc5a0
FUN_00cfc5a0::FUN_00cfc5a0(int aiValue, S_00cfc5a0* apFirst, S_00cfc5a0* apSecond)
{
    unk06 = 1;
    unk08 = 1;
    vtbl = &DAT_010cc86c;
    unsigned short w3 = apSecond->unkAA;
    unsigned short w2 = apFirst->unkAA;
    unsigned short chosen = w2 < w3 ? w2 : w3;
    unk10 = apFirst;
    unk14 = apSecond;
    unk18 = chosen;
    unk0c = aiValue;
}

// @fnv 0x00cfdb40
void FUN_00cfdb40()
{}

// Per-thread profiler ring: TlsGetValue(index) -> buffer with head@+4 / end@+0xc,
// 0xc-byte events {tag, timestamp, pad}.
struct CE0020Event
{
    const char* m_pTag;
    unsigned int m_uiEventId;
    int m_unk08;
};
struct CE0020Buffer
{
    int m_unk00;
    CE0020Event* m_pHead;
    int m_unk08;
    CE0020Event* m_pRecordEnd;
};

extern char DAT_010cb81c[];
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

__forceinline void CE0020TimerMark(const char* pTag)
{
    CE0020Buffer* pBuffer = (CE0020Buffer*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    CE0020Event* pEvent = pBuffer->m_pHead;
    if (pEvent < pBuffer->m_pRecordEnd)
    {
        pEvent->m_pTag = pTag;
        _ReadWriteBarrier();
        volatile unsigned int uiStamp = (unsigned int)__rdtsc();
        pEvent->m_uiEventId = uiStamp;
        pBuffer->m_pHead = pEvent + 1;
    }
}

// 4-byte flags struct passed by value (bool first member).
class CE0020Flag
{
  public:
    bool m_bEnableState;
    unsigned char m_unk01;
    unsigned char m_unk02;
    unsigned char m_unk03;
};
class CE0020ZeroInfo
{
  public:
    int m_unk00;
    int m_iArrayLength;
};
class CE0020Holder
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Fill(CE0020Flag kFlags, CE0020ZeroInfo* pInfo);
};
class CE0020Arrays
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    float* m_pFloats;
};
class CE0020Target
{
  public:
    int unk00, unk04, unk08;
    CE0020Holder* m_pHolder;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    CE0020Arrays* m_pArrayData;
};
class CE0020Subject
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void EnableConstraints();
};


// @fnv 0x00ce0020
void __cdecl EnableConstraintsAndZeroArrays(CE0020Target* pTarget, CE0020Subject* pSubject)
{
    pSubject->EnableConstraints();
    CE0020TimerMark(DAT_010cb81c);
    ::FUN_00d27690((::D27690_Instance *)(pTarget), (::D27690_Owner *)(pSubject), 0x1b);
    float* pFloats = pTarget->m_pArrayData->m_pFloats;
    if (pFloats)
    {
        CE0020Flag kFlags;
        CE0020ZeroInfo kInfo;
        kFlags.m_bEnableState = true;
        pTarget->m_pHolder->Fill(kFlags, &kInfo);
        double dZero = 0.0;
        for (int i = 0; i < kInfo.m_iArrayLength; i++)
        {
            pFloats[2 * i] = (float)dZero;
            pFloats[2 * i + 1] = (float)dZero;
        }
    }
    CE0020TimerMark(DAT_010c41f8);
}

void __cdecl FUN_00ce2d10();

// @fnv 0x00ce2f30
void __cdecl FUN_00ce2f30()
{
    FUN_00ce2d10();
}

struct NiBinaryStreamCF42
{
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCF42* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiStreamLoadBinaryCF42(NiBinaryStreamCF42& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}

struct NiStreamCF42
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
    int unk240, unk244, unk248, unk24C;
    NiBinaryStreamCF42* m_pUnderlyingStream;

    NiBinaryStreamCF42* GetIstr()
    {
        return m_pUnderlyingStream;
    }
};

class SerializableCF42;

class SerializableCF42
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned int m_uiValue1C;
    unsigned int m_uiValue20;

    void FUN_00cf4260(NiStreamCF42& kStream);
};

// Calls FUN_00d86160 then reads four unsigned int fields from the stream's underlying binary stream.
// @fnv 0x00cf4260
void SerializableCF42::FUN_00cf4260(NiStreamCF42& kStream)
{
    ::FUN_00d86160((::NiStreamD8616 &)(kStream), (::DataD8616 *)(::SerializableCF42 *)(this));
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue14);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue18);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue1C);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue20);
}

// bhkVelocityConstraintMotor ctor (hkpVelocityConstraintMotor chain):
// vptr(0), memSizeAndFlags(4), referenceCount(6), motor type(8), min/max force, tau, damping, velocity-clamp bool.
extern const void* DAT_010cc0ec[];

extern "C" void _ReadWriteBarrier();

struct hkBoolC43
{
    char v;
};

class FUN_00cf43b0
{
  public:
    const void** m_vftable;              // 0x00
    unsigned short m_usMemSizeAndFlags;  // 0x04
    unsigned short m_sReferenceCount;    // 0x06
    unsigned char m_motorType;           // 0x08
    char unk09;
    char unk0A;
    char unk0B;
    float m_fMinForce;        // 0x0c
    float m_fMaxForce;        // 0x10
    float m_fTau;             // 0x14
    float m_fMotorDamping;    // 0x18
    char m_useVelocityClamp;  // 0x1c

    FUN_00cf43b0();
};

// Initializes a motor with default force limits, damping, tau, and velocity clamp settings, and sets its vftable.
// @fnv 0x00cf43b0
FUN_00cf43b0::FUN_00cf43b0()
{
    m_sReferenceCount = 1;
    m_fMinForce = -1000000.0f;
    m_fMaxForce = 1000000.0f;
    hkBoolC43 kClamp = {};
    m_motorType = 2;
    m_fMotorDamping = 1.0f;
    m_fTau = 0.8f;
    _ReadWriteBarrier();
    m_useVelocityClamp = kClamp.v;
    _ReadWriteBarrier();
    m_vftable = DAT_010cc0ec;
}

struct NiBinaryStreamCF44
{
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCF44* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiStreamLoadBinaryCF44(NiBinaryStreamCF44& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}

struct NiStreamCF44
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
    NiBinaryStreamCF44* m_pUnderlyingStream;

    NiBinaryStreamCF44* GetIstr()
    {
        return m_pUnderlyingStream;
    }
};

class SerializableCF44;

class SerializableCF44
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned char m_ucValue1C;

    void FUN_00cf4400(NiStreamCF44& kStream);
};

// Calls FUN_00d86100, then reads m_uiValue14, m_uiValue18, and m_ucValue1C from the stream via NiStreamLoadBinaryCF44.
// @fnv 0x00cf4400
void SerializableCF44::FUN_00cf4400(NiStreamCF44& kStream)
{
    ::FUN_00d86100((::NiStreamD861 &)(kStream), (::DataD861 *)(::SerializableCF44 *)(this));
    NiStreamLoadBinaryCF44(*kStream.GetIstr(), m_uiValue14);
    NiStreamLoadBinaryCF44(*kStream.GetIstr(), m_uiValue18);
    NiStreamLoadBinaryCF44(*kStream.GetIstr(), m_ucValue1C);
}

struct CF4BC0StreamInput
{
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
    int unk0D8;
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
    CF4BC0BinaryStream* m_pUnderlyingStream;
    CF4BC0BinaryStream* m_pBackingStream;
};

class CF4BC0BinaryStreamIn
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CF4BC0BinaryStreamIn*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Load(T* value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, value, sizeof(T), &uiSize, 1);
    }
};

class CF4BC0SaverLoader
{
  public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void LoadBinary(CF4BC0Stream& kStream);
    virtual void SaveBinary(CF4BC0Stream& kStream);
    hkReferencedObject* m_pPointer;
};

struct TagState
{
    int oldTag;
    int newTag;
};
__forceinline TagState GetTag(int tag)
{
    TagState state = {(*reinterpret_cast<int *>(&::currentAllocationContext)), tag};
    return state;
}
struct AllocScope
{
    int saved;
    AllocScope(TagState t) : saved(t.oldTag)
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = t.newTag;
    }
    ~AllocScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = saved;
    }
};
// Reads a type ID from the stream, creates a saver, loads its binary data, and returns the retained object pointer.
// @fnv 0x00cf4af0
hkReferencedObject* __cdecl FUN_00cf4af0(CF4BC0Stream& kStream)
{
    AllocScope kAllocTag(GetTag(16));
    CF4BC0StreamInput& kIn = (CF4BC0StreamInput&)kStream;
    CF4BC0BinaryStreamIn* pIstr = (CF4BC0BinaryStreamIn*)kIn.m_pUnderlyingStream;
    unsigned int uiType;
    pIstr->Load(&uiType);
    CF4BC0Saver* pSaver = ((::CF4BC0Saver *)(::CreateSaver(uiType)));
    if (pSaver)
    {
        CF4BC0SaverLoader* pLoader = (CF4BC0SaverLoader*)pSaver;
        pLoader->LoadBinary(kStream);
        hkReferencedObject* pObject = pLoader->m_pPointer;
        reinterpret_cast<::FUN_00c90510_class *>((pObject))->FUN_00c90510();
        pSaver->DeleteThis(true);
        return pObject;
    }
    return 0;
}

// @fnv 0x00cf6d10
__declspec(noinline) void FUN_00cf6d10()
{}

class hkBaseObject
{
  public:
    virtual ~hkBaseObject()
    {}
};

class hkRefObjCF70 : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpBroadPhaseListener
{
  public:
    virtual ~hkpBroadPhaseListener()
    {}
    virtual void AddCollisionPair(void* pair) = 0;
    virtual void RemoveCollisionPair(void* pair) = 0;
};

class ListenerCF70 : public hkRefObjCF70, public hkpBroadPhaseListener
{
  public:
    virtual void AddCollisionPair(void* pair);
    virtual void RemoveCollisionPair(void* pair);
};

class FUN_00cf7060
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC;
    ListenerCF70 m_kListener;

    ~FUN_00cf7060();
};

// @fnv 0x00cf7060
FUN_00cf7060::~FUN_00cf7060()
{}


struct __declspec(align(16)) CE5430Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void SetAllComponents(float f)
    {
        m_vComponents = _mm_set_ps1(f);
    }
};

struct __declspec(align(16)) CE5430Quaternion
{
    __m128 m_vec;

    void setIdentity()
    {
        m_vec = ::DAT_010c71b0;
    }
};

struct __declspec(align(16)) CE5430QsTransform
{
    CE5430Vector4 m_vTranslation;
    CE5430Quaternion m_rotation;
    CE5430Vector4 m_vScale;

    void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.setIdentity();
        m_vScale.SetAllComponents(1.0f);
    }
};

struct __declspec(align(16)) CE5430Pose
{
    short m_sIndex0;
    short m_sIndex1;
    short m_sIndex2;
    short m_sIndex3;
    int unk08;
    int unk0C;
    CE5430QsTransform m_kTransform0;
    CE5430QsTransform m_kTransform1;

    void SetIdentity();
};

// Resets the pose indices to zero and sets both transforms to their identity state.
// @fnv 0x00ce5430
void CE5430Pose::SetIdentity()
{
    m_sIndex0 = 0;
    m_sIndex1 = 0;
    m_sIndex2 = 0;
    m_sIndex3 = 0;
    m_kTransform0.setIdentity();
    m_kTransform1.setIdentity();
}

struct __declspec(align(16)) hkVector4CE98
{
    __m128 m_vComponents;

    void operator=(const hkVector4CE98& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkElementCE98
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    hkVector4CE98 m_vector;
};

// Copies the m_vector field from pkSrc to pkDst for iCount elements.
// @fnv 0x00ce9840
void __cdecl CopyVectors(hkElementCE98* pkDst, const hkElementCE98* pkSrc, int iCount)
{
    for (int i = 0; i < iCount; i++)
        pkDst[i].m_vector = pkSrc[i].m_vector;
}

struct FUN_00cf0820
{
    float field00;
    float field04;
    unsigned int unk08;
    unsigned int unk0c;
    __m128 field10;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    FUN_00cf0820(const FUN_00cf0820& input);
};
// Copy constructor: copies field00, field04, field10, field20, field30 and field40 from input, leaving unk08 and unk0c unset.
// @fnv 0x00cf0820
FUN_00cf0820::FUN_00cf0820(const FUN_00cf0820& input)
{
    field00 = input.field00;
    field04 = input.field04;
    field10 = input.field10;
    field20 = input.field20;
    field30 = input.field30;
    field40 = input.field40;
}

struct FUN_00cf08c0_VectorArray
{
    float* values;
    int count;
};
// Returns true when both arrays have the same count and every component differs by at most the tolerance DAT_01017d00.
// @fnv 0x00cf08c0
bool __cdecl FUN_00cf08c0(const FUN_00cf08c0_VectorArray* left, const FUN_00cf08c0_VectorArray* right)
{
    bool equal = left->count == right->count;
    if (equal)
    {
        int i = 0;
        if (i < left->count)
        {
            const __m128 absoluteMask = _mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_01017d10)));
            for (; i < left->count && equal; ++i)
            {
                __m128 delta = _mm_sub_ps(_mm_load_ps(left->values + 4 * i), _mm_load_ps(right->values + 4 * i));
                __m128 tolerance = _mm_load1_ps(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
                __m128 absoluteDelta = _mm_and_ps(delta, absoluteMask);
                int bits = _mm_movemask_ps(_mm_cmple_ps(absoluteDelta, tolerance));
                equal = (bits & 15) == 15;
            }
        }
    }
    return equal;
}

struct BinaryStreamCF0
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(BinaryStreamCF0*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest, unsigned int uiBytes)
    {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, uiBytes, &byteCount, 1);
    }
};

struct StreamViewCF0
{
    BinaryStreamCF0* stream()
    {
        return *reinterpret_cast<BinaryStreamCF0**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};

struct hkVector4CF0
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct hkMatrixCF0
{
    hkVector4CF0 m_kColumn0;
    hkVector4CF0 m_kColumn1;
    hkVector4CF0 m_kColumn2;
};

// Reads 10 floats from the view's stream into pkDest's columns: x,y,z for columns 0 and 2 (w set to 0) and x,y,z,w for column 1.
// @fnv 0x00cf0b00
void __cdecl FUN_00cf0b00(StreamViewCF0* pkView, hkMatrixCF0* pkDest)
{
    int n = 4;
    unsigned int sz;
    float x, y, z, w;
    BinaryStreamCF0* bs;
    pkView->stream()->Load(&x, n);
    pkView->stream()->Load(&y, n);
    pkView->stream()->Load(&z, n);
    pkDest->m_kColumn0.set(x, y, z, 0.0f);
    pkView->stream()->Load(&x, n);
    pkView->stream()->Load(&y, n);
    pkView->stream()->Load(&z, n);
    pkView->stream()->Load(&w, n);
    pkDest->m_kColumn1.set(x, y, z, w);
    pkView->stream()->Load(&x, n);
    pkView->stream()->Load(&y, n);
    pkView->stream()->Load(&z, n);
    pkDest->m_kColumn2.set(x, y, z, 0.0f);
}

struct S00cf0cf0_Stream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnWrite)(S00cf0cf0_Stream*, const void*, unsigned int, unsigned int*, unsigned int);
};

struct S00cf0cf0_Arr
{
    __m128* data;
    unsigned int count;
};

struct S00cf0cf0_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    S00cf0cf0_Stream* m_pBinaryStream;
};

static unsigned int S00cf0cf0_SaveRaw(S00cf0cf0_Stream* s, const void* p, unsigned int n, unsigned int elemSize)
{
    unsigned int uiSize = elemSize;
    return s->m_pfnWrite(s, p, n * elemSize, &uiSize, 1);
}

// Writes arr's count and then each 16-byte element to the binary stream, and returns count * 16.
// @fnv 0x00cf0cf0
int __cdecl FUN_00cf0cf0(S00cf0cf0_Obj* self, S00cf0cf0_Arr* arr)
{
    S00cf0cf0_Arr* a = arr;
    int count = a->count;
    {
        S00cf0cf0_Stream* s = self->m_pBinaryStream;
        s->m_uiStreamFlags += S00cf0cf0_SaveRaw(s, &count, 1, 4);
    }
    int total = count << 4;
    for (int i = 0; i < count; i++)
    {
        __m128 tmp = a->data[i];
        S00cf0cf0_Stream* s = self->m_pBinaryStream;
        s->m_uiStreamFlags += S00cf0cf0_SaveRaw(s, &tmp, 1, 16);
    }
    return total;
}

struct TargetType
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 unk10;
    void* unk20;
    unsigned int unk24;
};

// Writes obj->unk24, obj->unk10 and the buffer at obj->unk20 to the stream, returning the buffer size.
// @fnv 0x00cf0dc0
unsigned int FUN_00cf0dc0(CF4BC0Stream& stream, TargetType* obj)
{
    unsigned int size = 0;
    if (obj)
    {
        size = obj->unk24;
        CF4BC0BinaryStreamSave(*stream.m_pBackingStream, &size);

        __m128 data = obj->unk10;
        CF4BC0BinaryStreamSave(*stream.m_pBackingStream, &data);

        if (size)
        {
            CF4BC0BinaryStreamSave(*stream.m_pBackingStream, (char*)obj->unk20, size);
        }
    }
    return size;
}

// Returns the Havok constraint class name string for the given eType, or "Unknown" if the type is not recognized.
// @fnv 0x00cf4790
const char* __cdecl GetConstraintTypeName(intptr_t eType)
{
    switch (eType)
    {
    case 0:
        return "hkBallAndSocketConstraint";
    case 1:
        return "hkHingeConstraint";
    case 2:
        return "hkLimitedHingeConstraint";
    case 3:
        return "hkPointToPathConstraint";
    case 6:
        return "hkPrismaticConstraint";
    case 7:
        return "hkRagdollConstraint";
    case 8:
        return "hkStiffSpringConstraintC";
    case 9:
        return "hkWheelConstraint";
    case 10:
        return "hkGenericConstraint";
    case 12:
        return "hkBreakableConstraint";
    case 13:
        return "hkMalleableConstraint";
    }
    return "Unknown";
}

// @fnv 0x00cf6d00
void FUN_00cf6d00(int)

{}

extern void* DAT_010cc4e0;
extern void* DAT_010cc4d0;

struct NodeBaseA
{
    void* m_vtbl;
    unsigned short m_04;
    unsigned short m_06;
    NodeBaseA()
    {
        m_06 = 1;
    }
};

struct NodeBaseB
{
    void* m_vtbl;
    NodeBaseB()
    {
        m_vtbl = &(*reinterpret_cast<void * *>(&::DAT_010c63bc));
    }
};

struct NodeObj : NodeBaseA, NodeBaseB
{
    NodeObj()
    {
        NodeBaseA::m_vtbl = &DAT_010cc4e0;
        NodeBaseB::m_vtbl = &DAT_010cc4d0;
    }
};

struct FUN_00cf6f90
{
    NodeBaseB* m_apSlots[8][8];
    NodeObj m_kDefault;
    FUN_00cf6f90();
};

// Initializes the 8x8 m_apSlots array so that every slot points to the embedded m_kDefault NodeObj instance.
// @fnv 0x00cf6f90
FUN_00cf6f90::FUN_00cf6f90()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            m_apSlots[i][j] = &m_kDefault;
}

// @fnv 0x00cf8810
void FUN_00cf8810(int a)
{}

extern char DAT_010cc688[];
struct VecCFAD
{
    union
    {
        __m128 v;
        float f[4];
    };
};
struct InputCFAD
{
    VecCFAD vec;
    int unk10, unk14, unk18, unk1C;
    unsigned char enabled;
};
struct DescCFAD
{
    VecCFAD vec;
    void* data;
    void* extra;
    unsigned int size;
    unsigned int flags;
};
struct ContextCFAD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
};
struct TargetCFAD;
struct SelfCFAD;
struct TargetCFAD
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C(DescCFAD*, SelfCFAD*, int);
};
struct SelfCFAD
{
    void* unk00;
    InputCFAD* input;
    void* extra;
    unsigned int flags;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* context;
    void FUN_00cfad60(TargetCFAD*, InputCFAD*, void*, ContextCFAD*, unsigned int, unsigned int);
};
// Stores input, output flags, extra and context, builds a DescCFAD from the input and flagsIn, then calls target->unk5C, timed by CE0020TimerMark.
// @fnv 0x00cfad60
void SelfCFAD::FUN_00cfad60(TargetCFAD* target, InputCFAD* apInput, void* data, ContextCFAD* apContext,
                            unsigned int flagsIn, unsigned int flagsOut)
{
    CE0020TimerMark(DAT_010cc688);
    input = apInput;
    flags = flagsOut;
    extra = apContext ? &apContext->unk14 : 0;
    if (apInput->enabled)
        context = apContext ? &apContext->unk10 : 0;
    else
        context = 0;
    DescCFAD desc;
    desc.vec.v = apInput->vec.v;
    desc.extra = &apInput->unk10;
    desc.flags = flagsIn;
    desc.data = data;
    desc.size = 0x30;
    target->unk5C(&desc, this, 0);
    CE0020TimerMark(DAT_010c41f8);
}

struct Cfd50Range
{
    int m_00;
    int* m_04;
    int m_08;
};

// @fnv 0x00cfdb50
static __declspec(noinline) int FUN_00cfdb50(Cfd50Range* apRange)
{
    return apRange->m_00 + apRange->m_04[apRange->m_08 - 1] - 0x80;
}

extern "C" Cfd50Range* Cfd50Get(void);
extern "C" int Cfd50Sink(int);

void Cfd50Caller(void)
{
    volatile int r = FUN_00cfdb50(Cfd50Get());
    Cfd50Sink(r);
}

struct CE1700World
{
    void FUN_00c97e80(char* result, void* object);
};
struct CE1700Node
{
    int unk00;
    int unk04;
    CE1700World* world;
};
struct CE1700Owner
{
    int unk00;
    int unk04;
    CE1700Node** owner;
    int flags;
    int unk10;
    void** objects;
    int count;
    int FUN_00ce1700();
};
// Returns 1 if the owner's node has no world; otherwise calls world->FUN_00c97e80 per object, then world->RemoveEntities(owner, flags), and returns 0.
// @fnv 0x00ce1700
int CE1700Owner::FUN_00ce1700()
{
    CE1700Node* node = *owner;
    CE1700World* world = 0;
    if (node)
        world = node->world;
    if (!world)
        return 1;
    for (int i = 0; i < count; ++i)
    {
        char result;
        world->FUN_00c97e80(&result, objects[i]);
    }
    reinterpret_cast<::HostWorld_00c951b0 *>((world))->RemoveEntities((void *const *)(owner), flags);
    return 0;
}

struct Slot_cfdb70
{
    void* m_p;
    int m_04;
};
struct Node_cfdb70
{
    char pad[0x50];
    Slot_cfdb70* m_slots;
};
struct Edge_cfdb70
{
    void* m_vtbl;
    unsigned short m_idxA;
    unsigned short m_idxB;
    int m_08;
    int m_0c;
    Node_cfdb70* m_kPointA;
    Node_cfdb70* m_kPointB;
};

// Stores the edge pointer in the slot arrays of both connected nodes at their respective indices.
// @fnv 0x00cfdb70
static __declspec(noinline) void LinkEdge(Edge_cfdb70* apEdge)
{
    unsigned short a = apEdge->m_idxA;
    unsigned short b = apEdge->m_idxB;
    apEdge->m_kPointA->m_slots[a].m_p = apEdge;
    apEdge->m_kPointB->m_slots[b].m_p = apEdge;
}

void zz_probe_cfdb70(Edge_cfdb70* e)
{
    LinkEdge(e);
}

struct BlockArr_cfd
{
    unsigned* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned operator[](int i) const
    {
        return m_data[i];
    }
    const unsigned& at(int i) const
    {
        return m_data[i];
    }
};
struct BlockList_cfd
{
    unsigned m_lastSize;
    BlockArr_cfd m_kBlocks;
};

// Checks whether addr falls within any block range in list->m_kBlocks, using m_lastSize for the final block and 0x200 for the others.
// @fnv 0x00cfdb90
bool __cdecl IsAddressInBlock(const BlockList_cfd* list, unsigned addr)
{
    for (int i = 0; i < list->m_kBlocks.GetLogicalSize(); i++)
    {
        unsigned base = list->m_kBlocks[i];
        unsigned size = (i + 1 == list->m_kBlocks.GetLogicalSize()) ? list->m_lastSize : 0x200;
        if (base <= addr && addr < base + size)
            return true;
    }
    return false;
}

inline AudioAllocator& heap_cfde()
{
    return *static_cast<AudioHolder*>(::FUN_00c85750())->m_pAllocator;
}

struct BlockArr_cfde
{
    char*& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_kStorage[1];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void OptimizeCapacity(int numFreeElemsLeft)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            unsigned c = m_iElementCount + numFreeElemsLeft - 1;
            c |= c >> 16;
            c |= c >> 8;
            c |= c >> 4;
            c |= c >> 2;
            c |= c >> 1;
            int newCap = c + 1;
            if (newCap < 1)
            {
                AudioHolder* h = static_cast<AudioHolder*>(::FUN_00c85750());
                ::fnv_00c909d0::FUN_00c909d0((*(::fnv_00c909d0::hkMemoryAllocator *)(h->m_pAllocator)), this, sizeof(char*), m_kStorage, 1);
            }
            else if (newCap < getCapacity())
            {
                AudioAllocator& a = heap_cfde();
                ::fnv_00c909d0::FUN_00c909d0((*(::fnv_00c909d0::hkMemoryAllocator *)(&a)), this, sizeof(char*), 0, newCap);
            }
        }
    }
};

struct BlockStack_cfde
{
    int m_uiBufferCapacity;
    BlockArr_cfde m_kBlocks;
};

// Subtracts 0x80 from m_uiBufferCapacity; at zero frees the last block, pops it and resets capacity to 0x200; then calls OptimizeCapacity(4).
// @fnv 0x00cfdeb0
static __declspec(noinline) void FUN_00cfdeb0(BlockStack_cfde* s)
{
    s->m_uiBufferCapacity -= 0x80;
    if (s->m_uiBufferCapacity == 0)
    {
        char* block = s->m_kBlocks.back();
        s->m_kBlocks.popBack();
        AudioHolder* h = static_cast<AudioHolder*>(::FUN_00c85750());
        h->m_pAllocator->Free(block, 0x200);
        s->m_uiBufferCapacity = 0x200;
    }
    s->m_kBlocks.OptimizeCapacity(4);
}

void zz_probe_cfdeb0(BlockStack_cfde* s)
{
    FUN_00cfdeb0(s);
}

// Havok: build index maps for a selection and propagate it through records and links (hkArray<hkInt16> maps).
typedef short hkInt16;
typedef unsigned short hkUint16;

struct hkBoolX
{
    char m_cBooleanValue;
    hkBoolX() throw()
    {}
    hkBoolX(bool b) throw()
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator() throw();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename T> __forceinline void _bufFree(T* p, int numElem) throw()
    {
        ReturnMemory(p, numElem * int(sizeof(T)));
    }
};

struct hkMemoryRouterX
{
    int m_pad00, m_pad04, m_pad08, m_pad0c;
    hkMemoryAllocator* m_pStreamAllocator;
    static hkMemoryRouterX& GetMonitorStream() throw();
    __forceinline hkMemoryAllocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

struct hkArrayUtilX
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& a, void* array, int reqElements, int sizeElem) throw();
    template <typename T> static __forceinline void construct(T* p, int n, const T& t) throw()
    {
        for (int i = 0; i < n; ++i)
            p[i] = t;
    }
};

template <typename T> struct hkArrayX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArrayX() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~hkArrayX() throw()
    {
        _clearAndDeallocate(hkMemoryRouterX::GetMonitorStream().heap());
    }

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n) throw()
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        const int numToFill = n - m_iElementCount;
        T* dst = m_data + m_iElementCount;
        for (int i = 0; i < numToFill; ++i)
            dst[i] = fill;
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n, const T& fill) throw()
    {
        _setSize(hkMemoryRouterX::GetMonitorStream().heap(), n, fill);
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, int t) throw()
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(T));
        T value = (T)t;
        hkArrayUtilX::construct(m_data + m_iElementCount, 1, value);
        m_iElementCount++;
    }
    __forceinline void AddBack(int t) throw()
    {
        _pushBack(hkMemoryRouterX::GetMonitorStream().heap(), t);
    }
};

struct IndexSource
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int m_iStridedVertexCount;
};
struct SelRecord
{
    hkInt16 m_vFrom;
    hkUint16 m_vTo;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct SelLink
{
    hkUint16 m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};

struct Selection
{
    int unk00, unk04, unk08, unk0c;
    hkArrayX<hkInt16> m_ppIndices;
};

struct SelectionMapper
{
    int unk00, unk04, unk08, unk0c;
    IndexSource* m_pObservedSource;
    IndexSource* m_target;
    SelRecord* m_records;
    int m_numRecords;
    int unk20;
    SelLink* m_ppLinks;
    int m_numLinks;
    void MapSelection(const Selection& sel, hkArrayX<hkInt16>& sourceMap, hkArrayX<hkInt16>& targetMap,
                      hkArrayX<hkInt16>& output);
};

// Maps a Selection's source indices to target indices via records and links, filling sourceMap, targetMap, and output arrays.
// @fnv 0x00ce35f0
void SelectionMapper::MapSelection(const Selection& sel, hkArrayX<hkInt16>& sourceMap, hkArrayX<hkInt16>& targetMap,
                                   hkArrayX<hkInt16>& output)
{
    hkInt16 i;
    const hkArrayX<hkInt16>& selIdx = sel.m_ppIndices;
    const IndexSource* src = m_pObservedSource;
    const IndexSource* dst = m_target;

    sourceMap.clear();
    sourceMap.SetSizeAndGrow(src->m_iStridedVertexCount, -1);
    for (i = 0; i < selIdx.GetLogicalSize(); i++)
        sourceMap[selIdx[i]] = i;

    output.clear();
    targetMap.clear();
    targetMap.SetSizeAndGrow(dst->m_iStridedVertexCount, -1);

    for (hkInt16 recordI = 0; recordI < m_numRecords; ++recordI)
    {
        if (sourceMap[m_records[recordI].m_vFrom] >= 0)
            output.AddBack(m_records[recordI].m_vTo);
    }
    for (i = 0; i < m_numLinks; i++)
    {
        {
            hkInt16 linkIndex = i;
            hkArrayX<hkInt16> a;
            hkArrayX<hkInt16> b;
            ::hkBoolX found;
            if (!(*(::hkBoolX *)(::WalkChainUntilLimit((unsigned char *)&(found), (::ScanRec *)(src), m_ppLinks[linkIndex].m_kPointA, m_ppLinks[linkIndex].m_kPointB, (::ScanObj *)&(a)))))
                continue;
            if (!(*(::hkBoolX *)(::WalkChainUntilLimit((unsigned char *)&(found), (::ScanRec *)(dst), m_ppLinks[linkIndex].m_iThirdValue, m_ppLinks[linkIndex].m_iFourthElementInteger, (::ScanObj *)&(b)))))
                continue;
            bool complete = true;
            for (int j = 0; j < a.GetLogicalSize(); ++j)
            {
                if (sourceMap[a[j]] < 0)
                {
                    complete = false;
                    break;
                }
            }
            if (!complete)
                continue;
            for (int k = 0; k < b.GetLogicalSize(); ++k)
            {
                hkInt16 v = b[k];
                output.AddBack(v);
            }
        }
    nextLink:;
    }

    targetMap.SetSizeAndGrow(dst->m_iStridedVertexCount, -1);
    for (i = 0; i < output.GetLogicalSize(); i++)
        targetMap[output[i]] = i;
}

namespace fnv_00ce0ca0 {


struct FUN_00ce0ca0_Quaternion
{
    __m128 value;

    void FUN_00ce0ca0(const FUN_00ce0ca0_Quaternion& rhs);
};

// Computes the Hamilton product of two quaternions using SSE intrinsics and stores the result in value.
// @fnv 0x00ce0ca0
void FUN_00ce0ca0_Quaternion::FUN_00ce0ca0(const FUN_00ce0ca0_Quaternion& rhs)
{
    __m128 b = rhs.value;
    __m128 a = value;

    __m128 v = _mm_shuffle_ps(a, a, 0xc9);
    __m128 t = _mm_shuffle_ps(b, b, 0xd2);
    v = _mm_mul_ps(v, t);

    __m128 u = _mm_shuffle_ps(b, b, 0xc9);
    t = _mm_shuffle_ps(a, a, 0xd2);
    t = _mm_mul_ps(t, u);
    v = _mm_sub_ps(v, t);

    t = _mm_shuffle_ps(a, a, 0xff);
    t = _mm_shuffle_ps(t, t, 0);
    t = _mm_mul_ps(t, b);
    t = _mm_add_ps(t, v);

    v = _mm_shuffle_ps(b, b, 0xff);
    v = _mm_shuffle_ps(v, v, 0);
    v = _mm_mul_ps(v, a);

    v = _mm_add_ps(v, t);
    a = _mm_mul_ps(a, b);

    t = _mm_shuffle_ps(a, a, 0x55);
    t = _mm_add_ss(t, a);

    b = _mm_shuffle_ps(a, a, 0xaa);
    b = _mm_add_ss(b, t);

    t = v;
    b = _mm_shuffle_ps(b, b, 0);
    a = _mm_sub_ps(a, b);

    v = _mm_unpackhi_ps(v, a);
    t = _mm_shuffle_ps(t, v, 0xc4);

    value = t;
}
}  // namespace fnv_00ce0ca0

namespace fnv_00cf4fb0 {
extern const __m128 DAT_010c71d0;

struct BoundsVector
{
    union
    {
        __m128 quad;
        float components[4];
    };
};
struct Bounds
{
    BoundsVector minimum;
    BoundsVector maximum;
};
struct BoundShape
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getBounds(const void* transform, float tolerance, Bounds* out);
};
struct ShapeEntry
{
    BoundShape* shape;
    int unk04, unk08, unk0c;
};
struct ShapeCollection
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ShapeEntry* entries;
    int count;
    int unk20, unk24, unk28, unk2c;
    BoundsVector halfExtent;
    BoundsVector center;
    void FUN_00cf4fb0(Bounds* bounds);
};

// Computes the combined bounding box of all shapes in the collection, then derives center and halfExtent from the min/max bounds.
// @fnv 0x00cf4fb0
void ShapeCollection::FUN_00cf4fb0(Bounds* bounds)
{
    entries[0].shape->getBounds(&::DAT_01268370, 0.0f, bounds);
    for (int i = 1; i < count; ++i)
    {
        Bounds local;
        BoundShape* shape = entries[i].shape;
        shape->getBounds(&::DAT_01268370, 0.0f, &local);
        bounds->minimum.quad = _mm_min_ps(bounds->minimum.quad, local.minimum.quad);
        __m128 localMaximum = local.maximum.quad;
        __m128 maximum = bounds->maximum.quad;
        bounds->maximum.quad = _mm_max_ps(maximum, localMaximum);
    }
    __m128 minimum = bounds->minimum.quad;
    __m128 maximum = bounds->maximum.quad;
    center.quad = _mm_mul_ps(_mm_add_ps(maximum, minimum), DAT_010c71d0);
    minimum = bounds->minimum.quad;
    maximum = bounds->maximum.quad;
    halfExtent.quad = _mm_mul_ps(_mm_sub_ps(maximum, minimum), DAT_010c71d0);
}
}  // namespace fnv_00cf4fb0

namespace fnv_00cf6d60 {

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    intptr_t unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


// Deletes the global critical section and frees its memory through the audio holder's allocator.
// @fnv 0x00cf6d60
void FUN_00cf6d60()
{
    if (::DAT_01268794 != 0)
    {
        CRITICAL_SECTION* p = ::DAT_01268794;
        DeleteCriticalSection(::DAT_01268794);
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        pHolder->m_pAllocator->Free(p, 0x18);
        ::DAT_01268794 = 0;
    }
}
}  // namespace fnv_00cf6d60

extern "C" bool __cdecl FUN_00ce2a00(int mappingType, const FnvSpawnedObject* transform);

struct FUN_00cb1600
{
    void* vtable;
    void* writer;
    int flags;
    FUN_00cb1600(char*, int) throw();
};
struct CEError
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void report(int, unsigned int, const char*, const char*, int) throw();
};
extern const char DAT_010cba14, DAT_010cb9f8, DAT_010cb9d8, DAT_010cb9c4;
extern const char DAT_010cb9b0, DAT_010cb98c, DAT_010cb964, DAT_010cb8d0;
struct CEBoneName
{
    void* name;
    int flags;
};
struct CESkeleton
{
    int unk00;
    int unk04;
    int unk08;
    short* parents;
    int unk10;
    int unk14;
    CEBoneName* names;
    int count;
};
struct CESingle
{
    short source, target;
    int unk04, unk08, unk0c;
    FnvSpawnedObject transform;
};
struct CERange
{
    short startA, endA, startB, endB;
    int unk08, unk0c;
    FnvSpawnedObject transformA;
    FnvSpawnedObject transformB;
};
struct CEMap
{
    CESkeleton* a;
    CESkeleton* b;
    CESingle* singles;
    int singleCount;
    int unk10;
    CERange* ranges;
    int rangeCount;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int checker;
};
struct CEAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void free(void*, int) throw();
};

struct CECountArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int* m_pStackAllocation;
};

// Validates a CEMap by checking single and range bone mappings, counting target bone usage, and reporting errors via CEError.
// @fnv 0x00ce43e0
void __cdecl FUN_00ce43e0(CEMap* map)
{
    int count = map->b->count;
    AudioHolder* scratch = static_cast<AudioHolder*>(::FUN_00c85750());
    CECountArray counts;
    counts.m_data = reinterpret_cast<int*>(scratch->unk00);
    scratch->unk00 += (count * 4 + 127) & -128;
    counts.m_iElementCount = count;
    counts.m_iCapacityState = count | 0x80000000;
    counts.m_pStackAllocation = counts.m_data;
    int* data = counts.m_data;
    for (int z = 0; z < count; ++z)
        data[z] = 0;
    int buffer[128];
    for (int i = 0; i < map->singleCount; ++i)
    {
        CESingle* single = &map->singles[i];
        int checkerS = map->checker;
        if (!FUN_00ce2a00(checkerS, static_cast<const FnvSpawnedObject*>(&single->transform)))
        {
            char* bufPtr = (char*)buffer;
            FUN_00cb1600 s1(bufPtr, 512);
            reinterpret_cast<::SinkOwner *>(&(s1))->FUN_00cc01c0(&DAT_010cba14);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabbabac1, (char*)buffer, &DAT_010cb8d0, 0x227);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s1))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (single->source < 0 || single->source >= map->a->count)
        {
            FUN_00cb1600 s2((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s2))->FUN_00cc01c0(&DAT_010cb9f8);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabba3f01, (char*)buffer, &DAT_010cb8d0, 0x22c);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s2))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (single->target < 0 || single->target >= map->b->count)
        {
            FUN_00cb1600 s3((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s3))->FUN_00cc01c0(&DAT_010cb9f8);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabbaeab2, (char*)buffer, &DAT_010cb8d0, 0x231);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s3))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        ++data[single->target];
        if (data[single->target] > 1)
        {
            FUN_00cb1600 s4((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s4))->FUN_00cc01c0(&DAT_010cb9d8);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabba819f, (char*)buffer, &DAT_010cb8d0, 0x239);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s4))->FUN_00cc00e0::~FUN_00cc00e0();
        }
    }
    for (int j = 0; j < map->rangeCount; ++j)
    {
        CERange* range = &map->ranges[j];
        int checkerA = map->checker;
        if (!FUN_00ce2a00(checkerA, static_cast<const FnvSpawnedObject*>(&range->transformA)))
        {
            FUN_00cb1600 s5((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s5))->FUN_00cc01c0(&DAT_010cba14);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabbabac1, (char*)buffer, &DAT_010cb8d0, 0x246);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s5))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        int checkerB = map->checker;
        if (!FUN_00ce2a00(checkerB, static_cast<const FnvSpawnedObject*>(&range->transformB)))
        {
            FUN_00cb1600 s6((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s6))->FUN_00cc01c0(&DAT_010cba14);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabbabac1, (char*)buffer, &DAT_010cb8d0, 0x24b);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s6))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (range->endA <= range->startA)
        {
            FUN_00cb1600 s7((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s7))->FUN_00cc01c0(&DAT_010cb9c4);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabba819f, (char*)buffer, &DAT_010cb8d0, 0x250);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s7))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (range->endB <= range->startB)
        {
            FUN_00cb1600 s8((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s8))->FUN_00cc01c0(&DAT_010cb9c4);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabba819f, (char*)buffer, &DAT_010cb8d0, 0x255);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s8))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (range->endA < 0 || range->endA >= map->a->count)
        {
            FUN_00cb1600 s9((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s9))->FUN_00cc01c0(&DAT_010cb9b0);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0x17626ee1, (char*)buffer, &DAT_010cb8d0, 0x25a);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s9))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (range->startA < 0 || range->startA >= map->a->count)
        {
            FUN_00cb1600 s10((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s10))->FUN_00cc01c0(&DAT_010cb9b0);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0x06073fdc, (char*)buffer, &DAT_010cb8d0, 0x25f);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s10))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (range->endB < 0 || range->endB >= map->b->count)
        {
            FUN_00cb1600 s11((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s11))->FUN_00cc01c0(&DAT_010cb9b0);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0x19a18bfd, (char*)buffer, &DAT_010cb8d0, 0x264);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s11))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        if (range->startB < 0 || range->startB >= map->b->count)
        {
            FUN_00cb1600 s12((char*)buffer, 512);
            reinterpret_cast<::SinkOwner *>(&(s12))->FUN_00cc01c0(&DAT_010cb9b0);
            reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0x0fb695b1, (char*)buffer, &DAT_010cb8d0, 0x269);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s12))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        for (int bone = range->endB; bone >= range->startB; bone = map->b->parents[bone])
        {
            ++data[bone];
            if (data[bone] > 1)
            {
                FUN_00cb1600 s13((char*)buffer, 512);
                CEBoneName* boneName = &map->b->names[bone];
                reinterpret_cast<::SinkOwner *>(&((*(::FUN_00cb1600 *)(reinterpret_cast<::AttributeFormatter *>(&((*(::FUN_00cb1600 *)(reinterpret_cast<::SinkOwner *>(&(s13))->FUN_00cc01c0(&DAT_010cb964)))))->WriteName((::NameReference *)(boneName))))))->FUN_00cc01c0(&DAT_010cb98c);
                reinterpret_cast<CEError*>((*reinterpret_cast<int *>(&::DAT_01268360)))->report(1, 0xabba819f, (char*)buffer, &DAT_010cb8d0, 0x275);
                reinterpret_cast<struct ::FUN_00cc00e0 *>(&(s13))->FUN_00cc00e0::~FUN_00cc00e0();
            }
        }
    }
    static_cast<AudioHolder*>(::FUN_00c85750())->unk00 = reinterpret_cast<intptr_t>(data);
    CEAllocator* allocator = reinterpret_cast<CEAllocator*>(static_cast<AudioHolder*>(::FUN_00c85750())->m_pAllocator);
    if ((counts.m_iCapacityState & (int)0x80000000) == 0)
        allocator->free(data, (counts.m_iCapacityState & 0x3fffffff) * 4);
}


struct MapperInitialization
{
    int unk00;
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
    unsigned char unk60;
    void FUN_00ce5310();
};
// @fnv 0x00ce4a20
intptr_t FUN_00ce4a20_cls::FUN_00ce4a20(intptr_t a)
{
    m_iThirdValue = 1;
    m_kPointA = (intptr_t)&DAT_010cb864;
    reinterpret_cast<::MapperInitialization *>((((FUN_00ce4ae0_cls*)((char*)this + 0x10))))->FUN_00ce5310();
    reinterpret_cast<::ShapeData *>((((FUN_00ce4ae0_cls*)((char*)this + 0x10))))->FUN_00ce4ae0((*(const ::ShapeData *)(a)));
    return (intptr_t)this;
}

// @fnv 0x00ce5310
void MapperInitialization::FUN_00ce5310()
{
    MapperInitialization* data = reinterpret_cast<MapperInitialization*>(this);

    data->unk00 = 0;
    data->unk04 = 0;
    data->unk08 = 0;
    data->unk0C = 0;
    data->unk10 = 0x80000000;
    data->unk14 = 0;
    data->unk18 = 0;
    data->unk1C = 0x80000000;
    data->unk20 = 0;
    data->unk24 = 0;
    data->unk28 = 0x80000000;
    data->unk60 = 1;

    _mm_store_ps(reinterpret_cast<float*>(&data->unk30), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&data->unk40), ::DAT_010c71b0);
    _mm_store_ps(reinterpret_cast<float*>(&data->unk50), _mm_set1_ps(DAT_01012068));
}

void __cdecl FUN_00cf6950(intptr_t a, intptr_t apObject);




void __cdecl FUN_00ce2cf0(intptr_t pObject, intptr_t param_2, intptr_t param_3);

void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pKeyBox);

CpuOpaque* __cdecl FUN_00cf45f0();

void __cdecl FUN_00cf6980(FUN_00cf6980_class* object);

int* __cdecl FUN_00cf6990();

void __cdecl DeleteObjectIfNotNull(FUN_00ce9800_obj* pkObject);

void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* pObject);

int* FUN_00cf41b0();

CpuOpaque* __cdecl FUN_00cf43f0();

void __cdecl FUN_00cf74a0(void);

void FUN_00cfb060();

void FUN_00cfc580(int, int, int, int, int);

void FUN_00cfdb40();

void FUN_00cf6d10();

void __cdecl CopyVectors(hkElementCE98* pkDst, const hkElementCE98* pkSrc, int iCount);

void FUN_00cf6d00(int);

void FUN_00cf8810(int a);

static int FUN_00cfdb50(Cfd50Range* a);

void Cfd50Caller(void);


static void LinkEdge(Edge_cfdb70* e);

void zz_probe_cfdb70(Edge_cfdb70* e);

bool __cdecl IsAddressInBlock(const BlockList_cfd* list, unsigned addr);

static void FUN_00cfdeb0(BlockStack_cfde* s);

void zz_probe_cfdeb0(BlockStack_cfde* s);

void __cdecl FUN_00ce43e0(CEMap* map);

struct ElemA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_v;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct ElemB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_v0;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    __m128 m_v1;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct ScaleObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ElemA* m_pA;
    int m_nCallbackId;
    int unk20;
    ElemB* m_pB;
    int m_nB;
};

// @fnv 0x00ce54c0
void __cdecl FUN_00ce54c0(ScaleObj* obj, float scale)
{
    for (int i = 0; i < obj->m_nCallbackId; i++)
    {
        __m128 s = _mm_load_ss(&scale);
        obj->m_pA[i].m_v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), obj->m_pA[i].m_v);
    }
    for (int i = 0; i < obj->m_nB; i++)
    {
        __m128 s = _mm_load_ss(&scale);
        obj->m_pB[i].m_v0 = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), obj->m_pB[i].m_v0);
        __m128 t = _mm_load_ss(&scale);
        obj->m_pB[i].m_v1 = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), obj->m_pB[i].m_v1);
    }
}

struct ScalarValue
{
    __m128 v;
    ScalarValue(__m128 x) : v(x)
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(v, v, 0);
    }
};

struct __declspec(align(16)) VectorValue
{
    __m128 v;
    void apply(const ScalarValue& s)
    {
        v = _mm_mul_ps(s.splat(), v);
    }
};

struct QsTransform
{
    VectorValue m_vTranslation;
    __m128 m_rotation;
    VectorValue m_vScale;
};

static __forceinline float LengthSquared4(__m128 v, float& out)
{
    v = _mm_mul_ps(v, v);
    __m128 s0 = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4E), v);
    __m128 s1 = _mm_add_ps(_mm_shuffle_ps(s0, s0, 0xB1), s0);
    _mm_store_ss(&out, s1);
    return out;
}

static __forceinline __m128 LengthSquared4v(__m128 v)
{
    v = _mm_mul_ps(v, v);
    __m128 s0 = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4E), v);
    return _mm_add_ps(_mm_shuffle_ps(s0, s0, 0xB1), s0);
}

static __forceinline void Normalize4(QsTransform* p)
{
    float dots[4];
    __declspec(align(16)) float len2[4];
    len2[0] = LengthSquared4(p[0].m_rotation, dots[0]);
    len2[1] = LengthSquared4(p[1].m_rotation, dots[1]);
    len2[2] = LengthSquared4(p[2].m_rotation, dots[2]);
    len2[3] = LengthSquared4(p[3].m_rotation, dots[3]);
    _ReadWriteBarrier();
    __m128 x = _mm_load_ps(len2);
    __m128 y0 = _mm_rsqrt_ps(x);
    __m128 ree = _mm_mul_ps(_mm_mul_ps(y0, x), y0);
    __m128 t = _mm_sub_ps(::DAT_010c71c0, ree);
    y0 = _mm_mul_ps(y0, ::DAT_010c71d0);
    __m128 inv = _mm_mul_ps(t, y0);
    __m128 s0 = _mm_shuffle_ps(inv, inv, 0);
    p[0].m_rotation = _mm_mul_ps(s0, p[0].m_rotation);
    __m128 s1 = _mm_shuffle_ps(inv, inv, 0x55);
    s1 = _mm_shuffle_ps(s1, s1, 0);
    p[1].m_rotation = _mm_mul_ps(s1, p[1].m_rotation);
    __m128 s2 = _mm_shuffle_ps(inv, inv, 0xAA);
    s2 = _mm_shuffle_ps(s2, s2, 0);
    __m128 s3 = _mm_shuffle_ps(inv, inv, 0xFF);
    p[2].m_rotation = _mm_mul_ps(s2, p[2].m_rotation);
    _ReadWriteBarrier();
    s3 = _mm_shuffle_ps(s3, s3, 0);
    p[3].m_rotation = _mm_mul_ps(s3, p[3].m_rotation);
}

// @fnv 0x00ce4e20
void __cdecl FUN_00ce4e20(QsTransform* xforms, const float* volatile weights, unsigned int count)
{
    unsigned int i = 0;
    if (count > 0)
    {
        const float* input = weights;
        __m128 one = _mm_load_ss(&DAT_01012068);
        QsTransform* scaled = xforms;
        do
        {
            ScalarValue inv(_mm_div_ss(_mm_load_ss((const float*)&one), _mm_load_ss(input + i)));
            scaled->m_vTranslation.apply(inv);
            scaled->m_vScale.apply(inv);
            ++i;
            ++scaled;
        } while (i < count);
    }

    unsigned int n4 = count >> 2;
    QsTransform* batch = xforms;
    if (n4 > 0)
    {
        do
        {
            Normalize4(batch);
            batch += 4;
        } while (--n4);
    }

    unsigned int rem = count & 3;
    if (rem > 0)
    {
        __m128 zero = _mm_set_ss(::DAT_01011d78);
        __m128 three = _mm_set_ss(::DAT_01017718);
        __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
        unsigned int n = rem;
        do
        {
            __m128 v = batch->m_rotation;
            __m128 len2 = LengthSquared4v(v);
            __m128 y0 = _mm_rsqrt_ss(len2);
            __m128 ree = _mm_mul_ss(_mm_mul_ss(len2, y0), y0);
            __m128 refined = _mm_mul_ss(_mm_mul_ss(half, y0), _mm_sub_ss(three, ree));
            __m128 factor = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), refined);
            factor = _mm_shuffle_ps(factor, factor, 0);
            batch->m_rotation = _mm_mul_ps(factor, v);
            ++batch;
        } while (--n);
    }
}

void __cdecl FUN_00cf6950(intptr_t a, intptr_t b);

void __cdecl FUN_00ce2cf0(intptr_t param_1, intptr_t param_2, intptr_t param_3);

void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pBox);

void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* p);

struct SimdReal
{
    __m128 m_vValue;
    __forceinline SimdReal(__m128 r) : m_vValue(r)
    {}
    __forceinline operator __m128() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
};

struct FourFloatVector
{
    __m128 m_vComponents;

    __forceinline SimdReal lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        return SimdReal(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s));
    }
    __forceinline void setXYZ_W(__m128 xyz, __m128 w)
    {
        m_vComponents = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, w), 0xc4);
    }
    __forceinline void setSqrtInverse4(const FourFloatVector& v)
    {
        __m128 e = _mm_rsqrt_ps(v.m_vComponents);
        __m128 he = _mm_mul_ps(::DAT_010c71d0, e);
        __m128 ree = _mm_mul_ps(_mm_mul_ps(e, v.m_vComponents), e);
        m_vComponents = _mm_mul_ps(_mm_sub_ps(::DAT_010c71c0, ree), he);
    }
};

// @fnv 0x00ce2a50
static __declspec(noinline) void FUN_00ce2a50(FourFloatVector* a, FourFloatVector* b)
{
    FourFloatVector len2;
    SimdReal la = a->lengthSquared3();
    SimdReal lb = b->lengthSquared3();
    len2.setXYZ_W(la, lb);
    FourFloatVector inv;
    inv.setSqrtInverse4(len2);
    __m128 x = _mm_shuffle_ps(inv.m_vComponents, inv.m_vComponents, 0x00);
    a->m_vComponents = _mm_mul_ps(x, a->m_vComponents);
    __m128 w = _mm_shuffle_ps(inv.m_vComponents, inv.m_vComponents, 0xff);
    b->m_vComponents = _mm_mul_ps(_mm_shuffle_ps(w, w, 0), b->m_vComponents);
}

void CallerX(FourFloatVector* a, FourFloatVector* b)
{
    FUN_00ce2a50(a, b);
}

struct SubMatrix
{
    __m128 m_row[4];
};

struct TransformOwner
{
    int unk00;
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
    SubMatrix m_matrix;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    __m128 m_vec140;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    __m128 m_quat170;
};

extern "C" TransformOwner* cf8b60_self(void);

extern "C" __m128* cf8b60_quat(void);

// @fnv 0x00cf8b60
static __declspec(noinline) void FUN_00cf8b60(TransformOwner* self, __m128* pQuat)
{
    SubMatrix* m = &self->m_matrix;
    reinterpret_cast<::RotationRows *>((m))->FUN_00cb2d90((void *)((const float*)pQuat));
    __m128 q = self->m_quat170;
    __m128 v = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 1, 1, 1)), m->m_row[1]);
    v = _mm_add_ps(v, _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(0, 0, 0, 0)), m->m_row[0]));
    v = _mm_add_ps(v, _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(2, 2, 2, 2)), m->m_row[2]));
    m->m_row[3] = _mm_sub_ps(self->m_vec140, v);
}

void cf8b60_caller(void)
{
    FUN_00cf8b60(cf8b60_self(), cf8b60_quat());
}

struct ResultByte
{
    char value;
    __forceinline ResultByte(bool b) : value(b)
    {}
};

struct ScalarValueEB6
{
    __m128 packed;
    __forceinline ScalarValueEB6(__m128 x) : packed(x)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, packed);
        return f;
    }
};

struct VectorValueEB6
{
    __m128 packed;
    __forceinline void subtract(const VectorValueEB6& a, const VectorValueEB6& b)
    {
        packed = _mm_sub_ps(a.packed, b.packed);
    }
    __forceinline void cross(const VectorValueEB6& a, const VectorValueEB6& b)
    {
        packed =
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.packed, a.packed, 201), _mm_shuffle_ps(b.packed, b.packed, 210)),
                       _mm_mul_ps(_mm_shuffle_ps(a.packed, a.packed, 210), _mm_shuffle_ps(b.packed, b.packed, 201)));
    }
    __forceinline ScalarValueEB6 dot(const VectorValueEB6& b) const
    {
        __m128 products = _mm_mul_ps(packed, b.packed);
        __m128 first = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
        return ScalarValueEB6(_mm_add_ss(_mm_shuffle_ps(products, products, 170), first));
    }
};

// @fnv 0x00ceb6f0
ResultByte FUN_00ceb6f0(float& outT, float& outU, float& outV, const VectorValueEB6& position,
                        const VectorValueEB6& direction, const VectorValueEB6& a, const VectorValueEB6& b, const VectorValueEB6& c,
                        bool cull)
{
    VectorValueEB6 e1, e2, p;
    e1.subtract(b, a);
    e2.subtract(c, a);
    p.cross(direction, e2);
    float determinant = p.dot(e1);
    if (cull)
    {
        if (determinant < DAT_01032980)
            return false;
    }
    else
    {
        if (determinant > (double)-0.0001f && determinant < DAT_01032980)
            return false;
    }
    float inverse = 1.0f / determinant;
    VectorValueEB6 offset;
    offset.subtract(position, a);
    outU = offset.dot(p);
    if (outU < 0.0f || outU > determinant)
        return false;
    VectorValueEB6 q;
    q.cross(offset, e1);
    outV = direction.dot(q);
    if (outV < 0.0f || outU + outV > determinant)
        return false;
    outT = q.dot(e2);
    outT *= inverse;
    outU *= inverse;
    outV *= inverse;
    return true;
}











static void FUN_00ce2a50(FourFloatVector* a, FourFloatVector* b);

void CallerX(FourFloatVector* a, FourFloatVector* b);

static void FUN_00cf8b60(TransformOwner* self, __m128* pQuat);

void cf8b60_caller(void);


struct BoolX {
    char value;
    __forceinline BoolX(bool b) throw() : value((char)b) {}
    __forceinline operator bool() const throw() { return value != 0; }
};

class ScalarX {
    union { __m128 value; float lane[4]; };
public:
    ScalarX() {}
    ScalarX(const ScalarX& a) : value(a.value) {}
    void operator=(const ScalarX& a) { value=a.value; }
    ScalarX(float x) { value=_mm_load_ss(&x); }
    ScalarX(const __m128& x) : value(x) {}
    __forceinline __m128 splat() const { return _mm_shuffle_ps(value,value,0); }
    __forceinline const __m128& quad() const { return value; }
};

inline ScalarX __cdecl operator+(const ScalarX& a,const ScalarX& b) { return _mm_add_ss(a.quad(),b.quad()); }

struct RotationX;

class VectorX {
    union { __m128 value; float lane[4]; };
public:
    __forceinline VectorX() {}
    __forceinline VectorX(const VectorX& a) : value(a.value) {}
    __forceinline __m128& quad() { return value; }
    __forceinline const __m128& quad() const { return value; }
    operator __m128() const { return value; }
    __forceinline void operator=(const VectorX& x) throw() { value=x.value; }
    __forceinline void zero() throw() { value=_mm_setzero_ps(); }
    __forceinline void add(const VectorX& x) throw() { value=_mm_add_ps(value,x.value); }
    __forceinline void multiply(const VectorX& x) throw() { value=_mm_mul_ps(value,x.value); }
    __forceinline void multiply(const ScalarX& x) throw() { value=_mm_mul_ps(x.splat(),value); }
    __forceinline void setProduct(const ScalarX& s, const VectorX& x) throw() { value=_mm_mul_ps(s.splat(),x.value); }
    __forceinline ScalarX dot(const VectorX& x) const throw() {
        __m128 squares = _mm_mul_ps(value,x.value);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(squares,squares,0x55),squares);
        return _mm_add_ss(_mm_shuffle_ps(squares,squares,0xaa),xy);
    }
    __forceinline ScalarX length() const throw() { return _mm_sqrt_ss(dot(*this).quad()); }
    __forceinline void sumProduct(const VectorX& a,const VectorX& b,const VectorX& c) { value=_mm_add_ps(a.value,_mm_mul_ps(b.value,c.value)); }
    __forceinline void product(const VectorX& a,const VectorX& b) { value=_mm_mul_ps(a.value,b.value); }
    __forceinline void accumulateProduct(const VectorX& a,const VectorX& b) { value=_mm_add_ps(value,_mm_mul_ps(a.value,b.value)); }
    __forceinline void sum(const VectorX& a,const VectorX& b) { value=_mm_add_ps(a.value,b.value); }
    __forceinline void broadcast(const VectorX& a,int lane) { if(lane==0) value=_mm_shuffle_ps(a.value,a.value,0); else if(lane==1) value=_mm_shuffle_ps(a.value,a.value,0x55); else if(lane==2) value=_mm_shuffle_ps(a.value,a.value,0xaa); else if(lane==3) value=_mm_shuffle_ps(a.value,a.value,0xff); }
    __forceinline void broadcast(int lane) { if(lane==0) value=_mm_shuffle_ps(value,value,0); else if(lane==1) value=_mm_shuffle_ps(value,value,0x55); else if(lane==2) value=_mm_shuffle_ps(value,value,0xaa); else if(lane==3) value=_mm_shuffle_ps(value,value,0xff); }
    __forceinline void cross(const VectorX& a,const VectorX& b) {
        __m128 lhs=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xc9),_mm_shuffle_ps(b.value,b.value,0xd2));
        __m128 rhs=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xd2),_mm_shuffle_ps(b.value,b.value,0xc9));
        value=_mm_sub_ps(lhs,rhs);
    }
    __forceinline ScalarX element(int lane) const {
        if(lane==0) return _mm_shuffle_ps(value,value,0);
        if(lane==1) return _mm_shuffle_ps(value,value,0x55);
        if(lane==2) return _mm_shuffle_ps(value,value,0xaa);
        return _mm_shuffle_ps(value,value,0xff);
    }
    __forceinline void fill(const ScalarX& x) { value=x.splat(); }
    __forceinline void accumulateProduct(const ScalarX& s,const VectorX& x) { value=_mm_add_ps(value,_mm_mul_ps(s.splat(),x.value)); }
    __forceinline void subtractProduct(const ScalarX& s,const VectorX& x) { value=_mm_sub_ps(value,_mm_mul_ps(s.splat(),x.value)); }
    __forceinline void subtract(const VectorX& x) { value=_mm_sub_ps(value,x.value); }
    __forceinline void pack(const VectorX& xyz,const VectorX& w) { value=_mm_shuffle_ps(xyz.value,_mm_unpackhi_ps(xyz.value,w.value),0xc4); }
    __forceinline ScalarX dot4(const VectorX& x) const {
        __m128 p=_mm_mul_ps(value,x.value);
        __m128 s=_mm_add_ps(_mm_shuffle_ps(p,p,0x4e),p);
        return _mm_add_ps(s,_mm_shuffle_ps(s,s,0xb1));
    }
    __forceinline void rotate(const RotationX& q,const VectorX& dir);

};

struct RotationX {
    VectorX vec;
    RotationX() {}
    RotationX(const RotationX& a) { vec=a.vec; }
    void operator=(const RotationX& a) { vec=a.vec; }
    void flipped(const VectorX&);
    __forceinline const VectorX& imag() const { return vec; }
};

__forceinline void VectorX::rotate(const RotationX& q,const VectorX& dir) {
    VectorX half; half.quad()=DAT_010c71e0;
    VectorX w; w.broadcast(q.vec,3);
    VectorX coeff; coeff.sumProduct(half,w,w);
    VectorX result; result.product(dir,coeff);
    VectorX projection; projection.quad()=q.imag().dot(dir).quad();
    projection.broadcast(0);
    result.accumulateProduct(projection,q.imag());
    VectorX perpendicular; perpendicular.cross(q.imag(),dir);
    result.accumulateProduct(w,perpendicular);
    sum(result,result);
}

static __forceinline __m128 reciprocalRootX(__m128 a) {
    __m128 r=_mm_rsqrt_ps(a);
    return _mm_mul_ps(_mm_mul_ps(_mm_set1_ps(0.5f),r),_mm_sub_ps(_mm_set1_ps(3.0f),_mm_mul_ps(_mm_mul_ps(r,a),r)));
}
struct PoseX { VectorX translation; RotationX rotation; VectorX scale;
    __forceinline const VectorX& position() const { return translation; }
    __forceinline const RotationX& orient() const { return rotation; }
    __forceinline const VectorX& sizing() const { return scale; }
};

template<class T> struct ArrayBaseX {
    T* data; int size, capacity;
    __forceinline int count() const throw() { return size; }
    __forceinline T* begin() throw() { return data; }
    __forceinline const T* begin() const throw() { return data; }
    __forceinline const T& operator[](int n) const throw() { return data[n]; }
};

template<class T> struct ArrayX : ArrayBaseX<T> {};

template<class T> struct RefPtrX {
    T* pointer;
    __forceinline T* operator->() const throw() { return pointer; }
};

struct BoneX;

struct SkeletonX {
    int unk00, unk04;
    const char* name;
    ArrayX<short> parents;
    ArrayX<BoneX> bones;
    ArrayX<PoseX> reference;
};

struct RecordX { short a,b; PoseX offset; };

struct LinkX { short a,b,c,d; PoseX root,end; };

struct MapperX {
    int unk00,unk04,unk08,unk0c;
    RefPtrX<const SkeletonX> first,second;
    ArrayX<RecordX> records;
    ArrayX<LinkX> links;
    ArrayX<short> unmapped;
    PoseX motion;
    BoolX keepLocal;
    intptr_t property;
    void __cdecl FUN_00ce3090(const PoseX*, PoseX*, const short*, const short*, bool) const;
};

// Calls FUN_00ce3090 with a1, a2, a3, two zero arguments, and a4.
// @fnv 0x00ce4330
void __cdecl FUN_00ce4330(intptr_t a1, intptr_t a2, intptr_t a3, int a4)
{
    reinterpret_cast<::MapperX *>((a1))->FUN_00ce3090((const ::PoseX *)(a2), (::PoseX *)(a3), (const short *)(0), (const short *)(0), a4);
}

struct ClockEventX { const char* tag; unsigned stamp; int unused; };

struct ClockListX : ClockEventX { const char* split; };

struct ClockX {
    int unk00; char* current; int unk08; char* end;
    __forceinline void mark(const char* tag) throw() {
        if (current<end) {
            ClockEventX* event=(ClockEventX*)current;
            event->tag=tag;
            unsigned ticks;
            ticks = (unsigned int)__rdtsc();
            event->stamp=ticks;
            current=(char*)(event+1);
        }
    }
    __forceinline void begin(const char* tag,const char* split) throw() {
        if (current<end) {
            ClockListX* event=(ClockListX*)current;
            event->tag=tag; event->split=split;
            unsigned ticks;
            ticks = (unsigned int)__rdtsc();
            event->stamp=ticks;
            current=(char*)(event+1);
        }
    }
    static __forceinline ClockX& instance() throw() { return *(ClockX*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))); }
};

template<class T> class StoredX {
    T value;
public:
    __forceinline StoredX() throw() {}
    __forceinline StoredX(T v) throw() : value(v) {}
    __forceinline void operator=(T v) throw() { value=v; }
    __forceinline operator T() const throw() { return value; }
    __forceinline T get() const throw() { return value; }
};

template<class T> __forceinline T* stackAllocateX(int n) {
    T** top=(T**)static_cast<AudioHolder*>(::FUN_00c85750());
    T* result=*top;
    *top=(T*)((char*)result+((n*int(sizeof(T))+127)&~127));
    return result;
}

template<class T> struct BufferX {
    StoredX<T*> data;
    int debugSize;
    __forceinline BufferX(int n) throw() { data=stackAllocateX<T>(n); }
    __forceinline T* begin() throw() { return data; }
    __forceinline ~BufferX() throw() { *(T**)static_cast<AudioHolder*>(::FUN_00c85750())=data.get(); }
};

// @fnv 0x00ce3090
void __cdecl MapperX::FUN_00ce3090(const PoseX* original,PoseX* output,const short* mapA,const short* mapB,bool additive) const {
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockListX* event=(ClockListX*)timer.current;
            event->tag="LtMapPoseLocalSpace";
            event->split="Stinit";
            unsigned ticks;
            ticks = (unsigned int)__rdtsc();
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockEventX* event=(ClockEventX*)timer.current;
            event->tag="StsimpleMappings";
            
            unsigned ticks;
            ticks = (unsigned int)__rdtsc();
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
    const BoolX sparse=mapA&&mapB;
    BufferX<PoseX> scratch(first->bones.count());
    if (additive) ::FUN_00ce2f30();
    const PoseX* input=additive?scratch.begin():original;
    {
        const int total=records.count();
        for(int i=0;i<total;++i) {
            _mm_prefetch((const char*)&records[i]+128,_MM_HINT_NTA);
            const RecordX& r=records[i];
            int a=r.a,b=r.b;
            if(sparse) { a=mapA[a]; if(a<0) continue; b=mapB[b]; }
            ::FUN_00ce2ca0((void *)(property),(__m128 *)&(output[b]),(const __m128 *)&(r.offset),(const __m128 *)&(input[a]));
            _mm_prefetch((const char*)&input[a]+128,_MM_HINT_NTA);
            _mm_prefetch((const char*)&output[b]+128,_MM_HINT_NTA);
        }
    }
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockEventX* event=(ClockEventX*)timer.current;
            event->tag="StchainMappings";
            
            unsigned ticks;
            ticks = (unsigned int)__rdtsc();
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
    {
        const int total=links.count();
        for(int i=0;i<total;++i) {
            const LinkX& r=links[i];
            VectorX posA,posB;
            posA.zero(); posB.zero();
            ScalarX length=0.0f;
            bool valid=true;
            for(short bone=r.b;bone>r.a;bone=first->parents[bone]) {
                short track=sparse?mapA[bone]:bone;
                if(track<0) { valid=false; break; }
                const PoseX& t=input[track];
                VectorX prev(posA);
                posA.rotate(t.orient(),prev);
                posA.add(t.position());
                length=length+t.position().length();
            }
            if(sparse) { valid=valid&&mapA[r.a]>=0; if(!valid) continue; }
            VectorX scale; scale.setProduct(length,r.end.sizing());
            for(short bone=r.d;bone>r.c;bone=second->parents[bone]) {
                short track=sparse?mapB[bone]:bone;
                PoseX& t=output[track];
                t.translation.multiply(scale);
                VectorX prev(posB);
                posB.rotate(t.orient(),prev);
                posB.add(t.position());
            }
            int a=r.a,c=r.c,b=r.b,d=r.d;
            if(sparse) { a=mapA[a];c=mapB[c];b=mapA[b];d=mapB[d]; }
            ::FUN_00ce2ca0((void *)(property),(__m128 *)&(output[c]),(const __m128 *)&(r.root),(const __m128 *)&(input[a]));
            FUN_00ce2a50((FourFloatVector*)&posA,(FourFloatVector*)&posB);
            RotationX shortest; reinterpret_cast<::fnv_00cd9d10::Q_00cd9d10 *>(&shortest)->FUN_00cd9d10((const __m128 *)&posB,(const __m128 *)&posA);
            RotationX offset; offset.vec=r.end.translation;
            RotationX applied; reinterpret_cast<::Quat74 *>(&(applied))->FUN_00c74ac0((const ::Quat74 &)(shortest),(const ::Quat74 &)(offset));
            reinterpret_cast<::fnv_00ce0ca0::FUN_00ce0ca0_Quaternion *>(&output[c].rotation)->FUN_00ce0ca0(*reinterpret_cast<const ::fnv_00ce0ca0::FUN_00ce0ca0_Quaternion *>(&applied));
            ::fnv_00c66320::FUN_00c66320((__m128 *)&(output[d].rotation), nullptr, (const __m128 *)&(r.end.rotation), (const __m128 *)&(input[b].rotation));
        }
    }
    if(additive) ::FUN_00ce2f40((unsigned int)(output),(uintptr_t)(second->reference.begin()),(unsigned int)(mapB),second->bones.count(),(unsigned int)(output));
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockEventX* event=(ClockEventX*)timer.current;
            event->tag="lt";
            
            unsigned ticks;
            ticks = (unsigned int)__rdtsc();
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
}

#include "generated/data/staging/blk_00ce0000_o2.inc"
#include "generated/data/staging/blk_00ce0000_o2_rtm_variant.inc"
#include "generated/data/staging/blk_00ce0000_o2_gs_nogs_variant.inc"
#include "generated/data/staging/blk_00ce0000_o2_gs_nogs_variant_rtm_variant.inc"
