
// src/staging/blk_00440000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include <new>
#include <stdexcept>
#include <string>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSCameraShot.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C44C8E0Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DataHandlerX.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/Entry664.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00446ff0.h"
#include "fnv/decl/FUN_0044c3f0.h"
#include "fnv/decl/FUN_0044cae0_cls.h"
#include "fnv/decl/FUN_0044ee20_class.h"
#include "fnv/decl/FUN_0044ee40_cls.h"
#include "fnv/decl/FUN_0044f600_class.h"
#include "fnv/decl/FUN_004539a0_cls.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004587f0_shell.h"
#include "fnv/decl/FUN_00458f90_shell.h"
#include "fnv/decl/FUN_0045d110.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00481110_shell.h"
#include "fnv/decl/FUN_004baab0_shell.h"
#include "fnv/decl/FUN_004bad40_shell.h"
#include "fnv/decl/FUN_004bae20_shell.h"
#include "fnv/decl/FUN_00522d80_shell.h"
#include "fnv/decl/FUN_00529000_cls.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_0053a5e0_cls.h"
#include "fnv/decl/FUN_00552840_cls.h"
#include "fnv/decl/FUN_00553ee0_shell.h"
#include "fnv/decl/FUN_005549d0_shell.h"
#include "fnv/decl/FUN_0058b7d0.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005ffb60_cls.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_0065f7f0_Class.h"
#include "fnv/decl/FUN_0068b4a0_shell.h"
#include "fnv/decl/FUN_006ebde0_shell.h"
#include "fnv/decl/FUN_006ecba0_class.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_00878080_Class.h"
#include "fnv/decl/FUN_00906570_Class.h"
#include "fnv/decl/FUN_0092c870_shell.h"
#include "fnv/decl/FUN_00c3e310_shell.h"
#include "fnv/decl/FUN_00c3e340_cls.h"
#include "fnv/decl/FUN_00c47770.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/HashMap44c1e0.h"
#include "fnv/decl/IOManager.h"
#include "fnv/decl/LLD_TESHelper.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/NP_0092c820.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/Owner67430.h"
#include "fnv/decl/OwnerC44.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Proxy.h"
#include "fnv/decl/QueuedMap.h"
#include "fnv/decl/S00458900_Vector.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/S694a0.h"
#include "fnv/decl/SearchWorker.h"
#include "fnv/decl/Self.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TaskProcessor.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TerrainStream.h"
#include "fnv/decl/Traversal.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/Worker.h"
#include "fnv/decl/fnv_00444350__HeadLoader444.h"
#include "fnv/decl/fnv_00446f70__FUN_00446f70_Cl.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_0045a520__FUN_0045a520_shell.h"
#include "fnv/decl/fnv_004e19c0__FUN_004e19c0.h"
#include "fnv/decl/fnv_00559490__S.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00856870__FUN_00856870.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_008a8150__FUN_008a8150_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00977540__ProcessManager.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_0044e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00451000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004e0000.h"
#include "fnv/symbols_004e8000.h"
#include "fnv/symbols_004f9000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_0065e000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_00662000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_0084f000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b60000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01267000.h"
#include "../../include/layout_support.h"

struct FUN_004410d0_Class
{
    void SetByteAtOffset38(unsigned char a);
};

// @fnv 0x004410d0
void FUN_004410d0_Class::SetByteAtOffset38(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x38) = aucValue;
}

struct FUN_00444020_Class
{
    void FUN_00444020(float fInitialRadius);
};

// @fnv 0x00444020
void FUN_00444020_Class::FUN_00444020(float afRadius)
{
    *(float*)((char*)this + 0x40) = afRadius;
}

struct Loader_S
{
    int FUN_00446dc0();
};

// @fnv 0x00446f00
void FUN_00446f00()
{
    (*reinterpret_cast<::Loader_S * *>(&::g_modelLoader))->FUN_00446dc0();
}

namespace fnv_00446f10 {
struct ModelLoader;
struct ModelLoader
{
    void FUN_00446f20();
};
// @fnv 0x00446f10
void FUN_00446f10()
{
    (*reinterpret_cast<::fnv_00446f10::ModelLoader * *>(&::g_modelLoader))->FUN_00446f20();
}
}  // namespace fnv_00446f10

struct FUN_00446f40_cls
{
};
struct FUN_00446f20_cls
{
    void* p[11];
    void FUN_00446f20();
};
unsigned int __cdecl gm_GetCurrentThreadId();
struct ArrSI
{
    void FUN_00446f40();
};
// @fnv 0x00446f20
void FUN_00446f20_cls::FUN_00446f20()
{
    reinterpret_cast<::ArrSI *>((((FUN_00446f40_cls*)p[10])))->FUN_00446f40();
}
// @fnv 0x00446f40
void ArrSI::FUN_00446f40()
{
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())) != gm_GetCurrentThreadId())
        reinterpret_cast<::fnv_00446f70::FUN_00446f70_Cl *>(this)->FUN_00446f70();
}

namespace fnv_00446f90 {
struct ModelLoader
{
    void CallMemberAtOffset28();
};

// @fnv 0x00446f90
void FUN_00446f90()
{
    (*reinterpret_cast<::fnv_00446f90::ModelLoader * *>(&::g_modelLoader))->CallMemberAtOffset28();
}
}  // namespace fnv_00446f90

struct FUN_00446fc0_class
{
    void FUN_00446fc0();
};

struct FUN_00446fa0_class
{
    void CallMemberAtOffset28();
};

// @fnv 0x00446fa0
void FUN_00446fa0_class::CallMemberAtOffset28()
{
    ((FUN_00446fc0_class*)*(void**)((char*)this + 0x28))->FUN_00446fc0();
}

namespace fnv_00446fc0 {
unsigned int __cdecl gm_GetCurrentThreadId();

struct ArrSI
{
};

struct Elem00c3e7d0
{
};

struct FUN_00446fc0_Class
{
    void FUN_00446fc0();
};

// Compares the object's flags with the current thread id and calls FUN_00446ff0 when they differ.
// @fnv 0x00446fc0
void FUN_00446fc0_Class::FUN_00446fc0()
{
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())) != gm_GetCurrentThreadId())
        reinterpret_cast<::FUN_00446ff0 *>((((Elem00c3e7d0*)this)))->FUN_00446ff0_();
}
}  // namespace fnv_00446fc0

struct FUN_0044abf0
{
};

struct FUN_0044a2c0_class
{
    void FUN_0044a2c0();
};

extern int DAT_010173dc;
struct Dummy44a3a0
{
    void FUN_0044a3d0();
};
struct Dummy44a400 : Dummy44a3a0
{
    void FUN_0044a400();
};
// @fnv 0x0044a400
void Dummy44a400::FUN_0044a400()
{
    *(int**)(void*)this = (int*)&DAT_010173dc;
    FUN_0044a3d0();
}

struct Unk65
{
    void* FUN_0044a7b0(int param);
public:
    void FUN_0065de30(const void*);
};

// @fnv 0x0044a7b0
void* Unk65::FUN_0044a7b0(int param)
{
    reinterpret_cast<::Unk65 *>(this)->FUN_0065de30(&param);
    return this;
}

extern int DAT_010173dc;
struct FUN_0044a9a0_Class
{
    void FUN_0044a450(int a);
    void* FUN_0044a9a0(const struct FUN_0044a450* apOther);
};
void __cdecl FUN_0044d670(int, int);
struct FUN_0044abd0_Class
{
    void FUN_0044abd0(int);
};
// @fnv 0x0044abd0
void FUN_0044abd0_Class::FUN_0044abd0(int aiValue)
{
    FUN_0044d670(aiValue, 0);
}

struct FUN_0044ac20_class
{
    int m;
    void FUN_0044ac20(const int* p);
};

// @fnv 0x0044ac20
void FUN_0044ac20_class::FUN_0044ac20(const int* piValue)
{
    m = *piValue;
}

struct FUN_0044caa0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    unsigned int ModuloByField(unsigned int a);
};
// @fnv 0x0044caa0
unsigned int FUN_0044caa0_class::ModuloByField(unsigned int auiValue)
{
    return auiValue % m_8;
}

struct FUN_0044cac0_class
{
    void SetIntValue(int a, int* b);
};

// @fnv 0x0044cac0
void FUN_0044cac0_class::SetIntValue(int aiValue, int* piOut)
{
    *piOut = aiValue;
}

struct FUN_0044d6c0_class
{
    void* FUN_00ec78f1(void***);
    void* m_field;
    void* FUN_0044d6c0(void** p);
};
// @fnv 0x0044d6c0
void* FUN_0044d6c0_class::FUN_0044d6c0(void** p)
{
    FUN_00ec78f1(&p);
    m_field = &DAT_010176f8;
    return this;
}

struct FUN_0044d6f0_This
{
    void* vtbl;
    void FUN_00ec79a1();
    void InitVtblAndCall();
};

// @fnv 0x0044d6f0
void FUN_0044d6f0_This::InitVtblAndCall()
{
    vtbl = &DAT_010176f8;
    FUN_00ec79a1();
}

extern int DAT_01017458;

struct FUN_0044d7f0_class
{
    int* vfn;
    FUN_0044d7f0_class* FUN_0044d7f0();
};

// @fnv 0x0044d7f0
FUN_0044d7f0_class* FUN_0044d7f0_class::FUN_0044d7f0()
{
    vfn = &DAT_01017458;
    return this;
}

namespace fnv_0044dd10 {
extern "C" void FUN_00ec7944(int);
extern int DAT_010176f8;

struct FUN_0044dd10_class
{
    void FUN_00ec7944(int);
    FUN_0044dd10_class* FUN_0044dd10(int arg);
};

// Calls FUN_00ec7944 with arg, stores the address of DAT_010176f8 at this, and returns this.
// @fnv 0x0044dd10
FUN_0044dd10_class* FUN_0044dd10_class::FUN_0044dd10(int arg)
{
    FUN_00ec7944(arg);
    *reinterpret_cast<int**>(this) = &DAT_010176f8;
    return this;
}
}  // namespace fnv_0044dd10

bool FUN_0044dff0(int*);

struct FUN_0044df20
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int m6;
    int m7;
    int m8;
    int m9;
    int m10;
    int m11;
    int m12;
    int m13;
    int m14;
    int m15;
    int m16;
    int m17;
    int m18;
    int m19;
    int m20;
    int m21;
    int m22;
    int m23;
    int m24;
    int m25;
    int m26;
    int m27;
    int m28;
    int m29;
    int m30;
    int m31;
    void Call();
};

// @fnv 0x0044df20
void FUN_0044df20::Call()
{
    FUN_0044dff0(&this->m2);
}


// @fnv 0x0044e420
void __cdecl FUN_0044e420(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    ::FUN_0044e440(apArg1, (uintptr_t)(apArg2), apArg3, (uintptr_t)(apArg4));
}

extern "C" void* __cdecl FUN_00ec7c66(void*, unsigned int, void*, unsigned int);

// Calls FUN_00ec7c66 with the given arguments and returns the first argument.
// @fnv 0x0044e440
void* __cdecl FUN_0044e440(void* a, uintptr_t b, void* c, uintptr_t d)
{
    FUN_00ec7c66(a, b, c, d);
    return a;
}


// @fnv 0x0044e460
void __cdecl FUN_0044e460(intptr_t aiArg1, int aiArg2, int aiArg3, intptr_t aiArg4)
{
    ::FUN_0044e480((void *)(aiArg1), aiArg2, aiArg3, (void *)(aiArg4));
}

void* __cdecl FUN_00ec7ce3(void*, unsigned int, unsigned int, void*);

// Calls FUN_00ec7ce3 with the given arguments and returns the first argument.
// @fnv 0x0044e480
void* __cdecl FUN_0044e480(void* a, unsigned int b, unsigned int c, void* d)
{
    FUN_00ec7ce3(a, b, c, d);
    return a;
}

struct FUN_0044f400_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void FUN_0044f400();
};


// @fnv 0x00450470
void __cdecl SetGlobalInt(int aiIndex, int aiValue)
{
    ((int*)&DAT_011afe88)[aiIndex] = aiValue;
}

struct FUN_00450b40_Class
{
    void FUN_00450b40(unsigned char b);
};

// @fnv 0x00450b40
void FUN_00450b40_Class::FUN_00450b40(unsigned char abValue)
{
    ((unsigned char*)this)[0x61d] = abValue;
}

struct List_009e03e0
{
    void RemoveAll();
};

struct FUN_00450b60_Class
{
    void ClearList();
};

// @fnv 0x00450b60
void FUN_00450b60_Class::ClearList()
{
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 0x94))))->RemoveAll();
}

int GetByteAtOffset38(void*);

// @fnv 0x00450fb0
bool FUN_00450fb0(void* pThis)
{
    return GetByteAtOffset38(pThis) == 3;
}

struct FUN_00450fd0_class
{
    unsigned int GetByteAtOffset38() const;
};

// @fnv 0x00450fd0
unsigned int FUN_00450fd0_class::GetByteAtOffset38() const
{
    return ((const unsigned char*)this)[0x26];
}

int GetByteAtOffset38(void*);

// @fnv 0x00450ff0
bool FUN_00450ff0(void* self)
{
    return ((int)(reinterpret_cast<::FUN_00450fd0_class *>((self))->GetByteAtOffset38())) == 6;
}

struct FUN_004524f0_Class
{
    unsigned char GetByteB5();
};

// @fnv 0x004524f0
unsigned char FUN_004524f0_Class::GetByteB5()
{
    return ((unsigned char*)this)[0xb5];
}

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};


// @fnv 0x00452510
void LockSpinLock()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(::g_spinLock))->FUN_0040fbf0((char *)(0));
}

struct FUN_00452e50_class
{
    void FUN_00452e50();
};

// @fnv 0x00452e50
void FUN_00452e50_class::FUN_00452e50()
{
    ((char*)this)[0x7d] = 1;
}


// @fnv 0x00452e70
float __cdecl FUN_00452e70(unsigned char index)
{
    return (*reinterpret_cast<float (*)[]>(&::DAT_011f940c))[index ? 1 : 0];
}

struct FUN_00452e90_Class
{
    unsigned int m_uiInitializationFlags;
    bool IsFlag20Set() const;
};

// @fnv 0x00452e90
bool FUN_00452e90_Class::IsFlag20Set() const
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x244) & 0x20) ? true : false;
}

struct FUN_004536e0_Class
{
    float GetFieldCC();
};

// @fnv 0x004536e0
float FUN_004536e0_Class::GetFieldCC()
{
    return *(float*)((char*)this + 0xcc);
}

struct FUN_00454380_Class
{
    void FUN_00454380(bool abTF);
};

// @fnv 0x00454380
void FUN_00454380_Class::FUN_00454380(bool abTF)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x15) = abTF;
}

struct FNStub
{
};
struct FUN_004543a0_Class
{
    const char* FUN_004543a0();
};
// @fnv 0x004543a0
const char* FUN_004543a0_Class::FUN_004543a0()
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)this + 0x58))))->FUN_00408da0()));
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
    unsigned char GetBoolValue();
};

// @fnv 0x00454af0
unsigned char GlobalObject_0045cf30::GetBoolValue()
{
    return *Bool();
}

struct FUN_00454b30_class
{
    unsigned int* FUN_00454b30();
};
// @fnv 0x00454b30
unsigned int* FUN_00454b30_class::FUN_00454b30()
{
    return *(unsigned int**)((char*)this + 0x1e0);
}

struct FUN_00454b70
{
    void* p0;
    void* p1;
    bool GetHasLOD();
};

// @fnv 0x00454b70
bool FUN_00454b70::GetHasLOD()
{
    return p1 != 0;
}

struct FUN_00456520_Class
{
    void FUN_00456520();
};

struct FUN_00c3dfa0_Class
{
};

// @fnv 0x00456520
void FUN_00456520_Class::FUN_00456520()
{
    reinterpret_cast<::IOManager *>((((FUN_00c3dfa0_Class*)this)))->FUN_00c3dfa0(5);
}

struct FUN_00456630_helper
{
    bool FUN_00456610();
};

struct FUN_004567e0_Class
{
    unsigned short GetShortAtOffset40();
};

// @fnv 0x004567e0
unsigned short FUN_004567e0_Class::GetShortAtOffset40()
{
    return *(unsigned short*)((char*)this + 0x40);
}

namespace fnv_00456c90 {
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};


// @fnv 0x00456c90
void FUN_00456c90(unsigned char value)
{
    *(*reinterpret_cast<::fnv_00456c90::GlobalObject_0045cf30 *>(&::g_01267c24)).Bool() = value;
}
}  // namespace fnv_00456c90

struct GridCell;
struct GridCellArray
{
    GridCell* Get(unsigned int, unsigned int);
};
struct TES
{
    GridCellArray* m_pGridCells;
    GridCell* FUN_00457050(int x, int y);
};
// Returns the grid cell at coordinates x and y from the grid cell array stored at offset 8 of this TES object.
// @fnv 0x00457050
GridCell* TES::FUN_00457050(int x, int y)
{
    return (*reinterpret_cast<GridCellArray**>(reinterpret_cast<char*>(this) + 8))->Get(x, y);
}


// @fnv 0x004579e0
float __cdecl FUN_004579e0(float value)
{
    return FUN_004019b0(value);
}

struct FUN_00457b80_class
{
    int FUN_00457b80();
};

// @fnv 0x00457b80
int FUN_00457b80_class::FUN_00457b80()
{
    return *(unsigned short*)((char*)this + 0xe) & 0x7000;
}

struct FUN_00457ff0_class
{
    void FUN_00457ff0();
};

// @fnv 0x00457ff0
void FUN_00457ff0_class::FUN_00457ff0()
{
    if (reinterpret_cast<int*>(this)[0x5c / 4] == 1)
        reinterpret_cast<int*>(this)[0x5c / 4] = 2;
}

struct FUN_00458010_class
{
    void FUN_00458010();
};

// @fnv 0x00458010
void FUN_00458010_class::FUN_00458010()
{
    if (*(int*)((char*)this + 0x5c) == 2)
        *(int*)((char*)this + 0x5c) = 1;
}

struct BSSystemUtility
{
    static int s_iUpdateEnabled;
};
struct LoadingMenu
{
    bool GetFloat(int);
public:
    void SetFloatFlag(int, bool);
};
// Returns the result of LoadingMenu::GetFloat(0xa) when s_iUpdateEnabled is set, otherwise returns 0.
// @fnv 0x004580e0
char FUN_004580e0()
{
    char result;
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        result = ((LoadingMenu*)BSSystemUtility::s_iUpdateEnabled)->GetFloat(0xa);
    }
    else
    {
        result = 0;
    }
    return result;
}

namespace fnv_004581e0 {
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct FUN_004581e0_Class
{
    unsigned char* FUN_004581e0(int);
};
// @fnv 0x004581e0
unsigned char* FUN_004581e0_Class::FUN_004581e0(int)
{
    return (*reinterpret_cast<::fnv_004581e0::GlobalObject_0045cf30 *>(&::g_011c3dbc)).Bool();
}
}  // namespace fnv_004581e0

