#include <cstdint>
#include <cstddef>
// bshavok/bhkrigidbody_h_unit.cpp: WorldObject (4 functions)

#include <cstddef>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CA8830Object.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_005d3d10_This.h"
#include "fnv/decl/FUN_00c87a50_t.h"
#include "fnv/decl/FUN_00c9d530_cls.h"
#include "fnv/decl/FUN_00ca8800_Class.h"
#include "fnv/decl/FUN_00ca8860_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/SwapBlock_c8ce70.h"
#include "fnv/decl/Wrapper482.h"
#include "fnv/decl/bhkWorldObjectX.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c59000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "bhkrigidbody.h"
#include "fnv/decl/C87710HavokObject.h"
#include "fnv/decl/FUN_00a6e190_shell.h"
#include "fnv/decl/Object.h"
#include "fnv/decl/S.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c8e000.h"
#include "fnv/symbols_0126f000.h"

struct MemoryContextGuard
{
    unsigned int previous;
    __forceinline MemoryContextGuard() : previous(::currentAllocationContext)
    {
        ::currentAllocationContext = 16;
    }
    __forceinline ~MemoryContextGuard()
    {
        ::currentAllocationContext = previous;
    }
};
struct AllocationManager
{
};
struct FUN_00c8f510
{
    unsigned int value;
    FUN_00c8f510();
    ~FUN_00c8f510();
};
__forceinline void* __cdecl operator new(std::size_t size, AllocationManager& allocator)
{
    unsigned char* storage = static_cast<unsigned char*>(reinterpret_cast<::MemoryManagerStandIn *>(&(allocator))->FUN_00aa3e40(0xf0));
    unsigned char adjustment = static_cast<unsigned char>(16 - (reinterpret_cast<std::uintptr_t>(storage) & 15));
    storage += adjustment;
    storage[-1] = adjustment;
    return storage;
}
void __cdecl operator delete(void* memory, AllocationManager& allocator);
struct FUN_00c8f5a0_Class
{
    void* virtualFunctions;
    unsigned int referenceCount;
    void* havokObject;
    FUN_00c8f510* rigidBodyInfo;
    FUN_00c8f510* GetOrCreateRigidBodyInfo(unsigned char* wasCreated);
};
// @fnv 0x00c8f5a0
FUN_00c8f510* FUN_00c8f5a0_Class::GetOrCreateRigidBodyInfo(unsigned char* wasCreated)
{
    MemoryContextGuard context;
    const bool needsCreation = rigidBodyInfo == 0;
    *wasCreated = needsCreation;
    if (needsCreation)
    {
        rigidBodyInfo = new ((*reinterpret_cast<::AllocationManager *>(&::g_memoryManager))) FUN_00c8f510();
        if (havokObject)
            reinterpret_cast<::Wrapper482 *>(this)->FUN_00c8cfd0((::Info482 *)(rigidBodyInfo));
    }
    return rigidBodyInfo;
}

class C8F670Heap
{
  public:
};


struct C8F670Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct C8F670MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8F670Allocator* m_pStreamAllocator;

    C8F670Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" C8F670MemoryRouter& __cdecl FUN_00c85750() throw();

struct C8F670Pair
{
    int m_iKey;
    int m_iValue;
};

template <class T> struct C8F670Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~C8F670Array() throw()
    {
        C8F670Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class __declspec(novtable) C8F670Object
{
  public:
    virtual ~C8F670Object() throw()
    {}

    static void operator delete(void* pvMem)
    {
        if (pvMem)
        {
            unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::C8F670Heap *>(&::g_memoryManager))))->FUN_00aa4060(static_cast<char*>(pvMem) - ucOffset);
        }
    }

    void* DestroyObject(unsigned int uiFlags);

    int unk04;
    int unk08;
    C8F670Array<C8F670Pair> m_kPairs;
};

// Calls the object's destructor and, when uiFlags has bit 0 set, frees the object, then returns this.
// @fnv 0x00c8f670
void* C8F670Object::DestroyObject(unsigned int uiFlags)
{
    this->C8F670Object::~C8F670Object();
    if (uiFlags & 1)
        operator delete(this);
    return this;
}

