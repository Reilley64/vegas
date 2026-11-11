#include "AutoMemContext.h"

// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0056e900_cls.h"
#include "fnv/decl/FUN_00629a80_Class.h"
#include "fnv/decl/FUN_00666f00_shell.h"
#include "fnv/decl/FUN_006699d0_shell.h"
#include "fnv/decl/FUN_0066da50.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FUN_00a5dbe0_shell.h"
#include "fnv/decl/FUN_00a5ea70_t.h"
#include "fnv/decl/FUN_00b4dec0_shell.h"
#include "fnv/decl/FUN_00c6b950.h"
#include "fnv/decl/FUN_00c6b980_cls.h"
#include "fnv/decl/FUN_00c6c290.h"
#include "fnv/decl/FUN_00c8bed0_cls.h"
#include "fnv/decl/FUN_00caacf0.h"
#include "fnv/decl/FUN_00cb78b0.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiTriGeom2.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00669990__BSTreeModel.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_00c8c5b0__TargetHolder.h"
#include "fnv/decl/fnv_00cb7b80__FUN_00cb7b80_cls.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0054e000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0066b000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a93000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01066000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_01268000.h"
#include <windows.h>
#include "fnv/decl/FUN_004b5020_shell.h"
#include "fnv/decl/FUN_0066a630_shell.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/fnv_0056e270__FUN_0056e270.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/tls.h"
#include <xmmintrin.h>
#include <cstddef>
#include "fnv/decl/FUN_00ca05b0_cls.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c9f000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/PhantomBounds.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/decl/BC6C330HavokCollision.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0056df20_Class.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c84d00_cls.h"
#include "fnv/decl/FUN_00c84d50_cls.h"
#include "fnv/decl/FUN_00c84dc0_cls.h"
#include "fnv/decl/FUN_00c84df0_cls.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/FloatMatrix3.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyObj.h"
#include "fnv/decl/OwnerProxy.h"
#include "fnv/decl/ProjectileListener.h"
#include "fnv/decl/ShapeViewerFields.h"
#include "fnv/decl/SphereShape.h"
#include "fnv/decl/ViewerCollision.h"
#include "fnv/decl/bhkBoxShape.h"
#include "fnv/decl/bhkLimitedHingeConstraint.h"
#include "fnv/decl/bhkLimitedHingeVectorSet.h"
#include "fnv/decl/fnv_00c6bb70__bhkNiCollisionObject.h"
#include "fnv/decl/fnv_00cb7c60__VertsSource.h"
#include "fnv/symbols_00a62000.h"
#include "fnv/symbols_00c65000.h"
#include "fnv/symbols_00c6b000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c9e000.h"
#include "fnv/symbols_00cf0000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_011f6000.h"
#include <cstring>
#include "fnv/decl/Callees.h"
#include "fnv/decl/D9B0Container.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_0062e150_cls.h"
#include "fnv/decl/FUN_00630100_shell.h"
#include "fnv/decl/FUN_0066c9c0_Class.h"
#include "fnv/decl/FUN_0066ca50_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00b0a260_Class.h"
#include "fnv/decl/FUN_00b0d5d0_Class.h"
#include "fnv/decl/HolderFUN.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec4.h"
#include "fnv/decl/fnv_004b4ff0__FUN_004b4ff0_shell.h"
#include "fnv/decl/fnv_00623150__FUN_00623150_Class.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00b0a2a0__SpeedTreeRTB0A2A0.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00c6d000.h"
#include "fnv/symbols_00cb7000.h"
#include "fnv/symbols_00d23000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01017000.h"
#include <math.h>

// The BSTreeNode field after its NiNode part that holds the tree geometry.
struct TreeNodeGeometryView
{
    char niNode[0xf0];
    void* spGeometry;
};
struct FUN_00622430_shell
{
    unsigned int FUN_00622430();
};

// @fnv 0x00622430
unsigned int FUN_00622430_shell::FUN_00622430()
{
    return 0x50;
}

struct NiRTTI;


struct FUN_0066b5b0_shell
{
    const NiRTTI* GetNiRTTI();
};

// @fnv 0x0066b5b0
const NiRTTI* FUN_0066b5b0_shell::GetNiRTTI()
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_011d5e70));
}

class NiAVObject;

struct NiUpdateData;
class NiNode
{
  public:
    NiAVObject* GetAt(unsigned int);
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};

struct BSTreeNode : NiNode
{
    NiAVObject* GetFirstChild();
};

// @fnv 0x0066b5c0
NiAVObject* BSTreeNode::GetFirstChild()
{
    return GetAt(0);
}

namespace fnv_0066b5e0 {
class NiAVObject;

class NiNode
{
  public:
    NiAVObject* GetAt(unsigned int);
};

struct BSTreeNode
{
    NiAVObject* FUN_0066b5e0();
};

// @fnv 0x0066b5e0
NiAVObject* BSTreeNode::FUN_0066b5e0()
{
    return ((NiNode*)this)->GetAt(1);
}
}  // namespace fnv_0066b5e0

namespace fnv_0066b600 {
class NiAVObject;

class NiNode
{
  public:
    NiAVObject* GetAt(unsigned int);
};

struct BSTreeNode : NiNode
{
    NiAVObject* FUN_0066b600();
};

// @fnv 0x0066b600
NiAVObject* BSTreeNode::FUN_0066b600()
{
    return GetAt(2);
}
}  // namespace fnv_0066b600

namespace fnv_0066b680 {
struct BSTreeNode
{
    void FUN_0066b6c0();
    void* FUN_0066b680(unsigned int);
};

void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x0066b680
void* BSTreeNode::FUN_0066b680(unsigned int flags)
{
    this->FUN_0066b6c0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 248);
    return this;
}
}  // namespace fnv_0066b680

namespace fnv_0066be30 {
struct NiProperty
{
    virtual ~NiProperty();
};

struct NiAlphaProperty : NiProperty
{
    void FUN_0094db80(unsigned char);
};

class NiAVObject
{
};

struct Flt {
    operator void*() const;
};

struct PropHelper
{
};

struct BSTreeNode : ::TreeNodeGeometryView
{
    BSTreeNode();
    ~BSTreeNode();
    bool FUN_0066be30(unsigned char acTest);
};

// @fnv 0x0066be30
bool BSTreeNode::FUN_0066be30(unsigned char acTest)
{
    if (!reinterpret_cast<Flt*>(&spGeometry)->operator void*())
    {
        return false;
    }
    if (acTest == 0xff)
    {
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<NiAVObject*>(
            reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(&spGeometry)->operator void*()))))->QueueActorDisarm(true);
    }
    else
    {
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<NiAVObject*>(
            reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(&spGeometry)->operator void*()))))->QueueActorDisarm(false);
        NiAlphaProperty* pprop = reinterpret_cast<NiAlphaProperty*>(
            ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((reinterpret_cast<PropHelper*>(
                reinterpret_cast<char*>(
                    reinterpret_cast<Flt*>(&spGeometry)->operator void*()))))->FUN_00a59d30(0))));
        if (pprop)
        {
            pprop->FUN_0094db80(acTest);
        }
    }
    return true;
}
}  // namespace fnv_0066be30

class NiCullingProcess;
struct DummyNode
{
    void FUN_0066bf50(NiCullingProcess* arCuller);
};

// If FUN_0054ee20() returns nonzero, forwards the culling call to FUN_00a5dbe0 with arCuller.
// @fnv 0x0066bf50
void DummyNode::FUN_0066bf50(NiCullingProcess* arCuller)
{
    if (::FUN_0054ee20({}))
    {
        reinterpret_cast<::FUN_00a5dbe0_shell *>((this))->FUN_00a5dbe0(arCuller);
    }
}

struct FUN_00c6c290_holder
{
};

struct FUN_0066d410_shell : public FUN_00c6c290_holder
{
    void FUN_0066d410();
};

// @fnv 0x0066d410
void FUN_0066d410_shell::FUN_0066d410()
{
    reinterpret_cast<::FUN_00c6c290 *>(this)->FUN_00c6c290::~FUN_00c6c290();
}

struct NiRTTI
{
};


struct FUN_0066d430_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x0066d430
const NiRTTI* FUN_0066d430_shell::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_012683d0));
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

struct FUN_0066d440_shell
{
    void* FUN_0066d440(unsigned int flags);
};

struct FUN_0066d470_shell
{
    void FUN_0066d470();
};
// @fnv 0x0066d440
void* FUN_0066d440_shell::FUN_0066d440(unsigned int flags)
{
    reinterpret_cast<::FUN_0066d470_shell *>((this))->FUN_0066d470();
    if (flags & 1)
        __Dummy_00b6fef0(this, 20);
    return this;
}

// @fnv 0x0066d470
void FUN_0066d470_shell::FUN_0066d470()
{
    reinterpret_cast<::FUN_0066d410_shell *>((this))->FUN_0066d410();
}

struct FUN_0066d510_shell
{
    const void* FUN_0066d510();
};


// @fnv 0x0066d510
const void* FUN_0066d510_shell::FUN_0066d510()
{
    return &(*reinterpret_cast<const void * *>(&::g_012683e0));
}

struct FUN_0066d520_shell
{
    void* FUN_0066d520(unsigned int flags);
};

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x0066d520
void* FUN_0066d520_shell::FUN_0066d520(unsigned int flags)
{
    reinterpret_cast<::FUN_00cb78b0 *>((this))->FUN_00cb78b0::~FUN_00cb78b0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x14);
    return this;
}

struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610 g_012681b4;

struct FUN_0066d610_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

// @fnv 0x0066d610
GlobalObjectO2_00a7b610* FUN_0066d610_shell::GetGlobalObject()
{
    return &g_012681b4;
}

struct bhkCapsuleShape
{
    unsigned int FUN_0066d730() const;
};

// @fnv 0x0066d730
unsigned int bhkCapsuleShape::FUN_0066d730() const
{
    return 0x30;
}

struct FUN_0066da50_t
{
};

struct FUN_0066d7a0_shell
{
    int m0;
    FUN_0066da50_t m1;
    void RunInner();
};

// @fnv 0x0066d7a0
void FUN_0066d7a0_shell::RunInner()
{
    reinterpret_cast<::FUN_0066da50 *>(&(m1))->FUN_0066da50::~FUN_0066da50();
}

struct Flt {
    operator void*() const;
};

class NiTriBasedGeom;

struct FUN_0066b620_shell : ::TreeNodeGeometryView
{
    NiTriBasedGeom* GetTriBasedGeom();
};

// @fnv 0x0066b620
NiTriBasedGeom* FUN_0066b620_shell::GetTriBasedGeom()
{
    return (NiTriBasedGeom*)reinterpret_cast<Flt*>(&spGeometry)->operator void*();
}


struct FUN_0066d400_shell
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x0066d400
const char* const* FUN_0066d400_shell::GetArg1Ptr()
{
    return &(*reinterpret_cast<const char *const *>(&::g_01268168));
}

class NiAVObject
{
public:
    void SetLocalRotation(float, float, float, float);
    void UpdateWorldLoc();
};
struct BSTreeNodeVisibility : BSTreeNode
{
    bool FUN_0066bc40(bool);
};
// Gets the node's NiAVObject and sets its app-culled flag to the inverse of abVisible; returns false if there is no object.
// @fnv 0x0066bc40
bool BSTreeNodeVisibility::FUN_0066bc40(bool abVisible)
{
    NiAVObject* object =
        (NiAVObject*)((NiAVObject * (*)(BSTreeNodeVisibility*)) * (char**)(*(char**)this + 0x104))(this);
    if (!object)
        return false;
    reinterpret_cast<::TaskQueueInterface *>((object))->QueueActorDisarm(!abVisible);
    return true;
}

namespace fnv_0066bc90 {
class NiAVObject
{
};
struct StandInBC90
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual NiNode* GetLeaf();
    bool SetLeafVisible(bool abVisible);
};
// Gets the leaf node via GetLeaf, sets its app-culled flag to the inverse of abVisible, and returns false if no leaf exists.
// @fnv 0x0066bc90
bool StandInBC90::SetLeafVisible(bool abVisible)
{
    NiNode* pnode = GetLeaf();
    if (pnode == 0)
        return false;
    reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)pnode)))->QueueActorDisarm(!abVisible);
    return true;
}
}  // namespace fnv_0066bc90

struct FUN_0066d3d0_shell
{
    void FUN_0066d3d0(void*);
};
struct FUN_0066d3a0_shell
{
    void* FUN_0066d3a0(void*);
};
// @fnv 0x0066d3a0
void* FUN_0066d3a0_shell::FUN_0066d3a0(void* arg)
{
    reinterpret_cast<FUN_0066d3d0_shell*>(this)->FUN_0066d3d0(arg);
    *reinterpret_cast<void**>(this) = &DAT_01066acc;
    return this;
}

namespace fnv_0066d3d0 {
struct FUN_00c6b950_shell
{
};

struct FUN_0066d3d0_shell
{
    void* m0;
    void* FUN_0066d3d0(std::uintptr_t a);
};

// Calls FUN_00c6b950 with a, then sets m0 to point at DAT_01066b94 and returns this.
// @fnv 0x0066d3d0
void* FUN_0066d3d0_shell::FUN_0066d3d0(std::uintptr_t a)
{
    new ((void *)(((FUN_00c6b950_shell*)this))) ::FUN_00c6b950((void *)(a));
    m0 = &(*reinterpret_cast<void * *>(&::DAT_01066b94));
    return this;
}
}  // namespace fnv_0066d3d0

extern "C" void __cdecl FUN_004b5020();
extern "C" void __cdecl FUN_0056e270();
struct FUN_0056e120_shell
{
    void FUN_0056e120();
};
struct FUN_0066d550_shell
{
    const void* pVtable;
    unsigned int uiUnk04;
    char pad08[0x10 - 0x08];
    char kUnk10[4];
    void* Initialize();
};
// @fnv 0x0066d550
void* FUN_0066d550_shell::Initialize()
{
    ((void(*)(void*))FUN_004b5020)(this);
    uiUnk04 = 0;
    ((void(*)(void*))FUN_0056e270)(kUnk10);
    reinterpret_cast<FUN_0056e120_shell*>(kUnk10)->FUN_0056e120();
    return this;
}

struct FUN_00c8bed0_holder
{
};
void __cdecl _delete(void*, unsigned int);
struct bhkTransformShape
{
    void* Destroy(unsigned int);
};
// @fnv 0x0066d620
void* bhkTransformShape::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00c8bed0_cls *>((((FUN_00c8bed0_holder*)this)))->FUN_00c8bed0_cls::~FUN_00c8bed0_cls();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_0066d740_owner
{
    void* DestroyIfFlagged(unsigned int flags);
};
void __cdecl _delete(void* p, unsigned int size);
// @fnv 0x0066d740
void* FUN_0066d740_owner::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00caacf0 *>((this))->FUN_00caacf0::~FUN_00caacf0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_0056e900_shell
{
};
struct FUN_006299a0_shell
{
};
struct FUN_0066d770_shell
{
    const void* pVtable;
    char kUnk04[4];
    void* FUN_0066d770();
};
// Calls StepAndReturnThis on this and FUN_006299a0 on the object at this+4, then returns this.
// @fnv 0x0066d770
void* FUN_0066d770_shell::FUN_0066d770()
{
    reinterpret_cast<::FUN_0056e900_cls *>((((FUN_0056e900_shell*)this)))->StepAndReturnThis();
    reinterpret_cast<::FUN_00629a80_Class *>(reinterpret_cast<FUN_006299a0_shell*>(kUnk04))->FUN_006299a0();
    return this;
}

namespace fnv_0066bce0 {
class NiAVObject
{
};
struct FUN_0066bce0_holder
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual NiNode* GetNode();
    bool SetNodeVisible(bool abVisible);
};
// Gets the node and, if present, sets its app-culled flag to the inverse of abVisible; returns whether a node was found.
// @fnv 0x0066bce0
bool FUN_0066bce0_holder::SetNodeVisible(bool abVisible)
{
    NiNode* pnode;
    pnode = GetNode();
    if (pnode == 0)
        return false;
    reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)pnode)))->QueueActorDisarm(!abVisible);
    return true;
}
}  // namespace fnv_0066bce0

struct NiObject
{
    virtual ~NiObject();
};
struct NiTexturingProperty : NiObject
{
    virtual ~NiTexturingProperty();
};
struct PropHelper
{
};
struct NiAVObjectProp
{
};
struct FUN_0066bec0_shell : ::TreeNodeGeometryView
{
    bool AttachTexturingProperty(NiTexturingProperty* apProp);
};
// If this object has a property container and apProp is non-null, replaces any existing property slot 5 with apProp and returns whether it attached.
// @fnv 0x0066bec0
bool FUN_0066bec0_shell::AttachTexturingProperty(NiTexturingProperty* apProp)
{
    NiTexturingProperty* pprop = 0;
    if (!(void*)(void*)(*reinterpret_cast<Flt*>(&spGeometry)) || !apProp)
        return false;
    pprop = (NiTexturingProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(void*)(*reinterpret_cast<Flt*>(&spGeometry)))))->FUN_00a59d30(5)));
    if (pprop)
    {
        if (pprop == apProp)
            return false;
        reinterpret_cast<::ExtraOwnerB *>((((NiAVObjectProp*)(void*)(*reinterpret_cast<Flt*>(&spGeometry)))))->FUN_00a5b230(5);
    }
    reinterpret_cast<::FUN_00439410_cls *>((((NiAVObjectProp*)(void*)(*reinterpret_cast<Flt*>(&spGeometry)))))->FUN_00439410((::ArgObject *)(apProp));
    return true;
}

struct FUN_0094db80_shell
{
    void FUN_0094db80(unsigned char);
};
struct BSTreeNodeVisibilityWork : BSTreeNodeVisibility
{
    bool SetVisibilityByType(unsigned short type, unsigned char mode);
};
// Looks up the node for a type; if mode is 0xff it culls the node, otherwise it unculls it and passes mode to the node's property 0.
// @fnv 0x0066bdb0
bool BSTreeNodeVisibilityWork::SetVisibilityByType(unsigned short type, unsigned char mode)
{
    typedef NiAVObject*(* GetAtFn)(void*, unsigned int);
    NiAVObject* node = ((GetAtFn)(*(void***)this)[0x45])(this, type);
    if (node == 0)
        return false;
    if (mode == 0xff)
    {
        reinterpret_cast<::TaskQueueInterface *>((node))->QueueActorDisarm(true);
    }
    else
    {
        reinterpret_cast<::TaskQueueInterface *>((node))->QueueActorDisarm(false);
        NiObject* property = (NiObject*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)node)))->FUN_00a59d30(0)));
        if (property != 0)
            ((FUN_0094db80_shell*)property)->FUN_0094db80(mode);
    }
    return true;
}

