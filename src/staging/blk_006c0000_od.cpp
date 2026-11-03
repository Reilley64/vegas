
// src/staging/blk_006c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cstring>
#include "fnv/decl/Array6d0.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSSaveGameBuffer.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DoorAccessData.h"
#include "fnv/decl/DoorSearchInit.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0042fb60_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005efa80_cls.h"
#include "fnv/decl/FUN_00613fb0_C.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_0068f2c0_shell.h"
#include "fnv/decl/FUN_0069dec0_class.h"
#include "fnv/decl/FUN_0069f920_cls.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_006ac220_shell.h"
#include "fnv/decl/FUN_006b3f40_Class.h"
#include "fnv/decl/FUN_006b4060_class.h"
#include "fnv/decl/FUN_006bc870_shell.h"
#include "fnv/decl/FUN_006c0100_t.h"
#include "fnv/decl/FUN_006c6200_cls.h"
#include "fnv/decl/FUN_006c7e00.h"
#include "fnv/decl/FUN_006c87f0_shell.h"
#include "fnv/decl/FUN_006c90d0_fix.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_006c9920_cls.h"
#include "fnv/decl/FUN_006c9fa0_shell.h"
#include "fnv/decl/FUN_006ced90_stand.h"
#include "fnv/decl/FUN_006cee10_shell.h"
#include "fnv/decl/FUN_006cef10_shell.h"
#include "fnv/decl/FUN_006cf900_Class.h"
#include "fnv/decl/FUN_006cfac0_cls.h"
#include "fnv/decl/FUN_006cfbc0.h"
#include "fnv/decl/FUN_006d0680_cls.h"
#include "fnv/decl/FUN_006d3ae0.h"
#include "fnv/decl/FUN_006dad70_shell.h"
#include "fnv/decl/FUN_006dc590.h"
#include "fnv/decl/FUN_006dd460.h"
#include "fnv/decl/FUN_006df440_owner.h"
#include "fnv/decl/FUN_006e4430_class.h"
#include "fnv/decl/FUN_006e5ee0_Class.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_006e7970_shell.h"
#include "fnv/decl/FUN_006e8f40_shell.h"
#include "fnv/decl/FUN_006f2270.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_009a3910_cls.h"
#include "fnv/decl/FUN_009a3c50_cls.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/Holder670.h"
#include "fnv/decl/InfoEntryArrY.h"
#include "fnv/decl/LFFreeList.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/Mid.h"
#include "fnv/decl/MyClass.h"
#include "fnv/decl/NLLocation.h"
#include "fnv/decl/NavMesh.h"
#include "fnv/decl/NavMeshInfo.h"
#include "fnv/decl/NavMeshSearchLOSArray.h"
#include "fnv/decl/NavMeshStub.h"
#include "fnv/decl/Owner6df780.h"
#include "fnv/decl/PathOwner.h"
#include "fnv/decl/PathingGraphNode.h"
#include "fnv/decl/PathingLocationProxy.h"
#include "fnv/decl/PlacementRange.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/S006949d0.h"
#include "fnv/decl/S2f850.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_006ac070.h"
#include "fnv/decl/S_FUN_006b05a0.h"
#include "fnv/decl/SetupPathingLocation.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00568fa0__Fn568fa0.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/decl/fnv_006b8c50__FUN_006b8c50_shell.h"
#include "fnv/decl/fnv_006c99c0__FUN_006c99c0_shell.h"
#include "fnv/decl/fnv_006dae90__FUN_006dae90_shell.h"
#include "fnv/decl/fnv_006e1610__PathingLOSMap.h"
#include "fnv/decl/fnv_006e7e70__FUN_006e7e70_shell.h"
#include "fnv/decl/fnv_006f2290__CtorHelper.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_009f6540__FUN_009f6540_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0044e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00637000.h"
#include "fnv/symbols_006a0000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006c6000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006d0000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_006d3000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_006d5000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_0099d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01025000.h"
#include "fnv/symbols_0106c000.h"
#include "../../include/layout_support.h"
#undef SearchPath


struct FUN_006c8bd0_Class
{
    void FUN_006c8bd0(const char* dst, const char* src, unsigned int count);
};

// @fnv 0x006c8bd0
void FUN_006c8bd0_Class::FUN_006c8bd0(const char* dst, const char* src, unsigned int count)
{
    if (count <= 0)
        return;
    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            std::memmove(const_cast<char*>(dst) + i * 16, src + i * 16, 16);
    }
    else if (dst > src)
    {
        for (long i = count - 1; i >= 0; --i)
            std::memmove(const_cast<char*>(dst) + i * 16, src + i * 16, 16);
    }
}

struct FUN_006dc1d0_Class
{
    virtual int vfn();
    intptr_t m_iElementCount;
    int m_vContactPosition;
    int m_dataLength;
    virtual intptr_t Write(unsigned int);
    void ConstructPlacementObjects(intptr_t, unsigned int);
    void FUN_006dc1d0(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x006dc1d0
void FUN_006dc1d0_Class::FUN_006dc1d0(unsigned int requested, unsigned int savedSize)
{
    m_iElementCount = 0;
    m_vContactPosition = 0;
    m_dataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_iElementCount = Write(requested);
        m_dataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructPlacementObjects(m_iElementCount, savedSize);
        m_vContactPosition = savedSize;
    }
}

extern int DAT_0106c3b4;
struct FUN_006c00b0_Class
{
    int* m_ptr;
    FUN_006c00b0_Class();
};
// @fnv 0x006c00b0
FUN_006c00b0_Class::FUN_006c00b0_Class()
{
    reinterpret_cast<::FUN_006c0100_t *>(this)->FUN_006c0100();
    m_ptr = &DAT_0106c3b4;
}

extern int DAT_0106c640;
struct Caller00822860
{
    void FUN_00822860(unsigned int, bool);
    Caller00822860* FUN_006c6160();
};
// @fnv 0x006c6160
Caller00822860* Caller00822860::FUN_006c6160()
{
    *reinterpret_cast<void**>(this) = &DAT_0106c640;
    FUN_00822860(0, false);
    return this;
}

extern int DAT_0106c640;

struct Arr3520
{
    void RemoveAll(bool clear);
};

struct FUN_006c6190_cls
{
    void FUN_006c6190();
};

// @fnv 0x006c6190
void FUN_006c6190_cls::FUN_006c6190()
{
    *reinterpret_cast<int**>(this) = &DAT_0106c640;
    reinterpret_cast<::FUN_006c6200_cls *>((reinterpret_cast<Arr3520*>(this)))->FUN_006c6200(true);
}

struct FUN_006c72f0_Class
{
};
struct FUN_006c63e0_Class
{
    void FUN_006c63e0();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_006c6c40_Class
{
    char* m_ptr;
    void FUN_006c6c40();
};

// @fnv 0x006c6c40
void FUN_006c6c40_Class::FUN_006c6c40()
{
    m_ptr = "0rl";
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}

struct FUN_006c7370_Class
{
    void FUN_006c7390();
    void* FUN_006c7370();
};

struct FUN_006c75f0_Class
{
    void FUN_006c75f0();
};

// @fnv 0x006c75f0
void FUN_006c75f0_Class::FUN_006c75f0()
{
    while (*(int*)((char*)this + 0xc))
        reinterpret_cast<::LFFreeList *>(this)->PruneFreeList();
}

extern int DAT_0106c814;

struct FUN_006c78d0_Class
{
    void* p;
    char b;
    void* FUN_006c78d0();
};

// @fnv 0x006c78d0
void* FUN_006c78d0_Class::FUN_006c78d0()
{
    p = &DAT_0106c814;
    b = 0;
    return this;
}

extern int DAT_0106c814;

struct FUN_006c78f0_Class
{
    void FUN_006c78f0();
};

// @fnv 0x006c78f0
void FUN_006c78f0_Class::FUN_006c78f0()
{
    *(void**)this = &DAT_0106c814;
}

struct FUN_006caa20_Class
{
    unsigned char GetByteAtOffsetA1();
};

// @fnv 0x006caa20
unsigned char FUN_006caa20_Class::GetByteAtOffsetA1()
{
    return ((unsigned char*)this)[0xa1];
}

struct EdgeArr
{
    char* FUN_006a1440(unsigned int);
    char* FUN_006ced70();
};

// @fnv 0x006ced70
char* EdgeArr::FUN_006ced70()
{
    return FUN_006a1440(0);
}

struct Dummy_0061bf20
{
    Dummy_0061bf20* FUN_006d03a0();
};
// Sets the object's vtable pointer to DAT_0106c9b8, calls FUN_006b3f40(0, 0), and returns this.
// @fnv 0x006d03a0
Dummy_0061bf20* Dummy_0061bf20::FUN_006d03a0()
{
    *reinterpret_cast<int**>(this) = &DAT_0106c9b8;
    reinterpret_cast<::FUN_006b3f40_Class *>((this))->FUN_006b3f40(0, 0);
    return this;
}

struct FUN_006d1be0_Class
{
    int* GetField2090();
};

// @fnv 0x006d1be0
int* FUN_006d1be0_Class::GetField2090()
{
    return *(int**)((char*)this + 0x2090);
}

struct FUN_006d1c00_Class
{
    unsigned int GetField2094();
};
// @fnv 0x006d1c00
unsigned int FUN_006d1c00_Class::GetField2094()
{
    return *(unsigned int*)((char*)this + 0x2094);
}

struct FUN_006d1c20_Class
{
    int GetField2098();
};

// @fnv 0x006d1c20
int FUN_006d1c20_Class::GetField2098()
{
    return *(int*)((char*)this + 0x2098);
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_006d1c40_Class
{
    unsigned int FUN_006d1c40() const;
};

// @fnv 0x006d1c40
unsigned int FUN_006d1c40_Class::FUN_006d1c40() const
{
    return ((const Flt*)((const char*)this + 0x2070))->operator unsigned int();
}

struct FUN_006d2c20_Class
{
    float GetFloatAtOffsetB0() const;
};
// @fnv 0x006d2c20
float FUN_006d2c20_Class::GetFloatAtOffsetB0() const
{
    return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0xb0);
}

struct FUN_006d2c60_Class
{
    void FUN_006d2c60(float value);
};

// @fnv 0x006d2c60
void FUN_006d2c60_Class::FUN_006d2c60(float value)
{
    *(float*)((char*)this + 0x20a4) = value;
}

struct FUN_006d30e0_Class
{
    void FUN_006d30e0(intptr_t value);
};

// @fnv 0x006d30e0
void FUN_006d30e0_Class::FUN_006d30e0(intptr_t value)
{
    *(int*)((char*)this + 0x108) = value;
}

struct FUN_006d3120_Class
{
    void FUN_006d3120();
};

// Sets the two int fields at offsets 0x104 and 0x108 of this object to zero.
// @fnv 0x006d3120
void FUN_006d3120_Class::FUN_006d3120()
{
    *(int*)((char*)this + 0x104) = 0;
    *(int*)((char*)this + 0x108) = 0;
}

struct FUN_006d33a0_Class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    void FUN_006d33a0();
};

struct FUN_006d32c0_Class
{
    void FUN_006d32c0();
};

class NavMeshPtr;
struct PathingLocation
{
    PathingLocation& operator=(const PathingLocation&);
public:
    bool HasValidTriangle();
public:
    bool ResolveNavMesh(::NavMeshPtr &);
public:
    bool FindNavMeshTriangle(::NavMeshPtr &, unsigned short &);
public:
    bool HasValidTriangle_006dd6a0();
public:
    bool HasPathingLocation();
};
struct FUN_006d3ac0_Class
{
    void AssignPathingLocation(const PathingLocation& src);
};
// @fnv 0x006d3ac0
void FUN_006d3ac0_Class::AssignPathingLocation(const PathingLocation& aLocation)
{
    *(PathingLocation*)((char*)this + 0xc) = aLocation;
}


// @fnv 0x006d62c0
void* __cdecl CallWithNullArgs(void* apArg1, void* apArg2, void* apArg3)
{
    return ((void *)(::FUN_006d5490((::RouteLocation *)(apArg1), (::RouteLocation *)(apArg2), apArg3, (float *)(void *)(0), (::FUN_006abbb0 *)(void *)(0))));
}

struct NiPoint3
{
    int x, y, z;
public:
    static const ::NiPoint3 ZERO;
};

struct FUN_006dad40_Class
{
    void FUN_006dad40(const NiPoint3& src);
};

// Copies the given NiPoint3 into the object at offset 0xb0.
// @fnv 0x006dad40
void FUN_006dad40_Class::FUN_006dad40(const NiPoint3& src)
{
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0xb0) = src;
}

struct FUN_006db060_Class
{
    void* FUN_006db060(unsigned int size);
};

// Allocates size * 0x54 bytes via operator new and returns the pointer.
// @fnv 0x006db060
void* FUN_006db060_Class::FUN_006db060(unsigned int size)
{
    void* result = ::FUN_00401000(size * 0x54);
    return result;
}


struct FUN_006db0b0_Class
{
    void* FUN_006db0b0(void* base, unsigned int count);
};

// @fnv 0x006db0b0
void* FUN_006db0b0_Class::FUN_006db0b0(void* base, unsigned int count)
{
    return ::Reallocate(base, count * 0x54);
}

