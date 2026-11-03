
// src/fallout_shared/tesobjectrefr_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/tesobjectrefr_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tesobjectrefr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectrefr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/C68CB0World.h"
#include "fnv/decl/C8F670Object.h"
#include "fnv/decl/Entity_c8ea.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0041fbe0_shell.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004523c0_shell.h"
#include "fnv/decl/FUN_00452440_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458990_Holder.h"
#include "fnv/decl/FUN_004589c0_cls.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/decl/FUN_00564c60_cls.h"
#include "fnv/decl/FUN_0056c880_S.h"
#include "fnv/decl/FUN_0056d230_Class.h"
#include "fnv/decl/FUN_0056d2c0_cls.h"
#include "fnv/decl/FUN_0056d300_S.h"
#include "fnv/decl/FUN_0056d360_Class.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0086a830_S.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FUN_00c6b980_cls.h"
#include "fnv/decl/FUN_00c84df0_cls.h"
#include "fnv/decl/FUN_00c87600_Obj.h"
#include "fnv/decl/FUN_00c878c0_cls.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/FUN_00cb2ff0.h"
#include "fnv/decl/HavokFilterInfo.h"
#include "fnv/decl/Holder4523e0.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/Ref56D.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S00458900_Vector.h"
#include "fnv/decl/S00458a10_Vector.h"
#include "fnv/decl/S00458ad0_Vector.h"
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_00c85c10.h"
#include "fnv/decl/ShapeViewerFields.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WaterRef.h"
#include "fnv/decl/WorldC944.h"
#include "fnv/decl/bhkViewerObject.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_005617c0__FUN_005617c0_.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/s56eab0__Actor.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_00561000.h"
#include "fnv/symbols_00564000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00575000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_0057a000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c81000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c9f000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011b1000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "tesobjectrefr_decls.h"
void* FUN_0056a8c0();
struct FUN_00c9c240_holder
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00c9c240();
    void FUN_00c9d600();
};
extern int DAT_0126822c;
extern int DAT_01268238;
struct bhkRefObject
{
    void* vtbl;
    int f4;
    int f8;
    int fc;
    int f10;
    unsigned char f14;
};
struct FUN_0056e2d0
{
    virtual ~FUN_0056e2d0();
};
extern const void* vftable_FUN_0056e2d0;
struct FUN_00c6d190 : bhkRefObject
{
    FUN_00c6d190();
};
struct ProjectileListener
{
    void* vfptr;
    int m4;
    int m8;
    void FUN_00c876a0();
};
struct hkReferencedObject
{
};
struct FUN_00c9d4c0_holder
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00c9d4c0();
    void FUN_00c9d600();
};
struct CollisionEntity;
struct CallRet
{
public:
    void FUN_00c946e0(::CollisionEntity *, int, int);
};
struct Holder00c9d5d0
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual CallRet* GetRet();
    void* unk4;
    void* unk8;
    void FUN_00c9d5d0();
};
extern int DAT_01268238;
struct FUN_00c876a0_holder
{
    virtual ~FUN_00c876a0_holder();
};
struct bhkWorldObject
{
    void FUN_00c85790();
};
struct FUN_00c9f3b0 : FUN_00c876a0_holder
{
    virtual ~FUN_00c9f3b0();
};
struct WorldHolder
{
};
struct PhantomBase
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
};
struct bhkAabbPhantom : PhantomBase
{
    virtual WorldHolder* GetWorld();
    int m4;
    void* m8;
    void FUN_00c9f460();
};
struct InnerS
{
    char pad[16];
    float f10;
};
struct MyObj
{
    char pad[8];
    InnerS* p8;
};
struct OutS
{
    int i0;
    float f4;
};
struct ArgB
{
    char _0[16];
    float f10;
};
struct RetV
{
    char _0[4];
    float f4;
};
struct bhkSphereShape
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual RetV* Target(char* p);
    void FUN_00ca0740(void* a, ArgB* b);
};
struct S_00cb3070
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
    virtual void v43b();
    virtual void v44(int*);
    void FUN_00cb3070(int);
};
struct MM
{
    void* FUN_00cb30a0(unsigned int);
};
struct FUN_00c9d620_holder : FUN_00c876a0_holder
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00c9d620_holder();
    ~FUN_00c9d620_holder();
};
struct FUN_0056e780_Class
{
    virtual ~FUN_0056e780_Class();
    void FUN_00ca0540();
};
struct FUN_00c9fb00 : FUN_0056e780_Class
{
    virtual ~FUN_00c9fb00();
};
extern void* DAT_0103093c;
struct FUN_00c9fde0 : bhkRefObject
{
    FUN_00c9fde0();
};
struct A51BF0Base
{
};
extern int DAT_01030864;
struct S_00cb79d0_Base
{
    void* vtbl;
    char pad[8];
    int f0c;
    int f10;
    unsigned char f14;