struct FUN_0066bf80_vftable
{
    void* slot000;
    void* slot004;
    void* slot008;
    void* slot00C;
    void* slot010;
    void* slot014;
    void* slot018;
    void* slot01C;
    void* slot020;
    void* slot024;
    void* slot028;
    void* slot02C;
    void* slot030;
    void* slot034;
    void* slot038;
    void* slot03C;
    void* slot040;
    void* slot044;
    void* slot048;
    void* slot04C;
    void* slot050;
    void* slot054;
    void* slot058;
    void* slot05C;
    void* slot060;
    void* slot064;
    void* slot068;
    void* slot06C;
    void* slot070;
    void* slot074;
    void* slot078;
    void* slot07C;
    void* slot080;
    void* slot084;
    void* slot088;
    void* slot08C;
    void* slot090;
    void* slot094;
    void* slot098;
    void* slot09C;
    void* slot0A0;
    void* slot0A4;
    void* slot0A8;
    void* slot0AC;
    void* slot0B0;
    void* slot0B4;
    void* slot0B8;
    void* slot0BC;
    void* slot0C0;
    void* slot0C4;
    void* slot0C8;
    void* slot0CC;
    void* slot0D0;
    void* slot0D4;
    void* slot0D8;
    void* slot0DC;
    void* slot0E0;
    void* slot0E4;
    void* slot0E8;
    void* slot0EC;
    void* slot0F0;
    void* slot0F4;
    void* slot0F8;
    void* slot0FC;
    void* slot100;
    void* slot104;
    void* slot108;
    void* slot10C;
    void* slot110;
    void* slot114;
    void* slot118;
    void* slot11C;
    void* slot120;
    void* slot124;
    void* slot128;
    void* slot12C;
    void* slot130;
    void* slot134;
    void* slot138;
    void* slot13C;
    void* slot140;
    void(* process)(void*, float);
};
struct FUN_0066bf80_owner
{
    FUN_0066bf80_vftable* vtable;
    void FUN_0066bf80(struct FUN_0066bf80_data*, unsigned int);
};
struct FUN_0066bf80_data
{
    float time;
};
class NiCamera;
struct FUN_00a5dd70_shell
{
};
enum MEM_CONTEXT
{
    MEM_CONTEXT_SCENE = 0x1e
};
using ::AutoMemContext;
// @fnv 0x0066bf80
void FUN_0066bf80_owner::FUN_0066bf80(FUN_0066bf80_data* data, unsigned int flags)
{
    AutoMemContext context(MEM_CONTEXT_SCENE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeNode.cpp", 0x20d);
    if (!::FUN_0054ee20({}))
        return;
    if (data->time > ::_DAT_01012060)
    {
        if (!::FUN_004b5fc0((NiAVObject*)this, (NiCamera*)(std::uintptr_t)::FUN_00552380()))
            return;
    }
    vtable->process(this, data->time);
    reinterpret_cast<::NiNode *>((((FUN_00a5dd70_shell*)this)))->UpdateDownwardPass((::NiUpdateData &)(*data), flags);
}

class NiTexture;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* apObject);
    ~NiPointer();
    operator T*() const;
};

struct BGSBodyPart
{
};

struct bhkWorldObject;

struct bhkCollisionObject
{
};


struct FUN_0066d7c0_cls
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
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual BGSBodyPart* GetPart();
    NiObject* FUN_0066d7c0();
};

// @fnv 0x0066d7c0
NiObject* FUN_0066d7c0_cls::FUN_0066d7c0()
{
    NiObject* pResult4 = 0;
    BGSBodyPart* pPart8 = GetPart();
    if (pPart8)
    {
        NiPointer<NiTexture> spRetainedObject((NiTexture*)((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pPart8))->FUN_006838b0())));
        if (spRetainedObject)
        {
            bhkWorldObject* pWorld5 = ((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(((bhkCollisionObject*)(NiTexture*)spRetainedObject)))));
            pResult4 = FUN_00653270((const NiRTTI*)&(*reinterpret_cast<char *>(&::g_01268230)), (NiObject*)pWorld5);
        }
    }
    return pResult4;
}

struct S_0066b6c0_Base
{
    virtual ~S_0066b6c0_Base();
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
};

struct FUN_0066b6c0 : S_0066b6c0_Base
{
    NiPointer<NiNode> spTree0;
    NiPointer<NiNode>* pArr1;
    NiPointer<NiNode>* pArr2;
    NiPointer<NiNode> spTree1;

    virtual ~FUN_0066b6c0();
};

// Frees the two NiPointer<NiNode> arrays owned by the object and nulls their pointers.
// @fnv 0x0066b6c0
FUN_0066b6c0::~FUN_0066b6c0()
{
    if (pArr1)
    {
        delete[] pArr1;
        pArr1 = 0;
    }
    if (pArr2)
    {
        delete[] pArr2;
        pArr2 = 0;
    }
}

struct ItemList
{
};

struct SmartPtr
{
    void* m_pObject;
};

struct FUN_0066b840_cls
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    SmartPtr m_kNode;
    int unkE8;
    SmartPtr* m_entries;
    void* GetEntry(unsigned short index);
};

// Returns the entry at index from m_entries if the list pointer and entries are valid and index is in range, otherwise returns 0.
// @fnv 0x0066b840
void* FUN_0066b840_cls::GetEntry(unsigned short index)
{
    if (((void *)(::FUN_00559450((int *)&(m_kNode)))) == 0 || m_entries == 0 || index >= reinterpret_cast<::FUN_006699d0_shell *>((((ItemList*)((void *)(::FUN_00559450((int *)&(m_kNode)))))))->GetUnsignedShort())
        return 0;
    return ((void *)(::FUN_00559450((int *)&(m_entries[index]))));
}

struct S_0066ba30_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    S_0066ba30_Str();
    ~S_0066ba30_Str();
};
struct S_0066ba30_Model
{
};
struct S_0066ba30_Obj;
template <class T> struct S_0066ba30_Ptr
{
    T* m_pObject;
    operator T*() const;
    T* operator->() const;
    S_0066ba30_Ptr& operator=(T* p);
};
struct S_0066ba30_Node
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
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void SetObj(S_0066ba30_Obj* apObj, bool abFlag);
    virtual void ve0();
    virtual void ve4();
    virtual void ClearObj(S_0066ba30_Obj* apObj);
};
struct S_0066ba30
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
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual S_0066ba30_Node* GetNode();
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    S_0066ba30_Ptr<S_0066ba30_Model> m_spModel;
    int unkE8;
    S_0066ba30_Ptr<S_0066ba30_Obj>* m_pObjects;
    bool SetObjectAtIndex(unsigned short index, S_0066ba30_Obj* apObj);
};

// Validates the model, object array and object, then clears the node's old object, sets the new one and stores it at index.
// @fnv 0x0066ba30
bool S_0066ba30::SetObjectAtIndex(unsigned short index, S_0066ba30_Obj* apObj)
{
    S_0066ba30_Str name5;
    if (!m_spModel || !m_pObjects || !apObj)
        return false;
    unsigned short count = reinterpret_cast<::FUN_006699d0_shell *>(((m_spModel).operator->()))->GetUnsignedShort();
    if (index >= count)
        return false;
    S_0066ba30_Node* pNode2 = GetNode();
    if (!pNode2)
        return false;
    if (m_pObjects[index])
        pNode2->ClearObj(m_pObjects[index]);
    pNode2->SetObj(apObj, true);
    m_pObjects[index] = apObj;
    return true;
}

struct VisNode70
{
};

struct VisNodeAlpha70
{
};

struct FUN_0066bd30_cls
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
    virtual VisNode70* v44(unsigned short aType);

    bool FUN_0066bd30(unsigned short aType, unsigned char aMode);
};

// @fnv 0x0066bd30
bool FUN_0066bd30_cls::FUN_0066bd30(unsigned short aType, unsigned char aMode)
{
    VisNode70* node = v44(aType);
    if (node == 0)
        return false;
    if (aMode == 0xff)
    {
        reinterpret_cast<::TaskQueueInterface *>((node))->QueueActorDisarm(1);
    }
    else
    {
        reinterpret_cast<::TaskQueueInterface *>((node))->QueueActorDisarm(0);
        VisNodeAlpha70* alpha = (VisNodeAlpha70*)((::VisNode70 *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(0)));
        if (alpha)
            reinterpret_cast<::FUN_0094db80_shell *>((alpha))->FUN_0094db80(aMode);
    }
    return true;
}

struct C070Node
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void UpdateTime(float fTime);

};

struct C070TreeNode : C070Node
{
    void FUN_0066c070(FUN_0066bf80_data& kUpdate, unsigned int uiFlags);
};

// @fnv 0x0066c070
void C070TreeNode::FUN_0066c070(FUN_0066bf80_data& kUpdate, unsigned int uiFlags)
{
    AutoMemContext kMemContext(MEM_CONTEXT_SCENE, true,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeNode.cpp",
                               0x223);
    if (!::FUN_0054ee20({}))
        return;
    if (kUpdate.time > ::_DAT_01012060)
    {
        if (!::FUN_004b5fc0((NiAVObject*)this, (NiCamera*)(std::uintptr_t)::FUN_00552380()))
            return;
    }
    UpdateTime(kUpdate.time);
    reinterpret_cast<::NiNode *>(this)->UpdateSelectedDownwardPass((::NiUpdateData &)(kUpdate), uiFlags);
}

extern char DAT_01066c5c;

struct FUN_0066d490_base
{
    FUN_0066d490_base();
    ~FUN_0066d490_base();
};

struct FUN_0066d490_cls : FUN_0066d490_base
{
    void* m_vptr;
    FUN_0066d490_cls(std::uintptr_t a1);
};

// Sets the vtable pointer, calls FUN_00cb7b80 with a1, and increments DAT_012683dc.
// @fnv 0x0066d490
FUN_0066d490_cls::FUN_0066d490_cls(std::uintptr_t a1)
{
    *(void* volatile*)&m_vptr = &DAT_01066c5c;
    reinterpret_cast<::fnv_00cb7b80::FUN_00cb7b80_cls *>((this))->FUN_00cb7b80((::fnv_00cb7b80::SpawnArgs *)(a1));
    DAT_012683dc = DAT_012683dc + 1;
}


struct FUN_0066d590_base
{
    FUN_0066d590_base();
    ~FUN_0066d590_base();
};

struct FUN_0066d590_cls : FUN_0066d590_base
{
    void* m_vptr;
    FUN_0066d590_cls(std::uintptr_t a1);
};

// Sets the vtable pointer, calls FUN_00c8c5b0 with the given id, and increments DAT_012681b0.
// @fnv 0x0066d590
FUN_0066d590_cls::FUN_0066d590_cls(std::uintptr_t a1)
{
    *(void* volatile*)&m_vptr = &DAT_01066d44;
    reinterpret_cast<::fnv_00c8c5b0::TargetHolder *>((this))->FUN_00c8c5b0((::fnv_00c8c5b0::Src *)(a1));
    DAT_012681b0 = DAT_012681b0 + 1;
}


struct S_0066d880_List
{
};
struct S_0066d880_Obj
{
};
struct S_0066d880_Holder
{
};
struct S_0066d880_Base
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
};
struct S_0066d880 : S_0066d880_Base
{
    S_0066d880_Holder m_e4;
    void FUN_0066d880(S_0066d880_List* list);
};

// @fnv 0x0066d880
void S_0066d880::FUN_0066d880(S_0066d880_List* list)
{
    reinterpret_cast<::FUN_00a5ea70_t *>(this)->FUN_00a5ea70((::StrArr *)(list));
    char* name = ::FUN_00a7d330("BSTreeNode");
    reinterpret_cast<::S_0060ba10 *>((list))->FUN_0096a610((std::intptr_t)(&name));
    char* text;
    if (((::S_0066d880_Obj *)(::FUN_00559450((int *)&(m_e4)))))
    {
        text = new char[0x20];
        if (((unsigned char)(reinterpret_cast<::FUN_00666f00_shell *>((((::S_0066d880_Obj *)(::FUN_00559450((int *)&(m_e4))))))->FUN_00666f00())))
            ::FUN_00406d00(text, 0x20, "Type = Instance");
        else
            ::FUN_00406d00(text, 0x20, "Type = Base");
        reinterpret_cast<::S_0060ba10 *>((list))->FUN_0096a610((std::intptr_t)(&text));
        text = new char[0x20];
        ::FUN_00406d00(text, 0x20, "Seed = %d", ((std::intptr_t)(reinterpret_cast<::LowProcess *>((((::S_0066d880_Obj *)(::FUN_00559450((int *)&(m_e4))))))->GetTarget())));
        reinterpret_cast<::S_0060ba10 *>((list))->FUN_0096a610((std::intptr_t)(&text));
    }
    else
    {
        text = new char[0x20];
        ::FUN_00406d00(text, 0x20, "-No Model-");
        reinterpret_cast<::S_0060ba10 *>((list))->FUN_0096a610((std::intptr_t)(&text));
    }
}

extern void* __cdecl FUN_00aa13e0(unsigned int size);

struct FUN_00b4e150
{
    virtual ~FUN_00b4e150();
    FUN_00b4e150();
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
};
struct TreePointer
{
    void* m_pObject;
    TreePointer(void* p);
    ~TreePointer();
    void FUN_0066b0d0(void* p);
};
struct TreeLists
{
    void* ConvertFloatToUInt();
};
struct FUN_00a5ecb0
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
    FUN_00a5ecb0(int initial);
};
struct FUN_0051cf00
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
    FUN_0051cf00();
};
struct FUN_006694e0
{
    void* m_pObject;
    FUN_006694e0();
    ~FUN_006694e0();
    void FUN_0066b0d0(void* p);
};
struct FUN_0066b640
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
    virtual void v8c(void*);
    unsigned int unk04, unk08, unk0c, unk10;
    FUN_0066b640();
};
struct FUN_0066b120 : FUN_00b4e150
{
    TreePointer m_e4;
    FUN_006694e0* m_e8;
    FUN_006694e0* m_ec;
    TreePointer m_f0;
    float m_f4;
    virtual ~FUN_0066b120();
    FUN_0066b120(void* initial, void* external);

};

// Initializes the tree controller: sets up slots, allocates arrays from the tree list counts, creates controllers and attaches the chosen object.
// @fnv 0x0066b120
FUN_0066b120::FUN_0066b120(void* initial, void* external) : m_e4(0), m_f0(0)
{
    reinterpret_cast<::FUN_00b4dec0_shell *>(this)->FUN_00b4dec0(6);
    m_e4.FUN_0066b0d0(initial);
    reinterpret_cast<::TaskQueueInterface *>(this)->FUN_004902f0(1);
    FUN_00a5ecb0* pkCurrentObject = new FUN_00a5ecb0(0);
    ::fnv_00a93ea0::SetChildAt((::NiNode *)this, 0, (std::uintptr_t)(pkCurrentObject), {});
    pkCurrentObject = new FUN_00a5ecb0(0);
    ::fnv_00a93ea0::SetChildAt((::NiNode *)this, 1, (std::uintptr_t)(pkCurrentObject), {});
    FUN_0066b640* pController;
    FUN_0051cf00* controller = new FUN_0051cf00();
    reinterpret_cast<::NiTriGeom2 *>((controller))->FUN_0051d000(1);
    reinterpret_cast<::NiAVObject *>((controller))->SetLocalRotation(DAT_01016b78, 1.0f, 0.0f, 0.0f);
    ::fnv_00a93ea0::SetChildAt((::NiNode *)this, 2, (std::uintptr_t)(controller), {});

    unsigned short count;
    unsigned short i = reinterpret_cast<::fnv_00669990::BSTreeModel *>((((::TreeLists *)(::FUN_00559450((int *)&(m_e4))))))->FUN_00669990();
    if (i != 0)
    {
        m_e8 = new FUN_006694e0[i];
        for (count = 0; count < i; ++count)
            m_e8[count].FUN_0066b0d0(0);
    }
    else
    {
        m_e8 = 0;
    }
    i = reinterpret_cast<::FUN_006699d0_shell *>((((::TreeLists *)(::FUN_00559450((int *)&(m_e4))))))->GetUnsignedShort();
    if (i != 0)
    {
        m_ec = new FUN_006694e0[i];
        for (count = 0; count < i; ++count)
            m_ec[count].FUN_0066b0d0(0);
    }
    else
    {
        m_ec = 0;
    }
    m_f0.FUN_0066b0d0(0);
    reinterpret_cast<::FUN_00a5bca0_shell *>(this)->SetExtraDataName((::NiExtraData *)(void *)(((void *)(::GetFltValueAtOffset16()))));
    void* chosen = external ? external : ((::TreeLists *)(::FUN_00559450((int *)&(m_e4))))->ConvertFloatToUInt();
    if (chosen)
    {
        pController = new FUN_0066b640();
        reinterpret_cast<::FUN_00c6b980_cls *>((pController))->FUN_00c6b980((::World_c6b *)(void *)(external ? external : ((::TreeLists *)(::FUN_00559450((int *)&(m_e4))))->ConvertFloatToUInt()));
        pController->v8c(this);
    }
    m_f4 = 0.0f;
}

class B66B7D0Object;

class B66B7D0Header
{
  public:
};

class B66B7D0HeaderPtr
{
  public:

    B66B7D0Header* m_pkHeader;
};

class B66B7D0ObjectPtr
{
  public:

    B66B7D0Object* m_pPointer;
};

class B66B7D0Owner
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    B66B7D0HeaderPtr m_kHeader;
    B66B7D0ObjectPtr* m_pkObjects;

    B66B7D0Object* GetObjectByIndex(unsigned short usIndex);
};