struct FUN_00458400_cls
{
    unsigned int GetFieldD0();
};

// @fnv 0x00458400
unsigned int FUN_00458400_cls::GetFieldD0()
{
    return *(unsigned int*)((char*)this + 0xd0);
}

struct FUN_00458440_cls
{
};

struct FUN_00458420_cls : FUN_00458440_cls
{
    void FUN_00458420(int a);
};

extern float runtimeInitializationFloat654;

// @fnv 0x004587d0
float FUN_004587d0(float afValue)
{
    return runtimeInitializationFloat654 * afValue;
}

struct FUN_00458b30_class
{
    void SetByteAtOffset17(unsigned char value);
};

// @fnv 0x00458b30
void FUN_00458b30_class::SetByteAtOffset17(unsigned char value)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x11) = value;
}

struct FUN_00459470_Class
{
    char pad0[0x3c];
    int* pArray;
    int FUN_00459470(int index);
};

// @fnv 0x00459470
int FUN_00459470_Class::FUN_00459470(int index)
{
    return pArray[index];
}

struct FUN_0045a140_Class
{
    void SetShortAtOffsetBC(short value);
};

// @fnv 0x0045a140
void FUN_0045a140_Class::SetShortAtOffsetBC(short value)
{
    *(short*)((char*)this + 0xbc) = value;
}

struct FUN_0045a1a0_Class
{
    unsigned short GetShortAtOffset58();
};

// @fnv 0x0045a1a0
unsigned short FUN_0045a1a0_Class::GetShortAtOffset58()
{
    return *(unsigned short*)((char*)this + 0x58);
}

struct QueuedFile;
struct QIdlePtr
{
    QueuedFile* operator=(QueuedFile*);
};
struct FUN_0045a1c0_cls
{
    QueuedFile* ClearQueuedFile();
};
// @fnv 0x0045a1c0
QueuedFile* FUN_0045a1c0_cls::ClearQueuedFile()
{
    return ((::QueuedFile *)(reinterpret_cast<::FUN_006f74f0_cls *>((((QIdlePtr*)((char*)this + 0xa4))))->FUN_006f74f0((::ObjA *)nullptr)));
}

namespace fnv_0045a350 {
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};

struct FUN_0045a350_cls
{
    void ClearIdlePointer();
};

// @fnv 0x0045a350
void FUN_0045a350_cls::ClearIdlePointer()
{
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::fnv_0045a350::QIdlePtr &)(*(QIdlePtr*)((char*)this + 0xac)))->FUN_006f74f0((::ObjA *)(void *)(0));
}
}  // namespace fnv_0045a350

void __cdecl FUN_0065c5f0();

// @fnv 0x0045b050
void __cdecl FUN_0045b050()
{
    ::fnv_00649ec0::FUN_00649ec0();
    FUN_0065c5f0();
    ::fnv_006627e0::FUN_006627e0();
    ::fnv_004f9360::FUN_004f9360();
    ::fnv_004e00d0::FUN_004e00d0();
}

struct GO
{
    GO& operator=(void*);
};

struct FUN_0045bc40_Class
{
    char pad[0x2c];
    GO m_2c;
    void FUN_0045bc40(void* p);
};

// @fnv 0x0045bc40
void FUN_0045bc40_Class::FUN_0045bc40(void* p)
{
    m_2c = p;
}

struct FUN_004a4650_class
{
};

struct FUN_0045bc60_class
{
    void FUN_0045bc60();
};

// @fnv 0x0045bc60
void FUN_0045bc60_class::FUN_0045bc60()
{
    ::FUN_004a4650((::FUN_004a4650_ListBase *)(((FUN_004a4650_class*)((char*)this + 0x30))));
}

struct FUN_0045c4a0_class
{
    void ClearField40();
};

// @fnv 0x0045c4a0
void FUN_0045c4a0_class::ClearField40()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x40) = 0;
}

struct Flt
{
    operator unsigned int();
};

struct FUN_0045c4c0_cls
{
    unsigned int FUN_0045c4c0();
};

// @fnv 0x0045c4c0
unsigned int FUN_0045c4c0_cls::FUN_0045c4c0()
{
    return ((Flt*)((char*)this + 0x104))->operator unsigned int();
}

struct FUN_0045ce40_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    void FUN_0045ce40();
};

// @fnv 0x0045ce40
void FUN_0045ce40_class::FUN_0045ce40()
{
    m_b8 += 1;
}

struct FUN_0045ce60_Class
{
    void FUN_0045ce60();
};

// Decrements the int at offset 0xb8 of this object by one.
// @fnv 0x0045ce60
void FUN_0045ce60_Class::FUN_0045ce60()
{
    *(int*)((char*)this + 0xb8) -= 1;
}

struct FUN_0045cea0_Class
{
    void* SetValueAndGetSelf(int);
};

// @fnv 0x0045cea0
void* FUN_0045cea0_Class::SetValueAndGetSelf(int aiValue)
{
    if (this)
        *(int*)((char*)this + 4) = aiValue;
    return this;
}

struct FUN_0045d930_class
{
    void FUN_0046ffd0();
    void FUN_0045d930();
};

// @fnv 0x0045d930
void FUN_0045d930_class::FUN_0045d930()
{
    FUN_0046ffd0();
}

extern "C" void __cdecl FUN_00470070();

struct FUN_0045d950_Class
{
    void FUN_00470070();
    void FUN_0045d950();
};

// @fnv 0x0045d950
void FUN_0045d950_Class::FUN_0045d950()
{
    FUN_00470070();
}

void __cdecl FUN_00473270(void*);

struct FUN_0045dfa0_shell : public TESDataHandler
{
    void FUN_0045dfa0();
};

// @fnv 0x0045dfa0
void FUN_0045dfa0_shell::FUN_0045dfa0()
{
    FUN_00473270(((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::FUN_0045dfc0_shell *>(this)->FUN_0045dfc0())));
}

struct HUDMainMenu
{
    enum HUD_MENU_MODE
    {
        HUD_MENU_NONE = 0
    };
    HUD_MENU_MODE m_eHudMenuMode;
};


// Returns the HUD menu mode stored at offset 0x1c4 of _pme, or HUD_MENU_NONE when _pme is null.
// @fnv 0x00458030
HUDMainMenu::HUD_MENU_MODE FUN_00458030()
{
    HUDMainMenu::HUD_MENU_MODE mode;
    if (::g_pHudMainMenuInstance)
        mode = *(HUDMainMenu::HUD_MENU_MODE*)((char*)::g_pHudMainMenuInstance + 0x1c4);
    else
        mode = HUDMainMenu::HUD_MENU_NONE;
    return mode;
}

struct FUN_00449f80_Class
{
    void* FUN_00449f80(void* a, void* b);
};
struct FUN_0044bb90_Class
{
    bool FUN_0044bb90(void* a, void* b);
};
// Calls FUN_00449f80 with a and b, then passes the result to LookupBucket and returns its bool.
// @fnv 0x0044bb90
bool FUN_0044bb90_Class::FUN_0044bb90(void* apArg1, void* apArg2)
{
    bool result;
    result = ((bool)(reinterpret_cast<::C44C8E0Map *>((((FUN_00449f80_Class*)this)->FUN_00449f80(apArg1, apArg2)))->LookupBucket({}, {})));
    return result;
}