    S_00cb79d0_Base();
};
struct Object_00c9f5a0 : S_00cb79d0_Base, A51BF0Base
{
    Object_00c9f5a0() : S_00cb79d0_Base()
    {
        vtbl = (void*)&(*reinterpret_cast<const void * *>(&::DAT_01030394));
        f0c = 0;
        f10 = 0;
        ++DAT_0126810c;
        vtbl = (void*)&(*reinterpret_cast<const void * *>(&::DAT_0103078c));
        ++DAT_01268238;
        vtbl = (void*)&DAT_01030864;
        ++DAT_01268244;
        f14 = 0;
    }
};
struct FUN_00c877b0
{
    virtual ~FUN_00c877b0();
};
struct FUN_00c84c50 : FUN_00c877b0
{
    virtual ~FUN_00c84c50();
};
class FUN_00c85790_base
{
  public:
    virtual void unk00();
    ~FUN_00c85790_base();
    int unk04;
};
class FUN_00c85790 : public FUN_00c85790_base
{
  public:
    virtual ~FUN_00c85790();
    void unk08();
};
struct CollisionObject;
struct CollisionResult
{
    unsigned short kind;
    unsigned short enabled;
    struct CollisionRecord* record;
    unsigned int data08;
    unsigned int data0c;
    unsigned int state;
};
struct CollisionValue
{
    unsigned int data00;
    unsigned int data04;
    CollisionRecord* record;
};
struct CollisionRecord
{
    unsigned int data00;
    unsigned int data04;
    struct CollisionHandler* handler;
};
struct CollisionHandler
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
    virtual CollisionValue* Find(int target);
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
    virtual bool IsAllowed(int target);
};
struct ScopedMode
{
    unsigned int oldValue;
    ScopedMode() : oldValue(::currentAllocationContext)
    {
        ::currentAllocationContext = 0x10;
    }
    ~ScopedMode()
    {
        ::currentAllocationContext = oldValue;
    }
};
struct WorldObjectView
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
    virtual CollisionResult* GetResult(unsigned char* used);
    void FUN_00c85900(int a, int b);
};
struct NiRTTI
{
    const char* m_pcName;
};
struct NiObject
{
    virtual void v00();
    virtual void v01();
    virtual const NiRTTI* GetRTTI();
};
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    void* vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int Add(T element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > DebugStrArray;
struct hkShapeStub
{
    void* vtbl;
    int unk04;
    NiObject* userData;
};
struct hkCdBodyStub
{
    hkShapeStub* m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct hkObjHead
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
};
struct hkWorldObjStub : hkObjHead, hkCdBodyStub
{
};
struct DebugHelper_c849b0
{
    int value;
    DebugHelper_c849b0(int v) : value(v)
    {}
};
struct HeapContextGuard
{
    int saved;
    HeapContextGuard(int ctx)
    {
        saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = ctx;
    }
    ~HeapContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = saved;
    }
};
struct bhkBase_c878c0
{
    void* vtbl;
    int unk04;
    hkWorldObjStub* m_pObject;
    hkCdBodyStub* GetBody()
    {
        return m_pObject;
    }
};
struct bhkWorldObject_c86190 : bhkBase_c878c0
{
    void FUN_00c86190(DebugStrArray* arr);
};
class FUN_00c8bed0_base_cls
{
  public:
    virtual void unk00();
    ~FUN_00c8bed0_base_cls();
    int unk04;
};
class FUN_00c8bed0_cls : public FUN_00c8bed0_base_cls
{
  public:
    virtual ~FUN_00c8bed0_cls();
    void unk08();
};
struct FUN_00c9eb30 : FUN_00c9f3b0
{
    virtual ~FUN_00c9eb30();
};
struct TlsBlock_t
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
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
struct FUN_00c9efa0_cls
{
    bhkRefObject* FUN_00c9efa0(unsigned int flag);
};
struct S_00c9f1e0_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct S_00c9f1e0_Elem
{
    S_00c9f1e0_Shape* shape;
};
struct S_00c9f1e0_Base1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c9f1e0_Base2
{
    S_00c9f1e0_Shape* shape;
};
struct S_00c9f1e0_Range
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int begin;
    int end;
};
struct S_00c9f1e0_World;
typedef void(__cdecl* S_00c9f1e0_Fn)(S_00c9f1e0_Base2*, S_00c9f1e0_Elem*, S_00c9f1e0_World*, S_00c9f1e0_Range*);
struct S_00c9f1e0_Entry
{
    S_00c9f1e0_Fn fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_00c9f1e0_Disp
{
    unsigned char types[77][32];
    int unk9a0;
    int unk9a4;
    S_00c9f1e0_Entry funcs[32];
};
struct S_00c9f1e0_World
{
    S_00c9f1e0_Disp* disp;
};
struct S_00c9f1e0_Holder
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
    S_00c9f1e0_World* world;
};
struct S_00c9f1e0_Ctx : S_00c9f1e0_Base1, S_00c9f1e0_Base2
{
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00c9f1e0_Elem** items;
    int count;
};
struct S_00c9f1e0_Obj
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
    virtual S_00c9f1e0_Holder* GetWorld();
    int unk04;
    S_00c9f1e0_Ctx* ctx;
    void FUN_00c9f1e0(S_00c9f1e0_Range* r);
};
class C9F270MemContext
{
  public:
    C9F270MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~C9F270MemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious;
    }

    int m_iPrevious;
};
class C9F270StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcValue));
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class C9F270Object
{
  public:
    void FUN_00c9f270(C9F270StrArray* pkStrings);
};
__declspec(thread) int tlsMode = 0x3b;
struct ReleaseObject
{
};
struct FUN_00c9f320_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00c9f320(char release);
};
struct TlsGuard
{
    int previous;
    TlsGuard()
    {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~TlsGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};
struct PhysicsAction
{
};
struct LinkedObject
{
    PhysicsAction* GetAction() const
    {
        return *reinterpret_cast<PhysicsAction* const*>(reinterpret_cast<const char*>(this) + 0x350);
    }
};
struct FUN_00c9f420_Class
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual LinkedObject* ResolveLinkedObject();
    int unk4;
    void* handle;
    bool FUN_00c9f420();
};
struct ProjectileCreator
{
    Object_00c9f5a0* FUN_00c9f640(int mode);
};
struct TLSBlock
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int value;
};
__declspec(thread) TLSBlock g_tls;
struct ThreadFlagGuard
{
    int previous;
    ThreadFlagGuard()
    {
        previous = (*reinterpret_cast<::TLSBlock *>(&::g_tlsBlock)).value;
        (*reinterpret_cast<::TLSBlock *>(&::g_tlsBlock)).value = 16;
    }
    ~ThreadFlagGuard()
    {
        (*reinterpret_cast<::TLSBlock *>(&::g_tlsBlock)).value = previous;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* Allocate(unsigned int);
};
struct Pool
{
    int unk0, unk4, unk8, unkc;
    Allocator* allocator;
};
extern "C" Pool* __cdecl FUN_00c85750();
struct FUN_00cf2cb0
{
    int unk0;
    unsigned short length;
    static void* operator new(std::size_t count)
    {
        Pool* pool = FUN_00c85750();
        FUN_00cf2cb0* p = (FUN_00cf2cb0*)pool->allocator->Allocate(224);
        p->length = 224;
        return p;
    }
    static void operator delete(void*, std::size_t);
    FUN_00cf2cb0(void* contents, int tag);
};
struct Input
{
    int tag;
    int unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    int payload;
};
struct Receiver
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
    virtual void v9();
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
    virtual void dispatch(void*);
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
    virtual void finish(void*);
    void FUN_00c9f890(Input* input);
};
struct BC9F970AllocTagScope
{
    int m_iSaved;