// Returns the object at usIndex from m_pkObjects if the header exists, the array exists and usIndex is below the header count; otherwise returns 0.
// @fnv 0x0066b7d0
B66B7D0Object* B66B7D0Owner::GetObjectByIndex(unsigned short usIndex)
{
    if (!((::B66B7D0Header *)(::FUN_00559450((int *)&(m_kHeader)))) || !m_pkObjects || usIndex >= reinterpret_cast<::fnv_00669990::BSTreeModel *>((((::B66B7D0Header *)(::FUN_00559450((int *)&(m_kHeader))))))->FUN_00669990())
        return 0;
    return ((::B66B7D0Object *)(::FUN_00559450((int *)&(m_pkObjects[usIndex]))));
}

class C66BBB0Path;

class C66BBB0PathRef
{
  public:
    void Reset(C66BBB0Path* pkPath);

    C66BBB0Path* m_pkPath;
};

class C66BBB0Handler
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void SetPath(C66BBB0Path* pkPath, bool bFlag);
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void ClearPath(C66BBB0Path* pkPath);
};

class C66BBB0Owner
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual C66BBB0Handler* GetHandler();

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
    C66BBB0PathRef m_kPathRef;

    void FUN_0066bbb0(C66BBB0Path* pkPath);
};

// Clears the handler's current path if one is set, assigns pkPath to the handler, and stores it in m_kPathRef.
// @fnv 0x0066bbb0
void C66BBB0Owner::FUN_0066bbb0(C66BBB0Path* pkPath)
{
    if (!pkPath)
        return;

    C66BBB0Handler* pkHandler = GetHandler();
    if (!pkHandler)
        return;

    if (((::C66BBB0Path *)(::FUN_00559450((int *)&(m_kPathRef)))))
        pkHandler->ClearPath(((::C66BBB0Path *)(::FUN_00559450((int *)&(m_kPathRef)))));
    pkHandler->SetPath(pkPath, true);
    m_kPathRef.Reset(pkPath);
}

struct FnvScopedContext
{
    int previousContext;
    int currentContext;
    FnvScopedContext();
    ~FnvScopedContext();
};
struct FnvModelElement
{
};
struct FnvModelReference
{
};
struct FnvObjectSlot
{
    void* m_object;
    void FUN_0066b0d0(int type);
};
struct FnvElementCollection : S_0066b6c0_Base
{
    FnvModelReference m_model;
    FnvObjectSlot* m_slots;
    bool SetSlotObject(unsigned short index, int type);
};
typedef S_0066ba30_Node*(* FnvNodeGetter)(FnvElementCollection*);
// Validates index and type against the model, clears the slot's existing object, sets the new object on the actor, and stores it in the slot.
// @fnv 0x0066b8b0
bool FnvElementCollection::SetSlotObject(unsigned short index, int type)
{
    FnvScopedContext guard;
    if (!((::FnvModelElement *)(::FUN_00559450((int *)&(m_model)))) || !m_slots || !type)
        return false;
    unsigned short maxIndex = reinterpret_cast<::fnv_00669990::BSTreeModel *>((((::FnvModelElement *)(::FUN_00559450((int *)&(m_model))))))->FUN_00669990();
    if (index >= maxIndex)
        return false;
    S_0066ba30_Node* actor = reinterpret_cast<FnvNodeGetter>(
        reinterpret_cast<FUN_0066bf80_vftable*>(*reinterpret_cast<void**>(this))->slot104)(this);
    if (!actor)
        return false;
    if (((void *)(::FUN_00559450((int *)&(m_slots[index])))))
    {
        actor->ClearObj(reinterpret_cast<S_0066ba30_Obj*>(((void *)(::FUN_00559450((int *)&(m_slots[index]))))));
    }
    actor->SetObj(reinterpret_cast<S_0066ba30_Obj*>(type), true);
    m_slots[index].FUN_0066b0d0(type);
    return true;
}

struct NiNode_o2_nood_nogf
{
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};

struct BSTreeNode_o2_nood_nogf : NiNode_o2_nood_nogf
{
    NiAVObject* GetFirstChild();
};

struct BSTreeNodeVisibility_o2_nood_nogf : BSTreeNode_o2_nood_nogf
{
    bool FUN_0066bc40(bool);
};

struct FUN_0066d3d0_shell_o2_nood_nogf
{
};

struct BSTreeNodeVisibilityWork_o2_nood_nogf : BSTreeNodeVisibility_o2_nood_nogf
{
    bool SetVisibilityByType(unsigned short type, unsigned char mode);
};

struct FUN_0066b6c0_o2_nood_nogf : S_0066b6c0_Base
{
    NiPointer<NiNode_o2_nood_nogf> spTree0;
    NiPointer<NiNode_o2_nood_nogf>* pArr1;
    NiPointer<NiNode_o2_nood_nogf>* pArr2;
    NiPointer<NiNode_o2_nood_nogf> spTree1;

    virtual ~FUN_0066b6c0_o2_nood_nogf();
};

struct TreeLists_o2_nood_nogf
{
};

inline unsigned int GetMemContextC8C()
{
    return ::g_tlsBlock.memoryContext;
}

inline void SetMemContextC8C(unsigned int m_uiGeometryShaderFlags)
{
    ::g_tlsBlock.memoryContext = m_uiGeometryShaderFlags;
}

class AutoMemContextC8C
{
  public:
    AutoMemContextC8C(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC8C();
        SetMemContextC8C(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC8C()
    {
        SetMemContextC8C(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

struct __declspec(align(16)) hkVector4C8C
{
    __m128 m_vComponents;
    inline hkVector4C8C& operator=(const hkVector4C8C& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct hkRotationC8C
{
    hkVector4C8C m_kColumn0;
    hkVector4C8C m_kColumn1;
    hkVector4C8C m_kColumn2;
};

struct hkTransformC8C
{
    hkRotationC8C m_rotation;
    hkVector4C8C m_vTranslation;
};

struct NiMatrix3C8C
{
    float m_afEntries[3][3];
};

struct NiPoint3C8C
{
    float x, y, z;
};

struct NiTransformC8C
{
    NiMatrix3C8C m_kOrientation;
    NiPoint3C8C m_kTranslation;
    float m_fScale;
};

class NiFixedStringC8C
{
  public:
    NiFixedStringC8C(const char* pcString)
    {
        m_kHandle = ::NiGlobalStringTable::AddString(pcString);
    }
    ~NiFixedStringC8C()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

__declspec(restrict) void* __cdecl FUN_00aa13e0(unsigned int uiSize);

void __cdecl FUN_00aa1460(void* p);

struct ArgC8C;

class NiNodeC8C
{
  public:
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    NiTransformC8C m_kLocalTransform;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;

    NiNodeC8C(int iInitial);
};

class ParentC8C
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void OnAttached(NiNodeC8C* pkNode, ArgC8C* iValue);
    virtual void vD8();
    virtual void AttachChildInAvailableSlot(NiNodeC8C* pkChild, bool abFirstAvailableSlot);
};

struct LinkC8C
{
    int unk00, unk04;
    ParentC8C* m_pkOwnerManager;
};

struct BodyC8C
{
    int unk00, unk04, unk08, unk0C, unk10;
    LinkC8C* m_pkLink;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkTransformC8C m_kTransform;
};

class SceneObjectC8C
{
  public:
    int unk00, unk04;
    BodyC8C* m_pkBody;

    void FUN_00c8c860(ParentC8C* pkParent, ArgC8C* iValue);
};

// @fnv 0x00c8c860
void SceneObjectC8C::FUN_00c8c860(ParentC8C* pkParent, ArgC8C* iValue)
{
    AutoMemContextC8C kContext(0x10);

    hkTransformC8C kXform;
    kXform = (this && m_pkBody) ? m_pkBody->m_kTransform : (*reinterpret_cast<::hkTransformC8C *>(&::DAT_01268370));

    NiTransformC8C kLocal;
    ::FUN_00624b10((::FUN_004769c0_shell *)(::NiMatrix3C8C *)(&kLocal.m_kOrientation), (::FUN_004b4cf0_shell *)(&kXform.m_rotation));
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&kLocal.m_kTranslation)), (*(const ::hkVector4 *)(&kXform.m_vTranslation)));

    NiNodeC8C* __restrict pkNode = new NiNodeC8C(0);
    ::AssignFixedString((char *)(pkNode), (std::intptr_t)&(const ::NiFixedStringC8C &)(NiFixedStringC8C("bhkTransformShape")), {});
    pkParent->AttachChildInAvailableSlot(pkNode, true);
    pkNode->m_kLocalTransform.m_kTranslation = kLocal.m_kTranslation;
    pkNode->m_kLocalTransform.m_kOrientation = kLocal.m_kOrientation;

    if (this)
    {
        BodyC8C* pkBody = m_pkBody;
        if (pkBody)
        {
            LinkC8C* pkLink = pkBody->m_pkLink;
            if (pkLink)
            {
                ParentC8C* pkOwner = pkLink->m_pkOwnerManager;
                if (pkOwner)
                    pkOwner->OnAttached(pkNode, iValue);
            }
        }
    }
}

struct NiAVObject_o2_nood;

struct NiNode_o2_nood
{
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};

struct BSTreeNode_o2_nood : NiNode_o2_nood
{
    NiAVObject_o2_nood* GetFirstChild();
};

struct NiAVObject_o2_nood
{
};

struct BSTreeNodeVisibility_o2_nood : BSTreeNode_o2_nood
{
    bool FUN_0066bc40(bool);
};

struct FUN_0066d3d0_shell_o2_nood
{
};

struct BSTreeNodeVisibilityWork_o2_nood : BSTreeNodeVisibility_o2_nood
{
    bool SetVisibilityByType(unsigned short type, unsigned char mode);
};

struct FUN_0066b6c0_o2_nood : S_0066b6c0_Base
{
    NiPointer<NiNode_o2_nood> spTree0;
    NiPointer<NiNode_o2_nood>* pArr1;
    NiPointer<NiNode_o2_nood>* pArr2;
    NiPointer<NiNode_o2_nood> spTree1;

    virtual ~FUN_0066b6c0_o2_nood();
};

struct bhkLimitedHingeVector
{
    unsigned char vecData[16];
};

struct Inner
{
    unsigned char unk00[0x14];
    void* m14;
    unsigned char unk18[0x18];
    __m128 rows[4];
};

struct Param
{
    unsigned char unk00[4];
    void* m4;
    unsigned char unk08[8];
    bhkLimitedHingeVector vecs[4];
};

struct MyObj_o2_nood
{
    unsigned char unk00[8];
    Inner* m8;
    void FUN_00c8c410(void*);
};

// @fnv 0x00c8c410
void MyObj_o2_nood::FUN_00c8c410(void* pArg)
{
    reinterpret_cast<::This *>((this))->FUN_00c84e20((unsigned int *)(pArg));
    Param* p = (Param*)pArg;
    p->m4 = (this && this->m8) ? this->m8->m14 : 0;
    const __m128* src = (this && this->m8) ? &this->m8->rows[0] : (*reinterpret_cast<const __m128 (*)[4]>(&::DAT_01268370));
    __m128 tmp[4];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    tmp[3] = src[3];
    bhkLimitedHingeVector* pv = p->vecs;
    reinterpret_cast<::S004b4db0_Quaternion *>(&(pv[0]))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((float*)tmp)));
    reinterpret_cast<::S004b4db0_Quaternion *>(&(pv[1]))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((float*)&tmp[1])));
    reinterpret_cast<::S004b4db0_Quaternion *>(&(pv[2]))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((float*)&tmp[2])));
    reinterpret_cast<::S004b4db0_Quaternion *>(&(pv[3]))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((float*)&tmp[3])));
}

namespace fnv_00c8c5b0 {

struct AllocVt
{
    void* v0;
    void*(* Alloc)(void*, unsigned int);
};
struct AllocObj
{
    AllocVt* vt;
};
struct AllocHolder
{
    unsigned int unk00, unk04, unk08, unk0C;
    AllocObj* mpAlloc;
};

struct FUN_00cf5990
{
    unsigned int unk00;
    unsigned short w4;
    FUN_00cf5990(unsigned int, void*);
    static void* operator new(std::size_t)
    {
        AllocHolder* h = ((AllocHolder *)::FUN_00c85750());
        AllocObj* al = h->mpAlloc;
        FUN_00cf5990* p = (FUN_00cf5990*)al->vt->Alloc(al, 0x70);
        p->w4 = 0x70;
        return p;
    }
    static void operator delete(void*);
};

struct Inner
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int m10;
};
struct Mid
{
    unsigned int unk00, unk04;
    Inner* p;
};
struct Top
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    Mid* p;
};

struct Src
{
    unsigned int m0, m4;
    Top* m8;
    unsigned int mC;
    float f[16];
};

struct Guard
{
    unsigned int saved;
    Guard() : saved(::g_tlsBlock.memoryContext)
    {
        ::g_tlsBlock.memoryContext = 0x10;
    }
    ~Guard()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};
struct Transform
{
    __m128 r[4];
    __forceinline Transform(Src* apSrc)
    {
        r[0] = _mm_setr_ps(apSrc->f[0], apSrc->f[1], apSrc->f[2], apSrc->f[3]);
        r[1] = _mm_setr_ps(apSrc->f[4], apSrc->f[5], apSrc->f[6], apSrc->f[7]);
        r[2] = _mm_setr_ps(apSrc->f[8], apSrc->f[9], apSrc->f[10], apSrc->f[11]);
        r[3] = _mm_setr_ps(apSrc->f[12], apSrc->f[13], apSrc->f[14], apSrc->f[15]);
    }
};

struct TargetHolder_o2_nood
{
    void** vt;
    unsigned int unk04;
    Top* m8;
    unsigned int unk0C;
    unsigned int m10;
    void FUN_00c8c5b0(Src* apSrc);
};

// @fnv 0x00c8c5b0
void TargetHolder_o2_nood::FUN_00c8c5b0(Src* apSrc)
{
    Guard g0;
    Transform kTransform(apSrc);
    FUN_00cf5990* n = new FUN_00cf5990(apSrc->m4, &kTransform);
    ((void(*)(void*, FUN_00cf5990*))this->vt[35])(this, n);
    reinterpret_cast<::hkReferencedObjectC905 *>((n))->FUN_00c905b0();
    ((void(*)(void*, Src*))this->vt[47])(this, apSrc);
    if (this->m8)
    {
        if (this->m8->p)
        {
            if (this->m8->p->p)
                this->m10 = this->m8->p->p->m10 & 0x1f;
        }
    }
}
}

// namespace fnv_00c8c5b0

struct Alloc
{
    virtual void v0();
    virtual void* Alloc_(unsigned int);
};

struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Alloc* unk10;
};


struct Data8
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float unk20[4], unk30[4];
};

struct Vec
{
    float x, y, z, w;
};

struct Output
{
    int unk00;
    float unk04;
    int unk08, unk0c;
    Vec unk10, unk20;
    int unk30;
    int unk34;
    int unk38;
};

struct FUN_00d22dc0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int unk04;
    void* unk08;
    FUN_00d22dc0(const __m128&, const __m128&, float, int, int);
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
    static void* operator new(std::size_t n);
    static void operator delete(void*);
};

struct Obj
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
    virtual void Call(void*, void*, void*, const char*);
    int unk04;
    Data8* unk08;
    void FUN_00cab1b0(void*, void*);
};



// The size word operator new stores after the vtable pointer.
struct AllocatedSizeView
{
    const void* pVtable;
    short sAllocSize;
};

void* FUN_00d22dc0::operator new(std::size_t n)
{
    Holder* h = ((Holder *)::FUN_00c85750());
    Alloc* allocator = h->unk10;
    void* p = allocator->Alloc_(n);
    static_cast<AllocatedSizeView*>(p)->sAllocSize = (short)n;
    return p;
}

struct TlsRestore
{
    int old;
    TlsRestore()
    {
        old = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }
    ~TlsRestore()
    {
        ::g_tlsBlock.memoryContext = old;
    }
};

// @fnv 0x00cab1b0
void Obj::FUN_00cab1b0(void* a1, void* a2)
{
    TlsRestore guard;
    Output out;
    out.unk04 = DAT_010c72bc;
    out.unk10.x = 0;
    out.unk10.y = 0;
    out.unk10.z = 0;
    out.unk10.w = 0;
    out.unk00 = 0;
    out.unk20.x = 1;
    out.unk20.y = 0;
    out.unk20.z = 0;
    out.unk20.w = 0;
    ::FUN_00c9fb70((::MyObj *)this, (std::intptr_t)(&out), {});
    reinterpret_cast<::S004b4db0_Quaternion *>(&(out.unk10))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(this && unk08 ? unk08->unk20 : (*reinterpret_cast<float (*)[]>(&::DAT_01267e30)))));
    reinterpret_cast<::S004b4db0_Quaternion *>(&(out.unk20))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(this && unk08 ? unk08->unk30 : (*reinterpret_cast<float (*)[]>(&::DAT_01267e30)))));
    FUN_00d22dc0* sub =
        new FUN_00d22dc0(_mm_setr_ps(out.unk10.x, out.unk10.y, out.unk10.z, out.unk10.w),
                         _mm_setr_ps(out.unk20.x, out.unk20.y, out.unk20.z, out.unk20.w), out.unk04, 6, 1);
    sub->v4();
    void* inner = sub->unk08;
    if (inner)
        Call(a1, inner, a2, "bhkCapsuleShape");
}

struct SpawnedSource
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};

struct SpawnedSourceOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void Apply(SpawnedSource* apSource);

    void FUN_00cab820(SpawnedSource* apSource);
};

// @fnv 0x00cab820
void SpawnedSourceOwner::FUN_00cab820(SpawnedSource* apSource)
{
    __m128 vA = _mm_setr_ps(apSource->m_f20, apSource->m_f24, apSource->m_f28, apSource->m_f2C);
    __m128 vB = _mm_setr_ps(apSource->m_f10, apSource->m_f14, apSource->m_f18, apSource->m_f1C);
    reinterpret_cast<::Owner *>(this)->FUN_00cab0e0((std::intptr_t)(&vB), (std::intptr_t)(&vA), apSource->m_f04);
    Apply(apSource);
}

namespace fnv_00cb7c60 {

struct HeapContextScope
{
    int m_saved;
    HeapContextScope()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~HeapContextScope()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

struct hkVec4
{
    __m128 m_vComponents;
    hkVec4()
    {}
    hkVec4(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkMemAllocator;
struct hkMemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemAllocator* unk10;
    hkMemAllocator& heap()
    {
        return *unk10;
    }
};

struct VecArray
{
    hkVec4* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void GrowArrayCapacity(hkMemAllocator& a, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(a), (::SpawnedArray *)(void *)(this), newSize, sizeof(hkVec4));
        }
    }
    void _setSize(hkMemAllocator& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(((hkMemRouter *)::FUN_00c85750())->heap(), n);
    }
    void setSizeCleared(int n)
    {
        clear();
        SetSizeAndGrow(n);
    }
};

struct VertsOut
{
    int unk00;
    VecArray unk04;
};

struct VertsData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVec4 unk20;
};

