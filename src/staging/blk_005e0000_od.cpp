#include "AutoMemContext.h"

// src/staging/blk_005e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <windows.h>
#include <new>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSGameSound.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ChallengeManager.h"
#include "fnv/decl/FUN_0045c650_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046e8c0_class.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_00481790_t.h"
#include "fnv/decl/FUN_0048cea0_shell.h"
#include "fnv/decl/FUN_00495f30_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f8a60_class.h"
#include "fnv/decl/FUN_00507b20Class.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005a8ea0_shell.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005ac340_t.h"
#include "fnv/decl/FUN_005e9590.h"
#include "fnv/decl/FUN_005f5820_shell.h"
#include "fnv/decl/FUN_00600b90_Cls.h"
#include "fnv/decl/FUN_006928a0_class.h"
#include "fnv/decl/FUN_0069ccf0_class.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00884730_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008bffa0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00ad8570_S.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/IdleCleanup.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/S005e0460.h"
#include "fnv/decl/ScriptRunner.h"
#include "fnv/decl/SomeClass.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESClass.h"
#include "fnv/decl/TESCreature.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TESIdleForm.h"
#include "fnv/decl/TESObjectARMOFoley.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/ThisCls_cls.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00522c00__FUN_00522c00_shell.h"
#include "fnv/decl/fnv_005e0590__GlobalObject_00869f00.h"
#include "fnv/decl/fnv_005eee10__FUN_005eee10_shell.h"
#include "fnv/decl/fnv_005ef010__FUN_005ef010_Arr.h"
#include "fnv/decl/fnv_005ef1f0__FUN_005ef1f0_Arr.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/s891b90__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00471000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_005a6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_005e2000.h"
#include "fnv/symbols_005e3000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_0083a000.h"
#include "fnv/symbols_008d1000.h"
#include "fnv/symbols_00af7000.h"
#include "fnv/symbols_00afe000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0103d000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "../../include/layout_support.h"
#include <string.h>
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/Flt.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/SoundPlaybackManager.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/TESAnimGroup.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_005f6000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_011f4000.h"

namespace {
// Room for the 0x24-byte Big record that Holder::CopyBig (0x004e75d0) writes through its result pointer;
// the temporary lives until the end of the full expression.
struct BigResult
{
    int v[9];
};
template <class T> T& BigSlot(BigResult&& r) { return *reinterpret_cast<T*>(&r); }
}  // namespace

class TESObjectREFR;
// The shared fnv/decl/DialogueItem.h declares SelectDefaultResponseList twice (0x005e3fa0 and 0x0083c7b0, which differ
// only in the return type); this unit calls the 0x005e3fa0 one.
class DialogueItem {
public:
    ::TESObjectREFR *SelectDefaultResponseList();
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct FUN_00851d70_shell
{
    void SetFlagByte();
};
// If the global bool is set, calls SetFlagByte on the object at DAT_011de134, then returns true.
// @fnv 0x005e0160
bool FUN_005e0160()
{
    if (*::g_011de29c.Bool())
        reinterpret_cast<FUN_00851d70_shell*>((*reinterpret_cast<void * *>(&::DAT_011de134)))->SetFlagByte();
    return true;
}

extern int DAT_0103d3e8;

struct FUN_005e02e0
{
    void* m0;
    int m4;
    void Init();
};

// Stores the address of DAT_0103d3e8 into m0 and calls FUN_004b0220 with m4.
// @fnv 0x005e02e0
void FUN_005e02e0::Init()
{
    m0 = &DAT_0103d3e8;
    ::FUN_004b0220(m4);
}

extern "C" void* DAT_0103d3f0;
struct FUN_005e0310_class
{
    void* vtbl;
    FUN_005e0310_class* FUN_005e0310(void* a, void* b);
};

struct ActorCombatGroup;

struct NiTMallocInterface_
{
};

struct FUN_005e0340Class
{
    void* m_vtbl;
    ActorCombatGroup** m_ptr;
    void FUN_005e0340();
};

extern int DAT_0103d3f8;

// Sets the vtable pointer to DAT_0103d3f8 and deallocates m_ptr through NiTMallocInterface_::Deallocate.
// @fnv 0x005e0340
void FUN_005e0340Class::FUN_005e0340()
{
    m_vtbl = &DAT_0103d3f8;
    ::FUN_004ede70(m_ptr);
}

extern int DAT_0103d400;
struct FUN_005e0370_Class
{
    void* vtbl;
    void FUN_005e0950(int a, int b);
    void* FUN_005e0370(int a, int b);
};
struct NavMeshPtr
{
    void* FUN_00458b50();
    void* FUN_005e05b0(int index);
};

// @fnv 0x005e05b0
void* NavMeshPtr::FUN_005e05b0(int index)
{
    return (char*)FUN_00458b50() + (index << 9);
}

struct QuantityData
{
    void FUN_005e0b80(uintptr_t quantity);
};

// @fnv 0x005e0b80
void QuantityData::FUN_005e0b80(uintptr_t quantity)
{
    reinterpret_cast<::FUN_00537e90 *>(this)->SetQuantity(quantity);
}

struct FUN_005e1140_Class
{
    char pad[0x34];
    float unk34;
    void FUN_005e1140(float value);
};

// @fnv 0x005e1140
void FUN_005e1140_Class::FUN_005e1140(float value)
{
    unk34 += value;
}

struct FUN_005e2850_class
{
    char pad[0x14];
    int unk14;
    bool FUN_005e2850();
};

// @fnv 0x005e2850
bool FUN_005e2850_class::FUN_005e2850()
{
    return unk14 != 0;
}

struct Stub
{
    void FUN_005e9860();
};

// @fnv 0x005e9860
void Stub::FUN_005e9860()
{
    reinterpret_cast<::FUN_005e9590 *>(this)->FUN_005e9590::~FUN_005e9590();
}

struct TESFaction_RankDataView
{
    bool HasFlag20();
};

// @fnv 0x005ec6e0
bool TESFaction_RankDataView::HasFlag20()
{
    return (*reinterpret_cast<unsigned char*>(((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))) & 0x20) != 0;
}

struct FUN_005ec8f0_class
{
    bool FUN_005ec8f0(intptr_t a);
};

struct FUN_005ecd10_cls
{
    bool FUN_005ece20(intptr_t a);
};

struct FUN_005ed1b0_Class
{
    bool FUN_005ed1b0(intptr_t arg);
};

extern int DAT_010472e4;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void ResetToGlobal();
};

// @fnv 0x005eee60
void GlobalObject_00869f00::ResetToGlobal()
{
    p = &DAT_010472e4;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}


struct FUN_005ef910_class
{
    int FUN_005ef910(int, int);
};

struct FUN_005eefc0_class
{
    FUN_005eefc0_class* FUN_005eefc0();
};

namespace fnv_005eeff0 {

struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_005eeff0();
};

