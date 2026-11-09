#include "AutoMemContext.h"

// src/staging/blk_00460000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/simple_array_item.h"
#include "fnv/tls.h"
#include <cstdint>
#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/Actor.h"
#include "fnv/decl/AttachmentHandler.h"
#include "fnv/decl/B200Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDebris_shell2.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSettingCollection.h"
#include "fnv/decl/EntryMap9A5.h"
#include "fnv/decl/ExtraListHelper.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0041b6b0_shell.h"
#include "fnv/decl/FUN_0042e150_StandIn.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00460360_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00462ea0_shell.h"
#include "fnv/decl/FUN_00462ec0_shell.h"
#include "fnv/decl/FUN_00464df0_shell.h"
#include "fnv/decl/FUN_00470650_shell.h"
#include "fnv/decl/FUN_00471130_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00471a10_shell.h"
#include "fnv/decl/FUN_00471ad0_shell.h"
#include "fnv/decl/FUN_00472150_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_00473d00_Class.h"
#include "fnv/decl/FUN_00475100_shell.h"
#include "fnv/decl/FUN_00475ab0_cls.h"
#include "fnv/decl/FUN_004778a0_cls.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00480d90_shell.h"
#include "fnv/decl/FUN_0049fa20_List.h"
#include "fnv/decl/FUN_0054de80Class.h"
#include "fnv/decl/FUN_00589f50_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c455a0_cls.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/HealthHandler.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder42.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LLD_TESHelper.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/Projectile.h"
#include "fnv/decl/Ref57b240.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_0042f730.h"
#include "fnv/decl/S_9a54a0_Class.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESObjectARMO.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TMapStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Unk0046a330.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004695a0__FUN_004695a0_t.h"
#include "fnv/decl/fnv_00471400__FUN_00471400_shell.h"
#include "fnv/decl/fnv_00472d30__FUN_00472d30_shell.h"
#include "fnv/decl/fnv_0047d680__FUN_0047d680_shell.h"
#include "fnv/decl/fnv_0047e2a0__FUN_0047e2a0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_0056fa90__Holder.h"
#include "fnv/decl/fnv_0057a3c0__FUN_0057a3c0_shell.h"
#include "fnv/decl/fnv_005857b0__FUN_005857b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008632a0__FUN_008632a0_slg.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0087b0f0__FUN_0087b0f0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040b000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00462000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00477000.h"
#include "fnv/symbols_0047b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00562000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006f9000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/WorldData.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00474000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00486000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_009ac000.h"

struct FUN_004600f0_class
{
    char pad[0x618];
    unsigned char unk618;
    unsigned char GetByteAt618();
};

// @fnv 0x004600f0
unsigned char FUN_004600f0_class::GetByteAt618()
{
    return unk618;
}

struct FUN_00460fb0_class
{
    char pad[0x178];
    char unk178;
    void* FUN_00460fb0();
};

// @fnv 0x00460fb0
void* FUN_00460fb0_class::FUN_00460fb0()
{
    return &unk178;
}

struct FUN_00460fd0_class
{
    char pad[0x170];
    char unk170;
    void* FUN_00460fd0();
};

// @fnv 0x00460fd0
void* FUN_00460fd0_class::FUN_00460fd0()
{
    return &unk170;
}

struct FUN_004610f0_Class
{
    char pad[0x70];
    char unk70;
    void* GetOffset70Ptr();
};
// @fnv 0x004610f0
void* FUN_004610f0_Class::GetOffset70Ptr()
{
    return &unk70;
}

struct FUN_00462e60_Class
{
    char pad[0x428];
    unsigned char unk428;
    void SetByteAt428(unsigned char value);
};

// @fnv 0x00462e60
void FUN_00462e60_Class::SetByteAt428(unsigned char value)
{
    unk428 = value;
}

struct FUN_00464f40_class
{
    void FUN_00470110();
    void FUN_00464f40();
};

// @fnv 0x00464f40
void FUN_00464f40_class::FUN_00464f40()
{
    FUN_00470110();
}

struct NavMesh
{
    NavMesh* FUN_00464ff0(intptr_t);
};

// @fnv 0x00464ff0
NavMesh* NavMesh::FUN_00464ff0(intptr_t a)
{
    reinterpret_cast<::Holder42 *>(this)->FUN_0042fd70((char *)(a));
    return this;
}

struct FUN_0046dcc0_class
{
    char pad[0xf4];
    unsigned char unkf4;
    void SetByteAtOffsetF4(unsigned char param);
};

// @fnv 0x0046dcc0
void FUN_0046dcc0_class::SetByteAtOffsetF4(unsigned char param)
{
    unkf4 = param;
}

struct FUN_0046dce0_class
{
    char pad[0x24];
    float unk24;
    void FUN_0046dce0(float value);
};

// @fnv 0x0046dce0
void FUN_0046dce0_class::FUN_0046dce0(float value)
{
    unk24 = value;
}


// Calls FUN_00ec825b, passing through p, a, b, c, d and e unchanged.
// @fnv 0x0046e850
void __cdecl FUN_0046e850(char* p, unsigned int a, char const* b, char const* c, char const* d, char const* e)
{
    fnv::crt::makepath_s(p, a, b, c, d, e);
}

struct FUN_0046e880_Class
{
    char pad[0x61f];
    char unk61f;
    void SetByteField(int value);
};
// @fnv 0x0046e880
void FUN_0046e880_Class::SetByteField(int value)
{
    unk61f = (char)value;
}

struct FUN_0046e8c0_class
{
    char pad[0x100];
    unsigned char unk100;
    bool FUN_0046e8c0();
};

// @fnv 0x0046e8c0
bool FUN_0046e8c0_class::FUN_0046e8c0()
{
    return unk100 & 0x20;
}

struct Arr
{
    unsigned int* GetAt(int);
};

struct FUN_0046eb00_Class
{
    char pad[0x1c];
    Arr unk1c;
    std::uintptr_t GetSecondElement();
};

// @fnv 0x0046eb00
std::uintptr_t FUN_0046eb00_Class::GetSecondElement()
{
    return *unk1c.GetAt(1);
}

namespace fnv_0046eb40 {
struct Arr
{
    unsigned int* GetAt(int);
};

struct FUN_0046eb40_Class
{
    std::uintptr_t FUN_0046eb40();
};

// @fnv 0x0046eb40
std::uintptr_t FUN_0046eb40_Class::FUN_0046eb40()
{
    return *(reinterpret_cast<Arr*>(this + 0x1c)->GetAt(3));
}
}  // namespace fnv_0046eb40

namespace fnv_0046eb60 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_0046eb60_Class
{
    std::uintptr_t FUN_0046eb60();
};
// @fnv 0x0046eb60
std::uintptr_t FUN_0046eb60_Class::FUN_0046eb60()
{
    return *(reinterpret_cast<Arr*>(this + 0x1c)->GetAt(4));
}
}  // namespace fnv_0046eb60

namespace fnv_0046eb80 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_0046eb80_Class
{
    char pad[0x1c];
    Arr unk1c;
    std::uintptr_t GetEntryAt5();
};
// @fnv 0x0046eb80
std::uintptr_t FUN_0046eb80_Class::GetEntryAt5()
{
    return *unk1c.GetAt(5);
}
}  // namespace fnv_0046eb80

namespace fnv_0046eba0 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_0046eba0_class
{
    char pad[0x1c];
    Arr m_aiIndexedValues;
    std::uintptr_t GetElementAtOffset(int a);
};
// Returns the unsigned int stored at index a + 8 of the Arr object located at this + 0x1c.
// @fnv 0x0046eba0
std::uintptr_t FUN_0046eba0_class::GetElementAtOffset(int aiIndex)
{
    return *m_aiIndexedValues.GetAt(aiIndex + 8);
}
}  // namespace fnv_0046eba0

struct FUN_0046ebf0_Class
{
    char pad[0x18];
    unsigned short unk18;
    unsigned short GetMaskedShifted(unsigned short a, unsigned short b);
};

// Returns the 16-bit field at offset 0x18 masked with a, shifted right by b.
// @fnv 0x0046ebf0
unsigned short FUN_0046ebf0_Class::GetMaskedShifted(unsigned short ausMask, unsigned short b)
{
    return (unk18 & ausMask) >> b;
}

struct FUN_0046fdf0_class
{
    int GetZero();
};

// @fnv 0x0046fdf0
int FUN_0046fdf0_class::GetZero()
{
    int result = 0;
    return result;
}

struct FUN_0046fe90_Class
{
    bool HasFlag(signed char flag);
};

// @fnv 0x0046fe90
bool FUN_0046fe90_Class::HasFlag(signed char flag)
{
    return (reinterpret_cast<const signed char*>(this)[0] & flag) != 0;
}

extern int DAT_01019a1c;
struct FUN_00470040_class
{
    void* m_vft;
    void FUN_004704e0(int a, int b);
    FUN_00470040_class(int a, int b);
};
extern int DAT_01019a2c;
struct FUN_004700a0
{
    void* vtbl;
    void FUN_00470550(int a, int b);
    FUN_004700a0(int a, int b);
};
// Calls FUN_00470550 with the two arguments, then sets the object's vtbl to DAT_01019a2c.
// @fnv 0x004700a0
FUN_004700a0::FUN_004700a0(int aiFirst, int aiSecond)
{
    FUN_00470550(aiFirst, aiSecond);
    vtbl = &DAT_01019a2c;
}


struct FUN_004705c0_cls
{
    void* FUN_004705c0();
};

// @fnv 0x004705c0
void* FUN_004705c0_cls::FUN_004705c0()
{
    return FUN_006f99e0(this + 8);
}

struct FUN_00471110_Class
{
    char pad[0x3dc];
    float unk3dc;
    void SetField3DC(float value);
};

// @fnv 0x00471110
void FUN_00471110_Class::SetField3DC(float value)
{
    unk3dc = value;
}

struct FUN_00471de0_class
{
    char pad[0x3e8];
    int unk3e8;
    bool FUN_00471de0();
};

// @fnv 0x00471de0
bool FUN_00471de0_class::FUN_00471de0()
{
    if (unk3e8 & 0x40)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct P03MM
{
};
// @fnv 0x00474460
void* __cdecl AllocateProduct(unsigned int auiUnused, unsigned int b, unsigned int c, unsigned int auiUnused2)
{
    return reinterpret_cast<::MemoryManagerStandIn *>((((::P03MM *)(::FUN_00401020()))))->FUN_00aa3e40(b * c);
}

namespace fnv_00474480 {
struct MemoryManager
{
};
// @fnv 0x00474480
void __cdecl FUN_00474480(void* apUnused, void* apBlock)
{
    reinterpret_cast<::FNV_MemoryManager *>((((::fnv_00474480::MemoryManager *)(::FUN_00401020()))))->FUN_00aa4060(apBlock);
}
}  // namespace fnv_00474480

struct ActorCombatGroup;

struct NiTMallocInterface_StandIn
{
};

struct FUN_00474760_This
{
    const char* p;
    ActorCombatGroup* q;
    void FUN_00474760();
};

// @fnv 0x00474760
void FUN_00474760_This::FUN_00474760()
{
    p = " HG";
    ::FUN_004ede70(q);
}

extern "C" void* DAT_0101a3b8;
struct BFC_s
{
    BFC_s();
};
struct FUN_008c6060_shell
{
    void FUN_008c6060();
};
struct FUN_004748f0 : BFC_s
{
    void* vtbl;
    FUN_004748f0();
};
// Sets the vtable pointer to DAT_0101a3b8 and then calls FUN_008c6060 on this object.
// @fnv 0x004748f0
FUN_004748f0::FUN_004748f0()
{
    vtbl = &DAT_0101a3b8;
    ((FUN_008c6060_shell*)this)->FUN_008c6060();
}

namespace fnv_004750b0 {
extern "C" void* DAT_0101a644;

struct BFC_s
{
    BFC_s();
};

struct FUN_00475100_shell
{
};

struct FUN_004750b0 : BFC_s
{
    FUN_004750b0();
};

// Sets the object's vtable pointer to DAT_0101a644, then calls SetClipRounds on this object.
// @fnv 0x004750b0
FUN_004750b0::FUN_004750b0()
{
    *reinterpret_cast<void**>(this) = &DAT_0101a644;
    reinterpret_cast<::FUN_00475100_shell *>((reinterpret_cast<FUN_00475100_shell*>(this)))->SetClipRounds();
}
}  // namespace fnv_004750b0

struct FUN_00475a90_cls
{
    char pad[0x2];
    unsigned char unk02;
    bool IsFlag2Set();
};

// @fnv 0x00475a90
bool FUN_00475a90_cls::IsFlag2Set()
{
    return unk02 & 2;
}

struct FUN_00476a00_cls
{
    char pad[0x2];
    unsigned char unk02;
    bool FUN_00476a00();
};

// @fnv 0x00476a00
bool FUN_00476a00_cls::FUN_00476a00()
{
    return (unk02 & 1) ? true : false;
}

struct FUN_00476a20_Class
{
    char pad[0x2];
    unsigned char unk02;
    bool IsFlag4Set();
};

// @fnv 0x00476a20
bool FUN_00476a20_Class::IsFlag4Set()
{
    return unk02 & 4;
}

struct FUN_00476ae0_class
{
    void FUN_00476ae0(bool a);
    void SetTaskFlag(bool a);
};

struct TaskQueueInterface
{
    void SetTaskFlag(bool enabled);
public:
    static void CopyStringToBuffer(char *, unsigned int, const char *);
public:
    static ::TaskQueueInterface *GetSingleton();
};
// @fnv 0x00476ae0
void FUN_00476ae0_class::FUN_00476ae0(bool abEnabled)
{
    reinterpret_cast<::TaskQueueInterface *>(this)->SetTaskFlag(abEnabled);
}
// @fnv 0x00476b00
void TaskQueueInterface::SetTaskFlag(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x4000);
}

#include "bscore/bsrandom.h"


// @fnv 0x00476be0
unsigned int MersenneTwister::FUN_00476be0()
{
    return GetRandomUInt(0xffffffff);
}

struct FUN_00476c70_Class
{
    char pad[0xe0];
    intptr_t unke0;
    void FUN_00476c70(intptr_t value);
};

// @fnv 0x00476c70
void FUN_00476c70_Class::FUN_00476c70(intptr_t value)
{
    unke0 = value;
}

struct FUN_00476c90_Class
{
    char pad[0xf8];
    unsigned int unkf8;
    uintptr_t FUN_00476c90();
};
// @fnv 0x00476c90
uintptr_t FUN_00476c90_Class::FUN_00476c90()
{
    return unkf8;
}

struct FUN_004791f0_holder
{
};
extern int DAT_0101a8fc;

struct FUN_00479190_holder
{
    void* m_iWordAt00;
    FUN_00479190_holder* Construct(int a);
};

