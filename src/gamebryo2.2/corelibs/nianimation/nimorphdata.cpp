
// src/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// Returns the address of the global g_011f3e74.
// @fnv 0x00a415e0
#include <cstdint>
#include <windows.h>
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
void* __cdecl FUN_00a415e0()
{
    return &(*reinterpret_cast<void * *>(&::g_011f3e74));
}

extern int DAT_010976fc;
struct NiRefObject
{
    ~NiRefObject();
};
struct S41660
{
    void FUN_00a41660(int);
};
struct NiMorphData
{
    char _pad[16];
    void* m_pMorphTargets;
    void* FUN_00a41a00(unsigned int);
};
// @fnv 0x00a41a00
void* NiMorphData::FUN_00a41a00(unsigned int auiFlags)
{
    void* p = m_pMorphTargets;
    *(void**)this = (void*)&DAT_010976fc;
    if (p)
        ((S41660*)p)->FUN_00a41660(3);
    reinterpret_cast<class ::FUN_00a5d3d0 *>((((NiRefObject*)this)))->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}

namespace fnv_00a41710 {
struct NiStream
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8(int&);
};
struct NiObject
{
    void* _vfptr;
    int _ref;
    bool RegisterStreamables(NiStream&);
};
struct NiMorphData : NiObject
{
    struct MorphTarget
    {
        int _00;
        int _04;
        int _08;
        int _0C;
    };
    unsigned int m_uiNumTargets;
    unsigned int _pad0C;
    MorphTarget* m_pMorphTargets;
    bool FUN_00a41710(NiStream& kStream);
};
// Registers the base object's streamables, then streams the _04 field of each morph target, returning false if registration fails.
// @fnv 0x00a41710
bool NiMorphData::FUN_00a41710(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    unsigned int ui;
    MorphTarget* pkTarget;
    for (ui = 0; ui < m_uiNumTargets; ui++)
    {
        pkTarget = (ui < m_uiNumTargets ? &m_pMorphTargets[ui] : 0);
        kStream.V8(pkTarget->_04);
    }
    return true;
}
}  // namespace fnv_00a41710

struct NiStream
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void RegisterStreamable(void* pkObject);
};

struct FUN_00a57850_shell
{
    void FUN_00a57850(NiStream& kStream);
};

// @fnv 0x00a57850
void FUN_00a57850_shell::FUN_00a57850(NiStream& kStream)
{
    kStream.RegisterStreamable((void*)((char*)this + 4));
}

struct Object
{
    int field_00;
    int field_04;
    volatile float field_08;
    int field_0c;
    Object* FUN_00a415f0();
};
// @fnv 0x00a415f0
Object* Object::FUN_00a415f0()
{
    field_00 = 0;
    field_04 = (*reinterpret_cast<int *>(&::DAT_0109b220));
    field_08 = 0.0f;
    field_0c = 0;
    return this;
}

extern void* DAT_00fdf1c4;

struct GlobalMgr_b9415
{
};

struct RefItem_b9415
{
    virtual void V0();
    virtual void Delete();
    int m_refs;
};

typedef int(* ReleaseFn_b9415)(int p);

class FUN_00a41610_cls
{
  public:
    intptr_t m_00;
    int m_04;
    int m_08;
    RefItem_b9415* m_0c;
    void ReleaseResources();
};

// @fnv 0x00a41610
void FUN_00a41610_cls::ReleaseResources()
{
    reinterpret_cast<::FNV_MemoryManager *>((((GlobalMgr_b9415*)&(*reinterpret_cast<int *>(&::g_memoryManager)))))->FUN_00aa4060((void *)(m_00));
    ReleaseFn_b9415 pfnRelease = (ReleaseFn_b9415)DAT_00fdf1c4;
    RefItem_b9415* pRefItem = m_0c;
    if (pRefItem != 0)
    {
        if (pfnRelease((intptr_t)&pRefItem->m_refs) == 0)
            pRefItem->Delete();
    }
    if (m_04 != (*reinterpret_cast<int *>(&::DAT_0109b220)))
        pfnRelease(m_04 - 8);
}