// @fnv 0x005eeff0
void GlobalObject_00869f00::FUN_005eeff0()
{
    *reinterpret_cast<int**>(this) = &::DAT_010472f8;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_005eeff0


struct FUN_005ef150_class
{
    void* FUN_005ef150(int a);
};

// Allocates a block of a * 0x38 bytes via operator new and returns the pointer.
// @fnv 0x005ef150
void* FUN_005ef150_class::FUN_005ef150(int a)
{
    void* p = ::FUN_00401000(a * 0x38);
    return p;
}


struct FUN_005ef180_Class
{
    void* FUN_005ef180(intptr_t n, int m);
};

// @fnv 0x005ef180
void* FUN_005ef180_Class::FUN_005ef180(intptr_t n, int iCount)
{
    return ::Reallocate((void*)n, iCount * 0x38);
}

void FUN_005efb30(int, int);

struct FUN_005ef1a0_Class
{
    void FUN_005efb30(int, int);
    FUN_005ef1a0_Class* FUN_005ef1a0();
};

namespace fnv_005ef1d0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_005ef1d0
{
    void Init();
};
// @fnv 0x005ef1d0
void FUN_005ef1d0::Init()
{
    *(void**)this = &::DAT_0104730c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_005ef1d0

struct FUN_005ef330_Class
{
    void* FUN_005ef330(int param_2);
};

// Allocates param_2 blocks of 0x28 bytes via operator new and returns the pointer.
// @fnv 0x005ef330
void* FUN_005ef330_Class::FUN_005ef330(int aiCount)
{
    void* result = ::FUN_00401000(aiCount * 0x28);
    return result;
}


struct FUN_005ef360_class
{
    void* FUN_005ef360(uintptr_t n, unsigned int m);
};

// @fnv 0x005ef360
void* FUN_005ef360_class::FUN_005ef360(uintptr_t n, unsigned int m)
{
    return Reallocate((void*)n, m * 0x28);
}

extern int DAT_01047320;

struct FUN_005efd40_class
{
    void* vtbl;
    FUN_005efd40_class* FUN_005ef380();
};

struct FUN_005ef510_Class
{
    void* AllocateSixTimesSize(int n);
};

// Allocates n * 6 bytes with operator new and returns the pointer.
// @fnv 0x005ef510
void* FUN_005ef510_Class::AllocateSixTimesSize(int n)
{
    void* p = ::FUN_00401000(n * 6);
    return p;
}


struct FUN_005ef540_class
{
    void* FUN_005ef540(int a, int b);
};

// @fnv 0x005ef540
void* FUN_005ef540_class::FUN_005ef540(int a, int b)
{
    return ::Reallocate(reinterpret_cast<void*>(a), b * 6);
}

struct TESAttributes
{
};

struct FUN_005f1210_shell : TESAttributes
{
    unsigned char FUN_005f1210();
};

// @fnv 0x005f1210
unsigned char FUN_005f1210_shell::FUN_005f1210()
{
    return reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(6);
}

namespace fnv_005f1250 {
struct TESAttributes
{
};

struct FUN_005f1250_shell : TESAttributes
{
    unsigned char FUN_005f1250();
};

// @fnv 0x005f1250
unsigned char FUN_005f1250_shell::FUN_005f1250()
{
    return reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(8);
}
}  // namespace fnv_005f1250

namespace fnv_005f1270 {
struct TESAttributes
{
    unsigned char FUN_005f1270();
};

// @fnv 0x005f1270
unsigned char TESAttributes::FUN_005f1270()
{
    return reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(9);
}
}  // namespace fnv_005f1270

namespace fnv_005f12b0 {
struct TESAttributes
{
};

struct FUN_005f12b0_shell : TESAttributes
{
    int FUN_005f12b0();
};

// @fnv 0x005f12b0
int FUN_005f12b0_shell::FUN_005f12b0()
{
    return ((int)(reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(0xb)));
}
}  // namespace fnv_005f12b0

namespace fnv_005f14b0 {
struct TESAttributes
{
    void SetAttributeValue(unsigned int index, unsigned char value, bool flag);
};

void TESAttributes::SetAttributeValue(unsigned int index, unsigned char value, bool flag)
{}

struct FUN_005f14b0_Class
{
    void SetAttribute5(unsigned char value);
};

// @fnv 0x005f14b0
void FUN_005f14b0_Class::SetAttribute5(unsigned char value)
{
    reinterpret_cast<::Thing *>((reinterpret_cast<TESAttributes*>(this)))->SetByte(5, value, true);
}
}  // namespace fnv_005f14b0

namespace fnv_005f14d0 {
struct TESAttributes
{
    void SetAttributeValue(unsigned char index, unsigned char value, bool force);
    void FUN_005f14d0(unsigned char index);
};

void TESAttributes::SetAttributeValue(unsigned char index, unsigned char value, bool force)
{}

// @fnv 0x005f14d0
void TESAttributes::FUN_005f14d0(unsigned char index)
{
    reinterpret_cast<::Thing *>(this)->SetByte(6, index, true);
}
}  // namespace fnv_005f14d0

namespace fnv_005f14f0 {
struct TESAttributes
{
    void FUN_005f14f0(bool argument0);
};
// @fnv 0x005f14f0
void TESAttributes::FUN_005f14f0(bool abValue)
{
    reinterpret_cast<::Thing *>(this)->SetByte((*(int *)&(const ::ActorValue::Index &)(static_cast<ActorValue::Index>(7))), static_cast<unsigned char>(abValue), true);
}
}  // namespace fnv_005f14f0

namespace fnv_005f1510 {
struct TESAttributes
{
};
struct FUN_005f1510
{
    void SetFlag(bool flag);
};
// @fnv 0x005f1510
void FUN_005f1510::SetFlag(bool flag)
{
    reinterpret_cast<::Thing *>((((TESAttributes*)this)))->SetByte(8, flag, true);
}
}  // namespace fnv_005f1510

namespace fnv_005f1530 {
struct TESAttributes
{
    void FUN_005f1530(unsigned char value);
};

// @fnv 0x005f1530
void TESAttributes::FUN_005f1530(unsigned char value)
{
    reinterpret_cast<::Thing *>(this)->SetByte(9, value, true);
}
}  // namespace fnv_005f1530

namespace fnv_005f1550 {
struct TESAttributes
{
    void SetAttributeValue(unsigned char index, unsigned char value, bool flag);
    void SetAttribute(unsigned char index);
};

void TESAttributes::SetAttributeValue(unsigned char index, unsigned char value, bool flag)
{}

// @fnv 0x005f1550
void TESAttributes::SetAttribute(unsigned char index)
{
    reinterpret_cast<::Thing *>(this)->SetByte(10, index, true);
}
}  // namespace fnv_005f1550

namespace fnv_005f1570 {
struct TESAttributes
{
    void FUN_005f1570(unsigned char index);
};

// @fnv 0x005f1570
void TESAttributes::FUN_005f1570(unsigned char index)
{
    reinterpret_cast<::Thing *>(this)->SetByte(0xb, index, true);
}
}  // namespace fnv_005f1570

struct FUN_005f3710_Class
{
    char pad[0x34];
    unsigned int unk34;
    intptr_t unk38;
    intptr_t GetEntryAt(int index);
};

// @fnv 0x005f3710
intptr_t FUN_005f3710_Class::GetEntryAt(int index)
{
    if ((unsigned int)index < unk34)
    {
        return index * 16 + unk38;
    }
    return 0;
}

struct FUN_005f4b70_Class
{
    char pad[0x29];
    unsigned char unk29;
    void FUN_005f4b70(unsigned char aucLevel);
};

// @fnv 0x005f4b70
void FUN_005f4b70_Class::FUN_005f4b70(unsigned char aucLevel)
{
    unk29 = aucLevel;
}

struct FUN_005f4b90_Class
{
    char pad[0x2b];
    unsigned char unk2b;
    void SetByteAtOffset2B(unsigned char v);
};
// @fnv 0x005f4b90
void FUN_005f4b90_Class::SetByteAtOffset2B(unsigned char aucValue)
{
    unk2b = aucValue;
}

struct FUN_005f5f60_class
{
    char pad[0x5c];
    unsigned short unk5c;
    int FUN_005f5f60();
};

// @fnv 0x005f5f60
int FUN_005f5f60_class::FUN_005f5f60()
{
    return unk5c & 2;
}

struct FUN_005f5fa0_cls
{
    char pad[0x64];
    unsigned short unk64;
    unsigned int GetShortAtOffset64();
};

// @fnv 0x005f5fa0
unsigned int FUN_005f5fa0_cls::GetShortAtOffset64()
{
    return unk64;
}

struct FUN_005f5fc0_class
{
    char pad[0x66];
    unsigned short unk66;
    unsigned int GetShortAtOffset66();
};

// @fnv 0x005f5fc0
unsigned int FUN_005f5fc0_class::GetShortAtOffset66()
{
    return unk66;
}

struct FUN_005f5fe0_class
{
    char pad[0x68];
    unsigned short unk68;
    unsigned int GetShortAtOffset68();
};

// @fnv 0x005f5fe0
unsigned int FUN_005f5fe0_class::GetShortAtOffset68()
{
    return unk68;
}

struct FUN_005f60c0_Class
{
    char pad[0x70];
    int unk70;
    int HasFlag8();
};

// @fnv 0x005f60c0
int FUN_005f60c0_Class::HasFlag8()
{
    return unk70 & 8;
}

struct TESChallenge
{
    char pad[0x6c];
    int unk6c;
    int unk70;
    void MarkForSave();
    void FUN_005f60e0(int amount);
public:
    int GetStartsLocked();
};

// Adds amount to the int at offset 0x6c of this object and calls MarkForSave.
// @fnv 0x005f60e0
void TESChallenge::FUN_005f60e0(int amount)
{
    unk6c += amount;
    MarkForSave();
}

struct TESActorBaseData
{
    void FUN_005f9010(bool set);
};

// @fnv 0x005f9010
void TESActorBaseData::FUN_005f9010(bool set)
{
    reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(0x800, set, true);
}

void __cdecl FUN_00600b90();

struct FUN_005ffbd0_cls
{
    void FUN_005ffbd0();
    void FUN_00600b90();
};

// @fnv 0x005ffbd0
void FUN_005ffbd0_cls::FUN_005ffbd0()
{
    reinterpret_cast<::FUN_00600b90_Cls *>((this))->FUN_00600b90();
}

struct FUN_005e0830
{
    void Open(const char* apFileName, bool abWrite);
};
// Calls FUN_004f8ac0 with apFileName, then invokes the object's vtable slot 6 with abWrite.
// @fnv 0x005e0830
void FUN_005e0830::Open(const char* apFileName, bool abWrite)
{
    reinterpret_cast<::FUN_004f8a60_class *>(this)->FUN_004f8ac0((intptr_t)(apFileName));
    ((void(*)(void*, bool))(*reinterpret_cast<void***>(this))[6])(this, abWrite);
}

struct FUN_005efc60_class
{
    void* InitToMinusOne();
};

// Sets the three shorts at offsets 0, 2 and 4 of this object to -1 and returns this.
// @fnv 0x005efc60
void* FUN_005efc60_class::InitToMinusOne()
{
    *(short*)this = -1;
    *(short*)(this + 2) = -1;
    *(short*)(this + 4) = -1;
    return this;
}

struct FUN_005f4bd0_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    char* m14;
    void SetEntryByte(unsigned int index, unsigned char value);
};
// If index is below the count in mc, writes value to byte 13 of the 16-byte entry at m14 + index*16.
// @fnv 0x005f4bd0
void FUN_005f4bd0_class::SetEntryByte(unsigned int index, unsigned char value)
{
    if (index < (unsigned int)mc)
        *(unsigned char*)((char*)m14 + index * 16 + 13) = value;
}

extern int DAT_0103d408;
struct Standin005e03a0
{
    void* vtbl;
    void* m4;
    void FUN_005e03a0();
};
// Sets the object's vtbl to DAT_0103d408 and passes m4 to FUN_004ede70.
// @fnv 0x005e03a0
void Standin005e03a0::FUN_005e03a0()
{
    vtbl = (void*)&DAT_0103d408;
    FUN_004ede70(m4);
}

struct NiBound
{
    NiBound();
};
int __cdecl FUN_005e0aa0(void* a, int b);
struct FUN_005e05d0 : NiBound
{
    FUN_005e05d0(void* a, int b);
};
// Constructs the object by calling FUN_005e0aa0 with a and 0, then passing the result to SetQuantity.
// @fnv 0x005e05d0
FUN_005e05d0::FUN_005e05d0(void* a, int b)
{
    reinterpret_cast<::FUN_00537e90 *>((((QuantityData*)this)))->SetQuantity((unsigned int)FUN_005e0aa0(a, 0));
}

struct Holder005e0620
{
    void* InitAndMaybeFree(unsigned int);
};
// Calls Init on this, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x005e0620
void* Holder005e0620::InitAndMaybeFree(unsigned int flags)
{
    ((FUN_005e02e0*)this)->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005dd810_Class
{
    void FUN_005dd810();
    void* FUN_005e0650(unsigned int flags);
};
// @fnv 0x005e0650
void* FUN_005dd810_Class::FUN_005e0650(unsigned int flags)
{
    FUN_005dd810();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005e0680_Class : FUN_005e0340Class
{
    void* FUN_005e0680(unsigned int flags);
};
// Calls the base destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005e0680
void* FUN_005e0680_Class::FUN_005e0680(unsigned int flags)
{
    FUN_005e0340();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005dd7b0_class
{
    void FUN_005dd7b0();
    void* FUN_005e06b0(unsigned int flags);
};
// @fnv 0x005e06b0
void* FUN_005dd7b0_class::FUN_005e06b0(unsigned int flags)
{
    FUN_005dd7b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005e03a0_Class
{
};
struct FUN_005e06e0_Class
{
    void* FUN_005e06e0(unsigned int flags);
};
// Calls FUN_005e03a0 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x005e06e0
void* FUN_005e06e0_Class::FUN_005e06e0(unsigned int flags)
{
    reinterpret_cast<::Standin005e03a0 *>((((FUN_005e03a0_Class*)this)))->FUN_005e03a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005dd7d0_Class
{
    void FUN_005dd7d0();
};
struct FUN_005e0710_Class
{
    void* FUN_005e0710(unsigned int flags);
};
// @fnv 0x005e0710
void* FUN_005e0710_Class::FUN_005e0710(unsigned int flags)
{
    ((FUN_005dd7d0_Class*)this)->FUN_005dd7d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005e0460_class
{
};
struct FUN_005e0740_class : FUN_005e0460_class
{
    void* FUN_005e0740(unsigned int flags);
};
// @fnv 0x005e0740
void* FUN_005e0740_class::FUN_005e0740(unsigned int flags)
{
    reinterpret_cast<::S005e0460 *>(this)->FUN_005e0460();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005dd7f0_class
{
    void FUN_005dd7f0();
};
struct FUN_005e0770_class
{
    FUN_005e0770_class* FUN_005e0770(unsigned int flags);
};
// @fnv 0x005e0770
FUN_005e0770_class* FUN_005e0770_class::FUN_005e0770(unsigned int flags)
{
    ((FUN_005dd7f0_class*)this)->FUN_005dd7f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct _Mem_20a4
{
    ~_Mem_20a4();
    _Mem_20a4* FUN_005e07a0(unsigned int flags);
};

// Destructs the object and, when bit 0 of flags is set, frees its memory, then returns the pointer.
// @fnv 0x005e07a0
_Mem_20a4* _Mem_20a4::FUN_005e07a0(unsigned int flags)
{
    this->_Mem_20a4::~_Mem_20a4();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_005e0590_shell
{
};

struct FUN_005e0800_class
{
    void* FUN_005e0800(unsigned int flags);
};

// Calls FUN_005e0590 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005e0800
void* FUN_005e0800_class::FUN_005e0800(unsigned int flags)
{
    reinterpret_cast<::fnv_005e0590::GlobalObject_00869f00 *>((((FUN_005e0590_shell*)this)))->FUN_005e0590();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void* __cdecl FUN_00c85750();
struct ref_006815c0_class
{
    void FUN_005e0ad0();
};
// @fnv 0x005e0aa0
void FUN_005e0aa0(int a, int b)
{
    ref_006815c0_class* obj = reinterpret_cast<ref_006815c0_class*>(FUN_00c85750());
    reinterpret_cast<ref_006815c0_class*>(
        ((::ref_006815c0_class *)(new ((void *)(obj)) ::Vec3())))
        ->FUN_005e0ad0();
}

struct FUN_005e0b10_holder
{
};
uintptr_t __cdecl FUN_005e0b50(void*, int);
struct S_005e0ad0
{
    void* FUN_005e0ad0(int a, int b);
};
void __cdecl FUN_005e0b40(void*, void*);
struct FUN_005e0b10_Cls
{
    NavMeshPtr m0;
    char _pad[7];
    NavMeshPtr m8;
    void FUN_005e0b10();
};
// @fnv 0x005e0ad0
void* S_005e0ad0::FUN_005e0ad0(int aiValue, int aiUnused)
{
    void* p;
    reinterpret_cast<::FUN_005e0b10_Cls *>((((FUN_005e0b10_holder*)this)))->FUN_005e0b10();
    p = ((NavMeshPtr*)this)->FUN_00458b50();
    reinterpret_cast<::FUN_00537e90 *>((((QuantityData*)this)))->SetQuantity(FUN_005e0b50(p, aiValue));
    return p;
}
// Calls FUN_005e0b40 with the results of FUN_00458b50 on m0 and m8.
// @fnv 0x005e0b10
void FUN_005e0b10_Cls::FUN_005e0b10()
{
    FUN_005e0b40(m0.FUN_00458b50(), m8.FUN_00458b50());
}

template <int N> struct EndianSizeTag
{
    unsigned char v;
};
struct T2870
{
    int unk00;
    char pad04[0x4];
    long long unk08;
    void FUN_005e2870();
};
// @fnv 0x005e2870
void T2870::FUN_005e2870()
{
    ::FUN_00401080(&unk00);
    ::FUN_004717f0(&unk08);
}

struct FUN_005ec700_shell : TESFaction_RankDataView
{
    void SetFlag20(bool b);
};

// @fnv 0x005ec700
void FUN_005ec700_shell::SetFlag20(bool abSet)
{
    abSet ? *((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField())) |= 0x20 : *((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField())) &= ~0x20;
}

struct FUN_005ed160_Class
{
    bool Equals(intptr_t arg);
};
// Returns the logical negation of Equals(arg).
// @fnv 0x005ed1b0
bool FUN_005ed1b0_Class::FUN_005ed1b0(intptr_t arg)
{
    return !reinterpret_cast<::FUN_005ed160_Class *>(this)->Equals(arg);
}

// Compares three consecutive 16-bit values at this and arg, returning true only if all three pairs match.
// @fnv 0x005ed160
bool FUN_005ed160_Class::Equals(intptr_t arg)
{
    bool equal = false;
    if (*(short*)this == *(short*)arg && *(short*)(this + 2) == *(short*)(arg + 2) &&
        *(short*)(this + 4) == *(short*)(arg + 4))
        equal = true;
    return equal;
}

struct FUN_00692290_class
{
    void FUN_00692290(unsigned int, unsigned int);
};
struct FUN_005eee30_class
{
    void* vtbl;
    FUN_005eee30_class* FUN_005eee30();
};
// Sets the vtable pointer and calls FUN_00692290 with 0, 0, then returns this.
// @fnv 0x005eee30
FUN_005eee30_class* FUN_005eee30_class::FUN_005eee30()
{
    vtbl = (void*)&DAT_010472e4;
    ((FUN_00692290_class*)this)->FUN_00692290(0, 0);
    return this;
}

struct GlobalObject_00869f00_Deleting : GlobalObject_00869f00
{
    GlobalObject_00869f00* FUN_005ef590(unsigned int flags);
};

// Calls ResetToGlobal, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x005ef590
GlobalObject_00869f00* GlobalObject_00869f00_Deleting::FUN_005ef590(unsigned int flags)
{
    ResetToGlobal();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005eeff0_shell
{
};
struct FUN_005ef5c0_class
{
    void* FUN_005ef5c0(unsigned int flags);
};
// Calls FUN_005eeff0 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x005ef5c0
void* FUN_005ef5c0_class::FUN_005ef5c0(unsigned int flags)
{
    reinterpret_cast<::fnv_005eeff0::GlobalObject_00869f00 *>((((FUN_005eeff0_shell*)this)))->FUN_005eeff0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005ef1d0_class
{
    void FUN_005ef1d0();
};

struct FUN_005ef5f0_class
{
    void* FUN_005ef5f0(unsigned int flags);
};

// @fnv 0x005ef5f0
void* FUN_005ef5f0_class::FUN_005ef5f0(unsigned int flags)
{
    reinterpret_cast<::fnv_005ef1d0::FUN_005ef1d0 *>((reinterpret_cast<FUN_005ef1d0_class*>(this)))->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_005ef3b0
{
    FUN_005ef3b0* FUN_005ef620(unsigned int flags);
};

struct NavMeshSearchLOSArray
{
};
struct FUN_005ef860_class
{
    virtual void v0();
    virtual void* v4(int a);
    virtual void v8();
    virtual void* vC(void* a, int b);
    void* m4;
    int m8;
    int mC;
    void FUN_005ef860(int a, int b);
};
struct FUN_005efa40_class
{
    short m0;
    short m2;
    char pad4[24];
    float m1C;
    float m20;
    float m24;
    FUN_005efa40_class* FUN_005efa40();
};
// Initializes the object: sets m0 and m2 to -1, zeroes m1C, m20 and m24, and returns this.
// @fnv 0x005efa40
FUN_005efa40_class* FUN_005efa40_class::FUN_005efa40()
{
    m0 = -1;
    m2 = -1;
    m1C = 0.0f;
    m20 = 0.0f;
    m24 = 0.0f;
    return this;
}

struct FUN_005f29f0_Entry
{
    float value;
    char pad04[0xc];
};
struct FUN_005f29f0_Class
{
    char pad[0x34];
    unsigned int unk34;
    void* unk38;
    void SetValueAtIndex(unsigned int index, float value);
};
// If index is below the count at offset 0x34 and the pointer at 0x38 is non-null, writes value into the float slot at index*16 of that array.
// @fnv 0x005f29f0
void FUN_005f29f0_Class::SetValueAtIndex(unsigned int index, float value)
{
    if (index >= unk34)
        return;
    if (!unk38)
        return;
    static_cast<FUN_005f29f0_Entry*>(unk38)[index].value = value;
}

struct FUN_005f2a30_Class
{
    char _pad0[0x34];
    unsigned int m34;
    void* m38;
    void SetEntryValue(unsigned int index, unsigned int value);
};
// If index is below m34 and m38 is non-null, writes value into the 16-byte entry at m38 + index*16, offset 12.
// @fnv 0x005f2a30
void FUN_005f2a30_Class::SetEntryValue(unsigned int index, unsigned int value)
{
    if (index >= m34)
        return;
    if (m38 == 0)
        return;
    *(unsigned int*)((char*)m38 + index * 16 + 12) = value;
}

struct FUN_005f2b20_Class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    unsigned int m34;
    char* m38;
    void SetEntryFloat(unsigned int a, float b);
};
// If index a is below m34 and m38 is set, writes float b at offset 8 of the 16-byte entry at m38 + a*16.
// @fnv 0x005f2b20
void FUN_005f2b20_Class::SetEntryFloat(unsigned int uiIndex, float fValue)
{
    if (uiIndex >= m34)
        return;
    if (!m38)
        return;
    *(float*)(m38 + uiIndex * 16 + 8) = fValue;
}

struct FUN_005f6000_Class : TESChallenge
{
    void SetFlagAndMarkForSave(bool bFlag);
};

// @fnv 0x005f6000
void FUN_005f6000_Class::SetFlagAndMarkForSave(bool abSet)
{
    !abSet ? unk70 &= ~2 : unk70 |= 2;
    MarkForSave();
}

struct FUN_005f6060_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    void FUN_005f6060(bool show);
};
// @fnv 0x005f6060
void FUN_005f6060_class::FUN_005f6060(bool show)
{
    !show ? m70 &= ~4 : m70 |= 4;
    reinterpret_cast<::TESChallenge *>(this)->MarkForSave();
}

struct FUN_005f6570 : public TESChallenge
{
    void SetFlag(bool set);
};
// Sets or clears bit 0 of the flags at offset 0x70 based on set, then calls MarkForSave.
// @fnv 0x005f6570
void FUN_005f6570::SetFlag(bool set)
{
    !set ? unk70 &= ~1 : unk70 |= 1;
    MarkForSave();
}

struct FUN_005f74b0_cls
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
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
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void Target(int, int);
    void TargetWithFloatArg(int a, float b);
};
// Calls the virtual Target method, converting the float argument to int.
// @fnv 0x005f74b0
void FUN_005f74b0_cls::TargetWithFloatArg(int aiValue, float afValue)
{
    Target(aiValue, (int)afValue);
}

struct Inner74e0
{
    virtual void i0();
    virtual void i1();
    virtual int i2(int);
};
struct Outer74e0
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void u53();
    virtual void u54();
    virtual void u55();
    virtual void u56();
    virtual void u57();
    virtual void u58();
    virtual void u59();
    virtual void u60();
    virtual void u61();
    virtual void u62();
    virtual void u63();
    virtual void u64();
    virtual void u65();
    virtual void u66();
    virtual void u67();
    virtual void u68();
    virtual void u69();
    virtual void u70();
    virtual void u71();
    virtual void u72();
    virtual void u73();
    virtual void u74();
    virtual void u75();
    virtual void u76();
    virtual void u77();
    virtual void u78();
    virtual void u79();
    virtual void u80();
    virtual void u81();
    virtual void u82();
    virtual void u83();
    virtual void u84();
    virtual void u85();
    virtual void u86();
    virtual void u87();
    virtual void u88();
    virtual void u89();
    virtual void u90();
    virtual void u91();
    virtual void u92();
    virtual void u93();
    virtual void u94();
    virtual void u95();
    virtual void u96();
    virtual void u97();
    virtual void u98();
    virtual void u99();
    virtual void u100();
    virtual void targ(int, int);
    char _pad[252];
    Inner74e0 fld100;
    void ForwardToTarget(int, int);
};
// Calls targ with a and the sum of fld100.i2(a) and b.
// @fnv 0x005f74e0
void Outer74e0::ForwardToTarget(int aiValue, int b)
{
    targ(aiValue, fld100.i2(aiValue) + b);
}

struct GlobalObject_0045cfe0
{
};
struct FUN_005fbeb0_shell
{
    char pad[0x154];
    int unk154;
    int* FUN_005fbeb0();
};
// Returns the int pointed to by one of three global objects, chosen by the value at this+0x154 (2, 1 or 0); otherwise returns null.
// @fnv 0x005fbeb0
int* FUN_005fbeb0_shell::FUN_005fbeb0()
{
    int* result = 0;
    switch (unk154)
    {
    case 2:
        result = *((int **)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cd3b4))))));
        break;
    case 1:
        result = *((int **)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cd538))))));
        break;
    case 0:
        result = *((int **)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cdde0))))));
        break;
    }
    return result;
}

