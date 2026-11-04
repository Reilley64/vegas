// gamebryo2.2/corelibs/nimain/nitribasedgeomdata.cpp: NiTriBasedGeomData (12 functions)

#include "fnv/symbols_00a8a000.h"
#include <cstdint>
#include <new>
#include "fnv/decl/FUN_00a67c00.h"
#include "fnv/decl/GeomData.h"
#include "fnv/decl/GeometryEquality.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a67c70__FUN_00a67c70_shell.h"
#include "fnv/decl/fnv_00a67ea0__GeomEA0.h"
#include "fnv/decl/fnv_00a68520__NiGeometryDataSave.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00d3d000.h"
#include "fnv/symbols_0109f000.h"
#include "fnv/symbols_011f5000.h"
#include "nitribasedgeomdata_decls.h"
// Constructs a NiTriBasedGeomData by initializing the NiGeometryData base and storing the triangle count in m_usTriangles.
// @fnv 0x00a8a920
NiTriBasedGeomData::NiTriBasedGeomData(unsigned short ausVertexCount, NiPoint3* apVertices, NiPoint3* apNormals,
                                       RgbaColor* d, NiPoint2* apTextureCoords, unsigned short f,
                                       NiGeometryData__DataFlags aeDataFlags, unsigned short ausTriangleCount)
    : NiGeometryData(ausVertexCount, apVertices, apNormals, d, apTextureCoords, f, aeDataFlags),
      m_usTriangles(ausTriangleCount)
{}


// @fnv 0x00a8a970
NiTriBasedGeomData* InitializeTriBasedGeomData(NiTriBasedGeomData* pThis)
{
    new ((void *)(pThis)) struct ::FUN_00a67c00();
    pThis->m_usTriangles = 0;
    *(void**)pThis = &(*reinterpret_cast<void * *>(&::DAT_0109f2f4));
    return pThis;
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a8aa30_shell : public NiTriBasedGeomData
{
    void FUN_00a8aa30(NiStream*);
};

struct FakeBinaryStream
{
    int pad;
    unsigned int position;
    unsigned int(__cdecl* read)(void*, void*, unsigned int, unsigned int*, unsigned int);
};

// Loads NiGeometryData binary data from the stream, then reads 2 bytes from the stream's binary reader into this+0x40.
// @fnv 0x00a8aa30
void FUN_00a8aa30_shell::FUN_00a8aa30(NiStream* kStream)
{
    reinterpret_cast<::fnv_00a67ea0::GeomEA0 *>((reinterpret_cast<NiGeometryData*>(this)))->ReadBinary((::fnv_00a67ea0::StreamEA0 &)(*kStream));
    FakeBinaryStream* __restrict input =
        *reinterpret_cast<FakeBinaryStream**>(reinterpret_cast<char*>(kStream) + 0x24c);
    unsigned int size = 2;
    input->position += input->read(input, reinterpret_cast<char*>(&this->m_usTriangles), 2, &size, 1);
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a8aa70_shell : public NiTriBasedGeomData
{
    void FUN_00a8aa70(NiStream*);
};

struct NiBinaryStream_Save
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(void*, const void*, unsigned int, unsigned int*, unsigned int);
};

// @fnv 0x00a8aa70
void FUN_00a8aa70_shell::FUN_00a8aa70(NiStream* kStream)
{
    reinterpret_cast<::fnv_00a68520::NiGeometryDataSave *>(this)->FUN_00a68520((::fnv_00a68520::SaveStream &)(*kStream));
    NiBinaryStream_Save* __restrict output = *(NiBinaryStream_Save**)((char*)kStream + 0x250);
    unsigned int size = 2;
    output->m_uiStreamFlags += output->m_pfnWrite(output, (char*)&this->m_usTriangles, 2, &size, 1);
}


// @fnv 0x00a8a9f0
char const* const* __cdecl FUN_00a8a9f0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5b90));
}