namespace fnv_006db330 {

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_006db330_Class
{
    GlobalObject_00869f00* m_ptr;
    void FUN_006db330();
};

// @fnv 0x006db330
void FUN_006db330_Class::FUN_006db330()
{
    m_ptr = (GlobalObject_00869f00*)&::DAT_0106cc14;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_006db330

struct FUN_006db3b0_Class : public FUN_006dc1d0_Class
{
    FUN_006db3b0_Class* FUN_006db3b0();
};
// @fnv 0x006db3b0
FUN_006db3b0_Class* FUN_006db3b0_Class::FUN_006db3b0()
{
    *reinterpret_cast<int**>(this) = &DAT_0106cc28;
    FUN_006dc1d0(0, 0);
    return this;
}

namespace fnv_006db3e0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006db3e0_Class
{
    void* m_ptr;
    void FUN_006db3e0();
};
// @fnv 0x006db3e0
void FUN_006db3e0_Class::FUN_006db3e0()
{
    m_ptr = &::DAT_0106cc28;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_006db3e0

namespace fnv_006db4d0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006db4d0_Class
{
    void* m_ptr;
    void InitializeAndClear();
};
// @fnv 0x006db4d0
void FUN_006db4d0_Class::InitializeAndClear()
{
    m_ptr = &::DAT_0106cc3c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_006db4d0

namespace fnv_006db720 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006db720_Class
{
    void* vtbl;
    void FUN_006db720();
};
// @fnv 0x006db720
void FUN_006db720_Class::FUN_006db720()
{
    vtbl = &DAT_0106cc64;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_006db720

namespace fnv_006db930 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006db930_Class
{
    void FUN_006db930();
};
// @fnv 0x006db930
void FUN_006db930_Class::FUN_006db930()
{
    *reinterpret_cast<int**>(this) = &::DAT_0106cc8c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_006db930

struct FUN_006dc440_class
{
};
struct FUN_006db9e0_Class
{
    void* FUN_006db9e0();
};
namespace fnv_006dba10 {

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_006dba10_Class
{
    void InitAndClear();
};

// @fnv 0x006dba10
void FUN_006dba10_Class::InitAndClear()
{
    *reinterpret_cast<int**>(this) = &::DAT_0106cca0;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_006dba10

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_006dc100_Class
{
    AX* FUN_006dc100();
};
// Sets the object's vtable pointer to DAT_0106cc14, calls FUN_006b3eb0 with 0, 0, and returns the object as an AX pointer.
// @fnv 0x006dc100
AX* FUN_006dc100_Class::FUN_006dc100()
{
    *reinterpret_cast<const void**>(this) = &DAT_0106cc14;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return reinterpret_cast<AX*>(this);
}

namespace fnv_006dc2f0 {

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};

struct FUN_006dc2f0_Class
{
    void* FUN_006dc2f0();
};

// Sets the object's vtable pointer to DAT_0106cc64, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x006dc2f0
void* FUN_006dc2f0_Class::FUN_006dc2f0()
{
    *(void**)this = &::fnv_006db720::DAT_0106cc64;
    ((AX*)this)->FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_006dc2f0

struct FUN_006df200_Class
{
    char m_flag;
    int m_auiShapeKeys;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_field14;
    int m_field18;
    void FUN_006df200(int a, int b);
};
// Clears m_flag and stores the two arguments into m_field14 and m_field18.
// @fnv 0x006df200
void FUN_006df200_Class::FUN_006df200(int aiFirst, int aiSecond)
{
    m_flag = 0;
    m_field14 = aiFirst;
    m_field18 = aiSecond;
}

struct FUN_006c63b0_Class
{
    const char* m_str;
    int m_auiShapeKeys;
    void* m_alloc;
    void FUN_006c63b0();
};
// Sets m_str to "@ql", clears the pointer map contents, and frees m_alloc.
// @fnv 0x006c63b0
void FUN_006c63b0_Class::FUN_006c63b0()
{
    m_str = "@ql";
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(m_alloc);
}

extern int DAT_0106c6ac;
struct FUN_006c6be0_Class
{
    void* m_vtbl;
    int m_auiShapeKeys;
    void* m_ptr;
    void FUN_006c6be0();
};
// Sets the vtable, clears the pointer map, and frees m_ptr.
// @fnv 0x006c6be0
void FUN_006c6be0_Class::FUN_006c6be0()
{
    m_vtbl = &DAT_0106c6ac;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(m_ptr);
}


struct FUN_006c60d0_Class
{
    void FUN_006c6350();
    void* FUN_006c60d0(unsigned int flags);
};

struct FUN_006c6100_Class
{
    void FUN_006c6a80();
    void* FUN_006c6100(unsigned int flags);
};
struct FUN_006c6b80_Class
{
    void FUN_006c6b80();
};
struct FUN_006c6130_Class
{
    void* FUN_006c6130(unsigned int flags);
};
extern int DAT_0106c654;
struct FUN_006c6260_Class
{
    void* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006c6260_Class(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes with NiMalloc and zero-fills them.
// @fnv 0x006c6260
FUN_006c6260_Class::FUN_006c6260_Class(unsigned int count)
{
    m_vtbl = &DAT_0106c654;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    int size = m_uiItemCount * 4;
    m_data = ::FUN_00aa1070(size);
    ::FUN_00403d30(m_data, 0, m_uiItemCount * 4);
}

struct NiAVObject;
struct FUN_006c6400_Node
{
    NiPointer<NiAVObject> m_ptr;
    FUN_006c6400_Node* m_next;
    bool Contains(const NiPointer<NiAVObject>&);
};
// Walks the linked list from this node and returns whether any node holds the given NiPointer<NiAVObject>.
// @fnv 0x006c6400
bool FUN_006c6400_Node::Contains(const NiPointer<NiAVObject>& a)
{
    FUN_006c6400_Node* cur = this;
    while (cur != 0 && reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(cur->m_ptr))->IsNotEqual((const ::DummyStruct_00631820 &)(a)))
        cur = cur->m_next;
    return cur != 0;
}

extern int DAT_0106c68c;
struct FUN_006c68b0_Class
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006c68b0_Class* FUN_006c68b0(int count);
};
// Sets the vtable, stores count, allocates count*4 bytes zeroed into m_data and returns this.
// @fnv 0x006c68b0
FUN_006c68b0_Class* FUN_006c68b0_Class::FUN_006c68b0(int count)
{
    unsigned int iAllocationSize;
    m_vtbl = &DAT_0106c68c;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    iAllocationSize = m_uiItemCount * 4;
    m_data = ::FUN_00aa1070(iAllocationSize);
    ::FUN_00403d30(m_data, 0, m_uiItemCount * 4);
    return this;
}

extern int DAT_0106c68c;
struct FUN_006c6ae0_S : public NiTPointerMap<int, int>
{
    void FUN_006c6ae0();
};
// @fnv 0x006c6ae0
void FUN_006c6ae0_S::FUN_006c6ae0()
{
    *(void**)this = &DAT_0106c68c;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

struct FUN_006c6b10_Class
{
    int* m_vtbl;
    unsigned int m_uiItemCount;
    void* m_data;
    unsigned int m_uiBufferCapacity;
    FUN_006c6b10_Class* FUN_006c6b10(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes zeroed into m_data and returns this.
// @fnv 0x006c6b10
FUN_006c6b10_Class* FUN_006c6b10_Class::FUN_006c6b10(unsigned int count)
{
    m_vtbl = &DAT_0106c6ac;
    m_uiItemCount = count;
    m_uiBufferCapacity = 0;
    unsigned int iAllocationSize = m_uiItemCount * 4;
    m_data = ::FUN_00aa1070(iAllocationSize);
    ::FUN_00403d30(m_data, 0, m_uiItemCount * 4);
    return this;
}

struct FUN_006c7110_Class : FUN_006c6190_cls
{
    void* FUN_006c7110(unsigned int);
};
// Calls FUN_006c6190, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006c7110
void* FUN_006c7110_Class::FUN_006c7110(unsigned int flags)
{
    FUN_006c6190();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006c7140_Class
{
    void* FUN_006c7140(unsigned int flags);
};
// Calls FUN_006c63b0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006c7140
void* FUN_006c7140_Class::FUN_006c7140(unsigned int flags)
{
    reinterpret_cast<FUN_006c63b0_Class*>(this)->FUN_006c63b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_006c6680_Class
{
    void FUN_006c6680();
};

struct FUN_006c7170_Class : public FUN_006c6680_Class
{
    void* FUN_006c7170(unsigned int flags);
};

struct FUN_006c74a0_Class
{
    void* FUN_006c71a0(unsigned int flags);
};
namespace fnv_006c71d0 {

struct FUN_006c6ae0_Class
{
};

struct FUN_006c71d0_Class : public FUN_006c6ae0_Class
{
    void* FUN_006c71d0(unsigned int flags);
};

// @fnv 0x006c71d0
void* FUN_006c71d0_Class::FUN_006c71d0(unsigned int flags)
{
    reinterpret_cast<::FUN_006c6ae0_S *>(this)->FUN_006c6ae0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006c71d0

struct FUN_006c7200_Class : public FUN_006c6be0_Class
{
    void* FUN_006c7200(unsigned int flags);
};
// @fnv 0x006c7200
void* FUN_006c7200_Class::FUN_006c7200(unsigned int flags)
{
    FUN_006c6be0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_006c7230_Class : public FUN_006c6c40_Class
{
    void* FUN_006c7230(unsigned int flags);
};

// @fnv 0x006c7230
void* FUN_006c7230_Class::FUN_006c7230(unsigned int flags)
{
    FUN_006c6c40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006c7260
namespace FUN_006c6ce0 {
struct FUN_006c6c60
{
    ~FUN_006c6c60();
    void* FUN_006c7260(unsigned int);
};
}
void* FUN_006c6ce0::FUN_006c6c60::FUN_006c7260(unsigned int flags)
{
    ((FUN_006c6ce0::FUN_006c6c60*)this)->FUN_006c6ce0::FUN_006c6c60::~FUN_006c6c60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006c72c0_Class
{
    void FUN_006c6e00();
    void* ScalarDeletingDestructor(unsigned int flags);
};

struct FUN_006c75c0_Class : public FUN_006c75f0_Class
{
    void* FUN_006c75c0(unsigned int flags);
};

// Calls FUN_006c75f0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006c75c0
void* FUN_006c75c0_Class::FUN_006c75c0(unsigned int flags)
{
    FUN_006c75f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct M24
{
    void* FUN_006c89b0(unsigned int flags);
};
// @fnv 0x006c89b0
void* M24::FUN_006c89b0(unsigned int flags)
{
    reinterpret_cast<::FUN_006c87f0_shell *>(this)->FUN_006c87f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006c8a30_Class
{
    int m_vtbl;
    void* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    void FUN_006c8a30(bool freeStorage);
};
struct S16_6c8d00
{
    int f0;
    int f1;
    int f2;
    int f3;
};
struct FUN_006c8b90_Class
{
    void FUN_006c8b90(S16_6c8d00* p, unsigned int n);
};
struct ObstacleTask
{
    ~ObstacleTask();
    void* FUN_006c8d00(unsigned int);
};
// @fnv 0x006c8a30
void FUN_006c8a30_Class::FUN_006c8a30(bool freeStorage)
{
    if (m_data)
    {
        reinterpret_cast<::FUN_006c8b90_Class *>(this)->FUN_006c8b90((::S16_6c8d00 *)(m_data), m_iElementCount);
        if (freeStorage)
        {
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            m_data = 0;
            m_pRayCursor = 0;
        }
        m_iElementCount = 0;
    }
}
// Calls FUN_006c8d00(0) on each of the n elements of the array pointed to by p.
// @fnv 0x006c8b90
void FUN_006c8b90_Class::FUN_006c8b90(S16_6c8d00* p, unsigned int n)
{
    unsigned int i = 0;
    for (; i < n; i++)
        reinterpret_cast<::ObstacleTask *>(&(p[i]))->FUN_006c8d00(0);
}
// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete; returns this.
// @fnv 0x006c8d00
void* ObstacleTask::FUN_006c8d00(unsigned int flags)
{
    reinterpret_cast<::FUN_006c7e00 *>((this))->FUN_006c7e00::~FUN_006c7e00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006ced60_Class
{
    char FUN_006ced60(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};
// @fnv 0x006ced60
char FUN_006ced60_Class::FUN_006ced60(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return 1;
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* p, unsigned int n);
};
struct S5460
{
public:
    unsigned int FUN_00845460();
public:
    unsigned int FUN_00978bc0();
};
struct FUN_006cee30_Class
{
    int m_vtbl;
    char* m_base;
    unsigned int m_iElementCount;
    unsigned int m_uiBufferCapacity;
    void FUN_006cee30(unsigned int n);
};
// @fnv 0x006cee30
void FUN_006cee30_Class::FUN_006cee30(unsigned int n)
{
    if (n == m_uiBufferCapacity)
        return;
    if (n < m_iElementCount)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(m_base + n * 12, m_iElementCount - n);
        m_iElementCount = n;
    }
    reinterpret_cast<::FUN_006dc590 *>((((S5460*)this)))->FUN_006dc590_(n, m_iElementCount);
    m_uiBufferCapacity = n;
}

namespace fnv_006ceea0 {
struct ActorAvoidanceEntry
{
    char pad[16];
};
struct FUN_0072ba80_shell
{
};
struct FUN_006ceea0_Class
{
    char* m_uiStandInValue;
    char* m_base;
    unsigned int m_iElementCount;
    unsigned int m_uiItemCount;
    void FUN_006ceea0(unsigned int count);
};
// @fnv 0x006ceea0
void FUN_006ceea0_Class::FUN_006ceea0(unsigned int count)
{
    if (count == m_uiItemCount)
        return;
    if (count < m_iElementCount)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((((FUN_0072ba80_shell*)this)))->FUN_0072ba80((char*)m_base + count * 16, m_iElementCount - count);
        m_iElementCount = count;
    }
    reinterpret_cast<::fnv_009f6540::FUN_009f6540_Class *>(this)->FUN_009f6540(count, m_iElementCount);
    m_uiItemCount = count;
}
}  // namespace fnv_006ceea0

struct FUN_006cfaa0
{
    void FUN_006cfaa0_();
};
struct FUN_006cfda0_Class
{
    void* FUN_006cfda0(unsigned int flags);
};
// @fnv 0x006cfda0
void* FUN_006cfda0_Class::FUN_006cfda0(unsigned int flags)
{
    ((FUN_006cfaa0*)this)->FUN_006cfaa0_();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006cfdd0_Class
{
    void* FUN_006cfdd0(unsigned int flags);
};
// Calls FUN_006cfac0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006cfdd0
void* FUN_006cfdd0_Class::FUN_006cfdd0(unsigned int flags)
{
    reinterpret_cast<::FUN_006cfac0_cls *>(this)->FUN_006cfac0_cls::~FUN_006cfac0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_006cfe00_Class
{
    void* FUN_006cfe00(unsigned int flags);
};

// Calls FUN_006cfbc0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006cfe00
void* FUN_006cfe00_Class::FUN_006cfe00(unsigned int flags)
{
    reinterpret_cast<::FUN_006cfbc0 *>(this)->FUN_006cfbc0::~FUN_006cfbc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006d30b0_Class2
{
    char _pad[0xC8];
    NiPoint3 m_c8;
    void FUN_006d30b0(const NiPoint3& v);
};
// Stores the given NiPoint3 into the object's m_c8 field.
// @fnv 0x006d30b0
void FUN_006d30b0_Class2::FUN_006d30b0(const NiPoint3& aPoint)
{
    m_c8 = aPoint;
}

struct S_006d3ff0
{
    void FUN_006d3ff0(NiPoint3& a);
};
// Copies the NiPoint3 stored at offset 0x20cc of this object into the given NiPoint3.
// @fnv 0x006d3ff0
void S_006d3ff0::FUN_006d3ff0(NiPoint3& a)
{
    a = *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x20cc);
}

struct FUN_006d4ca0_Class
{
    int m_kPointA;
    unsigned short m_kPointB;
    unsigned char Equals(const FUN_006d4ca0_Class* other);
};
// @fnv 0x006d4ca0
unsigned char FUN_006d4ca0_Class::Equals(const FUN_006d4ca0_Class* other)
{
    return (m_kPointA == other->m_kPointA && m_kPointB == other->m_kPointB) ? 1 : 0;
}

struct TwoIntRecord
{
    int f0;
    int f4;
    TwoIntRecord(const TwoIntRecord&);
    TwoIntRecord& operator=(const TwoIntRecord&);
};
struct T3
{
    char a;
    char b;
    char c;
};
struct FUN_006d4ce0 : public TwoIntRecord
{
    T3 t;
    FUN_006d4ce0(const FUN_006d4ce0&);
};
// @fnv 0x006d4ce0
FUN_006d4ce0::FUN_006d4ce0(const FUN_006d4ce0& o) : TwoIntRecord(o), t(o.t)
{}

struct FUN_006d61b0_Class
{
    int m_kPointA;
    int m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
    float m_usTrailingValue;
    void SetFromFloat3(const float* src);
};
// Copies the first three floats from src into the object's three float fields.
// @fnv 0x006d61b0
void FUN_006d61b0_Class::SetFromFloat3(const float* src)
{
    m_iThirdValue = src[0];
    m_iFourthElementInteger = src[1];
    m_usTrailingValue = src[2];
}

struct Elem;
struct FUN_006dbee0_s
{
    void FUN_006dbee0(Elem* dst, unsigned int count);
};
struct FUN_006daeb0_Class
{
    unsigned int m_auiShapeKeys;
    Elem* m_data;
    unsigned int m_uiBufferCapacity;
    unsigned int m_cap;
    void FUN_006daeb0(unsigned int pos);
};
namespace fnv_006db0d0 {
struct FUN_0072ba80_shell
{
};
struct FUN_009a3c50_shell
{
};
struct FUN_006db0d0_Class
{
    int m_vtbl;
    void* m_ptr;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
    void SetPosition(unsigned int position);
};
// @fnv 0x006db0d0
void FUN_006db0d0_Class::SetPosition(unsigned int position)
{
    if (position == m_pRayCursor)
        return;
    if (position < m_uiItemCount)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((((FUN_0072ba80_shell*)this)))->FUN_0072ba80((char*)m_ptr + position * 0x14, m_uiItemCount - position);
        m_uiItemCount = position;
    }
    reinterpret_cast<::FUN_009a3c50_cls *>((((FUN_009a3c50_shell*)this)))->UpdateThreat(position, m_uiItemCount);
    m_pRayCursor = position;
}
}  // namespace fnv_006db0d0

struct Dummy_0069af30
{
};
struct S_006db4a0
{
    int* vtable;
    S_006db4a0* FUN_006db4a0();
};
extern int DAT_0106cc78;
struct FUN_006db930
{
    virtual ~FUN_006db930();
};
struct FUN_006db950 : public FUN_006db930
{
    virtual ~FUN_006db950();
};
// Destructor that calls Clear(true) on the object.
// @fnv 0x006db950
FUN_006db950::~FUN_006db950()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}

namespace fnv_006dba80 {
struct FUN_006dae90_shell
{
};
struct FUN_006dba80_Class
{
    void* FUN_006dba80(unsigned int flags);
};
// Calls FUN_006dae90 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006dba80
void* FUN_006dba80_Class::FUN_006dba80(unsigned int flags)
{
    reinterpret_cast<::fnv_006dae90::FUN_006dae90_shell *>((((FUN_006dae90_shell*)this)))->FUN_006dae90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006dba80

struct FUN_006db330
{
    virtual ~FUN_006db330();
};
struct FUN_006dbab0_Class : public FUN_006db330
{
    void* DestroySelf(unsigned int flags);
};
// Runs the base destructor, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006dbab0
void* FUN_006dbab0_Class::DestroySelf(unsigned int flags)
{
    reinterpret_cast<::fnv_006db330::FUN_006db330_Class *>(this)->FUN_006db330();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006db350
{
    virtual ~FUN_006db350();
};
struct Holder
{
    void* DestroyHolder(unsigned int);
};
// Runs the destructor on this object and, when bit 0 of flags is set, deallocates it; returns this.
// @fnv 0x006dbae0
void* Holder::DestroyHolder(unsigned int flags)
{
    ((FUN_006db350*)this)->FUN_006db350::~FUN_006db350();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006dbb10_Class
{
    void* FUN_006dbb10(unsigned int flags);
};
// @fnv 0x006dbb10
void* FUN_006dbb10_Class::FUN_006dbb10(unsigned int flags)
{
    reinterpret_cast<::fnv_006db3e0::FUN_006db3e0_Class *>(this)->FUN_006db3e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NavMeshEdgePoint
{
    NavMeshEdgePoint& operator=(const NavMeshEdgePoint& src);
    NavMeshEdgePoint& FUN_006dbb40(const NavMeshEdgePoint& src);
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    int pad5;
    float f18;
    float f1c;
};
NavMeshEdgePoint& NavMeshEdgePoint::operator=(const NavMeshEdgePoint& src)
{
    reinterpret_cast<::FUN_006cf900_Class *>((void *)&(const ::NavMeshEdgePoint &)(*this))->FUN_006cf900((const ::FUN_006cf900_Class *)&(src));
    f18 = src.f18;
    f1c = src.f1c;
    return *this;
}
// Copies src into this, then copies the f18 and f1c floats from src, and returns this.
// @fnv 0x006dbb40
NavMeshEdgePoint& NavMeshEdgePoint::FUN_006dbb40(const NavMeshEdgePoint& src)
{
    reinterpret_cast<::FUN_006cf900_Class *>((void *)&(const ::NavMeshEdgePoint &)(*this))->FUN_006cf900((const ::FUN_006cf900_Class *)&(src));
    f18 = src.f18;
    f1c = src.f1c;
    return *this;
}

namespace fnv_006dbb80 {
struct FUN_006db4d0_Class
{
    void* FUN_006dbb80(unsigned int flags);
};
// @fnv 0x006dbb80
void* FUN_006db4d0_Class::FUN_006dbb80(unsigned int flags)
{
    reinterpret_cast<::fnv_006db4d0::FUN_006db4d0_Class *>(this)->InitializeAndClear();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006dbb80

namespace fnv_006dbbb0 {
struct TwoIntRecord
{
    int a;
    int b;
    char c[4];
    TwoIntRecord(const TwoIntRecord&);
    TwoIntRecord& operator=(const TwoIntRecord&);
};
struct FUN_006dbbb0_Class
{
    TwoIntRecord m_handle;
    TwoIntRecord* CopyHandle(const TwoIntRecord* src);
};
// Copies the 8-byte handle from src into m_handle and then copies the 3 trailing bytes at offset 8, returning &m_handle.
// @fnv 0x006dbbb0
TwoIntRecord* FUN_006dbbb0_Class::CopyHandle(const TwoIntRecord* apSource)
{
    m_handle.TwoIntRecord::TwoIntRecord(*apSource);
    for (unsigned int i = 0; i < 3; ++i)
        ((char*)&m_handle.c)[i] = ((char*)&apSource->c)[i];
    return &m_handle;
}
}  // namespace fnv_006dbbb0

struct FUN_006db720_Class
{
    void FUN_006db720();
    void* FUN_006dbc00(unsigned int flags);
};
// @fnv 0x006dbc00
void* FUN_006db720_Class::FUN_006dbc00(unsigned int flags)
{
    reinterpret_cast<::fnv_006db720::FUN_006db720_Class *>(this)->FUN_006db720();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006dbc30_Class
{
    void FUN_006db740();
    void* FUN_006dbc30(unsigned int flags);
};
void FUN_006db930();
struct FUN_006dbc60_Class
{
    void FUN_006db930();
    void* FUN_006dbc60(unsigned int flags);
};
// Calls FUN_006db930, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006dbc60
void* FUN_006dbc60_Class::FUN_006dbc60(unsigned int flags)
{
    reinterpret_cast<::fnv_006db930::FUN_006db930_Class *>(this)->FUN_006db930();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_006db950_Class
{
    void FUN_006db950();
    void* FUN_006dbc90(unsigned int flags);
};

// Calls FUN_006db950, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006dbc90
void* FUN_006db950_Class::FUN_006dbc90(unsigned int flags)
{
    reinterpret_cast<::FUN_006db950 *>(this)->FUN_006db950::~FUN_006db950();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_006dbcc0
{
    void* FUN_006dbcc0(unsigned int);
};
// Calls InitAndClear on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006dbcc0
void* S_006dbcc0::FUN_006dbcc0(unsigned int flags)
{
    reinterpret_cast<::fnv_006dba10::FUN_006dba10_Class *>((this))->InitAndClear();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct RetObj
{
};
struct FUN_006dbd90_Class
{
    int m_unk0;
    char* m_unk4;
    int FUN_006dc500();
    void ConstructInPlace(void* dst, unsigned int n);
    int AllocateSlot(void* src);
};
// @fnv 0x006dbd90
int FUN_006dbd90_Class::AllocateSlot(void* src)
{
    int dst = FUN_006dc500();
    ConstructInPlace(m_unk4 + (unsigned int)dst * 0x54, 1);
    reinterpret_cast<::FUN_006e4430_class *>((((RetObj*)(m_unk4 + (unsigned int)dst * 0x54))))->operator=((*(const ::FUN_006e4430_class *)(src)));
    return dst;
}

struct FUN_006dbf20_Class
{
    void FUN_006dbf20(char* dst, char* src, unsigned int count);
};

// Copies count elements of 0x54 bytes from src to dst, iterating forward or backward depending on the relative addresses.
// @fnv 0x006dbf20
void FUN_006dbf20_Class::FUN_006dbf20(char* dst, char* src, unsigned int count)
{
    if (!(count > 0))
    {
    }
    else
    {
        if (dst < src)
        {
            for (unsigned int i = 0; i < count; ++i)
                std::memmove(dst + i * 0x54, src + i * 0x54, 0x54);
        }
        else if (dst > src)
        {
            for (int i = (int)count - 1; i >= 0; --i)
                std::memmove(dst + i * 0x54, src + i * 0x54, 0x54);
        }
    }
}

struct FUN_006dc370_Class
{
    void* vtable;
    FUN_006dc370_Class* FUN_006dc370();
};
namespace fnv_006dc4d0 {

struct FUN_006dc4d0_Class
{
    void* FUN_006dc4d0(unsigned int flags);
};

// Calls FUN_006d32c0 on this, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006dc4d0
void* FUN_006dc4d0_Class::FUN_006dc4d0(unsigned int flags)
{
    ((FUN_006d32c0_Class*)this)->FUN_006d32c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006dc4d0

struct Inner04
{
};
struct SetupHelper
{
};
struct FUN_006dcea0_Class
{
    void* ConstructWithSetup(void*, void*);
};
struct FUN_006dfd70_Class
{
    unsigned int* GetAt(int, unsigned int);
    bool FUN_006dfd70(unsigned int idx);
};
// Iterates over all entries up to GetFlags(), calls InitFromLookup on each element obtained via GetAt(i, idx), and returns true.
// @fnv 0x006dfd70
bool FUN_006dfd70_Class::FUN_006dfd70(unsigned int idx)
{
    unsigned int i = 0;
    for (; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())); ++i)
        reinterpret_cast<::FUN_006df440_owner *>((((FUN_006dfd70_Class*)(uintptr_t)*GetAt(i, idx))))->InitFromLookup({});
    return true;
}

struct FUN_006c0010_Class
{
    void FUN_006c0010(void* dst, void* src, unsigned int count);
};
// @fnv 0x006c0010
void FUN_006c0010_Class::FUN_006c0010(void* apDest, void* apSource, unsigned int count)
{
    if (count <= 0)
        return;
    if (apDest < apSource)
    {
        for (unsigned int i = 0; i < count; ++i)
            std::memmove((char*)apDest + i * 0x1c, (const char*)apSource + i * 0x1c, 0x1c);
    }
    else if (apDest > apSource)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            std::memmove((char*)apDest + i * 0x1c, (const char*)apSource + i * 0x1c, 0x1c);
    }
}

struct PathingLocationArray
{
    int m_iElementCount;
    int m_vContactPosition;
    int m_dataLength;
    virtual int fn0();
    virtual int Write(unsigned int);
    void ConstructItems(PathingLocation*, unsigned int);
    void ResizeAndConstruct(unsigned int requested, unsigned int savedSize);
};
// Resets the array, allocates space for max(requested, savedSize) via Write, then constructs savedSize items into the buffer.
// @fnv 0x006d0140
void PathingLocationArray::ResizeAndConstruct(unsigned int requested, unsigned int savedSize)
{
    m_iElementCount = 0;
    m_vContactPosition = 0;
    m_dataLength = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        m_iElementCount = Write(requested);
        m_dataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructItems(reinterpret_cast<PathingLocation*>(m_iElementCount), savedSize);
        m_vContactPosition = savedSize;
    }
}

struct FUN_006d05e0_Class
{
    void FUN_006d05e0(int, unsigned int);
};
struct FUN_006d0310_Class
{
    virtual int vfn();
    void* m_iElementCount;
    int m_vContactPosition;
    int m_dataLength;
    virtual void* Write(unsigned int);
    void FUN_006d05e0(int, unsigned int);
    void FUN_006d0310(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x006d0310
void FUN_006d0310_Class::FUN_006d0310(unsigned int requested, unsigned int savedSize)
{
    m_iElementCount = nullptr;
    m_vContactPosition = 0;
    m_dataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_iElementCount = Write(requested);
        m_dataLength = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::Array6d0 *>(this)->FUN_006d05e0((struct ::FUN_006a0480 *)(m_iElementCount), savedSize);
        m_vContactPosition = savedSize;
    }
}

struct FUN_006dc440_Class : public FUN_006dc1d0_Class
{
    void FUN_006dc440(unsigned int requested, unsigned int savedSize);
};
// Sets the object's vtable pointer to DAT_0106cca0, calls FUN_006dc440(0, 0) on it, and returns this.
// @fnv 0x006db9e0
void* FUN_006db9e0_Class::FUN_006db9e0()
{
    *reinterpret_cast<int**>(this) = &DAT_0106cca0;
    reinterpret_cast<::FUN_006dc440_Class *>((reinterpret_cast<FUN_006dc440_class*>(this)))->FUN_006dc440(0, 0);
    return this;
}
// Sets the vtable to DAT_0106cc8c, calls FUN_006dc440 with 0, 0, and returns this.
// @fnv 0x006dc370
FUN_006dc370_Class* FUN_006dc370_Class::FUN_006dc370()
{
    vtable = &DAT_0106cc8c;
    reinterpret_cast<::FUN_006dc440_Class *>((reinterpret_cast<FUN_006dc440_class*>(this)))->FUN_006dc440(0, 0);
    return this;
}

struct FUN_006dc640_Class
{
    void FUN_006dc640(char* dst, char* src, unsigned int count);
};
// Copies count 32-byte elements from src to dst, iterating forward or backward depending on the relative addresses to handle overlap.
// @fnv 0x006dc640
void FUN_006dc640_Class::FUN_006dc640(char* apDest, char* apSource, unsigned int count)
{
    if (count <= 0)
        return;
    if (apDest < apSource)
    {
        for (unsigned int i = 0; i < count; i++)
            std::memmove(apDest + i * 32, apSource + i * 32, 32);
    }
    else if (apDest > apSource)
    {
        for (int i = (int)count - 1; i >= 0; i--)
            std::memmove(apDest + i * 32, apSource + i * 32, 32);
    }
}

struct BGSSaveFormBuffer
{
};
struct FUN_006dc890_Class
{
    char m_auiShapeKeys[0x18];
    int m_f18;
    int m_f1c;
    unsigned char m_flag;
    void FUN_006dc890(BGSSaveFormBuffer* buffer);
};
// Saves m_flag, m_f18, m_f1c and the first 0xc bytes to the buffer, then saves bytes at offset 0xc if the int at offset 0x20 equals 1.
// @fnv 0x006dc890
void FUN_006dc890_Class::FUN_006dc890(BGSSaveFormBuffer* buffer)
{
    unsigned char flag = m_flag;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&flag, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_f18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_f1c, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(this, 0xc, 0);
    if (*(int*)((char*)this + 0x20) == 1)
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)&this->m_auiShapeKeys[12], 0xc, 0);
}

struct NavMeshPtr
{
    void* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
};
struct FUN_00438690
{
    void* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    unsigned int m_uiGrow;
    ~FUN_00438690();
};
struct PSM3 : FUN_00438690
{
    PSM3();
};
struct ArrSI
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_006a7ad0_shell
{
};
struct PathingLocation_Helper
{
};
struct FUN_006df760_shell
{
    unsigned short GetShortValueAtOffset24();
};
struct FUN_00691350_S
{
};
struct FUN_006df780_S
{
};

struct FUN_006dfe90_S
{
    bool FUN_006dfe90(PathingLocation* loc, bool b);
};

// @fnv 0x006dfe90
bool FUN_006dfe90_S::FUN_006dfe90(PathingLocation* pLocation, bool bFlag)
{
    NavMeshPtr apSearchNavMesh;
    bool bResult;
    if (reinterpret_cast<::PathingLocation *>((((PathingLocation_Helper*)pLocation)))->ResolveNavMesh(apSearchNavMesh))
    {
        PSM3 triangles;
        reinterpret_cast<::NavMeshStub *>((((FUN_00691350_S*)apSearchNavMesh.m_pObject)))->CollectTriangleCells(((FUN_006df760_shell*)pLocation)->GetShortValueAtOffset24(), (::OutArr &)(triangles));
        bResult = false;
        for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&triangles)))->GetName())); i++)
        {
            unsigned int index = ((unsigned int)(reinterpret_cast<::S3e60 *>((((FUN_006a7ad0_shell*)&triangles)))->FUN_006a7ad0(i)));
            if (index < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())))
            {
                if (reinterpret_cast<::Owner6df780 *>((((FUN_006df780_S*)(uintptr_t)*((Arr*)this)->GetAt(index))))->UpdateNavMeshResults((::FUN_006df760_shell *)(pLocation), bFlag))
                    bResult = true;
            }
        }
        return bResult;
    }
    return false;
}

struct Elem16
{
    int v;
};
struct Arr16
{
};
struct FUN_006c8c70_Class : public FUN_006dc1d0_Class
{
    void FUN_006c8c70(unsigned int requested, unsigned int savedSize);
};
struct EH;
struct FUN_0069b310_S
{
public:
    unsigned int AppendElement(const ::EH *);
public:
    void ResetAndWrite(unsigned int, unsigned int);
};
// Sets the vtable to DAT_0106cc3c, calls ResetAndWrite with 0, 0, and returns this.
// @fnv 0x006db4a0
S_006db4a0* S_006db4a0::FUN_006db4a0()
{
    vtable = &DAT_0106cc3c;
    reinterpret_cast<::FUN_0069b310_S *>((reinterpret_cast<Dummy_0069af30*>(this)))->ResetAndWrite(0, 0);
    return this;
}
struct FUN_006dbbb0_S
{
};
struct FUN_006db4f0_Class
{
    int m_auiShapeKeys;
    char* m_data;
    unsigned int FUN_006db4f0(intptr_t value);
};
// @fnv 0x006db4f0
unsigned int FUN_006db4f0_Class::FUN_006db4f0(intptr_t value)
{
    unsigned int idx = reinterpret_cast<::S5460 *>((((FUN_0069b310_S*)this)))->FUN_00978bc0();
    reinterpret_cast<::PlacementRange *>((((FUN_0069b310_S*)this)))->ConstructBounds((::NiBound *)(void *)(m_data + idx * 0xc), 1);
    reinterpret_cast<::fnv_006dbbb0::FUN_006dbbb0_Class *>((((FUN_006dbbb0_S*)(m_data + idx * 0xc))))->CopyHandle((const ::fnv_006dbbb0::TwoIntRecord *)(value));
    return idx;
}

struct FUN_006dbfc0_Class
{
    virtual void v0();
    virtual char* v1(unsigned int);
    virtual char* v2(char*, unsigned int);
    virtual char* v3(char*, unsigned int);
    char* m_ptr;
    unsigned int m_iElementCount;
    unsigned int m_data;
    void FUN_006dbfc0(unsigned int data, unsigned int size);
};
// @fnv 0x006daeb0
void FUN_006daeb0_Class::FUN_006daeb0(unsigned int pos)
{
    if (pos == m_cap)
        return;
    if (pos < m_uiBufferCapacity)
    {
        ((FUN_006dbee0_s*)this)->FUN_006dbee0((Elem*)((char*)m_data + pos * 0x54), m_uiBufferCapacity - pos);
        m_uiBufferCapacity = pos;
    }
    reinterpret_cast<::FUN_006dbfc0_Class *>(this)->FUN_006dbfc0(pos, m_uiBufferCapacity);
    m_cap = pos;
}
// @fnv 0x006dbfc0
void FUN_006dbfc0_Class::FUN_006dbfc0(unsigned int data, unsigned int size)
{
    if (m_ptr)
    {
        if (size == m_data)
        {
            m_ptr = v3(m_ptr, data);
        }
        else
        {
            char* p = v1(data);
            ((FUN_006dbf20_Class*)this)->FUN_006dbf20(p, m_ptr, size);
            ::FUN_006a8500((::DummyClass_006a8500 *)(((FUN_006c8a30_Class*)this)));
            m_ptr = p;
        }
    }
    else
    {
        m_ptr = v1(data);
        m_data = data;
    }
}


extern const char str_0106649c[];

struct AutoMemHelper
{
    int m_data;
    AutoMemHelper(int context, bool flag, const char* source, int line);
    ~AutoMemHelper();
};

struct FUN_0044cd00_Class
{
    int m_data[5];
    FUN_0044cd00_Class(void* owner, void* first, void* second);
};

struct FUN_006c65b0_Class
{
    int m_vtbl;
    int m_uiStandInValue;
    void* m_unknown;
    int m_iValueAfterStandIn;
    int* m_data;
    FUN_0044cd00_Class* FUN_006c65b0(unsigned int index);
};

// Allocates a FUN_0044cd00_Class from this object and the two m_data entries at index*2 and index*2+1.
// @fnv 0x006c65b0
FUN_0044cd00_Class* FUN_006c65b0_Class::FUN_006c65b0(unsigned int index)
{
    AutoMemHelper helper(6, true, str_0106649c, 149);
    return new FUN_0044cd00_Class(this, &m_data[index * 2], &m_data[index * 2 + 1]);
}

struct _Mem_2064
{
    ~_Mem_2064();
};

struct FUN_006d32c0_StandIn : public _Mem_2064
{
    void FUN_006d32c0();
};
// @fnv 0x006d33a0
void FUN_006d33a0_Class::FUN_006d33a0()
{
    reinterpret_cast<::FUN_006d32c0_StandIn *>((reinterpret_cast<FUN_006d32c0_Class*>(&this->m_f)))->FUN_006d32c0();
}

// @fnv 0x006d32c0
void FUN_006d32c0_StandIn::FUN_006d32c0()
{
    reinterpret_cast<::PathingLocation *>(this)->HasValidTriangle();
}

class PathingLocation;
struct PathingRequest
{
    ~PathingRequest();
public:
    void SetDestination(::PathingLocation *);
public:
    void SetCenterRadius(float);
public:
    void CopyTo(::PathingRequest *);
};

struct FUN_006d3b20_Class : public PathingRequest
{
    void DestroyPathingRequest();
};

// @fnv 0x006d3b20
void FUN_006d3b20_Class::DestroyPathingRequest()
{
    reinterpret_cast<::FUN_006dad70_shell *>(this)->DestroyPathingRequest();
}

struct FUN_006d4550_Helper
{
};

struct FUN_006d4550_Class
{
    FUN_006d4550_Class();
};

// @fnv 0x006d4550
FUN_006d4550_Class::FUN_006d4550_Class()
{
    ::FUN_006a0480((void *)(((FUN_006d4550_Helper*)this)));
}

struct CombatThreatEntry;

struct BSSimpleArrayActor
{
    void Clear(bool clear);
};

struct FUN_006f3170_Class
{
    bool FUN_006f3170();
};

struct FUN_00869600_Class
{
    unsigned int FUN_00869600();
};

struct FUN_009a3b20_Class
{
    void CopyCombatThreatEntries(CombatThreatEntry* destination, CombatThreatEntry* source, unsigned int count);
};

struct FUN_006db140_Class
{
    virtual int vfn0()
    {
        return 0;
    }
    virtual CombatThreatEntry* vfn4(unsigned int size)
    {
        return 0;
    }

    CombatThreatEntry* m_data;
    unsigned int m_uiItemCount;
    unsigned int m_savedSize;

    void FUN_006db140(unsigned int index, unsigned int count, bool clear);
};

// @fnv 0x006db140
void FUN_006db140_Class::FUN_006db140(unsigned int index, unsigned int count, bool clear)
{
    unsigned int uiNewSize;
    CombatThreatEntry* pNewData;

    if (count >= m_uiItemCount)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArrayActor*>(this)))->Clear(clear);
    }
    else
    {
        if (clear && reinterpret_cast<FUN_006f3170_Class*>(this)->FUN_006f3170())
        {
            uiNewSize = reinterpret_cast<FUN_00869600_Class*>(this)->FUN_00869600();

            pNewData = vfn4(uiNewSize);

            reinterpret_cast<FUN_009a3b20_Class*>(this)->CopyCombatThreatEntries(pNewData, m_data, index);

            reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(m_data) + index * 0x14,
                                                                      count);

            reinterpret_cast<FUN_009a3b20_Class*>(this)->CopyCombatThreatEntries(
                reinterpret_cast<CombatThreatEntry*>(reinterpret_cast<char*>(pNewData) + index * 0x14),
                reinterpret_cast<CombatThreatEntry*>(reinterpret_cast<char*>(m_data) + index * 0x14 + count * 0x14),
                m_uiItemCount - count);

            ::FUN_006a8500((::DummyClass_006a8500 *)(reinterpret_cast<FUN_006c8a30_Class*>(this)));

            m_data = pNewData;
            m_savedSize = uiNewSize;
        }
        else
        {
            reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(m_data) + index * 0x14,
                                                                      count);

            reinterpret_cast<FUN_009a3b20_Class*>(this)->CopyCombatThreatEntries(
                reinterpret_cast<CombatThreatEntry*>(reinterpret_cast<char*>(m_data) + index * 0x14),
                reinterpret_cast<CombatThreatEntry*>(reinterpret_cast<char*>(m_data) + index * 0x14 + count * 0x14),
                m_uiItemCount - index - count);
        }

        m_uiItemCount -= count;
    }
}

struct FUN_006dc070_Class : public FUN_006dbd90_Class
{
    void FUN_006dc070(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x006dc070
void FUN_006dc070_Class::FUN_006dc070(unsigned int requested, unsigned int savedSize)
{
    this->m_unk4 = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 12) = 0;

    if (savedSize > requested)
    {
        requested = savedSize;
    }

    if (requested > 0)
    {
        this->m_unk4 =
            (char*)reinterpret_cast<FUN_006dc1d0_Class*>(this)->Write(requested);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 12) = requested;
    }

    if (savedSize > 0)
    {
        ConstructInPlace(reinterpret_cast<void*>(this->m_unk4),
                         savedSize);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = savedSize;
    }
}

struct FUN_00438b90_class
{
    bool FUN_00438b90();
};

struct FUN_006925b0_class
{
};

struct FUN_006d0680_class
{
};

struct FUN_006dc260_Class
{
    virtual int VirtualCall0();
    virtual int VirtualCall4(int);
    int m_uiFilterValue;
    unsigned int m_uiItemCount;
    int m_iElementCount;

    unsigned int GetNextIndex();
};

// @fnv 0x006dc260
unsigned int FUN_006dc260_Class::GetNextIndex()
{
    if (reinterpret_cast<FUN_00438b90_class*>(this)->FUN_00438b90())
    {
        if (this->m_iElementCount == 0)
        {
            int value = 4;
            this->m_uiFilterValue = this->VirtualCall4(value);
            this->m_iElementCount = value;
        }
        else
        {
            unsigned int size = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>((reinterpret_cast<FUN_006925b0_class*>(this)))->FUN_009a3910()));
            reinterpret_cast<::FUN_006d0680_cls *>((reinterpret_cast<FUN_006d0680_class*>(this)))->FUN_006d0680(size, this->m_uiItemCount);
            this->m_iElementCount = static_cast<int>(size);
        }
    }

    ++this->m_uiItemCount;
    return this->m_uiItemCount - 1;
}

namespace fnv_006dc500 {
struct FUN_00438b90_class
{
    bool FUN_00438b90();
};

struct FUN_006925b0_class
{
};

struct FUN_006dc500_Class
{
    virtual int vfn();
    int m_iElementCount;
    int m_vContactPosition;
    int m_dataLength;
    virtual int Write(unsigned int);
    int FUN_006dc500();
};

// @fnv 0x006dc500
int FUN_006dc500_Class::FUN_006dc500()
{
    if (reinterpret_cast<FUN_00438b90_class*>(this)->FUN_00438b90())
    {
        if (m_dataLength == 0)
        {
            int size = 4;
            m_iElementCount = Write(size);
            m_dataLength = size;
        }
        else
        {
            unsigned int size = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>((reinterpret_cast<FUN_006925b0_class*>(this)))->FUN_009a3910()));
            reinterpret_cast<::FUN_006dbfc0_Class *>((reinterpret_cast<FUN_006daeb0_Class*>(this)))->FUN_006dbfc0(size, m_vContactPosition);
            m_dataLength = size;
        }
    }

    m_vContactPosition++;
    return m_vContactPosition - 1;
}
}  // namespace fnv_006dc500

struct PathingLocationGetNavMeshHelper
{
};

struct LocS
{
};

struct FUN_00691240_shell
{
    unsigned int ForwardToInner(::NiPoint3* location);
};

struct GO
{
    operator FUN_00691240_shell*() const;
};

struct FUN_006df5f0_Class
{
};

struct FUN_006dfdc0_Class
{
    bool FUN_006dfdc0(PathingLocation* path);
};

struct FUN_006d01d0_Class
{
    virtual int vfn()
    {
        return 0;
    }
    // Returns a null pointer for the requested size; a stub allocator that never allocates memory.
// @fnv 0x006d01d0
    virtual void* FUN_006d01d0_alloc(unsigned int size)
    {
        return 0;
    }


    void* m_data;
    unsigned int m_vContactPosition;
    unsigned int m_pRayCursor;

    void FUN_006d01d0(unsigned int count, bool clear);
};

void FUN_006d01d0_Class::FUN_006d01d0(unsigned int count, bool clear)
{
    if (count == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArrayActor*>(this)))->Clear(clear);
    }
    else if (count > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_data = FUN_006d01d0_alloc(count);
            m_pRayCursor = count;
        }
        else
        {
            reinterpret_cast<::FUN_006d0680_cls *>(this)->FUN_006d0680(count, m_vContactPosition);
            m_pRayCursor = count;
        }

        reinterpret_cast<::Array6d0 *>((reinterpret_cast<FUN_006d0310_Class*>(this)))->FUN_006d05e0(
            (struct ::FUN_006a0480 *)(reinterpret_cast<char*>(m_data) + m_vContactPosition * 24), count - m_vContactPosition);
        m_vContactPosition = count;
    }
    else if (count < m_vContactPosition)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(m_data) + count * 24,
                                                                  m_vContactPosition - count);
        m_vContactPosition = count;

        if (clear && count <= (m_pRayCursor >> 2))
        {
            reinterpret_cast<::FUN_006d0680_cls *>(this)->FUN_006d0680(count, count);
            m_pRayCursor = count;
        }
    }
    else
    {
        reinterpret_cast<::Array6d0 *>((reinterpret_cast<FUN_006d0310_Class*>(this)))->FUN_006d05e0(
            (struct ::FUN_006a0480 *)(reinterpret_cast<char*>(m_data) + m_vContactPosition * 24), count - m_vContactPosition);
        m_vContactPosition = count;
    }
}

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pcFile, int iLine);
    ~AutoMemContext();
    int m_iPrev;
};

struct SpinLock6c67
{
    int m_kNextStreamField[2];
};

struct FUN_0096a2d0
{
    FUN_0096a2d0* m_pkNext;
    void* m_pvItem;
    FUN_0096a2d0();
};

struct FUN_006c73b0
{
    FUN_006c73b0(int iCapacity);
    ~FUN_006c73b0();
    int m_kNextStreamField[4];
};

struct Queue6c67
{
    int unk00;
    FUN_0096a2d0* m_pkHead;
    FUN_0096a2d0* m_pkTail;
    int unk0C[2];
    FUN_006c73b0* m_pkTable;
    int m_iArrayLength;
    int unk1C;
    SpinLock6c67 m_kLock;
    void ClearQueue(bool abFreeNodes);
};

// Locks the queue, deletes its table and all queued nodes, then optionally recreates an empty head/tail and table with the old capacity, and unlocks.
// @fnv 0x006c6700
void Queue6c67::ClearQueue(bool abFreeNodes)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kLock))->FUN_0040fbf0((char *)(0));
    AutoMemContext kMemContext(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
                               "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.inl", 0x115);
    int iCapacity = ::FUN_00559450((int *)(m_pkTable));
    delete m_pkTable;
    m_pkTable = 0;
    m_iArrayLength = 0;
    while (m_pkHead)
    {
        FUN_0096a2d0* pkNext = m_pkHead->m_pkNext;
        m_pkHead->m_pvItem = 0;
        delete m_pkHead;
        m_pkHead = pkNext;
    }
    if (!abFreeNodes)
    {
        m_pkHead = new FUN_0096a2d0;
        m_pkTail = m_pkHead;
        m_pkTable = new FUN_006c73b0(iCapacity);
    }
    reinterpret_cast<::RecursiveSpinLock *>(&(m_kLock))->FUN_0040fba0();
}

struct FUN_006c6ae0_Base
{
    virtual ~FUN_006c6ae0_Base();
};
struct FUN_006c6a80 : FUN_006c6ae0_Base
{
    virtual ~FUN_006c6a80();
};
// Calls FUN_006c6a80, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x006c6100
void* FUN_006c6100_Class::FUN_006c6100(unsigned int flags)
{
    reinterpret_cast<::FUN_006c6a80 *>(this)->FUN_006c6a80::~FUN_006c6a80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x006c6a80
FUN_006c6a80::~FUN_006c6a80()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

namespace fnv_006c6e60 {

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT context, bool flag, const char* source, int line);
    ~AutoMemContext();
    int m_data;
};


struct TSQueueNode
{
    TSQueueNode* next;
    int item;
    TSQueueNode();
};

struct TSQueue
{
    virtual void vfn0();
    virtual void vfn4();
    virtual void OnPush();
    int unk04;
    TSQueueNode* tail;
};

struct TSQueueHandle
{
    TSQueue* queue;
    void** hazard;
    void Push(const int& item);
};

// Allocates a TSQueueNode for item and links it onto the queue's tail using hazard-pointer CAS loops, then clears the hazard pointer.
// @fnv 0x006c6e60
void TSQueueHandle::Push(const int& item)
{
    TSQueueNode* node2;
    AutoMemContext ctx2(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, ::kThreadSafeStructuresSourceFile, 0x76);
    TSQueueNode* volatile tail = 0;
    node2 = new TSQueueNode;
    node2->item = item;
    while (true)
    {
        *hazard = tail = queue->tail;
        if (tail != queue->tail)
            continue;
        TSQueueNode* next = tail->next;
        if (tail != queue->tail)
            continue;
        if (next)
        {
            ::FUN_004491c0((volatile long *)(void *)(&queue->tail), (int)(intptr_t)next, (int)(intptr_t)tail);
            continue;
        }
        if (::FUN_004491c0((volatile long *)(tail), (int)(intptr_t)node2, 0))
        {
            queue->OnPush();
            break;
        }
    }
    ::FUN_004491c0((volatile long *)(void *)(&queue->tail), (int)(intptr_t)node2, (int)(intptr_t)tail);
    *hazard = 0;
}
}  // namespace fnv_006c6e60