struct FUN_00573eb0_Class
{
    int FUN_0047b4b0();
};

struct FUN_0047b4d0_Class
{
    char pad[0xc];
    unsigned short unk0c;
    bool FUN_0047b4d0(unsigned short flags);
};
// @fnv 0x0047b4b0
int FUN_00573eb0_Class::FUN_0047b4b0()
{
    return ((int)(reinterpret_cast<::FUN_0047b4d0_Class *>(this)->FUN_0047b4d0(0x40)));
}

// Returns true if the flags stored at offset 0xc on this object contain any of the given flags.
// @fnv 0x0047b4d0
bool FUN_0047b4d0_Class::FUN_0047b4d0(unsigned short flags)
{
    return (unk0c & flags) != 0;
}

struct S47
{
    char pad[0x18];
    short unk18;
    void FUN_0047dea0(short);
};

// Stores p at offset 0x18 of this and calls FUN_0047e2a0 with 2.
// @fnv 0x0047dea0
void S47::FUN_0047dea0(short asValue)
{
    unk18 = asValue;
    reinterpret_cast<::fnv_0047e2a0::FUN_0047e2a0_shell *>(this)->FUN_0047e2a0(2);
}

struct FUN_0047ebb0_Class
{
    void FUN_0047ebb0(int value);
};

// @fnv 0x0047ebb0
void FUN_0047ebb0_Class::FUN_0047ebb0(int value)
{
    reinterpret_cast<::Holder *>(this)->FUN_005fc970(0x40, (char)value);
}

struct FUN_0047ebd0_Class
{
    void FUN_0047ebd0(bool value);
};

// @fnv 0x0047ebd0
void FUN_0047ebd0_Class::FUN_0047ebd0(bool value)
{
    reinterpret_cast<::Holder *>(this)->FUN_005fc970(0x20, value);
}

struct FUN_0047ff50_class
{
    char pad[0x4];
    unsigned short unk04;
    void FUN_0047ff50(unsigned short value);
};

// @fnv 0x0047ff50
void FUN_0047ff50_class::FUN_0047ff50(unsigned short value)
{
    unk04 = value;
}

extern void* DAT_0101a364;

struct FUN_00474630 : public NiTPointerMap<int, int>
{
    void FUN_00474631();
};

