
// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0042f030_cls.h"
#include "fnv/decl/FUN_0042f180_cls.h"
#include "fnv/decl/FUN_0042f1d0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00452440_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004572e0_shell.h"
#include "fnv/decl/FUN_004700d0_class.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00547770_shell.h"
#include "fnv/decl/FUN_00560d50_Struct.h"
#include "fnv/decl/FUN_00563200_Struct.h"
#include "fnv/decl/FUN_0057b0d0_cls.h"
#include "fnv/decl/FUN_00580060_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0061f6c0_shell.h"
#include "fnv/decl/FUN_00620300_cls.h"
#include "fnv/decl/FUN_0062e860_cls.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087b700_shell.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FakeTaskQueue.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ImpactManager620.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NodeList620.h"
#include "fnv/decl/ObstacleManagerC9A.h"
#include "fnv/decl/QueryOwner.h"
#include "fnv/decl/Ref57b240.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/Target5c80.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/fnv_004e8510__OwnerW.h"
#include "fnv/decl/fnv_00620760__BGSZoneTargetListener.h"
#include "fnv/decl/fnv_00631370__WorkOwner.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00575000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0062e000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/OwnerC9Body.h"
#include "fnv/symbols_00631000.h"
#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_005532a0_cls.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_00630bb0_shell.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S00458a10_Vector.h"
#include "fnv/decl/S00630ae0_Result.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/V.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldObject_c8d3.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/fnv_00437c10__FUN_00437c10.h"
#include "fnv/decl/fnv_004b4ea0__TESDataHandler.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/decl/B200Owner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0062f2f0_shell.h"
#include "fnv/decl/FUN_00c9bff0_Class.h"
#include "fnv/decl/FUN_00c9c240_holder.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/PhysicsController.h"
#include "fnv/decl/S00561240_Vector.h"
#include "fnv/decl/S3e60.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_simd.h"
struct FUN_0062e750_shell
{
    void* FUN_0062e750(unsigned int flags);
};


// Calls FUN_0062e860, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062e750
void* FUN_0062e750_shell::FUN_0062e750(unsigned int flags)
{
    reinterpret_cast<::FUN_0062e860_cls *>(this)->FUN_0062e860_cls::~FUN_0062e860_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_011c7a3c;

// @fnv 0x0062f310
void FUN_0062f310(int value)
{
    DAT_011c7a3c = value;
}

extern unsigned char DAT_011c7a5a;

// @fnv 0x0062f8e0
void FUN_0062f8e0(unsigned char value)
{
    DAT_011c7a5a = value;
}


// @fnv 0x0062f8f0
void FUN_0062f8f0(float value)
{
    _DAT_011c7a5c = value;
}

struct BSOcclusionPlane
{
};

struct ExtraDataList
{
};

struct BSThread
{
};

// Returns the thread ID reached through the plane's cull result and its extra data, or 0 if any step is null.
// @fnv 0x0062fec0
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane)
{
    unsigned int result = 0;
    if (pPlane)
    {
        unsigned int cullResult = ((unsigned int)(reinterpret_cast<::LowProcess *>((void *)(pPlane))->GetTarget()));
        if (cullResult)
        {
            unsigned int room = ((unsigned int)(reinterpret_cast<::FUN_004543c0_cls *>((((ExtraDataList*)cullResult)))->FUN_004543c0()));
            if (room)
            {
                result = reinterpret_cast<::ActorMover *>((((BSThread*)room)))->GetCurrentMoveModeType();
            }
        }
    }
    return result;
}

extern "C" float __cdecl ExpFloat(float);

// @fnv 0x00630aa0
float FUN_00630aa0(float value)
{
    return ExpFloat(value);
}


// @fnv 0x00630ac0
float ExpFloat(float value)
{
    return static_cast<float>(std::exp(value));
}

extern float _gModifierZero;

// Returns 1.0 for a positive input, -1.0 for a negative input, and 0.0 for zero.
// @fnv 0x00631070
float __cdecl SignOfFloat(float afValue)
{
    float result;
    if (afValue > 0.0f)
        result = 1.0f;
    else
    {
        float t;
        if (afValue < 0.0f)
            t = -1.0f;
        else
            t = 0.0f;
        result = t;
    }
    return result;
}

struct FUN_005631e0_shell
{
    bool IsNonZero(int a);
};

// @fnv 0x005631e0
bool FUN_005631e0_shell::IsNonZero(int aiValue)
{
    return reinterpret_cast<::FUN_00563200_Struct *>(this)->MaskWithField(aiValue) != 0;
}


struct FUN_0062e710_shell
{
    void SetValueAt(float f, int a, int b);
};

// @fnv 0x0062e710
void FUN_0062e710_shell::SetValueAt(float afValue, int a, int b)
{
    int index = a + b * (*(int*)((char*)this + 0x28));
    *(float*)((*(int*)((char*)this + 0x20)) + index * 4) = FUN_004a3e90(afValue);
}

struct BSSimpleList_Ragdoll
{
    void* FUN_006310e0();
};
struct TESDataHandler
{
};
struct FUN_006310c0_shell
{
    void FUN_006310c0();
};

// @fnv 0x006310c0
void FUN_006310c0_shell::FUN_006310c0()
{
    ((::BSSimpleList_Ragdoll *)(reinterpret_cast<::FUN_009d9f40_Class *>((((TESDataHandler*)this)))->FUN_009d9f40()))->FUN_006310e0();
}

struct FUN_00c9a520_shell
{
};
struct FUN_0062e940_shell
{
    void ProcessAndForward(const void* p);
};
// @fnv 0x0062e940
void FUN_0062e940_shell::ProcessAndForward(const void* p)
{
    void* q = FUN_004b5a80(p);
    reinterpret_cast<::ObstacleManagerC9A *>((((FUN_00c9a520_shell*)this)))->FUN_00c9a520((::ObstacleDataC9A *)(q));
}

struct FUN_00576830_shell
{
    void* FUN_00576830(BSOcclusionPlane* pPlane);
};

// Calls GetOcclusionPlaneThreadID on pPlane; if it returns non-null, calls FUN_00576830 on the object at offset 0x14 and returns its result, otherwise returns null.
// @fnv 0x0062fe80
void* FUN_0062fe80(BSOcclusionPlane* pPlane)
{
    void* result = 0;
    unsigned int cull = GetOcclusionPlaneThreadID(pPlane);
    if (cull)
        result = reinterpret_cast<FUN_00576830_shell*>(reinterpret_cast<char*>(cull) + 0x14)->FUN_00576830(pPlane);
    return result;
}

struct FUN_0062b0a0_shell
{
    void* FUN_0062b0a0(void* a, void* b);
};
struct FUN_00630100_shell
{
    void* FUN_00630100(void* arg);
};
// Calls FUN_0062b0a0 with arg and this, then returns arg.
// @fnv 0x00630100
void* FUN_00630100_shell::FUN_00630100(void* arg)
{
    ((FUN_0062b0a0_shell*)this)->FUN_0062b0a0(arg, this);
    return arg;
}

struct PackedByteIntRecord
{
    char* Endian();
};
// @fnv 0x006310e0
void* BSSimpleList_Ragdoll::FUN_006310e0()
{
    return (char*)((PackedByteIntRecord*)((char*)this + 0x10))->Endian() + 0x10;
}

struct UnkCall
{
};
struct VList
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
    virtual void Target(float a, int b);
};
struct FUN_00631100_shell
{
    void FUN_00631100(float a, int b);
};
// Calls FUN_00c9c1d0 on this, then forwards a and b to Target on the BGSRagdollList from TESDataHandler.
// @fnv 0x00631100
void FUN_00631100_shell::FUN_00631100(float afValue, int aiValue)
{
    reinterpret_cast<::hkpEntityC9C *>((((UnkCall*)this)))->FUN_00c9c1d0();
    ((VList*)((::BSSimpleList_Ragdoll *)(reinterpret_cast<::FUN_009d9f40_Class *>((((TESDataHandler*)this)))->FUN_009d9f40())))->Target(afValue, aiValue);
}

struct FUN_00c9c1d0_shell
{
};
struct ListCall00631140
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
    virtual void Target(float, int, int);
};
struct FUN_00631140_shell
{
    void FUN_00631140(float, int, int);
};
// Calls FUN_00c9c1d0 on this, then forwards a, b and c to Target on the BGSRagdollList from the data handler.
// @fnv 0x00631140
void FUN_00631140_shell::FUN_00631140(float afValue, int aiArg1, int aiArg2)
{
    reinterpret_cast<::hkpEntityC9C *>((((FUN_00c9c1d0_shell*)this)))->FUN_00c9c1d0();
    ((ListCall00631140*)((::BSSimpleList_Ragdoll *)(reinterpret_cast<::FUN_009d9f40_Class *>((((TESDataHandler*)this)))->FUN_009d9f40())))->Target(afValue, aiArg1, aiArg2);
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};

struct FUN_00631750_shell
{
    void* FUN_00631750();
};

// Sets the object's vtable pointer to DAT_0104e4bc, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00631750
void* FUN_00631750_shell::FUN_00631750()
{
    *(void**)this = &DAT_0104e4bc;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_00628f30_shell
{
    int m0;
    int m4;
    int m8;
    int m12;
    int m16;
    int m20;
    void FUN_00628f70(int arg);
    void SetFlag(int a, bool b);
};
// @fnv 0x00628f30
void FUN_00628f30_shell::SetFlag(int aiFlag, bool abSet)
{
    if (abSet)
        m16 |= aiFlag;
    else
        FUN_00628f70(aiFlag);
}

struct ArrSI
{
};
struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool(__cdecl*)(int const*, int const*));
};
struct FUN_0057b700_class
{
    int FUN_0057b730(int);
};
struct FUN_0062e500_shell : FUN_0057b700_class
{
    void FUN_0062e500(int a, int b);
};