class C8D9BinaryStream
{
  public:
    virtual void v00();
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(C8D9BinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    template <class T> unsigned int Write(const T* pValue, unsigned int uiElementCount)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, uiElementCount * sizeof(T), &uiSize, uiElementCount);
    }
};

class C8D9HavokData
{
  public:
};

class C8D9Stream
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SaveLinkID(void* pkObject);
    unsigned int unk[(0x1e4 - 4) / 4];
    unsigned char m_ucMode;
    unsigned char unk1e5, unk1e6, unk1e7;
    unsigned int unk1e8[(0x250 - 0x1e8) / 4];
    C8D9BinaryStream* m_pBackingStream;
};

template <class T> inline void C8D9SaveBinary(C8D9Stream* pkStream, const T& kValue)
{
    pkStream->m_pBackingStream->Write(&kValue, 1);
}

struct C8D9Node
{
    void* m_item;
    C8D9Node* m_pkNext;
};

struct C8D9List
{
    C8D9Node m_kHead;
    unsigned int ItemsInList() const
    {
        unsigned int ItemUpdateArray = 0;
        for (const C8D9Node* pkNode = &m_kHead; pkNode && pkNode->m_item; pkNode = pkNode->m_pkNext)
            ItemUpdateArray++;
        return ItemUpdateArray;
    }
};

class FUN_00c8d960_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va();
    virtual void vaCur();
    virtual void vaValue();
    virtual void vac();
    virtual void vb();
    virtual C8D9HavokData* CreateHavokData(bool* pbCreated);

    unsigned int unk;
    unsigned int unkCur;
    unsigned int unk0c;
    unsigned int m_uiValue1;
    C8D9List m_kList;

    void FUN_00c8d960(C8D9Stream* pkStream);
};

// Creates Havok data, swaps endianness when not in mode 1, saves list count and item link IDs, then swaps endianness back.
// @fnv 0x00c8d960
void FUN_00c8d960_cls::FUN_00c8d960(C8D9Stream* pkStream)
{
    bool bCreated;
    C8D9HavokData* pkData = CreateHavokData(&bCreated);
    if (pkStream->m_ucMode != 1)
        reinterpret_cast<::SwapBlock_c8ce70 *>((pkData))->SwapEndian();

    reinterpret_cast<::FUN_00c9d530_cls *>(this)->FUN_00c9d530((::FUN_00c9d530_arg *)(pkStream));

    C8D9SaveBinary(pkStream, m_kList.ItemsInList());

    for (C8D9Node* pkIter = &m_kList.m_kHead; pkIter && pkIter->m_item; pkIter = pkIter->m_pkNext)
        pkStream->SaveLinkID(pkIter->m_item);

    C8D9SaveBinary(pkStream, m_uiValue1);

    if (pkStream->m_ucMode != 1)
        reinterpret_cast<::SwapBlock_c8ce70 *>((pkData))->SwapEndian();
}

struct DebugShape
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
    NiPoint3 pos;
};


struct WorldObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(void* p, int flag);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59(void* out);
    void* FUN_00c8d2f0(void* a1);
};

// Gets a node from AddDebugNodeToWorld, creates a shape with 6.0f, sets its position, attaches it, and returns the node.
// @fnv 0x00c8d2f0
void* WorldObject::FUN_00c8d2f0(void* a1)
{
    WorldObject* pDebugNode = (WorldObject*)((void *)(reinterpret_cast<::bhkWorldObjectX *>(this)->AddDebugNodeToWorld((::NiNodeX *)(a1))));
    if (pDebugNode != 0)
    {
        __m128 src;
        v59(&src);
        NiPoint3 p;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&p)), (*(const ::hkVector4 *)((NiPoint3*)&src)));
        DebugShape* __restrict pDebugShape = (DebugShape*)((void *)(::FUN_00c59200(6.0f)));
        if (pDebugShape != 0)
        {
            pDebugShape->pos = p;
            pDebugNode->v55(pDebugShape, 1);
        }
    }
    return pDebugNode;
}

