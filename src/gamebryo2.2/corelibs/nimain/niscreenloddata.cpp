// gamebryo2.2/corelibs/nimain/niscreenloddata.cpp: NiScreenLODData, Fake, Holder, LodPart_cls and more (17 functions)

#include <new>
#include <cstring>
#include "fnv/decl/FUN_008b42e0_shell.h"
#include "fnv/decl/FUN_00a991d0_shell.h"
#include "fnv/decl/FUN_00aa09a0.h"
#include "fnv/decl/FUN_00aa09c0_cls.h"
#include "fnv/decl/NiSphere.h"
#include "fnv/decl/S_00a7fea0_Class.h"
#include "fnv/decl/Sphere.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a72000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a88000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "niscreenloddata_decls.h"
// @fnv 0x00a86530
void NiScreenLODData::UpdateScreenBound(NiBound& bound)
{
    ScreenBone* bone = data->bones;
    bound.Update(bone->bound, objects[0]->world);
    unsigned int count = data->count;
    for (unsigned int i = 1; i < count; i++)
    {
        const NiTransform& transform = objects[i]->world;
        NiBound current;
        if (transform.scale == 1.0f)
        {
            current = bone[i].bound;
            current.center = current.center + transform.translation;
        }
        else
            current.Update(bone[i].bound, transform);
        reinterpret_cast<::Sphere *>(&(bound))->FUN_00a7f3f0((*(const ::Sphere *)(&current)));
    }
    NiTransform inverse;
    reinterpret_cast<::FUN_008b42e0_shell *>((void *)&(root->world))->InvertTransform((::NiTransform *)&(inverse));
    ScreenData* finalData = data;
    inverse = finalData->transform * inverse;
    reinterpret_cast<::S_00a7fea0_Class *>(&(bound))->TransformPoint((const ::S_00a7fea0_Xf &)(inverse));
}

struct FUN_00a95cb0_shell : public NiScreenLODData
{
    void* FUN_00a95cb0();
};


// @fnv 0x00a95cb0
void* FUN_00a95cb0_shell::FUN_00a95cb0()
{
    return &(*reinterpret_cast<void * *>(&::g_011f5ee8));
}

struct FUN_00a95c80_shell : public NiScreenLODData
{
    int ClampToLODCount(int v);
};

// @fnv 0x00a95c80
int FUN_00a95c80_shell::ClampToLODCount(int aiIndex)
{
    if (aiIndex < 0)
        return 0;
    int n = *(int*)((char*)this + 0x28);
    return aiIndex < n ? aiIndex : n;
}

struct Holder
{
};
struct Fake
{
    void* vtable;
    char pad[0x28];
    float* prop;
    void* Destroy(unsigned int);
};
// Sets the vtable, frees prop, calls FUN_00aa09c0, and if f has bit 0 set deletes this with size 0x30, returning this.
// @fnv 0x00a95d20
void* Fake::Destroy(unsigned int auiFlags)
{
    vtable = (void*)&DAT_010a051c;
    ::FUN_00aa10f0(prop);
    reinterpret_cast<::FUN_00aa09c0_cls *>((((Holder*)this)))->FUN_00aa09c0_cls::~FUN_00aa09c0_cls();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x30);
    return this;
}

namespace fnv_00a961a0 {
struct NiLODNode
{
    char _pad[0x68];
    NiTransform m_kWorldSpaceTransform;
};
struct Helper
{
    void MergeBoundsFromSource(NiLODNode*);
};
struct Holder
{
    char _pad0[8];
    NiBound m_kBound;
    NiBound m_kWorldBound;
    void UpdateWorldBound(NiLODNode*);
};
// @fnv 0x00a961a0
void Holder::UpdateWorldBound(NiLODNode* pkLOD)
{
    if (m_kBound.radius == 0.0f)
        ((Helper*)this)->MergeBoundsFromSource(pkLOD);
    else
        m_kWorldBound.Update(m_kBound, pkLOD->m_kWorldSpaceTransform);
}
}  // namespace fnv_00a961a0


struct FUN_00a95d60_shell : public NiScreenLODData
{
    void SetProportionCount(unsigned int count);
};

