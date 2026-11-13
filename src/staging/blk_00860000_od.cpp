#include "AutoMemContext.h"

// src/staging/blk_00860000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include "fnv/ni_allocator.h"
#include "fnv/game_timer.h"
#include <cstddef>
#include <windows.h>
#include <new>
#include <cstdio>
#include "fnv/decl/Actor.h"
#include "fnv/decl/Actor8c30.h"
#include "fnv/decl/ActorExtraShell.h"
#include "fnv/decl/ActorValueModifierList.h"
#include "fnv/decl/B01130Task.h"
#include "fnv/decl/BGSLoadFormBuffer.h"
#include "fnv/decl/BSFileCache.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CameraState4E9.h"
#include "fnv/decl/ControlsIniLoader.h"
#include "fnv/decl/CrimeProcess.h"
#include "fnv/decl/Date.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/F8660Owner.h"
#include "fnv/decl/FUN_00404f00_shell.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_00418890_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_0044f650.h"
#include "fnv/decl/FUN_0044f700.h"
#include "fnv/decl/FUN_0044fb00_Shim.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_004a1040_Helper.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_004dc020_Class.h"
#include "fnv/decl/FUN_004ebbc0_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_005b6cb0_Class.h"
#include "fnv/decl/FUN_005b9f80.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_0064da80_Class.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_006c6200_cls.h"
#include "fnv/decl/FUN_006ec390_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00856350_shell.h"
#include "fnv/decl/FUN_00869b70_Class.h"
#include "fnv/decl/FUN_00871d10_t.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_008bbdb0_shell.h"
#include "fnv/decl/FUN_008bbe00_shell.h"
#include "fnv/decl/FUN_008c4400_shell.h"
#include "fnv/decl/FUN_008c5090_shell.h"
#include "fnv/decl/FUN_00906050_Class.h"
#include "fnv/decl/FUN_00936aa0_shell.h"
#include "fnv/decl/FUN_0093a660_class.h"
#include "fnv/decl/FUN_00967350_shell.h"
#include "fnv/decl/FUN_0096e6f0_shell.h"
#include "fnv/decl/FUN_00aa54a0_s.h"
#include "fnv/decl/FUN_00b65ec0_cls.h"
#include "fnv/decl/FUN_00c3e310_shell.h"
#include "fnv/decl/FUN_00c3e340_cls.h"
#include "fnv/decl/FUN_00ec1680_cls.h"
#include "fnv/decl/FalloutAudioMedia.h"
#include "fnv/decl/H_00ba39a0.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/ImageSpaceManager.h"
#include "fnv/decl/InputManagerClose.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/MouseInputStandIn.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/S00b66050_cls.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/StateMachine.h"
#include "fnv/decl/SummonOwner.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESObjectREFR8B3.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Twin_0086cf00.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/bhkEntityListener_shell.h"
#include "fnv/decl/fnv_00404f70__FUN_00404f70_shell.h"
#include "fnv/decl/fnv_00449030__FUN_00449030Class.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008637a0__MyMap.h"
#include "fnv/decl/fnv_008638c0__Holder.h"
#include "fnv/decl/fnv_008639c0__Holder.h"
#include "fnv/decl/fnv_008665b0__FUN_008665b0_shell.h"
#include "fnv/decl/fnv_00871c90__FUN_00871c90_shell.h"
#include "fnv/decl/fnv_0087d230__FUN_0087d230.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_008a06c0__ActorX.h"
#include "fnv/decl/fnv_0092ed60__FNVCurrent.h"
#include "fnv/decl/fnv_0096f600__FUN_0096f600_shell.h"
#include "fnv/decl/fnv_00976680__Host.h"
#include "fnv/decl/fnv_00a22e10__S_00a22e10_Cls.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/reconstruct_c5a9d0__Tail.h"
#include "fnv/decl/s44b130__Lock.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00442000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_0044f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_005e3000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_006e6000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_007fd000.h"
#include "fnv/symbols_0082d000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00835000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00866000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00869000.h"
#include "fnv/symbols_0086c000.h"
#include "fnv/symbols_00877000.h"
#include "fnv/symbols_0087b000.h"
#include "fnv/symbols_0087f000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00af5000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0105c000.h"
#include "fnv/symbols_01082000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/symbols_01400000.h"
#include "../../include/layout_support.h"

extern int DAT_01081fa0;
struct FUN_00863e00_cls
{
    virtual void vfn();
    void FUN_008641d0(int a, int b);
    int* FUN_00863e00(int a, int b);
};
struct FUN_008640e0_class
{
    char pad[0x4];
    void** unk04;
    void DestroyAndFreeBuffer();
    void FUN_008640e0();
};
// @fnv 0x008640e0
void FUN_008640e0_class::FUN_008640e0()
{
    DestroyAndFreeBuffer();
}

struct FUN_00865900_Class
{
};

struct FUN_00865870_Class
{
    char pad[0xc];
    FUN_00865900_Class unk0c;
    void FUN_00865870();
};

struct FUN_00865980_class
{
    void* FUN_00865980();
};

struct CF_0081c630
{
    CF_0081c630();
};

struct FUN_008659a0_Class
{
    int a;
    int b;
    CF_0081c630 member;
    FUN_008659a0_Class();
};
// @fnv 0x00865980
void* FUN_00865980_class::FUN_00865980()
{
    new ((void *)this) ::FUN_008659a0_Class();
    return this;
}

// @fnv 0x008659a0
FUN_008659a0_Class::FUN_008659a0_Class()
{}


struct FUN_00866dc0_Class
{
    char pad[0x50];
    char** m_pArr;
    void FUN_00866dc0(int idx);
};

// @fnv 0x00866dc0
void FUN_00866dc0_Class::FUN_00866dc0(int aiIndex)
{
    SignalAtOffset18(*(m_pArr + aiIndex));
}

extern int DAT_011de804;

// @fnv 0x00869180
bool __cdecl HasFlags(int flags)
{
    return (DAT_011de804 & flags) ? true : false;
}

struct FUN_008693f0_Class
{
    char pad[0xa];
    unsigned short unk0a;
    void FUN_008693f0(std::intptr_t aiParam);
};


// @fnv 0x008696c0
void __cdecl FUN_008696c0(void* apMemory)
{
    void* q = apMemory;
    ::FUN_00401030(q);
}

extern int DAT_010827f0;

struct FUN_00869a40_Class
{
    void* m_ppVirtualMethodTable;
    void* m_field;
    void FUN_00869a40();
};

// @fnv 0x00869a40
void FUN_00869a40_Class::FUN_00869a40()
{
    m_ppVirtualMethodTable = &DAT_010827f0;
    ::FUN_008696c0(m_field);
}

extern int DAT_01082800;
struct FUN_00869b90_cls
{
    const void* vtbl;
    void* next;
    void InitializeAndReleaseNext();
};
// Sets the object's vtbl to DAT_01082800 and passes next to FUN_008696c0.
// @fnv 0x00869b90
void FUN_00869b90_cls::InitializeAndReleaseNext()
{
    vtbl = &DAT_01082800;
    ::FUN_008696c0(next);
}

extern void* DAT_01082808;
struct FUN_00869d40;
struct FUN_00869c60
{
    void* vfn;
    void FUN_00869d40(unsigned int a, unsigned int b);
    FUN_00869c60(unsigned int a, unsigned int b);
};

// Calls FUN_00869d40 with the two arguments, then sets vfn to point at DAT_01082808.
// @fnv 0x00869c60
FUN_00869c60::FUN_00869c60(unsigned int auiFirst, unsigned int auiSecond)
{
    FUN_00869d40(auiFirst, auiSecond);
    vfn = &DAT_01082808;
}

struct FUN_00869cc0_class
{
    void FUN_00869cc0();
};

extern int DAT_01082810;
struct FUN_00869ce0_cls
{
    const void* vtbl;
    void* field4;
    void FUN_00869ce0();
};
// @fnv 0x00869cc0
void FUN_00869cc0_class::FUN_00869cc0()
{
    reinterpret_cast<::FUN_00869ce0_cls *>(this)->FUN_00869ce0();
}
// Sets the vtable pointer to DAT_01082810 and calls FUN_008696c0 with field4.
// @fnv 0x00869ce0
void FUN_00869ce0_cls::FUN_00869ce0()
{
    vtbl = &DAT_01082810;
    ::FUN_008696c0(field4);
}

extern int DAT_01082820;

struct FUN_00869e30_class
{
    void* p;
    int f;
    void FUN_00869e30();
};

// Sets p to point at DAT_01082820 and calls FUN_004b0220 with f.
// @fnv 0x00869e30
void FUN_00869e30_class::FUN_00869e30()
{
    p = &DAT_01082820;
    FUN_004b0220(f);
}

struct CountingSemaphore
{
};
struct FUN_0086c600_shell
{
    char pad[0x14];
    CountingSemaphore unk14;
    void SignalAtOffset();
};
// @fnv 0x0086c600
void FUN_0086c600_shell::SignalAtOffset()
{
    reinterpret_cast<::FUN_00442550_shell *>(((&unk14)))->ReleaseAndInitScriptRunLock();
}

namespace fnv_0086cdd0 {
struct CountingSemaphore
{
};
struct FUN_0086cdd0
{
    char pad[0x14];
    CountingSemaphore unk14;
    void Wait();
};

// @fnv 0x0086cdd0
void FUN_0086cdd0::Wait()
{
    reinterpret_cast<::SemaphoreWaitReceiver *>(((&unk14)))->FUN_004424e0();
}
}  // namespace fnv_0086cdd0

struct ImageSpaceTexture
{
};

struct FUN_00876a00_Class
{
    char pad[0x7c];
    ImageSpaceTexture unk7c;
    void FUN_00876a00();
};

// @fnv 0x00876a00
void FUN_00876a00_Class::FUN_00876a00()
{
    reinterpret_cast<::H_00ba39a0 *>(((&unk7c)))->FUN_00ba39a0();
}

struct FUN_00877a10_Class
{
    void FUN_00877a10();
};

// @fnv 0x00877a10
void FUN_00877a10_Class::FUN_00877a10()
{
    reinterpret_cast<::FUN_0044f650 *>(this)->FUN_0044f650::~FUN_0044f650();
}


struct FUN_00877b40
{
    void Init();
};

extern int DAT_01082f44;

struct FUN_00877b60_Class
{
    void SetVtable();
};
// @fnv 0x00877b40
void FUN_00877b40::Init()
{
    *(void**)this = &DAT_01082f24;
    reinterpret_cast<::FUN_00877b60_Class *>(this)->SetVtable();
}

// @fnv 0x00877b60
void FUN_00877b60_Class::SetVtable()
{
    *reinterpret_cast<const void**>(this) = &DAT_01082f44;
}

struct FUN_00877d30_Class
{
    char pad[0x40];
    char unk40;
    void FUN_00877d30();
};

// @fnv 0x00877d30
void FUN_00877d30_Class::FUN_00877d30()
{
    unk40 = 1;
}

namespace fnv_00877d80 {
struct BSTCommonMessageQueue
{
    virtual ~BSTCommonMessageQueue();
    int m_04;
    void* FUN_00877df0();
    void* Construct();
};
// Calls FUN_00877df0, installs the vtable pointer at offset 0 and clears the field at offset 4, then returns this.
// @fnv 0x00877d80
void* BSTCommonMessageQueue::Construct()
{
    FUN_00877df0();
    *reinterpret_cast<void**>(this) = &(*reinterpret_cast<int *>(&::DAT_01082f24));
    m_04 = 0;
    return this;
}
}  // namespace fnv_00877d80

extern int DAT_01082f44;

struct FUN_00877df0
{
    void* m_vft;
    FUN_00877df0();
};

// @fnv 0x00877df0
FUN_00877df0::FUN_00877df0()
{
    m_vft = &DAT_01082f44;
}

struct FUN_00878110_Class
{
    char pad[0x134];
    unsigned int unk134;
    unsigned int FUN_00878110();
};

// @fnv 0x00878110
unsigned int FUN_00878110_Class::FUN_00878110()
{
    return unk134;
}

struct FUN_00878130_Class
{
    char pad[0x134];
    int m_0x134;
    int ResetAndGetValue();
};

// Sets the int at offset 0x134 of this object to 0 and returns that value.
// @fnv 0x00878130
int FUN_00878130_Class::ResetAndGetValue()
{
    m_0x134 = 0;
    return m_0x134;
}

namespace fnv_0087a6f0 {
struct FUN_0086c600_shell
{
    void* SignalAtOffset();
};

struct FUN_0087a6f0_shell
{
    char pad[0x4];
    void* unk04;
    void* FUN_0087a6f0();
};

// @fnv 0x0087a6f0
void* FUN_0087a6f0_shell::FUN_0087a6f0()
{
    return reinterpret_cast<FUN_0086c600_shell*>(unk04)->SignalAtOffset();
}
}  // namespace fnv_0087a6f0

struct FUN_0086cdd0_shell
{
    void FUN_0086cdd0();
};
struct FUN_0087a710_shell
{
    int pad;
    FUN_0086cdd0_shell* p;
    void FUN_0087a710();
};
// @fnv 0x0087a710
void FUN_0087a710_shell::FUN_0087a710()
{
    reinterpret_cast<::fnv_0086cdd0::FUN_0086cdd0 *>((p))->Wait();
}

struct FUN_0087a770
{
    void DoWork();
};

// @fnv 0x0087a770
void FUN_0087a770::DoWork()
{
    ::IsFieldCZero((::Dummy_0069b080 *)this);
}

extern int DAT_010840d0;
struct FUN_0087d2c0_class
{
    void* vtable;
    FUN_0087d2c0_class* FUN_0087d2c0();
};
extern int DAT_010840d0;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_0087d320();
};
// @fnv 0x0087d320
void GlobalObject_00869f00::FUN_0087d320()
{
    *reinterpret_cast<const void**>(this) = &DAT_010840d0;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}


struct Caller00822860
{
    void FUN_00822860(unsigned int, bool);
    void* FUN_0087d420();
};

// @fnv 0x0087d420
void* Caller00822860::FUN_0087d420()
{
    *(void**)(this) = (void*)&::reconstruct_c5a9d0::Tail::DAT_010840e4;
    FUN_00822860(0, false);
    return this;
}

struct Arr3520
{
    void* p;
    void RemoveAll(bool);
    void FUN_0087d480();
};


// @fnv 0x0087d480
void Arr3520::FUN_0087d480()
{
    p = &::reconstruct_c5a9d0::Tail::DAT_010840e4;
    reinterpret_cast<::FUN_006c6200_cls *>(this)->FUN_006c6200(true);
}

class BSPackedTask;
struct TaskQueueInterface
{
    void FUN_0087e100(bool argument0);
public:
    static void CopyStringToBuffer(char *, unsigned int, const char *);
public:
    static void ProcessQueuedTask(const ::BSPackedTask &);
public:
    void ProcessPackedTask(const ::BSPackedTask &);
};

// @fnv 0x0087e100
void TaskQueueInterface::FUN_0087e100(bool abFlag)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(abFlag == 0, 0x800000);
}

struct FUN_0087e920_class
{
    char pad[0x60];
    unsigned char unk60;
    bool FUN_0087e920();
};

// @fnv 0x0087e920
bool FUN_0087e920_class::FUN_0087e920()
{
    return unk60 & 4;
}

struct FUN_0087e940_cls
{
    char pad[0x60];
    unsigned char unk60;
    bool FUN_0087e940();
};

// @fnv 0x0087e940
bool FUN_0087e940_cls::FUN_0087e940()
{
    return unk60 & 0x20;
}