// @fnv 0x0062e500
void FUN_0062e500_shell::FUN_0062e500(int aiKey, int auiValue)
{
    int ptarget2 = *(int*)((char*)this + 0x14) ? FUN_0057b730(aiKey) : 0;
    unsigned int uindex;
    if (ptarget2)
    {
        uindex = ((LS3de0*)((char*)ptarget2 + 0x50))->Find(*(unsigned int*)&auiValue, 0, FUN_009a3830);
        if (uindex != (unsigned int)-1)
            reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>((((LS3de0*)((char*)ptarget2 + 0x50))))->FUN_009a4320(uindex, 1);
        if (!((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((void *)(((ArrSI*)((char*)ptarget2 + 0x50))))->GetName())))
            reinterpret_cast<::Holder *>(this)->FUN_0061ff30((::Node *)(ptarget2));
    }
}

struct GameTimerRecord
{
};
struct FUN_0061fef0_Node
{
    void* FUN_0061fef0();
};
struct WaterZone;
struct FUN_0042f130
{
public:
    bool SetWaterZone(::WaterZone *);
};
struct XActor
{
};
struct FUN_0042f030_shell
{
};
struct FUN_006205e0_shell
{
};
struct ref_0084e3a0_shell
{
};
struct FUN_006312d0_shell
{
    void FUN_006312d0(void* apWaterRef);
};
// @fnv 0x006312d0
void FUN_006312d0_shell::FUN_006312d0(void* apWaterRef)
{
    void* pzone = FUN_0062fe80((BSOcclusionPlane*)apWaterRef);
    if (pzone)
    {
        GameTimerRecord* pentry = (GameTimerRecord*)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)(((GameTimerRecord*)pzone)))->FUN_00825c00();
        while (pentry)
        {
            XActor* pActor = (XActor*)((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ref_0084e3a0_shell*)((char*)pentry + 0x10))))->FUN_0084e3a0()));
            if (pActor)
            {
                while (((FUN_0042f130*)reinterpret_cast<::FUN_005d43c0_ *>((void *)(((XActor*)pActor)))->FUN_005d43c0())->SetWaterZone((::WaterZone *)(pzone)))
                    reinterpret_cast<::FUN_0042f030_cls *>((((FUN_0042f030_shell*)reinterpret_cast<::FUN_005d43c0_ *>((void *)(((XActor*)pActor)))->FUN_005d43c0())))->FUN_0042f030((::TESForm *)(pzone), 0);
            }
            pentry = (GameTimerRecord*)((FUN_0061fef0_Node*)pentry)->FUN_0061fef0();
        }
        reinterpret_cast<::NodeList620 *>((((FUN_006205e0_shell*)((char*)this + 0x14))))->RemoveNode((::Node620 *)(pzone));
    }
}

struct TESObjectREFR;
struct EffectSetting
{
};
class TESObjectREFR;
struct WaterZoneManager
{
    void* GetWaterZone(TESObjectREFR*, TESObjectREFR*, float);
public:
    void UpdateWaterZone(::TESObjectREFR *, ::TESObjectREFR *, float);
};
struct FUN_00631230_shell
{
    FUN_00631230_shell(TESObjectREFR*, void*);
    char m0[0x1c];
    void* pGroup;
};
struct FUN_00631180_shell
{
    FUN_00631230_shell* FUN_00631180(TESObjectREFR*, void*);
};
// Allocates a FUN_00631230_shell for apRef and apCol, stores the result of a call on the effect setting's object into pGroup, and returns it.
// @fnv 0x00631180
FUN_00631230_shell* FUN_00631180_shell::FUN_00631180(TESObjectREFR* apRef, void* apCol)
{
    FUN_00631230_shell* apWZone = new FUN_00631230_shell(apRef, apCol);
    apWZone->pGroup = ((WaterZoneManager*)(void*)((int)(::FUN_0070ec90((char *)(((EffectSetting*)g_TES))))))
                          ->GetWaterZone(apRef, (TESObjectREFR*)0, 0.0f);
    return apWZone;
}


struct RefList : LS3de0
{
    int list00;
    int list04;
    int list08;
    int list0C;
};

struct LinkBase
{
    int link00;
    int link04;
    int link08;
    int link0C;
    int link10;
    int link14;
    int link18;
    int link1C;
    int link20;
    int link24;
    int link28;
    int link2C;
    int link30;
    int link34;
    int link38;
    int link3C;
};

struct NodeHead
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct LinkedNode : NodeHead, LinkBase
{
    LinkedNode(int a, unsigned int b);
    static void* operator new(std::size_t size);
    static void operator delete(void*);
    RefList refs;
};

struct NodeOwner : FUN_0057b700_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LinkedNode* pHead;
    LinkedNode* FindOrCreateNode(int key, unsigned int ref, int arg);
};

// Looks up a node by key, adds ref to its ref list if missing, or creates and links a new node into the head list.
// @fnv 0x0062e3d0
LinkedNode* NodeOwner::FindOrCreateNode(int key, unsigned int ref, int arg)
{
    LinkedNode* pNode = pHead ? (LinkedNode*)FUN_0057b730(key) : 0;
    if (pNode)
    {
        if (pNode->refs.Find(ref, 0, FUN_009a3830) == -1)
            reinterpret_cast<::FUN_00438690 *>(&(pNode->refs))->FUN_007cb2e0((unsigned int *)&(ref));
    }
    else
    {
        pNode = new LinkedNode(key, ref);
        reinterpret_cast<::fnv_00620760::BGSZoneTargetListener *>((pNode))->SetFlags(arg, 1);
        reinterpret_cast<::CombatProcedure *>((pNode))->Initialize((::CombatController *)(pHead));
        pHead = pNode;
    }
    return pNode;
}

struct SpawnedBase
{
    SpawnedBase(int a, int b);
    virtual void Vf();
};

struct SpawnedSub
{
    SpawnedSub();
    ~SpawnedSub();
    unsigned int FUN_00719b20(const int* a, int b, bool(__cdecl* cmp)(int const*, int const*));
};

struct FUN_0062e590 : SpawnedBase
{
    FUN_0062e590(int a1, int a2);
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
    SpawnedSub m_50;
};

// Constructs the base with a1 and zero, then initializes m_50 from a2, falling back to FUN_007cb2e0 when FUN_00719b20 returns -1.
// @fnv 0x0062e590
FUN_0062e590::FUN_0062e590(int a1, int aiValue) : SpawnedBase(a1, 0), m_50()
{
    if (m_50.FUN_00719b20(&aiValue, 0, FUN_009a3830) == -1)
    {
        reinterpret_cast<::FUN_00438690 *>(&(m_50))->FUN_007cb2e0((unsigned int *)(&aiValue));
    }
}

struct FUN_00cb75d0
{
    virtual void OnEvent();
    void* owner;
    unsigned int flags;
    void* context;
    unsigned int referenceCount;
    FUN_00cb75d0();
    ~FUN_00cb75d0();
};
struct FUN_0061ffb0
{
    virtual void Update();
    unsigned int state;
    FUN_0061ffb0();
    ~FUN_0061ffb0();
};
struct FUN_0048f200
{
    FUN_0048f200();
    ~FUN_0048f200();
};
struct FUN_0062e630 : FUN_00cb75d0, FUN_0061ffb0
{
    float scale;
    int* data;
    unsigned int capacity;
    unsigned int enabled;
    int predecessor;
    int successor;
    FUN_0048f200 synchronization;
    FUN_0062e630(float value);
};
// Initializes the object: sets scale to 1.0, enabled to 1, allocates data, calls SetValueAt with value, and clears predecessor and successor.
// @fnv 0x0062e630
FUN_0062e630::FUN_0062e630(float value) : scale(1.0f)
{
    enabled = 1;
    data = new int;
    reinterpret_cast<FUN_0062e710_shell*>(this)->SetValueAt(value, 0, 0);
    predecessor = 0;
    successor = 0;
}

struct S_0062f320_Tmp
{
    int unk00;
};
struct S_0062f320_Type
{
};
struct S_0062f320_Form
{
    S_0062f320_Type* FUN_0043b4f0(S_0062f320_Tmp* t);
};
struct S_0062f320_This
{
    S_0062f320_Form* FUN_0062f320(const char* name);
};
// Looks up a form by name in DAT_012681c0, rejects it if FUN_00517630 returns 5, and returns it only when FUN_0043b4d0 yields one of the listed values.
// @fnv 0x0062f320
S_0062f320_Form* S_0062f320_This::FUN_0062f320(const char* name)
{
    const char* akey = ((const char *)(::FUN_004b5a80(name)));
    S_0062f320_Form* bform = ((::S_0062f320_Form *)(::FUN_00653270((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012681c0))), (::NiObject *)(akey))));
    if (reinterpret_cast<::bhkRigidBody_shell *>((bform))->FUN_00517630() == 5)
    {
        return 0;
    }
    if (bform)
    {
        S_0062f320_Tmp tmp;
        switch (reinterpret_cast<::FUN_0043b4d0_shell *>((bform->FUN_0043b4f0(&tmp)))->FUN_0043b4d0())
        {
        case 4:
        case 5:
        case 6:
        case 8:
        case 10:
        case 12:
        case 13:
        case 14:
        case 29:
            return bform;
        }
    }
    return 0;
}

struct S_0062f5b0_Obj;

struct S_0062f5b0_Ptr
{
    S_0062f5b0_Obj* unk0;
    S_0062f5b0_Ptr(S_0062f5b0_Obj* p);
    ~S_0062f5b0_Ptr();
};

struct S_0062f5b0_Sub
{
};


struct S_0062f5b0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    S_0062f5b0_Sub unk0c;
    bool FUN_0062f5b0(void* a, int b);
};

