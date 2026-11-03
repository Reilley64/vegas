
// src/havok/physics/dynamics/action/hkpbinaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpbinaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00cf4ca0_class.h"
#include "fnv/decl/ListenerC92B.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpWorldDecomp.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c97000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010cc000.h"
#include "havok/hkpBinaryAction.h"

struct DDCC60World
{
};

struct S_00d49310_Lock
{
    ~S_00d49310_Lock(void);
};

extern int DAT_010cc320;

struct FUN_00cf4de0_class
{
    void FUN_00cf4de0(void);
};

// Resets the vtable, releases the two referenced objects at offsets 0x18 and 0x1c, then destroys the lock at 0x14 and resets the vtable again.
// @fnv 0x00cf4de0
void FUN_00cf4de0_class::FUN_00cf4de0(void)
{
    *(void**)this = &DAT_010cc320;
    if (*(void**)((char*)this + 0x18))
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((((DDCC60World*)*(void**)((char*)this + 0x18))))->FUN_00c905b0();
        *(void**)((char*)this + 0x18) = 0;
    }
    if (*(void**)((char*)this + 0x1c))
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((((DDCC60World*)*(void**)((char*)this + 0x1c))))->FUN_00c905b0();
        *(void**)((char*)this + 0x1c) = 0;
    }
    *(void**)this = &DAT_010cc2fc;
    ::FUN_00cb0c00((int)(((S_00d49310_Lock*)((char*)this + 0x14))));
    *(void**)this = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct FUN_00c97510
{
};

struct FUN_00cf4cc0_class
{
    void FUN_00cf4cc0(void* arg);
};

// @fnv 0x00cf4cc0
void FUN_00cf4cc0_class::FUN_00cf4cc0(void* arg)
{
    void* p = *(void**)((char*)this + 8);
    if (p)
        reinterpret_cast<::hkpWorldDecomp *>((((FUN_00c97510*)p)))->FUN_00c97510((::hkpAction *)(void *)(this));
}

struct FUN_00cf4d30_class
{
    void SetRefObject(void* arg);
};
struct RefObj
{
};
struct WorldObj
{
};

namespace fnv_00d4f850 {
struct RefObj
{
    void RetainReference(void);
};

struct FUN_00d4f850_class : hkReferencedObject
{
    void SetReferencedObject(hkReferencedObject* obj);
};

// @fnv 0x00d4f850
void FUN_00d4f850_class::SetReferencedObject(hkReferencedObject* apObject)
{
    if (apObject)
        ((RefObj*)apObject)->RetainReference();
    if (*(DDCC60World**)((char*)this + 0xac))
        reinterpret_cast<::hkReferencedObjectC905 *>(((*(DDCC60World**)((char*)this + 0xac))))->FUN_00c905b0();
    *(hkReferencedObject**)((char*)this + 0xac) = apObject;
}
}  // namespace fnv_00d4f850

struct FUN_00cf4ce0_class
{
    int unk00;
    int unk04;
    void* unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
    void FUN_00cf4ce0(void* newAction);
};

struct FUN_00c90510_class
{
    void FUN_00c90510();
};
// Releases the current reference object, stores arg as the new one, and notifies the world object of the change.
// @fnv 0x00cf4d30
void FUN_00cf4d30_class::SetRefObject(void* arg)
{
    reinterpret_cast<::FUN_00c90510_class *>((((RefObj*)arg)))->FUN_00c90510();
    if (*(void**)((char*)this + 0x1c))
    {
        WorldObj* pWorld = (WorldObj*)*(void**)((char*)this + 8);
        if (pWorld)
            ::fnv_00c976a0::RemoveActionFromEntity((::fnv_00c976a0::hkpActionC976 *)(pWorld), (::fnv_00c976a0::hkpEntityC976 *)(void *)(this));
        reinterpret_cast<::hkReferencedObjectC905 *>((((DDCC60World*)*(void**)((char*)this + 0x1c))))->FUN_00c905b0();
        *(void**)((char*)this + 0x1c) = 0;
    }
    *(void**)((char*)this + 0x1c) = arg;
    WorldObj* w2 = (WorldObj*)*(void**)((char*)this + 8);
    if (w2)
        reinterpret_cast<::ListenerC92B *>((w2))->FUN_00c92bd0((::EntityC92B *)(void *)(this), (::WorldC92B *)(arg));
}

struct FUN_00c905b0_class
{
};

struct FUN_00c976a0_class
{
};

struct FUN_00c92bd0_class
{
};

// @fnv 0x00cf4ce0
void FUN_00cf4ce0_class::FUN_00cf4ce0(void* newAction)
{
    ((FUN_00c90510_class*)newAction)->FUN_00c90510();
    if (unk18)
    {
        if (unk08)
        {
            ::fnv_00c976a0::RemoveActionFromEntity((::fnv_00c976a0::hkpActionC976 *)(((FUN_00c976a0_class*)unk08)), (::fnv_00c976a0::hkpEntityC976 *)(void *)(this));
        }
        reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00c905b0_class*)unk18)))->FUN_00c905b0();
        unk18 = 0;
    }
    unk18 = newAction;
    if (unk08)
    {
        reinterpret_cast<::ListenerC92B *>((((FUN_00c92bd0_class*)unk08)))->FUN_00c92bd0((::EntityC92B *)(void *)(this), (::WorldC92B *)(newAction));
    }
}

struct NameStr
{
    NameStr() throw();
    char* p;
};
struct Ref
{
    virtual ~Ref();
    unsigned short flags;
    short refs;
    Ref() : refs(1)
    {}
};
struct Act : Ref
{
    void* world;
    void* island;
    unsigned long userData;
    NameStr name;
    Act(unsigned long u) : world(0), island(0), userData(u)
    {}
};
struct FUN_00cf4d80 : Act
{
    void* a;
    void* b;
    virtual ~FUN_00cf4d80();
    FUN_00cf4d80(void* x, void* y, unsigned long u);
};
// Constructs the object from two pointers and a userData value, calling Init() when either pointer is non-null.
// @fnv 0x00cf4d80
FUN_00cf4d80::FUN_00cf4d80(void* x, void* y, unsigned long uiUserData) : Act(uiUserData), a(x), b(y)
{
    if (b || a)
        reinterpret_cast<::FUN_00cf4ca0_class *>(this)->FUN_00cf4ca0();
}

template <int SIZE> __forceinline void memCpyOneAlignedXcf4e30(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXcf4e30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXcf4e30 {
extern "C" hkMemoryRouterXcf4e30& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayXcf4e30
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXcf4e30& router = hkRouterXcf4e30::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(router.m_pStreamAllocator), (::AudioStream *)(void *)(this), sizeof(T));
        memCpyOneAlignedXcf4e30<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkOwnerXcf4e30
{
  public:
    int unk00[6];
    void* m_kPointA;
    void* m_kPointB;

    void GetPointers(hkArrayXcf4e30<void*>& out);
};

// @fnv 0x00cf4e30
void hkOwnerXcf4e30::GetPointers(hkArrayXcf4e30<void*>& out)
{
    out.AddBack(m_kPointA);
    out.AddBack(m_kPointB);
}