// Sets the vtable pointer, removes all entries from the map, and frees the pointer stored at offset 8.
// @fnv 0x00474630
void FUN_00474630::FUN_00474631()
{
    *(void**)this = &DAT_0101a364;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

namespace fnv_00474730 {

struct FUN_00474730_Map
{
    void* m_vtbl;
    void* m_data;
    void* m_ptr;
    void RemoveAll();
    void FUN_00474730();
};

// Sets the vtable pointer, removes all entries, and frees the m_ptr allocation.
// @fnv 0x00474730
void FUN_00474730_Map::FUN_00474730()
{
    m_vtbl = &(*reinterpret_cast<void * *>(&::DAT_0101a384));
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(m_ptr);
}
}  // namespace fnv_00474730

extern int DAT_0101a91c;

struct FUN_004792c0_Class : NiTPointerMap<int, int>
{
    void FUN_004792c0();
};

// @fnv 0x004792c0
void FUN_004792c0_Class::FUN_004792c0()
{
    *(void**)this = (void*)&DAT_0101a91c;
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

struct FUN_0045d930_class
{
    void* vtbl;
    void** unk04;
    void FUN_0046ffd0();
    void* FUN_00470320(unsigned int flags);
public:
    void FUN_0045d930();
};

// Calls FUN_0046ffd0, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00470320
void* FUN_0045d930_class::FUN_00470320(unsigned int flags)
{
    FUN_0046ffd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00470350 {
struct FUN_0045d930_class
{
    void* FUN_00470350(unsigned int flags);
};
// @fnv 0x00470350
void* FUN_0045d930_class::FUN_00470350(unsigned int flags)
{
    reinterpret_cast<::FUN_0045d930_class *>(this)->FUN_0045d930();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00470350

struct FUN_0045d950_Class
{
    void* vtbl;
    ActorCombatGroup* unk04;
    void FUN_00470070();
    void* FUN_00470380(unsigned int flags);
public:
    void FUN_0045d950();
};

// Calls FUN_00470070, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00470380
void* FUN_0045d950_Class::FUN_00470380(unsigned int flags)
{
    FUN_00470070();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_004703b0 {
struct FUN_0045d950_Class
{
};
struct FUN_004703b0_Class : FUN_0045d950_Class
{
    void* FUN_004703b0(unsigned int flags);
};
// Calls the base class cleanup, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x004703b0
void* FUN_004703b0_Class::FUN_004703b0(unsigned int flags)
{
    reinterpret_cast<::FUN_0045d950_Class *>(this)->FUN_0045d950();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_004703b0

struct FUN_004703e0_class : public FUN_00464f40_class
{
    void* FUN_004703e0(unsigned int flags);
};
// Calls FUN_00470110, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004703e0
void* FUN_004703e0_class::FUN_004703e0(unsigned int flags)
{
    FUN_00470110();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00470410_class : public FUN_00464f40_class
{
    void* FUN_00470410(unsigned int flags);
};
// @fnv 0x00470410
void* FUN_00470410_class::FUN_00470410(unsigned int flags)
{
    FUN_00464f40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004746d0_Class
{
    void FUN_004746d0();
    void* FUN_00474530(unsigned int flags);
};

struct FUN_004747c0_Class : public FUN_00474630
{
    void* FUN_004747c0(unsigned int flags);
};

// Calls FUN_00474631, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x004747c0
void* FUN_004747c0_Class::FUN_004747c0(unsigned int flags)
{
    FUN_00474631();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_00474730();
struct FUN_004747f0_class
{
    void FUN_00474730();
    void* FUN_004747f0(unsigned int flags);
};
// Calls FUN_00474730, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004747f0
void* FUN_004747f0_class::FUN_004747f0(unsigned int flags)
{
    reinterpret_cast<::fnv_00474730::FUN_00474730_Map *>(this)->FUN_00474730();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00473f00_class
{
    void ForwardToHolder();
};
struct FUN_00474850_class : public FUN_00473f00_class
{
    void* FUN_00474850(unsigned int flags);
};
// @fnv 0x00474850
void* FUN_00474850_class::FUN_00474850(unsigned int flags)
{
    ForwardToHolder();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004752e0_Class
{
    void* FUN_004752e0(unsigned int flags);
};

struct FUN_00479140_class
{
    void FUN_00479140();
};
struct FUN_00479160_class
{
    void* FUN_00479160(unsigned int flags);
};
// @fnv 0x00479160
void* FUN_00479160_class::FUN_00479160(unsigned int flags)
{
    ((FUN_00479140_class*)this)->FUN_00479140();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004792f0_Class : FUN_004792c0_Class
{
    void* FUN_004792f0(unsigned int flags);
};

// @fnv 0x004792f0
void* FUN_004792f0_Class::FUN_004792f0(unsigned int flags)
{
    FUN_004792c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BGSImpactDataSet
{
    static BGSImpactDataSet* ms_pImpactDataSet;
};
BGSImpactDataSet* BGSImpactDataSet::ms_pImpactDataSet;

// @fnv 0x00460160
void FUN_00460160()
{
    BGSImpactDataSet::ms_pImpactDataSet = 0;
}

struct BGSEncounterZone
{
};
// @fnv 0x00460190
void __cdecl FUN_00460190()
{
    ::DAT_011c9520 = 0;
}

template <int N> struct EndianSizeTag
{
};
#include "fnv/decl/S_00462230.h"


struct FUN_00462480_Class
{
    unsigned char FUN_00462480();
};
// Returns true when bit 0 of the thread flags is clear.
// @fnv 0x00462480
unsigned char FUN_00462480_Class::FUN_00462480()
{
    return (::g_tlsBlock.threadFlags & 1) == 0;
}

struct S69570
{
    unsigned char FUN_00469570();
};
// @fnv 0x00469570
unsigned char S69570::FUN_00469570()
{
    return (::g_tlsBlock.threadFlags & 2) != 0;
}

struct KFModel
{
};
struct FUN_0046e8e0_This
{
    void FUN_0046e8e0(KFModel* a, int b, int c, int d, int e);
};
// @fnv 0x0046e8e0
void FUN_0046e8e0_This::FUN_0046e8e0(KFModel* a, int b, int c, int d, int e)
{
    void* v;
    if (a)
    {
        v = ((void *)(::FUN_00653270((const ::NiRTTI *)((*reinterpret_cast<const char (*)[]>(&::g_011f444c))), (::NiObject *)(void *)(((void *)(reinterpret_cast<::TESRegionDataMap *>((a))->GetRegionMapName()))))));
    }
}

extern int DAT_01019a14;
// @fnv 0x0046ffd0
template <> struct NiTMallocInterface<void*>
{
};
void FUN_0045d930_class::FUN_0046ffd0()
{
    vtbl = (void*)&DAT_01019a14;
    ::FUN_004ede70(unk04);
}

struct FUN_004700d0_Node
{
    char pad[8];
    int unk08;
};
struct FUN_004700d0_class : FUN_004705c0_cls
{
    void FUN_004700d0(int* p);
};
// Calls FUN_004705c0 to get an object, stores *p at offset 8, then passes it to FUN_0049fa20.
// @fnv 0x004700d0
void FUN_004700d0_class::FUN_004700d0(int* piValue)
{
    void* v = ((FUN_004705c0_cls*)this)->FUN_004705c0();
    static_cast<FUN_004700d0_Node*>(v)->unk08 = *piValue;
    reinterpret_cast<::FUN_0049fa20_List *>((this))->FUN_0049fa20((::FUN_0049fa20_Node *)(v));
}

struct FUN_00471d90_class
{
    char m_auiShapeKeys[0x3e8];
    int m_flags;
    void FUN_00471d90(bool enabled);
};

// @fnv 0x00471d90
void FUN_00471d90_class::FUN_00471d90(bool enabled)
{
    if (enabled)
        m_flags |= 8;
    else
        m_flags &= ~8;
}

struct FUN_00471e10_class
{
    char pad[0x3e8];
    unsigned int unk3e8;
    void SetFlag40(bool set);
};
// @fnv 0x00471e10
void FUN_00471e10_class::SetFlag40(bool set)
{
    if (set)
        unk3e8 |= 0x40;
    else
        unk3e8 &= ~0x40;
}


struct BSFile
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Seek(int, int);
    unsigned int Read(void*, unsigned int);
public:
    bool Write();
};
struct MyForm
{
    unsigned int uiID;
    char _rest[0x14];
};
struct Twin_008d0360
{
    bool GetBooleanValue();
};
Twin_008d0360* FUN_00471f70();

struct FUN_00471e60_shell
{
    char _pad0[0x10];
    BSFile* pFile;
    char _pad14[0x22c];
    MyForm kForm;
    char _pad258[0x41];
    bool bFlag;
    void LoadFormAndUpdateFlag();
};

// @fnv 0x00471e60
void FUN_00471e60_shell::LoadFormAndUpdateFlag()
{
    if (!pFile)
        return;
    pFile->Seek(0, DAT_010a2480);
    ::FUN_00403d30(&kForm, 0, 0x18);
    if (!pFile->Read(&kForm, 0x18))
        return;
    if (kForm.uiID == DAT_01187014)
    {
        reinterpret_cast<::FUN_00471e10_class *>(this)->SetFlag40(FUN_00471f70()->GetBooleanValue());
    }
    else
    {
        reinterpret_cast<::FUN_00470650_shell *>(&(kForm))->FUN_00470650();
        if (kForm.uiID == DAT_01187014)
            reinterpret_cast<::FUN_00471e10_class *>(this)->SetFlag40(!FUN_00471f70()->GetBooleanValue());
    }
    bFlag = false;
    if (((FUN_00471de0_class*)this)->FUN_00471de0() ^ FUN_00471f70()->GetBooleanValue())
        bFlag = true;
}

struct FUN_00474500_Class
{
    void FUN_004745d0();
    void* FUN_00474500(unsigned int flags);
};
namespace fnv_00474560 {
struct FUN_00474560_class
{
    void* vtbl;
    unsigned int m_iElementCount;
    void* m_data;
    unsigned int m_uiItemCount;
    FUN_00474560_class(unsigned int size);
};
// Sets the vtable, stores size and zeroes a newly allocated buffer of size*4 bytes.
// @fnv 0x00474560
FUN_00474560_class::FUN_00474560_class(unsigned int size)
{
    vtbl = &DAT_0101a364;
    m_iElementCount = size;
    m_uiItemCount = 0;
    unsigned int n = m_iElementCount << 2;
    m_data = ::FUN_00aa1070(n);
    ::FUN_00403d30(m_data, 0, m_iElementCount << 2);
}
}  // namespace fnv_00474560

struct FUN_00474660_class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00474660_class(int n);
};
// Sets the vtable, stores n in count, allocates count*4 bytes for data and zeroes them.
// @fnv 0x00474660
FUN_00474660_class::FUN_00474660_class(int aiCount)
{
    vtbl = &DAT_0101a384;
    count = aiCount;
    pad = 0;
    int size = count * 4;
    data = ::FUN_00aa1070(size);
    ::FUN_00403d30(data, 0, count * 4);
}

struct FUN_00474880_Helper
{
    void FUN_00474880(unsigned int a, unsigned int b);
};
struct FUN_00474790_Class
{
    const char* m0;
    FUN_00474790_Class* FUN_00474790(unsigned int a, unsigned int b);
};
// Calls FUN_00474880 with the two arguments, sets m0 to "PHG", and returns this.
// @fnv 0x00474790
FUN_00474790_Class* FUN_00474790_Class::FUN_00474790(unsigned int a, unsigned int b)
{
    ((FUN_00474880_Helper*)this)->FUN_00474880(a, b);
    m0 = "PHG";
    return this;
}

struct FUN_00474820_Class
{
    void* FUN_00474820(unsigned int);
};
// Calls FUN_00474760 on this, then frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00474820
void* FUN_00474820_Class::FUN_00474820(unsigned int flags)
{
    ((FUN_00474760_This*)this)->FUN_00474760();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESForm
{
    unsigned int GetFormType();
public:
    bool GetDisabled() const;
public:
    void MarkForDeletion(bool);
public:
    void SetDestroyed(bool);
    virtual ~TESForm();
    ::ENUM_FORM_ID GetFormType() const;
};
struct FUN_00474a00_shell
{
    void* p;
    void* q;
    void* GetAmmoForm();
};
// Returns q if it is non-null and its form type is 0x29, otherwise returns null.
// @fnv 0x00474a00
void* FUN_00474a00_shell::GetAmmoForm()
{
    return q && reinterpret_cast<TESForm*>(q)->GetFormType() == 0x29 ? q : 0;
}

namespace fnv_00474a40 {
struct TESForm
{
    unsigned int vtbl;
    unsigned int formID;
    int FNV_GetFormType();
};
struct FUN_00474a40_shell
{
    unsigned int vtbl;
    TESForm* form;
    TESForm* FUN_00474a40();
};
// Returns form if it is non-null and its FNV_GetFormType() equals 0x55, otherwise returns null.
// @fnv 0x00474a40
TESForm* FUN_00474a40_shell::FUN_00474a40()
{
    return form && form->FNV_GetFormType() == 0x55 ? form : 0;
}
}  // namespace fnv_00474a40

struct QueueObj
{
    QueueObj(int);
};
struct S751
{
    int unk00;
    unsigned char unk04;
    unsigned char unk05;
    char pad06[0x2];
    int unk08;
    int unk0c;
    QueueObj unk10;
    S751* Initialize();
};
// Zeroes the object's fields at offsets 0, 4, 5, 8 and 12, constructs the QueueObj at offset 16 with 0, and returns this.
// @fnv 0x004751d0
S751* S751::Initialize()
{
    unk00 = 0;
    unk04 = 0;
    unk05 = 0;
    unk08 = 0;
    unk0c = 0;
    reinterpret_cast<::S_0042f730 *>((&unk10))->FUN_00528cb0((::AC_0042f730 *)(0));
    return this;
}

struct FUN_00476a40_Data
{
    int _00;
    unsigned char count;
    unsigned char _pad[3];
    void** items;
};
struct FUN_00476a40_Holder
{
    int _00;
    FUN_00476a40_Data* data;
    void* FUN_00476a40(unsigned int index);
};
// Returns the item at index from data->items when data is non-null and index is below data->count, otherwise returns 0.
// @fnv 0x00476a40
void* FUN_00476a40_Holder::FUN_00476a40(unsigned int index)
{
    if (data != 0 && index < data->count)
        return data->items[index];
    else
        return 0;
}

struct FUN_004781b0_This
{
    int field0;
    unsigned char field4;
    unsigned char field5;
    FUN_004781b0_This* FUN_004781b0();
};
// Sets field0, field4 and field5 to zero and returns this.
// @fnv 0x004781b0
FUN_004781b0_This* FUN_004781b0_This::FUN_004781b0()
{
    field0 = 0;
    field4 = 0;
    field5 = 0;
    return this;
}

struct FUN_00478f70_s
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
    unsigned int d10;
    unsigned int d14;
    FUN_00478f70_s* FUN_00478f70();
};

// Zeroes all fields of the object and returns this.
// @fnv 0x00478f70
FUN_00478f70_s* FUN_00478f70_s::FUN_00478f70()
{
    b0 = 0;
    b1 = 0;
    b2 = 0;
    d4 = 0;
    d8 = 0;
    dc = 0;
    d10 = 0;
    d14 = 0;
    return this;
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
extern int vftable__ShadowSceneArray;
struct S
{
    void* vf;
    S* ConstructShadowSceneArray();
};
// Sets the vtable to vftable__ShadowSceneArray, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00479110
S* S::ConstructShadowSceneArray()
{
    vf = (void*)&vftable__ShadowSceneArray;
    ((AX*)this)->FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_004791f0_holder2
{
    void* m_pVtbl;
    int m_iCount;
    void* m_pData;
    int m_iUnk0c;
    void* InitArrayHolder(int a);
};
// @fnv 0x00479190
FUN_00479190_holder* FUN_00479190_holder::Construct(int a)
{
    reinterpret_cast<::FUN_004791f0_holder2 *>((((FUN_004791f0_holder*)this)))->InitArrayHolder(a);
    m_iWordAt00 = &DAT_0101a8fc;
    return this;
}
// Sets the vtable, stores the element count, allocates count*4 zeroed bytes and stores the pointer at offset 8.
// @fnv 0x004791f0
void* FUN_004791f0_holder2::InitArrayHolder(int aiCount)
{
    m_pVtbl = &DAT_0101a91c;
    m_iCount = aiCount;
    m_iUnk0c = 0;
    unsigned int uiSize = m_iCount << 2;
    m_pData = ::FUN_00aa1070(uiSize);
    ::FUN_00403d30(m_pData, 0, m_iCount << 2);
    return this;
}

struct FUN_0047b470_This
{
    char pad[0xc];
    unsigned short unk0c;
    bool FUN_0047b470();
};
// Returns true when bit 0x20 is set in the word at offset 0xc and the result of FUN_0047b4b0 is zero.
// @fnv 0x0047b470
bool FUN_0047b470_This::FUN_0047b470()
{
    return (((unk0c & 0x20) != 0) &&
            ((unsigned char)((FUN_00573eb0_Class*)this)->FUN_0047b4b0() == 0));
}

struct Actor;
struct LH
{
    bool IsInList(Actor*&);
};
struct ScriptS
{
};
struct FUN_0047ba80_This
{
    int _0;
    ScriptS* m4;
    bool IsActorInList(Actor* actor);
};
// Returns true if m4 is set and its header reports actor as being in the list; otherwise returns false.
// @fnv 0x0047ba80
bool FUN_0047ba80_This::IsActorInList(Actor* actor)
{
    bool flag = false;
    if (m4 != 0)
        flag = reinterpret_cast<::RefList *>((((::LH *)(reinterpret_cast<::BGSCameraPath *>((m4))->GetConditions()))))->FUN_005f65d0((void **)&(actor));
    return flag;
}

struct FUN_0046fe10_Class
{
    int FUN_0046fe10();
};
// @fnv 0x0046fe10
int FUN_0046fe10_Class::FUN_0046fe10()
{
    int count = 0;
    if (((FUN_0046fe90_Class*)this)->HasFlag(1))
        ++count;
    if (((FUN_0046fe90_Class*)this)->HasFlag(2))
        ++count;
    if (((FUN_0046fe90_Class*)this)->HasFlag(4))
        ++count;
    if (((FUN_0046fe90_Class*)this)->HasFlag(8))
        ++count;
    return count;
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
    BSSimpleList<TESForm*>* GetNext();
};
struct TESObject
{
    unsigned int GetNext();
};
struct FUN_00474a00
{
};
struct FUN_00474a40
{
};
struct FUN_00474920_shell
{
    TESForm* GetFormOrScriptForm();
};
// Returns GetForm() if present, otherwise a TESForm from the script's header list at index GetNext(), or the header's first item when the index is out of range.
// @fnv 0x00474920
TESForm* FUN_00474920_shell::GetFormOrScriptForm()
{
    TESForm* result = 0;
    if (((::TESForm *)(reinterpret_cast<::FUN_00474a00_shell *>((((FUN_00474a00*)this)))->GetAmmoForm())))
        result = ((::TESForm *)(reinterpret_cast<::FUN_00474a00_shell *>((((FUN_00474a00*)this)))->GetAmmoForm()));
    else if (((::ScriptS *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>((((FUN_00474a40*)this)))->FUN_00474a40())))
    {
        unsigned int count = ((unsigned int)(uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)((::ScriptS *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>((((FUN_00474a40*)this)))->FUN_00474a40())))))->FUN_007af430()));
        if (((BSSimpleListTESRaceSize*)((::LH *)(reinterpret_cast<::BGSCameraPath *>((((::ScriptS *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>((((FUN_00474a40*)this)))->FUN_00474a40()))))->GetConditions())))->GetSize() > count)
        {
            BSSimpleList<TESForm*>* node = (BSSimpleList<TESForm*>*)((::LH *)(reinterpret_cast<::BGSCameraPath *>((((::ScriptS *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>((((FUN_00474a40*)this)))->FUN_00474a40()))))->GetConditions()));
            for (unsigned int i = 0; i < count; ++i)
                node = ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            result = ((::TESForm *)(new ((void *)(node)) ::Vec3()));
        }
        else
        {
            result = ((::TESForm *)(new ((void *)(((BSSimpleList<TESForm*>*)((::LH *)(reinterpret_cast<::BGSCameraPath *>((((::ScriptS *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>((((FUN_00474a40*)this)))->FUN_00474a40()))))->GetConditions()))))) ::Vec3()));
        }
    }
    return result;
}

struct GlobalObject_00a7b610;
struct NiAVObject;
struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};
struct FUN_00476ec0_Class
{
};
struct NiObject
{
    virtual ~NiObject();
    virtual void v1();
    virtual void v2();
    virtual NiNode* GetAsNode();
};
void __cdecl FUN_00476ec0(NiAVObject*, int);
// If object is non-null and passes FUN_0043b300, calls FUN_00c455a0 with flag, then recurses over all children of its node.
// @fnv 0x00476ec0
void __cdecl FUN_00476ec0(NiAVObject* object, int flag)
{
    if (!object)
        return;
    if (::FUN_0043b300((const ::NiRTTI *)(::GlobalObject_00a7b610 *)(&::g_01202e8c), object))
    {
        FUN_00476ec0_Class* p = (FUN_00476ec0_Class*)object;
        reinterpret_cast<::FUN_00c455a0_cls *>((p))->FUN_00c455a0((unsigned char)flag);
    }
    NiNode* node = ((NiObject*)object)->GetAsNode();
    if (node)
        for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
            FUN_00476ec0(node->GetAt(i), flag);
}

struct FUN_00478130_class
{
    char pad[0x4];
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00478130();
};
// Applies BSEndian to the four fields at offsets 4, 8, 12 and 16 of this object.
// @fnv 0x00478130
void FUN_00478130_class::FUN_00478130()
{
    ::FUN_00401080(&unk04);
    ::FUN_00401080(&unk08);
    ::FUN_00401080(&unk0c);
    ::FUN_00401080(&unk10);
}

struct FUN_00462e10_Class
{
    signed char m_flags;
    void SetFlags(signed char mask, bool set);
};
// Sets or clears the bits of m_flags selected by mask, according to set.
// @fnv 0x00462e10
void FUN_00462e10_Class::SetFlags(signed char mask, bool set)
{
    set ? m_flags |= mask : m_flags &= ~mask;
}

struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_004704e0
{
    void* vtbl;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short c;
    unsigned short d;
    unsigned short f;
    FUN_004704e0(unsigned short x, unsigned short y);
};
// Calls FUN_004704e0 with the two arguments, then sets m_vft to the address of DAT_01019a1c.
// @fnv 0x00470040
FUN_00470040_class::FUN_00470040_class(int aiFirst, int aiSecond)
{
    new ((void *)this) ::FUN_004704e0(aiFirst, aiSecond);
    m_vft = &DAT_01019a1c;
}
// Sets the vtable, stores x and y, zeroes c and d, and allocates a buffer of x elements (or null when x is 0).
// @fnv 0x004704e0
FUN_004704e0::FUN_004704e0(unsigned short ausCount, unsigned short y)
{
    vtbl = &DAT_01019a14;
    a = ausCount;
    f = y;
    c = 0;
    d = 0;
    if (a > 0)
        p = NiTMallocInterface_0096afc0::Allocate(a);
    else
        p = 0;
}

namespace fnv_00470550 {
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_00470550_t
{
    void* vtbl;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    FUN_00470550_t(unsigned short x, unsigned short y);
};
// @fnv 0x00470550
FUN_00470550_t::FUN_00470550_t(unsigned short ausCapacity, unsigned short y)
{
    vtbl = &::DAT_01019a24;
    a = ausCapacity;
    d = y;
    b = 0;
    c = 0;
    if (a > 0)
        p = NiTMallocInterface_0096afc0::Allocate(a);
    else
        p = 0;
}
}  // namespace fnv_00470550

namespace fnv_00474880 {
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
void* $SG6264;
struct FUN_00474880
{
    void* vtbl;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    FUN_00474880(unsigned short x, unsigned short y);
};
// @fnv 0x00474880
FUN_00474880::FUN_00474880(unsigned short x, unsigned short y)
{
    vtbl = &$SG6264;
    a = x;
    d = y;
    b = 0;
    c = 0;
    if (a > 0)
        p = NiTMallocInterface_0096afc0::Allocate(a);
    else
        p = 0;
}
}  // namespace fnv_00474880

struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    char d[0x20];
};
struct FUN_00478570_holder
{
    char m_iWordAt00[0x14];
    B2_4fe* m_cByteAtOffset1;
    void EnsureB2_4fe();
};
// @fnv 0x00478570
void FUN_00478570_holder::EnsureB2_4fe()
{
    if (!m_cByteAtOffset1)
        m_cByteAtOffset1 = new B2_4fe;
}

struct FUN_0047bac0_NPC : TESForm
{
    unsigned char m_npc[0x15c];
    void* biped;
};
struct FUN_0047bac0_ARMO : TESForm
{
    unsigned char m_armor[0xbc];
    void* biped;
};
// Returns a pointer to the biped field of the given form if it is armor (type 0x28) or an NPC (type 0x18), otherwise null.
// @fnv 0x0047bac0
void* GetBipedPointer(TESForm* form)
{
    void* result = 0;
    if (form)
    {
        switch (form->GetFormType())
        {
        case 0x28: {
            FUN_0047bac0_ARMO* armor = static_cast<FUN_0047bac0_ARMO*>(form);
            result = armor ? &armor->biped : 0;
            break;
        }
        case 0x18: {
            FUN_0047bac0_NPC* npc = static_cast<FUN_0047bac0_NPC*>(form);
            result = npc ? &npc->biped : 0;
            break;
        }
        }
    }
    return result;
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct TESAttackDamageForm : public BaseFormComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned short GetDamage();
    void FUN_0047fe30(BaseFormComponent* apCopyFC);
};
// Casts apCopyFC to TESAttackDamageForm and, if the cast succeeds, copies its damage value via FUN_0047ff50.
// @fnv 0x0047fe30
void TESAttackDamageForm::FUN_0047fe30(BaseFormComponent* apCopyFC)
{
    TESAttackDamageForm* pCopy = dynamic_cast<TESAttackDamageForm*>(apCopyFC);
    if (!pCopy)
        return;
    reinterpret_cast<::FUN_0047ff50_class *>(this)->FUN_0047ff50(pCopy->GetDamage());
}

struct FUN_0046eb20_Class
{
    std::uintptr_t GetElementAt2();
};
// @fnv 0x0046eb20
std::uintptr_t FUN_0046eb20_Class::GetElementAt2()
{
    return *reinterpret_cast<Arr*>(this + 0x1c)->GetAt(2);
}

struct FUN_0046ebd0_Class
{
    unsigned int FUN_0046ebd0();
};

// @fnv 0x0046ebd0
unsigned int FUN_0046ebd0_Class::FUN_0046ebd0()
{
    return (unsigned int)(unsigned short)reinterpret_cast<FUN_0046ebf0_Class*>(this)->GetMaskedShifted(0xff0, 4);
}

struct FUN_0046fdd0_Class
{
    char m_iWordAt00[0x38];
    int m_38;
    char IsFieldEqual(int param_2);
};
// @fnv 0x0046fdd0
char FUN_0046fdd0_Class::IsFieldEqual(int aiValue)
{
    return m_38 == aiValue;
}


// @fnv 0x00470070
void FUN_0045d950_Class::FUN_00470070()
{
    vtbl = &DAT_01019a24;
    ::FUN_004ede70(unk04);
}

struct Date
{
    virtual ~Date();
    virtual int v0();
};
struct FUN_004750e0 : Date
{
    ~FUN_004750e0();
};
// @fnv 0x004750e0
FUN_004750e0::~FUN_004750e0()
{}

struct BSSimpleArrayActor
{
    void Clear(bool);
};

// @fnv 0x00479140
void FUN_00479140_class::FUN_00479140()
{
    *(void**)this = &vftable__ShadowSceneArray;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArrayActor*)this)))->Clear(true);
}

struct FUN_0047bcf0_class
{
    char pad[0x100];
    unsigned char unk100;
    bool IsFlag80Clear();
};

// @fnv 0x0047bcf0
bool FUN_0047bcf0_class::IsFlag80Clear()
{
    return (unk100 & 0x80) ? false : true;
}

struct FUN_0047eb90_Class
{
    void FUN_0047eb90(int value);
};
// @fnv 0x0047eb90
void FUN_0047eb90_Class::FUN_0047eb90(int value)
{
    reinterpret_cast<::Holder *>(this)->FUN_005fc970(0x10, (char)value);
}

class FUN_00462dc0_cls
{
  public:
    int m_00;
    int m_04;
    int(__cdecl* m_08)(FUN_00462dc0_cls* self, int a, int b, int c, int d);
    int InvokeAndAccumulate(std::intptr_t a1, int a2, int a3, int a4);
};

// Calls the callback stored in m_08 with the four arguments, adds its return value to m_04, and returns that value.
// @fnv 0x00462dc0
int FUN_00462dc0_cls::InvokeAndAccumulate(std::intptr_t a1, int a2, int a3, int a4)
{
    int result = this->m_08(this, a1, a2, a3, a4);
    this->m_04 += result;
    return result;
}

// FUN_00464f30 : an identity function.  The module is an /Od build, so even
// this keeps the full frame: push ebp / mov ebp,esp / mov eax,[ebp+8] / pop ebp / ret.
// @fnv 0x00464f30
std::intptr_t __cdecl FUN_00464f30(std::intptr_t a)
{
    return a;
}

extern int DAT_01019a34;
extern void* __cdecl FUN_0096afc0(unsigned int count);
struct ResourceDescriptor
{
    void* vtable;
    void* resource;
    unsigned int count;
    unsigned int capacity;
    void* manager;
    unsigned int options;

    ResourceDescriptor* FUN_004705e0(unsigned int initialCount, unsigned int initialOptions);
};
// @fnv 0x004705e0
ResourceDescriptor* ResourceDescriptor::FUN_004705e0(unsigned int initialCount, unsigned int initialOptions)
{
    vtable = &DAT_01019a34;
    count = initialCount;
    options = initialOptions;
    capacity = 0;
    manager = 0;
    if (count > 0)
    {
        resource = FUN_0096afc0(count);
    }
    else
    {
        resource = 0;
    }
    return this;
}


// @fnv 0x00471f70
Twin_008d0360* __cdecl FUN_00471f70()
{
    return g_011f6078;
}

class Base_b9207
{
  public:
    virtual ~Base_b9207();
    unsigned int unk04;
    unsigned int unk08;
};

class FUN_004745d0 : public Base_b9207
{
  public:
    virtual ~FUN_004745d0();
};
// @fnv 0x00474500
void* FUN_00474500_Class::FUN_00474500(unsigned int flags)
{
    reinterpret_cast<::FUN_004745d0 *>(this)->FUN_004745d0::~FUN_004745d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004745d0
FUN_004745d0::~FUN_004745d0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_00475220_member
{
    ~FUN_00475220_member();
};
struct FUN_00475220
{
    int unk00;
    unsigned char ucCount;
    FUN_004752e0_Class** ppItems;
    int unk0C;
    FUN_00475220_member member;
    ~FUN_00475220();
};

// @fnv 0x00475220
FUN_00475220::~FUN_00475220()
{
    for (unsigned int i = 0; i < ucCount; i++)
    {
        FUN_004752e0_Class* pItem = ppItems[i];
        FUN_004752e0_Class* pCopy = pItem;
        pCopy ? pCopy->FUN_004752e0(1) : 0;
    }
    {
        void* pData = ppItems;
        ::FUN_00401030(pData);
    }
}

class FUN_00475310_obj
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual int vSlot10(int arg);
};

class FUN_00475310_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00475310_obj* m_14;
    void FUN_00475310();
};
// Calls FUN_00475310, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x004752e0
void* FUN_004752e0_Class::FUN_004752e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00475310_cls *>(this)->FUN_00475310();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls vSlot10(1) on m_14 if it is non-null.
// @fnv 0x00475310
void FUN_00475310_cls::FUN_00475310()
{
    FUN_00475310_obj* obj = m_14;
    FUN_00475310_obj* p = obj;
    (p != 0) ? p->vSlot10(1) : 0;
}

struct InstanceData36
{
    unsigned int values[9];
};
struct InstanceData12
{
    unsigned int values[3];
};
struct OutputRenderer
{
};
struct ChildRange;
struct CollectionItem
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual ChildRange* GetChildren();
};
struct ChildRange
{
    unsigned int FUN_0043b480();
    CollectionItem* FUN_0043b4a0(unsigned int);
};
void __cdecl CreateProjectileRef(int, OutputRenderer*, OutputRenderer*, unsigned int, InstanceData12, InstanceData36);
struct ActorProcessor
{
    int ProcessCollectionTree(CollectionItem*, intptr_t, unsigned int, OutputRenderer*);
};
// Recursively processes item and its children, calling CreateProjectileRef on matching items and returning the count processed.
// @fnv 0x00476cb0
int ActorProcessor::ProcessCollectionTree(CollectionItem* item, intptr_t arg, unsigned int options, OutputRenderer* output)
{
    if (item == 0)
        return 0;
    int processed = 0;
    if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned char *>(&::g_01202e7c))), (::NiAVObject *)(item)))
    {
        CollectionItem* localItem = item;
        if (reinterpret_cast<::FUN_00c455a0_cls *>((localItem))->FUN_00c455a0(static_cast<unsigned char>(options)))
        {
            CreateProjectileRef(arg, output, output, ((unsigned int)(uintptr_t)(reinterpret_cast<::LowProcess *>((output))->GetTarget())), *((::InstanceData12 *)(::FUN_0045bb80((intptr_t)(localItem)))),
                                *((::InstanceData36 *)(::FUN_00461130((intptr_t)(localItem)))));
            ++processed;
        }
    }
    ChildRange* children = item->GetChildren();
    if (children != 0)
    {
        for (unsigned int index = 0; index < children->FUN_0043b480(); ++index)
            processed += ProcessCollectionTree(children->FUN_0043b4a0(index), arg, options, output);
    }
    return processed;
}