struct FUN_005ff520_shell
{
    unsigned int FUN_005ff520(unsigned int);
};
struct FUN_005ff560_shell
{
    void RemoveChildAndRelinkNeighbors(unsigned int);
};
struct FUN_005ff5d0_class
{
    char pad[0x40];
    unsigned int unk40;
    void FUN_005ff5d0(unsigned int a);
};
// If a is nonzero and the object's field at offset 0x40 is set, calls FUN_005ff520(a) and passes its result to RemoveChildAndRelinkNeighbors.
// @fnv 0x005ff5d0
void FUN_005ff5d0_class::FUN_005ff5d0(unsigned int uiValue)
{
    if (uiValue && unk40)
    {
        unsigned int r = ((FUN_005ff520_shell*)this)->FUN_005ff520(uiValue);
        ((FUN_005ff560_shell*)this)->RemoveChildAndRelinkNeighbors(r);
    }
}

char** __cdecl FUN_005e0ba0(unsigned int);

struct FUN_005e08e0_class
{
    int* vtbl;
    char** data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    FUN_005e08e0_class* FUN_005e08e0(unsigned short x, unsigned short y);
};
// Calls FUN_005e08e0 with the two arguments, sets vtbl to DAT_0103d3f0, and returns this.
// @fnv 0x005e0310
FUN_005e0310_class* FUN_005e0310_class::FUN_005e0310(void* apArg, void* apArg2)
{
    reinterpret_cast<::FUN_005e08e0_class *>(this)->FUN_005e08e0((unsigned short)(uintptr_t)(apArg), (unsigned short)(uintptr_t)(apArg2));
    vtbl = &DAT_0103d3f0;
    return this;
}

// @fnv 0x005e08e0
FUN_005e08e0_class* FUN_005e08e0_class::FUN_005e08e0(unsigned short x, unsigned short y)
{
    vtbl = &DAT_0103d3e8;
    a = x;
    d = y;
    b = 0;
    c = 0;
    if (a > 0)
        data = FUN_005e0ba0(a);
    else
        data = 0;
    return this;
}

struct FUN_005ef9a0_shell
{
    virtual void v0();
    virtual void* v1(unsigned int);
};
struct FUN_005efb30_class
{
    void* vtbl;
    void* m4;
    unsigned int m8;
    unsigned int mc;
    void FUN_005efb30(unsigned int requested, unsigned int savedSize);
};
struct FUN_005efdd0_class
{
    void FUN_005efdd0(char* a, char* b, unsigned int count);
};
// Copies count 2-byte elements from b to a, iterating forward when a < b and backward when a > b to handle overlap.
// @fnv 0x005efdd0
void FUN_005efdd0_class::FUN_005efdd0(char* pDest, char* pSrc, unsigned int count)
{
    if (count <= 0)
        return;
    if (pDest < pSrc)
    {
        for (unsigned int i = 0; i < count; ++i)
            std::memmove(pDest + i * 2, pSrc + i * 2, 2);
    }
    else if (pDest > pSrc)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            std::memmove(pDest + i * 2, pSrc + i * 2, 2);
    }
}


struct FUN_005efe70_shell
{
    void FUN_005efe70(char* a, char* b, unsigned int c);
};
// @fnv 0x005ef860
void FUN_005ef860_class::FUN_005ef860(int a, int b)
{
    if (m4)
    {
        if (b == mC)
        {
            m4 = vC(m4, a);
        }
        else
        {
            void* r = v4(a);
            reinterpret_cast<::FUN_005efe70_shell *>((((NavMeshSearchLOSArray*)this)))->FUN_005efe70((char *)(r), (char *)(m4), b);
            ::FUN_006a8500((::DummyClass_006a8500 *)(((NavMeshSearchLOSArray*)this)));
            m4 = r;
        }
    }
    else
    {
        m4 = v4(a);
        mC = a;
    }
}

// @fnv 0x005efe70
void FUN_005efe70_shell::FUN_005efe70(char* pDest, char* pSrc, unsigned int c)
{
    if (c <= 0)
        return;
    if (pDest < pSrc)
    {
        for (unsigned int i = 0; i < c; ++i)
            std::memmove(pDest + i * 0x38, pSrc + i * 0x38, 0x38);
    }
    else if (pDest > pSrc)
    {
        for (int i = c - 1; i >= 0; --i)
            std::memmove(pDest + i * 0x38, pSrc + i * 0x38, 0x38);
    }
}

struct FUN_005eff10_class
{
    void FUN_005eff10(char* dst, const char* src, uintptr_t count);
};
// Copies count 6-byte elements from src to dst, iterating forward when dst<src and backward when dst>src to handle overlap.
// @fnv 0x005eff10
void FUN_005eff10_class::FUN_005eff10(char* dst, const char* src, uintptr_t count)
{
    if (count <= 0)
        return;
    if (dst < src)
    {
        for (unsigned int i = 0; i < count; i++)
            std::memmove(dst + i * 6, src + i * 6, 6);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; i--)
            std::memmove(dst + i * 6, src + i * 6, 6);
    }
}

struct FNStub
{
};
struct TESSaveLoadGame
{
};

struct FUN_005f6f70_Class
{
    char pad[0x18];
    FNStub unk18;
    char pad19[0x13];
    FNStub unk2c;
    char pad2d[0x17];
    char unk44[0x1c];
    void FUN_005f6f70();
};

struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_005e0950
{
    void* m0;
    void* m4;
    unsigned short m8;
    unsigned short ma;
    unsigned short mc;
    unsigned short me;
    FUN_005e0950(unsigned short, unsigned short);
};
// Calls FUN_005e0950 with the two arguments, sets vtbl to &DAT_0103d400, and returns this.
// @fnv 0x005e0370
void* FUN_005e0370_Class::FUN_005e0370(int aiArg1, int aiArg2)
{
    new ((void *)this) ::FUN_005e0950(aiArg1, aiArg2);
    vtbl = &DAT_0103d400;
    return this;
}
// @fnv 0x005e0950
FUN_005e0950::FUN_005e0950(unsigned short ausSize, unsigned short b)
{
    m0 = &DAT_0103d3f8;
    m8 = ausSize;
    me = b;
    ma = 0;
    mc = 0;
    if (m8 > 0)
        m4 = NiTMallocInterface_0096afc0::Allocate(m8);
    else
        m4 = 0;
}

namespace fnv_005e09c0 {
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short size);
};
struct FUN_005e09c0
{
    int* vtbl;
    ActorCombatGroup** data;
    unsigned short count;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short capacity;
    FUN_005e09c0(unsigned short a, unsigned short b);
};
// @fnv 0x005e09c0
FUN_005e09c0::FUN_005e09c0(unsigned short ausCount, unsigned short ausCapacity)
{
    vtbl = (int*)&DAT_0103d408;
    count = ausCount;
    capacity = ausCapacity;
    m0a = 0;
    m0c = 0;
    if (count > 0)
        data = NiTMallocInterface_0096afc0::Allocate(count);
    else
        data = 0;
}
}  // namespace fnv_005e09c0

namespace fnv_005e0a30 {
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_005e0a30_t
{
    void* vtbl;
    void* unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
    void* FUN_005e0a30(unsigned short a, unsigned short b);
};
// @fnv 0x005e0a30
void* FUN_005e0a30_t::FUN_005e0a30(unsigned short ausCapacity, unsigned short b)
{
    vtbl = &::DAT_0103d418;
    unk08 = ausCapacity;
    unk0e = b;
    unk0a = 0;
    unk0c = 0;
    if (unk08 > 0)
        unk04 = (void*)NiTMallocInterface_0096afc0::Allocate(unk08);
    else
        unk04 = 0;
    return this;
}
}  // namespace fnv_005e0a30

struct FUN_006c8a30_Class
{
};

struct FUN_005ef6a0Class
{
    virtual void v0();
    virtual void* v4(int);
    virtual void v8();
    virtual void* v12(void*, int);
    void* p;
    int pad;
    int idx;
    void SetOrReplace(int a, int b);
};
// @fnv 0x005ef6a0
void FUN_005ef6a0Class::SetOrReplace(int a, int b)
{
    if (p)
    {
        if (b == idx)
        {
            p = v12(p, a);
        }
        else
        {
            void* pNew = v4(a);
            ((FUN_005efdd0_class*)this)->FUN_005efdd0((char*)pNew, (char*)p, (unsigned int)b);
            ::FUN_006a8500((::DummyClass_006a8500 *)(((FUN_006c8a30_Class*)this)));
            p = pNew;
        }
    }
    else
    {
        p = v4(a);
        idx = a;
    }
}

struct FUN_005ef7f0_Data
{
    short x0;
    short x2;
    short x4;
    char x6;
    float x8;
    float xc;
    float x10;
    float x14;
    float x18;
    float x1c;
    void* FUN_005ef7f0();
};

// Initialises all fields of the object: shorts to -1, byte to 0, floats to 0.0, and returns this.
// @fnv 0x005ef7f0
void* FUN_005ef7f0_Data::FUN_005ef7f0()
{
    x0 = -1;
    x2 = -1;
    x4 = -1;
    x6 = 0;
    x8 = 0.0f;
    xc = 0.0f;
    x10 = 0.0f;
    x14 = 0.0f;
    x18 = 0.0f;
    x1c = 0.0f;
    return this;
}

struct FUN_005ef910_vt
{
    virtual void v0();
    virtual int Write(int);
};

struct FUN_005ef910 : FUN_005ef910_vt
{
    int iSize;
    int iPosition;
    int iDataLength;
    void ConstructSpawnItems(intptr_t, int);
    void RecordRequestedSize(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x005eefc0
FUN_005eefc0_class* FUN_005eefc0_class::FUN_005eefc0()
{
    *reinterpret_cast<int**>(this) = &DAT_010472f8;
    reinterpret_cast<::FUN_005ef910 *>((reinterpret_cast<FUN_005ef910_class*>(this)))->RecordRequestedSize(0, 0);
    return this;
}

// @fnv 0x005ef910
void FUN_005ef910::RecordRequestedSize(unsigned int requested, unsigned int savedSize)
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
        ConstructSpawnItems(iSize, savedSize);
        iPosition = savedSize;
    }
}

namespace fnv_005efc90 {
struct FUN_006c8a30_Class
{
};
struct FUN_005efc90_class
{
    virtual void v0();
    virtual void* v1(void*);
    virtual void* v2(void*, void*);
    virtual void* v3(void*, void*);
    void* m4;
    void* m8;
    void* mc;
    void FUN_005efc90(void* a, void* b);
};
// @fnv 0x005efc90
void FUN_005efc90_class::FUN_005efc90(void* a, void* b)
{
    if (m4)
    {
        if (b == mc)
        {
            m4 = v3(m4, a);
        }
        else
        {
            void* t = v1(a);
            ((FUN_005eff10_class*)this)->FUN_005eff10((char*)t, (char const*)m4, (uintptr_t)b);
            ::FUN_006a8500((::DummyClass_006a8500 *)(((FUN_006c8a30_Class*)this)));
            m4 = t;
        }
    }
    else
    {
        m4 = v1(a);
        mc = a;
    }
}
}  // namespace fnv_005efc90

void __cdecl FUN_005e0b60(void*);
struct GO
{
    operator unsigned int();
};
struct FUN_005e0600_Class
{
    void FUN_005e0600();
};
// @fnv 0x005e0600
void FUN_005e0600_Class::FUN_005e0600()
{
    FUN_005e0b60((void*)(uintptr_t)(unsigned int)*(GO*)this);
}

void* __cdecl FUN_00885750();
struct BSSimpleList_005e0b60
{
};
// @fnv 0x005e0b60
void FUN_005e0b60(void* p)
{
    reinterpret_cast<QuantityData*>(((::BSSimpleList_005e0b60 *)(new ((void *)(reinterpret_cast<BSSimpleList_005e0b60*>(FUN_00885750()))) ::Vec3())))
        ->FUN_005e0b80((uintptr_t)p);
}

struct FUN_005e3fe0_class
{
    int unk00;
    char pad04[0x10];
    int unk14;
    int unk18;
    char pad1c[0xc];
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    char pad44[0xc];
    int unk50;
    void SwapEndianFields();
};

// Byte-swaps the fields at offsets 0x0, 0x14, 0x18, 0x28 through 0x40 and 0x50 of this object via BSEndian.
// @fnv 0x005e3fe0
void FUN_005e3fe0_class::SwapEndianFields()
{
    ::FUN_00401080(&unk00);
    ::FUN_00401080(&unk14);
    ::FUN_00401080(&unk18);
    ::FUN_00401080(&unk28);
    ::FUN_00401080(&unk2c);
    ::FUN_00401080(&unk30);
    ::FUN_00401080(&unk34);
    ::FUN_00401080(&unk38);
    ::FUN_00401080(&unk3c);
    ::FUN_00401080(&unk40);
    ::FUN_00401080(&unk50);
}

struct FUN_005eee10
{
    ~FUN_005eee10();
};

struct FUN_005ef560_Class : public FUN_005eee10
{
    void* FUN_005ef560(unsigned int flags);
};

FUN_005eee10::~FUN_005eee10()
{}

// Runs the base destructor, then frees this with _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x005ef560
void* FUN_005ef560_Class::FUN_005ef560(unsigned int flags)
{
    reinterpret_cast<::fnv_005eee10::FUN_005eee10_shell *>(this)->FUN_005eee10();
    if (flags & 1U)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005f11f0_shell : TESAttributes
{
    unsigned char GetAttributeValue5();
};
// @fnv 0x005f11f0
unsigned char FUN_005f11f0_shell::GetAttributeValue5()
{
    return reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(5);
}

struct FUN_005f1290_shell : TESAttributes
{
    unsigned char GetAttributeValue10();
};
// @fnv 0x005f1290
unsigned char FUN_005f1290_shell::GetAttributeValue10()
{
    return reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(10);
}

// FindByKey: list search over a cursor list at this+0x10c.
class FNVCursor
{
  public:
    bool IsEnd();
};
class FNVObject
{
  public:
};

class FUN_005e0860_cls
{
  public:
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
    FNVCursor m_kNode;
    bool FindByKey(void* a1, FNVObject** a2);
};

// Searches the cursor list for an object whose key matches a1, stores it in a2 and returns true, otherwise returns false.
// @fnv 0x005e0860
bool FUN_005e0860_cls::FindByKey(void* pKey, FNVObject** ppFound)
{
    if (pKey == 0)
    {
        return false;
    }
    FNVCursor* cur = &m_kNode;
    while (cur != 0 && !cur->IsEnd())
    {
        FNVObject* v = (FNVObject*)*((void **)(new ((void *)(cur)) ::Vec3()));
        if (::FUN_00404dc0((const char *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((v))->GetName()))), (const char *)(pKey)) == 0)
        {
            *ppFound = v;
            return true;
        }
        cur = ((::FNVCursor *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
    return false;
}

// @fnv 0x005e0b40
int __cdecl FUN_005e0b40(unsigned int arg0, unsigned int arg1)
{
    return (int)(arg1 - arg0);
}

// @fnv 0x005e0b50
uintptr_t __cdecl FUN_005e0b50(void* base, int offset)
{
    return (uintptr_t)base + offset;
}

struct ObjectHeader
{
    unsigned int flags;
};
struct Component
{
    unsigned int state;
};
struct CompleteObject : ObjectHeader, Component
{
};
struct VirtualReader
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual Component* readEntry(bool* success);
    CompleteObject* ReadCompleteObject();
};
// Reads an entry via readEntry and returns it cast to CompleteObject, ignoring the success flag.
// @fnv 0x005e4ab0
CompleteObject* VirtualReader::ReadCompleteObject()
{
    bool success;
    return static_cast<CompleteObject*>(readEntry(&success));
}

struct LightingDataCmp
{
    short s00;
    short s02;
    short s04;
    unsigned char b06;
    unsigned char unk07;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    bool FUN_005ec760(const LightingDataCmp* other);
};
// Returns the logical negation of FUN_005ec760(a).
// @fnv 0x005ec8f0
bool FUN_005ec8f0_class::FUN_005ec8f0(intptr_t a)
{
    return !reinterpret_cast<::LightingDataCmp *>(this)->FUN_005ec760((const ::LightingDataCmp *)(a));
}

// @fnv 0x005ec760
bool LightingDataCmp::FUN_005ec760(const LightingDataCmp* other)
{
    bool result = false;
    if (s00 == other->s00 && s02 == other->s02 && s04 == other->s04 && b06 == other->b06 && f08 == other->f08 &&
        f0C == other->f0C && f10 == other->f10 && f14 == other->f14 && f18 == other->f18 && f1C == other->f1C &&
        f20 == other->f20 && f24 == other->f24 && f28 == other->f28 && f2C == other->f2C && f30 == other->f30 &&
        f34 == other->f34)
    {
        result = true;
    }
    return result;
}

struct Entry38
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
};