    BC9F970AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BC9F970AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
class BC9F970StringArray
{
  public:
    virtual ~BC9F970StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class FUN_00c9f970_cls
{
  public:
    void FUN_00c9f480(BC9F970StringArray* pkArray);
    void FUN_00c9f970(BC9F970StringArray* pkArray);
};
struct MemContextTLS
{
    int unk2b4;
};
struct MemContextGuard
{
    int iOld;
    MemContextGuard()
    {
        iOld = (*reinterpret_cast<::MemContextTLS *>(&::currentAllocationContext)).unk2b4;
        (*reinterpret_cast<::MemContextTLS *>(&::currentAllocationContext)).unk2b4 = 0x10;
    }
    ~MemContextGuard()
    {
        (*reinterpret_cast<::MemContextTLS *>(&::currentAllocationContext)).unk2b4 = iOld;
    }
};
struct ViewerStringArray
{
    char** m_pBase;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
};
struct ViewerRTTI
{
    const char* m_pcName;
};
extern float DAT_011b15c0;
struct SphereHkShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float fRadius;
};
struct SphereShapeBase
{
    void* vtbl;
    int unk04;
};
struct SphereShape : SphereShapeBase
{
    SphereHkShape* pHkShape;
    float GetRadius()
    {
        return (this && pHkShape) ? pHkShape->fRadius : DAT_010c72bc;
    }
    void FUN_00c9fc50(ViewerStringArray* apViewerStrings);
};
class FUN_00c9fd70_cls : public FUN_00c9fb00
{
  public:
    virtual ~FUN_00c9fd70_cls();
};
struct SphereScaleFields
{
    unsigned int m_00, m_04, m_08, m_0c;
    float m_10, m_14, m_18, m_1c;
};
struct SphereScalingMethod : bhkSphereShape
{
    void FUN_00c9fea0(void* first, ArgB* second);
};
struct Tls_ca0090
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern int DAT_0126fd98;
struct TlsGuard_ca0090
{
    unsigned int m_saved;
    TlsGuard_ca0090()
    {
        m_saved = (*reinterpret_cast<::Tls_ca0090 *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::Tls_ca0090 *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_ca0090()
    {
        (*reinterpret_cast<::Tls_ca0090 *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};
struct MemMgr_ca0090
{
};
struct Sub_ca0090
{
};
struct FUN_00ca0090_cls
{
    unsigned int unk00;
    unsigned int unk04;
    void* m08;
    void* m0C;
    void* FUN_00ca0090(unsigned char* out);
};
class CA0540Base
{
  public:
    virtual ~CA0540Base();

};
class FUN_00ca0540 : public CA0540Base
{
  public:
    virtual ~FUN_00ca0540();

};
struct BCA05B0AllocTagScope
{
    int m_iSaved;

    BCA05B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCA05B0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
class BCA05B0StringArray
{
  public:
    virtual ~BCA05B0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class FUN_00ca05b0_cls
{
  public:
    void FUN_00ca05b0(BCA05B0StringArray* pkArray);
};
class FUN_00ca0660_base
{
  public:
    virtual void unk00();
    ~FUN_00ca0660_base();
    int unk04;
};
class FUN_00ca0660 : public FUN_00ca0660_base
{
  public:
    virtual ~FUN_00ca0660();
    void unk08();
};
class CA0840Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
class CA0840MemContext
{
  public:
    CA0840MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~CA0840MemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious;
    }

    int m_iPrevious;
};
class CA0840Output
{
  public:
    CA0840Output() : m_pkTarget(0), m_fValue(DAT_010c72bc)
    {}


    void* m_pkTarget;
    float m_fValue;
};
class CA0840Constraint
{
  public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    CA0840Output* m_pkOutput;

    CA0840Output* FUN_00ca0840(bool* pbCreated);
};
class CAACF0Base
{
  public:
    virtual ~CAACF0Base();

};
class FUN_00caacf0 : public CAACF0Base
{
  public:
    virtual ~FUN_00caacf0();

};
void* FUN_00cb3060();
class CC2350Base
{
  public:
    virtual ~CC2350Base();
};
class FUN_00cc2350 : public CC2350Base
{
  public:

    virtual ~FUN_00cc2350();
};
struct FUN_00cca8d0 : FUN_00c9fb00
{
    virtual ~FUN_00cca8d0();
};
struct FUN_00ccd080 : FUN_00c9fb00
{
    int unk04;
    virtual ~FUN_00ccd080();
};
struct FUN_00ccdbc0 : FUN_00c9fb00
{
    virtual ~FUN_00ccdbc0();
};
class CCE900Base
{
  public:
    virtual ~CCE900Base();
};
class FUN_00cce900 : public CCE900Base
{
  public:

    virtual ~FUN_00cce900();
};
struct FUN_00ccf4f0_cls : FUN_00c9fb00
{
    int unk04;
    virtual ~FUN_00ccf4f0_cls();
};
class FUN_00ccf740_cls : public FUN_00c9fb00
{
  public:
    virtual ~FUN_00ccf740_cls();
};
class NiObjectC9E
{
  public:

    virtual ~NiObjectC9E();
};
class NiControllerC9E : public NiObjectC9E
{
  public:
    NiControllerC9E();

    static NiObjectC9E* FUN_00c9ef30();

    unsigned int m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

#include <xmmintrin.h>
class S00560c20_Value
{
  public:
    S00560c20_Value();  // FUN_006240d0
    __m128 m_vComponents;
};

class S00560c20_Target;

class S00560c20_Object
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual const S00560c20_Value* vfD8(S00560c20_Value* pOut);
    void FUN_00560c20(S00560c20_Target* pTarget);
};

// @fnv 0x00560c20
void S00560c20_Object::FUN_00560c20(S00560c20_Target* pTarget)
{
    S00560c20_Value kValue;
    ::CopyModifierSettings((::Modifier *)(pTarget), (::FUN_00560d10_shell *)(vfD8(&kValue)));
}

class S00561150_Value
{
  public:
    S00561150_Value();  // FUN_006240d0
    __m128 m_vComponents;
};

class S00561150_Source;

class S00561150_Object
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0(const S00561150_Value* pValue);
    void FUN_00561150(const S00561150_Source* pSource);
};

// @fnv 0x00561150
void S00561150_Object::FUN_00561150(const S00561150_Source* pSource)
{
    S00561150_Value kValue;
    ::FUN_00561500((::bhkCharacterController *)(::S00561150_Value *)(&kValue), (void *)(pSource));
    reinterpret_cast<::FUN_005611c0_t *>(&(kValue))->FUN_005611c0();
    vfE0(&kValue);
}

struct S005611e0_Vector
{
    __m128 m_vComponents;
      // inverse length, as a vector
      // broadcast x
    void FUN_005611e0();                                           // normalize3
};

struct S00561240_Vector
{
    __m128 m_vComponents;
    S00561240_Vector* FUN_00561240(S00561240_Vector* pOut) const;  // broadcast x
};

// @fnv 0x00561240
S00561240_Vector* S00561240_Vector::FUN_00561240(S00561240_Vector* pOut) const
{
    pOut->m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
    return pOut;
}

typedef __m128 hkQuadReal;

class hkSimdRealX
{
  public:
    hkQuadReal m_vValue;
};

class hkVector4X
{
  public:
    hkQuadReal m_vComponents;
    hkSimdRealX dot3(const hkVector4X& a) const;
    hkSimdRealX* FUN_005612a0(hkSimdRealX* out) const;
};
// @fnv 0x005611e0
void S005611e0_Vector::FUN_005611e0()
{
    S005611e0_Vector kScale;
    S005611e0_Vector kInvLength;
    reinterpret_cast<::S00561240_Vector *>((void *)(((::S005611e0_Vector *)(reinterpret_cast<::hkVector4X *>((void *)this)->FUN_005612a0((::hkSimdRealX *)(::S005611e0_Vector *)(&kInvLength))))))->FUN_00561240((::S00561240_Vector *)(::S005611e0_Vector *)(&kScale));
    m_vComponents = _mm_mul_ps(kScale.m_vComponents, m_vComponents);
}

// @fnv 0x005612a0
hkSimdRealX* hkVector4X::FUN_005612a0(hkSimdRealX* out) const
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = (*(const ::__m128 *)(new ((void *)&(dot3(*this))) ::Vec3()));
    const hkQuadReal equalsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal e = _mm_rsqrt_ss(len2);
    const hkQuadReal r = _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    new ((void *)(out)) ::FUN_004a3c90((const ::FUN_004a3c90 &)((const ::__m128 &)(_mm_andnot_ps(equalsZero, r))));
    return out;
}

class S00561440_SimdReal
{
  public:
    S00561440_SimdReal(const __m128& q);  // FUN_004a3c90
    __m128 m_vValue;
};

class S00561440_Vector
{
  public:
    S00561440_SimdReal FUN_00561440(const S00561440_Vector& v) const;  // dot4
    __m128 m_vComponents;
};

// @fnv 0x00561440
S00561440_SimdReal S00561440_Vector::FUN_00561440(const S00561440_Vector& v) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    __m128 sum = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
    __m128 swapped = _mm_shuffle_ps(sum, sum, 0xb1);
    return S00561440_SimdReal(_mm_add_ps(sum, swapped));
}

struct AlignedLocal5615
{
    __m128 m_v;
    AlignedLocal5615();
};
struct Owner5615
{
    void FUN_005615d0(int value);
};
// @fnv 0x005615d0
void Owner5615::FUN_005615d0(int value)
{
    AlignedLocal5615 local;
    reinterpret_cast<::S *>(this)->FUN_00561690((std::intptr_t)(((void *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&local)), (*(const ::fnv_004a3e00::NiPoint3 *)(value)))))));
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct __declspec(align(16)) HKVector4
{
    __m128 m_vComponents;
    HKVector4();
};


class bhkCharacterController
{
  public:
    void FUN_00561630(const NiPoint3& param_1);
};

// @fnv 0x00561630
void bhkCharacterController::FUN_00561630(const NiPoint3& param_1)
{
    HKVector4 local;
    reinterpret_cast<::fnv_005617c0::FUN_005617c0_ *>(this)->FUN_005617c0((std::intptr_t)(((void *)(::CopyCharacterControllerVector((::bhkCharacterController *)(void *)(&local), param_1)))));
}

class S00561730_Comparison
{
  public:
      // allAreSet
    __m128 m_uiMask;
};

class S00561730_Vector
{
  public:
    S00561730_Vector();                                                       // FUN_006815c0
      // setSub4
                                 // setAbs4
    S00561730_Comparison FUN_00458a60(const S00561730_Vector* v) const;  // compareLessThan4
    bool FUN_00561730(const S00561730_Vector* v, float epsilon) const;   // equals4
    __m128 m_vComponents;
};

// @fnv 0x00561730
bool S00561730_Vector::FUN_00561730(const S00561730_Vector* v, float epsilon) const
{
    S00561730_Vector kDiff;
    reinterpret_cast<::S00458a10_Vector *>(&(kDiff))->FUN_00458a10((const ::S00458a10_Vector *)(const ::S00561730_Vector *)(this), (const ::S00458a10_Vector *)(v));
    reinterpret_cast<::S00458ad0_Vector *>(&(kDiff))->FUN_00458ad0((const ::S00458ad0_Vector *)(const ::S00561730_Vector *)(&kDiff));
    S00561730_Vector kEpsilon;
    reinterpret_cast<::FUN_004589c0_cls *>(&(kEpsilon))->FUN_004589c0(epsilon);
    return ((bool)(reinterpret_cast<::FUN_00458990_Holder *>((void *)(void *)&(const ::S00561730_Comparison &)(kDiff.FUN_00458a60(&kEpsilon)))->FUN_00458990(0xf)));
}

class S005620e0_Vector
{
  public:
    S005620e0_Vector();  // FUN_006815c0
    __m128 m_vComponents;
};

class S005620e0_Source;

class S005620e0_Object
{
  public:
    void FUN_00c6e390(const S005620e0_Vector* pValue);
    void FUN_005620e0(const S005620e0_Source* pSource);
};

// @fnv 0x005620e0
void S005620e0_Object::FUN_005620e0(const S005620e0_Source* pSource)
{
    S005620e0_Vector kValue;
    FUN_00c6e390(((const ::S005620e0_Vector *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kValue)), (*(const ::fnv_004a3e00::NiPoint3 *)(pSource))))));
}