struct FUN_0044d710_Class
{
    void* FUN_0044d710(unsigned int flags);
};
// Calls InitVtblAndCall on this, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0044d710
void* FUN_0044d710_Class::FUN_0044d710(unsigned int flags)
{
    ((FUN_0044d6f0_This*)this)->InitVtblAndCall();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0044d770_Class
{
};
struct FUN_0044d740_Class
{
    void* FUN_0044d740(unsigned int flags);
};
struct FUN_0044d810_class
{
    void FUN_0044d840();
    void* FUN_0044d810(unsigned int flags);
};

struct FUN_0044d8c0_class
{
    void FUN_0044d8f0();
    void* FUN_0044d8c0(unsigned int flags);
};

// Calls FUN_0044d8f0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0044d8c0
void* FUN_0044d8c0_class::FUN_0044d8c0(unsigned int flags)
{
    FUN_0044d8f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0044d9b0_class
{
    void FUN_0044d9b0();
};

struct FUN_0044d980_class
{
    void* FUN_0044d980(unsigned int flags);
};

namespace fnv_0044da40 {

struct FUN_0044da40_Class
{
    void FUN_0044da70();
    void* FUN_0044da40(unsigned int flags);
};

// Calls FUN_0044da70, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x0044da40
void* FUN_0044da40_Class::FUN_0044da40(unsigned int flags)
{
    FUN_0044da70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0044da40

struct FUN_0044db00_class
{
    void* FUN_0044db00(unsigned int flags);
};

namespace fnv_0044dbf0 {
struct FUN_0044dbf0_class
{
    void* FUN_0044dbf0(unsigned int flags);
};
// Calls FUN_0044c3f0, then frees this with Deallocate if flags has bit 0 set, and returns this.
// @fnv 0x0044dbf0
void* FUN_0044dbf0_class::FUN_0044dbf0(unsigned int flags)
{
    reinterpret_cast<::FUN_0044c3f0 *>(this)->FUN_0044c3f0::~FUN_0044c3f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0044dbf0

struct FUN_0044dc20_class
{
    void FUN_0044dc50();
    void* FUN_0044dc20(unsigned int flags);
};
namespace fnv_0044dce0 {

struct FUN_0044dce0_class
{
    void* FUN_0044dce0(unsigned int flags);
};

// @fnv 0x0044dce0
void* FUN_0044dce0_class::FUN_0044dce0(unsigned int flags)
{
    reinterpret_cast<::FUN_0044cae0_cls *>(this)->FUN_0044cae0_cls::~FUN_0044cae0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0044dce0

struct ObjA
{
};
struct FUN_0044e370_class
{
    ObjA* m_p;
    void* FUN_0044e370(ObjA** pArg);
};
// Stores the ObjA pointer from pArg into m_p and, if non-null, calls its FUN_0092c870, then returns this.
// @fnv 0x0044e370
void* FUN_0044e370_class::FUN_0044e370(ObjA** pArg)
{
    m_p = *pArg;
    if (m_p)
        reinterpret_cast<::FUN_0092c870_shell *>((m_p))->FUN_0092c870();
    return this;
}

namespace fnv_0044ed20 {
struct FUN_0044ed20_Class
{
    void* FUN_0044ed20(unsigned int a);
};
// Calls ClearSlots, then frees this via Deallocate when bit 0 of a is set, and returns this.
// @fnv 0x0044ed20
void* FUN_0044ed20_Class::FUN_0044ed20(unsigned int uiFlags)
{
    reinterpret_cast<::FUN_0044ee40_cls *>(this)->ClearSlots();
    if (uiFlags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0044ed20

struct FUN_0044ed50_Class
{
    void FUN_0044dd40();
    void* FUN_0044ed50(unsigned int flags);
};
struct FUN_0044f200_Class
{
    void FUN_0044f200();
};
struct FUN_0044ed80_Class
{
    void* FUN_0044ed80(unsigned int flags);
};
// Calls FUN_0044f200 on this, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0044ed80
void* FUN_0044ed80_Class::FUN_0044ed80(unsigned int flags)
{
    ((FUN_0044f200_Class*)this)->FUN_0044f200();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_0044f3b0_Class : FUN_0044f400_class
{
    void* FUN_0044f3b0(unsigned int flags);
};

// @fnv 0x0044f3b0
void* FUN_0044f3b0_Class::FUN_0044f3b0(unsigned int flags)
{
    FUN_0044f400();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00450b90 {

struct FUN_00450b90_Class
{
    void* FUN_00450b90(unsigned int flags);
};

// @fnv 0x00450b90
void* FUN_00450b90_Class::FUN_00450b90(unsigned int flags)
{
    reinterpret_cast<::Self *>(this)->DestroyAllStreams();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00450b90

struct FUN_00450c20_class
{
    void FUN_0045d970();
    void* FUN_00450c20(unsigned int flags);
};

// @fnv 0x00450c20
void* FUN_00450c20_class::FUN_00450c20(unsigned int flags)
{
    FUN_0045d970();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00450d50 {

struct FUN_00450d50_Class
{
    void* FUN_00450d50(unsigned int flags);
};

// @fnv 0x00450d50
void* FUN_00450d50_Class::FUN_00450d50(unsigned int flags)
{
    reinterpret_cast<::fnv_004e19c0::FUN_004e19c0 *>(this)->fnv_004e19c0::FUN_004e19c0::~FUN_004e19c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00450d50

struct FUN_0045c5f0_class
{
    void* FUN_0045c5f0(unsigned int flags);
};
// Calls FUN_00c47770, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x0045c5f0
void* FUN_0045c5f0_class::FUN_0045c5f0(unsigned int flags)
{
    reinterpret_cast<::FUN_00c47770 *>(this)->FUN_00c47770::~FUN_00c47770();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00510110_class
{
    void* FUN_0045df10(unsigned int flags);
    void FUN_00510110();
};
// @fnv 0x0045df10
void* FUN_00510110_class::FUN_0045df10(unsigned int flags)
{
    FUN_00510110();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0045df40_class
{
    void* FUN_0045df40(unsigned int flags);
};
// @fnv 0x0045df40
void* FUN_0045df40_class::FUN_0045df40(unsigned int flags)
{
    reinterpret_cast<::FUN_005ffb60_cls *>(this)->FUN_005ffb60_cls::~FUN_005ffb60_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0045df70_class
{
    void FUN_0058b7d0();
    void* FUN_0045df70(unsigned int flags);
};
// @fnv 0x0045df70
void* FUN_0045df70_class::FUN_0045df70(unsigned int flags)
{
    reinterpret_cast<::FUN_0058b7d0 *>(this)->FUN_0058b7d0::~FUN_0058b7d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct V446c90
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
};
struct S446c90
{
    int m0;
    int m4;
    V446c90* m8;
    void CallVirtual17();
};
// Calls virtual method f17 on the object stored in m8.
// @fnv 0x00446c90
void S446c90::CallVirtual17()
{
    m8->f17();
}

struct FUN_00446da0_Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
struct FUN_00446da0_Class
{
    char _pad[0x64];
    FUN_00446da0_Inner* p;
    void CallInnerF3();
};
// Calls f3() on the inner object pointed to by p.
// @fnv 0x00446da0
void FUN_00446da0_Class::CallInnerF3()
{
    p->f3();
}

struct Inner00446de0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};
struct FUN_00446de0_Class
{
    char _pad[0x34];
    volatile int m34;
    Inner00446de0* m38;
    int FUN_00446de0();
};
// Returns the value from m38's f4() plus the volatile m34 field.
// @fnv 0x00446de0
int FUN_00446de0_Class::FUN_00446de0()
{
    return m38->f4() + m34;
}

struct TESSaveLoadGame
{
};
struct FalloutAudioMedia
{
};
struct S78080
{
};
// Calls FUN_00878080 on the object from FUN_00446ef0(0), updates FalloutAudioMedia, and if loading is active twice, calls FUN_00861ea0 on g_TESSaveLoadGame.
// @fnv 0x00446ea0
void __cdecl FUN_00446ea0()
{
    reinterpret_cast<::FUN_00878080_Class *>((((::S78080 *)(::FUN_00446ef0()))))->FUN_00878080({});
    ::UpdateMediaLocation();
    if (reinterpret_cast<::FUN_0047c850 *>((g_TESSaveLoadGame))->EvaluateCondition() && reinterpret_cast<::FUN_0047c850 *>((g_TESSaveLoadGame))->EvaluateCondition())
        reinterpret_cast<::LLD_TESHelper *>((g_TESSaveLoadGame))->FUN_00861ea0();
}

struct IFace_447010
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned char Foo(int a, int* b, int c);
};
struct S_447010
{
    IFace_447010* m_iWordAt00;
    unsigned char CallFoo(int a, int b);
};
// Calls Foo on the interface pointer with a, the address of b and 0, returning its result.
// @fnv 0x00447010
unsigned char S_447010::CallFoo(int a, int b)
{
    unsigned char v = m_iWordAt00->Foo(a, &b, 0);
    return v;
}

struct Inner_00447040
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool Virt(int a, int* b, int c);
};
struct S_00447040
{
    int f0;
    Inner_00447040* p;
    bool CallVirtWithLocal(int a, int b);
};
// Calls Virt on the inner object with a, the address of b, and 0, returning its result.
// @fnv 0x00447040
bool S_00447040::CallVirtWithLocal(int aiArg, int aiValue)
{
    bool v = p->Virt(aiArg, &aiValue, 0);
    return v;
}

struct FUN_0044a2e0 : public std::logic_error
{
    FUN_0044a2e0(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const& a);
};
// Constructs the object from a string via the std::logic_error base constructor and sets its vtable pointer to DAT_010173dc.
// @fnv 0x0044a2e0
FUN_0044a2e0::FUN_0044a2e0(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const& strMessage)
    : std::logic_error(strMessage)
{
    *(void**)this = &DAT_010173dc;
}

struct NarrowString
{
    ~NarrowString();
};
extern int DAT_010173e8;
// @fnv 0x0044a3d0
void Dummy44a3a0::FUN_0044a3d0()
{
    *(void**)this = (void*)&DAT_010173e8;
    ::FUN_0044a540((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(((NarrowString*)((char*)this + 12))));
    ((FUN_0044d6f0_This*)this)->FUN_0044d6f0_This::FUN_00ec79a1();
}

struct FUN_0044a420_Class
{
    void* FUN_0044a420(unsigned int);
};
// Calls FUN_0044a400 on this, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0044a420
void* FUN_0044a420_Class::FUN_0044a420(unsigned int flags)
{
    ((Dummy44a400*)this)->FUN_0044a400();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0044a640 {
namespace std {
template <class _E> struct char_traits;
template <class _T> class allocator;
template <class _E, class _Tr, class _Ax> class basic_string
{
  public:
    basic_string<char, char_traits<char>, allocator<char> >& assign(const char*, unsigned int);
};
}
struct FUN_0044a640_Wrap
{
    void AssignCString(const char* s);
};
// Assigns the C string s to the string object at this, using its length from _BSStringLength.
// @fnv 0x0044a640
void FUN_0044a640_Wrap::AssignCString(const char* apString)
{
    reinterpret_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char> >*>(this)->assign(
        apString, ::FUN_0044a670(apString));
}
}  // namespace fnv_0044a640

// @fnv 0x0044a8c0
void __cdecl FUN_0044a8c0(unsigned char* dst, const unsigned char* src)
{
    *dst = *src;
}

struct FUN_0044a970_Cls
{
    int _pd0;  // +0x00
    union
    {
        char* _Ptr;     // +0x04
        char _Buf[16];  // +0x04
    } _Bx;
    int _Mysize;          // +0x14
    unsigned int _Myres;  // +0x18
    char* FUN_0044a970();
};
// Returns the string's data pointer: the heap buffer when capacity is at least 16, otherwise the inline buffer.
// @fnv 0x0044a970
char* FUN_0044a970_Cls::FUN_0044a970()
{
    return (_Myres >= 16 ? _Bx._Ptr : _Bx._Buf);
}

struct FUN_0044a9d0_Class
{
    unsigned int FUN_0044a9d0();
};
// Calls FUN_0065f7f0 and returns 1 when the result is at most 1, otherwise the result minus 1.
// @fnv 0x0044a9d0
unsigned int FUN_0044a9d0_Class::FUN_0044a9d0()
{
    unsigned int a = reinterpret_cast<::FUN_0065f7f0_Class *>(this)->FUN_0065f7f0();
    return (a <= 1) ? 1 : a - 1;
}

namespace fnv_0044ab90 {
struct VC9String : ::FUN_0044a970_Cls
{
    bool ContainsPointer(char* _Ptr);
};
// Returns true if _Ptr lies within the string's character buffer, i.e. _Myptr() <= _Ptr < _Myptr() + _Mysize.
// @fnv 0x0044ab90
bool VC9String::ContainsPointer(char* _Ptr)
{
    if (_Ptr == 0 || _Ptr < FUN_0044a970() || FUN_0044a970() + _Mysize <= _Ptr)
        return false;
    else
        return true;
}
}  // namespace fnv_0044ab90

struct Alloc44abf0
{
    unsigned int FUN_0044abf0() const;
};
// @fnv 0x0044a2c0
void FUN_0044a2c0_class::FUN_0044a2c0()
{
    reinterpret_cast<::Alloc44abf0 *>((((FUN_0044abf0*)((char*)this + 8))))->FUN_0044abf0();
}
// Computes (unsigned)-1 / 4 and returns it, or 1 if that result is zero.
// @fnv 0x0044abf0
unsigned int Alloc44abf0::FUN_0044abf0() const
{
    unsigned int _Count = (unsigned int)-1 / 4;
    return (_Count > 0 ? _Count : 1);
}

struct FUN_0043bb80_shell
{
    void DestroyLoadedFile();
};
struct FUN_0044b1f0_class
{
    void* FUN_0044b1f0(unsigned int flags);
};
// Calls DestroyLoadedFile on this, deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x0044b1f0
void* FUN_0044b1f0_class::FUN_0044b1f0(unsigned int flags)
{
    reinterpret_cast<FUN_0043bb80_shell*>(this)->DestroyLoadedFile();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

extern int DAT_01017294;
struct FUN_0044cb70_Holder
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    unsigned char m_C;
    FUN_0044cb70_Holder* FUN_0044cb70();
};
// @fnv 0x0044cb70
FUN_0044cb70_Holder* FUN_0044cb70_Holder::FUN_0044cb70()
{
    m_iWordAt00 = (void*)&DAT_01017294;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_C = 0;
    return this;
}

extern int DAT_010172ac;
struct FUN_0044cbb0_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    unsigned char m_iThirdValue;
    FUN_0044cbb0_class();
};
// @fnv 0x0044cbb0
FUN_0044cbb0_class::FUN_0044cbb0_class()
{
    m_iWordAt00 = &DAT_010172ac;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

extern int DAT_010172c4;
struct FUN_0044cc50_class
{
    int* vfn;
    int m_iWordAt04;
    int m_8;
    unsigned char m_iThirdValue;
    FUN_0044cc50_class* FUN_0044cc50();
};
// @fnv 0x0044cc50
FUN_0044cc50_class* FUN_0044cc50_class::FUN_0044cc50()
{
    vfn = &DAT_010172c4;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    return this;
}

extern int DAT_010172d0;

struct FUN_0044cc90_Class
{
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    unsigned char m_iThirdValue;
    FUN_0044cc90_Class();
};

// @fnv 0x0044cc90
FUN_0044cc90_Class::FUN_0044cc90_Class()
{
    vtbl = &DAT_010172d0;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

struct FUN_0044cd00_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    FUN_0044cd00_Class* Init(void* a, void* b, void* c);
};

// Stores the three arguments into m_00, m_04 and m_08, clears m_0c and m_10, and returns this.
// @fnv 0x0044cd00
FUN_0044cd00_Class* FUN_0044cd00_Class::Init(void* pFirst, void* pSecond, void* pThird)
{
    m_00 = pFirst;
    m_04 = pSecond;
    m_08 = pThird;
    m_0c = 0;
    m_10 = 0;
    return this;
}

struct CF_0081c630
{
    CF_0081c630();
    int pad;
};
struct FUN_0044d000
{
    int a;
    int b;
    int c;
    int d;
    int e;
    CF_0081c630 f;
    CF_0081c630 g;
    int h;
    int i;
    int j;
    FUN_0044d000(intptr_t p1, intptr_t p2, intptr_t p3, int p4);
};
// Initializes the four given values into a-d and zeroes e, h and i.
// @fnv 0x0044d000
FUN_0044d000::FUN_0044d000(intptr_t aiA, intptr_t aiB, intptr_t aiC, int aiD)
{
    a = aiA;
    b = aiB;
    c = aiC;
    d = aiD;
    e = 0;
    h = 0;
    i = 0;
}


// @fnv 0x0044d5b0
void __cdecl FUN_0044d5b0(unsigned int a)
{
    TlsGetValue(a);
}

int __cdecl FUN_0044d5b0(int);
struct FUN_0044d5c0_Cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int FUN_0044d5c0(intptr_t);
};
struct S_0044dbc0
{
    void* FUN_0044dbc0(unsigned int);
};
// Calls FUN_0044c1e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0044dbc0
void* S_0044dbc0::FUN_0044dbc0(unsigned int flags)
{
    reinterpret_cast<::HashMap44c1e0 *>(this)->HashMap44c1e0::~HashMap44c1e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct QueueObj
{
    QueueObj(int a);
};
struct FUN_0044dfc0
{
    int m0;
    QueueObj m4;
    FUN_0044dfc0();
};
// Initializes m0 to 0 and constructs m4 with 0.
// @fnv 0x0044dfc0
FUN_0044dfc0::FUN_0044dfc0() : m0(0), m4(0)
{}

struct FUN_0044e010_class
{
    unsigned int m_flags;
    void FUN_0044e010(bool set);
};
// Sets or clears bit 0 of m_flags according to set.
// @fnv 0x0044e010
void FUN_0044e010_class::FUN_0044e010(bool set)
{
    if (set)
        m_flags |= 1;
    else
        m_flags &= ~1;
}

struct FUN_0044e120_Cls
{
    void CallAndAccumulate(int a, int b, int* c, int d);
};
// Calls CallAndAccumulate on the object with b, a scaled local value (4*c), a pointer to that local, and 1.
// @fnv 0x0044e0f0
void __cdecl CallWithScaledArg(FUN_0044e120_Cls* pObject, int b, int iScale)
{
    int iValue = 4;
    pObject->CallAndAccumulate(b, iValue * iScale, &iValue, 1);
}

extern int DAT_011f4300;
// @fnv 0x00450430
void __cdecl FUN_00450430(int param_1)
{
    DAT_011f4300 = param_1;
}

extern unsigned char DAT_01202d62;
// @fnv 0x00450440
void FUN_00450440(unsigned char value)
{
    DAT_01202d62 = value;
}

// @fnv 0x00450450
void FUN_00450450(int a)
{
    DAT_012677b8 = a;
}

extern float DAT_011afe70;

// @fnv 0x00450460
void FUN_00450460(float value)
{
    DAT_011afe70 = value;
}

extern unsigned char DAT_011afe59;

// @fnv 0x00450490
void FUN_00450490(unsigned char value)
{
    DAT_011afe59 = value;
}

extern float DAT_012677c0;

// @fnv 0x004504a0
void FUN_004504a0(float value)
{
    DAT_012677c0 = value;
}

extern float DAT_012677bc;

// @fnv 0x004504b0
void FUN_004504b0(float value)
{
    DAT_012677bc = value;
}

float DAT_011afe74;

// @fnv 0x004504c0
void FUN_004504c0(float value)
{
    DAT_011afe74 = value;
}

float DAT_011afe78;

// @fnv 0x004504d0
void FUN_004504d0(float v)
{
    DAT_011afe78 = v;
}

// @fnv 0x004504e0
void FUN_004504e0(int a)
{
    (*reinterpret_cast<int *>(&::DAT_011afe7c)) = a;
}

// @fnv 0x00450510
void FUN_00450510(float a)
{
    DAT_011ad7e4 = a;
}


// @fnv 0x00450520
void FUN_00450520(float value)
{
    DAT_011ad7e8 = value;
}


// @fnv 0x00450530
void FUN_00450530(float value)
{
    DAT_011ad7ec = value;
}


// @fnv 0x00450540
void FUN_00450540(float value)
{
    DAT_011ad7f0 = value;
}


// @fnv 0x00450550
void FUN_00450550(float value)
{
    DAT_011ad7f4 = value;
}

extern unsigned char DAT_011f4460;

// @fnv 0x00450560
void FUN_00450560(unsigned char value)
{
    DAT_011f4460 = value;
}

class NiNode;
struct Model
{
};
struct FUN_00450570_Class
{
    int _pad[8];
    Model* m20;
    NiNode* FUN_00450570();
};
// Returns the object 3D from m20's model, or null when m20 is null.
// @fnv 0x00450570
NiNode* FUN_00450570_Class::FUN_00450570()
{
    return m20 ? ((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(m20)))) : 0;
}

// @fnv 0x004505d0
void FUN_004505d0(int param_1)
{
    DAT_01267b68 = param_1;
}

// @fnv 0x004505e0
void __cdecl FUN_004505e0(int value)
{
    (*reinterpret_cast<int *>(&::g_pfnC11F0EmissiveChanged)) = value;
}

namespace fnv_004505f0 {
struct NiNode
{
    NiNode(unsigned short);
};
extern int DAT_010178bc;
struct FUN_004505f0 : NiNode
{
    FUN_004505f0();
};
// @fnv 0x004505f0
FUN_004505f0::FUN_004505f0() : NiNode(0)
{
    *(void**)this = &DAT_010178bc;
}
}  // namespace fnv_004505f0

extern float DAT_011b0128;

// @fnv 0x00450670
void FUN_00450670(float value)
{
    DAT_011b0128 = value;
}

extern float DAT_011b0150;

// @fnv 0x00450680
void FUN_00450680(float value)
{
    DAT_011b0150 = value;
}

extern float DAT_01267bc0;

// @fnv 0x00450690
void FUN_00450690(float value)
{
    DAT_01267bc0 = value;
}


// @fnv 0x004506a0
void __cdecl FUN_004506a0(int a)
{
    (*reinterpret_cast<int *>(&::DAT_01202e08)) = a;
}

struct GlobalObject_0045d060
{
};
// Reads floats from three global objects and passes them to SetFloatAt with several slot indices.
// @fnv 0x004506b0
void FUN_004506b0()
{
    float v;
    v = *((float *)&(::FUN_00403e20((float *)&(::g_011c3d0c))));
    SetFloatAt(2, v);
    v = *((float *)&(::FUN_00403e20((float *)&(::g_011c3ec0))));
    SetFloatAt(3, v);
    v = *((float *)&(::FUN_00403e20((float *)&(::g_011c3d78))));
    SetFloatAt(0, v);
    SetFloatAt(1, v);
    SetFloatAt(4, v);
    SetFloatAt(5, v);
    SetFloatAt(8, v);
    SetFloatAt(10, v);
}

struct Unk_00450bc0
{
    void* FUN_00450bc0(unsigned int);
};
// @fnv 0x00450bc0
void* Unk_00450bc0::FUN_00450bc0(unsigned int flags)
{
    reinterpret_cast<::OwnerC44 *>(this)->FUN_00c44b70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00856870_Holder
{
};
struct S_00450bf0
{
    void* FUN_00450bf0(unsigned int flags);
};
// Calls FUN_00856870 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00450bf0
void* S_00450bf0::FUN_00450bf0(unsigned int flags)
{
    reinterpret_cast<::fnv_00856870::FUN_00856870 *>((((FUN_00856870_Holder*)this)))->fnv_00856870::FUN_00856870::~FUN_00856870();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_00450d50
{
};
struct This_00450d00
{
    char _pad[0x64];
    S_00450d50* _p64;
    void FUN_00450d00();
};
// Calls FUN_00450d50(1) on the object at _p64 if non-null, then sets _p64 to null.
// @fnv 0x00450d00
void This_00450d00::FUN_00450d00()
{
    S_00450d50* b;
    {
        S_00450d50* a = _p64;
        b = a;
        b ? ((int)(reinterpret_cast<::fnv_00450d50::FUN_00450d50_Class *>((b))->FUN_00450d50(1))) : 0;
    }
    _p64 = 0;
}

struct NiNode;
// @fnv 0x00451010
unsigned int __cdecl FUN_00451010()
{
    return (*reinterpret_cast<::Flt *>(&::g_011ca0d8));
}

struct BSSpinLockUnlock
{
};
// @fnv 0x00452530
void __cdecl FUN_00452530()
{
    reinterpret_cast<::RecursiveSpinLock *>((((BSSpinLockUnlock*)&::g_spinLock)))->FUN_0040fba0();
}


// @fnv 0x00452e40
void FUN_00452e40(unsigned char value)
{
    (*reinterpret_cast<unsigned char *>(&::DAT_011af70c)) = value;
}

struct CP_008c48d0
{
};
struct FUN_00552840_Class
{
};
struct FUN_004baab0_Class
{
};
struct FUN_00453900_Class
{
    void FUN_00453900();
};
// @fnv 0x00453900
void FUN_00453900_Class::FUN_00453900()
{
    void* prev = ((void *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath()));
    if (prev)
        reinterpret_cast<::FUN_00552840_cls *>((((FUN_00552840_Class*)prev)))->FUN_00552840();
    else
        reinterpret_cast<::FUN_004baab0_shell *>((((FUN_004baab0_Class*)((int*)this)[2])))->FUN_004baab0();
}

struct FUN_004567b0_Owner
{
    unsigned short FUN_004567b0();
};
// Converts the float at offset 0xB8 to an unsigned int and calls GetShortAtOffset40 on the resulting object, returning its unsigned short result.
// @fnv 0x004567b0
unsigned short FUN_004567b0_Owner::FUN_004567b0()
{
    unsigned int v = ((Flt*)((char*)this + 0xB8))->operator unsigned int();
    return ((FUN_004567e0_Class*)v)->GetShortAtOffset40();
}

namespace fnv_00456a60 {
struct CP_008c48d0
{
};
struct S554910
{
};
struct Sbad40
{
};
struct S_456a60
{
    int m0;
    int m4;
    Sbad40* m8;
    void FUN_00456a60();
};
// Gets the previous path object; if it exists it calls FUN_00554910 on it, otherwise calls FUN_004bad40 on m8.
// @fnv 0x00456a60
void S_456a60::FUN_00456a60()
{
    S554910* p = (S554910*)((reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath()));
    if (p)
    {
        reinterpret_cast<::ExtraDataList *>((p))->FUN_00554910();
    }
    else
    {
        reinterpret_cast<::FUN_004bad40_shell *>((m8))->FUN_004bad40();
    }
}
}  // namespace fnv_00456a60

extern unsigned char DAT_011c3c0d;
// @fnv 0x00456c80
void FUN_00456c80(unsigned char a)
{
    DAT_011c3c0d = a;
}

struct FUN_00541570_shell
{
    unsigned int GetField1C();
};
struct FUN_00457880_Class
{
    unsigned int FUN_00457880(intptr_t);
};
struct NiPoint3
{
    float x, y, z;
    NiPoint3& Subtract(const NiPoint3& pt);
};
// Subtracts pt's x, y and z from this point's components and returns *this.
// @fnv 0x004578c0
NiPoint3& NiPoint3::Subtract(const NiPoint3& aPoint)
{
    x -= aPoint.x;
    y -= aPoint.y;
    z -= aPoint.z;
    return *this;
}

struct CloningProcess;
struct NiAVObject
{
};
void __cdecl FUN_00457a00(NiAVObject*);
struct FUN_00457ba0_class
{
    NiAVObject* FUN_00457ba0(NiAVObject* apObject, CloningProcess* arCloneData);
};
// Clones apObject using arCloneData, passes the clone to FUN_00457a00, and returns it (or null if apObject is null).
// @fnv 0x00457ba0
NiAVObject* FUN_00457ba0_class::FUN_00457ba0(NiAVObject* apObject, CloningProcess* arCloneData)
{
    NiAVObject* pClonedObject = 0;
    if (apObject)
    {
        pClonedObject = ((::NiAVObject *)(reinterpret_cast<::A5D2C0Object *>((apObject))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(*arCloneData))));
        FUN_00457a00(pClonedObject);
    }
    return pClonedObject;
}

struct LoadingMenuHelper
{
};
// @fnv 0x00458060
void FUN_00458060(bool param_1)
{
    if (BSSystemUtility::s_iUpdateEnabled)
        reinterpret_cast<::LoadingMenu *>((((LoadingMenuHelper*)BSSystemUtility::s_iUpdateEnabled)))->SetFloatFlag(10, param_1);
}

// Returns 1 if the update-enabled loading menu exists and its float value at index 3 is nonzero, otherwise 0.
// @fnv 0x00458140
char FUN_00458140()
{
    int result;
    if (BSSystemUtility::s_iUpdateEnabled && ((LoadingMenu*)BSSystemUtility::s_iUpdateEnabled)->GetFloat(3))
        result = 1;
    else
        result = 0;
    return result;
}

// @fnv 0x004583f0
void FUN_004583f0(unsigned char abVal)
{
    DAT_011ad80c = abVal;
}

struct HelperD0_458840
{
};
struct Helper80_458840
{
    void FUN_00458880(void* a, void* b);
};
struct FUN_00458840_Class
{
    void FUN_00458840();
};
struct FUN_004588d0_Sub
{
};
struct FUN_004588d0_Class
{
    char pad[0x90];
    FUN_004588d0_Sub sub;
    bool IsSubCallZero();
};
// If IsSubCallZero returns true, calls FUN_00458880 on the sub-object at offset 0x10 with this and the pointer at offset 0x90.
// @fnv 0x00458840
void FUN_00458840_Class::FUN_00458840()
{
    if (reinterpret_cast<::FUN_004588d0_Class *>((((HelperD0_458840*)this)))->IsSubCallZero())
    {
        ((Helper80_458840*)((char*)this + 0x10))->FUN_00458880(this, (void*)((char*)this + 0x90));
    }
}
// Calls sub.FUN_00458900 with the result of FUN_00458b20(0.001f) and returns whether that call returns 0.
// @fnv 0x004588d0
bool FUN_004588d0_Class::IsSubCallZero()
{
    return ((int)(reinterpret_cast<::S00458900_Vector *>(&(sub))->FUN_00458900((const ::S00458900_Vector *)(void *)(::FUN_00458b20()), {}))) == 0;
}

struct FUN_0045a160_Cls
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
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void Virt(int, int) = 0;
    void FUN_0045a160(int);
};
// Calls the virtual function Virt with the given argument and 1.
// @fnv 0x0045a160
void FUN_0045a160_Cls::FUN_0045a160(int aiValue)
{
    Virt(aiValue, 1);
}

// @fnv 0x0045a190
unsigned int __cdecl FUN_0045a190()
{
    return (*reinterpret_cast<::Flt *>(&::g_011ded58));
}

struct FUN_0045baf0_This
{
    virtual void f0();
    virtual void f1();
    virtual int f2();
    bool IsEqual(int);
};
// Returns whether f2() equals the given value.
// @fnv 0x0045baf0
bool FUN_0045baf0_This::IsEqual(int aiValue)
{
    return f2() == aiValue;
}

struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct S_FUN_0045bc00
{
    char _pad[156];
    Arr arr;
    std::uintptr_t FUN_0045bc00(unsigned int i);
};
// Returns the element at index i converted to unsigned int, or 0 when i is out of range.
// @fnv 0x0045bc00
std::uintptr_t S_FUN_0045bc00::FUN_0045bc00(unsigned int uiIndex)
{
    if (reinterpret_cast<::FUN_00658930_class *>(&(arr))->GetShortAtOffsetA() <= uiIndex)
    {
        return 0;
    }
    else
    {
        return ((Flt*)arr.GetAt(uiIndex))->operator unsigned int();
    }
}

struct FUN_0045c4e0_This
{
    unsigned char pad[0xCC];
    void* fieldCC;
    void SetFieldCC(void*);
};
namespace fnv_0045d0e0 {
struct GlobalObject_0045d060
{
    ~GlobalObject_0045d060();
    void* FUN_0045d0e0(unsigned int);
};
// Runs the destructor, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0045d0e0
void* GlobalObject_0045d060::FUN_0045d0e0(unsigned int flags)
{
    reinterpret_cast<::FUN_0045d110 *>((this))->FUN_0045d110::~FUN_0045d110();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0045d0e0

extern int DAT_011f35a4;
void __cdecl FUN_0045d190();
// @fnv 0x0045d180
int __cdecl FUN_0045d180()
{
    FUN_0045d190();
    return DAT_011f35a4;
}

int ClearLowBit(int*);
struct FUN_0044df20_b
{
    bool Call();
};
struct FUN_0044df00Class
{
    void* m_pHead;
    int* FUN_0044df00();
};
struct Interface
{
};
struct VObj_44eb80
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
    virtual void v30(int a, int* b);
};
struct FUN_006ec9b0_Class
{
    VObj_44eb80* m_pEntryObject;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_0044df00Class m_list14;
    FUN_0044df00Class m_list18;
    bool FUN_0044eb80(int a, int* pKey, int* pOut);
};
// @fnv 0x0044eb80
bool FUN_006ec9b0_Class::FUN_0044eb80(int a, int* pKey, int* pOut)
{
    bool bResult = false;
    while (1)
    {
        bResult = reinterpret_cast<::Worker *>(this)->ProcessNodeChain(a, *pKey);
        if (bResult)
        {
            if (ClearLowBit((int*)&m_list18))
            {
                if (((FUN_0044df20_b*)m_list18.FUN_0044df00())->Call())
                    continue;
                m_pEntryObject->v30(*m_list18.FUN_0044df00(), pKey);
                *pOut = m_list18.FUN_0044df00()[1];
                bResult = true;
                ::FUN_0040fbe0();
                if (((FUN_0044df20_b*)m_list18.FUN_0044df00())->Call())
                {
                    *pOut = 0;
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
        else
        {
            if (ClearLowBit((int*)&m_list14))
            {
                if (((FUN_0044df20_b*)m_list14.FUN_0044df00())->Call())
                    continue;
                m_pEntryObject->v30(*m_list14.FUN_0044df00(), pKey);
                *pOut = m_list14.FUN_0044df00()[1];
                bResult = true;
                ::FUN_0040fbe0();
                if (((FUN_0044df20_b*)m_list14.FUN_0044df00())->Call())
                {
                    *pOut = 0;
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return bResult;
}

struct FUN_00452df0_class
{
    bool FUN_00452df0(float* a);
};
// Returns true when the two floats at this and the two floats at a are pairwise equal.
// @fnv 0x00452df0
bool FUN_00452df0_class::FUN_00452df0(float* afValues)
{
    return *(float*)this == *afValues && *(float*)((char*)this + 4) == afValues[1];
}

// Sets or clears bit a in DAT_011ca08c depending on b.
// @fnv 0x00457000
void __cdecl FUN_00457000(int aiBitIndex, bool abSet)
{
    abSet ? (DAT_011ca08c |= (1 << aiBitIndex)) : (DAT_011ca08c &= ~(1 << aiBitIndex));
}

struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
class TESModel;
struct TESObjectREFR
{
public:
    ::TESModel *GetTESModel();
};

struct TL
{
};
struct FUN_0045c570_Class : BSFaceGenNiNode
{
    void FUN_0045c570(uintptr_t a);
};
// Sets the given flags on this node's object 3D and on each node in the linked list at offset 0xd0.
// @fnv 0x0045c570
void FUN_0045c570_Class::FUN_0045c570(uintptr_t uiFlags)
{
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((Model*)GetAnimationData()))))))))->AssignLandTexture((::TESLandTexture *)(uiFlags));
    unsigned int p = *(Flt*)((char*)this + 0xd0);
    while (p)
    {
        unsigned int n = *(Flt*)((void *)(reinterpret_cast<::ListStandIn *>((((TL*)((char*)this + 0xd0))))->FUN_0057cbe0((int **)&(*(void**)&p))));
        if (n)
            reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((Model*)(void*)n))))))))->AssignLandTexture((::TESLandTexture *)(uiFlags));
    }
}

struct FUN_0045d220
{
    FUN_0045d220();
    ~FUN_0045d220();
    char m[0x114];
};

// Allocates a FUN_0045d220 object and stores it in DAT_011f35a4 if that pointer is currently null.
// @fnv 0x0045d190
void FUN_0045d190()
{
    if (!DAT_011f35a4)
        DAT_011f35a4 = (int)new FUN_0045d220;
}

struct FUN_00446dc0_Class
{
    int FUN_00446dc0();
};
// @fnv 0x00446dc0
int FUN_00446dc0_Class::FUN_00446dc0()
{
    return ((FUN_00446de0_Class*)*(void**)((char*)this + 0x28))->FUN_00446de0();
}

struct FUN_0044e0d0_Class
{
    unsigned long long GetValue64();
};
// @fnv 0x0044e0d0
unsigned long long FUN_0044e0d0_Class::GetValue64()
{
    return *(unsigned long long*)((char*)this + 0x10);
}


// @fnv 0x0044e360
void FUN_0044e360(unsigned long param_1)
{
    TlsFree(param_1);
}

struct FUN_0044e3a0_Arg
{
    virtual void FUN_0044e3a0_arg0() = 0;
    virtual int FUN_0044e3a0_arg1(unsigned int index) = 0;
};

struct FUN_0044e3a0_Entry
{
    unsigned int threadId;
    int result;
};

struct FUN_0044e3a0_Class
{
    unsigned int count;
    void* context;
    FUN_0044e3a0_Entry* entries;
    unsigned char runLock;

    int FUN_0044e3a0(FUN_0044e3a0_Arg* arg);
};
// @fnv 0x0044d5c0
int FUN_0044d5c0_Cls::FUN_0044d5c0(intptr_t a)
{
    int r;
    r = FUN_0044d5b0(m_iWordAt04);
    if (r != 0)
        return r;
    return reinterpret_cast<::FUN_0044e3a0_Class *>(this)->FUN_0044e3a0((::FUN_0044e3a0_Arg *)(a));
}

int __cdecl InitScriptRunLock(void*);

// Acquires the run lock, calls arg's indexed method for the current slot, stores its result and thread id, then passes the result to FUN_0044e340.
// @fnv 0x0044e3a0
int FUN_0044e3a0_Class::FUN_0044e3a0(FUN_0044e3a0_Arg* arg)
{
    int result = 0;

    {
        unsigned int index = InitScriptRunLock(&runLock) - 1;

        if (index < count)
        {
            result = arg->FUN_0044e3a0_arg1(index);
            entries[index].result = result;
            entries[index].threadId = gm_GetCurrentThreadId();
            ::FUN_0044e340((unsigned long)(context), (void *)(result));
        }
    }

    return result;
}

struct FUN_0044f420_class
{
    void FUN_0044f070();
    void FUN_0044f420();
};
// @fnv 0x0044f420
void FUN_0044f420_class::FUN_0044f420()
{
    while (*(int*)((char*)this + 0x20))
        FUN_0044f070();
}

struct Setting_S
{
};

struct FUN_00450410_Class
{
    float FUN_00450410();
};

// @fnv 0x00450410
float FUN_00450410_Class::FUN_00450410()
{
    return *((float *)&(::FUN_00403e20((float *)(reinterpret_cast<Setting_S*>(this)))));
}

struct AutoMemHelper
{
    char data[3];

    AutoMemHelper(int context, bool condition, const char* file, int line);
    ~AutoMemHelper();
};

struct FUN_004e1650
{
    unsigned char data[0xa0];
    FUN_004e1650();
};

struct FUN_00450c50_Class
{
    void FUN_00450c50();
};

// Constructs a new FUN_004e1650 object and stores its pointer at offset 0x64 of this object.
// @fnv 0x00450c50
void FUN_00450c50_Class::FUN_00450c50()
{
    AutoMemHelper autoMemHelper(0x1d, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 0x286);
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x64) = new FUN_004e1650;
}

struct TESQueuedCellManager
{
    void FUN_00528540();
};

struct FUN_00452eb0_Class
{
    void FUN_00452eb0();
};

// @fnv 0x00452eb0
void FUN_00452eb0_Class::FUN_00452eb0()
{
    ::DAT_011c9618->FUN_00528540();
}

struct FUN_004538e0_Class
{
    void FUN_004538e0(int);
};
// @fnv 0x004538e0
void FUN_004538e0_Class::FUN_004538e0(int)
{
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(this));
}

struct FUN_00454420_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int* m_ppCellBufferA;
    int GetEntry(unsigned int aiIndex);
};

// @fnv 0x00454420
int FUN_00454420_Class::GetEntry(unsigned int aiIndex)
{
    return m_ppCellBufferA[aiIndex];
}

struct FUN_00877a10_Class
{
    void FUN_00877a10();
};
struct FUN_0045d240_Class : FUN_00877a10_Class
{
    void FUN_0045d240();
};
// @fnv 0x0045d240
void FUN_0045d240_Class::FUN_0045d240()
{
    FUN_00877a10_Class::FUN_00877a10();
}

struct Vector2
{
    float x;
    float y;
};

struct Vector3
{
};

struct TESObjectLAND
{
};

struct FakeCell
{
};

struct FUN_00451900_shell
{
    FakeCell* FUN_00451900(int, int);
    Vector3* FUN_00457720(const Vector2*);
};
// @fnv 0x00457880
unsigned int FUN_00457880_Class::FUN_00457880(intptr_t arg)
{
    unsigned int pRes;
    FUN_00541570_shell* pObj;
    pRes = 2;
    pObj = ((::FUN_00541570_shell *)(reinterpret_cast<::FUN_00451900_shell *>(this)->FUN_00457720((const ::Vector2 *)(arg))));
    if (pObj)
        pRes = pObj->GetField1C();
    return pRes;
}


extern int DAT_01186088;
extern int DAT_0118608c;
extern Vector3* DAT_011c3ef8;

// @fnv 0x00457720
Vector3* FUN_00451900_shell::FUN_00457720(const Vector2* position)
{
    Vector3* yBlock = 0;
    int y8 = ::FUN_00406d90(position->x);
    int xBlock = ::FUN_00406d90(position->y);
    int result;
    int x;

    if (y8 % 4096 == 0 && y8 > position->x)
        --y8;

    if (xBlock % 4096 == 0 && xBlock > position->y)
        --xBlock;

    result = y8 - y8 % 128;
    x = xBlock - xBlock % 128;

    if (result == DAT_0118608c && result == DAT_0118608c)
    {
        yBlock = DAT_011c3ef8;
    }
    else
    {
        int cellXVal = y8 >> 12;
        int cellY = xBlock >> 12;
        FakeCell* cell7 = FUN_00451900(cellXVal, cellY);

        if (cell7)
        {
            yBlock = ((::Vector3 *)(reinterpret_cast<::FUN_0053a5e0_cls *>((reinterpret_cast<::S00546fb0_Cell *>((cell7))->FUN_00546fb0()))->FUN_0053a5e0({})));

            if (yBlock)
            {
                DAT_011c3ef8 = yBlock;
                DAT_0118608c = result;
                DAT_01186088 = x;
            }
        }
    }

    return yBlock;
}

struct C4442C0Object;

class C4442C0Ptr
{
  public:
    C4442C0Ptr(C4442C0Object* pkObject);
    ~C4442C0Ptr();

    C4442C0Object* m_pPointer;
};

class C4442C0Queue
{
  public:
    void QueueFullWithNullResult(int iA, int iB, int iC, int iD, int iE, bool bF, bool bG, bool bH);
};

// Creates a null C4442C0Ptr and forwards all arguments to QueueFull.
// @fnv 0x004442c0
void C4442C0Queue::QueueFullWithNullResult(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5, bool abFlag1,
                                           bool abFlag2, bool abFlag3)
{
    C4442C0Ptr spResult(0);
    reinterpret_cast<::fnv_00444350::HeadLoader444 *>(this)->FUN_00444350((void *)(aiArg1), aiArg2, (::fnv_00444350::QPtr444 *)&(spResult), aiArg3, (::fnv_00444350::QFile444 *)(aiArg4), (void *)(aiArg5), abFlag1, abFlag2, abFlag3);
}

struct FUN_00ec7944
{
    virtual ~FUN_00ec7944();
    unsigned int unknown04;
    unsigned int unknown08;
    FUN_00ec7944(const FUN_00ec7944& other);
};
struct FUN_0044a500
{
    FUN_0044a500(const FUN_0044a500& other);
    ~FUN_0044a500();
};
struct FUN_0044a450 : FUN_00ec7944
{
    FUN_0044a500 value;
    virtual ~FUN_0044a450();
    FUN_0044a450(const FUN_0044a450& other);
};
// Calls FUN_0044a450 with a, stores the address of DAT_010173dc at this, and returns this.
// @fnv 0x0044a9a0
void* FUN_0044a9a0_Class::FUN_0044a9a0(const struct FUN_0044a450* apOther)
{
    new ((void *)this) ::FUN_0044a450(*apOther);
    *reinterpret_cast<void**>(this) = &DAT_010173dc;
    return this;
}
// Copy constructor: copies the base FUN_00ec7944 subobject and the value member from other.
// @fnv 0x0044a450
FUN_0044a450::FUN_0044a450(const FUN_0044a450& other) : FUN_00ec7944(other), value(other.value)
{}

void __cdecl AssertHelper();
void __cdecl CopyHelper(void* dst, unsigned int count, const void* src, unsigned int n);

struct FUN_0044a690_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_uiItemCount;
    int m_other;
    void SetCount(unsigned int count);
    FUN_0044a690_cls* EraseRange(unsigned int a1, unsigned int a2);
};

// Removes a2 elements starting at index a1 by shifting the tail left and reducing the count, asserting that a1 is within the count.
// @fnv 0x0044a690
FUN_0044a690_cls* FUN_0044a690_cls::EraseRange(unsigned int uiStart, unsigned int a2)
{
    if ((unsigned int)m_uiItemCount < uiStart)
    {
        AssertHelper();
    }
    if ((unsigned int)m_uiItemCount - uiStart < a2)
    {
        a2 = (unsigned int)m_uiItemCount - uiStart;
    }
    if (a2 > 0)
    {
        CopyHelper(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + uiStart, (unsigned int)m_other - uiStart, reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + uiStart + a2,
                   (unsigned int)m_uiItemCount - uiStart - a2);
        unsigned int newCount = (unsigned int)m_uiItemCount - a2;
        SetCount(newCount);
    }
    return this;
}

extern const char kThreadSafeStructuresSourceFile[];

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
    int iPrev;
};

struct QHeadPtr
{
    int m_iWordAt00;
};

struct QHeadPtrDest
{
    int m_iWordAt00;
};

struct HandlerRegistration
{
    HandlerRegistration* pNext;
    QHeadPtrDest kValue;
    HandlerRegistration();
};


struct QueueRoot
{
    virtual void Unk00();
    virtual void Unk04();
    virtual void Signal();
    HandlerRegistration* pHead;
    HandlerRegistration* pTail;
};

struct LockFreeQueue
{
    QueueRoot* pRoot;
    HandlerRegistration** ppHazard;
    void Enqueue(const QHeadPtr& rkValue);
};

// Allocates a node holding rkValue and appends it to the lock-free queue, retrying until the tail link is swapped and signalling the root.
// @fnv 0x0044cd40
void LockFreeQueue::Enqueue(const QHeadPtr& rkValue)
{
    AutoMemContext kMemContext2(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, kThreadSafeStructuresSourceFile, 0x76);
    HandlerRegistration* volatile pTail = 0;
    HandlerRegistration* pNode2 = new HandlerRegistration;
    reinterpret_cast<::NP_0092c820 *>(&(pNode2->kValue))->FUN_0092c820((const ::NP_0092c820 &)(rkValue));
    while (1)
    {
        pTail = pRoot->pTail;
        *ppHazard = pTail;
        if (pTail != pRoot->pTail)
            continue;
        HandlerRegistration* pNext2 = pTail->pNext;
        if (pTail != pRoot->pTail)
            continue;
        if (pNext2)
        {
            ::FUN_004491c0((volatile long *)(void *)(&pRoot->pTail), (int)pNext2, (int)pTail);
            continue;
        }
        if (::FUN_004491c0((volatile long *)(pTail), (int)pNode2, 0))
        {
            pRoot->Signal();
            break;
        }
    }
    ::FUN_004491c0((volatile long *)(void *)(&pRoot->pTail), (int)pNode2, (int)pTail);
    *ppHazard = 0;
}

struct MemoryScope
{
    unsigned char category, previous, active;
    MemoryScope(int, bool, const char*, int);
    ~MemoryScope();
};
struct Node
{
    int key;
    int value;
    Node* next;
    Node(int, int, int*);
};
struct TaggedPointer
{
    Node* node;
    TaggedPointer(int, Node*);
};
struct List
{
    Node* head;
    Node* ClearLowBit();
};
struct NodeFactory
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
    virtual int get();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void notify();
};
struct Object
{
    NodeFactory* object;
    int unk04, unk08, unk0c;
    int lock;
    List list;
    bool InsertOrReplaceNode(int, int, int*, bool);
};
// @fnv 0x0044d240
bool Object::InsertOrReplaceNode(int a, int b, int* value, bool replace)
{
    MemoryScope scope(6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.inl", 391);
    bool result2 = true;
    Node* node7 = 0;
    while (true)
    {
        if (reinterpret_cast<::Worker *>(this)->ProcessNodeChain(a, b))
        {
            delete node7;
            if (replace)
                list.ClearLowBit()->value = *value;
            else
                result2 = false;
            break;
        }
        if (!node7)
            node7 = new Node(object->get(), b, value);
        TaggedPointer previous2(0, list.ClearLowBit());
        TaggedPointer current2(0, node7);
        node7->next = previous2.node;
        if (::FUN_004491c0((volatile long *)(lock), (long)(((::Node **)(::FUN_00559450((int *)&(current2))))), (long)(((::Node **)(::FUN_00559450((int *)&(previous2)))))))
        {
            object->notify();
            break;
        }
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return result2;
}

struct Flag
{
    bool value;
};
struct Value
{
    int value;
};
struct C44E4A0ScalarTag
{
};
struct C44E4A0RangeTag
{
};
// Calls FUN_0044e4a0 with the results of CallWithFlag on p1 and p2, p3, a char from FUN_0065fd70, and the bool from FUN_0065e750.
// @fnv 0x0044d600
void __cdecl FUN_0044d600(Value aValue1, Value aValue2, intptr_t aiArg)
{
    Flag zero = {};
    bool result = ((bool)(::FUN_0065e750(&aValue1, &aiArg)));
    (void)result;
    ::FUN_0044e4a0((void **)(::CallWithFlag((int *)(::Value *)(&aValue1))), (void **)(::CallWithFlag((int *)(::Value *)(&aValue2))), (void **)(aiArg), ::C44E4A0ScalarTag{}, ::C44E4A0RangeTag{});
}


class FUN_0044d770_base
{
  public:
    virtual ~FUN_0044d770_base();
};

class FUN_0044d770_cls : public FUN_0044d770_base
{
  public:
    int unk04;
    int unk08;
    void* m_0c;
    void* m_10;
    virtual ~FUN_0044d770_cls();
};
// Calls FUN_0044d770 on this, frees this when flags has bit 1 set, and returns this.
// @fnv 0x0044d740
void* FUN_0044d740_Class::FUN_0044d740(unsigned int flags)
{
    reinterpret_cast<::FUN_0044d770_cls *>((((FUN_0044d770_Class*)this)))->FUN_0044d770_cls::~FUN_0044d770_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_0044b4b0
{
    virtual ~FUN_0044b4b0();
};
FUN_0044b4b0::~FUN_0044b4b0()
{}

struct FUN_0044d9b0 : FUN_0044b4b0
{
    void* m04;
    void* m08;
    void* m0c;
    virtual ~FUN_0044d9b0();
};
// @fnv 0x0044d980
void* FUN_0044d980_class::FUN_0044d980(unsigned int flags)
{
    reinterpret_cast<::FUN_0044d9b0 *>((((FUN_0044d9b0_class*)this)))->FUN_0044d9b0::~FUN_0044d9b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls FUN_00528e40(1), then deallocates m0c and m04.
// @fnv 0x0044d9b0
FUN_0044d9b0::~FUN_0044d9b0()
{
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(1);
    void* p = m0c;
    ::FUN_00401030(p);
    void* q = m04;
    ::FUN_00401030(q);
}


class FUN_0044da70_base
{
  public:
    virtual ~FUN_0044da70_base();
};

class FUN_0044da70_cls : public FUN_0044da70_base
{
  public:
    int m_04;
    int unk08;
    void* m_0c;

    virtual ~FUN_0044da70_cls();
};

// @fnv 0x0044da70
FUN_0044da70_cls::~FUN_0044da70_cls()
{
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(1);
    void* pFirst_2 = m_0c;
    FUN_00401030(pFirst_2);
    void* pSecond = (void*)m_04;
    FUN_00401030(pSecond);
}


class FUN_0044db30_base
{
  public:
    virtual ~FUN_0044db30_base();
};

class FUN_0044db30_cls : public FUN_0044db30_base
{
  public:
    void* m_04;
    int unk08;
    void* m_0c;
    virtual ~FUN_0044db30_cls();
};
// @fnv 0x0044db00
void* FUN_0044db00_class::FUN_0044db00(unsigned int flags)
{
    reinterpret_cast<::FUN_0044db30_cls *>(this)->FUN_0044db30_cls::~FUN_0044db30_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0044db30
FUN_0044db30_cls::~FUN_0044db30_cls()
{
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(1);
    void* a = m_0c;
    FUN_00401030(a);
    void* b = m_04;
    FUN_00401030(b);
}

struct B44DD40HeadPtr
{
    void* m_pHead;

    ~B44DD40HeadPtr();
};

class FUN_0044dd40
{
  public:
    int m_iArrayLength;
    B44DD40HeadPtr m_kHead;

    ~FUN_0044dd40();
};
// Calls FUN_0044dd40, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0044ed50
void* FUN_0044ed50_Class::FUN_0044ed50(unsigned int flags)
{
    reinterpret_cast<::FUN_0044dd40 *>(this)->FUN_0044dd40::~FUN_0044dd40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0044dd40
FUN_0044dd40::~FUN_0044dd40()
{}

// Thin cdecl wrapper that forwards directly to the kernel32 TLS allocator.

// @fnv 0x0044e330
unsigned int __cdecl FUN_0044e330()
{
    return TlsAlloc();
}

int C44E4A0MemMoveS(void* pvDest, unsigned int uiDestSize, const void* pvSrc, unsigned int ItemUpdateArray);

// std::_Copy_opt for pointer-sized scalars
// Moves _Off elements from [_First,_Last) to _Dest via C44E4A0MemMoveS and returns _Dest + _Off.
// @fnv 0x0044e4a0
void** FUN_0044e4a0(void** _First, void** _Last, void** _Dest, C44E4A0ScalarTag, C44E4A0RangeTag)
{
    int iCount = (int)(_Last - _First);
    void** _Result = _Dest + iCount;
    if (iCount > 0)
        C44E4A0MemMoveS(_Dest, iCount * sizeof(void*), _First, iCount * sizeof(void*));
    return _Result;
}

struct X6f74f0
{
};
struct X6ecd40
{
};
struct X84e3a0
{
};
struct X44eed0
{
};

struct S
{
    void FUN_0044e4f0(void* arg0);
};

int ClearLowBit(int*);

struct ListNode_44ea60
{
    int item;
    int value;
    bool Call();
};

struct ListIter_44ea60
{
    void* m_pHead;
    ListNode_44ea60* FUN_0044df00();
    operator void*() const;
};

struct Owner_44ea60
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
    virtual void v30(int a, int* b);
};

struct Walker_44ea60
{
    Owner_44ea60* m_pEntryObject;
    int unk04;
    int* unk08;
    int unk0C;
    ListIter_44ea60* unk10;
    ListIter_44ea60 m_list14;
    bool FindAndProcessNode(int a, int* b, int* c);
};

// @fnv 0x0044ea60
bool Walker_44ea60::FindAndProcessNode(int a, int* b, int* apiValueOut)
{
    bool bResult = false;
    while (1)
    {
        ListIter_44ea60* pFound = ((::ListIter_44ea60 *)(reinterpret_cast<::FUN_0044ee20_class *>((m_pEntryObject))->GetElementAddress(a)));
        unk10 = pFound;
        m_list14 = *unk10;
        *unk08 = ClearLowBit((int*)&m_list14);
        FUN_0040fbe0();
        ListIter_44ea60 kNode;
        reinterpret_cast<::FUN_006ecba0_class *>(&(kNode))->FUN_006ecba0(false, (void*)ClearLowBit((int*)&m_list14));
        if ((void*)*unk10 != (void*)kNode)
        {
            continue;
        }
        if (ClearLowBit((int*)&m_list14) == 0)
        {
            bResult = false;
            break;
        }
        m_pEntryObject->v30(m_list14.FUN_0044df00()->item, b);
        *apiValueOut = m_list14.FUN_0044df00()->value;
        bResult = true;
        FUN_0040fbe0();
        if (m_list14.FUN_0044df00()->Call())
        {
            continue;
        }
        break;
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return bResult;
}

struct FUN_0044edd0_Disposable
{
    unsigned int value;
    ~FUN_0044edd0_Disposable();
};
struct FUN_0044edd0_owner
{
    virtual void OnMessage0();
    virtual void OnMessage1();
    virtual void OnMessage2();
    virtual void OnMessage3();
    virtual void OnMessage4();
    virtual void OnMessage5();
    virtual void OnMessage6();
    virtual void OnMessage7();
    virtual void OnMessage8();
    virtual void OnMessage9();
    virtual void OnMessage10(unsigned int value);
    void DispatchAndDelete(FUN_0044edd0_Disposable* object);
};
// Passes object->value to OnMessage10, then deletes object.
// @fnv 0x0044edd0
void FUN_0044edd0_owner::DispatchAndDelete(FUN_0044edd0_Disposable* pDisposable)
{
    OnMessage10(pDisposable->value);
    delete pDisposable;
}

struct Inner
{
};
struct Target
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    Inner* member14;
    void FUN_0044f3e0();
public:
    void FUN_0045ac80();
};
// @fnv 0x0044f3e0
void Target::FUN_0044f3e0()
{
    ::FUN_00559450((int *)(member14));
}

struct S_00453720_Obj
{
    S_00453720_Obj();
    int unk00;
    int unk04;
    int unk08;
};

// Returns the global S_00453720_Obj instance, allocating a new one if it is null.
// @fnv 0x00453720
S_00453720_Obj* FUN_00453720()
{
    return (*reinterpret_cast<::S_00453720_Obj * *>(&::DAT_011cc224)) ? (*reinterpret_cast<::S_00453720_Obj * *>(&::DAT_011cc224)) : new S_00453720_Obj();
}


// @fnv 0x00453850
float __cdecl FUN_00453850()
{
    return DAT_011dea30;
}

extern int DAT_011f4500;

// @fnv 0x00456510
int __cdecl FUN_00456510()
{
    return DAT_011f4500;
}

class AVObj
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void* IsGeometry();
    void IncRefCount();
    void DecRefCount();
};

class NodeObj : public AVObj
{
  public:
    unsigned int GetChildCount();
};

struct GeomCounter
{
    int CountGeometry(NodeObj* apNode, bool abAll);
};

// Recursively counts geometry in a node's children, summing FUN_004567b0 for geometry objects unless abAll is false and FUN_00456610 is true.
// @fnv 0x00456670
int GeomCounter::CountGeometry(NodeObj* apNode, bool abAll)
{
    int iCount = 0;
    if (!apNode)
        return iCount;
    for (unsigned int i = 0; i < apNode->GetChildCount(); i++)
    {
        NiPointer<AVObj> spChild(((::AVObj *)(reinterpret_cast<::NiNode *>((apNode))->GetAt(i))));
        if (spChild)
        {
            if (spChild->IsSceneNode())
            {
                iCount += CountGeometry((NodeObj*)(AVObj*)spChild, abAll);
            }
            else if (spChild->IsGeometry())
            {
                AVObj* pGeom = spChild;
                if (abAll || !reinterpret_cast<::FUN_00456630_helper *>((pGeom))->FUN_00456610())
                {
                    iCount += reinterpret_cast<::FUN_004567b0_Owner *>((pGeom))->FUN_004567b0();
                }
            }
        }
    }
    return iCount;
}

class B456AA0Setting
{
  public:
    unsigned char* Bool();
};


class B456AA0Cell
{
  public:
};

class B456AA0Sky
{
  public:
};

class B456AA0TES
{
  public:
    void FUN_00456aa0();

    int unk00;
    int unk04;
    B456AA0Sky* m_pkSky;
};

// @fnv 0x00456aa0
void B456AA0TES::FUN_00456aa0()
{
    B456AA0Cell* pkCell = ((::B456AA0Cell *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    bool bToggled = (*(*reinterpret_cast<::B456AA0Setting *>(&::g_011ca2dc)).Bool() = !*(*reinterpret_cast<::B456AA0Setting *>(&::g_011ca2dc)).Bool());
    if (pkCell)
        reinterpret_cast<::FUN_005549d0_shell *>((pkCell))->FUN_005549d0(bToggled);
    else
        reinterpret_cast<::FUN_004bae20_shell *>((m_pkSky))->FUN_004bae20(bToggled);
}

class BGSTerrainManager;
class TESWorldSpace
{
  public:
public:
    ::BGSTerrainManager *GetWorldTerrainManager();
};
class bhkWorld
{
  public:
};
int __cdecl FUN_00406d50(char* dst, unsigned int size, const char* src);
struct Stand_456b10
{
    void FUN_00456b10(const char* name);
};
// @fnv 0x00456b10
void Stand_456b10::FUN_00456b10(const char* name)
{
    if (name)
    {
        char hkxPath[260];
        bhkWorld* hkWorld = 0;
        TESObjectCELL* interiorCell = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((TESWorldSpace*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetPrevPath()));
        if (interiorCell != 0)
        {
            hkWorld = ((::bhkWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((interiorCell))->FUN_004543c0()));
        }
        else
        {
            hkWorld = (bhkWorld*)FUN_00451010();
        }
        if (hkWorld)
        {
            ::TaskQueueInterface::CopyStringToBuffer(hkxPath, 260, name);
            FUN_00406d50(hkxPath, 260, ".hkx");
            reinterpret_cast<::Owner67430 *>((hkWorld))->FUN_00c67430((int)(hkxPath));
        }
    }
}

class NiGeometryData
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiGeometry;
class NiNodeS;
struct NiAVObjectV
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual NiNodeS* IsNiNode();
    virtual void vf10();
    virtual void vf14();
    virtual NiGeometry* IsGeometry();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void ReplaceModelData(NiGeometryData* apData);
};
class NiGeometry : public NiAVObjectV
{
  public:
};
class NiNodeS : public NiAVObjectV
{
  public:
    unsigned int GetArrayCount();
    NiAVObject* GetAt(unsigned int auiIndex);
};

// @fnv 0x00457a00
void __cdecl FUN_00457a00(NiAVObject* apObject)
{
    NiPointer<NiGeometryData> spCopy2(0);
    NiGeometry* pGeom = 0;
    if (apObject)
    {
        pGeom = ((NiAVObjectV*)apObject)->IsGeometry();
        if (pGeom)
        {
            NiPointer<NiGeometryData> spScreenData(((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(pGeom)))));
            if (spScreenData)
            {
                if (!reinterpret_cast<::FUN_00457b80_class *>(((spScreenData).operator->()))->FUN_00457b80() && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((spScreenData).operator->()))->FUN_007af430())))
                {
                    reinterpret_cast<::NiObjectD510 *>(((spScreenData).operator->()))->FUN_00a5d510((*(::NiPointerD510 *)(&spCopy2)));
                    spScreenData = (NiGeometryData*)spCopy2;
                    pGeom->ReplaceModelData(spScreenData);
                }
                else
                {
                    pGeom->ReplaceModelData(spScreenData);
                }
            }
        }
        else
        {
            NiNodeS* pNode = ((NiAVObjectV*)apObject)->IsNiNode();
            if (pNode)
            {
                unsigned int i2 = pNode->GetArrayCount();
                while (i2--)
                    FUN_00457a00(reinterpret_cast<::NiNode *>((pNode))->GetAt(i2));
            }
        }
    }
}

// @fnv 0x00458b20
void* __cdecl FUN_00458b20()
{
    return &(*reinterpret_cast<int *>(&::DAT_01267e30));
}

struct TESForm;

struct SaveBuffer
{
};

struct ListEntry
{
    TESForm* form;
    short value;
};

struct EntryListNode
{
    ListEntry* item;
    EntryListNode* next;
};

struct CellRef
{
};

struct CellSlot
{
    CellRef* ref;
};

struct CellGrid
{
    CellSlot* Get(unsigned int x, unsigned int y);
};

struct DataHandlerStub
{
};

struct GameSettingStub
{
};

struct TESGridOwner
{
    int unk00;
    int unk04;
    CellGrid* grid;
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
    EntryListNode entries;
    void SaveGridState(SaveBuffer* buffer);
};

// Writes each entry's form ref and value to the buffer, patches the entry count, then saves the grid size and the ref ID of every cell in the grid.
// @fnv 0x00459490
void TESGridOwner::SaveGridState(SaveBuffer* buffer)
{
    int count = 0;
    unsigned int offset = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    EntryListNode* node6 = &entries;
    while (node6)
    {
        ListEntry* entry4 = *((::ListEntry **)(new ((void *)(node6)) ::Vec3()));
        if (entry4)
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(entry4->form), 0);
            reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&entry4->value, 2, 0);
            count++;
        }
        node6 = ((::EntryListNode *)(reinterpret_cast<::Callees *>((node6))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count, offset);
    unsigned int gridSizeB = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GameSettingStub *>(&::g_011c63cc))))));
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&gridSizeB, 4, 0);
    for (unsigned int xTmp = 0; xTmp < gridSizeB; xTmp++)
    {
        for (unsigned int y_ = 0; y_ < gridSizeB; y_++)
        {
            CellRef* cell = grid->Get(xTmp, y_)->ref;
            unsigned int refID8 = (cell && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0())))) ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0())) : 0;
            reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(refID8, 0);
        }
    }
}