namespace fnv_00a41660 {
struct MemoryManager_00a41660
{
};
struct Reference_00a41660
{
    virtual void Unused();
    virtual void Destroy();
    long count;
};
struct Entry_00a41660
{
    void* allocation;
    char* name;
    int unused;
    Reference_00a41660* reference;
};
struct Owner_00a41660
{
    Entry_00a41660 object;
    void* FUN_00a41660(unsigned char flags);
};
// @fnv 0x00a41660
void* Owner_00a41660::FUN_00a41660(unsigned char flags)
{
    if (flags & 2)
    {
        int count = *(int*)((char*)this - 4);
        Entry_00a41660* pEntry = &object + count;
        while (--count >= 0)
        {
            --pEntry;
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a41660::MemoryManager_00a41660 *>(&::g_memoryManager))))->FUN_00aa4060(pEntry->allocation);
            Reference_00a41660* ref = pEntry->reference;
            if (ref)
            {
                if (InterlockedDecrement(&ref->count) == 0)
                    ref->Destroy();
            }
            char* pName = pEntry->name;
            if (pName != ::DAT_0109b220)
                InterlockedDecrement((long volatile*)(pName - 8));
        }
        void* header = (char*)this - 4;
        if (flags & 1)
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a41660::MemoryManager_00a41660 *>(&::g_memoryManager))))->FUN_00aa4060(header);
        return header;
    }
    reinterpret_cast<::FUN_00a41610_cls *>(this)->ReleaseResources();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a41660::MemoryManager_00a41660 *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00a41660

struct MorphBuffer
{
    void* unk00;
    unsigned int used;
    void* unk08;
    int(__cdecl* append)(MorphBuffer*, void*, unsigned int, const unsigned int*, int);
};
static __forceinline unsigned int countBytes(const volatile unsigned int& count)
{
    return count * 4;
}
// @fnv 0x00a417b0
void __cdecl FUN_00a417b0(void* owner, void* source, unsigned int elementCount)
{
    MorphBuffer* __restrict buffer = *reinterpret_cast<MorphBuffer**>(reinterpret_cast<char*>(owner) + 0x250);
    unsigned int stride = 4;
    buffer->used += buffer->append(buffer, source, countBytes(elementCount), &stride, 1);
}

struct FUN_00a417f0_vec3
{
    float x;
    float y;
    float z;
};

struct FUN_00a417f0_cls
{
    FUN_00a417f0_vec3* m_pData;
    unsigned int m_iArrayLength;

    bool Equals(FUN_00a417f0_cls* other, unsigned int n);
};
// @fnv 0x00a417f0
bool FUN_00a417f0_cls::Equals(FUN_00a417f0_cls* other, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
    {
        FUN_00a417f0_vec3 b = other->m_pData[i];
        FUN_00a417f0_vec3 a = m_pData[i];
        if (!(a.x == b.x))
            return false;
        if (!(a.y == b.y))
            return false;
        if (!(a.z == b.z))
            return false;
    }
    if (m_iArrayLength != other->m_iArrayLength)
        return false;
    return true;
}

// NiMorphData::SaveBinary: base data, target/vertex counts, relative flag, then each morph
// target's name and vertex array. WriteBinaryArray multiplies by the uiSize variable (Gamebryo form).
struct NiBinaryStream;
typedef unsigned int(__cdecl* NiBinWriteFn)(NiBinaryStream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NiBinWriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};

template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

struct NiFixedStr
{
    const char* m_handle;
};

struct NiStreamM
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
    intptr_t unk24C;
    NiBinaryStream* m_pBackingStream;

};

inline void SerializeValue(NiStreamM& kStream, const unsigned int& uiValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &uiValue, 1);
}

inline void SerializeValue(NiStreamM& kStream, const char& cValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &cValue, 1);
}

inline void SerializeValue(NiStreamM& kStream, const float* pfValues, unsigned int uiNumEls)
{
    WriteBinaryArray(*kStream.m_pBackingStream, pfValues, uiNumEls);
}

