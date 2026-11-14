
#include "nitristripsdata_types_NiTriStripsData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include <cstdint>
#include "fnv/decl/FUN_00a66f90_cls.h"
#include "fnv/decl/FUN_00a8a670_shell.h"
#include "fnv/decl/FUN_00a8aa70_shell.h"
#include "fnv/decl/S_00a8a9c0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a66000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a8a000.h"

extern "C" const NiRTTI DAT_011f4a70;
extern "C" void* NiMalloc(unsigned int, const char* = 0, int = 0, const char* = 0);

#include "nitristripsdata_forwarders.h"


// @fnv 0x00a75f30
extern "C" const NiRTTI* __cdecl FUN_00a75f30()
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4a70));
}

class NiTriStripsDataWork : public NiTriStripsData
{
  public:
    void FUN_00a75f40(unsigned short& rNumStrips, const unsigned short*& rStripLengths,
                      const unsigned short*& rStripLists, unsigned int& rNumIndices);
};

// @fnv 0x00a75f40
void NiTriStripsDataWork::FUN_00a75f40(unsigned short& rNumStrips, const unsigned short*& rStripLengths,
                                       const unsigned short*& rStripLists, unsigned int& rNumIndices)
{
    rNumStrips = m_usStrips;
    rStripLengths = m_pusStripLengths;
    rStripLists = m_pusStripLists;
    rNumIndices = (unsigned int)(unsigned short)(m_usStrips * 2 + m_usTriangles);
}


extern const void* DAT_0109d8ac;


// @fnv 0x00a75e20
NiTriBasedGeomData* FUN_00a75e20(NiTriBasedGeomData* self)
{
    InitializeTriBasedGeomData(self);
    unsigned int v = 0;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(self) + 0x44) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(self) + 0x48) = v;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(self) + 0x4c) = v;
    *reinterpret_cast<const void**>(self) = &DAT_0109d8ac;
    return self;
}

struct Standin00a761a0
{
    void FUN_00a76040();
    void* FUN_00a761a0(unsigned int);
};
// @fnv 0x00a761a0
void* Standin00a761a0::FUN_00a761a0(unsigned int flags)
{
    FUN_00a76040();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x50);
    return this;
}

// @fnv 0x00a75f10
int FUN_00a75f10(char* self)
{
    return *reinterpret_cast<int*>(self + 0x4c);
}

struct SharedData_S
{
    char pad_00[0x0c];
    int refCount;
};


struct NiTriStripsDataStandin
{
    virtual void V01() = 0;
    virtual void V02() = 0;
    virtual void V03() = 0;
    virtual void V04() = 0;
    virtual void V05() = 0;
    virtual void V06() = 0;
    virtual void V07() = 0;
    virtual void V08() = 0;
    virtual void V09() = 0;
    virtual void V10() = 0;
    virtual void V11() = 0;
    virtual void V12() = 0;
    virtual void V13() = 0;
    virtual void V14() = 0;
    virtual void V15() = 0;
    virtual void V16() = 0;
    virtual void V17() = 0;
    virtual void V18() = 0;
    virtual void V19() = 0;
    virtual void V20() = 0;
    virtual void V21() = 0;
    virtual void V22() = 0;
    virtual void V23() = 0;
    virtual void V24() = 0;
    virtual void V25() = 0;
    virtual void V26() = 0;
    virtual void V27() = 0;
    virtual void V28() = 0;
    virtual void V29() = 0;
    virtual void V30() = 0;
    virtual void V31() = 0;
    virtual void V32() = 0;
    virtual SharedData_S* GetSharedData() = 0;

    char pad_04[0x3c];
    unsigned short m_total;
    unsigned short m_reserved;
    unsigned short m_uiItemCount;
    void* m_data1;
    void* m_data2;

    void FUN_00a760c0(unsigned short count, unsigned short* data1, unsigned short* data2);
};