struct NodeChildren;
struct Node
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual NodeChildren* GetChildren();
};
struct NodeChildren
{
    unsigned int FUN_0043b480();
    Node* FUN_0043b4a0(unsigned int index);
};
struct Context
{
};
struct Receiver
{
};
struct Walk
{
    int WalkTree(Node* node, Receiver* receiver, unsigned int mode, Context* context, void* extra);
};
// Recursively walks a node tree, applying a typed check and receiver update to matching nodes, and returns the number of nodes processed.
// @fnv 0x00476dd0
int Walk::WalkTree(Node* node, Receiver* receiver, unsigned int mode, Context* context, void* extra)
{
    if (node == 0)
        return 0;
    int count = 0;
    if (((unsigned char)(::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned char *>(&::g_01202e84))), (::NiAVObject *)(node)))))
    {
        Node* typed = node;
        if (((unsigned char)(reinterpret_cast<::FUN_00c455a0_cls *>((typed))->FUN_00c455a0((unsigned char)mode))))
        {
            reinterpret_cast<::BGSDebris_shell2 *>((receiver))->FUN_004fa6f0((void *)(reinterpret_cast<::LowProcess *>((context))->GetTarget()), (::Vec3 *)(::FUN_0045bb80((intptr_t)(typed))), (unsigned int)(uintptr_t)(extra), reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((context))->FUN_00567400());
            count++;
        }
    }
    NodeChildren* children = node->GetChildren();
    if (children != 0)
    {
        for (unsigned int index = 0; index < children->FUN_0043b480(); ++index)
        {
            count += WalkTree(children->FUN_0043b4a0(index), receiver, mode, context, extra);
        }
    }
    return count;
}

struct FUN_00477090_Sound;
struct FUN_00477090_Space;

struct FUN_00477090_Handle
{
};

struct FUN_00477090_Ref
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
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void RefreshSound(int a, int b);
};

struct FUN_00477090_Stage
{
    unsigned char unk00;
    unsigned char percent;
    unsigned char unk02;
    unsigned char unk03;
    int value;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00477090_Sound* sound;
};

struct FUN_00477090_Data
{
    unsigned int total;
    unsigned char count;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    FUN_00477090_Stage** stages;
};


struct FUN_00477090_Owner
{
    int unk00;
    FUN_00477090_Data* data;
    void UpdateSoundLevel(FUN_00477090_Ref* ref);
};

