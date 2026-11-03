
// src/havok/common/visualize/process/hkinspectprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkinspectprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ddb2f0
#include <cstdint>
#include "fnv/decl/DD8FE0_Stream.h"
#include "fnv/decl/FUN_00d46f60_Class.h"
#include "fnv/decl/FUN_00dd90d0_cls.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00d605d0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d609a0_Class.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/S_00dd9380.h"
#include "fnv/decl/hkOwnerXcd13c0.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpEntityTrackerCD11.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00ddb000.h"
#include "fnv/symbols_00ddc000.h"
#include "fnv/symbols_00e0b000.h"
#include "fnv/symbols_010d6000.h"
#include "fnv/symbols_011b7000.h"
#include "fnv/symbols_01269000.h"
#include "fnv/symbols_0126c000.h"
void GetPunctuationChars(char** apOutString, int* apiLength)
{
    *apOutString = "!\"#$%";
    *apiLength = 5;
}

struct hkInspectProcess;
struct hkProcess;
extern hkInspectProcess* DAT_01269cd4;
struct hkProcessFactory
{
};
// @fnv 0x00ddb750
void __cdecl RegisterObjectInspectionProcess()
{
    DAT_01269cd4 = ((::hkInspectProcess *)(reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::hkProcessFactory * *>(&::DAT_01269cd0))))->FUN_00dd9380("ObjectInspection", (intptr_t)(((void (&)(hkProcess *))::FUN_00ddb710)))));
}

struct hkInspectProcessStandIn
{
    void WriteObjectHeader(void* object, int type, int flags);
    void RemovePair(void* object);
};

// If addObject is set, calls WriteObjectHeader with object, type and flags; otherwise calls RemovePair with object.
// @fnv 0x00ddb5d0
void __cdecl FUN_00ddb5d0(void* object, int type, char addObject, int flags, hkInspectProcess* inspectProcess)
{
    if (addObject)
    {
        reinterpret_cast<hkInspectProcessStandIn*>(inspectProcess)->WriteObjectHeader(object, type, flags);
    }
    else
    {
        reinterpret_cast<hkInspectProcessStandIn*>(inspectProcess)->RemovePair(object);
    }
}

struct hkInspectProcess;

// @fnv 0x00ddc1a0
hkInspectProcess* __cdecl CreateStatisticsProcess()
{
    return DAT_01269cd8 = ((::hkInspectProcess *)(reinterpret_cast<::S_00dd9380 *>((((hkProcessFactory*)(*reinterpret_cast<::hkProcess * *>(&::DAT_01269cd0)))))->FUN_00dd9380("Statistics", (intptr_t)(((void (&)(hkProcess *))::fnv_00ddc160::CreateImpl)))));
}

struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd4;

// @fnv 0x00ddbeb0
hkInspectProcess* FUN_00ddbeb0()
{
    return DAT_01269cd4;
}

class hkRefObjDDB6
{
  public:
    virtual ~hkRefObjDDB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjDDB6() throw()
    {
        m_sReferenceCount = 1;
    }
};

class hkListenerDDB6
{
  public:
    virtual void onEvent() = 0;
    bool m_enabled;
    hkListenerDDB6() throw() : m_enabled(true)
    {}
};

class hkSourceDDB6
{
  public:
    int unk00;
    void* m_target;

};

struct hkSourceListDDB6
{
    hkSourceDDB6** m_data;
    int m_iElementCount;
};

template <typename T> struct hkArrayDDB6
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayDDB6() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};


class FUN_00ddb600 : public hkRefObjDDB6, public hkListenerDDB6
{
  public:
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkArrayDDB6<void*> m_items;
    hkSourceDDB6* m_pObservedSource;

    FUN_00ddb600(const hkSourceListDDB6& sources) throw();
    virtual ~FUN_00ddb600() throw();
    virtual void onEvent();
};