// Wraps the object returned by FUN_004b59f0 in a scoped pointer, passes it to unk0c.FUN_00631540, and returns false.
// @fnv 0x0062f5b0
bool S_0062f5b0_Cls::FUN_0062f5b0(void* a, int b)
{
    bool result = false;
    {
        S_0062f5b0_Ptr p(((::S_0062f5b0_Obj *)(::FUN_004b59f0(a))));
        reinterpret_cast<::fnv_00631540::TargetClass *>(&(unk0c))->FUN_00631540((const ::NiPointer< ::NiNode> &)(p));
    }
    return result;
}


struct LocalObj
{
    unsigned int unk00;
    LocalObj(void* src);
    ~LocalObj();
};

struct MemberObj
{
    unsigned int unk00;
};

struct FUN_0062f630_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    MemberObj m_0c;

    bool ApplyToMember(int a, int unused);
};

// Builds a LocalObj from FUN_004b59f0(a), passes it to m_0c.FUN_00631620, then returns true.
// @fnv 0x0062f630
bool FUN_0062f630_cls::ApplyToMember(int a, int unused)
{
    bool done = false;
    {
        LocalObj tmp(::FUN_004b59f0((const void *)(a)));
        reinterpret_cast<::ListReader *>(&(m_0c))->FUN_00631620((*(const ::NodeValue *)(&tmp)));
    }
    done = true;
    return done;
}


class B630120Grid
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
    float* m_pfValues;
    int unk24;
    unsigned int m_uiSize;

    float GetValue(unsigned int uiX, unsigned int uiY);
};

// Returns the grid value at (uiX, uiY) if the computed index is within m_uiSize squared, otherwise g_fB630120Invalid.
// @fnv 0x00630120
float B630120Grid::GetValue(unsigned int uiX, unsigned int uiY)
{
    unsigned int uiIndex = uiY * m_uiSize + uiX;
    return uiIndex < m_uiSize * m_uiSize ? m_pfValues[uiIndex] : ::DAT_01015f5c;
}

struct Vec3_62e970
{
    float x;
    float y;
    float z;
    Vec3_62e970();
};
struct FilterTmp_62e970
{
    int unk00;
};
struct Filter_62e970
{
};
struct Body_62e970
{
    Filter_62e970* FUN_0043b4f0(FilterTmp_62e970* t);
};
struct FloatSetting_62e970
{
};
struct Splash_62e970
{
};
struct TES_62e970
{
};
struct TaskQueue_62e970
{
};

struct WaterSplash_62e970
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float fCooldown;
    void SpawnWaterSplash(Body_62e970* apBody, float afWaterZ);
};

class GameSettingCollection;
union SETTING_VALUE
{
    float f;
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

class GlobalObject_0040e0b0
{
  public:
};

class GlobalObject_0040c150
{
  public:
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting981;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting982;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting983;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting987;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting988;

class BSSoundHandleEx
{
  public:
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx& rhs);
};

class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct ThreeByThreeMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    ThreeByThreeMatrix();
};

struct TESWaterForm
{
};

class TESObjectCELL
{
  public:
};

class PlayerCharacter
{
  public:
    TESObjectCELL* GetParentCell();
};


void* __cdecl FUN_00689210(TESObjectCELL* cell, float f1, const char* str, ThreeByThreeMatrix mat, NiPoint3 pos, float f2,
                           int b1, void* p0);

struct TESWaterSystemMgr
{
};

class TES_Ext
{
  public:
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
};
// @fnv 0x0062e970
void WaterSplash_62e970::SpawnWaterSplash(Body_62e970* apBody, float afWaterZ)
{
    FilterTmp_62e970 tmp4;
    float fMass;
    float fScale;
    float fSpeed;
    float fHeight4;

    if (!apBody || fCooldown > 0.0)
        return;
    if (reinterpret_cast<::FUN_0043b4d0_shell *>((apBody->FUN_0043b4f0(&tmp4)))->FUN_0043b4d0() == 8)
        return;
    fMass = FUN_004b5400(apBody);
    Vec3_62e970 vel;
    reinterpret_cast<::FUN_00560d50_Struct *>((apBody))->FUN_00560d50((const ::hkVector4 &)(vel));
    fSpeed = ((float)(::FUN_00408820(vel.z)));
    if (fSpeed < 0.001)
        return;
    fScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting_62e970 *>(&::originalRuntimeFloatSetting985)))))) * fSpeed + fMass;
    if (vel.z > 0.0)
        fScale = fScale * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting_62e970 *>(&::originalRuntimeFloatSetting986))))));
    Vec3_62e970 _pos;
    reinterpret_cast<::QueryOwner *>((apBody))->FUN_00560bc0((std::intptr_t)&(_pos));
    fHeight4 = afWaterZ;
    if (!((void *)(reinterpret_cast<::BGSCameraPath *>((((TES_62e970*)g_TES)))->GetPrevPath())) && reinterpret_cast<::FUN_004572e0_shell *>((((TES_62e970*)g_TES)))->GetLandHeightAt((const ::NiPoint3 &)(_pos), fHeight4) &&
        fHeight4 > afWaterZ)
        return;
    _pos.z = afWaterZ;
    if (!FUN_008c7aa0())
        ::FUN_0062eb50(fScale, (*(::NiPoint3 *)&(const ::Vec3_62e970 &)(_pos)));
    else
        reinterpret_cast<::FUN_0087b700_shell *>((((::TaskQueue_62e970 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b700(fScale, (::NiPoint3 *)(::Vec3_62e970 *)(&_pos));
    if (!FUN_008c7aa0())
        reinterpret_cast<::fnv_004e8510::OwnerW *>((((::Splash_62e970 *)(::FUN_0070ec90((char *)(((TES_62e970*)g_TES)))))))->SpawnGroupNodeNearPlayer((*(float *)&(const ::Vec3_62e970 &)(_pos)), ::DAT_01013ea4, {}, {});
    else
        reinterpret_cast<::Holder *>((((::TaskQueue_62e970 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b760(::DAT_01013ea4, (::NiPoint3 *)(::Vec3_62e970 *)(&_pos));
    fCooldown = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting_62e970 *>(&::originalRuntimeFloatSetting984))))));
}

// @fnv 0x0062eb50
void __cdecl FUN_0062eb50(float a1, NiPoint3 aPosition)
{
    float fMult = 1.0f;
    BSSoundHandleEx kSound;

    if (a1 > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting981))))->f)
    {
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(kSound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("CWaterLarge", 0x102))));
        fMult = *((float *)&(::FUN_00403e20((float *)&(g_011d1458))));
    }
    if (!reinterpret_cast<::SoundPlaybackHandle *>(&(kSound))->IsValid() && a1 > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting982))))->f)
    {
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(kSound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("CWaterMedium", 0x102))));
        fMult = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting987))))->f;
    }
    if (!reinterpret_cast<::SoundPlaybackHandle *>(&(kSound))->IsValid() && a1 > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting983))))->f)
    {
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(kSound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("CWaterSmall", 0x102))));
        fMult = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting988))))->f;
    }
    if (reinterpret_cast<::SoundPlaybackHandle *>(&(kSound))->IsValid())
    {
        reinterpret_cast<::FUN_00ad8b60_h *>(&(kSound))->FUN_00ad8b60(aPosition.x, aPosition.y, aPosition.z);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(kSound))->FUN_00ad8830(false);
        if (fMult > 0.0 && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((_g_thePlayer))->GetTarget())) && reinterpret_cast<::FUN_00547770_shell *>((((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((_g_thePlayer))->GetTarget()))))->FUN_00547770() &&
            !reinterpret_cast<::FUN_00580060_shell *>((reinterpret_cast<::FUN_00547770_shell *>((((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((_g_thePlayer))->GetTarget()))))->FUN_00547770()))->FUN_00580060())
        {
            ThreeByThreeMatrix kMat;
            reinterpret_cast<::FUN_004a0c90_shell *>(&(kMat))->FUN_004a0c90(::FUN_004a4240());
            FUN_00689210(((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((_g_thePlayer))->GetTarget())), 1.0f, ((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d12c0))->GetMenuTitle())), kMat, aPosition, fMult, 1, 0);
        }
    }
    if (!FUN_008c7aa0())
    {
        reinterpret_cast<::fnv_004e8510::OwnerW *>((((::TESWaterSystemMgr *)(::FUN_0070ec90((char *)(((TES_Ext*)g_TES)))))))->SpawnGroupNodeNearPlayer((*(float *)&(const ::NiPoint3 &)(aPosition)), 0.01f, {}, {});
    }
    else
    {
        reinterpret_cast<::Holder *>((TaskQueueInterface::GetSingleton()))->FUN_0087b760(0.01f, &aPosition);
    }
}

#include <xmmintrin.h>
struct FUN_00630d30_cls
{
    __m128 m_vec;
    void FUN_00630d30(const __m128* a, const __m128* b);
};
// Adds the element-wise product of two vectors to m_vec using SSE intrinsics.
// @fnv 0x00630d30
void FUN_00630d30_cls::FUN_00630d30(const __m128* apFirst, const __m128* apSecond)
{
    m_vec = _mm_add_ps(m_vec, _mm_mul_ps(*apFirst, *apSecond));
}

struct B631230Stats
{
    int unk00;
    int unk04;
    float m_fValue;
};