class S0056e810_Vector
{
  public:
    __m128 m_vComponents;
};

class S0056e810_Quaternion
{
  public:
      // set from vector
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};

class __declspec(align(16)) S0056e810_Rotation
{
  public:
    S0056e810_Rotation();  // FUN_0056e860
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S0056e810_Quaternion m_kQuat;
};

class S0056e810_Object
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0(const S0056e810_Rotation* pRotation);
    void FUN_0056e810(const S0056e810_Vector& v);
};

// @fnv 0x0056e810
void S0056e810_Object::FUN_0056e810(const S0056e810_Vector& v)
{
    S0056e810_Rotation kRotationBasis;
    reinterpret_cast<::S004b4db0_Quaternion *>(&(kRotationBasis.m_kQuat))->FUN_004b4db0((const ::S004b4db0_Vector4 &)(v));
    vfB0(&kRotationBasis);
}

class NiPoint3F14
{
  public:
    NiPoint3F14();
    float x;
    float y;
    float z;
};

class NiMatrix3F14
{
  public:
    NiMatrix3F14();
    float m_afEntries[3][3];
};

class NiTransformF14
{
  public:
    NiTransformF14();
    NiMatrix3F14 m_kOrientation;
    NiPoint3F14 m_kTranslation;
    float m_fScale;
};