struct S8d280_Quad
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct S8d280_Mat
{
    S8d280_Quad r0;
    S8d280_Quad r1;
    S8d280_Quad r2;
    S8d280_Quad r3;
    void setIdentity()
    {
        r0.setZero4();
        r1.setZero4();
        r2.setZero4();
        r0(0) = 1.0f;
        r1(1) = 1.0f;
        r2(2) = 1.0f;
        r3.setZero4();
    }
};

struct S8d280_Body
{
    char unk000[0xf0];
    S8d280_Mat kTransform;
};

class FUN_00c8d280_cls : public bhkRefObject
{
  public:
    S8d280_Mat* FUN_00c8d280(S8d280_Mat* out);
};

// @fnv 0x00c8d280
S8d280_Mat* FUN_00c8d280_cls::FUN_00c8d280(S8d280_Mat* out)
{
    if (this != 0)
    {
        if (m_pHavokObject != 0)
        {
            S8d280_Mat* src = &((S8d280_Body*)m_pHavokObject)->kTransform;
            out->r0.m_vComponents = src->r0.m_vComponents;
            out->r1.m_vComponents = src->r1.m_vComponents;
            out->r2.m_vComponents = src->r2.m_vComponents;
            out->r3.m_vComponents = src->r3.m_vComponents;
            return out;
        }
    }
    out->setIdentity();
    return out;
}

// Preserves full 2026-10-24 prior contributor reconstruction; prior observed  /Od compiler mismatch.

struct ThreadState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
};