class B631230Actor
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void vfunc4F();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual void vfunc56();
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc5A();
    virtual void vfunc5B();
    virtual void vfunc5C();
    virtual void vfunc5D();
    virtual void vfunc5E();
    virtual void vfunc5F();
    virtual void vfunc60();
    virtual void vfunc61();
    virtual void vfunc62();
    virtual void vfunc63();
    virtual void vfunc64();
    virtual void vfunc65();
    virtual void vfunc66();
    virtual void vfunc67();
    virtual void vfunc68();
    virtual void vfunc69();
    virtual void vfunc6A();
    virtual void vfunc6B();
    virtual void vfunc6C();
    virtual void vfunc6D();
    virtual void vfunc6E();
    virtual void vfunc6F();
    virtual void vfunc70();
    virtual void vfunc71();
    virtual void vfunc72();
    virtual void vfunc73();
    virtual void vfunc74();
    virtual void vfunc75();
    virtual void vfunc76();
    virtual void vfunc77();
    virtual void vfunc78();
    virtual void vfunc79();
    virtual void vfunc7A();
    virtual void vfunc7B();
    virtual void vfunc7C();
    virtual B631230Stats* GetStats();
};

class B631230Base
{
  public:
    B631230Base(B631230Actor* pkActor, unsigned int uiType);
    virtual ~B631230Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_00631230 : public B631230Base
{
  public:
    float m_fStartValue;
    int m_iArrayLength;

    FUN_00631230(B631230Actor* pkActor, unsigned int uiType);
    virtual ~FUN_00631230();
};

// @fnv 0x00631230
FUN_00631230::FUN_00631230(B631230Actor* pkActor, unsigned int uiType) : B631230Base(pkActor, uiType)
{
    m_fStartValue = pkActor ? pkActor->GetStats()->m_fValue : 0.0f;
    m_iArrayLength = 0;
}

class TESBoundObject
{
  public:
    virtual void vf0();
};
class BGSPlaceableWater : public TESBoundObject
{
  public:
};
struct PhysBody
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
    virtual PhysBody* Body();
};
struct Collision
{
};
struct Scene
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
    virtual Collision* CollisionData();
};
struct SceneHolder
{
};
struct WaterForm
{
};
struct TESObjectREFR
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
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual int WaterType();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual SceneHolder* BoneTransformData();
};
struct Cell
{
};
struct PlayerExtra
{
};
struct RefHolder
{
};
struct WaterSub
{
};
struct WaterEntry
{
    int unk00;
    WaterSub sub;
};
struct Player
{
};
struct PlayerHandle
{
};
struct SettingWater
{
    unsigned char* Bool();
};
void FUN_0062f8f0(float);
void FUN_0062f8e0(unsigned char);
void FUN_0062f310(int);
struct WaterRecord
{
    TESObjectREFR* reference;
    PhysBody* body;
    TESObjectREFR* water;
    struct Group* group;
    void* source;
};
struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* data;
};
struct GroupMap
{
};
struct RecordList
{
};
struct EventWater
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* water;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    void* reference;
};
struct WaterManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    GroupMap* groups;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    RecordList records;
    bool FUN_0062f900(EventWater* event);
};
struct WaterPosition
{
    float x;
    float y;
    float z;
};
struct WaterContactPositionView
{
    virtual void Virtual000();
    virtual void Virtual001();
    virtual void Virtual002();
    virtual void Virtual003();
    virtual void Virtual004();
    virtual void Virtual005();
    virtual void Virtual006();
    virtual void Virtual007();
    virtual void Virtual008();
    virtual void Virtual009();
    virtual void Virtual010();
    virtual void Virtual011();
    virtual void Virtual012();
    virtual void Virtual013();
    virtual void Virtual014();
    virtual void Virtual015();
    virtual void Virtual016();
    virtual void Virtual017();
    virtual void Virtual018();
    virtual void Virtual019();
    virtual void Virtual020();
    virtual void Virtual021();
    virtual void Virtual022();
    virtual void Virtual023();
    virtual void Virtual024();
    virtual void Virtual025();
    virtual void Virtual026();
    virtual void Virtual027();
    virtual void Virtual028();
    virtual void Virtual029();
    virtual void Virtual030();
    virtual void Virtual031();
    virtual void Virtual032();
    virtual void Virtual033();
    virtual void Virtual034();
    virtual void Virtual035();
    virtual void Virtual036();
    virtual void Virtual037();
    virtual void Virtual038();
    virtual void Virtual039();
    virtual void Virtual040();
    virtual void Virtual041();
    virtual void Virtual042();
    virtual void Virtual043();
    virtual void Virtual044();
    virtual void Virtual045();
    virtual void Virtual046();
    virtual void Virtual047();
    virtual void Virtual048();
    virtual void Virtual049();
    virtual void Virtual050();
    virtual void Virtual051();
    virtual void Virtual052();
    virtual void Virtual053();
    virtual void Virtual054();
    virtual void Virtual055();
    virtual void Virtual056();
    virtual void Virtual057();
    virtual void Virtual058();
    virtual void Virtual059();
    virtual void Virtual060();
    virtual void Virtual061();
    virtual void Virtual062();
    virtual void Virtual063();
    virtual void Virtual064();
    virtual void Virtual065();
    virtual void Virtual066();
    virtual void Virtual067();
    virtual void Virtual068();
    virtual void Virtual069();
    virtual void Virtual070();
    virtual void Virtual071();
    virtual void Virtual072();
    virtual void Virtual073();
    virtual void Virtual074();
    virtual void Virtual075();
    virtual void Virtual076();
    virtual void Virtual077();
    virtual void Virtual078();
    virtual void Virtual079();
    virtual void Virtual080();
    virtual void Virtual081();
    virtual void Virtual082();
    virtual void Virtual083();
    virtual void Virtual084();
    virtual void Virtual085();
    virtual void Virtual086();
    virtual void Virtual087();
    virtual void Virtual088();
    virtual void Virtual089();
    virtual void Virtual090();
    virtual void Virtual091();
    virtual void Virtual092();
    virtual void Virtual093();
    virtual void Virtual094();
    virtual void Virtual095();
    virtual void Virtual096();
    virtual void Virtual097();
    virtual void Virtual098();
    virtual void Virtual099();
    virtual void Virtual100();
    virtual void Virtual101();
    virtual void Virtual102();
    virtual void Virtual103();
    virtual void Virtual104();
    virtual void Virtual105();
    virtual void Virtual106();
    virtual void Virtual107();
    virtual void Virtual108();
    virtual void Virtual109();
    virtual void Virtual110();
    virtual void Virtual111();
    virtual void Virtual112();
    virtual void Virtual113();
    virtual void Virtual114();
    virtual void Virtual115();
    virtual void Virtual116();
    virtual void Virtual117();
    virtual void Virtual118();
    virtual void Virtual119();
    virtual void Virtual120();
    virtual void Virtual121();
    virtual void Virtual122();
    virtual void Virtual123();
    virtual void Virtual124();
    virtual WaterPosition* GetWaterPosition();
};
struct PlayerWaterReference
{
};
struct WaterContactReference : TESObjectREFR
{
};
struct PlayerWater : TESObjectREFR
{
};
struct WaterRequest
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    void* source;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* destination;
};
struct WaterUpdates
{
};
struct WaterTaskQueue
{
};
struct WaterContactManager
{
};
struct TESWaterAccess
{
};
struct WaterOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    WaterUpdates updates;
    bool FUN_0062f6b0(WaterRequest* request);
};
// Processes a water request by resolving source and destination references, checking restrictions, and dispatching water contact updates.
// @fnv 0x0062f6b0
bool WaterOwner::FUN_0062f6b0(WaterRequest* request)
{
    bool e = false;
    TESObjectREFR* d = FUN_0062b4e0(request->destination);
    if (!d)
    {
        if (request->destination == reinterpret_cast<::FUN_0043b560_shell *>((((::PlayerWaterReference *)(reinterpret_cast<::FUN_0061f6c0_shell *>((((PlayerWater*)_g_thePlayer)))->FUN_0061f6c0()))))->GetSourceFilesFromObject())
        {
            TESObjectREFR* f = FUN_0062b4e0(request->source);
            if (!f)
                return false;
            BGSPlaceableWater* g = dynamic_cast<BGSPlaceableWater*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((f))->FUN_007af430())));
            if (!*(*reinterpret_cast<::SettingWater *>(&::g_011cc5a8)).Bool() && reinterpret_cast<::FUN_00452440_shell *>((g))->FUN_00452440())
                return false;
            FUN_0062f8f0(((WaterContactPositionView*)f)->GetWaterPosition()->z);
            ::FUN_00575c90(1);
            FUN_0062f8e0(1);
            FUN_0062f310(((TESObjectREFR*)g)->WaterType());
            return true;
        }
        return false;
    }
    TESObjectREFR* b = FUN_0062b4e0(request->source);
    if (!b)
        return false;
    BGSPlaceableWater* c = dynamic_cast<BGSPlaceableWater*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((b))->FUN_007af430())));
    if (!*(*reinterpret_cast<::SettingWater *>(&::g_011cc5a8)).Bool() && reinterpret_cast<::FUN_00452440_shell *>((c))->FUN_00452440())
        return false;
    if (d == (TESObjectREFR*)_g_thePlayer)
        FUN_0062f310(((TESObjectREFR*)c)->WaterType());
    void* a = ((void *)(reinterpret_cast<::ImpactManager620 *>(&(updates))->FUN_00620340((::CollisionInfo620 *)(request), b, d, (void *)(0), 0)));
    reinterpret_cast<::FUN_0057b0d0_cls *>((((WaterContactReference*)d)))->FUN_0057b0d0((int)(a), 1);
    if (FUN_008c7aa0() && ((::WaterTaskQueue *)(::TaskQueueInterface::GetSingleton())))
    {
        reinterpret_cast<::FakeTaskQueue *>((((::WaterTaskQueue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b4a0((int)(b), (int)(d), 0.0f);
    }
    else
    {
        WaterContactManager* h = ((::WaterContactManager *)(::FUN_0070ec90((char *)(((TESWaterAccess*)g_TES)))));
        reinterpret_cast<::Target5c80 *>((h))->AddObjectToEntry(b, (::Object5c80 *)(d), 0.0f);
    }
    reinterpret_cast<::fnv_00631370::WorkOwner *>(this)->FUN_00631370((::fnv_00631370::WorkActor *)(d), 0, 1);
    return true;
}

struct RetStruct
{
    int unk00;
    int unk04;
    float unk08;
};

struct VBase125
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual RetStruct* Vf125();
};

class EffectItem;

class Ref_0062fc70 : public VBase125
{
  public:
    TESObjectCELL* GetParentCell();
};

class EffectItem
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* unk1c;
};

struct NiTMap
{
};

struct EDL_Helper
{
};

struct Holder0087b4f0
{
    void FUN_0087b4f0(int a, int b, float c);
};



struct WaterGroupRemovalCall
{
};

struct ParamStruct
{
    Ref_0062fc70* unk00;
    FUN_00628f30_shell* unk04;
    Ref_0062fc70* unk08;
    EffectItem* unk0c;
    int unk10;
};

struct WaterZoneRemoval : WaterSplash_62e970
{
    void FUN_0062fc70(ParamStruct* param);
};
// Resolves the event's water and reference, checks restrictions, then handles the player case or records or processes the reference.
// @fnv 0x0062f900
bool WaterManager::FUN_0062f900(EventWater* event)
{
    bool f = false;
    TESObjectREFR* s = FUN_0062b4e0(event->reference);
    TESObjectREFR* eb = FUN_0062b4e0(event->water);
    if (!eb)
        return false;
    BGSPlaceableWater* i = dynamic_cast<BGSPlaceableWater*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((eb))->FUN_007af430())));
    if (!*(*reinterpret_cast<::SettingWater *>(&::g_011cc5a8)).Bool() && reinterpret_cast<::FUN_00452440_shell *>((i))->FUN_00452440())
        return false;
    Group* p = groups ? ((::Group *)(reinterpret_cast<::FUN_00620300_cls *>((groups))->FindDerivedByKey(event->water))) : 0;
    Group* q = p;
    void* cf = q ? q->data : 0;
    if (!s && ((::Cell *)(reinterpret_cast<::LowProcess *>((((Player*)_g_thePlayer)))->GetTarget())))
    {
        if (event->reference == reinterpret_cast<::FUN_0043b560_shell *>((((::PlayerHandle *)(reinterpret_cast<::FUN_0061f6c0_shell *>((((Player*)_g_thePlayer)))->FUN_0061f6c0()))))->GetSourceFilesFromObject())
        {
            ::FUN_00575c90(0);
            FUN_0062f8f0(reinterpret_cast<::FUN_005471e0_shell *>((((::Cell *)(reinterpret_cast<::LowProcess *>((((Player*)_g_thePlayer)))->GetTarget()))))->FUN_005471e0());
            FUN_0062f8e0(0);
            WaterEntry* entry = ((::WaterEntry *)(reinterpret_cast<::FUN_0042f180_cls *>((((::PlayerExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((((Player*)_g_thePlayer)))->FUN_005d43c0()))))->FUN_0042f180()));
            if (entry)
            {
                TESObjectREFR* ref = ((::TESObjectREFR *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RefHolder *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(entry->sub))->FUN_0084e3a0()))))->FUN_007af430()));
                FUN_0062f310(ref->WaterType());
            }
            else
            {
                FUN_0062f310(((int)(reinterpret_cast<::FUN_00547770_shell *>((((::Cell *)(reinterpret_cast<::LowProcess *>((((Player*)_g_thePlayer)))->GetTarget()))))->FUN_00547770())));
            }
            return true;
        }
        return false;
    }
    else if (!s)
    {
        return false;
    }
    else if (reinterpret_cast<::FUN_00440d80_shell *>((s))->FUN_00440d80())
    {
        return false;
    }
    PhysBody* a = 0;
    Scene* h = ((::Scene *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((s->BoneTransformData()))->FUN_006838b0()));
    if (h)
    {
        Collision* collision = h->CollisionData();
        if (collision)
        {
            PhysBody* world = ((::PhysBody *)(::fnv_006fa820::FUN_006fa820((const char *)(collision))));
            if (world)
                a = world->Body();
        }
    }
    {
        void* p;
        int h;
        bool found8;
        WaterRecord* item5;
        WaterRecord* record3;
        WaterRecord recordX;
        unsigned int size;
        void* allocationX;
        if (a)
        {
            p = ((void *)(::FUN_00559450((int *)&(records))));
            h = 0;
            found8 = false;
            while (p)
            {
                item5 = ((::WaterRecord *)(reinterpret_cast<::FUN_006317a0_struct *>(&(records))->AddEight((int)(p))));
                p = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(records))->DereferenceIfNotNull((int **)(p))));
                if (item5->body == a)
                {
                    found8 = true;
                    break;
                }
            }
            if (!found8)
            {
                size = sizeof(WaterRecord);
                allocationX = ::FUN_00401000(size);
                record3 = allocationX ? (std::memset(allocationX, 0, size), (WaterRecord*)allocationX) : 0;
                record3->reference = s;
                record3->body = a;
                record3->water = eb;
                record3->group = q;
                record3->source = event->reference;
                reinterpret_cast<::FUN_004700d0_class *>(&(records))->FUN_004700d0((int *)&(record3));
            }
        }
        else
        {

            recordX.reference = s;
            recordX.body = a;
            recordX.water = eb;
            recordX.group = q;
            recordX.source = event->reference;
            reinterpret_cast<::WaterZoneRemoval *>(this)->FUN_0062fc70((::ParamStruct *)(::WaterRecord *)(&recordX));
        }
    }
    return true;
}