struct FUN_0087e960_Class
{
    char pad[0x1b0];
    char unk1b0;
    void SetByteAtOffset1B0(char value);
};

// @fnv 0x0087e960
void FUN_0087e960_Class::SetByteAtOffset1B0(char value)
{
    unk1b0 = value;
}

struct Flt
{
    operator unsigned int();
};

struct FUN_0087e980_class
{
    char pad[0x594];
    char unk594;
    unsigned int FUN_0087e980();
};

// @fnv 0x0087e980
unsigned int FUN_0087e980_class::FUN_0087e980()
{
    return ((Flt*)&unk594)->operator unsigned int();
}

struct FUN_0087ea40_class
{
    char pad[0x5c];
    int unk5c;
    void FUN_0087ea40(int value);
};

// @fnv 0x0087ea40
void FUN_0087ea40_class::FUN_0087ea40(int value)
{
    unk5c = value;
}

struct ABD_005f92d0
{
public:
    bool GetFlag8();
};

struct FUN_0087f480_Class
{
    bool FUN_0087f480();
};

// @fnv 0x0087f480
bool FUN_0087f480_Class::FUN_0087f480()
{
    return reinterpret_cast<::TESActorBaseData *>((void *)(((ABD_005f92d0*)this)))->GetFlag(2);
}

extern void* DAT_01081fa8;

struct FUN_00863f00 : public NiTPointerMap<int, int>
{
    void Init();
};

// Sets the vtable pointer, clears the map with RemoveAll, and frees the pointer stored at offset 8.
// @fnv 0x00863f00
void FUN_00863f00::Init()
{
    *(void**)this = &DAT_01081fa8;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

struct NiRenderer
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
};


// If FUN_0043c4b0 returns a renderer, calls its vfn_8c virtual method, then returns 0.
// @fnv 0x0086a020
int __cdecl FUN_0086a020()
{
    if (::FUN_0043c4b0())
    {
        NiRenderer* renderer = ::FUN_0043c4b0();
        renderer->vfn_8c();
    }
    return 0;
}

struct FUN_00863db0_class
{
    void* vtbl;
    int* items;
    int pad;
    unsigned int count;
    unsigned int cap;
    void ClearItems();
};
// Sets every element of items to 0, then resets count and cap to 0.
// @fnv 0x00863db0
void FUN_00863db0_class::ClearItems()
{
    for (unsigned int i = 0; i < count; ++i)
        items[i] = 0;
    count = 0;
    cap = 0;
}

struct FUN_00863e30_struct
{
    void* m_pVTable;
    unsigned int m_uiCount;
    void** m_pData;
    int m_iPad;
    void* FUN_00863e30(unsigned int ItemUpdateArray);
};
// Sets the vtable, stores the count, allocates count*4 bytes for m_pData, zeroes them, and returns this.
// @fnv 0x00863e30
void* FUN_00863e30_struct::FUN_00863e30(unsigned int auiCount)
{
    m_pVTable = &DAT_01081fa8;
    m_uiCount = auiCount;
    m_iPad = 0;
    unsigned int uiSize = m_uiCount * 4;
    m_pData = static_cast<void**>(::FUN_00aa1070(uiSize));
    ::FUN_00403d30(m_pData, 0, m_uiCount * 4);
    return this;
}

struct FUN_008636a0
{
    void Init();
};
struct FUN_00863f60_cls
{
    void* InitAndMaybeFree(unsigned int flags);
};
// Calls Init on this, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00863f60
void* FUN_00863f60_cls::InitAndMaybeFree(unsigned int flags)
{
    ((FUN_008636a0*)this)->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_008637a0_class
{
    void FUN_008637a0();
};
struct FUN_00863f90_class
{
    void FUN_008637a0();
    void* FUN_00863f90(unsigned int flags);
};
// @fnv 0x00863f90
void* FUN_00863f90_class::FUN_00863f90(unsigned int flags)
{
    reinterpret_cast<::fnv_008637a0::MyMap *>(this)->FUN_008637a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_008638c0_Class
{
    void* FUN_00863fc0(unsigned int flags);
};
// Calls FUN_008638c0, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00863fc0
void* FUN_008638c0_Class::FUN_00863fc0(unsigned int flags)
{
    reinterpret_cast<::fnv_008638c0::Holder *>(this)->FUN_008638c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00863ff0_class
{
    void* FUN_00863ff0(unsigned int flags);
};
// @fnv 0x00863ff0
void* FUN_00863ff0_class::FUN_00863ff0(unsigned int flags)
{
    reinterpret_cast<::fnv_008639c0::Holder *>(this)->FUN_008639c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NiTPointerMap_Standin
{
    void ClearAndFree();
};
struct FUN_00864020_Class
{
    void* FUN_00864020(unsigned int flags);
};
// @fnv 0x00864020
void* FUN_00864020_Class::FUN_00864020(unsigned int flags)
{
    reinterpret_cast<NiTPointerMap_Standin*>(this)->ClearAndFree();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00863d60_obj
{
    void FUN_00863d60();
};

struct FUN_00864050_class
{
    void* FUN_00864050(unsigned int flags);
};

// @fnv 0x00864050
void* FUN_00864050_class::FUN_00864050(unsigned int flags)
{
    reinterpret_cast<FUN_00863d60_obj*>(this)->FUN_00863d60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00857350_obj
{
    void FUN_00857350();
};
struct FUN_00864080_shell
{
    void* FUN_00864080(unsigned int flags);
};
// @fnv 0x00864080
void* FUN_00864080_shell::FUN_00864080(unsigned int flags)
{
    ((FUN_00857350_obj*)this)->FUN_00857350();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_008640b0_Class
{
    void* FUN_008640b0(unsigned int flags);
};
// Calls Init on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x008640b0
void* FUN_008640b0_Class::FUN_008640b0(unsigned int flags)
{
    reinterpret_cast<FUN_00863f00*>(this)->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00864130_Class
{
    void* FUN_00864130(unsigned int flags);
};
// @fnv 0x00864130
void* FUN_00864130_Class::FUN_00864130(unsigned int flags)
{
    ((FUN_008640e0_class*)this)->DestroyAndFreeBuffer();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// If DAT_0126fac4 is set, calls its first virtual method with 1, then clears DAT_0126fac4.
// @fnv 0x00867090
void __cdecl FUN_00867090()
{
    void* p = (*reinterpret_cast<void * *>(&::DAT_0126fac4));
    void* RunFourthVirtual = p;
    void* result;
    if (RunFourthVirtual)
        result = ((void*(*)(void*, int)) * ((void***)RunFourthVirtual)[0])(RunFourthVirtual, 1);
    else
        result = 0;
    (*reinterpret_cast<void * *>(&::DAT_0126fac4)) = 0;
}

struct FUN_008677d0_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
// @fnv 0x008677d0
void* FUN_008677d0(void* p)
{
    FUN_008677d0_Object* object = static_cast<FUN_008677d0_Object*>(p);
    object->unk00 = 0;
    object->unk04 = 0;
    object->unk08 = 0;
    object->unk0c = 0;
    object->unk10 = 0;
    object->unk14 = 0;
    object->unk18 = 0;
    FUN_00867a20(p);
    ::ZeroSixInts((int *)(p));
    return p;
}

// Writes zero to the six consecutive ints starting at p.
// @fnv 0x00867840
void ZeroSixInts(int* piValues)
{
    piValues[0] = 0;
    piValues[1] = 0;
    piValues[2] = 0;
    piValues[3] = 0;
    piValues[4] = 0;
    piValues[5] = 0;
}

struct FUN_00869600_Class
{
    char pad[0xc];
    unsigned int unk0c;
    unsigned int FUN_00869600();
};

// @fnv 0x00869600
unsigned int FUN_00869600_Class::FUN_00869600()
{
    return unk0c > 0x800 ? unk0c - 0x400
                                                       : unk0c >> 1;
}

struct FUN_00869a20_class
{
    void* FUN_00869a70(unsigned int flags);
public:
    void FUN_00869a20();
};
// @fnv 0x00869a70
void* FUN_00869a20_class::FUN_00869a70(unsigned int flags)
{
    reinterpret_cast<::FUN_00869a40_Class *>(this)->FUN_00869a40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GlobalObject_00869b10
{
    GlobalObject_00869b10* FUN_00869b40(unsigned int flags);
    ~GlobalObject_00869b10();
};
// Calls FUN_00869b70, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00869b40
GlobalObject_00869b10* GlobalObject_00869b10::FUN_00869b40(unsigned int flags)
{
    reinterpret_cast<::FUN_00869b70_Class *>(this)->FUN_00869b70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct GlobalObject_00869c60
{
    virtual void vfn();
    GlobalObject_00869c60* FUN_00869c90(unsigned int flags);
};

// @fnv 0x00869c90
GlobalObject_00869c60* GlobalObject_00869c60::FUN_00869c90(unsigned int flags)
{
    reinterpret_cast<::FUN_00869cc0_class *>(this)->FUN_00869cc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00869d10_cls
{
    FUN_00869d10_cls* FUN_00869d10(unsigned int flags);
};
// Calls FUN_00869ce0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00869d10
FUN_00869d10_cls* FUN_00869d10_cls::FUN_00869d10(unsigned int flags)
{
    reinterpret_cast<::FUN_00869ce0_cls *>(this)->FUN_00869ce0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00869e10_class
{
    void* FUN_00869e60(unsigned int flags);
public:
    void FUN_00869e10();
};

// @fnv 0x00869e60
void* FUN_00869e10_class::FUN_00869e60(unsigned int flags)
{
    reinterpret_cast<::FUN_00869e30_class *>(this)->FUN_00869e30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0086bff0
void FUN_0086bff0(float(__cdecl* fn)(int))
{
    DAT_011f91f0 = fn;
}

extern bool DAT_011f94a7;

// @fnv 0x0086c000
void FUN_0086c000(bool abUseCache)
{
    DAT_011f94a7 = abUseCache;
}

struct GlobalObject_0044f440
{
};
// @fnv 0x0086c0c0
void FUN_0086c0c0()
{
    reinterpret_cast<::FUN_00450410_Class *>(&(::g_011c72a0))->FUN_00450410();
}

namespace fnv_0086c0d0 {
struct GlobalObject_0044f440
{
};

// @fnv 0x0086c0d0
void __cdecl FUN_0086c0d0()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c0d0::GlobalObject_0044f440 *>(&::g_011c774c))))->FUN_00450410();
}
}  // namespace fnv_0086c0d0

namespace fnv_0086c0e0 {
struct GlobalObject_0044f440
{
};

// @fnv 0x0086c0e0
void __cdecl FUN_0086c0e0()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c0e0::GlobalObject_0044f440 *>(&::g_011c7314))))->FUN_00450410();
}
}  // namespace fnv_0086c0e0

namespace fnv_0086c0f0 {
struct GlobalObject_0044f440
{
};
// @fnv 0x0086c0f0
void FUN_0086c0f0()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c0f0::GlobalObject_0044f440 *>(&::g_011c768c))))->FUN_00450410();
}
}  // namespace fnv_0086c0f0

namespace fnv_0086c100 {
struct GlobalObject_0044f440
{
};
// @fnv 0x0086c100
void FUN_0086c100()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c100::GlobalObject_0044f440 *>(&::g_011c7758))))->FUN_00450410();
}
}  // namespace fnv_0086c100

namespace fnv_0086c110 {
struct GlobalObject_0044f440
{
};

// @fnv 0x0086c110
void __cdecl FUN_0086c110()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c110::GlobalObject_0044f440 *>(&::g_011c75bc))))->FUN_00450410();
}
}  // namespace fnv_0086c110

namespace fnv_0086c120 {
struct GlobalObject_0044f440
{
};

// @fnv 0x0086c120
void __cdecl FUN_0086c120()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c120::GlobalObject_0044f440 *>(&::g_011c7458))))->FUN_00450410();
}
}  // namespace fnv_0086c120

namespace fnv_0086c130 {
struct GlobalObject_0044f440
{
};
GlobalObject_0044f440 g_011c74a0;
// @fnv 0x0086c130
void FUN_0086c130()
{
    reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_0086c130::GlobalObject_0044f440 *>(&::g_011c74a0))))->FUN_00450410();
}
}  // namespace fnv_0086c130

extern float DAT_011ff8ac;

// @fnv 0x0086c140
void FUN_0086c140(float value)
{
    DAT_011ff8ac = value;
}

extern float DAT_011ff8b0;
// @fnv 0x0086c150
void __cdecl FUN_0086c150(float value)
{
    DAT_011ff8b0 = value;
}

class MessageHandler
{
  public:
    unsigned char unk04;
    static MessageHandler* pHandler;
    virtual ~MessageHandler();
};

// Deletes the global MessageHandler instance if it exists and its byte at offset 4 is zero.
// @fnv 0x0086cd80
void __cdecl DestroyMessageHandler()
{
    if (MessageHandler::pHandler && !MessageHandler::pHandler->unk04)
        delete MessageHandler::pHandler;
}

extern unsigned char DAT_011f9fc5;
// @fnv 0x00872df0
void FUN_00872df0(unsigned char value)
{
    DAT_011f9fc5 = value;
}

extern void* DAT_01204368;
void __cdecl FUN_00877960();
// @fnv 0x00877950
void* __cdecl FUN_00877950()
{
    FUN_00877960();
    return DAT_01204368;
}

void __cdecl FUN_00877ac0();
struct FUN_00877d50_Class
{
    void FUN_00877ac0();
    void* FUN_00877d50(unsigned int flags);
};
struct StrArr
{
};
struct FUN_00877e10_Class
{
    char pad[0x8];
    unsigned short unk08;
    char pad0a[0x4];
    unsigned short unk0e;
    unsigned int FUN_00877e10(unsigned int a, std::uintptr_t b);
};
struct GlobalObject_00877f10
{
    ~GlobalObject_00877f10();
    void* FUN_00877f90(unsigned int flags);
};

extern int DAT_011a95fc;

// @fnv 0x008781e0
void FUN_008781e0(int value)
{
    DAT_011a95fc = value;
}

class TESSound
{
};
struct FUN_00878f20_shell
{
    int pad[4];
    Flt f;
    uintptr_t DeallocateSound();
};
// If the stored float converts to a nonzero pointer, calls TESSound::Deallocate on it and returns the result; otherwise returns 0.
// @fnv 0x00878f20
uintptr_t FUN_00878f20_shell::DeallocateSound()
{
    if (f.operator unsigned int())
        return ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESSound*>(f.operator unsigned int())))->FUN_0084e3a0()));
    else
        return 0;
}

struct FUN_00879860_Class
{
    char pad[0x308];
    float unk308;
    float unk30c;
    float unk310;
    float unk314;
    void FUN_00879860(float a, float b, float c, float d);
};
// Stores the four float arguments into the object's fields at offsets 0x308, 0x30c, 0x310 and 0x314.
// @fnv 0x00879860
void FUN_00879860_Class::FUN_00879860(float a, float b, float c, float d)
{
    unk308 = a;
    unk30c = b;
    unk310 = c;
    unk314 = d;
}

struct FUN_008798a0_Class
{
    char pad[0x308];
    float unk308;
    float unk30c;
    float unk310;
    float unk314;
    void FUN_008798a0();
};

// Sets four floats at offsets 0x308-0x314 of this object to 0.0, 1.0, 1.0, 0.0.
// @fnv 0x008798a0
void FUN_008798a0_Class::FUN_008798a0()
{
    unk308 = 0.0f;
    unk30c = 1.0f;
    unk310 = 1.0f;
    unk314 = 0.0f;
}