struct VertsSource_o2_nood
{
    int unk00;
    int unk04;
    VertsData* unk08;
    int getNumVerts() const
    {
        return (this && unk08) ? unk08->unk10 : 0;
    }
    const hkVec4* getVerts() const
    {
        return (this && unk08) ? &unk08->unk20 : 0;
    }
    void FUN_00cb7c60(VertsOut* out);
};

// @fnv 0x00cb7c60
void VertsSource_o2_nood::FUN_00cb7c60(VertsOut* out)
{
    HeapContextScope scope;
    reinterpret_cast<::This *>(this)->FUN_00c84e20((unsigned int *)(out));
    int n = getNumVerts();
    out->unk04.clear();
    out->unk04.SetSizeAndGrow(n);
    const hkVec4* src = getVerts();
    for (int i = 0; i < n; i++)
        out->unk04.m_data[i] = src[i];
}
}

namespace fnv_00cab710 {

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct hkVector4
{
  public:
    __m128 m_vComponents;
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    void set(float a, float b, float c, float d)
    {
        (*this)(0) = a;
        (*this)(1) = b;
        (*this)(2) = c;
        (*this)(3) = d;
    }
};

extern float DAT_01268328;

class bhkSerializable
{
  public:
    bhkSerializable();
    virtual ~bhkSerializable();
    int unk04;
    int unk08;
};

class bhkShape : public bhkSerializable
{
  public:
    bhkShape() : m_0c(0), m_10(0)
    {
        ++::DAT_012680f8;
    }
    int m_0c;
    int m_10;
};

class bhkSphereRepShape : public bhkShape
{
  public:
    bhkSphereRepShape()
    {
        ++::DAT_01268274;
    }
};

class bhkConvexShape : public bhkSphereRepShape
{
  public:
    bhkConvexShape()
    {
        ++::DAT_01268250;
    }
};

class bhkCapsuleShapeCtor : public bhkConvexShape
{
  public:
    bhkCapsuleShapeCtor(const NiPoint3& kPoint1, const NiPoint3& kPoint2, float fRadius);
};

// @fnv 0x00cab710
bhkCapsuleShapeCtor::bhkCapsuleShapeCtor(const NiPoint3& kPoint1, const NiPoint3& kPoint2, float fRadius)
{
    hkVector4 kA;
    kA.set(kPoint1.x * DAT_01268328, kPoint1.y * DAT_01268328, kPoint1.z * DAT_01268328, 0.0f);
    hkVector4 kB;
    kB.set(kPoint2.x * DAT_01268328, kPoint2.y * DAT_01268328, kPoint2.z * DAT_01268328, 0.0f);
    reinterpret_cast<::Owner *>(this)->FUN_00cab0e0((std::intptr_t)&(kA), (std::intptr_t)&(kB), fRadius * DAT_01268328);
}
}


namespace fnv_00cb7d80 {

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t(int value)
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = value;
    }
    ~TlsGuard_t()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};
extern float DAT_011b1cd4;
extern char str_010c8900[];
extern char str_010c88f8[];
extern char str_010c88ec[];


struct NiStrArr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_w08;
    unsigned short m_w0A;
    unsigned short unk0C;
    unsigned short m_w0E;
    void append(char*& text)
    {
        unsigned count = m_w0A;
        if (count >= m_w08)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(count + m_w0E);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(count, (*(char * *)(&text)));
    }
};

struct __declspec(align(16)) StrRec
{
    float x;
    float y;
    float z;
    float w;
};

struct StrNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_uiItemCount;
    int unk14;
    int unk18;
    int unk1C;
    StrRec records[1];
};

struct RecordCollection
{
    unsigned int unk00;
    unsigned int unk04;
    StrNode* m_08;


    void FUN_00cb7d80(NiStrArr* a1);
};

inline float getX(__m128 v)
{
    float r;
    _mm_store_ss(&r, v);
    return r;
}
inline float getY(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_shuffle_ps(v, v, 0x55));
    return r;
}
inline float getZ(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_shuffle_ps(v, v, 0xaa));
    return r;
}
union ScalarString
{
    float value;
    char* text;
};
struct Point
{
    float x, y, z;
    Point()
    {}
    Point(const Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};
inline Point scale(__m128 v, float k)
{
    Point r;
    r.x = getX(v) * k;
    r.y = getY(v) * k;
    r.z = getZ(v) * k;
    return r;
}

// @fnv 0x00cb7d80
void RecordCollection::FUN_00cb7d80(NiStrArr* a1)
{
    TlsGuard_t guard(0x10);
    reinterpret_cast<::FUN_00ca05b0_cls *>(this)->FUN_00ca05b0((::BCA05B0StringArray *)(a1));
    int n;
    {
        char* text = ::FUN_00a7d330((*reinterpret_cast<const char **>(&::g_012683e0)));
        a1->append(text);

        if (this != 0 && m_08 != 0)
        {
            n = m_08->m_uiItemCount;
        }
        else
        {
            n = 0;
        }
        text = ::FUN_00a7d4d0(str_010c8900, n);

        a1->append(text);
    }

    if (this != 0)
    {
        StrNode* node = m_08;
        if (node != 0)
        {
            StrRec* rec = node->records;
            if (rec)
                for (int i = 0; i < n; ++i)
                {
                    __m128 cur = _mm_load_ps(&rec->x);
                    ScalarString scalar;
                    scalar.value = rec->w;
                    Point pt = scale(cur, DAT_011b1cd4);
                    char buf[0x20];
                    ::FUN_00406d00(buf, 0x20, str_010c88f8, i);
                    {
                        char* t2 = reinterpret_cast<::NiPoint3 *>(&(pt))->FUN_00a59af0(buf);
                        a1->append(t2);
                    }
                    ::FUN_00406d00(buf, 0x20, str_010c88ec, i);
                    scalar.text = ::FUN_00a7d550(buf, scalar.value);
                    a1->append(scalar.text);
                    ++rec;
                }
        }
    }
}
}

struct NiAVObject_o2_nood_rtm;

struct NiNode_o2_nood_rtm
{
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};

struct BSTreeNode_o2_nood_rtm : NiNode_o2_nood_rtm
{
    NiAVObject_o2_nood_rtm* GetFirstChild();
};

struct NiAVObject_o2_nood_rtm
{
public:
    void UpdateWorldLoc();
};

struct BSTreeNodeVisibility_o2_nood_rtm : BSTreeNode_o2_nood_rtm
{
    bool FUN_0066bc40(bool);
};

struct FUN_0066d3d0_shell_o2_nood_rtm
{
};

struct BSTreeNodeVisibilityWork_o2_nood_rtm : BSTreeNodeVisibility_o2_nood_rtm
{
    bool SetVisibilityByType(unsigned short type, unsigned char mode);
};

struct FUN_0066b6c0_o2_nood_rtm : S_0066b6c0_Base
{
    NiPointer<NiNode_o2_nood_rtm> spTree0;
    NiPointer<NiNode_o2_nood_rtm>* pArr1;
    NiPointer<NiNode_o2_nood_rtm>* pArr2;
    NiPointer<NiNode_o2_nood_rtm> spTree1;

    virtual ~FUN_0066b6c0_o2_nood_rtm();
};

struct MyObj_o2_nood_rtm
{
    unsigned char unk00[8];
    Inner* m8;
    void FUN_00c8c410(void*);
};

extern float DAT_01268170;

struct S00c880f0_Point3
{
    float x, y, z;
};

struct FloatMatrix3_o2_nood_rtm
{
    float values[9];
};

struct Pose
{
    FloatMatrix3_o2_nood_rtm rotation;
    S00c880f0_Point3 translation;
    float scale;
};

struct S00c880f0_ScalarC880
{
    __m128 r;
    S00c880f0_ScalarC880(float f) : r(_mm_load_ss(&f))
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(r, r, 0);
    }
};

union S00c880f0_VecC880
{
    S00c880f0_VecC880& operator=(const S00c880f0_VecC880& o)
    {
        v = o.v;
        return *this;
    }
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
    void sub(const S00c880f0_VecC880& o)
    {
        v = _mm_sub_ps(v, o.v);
    }
    void scale(const S00c880f0_ScalarC880& f)
    {
        v = _mm_mul_ps(f.splat(), v);
    }
    void plus(const S00c880f0_VecC880& o)
    {
        v = _mm_add_ps(v, o.v);
    }
};

inline void makePosition(S00c880f0_VecC880& result, const S00c880f0_Point3& p)
{
    result.x = p.x * DAT_01268170;
    result.y = p.y * DAT_01268170;
    result.z = p.z * DAT_01268170;
    result.w = 0.0f;
}

struct S00c880f0_Bounds
{
    S00c880f0_VecC880 min, max;
};

struct S00c880f0_Ifc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(S00c880f0_Bounds* out);
};

struct S00c880f0_HolderA
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
    Pose world;
};

struct S00c880f0_Node
{
    int unk00, unk04;
    S00c880f0_Ifc* m_08;
};

struct S00c880f0_Cls
{
    int unk00, unk04;
    S00c880f0_HolderA* m_08;
    unsigned int m_0c;
    S00c880f0_Node* m_10;
    void FUN_00c880f0();
};

struct S00c880f0_LockObj
{
};

// @fnv 0x00c880f0
void S00c880f0_Cls::FUN_00c880f0()
{
    S00c880f0_HolderA* a = m_08;
    S00c880f0_Node* b = m_10;
    if (a)
    {
        reinterpret_cast<::NiAVObject_o2_nood_rtm *>((a))->UpdateWorldLoc();
        if (b)
        {
            S00c880f0_Ifc* c = b->m_08;
            if (c)
            {
                Pose pose = a->world;
                S00c880f0_VecC880 position;
                S00c880f0_Bounds out;
                c->v18(&out);
                out.max.sub(out.min);
                out.max.scale(S00c880f0_ScalarC880(0.5f));
                out.min = out.max;
                out.min.scale(S00c880f0_ScalarC880(-1.0f));
                makePosition(position, pose.translation);
                out.min.plus(position);
                out.max.plus(position);
                reinterpret_cast<::FUN_0040fbf0_shell *>((reinterpret_cast<S00c880f0_LockObj*>(&(*reinterpret_cast<int *>(&::DAT_01267b80)))))->FUN_0040fbf0((char *)(0));
                S00c880f0_Ifc* item = b->m_08;
                if (item)
                {
                    ::FUN_00a29680();
                    reinterpret_cast<::PhantomBounds *>((item))->FUN_00cf24a0((*(const ::hkAabb *)(&out)));
                    ::FUN_00a29680();
                }
                if (--DAT_01267b84 == 0)
                    (*reinterpret_cast<int *>(&::DAT_01267b80)) = 0;
            }
        }
    }
}

struct NiNode_o2
{
};

struct BSTreeNode_o2 : NiNode_o2
{
    NiAVObject* GetFirstChild();
};

struct FUN_0066d520_shell_o2
{
    void FUN_00cb78b0_o2();
    void* FUN_0066d520(unsigned int flags);
};

struct NiStream;

struct HC1Base
{
    bool FUN_00aa0ad0(NiStream*);
};

struct VirtCls
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
    virtual void Target(NiStream*);
};

struct Mid8
{
    char _0[8];
    VirtCls* p8;
};

struct Mid14
{
    char _0[20];
    Mid8* p14;
};

struct S_00c8c390
{
    char _0[8];
    Mid14* p8;
    bool FUN_00c8c390(NiStream*);
};

// @fnv 0x00c8c390
bool S_00c8c390::FUN_00c8c390(NiStream* arStream)
{
    if (this)
    {
        Mid14* v1 = p8;
        if (v1)
        {
            Mid8* v2 = v1->p14;
            if (v2)
            {
                VirtCls* v3 = v2->p8;
                if (v3)
                    v3->Target(arStream);
            }
        }
    }
    return ((HC1Base*)this)->FUN_00aa0ad0(arStream);
}

struct S_00c8c810_A
{
    int _0;
    volatile long _ref;
};

struct S_00c8c810_B
{
    char _p[8];
    S_00c8c810_A* p;
};

struct S_00c8c810_C
{
    char _p[20];
    S_00c8c810_B* p;
};

struct H_00c8c810
{
    char _p[8];
    S_00c8c810_C* p;
    void FUN_00c8c770();
    void FUN_00c8c810(bool);
};

// @fnv 0x00c8c810
void H_00c8c810::FUN_00c8c810(bool b)
{
    if (b)
    {
        if (this && p && p->p && p->p->p)
        {
            InterlockedIncrement(&p->p->p->_ref);
            reinterpret_cast<::bhkBoxShape *>(this)->FUN_00c84e50(b);
            return;
        }
    }
    else
    {
        FUN_00c8c770();
    }
    reinterpret_cast<::bhkBoxShape *>(this)->FUN_00c84e50(b);
}

struct Buf00cb7750
{
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
};

struct Inner00cb7750
{
    int _00;
    int _04;
    int m_08;
};

struct S00cb7750
{
    virtual void a00()
    {}
    virtual void a01()
    {}
    virtual void a02()
    {}
    virtual void a03()
    {}
    virtual void a04()
    {}
    virtual void a05()
    {}
    virtual void a06()
    {}
    virtual void a07()
    {}
    virtual void a08()
    {}
    virtual void a09()
    {}
    virtual void a10()
    {}
    virtual void a11()
    {}
    virtual void a12()
    {}
    virtual void a13()
    {}
    virtual void a14()
    {}
    virtual void a15()
    {}
    virtual void a16()
    {}
    virtual void a17()
    {}
    virtual void a18()
    {}
    virtual void a19()
    {}
    virtual void a20()
    {}
    virtual void a21()
    {}
    virtual void a22()
    {}
    virtual void a23()
    {}
    virtual void a24()
    {}
    virtual void a25()
    {}
    virtual void a26()
    {}
    virtual void a27()
    {}
    virtual void a28()
    {}
    virtual void a29()
    {}
    virtual void a30()
    {}
    virtual void a31()
    {}
    virtual void a32()
    {}
    virtual void a33()
    {}
    virtual void a34()
    {}
    virtual void a35()
    {}
    virtual void a36()
    {}
    virtual void a37()
    {}
    virtual void a38()
    {}
    virtual void a39()
    {}
    virtual void a40()
    {}
    virtual void a41()
    {}
    virtual void a42()
    {}
    virtual void a43()
    {}
    virtual void a44()
    {}
    virtual void a45()
    {}
    virtual void f46(Buf00cb7750*)
    {}
    int _04;
    int _08;
    int _0C;
    Inner00cb7750* m_10;
    void FUN_00cb7750();
};

// @fnv 0x00cb7750
void S00cb7750::FUN_00cb7750()
{
    if (m_10 && m_10->m_08)
    {
        Buf00cb7750 b;
        ::FUN_00c9ec60((::NiTransformC9E *)(m_10));
        f46(&b);
    }
}

struct BSFadeNode
{
    void* vf;
    char pad[16];
    BSFadeNode()
    {
        FUN_00c6b910(this);
        vf = (void*)&DAT_01066b94;
    }
};

// @fnv 0x00c87fc0
BSFadeNode* FUN_00c87fc0()
{
    return new BSFadeNode;
}

namespace fnv_00cb7640 {
struct BSFadeNode
{
};
struct NewObjA : BSFadeNode
{
    int a;
    int b;
    int c;
    int d;
    int e;
    NewObjA()
    {
        ::FUN_00c6b910(this);
        *(void**)this = &::DAT_01066acc;
    }
};
// @fnv 0x00cb7640
void* FUN_00cb7640()
{
    return new NewObjA;
}
}

// namespace fnv_00cb7640

struct Middle
{
    int unk00;
    int unk04;
    unsigned int value;
};

struct This_o2
{
    int unk00;
    int unk04;
    Middle* middle;
    void FUN_00c84e20(unsigned int* output);
};

// @fnv 0x00c84e20
void This_o2::FUN_00c84e20(unsigned int* output)
{
    *output = (this != 0 && middle != 0) ? middle->value : 0;
}

struct NiObject;

struct NiStream
{
    int unk00;
    unsigned int version;
public:
    ::NiObject *GetLoadedObject();
};

struct NiStream;

struct NiCollisionObject
{
    void LinkObject(NiStream&);
public:
    void LoadBinary(::NiStream &);
};

struct LegacyLinker : NiCollisionObject
{
    void FUN_00c87f80(NiStream*);
};

// @fnv 0x00c87f80
void LegacyLinker::FUN_00c87f80(NiStream* stream)
{
    if (stream->version >= 0x15)
        reinterpret_cast<::fnv_00c6bb70::bhkNiCollisionObject *>(this)->FUN_00c6bb70((*(::fnv_00c6bb70::NiStream *)(stream)));
    else
        NiCollisionObject::LinkObject(*stream);
}

struct C8C330Source
{
    int unk00;
    int unk04;
    int m_uiFilterValue;
};

struct C8C330Node
{
};

struct C8C330Child
{
    int unk00;
    int m_uiFilterValue;
};

struct C8C330Owner
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual C8C330Child* GetOrCreateChild(bool* pbCreated);

    void FUN_00c8c330(C8C330Node* pkNode);
};

// @fnv 0x00c8c330
void C8C330Owner::FUN_00c8c330(C8C330Node* pkNode)
{
    bool bCreated;
    C8C330Child* pkChild = GetOrCreateChild(&bCreated);
    C8C330Source* pkSource = ((::C8C330Source *)(reinterpret_cast<::NiStream *>((pkNode))->GetLoadedObject()));
    pkChild->m_uiFilterValue = pkSource ? pkSource->m_uiFilterValue : 0;
    ::FUN_00c84cc0((int *)this, (std::uintptr_t)(pkNode));
}

typedef unsigned int C8CA60size_t;

struct C8CA60MemoryManager
{
};

struct C8CA60AllocTagScope
{
    int m_iSaved;

    C8CA60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = aiAllocationTag;
    }
    ~C8CA60AllocTagScope()
    {
        ::g_tlsBlock.memoryContext = m_iSaved;
    }
};