// @fnv 0x0062fc70
void WaterZoneRemoval::FUN_0062fc70(ParamStruct* apParams)
{
    bool b5;
    bool b8 = false;
    bool b9;
    void* var_8 = apParams->unk0c ? apParams->unk0c->unk1c : 0;

    if (apParams->unk00 == (Ref_0062fc70*)_g_thePlayer && b8)
    {
        if (((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((_g_thePlayer))->GetTarget())))
        {
            FUN_0062f310((int)reinterpret_cast<::FUN_00547770_shell *>((((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((_g_thePlayer))->GetTarget()))))->FUN_00547770());
        }
    }

    b9 = false;
    if (apParams->unk0c)
    {
        reinterpret_cast<::FUN_0062e500_shell *>((apParams->unk0c))->FUN_0062e500((int)(apParams->unk00), apParams->unk10);
        if (!((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((apParams->unk0c))->FUN_00825c00())))
        {
            b9 = true;
        }
    }

    if (apParams->unk04)
    {
        this->SpawnWaterSplash((Body_62e970*)apParams->unk04, apParams->unk08->Vf125()->unk08);
        apParams->unk04->SetFlag(0x80, false);
    }

    if (apParams->unk0c)
    {
        reinterpret_cast<::FUN_0057b0d0_cls *>((apParams->unk00))->FUN_0057b0d0((int)(apParams->unk0c), 0);
    }
    reinterpret_cast<::Ref57b240 *>((apParams->unk00))->FUN_0057b240(0);

    b5 = true;
    if (!((int)(reinterpret_cast<::FUN_0042f180_cls *>((((EDL_Helper*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((apParams->unk00))->FUN_005d43c0())))))->FUN_0042f180())))
    {
        NiTMap* map4 = ((::NiTMap *)(reinterpret_cast<::FUN_0042f1d0_shell *>((((EDL_Helper*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((apParams->unk00))->FUN_005d43c0())))))->FUN_0042f1d0()));
        if (map4)
        {
            void* pos4 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((map4))->GetFirstPos();
            while (pos4)
            {
                void* val = 0;
                unsigned int keyTmp = 0;
                reinterpret_cast<::C6b7f20_Map *>((map4))->FUN_006b7f20((::C6b7f20_Node **)&(pos4), (unsigned int *)&(keyTmp), (void **)&(val));
                if (var_8 != 0 && ((EffectItem*)keyTmp)->unk1c == var_8)
                {
                    b5 = false;
                    break;
                }
            }
        }
    }

    if (b5)
    {
        if (FUN_008c7aa0() && TaskQueueInterface::GetSingleton())
        {
            ((Holder0087b4f0*)TaskQueueInterface::GetSingleton())
                ->FUN_0087b4f0((int)apParams->unk08, (int)apParams->unk00, 0.0f);
        }
        else
        {
            WaterGroupRemovalCall* pWaterSystem7 = (WaterGroupRemovalCall*)FUN_0070ec90((char*)g_TES);
            reinterpret_cast<::WaterZoneManager *>((pWaterSystem7))->UpdateWaterZone((TESObjectREFR*)apParams->unk08, (TESObjectREFR*)apParams->unk00, 0.0f);
        }
    }
}

void FUN_0062f8e0(unsigned char value);

unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane);

float FUN_00630aa0(float value);

extern "C" double __cdecl _exp(double);

float ExpFloat(float value);

struct FUN_00c9a460_shell
{
    void FUN_00c9a600(int a);
};

// @fnv 0x00c9a600
void FUN_00c9a460_shell::FUN_00c9a600(int a)
{
    int r = ((int(*)(void*, int))(*reinterpret_cast<void***>(this))[9])(this, a);
    reinterpret_cast<::OwnerC9Body *>(this)->AddObject((::RefObjectC9 *)(r));
}

struct PhysicsVector
{
    __m128 m_vComponents;
    void FUN_005dbf20(float);
    PhysicsVector* FUN_00630b40(PhysicsVector*);
};

struct PhysicsBounds
{
    PhysicsVector minimum, maximum;
};

struct FUN_005dbf20 : PhysicsVector
{
    FUN_005dbf20(float);
};

struct PhysicsBody
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void GetRotation(PhysicsVector*);
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void GetBounds(PhysicsBounds*);
};