struct FUN_0087a670_shell
{
    char pad[0x4];
    int unk04;
    int unk08;
    int unk0c;
    int* FUN_0087a670(int a, int b);
};

// Stores a at offset 0, b at offset 4, sets offset 12 to 0 and offset 8 to the value at offset 0, then returns this.
// @fnv 0x0087a670
int* FUN_0087a670_shell::FUN_0087a670(int aiFirst, int aiSecond)
{
    *(int*)this = aiFirst;
    unk04 = aiSecond;
    unk0c = 0;
    unk08 = *(int*)this;
    return (int*)this;
}

struct GlobalObject_0087d420
{
    ~GlobalObject_0087d420();
    GlobalObject_0087d420* FUN_0087d450(unsigned int flags);
};
// Runs the destructor, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0087d450
GlobalObject_0087d420* GlobalObject_0087d420::FUN_0087d450(unsigned int flags)
{
    reinterpret_cast<::Arr3520 *>(this)->FUN_0087d480();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class BGSSaveLoadManager
{
};
struct FUN_008660b0_shell
{
    int vtbl;
    int* data;
    unsigned int size;
    void GrowBuffer();
};
// @fnv 0x008660b0
void FUN_008660b0_shell::GrowBuffer()
{
    int* old = data;
    unsigned int oldSize = size;
    size += 0x10000;
    if (!((unsigned char)(reinterpret_cast<::FUN_00424940_shell *>((DAT_011de134))->FUN_00424940())))
    {
        int* alloc3 = (int*)::FUN_00401000(size);
        data = alloc3;
        if (old)
        {
            __memcpy(data, old, oldSize);
        }
        int* tmp = old;
        ::FUN_00401030(tmp);
    }
}

void** __cdecl AllocateUIntArray(unsigned int);

struct FUN_00869aa0
{
    void* vtbl;
    void* data;
    unsigned short w0;
    unsigned short w1;
    unsigned short w2;
    unsigned short w3;
    unsigned short w4;
    FUN_00869aa0(unsigned short a, unsigned short b);
};

// @fnv 0x00869aa0
FUN_00869aa0::FUN_00869aa0(unsigned short a, unsigned short b)
{
    vtbl = &DAT_010827f0;
    w0 = a;
    w3 = b;
    w1 = 0;
    w2 = 0;
    if (w0 > 0)
        data = AllocateUIntArray(w0);
    else
        data = 0;
}

struct FUN_00869bf0
{
    int* vtbl;
    void* data;
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
    unsigned short fe;
    FUN_00869bf0(unsigned short a, unsigned short b);
};
// @fnv 0x00869bf0
FUN_00869bf0::FUN_00869bf0(unsigned short a, unsigned short b)
{
    vtbl = &DAT_01082800;
    f8 = a;
    fe = b;
    fa = 0;
    fc = 0;
    if (f8 > 0)
        data = ::AllocateUIntArray(f8);
    else
        data = 0;
}

namespace fnv_00869d40 {

struct FUN_00869d40
{
    void* vtbl;
    void* data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    FUN_00869d40(unsigned int aiA, unsigned int aiB);
};
// @fnv 0x00869d40
FUN_00869d40::FUN_00869d40(unsigned int aiA, unsigned int aiB)
{
    vtbl = &DAT_01082810;
    a = aiA;
    d = aiB;
    b = 0;
    c = 0;
    if (a > 0)
        data = ::AllocateUIntArray(a);
    else
        data = 0;
}
}  // namespace fnv_00869d40

struct ActorCombatGroup
{
    int pad;
};
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned int);
};
extern int DAT_01081fc8;
struct FUN_00864160
{
    void* m_vtbl;
    ActorCombatGroup** m_pData;
    unsigned int m_uiCount;
    int m_uiPad;
    int m_uiAlloc;
    int m_iExtra;
    FUN_00864160(unsigned int ItemUpdateArray, int iExtra);
};
// Sets the vtable, stores the count and extra value, zeroes the pad and alloc fields, and allocates the data array when the count is positive.
// @fnv 0x00864160
FUN_00864160::FUN_00864160(unsigned int ItemUpdateArray, int iExtra)
{
    m_vtbl = (void*)&DAT_01081fc8;
    m_uiCount = ItemUpdateArray;
    m_iExtra = iExtra;
    m_uiPad = 0;
    m_uiAlloc = 0;
    if (m_uiCount > 0)
        m_pData = NiTMallocInterface_0096afc0::Allocate(m_uiCount);
    else
        m_pData = 0;
}

struct TESGlobal
{
};
class TESForm;
struct FUN_00867890_shell
{
    TESForm* f0;
    TESForm* f1;
    TESForm* f2;
    TESForm* f3;
    TESForm* f4;
    TESForm* f5;
    int f6;
    void FUN_00867890();
};
// Looks up six forms by id, adds the f3 global's value divided by 24 to the f4 global, stores it, resets f6 and calls FUN_00867a20.
// @fnv 0x00867890
void FUN_00867890_shell::FUN_00867890()
{
    f0 = ::FUN_004839c0(0x35);
    f1 = ::FUN_004839c0(0x36);
    f2 = ::FUN_004839c0(0x37);
    f3 = ::FUN_004839c0(0x38);
    f4 = ::FUN_004839c0(0x39);
    f5 = ::FUN_004839c0(0x3a);
    float b = reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobal*)f3)))->FUN_00526ac0();
    float a = reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobal*)f4)))->FUN_00526ac0();
    a = b / 24.0 + a;
    reinterpret_cast<::FUN_0046dce0_class *>((((TESGlobal*)f4)))->FUN_0046dce0(a);
    f6 = 0;
    ::FUN_00867a20((void *)this);
}

struct GO
{
    unsigned int m_uiData;
    GO(unsigned int* p);
    ~GO();
    operator unsigned int() const;
};
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int i);
};
// Iterates pArr, wraps each element in a GO, and passes it to pDest->FUN_008693f0 only when the GO converts to a non-zero value.
// @fnv 0x00869560
void FUN_00869560(Arr* pArr, FUN_008693f0_Class* pDest)
{
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>((pArr))->GetShortAtOffsetA(); i++)
    {
        GO sp(pArr->GetAt(i));
        if ((unsigned int)sp)
            pDest->FUN_008693f0((std::intptr_t)&sp);
    }
}

struct FUN_00869e90_Class
{
    int* vtbl;
    char** p;
    unsigned short count;
    unsigned short pad;
    unsigned short w0;
    unsigned short w1;
    FUN_00869e90_Class(unsigned short, unsigned short);
};
// @fnv 0x00869e90
FUN_00869e90_Class::FUN_00869e90_Class(unsigned short ausCount, unsigned short b)
{
    vtbl = &DAT_01082820;
    count = ausCount;
    w1 = b;
    pad = 0;
    w0 = 0;
    if (count > 0)
        p = FUN_005e0ba0(count);
    else
        p = 0;
}

struct FUN_008779f0
{
    char data[0x114];
    FUN_008779f0();
};
extern void* DAT_01204368;
// Allocates a FUN_008779f0 instance and stores it in DAT_01204368 if that global is currently null.
// @fnv 0x00877960
void FUN_00877960()
{
    if (!DAT_01204368)
        DAT_01204368 = new FUN_008779f0;
}

extern int DAT_01082f04;
struct FUN_00877d80_Class
{
};
struct FUN_00877a80_Class : FUN_00877d80_Class
{
    char pad[0x8];
    int unk08;
    int unk0c;
    void* unk10;
    void* InitWithValue(int a);
};
// Calls the base initializer, installs DAT_01082f04 as the vtable, stores a at offset 8, and sets offset 12 to 0 with offset 16 pointing to it.
// @fnv 0x00877a80
void* FUN_00877a80_Class::InitWithValue(int aiValue)
{
    reinterpret_cast<::fnv_00877d80::BSTCommonMessageQueue *>(this)->Construct();
    *(const void**)this = &DAT_01082f04;
    unk08 = aiValue;
    unk0c = 0;
    unk10 = (char*)&unk0c;
    return this;
}

struct FUN_00877e50_Class
{
    int m_pVTable;
    int* m_pData;
    unsigned short m_usPad;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    void SetEntry(unsigned int index, int* value);
};
// @fnv 0x00877e10
unsigned int FUN_00877e10_Class::FUN_00877e10(unsigned int a, std::uintptr_t b)
{
    if (a >= unk08)
        reinterpret_cast<::ViewerStrings *>((reinterpret_cast<StrArr*>(this)))->SetSize(unk0e + a);
    reinterpret_cast<::FUN_00877e50_Class *>(this)->SetEntry(a, (int *)(b));
    return a;
}
// @fnv 0x00877e50
void FUN_00877e50_Class::SetEntry(unsigned int index, int* piValue)
{
    if (index >= m_usSize)
    {
        m_usSize = index + 1;
        if (*piValue != (*reinterpret_cast<int *>((void *)&::DAT_01011d78)))
            m_usElementCount++;
    }
    else
    {
        if (*piValue != (*reinterpret_cast<int *>((void *)&::DAT_01011d78)))
        {
            if (m_pData[index] == (*reinterpret_cast<int *>((void *)&::DAT_01011d78)))
                m_usElementCount++;
        }
        else if (m_pData[index] != (*reinterpret_cast<int *>((void *)&::DAT_01011d78)))
        {
            m_usElementCount--;
        }
    }
    m_pData[index] = *piValue;
}