// @fnv 0x00ddb600
FUN_00ddb600::FUN_00ddb600(const hkSourceListDDB6& sources) throw()
{
    m_pObservedSource = sources.m_iElementCount > 0 ? (hkSourceDDB6*)sources.m_data[0]->m_target : 0;
    if (m_pObservedSource)
    {
        reinterpret_cast<::FUN_00c90510_class *>((m_pObservedSource))->FUN_00c90510();
        reinterpret_cast<::hkOwnerXcd13c0 *>((m_pObservedSource))->FUN_00cd13c0(((void (&)(void *))::FUN_00ddb5d0), this);
    }
}

namespace fnv_00ddb670 {
class hkMemoryAllocatorDDB6
{
  public:
    virtual ~hkMemoryAllocatorDDB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDDB6
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDDB6* m_pStreamAllocator;
    hkMemoryAllocatorDDB6& heap()
    {
        return *m_pStreamAllocator;
    }
};

template <class T> __forceinline void destructDDB6(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayDDB6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayDDB6() throw()
    {
        ClearAndRelease((*static_cast<hkMemoryRouterDDB6*>(::FUN_00c85750())).heap());
    }
    __forceinline void clear()
    {
        destructDDB6(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorDDB6& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

};

class hkProcessDDB6
{
  public:
    virtual ~hkProcessDDB6() throw()
    {}
};

struct hkProcessObjectDDB6
{
    void* m_object;
    int unk04;
    int unk08;
};

class hkProcessContextDDB6 : public hkReferencedObject
{
  public:
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    hkProcessObjectDDB6* m_kTrackedObjects;
    int m_numObjects;

};

struct hkInspectEntryDDB6
{
    int unk00;
    int unk04;
};

class FUN_00ddb670 : public hkReferencedObject, public hkProcessDDB6
{
  public:
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkArrayDDB6<hkInspectEntryDDB6> m_entries;
    hkProcessContextDDB6* m_iValueAtOffset0C;

    void RemovePair(void* pvObject) throw();
    virtual ~FUN_00ddb670() throw();
};

// @fnv 0x00ddb670
FUN_00ddb670::~FUN_00ddb670() throw()
{
    hkProcessContextDDB6* pkContext = m_iValueAtOffset0C;
    if (pkContext)
    {
        for (int i = 0; i < pkContext->m_numObjects; i++)
            RemovePair(pkContext->m_kTrackedObjects[i].m_object);
        reinterpret_cast<::hkpEntityTrackerCD11 *>((m_iValueAtOffset0C))->FUN_00cd1140((::hkpEntityCD11 *)(FUN_00ddb5d0));
        reinterpret_cast<::hkReferencedObjectC905 *>((m_iValueAtOffset0C))->FUN_00c905b0();
    }
}
}  // namespace fnv_00ddb670

struct FnvCpu_FUN_00ddb710_CpuBlock;
struct FnvCpu_FUN_00ddb710_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00ddb710_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ddb710_CpuAllocator* allocator;
};
struct FnvCpu_FUN_00ddb710_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00ddb710_CpuBlock* FUN_00ddb600(unsigned int value);
};
// @fnv 0x00ddb710
void* __cdecl FUN_00ddb710(uintptr_t value)
{
    FnvCpu_FUN_00ddb710_CpuHolder* pCpuHolder = static_cast<FnvCpu_FUN_00ddb710_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00ddb710_CpuBlock* pCpuBlock =
        static_cast<FnvCpu_FUN_00ddb710_CpuBlock*>(pCpuHolder->allocator->Invoke(48));
    pCpuBlock->size = 48;
    pCpuBlock = ((::FnvCpu_FUN_00ddb710_CpuBlock *)(new ((void *)(pCpuBlock)) ::FUN_00ddb600((*(const ::hkSourceListDDB6 *)(value)))));
    if (pCpuBlock)
        return reinterpret_cast<char*>(pCpuBlock) + 8;
    return 0;
}

struct MemoryManager
{
    virtual void unk0();
    virtual void unk4();
    virtual void deallocate(void* p, unsigned int size);
};

struct ThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemoryManager* memoryManager;
};


class hkClass;
struct TestClass
{
    void* vtable;
    unsigned short m_usAllocationSize;
    unsigned short m_iObjectReferenceCount;

    void FUN_00ddb670();
    void* FUN_00ddbed0(char flags);
public:
    const ::hkClass *FUN_00d86910() const;
};