struct NiPt3
{
    float x, y, z;
};

inline void SerializeValue(NiStreamM& kStream, const NiPt3* pkValues, unsigned int uiNumEls)
{
    SerializeValue(kStream, (const float*)pkValues, uiNumEls * 3);
}

struct NiObjBase
{
    void* m_ppVirtualMethodTable;
    int m_uiRefCount;
};

struct MorphTgt
{
    NiPt3* m_aVerts;
    NiFixedStr m_kName;
    int unk08;
    int unk0C;

    void SaveBinary(NiStreamM& kStream, unsigned int m_uiScaleCount)
    {
        reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)&(m_kName));
        if (m_uiScaleCount)
            SerializeValue(kStream, m_aVerts, m_uiScaleCount);
    }
};

struct NiMorphDataX : NiObjBase
{
    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTgt* m_pMorphTargets;
    bool m_bTargetsAreRelative;

    void FUN_00a41d90(NiStreamM& kStream);
};

// @fnv 0x00a41d90
void NiMorphDataX::FUN_00a41d90(NiStreamM& kStream)
{
    ::FUN_00a89af0((intptr_t)this);
    SerializeValue(kStream, m_uiNumTargets);
    SerializeValue(kStream, m_uiNumVertsPerTarget);
    char cRelative = m_bTargetsAreRelative;
    SerializeValue(kStream, cRelative);
    for (unsigned int i = 0; i < m_uiNumTargets; i++)
        m_pMorphTargets[i].SaveBinary(kStream, m_uiNumVertsPerTarget);
}

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    inline unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
    __forceinline unsigned int AddInl(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAtInl(uiIndex, element);
        return uiIndex;
    }
    __forceinline void SetAtInl(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
};

struct MorphTarget
{
    void* vtbl;
    char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
    int unk08;
    int unk0c;
};



struct NiObjectBase
{
};

struct NiMorphDataV : NiObjectBase
{
    int unk00;
    int unk04;
    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTarget* m_pMorphTargets;
    MorphTarget* GetTarget(unsigned int i)
    {
        return i < m_uiNumTargets ? &m_pMorphTargets[i] : 0;
    }
    void AppendToStrings(ViewerStrings* pkStrings);
};

// Appends the base object's strings, the target and vertex counts, a MorphTargets header, and each target's name to pkStrings.
// @fnv 0x00a41ea0
void NiMorphDataV::AppendToStrings(ViewerStrings* pkStrings)
{
    reinterpret_cast<::A5D6E0This *>(this)->AppendCameraPathEntries((::NiTArray< ::BGSCameraPath *, ::NiTMallocInterface< ::BGSCameraPath *>> *)(pkStrings));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d330((const char*)(*reinterpret_cast<void * *>(&::g_011f3e74)))));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d510("m_uiNumTargets", m_uiNumTargets)));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d510("m_uiNumVertsPerTarget", m_uiNumVertsPerTarget)));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d330("MorphTargets")));
    for (unsigned int i = 0; i < m_uiNumTargets; i++)
        pkStrings->AddInl(::fnv_00a7d5e0::FUN_00a7d5e0("m_pcName", GetTarget(i)->GetName()));
}

struct FNVBinaryInput
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(FNVBinaryInput*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(const void* data, unsigned int bytes, unsigned int* elementSize, unsigned int elementCount)
    {
        unsigned int bytesRead = m_pfnRead(this, data, bytes, elementSize, elementCount);
        m_uiStreamFlags += bytesRead;
        return bytesRead;
    }
};
template <class T> inline unsigned int FNVReadElements(FNVBinaryInput& stream, const T* data, unsigned int count)
{
    unsigned int elementSize = sizeof(T);
    return stream.Read(data, count * elementSize, &elementSize, 1);
}
// Reads count unsigned int elements from the stream pointed to by context->unk24C via FNVReadElements.
// @fnv 0x00a41770
void __cdecl ReadElements(NiStreamM* apStreamContext, const unsigned int* data, unsigned int count)
{
    FNVBinaryInput* stream = reinterpret_cast<FNVBinaryInput*>(apStreamContext->unk24C);
    FNVReadElements(*stream, data, count);
}