struct StrArr
{
    void* m_pkArray;
    void* m_reserved;
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short m_reserved2;
    unsigned short m_uiGrowSize;

};

template <class T> struct NiTPrimitiveArray : public StrArr
{
};

struct FUN_00a8aab0_shell
{
    unsigned char m_auiShapeKeys[0x40];
    unsigned short m_usTriangles;

    void AppendTrianglesInfo(NiTPrimitiveArray<char*>* pkStrings);
};


// Calls RegisterFields, then appends a string from g_011f4a70_arg1 and a formatted m_usTriangles entry to pkStrings, growing it when full.
// @fnv 0x00a8aab0
void FUN_00a8aab0_shell::AppendTrianglesInfo(NiTPrimitiveArray<char*>* pkStrings)
{
    reinterpret_cast<::GeomData *>(this)->RegisterFields((::StrArr *)(pkStrings));

    char* pString = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f5b90)));

    unsigned int uiSize = pkStrings->m_uiSize;
    unsigned int uiCapacity = pkStrings->m_uiCapacity;
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowSize = pkStrings->m_uiGrowSize;
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + uiGrowSize);
    }

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, pString);

    pString = FUN_00a7d490("m_usTriangles", m_usTriangles);

    uiSize = pkStrings->m_uiSize;
    uiCapacity = pkStrings->m_uiCapacity;
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowSize = pkStrings->m_uiGrowSize;
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + uiGrowSize);
    }

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, pString);
}


struct FUN_00a8a990_shell
{
    void* vptr;
    void FUN_00a8a990();
};

// @fnv 0x00a8a990
void FUN_00a8a990_shell::FUN_00a8a990()
{
    vptr = (*reinterpret_cast<void * (*)[]>(&::DAT_0109f2f4));
    reinterpret_cast<::fnv_00a67c70::FUN_00a67c70_shell *>(this)->DestroyGeometryData();
}

struct S_00a8a9c0_Base
{
    virtual void v00();
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
struct S_00a8a9c0 : S_00a8a9c0_Base
{
    unsigned short m_usTriangles;
    unsigned char MatchesTriangleCount(const S_00a8a9c0_Base* pkObject);
};
// Returns false if FUN_00a67840 fails, otherwise returns whether m_usTriangles equals the passed object's m_usTriangles.
// @fnv 0x00a8a9c0
unsigned char S_00a8a9c0::MatchesTriangleCount(const S_00a8a9c0_Base* pkObject)
{
    if (!reinterpret_cast<::GeometryEquality *>(this)->FUN_00a67840((::NiObject *)(pkObject)))
        return false;
    return m_usTriangles == ((const S_00a8a9c0*)pkObject)->m_usTriangles;
}



struct FUN_00a8aa00_cls
{
    intptr_t m_vptr;
    int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned short m_usTriangles;


    FUN_00a8aa00_cls* Destroy(unsigned char acFlags);
};

// Sets the vtable pointer, calls BaseCleanup, and frees the object with FUN_00aa1460 when acFlags bit 0 is set; returns this.
// @fnv 0x00a8aa00
FUN_00a8aa00_cls* FUN_00a8aa00_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (intptr_t)&DAT_0109f2f4;
    reinterpret_cast<::fnv_00a67c70::FUN_00a67c70_shell *>(this)->DestroyGeometryData();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x44);
    }
    return this;
}

struct FUN_00a8a9b0 : NiGeometryData
{
    virtual bool RegisterStreamables(NiStream&);
};
// @fnv 0x00a8a9b0
bool FUN_00a8a9b0::RegisterStreamables(NiStream& kStream)
{
    return NiGeometryData::RegisterStreamables(kStream);
}

// @fnv 0x00d3dd00
void FUN_00d3dd00(intptr_t a, int b, int c, int d)
{}

// @fnv 0x00a8a9a0
void FUN_00a8a9a0_shell::FUN_00a8a9a0(::NiStream& kStream)
{
    reinterpret_cast<::NiGeometryData *>(this)->LinkObject(kStream);
}