struct StrArray
{
    void* vtbl;
    char** data;
    int unk08;
    int unk0C;
    char*& GetAt(unsigned int index);
    void Clear(bool);
    unsigned int GetSize();
};

struct EntryArray
{
    void* vtbl;
    Entry38* data;
    int unk08;
    int unk0C;
    void Clear(bool);
    unsigned int GetSize();
};


struct Data005ecb30
{
    unsigned char flag;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    StrArray strings;
    EntryArray entries;
    void FUN_005ecb30(Data005ecb30* other);
};

namespace fnv_005ecfd0 {

struct Entry28
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

struct StringArray
{
    void* m_ppVirtualMethodTable;
    char** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    char*& GetAt(unsigned int index);
    void Clear(bool freeMemory);
};

struct EntryArray
{
    void* m_ppVirtualMethodTable;
    Entry28* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    Entry28& GetAt(unsigned int index);
    void Clear(bool freeMemory);
};

struct StringEntryData
{
    unsigned char flag;
    StringArray strings;
    EntryArray entries;
    void FUN_005ecfd0(StringEntryData* other);
};

// Clears entries and strings, then deep-copies the other object's entries, duplicated strings and flag into this object.
// @fnv 0x005ecfd0
void StringEntryData::FUN_005ecfd0(StringEntryData* other)
{
    unsigned int i;
    unsigned int j3;
    unsigned int k;
    unsigned int len3;
    char* str;

    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(entries))->Clear(true);
    for (i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(strings))->GetName())); i++)
    {
        delete strings.GetAt(i);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(strings))->Clear(true);
    reinterpret_cast<::fnv_005ef1f0::FUN_005ef1f0_Arr *>(&(entries))->FUN_005ef1f0(((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->entries))->GetName())), true);
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(strings))->FUN_006f2290(((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->strings))->GetName())), true);
    for (j3 = 0; j3 < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->entries))->GetName())); j3++)
    {
        entries.GetAt(j3) = other->entries.GetAt(j3);
    }
    for (k = 0; k < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->strings))->GetName())); k++)
    {
        len3 = ((int)(::FUN_0044a670(other->strings.GetAt(k)))) + 1;
        str = new char[len3];
        ::TaskQueueInterface::CopyStringToBuffer(str, len3, other->strings.GetAt(k));
        strings.GetAt(k) = str;
    }
    flag = other->flag;
}
}  // namespace fnv_005ecfd0

// FUN_005eedc0 : returns &m_pEntries[index] (element size 0x38)
struct FUN_005eedc0_item
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
};

struct FUN_005eedc0_cls
{
    int m_unk00;
    FUN_005eedc0_item* m_pEntries;
    FUN_005eedc0_item* FUN_005eedc0(int index);
};
// Clears entries and strings, copies the other object's entry array and deep-copies its strings, then copies the float fields and flag.
// @fnv 0x005ecb30
void Data005ecb30::FUN_005ecb30(Data005ecb30* other)
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(entries))->Clear(true);
    for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(strings))->GetName())); i++)
    {
        delete strings.GetAt(i);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(strings))->Clear(true);
    reinterpret_cast<::fnv_005ef010::FUN_005ef010_Arr *>(&(entries))->FUN_005ef010(((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->entries))->GetName())), true);
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(strings))->FUN_006f2290(((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->strings))->GetName())), true);
    for (unsigned int j = 0; j < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->entries))->GetName())); j++)
    {
        *((::Entry38 *)(reinterpret_cast<::FUN_005eedc0_cls *>(&(entries))->FUN_005eedc0(j))) = *((::Entry38 *)(reinterpret_cast<::FUN_005eedc0_cls *>(&(other->entries))->FUN_005eedc0(j)));
    }
    for (unsigned int k = 0; k < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->strings))->GetName())); k++)
    {
        unsigned int len = ((int)(::FUN_0044a670(other->strings.GetAt(k)))) + 1;
        char* str = new char[len];
        ::TaskQueueInterface::CopyStringToBuffer(str, len, other->strings.GetAt(k));
        strings.GetAt(k) = str;
    }
    f04 = other->f04;
    f08 = other->f08;
    f0C = other->f0C;
    f10 = other->f10;
    f14 = other->f14;
    f18 = other->f18;
    f1C = other->f1C;
    flag = other->flag;
}

// @fnv 0x005eedc0
FUN_005eedc0_item* FUN_005eedc0_cls::FUN_005eedc0(int index)
{
    return &m_pEntries[index];
}

struct FUN_005efa80_cls
{
    virtual void v0();
    virtual void* v4(void* a);
    virtual void v8();
    virtual void* vC(void* a, void* b);
    void* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void FUN_005efa80(void* a1, unsigned int a2);
};

// @fnv 0x005efa80
void FUN_005efa80_cls::FUN_005efa80(void* a1, unsigned int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = vC(m_04, a1);
        }
        else
        {
            void* tmp = v4(a1);
            reinterpret_cast<::FUN_006928a0_class *>(this)->FUN_006928a0((char *)(tmp), (char *)(m_04), a2);
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            m_04 = tmp;
        }
    }
    else
    {
        m_04 = v4(a1);
        m_0c = (unsigned int)(uintptr_t)a1;
    }
}


struct EFBC0Item
{
    EFBC0Item();

    short m_sValue0;
    short m_sValue1;
    short m_sValue2;
};

class EFBC0Array
{
  public:
    void ConstructItems(EFBC0Item* pkItems, unsigned int ItemUpdateArray);
};

// Default-constructs each of the given number of EFBC0Item elements in place.
// @fnv 0x005efbc0
void EFBC0Array::ConstructItems(EFBC0Item* pkItems, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkItems[i]) EFBC0Item;
}

struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};


struct RootCls_b9637
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RootCls_b9637();
    ~RootCls_b9637();
};

class FUN_005f21c0_cls : public RootCls_b9637
{
  public:
    virtual void unk00();
    int unk18;
    Vec3Sub m_1c;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    int unk30;
    int unk34;
    int unk38;
    FUN_005f21c0_cls(unsigned short a);
    void SetAnimGroupType(unsigned short a);
};

// @fnv 0x005f21c0
FUN_005f21c0_cls::FUN_005f21c0_cls(unsigned short a) : RootCls_b9637(), m_1c()
{
    unk18 = 0;
    unk28 = 0;
    unk29 = 0;
    unk2a = 0;
    unk2b = 0;
    unk2c = 0;
    m_1c = (*reinterpret_cast<::Vec3Sub *>((void *)&::NiPoint3::ZERO));
    unk30 = 0;
    SetAnimGroupType(a);
    unk38 = 0;
    unk34 = 0;
}

struct PairRecord16
{
    unsigned int unk00;
    unsigned char m_flag;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int m_uiFilterValue;
    unsigned int unk0C;
};

class FUN_005f2a70_cls
{
  public:
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
    unsigned int m_uiItemCount;
    PairRecord16* m_pRecords;
    void SetRecordFlagAndValue(unsigned int index, unsigned char flag, unsigned int value);
};

// @fnv 0x005f2a70
void FUN_005f2a70_cls::SetRecordFlagAndValue(unsigned int index, unsigned char flag, unsigned int value)
{
    if (index > m_uiItemCount)
    {
    }
    else
    {
        if (m_pRecords == 0)
        {
        }
        else
        {
            m_pRecords[index].m_flag = flag;
            m_pRecords[index].m_uiFilterValue = value;
        }
    }
}

extern double DAT_010484f0;

struct FUN_005f2ac0_rec
{
    unsigned char m_00[4];
    unsigned char m_04;
    unsigned char m_05[11];
};

struct FUN_005f2ac0_cls
{
    char m_000[0x34];
    unsigned int m_34;
    FUN_005f2ac0_rec* m_38;
    void SetRecordValue(unsigned int idx, float f);
};

// If idx is within m_34 and m_38 is set, stores f scaled by DAT_010484f0 as a byte into m_38[idx].m_04.
// @fnv 0x005f2ac0
void FUN_005f2ac0_cls::SetRecordValue(unsigned int uiIndex, float afValue)
{
    if (!(uiIndex < m_34))
    {
        return;
    }
    if (!m_38)
    {
        return;
    }
    m_38[uiIndex].m_04 = (unsigned char)(afValue * DAT_010484f0);
}

struct Pt3
{
    float x;
    float y;
    float z;
};

struct Ext
{
};

struct Ref;

struct SndInfo
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
};

struct SndForm
{
};

struct AudioPlaybackHandle
{
    int m0;
    int m4;
    int m8;
    AudioPlaybackHandle();
    ~AudioPlaybackHandle();
    AudioPlaybackHandle& operator=(const AudioPlaybackHandle& o);
};

struct AudioMgr
{
    AudioPlaybackHandle Make(int id, SndForm* form);
    AudioPlaybackHandle Make2(int id);
};

struct SndList
{
};

struct SndTable
{
};

struct Big;
struct Holder
{
    ~Holder();
public:
    void FUN_00485680();
public:
    ::Big *CopyBig(::Big *);
};

struct StrHolder
{
    char* GetStr();
};

struct StrElem
{
    int m0;
    int m4;
};

struct ArrHolder
{
};

class Script
{
  public:
    ArrHolder* GetData(int* found);
};

struct Proc
{
};

struct Ref
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
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
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
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
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void* GetNode();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual Ext* GetExt();
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual Pt3* GetPos();
    virtual void v7E();
    virtual void v7F();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual bool IsAlive();
};

union EntryData
{
    float f;
    unsigned int u;
};

struct Entry
{
    float fTime_2;
    unsigned char ucType;
    EntryData data;
    SndForm* pForm;
};


bool __cdecl CheckDist(SndForm* form, Pt3 pos3, float f);

struct FUN_005f2b60_cls
{
    Entry* GetAt(unsigned int i);
    int GetKind();
    void ProcessSoundEntries(Ref* ref, float fFrom, float fTo, Script* script);
};

// Iterates the entry list, firing entries whose time falls in the range and dispatching sound, effect, shake and ref handling by entry type.
// @fnv 0x005f2b60
void FUN_005f2b60_cls::ProcessSoundEntries(Ref* ref, float fFrom, float fTo, Script* script)
{
    bool bWrap5 = false;
    float fMultVal = 1.0f;
    Ext* pExt6 = ref->GetExt();
    if (fTo < fFrom)
        bWrap5 = true;
    for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())); i++)
    {
        Entry* pEntry7 = ((::Entry *)(reinterpret_cast<::FUN_005f3710_Class *>(this)->GetEntryAt(i)));
        float fTime_2 = pEntry7->fTime_2;
        bool bFire = false;
        if (bWrap5 && (fTime_2 > fFrom || fTime_2 <= fTo))
            bFire = true;
        else if (fTime_2 > fFrom && fTime_2 <= fTo)
            bFire = true;
        if (bFire)
        {
            if (pEntry7->pForm != 0)
            {
                bool bLoopTmp = ((*(::SndInfo *)(reinterpret_cast<::Holder *>((pEntry7->pForm))->CopyBig(&BigSlot<::Big>(BigResult{})))).m04 & 0x40) ? true : false;
                int iBits7 = ::GetFlagMask((*(::SndInfo *)(reinterpret_cast<::Holder *>((pEntry7->pForm))->CopyBig(&BigSlot<::Big>(BigResult{})))).m04);
                Pt3 pos3 = *ref->GetPos();
                if (iBits7 != 0 || CheckDist(pEntry7->pForm, pos3, 1.0f))
                {
                    if (pExt6 != 0 && GetKind() >= 0xb1 && GetKind() <= 0xc7)
                        fMultVal *= reinterpret_cast<::FUN_00507b20Class *>((ref->GetExt()))->FUN_00507b20();
                    AudioPlaybackHandle snd = ((::AudioMgr *)(::FUN_00453a70()))->Make(
                        ((int)(intptr_t)(::FUN_00511840((char *)(pEntry7->pForm)))),
                        pEntry7->pForm);
                    reinterpret_cast<::FUN_00ad8b60_h *>(&(snd))->FUN_00ad8b60(pos3.x, pos3.y, pos3.z);
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(snd))->FUN_00ad89e0((float)(pEntry7->ucType / ::DAT_0101e568));
                    reinterpret_cast<::FUN_00ad8f20_shell *>(&(snd))->FUN_00ad8f20((::NiAVObject *)(void *)(ref->GetNode()));
                    reinterpret_cast<::SoundPlaybackHandle *>(&(snd))->SetPlaybackFrequency(pEntry7->data.f * fMultVal);
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(snd))->FUN_00ad8830(::GetFlagMask((*(::SndInfo *)(reinterpret_cast<::Holder *>((pEntry7->pForm))->CopyBig(&BigSlot<::Big>(BigResult{})))).m04) != 0);
                }
            }
            else
            {
                switch (pEntry7->ucType)
                {
                case 0xd:
                    reinterpret_cast<::ThisCls_cls *>(((*reinterpret_cast<::Ref * *>(&::_g_thePlayer))))->FUN_00962290((::ArgCls_cls *)(ref));
                    break;
                case 0xc: {
                    int iFoundB;
                    StrElem* pArrVal = ((::StrElem *)(uintptr_t)(reinterpret_cast<::FUN_00495f30_shell *>((script->GetData(&iFoundB)))->FUN_00495f30({})));
                    float fVal8 = 1.0f;
                    if (iFoundB != 0)
                    {
                        char* pStr7 = ((::StrHolder *)(reinterpret_cast<::BaseProcess *>(&(pArrVal[pEntry7->data.u & 0xff]))->GetCurrentProcessData()))->GetStr();
                        unsigned int uOff_2 = (pEntry7->data.u & 0xffffff00) >> 8;
                        fVal8 = (float)std::atof(pStr7 + uOff_2 + 0x11);
                    }
                    reinterpret_cast<::FUN_00ad8570_S *>((((::AudioMgr *)(::FUN_00453a70()))))->FUN_00ad8570((intptr_t)(ref->GetNode()), fVal8, 0x40000000);
                    break;
                }
                case 0:
                case 1:
                case 2:
                case 3:
                    ::PlayFootstepSound((::FootstepActor *)(ref), pEntry7->ucType);
                    break;
                case 4:
                case 5:
                case 6:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                    if (ref->IsActor())
                    {
                        Ref* pActorA = ref;
                        if (pActorA != 0 && pActorA->IsAlive())
                        {
                            SndList* pList5 = ((::SndList *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
                            SndForm* pSnd2 =
                                ((::SndForm *)(reinterpret_cast<::TESCreature *>((pList5))->FUN_005f92d0(pEntry7->ucType < 0x16 ? pEntry7->ucType : pEntry7->ucType - 0xb)));
                            Pt3 pos7 = *ref->GetPos();
                            if (pSnd2 != 0 && CheckDist(pSnd2, pos7, 1.0f))
                            {
                                AudioPlaybackHandle snd2 = ((::AudioMgr *)(::FUN_00453a70()))->Make2(
                                    reinterpret_cast<::FUN_0084e3a0_Class *>((pSnd2))->FUN_0084e3a0());
                                if (pExt6 != 0 && GetKind() >= 0xb1 && GetKind() <= 0xc7)
                                    fMultVal *= reinterpret_cast<::FUN_00507b20Class *>((ref->GetExt()))->FUN_00507b20();
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(snd2))->FUN_00ad8b60(pos7.x, pos7.y, pos7.z);
                                reinterpret_cast<::FUN_00ad8f20_shell *>(&(snd2))->FUN_00ad8f20((::NiAVObject *)(void *)(ref->GetNode()));
                                reinterpret_cast<::FUN_00ad89e0_shell *>(&(snd2))->FUN_00ad89e0(::g_011c629c_arg1);
                                reinterpret_cast<::SoundPlaybackHandle *>(&(snd2))->SetPlaybackFrequency(1.0f * fMultVal);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd2))->FUN_00ad8830(0);
                            }
                        }
                    }
                    break;
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x14:
                case 0x15:
                case 0x16:
                    if (ref->IsActor())
                    {
                        Ref* pActor = ref;
                        Holder* pHolder3 = ((::Holder *)(intptr_t)(reinterpret_cast<::s891b90::Owner *>((pActor))->FUN_00891b90(2)));
                        if (pHolder3 != 0)
                        {
                            SndTable* pSearchEntries = ((::SndTable *)(reinterpret_cast<::Twin_0044ddc0 *>((pHolder3))->GetName()));
                            SndForm* pSnd3 = ((::SndForm *)(reinterpret_cast<::TESObjectARMOFoley *>((pSearchEntries))->GetFoleySound(pEntry7->ucType)));
                            Pt3 pos = *ref->GetPos();
                            if (pSnd3 != 0 && CheckDist(pSnd3, pos, 1.0f))
                            {
                                AudioPlaybackHandle snd3;
                                if (ref == (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)))
                                {
                                    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::AudioPlaybackHandle &)(snd3))->operator=((const ::SoundPlaybackHandle &)((const ::AudioPlaybackHandle &)(((::AudioMgr *)(::FUN_00453a70()))->Make2(reinterpret_cast<::FUN_0084e3a0_Class *>((pSnd3))->FUN_0084e3a0()))));
                                }
                                else
                                {
                                    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::AudioPlaybackHandle &)(snd3))->operator=((const ::SoundPlaybackHandle &)((const ::AudioPlaybackHandle &)(((::AudioMgr *)(::FUN_00453a70()))->Make2(reinterpret_cast<::FUN_0084e3a0_Class *>((pSnd3))->FUN_0084e3a0()))));
                                    reinterpret_cast<::FUN_00ad8b60_h *>(&(snd3))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                                    reinterpret_cast<::FUN_00ad8f20_shell *>(&(snd3))->FUN_00ad8f20((::NiAVObject *)(void *)(ref->GetNode()));
                                }
                                reinterpret_cast<::FUN_00ad89e0_shell *>(&(snd3))->FUN_00ad89e0(::g_011c629c_arg1);
                                reinterpret_cast<::SoundPlaybackHandle *>(&(snd3))->SetPlaybackFrequency(1.0f * fMultVal);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd3))->FUN_00ad8830(0);
                            }
                            delete pHolder3;
                        }
                    }
                    break;
                case 9:
                    ::PlayWeaponImpactSound((::TESObjectREFR *)(ref), 9);
                    break;
                case 0xa:
                    ::PlayWeaponImpactSound((::TESObjectREFR *)(ref), 10);
                    break;
                case 0x10:
                    if (ref->IsActor())
                    {
                        Ref* pActor7 = ref;
                        Proc* pProc5 = ((::Proc *)(reinterpret_cast<::FUN_008a1710_shell *>((pActor7))->FUN_008a1710()));
                        if (pProc5 != 0)
                        {
                            SndForm* pSnd4 = ((::SndForm *)(uintptr_t)(reinterpret_cast<::FUN_008bffa0_shell *>((pProc5))->GetField228()));
                            if (pSnd4 != 0)
                            {
                                AudioPlaybackHandle snd5 = ((::AudioMgr *)(::FUN_00453a70()))->Make2(
                                    reinterpret_cast<::FUN_0084e3a0_Class *>((pSnd4))->FUN_0084e3a0());
                                Pt3 pos_ = *ref->GetPos();
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(snd5))->FUN_00ad8b60(pos_.x, pos_.y, pos_.z);
                                reinterpret_cast<::FUN_00ad8f20_shell *>(&(snd5))->FUN_00ad8f20((::NiAVObject *)(void *)(ref->GetNode()));
                                reinterpret_cast<::FUN_00ad89e0_shell *>(&(snd5))->FUN_00ad89e0(::g_011c629c_arg1);
                                reinterpret_cast<::SoundPlaybackHandle *>(&(snd5))->SetPlaybackFrequency(1.0f * fMultVal);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd5))->FUN_00ad8830(0);
                            }
                        }
                    }
                    break;
                case 0xb:
                    if (script != 0)
                    {
                        int iFoundTmp;
                        StrElem* pArr2 = ((::StrElem *)(uintptr_t)(reinterpret_cast<::FUN_00495f30_shell *>((script->GetData(&iFoundTmp)))->FUN_00495f30({})));
                        if (iFoundTmp != 0)
                        {
                            char* pStr6 = ((::StrHolder *)(reinterpret_cast<::BaseProcess *>(&(pArr2[pEntry7->data.u & 0xff]))->GetCurrentProcessData()))->GetStr();
                            unsigned int uOff5 = (pEntry7->data.u & 0xffffff00) >> 8;
                            float fShake3 = (float)std::atof(pStr6 + uOff5 + 0x12);
                            if (fShake3 > ::_DAT_01012060)
                                ::UpdateDistanceFade(fShake3, (*(const ::NiPoint3 *)(ref->GetPos())));
                        }
                    }
                    break;
                }
            }
        }
    }
}