// Resizes the proportions array to count floats, copying the existing entries, or frees it and clears the count when count is zero.
// @fnv 0x00a95d60
void FUN_00a95d60_shell::SetProportionCount(unsigned int count)
{
    if (count != *(unsigned int*)((char*)this + 0x28))
    {
        if (!count)
        {
            ::FUN_00aa10f0(*(float**)((char*)this + 0x2c));
            *(float**)((char*)this + 0x2c) = 0;
            *(unsigned int*)((char*)this + 0x28) = 0;
            return;
        }
        float* pfNewProportions = (float*)::FUN_00aa1070(count * 4);
        if (*(float**)((char*)this + 0x2c))
        {
            unsigned int uiCopyCount =
                *(int*)((char*)this + 0x28) < (int)count ? *(int*)((char*)this + 0x28) : (int)count;
            std::memmove(pfNewProportions, *(float**)((char*)this + 0x2c), uiCopyCount * 4);
        }
        ::FUN_00aa10f0(*(float**)((char*)this + 0x2c));
        *(float**)((char*)this + 0x2c) = pfNewProportions;
        *(unsigned int*)((char*)this + 0x28) = count;
    }
}

struct A51BF0Base
{
};

struct FUN_00a95cc0_shell
{
    void* InitializeScreenLODData();
};

// @fnv 0x00a95f20
void* AllocateAndConstruct()
{
    void* p = ::operator new(0x30);
    return p ? reinterpret_cast<FUN_00a95cc0_shell*>(p)->InitializeScreenLODData() : 0;
}

struct ScreenObj_cls
{
    unsigned int unk00[8];
    NiBound* m_20;
};

struct Xform_cls
{
};

struct ScreenSrc_cls
{
    unsigned int unk00[0x1a];
    NiTransform m_68;
    unsigned int unk9c;
    ScreenObj_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};


struct LodPart_cls
{
    unsigned int unk00[2];
    NiBound m_08;
    NiBound m_18;
    void MergeBoundsFromSource(ScreenSrc_cls* src);
};

// @fnv 0x00a95fb0
void LodPart_cls::MergeBoundsFromSource(ScreenSrc_cls* apSource)
{
    NiTransform local;
    reinterpret_cast<::FUN_00a991d0_shell *>((apSource))->UpdateChildrenWorldData();
    m_18.radius = 0.0f;
    for (int i = 0; i < apSource->m_a6; ++i)
    {
        ScreenObj_cls* o = apSource->m_a0[i];
        if (o != 0)
        {
            NiBound* b = o->m_20;
            if (b == 0)
            {
                b = (NiBound*)&(*reinterpret_cast<int *>(&::g_defaultBound));
            }
            reinterpret_cast<::Sphere *>(&(m_18))->FUN_00a7f3f0((*(const ::Sphere *)(b)));
        }
    }
    reinterpret_cast<::NiTransform *>((((Xform_cls*)&apSource->m_68)))->CalculateInverse(local);
    m_08.Update(m_18, local);
}

class A960A0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A960A0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A960A0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A960A0Object;

class A960A0Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(A960A0Object* pkObject);

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
    A960A0BinaryStream* m_pBackingStream;
};