struct TgtOps
{
};
struct FUN_005e0830
{
    bool Open(const char*, bool);
};
struct FUN_008798e0_shell : TgtOps
{
    bool OpenAtPosition();
};
// @fnv 0x008798e0
bool FUN_008798e0_shell::OpenAtPosition()
{
    bool result = false;
    void* position = ((void *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    if (position)
    {
        result = ((FUN_005e0830*)this)->Open((const char*)position, true);
        if (result)
        {
            result = ((bool(*)(void*))(*(void***)this)[8])(this);
            ((void(*)(void*))(*(void***)this)[7])(this);
        }
    }
    return result;
}

struct FUN_0087d340_Class
{
    virtual void vfn_00();
    virtual char* vfn_04(unsigned int);
    char* m_pData;
    int m_iSize;
    int m_iCapacity;
    void FUN_0087d340(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x0087d2c0
FUN_0087d2c0_class* FUN_0087d2c0_class::FUN_0087d2c0()
{
    vtable = &DAT_010840d0;
    reinterpret_cast<::FUN_0087d340_Class *>(this)->FUN_0087d340(0, 0);
    return this;
}

struct BSFadeNode
{
    unsigned int FUN_009ad610();
};

struct BSFadeNodeResult
{
    virtual bool vfn_00();
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
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool vfn_100();
};

struct BSFadeNodeResult2 : public BSFadeNodeResult
{
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual float vfn_420();
};

// @fnv 0x0086a050
float __cdecl FUN_0086a050(BSFadeNode* node)
{
    BSFadeNodeResult2* p = (BSFadeNodeResult2*)(std::uintptr_t)node->FUN_009ad610();
    if (p != 0 && p->vfn_100())
    {
        return p->vfn_420();
    }
    return 1.0f;
}

struct FUN_00863f30_shell
{
    void* FUN_00863f30(unsigned int flags);
};

// Calls FUN_008640e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00863f30
void* FUN_00863f30_shell::FUN_00863f30(unsigned int flags)
{
    reinterpret_cast<::FUN_008640e0_class *>(this)->FUN_008640e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// Sets the object's vtable pointer to DAT_01081fc8 and frees the buffer stored at offset 4 via FUN_00864100_Deallocate.
// @fnv 0x00864100
void FUN_008640e0_class::DestroyAndFreeBuffer()
{
    *(const void**)this = &DAT_01081fc8;
    ::FUN_004ede70(unk04);
}

extern int DAT_010822a8;
struct FUN_00865840_class : NiTPointerMap<int, int>
{
    void FUN_00865840();
};
// @fnv 0x00865840
void FUN_00865840_class::FUN_00865840()
{
    *(void**)this = (void*)&DAT_010822a8;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

struct CF845
{
    int value;
    CF845(int);
};

struct FUN_006b8310_class
{
    void FreeMemory(void*);
};

struct FUN_00865890_Class
{
    char pad_0x00[0x0c];
    FUN_006b8310_class member_0x0c;

    void InitAndDispatch(int* param);
};

// Constructs a CF845 with value 0, stores its value into param[2], then calls member_0x0c.FreeMemory(param).
// @fnv 0x00865890
void FUN_00865890_Class::InitAndDispatch(int* piData)
{
    CF845 local(0);
    piData[2] = local.value;
    member_0x0c.FreeMemory(piData);
}

struct FUN_00865840_shell
{
};
struct FUN_008658d0 : FUN_00865840_shell
{
    void* DeleteThis(unsigned int flags);
};
// @fnv 0x008658d0
void* FUN_008658d0::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_00865840_class *>(this)->FUN_00865840();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_01082324;
struct FUN_00865bd0
{
    void* m_vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_00865bd0();
};
// Sets the vtable pointer to DAT_01082324 and zeroes the four integer fields a, b, c and d.
// @fnv 0x00865bd0
FUN_00865bd0::FUN_00865bd0()
{
    m_vtbl = &DAT_01082324;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

struct FUN_00865aa0_shell
{
    void SetFlags(unsigned int value);
};

struct FUN_00853670_shell
{
    void FUN_00853670(int value);
};

unsigned int __cdecl FUN_00845d40(unsigned int value);
unsigned int __cdecl FUN_00845d70(unsigned int value);

struct FUN_008665d0_class
{
    void* m_pData;
    void FUN_008665d0(void* source, unsigned int size, int value, unsigned char flag);
};

// Allocates a buffer sized from size, writes a flag and encoded size/value header, then copies size bytes from source into it.
// @fnv 0x008665d0
void FUN_008665d0_class::FUN_008665d0(void* source, unsigned int size, int value, unsigned char flag)
{
    unsigned int data4 = FUN_00845d40(size);
    unsigned int totalSize = FUN_00845d70(data4);
    unsigned int encodedSize = size + totalSize + 2;
    void* object = ::FUN_00401000(encodedSize);

    this->m_pData = object;

    char* headerSize = reinterpret_cast<char*>(this->m_pData);
    char* destination = headerSize;

    destination[1] = flag;

    reinterpret_cast<FUN_00865aa0_shell*>(destination)->SetFlags(data4);
    reinterpret_cast<FUN_00853670_shell*>(destination)->FUN_00853670(value);

    headerSize += 2;
    WriteTypedValue(headerSize, size, data4);
    headerSize += totalSize;

    __memcpy(headerSize, source, size);
}

struct FUN_00866690_Class
{
    void InitializeGlobal();
};



namespace std {
class StandardLibrarySingletonObject
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04(int, int, int) = 0;
};

template <class T> T& __cdecl _Immortalize();
}

// @fnv 0x00866690
void FUN_00866690_Class::InitializeGlobal()
{
    ::fnv::memory::PublishManagerNiAllocator();

    std::_Immortalize<std::StandardLibrarySingletonObject>().vfn_04(0, 0, 0);
}

__declspec(thread) bool g_tls_0298 = true;

// @fnv 0x00869190
void __cdecl SetTlsFlag(bool value)
{
    g_tls_0298 = value;
}

struct FUN_00869640_StrArr
{
    char pad[0x8];
    unsigned short unk08;
    char pad0a[0x4];
    unsigned short unk0e;
    unsigned int FUN_00869640(unsigned int index, char*& value);
};
struct GlobalObject_008699c0
{
    virtual ~GlobalObject_008699c0();
};
struct FUN_008699f0_class : public GlobalObject_008699c0
{
    void* FUN_008699f0(unsigned int flags);
};
// Runs the base destructor, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008699f0
void* FUN_008699f0_class::FUN_008699f0(unsigned int flags)
{
    reinterpret_cast<::FUN_00869a20_class *>((this))->FUN_00869a20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00869bc0_Class : FUN_00869b90_cls
{
    void* FUN_00869bc0(unsigned int flags);
};

// @fnv 0x00869bc0
void* FUN_00869bc0_Class::FUN_00869bc0(unsigned int flags)
{
    InitializeAndReleaseNext();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GlobalObject_00869db0
{
    ~GlobalObject_00869db0();
    void* FUN_00869de0(unsigned int flags);
};
// Calls FUN_00869e10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00869de0
void* GlobalObject_00869db0::FUN_00869de0(unsigned int flags)
{
    reinterpret_cast<::FUN_00869e10_class *>(this)->FUN_00869e10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl ShutdownInput();
struct FUN_0086c850_shell
{
    void ShutdownInput();
    void* FUN_0086c850(unsigned int flags);
};
// Calls ShutdownInput, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0086c850
void* FUN_0086c850_shell::FUN_0086c850(unsigned int flags)
{
    reinterpret_cast<::InputManagerClose *>(this)->ShutdownInput();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSAudio;
struct RegionPointList;
struct SoundPlaybackManager;
struct TESRecipe;
struct BGSMessage;
struct BGSMenuIcon;
class BGSCameraPath;
struct TES;
class TESSound;

typedef void(__cdecl* AudioCallback)();

void __cdecl FUN_00aea020();
void __cdecl FUN_00832c40();
void __cdecl FUN_0082f830();
bool __cdecl FUN_0082d740(TESSound*, int*, int*);

struct BSAudio
{
    virtual void vfn_00();
    virtual void vfn_04(unsigned int value);
    virtual void vfn_08();
    virtual void vfn_0c(AudioCallback callback);

};

struct RegionPointList
{
};

struct SoundPlaybackManager
{
    static bool __cdecl ResolveSoundFile(char const*, char*, unsigned int*, void**);
};

namespace ActorValue { enum Index; }
struct TESRecipe
{
public:
    void SetRequiredSkill(::ActorValue::Index);
};

struct BGSMessage
{
};

class BGSCameraPath
{
  public:
    void AssignParentPath(BGSCameraPath* value);
};

struct TES
{
};

struct FalloutRadio
{
    static void __cdecl RadioSynchUnPaused();
};

struct FUN_0086ce40_class
{
    int vfn_00;
    int padding_04;
    unsigned int value_08;

    void InitAudioCallbacks();
};

// Registers audio callbacks and a value on the BSAudio singleton, then calls FUN_0082f830.
// @fnv 0x0086ce40
void FUN_0086ce40_class::InitAudioCallbacks()
{
    FUN_00aea020();

    reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((reinterpret_cast<RegionPointList*>(::FUN_00453a70())))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(reinterpret_cast<uintptr_t>(&((void (&)())::GetSoundPathAndFlags))));

    reinterpret_cast<TESRecipe*>(::FUN_00453a70())->SetRequiredSkill((::ActorValue::Index)(reinterpret_cast<intptr_t>(&SoundPlaybackManager::ResolveSoundFile)));

    reinterpret_cast<::FUN_0061cc40_shell *>((reinterpret_cast<TESRecipe*>(::FUN_00453a70())))->FUN_0061cc40((int)reinterpret_cast<std::uintptr_t>(&((void (&)())::FindDialogueFile)));

    reinterpret_cast<::Twin_0086cf00 *>((reinterpret_cast<BGSMessage*>(::FUN_00453a70())))->SetD3DPixelShader((::GeometryRelatedType *const)(reinterpret_cast<BGSMenuIcon*>(&((void (&)())::ApplySoundFormToGameSound))));

    reinterpret_cast<BGSCameraPath*>(::FUN_00453a70())
        ->AssignParentPath(reinterpret_cast<BGSCameraPath*>(&FUN_00832c40));

    reinterpret_cast<::LowProcess *>((reinterpret_cast<TES*>(::FUN_00453a70())))->SetCurrentBoundObject((::TESBoundObject *)(::TESSound *)(reinterpret_cast<TESSound*>(&FalloutRadio::RadioSynchUnPaused)));

    ::FUN_00453a70()->vfn_0c(reinterpret_cast<AudioCallback>(&FUN_0082d740));

    ::FUN_00453a70()->vfn_04(value_08);

    FUN_0082f830();
}

struct NiVisibleArray;
struct FUN_00a69400
{
    FUN_00a69400(NiVisibleArray*);
};
extern void* DAT_01082ccc;
struct FUN_00872ea0 : FUN_00a69400
{
    void* m_vft;
    FUN_00872ea0(NiVisibleArray*);
};
// Constructs the object by forwarding the NiVisibleArray pointer to the base constructor and setting the vtable pointer to DAT_01082ccc.
// @fnv 0x00872ea0
FUN_00872ea0::FUN_00872ea0(NiVisibleArray* apVisibleArray) : FUN_00a69400(apVisibleArray)
{
    m_vft = &DAT_01082ccc;
}

extern int DAT_01082ed8;
struct FUN_0044f600_class
{
};
struct FUN_008779f0_class : FUN_0044f600_class
{
    FUN_008779f0_class();
};
// @fnv 0x008779f0
FUN_008779f0_class::FUN_008779f0_class()
{
    new ((void *)this) ::FUN_0044f700();
    *reinterpret_cast<void**>(this) = &DAT_01082ed8;
}

struct FUN_00877b40_Delete : FUN_00877b40
{
    void* FUN_00877b80(unsigned int flags);
};
// Calls Init, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00877b80
void* FUN_00877b40_Delete::FUN_00877b80(unsigned int flags)
{
    Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00877bb0 : FUN_00877b40
{
    void* DeleteThis(unsigned int flags);
};
// Calls SetVtable, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00877bb0
void* FUN_00877bb0::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_00877b60_Class *>(this)->SetVtable();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00878360_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned int m_10;
    bool FUN_00878360();
};
// Returns true unless m_10 exceeds m_08 and the difference is greater than 0x00500000.
// @fnv 0x00878360
bool FUN_00878360_Class::FUN_00878360()
{
    bool b = true;
    if (m_10 > m_08 && (m_10 - m_08) > 0x00500000u)
        b = false;
    return b;
}

unsigned int __cdecl gm_GetCurrentThreadId(void);

struct PackedTaskQueueProcessor
{
    void Process();
};

struct FUN_0087a790_class
{
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;
    unsigned int m_uiTaskFlags;

    void FUN_0087a790();
};

// @fnv 0x0087a790
void FUN_0087a790_class::FUN_0087a790()
{
    m_pTaskQueueProcessor = m_pSecondaryTaskProcessor;
    m_uiTaskFlags = gm_GetCurrentThreadId();
    m_pPrimaryTaskProcessor->Process();
    m_uiTaskFlags = 0;
}

struct BSScrapArray_NiPointer_NiAVObject_1024
{
    ~BSScrapArray_NiPointer_NiAVObject_1024();
    void* FUN_0087d290(unsigned int flags);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x0087d290
void* BSScrapArray_NiPointer_NiAVObject_1024::FUN_0087d290(unsigned int flags)
{
    reinterpret_cast<::fnv_0087d230::FUN_0087d230 *>((this))->fnv_0087d230::FUN_0087d230::~FUN_0087d230();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GlobalObject_0087d2c0
{
    void* vtable;
    ~GlobalObject_0087d2c0();
    GlobalObject_0087d2c0* FUN_0087d2f0(unsigned int flags);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this, returning the pointer.
// @fnv 0x0087d2f0
GlobalObject_0087d2c0* GlobalObject_0087d2c0::FUN_0087d2f0(unsigned int flags)
{
    reinterpret_cast<::GlobalObject_00869f00 *>((this))->FUN_0087d320();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_0087d3d0_Class
{
    void FUN_0087d3d0(char* a, unsigned int count);
};
// @fnv 0x0087d340
void FUN_0087d340_Class::FUN_0087d340(unsigned int requested, unsigned int savedSize)
{
    m_pData = nullptr;
    m_iSize = 0;
    m_iCapacity = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_pData = vfn_04(requested);
        m_iCapacity = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_0087d3d0_Class *>(this)->FUN_0087d3d0(m_pData, savedSize);
        m_iSize = savedSize;
    }
}

// Calls operator new(8, ...) for each of count elements at successive 8-byte offsets from a.
// @fnv 0x0087d3d0
void FUN_0087d3d0_Class::FUN_0087d3d0(char* aiBase, unsigned int count)
{
    unsigned int i;
    void* p2;
    for (i = 0; i < count; ++i)
    {
        p2 = ::FUN_006e6da0(8, (void*)(aiBase + i * 8));
    }
}

struct ScriptLocalsX
{
};
struct FUN_0087ea80_shell
{
    char pad[0x90];
    char unk90;
    void FUN_0087ea80(std::uintptr_t a);
};
// @fnv 0x0087ea80
void FUN_0087ea80_shell::FUN_0087ea80(std::uintptr_t a)
{
    *(std::intptr_t*)(&unk90) = ::FUN_004ae750((void *)(((ScriptLocalsX*)a)));
}

struct Actor_0087f4a0
{
    bool FUN_0087f4a0();
};
struct FlagHelper
{
};
struct FlagHelper_ActorBase
{
    char pad[0x30];
    FlagHelper unk30;
};
// @fnv 0x0087f4a0
bool Actor_0087f4a0::FUN_0087f4a0()
{
    return reinterpret_cast<::ABD_005f92d0 *>((&reinterpret_cast<FlagHelper_ActorBase*>(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))->unk30))->GetFlag8();
}

class MapDtorWrap_b9629 : public NiTPointerMap<int, int>
{
  public:
    virtual void unk00();
    ~MapDtorWrap_b9629();
};

class FUN_008657e0_cls : public MapDtorWrap_b9629
{
  public:
    virtual ~FUN_008657e0_cls();
};

// Destructor that clears all entries from the underlying NiTPointerMap before destruction.
// @fnv 0x008657e0
FUN_008657e0_cls::~FUN_008657e0_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<NiTPointerMap<int, int>*>(this)))->FUN_00438af0();
}


struct FUN_00866140_cls
{
    int m_00;
    char* m_04;
    int m_08;
    int m_0c;
    void FUN_00866140(int a1, int a2);
};

// Adds a2 to m_0c, calls Step while the total exceeds m_08, then emits four values unless DAT_011de134->FUN_00424940() is true, and stores the new total.
// @fnv 0x00866140
void FUN_00866140_cls::FUN_00866140(int aiOffset, int aiAmount)
{
    int iNewTotal = m_0c + aiAmount;
    if (iNewTotal <= 0)
    {
        return;
    }
    while (iNewTotal > m_08)
    {
        reinterpret_cast<::FUN_008660b0_shell *>(this)->GrowBuffer();
    }
    if (!((unsigned char)(reinterpret_cast<::FUN_00424940_shell *>((DAT_011de134))->FUN_00424940())))
    {
        char* lo_ = m_04 + aiOffset;
        char* hi = m_04 + aiOffset + aiAmount;
        int rem3 = m_08 - (aiOffset + aiAmount);
        ::fnv_008661e0::FUN_008661e0(hi, rem3, lo_, m_0c - aiOffset);
    }
    m_0c = iNewTotal;
}

struct FUN_00866570_Input
{
};
struct FUN_00866570_Class : public FUN_008665d0_class
{
    void InitFromInput(FUN_00866570_Input* input);
};
// Calls the base initializer with four values obtained from the input object.
// @fnv 0x00866570
void FUN_00866570_Class::InitFromInput(FUN_00866570_Input* input)
{
    FUN_008665d0(reinterpret_cast<::Callees *>((input))->FUN_00726070(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((input))->FUN_0084e3a0())), reinterpret_cast<::fnv_008665b0::FUN_008665b0_shell *>((input))->FUN_008665b0(), reinterpret_cast<::BGSLoadFormBuffer *>((input))->GetVersion());
}

// Stand-in for the object stored in the array held by FUN_00866de0_cls::m_pArr.
struct FUN_004424c0_Element
{
};

// Class owning the array at +0x50; CallElementAt forwards an indexed element
// to its own member routine.
struct FUN_00866de0_cls
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
    FUN_004424c0_Element** m_pArr;
    void CallElementAt(int idx);
};

// @fnv 0x00866de0
void FUN_00866de0_cls::CallElementAt(int aiIndex)
{
    ::FUN_004424c0((char *)(m_pArr[aiIndex]));
}

using ScopeGuardCtx = ::AutoMemContext;

struct FUN_00866ff0_cls
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    FUN_00866ff0_cls();
};



// @fnv 0x00866ff0
void __cdecl FUN_00866ff0()
{
    ScopeGuardCtx ctx(0x14, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\BGSMoviePlayer.cpp", 0x1c);
    (*reinterpret_cast<void * *>(&::DAT_0126fac4)) = new FUN_00866ff0_cls();
}


struct S_00867510_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    float unk38;
    float unk3c;
    bool unk40;
    int unk44;

    S_00867510_Class* FUN_00867510();
};

// Initializes the object's fields: sets most floats to DAT_01012054, unk30/unk34 to -1, unk40 to false, unk38/unk3c to 0.0f, unk44 to 0, and returns this.
// @fnv 0x00867510
S_00867510_Class* S_00867510_Class::FUN_00867510()
{
    unk00 = ::DAT_01012054;
    unk04 = ::DAT_01012054;
    unk08 = ::DAT_01012054;
    unk0c = ::DAT_01012054;
    unk10 = ::DAT_01012054;
    unk14 = ::DAT_01012054;
    unk1c = ::DAT_01012054;
    unk20 = ::DAT_01012054;
    unk24 = ::DAT_01012054;
    unk28 = ::DAT_01012054;
    unk2c = ::DAT_01012054;

    unk30 = -1;
    unk34 = -1;
    unk40 = false;
    unk38 = 0.0f;
    unk3c = 0.0f;
    unk44 = 0;

    return this;
}

struct FUN_008676d0_Class
{
    virtual float vfn_00();
    virtual float vfn_04();
    virtual float vfn_08();
    virtual float vfn_0c();
    virtual float vfn_10();
    virtual float vfn_14();
    virtual float vfn_18();
    virtual float vfn_1c();
    virtual float vfn_20();
    virtual float vfn_24();
    virtual float vfn_28();
    virtual float vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual float vfn_38();
    virtual float vfn_3c();
    virtual void vfn_40();

    void FUN_008676d0();
};

// Calls the object's virtual functions vfn_00 through vfn_40 in order, skipping vfn_18.
// @fnv 0x008676d0
void FUN_008676d0_Class::FUN_008676d0()
{
    vfn_00();
    vfn_04();
    vfn_08();
    vfn_0c();
    vfn_10();
    vfn_14();
    vfn_1c();
    vfn_20();
    vfn_24();
    vfn_28();
    vfn_2c();
    vfn_30();
    vfn_34();
    vfn_38();
    vfn_3c();
    vfn_40();
}

class FUN_008691d0_cls
{
  public:
    void** m_ppVirtualMethodTable;
    TESObjectREFR** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    TESObjectREFR* RemoveAt(unsigned int index);
};

// Removes the element at index by swapping in the last element, clearing the slot, and decrementing the size and element count if non-null.
// @fnv 0x008691d0
TESObjectREFR* FUN_008691d0_cls::RemoveAt(unsigned int index)
{
    if (index >= m_usSize)
    {
        return 0;
    }
    m_usSize--;
    TESObjectREFR* removed = m_pBase[index];
    m_pBase[index] = m_pBase[m_usSize];
    m_pBase[m_usSize] = 0;
    if (removed != 0)
    {
        m_usESize--;
    }
    return removed;
}

struct C869680Item;

class C869680Array
{
  public:
    virtual ~C869680Array();

    unsigned int FUN_00869680(unsigned int uiIndex, C869680Item* const& pkElement);

    C869680Item** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
// Calls FUN_00869680 with the unsigned short at offset 0xa of this object and the given int.
// @fnv 0x008693f0
void FUN_008693f0_Class::FUN_008693f0(std::intptr_t aiParam)
{
    reinterpret_cast<::C869680Array *>(this)->FUN_00869680(unk0a, (*(::C869680Item *const *)(aiParam)));
}

struct FNV_869F30_Renderer : NiRenderer
{
    void FUN_00483710();
};

struct FNV_869F30_Manager
{
};

struct FNV_869F30_World
{
};

struct FNV_869F30_Service
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
};
void __cdecl UpdateSystemUtility();
void __cdecl ResetSystemUtility();

// Switches on mode; for mode 2 it runs a fixed sequence of renderer, manager, world and service calls, with the manager call repeated at the end.
// @fnv 0x00869f30
void __cdecl RunModeSwitch(int mode)
{
    switch (mode)
    {
    default:
        break;
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (::FUN_0043c4b0())
        {
            reinterpret_cast<::TESForm *>((static_cast<FNV_869F30_Renderer*>(::FUN_0043c4b0())))->ClearData();
        }
        FUN_00867090();
        if ((*reinterpret_cast<::FNV_869F30_Manager * *>(&::DAT_01202d98)))
        {
            reinterpret_cast<::FUN_00c3e310_shell *>(((*reinterpret_cast<::FNV_869F30_Manager * *>(&::DAT_01202d98))))->FUN_00c3e310();
        }
        reinterpret_cast<::fnv_00449030::FUN_00449030Class *>(((*reinterpret_cast<::FNV_869F30_World * *>(&::g_modelLoader))))->CallMemberFunction();
        reinterpret_cast<::FUN_00877d30_Class *>(((*reinterpret_cast<::FNV_869F30_Manager * *>(&::DAT_01202d98))))->FUN_00877d30();
        reinterpret_cast<::FUN_00c3e340_cls *>(((*reinterpret_cast<::FNV_869F30_Manager * *>(&::DAT_01202d98))))->FUN_00c3e340();
        reinterpret_cast<::B01130Task *>((((::FNV_869F30_Service *)&(::BSFileCache::GetRandomGenerator()))))->FUN_00b01130();
        ((::FNV_869F30_Service *)&(::BSFileCache::GetRandomGenerator()))->method2();
        ::FalloutAudioMedia::BeginMediaUpdate();
        FUN_0082f9c0();
        ((::FNV_869F30_Service *)(::FUN_00453a70()))->method2();
        UpdateSystemUtility();
        ResetSystemUtility();
        ((::FNV_869F30_Service *)&(::GetTaskletManager()))->method2();
        if ((*reinterpret_cast<::FNV_869F30_Manager * *>(&::DAT_01202d98)))
        {
            reinterpret_cast<::FUN_00c3e310_shell *>(((*reinterpret_cast<::FNV_869F30_Manager * *>(&::DAT_01202d98))))->FUN_00c3e310();
        }
        break;
    }
}

struct FUN_0086a480_holder
{
};

struct FUN_0086a480_other
{
};



// @fnv 0x0086a480
float FUN_0086a480(int aiMode)
{
    if (aiMode == 3)
    {
        return ::fnv::timer::Seconds();
    }
    if (aiMode == 2)
    {
        if (!FUN_00702360())
        {
            struct Pair64
            {
                unsigned int lo;
                unsigned int hi;
            } value;
            value.lo = ::fnv::timer::Time();
            value.hi = 0;
            float r1 = (double)*(__int64*)&value / DAT_01017b70;
            return r1;
        }
        else
        {
            return 0.0f;
        }
    }
    if (aiMode == 1)
    {
        if (!FUN_00702360())
        {
            return ::fnv::timer::Seconds();
        }
        else
        {
            return 0.0f;
        }
    }
    else if (aiMode == 0)
    {
        float r2 = ((double)(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::FUN_0086a480_other *>(&::g_011de7b8))))->GetGameTime())) * DAT_01012638 * DAT_01012638;
        return r2;
    }
    return 0.0f;
}

extern int DAT_011f638c;
// @fnv 0x0086a820
int __cdecl FUN_0086a820()
{
    return DAT_011f638c;
}


struct SettingsRef_011cf8a4
{
};

struct ChainLeaf_005b9f80
{
};
struct ChainNode_004ebbc0
{
};

float Sample_0086c0c0();
float Sample_0086c0d0();
float Sample_0086c0e0();
float Sample_0086c0f0();
float Sample_0086c100();
float Sample_0086c110();
float Sample_0086c120();
float Sample_0086c130();
void FUN_0086c140(float value);
void __cdecl FUN_0086c150(float value);

// @fnv 0x0086c010
void FUN_0086c010()
{
    float value;
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011f941e)) != 0)
    {
        ::DAT_011adbcc = Sample_0086c120();
        g_011adbd0 = Sample_0086c130();
        FUN_0086c140(Sample_0086c100());
        FUN_0086c150(Sample_0086c110());
    }
    else
    {
        FUN_0086c140(Sample_0086c0c0());
        FUN_0086c150(Sample_0086c0d0());
        ::DAT_011adbcc = Sample_0086c0e0();
        g_011adbd0 = Sample_0086c0f0();
    }
    value = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingsRef_011cf8a4 *>(&::g_011cf8a4))))));
    reinterpret_cast<::FUN_005b9f80 *>((((::ChainLeaf_005b9f80 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((((::ChainNode_004ebbc0 *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_004ebbc0({})))))->SetScanlines({});
}

class B86C620Base
{
  public:
    B86C620Base(void* pvOwner);
    ~B86C620Base();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class B86C620Timer
{
  public:
    B86C620Timer(int iStart, int m_iPayloadInteger);

    int m_iStart;
    int m_iDuration;
    int m_iElapsed;
};

class FUN_0086c620_cls : public B86C620Base
{
  public:
    FUN_0086c620_cls(void* pvOwner, void* pvTarget);

    B86C620Timer m_kTimer;
    void* m_pvTarget;
    bool m_bDone;
};

// Constructs the object with the given owner and target, initializing the timer to start 0 with duration 100 and marking it not done.
// @fnv 0x0086c620
FUN_0086c620_cls::FUN_0086c620_cls(void* pvOwner, void* pvTarget)
    : B86C620Base(pvOwner), m_kTimer(0, 100), m_pvTarget(pvTarget), m_bDone(false)
{}

// Thiscall, 98 bytes /MT /Od /GS /EHsc: body call on this (state 1), member sub-object
// at +0x14 released (state 0), then base sub-object dtor on this (state -1).
class FUN_0086c6e0_base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ~FUN_0086c6e0_base();
};

class FUN_0086c6e0_child
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    ~FUN_0086c6e0_child();
};

class FUN_0086c6e0_cls : public FUN_0086c6e0_base
{
  public:
    FUN_0086c6e0_child m_14;
    ~FUN_0086c6e0_cls();
};

// Fade node helper: repeatedly asks the node to process a scratch buffer
// until it reports that it is done.
struct FadeNodeLocal_cls
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool vfn_10(char* pBuf);
    void FUN_0086c750();
};
// @fnv 0x0086c6e0
FUN_0086c6e0_cls::~FUN_0086c6e0_cls()
{
    reinterpret_cast<::FadeNodeLocal_cls *>(this)->FUN_0086c750();
}

// Repeatedly calls vfn_10 with a 32-byte scratch buffer until it returns false.
// @fnv 0x0086c750
void FadeNodeLocal_cls::FUN_0086c750()
{
    char buffer[0x20];
    while (this->vfn_10(buffer))
    {
    }
}

struct FUN_0086c850_cls
{
    int unk00;
};

struct FUN_0086cdf0_cls
{
    int unk00;
    FUN_0086c850_cls* m_04;
};


// @fnv 0x0086cdf0
void FUN_0086cdf0()
{
    if ((*reinterpret_cast<::FUN_0086cdf0_cls * *>(&::DAT_011f35cc)) != 0)
    {
        FUN_0086cdf0_cls* tmp = (*reinterpret_cast<::FUN_0086cdf0_cls * *>(&::DAT_011f35cc));
        FUN_0086cdf0_cls* obj2 = tmp;
        void* result;
        if (obj2 != 0)
        {
            result = reinterpret_cast<::FUN_0086c850_shell *>((reinterpret_cast<FUN_0086c850_cls*>(obj2)))->FUN_0086c850(1);
        }
        else
        {
            result = 0;
        }
    }
    (*reinterpret_cast<::FUN_0086cdf0_cls * *>(&::DAT_011f35cc)) = 0;
}

struct FUN_00876a20_out
{
};
struct FUN_00876a20_list
{
};
struct FUN_00876a20_arg
{
};
extern int __cdecl FUN_00874690();
struct FUN_00876a20_shell
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
    FUN_00876a20_list unk94;
    void FUN_00876a20(FUN_00876a20_arg* apArg);
};