// GetEntryByte0d: lookup of a per-entry byte value by index.
// The class holds a count of entries at +0x0c and a pointer to a table of
// 16-byte entries at +0x14; the byte read from each entry sits at +0x0d.
struct F4c00Entry
{
    int m_i00;
    int m_i04;
    int m_i08;
    unsigned char m_uc0c;
    unsigned char m_uc0d;
    unsigned char m_uc0e;
    unsigned char m_uc0f;
};

struct FUN_005f4c00_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    unsigned int m_uCount;
    int m_i10;
    F4c00Entry* m_pEntries;
    unsigned char GetEntryByte0d(unsigned int index);
};

// Returns byte 0x0d of the entry at index if index is below m_uCount, otherwise 0xff.
// @fnv 0x005f4c00
unsigned char FUN_005f4c00_cls::GetEntryByte0d(unsigned int index)
{
    return index < m_uCount ? m_pEntries[index].m_uc0d : 0xff;
}

struct FUN_005f4db0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m10;
    bool FUN_005f4db0();
};

extern "C" int __cdecl FUN_005f2440(unsigned short value);

// Returns true if FUN_005f2440(m10) yields one of the codes 0xe5, 0xf1, 0xf2, 0xf3 or 0xf4, otherwise false.
// @fnv 0x005f4db0
bool FUN_005f4db0_cls::FUN_005f4db0()
{
    switch (FUN_005f2440(this->m10))
    {
    case 0xe5:
    case 0xf1:
    case 0xf2:
    case 0xf3:
    case 0xf4:
        return true;
    default:
        return false;
    }
}

class B5FA120Form
{
  public:
    int GetFormType();
};

class B5FA120Checker
{
  public:
    bool FUN_005fa120(B5FA120Form* pkForm);
};

// Returns true if the form's type is 0x1e, 0x28 or 0x29, or if it is type 0x28 and FUN_0046e8c0 succeeds; otherwise false.
// @fnv 0x005fa120
bool B5FA120Checker::FUN_005fa120(B5FA120Form* pkForm)
{
    switch (pkForm->GetFormType())
    {
    case 0x1e:
    case 0x28:
    case 0x29:
        return true;
    }
    if (pkForm->GetFormType() == 0x28 && reinterpret_cast<::FUN_0046e8c0_class *>((pkForm))->FUN_0046e8c0())
        return true;
    return false;
}

struct FUN_005fbdd0_Entry
{
    void* unk00;
    void* unk04;
};
struct FUN_005fbdd0_cls
{
    char pad[0x64];
    char unk64;
    char pad65[0x150 - 0x65];
    unsigned char unk150;
    void FUN_005fbdd0(::NiAVObject* apRoot);
    int FUN_00401170();
};

// @fnv 0x005fbdd0
void FUN_005fbdd0_cls::FUN_005fbdd0(::NiAVObject* apRoot)
{
    void* node2;
    void* ptr;
    void* tmp;
    unsigned char flag_;

    if (unk150 != 0 || apRoot == 0)
    {
        return;
    }
    node2 = ((void *)(reinterpret_cast<::BaseProcess *>((&unk64))->GetCurrentProcessData()));
    while (node2 != 0)
    {
        ptr = *(void**)((void *)(new ((void *)(((FUN_005fbdd0_cls*)node2))) ::Vec3()));
        flag_ = 0;
        if (ptr != 0 && ((FUN_005fbdd0_cls*)static_cast<FUN_005fbdd0_Entry*>(ptr)->unk04)->FUN_00401170() == 0x28)
        {
            tmp = static_cast<FUN_005fbdd0_Entry*>(ptr)->unk04;
            if (((unsigned char)(reinterpret_cast<::FUN_0046e8c0_class *>((((FUN_005fbdd0_cls*)tmp)))->FUN_0046e8c0())) &&
                ::FUN_004aae30(apRoot, (::NiFixedString *)(std::uintptr_t)(reinterpret_cast<::fnv_00522c00::FUN_00522c00_shell *>(tmp)->FUN_00522c00())) == 0)
            {
                reinterpret_cast<::FUN_00481790_t *>((&unk64))->FUN_00481790((::BGSPerkEntry *)(ptr));
                node2 = ((void *)(reinterpret_cast<::BaseProcess *>((&unk64))->GetCurrentProcessData()));
                flag_ = 1;
            }
        }
        if (!flag_)
        {
            node2 = reinterpret_cast<::Callees *>((((FUN_005fbdd0_cls*)node2)))->FUN_00726070();
        }
    }
    unk150 = 1;
}

class B5FC120Form
{
  public:
    virtual ~B5FC120Form();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B5FC120FullName
{
  public:
    virtual ~B5FC120FullName();
    int unk04;
    int unk08;
};

class B5FC120Texture
{
  public:
    virtual ~B5FC120Texture();
    int unk04;
    int unk08;
};

// TESEyes destructor
class FUN_005fc120 : public B5FC120Form, public B5FC120FullName, public B5FC120Texture
{
  public:
    virtual ~FUN_005fc120();
};

// Destructor for a class that inherits from B5FC120Form, B5FC120FullName and B5FC120Texture; it has an empty body.
// @fnv 0x005fc120
FUN_005fc120::~FUN_005fc120()
{}

class C5FDB90Form
{
  public:
    virtual ~C5FDB90Form();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C5FDB90FullName
{
  public:
    virtual ~C5FDB90FullName();
    int unk04;
    int unk08;
};

class C5FDB90Model
{
  public:
    virtual ~C5FDB90Model();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C5FDB90Texture
{
  public:
    virtual ~C5FDB90Texture();
    int unk04;
    int unk08;
};

// TESHair
class FUN_005fdb90 : public C5FDB90Form, public C5FDB90FullName, public C5FDB90Model, public C5FDB90Texture
{
  public:
    virtual ~FUN_005fdb90();
};

// @fnv 0x005fdb90
FUN_005fdb90::~FUN_005fdb90()
{}

class FUN_005fe040_baseA
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_005fe040_baseA();
    ~FUN_005fe040_baseA();
};

class FUN_005fe040_baseB
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_005fe040_baseB();
    ~FUN_005fe040_baseB();
};

class FUN_005fe040_memberC
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_005fe040_memberC();
    ~FUN_005fe040_memberC();
};

class FUN_005fe040_memberD
{
  public:
    unsigned int unk00;
    FUN_005fe040_memberD();
    ~FUN_005fe040_memberD();
};

class FUN_005fe040 : public FUN_005fe040_baseA, public FUN_005fe040_baseB
{
  public:
    FUN_005fe040_memberC m_30;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    FUN_005fe040_memberD m_4c;

    FUN_005fe040();
    virtual void unk_Vfn();
};

// Initializes the object by calling unk_Init with size 0x48, sets m_40 to 0, then calls unk_Finish.
// @fnv 0x005fe040
FUN_005fe040::FUN_005fe040()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x48);
    m_40 = 0;
    reinterpret_cast<::TESIdleForm *>(this)->ResetFormData();
}

class ThisBase_b3969
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    ThisBase_b3969(int aValue, bool aFlag);
    ~ThisBase_b3969();
};

class ThisMember_b3969
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b3969(unsigned int aValue, bool aFlag);
    ~ThisMember_b3969();
};

class FUN_005ffaf0 : public ThisBase_b3969
{
  public:
    unsigned char m_14;
    ThisMember_b3969 m_18;

    FUN_005ffaf0();
};

// Initialises the base with value 0x25 and flag true, constructs m_18 with 0 and true, and sets m_14 to 0.
// @fnv 0x005ffaf0
FUN_005ffaf0::FUN_005ffaf0() : ThisBase_b3969(0x25, true), m_18(0, true)
{
    m_14 = 0;
}

// Thiscall dtor, 98 bytes /MT /Od /GS /EHsc: body call on this (state 1),
// member sub-object at +0x18 released (state 0), then base sub-object dtor on this (state -1).
class FUN_005ffb60_base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~FUN_005ffb60_base();
};

class FUN_005ffb60_child
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    ~FUN_005ffb60_child();
};

class FUN_005ffb60_cls : public FUN_005ffb60_base
{
  public:
    FUN_005ffb60_child m_18;
    ~FUN_005ffb60_cls();
};

// @fnv 0x005ffb60
FUN_005ffb60_cls::~FUN_005ffb60_cls()
{
    reinterpret_cast<::IdleCleanup *>(this)->DeleteAllOwnedForms();
}

using C5E0200AutoMemHelper = ::AutoMemContext;


class C5E0200File
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void Process();
    virtual void VFunc20();
    virtual void Prepare();

    bool Open(const char* pcFileName, bool bWrite);
    bool FUN_005e0200(const char* pcFileName);
};

// Opens pcFileName for reading; if that succeeds, calls Prepare and Process and returns whether the open succeeded.
// @fnv 0x005e0200
bool C5E0200File::FUN_005e0200(const char* pcFileName)
{
    C5E0200AutoMemHelper kMemHelper(9, true, g_ac5E0200SourceFile, 0x19d);
    bool bResult = Open(pcFileName, false);
    if (bResult)
    {
        Prepare();
        Process();
    }
    return bResult;
}

struct NiRTTI_S;
struct SkinInst_S;
struct TriGeom_S;
struct Node_S;

struct AVObj_S
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node_S* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual TriGeom_S* IsTriBasedGeom();
};

struct Node_S : AVObj_S
{
    unsigned int GetChildCount();
    AVObj_S* GetAt(unsigned int);
};

struct TriGeom_S : AVObj_S
{
};

struct SkinPartObj_S
{
};

SkinPartObj_S* NiDynamicCast(const NiRTTI_S* rtti, SkinInst_S* obj);

// @fnv 0x005e4970
void SetPartitionVisibility(intptr_t partition, AVObj_S* root)
{
    Node_S* nodeB = root->IsSceneNode();
    unsigned int i = 0;
    while (nodeB && i < nodeB->GetChildCount())
    {
        TriGeom_S* geom8 = ((::AVObj_S *)(reinterpret_cast<::NiNode *>((nodeB))->GetAt(i))) ? ((::AVObj_S *)(reinterpret_cast<::NiNode *>((nodeB))->GetAt(i)))->IsTriBasedGeom() : root->IsTriBasedGeom();
        i++;
        SkinInst_S* aSkin = geom8 ? ((::SkinInst_S *)(::fnv_0043fad0::FUN_0043fad0((const char *)(geom8)))) : 0;
        SkinPartObj_S* part = NiDynamicCast(reinterpret_cast<const NiRTTI_S*>(&g_011f49d8), aSkin);
        if (part)
        {
            for (int j = 0; j < 15; j++)
            {
                if (j == partition)
                {
                    reinterpret_cast<::SomeClass *>((part))->SetEntryStateByKey(partition + 100, true);
                }
                else
                {
                    reinterpret_cast<::SomeClass *>((part))->SetEntryStateByKey((unsigned short)j, false);
                    reinterpret_cast<::SomeClass *>((part))->SetEntryStateByKey(j + 200, false);
                }
                reinterpret_cast<::SomeClass *>((part))->SetEntryStateByKey(j * 1000, false);
            }
        }
    }
}

struct CompareEntry
{
};
struct CompareArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct CompareStrings
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const char*& At(unsigned int);
};
struct CompareData
{
    unsigned char flag;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    CompareStrings strings;
    CompareArray entries;
    bool FUN_005ec920(CompareData* other);
};
// Compares entry and string arrays plus flag and float fields against another CompareData, returning whether any differ.
// @fnv 0x005ec920
bool CompareData::FUN_005ec920(CompareData* other)
{
    bool different = false;
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->entries))->GetName())))
        different = true;
    if (!different)
    {
        for (unsigned int index = 0; index < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries))->GetName())) && !different; ++index)
            different = different || reinterpret_cast<::FUN_005ec8f0_class *>((((::CompareEntry *)(reinterpret_cast<::FUN_005eedc0_cls *>(&(entries))->FUN_005eedc0(index)))))->FUN_005ec8f0((intptr_t)(((::CompareEntry *)(reinterpret_cast<::FUN_005eedc0_cls *>(&(other->entries))->FUN_005eedc0(index)))));
    }
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(strings))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->strings))->GetName())))
        different = true;
    if (!different)
    {
        for (unsigned int textIndex = 0; textIndex < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(strings))->GetName())) && !different; ++textIndex)
            different = different || ::FUN_00408b20(strings.At(textIndex), other->strings.At(textIndex)) != 0;
    }
    if (different || flag != other->flag || f04 != other->f04 || f08 != other->f08 || f0C != other->f0C ||
        f10 != other->f10 || f14 != other->f14 || f18 != other->f18 || f1C != other->f1C)
        different = true;
    return different;
}