extern int DAT_01018508;

struct S_0044f600
{
    void* m_vtbl;
};

struct S_0045d220 : public S_0044f600
{
    void* FUN_0045d220();
};

// @fnv 0x0045d220
void* S_0045d220::FUN_0045d220()
{
    reinterpret_cast<::FUN_0044f600_class *>((this))->InitializeVtbl();
    this->m_vtbl = &DAT_01018508;
    return this;
}

struct TSMapNode
{
    int iKey;
    QHeadPtrDest kValue;
    TSMapNode* pNext;

    TSMapNode(int aiValue);
    ~TSMapNode();
};

struct TSMapTaggedPtr
{
    TSMapNode* pNode;

    TSMapTaggedPtr(bool abTag, TSMapNode* apNode);
};

struct TSMapList
{
    TSMapNode* pHead;

    TSMapNode* GetHead();
};

struct TSMapFactory
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
    virtual int CreateValue(int aiKey, const QHeadPtr& arValue);
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void Notify();
};


struct TSMap
{
    TSMapFactory* pFactory;
    int unk04;
    int unk08;
    int unk0C;
    int aiNumVertices;
    TSMapList kList;

    bool InsertOrReplace(int aiKey, int aiHash, const QHeadPtr& arValue, bool abReplace);
};

// Inserts a new node for aiHash unless Find succeeds, replacing the head value when abReplace, then unlocks and returns whether it succeeded.
// @fnv 0x0044d070
bool TSMap::InsertOrReplace(int aiKey, int aiHash, const QHeadPtr& arValue, bool abReplace)
{
    AutoMemContext kMemContext((MEM_CONTEXT)6, true,
                               "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.inl", 0x187);
    bool bResult = true;
    TSMapNode* pNewNode2 = 0;

    while (true)
    {
        if (reinterpret_cast<::SearchWorker *>(this)->ProcessNode(aiKey, aiHash))
        {
            delete pNewNode2;
            if (abReplace)
                reinterpret_cast<::NP_0092c820 *>(&(kList.GetHead()->kValue))->FUN_0092c820((const ::NP_0092c820 &)(arValue));
            else
                bResult = false;
            break;
        }

        if (!pNewNode2)
            pNewNode2 = new TSMapNode(pFactory->CreateValue(aiHash, arValue));

        TSMapTaggedPtr kOldTop(false, kList.GetHead());
        TSMapTaggedPtr kNewTop(false, pNewNode2);
        pNewNode2->pNext = kOldTop.pNode;
        if (::FUN_004491c0((volatile long *)(aiNumVertices), (long)(((::TSMapNode **)(::FUN_00559450((int *)&(kNewTop))))), (long)(((::TSMapNode **)(::FUN_00559450((int *)&(kOldTop)))))))
        {
            pFactory->Notify();
            break;
        }
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return bResult;
}

struct Bucket44D
{
    int m_iKey;
    int m_iValue;
};

class MapBase44D
{
  public:
    virtual ~MapBase44D();

    int unk04;
    int unk08;
    int unk0C;
};

class FUN_0044d840 : public MapBase44D
{
  public:
    virtual ~FUN_0044d840();

    void Clear(bool bFree);

    Bucket44D* m_pkBuckets;
};
// Calls FUN_0044d840, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x0044d810
void* FUN_0044d810_class::FUN_0044d810(unsigned int flags)
{
    reinterpret_cast<::FUN_0044d840 *>(this)->FUN_0044d840::~FUN_0044d840();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0044d8f0 {
struct Bucket44D
{
    int m_iKey;
    int m_iValue;
};

class MapBase44D
{
  public:
    virtual ~MapBase44D();
};

class FUN_0044d8f0 : public MapBase44D
{
  public:
    virtual ~FUN_0044d8f0();
    void Clear(bool bFree);

    Bucket44D* m_pkEntryArray;
    int unk08;
    Bucket44D* m_pkBuckets;
};

// @fnv 0x0044d8f0
FUN_0044d8f0::~FUN_0044d8f0()
{
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(true);
    delete m_pkBuckets;
    delete m_pkEntryArray;
}
}  // namespace fnv_0044d8f0


struct Ptr_44e550
{
    void* m_p;
    operator void*() const;
};

struct QHeadPtr_44e550
{
    int unk00;
};
struct QHeadPtrDest_44e550
{
};

struct Entry_44e550
{
    int key;
    QHeadPtr_44e550 head;
    bool Call();
};

struct List_44e550
{
    void* m_pHead;
    Entry_44e550* FUN_0044df00();
};
int ClearLowBit(List_44e550*);

struct Obj_44e550
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
    virtual void v30(int key, int b);
};

struct Owner_44e550
{
    Obj_44e550* m_pEntryObject;
    int unk04;
    int* unk08;
    int unk0C;
    Ptr_44e550* unk10;
    List_44e550 m_list14;
    bool FUN_0044e550(int a1, int a2, QHeadPtrDest_44e550* a3);
};

// @fnv 0x0044e550
bool Owner_44e550::FUN_0044e550(int a1, int a2, QHeadPtrDest_44e550* apDest)
{
    bool result = false;
    FUN_0040fbe0();
    Ptr_44e550 cur;
    reinterpret_cast<::FUN_006ecba0_class *>(&(cur))->FUN_006ecba0(false, 0);
    while (1)
    {
        unk10 = ((::Ptr_44e550 *)(reinterpret_cast<::FUN_0044ee20_class *>((m_pEntryObject))->GetElementAddress(a1)));
        m_list14 = *(List_44e550*)unk10;
        *unk08 = ClearLowBit(&m_list14);
        reinterpret_cast<::FUN_00537e90 *>(&(cur))->SetQuantity(ClearLowBit(&m_list14));
        reinterpret_cast<::FUN_0044e010_class *>(&(cur))->FUN_0044e010(false);
        if ((void*)*unk10 != (void*)cur)
            continue;
        if (ClearLowBit(&m_list14) == 0)
        {
            result = false;
            break;
        }
        m_pEntryObject->v30(m_list14.FUN_0044df00()->key, a2);
        reinterpret_cast<::NP_0092c820 *>((apDest))->FUN_0092c820((const ::NP_0092c820 &)(m_list14.FUN_0044df00()->head));
        result = true;
        if (m_list14.FUN_0044df00()->Call())
            continue;
        break;
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return result;
}

int ClearLowBit(int*);
struct Node_44e680
{
    int item;
    int value;
    bool Call();
};
struct List_44e680
{
    void* m_pHead;
    int* FUN_0044df00();
};
struct Obj_44e680
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
    virtual void v30(int a, int* b);
};
struct Ptr_44e680
{
};
struct Queue_44e680
{
    Obj_44e680* m_pEntryObject;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    List_44e680 m_list14;
    List_44e680 m_list18;
    bool FindEntry(int a, int* pKey, Ptr_44e680* pOut);
};

// @fnv 0x0044e680
bool Queue_44e680::FindEntry(int a, int* pKey, Ptr_44e680* pOut)
{
    bool bResult = false;
    FUN_0040fbe0();
    while (1)
    {
        bResult = reinterpret_cast<::SearchWorker *>(this)->ProcessNode(a, *pKey);
        if (bResult)
        {
            if (ClearLowBit((int*)&m_list18))
            {
                if (((Node_44e680*)m_list18.FUN_0044df00())->Call())
                    continue;
                m_pEntryObject->v30(*m_list18.FUN_0044df00(), pKey);
                reinterpret_cast<::NP_0092c820 *>((pOut))->FUN_0092c820((*(const ::NP_0092c820 *)(m_list18.FUN_0044df00() + 1)));
                bResult = true;
                if (((Node_44e680*)m_list18.FUN_0044df00())->Call())
                {
                    reinterpret_cast<::FUN_006f74f0_cls *>((pOut))->FUN_006f74f0((::ObjA *)(0));
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
        else
        {
            if (ClearLowBit((int*)&m_list14))
            {
                if (((Node_44e680*)m_list14.FUN_0044df00())->Call())
                    continue;
                m_pEntryObject->v30(*m_list14.FUN_0044df00(), pKey);
                reinterpret_cast<::NP_0092c820 *>((pOut))->FUN_0092c820((*(const ::NP_0092c820 *)(m_list14.FUN_0044df00() + 1)));
                bResult = true;
                if (((Node_44e680*)m_list14.FUN_0044df00())->Call())
                {
                    reinterpret_cast<::FUN_006f74f0_cls *>((pOut))->FUN_006f74f0((::ObjA *)(0));
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return bResult;
}

struct ShutdownList
{
    void* head;
    ShutdownList* next;
    ~ShutdownList();
};
struct ShutdownPointer
{
    void* object;
    ~ShutdownPointer();
    ShutdownPointer& FUN_0066b0d0(void*);
};
struct ShutdownQueuePointer
{
    void* object;
    ~ShutdownQueuePointer();
};
struct GlobalObject_004ee810
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    ~GlobalObject_004ee810();
};
struct ShutdownModelLoader
{
    ~ShutdownModelLoader();
};
struct ShutdownIOManager
{
    virtual ~ShutdownIOManager();
};
struct ShutdownTaskQueue
{
    ~ShutdownTaskQueue();
};
struct ShutdownGrid
{
    virtual ~ShutdownGrid();
};
struct ShutdownSaveGame
{
    ~ShutdownSaveGame();
};
struct ShutdownDataHandler
{
    ~ShutdownDataHandler();
};
struct ShutdownCalendar
{
};
struct ShutdownProcess
{
};
struct ShutdownVATS
{
};
struct ShutdownPlayer
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void Reset(int, int);
};
struct ShutdownScene
{
};
void __cdecl FUN_00527f40();
void __cdecl ClearGlobalArray();
void __cdecl FUN_00847500();
void __cdecl FUN_00625fb0();
struct ShutdownWorld
{
};
struct FUN_00450770
{
    virtual ~FUN_00450770();
    int field04;
    ShutdownGrid* grid;
    int field0c, field10, field14, field18;
    void* field1c;
    void* field20;
    int field24, field28, field2c, field30, field34;
    void* field38;
    void* field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c, field60, field64;
    void* field68;
    GlobalObject_004ee810 collection;
    ShutdownList list8c, list94, list9c;
    ShutdownQueuePointer queueA4;
    ShutdownPointer pointerA8;
    ShutdownQueuePointer queueAC;
    int fieldb0, fieldb4, fieldb8, fieldbc;
    ShutdownPointer pointerC0;
};
struct Target_00458440;

struct GridCell
{
    Target_00458440* unk00;
};

struct GlobalObject2_0045cfe0
{
};

struct Target_00458440
{
};

struct Obj_00458440
{
    int unk00;
    int unk04;
    GridCellArray* m_08;
    void Notify(int a);
    int ApplyOrNotify(intptr_t a, bool b);
};
// @fnv 0x00458420
void FUN_00458420_cls::FUN_00458420(int aiValue)
{
    reinterpret_cast<::Obj_00458440 *>(this)->ApplyOrNotify(aiValue, 1);
}

struct Vec08
{
    float x, y, z;
    Vec08();
    Vec08 operator-(const Vec08&) const;
};
struct Proxy08
{
};
struct NavMeshPtr
{
    void* FUN_00458b50();
};
struct Results08
{
};
struct GlobalObject_00e98f20
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
    GlobalObject_00e98f20(int, int);
    ~GlobalObject_00e98f20();
};
struct Source08
{
    void* FUN_004584d0(Proxy08*);
};
// If b is set, finds a Target_00458440 (falling back to a grid cell) and applies a to it, returning the result or 0; otherwise calls Notify(a).
// @fnv 0x00458440
int Obj_00458440::ApplyOrNotify(intptr_t a, bool abApply)
{
    if (abApply)
    {
        Target_00458440* p = ((::Target_00458440 *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
        if (p == 0)
        {
            p = this->m_08->Get((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0045cfe0 *>(&::g_011c63cc)))))) >> 1, (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0045cfe0 *>(&::g_011c63cc)))))) >> 1)->unk00;
        }
        return p ? ((int)(reinterpret_cast<::FUN_00553ee0_shell *>((p))->FUN_00553ee0((::TESObjectREFR *)(a)))) : 0;
    }
    else
    {
        reinterpret_cast<::Source08 *>(this)->FUN_004584d0((::Proxy08 *)(a));
    }
}
// @fnv 0x004584d0
void* Source08::FUN_004584d0(Proxy08* proxy)
{
    Vec08 start;
    Vec08 delta;
    Vec08 pick;
    reinterpret_cast<::Proxy *>((proxy))->FUN_004585f0((::NiPoint3 &)(delta));
    reinterpret_cast<::FUN_004587f0_shell *>((proxy))->FUN_004587f0((::NiPoint3 &)(pick));
    start = pick - delta;
    GlobalObject_00e98f20 finish(0, 8);
    reinterpret_cast<::NiPick *>(&(finish))->FUN_00705fc0(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
    reinterpret_cast<::FUN_00458b30_class *>(&(finish))->SetByteAtOffset17(1);
    void* result = 0;
    if (reinterpret_cast<::NiPick *>(&(finish))->PerformPick((const ::NiPoint3 &)(delta), (const ::NiPoint3 &)(start), 0))
    {
        Results08* entry = ((::Results08 *)(reinterpret_cast<::BGSCameraPath *>(&(finish))->GetConditions()));
        NavMeshPtr* results = ((::NavMeshPtr *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((entry))->FUN_00968670(0)));
        result = results->FUN_00458b50();
    }
    return result;
}

namespace SceneUpdate {
struct World;
struct Array;
struct Entity;
struct Actor;
struct Region;
struct Cell;
struct Query;
struct Vec3
{
    float x, y;

  private:
    float z;

  public:
    Vec3 ApplyScaled(float) const;
};
struct Bound
{
    float x, y, z, w, radius;
};
struct View
{
    const Vec3& FUN_0045bb80();
    Vec3 FUN_0045bba0();
};
struct Marker
{
};
struct Setting
{
};
struct Query
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
    Query(int);
    ~Query();
};
struct Entity
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Array* Children();
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
    virtual int IsExcluded();
    virtual bool Contains(const Vec3&);
    virtual void v67();
};
struct Array
{
    unsigned int FUN_0043b480();
};
struct Cell
{
};
struct Grid
{
    Cell** FUN_004ba490(unsigned int, unsigned int);
};
struct List
{
};
struct Region
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
    List actors;
};
struct Actor
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
    virtual Array* Nodes();
};
struct Area
{
    Region* FUN_006733e0();
};
struct ViewUpdater
{
};
struct AreaOwner
{
};
struct Handle
{
    Entity* pointer;
    Handle(Entity*);
    ~Handle();
    void FUN_0066b0d0(Entity*);
};
struct EntityList
{
};
struct State
{
};
struct Renderer
{
    void ProcessTargetIfEligible(Entity*, Vec3, Query*);
};
struct World
{
    int unk00, unk04;
    Grid* grid;
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
    Cell* cell;
    void FUN_0045b070(View*);
};
// Builds a view query, renders entities from the current cell or grid cells, region actors and children, then updates the selected entity under the view point.
// @fnv 0x0045b070
void World::FUN_0045b070(View* view)
{
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::SceneUpdate::Marker *>(&::g_011c3c0f))))->ClearData();
    Query query(0);
    reinterpret_cast<::FUN_0041fd00_shell *>(&(query))->FUN_0041fd00((int)(view));
    reinterpret_cast<::S694a0 *>(&(query))->FUN_00a694a0(((::SceneUpdate::Bound *)&(reinterpret_cast<::NiCamera *>((view))->GetViewFrustum())));
    Vec3 origin4 = view->FUN_0045bb80();
    Renderer* renderer = ((::SceneUpdate::Renderer *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
    if (cell)
    {
        Array* nodes = ((::SceneUpdate::Array *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellChildAt(7)));
        if (nodes)
        {
            for (unsigned int i = 0; i < nodes->FUN_0043b480(); i++)
            {
                Entity* entry = ((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((nodes))->GetAt(i)));
                if (entry)
                {
                    Entity* object = entry;
                    if (!object->IsExcluded())
                        renderer->ProcessTargetIfEligible(object, origin4, &query);
                }
            }
        }
    }
    else
    {
        ViewUpdater* updater = ((::SceneUpdate::AreaOwner *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())) ? ((::SceneUpdate::ViewUpdater *)(reinterpret_cast<::TESWorldSpace *>((((::SceneUpdate::AreaOwner *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()))))->GetWorldTerrainManager())) : 0;
        if (updater)
            reinterpret_cast<::TerrainStream *>((updater))->PushRef((::TerrainRefProxy *)(view));
        for (unsigned int x = 0; x < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SceneUpdate::Setting *>(&::g_011c63cc)))))); x++)
        {
            for (unsigned int y = 0; y < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SceneUpdate::Setting *>(&::g_011c63cc)))))); y++)
            {
                Cell** slot = grid->FUN_004ba490(x, y);
                Cell* current3 = *slot;
                if (current3)
                {
                    Array* nodes2 = ((::SceneUpdate::Array *)(reinterpret_cast<::TESObjectCELL *>((current3))->GetCellChildAt(7)));
                    if (nodes2)
                    {
                        for (unsigned int j = 0; j < nodes2->FUN_0043b480(); j++)
                        {
                            Entity* entry2 = ((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((nodes2))->GetAt(j)));
                            if (entry2)
                            {
                                Entity* object2 = entry2;
                                renderer->ProcessTargetIfEligible(object2, origin4, &query);
                            }
                        }
                    }
                    nodes2 = ((::SceneUpdate::Array *)(reinterpret_cast<::TESObjectCELL *>((current3))->GetCellChildAt(2)));
                    for (unsigned int k = 0; k < nodes2->FUN_0043b480(); k++)
                    {
                        Entity* entry3 = ((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((nodes2))->GetAt(k)));
                        if (entry3)
                        {
                            Entity* object3 = entry3;
                            renderer->ProcessTargetIfEligible(object3, origin4, &query);
                        }
                    }
                }
            }
        }
    }
    Entity* rootX = ((::SceneUpdate::Entity *)(reinterpret_cast<::S_FUN_0045bc00 *>((renderer))->FUN_0045bc00(6)));
    Array* extra = rootX ? rootX->Children() : 0;
    if (extra)
    {
        for (unsigned int n = 0; n < extra->FUN_0043b480(); n++)
        {
            Entity* entry4 = ((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((extra))->GetAt(n)));
            if (entry4)
            {
                Entity* object4 = entry4;
                renderer->ProcessTargetIfEligible(object4, origin4, &query);
            }
        }
    }
    if (((::SceneUpdate::Area *)(::FUN_0070ec90((char *)this))))
    {
        Region* region = 0;
        void* position = ((void *)(::FUN_00559450((int *)(((::SceneUpdate::List *)(reinterpret_cast<struct ::FUN_005a8080 *>((((::SceneUpdate::Area *)(::FUN_0070ec90((char *)this)))))->GetField()))))));
        void* next9 = 0;
        while (position)
        {
            next9 = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((((::SceneUpdate::List *)(reinterpret_cast<struct ::FUN_005a8080 *>((((::SceneUpdate::Area *)(::FUN_0070ec90((char *)this)))))->GetField()))))->DereferenceIfNotNull((int **)(position))));
            if (position)
            {
                region = (Region*)*((void **)(reinterpret_cast<::FUN_006317a0_struct *>((((::SceneUpdate::List *)(reinterpret_cast<struct ::FUN_005a8080 *>((((::SceneUpdate::Area *)(::FUN_0070ec90((char *)this)))))->GetField()))))->AddEight((intptr_t)(position))));
                void* actorPos3 = ((void *)(::FUN_00559450((int *)&(region->actors))));
                void* actorNext = 0;
                while (actorPos3)
                {
                    actorNext = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(region->actors))->DereferenceIfNotNull((int **)(actorPos3))));
                    if (actorPos3)
                    {
                        Actor* actor = (Actor*)*((void **)(reinterpret_cast<::FUN_006317a0_struct *>(&(region->actors))->AddEight((intptr_t)(actorPos3))));
                        void* unused = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430()));
                        Array* actorNodes = actor->Nodes();
                        if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_01202e74))), (const ::fnv_0045bad0::NiObject *)(::SceneUpdate::Entity *)(((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((actorNodes))->GetAt(0))))))
                        {
                            Entity* object5 = ((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((actorNodes))->GetAt(0)));
                            renderer->ProcessTargetIfEligible(object5, origin4, &query);
                        }
                    }
                    actorPos3 = actorNext;
                }
            }
            position = next9;
        }
        region = ((::SceneUpdate::Area *)(::FUN_0070ec90((char *)this)))->FUN_006733e0();
        if (region)
        {
            void* pos2 = ((void *)(::FUN_00559450((int *)&(region->actors))));
            void* next2 = 0;
            while (pos2)
            {
                next2 = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(region->actors))->DereferenceIfNotNull((int **)(pos2))));
                if (pos2)
                {
                    Actor* actor2 = (Actor*)*((void **)(reinterpret_cast<::FUN_006317a0_struct *>(&(region->actors))->AddEight((intptr_t)(pos2))));
                    void* unused2 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor2))->FUN_007af430()));
                    Array* actorNodes3 = actor2->Nodes();
                    if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_01202e74))), (const ::fnv_0045bad0::NiObject *)(::SceneUpdate::Entity *)(((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((actorNodes3))->GetAt(0))))))
                    {
                        Entity* object6 = ((::SceneUpdate::Entity *)(reinterpret_cast<::NiNode *>((actorNodes3))->GetAt(0)));
                        renderer->ProcessTargetIfEligible(object6, origin4, &query);
                    }
                }
                pos2 = next2;
            }
        }
    }
    if (((::SceneUpdate::State *)(reinterpret_cast<::FUN_00454b30_class *>((((::SceneUpdate::Renderer *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00454b30())))
    {
        reinterpret_cast<::FUN_0045bc60_class *>((((::SceneUpdate::State *)(reinterpret_cast<::FUN_00454b30_class *>((((::SceneUpdate::Renderer *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00454b30()))))->FUN_0045bc60();
        Handle chosen(((::SceneUpdate::Entity *)(uintptr_t)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((::SceneUpdate::State *)(reinterpret_cast<::FUN_00454b30_class *>((((::SceneUpdate::Renderer *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00454b30()))))->FUN_0056c7f0())));
        View* active8 = 0;
        if (!active8)
            active8 = view;
        Vec3 point3 = (*(::SceneUpdate::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(view->FUN_0045bb80()))->ProjectileLaunched((::NiPoint3 *)&(const ::SceneUpdate::Vec3 &)(view->FUN_0045bba0().ApplyScaled(((::SceneUpdate::Bound *)&(reinterpret_cast<::NiCamera *>((view))->GetViewFrustum()))->radius)), {})));
        if (((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen)))))
        {
            if (!((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen))))->Contains(point3))
                chosen.FUN_0066b0d0(0);
            else
                reinterpret_cast<::Traversal *>((renderer))->UpdateVisibility((::Region *)(::SceneUpdate::Entity *)(((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen))))), (::View *)(uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(query))->FUN_0084e3a0()))), ((unsigned int)(reinterpret_cast<::TESRegion *>(&(query))->GetDiffuseColor())), {});
        }
        bool firstB = true;
        if (!((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen)))))
        {
            EntityList* list = ((::SceneUpdate::EntityList *)(reinterpret_cast<::BGSCameraPath *>((((::SceneUpdate::State *)(reinterpret_cast<::FUN_00454b30_class *>((renderer))->FUN_00454b30()))))->GetShotList()));
            if (!reinterpret_cast<::FUN_0076b610_Class *>((list))->FUN_0076b610())
            {
                void* p = ((void *)(::FUN_00559450((int *)(list))));
                while (p)
                {
                    Entity* entity = ((::SceneUpdate::Entity *)(::FUN_00559450((int *)(((::SceneUpdate::Handle *)(reinterpret_cast<::ListStandIn *>((list))->FUN_0057cbe0((int **)(void **)(&p))))))));
                    if (entity && entity->Contains(point3))
                    {
                        reinterpret_cast<::Traversal *>((renderer))->UpdateVisibility((::Region *)(entity), (::View *)(uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(query))->FUN_0084e3a0()))), ((unsigned int)(reinterpret_cast<::TESRegion *>(&(query))->GetDiffuseColor())), {});
                        if (!((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen)))))
                        {
                            chosen.FUN_0066b0d0(entity);
                            firstB = false;
                        }
                    }
                }
            }
        }
        if (!((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen)))))
            reinterpret_cast<::Traversal *>((renderer))->UpdateVisibility((::Region *)(::SceneUpdate::Entity *)(0), (::View *)(uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(query))->FUN_0084e3a0()))), ((unsigned int)(reinterpret_cast<::TESRegion *>(&(query))->GetDiffuseColor())), {});
        reinterpret_cast<::FUN_0045bc40_Class *>((((::SceneUpdate::State *)(reinterpret_cast<::FUN_00454b30_class *>((renderer))->FUN_00454b30()))))->FUN_0045bc40(((::SceneUpdate::Entity *)(::FUN_00559450((int *)&(chosen)))));
    }
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::SceneUpdate::Marker *>(&::g_011c3c0f))))->ClearData();
}
}