// Clears DAT_011a9604, passes FUN_00874690() to apArg, calls FUN_00b65ec0 on unk94's element, then restores the flag.
// @fnv 0x00876a20
void FUN_00876a20_shell::FUN_00876a20(FUN_00876a20_arg* apArg)
{
    bool bOld = (*reinterpret_cast<bool *>(&::DAT_011a9604));
    (*reinterpret_cast<bool *>(&::DAT_011a9604)) = false;
    reinterpret_cast<::CameraState4E9 *>((apArg))->SetFromCamera((*(const ::Camera4E9 *)(std::uintptr_t)(FUN_00874690())));
    reinterpret_cast<::FUN_00b65ec0_cls *>((((::FUN_00876a20_out *)(::FUN_00559450((int *)&(unk94))))))->FUN_00b65ec0();
    (*reinterpret_cast<bool *>(&::DAT_011a9604)) = bOld;
}

class FUN_00877ac0_iter
{
  public:
    char m_bytes[0x20];
};

class FUN_00877ac0_base
{
  public:
    virtual ~FUN_00877ac0_base();
};

class FUN_00877ac0_cls : public FUN_00877ac0_base
{
  public:
    virtual ~FUN_00877ac0_cls();
};
// @fnv 0x00877d50
void* FUN_00877d50_Class::FUN_00877d50(unsigned int flags)
{
    reinterpret_cast<::FUN_00877ac0_cls *>(this)->FUN_00877ac0_cls::~FUN_00877ac0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that repeatedly calls FUN_00877ac0_step with a local iterator until it returns false.
// @fnv 0x00877ac0
FUN_00877ac0_cls::~FUN_00877ac0_cls()
{
    FUN_00877ac0_iter it;
    while (reinterpret_cast<::FUN_006ec390_Class *>(this)->FUN_006ec390((std::intptr_t)&(it)))
    {
    }
}

struct B877BE0Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct B877BE0Node
{

    B877BE0Node();

    B877BE0Node* m_pkNext;
    B877BE0Item m_kItem;
};

class B877BE0Pool
{
  public:
};


class B877BE0Queue
{
  public:
    int unk00;
    int unk04;
    B877BE0Pool* m_pkPool;
    B877BE0Node* m_pkHead;
    B877BE0Node** m_ppkTail;

    bool Push(const B877BE0Item& kItem);
};

// Allocates and constructs a node, copies kItem into it, appends the node to the tail of the queue, and returns true.
// @fnv 0x00877be0
bool B877BE0Queue::Push(const B877BE0Item& kItem)
{
    B877BE0Node* pkNode = (B877BE0Node*)reinterpret_cast<::FUN_00aa54a0_s *>((m_pkPool))->FUN_00aa54a0(sizeof(B877BE0Node), ::DAT_010a2720);
    new (pkNode) B877BE0Node;
    pkNode->m_kItem = kItem;
    if (!m_pkHead)
        m_ppkTail = &m_pkHead;
    *m_ppkTail = pkNode;
    pkNode->m_pkNext = 0;
    m_ppkTail = &pkNode->m_pkNext;
    return true;
}

struct Node877
{
    Node877* next;
    int data[8];
};

struct Holder877
{
};

struct Cls877
{
    int m_00;
    int m_04;
    Holder877* m_08;
    Node877* m_0c;
    unsigned char PopNode(void* dest);
};

struct Block877
{
    int a, b, c, d, e, f, g, h;
};

// @fnv 0x00877cc0
unsigned char Cls877::PopNode(void* dest)
{
    Node877* node = m_0c;
    unsigned char result;
    if (node != 0)
    {
        *(Block877*)dest = *(Block877*)node->data;
        m_0c = node->next;
        reinterpret_cast<::Date *>((node))->FUN_007b3fa0(0);
        reinterpret_cast<::SHStub *>((m_08))->FUN_00aa5610(node);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

struct FUN_00877db0_Embedded
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00877db0_Class
{
    int unk00;
    FUN_00877db0_Embedded unk04;

    FUN_00877db0_Class();
};

// @fnv 0x00877db0
FUN_00877db0_Class::FUN_00877db0_Class() : unk00(0), unk04()
{}

class FUN_00877f10_base
{
  public:
    virtual ~FUN_00877f10_base();
    FUN_00877f10_base(int a, int b);

    int m_i04;
};

class FUN_00877f10_obj
{
  public:
    virtual void v0();
    virtual void v1(void* p);
};

class FUN_00877f10 : public FUN_00877f10_base
{
  public:
    FUN_00877f10(int a, int b);
    virtual ~FUN_00877f10();
};

// Constructs the base with a and b, then passes this to v1 on the object returned by FUN_00877950.
// @fnv 0x00877f10
FUN_00877f10::FUN_00877f10(int a, int b) : FUN_00877f10_base(a, b)
{
    reinterpret_cast<FUN_00877f10_obj*>(FUN_00877950())->v1(this);
}

class FUN_00877fc0_base
{
  public:
    virtual void v0();
    ~FUN_00877fc0_base();

    int m_i04;
};

class FUN_00877fc0_obj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p);
};

class FUN_00877fc0 : public FUN_00877fc0_base
{
  public:
    virtual ~FUN_00877fc0();
};
// Runs the destructor, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00877f90
void* GlobalObject_00877f10::FUN_00877f90(unsigned int flags)
{
    reinterpret_cast<::FUN_00877fc0 *>(this)->FUN_00877fc0::~FUN_00877fc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls v2 on the object returned by FUN_00877950, passing this, as part of destruction.
// @fnv 0x00877fc0
FUN_00877fc0::~FUN_00877fc0()
{
    reinterpret_cast<FUN_00877fc0_obj*>(FUN_00877950())->v2(this);
}

// FUN_00878030 : resets a game object and returns it.

struct Member14_b3616
{
};

struct FUN_00878030_cls
{
    void* m_pDatA;
    unsigned int m_uiFlags1;
    void* m_pDatB;
    unsigned int m_uiFlags2;
    unsigned int m_uiFlags3;
    Member14_b3616 m_Sub14;
    FUN_00878030_cls* FUN_00878030();
};

// @fnv 0x00878030
FUN_00878030_cls* FUN_00878030_cls::FUN_00878030()
{
    ::FUN_0044fae0((void *)&(m_Sub14));
    m_pDatA = &(*reinterpret_cast<char *>(&::DAT_01400000));
    m_uiFlags1 = 0xf00000;
    m_pDatB = &FUN_00a00000;
    m_uiFlags2 = 0x200000;
    m_uiFlags3 = 0xffffffff;
    return this;
}

struct StateControl
{
};
struct ManagedEntry
{
};
struct FUN_00878080_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    StateControl control;
    void FUN_00878080(int unused);
};
// @fnv 0x00878080
void FUN_00878080_Class::FUN_00878080(int unused)
{
    if (!reinterpret_cast<::s44b130::Lock *>(&(control))->FUN_0044b130())
        return;
    if (reinterpret_cast<FUN_00878110_Class*>(((void *)(::FUN_00401020())))->FUN_00878110() > 0)
    {
        bool enabled = true;
        {
            unsigned int index = 0;
            for (; index <= reinterpret_cast<FUN_00878110_Class*>(((void *)(::FUN_00401020())))->FUN_00878110(); ++index)
            {
                reinterpret_cast<::StateMachine *>((((::ManagedEntry *)(::FUN_00401020()))))->RunStep({}, {}, {});
            }
        }
        reinterpret_cast<FUN_00878130_Class*>(((void *)(::FUN_00401020())))->ResetAndGetValue();
    }
    reinterpret_cast<::S_0082f1f0_Lock *>(&(control))->FUN_0082f1f0();
}

extern int DAT_011a95fc;

// @fnv 0x008781f0
int __cdecl FUN_008781f0()
{
    return DAT_011a95fc;
}

// Claim: CallSubCallee (22 bytes, /MT /Od /Oy- /GS /EHsc /Gy)
//
// Shape: a tiny member that forwards to a member function of an
// embedded sub-object living at this+0x14.

struct Sub_0044fb00
{
};

// Stand-in for the owning class: 0x14 bytes of leading members, then the
// embedded sub-object whose method is invoked.
struct Owner_008783a0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    Sub_0044fb00 m_sub;

    void CallSubCallee();
};