struct PhysicsReference
{
    const PhysicsVector* FUN_004b4ec0();
    const PhysicsVector* FUN_006310c0();
    const PhysicsVector* FUN_00560e50();
};

float FUN_00408840(float);

extern float DAT_0119af4c, DAT_0119af48, DAT_0119af44;

extern float DAT_0119af40, DAT_011cc5e4, DAT_011cc5e0, DAT_0119af3c, DAT_0119af38;

struct RuntimeFloatSetting
{
};

struct ReferenceMap
{
};

struct PhysicsController_o2_od_noo2
{
    int FUN_00630170(PhysicsReference*, float, float, bool);
};

// @fnv 0x00630170
int PhysicsController_o2_od_noo2::FUN_00630170(PhysicsReference* reference, float height, float deltaTime, bool alternate)
{
    int result = 0;
    PhysicsVector position;
    new ((void *)&(position)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(reference->FUN_004b4ec0())));
    PhysicsBody* body = ((::PhysicsBody *)(::FUN_004b5a80(reference)));
    PhysicsBounds bounds;
    new ((void *)&(bounds)) ::fnv_00437c10::FUN_00437c10();
    body->GetBounds(&bounds);
    if (reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2) <= height)
    {
        int handle = ::FUN_00517670((::TESDataHandler *)(reference));
        if (((bool)(::FUN_00c8cce0(&handle))))
        {
            PhysicsReference* state = ((::PhysicsReference *)(reinterpret_cast<::Twin_0044ddc0 *>((reference))->GetName()));
            if (state)
            {
                reinterpret_cast<::TESForm *>((state))->ClearData();
                PhysicsVector direction;
                new ((void *)&(direction)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((const ::PhysicsVector *)(::FUN_00460140((int)(state)))))));
                PhysicsVector velocity;
                new ((void *)&(velocity)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((const ::PhysicsVector *)(::FUN_00560dc0((::TESDataHandler *)(reference)))))));
                float mass = reinterpret_cast<::fnv_004b4ea0::TESDataHandler *>((reference))->FUN_004b4ea0();
                float extent = reinterpret_cast<::bhkCharacterController *>(&(bounds.maximum))->GetVectorElement(2) - reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2);
                float lower = extent * 0.25 + reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2);
                float upper = extent * 0.8500000238418579 + reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2);
                float amount = (height - lower) / (upper - lower);
                if (amount <= 0.0)
                {
                    reinterpret_cast<::TESForm *>((state))->ClearData();
                    return result;
                }
                float strength = ::GetObjectMass((::WorldObject62b3 *)(body));
                bool dampVertical = true;
                if (amount < DAT_0119af4c && strength > 0.0)
                {
                    if (amount > DAT_0119af48)
                        strength = DAT_0119af44;
                    else if (amount > DAT_0119af40)
                        strength = DAT_011cc5e4;
                    else if (amount > DAT_011cc5e0)
                        strength = DAT_0119af3c;
                    PhysicsVector component;
                    if (DAT_0119af38 > FUN_00408840(reinterpret_cast<::S004586d0_Obj *>((((::PhysicsVector *)(reinterpret_cast<::Holder *>(&(velocity))->FUN_00458700((::Holder *)(::PhysicsVector *)(&component), 2)))))->FUN_004586d0()))
                        dampVertical = false;
                }
                strength = -strength;
                PhysicsVector force;
                FUN_005dbf20 multiplier(strength * mass);
                reinterpret_cast<::S00630ae0_Result *>(&(force))->FUN_00630ae0((const ::S00630ae0_Source *)(const ::PhysicsVector *)(&multiplier), (const ::S00630ae0_Vector *)(const ::PhysicsVector *)(&direction));
                PhysicsVector torque;
                if (!::FUN_00c9c380((void *)(reference), {}))
                {
                    PhysicsBounds inertiaBounds;
                    new ((void *)&(inertiaBounds)) ::fnv_00437c10::FUN_00437c10();
                    reinterpret_cast<::WorldObject_c8d3 *>((body))->GetAabb((*(::Aabb_c8d3 *)(&inertiaBounds)));
                    PhysicsVector localTorque;
                    reinterpret_cast<::FUN_005532a0_cls *>(&(localTorque))->FUN_005532a0(0, 0, 0, 0);
                    PhysicsVector sizes;
                    reinterpret_cast<::S00458a10_Vector *>(&(sizes))->FUN_00458a10((const ::S00458a10_Vector *)(const ::PhysicsVector *)(&inertiaBounds.maximum), (const ::S00458a10_Vector *)(const ::PhysicsVector *)(&inertiaBounds.minimum));
                    int smallest = reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) < reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1)
                                       ? (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1) < reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 1)
                                       : (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) < reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 0);
                    int largest = reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1)
                                      ? (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 1)
                                      : (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 0);
                    if (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(smallest) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(largest) * 1.5f)
                    {
                        reinterpret_cast<::bhkCharacterController *>(&(localTorque))->GetVectorElement(largest) =
                            reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(smallest) / reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(largest) * 0.1f * SignOfFloat(strength);
                        PhysicsVector rotation;
                        ::FUN_006240d0((void *)&(rotation));
                        body->GetRotation(&rotation);
                        reinterpret_cast<::FUN_00630bb0_shell *>(&(torque))->FUN_00630bb0((::Source630 *)(&rotation), (void *)(&localTorque));
                        reinterpret_cast<::V *>(&(torque))->FUN_00553f70((*(const ::V *)(reference->FUN_006310c0())));
                    }
                    else
                        reinterpret_cast<::AlignedVector *>(&(torque))->FUN_004a3f10((*(const ::AlignedVector *)(reference->FUN_006310c0())));
                }
                else
                    reinterpret_cast<::AlignedVector *>(&(torque))->FUN_004a3f10((*(const ::AlignedVector *)(reference->FUN_006310c0())));
                reinterpret_cast<::TESForm *>((state))->ClearData();
                reinterpret_cast<::FUN_00631140_shell *>((reference))->FUN_00631140(deltaTime, (int)(&force), (int)(&torque));
                PhysicsVector secondForce;
                FUN_005dbf20 secondMultiplier(mass * -1.0);
                reinterpret_cast<::S00630ae0_Result *>(&(secondForce))->FUN_00630ae0((const ::S00630ae0_Source *)(const ::PhysicsVector *)(&secondMultiplier), (const ::S00630ae0_Vector *)(const ::PhysicsVector *)(&direction));
                reinterpret_cast<::FUN_00631100_shell *>((reference))->FUN_00631100(deltaTime, (int)(&secondForce));
                reinterpret_cast<::TESForm *>((state))->ClearData();
                PhysicsVector linear;
                new ((void *)&(linear)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((const ::PhysicsVector *)(::FUN_00560dc0((::TESDataHandler *)(reference)))))));
                float vertical = reinterpret_cast<::bhkCharacterController *>(&(linear))->GetVectorElement(2);
                reinterpret_cast<::bhkCharacterController *>(&(linear))->GetVectorElement(2) = 0;
                if (dampVertical)
                {
                    vertical *= FUN_00630aa0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting979)))))) * -1.0 * deltaTime);
                }
                PhysicsVector magnitude;
                if (reinterpret_cast<::S004586d0_Obj *>((linear.FUN_00630b40(&magnitude)))->FUN_004586d0() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting975)))))))
                {
                    FUN_005dbf20 factor(FUN_00630aa0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting978)))))) * -1.0 * deltaTime));
                    reinterpret_cast<::S_00627920 *>(&(linear))->FUN_00627920((::S_00561240 *)(&factor));
                }
                reinterpret_cast<::bhkCharacterController *>(&(linear))->GetVectorElement(2) = vertical;
                reinterpret_cast<::FUN_005616d0_Owner *>((reference))->OnTrigger((::TriggerContext *)(&linear));
                PhysicsVector angular;
                new ((void *)&(angular)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(reference->FUN_00560e50())));
                FUN_005dbf20 factor(FUN_00630aa0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting980)))))) * -1.0 * deltaTime));
                reinterpret_cast<::S_00627920 *>(&(angular))->FUN_00627920((::S_00561240 *)(&factor));
                reinterpret_cast<::FUN_00561800_Class *>((reference))->FUN_00561800((::FUN_00561730_Obj *)(&angular));
                reinterpret_cast<::TESForm *>((state))->ClearData();
            }
        }
        int flag = alternate ? 128 : 8;
        if (!reinterpret_cast<::FUN_005631e0_shell *>((body))->IsNonZero(flag))
        {
            reinterpret_cast<::FUN_00628f30_shell *>((body))->SetFlag(flag, true);
            reinterpret_cast<::WaterSplash_62e970 *>(this)->SpawnWaterSplash((::Body_62e970 *)(body), FUN_004587d0(height));
            result = 1;
        }
        reinterpret_cast<::FUN_0084d310_class *>(&((*reinterpret_cast<::ReferenceMap *>(&::g_011cc584))))->FUN_0084d310((int)(reference), true);
    }
    else
    {
        int flag = alternate ? 128 : 8;
        if (reinterpret_cast<::FUN_005631e0_shell *>((body))->IsNonZero(flag))
        {
            reinterpret_cast<::WaterSplash_62e970 *>(this)->SpawnWaterSplash((::Body_62e970 *)(body), FUN_004587d0(height));
            result = 2;
        }
        reinterpret_cast<::FUN_00628f30_shell *>((body))->SetFlag(flag, false);
    }
    return result;
}

class S0062b0a0_SimdReal
{
  public:
    S0062b0a0_SimdReal(const __m128& q);  // FUN_004a3c90
    __m128 m_vValue;
};

class S0062b0a0_Vector
{
  public:
    S0062b0a0_SimdReal FUN_0062b0a0(const S0062b0a0_Vector& v) const;  // dot3
    __m128 m_vComponents;
};