struct S_0045c520
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
    FUN_0045c5f0_class* unkCC;

    void FUN_0045c520();
};
// If fieldCC is set and differs from a, calls FUN_0045c520, then stores a into fieldCC.
// @fnv 0x0045c4e0
void FUN_0045c4e0_This::SetFieldCC(void* apValue)
{
    if (fieldCC != 0 && fieldCC != apValue)
        reinterpret_cast<::S_0045c520 *>(this)->FUN_0045c520();
    fieldCC = apValue;
}

// Calls FUN_0045c5f0(1) on unkCC if it is non-null, then sets unkCC to 0.
// @fnv 0x0045c520
void S_0045c520::FUN_0045c520()
{
    FUN_0045c5f0_class* a = unkCC;
    FUN_0045c5f0_class* p = a;
    p ? p->FUN_0045c5f0(1) : 0;
    unkCC = 0;
}

struct GlobalObject_0096a2d0
{
    int unk00;
    int unk04;
    GlobalObject_0096a2d0();
    ~GlobalObject_0096a2d0();
};
struct FUN_00470040_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00470040_class(int, int);
    ~FUN_00470040_class();
};
struct FUN_004700a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_004700a0(int, int);
    ~FUN_004700a0();
};
struct GlobalObject_0048f200
{
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
};
struct FUN_005100d0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_005100d0(int);
};
struct TESRegionList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TESRegionList(int);
};
struct FUN_004f3660
{
    int unk00;
    int unk04;
    FUN_004f3660();
};
struct FUN_005ffaf0
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
    FUN_005ffaf0();
};
struct FUN_0058b770
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
    FUN_0058b770();
};
struct GlobalObject_0048f200_d0054da00 : GlobalObject_0048f200
{
    ~GlobalObject_0048f200_d0054da00();
};
struct FUN_0045d270
{
    unsigned char unk00;
    FUN_005100d0* unk04;
    GlobalObject_0096a2d0 unk008;
    GlobalObject_0096a2d0 unk010;
    GlobalObject_0096a2d0 unk018;
    GlobalObject_0096a2d0 unk020;
    GlobalObject_0096a2d0 unk028;
    GlobalObject_0096a2d0 unk030;
    GlobalObject_0096a2d0 unk038;
    GlobalObject_0096a2d0 unk040;
    GlobalObject_0096a2d0 unk048;
    GlobalObject_0096a2d0 unk050;
    GlobalObject_0096a2d0 unk058;
    GlobalObject_0096a2d0 unk060;
    GlobalObject_0096a2d0 unk068;
    GlobalObject_0096a2d0 unk070;
    GlobalObject_0096a2d0 unk078;
    GlobalObject_0096a2d0 unk080;
    GlobalObject_0096a2d0 unk088;
    GlobalObject_0096a2d0 unk090;
    GlobalObject_0096a2d0 unk098;
    GlobalObject_0096a2d0 unk0a0;
    GlobalObject_0096a2d0 unk0a8;
    GlobalObject_0096a2d0 unk0b0;
    GlobalObject_0096a2d0 unk0b8;
    GlobalObject_0096a2d0 unk0c0;
    GlobalObject_0096a2d0 unk0c8;
    GlobalObject_0096a2d0 unk0d0;
    GlobalObject_0096a2d0 unk0d8;
    GlobalObject_0096a2d0 unk0e0;
    GlobalObject_0096a2d0 unk0e8;
    GlobalObject_0096a2d0 unk0f0;
    GlobalObject_0096a2d0 unk0f8;
    GlobalObject_0096a2d0 unk100;
    GlobalObject_0096a2d0 unk108;
    GlobalObject_0096a2d0 unk110;
    GlobalObject_0096a2d0 unk118;
    GlobalObject_0096a2d0 unk120;
    GlobalObject_0096a2d0 unk128;
    GlobalObject_0096a2d0 unk130;
    GlobalObject_0096a2d0 unk138;
    GlobalObject_0096a2d0 unk140;
    GlobalObject_0096a2d0 unk148;
    GlobalObject_0096a2d0 unk150;
    GlobalObject_0096a2d0 unk158;
    GlobalObject_0096a2d0 unk160;
    GlobalObject_0096a2d0 unk168;
    GlobalObject_0096a2d0 unk170;
    GlobalObject_0096a2d0 unk178;
    GlobalObject_0096a2d0 unk180;
    GlobalObject_0096a2d0 unk188;
    GlobalObject_0096a2d0 unk190;
    GlobalObject_0096a2d0 unk198;
    GlobalObject_0096a2d0 unk1a0;
    GlobalObject_0096a2d0 unk1a8;
    GlobalObject_0096a2d0 unk1b0;
    GlobalObject_0096a2d0 unk1b8;
    GlobalObject_0096a2d0 unk1c0;
    GlobalObject_0096a2d0 unk1c8;
    GlobalObject_0096a2d0 unk1d0;
    TESRegionList* unk1d8;
    FUN_00470040_class unk1dc;
    FUN_004700a0 unk1ec;
    GlobalObject_0048f200_d0054da00 unk1fc;
    int unk208;
    int unk20c;
    GlobalObject_0096a2d0 unk210;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    unsigned char unk618;
    unsigned char unk619;
    unsigned char unk61a;
    unsigned char unk61b;
    unsigned char unk61c;
    unsigned char unk61d;
    unsigned char unk61e;
    unsigned char unk61f;
    unsigned char unk620;
    unsigned char unk621;
    unsigned char unk622;
    unsigned char unk623;
    FUN_004f3660* unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    FUN_0045d270();
};
// @fnv 0x0045d270
FUN_0045d270::FUN_0045d270() : unk1dc(0, 1), unk1ec(0, 1)
{
    unk208 = 0x800;
    unk218 = 0;
    unk20c = 0;
    unk618 = 0;
    unk619 = 0;
    unk61a = 0;
    unk61b = 0;
    unk61c = 0;
    unk61d = 0;
    unk61e = 1;
    unk621 = 0;
    unk00 = 0;
    unk622 = 0;
    FUN_00403d30(&unk21c, 0, 0x3fc);
    unk04 = new FUN_005100d0(1);
    unk1d8 = new TESRegionList(1);
    unk628 = 0;
    unk62c = 0;
    reinterpret_cast<::fnv_00559490::S *>(&(unk1dc))->FUN_00559490(100);
    unk624 = new FUN_004f3660;
    (*reinterpret_cast<::FUN_005ffaf0 * *>(&::DAT_011cb6a0)) = new FUN_005ffaf0;
    (*reinterpret_cast<::FUN_0058b770 * *>(&::DAT_011ca700)) = new FUN_0058b770;
    unk61f = 0;
    unk638 = 0;
    unk630 = 0;
    unk634 = 0;
}