struct MemoryManager
{
};
typedef unsigned int(__cdecl* NiBinReadFn_a41940)(struct NiBinIstr_a41940*, void*, unsigned int, unsigned int*,
                                                  unsigned int);
struct NiBinIstr_a41940
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    NiBinReadFn_a41940 m_pfnRead;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
template <class T> inline void NiBinIstrLoad_a41940(NiBinIstr_a41940* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
struct NiFixedStrL_a41940
{
    const char* m_handle;
};
struct NiStreamL_a41940
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
    unsigned int m_uiNifVersion;
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
    NiBinIstr_a41940* m_pUnderlyingStream;
};
struct NiPoint3_a41940
{
    float x, y, z;
    static void* operator new[](size_t uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(uiSize);
    }
};
struct MorphTarget_a41940
{
    NiPoint3_a41940* m_aVerts;
    NiFixedStrL_a41940 m_kName;
    float m_fMorphWeight;
    void Load(NiStreamL_a41940& kStream, unsigned int m_uiScaleCount);
};
// Reads m_kName, optionally m_fMorphWeight, and allocates and fills m_aVerts from kStream based on m_uiNifVersion.
// @fnv 0x00a41940
void MorphTarget_a41940::Load(NiStreamL_a41940& kStream, unsigned int m_uiScaleCount)
{
    if (kStream.m_uiNifVersion < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kName));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kName));
    if (kStream.m_uiNifVersion >= 0x0A010068 && kStream.m_uiNifVersion < 0x14010003)
        NiBinIstrLoad_a41940(kStream.m_pUnderlyingStream, &m_fMorphWeight, 1);
    m_aVerts = new NiPoint3_a41940[m_uiScaleCount];
    NiBinIstrLoad_a41940(kStream.m_pUnderlyingStream, (float*)m_aVerts, m_uiScaleCount * 3);
}

struct EqualVec
{
    float x;
    float y;
    float z;
};
struct MorphEqualTarget
{
    EqualVec* vertices;
    const char* name;
    int m08;
    int m0c;
    bool Equals(MorphEqualTarget* other, unsigned int val);
};
struct MorphEqualData
{
    int m_00;
    int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    MorphEqualTarget* m_10;
    unsigned char m_14;
    bool FUN_00a418a0(MorphEqualData* other);
};

__declspec(noinline) bool MorphEqualTarget::Equals(MorphEqualTarget* other, unsigned int val)
{
    for (unsigned int j = 0; j < val; ++j)
    {
        EqualVec a = vertices[j];
        EqualVec b = other->vertices[j];
        if (a.x != b.x || a.y != b.y || a.z != b.z)
            return false;
    }
    return name == other->name;
}

// Compares two MorphEqualData instances by checking m_08, m_0c, m_14 and each MorphEqualTarget in m_10 via Equals.
// @fnv 0x00a418a0
bool MorphEqualData::FUN_00a418a0(MorphEqualData* other)
{
    if (!reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(other)))
    {
        return false;
    }
    int otherCount = other->m_08;
    MorphEqualData* pOther = other;
    unsigned int thisCount = m_08;
    if (thisCount != otherCount)
    {
        return false;
    }
    if (m_0c != other->m_0c)
    {
        return false;
    }
    if (m_14 == other->m_14)
    {
        for (unsigned int i = 0; i < thisCount; ++i)
        {
            MorphEqualTarget* pOtherTarget = (i < otherCount) ? (pOther->m_10 + i) : 0;
            MorphEqualTarget* pThisTarget = (i < thisCount) ? (m_10 + i) : 0;
            if (!reinterpret_cast<::FUN_00a417f0_cls *>((pThisTarget))->Equals((::FUN_00a417f0_cls *)(pOtherTarget), m_0c))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nimorphdata.inc"