// @fnv 0x0062b0a0
S0062b0a0_SimdReal S0062b0a0_Vector::FUN_0062b0a0(const S0062b0a0_Vector& v) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return S0062b0a0_SimdReal(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy));
}

class hkVector4E
{
  public:
    hkVector4E();
    __m128 m_vComponents;
};

class NiPoint3E
{
  public:
    float x, y, z;
};

class SettingE
{
  public:
};

class FlagE
{
  public:
    bool* Get();
};

class SoundE;

class ImpactObjE
{
  public:
};

class AudioE
{
  public:
};

class AudioMgrE
{
  public:
};

class InterfaceE
{
  public:
};

class BodyE;

class RefE
{
  public:
};

class RefPtrE
{
  public:
    RefE* operator->();
};

class ListNodeE
{
  public:
};

class LockE
{
  public:
};

class FormArrayE
{
  public:
};

class LinkE
{
  public:
};

class SpawnListBaseE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

class SpawnListE : public SpawnListBaseE, public LinkE
{
  public:
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
    FormArrayE m_kForms;
};

class CellLinkE
{
  public:
};

class CellBaseE
{
  public:
    int unk00;
};

class SpawnCellE : public CellBaseE, public CellLinkE
{
  public:
};

class ProcessE
{
  public:
};

class PlayerE
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
    virtual void vp100();
    virtual void vp104();
    virtual void vp108();
    virtual void vp10c();
    virtual void vp110();
    virtual void vp114();
    virtual void vp118();
    virtual void vp11c();
    virtual void vp120();
    virtual void vp124();
    virtual void vp128();
    virtual void vp12c();
    virtual void vp130();
    virtual void vp134();
    virtual void vp138();
    virtual void vp13c();
    virtual void vp140();
    virtual void vp144();
    virtual void vp148();
    virtual void vp14c();
    virtual void vp150();
    virtual void vp154();
    virtual void vp158();
    virtual void vp15c();
    virtual void vp160();
    virtual void vp164();
    virtual void vp168();
    virtual void vp16c();
    virtual void vp170();
    virtual void vp174();
    virtual void vp178();
    virtual void vp17c();
    virtual void vp180();
    virtual void vp184();
    virtual void vp188();
    virtual void vp18c();
    virtual void vp190();
    virtual void vp194();
    virtual void vp198();
    virtual void vp19c();
    virtual void vp1a0();
    virtual void vp1a4();
    virtual void vp1a8();
    virtual void vp1ac();
    virtual void vp1b0();
    virtual void vp1b4();
    virtual void vp1b8();
    virtual void vp1bc();
    virtual void vp1c0();
    virtual void vp1c4();
    virtual void vp1c8();
    virtual void vp1cc();
    virtual void vp1d0();
    virtual void vp1d4();
    virtual void vp1d8();
    virtual void vp1dc();
    virtual void vp1e0();
    virtual void vp1e4();
    virtual void vp1e8();
    virtual void vp1ec();
    virtual void vp1f0();
    virtual const NiPoint3E* GetPosition();
};

class CameraE
{
  public:
    const NiPoint3E* GetPosition();
};

class SpawnManagerE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ListNodeE m_kActive;
    int unk10;
    int unk14;
    SpawnCellE* m_pkCells;
    float m_fTimer;

    void FUN_0062ee60(float fTimeDelta);
};

class hkSimdRealW
{
  public:
    __m128 m_vValue;
};

class hkVector4W
{
  public:
    __m128 m_vComponents;
    hkVector4W();
    hkVector4W(const hkVector4W& v);
};

class hkBoolW
{
  public:
    hkBoolW();
    operator bool() const;
    char m_cBooleanValue;
};

class NiPoint3W
{
  public:
    NiPoint3W();
    float x, y, z;
};

class TESObjectREFRW
{
  public:
    const hkVector4W& GetHavokPosition() const;
};

class CharacterW
{
  public:
};

class HeightSourceW
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_fOriginZ;
};

class GameSettingW
{
  public:
};

class HeightGridW
{
  public:
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
    unsigned int m_uiCells;
    int m_iOriginX;
    int m_iOriginY;

    bool FUN_0062ff10(TESObjectREFRW* pkRef, const hkVector4W& kTarget, float fRadius, HeightSourceW* pkSource,
                      float* pfHeight);
};

