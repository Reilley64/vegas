// gamebryo2.2/corelibs/nianimation/nikeyframemanager.cpp: NiGeomMorpherController (1 function)

#include <cstdint>
#include "fnv/decl/Twin_0044ddc0.h"
#include "nikeyframemanager_decls.h"
#include "fnv/symbols_00aa1000.h"
#include <windows.h>
#include <new>
#include "fnv/decl/AHSeqOwner.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a473d0_class.h"
#include "fnv/decl/FUN_00a4d660.h"
#include "fnv/decl/FUN_00a4da20_cls.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00a64ce0_shell.h"
#include "fnv/decl/FUN_00a6d290.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiStream.h"
#include "fnv/decl/NiTimeController_Luna.h"
#include "fnv/decl/ShaderStringPointerMap.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a48000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"

// @fnv 0x008d3ed0
uintptr_t NiGeomMorpherController::GetNumTargets() const
{
    return m_spMorphTargetData.operator->()
               ? ((uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<GlobalObject_00869f00*>(m_spMorphTargetData.operator->())))->GetName()))
               : 0;
}



// @fnv 0x00a4da80
void* __cdecl FUN_00a4da80()
{
    return &(*reinterpret_cast<void * *>(&::g_011f3fb4));
}

struct Map_00a4da90
{
};
void __cdecl _delete(void*, unsigned int);
struct Holder_00a4da90
{
    char _pad[0x34];
    Map_00a4da90 _map;
    void* FUN_00a4da90(unsigned int);
};
// @fnv 0x00a4da90
void* Holder_00a4da90::FUN_00a4da90(unsigned int flags)
{
    reinterpret_cast<::FUN_00a4d660 *>(&(_map))->FUN_00a4d660::~FUN_00a4d660();
    reinterpret_cast<struct ::FUN_00a6d290 *>(this)->FUN_00a6d290::~FUN_00a6d290();
    if (flags & 1)
        _delete(this, 0x48);
    return this;
}


struct AllocatedAnimationController
{
};
// @fnv 0x00a4db60
void* __cdecl FUN_00a4db60()
{
    void* storage = FUN_00aa13e0(0x48);
    if (storage != 0)
        return ((void *)(new ((void *)(static_cast<AllocatedAnimationController*>(storage))) ::FUN_00a4da20_cls()));
    return 0;
}

struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void ReadBinaryValue(NiBinaryStream* pkStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(&value, sizeof(T), &uiSize, 1);
}

struct MemoryManager
{
};

void __cdecl NiFree(void* p);

template <class T> struct OutArray
{
    virtual ~OutArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
};

template <class T> struct InArray
{
    virtual ~InArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element)
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
        else if (m_pBase[uiIndex] != 0)
        {
            m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};

struct SequenceData
{
    OutArray<unsigned int> m_kArr0;
    OutArray<char*> m_kArr1;
    OutArray<unsigned int> m_kArr2;
    InArray<char*> m_kArr3;
    SequenceData() throw();
};


struct NiStream;
class NiTimeController
{
public:
    void LinkObject(::NiStream &);
};

struct NiStreamR
{
    int Version()
    {
        return *(int*)((char*)this + 0xd8);
    }
    NiBinaryStream* Istr()
    {
        return *(NiBinaryStream**)((char*)this + 0x24c);
    }
};

struct SeqController : NiTimeController
{
    void FUN_00a4db80(NiStreamR& kStream);
};