// @fnv 0x00a760c0
void NiTriStripsDataStandin::FUN_00a760c0(unsigned short count, unsigned short* data1, unsigned short* data2)
{
    SharedData_S* sharedData = GetSharedData();
    if (sharedData)
    {
        if (data1 != m_data1)
        {
            SharedData_S* releasedData = GetSharedData();
            if (--releasedData->refCount == 0)
            {
                reinterpret_cast<::FUN_00a8a670_shell *>((releasedData))->FUN_00a8a670();
                ::FUN_00aa1460(releasedData, 0x10);
            }
        }

        if (data2 != m_data2)
        {
            SharedData_S* releasedData = GetSharedData();
            if (--releasedData->refCount == 0)
            {
                reinterpret_cast<::FUN_00a8a670_shell *>((releasedData))->FUN_00a8a670();
                ::FUN_00aa1460(releasedData, 0x10);
            }
        }
    }
    else
    {
        if (data1 != m_data1)
            ::FUN_00aa10f0(m_data1);

        if (data2 != m_data2)
            ::FUN_00aa10f0(m_data2);
    }

    unsigned short total = 0;
    unsigned short i = 0;
    m_uiItemCount = count;
    m_data1 = data1;
    m_data2 = data2;
    m_total = total;

    for (; i < count; ++i)
        m_total += data1[i] - 2;
}

struct Point3
{
    float x;
    float y;
    float z;
};
struct Bound
{
    Point3 center;
    float radius;
};
struct FUN_00a8a920
{
    virtual void GetRTTI();
    unsigned int refCount;
    unsigned short vertices;
    unsigned short geometryId;
    unsigned short dataFlags;
    unsigned short dirtyFlags;
    Bound bounds;
    void* vertexData;
    void* normalData;
    void* colors;
    void* textures;
    void* additionalData;
    void* rendererData;
    unsigned char keepFlags;
    unsigned char compressFlags;
    unsigned char vertexLocked;
    unsigned char vertexWriteLocked;
    unsigned char saveVertexData;
    unsigned char reserved3d0;
    unsigned char reserved3d1;
    unsigned char reserved3d2;
    unsigned short triangles;
    FUN_00a8a920(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};
struct FUN_00a75dc0 : FUN_00a8a920
{
    unsigned short strips;
    unsigned short* stripLengths;
    unsigned short* stripLists;
    virtual void GetRTTI();
    FUN_00a75dc0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned short stripCount,
                 unsigned short* lengths, unsigned short* lists);
};
// @fnv 0x00a75dc0
FUN_00a75dc0::FUN_00a75dc0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned short stripCount,
                           unsigned short* lengths, unsigned short* lists)
    : FUN_00a8a920(a1, a2, a3, a4, a5, a6, a7, a8), strips(stripCount), stripLengths(lengths), stripLists(lists)
{}

struct S_a76020_Strips : public NiTriStripsData
{
    unsigned int FUN_00a76020();
};
// @fnv 0x00a76020
unsigned int S_a76020_Strips::FUN_00a76020()
{
    unsigned short listLen = m_usTriangles + m_usStrips * 2;
    unsigned int size = (listLen + m_usStrips) * 2;
    return size + reinterpret_cast<::FUN_00a66f90_cls *>(this)->FUN_00a66f90();
}

class A76340BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A76340BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A76340BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize)
    {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};

class A76340Stream
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
    A76340BinaryStream* m_pBackingStream;
};