namespace fnv_0045d970 {
struct IntList
{
    int value;
    IntList* next;
    ~IntList();
};
struct FUN_0045d930
{
    int m0, m4, m8, mc;
    ~FUN_0045d930();
};
struct FUN_0045d950
{
    int m0, m4, m8, mc;
    ~FUN_0045d950();
};
struct FUN_0054da00
{
    int m0, m4, m8, mc, m10;
    ~FUN_0054da00();
};
struct FUN_00431920
{
    ~FUN_00431920();
};
struct FUN_0045df10
{
    ~FUN_0045df10();
};
struct VirtualOwned
{
    virtual ~VirtualOwned();
};
struct FUN_0045df40
{
    ~FUN_0045df40();
};
struct FUN_0045df70
{
    ~FUN_0045df70();
};
struct CleanupMap
{
};
struct FUN_0045d970
{
    int m00;
    FUN_0045df10* m04;
    IntList list8;
    IntList list10;
    IntList list18;
    IntList list20;
    IntList list28;
    IntList list30;
    IntList list38;
    IntList list40;
    IntList list48;
    IntList list50;
    IntList list58;
    IntList list60;
    IntList list68;
    IntList list70;
    IntList list78;
    IntList list80;
    IntList list88;
    IntList list90;
    IntList list98;
    IntList lista0;
    IntList lista8;
    IntList listb0;
    IntList listb8;
    IntList listc0;
    IntList listc8;
    IntList listd0;
    IntList listd8;
    IntList liste0;
    IntList liste8;
    IntList listf0;
    IntList listf8;
    IntList list100;
    IntList list108;
    IntList list110;
    IntList list118;
    IntList list120;
    IntList list128;
    IntList list130;
    IntList list138;
    IntList list140;
    IntList list148;
    IntList list150;
    IntList list158;
    IntList list160;
    IntList list168;
    IntList list170;
    IntList list178;
    IntList list180;
    IntList list188;
    IntList list190;
    IntList list198;
    IntList list1a0;
    IntList list1a8;
    IntList list1b0;
    IntList list1b8;
    IntList list1c0;
    IntList list1c8;
    IntList list1d0;
    VirtualOwned* m1d8;
    FUN_0045d930 m1dc;
    FUN_0045d950 m1ec;
    FUN_0054da00 m1fc;
    IntList list210;
    int m218;
    int m21c;
    int m220;
    int m224;
    int m228;
    int m22c;
    int m230;
    int m234;
    int m238;
    int m23c;
    int m240;
    int m244;
    int m248;
    int m24c;
    int m250;
    int m254;
    int m258;
    int m25c;
    int m260;
    int m264;
    int m268;
    int m26c;
    int m270;
    int m274;
    int m278;
    int m27c;
    int m280;
    int m284;
    int m288;
    int m28c;
    int m290;
    int m294;
    int m298;
    int m29c;
    int m2a0;
    int m2a4;
    int m2a8;
    int m2ac;
    int m2b0;
    int m2b4;
    int m2b8;
    int m2bc;
    int m2c0;
    int m2c4;
    int m2c8;
    int m2cc;
    int m2d0;
    int m2d4;
    int m2d8;
    int m2dc;
    int m2e0;
    int m2e4;
    int m2e8;
    int m2ec;
    int m2f0;
    int m2f4;
    int m2f8;
    int m2fc;
    int m300;
    int m304;
    int m308;
    int m30c;
    int m310;
    int m314;
    int m318;
    int m31c;
    int m320;
    int m324;
    int m328;
    int m32c;
    int m330;
    int m334;
    int m338;
    int m33c;
    int m340;
    int m344;
    int m348;
    int m34c;
    int m350;
    int m354;
    int m358;
    int m35c;
    int m360;
    int m364;
    int m368;
    int m36c;
    int m370;
    int m374;
    int m378;
    int m37c;
    int m380;
    int m384;
    int m388;
    int m38c;
    int m390;
    int m394;
    int m398;
    int m39c;
    int m3a0;
    int m3a4;
    int m3a8;
    int m3ac;
    int m3b0;
    int m3b4;
    int m3b8;
    int m3bc;
    int m3c0;
    int m3c4;
    int m3c8;
    int m3cc;
    int m3d0;
    int m3d4;
    int m3d8;
    int m3dc;
    int m3e0;
    int m3e4;
    int m3e8;
    int m3ec;
    int m3f0;
    int m3f4;
    int m3f8;
    int m3fc;
    int m400;
    int m404;
    int m408;
    int m40c;
    int m410;
    int m414;
    int m418;
    int m41c;
    int m420;
    int m424;
    int m428;
    int m42c;
    int m430;
    int m434;
    int m438;
    int m43c;
    int m440;
    int m444;
    int m448;
    int m44c;
    int m450;
    int m454;
    int m458;
    int m45c;
    int m460;
    int m464;
    int m468;
    int m46c;
    int m470;
    int m474;
    int m478;
    int m47c;
    int m480;
    int m484;
    int m488;
    int m48c;
    int m490;
    int m494;
    int m498;
    int m49c;
    int m4a0;
    int m4a4;
    int m4a8;
    int m4ac;
    int m4b0;
    int m4b4;
    int m4b8;
    int m4bc;
    int m4c0;
    int m4c4;
    int m4c8;
    int m4cc;
    int m4d0;
    int m4d4;
    int m4d8;
    int m4dc;
    int m4e0;
    int m4e4;
    int m4e8;
    int m4ec;
    int m4f0;
    int m4f4;
    int m4f8;
    int m4fc;
    int m500;
    int m504;
    int m508;
    int m50c;
    int m510;
    int m514;
    int m518;
    int m51c;
    int m520;
    int m524;
    int m528;
    int m52c;
    int m530;
    int m534;
    int m538;
    int m53c;
    int m540;
    int m544;
    int m548;
    int m54c;
    int m550;
    int m554;
    int m558;
    int m55c;
    int m560;
    int m564;
    int m568;
    int m56c;
    int m570;
    int m574;
    int m578;
    int m57c;
    int m580;
    int m584;
    int m588;
    int m58c;
    int m590;
    int m594;
    int m598;
    int m59c;
    int m5a0;
    int m5a4;
    int m5a8;
    int m5ac;
    int m5b0;
    int m5b4;
    int m5b8;
    int m5bc;
    int m5c0;
    int m5c4;
    int m5c8;
    int m5cc;
    int m5d0;
    int m5d4;
    int m5d8;
    int m5dc;
    int m5e0;
    int m5e4;
    int m5e8;
    int m5ec;
    int m5f0;
    int m5f4;
    int m5f8;
    int m5fc;
    int m600;
    int m604;
    int m608;
    int m60c;
    int m610;
    int m614;
    int m618;
    int m61c;
    int m620;
    void* m624;
    FUN_00431920* m628;
    ~FUN_0045d970();
};
// Destructor that deletes m628, m04, m1d8 and m624, clears DAT_011cb6a0 and DAT_011ca700, and calls FUN_00438af0 on DAT_011c54c0 if set.
// @fnv 0x0045d970
FUN_0045d970::~FUN_0045d970()
{
    delete m628;
    reinterpret_cast<::FUN_0045dfa0_shell *>(this)->FUN_0045dfa0();
    delete m04;
    delete m1d8;
    delete m624;
    delete (*reinterpret_cast<::fnv_0045d970::FUN_0045df40 * *>(&::DAT_011cb6a0));
    (*reinterpret_cast<::fnv_0045d970::FUN_0045df40 * *>(&::DAT_011cb6a0)) = 0;
    delete (*reinterpret_cast<::fnv_0045d970::FUN_0045df70 * *>(&::DAT_011ca700));
    (*reinterpret_cast<::fnv_0045d970::FUN_0045df70 * *>(&::DAT_011ca700)) = 0;
    if ((*reinterpret_cast<::fnv_0045d970::CleanupMap * *>(&::fnv_00483370::DAT_011c54c0)))
        reinterpret_cast<::FUN_00438af0_Class *>(((*reinterpret_cast<::fnv_0045d970::CleanupMap * *>(&::fnv_00483370::DAT_011c54c0))))->FUN_00438af0();
}
}  // namespace fnv_0045d970