struct Entry005ed1e0
{
};
struct Array005ed1e0
{
    void* unknown_00;
    void* unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
};
struct EntryArray005ed1e0 : Array005ed1e0
{
};
struct StringArray005ed1e0 : Array005ed1e0
{
    const char*& FUN_00877a30(unsigned int index);
};
struct Target005ed1e0
{
    unsigned char unknown_00;
    unsigned char unknown_01;
    unsigned short unknown_02;
    StringArray005ed1e0 strings_04;
    EntryArray005ed1e0 entries_14;
    bool FUN_005ed1e0(Target005ed1e0* other);
};
// Compares entry and string array counts and elements plus unknown_00 against another object, returning whether any differ.
// @fnv 0x005ed1e0
bool Target005ed1e0::FUN_005ed1e0(Target005ed1e0* other)
{
    bool different = false;
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries_14))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->entries_14))->GetName())))
        different = true;
    if (!different)
    {
        for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries_14))->GetName())) && !different; ++i)
            different = different || reinterpret_cast<::FUN_005ed1b0_Class *>((((::Entry005ed1e0 *)(reinterpret_cast<::FUN_0069ccf0_class *>(&(entries_14))->FUN_0069ccf0(i)))))->FUN_005ed1b0((intptr_t)(((::Entry005ed1e0 *)(reinterpret_cast<::FUN_0069ccf0_class *>(&(other->entries_14))->FUN_0069ccf0(i)))));
    }
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(strings_04))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->strings_04))->GetName())))
        different = true;
    if (!different)
    {
        for (unsigned int j = 0; j < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(strings_04))->GetName())) && !different; ++j)
            different = different || FUN_00408b20(strings_04.FUN_00877a30(j), other->strings_04.FUN_00877a30(j));
    }
    if (different || unknown_00 != other->unknown_00)
        different = true;
    return different;
}


struct SpawnItem : FUN_005ef7f0_Data
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    SpawnItem();
};

// Constructs count SpawnItem objects in place at base + i * 0x38 for each i from 0 to count-1.
// @fnv 0x005ef750
void FUN_005ef910::ConstructSpawnItems(intptr_t base, int count)
{
    unsigned int i;

    for (i = 0; i < count; ++i)
    {
        new ((void*)(base + i * 0x38)) SpawnItem;
    }
}


struct E5EF9A0Entry
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
    E5EF9A0Entry();
};

class E5EF9A0Allocator
{
  public:
    void ConstructEntries(E5EF9A0Entry* pkArray, unsigned int ItemUpdateArray);
};
// @fnv 0x005ef1a0
FUN_005ef1a0_Class* FUN_005ef1a0_Class::FUN_005ef1a0()
{
    *reinterpret_cast<void**>(this) = &DAT_0104730c;
    reinterpret_cast<::FUN_005efb30_class *>(this)->FUN_005efb30(0, 0);
    return this;
}
// @fnv 0x005efb30
void FUN_005efb30_class::FUN_005efb30(unsigned int requested, unsigned int savedSize)
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m4 = ((FUN_005ef9a0_shell*)this)->v1(requested);
        mc = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::E5EF9A0Allocator *>((((FUN_005ef9a0_shell*)this)))->ConstructEntries((::E5EF9A0Entry *)(m4), savedSize);
        m8 = savedSize;
    }
}

// Constructs each E5EF9A0Entry in the given array by placement new, for the given count.
// @fnv 0x005ef9a0
void E5EF9A0Allocator::ConstructEntries(E5EF9A0Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) E5EF9A0Entry;
}

struct ChallengeView;
struct ChallengeNode
{
};
struct ChallengeName
{
    const char* FUN_00408da0();
    int unk00;
    int unk04;
    int unk08;
};
struct ChallengeDescription
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual const char* GetText(int, unsigned int);
    int unk04;
};
struct ChallengeView : TESChallenge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ChallengeName name;
    ChallengeDescription description;
    ChallengeNode rewards;
};
struct ChallengeReward
{
};
extern ChallengeNode DAT_011cb448;

// @fnv 0x005f6110
bool __cdecl FUN_005f6110(ChallengeView* pSourceChallenge, int amount)
{
    ChallengeNode* pNode = &DAT_011cb448;
    bool result = false;
    ChallengeView* found = 0;
    while (pNode)
    {
        found = *((::ChallengeView **)(new ((void *)(pNode)) ::Vec3()));
        bool sameType = true;
        if (found)
        {
            if (((int)(::FUN_005a6150((const unsigned char *)(found)))) && !reinterpret_cast<::FUN_005f5f60_class *>((found))->FUN_005f5f60())
            {
                pNode = ((::ChallengeNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                continue;
            }
            if (reinterpret_cast<::TESChallenge *>((found))->GetStartsLocked() && !((int)(::FUN_005a60d0((const char *)(found)))))
            {
                pNode = ((::ChallengeNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                continue;
            }
            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSourceChallenge))->FUN_0084e3a0())) != ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((found))->FUN_0084e3a0())))
            {
                sameType = false;
                pNode = ((::ChallengeNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                continue;
            }
            found->FUN_005f60e0(amount);
            if (((int)(uintptr_t)(reinterpret_cast<::DialogueItem *>((found))->SelectDefaultResponseList())) >= reinterpret_cast<::LowProcess *>((found))->GetPackageObjectType())
            {
                if (((::ChallengeNode *)(reinterpret_cast<::Callees *>(&(found->rewards))->FUN_00726070())))
                    reinterpret_cast<::FUN_005ac340_t *>((((ChallengeReward*)((::ChallengeNode *)(reinterpret_cast<::Callees *>(&(found->rewards))->FUN_00726070())))))->RunScriptOnTarget((::TESObjectREFR *)((*reinterpret_cast<void * *>(&::_g_thePlayer))), (::ScriptLocals *)(0));
                if (((int)(uintptr_t)(reinterpret_cast<::FUN_006a1b60_Class *>((found))->GetField54())) != 11 || reinterpret_cast<::FUN_005f5fa0_cls *>((found))->GetShortAtOffset64() != 27)
                    ::TopicMenuController::IncrementMiscStat(27);
                if (found->name.FUN_00408da0() && found->description.GetText(0, 0x43534544) && *::g_011cb4d4.Bool())
                {
                    char message[512];
                    FUN_00406d00(message, 512, "%s   %d\\%d\n%s", found->name.FUN_00408da0(), reinterpret_cast<::LowProcess *>((found))->GetPackageObjectType(),
                                 reinterpret_cast<::LowProcess *>((found))->GetPackageObjectType(), found->description.GetText(0, 0x43534544));
                    ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::FUN_0048e730((::TESForm *)(found), 0)), (const char *)(0), 2.0f, false);
                    FUN_00706f30(21);
                }
                if (reinterpret_cast<::FUN_005f5f60_class *>((found))->FUN_005f5f60() && !reinterpret_cast<::FUN_005f60c0_Class *>((found))->HasFlag8())
                {
                    int remainder = ((int)(uintptr_t)(reinterpret_cast<::DialogueItem *>((found))->SelectDefaultResponseList())) - reinterpret_cast<::LowProcess *>((found))->GetPackageObjectType();
                    reinterpret_cast<::FUN_005f5820_shell *>((found))->ClearField6C();
                    reinterpret_cast<::FUN_005f6060_class *>((found))->FUN_005f6060(true);
                    found->FUN_005f60e0(remainder);
                }
                else
                {
                    reinterpret_cast<::FUN_005f6000_Class *>((found))->SetFlagAndMarkForSave(true);
                    result = true;
                }
            }
            else
            {
                int value = ((int)(uintptr_t)(reinterpret_cast<::DialogueItem *>((found))->SelectDefaultResponseList()));
                int item = ((int)(uintptr_t)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((found))->FUN_005f5f80())) ? ((int)(uintptr_t)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((found))->FUN_005f5f80())) : 100;
                for (int current = value; current >= 0; current -= item)
                {
                    if (current == 0)
                    {
                        if (found->name.FUN_00408da0() && found->description.GetText(0, 0x43534544) &&
                            *::g_011cb4d4.Bool())
                        {
                            char message[512];
                            FUN_00406d00(message, 512, "%s   %d\\%d\n%s", found->name.FUN_00408da0(),
                                         ((int)(uintptr_t)(reinterpret_cast<::DialogueItem *>((found))->SelectDefaultResponseList())), reinterpret_cast<::LowProcess *>((found))->GetPackageObjectType(),
                                         found->description.GetText(0, 0x43534544));
                            ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::FUN_0048e730((::TESForm *)(found), 0)), (const char *)(0), 2.0f, false);
                        }
                    }
                }
            }
        }
        pNode = ((::ChallengeNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    if (result)
        ::ChallengeManager::CheckCompletedChallenges();
    return true;
}

struct NavMeshStaticAvoidNode : FUN_005ecd10_cls
{
};
struct NodeArray : BSSimpleArray<NavMeshStaticAvoidNode*, 1024>
{
    NavMeshStaticAvoidNode* FUN_00691750(int index);
};
struct FUN_005ece50_class
{
    unsigned char m0;
    BSSimpleArray<const char*, 1024> m4;
    NodeArray m14;
    unsigned char FUN_005ece50(FUN_005ece50_class* other);
};
// Compares two instances by node-array size and per-node equality, string-array size and per-string comparison, and the m0 byte; returns 1 if any differ.
// @fnv 0x005ece50
unsigned char FUN_005ece50_class::FUN_005ece50(FUN_005ece50_class* other)
{
    unsigned char bStack_5 = 0;
    unsigned int uStack_18;
    {
        unsigned int uStack_c;
        if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m14))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(other->m14))->GetName())))
            bStack_5 = 1;
        if (bStack_5 == 0)
        {
            for (uStack_18 = 0; uStack_18 < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m14))->GetName())) && bStack_5 == 0; ++uStack_18)
            {
                bStack_5 =
                    (bStack_5 == 0 &&
                     m14.FUN_00691750((int)uStack_18)->FUN_005ece20((intptr_t)other->m14.FUN_00691750((int)uStack_18)) == 0)
                        ? 0
                        : 1;
            }
        }
        if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((void *)&(m4))->GetName())) != ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((void *)&(other->m4))->GetName())))
            bStack_5 = 1;
        if (bStack_5 == 0)
        {
            for (uStack_c = 0; uStack_c < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((void *)&(m4))->GetName())) && bStack_5 == 0; ++uStack_c)
            {
                bStack_5 = (bStack_5 == 0 && FUN_00408b20(m4.GetAt((int)uStack_c), other->m4.GetAt((int)uStack_c)) == 0)
                               ? 0
                               : 1;
            }
        }
    }
    if (bStack_5 != 0 || m0 != other->m0)
        bStack_5 = 1;
    return bStack_5;
}

class PlayerCharacter
{
};
class TESSound;
struct SoundDataHandler
{
};

// Builds a "BRUSH<prefix><Sneak|Run|Walk>" sound name from the player's state and looks it up via the sound data handler.
// @fnv 0x005e2a70
TESSound* GetBrushSound(const char* apPrefix)
{
    char soundName[40];
    char fallbackName[40];
    if (::_g_thePlayer)
    {
        const char* pcMotion;
        if (reinterpret_cast<::Actor *>((::_g_thePlayer))->IsSneaking())
            pcMotion = "Sneak";
        else
        {
            const char* pcRegularMotion;
            if (reinterpret_cast<::FUN_00884730_shell *>((::_g_thePlayer))->FUN_00884730())
                pcRegularMotion = "Run";
            else
                pcRegularMotion = "Walk";
            pcMotion = pcRegularMotion;
        }
        ::FUN_00406d00(soundName, 40, "BRUSH%s%s", ::GetStringByIndex((intptr_t)(apPrefix)), pcMotion);
        return reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::SoundDataHandler * *>(&::g_dataHandler))))->GetSoundByEditorID(soundName);
    }
    else
    {
        ::FUN_00406d00(fallbackName, 40, "BRUSH%sWalk", ::GetStringByIndex((intptr_t)(apPrefix)));
        return reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::SoundDataHandler * *>(&::g_dataHandler))))->GetSoundByEditorID(fallbackName);
    }
    return 0;
}

extern const char* DAT_01196d40[10];

// @fnv 0x005e2b50
const char* __cdecl GetStringByIndex(intptr_t index)
{
    if (index >= 0 && index < 10)
    {
        return DAT_01196d40[index];
    }
    return 0;
}

struct BSStr
{
};
struct FUN_005e2c10_shell
{
    char pad[0x3c];
    BSStr m3c;
    bool SetString(const char* a);
};
// Calls Set on the BSStr at offset 0x3c with the given string and a zero argument, then returns true.
// @fnv 0x005e2c10
bool FUN_005e2c10_shell::SetString(const char* apString)
{
    reinterpret_cast<::TextString *>((&m3c))->FUN_004037f0(apString, 0);
    return true;
}

extern const char $SG3295[];
struct FUN_005e2c30_class
{
    char m0[0x3c];
    GO m3c;
    const char* FUN_005e2c30();
};
// Returns m3c as a string pointer if it is non-null, otherwise returns the fallback string $SG3295.
// @fnv 0x005e2c30
const char* FUN_005e2c30_class::FUN_005e2c30()
{
    return (const char*)(uintptr_t)(unsigned int)m3c ? (const char*)(uintptr_t)(unsigned int)m3c : $SG3295;
}

struct FUN_005e2ca0_s
{
    void FUN_005e2ca0();
};
struct FUN_005e2c70_s : FUN_005e2ca0_s
{
    void* FUN_005e2c70(unsigned int flags);
};
struct SoundData
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
};

class TESForm
{
  public:
    virtual ~TESForm();
public:
    bool GetInitialized() const;
    ::ENUM_FORM_ID GetFormType() const;
};

class TESSound : public TESForm
{
  public:
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
    SoundData soundData;
    unsigned char unk68;
    void CopyFromSound(TESForm* form);
};

// Casts form to TESSound, copies unk68, calls FUN_004851b0, then copies soundData from CopyBig.
// @fnv 0x005e2d20
void TESSound::CopyFromSound(TESForm* form)
{
    TESSound* sound = dynamic_cast<TESSound*>(form);
    if (!sound)
    {
        return;
    }
    unk68 = sound->unk68;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(form);
    soundData = (*(::SoundData *)(reinterpret_cast<::Holder *>((sound))->CopyBig(&BigSlot<::Big>(BigResult{}))));
}


struct FUN_005e2fa0_SoundFile
{
};

struct FUN_005e2fa0_SoundData
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
};

struct FUN_005e2fa0_standin
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
    FUN_005e2fa0_SoundFile unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_005e2fa0_SoundData unk44;
    unsigned char unk68;
    void WriteToStream();
};

class TESSound;
struct ContNode;
bool FUN_008256d0(ContNode* node);
struct FUN_00408da0_Class
{
    int* FUN_00408da0();
};
// @fnv 0x005f6f70
void FUN_005f6f70_Class::FUN_005f6f70()
{
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(unk44, 0x1c);
    unsigned char a;
    a = 0;
    if (((char *)(reinterpret_cast<::FUN_00408da0_Class *>((&unk18))->FUN_00408da0())))
        a = ((int)(::FUN_0044a670(((char *)(reinterpret_cast<::FUN_00408da0_Class *>((&unk18))->FUN_00408da0())))));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&a, 1);
    if (a)
        reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(((char *)(reinterpret_cast<::FUN_00408da0_Class *>((&unk18))->FUN_00408da0())), a);
    a = 0;
    if (((char *)(reinterpret_cast<::FUN_00408da0_Class *>((&unk2c))->FUN_00408da0())))
        a = ((int)(::FUN_0044a670(((char *)(reinterpret_cast<::FUN_00408da0_Class *>((&unk2c))->FUN_00408da0())))));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&a, 1);
    if (a)
        reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(((char *)(reinterpret_cast<::FUN_00408da0_Class *>((&unk2c))->FUN_00408da0())), a);
}
struct ListNodeHelper
{
};
class DataHandler
{
  public:
};

