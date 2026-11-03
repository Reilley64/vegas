
// src/staging/blk_006e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cstring>
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSSimpleArray_006cefa0.h"
#include "fnv/decl/BSSimpleArray_PathingNode_1024.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Date.h"
#include "fnv/decl/EB2B0Owner.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00438b90_class.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_004941c0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004ea9a0_Class.h"
#include "fnv/decl/FUN_00528820_shell.h"
#include "fnv/decl/FUN_00529000_cls.h"
#include "fnv/decl/FUN_00546780_shell.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_0059ceb0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0062a290_Class.h"
#include "fnv/decl/FUN_0062a2b0_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_0068f200_shell.h"
#include "fnv/decl/FUN_006928a0_class.h"
#include "fnv/decl/FUN_0069b940_class.h"
#include "fnv/decl/FUN_0069f920_cls.h"
#include "fnv/decl/FUN_006a5ec0_shell.h"
#include "fnv/decl/FUN_006b0570_shell.h"
#include "fnv/decl/FUN_006b3f40_Class.h"
#include "fnv/decl/FUN_006b4060_class.h"
#include "fnv/decl/FUN_006b9710_Class.h"
#include "fnv/decl/FUN_006bc870_shell.h"
#include "fnv/decl/FUN_006cee10_shell.h"
#include "fnv/decl/FUN_006cf4c0_Array.h"
#include "fnv/decl/FUN_006cf700_cls.h"
#include "fnv/decl/FUN_006d0730_shell.h"
#include "fnv/decl/FUN_006d07d0_shell.h"
#include "fnv/decl/FUN_006d5320.h"
#include "fnv/decl/FUN_006dbcf0_Class.h"
#include "fnv/decl/FUN_006dd3e0_shell.h"
#include "fnv/decl/FUN_006e7970_shell.h"
#include "fnv/decl/FUN_006e9260Class.h"
#include "fnv/decl/FUN_006eb250_Class.h"
#include "fnv/decl/FUN_006ec870.h"
#include "fnv/decl/FUN_006f2270.h"
#include "fnv/decl/FUN_006f3e30_shell.h"
#include "fnv/decl/FUN_006f60c0_shell.h"
#include "fnv/decl/FUN_006f6250_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_006f9080_owner.h"
#include "fnv/decl/FUN_006fa840_shell.h"
#include "fnv/decl/FUN_006fb150_shell.h"
#include "fnv/decl/FUN_006ff3f0_shell.h"
#include "fnv/decl/FUN_0072ba80_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00869600_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009a3910_cls.h"
#include "fnv/decl/HitRect.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/MeshX.h"
#include "fnv/decl/NavMeshInfo.h"
#include "fnv/decl/NavMeshInfoStandIn.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/Object.h"
#include "fnv/decl/PathingLocationArray.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S006e6ae0_Object.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/S_005e0ad0.h"
#include "fnv/decl/S_006ac070.h"
#include "fnv/decl/SelfX.h"
#include "fnv/decl/StandInShell.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TaskProcessor.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/TreeOwnerS.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/Worker.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/detach6fb__D6Detacher.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004ea9c0__GlobalNodeAccessor.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_006f2290__CtorHelper.h"
#include "fnv/decl/fnv_006f4480__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_009f6540__FUN_009f6540_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00690000.h"
#include "fnv/symbols_006a1000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006df000.h"
#include "fnv/symbols_006e6000.h"
#include "fnv/symbols_006f4000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_006fe000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_0106d000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01202000.h"
#include "../../include/layout_support.h"

struct Interface
{
};

int __cdecl FUN_0043b460(long volatile* a1, long a2, long a3);

struct FUN_006ec0d0_Class
{
    bool FUN_006ec0d0(int a1);
};

// @fnv 0x006ec0d0
bool FUN_006ec0d0_Class::FUN_006ec0d0(int a1)
{
    bool result;
    if (FUN_0043b460((long volatile*)this + 1, 0, 1) == 0)
    {
        reinterpret_cast<void(__cdecl*)()>(&::FUN_0040fbe0)();
        result = (bool)((bool(*)(void*, int)) * (*(void***)this + 5))(this, a1);
        reinterpret_cast<void(__cdecl*)()>(&::FUN_0040fbe0)();
        FUN_0043b460((long volatile*)this + 1, 1, 0);
    }
    else
    {
        result = false;
    }
    return result;
}

struct FUN_006e1020_shell
{
    FUN_006e1020_shell* FUN_006e1020();
    FUN_006e1020_shell* FUN_006e0e80();
};
FUN_006e1020_shell* FUN_006e1020_shell::FUN_006e1020()
{
    return this;
}
// @fnv 0x006e0e80
FUN_006e1020_shell* FUN_006e1020_shell::FUN_006e0e80()
{
    this->FUN_006e1020();
    *(int*)((char*)this + 0x10) = 0;
    return this;
}

extern int DAT_0106ceb8;
struct FUN_006e0ea0_Class
{
    int* FUN_006e0ea0(int a1);
};
extern int DAT_0106cef8;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_006e1050();
};
// @fnv 0x006e1050
void GlobalObject_00869f00::FUN_006e1050()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106cef8);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(true);
}

struct S006d0420
{
};
struct FUN_006e1070_Class
{
    FUN_006e1070_Class* FUN_006e1070();
};
// @fnv 0x006e1070
FUN_006e1070_Class* FUN_006e1070_Class::FUN_006e1070()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0106cf0c;
    reinterpret_cast<::FUN_0069b940_class *>((reinterpret_cast<S006d0420*>(this)))->FUN_0069b940(0, 0);
    return this;
}

namespace fnv_006e10a0 {
struct GlobalObject_00869f00
{
    void Clear(bool a1);
};
struct FUN_006e10a0_Class
{
    void FUN_006e10a0();
};
// @fnv 0x006e10a0
void FUN_006e10a0_Class::FUN_006e10a0()
{
    *reinterpret_cast<int**>(this) = &::DAT_0106cf0c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_006e10a0

struct FUN_006e2080_Class
{
    int m;
    int FUN_006e2080(int a1);
};
struct Copy9
{
    Copy9* FUN_00502630(const Copy9* a1);
};
struct FUN_006e29b0_Class
{
    void FUN_006e29b0(const Copy9* a1);
};
// @fnv 0x006e29b0
void FUN_006e29b0_Class::FUN_006e29b0(const Copy9* a1)
{
    ((Copy9*)((char*)this + 0x5c))->FUN_00502630(a1);
}

struct PathingAvoidanceNode;
struct FUN_006e3a80
{
    void _InitialSetup(unsigned int, unsigned int);
    const char* m_p;
    FUN_006e3a80();
};
// @fnv 0x006e3a80
FUN_006e3a80::FUN_006e3a80()
{
    m_p = "`<n";
    _InitialSetup(0, 0);
}

namespace fnv_006e3ab0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006e3ab0_Class
{
    void FUN_006e3ab0();
};
// @fnv 0x006e3ab0
void FUN_006e3ab0_Class::FUN_006e3ab0()
{
    *reinterpret_cast<const char**>(this) = "`<n";
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_006e3ab0

struct FUN_006e5ee0_Class
{
    void FUN_006e5ee0(float value);
};

// @fnv 0x006e5ee0
void FUN_006e5ee0_Class::FUN_006e5ee0(float value)
{
    *(float*)((char*)this + 0xb4) = value;
}

void __cdecl FUN_005e0b60(void*);

struct FUN_006e6bd0_Class
{
    void FUN_006e6bd0();
};

// Calls FUN_005e0b60 on the pointer at offset 0x78, then sets that pointer to null.
// @fnv 0x006e6bd0
void FUN_006e6bd0_Class::FUN_006e6bd0()
{
    FUN_005e0b60(*(void**)((char*)this + 0x78));
    *(void**)((char*)this + 0x78) = 0;
}

struct Dummy_006e8f80
{
    void* FUN_006e8f80(unsigned int);
};
struct FUN_006e8fc0_Class
{
    void* FUN_006e8fc0();
};
// @fnv 0x006e8fc0
void* FUN_006e8fc0_Class::FUN_006e8fc0()
{
    return ((void *)(reinterpret_cast<::BSSimpleArray_PathingNode_1024 *>((reinterpret_cast<Dummy_006e8f80*>(this)))->FUN_006e8f80(0)));
}

namespace fnv_006e8fe0 {
struct PathingGraphNode
{
    void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void* operator new(unsigned int, const void*);
};

struct Dummy_006e8f80
{
    void* m_pFirst;
    unsigned int m_nCount;
    unsigned int m_nCapacity;
    void* m_pLast;
    PathingGraphNode* FUN_006e8f80(unsigned int index);
};

struct FUN_006e8fe0_Class
{
    void* m_pFirst;
    unsigned int m_nCount;
    unsigned int m_nCapacity;
    void* m_pLast;
    PathingGraphNode* FUN_006e8f80(unsigned int index);
    PathingGraphNode* FUN_006e8fe0();
};

// @fnv 0x006e8fe0
PathingGraphNode* FUN_006e8fe0_Class::FUN_006e8fe0()
{
    return ((::fnv_006e8fe0::PathingGraphNode *)(reinterpret_cast<::BSSimpleArray_PathingNode_1024 *>((this))->FUN_006e8f80(m_nCapacity - 1)));
}
}  // namespace fnv_006e8fe0

void __cdecl InitSizeState(int a1, int a2);

struct FUN_006e9050_Class
{
    void InitSizeState(int a1, int a2);
    void* FUN_006e9050();
};

namespace fnv_006e9080 {
struct PSClearStub
{
    void Clear(bool a1);
    int m_stub;
    void FUN_006e9080();
};
// @fnv 0x006e9080
void PSClearStub::FUN_006e9080()
{
    m_stub = (int)&(*reinterpret_cast<int *>(&::DAT_0106d4d4));
    reinterpret_cast<::BSSimpleArray_006cefa0 *>(this)->FreeArray(true);
}
}  // namespace fnv_006e9080


struct FUN_006ec1e0_Class
{
    void FUN_006ec1e0();
};

// @fnv 0x006ec1e0
void FUN_006ec1e0_Class::FUN_006ec1e0()
{
    *reinterpret_cast<long*>(this) = (long)&DAT_0106d6b8;
}

extern int DAT_0106d6d0;
struct FUN_006ec3f0_Class
{
    void FUN_006ec3f0();
};
extern const void* DAT_0106d6f0;

struct FUN_006ec410_Class
{
    virtual ~FUN_006ec410_Class();
};
// @fnv 0x006ec3f0
void FUN_006ec3f0_Class::FUN_006ec3f0()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0106d6d0;
    reinterpret_cast<::FUN_006ec410_Class *>(this)->FUN_006ec410_Class::~FUN_006ec410_Class();
}


struct FUN_006ec430_Class
{
    void FUN_006ec430();
};
// @fnv 0x006ec410
FUN_006ec410_Class::~FUN_006ec410_Class()
{
    reinterpret_cast<::FUN_006ec430_Class *>(this)->FUN_006ec430();
}

// @fnv 0x006ec430
void FUN_006ec430_Class::FUN_006ec430()
{
    *(int*)this = (int)&DAT_0106d710;
}

extern "C" void __cdecl FUN_006ecc00();
extern int DAT_0106d698;

struct FUN_006ecb40_Class
{
    void FUN_006ecc00();
    FUN_006ecb40_Class* FUN_006ecb40();
};

// @fnv 0x006ecb40
FUN_006ecb40_Class* FUN_006ecb40_Class::FUN_006ecb40()
{
    FUN_006ecc00();
    *reinterpret_cast<long*>(this) = (long)&DAT_0106d698;
    *reinterpret_cast<long*>(reinterpret_cast<char*>(this) + 4) = 0;
    return this;
}

namespace fnv_006ecb70 {
void __cdecl FUN_006ecc20();
extern void* DAT_0106d6f0;

struct FUN_006ecb70_Class
{
    void* m_vtbl;
    int m_field;
    void FUN_006ecc20();
    FUN_006ecb70_Class();
};

// Calls FUN_006ecc20, sets m_vtbl to &DAT_0106d6f0 and initializes m_field to 0.
// @fnv 0x006ecb70
FUN_006ecb70_Class::FUN_006ecb70_Class()
{
    FUN_006ecc20();
    m_vtbl = &DAT_0106d6f0;
    m_field = 0;
}
}  // namespace fnv_006ecb70

namespace fnv_006ecc00 {

struct FUN_006ecc00_Class
{
    void* FUN_006ecc00();
};

// @fnv 0x006ecc00
void* FUN_006ecc00_Class::FUN_006ecc00()
{
    *(void**)this = &(*reinterpret_cast<void * *>(&::DAT_0106d6b8));
    return this;
}
}  // namespace fnv_006ecc00

namespace fnv_006ecc20 {

struct FUN_006ecc20_Class
{
    void* FUN_006ecc20();
};

// @fnv 0x006ecc20
void* FUN_006ecc20_Class::FUN_006ecc20()
{
    *(void**)this = &(*reinterpret_cast<void * *>(&::DAT_0106d710));
    return this;
}
}  // namespace fnv_006ecc20

extern int DAT_0106d7a0;

struct FUN_006ecf20_Class
{
    void FUN_006ecf20();
};

// @fnv 0x006ecf20
void FUN_006ecf20_Class::FUN_006ecf20()
{
    *(int*)this = (int)&DAT_0106d7a0;
}

struct FUN_006ed0e0_Class
{
    int FUN_006ed0e0();
};
// @fnv 0x006ed0e0
int FUN_006ed0e0_Class::FUN_006ed0e0()
{
    *(int*)((char*)this + 8) = 0;
    return (int)this;
}

struct PathingLocation;
struct PathingSolution
{
};
struct FUN_006ed7a0_Class
{
    void FUN_006ed7a0(const PathingLocation&);
};
namespace fnv_006f25b0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_006f25b0();
};

// @fnv 0x006f25b0
void GlobalObject_00869f00::FUN_006f25b0()
{
    *reinterpret_cast<const char**>(this) = "0/o";
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_006f25b0

namespace fnv_006f26d0 {
struct GlobalObject_00869f00
{
    void Clear(bool a1);
};
struct FUN_006f26d0_Class
{
    void FUN_006f26d0();
};
// @fnv 0x006f26d0
void FUN_006f26d0_Class::FUN_006f26d0()
{
    *reinterpret_cast<long*>(this) = (long)&DAT_0106d828;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_006f26d0

namespace fnv_006f27f0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_006f27f0();
};
// @fnv 0x006f27f0
void GlobalObject_00869f00::FUN_006f27f0()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0106d850;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_006f27f0

namespace fnv_006f2e00 {
struct GlobalObject_00869f00
{
    void Clear(bool a1);
    void FUN_006f2e00();
};
// @fnv 0x006f2e00
void GlobalObject_00869f00::FUN_006f2e00()
{
    *reinterpret_cast<int**>(this) = &::DAT_0106d88c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_006f2e00


struct FUN_006f2e20_Class
{
    void* FUN_006f2e20(void* ptr, int count);
};

// @fnv 0x006f2e20
void* FUN_006f2e20_Class::FUN_006f2e20(void* ptr, int count)
{
    return Reallocate(ptr, count * 16);
}

struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};
struct FUN_006f30e0_Class
{
    AX* FUN_006f30e0();
};
// @fnv 0x006f30e0
AX* FUN_006f30e0_Class::FUN_006f30e0()
{
    *reinterpret_cast<unsigned int*>(this) = (unsigned int)"0/o";
    ((AX*)this)->FUN_006b3eb0(0, 0);
    return (AX*)this;
}

namespace fnv_006f3110 {
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_006f3110_Class : AX
{
    FUN_006f3110_Class* FUN_006f3110();
};
// @fnv 0x006f3110
FUN_006f3110_Class* FUN_006f3110_Class::FUN_006f3110()
{
    *reinterpret_cast<int*>(this) = (int)&::fnv_006f26d0::DAT_0106d828;
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_006f3110

namespace fnv_006f3140 {
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};


struct FUN_006f3140_Class
{
    void* vtable;
    FUN_006f3140_Class* FUN_006f3140();
};

// Sets the vtable to DAT_0106d850, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x006f3140
FUN_006f3140_Class* FUN_006f3140_Class::FUN_006f3140()
{
    vtable = &::fnv_006f27f0::DAT_0106d850;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_006f3140


struct FUN_006f3320_Class
{
    void InitBuffer(int a1, int a2);
    FUN_006f3320_Class* FUN_006f31c0();
};

// @fnv 0x006f31c0
FUN_006f3320_Class* FUN_006f3320_Class::FUN_006f31c0()
{
    *reinterpret_cast<void**>(this) = &DAT_0106d88c;
    InitBuffer(0, 0);
    return this;
}

struct ScrapHeapBuffer
{
    int m;
};
struct FUN_00aa5410_Helper
{
    ScrapHeapBuffer* InitWithAlignedSize(unsigned int);
};
struct FUN_006f4320_Class : public ScrapHeapBuffer
{
    ScrapHeapBuffer* FUN_006f4320();
};
// @fnv 0x006f4320
ScrapHeapBuffer* FUN_006f4320_Class::FUN_006f4320()
{
    ((FUN_00aa5410_Helper*)this)->InitWithAlignedSize(0x7000);
    return this;
}

namespace fnv_006f4640 {
struct GlobalObject_00869f00
{
    void Clear(bool a1);
    void FUN_006f4640();
};
// @fnv 0x006f4640
void GlobalObject_00869f00::FUN_006f4640()
{
    *(const char**)this = "`Fo";
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_006f4640

namespace fnv_006f4880 {
struct AX
{
    void FUN_006b3eb0(unsigned int a1, unsigned int a2);
};

struct FUN_006f4880_Class
{
    AX* FUN_006f4880();
};

// @fnv 0x006f4880
AX* FUN_006f4880_Class::FUN_006f4880()
{
    *reinterpret_cast<unsigned int*>(this) = (unsigned int)"`Fo";
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return reinterpret_cast<AX*>(this);
}
}  // namespace fnv_006f4880

struct Dummy_0061bf20
{
    Dummy_0061bf20* FUN_006f4b10();
};
// @fnv 0x006f4b10
Dummy_0061bf20* Dummy_0061bf20::FUN_006f4b10()
{
    *(int*)this = (int)&DAT_0106d974;
    reinterpret_cast<::FUN_006b3f40_Class *>((this))->FUN_006b3f40(0, 0);
    return this;
}

namespace fnv_006f4b40 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006f4b40_Class
{
    int* m_p;
    void FUN_006f4b40();
};
// @fnv 0x006f4b40
void FUN_006f4b40_Class::FUN_006f4b40()
{
    m_p = &::DAT_0106d974;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_006f4b40

struct FUN_006f4b60_Class
{
    void* FUN_006f4b60();
};
namespace fnv_006f4b90 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006f4b90_Class : GlobalObject_00869f00
{
    int* m_00;
    void FUN_006f4b90();
};
// @fnv 0x006f4b90
void FUN_006f4b90_Class::FUN_006f4b90()
{
    m_00 = &(*reinterpret_cast<int *>(&::DAT_0106d988));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_006f4b90

void* __cdecl operator new(unsigned int);

struct FUN_006f4bb0_Class
{
    void* FUN_006f4bb0(int a1);
};

// Allocates a block of a1 << 4 bytes via operator new and returns the pointer.
// @fnv 0x006f4bb0
void* FUN_006f4bb0_Class::FUN_006f4bb0(int a1)
{
    void* p = operator new((unsigned int)(a1 << 4));
    return p;
}

namespace fnv_006f4ed0 {
struct NiPoint3
{
    float x, y, z;
};
struct PathingLocation
{
    void FUN_006f4ed0(const NiPoint3* aLocation);
};
// Copies the given NiPoint3 into the NiPoint3 stored at offset 4 of this object.
// @fnv 0x006f4ed0
void PathingLocation::FUN_006f4ed0(const NiPoint3* aLocation)
{
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 4) = *aLocation;
}
}  // namespace fnv_006f4ed0

namespace fnv_006f7780 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006f7780_Class
{
    void FUN_006f7780();
};
// @fnv 0x006f7780
void FUN_006f7780_Class::FUN_006f7780()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x34))))->Clear(true);
}
}  // namespace fnv_006f7780

extern int DAT_0106df38;
struct FUN_006f98c0_Class
{
};
struct FUN_006f9680_Class
{
    int m_iWordAt00;
    int FUN_006f9680(int a1);
};
extern int DAT_0106df58;
struct FUN_006f9a00_Class
{
    void FUN_006f9a00(int a2);
};
struct FUN_006f96b0_Class
{
    int* FUN_006f96b0(int a1);
};

struct FUN_006f9740_Class
{
    FUN_006f9740_Class* FUN_006f9740();
};

namespace fnv_006f9770 {
struct GlobalObject_00869f00
{
    void Clear(bool a1);
    void FUN_006f9770();
};
// @fnv 0x006f9770
void GlobalObject_00869f00::FUN_006f9770()
{
    *reinterpret_cast<long*>(this) = (long)&::DAT_0106df78;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(true);
}
}  // namespace fnv_006f9770


struct FUN_006f9850_Class
{
    void* FUN_006f9850(void* p, unsigned int count);
};

// @fnv 0x006f9850
void* FUN_006f9850_Class::FUN_006f9850(void* p, unsigned int count)
{
    return Reallocate(p, count * 32);
}

namespace fnv_006f9870 {
struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};
struct FUN_006f9870_Class
{
    AX* self;
    AX* FUN_006f9870();
};
// @fnv 0x006f9870
AX* FUN_006f9870_Class::FUN_006f9870()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106df8c);
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return reinterpret_cast<AX*>(this);
}
}  // namespace fnv_006f9870

namespace fnv_006f98a0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006f98a0_Class
{
    void FUN_006f98a0();
};
// @fnv 0x006f98a0
void FUN_006f98a0_Class::FUN_006f98a0()
{
    *(int*)this = (int)&::fnv_006f9870::DAT_0106df8c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_006f98a0

extern int DAT_0106dfe0;
struct FUN_006fa180_Class
{
};

struct FUN_006fa100_Class
{
    FUN_006fa100_Class* FUN_006fa100();
};

extern int DAT_0106dfe0;
struct FUN_006f9c70_shell
{
    void FUN_006f9c70(bool a1);
};
struct FUN_006fa160_Class
{
    void FUN_006fa160();
};
// @fnv 0x006fa160
void FUN_006fa160_Class::FUN_006fa160()
{
    *reinterpret_cast<int**>(this) = &DAT_0106dfe0;
    reinterpret_cast<FUN_006f9c70_shell*>(this)->FUN_006f9c70(true);
}

struct NiBinaryStream
{
};

struct FUN_006fc920_Class
{
    int ReadFromStream(NiBinaryStream* a1);
};

// @fnv 0x006fc920
int FUN_006fc920_Class::ReadFromStream(NiBinaryStream* a1)
{
    *(unsigned int*)((char*)this + 0x148) = reinterpret_cast<::FUN_00462d80_shell *>((((NiBinaryStream*)this)))->ReadBytes((void*)a1, 2);
    return (int)this;
}

namespace fnv_006fc950 {
struct NiBinaryStream
{
};

struct FUN_006fc950_Class : NiBinaryStream
{
    int FUN_006fc950(int a1);
};

// @fnv 0x006fc950
int FUN_006fc950_Class::FUN_006fc950(int pBuffer)
{
    *(int*)((char*)this + 0x148) = reinterpret_cast<::FUN_00462d80_shell *>(this)->ReadBytes((void*)pBuffer, 4);
    return (int)this;
}
}  // namespace fnv_006fc950

void __cdecl FUN_006fda10();
struct FUN_006fca70_Class
{
    void FUN_006fca70();
    void* m_p;
};
// @fnv 0x006fca70
void FUN_006fca70_Class::FUN_006fca70()
{
    if (*(void**)((char*)this + 4))
        ((void(*)(void*))FUN_006fda10)(*(void**)((char*)this + 4));
}

struct FUN_006ff880_Class
{
    void FUN_006ff880(unsigned char a1);
};

// @fnv 0x006ff880
void FUN_006ff880_Class::FUN_006ff880(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x3e) = aucValue;
}

extern int DAT_0106e7b4;

struct FUN_006ff970_Class
{
    int* m_p;
    char m_kPointB;
    int m_i;
    FUN_006ff970_Class();
};

// Initializes the object: points m_p at DAT_0106e7b4 and zeroes the byte and int members.
// @fnv 0x006ff970
FUN_006ff970_Class::FUN_006ff970_Class()
{
    m_p = &DAT_0106e7b4;
    m_kPointB = 0;
    m_i = 0;
}

extern int DAT_0106e7a4;
struct FUN_006ffc00_Class
{
    void UnregisterSteamCallback();
    void FUN_006ff9a0();
};
// @fnv 0x006ff9a0
void FUN_006ffc00_Class::FUN_006ff9a0()
{
    *(int*)this = (int)&DAT_0106e7a4;
    if (*(unsigned char*)((char*)this + 4) & 1)
        UnregisterSteamCallback();
}

extern int DAT_0106e7c4;
struct FUN_006ffa40_Class
{
    int m_vtbl;
    bool m_flag;
    void FUN_006ffa40();
};
// Sets the vtable pointer to DAT_0106e7c4 and, if m_flag bit 0 is set, calls UnregisterSteamCallback.
// @fnv 0x006ffa40
void FUN_006ffa40_Class::FUN_006ffa40()
{
    m_vtbl = (int)&DAT_0106e7c4;
    if (m_flag & 1)
        reinterpret_cast<::FUN_006ffc00_Class *>(this)->UnregisterSteamCallback();
}

extern "C" void* DAT_0106e7d4;
struct FUN_006ffac0_Class
{
    void FUN_006ffac0();
};
// @fnv 0x006ffac0
void FUN_006ffac0_Class::FUN_006ffac0()
{
    *reinterpret_cast<void**>(this) = &DAT_0106e7d4;
    if (reinterpret_cast<unsigned char*>(this)[4] & 1)
        reinterpret_cast<::FUN_006ffc00_Class *>((this))->UnregisterSteamCallback();
}

struct FUN_006ffb10_Class
{
    int FUN_006ffb10();
};

// @fnv 0x006ffb10
int FUN_006ffb10_Class::FUN_006ffb10()
{
    return 0x98;
}

extern void* DAT_0106ced8;
struct FUN_006e0ff0_Class : NiTPointerMap<int, int>
{
    void FUN_006e0ff0();
};
// @fnv 0x006e0ff0
void FUN_006e0ff0_Class::FUN_006e0ff0()
{
    *(void**)this = &DAT_0106ced8;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

namespace fnv_006e21b0 {
struct FUN_006e21b0_Class : NiTPointerMap<int, int>
{
    void ClearAndFreeStorage();
};
// Sets the map's vtable pointer, removes all entries, and frees the storage at this[2].
// @fnv 0x006e21b0
void FUN_006e21b0_Class::ClearAndFreeStorage()
{
    *reinterpret_cast<int**>(this) = &::DAT_0106cf88;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0((*reinterpret_cast<void**>(&this->m_ppkHashTable)));
}
}  // namespace fnv_006e21b0

extern int DAT_0106d63c;

struct FUN_006ecc40_Class
{
    int m0;
    int m4;
    int m8;
    FUN_006ecc40_Class();
};

// Initializes the object: stores the address of DAT_0106d63c in m0 and zeroes m4 and m8.
// @fnv 0x006ecc40
FUN_006ecc40_Class::FUN_006ecc40_Class()
{
    m0 = (int)&DAT_0106d63c;
    m4 = 0;
    m8 = 0;
}

extern int DAT_0106d7a0;

struct FUN_006ed010_Class
{
    int* p;
    int a;
    int b;
    int* FUN_006ed010();
};

// Initializes the object: sets p to point at DAT_0106d7a0 and zeroes a and b, then returns this.
// @fnv 0x006ed010
int* FUN_006ed010_Class::FUN_006ed010()
{
    p = &DAT_0106d7a0;
    a = 0;
    b = 0;
    return (int*)this;
}

struct FUN_006e0f90_Class
{
    void* FUN_006e0ef0(unsigned int flags);
};
void __cdecl Deallocate(void*);

void __cdecl _Deallocate(void*);
struct FUN_006e11f0_Class
{
    void* FUN_006e11f0(unsigned int);
};
// Calls FUN_006e0ff0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006e11f0
void* FUN_006e11f0_Class::FUN_006e11f0(unsigned int flags)
{
    ((FUN_006e0ff0_Class*)this)->FUN_006e0ff0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct S006e1220 : GlobalObject_00869f00
{
    void* FUN_006e1220(unsigned int);
};
// @fnv 0x006e1220
void* S006e1220::FUN_006e1220(unsigned int flags)
{
    FUN_006e1050();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006e10a0_shell
{
};
void __cdecl Deallocate(void*);
struct FUN_006e1250_Class
{
    void* FUN_006e1250(unsigned int a1);
};
// Calls FUN_006e10a0 on this, frees this when bit 0 of a1 is set, and returns this.
// @fnv 0x006e1250
void* FUN_006e1250_Class::FUN_006e1250(unsigned int auiFlags)
{
    reinterpret_cast<::fnv_006e10a0::FUN_006e10a0_Class *>((((FUN_006e10a0_shell*)this)))->FUN_006e10a0();
    if (auiFlags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl operator new(unsigned int, void*);
struct FUN_006e1280_Class
{
    void FUN_006e1280(char* a1, unsigned int a2);
};
// @fnv 0x006e1280
void FUN_006e1280_Class::FUN_006e1280(char* apBuffer, unsigned int auiCount)
{
    unsigned int i = 0;
    for (; i < auiCount; ++i)
    {
        void* p = ::FUN_006e6da0(1, apBuffer + i);
    }
}

struct FUN_006e20e0_Class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006e20e0_Class(int a1);
};
// Calls FUN_006e20e0 with a1, stores the address of DAT_0106cf68 in m, and returns this.
// @fnv 0x006e2080
int FUN_006e2080_Class::FUN_006e2080(int a1)
{
    new ((void *)this) ::FUN_006e20e0_Class(a1);
    m = (int)&DAT_0106cf68;
    return (int)this;
}
// Sets the vtable, stores a1 and zeroes a newly allocated buffer of a1*4 bytes.
// @fnv 0x006e20e0
FUN_006e20e0_Class::FUN_006e20e0_Class(int aiCount)
{
    m_vtbl = &DAT_0106cf88;
    m_iElementCount = aiCount;
    m_auiShapeKeys = 0;
    unsigned int n = m_iElementCount * 4;
    m_data = ::FUN_00aa1070(n);
    ::FUN_00403d30(m_data, 0, m_iElementCount * 4);
}

void __cdecl Deallocate(void* p);
struct FUN_006e21e0_Class
{
    FUN_006e21e0_Class* FUN_006e21e0(unsigned int flags);
};
// Calls ClearAndFreeStorage, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006e21e0
FUN_006e21e0_Class* FUN_006e21e0_Class::FUN_006e21e0(unsigned int flags)
{
    reinterpret_cast<::fnv_006e21b0::FUN_006e21b0_Class *>(this)->ClearAndFreeStorage();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_006e2280 {
struct StandInShell
{
};
struct NiPoint3
{
    int x;
    int y;
    int z;
};
struct FUN_006e2280_Class
{
    int m_iWordAt00;
    StandInShell m_shell;
    int m_iWordAt04[9];
    NiPoint3 m_2c;
    int m_38;
    int m_3c;
    FUN_006e2280_Class(void* a1, const NiPoint3& a2);
};
// @fnv 0x006e2280
FUN_006e2280_Class::FUN_006e2280_Class(void* pObject, const NiPoint3& a2)
{
    m_iWordAt00 = 0;
    reinterpret_cast<::StandInShell *>(&(m_shell))->FUN_006dcc40(pObject);
    m_2c = a2;
    m_38 = 0;
}
}  // namespace fnv_006e2280

struct PathingRequestClosePoint
{
    PathingRequestClosePoint();
    char _pad[0xB8];
};
extern int DAT_0106d414;
struct FUN_006e5fa0 : public PathingRequestClosePoint
{
    int m_B8;
    FUN_006e5fa0();
};
// @fnv 0x006e5fa0
FUN_006e5fa0::FUN_006e5fa0()
{
    *(int*)this = (int)&DAT_0106d414;
    m_B8 = 0;
}

struct _Mem_2064
{
    ~_Mem_2064();
};
struct FUN_006e62b0_Class
{
    virtual ~FUN_006e62b0_Class();
    _Mem_2064 m1;
    char pad[0x27];
    _Mem_2064 m2;
};
// Destructor for the class; destroys the two embedded _Mem_2064 members and does nothing else.
// @fnv 0x006e62b0
FUN_006e62b0_Class::~FUN_006e62b0_Class()
{}

struct S006e7620_R2
{
};
struct S006e7620_R1
{
};
S006e7620_R1* __cdecl _FUN_00c85750();
// @fnv 0x006e7620
void __cdecl FUN_006e7620(int aiSize, const char* what)
{
    S006e7620_R1* mem = _FUN_00c85750();
    reinterpret_cast<::S_005e0ad0 *>((((::S006e7620_R2 *)(new ((void *)(mem)) ::Vec3()))))->FUN_005e0ad0({}, {});
}

struct FUN_006e9000_Class
{
    float m_iWordAt00;
    float m_cByteAtOffset1;
    float m_cByteAtOffset2;
    float m_cByteAtOffset3;
    float m_iWordAt04;
    float ComputeWeightedSum(float* a1, float* a2, float* a3, float* a4);
};
// @fnv 0x006e9000
float FUN_006e9000_Class::ComputeWeightedSum(float* apFirst, float* apThird, float* apSecond, float* apFourth)
{
    return m_cByteAtOffset1 * *apFirst + m_cByteAtOffset2 * *apSecond + m_cByteAtOffset3 * *apThird +
           m_iWordAt04 * *apFourth;
}

struct FUN_006e9260
{
    ~FUN_006e9260();
};
void __cdecl Deallocate(void*);
struct FUN_006e9500_Class : public FUN_006e9260
{
    void* FUN_006e9500(unsigned int flags);
};
// Runs the base destructor, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006e9500
void* FUN_006e9500_Class::FUN_006e9500(unsigned int flags)
{
    reinterpret_cast<::FUN_006e9260Class *>(this)->FUN_006e9260();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_006e9530 {
struct PathingLocation
{
    char _pad[40];
    PathingLocation& operator=(PathingLocation const&);
};
struct FUN_006e9530_Struct
{
    int f0;
    PathingLocation f4;
    int f2c;
    FUN_006e9530_Struct& FUN_006e9530(const FUN_006e9530_Struct&);
};
// Copies f0, f4 and f2c from a1 into this object and returns *this.
// @fnv 0x006e9530
FUN_006e9530_Struct& FUN_006e9530_Struct::FUN_006e9530(const FUN_006e9530_Struct& aOther)
{
    f0 = aOther.f0;
    f4 = aOther.f4;
    f2c = aOther.f2c;
    return *this;
}
}  // namespace fnv_006e9530

struct HostA
{
    bool DispatchToInner(int, bool);
};
struct FUN_006ebbd0_Cls
{
    HostA* h;
    bool ForwardToHost(int, bool);
};
// Calls DispatchToInner on the stored host pointer with the given arguments and returns its bool result.
// @fnv 0x006ebbd0
bool FUN_006ebbd0_Cls::ForwardToHost(int aiArg, bool abFlag)
{
    return h->DispatchToInner(aiArg, abFlag);
}

struct FUN_006ebbf0_Class
{
    void FUN_006ebbf0(void* a1, void* a2, void* a3, void* a4, bool a5);
};

// Forwards the five arguments to the CallVirtualObjectMethod method of the object stored at this's first pointer slot.
// @fnv 0x006ebbf0
void FUN_006ebbf0_Class::FUN_006ebbf0(void* a1, void* a2, void* a3, void* a4, bool a5)
{
    reinterpret_cast<::FUN_006eb250_Class *>((((FUN_006ebbf0_Class**)((FUN_006ebbf0_Class*)this))[0]))->CallVirtualObjectMethod((int)(a1), (int)(a2), (int)(a3), (int)(a4), a5);
}

struct FUN_006eb2b0_Callee
{
};
struct Host_006ebc20
{
    FUN_006eb2b0_Callee* m;
    void FUN_006ebc20(int a1, int a2, int a3, int a4);
};
// Forwards all four arguments to the callee's ProcessKeyedItem method through the m pointer.
// @fnv 0x006ebc20
void Host_006ebc20::FUN_006ebc20(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    reinterpret_cast<::EB2B0Owner *>((m))->ProcessKeyedItem(aiArg1, aiArg2, aiArg3, aiArg4);
}

struct SeqObj
{
};
struct G00559a40
{
};
struct FUN_006ebfb0_Class
{
    int* m_p;
    int* AssignPointer(int** other);
};
// @fnv 0x006ebfb0
int* FUN_006ebfb0_Class::AssignPointer(int** other)
{
    if (m_p != *other)
    {
        if (m_p)
            reinterpret_cast<::WaitableObject *>((((SeqObj*)((char*)m_p + 0x14))))->FUN_00401970();
        m_p = *other;
        if (m_p)
            reinterpret_cast<::FUN_0040f6e0_class *>((((G00559a40*)((char*)m_p + 0x14))))->FUN_0040f6e0();
    }
    return (int*)this;
}

extern int DAT_0106d678;
struct FUN_006ec090_Class
{
    int f0;
    int f4;
    int f8;
    int fC;
    void* f10;
    FUN_006ec090_Class* FUN_006ec090(int a1);
};
// @fnv 0x006ec090
FUN_006ec090_Class* FUN_006ec090_Class::FUN_006ec090(int aiValue)
{
    ((FUN_006ecb40_Class*)this)->FUN_006ecb40();
    *(int*)this = (int)&DAT_0106d678;
    this->f8 = aiValue;
    this->fC = 0;
    this->f10 = (void*)((char*)&this->fC);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_006ec200_Class
{
    void FUN_006ec1c0();
    void* FUN_006ec200(unsigned int flags);
};

// @fnv 0x006ec200
void* FUN_006ec200_Class::FUN_006ec200(unsigned int flags)
{
    FUN_006ec1c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Call_6ecb70
{
};
struct Holder_6ec340
{
    Holder_6ec340* FUN_006ec340();
};
// @fnv 0x006ec340
Holder_6ec340* Holder_6ec340::FUN_006ec340()
{
    new ((void *)(((Call_6ecb70*)this))) ::fnv_006ecb70::FUN_006ecb70_Class();
    *(int*)this = (int)&DAT_0106d6d0;
    *(int*)((char*)this + 0x408) = 0;
    *(int*)((char*)this + 0x40C) = 0;
    *(int*)((char*)this + 0x410) = 0;
    return this;
}

struct FUN_006ec390_Class
{
    bool FUN_006ec390(int a1);
};
// @fnv 0x006ec390
bool FUN_006ec390_Class::FUN_006ec390(int aiArg)
{
    bool result;
    if (FUN_0043b460((long volatile*)this + 1, 0, 1) == 0)
    {
        ::FUN_0040fbe0();
        result = ((bool(*)(void*, int))(*(void***)this)[6])(this, aiArg);
        ::FUN_0040fbe0();
        FUN_0043b460((long volatile*)this + 1, 1, 0);
    }
    else
    {
        result = false;
    }
    return result;
}

void __cdecl operator delete(void*);

struct FUN_006ec410_Helper
{
};

struct FUN_006ec450_Class
{
    void* FUN_006ec450(unsigned int a1);
};

// Calls FUN_006ec430 on this, deletes this when bit 0 of a1 is set, and returns this.
// @fnv 0x006ec450
void* FUN_006ec450_Class::FUN_006ec450(unsigned int uiFlags)
{
    reinterpret_cast<::FUN_006ec410_Class *>((((FUN_006ec410_Helper*)this)))->FUN_006ec410_Class::~FUN_006ec410_Class();
    if (uiFlags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006ec480_Class : public FUN_006ec410_Class
{
    void* FUN_006ec480(unsigned int flags);
};
// Calls FUN_006ec430, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006ec480
void* FUN_006ec480_Class::FUN_006ec480(unsigned int flags)
{
    reinterpret_cast<::FUN_006ec430_Class *>(this)->FUN_006ec430();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0044df00Class
{
    int* FUN_0044df00();
};
struct FUN_0044df20
{
    bool Call();
};
struct FUN_00529000_Class
{
};
struct FUN_006ec9b0_Class
{
    bool FUN_006ec9b0(int a1, int a2, int* a3);
};
// @fnv 0x006ec9b0
bool FUN_006ec9b0_Class::FUN_006ec9b0(int a1, int a2, int* piOut)
{
    bool r = reinterpret_cast<::Worker *>(this)->ProcessNodeChain(a1, a2);
    if (r)
    {
        *piOut = ((FUN_0044df00Class*)((char*)this + 0x14))->FUN_0044df00()[1];
        ::FUN_0040fbe0();
        if (((FUN_0044df20*)((FUN_0044df00Class*)((char*)this + 0x14))->FUN_0044df00())->Call())
            r = false;
    }
    reinterpret_cast<::FUN_00529000_cls *>((((FUN_00529000_Class*)this)))->FUN_00529000();
    return r;
}

void __cdecl Deallocate(void*);
struct FUN_006ec130_Class
{
    void FUN_006ec130();
    void* FUN_006eca80(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct FUN_006ecab0_Class
{
    void* FUN_006ecab0(unsigned int);
};
// Calls FUN_006ec3f0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006ecab0
void* FUN_006ecab0_Class::FUN_006ecab0(unsigned int flags)
{
    ((FUN_006ec3f0_Class*)this)->FUN_006ec3f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_006ec870_Class
{
    void* FUN_006ecae0(unsigned int flags);
};
// @fnv 0x006ecae0
void* FUN_006ec870_Class::FUN_006ecae0(unsigned int flags)
{
    reinterpret_cast<::FUN_006ec870 *>(this)->FUN_006ec870::~FUN_006ec870();
    if (flags & 1)
        Deallocate(this);
    return this;
}

class QueuedMessage;
template <class T> struct BSTFreeListElement
{
    void FUN_006ecce0();
};
template <class T> struct BSTFreeList
{
    void PushFront(BSTFreeListElement<T>*&);
    void FUN_006ecb10(BSTFreeListElement<T>*&);
};
// Calls FUN_006ecce0 on the node then passes it to PushFront.
// @fnv 0x006ecb10
void BSTFreeList<QueuedMessage>::FUN_006ecb10(BSTFreeListElement<QueuedMessage>*& pNode)
{
    pNode->FUN_006ecce0();
    PushFront(pNode);
}

struct CF_0081c630
{
    void Init();
    CF_0081c630();
};
struct FUN_006ecbd0_Class
{
    int m0;
    int m4;
    CF_0081c630 m8;
    FUN_006ecbd0_Class* InitFromValues(int a, int* b);
};
// Initializes the embedded object via Init, then stores a into m0 and the value pointed to by b into m4, returning this.
// @fnv 0x006ecbd0
FUN_006ecbd0_Class* FUN_006ecbd0_Class::InitFromValues(int aiValue, int* piValue)
{
    ::FUN_0044dee0((::BGSLoadGameSubBuffer *)&(m8));
    m0 = aiValue;
    m4 = *piValue;
    return this;
}

struct FUN_006ecd60_stub
{
    bool FUN_006ecd00(void** a1, int a2);
};
struct FUN_006ece00_Obj
{
    void AssignFrom(int);
};
void __cdecl _Deallocate(void*);
struct FUN_006ecf40_Class
{
    void* FUN_006ecf40(unsigned int);
};
// Calls FUN_006ecf20 on this, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006ecf40
void* FUN_006ecf40_Class::FUN_006ecf40(unsigned int flags)
{
    ((FUN_006ecf20_Class*)this)->FUN_006ecf20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NiBound
{
    NiBound();
};
struct ref_006815c0
{
    ref_006815c0();
};
struct FUN_006ee100_Class
{
    int a;
    int b;
    ref_006815c0 m_08;
    int c;
    int d;
    int e;
    int f;
    ref_006815c0 m_14;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    ref_006815c0 m_20;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    ref_006815c0 m_2c;
    int w;
    int x;
    int y;
    int z;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    NiBound m_3c;
    FUN_006ee100_Class* FUN_006ee100();
};
// Constructs the object by initializing the four ref_006815c0 subobjects at offsets 8, 0x14, 0x20 and 0x2c and the NiBound at 0x3c, then returns this.
// @fnv 0x006ee100
FUN_006ee100_Class* FUN_006ee100_Class::FUN_006ee100()
{
    new ((void *)((&this->m_08))) ::Vec3();
    new ((void *)(((ref_006815c0*)&this->e))) ::Vec3();
    new ((void *)(((ref_006815c0*)&this->g))) ::Vec3();
    new ((void *)(((ref_006815c0*)&this->j))) ::Vec3();
    ::FUN_006240d0((void *)(((NiBound*)&this->n)));
    return this;
}

struct B006815c0
{
    char d[12];
    B006815c0();
};
struct FUN_006efd50
{
    char _p[12];
    B006815c0 m[2];
    FUN_006efd50();
};
// @fnv 0x006efd50
FUN_006efd50::FUN_006efd50()
{}

struct S006F1E90
{
    bool FUN_006f1e90(int, int);
};
extern int DAT_0106d814;
struct FUN_006f26d0_Class
{
    virtual ~FUN_006f26d0_Class();
};
struct FUN_006f26f0_Class : public FUN_006f26d0_Class
{
    void Clear(bool a1);
    ~FUN_006f26f0_Class();
};
// @fnv 0x006f26f0
FUN_006f26f0_Class::~FUN_006f26f0_Class()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct ScrapHeapHelper
{
    void* Allocate(unsigned int a1, unsigned int a2);
};
struct BSScrapArray
{
    char _pad[16];
    void* m_pPoolBase;
    void* AllocateElements(unsigned int a1);
};
struct ScrapHeap_Allocate_Helper
{
    void* Allocate(unsigned int, unsigned int);
};
struct FUN_006f2c10_Holder
{
    int _00;
    int _04;
    int _08;
    int _0c;
    ScrapHeapBuffer* _10;
    void* FUN_006f2c10(int);
};
struct ArrSI
{
};
struct FUN_00aa54a0_s
{
    void* Allocate(unsigned int, unsigned int);
public:
    void *FUN_00aa54a0(unsigned int, unsigned int);
};
// @fnv 0x006f2870
void* BSScrapArray::AllocateElements(unsigned int auiCount)
{
    void* r;
    r = reinterpret_cast<::FUN_00aa54a0_s *>((((ScrapHeapHelper*)m_pPoolBase)))->FUN_00aa54a0(auiCount << 2, DAT_010a2720);
    return r;
}
// Allocates a block of a1 * 0x28 bytes from the scrap heap via the helper at _10 and returns it.
// @fnv 0x006f2c10
void* FUN_006f2c10_Holder::FUN_006f2c10(int aiCount)
{
    void* p;
    p = reinterpret_cast<::FUN_00aa54a0_s *>((((ScrapHeap_Allocate_Helper*)_10)))->FUN_00aa54a0(aiCount * 0x28, DAT_010a2720);
    return p;
}
struct FUN_006f2c40_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_00aa54a0_s* m_pStreamAllocator;
    void* ReallocateArray(int a1, int a2);
};
void* __cdecl __memcpy(void* dst, const void* src, unsigned int n);
// Allocates a new block of a2*0x28 bytes, copies GetFlags()*0x28 bytes from a1 into it, frees a1 and returns the new block.
// @fnv 0x006f2c40
void* FUN_006f2c40_Class::ReallocateArray(int pOldBuffer, int a2)
{
    void* dst = m_pStreamAllocator->FUN_00aa54a0(a2 * 0x28, DAT_010a2720);
    __memcpy(dst, (const void*)pOldBuffer, ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())) * 0x28);
    reinterpret_cast<::SHStub *>((m_pStreamAllocator))->FUN_00aa5610((void*)pOldBuffer);
    return dst;
}

struct AllocHelper_006f2ea0
{
    void* Allocate(unsigned int, unsigned int);
};
struct Host_006f2ea0
{
    unsigned char _pad[16];
    AllocHelper_006f2ea0* _heap;
    void* FUN_006f2ea0(int);
};
// Allocates a block of a1 << 4 bytes from the heap with DAT_010a2720 and returns the pointer.
// @fnv 0x006f2ea0
void* Host_006f2ea0::FUN_006f2ea0(int aiCount)
{
    void* r;
    r = reinterpret_cast<::FUN_00aa54a0_s *>((_heap))->FUN_00aa54a0(aiCount << 4, DAT_010a2720);
    return r;
}

namespace fnv_006f2ed0 {
struct ArrSI
{
};
void* __cdecl __memcpy(void* dst, const void* src, unsigned int n);
struct FUN_00aa54a0_s
{
};
struct FUN_006f2ed0_Class
{
    void* FUN_006f2ed0(const void* src, unsigned int n);
};
// @fnv 0x006f2ed0
void* FUN_006f2ed0_Class::FUN_006f2ed0(const void* src, unsigned int n)
{
    void* p = reinterpret_cast<::FUN_00aa54a0_s *>((reinterpret_cast<FUN_00aa54a0_s*>(*(void**)((char*)this + 0x10))))->FUN_00aa54a0(n << 4, ::DAT_010a2720);
    __memcpy(p, src, ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(this)))->GetName())) << 4);
    reinterpret_cast<::SHStub *>((reinterpret_cast<FUN_00aa54a0_s*>(*(void**)((char*)this + 0x10))))->FUN_00aa5610((void*)src);
    return p;
}
}  // namespace fnv_006f2ed0

struct FUN_006f25b0
{
    virtual ~FUN_006f25b0();
    void* FUN_006f2f30(unsigned int);
};
void _Deallocate(void*);
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x006f2f30
void* FUN_006f25b0::FUN_006f2f30(unsigned int flags)
{
    reinterpret_cast<::fnv_006f25b0::GlobalObject_00869f00 *>((this))->FUN_006f25b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006f25d0
{
    ~FUN_006f25d0();
};
void __cdecl _Deallocate(void*);
struct FUN_006f2f60_shell : public FUN_006f25d0
{
    void* FUN_006f2f60(unsigned int);
};
// Runs the destructor, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006f2f60
void* FUN_006f2f60_shell::FUN_006f2f60(unsigned int flags)
{
    this->FUN_006f25d0::~FUN_006f25d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006f2f90 {
extern "C" void __cdecl Deallocate(void*);
struct FUN_006f2f90_Class
{
    void* FUN_006f2f90(unsigned int flags);
};
// Calls FUN_006f26d0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x006f2f90
void* FUN_006f2f90_Class::FUN_006f2f90(unsigned int flags)
{
    reinterpret_cast<::fnv_006f26d0::FUN_006f26d0_Class *>(this)->FUN_006f26d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f2f90

namespace fnv_006f2fc0 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_006f2fc0_Class
{
    void* FUN_006f2fc0(unsigned int a1);
};

// Calls FUN_006f26f0, then deallocates this when bit 0 of a1 is set, and returns this.
// @fnv 0x006f2fc0
void* FUN_006f2fc0_Class::FUN_006f2fc0(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_006f26f0_Class *>(this)->FUN_006f26f0_Class::~FUN_006f26f0_Class();
    if (auiFlags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f2fc0

namespace fnv_006f2ff0 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_006f2ff0_Class
{
    void* FUN_006f2ff0(unsigned int flags);
};

// @fnv 0x006f2ff0
void* FUN_006f2ff0_Class::FUN_006f2ff0(unsigned int flags)
{
    reinterpret_cast<::fnv_006f27f0::GlobalObject_00869f00 *>(this)->FUN_006f27f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f2ff0

void __cdecl Deallocate(void* p);

struct FUN_006f2810_Class
{
    void FUN_006f2810();
    void* FUN_006f3020(unsigned int flags);
};

struct FUN_006f3050_Class
{
    void* FUN_006f3050(unsigned int flags);
};

namespace fnv_006f3080 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_006f3080_Class
{
    void* FUN_006f3080(unsigned int flags);
};

// @fnv 0x006f3080
void* FUN_006f3080_Class::FUN_006f3080(unsigned int flags)
{
    reinterpret_cast<::fnv_006f2e00::GlobalObject_00869f00 *>(this)->FUN_006f2e00();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f3080

struct FUN_006f2e40_Class
{
    void FUN_006f2e40();
    void* FUN_006f30b0(unsigned int flags);
};
void __cdecl Deallocate(void*);

struct FUN_006f3170_Class
{
    bool FUN_006f3170();
};
// @fnv 0x006f3170
bool FUN_006f3170_Class::FUN_006f3170()
{
    if (*(unsigned int*)((char*)this + 0xc) > 0x400)
    {
        if (*(unsigned int*)((char*)this + 8) <= *(unsigned int*)((char*)this + 0xc) - 0x800)
            return true;
    }
    else
    {
        if (*(unsigned int*)((char*)this + 8) <= *(unsigned int*)((char*)this + 0xc) >> 2)
            return true;
    }
    return false;
}

struct _Base_006f3c80
{
    ~_Base_006f3c80();
};

struct FUN_006f3f80_Class : public _Base_006f3c80
{
    void* FUN_006f3f80(unsigned int flags);
};

// Runs the base destructor, then frees this object with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006f3f80
void* FUN_006f3f80_Class::FUN_006f3f80(unsigned int flags)
{
    _Base_006f3c80::~_Base_006f3c80();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_006f4660 {
extern "C" void __cdecl Deallocate(void*);
struct FUN_006f4660_Class
{
    void* FUN_006f4640();
    void* FUN_006f4660(unsigned int flags);
};
// @fnv 0x006f4660
void* FUN_006f4660_Class::FUN_006f4660(unsigned int flags)
{
    reinterpret_cast<::fnv_006f4640::GlobalObject_00869f00 *>(this)->FUN_006f4640();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f4660

struct FUN_006f4690_Class
{
    void FUN_006f4690();
};
void __cdecl Deallocate(void*);
struct FUN_006f4850_Class
{
    void* FUN_006f4850(unsigned int flags);
};
struct FUN_006f4b40
{
    ~FUN_006f4b40();
    void* FUN_006f4be0(unsigned int);
};
// Runs the destructor and, when bit 0 of a1 is set, frees the object with operator delete; returns the pointer.
// @fnv 0x006f4be0
void* FUN_006f4b40::FUN_006f4be0(unsigned int auiFlags)
{
    reinterpret_cast<::fnv_006f4b40::FUN_006f4b40_Class *>((this))->FUN_006f4b40();
    if (auiFlags & 1)
        ::operator delete(this);
    return this;
}

struct FUN_006f4b90
{
    ~FUN_006f4b90();
    void* FUN_006f4c10(unsigned int);
};
void __cdecl _Deallocate(void*);
// Runs the destructor, then frees this object with _Deallocate when bit 0 of a1 is set, and returns this.
// @fnv 0x006f4c10
void* FUN_006f4b90::FUN_006f4c10(unsigned int auiFlags)
{
    reinterpret_cast<::fnv_006f4b90::FUN_006f4b90_Class *>((this))->FUN_006f4b90();
    if (auiFlags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006f4cd0 {
struct PathingLocation
{
    PathingLocation();
};

struct FUN_006f4cd0_Class
{
    int m_iWordAt00;
    PathingLocation m_loc;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    int m_iWordAt04;
    int m_5;
    int m_6;
    int m_7;
    int m_8;
    int m_9;
    int m_10;
    FUN_006f4cd0_Class();
};

// @fnv 0x006f4cd0
FUN_006f4cd0_Class::FUN_006f4cd0_Class()
{
    m_iWordAt00 = 0;
    m_10 = 0;
}
}  // namespace fnv_006f4cd0

struct FindTriangleForLocationFilter;
struct PathingLocationProxy
{
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
};
struct FUN_006f5020_Class
{
    int m_flags;
    PathingLocationProxy m_proxy;
    void UpdateProxyFlag();
};
// If m_flags bit 0 is clear and m_proxy's check returns true, sets bit 0 of m_flags.
// @fnv 0x006f5020
void FUN_006f5020_Class::UpdateProxyFlag()
{
    if (!(m_flags & 1) && m_proxy.FindContainingTriangle(0))
        m_flags |= 1;
}

namespace fnv_006f5060 {
struct PathingLocation
{
    PathingLocation& operator=(const PathingLocation&);
};
struct FindTriangleForLocationFilter;
struct PathingLocationProxy
{
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
};
struct FUN_006f5060_Class
{
    int m_type;
    PathingLocation m_loc;
    void SetLocation(const PathingLocation& location);
};
// @fnv 0x006f5060
void FUN_006f5060_Class::SetLocation(const PathingLocation& location)
{
    this->m_loc = location;
    m_type = 2;
    if (((PathingLocationProxy*)&this->m_loc)->FindContainingTriangle(0))
        m_type |= 1;
}
}  // namespace fnv_006f5060

namespace fnv_006f96e0 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_006f9940_Class
{
    void FUN_006f9940();
    void* FUN_006f96e0(unsigned int flags);
};

// @fnv 0x006f96e0
void* FUN_006f9940_Class::FUN_006f96e0(unsigned int flags)
{
    FUN_006f9940();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f96e0

struct FUN_006f9710_Class
{
    void FUN_006f9b80();
    void* FUN_006f9710(unsigned int a1);
};

extern int DAT_0106dfa0;
void __cdecl Deallocate(void*);
struct FUN_006f99a0_Class
{
    int m_vtbl;
    int m_auiShapeKeys;
    int m_i;
    void FUN_006f99a0();
};
// Sets the vtable pointer to DAT_0106dfa0 and, if m_i is non-null, deallocates the object it points to.
// @fnv 0x006f99a0
void FUN_006f99a0_Class::FUN_006f99a0()
{
    *reinterpret_cast<int**>(this) = &DAT_0106dfa0;
    if (m_i)
    {
        void* p = reinterpret_cast<void*>(m_i);
        Deallocate(p);
    }
}

struct FUN_006f9b80_shell
{
    virtual ~FUN_006f9b80_shell();
};
struct FUN_006f9b80 : public FUN_006f9b80_shell
{
    virtual ~FUN_006f9b80();
};
// Calls FUN_006f9b80, then deletes this when bit 0 of a1 is set, and returns this.
// @fnv 0x006f9710
void* FUN_006f9710_Class::FUN_006f9710(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_006f9b80 *>(this)->FUN_006f9b80::~FUN_006f9b80();
    if (auiFlags & 1)
        operator delete(this);
    return this;
}
// @fnv 0x006f9b80
FUN_006f9b80::~FUN_006f9b80()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

extern int DAT_0106dfc0;
void __cdecl Deallocate(void* p);
struct FUN_006f9be0_Class
{
    void FUN_006f9be0();
};
// @fnv 0x006f9be0
void FUN_006f9be0_Class::FUN_006f9be0()
{
    *reinterpret_cast<int**>(this) = &DAT_0106dfc0;
    void* tmp;
    if (reinterpret_cast<void**>(this)[2])
    {
        tmp = reinterpret_cast<void**>(this)[2];
        Deallocate(tmp);
    }
}

void __cdecl Deallocate(void*);
struct FUN_006f9770_Class
{
    FUN_006f9770_Class* FUN_006f9cd0(unsigned int flags);
};
// @fnv 0x006f9cd0
FUN_006f9770_Class* FUN_006f9770_Class::FUN_006f9cd0(unsigned int flags)
{
    reinterpret_cast<::fnv_006f9770::GlobalObject_00869f00 *>(this)->FUN_006f9770();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_006f9d00 {
extern "C" void __cdecl Deallocate(void*);
struct FUN_006f98a0_Class
{
    void* FUN_006f9d00(unsigned int flags);
};
// Calls FUN_006f98a0, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006f9d00
void* FUN_006f98a0_Class::FUN_006f9d00(unsigned int flags)
{
    reinterpret_cast<::fnv_006f98a0::FUN_006f98a0_Class *>(this)->FUN_006f98a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f9d00

namespace fnv_006f9d30 {
extern void __cdecl Deallocate(void*);

struct FUN_006f99a0_Class
{
    void* FUN_006f9d30(unsigned int a1);
};

// Calls FUN_006f99a0, then deallocates this if bit 0 of a1 is set, and returns this.
// @fnv 0x006f9d30
void* FUN_006f99a0_Class::FUN_006f9d30(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_006f99a0_Class *>(this)->FUN_006f99a0();
    if (auiFlags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006f9d30

void __cdecl Deallocate(void*);
struct FUN_006f9d60_Class
{
    void* FUN_006f9d60(unsigned int flags);
};
// @fnv 0x006f9d60
void* FUN_006f9d60_Class::FUN_006f9d60(unsigned int flags)
{
    reinterpret_cast<::FUN_006f9be0_Class *>(this)->FUN_006f9be0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_006fa0d0 {
extern "C" void __cdecl Deallocate(void*);
struct FUN_006fa0d0_Class
{
    void* FUN_006fa0d0(unsigned int flags);
};
// @fnv 0x006fa0d0
void* FUN_006fa0d0_Class::FUN_006fa0d0(unsigned int flags)
{
    reinterpret_cast<::FUN_006f9080_owner *>(this)->FUN_006f9080();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006fa0d0

void __cdecl Deallocate(void*);

struct GlobalObject_006fa100
{
    ~GlobalObject_006fa100();
    GlobalObject_006fa100* FUN_006fa130(unsigned int flags);
};

// Calls FUN_006fa160, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006fa130
GlobalObject_006fa100* GlobalObject_006fa100::FUN_006fa130(unsigned int flags)
{
    reinterpret_cast<::FUN_006fa160_Class *>((this))->FUN_006fa160();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006fa670_Target;
struct SoundListView
{
    void AddTail(FUN_006fa670_Target*&);
};
struct FUN_006fa670_Target
{
    void AddSelfToList();
};
// Appends this object to the list g_011d8624 via AddTail.
// @fnv 0x006fa670
void FUN_006fa670_Target::AddSelfToList()
{
    FUN_006fa670_Target* p = this;
    reinterpret_cast<::Callees *>(&((*reinterpret_cast<::SoundListView *>(&::g_011d8624))))->FUN_00905820((void *)&(p));
}

namespace fnv_006fa6a0 {
struct S006FA6A0;
struct List006FA6A0
{
};
struct S006FA6A0
{
    void FUN_006fa6a0();
};
// @fnv 0x006fa6a0
void S006FA6A0::FUN_006fa6a0()
{
    S006FA6A0* result = this;
    reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_006fa6a0::List006FA6A0 *>(&::g_011d8624))))->FUN_00905330((::InventoryStackRecord *const &)(result));
}
}  // namespace fnv_006fa6a0

struct Flt
{
    operator unsigned int();
};
struct Tile
{
    int _0;
    Flt _4;
    void SetNodeFloat(float);
};
// @fnv 0x006faa90
void Tile::SetNodeFloat(float afValue)
{
    NiNode* tmp;
    if ((unsigned int)_4)
    {
        tmp = ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>(this)->FUN_0056c7f0()));
        if (tmp)
            *(float*)((char*)tmp + 0x80) = afValue;
    }
}

struct FUN_006fd750
{
    void Unload();
};
void __cdecl Deallocate(void*);
struct FUN_006fca40_Class
{
    void* FUN_006fca40(unsigned int a1);
};
// Calls Unload on this object, then frees it via Deallocate when bit 0 of a1 is set, and returns this.
// @fnv 0x006fca40
void* FUN_006fca40_Class::FUN_006fca40(unsigned int auiFlags)
{
    ((FUN_006fd750*)this)->Unload();
    if (auiFlags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00759d80_Class
{
    unsigned char FUN_00759d80();
};
struct FORenderedMenu
{
};
struct FUN_006fea10_Class
{
    void* m_10;
    unsigned char FUN_006fea10(bool a1);
};
struct FUN_006ff660_Class
{
    int FUN_006ff660(int a1);
};
// If DAT_011d8794 is non-null, calls FUN_006ff660(1) on it, then sets DAT_011d8794 to 0.
// @fnv 0x006ff620
void __cdecl FUN_006ff620()
{
    int a = DAT_011d8794;
    int b5 = a;
    int c;
    if (b5)
        c = ((FUN_006ff660_Class*)b5)->FUN_006ff660(1);
    else
        c = 0;
    DAT_011d8794 = 0;
}

namespace fnv_006ff660 {
void __cdecl Deallocate(void*);
struct FUN_006ff660_Class
{
    void FUN_006ff7b0();
    void* FUN_006ff660(unsigned int flags);
};
// Calls FUN_006ff7b0, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006ff660
void* FUN_006ff660_Class::FUN_006ff660(unsigned int flags)
{
    FUN_006ff7b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006ff660

struct FUN_006ffb20_Class
{
};
struct FUN_006ff920 : public FUN_006ff970_Class
{
    FUN_006ff920(int a1, int a2);
};

struct FUN_006e3e70_Class
{
    void FUN_006e3e70(char* a, char* b, unsigned int c);
};

// @fnv 0x006e3e70
void FUN_006e3e70_Class::FUN_006e3e70(char* pDst, char* pSrc, unsigned int c)
{
    if (c <= 0)
        return;
    if (pDst < pSrc)
    {
        for (unsigned int i = 0; i < c; ++i)
            std::memmove(pDst + i * 0x24, pSrc + i * 0x24, 0x24);
    }
    else if (pDst > pSrc)
    {
        for (int i = c - 1; i >= 0; --i)
            std::memmove(pDst + i * 0x24, pSrc + i * 0x24, 0x24);
    }
}

struct SaveGameSizeState
{
    int iSize;
    int iPosition;
    int iDataLength;
    virtual int Write(unsigned int);
    virtual int Write2(unsigned int);
    void InitSizeState(unsigned int requested, unsigned int savedSize);
};
struct FUN_006e9700_Class
{
    virtual void* v0();
    virtual int v1(unsigned int a1);
    void ConstructArray(int a1, unsigned int a2);
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void FUN_006e97a0(unsigned int a1, unsigned int a2);
};
// @fnv 0x006e97a0
void FUN_006e9700_Class::FUN_006e97a0(unsigned int a1, unsigned int a2)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (a2 > a1)
        a1 = a2;
    if (a1 > 0)
    {
        m_iWordAt04 = v1(a1);
        m_iThirdValue = a1;
    }
    if (a2 > 0)
    {
        ConstructArray(m_iWordAt04, a2);
        m_8 = a2;
    }
}

struct FUN_006ec260_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int* m_10;
    bool FUN_006ec260(int a1);
};
// @fnv 0x006ec260
bool FUN_006ec260_Class::FUN_006ec260(int a1)
{
    bool r6;
    void* p2;
    if (m_8 && ((FUN_006ecd60_stub*)m_8)->FUN_006ecd00(&p2, a1))
    {
        if (!m_iThirdValue)
            m_10 = &this->m_iThirdValue;
        *m_10 = (int)p2;
        ((int*)p2)[2] = 0;
        m_10 = (int*)((char*)p2 + 8);
        r6 = true;
    }
    else
    {
        r6 = false;
    }
    return r6;
}

struct FUN_006ecc70_Class
{
    void PushFront(int* p);
};

// @fnv 0x006ecc70
void FUN_006ecc70_Class::PushFront(int* p)
{
    while (true)
    {
        if (FUN_0043b460((long volatile*)((char*)this + 4), 0, 1) == 0)
        {
            ::FUN_0040fbe0();
            *(int*)((char*)p[0] + 8) = *(int*)((char*)this + 8);
            *(int*)((char*)this + 8) = p[0];
            p[0] = 0;
            ::FUN_0040fbe0();
            FUN_0043b460((long volatile*)((char*)this + 4), 1, 0);
            break;
        }
    }
}

bool __cdecl FUN_00696540(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*);
struct NavMeshTriangleReference;
struct NavMeshTriangleEdgeReference;
struct AStarNode
{
    NavMeshTriangleReference* m_pReferencedNode;
    NavMeshTriangleEdgeReference* m_pLink;
    int m_i;
    int m_iUnknownValue;
    float m_f;
    float m_g;
    float m_h;
    float m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
};
struct Arr
{
    AStarNode* GetAt(int);
};
struct FUN_006ed7d0_Class
{
    bool FUN_006ed7d0(unsigned int a1, unsigned int a2, const NiPoint3& a3, const NiPoint3& a4);
};
// @fnv 0x006ed7d0
bool FUN_006ed7d0_Class::FUN_006ed7d0(unsigned int uiStartIndex, unsigned int uiEndIndex, const NiPoint3& aPoint1,
                                      const NiPoint3& aPoint2)
{
    for (unsigned int i = uiStartIndex; i <= uiEndIndex; i++)
    {
        if (!FUN_00696540((const NiPoint3*)((char*)((Arr*)((char*)this + 0x90))->GetAt(i)->m_pReferencedNode + 0x20),
                          (const NiPoint3*)((char*)((Arr*)((char*)this + 0x90))->GetAt(i)->m_pReferencedNode + 0x2c),
                          &aPoint1, &aPoint2))
            return false;
    }
    return true;
}

struct S5460
{
    virtual void* v0();
    virtual void* v1(unsigned int a);
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    void* p;
    unsigned int i;
    unsigned int n;
};
// @fnv 0x006f31f0
unsigned int FUN_006f31f0(S5460* self)
{
    if (((bool)(reinterpret_cast<::FUN_00438b90_class *>((self))->FUN_00438b90())))
    {
        if (self->n == 0)
        {
            unsigned int size = 4;
            self->p = self->v1(size);
            self->n = size;
        }
        else
        {
            unsigned int size = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>((self))->FUN_009a3910()));
            reinterpret_cast<::fnv_009f6540::FUN_009f6540_Class *>((self))->FUN_009f6540(size, self->i);
            self->n = size;
        }
    }
    self->i += 1;
    return self->i - 1;
}

namespace fnv_006f4e40 {
struct PathingLocation
{
    PathingLocation();
    ~PathingLocation();
};
struct FUN_006f4e40_Class
{
    void* p;
    PathingLocation loc;
    FUN_006f4e40_Class(int a1);
};
// @fnv 0x006f4e40
FUN_006f4e40_Class::FUN_006f4e40_Class(int aiValue)
{
    reinterpret_cast<::FUN_006dd3e0_shell *>(&(loc))->FUN_006dd3e0((const ::NavMeshInfo *)(aiValue));
    *(int*)((char*)this + 0x2c) = 0;
    reinterpret_cast<::fnv_006f4ed0::PathingLocation *>(&(loc))->FUN_006f4ed0((const ::fnv_006f4ed0::NiPoint3 *)(aiValue + 0x10));
    p = (void*)1;
}
}  // namespace fnv_006f4e40

namespace fnv_006f4f90 {
struct PathingLocation
{
    PathingLocation();
    ~PathingLocation();
};
struct FUN_006f4f90_Class
{
    int m_type;
    PathingLocation m_loc;
    int m_auiShapeKeys;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_w;
    int m_q;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q2;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w2;
    int m_x2;
    int m_y2;
    int m_z2;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f2;
    int m_g2;
    int m_h2;
    int m_i2;
    int m_j2;
    int m_k2;
    int m_l2;
    int m_m2;
    int m_n2;
    int m_o2;
    int m_p2;
    int m_q3;
    int m_r2;
    int m_s2;
    int m_t2;
    int m_u2;
    int m_v2;
    int m_w3;
    int m_x3;
    int m_y3;
    int m_z3;
    int m_a2;
    FUN_006f4f90_Class(int a1, int a2);
};
// @fnv 0x006f4f90
FUN_006f4f90_Class::FUN_006f4f90_Class(int aiFirst, int aiSecond)
{
    reinterpret_cast<::FUN_006dd3e0_shell *>(&(m_loc))->FUN_006dd3e0((const ::NavMeshInfo *)(aiSecond));
    this->m_i = 0;
    reinterpret_cast<::fnv_006f4ed0::PathingLocation *>(&(m_loc))->FUN_006f4ed0((const ::fnv_006f4ed0::NiPoint3 *)(aiFirst));
    m_type = 3;
}
}  // namespace fnv_006f4f90

struct FUN_006f98c0_Class2
{
    void* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006f98c0_Class2(int count);
};
// @fnv 0x006f9680
int FUN_006f9680_Class::FUN_006f9680(int aiValue)
{
    new ((void *)(((FUN_006f98c0_Class*)this))) ::FUN_006f98c0_Class2(aiValue);
    m_iWordAt00 = (int)&DAT_0106df38;
    return (int)this;
}
// Sets the vtable, stores count and zeroes a newly allocated count*4-byte buffer when count is non-zero.
// @fnv 0x006f98c0
FUN_006f98c0_Class2::FUN_006f98c0_Class2(int count)
{
    m_vtbl = &DAT_0106dfa0;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    if (count)
    {
        unsigned int size = m_uiItemCount * 4;
        void* buf = operator new(size);
        m_data = buf;
        std::memset(m_data, 0, m_uiItemCount * 4);
    }
}

struct AnimIdle;
struct Helper62d0
{
    AnimIdle* m_p;
    Helper62d0& operator=(const Helper62d0&);
};
struct FUN_006f9d90_S
{
    int m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
    float m_10;
    float m_14;
    float m_18;
    Helper62d0 m_1c;
    FUN_006f9d90_S& operator=(const FUN_006f9d90_S&);
};
// Copies all fields of another instance into this one and returns a reference to this object.
// @fnv 0x006f9d90
FUN_006f9d90_S& FUN_006f9d90_S::operator=(const FUN_006f9d90_S& aSource)
{
    m_iWordAt00 = aSource.m_iWordAt00;
    m_iWordAt04 = aSource.m_iWordAt04;
    m_8 = aSource.m_8;
    m_iThirdValue = aSource.m_iThirdValue;
    m_10 = aSource.m_10;
    m_14 = aSource.m_14;
    m_18 = aSource.m_18;
    m_1c = aSource.m_1c;
    return *this;
}

struct FakeArray
{
    virtual void* v0();
    virtual void* Write(unsigned int);
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void ResizeAndFill(unsigned int a1, unsigned int a2);
};
struct FUN_006fb170_Class
{
};
struct FUN_006fb3d0_Class
{
};
struct ListNode_680910
{
};
// If the flag differs from DAT_0119f154, walks the g_011d8624 list calling UpdateWaterReferences or FUN_006fb3d0 on each entry, then stores the flag.
// @fnv 0x006fa920
void SetSoundListFlag(unsigned char a1)
{
    if ((*reinterpret_cast<unsigned char *>(&::DAT_0119f154)) == a1)
        return;
    ListNode_680910* p = (ListNode_680910*)&(*reinterpret_cast<::SoundListView *>(&::g_011d8624));
    while (p)
    {
        void* q = (void*)*((int *)(new ((void *)(p)) ::Vec3()));
        if (q)
        {
            if (a1)
                reinterpret_cast<::SelfX *>((((FUN_006fb170_Class*)q)))->UpdateWaterReferences(1);
            else
                reinterpret_cast<::detach6fb::D6Detacher *>((((FUN_006fb3d0_Class*)q)))->FUN_006fb3d0(1);
        }
        p = ((::ListNode_680910 *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
    }
    (*reinterpret_cast<unsigned char *>(&::DAT_0119f154)) = a1;
}

struct FUN_006f2510_Class
{
    void* FUN_006f2510(int, int, int);
};
struct FUN_006edce0_Class
{
    BSSimpleList<BGSPerk*> l0;
    int p0;
    BSSimpleList<BGSPerk*> l1;
    int p1;
    BSSimpleList<BGSPerk*> l2;
    int p2;
    BSSimpleList<BGSPerk*> l3;
    FUN_006f2510_Class f;
    FUN_006edce0_Class* FUN_006edce0(int a1);
};
struct NavMeshSearchLOSArray
{
    void Clear(bool);
    virtual ~NavMeshSearchLOSArray();
};
struct FUN_006f2bb0_Class : public NavMeshSearchLOSArray
{
    virtual ~FUN_006f2bb0_Class();
};
// @fnv 0x006f3050
void* FUN_006f3050_Class::FUN_006f3050(unsigned int flags)
{
    reinterpret_cast<::FUN_006f2bb0_Class *>(this)->FUN_006f2bb0_Class::~FUN_006f2bb0_Class();
    if (flags & 1)
        operator delete(this);
    return this;
}
// Destructor that calls Clear(true) on the NavMeshSearchLOSArray base.
// @fnv 0x006f2bb0
FUN_006f2bb0_Class::~FUN_006f2bb0_Class()
{
    Clear(true);
}

struct FUN_006f46f0_Node
{
    FUN_006f46f0_Node* m_00;
    FUN_006f46f0_Node* m_04;
    FUN_006f46f0_Node* m_08;
    FUN_006f46f0_Node* m_0c;
    FUN_006f46f0_Node* m_10;
    FUN_006f46f0_Node* m_14;
    FUN_006f46f0_Node* m_18;
    FUN_006f46f0_Node* m_1c;
    FUN_006f46f0_Node* m_20;
    FUN_006f46f0_Node* m_24;
    FUN_006f46f0_Node** m_28;
    FUN_006f46f0_Node* m_2c;
};
// Scans 20 slots of a1 for the first non-null node, unlinks it (replacing the slot with its m_2c child), clears its m_28/m_2c, and returns it.
// @fnv 0x006f46f0
FUN_006f46f0_Node* PopFirstNode(FUN_006f46f0_Node* a1)
{
    FUN_006f46f0_Node* result = 0;
    for (unsigned int i = 0; i < 20; i++)
    {
        FUN_006f46f0_Node** ppSlot = (FUN_006f46f0_Node**)((char*)&a1->m_04 + i * 4);
        if (*ppSlot)
        {
            result = *ppSlot;
            if ((*ppSlot)->m_2c)
            {
                (*ppSlot)->m_2c->m_28 = ppSlot;
                *ppSlot = (*ppSlot)->m_2c;
            }
            else
            {
                *ppSlot = 0;
            }
            result->m_28 = 0;
            result->m_2c = 0;
            break;
        }
    }
    return result;
}

struct Elem16;
struct Arr16
{
    void FUN_006dbcf0(int*, int);
public:
    unsigned int AppendElement(const ::Elem16 *);
};
struct SizeState
{
    virtual void v0();
    virtual int Write(unsigned int requested);
    void FUN_006dbcf0(int*, int);
    int iSize;
    int iPosition;
    int iDataLength;
    void ResetAndWrite(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x006f4b60
void* FUN_006f4b60_Class::FUN_006f4b60()
{
    *(void***)this = &DAT_0106d988;
    reinterpret_cast<::SizeState *>(this)->ResetAndWrite((unsigned int)(0), (unsigned int)(0));
    return this;
}
// @fnv 0x006f4c40
void SizeState::ResetAndWrite(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_006dbcf0_Class *>(this)->FUN_006dbcf0((struct ::FUN_006d5320 *)(int *)((int*)iSize), savedSize);
        iPosition = savedSize;
    }
}

namespace fnv_006f4f00 {
struct PathingLocation
{
    PathingLocation();
    ~PathingLocation();
};
struct FUN_006f4f00_Class
{
    int m_type;
    PathingLocation m_loc;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    FUN_006f4f00_Class(int a1, int a2, int a3);
};
// @fnv 0x006f4f00
FUN_006f4f00_Class::FUN_006f4f00_Class(int a1, int a2, int a3)
{
    reinterpret_cast<::FUN_006dd3e0_shell *>(&(m_loc))->FUN_006dd3e0((const ::NavMeshInfo *)(a1));
    m_iUnknownValue = a3;
    reinterpret_cast<::fnv_006f4ed0::PathingLocation *>(&(m_loc))->FUN_006f4ed0((const ::fnv_006f4ed0::NiPoint3 *)(a2));
    m_type = 7;
}
}  // namespace fnv_006f4f00

struct FUN_006f9a00
{
    void* m_pVtbl;
    int m_uiLogicalSize;
    void* m_pData;
    int m_iPad;
    FUN_006f9a00(int iSize);
};
// Calls FUN_006f9a00 with a1, then stores the address of DAT_0106df58 in the object's first field and returns this.
// @fnv 0x006f96b0
int* FUN_006f96b0_Class::FUN_006f96b0(int a1)
{
    new ((void *)(reinterpret_cast<FUN_006f9a00_Class*>(this))) ::FUN_006f9a00(a1);
    *reinterpret_cast<int**>(this) = &DAT_0106df58;
    return reinterpret_cast<int*>(this);
}
// Sets the vtable, stores iSize, and if iSize is nonzero allocates iSize*4 zeroed bytes into m_pData.
// @fnv 0x006f9a00
FUN_006f9a00::FUN_006f9a00(int iSize)
{
    m_pVtbl = &DAT_0106dfc0;
    m_uiLogicalSize = iSize;
    m_iPad = 0;
    if (iSize)
    {
        unsigned int uiBytes = m_uiLogicalSize * 4;
        void* pData2 = operator new(uiBytes);
        m_pData = pData2;
        std::memset(m_pData, 0, m_uiLogicalSize * 4);
    }
}

struct FUN_006c8a30_Class
{
};
struct FUN_006dc640_Class
{
    void FUN_006dc640(char*, char*, unsigned int);
};
struct FUN_006f9eb0_Class
{
    virtual void v0();
    virtual char* v1(unsigned int);
    virtual void v2();
    virtual char* v3(char*, unsigned int);
    char* m;
    unsigned int pad;
    unsigned int key;
    void FUN_006f9eb0(unsigned int a, unsigned int b);
};
// @fnv 0x006f9eb0
void FUN_006f9eb0_Class::FUN_006f9eb0(unsigned int auiKey, unsigned int b)
{
    if (m)
    {
        if (b == key)
        {
            m = v3(m, auiKey);
        }
        else
        {
            char* t = v1(auiKey);
            ((FUN_006dc640_Class*)this)->FUN_006dc640(t, m, b);
            ::FUN_006a8500((::DummyClass_006a8500 *)(((FUN_006c8a30_Class*)this)));
            m = t;
        }
    }
    else
    {
        m = v1(auiKey);
        key = auiKey;
    }
}

struct FUN_006fa180_StandIn
{
    virtual int v00();
    int m_iElementCount;
    int m_pos;
    int m_len;
    virtual int v04(unsigned int);
    void FUN_006f9ff0(int, unsigned int);
    void FUN_006fa180(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x006fa100
FUN_006fa100_Class* FUN_006fa100_Class::FUN_006fa100()
{
    *(int**)this = &DAT_0106dfe0;
    reinterpret_cast<::FUN_006fa180_StandIn *>((((FUN_006fa180_Class*)this)))->FUN_006fa180(0, 0);
    return this;
}

// @fnv 0x006fa180
void FUN_006fa180_StandIn::FUN_006fa180(unsigned int requested, unsigned int savedSize)
{
    m_iElementCount = 0;
    m_pos = 0;
    m_len = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_iElementCount = v04(requested);
        m_len = requested;
    }
    if (savedSize > 0)
    {
        FUN_006f9ff0(m_iElementCount, savedSize);
        m_pos = savedSize;
    }
}

struct Unk006fec90
{
};
struct Unk006fec00
{
    bool FUN_006fec00(int a1);
};
struct Unk006fec90_Class
{
    int GetActiveMenu(int a1);
    bool FUN_006fec00(int a1);
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    FORenderedMenu* m_pMenu;
    int m_iWordAt04;
    int m_5;
    int m_6;
    Unk006fec90* m_pItems[4];
};
// Steam SDK import (called through the IAT in the original)
extern "C" __declspec(dllimport) void __cdecl SteamAPI_RunCallbacks();

struct FUN_006ff860_Class
{
    void FUN_006ff860();
};

// @fnv 0x006ff860
void FUN_006ff860_Class::FUN_006ff860()
{
    SteamAPI_RunCallbacks();
}

struct FUN_006ffb90_Class
{
};
struct FUN_006ff9f0 : FUN_006ff970_Class
{
    int m_kPointA;
    int m_kPointB;
    FUN_006ff9f0(int a1, int a2);
};
struct FUN_006ffa70 : FUN_006ff970_Class
{
    int m_i;
    int m_iUnknownValue;
    FUN_006ffa70(int a1, int a2);
};
struct FUN_006e22d0_Class
{
    int m0;
    _Mem_2064 m1;
    void FUN_006e22d0();
};
struct Elem4
{
    int m_uiFilterValue;
};

struct FUN_006ec5b0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    Elem4 m_queue[256];
    unsigned int m_uiItemCount;
    unsigned int m_40c;
    unsigned int m_uiEdgeIndex;

    bool FUN_006ec5b0(Helper62d0* a1);
};

struct FUN_006ee050_Class
{
    int m0;
    int m4;
    NiBound mBound;
    FUN_006ee050_Class();
};

// @fnv 0x006ee050
FUN_006ee050_Class::FUN_006ee050_Class()
{}

struct FUN_006f02e0_Point
{
    int x;
    int y;
    int z;
};

struct FUN_006f02e0_Node
{
    unsigned int* p0;
    unsigned int* p1;
};

struct FUN_006f02e0_Class
{
    void CopyNodePositions();
};

// For each element of the array at offset 0x90, copies a point from p0+0x0c into the node at +0x20 and a point from p1+0x0c into the node at +0x2c.
// @fnv 0x006f02e0
void FUN_006f02e0_Class::CopyNodePositions()
{
    for (int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x90)))->GetName())); ++i)
    {
        *reinterpret_cast<FUN_006f02e0_Point*>(
            reinterpret_cast<unsigned char*>(*reinterpret_cast<FUN_006f02e0_Node**>(
                reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x90)->GetAt(i))) +
            0x20) =
            *reinterpret_cast<FUN_006f02e0_Point*>(
                reinterpret_cast<unsigned char*>(
                    (*reinterpret_cast<FUN_006f02e0_Node**>(
                         reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x90)->GetAt(i)))
                        ->p0) +
                0x0c);

        *reinterpret_cast<FUN_006f02e0_Point*>(
            reinterpret_cast<unsigned char*>(*reinterpret_cast<FUN_006f02e0_Node**>(
                reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x90)->GetAt(i))) +
            0x2c) =
            *reinterpret_cast<FUN_006f02e0_Point*>(
                reinterpret_cast<unsigned char*>(
                    (*reinterpret_cast<FUN_006f02e0_Node**>(
                         reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x90)->GetAt(i)))
                        ->p1) +
                0x0c);
    }
}

struct BSSimpleArrayActor
{
    unsigned int Add(void*& item);
};

struct FUN_0042fb60_shell
{
    void FUN_0042fb60(char* destination, char* source, unsigned int count);
};

struct CtorHelper
{
};

struct FUN_006f23d0_Class
{
    virtual void FUN_006f23d0_v0() = 0;
    virtual void* FUN_006f23d0_v4(unsigned int count) = 0;

    void* m_p;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void FUN_006f23d0(unsigned int index, void*& value);
};

// @fnv 0x006f23d0
void FUN_006f23d0_Class::FUN_006f23d0(unsigned int index, void*& value)
{
    if (index == m_iElementCount)
    {
        reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArrayActor*>(this)))->FUN_007cb2e0((unsigned int *)&(value));
    }
    else
    {
        if (((bool)(reinterpret_cast<::FUN_00438b90_class *>((reinterpret_cast<S5460*>(this)))->FUN_00438b90())))
        {
            unsigned int m_ppNewArray = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>((reinterpret_cast<S5460*>(this)))->FUN_009a3910()));

            void* pNewData = FUN_006f23d0_v4(m_ppNewArray);

            reinterpret_cast<FUN_0042fb60_shell*>(this)->FUN_0042fb60(reinterpret_cast<char*>(pNewData),
                                                                      reinterpret_cast<char*>(m_p), index);

            reinterpret_cast<::fnv_006f2290::CtorHelper *>((reinterpret_cast<CtorHelper*>(this)))->InitializeItems(
                (::fnv_006f2290::NavMeshInfo **)(::NavMeshInfo **)(reinterpret_cast<NavMeshInfo**>(reinterpret_cast<char*>(pNewData) + index * 4)), 1);

            reinterpret_cast<FUN_0042fb60_shell*>(this)->FUN_0042fb60(reinterpret_cast<char*>(pNewData) + index * 4 + 4,
                                                                      reinterpret_cast<char*>(m_p) + index * 4,
                                                                      m_iElementCount - index);

            ::FUN_006a8500((::DummyClass_006a8500 *)(reinterpret_cast<FUN_006c8a30_Class*>(this)));

            m_p = pNewData;
            m_pRayCursor = m_ppNewArray;
        }
        else
        {
            reinterpret_cast<FUN_0042fb60_shell*>(this)->FUN_0042fb60(
                reinterpret_cast<char*>(m_p) + index * 4 + 4, reinterpret_cast<char*>(m_p) + index * 4, m_iElementCount - index);

            reinterpret_cast<::fnv_006f2290::CtorHelper *>((reinterpret_cast<CtorHelper*>(this)))->InitializeItems(
                (::fnv_006f2290::NavMeshInfo **)(::NavMeshInfo **)(reinterpret_cast<NavMeshInfo**>(reinterpret_cast<char*>(m_p) + index * 4)), 1);
        }

        ++m_iElementCount;

        reinterpret_cast<void**>(m_p)[index] = value;
    }
}

struct S006949d0
{
    void* GetAt(int);
};

struct FUN_006f4480_Class : public S006949d0
{
};

struct FUN_006f4230_EdgeData
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};

struct FUN_006f4230_ExtraData
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
};

struct FUN_006f4230_Node
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    FUN_006f4230_Node* m_next;
};

struct EdgeArr
{
    FUN_006f4230_EdgeData* FUN_006a1440(unsigned int);
public:
    char *FUN_006ced70();
};

struct H2 : public EdgeArr
{
public:
    void FUN_006a8890(unsigned int, unsigned char);
};

struct FUN_006f4230_Class
{
    bool CopyNodeListToArrays(FUN_006f4230_Node*, H2*, FUN_006f4480_Class*);
};

// @fnv 0x006f4230
bool FUN_006f4230_Class::CopyNodeListToArrays(FUN_006f4230_Node* pNodeList, H2* pEdgeArr,
                                                         FUN_006f4480_Class* pExtraArr)
{
    FUN_006f4230_Node* pNode;
    int iCount;
    int iIndex;

    if (!pNodeList)
    {
        return false;
    }

    iCount = 0;
    pNode = pNodeList;
    while (pNode)
    {
        ++iCount;
        pNode = pNode->m_next;
    }

    pEdgeArr->FUN_006a8890(iCount, 1);
    reinterpret_cast<::fnv_006f4480::BSSimpleArrayActor *>((pExtraArr))->FUN_006f4480(iCount - 1, 1);

    pNode = pNodeList;
    iIndex = iCount - 1;
    while (pNode)
    {
        *pEdgeArr->FUN_006a1440(static_cast<unsigned int>(iIndex)) =
            *reinterpret_cast<FUN_006f4230_EdgeData*>(reinterpret_cast<char*>(pNode) + 8);

        if (iIndex > 0)
        {
            *reinterpret_cast<FUN_006f4230_ExtraData*>(((void *)(reinterpret_cast<::FUN_00558dd0_class *>((pExtraArr))->FUN_00558dd0(iIndex - 1)))) =
                *reinterpret_cast<FUN_006f4230_ExtraData*>(reinterpret_cast<char*>(pNode) + 0x14);
        }

        pNode = pNode->m_next;
        --iIndex;
    }

    return true;
}

struct ScrapHeapBuffer;
struct FUN_006f47f0_Class
{
    void* Constructor();
};
struct FUN_006f4340_Class : public ScrapHeapBuffer
{
    void* FUN_006f4340();
};
// @fnv 0x006f4340
void* FUN_006f4340_Class::FUN_006f4340()
{
    void* p = FUN_006a1f90(0x38, this);
    void* result5 = p ? ((FUN_006f47f0_Class*)p)->Constructor() : 0;
    return result5;
}

struct FUN_006f4430_Class
{
    void UnlinkFromList(int* a1);
};

// Splices a node out of a doubly linked list by relinking its neighbours, then clears its own next and previous pointers.
// @fnv 0x006f4430
void FUN_006f4430_Class::UnlinkFromList(int* pNode)
{
    if (*(int*)((char*)pNode + 0x28) != 0)
    {
        **(int**)((char*)pNode + 0x28) = *(int*)((char*)pNode + 0x2c);
    }
    if (*(int*)((char*)pNode + 0x2c) != 0)
    {
        *(int*)(*(int*)((char*)pNode + 0x2c) + 0x28) = *(int*)((char*)pNode + 0x28);
    }
    *(int*)((char*)pNode + 0x28) = 0;
    *(int*)((char*)pNode + 0x2c) = 0;
}

namespace fnv_006f47f0 {
struct FUN_006d5320_Class
{
};

struct FUN_006f47f0_Class
{
    FUN_006f47f0_Class* Constructor();
};

// Initializes the object: zeroes two floats, calls FUN_006d5320 on the sub-object at offset 0x14, and zeroes five int fields from 0x24 to 0x34, returning this.
// @fnv 0x006f47f0
FUN_006f47f0_Class* FUN_006f47f0_Class::Constructor()
{
    *(float*)this = 0.0f;
    *(float*)((char*)this + 4) = 0.0f;
    new ((void *)(((FUN_006d5320_Class*)((char*)this + 0x14)))) struct ::FUN_006d5320();
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = 0;
    return this;
}
}  // namespace fnv_006f47f0

struct GO
{
    unsigned int m_uiFilterValue;
    operator unsigned int() const;
public:
    ::GO *FUN_008228f0(unsigned int);
};
// @fnv 0x006ec5b0
bool FUN_006ec5b0_Class::FUN_006ec5b0(Helper62d0* a1)
{
    bool result = m_uiItemCount > 0;

    if (result == true)
    {
        Elem4* pElement = &m_queue[m_uiEdgeIndex];
        a1->operator=(*reinterpret_cast<const Helper62d0*>(pElement));
        reinterpret_cast<::GO *>((pElement))->FUN_008228f0(0);
        m_uiEdgeIndex++;
        m_uiEdgeIndex %= 0x100;
        m_uiItemCount--;
    }
    else
    {
        result = false;
    }

    return result;
}

struct QIdlePtr : public GO
{
    QIdlePtr& operator=(void* a1);
};

struct MiddleHighProcess
{
    void FUN_00929260(unsigned char a1);
};

struct FUN_006faa50_Class
{
    void CopyHelperFromOffset(void* a1);
};

struct FUN_006faa70_Class
{
    void FUN_006faa70(void* a1);
};

struct FUN_006fa990_Entry
{
    int m_uiFilterValue;
};

struct TargetObject
{
    GO* m_go;
    FUN_006fa990_Entry m_entry4;
    FUN_006fa990_Entry m_entry8;
    FUN_006fa990_Entry m_entryC;
    FUN_006fa990_Entry m_entry10;
    char m_ucUnknownByte[0x10];
    QIdlePtr m_idle;
    bool m_flag;

    void FUN_006fa990();
};

namespace fnv_006faa50 {
struct FUN_006faa50_Class
{
    void CopyHelperFromOffset(Helper62d0* a1);
};

// @fnv 0x006faa50
void FUN_006faa50_Class::CopyHelperFromOffset(Helper62d0* apTarget)
{
    apTarget->operator=(*reinterpret_cast<Helper62d0*>(reinterpret_cast<unsigned char*>(this) + 0x50));
}
}  // namespace fnv_006faa50

struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};

struct TESActorBaseData
{
    short GetFatigue() const;
};

struct BSShaderPPLightingProperty
{
    short GetDiffuseTextureIndex();
};

struct FUN_006fe920_Class
{
    BGSTerrainManager* m_terrainManager;
    int m_iValueAtOffset04;
    unsigned char m_ucUnknownByte[0x18];
    FUN_006fea10_Class* m_object20;
    FUN_006fea10_Class* m_object24;
    FUN_006fea10_Class* m_object28;
    FUN_006fea10_Class* m_object2c;

    bool FUN_006fe920(bool value);
};
// @fnv 0x006fea10
unsigned char FUN_006fea10_Class::FUN_006fea10(bool a1)
{
    if (*((void**)((char*)this + 0x10)) && ((FUN_00759d80_Class*)*((void**)((char*)this + 0x10)))->FUN_00759d80())
        return 1;
    if (*((void**)((char*)this + 0x10)) && reinterpret_cast<::FOPipboyManager *>((((FORenderedMenu*)*((void**)((char*)this + 0x10)))))->IsUnk28Set())
        return 1;
    return ((unsigned char)(reinterpret_cast<::FUN_006fe920_Class *>(this)->FUN_006fe920(a1)));
}

// @fnv 0x006fe920
bool FUN_006fe920_Class::FUN_006fe920(bool value)
{
    if (m_iValueAtOffset04 == m_terrainManager->GetMinLevel())
    {
        return false;
    }

    bool result = this->m_object20->FUN_006fea10(value) && this->m_object24->FUN_006fea10(value) &&
                  this->m_object28->FUN_006fea10(value) && this->m_object2c->FUN_006fea10(value);

    if (reinterpret_cast<const TESActorBaseData*>(this)->GetFatigue() > 40 ||
        reinterpret_cast<const TESActorBaseData*>(this)->GetFatigue() < -40)
    {
        return true;
    }

    if (reinterpret_cast<BSShaderPPLightingProperty*>(this)->GetDiffuseTextureIndex() > 44 ||
        reinterpret_cast<BSShaderPPLightingProperty*>(this)->GetDiffuseTextureIndex() < -44)
    {
        return true;
    }

    return result;
}

struct FUN_006fed30_Callee
{
};

struct FUN_006fed30_Class
{
    int FUN_006fed30(int a1);
};

struct LocalUnk006fec90_Class
{
    bool FUN_006fec00(int a1);
};

struct LocalBSSimpleList
{
};


namespace fnv_006ee5d0 {
struct NavMesh
{
};

struct NavMeshTriangleReference
{
    NavMesh* m_pNavMesh;
    unsigned short m_flags;
};

template <> struct BSSimpleArray<NavMeshTriangleReference, 1024>
{
    const NavMeshTriangleReference& GetLastElement() const;
};

struct FUN_006f2270
{
};

struct BSSimpleArrayActor
{
    unsigned int Add(void*& value);
};

struct FUN_006ee5d0_Position
{
    unsigned int m_uiX;
    void* m_uiY;
    void* m_uiZ;
};

struct FUN_006ee5d0_Edge
{
    FUN_006ee5d0_Position m_vContactPosition;
    unsigned short m_short;
    unsigned short m_pad0e;
    unsigned int m_value10;
    unsigned char m_value14;
    unsigned char m_pad15[3];
    unsigned int m_flags;
    unsigned char m_pad1c[8];
    void* m_navMesh;
    unsigned short m_navFlags;
};

void* FUN_006edc40(void* self);
void* CreateSize28(void* self);

struct FUN_006ee5d0_Class
{
    unsigned char m_pad00[0x14];
    FUN_006ee5d0_Position m_vContactPosition;
    BSSimpleArray<NavMeshTriangleReference, 1024>* m_pSearchArray;

    void CreateNavMeshEdges();
};

// @fnv 0x006ee5d0
void FUN_006ee5d0_Class::CreateNavMeshEdges()
{
    void* p = FUN_006edc40(this);
    {
        void* r;
        {
            void* q;
            {
                const NavMeshTriangleReference& node = m_pSearchArray->GetLastElement();

                reinterpret_cast<FUN_006ee5d0_Edge*>(p)->m_navMesh = ((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((node.m_pNavMesh))->FUN_0068efb0()));
                reinterpret_cast<FUN_006ee5d0_Edge*>(p)->m_navFlags = node.m_flags;
                reinterpret_cast<FUN_006ee5d0_Edge*>(p)->m_vContactPosition = m_vContactPosition;

                q = CreateSize28(this);
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_vContactPosition.m_uiX =
                    *reinterpret_cast<::FUN_006f2270 *>((reinterpret_cast<FUN_006f2270*>(reinterpret_cast<char*>(this) + 0x40)))->GetLast();
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_vContactPosition.m_uiY = p;
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_value14 = 1;
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_vContactPosition.m_uiZ = ((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((node.m_pNavMesh))->FUN_0068efb0()));
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_short = node.m_flags;
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_value10 = 0xffffffff;
                reinterpret_cast<FUN_006ee5d0_Edge*>(q)->m_flags =
                    ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 0x68)))->GetName()));

                r = CreateSize28(this);
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_vContactPosition.m_uiX =
                    *reinterpret_cast<::FUN_006f2270 *>((reinterpret_cast<FUN_006f2270*>(reinterpret_cast<char*>(this) + 0x54)))->GetLast();
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_vContactPosition.m_uiY = p;
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_value14 = 1;
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_vContactPosition.m_uiZ = ((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((node.m_pNavMesh))->FUN_0068efb0()));
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_short = node.m_flags;
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_value10 = 0xffffffff;
                reinterpret_cast<FUN_006ee5d0_Edge*>(r)->m_flags =
                    ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 0x7c)))->GetName()));

                reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0x40)))->FUN_007cb2e0((unsigned int *)&(p));
                reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0x54)))->FUN_007cb2e0((unsigned int *)&(p));
                reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_007cb2e0((unsigned int *)&(q));
                reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0x7c)))->FUN_007cb2e0((unsigned int *)&(r));
            }
        }
    }
}
}  // namespace fnv_006ee5d0

namespace fnv_006f28a0 {
struct PathingLocation
{
    char padding[0x28];
    PathingLocation& operator=(const PathingLocation&);
};

struct FUN_006928a0_class
{
};

struct PathingLocationArray
{
};

struct FUN_006f28a0_Class
{
    virtual void FUN_006f28a0_vtable0() = 0;
    virtual PathingLocation* FUN_006f28a0_vtable1(unsigned int) = 0;

    PathingLocation* m_pPathingLocation;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void FUN_006f28a0(unsigned int, PathingLocation*);
};

// Inserts a PathingLocation at index, growing the array if needed and shifting existing elements to make room.
// @fnv 0x006f28a0
void FUN_006f28a0_Class::FUN_006f28a0(unsigned int index, PathingLocation* location)
{
    unsigned int count;
    PathingLocation* array6;

    if (index == m_uiItemCount)
    {
        reinterpret_cast<::PathingLocationArray *>((reinterpret_cast<BSSimpleArray<PathingLocation, 1024>*>(this)))->FUN_006cf1b0((const ::PathingLocation &)(*location));
    }
    else
    {
        if (((bool)(reinterpret_cast<::FUN_00438b90_class *>((reinterpret_cast<S5460*>(this)))->FUN_00438b90())))
        {
            count = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>((reinterpret_cast<S5460*>(this)))->FUN_009a3910()));
            array6 = this->FUN_006f28a0_vtable1(count);

            reinterpret_cast<::FUN_006928a0_class *>((reinterpret_cast<FUN_006928a0_class*>(this)))->FUN_006928a0(
                reinterpret_cast<char*>(array6), reinterpret_cast<char*>(m_pPathingLocation), index);

            reinterpret_cast<::PathingLocationArray *>((reinterpret_cast<PathingLocationArray*>(this)))->ConstructItems((::PathingLocation *)(::fnv_006f28a0::PathingLocation *)(array6 + index), 1);

            reinterpret_cast<::FUN_006928a0_class *>((reinterpret_cast<FUN_006928a0_class*>(this)))->FUN_006928a0(
                reinterpret_cast<char*>(array6 + index + 1), reinterpret_cast<char*>(m_pPathingLocation + index),
                m_uiItemCount - index);

            ::FUN_006a8500((::DummyClass_006a8500 *)(reinterpret_cast<FUN_006c8a30_Class*>(this)));

            m_pPathingLocation = array6;
            m_pRayCursor = count;
        }
        else
        {
            reinterpret_cast<::FUN_006928a0_class *>((reinterpret_cast<FUN_006928a0_class*>(this)))->FUN_006928a0(
                reinterpret_cast<char*>(m_pPathingLocation + index + 1),
                reinterpret_cast<char*>(m_pPathingLocation + index), m_uiItemCount - index);

            reinterpret_cast<::PathingLocationArray *>((reinterpret_cast<PathingLocationArray*>(this)))->ConstructItems((::PathingLocation *)(::fnv_006f28a0::PathingLocation *)(m_pPathingLocation + index), 1);
        }

        ++m_uiItemCount;

        (m_pPathingLocation + index)->operator=(*location);
    }
}
}  // namespace fnv_006f28a0

extern void* DAT_0106ced8;

struct FUN_006e0f20_Class
{
    void** m_ppVirtualMethodTable;
    unsigned int m_hashSize;
    void* m_table;
    unsigned int m_entryCount;

    FUN_006e0f20_Class* ConstructHashTable(unsigned int hashSize);
};
// @fnv 0x006e0ea0
int* FUN_006e0ea0_Class::FUN_006e0ea0(int aiValue)
{
    reinterpret_cast<::FUN_006e0f20_Class *>(this)->ConstructHashTable(aiValue);
    *(int**)this = &DAT_0106ceb8;
    return (int*)this;
}

// Initializes the hash table: stores the hash size, allocates a zeroed pointer table of that size, and resets the entry count.
// @fnv 0x006e0f20
FUN_006e0f20_Class* FUN_006e0f20_Class::ConstructHashTable(unsigned int hashSize)
{
    m_ppVirtualMethodTable = &DAT_0106ced8;
    m_hashSize = hashSize;
    m_entryCount = 0;

    unsigned int allocationSize = m_hashSize * sizeof(void*);
    m_table = ::FUN_00aa1070(allocationSize);
    ::FUN_00403d30(m_table, 0, m_hashSize * sizeof(void*));
    return this;
}

struct FUN_006e12c0_Class
{
    virtual void v0();
    virtual int v1(int requested);
    virtual void v2();
    virtual int v3(int oldData, int requested);
    int currentData;
    int reserved08;
    int cachedKey;
    void SetData(int newData, int searchKey);
};
// @fnv 0x006e12c0
void FUN_006e12c0_Class::SetData(int aiData, int aiKey)
{
    if (currentData)
    {
        if (aiKey == cachedKey)
        {
            currentData = v3(currentData, aiData);
        }
        else
        {
            int replacement = v1(aiData);
            reinterpret_cast<::FUN_006d07d0_shell *>(this)->FUN_006d07d0((void *)(replacement), (void *)(currentData), aiKey);
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            currentData = replacement;
        }
    }
    else
    {
        currentData = v1(aiData);
        cachedKey = aiData;
    }
}

struct FUN_004968b0
{
    virtual ~FUN_004968b0();
    int referenceCount;
    FUN_004968b0();
};
struct FUN_006e2080
{
    int data;
    int count;
    int capacity;
    int allocation;
    int flags;
    FUN_006e2080(unsigned int size);
    ~FUN_006e2080();
};
struct FUN_0042f800
{
    int x;
    int y;
    int z;
    int w;
    FUN_0042f800();
};
struct Position3
{
    int x;
    int y;
    int z;
};
struct FUN_006e1370 : FUN_004968b0
{
    FUN_006e2080 items;
    FUN_0042f800 range;
    int value2c;
    int value30;
    int value34;
    bool option38;
    bool option39;
    Position3 position;
    float size;
    FUN_006e1370(Position3 coordinates, float dimension);
    virtual ~FUN_006e1370();
};
// Initializes the object with a position and size, zeroes the value fields, and constructs the items container with 37 elements.
// @fnv 0x006e1370
FUN_006e1370::FUN_006e1370(Position3 aPosition, float afSize) : FUN_004968b0(), items(37), range()
{
    position = aPosition;
    size = afSize;
    value2c = 0;
    value30 = 0;
    value34 = 0;
    items.flags = 0;
    option38 = false;
    option39 = false;
}

struct FUN_006dcbb0
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
    FUN_006dcbb0();
    ~FUN_006dcbb0();
};

struct FUN_006e2210
{
    int m_00;
    FUN_006dcbb0 m_04;
    ref_006815c0 m_2c;
    int unk30;
    int unk34;
    int m_38;
    FUN_006e2210();
};

// Initializes m_00 and m_38 to zero and default-constructs m_04 and m_2c.
// @fnv 0x006e2210
FUN_006e2210::FUN_006e2210() : m_04(), m_2c()
{
    m_00 = 0;
    m_38 = 0;
}

struct FUN_006e3d30_cls
{
    virtual void v0();
    virtual int v1(int a);
    virtual void v2();
    virtual int v3(int a, int b);
    int m_04;
    int m_08;
    int m_0c;
    void FUN_006e3d30(int a1, int a2);
};

// @fnv 0x006e3d30
void FUN_006e3d30_cls::FUN_006e3d30(int a1, int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, a1);
        }
        else
        {
            int t = v1(a1);
            reinterpret_cast<::FUN_006e3e70_Class *>(this)->FUN_006e3e70((char *)(t), (char *)(m_04), a2);
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            m_04 = t;
        }
    }
    else
    {
        m_04 = v1(a1);
        m_0c = a1;
    }
}

struct TESObjectCELL_s
{
};
struct Loc_s
{
};
struct Holder_s
{
};
struct Flags_s
{
    int m_flags;
    Flags_s(int a1);
};
struct Child84_s
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
    Child84_s();
};
struct Child80_s
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
    Child80_s();
};
void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);

struct PathObj_s
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    Holder_s* m_holder;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    void* m_parent;
    void* m_pOwningWorld;
    Child80_s* m_child80;
    Child84_s* m_child84;
    bool SetupFromCellWorld();
};

class FUN_006e6db0_cls;

class FUN_006e6db0_ObjectBase
{
  public:
    virtual void Destroy();
    virtual void Release(int flags);
};


class FUN_006e6db0_cls
{
  public:
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    FUN_006e6db0_ObjectBase* m_80;
    FUN_006e6db0_ObjectBase* m_84;

    void FUN_006e6db0();
};

// Flushes children, then releases and frees m_84 and frees m_80, clearing both pointers.
// @fnv 0x006e6db0
void FUN_006e6db0_cls::FUN_006e6db0()
{
    reinterpret_cast<::FUN_006e6bd0_Class *>(this)->FUN_006e6bd0();
    if (m_84 != 0)
    {
        m_84->Release(0);
        ::FUN_00553380(m_84);
        m_84 = 0;
    }
    if (m_80 != 0)
    {
        ::FUN_00553380(m_80);
        m_80 = 0;
    }
}

struct FUN_006e7190_Helper30
{
};

struct FUN_006e7190_Target
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
    FUN_006e7190_Helper30 m_30;
};

struct FUN_006e7190_Helper84
{
};

struct FUN_006e7190_Dispatch
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual unsigned char Check(FUN_006e7190_Target* p) = 0;
};

struct FUN_006e7190_cls
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    FUN_006e7190_Dispatch* m_7c;
    FUN_006e7190_Target* m_80;
    FUN_006e7190_Helper84* m_84;
    int m_88;
    bool UpdateAndCheck(void* a1, void* a2);
};

// Ticks m_80's helper and m_84, increments m_88, calls Foo and Bar on m_80, then returns false if m_7c->Check(m_80) is nonzero, otherwise true.
// @fnv 0x006e7190
bool FUN_006e7190_cls::UpdateAndCheck(void* a1, void* a2)
{
    reinterpret_cast<::FUN_0062a2b0_Class *>(&(m_80->m_30))->FUN_0062a2b0();
    reinterpret_cast<::FUN_0062a290_Class *>((m_84))->FUN_0062a290();
    m_88 = m_88 + 1;
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>((m_80))->FUN_004a3da0((void *)((int)a1));
    reinterpret_cast<::FUN_004a3eb0_shell *>((m_80))->FUN_004a3eb0((void *)((int)a2));
    if (m_7c->Check(m_80) != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

class B6E9570PathingLocation
{
  public:
    B6E9570PathingLocation& operator=(const B6E9570PathingLocation& kOther);

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
};

struct B6E9570Point3
{
    float x;
    float y;
    float z;
};

class FUN_006e9570_cls
{
  public:
    FUN_006e9570_cls& operator=(const FUN_006e9570_cls& kOther);

    int m_iType;
    B6E9570PathingLocation m_kLocation;
    B6E9570Point3 m_kPathOffset;
    int m_iFlags;
};

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
struct FUN_006f4cd0
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
    FUN_006f4cd0();
};
struct FUN_006e95d0_Class
{
    void FUN_006e95d0(FUN_006f4cd0* destination, unsigned int count);
};
// @fnv 0x006e9050
void* FUN_006e9050_Class::FUN_006e9050()
{
    *reinterpret_cast<void**>(this) = &DAT_0106d4d4;
    reinterpret_cast<::SaveGameSizeState *>(this)->InitSizeState(0, 0);
    return this;
}
// Resets the size, position and length fields, writes the larger of requested and savedSize, then records savedSize as the position.
// @fnv 0x006e9670
void SaveGameSizeState::InitSizeState(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        iSize = Write2(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_006e95d0_Class *>(this)->FUN_006e95d0((::FUN_006f4cd0 *)(iSize), savedSize);
        iPosition = savedSize;
    }
}
// Constructs count FUN_006f4cd0 objects in place at destination using placement new.
// @fnv 0x006e95d0
void FUN_006e95d0_Class::FUN_006e95d0(FUN_006f4cd0* destination, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (destination + i) FUN_006f4cd0;
    }
}

class FUN_006ecc40
{
  public:
    virtual ~FUN_006ecc40();
    int value04;
    int value08;
    FUN_006ecc40();
};

class FUN_006ed0e0
{
  public:
    int value00;
    int value04;
    int value08;
    FUN_006ed0e0();
    ~FUN_006ed0e0();
};

class FUN_006ec000 : public FUN_006ecc40
{
  public:
    FUN_006ed0e0 nodes[256];

    FUN_006ec000();
    virtual ~FUN_006ec000();
};

extern int DAT_0106d698;

// @fnv 0x006ec1c0
void FUN_006ec200_Class::FUN_006ec1c0()
{
    *(void**)this = &DAT_0106d698;
    reinterpret_cast<FUN_006ec1e0_Class*>(this)->FUN_006ec1e0();
}

struct FUN_006ec2e0_Elem
{
    int unk00;
    int unk04;
    FUN_006ec2e0_Elem* next;
    int FUN_006815c0();
};

struct FUN_006ec2e0_Free
{
    void FUN_006ecb10(FUN_006ec2e0_Elem*& e);
};

struct FUN_006ec2e0_Out
{
};

struct FUN_006ec2e0_Class
{
    int unk00;
    int unk04;
    FUN_006ec2e0_Free* freeList;
    FUN_006ec2e0_Elem* head;
    bool PopHead(FUN_006ec2e0_Out* a1);
};

void* operator new(unsigned int size, void* where);
void operator delete(void* p, void* where);

class FUN_006ec4b0_item
{
  public:
    unsigned int m_unk00;
    FUN_006ec4b0_item(void* arg);
};

class FUN_006ec4b0_cls
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    void* m_slots[0x100];
    unsigned int m_uiItemCount;
    unsigned int m_pFirstNode;

    unsigned char PushItem(void* arg);
};

// @fnv 0x006ec4b0
unsigned char FUN_006ec4b0_cls::PushItem(void* arg)
{
    unsigned char bPushed = (m_uiItemCount < 0x100) ? 1 : 0;
    if (bPushed == 1)
    {
        new (&m_slots[m_pFirstNode]) FUN_006ec4b0_item(arg);
        m_pFirstNode = m_pFirstNode + 1;
        m_pFirstNode = m_pFirstNode % 0x100;
        m_uiItemCount = m_uiItemCount + 1;
    }
    else
    {
        bPushed = 0;
    }
    return bPushed;
}

class RecursiveSpinLock
{
  public:
public:
    void FUN_0040fba0();
};

struct FUN_006ec900_Class
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual bool Visit(unsigned int index, int arg);
    int unk04;
    unsigned int count;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RecursiveSpinLock lock;
    bool VisitUntilFound(int a1);
};

// Locks, iterates entries calling Visit until one returns true, unlocks, and returns whether one matched.
// @fnv 0x006ec900
bool FUN_006ec900_Class::VisitUntilFound(int aiValue)
{
    bool found = false;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0(0);
    for (unsigned int i = 0; i < count && !found; ++i)
    {
        found = Visit(i, aiValue);
    }
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return found;
}

struct FUN_006ecce0_Class
{
    void FUN_006ecce0();
};

// @fnv 0x006ecce0
void FUN_006ecce0_Class::FUN_006ecce0()
{
    reinterpret_cast<::Date *>((this))->FUN_007b3fa0(0);
}

struct SpawnedBase
{
    unsigned int unk04;
    unsigned int unk08;
    SpawnedBase();
    virtual ~SpawnedBase();
};

struct SpawnedElem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SpawnedElem();
    ~SpawnedElem();
};

class FUN_006ece90 : public SpawnedBase
{
  public:
    SpawnedElem m_0c[0x100];

    FUN_006ece90();
    virtual ~FUN_006ece90();
};

struct FUN_006ed040_Elem
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_006ed040_Elem* m_next;
};

struct FUN_006ed040_cls
{
    unsigned int unk00;
    long volatile m_lock;
    FUN_006ed040_Elem* m_pFirstNode;
    void InitElementList(unsigned int count, FUN_006ed040_Elem* elems);
};
// Constructs the object and initializes its 256-entry nodes table via InitElementList.
// @fnv 0x006ec000
FUN_006ec000::FUN_006ec000()
{
    reinterpret_cast<::FUN_006ed040_cls *>(this)->InitElementList(256, (::FUN_006ed040_Elem *)(nodes));
}
// Constructs the object and initializes its 0x100-element m_0c array via InitElementList.
// @fnv 0x006ece90
FUN_006ece90::FUN_006ece90()
{
    reinterpret_cast<::FUN_006ed040_cls *>(this)->InitElementList(0x100, (::FUN_006ed040_Elem *)(m_0c));
}


// Locks m_lock, links count elements starting at elems into a singly linked list, terminates the last with null, then unlocks.
// @fnv 0x006ed040
void FUN_006ed040_cls::InitElementList(unsigned int count, FUN_006ed040_Elem* elems)
{
    m_pFirstNode = elems;
    while (1)
    {
        if (FUN_0043b460(&m_lock, 0, 1) == 0)
        {
            FUN_0040fbe0();
            unsigned int i = 0;
            FUN_006ed040_Elem* p2 = elems;
            for (; i < count - 1; i++, p2++)
            {
                p2->m_next = p2 + 1;
            }
            p2->m_next = 0;
            FUN_0040fbe0();
            FUN_0043b460(&m_lock, 1, 0);
            return;
        }
    }
}

struct Position_006edd30
{
    float x;
    float y;
    float z;
};
struct PositionArray_006edd30
{
};
struct PositionIndex_006edd30
{
    PositionArray_006edd30* source;
    unsigned short itemIndex;
};
struct PositionCollection_006edd30
{
    PositionIndex_006edd30* FUN_006dad90(unsigned int);
};
struct Stamp_006edd30
{
};
struct LocationContext_006edd30
{
    Stamp_006edd30* stampSource;
    unsigned short index;
    unsigned short flags;
    unsigned int formID;
};
struct ContextProvider_006edd30
{
};
struct PointerList_006edd30
{
    void* entries;
    unsigned int capacity;
    unsigned int size;
    unsigned int flags;
    unsigned int revision;
    unsigned int* FUN_006f2270();
};
struct Location_006edd30
{
    Position_006edd30 position;
    unsigned int unknown0C;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1C;
    unsigned int unknown20;
    unsigned int stamp;
    unsigned short index;
    unsigned short flags;
    PointerList_006edd30 relatedPaths;
};
struct PathEdge_006edd30
{
    unsigned int nodeKey;
    Location_006edd30* location;
    unsigned int stamp;
    unsigned short index;
    unsigned short flags;
    unsigned int nextIndex;
    unsigned char active;
    unsigned char color;
    unsigned short padding16;
    unsigned int state;
};
struct Path_006edd30
{
    Location_006edd30* start;
    Location_006edd30* finish;
    unsigned int unknown08;
    unsigned int unknown0C;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1C;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2C;
    unsigned int unknown30;
    unsigned int unknown34;
    float distance;
    unsigned int stamp;
    unsigned short index;
    unsigned short flag42;
    unsigned int formID;
    unsigned int state;
    PathEdge_006edd30* startEdge;
    PathEdge_006edd30* finishEdge;
};
struct FUN_006edd30_shell
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0C;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1C;
    PositionCollection_006edd30* positions;
    ContextProvider_006edd30* contexts;
    unsigned int unknown28;
    unsigned int unknown2C;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3C;
    PointerList_006edd30 starts;
    PointerList_006edd30 ends;
    PointerList_006edd30 startEdges;
    PointerList_006edd30 endEdges;
    PointerList_006edd30 paths;
    void FUN_006edd30(const Position_006edd30* start, const Position_006edd30* finish);
};
void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* ptr, void* place);
struct FUN_006ee050_Size28 : public FUN_006ee050_Class
{
    int extra0c;
    int extra10;
    int extra14;
    int extra18;
    __forceinline FUN_006ee050_Size28() : FUN_006ee050_Class()
    {}
};
struct FUN_006edfc0_Host
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
    FUN_00aa54a0_s allocator;
    void* CreateSize28();
};
// Allocates 0x1c bytes from the allocator and placement-constructs a FUN_006ee050_Size28 in it, returning the memory.
// @fnv 0x006edfc0
void* FUN_006edfc0_Host::CreateSize28()
{
    void* memory = reinterpret_cast<::FUN_00aa54a0_s *>(&(allocator))->FUN_00aa54a0(0x1c, DAT_010a2720);
    new (memory) FUN_006ee050_Size28;
    return memory;
}

struct Heap_006ee070
{
    void* Allocate(unsigned int size, unsigned int flags);
};

void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void* p, void* where);

struct FUN_006ee070_obj
{
    char unk00[0x58];
    FUN_006ee070_obj();
};

struct FUN_006ee070_cls
{
    char unk00[0x30];
    Heap_006ee070 m_pStreamAllocator;
    void* CreateObject();
};

// Allocates 0x58 bytes from the heap, constructs a FUN_006ee070_obj in place, and returns the pointer.
// @fnv 0x006ee070
void* FUN_006ee070_cls::CreateObject()
{
    void* mem = reinterpret_cast<::FUN_00aa54a0_s *>(&(m_pStreamAllocator))->FUN_00aa54a0(0x58, DAT_010a2720);
    new (mem) FUN_006ee070_obj;
    return mem;
}

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float GetLengthSquared();
public:
    static const ::NiPoint3 ZERO;
};
// @fnv 0x006ed7a0
void FUN_006ed7a0_Class::FUN_006ed7a0(const PathingLocation& loc)
{
    reinterpret_cast<::FUN_0069f920_cls *>((((PathingSolution**)((char*)this + 0x28))[0]))->FUN_0069f920((int)&(loc), (int)&(::NiPoint3::ZERO));
}
struct S0069a690
{
    int unk0, unk4;
    S0069a690* FUN_0069a690(const S0069a690*);
};
struct EH
{
    int unk0, unk4, unk8;
    EH& operator=(const EH&);
};
struct Node;
struct Edge;
template <class T> struct LocalArray
{
    int unk0, unk4, unk8, unkC, unk10;
    T& FUN_00877a30(unsigned);
    unsigned FUN_0044ddc0();
    unsigned FUN_007cb2e0(T&);
    T& GetFirstForm();
    T& FUN_006f2270();
    void FUN_006f2290(unsigned, bool);
    void FUN_006f23d0(unsigned, T&);
};
struct Node
{
    NiPoint3 origin, position, direction;
    S0069a690 info;
    LocalArray<Edge*> edges;
};
struct Edge
{
    Node* first;
    Node* second;
    EH info;
    unsigned char flag;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float weight;
    EH bound;
    unsigned index;
    Edge* left;
    Edge* right;
};
bool __cdecl FUN_00696540(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*);
struct FUN_006ee740_Class
{
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    LocalArray<Node*> nodesA, nodesB;
    LocalArray<Edge*> edgesA, edgesB, edgesC;
    Node* SplitNode(unsigned index, bool side, const NiPoint3& start, const NiPoint3& end);
};
struct FUN_006eec00_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int index;
};
struct FUN_006eec00_Array
{
    FUN_006eec00_Entry** FUN_00877a30(unsigned int index);
};
struct FUN_006eec00_Class
{
    void SetEntry(unsigned int index, void* value, unsigned char usePrimary);
};
// @fnv 0x006eec00
void FUN_006eec00_Class::SetEntry(unsigned int index, void* value, unsigned char usePrimary)
{
    if (usePrimary)
    {
        reinterpret_cast<::FUN_006f23d0_Class *>((reinterpret_cast<FUN_006eec00_Array*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_006f23d0(index, value);
        for (unsigned int i = index;
             i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<FUN_006eec00_Array*>(reinterpret_cast<char*>(this) + 0x68)))->GetName())); ++i)
        {
            (*reinterpret_cast<FUN_006eec00_Array*>(reinterpret_cast<char*>(this) + 0x68)->FUN_00877a30(i))->index = i;
        }
    }
    else
    {
        reinterpret_cast<::FUN_006f23d0_Class *>((reinterpret_cast<FUN_006eec00_Array*>(reinterpret_cast<char*>(this) + 0x7c)))->FUN_006f23d0(index, value);
        for (unsigned int j = index;
             j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<FUN_006eec00_Array*>(reinterpret_cast<char*>(this) + 0x7c)))->GetName())); ++j)
        {
            (*reinterpret_cast<FUN_006eec00_Array*>(reinterpret_cast<char*>(this) + 0x7c)->FUN_00877a30(j))->index = j;
        }
    }
}

struct IndexedRecord
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
};
struct IndexCollection
{
    IndexedRecord** FUN_00877a30(unsigned int index);
};
struct FUN_006eecc0_Owner
{
    void AssignRecordIndices(unsigned int first, unsigned int last);
};
// @fnv 0x006eecc0
void FUN_006eecc0_Owner::AssignRecordIndices(unsigned int first, unsigned int last)
{
    reinterpret_cast<::FUN_006f23d0_Class *>((reinterpret_cast<IndexCollection*>(reinterpret_cast<char*>(this) + 0x90)))->FUN_006f23d0(first, (*(void * *)(&last)));
    for (unsigned int index = first;
         index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<IndexCollection*>(reinterpret_cast<char*>(this) + 0x90)))->GetName())); ++index)
    {
        (*reinterpret_cast<IndexCollection*>(reinterpret_cast<char*>(this) + 0x90)->FUN_00877a30(index))->unk48 = index;
    }
}

struct V08
{
    int x, y, z;
};
struct N08
{
    V08 original, copy;
};
struct A08
{
    int unk00, unk04, unk08, unk0c, unk10;
    N08*& FUN_006f2270();
};
struct F08
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    float unk2c;
    int unk30, unk34, unk38, unk3c;
    A08 unk40, unk54;
    unsigned int UpdateNodeDirection(unsigned int, float, bool);
    void FUN_006eef80();
};
// @fnv 0x006eef80
void F08::FUN_006eef80()
{
    ((::N08 *)&(::GetFirstForm((::NiFormArray *)&(unk40))))->copy = ((::N08 *)&(::GetFirstForm((::NiFormArray *)&(unk40))))->original;
    ((::N08 *)&(::GetFirstForm((::NiFormArray *)&(unk54))))->copy = ((::N08 *)&(::GetFirstForm((::NiFormArray *)&(unk54))))->original;
    unsigned int i = 1;
    while (i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(unk40))->GetName())) - 1)
    {
        i = UpdateNodeDirection(i, unk2c, true);
    }
    i = 1;
    while (i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(unk54))->GetName())) - 1)
    {
        i = UpdateNodeDirection(i, unk2c, false);
    }
    ((::N08 *)(reinterpret_cast<::FUN_006f2270 *>(&(unk40))->GetLast()))->copy = ((::N08 *)(reinterpret_cast<::FUN_006f2270 *>(&(unk40))->GetLast()))->original;
    ((::N08 *)(reinterpret_cast<::FUN_006f2270 *>(&(unk54))->GetLast()))->copy = ((::N08 *)(reinterpret_cast<::FUN_006f2270 *>(&(unk54))->GetLast()))->original;
}


struct Pt_6f03a0
{
    float x, y, z;
    Pt_6f03a0 operator+(const Pt_6f03a0& rhs) const;
    Pt_6f03a0 operator*(float s) const;
};

struct Elem_6f03a0
{
    int unk00;
    int unk04;
    Pt_6f03a0 pos08;
    int unk14;
    int unk18;
    int unk1c;
    Pt_6f03a0 pos20;
    Pt_6f03a0 pos2c;
};

struct Arr_6f03a0
{
    unsigned int GetSize();
    Elem_6f03a0*& GetAt(unsigned int i);
};

struct Host_6f03a0
{
    int unk[36];
    Arr_6f03a0 arr90;
    void FUN_006f03a0();
};

// For each element in arr90, sets pos08 to the sum of pos20 and pos2c scaled by DAT_01016248.
// @fnv 0x006f03a0
void Host_6f03a0::FUN_006f03a0()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr90))->GetName())); ++i)
    {
        arr90.GetAt(i)->pos08 = (arr90.GetAt(i)->pos20 + arr90.GetAt(i)->pos2c) * ::fnv_00c88020::DAT_01016248;
    }
}

namespace fnv_006f1d30 {
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator+(const NiPoint3& pt) const;
    NiPoint3 operator-(const NiPoint3& pt) const;
    NiPoint3 operator*(float fScalar) const;
};

struct PathLocStub
{
};

struct PathNodeStub
{
};

struct PathSolutionStub
{
};


struct PathSmoother
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
    PathSolutionStub* m_pOutputSolution;
    void SmoothPathDirections();
};

// @fnv 0x006f1d30
void PathSmoother::SmoothPathDirections()
{
    for (unsigned int i = 1; i < ::GetObjectFlags((char *)(m_pOutputSolution)) - 1; i++)
    {
        NiPoint3 kNextVal = (*(::fnv_006f1d30::NiPoint3 *)&(reinterpret_cast<::TaskQueueInterface *>((((::fnv_006f1d30::PathLocStub *)(reinterpret_cast<::BaseProcess *>((((::fnv_006f1d30::PathNodeStub *)(reinterpret_cast<::FUN_006e7970_shell *>((m_pOutputSolution))->FUN_006e7970(i + 1)))))->GetCurrentProcessData()))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))) -
                            (*(::fnv_006f1d30::NiPoint3 *)&(reinterpret_cast<::TaskQueueInterface *>((((::fnv_006f1d30::PathLocStub *)(reinterpret_cast<::BaseProcess *>((((::fnv_006f1d30::PathNodeStub *)(reinterpret_cast<::FUN_006e7970_shell *>((m_pOutputSolution))->FUN_006e7970(i)))))->GetCurrentProcessData()))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        float fNextLenTmp = reinterpret_cast<::NiPoint3 *>((void *)&(kNextVal))->GetLengthSquared();
        NiPoint3 kPrev_ = (*(::fnv_006f1d30::NiPoint3 *)&(reinterpret_cast<::TaskQueueInterface *>((((::fnv_006f1d30::PathLocStub *)(reinterpret_cast<::BaseProcess *>((((::fnv_006f1d30::PathNodeStub *)(reinterpret_cast<::FUN_006e7970_shell *>((m_pOutputSolution))->FUN_006e7970(i)))))->GetCurrentProcessData()))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))) -
                          (*(::fnv_006f1d30::NiPoint3 *)&(reinterpret_cast<::TaskQueueInterface *>((((::fnv_006f1d30::PathLocStub *)(reinterpret_cast<::BaseProcess *>((((::fnv_006f1d30::PathNodeStub *)(reinterpret_cast<::FUN_006e7970_shell *>((m_pOutputSolution))->FUN_006e7970(i - 1)))))->GetCurrentProcessData()))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        float fPrevLen = reinterpret_cast<::NiPoint3 *>((void *)&(kPrev_))->GetLengthSquared();
        float fLen = ::FUN_0040ebd0(fNextLenTmp, fPrevLen);
        reinterpret_cast<::FUN_006b0570_shell *>((((::fnv_006f1d30::PathNodeStub *)(reinterpret_cast<::FUN_006e7970_shell *>((m_pOutputSolution))->FUN_006e7970(i)))))->FUN_006b0570((::NiColor *)&(const ::fnv_006f1d30::NiPoint3 &)((kNextVal + kPrev_) * fLen * ::fnv_00c88020::DAT_01016248));
    }
}
}  // namespace fnv_006f1d30

struct S_00aa42e0_Mgr
{
    void* FUN_00aa42e0();
};
S_00aa42e0_Mgr* __cdecl FUN_00401020();

struct S_006f2510_Base
{
    int unk04;
    int unk08;
    int unk0c;
    S_006f2510_Base();
    virtual ~S_006f2510_Base();
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};

struct FUN_006f2510 : S_006f2510_Base
{
    void* unk10;
    FUN_006f2510(unsigned int a, unsigned int b, void* heap);
    virtual ~FUN_006f2510();
};
// Calls GetItem on the four perk lists, invokes FUN_006f2510 with (0, 0, a1), and returns this.
// @fnv 0x006edce0
FUN_006edce0_Class* FUN_006edce0_Class::FUN_006edce0(int a1)
{
    new ((void *)&(l0)) ::Vec3();
    new ((void *)&(l1)) ::Vec3();
    new ((void *)&(l2)) ::Vec3();
    new ((void *)&(l3)) ::Vec3();
    new ((void *)&(f)) ::FUN_006f2510(0, 0, (void *)(a1));
    return this;
}

// @fnv 0x006f2510
FUN_006f2510::FUN_006f2510(unsigned int a, unsigned int b, void* heap)
{
    unk10 = heap ? heap : ((void *)(reinterpret_cast<::MemoryManager *>((FUN_00401020()))->GetGeneralAllocator()));
    FUN_006b3eb0(a, b);
}

struct LOSElem
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
};

struct LOSArray6f29e0
{
    virtual void v0();
    virtual LOSElem* Allocate(unsigned int count);
    LOSElem* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Clear(bool shrink);
    void RemoveRange(unsigned int index, unsigned int count, bool shrink);
};

// Removes count elements starting at index from the array, optionally shrinking capacity, and updates the element count.
// @fnv 0x006f29e0
void LOSArray6f29e0::RemoveRange(unsigned int index, unsigned int count, bool shrink)
{
    if (count >= m_iElementCount)
    {
        reinterpret_cast<::NavMeshSearchLOSArray *>(this)->Clear(shrink);
        return;
    }
    if (shrink && reinterpret_cast<::FUN_006f3170_Class *>(this)->FUN_006f3170())
    {
        unsigned int newCapacity = reinterpret_cast<::FUN_00869600_Class *>(this)->FUN_00869600();
        LOSElem* newData2 = Allocate(newCapacity);
        reinterpret_cast<::FUN_006928a0_class *>(this)->FUN_006928a0((char *)(newData2), (char *)(m_data), index);
        reinterpret_cast<::S_006ac070 *>(this)->FUN_006ac070((::Elem_006ac070 *)(::LOSElem *)(m_data + index), count);
        reinterpret_cast<::FUN_006928a0_class *>(this)->FUN_006928a0((char *)(::LOSElem *)(newData2 + index), (char *)(::LOSElem *)(m_data + index + count), m_iElementCount - count);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        m_data = newData2;
        m_pRayCursor = newCapacity;
    }
    else
    {
        reinterpret_cast<::S_006ac070 *>(this)->FUN_006ac070((::Elem_006ac070 *)(::LOSElem *)(m_data + index), count);
        reinterpret_cast<::FUN_006928a0_class *>(this)->FUN_006928a0((char *)(::LOSElem *)(m_data + index), (char *)(::LOSElem *)(m_data + index + count), m_iElementCount - index - count);
    }
    m_iElementCount -= count;
}

namespace fnv_006f2ca0 {
extern int DAT_0106c990;

void* __cdecl FUN_00401020();

struct FUN_00aa42e0_Obj
{
    int FUN_00aa42e0();
};

struct Base_b9887
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;

    Base_b9887();
    ~Base_b9887();
};

struct FUN_006f2ca0_cls : Base_b9887
{
    int m_i10;  // +0x10


    FUN_006f2ca0_cls(int a1);
};

// Sets the vtable pointer, stores the result of FUN_00aa42e0 from FUN_00401020 into m_i10, then calls FUN_0069b940 with a1 twice.
// @fnv 0x006f2ca0
FUN_006f2ca0_cls::FUN_006f2ca0_cls(int a1)
{
    *(void**)this = &DAT_0106c990;
    m_i10 = ((int)(reinterpret_cast<::MemoryManager *>((((FUN_00aa42e0_Obj*)FUN_00401020())))->GetGeneralAllocator()));
    reinterpret_cast<::FUN_0069b940_class *>(this)->FUN_0069b940(a1, a1);
}
}  // namespace fnv_006f2ca0

namespace fnv_006f2d80 {
struct ObjCls
{
    void* FUN_00aa42e0();
};
extern ObjCls* __cdecl FUN_00401020();
extern int DAT_0106d878;
struct B31c0
{
    B31c0();
    ~B31c0();
};
struct FUN_006f2d80 : public B31c0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_10;
    FUN_006f2d80();
};
// Sets the vtable pointer, stores the result of FUN_00aa42e0 from FUN_00401020 in m_10, then calls InitBuffer with 0, 0.
// @fnv 0x006f2d80
FUN_006f2d80::FUN_006f2d80() : B31c0()
{
    *(void**)this = &DAT_0106d878;
    this->m_10 = ((void *)(reinterpret_cast<::MemoryManager *>((FUN_00401020()))->GetGeneralAllocator()));
    ((FUN_006f3320_Class*)this)->InitBuffer(0, 0);
}
}  // namespace fnv_006f2d80

class Base_6f33b0
{
  public:
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    Base_6f33b0();
    ~Base_6f33b0();
};

class Member_6f33b0_2064
{
  public:
    int m_00;
    Member_6f33b0_2064();
    ~Member_6f33b0_2064();
};

class Member_6f33b0_20a4
{
  public:
    int m_00;
    Member_6f33b0_20a4();
    ~Member_6f33b0_20a4();
};

class FUN_006f33b0_cls : public Base_6f33b0
{
  public:
    virtual void v00();
    int unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C,
        unk0040, unk0044, unk0048, unk004C;
    int unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C,
        unk0080, unk0084, unk0088, unk008C;
    int unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC,
        unk00C0, unk00C4, unk00C8, unk00CC;
    int unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC,
        unk0100, unk0104, unk0108, unk010C;
    int unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C,
        unk0140, unk0144, unk0148, unk014C;
    int unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C,
        unk0180, unk0184, unk0188, unk018C;
    int unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC,
        unk01C0, unk01C4, unk01C8, unk01CC;
    int unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC,
        unk0200, unk0204, unk0208, unk020C;
    int unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C,
        unk0240, unk0244, unk0248, unk024C;
    int unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C,
        unk0280, unk0284, unk0288, unk028C;
    int unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC,
        unk02C0, unk02C4, unk02C8, unk02CC;
    int unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC,
        unk0300, unk0304, unk0308, unk030C;
    int unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C,
        unk0340, unk0344, unk0348, unk034C;
    int unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C,
        unk0380, unk0384, unk0388, unk038C;
    int unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC,
        unk03C0, unk03C4, unk03C8, unk03CC;
    int unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC,
        unk0400, unk0404, unk0408, unk040C;
    int unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C,
        unk0440, unk0444, unk0448, unk044C;
    int unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C,
        unk0480, unk0484, unk0488, unk048C;
    int unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC,
        unk04C0, unk04C4, unk04C8, unk04CC;
    int unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC,
        unk0500, unk0504, unk0508, unk050C;
    int unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C,
        unk0540, unk0544, unk0548, unk054C;
    int unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C,
        unk0580, unk0584, unk0588, unk058C;
    int unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC,
        unk05C0, unk05C4, unk05C8, unk05CC;
    int unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC,
        unk0600, unk0604, unk0608, unk060C;
    int unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C,
        unk0640, unk0644, unk0648, unk064C;
    int unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C,
        unk0680, unk0684, unk0688, unk068C;
    int unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC,
        unk06C0, unk06C4, unk06C8, unk06CC;
    int unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC,
        unk0700, unk0704, unk0708, unk070C;
    int unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C,
        unk0740, unk0744, unk0748, unk074C;
    int unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C,
        unk0780, unk0784, unk0788, unk078C;
    int unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC,
        unk07C0, unk07C4, unk07C8, unk07CC;
    int unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC,
        unk0800, unk0804, unk0808, unk080C;
    int unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C,
        unk0840, unk0844, unk0848, unk084C;
    int unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C,
        unk0880, unk0884, unk0888, unk088C;
    int unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC,
        unk08C0, unk08C4, unk08C8, unk08CC;
    int unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC,
        unk0900, unk0904, unk0908, unk090C;
    int unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C,
        unk0940, unk0944, unk0948, unk094C;
    int unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C,
        unk0980, unk0984, unk0988, unk098C;
    int unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC,
        unk09C0, unk09C4, unk09C8, unk09CC;
    int unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC,
        unk0A00, unk0A04, unk0A08, unk0A0C;
    int unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C,
        unk0A40, unk0A44, unk0A48, unk0A4C;
    int unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C,
        unk0A80, unk0A84, unk0A88, unk0A8C;
    int unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC,
        unk0AC0, unk0AC4, unk0AC8, unk0ACC;
    int unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC,
        unk0B00, unk0B04, unk0B08, unk0B0C;
    int unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C,
        unk0B40, unk0B44, unk0B48, unk0B4C;
    int unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C,
        unk0B80, unk0B84, unk0B88, unk0B8C;
    int unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC,
        unk0BC0, unk0BC4, unk0BC8, unk0BCC;
    int unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC,
        unk0C00, unk0C04, unk0C08, unk0C0C;
    int unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C,
        unk0C40, unk0C44, unk0C48, unk0C4C;
    int unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C,
        unk0C80, unk0C84, unk0C88, unk0C8C;
    int unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC,
        unk0CC0, unk0CC4, unk0CC8, unk0CCC;
    int unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC,
        unk0D00, unk0D04, unk0D08, unk0D0C;
    int unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C,
        unk0D40, unk0D44, unk0D48, unk0D4C;
    int unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C,
        unk0D80, unk0D84, unk0D88, unk0D8C;
    int unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC,
        unk0DC0, unk0DC4, unk0DC8, unk0DCC;
    int unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC,
        unk0E00, unk0E04, unk0E08, unk0E0C;
    int unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C,
        unk0E40, unk0E44, unk0E48, unk0E4C;
    int unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C,
        unk0E80, unk0E84, unk0E88, unk0E8C;
    int unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC,
        unk0EC0, unk0EC4, unk0EC8, unk0ECC;
    int unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC,
        unk0F00, unk0F04, unk0F08, unk0F0C;
    int unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C,
        unk0F40, unk0F44, unk0F48, unk0F4C;
    int unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C,
        unk0F80, unk0F84, unk0F88, unk0F8C;
    int unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC,
        unk0FC0, unk0FC4, unk0FC8, unk0FCC;
    int unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC,
        unk1000, unk1004, unk1008, unk100C;
    int unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C,
        unk1040, unk1044, unk1048, unk104C;
    int unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C,
        unk1080, unk1084, unk1088, unk108C;
    int unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC,
        unk10C0, unk10C4, unk10C8, unk10CC;
    int unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC,
        unk1100, unk1104, unk1108, unk110C;
    int unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C,
        unk1140, unk1144, unk1148, unk114C;
    int unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C,
        unk1180, unk1184, unk1188, unk118C;
    int unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC,
        unk11C0, unk11C4, unk11C8, unk11CC;
    int unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC,
        unk1200, unk1204, unk1208, unk120C;
    int unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C,
        unk1240, unk1244, unk1248, unk124C;
    int unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C,
        unk1280, unk1284, unk1288, unk128C;
    int unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC,
        unk12C0, unk12C4, unk12C8, unk12CC;
    int unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC,
        unk1300, unk1304, unk1308, unk130C;
    int unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C,
        unk1340, unk1344, unk1348, unk134C;
    int unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C,
        unk1380, unk1384, unk1388, unk138C;
    int unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC,
        unk13C0, unk13C4, unk13C8, unk13CC;
    int unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC,
        unk1400, unk1404, unk1408, unk140C;
    int unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C,
        unk1440, unk1444, unk1448, unk144C;
    int unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C,
        unk1480, unk1484, unk1488, unk148C;
    int unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC,
        unk14C0, unk14C4, unk14C8, unk14CC;
    int unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC,
        unk1500, unk1504, unk1508, unk150C;
    int unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C,
        unk1540, unk1544, unk1548, unk154C;
    int unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C,
        unk1580, unk1584, unk1588, unk158C;
    int unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC,
        unk15C0, unk15C4, unk15C8, unk15CC;
    int unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC,
        unk1600, unk1604, unk1608, unk160C;
    int unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C,
        unk1640, unk1644, unk1648, unk164C;
    int unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C,
        unk1680, unk1684, unk1688, unk168C;
    int unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC,
        unk16C0, unk16C4, unk16C8, unk16CC;
    int unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC,
        unk1700, unk1704, unk1708, unk170C;
    int unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C,
        unk1740, unk1744, unk1748, unk174C;
    int unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C,
        unk1780, unk1784, unk1788, unk178C;
    int unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC,
        unk17C0, unk17C4, unk17C8, unk17CC;
    int unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC,
        unk1800, unk1804, unk1808, unk180C;
    int unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C,
        unk1840, unk1844, unk1848, unk184C;
    int unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C,
        unk1880, unk1884, unk1888, unk188C;
    int unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC,
        unk18C0, unk18C4, unk18C8, unk18CC;
    int unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC,
        unk1900, unk1904, unk1908, unk190C;
    int unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C,
        unk1940, unk1944, unk1948, unk194C;
    int unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C,
        unk1980, unk1984, unk1988, unk198C;
    int unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC,
        unk19C0, unk19C4, unk19C8, unk19CC;
    int unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC,
        unk1A00, unk1A04, unk1A08, unk1A0C;
    int unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C,
        unk1A40, unk1A44, unk1A48, unk1A4C;
    int unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C,
        unk1A80, unk1A84, unk1A88, unk1A8C;
    int unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC,
        unk1AC0, unk1AC4, unk1AC8, unk1ACC;
    int unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC,
        unk1B00, unk1B04, unk1B08, unk1B0C;
    int unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C,
        unk1B40, unk1B44, unk1B48, unk1B4C;
    int unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C,
        unk1B80, unk1B84, unk1B88, unk1B8C;
    int unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC,
        unk1BC0, unk1BC4, unk1BC8, unk1BCC;
    int unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC,
        unk1C00, unk1C04, unk1C08, unk1C0C;
    int unk1C10, unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C,
        unk1C40, unk1C44, unk1C48, unk1C4C;
    int unk1C50, unk1C54, unk1C58, unk1C5C, unk1C60, unk1C64, unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C,
        unk1C80, unk1C84, unk1C88, unk1C8C;
    int unk1C90, unk1C94, unk1C98, unk1C9C, unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC,
        unk1CC0, unk1CC4, unk1CC8, unk1CCC;
    int unk1CD0, unk1CD4, unk1CD8, unk1CDC, unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC,
        unk1D00, unk1D04, unk1D08, unk1D0C;
    int unk1D10, unk1D14, unk1D18, unk1D1C, unk1D20, unk1D24, unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C,
        unk1D40, unk1D44, unk1D48, unk1D4C;
    int unk1D50, unk1D54, unk1D58, unk1D5C, unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C,
        unk1D80, unk1D84, unk1D88, unk1D8C;
    int unk1D90, unk1D94, unk1D98, unk1D9C, unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC,
        unk1DC0, unk1DC4, unk1DC8, unk1DCC;
    int unk1DD0, unk1DD4, unk1DD8, unk1DDC, unk1DE0, unk1DE4, unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC,
        unk1E00, unk1E04, unk1E08, unk1E0C;
    int unk1E10, unk1E14, unk1E18, unk1E1C, unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C,
        unk1E40, unk1E44, unk1E48, unk1E4C;
    int unk1E50, unk1E54, unk1E58, unk1E5C, unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C,
        unk1E80, unk1E84, unk1E88, unk1E8C;
    int unk1E90, unk1E94, unk1E98, unk1E9C, unk1EA0, unk1EA4, unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC,
        unk1EC0, unk1EC4, unk1EC8, unk1ECC;
    int unk1ED0, unk1ED4, unk1ED8, unk1EDC, unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC,
        unk1F00, unk1F04, unk1F08, unk1F0C;
    int unk1F10, unk1F14, unk1F18, unk1F1C, unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C,
        unk1F40, unk1F44, unk1F48, unk1F4C;
    int unk1F50, unk1F54, unk1F58, unk1F5C, unk1F60, unk1F64, unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C,
        unk1F80, unk1F84, unk1F88, unk1F8C;
    int unk1F90, unk1F94, unk1F98, unk1F9C, unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC,
        unk1FC0, unk1FC4, unk1FC8, unk1FCC;
    int unk1FD0, unk1FD4, unk1FD8, unk1FDC, unk1FE0, unk1FE4, unk1FE8, unk1FEC, unk1FF0, unk1FF4, unk1FF8, unk1FFC,
        unk2000, unk2004, unk2008, unk200C;
    int unk2010, unk2014, unk2018, unk201C, unk2020, unk2024, unk2028, unk202C, unk2030, unk2034, unk2038, unk203C,
        unk2040, unk2044, unk2048, unk204C;
    int unk2050, unk2054, unk2058, unk205C, unk2060;
    Member_6f33b0_2064 m_2064;
    int unk2068, unk206C, unk2070, unk2074, unk2078, unk207C, unk2080, unk2084, unk2088, unk208C, unk2090, unk2094,
        unk2098, unk209C, unk20A0;
    Member_6f33b0_20a4 m_20a4;

    FUN_006f33b0_cls();
};

// Empty constructor for the class; the base and member subobjects are initialized by their own constructors.
// @fnv 0x006f33b0
FUN_006f33b0_cls::FUN_006f33b0_cls()
{}

extern unsigned int DAT_0106d90c;

struct FUN_006f4320
{
    unsigned int m_pTreeNode;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    unsigned int m_uiFirstValue;
    FUN_006f4320();
    ~FUN_006f4320();
};

struct FUN_006b3de0
{
    unsigned int m_entries[2040];
    FUN_006b3de0();
    ~FUN_006b3de0();
};

struct FUN_006b9470
{
    unsigned int m_auiBitFieldWords[21];
    FUN_006b9470();
};

struct FUN_006f3bd0
{
    unsigned int* m_ppVirtualMethodTable;
    FUN_006f4320 m_pStreamAllocator;
    FUN_006b3de0 m_entries;
    FUN_006b9470 m_lookup;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
    unsigned int m_uiEdgeIndex;
    unsigned char m_sState;
    FUN_006f3bd0();
};

// @fnv 0x006f3bd0
FUN_006f3bd0::FUN_006f3bd0() : m_ppVirtualMethodTable(&DAT_0106d90c), m_uiItemCount(0), m_pRayCursor(0), m_uiEdgeIndex(0), m_sState(0)
{}

struct S_006f3d00_Vec3
{
    float x, y, z;
};

struct S_006f3d00_Node
{
    int unk0;
    float unk4;
    S_006f3d00_Vec3 unk8;
};

struct S_006f3d00_List
{
    int unk0;
};

struct S_006f3d00_Obj
{
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234,
        unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274,
        unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4,
        unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4,
        unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c, unk330, unk334,
        unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c, unk370, unk374,
        unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4,
        unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4,
        unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c, unk420, unk424, unk428, unk42c, unk430, unk434,
        unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474,
        unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4,
        unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4,
        unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534,
        unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c, unk570, unk574,
        unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c, unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4,
        unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4,
        unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c, unk620, unk624, unk628, unk62c, unk630, unk634,
        unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c, unk660, unk664, unk668, unk66c, unk670, unk674,
        unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c, unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4,
        unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc, unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4,
        unk6f8, unk6fc;
    int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c, unk720, unk724, unk728, unk72c, unk730, unk734,
        unk738, unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c, unk760, unk764, unk768, unk76c, unk770, unk774,
        unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c, unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4,
        unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc, unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4,
        unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c, unk820, unk824, unk828, unk82c, unk830, unk834,
        unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c, unk860, unk864, unk868, unk86c, unk870, unk874,
        unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c, unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4,
        unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc, unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4,
        unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c, unk920, unk924, unk928, unk92c, unk930, unk934,
        unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c, unk960, unk964, unk968, unk96c, unk970, unk974,
        unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c, unk9a0, unk9a4, unk9a8, unk9ac, unk9b0, unk9b4,
        unk9b8, unk9bc;
    int unk9c0, unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc, unk9e0, unk9e4, unk9e8, unk9ec, unk9f0, unk9f4,
        unk9f8, unk9fc;
    int unka00, unka04, unka08, unka0c, unka10, unka14, unka18, unka1c, unka20, unka24, unka28, unka2c, unka30, unka34,
        unka38, unka3c;
    int unka40, unka44, unka48, unka4c, unka50, unka54, unka58, unka5c, unka60, unka64, unka68, unka6c, unka70, unka74,
        unka78, unka7c;
    int unka80, unka84, unka88, unka8c, unka90, unka94, unka98, unka9c, unkaa0, unkaa4, unkaa8, unkaac, unkab0, unkab4,
        unkab8, unkabc;
    int unkac0, unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc, unkae0, unkae4, unkae8, unkaec, unkaf0, unkaf4,
        unkaf8, unkafc;
    int unkb00, unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c, unkb20, unkb24, unkb28, unkb2c, unkb30, unkb34,
        unkb38, unkb3c;
    int unkb40, unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c, unkb60, unkb64, unkb68, unkb6c, unkb70, unkb74,
        unkb78, unkb7c;
    int unkb80, unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c, unkba0, unkba4, unkba8, unkbac, unkbb0, unkbb4,
        unkbb8, unkbbc;
    int unkbc0, unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc, unkbe0, unkbe4, unkbe8, unkbec, unkbf0, unkbf4,
        unkbf8, unkbfc;
    int unkc00, unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c, unkc20, unkc24, unkc28, unkc2c, unkc30, unkc34,
        unkc38, unkc3c;
    int unkc40, unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c, unkc60, unkc64, unkc68, unkc6c, unkc70, unkc74,
        unkc78, unkc7c;
    int unkc80, unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c, unkca0, unkca4, unkca8, unkcac, unkcb0, unkcb4,
        unkcb8, unkcbc;
    int unkcc0, unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc, unkce0, unkce4, unkce8, unkcec, unkcf0, unkcf4,
        unkcf8, unkcfc;
    int unkd00, unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c, unkd20, unkd24, unkd28, unkd2c, unkd30, unkd34,
        unkd38, unkd3c;
    int unkd40, unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c, unkd60, unkd64, unkd68, unkd6c, unkd70, unkd74,
        unkd78, unkd7c;
    int unkd80, unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c, unkda0, unkda4, unkda8, unkdac, unkdb0, unkdb4,
        unkdb8, unkdbc;
    int unkdc0, unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc, unkde0, unkde4, unkde8, unkdec, unkdf0, unkdf4,
        unkdf8, unkdfc;
    int unke00, unke04, unke08, unke0c, unke10, unke14, unke18, unke1c, unke20, unke24, unke28, unke2c, unke30, unke34,
        unke38, unke3c;
    int unke40, unke44, unke48, unke4c, unke50, unke54, unke58, unke5c, unke60, unke64, unke68, unke6c, unke70, unke74,
        unke78, unke7c;
    int unke80, unke84, unke88, unke8c, unke90, unke94, unke98, unke9c, unkea0, unkea4, unkea8, unkeac, unkeb0, unkeb4,
        unkeb8, unkebc;
    int unkec0, unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc, unkee0, unkee4, unkee8, unkeec, unkef0, unkef4,
        unkef8, unkefc;
    int unkf00, unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c, unkf20, unkf24, unkf28, unkf2c, unkf30, unkf34,
        unkf38, unkf3c;
    int unkf40, unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c, unkf60, unkf64, unkf68, unkf6c, unkf70, unkf74,
        unkf78, unkf7c;
    int unkf80, unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c, unkfa0, unkfa4, unkfa8, unkfac, unkfb0, unkfb4,
        unkfb8, unkfbc;
    int unkfc0, unkfc4, unkfc8, unkfcc, unkfd0, unkfd4, unkfd8, unkfdc, unkfe0, unkfe4, unkfe8, unkfec, unkff0, unkff4,
        unkff8, unkffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020, unk1024, unk1028, unk102c,
        unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c, unk1060, unk1064, unk1068, unk106c,
        unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0, unk10a4, unk10a8, unk10ac,
        unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0, unk10e4, unk10e8, unk10ec,
        unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c, unk1120, unk1124, unk1128, unk112c,
        unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160, unk1164, unk1168, unk116c,
        unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0, unk11a4, unk11a8, unk11ac,
        unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc, unk11e0, unk11e4, unk11e8, unk11ec,
        unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220, unk1224, unk1228, unk122c,
        unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260, unk1264, unk1268, unk126c,
        unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c, unk12a0, unk12a4, unk12a8, unk12ac,
        unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0, unk12e4, unk12e8, unk12ec,
        unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320, unk1324, unk1328, unk132c,
        unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c, unk1360, unk1364, unk1368, unk136c,
        unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0, unk13a4, unk13a8, unk13ac,
        unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0, unk13e4, unk13e8, unk13ec,
        unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c, unk1420, unk1424, unk1428, unk142c,
        unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460, unk1464, unk1468, unk146c,
        unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0, unk14a4, unk14a8, unk14ac,
        unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc, unk14e0, unk14e4, unk14e8, unk14ec,
        unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520, unk1524, unk1528, unk152c,
        unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560, unk1564, unk1568, unk156c,
        unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c, unk15a0, unk15a4, unk15a8, unk15ac,
        unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0, unk15e4, unk15e8, unk15ec,
        unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620, unk1624, unk1628, unk162c,
        unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c, unk1660, unk1664, unk1668, unk166c,
        unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0, unk16a4, unk16a8, unk16ac,
        unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0, unk16e4, unk16e8, unk16ec,
        unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c, unk1720, unk1724, unk1728, unk172c,
        unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760, unk1764, unk1768, unk176c,
        unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0, unk17a4, unk17a8, unk17ac,
        unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc, unk17e0, unk17e4, unk17e8, unk17ec,
        unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820, unk1824, unk1828, unk182c,
        unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860, unk1864, unk1868, unk186c,
        unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c, unk18a0, unk18a4, unk18a8, unk18ac,
        unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0, unk18e4, unk18e8, unk18ec,
        unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920, unk1924, unk1928, unk192c,
        unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c, unk1960, unk1964, unk1968, unk196c,
        unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0, unk19a4, unk19a8, unk19ac,
        unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0, unk19e4, unk19e8, unk19ec,
        unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c, unk1a20, unk1a24, unk1a28, unk1a2c,
        unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60, unk1a64, unk1a68, unk1a6c,
        unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0, unk1aa4, unk1aa8, unk1aac,
        unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc, unk1ae0, unk1ae4, unk1ae8, unk1aec,
        unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20, unk1b24, unk1b28, unk1b2c,
        unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60, unk1b64, unk1b68, unk1b6c,
        unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c, unk1ba0, unk1ba4, unk1ba8, unk1bac,
        unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc, unk1be0, unk1be4, unk1be8, unk1bec,
        unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    int unk1c00, unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c, unk1c20, unk1c24, unk1c28, unk1c2c,
        unk1c30, unk1c34, unk1c38, unk1c3c;
    int unk1c40, unk1c44, unk1c48, unk1c4c, unk1c50, unk1c54, unk1c58, unk1c5c, unk1c60, unk1c64, unk1c68, unk1c6c,
        unk1c70, unk1c74, unk1c78, unk1c7c;
    int unk1c80, unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c, unk1ca0, unk1ca4, unk1ca8, unk1cac,
        unk1cb0, unk1cb4, unk1cb8, unk1cbc;
    int unk1cc0, unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc, unk1ce0, unk1ce4, unk1ce8, unk1cec,
        unk1cf0, unk1cf4, unk1cf8, unk1cfc;
    int unk1d00, unk1d04, unk1d08, unk1d0c, unk1d10, unk1d14, unk1d18, unk1d1c, unk1d20, unk1d24, unk1d28, unk1d2c,
        unk1d30, unk1d34, unk1d38, unk1d3c;
    int unk1d40, unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c, unk1d60, unk1d64, unk1d68, unk1d6c,
        unk1d70, unk1d74, unk1d78, unk1d7c;
    int unk1d80, unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c, unk1da0, unk1da4, unk1da8, unk1dac,
        unk1db0, unk1db4, unk1db8, unk1dbc;
    int unk1dc0, unk1dc4, unk1dc8, unk1dcc, unk1dd0, unk1dd4, unk1dd8, unk1ddc, unk1de0, unk1de4, unk1de8, unk1dec,
        unk1df0, unk1df4, unk1df8, unk1dfc;
    int unk1e00, unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c, unk1e20, unk1e24, unk1e28, unk1e2c,
        unk1e30, unk1e34, unk1e38, unk1e3c;
    int unk1e40, unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c, unk1e60, unk1e64, unk1e68, unk1e6c,
        unk1e70, unk1e74, unk1e78, unk1e7c;
    int unk1e80, unk1e84, unk1e88, unk1e8c, unk1e90, unk1e94, unk1e98, unk1e9c, unk1ea0, unk1ea4, unk1ea8, unk1eac,
        unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    int unk1ec0, unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc, unk1ee0, unk1ee4, unk1ee8, unk1eec,
        unk1ef0, unk1ef4, unk1ef8, unk1efc;
    int unk1f00, unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c, unk1f20, unk1f24, unk1f28, unk1f2c,
        unk1f30, unk1f34, unk1f38, unk1f3c;
    int unk1f40, unk1f44, unk1f48, unk1f4c, unk1f50, unk1f54, unk1f58, unk1f5c, unk1f60, unk1f64, unk1f68, unk1f6c,
        unk1f70, unk1f74, unk1f78, unk1f7c;
    int unk1f80, unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c, unk1fa0, unk1fa4, unk1fa8, unk1fac,
        unk1fb0, unk1fb4, unk1fb8, unk1fbc;
    int unk1fc0, unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc, unk1fe0, unk1fe4, unk1fe8, unk1fec,
        unk1ff0;
    S_006f3d00_List unk1ff4;
    int unk1ff8, unk1ffc, unk2000, unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c, unk2020, unk2024,
        unk2028, unk202c, unk2030, unk2034;
    int unk2038, unk203c, unk2040, unk2044, unk2048, unk204c;
    S_006f3d00_Node* unk2050;
    S_006f3d00_Node* FUN_006f3d00(int key, S_006f3d00_Vec3* pos, float f);
};

namespace fnv_006f45c0 {
struct FUN_006f4880
{
    int baseVptr;
    FUN_006f4880();
    ~FUN_006f4880();
};
struct FUN_006f45c0 : FUN_006f4880
{
    int unk04;
    int unk08;
    int unk0c;
    int value10;
    FUN_006f45c0();
};
extern int str_0106d91c;
struct Helper_00401020
{
    int FUN_00aa42e0();
};
extern "C" Helper_00401020* __cdecl FUN_00401020();
// Sets the vtable pointer, stores the result of FUN_00401020()->FUN_00aa42e0() in value10, then calls FUN_006b3eb0(0, 0) on this.
// @fnv 0x006f45c0
FUN_006f45c0::FUN_006f45c0() : FUN_006f4880()
{
    baseVptr = (int)&str_0106d91c;
    value10 = ((int)(reinterpret_cast<::MemoryManager *>((FUN_00401020()))->GetGeneralAllocator()));
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
}
}  // namespace fnv_006f45c0

class SpawnedArg
{
  public:
    float m_00;
};

extern const double DAT_010356e8;

class FUN_006f4790_cls
{
  public:
    float m_00;
    unsigned int GetScaledValue(SpawnedArg* p);
};

// Reads p's value; returns 0x13 if it is at least m_00, otherwise returns the value scaled by DAT_010356e8 divided by m_00.
// @fnv 0x006f4790
unsigned int FUN_006f4790_cls::GetScaledValue(SpawnedArg* pSpawnedArg)
{
    float f = reinterpret_cast<::FUN_006b9710_Class *>((pSpawnedArg))->GetSum();
    if (f >= m_00)
    {
        return 0x13;
    }
    else
    {
        return (unsigned int)((f * DAT_010356e8) / m_00);
    }
}

struct DTB_Ref
{
};

struct DTB_Task
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Start();
};

struct DTB_TaskPtr
{
    DTB_Task* m_pObject;
    DTB_TaskPtr(DTB_Task* p);
    ~DTB_TaskPtr();
    DTB_TaskPtr& operator=(DTB_Task* p);
    operator DTB_Task*() const;
};

struct DTB_List
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_List();
    ~DTB_List();
};

struct DTB_MapA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_MapA(int size);
    ~DTB_MapA();
};

struct DTB_MapB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_MapB(int size);
    ~DTB_MapB();
};

struct DTB_Array
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DTB_Array();
    ~DTB_Array();
};

struct DTB_MemContext
{
    int unk00;
    DTB_MemContext(MEM_CONTEXT ctx, bool b, const char* file, int line);
    ~DTB_MemContext();
};

extern int DAT_011d859c;
extern int DAT_011d8598;

struct FUN_006f7540;

struct DTB_LoadTask : DTB_Task
{
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
    DTB_LoadTask(FUN_006f7540* block, DTB_Ref* ref, int x, int y, int lod, int flags);
};

struct FUN_006f7540
{
    DTB_TaskPtr m_spTask;
    DTB_List m_kNode;
    DTB_MapA m_mapA;
    DTB_MapB m_mapB;
    DTB_Array m_ppData;
    DTB_Ref* m_pReference;
    bool m_bLoadComplete;
    bool m_bAttached;
    FUN_006f7540(DTB_Ref* ref, int lod, short x, short y);
};

// @fnv 0x006f7540
FUN_006f7540::FUN_006f7540(DTB_Ref* ref, int lod, short x, short y) : m_spTask(0), m_mapA(0x25), m_mapB(0x25)
{
    DTB_MemContext ctx(
        MEM_CONTEXT_MEM_CONTEXT_LODTREES, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantTreeBlock.cpp",
        0x2e);
    DAT_011d859c = lod;
    DAT_011d8598++;
    m_pReference = ref;
    m_bLoadComplete = false;
    m_bAttached = false;
    DTB_Ref* pRootRef = ((::DTB_Ref *)(::FUN_00559450((int *)(((::DTB_Ref *)(::FUN_00559450((int *)(ref))))))));
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::DTB_TaskPtr &)(m_spTask))->FUN_006f74f0((::ObjA *)(::DTB_Task *)(new DTB_LoadTask(this, pRootRef, x, y, lod, 0)));
    ((DTB_Task*)m_spTask)->Start();
}

extern int DAT_011d8598;

struct Sub_b9266A
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266A();
};

struct Sub_b9266B
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266B();
};

struct Sub_b9266C
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266C();
};

struct Sub_b9266D
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9266D();
};

struct Helper_b9266
{
    int unk00;
};


class Base_b9266
{
  public:
    unsigned int m_00;
    ~Base_b9266();
};

class FUN_006f76b0_cls : public Base_b9266
{
  public:
    Sub_b9266A m_04;
    Sub_b9266B m_14;
    Sub_b9266C m_24;
    Sub_b9266D m_34;
    ~FUN_006f76b0_cls();
};

// @fnv 0x006f76b0
FUN_006f76b0_cls::~FUN_006f76b0_cls()
{
    DAT_011d8598--;
    reinterpret_cast<::TreeOwnerS *>(this)->ClearEntries();
    reinterpret_cast<::fnv_006f7780::FUN_006f7780_Class *>(this)->FUN_006f7780();
    if (((unsigned int)(::FUN_00559450((int *)this))) != 0)
    {
        reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::Helper_b9266 * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)(((unsigned int)(::FUN_00559450((int *)this)))), 0);
    }
    reinterpret_cast<::FUN_006f74f0_cls *>(this)->FUN_006f74f0((::ObjA *)(0));
}

struct S_006f9c20_Elem
{
    int unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
};
struct S_006f9c20
{
    int unk00;
    S_006f9c20_Elem* unk04;
    int AddElement(const S_006f9c20_Elem* a1);
};
// @fnv 0x006f9c20
int S_006f9c20::AddElement(const S_006f9c20_Elem* pElem)
{
    int iIndex = reinterpret_cast<::FUN_006b4060_class *>(this)->GetNextIndex();
    reinterpret_cast<::FUN_006fa180_StandIn *>(this)->FUN_006f9ff0((int)(&unk04[iIndex]), 1);
    reinterpret_cast<::FUN_006f9d90_S *>(&(unk04[iIndex]))->operator=((*(const ::FUN_006f9d90_S *)(pElem)));
    return iIndex;
}

void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* p, void* place);

class FNVElem_cls
{
  public:
    FNVElem_cls();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

class FNVOwner_cls
{
  public:
    void ConstructElements(char* base, unsigned int count);
};
// @fnv 0x006f9740
FUN_006f9740_Class* FUN_006f9740_Class::FUN_006f9740()
{
    *(int*)this = (int)&DAT_0106df78;
    reinterpret_cast<::FakeArray *>(this)->ResizeAndFill(0, 0);
    return this;
}
// @fnv 0x006f9f60
void FakeArray::ResizeAndFill(unsigned int auiCapacity, unsigned int auiFillSize)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (auiFillSize > auiCapacity)
        auiCapacity = auiFillSize;
    if (auiCapacity > 0)
    {
        m_iWordAt04 = (int)Write(auiCapacity);
        m_iThirdValue = auiCapacity;
    }
    if (auiFillSize > 0)
    {
        reinterpret_cast<::FNVOwner_cls *>(this)->ConstructElements((char *)(void *)((void*)m_iWordAt04), auiFillSize);
        m_8 = auiFillSize;
    }
}

// Placement-constructs count FNVElem_cls objects at 0x20-byte strides starting at base.
// @fnv 0x006f9e10
void FNVOwner_cls::ConstructElements(char* base, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        new (base + i * 0x20) FNVElem_cls();
    }
}


struct Pair3Pool
{
};

struct Mid
{
    Pair3Pool* Pair();
};

struct Sub
{
};

struct Holder
{
};

struct Item
{
};

struct Cursor
{
};

// Walks the cursor list from DAT_011d8624, and for each item calls Done on the pair reached via Find and via the holders at offsets 0x14 and 0x18.
// @fnv 0x006fa860
void __cdecl FUN_006fa860()
{
    Cursor* cur = (Cursor*)&(*reinterpret_cast<int *>(&::g_011d8624));
    while (cur != 0)
    {
        Item* item = *((::Item **)(new ((void *)(cur)) ::Vec3()));
        if (item != 0)
        {
            Sub* s = ((::Sub *)(::fnv_006fa820::FUN_006fa820((const char *)(item))));
            if (s != 0)
            {
                reinterpret_cast<::FUN_00528820_shell *>((((::Mid *)(reinterpret_cast<::BSFaceGenNiNode *>((s))->GetAnimationData()))->Pair()))->ClearField();
            }

            s = ((::Sub *)(::FUN_00559450((int *)(((Holder*)((char*)item + 0x14))))));
            if (s != 0)
            {
                reinterpret_cast<::FUN_00528820_shell *>((((::Mid *)(reinterpret_cast<::BSFaceGenNiNode *>((s))->GetAnimationData()))->Pair()))->ClearField();
            }

            s = ((::Sub *)(::FUN_00559450((int *)(((Holder*)((char*)item + 0x18))))));
            if (s != 0)
            {
                reinterpret_cast<::FUN_00528820_shell *>((((::Mid *)(reinterpret_cast<::BSFaceGenNiNode *>((s))->GetAnimationData()))->Pair()))->ClearField();
            }
        }
        cur = ((::Cursor *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
}

struct MenuValueTarget
{
    void Assign(const void* value);
};

struct MenuValueSource : TargetObject
{
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int value48;

    void AssignValue(MenuValueTarget* target);
};
// Passes the four entry fields to methods on the object held by m_idle, clears m_idle, sets m_flag, and calls FUN_00929260(1) on the m_go object.
// @fnv 0x006fa990
void TargetObject::FUN_006fa990()
{
    reinterpret_cast<::MenuValueSource *>((reinterpret_cast<TargetObject*>(this->m_idle.operator unsigned int())))->AssignValue((::MenuValueTarget *)(void *)(&this->m_entry4));

    reinterpret_cast<::FUN_006f6250_shell *>((reinterpret_cast<TargetObject*>(this->m_idle.operator unsigned int())))->FUN_006f6250((::FUN_006e5cc0_shell *)(void *)(&this->m_entry8));

    reinterpret_cast<FUN_006faa50_Class*>(this->m_idle.operator unsigned int())->CopyHelperFromOffset(&this->m_entryC);

    reinterpret_cast<FUN_006faa70_Class*>(this->m_idle.operator unsigned int())->FUN_006faa70(&this->m_entry10);

    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QIdlePtr &)(this->m_idle))->FUN_006f74f0((::ObjA *)(void *)(0));
    this->m_flag = true;

    reinterpret_cast<MiddleHighProcess*>(this->m_go->operator unsigned int())->FUN_00929260(1);
}

// @fnv 0x006faa30
void MenuValueSource::AssignValue(MenuValueTarget* target)
{
    target->Assign(&value48);
}


// @fnv 0x006fe540
unsigned char FUN_006fe540()
{
    return ::DAT_011d85a0;
}

// Whether a position still falls inside this area's influence: full areas never accept,
// forced areas always do, otherwise compare the falloff value at the point to the threshold.

class FE550Point2
{
  public:
    float x;
    float y;
    FE550Point2(float fX, float fY);
};

struct FE550Point3
{
    float x;
    float y;
    float z;
};

class FE550List
{
  public:
};

class FE550Area
{
  public:
    FE550List* m_pkList;
    unsigned int m_uiCount;
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
    float m_fCenterX;
    float m_fCenterY;
    int unk3C;
    int unk40;
    float m_fThreshold;

    bool FUN_006fe550(const FE550Point3* pkPos);
};

struct Vec2
{
    float x;
    float y;
    Vec2(float px, float py);
    void Dummy();
};

struct GameSettingRef
{
};


struct FUN_006fe620_cls
{
    int unk00;
    unsigned int m_04;
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
    float m_34;
    float m_38;

    bool FUN_006fe620(Vec2* p);
};

struct S_006fe6d0_Vec2
{
    float x;
    float y;
    S_006fe6d0_Vec2(float ax, float ay);
};
struct S_006fe6d0_Gl
{
};
struct S_006fe6d0
{
    int unk0;
    unsigned int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    float unk34;
    float unk38;
    bool FUN_006fe6d0(const S_006fe6d0_Vec2* p);
};
struct FUN_00452dc0
{
    float x, y;
    FUN_00452dc0(float a, float b);
};

struct S_006fe780_Global
{
};

struct S_006fe780_Foo
{
    int unk00;
    unsigned int unk04;
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
    float unk34;
    float unk38;
    bool FUN_006fe780(const FUN_00452dc0* p);
};

struct FnvVec2
{
    float x;
    float y;
};

struct FnvPt2
{
    float x;
    float y;
    FnvPt2(float, float);
    void* Subtract(FnvVec2* out, FnvPt2& v);
};

float __cdecl ConvertDoubleResult(float);

struct FnvOwner
{
    void* m_10;
    float ComputeDistanceSquaredToRect(FnvPt2 s, float a, float b, float c);
};
// Returns false if the list count matches m_uiCount, true if forced, otherwise compares GetFalloff against m_fThreshold.
// @fnv 0x006fe550
bool FE550Area::FUN_006fe550(const FE550Point3* pkPos)
{
    if (m_uiCount == reinterpret_cast<::BGSTerrainManager *>((m_pkList))->GetMinLevel())
        return false;
    if (reinterpret_cast<::HitRect *>(this)->FUN_006fede0())
        return true;

    FE550Point2 kTestPoint(pkPos->x, pkPos->y);
    FE550Point2 kTargetCenter(m_fCenterX, m_fCenterY);
    float fValue = reinterpret_cast<::FnvOwner *>(this)->ComputeDistanceSquaredToRect((*(::FnvPt2 *)&(const ::FE550Point2 &)(kTargetCenter)), m_uiCount * 4096.0, (*(float *)&(const ::FE550Point2 &)(kTestPoint)), {});
    if (fValue < m_fThreshold)
        return true;
    return false;
}
// @fnv 0x006fe620
bool FUN_006fe620_cls::FUN_006fe620(Vec2* pPoint)
{
    Vec2 a(pPoint->x, pPoint->y);
    Vec2 b(m_34, m_38);
    float r2 = reinterpret_cast<::FnvOwner *>(this)->ComputeDistanceSquaredToRect((*(::FnvPt2 *)&(const ::Vec2 &)(b)), (float)((double)m_04 * DAT_01017a10), (*(float *)&(const ::Vec2 &)(a)), {});
    if (r2 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GameSettingRef *>(&::g_011d877c)))))))
    {
        return true;
    }
    return false;
}
// @fnv 0x006fe6d0
bool S_006fe6d0::FUN_006fe6d0(const S_006fe6d0_Vec2* pPoint)
{
    S_006fe6d0_Vec2 a(pPoint->x, pPoint->y);
    S_006fe6d0_Vec2 b(unk34, unk38);
    float r2 = reinterpret_cast<::FnvOwner *>(this)->ComputeDistanceSquaredToRect((*(::FnvPt2 *)&(const ::S_006fe6d0_Vec2 &)(b)), (float)(unk4 * DAT_01017a10), (*(float *)&(const ::S_006fe6d0_Vec2 &)(a)), {});
    if (r2 < *((float *)&(::FUN_00403e20((float *)&(DAT_011d8724)))))
        return true;
    return false;
}
// Builds a point from p and a point from unk34/unk38, calls ComputeDistanceSquaredToRect with a scaled unk04, and returns whether the result is below the value from DAT_011d8788.
// @fnv 0x006fe780
bool S_006fe780_Foo::FUN_006fe780(const FUN_00452dc0* pPoint)
{
    FUN_00452dc0 a(pPoint->x, pPoint->y);
    float r2;
    FUN_00452dc0 b(unk34, unk38);
    r2 = reinterpret_cast<::FnvOwner *>(this)->ComputeDistanceSquaredToRect((*(::FnvPt2 *)&(const ::FUN_00452dc0 &)(b)), (float)(DAT_01017a10 * (double)unk04), (*(float *)&(const ::FUN_00452dc0 &)(a)), {});
    if (r2 < *((float *)&(::FUN_00403e20((float *)&(DAT_011d8788)))))
        return true;
    return false;
}

// Computes the squared distance from point (b,c) to the axis-aligned square of side a centred at s, returning 0 when inside.
// @fnv 0x006fe830
float FnvOwner::ComputeDistanceSquaredToRect(FnvPt2 aCenter, float afSize, float afPointX, float afPointY)
{
    float gapX;
    float gapY;
    FnvVec2 res;
    aCenter.Subtract(&res, FnvPt2(afSize * 0.5, afSize * 0.5));
    gapX = 0.0f;
    if (afPointX > res.x)
    {
        if (afPointX > res.x + afSize)
        {
            gapX = afPointX - (res.x + afSize);
        }
    }
    else
    {
        gapX = res.x - afPointX;
    }
    gapY = 0.0f;
    if (afPointY > res.y)
    {
        if (afPointY > res.y + afSize)
        {
            gapY = afPointY - (res.y + afSize);
        }
    }
    else
    {
        gapY = res.y - afPointY;
    }
    return ConvertDoubleResult(gapX * gapX + gapY * gapY);
}

struct FUN_00974d90_Class
{
};

struct FUN_006fea70_Class
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00974d90_Class* m_10;
    int m_14;
    int m_18;
    int m_1c;

    FUN_006fea70_Class* m_20[4];

    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char m_33;
    unsigned char m_34;
    unsigned char m_35;
    unsigned char m_36;
    unsigned char m_37;
    unsigned char m_38;
    unsigned char m_39;
    unsigned char m_3a;
    unsigned char m_3b;
    unsigned char m_3c;
    unsigned char m_3d;
    unsigned char m_3e;
    unsigned char m_3f;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    unsigned char m_44;
    unsigned char m_45;
    unsigned char m_46;
    unsigned char m_47;
    unsigned char m_48;
    unsigned char m_49;
    unsigned char m_4a;
    unsigned char m_4b;
    unsigned char m_4c;
    unsigned char m_4d;
    unsigned char m_4e;
    unsigned char m_4f;
    unsigned char m_50;
    unsigned char m_51;
    unsigned char m_52;
    unsigned char m_53;
    unsigned char m_54;

    unsigned char m_55;
    unsigned char m_56;
    unsigned char m_57;
    unsigned char m_58;
    unsigned char m_59;
    unsigned char m_5a;
    unsigned char m_5b;
    unsigned char m_5c;
    unsigned char m_5d;


    void SetValue(int value);
};

// Stand-in for the game's NiPoint2 (float x, float y).  The real constructor
// lives at 0x452dc0 in the image; it is only declared here so that the call
// keeps the original relocation.
struct NiPoint2
{
    float x;
    float y;
    NiPoint2(float a, float b);
};

// Stand-in for the class that owns GetScaleAtPoint.  Only the members the
// function actually touches are modelled, at their original offsets.
struct FnvScaleNode
{
    int unk00;
    unsigned int m04;
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
    float m34;
    float m38;
    int unk3c;
    int unk40;
    int unk44;
    float m48;
    float m4c;
    float GetScaleAtPoint(NiPoint2* arg);
};
// @fnv 0x006fea70
void FUN_006fea70_Class::SetValue(int value)
{
    if (m_10 != 0 && reinterpret_cast<::FOPipboyManager *>((m_10))->IsUnk28Set())
    {
        reinterpret_cast<::Tile *>((m_10))->SetNodeFloat(reinterpret_cast<::FnvScaleNode *>(this)->GetScaleAtPoint((::NiPoint2 *)(value)));

        if (m_54 != 0)
        {
            reinterpret_cast<::FUN_006ff3f0_shell *>(this)->FUN_006ff3f0();
        }

        if (!((bool)(reinterpret_cast<::FUN_006fb150_shell *>(this)->GetByteAtOffset5C())) && m_5d != 0)
        {
            return;
        }
    }

    if (m_20[0] != 0)
    {
        int index;

        for (index = 0; index < 4; ++index)
        {
            m_20[index]->SetValue(value);
        }
    }
}

// Computes a value from the point and m04, then returns 1.0, 0.0, or a scale interpolated between m4c and m48.
// @fnv 0x006feb20
float FnvScaleNode::GetScaleAtPoint(NiPoint2* pPoint)
{
    NiPoint2 aPt(pPoint->x, pPoint->y);
    NiPoint2 inPt(this->m34, this->m38);
    float res = reinterpret_cast<::FnvOwner *>((this))->ComputeDistanceSquaredToRect((*(::FnvPt2 *)&(const ::NiPoint2 &)(inPt)), (float)((double)this->m04 * 4096.0), (*(float *)&(const ::NiPoint2 &)(aPt)), {});
    if (res < this->m4c)
    {
        return 1.0f;
    }
    if (res > this->m48)
    {
        return 0.0f;
    }
    float scale = 1.0f - (res - this->m4c) / (this->m48 - this->m4c);
    return scale;
}


float C6FEC00Abs(float fValue);

struct C6FEC00Point2
{
    float x;
    float y;
};

class C6FEC00Cell
{
  public:
    int unk00;
    unsigned int m_uiSize;
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
    float m_fCenterX;
    float m_fCenterY;

    bool FUN_006fec00(const C6FEC00Point2* pkPoint);
};
// @fnv 0x006fec90
int Unk006fec90_Class::GetActiveMenu(int a1)
{
    int result = 0;
    if (reinterpret_cast<::C6FEC00Cell *>(this)->FUN_006fec00((const ::C6FEC00Point2 *)(a1)))
    {
        if (m_pMenu && reinterpret_cast<::FOPipboyManager *>((m_pMenu))->IsUnk28Set() && !((unsigned char*)this)[0x5d])
        {
            result = (int)m_pMenu;
        }
        else if (m_pItems[0])
        {
            for (int i = 0; i < 4; i++)
            {
                result = reinterpret_cast<::Unk006fec90_Class *>((m_pItems[i]))->GetActiveMenu(a1);
                if (result)
                    break;
            }
        }
    }
    return result;
}
// @fnv 0x006fed30
int FUN_006fed30_Class::FUN_006fed30(int a1)
{
    int result = 0;

    if (reinterpret_cast<::C6FEC00Cell *>((reinterpret_cast<LocalUnk006fec90_Class*>(this)))->FUN_006fec00((const ::C6FEC00Point2 *)(a1)))
    {
        if (reinterpret_cast<::Callees *>((reinterpret_cast<LocalBSSimpleList*>(this)))->FUN_00726070() == ((void *)(::fnv_006fe510::FUN_006fe510())) &&
            *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) != 0)
        {
            result = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18);
        }
        else if (reinterpret_cast<::Callees *>((reinterpret_cast<LocalBSSimpleList*>(this)))->FUN_00726070() > ((void *)(::fnv_006fe510::FUN_006fe510())))
        {
            if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x20) != 0)
            {
                for (int i = 0; i < 4; ++i)
                {
                    result =
                        reinterpret_cast<::FUN_006fed30_Class *>((reinterpret_cast<FUN_006fed30_Callee**>(reinterpret_cast<char*>(this) + 0x20)[i]))->FUN_006fed30(
                            a1);
                    if (result != 0)
                        break;
                }
            }
        }
    }

    return result;
}

// Returns true if pkPoint lies within m_uiSize * DAT_01016968 of the cell center on both axes.
// @fnv 0x006fec00
bool C6FEC00Cell::FUN_006fec00(const C6FEC00Point2* pkPoint)
{
    float fRadius = m_uiSize * DAT_01016968;
    if (C6FEC00Abs(pkPoint->y - m_fCenterY) > fRadius)
        return false;
    if (C6FEC00Abs(pkPoint->x - m_fCenterX) > fRadius)
        return false;
    return true;
}

struct SteamCallbackA
{
    int unk00, unk04, unk08, unk0C, unk10;
    SteamCallbackA(void*, void (*)());
    ~SteamCallbackA();
};
struct SteamCallbackB
{
    int unk00, unk04, unk08, unk0C, unk10;
    SteamCallbackB(void*, void (*)());
    ~SteamCallbackB();
};
struct SteamCallbackC
{
    int unk00, unk04, unk08, unk0C, unk10;
    SteamCallbackC(void*, void (*)());
    ~SteamCallbackC();
};
void OnEvent();
void FUN_006ff8f0();
struct SteamUserInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int GetId();
};
struct SteamStatsInterface
{
    virtual void Init();
};
extern "C" __declspec(dllimport) bool __cdecl SteamAPI_Init();
extern "C" __declspec(dllimport) SteamUserInterface* __cdecl SteamUtils();
extern "C" __declspec(dllimport) SteamStatsInterface* __cdecl SteamUserStats();
struct FUN_006ff690
{
    SteamCallbackA callbackA;
    SteamCallbackB callbackB;
    SteamCallbackC callbackC;
    bool initialized, unk3D, enabled;
    int userId;
    bool FUN_006ff820();
    FUN_006ff690();
};
// Initializes the Steam API, stores the user id from SteamUser, and initializes user stats when ready.
// @fnv 0x006ff690
FUN_006ff690::FUN_006ff690()
    : callbackA(this, OnEvent), callbackB(this, FUN_006ff8f0), callbackC(this, FUN_006ff8f0), initialized(false),
      unk3D(false), enabled(true), userId(0)
{
    initialized = SteamAPI_Init();
    if (initialized)
    {
        bool ready = FUN_006ff820();
        if (SteamUtils())
            userId = SteamUtils()->GetId();
        if (ready && SteamUserStats())
            SteamUserStats()->Init();
    }
}

// FUN_006ff7b0 - destructor of the game's Steam callback holder.
//
// The object is a plain (NON-polymorphic) hub that owns three VSteam::CCallback<>
// sub-objects, each 0x14 bytes wide:
//
//     +0x00  CCallback<UserStatsReceived_t>       (dtor 0x6ff9a0)
//     +0x14  CCallback<UserStatsStored_t>         (dtor 0x6ffa40)
//     +0x28  CCallback<UserAchievementStored_t>   (dtor 0x6ffac0)
//
// The destructor shuts the Steam API down and then lets the compiler tear the
// three members down in reverse declaration order.  Because the holder itself is
// not polymorphic it has no vptr of its own, so no vtable store appears here -
// only the sub-objects' own destructors install theirs.
//
// The three sub-object destructors are only DECLARED here: they live in the game
// image and the checker binds the three call relocations from the original's own
// bytes.  They need three DIFFERENT class names - if two sub-objects shared a
// class they would share one relocation symbol and only one binding would
// survive.

extern "C" __declspec(dllimport) void __cdecl SteamAPI_Shutdown();

// Stand-in for VSteam::CCallback<UserStatsReceived_t>: 0x14 bytes.
struct SteamCallbackReceived
{
    int* m_pCallback;     // +0x00
    char m_bEnableState;  // +0x04
    int m_nCallbackSize;  // +0x08
    int m_nCallbackId;    // +0x0c
    int m_nB;             // +0x10
    ~SteamCallbackReceived();
};

// Stand-in for VSteam::CCallback<UserStatsStored_t>: 0x14 bytes.
struct SteamCallbackStored
{
    int* m_pCallback;     // +0x00
    char m_bEnableState;  // +0x04
    int m_nCallbackSize;  // +0x08
    int m_nCallbackId;    // +0x0c
    int m_nB;             // +0x10
    ~SteamCallbackStored();
};

// Stand-in for VSteam::CCallback<UserAchievementStored_t>: 0x14 bytes.
struct SteamCallbackAchieved
{
    int* m_pCallback;     // +0x00
    char m_bEnableState;  // +0x04
    int m_nCallbackSize;  // +0x08
    int m_nCallbackId;    // +0x0c
    int m_nB;             // +0x10
    ~SteamCallbackAchieved();
};

struct FUN_006ff7b0_Class
{
    SteamCallbackReceived m_received;  // +0x00
    SteamCallbackStored m_stored;      // +0x14
    SteamCallbackAchieved m_achieved;  // +0x28
    ~FUN_006ff7b0_Class();
};

// Destructor that shuts down the Steam API via SteamAPI_Shutdown().
// @fnv 0x006ff7b0
FUN_006ff7b0_Class::~FUN_006ff7b0_Class()
{
    SteamAPI_Shutdown();
}

// InvokeHandler: thiscall wrapper that forwards to a handler stored in the object.
//   ecx = this
//   [ebp+8] = int argument, pushed for the handler
//   handler is called as handler(this->m_pFlagTarget, a1): the target object goes in
//   ecx, the int argument on the stack, and the handler pops it (ret 4).
typedef void(* FUN_006ff9d0_Handler)(void* self, int a1);

struct FUN_006ff9d0_cls : public FUN_006ff970_Class
{
    void* m_pFlagTarget;
    FUN_006ff9d0_Handler m_pHandler;
    void InvokeHandler(int a1);
};

// @fnv 0x006ff9d0
void FUN_006ff9d0_cls::InvokeHandler(int aiArg)
{
    m_pHandler(m_pFlagTarget, aiArg);
}

struct FUN_006ffaf0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_0c;
    void(* m_10)(void*, int);

    void ForwardToCallback(int a1, int a2, int a3, int a4);
};

// @fnv 0x006ffaf0
void FUN_006ffaf0_Class::ForwardToCallback(int aiValue, int a2, int a3, int a4)
{
    m_10(m_0c, aiValue);
}

extern "C" __declspec(dllimport) void __cdecl SteamAPI_RegisterCallback(void* pvObject, int iMessage);

class B6FFB20Request
{
  public:
    int unk00;
    unsigned char m_ucFlags;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    void* m_pvSource;
    void* m_pvTarget;

    void SetSourceAndTarget(void* pvSource, void* pvTarget);
};
// @fnv 0x006ff920
FUN_006ff920::FUN_006ff920(int a1, int a2)
{
    m_p = (int*)&DAT_0106e7a4;
    *(int*)((char*)this + 0xc) = a1;
    *(int*)((char*)this + 0x10) = a2;
    if (a1 && a2)
        reinterpret_cast<::B6FFB20Request *>((((FUN_006ffb20_Class*)this)))->SetSourceAndTarget((void *)(a1), (void *)(a2));
}

// @fnv 0x006ffb20
void B6FFB20Request::SetSourceAndTarget(void* pvSource, void* pvTarget)
{
    if (!pvSource || !pvTarget)
        return;
    if (m_ucFlags & 1)
        reinterpret_cast<::FUN_006ffc00_Class *>(this)->UnregisterSteamCallback();
    if (false)
        m_ucFlags |= 2;
    m_pvSource = pvSource;
    m_pvTarget = pvTarget;
    SteamAPI_RegisterCallback(this, 0x44d);
}

struct FFB90Request;

extern void(__cdecl* g_pfnFFB90Notify)(FFB90Request* request, int message);

struct FFB90Request
{
    int unk00;
    unsigned char m_ucFlags;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int m_iParam1;
    int m_iParam2;

    void SetParams(int param1, int param2);
};
// Stores the two arguments in the object and, when both are non-zero, calls SetParams with them.
// @fnv 0x006ff9f0
FUN_006ff9f0::FUN_006ff9f0(int iFirst, int iSecond)
{
    m_p = (int*)&DAT_0106e7c4;
    m_kPointA = iFirst;
    m_kPointB = iSecond;
    if (iFirst && iSecond)
        reinterpret_cast<::FFB90Request *>((((FUN_006ffb90_Class*)this)))->SetParams(iFirst, iSecond);
}

// @fnv 0x006ffb90
void FFB90Request::SetParams(int param1, int param2)
{
    if (!param1 || !param2)
        return;
    if (m_ucFlags & 1)
        reinterpret_cast<::FUN_006ffc00_Class *>(this)->UnregisterSteamCallback();
    if (false)
        m_ucFlags |= 2;
    m_iParam1 = param1;
    m_iParam2 = param2;
    g_pfnFFB90Notify(this, 0x44e);
}

extern "C" __declspec(dllimport) void __cdecl SteamAPI_RegisterCallback(void* callback, int callbackId);

struct FUN_006ffc20_shell : FUN_006ff970_Class
{
    int callbackObject;
    int callbackTarget;
    enum
    {
        kGameServerCallback = 0
    };
    void FUN_006ffc20(int object, int target);
};
// @fnv 0x006ffa70
FUN_006ffa70::FUN_006ffa70(int a1, int a2)
{
    m_p = (int*)&DAT_0106e7d4;
    m_i = a1;
    m_iUnknownValue = a2;
    if (a1 && a2)
        reinterpret_cast<::FUN_006ffc20_shell *>(this)->FUN_006ffc20(a1, a2);
}

// @fnv 0x006ffc20
void FUN_006ffc20_shell::FUN_006ffc20(int object, int target)
{
    if (object == 0 || target == 0)
        return;

    if ((static_cast<unsigned char>(m_kPointB) & 1) != 0)
        reinterpret_cast<FUN_006ffc00_Class*>(this)->UnregisterSteamCallback();

    if (kGameServerCallback)
        m_kPointB = static_cast<unsigned char>(m_kPointB) | 2;

    callbackObject = object;
    callbackTarget = target;
    SteamAPI_RegisterCallback(this, 0x44f);
}

struct FUN_006ffda0_cls
{
    int m_i0;
    int m_i4;
    int m_i8;
    int m_ic;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    unsigned char m_ca28;
    unsigned char m_cb29;

    void FUN_006ffda0();
};

int __cdecl FUN_00401030(int a);

// @fnv 0x006ffda0
void FUN_006ffda0_cls::FUN_006ffda0()
{
    FUN_00401030(m_i24);
    m_i24 = (::FUN_00559450((int *)this) != 0) ? ((int)(::AllocateZeroed(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0() + 1, 1))) : 0;
    m_cb29 = 0;
    m_i1c = 0;
}

class NiTMapBase6E2
{
  public:
    virtual ~NiTMapBase6E2();


    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_006e2150 : public NiTMapBase6E2
{
  public:
    virtual ~FUN_006e2150();
};

// @fnv 0x006e2150
FUN_006e2150::~FUN_006e2150()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class TESForm
{
  public:
    virtual ~TESForm();
public:
    void ClearData();
};
class TESObjectREFR : public TESForm
{
};
class BGSLoadFormBuffer
{
  public:
};

struct LoadedRefPosition
{
    float x;
    float y;
    float z;
};
class LoadedRefMember
{
  public:
    virtual void v00();
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
class LoadedRefHolder
{
  public:
    unsigned int m_uiValue1;
    LoadedRefMember m_kMember;
    LoadedRefPosition m_kPathOffset;
    TESObjectREFR* m_pReference;

    void FUN_006e23b0(BGSLoadFormBuffer* apBuffer);
};

// Reads the holder's id, position and a form reference from the buffer, then loads the member's game data.
// @fnv 0x006e23b0
void LoadedRefHolder::FUN_006e23b0(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiValue1), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_kPathOffset), 12);
    m_pReference = dynamic_cast<TESObjectREFR*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apBuffer))->FUN_008648a0()));
    m_kMember.LoadGame(apBuffer);
}

struct Point3 : public NiPoint3
{
    Point3();
    Point3 operator*(float distance) const;
    Point3 operator+(const Point3& other) const;
};

float __cdecl FUN_00408840(float value);

class PathCheck
{
  public:
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    float m_spacing;

    bool CheckPathClear(NiPoint3* start, NiPoint3* end);
};

struct TraceVector
{
    float x;
    float y;
    float z;
    TraceVector ApplyScaled(float) const;
};
struct TraceReset
{
};
struct TraceRequest
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
    TraceReset state;
};
struct TraceFraction
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float fraction;
};
struct TraceResult
{
};
struct TraceWorld
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual bool Trace(TraceRequest*);
};
struct TraceOwner
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
    TraceWorld* world;
    TraceRequest* request;
    TraceResult* result;
    unsigned int count;
    float distance;
    float height;
    bool TraceWithLiftAndExtension(const TraceVector&, const TraceVector&, TraceVector&);
};
// Steps from start toward end in m_spacing increments, testing each segment with TraceWithLiftAndExtension and finally comparing the height difference against DAT_010240c0.
// @fnv 0x006e6e40
bool PathCheck::CheckPathClear(NiPoint3* start, NiPoint3* end)
{
    NiPoint3 diff2 = *end - *start;
    float fLength2 = reinterpret_cast<::NiPoint3 *>((((Point3*)&diff2)))->GetLengthSquared();
    int count = (int)(fLength2 / m_spacing);
    Point3 current_pos_2 = *(Point3*)start;
    for (int i4 = 0; i4 < count; i4++)
    {
        Point3 next_point = current_pos_2 + ((Point3*)&diff2)->operator*(m_spacing);
        next_point.z = current_pos_2.z;
        Point3 hit_point4;
        if (!reinterpret_cast<::TraceOwner *>(this)->TraceWithLiftAndExtension((*(const ::TraceVector *)(&current_pos_2)), (*(const ::TraceVector *)(&next_point)), (*(::TraceVector *)(&hit_point4))))
            return false;
        *(NiPoint3*)&current_pos_2 = *(NiPoint3*)&hit_point4;
    }
    Point3 hit_point2;
    Point3 target2 = *(Point3*)end;
    target2.z = current_pos_2.z;
    if (!reinterpret_cast<::TraceOwner *>(this)->TraceWithLiftAndExtension((*(const ::TraceVector *)(&current_pos_2)), (*(const ::TraceVector *)(&target2)), (*(::TraceVector *)(&hit_point2))))
        return false;
    else
        return FUN_00408840(hit_point2.z - end->z) < ::DAT_010240c0;
}
// @fnv 0x006e6f90
bool TraceOwner::TraceWithLiftAndExtension(const TraceVector& from, const TraceVector& to, TraceVector& output)
{
    float lift2 = height;
    TraceVector start3 = (*(::TraceVector *)(reinterpret_cast<::Point3Offset *>((void *)&(from))->ProjectileLaunched((::NiPoint3 *)&(const ::TraceVector &)((*reinterpret_cast<::TraceVector *>((void *)&::DAT_011a9484)).ApplyScaled(lift2)), {})));
    TraceVector end3 = (*(::TraceVector *)(reinterpret_cast<::Point3Offset *>((void *)&(to))->ProjectileLaunched((::NiPoint3 *)&(const ::TraceVector &)((*reinterpret_cast<::TraceVector *>((void *)&::DAT_011a9484)).ApplyScaled(lift2)), {})));
    reinterpret_cast<::FUN_0062a2b0_Class *>(&(request->state))->FUN_0062a2b0();
    reinterpret_cast<::FUN_0062a290_Class *>((result))->FUN_0062a290();
    count++;
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>((request))->FUN_004a3da0((void *)&(start3));
    reinterpret_cast<::FUN_004a3eb0_shell *>((request))->FUN_004a3eb0((void *)&(end3));
    if (world->Trace(request))
    {
        return false;
    }
    else
    {
        count++;
        TraceVector extended = (*(::TraceVector *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(end3))->FUN_00439ef0((::NiPoint3 *)&(const ::TraceVector &)((*reinterpret_cast<::TraceVector *>((void *)&::DAT_011a9484)).ApplyScaled(distance + height)), *(const ::NiPoint3 *)nullptr)));
        reinterpret_cast<::FUN_0062a2b0_Class *>(&(request->state))->FUN_0062a2b0();
        reinterpret_cast<::FUN_0062a290_Class *>((result))->FUN_0062a290();
        reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>((request))->FUN_004a3da0((void *)&(end3));
        reinterpret_cast<::FUN_004a3eb0_shell *>((request))->FUN_004a3eb0((void *)&(extended));
        if (world->Trace(request))
        {
            TraceVector hit =
                (*(::TraceVector *)(reinterpret_cast<::Point3Offset *>((void *)&(end3))->ProjectileLaunched((::NiPoint3 *)&(const ::TraceVector &)((*(::TraceVector *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(extended))->FUN_00439ef0((::NiPoint3 *)&(end3), *(const ::NiPoint3 *)nullptr))).ApplyScaled(((::TraceFraction *)(::FUN_00460140((int)(result))))->fraction)), {})));
            output = hit;
            return true;
        }
        else
        {
            return false;
        }
    }
}

namespace fnv_006e7230 {

struct Point3_stub
{
    float x, y, z;
    Point3_stub(float x, float y, float z);
};

struct PathingLocation
{
};

struct Node_6cee10
{
    int unk00;
    int unk04;
    int unk08;
    Point3_stub pt;
};

struct FUN_006cee10_shell
{
    unsigned int GetSize();
};


struct Class_6e7230
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
    PathingLocation m_loc;  // offset 0x2c
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
    Point3_stub min;  // offset 0x5c
    Point3_stub max;  // offset 0x68

    void ComputeBounds(FUN_006cee10_shell* list);
};

// Initializes min/max to extreme values, then expands them over each node's point in list and over m_loc's location.
// @fnv 0x006e7230
void Class_6e7230::ComputeBounds(FUN_006cee10_shell* pNodeList)
{
    min = Point3_stub(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
    max = Point3_stub(::DAT_01015f5c, ::DAT_01015f5c, ::DAT_01015f5c);

    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((pNodeList))->GetName())); i++)
    {
        min.x = ::FUN_0040ebd0(((Node_6cee10*)reinterpret_cast<::FUN_006cee10_shell *>((pNodeList))->FUN_006cee10(i))->pt.x, min.x);
        min.y = ::FUN_0040ebd0(((Node_6cee10*)reinterpret_cast<::FUN_006cee10_shell *>((pNodeList))->FUN_006cee10(i))->pt.y, min.y);
        min.z = ::FUN_0040ebd0(((Node_6cee10*)reinterpret_cast<::FUN_006cee10_shell *>((pNodeList))->FUN_006cee10(i))->pt.z, min.z);
        max.x = ::FUN_00404010(((Node_6cee10*)reinterpret_cast<::FUN_006cee10_shell *>((pNodeList))->FUN_006cee10(i))->pt.x, max.x);
        max.y = ::FUN_00404010(((Node_6cee10*)reinterpret_cast<::FUN_006cee10_shell *>((pNodeList))->FUN_006cee10(i))->pt.y, max.y);
        max.z = ::FUN_00404010(((Node_6cee10*)reinterpret_cast<::FUN_006cee10_shell *>((pNodeList))->FUN_006cee10(i))->pt.z, max.z);
    }

    min.x = ::FUN_0040ebd0((*(::fnv_006e7230::Point3_stub *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(m_loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))).x, min.x);
    min.y = ::FUN_0040ebd0((*(::fnv_006e7230::Point3_stub *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(m_loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))).y, min.y);
    min.z = ::FUN_0040ebd0((*(::fnv_006e7230::Point3_stub *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(m_loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))).z, min.z);
    max.x = ::FUN_00404010((*(::fnv_006e7230::Point3_stub *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(m_loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))).x, max.x);
    max.y = ::FUN_00404010((*(::fnv_006e7230::Point3_stub *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(m_loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))).y, max.y);
    max.z = ::FUN_00404010((*(::fnv_006e7230::Point3_stub *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(m_loc))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))).z, max.z);
}
}  // namespace fnv_006e7230

struct SAElement
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SAArray
{
    virtual void v00();
    virtual SAElement* Allocate(unsigned int auiCount);

    SAElement* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;

    void Destroy(SAElement* apItems, unsigned int auiCount);
    void FUN_006e7500(unsigned int auiIndex, bool abShrink);
};

// Removes the element at auiIndex, optionally shrinking the buffer, then decrements uiSize.
// @fnv 0x006e7500
void SAArray::FUN_006e7500(unsigned int auiIndex, bool abShrink)
{
    if (abShrink && reinterpret_cast<::FUN_006f3170_Class *>(this)->FUN_006f3170())
    {
        unsigned int uiNewAlloc = reinterpret_cast<::FUN_00869600_Class *>(this)->FUN_00869600();
        SAElement* pNewBuffer6 = Allocate(uiNewAlloc);
        reinterpret_cast<::FUN_006d0730_shell *>(this)->FUN_006d0730(pNewBuffer6, pBuffer, auiIndex);
        reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(&pBuffer[auiIndex], 1);
        reinterpret_cast<::FUN_006d0730_shell *>(this)->FUN_006d0730(&pNewBuffer6[auiIndex], pBuffer + auiIndex + 1, uiSize - 1);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        pBuffer = pNewBuffer6;
        uiAllocSize = uiNewAlloc;
    }
    else
    {
        reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(&pBuffer[auiIndex], 1);
        reinterpret_cast<::FUN_006d0730_shell *>(this)->FUN_006d0730(&pBuffer[auiIndex], pBuffer + auiIndex + 1, uiSize - auiIndex - 1);
    }
    --uiSize;
}

struct S_006eaa00
{
    int unk00;
    int unk04;
    S_006eaa00(S_006eaa00* other);
public:
    ::S_006eaa00 *FUN_006eaa00(::S_006eaa00 *);
};
// If the list has a head element, passes its value to a1, advances head to next, frees the old head, and returns true; otherwise returns false.
// @fnv 0x006ec2e0
bool FUN_006ec2e0_Class::PopHead(FUN_006ec2e0_Out* pOut)
{
    bool bPopped;
    FUN_006ec2e0_Elem* tmp = head;
    if (tmp)
    {
        reinterpret_cast<::S_006eaa00 *>((pOut))->FUN_006eaa00((::S_006eaa00 *)(((int)(new ((void *)(tmp)) ::Vec3()))));
        head = tmp->next;
        freeList->FUN_006ecb10(tmp);
        bPopped = true;
    }
    else
    {
        bPopped = false;
    }
    return bPopped;
}

struct FUN_006ece00_Empty
{
    void Clear();
};

// Clears the object, then placement-constructs an S_006eaa00 copy from value into this object.
// @fnv 0x006ece00
void FUN_006ece00_Obj::AssignFrom(int apSource)
{
    reinterpret_cast<::TESForm *>((((FUN_006ece00_Empty*)this)))->ClearData();
    new (this) S_006eaa00((S_006eaa00*)apSource);
}

struct Elem_00483710
{
    int unk00;
    int unk04;
    int unk08;
    ~Elem_00483710();
};

struct Base_006ecf20
{
    virtual ~Base_006ecf20();
};

struct FUN_006ecfa0 : Base_006ecf20
{
    int unk04;
    int unk08;
    Elem_00483710 elements[256];
    ~FUN_006ecfa0();
};

// Destructor for the object holding an array of 256 elements; the body is empty.
// @fnv 0x006ecfa0
FUN_006ecfa0::~FUN_006ecfa0()
{}

// Create a path entry at this position for the current navmesh triangle and register it in both lists.

struct EDBC0Point3
{
    float x;
    float y;
    float z;
};

class EDBC0NavMesh
{
  public:
};

struct EDBC0Location
{
    EDBC0NavMesh* m_pkNavMesh;
    unsigned short m_usTriangle;
};

class EDBC0Source
{
  public:
};

struct EDBC0Entry
{
    EDBC0Point3 m_kPathOffset;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void* m_pkNavMeshInfo;
    unsigned short m_usTriangle;
};

class EDBC0EntryArray
{
  public:
    unsigned int Add(EDBC0Entry*& rpkEntry);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class EDBC0Builder
{
  public:
    int unk00;
    int unk04;
    EDBC0Point3 m_kPathOffset;
    int unk14;
    int unk18;
    int unk1C;
    EDBC0Source* m_pkSource;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    EDBC0EntryArray m_kAll;
    EDBC0EntryArray m_kOpen;

    void FUN_006edbc0();
};

struct PBTriangle
{
};

struct PBNavMesh
{
};

struct PBContext
{
    PBNavMesh* m_pLocationNavMesh;
    unsigned short usIndex;
    unsigned short usFlags;
    int m_iEdgeNumber;
};

struct PBContextArray
{
    PBContext* GetAt(int aiIndex);
};

struct PBList
{
    void* pEntries;
    unsigned int uiCapacity;
    unsigned int uiSize;
    unsigned int uiFlags;
    unsigned int uiRevision;

    unsigned int GetSize();
    void Add(void** appItem);
};

struct PBBuilder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    PositionCollection_006edd30* pPositions;
    PBContextArray* m_pContextArray;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    PBList kStarts;
    PBList kEnds;
    PBList kStartEdges;
    PBList kEndEdges;
    PBList kPaths;

    void AddPathFromContext(const Position_006edd30* apPosition, int aiIndex);
};

struct Vec390
{
    float x, y, z;
};
struct Info390;
struct Tri390
{
};
struct Mesh390
{
    Vec390 Position(unsigned short);
};
struct Parent390
{
    Mesh390* mesh;
    unsigned short triangle;
    int edge;
};
struct Parents390
{
    Parent390& GetAt(int);
};
struct Search390
{
    Parent390* Get(unsigned) const;
};
template <class T> struct List390
{
    int unk00, unk04, unk08, unk0c, unk10;
    T& GetLast();
    unsigned Add(T&);
    unsigned Size();
};
struct Path390;
struct PathList390
{
    int unk00, unk04, unk08;
    unsigned Add(Path390*&);
};
struct Location390
{
    Vec390 position;
    int unk0c, unk10, unk14, unk18, unk1c, unk20;
    Info390* info;
    unsigned short triangle;
    PathList390 paths;
};
struct Link390
{
    Location390* previous;
    Location390* location;
    Info390* info;
    unsigned short triangle;
    int edge;
    unsigned char flag;
    unsigned index;
};
struct Path390
{
    Path390* previous;
    Location390* location;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    PathList390 paths;
    float dot;
    Info390* info;
    unsigned short triangle;
    int edge;
    unsigned index;
    Path390* prior;
    Link390* link;
};
struct Builder390
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Search390* search;
    Parents390* parents;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    List390<Path390*> paths;
    List390<Location390*> locations;
    List390<Path390*> other;
    List390<Link390*> links;
    List390<Path390*> allPaths;
    void AddPathFromEdge(const Vec390* position, int index);
};
struct NodeS;
struct EdgeS;
struct ArrE
{
    int unk0, unk4, unk8, unkC, unk10;
    EdgeS*& FUN_006f2270();
};
struct ArrN
{
    int unk0, unk4, unk8, unkC, unk10;
};
struct NodeS
{
    NiPoint3 origin, position, direction;
    S0069a690 info;
    ArrE edges;
};
struct EdgeS
{
    NodeS* first;
    NodeS* second;
    EH info;
    unsigned char flag;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float weight;
    EH bound;
    unsigned int index;
    EdgeS* left;
    EdgeS* right;
};
struct HostS
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    ArrN nodesA, nodesB;
    ArrE edgesA, edgesB, edgesC;
    NodeS* SplitEdge(unsigned int index, bool side);
};
namespace fnv_006ef0c0 {
struct PointP059
{
    float x, y, z;
    PointP059();
    PointP059 operator-(const PointP059&) const;
    PointP059 operator+(const PointP059&) const;
    PointP059 operator*(float) const;
    PointP059 FUN_004a0bd0() const;
    PointP059 Cross(const PointP059&) const;
};
PointP059 operator*(float, const PointP059&);
struct InfoP059
{
    int unk00, unk04;
    InfoP059(const InfoP059&);
};
struct NodeP059;
struct EdgeP059
{
    NodeP059* first;
    NodeP059* second;
    int unk08, unk0c, unk10;
    bool active;
};
template <class T> struct ArrayP059
{
    int unk00, unk04, unk08, unk0c, unk10;
    T& FUN_006a7ad0(unsigned int);
    T& FUN_00877a30(unsigned int);
    unsigned int FUN_0044ddc0();
};
struct NodeP059 : PointP059
{
    PointP059 position, direction;
    InfoP059 info;
    ArrayP059<EdgeP059*> edges;
};
struct HostP059
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    ArrayP059<NodeP059*> nodesA, nodesB;
    ArrayP059<EdgeP059*> edgesA, edgesB;
    unsigned int UpdateNodeDirection(unsigned int, float, bool);
    bool FUN_006f0050(const PointP059&, const PointP059&, InfoP059, const PointP059&, const PointP059&,
                      const PointP059&);
};
bool FUN_00696540(const PointP059*, const PointP059*, const PointP059*, const PointP059*);
// Computes a node's direction from its neighbours' positions and radius, optionally spawning a new node, and returns the next index.
// @fnv 0x006ef0c0
unsigned int HostP059::UpdateNodeDirection(unsigned int index, float radius, bool side)
{
    ArrayP059<NodeP059*>* l = side ? &nodesA : &nodesB;
    ArrayP059<EdgeP059*>* g = side ? &edgesA : &edgesB;
    PointP059 f;
    PointP059 b;
    f = *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1))) - *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)));
    b = *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index + 1))) - *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)));
    if (reinterpret_cast<::NiPoint3 *>(&(f))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<const ::fnv_006ef0c0::PointP059 *>((void *)&::NiPoint3::ZERO)))) && index > 1)
        f = *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 2))) - *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)));
    if (reinterpret_cast<::NiPoint3 *>(&(b))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<const ::fnv_006ef0c0::PointP059 *>((void *)&::NiPoint3::ZERO)))) && index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((l))->GetName())) - 2)
        b = *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index + 2))) - *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)));
    f.z = 0.0f;
    b.z = 0.0f;
    reinterpret_cast<::FUN_004a0c10_s *>(&(f))->FUN_004a0c10();
    reinterpret_cast<::FUN_004a0c10_s *>(&(b))->FUN_004a0c10();
    PointP059 k = b.Cross((*reinterpret_cast<const ::fnv_006ef0c0::PointP059 *>((void *)&::DAT_011a9484)));
    PointP059 e = f.Cross((*reinterpret_cast<const ::fnv_006ef0c0::PointP059 *>((void *)&::DAT_011a9484)));
    float i = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(f))->DotProduct((void *)&(k));
    float a = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(f))->DotProduct((void *)&(b));
    float h = (3.1415927410125732 - ::FUN_004b5570(i, a)) * 0.5;
    float d = ::FUN_0057dd70(h) * radius;
    NodeP059* c = ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)));
    PointP059 j;
    if (side)
        j = *c->edges.FUN_00877a30(0)->second - *c->edges.FUN_00877a30(0)->first;
    else
        j = *c->edges.FUN_00877a30(0)->first - *c->edges.FUN_00877a30(0)->second;
    if (a >= 0.800000011920929 && reinterpret_cast<::FUN_004b6190_shell *>((void *)&(e))->DotProduct((void *)&(j)) * reinterpret_cast<::FUN_004b6190_shell *>((void *)&(k))->DotProduct((void *)&(j)) > 0.0)
    {
        PointP059 n;
        PointP059 m;
        if (side)
        {
            n = (*c - radius * e) - (radius * 1.5) * f;
            m = (*c + radius * k) - (radius * 1.5) * b;
        }
        else
        {
            n = (*c + radius * e) - (radius * 1.5) * f;
            m = (*c - radius * k) - (radius * 1.5) * b;
        }
        reinterpret_cast<::FUN_006ee740_Class *>(this)->SplitNode(index, side, (const ::NiPoint3 &)(n), (const ::NiPoint3 &)(m));
        return index + 2;
    }
    else
    {
        if (side)
            c->direction = b * d + k * radius;
        else
            c->direction = b.FUN_004a0bd0() * d - k * radius;
        bool o = false;
        if (((::fnv_006ef0c0::EdgeP059 *)(reinterpret_cast<::S3e60 *>((g))->FUN_006a7ad0(index - 1)))->active && ((::fnv_006ef0c0::EdgeP059 *)(reinterpret_cast<::S3e60 *>((g))->FUN_006a7ad0(index)))->active)
            o = FUN_006f0050(*c, c->position, c->info, c->direction, ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1)))->position,
                             *((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index + 1))));
        else
        {
            c->position = *c + c->direction;
            o = true;
        }
        if (o && FUN_00696540(&((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1)))->position, ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1))),
                              &((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)))->position, ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)))))
        {
            PointP059 q = ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)))->position - ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1)))->position;
            PointP059 p = (((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1)))->position + ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)))->position) * 0.5f;
            ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index - 1)))->position = p + q * 0.01f;
            ((::fnv_006ef0c0::NodeP059 *)(reinterpret_cast<::S3e60 *>((l))->FUN_006a7ad0(index)))->position = p - q * 0.01f;
        }
        return index + 1;
    }
}
}  // namespace fnv_006ef0c0

struct FNV_006ef920_Vertex
{
    unsigned int unk00, unk04, unk08;
    NiPoint3 position;
};
struct FNV_006ef920_Nodes
{
    FNV_006ef920_Vertex* first;
    FNV_006ef920_Vertex* second;
};
struct FNV_006ef920_Temporary
{
    unsigned int handle;
    FNV_006ef920_Temporary()
    {
        FUN_0042fb00();
    }
    ~FNV_006ef920_Temporary()
    {
        FUN_0042fa40();
    }
    void FUN_0042fb00();
    void FUN_0042fa40();
};
struct FNV_006ef920_Serializer
{
};
struct FNV_006ef920_Entry
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
    FNV_006ef920_Serializer* serializer;
    unsigned short identifier;
    unsigned short unk42;
    void* extra;
    unsigned int unk48;
    FNV_006ef920_Nodes* sideA;
    FNV_006ef920_Nodes* sideB;
};
struct FNV_006ef920_Record
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
    void FUN_006efd50();
};
struct FNV_006ef920_RecordFields
{
    void* handle;
    unsigned short identifier;
    unsigned short unk06;
    void* extra;
};
struct FNV_006ef920_Receiver
{
};
struct FNV_006ef920
{
    FNV_006ef920_Receiver* receiver;
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
    IndexCollection edges;
    bool CheckEdges();
};
struct Point
{
    float x, y, z;
    Point operator-(const Point&) const;
    Point operator+(const Point&) const;
    Point operator*(float) const;
};
struct Mesh;
struct Location
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Location(const Point&, const Mesh*);
    ~Location();
};
struct Segment
{
    Point start, end;
};
struct Vertex
{
    Point origin, position, direction;
    const Mesh* mesh;
};
struct Link
{
    Vertex* first;
    Vertex* second;
    int unk08, unk0c, unk10, unk14;
    unsigned index;
};
bool __cdecl Cross(const Point*, const Point*, const Point*, const Point*);
bool __cdecl Reach(Location*, const Point&, int, int);
extern const float scale;
struct Owner
{
    Segment* Allocate(unsigned, bool);
    bool CheckLinkCrossing(Link* source, Link* target, bool side);
};
// Walks the edges collection twice, checking consecutive side nodes and segment intersections, reporting failures to receiver and returning false on any failure.
// @fnv 0x006ef920
bool FNV_006ef920::CheckEdges()
{
    FNV_006ef920_Nodes* prevA = reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(0))->sideA;
    FNV_006ef920_Nodes* prevB = reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(0))->sideB;
    for (unsigned int index = 1; index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(edges))->GetName())); ++index)
    {
        FNV_006ef920_Nodes* nextA = reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->sideA;
        FNV_006ef920_Nodes* nextB = reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->sideB;
        if (nextA == prevA && !reinterpret_cast<::Owner *>(this)->CheckLinkCrossing((::Link *)(nextB), (::Link *)(nextA), false))
        {
            if (receiver)
            {
                FNV_006ef920_Record record;
                new ((void *)&(record)) ::FUN_006efd50();
                FNV_006ef920_Temporary temp;
                if (reinterpret_cast<::NavMeshInfo *>((reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->serializer))->ResolveNavMesh((*(::NavMeshPtr *)(&temp))))
                {

                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).handle = ((void *)(::FUN_00559450((int *)&(temp))));
                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).identifier =
                        reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->identifier;
                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).extra =
                        reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->extra;
                    reinterpret_cast<::FUN_006cf4c0_Array *>((receiver))->FUN_006cf4c0((*(const ::ParentSpaceNode *)(&record)));
                }
            }
            return false;
        }
        if (nextB == prevB && !reinterpret_cast<::Owner *>(this)->CheckLinkCrossing((::Link *)(nextA), (::Link *)(nextB), true))
        {
            if (receiver)
            {
                FNV_006ef920_Record record;
                new ((void *)&(record)) ::FUN_006efd50();
                FNV_006ef920_Temporary temp;
                if (reinterpret_cast<::NavMeshInfo *>((reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->serializer))->ResolveNavMesh((*(::NavMeshPtr *)(&temp))))
                {

                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).handle = ((void *)(::FUN_00559450((int *)&(temp))));
                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).identifier =
                        reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->identifier;
                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).extra =
                        reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->extra;
                    reinterpret_cast<::FUN_006cf4c0_Array *>((receiver))->FUN_006cf4c0((*(const ::ParentSpaceNode *)(&record)));
                }
            }
            return false;
        }
        prevA = nextA;
        prevB = nextB;
    }
    for (unsigned int index = 0; index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(edges))->GetName())); ++index)
    {
        FNV_006ef920_Nodes* nodesA = reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->sideA;
        FNV_006ef920_Nodes* nodesB = reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->sideB;
        if (FUN_00696540(&nodesA->first->position, &nodesA->second->position, &nodesB->first->position,
                         &nodesB->second->position))
        {
            if (receiver)
            {
                FNV_006ef920_Record record;
                new ((void *)&(record)) ::FUN_006efd50();
                FNV_006ef920_Temporary temp;
                if (reinterpret_cast<::NavMeshInfo *>((reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->serializer))->ResolveNavMesh((*(::NavMeshPtr *)(&temp))))
                {

                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).handle = ((void *)(::FUN_00559450((int *)&(temp))));
                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).identifier =
                        reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->identifier;
                    reinterpret_cast<FNV_006ef920_RecordFields&>(record).extra =
                        reinterpret_cast<FNV_006ef920_Entry*>(*edges.FUN_00877a30(index))->extra;
                    reinterpret_cast<::FUN_006cf4c0_Array *>((receiver))->FUN_006cf4c0((*(const ::ParentSpaceNode *)(&record)));
                }
            }
            return false;
        }
    }
    return true;
}
// @fnv 0x006efd80
bool Owner::CheckLinkCrossing(Link* pSourceLink, Link* pTargetLink, bool side)
{
    Point startTmp = pSourceLink->first->position;
    Point end3 = pSourceLink->second->position;
    Vertex* vertex2 = pTargetLink->second;
    if (Cross(&startTmp, &end3, &vertex2->origin, &vertex2->position))
    {
        Point delta9 = vertex2->position - vertex2->origin;
        Location centerB(vertex2->position, vertex2->mesh);
        if (Reach(&centerB, vertex2->position + delta9, 0, 0))
        {
            Location first4(vertex2->position + delta9, vertex2->mesh);
            Location second3(vertex2->position + delta9, vertex2->mesh);
            if (Reach(&first4, startTmp, 0, 0) && Reach(&second3, end3, 0, 0))
            {
                Segment* result = ((::Segment *)(reinterpret_cast<::HostS *>(this)->SplitEdge(pSourceLink->index, side)));
                result->start = vertex2->position;
                result->end = vertex2->position + delta9 * ::DAT_0101e2bc;
                return true;
            }
        }
        return false;
    }
    else
    {
        if (Cross(&startTmp, &end3, &pTargetLink->first->position, &pTargetLink->second->position))
            return false;
        return true;
    }
}

class NiPoint3Ex : public NiPoint3
{
  public:
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
    NiPoint3Ex operator-(const NiPoint3Ex&) const;
    NiPoint3Ex operator*(float) const;
};
class TESObjectCELL;
class PathingLocation
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    PathingLocation();
    PathingLocation(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
    ~PathingLocation();
public:
    bool HasValidTriangle();
public:
    ::PathingLocation &operator=(const ::PathingLocation &);
public:
    ::TESObjectCELL *GetContainingCell();
};
// @fnv 0x006e22d0
void FUN_006e22d0_Class::FUN_006e22d0()
{
    reinterpret_cast<::PathingLocation *>(&(m1))->HasValidTriangle();
}
// @fnv 0x006e6c00
bool PathObj_s::SetupFromCellWorld()
{
    TESObjectCELL_s* pCell = ((::TESObjectCELL_s *)(reinterpret_cast<::PathingLocation *>((((::Loc_s *)(::GetOffsetC((int)(m_holder))))))->GetContainingCell()));
    if (pCell == 0)
        return false;
    m_pOwningWorld = reinterpret_cast<::FUN_004543c0_cls *>((pCell))->FUN_004543c0();
    if (m_pOwningWorld == 0)
        return false;
    Flags_s kFlags9(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(kFlags9))->FUN_004a39f0(0x26);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(kFlags9))->FUN_0059ce80(3);
    reinterpret_cast<::S006e6ae0_Object *>(this)->FUN_006e6ae0();
    m_child80 = new (((void *)(::FUN_00553320(0x10, 0xb0)))) Child80_s;
    ::FUN_004a3f70((char *)(m_child80), (*(::Flt *)&(const ::Flags_s &)(kFlags9)));
    reinterpret_cast<::InterfaceManager *>((m_child80))->FUN_00500a20((::Tile *)(m_parent));
    m_child84 = new (((void *)(::FUN_00553320(0x10, 0x70)))) Child84_s;
    reinterpret_cast<::FUN_0059ceb0_shell *>((m_child80))->FUN_0059ceb0((::hkpClosestRayHitCollector *)(m_child84));
    return true;
}
// Copies m_iType, m_kLocation, the point and m_iFlags from kOther into this object and returns *this.
// @fnv 0x006e9570
FUN_006e9570_cls& FUN_006e9570_cls::operator=(const FUN_006e9570_cls& kOther)
{
    m_iType = kOther.m_iType;
    reinterpret_cast<::PathingLocation *>((void *)&(const ::B6E9570PathingLocation &)(m_kLocation))->operator=((const ::PathingLocation &)(kOther.m_kLocation));
    m_kPathOffset = kOther.m_kPathOffset;
    m_iFlags = kOther.m_iFlags;
    return *this;
}
struct TargetNavInfo
{
};
bool __cdecl FUN_006d7350(PathingLocation&, PathingLocation&, PathingLocation*, void*);
bool __cdecl FUN_006d7490(PathingLocation&, PathingLocation&, void*, void*);
struct TargetHost
{
    bool FUN_006f0050(const NiPoint3Ex&, NiPoint3Ex&, TargetNavInfo*, int, const NiPoint3Ex&, PathingLocation&,
                      PathingLocation&);
};
// @fnv 0x006f0050
bool TargetHost::FUN_006f0050(const NiPoint3Ex& start, NiPoint3Ex& output, TargetNavInfo* nav, int unused,
                              const NiPoint3Ex& offset, PathingLocation& first, PathingLocation& second)
{
    PathingLocation endLocation(start + offset * 0.01f + (*reinterpret_cast<::NiPoint3Ex *>(&::DAT_011a946c)), reinterpret_cast<::NavMeshInfoStandIn *>((nav))->FUN_006b7770(), ::FUN_00690800((const ::NavMeshInfo *)(nav)));
    PathingLocation startLocation(start - offset + (*reinterpret_cast<::NiPoint3Ex *>(&::DAT_011a946c)), reinterpret_cast<::NavMeshInfoStandIn *>((nav))->FUN_006b7770(), ::FUN_00690800((const ::NavMeshInfo *)(nav)));
    PathingLocation hitLocation;
    if (FUN_006d7350(endLocation, startLocation, &hitLocation, 0))
    {
        output = start;
        bool visible = true;
        if (!FUN_006d7490(startLocation, first, 0, 0))
            visible = false;
        else if (!FUN_006d7490(startLocation, second, 0, 0))
            visible = false;
        if (!visible)
        {
            output = start + offset;
            return true;
        }
    }
    else
    {
        output = (*(::NiPoint3Ex *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(hitLocation))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))) + offset;
        return true;
    }
    return false;
}

struct HeightVec
{
    float x, y, z;
    HeightVec operator-(const HeightVec&) const;
};
struct HeightTriangle
{
};
struct HeightMesh
{
};
struct HeightPtr
{
    HeightMesh* ptr;
    HeightPtr();
    ~HeightPtr();
    operator HeightMesh*() const;
};
struct HeightInfo
{
};
struct HeightEntry
{
    int unk00, unk04, unk08, unk0c, unk10;
    HeightVec position;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    HeightInfo* info;
    unsigned short triangle;
    unsigned short unk42;
    int unk44, unk48, unk4c, unk50;
    int boundary;
};
struct HeightArray
{
    unsigned GetSize();
    HeightEntry*& GetAt(unsigned);
};
struct HeightFlags
{
    int unk00, unk04, unk08, unk0c, unk10;
    HeightFlags(unsigned);
    ~HeightFlags();
    unsigned GetSize();
    bool& GetAt(unsigned);
};
bool __cdecl AreBytesEqual(const unsigned char*, const unsigned char*);
struct HeightPath
{
    int unk00, unk04;
    HeightVec start, end;
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
    HeightArray points;
    void FlattenPathPoints();
};
struct PSPoint3
{
    float x;
    float y;
    float z;
};

struct PSNavMeshInfo;

struct PSNavMesh
{
};

struct PSRequest
{
};

struct PSLocation
{
    int unk00[10];

    PSLocation(const PSPoint3& arPoint, const PSNavMeshInfo* apInfo);
    ~PSLocation();
};

struct PSLocationArray
{
    unsigned int Add(const PSLocation& arLocation);
};

struct PSNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    PSPoint3 kPosition;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float m_fPathingCostCur;
    PSNavMeshInfo* m_pNavigationMesh;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    void* pPathNodeDoor;
};

struct PSNodeArray
{
    int GetSize();
    PSNode*& GetAt(unsigned int auiIndex);
};

struct PSSolution
{
    int unk00;
    int unk04;
    PSPoint3 kStart;
    PSPoint3 kEnd;
    PSRequest* pRequest;
    int unk24[27];
    PSNodeArray kNodes;
    int unk94[4];
    PSLocationArray kLocations;

    void BuildLocations();
};

// @fnv 0x006f10d0
void PSSolution::BuildLocations()
{
    {
        PSLocation kStartLocation(kStart, ((::PSNavMeshInfo *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::PSNavMesh *)&(::GetFirstElement((const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(pRequest))))))->FUN_0068efb0())));
        reinterpret_cast<::PathingLocationArray *>(&(kLocations))->FUN_006cf1b0((const ::PathingLocation &)(kStartLocation));
    }

    int iPreviousNodeIndex = -1;
    int i = 1;
    float fAccum = 0.0f;
    while (i < ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kNodes))->GetName())) + 1)
    {
        if (i != ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kNodes))->GetName())))
            fAccum += 1.0f - kNodes.GetAt(i - 1)->m_fPathingCostCur;

        bool bAdd = false;
        if (fAccum > (double)0.2f)
        {
            bAdd = true;
        }
        else
        {
            PSNode* pNode = (i == ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kNodes))->GetName()))) ? 0 : kNodes.GetAt(i);
            if (pNode && pNode->pPathNodeDoor)
            {
                bAdd = true;
            }
            else
            {
                PSPoint3 kFrom = (iPreviousNodeIndex == -1) ? kStart : kNodes.GetAt(iPreviousNodeIndex)->kPosition;
                PSPoint3 kTo = (i == ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kNodes))->GetName()))) ? kEnd : kNodes.GetAt(i)->kPosition;
                if (!reinterpret_cast<::FUN_006ed7d0_Class *>(this)->FUN_006ed7d0(iPreviousNodeIndex + 1, i - 1, (const ::NiPoint3 &)(kFrom), (const ::NiPoint3 &)(kTo)))
                    bAdd = true;
            }
        }

        if (bAdd)
        {
            PSLocation kTargetPoint(kNodes.GetAt(i - 1)->kPosition, kNodes.GetAt(i - 1)->m_pNavigationMesh);
            reinterpret_cast<::PathingLocationArray *>(&(kLocations))->FUN_006cf1b0((const ::PathingLocation &)(kTargetPoint));
            fAccum = 0.0f;
            iPreviousNodeIndex = i - 1;
        }
        i++;
    }

    {
        PSLocation kEndLocation(kEnd, ((::PSNavMeshInfo *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::PSNavMesh *)&(::GetLastElement((const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(pRequest))))))->FUN_0068efb0())));
        reinterpret_cast<::PathingLocationArray *>(&(kLocations))->FUN_006cf1b0((const ::PathingLocation &)(kEndLocation));
    }
}

struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
};
struct AvoidObject
{
    float x, y, z, radius;
    void* object;
    int unk14, unk18, unk1c, unk20;
    const FUN_006815c0* FUN_006815c0();
};
struct AvoidObjects
{
    const AvoidObject& FUN_006a1400(unsigned int);
};
struct AvoidOwner
{
};
struct FUN_006240d0
{
    FUN_006815c0 center;
    float radius;
    FUN_006240d0();
};
struct FUN_006f2d80
{
    void* table;
    FUN_006240d0* data;
    unsigned int size, capacity;
    void* allocator;
    FUN_006f2d80();
    ~FUN_006f2d80();
};
struct FUN_006dd0d0
{
    void* table;
    float x, y, z;
    void* mesh;
    void* meshes;
    void* cell;
    void* world;
    unsigned int cellKey;
    unsigned short triangle, flags;
    FUN_006dd0d0(const FUN_006815c0&, const FUN_006dd0d0&);
    ~FUN_006dd0d0();
};
struct AvoidPoints
{
    FUN_006dd0d0* FUN_00691750(unsigned int);
};
struct AvoidPath
{
    void* table;
    AvoidOwner* owner;
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
    AvoidPoints points;
    void ClipPathAgainstObstacles();
};
bool FUN_006ba9e0(const FUN_006815c0&, const FUN_006815c0&, const FUN_006815c0&, float);
bool ComputeCircleTangents(const FUN_006815c0&, float, const FUN_006815c0&, FUN_006815c0*, FUN_006815c0*);
// Whether a point lies strictly inside the sphere.

class C6F1BC0Vector : public NiPoint3
{
  public:
    float SqrLength() const;
};

class C6F1BC0Sphere
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;

    bool FUN_006f1bc0(const NiPoint3& kPoint);
};
// Builds obstacle spheres from the owner's avoid objects and inserts detour points into the path where segments intersect them.
// @fnv 0x006f1440
void AvoidPath::ClipPathAgainstObstacles()
{
    AvoidObjects* objects = ((::AvoidObjects *)(reinterpret_cast<::_Dummy_0069e390 *>((owner))->GetString()));
    if (objects)
    {
        FUN_006f2d80 obstacles;
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((objects))->GetName())); ++i)
        {
            AvoidObject object = objects->FUN_006a1400(i);
            bool include = true;
            if (include)
            {
                FUN_006240d0 sphere;
                sphere.center = *((const class ::FUN_006815c0 *)(new ((void *)&(object)) ::Vec3()));
                sphere.radius = reinterpret_cast<::BSMultiBoundSphere *>(&(object))->GetRadius();
                reinterpret_cast<::Arr16 *>(&(obstacles))->AppendElement((const ::Elem16 *)&(sphere));
            }
        }
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(obstacles))->GetName())); ++i)
        {
            for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(points))->GetName())) - 1; ++j)
            {
                if (!FUN_006ba9e0((*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(j)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), (*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(j + 1)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))),
                                  ((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))->center, ((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))->radius))
                    continue;
                FUN_006815c0 entry29[2];
                if (!ComputeCircleTangents(((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))->center, ((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))->radius,
                                           (*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(j)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), &entry29[0], &entry29[1]))
                    entry29[0] = entry29[1] = (*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(j)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
                bool entryValid2[2];
                entryValid2[0] = reinterpret_cast<::S006F1E90 *>(this)->FUN_006f1e90((int)&(const class class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(j)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (int)&(entry29[0]));
                entryValid2[1] = reinterpret_cast<::S006F1E90 *>(this)->FUN_006f1e90((int)&(const class class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(j)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (int)&(entry29[1]));
                unsigned int end14 = j + 1;
                while (end14 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(points))->GetName())))
                {
                    if (!reinterpret_cast<::C6F1BC0Sphere *>((((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))))->FUN_006f1bc0((const ::NiPoint3 &)((const class class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(end14)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))))))
                        break;
                    ++end14;
                }
                if (end14 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(points))->GetName())))
                {
                    FUN_006815c0 exit[2];
                    if (ComputeCircleTangents(((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))->center, ((struct ::FUN_006240d0 *)(reinterpret_cast<::FUN_00558dd0_class *>(&(obstacles))->FUN_00558dd0(i)))->radius,
                                              (*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(end14)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), &exit[0], &exit[1]))
                    {
                        bool exitValid21[2];
                        exitValid21[0] = reinterpret_cast<::S006F1E90 *>(this)->FUN_006f1e90((int)&(const class class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(end14)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (int)&(exit[0]));
                        exitValid21[1] = reinterpret_cast<::S006F1E90 *>(this)->FUN_006f1e90((int)&(const class class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((points.FUN_00691750(end14)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (int)&(exit[1]));
                        bool available2[2];
                        available2[0] = entryValid2[0] && exitValid21[1];
                        available2[1] = entryValid2[1] && exitValid21[0];
                        bool found12 = false;
                        int from8 = 0, to12 = 1;
                        if (available2[0] && !available2[1])
                        {
                            from8 = 0;
                            to12 = 1;
                            found12 = true;
                        }
                        else if (available2[1] && !available2[0])
                        {
                            from8 = 1;
                            to12 = 0;
                            found12 = true;
                        }
                        else if (available2[0] && available2[1])
                        {
                            float first = reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(entry29[0]))->FUN_00439ef0((::NiPoint3 *)&(exit[1]), *(const ::NiPoint3 *)nullptr)))))->UpdateCombatStyle();
                            float second = reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(entry29[1]))->FUN_00439ef0((::NiPoint3 *)&(exit[0]), *(const ::NiPoint3 *)nullptr)))))->UpdateCombatStyle();
                            if (first < second)
                            {
                                from8 = 0;
                                to12 = 1;
                            }
                            else
                            {
                                from8 = 1;
                                to12 = 0;
                            }
                            found12 = true;
                        }
                        if (found12)
                        {
                            if (end14 > j + 1)
                            {
                                unsigned int count = end14 - j - 1;
                                reinterpret_cast<::LOSArray6f29e0 *>(&(points))->RemoveRange(j + 1, count, 0);
                            }
                            reinterpret_cast<::fnv_006f28a0::FUN_006f28a0_Class *>(&(points))->FUN_006f28a0(j + 1, (::fnv_006f28a0::PathingLocation *)&(const ::FUN_006dd0d0 &)(FUN_006dd0d0(entry29[from8], *points.FUN_00691750(j))));
                            reinterpret_cast<::fnv_006f28a0::FUN_006f28a0_Class *>(&(points))->FUN_006f28a0(j + 2, (::fnv_006f28a0::PathingLocation *)&(const ::FUN_006dd0d0 &)(FUN_006dd0d0(exit[to12], *points.FUN_00691750(j))));
                            break;
                        }
                        else
                            j = end14 - 1;
                    }
                }
            }
        }
    }
}

// Returns whether the squared distance from the point to m_kCenter is less than the squared radius.
// @fnv 0x006f1bc0
bool C6F1BC0Sphere::FUN_006f1bc0(const NiPoint3& akPoint)
{
    return ((const C6F1BC0Vector&)(akPoint - m_kCenter)).SqrLength() < m_fBoundRadius * m_fBoundRadius;
}

struct PathPoint3
{
    float x;
    float y;
    float z;
};
struct PathSegment
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
    PathSegment(const PathPoint3& kPoint, int iCellID);
    ~PathSegment();
};
struct PathCell
{
};
struct PathCellSource
{
    PathCell*& GetLastElement();
};
struct PathSegmentArray
{
    PathSegment& FUN_00691750(unsigned int uiIndex);
};

struct FUN_006f1c10_Path
{
    int unk00;
    int unk04;
    PathPoint3 kStart;
    PathPoint3 kEnd;
    PathCellSource* pCells;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    PathSegmentArray kSegments;

    void AppendSegments(bool abIncludeStart, bool abIncludeEnd);
};

// Appends a segment for the start point, every interior segment, and the end point to the path, depending on the two flags.
// @fnv 0x006f1c10
void FUN_006f1c10_Path::AppendSegments(bool abIncludeStart, bool abIncludeEnd)
{
    if (abIncludeStart)
    {
        PathSegment kFirst(kStart, ((int)(reinterpret_cast<::FUN_0068efb0_shell *>((((::PathCell *)&(::GetFirstElement((const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(pCells))))))->FUN_0068efb0())));
        reinterpret_cast<::FUN_006ed7a0_Class *>(this)->FUN_006ed7a0((const ::PathingLocation &)(kFirst));
    }
    for (unsigned int i = 1; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kSegments))->GetName())) - 1; i++)
        reinterpret_cast<::FUN_006ed7a0_Class *>(this)->FUN_006ed7a0((const ::PathingLocation &)(kSegments.FUN_00691750(i)));
    if (abIncludeEnd)
    {
        PathSegment kLast(kEnd, ((int)(reinterpret_cast<::FUN_0068efb0_shell *>((((::PathCell *)&(::GetLastElement((const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(pCells))))))->FUN_0068efb0())));
        reinterpret_cast<::FUN_006ed7a0_Class *>(this)->FUN_006ed7a0((const ::PathingLocation &)(kLast));
    }
}

// Whether the segment a-b crosses none of the area's border edges (both edge lists).

struct F1ED0Point3
{
    float x;
    float y;
    float z;
};

struct F1ED0Vertex
{
    int unk00;
    int unk04;
    int unk08;
    F1ED0Point3 m_kPos;
};

struct F1ED0Edge
{
    F1ED0Vertex* m_pkStart;
    F1ED0Vertex* m_pkEnd;
};

class F1ED0EdgeArray
{
  public:
    unsigned int GetSize();
    F1ED0Edge*& GetAt(unsigned int uiIndex) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

bool __cdecl F1ED0SegmentsIntersect(const F1ED0Point3& kA0, const F1ED0Point3& kA1, const F1ED0Point3& kB0,
                                    const F1ED0Point3& kB1);

class F1ED0Area
{
  public:
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    F1ED0EdgeArray m_kOuterEdges;
    F1ED0EdgeArray m_kInnerEdges;

    bool IsSegmentClear(const F1ED0Point3& kStart, const F1ED0Point3& kEnd);
};

// Returns false if the segment from kStart to kEnd intersects any outer or inner edge; otherwise returns true.
// @fnv 0x006f1ed0
bool F1ED0Area::IsSegmentClear(const F1ED0Point3& kStart, const F1ED0Point3& kEnd)
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kOuterEdges))->GetName())); i++)
    {
        if (F1ED0SegmentsIntersect(kStart, kEnd, m_kOuterEdges.GetAt(i)->m_pkStart->m_kPos,
                                   m_kOuterEdges.GetAt(i)->m_pkEnd->m_kPos))
            return false;
    }
    for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kInnerEdges))->GetName())); j++)
    {
        if (F1ED0SegmentsIntersect(kStart, kEnd, m_kInnerEdges.GetAt(j)->m_pkStart->m_kPos,
                                   m_kInnerEdges.GetAt(j)->m_pkEnd->m_kPos))
            return false;
    }
    return true;
}

struct PtObj1fc0
{
    int u0;
    int u4;
    int u8;
    NiPoint3 pt;
};
struct Elem1fc0
{
    PtObj1fc0* first;
    PtObj1fc0* second;
};
struct Arr1fc0
{
    int u0;
    int u4;
    int u8;
    int uc;
    int u10;
    Elem1fc0** FUN_00877a30(unsigned int);
    Elem1fc0** FUN_006f2270();
};
struct Host1fc0
{
    int m00;
    int m04;
    NiPoint3 pt08;
    NiPoint3 pt14;
    int m20, m24, m28, m2c, m30, m34, m38, m3c;
    int m40, m44, m48, m4c, m50, m54, m58, m5c;
    int m60, m64, m68, m6c, m70, m74, m78, m7c;
    int m80, m84, m88, m8c;
    Arr1fc0 arr90;
    bool FUN_006f1fc0(int);
};
// Returns true when the second argument passes FUN_006f1fc0 and the pair passes IsSegmentClear; otherwise false.
// @fnv 0x006f1e90
bool S006F1E90::FUN_006f1e90(int aiFirst, int aiSecond)
{
    if (reinterpret_cast<::Host1fc0 *>(this)->FUN_006f1fc0(aiSecond) && reinterpret_cast<::F1ED0Area *>(this)->IsSegmentClear((*(const ::F1ED0Point3 *)(aiFirst)), (*(const ::F1ED0Point3 *)(aiSecond))))
        return true;
    else
        return false;
}
// @fnv 0x006f1fc0
bool Host1fc0::FUN_006f1fc0(int apPoint)
{
    float f6;
    int i;
    if (reinterpret_cast<::FUN_0076b610_Class *>(&(arr90))->FUN_0076b610())
        return true;
    if (FUN_006b9cf0(pt08, (*arr90.FUN_00877a30(0))->second->pt, (*arr90.FUN_00877a30(0))->first->pt,
                     *(const NiPoint3*)apPoint, f6, DAT_0106b158, DAT_0106b158))
        return true;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr90))->GetName())) - 1; i++)
    {
        if ((*arr90.FUN_00877a30(i))->first == (*arr90.FUN_00877a30(i + 1))->first)
        {
            if (FUN_006b9cf0((*arr90.FUN_00877a30(i))->first->pt, (*arr90.FUN_00877a30(i))->second->pt,
                             (*arr90.FUN_00877a30(i + 1))->second->pt, *(const NiPoint3*)apPoint, f6, DAT_0106b158,
                             DAT_0106b158))
                return true;
        }
        else if ((*arr90.FUN_00877a30(i))->second == (*arr90.FUN_00877a30(i + 1))->second)
        {
            if (FUN_006b9cf0((*arr90.FUN_00877a30(i))->first->pt, (*arr90.FUN_00877a30(i))->second->pt,
                             (*arr90.FUN_00877a30(i + 1))->first->pt, *(const NiPoint3*)apPoint, f6, DAT_0106b158,
                             DAT_0106b158))
                return true;
        }
    }
    if (FUN_006b9cf0(pt14, (*((::Elem1fc0 **)(reinterpret_cast<::FUN_006f2270 *>(&(arr90))->GetLast())))->first->pt, (*((::Elem1fc0 **)(reinterpret_cast<::FUN_006f2270 *>(&(arr90))->GetLast())))->second->pt,
                     *(const NiPoint3*)apPoint, f6, DAT_0106b158, DAT_0106b158))
        return true;
    return false;
}

class Heap6F2;

class MemoryManager6F2
{
  public:
};

MemoryManager6F2* GetMemoryManager6F2();

class Base6F2
{
  public:
    Base6F2();
    virtual ~Base6F2();

    int unk04;
    int unk08;
    int unk0C;
    Heap6F2* m_pkHeap;

    void Initialize(unsigned int uiA, unsigned int uiB);
};

class FUN_006f2630 : public Base6F2
{
  public:
    FUN_006f2630(unsigned int uiA, unsigned int uiB, Heap6F2* pkHeap);
    virtual ~FUN_006f2630();
};

// Stores the given heap, or the memory manager's default heap when none is given, then calls Initialize with the two values.
// @fnv 0x006f2630
FUN_006f2630::FUN_006f2630(unsigned int uiA, unsigned int uiB, Heap6F2* pkHeap)
{
    m_pkHeap = pkHeap ? pkHeap : ((::Heap6F2 *)(reinterpret_cast<::MemoryManager *>((GetMemoryManager6F2()))->GetGeneralAllocator()));
    Initialize(uiA, uiB);
}

namespace fnv_006f2b30 {
extern "C" void* __cdecl FUN_00401020(void);

struct FUN_006cf180
{
    FUN_006cf180();
    virtual void unk00();
    ~FUN_006cf180();
};

struct FUN_00aa42e0_Obj
{
    int FUN_00aa42e0();
};

struct FUN_006f2b30 : FUN_006cf180
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_006f2b30();
    virtual void unk00();
};

// Stores the result of FUN_00aa42e0 into unk10 and calls ResizeAndConstruct with 0, 0.
// @fnv 0x006f2b30
FUN_006f2b30::FUN_006f2b30()
{
    unk10 = ((FUN_00aa42e0_Obj*)FUN_00401020())->FUN_00aa42e0();
    reinterpret_cast<::PathingLocationArray *>(this)->ResizeAndConstruct(0, 0);
}
}  // namespace fnv_006f2b30

inline void* __cdecl operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}
inline void __cdecl operator delete(void*, void*)
{}

class C6F3280Bound
{
  public:
    C6F3280Bound();

    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;
    float m_fBoundRadius;
};

class C6F3280Allocator
{
  public:
    void ConstructBounds(C6F3280Bound* pkElements, unsigned int ItemUpdateArray);
};

// @fnv 0x006f3280
void C6F3280Allocator::ConstructBounds(C6F3280Bound* pkElements, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkElements[i]) C6F3280Bound;
}

struct SearchNode
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    SearchNode* parent;
};
struct Neighbours
{
    int unk00, unk04, unk08, unk0c, unk10;
    Neighbours();
    ~Neighbours();
    void Clear(bool);
    SearchNode*& At(unsigned int);
};
struct OpenNodes
{
    void Add(SearchNode*);
};
struct Search
{
    virtual void Unused();
    virtual void Expand(SearchNode*, Neighbours*);
    virtual bool IsGoal(SearchNode*);
    int unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c, unk0020, unk0024, unk0028, unk002c, unk0030,
        unk0034, unk0038, unk003c, unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c, unk0060,
        unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c, unk0080, unk0084, unk0088, unk008c, unk0090,
        unk0094, unk0098, unk009c, unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc, unk00c0,
        unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc, unk00e0, unk00e4, unk00e8, unk00ec, unk00f0,
        unk00f4, unk00f8, unk00fc, unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c, unk0120,
        unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c, unk0140, unk0144, unk0148, unk014c, unk0150,
        unk0154, unk0158, unk015c, unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c, unk0180,
        unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c, unk01a0, unk01a4, unk01a8, unk01ac, unk01b0,
        unk01b4, unk01b8, unk01bc, unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc, unk01e0,
        unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc, unk0200, unk0204, unk0208, unk020c, unk0210,
        unk0214, unk0218, unk021c, unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c, unk0240,
        unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c, unk0260, unk0264, unk0268, unk026c, unk0270,
        unk0274, unk0278, unk027c, unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c, unk02a0,
        unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc, unk02c0, unk02c4, unk02c8, unk02cc, unk02d0,
        unk02d4, unk02d8, unk02dc, unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc, unk0300,
        unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c, unk0320, unk0324, unk0328, unk032c, unk0330,
        unk0334, unk0338, unk033c, unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c, unk0360,
        unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c, unk0380, unk0384, unk0388, unk038c, unk0390,
        unk0394, unk0398, unk039c, unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc, unk03c0,
        unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc, unk03e0, unk03e4, unk03e8, unk03ec, unk03f0,
        unk03f4, unk03f8, unk03fc, unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c, unk0420,
        unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c, unk0440, unk0444, unk0448, unk044c, unk0450,
        unk0454, unk0458, unk045c, unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c, unk0480,
        unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c, unk04a0, unk04a4, unk04a8, unk04ac, unk04b0,
        unk04b4, unk04b8, unk04bc, unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc, unk04e0,
        unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc, unk0500, unk0504, unk0508, unk050c, unk0510,
        unk0514, unk0518, unk051c, unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c, unk0540,
        unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c, unk0560, unk0564, unk0568, unk056c, unk0570,
        unk0574, unk0578, unk057c, unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c, unk05a0,
        unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc, unk05c0, unk05c4, unk05c8, unk05cc, unk05d0,
        unk05d4, unk05d8, unk05dc, unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc, unk0600,
        unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c, unk0620, unk0624, unk0628, unk062c, unk0630,
        unk0634, unk0638, unk063c, unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c, unk0660,
        unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c, unk0680, unk0684, unk0688, unk068c, unk0690,
        unk0694, unk0698, unk069c, unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc, unk06c0,
        unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc, unk06e0, unk06e4, unk06e8, unk06ec, unk06f0,
        unk06f4, unk06f8, unk06fc, unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c, unk0720,
        unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c, unk0740, unk0744, unk0748, unk074c, unk0750,
        unk0754, unk0758, unk075c, unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c, unk0780,
        unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c, unk07a0, unk07a4, unk07a8, unk07ac, unk07b0,
        unk07b4, unk07b8, unk07bc, unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc, unk07e0,
        unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc, unk0800, unk0804, unk0808, unk080c, unk0810,
        unk0814, unk0818, unk081c, unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c, unk0840,
        unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c, unk0860, unk0864, unk0868, unk086c, unk0870,
        unk0874, unk0878, unk087c, unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c, unk08a0,
        unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc, unk08c0, unk08c4, unk08c8, unk08cc, unk08d0,
        unk08d4, unk08d8, unk08dc, unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc, unk0900,
        unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c, unk0920, unk0924, unk0928, unk092c, unk0930,
        unk0934, unk0938, unk093c, unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c, unk0960,
        unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c, unk0980, unk0984, unk0988, unk098c, unk0990,
        unk0994, unk0998, unk099c, unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc, unk09c0,
        unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc, unk09e0, unk09e4, unk09e8, unk09ec, unk09f0,
        unk09f4, unk09f8, unk09fc, unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c, unk0a20,
        unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c, unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50,
        unk0a54, unk0a58, unk0a5c, unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c, unk0a80,
        unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c, unk0aa0, unk0aa4, unk0aa8, unk0aac, unk0ab0,
        unk0ab4, unk0ab8, unk0abc, unk0ac0, unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc, unk0ae0,
        unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc, unk0b00, unk0b04, unk0b08, unk0b0c, unk0b10,
        unk0b14, unk0b18, unk0b1c, unk0b20, unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c, unk0b40,
        unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c, unk0b60, unk0b64, unk0b68, unk0b6c, unk0b70,
        unk0b74, unk0b78, unk0b7c, unk0b80, unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c, unk0ba0,
        unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc, unk0bc0, unk0bc4, unk0bc8, unk0bcc, unk0bd0,
        unk0bd4, unk0bd8, unk0bdc, unk0be0, unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc, unk0c00,
        unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c, unk0c20, unk0c24, unk0c28, unk0c2c, unk0c30,
        unk0c34, unk0c38, unk0c3c, unk0c40, unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c, unk0c60,
        unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c, unk0c80, unk0c84, unk0c88, unk0c8c, unk0c90,
        unk0c94, unk0c98, unk0c9c, unk0ca0, unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc, unk0cc0,
        unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc, unk0ce0, unk0ce4, unk0ce8, unk0cec, unk0cf0,
        unk0cf4, unk0cf8, unk0cfc, unk0d00, unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c, unk0d20,
        unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c, unk0d40, unk0d44, unk0d48, unk0d4c, unk0d50,
        unk0d54, unk0d58, unk0d5c, unk0d60, unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c, unk0d80,
        unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c, unk0da0, unk0da4, unk0da8, unk0dac, unk0db0,
        unk0db4, unk0db8, unk0dbc, unk0dc0, unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc, unk0de0,
        unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc, unk0e00, unk0e04, unk0e08, unk0e0c, unk0e10,
        unk0e14, unk0e18, unk0e1c, unk0e20, unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c, unk0e40,
        unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c, unk0e60, unk0e64, unk0e68, unk0e6c, unk0e70,
        unk0e74, unk0e78, unk0e7c, unk0e80, unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c, unk0ea0,
        unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc, unk0ec0, unk0ec4, unk0ec8, unk0ecc, unk0ed0,
        unk0ed4, unk0ed8, unk0edc, unk0ee0, unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc, unk0f00,
        unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c, unk0f20, unk0f24, unk0f28, unk0f2c, unk0f30,
        unk0f34, unk0f38, unk0f3c, unk0f40, unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c, unk0f60,
        unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c, unk0f80, unk0f84, unk0f88, unk0f8c, unk0f90,
        unk0f94, unk0f98, unk0f9c, unk0fa0, unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc, unk0fc0,
        unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc, unk0fe0, unk0fe4, unk0fe8, unk0fec, unk0ff0,
        unk0ff4, unk0ff8, unk0ffc, unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020,
        unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c, unk1040, unk1044, unk1048, unk104c, unk1050,
        unk1054, unk1058, unk105c, unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c, unk1080,
        unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0, unk10a4, unk10a8, unk10ac, unk10b0,
        unk10b4, unk10b8, unk10bc, unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0,
        unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc, unk1100, unk1104, unk1108, unk110c, unk1110,
        unk1114, unk1118, unk111c, unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c, unk1140,
        unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160, unk1164, unk1168, unk116c, unk1170,
        unk1174, unk1178, unk117c, unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0,
        unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc, unk11c0, unk11c4, unk11c8, unk11cc, unk11d0,
        unk11d4, unk11d8, unk11dc, unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc, unk1200,
        unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220, unk1224, unk1228, unk122c, unk1230,
        unk1234, unk1238, unk123c, unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260,
        unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c, unk1280, unk1284, unk1288, unk128c, unk1290,
        unk1294, unk1298, unk129c, unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc, unk12c0,
        unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0, unk12e4, unk12e8, unk12ec, unk12f0,
        unk12f4, unk12f8, unk12fc, unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320,
        unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c, unk1340, unk1344, unk1348, unk134c, unk1350,
        unk1354, unk1358, unk135c, unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c, unk1380,
        unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0, unk13a4, unk13a8, unk13ac, unk13b0,
        unk13b4, unk13b8, unk13bc, unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0,
        unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc, unk1400, unk1404, unk1408, unk140c, unk1410,
        unk1414, unk1418, unk141c, unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c, unk1440,
        unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460, unk1464, unk1468, unk146c, unk1470,
        unk1474, unk1478, unk147c, unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0,
        unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc, unk14c0, unk14c4, unk14c8, unk14cc, unk14d0,
        unk14d4, unk14d8, unk14dc, unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc, unk1500,
        unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520, unk1524, unk1528, unk152c, unk1530,
        unk1534, unk1538, unk153c, unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560,
        unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c, unk1580, unk1584, unk1588, unk158c, unk1590,
        unk1594, unk1598, unk159c, unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc, unk15c0,
        unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0, unk15e4, unk15e8, unk15ec, unk15f0,
        unk15f4, unk15f8, unk15fc, unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620,
        unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c, unk1640, unk1644, unk1648, unk164c, unk1650,
        unk1654, unk1658, unk165c, unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c, unk1680,
        unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0, unk16a4, unk16a8, unk16ac, unk16b0,
        unk16b4, unk16b8, unk16bc, unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0,
        unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc, unk1700, unk1704, unk1708, unk170c, unk1710,
        unk1714, unk1718, unk171c, unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c, unk1740,
        unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760, unk1764, unk1768, unk176c, unk1770,
        unk1774, unk1778, unk177c, unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0,
        unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc, unk17c0, unk17c4, unk17c8, unk17cc, unk17d0,
        unk17d4, unk17d8, unk17dc, unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc, unk1800,
        unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820, unk1824, unk1828, unk182c, unk1830,
        unk1834, unk1838, unk183c, unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860,
        unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c, unk1880, unk1884, unk1888, unk188c, unk1890,
        unk1894, unk1898, unk189c, unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc, unk18c0,
        unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0, unk18e4, unk18e8, unk18ec, unk18f0,
        unk18f4, unk18f8, unk18fc, unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920,
        unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c, unk1940, unk1944, unk1948, unk194c, unk1950,
        unk1954, unk1958, unk195c, unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c, unk1980,
        unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0, unk19a4, unk19a8, unk19ac, unk19b0,
        unk19b4, unk19b8, unk19bc, unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0,
        unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc, unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10,
        unk1a14, unk1a18, unk1a1c, unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c, unk1a40,
        unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70,
        unk1a74, unk1a78, unk1a7c, unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0,
        unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc, unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0,
        unk1ad4, unk1ad8, unk1adc, unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc, unk1b00,
        unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30,
        unk1b34, unk1b38, unk1b3c, unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60,
        unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c, unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90,
        unk1b94, unk1b98, unk1b9c, unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc, unk1bc0,
        unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc, unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0,
        unk1bf4, unk1bf8, unk1bfc, unk1c00, unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c, unk1c20,
        unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34, unk1c38, unk1c3c, unk1c40, unk1c44, unk1c48, unk1c4c, unk1c50,
        unk1c54, unk1c58, unk1c5c, unk1c60, unk1c64, unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c, unk1c80,
        unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c, unk1ca0, unk1ca4, unk1ca8, unk1cac, unk1cb0,
        unk1cb4, unk1cb8, unk1cbc, unk1cc0, unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc, unk1ce0,
        unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4, unk1cf8, unk1cfc, unk1d00, unk1d04, unk1d08, unk1d0c, unk1d10,
        unk1d14, unk1d18, unk1d1c, unk1d20, unk1d24, unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c, unk1d40,
        unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c, unk1d60, unk1d64, unk1d68, unk1d6c, unk1d70,
        unk1d74, unk1d78, unk1d7c, unk1d80, unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c, unk1da0,
        unk1da4, unk1da8, unk1dac, unk1db0, unk1db4, unk1db8, unk1dbc, unk1dc0, unk1dc4, unk1dc8, unk1dcc, unk1dd0,
        unk1dd4, unk1dd8, unk1ddc, unk1de0, unk1de4, unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc, unk1e00,
        unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c, unk1e20, unk1e24, unk1e28, unk1e2c, unk1e30,
        unk1e34, unk1e38, unk1e3c, unk1e40, unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c, unk1e60,
        unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74, unk1e78, unk1e7c, unk1e80, unk1e84, unk1e88, unk1e8c, unk1e90,
        unk1e94, unk1e98, unk1e9c, unk1ea0, unk1ea4, unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc, unk1ec0,
        unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc, unk1ee0, unk1ee4, unk1ee8, unk1eec, unk1ef0,
        unk1ef4, unk1ef8, unk1efc, unk1f00, unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c, unk1f20,
        unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34, unk1f38, unk1f3c, unk1f40, unk1f44, unk1f48, unk1f4c, unk1f50,
        unk1f54, unk1f58, unk1f5c, unk1f60, unk1f64, unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c, unk1f80,
        unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c, unk1fa0, unk1fa4, unk1fa8, unk1fac, unk1fb0,
        unk1fb4, unk1fb8, unk1fbc, unk1fc0, unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc, unk1fe0,
        unk1fe4, unk1fe8, unk1fec, unk1ff0;
    OpenNodes open;
    int unk1ff8, unk1ffc, unk2000, unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c, unk2020, unk2024,
        unk2028, unk202c, unk2030, unk2034, unk2038, unk203c, unk2040, unk2044;
    SearchNode* best;
    SearchNode* current;
    int unk2050;
    bool yielding;
    SearchNode* StepSearch();
};
struct FUN_006f4640
{
    virtual ~FUN_006f4640();
};

struct FUN_006f4690 : FUN_006f4640
{
    virtual ~FUN_006f4690();
};
// Calls FUN_006f4690 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006f4850
void* FUN_006f4850_Class::FUN_006f4850(unsigned int flags)
{
    reinterpret_cast<::FUN_006f4690 *>((((FUN_006f4690_Class*)this)))->FUN_006f4690::~FUN_006f4690();
    if (flags & 1)
        Deallocate(this);
    return this;
}

FUN_006f4640::~FUN_006f4640()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

// Destructor for the derived class that calls FUN_008454f0 with true.
// @fnv 0x006f4690
FUN_006f4690::~FUN_006f4690()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct ObjRef
{
};
struct NodePtr
{
    void* value;
    NodePtr(void* p = 0);
    ~NodePtr();
    NodePtr& operator=(void* p);
};
struct LoadTask;
struct TaskPtr
{
    LoadTask* value;
    TaskPtr(LoadTask* p = 0);
    ~TaskPtr();
    TaskPtr& operator=(LoadTask* p);
    operator LoadTask*() const;
};
struct MemScope
{
    int context;
    MemScope(int, bool, const char*, int);
    ~MemScope();
};
struct FUN_006f5160;
struct LoadTask
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Start();
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    LoadTask(FUN_006f5160*, ObjRef*, int, int, int, int, bool, int);
};
struct NodePtr_d0045cec0 : NodePtr
{
    NodePtr_d0045cec0(void* p = 0) : NodePtr(p)
    {}
    ~NodePtr_d0045cec0();
    using NodePtr::operator=;
};
struct FUN_006f5160
{
    ObjRef* owner;
    NodePtr_d0045cec0 node04, node08, node0c, node10, node14;
    TaskPtr task18, task1c;
    bool flag20, flag21, flag22, flag23, flag24;
    int value28;
    FUN_006f5160(ObjRef*, int, short, short, bool);
};
// @fnv 0x006f5160
FUN_006f5160::FUN_006f5160(ObjRef* apOwner, int lod, short x, short y, bool flag)
{
    MemScope scope(
        0x24, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantObjectBlock.cpp",
        52);
    owner = apOwner;
    node08 = 0;
    node04 = 0;
    node0c = 0;
    node14 = 0;
    node10 = 0;
    flag20 = 0;
    flag21 = 0;
    flag22 = 0;
    flag23 = !flag;
    flag24 = 0;
    value28 = 0;
    ObjRef* pInnerRef = ((::ObjRef *)(::FUN_00559450((int *)(((::ObjRef *)(::FUN_00559450((int *)(apOwner))))))));
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::TaskPtr &)(task18))->FUN_006f74f0((::ObjA *)(::LoadTask *)(new LoadTask(this, pInnerRef, x, y, lod, 0, !flag, 0)));
    value28 = 0;
    ((LoadTask*)task18)->Start();
}

struct SceneRelease
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void Detach(void*);
};
struct OwnerRef
{
};
struct OwnerHandle
{
};
struct SceneHandle
{
    void* value;
    operator void*() const;
    SceneHandle& operator=(void*);
    ~SceneHandle();
};
struct QueueHandle
{
    void* value;
    operator void*() const;
    QueueHandle& operator=(void*);
    ~QueueHandle();
};

struct ReleaseGlobals
{
};
extern int DAT_011d8514;
struct FUN_006f5370
{
    OwnerHandle* owner;
    SceneHandle scene04, scene08, scene0c, scene10, scene14;
    QueueHandle queue18, queue1c;
    ~FUN_006f5370();
};
// @fnv 0x006f5370
FUN_006f5370::~FUN_006f5370()
{
    reinterpret_cast<::FUN_006f60c0_shell *>(this)->RunLoop();
    if ((void*)scene08 || (void*)scene04)
    {
        --DAT_011d8514;
        ((::SceneRelease *)(reinterpret_cast<::fnv_004ea9c0::GlobalNodeAccessor *>((((::OwnerRef *)(::FUN_00559450((int *)(owner))))))->FUN_004ea9c0()))->Detach(scene08);
        ((::SceneRelease *)(reinterpret_cast<::fnv_004ea9c0::GlobalNodeAccessor *>((((::OwnerRef *)(::FUN_00559450((int *)(owner))))))->FUN_004ea9c0()))->Detach(scene04);
    }
    if ((void*)scene10)
    {
        --DAT_011d8514;
        ((::SceneRelease *)(reinterpret_cast<::fnv_004ea9c0::GlobalNodeAccessor *>((((::OwnerRef *)(::FUN_00559450((int *)(owner))))))->FUN_004ea9c0()))->Detach(scene10);
    }
    if ((void*)queue18)
        reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::Helper_b9266 * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)((unsigned int)(void*)queue18), 0);
    if ((void*)queue1c)
        reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::Helper_b9266 * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)((unsigned int)(void*)queue1c), 0);
    ::FUN_00c45830((::MyRef *)(void *)(scene08));
    ::FUN_00c45830((::MyRef *)(void *)(scene10));
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QueueHandle &)(queue18))->FUN_006f74f0((::ObjA *)(void *)(0));
    scene04 = 0;
    scene0c = 0;
    scene08 = 0;
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QueueHandle &)(queue1c))->FUN_006f74f0((::ObjA *)(void *)(0));
    scene14 = 0;
    scene10 = 0;
    if (reinterpret_cast<::FUN_005bb4d0_shell *>(((*reinterpret_cast<::ReleaseGlobals * *>(&::g_osGlobals))))->FUN_005bb4d0())
        ::FUN_00a61cd0();
}

struct FUN_006f9060
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1c;
    FUN_006f9060();
};

// Placement-constructs auiCount FUN_006f9060 objects in the buffer at apBuffer.
// @fnv 0x006f9ff0
void FUN_006fa180_StandIn::FUN_006f9ff0(int apBuffer, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
        new ((FUN_006f9060*)apBuffer + i) FUN_006f9060;
}

struct GlobalObject_00633c90
{
    void* object;
    GlobalObject_00633c90(int value);
    ~GlobalObject_00633c90();
    GlobalObject_00633c90& operator=(void* value);
    GlobalObject_00633c90& FUN_006e5cc0(const GlobalObject_00633c90& other);
};
struct WorldData
{
};
struct WorldPointer
{
};
struct OwnerPointer
{
};
struct FUN_006fa210;
struct FUN_006fb980
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Start();
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
    bool active30;
    int x34;
    int y38;
    int lod3c;
    FUN_006fa210* owner40;
    WorldData* world44;
    void* node48;
    void* node4c;
    void* node50;
    void* node54;
    bool flag58;
    int unk5c;
    FUN_006fb980(FUN_006fa210*, WorldData*, int, int, int);
};
struct GlobalObject_00528cb0
{
    FUN_006fb980* object;
    GlobalObject_00528cb0(int value);
    ~GlobalObject_00528cb0();
};
class AutoMemContext
{
    int previous;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
extern const char DAT_0106e068[];
struct FUN_006fa210
{
    OwnerPointer* owner;
    GlobalObject_00633c90 node04, node08, node0c, node10, node14, node18;
    int state1c, state20;
    GlobalObject_00528cb0 queued;
    bool flag28, flag29, flag2a;
    GlobalObject_00633c90 node2c;
    FUN_006fa210(OwnerPointer* input, int lod, short x, short y);
};
// @fnv 0x006fa210
FUN_006fa210::FUN_006fa210(OwnerPointer* apOwner, int lod, short x, short y)
    : node04(0), node08(0), node0c(0), node10(0), node14(0), node18(0), queued(0), node2c(0)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_LODLANDSCAPE, true, DAT_0106e068, 48);
    owner = apOwner;
    WorldData* world = ((::WorldData *)(::FUN_00559450((int *)(((::WorldPointer *)(::FUN_00559450((int *)(apOwner))))))));
    reinterpret_cast<::FUN_006f74f0_cls *>(&(queued))->FUN_006f74f0((::ObjA *)(::FUN_006fb980 *)(new FUN_006fb980(this, world, x, y, lod)));
    ((::FUN_006fb980 *)(::FUN_00559450((int *)&(queued))))->Start();
    flag28 = false;
    flag29 = false;
    flag2a = false;
    node04.FUN_006e5cc0(node08.FUN_006e5cc0(node0c = 0));
    node10 = 0;
    node14.FUN_006e5cc0(node18 = 0);
    node2c = 0;
    state1c = 0;
    state20 = 0;
}

class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void InsertChild(NiNode* child);
};
class QueuedFile
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class BSAudio
{
  public:
};
struct FUN_006fa420
{
    NiPointer<NiNode>* owner;
    NiPointer<NiNode> root;
    NiPointer<NiNode> node08;
    NiPointer<NiNode> node0C;
    NiPointer<NiNode> node10;
    NiPointer<NiNode> node14;
    NiPointer<NiNode> node18;
    int unk1C;
    int unk20;
    NiPointer<QueuedFile> queued;
    int unk28;
    NiPointer<NiNode> node2C;
    ~FUN_006fa420();
};
// @fnv 0x006fa420
FUN_006fa420::~FUN_006fa420()
{
    if (root)
        reinterpret_cast<::fnv_006fa6a0::S006FA6A0 *>(this)->FUN_006fa6a0();
    if (root)
    {
        --(*reinterpret_cast<int *>(&::DAT_011d85ec));
        if (node10)
        {
            ((::NiNode *)(reinterpret_cast<::FUN_004ea9a0_Class *>((((NiNode*)*owner)))->FUN_004ea9a0()))->InsertChild(node10);
        }
        else
        {
            ((::NiNode *)(reinterpret_cast<::FUN_004ea9a0_Class *>((((NiNode*)*owner)))->FUN_004ea9a0()))->InsertChild(root);
        }
    }
    else if (queued)
    {
        reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::Helper_b9266 * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)((unsigned int)(QueuedFile*)queued), 0);
    }
    reinterpret_cast<::detach6fb::D6Detacher *>(this)->FUN_006fb3d0(0);
    ::FUN_00c45830((::MyRef *)(::NiNode *)(node10));
    ::FUN_00c45830((::MyRef *)(::NiNode *)(node14));
    ::FUN_00c45830((::MyRef *)(::NiNode *)(node18));
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)(queued))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(0));
    root = 0;
    node08 = 0;
    node10 = 0;
    node14 = 0;
    node18 = 0;
    node2C = 0;
    if (reinterpret_cast<::FUN_005bb4d0_shell *>(((*reinterpret_cast<::BSAudio * *>(&::g_osGlobals))))->FUN_005bb4d0())
        FUN_00a61cd0();
}

namespace fnv_006fa6d0 {
struct ScenePosition
{
    float x;
    float y;
    float z;
    const ScenePosition& FUN_0045bb80() const;
};
struct SceneRenderable
{
};
struct SceneHandle
{
    SceneRenderable* value;
};
struct SceneEntry : SceneHandle
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    SceneHandle second;
    SceneHandle third;
};
struct SceneEntryLink
{
    SceneEntry** FUN_006815c0();
};

struct SceneRadiusUpdater
{
    void ProcessTargetIfEligible(SceneRenderable*, ScenePosition, unsigned int);
};
// @fnv 0x006fa6d0
void UpdateSceneEntryRadii(const ScenePosition& aPosition, unsigned int radius)
{
    unsigned int scale = radius;
    ScenePosition position8 = aPosition.FUN_0045bb80();
    SceneEntryLink* link6 = reinterpret_cast<SceneEntryLink*>(&(*reinterpret_cast<int *>(&::g_011d8624)));
    while (link6)
    {
        SceneEntry* entry = *((::fnv_006fa6d0::SceneEntry **)(new ((void *)(link6)) ::Vec3()));
        if (entry && !((bool)(reinterpret_cast<::FUN_006fa840_shell *>((((::fnv_006fa6d0::SceneRenderable *)(::FUN_00559450((int *)(entry))))))->GetByteAt5D())))
        {
            SceneRenderable* node = ((::fnv_006fa6d0::SceneRenderable *)(::fnv_006fa820::FUN_006fa820((const char *)(entry))));
            if (node)
                ((::fnv_006fa6d0::SceneRadiusUpdater *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->ProcessTargetIfEligible(node, position8, scale);
            node = ((::fnv_006fa6d0::SceneRenderable *)(::FUN_00559450((int *)&(entry->second))));
            if (node)
                ((::fnv_006fa6d0::SceneRadiusUpdater *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->ProcessTargetIfEligible(node, position8, scale);
            node = ((::fnv_006fa6d0::SceneRenderable *)(::FUN_00559450((int *)&(entry->third))));
            if (node)
                ((::fnv_006fa6d0::SceneRadiusUpdater *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->ProcessTargetIfEligible(node, position8, scale);
        }
        link6 = ((::fnv_006fa6d0::SceneEntryLink *)(reinterpret_cast<::Callees *>((link6))->FUN_00726070()));
    }
}
}  // namespace fnv_006fa6d0

struct FUN_006e5cc0_Class
{
    void FUN_006e5cc0(void* a1);
};
// @fnv 0x006faa70
void FUN_006faa70_Class::FUN_006faa70(void* pTarget)
{
    ((FUN_006e5cc0_Class*)pTarget)->FUN_006e5cc0((char*)this + 0x54);
}

namespace fnv_006fe510 {
// @fnv 0x006fe510
int __cdecl FUN_006fe510()
{
    return (int)8u;
}
}  // namespace fnv_006fe510

struct S006f4390_Node
{
    float m_key0;
    float m_key4;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    S006f4390_Node** m_link;
    S006f4390_Node* m_next;

};

struct S006f4390_Map
{
    int m_hashSize;
    S006f4390_Node* m_buckets[20];

    void InsertNode(S006f4390_Node* node);
};
// @fnv 0x006f3d00
S_006f3d00_Node* S_006f3d00_Obj::FUN_006f3d00(int key, S_006f3d00_Vec3* pos, float afValue)
{
    S_006f3d00_Node* node;
    switch (reinterpret_cast<::FUN_006f3e30_shell *>(this)->InsertOrUpdateNode(key, 0.0f, (::AStarNodeTD **)(::S_006f3d00_Node **)(&node)))
    {
    case 0:
        node->unk4 = afValue;
        node->unk8 = *pos;
        reinterpret_cast<::S006f4390_Map *>(&(unk1ff4))->InsertNode((::S006f4390_Node *)(node));
        unk2050 = node;
        return node;
    case 1:
        return node;
    case 2:
        return 0;
    default:
        return 0;
    }
}
// Pops the next open node, expands it, reparents and re-adds its neighbours, tracks the best node, and returns a goal node or null.
// @fnv 0x006f3fb0
SearchNode* Search::StepSearch()
{
    Neighbours neighbours5;
    SearchNode* previous = current;
    current = ((::SearchNode *)(::PopFirstNode((::FUN_006f46f0_Node *)&(open))));
    if (!current)
        return 0;
    best = current;
    int count2 = 0;
    while (current)
    {
        if (IsGoal(current))
        {
            best = current;
            return current;
        }
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(neighbours5))->Clear(false);
        Expand(current, &neighbours5);
        for (unsigned int index = 0; index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(neighbours5))->GetName())); ++index)
        {
            SearchNode* node = neighbours5.At(index);
            reinterpret_cast<::FUN_006f4430_Class *>(&(open))->UnlinkFromList((int *)(node));
            if (current->parent == node)
                return 0;
            node->parent = current;
            reinterpret_cast<::S006f4390_Map *>(&(open))->InsertNode((::S006f4390_Node *)(node));
            if (reinterpret_cast<::TimeoutTimer *>((node))->FUN_006b9130() < reinterpret_cast<::TimeoutTimer *>((best))->FUN_006b9130())
                best = node;
        }
        if (yielding)
        {
            ++count2;
            if (count2 == 50)
            {
                count2 = 0;
                ::FUN_0040fca0(0);
            }
        }
        previous = current;
        current = ((::SearchNode *)(::PopFirstNode((::FUN_006f46f0_Node *)&(open))));
    }
    current = previous;
    return 0;
}

// Computes the bucket for node, walks the bucket list to the first entry with a lower key, then links node in before it.
// @fnv 0x006f4390
void S006f4390_Map::InsertNode(S006f4390_Node* node)
{
    int bucket = ((int)(reinterpret_cast<::FUN_006f4790_cls *>(this)->GetScaledValue((::SpawnedArg *)(node))));
    S006f4390_Node** headX = &m_buckets[bucket];
    S006f4390_Node** cur = headX;
    while (*cur != 0 && ((double)(reinterpret_cast<::FUN_006b9710_Class *>(((*cur)))->GetSum())) < ((double)(reinterpret_cast<::FUN_006b9710_Class *>((node))->GetSum())))
        cur = &(*cur)->m_next;
    if (*cur != 0)
        (*cur)->m_link = &node->m_next;
    node->m_next = *cur;
    node->m_link = cur;
    *cur = node;
}

struct PathingRequestHelper
{
    PathingRequestHelper();
    virtual ~PathingRequestHelper();
    char _pad04[0xAC];
};

struct FUN_00438660
{
    FUN_00438660();
    ~FUN_00438660();
    int unk00[4];
};

struct FUN_0049f1c0
{
    FUN_0049f1c0();
    int unk00[4];
};


struct FUN_006e4a50 : public PathingRequestHelper
{
    float m_fB0;
    float m_fB4;
    float m_fB8;
    float m_fBC;
    float m_fC0;
    int m_iC4;
    FUN_006815c0 m_kPosC8;
    FUN_006815c0 m_kPosD4;
    bool m_bE0;
    bool m_bE1;
    FUN_00438660 m_kE4;
    FUN_0049f1c0 m_kF4;
    int m_i104;
    int m_i108;

    FUN_006e4a50();
    virtual ~FUN_006e4a50();
};

// @fnv 0x006e4a50
FUN_006e4a50::FUN_006e4a50()
{
    m_fB4 = 1.0f;
    m_fB0 = 0.0f;
    m_fB8 = 0.0f;
    m_fBC = 0.0f;
    m_fC0 = 1.0f;
    m_iC4 = 0;
    m_kPosC8 = (*reinterpret_cast<class ::FUN_006815c0 *>((void *)&::NiPoint3::ZERO));
    m_kPosD4 = (*reinterpret_cast<class ::FUN_006815c0 *>((void *)&::NiPoint3::ZERO));
    m_bE0 = false;
    m_bE1 = false;
    m_i104 = 0;
    m_i108 = 0;
}

struct FUN_006ffcf0
{
    unsigned int w00 : 32;
    unsigned int lo : 20;
    unsigned int mid : 4;
    unsigned int hi : 8;
    void SetPackedFields(long a1, int a2, int a3, int a4);
};

// Packs the four arguments into the bitfield: w00 gets a1, hi gets a3, mid gets a4, lo gets a2.
// @fnv 0x006ffd20
void FUN_006ffcf0::SetPackedFields(long aValue, int aLow, int aHigh, int aMid)
{
    w00 = aValue;
    hi = aHigh;
    mid = aMid;
    lo = aLow;
}

struct LockEC7E
{
    int unk00[2];
};

struct EntryEC7E
{
};

class FUN_006ec7e0_C
{
  public:
    int unk00[8];
    LockEC7E m_kLock;

    EntryEC7E* FUN_00449f80(void* a1, void* a2, void* a3, bool a4);
    bool FUN_006ec7e0(void* a1, void* a2, void* a3, bool a4);
};

// Locks the container, inserts or replaces a node via FUN_00449f80, unlocks, and returns the result.
// @fnv 0x006ec7e0
bool FUN_006ec7e0_C::FUN_006ec7e0(void* a1, void* a2, void* a3, bool a4)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kLock))->FUN_0040fbf0((char *)(0));
    bool bResult = reinterpret_cast<::Object *>((FUN_00449f80(a1, a2, a3, a4)))->InsertOrReplaceNode({}, {}, {}, {});
    reinterpret_cast<::RecursiveSpinLock *>(&(m_kLock))->FUN_0040fba0();
    return bResult;
}

struct NavMesh;

struct P3
{
    float x;
    float y;
    float z;
    P3();
    P3 operator-(const P3& rhs) const;
    P3 Cross(const P3& rhs) const;
};

class NavMeshTriangle;
class NiPoint3;
struct NavMesh
{
public:
    ::NavMeshTriangle *GetTriangle(unsigned short);
public:
    ::NiPoint3 GetPlaneNormal(unsigned short);
};
// @fnv 0x006f0d20
void HeightPath::FlattenPathPoints()
{
    HeightFlags flags9(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(points))->GetName())));
    for (unsigned index4 = 0; index4 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(points))->GetName())); ++index4)
    {
        HeightPtr mesh6;
        if (reinterpret_cast<::NavMeshInfo *>((points.GetAt(index4)->info))->ResolveNavMesh((::NavMeshPtr &)(mesh6)))
            flags9.GetAt(index4) = reinterpret_cast<::FUN_006a5ec0_shell *>((((::HeightTriangle *)(reinterpret_cast<::NavMesh *>((((HeightMesh*)mesh6)))->GetTriangle(points.GetAt(index4)->triangle)))))->FUN_006a5ec0();
        points.GetAt(index4)->boundary = 0;
    }
    unsigned firstB = ((unsigned int)(reinterpret_cast<::FUN_006cf700_cls *>(&(flags9))->FindIndexIf((int)&(const bool &)(true), 0, (bool (*)(int, int))(AreBytesEqual))));
    while (firstB != -1)
    {
        unsigned last5 = ((unsigned int)(reinterpret_cast<::FUN_006cf700_cls *>(&(flags9))->FindIndexIf((int)&(const bool &)(false), firstB + 1, (bool (*)(int, int))(AreBytesEqual))));
        if (last5 == -1)
            last5 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(flags9))->GetName())) - 1;
        else
            --last5;
        HeightEntry* beforeB = firstB == 0 ? 0 : points.GetAt(firstB - 1);
        HeightEntry* after5 = last5 == ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(flags9))->GetName())) - 1 ? 0 : points.GetAt(last5 + 1);
        if (beforeB)
            beforeB->boundary = 1;
        if (after5)
            after5->boundary = 2;
        HeightVec fromB = beforeB ? beforeB->position : start;
        HeightVec _to = after5 ? after5->position : end;
        float delta5 = _to.z - fromB.z;
        float lengthVal = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::HeightVec &)((_to - fromB)))->FUN_00589850();
        for (unsigned cursorA = firstB; cursorA <= last5; ++cursorA)
        {
            float distance4 = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::HeightVec &)((points.GetAt(cursorA)->position - fromB)))->FUN_00589850();
            points.GetAt(cursorA)->position.z = fromB.z + delta5 * distance4 / lengthVal;
        }
        if (last5 != ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(flags9))->GetName())) - 1)
        {
            firstB = ((unsigned int)(reinterpret_cast<::FUN_006cf700_cls *>(&(flags9))->FindIndexIf((int)&(const bool &)(true), last5 + 1, (bool (*)(int, int))(AreBytesEqual))));
        }
        else
            firstB = -1;
    }
}

struct PathNode
{
    NavMesh* mesh;
    unsigned short tri;
    int edge;
};

struct PathNodeArray
{
    PathNode& GetAt(int i);
};

struct SearchNodeArray
{
    PathNode* GetAt(unsigned int i) const;
};

struct PointList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct PathSmoother
{
    int unk00;
    int unk04;
    P3 m08;
    int unk14;
    int unk18;
    int unk1C;
    SearchNodeArray* m20;
    PathNodeArray* m24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    PointList m40;
    PointList m54;

    void FUN_006ed850();
};

// Iterates path nodes, resolves adjacent mesh edges, and adds path segments from edge or context points to build a smoothed path.
// @fnv 0x006ed850
void PathSmoother::FUN_006ed850()
{
    reinterpret_cast<::EDBC0Builder *>(this)->FUN_006edbc0();
    for (unsigned int i8 = 0; i8 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((m24))->GetName())); i8++)
    {
        P3 a;
        P3 b;
        reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((m24->GetAt(i8).mesh))->FUN_0068f0c0(m24->GetAt(i8).tri, m24->GetAt(i8).edge, (::NiPoint3 *)&(a), (::NiPoint3 *)&(b));
        if (i8 == 0)
        {
            P3 crTmp = (a - b).Cross(a - m08);
            if (crTmp.z > 0.0)
            {
                reinterpret_cast<::FUN_006edd30_shell *>(this)->FUN_006edd30((const ::Position_006edd30 *)&(b), (const ::Position_006edd30 *)&(a));
            }
            else
            {
                reinterpret_cast<::FUN_006edd30_shell *>(this)->FUN_006edd30((const ::Position_006edd30 *)&(a), (const ::Position_006edd30 *)&(b));
            }
        }
        else if (reinterpret_cast<::NiPoint3 *>(&(a))->FUN_004390c0((const ::NiPoint3 &)(**((::P3 **)(reinterpret_cast<::FUN_006f2270 *>(&(m40))->GetLast())))))
        {
            reinterpret_cast<::Builder390 *>(this)->AddPathFromEdge((const ::Vec390 *)&(b), i8);
        }
        else if (reinterpret_cast<::NiPoint3 *>(&(a))->FUN_004390c0((const ::NiPoint3 &)(**((::P3 **)(reinterpret_cast<::FUN_006f2270 *>(&(m54))->GetLast())))))
        {
            reinterpret_cast<::PBBuilder *>(this)->AddPathFromContext((const ::Position_006edd30 *)&(b), i8);
        }
        else if (reinterpret_cast<::NiPoint3 *>(&(b))->FUN_004390c0((const ::NiPoint3 &)(**((::P3 **)(reinterpret_cast<::FUN_006f2270 *>(&(m40))->GetLast())))))
        {
            reinterpret_cast<::Builder390 *>(this)->AddPathFromEdge((const ::Vec390 *)&(a), i8);
        }
        else if (reinterpret_cast<::NiPoint3 *>(&(b))->FUN_004390c0((const ::NiPoint3 &)(**((::P3 **)(reinterpret_cast<::FUN_006f2270 *>(&(m54))->GetLast())))))
        {
            reinterpret_cast<::PBBuilder *>(this)->AddPathFromContext((const ::Position_006edd30 *)&(a), i8);
        }
        else
        {
            NavMesh* mesh9 = 0;
            unsigned short tri = 0xFFFF;
            int edge9 = -1;
            reinterpret_cast<::MeshX *>((m20->GetAt(i8 - 1)->mesh))->FindAdjacentEdge(m20->GetAt(i8 - 1)->tri, m24->GetAt(i8 - 1).edge, (::MeshX **)&(mesh9), (unsigned short *)&(tri),
                                                       (int *)&(edge9));
            if (0)
            {
            }
            P3 c;
            P3 d4;
            reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((mesh9))->FUN_0068f0c0(tri, edge9, (::NiPoint3 *)&(c), (::NiPoint3 *)&(d4));
            P3 left3;
            P3 rightB;
            if (reinterpret_cast<::NiPoint3 *>(((*((::P3 **)(reinterpret_cast<::FUN_006f2270 *>(&(m54))->GetLast())))))->FUN_004390c0((const ::NiPoint3 &)(c)))
            {
                left3 = d4;
                rightB = c;
            }
            else
            {
                left3 = c;
                rightB = d4;
            }
            if (reinterpret_cast<::NiPoint3 *>(&(a))->FUN_004390c0((const ::NiPoint3 &)(left3)))
            {
                reinterpret_cast<::Builder390 *>(this)->AddPathFromEdge((const ::Vec390 *)&(b), i8);
            }
            else if (reinterpret_cast<::NiPoint3 *>(&(a))->FUN_004390c0((const ::NiPoint3 &)(rightB)))
            {
                reinterpret_cast<::PBBuilder *>(this)->AddPathFromContext((const ::Position_006edd30 *)&(b), i8);
            }
            else if (reinterpret_cast<::NiPoint3 *>(&(b))->FUN_004390c0((const ::NiPoint3 &)(left3)))
            {
                reinterpret_cast<::Builder390 *>(this)->AddPathFromEdge((const ::Vec390 *)&(a), i8);
            }
            else if (reinterpret_cast<::NiPoint3 *>(&(b))->FUN_004390c0((const ::NiPoint3 &)(rightB)))
            {
                reinterpret_cast<::PBBuilder *>(this)->AddPathFromContext((const ::Position_006edd30 *)&(a), i8);
            }
        }
    }
    reinterpret_cast<::fnv_006ee5d0::FUN_006ee5d0_Class *>(this)->CreateNavMeshEdges();
}

void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* object, void* place);

struct Allocator_006edc40
{
    void* Allocate(unsigned int size, unsigned int flags);
    int FUN_006815c0();
};

struct Object_006edc40
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    Object_006edc40(int value);
};

struct Host_006edc40
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    Allocator_006edc40 allocator;
    void* FUN_006edc40();
};
// @fnv 0x006edd30
void FUN_006edd30_shell::FUN_006edd30(const Position_006edd30* start, const Position_006edd30* finish)
{
    Location_006edd30* startLocation2 = ((::Location_006edd30 *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    LocationContext_006edd30* context_2 = ((::LocationContext_006edd30 *)(reinterpret_cast<::EdgeArr *>((contexts))->FUN_006ced70()));
    startLocation2->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((context_2->stampSource))->FUN_0068efb0()));
    startLocation2->index = context_2->index;
    startLocation2->position = *start;

    Location_006edd30* finishLocation = ((::Location_006edd30 *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    finishLocation->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((context_2->stampSource))->FUN_0068efb0()));
    finishLocation->index = context_2->index;
    finishLocation->position = *finish;

    PathEdge_006edd30* startEdge = ((::PathEdge_006edd30 *)(reinterpret_cast<::FUN_006edfc0_Host *>(this)->CreateSize28()));
    startEdge->nodeKey = *reinterpret_cast<::FUN_006f2270 *>(&(starts))->GetLast();
    startEdge->location = startLocation2;
    startEdge->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((context_2->stampSource))->FUN_0068efb0()));
    startEdge->index = context_2->index;
    startEdge->nextIndex = 0xffffffff;
    startEdge->state = 0;
    startEdge->active = 1;

    PathEdge_006edd30* finishEdge4 = ((::PathEdge_006edd30 *)(reinterpret_cast<::FUN_006edfc0_Host *>(this)->CreateSize28()));
    finishEdge4->nodeKey = *reinterpret_cast<::FUN_006f2270 *>(&(ends))->GetLast();
    finishEdge4->location = finishLocation;
    finishEdge4->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((context_2->stampSource))->FUN_0068efb0()));
    finishEdge4->index = context_2->index;
    finishEdge4->nextIndex = 0xffffffff;
    finishEdge4->state = 0;
    finishEdge4->active = 1;

    Path_006edd30* path5 = ((::Path_006edd30 *)(reinterpret_cast<::FUN_006ee070_cls *>(this)->CreateObject()));
    path5->start = startLocation2;
    path5->finish = finishLocation;
    path5->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((context_2->stampSource))->FUN_0068efb0()));
    path5->index = context_2->index;
    path5->formID = context_2->formID;
    path5->state = 0;
    path5->startEdge = startEdge;
    path5->finishEdge = finishEdge4;
    reinterpret_cast<::FUN_00438690 *>(&(startLocation2->relatedPaths))->FUN_007cb2e0((unsigned int *)(void **)((void**)&path5));
    reinterpret_cast<::FUN_00438690 *>(&(finishLocation->relatedPaths))->FUN_007cb2e0((unsigned int *)(void **)((void**)&path5));

    Position_006edd30 firstPositionVal;
    Position_006edd30 lastPosition;
    reinterpret_cast<::NavMesh *>((positions->FUN_006dad90(0)->source))->GetPlaneNormal((unsigned short)(&firstPositionVal));
    reinterpret_cast<::NavMesh *>((positions->FUN_006dad90(1)->source))->GetPlaneNormal((unsigned short)(&lastPosition));
    path5->distance = reinterpret_cast<::FUN_004b6190_shell *>(&(firstPositionVal))->DotProduct((void *)(&lastPosition));

    reinterpret_cast<::FUN_00438690 *>(&(starts))->FUN_007cb2e0((unsigned int *)(void **)((void**)&startLocation2));
    reinterpret_cast<::FUN_00438690 *>(&(ends))->FUN_007cb2e0((unsigned int *)(void **)((void**)&finishLocation));
    reinterpret_cast<::FUN_00438690 *>(&(startEdges))->FUN_007cb2e0((unsigned int *)(void **)((void**)&startEdge));
    reinterpret_cast<::FUN_00438690 *>(&(endEdges))->FUN_007cb2e0((unsigned int *)(void **)((void**)&finishEdge4));
    reinterpret_cast<::FUN_00438690 *>(&(paths))->FUN_007cb2e0((unsigned int *)(void **)((void**)&path5));
}
// Splits the node at index into two nodes joined by a bridge edge, redistributing edges and creating a new edge at the split index.
// @fnv 0x006ee740
Node* FUN_006ee740_Class::SplitNode(unsigned index, bool side, const NiPoint3& start, const NiPoint3& end)
{
    Node* old = side ? nodesA.FUN_00877a30(index) : nodesB.FUN_00877a30(index);
    Node* added = ((::Node *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    added->origin = old->origin;
    added->info.FUN_0069a690(&old->info);
    unsigned count = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(old->edges))->GetName()));
    old->position = start;
    old->direction = old->position - old->origin;
    added->position = end;
    added->direction = added->position - added->origin;
    if (count == 1)
        reinterpret_cast<::FUN_00438690 *>(&(added->edges))->FUN_007cb2e0((unsigned int *)&(old->edges.FUN_00877a30(0)));
    else
    {
        unsigned half = count >> 1;
        for (unsigned i = half; i < count; i++)
        {
            if (side)
                old->edges.FUN_00877a30(i)->first = added;
            else
                old->edges.FUN_00877a30(i)->second = added;
            reinterpret_cast<::FUN_00438690 *>(&(added->edges))->FUN_007cb2e0((unsigned int *)&(old->edges.FUN_00877a30(i)));
        }
        reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(old->edges))->FUN_006f2290(half, true);
    }
    if (side)
        reinterpret_cast<::FUN_006f23d0_Class *>(&(nodesA))->FUN_006f23d0(index + 1, (void *&)(added));
    else
        reinterpret_cast<::FUN_006f23d0_Class *>(&(nodesB))->FUN_006f23d0(index + 1, (void *&)(added));
    Edge* bridge = ((::Edge *)(reinterpret_cast<::FUN_006edfc0_Host *>(this)->CreateSize28()));
    bridge->first = old;
    bridge->second = added;
    reinterpret_cast<::FUN_006eec00_Class *>(this)->SetEntry(index, bridge, side);
    if (side)
    {
        reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::EH &)(bridge->info))->CopyFromNavMeshEdge((void *)&(edgesA.FUN_00877a30(index)->info));
        bridge->flag = edgesA.FUN_00877a30(index)->flag;
        edgesA.FUN_00877a30(index + 1)->first = added;
    }
    else
    {
        reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::EH &)(bridge->info))->CopyFromNavMeshEdge((void *)&(edgesB.FUN_00877a30(index)->info));
        bridge->flag = edgesB.FUN_00877a30(index)->flag;
        edgesB.FUN_00877a30(index + 1)->first = added;
    }
    unsigned split;
    Edge* edgeIndex = ((::Edge *)(reinterpret_cast<::FUN_006ee070_cls *>(this)->CreateObject()));
    if (side)
    {
        if (FUN_00696540(&old->position, &((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->second->position, &added->origin,
                         &added->position))
        {
            edgeIndex->first = added;
            edgeIndex->second = ((::Edge *)(reinterpret_cast<::FUN_006f2270 *>(&(old->edges))->GetLast()))->second;
            edgeIndex->left = bridge;
            edgeIndex->right = ((::Edge *)(reinterpret_cast<::FUN_006f2270 *>(&(old->edges))->GetLast()))->right;
        }
        else
        {
            edgeIndex->first = old;
            edgeIndex->second = ((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->second;
            edgeIndex->left = ((::Edge *)(reinterpret_cast<::FUN_006f2270 *>(&(old->edges))->GetLast()))->left;
            edgeIndex->right = ((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->right;
        }
    }
    else
    {
        if (FUN_00696540(&old->position, &((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->first->position, &added->origin,
                         &added->position))
        {
            edgeIndex->first = ((::Edge *)(reinterpret_cast<::FUN_006f2270 *>(&(old->edges))->GetLast()))->first;
            edgeIndex->second = added;
            edgeIndex->left = ((::Edge *)(reinterpret_cast<::FUN_006f2270 *>(&(old->edges))->GetLast()))->left;
            edgeIndex->right = bridge;
        }
        else
        {
            edgeIndex->first = ((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->first;
            edgeIndex->second = old;
            edgeIndex->left = ((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->left;
            edgeIndex->right = ((::Edge *)(reinterpret_cast<::FUN_006f2270 *>(&(old->edges))->GetLast()))->right;
        }
    }
    split = ((::Edge *)&(::GetFirstForm((::NiFormArray *)&(added->edges))))->index;
    reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::EH &)(edgeIndex->bound))->CopyFromNavMeshEdge((void *)&(edgesC.FUN_00877a30(split)->bound));
    edgeIndex->weight = 1.0f;
    reinterpret_cast<::FUN_006eecc0_Owner *>(this)->AssignRecordIndices(split, (unsigned int)(edgeIndex));
    return added;
}
// Creates an entry from the source location's nav mesh info and triangle, copies the builder's point, and adds it to both the all and open arrays.
// @fnv 0x006edbc0
void EDBC0Builder::FUN_006edbc0()
{
    EDBC0Entry* pkEntry = ((::EDBC0Entry *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    EDBC0Location* pkLocation = ((::EDBC0Location *)&(::GetFirstElement((const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(m_pkSource))));
    pkEntry->m_pkNavMeshInfo = ((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((pkLocation->m_pkNavMesh))->FUN_0068efb0()));
    pkEntry->m_usTriangle = pkLocation->m_usTriangle;
    pkEntry->m_kPathOffset = m_kPathOffset;
    reinterpret_cast<::FUN_00438690 *>(&(m_kAll))->FUN_007cb2e0((unsigned int *)&(pkEntry));
    reinterpret_cast<::FUN_00438690 *>(&(m_kOpen))->FUN_007cb2e0((unsigned int *)&(pkEntry));
}
// Creates a location, edge and path from the context at aiIndex, links them, computes the path distance and appends them to the builder's lists.
// @fnv 0x006ee150
void PBBuilder::AddPathFromContext(const Position_006edd30* apPosition, int aiIndex)
{
    Location_006edd30* pLocation = ((::Location_006edd30 *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    PBContext* pContext9 = m_pContextArray->GetAt(aiIndex);
    pLocation->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((pContext9->m_pLocationNavMesh))->FUN_0068efb0()));
    pLocation->index = pContext9->usIndex;
    pLocation->position = *apPosition;

    PathEdge_006edd30* pRetrievedObject = ((::PathEdge_006edd30 *)(reinterpret_cast<::FUN_006edfc0_Host *>(this)->CreateSize28()));
    pRetrievedObject->nodeKey = *reinterpret_cast<::FUN_006f2270 *>(&(kStarts))->GetLast();
    pRetrievedObject->location = pLocation;
    pRetrievedObject->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((pContext9->m_pLocationNavMesh))->FUN_0068efb0()));
    pRetrievedObject->index = pContext9->usIndex;
    pRetrievedObject->nextIndex = (pContext9->m_iEdgeNumber + 1) % 3;
    pRetrievedObject->active =
        ((unsigned char)(reinterpret_cast<::FUN_0068f200_shell *>((((::PBTriangle *)(reinterpret_cast<::NavMesh *>((pContext9->m_pLocationNavMesh))->GetTriangle(pContext9->usIndex)))))->FUN_0068f200(pRetrievedObject->nextIndex)));
    pRetrievedObject->state = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kStartEdges))->GetName()));

    Path_006edd30* pPath2 = ((::Path_006edd30 *)(reinterpret_cast<::FUN_006ee070_cls *>(this)->CreateObject()));
    pPath2->start = pLocation;
    pPath2->finish = (Location_006edd30*)*reinterpret_cast<::FUN_006f2270 *>(&(kEnds))->GetLast();
    pPath2->stamp = ((unsigned int)(reinterpret_cast<::FUN_0068efb0_shell *>((pContext9->m_pLocationNavMesh))->FUN_0068efb0()));
    pPath2->index = pContext9->usIndex;
    pPath2->formID = pContext9->m_iEdgeNumber;
    pPath2->state = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kPaths))->GetName()));
    pPath2->startEdge = pRetrievedObject;
    pPath2->finishEdge = (PathEdge_006edd30*)*reinterpret_cast<::FUN_006f2270 *>(&(kEndEdges))->GetLast();
    reinterpret_cast<::FUN_00438690 *>(&(pLocation->relatedPaths))->FUN_007cb2e0((unsigned int *)(void **)((void**)&pPath2));
    reinterpret_cast<::FUN_00438690 *>(&(((Location_006edd30*)*reinterpret_cast<::FUN_006f2270 *>(&(kEnds))->GetLast())->relatedPaths))->FUN_007cb2e0((unsigned int *)(void **)((void**)&pPath2));

    Position_006edd30 kStart2;
    reinterpret_cast<::NavMesh *>((pPositions->FUN_006dad90(aiIndex)->source))->GetPlaneNormal((unsigned short)(&kStart2));
    Position_006edd30 kEnd;
    reinterpret_cast<::NavMesh *>((pPositions->FUN_006dad90(aiIndex + 1)
        ->source))->GetPlaneNormal((unsigned short)(&kEnd));
    pPath2->distance = reinterpret_cast<::FUN_004b6190_shell *>(&(kStart2))->DotProduct((void *)(&kEnd));

    reinterpret_cast<::FUN_00438690 *>(&(kStarts))->FUN_007cb2e0((unsigned int *)(void **)((void**)&pLocation));
    reinterpret_cast<::FUN_00438690 *>(&(kStartEdges))->FUN_007cb2e0((unsigned int *)(void **)((void**)&pRetrievedObject));
    reinterpret_cast<::FUN_00438690 *>(&(kPaths))->FUN_007cb2e0((unsigned int *)(void **)((void**)&pPath2));
}
// Creates a location, link and path from the parent edge at index, computes the dot of the two search positions, and appends them to the builder's lists.
// @fnv 0x006ee390
void Builder390::AddPathFromEdge(const Vec390* position, int index)
{
    Location390* location5 = ((::Location390 *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    Parent390* parent = &parents->GetAt(index);
    location5->info = ((::Info390 *)(reinterpret_cast<::FUN_0068efb0_shell *>((parent->mesh))->FUN_0068efb0()));
    location5->triangle = parent->triangle;
    location5->position = *position;
    Link390* link = ((::Link390 *)(reinterpret_cast<::FUN_006edfc0_Host *>(this)->CreateSize28()));
    link->previous = ((::Location390 *)(reinterpret_cast<::FUN_006f2270 *>(&(locations))->GetLast()));
    link->location = location5;
    link->info = ((::Info390 *)(reinterpret_cast<::FUN_0068efb0_shell *>((parent->mesh))->FUN_0068efb0()));
    link->triangle = parent->triangle;
    link->edge = (parent->edge + 2) % 3;
    link->flag = ((unsigned char)(reinterpret_cast<::FUN_0068f200_shell *>((((::Tri390 *)(reinterpret_cast<::NavMesh *>((parent->mesh))->GetTriangle(parent->triangle)))))->FUN_0068f200(link->edge)));
    link->index = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(links))->GetName()));
    Path390* path8 = ((::Path390 *)(reinterpret_cast<::FUN_006ee070_cls *>(this)->CreateObject()));
    path8->previous = ((::Path390 *)(reinterpret_cast<::FUN_006f2270 *>(&(paths))->GetLast()));
    path8->location = location5;
    path8->info = ((::Info390 *)(reinterpret_cast<::FUN_0068efb0_shell *>((parent->mesh))->FUN_0068efb0()));
    path8->triangle = parent->triangle;
    path8->edge = parent->edge;
    path8->index = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(allPaths))->GetName()));
    path8->prior = ((::Path390 *)(reinterpret_cast<::FUN_006f2270 *>(&(other))->GetLast()));
    path8->link = link;
    reinterpret_cast<::FUN_00438690 *>(&(location5->paths))->FUN_007cb2e0((unsigned int *)&(path8));
    reinterpret_cast<::FUN_00438690 *>(&(((::Path390 *)(reinterpret_cast<::FUN_006f2270 *>(&(paths))->GetLast()))->paths))->FUN_007cb2e0((unsigned int *)&(path8));
    Vec390 first2 = search->Get(index)->mesh->Position(search->Get(index)->triangle);
    Vec390 second = search->Get(index + 1)->mesh->Position(search->Get(index + 1)->triangle);
    path8->dot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(first2))->DotProduct((void *)&(second));
    reinterpret_cast<::FUN_00438690 *>(&(locations))->FUN_007cb2e0((unsigned int *)&(location5));
    reinterpret_cast<::FUN_00438690 *>(&(links))->FUN_007cb2e0((unsigned int *)&(link));
    reinterpret_cast<::FUN_00438690 *>(&(allPaths))->FUN_007cb2e0((unsigned int *)&(path8));
}
// Splits the edge at index on the chosen side, creating a new node and two edges and inserting them into the node and edge arrays.
// @fnv 0x006eed30
NodeS* HostS::SplitEdge(unsigned int index, bool side)
{
    ArrE* arr3 = side ? &edgesA : &edgesB;
    EdgeS* cur3 = ((::EdgeS *)(reinterpret_cast<::S3e60 *>((arr3))->FUN_006a7ad0(index)));
    NodeS* first7 = cur3->first;
    NodeS* second6 = cur3->second;
    EdgeS* exist = reinterpret_cast<::FUN_0076b610_Class *>(&(first7->edges))->FUN_0076b610() ? ((::EdgeS *)&(::GetFirstForm((::NiFormArray *)&(second6->edges)))) : ((::EdgeS *)(reinterpret_cast<::FUN_006f2270 *>(&(first7->edges))->GetLast()));
    NodeS* nn = ((::NodeS *)(reinterpret_cast<::Host_006edc40 *>(this)->FUN_006edc40()));
    nn->origin = first7->origin;
    nn->info.FUN_0069a690(&first7->info);
    if (side)
        reinterpret_cast<::FUN_006f23d0_Class *>(&(nodesA))->FUN_006f23d0(index + 1, (void *&)(nn));
    else
        reinterpret_cast<::FUN_006f23d0_Class *>(&(nodesB))->FUN_006f23d0(index + 1, (void *&)(nn));
    EdgeS* e6 = ((::EdgeS *)(reinterpret_cast<::FUN_006edfc0_Host *>(this)->CreateSize28()));
    e6->first = first7;
    e6->second = nn;
    reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::EH &)(e6->info))->CopyFromNavMeshEdge((void *)&(((::EdgeS *)(reinterpret_cast<::S3e60 *>((arr3))->FUN_006a7ad0(index)))->info));
    e6->flag = ((::EdgeS *)(reinterpret_cast<::S3e60 *>((arr3))->FUN_006a7ad0(index)))->flag;
    ((::EdgeS *)(reinterpret_cast<::S3e60 *>((arr3))->FUN_006a7ad0(index)))->first = nn;
    reinterpret_cast<::FUN_006eec00_Class *>(this)->SetEntry(index, e6, side);
    EdgeS* e9 = ((::EdgeS *)(reinterpret_cast<::FUN_006ee070_cls *>(this)->CreateObject()));
    e9->weight = 1.0f;
    reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::EH &)(e9->bound))->CopyFromNavMeshEdge((void *)&(exist->bound));
    if (side)
    {
        e9->first = nn;
        e9->second = exist->second;
        e9->right = exist->right;
        e9->left = e6;
    }
    else
    {
        e9->first = exist->first;
        e9->left = exist->left;
        e9->second = nn;
        e9->right = e6;
    }
    if (reinterpret_cast<::FUN_0076b610_Class *>(&(first7->edges))->FUN_0076b610())
        reinterpret_cast<::FUN_006eecc0_Owner *>(this)->AssignRecordIndices(((::EdgeS *)&(::GetFirstForm((::NiFormArray *)&(second6->edges))))->index, (unsigned int)(e9));
    else
        reinterpret_cast<::FUN_006eecc0_Owner *>(this)->AssignRecordIndices(((::EdgeS *)(reinterpret_cast<::FUN_006f2270 *>(&(first7->edges))->GetLast()))->index + 1, (unsigned int)(e9));
    return nn;
}

// Allocates 0x40 bytes from the allocator and constructs an Object_006edc40 in that memory, returning the pointer.
// @fnv 0x006edc40
void* Host_006edc40::FUN_006edc40()
{
    void* memory = reinterpret_cast<::FUN_00aa54a0_s *>(&(allocator))->FUN_00aa54a0(0x40, DAT_010a2720);
    new (memory) Object_006edc40(((int)(new ((void *)&(allocator)) ::Vec3())));
    return memory;
}

class SMPPoint
{
  public:
    float x, y, z;
    SMPPoint(float fX, float fY, float fZ);
    SMPPoint& operator+=(const SMPPoint& kOther);
    SMPPoint& operator/=(float fScalar);
    SMPPoint operator-(const SMPPoint& kOther) const;
    SMPPoint operator+(const SMPPoint& kOther) const;
    SMPPoint operator*(float fScalar) const;
    bool operator==(const SMPPoint& kOther) const;
};
SMPPoint operator*(float fScalar, const SMPPoint& kPoint);
SMPPoint FUN_006ba550(const SMPPoint* pkA, const SMPPoint* pkB, const SMPPoint* pkBefore, const SMPPoint* pkAfter);
float FUN_00408840(float fValue);

struct SMPNode
{
    int unk00;
    int unk04;
    SMPPoint m_kPos;       // +0x08
    SMPPoint m_kSmoothed;  // +0x14
    SMPPoint m_kLeft;      // +0x20
    SMPPoint m_kRight;     // +0x2c
};

struct SMPNodeArray
{
    SMPNode*& FUN_00877a30(int iIndex);
};

struct SMPSide
{
};

class SMPPath
{
  public:
    int unk00;
    SMPSide* m_pkSide;       // +0x04
    SMPPoint m_kStartPoint;  // +0x08
    SMPPoint m_kEnd;         // +0x14
    int unk20[28];
    SMPNodeArray m_kNodeArray;  // +0x90

    void SmoothNodes();
};

class FUN_006f3140
{
  public:
    FUN_006f3140();
    virtual ~FUN_006f3140();

    int unk04;
    int unk08;
    int unk0C;
    void* m_pkHeap;
};

class FUN_006f2750 : public FUN_006f3140
{
  public:
    FUN_006f2750(unsigned int uiA, unsigned int uiB, void* pkHeap);
    virtual ~FUN_006f2750();
};

// @fnv 0x006f2750
FUN_006f2750::FUN_006f2750(unsigned int uiA, unsigned int uiB, void* pkHeap)
{
    m_pkHeap = pkHeap ? pkHeap : ((void *)(reinterpret_cast<::MemoryManager *>((FUN_00401020()))->GetGeneralAllocator()));
    ((AX*)this)->FUN_006b3eb0(uiA, uiB);
}

class LoadMember6F51
{
  public:
    virtual void v00();
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    int unk04[9];
};

class LoadHolder6F51
{
  public:
    unsigned int m_uiValue1;
    LoadMember6F51 m_kMember;
    TESObjectREFR* m_pReference;

    void FUN_006f5100(BGSLoadFormBuffer* apBuffer);
};

// Calls FUN_00864980(this, 4) on apBuffer, sets m_pReference via FUN_004839c0 and a dynamic_cast to TESObjectREFR, then calls m_kMember.LoadGame.
// @fnv 0x006f5100
void LoadHolder6F51::FUN_006f5100(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 4);
    m_pReference = dynamic_cast<TESObjectREFR*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apBuffer))->FUN_008648a0()));
    m_kMember.LoadGame(apBuffer);
}

class FUN_006fca40
{
  public:
    ~FUN_006fca40();
    int unk0;
};
class FUN_005e04f0
{
  public:
    ~FUN_005e04f0();
    int unk[4];
};
class FUN_006fc980
{
  public:
    int unk0;
    FUN_006fca40* m_pData;
    NiPointer<NiNode> m_spA;
    NiPointer<NiNode> m_spB;
    int unk10[7];
    FUN_005e04f0 m_kList;
    ~FUN_006fc980();
};
// Destructor that deletes m_pData and nulls the m_spA and m_spB NiNode pointers.
// @fnv 0x006fc980
FUN_006fc980::~FUN_006fc980()
{
    delete m_pData;
    m_spA = 0;
    m_spB = 0;
}

struct EventArg6FF
{
    unsigned __int64 m_uiKey;
    int m_iType;
};

class Owner6FF
{
  public:
    int unk00[15];
    char unk3C;
    bool m_bFlag;
    char unk3E[2];
    unsigned int m_uiKey;

    void OnEvent(EventArg6FF* pkArg);
};

// If the event key matches m_uiKey, sets m_bFlag to true when the event type is 1, otherwise false.
// @fnv 0x006ff8a0
void Owner6FF::OnEvent(EventArg6FF* pkArg)
{
    if (m_uiKey == pkArg->m_uiKey)
        m_bFlag = (pkArg->m_iType == 1);
}

struct SteamParam
{
    unsigned __int64 unk00;
};

struct C006ff8f0
{
    char unk00[0x40];
    unsigned int unk40;

    void FUN_006ff8f0(SteamParam* a1);
};

// @fnv 0x006ff8f0
void C006ff8f0::FUN_006ff8f0(SteamParam* a1)
{
    if ((unsigned __int64)unk40 == a1->unk00)
    {
    }
}

struct ThreadOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual bool IsOwnerThread(unsigned long id);
};
unsigned long __cdecl FUN_0040fc90();
struct PathSearch : public Search
{
    bool FindPath(int a, int b, bool useBest);
};
// Steps the search, picks the target node (best or none), copies its node list into arrays, and returns whether a path was found.
// @fnv 0x006f3d90
bool PathSearch::FindPath(int a, int b, bool useBest)
{
    yielding = ((::ThreadOwner *)&(::GetTaskletManager()))->IsOwnerThread(FUN_0040fc90());
    bool found;
    SearchNode* target;
    SearchNode* node2 = StepSearch();
    if (node2)
    {
        found = true;
        target = node2;
    }
    else if (useBest)
    {
        found = false;
        target = best;
    }
    else
    {
        found = false;
        target = 0;
    }
    if (target)
        reinterpret_cast<::FUN_006f4230_Class *>(this)->CopyNodeListToArrays((::FUN_006f4230_Node *)(target), (::H2 *)(a), (::FUN_006f4480_Class *)(b));
    return found;
}

class FUN_006e0f90_base
{
  public:
    virtual ~FUN_006e0f90_base();
    int unk04;
};

class FUN_006e0f90_cls : public FUN_006e0f90_base
{
  public:
    virtual ~FUN_006e0f90_cls();
    void unk08();
};
// @fnv 0x006e0ef0
void* FUN_006e0f90_Class::FUN_006e0ef0(unsigned int flags)
{
    reinterpret_cast<::FUN_006e0f90_cls *>(this)->FUN_006e0f90_cls::~FUN_006e0f90_cls();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// Destructor that calls its own unk08 method.
// @fnv 0x006e0f90
FUN_006e0f90_cls::~FUN_006e0f90_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
}

// @fnv 0x006e20b0
struct FUN_006e20b0 : NiTPointerMap<unsigned int, unsigned int>
{
    virtual ~FUN_006e20b0();
};
FUN_006e20b0::~FUN_006e20b0()
{}

struct FUN_006e3ab0
{
    ~FUN_006e3ab0();
};
struct FUN_006e3c60 : public FUN_006e3ab0
{
    virtual ~FUN_006e3c60();
};
// @fnv 0x006e3c60
FUN_006e3c60::~FUN_006e3c60()
{}

// FUN_006e3f10 (0x006e3f10, 8 bytes): `sub ecx,0x10 ; jmp FUN_006e3a50`
// This is a compiler-generated adjustor thunk: the second base of a multiply
// inherited class sits 0x10 bytes into the object, so the slot inherited from
// that base has to move `this` back to the start of the derived object before
// jumping to the implementation of the overridden virtual.
struct PrimaryBase
{
    virtual void FUN_006e3f10();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_006e3f10();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x006e3f10
    virtual void FUN_006e3f10();
};

Derived::Derived()
{}

void __cdecl operator delete(void*, void*);

// Places a2 instances of FUN_006e2210 into the memory block at a1 by calling the constructor at each offset.
// @fnv 0x006e9700
void FUN_006e9700_Class::ConstructArray(int a1, unsigned int a2)
{
    for (unsigned int i = 0; i < a2; i++)
    {
        new ((FUN_006e2210*)a1 + i) FUN_006e2210;
    }
}

struct FUN_006ec130_Local
{
    FUN_006ec130_Local();
    ~FUN_006ec130_Local();
    int m_iOwnerObjectOffset;
    int m_uiContentCount;
};

struct FUN_006ec130_Base
{
    int m_unk00;
    int m_unk04;
    virtual ~FUN_006ec130_Base();
};

struct FUN_006ec130 : FUN_006ec130_Base
{
    virtual ~FUN_006ec130();
};
// @fnv 0x006eca80
void* FUN_006ec130_Class::FUN_006eca80(unsigned int flags)
{
    reinterpret_cast<::FUN_006ec130 *>(this)->FUN_006ec130::~FUN_006ec130();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// @fnv 0x006ec130
FUN_006ec130::~FUN_006ec130()
{
    FUN_006ec130_Local item;
    while (reinterpret_cast<::FUN_006ec390_Class *>(this)->FUN_006ec390((int)(&item)))
    {
    }
}

struct FUN_006eca20
{
    virtual ~FUN_006eca20();
};
// Empty virtual destructor for the FUN_006eca20 class.
// @fnv 0x006eca20
FUN_006eca20::~FUN_006eca20()
{}

struct Arr2_006e9e20
{
    ~Arr2_006e9e20();
};
struct FUN_006eca50 : Arr2_006e9e20
{
    virtual ~FUN_006eca50();
};
// @fnv 0x006eca50
FUN_006eca50::~FUN_006eca50()
{}

int __cdecl FUN_0043b460(long volatile* a1, long a2, long a3);
struct NodeX
{
    int unk00;
    int unk04;
    NodeX* pNext;
};
struct QueueX
{
    int unk00;
    long volatile lLock;
    NodeX* pHead;
    bool FUN_006ecd60(NodeX** ppOut);
};
// If FUN_006ecd60 succeeds on a1, calls AssignFrom on the object pointed to by a1 with a2 and returns true; otherwise returns false.
// @fnv 0x006ecd00
bool FUN_006ecd60_stub::FUN_006ecd00(void** a1, int aiValue)
{
    if (reinterpret_cast<::QueueX *>(this)->FUN_006ecd60((::NodeX **)(a1)))
    {
        (*(FUN_006ece00_Obj**)a1)->AssignFrom(aiValue);
        return true;
    }
    else
    {
        return false;
    }
}
// Removes and returns the head node from the queue under a spin lock, returning true if a node was found.
// @fnv 0x006ecd60
bool QueueX::FUN_006ecd60(NodeX** ppOut)
{
    bool bResult;
    while (true)
    {
        if (!FUN_0043b460(&lLock, 0, 1))
        {
            FUN_0040fbe0();
            if (pHead)
            {
                *ppOut = pHead;
                pHead = (*ppOut)->pNext;
                (*ppOut)->pNext = 0;
                bResult = true;
            }
            else
            {
                bResult = false;
                *ppOut = 0;
            }
            FUN_0040fbe0();
            FUN_0043b460(&lLock, 1, 0);
            break;
        }
    }
    return bResult;
}

struct FUN_006ecf70
{
    virtual ~FUN_006ecf70();
};
// Empty destructor for FUN_006ecf70.
// @fnv 0x006ecf70
FUN_006ecf70::~FUN_006ecf70()
{}

struct FUN_006f27f0_Class
{
    virtual ~FUN_006f27f0_Class();
};
struct FUN_006f2810 : FUN_006f27f0_Class
{
    const char* m_p;
    ~FUN_006f2810();
};
// @fnv 0x006f3020
void* FUN_006f2810_Class::FUN_006f3020(unsigned int flags)
{
    reinterpret_cast<::FUN_006f2810 *>(this)->FUN_006f2810::~FUN_006f2810();
    if (flags & 1)
        Deallocate(this);
    return this;
}
// Destructor that calls Clear(true) on this, viewed as a GlobalObject_00869f00.
// @fnv 0x006f2810
FUN_006f2810::~FUN_006f2810()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}

struct Base006f2e00
{
    virtual ~Base006f2e00();
};

struct FUN_006f2e40 : Base006f2e00
{
    virtual ~FUN_006f2e40();
};
// @fnv 0x006f30b0
void* FUN_006f2e40_Class::FUN_006f30b0(unsigned int flags)
{
    reinterpret_cast<::FUN_006f2e40 *>(this)->FUN_006f2e40::~FUN_006f2e40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// Destructor that calls FUN_008454f0 with 1.
// @fnv 0x006f2e40
FUN_006f2e40::~FUN_006f2e40()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(1);
}

struct FUN_006f3320_Arr16Helper
{
};

struct FUN_006f3320_Fields
{
    void* m_pBuffer;
    int m_bufferPosition;
    int m_iBufferSize;
};

struct FUN_006f3320_VTable
{
    virtual void FUN_006f3320_Alloc0();
    virtual void* FUN_006f3320_Alloc(int a1);
};

// Zeroes the buffer fields, allocates max(a1, a2) elements, and if a2 is nonzero constructs a2 elements and sets the position to a2.
// @fnv 0x006f3320
void FUN_006f3320_Class::InitBuffer(int a1, int a2)
{
    reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_pBuffer = 0;
    reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_bufferPosition = 0;
    reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_iBufferSize = 0;

    if ((unsigned int)a2 > (unsigned int)a1)
    {
        a1 = a2;
    }

    if ((unsigned int)a1 > 0)
    {
        reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_pBuffer =
            reinterpret_cast<FUN_006f3320_VTable*>(this)->FUN_006f3320_Alloc(a1);
        reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_iBufferSize = a1;
    }

    if ((unsigned int)a2 > 0)
    {
        reinterpret_cast<::C6F3280Allocator *>((reinterpret_cast<FUN_006f3320_Arr16Helper*>(this)))->ConstructBounds(
            (::C6F3280Bound *)(reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_pBuffer), a2);
        reinterpret_cast<FUN_006f3320_Fields*>(reinterpret_cast<char*>(this) + 4)->m_bufferPosition = a2;
    }
}

// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.

class F9940MapBase
{
  public:
    virtual ~F9940MapBase();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_006f9940 : public F9940MapBase
{
  public:
    virtual ~FUN_006f9940();
};

// Destroys the object by calling RemoveAll to clear the hash table entries.
// @fnv 0x006f9940
FUN_006f9940::~FUN_006f9940()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

#include <stdio.h>
namespace fnv_006fc490 {
struct NiNode
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc(NiNode*, bool);
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    NiNode(unsigned short);
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
};
struct Ptr490
{
    NiNode* ptr;
    Ptr490(NiNode*);
    ~Ptr490();
    Ptr490& operator=(NiNode*);
    operator NiNode*() const;
};
struct Member490
{
    unsigned value;
    Member490();
    ~Member490();
};
struct Mem490
{
    int value;
    Mem490(int, bool, const char*, int);
    ~Mem490();
};
struct Source490
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* v130();
};
struct Stream490
{
    virtual ~Stream490();
    Stream490& FUN_006fc950(unsigned&);
    Stream490& ReadFromStream(unsigned short&);
};
struct FileFinder490
{
    static int Exist(const char*, char*, unsigned, unsigned);
};
Stream490* __cdecl FUN_00afdf00(const char*, int, unsigned);
struct FUN_006fc490;
struct TerrainNode490
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    TerrainNode490(FUN_006fc490*, TerrainNode490*, short, short, unsigned, bool);
};
struct Sky490
{
};
struct FUN_006fc490
{
    Source490* source;
    TerrainNode490* root;
    Ptr490 first, second;
    unsigned short value10, value12, value14, value16;
    unsigned value18, value1c, value20, value24;
    bool flag28, flag29;
    Member490 member;
    FUN_006fc490(Source490*);
};
// Constructor: reads Data\LODSettings\<name>.DLODSettings if present, creates a TerrainNode490 root, and sets first/second from DAT_011dea10.
// @fnv 0x006fc490
FUN_006fc490::FUN_006fc490(Source490* apSource) : first(0), second(0)
{
    Mem490 context(
        34, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSTerrainManager.cpp", 47);
    {
        flag29 = false;
        source = apSource;
        char filename[260];
        {
            sprintf(filename, "Data\\LODSettings\\%s.DLODSettings", apSource->v130());
            Stream490* stream = 0;
            if (FileFinder490::Exist(filename, 0, 6, 256))
                stream = FUN_00afdf00(filename, 0, 100);
            if (stream)
            {
                reinterpret_cast<::fnv_006fc950::FUN_006fc950_Class *>(&(stream->FUN_006fc950(value1c)
                    .FUN_006fc950(value18)
                    .FUN_006fc950(value20)
                    .ReadFromStream(value10)
                    .ReadFromStream(value12)
                    .ReadFromStream(value14)
                    .ReadFromStream(value16)))->FUN_006fc950((int)&(value24));
                delete stream;
                root = new TerrainNode490(this, 0, value10, value12, value20, false);
                flag29 = true;
            }
            else
                root = 0;
            first = ((::fnv_006fc490::NiNode *)(reinterpret_cast<::MagicCaster_shell *>(((*reinterpret_cast<::fnv_006fc490::Sky490 * *>(&::g_TES))))->FUN_0044edb0()));
            if ((NiNode*)first)
            {
                second = ((::fnv_006fc490::NiNode *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_006fc490::Sky490 * *>(&::g_TES))))->FUN_00825c00()));
                reinterpret_cast<::FUN_00546780_shell *>((((NiNode*)first)))->FUN_00546780(true);
                reinterpret_cast<::FUN_00546780_shell *>((((::fnv_006fc490::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((NiNode*)first)))->FUN_009611e0()))))->FUN_00546780(true);
            }
            flag28 = false;
            if (!(NiNode*)(*reinterpret_cast<::fnv_006fc490::Ptr490 *>(&::g_011d86a8)) && (NiNode*)first)
            {
                (*reinterpret_cast<::fnv_006fc490::Ptr490 *>(&::g_011d86a8)) = new NiNode(0);
                ((NiNode*)first)->v0dc((*reinterpret_cast<::fnv_006fc490::Ptr490 *>(&::g_011d86a8)), true);
                (*reinterpret_cast<::fnv_006fc490::Ptr490 *>(&::g_011d8690)) = new NiNode(0);
                ((NiNode*)first)->v0dc((*reinterpret_cast<::fnv_006fc490::Ptr490 *>(&::g_011d8690)), true);
            }
        }
    }
}
}  // namespace fnv_006fc490

// Unregisters this object's Steam callback (GalaxyWrp.dll import).
extern "C" __declspec(dllimport) void __cdecl SteamAPI_UnregisterCallback(void* pCallback);

// @fnv 0x006ffc00
void FUN_006ffc00_Class::UnregisterSteamCallback()
{
    SteamAPI_UnregisterCallback(this);
}

namespace fnv_006f3c80 {
struct FUN_00982610
{
    unsigned int m_pTreeNode;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    unsigned int m_uiFirstValue;
    ~FUN_00982610();
};

struct FUN_00483710
{
    unsigned int m_pTreeNode;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    unsigned int m_uiFirstValue;
    ~FUN_00483710();
};

struct EntryTable : FUN_00483710
{
    unsigned int m_entries[2036];
};

struct FUN_006f3c80
{
    FUN_00982610 m_pStreamAllocator;
    EntryTable m_entries;
    FUN_00483710 m_lookup;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
    unsigned int m_uiEdgeIndex;
    unsigned char m_sState;
    virtual ~FUN_006f3c80();
};

// @fnv 0x006f3c80
FUN_006f3c80::~FUN_006f3c80()
{}
}  // namespace fnv_006f3c80

struct PathingRequest
{
    virtual ~PathingRequest();
    PathingRequest();
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
    float unk68;
    float unk6c;
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
public:
    float GetGoalZDelta();
};
// Computes m_kSmoothed for each node in m_kNodeArray using surrounding positions, then adjusts it toward the side offset.
// @fnv 0x006f0450
void SMPPath::SmoothNodes()
{
    for (int i = 0; i < ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kNodeArray))->GetName())); i++)
    {
        SMPPoint kBeforeNew(0.0f, 0.0f, 0.0f);
        unsigned int uiBeforeNext = 0;
        for (int j = -4; j < 0; j++)
        {
            int iIndex = i + j;
            if (iIndex == -1)
            {
                uiBeforeNext++;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(kBeforeNew))->FUN_0063c8a0((void *)&(m_kStartPoint));
            }
            else if (iIndex == ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kNodeArray))->GetName())))
            {
                uiBeforeNext++;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(kBeforeNew))->FUN_0063c8a0((void *)&(m_kEnd));
            }
            else if (iIndex >= 0 && iIndex < ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kNodeArray))->GetName())))
            {
                uiBeforeNext++;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(kBeforeNew))->FUN_0063c8a0((void *)&(m_kNodeArray.FUN_00877a30(iIndex)->m_kPos));
            }
        }
        if (uiBeforeNext)
            reinterpret_cast<::FUN_004941c0_shell *>((void *)&(const ::SMPPoint &)(kBeforeNew))->ScaleByInverse((float)uiBeforeNext);
        else
            kBeforeNew = m_kStartPoint;
        SMPPoint kAfterIn(0.0f, 0.0f, 0.0f);
        unsigned int uiAfter = 0;
        for (int k = 1; k <= 4; k++)
        {
            int iIndex2 = i + k;
            if (iIndex2 == -1)
            {
                uiAfter++;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(kAfterIn))->FUN_0063c8a0((void *)&(m_kStartPoint));
            }
            else if (iIndex2 == ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kNodeArray))->GetName())))
            {
                uiAfter++;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(kAfterIn))->FUN_0063c8a0((void *)&(m_kEnd));
            }
            else if (iIndex2 >= 0 && iIndex2 < ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kNodeArray))->GetName())))
            {
                uiAfter++;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(kAfterIn))->FUN_0063c8a0((void *)&(m_kNodeArray.FUN_00877a30(iIndex2)->m_kPos));
            }
        }
        if (uiAfter)
            reinterpret_cast<::FUN_004941c0_shell *>((void *)&(const ::SMPPoint &)(kAfterIn))->ScaleByInverse((float)uiAfter);
        else
            kAfterIn = m_kEnd;
        m_kNodeArray.FUN_00877a30(i)->m_kSmoothed = FUN_006ba550(
            &m_kNodeArray.FUN_00877a30(i)->m_kLeft, &m_kNodeArray.FUN_00877a30(i)->m_kRight, &kBeforeNew, &kAfterIn);
        if (reinterpret_cast<::NiPoint3 *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_004390c0((const ::NiPoint3 &)(m_kNodeArray.FUN_00877a30(i)->m_kLeft)) ||
            reinterpret_cast<::NiPoint3 *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_004390c0((const ::NiPoint3 &)(m_kNodeArray.FUN_00877a30(i)->m_kRight)))
        {
            SMPPoint kTravel = kAfterIn - kBeforeNew;
            reinterpret_cast<::FUN_004a0c10_s *>(&(kTravel))->FUN_004a0c10();
            SMPPoint kSpan = m_kNodeArray.FUN_00877a30(i)->m_kLeft - m_kNodeArray.FUN_00877a30(i)->m_kRight;
            reinterpret_cast<::FUN_004a0c10_s *>(&(kSpan))->FUN_004a0c10();
            if (i > 0 && FUN_00408840(reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kTravel))->DotProduct((void *)&(kSpan))) > 0.8f)
            {
                float fLeftDistPtr =
                    reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::SMPPoint &)((m_kNodeArray.FUN_00877a30(i)->m_kLeft - m_kNodeArray.FUN_00877a30(i - 1)->m_kSmoothed)))->GetSquaredXYLength();
                float fRightDist =
                    reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::SMPPoint &)((m_kNodeArray.FUN_00877a30(i)->m_kRight - m_kNodeArray.FUN_00877a30(i - 1)->m_kSmoothed)))->GetSquaredXYLength();
                if (fLeftDistPtr < fRightDist)
                    m_kNodeArray.FUN_00877a30(i)->m_kSmoothed =
                        m_kNodeArray.FUN_00877a30(i)->m_kLeft * 0.99f + m_kNodeArray.FUN_00877a30(i)->m_kRight * 0.01f;
                else
                    m_kNodeArray.FUN_00877a30(i)->m_kSmoothed =
                        m_kNodeArray.FUN_00877a30(i)->m_kLeft * 0.01f + m_kNodeArray.FUN_00877a30(i)->m_kRight * 0.99f;
            }
            else if (reinterpret_cast<::NiPoint3 *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_004390c0((const ::NiPoint3 &)(m_kNodeArray.FUN_00877a30(i)->m_kLeft)))
            {
                SMPPoint kToRight = m_kNodeArray.FUN_00877a30(i)->m_kRight - m_kNodeArray.FUN_00877a30(i)->m_kLeft;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_0063c8a0((void *)&(const ::SMPPoint &)(kToRight * 0.01f));
            }
            else if (reinterpret_cast<::NiPoint3 *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_004390c0((const ::NiPoint3 &)(m_kNodeArray.FUN_00877a30(i)->m_kRight)))
            {
                SMPPoint kToLeft = m_kNodeArray.FUN_00877a30(i)->m_kLeft - m_kNodeArray.FUN_00877a30(i)->m_kRight;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_0063c8a0((void *)&(const ::SMPPoint &)(kToLeft * 0.01f));
            }
        }
        float fSideOffset = reinterpret_cast<::PathingRequest *>((m_pkSide))->GetGoalZDelta();
        SMPPoint kOffsetVal = fSideOffset > 0.0
                                  ? m_kNodeArray.FUN_00877a30(i)->m_kRight - m_kNodeArray.FUN_00877a30(i)->m_kSmoothed
                                  : m_kNodeArray.FUN_00877a30(i)->m_kLeft - m_kNodeArray.FUN_00877a30(i)->m_kSmoothed;
        fSideOffset = FUN_00408840(fSideOffset);
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::SMPPoint &)(m_kNodeArray.FUN_00877a30(i)->m_kSmoothed))->FUN_0063c8a0((void *)&(const ::SMPPoint &)(fSideOffset * 0.5f * kOffsetVal));
    }
}
struct PtB006815c0
{
    float x, y, z;
    PtB006815c0();
};
struct FUN_006e4080 : PathingRequest
{
    PtB006815c0 pointb0;
    float unkbc, unkc0, unkc4;
    int unkc8;
    bool unkcc, unkcd, unkce, unkcf, unkd0, unkd1;
    PtB006815c0 pointd4, pointe0;
    FUN_006e4080();
    virtual ~FUN_006e4080();
};
// Constructor: sets unk68, unk6c, unkbc, unkc0, unkc4 from globals, unkc8 to 50, unkcc to true, the other flags to false, and two points to zero.
// @fnv 0x006e4080
FUN_006e4080::FUN_006e4080()
{
    unk68 = DAT_0104e0e8;
    unk6c = ::DAT_0101e704;
    unkc0 = DAT_0101e6ec;
    unkbc = ::DAT_010236e0;
    unkc4 = DAT_0106b158;
    unkc8 = 50;
    unkcc = true;
    unkcd = false;
    unkce = false;
    unkcf = false;
    unkd0 = false;
    unkd1 = false;
    pointd4 = *(PtB006815c0*)&::NiPoint3::ZERO;
    pointe0 = *(PtB006815c0*)&::NiPoint3::ZERO;
}

struct QueueDeletingView : public FUN_006ec1e0_Class
{
    void* FUN_006ec230(unsigned int flags);
};

// @fnv 0x006ec230
void* QueueDeletingView::FUN_006ec230(unsigned int flags)
{
    FUN_006ec1e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

#include "generated/data/staging/blk_006e0000_od.inc"