// @fnv 0x008783a0
void Owner_008783a0::CallSubCallee()
{
    reinterpret_cast<::FUN_0044fb00_Shim *>(&(m_sub))->FUN_0044fb00();
}

// Claim: clm_7b4ec1e887d84607aabf  FUN_0087a730
// 51 bytes, thiscall, /Od. Prologue stores `this` in the local slot, then the
// member pointer at +0 is used as the `this` of two byte-returning helpers.

struct FUN_0087a730_target
{
    bool FUN_0087a770();
};

struct FUN_0087a730_cls
{
    FUN_0087a730_target* unk00;
    bool FUN_0087a730();
};

// Returns true when unk00's FUN_0087a770 and GetField24 both return false, otherwise false.
// @fnv 0x0087a730
bool FUN_0087a730_cls::FUN_0087a730()
{
    if (!this->unk00->FUN_0087a770() && !((bool)(reinterpret_cast<::TESObjectCELL *>((this->unk00))->GetField24())))
        return true;
    return false;
}

struct EventSource
{
};
union PacketValue
{
    unsigned int bits;
    unsigned char byte;
};
struct EventMessage
{
    unsigned int code;
    EventSource* source;
    union
    {
        struct
        {
            PacketValue first;
            PacketValue second;
            PacketValue third;
        } arguments;
        unsigned char serializedArguments[24];
    } payload;
};
struct Receiver
{
    void SendEvent(EventSource* source, unsigned char first, unsigned char second, unsigned char third);
};
// @fnv 0x0087b300
void Receiver::SendEvent(EventSource* source, unsigned char first, unsigned char second, unsigned char third)
{
    EventMessage message;
    message.code = 49;
    message.source = source;
    message.payload.arguments.first.byte = first;
    message.payload.arguments.second.byte = second;
    message.payload.arguments.third.byte = third;
    reinterpret_cast<::FUN_0040f6e0_class *>((source))->FUN_0040f6e0();
    reinterpret_cast<::TaskQueueInterface *>(this)->ProcessPackedTask((*(const ::BSPackedTask *)(&message)));
}

struct S_0087e9d0_Base
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
};

struct S_0087e9d0_Class : public S_0087e9d0_Base
{
    bool unk254;
    bool unk255;

    void FUN_0087e9d0(bool value);
};

// Stores the logical AND of unk254 and value into unk255.
// @fnv 0x0087e9d0
void S_0087e9d0_Class::FUN_0087e9d0(bool value)
{
    unk255 = unk254 && value;
}

// Buffer constructor: remember capacity and owner data, allocate the storage when the capacity is non-zero.

void* __cdecl C41D0Allocate(unsigned int uiSize);

class FUN_008641d0
{
  public:
    FUN_008641d0(unsigned int uiCapacity, unsigned int uiGrowBy);
    virtual ~FUN_008641d0();

    void* pvContextData;
    unsigned int m_uiCapacity;
    unsigned int m_uiAllocatedCapacity;
    unsigned int m_uiPosition;
    unsigned int m_uiGrowBy;
};
// Calls FUN_008641d0 with the two arguments, stores the address of DAT_01081fa0 at offset 0 of this, and returns this.
// @fnv 0x00863e00
int* FUN_00863e00_cls::FUN_00863e00(int a, int b)
{
    new ((void *)this) ::FUN_008641d0(a, b);
    *(int**)((char*)this + 0) = &DAT_01081fa0;
    return (int*)this;
}

// @fnv 0x008641d0
FUN_008641d0::FUN_008641d0(unsigned int uiCapacity, unsigned int uiGrowBy)
{
    m_uiCapacity = uiCapacity;
    m_uiGrowBy = uiGrowBy;
    m_uiAllocatedCapacity = 0;
    m_uiPosition = 0;
    if (m_uiCapacity > 0)
        pvContextData = C41D0Allocate(m_uiCapacity);
    else
        pvContextData = 0;
}

class BSAudio867
{
  public:
};

class Base867
{
  public:
    Base867();
    virtual ~Base867();

};

class FUN_008670e0 : public Base867
{
  public:
    FUN_008670e0();
    virtual ~FUN_008670e0();
};

// Constructs the object and sets its enabled state from BSAudio867::GetSingleton()->IsEnabled().
// @fnv 0x008670e0
FUN_008670e0::FUN_008670e0()
{
    reinterpret_cast<::FUN_00ec1680_cls *>(this)->EnableSoundSystem(reinterpret_cast<::PatrolActorPackageData *>((((::BSAudio867 *)(::FUN_00453a70()))))->IsPatrolling());
}

struct Array08
{
    int unk00;
    char** data;
    unsigned short capacity, size, count, grow;
    void Resize(unsigned int newSize);
};
// @fnv 0x00869640
unsigned int FUN_00869640_StrArr::FUN_00869640(unsigned int index, char*& value)
{
    if (index >= unk08)
        reinterpret_cast<::Array08 *>(this)->Resize(unk0e + index);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    return index;
}
// Resizes the array to newSize: clears and counts down removed non-null entries, reallocates data, copies old entries and zero-fills the rest.
// @fnv 0x008696e0
void Array08::Resize(unsigned int newSize)
{
    if (newSize == capacity)
        return;
    unsigned short i;
    if (newSize < size)
    {
        for (i = (unsigned short)newSize; i < size; i++)
        {
            if (data[i])
            {
                data[i] = 0;
                count--;
            }
        }
        size = (unsigned short)newSize;
    }
    char** oldData = data;
    capacity = (unsigned short)newSize;
    if (newSize > 0)
    {
        data = (char**)AllocateUIntArray((unsigned int)capacity);
        for (i = 0; i < size; i++)
            data[i] = oldData[i];
        for (i = size; i < capacity; i++)
            data[i] = 0;
    }
    else
        data = 0;
    FUN_008696c0((void*)oldData);
}

struct FUN_00aa53f0
{
    int count;
    int capacity;
    void* data;
    int state;
    FUN_00aa53f0();
    ~FUN_00aa53f0();
};
struct FUN_0086c620
{
    int owner;
    int state;
    int flags;
    int start;
    int duration;
    int elapsed;
    int value;
    int target;
    int done;
    int reserved;
    FUN_0086c620(void*, void (*)());
    ~FUN_0086c620();
};
class BSShaderAccumulator
{
  public:
    BSShaderAccumulator(int, unsigned int, unsigned int);
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
};
struct G00559a40;
struct FUN_00633c90
{
    void* ptr;
    FUN_00633c90(int);
    ~FUN_00633c90();
    void FUN_0066b0d0(void*);
public:
    FUN_00633c90(::G00559a40 *);
};
class FUN_00a712f0
{
  public:
    FUN_00a712f0();
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
};
struct Global_p161
{
};
int FUN_0040fc90();
using ::AutoMemContext;
struct Controls_p161
{
};
struct FUN_0086c160
{
    char unk00;
    bool b1, b2, b3, b4, b5, b6, b7;
    void* arg1;
    void* arg2;
    int thread, state;
    FUN_00aa53f0 list18;
    FUN_0086c620 timer28;
    FUN_00aa53f0 list50;
    FUN_0086c620 timer60;
    FUN_00633c90 acc88, acc8c, acc90, acc94, acc98;
    bool flag9c;
    FUN_00633c90 acca0;
    FUN_0086c160(void*, void*);
};
// @fnv 0x0086c160
FUN_0086c160::FUN_0086c160(void* aiArg1, void* aiArg2)
    : timer28(&list18, ((void (&)())::TaskQueueInterface::ProcessQueuedTask)), timer60(&list50, ((void (&)())::TaskQueueInterface::ProcessQueuedTask)), acc88(0), acc8c(0), acc90(0), acc94(0), acc98(0),
      acca0(0)
{
    b1 = false;
    b2 = false;
    b3 = false;
    b4 = false;
    b5 = false;
    b6 = false;
    b7 = false;
    (*reinterpret_cast<::FUN_00633c90 *>(&::g_011dec64)).FUN_0066b0d0(0);
    acc88.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    acc8c.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    reinterpret_cast<::FUN_004a1040_Helper *>((((::BSShaderAccumulator *)(::FUN_00559450((int *)&(acc8c))))))->Set(12);
    reinterpret_cast<::FUN_00936aa0_shell *>((((::BSShaderAccumulator *)(::FUN_00559450((int *)&(acc8c))))))->FUN_00936aa0(true);
    acc90.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    reinterpret_cast<::FUN_004a1040_Helper *>((((::BSShaderAccumulator *)(::FUN_00559450((int *)&(acc90))))))->Set(12);
    reinterpret_cast<::FUN_00936aa0_shell *>((((::BSShaderAccumulator *)(::FUN_00559450((int *)&(acc90))))))->FUN_00936aa0(true);
    acc94.FUN_0066b0d0(new BSShaderAccumulator(100, 1, 4));
    reinterpret_cast<::FUN_004a1040_Helper *>((((::BSShaderAccumulator *)(::FUN_00559450((int *)&(acc94))))))->Set(13);
    acc98.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    flag9c = false;
    acca0.FUN_0066b0d0(new FUN_00a712f0);
    if (*((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::Global_p161 *>(&::g_011c3ea4)))))) > 1)
    {
        ::FUN_0087b8d0((unsigned int)(std::uintptr_t)(&timer28), (unsigned int)(std::uintptr_t)(&timer60));
        reinterpret_cast<::FUN_0086c600_shell *>(&(timer28))->SignalAtOffset();
        reinterpret_cast<::FUN_0086c600_shell *>(&(timer60))->SignalAtOffset();
    }
    ::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::Global_p161 *>(&::g_011c3ea4))));
    thread = FUN_0040fc90();
    arg1 = aiArg1;
    arg2 = aiArg2;
    state = 0;
    ::SetDebuggerThreadName(thread, ::g_011d2a30_arg1);
    AutoMemContext context(13, true, DAT_010829c4, 3526);
    ::CreateC790Manager(aiArg2);
    reinterpret_cast<::ControlsIniLoader *>((((::Controls_p161 *)(::FUN_007fdf30()))))->LoadControlsFromIni();
    context.Leave();
    context.Enter(11, true, (char *)(DAT_010829c4), 3541);
    reinterpret_cast<::FUN_0086ce40_class *>(this)->InitAudioCallbacks();
    context.Leave();
}

// Recreate the global manager: delete the old instance and construct a new one for the given owner.

class C790Manager
{
  public:
    C790Manager(void* pvOwner);
    ~C790Manager();

    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    int unk16B4;
    int unk16B8;
    int unk16BC;
    int unk16C0;
    int unk16C4;
    int unk16C8;
    int unk16CC;
    int unk16D0;
    int unk16D4;
    int unk16D8;
    int unk16DC;
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int unk16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
};


// Deletes the existing g_pkC790Manager if present, then allocates a new C790Manager with pvOwner.
// @fnv 0x0086c790
void CreateC790Manager(void* pvOwner)
{
    if ((*reinterpret_cast<::C790Manager * *>(&::DAT_011f35cc)))
        delete (*reinterpret_cast<::C790Manager * *>(&::DAT_011f35cc));
    (*reinterpret_cast<::C790Manager * *>(&::DAT_011f35cc)) = new C790Manager(pvOwner);
}

namespace fnv_0086c880 {
struct FUN_0045cec0
{
    int value;
    ~FUN_0045cec0();
    void FUN_0066b0d0(int);
};
struct FUN_00aa5460
{
    int field00, field04, field08, field0c;
    ~FUN_00aa5460();
};
struct FUN_0086c6e0
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c, field20, field24;
    ~FUN_0086c6e0();
    void FUN_0086cdd0();
};
struct Delete86
{
    virtual ~Delete86();
};
struct List86
{
    void FUN_0066b0d0(int);
};
struct Entry86
{
    void FUN_00483710();
};
struct Manager86
{
};
struct Setting86
{
};
extern Delete86* DAT_011d5128[14];
extern Delete86* DAT_011d56a8[34];
struct FUN_0086c880
{
    int field00, field04, field08, field0c, field10, field14;
    FUN_00aa5460 member18;
    FUN_0086c6e0 member28;
    FUN_00aa5460 member50;
    FUN_0086c6e0 member60;
    FUN_0045cec0 member88, member8c, member90, member94, member98;
    int field9c;
    FUN_0045cec0 membera0;
    ~FUN_0086c880();
};
// @fnv 0x0086c880
FUN_0086c880::~FUN_0086c880()
{
    ::ClearArchiveTables();
    reinterpret_cast<::fnv_00a22e10::S_00a22e10_Cls *>((((::fnv_0086c880::Manager86 *)(::FUN_007fdf30()))))->FUN_00a22e10();
    ::DAT_011dea14 = 0;
    ::DAT_011dea18 = 0;
    ::DAT_011dea1c = 0;
    FUN_0086cdf0();
    reinterpret_cast<::TESForm *>((((::fnv_0086c880::Entry86 *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011deb7c))))))))->ClearData();
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011deb7c)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011d6e5c)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011deb34)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011deda4)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011ded58)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011deb00)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011ded3c)).FUN_0066b0d0(0);
    (*reinterpret_cast<::fnv_0086c880::List86 *>(&::g_011dec94)).FUN_0066b0d0(0);
    DestroyMessageHandler();
    for (unsigned int i = 0; i < 4; i++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[4]>(&::DAT_011d5730))[i];
    for (unsigned int j = 0; j < 238; j++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[238]>(&::DAT_011d52f0))[j];
    for (unsigned int k = 0; k < 9; k++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[9]>(&::DAT_011d5240))[k];
    for (unsigned int l = 0; l < 8; l++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[8]>(&::DAT_011d51b0))[l];
    for (unsigned int m = 0; m < 28; m++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[28]>(&::fnv_00707330::DAT_011d51d0))[m];
    for (unsigned int n = 0; n < 14; n++)
        delete DAT_011d5128[n];
    for (unsigned int o = 0; o < 20; o++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[20]>(&::DAT_011d5160))[o];
    for (unsigned int p = 0; p < 34; p++)
        delete (*reinterpret_cast<fnv_0086c880::Delete86 * (*)[34]>(&::DAT_011d5268))[p];
    for (unsigned int q = 0; q < 34; q++)
        delete DAT_011d56a8[q];
    if (*((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::fnv_0086c880::Setting86 *>(&::g_011c3ea4)))))) > 1)
    {
        reinterpret_cast<::fnv_0086cdd0::FUN_0086cdd0 *>(&(member28))->Wait();
        reinterpret_cast<::fnv_0086cdd0::FUN_0086cdd0 *>(&(member60))->Wait();
        ::fnv_0087b950::ClearTaskQueue();
    }
    member88.FUN_0066b0d0(0);
    member8c.FUN_0066b0d0(0);
    member94.FUN_0066b0d0(0);
    member98.FUN_0066b0d0(0);
    membera0.FUN_0066b0d0(0);
}
}  // namespace fnv_0086c880