struct Node
{
    Node* m_next;
    void* m_data;
};

struct Queue
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    Node* m_pFirstNode;
    Node* m_pTail;
};


struct QueueConsumer
{
    Queue* m_queue;
    Node** m_hp0;
    Node** m_hp1;

    bool FUN_006c6fe0(void** out_val);
};

struct DummyRef
{
    void IncRefCount();
    void DecRefCount();
};

struct FUN_006c7390
{
    int unk00;
    int unk04;
    NiPointer<DummyRef> unk08;
    FUN_006c7390();
};
// @fnv 0x006c7370
void* FUN_006c7370_Class::FUN_006c7370()
{
    new ((void *)this) ::FUN_006c7390();
    return this;
}

// @fnv 0x006c7390
FUN_006c7390::FUN_006c7390()
{}

struct AlchEquip
{
};
struct BGSSaveLoadGame
{
};
struct FUN_006c7560_arg
{
    int unk00;
    int m04;
};
struct FUN_006c7560_self
{
    BGSSaveLoadGame* m00;
    int unk04;
    int unk08;
    int m0C;
    FUN_006c7560_arg* m10;
};
struct FUN_006c7560_shell : FUN_006c75f0_Class
{
    void FUN_006c7560(FUN_006c7560_arg* arg);
};
// Pops the head node from m_queue using a CAS loop, returns its data via out_val, and frees the old head; returns false when the queue is empty.
// @fnv 0x006c6fe0
bool QueueConsumer::FUN_006c6fe0(void** ppOutValue)
{
    Node* volatile head7 = 0;
    Node* volatile next2;
    Node* tail;

    while (1)
    {
        head7 = m_queue->m_pFirstNode;
        m_hp0[0] = head7;
        if (head7 != m_queue->m_pFirstNode)
        {
            continue;
        }

        tail = m_queue->m_pTail;
        next2 = head7->m_next;
        m_hp1[0] = next2;
        if (head7 != m_queue->m_pFirstNode)
        {
            continue;
        }

        if (next2 == 0)
        {
            m_hp0[0] = 0;
            *ppOutValue = 0;
            return false;
        }

        if (head7 == tail)
        {
            ::FUN_004491c0((volatile long *)(void *)(&m_queue->m_pTail), (long)(intptr_t)next2, (long)(intptr_t)tail);
            continue;
        }

        *ppOutValue = next2->m_data;
        if (::FUN_004491c0((volatile long *)(void *)(&m_queue->m_pFirstNode), (long)(intptr_t)next2, (long)(intptr_t)head7))
        {
            m_queue->vfn3();
            next2->m_data = 0;
            break;
        }
    }

    m_hp0[0] = 0;
    m_hp1[0] = 0;
    reinterpret_cast<::FUN_006c7560_shell *>(this)->FUN_006c7560((::FUN_006c7560_arg *)(head7));
    return true;
}
// @fnv 0x006c7560
void FUN_006c7560_shell::FUN_006c7560(FUN_006c7560_arg* arg)
{
    arg->m04 = 0;
    reinterpret_cast<::CombatProcedure *>((reinterpret_cast<AlchEquip*>(arg)))->Initialize(
        (::CombatController *)(reinterpret_cast<FUN_006c7560_self*>(this)->m10));
    reinterpret_cast<FUN_006c7560_self*>(this)->m10 = arg;
    reinterpret_cast<FUN_006c7560_self*>(this)->m0C = reinterpret_cast<FUN_006c7560_self*>(this)->m0C + 1;
    if (reinterpret_cast<FUN_006c7560_self*>(this)->m0C ==
        static_cast<int>(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FUN_006c7560_self*>(this)->m00))->FUN_0084e3a0()))))
    {
        reinterpret_cast<::LFFreeList *>(this)->PruneFreeList();
    }
}