// Searches the data handler's sound list for a TESSound whose stored name matches filename, returning the first match or null.
// @fnv 0x005e3570
TESSound* __cdecl FUN_005e3570(char const* filename)
{
    TESSound* result = 0;
    if (filename != 0)
    {
        ContNode* node = reinterpret_cast<ContNode*>(((::BSSimpleList< ::TESSound *> *)(reinterpret_cast<::FUN_0045c650_shell *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->FUN_0045c650())));
        while (node != 0 && !FUN_008256d0(node))
        {
            TESSound* sound = reinterpret_cast<TESSound*>(*((void **)(new ((void *)(reinterpret_cast<ListNodeHelper*>(node))) ::Vec3())));
            if (reinterpret_cast<FUN_00408da0_Class*>(&sound->unk30)->FUN_00408da0() != 0)
            {
                if (FUN_00404dc0(reinterpret_cast<char const*>(
                                     reinterpret_cast<FUN_00408da0_Class*>(&sound->unk30)
                                         ->FUN_00408da0()),
                                 filename) == 0)
                {
                    result = sound;
                    break;
                }
            }
            node = ((::ContNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    return result;
}


bool __cdecl FUN_005e39a0();

extern unsigned int DAT_011caf04[10];
extern char DAT_011caf2c[10];
extern char DAT_011caf36;

template <class T> struct BSSimpleListEx : public BSSimpleList<T>
{
    int GetSize();
};

// Searches a directory for a .wav or .ogg file, picks one at random avoiding recent repeats, writes its path into a1 and returns whether one was found.
// @fnv 0x005e3630
bool FindDialogueFile(char* apPath)
{
    char oggPattern3[260];
    char basePath8[260];
    char wavPattern[260];

    ::TaskQueueInterface::CopyStringToBuffer(wavPattern, 260, apPath);
    ::TaskQueueInterface::CopyStringToBuffer(basePath8, 260, apPath);
    strcat_s(wavPattern, 260, "*.wav");
    ::TaskQueueInterface::CopyStringToBuffer(oggPattern3, 260, apPath);
    strcat_s(oggPattern3, 260, "*.ogg");

    if (!FUN_005e39a0())
    {
        bool found7 = false;
        found7 = ::fnv_00af7400::ResolveArchivePath(wavPattern, basePath8, 8);
        if (found7)
        {
            ::TaskQueueInterface::CopyStringToBuffer(apPath, 260, basePath8);
        }
        return found7;
    }

    BSSimpleList<char*>* pFileList = ((::BSSimpleList<char *> *)(::FUN_00afe420(oggPattern3, basePath8, 8, (::FileMatchList *)(0))));
    if (!pFileList)
    {
        pFileList = ((::BSSimpleList<char *> *)(::FUN_00afe420(wavPattern, basePath8, 8, (::FileMatchList *)(0))));
    }

    if (pFileList != NULL)
    {
        unsigned int aCount = ((BSSimpleListEx<char*>*)pFileList)->GetSize();
        if (aCount != 0)
        {
            unsigned int uiChosen = DialogueRandom() % aCount;
            if (aCount > 1)
            {
                unsigned int uiHash = ::BSGameSound::ComputeSoundNameHash(apPath);
                for (int iIndex = 0; iIndex < 10; ++iIndex)
                {
                    if (DAT_011caf04[iIndex] == uiHash)
                    {
                        while (uiChosen == (unsigned int)DAT_011caf2c[iIndex])
                        {
                            uiChosen = FUN_005a00a0(aCount);
                        }
                        break;
                    }
                }
                DAT_011caf04[DAT_011caf36] = uiHash;
                DAT_011caf2c[DAT_011caf36] = (char)uiChosen;
                DAT_011caf36 %= 10;
            }

            BSSimpleList<char*>* pNode = pFileList;
            while (pNode != NULL)
            {
                if (((char *)(new ((void *)(pNode)) ::Vec3())) != NULL)
                {
                    if (uiChosen == 0)
                    {
                        ::TaskQueueInterface::CopyStringToBuffer(apPath, 260, ((char *)(new ((void *)(pNode)) ::Vec3())));
                    }
                    void* item = ((char *)(new ((void *)(pNode)) ::Vec3()));
                    ::FUN_00401030(item);
                }
                uiChosen--;
                pNode = ((::BSSimpleList<char *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
            }

            reinterpret_cast<::FileMatchList *>((pFileList))->RemoveAll();
            delete pFileList;
            return true;
        }
        delete pFileList;
    }
    return false;
}

// @fnv 0x005e39a0
bool FUN_005e39a0()
{
    return DAT_011acdf9;
}

// @fnv 0x005e39b0
int __cdecl GetFlagMask(unsigned int flags)
{
    int result = 0;
    if (flags & 0x10)
        result = 0x10;
    else if (flags & 0x200)
        result = 0x2000000;
    else if (flags & 0x400)
        result = 0x4000000;
    return result;
}

struct FUN_005e50f0_Obj
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
    std::intptr_t unk34[16];
    std::intptr_t GetValueByIndex(intptr_t index);
};

// Returns unk34[index] when index is between 0 and 14, otherwise returns 0.
// @fnv 0x005e50f0
std::intptr_t FUN_005e50f0_Obj::GetValueByIndex(intptr_t index)
{
    std::intptr_t result = 0;
    if (index > -1 && index < 15)
        result = unk34[index];
    return result;
}

struct FUN_005e5190_Class
{
    char pad[0x63];
    unsigned char unk63;
    unsigned char GetByte63();
};

// @fnv 0x005e5190
unsigned char FUN_005e5190_Class::GetByte63()
{
    return unk63;
}

struct Obj5e5300
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned char unk60;
    unsigned char unk61;
    unsigned int GetByte61();
};

// @fnv 0x005e5300
unsigned int Obj5e5300::GetByte61()
{
    return unk61;
}

struct FUN_005e5380_shell
{
};
struct FUN_0066e010_entry
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
};
struct G2
{
    void AddHead(int*);
};
struct FUN_005e5320_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    FUN_0066e010_entry m34;
    FUN_0066e010_entry m54;
    FUN_0066e010_entry m74;
    FUN_0066e010_entry m94;
    FUN_0066e010_entry mb4;
    FUN_0066e010_entry md4;
    FUN_0066e010_entry mf4;
    FUN_0066e010_entry m114;
    FUN_0066e010_entry m134;
    FUN_0066e010_entry m154;
    FUN_0066e010_entry m174;
    FUN_0066e010_entry m194;
    FUN_0066e010_entry m1b4;
    FUN_0066e010_entry m1d4;
    FUN_0066e010_entry m1f4;
    void FUN_005e5320(G2* list);
};

struct FUN_005e5380_Class
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
    unsigned char unk60;
    bool IsFlag2Set();
};
// @fnv 0x005e5320
void FUN_005e5320_class::FUN_005e5320(G2* list)
{
    if (list)
    {
        for (int i = 0; i < 15; ++i)
        {
            int* entry = *(int**)((char*)&this->m34 + i * 4);
            if (!entry)
                continue;
            if (reinterpret_cast<::FUN_005e5380_Class *>((((FUN_005e5380_shell*)entry)))->IsFlag2Set())
            {
                list->AddHead((int*)&entry);
            }
        }
    }
}

// @fnv 0x005e5380
bool FUN_005e5380_Class::IsFlag2Set()
{
    return this->unk60 & 2;
}

// 0x005e0d20 - ScriptRunner::Run-like: nested-run guard, climate-list loop,
// per-run expression object (ctor 0x593490 / dtor 0x483710), optional timing.

extern "C" __int64 DAT_011caec8;
extern "C" char g_nestedScriptRunFormat[];


struct Clist
{
    char m0[8];
    unsigned int m8;
    char mC[5];
    unsigned char m11;
};

struct CL8
{
    unsigned char b0;
    unsigned char b1;
    float f4;
};

struct SLoc
{
    ~SLoc();
    char p0[0x10];
    CL8* m10;
};

struct Vt130
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
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
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual int v130();
};

struct A8 : Vt130
{
};

struct Big79
{
    Big79();
    ~Big79();
    char m[0x710];
};

struct Runner
{
    int m0;
    void* m4;
    SLoc* m8;
    int mC;
    int m10;
    A8* m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    char pad28[0xa1 - 0x28];
    bool m_a1;
    bool RunScript(A8* a1, void* a2, SLoc* a3, int a4, bool a5, char a6, char a7, float a8);
};

// Executes a script on a1, iterating its Clist entries via FUN_005e13a0/FUN_005e1550, and records elapsed time when profiling is enabled.
// @fnv 0x005e0d20
bool Runner::RunScript(A8* apScript, void* apObject, SLoc* a3, int a4, bool a5, char a6, char a7, float a8)
{
    bool vf = FUN_00702fc0();
    __int64 ve = 0;
    __int64 vo;
    if (vf)
    {
        if (DAT_011caec8 == 0)
            QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&DAT_011caec8));
        QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&ve));
    }

    this->m_a1 = false;
    if (!apScript || !reinterpret_cast<::TESForm *>((apScript))->GetInitialized())
        return this->m_a1;

    if (this->m14)
    {
        ::FUN_005b5e40();
        return this->m_a1;
    }
    this->m14 = apScript;

    Big79 vb;
    SLoc* vg = 0;
    this->m24 = 0;
    this->m20 = 0;
    int va = 0xffff;
    unsigned int vd = 0;
    this->m0 = a4;
    if (apObject)
        this->m4 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apObject))->FUN_007af430()));
    else
        this->m4 = 0;
    if (a3)
    {
        this->m8 = a3;
    }
    else
    {
        vg = ((::SLoc *)(reinterpret_cast<::FUN_005abf60_shell *>((apScript))->FUN_005abf60()));
        this->m8 = vg;
    }

    if (((::Clist *)(reinterpret_cast<::BGSCameraPath *>((apScript))->GetConditions()))->m11)
    {
        if (!this->m8->m10)
            this->m8->m10 = new CL8;
        this->m8->m10->b0 = a6;
        this->m8->m10->b1 = a7;
        this->m8->m10->f4 = a8;
    }

    int vk = 0;
    intptr_t vi = 0;
    int vl = 0;
    bool vw = false;
    int vc = 0;
    while (vd < ((::Clist *)(reinterpret_cast<::BGSCameraPath *>((apScript))->GetConditions()))->m8)
    {
        vc++;
        this->m10 = 0;
        vk = 0;
        if (!reinterpret_cast<::ScriptRunner *>((this))->ParseOutput((::Script *)(apScript), (*(::SCRIPT_OUTPUT *)(&va)), (*(unsigned int *)(&vd)), (*(int *)(&vk)), (::TESObjectREFR **)(int *)(&vi), vl != 0))
        {
            ((::Clist *)(reinterpret_cast<::BGSCameraPath *>((apScript))->GetConditions()))->m8 = 0;
            break;
        }
        if (vl)
        {
            vl--;
        }
        else
        {
            if (va == 0x1e)
                break;
            if (!vi)
                vi = (intptr_t)apObject;
            if (!reinterpret_cast<::ScriptRunner *>((this))->ParseBlock((::Script *)(apScript), (const ::SCRIPT_OUTPUT)(va), (::TESObjectREFR *)(void *)((void*)vi), (*(int *)(&vk)), vd, (*(unsigned int *)(&vl)), vc, 0, 0))
            {
                vw = true;
                break;
            }
        }
        vd += vk;
    }

    if (!a5 && !vw)
        reinterpret_cast<::FUN_005a8ea0_shell *>((this->m8))->FUN_005a8ea0();

    if (vg)
        delete vg;

    this->m14 = 0;

    if (vf)
    {
        QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&vo));
        float elapsed = (float)((double)(vo - ve) / (double)DAT_011caec8);
        reinterpret_cast<::FUN_005e1140_Class *>((apScript))->FUN_005e1140(elapsed);
    }

    return this->m_a1;
}

// Stand-in for the native TESBoundAnimObject base subobject (size 0x30).
class SoundBoundAnimBase
{
  public:
    virtual ~SoundBoundAnimBase();
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
};
class TESSoundFile
{
  public:
    virtual ~TESSoundFile();
    BSStringT<char> soundFile;
};
// Native TESSound destructor; both bases and the string member own their lifetimes.
class FUN_005e2ca0 : public SoundBoundAnimBase, public TESSoundFile
{
  public:
    BSStringT<char> editorID;
    virtual ~FUN_005e2ca0();
};
// Calls FUN_005e2ca0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005e2c70
void* FUN_005e2c70_s::FUN_005e2c70(unsigned int flags)
{
    reinterpret_cast<::FUN_005e2ca0 *>(this)->FUN_005e2ca0::~FUN_005e2ca0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Empty destructor of a class deriving from SoundBoundAnimBase and TESSoundFile with an editorID string member.
// @fnv 0x005e2ca0
FUN_005e2ca0::~FUN_005e2ca0()
{}

struct TESSound__SOUND_DATA
{
    unsigned char minAttenuation;
    unsigned char maxAttenuation;
    signed char frequencyAdjustment;
    unsigned char unk03;
    unsigned int soundFlags;
    unsigned short staticAttenuation;
    unsigned short stopTime;
    unsigned short attenuationCurve[5];
    unsigned short reverbAttenuation;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    signed char frequencyVariance;
    void SwapEndian();
};
// @fnv 0x005e2fa0
void FUN_005e2fa0_standin::WriteToStream()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((this))->FUN_004855a0();
    reinterpret_cast<::FUN_0048cea0_shell *>(&(this->unk30))->FUN_0048cea0();
    FUN_004858f0(0x4d414e52, this->unk68);

    if (FUN_00401500() != 0)
    {
        reinterpret_cast<::TESSound__SOUND_DATA *>(&(this->unk44))->SwapEndian();
    }

    ::AppendChunk(0x44444e53, &this->unk44, 0x24);

    if (FUN_00401500() != 0)
    {
        reinterpret_cast<::TESSound__SOUND_DATA *>(&(this->unk44))->SwapEndian();
    }

    reinterpret_cast<::Holder *>((this))->FUN_00485680();
}
// Swaps the byte order of the multi-byte fields in the TESSound__SOUND_DATA structure using BSEndian.
// @fnv 0x005e3020
void TESSound__SOUND_DATA::SwapEndian()
{
    ::FUN_00401080((int *)(unsigned int *)(&soundFlags));
    ::FUN_00407a90((short *)(unsigned short *)(&staticAttenuation));
    ::FUN_00407a90((short *)(unsigned short *)(&stopTime));
    ::FUN_00407a90((short *)(unsigned short *)(&attenuationCurve[0]));
    ::FUN_00407a90((short *)(unsigned short *)(&attenuationCurve[1]));
    ::FUN_00407a90((short *)(unsigned short *)(&attenuationCurve[2]));
    ::FUN_00407a90((short *)(unsigned short *)(&attenuationCurve[3]));
    ::FUN_00407a90((short *)(unsigned short *)(&attenuationCurve[4]));
    ::FUN_00407a90((short *)(unsigned short *)(&reverbAttenuation));
    ::FUN_00401080((int *)(unsigned int *)(&unk18));
    ::FUN_00401080((int *)(unsigned int *)(&unk1c));
    ::FUN_00401080((int *)(unsigned int *)(&unk20));
}

struct InitTag5E35
{
};


struct Data5E35
{
    int unk00;
    int m_04;
    short m_08;
    short m_0A;
    void FUN_005e3510();
};

// Initializes m_04, m_08, and m_0A by calling FUN_00401080 and FUN_00407a90 with InitTag5E35.
// @fnv 0x005e3510
void Data5E35::FUN_005e3510()
{
    ::FUN_00401080(&m_04);
    ::FUN_00407a90(&m_08);
    ::FUN_00407a90(&m_0A);
}