template <class T> class CA4D780Array
{
  public:
    CA4D780Array(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = new T[m_usMaxSize];
        else
            m_pBase = 0;
    }
    virtual ~CA4D780Array();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class CA4D780PrimitiveArray : public CA4D780Array<T>
{
  public:
    CA4D780PrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : CA4D780Array<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~CA4D780PrimitiveArray();
};

class CA4D780Object;

class FUN_00a4d780
{
  public:
    FUN_00a4d780() throw();

    CA4D780PrimitiveArray<unsigned int> m_kFirstIDs;
    CA4D780PrimitiveArray<CA4D780Object*> m_kFirstObjects;
    CA4D780PrimitiveArray<unsigned int> m_kSecondIDs;
    CA4D780PrimitiveArray<CA4D780Object*> m_kSecondObjects;
};

// @fnv 0x00a4d780
FUN_00a4d780::FUN_00a4d780() throw()
{}

__declspec(nothrow) void __cdecl NiFree(void*);
struct MemShellD810
{
};
extern int PTR_0102102c;
struct RefD810
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    int id;
};
struct SmartD810
{
    RefD810* ptr;
    SmartD810(RefD810* p) : ptr(p)
    {
        if (ptr)
            InterlockedIncrement(&ptr->refs);
    }
};
struct StreamD810
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc,
        unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    unsigned int version;
};
struct FUN_00a47bd0 : RefD810
{
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    RefD810* object;
    unsigned int unk30;
    __declspec(nothrow) FUN_00a47bd0(void*, int, int);
    void SetObject(RefD810* p)
    {
        if (object != p)
        {
            RefD810* pvOld = object;
            if (pvOld && !InterlockedDecrement(&pvOld->refs))
                pvOld->DeleteThis();
            object = p;
            if (p)
                InterlockedIncrement(&p->refs);
        }
    }
};
struct MapD810
{
};
template <class T, int* VTBL> struct ArrD810
{
    int* vtbl;
    T* data;
    unsigned short capacity, size;
    int unk0c;
    ~ArrD810()
    {
        vtbl = VTBL;
        NiFree(data);
    }
};
struct LegacyD810
{
    ArrD810<unsigned int, &::DAT_0101a3a4> values;
    ArrD810<void*, &::DAT_0102102c> names;
    ArrD810<unsigned int, &DAT_0101a3a4> counts;
    ArrD810<void*, &DAT_0102102c> linkNames;
    ~LegacyD810()
    {}
};
struct TargetD810
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    MapD810 map;
    void FUN_00a4d810(StreamD810& akStream);
};
// @fnv 0x00a4d810
void TargetD810::FUN_00a4d810(StreamD810& akStream)
{
    reinterpret_cast<::NiTimeController *>(this)->LinkObject((::NiStream &)(akStream));
    if (akStream.version < 0x4010003)
    {
        unsigned int ItemUpdateArray = DAT_011f3fb0->counts.size;
        unsigned int uiLink = 0;
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            void* pvName = DAT_011f3fb0->names.data[i];
            FUN_00a47bd0* pkItem = new FUN_00a47bd0(pvName, 12, 12);
            NiFree(pvName);
            pkItem->unk30 = DAT_011f3fb0->values.data[i];
            pkItem->SetObject(((::RefD810 *)(reinterpret_cast<::NiStream *>(&(akStream))->GetLoadedObject())));
            unsigned int uiEntries = DAT_011f3fb0->counts.data[i];
            while (uiEntries)
            {
                void* pvLink = DAT_011f3fb0->linkNames.data[uiLink];
                --uiEntries;
                ++uiLink;
                RefD810* pkObj = ((::RefD810 *)(reinterpret_cast<::NiStream *>(&(akStream))->GetLoadedObject()));
                reinterpret_cast<::AHSeqOwner *>((pkItem))->AddSeq((const char *)(pvLink), (::S_00a47ae0_Rc *)(pkObj));
                NiFree(pvLink);
            }
            intptr_t id = pkItem->id;
            reinterpret_cast<::ShaderStringPointerMap *>(&(map))->FUN_00e927f0((const char *)(id), (*(::NiPointer< ::ShaderRefObject> *)&(const ::SmartD810 &)(pkItem)));
        }
        delete DAT_011f3fb0;
        DAT_011f3fb0 = 0;
    }
    else
    {
        unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00a63460_shell *>(&(akStream))->FUN_00a63460();
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            RefD810* pkItem = ((::RefD810 *)(reinterpret_cast<::NiStream *>(&(akStream))->GetLoadedObject()));
            intptr_t id = pkItem->id;
            reinterpret_cast<::ShaderStringPointerMap *>(&(map))->FUN_00e927f0((const char *)(id), (*(::NiPointer< ::ShaderRefObject> *)&(const ::SmartD810 &)(pkItem)));
        }
    }
}