struct Allocator125
{
    Allocator125();
    Allocator125(const Allocator125&);
};
struct StringBase125
{
    Allocator125 alloc;
    StringBase125(Allocator125);
};
struct FUN_0044a4c0 : StringBase125
{
    union Buffer
    {
        char small[16];
        char* pointer;
    } buffer;
    unsigned int length, capacity;
    FUN_0044a4c0(const char* text);
};
// Initializes the string buffer to empty, then assigns the given text to it.
// @fnv 0x0044a4c0
FUN_0044a4c0::FUN_0044a4c0(const char* text) : StringBase125(Allocator125())
{
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
    reinterpret_cast<::fnv_0044a640::FUN_0044a640_Wrap *>(this)->AssignCString(text);
}

class GlobalObject_00528cb0
{
  public:
    ~GlobalObject_00528cb0();
    void* m_pObject;
};

class FUN_0044e370 : public GlobalObject_00528cb0
{
  public:
    FUN_0044e370(const FUN_0044e370& sp);
};

struct Lock44b
{
};

class List44b
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual bool Visit(unsigned int uiIndex, FUN_0044e370 pSceneObject);

    bool FUN_0044bdb0(FUN_0044e370 pSceneObject);

    int m_04;
    unsigned int m_uiCount;
    char pad0c[0x14];
    Lock44b m_kLock;
};