template <class T>
inline void A76340BinaryStreamSave(A76340BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A76340SaveBinary(A76340Stream& kStream, const T& value)
{
    A76340BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

template <class T> inline void A76340SaveBinary(A76340Stream& kStream, const T* pValues, unsigned int ItemUpdateArray)
{
    A76340BinaryStreamSave(*kStream.m_pBackingStream, pValues, ItemUpdateArray);
}

class A76340GeomData
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
    unsigned short m_usTriangles;
    unsigned short unk42;

};

// NiTriStripsData::SaveBinary
class A76340StripsData : public A76340GeomData
{
  public:
    unsigned short m_usStrips;
    unsigned short unk46;
    unsigned short* m_pusStripLengths;
    unsigned short* m_pusStripLists;

    unsigned short GetStripIndexCount() const
    {
        return m_usTriangles + 2 * m_usStrips;
    }
    void FUN_00a76340(A76340Stream& kStream);
};

// @fnv 0x00a76340
void A76340StripsData::FUN_00a76340(A76340Stream& kStream)
{
    reinterpret_cast<::FUN_00a8aa70_shell *>(this)->FUN_00a8aa70((::NiStream *)&(kStream));
    A76340SaveBinary(kStream, m_usStrips);
    if (m_usStrips > 0)
    {
        A76340SaveBinary(kStream, m_pusStripLengths, m_usStrips);
        bool bHasPoints = m_pusStripLists != 0;
        A76340SaveBinary(kStream, bHasPoints);
        if (bHasPoints)
            A76340SaveBinary(kStream, m_pusStripLists, GetStripIndexCount());
    }
}

struct NiStream
{
  public:
    void* m_ppVirtualMethodTable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern "C" const char str_0109d984[];
extern "C" const char str_0109d970[];
extern "C" const char str_0109d960[];

struct NiTriStripsSerializer : NiTriStripsData
{
    void FUN_00a76430(NiStream& stream);
    void AppendTrianglesInfo(NiStream& stream);
};

// @fnv 0x00a76430
void NiTriStripsSerializer::FUN_00a76430(NiStream& stream)
{
    AppendTrianglesInfo(stream);
    uintptr_t entry = ((uintptr_t)(::FUN_00a7d330((const char *)(*reinterpret_cast<const NiRTTI* const*>(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4a70)))))));
    unsigned int count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        reinterpret_cast<::ViewerStrings *>(&(stream))->SetSize(count + stream.m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(stream))->SetAt(count, (*(char * *)(&entry)));

    entry = ((uintptr_t)(::FUN_00a7d490((const char *)(str_0109d984), m_usStrips)));
    count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        reinterpret_cast<::ViewerStrings *>(&(stream))->SetSize(count + stream.m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(stream))->SetAt(count, (*(char * *)(&entry)));

    entry = ((uintptr_t)(::FUN_00a7d5a0((const char *)(str_0109d970), (void *)(m_pusStripLengths))));
    count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        reinterpret_cast<::ViewerStrings *>(&(stream))->SetSize(count + stream.m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(stream))->SetAt(count, (*(char * *)(&entry)));

    entry = ((uintptr_t)(::FUN_00a7d5a0((const char *)(str_0109d960), (void *)(m_pusStripLists))));
    count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        reinterpret_cast<::ViewerStrings *>(&(stream))->SetSize(count + stream.m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(stream))->SetAt(count, (*(char * *)(&entry)));
}

namespace fnv_00a761c0 {
struct BinaryA
{
    int unk0;
    unsigned pos;
    unsigned(__cdecl* read)(BinaryA*, void*, unsigned, unsigned*, unsigned);
    void Read(void* dest, unsigned bytes, unsigned component)
    {
        unsigned size = component;
        pos += read(this, dest, bytes, &size, 1);
    }
};
struct NiStream
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned version;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    BinaryA* binary;
};
struct SharedView
{
    int unk0, unk4;
    unsigned char* current;
    int refs;
    void* Allocate(unsigned bytes)
    {
        unsigned char* old = current;
        refs++;
        current += bytes;
        return old;
    }
};
struct BaseLoad
{
};
struct StripLoad : NiTriStripsDataStandin
{
    void FUN_00a761c0(NiStream&);
};
// @fnv 0x00a761c0
void StripLoad::FUN_00a761c0(NiStream& stream)
{
    reinterpret_cast<::FUN_00a8aa30_shell *>((((BaseLoad*)this)))->FUN_00a8aa30((::NiStream *)&(stream));
    stream.binary->Read(&m_uiItemCount, 2, 2);
    if (m_uiItemCount > 0)
    {
        if (GetSharedData())
            m_data1 = ((SharedView*)GetSharedData())->Allocate(m_uiItemCount * sizeof(unsigned short));
        else
            m_data1 = ::FUN_00aa1070(m_uiItemCount * sizeof(unsigned short));
        stream.binary->Read(m_data1, m_uiItemCount * 2, 2);
        bool present;
        if (stream.version >= 0x0a000111)
            stream.binary->Read(&present, 1, 1);
        else
            present = true;
        if (present)
        {
            unsigned int count = (unsigned short)(m_total + 2 * m_uiItemCount);
            if (GetSharedData())
                m_data2 = ((SharedView*)GetSharedData())->Allocate(count * sizeof(unsigned short));
            else
                m_data2 = ::FUN_00aa1070(count * sizeof(unsigned short));
            stream.binary->Read(m_data2, count * 2, 2);
        }
    }
}
}  // namespace fnv_00a761c0