struct MemoryContext
{
    unsigned int previous;
    MemoryContext() : previous((*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2b4)
    {
        (*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2b4 = 0x10;
    }
    ~MemoryContext()
    {
        (*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2b4 = previous;
    }
};

struct InspectorList
{
    unsigned int state00;
    void** items;
    unsigned short capacity, length, occupied, growth;
    __forceinline void append(void*& entry)
    {
        unsigned int location = length;
        if (location >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(location + growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(location, (*(char * *)(&entry)));
    }
    __forceinline void appendInline(void* const& entry)
    {
        unsigned int location = length;
        if (location >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(location + growth);
        if (location >= length)
        {
            length = (unsigned short)(location + 1);
            if (entry)
                ++occupied;
        }
        else if (entry)
        {
            if (!items[location])
                ++occupied;
        }
        else
        {
            if (items[location])
                --occupied;
        }
        items[location] = entry;
    }
};

struct InspectionField
{
    virtual void unused00();
    virtual void unused04();
    virtual const NiRTTI* description();
};

struct InspectionNode
{
    InspectionField* item;
    InspectionNode* next;
};

struct MaterialInspector
{
    unsigned int field00, field04, field08, field0c, field10;
    InspectionNode firstField;
    void FUN_00c8f870(InspectorList*);
};

struct PointFormat
{
    float x, y, z;
    PointFormat()
    {}
    __forceinline PointFormat(float a, float b, float c) : x(a), y(b), z(c)
    {}
    void* format(const char*) const;
};

struct QuaternionFormat
{
    float w, x, y, z;
    void* format(const char*) const;
};

struct __declspec(align(16)) FloatVector
{
    float x, y, z, w;
    __forceinline FloatVector& operator=(const FloatVector& other)
    {
        *(__m128*)this = *(const __m128*)&other;
        return *this;
    }
};

struct __declspec(align(16)) FloatMatrix3
{
    FloatVector a, b, c;
    __forceinline FloatMatrix3& operator=(const FloatMatrix3& other)
    {
        a = other.a;
        b = other.b;
        c = other.c;
        return *this;
    }
};

struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, unsigned int);
};

struct AllocatorHolder
{
    unsigned int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
    Allocator& getAllocator()
    {
        return *allocator;
    }
};

extern AllocatorHolder* GetAllocator();

struct __declspec(align(16)) AlignedDynamicArray
{
    unsigned int unk00, unk04, unk08;
    void* data;
    unsigned int count, capacity;
    unsigned int unk18, unk1c;
    FloatVector unk20;
    FloatVector rotation;
    FloatVector position;
    FloatVector linVelocity;
    FloatVector angVelocity;
    FloatMatrix3 inertia;
    FloatVector centerOfMass;
    float mass, linDamp, angDamp, unkbc, friction, restitution;
    float maxLinVel, maxAngVel, penetration;
    signed char motionType;
    unsigned char unkd5, unkd6, unkd7;
    unsigned int unkd8, unkdc;
    AlignedDynamicArray();
    __forceinline void ClearAndRelease(Allocator& a)
    {
        count = 0;
        if ((capacity & 0x80000000u) == 0)
            a.Free(data, (capacity & 0x3fffffff) * 8);
    }
    __forceinline ~AlignedDynamicArray()
    {
        ClearAndRelease(GetAllocator()->getAllocator());
    }
};

// @fnv 0x00c8f870
void MaterialInspector::FUN_00c8f870(InspectorList* output)
{
    MemoryContext context;
    reinterpret_cast<::Object *>(this)->FUN_00c9d6b0((::StringArray *)(output));
    {
        void* entry = ((void *)(::FUN_00a7d330((*reinterpret_cast<::NiRTTI *>(&::g_012681c0)).m_pcName)));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
    }
    AlignedDynamicArray info;
    reinterpret_cast<::Wrapper482 *>(this)->FUN_00c8cfd0((::Info482 *)(void *)(&info));
    {
        void* entry;
        PointFormat point;
        QuaternionFormat rotation;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&point)), (*(const ::hkVector4 *)(&info.rotation)));
        rotation.x = info.position.x;
        rotation.y = info.position.y;
        rotation.z = info.position.z;
        rotation.w = info.position.w;
        entry = ((void *)(reinterpret_cast<::NiPoint3 *>((void *)&(point))->FUN_00a59af0("Position")));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
        entry = ((void *)(reinterpret_cast<::FUN_00a6e190_shell *>((void *)&(rotation))->FUN_00a6e190("Rotation")));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&point)), (*(const ::hkVector4 *)(&info.centerOfMass)));
        entry = ((void *)(reinterpret_cast<::NiPoint3 *>((void *)&(point))->FUN_00a59af0("COM")));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
        entry = ((void *)(::FUN_00a7d550("MASS", info.mass)));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
        entry = ((void *)(::FUN_00a7d550("LINDAMP", info.linDamp)));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
        entry = ((void *)(::FUN_00a7d550("ANGDAMP", info.angDamp)));
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>((output))->SetAt(index, (*(char * *)(&entry)));
        }
        entry = ((void *)(::FUN_00a7d550("FRICTION", info.friction)));
        output->append(entry);
        entry = ((void *)(::FUN_00a7d550("REST", info.restitution)));
        output->append(entry);
        ::AddMotionTypeName((::StrArr *)(output), info.motionType);
        entry = ((void *)(::FUN_00a7d550("MAXLINVEL", info.maxLinVel)));
        output->append(entry);
        entry = ((void *)(::FUN_00a7d550("MAXANGVEL", info.maxAngVel)));
        output->append(entry);
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&point)), (*(const ::hkVector4 *)(&info.linVelocity)));
        entry = ((void *)(reinterpret_cast<::NiPoint3 *>((void *)&(point))->FUN_00a59af0("LinVel")));
        output->append(entry);
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&point)), (*(const ::hkVector4 *)(&info.angVelocity)));
        entry = ((void *)(reinterpret_cast<::NiPoint3 *>((void *)&(point))->FUN_00a59af0("AngVel")));
        output->append(entry);
        FloatMatrix3 inertia;
        inertia = info.inertia;
        PointFormat diagonal;
        diagonal.x = inertia.a.x;
        diagonal.y = inertia.b.y;
        diagonal.z = inertia.c.z;
        entry = ((void *)(reinterpret_cast<::NiPoint3 *>((void *)&(diagonal))->FUN_00a59af0("InertiaTensor")));
        output->append(entry);
        entry = ((void *)(::FUN_00a7d550("PENDEPTH", info.penetration)));
        output->append(entry);
        entry = ((void *)(::fnv_00a7d5e0::FUN_00a7d5e0("QUALITYTYPE", reinterpret_cast<::S *>(&(info))->FUN_00c8d4a0())));
        output->append(entry);
        unsigned int count = 0;
        InspectionNode* node = &firstField;
        while (node && node->item)
        {
            ++count;
            node = node->next;
        }
        entry = ((void *)(::FUN_00a7d510("ACTCONCOUNT", count)));
        output->append(entry);
    }
    for (InspectionNode* current = &firstField; current && current->item; current = current->next)
    {
        InspectionField* field = current->item;
        const char* name = field->description()->m_pcName;
        char message[128];
        ::FUN_00406d00(message, 128, "%s: 0x%8X", name, field);
        output->appendInline(((void *)(::fnv_00a7d5e0::FUN_00a7d5e0("ACTCON", message))));
    }
}