class NiColorF14
{
  public:
    NiColorF14(float fR, unsigned int uiG, unsigned int uiB);
    float r;
    float g;
    float b;
};

class hkVector4F14
{
  public:
    hkVector4F14();
    __m128 m_vComponents;
};

class hkQuaternionF14
{
  public:
    hkQuaternionF14();
    __m128 m_vec;
};

class hkMotionStateF14
{
  public:
    hkMotionStateF14();
    __m128 m_data[4];
};


class SceneNodeF14
{
  public:
};

class OwnerF14
{
  public:
    NiPoint3F14 GetNavMeshData();
};

class OwnerRootF14
{
  public:
};

class SystemF14
{
  public:
};

class SystemSrcF14
{
  public:
};


class ShapeF14
{
  public:
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pv);
    ShapeF14(const hkVector4F14& m_kPoint2, float fRadius);
    char m_acData[0x30];
};

class MaterialF14
{
  public:
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pv);
    MaterialF14();
    char m_acData[0x10];
};

class WrapperF14
{
  public:
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pv);
    WrapperF14(ShapeF14* pkShape, MaterialF14* pkMaterial);
    char m_acData[0x1c];
};

class BodyInfoF14
{
  public:
    BodyInfoF14();
    ~BodyInfoF14();
    unsigned int m_uiFilterInfo;
    WrapperF14* m_pkShape;
    __m128 m_akData[13];
};