struct FUN_006c7850
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_006c7850();
    ~FUN_006c7850();
};
struct FUN_0042fb00
{
    int unk00;
    FUN_0042fb00();
    ~FUN_0042fb00();
};
struct FUN_006c87c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_006c87c0();
    ~FUN_006c87c0();
};
struct FUN_00699450
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00699450();
    ~FUN_00699450();
};
struct FUN_006c77a0 : FUN_006c7850
{
    unsigned int unk18;
    FUN_0042fb00 m1c;
    FUN_0042fb00 m20;
    FUN_006c87c0 m24;
    FUN_00699450 m34;
    unsigned char unk54;
    FUN_006c77a0(unsigned int value);
};
// Stores the given value into unk18 and clears unk54.
// @fnv 0x006c77a0
FUN_006c77a0::FUN_006c77a0(unsigned int value)
{
    unk18 = value;
    unk54 = 0;
}

namespace fnv_006c7850 {
struct FUN_006c78d0
{
    virtual void vfn0();
    int unk04;
    FUN_006c78d0();
    ~FUN_006c78d0();
};
struct CF_0081c630
{
    int unk00;
    CF_0081c630();
};
struct FUN_006c7850 : public FUN_006c78d0
{
    unsigned int unk08;
    unsigned char unk0c;
    CF_0081c630 unk10;
    FUN_006c7850();
};
// Constructor that initializes unk08 to 0 and unk0c to 1.
// @fnv 0x006c7850
FUN_006c7850::FUN_006c7850() : unk08(0), unk0c(1)
{}
}  // namespace fnv_006c7850

class PathingActorData;
struct PathLocationView
{
};
struct PathRequestView
{
};
struct PathDoorView
{
};
struct DoorStep
{
    PathDoorView* door;
    NiPoint3 point;
};
struct PathEdgeArray
{
    void** vtable;
    void* data;
    unsigned int size, capacity;
    void* FUN_006a1440(unsigned int);
};
struct PathDoorArray
{
    void** vtable;
    DoorStep* data;
    unsigned int size, capacity;
    DoorStep& FUN_00558dd0(unsigned int);
    DoorStep& FUN_006cedb0();
};
struct TeleportPathHelper
{
    PathEdgeArray edges;
    PathDoorArray doors;
    NiPoint3 start, end;
    TeleportPathHelper();
    ~TeleportPathHelper();
};
struct PathSearchBuckets
{
    void* buckets[2039];
    unsigned int count;
};
struct PathSearchCache
{
    float value;
    void* buckets[20];
};
struct PathLocationStorage
{
    void** vtable;
    NiPoint3 point;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    unsigned int unk20;
    unsigned short unk24;
    bool unk26;
    unsigned int unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct FUN_006f33b0
{
    void** vtable;
    void* allocatorVtable;
    void* allocatorData;
    unsigned int allocatorSize, allocatorCapacity;
    PathSearchBuckets openNodes;
    PathSearchCache closedNodes;
    void* unk2048;
    void* unk204c;
    void* unk2050;
    bool unk2054;
    unsigned int unk2058, unk205c, unk2060;
    PathLocationStorage location;
    PathEdgeArray edges;
    FUN_006f33b0();
    ~FUN_006f33b0();
};
struct PathingContext
{
    int unk00;
    TESWorldSpace* worldSpace;
    TESObjectCELL* cell;
};
struct FUN_006dcee0 : public _Mem_2064
{
    virtual void Loc_006dcee0_Vfn();
    NiPoint3 m_kPoint;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;

    FUN_006dcee0(const NiPoint3& pt, TESObjectCELL* cell, TESWorldSpace* worldSpace);
};
struct Search_006b8340_Pool
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct Search_006b8340_OpenList
{
    void* m_items[2039];
    int m_uiItemCount;
};
struct Search_006b8340_Bins
{
    float m_vScale;
    int m_bins[20];
};
struct Search_006b8340_Base
{
    virtual ~Search_006b8340_Base();
    Search_006b8340_Pool m_kNodePool;
    Search_006b8340_OpenList m_openList;
    Search_006b8340_Bins m_bins;
    int unk2048;
    int unk204c;
    int unk2050;
    bool unk2054;
};
struct Search_006b8340_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct FUN_006cf340;
struct FUN_006cf440;
struct FUN_006b8420 : public Search_006b8340_Base
{
    NiPoint3 m_kRayStart;
    int unk2064;
    NiPoint3 m_goal;
    int unk2074;
    int unk2078;
    int unk207c;
    int unk2080;
    Search_006b8340_Result m_result;

    FUN_006b8420();
    ~FUN_006b8420();
};
struct FUN_006cf340
{
    virtual ~FUN_006cf340();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    FUN_006cf340(int a, int b, void* c);
    void** FUN_00877a30(unsigned int index);
};
struct FUN_006cf440
{
    virtual ~FUN_006cf440();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    FUN_006cf440(int a, int b, void* c);
};
struct RequestHelper
{
};
struct PathingSolution
{
};
class PathHandler
{
  public:
    PathingRequest* m_request;
    PathingSolution* m_pPathingSolution;
    void* m_unk08;

    bool FindPath(const NiPoint3& pt1, const NiPoint3& pt2, PathingContext* ctx, intptr_t flag);
};

struct PathBuilder
{
    PathRequestView* request;
    PathingSolution* solution;
    bool FUN_006c9b20();
};
// Runs a path search between the request's start and end locations, then builds the path through the resulting edges and doors, returning the search result.
// @fnv 0x006c9b20
bool PathBuilder::FUN_006c9b20()
{
    FUN_006f33b0 searchB;
    TeleportPathHelper dataB;
    reinterpret_cast<::FUN_006cee30_Class *>(&(dataB.edges))->FUN_006cee30(10);
    reinterpret_cast<::fnv_006ceea0::FUN_006ceea0_Class *>(&(dataB.doors))->FUN_006ceea0(10);
    PathingActorData* current = 0;
    if (!reinterpret_cast<::DoorAccessData *>((void *)(request))->ReadState98())
        current = reinterpret_cast<::FUN_006c9900_shell *>((request))->FUN_006c9900();
    bool _result = reinterpret_cast<::DoorSearchInit *>(&(searchB))->InitDoorSearch((::SearchLocation *)(::PathLocationView *)(((::PathLocationView *)(::GetOffsetC((intptr_t)(request))))), (::SearchLocation *)(::PathLocationView *)(((::PathLocationView *)(::FUN_006a9540((char *)(request))))), (::SearchResult *)(::TeleportPathHelper *)(&dataB), 0, 0.0f, current, 0);
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(dataB.edges))->GetName())) <= 1)
    {
        if (_result)
        {
            if (!reinterpret_cast<::PathHandler *>(this)->FindPath(reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathLocationView *)(::GetOffsetC((intptr_t)(request))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr), reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathLocationView *)(::FUN_006a9540((char *)(request))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr),
                          (::PathingContext *)(void *)(dataB.edges.FUN_006a1440(0)), (int)(0)))
                return false;
        }
    }
    else
    {
        NiPoint3 end3 = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathLocationView *)(::GetOffsetC((intptr_t)(request))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
        NiPoint3 origin6 = *((::NiPoint3 *)&(reinterpret_cast<::fnv_00568fa0::Fn568fa0 *>((((::DoorStep *)(reinterpret_cast<::S006949d0 *>(&(dataB.doors))->GetFirst()))->door))->FUN_00568fa0()));
        if (!reinterpret_cast<::PathHandler *>(this)->FindPath(end3, origin6, (::PathingContext *)(void *)(((void *)(reinterpret_cast<::EdgeArr *>(&(dataB.edges))->FUN_006ced70()))), (intptr_t)(((::DoorStep *)(reinterpret_cast<::S006949d0 *>(&(dataB.doors))->GetFirst()))->door)))
            return false;
        for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(dataB.doors))->GetName())) - 1; ++i)
        {
            NiPoint3 origin = dataB.doors.FUN_00558dd0(i).point;
            NiPoint3 point2 = *((::NiPoint3 *)&(reinterpret_cast<::fnv_00568fa0::Fn568fa0 *>((dataB.doors.FUN_00558dd0(i + 1).door))->FUN_00568fa0()));
            if (!reinterpret_cast<::PathHandler *>(this)->FindPath(origin, point2, (::PathingContext *)(void *)(dataB.edges.FUN_006a1440(i + 1)), (intptr_t)(dataB.doors.FUN_00558dd0(i + 1).door)))
            {
                reinterpret_cast<::FUN_006c9fa0_shell *>((solution))->SetByteAtOffset40(1);
                return false;
            }
        }
        end3 = dataB.doors.FUN_006cedb0().point;
        origin6 = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathLocationView *)(::FUN_006a9540((char *)(request))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
        if (!reinterpret_cast<::PathHandler *>(this)->FindPath(end3, origin6, (::PathingContext *)(void *)(((void *)(reinterpret_cast<::FUN_006ced90_stand *>(&(dataB.edges))->GetLastEdge()))), (int)(0)))
        {
            reinterpret_cast<::FUN_006c9fa0_shell *>((solution))->SetByteAtOffset40(1);
            return false;
        }
    }
    return _result;
}

namespace fnv_006cec40 {

struct FUN_004ff7e0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    ~FUN_004ff7e0();
};

struct LocationData6cec
{
    int unk00, unk04, unk08, unk0c;
    NiPoint3 kPos;
};

struct FUN_006dcc40 : FUN_004ff7e0
{
    FUN_006dcc40(void* pkSource);
};

class VirtualPathingNodeS
{
  public:
};


struct Mid6cec
{
};

struct PathingSolutionS
{
};

struct PathBuilder
{
    void* m_pVtbl;
    PathingSolutionS* m_pSolution;
    bool BuildPathSegment(unsigned int uiStart, unsigned int uiEnd);
};

// @fnv 0x006cec40
bool PathBuilder::BuildPathSegment(unsigned int uiStartIndex, unsigned int uiEndIndex)
{
    for (unsigned int i = uiStartIndex; i <= uiEndIndex; ++i)
    {
        FUN_006dcc40 kTargetPoint(((void *)(reinterpret_cast<::BaseProcess *>((((::fnv_006cec40::VirtualPathingNodeS *)(reinterpret_cast<::FUN_006e78b0_shell *>((m_pSolution))->FUN_006e78b0(i)))))->GetCurrentProcessData())));
        if (!::FUN_006cac70((const int *)(::fnv_006cec40::VirtualPathingNodeS *)(((::fnv_006cec40::VirtualPathingNodeS *)(reinterpret_cast<::FUN_006e78b0_shell *>((m_pSolution))->FUN_006e78b0(i))))))
            reinterpret_cast<::FUN_006dd460 *>(&(kTargetPoint))->FUN_006dd460_1((*(const ::NiPoint3 *)(&((::fnv_006cec40::LocationData6cec *)(reinterpret_cast<::PathingLocationProxy *>(&(kTargetPoint))->GetAssociatedNavMesh()))->kPos)));
        reinterpret_cast<::FUN_0069f920_cls *>((m_pSolution))->FUN_0069f920((intptr_t)(&kTargetPoint), (intptr_t)(&::NiPoint3::ZERO));
    }
    if (reinterpret_cast<::PathingGraphNode *>((((::fnv_006cec40::VirtualPathingNodeS *)(reinterpret_cast<::FUN_006e78b0_shell *>((m_pSolution))->FUN_006e78b0(uiEndIndex)))))->IsTransitionNode())
        reinterpret_cast<::Mid *>((((::fnv_006cec40::Mid6cec *)(reinterpret_cast<::S_FUN_006b05a0 *>((m_pSolution))->FUN_006b05a0()))))->FUN_006cc560(((int)(reinterpret_cast<::BGSMessageInitAccess *>((((::fnv_006cec40::VirtualPathingNodeS *)(reinterpret_cast<::FUN_006e78b0_shell *>((m_pSolution))->FUN_006e78b0(uiEndIndex)))))->GetIconFormID())));
    return true;
}
}  // namespace fnv_006cec40

struct Elem6cff
{
    char _pad[0x28];
};

struct Array6cff
{
    virtual void FUN_V0();
    virtual Elem6cff* FUN_V1(unsigned int ItemUpdateArray);
    Elem6cff* m_pUserData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void FUN_006d00a0(Elem6cff* pkItems, unsigned int ItemUpdateArray);
    void FUN_006cff60(uintptr_t uiNewSize, bool bFree);
};