// @fnv 0x00477090
void FUN_00477090_Owner::UpdateSoundLevel(FUN_00477090_Ref* ref)
{
    float levelX = reinterpret_cast<::FUN_0041b6b0_shell *>((((::FUN_00477090_Handle *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041b6b0();
    if (levelX == -1.0)
        return;
    unsigned char target9 = (unsigned char)::InventoryStackRecord::GetConditionPercent(levelX * 100.0 / data->total);
    int prevValue7 = 0;
    unsigned char prevPercent = 100;
    FUN_00477090_Sound* sound = 0;
    for (unsigned int i4 = 0; i4 < data->count; i4++)
    {
        FUN_00477090_Stage* stage5 = data->stages[i4];
        if (stage5->percent < target9)
        {
            if (!prevValue7)
                break;
            if (stage5->sound)
                sound = stage5->sound;
        }
        prevValue7 = stage5->value;
        prevPercent = stage5->percent;
    }
    if (prevPercent < target9)
    {
        float newLevel3 = prevPercent / 100.0 * data->total;
        reinterpret_cast<::ExtraListHelper *>((((::FUN_00477090_Handle *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041b6e0(newLevel3);
        if (sound)
        {
            ref->RefreshSound(0, 1);
            reinterpret_cast<::FUN_0042e150_StandIn *>((((::FUN_00477090_Handle *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0042e150((intptr_t)(sound), (intptr_t)(((::FUN_00477090_Space *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))));
        }
        reinterpret_cast<::HealthHandler *>(this)->FUN_00476f50((::HealthReference *)(ref), 0);
    }
}

struct FUN_00477230_owner
{
    int IsFlagged();
};

struct FUN_00477230_item
{
    unsigned int GetCount();
    struct FUN_00477230_node* GetChild(unsigned int index);
};

struct FUN_00477230_arg
{
};

struct FUN_00477230_node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual FUN_00477230_item* v0c();
};

struct FUN_00477230_cls
{
    void FUN_00477230(FUN_00477230_node* node, FUN_00477230_arg* arg);
};


// Recursively visits a node's item, calls arg->Update when the item's owner is flagged and matches SceneHelperA, then recurses into each child.
// @fnv 0x00477230
void FUN_00477230_cls::FUN_00477230(FUN_00477230_node* node, FUN_00477230_arg* arg)
{
    if (node == 0)
    {
        return;
    }
    FUN_00477230_item* item = node->v0c();
    if (item != 0)
    {
        if (((::FUN_00477230_owner *)(reinterpret_cast<::TESTopicInfoData *>((item))->GetLinkToList()))->IsFlagged())
        {
            if (::FUN_009a3830((const int *)(::FUN_00477230_owner *)(((::FUN_00477230_owner *)(reinterpret_cast<::TESTopicInfoData *>((item))->GetLinkToList()))), (const int *)(::FUN_00477230_owner *)(((::FUN_00477230_owner *)(::FUN_004772e0())))))
            {
                reinterpret_cast<::FUN_00438690 *>((arg))->FUN_007cb2e0((unsigned int *)(::FUN_00477230_item **)(&item));
            }
        }
        for (unsigned int i = 0; i < item->GetCount(); i++)
        {
            this->FUN_00477230(item->GetChild(i), arg);
        }
    }
}


// @fnv 0x004772e0
NiFixedString* __cdecl FUN_004772e0()
{
    return ::DAT_011c61d8;
}


class FnvShapeObject
{
  public:
};

struct FnvShapeEntry
{
    unsigned char unk00;
    unsigned char m_b01;
    unsigned short unk02;
    unsigned int unk04;
    FnvShapeObject* m_obj08;
};

struct FnvShapeList
{
    unsigned int unk00;
    unsigned char m_count04;
    unsigned char unk05;
    unsigned short unk06;
    FnvShapeEntry** m_entries08;
};

class FUN_00477970_cls
{
  public:
    unsigned int unk00;
    FnvShapeList* m_list04;
    float FindShapeByThresholds(unsigned char a1, float a2, float a3, FnvShapeObject** out);
};

struct ManagedSceneEntry
{
    unsigned int state;
    unsigned int identifier;
    unsigned int priority;
    unsigned int flags;
    unsigned int timestamp;

    __forceinline ManagedSceneEntry()
    {
        reinterpret_cast<S751*>(this)->Initialize();
    }
};

struct ManagedSceneHolder
{
    unsigned int mode;
    ManagedSceneEntry* current;
    void EnsureCurrentEntry();
};

// Allocates a new ManagedSceneEntry and stores it in current when current is null.
// @fnv 0x00478600
void ManagedSceneHolder::EnsureCurrentEntry()
{
    if (!current)
        current = new ManagedSceneEntry;
}


struct SpawnedItem_b10003
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SpawnedItem_b10003();
};

struct FUN_00478e90_This
{
    int unk00;
    SpawnedItem_b10003** AllocateSpawnedItemArray(unsigned char count);
};

// Allocates an array of count SpawnedItem_b10003 pointers, constructs a new SpawnedItem_b10003 for each, and returns the array (or null when count is 0).
// @fnv 0x00478e90
SpawnedItem_b10003** FUN_00478e90_This::AllocateSpawnedItemArray(unsigned char count)
{
    if (count == 0)
        return 0;
    SpawnedItem_b10003** pItemArray = new SpawnedItem_b10003*[count];
    for (unsigned int i = 0; i < count; ++i)
    {
        pItemArray[i] = new SpawnedItem_b10003();
    }
    return pItemArray;
}

struct FUN_0048a3d0;
typedef void(* CopyMethod)(FUN_0048a3d0*, const FUN_0048a3d0*);
typedef void*(* ReleaseMethod)(FUN_0048a3d0*, int);
struct EffectMethods
{
    void* unk00;
    void* unk04;
    CopyMethod copy08;
    void* unk0c;
    ReleaseMethod release10;
};
struct FUN_0048a3d0
{
    EffectMethods* methods;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_0048a3d0();
};
struct CopyInterface
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void CopyFrom(const FUN_0048a3d0* other);
};
struct EffectData
{
    unsigned char flags00;
    unsigned char flags01;
    unsigned char flags02;
    int count04;
    int count08;
    int count0c;
    int count10;
    FUN_0048a3d0* effect14;
    void FUN_00478fd0(const EffectData* source);
};
// Copies the scalar fields from source, releases the current effect14, then clones source->effect14 into a new object.
// @fnv 0x00478fd0
void EffectData::FUN_00478fd0(const EffectData* source)
{
    if (!source)
        return;
    flags01 = source->flags01;
    count04 = source->count04;
    flags00 = source->flags00;
    flags02 = source->flags02;
    count08 = source->count08;
    count0c = source->count0c;
    count10 = source->count10;
    if (effect14)
    {
        FUN_0048a3d0* oldEffect = effect14;
        FUN_0048a3d0* previous = oldEffect;
        previous ? previous->methods->release10(previous, 1) : 0;
        effect14 = 0;
    }
    if (source->effect14)
    {
        effect14 = new FUN_0048a3d0();
        reinterpret_cast<CopyInterface*>(effect14)->CopyFrom(source->effect14);
    }
}

class B479260MapBase
{
  public:
    virtual ~B479260MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};

class FUN_00479260_Map : public B479260MapBase
{
  public:
    virtual ~FUN_00479260_Map();
    void RemoveAll();
};

// @fnv 0x00479260
FUN_00479260_Map::~FUN_00479260_Map()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class BGSChangeFlags47E
{
  public:
    BGSChangeFlags47E(unsigned int uiFlags);

    unsigned int m_uiValue1;
};

class BGSLoadFormBuffer47E
{
  public:
    BGSChangeFlags47E GetChangeFlags();
};

class TESActorBaseData47E
{
  public:
    void FUN_0047ea70(BGSLoadFormBuffer47E* pkBuffer);
    int unk00;
    int m_iFlags;
};

// If the buffer's change flags include bit 2, saves flag bit 1, reads 0x18 bytes into m_iFlags, then restores flag bit 1.
// @fnv 0x0047ea70
void TESActorBaseData47E::FUN_0047ea70(BGSLoadFormBuffer47E* pkBuffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::BGSChangeFlags47E &)(pkBuffer->GetChangeFlags()))->FUN_004280f0(2))
    {
        bool bFlag = reinterpret_cast<::TESActorBaseData *>(this)->GetFlag(1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pkBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iFlags), 0x18);
        reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(1, bFlag, 1);
    }
}

struct FUN_0047ead0_cls
{
    void FUN_0047ead0(int mode);
};
struct FUN_0047ead0_ActorBase
{
    char pad[0x30];
    FUN_0047ead0_cls unk30;
};


// @fnv 0x0047ead0
void FUN_0047ead0_cls::FUN_0047ead0(int mode)
{
    FUN_0047ead0_cls* cur = ((::FUN_0047ead0_cls *)(reinterpret_cast<::TESRegion *>((this))->GetDiffuseColor()));
    while (cur != 0 && *((::FUN_0047ead0_cls **)(new ((void *)(cur)) ::Vec3())) != 0)
    {
        FUN_0047ead0_cls* obj = *((::FUN_0047ead0_cls **)(new ((void *)(cur)) ::Vec3()));
        {
            FUN_0047ead0_cls* vt = *(FUN_0047ead0_cls**)obj;
            if (obj != 0)
            {
                if (reinterpret_cast<::fnv_0047d680::FUN_0047d680_shell *>((&reinterpret_cast<FUN_0047ead0_ActorBase*>(reinterpret_cast<::Actor *>(((*reinterpret_cast<::FUN_0047ead0_cls * *>(&::_g_thePlayer))))->GetActorBase())->unk30))->GetFactionRank((::fnv_0047d680::TESFaction *)(vt), true) != -1)
                {
                    switch (mode)
                    {
                    case 1:
                        reinterpret_cast<::FUN_0047ebd0_Class *>((vt))->FUN_0047ebd0(1);
                        break;
                    case 0:
                        reinterpret_cast<::FUN_0047ebb0_Class *>((vt))->FUN_0047ebb0(1);
                        break;
                    case 2:
                        reinterpret_cast<::FUN_0047eb90_Class *>((vt))->FUN_0047eb90(1);
                        break;
                    }
                }
            }
        }
        cur = ((::FUN_0047ead0_cls *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
}

struct FUN_0047fe80_class : BaseFormComponent
{
    virtual void FUN_0047fe80_v1();
    virtual void FUN_0047fe80_v2();
    virtual void FUN_0047fe80_v3();
    virtual unsigned short GetAttackDamage();
    bool IsAttackDamageDifferent(BaseFormComponent* other);
};

// Casts other to TESAttackDamageForm; returns true if the cast fails or the attack damage values differ, otherwise false.
// @fnv 0x0047fe80
bool FUN_0047fe80_class::IsAttackDamageDifferent(BaseFormComponent* other)
{
    TESAttackDamageForm* form = dynamic_cast<TESAttackDamageForm*>(other);
    if (form == 0)
    {
        return true;
    }
    if (GetAttackDamage() != reinterpret_cast<FUN_0047fe80_class*>(form)->GetAttackDamage())
    {
        return true;
    }
    return false;
}

struct Standin77900
{
    float FUN_00477900();
};
class PathingRequest
{
  public:
public:
    float GetTargetRadius();
};
// @fnv 0x00477970
float FUN_00477970_cls::FindShapeByThresholds(unsigned char a1, float fMinMeasure, float fMinWeight,
                                              FnvShapeObject** ppOutObject)
{
    for (unsigned int i = 0; i < m_list04->m_count04; i++)
    {
        FnvShapeEntry* item = m_list04->m_entries08[i];
        if (item->m_b01 < a1 && item->m_obj08 != 0)
        {
            if (fMinMeasure <= reinterpret_cast<::Standin77900 *>((item->m_obj08))->FUN_00477900() && fMinWeight <= reinterpret_cast<::PathingRequest *>((item->m_obj08))->GetTargetRadius())
            {
                float result = (float)((double)item->m_b01 / ::g_d100 * (double)m_list04->unk00);
                if (ppOutObject != 0)
                {
                    *ppOutObject = item->m_obj08;
                }
                return result;
            }
        }
    }
    return ::DAT_01012054;
}
struct FUN_00477a50_Entry
{
    char cType;
    unsigned char ucHour;
    char pad02[2];
    unsigned int ItemUpdateArray;
    Standin77900* pData;
};
struct FUN_00477a50_Table
{
    unsigned int uiTotal;
    unsigned char ucEntries;
    char pad05[3];
    FUN_00477a50_Entry** ppEntries;
};
struct FUN_00477a50_shell
{
    void* vtbl;
    FUN_00477a50_Table* pSearchEntries;
    float GetHourlyWeightedTime(unsigned char aucHour, float afMin, float afMinB, Standin77900** appData);
};
// @fnv 0x00477a50
float FUN_00477a50_shell::GetHourlyWeightedTime(unsigned char aucHour, float afMin, float afMinB,
                                                Standin77900** appData)
{
    float fTotal = 0.0f;
    float fPriorKeyTime = (float)pSearchEntries->uiTotal * aucHour / ::g_d100;
    unsigned int uiLastNum = 0;
    for (unsigned int i = 0; i < pSearchEntries->ucEntries; ++i)
    {
        FUN_00477a50_Entry* pEntry = pSearchEntries->ppEntries[i];
        if (pEntry->ucHour < aucHour)
        {
            if (!uiLastNum)
                break;
            float fTime = (float)pSearchEntries->uiTotal * pEntry->ucHour / ::g_d100;
            fTotal += (fPriorKeyTime - fTime) / uiLastNum;
            fPriorKeyTime = fTime;
            if (pEntry->pData && afMin <= pEntry->pData->FUN_00477900() &&
                afMinB <= reinterpret_cast<::PathingRequest *>((void *)(((PathingRequest*)pEntry->pData)))->GetTargetRadius())
            {
                if (appData)
                    *appData = pEntry->pData;
                return fTotal;
            }
        }
        uiLastNum = pEntry->ItemUpdateArray;
    }
    return DAT_01012054;
}

struct CopyStage
{
    ~CopyStage();
};
struct DestructionData
{
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short unk06;
    CopyStage** stages;
    unsigned int unk0c;
    unsigned int unk10;
    DestructionData();
    ~DestructionData();
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    DestructionData* data;
    void FUN_004786e0(BaseFormComponent* source);
};
// Copies destruction data from another BGSDestructibleObjectForm, freeing old stages and cloning each stage, or clears data if the source has none.
// @fnv 0x004786e0
void BGSDestructibleObjectForm::FUN_004786e0(BaseFormComponent* source)
{
    BGSDestructibleObjectForm* pOther = dynamic_cast<BGSDestructibleObjectForm*>(source);
    if (!pOther)
        return;
    DestructionData* pSourceData = ((::DestructionData *)(reinterpret_cast<::Callees *>((pOther))->FUN_00726070()));
    if (pSourceData)
    {
        if (!data)
            data = new DestructionData;
        else
        {
            for (unsigned int index = 0; index < data->count; ++index)
                delete data->stages[index];
            delete[] data->stages;
            data->stages = 0;
        }
        data->flags = pSourceData->flags;
        data->health = pSourceData->health;
        data->count = pSourceData->count;
        if (data->count)
        {
            data->stages = ((::CopyStage **)(reinterpret_cast<::FUN_00478e90_This *>(this)->AllocateSpawnedItemArray(data->count)));
            for (unsigned int stageIndex = 0; stageIndex < data->count; ++stageIndex)
                reinterpret_cast<::EffectData *>((data->stages[stageIndex]))->FUN_00478fd0((const ::EffectData *)(pSourceData->stages[stageIndex]));
        }
    }
    else
    {
        delete data;
        data = 0;
    }
}

struct NiFixedString_47ab40
{
    operator const char*() const;
};
struct NamedObject_47ab40
{
};
union SETTING_VALUE_47ab40
{
    bool b;
    int i;
};
struct Setting_47ab40
{
    SETTING_VALUE_47ab40* Bool();
};

struct NiNode_47ab40;
struct World_47ab40
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
    virtual void AddObject(NiNode_47ab40* node, bool a, bool b, int c, int d);
};
struct Cell_47ab40;

struct TaskQueue_47ab40
{
};

struct Ref_47ab40
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NiNode_47ab40* Get3D();
};

// @fnv 0x0047ab40
bool FUN_0047ab40(Ref_47ab40* ref, NamedObject_47ab40* obj)
{
    bool result = false;
    if (ref && obj)
    {
        if (!std::strcmp((*(::NiFixedString_47ab40 *)(reinterpret_cast<::TESTopicInfoData *>((obj))->GetLinkToList())), "Open") || !std::strcmp((*(::NiFixedString_47ab40 *)(reinterpret_cast<::TESTopicInfoData *>((obj))->GetLinkToList())), "Close"))
            result = true;
        if (!(*reinterpret_cast<::Setting_47ab40 *>(&::g_011c4c64)).Bool()->b && result && !(*reinterpret_cast<::Setting_47ab40 *>(&::g_011c4c64)).Bool()->b)
        {
            NiNode_47ab40* node = ref->Get3D();
            if (node)
            {
                if (FUN_008c7aa0())
                {
                    reinterpret_cast<::fnv_0087b0f0::FUN_0087b0f0_shell *>((((::TaskQueue_47ab40 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b0f0((::fnv_0087b0f0::G00559a40 *)(node));
                }
                else
                {
                    Cell_47ab40* cell = ((::Cell_47ab40 *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()));
                    World_47ab40* world = cell ? ((::World_47ab40 *)(reinterpret_cast<::FUN_004543c0_cls *>((cell))->FUN_004543c0())) : 0;
                    if (world)
                        world->AddObject(node, true, true, 0, 0);
                }
            }
        }
    }
    return result;
}

class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    bool multithread;
    NiUpdateData(float, bool, bool);
};

class NN_00605d70
{
  public:
};

template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer(NiNode* object);
    ~NiPointer();
    operator NiNode*() const;
};


struct RefWithGetNiNode
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
    virtual NiNode* GetNiNode();
};

// @fnv 0x0047b360
void __cdecl FUN_0047b360(RefWithGetNiNode* apRef)
{
    NiPointer<NiNode> spNode7(apRef->GetNiNode());
    if (spNode7)
    {
        FUN_0047b470_This* pObj2 = ((::FUN_0047b470_This *)(::FUN_00c802d0((::MyNode *)(::NiNode *)(spNode7))));
        bool bFlag3 = pObj2 ? pObj2->FUN_0047b470() : false;
        if (bFlag3)
        {
            ::SetFlagRecursive(0, (::WalkNode_cls *)(void *)(spNode7));
        }
        NiUpdateData kData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NN_00605d70*)(NiNode*)spNode7)))->FUN_00a59c60((std::intptr_t)&(kData));
        if (bFlag3)
        {
            ::SetFlagRecursive(bFlag3, (::WalkNode_cls *)(void *)(spNode7));
        }
    }
}

struct ItemForm
{
    unsigned int FNV_GetFormType();
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
    virtual bool IsQuestItem();
};

struct ActorStub;

struct ScriptOwnerStub
{
};


struct WeapStub : ItemForm
{
    int GetWeaponType();
};

struct BipedFlagsStub
{
    int flags;
};

struct ListStub
{
    void* item;
    ListStub* next;
};

struct ArmorStub : ItemForm
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    BipedFlagsStub bipedModel;
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
    ListStub list154;
};

struct PlayerStub;

// @fnv 0x0047bb50
bool __cdecl IsItemEquivalent(ItemForm* a, ItemForm* pItemB)
{
    bool result5 = false;
    if (!a || !pItemB)
    {
        result5 = false;
    }
    else if (a != pItemB)
    {
        ScriptOwnerStub* owner3 = ((::ScriptOwnerStub *)(::GetBipedPointer((::TESForm *)(pItemB))));
        if (owner3)
        {
            if (reinterpret_cast<::FUN_0047ba80_This *>((owner3))->IsActorInList((::Actor *)(::ActorStub *)((ActorStub*)a)))
            {
                result5 = true;
            }
            else
            {
                float fValue = 0.0f;
                ::ApplyPerkModifiers(0x30, (::Actor *)((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))), &fValue);
                if (fValue > ::_DAT_01012060 && pItemB->FNV_GetFormType() == a->FNV_GetFormType() && !a->IsQuestItem())
                {
                    switch (pItemB->FNV_GetFormType())
                    {
                    case 0x28: {
                        WeapStub* weapA6 = (WeapStub*)a;
                        WeapStub* weapBTmp = (WeapStub*)pItemB;
                        if (reinterpret_cast<::FUN_0047bcf0_class *>((weapA6))->IsFlag80Clear() && ((int)(reinterpret_cast<::FUN_008d85e0_Class *>((weapA6))->GetUnk15C())) == ((int)(reinterpret_cast<::FUN_008d85e0_Class *>((weapBTmp))->GetUnk15C())) &&
                            weapA6->GetWeaponType() == weapBTmp->GetWeaponType())
                        {
                            result5 = true;
                        }
                        break;
                    }
                    case 0x18: {
                        ArmorStub* armA = (ArmorStub*)a;
                        ArmorStub* armB5 = (ArmorStub*)pItemB;
                        if (reinterpret_cast<::FUN_00480d90_shell *>(&(armA->bipedModel))->FUN_00480d90() && ((bool)(reinterpret_cast<::TESObjectARMO *>((armA))->GetArmorType())) == ((bool)(reinterpret_cast<::TESObjectARMO *>((armB5))->GetArmorType())) &&
                            reinterpret_cast<::Callees *>(&(armA->list154))->FUN_00726070() == reinterpret_cast<::Callees *>(&(armB5->list154))->FUN_00726070())
                        {
                            result5 = true;
                        }
                        break;
                    }
                    }
                }
            }
        }
    }
    else
    {
        result5 = true;
    }
    return result5;
}

struct xFileTime
{
    unsigned int lo, hi;
};
struct xFindData
{
    unsigned int dwFileAttributes;
    xFileTime ftCreationTime, ftLastAccessTime, ftLastWriteTime;
    unsigned int nFileSizeHigh, nFileSizeLow, dwReserved0, dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
extern "C" char*(* xg_lstrcpyA)(char*, const char*);
extern "C" char*(* xg_lstrcatA)(char*, const char*);
extern "C" void*(* xg_FindFirstFileA)(const char*, xFindData*);
extern "C" int(* xg_FindNextFileA)(void*, xFindData*);
extern "C" int(* xg_FindClose)(void*);
extern "C" long(* xg_CompareFileTime)(const xFileTime*, const xFileTime*);
int xFileExist(const char*, char*, unsigned int, unsigned int);
using xAutoMem = ::AutoMemContext;
struct xTimes
{
    int m_auiShapeKeys[5];
    xFileTime m_uiCommandId;
};
struct xList;
struct xFile
{
    xFile(const char*, const char*, int);
    ~xFile();
    int m_auiShapeKeys[0x10b];
};
struct xList
{
    void RemoveHead();
    bool IsEmpty();
    void AddHead(xFile**);
    void AddTail(xFile* const&);
    bool IsInList(xFile*&);
};
struct xBSFile
{
    xBSFile(const char*, int, unsigned int, bool);
    ~xBSFile();
    int m_auiShapeKeys[0x56];
};
struct FUN_004624b0_cls
{
    bool FUN_004624b0(const char*);
};

// @fnv 0x004624b0
bool FUN_004624b0_cls::FUN_004624b0(const char* DIR)
{
    xList* qfTOqo;
    char qsSDDgz[0x104];
    unsigned int qrEZrs;
    xList* qpqRa;
    xFile* qdqWL;
    char qpTd[0x104];
    xFindData qvyWyw;
    xFile* qHXYKT;
    char qbGYp[0x104];
    void* qnuVZg;
    xAutoMem qSVM(0x16, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 0x1195);
    ::TaskQueueInterface::CopyStringToBuffer(qbGYp, 0x104, DIR);
    qpqRa = ((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0()));
    while (qpqRa)
    {
        qdqWL = (xFile*)*((void **)(new ((void *)(qpqRa)) ::Vec3()));
        if (qdqWL)
        {
            if (reinterpret_cast<::fnv_00471400::FUN_00471400_shell *>((qdqWL))->FUN_00471400())
                qpqRa->RemoveHead();
            else
                qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070()));
            reinterpret_cast<::FUN_00471130_shell *>((qdqWL))->FUN_00471130();
        }
        else
            qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070()));
    }
    for (qrEZrs = 0; qrEZrs < 2; qrEZrs++)
    {
        xg_lstrcpyA(qsSDDgz, qbGYp);
        switch (qrEZrs)
        {
        case 0:
            xg_lstrcatA(qsSDDgz, "*.esm");
            break;
        case 1:
            xg_lstrcatA(qsSDDgz, "*.esp");
            break;
        }
        qnuVZg = xg_FindFirstFileA(qsSDDgz, &qvyWyw);
        if (qnuVZg != (void*)-1)
        {
            do
            {
                if (qvyWyw.nFileSizeHigh || qvyWyw.nFileSizeLow)
                {
                    qdqWL = ((::xFile *)(reinterpret_cast<::TESDataHandler *>(this)->LookupTESFile(qvyWyw.cFileName)));
                    if (!qdqWL)
                    {
                        const char* qxQHW;
                        xList* qAhbO;
                        char qArxcFu[0x104];
                        bool qGfbX;
                        int qrzAir;
                        char qrKBG[0x104];
                        char qbXcw[0x10];
                        unsigned int qBCzzXA;
                        char qsTDDg[0x100];
                        qxQHW = DIR;
                        qdqWL = new xFile(qxQHW, qvyWyw.cFileName, 0);
                        reinterpret_cast<::FUN_00471130_shell *>((qdqWL))->FUN_00471130();
                        ::FUN_00462d40(qvyWyw.cFileName, 0, 0, 0, 0, qrKBG, 0x104, qbXcw, 0x10);
                        ::FUN_00406d00(qArxcFu, 0x104, "%s%s.NAM", qxQHW, qrKBG);
                        xBSFile qZAdkzg(qArxcFu, 0, 0x100, true);
                        if (reinterpret_cast<::BSFile *>(&(qZAdkzg))->Write() && ::FUN_008905f0((bool *)(::xBSFile *)(&qZAdkzg)))
                        {
                            qBCzzXA = reinterpret_cast<::FUN_00462d80_shell *>(&(qZAdkzg))->ReadBytes(qsTDDg, 0x100);
                            qsTDDg[qBCzzXA] = 0;
                            reinterpret_cast<::FUN_00462ec0_shell *>((qdqWL))->AssignString(qsTDDg);
                            reinterpret_cast<::EffectSettingCollection *>((qdqWL))->InitializeCollection(true);
                            reinterpret_cast<::FUN_00462e60_Class *>((qdqWL))->SetByteAt428(1);
                        }
                        qrzAir = reinterpret_cast<::TESDataHandler *>(this)->GetDLCIndex(qrKBG);
                        if (qrzAir)
                            reinterpret_cast<::FUN_00462e10_Class *>(this)->SetFlags(1 << (qrzAir - 1), true);
                        qpqRa = ((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0()));
                        qAhbO = 0;
                        qGfbX = false;
                        while (qpqRa && *((void **)(new ((void *)(qpqRa)) ::Vec3())))
                        {
                            qHXYKT = (xFile*)*((void **)(new ((void *)(qpqRa)) ::Vec3()));
                            if ((reinterpret_cast<::TESFile *>((qHXYKT))->IsMasterFile() && reinterpret_cast<::TESFile *>((qdqWL))->IsMasterFile()) ||
                                (!reinterpret_cast<::TESFile *>((qHXYKT))->IsMasterFile() && !reinterpret_cast<::TESFile *>((qdqWL))->IsMasterFile()))
                            {
                                if (xg_CompareFileTime(&((::xTimes *)(reinterpret_cast<::FUN_00462ea0_shell *>((qHXYKT))->GetOffset29C()))->m_uiCommandId, &qvyWyw.ftLastWriteTime) >= 0)
                                {
                                    qGfbX = true;
                                    qpqRa->AddHead(&qdqWL);
                                    break;
                                }
                            }
                            else if (reinterpret_cast<::TESFile *>((qdqWL))->IsMasterFile())
                            {
                                qGfbX = true;
                                qpqRa->AddHead(&qdqWL);
                                break;
                            }
                            qAhbO = qpqRa;
                            qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070()));
                        }
                        if (!qGfbX)
                        {
                            if (qAhbO)
                                reinterpret_cast<::Callees *>((qAhbO))->FUN_00905820((void *)&(qdqWL));
                            else
                                reinterpret_cast<::Callees *>((((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0()))))->FUN_00905820((void *)&(qdqWL));
                        }
                    }
                }
            } while (xg_FindNextFileA(qnuVZg, &qvyWyw));
            xg_FindClose(qnuVZg);
        }
    }
    qpqRa = ((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0()));
    qfTOqo = 0;
    while (qpqRa && *((void **)(new ((void *)(qpqRa)) ::Vec3())))
    {
        qdqWL = (xFile*)*((void **)(new ((void *)(qpqRa)) ::Vec3()));
        xg_lstrcpyA(qsSDDgz, reinterpret_cast<::FUN_00462e80_shell *>((qdqWL))->FUN_00462e80());
        xg_lstrcatA(qsSDDgz, ((const char *)(reinterpret_cast<::BGSCameraPath *>((qdqWL))->GetShotList())));
        qnuVZg = xg_FindFirstFileA(qsSDDgz, &qvyWyw);
        if (qnuVZg == (void*)-1)
        {
            if (((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070())) || !qfTOqo)
                qpqRa->RemoveHead();
            else
            {
                reinterpret_cast<::ItemChangeListNode *>((qfTOqo))->FUN_00905330((::InventoryStackRecord *const &)(qdqWL));
                qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qfTOqo))->FUN_00726070()));
            }
            delete qdqWL;
        }
        else
        {
            qfTOqo = qpqRa;
            qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070()));
            xg_FindClose(qnuVZg);
        }
    }
    if (xFileExist("Update.bsa", qpTd, 1, -1))
        ::fnv_00af4be0::FUN_00af4be0("Update.bsa", 0, 0);
    qpqRa = ((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0()));
    while (qpqRa && !qpqRa->IsEmpty())
    {
        bool qQMZREG = false;
        xFile* qJDuOZ = (xFile*)*((void **)(new ((void *)(qpqRa)) ::Vec3()));
        if (reinterpret_cast<::TESFile *>((qJDuOZ))->IsMasterFile())
        {
            reinterpret_cast<::FUN_00471870_shell *>((qJDuOZ))->MatchMasterFiles(((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0())), false);
            for (unsigned int qpia = 0; qpia < reinterpret_cast<::FUN_00471ad0_shell *>((qJDuOZ))->FUN_00471ad0(); qpia++)
            {
                xFile* qXMUYT = ((::xFile *)(reinterpret_cast<::FUN_00471a10_shell *>((qJDuOZ))->GetFileByIndex(qpia + 1)));
                if (qXMUYT && reinterpret_cast<::RefList *>((qpqRa))->FUN_005f65d0((void **)&(qXMUYT)))
                {
                    reinterpret_cast<::ItemChangeListNode *>((qpqRa))->FUN_00905330((::InventoryStackRecord *const &)(qXMUYT));
                    qpqRa->AddHead(&qXMUYT);
                    qQMZREG = true;
                }
            }
        }
        if (!qQMZREG)
            qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070()));
    }
    qpqRa = ((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0()));
    while (qpqRa && !qpqRa->IsEmpty())
    {
        xFile* qbfQdhM = (xFile*)*((void **)(new ((void *)(qpqRa)) ::Vec3()));
        reinterpret_cast<::FUN_00471870_shell *>((qbfQdhM))->MatchMasterFiles(((::xList *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0())), false);
        qpqRa = ((::xList *)(reinterpret_cast<::Callees *>((qpqRa))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00460360_shell *>(this)->ProcessAllFiles();
    return true;
}

struct DPoint
{
    float x, y, z;
    DPoint();
    DPoint& operator*=(float);
    DPoint operator+(const DPoint&) const;
    DPoint operator-(const DPoint&) const;
    DPoint& operator+=(const DPoint&);
    DPoint& Center();
};
struct DMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    DMatrix operator*(const DMatrix&) const;
};
struct DTransform
{
    DMatrix rotation;
    DPoint translation;
    float scale;
    DTransform();
    DMatrix InverseRotation();
};
struct DBound
{
    float x, y, z, radius;
    DPoint& Center();
};
struct DNode;
struct DFader
{
};
struct DBranch
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual DFader* AsFade();
};
struct DNode
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual DBranch* AsBranch();
    DTransform& Transform();
};
struct DPointer
{
    DNode* object;
    DPointer(DNode*);
    ~DPointer();
    operator DNode*() const;
};
struct DArray
{
    unsigned int unk00, unk04, unk08, unk0c;
    DArray();
    ~DArray();
};
struct DActorValues
{
    virtual void v0();
    virtual void v4();
    virtual int GetValue(int);
};
struct DExtra
{
};
struct DRef
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
    virtual void Changed(unsigned int);
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
    virtual bool IsActor();
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
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void Reload(int, int);
    virtual DNode* GetNode();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const DPoint& GetPosition();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool IsSpecial();
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
    DActorValues values;
    DMatrix GetRotation();
    void* GetSource(int);
};
struct DStage
{
    unsigned char part, percent, unk02, unk03;
    unsigned int value;
    void* explosion;
    void* debris;
    unsigned int debrisCount;
    void* replacement;
};
struct DString
{
    void* ptr;
    operator void*() const;
};
struct ImpactDecalInfo
{
    unsigned int health;
    unsigned char count, unk05, unk06, unk07;
    DStage** stages;
    unsigned int lock;
    DString string;
};
struct DSave
{
};
struct DWorld
{
};
struct DMap
{
};
struct DSetting
{
};
struct DManager
{
    void Add(DRef*, void*, float);
};
struct DSingleton
{
};
struct DResult
{
};
struct DDebris
{
};
DResult* __cdecl SpawnExplosion(void*, void*, void*, void*, DPoint, DMatrix);
struct Destruction
{
    unsigned int unk00;
    ImpactDecalInfo* data;
    void Clear();
    void FUN_00475b20(DRef*, float, unsigned int);
};
// Reduces ref's health by damage, runs the stages crossed (delete, destroy, replace, debris, explosions), then adds or removes ref in a manager.
// @fnv 0x00475b20
void Destruction::FUN_00475b20(DRef* ref, float damage, unsigned int flags)
{
    if (!data || !ref || damage <= 0.0 || reinterpret_cast<::TESForm *>((ref))->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((ref))->FUN_00440d80())
        return;
    if (!ref->GetNode())
        return;
    unsigned int locked = reinterpret_cast<::FUN_00475ab0_cls *>(this)->FUN_00475ab0((::TESForm *)(ref));
    float frac = reinterpret_cast<::FUN_0041b6b0_shell *>((((::DExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041b6b0();
    if (frac == -1.0)
        frac = locked;
    if (frac == 0.0)
        return;
    unsigned char r = (unsigned char)::InventoryStackRecord::GetConditionPercent(frac * 100.0 / locked);
    float val = frac - damage;
    if (ref->IsActor())
    {
        DRef* actor = ref;
        val = actor->values.GetValue(16);
    }
    if (val <= 0.0)
        val = 0.0f;
    unsigned char b = (unsigned char)::InventoryStackRecord::GetConditionPercent(val * 100.0 / locked);
    if (!b && val > 0.0)
        b = 1;
    DPointer root(ref->GetNode());
    void* z = 0;
    long oldIndex;
    oldIndex = 0;
    unsigned long n;
    n = 0;
    unsigned int result = 0;
    unsigned long plus;
    int oldPart = 0;
    plus = 0;
    unsigned long newPercent;
    newPercent = 0;
    for (unsigned int index = 0; index < data->count; ++index)
    {
        DStage* stage = ((::DStage *)(reinterpret_cast<::FUN_00476a40_Holder *>(this)->FUN_00476a40(index)));
        if (stage->percent < r && stage->percent >= b)
        {
            if (stage->part)
                plus = stage->part;
            if (stage->replacement)
                z = stage->replacement;
            oldIndex = stage->value;
            result = 1 + index;
            if (reinterpret_cast<::FUN_00475a90_cls *>((stage))->IsFlag2Set())
            {
                if (ref->IsSpecial())
                {
                    DRef* newRotation = ref;
                    reinterpret_cast<::Projectile *>((newRotation))->FUN_009bc8f0();
                }
                else
                {
                    ::fnv_005aa500::FUN_005aa500((intptr_t)(ref), 0);
                    reinterpret_cast<::TESForm *>((ref))->MarkForDeletion(true);
                }
            }
            if (reinterpret_cast<::FUN_00476a20_Class *>((stage))->IsFlag4Set())
                reinterpret_cast<::TESForm *>((ref))->SetDestroyed(true);
            if (reinterpret_cast<::FUN_00476a00_cls *>((stage))->FUN_00476a00())
            {
                val = (locked * stage->percent) / 100.0;
                b = stage->percent;
                break;
            }
        }
        else if (r <= stage->percent && b < stage->percent)
        {
            n = index + 1;
            if (stage->part)
                oldPart = stage->part;
            newPercent = stage->value;
        }
    }
    if (val <= 0.0)
        reinterpret_cast<::TESForm *>((ref))->SetDestroyed(true);
    reinterpret_cast<::ExtraListHelper *>((((::DExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041b6e0(val);
    ref->Changed(0x80000000);
    if (result > n)
    {
        if (!reinterpret_cast<::TESForm *>((ref))->GetDisabled())
        {
            if (z)
            {
                DArray branch;
                DTransform j;
                reinterpret_cast<::FUN_00477230_cls *>(this)->FUN_00477230((::FUN_00477230_node *)(::DNode *)(ref->GetNode()), (::FUN_00477230_arg *)(::DArray *)(&branch));
                if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(branch))->GetName())))
                    j = (SimpleArrayItem<::DNode*>(&(branch), 0))->Transform();
                bool total;
                total = false;
                if ((void*)data->string)
                {
                    ::FUN_0040b460((unsigned int *)(void *)(&data->lock));
                    total = true;
                }
                bool tmp = reinterpret_cast<::B200Owner *>((ref))->FUN_0057b200();
                bool oldNodes;
                oldNodes = reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::DSave * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(false);
                ref->Reload(0, 1);
                if (tmp)
                    reinterpret_cast<::Ref57b240 *>((ref))->FUN_0057b240(true);
                reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::DSave * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(oldNodes);
                reinterpret_cast<::FUN_0042e150_StandIn *>((((::DExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0042e150((intptr_t)(z), (intptr_t)(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))));
                ref->Changed(0x80000000);
                reinterpret_cast<::AttachmentHandler *>(((*reinterpret_cast<::DWorld * *>(&::g_TES))))->FUN_00451ef0((::AttachRef *)(ref), (::AttachCell *)(void *)(((void *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()))), (::AttachRef *)(0), 0);
                if (ref->GetNode())
                {
                    DNode* q;
                    q = ref->GetNode();
                    DBranch* s;
                    s = q ? q->AsBranch() : 0;
                    DFader* health;
                    health = s ? s->AsFade() : 0;
                    if (health)
                        ::FUN_00476ab0((::BSFadeNode_Dummy *)(health));
                    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(branch))->GetName())))
                    {
                        DArray bound;
                        reinterpret_cast<::FUN_00477230_cls *>(this)->FUN_00477230((::FUN_00477230_node *)(q), (::FUN_00477230_arg *)(::DArray *)(&bound));
                        if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(bound))->GetName())))
                        {
                            DTransform found = (SimpleArrayItem<::DNode*>(&(bound), 0))->Transform();
                            DMatrix i = found.InverseRotation();
                            DMatrix changes = j.rotation;
                            DMatrix newNodes = ref->GetRotation();
                            DMatrix res = changes * i * newNodes;
                            reinterpret_cast<::fnv_0056fa90::Holder *>((ref))->FUN_0056fa90(res.m00, res.m01, res.m02, res.m10, res.m11, res.m12, res.m20, res.m21, res.m22);
                            ::fnv_00562020::FUN_00562020((::TESObjectREFR *)(ref));
                            found = (SimpleArrayItem<::DNode*>(&(bound), 0))->Transform();
                            DPoint pForm = j.translation - found.translation;
                            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::DPoint &)(pForm))->FUN_0063c8a0((void *)&(ref->GetPosition()));
                            reinterpret_cast<::Reference *>((ref))->FUN_00575830((::Position *)&(pForm));
                            ::fnv_00562020::FUN_00562020((::TESObjectREFR *)(ref));
                        }
                    }
                    ::FUN_00c6a270((intptr_t)(q), true, true, 0);
                }
                if (total)
                    reinterpret_cast<::FUN_004778a0_cls *>(this)->ReleaseScriptRunLock();
            }
            else if (plus > oldPart)
            {
                ::FUN_00476ec0((::NiAVObject *)(::DNode *)(((::DNode *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((ref))->FUN_0043fcd0()))), plus);
                reinterpret_cast<::fnv_0057a3c0::FUN_0057a3c0_shell *>((ref))->FUN_0057a3c0(0);
            }
        }
        if (oldIndex && val > 0.0)
        {
            reinterpret_cast<::FUN_00844700_Class *>(&((*reinterpret_cast<::DMap *>(&::g_011c4104))))->FUN_00844700((unsigned int)(uintptr_t)(ref), oldIndex);
            newPercent = oldIndex;
        }
        else
            reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::DMap *>(&::g_011c4104))))->RemoveKey((unsigned int)(uintptr_t)(ref));
    }
    for (unsigned int stageIndex = n; stageIndex < result; ++stageIndex)
    {
        DStage* stage = ((::DStage *)(reinterpret_cast<::FUN_00476a40_Holder *>(this)->FUN_00476a40(stageIndex)));
        ::FUN_005ac750((::TESForm *)(ref), (::ExtraDataList *)(::DExtra *)(((::DExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))), 0x200000);
        unsigned long ptr;
        ptr = 0;
        if (plus)
            ptr = plus;
        else if (oldPart)
            ptr = oldPart;
        if (stage->debris && stage->debrisCount)
        {
            int threshold;
            threshold = reinterpret_cast<::Walk *>(this)->WalkTree((::Node *)(::DNode *)(root), (::Receiver *)(stage->debris), ptr, (::Context *)(ref), (void *)(uintptr_t)(stage->debrisCount));
            if (!threshold)
            {
                DPoint pObj = ref->GetPosition();
                reinterpret_cast<::BGSDebris_shell2 *>((((DDebris*)stage->debris)))->FUN_004fa6f0(((void *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())), (::Vec3 *)(::DPoint *)(&pObj), stage->debrisCount, reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((ref))->FUN_00567400());
            }
        }
        if (stage->explosion)
        {
            int threshold = reinterpret_cast<::ActorProcessor *>(this)->ProcessCollectionTree((::CollectionItem *)(::DNode *)(root), (intptr_t)(stage->explosion), ptr, (::OutputRenderer *)(ref));
            if (0 == threshold)
            {
                DMatrix oldPercent = ref->GetRotation();
                DBound newTransform;
                newTransform = (*(::DBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((((DNode*)root)))->FUN_0043d450()));
                DPoint pObj;
                pObj.x = RandomFloat(DAT_01012054, 1.0f);
                pObj.y = RandomFloat(DAT_01012054, 1.0f);
                pObj.z = RandomFloat(DAT_01012054, 0.0f);
                reinterpret_cast<::MyPoint439180 *>((void *)&(const ::DPoint &)(pObj))->FUN_00439180(reinterpret_cast<::Twin_0084d030 *>(&(newTransform))->GetStoredFloatValue());
                DPoint cnt = (*(::DPoint *)(new ((void *)&(newTransform)) ::Vec3())) + pObj;
                if (ref->IsSpecial())
                {
                    DRef* newRotation = ref;
                    DResult* stageValue = SpawnExplosion(stage->explosion, ((void *)(uintptr_t)(::FUN_00874480((char *)(newRotation)))), 0,
                                                         ((void *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())), cnt, oldPercent);
                    if (stageValue && ((int)(reinterpret_cast<::FUN_00476c90_Class *>((newRotation))->FUN_00476c90())))
                        reinterpret_cast<::FUN_00476c70_Class *>((stageValue))->FUN_00476c70(((int)(reinterpret_cast<::FUN_00476c90_Class *>((newRotation))->FUN_00476c90())));
                }
                else
                    SpawnExplosion(stage->explosion, ref, ref, ((void *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())), cnt, oldPercent);
            }
        }
    }
    if (val == 0.0)
        reinterpret_cast<::FUN_004778a0_cls *>(this)->ReleaseScriptRunLock();
    void* replacement = 0;
    float rate;
    rate = DAT_01012054;
    if (newPercent)
    {
        rate =
            reinterpret_cast<::FUN_00477a50_shell *>(this)->GetHourlyWeightedTime(b, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting356)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting355)))))), (::Standin77900 **)(void **)(&replacement));
        if (rate > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting478)))))))
            rate = DAT_01012054;
    }
    if (rate == -1.0)
    {
        float inverse;
        inverse = reinterpret_cast<::FUN_00477970_cls *>(this)->FindShapeByThresholds(b, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting356)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting355)))))),
                               (::FnvShapeObject **)(void **)(&replacement));
        if (inverse != -1.0 && val - inverse < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting480)))))))
            rate = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DSetting *>(&::originalRuntimeFloatSetting479))))));
    }
    if (rate != -1.0)
        reinterpret_cast<::S_9a54a0_Class *>((((::DManager *)(uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::DSingleton * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))))->FUN_009a54a0((intptr_t)(ref), (::S_9a54a0_Actor *)(replacement), rate);
    else
        reinterpret_cast<::EntryMap9A5 *>((((::DManager *)(uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::DSingleton * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))))->RemoveEntryForRef((::Ref9A5 *)(ref));
}