class NiMemObjectF14
{
  public:
};

class BodyF14 : public NiMemObjectF14
{
  public:
    BodyF14(const BodyInfoF14& kInfo);
    void Attach(SceneNodeF14* pkNode, int iFlags);
    char m_acData[0x1c];
};

class BodyWrapF14 : public NiMemObjectF14
{
  public:
    BodyWrapF14(SceneNodeF14* pkNode);
    char m_acData[0x14];
};

class CtlrF14 : public NiMemObjectF14
{
  public:
    CtlrF14();
    char m_acData[0x10];
};

class P107RefF14
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual SceneNodeF14* Get3D();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const NiPoint3F14* GetPos();
    NiMatrix3F14 GetRotationMatrix();
    void FUN_0056f140();
};

// @fnv 0x0056f140
void P107RefF14::FUN_0056f140()
{
    OwnerF14* pkOwner = ((::OwnerF14 *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::OwnerRootF14 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041fbe0()));
    SystemF14* pkSystem = ((::SystemSrcF14 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) ? ((::SystemF14 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::SystemSrcF14 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) : 0;
    if (pkSystem)
    {
        ShapeF14* pkShape = 0;
        hkMotionStateF14 kMotion;
        hkVector4F14 m_kPoint2;
        reinterpret_cast<::fnv_00567490::ScaleReference *>(this)->FUN_00567490(1.0f);
        reinterpret_cast<::FUN_00440490_shell *>((Get3D()))->FUN_00440490(1.0f);
        NiColorF14 kColor(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((Get3D()))->FUN_00a59c60((int)&(kColor));
        NiTransformF14 kXform;
        kXform.m_kOrientation = GetRotationMatrix();
        kXform.m_kTranslation = *GetPos();
        kXform.m_fScale = 1.0f;
        const int iLayer = 0x15;
        ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(m_kPoint2), (const ::fnv_004a3e00::NiPoint3 &)((const ::NiPoint3F14 &)(pkOwner->GetNavMeshData())));
        pkShape = new ShapeF14(m_kPoint2, ::DAT_011b153c);
        MaterialF14* pkMaterial = new MaterialF14();
        WrapperF14* pkWrapper = new WrapperF14(pkShape, pkMaterial);
        BodyInfoF14 kInfo;
        kInfo.m_pkShape = pkWrapper;
        reinterpret_cast<::FUN_0056d360_Class *>(&(kInfo))->FUN_0056d360(5);
        hkVector4F14 kPos;
        hkVector4F14 kRot;
        hkQuaternionF14 kQuat;
        reinterpret_cast<::FUN_0056d230_Class *>((Get3D()))->FUN_0056d230((::FUN_00a6df40_Obj *)&(kRot));
        ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kPos), (const ::fnv_004a3e00::NiPoint3 &)(*GetPos()));
        ::FUN_00561500((::bhkCharacterController *)&(kQuat), (void *)&(kRot));
        reinterpret_cast<::FUN_0056d300_S *>(&(kInfo))->FUN_0056d300((const void *)&(kPos));
        reinterpret_cast<::S3e60 *>(&(kInfo))->FUN_0056d320((unsigned int)&(kQuat));
        unsigned int uiFilterInfo = 0x50000;
        uiFilterInfo |= iLayer;
        kInfo.m_uiFilterInfo = uiFilterInfo;
        BodyF14* pkBody = new BodyF14(kInfo);
        BodyWrapF14* pkWrap = new BodyWrapF14(Get3D());
        CtlrF14* pkCtlr = new CtlrF14();
        reinterpret_cast<::BSXFlags_shell *>((pkCtlr))->FUN_00519230(2, 1);
        reinterpret_cast<::FUN_00a5bca0_shell *>((Get3D()))->SetExtraDataName((::NiExtraData *)(pkCtlr));
        reinterpret_cast<::FUN_00c6b980_cls *>((pkWrap))->FUN_00c6b980((::World_c6b *)(pkBody));
        reinterpret_cast<::S_00c85c10 *>((pkBody))->FUN_00c85c10((int *)(::SceneNodeF14 *)(Get3D()), (int *)(0));
        reinterpret_cast<::FUN_0056d2c0_cls *>((pkSystem))->FUN_0056d2c0((::Arg56d2c0 *)(pkBody));
    }
}

class NiPoint3Q
{
  public:
    float x, y, z;
    NiPoint3Q operator*(float fScalar) const;
};

class hkVector4Q
{
  public:
    hkVector4Q(const hkVector4Q& v);
    __m128 m_vComponents;
};

class TESFormQ
{
  public:
    int GetFormType();
};

class NiAVObjectQ
{
  public:
    virtual void vn000();
    virtual void vn004();
    virtual void vn008();
    virtual void* GetName();
};

class NodeQ
{
  public:
};

class ProjectileStateQ
{
  public:
    virtual void vs000();
    virtual void vs004();
    virtual void vs008();
    virtual void vs00c();
    virtual void vs010();
    virtual void vs014();
    virtual void vs018();
    virtual void vs01c();
    virtual void vs020();
    virtual void vs024();
    virtual void vs028();
    virtual void vs02c();
    virtual void vs030();
    virtual void vs034();
    virtual void vs038();
    virtual void vs03c();
    virtual void vs040();
    virtual void vs044();
    virtual void vs048();
    virtual void vs04c();
    virtual void vs050();
    virtual void vs054();
    virtual void vs058();
    virtual void vs05c();
    virtual void vs060();
    virtual void vs064();
    virtual void vs068();
    virtual void vs06c();
    virtual void vs070();
    virtual void vs074();
    virtual void vs078();
    virtual void vs07c();
    virtual void vs080();
    virtual void vs084();
    virtual void vs088();
    virtual void vs08c();
    virtual void vs090();
    virtual int GetID();
};