// Resizes the array to uiNewSize: frees when zero, grows capacity and constructs new items, or shrinks and optionally reallocates when bFree is set.
// @fnv 0x006cff60
void Array6cff::FUN_006cff60(uintptr_t uiNewSize, bool bFree)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<::NavMeshSearchLOSArray *>(this)->Clear(bFree);
    }
    else if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pUserData = FUN_V1(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_005efa80_cls *>(this)->FUN_005efa80((void *)(uiNewSize), m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        FUN_006d00a0(&m_pUserData[m_uiSize], uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        reinterpret_cast<::S_006ac070 *>(this)->FUN_006ac070((::Elem_006ac070 *)(::Elem6cff *)(&m_pUserData[uiNewSize]), m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bFree && uiNewSize <= m_uiCapacity >> 2)
        {
            reinterpret_cast<::FUN_005efa80_cls *>(this)->FUN_005efa80((void *)(uiNewSize), uiNewSize);
            m_uiCapacity = uiNewSize;
        }
    }
    else
    {
        FUN_006d00a0(&m_pUserData[m_uiSize], uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

namespace TargetTypes {
struct Point3
{
    float x, y, z;
};
struct Location
{
    Location(TESObjectREFR*);
    ~Location();
    unsigned int vtable;
    unsigned int navMesh;
    unsigned int triangle;
    Point3 position;
    unsigned int cell;
    unsigned int world;
    unsigned int flags;
    unsigned int extra;
};
struct Request
{
    Request();
    ~Request();
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
};
}
class TESObjectREFR
{
  public:
    virtual void Slot000();
    virtual void Slot001();
    virtual void Slot002();
    virtual void Slot003();
    virtual void Slot004();
    virtual void Slot005();
    virtual void Slot006();
    virtual void Slot007();
    virtual void Slot008();
    virtual void Slot009();
    virtual void Slot010();
    virtual void Slot011();
    virtual void Slot012();
    virtual void Slot013();
    virtual void Slot014();
    virtual void Slot015();
    virtual void Slot016();
    virtual void Slot017();
    virtual void Slot018();
    virtual void Slot019();
    virtual void Slot020();
    virtual void Slot021();
    virtual void Slot022();
    virtual void Slot023();
    virtual void Slot024();
    virtual void Slot025();
    virtual void Slot026();
    virtual void Slot027();
    virtual void Slot028();
    virtual void Slot029();
    virtual void Slot030();
    virtual void Slot031();
    virtual void Slot032();
    virtual void Slot033();
    virtual void Slot034();
    virtual void Slot035();
    virtual void Slot036();
    virtual void Slot037();
    virtual void Slot038();
    virtual void Slot039();
    virtual void Slot040();
    virtual void Slot041();
    virtual void Slot042();
    virtual void Slot043();
    virtual void Slot044();
    virtual void Slot045();
    virtual void Slot046();
    virtual void Slot047();
    virtual void Slot048();
    virtual void Slot049();
    virtual void Slot050();
    virtual void Slot051();
    virtual void Slot052();
    virtual void Slot053();
    virtual void Slot054();
    virtual void Slot055();
    virtual void Slot056();
    virtual void Slot057();
    virtual void Slot058();
    virtual void Slot059();
    virtual void Slot060();
    virtual void Slot061();
    virtual void Slot062();
    virtual void Slot063();
    virtual void Slot064();
    virtual void Slot065();
    virtual void Slot066();
    virtual void Slot067();
    virtual void Slot068();
    virtual void Slot069();
    virtual void Slot070();
    virtual void Slot071();
    virtual void Slot072();
    virtual void Slot073();
    virtual void Slot074();
    virtual void Slot075();
    virtual void Slot076();
    virtual void Slot077();
    virtual void Slot078();
    virtual void Slot079();
    virtual void Slot080();
    virtual void Slot081();
    virtual void Slot082();
    virtual void Slot083();
    virtual void Slot084();
    virtual void Slot085();
    virtual void Slot086();
    virtual void Slot087();
    virtual void Slot088();
    virtual void Slot089();
    virtual void Slot090();
    virtual void Slot091();
    virtual void Slot092();
    virtual void Slot093();
    virtual void Slot094();
    virtual void Slot095();
    virtual void Slot096();
    virtual void Slot097();
    virtual void Slot098();
    virtual void Slot099();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual TargetTypes::Point3 GetMinimum();
    virtual TargetTypes::Point3 GetMaximum();
};

// Builds a pathing request from two references' bounds and radii plus a margin, sets origin/destination and inner/outer radii, and passes it to FindPathToTarget.
// @fnv 0x006d3780
bool __cdecl BuildPathingRequest(TESObjectREFR* pFirstRef, TESObjectREFR* pSecondRef, float margin, void* output)
{
    TargetTypes::Request request;
    float originRadius;
    float destinationRadius;
    reinterpret_cast<::FUN_006d3ac0_Class *>(&(request))->AssignPathingLocation((const ::PathingLocation &)((const ::TargetTypes::Location &)(TargetTypes::Location(pFirstRef))));
    reinterpret_cast<::PathingRequest *>(&(request))->SetDestination((::PathingLocation *)&(const ::TargetTypes::Location &)(TargetTypes::Location(pSecondRef)));
    {
        TargetTypes::Point3 maximumTmp = pFirstRef->GetMaximum();
        TargetTypes::Point3 minimumB = pFirstRef->GetMinimum();
        float delta = maximumTmp.x - minimumB.x;
        float delta5 = maximumTmp.y - minimumB.y;
        float kRadius = FUN_00404010(delta, delta5);
        kRadius *= reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((pFirstRef))->FUN_00567400();
        kRadius = FUN_00404010(kRadius, 32.0f);
        kRadius *= 0.5;
        originRadius = kRadius;
        reinterpret_cast<::FUN_006d3ae0 *>(&(request))->SetValue(originRadius);
        maximumTmp = pSecondRef->GetMaximum();
        minimumB = pSecondRef->GetMinimum();
        delta = maximumTmp.x - minimumB.x;
        delta5 = maximumTmp.y - minimumB.y;
        kRadius = FUN_00404010(delta, delta5);
        kRadius *= reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((pSecondRef))->FUN_00567400();
        kRadius = FUN_00404010(kRadius, 32.0f);
        kRadius *= 0.5;
        destinationRadius = kRadius;
        reinterpret_cast<::PathingRequest *>(&(request))->SetCenterRadius(destinationRadius);
    }
    reinterpret_cast<::FUN_00507610_Class *>(&(request))->FUN_00507610(originRadius + margin * 0.9f);
    reinterpret_cast<::FUN_006e5ee0_Class *>(&(request))->FUN_006e5ee0(margin + originRadius);
    return ::fnv_006d3b40::FindPathToTarget((::fnv_006d3b40::RequestAccess *)(::TargetTypes::Request *)(&request), (::NiPoint3 *)(output));
}

namespace fnv_006d3b40 {
// Opaque fields retain their observed offsets; all object lifetimes are ordinary C++.
struct MeshTriangle
{
    void* mesh;
    unsigned short triangle;
    NiPoint3 position;
};
struct LocationAccess
{
};
struct MeshAccess
{
    void* FUN_00458b50();
};
struct RequestAccess
{
};
struct FUN_006ac0e0
{
    void* vtable;
    unsigned int unk0004, unk0008, unk000c, unk0010, unk0014;
    unsigned int unk0018, unk001c, unk0020, unk0024, unk0028, unk002c;
    unsigned int unk0030, unk0034, unk0038, unk003c, unk0040, unk0044;
    unsigned int unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    unsigned int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074;
    unsigned int unk0078, unk007c, unk0080, unk0084, unk0088, unk008c;
    unsigned int unk0090, unk0094, unk0098, unk009c, unk00a0, unk00a4;
    unsigned int unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    unsigned int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4;
    unsigned int unk00d8, unk00dc, unk00e0, unk00e4, unk00e8, unk00ec;
    unsigned int unk00f0, unk00f4, unk00f8, unk00fc, unk0100, unk0104;
    unsigned int unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    unsigned int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134;
    unsigned int unk0138, unk013c, unk0140, unk0144, unk0148, unk014c;
    unsigned int unk0150, unk0154, unk0158, unk015c, unk0160, unk0164;
    unsigned int unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    unsigned int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194;
    unsigned int unk0198, unk019c, unk01a0, unk01a4, unk01a8, unk01ac;
    unsigned int unk01b0, unk01b4, unk01b8, unk01bc, unk01c0, unk01c4;
    unsigned int unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    unsigned int unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4;
    unsigned int unk01f8, unk01fc, unk0200, unk0204, unk0208, unk020c;
    unsigned int unk0210, unk0214, unk0218, unk021c, unk0220, unk0224;
    unsigned int unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    unsigned int unk0240, unk0244, unk0248, unk024c, unk0250, unk0254;
    unsigned int unk0258, unk025c, unk0260, unk0264, unk0268, unk026c;
    unsigned int unk0270, unk0274, unk0278, unk027c, unk0280, unk0284;
    unsigned int unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    unsigned int unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4;
    unsigned int unk02b8, unk02bc, unk02c0, unk02c4, unk02c8, unk02cc;
    unsigned int unk02d0, unk02d4, unk02d8, unk02dc, unk02e0, unk02e4;
    unsigned int unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    unsigned int unk0300, unk0304, unk0308, unk030c, unk0310, unk0314;
    unsigned int unk0318, unk031c, unk0320, unk0324, unk0328, unk032c;
    unsigned int unk0330, unk0334, unk0338, unk033c, unk0340, unk0344;
    unsigned int unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    unsigned int unk0360, unk0364, unk0368, unk036c, unk0370, unk0374;
    unsigned int unk0378, unk037c, unk0380, unk0384, unk0388, unk038c;
    unsigned int unk0390, unk0394, unk0398, unk039c, unk03a0, unk03a4;
    unsigned int unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    unsigned int unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4;
    unsigned int unk03d8, unk03dc, unk03e0, unk03e4, unk03e8, unk03ec;
    unsigned int unk03f0, unk03f4, unk03f8, unk03fc, unk0400, unk0404;
    unsigned int unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    unsigned int unk0420, unk0424, unk0428, unk042c, unk0430, unk0434;
    unsigned int unk0438, unk043c, unk0440, unk0444, unk0448, unk044c;
    unsigned int unk0450, unk0454, unk0458, unk045c, unk0460, unk0464;
    unsigned int unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    unsigned int unk0480, unk0484, unk0488, unk048c, unk0490, unk0494;
    unsigned int unk0498, unk049c, unk04a0, unk04a4, unk04a8, unk04ac;
    unsigned int unk04b0, unk04b4, unk04b8, unk04bc, unk04c0, unk04c4;
    unsigned int unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    unsigned int unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4;
    unsigned int unk04f8, unk04fc, unk0500, unk0504, unk0508, unk050c;
    unsigned int unk0510, unk0514, unk0518, unk051c, unk0520, unk0524;
    unsigned int unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    unsigned int unk0540, unk0544, unk0548, unk054c, unk0550, unk0554;
    unsigned int unk0558, unk055c, unk0560, unk0564, unk0568, unk056c;
    unsigned int unk0570, unk0574, unk0578, unk057c, unk0580, unk0584;
    unsigned int unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    unsigned int unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4;
    unsigned int unk05b8, unk05bc, unk05c0, unk05c4, unk05c8, unk05cc;
    unsigned int unk05d0, unk05d4, unk05d8, unk05dc, unk05e0, unk05e4;
    unsigned int unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    unsigned int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614;
    unsigned int unk0618, unk061c, unk0620, unk0624, unk0628, unk062c;
    unsigned int unk0630, unk0634, unk0638, unk063c, unk0640, unk0644;
    unsigned int unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    unsigned int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674;
    unsigned int unk0678, unk067c, unk0680, unk0684, unk0688, unk068c;
    unsigned int unk0690, unk0694, unk0698, unk069c, unk06a0, unk06a4;
    unsigned int unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    unsigned int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4;
    unsigned int unk06d8, unk06dc, unk06e0, unk06e4, unk06e8, unk06ec;
    unsigned int unk06f0, unk06f4, unk06f8, unk06fc, unk0700, unk0704;
    unsigned int unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    unsigned int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734;
    unsigned int unk0738, unk073c, unk0740, unk0744, unk0748, unk074c;
    unsigned int unk0750, unk0754, unk0758, unk075c, unk0760, unk0764;
    unsigned int unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    unsigned int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794;
    unsigned int unk0798, unk079c, unk07a0, unk07a4, unk07a8, unk07ac;
    unsigned int unk07b0, unk07b4, unk07b8, unk07bc, unk07c0, unk07c4;
    unsigned int unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    unsigned int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4;
    unsigned int unk07f8, unk07fc, unk0800, unk0804, unk0808, unk080c;
    unsigned int unk0810, unk0814, unk0818, unk081c, unk0820, unk0824;
    unsigned int unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    unsigned int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854;
    unsigned int unk0858, unk085c, unk0860, unk0864, unk0868, unk086c;
    unsigned int unk0870, unk0874, unk0878, unk087c, unk0880, unk0884;
    unsigned int unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    unsigned int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4;
    unsigned int unk08b8, unk08bc, unk08c0, unk08c4, unk08c8, unk08cc;
    unsigned int unk08d0, unk08d4, unk08d8, unk08dc, unk08e0, unk08e4;
    unsigned int unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    unsigned int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914;
    unsigned int unk0918, unk091c, unk0920, unk0924, unk0928, unk092c;
    unsigned int unk0930, unk0934, unk0938, unk093c, unk0940, unk0944;
    unsigned int unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    unsigned int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974;
    unsigned int unk0978, unk097c, unk0980, unk0984, unk0988, unk098c;
    unsigned int unk0990, unk0994, unk0998, unk099c, unk09a0, unk09a4;
    unsigned int unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    unsigned int unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4;
    unsigned int unk09d8, unk09dc, unk09e0, unk09e4, unk09e8, unk09ec;
    unsigned int unk09f0, unk09f4, unk09f8, unk09fc, unk0a00, unk0a04;
    unsigned int unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    unsigned int unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34;
    unsigned int unk0a38, unk0a3c, unk0a40, unk0a44, unk0a48, unk0a4c;
    unsigned int unk0a50, unk0a54, unk0a58, unk0a5c, unk0a60, unk0a64;
    unsigned int unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    unsigned int unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94;
    unsigned int unk0a98, unk0a9c, unk0aa0, unk0aa4, unk0aa8, unk0aac;
    unsigned int unk0ab0, unk0ab4, unk0ab8, unk0abc, unk0ac0, unk0ac4;
    unsigned int unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc;
    unsigned int unk0ae0, unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4;
    unsigned int unk0af8, unk0afc, unk0b00, unk0b04, unk0b08, unk0b0c;
    unsigned int unk0b10, unk0b14, unk0b18, unk0b1c, unk0b20, unk0b24;
    unsigned int unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c;
    unsigned int unk0b40, unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54;
    unsigned int unk0b58, unk0b5c, unk0b60, unk0b64, unk0b68, unk0b6c;
    unsigned int unk0b70, unk0b74, unk0b78, unk0b7c, unk0b80, unk0b84;
    unsigned int unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c;
    unsigned int unk0ba0, unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4;
    unsigned int unk0bb8, unk0bbc, unk0bc0, unk0bc4, unk0bc8, unk0bcc;
    unsigned int unk0bd0, unk0bd4, unk0bd8, unk0bdc, unk0be0, unk0be4;
    unsigned int unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    unsigned int unk0c00, unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14;
    unsigned int unk0c18, unk0c1c, unk0c20, unk0c24, unk0c28, unk0c2c;
    unsigned int unk0c30, unk0c34, unk0c38, unk0c3c, unk0c40, unk0c44;
    unsigned int unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c;
    unsigned int unk0c60, unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74;
    unsigned int unk0c78, unk0c7c, unk0c80, unk0c84, unk0c88, unk0c8c;
    unsigned int unk0c90, unk0c94, unk0c98, unk0c9c, unk0ca0, unk0ca4;
    unsigned int unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    unsigned int unk0cc0, unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4;
    unsigned int unk0cd8, unk0cdc, unk0ce0, unk0ce4, unk0ce8, unk0cec;
    unsigned int unk0cf0, unk0cf4, unk0cf8, unk0cfc, unk0d00, unk0d04;
    unsigned int unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c;
    unsigned int unk0d20, unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34;
    unsigned int unk0d38, unk0d3c, unk0d40, unk0d44, unk0d48, unk0d4c;
    unsigned int unk0d50, unk0d54, unk0d58, unk0d5c, unk0d60, unk0d64;
    unsigned int unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c;
    unsigned int unk0d80, unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94;
    unsigned int unk0d98, unk0d9c, unk0da0, unk0da4, unk0da8, unk0dac;
    unsigned int unk0db0, unk0db4, unk0db8, unk0dbc, unk0dc0, unk0dc4;
    unsigned int unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    unsigned int unk0de0, unk0de4, unk0de8, unk0dec, unk0df0, unk0df4;
    unsigned int unk0df8, unk0dfc, unk0e00, unk0e04, unk0e08, unk0e0c;
    unsigned int unk0e10, unk0e14, unk0e18, unk0e1c, unk0e20, unk0e24;
    unsigned int unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c;
    unsigned int unk0e40, unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54;
    unsigned int unk0e58, unk0e5c, unk0e60, unk0e64, unk0e68, unk0e6c;
    unsigned int unk0e70, unk0e74, unk0e78, unk0e7c, unk0e80, unk0e84;
    unsigned int unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c;
    unsigned int unk0ea0, unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4;
    unsigned int unk0eb8, unk0ebc, unk0ec0, unk0ec4, unk0ec8, unk0ecc;
    unsigned int unk0ed0, unk0ed4, unk0ed8, unk0edc, unk0ee0, unk0ee4;
    unsigned int unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc;
    unsigned int unk0f00, unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14;
    unsigned int unk0f18, unk0f1c, unk0f20, unk0f24, unk0f28, unk0f2c;
    unsigned int unk0f30, unk0f34, unk0f38, unk0f3c, unk0f40, unk0f44;
    unsigned int unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c;
    unsigned int unk0f60, unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74;
    unsigned int unk0f78, unk0f7c, unk0f80, unk0f84, unk0f88, unk0f8c;
    unsigned int unk0f90, unk0f94, unk0f98, unk0f9c, unk0fa0, unk0fa4;
    unsigned int unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    unsigned int unk0fc0, unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4;
    unsigned int unk0fd8, unk0fdc, unk0fe0, unk0fe4, unk0fe8, unk0fec;
    unsigned int unk0ff0, unk0ff4, unk0ff8, unk0ffc, unk1000, unk1004;
    unsigned int unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    unsigned int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034;
    unsigned int unk1038, unk103c, unk1040, unk1044, unk1048, unk104c;
    unsigned int unk1050, unk1054, unk1058, unk105c, unk1060, unk1064;
    unsigned int unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    unsigned int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094;
    unsigned int unk1098, unk109c, unk10a0, unk10a4, unk10a8, unk10ac;
    unsigned int unk10b0, unk10b4, unk10b8, unk10bc, unk10c0, unk10c4;
    unsigned int unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    unsigned int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4;
    unsigned int unk10f8, unk10fc, unk1100, unk1104, unk1108, unk110c;
    unsigned int unk1110, unk1114, unk1118, unk111c, unk1120, unk1124;
    unsigned int unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    unsigned int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154;
    unsigned int unk1158, unk115c, unk1160, unk1164, unk1168, unk116c;
    unsigned int unk1170, unk1174, unk1178, unk117c, unk1180, unk1184;
    unsigned int unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    unsigned int unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4;
    unsigned int unk11b8, unk11bc, unk11c0, unk11c4, unk11c8, unk11cc;
    unsigned int unk11d0, unk11d4, unk11d8, unk11dc, unk11e0, unk11e4;
    unsigned int unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    unsigned int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214;
    unsigned int unk1218, unk121c, unk1220, unk1224, unk1228, unk122c;
    unsigned int unk1230, unk1234, unk1238, unk123c, unk1240, unk1244;
    unsigned int unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    unsigned int unk1260, unk1264, unk1268, unk126c, unk1270, unk1274;
    unsigned int unk1278, unk127c, unk1280, unk1284, unk1288, unk128c;
    unsigned int unk1290, unk1294, unk1298, unk129c, unk12a0, unk12a4;
    unsigned int unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    unsigned int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4;
    unsigned int unk12d8, unk12dc, unk12e0, unk12e4, unk12e8, unk12ec;
    unsigned int unk12f0, unk12f4, unk12f8, unk12fc, unk1300, unk1304;
    unsigned int unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    unsigned int unk1320, unk1324, unk1328, unk132c, unk1330, unk1334;
    unsigned int unk1338, unk133c, unk1340, unk1344, unk1348, unk134c;
    unsigned int unk1350, unk1354, unk1358, unk135c, unk1360, unk1364;
    unsigned int unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    unsigned int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394;
    unsigned int unk1398, unk139c, unk13a0, unk13a4, unk13a8, unk13ac;
    unsigned int unk13b0, unk13b4, unk13b8, unk13bc, unk13c0, unk13c4;
    unsigned int unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    unsigned int unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4;
    unsigned int unk13f8, unk13fc, unk1400, unk1404, unk1408, unk140c;
    unsigned int unk1410, unk1414, unk1418, unk141c, unk1420, unk1424;
    unsigned int unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    unsigned int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454;
    unsigned int unk1458, unk145c, unk1460, unk1464, unk1468, unk146c;
    unsigned int unk1470, unk1474, unk1478, unk147c, unk1480, unk1484;
    unsigned int unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    unsigned int unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4;
    unsigned int unk14b8, unk14bc, unk14c0, unk14c4, unk14c8, unk14cc;
    unsigned int unk14d0, unk14d4, unk14d8, unk14dc, unk14e0, unk14e4;
    unsigned int unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    unsigned int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514;
    unsigned int unk1518, unk151c, unk1520, unk1524, unk1528, unk152c;
    unsigned int unk1530, unk1534, unk1538, unk153c, unk1540, unk1544;
    unsigned int unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    unsigned int unk1560, unk1564, unk1568, unk156c, unk1570, unk1574;
    unsigned int unk1578, unk157c, unk1580, unk1584, unk1588, unk158c;
    unsigned int unk1590, unk1594, unk1598, unk159c, unk15a0, unk15a4;
    unsigned int unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    unsigned int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4;
    unsigned int unk15d8, unk15dc, unk15e0, unk15e4, unk15e8, unk15ec;
    unsigned int unk15f0, unk15f4, unk15f8, unk15fc, unk1600, unk1604;
    unsigned int unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    unsigned int unk1620, unk1624, unk1628, unk162c, unk1630, unk1634;
    unsigned int unk1638, unk163c, unk1640, unk1644, unk1648, unk164c;
    unsigned int unk1650, unk1654, unk1658, unk165c, unk1660, unk1664;
    unsigned int unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    unsigned int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694;
    unsigned int unk1698, unk169c, unk16a0, unk16a4, unk16a8, unk16ac;
    unsigned int unk16b0, unk16b4, unk16b8, unk16bc, unk16c0, unk16c4;
    unsigned int unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc;
    unsigned int unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4;
    unsigned int unk16f8, unk16fc, unk1700, unk1704, unk1708, unk170c;
    unsigned int unk1710, unk1714, unk1718, unk171c, unk1720, unk1724;
    unsigned int unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    unsigned int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754;
    unsigned int unk1758, unk175c, unk1760, unk1764, unk1768, unk176c;
    unsigned int unk1770, unk1774, unk1778, unk177c, unk1780, unk1784;
    unsigned int unk1788, unk178c, unk1790, unk1794, unk1798, unk179c;
    unsigned int unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4;
    unsigned int unk17b8, unk17bc, unk17c0, unk17c4, unk17c8, unk17cc;
    unsigned int unk17d0, unk17d4, unk17d8, unk17dc, unk17e0, unk17e4;
    unsigned int unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    unsigned int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814;
    unsigned int unk1818, unk181c, unk1820, unk1824, unk1828, unk182c;
    unsigned int unk1830, unk1834, unk1838, unk183c, unk1840, unk1844;
    unsigned int unk1848, unk184c, unk1850, unk1854, unk1858, unk185c;
    unsigned int unk1860, unk1864, unk1868, unk186c, unk1870, unk1874;
    unsigned int unk1878, unk187c, unk1880, unk1884, unk1888, unk188c;
    unsigned int unk1890, unk1894, unk1898, unk189c, unk18a0, unk18a4;
    unsigned int unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    unsigned int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4;
    unsigned int unk18d8, unk18dc, unk18e0, unk18e4, unk18e8, unk18ec;
    unsigned int unk18f0, unk18f4, unk18f8, unk18fc, unk1900, unk1904;
    unsigned int unk1908, unk190c, unk1910, unk1914, unk1918, unk191c;
    unsigned int unk1920, unk1924, unk1928, unk192c, unk1930, unk1934;
    unsigned int unk1938, unk193c, unk1940, unk1944, unk1948, unk194c;
    unsigned int unk1950, unk1954, unk1958, unk195c, unk1960, unk1964;
    unsigned int unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    unsigned int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994;
    unsigned int unk1998, unk199c, unk19a0, unk19a4, unk19a8, unk19ac;
    unsigned int unk19b0, unk19b4, unk19b8, unk19bc, unk19c0, unk19c4;
    unsigned int unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc;
    unsigned int unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4;
    unsigned int unk19f8, unk19fc, unk1a00, unk1a04, unk1a08, unk1a0c;
    unsigned int unk1a10, unk1a14, unk1a18, unk1a1c, unk1a20, unk1a24;
    unsigned int unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    unsigned int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54;
    unsigned int unk1a58, unk1a5c, unk1a60, unk1a64, unk1a68, unk1a6c;
    unsigned int unk1a70, unk1a74, unk1a78, unk1a7c, unk1a80, unk1a84;
    unsigned int unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c;
    unsigned int unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4;
    unsigned int unk1ab8, unk1abc, unk1ac0, unk1ac4, unk1ac8, unk1acc;
    unsigned int unk1ad0, unk1ad4, unk1ad8, unk1adc, unk1ae0, unk1ae4;
    unsigned int unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    unsigned int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14;
    unsigned int unk1b18, unk1b1c, unk1b20, unk1b24, unk1b28, unk1b2c;
    unsigned int unk1b30, unk1b34, unk1b38, unk1b3c, unk1b40, unk1b44;
    unsigned int unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c;
    unsigned int unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74;
    unsigned int unk1b78, unk1b7c, unk1b80, unk1b84, unk1b88, unk1b8c;
    unsigned int unk1b90, unk1b94, unk1b98, unk1b9c, unk1ba0, unk1ba4;
    unsigned int unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    unsigned int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4;
    unsigned int unk1bd8, unk1bdc, unk1be0, unk1be4, unk1be8, unk1bec;
    unsigned int unk1bf0, unk1bf4, unk1bf8, unk1bfc, unk1c00, unk1c04;
    unsigned int unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c;
    unsigned int unk1c20, unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34;
    unsigned int unk1c38, unk1c3c, unk1c40, unk1c44, unk1c48, unk1c4c;
    unsigned int unk1c50, unk1c54, unk1c58, unk1c5c, unk1c60, unk1c64;
    unsigned int unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c;
    unsigned int unk1c80, unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94;
    unsigned int unk1c98, unk1c9c, unk1ca0, unk1ca4, unk1ca8, unk1cac;
    unsigned int unk1cb0, unk1cb4, unk1cb8, unk1cbc, unk1cc0, unk1cc4;
    unsigned int unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc;
    unsigned int unk1ce0, unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4;
    unsigned int unk1cf8, unk1cfc, unk1d00, unk1d04, unk1d08, unk1d0c;
    unsigned int unk1d10, unk1d14, unk1d18, unk1d1c, unk1d20, unk1d24;
    unsigned int unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c;
    unsigned int unk1d40, unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54;
    unsigned int unk1d58, unk1d5c, unk1d60, unk1d64, unk1d68, unk1d6c;
    unsigned int unk1d70, unk1d74, unk1d78, unk1d7c, unk1d80, unk1d84;
    unsigned int unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c;
    unsigned int unk1da0, unk1da4, unk1da8, unk1dac, unk1db0, unk1db4;
    unsigned int unk1db8, unk1dbc, unk1dc0, unk1dc4, unk1dc8, unk1dcc;
    unsigned int unk1dd0, unk1dd4, unk1dd8, unk1ddc, unk1de0, unk1de4;
    unsigned int unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc;
    unsigned int unk1e00, unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14;
    unsigned int unk1e18, unk1e1c, unk1e20, unk1e24, unk1e28, unk1e2c;
    unsigned int unk1e30, unk1e34, unk1e38, unk1e3c, unk1e40, unk1e44;
    unsigned int unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c;
    unsigned int unk1e60, unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74;
    unsigned int unk1e78, unk1e7c, unk1e80, unk1e84, unk1e88, unk1e8c;
    unsigned int unk1e90, unk1e94, unk1e98, unk1e9c, unk1ea0, unk1ea4;
    unsigned int unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    unsigned int unk1ec0, unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4;
    unsigned int unk1ed8, unk1edc, unk1ee0, unk1ee4, unk1ee8, unk1eec;
    unsigned int unk1ef0, unk1ef4, unk1ef8, unk1efc, unk1f00, unk1f04;
    unsigned int unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c;
    unsigned int unk1f20, unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34;
    unsigned int unk1f38, unk1f3c, unk1f40, unk1f44, unk1f48, unk1f4c;
    unsigned int unk1f50, unk1f54, unk1f58, unk1f5c, unk1f60, unk1f64;
    unsigned int unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c;
    unsigned int unk1f80, unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94;
    unsigned int unk1f98, unk1f9c, unk1fa0, unk1fa4, unk1fa8, unk1fac;
    unsigned int unk1fb0, unk1fb4, unk1fb8, unk1fbc, unk1fc0, unk1fc4;
    unsigned int unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc;
    unsigned int unk1fe0, unk1fe4, unk1fe8, unk1fec, unk1ff0, unk1ff4;
    unsigned int unk1ff8, unk1ffc, unk2000, unk2004, unk2008, unk200c;
    unsigned int unk2010, unk2014, unk2018, unk201c, unk2020, unk2024;
    unsigned int unk2028, unk202c, unk2030, unk2034, unk2038, unk203c;
    unsigned int unk2040, unk2044, unk2048, unk204c, unk2050, unk2054;
    unsigned int unk2058, unk205c, unk2060, unk2064, unk2068, unk206c;
    unsigned int unk2070, unk2074, unk2078, unk207c, unk2080, unk2084;
    unsigned int unk2088, unk208c, unk2090, unk2094, unk2098, unk209c;
    unsigned int unk20a0, unk20a4, unk20a8, unk20ac, unk20b0, unk20b4;
    unsigned int unk20b8, unk20bc, unk20c0, unk20c4, unk20c8, unk20cc;
    unsigned int unk20d0, unk20d4, unk20d8, unk20dc, unk20e0, unk20e4;
    unsigned int unk20e8, unk20ec, unk20f0, unk20f4, unk20f8, unk20fc;
    unsigned int unk2100;
    FUN_006ac0e0();
    ~FUN_006ac0e0();
};
struct PathBuilderDetailedPathMeshes
{
    void* vtable;
    NavMeshPtr* data;
    unsigned int size;
    unsigned int capacity;
    PathBuilderDetailedPathMeshes();
    ~PathBuilderDetailedPathMeshes();
};
struct PathingRequestHelper
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned int unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74;
    unsigned int unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c, unka0, unka4;
    unsigned int unka8, unkac;
    PathingRequestHelper();
    ~PathingRequestHelper();
};
struct PathingSolution
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40;
    PathingSolution();
    ~PathingSolution();
};
struct PathingRequestClosePoint
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned int unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74;
    unsigned int unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c, unka0, unka4;
    unsigned int unka8, unkac, unkb0, unkb4;
    PathingRequestClosePoint();
    ~PathingRequestClosePoint();
};
bool FUN_006d91d0(PathBuilderDetailedPathMeshes*);

// Checks both request endpoints' nav meshes, builds a search between their triangles, and writes a path point to output, falling back to a close-point path.
// @fnv 0x006d3b40
bool __cdecl FindPathToTarget(RequestAccess* request, NiPoint3* output)
{
    if (!reinterpret_cast<::NLLocation *>((((::fnv_006d3b40::LocationAccess *)(::GetOffsetC((intptr_t)(request))))))->UpdateMeshLocation())
        return false;
    NavMeshPtr mesh_;
    unsigned short aLocation = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((((::fnv_006d3b40::LocationAccess *)(::GetOffsetC((intptr_t)(request))))))->FindNavMeshTriangle(mesh_, aLocation))
        return false;
    MeshTriangle origin_;
    origin_.mesh = reinterpret_cast<MeshAccess*>(&mesh_)->FUN_00458b50();
    origin_.triangle = aLocation;
    if (!reinterpret_cast<::NLLocation *>((((::fnv_006d3b40::LocationAccess *)(::FUN_006a9540((char *)(request))))))->UpdateMeshLocation())
        return false;
    NavMeshPtr meshX;
    unsigned short aType = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((((::fnv_006d3b40::LocationAccess *)(::FUN_006a9540((char *)(request))))))->FindNavMeshTriangle(meshX, aType))
        return false;
    MeshTriangle target3;
    target3.mesh = reinterpret_cast<MeshAccess*>(&meshX)->FUN_00458b50();
    target3.triangle = aType;
    FUN_006ac0e0 _search;
    PathBuilderDetailedPathMeshes kList;
    FUN_006d91d0(&kList);
    if (!reinterpret_cast<::FUN_006ac220_shell *>(&(_search))->SearchPath((::PathingRequestS *)(request), (*(const ::NavMeshTriangleReference *)(&origin_)), (*(const ::NavMeshTriangleReference *)(&target3))))
    {
        PathingRequestHelper aOrigin;
        reinterpret_cast<::PathingRequest *>((request))->CopyTo((::PathingRequest *)(void *)(&aOrigin));
        PathingSolution aMatrix;
        if (::FUN_006d0b10((::PathingRequest *)(::fnv_006d3b40::PathingRequestHelper *)(&aOrigin), (::PathingSolution *)(::fnv_006d3b40::PathingSolution *)(&aMatrix)))
        {
            float aNode;
            if (reinterpret_cast<::fnv_006e7e70::FUN_006e7e70_shell *>(&(aMatrix))->FUN_006e7e70(float(::GetObjectFlags((char *)&(aMatrix)) - 1), reinterpret_cast<::FUN_006d2c20_Class *>((void *)(request))->GetFloatAtOffsetB0(), 0, &aNode,
                                     output))
            {
                return true;
            }
            else
            {
                PathingRequestClosePoint aSub;
                reinterpret_cast<::PathingRequest *>((request))->CopyTo((::PathingRequest *)(void *)(&aSub));
                reinterpret_cast<::FUN_006d3ac0_Class *>(&(aSub))->AssignPathingLocation((*(const ::PathingLocation *)(((::fnv_006d3b40::LocationAccess *)(::FUN_006a9540((char *)(request)))))));
                reinterpret_cast<::FUN_00507610_Class *>(&(aSub))->FUN_00507610(reinterpret_cast<::FUN_006d2c20_Class *>((void *)(request))->GetFloatAtOffsetB0());
                reinterpret_cast<::FUN_006e5ee0_Class *>(&(aSub))->FUN_006e5ee0(::GetFieldB4Float((char *)(request)));
                if (::FUN_006d34d0(&aSub, output))
                    return true;
            }
        }
        return false;
    }
    reinterpret_cast<::S_006d3ff0 *>(&(_search))->FUN_006d3ff0(*output);
    return true;
}
}  // namespace fnv_006d3b40