template <class T>
inline void A960A0BinaryStreamSave(A960A0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A960A0SaveBinary(A960A0Stream& kStream, const T& value)
{
    A960A0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A960A0Sphere
{
  public:

    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fBoundRadius;
};

class A960A0Object
{
  public:

    int unk00;
    int unk04;
};

class A960A0Data : public A960A0Object
{
  public:
    A960A0Sphere m_kBoundA;
    A960A0Sphere m_kBoundB;
    unsigned int m_uiCount;
    int* m_piIndices;

    void FUN_00a960a0(A960A0Stream& kStream);
};

// SaveBinary
// Saves the base object, both bounding spheres, the index count and each index to the stream.
// @fnv 0x00a960a0
void A960A0Data::FUN_00a960a0(A960A0Stream& kStream)
{
    ::FUN_00a724d0();
    reinterpret_cast<::NiSphere *>(&(m_kBoundA))->SaveBinary((::NiStream &)(kStream));
    reinterpret_cast<::NiSphere *>(&(m_kBoundB))->SaveBinary((::NiStream &)(kStream));
    A960A0SaveBinary(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        A960A0SaveBinary(kStream, m_piIndices[i]);
}

struct ShapeSub
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
};

struct FUN_00a96130_cls
{
    int unk00;
    int unk04;
    ShapeSub m_08;
    ShapeSub m_18;
    unsigned int m_uiItemCount;
    float* m_iSlotIds;

    bool Equals(FUN_00a96130_cls* other);
};

// @fnv 0x00a96130
bool FUN_00a96130_cls::Equals(FUN_00a96130_cls* other)
{
    if (reinterpret_cast<::NiBound *>(&(m_08))->FUN_00a926b0((*(const ::NiBound *)(&other->m_08))))
    {
        return false;
    }
    if (reinterpret_cast<::NiBound *>(&(m_18))->FUN_00a926b0((*(const ::NiBound *)(&other->m_18))))
    {
        return false;
    }
    if (m_uiItemCount != other->m_uiItemCount)
    {
        return false;
    }
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        if (!(other->m_iSlotIds[i] == m_iSlotIds[i]))
        {
            return false;
        }
    }
    return true;
}

namespace fnv_00a95cc0 {

struct S_00a95cc0_Foo
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    int unk18;
    int unk1c;
    int unk20;
    float unk24;
    volatile int unk28;
    volatile int unk2c;
};

struct S_00aa09a0_Foo
{
};

struct FUN_00a95cc0_shell : public NiScreenLODData
{
    FUN_00a95cc0_shell* InitializeScreenLODData();
};

// @fnv 0x00a95cc0
FUN_00a95cc0_shell* FUN_00a95cc0_shell::InitializeScreenLODData()
{
    S_00a95cc0_Foo* p = reinterpret_cast<S_00a95cc0_Foo*>(this);
    S_00aa09a0_Foo* q = reinterpret_cast<S_00aa09a0_Foo*>(this);

    new ((void *)(q)) ::FUN_00aa09a0();

    p->unk00 = reinterpret_cast<void*>(&::DAT_010a051c);
    p->unk08 = (*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    p->unk0c = ::_DAT_011f4270;
    p->unk10 = ::_DAT_011f4274;
    p->unk14 = 0.0f;
    p->unk18 = (*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    p->unk1c = ::_DAT_011f4270;
    p->unk20 = ::_DAT_011f4274;
    p->unk24 = 0.0f;
    p->unk28 = 0;
    p->unk2c = 0;

    return this;
}
}  // namespace fnv_00a95cc0

struct FUN_00a96030_cls
{
    int unk00;
    int unk04;
    NiBound m_08;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned int m_28;
    void* m_2c;
    void* CloneWithBounds(unsigned int unused);
};

void* InitializeScreenLODData();
void SetProportionCount(unsigned int count);

// Allocates a new object, copies the NiBound center and radius, copies m_28 entries from m_2c, and returns the new object.
// @fnv 0x00a96030
void* FUN_00a96030_cls::CloneWithBounds(unsigned int unused)
{
    FUN_00a96030_cls* result;
    float radius;
    void* pMemory = ::operator new(0x30);
    if (pMemory != 0)
    {
        result = (FUN_00a96030_cls*)((FUN_00a95cc0_shell*)pMemory)->InitializeScreenLODData();
    }
    else
    {
        result = 0;
    }
    float* pRadius = &radius;
    *pRadius = m_08.radius;
    result->m_08.center = m_08.center;
    result->m_08.radius = radius;
    ((FUN_00a95d60_shell*)result)->SetProportionCount(m_28);
    std::memmove(result->m_2c, m_2c, m_28 * 4);
    return result;
}

struct S_00a58160_Stream
{
};
struct S_00a58160_Foo
{
};
struct FUN_00a95ca0_shell : public S_00a58160_Foo
{
    void FUN_00a95ca0(S_00a58160_Stream& s);
};
// @fnv 0x00a95ca0
void FUN_00a95ca0_shell::FUN_00a95ca0(S_00a58160_Stream& s)
{
    ::FUN_00a724d0();
}

struct FUN_00a95f40_cls
{
    char unk00[8];
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    float m_14;
    char unk18[0x10];
    unsigned int m_28;
    void* m_2c;
    void* Clone();
};

// Allocates a 0x30-byte copy, copies m_08..m_14, calls SetProportionCount with m_28, then memmoves m_28*4 bytes from m_2c into the copy and returns it.
// @fnv 0x00a95f40
void* FUN_00a95f40_cls::Clone()
{
    FUN_00a95f40_cls* dst;
    void* raw = ::operator new(0x30);
    if (raw != 0)
    {
        dst = (FUN_00a95f40_cls*)reinterpret_cast<FUN_00a95cc0_shell*>(raw)->InitializeScreenLODData();
    }
    else
    {
        dst = 0;
    }
    float fValue = m_14;
    dst->m_08 = m_08;
    dst->m_0c = m_0c;
    dst->m_10 = m_10;
    dst->m_14 = fValue;
    reinterpret_cast<FUN_00a95d60_shell*>(dst)->SetProportionCount(m_28);
    std::memmove(dst->m_2c, m_2c, m_28 * 4);
    return dst;
}

struct StreamOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    A960A0BinaryStream* binary;
};
struct BoundLoader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
template <class T> inline void ReadValue(A960A0BinaryStream& in, T* value)
{
    unsigned int size = sizeof(T);
    in.m_uiStreamFlags += in.m_pfnRead(&in, value, size, &size, 1);
}
struct FUN_00a961d0_cls
{
    int unk00;
    int unk04;
    BoundLoader m_08;
    BoundLoader m_18;
    unsigned int m_uiItemCount;
    unsigned int* m_iSlotIds;
    void SetProportionCount(unsigned int size);
    void LoadFromStream(StreamOwner* owner);
};
// @fnv 0x00a961d0
void FUN_00a961d0_cls::LoadFromStream(StreamOwner* owner)
{
    reinterpret_cast<::FUN_00a88a40_shell *>(this)->FUN_00a88a40(*(::NiStream *)owner);
    reinterpret_cast<::NiSphere *>(&(m_08))->LoadBinary((*(::NiStream *)(owner)));
    reinterpret_cast<::NiSphere *>(&(m_18))->LoadBinary((*(::NiStream *)(owner)));
    unsigned int numberOfValues;
    ReadValue(*owner->binary, &numberOfValues);
    reinterpret_cast<::FUN_00a95d60_shell *>(this)->SetProportionCount(numberOfValues);
    for (unsigned int i = 0; i < numberOfValues; ++i)
    {
        ReadValue(*owner->binary, &m_iSlotIds[i]);
    }
}

struct StrArray
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
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
    unsigned int SetAtGrow(unsigned int uiIndex, char* element)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char* element)
    {
        return SetAtGrow(m_usSize, element);
    }
    unsigned int AddCall(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
};
struct BoundStr
{
};
struct Obj96270
{
    int unk00;
    int unk04;
    BoundStr m_08;
    int unk0c;
    int unk10;
    int unk14;
    BoundStr m_18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned int m_28;
    float* m_2c;
    void FUN_00a96270(StrArray* pkStrings);
};
// Adds the global string, Bound and World Bound strings, and one formatted proportion string per m_28 entry into pkStrings.
// @fnv 0x00a96270
void Obj96270::FUN_00a96270(StrArray* pkStrings)
{
    pkStrings->AddCall(FUN_00a7d330(*(const char**)&(*reinterpret_cast<void * *>(&::g_011f5ee8))));
    pkStrings->AddCall(reinterpret_cast<::NiBound *>(&(m_08))->FUN_00a7fb20("Bound"));
    pkStrings->AddCall(reinterpret_cast<::NiBound *>(&(m_18))->FUN_00a7fb20("World Bound"));
    for (unsigned int i = 0; i < m_28; i++)
    {
        char* pBuffer = (char*)FUN_00aa1070(0x80);
        ::NiSprintf(pBuffer, 0x80, "Proportion[%d] = %g", i, m_2c[i]);
        pkStrings->Add(pBuffer);
    }
}