struct TSD : NiTriStripsData
{
    void FUN_00a75e40(unsigned short i, unsigned short& i0, unsigned short& i1, unsigned short& i2) const;
};
// @fnv 0x00a75e40
void TSD::FUN_00a75e40(unsigned short i, unsigned short& i0, unsigned short& i1, unsigned short& i2) const
{
    unsigned short* pusStripLists = m_pusStripLists;
    unsigned short* pusStripLengths = m_pusStripLengths;
    unsigned short usStrip = 0;
    unsigned short usTris = pusStripLengths[usStrip] - 2;
    while (i >= usTris)
    {
        i -= usTris;
        pusStripLists += pusStripLengths[usStrip];
        usStrip++;
        usTris = pusStripLengths[usStrip] - 2;
    }
    if (i & 1)
    {
        i0 = pusStripLists[i + 1];
        i1 = pusStripLists[i];
    }
    else
    {
        i0 = pusStripLists[i];
        i1 = pusStripLists[i + 1];
    }
    i2 = pusStripLists[i + 2];
}

struct FUN_00a8a9c0_s
{
};

class NiTriStripsDataA75F : public NiTriStripsData
{
  public:
    bool FUN_00a75f80(NiObject* pkObject);
};

// @fnv 0x00a75f80
bool NiTriStripsDataA75F::FUN_00a75f80(NiObject* pkObject)
{
    if (!((bool)(reinterpret_cast<::S_00a8a9c0 *>((((FUN_00a8a9c0_s*)this)))->MatchesTriangleCount((const ::S_00a8a9c0_Base *)(pkObject)))))
        return false;

    NiTriStripsData* pkData = (NiTriStripsData*)pkObject;

    if (m_usStrips != pkData->m_usStrips)
        return false;

    unsigned int i;
    for (i = 0; i < m_usStrips; i++)
    {
        if (m_pusStripLengths[i] != pkData->m_pusStripLengths[i])
            return false;
    }

    for (i = 0; i < (unsigned short)(m_usTriangles + 2 * m_usStrips); i++)
    {
        if (m_pusStripLists[i] != pkData->m_pusStripLists[i])
            return false;
    }

    return true;
}


struct NiSharedDataA76
{
    int unk00;
    int unk04;
    int unk08;
    int m_iRefCount;
};

class FUN_00a8a990
{
  public:
    virtual ~FUN_00a8a990() throw();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40;
};

namespace NiTriStripsDataImpl {
class FUN_00a76040 : public FUN_00a8a990
{
  public:
    virtual ~FUN_00a76040();
    virtual NiSharedDataA76* FUN_00a669c0() throw();

    unsigned short m_usStrips;
    unsigned short unk46;
    unsigned short* m_pusStripLengths;
    unsigned short* m_pusStripLists;
};

inline void ReleaseShared(NiSharedDataA76* pkShared) throw()
{
    if (--pkShared->m_iRefCount == 0)
    {
        reinterpret_cast<::FUN_00a8a670_shell *>((pkShared))->FUN_00a8a670();
        ::FUN_00aa1460(pkShared, 0x10);
    }
}

// @fnv 0x00a76040
FUN_00a76040::~FUN_00a76040()
{
    if (((::NiSharedDataA76 *)(::FUN_00a669c0())))
    {
        ReleaseShared(((::NiSharedDataA76 *)(::FUN_00a669c0())));
        ReleaseShared(((::NiSharedDataA76 *)(::FUN_00a669c0())));
    }
    else
    {
        ::FUN_00aa10f0(m_pusStripLengths);
        ::FUN_00aa10f0(m_pusStripLists);
    }
}
}


struct BSFadeNode
{
};

struct StripFactoryHeader
{
    const void* vtable;
};

// @fnv 0x00a75ec0
NiTriBasedGeomData* FUN_00a75ec0(NiTriBasedGeomData*)
{
    NiTriStripsData* p = (NiTriStripsData*)::operator new(sizeof(NiTriStripsData));
    if (p)
    {
        InitializeTriBasedGeomData(p);
        p->m_usStrips = 0;
        p->m_pusStripLengths = 0;
        p->m_pusStripLists = 0;
        ((StripFactoryHeader*)p)->vtable = &DAT_0109d8ac;
        return p;
    }
    return 0;
}

#include "generated/data/gamebryo2.2/corelibs/nimain/nitristripsdata.inc"