inline void* C8CA60AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::C8CA60MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(std::uintptr_t)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}

struct C8CA60Child
{
    C8CA60Child();

};

struct C8CA60Owner
{
    int unk00;
    int unk04;
    void* m_pParentNode;
    C8CA60Child* m_pkChild;

    C8CA60Child* FUN_00c8ca60(bool* pbCreated);
};

// @fnv 0x00c8ca60
C8CA60Child* C8CA60Owner::FUN_00c8ca60(bool* pbCreated)
{
    C8CA60AllocTagScope kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (*pbCreated)
    {
        m_pkChild = new (C8CA60AlignedAlloc(0x60)) C8CA60Child();
        if (m_pParentNode)
            reinterpret_cast<::MyObj *>(this)->FUN_00c8c410(m_pkChild);
    }
    return m_pkChild;
}

struct StrArr
{
    void* unk00;
    char** data;
    unsigned short capacity, size, live, growBy;
    void append(char* const& text)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + growBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (char *&)(text));
    }
};

struct NiPoint3_o2
{
    float x, y, z;
    char* FUN_00a59af0(const char*);
};

class NiTransform
{
  public:
    float rotation[9];
    NiPoint3_o2 translate;
    float scale;
};

struct NativeTransform
{
    float rotation[12];
    float translation[4];
};

struct AutoMemContext_o2
{
    unsigned int ePreviousContext;
    AutoMemContext_o2()
    {
        ePreviousContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~AutoMemContext_o2()
    {
        ::g_tlsBlock.memoryContext = ePreviousContext;
    }
};

struct Component
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
    virtual void serialize(StrArr*);
};

struct Holder_o2
{
    unsigned int unk00, unk04;
    Component* component;
};

struct State
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Holder_o2* holder;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    NativeTransform world;
};

struct Object
{
    unsigned int unk00, unk04;
    State* state;
    void FUN_00c8cb20(StrArr*);
    Component* getComponent()
    {
        if (this)
        {
            State* current = state;
            if (current)
            {
                Holder_o2* holder = current->holder;
                if (!holder)
                    return 0;
                return holder->component;
            }
            return 0;
        }
        return 0;
    }
};

// @fnv 0x00c8cb20
void Object::FUN_00c8cb20(StrArr* output)
{
    AutoMemContext_o2 task;
    reinterpret_cast<::ShapeViewerFields *>(this)->FUN_00c851c0((::BCA05B0StringArray *)(output));
    output->append(::FUN_00a7d330((const char *)(*(void**)&g_012681b4)));
    const NativeTransform* world = this && state ? &state->world : &(*reinterpret_cast<::NativeTransform *>(&::DAT_01268370));
    NiTransform transform;
    ::FUN_00624b10((::FUN_004769c0_shell *)(::NiTransform *)(&transform), (::FUN_004b4cf0_shell *)(::NiPoint3_o2 *)((NiPoint3_o2*)world));
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&transform.translate)), (*(const ::hkVector4 *)(world->translation)));
    output->append(transform.translate.FUN_00a59af0("Trans"));
    output->append(reinterpret_cast<::FloatMatrix3 *>(&(transform))->ToString("Rot"));
    Component* component = getComponent();
    if (component)
        component->serialize(output);
}

struct CB7800RTTI
{
    const char* m_pcName;
    const CB7800RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

struct CB7800StringArray
{
    virtual ~CB7800StringArray();

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;


    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct CB7800AllocTagScope
{
    int m_iSaved;

    CB7800AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = aiAllocationTag;
    }
    ~CB7800AllocTagScope()
    {
        ::g_tlsBlock.memoryContext = m_iSaved;
    }
};

struct CB7800Base
{
};

struct CB7800Object : CB7800Base
{

    void FUN_00cb7800(CB7800StringArray* pkStrings);
};

struct S_00cb78b0_Base
{
    virtual ~S_00cb78b0_Base();
};

struct FUN_00cb78b0_o2 : S_00cb78b0_Base
{
    virtual ~FUN_00cb78b0_o2();
};

// @fnv 0x00cb78b0
FUN_00cb78b0_o2::~FUN_00cb78b0_o2()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --(*reinterpret_cast<int *>(&::DAT_012683dc));
}

struct S_00cb79d0_Base
{
    S_00cb79d0_Base();
    virtual void v00();
    int unk04;
    int unk08;
};

struct S_00cb79d0_A : S_00cb79d0_Base
{
    int unk0C;
    int unk10;
    S_00cb79d0_A()
    {
        unk0C = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
    virtual void v00();
};

struct S_00cb79d0_B : S_00cb79d0_A
{
    S_00cb79d0_B()
    {
        DAT_01268274++;
    }
    virtual void v00();
};

struct S_00cb79d0_C : S_00cb79d0_B
{
    S_00cb79d0_C()
    {
        (*reinterpret_cast<int *>(&::DAT_012683dc))++;
    }
    virtual void v00();
};

struct S_00cb79d0
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049(S_00cb79d0_Base* obj, int arg);
    S_00cb79d0_C* FUN_00cb79d0(int arg);
};

// @fnv 0x00cb79d0
S_00cb79d0_C* S_00cb79d0::FUN_00cb79d0(int arg)
{
    FUN_00c876f0();
    S_00cb79d0_C* obj = new S_00cb79d0_C;
    v049(obj, arg);
    FUN_00c87700();
    return obj;
}

struct Vector3
{
    float x;
    float y;
    float z;
};

// @fnv 0x00cf0930
void __cdecl FUN_00cf0930(void* buffer, std::intptr_t bytes, Vector3* vector)
{
    int words = bytes / 4;
    ::SwapByteQuadWords((::Vector4f *)(buffer), words);
    char savedBytes[sizeof(Vector3)];
    Vector3* saved = reinterpret_cast<Vector3*>(savedBytes);
    *saved = *vector;
    ::SwapByteQuadWords((::Vector4f *)(buffer), words);
    *vector = *saved;
}



struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }

    ~TlsGuard_t()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

struct FUN_00c88210_cls
{
    BSFadeNode* FUN_00c88210(std::uintptr_t flags);
};

// @fnv 0x00c88210
BSFadeNode* FUN_00c88210_cls::FUN_00c88210(std::uintptr_t flags)
{
    TlsGuard_t guard;
    BSFadeNode* node = new BSFadeNode;
    reinterpret_cast<::OwnerProxy *>((this))->FUN_00c6ba30((::OwnerProxy *)(node), (::CloneProcess *)(flags));
    return node;
}

struct BC882C0AllocTagScope
{
    int m_iSaved;

    BC882C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = aiAllocationTag;
    }
    ~BC882C0AllocTagScope()
    {
        ::g_tlsBlock.memoryContext = m_iSaved;
    }
};

class BC882C0StringArray
{
  public:
    virtual ~BC882C0StringArray();

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

class FUN_00c882c0_cls
{
  public:
    void FUN_00c882c0(BC882C0StringArray* pkArray);
};

// @fnv 0x00cb7800
void CB7800Object::FUN_00cb7800(CB7800StringArray* pkStrings)
{
    CB7800AllocTagScope kScope(0x10);
    reinterpret_cast<::FUN_00c882c0_cls *>(this)->FUN_00c882c0((::BC882C0StringArray *)(pkStrings));
    char* pcString = ::FUN_00a7d330((*reinterpret_cast<::CB7800RTTI *>(&::g_012683d0)).GetName());
    pkStrings->Add(pcString);
}

// @fnv 0x00c882c0
void FUN_00c882c0_cls::FUN_00c882c0(BC882C0StringArray* pkArray)
{
    BC882C0AllocTagScope kScope(0x10);
    reinterpret_cast<::ViewerCollision *>(this)->AppendDebugInfo((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(pkArray));
    char* pcName = ::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268168)));
    pkArray->Add(pcName);
}

struct ScaleMatrix
{
    float m00;
    float m04;
    float m08;
    float m0c;
    float m10;
    float m14;
    float m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    float m2c;
};

struct SourceObject
{
    int m00;
    int m04;
    int m08;
    int m0c;
    float scale;
};

struct FUN_00caaea0_shell
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual ScaleMatrix* getMatrix(bool* outFlag) = 0;
    void FUN_00caaea0(void* context, SourceObject* source);
};

// @fnv 0x00caaea0
void FUN_00caaea0_shell::FUN_00caaea0(void* context, SourceObject* source)
{
    bool flag;
    ScaleMatrix* matrix = getMatrix(&flag);
    float scale = source->scale;
    if (scale != 1.0f)
    {
        matrix->m10 *= scale;
        matrix->m14 *= scale;
        matrix->m18 *= scale;
        matrix->m1c *= scale;
        matrix->m20 *= scale;
        matrix->m24 *= scale;
        matrix->m28 *= scale;
        matrix->m2c *= scale;
        matrix->m04 *= scale;
    }
    reinterpret_cast<::FUN_00c84df0_cls *>(this)->FUN_00c84df0((::FUN_00c84df0_cls *)(context), (::FUN_00c84df0_cls *)(source));
}



struct S_00caaf40_Ctx
{
    int saved;
    __forceinline S_00caaf40_Ctx(int c)
    {
        saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = c;
    }
    __forceinline ~S_00caaf40_Ctx()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};

struct S_00caaf40_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00caaf40_Obj();
};

struct S_00caaf40
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4(S_00caaf40_Obj* o, int a);
    S_00caaf40_Obj* FUN_00caaf40(int a);
};

// @fnv 0x00caaf40
S_00caaf40_Obj* S_00caaf40::FUN_00caaf40(int a)
{
    S_00caaf40_Ctx ctx(0x10);
    FUN_00c876f0();
    S_00caaf40_Obj* o = new S_00caaf40_Obj;
    vfn_c4(o, a);
    FUN_00c87700();
    return o;
}

namespace fnv_00cab000 {
// FUN_00cab000 - bhkCapsuleShape::FUN_00cab000 (vtable slot 46 of .?AVbhkCapsuleShape@@)
//
// The function is a member with one 4-byte stack argument (a bool* out flag).
// It runs under the per-thread recursion guard that lives in the thread-local block at
// offset +0x2b4, allocates a 0x30 byte object from the memory manager on first use,
// fills in the object's matrix area and then hands the object to FUN_00caade0.

// ---------------------------------------------------------------------------
// The thread-local block.  Only the guard word at +0x2b4 is touched; the rest of
// the block is padding so that the guard word sits at its original offset.
// ---------------------------------------------------------------------------


// The recursion guard: remember the old guard word, then mark the slot busy.
// The compiler keeps the guard word in a frame slot and restores it in the
// destructor, which is also what produces the exception-handling frame.
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }

    ~TlsGuard_t()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

// ---------------------------------------------------------------------------
// The memory manager that hands out the object's memory.
// ---------------------------------------------------------------------------
struct MemoryManager
{
};


// The game's default radius (0.1f) lives in this float table.

// ---------------------------------------------------------------------------
// The 0x30 byte object that is allocated on first use.
// The eight matrix floats at +0x10 are volatile because the original initialiser
// writes the whole matrix area and then rewrites part of it: a plain store that
// is overwritten later is deleted by the optimiser, a volatile one is kept.
// ---------------------------------------------------------------------------
struct BhkAllocObj
{
    int unk00;
    float unk04;
    int unk08;
    int unk0c;
    volatile float unk10;
    volatile float unk14;
    volatile float unk18;
    volatile float unk1c;
    volatile float unk20;
    volatile float unk24;
    volatile float unk28;
    volatile float unk2c;
};

// ---------------------------------------------------------------------------
// The shape itself.
// ---------------------------------------------------------------------------
struct BhkCap_00cab000
{
    int unk00;
    int unk04;
    int unk08;
    std::intptr_t unk0c;
    std::intptr_t FUN_00cab000(bool* out);
};

// @fnv 0x00cab000
std::intptr_t BhkCap_00cab000::FUN_00cab000(bool* out)
{
    TlsGuard_t guard;

    bool b = (unk0c == 0);
    *out = b;
    if (b)
    {
        BhkAllocObj* p = (BhkAllocObj*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00cab000::MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(0x30);
        if (p)
        {
            p->unk00 = 0;
            p->unk04 = (*reinterpret_cast<float (*)[]>(&::DAT_010c72bc))[0];
            p->unk10 = 0.0f;
            p->unk14 = 0.0f;
            p->unk18 = 0.0f;
            p->unk1c = 0.0f;
            p->unk20 = 0.0f;
            p->unk24 = 0.0f;
            p->unk28 = 0.0f;
            p->unk2c = 0.0f;
            p->unk20 = 1.0f;
            p->unk24 = 0.0f;
            p->unk28 = 0.0f;
            p->unk2c = 0.0f;
        }
        else
        {
            p = 0;
        }
        unk0c = (std::intptr_t)p;
        if (unk08 != 0)
        {
            reinterpret_cast<::bhkLimitedHingeConstraint *>(this)->PopulateOutput((::bhkLimitedHingeOutput *)(p));
        }
    }
    return unk0c;
}
}

// namespace fnv_00cab000

struct AudioTlsState_o2
{
    char* GetBlock();
};

struct MemoryContext
{
    int unk2b4;
};

struct ScopedContext
{
    int old;
    ScopedContext(int value)
    {
        old = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = value;
    }
    ~ScopedContext()
    {
        ::g_tlsBlock.memoryContext = old;
    }
};

struct Pool
{
    virtual void f00();
    virtual void* Alloc(unsigned int size);
};

struct Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Pool* unk10;
    void* Alloc(unsigned int size)
    {
        return unk10->Alloc(size);
    }
};


struct FUN_00d22590
{
    int unk00;
    short unk04;
    short unk06;
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
    FUN_00d22590(int a, int b, float c);
    static void* operator new(std::size_t size)
    {
        FUN_00d22590* p = (FUN_00d22590*)((Heap *)::FUN_00c85750())->Alloc(size);
        p->unk04 = (short)size;
        return p;
    }
    static void operator delete(void* p);
};

struct Owner_o2
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
    virtual void AddElement(FUN_00d22590* e);
    void FUN_00cab0e0(int a, int b, float c);
};

// @fnv 0x00cab0e0
void Owner_o2::FUN_00cab0e0(int a, int b, float c)
{
    ScopedContext scope(0x10);
    FUN_00d22590* e = new FUN_00d22590(a, b, c);
    AddElement(e);
    reinterpret_cast<::hkReferencedObjectC905 *>((e))->FUN_00c905b0();
}

namespace fnv_00cab8c0 {

struct S_00cab8c0_Ctx
{
    int saved;
    __forceinline S_00cab8c0_Ctx(int c)
    {
        saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = c;
    }
    __forceinline ~S_00cab8c0_Ctx()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};
struct S_00cab8c0_Arr
{
    int unk00;
    int unk04;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short unk0c;
    unsigned short m_grow;
};
struct S_00cab8c0_Owner
{
    void FUN_00cab8c0(S_00cab8c0_Arr* a);
};
// @fnv 0x00cab8c0
void S_00cab8c0_Owner::FUN_00cab8c0(S_00cab8c0_Arr* a)
{
    S_00cab8c0_Ctx guard(0x10);
    reinterpret_cast<::SphereShape *>(this)->FUN_00c9fc50((::ViewerStringArray *)(a));
    char* s = ::FUN_00a7d330((*reinterpret_cast<const char **>(&::g_0126832c)));
    unsigned idx = a->m_uiItemCount;
    if (idx >= a->m_iElementCount)
        reinterpret_cast<::ViewerStrings *>((a))->SetSize(idx + a->m_grow);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((a))->SetAt(idx, (char *&)(s));
}
}

// namespace fnv_00cab8c0

namespace fnv_00cb76a0 {


struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }

    ~TlsGuard_t()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};


struct SpawnedFade
{
    void* vf;
    char pad[16];

    SpawnedFade()
    {
        FUN_00c6b910(this);
        vf = (void*)&::DAT_01066acc;
    }
};

struct FUN_00cb76a0_cls
{
    void* FUN_00cb76a0(unsigned int arg);
};

// @fnv 0x00cb76a0
void* FUN_00cb76a0_cls::FUN_00cb76a0(unsigned int arg)
{
    TlsGuard_t guard;
    SpawnedFade* obj = new SpawnedFade;
    ::FUN_00c657f0();
    return obj;
}
}

// namespace fnv_00cb76a0

struct FUN_00cb7790_node
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    Buf00cb7750 transform;
};

struct FUN_00cb7790_receiver
{
    unsigned int unk00;
    unsigned int unk04;
    void* object;
};

struct FUN_00cb7790_state
{
    unsigned int owner;
    unsigned int depth;
};

struct FUN_00cb7790_class
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cb7790_node* node;
    unsigned int unk0C;
    FUN_00cb7790_receiver* receiver;
    void FUN_00cb7790();
};

// @fnv 0x00cb7790
void FUN_00cb7790_class::FUN_00cb7790()
{
    FUN_00cb7790_receiver* target = receiver;
    FUN_00cb7790_node* source = node;
    if (source)
    {
        reinterpret_cast<::NiAVObject *>((source))->UpdateWorldLoc();
        if (target && target->object)
        {
            Buf00cb7750 transform = source->transform;
            reinterpret_cast<::FUN_0040fbf0_shell *>(&(DAT_01267b80))->FUN_0040fbf0((char *)(0));
            reinterpret_cast<::FUN_0056df20_Class *>((target))->FUN_0056df20((*(const ::NiTransform *)(&transform)));
            if (--DAT_01267b80.depth == 0)
                DAT_01267b80.owner = 0;
        }
    }
}

// FUN_00cb7920 - factory for a bhkMultiSphereShape.
//
// The shape is allocated with the class' own operator new, the base
// constructor is run on it and the vtable pointer of the object is moved
// through the vtables of the whole class chain while the per class instance
// counters are bumped.  A guard object keeps the raw pointer alive so that
// the memory is released again if the construction throws.

struct VTable
{
    void* entries[1];
};

static void g_vtblDummy()
{}

// The vtables of the three class levels the shape is built from.
static const VTable g_vtblShape = {{(void*)&g_vtblDummy}};

static const VTable g_vtblSphereRep = {{(void*)&g_vtblDummy}};

static const VTable g_vtblMultiSphere = {{(void*)&g_vtblDummy}};

// Live instance counters of the three class levels.
static volatile int g_nShape;