// @fnv 0x00ddbed0
void* TestClass::FUN_00ddbed0(char flags)
{
    reinterpret_cast<::fnv_00ddb670::FUN_00ddb670 *>(this)->fnv_00ddb670::FUN_00ddb670::~FUN_00ddb670();
    if (flags & 1)
    {
        ThreadMemory* mem = (ThreadMemory*)FUN_00c85750();
        mem->memoryManager->deallocate(this, m_usAllocationSize);
    }
    return this;
}

class hkClass;
class hkStatisticsCollector;
class hkBool
{
    char value;

  public:
    operator bool() const
    {
        return value != 0;
    }
};
class hkClass
{
  public:
    hkBool GetLastNodeFlag() const;
};
class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector*, const hkClass*) const;
    unsigned short memSizeAndFlags;
    short referenceCount;
};
class hkVtableClassRegistry : public hkReferencedObject
{
  public:
    virtual void RegisterVtable(const void*, const hkClass*);
    virtual const hkClass* GetClassFromVirtualInstance(const void*) const;
};
class ProcessContext
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    hkVtableClassRegistry* registry;
};
class hkOArchive
{
  public:
};
struct hkInspectProcess
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkOArchive* archive;
    int unk18, unk1c, unk20, unk24, unk28;
    ProcessContext* context;
    int WriteObjectHeader(void*, const hkClass*, unsigned int);
};
// Writes a 25-byte object header to the archive, resolving the actual class via the vtable registry when available.
// @fnv 0x00ddb310
int hkInspectProcess::WriteObjectHeader(void* object, const hkClass* pClassInfo, unsigned int flags)
{
    ::FUN_00d60960((const float *)(archive));
    const hkClass* pActualClass = pClassInfo;
    if (context->registry && reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(pClassInfo->GetLastNodeFlag()))->FUN_005609f0())
    {
        pActualClass = context->registry->GetClassFromVirtualInstance(object);
        if (!pActualClass)
            pActualClass = pClassInfo;
    }
    reinterpret_cast<::FUN_00d605d0_class *>((archive))->FUN_00d605d0(33);
    reinterpret_cast<::FUN_00d609a0_Class *>((archive))->FUN_00d609a0(reinterpret_cast<uintptr_t>(object), {});
    reinterpret_cast<::FUN_00d609a0_Class *>((archive))->FUN_00d609a0(reinterpret_cast<uintptr_t>(pActualClass), {});
    reinterpret_cast<::FUN_00d609a0_Class *>((archive))->FUN_00d609a0(flags, {});
    return 25;
}

struct LayoutRulesDDB3
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

class GlobalObjectO2_00d472a0;

class FUN_00d605d0_Class
{
  public:
};

struct TrackedObjectDDB3
{
    void* m_pvObject;
    intptr_t m_iType;
    int m_iFlags;
};

template <class T> struct hkArrayDDB3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

struct TrackedListDDB3
{
    int unk00[10];
    hkArrayDDB3<TrackedObjectDDB3> m_kTrackedObjects;
};

class ProcessBaseDDB3
{
  public:
    virtual void vfn_00();
    int unk04;
};

class ListenerDDB3
{
  public:
    virtual void WriteTrackedObjects();
};

class InspectProcessDDB3 : public ProcessBaseDDB3, public ListenerDDB3
{
  public:
    int unk0C;
    int unk10;
    FUN_00d605d0_Class* m_pDataStream;
    int unk18, unk1C, unk20, unk24, unk28;
    TrackedListDDB3* m_pkTracked;

    virtual void WriteTrackedObjects();
};

