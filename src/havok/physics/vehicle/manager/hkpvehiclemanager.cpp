
// src/havok/physics/vehicle/manager/hkpvehiclemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/manager/hkpvehiclemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/VUBCD_Instance.h"
#include "fnv/decl/VUC_StepInstance.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
class FUN_00d1df70
{
  public:
};

class RefPtrArray
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00d1df70** m_items;
    int m_uiItemCount;

  public:
    void Remove(FUN_00d1df70* pObj);
};

// Finds pObj in m_items, removes it by moving the last element into its slot, decrements the count and releases a reference to pObj.
// @fnv 0x00e426b0
void RefPtrArray::Remove(FUN_00d1df70* pObj)
{
    int count = m_uiItemCount;
    int idx = 0;
    if (count > 0)
    {
        FUN_00d1df70** ppItem = m_items;
        for (; idx < count; idx++, ppItem++)
        {
            if (*ppItem == pObj)
                goto found;
        }
    }
    idx = -1;
found:
    int& rCount = m_uiItemCount;
    --rCount;
    int newCount = rCount;
    if (newCount != idx)
    {
        m_items[idx] = m_items[newCount];
    }
    reinterpret_cast<::hkReferencedObjectC905 *>((pObj))->FUN_00c905b0();
}

struct E426F0Allocator;

struct E426F0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E426F0Allocator* m_pStreamAllocator;

    E426F0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E426F0MemoryRouter& __cdecl FUN_00c85750();

struct E426F0Object
{
};

struct E426F0ObjectArray
{
    E426F0Object** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void construct(E426F0Object** p, int n, E426F0Object* const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void AddBack(E426F0Object* const& e)
    {
        E426F0Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(E426F0Object*));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct E426F0Container
{
    int unk00;
    int unk04;
    E426F0ObjectArray m_kTrackedObjects;

    void AddObject(E426F0Object* object);
};

// @fnv 0x00e426f0
void E426F0Container::AddObject(E426F0Object* object)
{
    reinterpret_cast<::FUN_00c90510_class *>((void *)(object))->FUN_00c90510();
    m_kTrackedObjects.AddBack(object);
}

namespace fnv_00e42740 {
struct E42740Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct E42740MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E42740Allocator* m_pStreamAllocator;

    E42740Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E42740MemoryRouter& __cdecl FUN_00c85750();

class E42740ReferencedObject
{
  public:
    virtual ~E42740ReferencedObject() throw()
    {}


    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct E42740ObjectArray
{
    E42740ReferencedObject** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~E42740ObjectArray()
    {
        E42740Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(E42740ReferencedObject*));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00e42740 : public E42740ReferencedObject
{
  public:
    virtual ~FUN_00e42740() throw();

    E42740ObjectArray m_kTrackedObjects;
};

// Destructor releases the reference held on each object in the array before the array is destroyed.
// @fnv 0x00e42740
FUN_00e42740::~FUN_00e42740() throw()
{
    int numObjects = m_kTrackedObjects.m_iElementCount;
    for (int i = 0; i < numObjects; i++)
        reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_kTrackedObjects.m_data[i]))->FUN_00c905b0();
}
}  // namespace fnv_00e42740

struct E426F0Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};


struct ParamObj
{
    int unk00;
    int unk04;
    float m_08;
};

struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char m_20;
};

struct ObjBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(float f, void* item, void* buf);
};

struct ItemRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    SubObj* m_1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    ObjBase* m_3c;

};

struct LocalArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void* m_initialBuffer;
};

struct FUN_00e427b0_cls
{
    int unk00;
    int unk04;
    ItemRec** m_items;
    int m_uiItemCount;

    void ProcessItems(ParamObj* p);
};

// Iterates m_items, resizing a temporary buffer to each item's m_1c->m_20, calls sub_e37940, v10 and sub_e39030, then frees the buffer.
// @fnv 0x00e427b0
void FUN_00e427b0_cls::ProcessItems(ParamObj* p)
{
    LocalArray buffer;
    buffer.m_data = 0;
    buffer.m_iElementCount = 0;
    buffer.m_iCapacityState = 0x80000000;
    E426F0MemoryRouter& router = FUN_00c85750();
    void* initial = (void*)router.unk00;
    router.unk00 += 0x600;
    buffer.m_data = initial;
    buffer.m_iCapacityState = 0x80000010;
    buffer.m_initialBuffer = initial;
    int count = m_uiItemCount;

    if (count > 0)
    {
        int i = 0;
        do
        {
            ItemRec* item = m_items[i];
            int flag = item->m_1c->m_20;
            E426F0MemoryRouter& h2 = FUN_00c85750();
            E426F0Allocator* pAllocator = h2.m_pStreamAllocator;
            int cap = buffer.m_iCapacityState & 0x3fffffff;
            if (cap < flag)
            {
                int iNewCapacity = cap * 2;
                if (flag >= iNewCapacity)
                {
                    iNewCapacity = flag;
                }
                ::FUN_00c908c0((::SpawnedObject *)(pAllocator), (::SpawnedArray *)(void *)(&buffer), iNewCapacity, 0x60);
            }
            buffer.m_iElementCount = flag;
            reinterpret_cast<::VUBCD_Instance *>((item))->FUN_00e37940();
            ObjBase* pObj = item->m_3c;
            pObj->v10(p->m_08, item, buffer.m_data);
            reinterpret_cast<::VUC_StepInstance *>((item))->FUN_00e39030((*(const ::VUC_StepInfo *)(p)), buffer.m_data);
            i++;
        } while (i < count);
    }
    if (buffer.m_initialBuffer == buffer.m_data)
    {
        buffer.m_iElementCount = 0;
    }
    void* last = buffer.m_initialBuffer;
    E426F0MemoryRouter& h3 = FUN_00c85750();
    h3.unk00 = (int)last;
    E426F0MemoryRouter& h4 = FUN_00c85750();
    E426F0Allocator* alloc = h4.m_pStreamAllocator;
    unsigned int flags = buffer.m_iCapacityState;
    buffer.m_iElementCount = 0;
    if ((flags & 0x80000000) == 0)
    {
        alloc->Free(buffer.m_data, (flags & 0x3fffffff) * 0x60);
    }
}