static volatile int g_nSphereRep;

static volatile int g_nMultiSphere;

struct Node
{
    void* vf;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

// Releases the raw shape again when the construction throws.
struct Guard
{
    void* p;
    Guard(void* q) : p(q)
    {}
    ~Guard()
    {
        p = 0;
    }
};

void* __cdecl opnew(unsigned int);

void __cdecl opdelete(void*);

// @fnv 0x00cb7920
Node* FUN_00cb7920()
{
    Node* p = (Node*)opnew(0x14);
    {
        Guard g(p);
        if (p)
        {
            reinterpret_cast<::FUN_00c87c30_t *>((p))->FUN_00c87c30();
            p->vf = (void*)&g_vtblShape;
            p->m_0c = 0;
            p->m_10 = 0;
            ++g_nShape;
            p->vf = (void*)&g_vtblSphereRep;
            ++g_nSphereRep;
            p->vf = (void*)&g_vtblMultiSphere;
            ++g_nMultiSphere;
            return p;
        }
        return 0;
    }
}

struct Shader
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
    virtual int f42();
    virtual void f43();
    virtual void f44();
    virtual int* f45(struct Pass** pass);
    void FUN_00cb7b20(struct Pass* pass);
};

struct Pass
{
    int unk000;
    char unk004;
    char pad005[0x1e5 - 0x5];
    char cUnk1e5;
};

// @fnv 0x00cb7b20
void Shader::FUN_00cb7b20(Pass* pass)
{
    Pass* p = pass;
    reinterpret_cast<::FUN_00c84d00_cls *>(this)->FUN_00c84d00((::FUN_00c84d00_obj *)(p));
    int* data = f45(&pass);
    if (p->cUnk1e5 != 1)
    {
        int r = f42();
        ::FUN_00cf0930(data, r, (::Vector3 *)(int *)(data + 1));
    }
    ::FUN_00cf0f40((::S00cf0f40_Owner *)(p), (::S00cf0f40_Arr *)(int *)(data + 1));
}

namespace fnv_00cb7b80 {



struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }
    ~TlsGuard()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

struct SpawnArgs
{
    int unk00;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
};

struct SpawnAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};

struct SpawnHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAllocator* m_alloc;
};

struct SpawnedNode
{
    void* m_vtbl;
    unsigned short m_iElementCount;
    unsigned short unk06;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    SpawnedNode(unsigned int a, unsigned int b);
    static void operator delete(void* p) throw()
    {}
    static void* operator new(std::size_t size) throw()
    {
        SpawnHolder* h = (SpawnHolder*)::FUN_00c85750();
        void* p = h->m_alloc->Alloc(size);
        ((SpawnedNode*)p)->m_iElementCount = (unsigned short)size;
        return p;
    }
};

struct FUN_00cb7b80_cls_o2
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
    virtual void v35(SpawnedNode* n);
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
    virtual void v47(SpawnArgs* a);
    void FUN_00cb7b80(SpawnArgs* a);
};

// @fnv 0x00cb7b80
void FUN_00cb7b80_cls_o2::FUN_00cb7b80(SpawnArgs* a)
{
    TlsGuard guard;
    unsigned int b, c;
    SpawnedNode* n = new SpawnedNode(c = a->m_kPointA, b = a->m_kPointB);
    this->v35(n);
    reinterpret_cast<::hkReferencedObjectC905 *>((n))->FUN_00c905b0();
    this->v47(a);
}
}

// namespace fnv_00cb7b80

namespace fnv_00cb8150 {
struct BSAudio;

struct CbAlloc8150
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct BSAudio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CbAlloc8150* m_pAllocator;
};

struct CbArr8150
{
    int unk00;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    CbArr8150() : unk00(0), m_pData(0), m_iArrayLength(0), m_uCapBits(0x80000000u)
    {}
    ~CbArr8150()
    {
        BSAudio* pHolder = ((BSAudio *)::FUN_00c85750());
        CbAlloc8150* pAllocator = pHolder->m_pAllocator;
        m_iArrayLength = 0;
        unsigned int uCapBits = m_uCapBits;
        if ((uCapBits & 0x80000000u) == 0)
        {
            pAllocator->FreeArray(m_pData, (uCapBits & 0x3fffffffu) * 16);
        }
        m_pData = 0;
        m_uCapBits = 0x80000000u;
    }
};


struct FUN_00cb8150_cls
{
    int unk00;

    unsigned char FUN_00cb8150(void* a1);
};

// @fnv 0x00cb8150
unsigned char FUN_00cb8150_cls::FUN_00cb8150(void* a1)
{
    FUN_00cb8150_cls* other = (FUN_00cb8150_cls*)a1;
    unsigned char r = ((unsigned char)(reinterpret_cast<::FUN_00c84dc0_cls *>((a1))->FUN_00c84dc0({})));
    if (r != 0)
    {
        CbArr8150 a;
        CbArr8150 b;
        reinterpret_cast<::fnv_00cb7c60::VertsSource *>((this))->FUN_00cb7c60((::fnv_00cb7c60::VertsOut *)(::fnv_00cb8150::CbArr8150 *)(&a));
        reinterpret_cast<::fnv_00cb7c60::VertsSource *>((other))->FUN_00cb7c60((::fnv_00cb7c60::VertsOut *)(::fnv_00cb8150::CbArr8150 *)(&b));
        r = ((unsigned char)(::FUN_00cf08c0((const ::FUN_00cf08c0_VectorArray *)(int *)((int*)&a.m_pData), (const ::FUN_00cf08c0_VectorArray *)(void **)((void**)&b.m_pData))));
    }
    return r;
}
}

// namespace fnv_00cb8150

namespace fnv_00cb8330 {


struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }
    ~TlsGuard()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

struct S_00cb8330_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int bytes) throw();
};
struct S_00cb8330_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cb8330_Heap* m_pStreamAllocator;
    S_00cb8330_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb8330_Pool
{
};
struct S_00cb8330_Obj
{
    int unk00;
    void* m_data;
    int m_iElementCount;
    int m_cap;
};
struct S_00cb8330_cls
{
    int unk00;
    int unk04;
    int unk08;
    S_00cb8330_Obj* m_0c;
    void FUN_00cb8330(bool bFree);
};
// @fnv 0x00cb8330
void S_00cb8330_cls::FUN_00cb8330(bool bFree)
{
    TlsGuard guard;
    if (bFree)
    {
        S_00cb8330_Obj* p = m_0c;
        if (p)
        {
            S_00cb8330_Heap& h = ((S_00cb8330_Router *)::FUN_00c85750())->heap();
            int cap = p->m_cap;
            p->m_iElementCount = 0;
            if ((cap & 0x80000000) == 0)
                h.v10(p->m_data, (cap & 0x3fffffff) * 16);
            p->m_data = 0;
            p->m_cap = 0x80000000;
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00cb8330::S_00cb8330_Pool *>(&::g_memoryManager))))->FUN_00aa4060(p);
        }
        m_0c = 0;
    }
}
}

// namespace fnv_00cb8330

struct A1Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char m1E4;
};

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

struct Triple
{
    unsigned int m00;
    unsigned int m04;
    unsigned int m08;
};

struct OwnerB
{
    unsigned int unk00;
    Triple m04;
};

struct TmpGuard
{
    std::uintptr_t m0;
    unsigned int m1;
    unsigned int m2;

    TmpGuard()
    {
        m0 = 0;
        m1 = 0;
        m2 = 0x80000000;
    }
    ~TmpGuard()
    {
        AudioHolder* pHolder = reinterpret_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        m1 = 0;
        if ((m2 & 0x80000000u) == 0)
        {
            pAllocator->Free((void*)m0, (m2 & 0x3fffffffu) * 16u);
        }
    }
};

struct FUN_00cb8010_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void v41(unsigned int a);
    virtual void* v42();
    virtual void vAC();
    virtual void vB0();
    virtual OwnerB* v45(unsigned char* pFlag);

    void FUN_00cb8010(A1Owner* a1);
};

// @fnv 0x00cb8010
void FUN_00cb8010_cls::FUN_00cb8010(A1Owner* a1)
{
    unsigned int flagSlot;
    OwnerB* p = this->v45((unsigned char*)&flagSlot);
    TmpGuard tmp;
    Triple* src = &p->m04;
    unsigned int s0 = src->m00;
    tmp.m0 = s0;
    src->m00 = 0;
    unsigned int t1 = tmp.m1;
    unsigned int s1 = src->m04;
    tmp.m1 = s1;
    src->m04 = t1;
    unsigned int t2 = tmp.m2;
    unsigned int s2 = src->m08;
    tmp.m2 = s2;
    src->m08 = t2;

    if (a1->m1E4 != 1)
    {
        void* r = this->v42();
        ::FUN_00cf0930(p, (std::intptr_t)(r), (::Vector3 *)(void *)(&p->m04));
    }
    reinterpret_cast<::FUN_00c84d50_cls *>((this))->FUN_00c84d50(a1);
    ::FUN_00cf0cf0((::S00cf0cf0_Obj *)(a1), (::S00cf0cf0_Arr *)(void *)(&tmp));
    this->v41(flagSlot);
    if (*(unsigned char*)&flagSlot == 0 && a1->m1E4 != 1)
    {
        void* r = this->v42();
        ::FUN_00cf0930(p, (std::intptr_t)(r), (::Vector3 *)(void *)(&p->m04));
    }
}

struct CTarget
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual bool vf0D0(int value);
};

struct CLevel2
{
    int unk00;
    int unk04;
    CTarget* unk08;
};

struct CLevel1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    CLevel2* unk14;
};

struct CObj
{
    int unk00;
    int unk04;
    CLevel1* unk08;

    bool FUN_00c8c3d0(std::intptr_t value);
};

inline bool Walk(CObj* o, int v, bool r)
{
    if (o)
    {
        CLevel1* l = o->unk08;
        if (l)
        {
            CLevel2* l2 = l->unk14;
            if (l2)
            {
                CTarget* t = l2->unk08;
                if (t)
                    r = t->vf0D0(v);
            }
        }
    }
    return r;
}

// @fnv 0x00c8c3d0
bool CObj::FUN_00c8c3d0(std::intptr_t value)
{
    bool r = ((bool)(::FUN_00c84ec0((void*)value)));
    if (r)
        r = Walk(this, value, r);
    return r;
}


// @fnv 0x00c8c020
void __cdecl FUN_00c8c020(unsigned int* apData)
{
    *(volatile unsigned int*)&apData[0] = _byteswap_ulong(*(volatile unsigned int*)&apData[0]);
    *(volatile unsigned int*)&apData[1] = _byteswap_ulong(*(volatile unsigned int*)&apData[1]);
    *(volatile unsigned int*)&apData[2] = _byteswap_ulong(*(volatile unsigned int*)&apData[2]);
    *(volatile unsigned int*)&apData[3] = _byteswap_ulong(*(volatile unsigned int*)&apData[3]);
    *(volatile unsigned int*)&apData[4] = _byteswap_ulong(*(volatile unsigned int*)&apData[4]);
    *(volatile unsigned int*)&apData[5] = _byteswap_ulong(*(volatile unsigned int*)&apData[5]);
    *(volatile unsigned int*)&apData[6] = _byteswap_ulong(*(volatile unsigned int*)&apData[6]);
    *(volatile unsigned int*)&apData[7] = _byteswap_ulong(*(volatile unsigned int*)&apData[7]);
    *(volatile unsigned int*)&apData[8] = _byteswap_ulong(*(volatile unsigned int*)&apData[8]);
    *(volatile unsigned int*)&apData[9] = _byteswap_ulong(*(volatile unsigned int*)&apData[9]);
    *(volatile unsigned int*)&apData[10] = _byteswap_ulong(*(volatile unsigned int*)&apData[10]);
    *(volatile unsigned int*)&apData[11] = _byteswap_ulong(*(volatile unsigned int*)&apData[11]);
}

struct FUN_00c8c1e0_arg
{
    int unk00;
    unsigned int m04;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};

struct FUN_00c8c1e0_sub
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
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00c8c1e0_rec
{
    int unk00;
    unsigned int m04;
    int unk08;
    int unk0C;
    FUN_00c8c1e0_sub sub;
};

struct FUN_00c8c1e0_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual FUN_00c8c1e0_rec* GetRec(FUN_00c8c1e0_arg*& a);
    void FUN_00c8c1e0(FUN_00c8c1e0_arg* a1);
};

// @fnv 0x00c8c1e0
void FUN_00c8c1e0_cls::FUN_00c8c1e0(FUN_00c8c1e0_arg* a1)
{
    FUN_00c8c1e0_rec* r;
    FUN_00c8c1e0_arg* volatile* pa = &a1;
    FUN_00c8c1e0_arg* a = *pa;
    reinterpret_cast<::FUN_00a645b0_cls *>((a))->FUN_00a645b0();
    reinterpret_cast<::FUN_00c84d00_cls *>(this)->FUN_00c84d00((::FUN_00c84d00_obj *)(a));
    r = GetRec(a1);
    r->m04 = 0;
    if (a->m1E5 != 1)
    {
        FUN_00c8c1e0_sub* s = &r->sub;
        volatile unsigned int* w = &s->m30;
        w[0] = _byteswap_ulong(w[0]);
        w[1] = _byteswap_ulong(w[1]);
        w[2] = _byteswap_ulong(w[2]);
        w[3] = _byteswap_ulong(w[3]);
        ::FUN_00c8c020((unsigned int *)(s));
    }
    if (a->m04 < 0x32)
    {
        reinterpret_cast<::bhkLimitedHingeVectorSet *>(&(r->sub))->FUN_00c8bf50();
    }
}

struct C8C260Block
{
    int unk00;
    int m_flags;
    int unk08;
    int unk0C;
    int m_kHeader[12];
    unsigned int m_iSlotIds[4];
};

inline void C8C260Swap32(unsigned int* p)
{
    *p = _byteswap_ulong(*p);
}

struct C8C260Renderer
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void SetTarget(void* target);

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
    unsigned char m_ucLittleEndian;
};

inline void C8C260Prepare(C8C260Block* block, C8C260Renderer* pkRenderer)
{
    block->m_flags = 0;
    if (pkRenderer->m_ucLittleEndian != 1)
    {
        int* header = block->m_kHeader;
        C8C260Swap32((unsigned int*)(header + 12));
        C8C260Swap32((unsigned int*)(header + 13));
        C8C260Swap32((unsigned int*)(header + 14));
        C8C260Swap32((unsigned int*)(header + 15));
        ::FUN_00c8c020((unsigned int *)(header));
    }
}

struct C8C260Inner
{
    int unk00;
    int unk04;
    void* m_target;
};

struct C8C260Link
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C8C260Inner* m_inner;
};

struct C8C260Shader
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual C8C260Block* GetBlock(bool* pbCreated);

    int unk04;
    C8C260Link* m_link;

    void FUN_00c8c260(C8C260Renderer* pkRenderer);
};

inline void* C8C260GetTarget(C8C260Shader* p)
{
    return (p && p->m_link && p->m_link->m_inner) ? p->m_link->m_inner->m_target : 0;
}

// @fnv 0x00c8c260
void C8C260Shader::FUN_00c8c260(C8C260Renderer* pkRenderer)
{
    pkRenderer->SetTarget(C8C260GetTarget(this));
    bool bCreated;
    C8C260Block* pkBlock = GetBlock(&bCreated);
    C8C260Prepare(pkBlock, pkRenderer);
    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50(pkRenderer);
    C8C260Prepare(pkBlock, pkRenderer);
}

typedef void(* ReleaseFn_t)(S_00c8c810_A* apObj);

// @fnv 0x00c8c770
void H_00c8c810::FUN_00c8c770()
{
    TlsGuard_t guard;
    if (this != 0)
    {
        S_00c8c810_C* pC = this->p;
        if (pC != 0)
        {
            S_00c8c810_B* pB = pC->p;
            if (pB != 0)
            {
                S_00c8c810_A* pA = pB->p;
                if (pA != 0)
                {
                    if (InterlockedDecrement(&pA->_ref) == 0)
                    {
                        void** vt = *(void***)pA;
                        ReleaseFn_t fn = (ReleaseFn_t)vt[1];
                        fn(pA);
                    }
                }
            }
        }
    }
}

namespace fnv_00c8c130 {
struct RenderArg
{
    unsigned int unknown0, unknown4, unknown8, unknownC;
    float alpha;
};
struct Holder_o2;
struct HolderResult;
struct RenderResult;
struct RenderNode
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual HolderResult* Fetch(RenderArg*);
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual bool NeedsRefresh(RenderArg*);
};
struct Holder_o2
{
    unsigned int value00, value04;
    RenderNode* node08;
};
struct HolderResult
{
    unsigned int value00, value04;
    Holder_o2* link08;
};
struct RenderResult
{
    unsigned int unknown00;
    Holder_o2* holder04;
    unsigned int unused8;
    unsigned int unused12;
    unsigned int unused16;
    unsigned int unused20;
    unsigned int unused24;
    unsigned int unused28;
    unsigned int unused32;
    unsigned int unused36;
    unsigned int unused40;
    unsigned int unused44;
    unsigned int unused48;
    unsigned int unused52;
    unsigned int unused56;
    unsigned int unused60;
    volatile float colour40;
    float colour44;
    volatile float colour48;
    float colour4C;
};
struct RenderProcessor
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual RenderResult* GetRendered(unsigned char*);
    void FUN_00c8c130(void* input, RenderArg* arg);
};
// @fnv 0x00c8c130
void RenderProcessor::FUN_00c8c130(void* input, RenderArg* arg)
{
    unsigned char ignored;
    RenderResult* result = GetRendered(&ignored);
    RenderNode* node = result->holder04 ? result->holder04->node08 : 0;
    float alpha = arg->alpha;
    if (alpha != 1.0f)
    {
        result->colour40 = result->colour40 * alpha;
        result->colour44 *= alpha;
        result->colour48 *= alpha;
        result->colour4C *= alpha;
    }
    else
    {
        if (node == 0)
            goto complete;
        if (node->NeedsRefresh(arg))
            goto complete;
    }
    {
        HolderResult* replacement = node->Fetch(arg);
        result->holder04 = replacement ? replacement->link08 : 0;
    }
complete:
    reinterpret_cast<::FUN_00c84df0_cls *>(this)->FUN_00c84df0((::FUN_00c84df0_cls *)(input), (::FUN_00c84df0_cls *)(arg));
}
}