// Writes layout rules and each tracked object entry to m_pDataStream via FUN_00d60960, FUN_00d605d0, FUN_00d609a0, and WriteObjectHeader.
// @fnv 0x00ddb3a0
void InspectProcessDDB3::WriteTrackedObjects()
{
    if (!m_pkTracked)
        return;
    ::FUN_00d60960((const float *)(m_pDataStream));
    reinterpret_cast<::FUN_00d605d0_class *>((m_pDataStream))->FUN_00d605d0(0x20);
    reinterpret_cast<::FUN_00d609a0_Class *>((m_pDataStream))->FUN_00d609a0((intptr_t)(&g_0126cae8), 0);
    reinterpret_cast<::FUN_00d605d0_class *>((m_pDataStream))->FUN_00d605d0((*reinterpret_cast<const ::LayoutRulesDDB3 *>(&::DAT_011b7b88)).m_ucBytesInPointer);
    reinterpret_cast<::FUN_00d605d0_class *>((m_pDataStream))->FUN_00d605d0((*reinterpret_cast<const ::LayoutRulesDDB3 *>(&::DAT_011b7b88)).m_bLittleEndian);
    reinterpret_cast<::FUN_00d605d0_class *>((m_pDataStream))->FUN_00d605d0((*reinterpret_cast<const ::LayoutRulesDDB3 *>(&::DAT_011b7b88)).m_bReusePaddingOptimization);
    reinterpret_cast<::FUN_00d605d0_class *>((m_pDataStream))->FUN_00d605d0((*reinterpret_cast<const ::LayoutRulesDDB3 *>(&::DAT_011b7b88)).m_bEmptyBaseClassOptimization);
    hkArrayDDB3<TrackedObjectDDB3>& kObjects = m_pkTracked->m_kTrackedObjects;
    for (int i = 0; i < kObjects.GetLogicalSize(); i++)
    {
        TrackedObjectDDB3& kEntry = kObjects[i];
        reinterpret_cast<::hkInspectProcess *>(this)->WriteObjectHeader(kEntry.m_pvObject, (const ::hkClass *)(kEntry.m_iType), kEntry.m_iFlags);
    }
}

namespace fnv_00ddb550 {
class FUN_00d605d0_Class
{
  public:
};

struct hkPairDDB5
{
    int m_key;
    int m_uiFilterValue;
};

template <typename T> struct hkArrayDDB5
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            unsigned int* src = reinterpret_cast<unsigned int*>(m_data + m_iElementCount);
            unsigned int* dst = reinterpret_cast<unsigned int*>(m_data + index);
            int k = 0;
            do
            {
                dst[k] = src[k];
            } while (++k < (int)(sizeof(T) / 4));
        }
    }
};

class FUN_00ddb550_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    FUN_00d605d0_Class* m_pStreamWriter;
    int unk18, unk1C;
    hkArrayDDB5<hkPairDDB5> m_pairs;

    int RemovePair(int iKey);
};

// Writes a header and key to m_pStreamWriter, removes the matching entry from m_pairs, and returns 9.
// @fnv 0x00ddb550
int FUN_00ddb550_cls::RemovePair(int iKey)
{
    ::FUN_00d60960((const float *)(m_pStreamWriter));
    reinterpret_cast<::FUN_00d605d0_class *>((m_pStreamWriter))->FUN_00d605d0(0x22);
    reinterpret_cast<::FUN_00d609a0_Class *>((m_pStreamWriter))->FUN_00d609a0(iKey, 0);
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_key == iKey)
        {
            m_pairs.removeAt(i);
            break;
        }
    }
    return 9;
}
}  // namespace fnv_00ddb550

struct hkMemoryAllocatorQ
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorQ* m_pStreamAllocator;
    hkMemoryAllocatorQ& heap()
    {
        return *m_pStreamAllocator;
    }
};


template <typename T> struct hkArrQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrQ() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrQ()
    {
        ClearAndRelease();
    }

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    void _clearAndDeallocate(hkMemoryAllocatorQ& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void ClearAndRelease()
    {
        _clearAndDeallocate(static_cast<hkMemoryRouterQ*>(FUN_00c85750())->heap());
    }

    void _pushBack(hkMemoryAllocatorQ& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)(::hkMemoryAllocatorQ *)(&alloc), (::AudioStream *)(void *)(this), sizeof(T));
        }
        T* p = m_data + m_iElementCount;
        m_iElementCount++;
        *p = t;
    }
    void AddBack(const T& t)
    {
        _pushBack(static_cast<hkMemoryRouterQ*>(FUN_00c85750())->heap(), t);
    }
};