namespace fnv_00872e00 {
struct FUN_005d8b10
{
    virtual void vfn00();
    int unk04;
    FUN_005d8b10();
};
struct FUN_00872ea0
{
    virtual ~FUN_00872ea0();
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
    FUN_00872ea0(int a);
};
struct FUN_00633c90
{
    void* m_p;
    FUN_00633c90(int a);
    ~FUN_00633c90();
};
struct S_00872e00_Raw
{
    void* m_p;
    S_00872e00_Raw* FUN_00633c90(int a);
};
struct FUN_00872e00 : FUN_005d8b10
{
    FUN_00872ea0 m08;
    FUN_00633c90 m98;
    FUN_00633c90 m9c;
    S_00872e00_Raw ma0;
    FUN_00872e00();
    virtual ~FUN_00872e00();
};
// @fnv 0x00872e00
FUN_00872e00::FUN_00872e00() : m08(0), m98(0), m9c(0)
{
    new ((void *)&(ma0)) ::FUN_00633c90((::G00559a40 *)(0));
}
}  // namespace fnv_00872e00

union Command
{
    struct
    {
        unsigned int operation;
        unsigned int first;
        unsigned int second;
    } fields;
    unsigned char payload[32];
};
struct H
{
    void SendCommand22(unsigned int, unsigned int);
};
// Builds a Command with operation 22 and the two arguments, then passes it to FUN_0087d160.
// @fnv 0x0087b3b0
void H::SendCommand22(unsigned int uiFirst, unsigned int uiSecond)
{
    Command cmdRequest;
    cmdRequest.fields.operation = 22;
    cmdRequest.fields.first = uiFirst;
    cmdRequest.fields.second = uiSecond;
    reinterpret_cast<::TaskQueueInterface *>(this)->ProcessPackedTask((*(const ::BSPackedTask *)(&cmdRequest)));
}

namespace ActorInitialization {
struct Process
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
    Process();
};
struct Controller
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
    static void* operator new(std::size_t);
    static void operator delete(void*);
    Controller();
};
struct Package
{
};
struct Vector
{
    float x, y, z;
};
struct Setting
{
};
class Actor;
struct Manager
{
};
class Actor
{
  public:
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
    virtual void v80();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void Update();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void ResetState();
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
    Process* process;
    int unk06c;
    int unk070;
    float value074;
    int unk078;
    unsigned char unk07c;
    unsigned char unk07d;
    unsigned char flag07e;
    unsigned char unk07f;
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
    Controller* controller;
    int unk0b4;
    float value0b8;
    unsigned char flag0bc;
    unsigned char unk0bd;
    unsigned char unk0be;
    unsigned char unk0bf;
    int unk0c0;
    unsigned char flag0c4;
    unsigned char unk0c5;
    unsigned char unk0c6;
    unsigned char unk0c7;
    float value0c8;
    float value0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    Package package;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    unsigned char flag0f0;
    unsigned char flag0f1;
    unsigned char unk0f2;
    unsigned char unk0f3;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    float value114;
    unsigned char flag118;
    unsigned char unk119;
    unsigned char unk11a;
    unsigned char unk11b;
    int unk11c;
    int unk120;
    unsigned char flag124;
    unsigned char flag125;
    unsigned char flag126;
    unsigned char flag127;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    unsigned char flag144;
    unsigned char flag145;
    unsigned char flag146;
    unsigned char unk147;
    int unk148;
    unsigned char flag14c;
    unsigned char flag14d;
    unsigned char unk14e;
    unsigned char unk14f;
    int unk150;
    float value154;
    float value158;
    unsigned char flag15c;
    unsigned char flag15d;
    unsigned char unk15e;
    unsigned char unk15f;
    Vector velocity;
    float value16c;
    int unk170;
    unsigned char flag174;
    unsigned char flag175;
    unsigned char unk176;
    unsigned char unk177;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    unsigned char flag18c;
    unsigned char flag18d;
    unsigned char flag18e;
    unsigned char unk18f;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    unsigned char flag1b0;
    unsigned char flag1b1;
    void FUN_0087d890(bool);
};
// Initializes the actor: allocates process and controller, optionally registers it, sets default field values, resets state and runs update/init calls.
// @fnv 0x0087d890
void Actor::FUN_0087d890(bool registerActor)
{
    reinterpret_cast<::FUN_0046a010_shell *>(this)->FUN_0046a010(1);
    process = new Process;
    if (registerActor)
    {
        if (::FUN_008c7aa0())
            reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::ActorInitialization::Manager *>(&::g_011e0e80))))->AddMobileObjectToList((::MobileObject *)(::ActorInitialization::Actor *)(this));
        else
            reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::ActorInitialization::Manager *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(::ActorInitialization::Actor *)(this), 3, 0, 0, (::MobileObject *)(0));
    }
    value114 = ::DAT_01012054;
    unk120 = 0;
    unk108 = 0;
    unk10c = 0;
    flag118 = 0;
    unk0b4 = 8;
    flag0bc = 1;
    flag0c4 = 0;
    value0b8 = 0.0f;
    flag125 = 0;
    flag124 = 0;
    unk0c0 = 0;
    unk070 = 0;
    unk148 = 0;
    flag126 = 1;
    flag14c = 0;
    value158 = 0.0f;
    flag15c = 1;
    value074 = ::RandomFloat(*((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ActorInitialization::Setting *>(&::g_011df810)))))), *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ActorInitialization::Setting *>(&::g_011df828)))))));
    unk11c = 0;
    unk170 = 0;
    value16c = 0.0f;
    velocity = (*reinterpret_cast<::ActorInitialization::Vector *>((void *)&::NiPoint3::ZERO));
    value0c8 = 0.0f;
    value0cc = ::DAT_01017718;
    flag174 = 0;
    flag175 = 1;
    unk110 = 255;
    ResetState();
    reinterpret_cast<::ActorExtraShell *>(this)->FUN_008a08e0(0);
    flag14d = 0;
    unk0ac = 0;
    controller = new Controller;
    flag18c = 0;
    reinterpret_cast<::FUN_008bbdb0_shell *>(this)->FUN_008bbdb0();
    reinterpret_cast<::FUN_008bbe00_shell *>(this)->FUN_008bbe00();
    Update();
    reinterpret_cast<::FUN_008c4400_shell *>(this)->FUN_008c4400();
    unk150 = 0;
    value154 = 0.0f;
    flag0f1 = 0;
    reinterpret_cast<::bhkEntityListener_shell *>(&(package))->FUN_00937090(1);
    flag145 = 0;
    flag146 = 0;
    flag07e = 0;
    flag0f0 = 0;
    unk1a4 = 0;
    unk1a8 = 0;
    flag18d = 0;
    flag127 = 0;
    unk128 = 0;
    unk12c = 0;
    unk130 = 0;
    unk1ac = 0;
    flag18e = 0;
    unk194 = 0;
    flag15d = 1;
    unk198 = 0;
    flag144 = 0;
    flag1b0 = 0;
    unk1a0 = 0;
    flag1b1 = 0;
    unk140 = 0;
    unk13c = 0;
}
}

// Allocates the element array of a pointer array with auiCount elements.
// @fnv 0x00869840
void** __cdecl AllocateUIntArray(unsigned int auiCount)
{
    return new void*[auiCount];
}

struct SSSurfaceDesc
{
    unsigned int uiFormat;
    unsigned int uiType;
    unsigned int uiUsage;
    unsigned int uiPool;
    unsigned int uiMultiSampleType;
    unsigned int uiMultiSampleQuality;
    unsigned int uiWidth;
    unsigned int uiHeightRes;
};
struct SSLockedRect
{
    int m_cPitchAdjustment;
    unsigned char* pBits;
};

class SSSurface
{
  public:
    virtual void v000();
    virtual void v004();
    virtual unsigned long Release();  // +0x08
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual long GetDesc(SSSurfaceDesc* pkDesc);  // +0x30
    virtual long LockRect(SSLockedRect* pkRect, const void* pkArea, unsigned long uiFlags);
    virtual long UnlockRect();  // +0x38
};

class SSDevice
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
    virtual long GetBackBuffer(unsigned int uiSwapChain, unsigned int uiBackBuffer, int iType,
                                         SSSurface** ppkSurface);
};

struct SSFormat
{
    unsigned int unk00[17];
    SSFormat();
};

struct SSFormatSource
{
    const SSFormat& DeallocateSound();
};

class SSRenderer
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
    virtual SSFormatSource* GetFormatSource();  // +0xd4
};

class SSImage
{
  public:
    SSImage(unsigned int uiWidth, unsigned int uiHeightRes, SSFormat* pkFormat, bool bA, bool bB);
    virtual ~SSImage();
    unsigned int unk04[28];
};

class SSFile
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    SSFile(const char* pcPath, int iMode, int iAccess, int iFlags);
    ~SSFile();
};

// BITMAPFILEHEADER + BITMAPINFOHEADER as one 2-byte-aligned block; the 32-bit fields sit at odd word offsets.
struct SSBitmapHeader
{
    unsigned short usType;
    unsigned short ausFileSize[2];
    unsigned short usReserved1;
    unsigned short usReserved2;
    unsigned short ausOffBits[2];
    unsigned short ausSize[2];
    unsigned short ausWidth[2];
    unsigned short ausHeight[2];
    unsigned short usPlanes;
    unsigned short usBitCount;
    unsigned short ausCompression[2];
    unsigned short ausSizeImage[2];
    unsigned short ausXPelsPerMeter[2];
    unsigned short ausYPelsPerMeter[2];
    unsigned short ausClrUsed[2];
    unsigned short ausClrImportant[2];
};

struct SSCounter
{
};
struct SSStringSetting
{
};
struct SSMenuState
{
};


int FUN_00e7bd20(SSFormat* pkFormat);
SSMenuState* FUN_004de490();

// Captures the back buffer, converts it to a 24-bit BMP, writes it to a file, and optionally notifies the user.
// @fnv 0x00878860
void SaveScreenshot(const char* pcPath)
{
    SSRenderer* pkRendererVal = ((::SSRenderer *)(std::uintptr_t)(::FUN_004bc3f0()));
    SSFormat kFormatRes;
    SSDevice* pkDevicePos = ((::SSDevice *)(std::uintptr_t)(reinterpret_cast<::FUN_004dc020_Class *>((pkRendererVal))->FUN_004dc020()));
    kFormatRes = pkRendererVal->GetFormatSource()->DeallocateSound();
    int iFormatTotal = FUN_00e7bd20(&kFormatRes);
    SSSurface* pkSurfaceInfo;
    if (pkDevicePos->GetBackBuffer(0, 0, 0, &pkSurfaceInfo))
    {
        ::FUN_005b5e40();
        return;
    }
    SSSurfaceDesc kDescEntry;
    if (pkSurfaceInfo->GetDesc(&kDescEntry))
    {
        ::FUN_005b5e40();
        pkSurfaceInfo->Release();
        return;
    }
    SSLockedRect kRectValue;
    if (pkSurfaceInfo->LockRect(&kRectValue, 0, 0x800))
    {
        if (FUN_004dc310())
            ::FUN_005b5e40();
        else
            ::FUN_005b5e40(
                );
        pkSurfaceInfo->Release();
        return;
    }
    SSImage* pkImageNew = new SSImage(FUN_004dc1f0(), FUN_004dc200(), &kFormatRes, true, true);
    unsigned int uiRowSize = ((unsigned int)(reinterpret_cast<::FUN_0064da80_Class *>((pkImageNew))->FUN_0064da80(0, 0))) * ::FUN_0070ec90((char *)(pkImageNew));
    unsigned char* pucDstPtr = ((unsigned char *)(reinterpret_cast<::S_0064dac0 *>((pkImageNew))->FUN_0064dac0(0, 0)));
    unsigned char* pucSrc = kRectValue.pBits;
    for (int i = 0; i < FUN_004dc200(); i++)
    {
        ::__memcpy(pucDstPtr, pucSrc, uiRowSize);
        pucDstPtr += uiRowSize;
        pucSrc += kRectValue.m_cPitchAdjustment;
    }
    pkSurfaceInfo->UnlockRect();
    pkSurfaceInfo->Release();
    char acPathCur[260];
    if (pcPath)
        ::TaskQueueInterface::CopyStringToBuffer(acPathCur, 0x104, pcPath);
    else
        ::FUN_00406d00(acPathCur, 0x104, "%s%d.bmp", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SSStringSetting *>(&::g_011df0f8))))->GetMenuTitle())), *((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::SSCounter *>(&::g_011df124)))))));
    SSFile kFileLast(acPathCur, 2, 2, 0);
    if (!::FUN_00559450((int *)&(kFileLast)))
    {
        unsigned int uiWidth = ((unsigned int)(reinterpret_cast<::FUN_0064da80_Class *>((pkImageNew))->FUN_0064da80(0, 0)));
        unsigned int uiHeightRes = FUN_004dc200();
        unsigned int uiBytesPerPixelOld = ::FUN_0070ec90((char *)(pkImageNew));
        unsigned char* pucPixelsTmp = ((unsigned char *)(reinterpret_cast<::S_0064dac0 *>((pkImageNew))->FUN_0064dac0(0, 0)));
        unsigned char* pucBuffer = (unsigned char*)FUN_00401000(uiWidth * uiHeightRes * 3);
        unsigned int uiOutPos = 0;
        SSBitmapHeader kHeader;
        unsigned __int64 uiWritten;
        for (int y = uiHeightRes - 1; y >= 0; y--)
        {
            for (unsigned int x = 0; x < uiWidth; x++)
            {
                unsigned int uiElapsedMilliseconds = uiWidth * uiBytesPerPixelOld * y + x * uiBytesPerPixelOld;
                pucBuffer[uiOutPos] = pucPixelsTmp[uiElapsedMilliseconds];
                pucBuffer[uiOutPos + 1] = pucPixelsTmp[uiElapsedMilliseconds + 1];
                pucBuffer[uiOutPos + 2] = pucPixelsTmp[uiElapsedMilliseconds + 2];
                uiOutPos += 3;
            }
        }
        uiBytesPerPixelOld = 3;
        kHeader.usType = 0x4d42;
        *(unsigned int*)kHeader.ausFileSize = uiWidth * uiHeightRes * uiBytesPerPixelOld + 0x36;
        kHeader.usReserved1 = 0;
        kHeader.usReserved2 = 0;
        *(unsigned int*)kHeader.ausOffBits = 0x36;
        *(unsigned int*)kHeader.ausSize = 0x28;
        *(int*)kHeader.ausWidth = uiWidth;
        *(int*)kHeader.ausHeight = uiHeightRes;
        kHeader.usPlanes = 1;
        kHeader.usBitCount = uiBytesPerPixelOld * 8;
        *(unsigned int*)kHeader.ausCompression = 0;
        *(unsigned int*)kHeader.ausSizeImage = uiWidth * uiHeightRes * uiBytesPerPixelOld;
        *(int*)kHeader.ausXPelsPerMeter = 0;
        *(int*)kHeader.ausYPelsPerMeter = 0;
        *(unsigned int*)kHeader.ausClrUsed = 0;
        *(unsigned int*)kHeader.ausClrImportant = 0;
        reinterpret_cast<::FUN_00856350_shell *>(&(kFileLast))->SetAndReturnPointer((void *)(&kHeader), (void *)(0x36), &uiWritten, {});
        reinterpret_cast<::FUN_00856350_shell *>(&(kFileLast))->SetAndReturnPointer((void *)(pucBuffer), (void *)(std::uintptr_t)(uiWidth * uiHeightRes * uiBytesPerPixelOld), &uiWritten, {});
        FUN_00401030(pucBuffer);
        if (!pcPath)
        {
            char acMessage[260];
            ::std::sprintf(acMessage, "ScreenShot: File '%s' created.", acPathCur);
            ::DispatchMessageToSink((const char *)(acMessage), 0, (const char *)(0), (const char *)(0), 2.0f, 0);
            *((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::SSCounter *>(&::g_011df124)))))) = *((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::SSCounter *>(&::g_011df124)))))) + 1;
            reinterpret_cast<::FUN_008798e0_shell *>((FUN_004de490()))->OpenAtPosition();
        }
    }
    else
    {
        ::FUN_005b5e40();
    }
    delete pkImageNew;
}