#include <math.h>
struct WorkerPoint
{
    float x, y, z;
    WorkerPoint operator-(const WorkerPoint& other) const
    {
        WorkerPoint r;
        r.x = x - other.x;
        r.y = y - other.y;
        r.z = z - other.z;
        return r;
    }
};
struct WorkerCamera
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    WorkerPoint position;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    float left, right, top, bottom;
    int unkec;
    int unkf0;
    unsigned char orthographic;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    float scale;
};
struct WorkerScreen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    WorkerPoint position;
    float radius;
    unsigned int count;
    float* thresholds;
    unsigned int FUN_00a95de0(WorkerCamera*, int);
};
// Computes a camera-scaled extent from the radius and returns the first threshold value less than or equal to it.
// @fnv 0x00a95de0
unsigned int WorkerScreen::FUN_00a95de0(WorkerCamera* camera, int unused)
{
    WorkerPoint delta = position - camera->position;
    float squared = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
    float distance = (float)sqrt(squared);
    if (distance < radius || distance <= 0.000001f)
        return 0;
    float ratio;
    if (camera->orthographic)
        ratio = radius;
    else
        ratio = radius / distance;
    float width = (float)(2.0 / (camera->right - camera->left));
    float height = (float)(2.0 / (camera->top - camera->bottom));
    float extent = width > height ? width : height;
    float projected = extent * ratio * camera->scale;
    unsigned int level = 0;
    while (level < count)
    {
        if (thresholds[level] <= projected)
            return level;
        ++level;
    }
    return level;
}