class hkBoolQ
{
  public:
    char m_cBooleanValue;
    hkBoolQ(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkClassQ
{
    hkBoolQ hasVtable() const throw();
};

struct hkVtableClassRegistryQ
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual const hkClassQ* GetClassFromVirtualInstance(const void* obj) const throw();
};

struct hkInspectContextQ
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
    hkVtableClassRegistryQ* m_vtableRegistry;
};

struct hkLayoutRulesQ
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};


struct hkStructureLayoutQ
{
    hkLayoutRulesQ m_kLayoutRules;
    hkStructureLayoutQ(const hkLayoutRulesQ& rules) throw();
};

struct hkArrayStreamWriterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkArrayStreamWriterQ(hkArrQ<char>* arr, int ownerShip) throw();
    ~hkArrayStreamWriterQ() throw();
};

struct hkObjectPatchQ
{
    int unk00;
    int unk04;
    const void* m_object;
    int unk0C;
    const hkClassQ* m_class;
    int unk14;
};

struct hkWrittenObjectQ
{
    const void* m_object;
    const hkClassQ* m_class;
};

struct hkDisplayOStreamQ
{
};


struct hkInspectProcessQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkDisplayOStreamQ* m_pDisplayStream;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    hkInspectContextQ* m_iValueAtOffset0C;

    // Calls FUN_00ddb770 with the given object, class, true, and written array.
// @fnv 0x00ddb770
    __forceinline int sendRecursiveQ(const void* apObject, const hkClassQ* apClass,
                                     hkArrQ<hkWrittenObjectQ>* apWrittenObjects) throw()
    {
        return FUN_00ddb770(apObject, apClass, true, apWrittenObjects);
    }
    int FUN_00ddb770(const void* object, const hkClassQ* pClassInfo, hkBoolQ recurse,
                     hkArrQ<hkWrittenObjectQ>* written) throw();
};

int hkInspectProcessQ::FUN_00ddb770(const void* object, const hkClassQ* pClassInfo, hkBoolQ recurse,
                                    hkArrQ<hkWrittenObjectQ>* written) throw()
{
    hkStructureLayoutQ layout(DAT_010d6ae8);
    hkArrQ<hkObjectPatchQ> patches;

    const hkClassQ* realClass = pClassInfo;
    if (m_iValueAtOffset0C->m_vtableRegistry && pClassInfo->hasVtable())
    {
        realClass = m_iValueAtOffset0C->m_vtableRegistry->GetClassFromVirtualInstance(object);
        if (!realClass)
        {
            realClass = pClassInfo;
        }
    }

    if (recurse)
    {
        int i;
        for (i = 0; i < written->GetLogicalSize(); i++)
        {
            if ((*written)[i].m_object == object)
            {
                break;
            }
        }
        if (i < written->GetLogicalSize())
        {
            return 0;
        }
        hkWrittenObjectQ w;
        w.m_object = object;
        w.m_class = realClass;
        written->AddBack(w);
    }

    hkArrQ<char> buffer;
    hkArrayStreamWriterQ writer(&buffer, 1);
    int size = ::FUN_00e0bd40((::Sink *)(::hkArrayStreamWriterQ *)(&writer), (::ObjectWriteInfo *)(::hkStructureLayoutQ *)(&layout), (uintptr_t)(object), 0, (intptr_t)(object), (uintptr_t)(realClass), (::ObjectWriteArrItem *)(::hkArrQ< ::hkObjectPatchQ> *)(&patches));
    if (size != buffer.GetLogicalSize() || size < 1)
    {
        return -1;
    }

    int total = size + 1;
    ::FUN_00d60960((const float *)(m_pDisplayStream));
    reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(0x24);
    reinterpret_cast<::FUN_00d607b0_class *>((m_pDisplayStream))->FUN_00d607b0((intptr_t)(buffer.m_data));
    if (recurse)
    {
        for (int i = 0; i < patches.GetLogicalSize(); i++)
        {
            const void* obj = patches[i].m_object;
            const hkClassQ* cls = patches[i].m_class;
            total += sendRecursiveQ(obj, cls, written);
        }
    }
    return total;
}