struct Mesh;
struct Point : NiPoint3
{
    Point();
    Point operator-(const Point&) const;
};
struct Triangle
{
};
struct MeshEdgeRecord
{
    Mesh* mesh;
    unsigned short triangle;
    int edge;
    MeshEdgeRecord();
    MeshEdgeRecord(Mesh*, unsigned short, int);
    MeshEdgeRecord* FUN_0069a6c0(Mesh*, unsigned short, int);
    MeshEdgeRecord& operator=(const MeshEdgeRecord&);
};
struct MeshTriangle
{
    Mesh* mesh;
    unsigned short triangle;
    MeshTriangle(Mesh*, unsigned short);
};
struct TriangleHandle : MeshTriangle
{
    bool enabled[3];
    TriangleHandle();
    TriangleHandle* FUN_0069a690(const MeshTriangle*);
};
struct Mesh
{
};
struct MeshPointer
{
    Mesh* object;
    MeshPointer();
    ~MeshPointer();
    Mesh* FUN_00458b50();
};
struct MeshEdgeArray
{
    void* vtable;
    MeshEdgeRecord* data;
    unsigned int size, capacity;
    MeshEdgeArray();
    ~MeshEdgeArray();
    MeshEdgeRecord* FUN_006a1440(unsigned int);
};
struct InitialEdgeList
{
    void* vtable;
    MeshEdgeRecord* data;
    unsigned int size, capacity;
    InitialEdgeList();
    ~InitialEdgeList();
};
struct TriangleList
{
    void* vtable;
    TriangleHandle* data;
    unsigned int size, capacity;
    TriangleList();
    ~TriangleList();
    TriangleHandle* FUN_006a1440(unsigned int);
};
struct CopyTriangle : TriangleHandle
{
    CopyTriangle(const TriangleHandle&);
};
struct LocationView
{
    NavMeshInfo* meshInfo;
    unsigned short triangle;
    int edge;
    Point position;
};
Point GetClosestPointOnSegment(const Point&, const Point&, const Point&);

// @fnv 0x006d4570
bool __cdecl FUN_006d4570(LocationView* location, float radius, LocationView* result)
{
    reinterpret_cast<::PathingLocationProxy *>((location))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
    if (!reinterpret_cast<::PathingLocation *>((location))->HasValidTriangle_006dd6a0())
    {
        InitialEdgeList initialEdges;
        ::CollectNearbyEdges((::PathActor *)(location), 1, (::EdgeHandleList *)(::InitialEdgeList *)(&initialEdges));
        if (!reinterpret_cast<::FUN_0076b610_Class *>(&(initialEdges))->FUN_0076b610())
        {
            reinterpret_cast<::FUN_006cf900_Class *>((result))->FUN_006cf900((const ::FUN_006cf900_Class *)(::MeshEdgeRecord *)(((::MeshEdgeRecord *)(reinterpret_cast<::FUN_006cee10_shell *>(&(initialEdges))->FUN_006cee10(0)))));
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        MeshEdgeArray a;
        TriangleList p;
        MeshPointer i;
        unsigned short f;
        if (!reinterpret_cast<::PathingLocation *>((location))->FindNavMeshTriangle((*(::NavMeshPtr *)(&i)), (*(unsigned short *)(&f))))
            return false;
        TriangleHandle h;
        MeshTriangle kTriangle(i.FUN_00458b50(), f);
        h.FUN_0069a690(&kTriangle);
        for (int edge = 0; edge < 3; ++edge)
        {
            Point q;
            Point b;
            reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((((::Mesh *)(::FUN_00559450((int *)&(i))))))->FUN_0068f0c0(f, edge, (::NiPoint3 *)&(q), (::NiPoint3 *)&(b));
            h.enabled[edge] = ::DistanceToSegment((::V006b9b10 *)&(const ::Point &)((*(::Point *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (::V006b9b10 *)&(q), (::V006b9b10 *)&(b), (unsigned char *)(float *)(0)) < radius;
        }
        reinterpret_cast<::FUN_006db4f0_Class *>(&(p))->FUN_006db4f0((intptr_t)(&h));
        bool s = false;
        for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(p))->GetName())); ++i)
        {
            CopyTriangle current(*p.FUN_006a1440(i));
            for (int edge = 0; edge < 3; ++edge)
            {
                if (current.enabled[edge])
                {
                    Triangle* j = ((::Triangle *)(reinterpret_cast<::NavMesh *>((current.mesh))->GetTriangle(current.triangle)));
                    MeshEdgeRecord eb(current.mesh, current.triangle, edge);
                    if (reinterpret_cast<::FUN_0068f2c0_shell *>((j))->FUN_0068f2c0(edge) == 0xffff)
                    {
                        reinterpret_cast<::FUN_0069b310_S *>(&(a))->AppendElement((const ::EH *)(const ::MeshEdgeRecord *)(&eb));
                    }
                    else
                    {
                        TriangleHandle neighbor;
                        if (reinterpret_cast<::Holder670 *>((current.mesh))->MatchNavMesh((::In670 *)(::MeshEdgeRecord *)(&eb), (::Out670 *)(::TriangleHandle *)(&neighbor)))
                        {
                            bool found = false;
                            for (unsigned int j = 0; j < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(p))->GetName())); ++j)
                            {
                                if (((FUN_006d4ca0_Class*)p.FUN_006a1440(j))->Equals((FUN_006d4ca0_Class*)&neighbor))
                                {
                                    found = true;
                                    break;
                                }
                            }
                            if (!found)
                            {
                                TriangleHandle next;
                                next.FUN_0069a690(&neighbor);
                                for (int side = 0; side < 3; ++side)
                                {
                                    Point q;
                                    Point b;
                                    reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((neighbor.mesh))->FUN_0068f0c0(neighbor.triangle, side, (::NiPoint3 *)&(q), (::NiPoint3 *)&(b));
                                    next.enabled[side] = ::DistanceToSegment((::V006b9b10 *)&(const ::Point &)((*(::Point *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (::V006b9b10 *)&(q), (::V006b9b10 *)&(b), (unsigned char *)(float *)(0)) < radius;
                                }
                                reinterpret_cast<::FUN_006db4f0_Class *>(&(p))->FUN_006db4f0((intptr_t)(&next));
                            }
                        }
                    }
                }
            }
        }
        if (!reinterpret_cast<::FUN_0076b610_Class *>(&(a))->FUN_0076b610())
        {
            MeshEdgeRecord eb;
            Point h;
            float p = 3.402823466e+38F;
            for (unsigned int j = 0; j < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(a))->GetName())); ++j)
            {
                Point i;
                Point cf;
                reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((a.FUN_006a1440(j)->mesh))->FUN_0068f0c0(a.FUN_006a1440(j)->triangle, a.FUN_006a1440(j)->edge, (::NiPoint3 *)&(i), (::NiPoint3 *)&(cf));
                Point f = GetClosestPointOnSegment((*(::Point *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), i, cf);
                float s = reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::Point &)((f - (*(::Point *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))))))->UpdateCombatStyle();
                if (s < p)
                {
                    p = s;
                    h = f;
                    reinterpret_cast<::FUN_006bc870_shell *>(&(eb))->CopyFromNavMeshEdge((void *)&(*a.FUN_006a1440(j)));
                }
            }
            result->meshInfo = reinterpret_cast<::FUN_0068efb0_shell *>((eb.mesh))->FUN_0068efb0();
            result->triangle = eb.triangle;
            result->edge = eb.edge;
            result->position = h;
            return true;
        }
        else
        {
            return false;
        }
    }
}

struct Elem6daf
{
    char _pad[0x54];
};

struct Array6daf
{
    virtual void FUN_V0();
    virtual Elem6daf* FUN_V1(unsigned int ItemUpdateArray);
    Elem6daf* m_pUserData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    bool FUN_00438b90();
    void ConstructInPlace(Elem6daf* pkItems, unsigned int ItemUpdateArray);
    void FUN_006daf20(unsigned int uiIndex, const Elem6daf& rkItem);
};

// Inserts rkItem at uiIndex, growing the array if needed and shifting existing elements to make room.
// @fnv 0x006daf20
void Array6daf::FUN_006daf20(unsigned int uiIndex, const Elem6daf& rkItem)
{
    if (uiIndex == m_uiSize)
    {
        reinterpret_cast<::FUN_006dbd90_Class *>(this)->AllocateSlot((void *)&(rkItem));
        return;
    }
    if (FUN_00438b90())
    {
        unsigned int uiNewCapacity = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>(this)->FUN_009a3910()));
        Elem6daf* pkNewData = FUN_V1(uiNewCapacity);
        reinterpret_cast<::FUN_006dbf20_Class *>(this)->FUN_006dbf20((char *)(pkNewData), (char *)(m_pUserData), uiIndex);
        ConstructInPlace(&pkNewData[uiIndex], 1);
        reinterpret_cast<::FUN_006dbf20_Class *>(this)->FUN_006dbf20((char *)(::Elem6daf *)(pkNewData + uiIndex + 1), (char *)(::Elem6daf *)(&m_pUserData[uiIndex]), m_uiSize - uiIndex);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        m_pUserData = pkNewData;
        m_uiCapacity = uiNewCapacity;
    }
    else
    {
        reinterpret_cast<::FUN_006dbf20_Class *>(this)->FUN_006dbf20((char *)(::Elem6daf *)(m_pUserData + uiIndex + 1), (char *)(::Elem6daf *)(&m_pUserData[uiIndex]), m_uiSize - uiIndex);
        ConstructInPlace(&m_pUserData[uiIndex], 1);
    }
    m_uiSize++;
    reinterpret_cast<::FUN_006e4430_class *>(&(m_pUserData[uiIndex]))->operator=((const ::FUN_006e4430_class &)(rkItem));
}

struct FUN_006db450_Element
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};
struct FUN_006db450_Owner
{
    unsigned int unk00;
    FUN_006db450_Element* elements;
    void FUN_006d05e0(FUN_006db450_Element* element, bool enabled);
    int FUN_006db450(void* argument);
};
// Gets the next element index, enables that element, passes argument to its FUN_006cf900, and returns the index.
// @fnv 0x006db450
int FUN_006db450_Owner::FUN_006db450(void* argument)
{
    int index = ((int)(reinterpret_cast<::FUN_006dc260_Class *>(this)->GetNextIndex()));
    reinterpret_cast<::Array6d0 *>(this)->FUN_006d05e0((struct ::FUN_006a0480 *)(::FUN_006db450_Element *)(&elements[index]), true);
    reinterpret_cast<::FUN_006cf900_Class *>(&(elements[index]))->FUN_006cf900((const ::FUN_006cf900_Class *)(argument));
    return index;
}