struct Q8f6e0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int bytes);
};

struct Q8f6e0_Mem
{
    int unk00;
    int total;
    int(__cdecl* alloc)(Q8f6e0_Mem*, void*, int, int, int);
    int Read(void* p, int n, int x, int y)
    {
        int done = alloc(this, p, n, (int)x, (int)y);
        total += done;
        return done;
    }
};

struct Q8f6e0_Report
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void log(int a, int b, const char* msg, const char* file, int line);
};

struct __declspec(align(16)) Q8f6e0_Pre
{
    int unk00;
    int unk04;
    unsigned char flag08;
    void* data;
    int size;
    unsigned int capFlags;
    unsigned char flag18;
    unsigned short unk1a;
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    __forceinline Q8f6e0_Pre()
    {
        data = 0;
        size = 0;
        capFlags = 0x80000000;
        flag08 = 1;
        unk00 = 0;
        unk04 = 0;
        flag18 = 1;
        unk1a = 0xffff;
    }
    ~Q8f6e0_Pre();
};

__forceinline Q8f6e0_Pre::~Q8f6e0_Pre()
{
    Q8f6e0_Heap& h = reinterpret_cast<Q8f6e0_Heap&>(FUN_00c85750().heap());
    size = 0;
    if ((capFlags & 0x80000000) == 0)
        h.ReturnMemory(data, (capFlags & 0x3fffffff) * 8);
}

struct Q8f6e0_Dummy
{
    void FromOldCinfo(Q8f6e0_Pre* p);
};

struct Q8f6e0_Arg
{
    int unk00;
    unsigned int count;
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    char name[260];
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
    Q8f6e0_Mem* mem;
};

extern const char str_010c6118[];

extern const char str_010c60dc[];

struct Q8f6e0_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual int vA8();
    virtual void vac();
    virtual void vb0();
    virtual Q8f6e0_Dummy* vB4(unsigned char* p);
    int FUN_00c8f6e0(Q8f6e0_Arg* a);
};

// @fnv 0x00c8f6e0
int Q8f6e0_Obj::FUN_00c8f6e0(Q8f6e0_Arg* a)
{
    unsigned char flag;
    int r = this->vA8();
    Q8f6e0_Dummy* pD = this->vB4(&flag);
    bool warn = false;
    bool recovered = false;
    if (a->count < 0x23u)
    {
        Q8f6e0_Pre pre;
        Q8f6e0_Mem* m = a->mem;
        m->Read(&pre, 0xe0, 0, 0);
        pD->FromOldCinfo(&pre);
        recovered = true;
    }
    else
    {
        reinterpret_cast<::C87710HavokObject *>(this)->FUN_00c87710((*(::C87710Stream *)(a)));
    }
    if (warn || recovered)
    {
        char buf[0x100];
        FUN_00406d00(buf, 0x100, str_010c6118, a->name);
        (*reinterpret_cast<::Q8f6e0_Report * *>(&::DAT_01268360))->log(!recovered, 0x234f2250, buf, str_010c60dc, 0x220);
    }
    return r;
}

#include "generated/data/bshavok/bhkrigidbody_h_unit.inc"
#include "generated/data/bshavok/bhkrigidbody_h_unit_od_variant_o2_nood_variant.inc"