// namespace fnv_00c8c130

namespace fnv_00c8c4d0 {


struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x10;
    }

    ~TlsGuard_t()
    {
        ::g_tlsBlock.memoryContext = m_saved;
    }
};

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedObject()
    {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01030bf4));
        unk0C = 0;
        unk10 = 0;
        ::DAT_012680f8++;
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01066d44));
        (*reinterpret_cast<int *>(&::DAT_012681b0))++;
    }
};

struct FUN_00c8c4d0_cls
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
    virtual void v49(SpawnedObject* obj, int a1);
    SpawnedObject* FUN_00c8c4d0(int a1);
};

// @fnv 0x00c8c4d0
SpawnedObject* FUN_00c8c4d0_cls::FUN_00c8c4d0(int a1)
{
    TlsGuard_t guard;
    ::FUN_00c876f0();
    SpawnedObject* p = new SpawnedObject();
    this->v49(p, a1);
    ::FUN_00c87700();
    return p;
}
}

// namespace fnv_00c8c4d0

namespace fnv_00cb8270 {

struct S_00cb8270_MM
{
};

struct S_00cb8270_Array
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;


    S_00cb8270_Array() : unk00(0), unk04(0), unk08(0), unk0C(0x80000000)
    {}
};

struct AutoMemContext_o2
{
    int m_oldContext;
    AutoMemContext_o2(int newContext)
    {
        m_oldContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = newContext;
    }
    ~AutoMemContext_o2()
    {
        ::g_tlsBlock.memoryContext = m_oldContext;
    }
};

struct S_00cb8270
{
    int unk00;
    int unk04;
    int unk08;
    S_00cb8270_Array* unk0C;


    S_00cb8270_Array* FUN_00cb8270(bool& outCreated);
};

// @fnv 0x00cb8270
S_00cb8270_Array* S_00cb8270::FUN_00cb8270(bool& outCreated)
{
    AutoMemContext_o2 memContext(0x10);

    bool created = (unk0C == 0);
    outCreated = created;
    if (created)
    {
        S_00cb8270_Array* arr = new S_00cb8270_Array();
        unk0C = arr;
        if (unk08 != 0)
        {
            reinterpret_cast<::fnv_00cb7c60::VertsSource *>(this)->FUN_00cb7c60((::fnv_00cb7c60::VertsOut *)(arr));
        }
    }
    return unk0C;
}
}

// namespace fnv_00cb8270

struct CollisionStreamLoader : NiCollisionObject
{
};

struct LegacyCollisionLoader : CollisionStreamLoader
{
    void FUN_00c87f60(NiStream& stream);
};

// @fnv 0x00c87f60
void LegacyCollisionLoader::FUN_00c87f60(NiStream& stream)
{
    if (stream.version >= 0x15)
    {
        reinterpret_cast<::BC6C330HavokCollision *>(this)->FUN_00c6c330((::BC6C330Stream &)(stream));
    }
    else
    {
        reinterpret_cast<::NiCollisionObject *>(this)->LoadBinary(stream);
    }
}

struct NiNode_o2_od_oy_noo2
{
};

struct BSTreeNode_o2_od_oy_noo2 : NiNode_o2_od_oy_noo2
{
    NiAVObject* GetFirstChild();
};

struct FUN_0066d520_shell_o2_od_oy_noo2
{
    void FUN_00cb78b0_o2_od_oy_noo2();
    void* FUN_0066d520(unsigned int flags);
};

struct HC1Base_o2_od_oy_noo2
{
};

struct This_o2_od_oy_noo2
{
    int unk00;
    int unk04;
    Middle* middle;
    void FUN_00c84e20(unsigned int* output);
};

struct NiCollisionObject_o2_od_oy_noo2
{
};

struct LegacyLinker_o2_od_oy_noo2 : NiCollisionObject_o2_od_oy_noo2
{
    void FUN_00c87f80(NiStream*);
};

struct NiPoint3_o2_od_oy_noo2
{
    float x, y, z;
    char* FUN_00a59af0(const char*);
public:
    float ComputeMagnitude() const;
};

struct NiTransform_o2_od_oy_noo2
{
    float rotation[9];
    NiPoint3_o2_od_oy_noo2 translate;
    float scale;
};

struct AutoMemContext_o2_od_oy_noo2
{
    unsigned int ePreviousContext;
    AutoMemContext_o2_od_oy_noo2()
    {
        ePreviousContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~AutoMemContext_o2_od_oy_noo2()
    {
        ::g_tlsBlock.memoryContext = ePreviousContext;
    }
};

struct Holder_o2_od_oy_noo2
{
    unsigned int unk00, unk04;
    Component* component;
};

struct State_o2_od_oy_noo2
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Holder_o2_od_oy_noo2* holder;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    NativeTransform world;
};

struct Object_o2_od_oy_noo2
{
    unsigned int unk00, unk04;
    State_o2_od_oy_noo2* state;
    void FUN_00c8cb20(StrArr*);
    Component* getComponent()
    {
        if (this)
        {
            State_o2_od_oy_noo2* current = state;
            if (current)
            {
                Holder_o2_od_oy_noo2* holder = current->holder;
                if (!holder)
                    return 0;
                return holder->component;
            }
            return 0;
        }
        return 0;
    }
};

struct FUN_00cb78b0_o2_od_oy_noo2 : S_00cb78b0_Base
{
    virtual ~FUN_00cb78b0_o2_od_oy_noo2();
};

struct AudioTlsState_o2_od_oy_noo2
{
    char* GetBlock();
};

struct FUN_00d22590_o2_od_oy_noo2
{
    int unk00;
    short unk04;
    short unk06;
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
    FUN_00d22590_o2_od_oy_noo2(int a, int b, float c);
    static void* operator new(std::size_t size)
    {
        FUN_00d22590_o2_od_oy_noo2* p = (FUN_00d22590_o2_od_oy_noo2*)((Heap *)::FUN_00c85750())->Alloc(size);
        p->unk04 = (short)size;
        return p;
    }
    static void operator delete(void* p, std::size_t);
};

struct Owner_o2_od_oy_noo2
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
    virtual void AddElement(FUN_00d22590_o2_od_oy_noo2* e);
    void FUN_00cab0e0(int a, int b, float c);
};

class hkVector4_66C
{
  public:
    hkVector4_66C(float fX, float fY, float fZ, float fW);
    void Set(float fX, float fY, float fZ, float fW);
    __m128 m_vComponents;
};

class Filter66C
{
  public:
    Filter66C(int iLayer, int iSystem, int iPart);
    unsigned int m_uiBits;
};

class MotionType66C
{
  public:
    void Set(int iType);
    unsigned int m_uiType;
};

class BodyCinfo66C
{
  public:
    BodyCinfo66C();
    ~BodyCinfo66C();
    unsigned int m_uiFilterInfo;
    void* m_pvShape;
    MotionType66C m_kMotion;
    int unk0c;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
};

class TransformShapeInfo66C
{
  public:
    TransformShapeInfo66C();
    int unk00;
    void* m_pvChild;
    int unk08;
    int unk0c;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    hkVector4_66C m_kTranslation;
};

class CapsuleInfo66C
{
  public:
    CapsuleInfo66C();
    int unk00;
    float m_fBoundRadius;
    int unk08;
    int unk0c;
    hkVector4_66C m_kVertexA;
    hkVector4_66C m_kVertexB;
};

class SphereArray66C
{
  public:
    void* m_pResource;
    int m_uiLogicalSize;
    int m_iCapacity;
};

class MultiSphereInfo66C
{
  public:
    MultiSphereInfo66C();
    ~MultiSphereInfo66C();
    int unk00;
    SphereArray66C m_kSpheres;
};

class Shape66C
{
  public:
    void* m_pvVtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class SphereShape66C : public Shape66C
{
  public:
    SphereShape66C(float fRadius, int iFlags);
};

class BoxShape66C : public Shape66C
{
  public:
    BoxShape66C(const hkVector4_66C& m_kPoint2);
};

class TransformShape66C : public Shape66C
{
  public:
    TransformShape66C(TransformShapeInfo66C& kInfo);
};

class CapsuleShape66C : public Shape66C
{
  public:
    CapsuleShape66C(CapsuleInfo66C& kInfo);
};

class MultiSphereShape66C : public Shape66C
{
  public:
    MultiSphereShape66C(MultiSphereInfo66C& kInfo);
};

class Body66C
{
  public:
    Body66C(BodyCinfo66C& kInfo);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

class Object66C
{
  public:
    Object66C(void* pvOwner);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};

class Bounds66C
{
  public:
};

class Havok66C
{
  public:
    bool IsEnabled(int iFlag);
};

class Tree66C
{
  public:
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
    virtual void* GetOwner();
    void FUN_0066cb40(Bounds66C* pkBounds, float fScale);
};

// @fnv 0x0066cb40
void Tree66C::FUN_0066cb40(Bounds66C* pkBounds, float fScale)
{
    if ((*reinterpret_cast<::Havok66C *>(&::g_011d5e84)).IsEnabled(1))
    {
        unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::FUN_00b0a260_Class *>((pkBounds))->GetEntryCount()));
        if (!ItemUpdateArray)
            return;
        float fHavokScale = FUN_0066b0b0() * fScale;
        void* pvOwner = GetOwner();
        BodyCinfo66C kInfo;
        if (ItemUpdateArray == 1)
        {
            float afSize[3];
            float afCenter[3];
            int iType;
            reinterpret_cast<::fnv_00b0a2a0::SpeedTreeRTB0A2A0 *>((pkBounds))->FUN_00b0a2a0(0, (*(int *)(&iType)), afCenter, afSize);
            afCenter[0] = FUN_004a3e90(afCenter[0]) * fHavokScale;
            afCenter[1] = FUN_004a3e90(afCenter[1]) * fHavokScale;
            afCenter[2] = FUN_004a3e90(afCenter[2]) * fHavokScale;
            afSize[0] = FUN_004a3e90(afSize[0]) * fHavokScale;
            afSize[1] = FUN_004a3e90(afSize[1]) * fHavokScale;
            afSize[2] = FUN_004a3e90(afSize[2]) * fHavokScale;
            switch (iType)
            {
            case 0: {
                TransformShapeInfo66C kTransform;
                hkVector4_66C kIntersectionOffset(afCenter[0], afCenter[1], afCenter[2], 0.0f);
                reinterpret_cast<::S004b4db0_Quaternion *>(&(kTransform.m_kTranslation))->FUN_004b4db0((const ::S004b4db0_Vector4 &)(kIntersectionOffset));
                SphereShape66C* pkSphere = new SphereShape66C(afSize[0], 0);
                kTransform.m_pvChild = ((void *)(::FUN_004ae750((void *)(pkSphere))));
                TransformShape66C* pkShape = new TransformShape66C(kTransform);
                kInfo.m_pvShape = ((void *)(::FUN_004ae750((void *)(pkShape))));
            }
            break;
            case 1: {
                CapsuleInfo66C kCapsule;
                reinterpret_cast<::fnv_004b4ff0::FUN_004b4ff0_shell *>(&(kCapsule.m_kVertexA))->FUN_004b4ff0(afCenter[0], afCenter[1], afCenter[2] + afSize[0], 0.0f);
                reinterpret_cast<::fnv_004b4ff0::FUN_004b4ff0_shell *>(&(kCapsule.m_kVertexB))->FUN_004b4ff0(afCenter[0], afCenter[1], afCenter[2] + afSize[1] - afSize[0], 0.0f);
                kCapsule.m_fBoundRadius = afSize[0];
                CapsuleShape66C* pkShape = new CapsuleShape66C(kCapsule);
                kInfo.m_pvShape = ((void *)(::FUN_004ae750((void *)(pkShape))));
            }
            break;
            case 2: {
                TransformShapeInfo66C kTransform;
                for (int i = 0; i < 3; i++)
                    afSize[i] *= 0.5;
                hkVector4_66C kIntersectionOffset(afCenter[0], afCenter[1], afCenter[2] + afSize[2], 0.0f);
                hkVector4_66C m_kPoint2(afSize[0], afSize[1], afSize[2], 0.0f);
                reinterpret_cast<::S004b4db0_Quaternion *>(&(kTransform.m_kTranslation))->FUN_004b4db0((const ::S004b4db0_Vector4 &)(kIntersectionOffset));
                BoxShape66C* pkBox = new BoxShape66C(m_kPoint2);
                kTransform.m_pvChild = ((void *)(::FUN_004ae750((void *)(pkBox))));
                TransformShape66C* pkShape = new TransformShape66C(kTransform);
                kInfo.m_pvShape = ((void *)(::FUN_004ae750((void *)(pkShape))));
            }
            break;
            }
        }
        else
        {
            MultiSphereInfo66C kSpheres;
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                float afSize[3];
                float afCenter[3];
                int iType;
                reinterpret_cast<::fnv_00b0a2a0::SpeedTreeRTB0A2A0 *>((pkBounds))->FUN_00b0a2a0(i, (*(int *)(&iType)), afCenter, afSize);
                if (iType == 0)
                {
                    afCenter[0] = FUN_004a3e90(afCenter[0]) * fHavokScale;
                    afCenter[1] = FUN_004a3e90(afCenter[1]) * fHavokScale;
                    afCenter[2] = FUN_004a3e90(afCenter[2]) * fHavokScale;
                    afSize[0] = FUN_004a3e90(afSize[0]) * fHavokScale;
                    hkVector4_66C kSphere(afCenter[0], afCenter[1], afCenter[2], afSize[0]);
                    reinterpret_cast<::D9B0Container *>(&(kSpheres.m_kSpheres))->EraseByKey((std::intptr_t)&(kSphere));
                }
                else
                {
                    ::FUN_005b5e40();
                }
            }
            MultiSphereShape66C* pkShape = new MultiSphereShape66C(kSpheres);
            kInfo.m_pvShape = ((void *)(::FUN_004ae750((void *)(pkShape))));
        }
        Filter66C kFilter(9, 4, 0);
        kInfo.m_uiFilterInfo = ((unsigned int)(::FUN_00559450((int *)&(kFilter))));
        Body66C* pkBody = new Body66C(kInfo);
        Object66C* pkObject = new Object66C(pvOwner);
        reinterpret_cast<::FUN_00c6b980_cls *>((pkObject))->FUN_00c6b980((::World_c6b *)(pkBody));
    }
}

namespace fnv_0066c160 {
struct __declspec(align(16)) xVec4
{
    float m_q[4];
    xVec4(float, float, float, float);
    xVec4(const xVec4&);
    xVec4 FUN_00630b40() const;
};
struct __declspec(align(16)) xL
{
    xL(float);
    float m_q[4];
};
struct xP3
{
    xP3();
    float x, y, z;
};
struct xBound
{
    xBound();
    xP3 m_pos;
    float m_iThirdValue;
    float m_10;
    unsigned char m_14;
    unsigned char m_15;
    std::intptr_t m_18;
    std::intptr_t m_1c;
    int m_20;
};
struct xEvent
{
    xEvent();
    int m_iWordAt00[8];
    std::intptr_t m_20;
    int m_24;
    int m_28[8];
    void* m_48;
    int m_4c;
    int m_50[10];
};
struct xForm
{
    int m_iWordAt00, m_iWordAt04;
    struct xNode* m_8;
};
struct xNode
{
};
struct xArr
{
};
struct __declspec(align(16)) xList
{
    xList();
    ~xList();
    int m_iWordAt00;
    char m_buf[0x10c];
};
struct xHasPos
{
};
struct xTarget;
struct xSink
{
    virtual void v0();
    virtual void v1();
    virtual void FUN_08(int, xEvent*);
};
struct xTarget
{
    char m_auiShapeKeys[0x410];
    xSink m_410;
};
struct xCreated
{
};
struct xB
{
    xVec4* FUN_00560e50();
};
float xFUN_004dfea0();
struct xShapeX
{
};
struct xIntSetting
{
};
struct xFltSetting
{
};
struct StringProvider
{
};
struct xObj3D;
struct xObj3D
{
    virtual void v0();
    virtual void v1();
    virtual void FUN_08(void*);
};

struct xObjPtr
{
    xObj3D* operator->();
};
struct xRef
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
    virtual void v35();
    virtual void v36();
    virtual int FUN_94();
};