// sub ecx,8; jmp FUN_00ddbed0 == MSVC adjustor thunk for a secondary base vtable slot.
struct PrimaryBase
{
    virtual void FUN_00ddbec0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddbec0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ddbec0
    virtual void FUN_00ddbec0();
};

Derived::Derived()
{}

namespace fnv_00ddb450 {
struct hkClass;
struct hkClassMember
{
    const char* unk00;
    const hkClass* unk04;
    const void* unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    short unk0E;
    unsigned short unk10;
    unsigned short unk12;
};
struct hkClass
{
};
struct hkPathArray
{
    unsigned short* unk00;
};
static __forceinline int nextIndex(const hkPathArray* path, int i)
{
    return path->unk00[i + 1];
}
// Walks a hkPathArray through hkClassMember types to compute and return the pointer to a nested member within data.
// @fnv 0x00ddb450
static __declspec(noinline) void* __cdecl FUN_00ddb450(const hkClassMember* member, char* data, const hkPathArray* path,
                                                       int type, int aiIndex)
{
    char* p = data;
    for (;;)
    {
        switch (type)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 24:
        case 30:
        case 31:
        case 32:
            return p;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18: {
            char* next = p + path->unk00[aiIndex + 1] * 16;
            type = 12;
            ++aiIndex;
            p = next;
        }
            continue;
        case 22:
        case 26: {
            int iIndex = path->unk00[aiIndex + 1];
            {
                char* next = *(char**)p + reinterpret_cast<::Owner *>((void *)(member))->GetTagValue() * iIndex;
                type = member->unk0D;
                ++aiIndex;
                p = next;
            }
            continue;
        }
        case 25: {
            if (!member)
                return 0;
            if (!member->unk04)
                return 0;
            const hkClass* k = ((const ::fnv_00ddb450::hkClass *)(reinterpret_cast<::TestClass *>((void *)(member))->FUN_00d86910()));
            if (!k)
                return 0;
            member = &(*(const ::fnv_00ddb450::hkClassMember *)(reinterpret_cast<::HkClassNode *>((void *)(k))->FUN_00d46f20(nextIndex(path, aiIndex))));
            {
                char* next = p + member->unk12;
                type = member->unk0C;
                ++aiIndex;
                p = next;
            }
            continue;
        }
        case 20:
            return 0;
        default:
            return 0;
        }
    }
}

void* S00ddb450_Call(int type, char* data, const hkPathArray* path, int i, const hkClassMember* member)
{
    return FUN_00ddb450(member, data, path, type, i);
}
}