class ControllerQ
{
  public:
    virtual void vc000();
    virtual void vc004();
    virtual void vc008();
    virtual void vc00c();
    virtual void vc010();
    virtual void vc014();
    virtual void vc018();
    virtual void vc01c();
    virtual void vc020();
    virtual void vc024();
    virtual void vc028();
    virtual void vc02c();
    virtual void vc030();
    virtual void vc034();
    virtual void vc038();
    virtual void vc03c();
    virtual void vc040();
    virtual void vc044();
    virtual void vc048();
    virtual void vc04c();
    virtual void vc050();
    virtual void vc054();
    virtual void vc058();
    virtual void vc05c();
    virtual void vc060();
    virtual void vc064();
    virtual void vc068();
    virtual void vc06c();
    virtual void vc070();
    virtual void vc074();
    virtual void vc078();
    virtual void vc07c();
    virtual void vc080();
    virtual void vc084();
    virtual void vc088();
    virtual void vc08c();
    virtual void vc090();
    virtual int GetID();
    virtual void vd098();
    virtual void vd09c();
    virtual void vd0a0();
    virtual void vd0a4();
    virtual void vd0a8();
    virtual void vd0ac();
    virtual void vd0b0();
    virtual void vd0b4();
    virtual void vd0b8();
    virtual void vd0bc();
    virtual void vd0c0();
    virtual void vd0c4();
    virtual void vd0c8();
    virtual void vd0cc();
    virtual void Detach(NiAVObjectQ* pkRoot, int a, int b, int c, int d);
    virtual void Attach(NiAVObjectQ* pkTarget, NiAVObjectQ* pkRoot);
};

class ProcessQ
{
  public:
};

class WaterStateQ
{
  public:
};

class CharControllerQ
{
  public:
};

class BodyQ
{
  public:
};

class BodyRefQ
{
  public:
};

class SettingsQ
{
  public:
};

class ManagerQ
{
  public:
};

class ExtraListQ
{
  public:
};

class CellQ
{
  public:
};

class ListQ;


class ProjectileQ
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual void vp078();
    virtual void vp07c();
    virtual void vp080();
    virtual void vp084();
    virtual void vp088();
    virtual void vp08c();
    virtual void vp090();
    virtual void vp094();
    virtual void vp098();
    virtual void vp09c();
    virtual void vp0a0();
    virtual void vp0a4();
    virtual void vp0a8();
    virtual void vp0ac();
    virtual void vp0b0();
    virtual void vp0b4();
    virtual void vp0b8();
    virtual void vp0bc();
    virtual void vp0c0();
    virtual void vp0c4();
    virtual void vp0c8();
    virtual void vp0cc();
    virtual void vp0d0();
    virtual void vp0d4();
    virtual void vp0d8();
    virtual void vp0dc();
    virtual void vp0e0();
    virtual void vp0e4();
    virtual void vp0e8();
    virtual void vp0ec();
    virtual void vp0f0();
    virtual void vp0f4();
    virtual void vp0f8();
    virtual void vp0fc();
    virtual bool IsActor();
    virtual void vq104();
    virtual void vq108();
    virtual void vq10c();
    virtual void vq110();
    virtual void vq114();
    virtual void vq118();
    virtual void vq11c();
    virtual void vq120();
    virtual void vq124();
    virtual void vq128();
    virtual void vq12c();
    virtual void vq130();
    virtual void vq134();
    virtual void vq138();
    virtual void vq13c();
    virtual void vq140();
    virtual void vq144();
    virtual void vq148();
    virtual void vq14c();
    virtual void vq150();
    virtual void vq154();
    virtual void vq158();
    virtual void vq15c();
    virtual void vq160();
    virtual void vq164();
    virtual void vq168();
    virtual void vq16c();
    virtual void vq170();
    virtual void vq174();
    virtual void vq178();
    virtual void vq17c();
    virtual void vq180();
    virtual void vq184();
    virtual void vq188();
    virtual void vq18c();
    virtual void vq190();
    virtual void vq194();
    virtual void vq198();
    virtual void vq19c();
    virtual void vq1a0();
    virtual void vq1a4();
    virtual void vq1a8();
    virtual void vq1ac();
    virtual void vq1b0();
    virtual void vq1b4();
    virtual void vq1b8();
    virtual void vq1bc();
    virtual void vq1c0();
    virtual void vq1c4();
    virtual void vq1c8();
    virtual void vq1cc();
    virtual NiAVObjectQ* Get3D();
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
    CellQ* m_pkCell;


    void FUN_005768b0();
};