struct S_00a4dac0_Obj
{
    virtual void unk_dtor() throw();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    const char* m_name;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct S_00a4dac0_Ptr
{
    S_00a4dac0_Obj* m_p;
    S_00a4dac0_Ptr() : m_p(0)
    {}
    S_00a4dac0_Ptr(const S_00a4dac0_Ptr& o) : m_p(o.m_p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00a4dac0_Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
};
struct S_00a4dac0_Arg
{
    S_00a4dac0_Obj* m_p;
    S_00a4dac0_Arg(S_00a4dac0_Obj* const& o) throw() : m_p(o)
    {
        if (m_p)
            m_p->IncRefCount();
    }
};
struct S_00a4dac0_Map
{
    int unk00;
};
struct S_00a4dac0
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
    S_00a4dac0_Map map34;
    bool FUN_00a4dac0(intptr_t a, const char* name, int b) throw();
};
// @fnv 0x00a4db80
void SeqController::FUN_00a4db80(NiStreamR& kStream)
{
    reinterpret_cast<::NiTimeController_Luna *>(this)->FUN_00a6d5e0((::NiStream &)(kStream));
    unsigned int uiCountB;
    if ((unsigned int)kStream.Version() < 0x4010003)
    {
        unsigned int ItemUpdateArray;
        ReadBinaryValue(kStream.Istr(), ItemUpdateArray);
        while (ItemUpdateArray)
        {
            ItemUpdateArray--;
            bool bFlag;
            ReadBinaryValue(kStream.Istr(), bFlag);
            char* pcName = 0;
            reinterpret_cast<::FUN_00a64ce0_shell *>(&(kStream))->FUN_00a64ce0((char **)&(pcName));
            if (bFlag)
            {
                char* pcName2 = 0;
                reinterpret_cast<::FUN_00a64ce0_shell *>(&(kStream))->FUN_00a64ce0((char **)&(pcName2));
                unsigned int uiValue;
                ReadBinaryValue(kStream.Istr(), uiValue);
                reinterpret_cast<::S_00a4dac0 *>(this)->FUN_00a4dac0((intptr_t)(pcName2), pcName, uiValue);
                NiFree(pcName2);
                NiFree(pcName);
            }
            else
            {
                (*reinterpret_cast<::SequenceData * *>(&::DAT_011f3fb0)) = new SequenceData;
                (*reinterpret_cast<::SequenceData * *>(&::DAT_011f3fb0))->m_kArr1.Add(pcName);
                unsigned int uiValue;
                ReadBinaryValue(kStream.Istr(), uiValue);
                (*reinterpret_cast<::SequenceData * *>(&::DAT_011f3fb0))->m_kArr0.Add(uiValue);
                reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
                unsigned int uiElementCount;
                ReadBinaryValue(kStream.Istr(), uiElementCount);
                (*reinterpret_cast<::SequenceData * *>(&::DAT_011f3fb0))->m_kArr2.Add(uiElementCount);
                while (uiElementCount--)
                {
                    char* pc = 0;
                    reinterpret_cast<::FUN_00a64ce0_shell *>(&(kStream))->FUN_00a64ce0((char **)&(pc));
                    (*reinterpret_cast<::SequenceData * *>(&::DAT_011f3fb0))->m_kArr3.Add(pc);
                    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
                }
            }
        }
    }
    else
    {
        unsigned int uiLinks = 0;
        ReadBinaryValue(kStream.Istr(), uiCountB);
        while (uiCountB--)
        {
            bool bFlag;
            ReadBinaryValue(kStream.Istr(), bFlag);
            if (bFlag)
            {
                char* pcName = 0;
                reinterpret_cast<::FUN_00a64ce0_shell *>(&(kStream))->FUN_00a64ce0((char **)&(pcName));
                char* pcName2 = 0;
                reinterpret_cast<::FUN_00a64ce0_shell *>(&(kStream))->FUN_00a64ce0((char **)&(pcName2));
                unsigned int uiValue;
                ReadBinaryValue(kStream.Istr(), uiValue);
                reinterpret_cast<::S_00a4dac0 *>(this)->FUN_00a4dac0((intptr_t)(pcName2), pcName, uiValue);
                NiFree(pcName);
                NiFree(pcName2);
            }
            else
            {
                reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
                uiLinks++;
            }
        }
        reinterpret_cast<::NiStream *>(&(kStream))->SetLinkIDCount(uiLinks);
    }
}
// @fnv 0x00a4dac0
bool S_00a4dac0::FUN_00a4dac0(intptr_t a, const char* name, int b) throw()
{
    S_00a4dac0_Obj* obj = 0;
    ::CreateOrReleaseRef((const char *)(a), b, (::S_00a48070_Ref **)(::S_00a4dac0_Obj **)(&obj), (void *)(name));
    if (!obj)
        return false;
    if (name)
        reinterpret_cast<::FUN_00a473d0_class *>((obj))->SetString(name);
    const char* key = obj->m_name;
    reinterpret_cast<::ShaderStringPointerMap *>(&(map34))->FUN_00e927f0(key, (*(::NiPointer< ::ShaderRefObject> *)&(const ::S_00a4dac0_Arg &)(obj)));
    if (obj)
        obj->DecRefCount();
    return true;
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nikeyframemanager.inc"