typedef unsigned __int64 Wide;
struct InputArchive
{
    __forceinline Wide readWide()
    {
        Wide value;
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&value, 8, 1);
        return value;
    }
    __forceinline unsigned short readWord()
    {
        unsigned short value;
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&value, 2, 1);
        return value;
    }
    __forceinline unsigned int ReadTag()
    {
        unsigned int value;
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&value, 4, 1);
        return value;
    }
    __forceinline unsigned char readByte()
    {
        unsigned char value;
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&value, 1, 1);
        return value;
    }
};
struct HeapAllocator
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* allocate(int& bytes);
    virtual void release(void* data, int bytes);
    template <class T> __forceinline T* allocateItems(int& count)
    {
        int bytes = count * int(sizeof(T));
        void* data = allocate(bytes);
        count = bytes / int(sizeof(T));
        return static_cast<T*>(data);
    }
};
struct HeapRouter
{
    int unk00, unk04, unk08, unk0c;
    HeapAllocator* allocator;
    __forceinline HeapAllocator& heap()
    {
        return *allocator;
    }
};
static __forceinline HeapAllocator& getHeap()
{
    return static_cast<HeapRouter*>(FUN_00c85750())->heap();
}
template <class T> struct ListBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ListBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline void owned(T* p, int n, int cap)
    {
        data = p;
        size = n;
        capacity = cap;
    }
    __forceinline void reserve(HeapAllocator& heap, int n)
    {
        if (getCapacity() < n)
        {
            int twice = 2 * getCapacity();
            ::FUN_00c908c0((::SpawnedObject *)&(heap), (::SpawnedArray *)(void *)(this), n < twice ? twice : n, sizeof(T));
        }
    }
    __forceinline void resize(HeapAllocator& heap, int n)
    {
        reserve(heap, n);
        size = n;
    }
    __forceinline void free(HeapAllocator& heap)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            heap.release(data, getCapacity() * int(sizeof(T)));
        data = 0;
        capacity = 0x80000000;
    }
    __forceinline T& expand(HeapAllocator& heap)
    {
        if (size == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(heap), (::AudioStream *)(void *)(this), sizeof(T));
        return data[size++];
    }
    __forceinline void remove(int index)
    {
        --size;
        if (size != index)
        {
            const int* source = reinterpret_cast<const int*>(data + size);
            int* destination = reinterpret_cast<int*>(data + index);
            unsigned int i = 0;
            do
            {
                destination[i] = source[i];
            } while (++i < sizeof(T) / 4);
        }
    }
};
template <class T> struct List : ListBase<T>
{
    __forceinline List()
    {}
    __forceinline explicit List(int n)
    {
        HeapAllocator& heap = getHeap();
        T* p = n ? heap.allocateItems<T>(n) : 0;
        int cap = n ? n : 0x80000000;
        owned(p, n, cap);
    }
    __forceinline ~List()
    {
        free(getHeap());
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        resize(getHeap(), n);
    }
    __forceinline T& AllocatePair()
    {
        return expand(getHeap());
    }
};
struct MemberInfo;
struct TypeInfo
{
    const MemberInfo& FUN_00d46f20(int index) const;
};
struct MemberInfo
{
    const char* name;
    const TypeInfo* type;
    const void* enumeration;
    unsigned char kind, subtype;
    unsigned short count;
    unsigned short flags, offset;
    int GetTagValue() const;
    const TypeInfo& FUN_00d86910() const;
    __forceinline int getOffset() const
    {
        return offset;
    }
    __forceinline int getKind() const
    {
        return kind;
    }
    __forceinline int getSubtype() const
    {
        return subtype;
    }
};
static __declspec(noinline) void* FUN_00ddb450(void* address, const List<unsigned short>& path, int depth, int kind,
                                               int subtype, const MemberInfo* field)
{
    switch (kind)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 24:
    case 30:
    case 31:
    case 32:
        return address;
    case 14:
    case 15:
    case 17:
    case 18: {
        int childIndex = path[depth + 1];
        void* child = static_cast<char*>(address) + childIndex * 16;
        return FUN_00ddb450(child, path, depth + 1, 12, 0, field);
    }
    case 20:
        return 0;
    case 22:
    case 26: {
        int childIndex = path[depth + 1];
        List<char>* array = static_cast<List<char>*>(address);
        void* child = array->begin() + childIndex * field->GetTagValue();
        return FUN_00ddb450(child, path, depth + 1, field->subtype, 0, field);
    }
    case 25: {
        const TypeInfo* type = field && field->type ? &field->FUN_00d86910() : 0;
        if (type)
        {
            int childIndex = path[depth + 1];
            const MemberInfo& child = type->FUN_00d46f20(childIndex);
            return FUN_00ddb450(static_cast<char*>(address) + child.offset, path, depth + 1, child.kind, child.subtype,
                                &child);
        }
        break;
    }
    }
    return 0;
}
struct InspectInputBase
{
    virtual void FUN_00ddbae0(unsigned char);
    int unk04;
    InputArchive* input;
    void* output;
    void* display;
    void* handler;
};
struct InspectConsumer : hkReferencedObject, InspectInputBase
{
    List<hkWrittenObjectQ> tracked;
    void* context;
    virtual void FUN_00ddbae0(unsigned char command);
};
// @fnv 0x00ddbae0
void InspectConsumer::FUN_00ddbae0(unsigned char command)
{
    switch (command)
    {
    case 0x25: {
        Wide objectID = input->readWide();
        Wide classID = input->readWide();
        unsigned short length = input->readWord();
        List<unsigned short> path(length);
        path.SetSizeAndGrow(length);
        for (int i = 0; i < length; ++i)
            path[i] = input->readWord();
        unsigned int bytes = input->ReadTag();
        List<unsigned char> payload(bytes);
        payload.SetSizeAndGrow(bytes);
        reinterpret_cast<::FUN_00dd90d0_cls *>((input))->FUN_00dd90d0((intptr_t)(payload.begin()));
        if (objectID > 0 && classID > 0 && path.GetLogicalSize() > 0 && bytes > 0)
        {
            void* object = reinterpret_cast<void*>(unsigned int(objectID));
            TypeInfo* type = reinterpret_cast<TypeInfo*>(unsigned int(classID));
            const MemberInfo& field = (*(::MemberInfo *)(reinterpret_cast<::FUN_00d46f60_Class *>((type))->FUN_00d46f60(path[0])));
            void* destination = FUN_00ddb450(static_cast<char*>(object) + field.getOffset(), path, 0, field.getKind(),
                                             field.getSubtype(), &field);
            if (destination)
                ::FUN_00cb1260(destination, payload.begin(), bytes);
        }
        break;
    }
    case 0x23: {
        Wide objectID = input->readWide();
        Wide classID = input->readWide();
        unsigned char flags = input->readByte();
        if (objectID > 0 && classID > 0)
        {
            void* object = reinterpret_cast<void*>(unsigned int(objectID));
            hkClassQ* type = reinterpret_cast<hkClassQ*>(unsigned int(classID));
            List<hkWrittenObjectQ> visited;
            bool recurse = static_cast<const void*>(type) == &g_0126cae8 || (flags & 2);
            reinterpret_cast<hkInspectProcessQ*>(this)->FUN_00ddb770(
                object, type, recurse, reinterpret_cast<hkArrQ<hkWrittenObjectQ>*>(&visited));
            int count = tracked.GetLogicalSize();
            int i = 0;
            for (; i < count; ++i)
                if (tracked[i].m_object == object)
                    break;
            bool present = i != count;
            if (flags & 1)
            {
                if (!present)
                {
                    hkWrittenObjectQ& entry = tracked.AllocatePair();
                    entry.m_class = type;
                    entry.m_object = object;
                }
            }
            else if (present)
                tracked.remove(i);
        }
        break;
    }
    }
}