struct xEffect
{
    char m_auiShapeKeys[0xe4];
    xObjPtr m_e4;
    void FUN_0066c160(float afTime);
};
// @fnv 0x0066c160
void xEffect::FUN_0066c160(float afTime)
{
    if (((unsigned int)(::FUN_00559450((int *)&(m_e4)))))
        m_e4->FUN_08(this);
    if (!reinterpret_cast<::FUN_0066ca50_cls *>(this)->FUN_0066ca50(afTime))
        return;
    xRef* PREF = ((::fnv_0066c160::xRef *)(reinterpret_cast<::FUN_0066d7c0_cls *>(this)->FUN_0066d7c0()));
    if (!PREF || !PREF->FUN_94())
        return;
    const char* PTAG = ((const char *)(std::strstr((char *)(((const char *)(reinterpret_cast<::FUN_00b0d5d0_Class *>((((::fnv_0066c160::StringProvider *)(reinterpret_cast<::FUN_0084e3a0_Class *>(((m_e4).operator->()))->FUN_0084e3a0()))))->GetUnk68()))), "~CF")));
    int LEVEL;
    if (PTAG)
        LEVEL = PTAG[3] - '0';
    else
        LEVEL = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0066c160::xIntSetting *>(&::g_011d5ea0))))));
    float CHANCE = LEVEL * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0066c160::xFltSetting *>(&::originalRuntimeFloatSetting1301)))))) * 100.0;
    xList LIST;
    reinterpret_cast<::fnv_00623150::FUN_00623150_Class *>((PREF))->FUN_00623150(&LIST);
    xArr* ARR = ((::fnv_0066c160::xArr *)(reinterpret_cast<::TESTopicInfoData *>(&(LIST))->GetLinkToList()));
    for (int I = 0; I < ((int)(std::intptr_t)(reinterpret_cast<::Callees *>((ARR))->FUN_00726070())); I++)
    {
        void* PA = ::FUN_004b5950(((::fnv_0066c160::xForm *)(reinterpret_cast<::FUN_0062e150_cls *>((ARR))->FUN_0062e150(I)))->m_8);
        xB* PB = ((::fnv_0066c160::xB *)(::FUN_004b59f0(((::fnv_0066c160::xForm *)(reinterpret_cast<::FUN_0062e150_cls *>((ARR))->FUN_0062e150(I)))->m_8)));
        if (PA)
        {
            xCreated* PC = ((::fnv_0066c160::xCreated *)(::LookupFirstByKey(0x3e8, (::FnvLookup_Container *)(PA))));
            if (PC)
            {
                xTarget* PD = ((::fnv_0066c160::xTarget *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((PC))->FUN_009306d0()));
                if (PD)
                {
                    xEvent EV;
                    xVec4 DIR(::RandomFloat0To1(), ::RandomFloat0To1(), ::RandomFloat0To1(), 0.0f);
                    reinterpret_cast<::Vec4 *>(&(DIR))->FUN_0066c930();
                    xVec4 POS(*((::fnv_0066c160::xVec4 *)(reinterpret_cast<::TESTopicInfo *>((((xHasPos*)((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((::fnv_0066c160::xForm *)(reinterpret_cast<::FUN_0062e150_cls *>((ARR))->FUN_0062e150(I)))->m_8))->GetName())))))->GetAddTopicList())));
                    reinterpret_cast<::FUN_0066c9c0_Class *>(&(EV))->FUN_0066c9c0((::T_ &)(POS), (::T_ &)(DIR), 0.0f);
                    EV.m_20 = ((std::intptr_t)(reinterpret_cast<::FUN_0043b560_shell *>((PREF))->GetSourceFilesFromObject()));
                    EV.m_48 = ((::fnv_0066c160::xForm *)(reinterpret_cast<::FUN_0062e150_cls *>((ARR))->FUN_0062e150(I)))->m_8;
                    EV.m_24 = EV.m_4c = 0;
                    PD->m_410.FUN_08(0, &EV);
                    xBound BND;
                    xP3 PT;
                    BND.m_14 = 4;
                    BND.m_15 = 7;
                    BND.m_10 = 1.0f;
                    reinterpret_cast<::HolderFUN *>((PD))->FUN_0066ca00(&PT);
                    BND.m_iThirdValue = reinterpret_cast<::NiPoint3_o2_od_oy_noo2 *>((void *)&(PT))->ComputeMagnitude();
                    BND.m_18 = (std::intptr_t)PA + (std::intptr_t)PREF;
                    BND.m_pos = *((::fnv_0066c160::xP3 *)&(::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&PT)), (*(const ::hkVector4 *)(&POS)))));
                    BND.m_1c = 0;
                    BND.m_20 = 0;
                    ::ImpactSound::FUN_00837550((::ImpactSound::ImpactData *)(::fnv_0066c160::xBound *)(&BND));
                }
            }
        }
        else if (PB)
        {
            if (((int)(::GetRandomNumberInRange(0, 100))) <= CHANCE)
            {
                xVec4 V1(*((::fnv_0066c160::xVec4 *)(std::uintptr_t)(::FUN_00560dc0((::TESDataHandler *)(PB)))));
                xVec4 V2(*PB->FUN_00560e50());
                if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_0066c160::xVec4 &)((*(::fnv_0066c160::xVec4 *)(reinterpret_cast<::FUN_00630100_shell *>((void *)&(V1))->FUN_00630100({})))))->FUN_004586d0() > 1.0)
                {
                    float SPEED = reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_0066c160::xVec4 &)(V1.FUN_00630b40()))->FUN_004586d0() *
                                  (1.0 - ((int)(::GetRandomNumberInRange(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0066c160::xIntSetting *>(&::g_011d5e58)))))), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0066c160::xIntSetting *>(&::g_011d5e94))))))))) / 100.0);
                    float R1 = xFUN_004dfea0();
                    float R2 = xFUN_004dfea0();
                    float R3 = xFUN_004dfea0() - 0.25;
                    xVec4 D1(R1, R2, R3, 0.0f);
                    reinterpret_cast<::Vec4 *>(&(D1))->FUN_0066c930();
                    xL L1(SPEED);
                    reinterpret_cast<::S_00627920 *>(&(D1))->FUN_00627920((::S_00561240 *)&(L1));
                    reinterpret_cast<::FUN_005616d0_Owner *>((PB))->OnTrigger((::TriggerContext *)(::fnv_0066c160::xVec4 *)(&D1));
                }
                if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_0066c160::xVec4 &)((*(::fnv_0066c160::xVec4 *)(reinterpret_cast<::FUN_00630100_shell *>((void *)&(V2))->FUN_00630100({})))))->FUN_004586d0() > 1.0)
                {
                    float SPEED2 = reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_0066c160::xVec4 &)(V2.FUN_00630b40()))->FUN_004586d0() * (((int)(::GetRandomNumberInRange(0, 20))) / 100.0 + 90.0);
                    float R4 = xFUN_004dfea0();
                    float R5 = xFUN_004dfea0();
                    float R6 = xFUN_004dfea0() - 0.25;
                    xVec4 D2(R4, R5, R6, 0.0f);
                    reinterpret_cast<::Vec4 *>(&(D2))->FUN_0066c930();
                    xL L2(SPEED2);
                    reinterpret_cast<::S_00627920 *>(&(D2))->FUN_00627920((::S_00561240 *)&(L2));
                    reinterpret_cast<::FUN_00561800_Class *>((PB))->FUN_00561800((::FUN_00561730_Obj *)(::fnv_0066c160::xVec4 *)(&D2));
                }
                xBound BND2;
                xP3 PT2;
                xShapeX* PS = (xShapeX*)((void *)(std::uintptr_t)(::FUN_004a3a40((::TESObjectREFR *)(((::FUN_00559450((int *)(((::fnv_0066c160::xForm *)(reinterpret_cast<::FUN_0062e150_cls *>((ARR))->FUN_0062e150(I)))->m_8))))))));
                BND2.m_14 = 4;
                BND2.m_15 = (unsigned char)(PS ? reinterpret_cast<::FUN_006205a0_Class *>((PS))->FUN_006205a0() : 0);
                BND2.m_10 = 1.0f;
                BND2.m_iThirdValue = ::FUN_004587d0(reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::fnv_0066c160::xVec4 &)(V1.FUN_00630b40()))->FUN_004586d0());
                BND2.m_18 = (std::intptr_t)PB + (std::intptr_t)PREF;
                BND2.m_pos = *((::fnv_0066c160::xP3 *)&(::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&PT2)), (*(const ::hkVector4 *)(((::fnv_0066c160::xVec4 *)(reinterpret_cast<::TESTopicInfo *>((((xHasPos*)((void *)(std::uintptr_t)(::FUN_004b4f00((::TESDataHandler *)(PB)))))))->GetAddTopicList())))))));
                BND2.m_1c = (std::intptr_t)::FUN_004b5a80(PB);
                BND2.m_20 = 0;
                ::ImpactSound::FUN_00837550((::ImpactSound::ImpactData *)(::fnv_0066c160::xBound *)(&BND2));
            }
        }
    }
}
}

struct NiNode_o2_rtm
{
};

struct BSTreeNode_o2_rtm : NiNode_o2_rtm
{
    NiAVObject* GetFirstChild();
};

struct FUN_0066d520_shell_o2_rtm
{
    void FUN_00cb78b0_o2_rtm();
    void* FUN_0066d520(unsigned int flags);
};

struct HC1Base_o2_rtm
{
};

struct This_o2_rtm
{
    int unk00;
    int unk04;
    Middle* middle;
    void FUN_00c84e20(unsigned int* output);
};

struct NiCollisionObject_o2_rtm
{
public:
    void LoadBinary(::NiStream &);
};

struct LegacyLinker_o2_rtm : NiCollisionObject_o2_rtm
{
    void FUN_00c87f80(NiStream*);
};

struct NiPoint3_o2_rtm
{
    float x, y, z;
    char* FUN_00a59af0(const char*);
};

struct NiTransform_o2_rtm
{
    float rotation[9];
    NiPoint3_o2_rtm translate;
    float scale;
};

struct AutoMemContext_o2_rtm
{
    unsigned int ePreviousContext;
    AutoMemContext_o2_rtm()
    {
        ePreviousContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~AutoMemContext_o2_rtm()
    {
        ::g_tlsBlock.memoryContext = ePreviousContext;
    }
};

struct Holder_o2_rtm
{
    unsigned int unk00, unk04;
    Component* component;
};

struct State_o2_rtm
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Holder_o2_rtm* holder;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    NativeTransform world;
};

struct Object_o2_rtm
{
    unsigned int unk00, unk04;
    State_o2_rtm* state;
    void FUN_00c8cb20(StrArr*);
    Component* getComponent()
    {
        if (this)
        {
            State_o2_rtm* current = state;
            if (current)
            {
                Holder_o2_rtm* holder = current->holder;
                if (!holder)
                    return 0;
                return holder->component;
            }
            return 0;
        }
        return 0;
    }
};

struct FUN_00cb78b0_o2_rtm : S_00cb78b0_Base
{
    virtual ~FUN_00cb78b0_o2_rtm();
};

struct AudioTlsState_o2_rtm
{
    char* GetBlock();
};

struct Owner_o2_rtm
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
    virtual void AddElement(FUN_00d22590* e);
    void FUN_00cab0e0(int a, int b, float c);
};

struct CollisionStreamLoader_o2_rtm : NiCollisionObject_o2_rtm
{
};

struct LegacyCollisionLoader_o2_rtm : CollisionStreamLoader_o2_rtm
{
    void FUN_00c87f60(NiStream& stream);
};

struct __declspec(align(16)) Vector
{
    union
    {
        __m128 v;
        float f[4];
    };
    __forceinline void xyz(const __m128& input)
    {
        __m128 hi = _mm_unpackhi_ps(input, v);
        v = _mm_shuffle_ps(input, hi, 0xc4);
    }
};

struct CapsuleData
{
    unsigned int unk00, unk04, unk08, unk0C;
    float radius;
    unsigned int unk14, unk18, unk1C;
    Vector endpoints[2];
};

struct Matrix
{
    __m128 c[4];
};

struct Contact
{
    Vector position, normal;
};

struct Sphere
{
    Vector center;
};

struct Capsule
{
    unsigned int unk00, unk04;
    CapsuleData* data;
    bool FUN_00cab3c0(Sphere*, Matrix*, Contact*);
};

__forceinline float scalar(__m128 v)
{
    float x;
    _mm_store_ss(&x, v);
    return x;
}
__forceinline __m128 sum3(const __m128& input)
{
    __m128 v = input;
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    y = _mm_add_ss(y, v);
    v = _mm_shuffle_ps(v, v, 0xaa);
    return _mm_add_ss(v, y);
}
__forceinline __m128 inverseRoot(__m128 v)
{
    __m128 r = _mm_rsqrt_ss(v);
    __m128 t = _mm_mul_ss(_mm_mul_ss(v, r), r);
    __m128 mask = _mm_cmpeq_ss(v, _mm_set_ss(DAT_01011d78));
    __m128 error = _mm_sub_ss(_mm_set_ss(DAT_01017718), t);
    __m128 result = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), r), error);
    return _mm_andnot_ps(mask, result);
}
__forceinline __m128 normalize(__m128 v)
{
    __m128 s = inverseRoot(sum3(_mm_mul_ps(v, v)));
    return _mm_mul_ps(_mm_shuffle_ps(s, s, 0), v);
}

inline float square(float x)
{
    return x * x;
}

inline float squaredNorm(const __m128& v)
{
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    __m128 z = _mm_shuffle_ps(v, v, 0xaa);
    return scalar(_mm_add_ss(z, _mm_add_ss(y, v)));
}

// @fnv 0x00cab3c0
bool Capsule::FUN_00cab3c0(Sphere* sphere, Matrix* matrix, Contact* contact)
{
    CapsuleData* shape = this ? data : 0;
    __m128 endpoints[2];
    __m128 m0 = matrix->c[0], m1 = matrix->c[1], m2 = matrix->c[2], m3 = matrix->c[3];
    for (int i = 1; i >= 0; --i)
    {
        __m128 v = shape->endpoints[i].v;
        __m128 y = _mm_shuffle_ps(v, v, 0x55);
        __m128 x = _mm_shuffle_ps(v, v, 0);
        x = _mm_mul_ps(x, m0);
        y = _mm_mul_ps(y, m1);
        y = _mm_add_ps(y, x);
        __m128 z = _mm_shuffle_ps(v, v, 0xaa);
        z = _mm_mul_ps(z, m2);
        z = _mm_add_ps(z, m3);
        endpoints[i] = _mm_add_ps(y, z);
    }
    __m128 closest;
    ::FUN_00d230e0((*(const ::hkVector4D230 *)(sphere)), (*(const ::hkVector4D230 *)(&endpoints[0])), (*(const ::hkVector4D230 *)(&endpoints[1])), (*(::hkVector4D230 *)(&closest)));
    float totalRadius = sphere->center.f[3] + shape->radius;
    __m128 delta = _mm_sub_ps(sphere->center.v, closest);

    // Preserve the complete squared vector for the later reciprocal-square-root path.
    __m128 squares = _mm_mul_ps(delta, delta);
    float squaredDistance = squaredNorm(squares);
    if (squaredDistance >= square(totalRadius))
        return false;
    float distance;
    __m128 normal;
    if (squaredDistance > 0.0f)
    {
        distance = sqrtf(squaredDistance);
        __m128 s = inverseRoot(sum3(_mm_load_ps((const float*)&squares)));
        normal = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), delta);
        contact->normal.xyz(normal);
    }
    else
    {
        distance = 0.0f;
        // At zero separation, choose a perpendicular to the capsule segment.
        __m128 delta = _mm_sub_ps(endpoints[1], endpoints[0]);
        float ax = fabsf(delta[0]);
        float ay = fabsf(delta[1]);
        float az = fabsf(delta[2]);
        int minimum = 0, other = 1, third = 2;
        if (ay < ax)
        {
            ax = ay;
            other = 0;
            minimum = 1;
        }
        if (az < ax)
            third = minimum;
        __m128 perpendicular;
        perpendicular = _mm_setzero_ps();
        perpendicular[other] = delta[third];
        perpendicular[third] = -delta[other];
        normal = normalize(perpendicular);
        contact->normal.xyz(normal);
    }

    float projection = shape->radius - distance;
    __m128 p = _mm_load_ss(&projection);
    p = _mm_shuffle_ps(p, p, 0);
    __m128 n = contact->normal.v;
    __m128 result = _mm_mul_ps(p, n);
    result = _mm_add_ps(result, sphere->center.v);
    contact->position.v = result;
    float* depth = &contact->normal.f[3];
    *depth = distance - totalRadius;
    return true;
}

struct ArgB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
};

struct __declspec(align(16)) BhkVec4
{
    float x, y, z, w;
};

struct BhkVecArray
{
    int unk00;
    BhkVec4* m_pVecs;
    unsigned int m_uCount;
};

struct bhkSphereShape
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
    virtual BhkVecArray* v45(unsigned char*);
    void FUN_00cb7a90(void*, ArgB*);
};

// @fnv 0x00cb7a90
void bhkSphereShape::FUN_00cb7a90(void* a1, ArgB* a2)
{
    unsigned char flag;
    BhkVecArray* arr = this->v45(&flag);
    float f = a2->unk10;
    if (f != 1.0f)
    {
        unsigned int n = arr->m_uCount;
        if (n != 0)
        {
            unsigned int off = n << 4;
            do
            {
                --n;
                __m128 b = _mm_load_ss(&f);
                off -= 16;
                float* p = (float*)((char*)arr->m_pVecs + off);
                _mm_store_ps(p, _mm_mul_ps(_mm_shuffle_ps(b, b, 0), _mm_load_ps(p)));
            } while (n != 0);
        }
    }
    reinterpret_cast<::FUN_00c84df0_cls *>((this))->FUN_00c84df0((::FUN_00c84df0_cls *)(a1), (::FUN_00c84df0_cls *)(a2));
}

namespace fnv_00c88020 {

extern "C" const float DAT_01016248 = 0.5f;

struct BoundsTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(float* value);
};

struct ShapeHolder
{
    unsigned int unk00;
    unsigned int unk04;
    BoundsTarget* target;
};

struct CollisionBoundsUpdater : S00cb7750
{
    void FUN_00c88020();
};

struct Amount
{
    __m128 lane;
    Amount(float value)
    {
        lane = _mm_load_ss(&value);
    }
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(lane, lane, 0);
    }
};
struct Vector4f
{
    __m128 value;
    void subtract(const Vector4f& other)
    {
        value = _mm_sub_ps(value, other.value);
    }
    void multiply(const Amount& factor)
    {
        value = _mm_mul_ps(factor.broadcast(), value);
    }
    void add(const Vector4f& other)
    {
        value = _mm_add_ps(value, other.value);
    }
};

// @fnv 0x00c88020
void CollisionBoundsUpdater::FUN_00c88020()
{
    ShapeHolder* shape = reinterpret_cast<ShapeHolder*>(m_10);
    if (shape != 0)
    {
        BoundsTarget* target = shape->target;
        if (target == 0)
            return;
        NiTransform_o2_rtm transform;
        __m128 box[2];
        transform.rotation[0] = 1.0f;
        transform.rotation[1] = 0.0f;
        transform.rotation[2] = 0.0f;
        transform.rotation[3] = 0.0f;
        transform.rotation[5] = 0.0f;
        transform.rotation[6] = 0.0f;
        transform.rotation[7] = 0.0f;
        transform.rotation[4] = 1.0f;
        transform.rotation[8] = 1.0f;
        transform.scale = 1.0f;
        target->v18((float*)box);
        Vector4f a, b;
        a.value = box[0];
        b.value = box[1];
        b.subtract(a);
        b.multiply(Amount(DAT_01016248));
        box[1] = b.value;
        a.add(b);
        box[0] = a.value;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&transform.translate)), (*(const ::hkVector4 *)((const float*)&box[1])));
        f46(reinterpret_cast<Buf00cb7750*>(&transform));
    }
}
}

#include "generated/data/fallout_shared/speedtree/bstreenode.inc"
#include "generated/data/fallout_shared/speedtree/bstreenode_o2_nood_variant.inc"
#include "generated/data/fallout_shared/speedtree/bstreenode_o2_nood_variant_rtm_variant.inc"
#include "generated/data/fallout_shared/speedtree/bstreenode_o2_variant.inc"