// @fnv 0x0044bdb0
bool List44b::FUN_0044bdb0(FUN_0044e370 pSceneObject)
{
    bool bResult = false;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kLock))->FUN_0040fbf0(0);
    for (unsigned int i = 0; i < m_uiCount && !bResult; i++)
        bResult = Visit(i, pSceneObject);
    reinterpret_cast<::RecursiveSpinLock *>(&(m_kLock))->FUN_0040fba0();
    return bResult;
}

struct FUN_0044dc50 : FUN_0044b4b0
{
    void* m_04;
    void* m_08;
    void* m_0c;
    virtual ~FUN_0044dc50();
};
// @fnv 0x0044dc20
void* FUN_0044dc20_class::FUN_0044dc20(unsigned int flags)
{
    reinterpret_cast<::FUN_0044dc50 *>(this)->FUN_0044dc50::~FUN_0044dc50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x0044dc50
FUN_0044dc50::~FUN_0044dc50()
{
    void* pkTail;
    void* pkHead;
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(1);
    pkHead = m_0c;
    FUN_00401030(pkHead);
    pkTail = m_04;
    FUN_00401030(pkTail);
}

struct FUN_0040fbf0_Class
{
};
struct SpinQ
{
};
struct AutoMemQ
{
    int m0;
    AutoMemQ(int a, bool b, const char* f, int l);
    ~AutoMemQ();
};
struct CurQ
{
    ~CurQ();
};
struct SPQ
{
    void* p;
    SPQ& operator=(void* q);
};
struct NodeQ
{
    NodeQ* next;
    SPQ sp;
    NodeQ();
    ~NodeQ();
};
struct NewCurQ
{
    int m0, m4, m8, mc;
    NewCurQ(unsigned int a1);
};
struct FUN_0044e170_Class
{
    int unk00;
    NodeQ* head;
    NodeQ* tail;
    int unk0c;
    int unk10;
    CurQ* current;
    void* owner;
    int unk1c;
    FUN_0040fbf0_Class lock;
    void FUN_0044e170(bool recreate);
};
// Calls Cleanup(1), then passes m_10 to FUN_00401030.
// @fnv 0x0044d770
FUN_0044d770_cls::~FUN_0044d770_cls()
{
    reinterpret_cast<::FUN_0044e170_Class *>(this)->FUN_0044e170(1);
    void* a = m_10;
    FUN_00401030(a);
}
// @fnv 0x0044d840
FUN_0044d840::~FUN_0044d840()
{
    reinterpret_cast<::FUN_0044e170_Class *>(this)->FUN_0044e170(true);
    delete m_pkBuckets;
}
// Deletes all nodes and the current object, and when recreate is false allocates a fresh head node and current object; unlocks lock at the end.
// @fnv 0x0044e170
void FUN_0044e170_Class::FUN_0044e170(bool recreate)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0(0);
    AutoMemQ memory(6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.inl", 0x115);
    unsigned int oldCurrent = ((unsigned int)(::FUN_00559450((int *)(current))));
    delete current;
    current = 0;
    owner = 0;
    while (head)
    {
        NodeQ* next = head->next;
        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::SPQ &)(head->sp))->FUN_006f74f0((::ObjA *)(void *)(0));
        delete head;
        head = next;
    }
    if (!recreate)
    {
        head = new NodeQ;
        tail = head;
        current = (CurQ*)new NewCurQ(oldCurrent);
    }
    reinterpret_cast<::RecursiveSpinLock *>((((SpinQ*)&lock)))->FUN_0040fba0();
}


// @fnv 0x0044e340
int FUN_0044e340(unsigned long index, void* value)
{
    return TlsSetValue(index, value);
}

struct AutoMemX
{
    int m;
    AutoMemX(int a, int b, const char* f, int l);
    ~AutoMemX();
};
struct FUN_0044ed50
{
    ~FUN_0044ed50();
};
struct ListX
{
    unsigned FUN_0044f3e0();
    int m0, m4, m8, mc;
    FUN_0044ed50* m10;
public:
    void FUN_004ee920();
};
// @fnv 0x00450770
FUN_00450770::~FUN_00450770()
{
    FUN_004506a0(0);
    reinterpret_cast<::FUN_00450b40_Class *>((((ShutdownDataHandler*)(*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler)))))->FUN_00450b40(1);
    ::ZeroSixInts((int *)&((*reinterpret_cast<::ShutdownCalendar *>(&::g_011de7b8))));
    FUN_00527f40();
    (*reinterpret_cast<::ShutdownPlayer * *>(&::_g_thePlayer))->Reset(0, 0);
    reinterpret_cast<::fnv_008a8150::FUN_008a8150_shell *>((((ShutdownSaveGame*)g_TESSaveLoadGame)))->FUN_008a8150(0);
    field20 = 0;
    field1c = 0;
    field68 = 0;
    reinterpret_cast<::fnv_00977540::ProcessManager *>(&((*reinterpret_cast<::ShutdownProcess *>(&::g_011e0e80))))->FUN_00977540();
    reinterpret_cast<::FUN_004539a0_cls *>(this)->FUN_004539a0(0, 0);
    reinterpret_cast<::FUN_00450b60_Class *>(this)->ClearList();
    reinterpret_cast<::FUN_00458f90_shell *>(this)->FUN_00458f90();
    FUN_00651e30();
    ::Entry664::FUN_00664cd0(0);
    reinterpret_cast<::Target *>(this)->FUN_0045ac80();
    reinterpret_cast<::fnv_0045a520::FUN_0045a520_shell *>(this)->LoadStartMenuModels();
    reinterpret_cast<::FUN_0045a1c0_cls *>(this)->ClearQueuedFile();
    reinterpret_cast<::fnv_0045a350::FUN_0045a350_cls *>(this)->ClearIdlePointer();
    ::FUN_0068b4a0_shell::FUN_0068b4a0();
    ClearGlobalArray();
    reinterpret_cast<::BGSCameraShot *>(&((*reinterpret_cast<::ShutdownVATS *>(&::g_011f2250))))->ResetCameraShot();
    reinterpret_cast<::DataHandlerX *>((((ShutdownDataHandler*)(*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler)))))->FUN_0045dfe0();
    reinterpret_cast<::This_00450d00 *>(this)->FUN_00450d00();
    reinterpret_cast<::FUN_00450b40_Class *>((((ShutdownDataHandler*)(*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler)))))->FUN_00450b40(1);
    ::FUN_00c459d0(0);
    delete (ShutdownModelLoader*)(*reinterpret_cast<::Loader_S * *>(&::g_modelLoader));
    (*reinterpret_cast<::Loader_S * *>(&::g_modelLoader)) = 0;
    delete (*reinterpret_cast<::ShutdownIOManager * *>(&::DAT_01202d98));
    (*reinterpret_cast<::ShutdownIOManager * *>(&::DAT_01202d98)) = 0;
    delete (*reinterpret_cast<::ShutdownTaskQueue * *>(&::DAT_01202df4));
    (*reinterpret_cast<::ShutdownTaskQueue * *>(&::DAT_01202df4)) = 0;
    delete grid;
    delete (ShutdownSaveGame*)g_TESSaveLoadGame;
    g_TESSaveLoadGame = 0;
    FUN_00847500();
    ::fnv_0084fd30::FUN_0084fd30();
    pointerC0.FUN_0066b0d0(0);
    delete (ShutdownDataHandler*)(*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler));
    (*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler)) = 0;
    delete field38;
    delete field3c;
    reinterpret_cast<::FileMatchList *>((((::ShutdownWorld *)(::FUN_0045bb80((int)this)))))->RemoveAll();
    ::fnv_004e8000::FUN_004e8000();
    for (int i = 0; i < 4; ++i)
    {
        if (((::ShutdownScene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(i))))
        {
            reinterpret_cast<::MultiBoundManagerB5D *>((((::ShutdownScene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(i)))))->FUN_00b5d180();
            ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(i);
            FUN_00b60040();
        }
    }
    FUN_00625fb0();
    reinterpret_cast<::ListX *>(&(collection))->FUN_004ee920();
}
struct OwnerX
{
    ListX* m0;
    int m4, m8;
    unsigned mc;
    FUN_0044ed50* m10;
    void FUN_0044eed0();
};
// @fnv 0x0044f400
void FUN_0044f400_class::FUN_0044f400()
{
    while (m_0c)
        reinterpret_cast<::OwnerX *>(this)->FUN_0044eed0();
}
// @fnv 0x0044e4f0
void S::FUN_0044e4f0(void* arg0)
{
    reinterpret_cast<::FUN_006f74f0_cls *>((((X6f74f0*)((char*)arg0 + 4))))->FUN_006f74f0((::ObjA *)(0));
    reinterpret_cast<::CombatProcedure *>((((X6ecd40*)arg0)))->Initialize((::CombatController *)(*(int*)((char*)this + 0x10)));
    *(void**)((char*)this + 0x10) = arg0;
    *(int*)((char*)this + 0xc) = *(int*)((char*)this + 0xc) + 1;
    if (*(int*)((char*)this + 0xc) == reinterpret_cast<::FUN_0084e3a0_Class *>((((X84e3a0*)*(void**)this)))->FUN_0084e3a0())
    {
        reinterpret_cast<::OwnerX *>((((X44eed0*)this)))->FUN_0044eed0();
    }
}
// Keeps only m10 list nodes that appear in an array copied from m0's list, deletes the others, then stores the new head in m10 and the count in mc.
// @fnv 0x0044eed0
void OwnerX::FUN_0044eed0()
{
    AutoMemX ctx(6, 1, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.inl", 0xd0);
    unsigned n9 = m0->FUN_0044f3e0() * 2;
    FUN_0044ed50** arr5 = new FUN_0044ed50*[n9];
    memcpy(arr5, m0->m10, n9 * 4);
    FUN_0044ed50* prev = 0;
    unsigned cnt2 = 0;
    while (m10)
    {
        FUN_0044ed50* curVal = m10;
        m10 = ((::FUN_0044ed50 *)(reinterpret_cast<::Callees *>((m10))->FUN_00726070()));
        bool found4 = false;
        for (unsigned i2 = 0; i2 < n9; i2++)
        {
            if (curVal == arr5[i2])
            {
                found4 = true;
                break;
            }
        }
        if (found4)
        {
            reinterpret_cast<::CombatProcedure *>((curVal))->Initialize((::CombatController *)(prev));
            prev = curVal;
            cnt2++;
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>((curVal))->Initialize((::CombatController *)(::FUN_0044ed50 *)(0));
            delete curVal;
        }
    }
    delete[] arr5;
    m10 = prev;
    mc = cnt2;
}

struct FUN_0044e120_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int(__cdecl* m_iThirdValue)(void*, int, int, int, int);
    int CallAndAccumulate(int, int, int, int);
};
// @fnv 0x0044e120
int FUN_0044e120_Class::CallAndAccumulate(int a, int b, int c, int d)
{
    int v;
    v = m_iThirdValue(this, a, b, c, d);
    m_iWordAt04 += v;
    return v;
}

struct GlobalObject_0044f440
{
    virtual ~GlobalObject_0044f440();
};
struct FUN_0044f4c0 : GlobalObject_0044f440
{
    virtual ~FUN_0044f4c0();
};
// @fnv 0x0044f4c0
FUN_0044f4c0::~FUN_0044f4c0()
{}

struct FUN_00456630_Class
{
    int FUN_00456630(int aFlag);
};
// @fnv 0x00456610
bool FUN_00456630_helper::FUN_00456610()
{
    return ((bool)(reinterpret_cast<::FUN_00456630_Class *>(this)->FUN_00456630(1)));
}

// @fnv 0x00456630
int FUN_00456630_Class::FUN_00456630(int aFlag)
{
    return (int)((unsigned int)*((int*)((char*)this + 0x30)) & aFlag) != 0;
}

namespace fnv_00448420 {
struct ItemObj
{
    int m_iWordAt00;
    ItemObj(int);
    ~ItemObj();
};

struct IterA
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    unsigned char m_iThirdValue;
    IterA();
    ~IterA();
};

struct IterB
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    unsigned char m_iThirdValue;
    IterB();
    ~IterB();
};

struct IterC
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    unsigned char m_iThirdValue;
    IterC();
    ~IterC();
};

struct EntryListA
{
};
struct EntryListB
{
};
struct EntryListC
{
};
struct Controller
{
};

struct GlobalManager
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
};


struct ModelLoader
{
    unsigned int m_00;
    unsigned int m_04;
    EntryListA* m_08;
    Controller* m_0c;
    EntryListB* m_10;
    unsigned int m_14;
    EntryListC* m_18;
    void FUN_00448420();
};

// Drains three entry lists through iterators, passing each accepted item's result to the global manager, bracketed by other global manager calls.
// @fnv 0x00448420
void ModelLoader::FUN_00448420()
{
    reinterpret_cast<::FUN_00c3e310_shell *>(((*reinterpret_cast<::fnv_00448420::GlobalManager * *>(&::DAT_01202d98))))->FUN_00c3e310();
    IterA first;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(first))->FUN_006ebde0())
    {
        int firstValue = 0;
        ItemObj firstItem3(0);
        if (reinterpret_cast<::FUN_00906570_Class *>((m_08))->AdvanceRequest((::Request9065 *)(::fnv_00448420::IterA *)(&first), (void **)(int *)(&firstValue), &firstItem3, 1))
            reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::fnv_00448420::GlobalManager * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)(void *)(((void *)(::FUN_00559450((int *)&(firstItem3))))), {});
    }
    reinterpret_cast<::QueuedMap *>((m_0c))->FUN_00528e40(0);
    IterB second;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(second))->FUN_006ebde0())
    {
        int secondValue = 0;
        ItemObj secondItem(0);
        if (reinterpret_cast<::FUN_00906570_Class *>((m_10))->AdvanceRequest((::Request9065 *)(::fnv_00448420::IterB *)(&second), (void **)(int *)(&secondValue), &secondItem, 1))
            reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::fnv_00448420::GlobalManager * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)(void *)(((void *)(::FUN_00559450((int *)&(secondItem))))), {});
    }
    IterC third8;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(third8))->FUN_006ebde0())
    {
        int thirdValue = 0;
        ItemObj thirdItem6(0);
        if (reinterpret_cast<::FUN_00906570_Class *>((m_18))->AdvanceRequest((::Request9065 *)(::fnv_00448420::IterC *)(&third8), (void **)(int *)(&thirdValue), &thirdItem6, 1))
            reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::fnv_00448420::GlobalManager * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)(void *)(((void *)(::FUN_00559450((int *)&(thirdItem6))))), {});
    }
    (*reinterpret_cast<::fnv_00448420::GlobalManager * *>(&::DAT_01202d98))->v21();
    reinterpret_cast<::FUN_00c3e340_cls *>(((*reinterpret_cast<::fnv_00448420::GlobalManager * *>(&::DAT_01202d98))))->FUN_00c3e340();
}
}  // namespace fnv_00448420

class TESModel
{
};

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};

class TESBipedModelForm
{
};

struct BoundObjectModelLookup
{
    TESModel* FUN_00446a60(TESForm* form, TESObjectREFR* reference);
};

struct TESForm_GetFormType_Helper
{
    unsigned int GetFormType();
};

struct TESObject_GetNext_Helper
{
};

struct TESObjectWEAP_GetWorldTESModel_Helper
{
};

struct TESNPC_GetSex_Helper
{
    int GetSex();
};

struct TESBipedModelForm_GetWorldTESModel_Helper
{
};

struct TESObjectREFR_GetOwner_Helper
{
};

struct TESObjectREFR_GetTESModel_Helper
{
};

// Returns a TESModel for form: the reference's model if GetNext equals form, else a weapon, direct or biped model (sex from the reference's owner NPC).
// @fnv 0x00446a60
TESModel* BoundObjectModelLookup::FUN_00446a60(TESForm* form, TESObjectREFR* reference)
{
    TESModel* m_kModelObjectsItem;
    {
        TESObjectWEAP_GetWorldTESModel_Helper* pWeapon;
        {
            TESBipedModelForm_GetWorldTESModel_Helper* pBiped;
            {
                int m_eSex;
                {
                    TESForm* pOwner;

                    if (reference &&
                        ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject_GetNext_Helper*)reference)))->FUN_007af430())) == reinterpret_cast<unsigned int>(form))
                    {
                        return reinterpret_cast<::TESObjectREFR *>((((TESObjectREFR_GetTESModel_Helper*)reference)))->GetTESModel();
                    }

                    m_kModelObjectsItem = 0;

                    if (form && ((TESForm_GetFormType_Helper*)form)->GetFormType() == 0x28)
                    {
                        pWeapon = (TESObjectWEAP_GetWorldTESModel_Helper*)form;
                        m_kModelObjectsItem = ((::TESModel *)(reinterpret_cast<::FUN_00522d80_shell *>((pWeapon))->FUN_00522d80()));
                    }
                    else
                    {
                        m_kModelObjectsItem = dynamic_cast<TESModel*>((TESBoundObject*)form);

                        if (!m_kModelObjectsItem)
                        {
                            pBiped = (TESBipedModelForm_GetWorldTESModel_Helper*)dynamic_cast<TESBipedModelForm*>(
                                (TESBoundObject*)form);

                            if (pBiped)
                            {
                                m_eSex = 0;

                                if (reference)
                                {
                                    pOwner = reinterpret_cast<::OwnerLookupView *>((((TESObjectREFR_GetOwner_Helper*)reference)))->FUN_00567790();

                                    if (pOwner && ((TESForm_GetFormType_Helper*)pOwner)->GetFormType() == 0x2a)
                                    {
                                        m_eSex = ((TESNPC_GetSex_Helper*)pOwner)->GetSex();
                                    }
                                }

                                m_kModelObjectsItem = ((::TESModel *)(reinterpret_cast<::FUN_00481110_shell *>((pBiped))->GetWorldModel(m_eSex)));
                            }
                        }
                    }

                    return m_kModelObjectsItem;
                }
            }
        }
    }
}

#include "generated/data/staging/blk_00440000_od.inc"