struct Heap_ddba
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct Router_ddba
{
    int unk00, unk04, unk08, unk0C;
    Heap_ddba* m_pStreamAllocator;
    Heap_ddba& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct hkBool_ddba
{
    char m_cBooleanValue;
    hkBool_ddba(bool b) throw() : m_cBooleanValue(b)
    {}
};

template <class T> struct hkArray_ddba
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray_ddba() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArray_ddba() throw()
    {
        Heap_ddba& heap = (*static_cast<Router_ddba*>(::FUN_00c85750())).heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        Heap_ddba& heap = (*static_cast<Router_ddba*>(::FUN_00c85750())).heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            ::FUN_00c908c0((::SpawnedObject *)(::Heap_ddba *)(&heap), (::SpawnedArray *)(void *)(this), n < cap2 ? cap2 : n, sizeof(T));
        }
        m_iElementCount = n;
    }
};

struct Pair_ddba
{
    void* m_kPointA;
    void* m_kPointB;
};

struct Hit_ddba
{
    int a, b;
};

struct Query_ddba
{
    void FUN_00ddb770(void* a, void* b, hkBool_ddba flag, hkArray_ddba<Hit_ddba>& hits) throw();
};

struct Shape_ddba
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    Pair_ddba* m_pairs;
    int m_numPairs;
    int getNumPairs() const
    {
        return m_numPairs;
    }
    void FUN_00ddba20(int unused);
};

// @fnv 0x00ddba20
void Shape_ddba::FUN_00ddba20(int unused)
{
    hkArray_ddba<Hit_ddba> hits;
    for (int i = 0; i < getNumPairs(); i++)
    {
        hits.SetSizeAndGrow(0);
        ((Query_ddba*)((char*)this - 8))->FUN_00ddb770(m_pairs[i].m_kPointA, m_pairs[i].m_kPointB, false, hits);
    }
}

#include "generated/data/havok/common/visualize/process/hkinspectprocess.inc"