struct FloatArray6db5
{
    virtual void FUN_V0();
    virtual float* FUN_V1(unsigned int ItemUpdateArray);
    float* m_pfData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    unsigned int AppendFloat(const float& rkItem);
    bool FUN_00438b90();
    void FUN_006db540(unsigned int uiIndex, const float& rkItem);
};

// Inserts rkItem at uiIndex, growing the buffer if needed and shifting existing elements right.
// @fnv 0x006db540
void FloatArray6db5::FUN_006db540(unsigned int uiIndex, const float& rkItem)
{
    if (uiIndex == m_uiSize)
    {
        AppendFloat(rkItem);
        return;
    }
    if (FUN_00438b90())
    {
        unsigned int uiNewCapacity = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>(this)->FUN_009a3910()));
        float* pfNewData = FUN_V1(uiNewCapacity);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(pfNewData), (char *)(m_pfData), uiIndex);
        reinterpret_cast<::fnv_006f2290::CtorHelper *>(this)->InitializeItems((::fnv_006f2290::NavMeshInfo **)(float *)(&pfNewData[uiIndex]), 1);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(void *)(&pfNewData[uiIndex + 1]), (char *)(void *)(&m_pfData[uiIndex]), m_uiSize - uiIndex);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        m_pfData = pfNewData;
        m_uiCapacity = uiNewCapacity;
    }
    else
    {
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(void *)(&m_pfData[uiIndex + 1]), (char *)(void *)(&m_pfData[uiIndex]), m_uiSize - uiIndex);
        reinterpret_cast<::fnv_006f2290::CtorHelper *>(this)->InitializeItems((::fnv_006f2290::NavMeshInfo **)(float *)(&m_pfData[uiIndex]), 1);
    }
    m_uiSize++;
    m_pfData[uiIndex] = rkItem;
}

extern int DAT_0106cc78;
struct FUN_00aa42e0_Obj
{
};
struct FUN_006dc370
{
    void* m_vtbl;
    FUN_006dc370();
    ~FUN_006dc370();
};
struct FUN_006db890 : FUN_006dc370
{
    int unk04;
    int unk08;
    int unk0c;
    intptr_t m_uiFilterValue;
    FUN_006db890(int arg8, int argC, intptr_t arg10);
};
// @fnv 0x006db890
FUN_006db890::FUN_006db890(int aiFirst, int aiSecond, intptr_t aiValue)
{
    m_vtbl = &DAT_0106cc78;
    m_uiFilterValue = aiValue ? aiValue : ((intptr_t)(reinterpret_cast<::MemoryManager *>((((FUN_00aa42e0_Obj*)((void *)(::FUN_00401020())))))->GetGeneralAllocator()));
    reinterpret_cast<::FUN_006dc440_Class *>(this)->FUN_006dc440(aiFirst, aiSecond);
}

struct S0069a690
{
    int unk00;
    int unk04;
    S0069a690* FUN_0069a690(S0069a690 const* other);
};
struct FUN_0069b030_S
{
};
struct FUN_006dc3a0_Obj
{
};
struct FUN_006dba30_Class
{
    int unk00;
    S0069a690* m_items;
    unsigned int FUN_006dba30(S0069a690 const* other);
};

struct FUN_006d5320
{
    FUN_006d5320();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct FUN_006dbcf0_Class
{
    void FUN_006dbcf0(FUN_006d5320* items, unsigned int count);
};

// Default-constructs each of count FUN_006d5320 elements in the items array via placement new.
// @fnv 0x006dbcf0
void FUN_006dbcf0_Class::FUN_006dbcf0(FUN_006d5320* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (&items[i]) FUN_006d5320();
    }
}


struct PlacementObject32 : FUN_006d4550_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

// Placement-constructs count PlacementObject32 objects at 32-byte intervals starting at base.
// @fnv 0x006dc130
void FUN_006dc1d0_Class::ConstructPlacementObjects(intptr_t base, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
    {
        new ((void*)(base + index * 32)) PlacementObject32;
    }
}

struct Pt6dc
{
    float x, y, z;
};

extern float DAT_0106ccd0;

struct Falloff6dc
{
    Pt6dc m_kStartPoint;
    Pt6dc m_kEnd;
    float m_fBoundRadius;
    float m_fValue;
    int m_iType;

    float EvaluateFalloff(const Pt6dc& kPt);
};

// @fnv 0x006dc780
float Falloff6dc::EvaluateFalloff(const Pt6dc& kPt)
{
    float fRadiusSq = m_fBoundRadius * m_fBoundRadius;
    float fDist = DAT_0106ccd0;
    switch (m_iType)
    {
    case 0:
    case 2: {
        Pt6dc kToPoint = (*(::Pt6dc *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(m_kStartPoint))->FUN_00439ef0((::NiPoint3 *)&(kPt), *(const ::NiPoint3 *)nullptr)));
        fDist = reinterpret_cast<::TESCombatStyle *>((void *)&(kToPoint))->UpdateCombatStyle();
        break;
    }
    case 1: {
        Pt6dc kKSeg = (*(::Pt6dc *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(m_kEnd))->FUN_00439ef0((::NiPoint3 *)&(m_kStartPoint), *(const ::NiPoint3 *)nullptr)));
        Pt6dc kPtRel = (*(::Pt6dc *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kPt))->FUN_00439ef0((::NiPoint3 *)&(m_kStartPoint), *(const ::NiPoint3 *)nullptr)));
        float fSegLen = reinterpret_cast<::TESCombatStyle *>((void *)&(kKSeg))->UpdateCombatStyle();
        float fDot2 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kPtRel))->DotProduct((void *)&(kKSeg));
        if (fDot2 < ::_DAT_01012060 || fDot2 > fSegLen)
            fDist = DAT_0106ccd0;
        else
            fDist = reinterpret_cast<::TESCombatStyle *>((void *)&(kPtRel))->UpdateCombatStyle() - fDot2 * fDot2 / fSegLen;
        break;
    }
    }
    if (fDist < fRadiusSq)
        return (1.0f - fDist / fRadiusSq) * m_fValue;
    return 0.0f;
}

struct FUN_00527990_shell
{
    bool FUN_00527990(int* first, int* second);
};
struct FUN_006dd280_shell
{
};
struct FUN_006dd220_Class
{
    FUN_006dd220_Class* ConstructFromSource(void* source);
};
struct TriList6df2
{
};

struct NavMesh6df2
{
    TriList6df2* FUN_006911f0(int iIndex);
};

struct NavMeshRef6df2
{
};

struct Grid6df2
{
};

struct GridOwner6df2
{
};

struct Location6df2
{
};

struct Values6df2
{
    char* AddOffset(unsigned int uiIndex);
};


struct TriFlags6df2
{
    bool m_bEnableState;
    char m_acPad1[3];
    Values6df2 m_kValues;
    char m_acPad8[0xc];
    Location6df2* m_pkLocation;
    int m_iTriList;
    bool ApplyTriFlags(GridOwner6df2* pkOwner);
};

// @fnv 0x006df230
bool TriFlags6df2::ApplyTriFlags(GridOwner6df2* pkOwner)
{
    char* pcFlags = reinterpret_cast<::fnv_006e1610::PathingLOSMap *>((((::Grid6df2 *)(::FUN_00559450((int *)(pkOwner))))))->GetTriangleScore((unsigned int)(uintptr_t)(((void *)(::FUN_00559450((int *)(m_pkLocation))))));
    if (!pcFlags)
        return false;
    NavMeshPtr kNavMesh;
    if (!reinterpret_cast<::NavMeshInfo *>((m_pkLocation))->ResolveNavMesh(kNavMesh))
        return false;
    TriList6df2* pkTriList = ((::NavMesh6df2 *)(::FUN_00559450((int *)(((NavMeshRef6df2*)&kNavMesh)))))->FUN_006911f0(m_iTriList);
    if (!pkTriList)
        return false;
    if (!reinterpret_cast<::FUN_0076b610_Class *>(&(m_kValues))->FUN_0076b610())
    {
        unsigned int ItemUpdateArray = FUN_0042f5a0(((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kValues))->GetName())), ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pkTriList))->GetName())));
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
            pcFlags[*((const unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((void *)(pkTriList))->FUN_0069dec0(i)))] = *m_kValues.AddOffset(i);
    }
    else if (m_bEnableState)
    {
        for (unsigned int j = 0; j < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pkTriList))->GetName())); j++)
            pcFlags[*((const unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((void *)(pkTriList))->FUN_0069dec0(j)))] = 3;
    }
    else
    {
        for (unsigned int k = 0; k < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pkTriList))->GetName())); k++)
            if (pcFlags[*((const unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((void *)(pkTriList))->FUN_0069dec0(k)))] == 0x7f)
                pcFlags[*((const unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((void *)(pkTriList))->FUN_0069dec0(k)))] = 0;
    }
    return true;
}

struct TriList6df5
{
};

struct NavMesh6df5
{
    TriList6df5* FUN_006911f0(int iIndex);
};

struct NavMeshAccess6df5
{
};

struct Owner6df5
{
};

struct Flags6df5
{
    char* AddOffset(unsigned int uiIndex);
    int unk00[4];
};

struct Loc6df5
{
};

struct Path6df5
{
    bool m_bDone;
    Flags6df5 m_kFlags;
    Owner6df5* m_pkOwnerManager;
    int m_iTriangle;
    bool IsLocationOnPath(Loc6df5* pkLoc);
};
// Gets the path's navmesh and location, looks up the location index in this array, and delegates the check to the element at that index.
// @fnv 0x006dfdc0
bool FUN_006dfdc0_Class::FUN_006dfdc0(PathingLocation* path)
{
    NavMeshPtr navMesh;

    if (reinterpret_cast<::PathingLocation *>((reinterpret_cast<PathingLocationGetNavMeshHelper*>(path)))->ResolveNavMesh(navMesh))
    {
        NiPoint3 location;
        unsigned int index = reinterpret_cast<GO*>(&navMesh)->operator FUN_00691240_shell*()->ForwardToInner(
            &reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<LocS*>(path)))->QueueActorAnimationTask(location));

        if (index < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(this)))->GetName())))
        {
            return reinterpret_cast<::Path6df5 *>((reinterpret_cast<FUN_006df5f0_Class*>(*reinterpret_cast<Arr*>(this)->GetAt(index))))->IsLocationOnPath((::Loc6df5 *)(path));
        }
    }

    return false;
}

// Checks whether the path is done or the navmesh triangle list contains the location's triangle with a positive flag.
// @fnv 0x006df5f0
bool Path6df5::IsLocationOnPath(Loc6df5* pkLoc)
{
    if (m_bDone)
        return true;
    NavMeshPtr kNavMesh;
    if (!reinterpret_cast<::NavMeshInfo *>((m_pkOwnerManager))->ResolveNavMesh(kNavMesh))
        return false;
    TriList6df5* pkTris = ((::NavMesh6df5 *)(::FUN_00559450((int *)(((NavMeshAccess6df5*)&kNavMesh)))))->FUN_006911f0(m_iTriangle);
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pkTris))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kFlags))->GetName())))
        return false;
    for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pkTris))->GetName())); i++)
    {
        unsigned short usTri = reinterpret_cast<::FUN_0069dec0_class *>((pkTris))->FUN_0069dec0(i);
        if (usTri == reinterpret_cast<::FUN_006df760_shell *>((pkLoc))->GetShortValueAtOffset24())
            return *m_kFlags.AddOffset(i) > 0;
    }
    return false;
}

namespace fnv_006dfb00 {
struct FUN_0042fb00
{
    int state;
    FUN_0042fb00();
    ~FUN_0042fb00();
};
struct Input_006dfb00
{
};
struct Owner_006dfb00
{
    int unk00, unk04, unk08, unk0c;
    Input_006dfb00* input;
    void SetInput(Input_006dfb00*);
};
// Stores p as input, validates it via FUN_0069ad00 into a local FUN_0042fb00; on failure clears input, otherwise calls RebuildFromNavMesh.
// @fnv 0x006dfb00
void Owner_006dfb00::SetInput(Input_006dfb00* apInput)
{
    input = apInput;
    FUN_0042fb00 local;
    if (!((unsigned char)(reinterpret_cast<::NavMeshInfo *>((input))->ResolveNavMesh((*(::NavMeshPtr *)(&local))))))
    {
        input = 0;
        return;
    }
    reinterpret_cast<::InfoEntryArrY *>(this)->RebuildFromNavMesh((*(const ::NavMeshPtrY *)(&local)));
}
}  // namespace fnv_006dfb00

class FUN_006c63b0
{
  public:
    virtual ~FUN_006c63b0();

};

class FUN_006c6350 : public FUN_006c63b0
{
  public:
    virtual ~FUN_006c6350();
};
// Calls FUN_006c6350, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006c60d0
void* FUN_006c60d0_Class::FUN_006c60d0(unsigned int flags)
{
    reinterpret_cast<::FUN_006c6350 *>(this)->FUN_006c6350::~FUN_006c6350();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006c6350
FUN_006c6350::~FUN_006c6350()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class bhkRigidBody;
class InterfacedClass
{
  public:
    virtual ~InterfacedClass();
};
// Native LockFreeQueue<bhkRigidBody*> owns its pointer-array storage.
class FUN_006c6680 : public InterfacedClass
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    bhkRigidBody** entries;
    virtual ~FUN_006c6680();
};
// @fnv 0x006c7170
void* FUN_006c7170_Class::FUN_006c7170(unsigned int flags)
{
    reinterpret_cast<::FUN_006c6680 *>(this)->FUN_006c6680::~FUN_006c6680();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that clears the queue and frees the entries array.
// @fnv 0x006c6680
FUN_006c6680::~FUN_006c6680()
{
    reinterpret_cast<::Queue6c67 *>(this)->ClearQueue(true);
    delete[] entries;
}

class FUN_006c6be0
{
  public:
    virtual ~FUN_006c6be0();

};

class FUN_006c6b80 : public FUN_006c6be0
{
  public:
    virtual ~FUN_006c6b80();
};
// Calls FUN_006c6b80 on this, then frees this via Deallocate if flags has bit 0 set, and returns this.
// @fnv 0x006c6130
void* FUN_006c6130_Class::FUN_006c6130(unsigned int flags)
{
    reinterpret_cast<::FUN_006c6b80 *>((((FUN_006c6b80_Class*)this)))->FUN_006c6b80::~FUN_006c6b80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls FUN_00438af0.
// @fnv 0x006c6b80
FUN_006c6b80::~FUN_006c6b80()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct BSSimpleArray_SandBoxChoiceListItem_1024_
{
    void Clear(bool bFree);
};

class FUN_006c6de0
{
  public:
    virtual ~FUN_006c6de0();
};

class FUN_006c6e00 : public FUN_006c6de0
{
  public:
    virtual ~FUN_006c6e00();
};
// Calls FUN_006c6e00, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006c72c0
void* FUN_006c72c0_Class::ScalarDeletingDestructor(unsigned int flags)
{
    reinterpret_cast<::FUN_006c6e00 *>(this)->FUN_006c6e00::~FUN_006c6e00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor: calls Clear(true) on this viewed as a BSSimpleArray_SandBoxChoiceListItem_1024_.
// @fnv 0x006c6e00
FUN_006c6e00::~FUN_006c6e00()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray_SandBoxChoiceListItem_1024_*>(this)))->Clear(true);
}

class Obj
{
  public:
    int a, b, c;
    Obj* FUN_006c7370();
};
struct FUN_006c7370
{
    int a, b, c;
    FUN_006c7370();
};
class Fac
{
  public:
    FUN_006c7370* CreateObj();
};
// @fnv 0x006c63e0
void FUN_006c63e0_Class::FUN_006c63e0()
{
    reinterpret_cast<::Fac *>((((FUN_006c72f0_Class*)((char*)this + 0xc))))->CreateObj();
}
// Allocates and returns a new FUN_006c7370 object.
// @fnv 0x006c72f0
FUN_006c7370* Fac::CreateObj()
{
    return new FUN_006c7370;
}

struct FUN_006c8b30
{
    int m0;
    int m1;
    int m2;
    int m3;
    FUN_006c8b30();
    ~FUN_006c8b30();
};
struct FUN_006c8a90_Class
{
    void InitializeArray(char* buffer, unsigned int count);
};
// @fnv 0x006c8c70
void FUN_006c8c70_Class::FUN_006c8c70(unsigned int uiRequestedSize, unsigned int savedSize)
{
    m_iElementCount = 0;
    m_vContactPosition = 0;
    m_dataLength = 0;
    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }
    if (uiRequestedSize > 0)
    {
        m_iElementCount = Write(uiRequestedSize);
        m_dataLength = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_006c8a90_Class *>((((Arr16*)this)))->InitializeArray((char *)(::Elem16 *)((Elem16*)m_iElementCount), savedSize);
        m_vContactPosition = savedSize;
    }
}
// Placement-constructs a FUN_006c8b30 object at each 16-byte slot of buffer for count elements.
// @fnv 0x006c8a90
void FUN_006c8a90_Class::InitializeArray(char* buffer, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (buffer + i * 16) FUN_006c8b30;
    }
}

namespace fnv_006c8b30 {
class PathingSolution
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class FUN_006c8b30_C
{
  public:
    NiPointer<PathingSolution> m_spSolution;
    int unk04;
    int unk08;
    NavMeshPtr m_kNavMesh;

    FUN_006c8b30_C();
};

// Constructor that initialises m_spSolution to null.
// @fnv 0x006c8b30
FUN_006c8b30_C::FUN_006c8b30_C() : m_spSolution(0)
{}
}  // namespace fnv_006c8b30

struct FUN_006e6da0
{
    int a;
};
class FUN_006f4f00
{
  public:
    FUN_006f4f00(int a, int b, int c);
    int unk[12];
};
class PoolX
{
  public:
};
class OwnerX
{
  public:
    int unk0, unk4;
    PoolX kPool;
    unsigned int CreateEntry(int a, int b, int c);
};
// Advances the pool counter, constructs a FUN_006f4f00 in the slot at that index, and returns the index.
// @fnv 0x006c9a70
unsigned int OwnerX::CreateEntry(int a, int b, int c)
{
    unsigned int uiIndex = reinterpret_cast<::FUN_006cef10_shell *>(&(kPool))->AdvanceCounter();
    FUN_006e6da0* pSlot = ((struct ::FUN_006e6da0 *)(reinterpret_cast<::FUN_006e8f40_shell *>(&(kPool))->FUN_006e8f40(uiIndex)));
    new (pSlot) FUN_006f4f00(a, b, c);
    return uiIndex;
}


struct NavMeshBuffer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    explicit NavMeshBuffer(void* source);
    NavMeshBuffer(void* source, const NavMeshBuffer& reference);
    ~NavMeshBuffer();
    void FUN_006dcce0(const NavMeshBuffer& original);
};

struct NavMeshPlan
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    NavMeshPlan();
    ~NavMeshPlan();
    void* FUN_006d3370(unsigned int deleteObject);
};
struct NavMeshTriangleVertexIndices
{
    unsigned int unk00;
    unsigned int unk04;
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
    NavMeshTriangleVertexIndices();
};
struct NavMeshResult
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk40;
    unsigned int unk44;
    NavMeshResult();
    ~NavMeshResult();
};

struct NavMeshContext
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    explicit NavMeshContext(NavMeshContext* original);
    ~NavMeshContext();
};

struct NavMeshItem
{
};
struct NavMeshRoute
{
};

// Iterates route items, testing each candidate position for combat suitability and updating the context with the first valid result found.
// @fnv 0x006d2c80
bool __cdecl FUN_006d2c80(NavMeshContext* context, NavMeshRoute* route)
{
    bool acceptedNew;
    AutoMemHelper memoryRef(0x2d, true, ::fnv_006d23d0::str_0106cb70, 0x322);
    acceptedNew = ::FUN_006d0b10((::PathingRequest *)(context), (::PathingSolution *)(route));
    if (!acceptedNew)
        return false;
    float thresholdRes = ::DAT_010231a0;
    NavMeshBuffer initial(((void *)(::GetOffsetC((intptr_t)(context)))));
    NavMeshPlan* plan = new NavMeshPlan;
    NavMeshTriangleVertexIndices* edgeTmp = new NavMeshTriangleVertexIndices;
    NavMeshContext currentVal(context);
    reinterpret_cast<::HX *>(&(currentVal))->FUN_006d3100((::CombatCoverPointData *)(plan));
    reinterpret_cast<::FUN_006d30e0_Class *>(&(currentVal))->FUN_006d30e0((intptr_t)(edgeTmp));
    reinterpret_cast<::HX *>((context))->FUN_006d3100((::CombatCoverPointData *)(plan));
    reinterpret_cast<::FUN_006d30e0_Class *>((context))->FUN_006d30e0((intptr_t)(edgeTmp));
    unsigned int index = 1;
    while (::GetObjectFlags((char *)(route)) > index)
    {
        NavMeshBuffer candidate(((void *)(reinterpret_cast<::BaseProcess *>((((::NavMeshItem *)(reinterpret_cast<::FUN_006e7970_shell *>((route))->FUN_006e7970(index)))))->GetCurrentProcessData())));
        reinterpret_cast<::PathingRequest *>(&(currentVal))->SetDestination((::PathingLocation *)&(candidate));
        if (::CombatPosition::FindCombatPosition((::CombatPosition::Actor *)(&currentVal), thresholdRes, true))
        {
            NavMeshBuffer replacement(((void *)(::FUN_006377e0((intptr_t)&(currentVal)))), candidate);
            reinterpret_cast<::PathingRequest *>(&(currentVal))->SetDestination((::PathingLocation *)&(replacement));
            NavMeshResult resultTmp;
            bool found = ::FUN_006d0b10((::PathingRequest *)(&currentVal), (::PathingSolution *)(&resultTmp));
            if (found)
            {
                reinterpret_cast<::FUN_006d30b0_Class2 *>((context))->FUN_006d30b0((*(const ::NiPoint3 *)(((void *)(::FUN_006377e0((intptr_t)&(currentVal)))))));
                reinterpret_cast<::PathingRequest *>((context))->SetDestination((::PathingLocation *)&(replacement));
                reinterpret_cast<::FUN_006d3120_Class *>(&(currentVal))->FUN_006d3120();
                reinterpret_cast<::MyClass *>(&(resultTmp))->FUN_006e8ab0((::MyClass *)(route));
                reinterpret_cast<::FUN_00613fb0_C *>((context))->Set(true);
                return found;
            }
        }
        index++;
        initial.FUN_006dcce0(candidate);
    }
    reinterpret_cast<::FUN_006d3120_Class *>(&(currentVal))->FUN_006d3120();
    delete plan;
    reinterpret_cast<::HX *>((context))->FUN_006d3100((::CombatCoverPointData *)(::NavMeshPlan *)(0));
    reinterpret_cast<::FUN_00613fb0_C *>((context))->Set(true);
    return true;
}