struct LoadRecordHeader
{
    unsigned int type;
    unsigned int size;
    unsigned int flags;
    int groupEnd;
};
struct LoadList
{
    bool FUN_008256d0();
};
struct LoadFile
{
    bool FUN_00470c70(int, int);
};
struct LoadForm
{
    unsigned int FUN_00401170();
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
    virtual const char* GetEditorID();
};
struct FormReconstructionMap
{
};
struct LoadWorld
{
};
struct LoadTopic
{
};
struct LoadSaveGame
{
};
struct LoadMap
{
};
extern unsigned int DAT_011c3f28, DAT_011c3f24, DAT_011c40a8;
struct LoadHandler
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
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned char unk620, unk621;
    bool loading622;
    bool FUN_00467780(LoadFile*, bool);
};
// Loops over file records, handling type 2 and 0x50 group markers, loading others via FUN_00467bd0, and formatting a 'Loading Files' percent string.
// @fnv 0x00467780
bool LoadHandler::FUN_00467780(LoadFile* file, bool mode)
{
    if (!file->FUN_00470c70(0, 0))
        reinterpret_cast<::Unk0046a330 *>(this)->ReportDataHandlerError(4);
    bool result5 = true;
    int lastPercent3 = 0;
    (*reinterpret_cast<::FormReconstructionMap * *>(&::DAT_011c3f30)) = 0;
    (*reinterpret_cast<::LoadWorld * *>(&::DAT_011c3f34)) = 0;
    (*reinterpret_cast<::LoadTopic * *>(&::DAT_011c3f38)) = 0;
    bool more6 = true;
    loading622 = false;
    do
    {
        bool advance4 = true;
        more6 = true;
        if (reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660() == 2)
        {
            if (!reinterpret_cast<::fnv_004695a0::FUN_004695a0_t *>(this)->FUN_004695a0((::fnv_004695a0::FileH *)(file), (::fnv_004695a0::FUN_004695a0_rec *)(::LoadRecordHeader *)(((::LoadRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader())))))
            {
                advance4 = false;
                if (!reinterpret_cast<::TESFile *>((file))->IsGroupOpen())
                    more6 = false;
            }
        }
        else if (reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660() == 0x50)
        {
            int groupEnd = ((::LoadRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()))->groupEnd;
            if (groupEnd == -1)
            {
                advance4 = false;
                more6 = false;
            }
            else if (groupEnd == -2)
            {
                unsigned int groupSize7 = ((::LoadRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()))->size;
                unsigned int nextOffset = reinterpret_cast<::TESFile *>((file))->GetOffset() + 0x18;
                reinterpret_cast<::FUN_00473d00_Class *>((file))->ReturnTrue(nextOffset, groupSize7);
                advance4 = false;
                more6 = false;
            }
            else if ((*reinterpret_cast<::LoadTopic * *>(&::DAT_011c3f38)))
            {
                reinterpret_cast<::FUN_00589f50_shell *>(((*reinterpret_cast<::LoadTopic * *>(&::DAT_011c3f38))))->SetSound((void *)(intptr_t)(groupEnd));
            }
            else if ((*reinterpret_cast<::LoadWorld * *>(&::DAT_011c3f34)))
            {
                unsigned int distance = groupEnd - reinterpret_cast<::TESFile *>((file))->GetOffset();
                distance += 0x18;
                reinterpret_cast<::fnv_005857b0::FUN_005857b0_shell *>(((*reinterpret_cast<::LoadWorld * *>(&::DAT_011c3f34))))->FUN_005857b0((intptr_t)(file), distance);
            }
            else if ((*reinterpret_cast<::FormReconstructionMap * *>(&::DAT_011c3f30)) && reinterpret_cast<::TESObjectCELL *>(((*reinterpret_cast<::FormReconstructionMap * *>(&::DAT_011c3f30))))->IsCellInterior() && ((::LoadList *)(reinterpret_cast<::FUN_00464df0_shell *>((file))->FUN_00464df0()))->FUN_008256d0())
            {
                reinterpret_cast<::FUN_0054de80Class *>(((*reinterpret_cast<::FormReconstructionMap * *>(&::DAT_011c3f30))))->FUN_0054de80(groupEnd);
            }
        }
        else if (!reinterpret_cast<::TESDataHandler *>(this)->ConstructObject((::TESFile *)(file), mode, (::TESForm *)(::LoadForm *)(0), (bool)(0)))
        {
            result5 = false;
        }
        else
        {
            LoadForm* form5 = 0;
            bool lookedUpTmp = false;
            if ((*reinterpret_cast<::LoadSaveGame * *>(&::g_TESSaveLoadGame)) && reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::LoadSaveGame * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
            {
                DAT_011c40a8++;
                if ((DAT_011c40a8 & 0xff) == 0)
                    reinterpret_cast<::LLD_TESHelper *>(((*reinterpret_cast<::LoadSaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00861ea0();
                form5 = ((::LoadForm *)(::FUN_004839c0(((unsigned int)(uintptr_t)(reinterpret_cast<::MiddleHighProcess *>((file))->GetFaceGenHeadNode())))));
                lookedUpTmp = true;
                if (form5)
                    reinterpret_cast<::fnv_008632a0::FUN_008632a0_slg *>(((*reinterpret_cast<::LoadSaveGame * *>(&::g_TESSaveLoadGame))))->AddLoadingTopic((::fnv_008632a0::TESTopicInfo *)(form5));
            }
            else
            {
                if (!lookedUpTmp)
                    form5 = ((::LoadForm *)(::FUN_004839c0(((unsigned int)(uintptr_t)(reinterpret_cast<::MiddleHighProcess *>((file))->GetFaceGenHeadNode())))));
                if (form5)
                {
                    switch (form5->FUN_00401170())
                    {
                    case 0x2a:
                    case 0x2b:
                    case 0x3a:
                    case 0x3b:
                    case 0x3c:
                    case 0x3d:
                    case 0x3e:
                    case 0x3f:
                    case 0x40:
                    case 0x69:
                        break;
                    default: {
                        const char* editorID2 = form5->GetEditorID();
                        if (editorID2 && *editorID2)
                            reinterpret_cast<::TMapStandIn *>(((*reinterpret_cast<::LoadMap * *>(&::DAT_011c54c8))))->InsertOrUpdate((uintptr_t)(editorID2), form5);
                    }
                    }
                }
            }
        }
        DAT_011c3f28++;
        int _percent = (int)((double)DAT_011c3f28 / (double)DAT_011c3f24 * 100.0);
        if (_percent != lastPercent3)
        {
            lastPercent3 = _percent;
            char progress2[260];
            ::FUN_00406d00(progress2, 260, "Loading Files %d%% (%s)", lastPercent3, ((const char *)(reinterpret_cast<::BGSCameraPath *>((file))->GetShotList())));
        }
        if (advance4)
            more6 = reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
    } while (more6);
    if (!reinterpret_cast<::FUN_00471130_shell *>((file))->FUN_00471130())
        reinterpret_cast<::Unk0046a330 *>(this)->ReportDataHandlerError(4);
    return result5;
}

struct FUN_004726b0_class
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
    int FUN_004726b0();
};


// If unk258 is zero, calls ReadChunkHeader and returns 0 if that fails; otherwise returns unk258.
// @fnv 0x004726b0
int FUN_004726b0_class::FUN_004726b0()
{
    if (this->unk258 == 0 && !((unsigned char)(reinterpret_cast<::fnv_00472d30::FUN_00472d30_shell *>((reinterpret_cast<TESFile*>(this)))->ReadChunkHeader())))
    {
        return 0;
    }

    return this->unk258;
}

struct FUN_00474730
{
    virtual ~FUN_00474730();
};
struct FUN_004746d0 : FUN_00474730
{
    virtual ~FUN_004746d0();
};
// @fnv 0x00474530
void* FUN_004746d0_Class::FUN_00474530(unsigned int flags)
{
    reinterpret_cast<::FUN_004746d0 *>(this)->FUN_004746d0::~FUN_004746d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x004746d0
FUN_004746d0::~FUN_004746d0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct GlobalObject_00479190
{
    ~GlobalObject_00479190();
};
struct FUN_004791c0 : GlobalObject_00479190
{
    virtual ~FUN_004791c0();
};
// @fnv 0x004791c0
FUN_004791c0::~FUN_004791c0()
{}

class DestructionExtra
{
  public:
    virtual void Destroy();
    virtual void Initialize();
    virtual void CopyFrom(DestructionExtra* other);
    virtual bool Differs(DestructionExtra* other);
};
struct DestructionStage
{
    unsigned char health;
    unsigned char index;
    unsigned char damageStage;
    unsigned int flags;
    unsigned int selfDamage;
    unsigned int explosion;
    unsigned int debris;
    DestructionExtra* extra;
};
class DestructibleComparison : public BGSDestructibleObjectForm
{
  public:
    bool FUN_00478900(BaseFormComponent* other);
};
// Compares destruction data of two destructible forms and returns true if their health, flags, count, or any destruction stage field differs.
// @fnv 0x00478900
bool DestructibleComparison::FUN_00478900(BaseFormComponent* other)
{
    BGSDestructibleObjectForm* form4 = dynamic_cast<BGSDestructibleObjectForm*>(other);
    if (!form4)
        return true;
    DestructionData* rhs3 = ((::DestructionData *)(reinterpret_cast<::Callees *>((form4))->FUN_00726070()));
    if (!rhs3 || !data)
    {
        if (!rhs3 && !data)
            return false;
        else
            return true;
    }
    if (data->health != rhs3->health)
        return true;
    if (data->flags != rhs3->flags)
        return true;
    if (data->count != rhs3->count)
        return true;
    for (unsigned int i = 0; i < data->count; ++i)
    {
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->index !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->index)
            return true;
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->flags !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->flags)
            return true;
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->health !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->health)
            return true;
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->damageStage !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->damageStage)
            return true;
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->selfDamage !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->selfDamage)
            return true;
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->explosion !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->explosion)
            return true;
        if (reinterpret_cast<DestructionStage*>(rhs3->stages[i])->debris !=
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->debris)
            return true;
        if ((reinterpret_cast<DestructionStage*>(data->stages[i])->extra &&
             !reinterpret_cast<DestructionStage*>(rhs3->stages[i])->extra) ||
            (!reinterpret_cast<DestructionStage*>(data->stages[i])->extra &&
             reinterpret_cast<DestructionStage*>(rhs3->stages[i])->extra))
            return true;
        if (reinterpret_cast<DestructionStage*>(data->stages[i])->extra &&
            reinterpret_cast<DestructionStage*>(rhs3->stages[i])->extra)
        {
            if (reinterpret_cast<DestructionStage*>(data->stages[i])
                    ->extra->Differs(reinterpret_cast<DestructionStage*>(rhs3->stages[i])->extra))
                return true;
        }
    }
    return false;
}