struct DeletingObject
{
    void FUN_005e4bc0();
    void* FUN_005e4b90(unsigned int flags);
};
class FUN_00483630_holder
{
  public:
    virtual ~FUN_00483630_holder();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class TESModel
{
  public:
    virtual ~TESModel();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class BGSPreloadable
{
  public:
    virtual void Preload();
};

class BGSBodyPartData
{
  public:
    virtual void ClearData();
};

class FUN_005e4bc0 : public FUN_00483630_holder, public TESModel, public BGSPreloadable
{
  public:
    virtual ~FUN_005e4bc0();
};
// Calls FUN_005e4bc0, then deletes this via operator delete if the low bit of flags is set, and returns this.
// @fnv 0x005e4b90
void* DeletingObject::FUN_005e4b90(unsigned int flags)
{
    reinterpret_cast<::FUN_005e4bc0 *>(this)->FUN_005e4bc0::~FUN_005e4bc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor whose body casts this to BGSBodyPartData and calls its ClearData.
// @fnv 0x005e4bc0
FUN_005e4bc0::~FUN_005e4bc0()
{
    reinterpret_cast<BGSBodyPartData*>(this)->BGSBodyPartData::ClearData();
}

struct Skin55;
struct Part55
{
};
struct Node55;
struct BaseObject55
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node55* IsSceneNode();
};
struct Object55 : BaseObject55
{
};
struct Skin55 : BaseObject55
{
};
struct Node55 : Object55
{
    unsigned int FUN_0043b480();
};
struct Geometry55 : Object55
{
};
struct Name55
{
    const char* FUN_007fa950();
};
extern const NiRTTI_S DAT_011f4acc;
struct Body55
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
    Name55* names[15];
    void HidePartitionsUnderAncestor(Object55* ancestor, Object55* root, intptr_t excluded, Object55* object);
};

// For each named entry other than excluded, if the object found under root has ancestor as a parent, sets partition i of object's geometry skins not visible.
// @fnv 0x005e55e0
void Body55::HidePartitionsUnderAncestor(Object55* ancestor, Object55* root, intptr_t excluded, Object55* object)
{
    Node55* node2 = object->IsSceneNode();
    for (int i = 0; i < 15; ++i)
    {
        if (i == excluded || !names[i])
            continue;
        Object55* found7 = (Object55*)::FUN_004aae30((::NiAVObject *)root, (::NiFixedString *)reinterpret_cast<::StrOwner *>((names[i]))->FUN_007fa950());
        if (!found7)
            continue;
        while (found7 != root)
        {
            if (found7 == ancestor)
            {
                unsigned int index = 0;
                do
                {
                    Skin55* skin5;
                    Geometry55* geometry = node2
                                               ? (Geometry55*)::FUN_00653270((const ::NiRTTI *)&DAT_011f4acc, (::NiObject *)((::Object55 *)(reinterpret_cast<::NiNode *>((node2))->GetAt(index++))))
                                               : (Geometry55*)::FUN_00653270((const ::NiRTTI *)&DAT_011f4acc, (::NiObject *)object);
                    skin5 = geometry ? ((::Skin55 *)(::fnv_0043fad0::FUN_0043fad0((const char *)(geometry)))) : 0;
                    Part55* partition2 = (Part55*)::FUN_00653270((const ::NiRTTI *)&g_011f49d8, (::NiObject *)skin5);
                    if (partition2)
                        reinterpret_cast<::SomeClass *>((partition2))->SetEntryStateByKey((unsigned short)i, false);
                } while (node2 && index < node2->FUN_0043b480());
                break;
            }
            found7 = ((::Object55 *)(reinterpret_cast<::FUN_009611e0_shell *>((found7))->FUN_009611e0()));
        }
    }
}

namespace fnv_005e5750 {
struct SceneNode;
struct SceneBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual SceneNode* IsSceneNode();
};
struct SceneObject : SceneBase
{
};
struct SceneNode : SceneObject
{
    SceneObject* FUN_0045bc00(unsigned int);
    unsigned int FUN_0043b480();
};
struct Geometry : SceneObject
{
};
struct PartitionSkin
{
};
struct PartitionOwner
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
    ::StrOwner* names[15];
    void ApplyPartitionState(SceneObject* target, SceneObject* root, intptr_t excluded, SceneObject* source);
};
// For each non-excluded name, if its node under root has target as an ancestor, enables that partition entry on the skin of each geometry in source.
// @fnv 0x005e5750
void PartitionOwner::ApplyPartitionState(SceneObject* target, SceneObject* root, intptr_t excluded, SceneObject* source)
{
    SceneNode* node = source->IsSceneNode();
    for (int i = 0; i < 15; ++i)
    {
        if (i == excluded || !names[i])
            continue;
        SceneObject* found = (SceneObject*)::FUN_004aae30((::NiAVObject *)root, (::NiFixedString *)names[i]->FUN_007fa950());
        if (!found)
            continue;
        while (found != root)
        {
            if (found == target)
            {
                int childIndex = 0;
                SkinInst_S* skin;
                do
                {
                    Geometry* geom = node ? (Geometry*)::FUN_00653270((const ::NiRTTI *)&DAT_011f4acc, (::NiObject *)node->FUN_0045bc00(childIndex++))
                                          : (Geometry*)::FUN_00653270((const ::NiRTTI *)&DAT_011f4acc, (::NiObject *)source);
                    skin = geom ? ((::SkinInst_S *)(::fnv_0043fad0::FUN_0043fad0((const char *)(geom)))) : 0;
                    PartitionSkin* partitions = (PartitionSkin*)::FUN_00653270((const ::NiRTTI *)&g_011f49d8, (::NiObject *)(SceneBase*)skin);
                    if (partitions)
                    {
                        for (int j = 0; j < 15; ++j)
                        {
                            if (j == i)
                                reinterpret_cast<::SomeClass *>((partitions))->SetEntryStateByKey((unsigned short)i, true);
                        }
                    }
                } while (node && childIndex < node->FUN_0043b480());
                break;
            }
            found = ((::fnv_005e5750::SceneObject *)(reinterpret_cast<::FUN_009611e0_shell *>((found))->FUN_009611e0()));
        }
    }
}
}  // namespace fnv_005e5750

namespace s5e5d20 {

class Actor
{
};


// Scales the value pointed to by ppfValue by the result of pkActor->FUN_006b9130() if FUN_005e5b80 succeeds.
// @fnv 0x005e5d20
void FUN_005e5d20(void* pvArg0, void* pvArg1, unsigned char ucArg2, float** ppfValue, Actor* pkActor)
{
    if (!::FUN_005e5b80(0, 1, (::TESObjectREFR *)(pvArg0), (int)(intptr_t)(pvArg1), ucArg2, (void **)(ppfValue), pkActor))
        return;
    float* pfValue = *ppfValue;
    Actor* pkTarget = pkActor;
    *pfValue = reinterpret_cast<::TimeoutTimer *>((pkTarget))->FUN_006b9130() * *pfValue;
}

}

namespace s5e63f0 {

extern "C" const char DAT_010462c0[];

struct Base
{
    const char* m_pVtbl;

    Base* FUN_005e6420();
};

struct Derived : Base
{
    float m_fValue;

    Derived* FUN_005e63f0();
};

// Calls FUN_005e6420, stores DAT_010462c0 in m_pVtbl, zeroes m_fValue and returns this.
// @fnv 0x005e63f0
Derived* Derived::FUN_005e63f0()
{
    FUN_005e6420();
    m_pVtbl = DAT_010462c0;
    m_fValue = 0.0f;
    return this;
}

}

namespace s5e6420 {

extern "C" const char DAT_010462e0[];

struct Holder
{
    const char* m_pTable;

    Holder* FUN_005e6420();
};

// @fnv 0x005e6420
Holder* Holder::FUN_005e6420()
{
    m_pTable = DAT_010462e0;
    return this;
}

}

extern void* DAT_01046320;

struct FUN_005e6510_cls
{
    void* vtbl;
    int m4;
    void FUN_005e6420();
    FUN_005e6510_cls* FUN_005e6510();
};

// Initializes the object by calling FUN_005e6420, setting the vtable to DAT_01046320, and zeroing m4.
// @fnv 0x005e6510
FUN_005e6510_cls* FUN_005e6510_cls::FUN_005e6510()
{
    FUN_005e6420();
    vtbl = &DAT_01046320;
    m4 = 0;
    return this;
}

extern int DAT_01048bb4, DAT_01048ba0, DAT_01048b88, DAT_01048b68, DAT_01048b54;
struct FUN_00483370
{
    void* table_00;
    unsigned int unknown_04, unknown_08, unknown_0c, unknown_10, unknown_14;
    FUN_00483370();
    ~FUN_00483370();
};
struct FUN_00402d00
{
    void* table_18;
    unsigned int unknown_1c, unknown_20;
    FUN_00402d00();
    ~FUN_00402d00();
};
struct FUN_00482c50
{
    void* table_24;
    unsigned int unknown_28;
    FUN_00482c50();
};
struct FUN_0048e270
{
    void* table_2c;
    unsigned int unknown_30, unknown_34;
    FUN_0048e270();
    ~FUN_0048e270();
};
struct FUN_0047ff70
{
    void* table_38;
    FUN_0047ff70();
    ~FUN_0047ff70();
};
struct FUN_005f6610 : FUN_00483370, FUN_00402d00, FUN_00482c50, FUN_0048e270, FUN_0047ff70
{
    FUN_005f6610();
};
// Sets the five table pointers at offsets 0x00, 0x18, 0x24, 0x2c and 0x38 after the base constructors, then calls FUN_004f15a0(7) and FUN_005f67c0().
// @fnv 0x005f6610
FUN_005f6610::FUN_005f6610()
{
    table_00 = &DAT_01048bb4;
    table_18 = &DAT_01048ba0;
    table_24 = &DAT_01048b88;
    table_2c = &DAT_01048b68;
    table_38 = &DAT_01048b54;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(7);
    reinterpret_cast<::TESClass *>(this)->ResetFormData();
}

struct FUN_005e07d0
{
    virtual ~FUN_005e07d0();
};
// @fnv 0x005e07d0
FUN_005e07d0::~FUN_005e07d0()
{}

struct FUN_005e9830 : Stub
{
    virtual ~FUN_005e9830();
};
// @fnv 0x005e9830
FUN_005e9830::~FUN_005e9830()
{
    this->FUN_005e9860();
}

struct EquivData_5ecd10
{
    short sValue00;
    short sValue02;
    float fValue04;
    float fValue08;
    float fValue0C;
    float fValue10;
    float fValue14;
    float fValue18;
    float fValue1C;
    float fValue20;
    float fValue24;

    bool IsEqual(const EquivData_5ecd10& other);
};
// Returns true when IsEqual returns zero for the given index.
// @fnv 0x005ece20
bool FUN_005ecd10_cls::FUN_005ece20(intptr_t a)
{
    return !((unsigned char)(reinterpret_cast<::EquivData_5ecd10 *>(this)->IsEqual((*(const ::EquivData_5ecd10 *)(a)))));
}

// Returns true when every member of this EquivData_5ecd10 matches the corresponding member of other.
// @fnv 0x005ecd10
bool EquivData_5ecd10::IsEqual(const EquivData_5ecd10& other)
{
    bool bEqual = false;
    if (sValue00 == other.sValue00 && sValue02 == other.sValue02 && fValue1C == other.fValue1C &&
        fValue20 == other.fValue20 && fValue24 == other.fValue24 && fValue10 == other.fValue10 &&
        fValue14 == other.fValue14 && fValue18 == other.fValue18 && fValue04 == other.fValue04 &&
        fValue08 == other.fValue08 && fValue0C == other.fValue0C)
    {
        bEqual = true;
    }
    return bEqual;
}

struct BSSimpleArrayActor
{
    void Clear(bool);
};
struct FUN_005ef3b0_class : BSSimpleArrayActor
{
    int* p;
    void FUN_005ef3b0();
};
// Calls the destructor on this object and, when bit 0 of flags is set, frees the object's memory, then returns this.
// @fnv 0x005ef620
FUN_005ef3b0* FUN_005ef3b0::FUN_005ef620(unsigned int flags)
{
    reinterpret_cast<::FUN_005ef3b0_class *>((this))->FUN_005ef3b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x005ef3b0
void FUN_005ef3b0_class::FUN_005ef3b0()
{
    p = &DAT_01047320;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct FUN_005efbc0_s
{
    virtual void v0();
    virtual void* v4(unsigned int);
};
struct FUN_005efd40_s : FUN_005efbc0_s
{
    void* m4;
    int m8;
    int mc;
    void FUN_005efd40(unsigned int requested, unsigned int savedSize);
};
// Sets the vtbl to DAT_01047320, calls FUN_005efd40(0, 0), and returns this.
// @fnv 0x005ef380
FUN_005efd40_class* FUN_005efd40_class::FUN_005ef380()
{
    vtbl = &DAT_01047320;
    reinterpret_cast<::FUN_005efd40_s *>(this)->FUN_005efd40(0, 0);
    return this;
}
// Zeroes m4/m8/mc, sets m4 from v4(max(requested, savedSize)) with mc as that size, then calls ConstructItems and sets m8 to savedSize if nonzero.
// @fnv 0x005efd40
void FUN_005efd40_s::FUN_005efd40(unsigned int requested, unsigned int savedSize)
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        m4 = v4(requested);
        mc = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::EFBC0Array *>(this)->ConstructItems((::EFBC0Item *)(m4), savedSize);
        m8 = savedSize;
    }
}

class FUN_005e2d90_TESSound : public TESForm
{
  public:
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
    unsigned char minAttenuation;
    unsigned char maxAttenuation;
    signed char frequencyAdjustment;
    unsigned char unk47;
    unsigned int soundFlags;
    unsigned short staticAttenuation;
    unsigned short stopTime;
    unsigned short attenuationCurve[5];
    unsigned short reverbAttenuation;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    signed char frequencyVariance;
    bool FUN_005e2d90(TESForm* other);
};
// Returns true if other is not a TESSound, any compared field differs, or FUN_00485270 reports a difference; otherwise false.
// @fnv 0x005e2d90
bool FUN_005e2d90_TESSound::FUN_005e2d90(TESForm* other)
{
    FUN_005e2d90_TESSound* sound = (FUN_005e2d90_TESSound*)dynamic_cast<TESSound*>(other);
    if (!sound)
        return true;
    if (sound->frequencyVariance != frequencyVariance)
        return true;
    for (int index = 0; index < 5; index++)
    {
        if (sound->attenuationCurve[index] != attenuationCurve[index])
            return true;
    }
    if (sound->soundFlags != soundFlags || sound->maxAttenuation != maxAttenuation ||
        sound->minAttenuation != minAttenuation || sound->frequencyAdjustment != frequencyAdjustment ||
        sound->staticAttenuation != staticAttenuation || sound->stopTime != stopTime ||
        sound->reverbAttenuation != reverbAttenuation || sound->unk5c != unk5c || sound->unk60 != unk60 ||
        sound->unk64 != unk64)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(sound))
        return true;
    return false;
}


struct FUN_005e63f0 : s5e63f0::Derived
{
    FUN_005e63f0();
};
struct FUN_005e64b0 : s5e63f0::Base
{
    float value04;
    float value08;
    FUN_005e64b0();
};
struct FUN_005e6510 : FUN_005e6510_cls
{
    FUN_005e6510();
};
struct FUN_005e6540 : s5e63f0::Base
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    FUN_005e6540();
};

// Allocates and returns a new variant object of the type indicated by n, or null for an unknown type.
// @fnv 0x005e6280
void* __cdecl FUN_005e6280(int aiType)
{
    switch (aiType)
    {
    case 1:
        return new FUN_005e63f0;
    case 2:
        return new FUN_005e64b0;
    case 3:
        return new FUN_005e6510;
    case 4:
        return new FUN_005e6540;
    default:
        return 0;
    }
}

class AnimIdle;

struct IdlePointerArrayBase
{
    ~IdlePointerArrayBase();
};

template <> class NiPointer<AnimIdle> : public IdlePointerArrayBase
{
  public:
    void* value;

    NiPointer();
};

NiPointer<AnimIdle>::NiPointer() : value(0)
{}

IdlePointerArrayBase::~IdlePointerArrayBase()
{}

// Allocates an array of NiPointer<AnimIdle> of the given count and returns it as a char pointer.
// @fnv 0x005e0ba0
char** FUN_005e0ba0(unsigned int count)
{
    return reinterpret_cast<char**>(new NiPointer<AnimIdle>[count]);
}


struct SaveManager
{
};
struct FullNameEx
{
    void* vtable;
    int unk04;
    int unk08;
};

struct ClassDataLoad5F
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct ClassLoad5F : TESForm
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FullNameEx fullName;
    unsigned int unk24;
    unsigned int unk28;
    FullNameEx alternateName;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    ClassDataLoad5F classData;
    void FUN_005f7050();
};

// Reads classData, fullName and alternateName from the save stream via SaveManager::ReadTypedData, using a length byte to gate each name read.
// @fnv 0x005f7050
void ClassLoad5F::FUN_005f7050()
{
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&classData, 0x1c);

    unsigned char present;
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&present, 1);
    if (present)
    {
        char szFullName[260];
        ::FUN_00403d30(szFullName, 0, 260);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(szFullName, present);
        reinterpret_cast<::TESFullName *>(&(fullName))->SetFullName(szFullName);
    }

    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&present, 1);
    if (present)
    {
        char szAlternateName[260];
        ::FUN_00403d30(szAlternateName, 0, 260);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(szAlternateName, present);
        reinterpret_cast<::TESFullName *>(&(alternateName))->SetFullName(szAlternateName);
    }
}

bool FUN_005e0160();

void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int count);

void FUN_005e0b60(void* p);

uintptr_t __cdecl FUN_005e0b50(void* base, int offset);

int strcpy_s(char* dst, unsigned int size, const char* src);

double __cdecl StrToD(const char* s);

enum ENUM_FORM_ID;

int strcpy_s(char* dst, unsigned int size, const char* src);

bool FUN_005e39a0();

void BSEndian(unsigned int*, EndianSizeTag<0>);

void BSEndian(unsigned short*, EndianSizeTag<0>);

struct LocalFormArray
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    LocalFormArray();
    ~LocalFormArray();
    void SetSize(unsigned int);
};

struct LocalString
{
    char* data;
    unsigned short size, capacity;
    LocalString();
    ~LocalString();
};

struct LocalState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
};

struct FUN_005ff890
{
    LocalFormArray first;
    LocalFormArray second;
    LocalString name;
    LocalState state;
    FUN_005ff890(const char*);
};

// @fnv 0x005ff890
FUN_005ff890::FUN_005ff890(const char* text)
{
    reinterpret_cast<::TextString *>(&(name))->FUN_004037f0(text, 0);
    first.SetSize(1);
    reinterpret_cast<::FUN_00600ab0_shell *>(&(first))->FUN_00600ab0(1);
    second.SetSize(1);
    reinterpret_cast<::FUN_00600ab0_shell *>(&(second))->FUN_00600ab0(1);
    memset(&state, 0, sizeof(state));
}

#include "generated/data/staging/blk_005e0000_od.inc"