// Representative of the actual 0x28-byte PathingLocation base.
class CoverPathingBase
{
  public:
    virtual ~CoverPathingBase();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    CoverPathingBase();
};
struct CoverPoint3
{
    float x, y, z;
    CoverPoint3();
};
// Native PathingCoverLocation constructor owns three real Point3 members.
class FUN_006d3200 : public CoverPathingBase
{
  public:
    CoverPoint3 point28;
    CoverPoint3 point34;
    CoverPoint3 point40;
    FUN_006d3200();
    virtual ~FUN_006d3200();
};
// Default constructor with an empty body; derives from CoverPathingBase and has three CoverPoint3 members.
// @fnv 0x006d3200
FUN_006d3200::FUN_006d3200()
{}

struct CoverSortItem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float score;
    float angle;
};
// Compares two CoverSortItem entries by angle range and score, returning -1, 0, or 1 for sort ordering.
// @fnv 0x006d4020
int __cdecl CompareCoverSortItems(const CoverSortItem* first, const CoverSortItem* second)
{
    bool firstInRange;
    bool rightInRange;
    const CoverSortItem* other;
    const CoverSortItem* a;
    a = first;
    other = second;
    firstInRange = a->angle > -64.0 && a->angle < 180.0;
    rightInRange = other->angle > -64.0 && other->angle < 180.0;
    if (firstInRange && !rightInRange)
        return -1;
    else if (!firstInRange && rightInRange)
        return 1;
    else if (a->score < other->score)
        return -1;
    else if (a->score > other->score)
        return 1;
    else
        return 0;
}

class FUN_006db720
{
  public:
    virtual ~FUN_006db720();

};

class FUN_006db740 : public FUN_006db720
{
  public:
    virtual ~FUN_006db740();
};
// Calls FUN_006db740, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006dbc30
void* FUN_006dbc30_Class::FUN_006dbc30(unsigned int flags)
{
    reinterpret_cast<::FUN_006db740 *>(this)->FUN_006db740::~FUN_006db740();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006db740
FUN_006db740::~FUN_006db740()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(1);
}

namespace fnv_006dbe40 {
struct FUN_006d3200
{
    FUN_006d3200();
    ~FUN_006d3200();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
};
struct FUN_006dbe40_Class
{
    void ConstructInPlace(FUN_006d3200* pBase, unsigned int aiCount);
};
// Calls the FUN_006d3200 constructor on each element of the pBase array, aiCount times.
// @fnv 0x006dbe40
void FUN_006dbe40_Class::ConstructInPlace(FUN_006d3200* pBase, unsigned int aiCount)
{
    for (unsigned int i = 0; i < aiCount; ++i)
        new (&pBase[i]) FUN_006d3200;
}
}  // namespace fnv_006dbe40

// Native BSSimpleArray<TwoUIntRecord,1024> elements have two words.
struct TwoUIntRecord
{
    unsigned int unk00;
    unsigned int unk04;
    TwoUIntRecord();
};
struct CrossedTriangleArray
{
    void ConstructElements(TwoUIntRecord* elements, unsigned int count);
};
// @fnv 0x006dc440
void FUN_006dc440_Class::FUN_006dc440(unsigned int uiRequestedSize, unsigned int savedSize)
{
    m_iElementCount = 0;
    m_vContactPosition = 0;
    m_dataLength = 0;
    if (savedSize > uiRequestedSize)
        uiRequestedSize = savedSize;
    if (uiRequestedSize > 0)
    {
        m_iElementCount = Write(uiRequestedSize);
        m_dataLength = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::CrossedTriangleArray *>(this)->ConstructElements((::TwoUIntRecord *)(m_iElementCount), savedSize);
        m_vContactPosition = savedSize;
    }
}
// @fnv 0x006dba30
unsigned int FUN_006dba30_Class::FUN_006dba30(S0069a690 const* other)
{
    unsigned int idx = reinterpret_cast<::S5460 *>((reinterpret_cast<FUN_0069b030_S*>(this)))->FUN_00845460();
    reinterpret_cast<::CrossedTriangleArray *>((reinterpret_cast<FUN_006dc3a0_Obj*>(this)))->ConstructElements((::TwoUIntRecord *)(::S0069a690 *)(&m_items[idx]), 1);
    m_items[idx].FUN_0069a690(other);
    return idx;
}
// Placement-constructs TwoUIntRecord objects into the elements array for the given count.
// @fnv 0x006dc3a0
void CrossedTriangleArray::ConstructElements(TwoUIntRecord* elements, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
        new (elements + index) TwoUIntRecord;
}

class FUN_006e1070
{
  public:
    FUN_006e1070();
    ~FUN_006e1070();
    int unk00;
};

class FUN_006dfcb0
{
  public:
    int unk00;
    FUN_006e1070 m_04;

    FUN_006dfcb0(int a, int b);
};

// Calls FUN_006df200 with the two constructor arguments.
// @fnv 0x006dfcb0
FUN_006dfcb0::FUN_006dfcb0(int a, int b)
{
    reinterpret_cast<::FUN_006df200_Class *>(this)->FUN_006df200(a, b);
}

class Elem6DFD
{
  public:
};

class List6DFD
{
  public:
    Elem6DFD** FUN_00877a30(unsigned int index, int arg);

    bool ApplyAllTriFlags(int arg);
};

// Iterates over all elements in the list and calls ApplyTriFlags on each one, returning true.
// @fnv 0x006dfd20
bool List6DFD::ApplyAllTriFlags(int arg)
{
    for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())); i++)
        reinterpret_cast<::TriFlags6df2 *>(((*FUN_00877a30(i, arg))))->ApplyTriFlags({});
    return true;
}

struct FUN_00559450_shell
{
};
struct FUN_0044ddc0_shell
{
};
struct FUN_00865db0_shell
{
    void FUN_00865db0(unsigned int value, unsigned int flags);
};
struct FUN_00865f60_shell
{
};
struct BGSSaveGameBuffer;
struct FUN_006df9c0_shell
{
public:
    void FUN_006df9c0(::BGSSaveGameBuffer *);
};
struct FUN_006dffc0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00559450_shell* m_ref;
    void WriteToBuffer(FUN_00865db0_shell* buffer);
};
// Passes a value from m_ref (or 0) and the item count to buffer, then calls FUN_006df9c0 on each item with buffer.
// @fnv 0x006dffc0
void FUN_006dffc0_Class::WriteToBuffer(FUN_00865db0_shell* buffer)
{
    buffer->FUN_00865db0(m_ref ? ((unsigned int)(::FUN_00559450((int *)(m_ref)))) : 0, 0);
    unsigned int count = this ? ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((FUN_0044ddc0_shell*)this)))->GetName())) : 0;
    reinterpret_cast<::BGSSaveGameBuffer *>((((FUN_00865f60_shell*)buffer)))->FUN_00865f60(count);
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned int item = (unsigned int)(reinterpret_cast<::S3e60 *>((((FUN_006a7ad0_shell*)this)))->FUN_006a7ad0(index));
        ((FUN_006df9c0_shell*)(uintptr_t)item)->FUN_006df9c0((::BGSSaveGameBuffer *)(buffer));
    }
}

namespace s6c7530 {


struct Owner
{
    const char* m_pVtbl;

    void FUN_006b3eb0(int iArg0, int iArg1);
    Owner* Initialize();
};

// Sets m_pVtbl to DAT_0106c708, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x006c7530
Owner* Owner::Initialize()
{
    m_pVtbl = DAT_0106c708;
    FUN_006b3eb0(0, 0);
    return this;
}

}


class FUN_006c75c0
{
  public:
    ~FUN_006c75c0();
};

struct Entry6C74
{
    unsigned int m_uiKey;
    FUN_006c75c0* m_pkValue;
};

struct Owner6C74
{
    unsigned int m_uiCount;
    unsigned long m_uiTlsIndex;
    Entry6C74* m_pkEntryArray;

    void Destroy();
};
// Calls Destroy, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006c71a0
void* FUN_006c74a0_Class::FUN_006c71a0(unsigned int flags)
{
    reinterpret_cast<::Owner6C74 *>(this)->Destroy();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Deletes each entry's value, deletes m_pkEntryArray, and frees the TLS index through FUN_0044e360.
// @fnv 0x006c74a0
void Owner6C74::Destroy()
{
    for (unsigned int i = 0; i < ((unsigned int)(::FUN_00559450((int *)this))); i++)
        delete m_pkEntryArray[i].m_pkValue;
    delete m_pkEntryArray;
    ::FUN_0044e360(m_uiTlsIndex);
}

struct NavMeshEdgeData;
struct FUN_006cfd70 : public BSSimpleArray<NavMeshEdgeData, 1024>
{
    virtual ~FUN_006cfd70();
};
// Empty virtual destructor of a class derived from BSSimpleArray<NavMeshEdgeData, 1024>.
// @fnv 0x006cfd70
FUN_006cfd70::~FUN_006cfd70()
{}

struct Vec3
{
    float x, y, z;
public:
    Vec3();
};
// Sets the vtable pointer, calls the base constructor at offset 4, then runs the setup helper with a and b, and returns this.
// @fnv 0x006dcea0
void* FUN_006dcea0_Class::ConstructWithSetup(void* apArg, void* apOther)
{
    *(void**)this = &DAT_0102583c;
    new ((void *)(((Inner04*)((char*)this + 4)))) ::Vec3();
    reinterpret_cast<::SetupPathingLocation *>((((SetupHelper*)this)))->FUN_006dd280((*(const ::NiPoint3 *)(apArg)), (::TESObjectCELL *)(0), (::TESWorldSpace *)(apOther));
    return this;
}
// @fnv 0x006dd220
FUN_006dd220_Class* FUN_006dd220_Class::ConstructFromSource(void* source)
{
    *reinterpret_cast<int**>(this) = &DAT_0102583c;
    new ((void *)(reinterpret_cast<BSSimpleList<BGSPerk*>*>(reinterpret_cast<char*>(this) + 4))) ::Vec3();
    int b = 0;
    int a = 0;
    reinterpret_cast<FUN_00527990_shell*>(source)->FUN_00527990(&b, &a);
    reinterpret_cast<::SetupPathingLocation *>((reinterpret_cast<FUN_006dd280_shell*>(this)))->FUN_006dd280(
        (*(const ::NiPoint3 *)(new ((void *)(reinterpret_cast<BSSimpleList<BGSPerk*>*>(source))) ::Vec3())), (::TESObjectCELL *)(intptr_t)(b), (::TESWorldSpace *)(intptr_t)(a));
    return this;
}
extern float DAT_0106cb30;

struct FUN_00435de0
{
    float value;
    FUN_00435de0(float initial);
};
struct FUN_006dae60
{
    unsigned int field0, field4, field8, fieldC;
    FUN_006dae60();
};
struct FUN_006d32e0
{
    Vec3 translation;
    Vec3 rotation;
    float progress;
    FUN_00435de0 time;
    FUN_006dae60 state;
    unsigned int count;
    unsigned int flags;
    unsigned char enabled;
    FUN_006d32e0();
};

// Initializes translation and rotation from DAT_011f426c, progress to 0, time to -DAT_0106cb30, and count, flags and enabled to 0.
// @fnv 0x006d32e0
FUN_006d32e0::FUN_006d32e0()
    : translation((*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO))), rotation((*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO))), progress(0.0f), time(-DAT_0106cb30), state(), count(0),
      flags(0), enabled(0)
{}

// Finds a navmesh path between two points, building a pathing solution with intermediate nodes and a final node or item.
// @fnv 0x006ce8b0
bool PathHandler::FindPath(const NiPoint3& pt1, const NiPoint3& pt2, PathingContext* ctx, intptr_t flag)
{
    FUN_006dcee0 loc1(pt1, ctx->cell, ctx->worldSpace);
    FUN_006dcee0 loc4(pt2, ctx->cell, ctx->worldSpace);

    if (!reinterpret_cast<::PathingLocation *>(&(loc1))->HasPathingLocation())
        return false;

    if (!reinterpret_cast<::PathingLocation *>(&(loc4))->HasPathingLocation())
        return false;

    FUN_006b8420 var20cc;
    FUN_006cf340 var5(0x14, 0, m_unk08);
    FUN_006cf440 var4(0x14, 0, m_unk08);
    ::fnv_006b8c50::PathingActorData* var14 = nullptr;

    bool retVal = reinterpret_cast<::fnv_006b8c50::FUN_006b8c50_shell *>(&(var20cc))->SetupNavMeshSearch(var14, (void *)&(const ::NiPoint3 &)(reinterpret_cast<::TaskQueueInterface *>((void *)&(loc1))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)), ((void *)(reinterpret_cast<::PathingLocationProxy *>(&(loc1))->GetAssociatedNavMesh())), (void *)&(const ::NiPoint3 &)(reinterpret_cast<::TaskQueueInterface *>((void *)&(loc4))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)),
                                             ((void *)(reinterpret_cast<::PathingLocationProxy *>(&(loc4))->GetAssociatedNavMesh())), &var5, &var4, 0);

    if (!retVal)
    {
        if (reinterpret_cast<::FUN_0076b610_Class *>(&(var5))->FUN_0076b610() || !((bool)(reinterpret_cast<::FUN_006a9560_Class *>((reinterpret_cast<RequestHelper*>(m_request)))->GetByteAtOffset9B())))
        {
            return false;
        }
        else
        {
            reinterpret_cast<::FUN_006c9fa0_shell *>((m_pPathingSolution))->SetByteAtOffset40(1);
        }
    }

    reinterpret_cast<::FUN_006c90d0_fix *>((m_pPathingSolution))->FUN_006c90d0((const ::PathingInfoEntry &)(loc1));

    for (unsigned int i2 = 1; i2 < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(var5))->GetName())) - 1; ++i2)
    {
        reinterpret_cast<::FUN_006c9920_cls *>((m_pPathingSolution))->ConstructThing((unsigned int)(uintptr_t)(*var5.FUN_00877a30(i2)));
    }

    if (retVal)
    {
        if (flag != 0)
        {
            reinterpret_cast<::PathOwner *>((m_pPathingSolution))->CreatePathNode((void *)&(loc4), (::TESForm *)(flag));
        }
        else
        {
            reinterpret_cast<::FUN_006c90d0_fix *>((m_pPathingSolution))->FUN_006c90d0((const ::PathingInfoEntry &)(loc4));
        }
    }
    else
    {
        reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((m_pPathingSolution))->AddPathingItem((char*)(*((void **)(reinterpret_cast<::FUN_006f2270 *>(&(var5))->GetLast()))) + 0x10, (::TESObjectREFR *)(*((void **)(reinterpret_cast<::FUN_006f2270 *>(&(var5))->GetLast()))));
    }

    return retVal;
}

namespace fnv_006db680 {
class ScrapHeapBuffer;
class MemoryManager
{
  public:
};
// Representative of the native BSSimpleArray<float,1024> base.
class FloatArrayBase
{
  public:
    virtual ~FloatArrayBase();
    float* buffer;
    unsigned int size;
    unsigned int reserved;
    FloatArrayBase();
    void FUN_006b3eb0(unsigned int, unsigned int);
};
// Native BSScrapArray<float,1024> constructor.
class FUN_006db680 : public FloatArrayBase
{
  public:
    ScrapHeapBuffer* heap;
    FUN_006db680(unsigned int count, unsigned int capacity, ScrapHeapBuffer* allocator);
    virtual ~FUN_006db680();
};
// Initialises a float array with the given count and capacity, using the supplied allocator or the global memory manager's scrap heap buffer.
// @fnv 0x006db680
FUN_006db680::FUN_006db680(unsigned int count, unsigned int capacity, ScrapHeapBuffer* allocator)
{
    heap = allocator ? allocator : ((::fnv_006db680::ScrapHeapBuffer *)(reinterpret_cast<::MemoryManager *>((((::fnv_006db680::MemoryManager *)(::FUN_00401020()))))->GetGeneralAllocator()));
    FUN_006b3eb0(count, capacity);
}
}  // namespace fnv_006db680

namespace fnv_006db7a0 {
class ScrapHeapBuffer;
class MemoryManager
{
  public:
};
// Representative of native BSSimpleArray<NavMeshPtr,1024>.
class NavMeshArrayBase
{
  public:
    virtual ~NavMeshArrayBase();
    NavMeshPtr* buffer;
    unsigned int size;
    unsigned int reserved;
    NavMeshArrayBase();
};
// Native BSScrapArray<NavMeshPtr,1024> constructor.
class FUN_006db7a0 : public NavMeshArrayBase
{
  public:
    ScrapHeapBuffer* heap;
    FUN_006db7a0(unsigned int count, unsigned int capacity, ScrapHeapBuffer* allocator);
    virtual ~FUN_006db7a0();
};
// Sets heap to allocator, or to FUN_00401020()->FUN_00aa42e0() if allocator is null, then calls FUN_0042fcb0(count, capacity).
// @fnv 0x006db7a0
FUN_006db7a0::FUN_006db7a0(unsigned int count, unsigned int capacity, ScrapHeapBuffer* allocator)
{
    heap = allocator ? allocator : ((::fnv_006db7a0::ScrapHeapBuffer *)(reinterpret_cast<::MemoryManager *>((((::fnv_006db7a0::MemoryManager *)(::FUN_00401020()))))->GetGeneralAllocator()));
    reinterpret_cast<::S2f850 *>(this)->FUN_0042fcb0(count, capacity);
}
}  // namespace fnv_006db7a0

namespace fnv_006df180 {
class MemoryManager
{
  public:
};


class PathBuilderDetailedPathInfos
{
  public:
    PathBuilderDetailedPathInfos();
    virtual ~PathBuilderDetailedPathInfos();
    void FUN_006b3eb0(unsigned int, unsigned int);

    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006df180 : public PathBuilderDetailedPathInfos
{
  public:
    FUN_006df180();
    virtual ~FUN_006df180();

    void* m_pMemoryAllocator;
};

// Initializes m_pMemoryAllocator from the global memory manager and calls FUN_006b3eb0 with zero arguments.
// @fnv 0x006df180
FUN_006df180::FUN_006df180()
{
    m_pMemoryAllocator = ((void *)(reinterpret_cast<::MemoryManager *>((((::fnv_006df180::MemoryManager *)(::FUN_00401020()))))->GetGeneralAllocator()));
    FUN_006b3eb0(0, 0);
}
}  // namespace fnv_006df180

struct FakeArray : public FUN_006dc1d0_Class
{
    unsigned int FUN_006db400(const NavMeshEdgePoint& item);
};

// Reserves a slot at the current index, copies item into it via FUN_006dbb40, and returns the index.
// @fnv 0x006db400
unsigned int FakeArray::FUN_006db400(const NavMeshEdgePoint& item)
{
    unsigned int index = ((unsigned int)(reinterpret_cast<::FUN_006b4060_class *>(this)->GetNextIndex()));
    reinterpret_cast<::FUN_006dc1d0_Class *>(this)->ConstructPlacementObjects(m_iElementCount + (index << 5), 1);
    ((NavMeshEdgePoint*)(m_iElementCount + (index << 5)))->FUN_006dbb40(item);
    return index;
}

void FUN_006c6de0(GlobalObject_00869f00*);
struct GlobalObjectDeletingEntry : public GlobalObject_00869f00
{
    void* FUN_006c7290(unsigned int flags);
};
// Calls FUN_006c6de0 on this, deallocates the object when the low bit of flags is set, and returns this.
// @fnv 0x006c7290
void* GlobalObjectDeletingEntry::FUN_006c7290(unsigned int flags)
{
    FUN_006c6de0(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

#include "generated/data/staging/blk_006c0000_od.inc"