// @fnv 0x00470110
void FUN_00464f40_class::FUN_00470110()
{
    reinterpret_cast<FNVPointerArray*>(this)->m_ppVirtualMethodTable = reinterpret_cast<void**>(&DAT_01019a34);
    ::FUN_004ede70(reinterpret_cast<FNVPointerArray*>(this)->m_pBase);
}

void __cdecl FUN_00ec825b(char* p, unsigned int a, char const* b, char const* c, char const* d, char const* e);

void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);

void __cdecl BSEndian(unsigned int*, EndianSizeTag<3>);

enum ENUM_FORM_ID;

Twin_008d0360* __cdecl FUN_00471f70();

int FUN_00ec6da0(const char*, const char*);

// FUN_00461cf0 (0x00461cf0, 1340 bytes) -- TESFile record scan.
// Vtable-free; member of the file-list holder (count at +0x218, array at +0x21c).
class TESWorldSpace;

struct TESRecordHeader
{
    unsigned int type;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
};

// XCLC chunk payload: two dwords swapped by the endian pass plus a trailing bool.
struct XCLC
{
    unsigned int x;
    unsigned int y;
    unsigned char z;
    XCLC();
};

using ::AutoMemContext;

class VoiceStr
{
  public:
    bool FUN_008256d0();
};