struct FUN_00865980
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00865980();
};

struct Factory_00865900
{
    FUN_00865980* CreateInstance();
};
// @fnv 0x00865870
void FUN_00865870_Class::FUN_00865870()
{
    reinterpret_cast<::Factory_00865900 *>(((&unk0c)))->CreateInstance();
}

// Allocates and returns a new FUN_00865980 object.
// @fnv 0x00865900
FUN_00865980* Factory_00865900::CreateInstance()
{
    return new FUN_00865980;
}

struct ArraySmartRef
{
    void* pointer;
    ArraySmartRef(void*);
    ~ArraySmartRef();
    ArraySmartRef& FUN_006e5cc0(const ArraySmartRef&);
};
struct RefArrayOwner
{
    int unk00;
    ArraySmartRef* entries;
    unsigned short capacity, size, used;
    void FUN_00869870(unsigned int, const ArraySmartRef&);
};
// SetAtGrow
// @fnv 0x00869680
unsigned int C869680Array::FUN_00869680(unsigned int uiIndex, C869680Item* const& pkElement)
{
    if (uiIndex >= m_usMaxSize)
        reinterpret_cast<::NiTObjectArrayA47 *>(this)->FUN_0060bef0(uiIndex + m_usGrowBy);
    reinterpret_cast<::RefArrayOwner *>(this)->FUN_00869870(uiIndex, (const ::ArraySmartRef &)(pkElement));
    return uiIndex;
}
// Stores value at index, growing size if needed and adjusting used when the empty state of the slot changes.
// @fnv 0x00869870
void RefArrayOwner::FUN_00869870(unsigned int index, const ArraySmartRef& value)
{
    static ArraySmartRef empty(0);
    if (index >= size)
    {
        size = (unsigned short)(index + 1);
        if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(value))->IsNotEqual((const ::DummyStruct_00631820 &)(empty)))
            used++;
    }
    else
    {
        if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(value))->IsNotEqual((const ::DummyStruct_00631820 &)(empty)))
        {
            if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(entries[index]))->FUN_004b0460((const void **)&(empty)))
                used++;
        }
        else
        {
            if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(entries[index]))->IsNotEqual((const ::DummyStruct_00631820 &)(empty)))
                used--;
        }
    }
    entries[index].FUN_006e5cc0(value);
}

namespace fnv_0086a0a0 {
#include <windows.h>

struct Inner
{
};
struct Obj
{
    int G(int a, int b);
    bool H(unsigned a, unsigned b);
};
struct Obj2
{
};
extern char DAT_011deef4;
extern unsigned char DAT_011a3014;

// Handles window messages including activation, cursor visibility, and input by dispatching to DAT_011dea0c and returning DefWindowProcA results.
// @fnv 0x0086a0a0
LRESULT CALLBACK FUN_0086a0a0(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case 0x281:
        lParam = 0;
        return DefWindowProcA(hWnd, msg, wParam, lParam);
        break;
    case 6:
        switch ((WORD)(wParam & 0xffff))
        {
        case 1:
        case 2:
            if ((WORD)((wParam >> 16) & 0xffff) == 0)
            {
                if ((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals)))
                {
                    reinterpret_cast<::fnv_00871c90::FUN_00871c90_shell *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->FUN_00871c90(1);
                    reinterpret_cast<::MouseInputStandIn *>((((::fnv_0086a0a0::Inner *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->FUN_00877720()))))->RecreateDevice({});
                }
            }
            break;
        case 0:
            if ((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals)))
            {
                if (((bool)(reinterpret_cast<::Calendar *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->GetGameHour())))
                {
                    if (reinterpret_cast<::PatrolActorPackageData *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->IsPatrolling())
                    {
                        if (!::FUN_0070ec00())
                        {
                            if (!::FUN_00a09030(0x3f5))
                            {
                                if (!::FUN_00a09030(0x3ef))
                                {
                                    ::FUN_00709470(6, 0, 0, 0, 1);
                                }
                            }
                        }
                    }
                    if ((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals)))
                    {
                        if (!::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0086a0a0::Obj2 *>(&::g_011deb30)))))
                        {
                            reinterpret_cast<::fnv_00871c90::FUN_00871c90_shell *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->FUN_00871c90(0);
                        }
                    }
                }
            }
            break;
        }
        return 0;
    case 0x86:
        if (wParam == 0)
            DAT_011deef4 = 1;
        break;
    case 0x84: {
        LRESULT r = DefWindowProcA(hWnd, msg, wParam, lParam);
        if ((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals)))
        {
            if (((::fnv_0086a0a0::Inner *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->FUN_00877720())))
            {
                if (r != 1)
                {
                    if (!DAT_011a3014)
                    {
                        ShowCursor(1);
                        DAT_011a3014 = 1;
                    }
                }
                else if (DAT_011a3014)
                {
                    while (ShowCursor(0) > 0)
                    {
                    }
                    DAT_011a3014 = 0;
                }
            }
        }
        return r;
        break;
    }
    case 0x200:
        if (reinterpret_cast<::FUN_00871d10_t *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->FUN_00871d10((WORD)(lParam & 0xffff), (WORD)(((unsigned)lParam >> 16) & 0xffff)))
            return 0;
        break;
    case 5:
        return 0;
        break;
    case 0x47:
        if (((int)(::FUN_004bc3f0())))
        {
            int* p = (int*)lParam;
            ::FUN_004dc6e0(p[2], p[3]);
        }
        else if (!((bool)(::FUN_00446e10())))
        {
            return 0;
        }
        break;
    case 0x105:
        return 0;
    case 2:
        if ((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals)))
            reinterpret_cast<::FUN_005b6cb0_Class *>(((*reinterpret_cast<::fnv_0086a0a0::Obj * *>(&::g_osGlobals))))->FUN_005b6cb0();
        break;
    case 0x14:
        if (::FUN_004dc1e0() == (intptr_t)hWnd)
            return 1;
        break;
    case 0x112:
        ::fnv_004b7210::FUN_004b7210();
        if (::FUN_004b71d0())
        {
            switch ((WORD)(wParam & 0xffff))
            {
            case 0xf140:
            case 0xf170:
                return 1;
            }
        }
        break;
    }
    return DefWindowProcA(hWnd, msg, wParam, lParam);
}
}  // namespace fnv_0086a0a0

namespace fnv_0087dcb0 {


struct H
{
    void FUN_0041a250();
    void FUN_00824970();
    void FUN_009370b0();
    void FUN_00483710();
    void FUN_0046ffb0();
    void FUN_00937030();
    void FUN_00822a80();
    void FUN_008153b0();
    void FUN_0092ec40();
};

struct VObj
{
    virtual ~VObj();
};

struct Temp
{
    void* unk00;
    void* unk04;
    void* unk08;
    Temp();
    ~Temp();
};

struct A0
{
    virtual void a0();
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
};
struct A18
{
    virtual void a18();
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* m_68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
};
struct Base0 : A0, A18
{
    ~Base0();
};
struct B88
{
    virtual void b88();
    void* unk04;
    void* unk08;
    ~B88();
};
struct X94
{
    virtual void x94();
    void* unk04;
    void* unk08;
    void* unk0C;
};
struct Y94
{
    virtual void y94();
};
struct Z94
{
    virtual void z94();
};
struct B94 : X94, Y94, Z94
{
    ~B94();
    void FUN_00824970();
};
struct M_d0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    ~M_d0();
    void FUN_009370b0();
};
struct M_e0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    ~M_e0();
    void FUN_009370b0();
};
struct M_f4
{
    void* unk00;
    void* unk04;
    ~M_f4();
};
struct M_fc
{
    void* unk00;
    void* unk04;
    ~M_fc();
};

struct FUN_0087dcb0 : Base0, B88, B94
{
    VObj* m_ac;
    VObj* m_b0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    M_d0 m_d0;
    M_e0 m_e0;
    M_f4 m_f4;
    M_fc m_fc;
    unsigned char m_104;
    unsigned char unk105;
    unsigned char unk106;
    unsigned char unk107;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    VObj* m_12c;
    VObj* m_130;

    ~FUN_0087dcb0();
};

// Deletes m_ac, m_b0, m_12c and m_130, then unless FUN_004077c0 is true runs a series of cleanup calls on this and global objects.
// @fnv 0x0087dcb0
FUN_0087dcb0::~FUN_0087dcb0()
{
    delete m_ac;
    if (m_b0)
        delete m_b0;

    {
        Temp temp;
        reinterpret_cast<::FUN_00418890_shell *>((((H*)reinterpret_cast<::FUN_005d43c0_ *>((((H*)this)))->FUN_005d43c0())))->FUN_00418890({});
        if (((unsigned char)(reinterpret_cast<::SoundPlaybackHandle *>((((H*)&temp)))->IsValid())))
        {
            reinterpret_cast<::SoundPlaybackHandle *>((((H*)&temp)))->Release();
        }
        ::FUN_00835980((::TESObjectREFR_Stub *)(void *)(this));

        delete m_12c;
        delete m_130;

        if (!((unsigned char)(reinterpret_cast<::FUN_004077c0_shell *>((((H*)this)))->FUN_004077c0())))
        {
            reinterpret_cast<::FUN_0093a660_class *>((((H*)(*reinterpret_cast<void * *>(&::_g_thePlayer)))))->FUN_0093a660((std::intptr_t)(this));
            reinterpret_cast<::FUN_00967350_shell *>((((H*)(*reinterpret_cast<void * *>(&::_g_thePlayer)))))->FUN_00967350((int)(std::uintptr_t)(this));
            reinterpret_cast<::FUN_0096e6f0_shell *>((((H*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->RemoveActor((::Actor *)(void *)(this));
            ::FUN_0087fd20((::FUN_0087fd20_Class *)(((H*)this)));
            reinterpret_cast<::FUN_00906050_Class *>((((H*)&(*reinterpret_cast<int *>(&::fnv_008a20d0::g_011f11e0)))))->FUN_00906050((int)(std::uintptr_t)(this));
            reinterpret_cast<::F8660Owner *>((((H*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00978660((unsigned int)(std::uintptr_t)(this));
            if (!((unsigned char)(reinterpret_cast<::FUN_004226e0_shell *>((((H*)(*reinterpret_cast<void * *>(&::g_dataHandler)))))->FUN_004226e0())))
            {
                reinterpret_cast<::MagicTarget *>(this)->DispelAllEffects();
                ::FUN_0066e100((unsigned int)(std::uintptr_t)(this));
                reinterpret_cast<::fnv_0092ed60::FNVCurrent *>((((H*)this)))->FUN_0092ed60(1);
                reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((((H*)this)))->FUN_00881680(0);
                reinterpret_cast<::fnv_00976680::Host *>((((H*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00976680((::fnv_00976680::Obj *)(void *)(this));
                reinterpret_cast<::fnv_0096f600::FUN_0096f600_shell *>((((H*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096f600((::Actor *)(void *)(this), 1);
                reinterpret_cast<::CrimeProcess *>((((H*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00975320((::TESForm *)(void *)(this));
                if (m_68)
                {
                    if (((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((H*)m_68)))->FUN_0045cd60())) == 1 || ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((H*)m_68)))->FUN_0045cd60())) == 0)
                    {
                        void* p = ((void *)(::FUN_00b4f5c0()));
                        if (p)
                        {
                            reinterpret_cast<::S00b66050_cls *>((((H*)p)))->RemoveEntry(reinterpret_cast<::FUN_0084e3a0_Class *>((((H*)this)))->FUN_0084e3a0());
                        }
                        reinterpret_cast<::Actor8c30 *>((((H*)this)))->FUN_008c30a0();
                    }
                    reinterpret_cast<::SummonOwner *>((((H*)this)))->DispelSummonEffects();
                }
            }
            reinterpret_cast<::ProcessLists *>((((H*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->RemoveMobileObjectFromList((::MobileObject *)(void *)(this));
            if (m_104)
            {
                reinterpret_cast<::fnv_008a06c0::ActorX *>((((H*)this)))->FUN_008a06c0((::Actor *)(0));
            }
            reinterpret_cast<::FUN_008c5090_shell *>((((H*)this)))->DeleteAllItems();
            reinterpret_cast<::ActorValueModifierList *>(&(m_d0))->RemoveAllModifiers();
            reinterpret_cast<::ActorValueModifierList *>(&(m_e0))->RemoveAllModifiers();
            reinterpret_cast<::TESObjectREFR8B3 *>((((H*)this)))->FUN_008b3180();
            reinterpret_cast<::Ref3 *>((((H*)this)))->FUN_005702e0((::Obj3 *)(0), 0);
        }
    }
}
}  // namespace fnv_0087dcb0

// Opens the FalloutNV registry key and queries the Installed Path value into pBuffer, closing the key afterwards.
// @fnv 0x00876a70
void FUN_00876a70(char* pBuffer, unsigned long cbBuffer)
{
    HKEY hKey;
    const char* subKey = "Software\\Bethesda Softworks\\FalloutNV";
    unsigned long cbData = cbBuffer;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_QUERY_VALUE, &hKey) == 0)
    {
        RegQueryValueExA(hKey, "Installed Path", 0, 0, (unsigned char*)pBuffer, &cbData);
    }
    RegCloseKey(hKey);
}

#include "generated/data/staging/blk_00860000_od.inc"