// @fnv 0x0062ee60
void SpawnManagerE::FUN_0062ee60(float fTimeDelta)
{
    if (((bool)(reinterpret_cast<::FUN_0062f2f0_shell *>(this)->FUN_0062f2f0())))
    {
        m_fTimer -= fTimeDelta;
        float fRadius = ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingE *>(&::originalRuntimeFloatSetting976))));
        fRadius = fRadius * fRadius;
        fRadius = FUN_004a3e90(fRadius);
        float m_fGlyphExtent = FUN_004a3e90(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingE *>(&::originalRuntimeFloatSetting977)))));
        hkVector4E kPlayerPos;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kPlayerPos)), (*(const ::fnv_004a3e00::NiPoint3 *)((*reinterpret_cast<::PlayerE * *>(&::_g_thePlayer))->GetPosition())));
        hkVector4E kUnused;
        ListNodeE* pkNode = &m_kActive;
        float fFoundHeight = 0.0f;
        reinterpret_cast<::FUN_00438af0_Class *>(&((*reinterpret_cast<::LockE *>(&::g_011cc584))))->FUN_00438af0();
        while (!*(*reinterpret_cast<::FlagE *>(&::g_011cc5a8)).Get() && pkNode && !reinterpret_cast<::ObsList *>((pkNode))->FUN_004a4460())
        {
            RefE* pkRef = ((::RefPtrE *)((void *)(pkNode)))->operator->();
            RefE* pkRef2 = pkRef;
            BodyE* pkBody = ((::BodyE *)(reinterpret_cast<::FUN_00620b80_shell *>((pkRef2))->GetReferenceFlags()));
            int iResult = 0;
            if (reinterpret_cast<::HeightGridW *>(this)->FUN_0062ff10((::TESObjectREFRW *)(pkBody), (const ::hkVector4W &)(kPlayerPos), fRadius, (::HeightSourceW *)(::SpawnCellE *)(0), &fFoundHeight))
                iResult = reinterpret_cast<::PhysicsController *>(this)->FUN_00630170((::PhysicsReference *)(pkBody), fFoundHeight, fTimeDelta, 0);
            if (iResult)
            {
                ImpactObjE* pkObj = ((::ImpactObjE *)(::FUN_0062b4e0(reinterpret_cast<::FUN_0043b560_shell *>((pkRef))->GetSourceFilesFromObject())));
                if (pkObj)
                {
                    fFoundHeight = FUN_004587d0(fFoundHeight);
                    if (iResult == 1)
                    {
                        if (!reinterpret_cast<::B200Owner *>((pkObj))->FUN_0057b200())
                        {
                            if (FUN_008c7aa0() && ((::AudioE *)(::TaskQueueInterface::GetSingleton())))
                                reinterpret_cast<::FakeTaskQueue *>((((::AudioE *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b4a0(0, (int)(pkObj), fFoundHeight);
                            else
                                reinterpret_cast<::Target5c80 *>((((::AudioMgrE *)(::FUN_0070ec90((char *)((*reinterpret_cast<::InterfaceE * *>(&::g_TES))))))))->AddObjectToEntry((void *)(0), (::Object5c80 *)(pkObj), fFoundHeight);
                        }
                        reinterpret_cast<::Ref57b240 *>((pkObj))->FUN_0057b240(true);
                    }
                    else if (iResult == 2)
                    {
                        reinterpret_cast<::Ref57b240 *>((pkObj))->FUN_0057b240(false);
                        if (!reinterpret_cast<::B200Owner *>((pkObj))->FUN_0057b200())
                        {
                            if (FUN_008c7aa0() && ((::AudioE *)(::TaskQueueInterface::GetSingleton())))
                                reinterpret_cast<::Holder0087b4f0 *>((((::AudioE *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b4f0(0, (int)(pkObj), fFoundHeight);
                            else
                                reinterpret_cast<::WaterZoneManager *>((((::AudioMgrE *)(::FUN_0070ec90((char *)((*reinterpret_cast<::InterfaceE * *>(&::g_TES))))))))->UpdateWaterZone((::TESObjectREFR *)(0), (::TESObjectREFR *)(pkObj), fFoundHeight);
                        }
                    }
                }
            }
            pkNode = ((::ListNodeE *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        }

        SpawnCellE* pkCell = m_pkCells;
        while (pkCell)
        {
            SpawnListE* pkList = ((::SpawnListE *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pkCell))->FUN_00825c00()));
            while (pkList)
            {
                bool bSkip = false;
                for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkList->m_kForms))->GetName())); i++)
                {
                    void* pvForm = *((void **)(reinterpret_cast<::S3e60 *>(&(pkList->m_kForms))->FUN_006a7ad0(i)));
                    BodyE* pkBody = ((::BodyE *)(::FUN_004b59f0(pvForm)));
                    int iResult = 0;
                    if (!reinterpret_cast<::FUN_0057c850_cls *>(&((*reinterpret_cast<::LockE *>(&::g_011cc584))))->FUN_0057c850(pkBody, &bSkip) &&
                        reinterpret_cast<::HeightGridW *>(this)->FUN_0062ff10((::TESObjectREFRW *)(pkBody), (const ::hkVector4W &)(kPlayerPos), fRadius, (::HeightSourceW *)(pkCell), &fFoundHeight))
                        iResult = reinterpret_cast<::PhysicsController *>(this)->FUN_00630170((::PhysicsReference *)(pkBody), fFoundHeight, fTimeDelta, 1);
                    if (iResult == 1)
                    {
                        reinterpret_cast<::Ref57b240 *>((((::ImpactObjE *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkList))->FUN_0084e3a0()))))->FUN_0057b240(true);
                        reinterpret_cast<::FUN_0057b0d0_cls *>((((::ImpactObjE *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkList))->FUN_0084e3a0()))))->FUN_0057b0d0((int)(pkCell), true);
                    }
                }
                pkList = static_cast<SpawnListE*>(((::LinkE *)(reinterpret_cast<::Callees *>((pkList))->FUN_00726070())));
            }
            pkCell = static_cast<SpawnCellE*>(((::CellLinkE *)(reinterpret_cast<::Callees *>((pkCell))->FUN_00726070())));
        }
        reinterpret_cast<::fnv_00631370::WorkOwner *>(this)->FUN_00631370((::fnv_00631370::WorkActor *)(0), 1, 0);
    }
    if (((::CameraE *)(::FUN_00524c90())) && ((::ProcessE *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::PlayerE * *>(&::_g_thePlayer))))->GetTarget())))
    {
        if (((const ::NiPoint3E *)(::FUN_0045bb80((int)(((::CameraE *)(::FUN_00524c90()))))))->z < reinterpret_cast<::FUN_005471e0_shell *>((((::ProcessE *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::PlayerE * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_005471e0())
            ::FUN_0062f310((int)(((void *)(reinterpret_cast<::FUN_00547770_shell *>((((::ProcessE *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::PlayerE * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_00547770()))));
    }
}

// @fnv 0x0062ff10
bool HeightGridW::FUN_0062ff10(TESObjectREFRW* pkRef, const hkVector4W& kTarget, float fRadius, HeightSourceW* pkSource,
                               float* pfHeight)
{
    if (pkRef)
    {
        FUN_005631e0_shell* pkCharacter = (FUN_005631e0_shell*)FUN_004b5a80(pkRef);
        if (!pkCharacter)
            return false;

        hkVector4W kPos(pkRef->GetHavokPosition());
        hkVector4W kDiff;
        reinterpret_cast<::S00458a10_Vector *>(&(kDiff))->FUN_00458a10((const ::S00458a10_Vector *)&(kPos), (const ::S00458a10_Vector *)&(kTarget));
        ::hkSimdRealW kLength;
        if (reinterpret_cast<::S004586d0_Obj *>(reinterpret_cast<::FUN_00630100_shell *>(&kDiff)->FUN_00630100(&kLength))->FUN_004586d0() > fRadius)
        {
            if (pkCharacter->IsNonZero(0x88))
            {
                unsigned char bInactive;
                if (reinterpret_cast<::FUN_005609f0_shell *>(reinterpret_cast<::FUN_00c9bff0_Class *>(pkRef)->FUN_00c9bff0(&bInactive))->FUN_005609f0())
                    reinterpret_cast<::FUN_00c9c240_holder *>((((CharacterW*)pkCharacter)))->FUN_00c9d600();
            }
            return false;
        }

        if (pkSource)
        {
            *pfHeight = FUN_004a3e90(pkSource->m_fOriginZ);
        }
        else if (m_uiCells > 1)
        {
            NiPoint3W kPoint;
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&kPoint)), (*(const ::hkVector4 *)(&kPos)));
            int iX = FUN_00406d90(kPoint.x) >> 12;
            int iY = FUN_00406d90(kPoint.y) >> 12;
            iX -= m_iOriginX;
            iY -= m_iOriginY;
            *pfHeight = reinterpret_cast<::B630120Grid *>(this)->GetValue(iX, iY);
        }
        else
        {
            *pfHeight = reinterpret_cast<::B630120Grid *>(this)->GetValue(0, 0);
        }

        float fProjectionAlongAim = FUN_004a3e90(::FUN_00403e20((float *)&((*reinterpret_cast<::GameSettingW *>(&::originalRuntimeFloatSetting977)))));
        if (*pfHeight + fProjectionAlongAim < reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::hkSimdRealW &)((*(::hkSimdRealW *)(reinterpret_cast<::Holder *>((void *)&(kPos))->FUN_00458700((::Holder *)(2), {})))))->FUN_004586d0())
            return pkCharacter->IsNonZero(0x88);
        return true;
    }
    return false;
}

struct S00630ae0_Vector
{
    __m128 m_vComponents;
};

class S00630ae0_Source
{
  public:
};

struct S00630ae0_Result_o2_od_oy_noo2
{
    __m128 m_vComponents;
    void FUN_00630ae0(const S00630ae0_Source* a, const S00630ae0_Vector* b);
};

// @fnv 0x00630ae0
void S00630ae0_Result_o2_od_oy_noo2::FUN_00630ae0(const S00630ae0_Source* a, const S00630ae0_Vector* b)
{
    ::S00630ae0_Vector kA;
    reinterpret_cast<const ::S00561240_Vector *>(a)->FUN_00561240((::S00561240_Vector *)&kA);
    m_vComponents = _mm_mul_ps(kA.m_vComponents, b->m_vComponents);
}

class S00630b40_SimdReal
{
  public:
    S00630b40_SimdReal(const __m128& q);  // FUN_004a3c90
            // FUN_006815c0
    __m128 m_vValue;
};

class S00630b40_Vector
{
  public:
    S00630b40_SimdReal dot3(const S00630b40_Vector& v) const;  // FUN_0062b0a0
    S00630b40_SimdReal FUN_00630b40() const;                   // length3
    __m128 m_vComponents;
};

// @fnv 0x00630b40
S00630b40_SimdReal S00630b40_Vector::FUN_00630b40() const
{
    return S00630b40_SimdReal(_mm_sqrt_ss(dot3(*this).m_vValue));
}

class FUN_006815c0
{
  public:
    __m128 m_vComponents;

    FUN_006815c0();

    void FUN_00630d30(FUN_006815c0* pkA, FUN_006815c0* pkB);
};

struct Transform630
{
    FUN_006815c0 FUN_0062b0a0(void* pvParam);
};

struct Source630
{
};

struct FUN_00630bb0_shell_o2_od_oy_noo2
{
    void FUN_00458880(FUN_006815c0* pkA, FUN_006815c0* pkB);
    void FUN_00630bb0(Source630* pkSource, void* pvParam);
};

struct S00630ce0_Vector
{
    __m128 m_vComponents;
    void FUN_00630ce0(const S00630ce0_Vector* a, const S00630ce0_Vector* b);
};

// @fnv 0x00630ce0
void S00630ce0_Vector::FUN_00630ce0(const S00630ce0_Vector* a, const S00630ce0_Vector* b)
{
    m_vComponents = _mm_mul_ps(a->m_vComponents, b->m_vComponents);
}

struct S00630d90_Vector
{
    __m128 m_vComponents;
    void FUN_00630d90(const S00630d90_Vector* a, const S00630d90_Vector* b, const S00630d90_Vector* c);  // setAddMul4
};

// @fnv 0x00630d90
void S00630d90_Vector::FUN_00630d90(const S00630d90_Vector* a, const S00630d90_Vector* b, const S00630d90_Vector* c)
{
    m_vComponents = _mm_add_ps(a->m_vComponents, _mm_mul_ps(b->m_vComponents, c->m_vComponents));
}

struct hkVector4
{
    __m128 m_vComponents;

    void FUN_00630df0(const hkVector4& a, const hkVector4& b);
};

// @fnv 0x00630df0
void hkVector4::FUN_00630df0(const hkVector4& a, const hkVector4& b)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                     _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                     _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

struct S00630ed0_Vector
{
    __m128 m_vComponents;
    void FUN_00630ed0(int i);  // broadcast(i)
};

// @fnv 0x00630ed0
void S00630ed0_Vector::FUN_00630ed0(int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
}

struct VectorStandIn
{
    __m128 m_vComponents;
    void FUN_00630fa0(const VectorStandIn& v, int i);
};

// @fnv 0x00630bb0
void FUN_00630bb0_shell_o2_od_oy_noo2::FUN_00630bb0(Source630* pkSource, void* pvParam)
{
    FUN_006815c0 kA;
    kA.m_vComponents = DAT_010c71e0;
    FUN_006815c0 kB;
    reinterpret_cast<::VectorStandIn *>(&(kB))->FUN_00630fa0((*(const ::VectorStandIn *)(pkSource)), 3);
    FUN_006815c0 kC;
    reinterpret_cast<::S00630d90_Vector *>(&(kC))->FUN_00630d90((const ::S00630d90_Vector *)(class ::FUN_006815c0 *)(&kA), (const ::S00630d90_Vector *)(class ::FUN_006815c0 *)(&kB), (const ::S00630d90_Vector *)(class ::FUN_006815c0 *)(&kB));
    FUN_006815c0 kD;
    reinterpret_cast<::S00630ce0_Vector *>(&(kD))->FUN_00630ce0((const ::S00630ce0_Vector *)(pvParam), (const ::S00630ce0_Vector *)(class ::FUN_006815c0 *)(&kC));
    FUN_006815c0 kE;
    kE.m_vComponents = ((::Transform630 *)pkSource)->FUN_0062b0a0(pvParam).m_vComponents;
    reinterpret_cast<::S00630ed0_Vector *>(&(kE))->FUN_00630ed0(0);
    kD.FUN_00630d30(&kE, (FUN_006815c0*)((::Transform630 *)pkSource));
    FUN_006815c0 kF;
    reinterpret_cast<::hkVector4 *>(&(kF))->FUN_00630df0((*(const ::hkVector4 *)((FUN_006815c0*)((::Transform630 *)pkSource))), (*(const ::hkVector4 *)(pvParam)));
    kD.FUN_00630d30(&kB, &kF);
    FUN_00458880(&kD, &kD);
}

// @fnv 0x00630fa0
void VectorStandIn::FUN_00630fa0(const VectorStandIn& v, int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}

#include "generated/data/fallout_shared/havok/teswaterlistener.inc"
#include "generated/data/fallout_shared/havok/teswaterlistener_o2_variant_od_noo2_variant.inc"