class DialogueResponse
{
  public:
};

struct FUN_00585940_shell
{
};

struct TESWorldSpace : TESForm
{
  public:
    virtual ~TESWorldSpace();
};

extern "C" char DAT_010186b8[];

struct TESFileArray
{
    char pad[0x218];
    unsigned int mCount;
    TESFile* mFiles[1];
    intptr_t FUN_00461cf0(char*, int*, int*);
};

// @fnv 0x00461cf0
intptr_t TESFileArray::FUN_00461cf0(char* name, int* out1, int* out2)
{
    AutoMemContext ctx(0x16, true, (char*)DAT_010186b8, 0x1041);
    intptr_t result = 0;
    *out1 = 0;
    *out2 = 0;
    if (name && *name)
    {
        bool found = false;
        for (unsigned int i = 0; i < mCount; i++)
        {
            if (mFiles[i] && mFiles[i]->GetOptimizedFile())
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            VoiceStr* p = ((::VoiceStr *)(::FUN_00460140((intptr_t)((*reinterpret_cast<::DialogueResponse * *>(&::g_dataHandler))))));
            while (p && !p->FUN_008256d0())
            {
                void* v = *((void **)(new ((void *)(p)) ::Vec3()));
                p = ((::VoiceStr *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
                if (reinterpret_cast<::WorldData *>((((FUN_00585940_shell*)v)))->FindCellByEditorID(name, out1, out2))
                {
                    result = (intptr_t)v;
                    break;
                }
            }
        }
        else
        {
            for (unsigned int j = 0; j < mCount; j++)
            {
                TESFile* f = mFiles[j];
                if (f && f->FUN_00470c70(0, 0))
                {
                    TESRecordHeader* hdr = f->GetRecordHeader();
                    bool got = false;
                    while (hdr && !got)
                    {
                        bool read = false;
                        if (hdr->type == (unsigned int)(*reinterpret_cast<int *>(&::fnv_00543df0::kGroupFormType)))
                        {
                            if (hdr->fC == 0 && hdr->f8 == (unsigned int)(*reinterpret_cast<int *>((void *)&::fnv_00543f50::str_01187314)))
                            {
                                got = true;
                                read = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                            }
                            else
                            {
                                read = f->IsGroupOpen();
                            }
                        }
                        else
                        {
                            read = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                        }
                        if (read)
                            hdr = f->GetRecordHeader();
                        else
                            hdr = 0;
                    }
                    if (got)
                    {
                        hdr = f->GetRecordHeader();
                        got = false;
                        while (hdr && !got)
                        {
                            bool read2 = false;
                            if (hdr->type == (unsigned int)(*reinterpret_cast<int *>((void *)&::fnv_00543f50::str_01187314)))
                            {
                                unsigned int id = hdr->fC;
                                unsigned int hi = id >> 24;
                                TESFile* w = reinterpret_cast<::FUN_00471a10_shell *>((f))->GetFileByIndex(hi + 1);
                                if (!w)
                                    w = f;
                                id &= 0xffffff;
                                id |= (unsigned int)(unsigned char)w->GetFileCompileIndex() << 24;
                                result = (intptr_t)dynamic_cast<TESWorldSpace*>(::FUN_004839c0(id));
                                read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                            }
                            else if (hdr->type == (unsigned int)(*reinterpret_cast<int *>(&::DAT_011872b4)))
                            {
                                int chunk = reinterpret_cast<::FUN_004726b0_class *>((f))->FUN_004726b0();
                                if (chunk == 0x44494445)
                                {
                                    unsigned int len = reinterpret_cast<::FUN_00401660_Class *>((f))->GetField25C() + 1;
                                    char* ptr = (char*)::FUN_00401000(len);
                                    ::FUN_00403d30(ptr, 0, len);
                                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((f))->FUN_00472890((char *)(ptr), 0);
                                    if (FUN_00404dc0(ptr, name) == 0)
                                    {
                                        got = true;
                                        while (chunk)
                                        {
                                            if (chunk == 0x434c4358)
                                            {
                                                XCLC v;
                                                ::FUN_00403d30(&v, 0, sizeof(v));
                                                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((f))->FUN_00472890((char *)(void *)(&v), sizeof(v));
                                                if (f->IsEndianConversionRequired())
                                                    reinterpret_cast<::S_00462230 *>(&(v))->FUN_00462230();
                                                *out1 = v.x;
                                                *out2 = v.y;
                                                chunk = 0;
                                            }
                                            else if (f->NextChunk())
                                            {
                                                chunk = reinterpret_cast<::FUN_004726b0_class *>((f))->FUN_004726b0();
                                            }
                                            else
                                            {
                                                chunk = 0;
                                            }
                                        }
                                    }
                                    FUN_00401030(ptr);
                                }
                                read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                            }
                            else
                            {
                                bool flag = false;
                                if (hdr->type == (unsigned int)(*reinterpret_cast<int *>(&::fnv_00543df0::kGroupFormType)))
                                {
                                    switch (hdr->fC)
                                    {
                                    case 0:
                                        if (hdr->f8 == (unsigned int)(*reinterpret_cast<int *>((void *)&::fnv_00543f50::str_01187314)))
                                        {
                                            read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                                            flag = true;
                                        }
                                        else
                                        {
                                            unsigned char c = (unsigned char)FindFormEnumIndex(hdr->f8);
                                            if (c > 0x41)
                                            {
                                                read2 = false;
                                                flag = true;
                                            }
                                        }
                                        break;
                                    case 1:
                                    case 4:
                                    case 5:
                                        read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                                        flag = true;
                                        break;
                                    case 6:
                                        read2 = f->IsGroupOpen();
                                        flag = true;
                                        break;
                                    }
                                }
                                if (0)
                                {
                                }
                            }
                            if (read2)
                                hdr = f->GetRecordHeader();
                            else
                                hdr = 0;
                        }
                    }
                    reinterpret_cast<::FUN_00471130_shell *>((f))->FUN_00471130();
                    if (!got)
                        result = 0;
                    else
                        break;
                }
            }
        }
    }
    return result;
}

#include "generated/data/staging/blk_00460000_od.inc"
#include "generated/data/staging/blk_00460000_od_rtti_variant.inc"