// @fnv 0x005768b0
void ProjectileQ::FUN_005768b0()
{
    if (m_pkCell && !::FUN_00450ff0((void *)(m_pkCell)) && !reinterpret_cast<::FUN_004523c0_shell *>((m_pkCell))->FUN_004523c0())
        return;
    NiAVObjectQ* pkRoot = Get3D();
    NiAVObjectQ* pkTarget = pkRoot;
    if (pkRoot)
    {
        reinterpret_cast<::ActorTaskManager *>(((*reinterpret_cast<::ManagerQ * *>(&::g_TES))))->FUN_00453860(true);
        if (!reinterpret_cast<::Holder4523e0 *>(this)->FUN_004523e0(1))
        {
            if (((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->GetFormType() == 0x23)
            {
                TESFormQ* pkBase = ((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
                if (!reinterpret_cast<::FUN_00452440_shell *>((pkBase))->FUN_00452440())
                    reinterpret_cast<::WaterRef *>(this)->FUN_0056c8f0();
            }
            else if (((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) == (*reinterpret_cast<::TESFormQ * *>(&::DAT_011ca240)))
            {
                reinterpret_cast<::s56eab0::Actor *>(this)->FUN_0056eab0();
            }
            else if (((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->GetFormType() == 0xe)
            {
                reinterpret_cast<::P107RefF14 *>(this)->FUN_0056f140();
            }
            else if (((int)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::ExtraListQ *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041fbe0())) && ((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->GetFormType() == 0x15)
            {
                reinterpret_cast<::Ref56D *>(this)->FUN_0056d7e0();
            }
        }
        void* pvName = pkRoot->GetName();
        NodeQ* pkNode = 0;
        if (!IsActor())
        {
            pkNode = ((::NodeQ *)(::FUN_00c812d0(pvName, (void *)(1))));
            pkTarget = pkNode ? ((::NiAVObjectQ *)(reinterpret_cast<::Twin_0044ddc0 *>((pkNode))->GetName())) : pkTarget;
        }
        if (pkTarget)
        {
            ProcessQ* pkProcess = ((::ProcessQ *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
            if (pkProcess)
            {
                ControllerQ* pkController = ((::ControllerQ *)(reinterpret_cast<::FUN_004543c0_cls *>((pkProcess))->FUN_004543c0()));
                BodyRefQ* pkBodyRef = ((::BodyRefQ *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(pkTarget))));
                ProjectileStateQ* pkState = pkBodyRef ? (ProjectileStateQ*)((::BodyQ *)(::fnv_006fa820::FUN_006fa820((const char *)(pkBodyRef)))) : 0;
                if (pkController)
                {
                    if (!pkState || pkState->GetID() != pkController->GetID())
                    {
                        pkController->Attach(pkTarget, pkRoot);
                        if (((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) == (*reinterpret_cast<::TESFormQ * *>(&::DAT_011ca27c)) || ((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) == (*reinterpret_cast<::TESFormQ * *>(&::DAT_011ca280)))
                        {
                            BodyQ* pkBody = pkBodyRef ? ((::BodyQ *)(::fnv_006fa820::FUN_006fa820((const char *)(pkBodyRef)))) : 0;
                            hkVector4Q kPos(*((const ::hkVector4Q *)&(::fnv_00560d80::FUN_00560d80((void *)(pkBody)))));
                            if (((reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::SettingsQ * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() || reinterpret_cast<::FUN_00576d30_shell *>(this)->FUN_00576d30()) && pkBody &&
                                 ((int)(reinterpret_cast<::S00458900_Vector *>(&(kPos))->FUN_00458900((const ::S00458900_Vector *)(void *)(FUN_00458b20()), 0.001f)))) ||
                                !::FUN_00564c10((::TESObjectREFR *)this))
                                ::FUN_00c6a350((::NiAVObject *)(pkRoot), 5, 1, 0, 1);
                        }
                        switch (((::TESFormQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->GetFormType())
                        {
                        case 0x20:
                        case 0x21:
                            ::FUN_00c6a350((::NiAVObject *)(pkRoot), 5, 1, 0, 1);
                            break;
                        default:
                            if (::FUN_00564c10((::TESObjectREFR *)this))
                            {
                                BodyQ* pkBody = pkBodyRef ? ((::BodyQ *)(::fnv_006fa820::FUN_006fa820((const char *)(pkBodyRef)))) : 0;
                                CharControllerQ* pkChar = pkBody ? ((::CharControllerQ *)(reinterpret_cast<::FUN_00620b80_shell *>((pkBody))->GetReferenceFlags())) : 0;
                                if (pkChar && ::FUN_00517690((char *)(((::WaterStateQ *)(reinterpret_cast<::FUN_009d9f40_Class *>((pkChar))->FUN_009d9f40())))) != 5 &&
                                    ::FUN_00517690((char *)(((::WaterStateQ *)(reinterpret_cast<::FUN_009d9f40_Class *>((pkChar))->FUN_009d9f40())))) != 4)
                                {
                                    NiPoint3Q kIntersectionOffset = (*reinterpret_cast<const ::NiPoint3Q *>((void *)&::DAT_011a9484)) * -1.0f;
                                    ::FUN_0062b8d0(pkRoot, &kIntersectionOffset, 0);
                                }
                                reinterpret_cast<::FUN_00564c60_cls *>(this)->FUN_00564c60(0);
                            }
                            break;
                        }
                        reinterpret_cast<::FUN_0086a830_S *>(this)->FUN_0086a830((int)(pkRoot));
                    }
                }
            }
        }
        else
        {
            if (::FUN_0043b300((const ::NiRTTI *)(::ListQ *)(&(*reinterpret_cast<::ListQ *>(&::g_011d5e70))), (::NiAVObject *)(pkRoot)))
            {
                ProcessQ* pkProcess = ((::ProcessQ *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
                if (pkProcess)
                {
                    ControllerQ* pkController = ((::ControllerQ *)(reinterpret_cast<::FUN_004543c0_cls *>((pkProcess))->FUN_004543c0()));
                    if (pkController)
                        pkController->Detach(pkRoot, 0, 0, 0, 0);
                }
            }
        }
        reinterpret_cast<::ActorTaskManager *>(((*reinterpret_cast<::ManagerQ * *>(&::g_TES))))->FUN_00453860(false);
    }
    reinterpret_cast<::FUN_0056c880_S *>(this)->FUN_0056c880(1, 1);
}
